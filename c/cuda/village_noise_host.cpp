/**
 * village_noise_host.cpp — Host-side helper to convert cubiomes SurfaceNoise
 * to GPU-friendly structures and batch height queries.
 *
 * This file is compiled with g++ (NOT nvcc). It only uses the CUDA API
 * through the C interface declared in village_noise.cuh.
 */

#include "village_noise.cuh"

// Include cubiomes headers for SurfaceNoise, PerlinNoise, etc.
extern "C" {
    #include "noise.h"
    #include "biomenoise.h"
}

#include "../surface_gen.h"
#include "../cubiomes_integration.h"

#include <cstring>
#include <cmath>
#include <unordered_map>
#include <vector>

// ============================================================================
// Convert cubiomes PerlinNoise → GpuPerlinNoise
// ============================================================================

static void convertPerlin(GpuPerlinNoise* dst, const PerlinNoise* src)
{
    memcpy(dst->d, src->d, 257);
    dst->h2 = src->h2;
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
    dst->amplitude = src->amplitude;
    dst->lacunarity = src->lacunarity;
    dst->d2 = src->d2;
    dst->t2 = src->t2;
}

// ============================================================================
// Convert cubiomes SurfaceNoise → GpuSurfaceNoise
// ============================================================================

void convertSurfaceNoise(GpuSurfaceNoise* dst, const SurfaceNoise* src)
{
    dst->xzScale = src->xzScale;
    dst->yScale  = src->yScale;
    dst->xzFactor = src->xzFactor;
    dst->yFactor  = src->yFactor;

    dst->octminCnt  = src->octmin.octcnt;
    dst->octmaxCnt  = src->octmax.octcnt;
    dst->octmainCnt = src->octmain.octcnt;

    for (int i = 0; i < 16 && i < src->octmin.octcnt; i++)
        convertPerlin(&dst->octmin[i], &src->octmin.octaves[i]);
    for (int i = 0; i < 16 && i < src->octmax.octcnt; i++)
        convertPerlin(&dst->octmax[i], &src->octmax.octaves[i]);
    for (int i = 0; i < 8 && i < src->octmain.octcnt; i++)
        convertPerlin(&dst->octmain[i], &src->octmain.octaves[i]);
}

// ============================================================================
// Convert SurfaceGen config → GpuSurfaceGenConfig
// ============================================================================

void convertSurfaceGenConfig(GpuSurfaceGenConfig* dst, const SurfaceGen* src)
{
    dst->chunkWidth   = src->chunkWidth;
    dst->chunkHeight  = src->chunkHeight;
    dst->startSizeY   = src->startSizeY;
    dst->noiseSizeY   = src->noiseSizeY;
    dst->seaLevel     = src->seaLevel;
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
// CudaHeightBatcher — collects height queries, deduplicates columns, batches
// ============================================================================

class CudaHeightBatcher {
public:
    CudaHeightBatcher(CubiomesContext* cubiomesCtx, SurfaceGen* sg,
                      int maxColumns = 4096, int maxQueries = 2048)
        : cubiomesCtx_(cubiomesCtx), sg_(sg),
          maxColumns_(maxColumns), maxQueries_(maxQueries),
          cudaCtx_(nullptr)
    {
        // Convert cubiomes structures to GPU format
        convertSurfaceNoise(&gpuSN_, &cubiomesCtx->sn);
        convertSurfaceGenConfig(&gpuCfg_, sg);

        // Initialize CUDA context
        cudaCtx_ = cuda_noise_init(&gpuSN_, &gpuCfg_, maxColumns, maxQueries);
        if (!cudaCtx_) {
            fprintf(stderr, "CudaHeightBatcher: failed to initialize CUDA context\n");
        }
    }

    ~CudaHeightBatcher() {
        if (cudaCtx_) cuda_noise_destroy(cudaCtx_);
    }

    // Add a height query. Returns the index in the results array.
    int addQuery(int worldX, int worldZ) {
        int idx = (int)queries_.size();
        queries_.push_back({worldX, worldZ});

        // Compute which 4 cell corners this query needs
        int cellX = (int)floor((double)worldX / (double)gpuCfg_.chunkWidth);
        int cellZ = (int)floor((double)worldZ / (double)gpuCfg_.chunkWidth);

        int corners[4][2] = {
            {cellX, cellZ}, {cellX, cellZ+1},
            {cellX+1, cellZ}, {cellX+1, cellZ+1}
        };

        for (int i = 0; i < 4; i++) {
            int colIdx = getOrCreateColumn(corners[i][0], corners[i][1]);
            cornerIndices_.push_back(colIdx);
        }

        return idx;
    }

    // Execute the batch on GPU. Returns 0 on success.
    int execute() {
        if (!cudaCtx_ || queries_.empty()) return -1;

        results_.resize(queries_.size());

        return cuda_noise_batch_heights(
            cudaCtx_,
            columns_.data(), (int)columns_.size(),
            queries_.data(), (int)queries_.size(),
            cornerIndices_.data(),
            results_.data()
        );
    }

    // Get result for query at index
    int getHeight(int queryIdx) const {
        if (queryIdx < 0 || queryIdx >= (int)results_.size()) return 0;
        return results_[queryIdx].height;
    }

    // Reset for a new batch (same seed/noise)
    void reset() {
        queries_.clear();
        columns_.clear();
        cornerIndices_.clear();
        results_.clear();
        columnMap_.clear();
    }

    bool isValid() const { return cudaCtx_ != nullptr; }

private:
    int getOrCreateColumn(int cellX, int cellZ) {
        uint64_t key = ((uint64_t)(uint32_t)cellX << 32) | (uint64_t)(uint32_t)cellZ;
        auto it = columnMap_.find(key);
        if (it != columnMap_.end()) return it->second;

        int idx = (int)columns_.size();
        columnMap_[key] = idx;

        // Compute depth/scale/randomOffset on CPU (uses cubiomes biome lookup)
        ColumnParams cp;
        cp.cellX = cellX;
        cp.cellZ = cellZ;

        double ds[2] = {0.0, 0.0};
        cubiomes_get_depth_and_scale(cellX, cellZ, ds, cubiomesCtx_);
        cp.depth = ds[0];
        cp.scale = ds[1];
        cp.randomOffset = 0.0;
        if (sg_->dim == 0) { // DIM_OVERWORLD
            cp.randomOffset = cubiomes_noise_2d(cellX, cellZ, cubiomesCtx_);
        }

        columns_.push_back(cp);
        return idx;
    }

    CubiomesContext* cubiomesCtx_;
    SurfaceGen* sg_;
    GpuSurfaceNoise gpuSN_;
    GpuSurfaceGenConfig gpuCfg_;
    CudaNoiseContext* cudaCtx_;
    int maxColumns_, maxQueries_;

    std::vector<HeightQuery> queries_;
    std::vector<ColumnParams> columns_;
    std::vector<int> cornerIndices_;
    std::vector<HeightResult> results_;
    std::unordered_map<uint64_t, int> columnMap_;
};
