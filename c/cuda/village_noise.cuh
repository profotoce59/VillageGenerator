#pragma once

#include <stdint.h>
#include <stddef.h>

// ============================================================================
// GPU-side structures (flat, no pointers — copied to device memory)
//
// Layout note: the permutation tables of every octave are grouped in one
// contiguous array so a block can stage them in shared memory with a single
// coalesced copy.  samplePerlin does 8 random byte lookups per octave, so the
// tables are the only part of the noise state that really needs fast random
// access.
// ============================================================================

#define GPU_OCT_MIN    16
#define GPU_OCT_MAX    16
#define GPU_OCT_MAIN    8
#define GPU_OCT_DEPTH  16
#define GPU_OCT_SURF   (GPU_OCT_MIN + GPU_OCT_MAX + GPU_OCT_MAIN)   // 40
#define GPU_OCT_TOTAL  (GPU_OCT_SURF + GPU_OCT_DEPTH)               // 56

// Scalar part of a cubiomes PerlinNoise.
struct GpuPerlinParams {
    double a, b, c;
    double d2, t2;          // cached y=0 fast path
    double amplitude;       // octdepth only
    double lacunarity;      // octdepth only
    int    h2;              // cached y=0 fast path
    int    _pad;
};

struct GpuSurfaceNoise {
    double xzScale, yScale;
    double xzFactor, yFactor;
    // [0..15]=octmin, [16..31]=octmax, [32..39]=octmain, [40..55]=octdepth
    GpuPerlinParams oct[GPU_OCT_TOTAL];
    uint8_t         perm[GPU_OCT_TOTAL][257];
};

// Parameters for one noise column (pre-computed on CPU from biome data).
// randomOffset is NOT here: it is pure noise and is computed on the device.
struct ColumnParams {
    int    cellX, cellZ;    // cell coordinates in the noise grid
    double depth, scale;    // from cubiomes_get_depth_and_scale
};

// SurfaceGen config needed on GPU for the column -> height conversion
struct GpuSurfaceGenConfig {
    int chunkWidth;         // 4
    int chunkHeight;        // 8
    int startSizeY;         // number of vertical noise cells actually sampled
    int noiseSizeY;         // worldHeight / chunkHeight — only used by the falloff math
    int seaLevel;           // 63
    int dim;                // cubiomes Dimension: randomOffset applies to DIM_OVERWORLD only
    double densityFactor;
    double densityOffset;
    // slide settings
    double topSlideTarget, topSlideSize, topSlideOffset;
    double botSlideTarget, botSlideSize, botSlideOffset;
};

// Which block predicate the height scan stops on.
// Mirrors SurfaceGenWrapper: NOT_AIR == defaultNotAirPredicate,
// STONE == worldSurfaceWGPredicate (the one villages use).
enum HeightPredicate {
    HEIGHT_PRED_NOT_AIR = 0,
    HEIGHT_PRED_STONE   = 1
};

// ============================================================================
// Low-level device API (implemented in village_noise.cu)
// ============================================================================

#ifdef __cplusplus
extern "C" {
#endif

typedef struct CudaNoiseContext CudaNoiseContext;

// Uploads the surface-noise state to the GPU and allocates the batch buffers.
// Returns NULL on failure.
CudaNoiseContext* cuda_noise_init(
    const GpuSurfaceNoise*     hostSN,
    const GpuSurfaceGenConfig* hostCfg,
    int maxColumns,         // max number of unique noise columns per batch
    int maxQueries);        // max number of height queries per batch

void cuda_noise_destroy(CudaNoiseContext* ctx);

// Ré-upload l'état de bruit et la config sans toucher aux buffers de travail.
// Sert à passer d'une seed/config à une autre sans payer un cycle
// cudaFree/cudaMalloc complet (coûteux : ~5 ms).
// Renvoie -1 si la nouvelle config ne tient pas dans l'allocation existante ;
// l'appelant doit alors recréer le contexte.
int cuda_noise_update_state(CudaNoiseContext* ctx,
                            const GpuSurfaceNoise*     hostSN,
                            const GpuSurfaceGenConfig* hostCfg);

// Scattered queries: the caller deduplicates columns itself and supplies, for
// every query, the 4 corner column indices in the order
//   (cellX,cellZ), (cellX,cellZ+1), (cellX+1,cellZ), (cellX+1,cellZ+1).
// Returns 0 on success, -1 on error.
int cuda_noise_batch_heights(
    CudaNoiseContext* ctx,
    const ColumnParams* columns, int numColumns,
    const int* queryX, const int* queryZ, int numQueries,
    const int* queryCornerIndices,      // [numQueries * 4]
    int predicate,                      // HeightPredicate
    int* heightsOut);                   // [numQueries]

// Rectangular heightmap: columns[] must be the (gridW x gridH) grid of cells
// starting at (cellX0, cellZ0), stored row-major as columns[cz * gridW + cx].
// Corner indices are derived on the GPU, so nothing but the columns is uploaded.
// heightsOut is [w * h], row-major (z-major), i.e. heightsOut[iz * w + ix].
// Returns 0 on success, -1 on error.
int cuda_noise_heightmap(
    CudaNoiseContext* ctx,
    const ColumnParams* columns, int gridW, int gridH,
    int cellX0, int cellZ0,
    int x0, int z0, int w, int h,
    int predicate,                      // HeightPredicate
    int* heightsOut);

// Étend une heightmap rectangulaire déjà calculée à un startSizeY plus grand.
//
// Après une reprise de scan côté C, seules les cellules [oldStartSizeY,
// newStartSizeY) manquent : les valeurs déjà en mémoire restent valables, le
// bruit à un y donné ne dépendant pas de startSizeY. On ne recalcule donc que
// la tranche manquante, puis on refait le scan de hauteur.
//
// Suppose que la zone, la grille de colonnes et la seed sont inchangées depuis
// l'appel à cuda_noise_heightmap(). Renvoie 0 si OK.
int cuda_noise_heightmap_extend(
    CudaNoiseContext* ctx,
    int gridW, int gridH,
    int cellX0, int cellZ0,
    int x0, int z0, int w, int h,
    int predicate,
    int oldStartSizeY, int newStartSizeY,
    int* heightsOut);

// Wall-clock time of the last launch, in milliseconds, split by phase.
// Any pointer may be NULL.
void cuda_noise_last_timings(const CudaNoiseContext* ctx,
                             float* msUpload, float* msColumns,
                             float* msHeights, float* msDownload);

#ifdef __cplusplus
}
#endif

// ============================================================================
// High-level host API (implemented in village_noise_host.cpp)
//
// These take the plain cubiomes/SurfaceGen structures and handle the
// conversion, the CPU-side biome work and the batching.
// ============================================================================

#ifdef __cplusplus

struct SurfaceGen_s;
typedef struct SurfaceGen_s SurfaceGen;
typedef struct SurfaceNoise SurfaceNoise;

void convertSurfaceNoise(GpuSurfaceNoise* dst, const SurfaceNoise* src);
void convertSurfaceGenConfig(GpuSurfaceGenConfig* dst, const SurfaceGen* src);

// Opaque high-level handle. Owns a CudaNoiseContext plus the CPU-side scratch.
class CudaHeightBatcher;

#endif
