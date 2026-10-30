/**
 * stats_pieces.cpp — la piece n°K d'un village predit-elle sa taille ?
 *
 * On filtre deja la piece 0 (le centre, --start de search_village_cuda) parce
 * que certains centres n'annoncent que de petits villages. Cet outil pose la
 * meme question un cran plus loin : en groupant les villages par le NOM de leur
 * piece n°K (par defaut K=1, la premiere rue accrochee au centre), les
 * distributions de « nombre de pieces » et de « forgerons » se separent-elles
 * assez pour qu'un filtre sur cette piece vaille le coup ?
 *
 * Mesure seulement — rien n'est filtre ici. Si une piece ressort, le filtre se
 * pose ensuite dans VillageGenerator, comme setStartTemplateFilter.
 *
 * Usage :
 *   stats_pieces.exe [--seed N] [--seeds N] [--worlds N] [--regions N]
 *                    [--biome NOM] [--start NOM] [--by K] [--threads N]
 *                    [--min-n N] [--cpu]
 *
 *     --by K      index de la piece servant de cle (0 = centre, 1 = 2e piece...)
 *     --seeds N   nombre de structure seeds parcourues (defaut 20)
 *     --min-n N   n'affiche que les groupes vus au moins N fois (defaut 30)
 *     --good N    seuil « bon village » pour le tableau de filtre (defaut 4)
 *
 * Pourquoi --good 4 et pas 8 : a >= 8 forgerons la recherche trouve environ un
 * village sur 300 000. Aucun echantillon raisonnable ne contient assez de ces
 * villages pour comparer des groupes. On mesure donc la queue a un seuil
 * atteignable et on suppose la monotonie : un groupe qui produit plus de
 * villages a >= 4 forgerons en produit plus a >= 8.
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

#include <algorithm>
#include <atomic>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

using Clock = std::chrono::steady_clock;

// Memes noms que search_village_cuda.cpp : les stats doivent parler du meme
// « forgeron » que le critere de recherche.
static const char* const WEAPONSMITHS[] = {
    "plains/houses/plains_weaponsmith_1",
    "desert/houses/desert_weaponsmith_1",
    "savanna/houses/savanna_weaponsmith_2",
    "taiga/houses/taiga_weaponsmith_1",
};
static bool isWeaponsmith(const std::string& n) {
    for (const char* w : WEAPONSMITHS) if (n == w) return true;
    return false;
}

static int parseBiomeFilter(const char* name)
{
    if (!strcmp(name, "any"))     return -1;
    if (!strcmp(name, "taiga"))   return (int)Biome::Type::TAIGA;
    if (!strcmp(name, "plains"))  return (int)Biome::Type::PLAINS;
    if (!strcmp(name, "desert"))  return (int)Biome::Type::DESERT;
    if (!strcmp(name, "savanna")) return (int)Biome::Type::SAVANNA;
    if (!strcmp(name, "snowy"))   return (int)Biome::Type::SNOWY_TUNDRA;
    return -2;
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

// Un groupe = tous les villages partageant la meme piece n°K.
// Les echantillons sont gardes bruts : la mediane et le p90 disent bien plus
// que la moyenne sur des distributions aussi etalees.
struct Bucket {
    std::vector<uint16_t> pieceCounts;
    std::vector<uint8_t>  smiths;

    void add(size_t np, int sm) {
        pieceCounts.push_back((uint16_t)std::min<size_t>(np, 65535));
        smiths.push_back((uint8_t)std::min(sm, 255));
    }
    void merge(const Bucket& o) {
        pieceCounts.insert(pieceCounts.end(), o.pieceCounts.begin(), o.pieceCounts.end());
        smiths.insert(smiths.end(), o.smiths.begin(), o.smiths.end());
    }
};

// v doit etre trie par l'appelant.
template <class T>
static double quantile(const std::vector<T>& v, double q) {
    if (v.empty()) return 0.0;
    double idx = q * (double)(v.size() - 1);
    size_t lo = (size_t)idx;
    size_t hi = std::min(lo + 1, v.size() - 1);
    double f = idx - (double)lo;
    return (double)v[lo] * (1.0 - f) + (double)v[hi] * f;
}

template <class T>
static double mean(const std::vector<T>& v) {
    if (v.empty()) return 0.0;
    double s = 0.0;
    for (T x : v) s += (double)x;
    return s / (double)v.size();
}

template <class T>
static double stddev(const std::vector<T>& v, double m) {
    if (v.size() < 2) return 0.0;
    double s = 0.0;
    for (T x : v) { double d = (double)x - m; s += d * d; }
    return std::sqrt(s / (double)(v.size() - 1));
}

int main(int argc, char** argv)
{
    uint64_t startSeed = 1;
    long     nSeeds    = 20;
    int      worlds    = 8;
    int      regions   = 10;
    int      threads   = 4;
    int      byIndex   = 1;
    long     minN      = 30;
    int      goodSmiths = 4;
    int      biomeFilter = (int)Biome::Type::TAIGA;
    bool     useCuda   = true;
    std::vector<std::string> startFilter;

    for (int i = 1; i < argc; i++) {
        if      (!strcmp(argv[i], "--seed")    && i+1 < argc) startSeed = strtoull(argv[++i], nullptr, 10);
        else if (!strcmp(argv[i], "--seeds")   && i+1 < argc) nSeeds  = strtol(argv[++i], nullptr, 10);
        else if (!strcmp(argv[i], "--worlds")  && i+1 < argc) worlds  = atoi(argv[++i]);
        else if (!strcmp(argv[i], "--regions") && i+1 < argc) regions = atoi(argv[++i]);
        else if (!strcmp(argv[i], "--threads") && i+1 < argc) threads = atoi(argv[++i]);
        else if (!strcmp(argv[i], "--by")      && i+1 < argc) byIndex = atoi(argv[++i]);
        else if (!strcmp(argv[i], "--min-n")   && i+1 < argc) minN    = strtol(argv[++i], nullptr, 10);
        else if (!strcmp(argv[i], "--good")    && i+1 < argc) goodSmiths = atoi(argv[++i]);
        else if (!strcmp(argv[i], "--cpu"))                   useCuda = false;
        else if (!strcmp(argv[i], "--biome")   && i+1 < argc) {
            biomeFilter = parseBiomeFilter(argv[++i]);
            if (biomeFilter == -2) { fprintf(stderr, "biome inconnu : %s\n", argv[i]); return 2; }
        }
        else if (!strcmp(argv[i], "--start")   && i+1 < argc) {
            std::string v = argv[++i];
            if (v == "any") { startFilter.clear(); continue; }
            size_t p0 = 0;
            while (p0 <= v.size()) {
                size_t p1 = v.find(',', p0);
                if (p1 == std::string::npos) p1 = v.size();
                if (p1 > p0) startFilter.push_back(v.substr(p0, p1 - p0));
                p0 = p1 + 1;
            }
        }
        else { fprintf(stderr, "argument inconnu : %s\n", argv[i]); return 2; }
    }
    if (threads < 1) threads = 1;
    if (byIndex < 0) byIndex = 0;
    VillageGenerator::setStartTemplateFilter(startFilter);

    printf("=== Stats : taille du village selon la piece n°%d ===\n", byIndex);
    printf("seed de depart %llu, %ld structure seeds x %d world seeds x %dx%d positions\n",
           (unsigned long long)startSeed, nSeeds, worlds, regions, regions);
    printf("biome : %s\n", biomeFilter < 0 ? "tous" : biomeFilterName(biomeFilter));
    if (startFilter.empty()) {
        printf("centres acceptes : tous\n\n");
    } else {
        printf("centres acceptes : %d\n", (int)startFilter.size());
        for (const std::string& sf : startFilter) printf("  %s\n", sf.c_str());
        printf("\n");
    }
    fflush(stdout);

    if (useCuda) {   // prechauffage du contexte CUDA, comme search_village_cuda
        CudaHeightProvider warmProvider;
        SurfaceGenWrapper::setHeightProvider(&warmProvider);
        SurfaceGenWrapper warm(startSeed, 19);
        warm.setStartSizeYExact(120);
        warm.prefetchRegion(0, 0, 194, 194);
        SurfaceGenWrapper::setHeightProvider(nullptr);
    }

    std::mutex mergeMutex;
    std::map<std::string, Bucket> global;
    std::atomic<long>     seedCursor{0};
    std::atomic<uint64_t> villages{0};
    auto tStart = Clock::now();

    std::vector<std::thread> pool;
    for (int t = 0; t < threads; t++) {
        pool.emplace_back([&]() {
            std::unique_ptr<CudaHeightProvider> provider;
            if (useCuda) {
                provider = std::make_unique<CudaHeightProvider>();
                SurfaceGenWrapper::setHeightProvider(provider.get());
            }
            std::map<std::string, Bucket> local;

            for (;;) {
                long k = seedCursor.fetch_add(1, std::memory_order_relaxed);
                if (k >= nSeeds) break;
                const uint64_t structureSeed = (startSeed + (uint64_t)k) & MASK48;

                std::vector<Pos> posList;
                for (int rx = 0; rx < regions; rx++)
                    for (int rz = 0; rz < regions; rz++) {
                        Pos p;
                        if (getStructurePos(Village, MC_1_16, structureSeed, rx, rz, &p)) {
                            Pos c; c.x = p.x >> 4; c.z = p.z >> 4;
                            posList.push_back(c);
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
                        if (biomeFilter >= 0) {
                            Biome* b = tg->getBiomeSource()->getBiomeForNoiseGen(
                                (sp.x << 2) + 2, 0, (sp.z << 2) + 2);
                            if (!b || (int)b->getType() != biomeFilter) continue;
                        }

                        ChunkRand rand;
                        VillageGenerator vg;
                        if (!vg.generate(tg.get(), sp.x, sp.z, rand, nullptr, true, false)) continue;

                        const auto& pieces = vg.getPieces();
                        if (pieces.empty()) continue;
                        villages.fetch_add(1, std::memory_order_relaxed);

                        int smiths = 0;
                        for (const auto& p : pieces)
                            if (isWeaponsmith(p->name)) smiths++;

                        // Village trop court pour avoir une piece n°K : groupe a
                        // part plutot qu'ecarte, sinon on masquerait justement les
                        // plus petits villages.
                        const std::string key = ((size_t)byIndex < pieces.size())
                                              ? pieces[byIndex]->name
                                              : std::string("(aucune)");
                        local[key].add(pieces.size(), smiths);
                    }
                    freeLayerCaches(&g);
                }
            }

            SurfaceGenWrapper::setHeightProvider(nullptr);
            std::lock_guard<std::mutex> lk(mergeMutex);
            for (auto& kv : local) global[kv.first].merge(kv.second);
        });
    }
    for (auto& th : pool) th.join();

    const double elapsed = std::chrono::duration<double>(Clock::now() - tStart).count();

    // Reference globale, pour juger si un groupe s'ecarte vraiment.
    Bucket all;
    for (auto& kv : global) all.merge(kv.second);
    if (all.pieceCounts.empty()) {
        printf("aucun village genere — elargis --seeds / --worlds ou change --biome\n");
        return 1;
    }
    std::sort(all.pieceCounts.begin(), all.pieceCounts.end());
    std::sort(all.smiths.begin(), all.smiths.end());

    struct Row {
        std::string name;
        size_t n, nGood;
        double share, meanP, sdP, p50, p90;
        int    maxP;
        double meanS, pctGood, rate;
        int    maxS;
    };
    std::vector<Row> rows;
    size_t totalGood = 0;
    for (auto& kv : global) {
        Bucket& b = kv.second;
        Row r;
        r.name  = kv.first;
        r.n     = b.pieceCounts.size();
        r.share = 100.0 * (double)r.n / (double)all.pieceCounts.size();
        std::sort(b.pieceCounts.begin(), b.pieceCounts.end());
        r.meanP = mean(b.pieceCounts);
        r.sdP   = stddev(b.pieceCounts, r.meanP);
        r.p50   = quantile(b.pieceCounts, 0.50);
        r.p90   = quantile(b.pieceCounts, 0.90);
        r.maxP  = (int)b.pieceCounts.back();
        r.meanS = mean(b.smiths);
        size_t g = 0; int maxS = 0;
        for (uint8_t s : b.smiths) { if ((int)s >= goodSmiths) g++; if (s > maxS) maxS = s; }
        r.nGood   = g;
        r.pctGood = 100.0 * (double)g / (double)r.n;
        r.rate    = (double)g / (double)r.n;
        r.maxS    = maxS;
        totalGood += g;
        rows.push_back(r);
    }
    std::sort(rows.begin(), rows.end(),
              [](const Row& a, const Row& b) { return a.meanP > b.meanP; });

    long shown = 0;
    for (const Row& r : rows) if ((long)r.n >= minN) shown++;

    printf("%llu villages generes en %.1f s (%.0f villages/s)\n",
           (unsigned long long)villages.load(), elapsed,
           elapsed > 0 ? (double)villages.load() / elapsed : 0.0);
    printf("ensemble : pieces moy %.1f  med %.0f  p90 %.0f  max %d | forgerons moy %.3f\n",
           mean(all.pieceCounts), quantile(all.pieceCounts, 0.50),
           quantile(all.pieceCounts, 0.90), (int)all.pieceCounts.back(), mean(all.smiths));

    // Distribution des forgerons : c'est elle qui dit si --good est bien place.
    {
        int maxS = all.smiths.empty() ? 0 : (int)all.smiths.back();
        printf("forgerons : ");
        for (int s = 0; s <= maxS; s++) {
            size_t c = 0;
            for (uint8_t v : all.smiths) if ((int)v == s) c++;
            if (c) printf("%d:%zu (%.3f%%)  ", s, c, 100.0 * (double)c / (double)all.smiths.size());
        }
        printf("\n");
    }
    printf("%zu valeurs distinctes pour la piece n°%d, %ld affichees (n >= %ld)\n\n",
           rows.size(), byIndex, shown, minN);

    printf("%-52s %8s %6s | %7s %6s %5s %5s %5s | %6s %7s %4s\n",
           "piece", "n", "%tot", "pieces", "ecart", "med", "p90", "max",
           "forg.", ">=N", "max");
    printf("%s\n", std::string(126, '-').c_str());
    for (const Row& r : rows) {
        if ((long)r.n < minN) continue;
        printf("%-52s %8zu %5.1f%% | %7.1f %6.1f %5.0f %5.0f %5d | %6.3f %6.2f%% %4d\n",
               r.name.c_str(), r.n, r.share, r.meanP, r.sdP, r.p50, r.p90, r.maxP,
               r.meanS, r.pctGood, r.maxS);
    }

    // Groupes trop rares pour conclure : resumes plutot que caches.
    size_t rareN = 0, rareGroups = 0;
    for (const Row& r : rows) if ((long)r.n < minN) { rareN += r.n; rareGroups++; }
    if (rareGroups)
        printf("\n(%zu groupes sous le seuil, %zu villages au total)\n", rareGroups, rareN);

    // ---- Le seul tableau qui decide vraiment ----------------------------
    //
    // Un filtre n'est pas gratuit : il jette aussi des bons villages. On classe
    // les groupes par densite de bons villages, puis on lit, pour chaque
    // coupure, ce qu'on garde (cout) et ce qu'on retrouve (rappel). Le gain net
    // est rappel/cout : au-dessus de 1, la meme puissance de calcul examine
    // plus de bons villages qu'aujourd'hui.
    printf("\n=== Filtre sur la piece n°%d : que gagne-t-on ? "
           "(bon = >= %d forgerons, %zu villages) ===\n",
           byIndex, goodSmiths, totalGood);
    if (totalGood == 0) {
        printf("aucun village a >= %d forgerons dans l'echantillon : baisse --good\n",
               goodSmiths);
        return 0;
    }

    std::vector<Row> byRate = rows;
    std::sort(byRate.begin(), byRate.end(),
              [](const Row& a, const Row& b) { return a.rate > b.rate; });

    printf("%-52s %8s %7s | %8s %8s %6s\n",
           "en gardant aussi ce groupe", "n", "bons", "garde%", "rappel%", "gain");
    printf("%s\n", std::string(96, '-').c_str());
    size_t cumN = 0, cumGood = 0;
    for (const Row& r : byRate) {
        cumN    += r.n;
        cumGood += r.nGood;
        double kept   = 100.0 * (double)cumN    / (double)all.pieceCounts.size();
        double recall = 100.0 * (double)cumGood / (double)totalGood;
        printf("%-52s %8zu %7zu | %7.1f%% %7.1f%% %6.2f\n",
               r.name.c_str(), r.n, r.nGood, kept, recall,
               kept > 0 ? recall / kept : 0.0);
        if (cumGood == totalGood) break;
    }

    printf("\nLecture : 'gain' = rappel/garde, le facteur d'enrichissement du filtre.\n"
           "1.00 signifie que la piece n°%d ne porte aucune information et qu'un\n"
           "filtre dessus reviendrait a jeter des villages au hasard.\n"
           "\n"
           "Mais l'enrichissement n'est PAS le gain en temps. Il faut generer le\n"
           "village jusqu'a la piece n°%d pour la connaitre, et ce prefixe se paie\n"
           "sur TOUS les villages. Avec a = part du cout d'un village payee avant\n"
           "l'abandon, garde = k et rappel = r, le nombre de bons villages trouves\n"
           "par seconde est multiplie par :\n"
           "\n"
           "        r / (a + k(1-a))\n"
           "\n"
           "Un filtre sur la piece 0 a a~0 (rien n'est assemble) et se resume donc\n"
           "a r/k. Plus l'index monte, plus a monte et plus r doit etre proche de 1\n"
           "pour que le filtre rapporte quoi que ce soit. Sur la piece 1, a est\n"
           "aujourd'hui minore par le prefetch GPU, qui precede l'assemblage dans\n"
           "Assembler::Assembler : il faudrait le rendre paresseux avant d'esperer\n"
           "un a faible.\n", byIndex, byIndex);
    return 0;
}
