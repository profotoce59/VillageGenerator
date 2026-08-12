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
#include <memory>
#include <vector>

using Clock = std::chrono::steady_clock;

int main(int argc, char** argv)
{
    bool useCuda  = true;
    uint64_t seed = 1;
    long count    = 300;

    for (int i = 1; i < argc; i++) {
        if      (!strcmp(argv[i], "--cuda")) useCuda = true;
        else if (!strcmp(argv[i], "--c"))    useCuda = false;
        else if (!strcmp(argv[i], "--seed")  && i+1 < argc) seed  = strtoull(argv[++i], nullptr, 10);
        else if (!strcmp(argv[i], "--count") && i+1 < argc) count = strtol(argv[++i], nullptr, 10);
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

    CudaHeightProvider provider;
    if (useCuda) {
        SurfaceGenWrapper::setHeightProvider(&provider);
        SurfaceGenWrapper warm(seed, 19);
        warm.setStartSizeYExact(120);
        warm.prefetchRegion(0, 0, 194, 194);
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

    vprofReset();
    long villages = 0;
    uint64_t pieces = 0;
    auto tStart = Clock::now();

    for (uint64_t ws = 0; villages < count; ws++) {
        uint64_t worldSeed = (seed & MASK48) | (ws << 48);

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
            if (villages >= count) break;

            bool viable;
            { VPROF_SCOPE(VZ_VIABLE);
              viable = isViableStructurePos(Village, &g, sp.x << 4, sp.z << 4, 0); }
            if (!viable) continue;

            ChunkRand rand;
            VillageGenerator vg;
            if (!vg.generate(tg.get(), sp.x, sp.z, rand, nullptr, true, false)) continue;
            villages++;
            pieces += vg.getPieces().size();
        }
        freeLayerCaches(&g);
    }

    double wallMs = std::chrono::duration<double, std::milli>(Clock::now() - tStart).count();

    printf("villages : %ld   pièces : %llu   temps total : %.1f ms  (%.2f ms/village)\n",
           villages, (unsigned long long)pieces, wallMs, villages ? wallMs / villages : 0.0);
    vprofReport(wallMs);

    SurfaceGenWrapper::setHeightProvider(nullptr);
    return 0;
}
