#include "cubiomes_integration.h"
#include "biomes.h"  // Pour DIM_OVERWORLD, DIM_NETHER, DIM_END
#include "noise.h"   // Pour samplePerlin
#include <math.h>
#include <stdio.h>   // Pour printf (debug)

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

// Initialise un contexte cubiomes
void init_cubiomes_context(CubiomesContext *ctx, int mc_version, uint64_t seed) {
    ctx->mc_version = mc_version;
    ctx->seed = seed;

    // Initialiser le générateur de biomes
    setupGenerator(&ctx->gen, mc_version, 0);
    applySeed(&ctx->gen, DIM_OVERWORLD, seed);

    // Initialiser le bruit de surface
    initSurfaceNoise(&ctx->sn, DIM_OVERWORLD, seed);
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

    // Debug pour position test
    int enableLogs = (x == 20121 && z == 20185);

    const int sampleRange = 2;
    double weightedScale = 0.0;
    double weightedDepth = 0.0;
    double totalWeight = 0.0;

    // x, z sont en noise cell coords (block / 4)
    // seaLevel = 63 en block coords (comme Java)
    // Testé: scale=4 avec coords=(cellX, seaLevel, cellZ) donne le bon biome
    const int seaLevel = 63;

    // Obtenir le biome central
    int centerBiomeId = getBiomeAt(&ctx->gen, 4, x, seaLevel, z);
    double centerDepth, centerScale;
    int grass;
    getBiomeDepthAndScale(centerBiomeId, &centerDepth, &centerScale, &grass);

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
            int biomeId = getBiomeAt(&ctx->gen, 4, x + rx, seaLevel, z + rz);
            double depth, scale;
            getBiomeDepthAndScale(biomeId, &depth, &scale, &grass);

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
