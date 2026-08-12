/**
 * bench_village.cpp — débit de génération de villages, backend hauteurs au choix.
 *
 * Un seul binaire pour les deux jobs : le backend est un paramètre, pas une
 * option de compilation. C'est volontaire — comparer un binaire mingw à un
 * binaire MSVC mesurerait surtout la différence entre les deux compilateurs.
 *
 * Usage : bench_village.exe [--cuda|--c] [--seed N] [--count N] [--quiet]
 *
 * L'énumération des villages est déterministe et identique quel que soit le
 * backend : à partir de --seed, on parcourt les positions de village de la
 * structure seed puis les world seeds, jusqu'à --count villages générés.
 * Le checksum imprimé à la fin couvre toutes les pièces de tous les villages :
 * si les deux jobs affichent le même, ils ont produit exactement les mêmes
 * villages et la comparaison de temps est valable.
 */

#include "cuda_height_provider.hpp"

#include "../VillageGenerator.hpp"
#include "../TerrainGenerator.hpp"
#include "../BiomeSource.hpp"
#include "../ChunkRand.hpp"
#include "../SurfaceGenWrapper.hpp"

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

static inline void fnv(uint64_t& h, uint64_t v) {
    h ^= v; h *= 1099511628211ULL;
}
static inline void fnvStr(uint64_t& h, const std::string& s) {
    for (unsigned char c : s) fnv(h, c);
}

