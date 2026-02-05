#pragma once
// Auto-generated from DesertVillageJigsawBlocks.java
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
namespace DesertVillageJigsawData {

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

    static const JigsawBlockEntry desert_desert_lamp_1[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry desert_houses_desert_animal_pen_1[] = {
        {PoolType::ANIMALS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 3},
        {PoolType::EMPTY, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 4, 0, 0},
    };

    static const JigsawBlockEntry desert_houses_desert_animal_pen_2[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 4, 0, 0},
        {PoolType::ANIMALS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 6, 0, 3},
    };

    static const JigsawBlockEntry desert_houses_desert_armorer_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 4},
    };

    static const JigsawBlockEntry desert_houses_desert_butcher_shop_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 3},
        {PoolType::BUTCHER_ANIMAL, "bottom", BlockDirection::UP, BlockDirection::NORTH, 6, 0, 6},
    };

    static const JigsawBlockEntry desert_houses_desert_cartographer_house_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 5},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 5, 0, 0},
    };

    static const JigsawBlockEntry desert_houses_desert_farm_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 3},
    };

    static const JigsawBlockEntry desert_houses_desert_farm_2[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 3},
    };

    static const JigsawBlockEntry desert_houses_desert_fisher_1[] = {
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 0, 9},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 6},
    };

    static const JigsawBlockEntry desert_houses_desert_fletcher_house_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 4},
    };

    static const JigsawBlockEntry desert_houses_desert_large_farm_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 2, 6},
    };

    static const JigsawBlockEntry desert_houses_desert_library_1[] = {
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 3},
        {PoolType::EMPTY, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 3, 1, 0},
    };

    static const JigsawBlockEntry desert_houses_desert_mason_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 4},
    };

    static const JigsawBlockEntry desert_houses_desert_medium_house_1[] = {
        {PoolType::DESERT_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 2},
        {PoolType::DESERT_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 4},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 3},
    };

    static const JigsawBlockEntry desert_houses_desert_medium_house_2[] = {
        {PoolType::DESERT_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 4, 0, 2},
        {PoolType::EMPTY, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 4, 1, 0},
        {PoolType::DESERT_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 7, 2, 2},
    };

    static const JigsawBlockEntry desert_houses_desert_shepherd_house_1[] = {
        {PoolType::SHEEPS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 2},
        {PoolType::EMPTY, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 5, 1, 4},
    };

    static const JigsawBlockEntry desert_houses_desert_small_house_1[] = {
        {PoolType::DESERT_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 2},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 2},
    };

    static const JigsawBlockEntry desert_houses_desert_small_house_2[] = {
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 0, 3},
        {PoolType::DESERT_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 1},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 2},
    };

    static const JigsawBlockEntry desert_houses_desert_small_house_3[] = {
        {PoolType::DESERT_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 1},
        {PoolType::EMPTY, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 2, 1, 5},
    };

    static const JigsawBlockEntry desert_houses_desert_small_house_4[] = {
        {PoolType::DESERT_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 2},
        {PoolType::EMPTY, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 3, 1, 4},
    };

    static const JigsawBlockEntry desert_houses_desert_small_house_5[] = {
        {PoolType::DESERT_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 3},
        {PoolType::EMPTY, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 2, 1, 0},
    };

    static const JigsawBlockEntry desert_houses_desert_small_house_6[] = {
        {PoolType::DESERT_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 3},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 2},
    };

    static const JigsawBlockEntry desert_houses_desert_small_house_7[] = {
        {PoolType::DESERT_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 5, 0, 3},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 1},
    };

    static const JigsawBlockEntry desert_houses_desert_small_house_8[] = {
        {PoolType::DESERT_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 2},
        {PoolType::EMPTY, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 1, 1, 0},
    };

    static const JigsawBlockEntry desert_houses_desert_tannery_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 3, 2, 0},
    };

    static const JigsawBlockEntry desert_houses_desert_temple_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 5},
    };

    static const JigsawBlockEntry desert_houses_desert_temple_2[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 5},
    };

    static const JigsawBlockEntry desert_houses_desert_tool_smith_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 3, 5},
    };

    static const JigsawBlockEntry desert_houses_desert_weaponsmith_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 5, 0, 0},
    };

    static const JigsawBlockEntry desert_streets_corner_01[] = {
        {PoolType::DESERT_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 1},
        {PoolType::DESERT_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 4},
        {PoolType::DESERT_HOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 3, 1, 5},
        {PoolType::DESERT_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 5, 1, 0},
    };

    static const JigsawBlockEntry desert_streets_corner_02[] = {
        {PoolType::DESERT_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 4},
        {PoolType::DESERT_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 1},
        {PoolType::DESERT_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 4, 1, 5},
    };

    static const JigsawBlockEntry desert_streets_crossroad_01[] = {
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 5, 0, 7},
        {PoolType::DESERT_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 10, 0, 12},
        {PoolType::DESERT_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 7},
        {PoolType::DESERT_HOUSES, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 2, 1, 6},
        {PoolType::DESERT_HOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 2, 1, 8},
        {PoolType::DESERT_HOUSES, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 3, 1, 6},
        {PoolType::DESERT_HOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 3, 1, 8},
        {PoolType::DESERT_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 7, 1, 0},
        {PoolType::DESERT_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 7, 1, 14},
        {PoolType::DESERT_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 8, 1, 2},
        {PoolType::DESERT_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 8, 1, 3},
        {PoolType::DESERT_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 8, 1, 7},
    };

    static const JigsawBlockEntry desert_streets_crossroad_02[] = {
        {PoolType::DESERT_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 8},
        {PoolType::DESERT_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 5, 0, 5},
        {PoolType::DESERT_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 9, 0, 1},
        {PoolType::DESERT_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 5},
        {PoolType::DESERT_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 5, 1, 0},
        {PoolType::DESERT_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 5, 1, 10},
        {PoolType::DESERT_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 10, 1, 5},
    };

    static const JigsawBlockEntry desert_streets_crossroad_03[] = {
        {PoolType::DESERT_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 2},
        {PoolType::DESERT_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 2, 1, 0},
        {PoolType::DESERT_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 2, 1, 4},
        {PoolType::DESERT_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 4, 1, 2},
    };

    static const JigsawBlockEntry desert_streets_square_01[] = {
        {PoolType::DESERT_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 13},
        {PoolType::DESERT_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 10, 0, 10},
        {PoolType::DESERT_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 12},
        {PoolType::DESERT_HOUSES, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 2, 1, 10},
        {PoolType::DESERT_HOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 2, 1, 15},
        {PoolType::DESERT_HOUSES, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 3, 1, 10},
        {PoolType::DESERT_HOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 3, 1, 15},
        {PoolType::DESERT_HOUSES, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 4, 1, 10},
        {PoolType::DESERT_HOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 4, 1, 15},
        {PoolType::DESERT_HOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 5, 1, 15},
        {PoolType::DESERT_HOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 6, 1, 15},
        {PoolType::DESERT_HOUSES, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 7, 1, 9},
        {PoolType::DESERT_HOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 7, 1, 15},
        {PoolType::DESERT_HOUSES, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 8, 1, 9},
        {PoolType::DESERT_HOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 8, 1, 15},
        {PoolType::DESERT_HOUSES, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 9, 1, 9},
        {PoolType::DESERT_HOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 9, 1, 15},
        {PoolType::DESERT_HOUSES, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 10, 1, 9},
        {PoolType::DESERT_HOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 10, 1, 15},
        {PoolType::DESERT_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 12, 1, 12},
    };

    static const JigsawBlockEntry desert_streets_square_02[] = {
        {PoolType::DESERT_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 0, 10},
        {PoolType::DESERT_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 4, 0, 8},
        {PoolType::EMPTY, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 8},
        {PoolType::DESERT_HOUSES, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 4, 1, 5},
        {PoolType::DESERT_HOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 5, 1, 11},
        {PoolType::DESERT_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 7, 1, 8},
    };

    static const JigsawBlockEntry desert_streets_straight_01[] = {
        {PoolType::DESERT_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 0},
        {PoolType::DESERT_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 13, 0, 0},
        {PoolType::DESERT_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 2},
        {PoolType::DESERT_HOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 2, 1, 3},
        {PoolType::DESERT_HOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 7, 1, 3},
        {PoolType::DESERT_HOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 12, 1, 3},
        {PoolType::DESERT_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 14, 1, 2},
    };

    static const JigsawBlockEntry desert_streets_straight_02[] = {
        {PoolType::DESERT_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 5, 0, 16},
        {PoolType::DESERT_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 12, 0, 17},
        {PoolType::DESERT_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 14},
        {PoolType::DESERT_HOUSES, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 3, 1, 13},
        {PoolType::DESERT_HOUSES, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 7, 1, 13},
        {PoolType::DESERT_HOUSES, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 11, 1, 13},
        {PoolType::DESERT_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 14, 1, 14},
    };

    static const JigsawBlockEntry desert_streets_straight_03[] = {
        {PoolType::DESERT_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 1},
        {PoolType::DESERT_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 3, 1, 1},
    };

    static const JigsawBlockEntry desert_streets_turn_01[] = {
        {PoolType::DESERT_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 3},
        {PoolType::DESERT_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 2},
        {PoolType::DESERT_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 2, 1, 0},
    };

    static const JigsawBlockEntry desert_terminators_terminator_01[] = {
        {PoolType::EMPTY, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 1},
    };

    static const JigsawBlockEntry desert_terminators_terminator_02[] = {
        {PoolType::DESERT_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 2},
        {PoolType::EMPTY, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 1},
    };

    static const JigsawBlockEntry desert_town_centers_desert_meeting_point_1[] = {
        {PoolType::IRON_GOLEM, "bottom", BlockDirection::UP, BlockDirection::NORTH, 9, 0, 1},
        {PoolType::DESERT_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 11, 0, 0},
        {PoolType::DESERT_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 15, 0, 1},
        {PoolType::DESERT_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 15, 0, 7},
        {PoolType::DESERT_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 2},
        {PoolType::DESERT_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 3},
        {PoolType::DESERT_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 4},
        {PoolType::DESERT_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 5},
        {PoolType::DESERT_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 6},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 9, 1, 6},
        {PoolType::DESERT_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 12, 1, 0},
        {PoolType::DESERT_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 12, 1, 8},
        {PoolType::DESERT_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 16, 1, 4},
    };

    static const JigsawBlockEntry desert_town_centers_desert_meeting_point_2[] = {
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 1},
        {PoolType::DESERT_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 8},
        {PoolType::IRON_GOLEM, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 10},
        {PoolType::DESERT_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 4, 0, 10},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 10, 0, 3},
        {PoolType::DESERT_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 10, 0, 10},
        {PoolType::DESERT_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 5},
        {PoolType::DESERT_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 5, 1, 11},
        {PoolType::DESERT_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 6, 1, 0},
        {PoolType::DESERT_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 11, 1, 6},
    };

    static const JigsawBlockEntry desert_town_centers_desert_meeting_point_3[] = {
        {PoolType::DESERT_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 0},
        {PoolType::DESERT_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 12},
        {PoolType::DESERT_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 10},
        {PoolType::IRON_GOLEM, "bottom", BlockDirection::UP, BlockDirection::NORTH, 4, 0, 11},
        {PoolType::DESERT_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 6, 0, 10},
        {PoolType::DESERT_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 0, 5},
        {PoolType::DESERT_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 13, 0, 11},
        {PoolType::DESERT_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 7},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 6, 1, 4},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 9, 1, 9},
        {PoolType::DESERT_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 12, 1, 14},
        {PoolType::DESERT_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 14, 1, 8},
    };

    static const JigsawBlockEntry desert_villagers_baby[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry desert_villagers_nitwit[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry desert_villagers_unemployed[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry desert_zombie_houses_desert_medium_house_1[] = {
        {PoolType::DESERT_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 2},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 3},
    };

    static const JigsawBlockEntry desert_zombie_houses_desert_medium_house_2[] = {
        {PoolType::DESERT_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 4, 0, 2},
        {PoolType::EMPTY, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 4, 1, 0},
        {PoolType::DESERT_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 7, 2, 2},
    };

    static const JigsawBlockEntry desert_zombie_houses_desert_small_house_1[] = {
        {PoolType::DESERT_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 2},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 2},
    };

    static const JigsawBlockEntry desert_zombie_houses_desert_small_house_2[] = {
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 0, 3},
        {PoolType::DESERT_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 1},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 2},
    };

    static const JigsawBlockEntry desert_zombie_houses_desert_small_house_3[] = {
        {PoolType::DESERT_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 1},
        {PoolType::EMPTY, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 2, 1, 5},
    };

    static const JigsawBlockEntry desert_zombie_houses_desert_small_house_4[] = {
        {PoolType::DESERT_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 2},
        {PoolType::EMPTY, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 3, 1, 4},
    };

    static const JigsawBlockEntry desert_zombie_houses_desert_small_house_5[] = {
        {PoolType::DESERT_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 3},
        {PoolType::EMPTY, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 2, 1, 0},
    };

    static const JigsawBlockEntry desert_zombie_houses_desert_small_house_6[] = {
        {PoolType::DESERT_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 3},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 3},
    };

    static const JigsawBlockEntry desert_zombie_houses_desert_small_house_7[] = {
        {PoolType::DESERT_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 5, 0, 3},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 1},
    };

    static const JigsawBlockEntry desert_zombie_houses_desert_small_house_8[] = {
        {PoolType::DESERT_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 2},
        {PoolType::EMPTY, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 1, 1, 0},
    };

    static const JigsawBlockEntry desert_zombie_streets_corner_01[] = {
        {PoolType::DESERT_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 1},
        {PoolType::DESERT_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 4},
        {PoolType::DESERT_ZHOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 3, 1, 5},
        {PoolType::DESERT_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 5, 1, 0},
    };

    static const JigsawBlockEntry desert_zombie_streets_corner_02[] = {
        {PoolType::DESERT_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 4},
        {PoolType::DESERT_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 1},
        {PoolType::DESERT_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 4, 1, 5},
    };

    static const JigsawBlockEntry desert_zombie_streets_crossroad_01[] = {
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 5, 0, 7},
        {PoolType::DESERT_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 10, 0, 12},
        {PoolType::DESERT_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 7},
        {PoolType::DESERT_ZHOUSES, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 2, 1, 6},
        {PoolType::DESERT_ZHOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 2, 1, 8},
        {PoolType::DESERT_ZHOUSES, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 3, 1, 6},
        {PoolType::DESERT_ZHOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 3, 1, 8},
        {PoolType::DESERT_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 7, 1, 0},
        {PoolType::DESERT_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 7, 1, 14},
        {PoolType::DESERT_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 8, 1, 2},
        {PoolType::DESERT_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 8, 1, 3},
        {PoolType::DESERT_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 8, 1, 7},
    };

    static const JigsawBlockEntry desert_zombie_streets_crossroad_02[] = {
        {PoolType::DESERT_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 8},
        {PoolType::DESERT_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 5, 0, 5},
        {PoolType::DESERT_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 9, 0, 1},
        {PoolType::DESERT_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 5},
        {PoolType::DESERT_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 5, 1, 0},
        {PoolType::DESERT_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 5, 1, 10},
        {PoolType::DESERT_ZSTREET, "street", BlockDirection::EAST, BlockDirection::UP, 10, 1, 5},
    };

    static const JigsawBlockEntry desert_zombie_streets_crossroad_03[] = {
        {PoolType::DESERT_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 2},
        {PoolType::DESERT_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 2, 1, 0},
        {PoolType::DESERT_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 2, 1, 4},
        {PoolType::DESERT_ZSTREET, "street", BlockDirection::EAST, BlockDirection::UP, 4, 1, 2},
    };

    static const JigsawBlockEntry desert_zombie_streets_square_01[] = {
        {PoolType::DESERT_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 13},
        {PoolType::DESERT_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 10, 0, 10},
        {PoolType::DESERT_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 12},
        {PoolType::DESERT_ZHOUSES, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 2, 1, 10},
        {PoolType::DESERT_ZHOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 2, 1, 15},
        {PoolType::DESERT_ZHOUSES, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 3, 1, 10},
        {PoolType::DESERT_ZHOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 3, 1, 15},
        {PoolType::DESERT_ZHOUSES, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 4, 1, 10},
        {PoolType::DESERT_ZHOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 4, 1, 15},
        {PoolType::DESERT_ZHOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 5, 1, 15},
        {PoolType::DESERT_ZHOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 6, 1, 15},
        {PoolType::DESERT_ZHOUSES, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 7, 1, 9},
        {PoolType::DESERT_ZHOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 7, 1, 15},
        {PoolType::DESERT_ZHOUSES, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 8, 1, 9},
        {PoolType::DESERT_ZHOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 8, 1, 15},
        {PoolType::DESERT_ZHOUSES, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 9, 1, 9},
        {PoolType::DESERT_ZHOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 9, 1, 15},
        {PoolType::DESERT_ZHOUSES, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 10, 1, 9},
        {PoolType::DESERT_ZHOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 10, 1, 15},
        {PoolType::DESERT_ZSTREET, "street", BlockDirection::EAST, BlockDirection::UP, 12, 1, 12},
    };

    static const JigsawBlockEntry desert_zombie_streets_square_02[] = {
        {PoolType::DESERT_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 0, 10},
        {PoolType::DESERT_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 4, 0, 8},
        {PoolType::EMPTY, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 8},
        {PoolType::DESERT_ZHOUSES, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 4, 1, 5},
        {PoolType::DESERT_ZHOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 5, 1, 11},
        {PoolType::DESERT_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 7, 1, 8},
    };

    static const JigsawBlockEntry desert_zombie_streets_straight_01[] = {
        {PoolType::DESERT_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 0},
        {PoolType::DESERT_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 13, 0, 0},
        {PoolType::DESERT_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 2},
        {PoolType::DESERT_ZHOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 2, 1, 3},
        {PoolType::DESERT_ZHOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 7, 1, 3},
        {PoolType::DESERT_ZHOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 12, 1, 3},
        {PoolType::DESERT_ZSTREET, "street", BlockDirection::EAST, BlockDirection::UP, 14, 1, 2},
    };

    static const JigsawBlockEntry desert_zombie_streets_straight_02[] = {
        {PoolType::DESERT_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 5, 0, 16},
        {PoolType::DESERT_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 12, 0, 17},
        {PoolType::DESERT_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 14},
        {PoolType::DESERT_ZHOUSES, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 3, 1, 13},
        {PoolType::DESERT_ZHOUSES, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 7, 1, 13},
        {PoolType::DESERT_ZHOUSES, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 11, 1, 13},
        {PoolType::DESERT_ZSTREET, "street", BlockDirection::EAST, BlockDirection::UP, 14, 1, 14},
    };

    static const JigsawBlockEntry desert_zombie_streets_straight_03[] = {
        {PoolType::DESERT_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 1},
        {PoolType::DESERT_ZSTREET, "street", BlockDirection::EAST, BlockDirection::UP, 3, 1, 1},
    };

    static const JigsawBlockEntry desert_zombie_streets_turn_01[] = {
        {PoolType::DESERT_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 3},
        {PoolType::DESERT_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 2},
        {PoolType::DESERT_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 2, 1, 0},
    };

    static const JigsawBlockEntry desert_zombie_terminators_terminator_02[] = {
        {PoolType::DESERT_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 2},
        {PoolType::EMPTY, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 1},
    };

    static const JigsawBlockEntry desert_zombie_town_centers_desert_meeting_point_1[] = {
        {PoolType::DESERT_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 2},
        {PoolType::DESERT_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 3},
        {PoolType::DESERT_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 4},
        {PoolType::DESERT_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 5},
        {PoolType::DESERT_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 6},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 9, 1, 6},
        {PoolType::DESERT_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 12, 1, 0},
        {PoolType::DESERT_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 12, 1, 8},
        {PoolType::DESERT_ZSTREET, "street", BlockDirection::EAST, BlockDirection::UP, 16, 1, 4},
    };

    static const JigsawBlockEntry desert_zombie_town_centers_desert_meeting_point_2[] = {
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 1},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 10, 0, 3},
        {PoolType::DESERT_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 5},
        {PoolType::DESERT_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 5, 1, 11},
        {PoolType::DESERT_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 6, 1, 0},
        {PoolType::DESERT_ZSTREET, "street", BlockDirection::EAST, BlockDirection::UP, 11, 1, 6},
    };

    static const JigsawBlockEntry desert_zombie_town_centers_desert_meeting_point_3[] = {
        {PoolType::DESERT_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 0},
        {PoolType::DESERT_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 12},
        {PoolType::DESERT_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 13, 0, 11},
        {PoolType::DESERT_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 7},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 6, 1, 4},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 9, 1, 9},
        {PoolType::DESERT_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 12, 1, 14},
        {PoolType::DESERT_ZSTREET, "street", BlockDirection::EAST, BlockDirection::UP, 14, 1, 8},
    };

    static const JigsawBlockEntry desert_zombie_villagers_nitwit[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry desert_zombie_villagers_unemployed[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
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
inline std::vector<JigsawBlockEntry> getDesertVillageJigsawBlocks(const std::string& templateName) {
    using namespace DesertVillageJigsawData;
    
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
        {"desert/desert_lamp_1", {desert_desert_lamp_1, 1}},
        {"desert/houses/desert_animal_pen_1", {desert_houses_desert_animal_pen_1, 2}},
        {"desert/houses/desert_animal_pen_2", {desert_houses_desert_animal_pen_2, 2}},
        {"desert/houses/desert_armorer_1", {desert_houses_desert_armorer_1, 1}},
        {"desert/houses/desert_butcher_shop_1", {desert_houses_desert_butcher_shop_1, 2}},
        {"desert/houses/desert_cartographer_house_1", {desert_houses_desert_cartographer_house_1, 2}},
        {"desert/houses/desert_farm_1", {desert_houses_desert_farm_1, 1}},
        {"desert/houses/desert_farm_2", {desert_houses_desert_farm_2, 1}},
        {"desert/houses/desert_fisher_1", {desert_houses_desert_fisher_1, 2}},
        {"desert/houses/desert_fletcher_house_1", {desert_houses_desert_fletcher_house_1, 1}},
        {"desert/houses/desert_large_farm_1", {desert_houses_desert_large_farm_1, 1}},
        {"desert/houses/desert_library_1", {desert_houses_desert_library_1, 2}},
        {"desert/houses/desert_mason_1", {desert_houses_desert_mason_1, 1}},
        {"desert/houses/desert_medium_house_1", {desert_houses_desert_medium_house_1, 3}},
        {"desert/houses/desert_medium_house_2", {desert_houses_desert_medium_house_2, 3}},
        {"desert/houses/desert_shepherd_house_1", {desert_houses_desert_shepherd_house_1, 2}},
        {"desert/houses/desert_small_house_1", {desert_houses_desert_small_house_1, 2}},
        {"desert/houses/desert_small_house_2", {desert_houses_desert_small_house_2, 3}},
        {"desert/houses/desert_small_house_3", {desert_houses_desert_small_house_3, 2}},
        {"desert/houses/desert_small_house_4", {desert_houses_desert_small_house_4, 2}},
        {"desert/houses/desert_small_house_5", {desert_houses_desert_small_house_5, 2}},
        {"desert/houses/desert_small_house_6", {desert_houses_desert_small_house_6, 2}},
        {"desert/houses/desert_small_house_7", {desert_houses_desert_small_house_7, 2}},
        {"desert/houses/desert_small_house_8", {desert_houses_desert_small_house_8, 2}},
        {"desert/houses/desert_tannery_1", {desert_houses_desert_tannery_1, 1}},
        {"desert/houses/desert_temple_1", {desert_houses_desert_temple_1, 1}},
        {"desert/houses/desert_temple_2", {desert_houses_desert_temple_2, 1}},
        {"desert/houses/desert_tool_smith_1", {desert_houses_desert_tool_smith_1, 1}},
        {"desert/houses/desert_weaponsmith_1", {desert_houses_desert_weaponsmith_1, 1}},
        {"desert/streets/corner_01", {desert_streets_corner_01, 4}},
        {"desert/streets/corner_02", {desert_streets_corner_02, 3}},
        {"desert/streets/crossroad_01", {desert_streets_crossroad_01, 12}},
        {"desert/streets/crossroad_02", {desert_streets_crossroad_02, 7}},
        {"desert/streets/crossroad_03", {desert_streets_crossroad_03, 4}},
        {"desert/streets/square_01", {desert_streets_square_01, 20}},
        {"desert/streets/square_02", {desert_streets_square_02, 6}},
        {"desert/streets/straight_01", {desert_streets_straight_01, 7}},
        {"desert/streets/straight_02", {desert_streets_straight_02, 7}},
        {"desert/streets/straight_03", {desert_streets_straight_03, 2}},
        {"desert/streets/turn_01", {desert_streets_turn_01, 3}},
        {"desert/terminators/terminator_01", {desert_terminators_terminator_01, 1}},
        {"desert/terminators/terminator_02", {desert_terminators_terminator_02, 2}},
        {"desert/town_centers/desert_meeting_point_1", {desert_town_centers_desert_meeting_point_1, 13}},
        {"desert/town_centers/desert_meeting_point_2", {desert_town_centers_desert_meeting_point_2, 10}},
        {"desert/town_centers/desert_meeting_point_3", {desert_town_centers_desert_meeting_point_3, 12}},
        {"desert/villagers/baby", {desert_villagers_baby, 1}},
        {"desert/villagers/nitwit", {desert_villagers_nitwit, 1}},
        {"desert/villagers/unemployed", {desert_villagers_unemployed, 1}},
        {"desert/zombie/houses/desert_medium_house_1", {desert_zombie_houses_desert_medium_house_1, 2}},
        {"desert/zombie/houses/desert_medium_house_2", {desert_zombie_houses_desert_medium_house_2, 3}},
        {"desert/zombie/houses/desert_small_house_1", {desert_zombie_houses_desert_small_house_1, 2}},
        {"desert/zombie/houses/desert_small_house_2", {desert_zombie_houses_desert_small_house_2, 3}},
        {"desert/zombie/houses/desert_small_house_3", {desert_zombie_houses_desert_small_house_3, 2}},
        {"desert/zombie/houses/desert_small_house_4", {desert_zombie_houses_desert_small_house_4, 2}},
        {"desert/zombie/houses/desert_small_house_5", {desert_zombie_houses_desert_small_house_5, 2}},
        {"desert/zombie/houses/desert_small_house_6", {desert_zombie_houses_desert_small_house_6, 2}},
        {"desert/zombie/houses/desert_small_house_7", {desert_zombie_houses_desert_small_house_7, 2}},
        {"desert/zombie/houses/desert_small_house_8", {desert_zombie_houses_desert_small_house_8, 2}},
        {"desert/zombie/streets/corner_01", {desert_zombie_streets_corner_01, 4}},
        {"desert/zombie/streets/corner_02", {desert_zombie_streets_corner_02, 3}},
        {"desert/zombie/streets/crossroad_01", {desert_zombie_streets_crossroad_01, 12}},
        {"desert/zombie/streets/crossroad_02", {desert_zombie_streets_crossroad_02, 7}},
        {"desert/zombie/streets/crossroad_03", {desert_zombie_streets_crossroad_03, 4}},
        {"desert/zombie/streets/square_01", {desert_zombie_streets_square_01, 20}},
        {"desert/zombie/streets/square_02", {desert_zombie_streets_square_02, 6}},
        {"desert/zombie/streets/straight_01", {desert_zombie_streets_straight_01, 7}},
        {"desert/zombie/streets/straight_02", {desert_zombie_streets_straight_02, 7}},
        {"desert/zombie/streets/straight_03", {desert_zombie_streets_straight_03, 2}},
        {"desert/zombie/streets/turn_01", {desert_zombie_streets_turn_01, 3}},
        {"desert/zombie/terminators/terminator_02", {desert_zombie_terminators_terminator_02, 2}},
        {"desert/zombie/town_centers/desert_meeting_point_1", {desert_zombie_town_centers_desert_meeting_point_1, 9}},
        {"desert/zombie/town_centers/desert_meeting_point_2", {desert_zombie_town_centers_desert_meeting_point_2, 6}},
        {"desert/zombie/town_centers/desert_meeting_point_3", {desert_zombie_town_centers_desert_meeting_point_3, 8}},
        {"desert/zombie/villagers/nitwit", {desert_zombie_villagers_nitwit, 1}},
        {"desert/zombie/villagers/unemployed", {desert_zombie_villagers_unemployed, 1}},
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
inline bool getDesertVillageJigsawBlocksFast(const std::string& templateName, const JigsawBlockEntry*& out, size_t& count) {
    using namespace DesertVillageJigsawData;
    
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
        {"desert/desert_lamp_1", {desert_desert_lamp_1, 1}},
        {"desert/houses/desert_animal_pen_1", {desert_houses_desert_animal_pen_1, 2}},
        {"desert/houses/desert_animal_pen_2", {desert_houses_desert_animal_pen_2, 2}},
        {"desert/houses/desert_armorer_1", {desert_houses_desert_armorer_1, 1}},
        {"desert/houses/desert_butcher_shop_1", {desert_houses_desert_butcher_shop_1, 2}},
        {"desert/houses/desert_cartographer_house_1", {desert_houses_desert_cartographer_house_1, 2}},
        {"desert/houses/desert_farm_1", {desert_houses_desert_farm_1, 1}},
        {"desert/houses/desert_farm_2", {desert_houses_desert_farm_2, 1}},
        {"desert/houses/desert_fisher_1", {desert_houses_desert_fisher_1, 2}},
        {"desert/houses/desert_fletcher_house_1", {desert_houses_desert_fletcher_house_1, 1}},
        {"desert/houses/desert_large_farm_1", {desert_houses_desert_large_farm_1, 1}},
        {"desert/houses/desert_library_1", {desert_houses_desert_library_1, 2}},
        {"desert/houses/desert_mason_1", {desert_houses_desert_mason_1, 1}},
        {"desert/houses/desert_medium_house_1", {desert_houses_desert_medium_house_1, 3}},
        {"desert/houses/desert_medium_house_2", {desert_houses_desert_medium_house_2, 3}},
        {"desert/houses/desert_shepherd_house_1", {desert_houses_desert_shepherd_house_1, 2}},
        {"desert/houses/desert_small_house_1", {desert_houses_desert_small_house_1, 2}},
        {"desert/houses/desert_small_house_2", {desert_houses_desert_small_house_2, 3}},
        {"desert/houses/desert_small_house_3", {desert_houses_desert_small_house_3, 2}},
        {"desert/houses/desert_small_house_4", {desert_houses_desert_small_house_4, 2}},
        {"desert/houses/desert_small_house_5", {desert_houses_desert_small_house_5, 2}},
        {"desert/houses/desert_small_house_6", {desert_houses_desert_small_house_6, 2}},
        {"desert/houses/desert_small_house_7", {desert_houses_desert_small_house_7, 2}},
        {"desert/houses/desert_small_house_8", {desert_houses_desert_small_house_8, 2}},
        {"desert/houses/desert_tannery_1", {desert_houses_desert_tannery_1, 1}},
        {"desert/houses/desert_temple_1", {desert_houses_desert_temple_1, 1}},
        {"desert/houses/desert_temple_2", {desert_houses_desert_temple_2, 1}},
        {"desert/houses/desert_tool_smith_1", {desert_houses_desert_tool_smith_1, 1}},
        {"desert/houses/desert_weaponsmith_1", {desert_houses_desert_weaponsmith_1, 1}},
        {"desert/streets/corner_01", {desert_streets_corner_01, 4}},
        {"desert/streets/corner_02", {desert_streets_corner_02, 3}},
        {"desert/streets/crossroad_01", {desert_streets_crossroad_01, 12}},
        {"desert/streets/crossroad_02", {desert_streets_crossroad_02, 7}},
        {"desert/streets/crossroad_03", {desert_streets_crossroad_03, 4}},
        {"desert/streets/square_01", {desert_streets_square_01, 20}},
        {"desert/streets/square_02", {desert_streets_square_02, 6}},
        {"desert/streets/straight_01", {desert_streets_straight_01, 7}},
        {"desert/streets/straight_02", {desert_streets_straight_02, 7}},
        {"desert/streets/straight_03", {desert_streets_straight_03, 2}},
        {"desert/streets/turn_01", {desert_streets_turn_01, 3}},
        {"desert/terminators/terminator_01", {desert_terminators_terminator_01, 1}},
        {"desert/terminators/terminator_02", {desert_terminators_terminator_02, 2}},
        {"desert/town_centers/desert_meeting_point_1", {desert_town_centers_desert_meeting_point_1, 13}},
        {"desert/town_centers/desert_meeting_point_2", {desert_town_centers_desert_meeting_point_2, 10}},
        {"desert/town_centers/desert_meeting_point_3", {desert_town_centers_desert_meeting_point_3, 12}},
        {"desert/villagers/baby", {desert_villagers_baby, 1}},
        {"desert/villagers/nitwit", {desert_villagers_nitwit, 1}},
        {"desert/villagers/unemployed", {desert_villagers_unemployed, 1}},
        {"desert/zombie/houses/desert_medium_house_1", {desert_zombie_houses_desert_medium_house_1, 2}},
        {"desert/zombie/houses/desert_medium_house_2", {desert_zombie_houses_desert_medium_house_2, 3}},
        {"desert/zombie/houses/desert_small_house_1", {desert_zombie_houses_desert_small_house_1, 2}},
        {"desert/zombie/houses/desert_small_house_2", {desert_zombie_houses_desert_small_house_2, 3}},
        {"desert/zombie/houses/desert_small_house_3", {desert_zombie_houses_desert_small_house_3, 2}},
        {"desert/zombie/houses/desert_small_house_4", {desert_zombie_houses_desert_small_house_4, 2}},
        {"desert/zombie/houses/desert_small_house_5", {desert_zombie_houses_desert_small_house_5, 2}},
        {"desert/zombie/houses/desert_small_house_6", {desert_zombie_houses_desert_small_house_6, 2}},
        {"desert/zombie/houses/desert_small_house_7", {desert_zombie_houses_desert_small_house_7, 2}},
        {"desert/zombie/houses/desert_small_house_8", {desert_zombie_houses_desert_small_house_8, 2}},
        {"desert/zombie/streets/corner_01", {desert_zombie_streets_corner_01, 4}},
        {"desert/zombie/streets/corner_02", {desert_zombie_streets_corner_02, 3}},
        {"desert/zombie/streets/crossroad_01", {desert_zombie_streets_crossroad_01, 12}},
        {"desert/zombie/streets/crossroad_02", {desert_zombie_streets_crossroad_02, 7}},
        {"desert/zombie/streets/crossroad_03", {desert_zombie_streets_crossroad_03, 4}},
        {"desert/zombie/streets/square_01", {desert_zombie_streets_square_01, 20}},
        {"desert/zombie/streets/square_02", {desert_zombie_streets_square_02, 6}},
        {"desert/zombie/streets/straight_01", {desert_zombie_streets_straight_01, 7}},
        {"desert/zombie/streets/straight_02", {desert_zombie_streets_straight_02, 7}},
        {"desert/zombie/streets/straight_03", {desert_zombie_streets_straight_03, 2}},
        {"desert/zombie/streets/turn_01", {desert_zombie_streets_turn_01, 3}},
        {"desert/zombie/terminators/terminator_02", {desert_zombie_terminators_terminator_02, 2}},
        {"desert/zombie/town_centers/desert_meeting_point_1", {desert_zombie_town_centers_desert_meeting_point_1, 9}},
        {"desert/zombie/town_centers/desert_meeting_point_2", {desert_zombie_town_centers_desert_meeting_point_2, 6}},
        {"desert/zombie/town_centers/desert_meeting_point_3", {desert_zombie_town_centers_desert_meeting_point_3, 8}},
        {"desert/zombie/villagers/nitwit", {desert_zombie_villagers_nitwit, 1}},
        {"desert/zombie/villagers/unemployed", {desert_zombie_villagers_unemployed, 1}},
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
