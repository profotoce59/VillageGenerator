/**
 * village_noise.cu — CUDA kernels for batch sampleSurfaceNoise + height computation
 *
 * Strategy:
 *   Kernel 1 (compute_noise_columns):
 *     One thread per (column, y).  Each thread runs the 40 Perlin octaves of
 *     sampleSurfaceNoise(cellX, y, cellZ), then the density/slide math, and
 *     writes one noise value.  The octave permutation tables are staged in
 *     shared memory once per block.
 *     Output: double noiseGrid[numColumns][startSizeY + 1]
 *
 *   Kernel 2 (compute_heights_scattered / compute_heightmap_rect):
 *     One thread per height query.  Reads the 4 corner columns from noiseGrid,
 *     interpolates trilinearly top-down and returns the first solid block.
 *
 * Bit-exactness with the CPU path is a hard requirement, so:
 *   - the octave accumulations keep their sequential order (no tree reduction),
 *   - d_lerp3 mirrors cubiomes' lerp3 argument order exactly,
 *   - the file must be compiled with -fmad=false (see Makefile) so that
 *     `from + part * (to - from)` is not contracted into an FMA.
 */

#include "village_noise.cuh"
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ============================================================================
// Device helpers — ports of cubiomes rng.h / noise.c
// ============================================================================

__device__ static inline double d_lerp(double part, double from, double to)
{
    return from + part * (to - from);
}

__device__ static inline double d_lerp2(
        double dx, double dy, double v00, double v10, double v01, double v11)
{
    return d_lerp(dy, d_lerp(dx, v00, v10), d_lerp(dx, v01, v11));
}

__device__ static inline double d_lerp3(
        double dx, double dy, double dz,
        double v000, double v100, double v010, double v110,
        double v001, double v101, double v011, double v111)
{
    v000 = d_lerp2(dx, dy, v000, v100, v010, v110);
    v001 = d_lerp2(dx, dy, v001, v101, v011, v111);
    return d_lerp(dz, v000, v001);
}

__device__ static inline double d_clampedLerp(double part, double from, double to)
{
    if (part <= 0.0) return from;
    if (part >= 1.0) return to;
    return d_lerp(part, from, to);
}

// clamped_lerp from surface_gen.c — note the *different* argument convention
// (a, b, t) with t clamped, used by the slide math.
__device__ static inline double d_clampedLerpAB(double a, double b, double t)
{
    if (t < 0.0) t = 0.0;
    else if (t > 1.0) t = 1.0;
    return a + (b - a) * t;
}

__device__ static inline double d_indexedLerp(uint8_t idx, double a, double b, double c)
{
    switch (idx & 0xf)
    {
    case 0:  return  a + b;
    case 1:  return -a + b;
    case 2:  return  a - b;
    case 3:  return -a - b;
    case 4:  return  a + c;
    case 5:  return -a + c;
    case 6:  return  a - c;
    case 7:  return -a - c;
    case 8:  return  b + c;
    case 9:  return -b + c;
    case 10: return  b - c;
    case 11: return -b - c;
    case 12: return  a + b;
    case 13: return -b + c;
    case 14: return -a + b;
    case 15: return -b - c;
    }
    return 0.0;
}

// samplePerlin — port of cubiomes noise.c
__device__ static double d_samplePerlin(
    const GpuPerlinParams* __restrict__ p,
    const uint8_t* __restrict__ idx,
    double d1, double d2, double d3,
    double yamp, double ymin)
{
    uint8_t h1, h2, h3;
    double t1, t2, t3;

    if (d2 == 0.0) {
        d2 = p->d2;
        h2 = (uint8_t)p->h2;
        t2 = p->t2;
    } else {
        d2 += p->b;
        double i2 = floor(d2);
        d2 -= i2;
        h2 = (uint8_t)(int)i2;
        t2 = d2*d2*d2 * (d2 * (d2*6.0-15.0) + 10.0);
    }

    d1 += p->a;
    d3 += p->c;

    double i1 = floor(d1);
    double i3 = floor(d3);
    d1 -= i1;
    d3 -= i3;

    h1 = (uint8_t)(int)i1;
    h3 = (uint8_t)(int)i3;

    t1 = d1*d1*d1 * (d1 * (d1*6.0-15.0) + 10.0);
    t3 = d3*d3*d3 * (d3 * (d3*6.0-15.0) + 10.0);

    if (yamp) {
        double yclamp = ymin < d2 ? ymin : d2;
        d2 -= floor(yclamp / yamp) * yamp;
    }

    uint8_t a1 = idx[h1]   + h2;
    uint8_t b1 = idx[h1+1] + h2;

    uint8_t a2 = idx[a1]   + h3;
    uint8_t b2 = idx[b1]   + h3;
    uint8_t a3 = idx[a1+1] + h3;
    uint8_t b3 = idx[b1+1] + h3;

    double l1 = d_indexedLerp(idx[a2],   d1,   d2,   d3);
    double l2 = d_indexedLerp(idx[b2],   d1-1, d2,   d3);
    double l3 = d_indexedLerp(idx[a3],   d1,   d2-1, d3);
    double l4 = d_indexedLerp(idx[b3],   d1-1, d2-1, d3);
    double l5 = d_indexedLerp(idx[a2+1], d1,   d2,   d3-1);
    double l6 = d_indexedLerp(idx[b2+1], d1-1, d2,   d3-1);
    double l7 = d_indexedLerp(idx[a3+1], d1,   d2-1, d3-1);
    double l8 = d_indexedLerp(idx[b3+1], d1-1, d2-1, d3-1);

    l1 = d_lerp(t1, l1, l2);
    l3 = d_lerp(t1, l3, l4);
    l5 = d_lerp(t1, l5, l6);
    l7 = d_lerp(t1, l7, l8);

    l1 = d_lerp(t2, l1, l3);
    l5 = d_lerp(t2, l5, l7);

    return d_lerp(t3, l1, l5);
}

