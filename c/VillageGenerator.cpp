#include "VillageGenerator.hpp"
#include <iostream>
#include "VillagePools.hpp"
#include "BlockRotation.hpp"
#include "VoxelShape.hpp"
#include "VillagePoolYMax.hpp"
#include "Biome.hpp"
#include "ChunkRand.hpp"
#include "TerrainGenerator.hpp"
#include "village_structure_size.hpp"
#include "BiomeSource.hpp"
#include "JigSawPool.hpp"
#include "SurfaceGenWrapper.hpp"
#include <algorithm>
#include <stdexcept>

// JigsawBlocks data - inclure avant les headers générés
struct JigsawBlockEntry {
    PoolType poolType;
    const char* jointName;
    BlockDirection front;
    BlockDirection top;
    int16_t x, y, z;
};
#define JIGSAW_BLOCK_ENTRY_DEFINED

#include "jigsaw/DesertVillageJigsawBlocks.hpp"
#include "jigsaw/PlainsVillageJigsawBlock.hpp"
#include "jigsaw/TaigaVillageJigsawBlocks.hpp"
#include "jigsaw/SavannaVillageJigsawBlocks.hpp"
#include "jigsaw/SnowyVillageJigsawBlocks.hpp"

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
      depth(depth), placementBehaviour(behaviour) {
}

void VillageGenerator::Piece::move(int dx, int dy, int dz) {
    box.move(dx, dy, dz);
    pos = pos.add(dx, dy, dz);
}

BPos VillageGenerator::Piece::getTransformedPos(const BPos& relativePos) const {
    return BlockRotationHelper::rotate(relativePos, rotation);
}

// BlockJigsawInfo::canAttach15 – comme Java (direction opposée + même jointName)
bool BlockJigsawInfo::canAttach15(const BlockJigsawInfo& other) const {
    return BlockRotationHelper::getOpposite(other.front) == front
        && jointName == other.jointName;
}

// BlockRotationHelper::getShuffled – Java BlockRotation.getShuffled(rand)
std::vector<BlockRotation> BlockRotationHelper::getShuffled(ChunkRand& rand) {
    std::vector<BlockRotation> rots = {
        BlockRotation::NONE, BlockRotation::CLOCKWISE_90,
        BlockRotation::CLOCKWISE_180, BlockRotation::COUNTERCLOCKWISE_90
    };
    rand.shuffle(rots);
    return rots;
}

// Entrée jigsaw brute (template → liste (poolType, jointName, localPos, front))
struct JigsawEntry {
    PoolType poolType;
    std::string jointName;
    BPos localPos;
    BlockDirection front;
};

static std::vector<JigsawEntry> getJigsawBlocksForTemplate(const std::string& name, VillageType villageType) {
    const JigsawBlockEntry* data = nullptr;
    size_t count = 0;
    bool found = false;

    switch (villageType) {
        case VillageType::DESERT:
            found = getDesertVillageJigsawBlocksFast(name, data, count);
            break;
        case VillageType::PLAINS:
            found = getPlainsVillageJigsawBlockFast(name, data, count);
            break;
        case VillageType::TAIGA:
            found = getTaigaVillageJigsawBlocksFast(name, data, count);
            break;
        case VillageType::SAVANNA:
            found = getSavannaVillageJigsawBlocksFast(name, data, count);
            break;
        case VillageType::SNOWY:
            found = getSnowyVillageJigsawBlocksFast(name, data, count);
            break;
        default:
            break;
    }

    std::vector<JigsawEntry> out;
    if (found && data) {
        out.reserve(count);
        for (size_t i = 0; i < count; i++) {
            out.push_back({
                data[i].poolType,
                data[i].jointName,
                BPos(data[i].x, data[i].y, data[i].z),
                data[i].front
            });
        }
    }
    return out;
}

static std::vector<BlockJigsawInfo> getShuffledJigsawBlocks(
    const VillageGenerator::Piece* piece, VillageType villageType, ChunkRand& rand)
{
    std::vector<JigsawEntry> entries = getJigsawBlocksForTemplate(piece->name, villageType);
    std::vector<BlockJigsawInfo> list;
    list.reserve(entries.size());
    for (const auto& e : entries) {
        BPos rotated = BlockRotationHelper::rotate(e.localPos, piece->rotation);
        BPos worldPos = piece->pos.add(rotated.x, rotated.y, rotated.z);
        BlockDirection worldFront = BlockRotationHelper::rotate(e.front, piece->rotation);
        list.push_back({e.poolType, e.jointName, worldPos, worldFront});
    }
    rand.shuffle(list);
    return list;
}

