#include "cubiomes_integration.h"
#include "biomes.h"  // Pour DIM_OVERWORLD, DIM_NETHER, DIM_END
#include <math.h>

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
    // Configuration typique pour Minecraft 1.16
    sg->chunkWidth   = 4;
    sg->chunkHeight  = 8;
    sg->startSizeY   = 33;
    sg->noiseSizeY   = 32;
    sg->seaLevel     = 63;
    sg->densityFactor= 1.0;
    sg->densityOffset= -0.46875;
    sg->dim          = DIM_OVERWORLD;

    // Slides (valeurs par défaut pour Overworld)
    sg->noiseSettings.topSlideSettings.target  = -3000.0;
    sg->noiseSettings.topSlideSettings.size    = 64.0;
    sg->noiseSettings.topSlideSettings.offset  = -46.0;

    sg->noiseSettings.bottomSlideSettings.target = -30.0;
    sg->noiseSettings.bottomSlideSettings.size   = 7.0;
    sg->noiseSettings.bottomSlideSettings.offset = 1.0;

    // Connecter les hooks cubiomes
    sg->get_depth_and_scale = cubiomes_get_depth_and_scale;
    sg->sample_noise_3d     = cubiomes_noise_3d;
    sg->sample_noise_2d     = cubiomes_noise_2d;
    sg->user                = ctx;
}

// Hook : récupère depth et scale depuis un biome cubiomes
void cubiomes_get_depth_and_scale(int x, int z, double out2[2], void *user) {
    CubiomesContext *ctx = (CubiomesContext*)user;

    // Obtenir le biome à cette position (échelle 1:4)
    int biomeId = getBiomeAt(&ctx->gen, 4, x, 0, z);

    // Obtenir depth et scale pour ce biome
    // Le dernier paramètre (grass) n'est pas utilisé ici
    int grass = 0;
    getBiomeDepthAndScale(biomeId, &out2[0], &out2[1], &grass);
}

// Hook : échantillonne le bruit 3D de cubiomes
double cubiomes_noise_3d(int x, int y, int z, void *user) {
    CubiomesContext *ctx = (CubiomesContext*)user;

    // Échantillonner le bruit de surface de cubiomes
    return sampleSurfaceNoise(&ctx->sn, x, y, z);
}

// Hook : échantillonne le bruit 2D pour randomOffset (Overworld)
double cubiomes_noise_2d(int x, int z, void *user) {
    CubiomesContext *ctx = (CubiomesContext*)user;

    // Pour le randomOffset, on utilise le bruit de surface à y=0
    // Échelle réduite pour avoir un effet plus subtil
    return sampleSurfaceNoise(&ctx->sn, x, 0, z) * 0.1;
}
