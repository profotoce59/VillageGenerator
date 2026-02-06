#include "cubiomes_integration.h"
#include "biomes.h"  // Pour DIM_OVERWORLD, DIM_NETHER, DIM_END
#include "noise.h"   // Pour samplePerlin
#include <math.h>
#include <stdio.h>   // Pour printf (debug)
#include <stdint.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

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

static inline int getBiomeAtCached(CubiomesContext *ctx, int x, int y, int z) {
    if (!ctx || !ctx->biome_cache_keys || ctx->biome_cache_mask == 0) {
        return getBiomeAt(&ctx->gen, 4, x, y, z);
    }
    uint64_t key = unique_hash_xyz(x, y, z);
    size_t idx = (size_t)(murmur64(key) & ctx->biome_cache_mask);
    if (ctx->biome_cache_keys[idx] == key) {
        return ctx->biome_cache_values[idx];
    }
    int value = getBiomeAt(&ctx->gen, 4, x, y, z);
    ctx->biome_cache_keys[idx] = key;
    ctx->biome_cache_values[idx] = value;
    return value;
}

static uint64_t g_ns_get_biome_at = 0;
static uint64_t g_ns_get_depth_and_scale = 0;

static inline uint64_t now_ns(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (uint64_t)ts.tv_sec * 1000000000ULL + (uint64_t)ts.tv_nsec;
}

void reset_cubiomes_profile_stats(void) {
    g_ns_get_biome_at = 0;
    g_ns_get_depth_and_scale = 0;
}

void get_cubiomes_profile_stats(uint64_t *ns_get_biome_at,
                                uint64_t *ns_get_depth_and_scale) {
    if (ns_get_biome_at) *ns_get_biome_at = g_ns_get_biome_at;
    if (ns_get_depth_and_scale) *ns_get_depth_and_scale = g_ns_get_depth_and_scale;
}

// Initialise un contexte cubiomes
void init_cubiomes_context(CubiomesContext *ctx, int mc_version, uint64_t seed) {
    ctx->mc_version = mc_version;
    ctx->seed = seed;
    ctx->biome_cache_keys = NULL;
    ctx->biome_cache_values = NULL;
    ctx->biome_cache_mask = 0;

    // Initialiser le générateur de biomes
    setupGenerator(&ctx->gen, mc_version, 0);
    applySeed(&ctx->gen, DIM_OVERWORLD, seed);

    // Initialiser le bruit de surface
    initSurfaceNoise(&ctx->sn, DIM_OVERWORLD, seed);

    // Direct-mapped cache (like Java IntLayerCache)
    init_biome_cache(ctx, 4096);
}

