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
#include <mutex>
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
    VZ_BIOME_FILTER,      // lecture du biome pour le filtre de recherche
    VZ_ATTACH_LOOP,       // boucle canAttach15 + placement sur list1
    VZ_COUNT
};

// Compteurs bruts (pas du temps), pour dimensionner une optimisation avant
// de l'ecrire.
enum VProfTally {
    VT_ATTACH_LOOPS = 0,   // entrees dans la boucle d'attache
    VT_ATTACH_EMPTY,       // ... qui n'ont trouve aucune attache
    VT_ATTACH_ENTRIES,     // entrees de list1 parcourues au total
    VT_TALLY_COUNT
};

struct VProfCounters {
    uint64_t nanos[VZ_COUNT];
    uint64_t calls[VZ_COUNT];
    uint64_t tally[VT_TALLY_COUNT];
};

// Un bloc de compteurs par thread, enregistré dans une liste globale.
// Incrémenter un compteur global depuis plusieurs threads serait à la fois
// faux (course) et lent (ligne de cache partagée) : ici chaque thread écrit
// dans son bloc, et vprofReport() somme le tout à la fin.
namespace vprof_detail {
inline std::mutex& listMutex() { static std::mutex m; return m; }
inline std::vector<VProfCounters*>& blocks() {
    static std::vector<VProfCounters*> v; return v;
}
} // namespace vprof_detail

inline VProfCounters& vprofLocal() {
    thread_local VProfCounters* tls = nullptr;
    if (!tls) {
        tls = new VProfCounters{};
        std::lock_guard<std::mutex> lk(vprof_detail::listMutex());
        vprof_detail::blocks().push_back(tls);
    }
    return *tls;
}

inline VProfCounters vprofTotal() {
    VProfCounters t{};
    std::lock_guard<std::mutex> lk(vprof_detail::listMutex());
    for (const VProfCounters* b : vprof_detail::blocks())
    {
        for (int z = 0; z < VZ_COUNT; z++) {
            t.nanos[z] += b->nanos[z];
            t.calls[z] += b->calls[z];
        }
        for (int i = 0; i < VT_TALLY_COUNT; i++) t.tally[i] += b->tally[i];
    }
    return t;
}

inline const char* vprofName(int z) {
    static const char* n[VZ_COUNT] = {
        "world_setup", "viable_check", "village_total", "surfacegen_ctor",
        "height_center", "prefetch", "height_query", "assemble",
        "pool_create", "jigsaw_blocks", "template_list", "size_lookup",
        "voxel_check", "biome_filter", "attach_loop"
    };
    return n[z];
}

class VProfScope {
public:
    explicit VProfScope(VProfZone z)
        : zone_(z), t0_(std::chrono::steady_clock::now()) {}
    ~VProfScope() {
        auto dt = std::chrono::steady_clock::now() - t0_;
        VProfCounters& c = vprofLocal();
        c.nanos[zone_] +=
            (uint64_t)std::chrono::duration_cast<std::chrono::nanoseconds>(dt).count();
        c.calls[zone_]++;
    }
private:
    VProfZone zone_;
    std::chrono::steady_clock::time_point t0_;
};

#define VPROF_CONCAT2(a, b) a##b
#define VPROF_CONCAT(a, b) VPROF_CONCAT2(a, b)
#define VPROF_SCOPE(zone) VProfScope VPROF_CONCAT(vprof_, __LINE__)(zone)
#define VPROF_TALLY(t) (void)(vprofLocal().tally[t]++)

inline void vprofReset() {
    std::lock_guard<std::mutex> lk(vprof_detail::listMutex());
    for (VProfCounters* b : vprof_detail::blocks()) *b = VProfCounters{};
}

/**
 * Affiche le détail, trié par temps décroissant.
 * `wallMs` sert de dénominateur pour les pourcentages.
 *
 * Attention à la lecture : les zones s'emboîtent (village_total contient
 * assemble, qui contient height_query...). Les pourcentages ne s'additionnent
 * donc pas à 100 %. La colonne "propre" retire des zones englobantes le temps
 * de leurs sous-zones connues.
 */
inline void vprofReport(double wallMs, int threads = 1) {
    const VProfCounters g_vprof = vprofTotal();
    // Sous-zones directes de chaque zone englobante, pour le temps propre.
    static const int childrenOf[VZ_COUNT][6] = {
        /*world_setup*/     {-1},
        /*viable_check*/    {-1},
        /*village_total*/   {VZ_SURFACEGEN_CTOR, VZ_HEIGHT_CENTER, VZ_PREFETCH, VZ_ASSEMBLE, -1},
        /*surfacegen_ctor*/ {-1},
        /*height_center*/   {-1},
        /*prefetch*/        {-1},
        /*height_query*/    {-1},
        /*assemble*/        {VZ_POOL_CREATE, VZ_JIGSAW_BLOCKS,
                             VZ_TEMPLATE_LIST, VZ_SIZE_LOOKUP, VZ_ATTACH_LOOP, -1},
        /*pool_create*/     {-1},
        /*jigsaw_blocks*/   {-1},
        /*template_list*/   {-1},
        /*size_lookup*/     {-1},
        /*voxel_check*/     {-1},
        /*biome_filter*/    {-1},
        /*attach_loop*/     {VZ_VOXEL_CHECK, VZ_HEIGHT_QUERY, -1},
    };

    // Avec N threads, les zones cumulent du temps de N threads en parallèle :
    // le dénominateur pertinent est wallMs * threads, pas wallMs.
    const double budgetMs = wallMs * (threads > 0 ? threads : 1);
    printf("\n--- Profil par zone (%d thread%s, budget %.0f ms de temps-thread) ---\n",
           threads, threads > 1 ? "s" : "", budgetMs);
    printf("  %-17s %10s %8s %12s %10s %10s\n",
           "zone", "total ms", "%budget", "appels", "us/appel", "propre ms");

    std::vector<int> order;
    for (int z = 0; z < VZ_COUNT; z++) order.push_back(z);
    std::sort(order.begin(), order.end(), [&](int a, int b) {
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
               vprofName(z), ms, budgetMs > 0 ? 100.0 * ms / budgetMs : 0.0,
               (unsigned long long)g_vprof.calls[z],
               g_vprof.calls[z] ? (g_vprof.nanos[z] / 1e3) / g_vprof.calls[z] : 0.0,
               own);
    }
    {
        const uint64_t loops   = g_vprof.tally[VT_ATTACH_LOOPS];
        const uint64_t empty   = g_vprof.tally[VT_ATTACH_EMPTY];
        const uint64_t entries = g_vprof.tally[VT_ATTACH_ENTRIES];
        if (loops) {
            printf("\n--- Boucle d'attache ---\n");
            printf("  entrees dans la boucle       : %llu\n", (unsigned long long)loops);
            printf("  sans aucune attache trouvee  : %llu  (%.1f %%)\n",
                   (unsigned long long)empty, 100.0 * empty / loops);
            printf("  entrees de list1 parcourues  : %llu  (%.1f par boucle)\n",
                   (unsigned long long)entries, (double)entries / loops);
        }
    }

    printf("\n  Les zones s'emboîtent : village_total contient assemble, qui contient\n"
           "  height_query et les autres. La colonne \"propre\" retire des zones\n"
           "  englobantes le temps de leurs sous-zones mesurées.\n");
}

#else   // VILLAGE_PROFILE non défini : tout disparaît

#define VPROF_SCOPE(zone) ((void)0)
#define VPROF_TALLY(t) ((void)0)
inline void vprofReset() {}
inline void vprofReport(double, int = 1) {}

#endif
