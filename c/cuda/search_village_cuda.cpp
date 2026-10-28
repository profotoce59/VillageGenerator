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
 *     --threads N     threads de travail (défaut 4)
 *     --biome NOM     taiga (défaut) / plains / desert / savanna / snowy / any
 *     --shard I --shards S   partitionnement pour lancer plusieurs PROCESSUS
 *     --cpu           hauteurs sur CPU (pour comparer les débits)
 *
 * Chaque thread possède son propre CudaHeightProvider (contexte CUDA et zone
 * pré-calculée non partageables) et sa propre tranche de structure seeds.
 * Au-delà de ~6 threads le GPU sature : mesuré ~725 villages/s sur RTX 5070.
 */

#include "cuda_height_provider.hpp"

#include "../VillageGenerator.hpp"
#include "../TerrainGenerator.hpp"
#include "../BiomeSource.hpp"
#include "../Biome.hpp"
#include "../ChunkRand.hpp"
#include "../SurfaceGenWrapper.hpp"

extern "C" {
    #include "finders.h"
}

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdarg>
#include <atomic>
#include <chrono>
#include <mutex>
#include <thread>
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

// Filtre de biome, comme le filterTaiga de test_village_generation.cpp.
// -1 = pas de filtre.
static int parseBiomeFilter(const char* name)
{
    if (!strcmp(name, "any"))     return -1;
    if (!strcmp(name, "taiga"))   return (int)Biome::Type::TAIGA;
    if (!strcmp(name, "plains"))  return (int)Biome::Type::PLAINS;
    if (!strcmp(name, "desert"))  return (int)Biome::Type::DESERT;
    if (!strcmp(name, "savanna")) return (int)Biome::Type::SAVANNA;
    if (!strcmp(name, "snowy"))   return (int)Biome::Type::SNOWY_TUNDRA;
    return -2;   // inconnu
}

static const char* biomeFilterName(int t)
{
    switch ((Biome::Type)t) {
        case Biome::Type::TAIGA:        return "taiga";
        case Biome::Type::PLAINS:       return "plains";
        case Biome::Type::DESERT:       return "desert";
        case Biome::Type::SAVANNA:      return "savanna";
        case Biome::Type::SNOWY_TUNDRA: return "snowy";
        default:                        return "?";
    }
}

static uint64_t randomStructureSeed()
{
    std::random_device rd;
    uint64_t s = ((uint64_t)rd() << 32) ^ (uint64_t)rd();
    s ^= (uint64_t)std::chrono::high_resolution_clock::now().time_since_epoch().count();
    return s & MASK48;
}

