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
    static BPos fromChunk(int chunkX, int y, int chunkZ) {
        return BPos(chunkX << 4, y, chunkZ << 4); // chunk * 16
    }
};

struct BlockBox {
    int minX, minY, minZ;
    int maxX, maxY, maxZ;
    
    BlockBox(int minX, int minY, int minZ, int maxX, int maxY, int maxZ)
        : minX(minX), minY(minY), minZ(minZ), maxX(maxX), maxY(maxY), maxZ(maxZ) {}
        
    bool contains(const BPos& pos) const;
    void move(int dx, int dy, int dz);
    // Décalage par un ancrage
    BlockBox offset(int dx, int dy, int dz) const {
        return BlockBox(minX + dx, minY + dy, minZ + dz,
                        maxX + dx, maxY + dy, maxZ + dz);
    }

    static inline BlockBox getBoundingBox(const BPos& anchor,
                                      BlockRotation rot,
                                      const BPos& size)
{
    BlockBox box = BlockBox(0, 0, 0, 0, 0, 0);

    switch (rot) {
        case BlockRotation::COUNTERCLOCKWISE_90: {
            int sx = size.z - 1;  // X <-> Z
            int sy = size.y - 1;
            int sz = size.x - 1;
            box = BlockBox(0, 0, -sz, sx, sy, 0);
            break;
        }

        case BlockRotation::CLOCKWISE_90: {
            int sx = size.z - 1;
            int sy = size.y - 1;
            int sz = size.x - 1;
            box = BlockBox(-sx, 0, 0, 0, sy, sz);
            break;
        }

        case BlockRotation::CLOCKWISE_180: {
            int sx = size.x - 1;
            int sy = size.y - 1;
            int sz = size.z - 1;
            box = BlockBox(-sx, 0, -sz, 0, sy, 0);
            break;
        }

        case BlockRotation::NONE:
        default: {
            int sx = size.x - 1;
            int sy = size.y - 1;
            int sz = size.z - 1;
            box = BlockBox(0, 0, 0, sx, sy, sz);
            break;
        }
    }

    return box.offset(anchor.x, anchor.y, anchor.z);
    }
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