// sampleSurfaceNoise — port of cubiomes biomenoise.c
// (maintainPrecision() is the identity in cubiomes, so it is elided)
__device__ static double d_sampleSurfaceNoise(
    const GpuSurfaceNoise* __restrict__ sn,
    const uint8_t* __restrict__ perm,       // perm[octave][257], flattened
    int x, int y, int z)
{
    double xzScale = 684.412 * sn->xzScale;
    double yScale  = 684.412 * sn->yScale;
    double xzStep  = xzScale / sn->xzFactor;
    double yStep   = yScale  / sn->yFactor;

    double minNoise  = 0.0;
    double maxNoise  = 0.0;
    double mainNoise = 0.0;
    double persist   = 1.0;
    double contrib   = 1.0;

    for (int i = 0; i < GPU_OCT_MIN; i++) {
        double dx = x * xzScale * persist;
        double dy = y * yScale  * persist;
        double dz = z * xzScale * persist;
        double sy = yScale * persist;
        double ty = y * sy;

        minNoise += d_samplePerlin(&sn->oct[i], perm + (size_t)i * 257,
                                   dx, dy, dz, sy, ty) * contrib;
        maxNoise += d_samplePerlin(&sn->oct[GPU_OCT_MIN + i],
                                   perm + (size_t)(GPU_OCT_MIN + i) * 257,
                                   dx, dy, dz, sy, ty) * contrib;

        if (i < GPU_OCT_MAIN) {
            double dx2 = x * xzStep * persist;
            double dy2 = y * yStep  * persist;
            double dz2 = z * xzStep * persist;
            double sy2 = yStep * persist;
            double ty2 = y * sy2;
            mainNoise += d_samplePerlin(&sn->oct[GPU_OCT_MIN + GPU_OCT_MAX + i],
                                        perm + (size_t)(GPU_OCT_MIN + GPU_OCT_MAX + i) * 257,
                                        dx2, dy2, dz2, sy2, ty2) * contrib;
        }

        persist *= 0.5;
        contrib *= 2.0;
    }

    return d_clampedLerp(0.5 + 0.05 * mainNoise, minNoise / 512.0, maxNoise / 512.0);
}

// ============================================================================
// Kernel 0: randomOffset per column — port of cubiomes_noise_2d()
// One thread per column. 16 octdepth octaves.
// ============================================================================

