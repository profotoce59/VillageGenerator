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
#include "Profiler.hpp"
#include <algorithm>
#include <stdexcept>
#include <cstring>
#include <unordered_map>

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
    if (BlockRotationHelper::getOpposite(other.front) != front)
        return false;
    // Comparaison de valeur, comme avec les std::string d'avant. Les noms
    // viennent de littéraux souvent mis en commun par le compilateur, d'où le
    // test de pointeur d'abord.
    if (jointName == other.jointName) return true;
    if (!jointName || !other.jointName) return false;
    return strcmp(jointName, other.jointName) == 0;
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

/**
 * Cache de VillagePool::getTemplates.
 *
 * getTemplates reconstruit son vecteur (et donc un std::string par entrée) à
 * chaque appel, alors que le résultat ne dépend que de (villageType, poolType).
 * Il est appelé deux fois par bloc jigsaw, soit des centaines de milliers de
 * fois par lot de villages. thread_local plutôt que static : la recherche peut
 * un jour être multi-thread, et les entrées ne sont jamais invalidées.
 */
static const std::vector<TemplateEntry>& cachedTemplates(
    const VillagePool* pool, VillageType villageType, PoolType type)
{
    thread_local std::unordered_map<int, std::vector<TemplateEntry>> cache;
    const int key = (int)villageType * 256 + (int)type;
    auto it = cache.find(key);
    if (it != cache.end()) return it->second;
    // unordered_map est à nœuds : les références restent valides après rehash,
    // ce sur quoi s'appuient les pointeurs conservés par l'appelant.
    return cache.emplace(key, pool->getTemplates(type)).first->second;
}

// Table jigsaw brute d'un template : pointeur dans les données statiques de
// c/jigsaw/*.hpp, pas de copie.
static bool lookupJigsawTable(const std::string& name, VillageType villageType,
                              const JigsawBlockEntry*& data, size_t& count) {
    data = nullptr;
    count = 0;
    switch (villageType) {
        case VillageType::DESERT:  return getDesertVillageJigsawBlocksFast(name, data, count);
        case VillageType::PLAINS:  return getPlainsVillageJigsawBlockFast(name, data, count);
        case VillageType::TAIGA:   return getTaigaVillageJigsawBlocksFast(name, data, count);
        case VillageType::SAVANNA: return getSavannaVillageJigsawBlocksFast(name, data, count);
        case VillageType::SNOWY:   return getSnowyVillageJigsawBlocksFast(name, data, count);
        default:                   return false;
    }
}

/**
 * Remplit `out` avec les blocs jigsaw du template, tournés en coordonnées monde
 * puis mélangés.
 *
 * `out` est fourni par l'appelant et réutilisé : cette fonction est appelée
 * ~11 000 fois par village (une fois par pièce candidate et par rotation), donc
 * une allocation par appel se voyait dans le profil. La version d'origine en
 * faisait deux, plus une table intermédiaire de JigsawEntry.
 *
 * Le mélange reste identique : ChunkRand::shuffle ne consomme du hasard qu'en
 * fonction de out.size(), pas du contenu.
 */
// Variante prenant la table déjà résolue : la recherche par nom ne dépend pas
// de la rotation, l'appelant la sort donc de la boucle sur les 4 rotations.
static void getShuffledJigsawBlocksFrom(
    const JigsawBlockEntry* data, size_t count,
    const BPos& piecePos, BlockRotation rotation, ChunkRand& rand,
    std::vector<BlockJigsawInfo>& out)
{
    VPROF_SCOPE(VZ_JIGSAW_BLOCKS);
    out.clear();
    if (data) {
        out.reserve(count);
        for (size_t i = 0; i < count; i++) {
            BPos rotated = BlockRotationHelper::rotate(
                BPos(data[i].x, data[i].y, data[i].z), rotation);
            BPos worldPos = piecePos.add(rotated.x, rotated.y, rotated.z);
            BlockDirection worldFront = BlockRotationHelper::rotate(data[i].front, rotation);
            out.push_back({data[i].poolType, data[i].jointName, worldPos, worldFront});
        }
    }
    rand.shuffle(out);
}

