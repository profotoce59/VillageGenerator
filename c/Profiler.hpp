#pragma once

/**
 * Profiler.hpp — chronométrage par zones nommées, à coût nul quand désactivé.
 *
 * Tout le code de mesure est derrière VILLAGE_PROFILE. Les binaires normaux
 * (bench_village, search_village_cuda) sont compilés sans, donc les sondes
 * disparaissent complètement à la compilation et ne faussent pas les mesures
 * de débit. Seule la cible profile_village définit le symbole.
 *
 * Usage :
 *     void f() {
 *         VPROF_SCOPE(VZ_ASSEMBLE);
 *         ...
 *     }
 */

#ifdef VILLAGE_PROFILE

#include <chrono>
#include <cstdint>
#include <cstdio>
#include <algorithm>
#include <vector>

enum VProfZone {
    VZ_WORLD_SETUP = 0,   // setupGenerator + applySeed + BiomeSource + TerrainGenerator
    VZ_VIABLE,            // isViableStructurePos
    VZ_VILLAGE_TOTAL,     // VillageGenerator::generate (englobe tout le reste)
    VZ_SURFACEGEN_CTOR,   // construction SurfaceGenWrapper (init_cubiomes_context)
    VZ_HEIGHT_CENTER,     // getHeightOnGround du centre (fixe startSizeY)
    VZ_PREFETCH,          // pré-calcul de la zone de hauteurs
    VZ_HEIGHT_QUERY,      // generateColumnFromY
    VZ_ASSEMBLE,          // assembler.run()
    VZ_POOL_CREATE,       // createVillagePool
    VZ_JIGSAW_BLOCKS,     // getShuffledJigsawBlocks
    VZ_TEMPLATE_LIST,     // construction + mélange de la liste pondérée
    VZ_SIZE_LOOKUP,       // get_bpos
    VZ_VOXEL_CHECK,       // isNotEmpty / VoxelShape::intersects
    VZ_COUNT
};

struct VProfCounters {
    uint64_t nanos[VZ_COUNT];
    uint64_t calls[VZ_COUNT];
};

inline VProfCounters g_vprof = {};

inline const char* vprofName(int z) {
    static const char* n[VZ_COUNT] = {
        "world_setup", "viable_check", "village_total", "surfacegen_ctor",
        "height_center", "prefetch", "height_query", "assemble",
        "pool_create", "jigsaw_blocks", "template_list", "size_lookup",
        "voxel_check"
    };
    return n[z];
}

class VProfScope {
public:
    explicit VProfScope(VProfZone z)
        : zone_(z), t0_(std::chrono::steady_clock::now()) {}
    ~VProfScope() {
        auto dt = std::chrono::steady_clock::now() - t0_;
        g_vprof.nanos[zone_] +=
            (uint64_t)std::chrono::duration_cast<std::chrono::nanoseconds>(dt).count();
        g_vprof.calls[zone_]++;
    }
private:
    VProfZone zone_;
    std::chrono::steady_clock::time_point t0_;
};

#define VPROF_CONCAT2(a, b) a##b
#define VPROF_CONCAT(a, b) VPROF_CONCAT2(a, b)
#define VPROF_SCOPE(zone) VProfScope VPROF_CONCAT(vprof_, __LINE__)(zone)

inline void vprofReset() { g_vprof = VProfCounters{}; }

/**
 * Affiche le détail, trié par temps décroissant.
 * `wallMs` sert de dénominateur pour les pourcentages.
 *
 * Attention à la lecture : les zones s'emboîtent (village_total contient
 * assemble, qui contient height_query...). Les pourcentages ne s'additionnent
 * donc pas à 100 %. La colonne "propre" retire des zones englobantes le temps
 * de leurs sous-zones connues.
 */
inline void vprofReport(double wallMs) {
    // Sous-zones directes de chaque zone englobante, pour le temps propre.
    static const int childrenOf[VZ_COUNT][6] = {
        /*world_setup*/     {-1},
        /*viable_check*/    {-1},
        /*village_total*/   {VZ_SURFACEGEN_CTOR, VZ_HEIGHT_CENTER, VZ_PREFETCH, VZ_ASSEMBLE, -1},
        /*surfacegen_ctor*/ {-1},
        /*height_center*/   {-1},
        /*prefetch*/        {-1},
        /*height_query*/    {-1},
        /*assemble*/        {VZ_HEIGHT_QUERY, VZ_POOL_CREATE, VZ_JIGSAW_BLOCKS,
                             VZ_TEMPLATE_LIST, VZ_SIZE_LOOKUP, VZ_VOXEL_CHECK},
        /*pool_create*/     {-1},
        /*jigsaw_blocks*/   {-1},
        /*template_list*/   {-1},
        /*size_lookup*/     {-1},
        /*voxel_check*/     {-1},
    };

    printf("\n--- Profil par zone ---\n");
    printf("  %-17s %10s %8s %12s %10s %10s\n",
           "zone", "total ms", "%", "appels", "us/appel", "propre ms");

    std::vector<int> order;
    for (int z = 0; z < VZ_COUNT; z++) order.push_back(z);
    std::sort(order.begin(), order.end(), [](int a, int b) {
        return g_vprof.nanos[a] > g_vprof.nanos[b];
    });

    for (int z : order) {
        if (g_vprof.calls[z] == 0) continue;
        double ms = g_vprof.nanos[z] / 1e6;

        double childMs = 0.0;
        for (int i = 0; i < 6; i++) {
            int c = childrenOf[z][i];
            if (c < 0) break;
            childMs += g_vprof.nanos[c] / 1e6;
        }
        double own = ms - childMs;

        printf("  %-17s %10.1f %7.1f%% %12llu %10.2f %10.1f\n",
               vprofName(z), ms, wallMs > 0 ? 100.0 * ms / wallMs : 0.0,
               (unsigned long long)g_vprof.calls[z],
               g_vprof.calls[z] ? (g_vprof.nanos[z] / 1e3) / g_vprof.calls[z] : 0.0,
               own);
    }
    printf("\n  Les zones s'emboîtent : village_total contient assemble, qui contient\n"
           "  height_query et les autres. La colonne \"propre\" retire des zones\n"
           "  englobantes le temps de leurs sous-zones mesurées.\n");
}

#else   // VILLAGE_PROFILE non défini : tout disparaît

#define VPROF_SCOPE(zone) ((void)0)
inline void vprofReset() {}
inline void vprofReport(double) {}

#endif
