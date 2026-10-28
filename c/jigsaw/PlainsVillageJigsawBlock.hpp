#pragma once
// Auto-generated from PlainsVillageJigsawBlock.java
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
namespace PlainsVillageJigsawData {

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
        {PoolType::WELL_BOTTOM, "bottom", BlockDirection::UP, BlockDirection::SOUTH, 4, 3, 4},
    };

    static const JigsawBlockEntry flower_plain[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry oak[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry patch_cactus[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry pile_hay[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry plains_houses_plains_accessory_1[] = {
        {PoolType::PLAIN_STREET, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 0},
    };

    static const JigsawBlockEntry plains_houses_plains_animal_pen_1[] = {
        {PoolType::ANIMALS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 1},
        {PoolType::PLAIN_TREE, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 4},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 2},
    };

    static const JigsawBlockEntry plains_houses_plains_animal_pen_2[] = {
        {PoolType::ANIMALS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 3},
        {PoolType::PLAIN_TREE, "bottom", BlockDirection::UP, BlockDirection::NORTH, 4, 0, 2},
        {PoolType::ANIMALS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 4, 0, 7},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 5},
    };

    static const JigsawBlockEntry plains_houses_plains_animal_pen_3[] = {
        {PoolType::PLAIN_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 0, 0},
        {PoolType::PLAIN_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 10},
        {PoolType::ANIMALS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 5},
        {PoolType::PLAIN_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 7},
        {PoolType::ANIMALS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 4, 0, 1},
        {PoolType::PLAIN_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 4, 0, 3},
        {PoolType::ANIMALS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 5, 0, 5},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 5},
    };

    static const JigsawBlockEntry plains_houses_plains_armorer_house_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 4},
    };

    static const JigsawBlockEntry plains_houses_plains_big_house_1[] = {
        {PoolType::PLAIN_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 3},
        {PoolType::PLAIN_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 8},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 5},
        {PoolType::PLAIN_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 4, 2},
        {PoolType::PLAIN_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 4, 8},
    };

    static const JigsawBlockEntry plains_houses_plains_butcher_shop_1[] = {
        {PoolType::PLAIN_STREET, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 3},
        {PoolType::BUTCHER_ANIMAL, "bottom", BlockDirection::UP, BlockDirection::NORTH, 6, 0, 9},
    };

    static const JigsawBlockEntry plains_houses_plains_butcher_shop_2[] = {
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 0, 0},
        {PoolType::PLAIN_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 5, 0, 6},
        {PoolType::BUTCHER_ANIMAL, "bottom", BlockDirection::UP, BlockDirection::NORTH, 12, 0, 3},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 13, 0, 6},
        {PoolType::PLAIN_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 14, 0, 0},
        {PoolType::PLAIN_STREET, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 3},
    };

    static const JigsawBlockEntry plains_houses_plains_cartographer_1[] = {
        {PoolType::PLAIN_STREET, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 3},
    };

    static const JigsawBlockEntry plains_houses_plains_fisher_cottage_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 2, 7},
    };

    static const JigsawBlockEntry plains_houses_plains_fletcher_house_1[] = {
        {PoolType::PLAIN_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 1},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 6},
    };

    static const JigsawBlockEntry plains_houses_plains_large_farm_1[] = {
        {PoolType::PLAIN_STREET, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 4},
    };

    static const JigsawBlockEntry plains_houses_plains_library_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 8},
    };

    static const JigsawBlockEntry plains_houses_plains_library_2[] = {
        {PoolType::PLAIN_STREET, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 4},
    };

    static const JigsawBlockEntry plains_houses_plains_masons_house_1[] = {
        {PoolType::PLAIN_STREET, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 3},
    };

    static const JigsawBlockEntry plains_houses_plains_medium_house_1[] = {
        {PoolType::PLAIN_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 10, 0, 0},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 4},
        {PoolType::PLAIN_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 4, 1, 7},
        {PoolType::PLAIN_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 6, 1, 6},
    };

    static const JigsawBlockEntry plains_houses_plains_medium_house_2[] = {
        {PoolType::PLAIN_STREET, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 6},
        {PoolType::PLAIN_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 4},
        {PoolType::PLAIN_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 8},
    };

    static const JigsawBlockEntry plains_houses_plains_meeting_point_4[] = {
        {PoolType::PLAIN_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 1},
        {PoolType::PLAIN_TREE, "bottom", BlockDirection::UP, BlockDirection::NORTH, 7, 0, 9},
        {PoolType::PLAIN_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 7, 0, 13},
        {PoolType::PLAIN_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 0, 2},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 8},
    };

    static const JigsawBlockEntry plains_houses_plains_meeting_point_5[] = {
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 6},
        {PoolType::PLAIN_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 7, 0, 2},
        {PoolType::PLAIN_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 0, 8},
        {PoolType::PLAIN_STREET, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 5},
    };

    static const JigsawBlockEntry plains_houses_plains_shepherds_house_1[] = {
        {PoolType::PLAIN_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 0, 0},
        {PoolType::SHEEPS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 7, 0, 5},
        {PoolType::PLAIN_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 0, 1},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 4},
    };

    static const JigsawBlockEntry plains_houses_plains_small_farm_1[] = {
        {PoolType::PLAIN_STREET, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 4},
    };

    static const JigsawBlockEntry plains_houses_plains_small_house_1[] = {
        {PoolType::PLAIN_STREET, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 3},
        {PoolType::PLAIN_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 3},
    };

    static const JigsawBlockEntry plains_houses_plains_small_house_2[] = {
        {PoolType::PLAIN_STREET, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 3},
        {PoolType::PLAIN_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 3},
    };

    static const JigsawBlockEntry plains_houses_plains_small_house_3[] = {
        {PoolType::PLAIN_STREET, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 3},
        {PoolType::PLAIN_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 3},
    };

    static const JigsawBlockEntry plains_houses_plains_small_house_4[] = {
        {PoolType::PLAIN_STREET, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 3},
        {PoolType::PLAIN_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 3},
    };

    static const JigsawBlockEntry plains_houses_plains_small_house_5[] = {
        {PoolType::PLAIN_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 0, 1},
        {PoolType::PLAIN_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 7},
        {PoolType::PLAIN_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 0, 3},
        {PoolType::PLAIN_STREET, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 4},
        {PoolType::PLAIN_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 1, 2},
    };

    static const JigsawBlockEntry plains_houses_plains_small_house_6[] = {
        {PoolType::PLAIN_STREET, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 3},
        {PoolType::PLAIN_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 4},
    };

    static const JigsawBlockEntry plains_houses_plains_small_house_7[] = {
        {PoolType::PLAIN_STREET, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 4},
        {PoolType::PLAIN_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 4},
    };

    static const JigsawBlockEntry plains_houses_plains_small_house_8[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 2, 4},
        {PoolType::PLAIN_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 2, 4},
    };

    static const JigsawBlockEntry plains_houses_plains_stable_1[] = {
        {PoolType::PLAIN_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 0, 11},
        {PoolType::PLAIN_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 0, 15},
        {PoolType::ANIMALS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 2},
        {PoolType::ANIMALS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 4, 0, 10},
        {PoolType::PLAIN_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 6, 0, 1},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 7, 0, 7},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 7, 0, 14},
        {PoolType::PLAIN_STREET, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 8},
    };

    static const JigsawBlockEntry plains_houses_plains_stable_2[] = {
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 0, 3},
        {PoolType::ANIMALS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 2},
        {PoolType::ANIMALS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 4},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 6, 0, 1},
        {PoolType::PLAIN_STREET, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 9},
    };

    static const JigsawBlockEntry plains_houses_plains_tannery_1[] = {
        {PoolType::PLAIN_STREET, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 7},
    };

    static const JigsawBlockEntry plains_houses_plains_temple_3[] = {
        {PoolType::PLAIN_STREET, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 3},
    };

    static const JigsawBlockEntry plains_houses_plains_temple_4[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 3},
    };

    static const JigsawBlockEntry plains_houses_plains_tool_smith_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 8},
    };

    static const JigsawBlockEntry plains_houses_plains_weaponsmith_1[] = {
        {PoolType::PLAIN_STREET, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 3},
    };

    static const JigsawBlockEntry plains_plains_lamp_1[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 1, 0, 1},
    };

    static const JigsawBlockEntry plains_streets_corner_01[] = {
        {PoolType::PLAIN_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 4},
        {PoolType::PLAIN_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 13},
        {PoolType::PLAIN_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 0, 12},
        {PoolType::PLAIN_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 10, 0, 3},
        {PoolType::PLAIN_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 13, 0, 9},
        {PoolType::PLAIN_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 8},
        {PoolType::PLAIN_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 7, 1, 0},
        {PoolType::PLAIN_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 8, 1, 6},
    };

    static const JigsawBlockEntry plains_streets_corner_02[] = {
        {PoolType::PLAIN_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 1, 1, 0},
        {PoolType::PLAIN_HOUSES, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 9, 1, 12},
        {PoolType::PLAIN_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 15, 1, 14},
    };

    static const JigsawBlockEntry plains_streets_corner_03[] = {
        {PoolType::PLAIN_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 1, 1, 3},
        {PoolType::PLAIN_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 3, 1, 1},
    };

    static const JigsawBlockEntry plains_streets_crossroad_01[] = {
        {PoolType::PLAIN_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 13, 0, 12},
        {PoolType::PLAIN_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 3},
        {PoolType::PLAIN_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 4},
        {PoolType::PLAIN_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 5},
        {PoolType::PLAIN_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 6},
        {PoolType::PLAIN_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 7},
        {PoolType::PLAIN_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 11},
        {PoolType::PLAIN_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 12},
        {PoolType::PLAIN_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 8, 1, 0},
        {PoolType::PLAIN_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 8, 1, 15},
        {PoolType::PLAIN_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 9, 1, 3},
        {PoolType::PLAIN_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 9, 1, 4},
        {PoolType::PLAIN_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 15, 1, 8},
    };

    static const JigsawBlockEntry plains_streets_crossroad_02[] = {
        {PoolType::PLAIN_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 5},
        {PoolType::PLAIN_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 5, 0, 1},
        {PoolType::PLAIN_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 11, 0, 5},
        {PoolType::PLAIN_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 13, 0, 12},
        {PoolType::PLAIN_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 14, 0, 2},
        {PoolType::PLAIN_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 8},
        {PoolType::PLAIN_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 8, 1, 0},
        {PoolType::PLAIN_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 8, 1, 15},
        {PoolType::PLAIN_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 15, 1, 8},
    };

    static const JigsawBlockEntry plains_streets_crossroad_03[] = {
        {PoolType::PLAIN_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 13},
        {PoolType::PLAIN_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 0, 11},
        {PoolType::PLAIN_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 8},
        {PoolType::PLAIN_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 4, 1, 0},
        {PoolType::PLAIN_HOUSES, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 11, 1, 7},
        {PoolType::PLAIN_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 11, 1, 15},
        {PoolType::PLAIN_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 15, 1, 8},
    };

    static const JigsawBlockEntry plains_streets_crossroad_04[] = {
        {PoolType::PLAIN_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 2},
        {PoolType::PLAIN_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 2, 1, 0},
        {PoolType::PLAIN_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 2, 1, 4},
    };

    static const JigsawBlockEntry plains_streets_crossroad_05[] = {
        {PoolType::PLAIN_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 2},
        {PoolType::PLAIN_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 2, 1, 0},
        {PoolType::PLAIN_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 2, 1, 4},
        {PoolType::PLAIN_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 4, 1, 2},
    };

    static const JigsawBlockEntry plains_streets_crossroad_06[] = {
        {PoolType::PLAIN_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 2},
        {PoolType::PLAIN_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 2},
        {PoolType::PLAIN_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 2, 1, 0},
        {PoolType::PLAIN_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 2, 1, 4},
        {PoolType::PLAIN_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 4, 1, 2},
    };

    static const JigsawBlockEntry plains_streets_straight_01[] = {
        {PoolType::PLAIN_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 13},
        {PoolType::PLAIN_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 4, 0, 7},
        {PoolType::PLAIN_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 11, 0, 6},
        {PoolType::PLAIN_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 11, 0, 13},
        {PoolType::PLAIN_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 12, 0, 4},
        {PoolType::PLAIN_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 7, 1, 0},
        {PoolType::PLAIN_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 7, 1, 15},
    };

    static const JigsawBlockEntry plains_streets_straight_02[] = {
        {PoolType::PLAIN_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 1, 1, 0},
        {PoolType::PLAIN_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 1, 1, 15},
        {PoolType::PLAIN_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 8},
    };

    static const JigsawBlockEntry plains_streets_straight_03[] = {
        {PoolType::PLAIN_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 1, 1, 0},
        {PoolType::PLAIN_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 1, 1, 10},
        {PoolType::PLAIN_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 3},
        {PoolType::PLAIN_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 4},
        {PoolType::PLAIN_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 5},
        {PoolType::PLAIN_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 6},
        {PoolType::PLAIN_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 7},
    };

    static const JigsawBlockEntry plains_streets_straight_04[] = {
        {PoolType::PLAIN_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 1, 1, 0},
        {PoolType::PLAIN_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 1, 1, 8},
        {PoolType::PLAIN_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 4},
    };

    static const JigsawBlockEntry plains_streets_straight_05[] = {
        {PoolType::PLAIN_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 1, 1, 0},
        {PoolType::PLAIN_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 1, 1, 16},
        {PoolType::PLAIN_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 7},
        {PoolType::PLAIN_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 8},
        {PoolType::PLAIN_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 9},
        {PoolType::PLAIN_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 10},
    };

    static const JigsawBlockEntry plains_streets_straight_06[] = {
        {PoolType::PLAIN_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 0, 3},
        {PoolType::PLAIN_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 9, 0, 9},
        {PoolType::PLAIN_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 9, 0, 15},
        {PoolType::PLAIN_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 3},
        {PoolType::PLAIN_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 4},
        {PoolType::PLAIN_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 8, 1, 0},
        {PoolType::PLAIN_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 8, 1, 8},
        {PoolType::PLAIN_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 8, 1, 9},
        {PoolType::PLAIN_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 8, 1, 14},
        {PoolType::PLAIN_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 8, 1, 15},
        {PoolType::PLAIN_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 9, 1, 2},
        {PoolType::PLAIN_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 9, 1, 3},
        {PoolType::PLAIN_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 9, 1, 4},
        {PoolType::PLAIN_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 9, 1, 17},
        {PoolType::PLAIN_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 10, 1, 8},
        {PoolType::PLAIN_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 10, 1, 9},
        {PoolType::PLAIN_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 10, 1, 10},
        {PoolType::PLAIN_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 10, 1, 14},
        {PoolType::PLAIN_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 10, 1, 15},
    };

    static const JigsawBlockEntry plains_streets_turn_01[] = {
        {PoolType::PLAIN_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 5, 1, 0},
        {PoolType::PLAIN_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 6},
        {PoolType::PLAIN_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 8, 1, 7},
        {PoolType::PLAIN_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 9, 1, 4},
    };

    static const JigsawBlockEntry plains_terminators_terminator_01[] = {
        {PoolType::EMPTY, "street", BlockDirection::EAST, BlockDirection::UP, 1, 1, 1},
    };

    static const JigsawBlockEntry plains_terminators_terminator_02[] = {
        {PoolType::EMPTY, "street", BlockDirection::EAST, BlockDirection::UP, 0, 1, 0},
    };

    static const JigsawBlockEntry plains_terminators_terminator_03[] = {
        {PoolType::EMPTY, "street", BlockDirection::EAST, BlockDirection::UP, 2, 1, 1},
    };

    static const JigsawBlockEntry plains_terminators_terminator_04[] = {
        {PoolType::EMPTY, "street", BlockDirection::EAST, BlockDirection::UP, 3, 1, 1},
    };

    static const JigsawBlockEntry plains_town_centers_plains_fountain_01[] = {
        {PoolType::IRON_GOLEM, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 0, 6},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 2},
        {PoolType::PLAIN_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 1},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 7},
        {PoolType::PLAIN_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 7, 0, 2},
        {PoolType::PLAIN_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 7, 0, 7},
        {PoolType::PLAIN_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 4},
        {PoolType::PLAIN_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 4, 1, 0},
        {PoolType::PLAIN_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 4, 1, 8},
        {PoolType::PLAIN_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 8, 1, 4},
    };

    static const JigsawBlockEntry plains_town_centers_plains_meeting_point_1[] = {
        {PoolType::PLAIN_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 1},
        {PoolType::IRON_GOLEM, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 6},
        {PoolType::PLAIN_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 8},
        {PoolType::WELL_BOTTOM, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 6, 0, 3},
        {PoolType::PLAIN_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 4},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 1, 2},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 1, 4},
        {PoolType::PLAIN_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 4, 1, 9},
        {PoolType::PLAIN_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 5, 1, 0},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 5, 1, 7},
        {PoolType::PLAIN_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 9, 1, 5},
    };

    static const JigsawBlockEntry plains_town_centers_plains_meeting_point_2[] = {
        {PoolType::IRON_GOLEM, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 4},
        {PoolType::PLAIN_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 6},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 11},
        {PoolType::PLAIN_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 8},
        {PoolType::PLAIN_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 10},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 4},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 4, 0, 11},
        {PoolType::PLAIN_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 7},
        {PoolType::PLAIN_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 5, 1, 0},
        {PoolType::PLAIN_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 5, 1, 14},
        {PoolType::PLAIN_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 7, 1, 3},
    };

    static const JigsawBlockEntry plains_town_centers_plains_meeting_point_3[] = {
        {PoolType::PLAIN_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 2},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 4},
        {PoolType::PLAIN_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 6},
        {PoolType::IRON_GOLEM, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 7},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 3},
        {PoolType::PLAIN_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 5},
        {PoolType::PLAIN_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 5, 1, 10},
        {PoolType::PLAIN_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 10, 1, 5},
    };

    static const JigsawBlockEntry plains_villagers_baby[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry plains_villagers_nitwit[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry plains_villagers_unemployed[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry plains_zombie_houses_plains_animal_pen_3[] = {
        {PoolType::PLAIN_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 0, 0},
        {PoolType::PLAIN_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 10},
        {PoolType::ANIMALS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 5},
        {PoolType::PLAIN_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 7},
        {PoolType::ANIMALS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 4, 0, 1},
        {PoolType::PLAIN_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 4, 0, 3},
        {PoolType::ANIMALS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 5, 0, 5},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 5},
    };

    static const JigsawBlockEntry plains_zombie_houses_plains_big_house_1[] = {
        {PoolType::PLAIN_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 3},
        {PoolType::PLAIN_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 8},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 5},
        {PoolType::PLAIN_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 4, 2},
        {PoolType::PLAIN_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 4, 8},
    };

    static const JigsawBlockEntry plains_zombie_houses_plains_butcher_shop_2[] = {
        {PoolType::PLAIN_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 5, 0, 6},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 11, 0, 6},
        {PoolType::BUTCHER_ANIMAL, "bottom", BlockDirection::UP, BlockDirection::NORTH, 12, 0, 3},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 13, 0, 6},
        {PoolType::PLAIN_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 14, 0, 0},
        {PoolType::PLAIN_ZSTREET, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 3},
    };

    static const JigsawBlockEntry plains_zombie_houses_plains_fletcher_house_1[] = {
        {PoolType::PLAIN_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 1},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 6},
    };

    static const JigsawBlockEntry plains_zombie_houses_plains_medium_house_1[] = {
        {PoolType::PLAIN_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 10, 0, 0},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 4},
        {PoolType::PLAIN_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 4, 1, 7},
        {PoolType::PLAIN_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 6, 1, 6},
    };

    static const JigsawBlockEntry plains_zombie_houses_plains_medium_house_2[] = {
        {PoolType::PLAIN_ZSTREET, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 6},
        {PoolType::PLAIN_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 4},
        {PoolType::PLAIN_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 8},
    };

    static const JigsawBlockEntry plains_zombie_houses_plains_meeting_point_4[] = {
        {PoolType::PLAIN_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 1},
        {PoolType::PLAIN_TREE, "bottom", BlockDirection::UP, BlockDirection::NORTH, 7, 0, 9},
        {PoolType::PLAIN_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 7, 0, 13},
        {PoolType::PLAIN_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 0, 2},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 8},
    };

    static const JigsawBlockEntry plains_zombie_houses_plains_meeting_point_5[] = {
        {PoolType::PLAIN_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 7, 0, 2},
        {PoolType::PLAIN_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 0, 8},
        {PoolType::PLAIN_ZSTREET, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 5},
    };

    static const JigsawBlockEntry plains_zombie_houses_plains_shepherds_house_1[] = {
        {PoolType::PLAIN_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 0, 0},
        {PoolType::SHEEPS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 7, 0, 5},
        {PoolType::PLAIN_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 0, 1},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 4},
    };

    static const JigsawBlockEntry plains_zombie_houses_plains_small_house_1[] = {
        {PoolType::PLAIN_ZSTREET, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 3},
        {PoolType::PLAIN_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 3},
    };

    static const JigsawBlockEntry plains_zombie_houses_plains_small_house_2[] = {
        {PoolType::PLAIN_ZSTREET, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 3},
        {PoolType::PLAIN_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 3},
    };

    static const JigsawBlockEntry plains_zombie_houses_plains_small_house_3[] = {
        {PoolType::PLAIN_ZSTREET, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 3},
        {PoolType::PLAIN_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 3},
    };

    static const JigsawBlockEntry plains_zombie_houses_plains_small_house_4[] = {
        {PoolType::PLAIN_ZSTREET, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 3},
        {PoolType::PLAIN_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 3},
    };

    static const JigsawBlockEntry plains_zombie_houses_plains_small_house_5[] = {
        {PoolType::PLAIN_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 0, 1},
        {PoolType::PLAIN_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 7},
        {PoolType::PLAIN_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 0, 3},
        {PoolType::PLAIN_ZSTREET, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 4},
        {PoolType::PLAIN_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 1, 2},
    };

    static const JigsawBlockEntry plains_zombie_houses_plains_small_house_6[] = {
        {PoolType::PLAIN_ZSTREET, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 3},
        {PoolType::PLAIN_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 4},
    };

    static const JigsawBlockEntry plains_zombie_houses_plains_small_house_7[] = {
        {PoolType::PLAIN_ZSTREET, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 4},
        {PoolType::PLAIN_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 4},
    };

    static const JigsawBlockEntry plains_zombie_houses_plains_small_house_8[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 2, 4},
        {PoolType::PLAIN_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 2, 4},
    };

    static const JigsawBlockEntry plains_zombie_houses_plains_stable_1[] = {
        {PoolType::PLAIN_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 0, 11},
        {PoolType::PLAIN_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 0, 15},
        {PoolType::ANIMALS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 2},
        {PoolType::ANIMALS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 4, 0, 10},
        {PoolType::PLAIN_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 6, 0, 1},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 0, 8},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 0, 14},
        {PoolType::PLAIN_ZSTREET, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 8},
    };

    static const JigsawBlockEntry plains_zombie_streets_corner_01[] = {
        {PoolType::PLAIN_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 4},
        {PoolType::PLAIN_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 13},
        {PoolType::PLAIN_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 0, 12},
        {PoolType::PLAIN_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 10, 0, 3},
        {PoolType::PLAIN_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 13, 0, 9},
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 8},
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 7, 1, 0},
        {PoolType::PLAIN_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 8, 1, 6},
    };

    static const JigsawBlockEntry plains_zombie_streets_corner_02[] = {
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 1, 1, 0},
        {PoolType::PLAIN_ZHOUSES, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 9, 1, 12},
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::EAST, BlockDirection::UP, 15, 1, 14},
    };

    static const JigsawBlockEntry plains_zombie_streets_corner_03[] = {
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 1, 1, 3},
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::EAST, BlockDirection::UP, 3, 1, 1},
    };

    static const JigsawBlockEntry plains_zombie_streets_crossroad_01[] = {
        {PoolType::PLAIN_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 13, 0, 12},
        {PoolType::PLAIN_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 3},
        {PoolType::PLAIN_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 4},
        {PoolType::PLAIN_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 5},
        {PoolType::PLAIN_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 6},
        {PoolType::PLAIN_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 7},
        {PoolType::PLAIN_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 11},
        {PoolType::PLAIN_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 12},
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 8, 1, 0},
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 8, 1, 15},
        {PoolType::PLAIN_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 9, 1, 3},
        {PoolType::PLAIN_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 9, 1, 4},
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::EAST, BlockDirection::UP, 15, 1, 8},
    };

    static const JigsawBlockEntry plains_zombie_streets_crossroad_02[] = {
        {PoolType::PLAIN_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 5},
        {PoolType::PLAIN_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 5, 0, 1},
        {PoolType::PLAIN_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 11, 0, 5},
        {PoolType::PLAIN_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 13, 0, 12},
        {PoolType::PLAIN_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 14, 0, 2},
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 8},
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 8, 1, 0},
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 8, 1, 15},
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::EAST, BlockDirection::UP, 15, 1, 8},
    };

    static const JigsawBlockEntry plains_zombie_streets_crossroad_03[] = {
        {PoolType::PLAIN_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 13},
        {PoolType::PLAIN_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 0, 11},
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 8},
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 4, 1, 0},
        {PoolType::PLAIN_ZHOUSES, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 11, 1, 7},
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 11, 1, 15},
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::EAST, BlockDirection::UP, 15, 1, 8},
    };

    static const JigsawBlockEntry plains_zombie_streets_crossroad_04[] = {
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 2},
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 2, 1, 0},
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 2, 1, 4},
    };

    static const JigsawBlockEntry plains_zombie_streets_crossroad_05[] = {
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 2},
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 2, 1, 0},
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 2, 1, 4},
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::EAST, BlockDirection::UP, 4, 1, 2},
    };

    static const JigsawBlockEntry plains_zombie_streets_crossroad_06[] = {
        {PoolType::PLAIN_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 2},
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 2},
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 2, 1, 0},
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 2, 1, 4},
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::EAST, BlockDirection::UP, 4, 1, 2},
    };

    static const JigsawBlockEntry plains_zombie_streets_straight_01[] = {
        {PoolType::PLAIN_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 13},
        {PoolType::PLAIN_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 4, 0, 7},
        {PoolType::PLAIN_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 11, 0, 6},
        {PoolType::PLAIN_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 11, 0, 13},
        {PoolType::PLAIN_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 12, 0, 4},
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 7, 1, 0},
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 7, 1, 15},
    };

    static const JigsawBlockEntry plains_zombie_streets_straight_02[] = {
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 1, 1, 0},
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 1, 1, 15},
        {PoolType::PLAIN_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 8},
    };

    static const JigsawBlockEntry plains_zombie_streets_straight_03[] = {
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 1, 1, 0},
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 1, 1, 10},
        {PoolType::PLAIN_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 3},
        {PoolType::PLAIN_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 4},
        {PoolType::PLAIN_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 5},
        {PoolType::PLAIN_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 6},
        {PoolType::PLAIN_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 7},
    };

    static const JigsawBlockEntry plains_zombie_streets_straight_04[] = {
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 1, 1, 0},
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 1, 1, 8},
        {PoolType::PLAIN_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 4},
    };

    static const JigsawBlockEntry plains_zombie_streets_straight_05[] = {
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 1, 1, 0},
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 1, 1, 16},
        {PoolType::PLAIN_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 7},
        {PoolType::PLAIN_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 8},
        {PoolType::PLAIN_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 9},
        {PoolType::PLAIN_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 10},
    };

    static const JigsawBlockEntry plains_zombie_streets_straight_06[] = {
        {PoolType::PLAIN_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 0, 3},
        {PoolType::PLAIN_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 9, 0, 9},
        {PoolType::PLAIN_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 9, 0, 15},
        {PoolType::PLAIN_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 3},
        {PoolType::PLAIN_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 4},
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 8, 1, 0},
        {PoolType::PLAIN_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 8, 1, 8},
        {PoolType::PLAIN_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 8, 1, 9},
        {PoolType::PLAIN_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 8, 1, 14},
        {PoolType::PLAIN_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 8, 1, 15},
        {PoolType::PLAIN_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 9, 1, 2},
        {PoolType::PLAIN_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 9, 1, 3},
        {PoolType::PLAIN_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 9, 1, 4},
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 9, 1, 17},
        {PoolType::PLAIN_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 10, 1, 8},
        {PoolType::PLAIN_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 10, 1, 9},
        {PoolType::PLAIN_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 10, 1, 10},
        {PoolType::PLAIN_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 10, 1, 14},
        {PoolType::PLAIN_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 10, 1, 15},
    };

    static const JigsawBlockEntry plains_zombie_streets_turn_01[] = {
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 5, 1, 0},
        {PoolType::PLAIN_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 6},
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 8, 1, 7},
        {PoolType::PLAIN_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 9, 1, 4},
    };

    static const JigsawBlockEntry plains_zombie_town_centers_plains_fountain_01[] = {
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 2},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 7},
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 4},
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 4, 1, 0},
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 4, 1, 8},
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::EAST, BlockDirection::UP, 8, 1, 4},
    };

    static const JigsawBlockEntry plains_zombie_town_centers_plains_meeting_point_1[] = {
        {PoolType::WELL_BOTTOM, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 6, 0, 3},
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 4},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 1, 2},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 1, 4},
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 4, 1, 9},
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 5, 1, 0},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 5, 1, 7},
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::EAST, BlockDirection::UP, 9, 1, 5},
    };

    static const JigsawBlockEntry plains_zombie_town_centers_plains_meeting_point_2[] = {
        {PoolType::CATS, "bottom", BlockDirection::EAST, BlockDirection::UP, 2, 0, 5},
        {PoolType::CATS, "bottom", BlockDirection::EAST, BlockDirection::UP, 2, 0, 9},
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 7},
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 5, 1, 0},
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 5, 1, 14},
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 7, 1, 3},
    };

    static const JigsawBlockEntry plains_zombie_town_centers_plains_meeting_point_3[] = {
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 4},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 3},
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 5},
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 5, 1, 10},
        {PoolType::PLAIN_ZSTREET, "street", BlockDirection::EAST, BlockDirection::UP, 10, 1, 5},
    };

    static const JigsawBlockEntry plains_zombie_villagers_nitwit[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry plains_zombie_villagers_unemployed[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

} // namespace

// Fonction pour obtenir les JigsawBlocks d'un template
inline std::vector<JigsawBlockEntry> getPlainsVillageJigsawBlock(const std::string& templateName) {
    using namespace PlainsVillageJigsawData;
    
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
        {"flower_plain", {flower_plain, 1}},
        {"oak", {oak, 1}},
        {"patch_cactus", {patch_cactus, 1}},
        {"pile_hay", {pile_hay, 1}},
        {"plains/houses/plains_accessory_1", {plains_houses_plains_accessory_1, 1}},
        {"plains/houses/plains_animal_pen_1", {plains_houses_plains_animal_pen_1, 3}},
        {"plains/houses/plains_animal_pen_2", {plains_houses_plains_animal_pen_2, 4}},
        {"plains/houses/plains_animal_pen_3", {plains_houses_plains_animal_pen_3, 8}},
        {"plains/houses/plains_armorer_house_1", {plains_houses_plains_armorer_house_1, 1}},
        {"plains/houses/plains_big_house_1", {plains_houses_plains_big_house_1, 5}},
        {"plains/houses/plains_butcher_shop_1", {plains_houses_plains_butcher_shop_1, 2}},
        {"plains/houses/plains_butcher_shop_2", {plains_houses_plains_butcher_shop_2, 6}},
        {"plains/houses/plains_cartographer_1", {plains_houses_plains_cartographer_1, 1}},
        {"plains/houses/plains_fisher_cottage_1", {plains_houses_plains_fisher_cottage_1, 1}},
        {"plains/houses/plains_fletcher_house_1", {plains_houses_plains_fletcher_house_1, 2}},
        {"plains/houses/plains_large_farm_1", {plains_houses_plains_large_farm_1, 1}},
        {"plains/houses/plains_library_1", {plains_houses_plains_library_1, 1}},
        {"plains/houses/plains_library_2", {plains_houses_plains_library_2, 1}},
        {"plains/houses/plains_masons_house_1", {plains_houses_plains_masons_house_1, 1}},
        {"plains/houses/plains_medium_house_1", {plains_houses_plains_medium_house_1, 4}},
        {"plains/houses/plains_medium_house_2", {plains_houses_plains_medium_house_2, 3}},
        {"plains/houses/plains_meeting_point_4", {plains_houses_plains_meeting_point_4, 5}},
        {"plains/houses/plains_meeting_point_5", {plains_houses_plains_meeting_point_5, 4}},
        {"plains/houses/plains_shepherds_house_1", {plains_houses_plains_shepherds_house_1, 4}},
        {"plains/houses/plains_small_farm_1", {plains_houses_plains_small_farm_1, 1}},
        {"plains/houses/plains_small_house_1", {plains_houses_plains_small_house_1, 2}},
        {"plains/houses/plains_small_house_2", {plains_houses_plains_small_house_2, 2}},
        {"plains/houses/plains_small_house_3", {plains_houses_plains_small_house_3, 2}},
        {"plains/houses/plains_small_house_4", {plains_houses_plains_small_house_4, 2}},
        {"plains/houses/plains_small_house_5", {plains_houses_plains_small_house_5, 5}},
        {"plains/houses/plains_small_house_6", {plains_houses_plains_small_house_6, 2}},
        {"plains/houses/plains_small_house_7", {plains_houses_plains_small_house_7, 2}},
        {"plains/houses/plains_small_house_8", {plains_houses_plains_small_house_8, 2}},
        {"plains/houses/plains_stable_1", {plains_houses_plains_stable_1, 8}},
        {"plains/houses/plains_stable_2", {plains_houses_plains_stable_2, 5}},
        {"plains/houses/plains_tannery_1", {plains_houses_plains_tannery_1, 1}},
        {"plains/houses/plains_temple_3", {plains_houses_plains_temple_3, 1}},
        {"plains/houses/plains_temple_4", {plains_houses_plains_temple_4, 1}},
        {"plains/houses/plains_tool_smith_1", {plains_houses_plains_tool_smith_1, 1}},
        {"plains/houses/plains_weaponsmith_1", {plains_houses_plains_weaponsmith_1, 1}},
        {"plains/plains_lamp_1", {plains_plains_lamp_1, 1}},
        {"plains/streets/corner_01", {plains_streets_corner_01, 8}},
        {"plains/streets/corner_02", {plains_streets_corner_02, 3}},
        {"plains/streets/corner_03", {plains_streets_corner_03, 2}},
        {"plains/streets/crossroad_01", {plains_streets_crossroad_01, 13}},
        {"plains/streets/crossroad_02", {plains_streets_crossroad_02, 9}},
        {"plains/streets/crossroad_03", {plains_streets_crossroad_03, 7}},
        {"plains/streets/crossroad_04", {plains_streets_crossroad_04, 3}},
        {"plains/streets/crossroad_05", {plains_streets_crossroad_05, 4}},
        {"plains/streets/crossroad_06", {plains_streets_crossroad_06, 5}},
        {"plains/streets/straight_01", {plains_streets_straight_01, 7}},
        {"plains/streets/straight_02", {plains_streets_straight_02, 3}},
        {"plains/streets/straight_03", {plains_streets_straight_03, 7}},
        {"plains/streets/straight_04", {plains_streets_straight_04, 3}},
        {"plains/streets/straight_05", {plains_streets_straight_05, 6}},
        {"plains/streets/straight_06", {plains_streets_straight_06, 19}},
        {"plains/streets/turn_01", {plains_streets_turn_01, 4}},
        {"plains/terminators/terminator_01", {plains_terminators_terminator_01, 1}},
        {"plains/terminators/terminator_02", {plains_terminators_terminator_02, 1}},
        {"plains/terminators/terminator_03", {plains_terminators_terminator_03, 1}},
        {"plains/terminators/terminator_04", {plains_terminators_terminator_04, 1}},
        {"plains/town_centers/plains_fountain_01", {plains_town_centers_plains_fountain_01, 10}},
        {"plains/town_centers/plains_meeting_point_1", {plains_town_centers_plains_meeting_point_1, 11}},
        {"plains/town_centers/plains_meeting_point_2", {plains_town_centers_plains_meeting_point_2, 11}},
        {"plains/town_centers/plains_meeting_point_3", {plains_town_centers_plains_meeting_point_3, 8}},
        {"plains/villagers/baby", {plains_villagers_baby, 1}},
        {"plains/villagers/nitwit", {plains_villagers_nitwit, 1}},
        {"plains/villagers/unemployed", {plains_villagers_unemployed, 1}},
        {"plains/zombie/houses/plains_animal_pen_3", {plains_zombie_houses_plains_animal_pen_3, 8}},
        {"plains/zombie/houses/plains_big_house_1", {plains_zombie_houses_plains_big_house_1, 5}},
        {"plains/zombie/houses/plains_butcher_shop_2", {plains_zombie_houses_plains_butcher_shop_2, 6}},
        {"plains/zombie/houses/plains_fletcher_house_1", {plains_zombie_houses_plains_fletcher_house_1, 2}},
        {"plains/zombie/houses/plains_medium_house_1", {plains_zombie_houses_plains_medium_house_1, 4}},
        {"plains/zombie/houses/plains_medium_house_2", {plains_zombie_houses_plains_medium_house_2, 3}},
        {"plains/zombie/houses/plains_meeting_point_4", {plains_zombie_houses_plains_meeting_point_4, 5}},
        {"plains/zombie/houses/plains_meeting_point_5", {plains_zombie_houses_plains_meeting_point_5, 3}},
        {"plains/zombie/houses/plains_shepherds_house_1", {plains_zombie_houses_plains_shepherds_house_1, 4}},
        {"plains/zombie/houses/plains_small_house_1", {plains_zombie_houses_plains_small_house_1, 2}},
        {"plains/zombie/houses/plains_small_house_2", {plains_zombie_houses_plains_small_house_2, 2}},
        {"plains/zombie/houses/plains_small_house_3", {plains_zombie_houses_plains_small_house_3, 2}},
        {"plains/zombie/houses/plains_small_house_4", {plains_zombie_houses_plains_small_house_4, 2}},
        {"plains/zombie/houses/plains_small_house_5", {plains_zombie_houses_plains_small_house_5, 5}},
        {"plains/zombie/houses/plains_small_house_6", {plains_zombie_houses_plains_small_house_6, 2}},
        {"plains/zombie/houses/plains_small_house_7", {plains_zombie_houses_plains_small_house_7, 2}},
        {"plains/zombie/houses/plains_small_house_8", {plains_zombie_houses_plains_small_house_8, 2}},
        {"plains/zombie/houses/plains_stable_1", {plains_zombie_houses_plains_stable_1, 8}},
        {"plains/zombie/streets/corner_01", {plains_zombie_streets_corner_01, 8}},
        {"plains/zombie/streets/corner_02", {plains_zombie_streets_corner_02, 3}},
        {"plains/zombie/streets/corner_03", {plains_zombie_streets_corner_03, 2}},
        {"plains/zombie/streets/crossroad_01", {plains_zombie_streets_crossroad_01, 13}},
        {"plains/zombie/streets/crossroad_02", {plains_zombie_streets_crossroad_02, 9}},
        {"plains/zombie/streets/crossroad_03", {plains_zombie_streets_crossroad_03, 7}},
        {"plains/zombie/streets/crossroad_04", {plains_zombie_streets_crossroad_04, 3}},
        {"plains/zombie/streets/crossroad_05", {plains_zombie_streets_crossroad_05, 4}},
        {"plains/zombie/streets/crossroad_06", {plains_zombie_streets_crossroad_06, 5}},
        {"plains/zombie/streets/straight_01", {plains_zombie_streets_straight_01, 7}},
        {"plains/zombie/streets/straight_02", {plains_zombie_streets_straight_02, 3}},
        {"plains/zombie/streets/straight_03", {plains_zombie_streets_straight_03, 7}},
        {"plains/zombie/streets/straight_04", {plains_zombie_streets_straight_04, 3}},
        {"plains/zombie/streets/straight_05", {plains_zombie_streets_straight_05, 6}},
        {"plains/zombie/streets/straight_06", {plains_zombie_streets_straight_06, 19}},
        {"plains/zombie/streets/turn_01", {plains_zombie_streets_turn_01, 4}},
        {"plains/zombie/town_centers/plains_fountain_01", {plains_zombie_town_centers_plains_fountain_01, 6}},
        {"plains/zombie/town_centers/plains_meeting_point_1", {plains_zombie_town_centers_plains_meeting_point_1, 8}},
        {"plains/zombie/town_centers/plains_meeting_point_2", {plains_zombie_town_centers_plains_meeting_point_2, 6}},
        {"plains/zombie/town_centers/plains_meeting_point_3", {plains_zombie_town_centers_plains_meeting_point_3, 5}},
        {"plains/zombie/villagers/nitwit", {plains_zombie_villagers_nitwit, 1}},
        {"plains/zombie/villagers/unemployed", {plains_zombie_villagers_unemployed, 1}},
    };
    
    auto it = LOOKUP.find(templateName);
    if (it != LOOKUP.end()) {
        return std::vector<JigsawBlockEntry>(it->second.first, it->second.first + it->second.second);
    }
    return {};
}

