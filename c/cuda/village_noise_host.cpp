/**
 * village_noise_host.cpp — converts cubiomes state to the GPU layout and
 * drives the batched height computation.
 */

#include "village_noise_host.hpp"

extern "C" {
    #include "noise.h"
    #include "biomenoise.h"
    #include "biomes.h"
}

#include <cstring>
#include <cmath>
#include <cstdio>
#include <chrono>

// ============================================================================
// cubiomes -> GPU structure conversion
// ============================================================================

static void convertPerlin(GpuPerlinParams* params, uint8_t* perm, const PerlinNoise* src)
{
    memcpy(perm, src->d, 257);
    params->a  = src->a;
    params->b  = src->b;
    params->c  = src->c;
    params->d2 = src->d2;
    params->t2 = src->t2;
    params->amplitude  = src->amplitude;
    params->lacunarity = src->lacunarity;
    params->h2 = (int)src->h2;
    params->_pad = 0;
}

void convertSurfaceNoise(GpuSurfaceNoise* dst, const SurfaceNoise* src)
{
    memset(dst, 0, sizeof(*dst));

    dst->xzScale  = src->xzScale;
    dst->yScale   = src->yScale;
    dst->xzFactor = src->xzFactor;
    dst->yFactor  = src->yFactor;

    // The kernel assumes the canonical 16/16/8 octave counts of the 1.16+
    // overworld surface noise. Anything else would silently produce garbage.
    if (src->octmin.octcnt   != GPU_OCT_MIN  ||
        src->octmax.octcnt   != GPU_OCT_MAX  ||
        src->octmain.octcnt  != GPU_OCT_MAIN ||
        src->octdepth.octcnt != GPU_OCT_DEPTH) {
        fprintf(stderr, "convertSurfaceNoise: unexpected octave counts "
                        "(min=%d max=%d main=%d depth=%d, expected %d/%d/%d/%d)\n",
                src->octmin.octcnt, src->octmax.octcnt, src->octmain.octcnt,
                src->octdepth.octcnt,
                GPU_OCT_MIN, GPU_OCT_MAX, GPU_OCT_MAIN, GPU_OCT_DEPTH);
    }

    for (int i = 0; i < GPU_OCT_MIN && i < src->octmin.octcnt; i++)
        convertPerlin(&dst->oct[i], dst->perm[i], &src->octmin.octaves[i]);
    for (int i = 0; i < GPU_OCT_MAX && i < src->octmax.octcnt; i++)
        convertPerlin(&dst->oct[GPU_OCT_MIN + i], dst->perm[GPU_OCT_MIN + i],
                      &src->octmax.octaves[i]);
    for (int i = 0; i < GPU_OCT_MAIN && i < src->octmain.octcnt; i++)
        convertPerlin(&dst->oct[GPU_OCT_MIN + GPU_OCT_MAX + i],
                      dst->perm[GPU_OCT_MIN + GPU_OCT_MAX + i],
                      &src->octmain.octaves[i]);
    for (int i = 0; i < GPU_OCT_DEPTH && i < src->octdepth.octcnt; i++)
        convertPerlin(&dst->oct[GPU_OCT_SURF + i], dst->perm[GPU_OCT_SURF + i],
                      &src->octdepth.octaves[i]);
}

void convertSurfaceGenConfig(GpuSurfaceGenConfig* dst, const SurfaceGen* src)
{
    memset(dst, 0, sizeof(*dst));

    dst->chunkWidth    = src->chunkWidth;
    dst->chunkHeight   = src->chunkHeight;
    dst->startSizeY    = src->startSizeY;
    dst->noiseSizeY    = src->noiseSizeY;
    dst->seaLevel      = src->seaLevel;
    dst->dim           = src->dim;
    dst->densityFactor = src->densityFactor;
    dst->densityOffset = src->densityOffset;

    dst->topSlideTarget = src->noiseSettings.topSlideSettings.target;
    dst->topSlideSize   = src->noiseSettings.topSlideSettings.size;
    dst->topSlideOffset = src->noiseSettings.topSlideSettings.offset;
    dst->botSlideTarget = src->noiseSettings.bottomSlideSettings.target;
    dst->botSlideSize   = src->noiseSettings.bottomSlideSettings.size;
    dst->botSlideOffset = src->noiseSettings.bottomSlideSettings.offset;
}

