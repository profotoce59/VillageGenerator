#pragma once
// Auto-generated from SavannaVillageJigsawBlocks.java
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
namespace SavannaVillageJigsawData {

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

    static const JigsawBlockEntry pile_melon[] = {
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

    static const JigsawBlockEntry savanna_acacia[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry savanna_houses_savanna_animal_pen_1[] = {
        {PoolType::ANIMALS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 2},
        {PoolType::EMPTY, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 4, 0, 0},
    };

    static const JigsawBlockEntry savanna_houses_savanna_animal_pen_2[] = {
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 1, 2},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 1, 10},
        {PoolType::ANIMALS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 4, 1, 4},
        {PoolType::SAVANNA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 7, 1, 6},
        {PoolType::ANIMALS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 1, 8},
        {PoolType::EMPTY, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 4, 2, 0},
    };

    static const JigsawBlockEntry savanna_houses_savanna_animal_pen_3[] = {
        {PoolType::SAVANNA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 6},
        {PoolType::ANIMALS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 4, 0, 5},
        {PoolType::EMPTY, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 4, 1, 8},
    };

    static const JigsawBlockEntry savanna_houses_savanna_armorer_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 3},
    };

    static const JigsawBlockEntry savanna_houses_savanna_butchers_shop_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 6},
        {PoolType::BUTCHER_ANIMAL, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 0, 5},
    };

    static const JigsawBlockEntry savanna_houses_savanna_butchers_shop_2[] = {
        {PoolType::BUTCHER_ANIMAL, "bottom", BlockDirection::UP, BlockDirection::NORTH, 10, 0, 2},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 4},
    };

    static const JigsawBlockEntry savanna_houses_savanna_cartographer_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 4},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 4, 0, 4},
    };

    static const JigsawBlockEntry savanna_houses_savanna_fisher_cottage_1[] = {
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 1, 7},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 4, 1, 3},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 6, 1, 8},
        {PoolType::EMPTY, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 3, 2, 0},
    };

    static const JigsawBlockEntry savanna_houses_savanna_fletcher_house_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 4, 1, 8},
    };

    static const JigsawBlockEntry savanna_houses_savanna_large_farm_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 3, 1, 8},
    };

    static const JigsawBlockEntry savanna_houses_savanna_large_farm_2[] = {
        {PoolType::SAVANNA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 6, 1, 3},
        {PoolType::EMPTY, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 5, 2, 0},
    };

    static const JigsawBlockEntry savanna_houses_savanna_library_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 5, 1, 0},
    };

    static const JigsawBlockEntry savanna_houses_savanna_mason_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 5},
    };

    static const JigsawBlockEntry savanna_houses_savanna_medium_house_1[] = {
        {PoolType::SAVANNA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 0, 8},
        {PoolType::SAVANNA_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 3},
        {PoolType::SAVANNA_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 11},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 7},
    };

    static const JigsawBlockEntry savanna_houses_savanna_medium_house_2[] = {
        {PoolType::SAVANNA_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 3},
        {PoolType::SAVANNA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 7, 0, 2},
        {PoolType::SAVANNA_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 7, 0, 8},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 5},
    };

    static const JigsawBlockEntry savanna_houses_savanna_shepherd_1[] = {
        {PoolType::SHEEPS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 7, 1, 4},
        {PoolType::SAVANNA_TREE, "bottom", BlockDirection::UP, BlockDirection::NORTH, 10, 1, 8},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 2, 5},
    };

    static const JigsawBlockEntry savanna_houses_savanna_small_farm[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 1, 2, 0},
    };

    static const JigsawBlockEntry savanna_houses_savanna_small_house_1[] = {
        {PoolType::SAVANNA_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 6},
        {PoolType::EMPTY, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 3, 1, 6},
    };

    static const JigsawBlockEntry savanna_houses_savanna_small_house_2[] = {
        {PoolType::SAVANNA_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 6},
        {PoolType::EMPTY, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 4, 1, 6},
    };

    static const JigsawBlockEntry savanna_houses_savanna_small_house_3[] = {
        {PoolType::SAVANNA_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 5, 0, 6},
        {PoolType::EMPTY, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 3, 1, 6},
    };

    static const JigsawBlockEntry savanna_houses_savanna_small_house_4[] = {
        {PoolType::SAVANNA_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 5, 0, 2},
        {PoolType::EMPTY, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 5, 1, 6},
    };

    static const JigsawBlockEntry savanna_houses_savanna_small_house_5[] = {
        {PoolType::SAVANNA_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 4, 0, 3},
        {PoolType::EMPTY, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 6, 1, 3},
    };

    static const JigsawBlockEntry savanna_houses_savanna_small_house_6[] = {
        {PoolType::SAVANNA_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 3},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 6, 0, 3},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 3},
    };

    static const JigsawBlockEntry savanna_houses_savanna_small_house_7[] = {
        {PoolType::SAVANNA_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 5, 0, 6},
        {PoolType::EMPTY, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 2, 1, 6},
    };

    static const JigsawBlockEntry savanna_houses_savanna_small_house_8[] = {
        {PoolType::SAVANNA_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 3},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 3},
    };

    static const JigsawBlockEntry savanna_houses_savanna_tannery_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 6, 1, 4},
    };

    static const JigsawBlockEntry savanna_houses_savanna_temple_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 4},
    };

    static const JigsawBlockEntry savanna_houses_savanna_temple_2[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 4},
    };

    static const JigsawBlockEntry savanna_houses_savanna_tool_smith_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 4},
    };

    static const JigsawBlockEntry savanna_houses_savanna_weaponsmith_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 7, 1, 4},
    };

    static const JigsawBlockEntry savanna_houses_savanna_weaponsmith_2[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 6},
    };

    static const JigsawBlockEntry savanna_savanna_lamp_post_01[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry savanna_streets_corner_01[] = {
        {PoolType::SAVANNA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 4},
        {PoolType::SAVANNA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 10, 0, 3},
        {PoolType::SAVANNA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 13, 0, 9},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 8},
        {PoolType::SAVANNA_HOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 5, 1, 8},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 7, 1, 0},
        {PoolType::SAVANNA_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 8, 1, 6},
    };

    static const JigsawBlockEntry savanna_streets_corner_03[] = {
        {PoolType::SAVANNA_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 1, 1, 3},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 3, 1, 1},
    };

    static const JigsawBlockEntry savanna_streets_crossroad_02[] = {
        {PoolType::SAVANNA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 2},
        {PoolType::SAVANNA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 6},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 5},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 4, 1, 0},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 4, 1, 9},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 6, 1, 5},
    };

    static const JigsawBlockEntry savanna_streets_crossroad_03[] = {
        {PoolType::SAVANNA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 4},
        {PoolType::SAVANNA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 13},
        {PoolType::SAVANNA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 0, 11},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 8},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 2, 1, 0},
        {PoolType::SAVANNA_HOUSES, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 10, 1, 7},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 11, 1, 15},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 15, 1, 8},
    };

    static const JigsawBlockEntry savanna_streets_crossroad_04[] = {
        {PoolType::SAVANNA_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 2},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 2, 1, 0},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 2, 1, 4},
    };

    static const JigsawBlockEntry savanna_streets_crossroad_05[] = {
        {PoolType::SAVANNA_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 2},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 2, 1, 0},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 2, 1, 4},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 4, 1, 2},
    };

    static const JigsawBlockEntry savanna_streets_crossroad_06[] = {
        {PoolType::SAVANNA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 2},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 2},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 2, 1, 0},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 2, 1, 4},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 4, 1, 2},
    };

    static const JigsawBlockEntry savanna_streets_crossroad_07[] = {
        {PoolType::SAVANNA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 12, 0, 4},
        {PoolType::SAVANNA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 13, 0, 9},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 8, 1, 13},
        {PoolType::SAVANNA_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 9, 1, 6},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 13, 1, 0},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 14, 1, 7},
    };

    static const JigsawBlockEntry savanna_streets_split_01[] = {
        {PoolType::SAVANNA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 4, 0, 4},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 1, 1, 4},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 4, 1, 0},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 7, 1, 3},
    };

    static const JigsawBlockEntry savanna_streets_split_02[] = {
        {PoolType::SAVANNA_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 8, 1, 4},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 9, 1, 0},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 10, 1, 8},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 13, 1, 4},
    };

    static const JigsawBlockEntry savanna_streets_straight_02[] = {
        {PoolType::SAVANNA_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 1, 1, 0},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 1, 1, 15},
        {PoolType::SAVANNA_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 3},
        {PoolType::SAVANNA_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 4},
        {PoolType::SAVANNA_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 8},
        {PoolType::SAVANNA_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 9},
        {PoolType::SAVANNA_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 10},
        {PoolType::SAVANNA_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 11},
    };

    static const JigsawBlockEntry savanna_streets_straight_04[] = {
        {PoolType::SAVANNA_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 1, 1, 0},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 1, 1, 8},
        {PoolType::SAVANNA_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 4},
    };

    static const JigsawBlockEntry savanna_streets_straight_05[] = {
        {PoolType::SAVANNA_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 1, 1, 0},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 1, 1, 16},
        {PoolType::SAVANNA_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 7},
        {PoolType::SAVANNA_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 8},
        {PoolType::SAVANNA_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 9},
        {PoolType::SAVANNA_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 10},
    };

    static const JigsawBlockEntry savanna_streets_straight_06[] = {
        {PoolType::SAVANNA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 12},
        {PoolType::SAVANNA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 6, 0, 4},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 1, 1, 13},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 7, 1, 0},
    };

    static const JigsawBlockEntry savanna_streets_straight_08[] = {
        {PoolType::SAVANNA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 5, 0, 6},
        {PoolType::SAVANNA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 5, 0, 13},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 1, 1, 0},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 1, 1, 15},
    };

    static const JigsawBlockEntry savanna_streets_straight_09[] = {
        {PoolType::SAVANNA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 9, 0, 3},
        {PoolType::SAVANNA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 11, 0, 13},
        {PoolType::SAVANNA_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 8, 1, 5},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 9, 1, 0},
        {PoolType::SAVANNA_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 10, 1, 10},
        {PoolType::SAVANNA_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 11, 1, 5},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 12, 1, 15},
        {PoolType::SAVANNA_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 13, 1, 11},
    };

    static const JigsawBlockEntry savanna_streets_straight_10[] = {
        {PoolType::SAVANNA_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 1, 1, 10},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 4, 1, 0},
    };

    static const JigsawBlockEntry savanna_streets_straight_11[] = {
        {PoolType::SAVANNA_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 1, 1, 0},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 1, 1, 16},
        {PoolType::SAVANNA_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 12},
    };

    static const JigsawBlockEntry savanna_streets_turn_01[] = {
        {PoolType::SAVANNA_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 6, 1, 0},
        {PoolType::SAVANNA_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 8, 1, 6},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 9, 1, 10},
        {PoolType::SAVANNA_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 10, 1, 5},
    };

    static const JigsawBlockEntry savanna_terminators_terminator_05[] = {
        {PoolType::SAVANNA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 2},
        {PoolType::SAVANNA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 12},
        {PoolType::SAVANNA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 14},
        {PoolType::EMPTY, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 8},
        {PoolType::SAVANNA_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 8},
    };

    static const JigsawBlockEntry savanna_town_centers_savanna_meeting_point_1[] = {
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 4},
        {PoolType::IRON_GOLEM, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 6},
        {PoolType::SAVANNA_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 5, 0, 4},
        {PoolType::SAVANNA_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 0, 4},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 0, 6},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 0, 9},
        {PoolType::SAVANNA_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 10, 0, 2},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 5},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 7, 1, 0},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 8, 1, 11},
    };

    static const JigsawBlockEntry savanna_town_centers_savanna_meeting_point_2[] = {
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 3},
        {PoolType::SAVANNA_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 6},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 8},
        {PoolType::SAVANNA_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 4, 0, 9},
        {PoolType::SAVANNA_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 7, 0, 8},
        {PoolType::IRON_GOLEM, "bottom", BlockDirection::UP, BlockDirection::NORTH, 9, 0, 7},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 5},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 5, 1, 0},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 5, 1, 10},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 10, 1, 5},
    };

    static const JigsawBlockEntry savanna_town_centers_savanna_meeting_point_3[] = {
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 2},
        {PoolType::SAVANNA_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 3},
        {PoolType::IRON_GOLEM, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 7},
        {PoolType::SAVANNA_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 5},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 7, 0, 1},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 0, 9},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 5},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 4, 1, 0},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 4, 1, 10},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 8, 1, 5},
    };

    static const JigsawBlockEntry savanna_town_centers_savanna_meeting_point_4[] = {
        {PoolType::SAVANNA_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 0, 3},
        {PoolType::SAVANNA_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 1},
        {PoolType::IRON_GOLEM, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 7},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 7, 0, 8},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 0, 0},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 4},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 4, 1, 0},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 4, 1, 8},
        {PoolType::SAVANNA_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 8, 1, 4},
    };

    static const JigsawBlockEntry savanna_villagers_baby[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry savanna_villagers_nitwit[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry savanna_villagers_unemployed[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry savanna_zombie_houses_savanna_animal_pen_2[] = {
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 1, 2},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 1, 10},
        {PoolType::ANIMALS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 4, 1, 4},
        {PoolType::SAVANNA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 7, 1, 6},
        {PoolType::ANIMALS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 1, 8},
        {PoolType::EMPTY, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 4, 2, 0},
    };

    static const JigsawBlockEntry savanna_zombie_houses_savanna_animal_pen_3[] = {
        {PoolType::SAVANNA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 6},
        {PoolType::ANIMALS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 4, 0, 5},
        {PoolType::EMPTY, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 4, 1, 8},
    };

    static const JigsawBlockEntry savanna_zombie_houses_savanna_large_farm_2[] = {
        {PoolType::SAVANNA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 6, 1, 3},
        {PoolType::EMPTY, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 5, 2, 0},
    };

    static const JigsawBlockEntry savanna_zombie_houses_savanna_medium_house_1[] = {
        {PoolType::SAVANNA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 0, 8},
        {PoolType::SAVANNA_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 3},
        {PoolType::SAVANNA_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 11},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 7},
    };

    static const JigsawBlockEntry savanna_zombie_houses_savanna_medium_house_2[] = {
        {PoolType::SAVANNA_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 3},
        {PoolType::SAVANNA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 7, 0, 2},
        {PoolType::SAVANNA_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 7, 0, 8},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 5},
    };

    static const JigsawBlockEntry savanna_zombie_houses_savanna_small_house_1[] = {
        {PoolType::SAVANNA_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 6},
        {PoolType::EMPTY, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 3, 1, 6},
    };

    static const JigsawBlockEntry savanna_zombie_houses_savanna_small_house_2[] = {
        {PoolType::SAVANNA_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 6},
        {PoolType::EMPTY, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 4, 1, 6},
    };

    static const JigsawBlockEntry savanna_zombie_houses_savanna_small_house_3[] = {
        {PoolType::SAVANNA_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 5, 0, 6},
        {PoolType::EMPTY, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 3, 1, 6},
    };

    static const JigsawBlockEntry savanna_zombie_houses_savanna_small_house_4[] = {
        {PoolType::SAVANNA_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 5, 0, 2},
        {PoolType::EMPTY, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 5, 1, 6},
    };

    static const JigsawBlockEntry savanna_zombie_houses_savanna_small_house_5[] = {
        {PoolType::SAVANNA_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 4, 0, 3},
        {PoolType::EMPTY, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 6, 1, 3},
    };

    static const JigsawBlockEntry savanna_zombie_houses_savanna_small_house_6[] = {
        {PoolType::SAVANNA_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 3},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 6, 0, 3},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 3},
    };

    static const JigsawBlockEntry savanna_zombie_houses_savanna_small_house_7[] = {
        {PoolType::SAVANNA_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 5, 0, 6},
        {PoolType::EMPTY, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 2, 1, 6},
    };

    static const JigsawBlockEntry savanna_zombie_houses_savanna_small_house_8[] = {
        {PoolType::SAVANNA_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 3},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 3},
    };

    static const JigsawBlockEntry savanna_zombie_streets_corner_01[] = {
        {PoolType::SAVANNA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 4},
        {PoolType::SAVANNA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 10, 0, 3},
        {PoolType::SAVANNA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 13, 0, 9},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 8},
        {PoolType::SAVANNA_ZHOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 5, 1, 8},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 7, 1, 0},
        {PoolType::SAVANNA_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 8, 1, 6},
    };

    static const JigsawBlockEntry savanna_zombie_streets_corner_03[] = {
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 1, 1, 3},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::EAST, BlockDirection::UP, 3, 1, 1},
    };

    static const JigsawBlockEntry savanna_zombie_streets_crossroad_02[] = {
        {PoolType::SAVANNA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 2},
        {PoolType::SAVANNA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 6},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 5},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 4, 1, 0},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 4, 1, 9},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::EAST, BlockDirection::UP, 6, 1, 5},
    };

    static const JigsawBlockEntry savanna_zombie_streets_crossroad_03[] = {
        {PoolType::SAVANNA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 4},
        {PoolType::SAVANNA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 13},
        {PoolType::SAVANNA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 0, 11},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 8},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 2, 1, 0},
        {PoolType::SAVANNA_ZHOUSES, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 10, 1, 7},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 11, 1, 15},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::EAST, BlockDirection::UP, 15, 1, 8},
    };

    static const JigsawBlockEntry savanna_zombie_streets_crossroad_04[] = {
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 2},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 2, 1, 0},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 2, 1, 4},
    };

    static const JigsawBlockEntry savanna_zombie_streets_crossroad_05[] = {
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 2},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 2, 1, 0},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 2, 1, 4},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::EAST, BlockDirection::UP, 4, 1, 2},
    };

    static const JigsawBlockEntry savanna_zombie_streets_crossroad_06[] = {
        {PoolType::SAVANNA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 2},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 2},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 2, 1, 0},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 2, 1, 4},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::EAST, BlockDirection::UP, 4, 1, 2},
    };

    static const JigsawBlockEntry savanna_zombie_streets_crossroad_07[] = {
        {PoolType::SAVANNA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 12, 0, 4},
        {PoolType::SAVANNA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 13, 0, 9},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 8, 1, 13},
        {PoolType::SAVANNA_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 9, 1, 6},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 13, 1, 0},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::EAST, BlockDirection::UP, 14, 1, 7},
    };

    static const JigsawBlockEntry savanna_zombie_streets_split_01[] = {
        {PoolType::SAVANNA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 4, 0, 4},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 1, 1, 4},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 4, 1, 0},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::EAST, BlockDirection::UP, 7, 1, 3},
    };

    static const JigsawBlockEntry savanna_zombie_streets_split_02[] = {
        {PoolType::SAVANNA_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 8, 1, 4},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 9, 1, 0},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 10, 1, 8},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::EAST, BlockDirection::UP, 13, 1, 4},
    };

    static const JigsawBlockEntry savanna_zombie_streets_straight_02[] = {
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 1, 1, 0},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 1, 1, 15},
        {PoolType::SAVANNA_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 3},
        {PoolType::SAVANNA_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 4},
        {PoolType::SAVANNA_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 8},
        {PoolType::SAVANNA_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 9},
        {PoolType::SAVANNA_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 10},
        {PoolType::SAVANNA_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 11},
    };

    static const JigsawBlockEntry savanna_zombie_streets_straight_04[] = {
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 1, 1, 0},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 1, 1, 8},
        {PoolType::SAVANNA_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 4},
    };

    static const JigsawBlockEntry savanna_zombie_streets_straight_05[] = {
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 1, 1, 0},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 1, 1, 16},
        {PoolType::SAVANNA_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 7},
        {PoolType::SAVANNA_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 8},
        {PoolType::SAVANNA_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 9},
        {PoolType::SAVANNA_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 10},
    };

    static const JigsawBlockEntry savanna_zombie_streets_straight_06[] = {
        {PoolType::SAVANNA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 12},
        {PoolType::SAVANNA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 6, 0, 4},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 1, 1, 13},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 7, 1, 0},
    };

    static const JigsawBlockEntry savanna_zombie_streets_straight_08[] = {
        {PoolType::SAVANNA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 5, 0, 6},
        {PoolType::SAVANNA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 5, 0, 13},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 1, 1, 0},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 1, 1, 15},
    };

    static const JigsawBlockEntry savanna_zombie_streets_straight_09[] = {
        {PoolType::SAVANNA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 9, 0, 3},
        {PoolType::SAVANNA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 11, 0, 13},
        {PoolType::SAVANNA_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 8, 1, 5},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 9, 1, 0},
        {PoolType::SAVANNA_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 10, 1, 10},
        {PoolType::SAVANNA_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 11, 1, 5},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 12, 1, 15},
        {PoolType::SAVANNA_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 13, 1, 11},
    };

    static const JigsawBlockEntry savanna_zombie_streets_straight_10[] = {
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 1, 1, 10},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 4, 1, 0},
    };

    static const JigsawBlockEntry savanna_zombie_streets_straight_11[] = {
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 1, 1, 0},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 1, 1, 16},
        {PoolType::SAVANNA_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 12},
    };

    static const JigsawBlockEntry savanna_zombie_streets_turn_01[] = {
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 6, 1, 0},
        {PoolType::SAVANNA_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 8, 1, 6},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 9, 1, 10},
        {PoolType::SAVANNA_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 10, 1, 5},
    };

    static const JigsawBlockEntry savanna_zombie_terminators_terminator_05[] = {
        {PoolType::SAVANNA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 2},
        {PoolType::SAVANNA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 12},
        {PoolType::SAVANNA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 14},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 8},
        {PoolType::SAVANNA_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 8},
    };

    static const JigsawBlockEntry savanna_zombie_town_centers_savanna_meeting_point_1[] = {
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 5},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 7, 1, 0},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 8, 1, 11},
    };

    static const JigsawBlockEntry savanna_zombie_town_centers_savanna_meeting_point_2[] = {
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 3},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 8},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 5},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 5, 1, 0},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 5, 1, 10},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::EAST, BlockDirection::UP, 10, 1, 5},
    };

    static const JigsawBlockEntry savanna_zombie_town_centers_savanna_meeting_point_3[] = {
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 2},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 7, 0, 1},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 0, 9},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 5},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 4, 1, 0},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 4, 1, 10},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::EAST, BlockDirection::UP, 8, 1, 5},
    };

    static const JigsawBlockEntry savanna_zombie_town_centers_savanna_meeting_point_4[] = {
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 7, 0, 8},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 0, 0},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 4},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 4, 1, 0},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 4, 1, 8},
        {PoolType::SAVANNA_ZSTREET, "street", BlockDirection::EAST, BlockDirection::UP, 8, 1, 4},
    };

    static const JigsawBlockEntry savanna_zombie_villagers_nitwit[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry savanna_zombie_villagers_unemployed[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

} // namespace

// Fonction pour obtenir les JigsawBlocks d'un template
inline std::vector<JigsawBlockEntry> getSavannaVillageJigsawBlocks(const std::string& templateName) {
    using namespace SavannaVillageJigsawData;
    
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
        {"pile_melon", {pile_melon, 1}},
        {"plains/terminators/terminator_01", {plains_terminators_terminator_01, 1}},
        {"plains/terminators/terminator_02", {plains_terminators_terminator_02, 1}},
        {"plains/terminators/terminator_03", {plains_terminators_terminator_03, 1}},
        {"plains/terminators/terminator_04", {plains_terminators_terminator_04, 1}},
        {"savanna/acacia", {savanna_acacia, 1}},
        {"savanna/houses/savanna_animal_pen_1", {savanna_houses_savanna_animal_pen_1, 2}},
        {"savanna/houses/savanna_animal_pen_2", {savanna_houses_savanna_animal_pen_2, 6}},
        {"savanna/houses/savanna_animal_pen_3", {savanna_houses_savanna_animal_pen_3, 3}},
        {"savanna/houses/savanna_armorer_1", {savanna_houses_savanna_armorer_1, 1}},
        {"savanna/houses/savanna_butchers_shop_1", {savanna_houses_savanna_butchers_shop_1, 2}},
        {"savanna/houses/savanna_butchers_shop_2", {savanna_houses_savanna_butchers_shop_2, 2}},
        {"savanna/houses/savanna_cartographer_1", {savanna_houses_savanna_cartographer_1, 2}},
        {"savanna/houses/savanna_fisher_cottage_1", {savanna_houses_savanna_fisher_cottage_1, 4}},
        {"savanna/houses/savanna_fletcher_house_1", {savanna_houses_savanna_fletcher_house_1, 1}},
        {"savanna/houses/savanna_large_farm_1", {savanna_houses_savanna_large_farm_1, 1}},
        {"savanna/houses/savanna_large_farm_2", {savanna_houses_savanna_large_farm_2, 2}},
        {"savanna/houses/savanna_library_1", {savanna_houses_savanna_library_1, 1}},
        {"savanna/houses/savanna_mason_1", {savanna_houses_savanna_mason_1, 1}},
        {"savanna/houses/savanna_medium_house_1", {savanna_houses_savanna_medium_house_1, 4}},
        {"savanna/houses/savanna_medium_house_2", {savanna_houses_savanna_medium_house_2, 4}},
        {"savanna/houses/savanna_shepherd_1", {savanna_houses_savanna_shepherd_1, 3}},
        {"savanna/houses/savanna_small_farm", {savanna_houses_savanna_small_farm, 1}},
        {"savanna/houses/savanna_small_house_1", {savanna_houses_savanna_small_house_1, 2}},
        {"savanna/houses/savanna_small_house_2", {savanna_houses_savanna_small_house_2, 2}},
        {"savanna/houses/savanna_small_house_3", {savanna_houses_savanna_small_house_3, 2}},
        {"savanna/houses/savanna_small_house_4", {savanna_houses_savanna_small_house_4, 2}},
        {"savanna/houses/savanna_small_house_5", {savanna_houses_savanna_small_house_5, 2}},
        {"savanna/houses/savanna_small_house_6", {savanna_houses_savanna_small_house_6, 3}},
        {"savanna/houses/savanna_small_house_7", {savanna_houses_savanna_small_house_7, 2}},
        {"savanna/houses/savanna_small_house_8", {savanna_houses_savanna_small_house_8, 2}},
        {"savanna/houses/savanna_tannery_1", {savanna_houses_savanna_tannery_1, 1}},
        {"savanna/houses/savanna_temple_1", {savanna_houses_savanna_temple_1, 1}},
        {"savanna/houses/savanna_temple_2", {savanna_houses_savanna_temple_2, 1}},
        {"savanna/houses/savanna_tool_smith_1", {savanna_houses_savanna_tool_smith_1, 1}},
        {"savanna/houses/savanna_weaponsmith_1", {savanna_houses_savanna_weaponsmith_1, 1}},
        {"savanna/houses/savanna_weaponsmith_2", {savanna_houses_savanna_weaponsmith_2, 1}},
        {"savanna/savanna_lamp_post_01", {savanna_savanna_lamp_post_01, 1}},
        {"savanna/streets/corner_01", {savanna_streets_corner_01, 7}},
        {"savanna/streets/corner_03", {savanna_streets_corner_03, 2}},
        {"savanna/streets/crossroad_02", {savanna_streets_crossroad_02, 6}},
        {"savanna/streets/crossroad_03", {savanna_streets_crossroad_03, 8}},
        {"savanna/streets/crossroad_04", {savanna_streets_crossroad_04, 3}},
        {"savanna/streets/crossroad_05", {savanna_streets_crossroad_05, 4}},
        {"savanna/streets/crossroad_06", {savanna_streets_crossroad_06, 5}},
        {"savanna/streets/crossroad_07", {savanna_streets_crossroad_07, 6}},
        {"savanna/streets/split_01", {savanna_streets_split_01, 4}},
        {"savanna/streets/split_02", {savanna_streets_split_02, 4}},
        {"savanna/streets/straight_02", {savanna_streets_straight_02, 8}},
        {"savanna/streets/straight_04", {savanna_streets_straight_04, 3}},
        {"savanna/streets/straight_05", {savanna_streets_straight_05, 6}},
        {"savanna/streets/straight_06", {savanna_streets_straight_06, 4}},
        {"savanna/streets/straight_08", {savanna_streets_straight_08, 5}},
        {"savanna/streets/straight_09", {savanna_streets_straight_09, 8}},
        {"savanna/streets/straight_10", {savanna_streets_straight_10, 2}},
        {"savanna/streets/straight_11", {savanna_streets_straight_11, 3}},
        {"savanna/streets/turn_01", {savanna_streets_turn_01, 5}},
        {"savanna/terminators/terminator_05", {savanna_terminators_terminator_05, 5}},
        {"savanna/town_centers/savanna_meeting_point_1", {savanna_town_centers_savanna_meeting_point_1, 10}},
        {"savanna/town_centers/savanna_meeting_point_2", {savanna_town_centers_savanna_meeting_point_2, 10}},
        {"savanna/town_centers/savanna_meeting_point_3", {savanna_town_centers_savanna_meeting_point_3, 10}},
        {"savanna/town_centers/savanna_meeting_point_4", {savanna_town_centers_savanna_meeting_point_4, 9}},
        {"savanna/villagers/baby", {savanna_villagers_baby, 1}},
        {"savanna/villagers/nitwit", {savanna_villagers_nitwit, 1}},
        {"savanna/villagers/unemployed", {savanna_villagers_unemployed, 1}},
        {"savanna/zombie/houses/savanna_animal_pen_2", {savanna_zombie_houses_savanna_animal_pen_2, 6}},
        {"savanna/zombie/houses/savanna_animal_pen_3", {savanna_zombie_houses_savanna_animal_pen_3, 3}},
        {"savanna/zombie/houses/savanna_large_farm_2", {savanna_zombie_houses_savanna_large_farm_2, 2}},
        {"savanna/zombie/houses/savanna_medium_house_1", {savanna_zombie_houses_savanna_medium_house_1, 4}},
        {"savanna/zombie/houses/savanna_medium_house_2", {savanna_zombie_houses_savanna_medium_house_2, 4}},
        {"savanna/zombie/houses/savanna_small_house_1", {savanna_zombie_houses_savanna_small_house_1, 2}},
        {"savanna/zombie/houses/savanna_small_house_2", {savanna_zombie_houses_savanna_small_house_2, 2}},
        {"savanna/zombie/houses/savanna_small_house_3", {savanna_zombie_houses_savanna_small_house_3, 2}},
        {"savanna/zombie/houses/savanna_small_house_4", {savanna_zombie_houses_savanna_small_house_4, 2}},
        {"savanna/zombie/houses/savanna_small_house_5", {savanna_zombie_houses_savanna_small_house_5, 2}},
        {"savanna/zombie/houses/savanna_small_house_6", {savanna_zombie_houses_savanna_small_house_6, 3}},
        {"savanna/zombie/houses/savanna_small_house_7", {savanna_zombie_houses_savanna_small_house_7, 2}},
        {"savanna/zombie/houses/savanna_small_house_8", {savanna_zombie_houses_savanna_small_house_8, 2}},
        {"savanna/zombie/streets/corner_01", {savanna_zombie_streets_corner_01, 7}},
        {"savanna/zombie/streets/corner_03", {savanna_zombie_streets_corner_03, 2}},
        {"savanna/zombie/streets/crossroad_02", {savanna_zombie_streets_crossroad_02, 6}},
        {"savanna/zombie/streets/crossroad_03", {savanna_zombie_streets_crossroad_03, 8}},
        {"savanna/zombie/streets/crossroad_04", {savanna_zombie_streets_crossroad_04, 3}},
        {"savanna/zombie/streets/crossroad_05", {savanna_zombie_streets_crossroad_05, 4}},
        {"savanna/zombie/streets/crossroad_06", {savanna_zombie_streets_crossroad_06, 5}},
        {"savanna/zombie/streets/crossroad_07", {savanna_zombie_streets_crossroad_07, 6}},
        {"savanna/zombie/streets/split_01", {savanna_zombie_streets_split_01, 4}},
        {"savanna/zombie/streets/split_02", {savanna_zombie_streets_split_02, 4}},
        {"savanna/zombie/streets/straight_02", {savanna_zombie_streets_straight_02, 8}},
        {"savanna/zombie/streets/straight_04", {savanna_zombie_streets_straight_04, 3}},
        {"savanna/zombie/streets/straight_05", {savanna_zombie_streets_straight_05, 6}},
        {"savanna/zombie/streets/straight_06", {savanna_zombie_streets_straight_06, 4}},
        {"savanna/zombie/streets/straight_08", {savanna_zombie_streets_straight_08, 4}},
        {"savanna/zombie/streets/straight_09", {savanna_zombie_streets_straight_09, 8}},
        {"savanna/zombie/streets/straight_10", {savanna_zombie_streets_straight_10, 2}},
        {"savanna/zombie/streets/straight_11", {savanna_zombie_streets_straight_11, 3}},
        {"savanna/zombie/streets/turn_01", {savanna_zombie_streets_turn_01, 4}},
        {"savanna/zombie/terminators/terminator_05", {savanna_zombie_terminators_terminator_05, 5}},
        {"savanna/zombie/town_centers/savanna_meeting_point_1", {savanna_zombie_town_centers_savanna_meeting_point_1, 3}},
        {"savanna/zombie/town_centers/savanna_meeting_point_2", {savanna_zombie_town_centers_savanna_meeting_point_2, 6}},
        {"savanna/zombie/town_centers/savanna_meeting_point_3", {savanna_zombie_town_centers_savanna_meeting_point_3, 7}},
        {"savanna/zombie/town_centers/savanna_meeting_point_4", {savanna_zombie_town_centers_savanna_meeting_point_4, 6}},
        {"savanna/zombie/villagers/nitwit", {savanna_zombie_villagers_nitwit, 1}},
        {"savanna/zombie/villagers/unemployed", {savanna_zombie_villagers_unemployed, 1}},
    };
    
    auto it = LOOKUP.find(templateName);
    if (it != LOOKUP.end()) {
        return std::vector<JigsawBlockEntry>(it->second.first, it->second.first + it->second.second);
    }
    return {};
}

