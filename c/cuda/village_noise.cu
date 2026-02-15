/**
 * village_noise.cu — CUDA kernels for batch sampleSurfaceNoise + height computation
 *
 * Strategy:
 *   Kernel 1 (compute_noise_columns):
 *     One thread per (column, y).  Each thread computes sampleSurfaceNoise(cellX, y, cellZ)
 *     then applies density/slide math to produce one noise value.
 *     Output: double noiseGrid[numColumns][noiseSizeY+1]
 *
 *   Kernel 2 (compute_heights):
 *     One thread per height query.  Each thread reads 4 corner columns from noiseGrid,
 *     interpolates trilinearly top-down, and finds the first solid block.
 *     Output: HeightResult[numQueries]
 */

#include "village_noise.cuh"
#include <math.h>
#include <stdio.h>

// ============================================================================
// Device helpers
// ============================================================================

__device__ static inline double d_lerp(double part, double from, double to)
{
    return from + part * (to - from);
}

__device__ static inline double d_clampedLerp(double part, double from, double to)
{
    if (part <= 0.0) return from;
    if (part >= 1.0) return to;
    return d_lerp(part, from, to);
}

// indexedLerp — port of cubiomes noise.c
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

// samplePerlin — direct port of cubiomes noise.c:109-208
__device__ static double d_samplePerlin(
    const GpuPerlinNoise* noise,
    double d1, double d2, double d3,
    double yamp, double ymin)
{
    uint8_t h1, h2, h3;
    double t1, t2, t3;

    if (d2 == 0.0) {
        d2 = noise->d2;
        h2 = noise->h2;
        t2 = noise->t2;
    } else {
        d2 += noise->b;
        double i2 = floor(d2);
        d2 -= i2;
        h2 = (uint8_t)(int)i2;
        t2 = d2*d2*d2 * (d2 * (d2*6.0-15.0) + 10.0);
    }

    d1 += noise->a;
    d3 += noise->c;

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

    const uint8_t* idx = noise->d;

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

// sampleSurfaceNoise — port of cubiomes biomenoise.c:118-158
__device__ static double d_sampleSurfaceNoise(
    const GpuSurfaceNoise* sn,
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

    for (int i = 0; i < 16; i++) {
        double dx = x * xzScale * persist;
        double dy = y * yScale  * persist;
        double dz = z * xzScale * persist;
        double sy = yScale * persist;
        double ty = y * sy;

        minNoise += d_samplePerlin(&sn->octmin[i], dx, dy, dz, sy, ty) * contrib;
        maxNoise += d_samplePerlin(&sn->octmax[i], dx, dy, dz, sy, ty) * contrib;

        if (i < 8) {
            double dx2 = x * xzStep * persist;
            double dy2 = y * yStep  * persist;
            double dz2 = z * xzStep * persist;
            double sy2 = yStep * persist;
            double ty2 = y * sy2;
            mainNoise += d_samplePerlin(&sn->octmain[i], dx2, dy2, dz2, sy2, ty2) * contrib;
        }

        persist *= 0.5;
        contrib *= 2.0;
    }

    return d_clampedLerp(0.5 + 0.05 * mainNoise, minNoise / 512.0, maxNoise / 512.0);
}

// ============================================================================
// Kernel 1: compute noise columns
// Grid: (numColumns, startSizeY) — one thread per (column, y)
// Output: noiseGrid[col * (noiseSizeY+1) + y]
// ============================================================================

__global__ void compute_noise_columns(
    const GpuSurfaceNoise* __restrict__ sn,
    const GpuSurfaceGenConfig* __restrict__ cfg,
    const ColumnParams* __restrict__ columns,
    int numColumns,
    double* __restrict__ noiseGrid)
{
    int col = blockIdx.x * blockDim.x + threadIdx.x;
    int y   = blockIdx.y * blockDim.y + threadIdx.y;

    if (col >= numColumns || y >= cfg->startSizeY)
        return;

    const ColumnParams* cp = &columns[col];
    int stride = cfg->noiseSizeY + 1;

    // Sample 3D noise
    double noise = d_sampleSurfaceNoise(sn, cp->cellX, y, cp->cellZ);

    // Density + falloff (1.16+ branch)
    double fallOff1 = 1.0 - (double)y * 2.0 / (double)cfg->noiseSizeY + cp->randomOffset;
    double fallOff2 = fallOff1 * cfg->densityFactor + cfg->densityOffset;
    double fallOff3 = (fallOff2 + cp->depth) * cp->scale;

    if (fallOff3 > 0.0)
        noise += fallOff3 * 4.0;
    else
        noise += fallOff3;

    // Top slide
    if (cfg->topSlideSize > 0.0) {
        double num = ((double)(cfg->noiseSizeY - y) - cfg->topSlideOffset) / cfg->topSlideSize;
        noise = d_clampedLerp(cfg->topSlideTarget, noise, num);
    }
    // Bottom slide
    if (cfg->botSlideSize > 0.0) {
        double num = ((double)y - cfg->botSlideOffset) / cfg->botSlideSize;
        noise = d_clampedLerp(cfg->botSlideTarget, noise, num);
    }

    noiseGrid[col * stride + y] = noise;

    // The slot at y=startSizeY should be 0 (matches calloc behavior in CPU code)
    // We only need to zero it once per column — let the y=0 thread do it
    if (y == 0) {
        noiseGrid[col * stride + cfg->startSizeY] = 0.0;
    }
}

// ============================================================================
// Kernel 2: compute heights from noise grid
// One thread per height query
// ============================================================================

__global__ void compute_heights(
    const GpuSurfaceGenConfig* __restrict__ cfg,
    const double* __restrict__ noiseGrid,
    const HeightQuery* __restrict__ queries,
    const int* __restrict__ cornerIndices,   // [numQueries * 4]
    int numQueries,
    HeightResult* __restrict__ results)
{
    int qIdx = blockIdx.x * blockDim.x + threadIdx.x;
    if (qIdx >= numQueries)
        return;

    const HeightQuery* q = &queries[qIdx];
    int stride = cfg->noiseSizeY + 1;

    // Get the 4 corner column indices
    int c0 = cornerIndices[qIdx * 4 + 0];  // (cellX, cellZ)
    int c1 = cornerIndices[qIdx * 4 + 1];  // (cellX, cellZ+1)
    int c2 = cornerIndices[qIdx * 4 + 2];  // (cellX+1, cellZ)
    int c3 = cornerIndices[qIdx * 4 + 3];  // (cellX+1, cellZ+1)

    const double* col0 = noiseGrid + c0 * stride;
    const double* col1 = noiseGrid + c1 * stride;
    const double* col2 = noiseGrid + c2 * stride;
    const double* col3 = noiseGrid + c3 * stride;

    // Local coordinates within cell
    int cellX = (int)floor((double)q->worldX / (double)cfg->chunkWidth);
    int cellZ = (int)floor((double)q->worldZ / (double)cfg->chunkWidth);

    int posX = ((q->worldX % cfg->chunkWidth) + cfg->chunkWidth) % cfg->chunkWidth;
    int posZ = ((q->worldZ % cfg->chunkWidth) + cfg->chunkWidth) % cfg->chunkWidth;

    double percentX = (double)posX / (double)cfg->chunkWidth;
    double percentZ = (double)posZ / (double)cfg->chunkWidth;

    // Scan top-down for first solid block
    for (int cellY = cfg->startSizeY - 1; cellY >= 0; --cellY) {
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

            // Trilinear interpolation (Mojang order)
            double v000 = d_lerp(percentX, xyz, x1yz);
            double v010 = d_lerp(percentX, xy1z, x1y1z);
            double v001 = d_lerp(percentX, xyz1, x1yz1);
            double v011 = d_lerp(percentX, xy1z1, x1y1z1);

            double v00 = d_lerp(percentY, v000, v010);
            double v01 = d_lerp(percentY, v001, v011);

            double noise = d_lerp(percentZ, v00, v01);

            int y = cellY * cfg->chunkHeight + posY;

            // get_block_from_noise logic inline
            // noise > 0 => STONE, y < seaLevel => WATER, else AIR
            // WORLD_SURFACE_WG predicate: STONE or WATER = solid
            if (noise > 0.0 || y < cfg->seaLevel) {
                // Found solid block (not air)
                results[qIdx].height = y + 1;
                return;
            }
        }
    }

    results[qIdx].height = 0;
}