// ============================================================================
// CudaHeightBatcher
// ============================================================================

CudaHeightBatcher::CudaHeightBatcher(CubiomesContext* cubiomesCtx, SurfaceGen* sg,
                                     int maxColumns, int maxQueries)
    : cubiomesCtx_(cubiomesCtx), sg_(sg), cudaCtx_(nullptr)
{
    convertSurfaceNoise(&gpuSN_, &cubiomesCtx->sn);
    convertSurfaceGenConfig(&gpuCfg_, sg);

    capColumns_ = maxColumns > 0 ? maxColumns : 1;
    capQueries_ = maxQueries > 0 ? maxQueries : 1;
    cudaCtx_ = cuda_noise_init(&gpuSN_, &gpuCfg_, capColumns_, capQueries_);
    if (!cudaCtx_)
        fprintf(stderr, "CudaHeightBatcher: failed to initialize CUDA context\n");
}

bool CudaHeightBatcher::bind(CubiomesContext* cubiomesCtx, SurfaceGen* sg)
{
    if (!cubiomesCtx || !sg) return false;

    cubiomesCtx_ = cubiomesCtx;
    sg_ = sg;
    reset();

    convertSurfaceNoise(&gpuSN_, &cubiomesCtx->sn);
    convertSurfaceGenConfig(&gpuCfg_, sg);

    if (cudaCtx_ && cuda_noise_update_state(cudaCtx_, &gpuSN_, &gpuCfg_) == 0)
        return true;

    // L'allocation en place ne convient pas (startSizeY plus grand qu'à
    // l'initialisation) : on recrée le contexte.
    if (cudaCtx_) cuda_noise_destroy(cudaCtx_);
    cudaCtx_ = cuda_noise_init(&gpuSN_, &gpuCfg_, capColumns_, capQueries_);
    if (!cudaCtx_) {
        fprintf(stderr, "CudaHeightBatcher::bind: failed to re-create the CUDA context\n");
        return false;
    }
    return true;
}

bool CudaHeightBatcher::prepareDevice(int columns, int queries)
{
    if (!cudaCtx_) return false;

    // convertSurfaceGenConfig memsets the struct first, so padding is zeroed
    // and memcmp is a valid equality test here.
    GpuSurfaceGenConfig current;
    convertSurfaceGenConfig(&current, sg_);
    bool configChanged = memcmp(&current, &gpuCfg_, sizeof(current)) != 0;
    bool tooSmall = (columns > capColumns_ || queries > capQueries_);

    if (!configChanged && !tooSmall) return true;

    gpuCfg_ = current;
    while (capColumns_ < columns) capColumns_ *= 2;
    while (capQueries_ < queries) capQueries_ *= 2;

    cuda_noise_destroy(cudaCtx_);
    cudaCtx_ = cuda_noise_init(&gpuSN_, &gpuCfg_, capColumns_, capQueries_);
    if (!cudaCtx_) {
        fprintf(stderr, "CudaHeightBatcher: failed to re-create the CUDA context "
                        "(%d columns / %d queries)\n", capColumns_, capQueries_);
        return false;
    }
    return true;
}

CudaHeightBatcher::~CudaHeightBatcher()
{
    if (cudaCtx_) cuda_noise_destroy(cudaCtx_);
}

ColumnParams CudaHeightBatcher::makeColumn(int cellX, int cellZ) const
{
    ColumnParams cp;
    cp.cellX = cellX;
    cp.cellZ = cellZ;

    double ds[2] = {0.0, 0.0};
    cubiomes_get_depth_and_scale(cellX, cellZ, ds, cubiomesCtx_);
    cp.depth = ds[0];
    cp.scale = ds[1];
    return cp;
}

