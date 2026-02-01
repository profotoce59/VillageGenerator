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
#include <iostream>

// Helper function to convert Biome type to Village type
static VillageType biomeToVillageType(const Biome* biome) {
    if (!biome) return VillageType::PLAINS;  // default

    switch (biome->getType()) {
        case Biome::Type::DESERT:
            return VillageType::DESERT;
        case Biome::Type::PLAINS:
            return VillageType::PLAINS;
        case Biome::Type::TAIGA:
            return VillageType::TAIGA;
        case Biome::Type::SAVANNA:
            return VillageType::SAVANNA;
        case Biome::Type::SNOWY_TUNDRA:
            return VillageType::SNOWY;
        default:
            return VillageType::PLAINS;
    }
}

// BlockRotationHelper implementation for ChunkRand
BlockRotation BlockRotationHelper::getRandom(ChunkRand& rand) {
    int value = rand.nextInt(4);
    switch (value) {
        case 0: return BlockRotation::NONE;
        case 1: return BlockRotation::CLOCKWISE_90;
        case 2: return BlockRotation::CLOCKWISE_180;
        case 3: return BlockRotation::COUNTERCLOCKWISE_90;
        default: return BlockRotation::NONE;
    }
}

// VillageGenerator::Piece implementation
VillageGenerator::Piece::Piece(const std::string& name, const BPos& pos, const BlockBox& box,
                                BlockRotation rotation, PlacementBehaviour behaviour, int depth)
    : name(name), pos(pos), box(box), rotation(rotation),
      depth(depth), placementBehaviour(behaviour), voxelShape(nullptr) {
    voxelShape = new VoxelShape(box);
}

VillageGenerator::Piece::~Piece() {
    delete voxelShape;
}

void VillageGenerator::Piece::move(int dx, int dy, int dz) {
    box.move(dx, dy, dz);
    pos = pos.add(dx, dy, dz);
}

BPos VillageGenerator::Piece::getTransformedPos(const BPos& relativePos) const {
    return BlockRotationHelper::rotate(relativePos, rotation);
}

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

                // Sélectionner un template aléatoire (for now, just pick randomly using nextInt)
                if (templates.empty()) continue;
                int idx = rand.nextInt(templates.size());
                std::string templateName = templates[idx].name;
                if (templateName.empty()) continue;

                // Créer la nouvelle pièce
                BlockRotation newRotation = BlockRotationHelper::getRandom(rand);
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
            if (piece->voxelShape && piece->voxelShape->intersects(existingPiece->box)) {
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

    // 1) Biome and villageType resolution
    Biome* biome = nullptr;
    if (generator->getBiomeSource()) {
        biome = generator->getBiomeSource()->getBiomeForNoiseGen((chunkX << 2) + 2, 0, (chunkZ << 2) + 2);
    }
    villageType = biomeToVillageType(biome);

    // 2) Seed rotation the Minecraft way
    rand.setCarverSeed(generator->getWorldSeed(), chunkX, chunkZ);
    BlockRotation rotation = BlockRotationHelper::getRandom(rand);

    // 3) Get start pool for this village type
    // For now, create a simple desert town center as placeholder
    // TODO: Use STARTS map when it's properly defined
    std::string templateName = "desert/town_centers/desert_meeting_point_2";

    // 4) Template size and world-space bounding box
    BPos size;
    get_bpos(templateName.c_str(), &size);

    BPos bPos = BPos::fromChunk(chunkX, 0, chunkZ);
    BlockBox box = BlockBox::getBoundingBox(bPos, rotation, size);

    int centerX = (box.minX + box.maxX) / 2;
    int centerZ = (box.minZ + box.maxZ) / 2;

    // 5) Ground Y using height map
    int heightY = generator->getHeightOnGround(centerX, centerZ);
    int y = bPos.y + heightY;
    int centerY = box.minY + 1;

    // DEBUG: Print height calculation details
    std::cout << "DEBUG Height Calculation:" << std::endl;
    std::cout << "  centerX, centerZ: " << centerX << ", " << centerZ << std::endl;
    std::cout << "  heightY (from getHeightOnGround): " << heightY << std::endl;
    std::cout << "  bPos.y: " << bPos.y << std::endl;
    std::cout << "  y (bPos.y + heightY): " << y << std::endl;
    std::cout << "  Initial box.minY: " << box.minY << std::endl;
    std::cout << "  centerY (box.minY + 1): " << centerY << std::endl;
    std::cout << "  Movement delta (y - centerY): " << (y - centerY) << std::endl;

    // 6) First piece (always RIGID), moved to Y
    auto piece = std::make_unique<Piece>(
        templateName, bPos, box, rotation, PlacementBehaviour::RIGID, /*depth=*/0
    );
    piece->move(0, y - centerY, 0);

    std::cout << "  Final piece pos.y: " << piece->pos.y << std::endl;
    std::cout << "  Final box.minY: " << piece->box.minY << std::endl;

    // 7) Configure assembler and generate village
    pieces.push_back(std::move(piece));

    // TODO: Actually run the assembler to add more pieces
    // Assembler assembler(6, generator, pieces, useHeightMapOptimizer);
    // assembler.tryPlacing(villageType, pieces[0].get(), rand, true);

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