void free_cubiomes_context_cache(CubiomesContext *ctx) {
    free_biome_cache(ctx);
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
    sg->cache_capacity = 8192;

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

// Hook : récupère depth et scale depuis un biome cubiomes
// Implémente la moyenne pondérée des biomes environnants comme Minecraft 1.16+
// IMPORTANT: x et z sont des coordonnées noise cell (block / 4)
// Java: getBiomeForNoiseGen(x, seaLevel, z) où x,z sont noise cell coords et seaLevel=63
void cubiomes_get_depth_and_scale(int x, int z, double out2[2], void *user) {
    CubiomesContext *ctx = (CubiomesContext*)user;

    // Debug désactivé pour les tests de pièces
    int enableLogs = 0;  // Mettre à 1 pour débugger la hauteur

    const int sampleRange = 2;
    double weightedScale = 0.0;
    double weightedDepth = 0.0;
    double totalWeight = 0.0;

    // x, z sont en noise cell coords (block / 4)
    // seaLevel = 63 en block coords (comme Java)
    // Testé: scale=4 avec coords=(cellX, seaLevel, cellZ) donne le bon biome
    const int seaLevel = 63;

    // Obtenir le biome central
    uint64_t t0 = now_ns();
    int centerBiomeId = getBiomeAtCached(ctx, x, seaLevel, z);
    uint64_t t1 = now_ns();
    g_ns_get_biome_at += (t1 - t0);
    double centerDepth, centerScale;
    int grass;
    uint64_t t2 = now_ns();
    getBiomeDepthAndScale(centerBiomeId, &centerDepth, &centerScale, &grass);
    uint64_t t3 = now_ns();
    g_ns_get_depth_and_scale += (t3 - t2);

    if (enableLogs) {
        printf("\n=== C getDepthAndScale ===\n");
        printf("Position: x=%d, z=%d\n", x, z);
        printf("centerBiomeId: %d, centerDepth: %.6f, centerScale: %.6f\n",
               centerBiomeId, centerDepth, centerScale);
    }

    // Parcourir les biomes environnants dans un rayon de 2 (en noise cell coords)
    for (int rx = -sampleRange; rx <= sampleRange; ++rx) {
        for (int rz = -sampleRange; rz <= sampleRange; ++rz) {
            // Utiliser scale=4 avec coords=(cellX, seaLevel, cellZ)
            uint64_t tb0 = now_ns();
            int biomeId = getBiomeAtCached(ctx, x + rx, seaLevel, z + rz);
            uint64_t tb1 = now_ns();
            g_ns_get_biome_at += (tb1 - tb0);
            double depth, scale;
            uint64_t td0 = now_ns();
            getBiomeDepthAndScale(biomeId, &depth, &scale, &grass);
            uint64_t td1 = now_ns();
            g_ns_get_depth_and_scale += (td1 - td0);

            // Calculer le poids depuis la table
            float weight = BIOME_WEIGHT_TABLE[(rx + 2) + (rz + 2) * 5] / (depth + 2.0);

            // Réduire le poids si le biome est plus élevé que le centre
            if (depth > centerDepth) {
                weight /= 2.0;
            }

            if (enableLogs) {
                printf("  rx=%d, rz=%d: biomeId=%d, depth=%.4f, scale=%.4f, tableWeight=%.4f, weight=%.6f\n",
                       rx, rz, biomeId, depth, scale, BIOME_WEIGHT_TABLE[(rx + 2) + (rz + 2) * 5], weight);
            }

            weightedScale += scale * weight;
            weightedDepth += depth * weight;
            totalWeight += weight;
        }
    }

    if (enableLogs) {
        printf("Before normalization: weightedDepth=%.6f, weightedScale=%.6f, totalWeight=%.6f\n",
               weightedDepth, weightedScale, totalWeight);
    }

    // Calculer les moyennes
    weightedDepth /= totalWeight;
    weightedScale /= totalWeight;

    if (enableLogs) {
        printf("After normalization: weightedDepth=%.6f, weightedScale=%.6f\n",
               weightedDepth, weightedScale);
    }

    // Transformations finales (comme dans Minecraft 1.16+)
    weightedScale = weightedScale * 0.9 + 0.1;
    weightedDepth = (weightedDepth * 4.0 - 1.0) / 8.0;

    if (enableLogs) {
        printf("After final transforms: weightedDepth=%.6f, weightedScale=%.6f\n",
               weightedDepth, weightedScale);
    }

    // Pour MC 1.16+ : appliquer les transformations spécifiques
    out2[0] = weightedDepth * 17.0 / 64.0;  // depth
    out2[1] = 96.0 / weightedScale;          // scale

    if (enableLogs) {
        printf("Final output: depth=%.10f, scale=%.10f\n", out2[0], out2[1]);
    }
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

    // DEBUG: afficher le bruit brut
    if (x == 0 && z == 0) {
        printf("DEBUG cubiomes_noise_2d(0,0): noise_brut=%.16f\n", noise);
    }

    // Ajustement du signe (ligne 253 du Java)
    noise = noise < 0.0 ? -noise * 0.3 : noise;

    // DEBUG: afficher après ajustement signe
    if (x == 0 && z == 0) {
        printf("DEBUG après ajustement signe=%.16f\n", noise);
    }

    // Traitement pour 1.16+ (ligne 255 du Java)
    noise = noise * 3.0 * 65535.0 / 8000.0 - 2.0;

    // DEBUG: afficher après transformation
    if (x == 0 && z == 0) {
        printf("DEBUG cubiomes_noise_2d(0,0): après transfo=%.16f\n", noise);
    }

    if (noise < 0.0) {
        return 17.0 * noise / 28.0 / 64.0;
    }

    return fmin(noise, 1.0) * 17.0 / 40.0 / 64.0;
}
