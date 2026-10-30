/**
 * refine_seeds.cpp — pour des structure seeds déjà trouvées, balaye TOUS les
 * world seeds possibles.
 *
 * Une world seed vaut (structureSeed | ws << 48) : les 48 bits de poids faible
 * fixent l'emplacement des structures, les 16 bits de poids fort font varier le
 * terrain. La recherche large n'en essaie que quelques-unes (--worlds 32), soit
 * 32 sur 65 536. Cet outil épuise les 65 536 pour les seeds prometteuses.
 *
 * Les positions de village ne dépendent que de la structure seed : le chunk
 * trouvé lors de la recherche large reste valable pour toutes les world seeds.
 *
 * Entrée : une cible par ligne, « structureSeed (chunkX,chunkZ) ». Les lignes
 * TROUVE de la recherche sont acceptées telles quelles (seuls structureSeed= et
 * chunk=(x,z) sont lus). Doublons fusionnés, lignes vides et # ignorées.
 *
 * Sortie : --out écrit un .txt NU, une seed par ligne et rien d'autre, à coller
 * telle quelle dans le jeu. Une ligne par cible : la meilleure world seed
 * trouvée. Inutile d'en écrire plus — toutes les world seeds qui atteignent le
 * même nombre de forgerons donnent le MÊME village (le jigsaw ne dépend que de
 * la structure seed), seul le terrain autour change.
 * Le détail (distribution, nombre de doublons) reste sur la console.
 *
 * Usage :
 *   refine_seeds.exe [--in FICHIER] [--worlds N] [--smiths N] [--threads N]
 *                    [--out FICHIER] [--biome NOM] [--cpu]
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
#include <cctype>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <memory>
#include <mutex>
#include <sstream>
#include <string>
#include <thread>
#include <vector>

using Clock = std::chrono::steady_clock;

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

struct Target {
    uint64_t structureSeed;
    int cx, cz;
    bool operator==(const Target& o) const {
        return structureSeed == o.structureSeed && cx == o.cx && cz == o.cz;
    }
};

struct Hit {
    uint64_t worldSeed;
    int smiths;
    size_t pieces;
};

// Lit une cible sur une ligne. Format normal : « structureSeed (chunkX,chunkZ) ».
// Une ligne TROUVE complete de la recherche marche aussi, collee telle quelle.
static bool parseLine(std::string line, Target& t)
{
    size_t h = line.find('#');
    if (h != std::string::npos) line.erase(h);

    // Ligne TROUVE : aller chercher les deux champs nommes. Un balayage naif des
    // nombres attraperait l'horodatage « [6385s] » puis worldSeed=.
    size_t p = line.find("structureSeed=");
    if (p != std::string::npos) {
        size_t c = line.find("chunk=(", p);
        if (c == std::string::npos) return false;
        t.structureSeed = strtoull(line.c_str() + p + 14, nullptr, 10) & MASK48;
        return sscanf(line.c_str() + c + 7, "%d,%d", &t.cx, &t.cz) == 2;
    }

    // Format normal. Les separateurs (parentheses, virgules) deviennent des
    // espaces : on lit ensuite simplement les trois nombres.
    for (char& ch : line)
        if (!isdigit((unsigned char)ch) && ch != '-') ch = ' ';

    std::istringstream is(line);
    unsigned long long s;
    if (!(is >> s >> t.cx >> t.cz)) return false;
    t.structureSeed = (uint64_t)s & MASK48;
    return true;
}

int main(int argc, char** argv)
{
    const char* inPath  = nullptr;
    const char* outPath = "seeds_trouvees.txt";
    long   worlds   = 65536;          // 2^16 : toutes les world seeds
    int    smithMin = 8;
    int    nThreads = 16;
    bool   useCuda  = true;
    int    biomeFilter = (int)Biome::Type::TAIGA;

    for (int i = 1; i < argc; i++) {
        if      (!strcmp(argv[i], "--cpu")) useCuda = false;
        else if (!strcmp(argv[i], "--in")      && i+1 < argc) inPath   = argv[++i];
        else if (!strcmp(argv[i], "--out")     && i+1 < argc) outPath  = argv[++i];
        else if (!strcmp(argv[i], "--worlds")  && i+1 < argc) worlds   = strtol(argv[++i], nullptr, 10);
        else if (!strcmp(argv[i], "--smiths")  && i+1 < argc) smithMin = atoi(argv[++i]);
        else if (!strcmp(argv[i], "--threads") && i+1 < argc) nThreads = atoi(argv[++i]);
        else if (!strcmp(argv[i], "--biome")   && i+1 < argc) {
            const char* b = argv[++i];
            if      (!strcmp(b, "any"))     biomeFilter = -1;
            else if (!strcmp(b, "taiga"))   biomeFilter = (int)Biome::Type::TAIGA;
            else if (!strcmp(b, "plains"))  biomeFilter = (int)Biome::Type::PLAINS;
            else if (!strcmp(b, "desert"))  biomeFilter = (int)Biome::Type::DESERT;
            else if (!strcmp(b, "savanna")) biomeFilter = (int)Biome::Type::SAVANNA;
            else if (!strcmp(b, "snowy"))   biomeFilter = (int)Biome::Type::SNOWY_TUNDRA;
            else { fprintf(stderr, "biome inconnu : %s\n", b); return 2; }
        }
        else { fprintf(stderr, "argument inconnu : %s\n", argv[i]); return 2; }
    }
    if (nThreads < 1) nThreads = 1;

    // Pas de filtre de centre ici : on veut évaluer TOUTES les world seeds,
    // pas seulement celles dont le centre annonce un gros village.
    VillageGenerator::setStartTemplateFilter({});

    // ---- lecture des cibles ----
    std::vector<Target> targets;
    {
        std::istream* in = &std::cin;
        std::ifstream f;
        if (inPath) {
            f.open(inPath);
            if (!f) { fprintf(stderr, "impossible d'ouvrir %s\n", inPath); return 1; }
            in = &f;
        }
        std::string line;
        while (std::getline(*in, line)) {
            Target t;
            if (!parseLine(line, t)) continue;
            if (std::find(targets.begin(), targets.end(), t) == targets.end())
                targets.push_back(t);
        }
    }
    if (targets.empty()) {
        fprintf(stderr, "aucune cible lue (attendu des lignes TROUVE, ou "
                        "\"structureSeed chunkX chunkZ\")\n");
        return 1;
    }

    // Fichier de sortie : rien que des seeds, une par ligne. Réécrit à chaque
    // lancement (un append rendrait la liste inutilisable au bout de deux runs).
    FILE* out = nullptr;
    if (outPath && strcmp(outPath, "-")) {
        out = fopen(outPath, "w");
        if (!out) { fprintf(stderr, "impossible d'ecrire %s\n", outPath); return 1; }
    }
    #define emit printf

    emit("=== Balayage exhaustif des world seeds ===\n");
    emit("cibles : %d   world seeds par cible : %ld   threads : %d\n",
         (int)targets.size(), worlds, nThreads);
    emit("seuil : >= %d forgerons", smithMin);
    if (out) emit("   sortie : %s", outPath);
    emit("\n\n");

    // Préchauffage CUDA hors mesure.
    if (useCuda) {
        CudaHeightProvider warm;
        SurfaceGenWrapper::setHeightProvider(&warm);
        SurfaceGenWrapper w(targets[0].structureSeed, 19);
        w.setStartSizeYExact(120);
        w.prefetchRegion(0, 0, 194, 194);
        SurfaceGenWrapper::setHeightProvider(nullptr);
    }

    auto tStart = Clock::now();
    long grandTotal = 0;
    int  kept = 0;

    for (size_t ti = 0; ti < targets.size(); ti++) {
        const Target& T = targets[ti];
        std::mutex hitMutex;
        std::vector<Hit> hits;
        // Distribution des forgerons : dit si faire varier le world seed change
        // vraiment le village, ou si on ne collecte que des doublons.
        std::vector<long> smithHist(64, 0);
        std::vector<size_t> distinctPieces;
        std::atomic<long> generated{0};
        int bestSmiths = -1;
        uint64_t bestSeed = 0;
        size_t bestPieces = 0;

        std::vector<std::thread> pool;
        for (int t = 0; t < nThreads; t++) {
            pool.emplace_back([&, t]() {
                std::unique_ptr<CudaHeightProvider> provider;
                if (useCuda) {
                    provider = std::make_unique<CudaHeightProvider>();
                    SurfaceGenWrapper::setHeightProvider(provider.get());
                }
                for (long ws = t; ws < worlds; ws += nThreads) {
                    uint64_t worldSeed = T.structureSeed | ((uint64_t)ws << 48);

                    Generator g;
                    setupGenerator(&g, MC_1_16, 0);
                    applySeed(&g, DIM_OVERWORLD, worldSeed);
                    auto bs = std::make_unique<SimpleBiomeSource>(worldSeed);
                    auto tg = std::make_unique<OverworldTerrainGenerator>(worldSeed, std::move(bs));

                    if (isViableStructurePos(Village, &g, T.cx << 4, T.cz << 4, 0)) {
                        bool biomeOk = true;
                        if (biomeFilter >= 0) {
                            Biome* b = tg->getBiomeSource()->getBiomeForNoiseGen(
                                (T.cx << 2) + 2, 0, (T.cz << 2) + 2);
                            biomeOk = (b && (int)b->getType() == biomeFilter);
                        }
                        if (biomeOk) {
                            ChunkRand rand;
                            VillageGenerator vg;
                            if (vg.generate(tg.get(), T.cx, T.cz, rand, nullptr, true, false)) {
                                generated.fetch_add(1, std::memory_order_relaxed);
                                const auto& pieces = vg.getPieces();
                                int smiths = 0;
                                for (const auto& p : pieces)
                                    if (isWeaponsmith(p->name)) smiths++;
                                if (smiths >= smithMin) {
                                    std::lock_guard<std::mutex> lk(hitMutex);
                                    hits.push_back({worldSeed, smiths, pieces.size()});
                                }
                                {
                                    std::lock_guard<std::mutex> lk(hitMutex);
                                    if (smiths >= 0 && smiths < (int)smithHist.size())
                                        smithHist[smiths]++;
                                    if (std::find(distinctPieces.begin(), distinctPieces.end(),
                                                  pieces.size()) == distinctPieces.end())
                                        distinctPieces.push_back(pieces.size());
                                    if (smiths > bestSmiths) {
                                        bestSmiths = smiths; bestSeed = worldSeed;
                                        bestPieces = pieces.size();
                                    }
                                }
                            }
                        }
                    }
                    freeLayerCaches(&g);
                }
                SurfaceGenWrapper::setHeightProvider(nullptr);
            });
        }
        for (auto& th : pool) th.join();

        grandTotal += generated.load();
        double el = std::chrono::duration<double>(Clock::now() - tStart).count();

        emit("--- [%d/%d] structureSeed=%llu chunk=(%d,%d) bloc=(%d,%d) ---\n",
             (int)ti + 1, (int)targets.size(),
             (unsigned long long)T.structureSeed, T.cx, T.cz, T.cx << 4, T.cz << 4);
        emit("  villages generes : %ld / %ld world seeds   [%.0fs]\n",
             generated.load(), worlds, el);
        if (bestSmiths >= 0)
            emit("  meilleur : %d forgerons, %zu pieces, worldSeed=%llu\n",
                 bestSmiths, bestPieces, (unsigned long long)bestSeed);

        {
            emit("  distribution des forgerons :");
            for (int k = 0; k < (int)smithHist.size(); k++)
                if (smithHist[k]) emit("  %d->%ld", k, smithHist[k]);
            emit("\n  tailles de village distinctes : %d\n", (int)distinctPieces.size());
        }

        emit("  au-dessus du seuil : %d world seeds (meme village, terrain different)\n",
             (int)hits.size());

        // Une seule ligne dans le .txt : la meilleure world seed de la cible.
        // Les 1200+ autres au meme score sont des doublons exacts du village.
        if (bestSmiths >= smithMin) {
            if (out) { fprintf(out, "%llu\n", (unsigned long long)bestSeed); fflush(out); }
            kept++;
        } else {
            emit("  (rien retenu : le meilleur est a %d forgerons)\n", bestSmiths);
        }
        emit("\n");
        fflush(stdout);
    }

    double el = std::chrono::duration<double>(Clock::now() - tStart).count();
    emit("fin : %d cibles, %ld villages generes en %.0f s (%.0f villages/s)\n",
         (int)targets.size(), grandTotal, el, el > 0 ? grandTotal / el : 0.0);
    if (out) {
        fclose(out);
        emit("%d seed%s ecrite%s dans %s (une par ligne, rien d'autre)\n",
             kept, kept > 1 ? "s" : "", kept > 1 ? "s" : "", outPath);
    }
    return 0;
}
