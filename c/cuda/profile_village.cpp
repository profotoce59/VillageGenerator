/**
 * profile_village.cpp — où part le temps de génération d'un village ?
 *
 * Compilé avec -DVILLAGE_PROFILE : les sondes de c/Profiler.hpp sont actives.
 * Elles coûtent deux appels à steady_clock par zone, donc les temps absolus
 * sont un peu gonflés par rapport à bench_village — c'est la répartition
 * relative qui compte ici, pas le débit.
 *
 * Usage : profile_village.exe [--cuda|--c] [--seed N] [--count N]
 */

#include "cuda_height_provider.hpp"

#include "../VillageGenerator.hpp"
#include "../TerrainGenerator.hpp"
#include "../BiomeSource.hpp"
#include "../Biome.hpp"
#include "../ChunkRand.hpp"
#include "../SurfaceGenWrapper.hpp"
#include "../Profiler.hpp"

extern "C" {
    #include "finders.h"
}

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <chrono>
#include <atomic>
#include <memory>
#include <mutex>
#include <thread>
#include <vector>

using Clock = std::chrono::steady_clock;

int main(int argc, char** argv)
{
    bool useCuda  = true;
    uint64_t seed = 1;
    long count    = 300;
    int  nThreads = 1;
    bool taigaOnly = false;   // reproduit la charge de la recherche filtree

    for (int i = 1; i < argc; i++) {
        if      (!strcmp(argv[i], "--cuda")) useCuda = true;
        else if (!strcmp(argv[i], "--c"))    useCuda = false;
        else if (!strcmp(argv[i], "--seed")  && i+1 < argc) seed  = strtoull(argv[++i], nullptr, 10);
        else if (!strcmp(argv[i], "--count") && i+1 < argc) count = strtol(argv[++i], nullptr, 10);
        else if (!strcmp(argv[i], "--threads") && i+1 < argc) nThreads = atoi(argv[++i]);
        else if (!strcmp(argv[i], "--taiga")) taigaOnly = true;
        else { fprintf(stderr, "argument inconnu : %s\n", argv[i]); return 2; }
    }

    printf("=== Profil de génération de villages ===\n");
    printf("backend : %s | seed : %llu | villages : %ld\n\n",
           useCuda ? "CUDA" : "C", (unsigned long long)seed, count);

    {
        const char* env = getenv("CUBIOMES_LAYER_CACHE");
        if (!env || env[0] != '0')
            printf("(CUBIOMES_LAYER_CACHE non nul : les biomes des requêtes 1x1 sont faux,\n"
                   " ça n'invalide pas le profil mais les villages générés ne sont pas justes)\n\n");
    }

    // Prechauffage CUDA hors mesure (init du contexte driver, ~100 ms).
    if (useCuda) {
        CudaHeightProvider warmProvider;
        SurfaceGenWrapper::setHeightProvider(&warmProvider);
        SurfaceGenWrapper warm(seed, 19);
        warm.setStartSizeYExact(120);
        warm.prefetchRegion(0, 0, 194, 194);
        SurfaceGenWrapper::setHeightProvider(nullptr);
    }

    std::vector<Pos> posList;
    for (int rx = 0; rx < 10; rx++) {
        for (int rz = 0; rz < 10; rz++) {
            Pos p;
            if (getStructurePos(Village, MC_1_16, seed & MASK48, rx, rz, &p)) {
                Pos c; c.x = p.x >> 4; c.z = p.z >> 4;
                posList.push_back(c);
            }
        }
    }

    // Le travail est un ENSEMBLE de world seeds (0..count-1), reparti par pas
    // entre les threads : la charge est donc identique quel que soit nThreads,
    // ce qui rend les profils comparables entre eux.
    vprofReset();
    std::atomic<long>     villages{0};
    std::atomic<uint64_t> pieces{0};
    auto tStart = Clock::now();

    {
        std::vector<std::thread> pool;
        for (int t = 0; t < nThreads; t++) {
            pool.emplace_back([&, t]() {
                std::unique_ptr<CudaHeightProvider> provider;
                if (useCuda) {
                    provider = std::make_unique<CudaHeightProvider>();
                    SurfaceGenWrapper::setHeightProvider(provider.get());
                }
                for (long ws = t; ws < count; ws += nThreads) {
                    uint64_t worldSeed = (seed & MASK48) | ((uint64_t)ws << 48);

                    Generator g;
                    std::unique_ptr<OverworldTerrainGenerator> tg;
                    {
                        VPROF_SCOPE(VZ_WORLD_SETUP);
                        setupGenerator(&g, MC_1_16, 0);
                        applySeed(&g, DIM_OVERWORLD, worldSeed);
                        auto bs = std::make_unique<SimpleBiomeSource>(worldSeed);
                        tg = std::make_unique<OverworldTerrainGenerator>(worldSeed, std::move(bs));
                    }

                    for (const Pos& sp : posList) {
                        bool viable;
                        { VPROF_SCOPE(VZ_VIABLE);
                          viable = isViableStructurePos(Village, &g, sp.x << 4, sp.z << 4, 0); }
                        if (!viable) continue;

                        if (taigaOnly) {
                            VPROF_SCOPE(VZ_BIOME_FILTER);
                            Biome* b = tg->getBiomeSource()->getBiomeForNoiseGen(
                                (sp.x << 2) + 2, 0, (sp.z << 2) + 2);
                            if (!b || b->getType() != Biome::Type::TAIGA) continue;
                        }

                        ChunkRand rand;
                        VillageGenerator vg;
                        if (!vg.generate(tg.get(), sp.x, sp.z, rand, nullptr, true, false)) continue;
                        villages.fetch_add(1, std::memory_order_relaxed);
                        pieces.fetch_add(vg.getPieces().size(), std::memory_order_relaxed);
                    }
                    freeLayerCaches(&g);
                }
                SurfaceGenWrapper::setHeightProvider(nullptr);
            });
        }
        for (auto& th : pool) th.join();
    }

    double wallMs = std::chrono::duration<double, std::milli>(Clock::now() - tStart).count();

    const long v = villages.load();
    printf("villages : %ld   pièces : %llu   temps total : %.1f ms  (%.0f villages/s)\n",
           v, (unsigned long long)pieces.load(), wallMs,
           wallMs > 0 ? v * 1000.0 / wallMs : 0.0);
    vprofReport(wallMs, nThreads);

    return 0;
}