// Version sans allocation (plus rapide)
inline bool getPlainsVillageJigsawBlockFast(const std::string& templateName, const JigsawBlockEntry*& out, size_t& count) {
    using namespace PlainsVillageJigsawData;
    
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
        {"flower_plain", {flower_plain, 1}},
        {"oak", {oak, 1}},
        {"patch_cactus", {patch_cactus, 1}},
        {"pile_hay", {pile_hay, 1}},
        {"plains/houses/plains_accessory_1", {plains_houses_plains_accessory_1, 1}},
        {"plains/houses/plains_animal_pen_1", {plains_houses_plains_animal_pen_1, 3}},
        {"plains/houses/plains_animal_pen_2", {plains_houses_plains_animal_pen_2, 4}},
        {"plains/houses/plains_animal_pen_3", {plains_houses_plains_animal_pen_3, 8}},
        {"plains/houses/plains_armorer_house_1", {plains_houses_plains_armorer_house_1, 1}},
        {"plains/houses/plains_big_house_1", {plains_houses_plains_big_house_1, 5}},
        {"plains/houses/plains_butcher_shop_1", {plains_houses_plains_butcher_shop_1, 2}},
        {"plains/houses/plains_butcher_shop_2", {plains_houses_plains_butcher_shop_2, 6}},
        {"plains/houses/plains_cartographer_1", {plains_houses_plains_cartographer_1, 1}},
        {"plains/houses/plains_fisher_cottage_1", {plains_houses_plains_fisher_cottage_1, 1}},
        {"plains/houses/plains_fletcher_house_1", {plains_houses_plains_fletcher_house_1, 2}},
        {"plains/houses/plains_large_farm_1", {plains_houses_plains_large_farm_1, 1}},
        {"plains/houses/plains_library_1", {plains_houses_plains_library_1, 1}},
        {"plains/houses/plains_library_2", {plains_houses_plains_library_2, 1}},
        {"plains/houses/plains_masons_house_1", {plains_houses_plains_masons_house_1, 1}},
        {"plains/houses/plains_medium_house_1", {plains_houses_plains_medium_house_1, 4}},
        {"plains/houses/plains_medium_house_2", {plains_houses_plains_medium_house_2, 3}},
        {"plains/houses/plains_meeting_point_4", {plains_houses_plains_meeting_point_4, 5}},
        {"plains/houses/plains_meeting_point_5", {plains_houses_plains_meeting_point_5, 4}},
        {"plains/houses/plains_shepherds_house_1", {plains_houses_plains_shepherds_house_1, 4}},
        {"plains/houses/plains_small_farm_1", {plains_houses_plains_small_farm_1, 1}},
        {"plains/houses/plains_small_house_1", {plains_houses_plains_small_house_1, 2}},
        {"plains/houses/plains_small_house_2", {plains_houses_plains_small_house_2, 2}},
        {"plains/houses/plains_small_house_3", {plains_houses_plains_small_house_3, 2}},
        {"plains/houses/plains_small_house_4", {plains_houses_plains_small_house_4, 2}},
        {"plains/houses/plains_small_house_5", {plains_houses_plains_small_house_5, 5}},
        {"plains/houses/plains_small_house_6", {plains_houses_plains_small_house_6, 2}},
        {"plains/houses/plains_small_house_7", {plains_houses_plains_small_house_7, 2}},
        {"plains/houses/plains_small_house_8", {plains_houses_plains_small_house_8, 2}},
        {"plains/houses/plains_stable_1", {plains_houses_plains_stable_1, 8}},
        {"plains/houses/plains_stable_2", {plains_houses_plains_stable_2, 5}},
        {"plains/houses/plains_tannery_1", {plains_houses_plains_tannery_1, 1}},
        {"plains/houses/plains_temple_3", {plains_houses_plains_temple_3, 1}},
        {"plains/houses/plains_temple_4", {plains_houses_plains_temple_4, 1}},
        {"plains/houses/plains_tool_smith_1", {plains_houses_plains_tool_smith_1, 1}},
        {"plains/houses/plains_weaponsmith_1", {plains_houses_plains_weaponsmith_1, 1}},
        {"plains/plains_lamp_1", {plains_plains_lamp_1, 1}},
        {"plains/streets/corner_01", {plains_streets_corner_01, 8}},
        {"plains/streets/corner_02", {plains_streets_corner_02, 3}},
        {"plains/streets/corner_03", {plains_streets_corner_03, 2}},
        {"plains/streets/crossroad_01", {plains_streets_crossroad_01, 13}},
        {"plains/streets/crossroad_02", {plains_streets_crossroad_02, 9}},
        {"plains/streets/crossroad_03", {plains_streets_crossroad_03, 7}},
        {"plains/streets/crossroad_04", {plains_streets_crossroad_04, 3}},
        {"plains/streets/crossroad_05", {plains_streets_crossroad_05, 4}},
        {"plains/streets/crossroad_06", {plains_streets_crossroad_06, 5}},
        {"plains/streets/straight_01", {plains_streets_straight_01, 7}},
        {"plains/streets/straight_02", {plains_streets_straight_02, 3}},
        {"plains/streets/straight_03", {plains_streets_straight_03, 7}},
        {"plains/streets/straight_04", {plains_streets_straight_04, 3}},
        {"plains/streets/straight_05", {plains_streets_straight_05, 6}},
        {"plains/streets/straight_06", {plains_streets_straight_06, 19}},
        {"plains/streets/turn_01", {plains_streets_turn_01, 4}},
        {"plains/terminators/terminator_01", {plains_terminators_terminator_01, 1}},
        {"plains/terminators/terminator_02", {plains_terminators_terminator_02, 1}},
        {"plains/terminators/terminator_03", {plains_terminators_terminator_03, 1}},
        {"plains/terminators/terminator_04", {plains_terminators_terminator_04, 1}},
        {"plains/town_centers/plains_fountain_01", {plains_town_centers_plains_fountain_01, 10}},
        {"plains/town_centers/plains_meeting_point_1", {plains_town_centers_plains_meeting_point_1, 11}},
        {"plains/town_centers/plains_meeting_point_2", {plains_town_centers_plains_meeting_point_2, 11}},
        {"plains/town_centers/plains_meeting_point_3", {plains_town_centers_plains_meeting_point_3, 8}},
        {"plains/villagers/baby", {plains_villagers_baby, 1}},
        {"plains/villagers/nitwit", {plains_villagers_nitwit, 1}},
        {"plains/villagers/unemployed", {plains_villagers_unemployed, 1}},
        {"plains/zombie/houses/plains_animal_pen_3", {plains_zombie_houses_plains_animal_pen_3, 8}},
        {"plains/zombie/houses/plains_big_house_1", {plains_zombie_houses_plains_big_house_1, 5}},
        {"plains/zombie/houses/plains_butcher_shop_2", {plains_zombie_houses_plains_butcher_shop_2, 6}},
        {"plains/zombie/houses/plains_fletcher_house_1", {plains_zombie_houses_plains_fletcher_house_1, 2}},
        {"plains/zombie/houses/plains_medium_house_1", {plains_zombie_houses_plains_medium_house_1, 4}},
        {"plains/zombie/houses/plains_medium_house_2", {plains_zombie_houses_plains_medium_house_2, 3}},
        {"plains/zombie/houses/plains_meeting_point_4", {plains_zombie_houses_plains_meeting_point_4, 5}},
        {"plains/zombie/houses/plains_meeting_point_5", {plains_zombie_houses_plains_meeting_point_5, 3}},
        {"plains/zombie/houses/plains_shepherds_house_1", {plains_zombie_houses_plains_shepherds_house_1, 4}},
        {"plains/zombie/houses/plains_small_house_1", {plains_zombie_houses_plains_small_house_1, 2}},
        {"plains/zombie/houses/plains_small_house_2", {plains_zombie_houses_plains_small_house_2, 2}},
        {"plains/zombie/houses/plains_small_house_3", {plains_zombie_houses_plains_small_house_3, 2}},
        {"plains/zombie/houses/plains_small_house_4", {plains_zombie_houses_plains_small_house_4, 2}},
        {"plains/zombie/houses/plains_small_house_5", {plains_zombie_houses_plains_small_house_5, 5}},
        {"plains/zombie/houses/plains_small_house_6", {plains_zombie_houses_plains_small_house_6, 2}},
        {"plains/zombie/houses/plains_small_house_7", {plains_zombie_houses_plains_small_house_7, 2}},
        {"plains/zombie/houses/plains_small_house_8", {plains_zombie_houses_plains_small_house_8, 2}},
        {"plains/zombie/houses/plains_stable_1", {plains_zombie_houses_plains_stable_1, 8}},
        {"plains/zombie/streets/corner_01", {plains_zombie_streets_corner_01, 8}},
        {"plains/zombie/streets/corner_02", {plains_zombie_streets_corner_02, 3}},
        {"plains/zombie/streets/corner_03", {plains_zombie_streets_corner_03, 2}},
        {"plains/zombie/streets/crossroad_01", {plains_zombie_streets_crossroad_01, 13}},
        {"plains/zombie/streets/crossroad_02", {plains_zombie_streets_crossroad_02, 9}},
        {"plains/zombie/streets/crossroad_03", {plains_zombie_streets_crossroad_03, 7}},
        {"plains/zombie/streets/crossroad_04", {plains_zombie_streets_crossroad_04, 3}},
        {"plains/zombie/streets/crossroad_05", {plains_zombie_streets_crossroad_05, 4}},
        {"plains/zombie/streets/crossroad_06", {plains_zombie_streets_crossroad_06, 5}},
        {"plains/zombie/streets/straight_01", {plains_zombie_streets_straight_01, 7}},
        {"plains/zombie/streets/straight_02", {plains_zombie_streets_straight_02, 3}},
        {"plains/zombie/streets/straight_03", {plains_zombie_streets_straight_03, 7}},
        {"plains/zombie/streets/straight_04", {plains_zombie_streets_straight_04, 3}},
        {"plains/zombie/streets/straight_05", {plains_zombie_streets_straight_05, 6}},
        {"plains/zombie/streets/straight_06", {plains_zombie_streets_straight_06, 19}},
        {"plains/zombie/streets/turn_01", {plains_zombie_streets_turn_01, 4}},
        {"plains/zombie/town_centers/plains_fountain_01", {plains_zombie_town_centers_plains_fountain_01, 6}},
        {"plains/zombie/town_centers/plains_meeting_point_1", {plains_zombie_town_centers_plains_meeting_point_1, 8}},
        {"plains/zombie/town_centers/plains_meeting_point_2", {plains_zombie_town_centers_plains_meeting_point_2, 6}},
        {"plains/zombie/town_centers/plains_meeting_point_3", {plains_zombie_town_centers_plains_meeting_point_3, 5}},
        {"plains/zombie/villagers/nitwit", {plains_zombie_villagers_nitwit, 1}},
        {"plains/zombie/villagers/unemployed", {plains_zombie_villagers_unemployed, 1}},
    };
    
    auto it = LOOKUP.find(templateName);
    if (it != LOOKUP.end()) {
        out = it->second.first;
        count = it->second.second;
        return true;
    }
    return false;
}
