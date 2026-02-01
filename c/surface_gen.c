#include "surface_gen.h"
#include "biomes.h"  // Pour DIM_OVERWORLD, DIM_NETHER, DIM_END
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>  // Pour printf (logs de debug)

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
    // TODO: get_depth_and_scale retourne des valeurs différentes de Java!
    // Java: depth=-0.0162, scale=652.02
    // C:    depth=-0.0066, scale=342.86
    // Le problème est dans cubiomes_get_depth_and_scale (cubiomes_integration.c)
    double ds[2] = {0.0, 0.0};
    sg->get_depth_and_scale(x, z, ds, sg->user);
    double depth = ds[0];
    double scale = ds[1];

    // randomOffset (only Overworld)
    double randomOffset = 0.0;
    if (sg->dim == DIM_OVERWORLD && sg->sample_noise_2d) {
        randomOffset = sg->sample_noise_2d(x, z, sg->user);
    }

    // LOG: paramètres pour position test
    int enableLogs = (x == 20121 && z == 20185);
    if (enableLogs) {
        printf("\n=== C sample_noise_column ===\n");
        printf("Position: x=%d, z=%d\n", x, z);
        printf("depth: %.10f, scale: %.10f\n", depth, scale);
        printf("randomOffset: %.10f\n", randomOffset);
        printf("densityFactor: %.10f, densityOffset: %.10f\n", sg->densityFactor, sg->densityOffset);
        printf("noiseSizeY: %d, startSizeY: %d\n", sg->noiseSizeY, sg->startSizeY);
    }

    for (int y = 6; y < sg->startSizeY; ++y) {

        // bruit principal 3D à (x,y,z) dans l'espace "cellule"
        double noise = sg->sample_noise_3d(x, y, z, sg->user);

        // ==== branche 1.16+ ====
        double fallOff1 = 1.0 - (double)y * 2.0 / (double)sg->noiseSizeY + randomOffset;
        double fallOff2 = fallOff1 * sg->densityFactor + sg->densityOffset;
        double fallOff3 = (fallOff2 + depth) * scale;

        if (enableLogs && y == 9) {
            printf("\n=== y=9 falloff calculation ===\n");
            printf("noise (brut): %.10f\n", noise);
            printf("fallOff step1: 1.0 - %d * 2.0 / %d + %.10f = %.10f\n", y, sg->noiseSizeY, randomOffset, fallOff1);
            printf("fallOff step2: %.10f * %.10f + %.10f = %.10f\n", fallOff1, sg->densityFactor, sg->densityOffset, fallOff2);
            printf("fallOff step3: (%.10f + %.10f) * %.10f = %.10f\n", fallOff2, depth, scale, fallOff3);
        }

        double fallOff = fallOff3;
        if (fallOff > 0.0)
            noise = noise + fallOff * 4.0;
        else
            noise = noise + fallOff;

        if (enableLogs && y == 9) {
            printf("fallOff > 0 ? %s -> noise après falloff: %.10f\n", fallOff > 0 ? "OUI" : "NON", noise);
        }

        // slides (top / bottom)
        if (sg->noiseSettings.topSlideSettings.size > 0.0) {
            double num = ((double)(sg->noiseSizeY - y) - sg->noiseSettings.topSlideSettings.offset)
                         / sg->noiseSettings.topSlideSettings.size;
            if (enableLogs && y == 9) {
                printf("topSlide: num = ((%d - %d) - %.1f) / %.1f = %.10f\n",
                       sg->noiseSizeY, y, sg->noiseSettings.topSlideSettings.offset,
                       sg->noiseSettings.topSlideSettings.size, num);
            }
            noise = clamped_lerp(sg->noiseSettings.topSlideSettings.target, noise, num);
            if (enableLogs && y == 9) {
                printf("noise après topSlide: %.10f\n", noise);
            }
        }
        if (sg->noiseSettings.bottomSlideSettings.size > 0.0) {
            double num = ((double)y - sg->noiseSettings.bottomSlideSettings.offset)
                         / sg->noiseSettings.bottomSlideSettings.size;
            noise = clamped_lerp(sg->noiseSettings.bottomSlideSettings.target, noise, num);
        }

        if (enableLogs && y == 9) {
            printf("buffer[9] FINAL = %.10f\n", noise);
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
    // LOG: Activer uniquement pour position de test
    int enableLogs = (x == 80485 && z == 80741);
    if (enableLogs) {
        printf("--- C generate_column_from_y ---\n");
        printf("Position: (%d, %d)\n", x, z);
    }

    // Coordonnées de la cellule dans la grille
    int cellX = (int)floor((double)x / (double)sg->chunkWidth);
    int cellZ = (int)floor((double)z / (double)sg->chunkWidth);

    // Coordonnées locales dans la cellule
    int posX = ((x % sg->chunkWidth) + sg->chunkWidth) % sg->chunkWidth;
    int posZ = ((z % sg->chunkWidth) + sg->chunkWidth) % sg->chunkWidth;

    // Pourcentages de position
    double percentX = (double)posX / (double)sg->chunkWidth;
    double percentZ = (double)posZ / (double)sg->chunkWidth;

    if (enableLogs) {
        printf("chunkWidth: %d\n", sg->chunkWidth);
        printf("cellX: %d, cellZ: %d\n", cellX, cellZ);
        printf("posX: %d, posZ: %d\n", posX, posZ);
        printf("percentX: %.6f, percentZ: %.6f\n", percentX, percentZ);
    }
    
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

    // LOG: Afficher les valeurs échantillonnées aux 4 coins pour cellY=9
    if (enableLogs && len > 9) {
        printf("\nValeurs de noise échantillonnées aux 4 coins (cellY=9):\n");
        printf("  ds[0][9] (cellX, cellZ): %.6f\n", ds[0][9]);
        printf("  ds[1][9] (cellX, cellZ+1): %.6f\n", ds[1][9]);
        printf("  ds[2][9] (cellX+1, cellZ): %.6f\n", ds[2][9]);
        printf("  ds[3][9] (cellX+1, cellZ+1): %.6f\n", ds[3][9]);
        printf("  ds[0][10] (cellX, cellZ): %.6f\n", ds[0][10]);
        printf("  ds[1][10] (cellX, cellZ+1): %.6f\n", ds[1][10]);
        printf("  ds[2][10] (cellX+1, cellZ): %.6f\n", ds[2][10]);
        printf("  ds[3][10] (cellX+1, cellZ+1): %.6f\n", ds[3][10]);
        printf("\n");
    }

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

            // LOG: Détails pour Y autour de 68-76
            
            printf("  cellY=%d, posY=%d, y=%d, percentY=%.4f, noise=%.6f, block=%d\n",
                       cellY, posY, y, percentY, noise, block);
            

            // Test du prédicat
            if (predicate != NULL && predicate(block, user)) {
                // Libérer la mémoire
                for (int i = 0; i < 4; i++) {
                    free(ds[i]);
                }
                if (enableLogs) {
                    printf(">>> BLOC TROUVÉ à y=%d (retourne %d)\n", y, y + 1);
                }
                return y + 1;
            }
        }
    }
    
    // Libérer la mémoire
    for (int i = 0; i < 4; i++) {
        free(ds[i]);
    }
    if (enableLogs) {
        printf(">>> AUCUN BLOC TROUVÉ (retourne 0)\n");
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