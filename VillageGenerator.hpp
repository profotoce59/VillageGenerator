#pragma once

#include <vector>
#include <deque>
#include <memory>
#include <string>
#include <map>
#include <random>

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

// Position structures
struct BPos {
    int x, y, z;
    
    BPos(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}
    
    BPos add(int dx, int dy, int dz) const {
        return BPos(x + dx, y + dy, z + dz);
    }
};

struct BlockBox {
    int minX, minY, minZ;
    int maxX, maxY, maxZ;
    
    BlockBox(int minX, int minY, int minZ, int maxX, int maxY, int maxZ)
        : minX(minX), minY(minY), minZ(minZ), maxX(maxX), maxY(maxY), maxZ(maxZ) {}
        
    bool contains(const BPos& pos) const;
    void move(int dx, int dy, int dz);
};

// Main VillageGenerator class
class VillageGenerator {
public:
    VillageGenerator();
    ~VillageGenerator();

    bool generate(TerrainGenerator* generator, int chunkX, int chunkZ, ChunkRand& rand);
    bool generate(TerrainGenerator* generator, int chunkX, int chunkZ, ChunkRand& rand, 
                 Biome* biomeWanted, bool useHeightMapOptimizer, bool towncenterOptimizer);

private:
    class Piece;
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