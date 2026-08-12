#include "SurfaceGenWrapper.hpp"
#include <cstdlib>
#include <new>
#include <iostream>
#include <cstdint>
#include <chrono>

static SurfaceGenWrapper::Stats g_stats =
    {0, 0, 0, 0, INT32_MAX, INT32_MIN, INT32_MAX, INT32_MIN, 0, 0};

SurfaceGenWrapper::Stats SurfaceGenWrapper::getStats() { return g_stats; }
void SurfaceGenWrapper::resetStats() {
    g_stats = Stats{0, 0, 0, 0, INT32_MAX, INT32_MIN, INT32_MAX, INT32_MIN, 0, 0};
}

static HeightProvider* g_heightProvider = nullptr;
static bool g_verifyProvider = false;

void SurfaceGenWrapper::setVerifyProvider(bool enabled) { g_verifyProvider = enabled; }

static FILE* g_trace = nullptr;

void SurfaceGenWrapper::setQueryTrace(const char* path) {
    if (g_trace) { fclose(g_trace); g_trace = nullptr; }
    if (path) g_trace = fopen(path, "w");
}

void SurfaceGenWrapper::setHeightProvider(HeightProvider* provider) {
    g_heightProvider = provider;
}
HeightProvider* SurfaceGenWrapper::getHeightProvider() { return g_heightProvider; }

void SurfaceGenWrapper::prefetchRegion(int x0, int z0, int w, int h) {
    prefetchGeneration = 0;
    if (!g_heightProvider || !sg || w <= 0 || h <= 0) return;
    prefetchGeneration = g_heightProvider->prefetch(sg, x0, z0, w, h);
}

// Prédicat par défaut : retourne 1 (true) pour tout bloc non-air
int SurfaceGenWrapper::defaultNotAirPredicate(Block block, void* user) {
    (void)user;  // Paramètre non utilisé
    return (block != BLOCK_AIR) ? 1 : 0;
}

// Prédicat WORLD_SURFACE_WG : correspond au premier bloc solide (STONE)
int SurfaceGenWrapper::worldSurfaceWGPredicate(Block block, void* user) {
    (void)user;
    return (block == BLOCK_STONE) ? 1 : 0;
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
    const bool notAir = (!predicate || predicate == defaultNotAirPredicate);
    if (!predicate) {
        predicate = defaultNotAirPredicate;
    }
    g_stats.columnQueries++;
    if (x < g_stats.minX) g_stats.minX = x;
    if (x > g_stats.maxX) g_stats.maxX = x;
    if (z < g_stats.minZ) g_stats.minZ = z;
    if (z > g_stats.maxZ) g_stats.maxZ = z;

    auto t0 = std::chrono::steady_clock::now();

    // La zone pré-calculée ne couvre que le prédicat non-air, et seulement si
    // c'est bien CETTE instance qui l'a demandée.
    int h = -1;
    if (notAir && prefetchGeneration != 0 && g_heightProvider &&
        g_heightProvider->currentGeneration() == prefetchGeneration) {
        h = g_heightProvider->lookup(x, z);
    }

    if (h >= 0) {
        g_stats.providerHits++;
        if (g_verifyProvider) {
            int ref = generate_column_from_y(sg, x, z, predicate, sg);
            if (ref != h) {
                std::cerr << "[verify] ECART a (" << x << ", " << z << ") : provider="
                          << h << " C=" << ref
                          << "  startSizeY=" << sg->startSizeY
                          << " noiseSizeY=" << sg->noiseSizeY << std::endl;
            }
        }
    } else {
        if (notAir && prefetchGeneration != 0) g_stats.providerMisses++;
        h = generate_column_from_y(sg, x, z, predicate, sg);
    }

    g_stats.columnNanos += (uint64_t)std::chrono::duration_cast<std::chrono::nanoseconds>(
        std::chrono::steady_clock::now() - t0).count();

    if (g_trace)
        fprintf(g_trace, "%d %d %d %d %d\n", x, z, h, sg->startSizeY, notAir ? 1 : 0);

    return h;
}

int SurfaceGenWrapper::generateColumnFromYEarlyExit(int x, int z, BlockPredicate predicate) {
    if (!predicate) {
        predicate = defaultNotAirPredicate;
    }
    return generate_column_from_y_early_exit(sg, x, z, predicate, sg);
}

int SurfaceGenWrapper::getHeightOnGround(int x, int z) {
    // small FIFO cache to avoid recomputing height for same (x,z)
    for (size_t i = 0; i < HEIGHT_CACHE_CAP; i++) {
        if (heightCache[i].valid && heightCache[i].x == x && heightCache[i].z == z) {
            heightCacheHits++;
            g_stats.groundCacheHits++;
            return heightCache[i].height;
        }
    }
    heightCacheMisses++;
    g_stats.groundQueries++;

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
    int height = generateColumnFromY(x, z, defaultNotAirPredicate);
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
