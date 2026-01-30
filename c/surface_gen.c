#include "surface_gen.h"
#include "biomes.h"  // Pour DIM_OVERWORLD, DIM_NETHER, DIM_END
#include <stdlib.h>
#include <string.h>
#include <math.h>

// ---------- utils ----------
double clamped_lerp(double a, double b, double t) {
    if (t < 0.0) t = 0.0;
    else if (t > 1.0) t = 1.0;
    return a + (b - a) * t;
}

// Note: lerp3 is now provided by cubiomes/rng.h
// We include the rng.h header to get the inline version
#include "rng.h"

// ---------- cache (optionnel, simple chaîné) ----------
typedef struct CacheNode {
    uint64_t key;
    double  *col; // length = noiseSizeY+1
    struct CacheNode *next;
} CacheNode;

static uint64_t pack_key(int x, int z) {
    return ( (uint64_t)( (uint32_t)x ) << 32 ) | (uint64_t)( (uint32_t)z );
}

typedef struct {
    CacheNode *head;
    size_t count;
    size_t limit; // nb max d'entrées, ex: 4096
} SurfaceCache;

static SurfaceCache* get_cache(SurfaceGen *sg) {
    // on range le cache dans sg->user si tu veux autre chose, adapte à ton infra
    // pour l’exemple on alloue un cache statique par process:
    static SurfaceCache *C = NULL;
    if (!C) {
        C = (SurfaceCache*)calloc(1, sizeof(SurfaceCache));
        C->limit = 4096;
    }
    (void)sg;
    return C;
}

static const double* cache_get(SurfaceGen *sg, uint64_t key) {
    SurfaceCache *C = get_cache(sg);
    for (CacheNode *n = C->head; n; n = n->next) {
        if (n->key == key) return n->col;
    }
    return NULL;
}

static void cache_put(SurfaceGen *sg, uint64_t key, const double *src, int len) {
    SurfaceCache *C = get_cache(sg);
    // limite grossière: si trop d'entrées, on drop la tête
    if (C->count >= C->limit && C->head) {
        CacheNode *drop = C->head;
        C->head = drop->next;
        free(drop->col);
        free(drop);
        C->count--;
    }
    CacheNode *n = (CacheNode*)malloc(sizeof(CacheNode));
    n->key = key;
    n->col = (double*)malloc(sizeof(double) * len);
    memcpy(n->col, src, sizeof(double) * len);
    n->next = C->head;
    C->head = n;
    C->count++;
}

void free_surface_cache(SurfaceGen *sg) {
    SurfaceCache *C = get_cache(sg);
    CacheNode *n = C->head;
    while (n) {
        CacheNode *nx = n->next;
        free(n->col);
        free(n);
        n = nx;
    }
    C->head = NULL;
    C->count = 0;
    (void)sg;
}

// ---------- cœur : sample_noise_column (branche 1.16+) ----------
void sample_noise_column(SurfaceGen *sg, double *buffer, int x, int z)
{
    // ds = { depth, scale }
    double ds[2] = {0.0, 0.0};
    sg->get_depth_and_scale(x, z, ds, sg->user);
    double depth = ds[0];
    double scale = ds[1];

    // randomOffset (only Overworld)
    double randomOffset = 0.0;
    if (sg->dim == DIM_OVERWORLD && sg->sample_noise_2d) {
        randomOffset = sg->sample_noise_2d(x, z, sg->user);
    }

    // IMPORTANT : dans ton Java, buffer a taille noiseSizeY+1
    // et on remplit à partir de y=6 jusqu’à startSizeY-1 inclus.
    // Laisse buffer[0..5] tranquilles si tu veux coller au jeu.
    for (int y = 6; y < sg->startSizeY; ++y) {

        // bruit principal 3D à (x,y,z) dans l’espace "cellule"
        double noise = sg->sample_noise_3d(x, y, z, sg->user);

        // ==== branche 1.16+ ====
        double fallOff = 1.0 - (double)y * 2.0 / (double)sg->noiseSizeY + randomOffset;
        fallOff = fallOff * sg->densityFactor + sg->densityOffset;
        fallOff = (fallOff + depth) * scale;

        if (fallOff > 0.0)
            noise = noise + fallOff * 4.0;
        else
            noise = noise + fallOff;

        // slides (top / bottom)
        if (sg->noiseSettings.topSlideSettings.size > 0.0) {
            double num = ((double)(sg->noiseSizeY - y) - sg->noiseSettings.topSlideSettings.offset)
                         / sg->noiseSettings.topSlideSettings.size;
            noise = clamped_lerp(sg->noiseSettings.topSlideSettings.target, noise, num);
        }
        if (sg->noiseSettings.bottomSlideSettings.size > 0.0) {
            double num = ((double)y - sg->noiseSettings.bottomSlideSettings.offset)
                         / sg->noiseSettings.bottomSlideSettings.size;
            noise = clamped_lerp(sg->noiseSettings.bottomSlideSettings.target, noise, num);
        }

        buffer[y] = noise;
    }

    // Optionnel: tu peux remplir buffer[0..5] si nécessaire pour tes usages.
}

