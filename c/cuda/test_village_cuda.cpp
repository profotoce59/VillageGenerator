/**
 * test_village_cuda.cpp — génération de village : C seul vs C + hauteurs CUDA.
 *
 * Chaque village est généré deux fois avec exactement le même code
 * (VillageGenerator / Assembler), la seule différence étant qu'un
 * CudaHeightProvider est installé ou non. On compare ensuite la liste de pièces
 * champ par champ : nom, position, rotation, boîte, profondeur, comportement.
 *
 * Run: cuda/test_village_cuda.exe [structureSeedDepart] [nbSeeds] [nbWorldSeeds]
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
#include <chrono>
#include <memory>
#include <string>
#include <vector>

using Clock = std::chrono::steady_clock;

// Copie plate d'une pièce, pour comparer sans garder le générateur en vie.
struct PieceSnapshot {
    std::string name;
    int px, py, pz;
    int rotation;
    int minX, minY, minZ, maxX, maxY, maxZ;
    int depth;
    int behaviour;

    bool operator!=(const PieceSnapshot& o) const {
        return name != o.name || px != o.px || py != o.py || pz != o.pz ||
               rotation != o.rotation || depth != o.depth || behaviour != o.behaviour ||
               minX != o.minX || minY != o.minY || minZ != o.minZ ||
               maxX != o.maxX || maxY != o.maxY || maxZ != o.maxZ;
    }
    std::string describe() const {
        char buf[512];
        snprintf(buf, sizeof(buf),
                 "%s pos=(%d,%d,%d) rot=%d box=(%d,%d,%d)-(%d,%d,%d) depth=%d beh=%d",
                 name.c_str(), px, py, pz, rotation,
                 minX, minY, minZ, maxX, maxY, maxZ, depth, behaviour);
        return buf;
    }
};

static std::vector<PieceSnapshot> snapshot(const VillageGenerator& vg)
{
    std::vector<PieceSnapshot> out;
    out.reserve(vg.getPieces().size());
    for (const auto& p : vg.getPieces()) {
        PieceSnapshot s;
        s.name = p->name;
        s.px = p->pos.x; s.py = p->pos.y; s.pz = p->pos.z;
        s.rotation = (int)p->rotation;
        s.minX = p->box.minX; s.minY = p->box.minY; s.minZ = p->box.minZ;
        s.maxX = p->box.maxX; s.maxY = p->box.maxY; s.maxZ = p->box.maxZ;
        s.depth = p->depth;
        s.behaviour = (int)p->placementBehaviour;
        out.push_back(std::move(s));
    }
    return out;
}

struct RunResult {
    std::vector<std::vector<PieceSnapshot>> villages;
    std::vector<std::string> labels;      // "structureSeed@chunkX,chunkZ"
    double totalMs = 0.0;
    double heightMs = 0.0;
    uint64_t queries = 0;
    uint64_t providerHits = 0, providerMisses = 0;
};

// Génère tous les villages du lot. Le code exécuté est identique dans les deux
// runs ; seule l'installation du provider change.
static RunResult runAll(uint64_t startSeed, int nbSeeds, int nbWorldSeeds)
{
    RunResult r;
    SurfaceGenWrapper::resetStats();

    for (int s = 0; s < nbSeeds; s++) {
        uint64_t structureSeed = (startSeed + s) & MASK48;

        std::vector<Pos> posList;
        for (int rx = 0; rx < 2; rx++) for (int rz = 0; rz < 2; rz++) {
            Pos p;
            if (getStructurePos(Village, MC_1_16, structureSeed, rx, rz, &p)) {
                Pos c; c.x = p.x >> 4; c.z = p.z >> 4; posList.push_back(c);
            }
        }

        for (int ws = 0; ws < nbWorldSeeds; ws++) {
            uint64_t worldSeed = structureSeed | ((uint64_t)ws << 48);

            Generator g;
            setupGenerator(&g, MC_1_16, 0);
            applySeed(&g, DIM_OVERWORLD, worldSeed);
            auto bs = std::make_unique<SimpleBiomeSource>(worldSeed);
            auto tg = std::make_unique<OverworldTerrainGenerator>(worldSeed, std::move(bs));

            for (const Pos& sp : posList) {
                if (!isViableStructurePos(Village, &g, sp.x << 4, sp.z << 4, 0)) continue;

                ChunkRand rand;
                VillageGenerator vg;
                auto t0 = Clock::now();
                bool ok = vg.generate(tg.get(), sp.x, sp.z, rand, nullptr, true, false);
                r.totalMs += std::chrono::duration<double, std::milli>(Clock::now() - t0).count();
                if (!ok) continue;

                r.villages.push_back(snapshot(vg));
                char lbl[128];
                snprintf(lbl, sizeof(lbl), "%llu/%llu@%d,%d",
                         (unsigned long long)structureSeed, (unsigned long long)worldSeed,
                         sp.x, sp.z);
                r.labels.push_back(lbl);
            }
            freeLayerCaches(&g);
        }
    }

    auto st = SurfaceGenWrapper::getStats();
    r.heightMs       = st.columnNanos / 1e6;
    r.queries        = st.columnQueries;
    r.providerHits   = st.providerHits;
    r.providerMisses = st.providerMisses;
    return r;
}

int main(int argc, char** argv)
{
    uint64_t startSeed  = (argc > 1) ? strtoull(argv[1], nullptr, 10) : 1ULL;
    int nbSeeds         = (argc > 2) ? atoi(argv[2]) : 40;
    int nbWorldSeeds    = (argc > 3) ? atoi(argv[3]) : 1;
    bool verify         = (argc > 4) ? atoi(argv[4]) != 0 : false;
    // mode 1 : run 2 sans provider — sert à distinguer un bug CUDA d'une
    // non-déterminisme du générateur lui-même.
    bool cpuVsCpu       = (argc > 5) ? atoi(argv[5]) != 0 : false;

    printf("=== Village : C seul vs C + hauteurs CUDA ===\n");
    printf("structureSeeds %llu..%llu, %d worldSeed(s) par structureSeed\n",
           (unsigned long long)startSeed,
           (unsigned long long)(startSeed + nbSeeds - 1), nbWorldSeeds);

    // Le cache de layer de cubiomes renvoie des biomes faux pour les requêtes
    // 1x1 (voir c/test_layer_cache_consistency.c). Les deux runs n'appellent
    // alors pas genBiomes de la même façon et divergent sur quelques villages —
    // ce n'est pas un écart imputable à CUDA.
    {
        const char* env = getenv("CUBIOMES_LAYER_CACHE");
        if (!env || env[0] != '0') {
            printf("\nATTENTION : le cache de layer cubiomes est actif.\n"
                   "  Il fausse les biomes des requêtes 1x1 et fait diverger quelques\n"
                   "  villages indépendamment de CUDA. Relancer avec CUBIOMES_LAYER_CACHE=0\n"
                   "  pour une comparaison valable (cf. c/test_layer_cache_consistency.c).\n");
        }
    }
    printf("\n");

    // ---- Run 1 : CPU seul ----
    SurfaceGenWrapper::setHeightProvider(nullptr);
    printf("Run CPU...\n");
    if (verify) SurfaceGenWrapper::setQueryTrace("trace_cpu.txt");
    RunResult cpu = runAll(startSeed, nbSeeds, nbWorldSeeds);
    SurfaceGenWrapper::setQueryTrace(nullptr);

    // ---- Run 2 : hauteurs sur GPU ----
    CudaHeightProvider provider;
    if (cpuVsCpu) printf("[mode CPU vs CPU : provider desactive pour le run 2]\n");
    else SurfaceGenWrapper::setHeightProvider(&provider);

    // Le tout premier appel CUDA du processus initialise le contexte du driver
    // (~100 ms). Sans ce préchauffage, ce coût unique serait imputé aux villages.
    if (!cpuVsCpu) {
        printf("Préchauffage CUDA...\n");
        auto t0 = Clock::now();
        SurfaceGenWrapper warm(startSeed, 19);
        warm.setStartSizeYExact(120);
        warm.prefetchRegion(0, 0, 194, 194);
        printf("  contexte CUDA prêt en %.1f ms\n",
               std::chrono::duration<double, std::milli>(Clock::now() - t0).count());
        provider.resetStats();
    }

    printf("Run CUDA...\n");
    SurfaceGenWrapper::setVerifyProvider(verify);
    if (verify) SurfaceGenWrapper::setQueryTrace("trace_gpu.txt");
    RunResult gpu = runAll(startSeed, nbSeeds, nbWorldSeeds);
    SurfaceGenWrapper::setQueryTrace(nullptr);
    SurfaceGenWrapper::setVerifyProvider(false);
    SurfaceGenWrapper::setHeightProvider(nullptr);

    // ---- Comparaison des pièces ----
    printf("\n--- Comparaison des pièces ---\n");
    int mismatches = 0;
    size_t totalPieces = 0;

    if (cpu.villages.size() != gpu.villages.size()) {
        printf("  ECHEC : %zu villages côté CPU, %zu côté CUDA\n",
               cpu.villages.size(), gpu.villages.size());
        mismatches++;
    }

    size_t n = std::min(cpu.villages.size(), gpu.villages.size());
    for (size_t v = 0; v < n; v++) {
        const auto& a = cpu.villages[v];
        const auto& b = gpu.villages[v];
        totalPieces += a.size();

        if (a.size() != b.size()) {
            if (mismatches < 10)
                printf("  ECART %s : %zu pièces (CPU) vs %zu (CUDA)\n",
                       cpu.labels[v].c_str(), a.size(), b.size());
            mismatches++;
            continue;
        }
        for (size_t i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                if (mismatches < 10) {
                    printf("  ECART %s pièce %zu\n", cpu.labels[v].c_str(), i);
                    printf("     CPU  : %s\n", a[i].describe().c_str());
                    printf("     CUDA : %s\n", b[i].describe().c_str());
                }
                mismatches++;
            }
        }
    }

    printf("  villages comparés : %zu\n", n);
    printf("  pièces comparées  : %zu\n", totalPieces);
    printf("  écarts            : %d  -> %s\n\n", mismatches,
           mismatches == 0 ? "IDENTIQUE" : "DIFFERENT");

    // ---- Temps ----
    // Le coût des hauteurs côté CUDA, c'est le temps passé dans
    // generateColumnFromY PLUS le pré-calcul de la zone, qui a lieu en dehors.
    const double gpuHeightTotal = gpu.heightMs + provider.prefetchMs();

    printf("--- Temps ---\n");
    printf("  %-30s %12s %12s %9s\n", "", "CPU", "CUDA", "gain");
    printf("  %-30s %10.1f ms %10.1f ms %8.2fx\n", "génération totale",
           cpu.totalMs, gpu.totalMs, gpu.totalMs > 0 ? cpu.totalMs / gpu.totalMs : 0.0);
    printf("  %-30s %10.1f ms %10.1f ms %8.2fx\n", "coût total des hauteurs",
           cpu.heightMs, gpuHeightTotal,
           gpuHeightTotal > 0 ? cpu.heightMs / gpuHeightTotal : 0.0);
    printf("  %-30s %10.1f ms %10.1f ms\n", "   dans generateColumnFromY",
           cpu.heightMs, gpu.heightMs);
    printf("  %-30s %10s    %10.1f ms\n", "   pré-calcul de zone", "-",
           provider.prefetchMs());
    printf("  %-30s %10.1f %% %10.1f %%\n", "part des hauteurs",
           cpu.totalMs > 0 ? 100.0 * cpu.heightMs / cpu.totalMs : 0.0,
           gpu.totalMs > 0 ? 100.0 * gpuHeightTotal / gpu.totalMs : 0.0);
    if (n > 0)
        printf("  %-30s %10.2f ms %10.2f ms\n", "par village",
               cpu.totalMs / n, gpu.totalMs / n);

    printf("\n--- Provider CUDA ---\n");
    printf("  requêtes de hauteur      : %llu\n", (unsigned long long)gpu.queries);
    printf("  servies par le GPU       : %llu (%.1f %%)\n",
           (unsigned long long)gpu.providerHits,
           gpu.queries ? 100.0 * gpu.providerHits / gpu.queries : 0.0);
    printf("  hors zone (repli sur C)  : %llu\n", (unsigned long long)gpu.providerMisses);
    printf("  pré-calculs              : %d  (moy %.2f ms, min %.2f, max %.2f)\n",
           provider.prefetchCount(),
           provider.prefetchCount() ? provider.prefetchMs() / provider.prefetchCount() : 0.0,
           provider.prefetchMinMs(), provider.prefetchMaxMs());
    printf("  points calculés          : %lld  (%.0f par requête utile)\n",
           provider.pointsComputed(),
           gpu.providerHits ? (double)provider.pointsComputed() / gpu.providerHits : 0.0);

    printf("\n=== Résultat ===\n");
    if (mismatches == 0)
        printf("SUCCES : les villages générés avec les hauteurs CUDA sont identiques au C.\n");
    else
        printf("ECHEC : %d écarts.\n", mismatches);
    return mismatches == 0 ? 0 : 1;
}
