/**
 * test_cuda.cpp — Validation: compare CUDA batch heights vs CPU generate_column_from_y
 *
 * Build: make -C cuda test_cuda
 * Run:   cd cuda && ./test_cuda
 */

#include "village_noise.cuh"

extern "C" {
    #include "noise.h"
    #include "biomenoise.h"
    #include "generator.h"
}

#include "../surface_gen.h"
#include "../cubiomes_integration.h"

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <chrono>
#include <vector>
#include <unordered_map>

// Forward declarations from village_noise_host.cpp
extern void convertSurfaceNoise(GpuSurfaceNoise* dst, const SurfaceNoise* src);
extern void convertSurfaceGenConfig(GpuSurfaceGenConfig* dst, const SurfaceGen* src);

// Default predicate: not air
static int notAirPredicate(Block block, void* user) {
    return block != BLOCK_AIR;
}

int main(int argc, char** argv)
{
    uint64_t seed = 123456789ULL;
    if (argc > 1) seed = strtoull(argv[1], nullptr, 10);

    printf("=== CUDA village noise test ===\n");
    printf("Seed: %llu\n", (unsigned long long)seed);

    // ---- Setup cubiomes + SurfaceGen (CPU) ----
    CubiomesContext ctx;
    init_cubiomes_context(&ctx, MC_1_16_1, seed);

    SurfaceGen sg;
    memset(&sg, 0, sizeof(sg));
    setup_surface_gen_with_cubiomes(&sg, &ctx);

    // ---- Convert to GPU structures ----
    GpuSurfaceNoise gpuSN;
    memset(&gpuSN, 0, sizeof(gpuSN));
    convertSurfaceNoise(&gpuSN, &ctx.sn);

    GpuSurfaceGenConfig gpuCfg;
    memset(&gpuCfg, 0, sizeof(gpuCfg));
    convertSurfaceGenConfig(&gpuCfg, &sg);

    // ---- Generate test points (random world coords near origin) ----
    int numTests = 500;
    std::vector<int> testX(numTests), testZ(numTests);
    srand(42);
    for (int i = 0; i < numTests; i++) {
        testX[i] = (rand() % 256) - 128;
        testZ[i] = (rand() % 256) - 128;
    }

    // ---- CPU reference ----
    printf("Computing CPU reference heights...\n");
    auto cpuStart = std::chrono::high_resolution_clock::now();
    std::vector<int> cpuHeights(numTests);
    for (int i = 0; i < numTests; i++) {
        cpuHeights[i] = generate_column_from_y(&sg, testX[i], testZ[i], notAirPredicate, &sg);
    }
    auto cpuEnd = std::chrono::high_resolution_clock::now();
    double cpuMs = std::chrono::duration<double, std::milli>(cpuEnd - cpuStart).count();
    printf("CPU: %d queries in %.1f ms (%.1f us/query)\n",
           numTests, cpuMs, cpuMs * 1000.0 / numTests);

    // ---- Prepare CUDA batch ----
    // Deduplicate columns
    std::unordered_map<uint64_t, int> columnMap;
    std::vector<ColumnParams> columns;
    std::vector<HeightQuery> queries(numTests);
    std::vector<int> cornerIndices;

    for (int i = 0; i < numTests; i++) {
        queries[i] = {testX[i], testZ[i]};

        int cellX = (int)floor((double)testX[i] / (double)gpuCfg.chunkWidth);
        int cellZ = (int)floor((double)testZ[i] / (double)gpuCfg.chunkWidth);

        int corners[4][2] = {
            {cellX, cellZ}, {cellX, cellZ+1},
            {cellX+1, cellZ}, {cellX+1, cellZ+1}
        };

        for (int c = 0; c < 4; c++) {
            uint64_t key = ((uint64_t)(uint32_t)corners[c][0] << 32) |
                           (uint64_t)(uint32_t)corners[c][1];
            auto it = columnMap.find(key);
            int colIdx;
            if (it != columnMap.end()) {
                colIdx = it->second;
            } else {
                colIdx = (int)columns.size();
                columnMap[key] = colIdx;

                ColumnParams cp;
                cp.cellX = corners[c][0];
                cp.cellZ = corners[c][1];
                double ds[2] = {0, 0};
                cubiomes_get_depth_and_scale(corners[c][0], corners[c][1], ds, &ctx);
                cp.depth = ds[0];
                cp.scale = ds[1];
                cp.randomOffset = cubiomes_noise_2d(corners[c][0], corners[c][1], &ctx);
                columns.push_back(cp);
            }
            cornerIndices.push_back(colIdx);
        }
    }

    printf("Unique columns: %d (from %d queries)\n", (int)columns.size(), numTests);

    // ---- CUDA execution ----
    int maxCols = (int)columns.size() + 128;
    int maxQs = numTests + 128;
    CudaNoiseContext* cudaCtx = cuda_noise_init(&gpuSN, &gpuCfg, maxCols, maxQs);
    if (!cudaCtx) {
        fprintf(stderr, "Failed to init CUDA context\n");
        free_cubiomes_context_cache(&ctx);
        return 1;
    }

    printf("Computing CUDA heights...\n");
    auto gpuStart = std::chrono::high_resolution_clock::now();

    std::vector<HeightResult> gpuResults(numTests);
    int rc = cuda_noise_batch_heights(
        cudaCtx,
        columns.data(), (int)columns.size(),
        queries.data(), numTests,
        cornerIndices.data(),
        gpuResults.data()
    );

    auto gpuEnd = std::chrono::high_resolution_clock::now();
    double gpuMs = std::chrono::duration<double, std::milli>(gpuEnd - gpuStart).count();
    printf("CUDA: %d queries in %.1f ms (%.1f us/query)\n",
           numTests, gpuMs, gpuMs * 1000.0 / numTests);

    if (rc != 0) {
        fprintf(stderr, "CUDA batch execution failed\n");
        cuda_noise_destroy(cudaCtx);
        free_cubiomes_context_cache(&ctx);
        return 1;
    }

    // ---- Compare ----
    int mismatches = 0;
    for (int i = 0; i < numTests; i++) {
        if (cpuHeights[i] != gpuResults[i].height) {
            if (mismatches < 20) {
                printf("MISMATCH at (%d, %d): CPU=%d, GPU=%d\n",
                       testX[i], testZ[i], cpuHeights[i], gpuResults[i].height);
            }
            mismatches++;
        }
    }

    printf("\n=== Results ===\n");
    printf("Total queries: %d\n", numTests);
    printf("Mismatches:    %d\n", mismatches);
    printf("Speedup:       %.1fx\n", cpuMs / gpuMs);

    if (mismatches == 0) {
        printf("SUCCESS: All heights match!\n");
    } else {
        printf("FAILURE: %d mismatches (%.1f%%)\n", mismatches, 100.0 * mismatches / numTests);
    }

    cuda_noise_destroy(cudaCtx);
    free_surface_cache(&sg);
    free_cubiomes_context_cache(&ctx);
    return mismatches > 0 ? 1 : 0;
}