// version avec cache (clé (x,z) → colonne)
const double* sample_noise_column_cached(SurfaceGen *sg, int x, int z)
{
    uint64_t key = pack_key(x, z);
    const double *hit = cache_get(sg, key);
    if (hit) return hit;

    int len = sg->noiseSizeY + 1;
    double *tmp = (double*)calloc((size_t)len, sizeof(double));
    sample_noise_column(sg, tmp, x, z);
    cache_put(sg, key, tmp, len);
    free(tmp);
    return cache_get(sg, key);
}

// Implémentation de generateColumnfromY
int generate_column_from_y(SurfaceGen *sg, int x, int z, 
                           BlockPredicate predicate, void *user)
{
    // Coordonnées de la cellule dans la grille
    int cellX = (int)floor((double)x / (double)sg->chunkWidth);
    int cellZ = (int)floor((double)z / (double)sg->chunkWidth);
    
    // Coordonnées locales dans la cellule
    int posX = ((x % sg->chunkWidth) + sg->chunkWidth) % sg->chunkWidth;
    int posZ = ((z % sg->chunkWidth) + sg->chunkWidth) % sg->chunkWidth;
    
    // Pourcentages de position
    double percentX = (double)posX / (double)sg->chunkWidth;
    double percentZ = (double)posZ / (double)sg->chunkWidth;
    
    // Échantillonner les 4 colonnes de bruit aux coins
    int len = sg->noiseSizeY + 1;
    double *ds[4];
    for (int i = 0; i < 4; i++) {
        ds[i] = (double*)calloc((size_t)len, sizeof(double));
    }
    
    sample_noise_column(sg, ds[0], cellX, cellZ);
    sample_noise_column(sg, ds[1], cellX, cellZ + 1);
    sample_noise_column(sg, ds[2], cellX + 1, cellZ);
    sample_noise_column(sg, ds[3], cellX + 1, cellZ + 1);
    
    // Parcourir de haut en bas
    for (int cellY = sg->startSizeY - 1; cellY >= 0; --cellY) {
        double xyz = ds[0][cellY];
        double xyz1 = ds[1][cellY];
        double x1yz = ds[2][cellY];
        double x1yz1 = ds[3][cellY];
        double xy1z = ds[0][cellY + 1];
        double xy1z1 = ds[1][cellY + 1];
        double x1y1z = ds[2][cellY + 1];
        double x1y1z1 = ds[3][cellY + 1];
        
        for (int posY = sg->chunkHeight - 1; posY >= 0; --posY) {
            double percentY = (double)posY / (double)sg->chunkHeight;
            
            // Interpolation trilinéaire (ordre Mojang)
            double noise = lerp3(percentY, percentX, percentZ,
                               xyz, xy1z, x1yz, x1y1z,
                               xyz1, xy1z1, x1yz1, x1y1z1);
            
            int y = cellY * sg->chunkHeight + posY;
            Block block = get_block_from_noise(noise, y, user);
            
            // Test du prédicat
            if (predicate != NULL && predicate(block, user)) {
                // Libérer la mémoire
                for (int i = 0; i < 4; i++) {
                    free(ds[i]);
                }
                return y + 1;
            }
        }
    }
    
    // Libérer la mémoire
    for (int i = 0; i < 4; i++) {
        free(ds[i]);
    }
    
    return 0;
}

// Implémentation de getBlockFromNoise
Block get_block_from_noise(double noise, int y, void *user) {
    // user devrait pointer vers SurfaceGen pour accéder à seaLevel
    SurfaceGen *sg = (SurfaceGen*)user;

    Block block;
    if (noise > 0.0) {
        block = BLOCK_STONE;
    } else if (y < sg->seaLevel) {
        // NOTE: Dans le code Java original, cette branche retourne AIR
        // TODO: Tester si ça devrait être BLOCK_WATER au lieu de BLOCK_AIR
        block = BLOCK_AIR;
    } else {
        block = BLOCK_AIR;
    }

    return block;
}