// ============================================================================
// Host-side context and API implementation
// ============================================================================

struct CudaNoiseContext {
    // Device pointers
    GpuSurfaceNoise*    d_sn;
    GpuSurfaceGenConfig* d_cfg;
    ColumnParams*       d_columns;
    double*             d_noiseGrid;
    HeightQuery*        d_queries;
    int*                d_cornerIndices;
    HeightResult*       d_results;

    // Config copy for kernel launch dims
    GpuSurfaceGenConfig hostCfg;
    int maxColumns;
    int maxQueries;
    int noiseSizeY;
};

#define CUDA_CHECK(call) do { \
    cudaError_t err = (call); \
    if (err != cudaSuccess) { \
        fprintf(stderr, "CUDA error at %s:%d: %s\n", __FILE__, __LINE__, \
                cudaGetErrorString(err)); \
        return nullptr; \
    } \
} while(0)

#define CUDA_CHECK_INT(call) do { \
    cudaError_t err = (call); \
    if (err != cudaSuccess) { \
        fprintf(stderr, "CUDA error at %s:%d: %s\n", __FILE__, __LINE__, \
                cudaGetErrorString(err)); \
        return -1; \
    } \
} while(0)

CudaNoiseContext* cuda_noise_init(
    const GpuSurfaceNoise* hostSN,
    const GpuSurfaceGenConfig* hostCfg,
    int maxColumns,
    int maxQueries)
{
    CudaNoiseContext* ctx = new CudaNoiseContext();
    ctx->hostCfg = *hostCfg;
    ctx->maxColumns = maxColumns;
    ctx->maxQueries = maxQueries;
    ctx->noiseSizeY = hostCfg->noiseSizeY;

    int stride = hostCfg->noiseSizeY + 1;

    // Allocate and upload constant data (SurfaceNoise + config)
    CUDA_CHECK(cudaMalloc(&ctx->d_sn, sizeof(GpuSurfaceNoise)));
    CUDA_CHECK(cudaMemcpy(ctx->d_sn, hostSN, sizeof(GpuSurfaceNoise), cudaMemcpyHostToDevice));

    CUDA_CHECK(cudaMalloc(&ctx->d_cfg, sizeof(GpuSurfaceGenConfig)));
    CUDA_CHECK(cudaMemcpy(ctx->d_cfg, hostCfg, sizeof(GpuSurfaceGenConfig), cudaMemcpyHostToDevice));

    // Allocate per-batch buffers
    CUDA_CHECK(cudaMalloc(&ctx->d_columns, sizeof(ColumnParams) * maxColumns));
    CUDA_CHECK(cudaMalloc(&ctx->d_noiseGrid, sizeof(double) * maxColumns * stride));
    CUDA_CHECK(cudaMalloc(&ctx->d_queries, sizeof(HeightQuery) * maxQueries));
    CUDA_CHECK(cudaMalloc(&ctx->d_cornerIndices, sizeof(int) * maxQueries * 4));
    CUDA_CHECK(cudaMalloc(&ctx->d_results, sizeof(HeightResult) * maxQueries));

    return ctx;
}

