#include "cubiomes_integration.h"
#include "biomes.h"  // Pour DIM_OVERWORLD, DIM_NETHER, DIM_END
#include "noise.h"   // Pour samplePerlin
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Table de poids pour la moyenne pondérée des biomes (Minecraft 1.16)
// Calculée avec: 10.0 / sqrt(rx*rx + rz*rz + 0.2) pour rx,rz dans [-2,2]
// Grille 5x5 centrée sur le biome principal
static const float BIOME_WEIGHT_TABLE[25] = {
    // rz=-2: (rx=-2,-1,0,1,2)
    3.4924283f,  4.3852901f,  4.8794785f,  4.3852901f,  3.4924283f,
    // rz=-1: (rx=-2,-1,0,1,2)
    4.3852901f,  6.7419987f,  9.1287088f,  6.7419987f,  4.3852901f,
    // rz=0: (rx=-2,-1,0,1,2)
    4.8794785f,  9.1287088f, 22.3606796f,  9.1287088f,  4.8794785f,
    // rz=1: (rx=-2,-1,0,1,2)
    4.3852901f,  6.7419987f,  9.1287088f,  6.7419987f,  4.3852901f,
    // rz=2: (rx=-2,-1,0,1,2)
    3.4924283f,  4.3852901f,  4.8794785f,  4.3852901f,  3.4924283f
};

static inline uint64_t unique_hash_xyz(int x, int y, int z) {
    uint64_t hash = (uint64_t)x & ((1ULL << 26) - 1);
    hash |= ((uint64_t)z & ((1ULL << 26) - 1)) << 26;
    hash |= ((uint64_t)y & ((1ULL << 8) - 1)) << 52;
    return hash;
}

static inline uint64_t murmur64(uint64_t value) {
    value ^= value >> 33;
    value *= 0xFF51AFD7ED558CCDLL;
    value ^= value >> 33;
    value *= 0xC4CEB9FE1A85EC53LL;
    value ^= value >> 33;
    return value;
}

static void init_biome_cache(CubiomesContext *ctx, size_t capacity) {
    if (!ctx) return;
    if (capacity < 1) capacity = 1024;
    size_t p = 1;
    while (p < capacity) p <<= 1;
    capacity = p;
    ctx->biome_cache_keys = (uint64_t*)malloc(sizeof(uint64_t) * capacity);
    ctx->biome_cache_values = (int*)malloc(sizeof(int) * capacity);
    if (!ctx->biome_cache_keys || !ctx->biome_cache_values) {
        free(ctx->biome_cache_keys);
        free(ctx->biome_cache_values);
        ctx->biome_cache_keys = NULL;
        ctx->biome_cache_values = NULL;
        ctx->biome_cache_mask = 0;
        return;
    }
    for (size_t i = 0; i < capacity; i++) {
        ctx->biome_cache_keys[i] = UINT64_MAX;
        ctx->biome_cache_values[i] = 0;
    }
    ctx->biome_cache_mask = capacity - 1;
}

static void free_biome_cache(CubiomesContext *ctx) {
    if (!ctx) return;
    free(ctx->biome_cache_keys);
    free(ctx->biome_cache_values);
    ctx->biome_cache_keys = NULL;
    ctx->biome_cache_values = NULL;
    ctx->biome_cache_mask = 0;
}


static inline int getBiomeAtFast(CubiomesContext *ctx, int scale, int x, int y, int z) {
    if (!ctx) {
        return none;
    }
    size_t len = getMinCacheSize(&ctx->gen, scale, 1, 1, 1);
    if (len == 0) {
        return getBiomeAt(&ctx->gen, scale, x, y, z);
    }
    if (ctx->biome_tmp_cache_len < len) {
        int *newbuf = (int*)realloc(ctx->biome_tmp_cache, sizeof(int) * len);
        if (!newbuf) {
            return getBiomeAt(&ctx->gen, scale, x, y, z);
        }
        ctx->biome_tmp_cache = newbuf;
        ctx->biome_tmp_cache_len = len;
    }
    Range r = {scale, x, z, 1, 1, y, 1};
    int id = genBiomes(&ctx->gen, ctx->biome_tmp_cache, r);
    if (id == 0) return ctx->biome_tmp_cache[0];
    return none;
}

