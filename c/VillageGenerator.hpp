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
    DESERT_CENTER,
    PLAIN_CENTER,
    TAIGA_CENTER,
    SAVANNA_CENTER,
    SNOWY_CENTER,

    // Maisons
    DESERT_HOUSES,
    PLAIN_HOUSES,
    TAIGA_HOUSES,
    SAVANNA_HOUSES,
    SNOWY_HOUSES,

    // Rues
    DESERT_STREETS,
    PLAIN_STREETS,
    TAIGA_STREETS,
    SAVANNA_STREETS,
    SNOWY_STREETS,

    // Décorations
    DESERT_DECOR,
    PLAIN_DECOR,
    TAIGA_DECOR,
    SAVANNA_DECOR,
    SNOWY_DECOR
};

// Forward declaration for VoxelShape
class VoxelShape;

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
        VoxelShape* voxelShape;

        Piece(const std::string& name, const BPos& pos, const BlockBox& box,
              BlockRotation rotation, PlacementBehaviour behaviour, int depth);
        ~Piece();

        void move(int dx, int dy, int dz);
        BPos getTransformedPos(const BPos& relativePos) const;
    };

    VillageGenerator();
    ~VillageGenerator();

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