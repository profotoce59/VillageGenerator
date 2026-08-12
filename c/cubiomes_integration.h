#ifndef CUBIOMES_INTEGRATION_H
#define CUBIOMES_INTEGRATION_H

#include "surface_gen.h"
#include "generator.h"
#include "biomenoise.h"

#ifdef __cplusplus
extern "C" {
#endif

// Structure pour encapsuler le générateur cubiomes avec SurfaceGen
typedef struct {
    Generator gen;
    SurfaceNoise sn;
    uint64_t seed;
    int mc_version;
    uint64_t *biome_cache_keys;
    int *biome_cache_values;
    size_t biome_cache_mask;
    int *biome_tmp_cache;
    size_t biome_tmp_cache_len;
} CubiomesContext;

// Initialise un contexte cubiomes pour l'utiliser avec SurfaceGen
void init_cubiomes_context(CubiomesContext *ctx, int mc_version, uint64_t seed);
void free_cubiomes_context_cache(CubiomesContext *ctx);

// Configure un SurfaceGen pour utiliser cubiomes
void setup_surface_gen_with_cubiomes(SurfaceGen *sg, CubiomesContext *ctx);

// Fonctions hooks pour SurfaceGen (utilisent cubiomes en interne)
void cubiomes_get_depth_and_scale(int x, int z, double out2[2], void *user);

// Version groupée de cubiomes_get_depth_and_scale pour une grille rectangulaire
// de cellules de bruit. Les voisinages 5x5 des cellules voisines se recouvrent
// presque entièrement : un seul appel genBiomes() couvre toute la zone au lieu
// d'un appel par colonne.
// depthOut/scaleOut doivent contenir gridW*gridH doubles, rangés en z-major
// (index = cz * gridW + cx). Renvoie 0 si OK, non-nul en cas d'échec — dans ce
// cas l'appelant doit retomber sur cubiomes_get_depth_and_scale.
int cubiomes_get_depth_and_scale_grid(CubiomesContext *ctx,
                                      int cellX0, int cellZ0,
                                      int gridW, int gridH,
                                      double *depthOut, double *scaleOut);

double cubiomes_noise_3d(int x, int y, int z, void *user);
double cubiomes_noise_2d(int x, int z, void *user);

#ifdef __cplusplus
}
#endif

#endif // CUBIOMES_INTEGRATION_H