__global__ void compute_random_offsets(
    const GpuSurfaceNoise*     __restrict__ sn,
    const ColumnParams*        __restrict__ columns,
    int numColumns,
    double* __restrict__ randomOffsets)
{
    extern __shared__ uint8_t s_perm[];      // [GPU_OCT_DEPTH * 257]
    {
        const int total = GPU_OCT_DEPTH * 257;
        const uint8_t* g_perm = (const uint8_t*)sn->perm[GPU_OCT_SURF];
        for (int i = threadIdx.x; i < total; i += blockDim.x)
            s_perm[i] = g_perm[i];
    }
    __syncthreads();

    int col = blockIdx.x * blockDim.x + threadIdx.x;
    if (col >= numColumns) return;

    const int x = columns[col].cellX;
    const int z = columns[col].cellZ;

    // sampleOctaveAmp(&sn->octdepth, x*200, 10.0, z*200, yamp=1.0, ymin=0.0, ydefault=1)
    double noise = 0.0;
    for (int i = 0; i < GPU_OCT_DEPTH; i++) {
        const GpuPerlinParams* p = &sn->oct[GPU_OCT_SURF + i];
        double lf = p->lacunarity;
        double ax = (double)(x * 200) * lf;
        double ay = -p->b;                  // ydefault == 1
        double az = (double)(z * 200) * lf;
        double pv = d_samplePerlin(p, s_perm + (size_t)i * 257,
                                   ax, ay, az, 1.0 * lf, 0.0 * lf);
        noise += p->amplitude * pv;
    }

    // Post-processing from cubiomes_noise_2d()
    noise = noise < 0.0 ? -noise * 0.3 : noise;
    noise = noise * 3.0 * 65535.0 / 8000.0 - 2.0;

    randomOffsets[col] = (noise < 0.0)
        ? (17.0 * noise / 28.0 / 64.0)
        : (fmin(noise, 1.0) * 17.0 / 40.0 / 64.0);
}

// ============================================================================
// Kernel 1: compute noise columns
// One thread per (column, y), flattened so no thread is wasted.
// Output: noiseGrid[col * (startSizeY + 1) + y]
// ============================================================================

__global__ void compute_noise_columns(
    const GpuSurfaceNoise*     __restrict__ sn,
    const GpuSurfaceGenConfig* __restrict__ cfg,
    const ColumnParams*        __restrict__ columns,
    const double*              __restrict__ randomOffsets,
    int numColumns,
    int yFrom, int yTo,         // tranche de cellules a calculer
    int sentinelIdx,            // indice ou ecrire le 0 de fin de colonne
    int stride,                 // pas fixe, independant de startSizeY
    double* __restrict__ noiseGrid)
{
    // Stage the permutation tables in shared memory: samplePerlin does 8
    // data-dependent byte lookups per octave, 320 per thread in total.
    extern __shared__ uint8_t s_perm[];      // [GPU_OCT_SURF * 257]
    {
        const int total = GPU_OCT_SURF * 257;
        const uint8_t* g_perm = (const uint8_t*)sn->perm;
        for (int i = threadIdx.x; i < total; i += blockDim.x)
            s_perm[i] = g_perm[i];
    }
    __syncthreads();

    // On ne calcule que la tranche [yFrom, yTo). En calcul complet c'est
    // [minCellY, startSizeY) ; en extension apres une reprise de scan, c'est
    // seulement les quelques cellules qui manquent.
    const int nY = yTo - yFrom;
    int tid = blockIdx.x * blockDim.x + threadIdx.x;
    int col = tid / nY;
    int y   = yFrom + (tid - col * nY);

    if (col >= numColumns)
        return;

    const ColumnParams cp = columns[col];
    const double randomOffset = randomOffsets[col];

    double noise = d_sampleSurfaceNoise(sn, s_perm, cp.cellX, y, cp.cellZ);

    // Density + falloff (1.16+ branch), mirrors sample_noise_column()
    double fallOff1 = 1.0 - (double)y * 2.0 / (double)cfg->noiseSizeY + randomOffset;
    double fallOff2 = fallOff1 * cfg->densityFactor + cfg->densityOffset;
    double fallOff3 = (fallOff2 + cp.depth) * cp.scale;

    if (fallOff3 > 0.0)
        noise = noise + fallOff3 * 4.0;
    else
        noise = noise + fallOff3;

    if (cfg->topSlideSize > 0.0) {
        double num = ((double)(cfg->noiseSizeY - y) - cfg->topSlideOffset) / cfg->topSlideSize;
        noise = d_clampedLerpAB(cfg->topSlideTarget, noise, num);
    }
    if (cfg->botSlideSize > 0.0) {
        double num = ((double)y - cfg->botSlideOffset) / cfg->botSlideSize;
        noise = d_clampedLerpAB(cfg->botSlideTarget, noise, num);
    }

    noiseGrid[(size_t)col * stride + y] = noise;

    // Cote CPU le buffer est calloc'd et seul [0, startSizeY) est ecrit, donc
    // l'indice startSizeY relit 0.0. On reproduit ca. En extension, l'ancienne
    // sentinelle est ecrasee par sa vraie valeur (elle est dans [yFrom, yTo))
    // et la nouvelle est posee plus haut.
    if (y == yFrom)
        noiseGrid[(size_t)col * stride + sentinelIdx] = 0.0;
}

// ============================================================================
// Shared height scan — identical to generate_column_from_y()
// ============================================================================

