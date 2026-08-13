#pragma once

#include <vector>
#include <deque>
#include <memory>
#include <string>
#include <map>
#include <random>
#include "BlockStructures.hpp"
#include "BlockRotation.hpp"

// Forward declarations
class TerrainGenerator;
class ChunkRand;
class Biome;

// Enums
enum class VillageType {
    DESERT,
    PLAINS,
    TAIGA,
    SAVANNA,
    SNOWY,
    LEGACY
};

enum class PlacementBehaviour {
    RIGID,
    TERRAIN_MATCHING
};

enum class PoolType {
    // Centres de village
    ANIMALS,
    SHEEPS,
    CATS,
    BUTCHER_ANIMAL,
    IRON_GOLEM,
    WELL_BOTTOM,
    EMPTY,

    PLAIN_CENTER,
    PLAIN_STREET,
    PLAIN_ZSTREET,
    PLAIN_HOUSES,
    PLAIN_ZHOUSES,
    PLAIN_DECOR,
    PLAIN_ZDECOR,
    PLAIN_VILLAGER,
    PLAIN_ZVILLAGER,
    PLAIN_TERMINATOR,
    PLAIN_TREE,

    DESERT_CENTER,
    DESERT_STREET,
    DESERT_ZSTREET,
    DESERT_HOUSES,
    DESERT_ZHOUSES,
    DESERT_DECOR,
    DESERT_ZDECOR,
    DESERT_VILLAGER,
    DESERT_ZVILLAGER,
    DESERT_TERMINATOR,
    DESERT_ZTERMINATOR,

    TAIGA_CENTER,
    TAIGA_STREET,
    TAIGA_ZSTREET,
    TAIGA_HOUSES,
    TAIGA_ZHOUSES,
    TAIGA_DECOR,
    TAIGA_ZDECOR,
    TAIGA_VILLAGER,
    TAIGA_ZVILLAGER,
    TAIGA_TERMINATOR,


    SAVANNA_CENTER,
    SAVANNA_STREET,
    SAVANNA_ZSTREET,
    SAVANNA_HOUSES,
    SAVANNA_ZHOUSES,
    SAVANNA_DECOR,
    SAVANNA_ZDECOR,
    SAVANNA_VILLAGER,
    SAVANNA_ZVILLAGER,
    SAVANNA_TERMINATOR,
    SAVANNA_ZTERMINATOR,
    SAVANNA_TREE,

    SNOWY_CENTER,
    SNOWY_STREET,
    SNOWY_ZSTREET,
    SNOWY_HOUSES,
    SNOWY_ZHOUSES,
    SNOWY_DECOR,
    SNOWY_ZDECOR,
    SNOWY_VILLAGER,
    SNOWY_ZVILLAGER,
    SNOWY_TERMINATOR,
    SNOWY_TREE,
};

// Forward declaration for VoxelShape
class VoxelShape;

// Info d'un bloc jigsaw (point d'attache) – comme Java BlockJigsawInfo
//
// jointName pointe dans les tables statiques de c/jigsaw/*.hpp, jamais dans une
// chaîne temporaire. C'était un std::string : ces structures sont construites
// et mélangées des millions de fois par village, et les constructions/échanges
// de chaînes dominaient le profil. La comparaison reste une comparaison de
// valeur (cf. canAttach15), le comportement est inchangé.
struct BlockJigsawInfo {
    PoolType poolType;
    const char* jointName;
    BPos pos;           // position monde (après rotation + offset)
    BlockDirection front;

    bool canAttach15(const BlockJigsawInfo& other) const;
};

// Main VillageGenerator class
class VillageGenerator {
public:
    // Piece class definition - public so external code can access members
    class Piece {
    public:
        std::string name;
        BPos pos;
        BlockBox box;
        BlockRotation rotation;
        int depth;
        PlacementBehaviour placementBehaviour;
        int boundsTop = 0;

        Piece(const std::string& name, const BPos& pos, const BlockBox& box,
              BlockRotation rotation, PlacementBehaviour behaviour, int depth);
        ~Piece() = default;

        void move(int dx, int dy, int dz);
        void setBoundsTop(int y) { boundsTop = y; }
        BPos getTransformedPos(const BPos& relativePos) const;
    };

    VillageGenerator();
    ~VillageGenerator();

    /**
     * Rayon (en blocs, autour du centre du village) de la zone de hauteurs
     * pré-calculée sur GPU. 0 = toute la zone bornée du VoxelShape (défaut).
     *
     * Mesuré sur 399 villages : les requêtes ne lisent que ~229 colonnes alors
     * qu'on en calcule ~2143, et 94,9 % d'entre elles tiennent dans un rayon de
     * 64 blocs. Réduire le rayon échange du temps GPU (ressource saturée) contre
     * quelques replis sur le chemin C (ressource abondante).
     * Les hauteurs restent identiques : hors zone, on retombe simplement sur le C.
     */
    static void setPrefetchRadius(int blocks);
    static int  getPrefetchRadius();

    bool generate(TerrainGenerator* generator, int chunkX, int chunkZ, ChunkRand& rand);
    bool generate(TerrainGenerator* generator, int chunkX, int chunkZ, ChunkRand& rand,
                 Biome* biomeWanted, bool useHeightMapOptimizer, bool towncenterOptimizer);

    // Accessor for pieces
    const std::vector<std::unique_ptr<Piece>>& getPieces() const { return pieces; }

private:
    class Assembler;

    std::vector<std::unique_ptr<Piece>> pieces;
    VillageType villageType;
    bool useHeightMapOptimizer;
    bool generated;
    bool superflat;
    bool towncenterOptimizer;

    bool getGoodMeetingPoint(Biome* biome, const std::string& template_name);

    // Internal helper classes will be defined in the cpp file
}; 