void cuda_noise_destroy(CudaNoiseContext* ctx)
{
    if (!ctx) return;
    cudaFree(ctx->d_sn);
    cudaFree(ctx->d_cfg);
    cudaFree(ctx->d_columns);
    cudaFree(ctx->d_noiseGrid);
    cudaFree(ctx->d_queries);
    cudaFree(ctx->d_cornerIndices);
    cudaFree(ctx->d_results);
    delete ctx;
}

int cuda_noise_batch_heights(
    CudaNoiseContext* ctx,
    const ColumnParams* columns, int numColumns,
    const HeightQuery* queries, int numQueries,
    const int* queryCornerIndices,
    HeightResult* results)
{
    if (numColumns > ctx->maxColumns || numQueries > ctx->maxQueries) {
        fprintf(stderr, "cuda_noise_batch_heights: batch too large (%d cols, %d queries)\n",
                numColumns, numQueries);
        return -1;
    }

    int startSizeY = ctx->hostCfg.startSizeY;

    // Upload batch data
    CUDA_CHECK_INT(cudaMemcpy(ctx->d_columns, columns,
        sizeof(ColumnParams) * numColumns, cudaMemcpyHostToDevice));
    CUDA_CHECK_INT(cudaMemcpy(ctx->d_queries, queries,
        sizeof(HeightQuery) * numQueries, cudaMemcpyHostToDevice));
    CUDA_CHECK_INT(cudaMemcpy(ctx->d_cornerIndices, queryCornerIndices,
        sizeof(int) * numQueries * 4, cudaMemcpyHostToDevice));

    // Kernel 1: compute noise columns
    // Grid: x = columns, y = startSizeY
    {
        dim3 block(16, 16);  // 16 columns * 16 y-values = 256 threads per block
        dim3 grid(
            (numColumns + block.x - 1) / block.x,
            (startSizeY + block.y - 1) / block.y
        );
        compute_noise_columns<<<grid, block>>>(
            ctx->d_sn, ctx->d_cfg, ctx->d_columns,
            numColumns, ctx->d_noiseGrid
        );
        CUDA_CHECK_INT(cudaGetLastError());
        CUDA_CHECK_INT(cudaDeviceSynchronize());
    }

    // DEBUG: dump first column's noise values
    {
        int stride = ctx->hostCfg.noiseSizeY + 1;
        int debugSize = startSizeY + 1;
        double* debugBuf = new double[debugSize];
        cudaMemcpy(debugBuf, ctx->d_noiseGrid, sizeof(double) * debugSize, cudaMemcpyDeviceToHost);
        fprintf(stderr, "DEBUG noiseGrid col0 (stride=%d, startSizeY=%d):\n", stride, startSizeY);
        for (int y = 0; y <= startSizeY && y < debugSize; y++) {
            fprintf(stderr, "  y=%2d: %.6f\n", y, debugBuf[y]);
        }
        delete[] debugBuf;
    }

    // Kernel 2: compute heights
    {
        int blockSize = 256;
        int gridSize = (numQueries + blockSize - 1) / blockSize;
        compute_heights<<<gridSize, blockSize>>>(
            ctx->d_cfg, ctx->d_noiseGrid,
            ctx->d_queries, ctx->d_cornerIndices,
            numQueries, ctx->d_results
        );
        CUDA_CHECK_INT(cudaGetLastError());
        CUDA_CHECK_INT(cudaDeviceSynchronize());
    }

    // Download results
    CUDA_CHECK_INT(cudaMemcpy(results, ctx->d_results,
        sizeof(HeightResult) * numQueries, cudaMemcpyDeviceToHost));

    return 0;
}