// Version sans allocation (plus rapide)
inline bool getSavannaVillageJigsawBlocksFast(const std::string& templateName, const JigsawBlockEntry*& out, size_t& count) {
    using namespace SavannaVillageJigsawData;
    
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
        {"pile_melon", {pile_melon, 1}},
        {"plains/terminators/terminator_01", {plains_terminators_terminator_01, 1}},
        {"plains/terminators/terminator_02", {plains_terminators_terminator_02, 1}},
        {"plains/terminators/terminator_03", {plains_terminators_terminator_03, 1}},
        {"plains/terminators/terminator_04", {plains_terminators_terminator_04, 1}},
        {"savanna/acacia", {savanna_acacia, 1}},
        {"savanna/houses/savanna_animal_pen_1", {savanna_houses_savanna_animal_pen_1, 2}},
        {"savanna/houses/savanna_animal_pen_2", {savanna_houses_savanna_animal_pen_2, 6}},
        {"savanna/houses/savanna_animal_pen_3", {savanna_houses_savanna_animal_pen_3, 3}},
        {"savanna/houses/savanna_armorer_1", {savanna_houses_savanna_armorer_1, 1}},
        {"savanna/houses/savanna_butchers_shop_1", {savanna_houses_savanna_butchers_shop_1, 2}},
        {"savanna/houses/savanna_butchers_shop_2", {savanna_houses_savanna_butchers_shop_2, 2}},
        {"savanna/houses/savanna_cartographer_1", {savanna_houses_savanna_cartographer_1, 2}},
        {"savanna/houses/savanna_fisher_cottage_1", {savanna_houses_savanna_fisher_cottage_1, 4}},
        {"savanna/houses/savanna_fletcher_house_1", {savanna_houses_savanna_fletcher_house_1, 1}},
        {"savanna/houses/savanna_large_farm_1", {savanna_houses_savanna_large_farm_1, 1}},
        {"savanna/houses/savanna_large_farm_2", {savanna_houses_savanna_large_farm_2, 2}},
        {"savanna/houses/savanna_library_1", {savanna_houses_savanna_library_1, 1}},
        {"savanna/houses/savanna_mason_1", {savanna_houses_savanna_mason_1, 1}},
        {"savanna/houses/savanna_medium_house_1", {savanna_houses_savanna_medium_house_1, 4}},
        {"savanna/houses/savanna_medium_house_2", {savanna_houses_savanna_medium_house_2, 4}},
        {"savanna/houses/savanna_shepherd_1", {savanna_houses_savanna_shepherd_1, 3}},
        {"savanna/houses/savanna_small_farm", {savanna_houses_savanna_small_farm, 1}},
        {"savanna/houses/savanna_small_house_1", {savanna_houses_savanna_small_house_1, 2}},
        {"savanna/houses/savanna_small_house_2", {savanna_houses_savanna_small_house_2, 2}},
        {"savanna/houses/savanna_small_house_3", {savanna_houses_savanna_small_house_3, 2}},
        {"savanna/houses/savanna_small_house_4", {savanna_houses_savanna_small_house_4, 2}},
        {"savanna/houses/savanna_small_house_5", {savanna_houses_savanna_small_house_5, 2}},
        {"savanna/houses/savanna_small_house_6", {savanna_houses_savanna_small_house_6, 3}},
        {"savanna/houses/savanna_small_house_7", {savanna_houses_savanna_small_house_7, 2}},
        {"savanna/houses/savanna_small_house_8", {savanna_houses_savanna_small_house_8, 2}},
        {"savanna/houses/savanna_tannery_1", {savanna_houses_savanna_tannery_1, 1}},
        {"savanna/houses/savanna_temple_1", {savanna_houses_savanna_temple_1, 1}},
        {"savanna/houses/savanna_temple_2", {savanna_houses_savanna_temple_2, 1}},
        {"savanna/houses/savanna_tool_smith_1", {savanna_houses_savanna_tool_smith_1, 1}},
        {"savanna/houses/savanna_weaponsmith_1", {savanna_houses_savanna_weaponsmith_1, 1}},
        {"savanna/houses/savanna_weaponsmith_2", {savanna_houses_savanna_weaponsmith_2, 1}},
        {"savanna/savanna_lamp_post_01", {savanna_savanna_lamp_post_01, 1}},
        {"savanna/streets/corner_01", {savanna_streets_corner_01, 7}},
        {"savanna/streets/corner_03", {savanna_streets_corner_03, 2}},
        {"savanna/streets/crossroad_02", {savanna_streets_crossroad_02, 6}},
        {"savanna/streets/crossroad_03", {savanna_streets_crossroad_03, 8}},
        {"savanna/streets/crossroad_04", {savanna_streets_crossroad_04, 3}},
        {"savanna/streets/crossroad_05", {savanna_streets_crossroad_05, 4}},
        {"savanna/streets/crossroad_06", {savanna_streets_crossroad_06, 5}},
        {"savanna/streets/crossroad_07", {savanna_streets_crossroad_07, 6}},
        {"savanna/streets/split_01", {savanna_streets_split_01, 4}},
        {"savanna/streets/split_02", {savanna_streets_split_02, 4}},
        {"savanna/streets/straight_02", {savanna_streets_straight_02, 8}},
        {"savanna/streets/straight_04", {savanna_streets_straight_04, 3}},
        {"savanna/streets/straight_05", {savanna_streets_straight_05, 6}},
        {"savanna/streets/straight_06", {savanna_streets_straight_06, 4}},
        {"savanna/streets/straight_08", {savanna_streets_straight_08, 5}},
        {"savanna/streets/straight_09", {savanna_streets_straight_09, 8}},
        {"savanna/streets/straight_10", {savanna_streets_straight_10, 2}},
        {"savanna/streets/straight_11", {savanna_streets_straight_11, 3}},
        {"savanna/streets/turn_01", {savanna_streets_turn_01, 5}},
        {"savanna/terminators/terminator_05", {savanna_terminators_terminator_05, 5}},
        {"savanna/town_centers/savanna_meeting_point_1", {savanna_town_centers_savanna_meeting_point_1, 10}},
        {"savanna/town_centers/savanna_meeting_point_2", {savanna_town_centers_savanna_meeting_point_2, 10}},
        {"savanna/town_centers/savanna_meeting_point_3", {savanna_town_centers_savanna_meeting_point_3, 10}},
        {"savanna/town_centers/savanna_meeting_point_4", {savanna_town_centers_savanna_meeting_point_4, 9}},
        {"savanna/villagers/baby", {savanna_villagers_baby, 1}},
        {"savanna/villagers/nitwit", {savanna_villagers_nitwit, 1}},
        {"savanna/villagers/unemployed", {savanna_villagers_unemployed, 1}},
        {"savanna/zombie/houses/savanna_animal_pen_2", {savanna_zombie_houses_savanna_animal_pen_2, 6}},
        {"savanna/zombie/houses/savanna_animal_pen_3", {savanna_zombie_houses_savanna_animal_pen_3, 3}},
        {"savanna/zombie/houses/savanna_large_farm_2", {savanna_zombie_houses_savanna_large_farm_2, 2}},
        {"savanna/zombie/houses/savanna_medium_house_1", {savanna_zombie_houses_savanna_medium_house_1, 4}},
        {"savanna/zombie/houses/savanna_medium_house_2", {savanna_zombie_houses_savanna_medium_house_2, 4}},
        {"savanna/zombie/houses/savanna_small_house_1", {savanna_zombie_houses_savanna_small_house_1, 2}},
        {"savanna/zombie/houses/savanna_small_house_2", {savanna_zombie_houses_savanna_small_house_2, 2}},
        {"savanna/zombie/houses/savanna_small_house_3", {savanna_zombie_houses_savanna_small_house_3, 2}},
        {"savanna/zombie/houses/savanna_small_house_4", {savanna_zombie_houses_savanna_small_house_4, 2}},
        {"savanna/zombie/houses/savanna_small_house_5", {savanna_zombie_houses_savanna_small_house_5, 2}},
        {"savanna/zombie/houses/savanna_small_house_6", {savanna_zombie_houses_savanna_small_house_6, 3}},
        {"savanna/zombie/houses/savanna_small_house_7", {savanna_zombie_houses_savanna_small_house_7, 2}},
        {"savanna/zombie/houses/savanna_small_house_8", {savanna_zombie_houses_savanna_small_house_8, 2}},
        {"savanna/zombie/streets/corner_01", {savanna_zombie_streets_corner_01, 7}},
        {"savanna/zombie/streets/corner_03", {savanna_zombie_streets_corner_03, 2}},
        {"savanna/zombie/streets/crossroad_02", {savanna_zombie_streets_crossroad_02, 6}},
        {"savanna/zombie/streets/crossroad_03", {savanna_zombie_streets_crossroad_03, 8}},
        {"savanna/zombie/streets/crossroad_04", {savanna_zombie_streets_crossroad_04, 3}},
        {"savanna/zombie/streets/crossroad_05", {savanna_zombie_streets_crossroad_05, 4}},
        {"savanna/zombie/streets/crossroad_06", {savanna_zombie_streets_crossroad_06, 5}},
        {"savanna/zombie/streets/crossroad_07", {savanna_zombie_streets_crossroad_07, 6}},
        {"savanna/zombie/streets/split_01", {savanna_zombie_streets_split_01, 4}},
        {"savanna/zombie/streets/split_02", {savanna_zombie_streets_split_02, 4}},
        {"savanna/zombie/streets/straight_02", {savanna_zombie_streets_straight_02, 8}},
        {"savanna/zombie/streets/straight_04", {savanna_zombie_streets_straight_04, 3}},
        {"savanna/zombie/streets/straight_05", {savanna_zombie_streets_straight_05, 6}},
        {"savanna/zombie/streets/straight_06", {savanna_zombie_streets_straight_06, 4}},
        {"savanna/zombie/streets/straight_08", {savanna_zombie_streets_straight_08, 4}},
        {"savanna/zombie/streets/straight_09", {savanna_zombie_streets_straight_09, 8}},
        {"savanna/zombie/streets/straight_10", {savanna_zombie_streets_straight_10, 2}},
        {"savanna/zombie/streets/straight_11", {savanna_zombie_streets_straight_11, 3}},
        {"savanna/zombie/streets/turn_01", {savanna_zombie_streets_turn_01, 4}},
        {"savanna/zombie/terminators/terminator_05", {savanna_zombie_terminators_terminator_05, 5}},
        {"savanna/zombie/town_centers/savanna_meeting_point_1", {savanna_zombie_town_centers_savanna_meeting_point_1, 3}},
        {"savanna/zombie/town_centers/savanna_meeting_point_2", {savanna_zombie_town_centers_savanna_meeting_point_2, 6}},
        {"savanna/zombie/town_centers/savanna_meeting_point_3", {savanna_zombie_town_centers_savanna_meeting_point_3, 7}},
        {"savanna/zombie/town_centers/savanna_meeting_point_4", {savanna_zombie_town_centers_savanna_meeting_point_4, 6}},
        {"savanna/zombie/villagers/nitwit", {savanna_zombie_villagers_nitwit, 1}},
        {"savanna/zombie/villagers/unemployed", {savanna_zombie_villagers_unemployed, 1}},
    };
    
    auto it = LOOKUP.find(templateName);
    if (it != LOOKUP.end()) {
        out = it->second.first;
        count = it->second.second;
        return true;
    }
    return false;
}
