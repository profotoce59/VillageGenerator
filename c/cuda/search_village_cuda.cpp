/**
 * search_village_cuda.cpp — recherche de villages à forte densité de forgerons,
 * hauteurs calculées sur GPU.
 *
 * Part d'une structure seed aléatoire (imprimée pour pouvoir rejouer), parcourt
 * les seeds, et journalise chaque village dépassant le seuil de forgerons.
 *
 * Usage :
 *   search_village_cuda.exe [options]
 *     --seed N        structure seed de départ (défaut : aléatoire)
 *     --smiths N      seuil : journalise si forgerons >= N (défaut 6, soit "plus de 5")
 *     --pieces N      journalise aussi si pièces >= N (défaut 250, 0 pour désactiver)
 *     --worlds N      world seeds testées par structure seed (défaut 32)
 *     --regions N     grille de régions NxN pour les positions (défaut 10 -> 100 positions)
 *     --max-seeds N   arrêt après N structure seeds (défaut 0 = sans fin)
 *     --out FICHIER   journalise aussi dans ce fichier (ajout en fin)
 *     --index I --threads T   partitionnement pour lancer plusieurs processus
 *     --cpu           hauteurs sur CPU (pour comparer les débits)
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
#include <cstdarg>
#include <chrono>
#include <memory>
#include <random>
#include <string>
#include <vector>

using Clock = std::chrono::steady_clock;

// Forgerons comptés, identiques au filtre de test_village_generation.cpp.
//
// Les pools contiennent trois autres bâtiments de type forgeron d'armes —
// savanna_weaponsmith_1, taiga_weaponsmith_2 et snowy/houses/snowy_weapon_smith_1
// — qui sont VOLONTAIREMENT exclus. Ne pas les ajouter en croyant corriger un
// oubli. (Les tool_smith et armorer ne comptent pas non plus.)
static const char* const WEAPONSMITHS[] = {
    "plains/houses/plains_weaponsmith_1",
    "desert/houses/desert_weaponsmith_1",
    "savanna/houses/savanna_weaponsmith_2",
    "taiga/houses/taiga_weaponsmith_1",
};
static const int NUM_WEAPONSMITHS = (int)(sizeof(WEAPONSMITHS) / sizeof(*WEAPONSMITHS));

static bool isWeaponsmith(const std::string& name)
{
    for (int i = 0; i < NUM_WEAPONSMITHS; i++)
        if (name == WEAPONSMITHS[i]) return true;
    return false;
}

static uint64_t randomStructureSeed()
{
    std::random_device rd;
    uint64_t s = ((uint64_t)rd() << 32) ^ (uint64_t)rd();
    s ^= (uint64_t)std::chrono::high_resolution_clock::now().time_since_epoch().count();
    return s & MASK48;
}

struct Logger {
    FILE* f = nullptr;
    void open(const char* path) {
        if (!path) return;
        f = fopen(path, "a");
        if (!f) fprintf(stderr, "impossible d'ouvrir %s en écriture\n", path);
    }
    void close() { if (f) { fclose(f); f = nullptr; } }
    void line(const char* fmt, ...) {
        va_list ap;
        va_start(ap, fmt); vprintf(fmt, ap); va_end(ap);
        if (f) { va_start(ap, fmt); vfprintf(f, fmt, ap); va_end(ap); fflush(f); }
    }
};

int main(int argc, char** argv)
{
    uint64_t startSeed  = 0;
    bool     seedGiven  = false;
    int      smithMin   = 6;        // "plus de 5"
    int      pieceMin   = 250;
    int      worlds     = 32;
    int      regions    = 10;
    long     maxSeeds   = 0;        // 0 = sans fin
    const char* outPath = nullptr;
    int      index      = 0;
    int      threads    = 1;
    bool     useCuda    = true;

    for (int i = 1; i < argc; i++) {
        if      (!strcmp(argv[i], "--cpu")) useCuda = false;
        else if (!strcmp(argv[i], "--seed")      && i+1 < argc) { startSeed = strtoull(argv[++i], nullptr, 10) & MASK48; seedGiven = true; }
        else if (!strcmp(argv[i], "--smiths")    && i+1 < argc) smithMin = atoi(argv[++i]);
        else if (!strcmp(argv[i], "--pieces")    && i+1 < argc) pieceMin = atoi(argv[++i]);
        else if (!strcmp(argv[i], "--worlds")    && i+1 < argc) worlds   = atoi(argv[++i]);
        else if (!strcmp(argv[i], "--regions")   && i+1 < argc) regions  = atoi(argv[++i]);
        else if (!strcmp(argv[i], "--max-seeds") && i+1 < argc) maxSeeds = strtol(argv[++i], nullptr, 10);
        else if (!strcmp(argv[i], "--out")       && i+1 < argc) outPath  = argv[++i];
        else if (!strcmp(argv[i], "--index")     && i+1 < argc) index    = atoi(argv[++i]);
        else if (!strcmp(argv[i], "--threads")   && i+1 < argc) threads  = atoi(argv[++i]);
        else { fprintf(stderr, "argument inconnu : %s\n", argv[i]); return 2; }
    }
    if (threads < 1) threads = 1;
    if (!seedGiven) startSeed = randomStructureSeed();

    Logger log;
    log.open(outPath);

    log.line("=== Recherche de villages (%s) ===\n", useCuda ? "hauteurs CUDA" : "hauteurs CPU");
    log.line("structure seed de depart : %llu%s\n",
             (unsigned long long)startSeed, seedGiven ? "" : "  (aleatoire)");
    log.line("critere : >= %d forgerons", smithMin);
    if (pieceMin > 0) log.line("  ou >= %d pieces", pieceMin);
    log.line("\nworld seeds/structure : %d,  positions : %dx%d\n", worlds, regions, regions);
    if (threads > 1) log.line("partition %d/%d\n", index, threads);
    log.line("forgerons comptes : %d noms\n", NUM_WEAPONSMITHS);

    {
        const char* env = getenv("CUBIOMES_LAYER_CACHE");
        if (!env || env[0] != '0')
            log.line("\nATTENTION : CUBIOMES_LAYER_CACHE n'est pas a 0. Le cache de layer de\n"
                     "  cubiomes renvoie des biomes faux pour les requetes 1x1, les resultats\n"
                     "  de la recherche ne sont pas fiables. Voir c/test_layer_cache_consistency.c\n");
    }
    log.line("\n");

    CudaHeightProvider provider;
    if (useCuda) {
        SurfaceGenWrapper::setHeightProvider(&provider);
        SurfaceGenWrapper warm(startSeed, 19);
        warm.setStartSizeYExact(120);
        warm.prefetchRegion(0, 0, 194, 194);
        provider.resetStats();
    }

    long     seedsDone  = 0;
    uint64_t villages   = 0;
    uint64_t hits       = 0;
    auto tStart = Clock::now();
    auto tLast  = tStart;
    uint64_t lastVillages = 0;
    long     lastSeeds = 0;

    for (uint64_t structureSeed = (startSeed + (uint64_t)index) & MASK48;
         maxSeeds == 0 || seedsDone < maxSeeds;
         structureSeed = (structureSeed + (uint64_t)threads) & MASK48)
    {
        std::vector<Pos> posList;
        for (int rx = 0; rx < regions; rx++) {
            for (int rz = 0; rz < regions; rz++) {
                Pos p;
                if (getStructurePos(Village, MC_1_16, structureSeed, rx, rz, &p)) {
                    Pos c; c.x = p.x >> 4; c.z = p.z >> 4;
                    posList.push_back(c);
                }
            }
        }

        for (int ws = 0; ws < worlds; ws++) {
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
                if (!vg.generate(tg.get(), sp.x, sp.z, rand, nullptr, true, false)) continue;

                villages++;
                const auto& pieces = vg.getPieces();
                int smiths = 0;
                for (const auto& p : pieces)
                    if (isWeaponsmith(p->name)) smiths++;

                bool interesting = (smiths >= smithMin) ||
                                   (pieceMin > 0 && (int)pieces.size() >= pieceMin);
                if (!interesting) continue;

                hits++;
                // Type de village : préfixe de la première pièce ("plains/...").
                std::string type = pieces.empty() ? "?" : pieces[0]->name;
                size_t slash = type.find('/');
                if (slash != std::string::npos) type = type.substr(0, slash);

                double el = std::chrono::duration<double>(Clock::now() - tStart).count();
                log.line("[%.0fs] TROUVE  structureSeed=%llu worldSeed=%llu "
                         "chunk=(%d,%d) bloc=(%d,%d) type=%s pieces=%zu forgerons=%d\n",
                         el,
                         (unsigned long long)structureSeed, (unsigned long long)worldSeed,
                         sp.x, sp.z, sp.x << 4, sp.z << 4,
                         type.c_str(), pieces.size(), smiths);
                fflush(stdout);
            }
            freeLayerCaches(&g);
        }

        seedsDone++;

        auto now = Clock::now();
        if (std::chrono::duration<double>(now - tLast).count() >= 30.0) {
            double el    = std::chrono::duration<double>(now - tStart).count();
            double delta = std::chrono::duration<double>(now - tLast).count();
            printf("[%.0fs] seeds=%ld villages=%llu trouves=%llu | "
                   "%.1f seeds/s  %.0f villages/s | seed courante=%llu\n",
                   el, seedsDone, (unsigned long long)villages, (unsigned long long)hits,
                   (seedsDone - lastSeeds) / delta,
                   (villages - lastVillages) / delta,
                   (unsigned long long)structureSeed);
            fflush(stdout);
            tLast = now;
            lastSeeds = seedsDone;
            lastVillages = villages;
        }
    }

    double el = std::chrono::duration<double>(Clock::now() - tStart).count();
    log.line("\nfin : %ld seeds, %llu villages, %llu trouves en %.0f s\n",
             seedsDone, (unsigned long long)villages, (unsigned long long)hits, el);
    log.close();
    SurfaceGenWrapper::setHeightProvider(nullptr);
    return 0;
}
