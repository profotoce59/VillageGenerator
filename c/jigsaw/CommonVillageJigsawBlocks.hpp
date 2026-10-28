#pragma once
// Auto-generated from CommonVillageJigsawBlocks.java
// DO NOT EDIT MANUALLY

#include <string>
#include <vector>
#include <unordered_map>
#include "../VillageGenerator.hpp"

#ifndef JIGSAW_BLOCK_ENTRY_DEFINED
struct JigsawBlockEntry {
    PoolType poolType;
    const char* jointName;
    BlockDirection front;
    BlockDirection top;
    int16_t x, y, z;
};
#endif

// Données statiques des JigsawBlocks
namespace CommonVillageJigsawData {

    static const JigsawBlockEntry common_animals_cat_black[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry common_animals_cat_british[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry common_animals_cat_calico[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry common_animals_cat_jellie[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry common_animals_cat_persia[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry common_animals_cat_persian[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry common_animals_cat_ragdoll[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry common_animals_cat_red[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry common_animals_cat_siamese[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry common_animals_cat_tabby[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry common_animals_cat_white[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry common_animals_cows_1[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry common_animals_horses_1[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry common_animals_horses_2[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry common_animals_horses_3[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry common_animals_horses_4[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry common_animals_horses_5[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry common_animals_pigs_1[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry common_animals_sheep_1[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry common_animals_sheep_2[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry common_iron_golem[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry common_well_bottom[] = {
        {PoolType::WELL_BOTTOM, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 2, 0},
    };

    static const JigsawBlockEntry patch_cactus[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry pile_hay[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry plains_terminators_terminator_01[] = {
        {PoolType::PLAIN_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 1, 1, 1},
    };

    static const JigsawBlockEntry plains_terminators_terminator_02[] = {
        {PoolType::PLAIN_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 0, 1, 0},
    };

    static const JigsawBlockEntry plains_terminators_terminator_03[] = {
        {PoolType::PLAIN_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 2, 1, 1},
    };

    static const JigsawBlockEntry plains_terminators_terminator_04[] = {
        {PoolType::PLAIN_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 3, 1, 1},
    };

} // namespace

// Fonction pour obtenir les JigsawBlocks d'un template
inline std::vector<JigsawBlockEntry> getCommonVillageJigsawBlocks(const std::string& templateName) {
    using namespace CommonVillageJigsawData;
    
    static const std::unordered_map<std::string, std::pair<const JigsawBlockEntry*, size_t>> LOOKUP = {
        {"common/animals/cat_black", {common_animals_cat_black, 1}},
        {"common/animals/cat_british", {common_animals_cat_british, 1}},
        {"common/animals/cat_calico", {common_animals_cat_calico, 1}},
        {"common/animals/cat_jellie", {common_animals_cat_jellie, 1}},
        {"common/animals/cat_persia", {common_animals_cat_persia, 1}},
        {"common/animals/cat_persian", {common_animals_cat_persian, 1}},
        {"common/animals/cat_ragdoll", {common_animals_cat_ragdoll, 1}},
        {"common/animals/cat_red", {common_animals_cat_red, 1}},
        {"common/animals/cat_siamese", {common_animals_cat_siamese, 1}},
        {"common/animals/cat_tabby", {common_animals_cat_tabby, 1}},
        {"common/animals/cat_white", {common_animals_cat_white, 1}},
        {"common/animals/cows_1", {common_animals_cows_1, 1}},
        {"common/animals/horses_1", {common_animals_horses_1, 1}},
        {"common/animals/horses_2", {common_animals_horses_2, 1}},
        {"common/animals/horses_3", {common_animals_horses_3, 1}},
        {"common/animals/horses_4", {common_animals_horses_4, 1}},
        {"common/animals/horses_5", {common_animals_horses_5, 1}},
        {"common/animals/pigs_1", {common_animals_pigs_1, 1}},
        {"common/animals/sheep_1", {common_animals_sheep_1, 1}},
        {"common/animals/sheep_2", {common_animals_sheep_2, 1}},
        {"common/iron_golem", {common_iron_golem, 1}},
        {"common/well_bottom", {common_well_bottom, 1}},
        {"patch_cactus", {patch_cactus, 1}},
        {"pile_hay", {pile_hay, 1}},
        {"plains/terminators/terminator_01", {plains_terminators_terminator_01, 1}},
        {"plains/terminators/terminator_02", {plains_terminators_terminator_02, 1}},
        {"plains/terminators/terminator_03", {plains_terminators_terminator_03, 1}},
        {"plains/terminators/terminator_04", {plains_terminators_terminator_04, 1}},
    };
    
    auto it = LOOKUP.find(templateName);
    if (it != LOOKUP.end()) {
        return std::vector<JigsawBlockEntry>(it->second.first, it->second.first + it->second.second);
    }
    return {};
}

// Version sans allocation (plus rapide)
inline bool getCommonVillageJigsawBlocksFast(const std::string& templateName, const JigsawBlockEntry*& out, size_t& count) {
    using namespace CommonVillageJigsawData;
    
    static const std::unordered_map<std::string, std::pair<const JigsawBlockEntry*, size_t>> LOOKUP = {
        {"common/animals/cat_black", {common_animals_cat_black, 1}},
        {"common/animals/cat_british", {common_animals_cat_british, 1}},
        {"common/animals/cat_calico", {common_animals_cat_calico, 1}},
        {"common/animals/cat_jellie", {common_animals_cat_jellie, 1}},
        {"common/animals/cat_persia", {common_animals_cat_persia, 1}},
        {"common/animals/cat_persian", {common_animals_cat_persian, 1}},
        {"common/animals/cat_ragdoll", {common_animals_cat_ragdoll, 1}},
        {"common/animals/cat_red", {common_animals_cat_red, 1}},
        {"common/animals/cat_siamese", {common_animals_cat_siamese, 1}},
        {"common/animals/cat_tabby", {common_animals_cat_tabby, 1}},
        {"common/animals/cat_white", {common_animals_cat_white, 1}},
        {"common/animals/cows_1", {common_animals_cows_1, 1}},
        {"common/animals/horses_1", {common_animals_horses_1, 1}},
        {"common/animals/horses_2", {common_animals_horses_2, 1}},
        {"common/animals/horses_3", {common_animals_horses_3, 1}},
        {"common/animals/horses_4", {common_animals_horses_4, 1}},
        {"common/animals/horses_5", {common_animals_horses_5, 1}},
        {"common/animals/pigs_1", {common_animals_pigs_1, 1}},
        {"common/animals/sheep_1", {common_animals_sheep_1, 1}},
        {"common/animals/sheep_2", {common_animals_sheep_2, 1}},
        {"common/iron_golem", {common_iron_golem, 1}},
        {"common/well_bottom", {common_well_bottom, 1}},
        {"patch_cactus", {patch_cactus, 1}},
        {"pile_hay", {pile_hay, 1}},
        {"plains/terminators/terminator_01", {plains_terminators_terminator_01, 1}},
        {"plains/terminators/terminator_02", {plains_terminators_terminator_02, 1}},
        {"plains/terminators/terminator_03", {plains_terminators_terminator_03, 1}},
        {"plains/terminators/terminator_04", {plains_terminators_terminator_04, 1}},
    };
    
    auto it = LOOKUP.find(templateName);
    if (it != LOOKUP.end()) {
        out = it->second.first;
        count = it->second.second;
        return true;
    }
    return false;
}
