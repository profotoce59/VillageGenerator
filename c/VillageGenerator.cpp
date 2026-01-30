#include "VillageGenerator.hpp"
#include "VillagePools.hpp"
#include "BlockRotation.hpp"
#include "VoxelShape.hpp"
#include "Biome.hpp"
#include "ChunkRand.hpp"
#include "TerrainGenerator.hpp"
#include "village_structure_size.hpp"
#include "BiomeSource.hpp"
#include "JigSawPool.hpp"
#include <algorithm>
#include <stdexcept>


// BlockBox implementation
bool BlockBox::contains(const BPos& pos) const {
    return pos.x >= minX && pos.x <= maxX &&
           pos.y >= minY && pos.y <= maxY &&
           pos.z >= minZ && pos.z <= maxZ;
}

void BlockBox::move(int dx, int dy, int dz) {
    minX += dx; maxX += dx;
    minY += dy; maxY += dy;
    minZ += dz; maxZ += dz;
}

// VillageGenerator implementation
class VillageGenerator::Piece {
public:
    std::string name;
    BPos pos;
    BlockBox box;
    BlockRotation rotation;
    int depth;
    PlacementBehaviour placementBehaviour;
    VoxelShape voxelShape;
    
    Piece(const std::string& name, const BPos& pos, const BlockBox& box, 
          BlockRotation rotation, PlacementBehaviour behaviour, int depth)
        : name(name), pos(pos), box(box), rotation(rotation), 
          depth(depth), placementBehaviour(behaviour) {
        voxelShape = VoxelShape(box);
    }
        
    void move(int dx, int dy, int dz) {
        box.move(dx, dy, dz);
        pos = pos.add(dx, dy, dz);
    }

    BPos getTransformedPos(const BPos& relativePos) const {
        return BlockRotationHelper::rotate(relativePos, rotation);
    }
};

class VillageGenerator::Assembler {
public:
    Assembler(int maxDepth, TerrainGenerator* generator, std::vector<std::unique_ptr<Piece>>& pieces,
             bool useHeightMapOptimizer)
        : maxDepth(maxDepth), generator(generator), pieces(pieces),
          useHeightMapOptimizer(useHeightMapOptimizer) {}
          
    void tryPlacing(VillageType villageType, Piece* piece, ChunkRand& rand, bool expansionHack) {
        // Obtenir le pool correspondant au type de village
        auto pool = createVillagePool(villageType);
        if (!pool) return;

        // Pour chaque direction possible
        for (int dir = 0; dir < 4; ++dir) {
            BlockDirection direction = static_cast<BlockDirection>(dir);
            
            // Obtenir la position relative dans cette direction
            BPos dirVector = BlockRotationHelper::getDirectionVector(direction);
            BPos relativePos = piece->pos.add(
                dirVector.x * 5,
                dirVector.y * 5,
                dirVector.z * 5
            );

            // Vérifier si on peut placer une pièce ici
            if (canPlacePieceHere(relativePos, piece->box)) {
                // Choisir une pièce aléatoire du pool approprié
                PoolType poolType;
                switch (dir) {
                    case 0: poolType = PoolType::DESERT_HOUSES; break;  // Nord
                    case 1: poolType = PoolType::DESERT_STREETS; break; // Sud
                    case 2: poolType = PoolType::DESERT_DECOR; break;   // Est
                    case 3: poolType = PoolType::DESERT_HOUSES; break;  // Ouest
                    default: continue;
                }

                auto templates = pool->getTemplates(poolType);
                if (templates.empty()) continue;

                // Sélectionner un template aléatoire
                std::string templateName = selectRandomTemplate(templates, rand.getRNG());
                if (templateName.empty()) continue;

                // Créer la nouvelle pièce
                BlockRotation newRotation = BlockRotationHelper::getRandom(rand.getRNG());
                auto newBox = createBoundingBox(relativePos, newRotation, templateName);
                
                auto newPiece = std::make_unique<Piece>(
                    templateName,
                    relativePos,
                    newBox,
                    newRotation,
                    pool->getPlacementBehaviour(),
                    piece->depth + 1
                );

                // Vérifier la hauteur et les collisions
                if (isValidPlacement(newPiece.get())) {
                    pieces.push_back(std::move(newPiece));
                }
            }
        }
    }
    
private:
    int maxDepth;
    TerrainGenerator* generator;
    std::vector<std::unique_ptr<Piece>>& pieces;
    bool useHeightMapOptimizer;
    std::deque<Piece*> placing;

    std::string selectRandomTemplate(const std::vector<TemplateEntry>& templates, std::mt19937_64& rng) {
        if (templates.empty()) return "";
        std::uniform_int_distribution<size_t> dist(0, templates.size() - 1);
        return templates[dist(rng)].name;
    }

    bool canPlacePieceHere(const BPos& pos, const BlockBox& existingBox) const {
        // Vérifier la distance avec la pièce existante
        int dx = pos.x - existingBox.minX;
        int dz = pos.z - existingBox.minZ;
        return (dx * dx + dz * dz) >= 16;  // Distance minimale
    }

    bool isValidPlacement(const Piece* piece) const {
        // Vérifier les collisions avec les pièces existantes
        for (const auto& existingPiece : pieces) {
            if (piece->voxelShape.intersects(existingPiece->box)) {
                return false;
            }
        }

        // Vérifier la hauteur du terrain
        if (useHeightMapOptimizer) {
            int groundHeight = generator->getHeightOnGround(piece->pos.x, piece->pos.z);
            return std::abs(piece->pos.y - groundHeight) <= 5;
        }

        return true;
    }