static void getShuffledJigsawBlocks(
    const std::string& templateName, const BPos& piecePos, BlockRotation rotation,
    VillageType villageType, ChunkRand& rand,
    std::vector<BlockJigsawInfo>& out)
{
    VPROF_SCOPE(VZ_JIGSAW_BLOCKS);
    const JigsawBlockEntry* data = nullptr;
    size_t count = 0;
    bool found = lookupJigsawTable(templateName, villageType, data, count);

    out.clear();
    if (found && data) {
        out.reserve(count);
        for (size_t i = 0; i < count; i++) {
            BPos rotated = BlockRotationHelper::rotate(
                BPos(data[i].x, data[i].y, data[i].z), rotation);
            BPos worldPos = piecePos.add(rotated.x, rotated.y, rotated.z);
            BlockDirection worldFront = BlockRotationHelper::rotate(data[i].front, rotation);
            out.push_back({data[i].poolType, data[i].jointName, worldPos, worldFront});
        }
    }
    rand.shuffle(out);
}

// Variante remplissant un buffer réutilisé : évite d'allouer un vecteur de 4
// éléments par pièce candidate. Le mélange est identique, ChunkRand::shuffle ne
// dépendant que de la taille.
static void getShuffledRotations(ChunkRand& rand, std::vector<BlockRotation>& out) {
    out.clear();
    out.push_back(BlockRotation::NONE);
    out.push_back(BlockRotation::CLOCKWISE_90);
    out.push_back(BlockRotation::CLOCKWISE_180);
    out.push_back(BlockRotation::COUNTERCLOCKWISE_90);
    rand.shuffle(out);
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
    VPROF_SCOPE(VZ_VOXEL_CHECK);
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
    // Marge au-delà des bounds du village pour la zone pré-calculée. Les bounds
    // vont à ±80/81 du centre ; sur 105 villages mesurés, les positions
    // effectivement interrogées atteignent 85 au plus (médiane 74, p90 84),
    // donc 8 de marge couvre tout le monde. Une requête qui sortirait quand
    // même retombe simplement sur le chemin C.
    static constexpr int PREFETCH_MARGIN = 8;

    Assembler(int maxDepth, TerrainGenerator* generator, std::vector<std::unique_ptr<Piece>>& pieces,
             bool useHeightMapOptimizer, int heightY, VoxelShape* globalShape)
        : maxDepth(maxDepth), generator(generator), pieces(pieces),
          useHeightMapOptimizer(useHeightMapOptimizer), heightY(heightY), globalShape(globalShape) {
        if (useHeightMapOptimizer && generator) {
            // Java: SurfaceGenerator2 dédié au heightMapOptimizer, avec startSizeY = heightY + 25
            heightMapGen = std::make_unique<SurfaceGenWrapper>(generator->getWorldSeed(), 19);
            heightMapGen->setStartSizeYExact(heightY + 25);
            heightMapGen->resetHeightCache();

            // Toutes les pièces tiennent dans les bounds du VoxelShape, donc les
            // requêtes de hauteur aussi (à la marge près des positions testées
            // puis rejetées). Si un HeightProvider est installé, on lui fait
            // calculer la zone entière d'un coup ; sinon c'est un no-op.
            if (globalShape && globalShape->hasBounds) {
                const int margin = PREFETCH_MARGIN;
                int x0 = globalShape->bounds.minX - margin;
                int z0 = globalShape->bounds.minZ - margin;
                int w  = (globalShape->bounds.maxX + margin) - x0 + 1;
                int hh = (globalShape->bounds.maxZ + margin) - z0 + 1;
                heightMapGen->prefetchRegion(x0, z0, w, hh);
            }
        }
    }

    void addToPlacing(Piece* piece) { placing.push_back(piece); }

    void run(VillageType villageType, ChunkRand& rand) {
        VPROF_SCOPE(VZ_ASSEMBLE);
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

        std::unique_ptr<VillagePool> pool;
        {
            VPROF_SCOPE(VZ_POOL_CREATE);
            pool = createVillagePool(villageType);
        }
        if (!pool) return;

        // Buffers membres réutilisés : tryPlacing n'est jamais réentrant
        // (run() dépile séquentiellement), et le buffer externe doit rester
        // valide pendant que l'interne est rerempli, d'où deux buffers.
        std::vector<BlockJigsawInfo>& jigsawBlocks = bufOuter;
        getShuffledJigsawBlocks(piece->name, piece->pos, piece->rotation,
                                villageType, rand, jigsawBlocks);

        VoxelShape mutableobject;

        for (const BlockJigsawInfo& blockJigsawInfo : jigsawBlocks) {
            BlockDirection blockDirection = blockJigsawInfo.front;
            BPos blockPos = blockJigsawInfo.pos;
            BPos dirVec = BlockRotationHelper::getDirectionVector(blockDirection);
            BPos relativeBlockPos(blockPos.x + dirVec.x, blockPos.y + dirVec.y, blockPos.z + dirVec.z);
            int y = blockPos.y - minY;
            int state = -1;

            PoolType jointType = blockJigsawInfo.poolType;
            const std::vector<TemplateEntry>& mainTemplates =
                cachedTemplates(pool.get(), villageType, jointType);
            if (mainTemplates.empty()) continue;

            PoolType fallbackType = getFallbackPoolType(villageType, jointType);
            const std::vector<TemplateEntry>& fallbackTemplates =
                cachedTemplates(pool.get(), villageType, fallbackType);
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

            // Listes de pointeurs et non de std::string : la liste est étendue
            // par poids (donc bien plus longue que la table) puis mélangée, ce
            // qui copiait des chaînes en masse. Les cibles vivent dans le cache
            // de templates, dont les entrées sont stables.
            // Le mélange est inchangé : ChunkRand::shuffle ne dépend que de la
            // taille de la liste.
            std::vector<const std::string*>& list = bufNames;
            list.clear();
            {
            VPROF_SCOPE(VZ_TEMPLATE_LIST);
            if (depth != maxDepth && !mainTemplates.empty()) {
                size_t total = 0;
                for (const auto& t : mainTemplates) total += t.weight;
                list.reserve(total);
                for (const auto& t : mainTemplates) {
                    for (int w = 0; w < t.weight; ++w) {
                        list.push_back(&t.name);
                    }
                }
                if (!list.empty()) {
                    rand.shuffle(list);
                    rand.advance(1);
                }
            }
            if (!fallbackTemplates.empty()) {
                std::vector<const std::string*>& listtmp = bufNamesFallback;
                listtmp.clear();
                size_t total = 0;
                for (const auto& t : fallbackTemplates) total += t.weight;
                listtmp.reserve(total);
                for (const auto& t : fallbackTemplates) {
                    for (int w = 0; w < t.weight; ++w) {
                        listtmp.push_back(&t.name);
                    }
                }
                if (!listtmp.empty()) {
                    rand.shuffle(listtmp);
                    rand.advance(1);
                }
                for (const auto* s : listtmp) list.push_back(s);
            }
            }

            for (const std::string* jigsawpiece1Ptr : list) {
                const std::string& jigsawpiece1 = *jigsawpiece1Ptr;
                if (jigsawpiece1 == "empty") break;

                // Ces deux recherches par nom ne dépendent pas de la rotation :
                // les faire dans la boucle les répétait 4 fois pour rien.
                BPos size1;
                bool hasSize;
                { VPROF_SCOPE(VZ_SIZE_LOOKUP); hasSize = get_bpos(jigsawpiece1.c_str(), &size1); }
                const JigsawBlockEntry* jigsawData = nullptr;
                size_t jigsawCount = 0;
                if (!lookupJigsawTable(jigsawpiece1, villageType, jigsawData, jigsawCount))
                    jigsawData = nullptr;

                getShuffledRotations(rand, bufRotations);
                for (BlockRotation rotation1 : bufRotations) {
                    BlockBox box1(0, 0, 0, 0, 0, 0);
                    if (hasSize) box1 = BlockBox::getBoundingBox(BPos(0, 0, 0), rotation1, size1);
                    // Pas de Piece temporaire ici : seuls le nom, la position
                    // et la rotation servaient, et la construire copiait un
                    // std::string 3,3 millions de fois par lot de villages.
                    std::vector<BlockJigsawInfo>& list1 = bufInner;
                    getShuffledJigsawBlocksFrom(jigsawData, jigsawCount,
                                                BPos(0, 0, 0), rotation1, rand, list1);

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
                                if (useHeightMapOptimizer && heightMapGen) {
                                    // Java heightMapOptimizer uses generateColumnfromY with (block != AIR)
                                    state = heightMapGen->generateColumnFromY(blockPos.x, blockPos.z, nullptr);
                                } else {
                                    state = generator->getFirstHeightInColumn(blockPos.x, blockPos.z, nullptr);
                                }
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
    std::vector<BlockJigsawInfo> bufOuter, bufInner;
    std::vector<BlockRotation> bufRotations;
    std::vector<const std::string*> bufNames, bufNamesFallback;
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
    int heightY;
    { VPROF_SCOPE(VZ_HEIGHT_CENTER); heightY = generator->getHeightOnGround(centerX, centerZ); }
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
    VPROF_SCOPE(VZ_VILLAGE_TOTAL);
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
