#include "SurfaceGenWrapper.hpp"
#include <cstdlib>
#include <new>
#include <iostream>
#include <cstdint>

// Prédicat par défaut : retourne 1 (true) pour tout bloc non-air
int SurfaceGenWrapper::defaultNotAirPredicate(Block block, void* user) {
    (void)user;  // Paramètre non utilisé
    return (block != BLOCK_AIR) ? 1 : 0;
}

// Prédicat WORLD_SURFACE_WG : pour l'instant, identique au prédicat par défaut
// car notre génération de surface ne produit que STONE/WATER/AIR (pas de blocs décoratifs détaillés)
// La différence de 3 blocs vient probablement d'un décalage dans le calcul du bruit ou des coordonnées
int SurfaceGenWrapper::worldSurfaceWGPredicate(Block block, void* user) {
    (void)user;
    // Pour l'instant, même logique que defaultNotAirPredicate
    // TODO: Investiguer pourquoi nous obtenons Y=74 au lieu de Y=71
    return (block != BLOCK_AIR) ? 1 : 0;
}

SurfaceGenWrapper::SurfaceGenWrapper(uint64_t worldSeed, int mcVersion) {
    // Allouer le contexte cubiomes
    ctx = (CubiomesContext*)malloc(sizeof(CubiomesContext));
    if (!ctx) {
        throw std::bad_alloc();
    }

    // Initialiser cubiomes avec la seed et la version MC
    init_cubiomes_context(ctx, mcVersion, worldSeed);

    // Allouer et configurer SurfaceGen
    sg = (SurfaceGen*)calloc(1, sizeof(SurfaceGen));
    if (!sg) {
        free(ctx);
        throw std::bad_alloc();
    }

    setup_surface_gen_with_cubiomes(sg, ctx);
    resetHeightCache();
}

SurfaceGenWrapper::~SurfaceGenWrapper() {
    // Libérer le cache si nécessaire
    if (sg) {
        free_surface_cache(sg);
        free(sg);
    }
    if (ctx) {
        free_cubiomes_context_cache(ctx);
        free(ctx);
    }
}

int SurfaceGenWrapper::generateColumnFromY(int x, int z, BlockPredicate predicate) {
    // Si aucun prédicat n'est fourni, utiliser le prédicat par défaut (non-air)
    if (!predicate) {
        predicate = defaultNotAirPredicate;
    }

    // Appeler la fonction C
    return generate_column_from_y(sg, x, z, predicate, sg);
}

int SurfaceGenWrapper::getHeightOnGround(int x, int z) {
    // small FIFO cache to avoid recomputing height for same (x,z)
    for (size_t i = 0; i < HEIGHT_CACHE_CAP; i++) {
        if (heightCache[i].valid && heightCache[i].x == x && heightCache[i].z == z) {
            heightCacheHits++;
            return heightCache[i].height;
        }
    }
    heightCacheMisses++;

    // Utiliser le prédicat WORLD_SURFACE_WG (comme en Java pour les villages)
    int height = generateColumnFromY(x, z, worldSurfaceWGPredicate);

    // insert with FIFO cursor
    heightCache[heightCacheCursor].x = x;
    heightCache[heightCacheCursor].z = z;
    heightCache[heightCacheCursor].height = height;
    heightCache[heightCacheCursor].valid = 1;
    heightCacheCursor = (heightCacheCursor + 1) % HEIGHT_CACHE_CAP;

    // DEBUG désactivé pour les tests de pièces
    // static bool first_call = true;
    // if (first_call) {
    //     std::cout << "  [DEBUG SurfaceGen] Hauteur brute à (" << x << ", " << z << "): " << height << std::endl;
    //     first_call = false;
    // }

    // La hauteur est maintenant correcte après la correction de getDepthAndScale
    // (version MC corrigée à 19, lookup biome avec seaLevel=63, weight table corrigée)
    return height;
}

void SurfaceGenWrapper::resetHeightCache() {
    for (size_t i = 0; i < HEIGHT_CACHE_CAP; i++) {
        heightCache[i].valid = 0;
    }
    heightCacheCursor = 0;
    heightCacheHits = 0;
    heightCacheMisses = 0;
}

int SurfaceGenWrapper::getFirstHeightFull(int x, int z) {
    if (!sg) return 0;
    int oldStart = sg->startSizeY;
    sg->startSizeY = sg->noiseSizeY;
    // cache dépend de startSizeY
    free_surface_cache(sg);
    int height = generateColumnFromY(x, z, worldSurfaceWGPredicate);
    // restaurer et invalider
    sg->startSizeY = oldStart;
    free_surface_cache(sg);
    return height;
}

void SurfaceGenWrapper::setStartSizeY(int startSizeYBlocks) {
    if (!sg) return;
    int cell = startSizeYBlocks / 8;
    if (cell > sg->noiseSizeY) {
        cell = sg->noiseSizeY;
    }
    if (cell > sg->startSizeY) {
        sg->startSizeY = cell;
        // Invalider le cache: les colonnes dépendant de startSizeY doivent être recalculées.
        free_surface_cache(sg);
    }
}

void SurfaceGenWrapper::setStartSizeYExact(int startSizeYBlocks) {
    if (!sg) return;
    int cell = startSizeYBlocks / 8; // match Java int division
    if (cell < 0) cell = 0;
    if (cell > sg->noiseSizeY) {
        cell = sg->noiseSizeY;
    }
    if (cell != sg->startSizeY) {
        sg->startSizeY = cell;
        free_surface_cache(sg);
    }
}

void SurfaceGenWrapper::debugPrintNoiseColumn(int x, int z, int yStart, int yEnd) {
    if (!sg) return;
    if (yStart < 0) yStart = 0;
    if (yEnd < yStart) return;

    double ds[2] = {0.0, 0.0};
    if (sg->get_depth_and_scale) {
        sg->get_depth_and_scale(x, z, ds, sg->user);
    }
    double randomOffset = 0.0;
    if (sg->dim == DIM_OVERWORLD && sg->sample_noise_2d) {
        randomOffset = sg->sample_noise_2d(x, z, sg->user);
    }

    std::cout.setf(std::ios::fixed);
    std::cout.precision(10);
    std::cout << "[C++][DBG] x=" << x << " z=" << z
              << " depth=" << ds[0] << " scale=" << ds[1]
              << " randomOffset=" << randomOffset
              << " startSizeY=" << sg->startSizeY
              << " noiseSizeY=" << sg->noiseSizeY
              << std::endl;

    int len = sg->noiseSizeY + 1;
    double* buf = (double*)calloc((size_t)len, sizeof(double));
    if (!buf) return;
    sample_noise_column(sg, buf, x, z);

    if (yEnd >= len) yEnd = len - 1;
    for (int y = yStart; y <= yEnd; ++y) {
        std::cout << "[C++][DBG] noise[" << y << "]=" << buf[y] << std::endl;
    }
    free(buf);
}