// Sérialise les écritures : plusieurs threads journalisent leurs trouvailles.
struct Logger {
    FILE* f = nullptr;
    std::mutex m;
    void open(const char* path) {
        if (!path) return;
        f = fopen(path, "a");
        if (!f) fprintf(stderr, "impossible d'ouvrir %s en écriture\n", path);
    }
    void close() { if (f) { fclose(f); f = nullptr; } }
    void line(const char* fmt, ...) {
        std::lock_guard<std::mutex> lk(m);
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
    int      shard      = 0;    // partitionnement inter-processus
    int      shards     = 1;
    int      threads    = 4;    // threads de travail dans CE processus
    bool     useCuda    = true;
    // Défaut taiga, comme filterTaiga = true dans test_village_generation.cpp.
    int      biomeFilter = (int)Biome::Type::TAIGA;

    for (int i = 1; i < argc; i++) {
        if      (!strcmp(argv[i], "--cpu")) useCuda = false;
        else if (!strcmp(argv[i], "--seed")      && i+1 < argc) { startSeed = strtoull(argv[++i], nullptr, 10) & MASK48; seedGiven = true; }
        else if (!strcmp(argv[i], "--smiths")    && i+1 < argc) smithMin = atoi(argv[++i]);
        else if (!strcmp(argv[i], "--pieces")    && i+1 < argc) pieceMin = atoi(argv[++i]);
        else if (!strcmp(argv[i], "--worlds")    && i+1 < argc) worlds   = atoi(argv[++i]);
        else if (!strcmp(argv[i], "--regions")   && i+1 < argc) regions  = atoi(argv[++i]);
        else if (!strcmp(argv[i], "--max-seeds") && i+1 < argc) maxSeeds = strtol(argv[++i], nullptr, 10);
        else if (!strcmp(argv[i], "--out")       && i+1 < argc) outPath  = argv[++i];
        else if (!strcmp(argv[i], "--shard")     && i+1 < argc) shard    = atoi(argv[++i]);
        else if (!strcmp(argv[i], "--shards")    && i+1 < argc) shards   = atoi(argv[++i]);
        else if (!strcmp(argv[i], "--threads")   && i+1 < argc) threads  = atoi(argv[++i]);
        else if (!strcmp(argv[i], "--biome")     && i+1 < argc) {
            biomeFilter = parseBiomeFilter(argv[++i]);
            if (biomeFilter == -2) {
                fprintf(stderr, "biome inconnu : %s "
                        "(taiga|plains|desert|savanna|snowy|any)\n", argv[i]);
                return 2;
            }
        }
        else { fprintf(stderr, "argument inconnu : %s\n", argv[i]); return 2; }
    }
    if (threads < 1) threads = 1;
    if (shards  < 1) shards  = 1;
    if (!seedGiven) startSeed = randomStructureSeed();

    Logger log;
    log.open(outPath);

    log.line("=== Recherche de villages (%s) ===\n", useCuda ? "hauteurs CUDA" : "hauteurs CPU");
    log.line("structure seed de depart : %llu%s\n",
             (unsigned long long)startSeed, seedGiven ? "" : "  (aleatoire)");
    log.line("critere : >= %d forgerons", smithMin);
    if (pieceMin > 0) log.line("  ou >= %d pieces", pieceMin);
    log.line("\nworld seeds/structure : %d,  positions : %dx%d\n", worlds, regions, regions);
    log.line("threads : %d", threads);
    if (shards > 1) log.line(",  shard %d/%d", shard, shards);
    log.line("\nbiome : %s\n", biomeFilter < 0 ? "tous" : biomeFilterName(biomeFilter));
    log.line("forgerons comptes : %d noms\n", NUM_WEAPONSMITHS);

    {
        const char* env = getenv("CUBIOMES_LAYER_CACHE");
        if (!env || env[0] != '0')
            log.line("\nATTENTION : CUBIOMES_LAYER_CACHE n'est pas a 0. Le cache de layer de\n"
                     "  cubiomes renvoie des biomes faux pour les requetes 1x1, les resultats\n"
                     "  de la recherche ne sont pas fiables. Voir c/test_layer_cache_consistency.c\n");
    }
    log.line("\n");

    // Prechauffage CUDA sur le thread principal : le premier appel du processus
    // initialise le contexte du driver (~100 ms).
    if (useCuda) {
        CudaHeightProvider warmProvider;
        SurfaceGenWrapper::setHeightProvider(&warmProvider);
        SurfaceGenWrapper warm(startSeed, 19);
        warm.setStartSizeYExact(120);
        warm.prefetchRegion(0, 0, 194, 194);
        SurfaceGenWrapper::setHeightProvider(nullptr);
    }

    std::atomic<long>     seedsDone{0};
    std::atomic<uint64_t> positions{0};   // positions viables examinees
    std::atomic<uint64_t> villages{0};    // villages effectivement generes
    std::atomic<uint64_t> hits{0};
    std::atomic<bool>     stop{false};
    auto tStart = Clock::now();

    // Chaque thread avance sur sa propre tranche de structure seeds, par pas de
    // (threads * shards). Aucun etat partage hors des compteurs atomiques et du
    // journal, qui a son verrou.
    std::vector<std::thread> pool;
    for (int t = 0; t < threads; t++) {
        pool.emplace_back([&, t]() {
            std::unique_ptr<CudaHeightProvider> provider;
            if (useCuda) {
                provider = std::make_unique<CudaHeightProvider>();
                SurfaceGenWrapper::setHeightProvider(provider.get());
            }

            const uint64_t stride = (uint64_t)threads * (uint64_t)shards;
            const uint64_t first  = (startSeed + (uint64_t)shard * (uint64_t)threads
                                     + (uint64_t)t) & MASK48;

            for (uint64_t structureSeed = first; !stop.load(std::memory_order_relaxed);
                 structureSeed = (structureSeed + stride) & MASK48)
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
                        positions.fetch_add(1, std::memory_order_relaxed);

                        // Filtre de biome AVANT de générer. test_village_generation.cpp
                        // le teste après coup, ce qui assemble intégralement des
                        // villages pour les jeter ensuite. Le biome ne dépend que de
                        // la position, donc le résultat est le même et on économise
                        // la génération.
                        if (biomeFilter >= 0) {
                            Biome* b = tg->getBiomeSource()->getBiomeForNoiseGen(
                                (sp.x << 2) + 2, 0, (sp.z << 2) + 2);
                            if (!b || (int)b->getType() != biomeFilter) continue;
                        }

                        ChunkRand rand;
                        VillageGenerator vg;
                        if (!vg.generate(tg.get(), sp.x, sp.z, rand, nullptr, true, false)) continue;

                        villages.fetch_add(1, std::memory_order_relaxed);
                        const auto& pieces = vg.getPieces();
                        int smiths = 0;
                        for (const auto& p : pieces)
                            if (isWeaponsmith(p->name)) smiths++;

                        bool interesting = (smiths >= smithMin) ||
                                           (pieceMin > 0 && (int)pieces.size() >= pieceMin);
                        if (!interesting) continue;

                        hits.fetch_add(1, std::memory_order_relaxed);
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
                    }
                    freeLayerCaches(&g);
                }

                long done = seedsDone.fetch_add(1, std::memory_order_relaxed) + 1;
                if (maxSeeds != 0 && done >= maxSeeds)
                    stop.store(true, std::memory_order_relaxed);
            }
            SurfaceGenWrapper::setHeightProvider(nullptr);
        });
    }

    // Rapport d'avancement pendant que les threads travaillent.
    {
        long lastSeeds = 0; uint64_t lastVillages = 0, lastPositions = 0;
        auto tLast = tStart;
        while (!stop.load()) {
            for (int i = 0; i < 30 && !stop.load(); i++)
                std::this_thread::sleep_for(std::chrono::seconds(1));
            auto now = Clock::now();
            double el    = std::chrono::duration<double>(now - tStart).count();
            double delta = std::chrono::duration<double>(now - tLast).count();
            long     s = seedsDone.load();
            uint64_t v = villages.load();
            uint64_t q = positions.load();
            if (delta > 0.5) {
                printf("[%.0fs] seeds=%ld positions=%llu villages=%llu trouves=%llu | "
                       "%.1f seeds/s  %.0f pos/s  %.0f villages/s\n",
                       el, s, (unsigned long long)q, (unsigned long long)v,
                       (unsigned long long)hits.load(),
                       (s - lastSeeds) / delta, (q - lastPositions) / delta,
                       (v - lastVillages) / delta);
                fflush(stdout);
            }
            tLast = now; lastSeeds = s; lastVillages = v; lastPositions = q;
        }
    }

    for (auto& th : pool) th.join();

    double el = std::chrono::duration<double>(Clock::now() - tStart).count();
    // "positions" = emplacements de village viables examinés ; "villages" = ceux
    // effectivement générés. Avec un filtre de biome les deux diffèrent beaucoup,
    // et c'est positions/s qui mesure l'avancement de la recherche.
    log.line("\nfin : %ld seeds, %llu positions, %llu villages generes, %llu trouves en %.0f s\n",
             seedsDone.load(), (unsigned long long)positions.load(),
             (unsigned long long)villages.load(),
             (unsigned long long)hits.load(), el);
    log.close();
    SurfaceGenWrapper::setHeightProvider(nullptr);
    return 0;
}