__device__ static inline int scan_column(
    const GpuSurfaceGenConfig* __restrict__ cfg,
    const double* __restrict__ col0,        // (cellX,   cellZ)
    const double* __restrict__ col1,        // (cellX,   cellZ+1)
    const double* __restrict__ col2,        // (cellX+1, cellZ)
    const double* __restrict__ col3,        // (cellX+1, cellZ+1)
    int startSizeY, int minCellY,
    double percentX, double percentZ,
    int predicate)
{
    for (int cellY = startSizeY - 1; cellY >= minCellY; --cellY) {
        double xyz    = col0[cellY];
        double xyz1   = col1[cellY];
        double x1yz   = col2[cellY];
        double x1yz1  = col3[cellY];
        double xy1z   = col0[cellY + 1];
        double xy1z1  = col1[cellY + 1];
        double x1y1z  = col2[cellY + 1];
        double x1y1z1 = col3[cellY + 1];

        for (int posY = cfg->chunkHeight - 1; posY >= 0; --posY) {
            double percentY = (double)posY / (double)cfg->chunkHeight;

            double noise = d_lerp3(percentY, percentX, percentZ,
                                   xyz,  xy1z,  x1yz,  x1y1z,
                                   xyz1, xy1z1, x1yz1, x1y1z1);

            int y = cellY * cfg->chunkHeight + posY;

            // get_block_from_noise: noise > 0 -> STONE, y < seaLevel -> WATER, else AIR
            bool hit = (predicate == HEIGHT_PRED_STONE)
                     ? (noise > 0.0)
                     : (noise > 0.0 || y < cfg->seaLevel);
            if (hit)
                return y + 1;
        }
    }
    return 0;
}

// ============================================================================
// Kernel 2a: scattered queries
// ============================================================================

__global__ void compute_heights_scattered(
    const GpuSurfaceGenConfig* __restrict__ cfg,
    const double* __restrict__ noiseGrid,
    int startSizeY, int minCellY, int stride,
    const int* __restrict__ queryX,
    const int* __restrict__ queryZ,
    const int* __restrict__ cornerIndices,      // [numQueries * 4]
    int numQueries,
    int predicate,
    int* __restrict__ heightsOut)
{
    int q = blockIdx.x * blockDim.x + threadIdx.x;
    if (q >= numQueries)
        return;

    int c0 = cornerIndices[q * 4 + 0];
    int c1 = cornerIndices[q * 4 + 1];
    int c2 = cornerIndices[q * 4 + 2];
    int c3 = cornerIndices[q * 4 + 3];

    int x = queryX[q];
    int z = queryZ[q];

    int posX = ((x % cfg->chunkWidth) + cfg->chunkWidth) % cfg->chunkWidth;
    int posZ = ((z % cfg->chunkWidth) + cfg->chunkWidth) % cfg->chunkWidth;

    double percentX = (double)posX / (double)cfg->chunkWidth;
    double percentZ = (double)posZ / (double)cfg->chunkWidth;

    heightsOut[q] = scan_column(cfg,
        noiseGrid + (size_t)c0 * stride, noiseGrid + (size_t)c1 * stride,
        noiseGrid + (size_t)c2 * stride, noiseGrid + (size_t)c3 * stride,
        startSizeY, minCellY, percentX, percentZ, predicate);
}

// ============================================================================
// Kernel 2b: rectangular heightmap — corner indices derived arithmetically
// ============================================================================

__global__ void compute_heightmap_rect(
    const GpuSurfaceGenConfig* __restrict__ cfg,
    const double* __restrict__ noiseGrid,
    int startSizeY, int minCellY, int stride,
    int gridW, int cellX0, int cellZ0,
    int x0, int z0, int w, int h,
    int predicate,
    int* __restrict__ heightsOut)
{
    int q = blockIdx.x * blockDim.x + threadIdx.x;
    if (q >= w * h)
        return;

    int ix = q % w;
    int iz = q / w;
    int x = x0 + ix;
    int z = z0 + iz;

    int cellX = (int)floor((double)x / (double)cfg->chunkWidth);
    int cellZ = (int)floor((double)z / (double)cfg->chunkWidth);

    int c0 = (cellZ - cellZ0) * gridW + (cellX - cellX0);

    int posX = ((x % cfg->chunkWidth) + cfg->chunkWidth) % cfg->chunkWidth;
    int posZ = ((z % cfg->chunkWidth) + cfg->chunkWidth) % cfg->chunkWidth;

    double percentX = (double)posX / (double)cfg->chunkWidth;
    double percentZ = (double)posZ / (double)cfg->chunkWidth;

    heightsOut[q] = scan_column(cfg,
        noiseGrid + (size_t)(c0)             * stride,
        noiseGrid + (size_t)(c0 + gridW)     * stride,
        noiseGrid + (size_t)(c0 + 1)         * stride,
        noiseGrid + (size_t)(c0 + gridW + 1) * stride,
        startSizeY, minCellY, percentX, percentZ, predicate);
}

