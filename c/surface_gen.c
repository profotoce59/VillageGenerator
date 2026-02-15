#include "surface_gen.h"
#include "biomes.h"  // Pour DIM_OVERWORLD, DIM_NETHER, DIM_END
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>  // Pour printf (logs de debug)
#include <time.h>

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
static uint64_t pack_key(int x, int z) {
    return ( (uint64_t)( (uint32_t)x ) << 32 ) | (uint64_t)( (uint32_t)z );
}

typedef struct {
    uint64_t key;
    double *col; // length = noiseSizeY+1
    int in_use;
    int next;       // bucket chain
    int prev_fifo;  // FIFO list
    int next_fifo;
} CacheEntry;

typedef struct {
    CacheEntry *entries;
    double *columns;
    size_t capacity;
    size_t bucket_count;
    int *buckets;
    int free_head;
    int fifo_head;
    int fifo_tail;
    size_t count;
} SurfaceCache;

static size_t next_pow2(size_t v) {
    size_t p = 1;
    while (p < v) p <<= 1;
    return p;
}

static SurfaceCache* get_cache(SurfaceGen *sg) {
    if (!sg) return NULL;
    if (sg->cache) return (SurfaceCache*)sg->cache;
    size_t cap = sg->cache_capacity ? sg->cache_capacity : 4096;
    cap = next_pow2(cap);
    SurfaceCache *C = (SurfaceCache*)calloc(1, sizeof(SurfaceCache));
    if (!C) return NULL;
    C->capacity = cap;
    C->bucket_count = next_pow2(cap * 2);
    C->entries = (CacheEntry*)calloc(cap, sizeof(CacheEntry));
    if (!C->entries) {
        free(C);
        return NULL;
    }
    size_t len = (size_t)sg->noiseSizeY + 1;
    C->columns = (double*)calloc(cap * len, sizeof(double));
    if (!C->columns) {
        free(C->entries);
        free(C);
        return NULL;
    }
    C->buckets = (int*)calloc(C->bucket_count, sizeof(int));
    if (!C->buckets) {
        free(C->columns);
        free(C->entries);
        free(C);
        return NULL;
    }
    for (size_t i = 0; i < C->bucket_count; i++) {
        C->buckets[i] = -1;
    }
    for (size_t i = 0; i < cap; i++) {
        C->entries[i].col = C->columns + i * len;
        C->entries[i].in_use = 0;
        C->entries[i].next = (i + 1 < cap) ? (int)(i + 1) : -1;
        C->entries[i].prev_fifo = -1;
        C->entries[i].next_fifo = -1;
    }
    C->free_head = 0;
    C->fifo_head = -1;
    C->fifo_tail = -1;
    C->count = 0;
    sg->cache = C;
    return C;
}

static const double* cache_get(SurfaceGen *sg, uint64_t key) {
    SurfaceCache *C = get_cache(sg);
    if (!C) return NULL;
    size_t mask = C->bucket_count - 1;
    size_t b = mask ? (size_t)(key & mask) : 0;
    int idx = C->buckets[b];
    while (idx != -1) {
        CacheEntry *e = &C->entries[idx];
        if (e->key == key) {
            sg->cache_hits++;
            return e->col;
        }
        idx = e->next;
    }
    sg->cache_misses++;
    return NULL;
}

static void remove_from_bucket(SurfaceCache *C, uint64_t key, int entry_idx) {
    size_t mask = C->bucket_count - 1;
    size_t b = mask ? (size_t)(key & mask) : 0;
    int cur = C->buckets[b];
    int prev = -1;
    while (cur != -1) {
        if (cur == entry_idx) {
            if (prev == -1) {
                C->buckets[b] = C->entries[cur].next;
            } else {
                C->entries[prev].next = C->entries[cur].next;
            }
            return;
        }
        prev = cur;
        cur = C->entries[cur].next;
    }
}

static void cache_put(SurfaceGen *sg, uint64_t key, const double *src, int len) {
    SurfaceCache *C = get_cache(sg);
    if (!C) return;
    size_t mask = C->bucket_count - 1;
    size_t b = mask ? (size_t)(key & mask) : 0;
    int idx = C->buckets[b];
    while (idx != -1) {
        CacheEntry *e = &C->entries[idx];
        if (e->key == key) {
            memcpy(e->col, src, sizeof(double) * (size_t)len);
            return;
        }
        idx = e->next;
    }

    int entry_idx = -1;
    if (C->free_head != -1) {
        entry_idx = C->free_head;
        C->free_head = C->entries[entry_idx].next;
    } else if (C->fifo_head != -1) {
        // evict FIFO head
        entry_idx = C->fifo_head;
        CacheEntry *old = &C->entries[entry_idx];
        remove_from_bucket(C, old->key, entry_idx);
        C->fifo_head = old->next_fifo;
        if (C->fifo_head != -1) {
            C->entries[C->fifo_head].prev_fifo = -1;
        } else {
            C->fifo_tail = -1;
        }
    }

    if (entry_idx == -1) return;

    CacheEntry *e = &C->entries[entry_idx];
    e->key = key;
    e->in_use = 1;
    e->next = C->buckets[b];
    C->buckets[b] = entry_idx;
    memcpy(e->col, src, sizeof(double) * (size_t)len);

    // append to FIFO tail
    e->prev_fifo = C->fifo_tail;
    e->next_fifo = -1;
    if (C->fifo_tail != -1) {
        C->entries[C->fifo_tail].next_fifo = entry_idx;
    } else {
        C->fifo_head = entry_idx;
    }
    C->fifo_tail = entry_idx;
}