static inline int getBiomeAtCached(CubiomesContext *ctx, int x, int y, int z) {
    if (!ctx || !ctx->biome_cache_keys || ctx->biome_cache_mask == 0) {
        return getBiomeAtFast(ctx, 4, x, y, z);
    }
    uint64_t key = unique_hash_xyz(x, y, z);
    size_t idx = (size_t)(murmur64(key) & ctx->biome_cache_mask);
    if (ctx->biome_cache_keys[idx] == key) {
        return ctx->biome_cache_values[idx];
    }
    int value = getBiomeAtFast(ctx, 4, x, y, z);
    ctx->biome_cache_keys[idx] = key;
    ctx->biome_cache_values[idx] = value;
    return value;
}

static inline void cache_biome_put(CubiomesContext *ctx, int x, int y, int z, int biomeId);

static inline int prefill_biome_5x5(CubiomesContext *ctx, int x, int z, int seaLevel, int *biomeGrid, unsigned char *filled) {
    if (!ctx) return -1;
    Range r = {4, x - 2, z - 2, 5, 5, seaLevel, 1};
    size_t need = getMinCacheSize(&ctx->gen, r.scale, r.sx, r.sy, r.sz);
    if (need == 0) return -1;
    if (ctx->biome_tmp_cache_len < need) {
        int *newbuf = (int*)realloc(ctx->biome_tmp_cache, sizeof(int) * need);
        if (!newbuf) return -1;
        ctx->biome_tmp_cache = newbuf;
        ctx->biome_tmp_cache_len = need;
    }
    int err = genBiomes(&ctx->gen, ctx->biome_tmp_cache, r);
    if (err != 0) return err;

    for (int rz = -2; rz <= 2; rz++) {
        for (int rx = -2; rx <= 2; rx++) {
            int idx = (rx + 2) + (rz + 2) * 5;
            int val = ctx->biome_tmp_cache[(rz + 2) * 5 + (rx + 2)];
            biomeGrid[idx] = val;
            filled[idx] = 1;
            cache_biome_put(ctx, x + rx, seaLevel, z + rz, val);
        }
    }
    return 0;
}

static inline void cache_biome_put(CubiomesContext *ctx, int x, int y, int z, int biomeId) {
    if (!ctx || !ctx->biome_cache_keys || ctx->biome_cache_mask == 0) {
        return;
    }
    uint64_t key = unique_hash_xyz(x, y, z);
    size_t idx = (size_t)(murmur64(key) & ctx->biome_cache_mask);
    ctx->biome_cache_keys[idx] = key;
    ctx->biome_cache_values[idx] = biomeId;
}

static inline void fill_biome_cell(CubiomesContext *ctx, int x, int z, int seaLevel,
                                   int rx, int rz,
                                   int *biomeGrid, unsigned char *filled) {
    int idx = (rx + 2) + (rz + 2) * 5;
    if (filled[idx]) return;
    int biomeId = getBiomeAtCached(ctx, x + rx, seaLevel, z + rz);
    biomeGrid[idx] = biomeId;
    filled[idx] = 1;
}

// Initialise un contexte cubiomes
void init_cubiomes_context(CubiomesContext *ctx, int mc_version, uint64_t seed) {
    ctx->mc_version = mc_version;
    ctx->seed = seed;
    ctx->biome_cache_keys = NULL;
    ctx->biome_cache_values = NULL;
    ctx->biome_cache_mask = 0;
    ctx->biome_tmp_cache = NULL;
    ctx->biome_tmp_cache_len = 0;

    // Initialiser le générateur de biomes
    setupGenerator(&ctx->gen, mc_version, 0);
    applySeed(&ctx->gen, DIM_OVERWORLD, seed);

    // Initialiser le bruit de surface
    initSurfaceNoise(&ctx->sn, DIM_OVERWORLD, seed);

    // Direct-mapped cache (like Java IntLayerCache)
    init_biome_cache(ctx, 8192);
}

void free_cubiomes_context_cache(CubiomesContext *ctx) {
    free_biome_cache(ctx);
    freeLayerCaches(&ctx->gen);
    if (ctx && ctx->biome_tmp_cache) {
        free(ctx->biome_tmp_cache);
        ctx->biome_tmp_cache = NULL;
        ctx->biome_tmp_cache_len = 0;
    }
}