// ============================================================================
// Host-side context and API implementation
// ============================================================================

struct CudaNoiseContext {
    GpuSurfaceNoise*     d_sn;
    GpuSurfaceGenConfig* d_cfg;
    ColumnParams*        d_columns;
    double*              d_randomOffsets;
    double*              d_noiseGrid;
    int*                 d_queryX;
    int*                 d_queryZ;
    int*                 d_cornerIndices;
    int*                 d_heights;

    GpuSurfaceGenConfig hostCfg;
    int maxColumns;
    int maxQueries;
    int allocStride;        // stride en doubles réservé par colonne dans d_noiseGrid

    cudaEvent_t evStart, evUpload, evColumns, evHeights, evEnd;
    float msUpload, msColumns, msHeights, msDownload;
};

#define CUDA_CHECK(call) do { \
    cudaError_t err__ = (call); \
    if (err__ != cudaSuccess) { \
        fprintf(stderr, "CUDA error at %s:%d: %s\n", __FILE__, __LINE__, \
                cudaGetErrorString(err__)); \
        return nullptr; \
    } \
} while(0)

#define CUDA_CHECK_INT(call) do { \
    cudaError_t err__ = (call); \
    if (err__ != cudaSuccess) { \
        fprintf(stderr, "CUDA error at %s:%d: %s\n", __FILE__, __LINE__, \
                cudaGetErrorString(err__)); \
        return -1; \
    } \
} while(0)

static const int  NOISE_BLOCK  = 128;
static const int  HEIGHT_BLOCK = 128;
static const size_t PERM_SURF_BYTES  = (size_t)GPU_OCT_SURF  * 257;
static const size_t PERM_DEPTH_BYTES = (size_t)GPU_OCT_DEPTH * 257;

// Mode d'attente de cudaEventSynchronize. Par defaut CUDA fait de l'attente
// active (spin) pour minimiser la latence, ce qui BRULE un coeur pendant que le
// GPU travaille. Avec autant de threads que de coeurs, ce coeur manque aux
// autres. VILLAGE_CUDA_BLOCKING_SYNC=1 bascule en attente bloquante : le thread
// s'endort et rend son coeur.
// A appeler avant toute creation de contexte CUDA, d'ou le one-shot ici.
static void apply_sync_mode_once()
{
    static bool done = false;
    if (done) return;
    done = true;
    const char* env = getenv("VILLAGE_CUDA_BLOCKING_SYNC");
    if (env && env[0] && env[0] != '0') {
        cudaError_t e = cudaSetDeviceFlags(cudaDeviceScheduleBlockingSync);
        if (e != cudaSuccess)
            fprintf(stderr, "cudaSetDeviceFlags(BlockingSync) : %s\n", cudaGetErrorString(e));
    }
}

