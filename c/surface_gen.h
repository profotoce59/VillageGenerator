#ifndef SURFACE_GEN_H
#define SURFACE_GEN_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

// Forward declaration
struct SurfaceGen_s;
typedef struct SurfaceGen_s SurfaceGen;

// Type pour les blocs (à adapter selon vos besoins)
typedef enum {
    BLOCK_AIR,
    BLOCK_STONE,
    BLOCK_WATER,
    // ... autres types de blocs
} Block;

// Prédicat de bloc : renvoie 1 si le test passe, 0 sinon
typedef int (*BlockPredicate)(Block block, void *user);

// Fonction pour obtenir un bloc depuis le bruit
// À implémenter selon votre logique de génération
Block get_block_from_noise(double noise, int y, void *user);

// Fonction principale : génère une colonne depuis Y
int generate_column_from_y(SurfaceGen *sg, int x, int z,
                           BlockPredicate predicate, void *user);

typedef struct {
    double target;
    double size;     // si == 0.0, slide inactif
    double offset;
} SlideSettings;

typedef struct {
    SlideSettings topSlideSettings;    // topSlide
    SlideSettings bottomSlideSettings; // bottomSlide
} NoiseSettings;

// Note: Dimension enum is defined in cubiomes/biomes.h
// Use: DIM_OVERWORLD (0), DIM_NETHER (-1), DIM_END (1)

struct SurfaceGen_s {
    // config "monde"
    int chunkWidth;     // largeur cellule X/Z (ex: 4, 8 ou 16 selon ton découpage)
    int chunkHeight;    // hauteur interne d'une cellule Y (ex: 8 ou 16)
    int startSizeY;     // nombre de cellules verticales (noise columns)
    int noiseSizeY;     // startSizeY*? selon ta config (dans ton Java, buffer a size noiseSizeY+1)
    int seaLevel;       // ex: 63

    // facteurs densité (1.16)
    double densityFactor;
    double densityOffset;

    // dimension (pour le randomOffset overworld)
    // Utilise les valeurs de cubiomes: DIM_OVERWORLD (0), DIM_NETHER (-1), DIM_END (1)
    int dim;

    // Reprise du scan quand le terrain dépasse la plage (comportement Java).
    // Si le sommet de [0, startSizeY) est encore solide, c'est que le terrain
    // monte plus haut : le Java élargit startSizeY de START_SIZE_STEP_CELLS et
    // recommence, jusqu'à START_SIZE_MAX_TRIES fois. Sans ça, generate_column_from_y
    // renvoie une hauteur plafonnée et les pièces se posent au mauvais endroit.
    //
    // ATTENTION : la reprise MUTE startSizeY de façon persistante et vide le
    // cache de colonnes, exactement comme le Java. Les requêtes suivantes voient
    // donc la nouvelle plage.
    //
    // Mettre à 0 pour obtenir la primitive sans reprise (utilisé par les tests
    // qui comparent le kernel CUDA, lequel travaille à startSizeY fixe).
    int enable_start_size_retry;

    // réglages slides
    NoiseSettings noiseSettings;

    // === HOOKS À FOURNIR ===
    // renvoie (depth, scale) selon biome autour de (x,z) (à l'échelle des "cellX/cellZ")
    void (*get_depth_and_scale)(int x, int z, double out2[2], void *user);
    // bruit 3D principal (x,y,z) à l’échelle "cellule" (comme ton this.sampleNoise(x,y,z))
    double (*sample_noise_3d)(int x, int y, int z, void *user);
    // bruit 2D pour randomOffset overworld (comme ton this.sampleNoise(x,z))
    double (*sample_noise_2d)(int x, int z, void *user);

    void *user; // pointeur libre pour passer un contexte à tes hooks

    // cache per-instance (initialisé à la demande)
    void *cache;
    size_t cache_capacity;
    size_t cache_hits;
    size_t cache_misses;
};

// utilitaires
double clamped_lerp(double a, double b, double t);
// Note: lerp3 is defined in cubiomes/rng.h as static inline
// We'll use their version to avoid conflicts

// remplit buffer[0..noiseSizeY] avec la colonne de bruit (1.16+ branch)
void sample_noise_column(SurfaceGen *sg, double *buffer, int x, int z);

// version avec cache simple (optionnelle)
// alloue et renvoie un pointeur sur un buffer interne (longueur = sg->noiseSizeY+1)
const double* sample_noise_column_cached(SurfaceGen *sg, int x, int z);

// libère le cache (si utilisé)
void free_surface_cache(SurfaceGen *sg);

// stats cache (globales au process)
void reset_surface_cache_stats(SurfaceGen *sg);
void get_surface_cache_stats(SurfaceGen *sg, size_t *hits, size_t *misses);

// Version early-exit de generate_column_from_y (pas de cache, stop dès match)
int generate_column_from_y_early_exit(SurfaceGen *sg, int x, int z,
                                       BlockPredicate predicate, void *user);

// profiling
void reset_surface_profile_stats(SurfaceGen *sg);
void get_surface_profile_stats(SurfaceGen *sg,
    uint64_t *ns_sample_noise_column,
    uint64_t *ns_sample_noise_3d,
    uint64_t *ns_sample_noise_2d,
    uint64_t *ns_get_depth_and_scale);

#ifdef __cplusplus
}
#endif
#endif
