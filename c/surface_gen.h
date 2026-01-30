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

#ifdef __cplusplus
}
#endif
#endif