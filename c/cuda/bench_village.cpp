/**
 * bench_village.cpp — débit de génération de villages, backend hauteurs au choix.
 *
 * Un seul binaire pour les deux jobs : le backend est un paramètre, pas une
 * option de compilation. C'est volontaire — comparer un binaire mingw à un
 * binaire MSVC mesurerait surtout la différence entre les deux compilateurs.
 *
 * Usage : bench_village.exe [--cuda|--c] [--seed N] [--worlds N] [--threads N] [--quiet]
 *
 * Le travail est défini par un ENSEMBLE de world seeds (0..worlds-1 pour la
 * structure seed donnée), pas par un nombre de villages : ainsi l'ensemble des
 * villages produits est identique quel que soit le nombre de threads, et seul
 * l'ordre change. Le checksum est donc commutatif (somme de checksums par
 * village) pour rester comparable entre 1 et N threads.
 *
 * Chaque thread possède son propre CudaHeightProvider : le contexte CUDA et la
 * zone pré-calculée ne sont pas partageables.
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

#include <atomic>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <chrono>
#include <memory>
#include <mutex>
#include <thread>
#include <vector>

using Clock = std::chrono::steady_clock;

static inline void fnv(uint64_t& h, uint64_t v) {
    h ^= v; h *= 1099511628211ULL;
}
static inline void fnvStr(uint64_t& h, const std::string& s) {
    for (unsigned char c : s) fnv(h, c);
}

struct ThreadResult {
    long     villages = 0;
    uint64_t pieces   = 0;
    uint64_t checksum = 0;   // somme des checksums par village (commutative)
    long     attempted = 0;
    // temps GPU cumulés du provider de ce thread
    double   prefetchWallMs = 0.0;   // vu depuis l'hôte (lancement + attente)
    double   gpuKernelsMs   = 0.0;   // temps GPU réel (événements CUDA)
    int      prefetchCount  = 0;
};

int main(int argc, char** argv)
{
    bool useCuda   = false;
    uint64_t seed  = 1;
    long worlds    = 520;      // ~10 000 villages pour la seed 1
    int  nThreads  = 1;
    bool quiet     = false;

    for (int i = 1; i < argc; i++) {
        if      (!strcmp(argv[i], "--cuda"))  useCuda = true;
        else if (!strcmp(argv[i], "--c"))     useCuda = false;
        else if (!strcmp(argv[i], "--quiet")) quiet = true;
        else if (!strcmp(argv[i], "--seed")    && i + 1 < argc) seed     = strtoull(argv[++i], nullptr, 10);
        else if (!strcmp(argv[i], "--worlds")  && i + 1 < argc) worlds   = strtol(argv[++i], nullptr, 10);
        else if (!strcmp(argv[i], "--threads") && i + 1 < argc) nThreads = atoi(argv[++i]);
        else { fprintf(stderr, "argument inconnu : %s\n", argv[i]); return 2; }
    }
    if (nThreads < 1) nThreads = 1;
    if (worlds   < 1) worlds   = 1;

    printf("=== Benchmark génération de villages ===\n");
    printf("backend    : %s\n", useCuda ? "CUDA (hauteurs sur GPU)" : "C (hauteurs sur CPU)");
    printf("seed       : %llu\n", (unsigned long long)seed);
    printf("world seeds: %ld\n", worlds);
    printf("threads    : %d\n", nThreads);

    {
        const char* env = getenv("CUBIOMES_LAYER_CACHE");
        if (!env || env[0] != '0')
            printf("\nATTENTION : CUBIOMES_LAYER_CACHE n'est pas à 0. Le cache de layer de\n"
                   "  cubiomes fausse les biomes des requêtes 1x1, les deux backends ne\n"
                   "  produiront pas les mêmes villages et les checksums différeront.\n"
                   "  Voir c/test_layer_cache_consistency.c\n");
    }
    printf("\n");

    // Positions de village de la structure seed : identiques pour tous les
    // world seeds et tous les threads, calculées une fois.
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

    // Préchauffage CUDA hors mesure : le premier appel du processus initialise
    // le contexte du driver (~100 ms). Les contextes par thread créés ensuite
    // sont bien moins coûteux.
    if (useCuda) {
        auto t0 = Clock::now();
        CudaHeightProvider warmProvider;
        SurfaceGenWrapper::setHeightProvider(&warmProvider);
        SurfaceGenWrapper warm(seed, 19);
        warm.setStartSizeYExact(120);
        warm.prefetchRegion(0, 0, 194, 194);
        SurfaceGenWrapper::setHeightProvider(nullptr);
        printf("préchauffage CUDA : %.1f ms (hors mesure)\n\n",
               std::chrono::duration<double, std::milli>(Clock::now() - t0).count());
    }

    SurfaceGenWrapper::resetStats();

    std::vector<ThreadResult> results(nThreads);
    std::vector<std::thread>  pool;
    std::atomic<long>         doneWorlds{0};
    auto tStart = Clock::now();

    for (int t = 0; t < nThreads; t++) {
        pool.emplace_back([&, t]() {
            // Un provider (donc un contexte CUDA) par thread.
            std::unique_ptr<CudaHeightProvider> provider;
            if (useCuda) {
                provider = std::make_unique<CudaHeightProvider>();
                SurfaceGenWrapper::setHeightProvider(provider.get());
            }
            ThreadResult& r = results[t];

            // Répartition par pas : l'ensemble des world seeds traitées est le
            // même quel que soit nThreads.
            for (long ws = t; ws < worlds; ws += nThreads) {
                uint64_t worldSeed = (seed & MASK48) | ((uint64_t)ws << 48);

                Generator g;
                setupGenerator(&g, MC_1_16, 0);
                applySeed(&g, DIM_OVERWORLD, worldSeed);
                auto bs = std::make_unique<SimpleBiomeSource>(worldSeed);
                auto tg = std::make_unique<OverworldTerrainGenerator>(worldSeed, std::move(bs));

                for (const Pos& sp : posList) {
                    r.attempted++;
                    if (!isViableStructurePos(Village, &g, sp.x << 4, sp.z << 4, 0)) continue;

                    ChunkRand rand;
                    VillageGenerator vg;
                    if (!vg.generate(tg.get(), sp.x, sp.z, rand, nullptr, true, false)) continue;

                    r.villages++;
                    uint64_t vh = 1469598103934665603ULL;
                    for (const auto& p : vg.getPieces()) {
                        r.pieces++;
                        fnvStr(vh, p->name);
                        fnv(vh, (uint64_t)(uint32_t)p->pos.x);
                        fnv(vh, (uint64_t)(uint32_t)p->pos.y);
                        fnv(vh, (uint64_t)(uint32_t)p->pos.z);
                        fnv(vh, (uint64_t)(uint32_t)p->rotation);
                        fnv(vh, (uint64_t)(uint32_t)p->box.minX);
                        fnv(vh, (uint64_t)(uint32_t)p->box.minY);
                        fnv(vh, (uint64_t)(uint32_t)p->box.minZ);
                        fnv(vh, (uint64_t)(uint32_t)p->box.maxX);
                        fnv(vh, (uint64_t)(uint32_t)p->box.maxY);
                        fnv(vh, (uint64_t)(uint32_t)p->box.maxZ);
                    }
                    r.checksum += vh;   // somme : indépendante de l'ordre
                }
                freeLayerCaches(&g);

                long done = ++doneWorlds;
                if (!quiet && t == 0 && (done % 50) == 0) {
                    double el = std::chrono::duration<double>(Clock::now() - tStart).count();
                    printf("  ... %ld / %ld world seeds  (%.0f s écoulées)\n", done, worlds, el);
                    fflush(stdout);
                }
            }
            if (provider) {
                r.prefetchWallMs = provider->prefetchMs();
                r.gpuKernelsMs   = provider->gpuTotalMs();
                r.prefetchCount  = provider->prefetchCount();
            }
            SurfaceGenWrapper::setHeightProvider(nullptr);
        });
    }
    for (auto& th : pool) th.join();

    double totalMs = std::chrono::duration<double, std::milli>(Clock::now() - tStart).count();

    ThreadResult tot;
    for (const auto& r : results) {
        tot.villages       += r.villages;
        tot.pieces         += r.pieces;
        tot.checksum       += r.checksum;
        tot.attempted      += r.attempted;
        tot.prefetchWallMs += r.prefetchWallMs;
        tot.gpuKernelsMs   += r.gpuKernelsMs;
        tot.prefetchCount  += r.prefetchCount;
    }
    auto st = SurfaceGenWrapper::getStats();

    printf("\n--- Résultat (%s, %d thread%s) ---\n",
           useCuda ? "CUDA" : "C", nThreads, nThreads > 1 ? "s" : "");
    printf("  villages générés      : %ld  (%ld positions testées)\n", tot.villages, tot.attempted);
    printf("  pièces                : %llu\n", (unsigned long long)tot.pieces);
    printf("  temps total           : %.2f s\n", totalMs / 1000.0);
    printf("  par village           : %.3f ms\n", tot.villages ? totalMs / tot.villages : 0.0);
    printf("  débit                 : %.0f villages/s\n",
           totalMs > 0 ? tot.villages * 1000.0 / totalMs : 0.0);
    printf("  hauteurs (cumul threads) : %.2f s de temps CPU\n", st.columnNanos / 1e9);
    if (useCuda && tot.prefetchCount > 0) {
        // Le GPU est un unique matériel partagé : comparer le temps de kernels
        // cumulé au temps mural donne son taux d'occupation réel. S'il est bas
        // alors qu'on plafonne, le mur est le surcoût de lancement, pas le calcul.
        printf("  prefetch : %d lancements, %.2f s d'attente hôte (cumul threads)\n",
               tot.prefetchCount, tot.prefetchWallMs / 1000.0);
        printf("     kernels GPU réels     : %.2f s  -> GPU occupé à %.0f %% du temps mural\n",
               tot.gpuKernelsMs / 1000.0,
               totalMs > 0 ? 100.0 * tot.gpuKernelsMs / totalMs : 0.0);
        printf("     par lancement         : %.3f ms mural / %.3f ms GPU  (surcoût %.3f ms)\n",
               tot.prefetchWallMs / tot.prefetchCount,
               tot.gpuKernelsMs / tot.prefetchCount,
               (tot.prefetchWallMs - tot.gpuKernelsMs) / tot.prefetchCount);
    }
    printf("  checksum des pièces   : %016llx\n", (unsigned long long)tot.checksum);
    printf("\n  (checksum commutatif : identique quels que soient le backend et le nombre de threads)\n");
    return 0;
}
