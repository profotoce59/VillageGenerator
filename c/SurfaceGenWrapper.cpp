#include "SurfaceGenWrapper.hpp"
#include <cstdlib>
#include <new>
#include <iostream>

// Prédicat par défaut : retourne 1 (true) pour tout bloc non-air
int SurfaceGenWrapper::defaultNotAirPredicate(Block block, void* user) {
    (void)user;  // Paramètre non utilisé
    return (block != BLOCK_AIR) ? 1 : 0;
}

// Prédicat WORLD_SURFACE_WG : pour l'instant, identique au prédicat par défaut
// car notre génération de surface ne produit que STONE/WATER/AIR (pas de blocs décoratifs détaillés)
// La différence de 3 blocs vient probablement d'un décalage dans le calcul du bruit ou des coordonnées
int SurfaceGenWrapper::worldSurfaceWGPredicate(Block block, void* user) {
    (void)user;
    // Pour l'instant, même logique que defaultNotAirPredicate
    // TODO: Investiguer pourquoi nous obtenons Y=74 au lieu de Y=71
    return (block != BLOCK_AIR) ? 1 : 0;
}

SurfaceGenWrapper::SurfaceGenWrapper(uint64_t worldSeed, int mcVersion) {
    // Allouer le contexte cubiomes
    ctx = (CubiomesContext*)malloc(sizeof(CubiomesContext));
    if (!ctx) {
        throw std::bad_alloc();
    }

    // Initialiser cubiomes avec la seed et la version MC
    init_cubiomes_context(ctx, mcVersion, worldSeed);

    // Allouer et configurer SurfaceGen
    sg = (SurfaceGen*)calloc(1, sizeof(SurfaceGen));
    if (!sg) {
        free(ctx);
        throw std::bad_alloc();
    }

    setup_surface_gen_with_cubiomes(sg, ctx);
}

SurfaceGenWrapper::~SurfaceGenWrapper() {
    // Libérer le cache si nécessaire
    if (sg) {
        free_surface_cache(sg);
        free(sg);
    }
    if (ctx) {
        free(ctx);
    }
}

int SurfaceGenWrapper::generateColumnFromY(int x, int z, BlockPredicate predicate) {
    // Si aucun prédicat n'est fourni, utiliser le prédicat par défaut (non-air)
    if (!predicate) {
        predicate = defaultNotAirPredicate;
    }

    // Appeler la fonction C
    return generate_column_from_y(sg, x, z, predicate, sg);
}

int SurfaceGenWrapper::getHeightOnGround(int x, int z) {
    // Utiliser le prédicat WORLD_SURFACE_WG (comme en Java pour les villages)
    int height = generateColumnFromY(x, z, worldSurfaceWGPredicate);

    // DEBUG: Afficher la valeur brute
    static bool first_call = true;
    if (first_call) {
        std::cout << "  [DEBUG SurfaceGen] Hauteur brute à (" << x << ", " << z << "): " << height << std::endl;
        first_call = false;
    }

    // La hauteur est maintenant correcte après la correction de getDepthAndScale
    // (version MC corrigée à 19, lookup biome avec seaLevel=63, weight table corrigée)
    return height;
}