CudaNoiseContext* cuda_noise_init(
    const GpuSurfaceNoise*     hostSN,
    const GpuSurfaceGenConfig* hostCfg,
    int maxColumns,
    int maxQueries)
{
    if (maxColumns <= 0 || maxQueries <= 0) {
        fprintf(stderr, "cuda_noise_init: invalid batch limits\n");
        return nullptr;
    }

    apply_sync_mode_once();

    CudaNoiseContext* ctx = new CudaNoiseContext();
    memset(ctx, 0, sizeof(*ctx));
    ctx->hostCfg    = *hostCfg;
    ctx->maxColumns = maxColumns;
    ctx->maxQueries = maxQueries;

    // startSizeY change d'un village à l'autre (setStartSizeYExact) mais reste
    // borné par noiseSizeY. Réserver la hauteur maximale d'emblée permet de
    // rebasculer sur une autre config par simple ré-upload.
    int maxStartSizeY = hostCfg->noiseSizeY > hostCfg->startSizeY
                      ? hostCfg->noiseSizeY : hostCfg->startSizeY;
    ctx->allocStride = maxStartSizeY + 1;
    const int stride = ctx->allocStride;

    CUDA_CHECK(cudaMalloc(&ctx->d_sn, sizeof(GpuSurfaceNoise)));
    CUDA_CHECK(cudaMemcpy(ctx->d_sn, hostSN, sizeof(GpuSurfaceNoise), cudaMemcpyHostToDevice));

    CUDA_CHECK(cudaMalloc(&ctx->d_cfg, sizeof(GpuSurfaceGenConfig)));
    CUDA_CHECK(cudaMemcpy(ctx->d_cfg, hostCfg, sizeof(GpuSurfaceGenConfig), cudaMemcpyHostToDevice));

    CUDA_CHECK(cudaMalloc(&ctx->d_columns,   sizeof(ColumnParams) * (size_t)maxColumns));
    CUDA_CHECK(cudaMalloc(&ctx->d_randomOffsets, sizeof(double) * (size_t)maxColumns));
    CUDA_CHECK(cudaMalloc(&ctx->d_noiseGrid, sizeof(double) * (size_t)maxColumns * stride));
    CUDA_CHECK(cudaMalloc(&ctx->d_queryX,    sizeof(int) * (size_t)maxQueries));
    CUDA_CHECK(cudaMalloc(&ctx->d_queryZ,    sizeof(int) * (size_t)maxQueries));
    CUDA_CHECK(cudaMalloc(&ctx->d_cornerIndices, sizeof(int) * (size_t)maxQueries * 4));
    CUDA_CHECK(cudaMalloc(&ctx->d_heights,   sizeof(int) * (size_t)maxQueries));

    CUDA_CHECK(cudaEventCreate(&ctx->evStart));
    CUDA_CHECK(cudaEventCreate(&ctx->evUpload));
    CUDA_CHECK(cudaEventCreate(&ctx->evColumns));
    CUDA_CHECK(cudaEventCreate(&ctx->evHeights));
    CUDA_CHECK(cudaEventCreate(&ctx->evEnd));

    return ctx;
}

int cuda_noise_update_state(CudaNoiseContext* ctx,
                            const GpuSurfaceNoise*     hostSN,
                            const GpuSurfaceGenConfig* hostCfg)
{
    if (!ctx || !hostSN || !hostCfg) return -1;
    if (hostCfg->startSizeY + 1 > ctx->allocStride) return -1;

    ctx->hostCfg = *hostCfg;
    CUDA_CHECK_INT(cudaMemcpy(ctx->d_sn, hostSN, sizeof(GpuSurfaceNoise),
                              cudaMemcpyHostToDevice));
    CUDA_CHECK_INT(cudaMemcpy(ctx->d_cfg, hostCfg, sizeof(GpuSurfaceGenConfig),
                              cudaMemcpyHostToDevice));
    return 0;
}

void cuda_noise_destroy(CudaNoiseContext* ctx)
{
    if (!ctx) return;
    cudaFree(ctx->d_sn);
    cudaFree(ctx->d_cfg);
    cudaFree(ctx->d_columns);
    cudaFree(ctx->d_randomOffsets);
    cudaFree(ctx->d_noiseGrid);
    cudaFree(ctx->d_queryX);
    cudaFree(ctx->d_queryZ);
    cudaFree(ctx->d_cornerIndices);
    cudaFree(ctx->d_heights);
    cudaEventDestroy(ctx->evStart);
    cudaEventDestroy(ctx->evUpload);
    cudaEventDestroy(ctx->evColumns);
    cudaEventDestroy(ctx->evHeights);
    cudaEventDestroy(ctx->evEnd);
    delete ctx;
}

void cuda_noise_last_timings(const CudaNoiseContext* ctx,
                             float* msUpload, float* msColumns,
                             float* msHeights, float* msDownload)
{
    if (!ctx) return;
    if (msUpload)   *msUpload   = ctx->msUpload;
    if (msColumns)  *msColumns  = ctx->msColumns;
    if (msHeights)  *msHeights  = ctx->msHeights;
    if (msDownload) *msDownload = ctx->msDownload;
}


// Plancher du scan de hauteur : avec le prédicat NOT_AIR, get_block_from_noise
// renvoie WATER dès que y < seaLevel, donc le scan touche TOUJOURS un bloc dans
// la cellule contenant y = seaLevel-1 et ne descend jamais plus bas. Inutile de
// calculer le bruit des cellules du dessous : c'est environ la moitié du volume
// quand startSizeY vaut 11 a 15.
// Avec STONE le scan peut aller jusqu'en bas, donc pas de plancher.
static inline int height_scan_floor(const GpuSurfaceGenConfig* cfg, int predicate)
{
    if (predicate == HEIGHT_PRED_STONE) return 0;
    if (cfg->chunkHeight <= 0 || cfg->seaLevel <= 0) return 0;
    int floorCell = (cfg->seaLevel - 1) / cfg->chunkHeight;
    if (floorCell < 0) floorCell = 0;
    if (floorCell > cfg->startSizeY - 1) floorCell = cfg->startSizeY - 1;
    if (floorCell < 0) floorCell = 0;
    return floorCell;
}