void free_surface_cache(SurfaceGen *sg) {
    if (!sg || !sg->cache) return;
    SurfaceCache *C = (SurfaceCache*)sg->cache;
    free(C->columns);
    free(C->entries);
    free(C->buckets);
    free(C);
    sg->cache = NULL;
    sg->cache_hits = 0;
    sg->cache_misses = 0;
}

void reset_surface_cache_stats(SurfaceGen *sg) {
    if (!sg) return;
    sg->cache_hits = 0;
    sg->cache_misses = 0;
}

void get_surface_cache_stats(SurfaceGen *sg, size_t *hits, size_t *misses) {
    if (!sg) return;
    if (hits) *hits = sg->cache_hits;
    if (misses) *misses = sg->cache_misses;
}



// ---------- cœur : sample_noise_column (branche 1.16+) ----------
void sample_noise_column(SurfaceGen *sg, double *buffer, int x, int z)
{
    double ds[2] = {0.0, 0.0};
    sg->get_depth_and_scale(x, z, ds, sg->user);
    double depth = ds[0];
    double scale = ds[1];

    // randomOffset (only Overworld)
    double randomOffset = 0.0;
    if (sg->dim == DIM_OVERWORLD && sg->sample_noise_2d) {
        randomOffset = sg->sample_noise_2d(x, z, sg->user);
    }
 

    for (int y = 0; y < sg->startSizeY; ++y) {

        double noise = sg->sample_noise_3d(x, y, z, sg->user);

        // ==== branche 1.16+ ====
        double fallOff1 = 1.0 - (double)y * 2.0 / (double)sg->noiseSizeY + randomOffset;
        double fallOff2 = fallOff1 * sg->densityFactor + sg->densityOffset;
        double fallOff3 = (fallOff2 + depth) * scale;

        double fallOff = fallOff3;
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
    const double *ds[4];
    ds[0] = sample_noise_column_cached(sg, cellX, cellZ);
    ds[1] = sample_noise_column_cached(sg, cellX, cellZ + 1);
    ds[2] = sample_noise_column_cached(sg, cellX + 1, cellZ);
    ds[3] = sample_noise_column_cached(sg, cellX + 1, cellZ + 1);

    double *tmp_ds[4] = {0};
    if (!ds[0] || !ds[1] || !ds[2] || !ds[3]) {
        int len = sg->noiseSizeY + 1;
        for (int i = 0; i < 4; i++) {
            tmp_ds[i] = (double*)calloc((size_t)len, sizeof(double));
        }
        sample_noise_column(sg, tmp_ds[0], cellX, cellZ);
        sample_noise_column(sg, tmp_ds[1], cellX, cellZ + 1);
        sample_noise_column(sg, tmp_ds[2], cellX + 1, cellZ);
        sample_noise_column(sg, tmp_ds[3], cellX + 1, cellZ + 1);
        ds[0] = tmp_ds[0];
        ds[1] = tmp_ds[1];
        ds[2] = tmp_ds[2];
        ds[3] = tmp_ds[3];
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


            

            // Test du prédicat
            if (predicate != NULL && predicate(block, user)) {
                if (tmp_ds[0]) {
                    for (int i = 0; i < 4; i++) {
                        free(tmp_ds[i]);
                    }
                }
                return y + 1;
            }
        }
    }
    if (tmp_ds[0]) {
        for (int i = 0; i < 4; i++) {
            free(tmp_ds[i]);
        }
    }
    return 0;
}

// Calcule la valeur de bruit à un seul y pour une colonne (x,z).
// depth, scale, randomOffset doivent être pré-calculés.
static inline double sample_noise_at_y(SurfaceGen *sg, int x, int y, int z,
                                        double depth, double scale, double randomOffset)
{
    double noise = sg->sample_noise_3d(x, y, z, sg->user);

    double fallOff1 = 1.0 - (double)y * 2.0 / (double)sg->noiseSizeY + randomOffset;
    double fallOff2 = fallOff1 * sg->densityFactor + sg->densityOffset;
    double fallOff3 = (fallOff2 + depth) * scale;

    if (fallOff3 > 0.0)
        noise = noise + fallOff3 * 4.0;
    else
        noise = noise + fallOff3;

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
    return noise;
}