int main(int argc, char** argv)
{
    bool useCuda     = false;
    uint64_t seed    = 1;
    long targetCount = 10000;
    bool quiet       = false;

    for (int i = 1; i < argc; i++) {
        if      (!strcmp(argv[i], "--cuda"))  useCuda = true;
        else if (!strcmp(argv[i], "--c"))     useCuda = false;
        else if (!strcmp(argv[i], "--quiet")) quiet = true;
        else if (!strcmp(argv[i], "--seed")  && i + 1 < argc) seed = strtoull(argv[++i], nullptr, 10);
        else if (!strcmp(argv[i], "--count") && i + 1 < argc) targetCount = strtol(argv[++i], nullptr, 10);
        else { fprintf(stderr, "argument inconnu : %s\n", argv[i]); return 2; }
    }

    printf("=== Benchmark génération de villages ===\n");
    printf("backend  : %s\n", useCuda ? "CUDA (hauteurs sur GPU)" : "C (hauteurs sur CPU)");
    printf("seed     : %llu\n", (unsigned long long)seed);
    printf("villages : %ld\n", targetCount);

    {
        const char* env = getenv("CUBIOMES_LAYER_CACHE");
        if (!env || env[0] != '0')
            printf("\nATTENTION : CUBIOMES_LAYER_CACHE n'est pas à 0. Le cache de layer de\n"
                   "  cubiomes fausse les biomes des requêtes 1x1, les deux backends ne\n"
                   "  produiront pas les mêmes villages et les checksums différeront.\n"
                   "  Voir c/test_layer_cache_consistency.c\n");
    }
    printf("\n");

    // Le provider est installé avant toute mesure ; le premier appel CUDA du
    // processus initialise le contexte du driver (~100 ms), qui n'a rien à faire
    // dans le chiffre final.
    CudaHeightProvider provider;
    if (useCuda) {
        SurfaceGenWrapper::setHeightProvider(&provider);
        auto t0 = Clock::now();
        SurfaceGenWrapper warm(seed, 19);
        warm.setStartSizeYExact(120);
        warm.prefetchRegion(0, 0, 194, 194);
        printf("préchauffage CUDA : %.1f ms (hors mesure)\n\n",
               std::chrono::duration<double, std::milli>(Clock::now() - t0).count());
        provider.resetStats();
    }

    SurfaceGenWrapper::resetStats();

    long villages = 0;
    uint64_t pieces = 0;
    uint64_t checksum = 1469598103934665603ULL;
    long attempted = 0;
    auto tStart = Clock::now();
    auto tLastReport = tStart;

    // Positions de village de la structure seed : fixées une fois, réutilisées
    // pour chaque world seed.
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
    if (posList.empty()) {
        fprintf(stderr, "aucune position de village pour cette seed\n");
        return 1;
    }

    for (uint64_t ws = 0; villages < targetCount; ws++) {
        uint64_t worldSeed = (seed & MASK48) | (ws << 48);

        Generator g;
        setupGenerator(&g, MC_1_16, 0);
        applySeed(&g, DIM_OVERWORLD, worldSeed);
        auto bs = std::make_unique<SimpleBiomeSource>(worldSeed);
        auto tg = std::make_unique<OverworldTerrainGenerator>(worldSeed, std::move(bs));

        for (const Pos& sp : posList) {
            if (villages >= targetCount) break;
            attempted++;
            if (!isViableStructurePos(Village, &g, sp.x << 4, sp.z << 4, 0)) continue;

            ChunkRand rand;
            VillageGenerator vg;
            if (!vg.generate(tg.get(), sp.x, sp.z, rand, nullptr, true, false)) continue;

            villages++;
            for (const auto& p : vg.getPieces()) {
                pieces++;
                fnvStr(checksum, p->name);
                fnv(checksum, (uint64_t)(uint32_t)p->pos.x);
                fnv(checksum, (uint64_t)(uint32_t)p->pos.y);
                fnv(checksum, (uint64_t)(uint32_t)p->pos.z);
                fnv(checksum, (uint64_t)(uint32_t)p->rotation);
                fnv(checksum, (uint64_t)(uint32_t)p->box.minX);
                fnv(checksum, (uint64_t)(uint32_t)p->box.minY);
                fnv(checksum, (uint64_t)(uint32_t)p->box.minZ);
                fnv(checksum, (uint64_t)(uint32_t)p->box.maxX);
                fnv(checksum, (uint64_t)(uint32_t)p->box.maxY);
                fnv(checksum, (uint64_t)(uint32_t)p->box.maxZ);
            }

            if (!quiet) {
                auto now = Clock::now();
                if (std::chrono::duration<double>(now - tLastReport).count() >= 5.0) {
                    double el = std::chrono::duration<double>(now - tStart).count();
                    printf("  ... %ld / %ld villages  (%.0f villages/s, %.0f s restantes)\n",
                           villages, targetCount, villages / el,
                           villages ? el * (targetCount - villages) / villages : 0.0);
                    fflush(stdout);
                    tLastReport = now;
                }
            }
        }
        freeLayerCaches(&g);
    }

    double totalMs = std::chrono::duration<double, std::milli>(Clock::now() - tStart).count();
    auto st = SurfaceGenWrapper::getStats();
    double heightMs = st.columnNanos / 1e6 + (useCuda ? provider.prefetchMs() : 0.0);

    printf("\n--- Résultat (%s) ---\n", useCuda ? "CUDA" : "C");
    printf("  villages générés      : %ld  (%ld positions testées)\n", villages, attempted);
    printf("  pièces                : %llu\n", (unsigned long long)pieces);
    printf("  temps total           : %.2f s\n", totalMs / 1000.0);
    printf("  par village           : %.3f ms\n", villages ? totalMs / villages : 0.0);
    printf("  débit                 : %.0f villages/s\n", totalMs > 0 ? villages * 1000.0 / totalMs : 0.0);
    printf("  coût des hauteurs     : %.2f s  (%.1f %% du total)\n",
           heightMs / 1000.0, totalMs > 0 ? 100.0 * heightMs / totalMs : 0.0);
    if (useCuda)
        printf("     dont pré-calcul GPU : %.2f s sur %d appels (%.2f ms chacun)\n",
               provider.prefetchMs() / 1000.0, provider.prefetchCount(),
               provider.prefetchCount() ? provider.prefetchMs() / provider.prefetchCount() : 0.0);
    printf("  checksum des pièces   : %016llx\n", (unsigned long long)checksum);
    printf("\n  (les deux backends doivent afficher le même checksum)\n");

    SurfaceGenWrapper::setHeightProvider(nullptr);
    return 0;
}