int CudaHeightBatcher::heightmap(int x0, int z0, int w, int h,
                                 int predicate, int* heightsOut)
{
    if (!cudaCtx_ || w <= 0 || h <= 0 || !heightsOut) return -1;

    const int cw = gpuCfg_.chunkWidth;
    const int cellX0 = (int)std::floor((double)x0 / (double)cw);
    const int cellZ0 = (int)std::floor((double)z0 / (double)cw);
    const int cellX1 = (int)std::floor((double)(x0 + w - 1) / (double)cw);
    const int cellZ1 = (int)std::floor((double)(z0 + h - 1) / (double)cw);

    // +2: the scan needs cellX+1 / cellZ+1 for the far corner.
    const int gridW = cellX1 - cellX0 + 2;
    const int gridH = cellZ1 - cellZ0 + 2;

    if (!prepareDevice(gridW * gridH, w * h)) return -1;

    auto t0 = std::chrono::high_resolution_clock::now();
    const size_t n = (size_t)gridW * gridH;
    columns_.resize(n);

    // One genBiomes() call for the whole grid instead of one per column.
    depthScratch_.resize(n);
    scaleScratch_.resize(n);
    bool batched = cubiomes_get_depth_and_scale_grid(
        cubiomesCtx_, cellX0, cellZ0, gridW, gridH,
        depthScratch_.data(), scaleScratch_.data()) == 0;

    for (int cz = 0; cz < gridH; cz++) {
        for (int cx = 0; cx < gridW; cx++) {
            const size_t i = (size_t)cz * gridW + cx;
            if (!batched) {
                columns_[i] = makeColumn(cellX0 + cx, cellZ0 + cz);
                continue;
            }
            ColumnParams& cp = columns_[i];
            cp.cellX = cellX0 + cx;
            cp.cellZ = cellZ0 + cz;
            cp.depth = depthScratch_[i];
            cp.scale = scaleScratch_[i];
        }
    }
    auto t1 = std::chrono::high_resolution_clock::now();
    lastPrepMs_ = std::chrono::duration<double, std::milli>(t1 - t0).count();
    lastColumnCount_ = gridW * gridH;

    return cuda_noise_heightmap(cudaCtx_, columns_.data(), gridW, gridH,
                                cellX0, cellZ0, x0, z0, w, h,
                                predicate, heightsOut);
}

void CudaHeightBatcher::lastGpuTimings(float* upload, float* columnsKernel,
                                       float* heightsKernel, float* download) const
{
    cuda_noise_last_timings(cudaCtx_, upload, columnsKernel, heightsKernel, download);
}

void CudaHeightBatcher::reset()
{
    queryX_.clear();
    queryZ_.clear();
    columns_.clear();
    cornerIndices_.clear();
    heights_.clear();
    columnMap_.clear();
    lastPrepMs_ = 0.0;
    lastColumnCount_ = 0;
}

int CudaHeightBatcher::getOrCreateColumn(int cellX, int cellZ)
{
    uint64_t key = ((uint64_t)(uint32_t)cellX << 32) | (uint64_t)(uint32_t)cellZ;
    auto it = columnMap_.find(key);
    if (it != columnMap_.end()) return it->second;

    int idx = (int)columns_.size();
    columnMap_[key] = idx;
    columns_.push_back(makeColumn(cellX, cellZ));
    return idx;
}

int CudaHeightBatcher::addQuery(int worldX, int worldZ)
{
    auto t0 = std::chrono::high_resolution_clock::now();

    int idx = (int)queryX_.size();
    queryX_.push_back(worldX);
    queryZ_.push_back(worldZ);

    const int cw = gpuCfg_.chunkWidth;
    int cellX = (int)std::floor((double)worldX / (double)cw);
    int cellZ = (int)std::floor((double)worldZ / (double)cw);

    const int corners[4][2] = {
        {cellX, cellZ}, {cellX, cellZ + 1},
        {cellX + 1, cellZ}, {cellX + 1, cellZ + 1}
    };
    for (int i = 0; i < 4; i++)
        cornerIndices_.push_back(getOrCreateColumn(corners[i][0], corners[i][1]));

    auto t1 = std::chrono::high_resolution_clock::now();
    lastPrepMs_ += std::chrono::duration<double, std::milli>(t1 - t0).count();
    return idx;
}

int CudaHeightBatcher::execute(int predicate)
{
    if (!cudaCtx_ || queryX_.empty()) return -1;
    if (!prepareDevice((int)columns_.size(), (int)queryX_.size())) return -1;

    heights_.resize(queryX_.size());
    lastColumnCount_ = (int)columns_.size();

    return cuda_noise_batch_heights(
        cudaCtx_,
        columns_.data(), (int)columns_.size(),
        queryX_.data(), queryZ_.data(), (int)queryX_.size(),
        cornerIndices_.data(),
        predicate,
        heights_.data());
}

int CudaHeightBatcher::getHeight(int queryIdx) const
{
    if (queryIdx < 0 || queryIdx >= (int)heights_.size()) return 0;
    return heights_[queryIdx];
}
