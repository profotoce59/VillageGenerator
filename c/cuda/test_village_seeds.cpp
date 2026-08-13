/**
 * test_village_seeds.cpp — cas de régression sur des villages précis.
 *
 * Génère un village pour un (worldSeed, chunkX, chunkZ) donné et vérifie des
 * invariants qui doivent tenir quoi qu'il arrive :
 *   - aucune pièce en double (même nom + même position + même rotation)
 *   - aucune pièce hors des bounds du village
 *   - le résultat CPU et le résultat CUDA sont identiques
 * Puis imprime le détail des forgerons, pour comparaison avec le jeu.
 *
 * Usage :
 *   test_village_seeds.exe                    -> rejoue les cas enregistrés
 *   test_village_seeds.exe <worldSeed> <cx> <cz> [--dump]
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
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <memory>
#include <string>
#include <vector>

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

struct PieceInfo {
    std::string name;
    int px, py, pz, rot;
    int minX, minY, minZ, maxX, maxY, maxZ;
    bool sameAs(const PieceInfo& o) const {
        return name == o.name && px == o.px && py == o.py && pz == o.pz && rot == o.rot;
    }
};

// Génère le village et renvoie ses pièces. useCuda choisit la source de hauteurs.
static bool generateVillage(uint64_t worldSeed, int cx, int cz, bool useCuda,
                            std::vector<PieceInfo>& out)
{
    out.clear();
    std::unique_ptr<CudaHeightProvider> provider;
    if (useCuda) {
        provider = std::make_unique<CudaHeightProvider>();
        SurfaceGenWrapper::setHeightProvider(provider.get());
    } else {
        SurfaceGenWrapper::setHeightProvider(nullptr);
    }

    Generator g;
    setupGenerator(&g, MC_1_16, 0);
    applySeed(&g, DIM_OVERWORLD, worldSeed);
    auto bs = std::make_unique<SimpleBiomeSource>(worldSeed);
    auto tg = std::make_unique<OverworldTerrainGenerator>(worldSeed, std::move(bs));

    bool viable = isViableStructurePos(Village, &g, cx << 4, cz << 4, 0);
    if (!viable) { freeLayerCaches(&g); SurfaceGenWrapper::setHeightProvider(nullptr); return false; }

    ChunkRand rand;
    VillageGenerator vg;
    bool ok = vg.generate(tg.get(), cx, cz, rand, nullptr, true, false);
    if (ok) {
        for (const auto& p : vg.getPieces()) {
            PieceInfo pi;
            pi.name = p->name;
            pi.px = p->pos.x; pi.py = p->pos.y; pi.pz = p->pos.z;
            pi.rot = (int)p->rotation;
            pi.minX = p->box.minX; pi.minY = p->box.minY; pi.minZ = p->box.minZ;
            pi.maxX = p->box.maxX; pi.maxY = p->box.maxY; pi.maxZ = p->box.maxZ;
            out.push_back(std::move(pi));
        }
    }
    freeLayerCaches(&g);
    SurfaceGenWrapper::setHeightProvider(nullptr);
    return ok;
}

// Renvoie le nombre d'anomalies trouvees.
static int checkVillage(uint64_t worldSeed, int cx, int cz, bool dump)
{
    printf("\n=== worldSeed=%llu  chunk=(%d,%d)  bloc=(%d,%d) ===\n",
           (unsigned long long)worldSeed, cx, cz, cx << 4, cz << 4);

    std::vector<PieceInfo> cpu, gpu;
    bool okCpu = generateVillage(worldSeed, cx, cz, false, cpu);
    bool okGpu = generateVillage(worldSeed, cx, cz, true,  gpu);

    if (!okCpu && !okGpu) { printf("  pas de village genere ici\n"); return 0; }

    int problems = 0;

    // 1. CPU vs CUDA
    if (cpu.size() != gpu.size()) {
        printf("  ECART CPU/CUDA : %zu pieces vs %zu\n", cpu.size(), gpu.size());
        problems++;
    } else {
        size_t diff = 0;
        for (size_t i = 0; i < cpu.size(); i++)
            if (!cpu[i].sameAs(gpu[i])) diff++;
        if (diff) { printf("  ECART CPU/CUDA : %zu pieces differentes\n", diff); problems++; }
    }

    // 2. Doublons exacts
    std::map<std::string, int> dupCount;
    size_t duplicates = 0;
    for (size_t i = 0; i < cpu.size(); i++) {
        for (size_t j = i + 1; j < cpu.size(); j++) {
            if (cpu[i].sameAs(cpu[j])) {
                duplicates++;
                dupCount[cpu[i].name]++;
                break;
            }
        }
    }

    // 3. Forgerons : total et distincts par position
    int smiths = 0;
    std::vector<PieceInfo> smithList;
    for (const auto& p : cpu) if (isWeaponsmith(p.name)) { smiths++; smithList.push_back(p); }

    int smithsDistinct = 0;
    for (size_t i = 0; i < smithList.size(); i++) {
        bool seen = false;
        for (size_t j = 0; j < i; j++)
            if (smithList[j].px == smithList[i].px && smithList[j].pz == smithList[i].pz)
                { seen = true; break; }
        if (!seen) smithsDistinct++;
    }

    printf("  pieces               : %zu\n", cpu.size());
    printf("  doublons exacts      : %zu%s\n", duplicates, duplicates ? "   <-- ANOMALIE" : "");
    printf("  forgerons comptes    : %d\n", smiths);
    printf("  forgerons distincts  : %d%s\n", smithsDistinct,
           smithsDistinct != smiths ? "   <-- ANOMALIE" : "");
    if (duplicates || smithsDistinct != smiths) problems++;

    if (!smithList.empty()) {
        // Le Java elargit la plage de scan et recommence quand le sommet est
        // encore solide (START_SIZE_MAX_TRIES) ; le C++ rend une hauteur
        // plafonnee. On compare donc chaque position au scan complet : un ecart
        // signale une hauteur tronquee, donc une piece potentiellement placee
        // la ou Minecraft ne la mettrait pas.
        SurfaceGenWrapper probe(worldSeed, 19);
        int heightY = probe.getHeightOnGround((cx << 4) + 8, (cz << 4) + 8);
        int startCells = (heightY + 25) / 8;
        int ceilingY = startCells * 8;
        printf("  heightY centre=%d -> startSizeY=%d cellules, plafond de scan y=%d\n",
               heightY, startCells, ceilingY);

        SurfaceGenWrapper trunc(worldSeed, 19);
        trunc.setStartSizeYExact(heightY + 25);

        printf("  detail des forgerons (h_tronque / h_complet) :\n");
        int truncated = 0;
        for (const auto& s : smithList) {
            int hT = trunc.generateColumnFromY(s.px, s.pz, nullptr);
            int hF = probe.getFirstHeightFull(s.px, s.pz);
            bool bad = (hT != hF);
            if (bad) truncated++;
            printf("    %-40s pos=(%d,%d,%d) rot=%d   h=%3d / %3d%s\n",
                   s.name.c_str(), s.px, s.py, s.pz, s.rot, hT, hF,
                   bad ? "   <-- HAUTEUR TRONQUEE" : "");
        }
        if (truncated) {
            printf("  %d forgeron(s) sur %d reposent sur une hauteur tronquee\n",
                   truncated, (int)smithList.size());
            problems++;
        }

        // Meme controle sur TOUTES les pieces : une seule hauteur tronquee
        // suffit a devier la suite de l'assemblage, donc la composition finale.
        int truncAll = 0, checked = 0;
        for (const auto& p : cpu) {
            int hT = trunc.generateColumnFromY(p.px, p.pz, nullptr);
            int hF = probe.getFirstHeightFull(p.px, p.pz);
            checked++;
            if (hT != hF) truncAll++;
        }
        printf("  pieces sur hauteur tronquee : %d / %d%s\n", truncAll, checked,
               truncAll ? "   <-- la disposition diverge de Minecraft" : "");
        if (truncAll && !truncated) problems++;
    }

    if (dump) {
        printf("  toutes les pieces :\n");
        for (size_t i = 0; i < cpu.size(); i++)
            printf("    [%3zu] %-45s pos=(%d,%d,%d) rot=%d\n", i, cpu[i].name.c_str(),
                   cpu[i].px, cpu[i].py, cpu[i].pz, cpu[i].rot);
    }
    return problems;
}

int main(int argc, char** argv)
{
    printf("=== Cas de regression sur villages precis ===\n");
    {
        const char* env = getenv("CUBIOMES_LAYER_CACHE");
        if (!env || env[0] != '0')
            printf("\nATTENTION : CUBIOMES_LAYER_CACHE n'est pas a 0, les biomes des\n"
                   "  requetes 1x1 sont faux (cf. c/test_layer_cache_consistency.c).\n");
    }

    int problems = 0;
    if (argc >= 4) {
        uint64_t ws = strtoull(argv[1], nullptr, 10);
        int cx = atoi(argv[2]), cz = atoi(argv[3]);
        bool dump = (argc > 4 && !strcmp(argv[4], "--dump"));
        problems += checkVillage(ws, cx, cz, dump);
    } else {
        // Cas signales comme incoherents avec le jeu : 8 forgerons rapportes,
        // 4 constates en jeu.
        struct Case { uint64_t worldSeed; int cx, cz; };
        static const Case cases[] = {
            { 3735182320702388ULL,   6,  23 },
            { 2327807437156000ULL, 205,  17 },
        };
        for (const Case& c : cases)
            problems += checkVillage(c.worldSeed, c.cx, c.cz, false);
    }

    printf("\n=== %s (%d anomalie%s) ===\n",
           problems ? "ANOMALIES DETECTEES" : "OK",
           problems, problems > 1 ? "s" : "");
    return problems ? 1 : 0;
}
