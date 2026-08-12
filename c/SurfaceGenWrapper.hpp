#pragma once

#include <cstdint>
#include <stdexcept>

// Inclure les headers C nécessaires
extern "C" {
    #include "cubiomes_integration.h"
    #include "surface_gen.h"
}

/**
 * Source de hauteurs pré-calculées, branchable de l'extérieur.
 *
 * La génération de village est un jigsaw séquentiel : la hauteur d'une pièce
 * détermine où sera la requête suivante, donc on ne peut pas grouper les
 * requêtes une par une. En revanche toutes les pièces d'un village tiennent
 * dans une zone bornée connue à l'avance, ce qui permet de calculer la
 * heightmap entière d'un coup (sur GPU par exemple) avant d'assembler.
 *
 * L'implémentation CUDA est dans c/cuda/cuda_height_provider.hpp ; sans
 * provider installé, tout retombe sur le chemin C habituel.
 */
class HeightProvider {
public:
    virtual ~HeightProvider() = default;

    /**
     * Pré-calcule les hauteurs (prédicat non-air) de la zone [x0, x0+w) x [z0, z0+h)
     * pour la configuration de `sg`. Renvoie un numéro de génération strictement
     * croissant, ou 0 en cas d'échec.
     */
    virtual uint64_t prefetch(SurfaceGen* sg, int x0, int z0, int w, int h) = 0;

    /** Numéro de la zone actuellement en mémoire. */
    virtual uint64_t currentGeneration() const = 0;

    /** Hauteur en (x, z), ou -1 si hors de la zone pré-calculée. */
    virtual int lookup(int x, int z) const = 0;
};

/**
 * Wrapper C++ pour utiliser SurfaceGen (code C) depuis le code C++ du générateur de villages
 */
class SurfaceGenWrapper {
public:
    /**
     * Installe le fournisseur de hauteurs partagé (non possédé, peut être nullptr).
     * Les SurfaceGenWrapper créés au fil de la génération le récupèrent
     * automatiquement — c'est nécessaire parce que l'Assembler fabrique son
     * propre wrapper en interne.
     */
    static void setHeightProvider(HeightProvider* provider);
    static HeightProvider* getHeightProvider();

    /**
     * Mode debug : recalcule chaque réponse du provider avec le chemin C et
     * signale les écarts sur stderr. Coûteux, réservé au diagnostic.
     */
    static void setVerifyProvider(bool enabled);

    /**
     * Mode debug : journalise chaque requête (x, z, hauteur, startSizeY) dans
     * le fichier indiqué. Diffusable entre deux runs pour localiser une
     * divergence. nullptr referme le fichier.
     */
    static void setQueryTrace(const char* path);

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
     * Version early-exit : calcule le bruit à la volée de haut en bas,
     * s'arrête dès qu'on trouve le premier bloc matchant.
     * Plus rapide que generateColumnFromY quand le bloc est haut (évite de calculer toute la colonne).
     */
    int generateColumnFromYEarlyExit(int x, int z, BlockPredicate predicate = nullptr);

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
    void resetHeightCache();

    /**
     * Demande au fournisseur installé de pré-calculer la zone indiquée.
     * Sans fournisseur, ne fait rien : le comportement reste identique au C pur.
     * À appeler après setStartSizeYExact(), dont dépend le résultat.
     */
    void prefetchRegion(int x0, int z0, int w, int h);

    // Getter pour accès direct au SurfaceGen (pour tests)
    SurfaceGen* getSurfaceGen() { return sg; }

    /**
     * Compteurs de requêtes, cumulés sur tout le processus.
     * Les instances de SurfaceGenWrapper sont créées et détruites au fil de la
     * génération (l'Assembler en fabrique une par village), donc des compteurs
     * d'instance seraient invisibles depuis l'extérieur.
     */
    struct Stats {
        uint64_t columnQueries;      // generateColumnFromY (inclut celles de getHeightOnGround)
        uint64_t groundQueries;      // getHeightOnGround (hors cache)
        uint64_t groundCacheHits;
        uint64_t columnNanos;        // temps cumulé dans generateColumnFromY
        int minX, maxX, minZ, maxZ;  // boîte englobante des positions interrogées
        uint64_t providerHits;       // requêtes servies par le HeightProvider
        uint64_t providerMisses;     // requêtes hors zone, retombées sur le C
    };
    static Stats getStats();
    static void resetStats();

private:
    CubiomesContext* ctx;
    SurfaceGen* sg;
    struct HeightEntry {
        int x;
        int z;
        int height;
        int valid;
    };
    static constexpr size_t HEIGHT_CACHE_CAP = 256;
    HeightEntry heightCache[HEIGHT_CACHE_CAP] = {};
    size_t heightCacheCursor = 0;
    size_t heightCacheHits = 0;
    size_t heightCacheMisses = 0;

    // Zone pré-calculée appartenant à CETTE instance. Le fournisseur est
    // partagé et ne garde qu'une zone : comparer le numéro de génération
    // évite de lire la zone d'un autre wrapper (même adresse réutilisée par
    // malloc, autre seed, autre startSizeY...).
    uint64_t prefetchGeneration = 0;

    // Prédicat par défaut : retourne true pour tout bloc non-air
    static int defaultNotAirPredicate(Block block, void* user);

    // Prédicat WORLD_SURFACE_WG : ignore les blocs décoratifs (pour la génération de villages)
    static int worldSurfaceWGPredicate(Block block, void* user);
};
