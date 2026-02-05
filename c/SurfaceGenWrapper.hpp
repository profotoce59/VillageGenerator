#pragma once

#include <cstdint>
#include <stdexcept>

// Inclure les headers C nécessaires
extern "C" {
    #include "cubiomes_integration.h"
    #include "surface_gen.h"
}

/**
 * Wrapper C++ pour utiliser SurfaceGen (code C) depuis le code C++ du générateur de villages
 */
class SurfaceGenWrapper {
public:
    /**
     * Constructeur : initialise le contexte cubiomes et SurfaceGen
     * @param worldSeed La seed du monde
     * @param mcVersion Version de Minecraft (ex: MC_1_16)
     */
    SurfaceGenWrapper(uint64_t worldSeed, int mcVersion = 2730); // MC_1_16 = 2730

    /**
     * Destructeur : libère les ressources
     */
    ~SurfaceGenWrapper();

    /**
     * Génère une colonne de terrain et trouve la première hauteur où le prédicat est vrai
     * Équivalent de generateColumnfromY en Java
     * @param x Coordonnée X du monde
     * @param z Coordonnée Z du monde
     * @param predicate Prédicat pour tester les blocs (nullptr = bloc non-air)
     * @return Hauteur Y où le prédicat est vrai (0 si non trouvé)
     */
    int generateColumnFromY(int x, int z, BlockPredicate predicate = nullptr);

    /**
     * Raccourci pour trouver la première hauteur avec un bloc solide selon WORLD_SURFACE_WG
     * (ignore les feuilles, fleurs, herbe, etc. comme en Java)
     * @param x Coordonnée X du monde
     * @param z Coordonnée Z du monde
     * @return Hauteur Y du premier bloc solide (WORLD_SURFACE_WG)
     */
    int getHeightOnGround(int x, int z);

    /**
     * Calcule la hauteur en scannant toute la colonne (startSizeY = noiseSizeY).
     * Utile pour reproduire getFirstHeightInColumn Java (non limité par startSizeY).
     */
    int getFirstHeightFull(int x, int z);

    /**
     * Debug ciblé: imprime depth/scale, randomOffset, startSizeY/noiseSizeY
     * et la colonne de bruit pour un range de y (indices de noise column).
     */
    void debugPrintNoiseColumn(int x, int z, int yStart, int yEnd);

    /**
     * Ajuste startSizeY (en blocs, comme Java: heightY + 25).
     * La valeur est convertie en cellules (division par 8) et ne peut que monter.
     */
    void setStartSizeY(int startSizeYBlocks);
    void setStartSizeYExact(int startSizeYBlocks);

    // Getter pour accès direct au SurfaceGen (pour tests)
    SurfaceGen* getSurfaceGen() { return sg; }

private:
    CubiomesContext* ctx;
    SurfaceGen* sg;

    // Prédicat par défaut : retourne true pour tout bloc non-air
    static int defaultNotAirPredicate(Block block, void* user);

    // Prédicat WORLD_SURFACE_WG : ignore les blocs décoratifs (pour la génération de villages)
    static int worldSurfaceWGPredicate(Block block, void* user);
};