// Configuration complète de SurfaceGen avec cubiomes
void setup_surface_gen_with_cubiomes(SurfaceGen *sg, CubiomesContext *ctx) {
    // Configuration identique au test Java (testVillageGen.java)
    // horizontalNoiseResolution = 1, verticalNoiseResolution = 2, worldHeight = 256, startSizeY = 105
    sg->chunkWidth   = 4;   // horizontalNoiseResolution * 4 = 1 * 4
    sg->chunkHeight  = 8;   // verticalNoiseResolution * 4 = 2 * 4
    sg->startSizeY   = 12;  // Math.round(100 / 8) = 12 (division entière en Java)
    sg->noiseSizeY   = 32;  // worldHeight / chunkHeight = 256 / 8
    sg->seaLevel     = 63;
    sg->densityFactor= 1.0;
    sg->densityOffset= -0.46875;
    sg->dim          = DIM_OVERWORLD;
    sg->cache_capacity = 16384;

    // Slides identiques au Java : topSlide(-10, 3, 0), bottomSlide(-30, 0, 0)
    sg->noiseSettings.topSlideSettings.target  = -10.0;
    sg->noiseSettings.topSlideSettings.size    = 3.0;
    sg->noiseSettings.topSlideSettings.offset  = 0.0;

    sg->noiseSettings.bottomSlideSettings.target = -30.0;
    sg->noiseSettings.bottomSlideSettings.size   = 0.0;
    sg->noiseSettings.bottomSlideSettings.offset = 0.0;

    // Connecter les hooks cubiomes
    sg->get_depth_and_scale = cubiomes_get_depth_and_scale;
    sg->sample_noise_3d     = cubiomes_noise_3d;
    sg->sample_noise_2d     = cubiomes_noise_2d;
    sg->user                = ctx;
}

// Moyenne pondérée depth/scale sur un voisinage 5x5 de biomes.
// getNeighbour(rx, rz, ctxData) renvoie l'id du biome au décalage (rx, rz).
// Le sens d'itération (rx externe, rz interne) et le type float des poids sont
// significatifs : ils fixent l'ordre des sommations flottantes, donc le résultat
// au bit près. Ne pas réorganiser.
static inline void weighted_depth_scale(const int *biome5x5, int centerBiomeId,
                                        double out2[2]) {
    double weightedScale = 0.0;
    double weightedDepth = 0.0;
    double totalWeight = 0.0;
    int grass;

    double centerDepth, centerScale;
    getBiomeDepthAndScale(centerBiomeId, &centerDepth, &centerScale, &grass);

    for (int rx = -2; rx <= 2; ++rx) {
        for (int rz = -2; rz <= 2; ++rz) {
            int biomeId = biome5x5[(rx + 2) + (rz + 2) * 5];
            double depth, scale;
            getBiomeDepthAndScale(biomeId, &depth, &scale, &grass);

            float weight = BIOME_WEIGHT_TABLE[(rx + 2) + (rz + 2) * 5] / (depth + 2.0);
            if (depth > centerDepth) {
                weight /= 2.0;
            }

            weightedScale += scale * weight;
            weightedDepth += depth * weight;
            totalWeight += weight;
        }
    }

    weightedDepth /= totalWeight;
    weightedScale /= totalWeight;

    // Transformations finales (comme dans Minecraft 1.16+)
    weightedScale = weightedScale * 0.9 + 0.1;
    weightedDepth = (weightedDepth * 4.0 - 1.0) / 8.0;

    out2[0] = weightedDepth * 17.0 / 64.0;  // depth
    out2[1] = 96.0 / weightedScale;         // scale
}