// Pré-calcule depth/scale/randomOffset pour une colonne (x,z)
static inline void get_column_params(SurfaceGen *sg, int x, int z,
                                      double *depth, double *scale, double *randomOffset)
{
    double ds[2] = {0.0, 0.0};
    sg->get_depth_and_scale(x, z, ds, sg->user);
    *depth = ds[0];
    *scale = ds[1];
    *randomOffset = 0.0;
    if (sg->dim == DIM_OVERWORLD && sg->sample_noise_2d) {
        *randomOffset = sg->sample_noise_2d(x, z, sg->user);
    }
}

// Version early-exit : tente d'abord le cache, puis calcule à la volée de haut en bas.
// Pour les cache hits → utilise les colonnes complètes (identique à generate_column_from_y).
// Pour les cache misses → calcule seulement les y nécessaires et s'arrête dès match.
int generate_column_from_y_early_exit(SurfaceGen *sg, int x, int z,
                                       BlockPredicate predicate, void *user)
{
    int cellX = (int)floor((double)x / (double)sg->chunkWidth);
    int cellZ = (int)floor((double)z / (double)sg->chunkWidth);

    int posX = ((x % sg->chunkWidth) + sg->chunkWidth) % sg->chunkWidth;
    int posZ = ((z % sg->chunkWidth) + sg->chunkWidth) % sg->chunkWidth;

    double percentX = (double)posX / (double)sg->chunkWidth;
    double percentZ = (double)posZ / (double)sg->chunkWidth;

    // Essayer le cache pour les 4 coins
    uint64_t keys[4] = {
        pack_key(cellX, cellZ), pack_key(cellX, cellZ + 1),
        pack_key(cellX + 1, cellZ), pack_key(cellX + 1, cellZ + 1)
    };
    const double *cached[4] = {
        cache_get(sg, keys[0]), cache_get(sg, keys[1]),
        cache_get(sg, keys[2]), cache_get(sg, keys[3])
    };

    // Si toutes les colonnes sont cachées → fast path (pas de calcul de bruit)
    if (cached[0] && cached[1] && cached[2] && cached[3]) {
        for (int cellY = sg->startSizeY - 1; cellY >= 0; --cellY) {
            double xyz = cached[0][cellY],   xyz1 = cached[1][cellY];
            double x1yz = cached[2][cellY],  x1yz1 = cached[3][cellY];
            double xy1z = cached[0][cellY+1], xy1z1 = cached[1][cellY+1];
            double x1y1z = cached[2][cellY+1], x1y1z1 = cached[3][cellY+1];

            for (int posY = sg->chunkHeight - 1; posY >= 0; --posY) {
                double percentY = (double)posY / (double)sg->chunkHeight;
                double noise = lerp3(percentY, percentX, percentZ,
                                   xyz, xy1z, x1yz, x1y1z,
                                   xyz1, xy1z1, x1yz1, x1y1z1);
                int y = cellY * sg->chunkHeight + posY;
                Block block = get_block_from_noise(noise, y, user);
                if (predicate != NULL && predicate(block, user))
                    return y + 1;
            }
        }
        return 0;
    }

    // Slow path : early-exit (calcule seulement les y nécessaires)
    double depth[4], scale[4], roff[4];
    int cornerX[4] = {cellX, cellX, cellX+1, cellX+1};
    int cornerZ[4] = {cellZ, cellZ+1, cellZ, cellZ+1};
    for (int i = 0; i < 4; i++) {
        if (!cached[i]) {
            get_column_params(sg, cornerX[i], cornerZ[i], &depth[i], &scale[i], &roff[i]);
        }
    }

    int startY = sg->startSizeY;
    // top[i] = noise at y=startSizeY : 0 for non-cached (buffer[startSizeY] never written),
    // cached[startSizeY] for cached columns
    double top[4];
    for (int i = 0; i < 4; i++)
        top[i] = cached[i] ? cached[i][startY] : 0.0;

    for (int cellY = startY - 1; cellY >= 0; --cellY) {
        double bot[4];
        for (int i = 0; i < 4; i++) {
            if (cached[i])
                bot[i] = cached[i][cellY];
            else
                bot[i] = sample_noise_at_y(sg, cornerX[i], cellY, cornerZ[i], depth[i], scale[i], roff[i]);
        }

        for (int posY = sg->chunkHeight - 1; posY >= 0; --posY) {
            double percentY = (double)posY / (double)sg->chunkHeight;
            double noise = lerp3(percentY, percentX, percentZ,
                               bot[0], top[0], bot[2], top[2],
                               bot[1], top[1], bot[3], top[3]);
            int y = cellY * sg->chunkHeight + posY;
            Block block = get_block_from_noise(noise, y, user);
            if (predicate != NULL && predicate(block, user))
                return y + 1;
        }

        // Le bas de cette cellule devient le haut de la cellule en dessous
        top[0] = bot[0]; top[1] = bot[1]; top[2] = bot[2]; top[3] = bot[3];
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
        // Java: default fluid below sea level
        block = BLOCK_WATER;
    } else {
        block = BLOCK_AIR;
    }

    return block;
}