static PoolType getFallbackPoolType(VillageType villageType, PoolType jointType) {
    (void)villageType;
    switch (jointType) {
        case PoolType::PLAIN_STREET:
        case PoolType::PLAIN_HOUSES:
        case PoolType::PLAIN_ZSTREET:
        case PoolType::PLAIN_ZHOUSES:
            return PoolType::PLAIN_TERMINATOR;
        case PoolType::DESERT_STREET:
        case PoolType::DESERT_HOUSES:
            return PoolType::DESERT_TERMINATOR;
        case PoolType::DESERT_ZSTREET:
        case PoolType::DESERT_ZHOUSES:
            return PoolType::DESERT_ZTERMINATOR;
        case PoolType::TAIGA_STREET:
        case PoolType::TAIGA_HOUSES:
        case PoolType::TAIGA_ZSTREET:
        case PoolType::TAIGA_ZHOUSES:
            return PoolType::TAIGA_TERMINATOR;
        case PoolType::SAVANNA_STREET:
        case PoolType::SAVANNA_HOUSES:
            return PoolType::SAVANNA_TERMINATOR;
        case PoolType::SAVANNA_ZSTREET:
        case PoolType::SAVANNA_ZHOUSES:
            return PoolType::SAVANNA_ZTERMINATOR;
        case PoolType::SNOWY_STREET:
        case PoolType::SNOWY_HOUSES:
        case PoolType::SNOWY_ZSTREET:
        case PoolType::SNOWY_ZHOUSES:
            return PoolType::SNOWY_TERMINATOR;
        default:
            return PoolType::EMPTY;
    }
}

// Java isNotEmpty(mutableobject1, box3) → true si on peut placer
// Vérifie: 1) la pièce est dans les bounds du village, 2) pas de collision
static bool isNotEmpty(const VoxelShape* vs, const BlockBox& box) {
    if (!vs || vs->isNull()) return true;

    // Vérifier les bounds (comme Java: box doit être DANS le VoxelShape)
    if (vs->hasBounds) {
        if (box.minX < vs->bounds.minX || box.minY < vs->bounds.minY || box.minZ < vs->bounds.minZ ||
            box.maxX >= vs->bounds.maxX || box.maxY >= vs->bounds.maxY || box.maxZ >= vs->bounds.maxZ) {
            return false;
        }
    }

    // Vérifier les collisions avec les pièces existantes
    return !vs->intersects(box);
}

class VillageGenerator::Assembler {
public:
    Assembler(int maxDepth, TerrainGenerator* generator, std::vector<std::unique_ptr<Piece>>& pieces,
             bool useHeightMapOptimizer, int heightY, VoxelShape* globalShape)
        : maxDepth(maxDepth), generator(generator), pieces(pieces),
          useHeightMapOptimizer(useHeightMapOptimizer), heightY(heightY), globalShape(globalShape) {
        if (useHeightMapOptimizer && generator) {
            // Java: SurfaceGenerator2 dédié au heightMapOptimizer, avec startSizeY = heightY + 25
            heightMapGen = std::make_unique<SurfaceGenWrapper>(generator->getWorldSeed(), 19);
            heightMapGen->setStartSizeYExact(heightY + 25);
        }
    }

    void addToPlacing(Piece* piece) { placing.push_back(piece); }

    void run(VillageType villageType, ChunkRand& rand) {
        while (!placing.empty()) {
            Piece* p = placing.front();
            placing.pop_front();
            tryPlacing(villageType, p, rand, true);
        }
    }