    BlockBox createBoundingBox(const BPos& pos, BlockRotation rotation, const std::string& templateName) {
        // TODO: Implémenter la création de la boîte englobante en fonction du template
        return BlockBox(pos.x - 5, pos.y - 5, pos.z - 5,
                       pos.x + 5, pos.y + 5, pos.z + 5);
    }
};

VillageGenerator::VillageGenerator()
    : useHeightMapOptimizer(true), generated(false), superflat(false), towncenterOptimizer(false) {
}

VillageGenerator::~VillageGenerator() = default;

bool VillageGenerator::generate(TerrainGenerator* generator, int chunkX, int chunkZ, ChunkRand& rand) {
    pieces.clear();
    generated = false;

    // 1) Biome and villageType resolution (do this earlier if you already have it)
    Biome* biome = generator->getBiomeSource()->getBiomeForNoiseGen((chunkX << 2) + 2, 0, (chunkZ << 2) + 2);
    villageType = VillageType::getType(biome);
    if (villageType == VillageType::UNKNOWN /* or however you signal null */) return false;

    // 2) canStart / canSpawn / canGenerate (mirror Java checks if you have them)
    // if (!Village::canStart(...)) return false;
    // if (!superflat && !Village::canSpawn(chunkX, chunkZ, generator->getBiomeSource())) return false;
    // if (!superflat && !Village::canGenerate(chunkX, chunkZ, generator)) return false;

    // 3) Seed rotation the Minecraft way
    rand.setCarverSeed(generator->getWorldSeed(), chunkX, chunkZ);
    BlockRotation rotation = BlockRotationHelper::getRandom(rand.getRNG());

    // 4) START pool + random template
    
    const JigSawPool& pool = STARTS.at(villageType);
    String template = rand.getRandom(jigSawPool.getTemplates());

    std::string templateName = startPool.getRandom(rand.getRNG());
    if (templateName.empty()) return false;

    // // Optional filter like in Java (to bias to max streets, etc.)
    // if (templateName != "desert/town_centers/desert_meeting_point_2") return false;

    // 5) Template size and world-space bounding box
    BPos size;
    get_bpos(templateName.c_str(), &size);

    BPos bPos = BPos::fromChunk(chunkX, 0, chunkZ);
    BlockBox box = BlockBox::getBoundingBox(bPos, rotation, size);

    int centerX = (box.minX + box.maxX) / 2;
    int centerZ = (box.minZ + box.maxZ) / 2;

    // 6) Ground Y from WORLD_SURFACE_WG and vertical alignment like Java
    int heightY = generator->getFirstHeightInColumn(centerX, centerZ, Surface::WORLD_SURFACE_WG);
    int y       = bPos.y + heightY;
    int centerY = box.minY + 1;

    // 7) First piece (always RIGID), moved to Y and bounded
    auto piece = std::make_unique<Piece>(
        templateName, bPos, box, rotation, PlacementBehaviour::RIGID, /*depth=*/0
    );
    piece->move(0, y - centerY, 0);

    // 8) Full village box (±80 in each axis) like Java
    BlockBox fullBox{
        centerX - 80, y - 80, centerZ - 80,
        centerX + 80 + 1, y + 80 + 1, centerZ + 80 + 1
    };
    // Configurer l'assembleur et générer le village
    Assembler assembler(6, generator, pieces, useHeightMapOptimizer);
    assembler.tryPlacing(villageType, piece.get(), rand, true);
    pieces.push_back(std::move(piece));
    
    generated = true;
    return true;
}

bool VillageGenerator::generate(TerrainGenerator* generator, int chunkX, int chunkZ, ChunkRand& rand,
                              Biome* biomeWanted, bool useHeightMapOptimizer, bool towncenterOptimizer) {
    this->useHeightMapOptimizer = useHeightMapOptimizer;
    this->towncenterOptimizer = towncenterOptimizer;
    
    // Vérifier le biome
    if (biomeWanted) {
        Biome* currentBiome = generator->getBiomeSource()->getBiomeForNoiseGen(chunkX * 4 + 2, 0, chunkZ * 4 + 2);
        if (currentBiome != biomeWanted) {
            return false;
        }
    }
    
    return generate(generator, chunkX, chunkZ, rand);
}

bool VillageGenerator::getGoodMeetingPoint(Biome* biome, const std::string& template_name) {
    if (!biome) return false;

    // Vérifier si le template est approprié pour le biome
    if (biome->getType() == Biome::Type::DESERT) {
        return template_name == "desert/town_centers/desert_meeting_point_2";
    }
    else if (biome->getType() == Biome::Type::PLAINS) {
        return template_name == "plains/town_centers/plains_meeting_point_2";
    }
    else if (biome->getType() == Biome::Type::TAIGA) {
        return template_name == "taiga/town_centers/taiga_meeting_point_2";
    }
    else if (biome->getType() == Biome::Type::SNOWY_TUNDRA) {
        return true;
    }
    else if (biome->getType() == Biome::Type::SAVANNA) {
        return template_name != "savanna/town_centers/savanna_meeting_point_1";
    }

    return false;
} 