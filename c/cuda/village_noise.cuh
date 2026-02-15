#pragma once

#include <cstdint>
#include <cstddef>

// ============================================================================
// GPU-side structures (flat, no pointers — copied to device memory)
// ============================================================================

// Mirrors cubiomes PerlinNoise but fully self-contained
struct GpuPerlinNoise {
    uint8_t d[257];     // permutation table (256 + wrap)
    uint8_t h2;
    double a, b, c;
    double amplitude;
    double lacunarity;
    double d2, t2;
};

// All octaves for SurfaceNoise flattened: 16 min + 16 max + 8 main = 40
// (octsurf and octdepth are NOT used by sampleSurfaceNoise)
struct GpuSurfaceNoise {
    double xzScale, yScale;
    double xzFactor, yFactor;
    int octminCnt;   // should be 16
    int octmaxCnt;   // should be 16
    int octmainCnt;  // should be 8
    GpuPerlinNoise octmin[16];
    GpuPerlinNoise octmax[16];
    GpuPerlinNoise octmain[8];
};

// Parameters for one noise column (pre-computed on CPU from biome data)
struct ColumnParams {
    int cellX, cellZ;       // cell coordinates in noise grid
    double depth, scale;    // from get_depth_and_scale
    double randomOffset;    // from sample_noise_2d (overworld only)
};

// Height query: one (x, z) world-coordinate point to compute height for
struct HeightQuery {
    int worldX, worldZ;
};

// Result: height at that point
struct HeightResult {
    int height;             // Y of first solid block (0 if none found)
};

// SurfaceGen config needed on GPU for column→height conversion
struct GpuSurfaceGenConfig {
    int chunkWidth;         // 4
    int chunkHeight;        // 8
    int startSizeY;         // typically ~10
    int noiseSizeY;         // typically == startSizeY (or larger)
    int seaLevel;           // 63
    double densityFactor;
    double densityOffset;
    // slide settings
    double topSlideTarget, topSlideSize, topSlideOffset;
    double botSlideTarget, botSlideSize, botSlideOffset;
};

// ============================================================================
// Host-side API
// ============================================================================

#ifdef __cplusplus
extern "C" {
#endif

// Opaque handle for GPU resources
typedef struct CudaNoiseContext CudaNoiseContext;

// Initialize: uploads SurfaceNoise data to GPU, allocates buffers
// Returns nullptr on failure
CudaNoiseContext* cuda_noise_init(
    const GpuSurfaceNoise* hostSN,
    const GpuSurfaceGenConfig* hostCfg,
    int maxColumns,         // max number of unique columns per batch
    int maxQueries          // max number of height queries per batch
);

// Free GPU resources
void cuda_noise_destroy(CudaNoiseContext* ctx);

// Batch compute heights:
//   1. Upload column params (unique cell corners) + height queries
//   2. GPU computes all noise columns in parallel
//   3. GPU computes height for each query by interpolating 4 corner columns
//   4. Download results
//
// Returns 0 on success, -1 on error
int cuda_noise_batch_heights(
    CudaNoiseContext* ctx,
    const ColumnParams* columns, int numColumns,
    const HeightQuery* queries, int numQueries,
    // For each query, indices into columns[] for the 4 corners:
    const int* queryCornerIndices,   // [numQueries * 4] — indices of (cellX,cellZ), (cellX,cellZ+1), (cellX+1,cellZ), (cellX+1,cellZ+1)
    HeightResult* results            // [numQueries] — output
);

#ifdef __cplusplus
}
#endif