// Hook : récupère depth et scale depuis un biome cubiomes
// Implémente la moyenne pondérée des biomes environnants comme Minecraft 1.16+
// IMPORTANT: x et z sont des coordonnées noise cell (block / 4)
// Java: getBiomeForNoiseGen(x, seaLevel, z) où x,z sont noise cell coords et seaLevel=63
void cubiomes_get_depth_and_scale(int x, int z, double out2[2], void *user) {
    CubiomesContext *ctx = (CubiomesContext*)user;

    // x, z sont en noise cell coords (block / 4)
    // seaLevel = 63 en block coords (comme Java)
    // Testé: scale=4 avec coords=(cellX, seaLevel, cellZ) donne le bon biome
    const int seaLevel = 63;

    // Obtenir le biome central
    int centerBiomeId = getBiomeAtCached(ctx, x, seaLevel, z);

    int biomeGrid[25];
    unsigned char filled[25] = {0};
    biomeGrid[12] = centerBiomeId;
    filled[12] = 1;

    // Fixed behavior: prefill the 5x5 grid to match Java's sampling pattern.
    if (prefill_biome_5x5(ctx, x, z, seaLevel, biomeGrid, filled) != 0) {
        // If prefill fails, fall back to on-demand filling.
        filled[12] = 1;
        biomeGrid[12] = centerBiomeId;
    }
    for (int rx = -2; rx <= 2; ++rx) {
        for (int rz = -2; rz <= 2; ++rz) {
            fill_biome_cell(ctx, x, z, seaLevel, rx, rz, biomeGrid, filled);
        }
    }

    weighted_depth_scale(biomeGrid, centerBiomeId, out2);
}

int cubiomes_get_depth_and_scale_grid(CubiomesContext *ctx,
                                      int cellX0, int cellZ0,
                                      int gridW, int gridH,
                                      double *depthOut, double *scaleOut) {
    if (!ctx || gridW <= 0 || gridH <= 0 || !depthOut || !scaleOut) return -1;

    const int seaLevel = 63;
    // Marge de 2 cellules de chaque côté pour les voisinages 5x5 des bords.
    const int bw = gridW + 4;
    const int bh = gridH + 4;

    Range r = {4, cellX0 - 2, cellZ0 - 2, bw, bh, seaLevel, 1};
    size_t need = getMinCacheSize(&ctx->gen, r.scale, r.sx, r.sy, r.sz);
    if (need == 0) return -1;

    int *biomes = (int*)malloc(sizeof(int) * need);
    if (!biomes) return -1;

    if (genBiomes(&ctx->gen, biomes, r) != 0) {
        free(biomes);
        return -1;
    }

    for (int cz = 0; cz < gridH; ++cz) {
        for (int cx = 0; cx < gridW; ++cx) {
            int biome5x5[25];
            for (int rz = -2; rz <= 2; ++rz) {
                for (int rx = -2; rx <= 2; ++rx) {
                    biome5x5[(rx + 2) + (rz + 2) * 5] =
                        biomes[(size_t)(cz + 2 + rz) * bw + (cx + 2 + rx)];
                }
            }
            double out2[2];
            weighted_depth_scale(biome5x5, biome5x5[12], out2);
            depthOut[(size_t)cz * gridW + cx] = out2[0];
            scaleOut[(size_t)cz * gridW + cx] = out2[1];
        }
    }

    free(biomes);
    return 0;
}

// Hook : échantillonne le bruit 3D de cubiomes
double cubiomes_noise_3d(int x, int y, int z, void *user) {
    CubiomesContext *ctx = (CubiomesContext*)user;

    // Échantillonner le bruit de surface de cubiomes
    return sampleSurfaceNoise(&ctx->sn, x, y, z);
}

// Hook : échantillonne le bruit 2D pour randomOffset (Overworld)
// Implémente le calcul du depthNoise comme Minecraft 1.16+
double cubiomes_noise_2d(int x, int z, void *user) {
    CubiomesContext *ctx = (CubiomesContext*)user;

    // Le Java fait: depthNoise.sample(x * 200, 10.0, z * 200, 1.0, 0.0, true)
    // En cubiomes, on utilise sampleOctaveAmp sur octdepth
    double noise = sampleOctaveAmp(&ctx->sn.octdepth,
                                   (double)(x * 200),
                                   10.0,
                                   (double)(z * 200),
                                   1.0,  // yamp
                                   0.0,  // ymin
                                   1);   // ydefault (true)

    // Ajustement du signe (ligne 253 du Java)
    noise = noise < 0.0 ? -noise * 0.3 : noise;

    // Traitement pour 1.16+ (ligne 255 du Java)
    noise = noise * 3.0 * 65535.0 / 8000.0 - 2.0;

    if (noise < 0.0) {
        return 17.0 * noise / 28.0 / 64.0;
    }

    return fmin(noise, 1.0) * 17.0 / 40.0 / 64.0;
}