// Launch kernel 1. Returns -1 on error.
// uploadColumns/computeOffsets : false en extension, ou colonnes et
// randomOffsets sont deja sur le device et inchanges.
static int launch_columns(CudaNoiseContext* ctx, const ColumnParams* columns,
                          int numColumns, int yFrom, int yTo, int sentinelIdx,
                          bool uploadColumns, bool computeOffsets)
{
    CUDA_CHECK_INT(cudaEventRecord(ctx->evStart));
    if (uploadColumns) {
        CUDA_CHECK_INT(cudaMemcpyAsync(ctx->d_columns, columns,
            sizeof(ColumnParams) * (size_t)numColumns, cudaMemcpyHostToDevice));
    }
    CUDA_CHECK_INT(cudaEventRecord(ctx->evUpload));

    // randomOffset: overworld only, exactly like sample_noise_column().
    if (computeOffsets && ctx->hostCfg.dim == 0 /* DIM_OVERWORLD */) {
        int roGrid = (numColumns + NOISE_BLOCK - 1) / NOISE_BLOCK;
        compute_random_offsets<<<roGrid, NOISE_BLOCK, PERM_DEPTH_BYTES>>>(
            ctx->d_sn, ctx->d_columns, numColumns, ctx->d_randomOffsets);
    } else if (computeOffsets) {
        CUDA_CHECK_INT(cudaMemsetAsync(ctx->d_randomOffsets, 0,
            sizeof(double) * (size_t)numColumns));
    }
    CUDA_CHECK_INT(cudaGetLastError());

    long long threads = (long long)numColumns * (yTo - yFrom);
    if (threads <= 0) {
        fprintf(stderr, "launch_columns: rien a lancer (numColumns=%d, yFrom=%d, yTo=%d)\n",
                numColumns, yFrom, yTo);
        return -1;
    }
    int gridSize = (int)((threads + NOISE_BLOCK - 1) / NOISE_BLOCK);
    compute_noise_columns<<<gridSize, NOISE_BLOCK, PERM_SURF_BYTES>>>(
        ctx->d_sn, ctx->d_cfg, ctx->d_columns, ctx->d_randomOffsets,
        numColumns, yFrom, yTo, sentinelIdx, ctx->allocStride, ctx->d_noiseGrid);
    CUDA_CHECK_INT(cudaGetLastError());
    CUDA_CHECK_INT(cudaEventRecord(ctx->evColumns));
    return 0;
}

// Finish: record events, download results, fill timings. Returns -1 on error.
static int finish_batch(CudaNoiseContext* ctx, int* heightsOut, int numQueries)
{
    CUDA_CHECK_INT(cudaEventRecord(ctx->evHeights));
    CUDA_CHECK_INT(cudaMemcpyAsync(heightsOut, ctx->d_heights,
        sizeof(int) * (size_t)numQueries, cudaMemcpyDeviceToHost));
    CUDA_CHECK_INT(cudaEventRecord(ctx->evEnd));
    CUDA_CHECK_INT(cudaEventSynchronize(ctx->evEnd));

    cudaEventElapsedTime(&ctx->msUpload,   ctx->evStart,   ctx->evUpload);
    cudaEventElapsedTime(&ctx->msColumns,  ctx->evUpload,  ctx->evColumns);
    cudaEventElapsedTime(&ctx->msHeights,  ctx->evColumns, ctx->evHeights);
    cudaEventElapsedTime(&ctx->msDownload, ctx->evHeights, ctx->evEnd);
    return 0;
}

