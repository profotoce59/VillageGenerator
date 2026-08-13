#include "SurfaceGenWrapper.hpp"
#include "Profiler.hpp"
#include <cstdlib>
#include <new>
#include <iostream>
#include <cstdint>
#include <chrono>
#include <mutex>
#include <vector>

static SurfaceGenWrapper::Stats emptyStats() {
    return SurfaceGenWrapper::Stats{0, 0, 0, 0, INT32_MAX, INT32_MIN, INT32_MAX, INT32_MIN, 0, 0};
}

// Un bloc de compteurs par thread, enregistré dans une liste globale pour que
// getStats() puisse tout sommer. Les blocs ne sont jamais libérés : ils vivent
// aussi longtemps que le processus, ce qui évite d'avoir à synchroniser la fin
// des threads avec la lecture des stats.
namespace {
struct StatsBlock { SurfaceGenWrapper::Stats s; };
std::mutex g_statsMutex;
std::vector<StatsBlock*> g_statsBlocks;
thread_local StatsBlock* t_statsBlock = nullptr;

StatsBlock& localStats() {
    if (!t_statsBlock) {
        t_statsBlock = new StatsBlock{emptyStats()};
        std::lock_guard<std::mutex> lk(g_statsMutex);
        g_statsBlocks.push_back(t_statsBlock);
    }
    return *t_statsBlock;
}
} // namespace

SurfaceGenWrapper::Stats SurfaceGenWrapper::getStats() {
    Stats total = emptyStats();
    std::lock_guard<std::mutex> lk(g_statsMutex);
    for (const StatsBlock* b : g_statsBlocks) {
        total.columnQueries   += b->s.columnQueries;
        total.groundQueries   += b->s.groundQueries;
        total.groundCacheHits += b->s.groundCacheHits;
        total.columnNanos     += b->s.columnNanos;
        total.providerHits    += b->s.providerHits;
        total.providerMisses  += b->s.providerMisses;
        if (b->s.minX < total.minX) total.minX = b->s.minX;
        if (b->s.maxX > total.maxX) total.maxX = b->s.maxX;
        if (b->s.minZ < total.minZ) total.minZ = b->s.minZ;
        if (b->s.maxZ > total.maxZ) total.maxZ = b->s.maxZ;
    }
    return total;
}

void SurfaceGenWrapper::resetStats() {
    std::lock_guard<std::mutex> lk(g_statsMutex);
    for (StatsBlock* b : g_statsBlocks) b->s = emptyStats();
}

// Par thread : un CudaHeightProvider possède un contexte CUDA et une zone
// pré-calculée, il ne peut pas être partagé entre threads.
static thread_local HeightProvider* t_heightProvider = nullptr;
static thread_local bool t_verifyProvider = false;
static thread_local FILE* t_trace = nullptr;

void SurfaceGenWrapper::setVerifyProvider(bool enabled) { t_verifyProvider = enabled; }

void SurfaceGenWrapper::setQueryTrace(const char* path) {
    if (t_trace) { fclose(t_trace); t_trace = nullptr; }
    if (path) t_trace = fopen(path, "w");
}

void SurfaceGenWrapper::setHeightProvider(HeightProvider* provider) {
    t_heightProvider = provider;
}
HeightProvider* SurfaceGenWrapper::getHeightProvider() { return t_heightProvider; }

void SurfaceGenWrapper::prefetchRegion(int x0, int z0, int w, int h) {
    VPROF_SCOPE(VZ_PREFETCH);
    prefetchGeneration = 0;
    if (!t_heightProvider || !sg || w <= 0 || h <= 0) return;
    prefetchGeneration = t_heightProvider->prefetch(sg, x0, z0, w, h);
    prefetchStartSizeY = sg->startSizeY;
    prefetchX0 = x0; prefetchZ0 = z0; prefetchW = w; prefetchH = h;
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
    VPROF_SCOPE(VZ_SURFACEGEN_CTOR);
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
    VPROF_SCOPE(VZ_HEIGHT_QUERY);
    Stats& st = localStats().s;
    st.columnQueries++;
    if (x < st.minX) st.minX = x;
    if (x > st.maxX) st.maxX = x;
    if (z < st.minZ) st.minZ = z;
    if (z > st.maxZ) st.maxZ = z;

    auto t0 = std::chrono::steady_clock::now();

    // Une reprise de scan a fait grandir startSizeY : la zone pré-calculée est
    // périmée. La recalculer coûte un lancement GPU, bien moins que de traiter
    // sur CPU toutes les requêtes restantes du village. startSizeY ne peut
    // grandir que START_SIZE_MAX_TRIES fois, donc ça converge.
    if (notAir && prefetchGeneration != 0 && sg->startSizeY != prefetchStartSizeY &&
        prefetchW > 0 && prefetchH > 0) {
        prefetchRegion(prefetchX0, prefetchZ0, prefetchW, prefetchH);
    }

    // La zone pré-calculée ne couvre que le prédicat non-air, et seulement si
    // c'est bien CETTE instance qui l'a demandée.
    int h = -1;
    if (notAir && prefetchGeneration != 0 && t_heightProvider &&
        sg->startSizeY == prefetchStartSizeY &&
        t_heightProvider->currentGeneration() == prefetchGeneration) {
        h = t_heightProvider->lookup(x, z);
    }

    if (h >= 0) {
        st.providerHits++;
        if (t_verifyProvider) {
            int ref = generate_column_from_y(sg, x, z, predicate, sg);
            if (ref != h) {
                std::cerr << "[verify] ECART a (" << x << ", " << z << ") : provider="
                          << h << " C=" << ref
                          << "  startSizeY=" << sg->startSizeY
                          << " noiseSizeY=" << sg->noiseSizeY << std::endl;
            }
        }
    } else {
        if (notAir && prefetchGeneration != 0) st.providerMisses++;
        h = generate_column_from_y(sg, x, z, predicate, sg);
    }

    st.columnNanos += (uint64_t)std::chrono::duration_cast<std::chrono::nanoseconds>(
        std::chrono::steady_clock::now() - t0).count();

    if (t_trace)
        fprintf(t_trace, "%d %d %d %d %d\n", x, z, h, sg->startSizeY, notAir ? 1 : 0);

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
            localStats().s.groundCacheHits++;
            return heightCache[i].height;
        }
    }
    heightCacheMisses++;
    localStats().s.groundQueries++;

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
