#pragma once

/**
 * village_noise_host.hpp — high-level, cubiomes-aware entry points.
 *
 * The GPU only computes the 3D surface noise and the height scan. The biome
 * lookups behind depth/scale stay on the CPU (they are layer-cache driven and
 * do not vectorise), so the batcher pre-computes one ColumnParams per noise
 * cell and hands the whole grid to the device in one shot.
 */

#include "village_noise.cuh"

extern "C" {
    #include "cubiomes_integration.h"
    #include "surface_gen.h"
}

#include <vector>
#include <unordered_map>

/**
 * Batches height queries for a single (seed, SurfaceGen config) pair.
 *
 * Typical use for a rectangular zone:
 *     CudaHeightBatcher b(&ctx, &sg);
 *     b.heightmap(x0, z0, 100, 100, HEIGHT_PRED_NOT_AIR, out);
 *
 * Typical use for scattered points (village piece placement):
 *     b.reset();
 *     int i0 = b.addQuery(x, z); ...
 *     b.execute(HEIGHT_PRED_STONE);
 *     int h = b.getHeight(i0);
 */
class CudaHeightBatcher {
public:
    // The limits are only a starting size: the device buffers grow on demand.
    CudaHeightBatcher(CubiomesContext* cubiomesCtx, SurfaceGen* sg,
                      int maxColumns = 16384, int maxQueries = 65536);
    ~CudaHeightBatcher();

    CudaHeightBatcher(const CudaHeightBatcher&) = delete;
    CudaHeightBatcher& operator=(const CudaHeightBatcher&) = delete;

    bool isValid() const { return cudaCtx_ != nullptr; }

    /**
     * Réassocie le batcher à un autre CubiomesContext / SurfaceGen (autre seed,
     * autre startSizeY). Les buffers device sont conservés quand c'est possible,
     * ce qui évite un cycle cudaFree/cudaMalloc (~5 ms) par village.
     * Renvoie false si la réassociation a échoué.
     */
    bool bind(CubiomesContext* cubiomesCtx, SurfaceGen* sg);

    // ---- rectangular heightmap ----------------------------------------
    // heightsOut must hold w*h ints, row-major: heightsOut[iz * w + ix].
    // Returns 0 on success.
    int heightmap(int x0, int z0, int w, int h, int predicate, int* heightsOut);

    // Milliseconds spent building the ColumnParams grid on the CPU
    // (biome lookups) during the last heightmap()/execute() call.
    double lastColumnPrepMs() const { return lastPrepMs_; }
    int    lastColumnCount()  const { return lastColumnCount_; }

    // Device-side split of the last launch, in ms. Any pointer may be null.
    void lastGpuTimings(float* upload, float* columnsKernel,
                        float* heightsKernel, float* download) const;

    // ---- scattered queries --------------------------------------------
    void reset();
    int  addQuery(int worldX, int worldZ);      // returns the query index
    int  execute(int predicate);                // 0 on success
    int  getHeight(int queryIdx) const;

private:
    ColumnParams makeColumn(int cellX, int cellZ) const;
    int getOrCreateColumn(int cellX, int cellZ);
    // Re-creates the device context when the batch outgrows the buffers or when
    // the SurfaceGen config changed under us (SurfaceGenWrapper::setStartSizeY
    // does exactly that). false on failure.
    bool prepareDevice(int columns, int queries);

    CubiomesContext* cubiomesCtx_;
    SurfaceGen*      sg_;
    GpuSurfaceNoise      gpuSN_;
    GpuSurfaceGenConfig  gpuCfg_;
    CudaNoiseContext*    cudaCtx_;

    std::vector<int>          queryX_, queryZ_;
    std::vector<ColumnParams> columns_;
    std::vector<int>          cornerIndices_;
    std::vector<int>          heights_;
    std::unordered_map<uint64_t, int> columnMap_;
    std::vector<double>       depthScratch_, scaleScratch_;

    int    capColumns_ = 0;
    int    capQueries_ = 0;
    double lastPrepMs_ = 0.0;
    int    lastColumnCount_ = 0;
};