int cuda_noise_batch_heights(
    CudaNoiseContext* ctx,
    const ColumnParams* columns, int numColumns,
    const int* queryX, const int* queryZ, int numQueries,
    const int* queryCornerIndices,
    int predicate,
    int* heightsOut)
{
    if (!ctx) return -1;
    if (numColumns <= 0 || numQueries <= 0) return -1;
    if (numColumns > ctx->maxColumns || numQueries > ctx->maxQueries) {
        fprintf(stderr, "cuda_noise_batch_heights: batch too large (%d cols / %d max, "
                        "%d queries / %d max)\n",
                numColumns, ctx->maxColumns, numQueries, ctx->maxQueries);
        return -1;
    }

    const int minCellY = height_scan_floor(&ctx->hostCfg, predicate);
    if (launch_columns(ctx, columns, numColumns, minCellY, ctx->hostCfg.startSizeY,
                       ctx->hostCfg.startSizeY, true, true) != 0) return -1;

    CUDA_CHECK_INT(cudaMemcpyAsync(ctx->d_queryX, queryX,
        sizeof(int) * (size_t)numQueries, cudaMemcpyHostToDevice));
    CUDA_CHECK_INT(cudaMemcpyAsync(ctx->d_queryZ, queryZ,
        sizeof(int) * (size_t)numQueries, cudaMemcpyHostToDevice));
    CUDA_CHECK_INT(cudaMemcpyAsync(ctx->d_cornerIndices, queryCornerIndices,
        sizeof(int) * (size_t)numQueries * 4, cudaMemcpyHostToDevice));

    int gridSize = (numQueries + HEIGHT_BLOCK - 1) / HEIGHT_BLOCK;
    compute_heights_scattered<<<gridSize, HEIGHT_BLOCK>>>(
        ctx->d_cfg, ctx->d_noiseGrid, ctx->hostCfg.startSizeY, minCellY, ctx->allocStride,
        ctx->d_queryX, ctx->d_queryZ, ctx->d_cornerIndices,
        numQueries, predicate, ctx->d_heights);
    CUDA_CHECK_INT(cudaGetLastError());

    return finish_batch(ctx, heightsOut, numQueries);
}

int cuda_noise_heightmap(
    CudaNoiseContext* ctx,
    const ColumnParams* columns, int gridW, int gridH,
    int cellX0, int cellZ0,
    int x0, int z0, int w, int h,
    int predicate,
    int* heightsOut)
{
    if (!ctx) return -1;
    if (gridW <= 0 || gridH <= 0 || w <= 0 || h <= 0) return -1;

    int numColumns = gridW * gridH;
    int numQueries = w * h;
    if (numColumns > ctx->maxColumns || numQueries > ctx->maxQueries) {
        fprintf(stderr, "cuda_noise_heightmap: batch too large (%d cols / %d max, "
                        "%d queries / %d max)\n",
                numColumns, ctx->maxColumns, numQueries, ctx->maxQueries);
        return -1;
    }

    const int minCellY = height_scan_floor(&ctx->hostCfg, predicate);
    if (launch_columns(ctx, columns, numColumns, minCellY, ctx->hostCfg.startSizeY,
                       ctx->hostCfg.startSizeY, true, true) != 0) return -1;

    int gridSize = (numQueries + HEIGHT_BLOCK - 1) / HEIGHT_BLOCK;
    compute_heightmap_rect<<<gridSize, HEIGHT_BLOCK>>>(
        ctx->d_cfg, ctx->d_noiseGrid, ctx->hostCfg.startSizeY, minCellY, ctx->allocStride,
        gridW, cellX0, cellZ0, x0, z0, w, h, predicate, ctx->d_heights);
    CUDA_CHECK_INT(cudaGetLastError());

    return finish_batch(ctx, heightsOut, numQueries);
}
int cuda_noise_heightmap_extend(
    CudaNoiseContext* ctx,
    int gridW, int gridH,
    int cellX0, int cellZ0,
    int x0, int z0, int w, int h,
    int predicate,
    int oldStartSizeY, int newStartSizeY,
    int* heightsOut)
{
    if (!ctx) return -1;
    if (gridW <= 0 || gridH <= 0 || w <= 0 || h <= 0) return -1;
    if (newStartSizeY <= oldStartSizeY) return -1;
    if (newStartSizeY + 1 > ctx->allocStride) return -1;   // ne tient pas

    const int numColumns = gridW * gridH;
    const int numQueries = w * h;
    if (numColumns > ctx->maxColumns || numQueries > ctx->maxQueries) return -1;

    ctx->hostCfg.startSizeY = newStartSizeY;

    // Seule la tranche manquante est calculee. La sentinelle passe de
    // oldStartSizeY (dont la vraie valeur est justement recalculee ici) a
    // newStartSizeY. Colonnes et randomOffsets sont deja sur le device.
    if (launch_columns(ctx, nullptr, numColumns,
                       oldStartSizeY, newStartSizeY, newStartSizeY,
                       false, false) != 0)
        return -1;

    const int minCellY = height_scan_floor(&ctx->hostCfg, predicate);
    int gridSize = (numQueries + HEIGHT_BLOCK - 1) / HEIGHT_BLOCK;
    compute_heightmap_rect<<<gridSize, HEIGHT_BLOCK>>>(
        ctx->d_cfg, ctx->d_noiseGrid, newStartSizeY, minCellY, ctx->allocStride,
        gridW, cellX0, cellZ0, x0, z0, w, h, predicate, ctx->d_heights);
    CUDA_CHECK_INT(cudaGetLastError());

    return finish_batch(ctx, heightsOut, numQueries);
}