    void tryPlacing(VillageType villageType, Piece* piece, ChunkRand& rand, bool expansionHack) {
        const int depth = piece->depth;
        const BPos pos = piece->pos;
        const bool isRigid = (piece->placementBehaviour == PlacementBehaviour::RIGID);
        const BlockBox& box = piece->box;
        const int minY = box.minY;

        auto pool = createVillagePool(villageType);
        if (!pool) return;

        std::vector<BlockJigsawInfo> jigsawBlocks = getShuffledJigsawBlocks(piece, villageType, rand);

        VoxelShape mutableobject;

        for (const BlockJigsawInfo& blockJigsawInfo : jigsawBlocks) {
            BlockDirection blockDirection = blockJigsawInfo.front;
            BPos blockPos = blockJigsawInfo.pos;
            BPos dirVec = BlockRotationHelper::getDirectionVector(blockDirection);
            BPos relativeBlockPos(blockPos.x + dirVec.x, blockPos.y + dirVec.y, blockPos.z + dirVec.z);
            int y = blockPos.y - minY;
            int state = -1;

            PoolType jointType = blockJigsawInfo.poolType;
            auto mainTemplates = pool->getTemplates(jointType);
            if (mainTemplates.empty()) continue;

            PoolType fallbackType = getFallbackPoolType(villageType, jointType);
            auto fallbackTemplates = pool->getTemplates(fallbackType);
            if (fallbackTemplates.empty() && mainTemplates.empty()) continue;


            bool isInside = box.contains(relativeBlockPos);
            VoxelShape* mutableobject1;
            if (isInside) {
                mutableobject1 = &mutableobject;
                if (mutableobject.isNull()) {
                    mutableobject.setValue(box, true);
                }
            } else {
                mutableobject1 = globalShape;
            }

            std::vector<std::string> list;
            if (depth != maxDepth && !mainTemplates.empty()) {
                size_t total = 0;
                for (const auto& t : mainTemplates) total += t.weight;
                list.reserve(total);
                for (const auto& t : mainTemplates) {
                    for (int w = 0; w < t.weight; ++w) {
                        list.push_back(t.name);
                    }
                }
                if (!list.empty()) {
                    rand.shuffle(list);
                    rand.advance(1);
                }
            }
            if (!fallbackTemplates.empty()) {
                std::vector<std::string> listtmp;
                size_t total = 0;
                for (const auto& t : fallbackTemplates) total += t.weight;
                listtmp.reserve(total);
                for (const auto& t : fallbackTemplates) {
                    for (int w = 0; w < t.weight; ++w) {
                        listtmp.push_back(t.name);
                    }
                }
                if (!listtmp.empty()) {
                    rand.shuffle(listtmp);
                    rand.advance(1);
                }
                for (const auto& s : listtmp) list.push_back(s);
            }
                

            for (const std::string& jigsawpiece1 : list) {
                if (jigsawpiece1 == "empty") break;
                auto rotations = BlockRotationHelper::getShuffled(rand);
                for (BlockRotation rotation1 : rotations) {
                    BPos size1;
                    bool hasSize = get_bpos(jigsawpiece1.c_str(), &size1);
                    BlockBox box1(0, 0, 0, 0, 0, 0);
                    if (hasSize) box1 = BlockBox::getBoundingBox(BPos(0, 0, 0), rotation1, size1);
                    VillageGenerator::Piece piece1(jigsawpiece1, BPos(0, 0, 0), box1, rotation1,
                        pool->getPlacementBehaviour(jointType), 0);
                    std::vector<BlockJigsawInfo> list1 = getShuffledJigsawBlocks(&piece1, villageType, rand);

                    int i1 = 0;
                    if (expansionHack && (box1.maxY - box1.minY) <= 16) {
                        for (const auto& j : list1) {
                            BPos d = BlockRotationHelper::getDirectionVector(j.front);
                            BPos rel(j.pos.x + d.x, j.pos.y + d.y, j.pos.z + d.z);
                            if (box1.contains(rel)) {
                                i1 = std::max(i1, getPoolYMax(j.poolType));
                            }
                        }
                    }

                    for (const BlockJigsawInfo& blockJigsawInfo2 : list1) {
                        bool canAttach = blockJigsawInfo.canAttach15(blockJigsawInfo2);
                        if (!canAttach) continue;

                        BPos blockPos3 = blockJigsawInfo2.pos;
                        BPos blockPos4(relativeBlockPos.x - blockPos3.x,
                                       relativeBlockPos.y - blockPos3.y,
                                       relativeBlockPos.z - blockPos3.z);
                        BlockBox box2(blockPos4.x, blockPos4.y, blockPos4.z,
                                      blockPos4.x, blockPos4.y, blockPos4.z);
                        if (hasSize)
                            box2 = BlockBox::getBoundingBox(blockPos4, rotation1, size1);
                        int j1 = box2.minY;
                        bool flag2 = (pool->getPlacementBehaviour(jointType) == PlacementBehaviour::RIGID);
                        int k1 = blockPos3.y;
                        int l1 = y - k1 + dirVec.y;
                        int i2;
                        if (isRigid && flag2) {
                            i2 = minY + l1;
                        } else {
                            if (state == -1) {
                                int hm = -1;
                                int fh = -1;
                                if (useHeightMapOptimizer && heightMapGen) {
                                    hm = heightMapGen->getHeightOnGround(blockPos.x, blockPos.z);
                                    state = hm;
                                } else {
                                    fh = generator->getFirstHeightInColumn(blockPos.x, blockPos.z, nullptr);
                                    state = fh;
                                }
                                // Log systématique pour comparer la source du Y
                                // logs temporaires retirés
                            
                            }
                            i2 = state - k1;
                        }
                        int j2 = i2 - j1;
                        BlockBox box3(box2.minX, box2.minY, box2.minZ, box2.maxX, box2.maxY, box2.maxZ);
                        box3.move(0, j2, 0);
                        BPos blockpos5(blockPos4.x, blockPos4.y + j2, blockPos4.z);
                        if (i1 > 0) {
                            int k2 = std::max(i1 + 1, box3.maxY - box3.minY);
                            box3.maxY = box3.minY + k2;
                        }

                        bool ok = isNotEmpty(mutableobject1, box3);
                        if (!ok) continue;


                        // Java: mutableobject1.fullBoxes.add(new BlockBox(...))
                        mutableobject1->addCollision(BlockBox(box3.minX, box3.minY, box3.minZ,
                                                             box3.maxX + 1, box3.maxY + 1, box3.maxZ + 1));
                        auto newPiece = std::make_unique<Piece>(
                            jigsawpiece1, blockpos5, box3, rotation1,
                            pool->getPlacementBehaviour(jointType), depth + 1
                        );
                        if (depth + 1 <= maxDepth) {
                            pieces.push_back(std::move(newPiece));
                            placing.push_back(pieces.back().get());
                        }
                        
                        goto next_jigsaw_block;
                    }
                }

            }
            next_jigsaw_block:;
        }
    }

private:
    int maxDepth;
    TerrainGenerator* generator;
    std::vector<std::unique_ptr<Piece>>& pieces;
    bool useHeightMapOptimizer;
    int heightY;
    VoxelShape* globalShape;  // VoxelShape partagé par toutes les pièces
    std::unique_ptr<SurfaceGenWrapper> heightMapGen;
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
        // Vérifier les collisions avec le VoxelShape global
        if (globalShape && globalShape->intersects(piece->box)) {
            return false;
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

    int rotationInt = rand.nextInt(4);
    BlockRotation rotation = static_cast<BlockRotation>(rotationInt);

    // 3) Get start pool and pick template (like Java: STARTS.get(villageType), rand.getRandom(...))
    auto it = STARTS.find(villageType);
    if (it == STARTS.end()) return false;
    std::string templateName(rand.getRandom(it->second));
    if (templateName.empty()) return false;

    // 4) Template size and world-space bounding box (STRUCTURE_SIZE.get(template))
    BPos size;
    if (!get_bpos(templateName.c_str(), &size)) return false;

    BPos bPos = BPos::fromChunk(chunkX, 0, chunkZ);
    BlockBox box = BlockBox::getBoundingBox(bPos, rotation, size);

    int centerX = (box.minX + box.maxX) / 2;
    int centerZ = (box.minZ + box.maxZ) / 2;

    // 5) Ground Y using height map
    int heightY = generator->getHeightOnGround(centerX, centerZ);
    int y = bPos.y + heightY;
    int centerY = box.minY + 1;

    // 6) First piece (always RIGID), moved to Y
    auto piece = std::make_unique<Piece>(
        templateName, bPos, box, rotation, PlacementBehaviour::RIGID, /*depth=*/0
    );
    piece->move(0, y - centerY, 0);
    piece->setBoundsTop(y + 80);

    // 7) VoxelShape global: fullBox is the bounds (pieces must be INSIDE), pieceBox is the collision
    // Ce VoxelShape est partagé par toutes les pièces (comme en Java)
    BlockBox fullBox(centerX - 80, y - 80, centerZ - 80,
                     centerX + 80 + 1, y + 80 + 1, centerZ + 80 + 1);
    VoxelShape globalShape;
    globalShape.setBounds(fullBox);  // Bounds = limite externe
    // Java: a.fullBoxes.add(new BlockBox(box.minX,box.minY,box.minZ,box.maxX+1,box.maxY+1,box.maxZ+1));
    globalShape.addCollision(BlockBox(
        piece->box.minX, piece->box.minY, piece->box.minZ,
        piece->box.maxX + 1, piece->box.maxY + 1, piece->box.maxZ + 1));

    pieces.push_back(std::move(piece));

    // 8) Assembler: add first piece to placing, then run until queue empty
    Assembler assembler(6, generator, pieces, useHeightMapOptimizer, heightY, &globalShape);
    assembler.addToPlacing(pieces[0].get());
    assembler.run(villageType, rand);

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
