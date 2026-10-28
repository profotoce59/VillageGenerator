#pragma once
// Auto-generated from SnowyVillageJigsawBlocks.java
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
namespace SnowyVillageJigsawData {

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

    static const JigsawBlockEntry snowy_houses_snowy_animal_pen_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 5},
        {PoolType::ANIMALS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 5},
    };

    static const JigsawBlockEntry snowy_houses_snowy_animal_pen_2[] = {
        {PoolType::ANIMALS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 4},
        {PoolType::ANIMALS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 6, 0, 3},
        {PoolType::EMPTY, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 3, 1, 0},
    };

    static const JigsawBlockEntry snowy_houses_snowy_armorer_house_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 3},
    };

    static const JigsawBlockEntry snowy_houses_snowy_armorer_house_2[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 3, 0, 0},
    };

    static const JigsawBlockEntry snowy_houses_snowy_butchers_shop_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 3, 0, 0},
        {PoolType::BUTCHER_ANIMAL, "bottom", BlockDirection::UP, BlockDirection::NORTH, 4, 0, 7},
    };

    static const JigsawBlockEntry snowy_houses_snowy_butchers_shop_2[] = {
        {PoolType::BUTCHER_ANIMAL, "bottom", BlockDirection::UP, BlockDirection::NORTH, 5, 0, 2},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 3},
    };

    static const JigsawBlockEntry snowy_houses_snowy_cartographer_house_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 5},
    };

    static const JigsawBlockEntry snowy_houses_snowy_farm_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 3},
    };

    static const JigsawBlockEntry snowy_houses_snowy_farm_2[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 3},
    };

    static const JigsawBlockEntry snowy_houses_snowy_fisher_cottage[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 1, 1, 6},
    };

    static const JigsawBlockEntry snowy_houses_snowy_fletcher_house_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 3},
    };

    static const JigsawBlockEntry snowy_houses_snowy_library_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 3},
    };

    static const JigsawBlockEntry snowy_houses_snowy_masons_house_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 4, 0, 8},
    };

    static const JigsawBlockEntry snowy_houses_snowy_masons_house_2[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 4},
    };

    static const JigsawBlockEntry snowy_houses_snowy_medium_house_1[] = {
        {PoolType::SNOWY_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 2},
        {PoolType::SNOWY_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 4},
        {PoolType::EMPTY, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 6, 1, 4},
    };

    static const JigsawBlockEntry snowy_houses_snowy_medium_house_2[] = {
        {PoolType::SNOWY_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 5, 0, 3},
        {PoolType::EMPTY, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 7, 0, 0},
        {PoolType::SNOWY_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 9, 0, 3},
    };

    static const JigsawBlockEntry snowy_houses_snowy_medium_house_3[] = {
        {PoolType::SNOWY_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 2},
        {PoolType::SNOWY_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 4},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 2},
    };

    static const JigsawBlockEntry snowy_houses_snowy_shepherds_house_1[] = {
        {PoolType::EMPTY, "buidling_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 6},
        {PoolType::SHEEPS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 2},
    };

    static const JigsawBlockEntry snowy_houses_snowy_small_house_1[] = {
        {PoolType::SNOWY_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 2},
        {PoolType::EMPTY, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 3, 1, 5},
    };

    static const JigsawBlockEntry snowy_houses_snowy_small_house_2[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 3, 0, 0},
        {PoolType::SNOWY_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 3},
    };

    static const JigsawBlockEntry snowy_houses_snowy_small_house_3[] = {
        {PoolType::SNOWY_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 2},
        {PoolType::EMPTY, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 3, 0, 6},
    };

    static const JigsawBlockEntry snowy_houses_snowy_small_house_4[] = {
        {PoolType::SNOWY_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 4, 0, 3},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 3},
    };

    static const JigsawBlockEntry snowy_houses_snowy_small_house_5[] = {
        {PoolType::SNOWY_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 2},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 3},
    };

    static const JigsawBlockEntry snowy_houses_snowy_small_house_6[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 3},
        {PoolType::SNOWY_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 3},
    };

    static const JigsawBlockEntry snowy_houses_snowy_small_house_7[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 3},
        {PoolType::SNOWY_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 3},
    };

    static const JigsawBlockEntry snowy_houses_snowy_small_house_8[] = {
        {PoolType::SNOWY_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 2},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 1},
    };

    static const JigsawBlockEntry snowy_houses_snowy_tannery_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 4},
    };

    static const JigsawBlockEntry snowy_houses_snowy_temple_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 3},
    };

    static const JigsawBlockEntry snowy_houses_snowy_tool_smith_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 4},
    };

    static const JigsawBlockEntry snowy_houses_snowy_weapon_smith_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 4},
    };

    static const JigsawBlockEntry snowy_pile_ice[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry snowy_pile_snow[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry snowy_snowy_lamp_post_01[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 1, 0, 0},
    };

    static const JigsawBlockEntry snowy_snowy_lamp_post_02[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 1, 0, 0},
    };

    static const JigsawBlockEntry snowy_snowy_lamp_post_03[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 1, 0, 1},
    };

    static const JigsawBlockEntry snowy_streets_corner_01[] = {
        {PoolType::SNOWY_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 1},
        {PoolType::SNOWY_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 6},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 10},
        {PoolType::SNOWY_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 4, 0, 12},
        {PoolType::SNOWY_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 6, 0, 3},
        {PoolType::SNOWY_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 9, 0, 9},
        {PoolType::SNOWY_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 8},
        {PoolType::SNOWY_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 3, 1, 0},
        {PoolType::SNOWY_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 4, 1, 6},
    };

    static const JigsawBlockEntry snowy_streets_corner_02[] = {
        {PoolType::SNOWY_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 1, 1, 0},
        {PoolType::SNOWY_HOUSES, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 9, 1, 12},
        {PoolType::SNOWY_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 15, 1, 14},
    };

    static const JigsawBlockEntry snowy_streets_corner_03[] = {
        {PoolType::SNOWY_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 1, 1, 3},
        {PoolType::SNOWY_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 3, 1, 1},
    };

    static const JigsawBlockEntry snowy_streets_crossroad_01[] = {
        {PoolType::SNOWY_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 13, 0, 12},
        {PoolType::SNOWY_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 3},
        {PoolType::SNOWY_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 4},
        {PoolType::SNOWY_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 5},
        {PoolType::SNOWY_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 6},
        {PoolType::SNOWY_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 7},
        {PoolType::SNOWY_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 11},
        {PoolType::SNOWY_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 12},
        {PoolType::SNOWY_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 8, 1, 0},
        {PoolType::SNOWY_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 8, 1, 15},
        {PoolType::SNOWY_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 9, 1, 3},
        {PoolType::SNOWY_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 9, 1, 4},
        {PoolType::SNOWY_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 15, 1, 8},
    };

    static const JigsawBlockEntry snowy_streets_crossroad_02[] = {
        {PoolType::SNOWY_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 11},
        {PoolType::SNOWY_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 5, 0, 13},
        {PoolType::SNOWY_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 0, 8},
        {PoolType::SNOWY_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 8},
        {PoolType::SNOWY_HOUSES, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 3, 1, 7},
        {PoolType::SNOWY_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 8, 1, 0},
        {PoolType::SNOWY_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 8, 1, 15},
        {PoolType::SNOWY_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 9, 1, 3},
        {PoolType::SNOWY_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 9, 1, 12},
    };

    static const JigsawBlockEntry snowy_streets_crossroad_03[] = {
        {PoolType::SNOWY_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 4, 0, 7},
        {PoolType::SNOWY_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 11, 0, 9},
        {PoolType::SNOWY_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 8},
        {PoolType::SNOWY_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 4, 1, 0},
        {PoolType::SNOWY_HOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 5, 1, 9},
        {PoolType::SNOWY_HOUSES, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 11, 1, 7},
        {PoolType::SNOWY_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 11, 1, 16},
        {PoolType::SNOWY_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 15, 1, 8},
    };

    static const JigsawBlockEntry snowy_streets_crossroad_04[] = {
        {PoolType::SNOWY_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 2},
        {PoolType::SNOWY_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 2, 1, 0},
        {PoolType::SNOWY_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 2, 1, 4},
    };

    static const JigsawBlockEntry snowy_streets_crossroad_05[] = {
        {PoolType::SNOWY_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 2},
        {PoolType::SNOWY_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 2, 1, 0},
        {PoolType::SNOWY_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 2, 1, 4},
        {PoolType::SNOWY_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 4, 1, 2},
    };

    static const JigsawBlockEntry snowy_streets_crossroad_06[] = {
        {PoolType::SNOWY_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 2},
        {PoolType::SNOWY_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 2},
        {PoolType::SNOWY_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 2, 1, 0},
        {PoolType::SNOWY_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 2, 1, 4},
        {PoolType::SNOWY_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 4, 1, 2},
    };

    static const JigsawBlockEntry snowy_streets_square_01[] = {
        {PoolType::SNOWY_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 14, 0, 5},
        {PoolType::SNOWY_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 19, 0, 2},
        {PoolType::SNOWY_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 11, 1, 5},
        {PoolType::SNOWY_HOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 14, 1, 8},
        {PoolType::SNOWY_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 18, 1, 0},
    };

    static const JigsawBlockEntry snowy_streets_straight_01[] = {
        {PoolType::SNOWY_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 13},
        {PoolType::SNOWY_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 4, 0, 7},
        {PoolType::SNOWY_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 11, 0, 6},
        {PoolType::SNOWY_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 11, 0, 13},
        {PoolType::SNOWY_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 12, 0, 4},
        {PoolType::SNOWY_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 7, 1, 0},
        {PoolType::SNOWY_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 7, 1, 15},
    };

    static const JigsawBlockEntry snowy_streets_straight_02[] = {
        {PoolType::SNOWY_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 1, 1, 0},
        {PoolType::SNOWY_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 1, 1, 15},
        {PoolType::SNOWY_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 8},
    };

    static const JigsawBlockEntry snowy_streets_straight_03[] = {
        {PoolType::SNOWY_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 0, 2},
        {PoolType::SNOWY_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 0, 8},
        {PoolType::SNOWY_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 1, 1, 0},
        {PoolType::SNOWY_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 1, 1, 10},
        {PoolType::SNOWY_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 3},
        {PoolType::SNOWY_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 4},
        {PoolType::SNOWY_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 5},
        {PoolType::SNOWY_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 6},
        {PoolType::SNOWY_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 7},
    };

    static const JigsawBlockEntry snowy_streets_straight_04[] = {
        {PoolType::SNOWY_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 0, 3},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 6},
        {PoolType::SNOWY_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 1, 1, 0},
        {PoolType::SNOWY_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 1, 1, 8},
        {PoolType::SNOWY_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 4},
    };

    static const JigsawBlockEntry snowy_streets_straight_06[] = {
        {PoolType::SNOWY_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 0, 3},
        {PoolType::SNOWY_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 9, 0, 9},
        {PoolType::SNOWY_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 9, 0, 15},
        {PoolType::SNOWY_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 3},
        {PoolType::SNOWY_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 4},
        {PoolType::SNOWY_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 8, 1, 0},
        {PoolType::SNOWY_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 8, 1, 8},
        {PoolType::SNOWY_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 8, 1, 9},
        {PoolType::SNOWY_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 8, 1, 14},
        {PoolType::SNOWY_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 8, 1, 15},
        {PoolType::SNOWY_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 9, 1, 2},
        {PoolType::SNOWY_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 9, 1, 3},
        {PoolType::SNOWY_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 9, 1, 4},
        {PoolType::SNOWY_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 9, 1, 17},
        {PoolType::SNOWY_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 10, 1, 8},
        {PoolType::SNOWY_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 10, 1, 9},
        {PoolType::SNOWY_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 10, 1, 10},
        {PoolType::SNOWY_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 10, 1, 14},
        {PoolType::SNOWY_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 10, 1, 15},
    };

    static const JigsawBlockEntry snowy_streets_straight_08[] = {
        {PoolType::SNOWY_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 3},
        {PoolType::SNOWY_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 13},
        {PoolType::SNOWY_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 1, 1, 0},
        {PoolType::SNOWY_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 1, 1, 16},
        {PoolType::SNOWY_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 7},
        {PoolType::SNOWY_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 8},
        {PoolType::SNOWY_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 9},
        {PoolType::SNOWY_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 10},
    };

    static const JigsawBlockEntry snowy_streets_turn_01[] = {
        {PoolType::SNOWY_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 0, 1},
        {PoolType::SNOWY_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 5, 1, 0},
        {PoolType::SNOWY_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 6},
        {PoolType::SNOWY_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 8, 1, 7},
        {PoolType::SNOWY_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 9, 1, 4},
    };

    static const JigsawBlockEntry snowy_town_centers_snowy_meeting_point_1[] = {
        {PoolType::IRON_GOLEM, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 2},
        {PoolType::SNOWY_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 4},
        {PoolType::SNOWY_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 7},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 4, 0, 0},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 5, 0, 0},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 5, 0, 7},
        {PoolType::SNOWY_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 0, 3},
        {PoolType::SNOWY_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 10, 0, 1},
        {PoolType::SNOWY_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 5},
        {PoolType::SNOWY_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 2, 1, 0},
        {PoolType::SNOWY_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 8, 1, 7},
        {PoolType::SNOWY_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 11, 1, 5},
    };

    static const JigsawBlockEntry snowy_town_centers_snowy_meeting_point_2[] = {
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 0, 2},
        {PoolType::SNOWY_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 2},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 0},
        {PoolType::IRON_GOLEM, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 7},
        {PoolType::SNOWY_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 1},
        {PoolType::SNOWY_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 4},
        {PoolType::SNOWY_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 5, 1, 0},
        {PoolType::SNOWY_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 5, 1, 8},
        {PoolType::SNOWY_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 10, 1, 4},
    };

    static const JigsawBlockEntry snowy_town_centers_snowy_meeting_point_3[] = {
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 0, 1},
        {PoolType::IRON_GOLEM, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 0},
        {PoolType::SNOWY_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 1},
        {PoolType::SNOWY_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 5},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 6, 0, 6},
        {PoolType::SNOWY_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 3},
        {PoolType::SNOWY_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 3, 1, 0},
        {PoolType::SNOWY_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 3, 1, 6},
        {PoolType::SNOWY_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 6, 1, 3},
    };

    static const JigsawBlockEntry snowy_villagers_baby[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry snowy_villagers_nitwit[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry snowy_villagers_unemployed[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry snowy_zombie_houses_snowy_medium_house_1[] = {
        {PoolType::SNOWY_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 2},
        {PoolType::SNOWY_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 4},
        {PoolType::EMPTY, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 6, 1, 4},
    };

    static const JigsawBlockEntry snowy_zombie_houses_snowy_medium_house_2[] = {
        {PoolType::SNOWY_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 5, 0, 3},
        {PoolType::EMPTY, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 7, 0, 0},
        {PoolType::SNOWY_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 9, 0, 3},
    };

    static const JigsawBlockEntry snowy_zombie_houses_snowy_medium_house_3[] = {
        {PoolType::SNOWY_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 2},
        {PoolType::SNOWY_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 4},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 2},
    };

    static const JigsawBlockEntry snowy_zombie_houses_snowy_small_house_1[] = {
        {PoolType::SNOWY_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 2},
        {PoolType::EMPTY, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 3, 1, 5},
    };

    static const JigsawBlockEntry snowy_zombie_houses_snowy_small_house_2[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 3, 0, 0},
        {PoolType::SNOWY_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 3},
    };

    static const JigsawBlockEntry snowy_zombie_houses_snowy_small_house_3[] = {
        {PoolType::SNOWY_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 2},
        {PoolType::EMPTY, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 3, 0, 6},
    };

    static const JigsawBlockEntry snowy_zombie_houses_snowy_small_house_4[] = {
        {PoolType::SNOWY_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 4, 0, 3},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 3},
    };

    static const JigsawBlockEntry snowy_zombie_houses_snowy_small_house_5[] = {
        {PoolType::SNOWY_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 2},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 3},
    };

    static const JigsawBlockEntry snowy_zombie_houses_snowy_small_house_6[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 3},
        {PoolType::SNOWY_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 3},
    };

    static const JigsawBlockEntry snowy_zombie_houses_snowy_small_house_7[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 3},
        {PoolType::SNOWY_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 3},
    };

    static const JigsawBlockEntry snowy_zombie_houses_snowy_small_house_8[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 1},
    };

    static const JigsawBlockEntry snowy_zombie_streets_corner_01[] = {
        {PoolType::SNOWY_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 1},
        {PoolType::SNOWY_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 6},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 10},
        {PoolType::SNOWY_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 4, 0, 12},
        {PoolType::SNOWY_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 6, 0, 3},
        {PoolType::SNOWY_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 9, 0, 9},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 8},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 3, 1, 0},
        {PoolType::SNOWY_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 4, 1, 6},
    };

    static const JigsawBlockEntry snowy_zombie_streets_corner_02[] = {
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 1, 1, 0},
        {PoolType::SNOWY_ZHOUSES, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 9, 1, 12},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::EAST, BlockDirection::UP, 15, 1, 14},
    };

    static const JigsawBlockEntry snowy_zombie_streets_corner_03[] = {
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 1, 1, 3},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::EAST, BlockDirection::UP, 3, 1, 1},
    };

    static const JigsawBlockEntry snowy_zombie_streets_crossroad_01[] = {
        {PoolType::SNOWY_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 13, 0, 12},
        {PoolType::SNOWY_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 3},
        {PoolType::SNOWY_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 4},
        {PoolType::SNOWY_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 5},
        {PoolType::SNOWY_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 6},
        {PoolType::SNOWY_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 7},
        {PoolType::SNOWY_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 11},
        {PoolType::SNOWY_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 12},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 8, 1, 0},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 8, 1, 15},
        {PoolType::SNOWY_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 9, 1, 3},
        {PoolType::SNOWY_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 9, 1, 4},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::EAST, BlockDirection::UP, 15, 1, 8},
    };

    static const JigsawBlockEntry snowy_zombie_streets_crossroad_02[] = {
        {PoolType::SNOWY_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 11},
        {PoolType::SNOWY_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 5, 0, 13},
        {PoolType::SNOWY_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 0, 8},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 8},
        {PoolType::SNOWY_ZHOUSES, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 3, 1, 7},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 8, 1, 0},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 8, 1, 15},
        {PoolType::SNOWY_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 9, 1, 3},
        {PoolType::SNOWY_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 9, 1, 12},
    };

    static const JigsawBlockEntry snowy_zombie_streets_crossroad_03[] = {
        {PoolType::SNOWY_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 4, 0, 7},
        {PoolType::SNOWY_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 11, 0, 9},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 8},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 4, 1, 0},
        {PoolType::SNOWY_ZHOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 5, 1, 9},
        {PoolType::SNOWY_ZHOUSES, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 11, 1, 7},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 11, 1, 16},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::EAST, BlockDirection::UP, 15, 1, 8},
    };

    static const JigsawBlockEntry snowy_zombie_streets_crossroad_04[] = {
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 2},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 2, 1, 0},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 2, 1, 4},
    };

    static const JigsawBlockEntry snowy_zombie_streets_crossroad_05[] = {
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 2},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 2, 1, 0},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 2, 1, 4},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::EAST, BlockDirection::UP, 4, 1, 2},
    };

    static const JigsawBlockEntry snowy_zombie_streets_crossroad_06[] = {
        {PoolType::SNOWY_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 2},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 2},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 2, 1, 0},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 2, 1, 4},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::EAST, BlockDirection::UP, 4, 1, 2},
    };

    static const JigsawBlockEntry snowy_zombie_streets_square_01[] = {
        {PoolType::SNOWY_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 14, 0, 5},
        {PoolType::SNOWY_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 19, 0, 2},
        {PoolType::SNOWY_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 11, 1, 5},
        {PoolType::SNOWY_ZHOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 14, 1, 8},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 18, 1, 0},
    };

    static const JigsawBlockEntry snowy_zombie_streets_straight_01[] = {
        {PoolType::SNOWY_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 13},
        {PoolType::SNOWY_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 4, 0, 7},
        {PoolType::SNOWY_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 11, 0, 6},
        {PoolType::SNOWY_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 11, 0, 13},
        {PoolType::SNOWY_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 12, 0, 4},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 7, 1, 0},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 7, 1, 15},
    };

    static const JigsawBlockEntry snowy_zombie_streets_straight_02[] = {
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 1, 1, 0},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 1, 1, 15},
        {PoolType::SNOWY_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 8},
    };

    static const JigsawBlockEntry snowy_zombie_streets_straight_03[] = {
        {PoolType::SNOWY_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 0, 2},
        {PoolType::SNOWY_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 0, 8},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 1, 1, 0},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 1, 1, 10},
        {PoolType::SNOWY_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 3},
        {PoolType::SNOWY_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 4},
        {PoolType::SNOWY_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 5},
        {PoolType::SNOWY_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 6},
        {PoolType::SNOWY_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 7},
    };

    static const JigsawBlockEntry snowy_zombie_streets_straight_04[] = {
        {PoolType::SNOWY_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 0, 3},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 6},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 1, 1, 0},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 1, 1, 8},
        {PoolType::SNOWY_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 4},
    };

    static const JigsawBlockEntry snowy_zombie_streets_straight_06[] = {
        {PoolType::SNOWY_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 0, 3},
        {PoolType::SNOWY_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 9, 0, 9},
        {PoolType::SNOWY_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 9, 0, 15},
        {PoolType::SNOWY_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 3},
        {PoolType::SNOWY_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 4},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 8, 1, 0},
        {PoolType::SNOWY_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 8, 1, 8},
        {PoolType::SNOWY_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 8, 1, 9},
        {PoolType::SNOWY_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 8, 1, 14},
        {PoolType::SNOWY_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 8, 1, 15},
        {PoolType::SNOWY_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 9, 1, 2},
        {PoolType::SNOWY_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 9, 1, 3},
        {PoolType::SNOWY_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 9, 1, 4},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 9, 1, 17},
        {PoolType::SNOWY_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 10, 1, 8},
        {PoolType::SNOWY_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 10, 1, 9},
        {PoolType::SNOWY_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 10, 1, 10},
        {PoolType::SNOWY_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 10, 1, 14},
        {PoolType::SNOWY_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 10, 1, 15},
    };

    static const JigsawBlockEntry snowy_zombie_streets_straight_08[] = {
        {PoolType::SNOWY_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 3},
        {PoolType::SNOWY_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 13},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 1, 1, 0},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 1, 1, 16},
        {PoolType::SNOWY_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 7},
        {PoolType::SNOWY_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 8},
        {PoolType::SNOWY_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 9},
        {PoolType::SNOWY_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 10},
    };

    static const JigsawBlockEntry snowy_zombie_streets_turn_01[] = {
        {PoolType::SNOWY_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 0, 1},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 5, 1, 0},
        {PoolType::SNOWY_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 6},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 8, 1, 7},
        {PoolType::SNOWY_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 9, 1, 4},
    };

    static const JigsawBlockEntry snowy_zombie_town_centers_snowy_meeting_point_1[] = {
        {PoolType::SNOWY_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 7},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 4, 0, 0},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 5, 0, 0},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 5, 0, 7},
        {PoolType::SNOWY_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 10, 0, 1},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 5},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 2, 1, 0},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 8, 1, 7},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::EAST, BlockDirection::UP, 11, 1, 5},
    };

    static const JigsawBlockEntry snowy_zombie_town_centers_snowy_meeting_point_2[] = {
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 0, 2},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 0},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 4},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 5, 1, 0},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 5, 1, 8},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::EAST, BlockDirection::UP, 10, 1, 4},
    };

    static const JigsawBlockEntry snowy_zombie_town_centers_snowy_meeting_point_3[] = {
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 0, 1},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 6, 0, 6},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 3},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 3, 1, 0},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 3, 1, 6},
        {PoolType::SNOWY_ZSTREET, "street", BlockDirection::EAST, BlockDirection::UP, 6, 1, 3},
    };

    static const JigsawBlockEntry snowy_zombie_villagers_nitwit[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry snowy_zombie_villagers_unemployed[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry taiga_spruce[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

} // namespace

// Fonction pour obtenir les JigsawBlocks d'un template
inline std::vector<JigsawBlockEntry> getSnowyVillageJigsawBlocks(const std::string& templateName) {
    using namespace SnowyVillageJigsawData;
    
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
        {"snowy/houses/snowy_animal_pen_1", {snowy_houses_snowy_animal_pen_1, 2}},
        {"snowy/houses/snowy_animal_pen_2", {snowy_houses_snowy_animal_pen_2, 3}},
        {"snowy/houses/snowy_armorer_house_1", {snowy_houses_snowy_armorer_house_1, 1}},
        {"snowy/houses/snowy_armorer_house_2", {snowy_houses_snowy_armorer_house_2, 1}},
        {"snowy/houses/snowy_butchers_shop_1", {snowy_houses_snowy_butchers_shop_1, 2}},
        {"snowy/houses/snowy_butchers_shop_2", {snowy_houses_snowy_butchers_shop_2, 2}},
        {"snowy/houses/snowy_cartographer_house_1", {snowy_houses_snowy_cartographer_house_1, 1}},
        {"snowy/houses/snowy_farm_1", {snowy_houses_snowy_farm_1, 1}},
        {"snowy/houses/snowy_farm_2", {snowy_houses_snowy_farm_2, 1}},
        {"snowy/houses/snowy_fisher_cottage", {snowy_houses_snowy_fisher_cottage, 1}},
        {"snowy/houses/snowy_fletcher_house_1", {snowy_houses_snowy_fletcher_house_1, 1}},
        {"snowy/houses/snowy_library_1", {snowy_houses_snowy_library_1, 1}},
        {"snowy/houses/snowy_masons_house_1", {snowy_houses_snowy_masons_house_1, 1}},
        {"snowy/houses/snowy_masons_house_2", {snowy_houses_snowy_masons_house_2, 1}},
        {"snowy/houses/snowy_medium_house_1", {snowy_houses_snowy_medium_house_1, 3}},
        {"snowy/houses/snowy_medium_house_2", {snowy_houses_snowy_medium_house_2, 3}},
        {"snowy/houses/snowy_medium_house_3", {snowy_houses_snowy_medium_house_3, 3}},
        {"snowy/houses/snowy_shepherds_house_1", {snowy_houses_snowy_shepherds_house_1, 2}},
        {"snowy/houses/snowy_small_house_1", {snowy_houses_snowy_small_house_1, 2}},
        {"snowy/houses/snowy_small_house_2", {snowy_houses_snowy_small_house_2, 2}},
        {"snowy/houses/snowy_small_house_3", {snowy_houses_snowy_small_house_3, 2}},
        {"snowy/houses/snowy_small_house_4", {snowy_houses_snowy_small_house_4, 2}},
        {"snowy/houses/snowy_small_house_5", {snowy_houses_snowy_small_house_5, 2}},
        {"snowy/houses/snowy_small_house_6", {snowy_houses_snowy_small_house_6, 2}},
        {"snowy/houses/snowy_small_house_7", {snowy_houses_snowy_small_house_7, 2}},
        {"snowy/houses/snowy_small_house_8", {snowy_houses_snowy_small_house_8, 2}},
        {"snowy/houses/snowy_tannery_1", {snowy_houses_snowy_tannery_1, 1}},
        {"snowy/houses/snowy_temple_1", {snowy_houses_snowy_temple_1, 1}},
        {"snowy/houses/snowy_tool_smith_1", {snowy_houses_snowy_tool_smith_1, 1}},
        {"snowy/houses/snowy_weapon_smith_1", {snowy_houses_snowy_weapon_smith_1, 1}},
        {"snowy/pile_ice", {snowy_pile_ice, 1}},
        {"snowy/pile_snow", {snowy_pile_snow, 1}},
        {"snowy/snowy_lamp_post_01", {snowy_snowy_lamp_post_01, 1}},
        {"snowy/snowy_lamp_post_02", {snowy_snowy_lamp_post_02, 1}},
        {"snowy/snowy_lamp_post_03", {snowy_snowy_lamp_post_03, 1}},
        {"snowy/streets/corner_01", {snowy_streets_corner_01, 9}},
        {"snowy/streets/corner_02", {snowy_streets_corner_02, 3}},
        {"snowy/streets/corner_03", {snowy_streets_corner_03, 2}},
        {"snowy/streets/crossroad_01", {snowy_streets_crossroad_01, 13}},
        {"snowy/streets/crossroad_02", {snowy_streets_crossroad_02, 9}},
        {"snowy/streets/crossroad_03", {snowy_streets_crossroad_03, 8}},
        {"snowy/streets/crossroad_04", {snowy_streets_crossroad_04, 3}},
        {"snowy/streets/crossroad_05", {snowy_streets_crossroad_05, 4}},
        {"snowy/streets/crossroad_06", {snowy_streets_crossroad_06, 5}},
        {"snowy/streets/square_01", {snowy_streets_square_01, 5}},
        {"snowy/streets/straight_01", {snowy_streets_straight_01, 7}},
        {"snowy/streets/straight_02", {snowy_streets_straight_02, 3}},
        {"snowy/streets/straight_03", {snowy_streets_straight_03, 9}},
        {"snowy/streets/straight_04", {snowy_streets_straight_04, 5}},
        {"snowy/streets/straight_06", {snowy_streets_straight_06, 19}},
        {"snowy/streets/straight_08", {snowy_streets_straight_08, 8}},
        {"snowy/streets/turn_01", {snowy_streets_turn_01, 5}},
        {"snowy/town_centers/snowy_meeting_point_1", {snowy_town_centers_snowy_meeting_point_1, 12}},
        {"snowy/town_centers/snowy_meeting_point_2", {snowy_town_centers_snowy_meeting_point_2, 9}},
        {"snowy/town_centers/snowy_meeting_point_3", {snowy_town_centers_snowy_meeting_point_3, 9}},
        {"snowy/villagers/baby", {snowy_villagers_baby, 1}},
        {"snowy/villagers/nitwit", {snowy_villagers_nitwit, 1}},
        {"snowy/villagers/unemployed", {snowy_villagers_unemployed, 1}},
        {"snowy/zombie/houses/snowy_medium_house_1", {snowy_zombie_houses_snowy_medium_house_1, 3}},
        {"snowy/zombie/houses/snowy_medium_house_2", {snowy_zombie_houses_snowy_medium_house_2, 3}},
        {"snowy/zombie/houses/snowy_medium_house_3", {snowy_zombie_houses_snowy_medium_house_3, 3}},
        {"snowy/zombie/houses/snowy_small_house_1", {snowy_zombie_houses_snowy_small_house_1, 2}},
        {"snowy/zombie/houses/snowy_small_house_2", {snowy_zombie_houses_snowy_small_house_2, 2}},
        {"snowy/zombie/houses/snowy_small_house_3", {snowy_zombie_houses_snowy_small_house_3, 2}},
        {"snowy/zombie/houses/snowy_small_house_4", {snowy_zombie_houses_snowy_small_house_4, 2}},
        {"snowy/zombie/houses/snowy_small_house_5", {snowy_zombie_houses_snowy_small_house_5, 2}},
        {"snowy/zombie/houses/snowy_small_house_6", {snowy_zombie_houses_snowy_small_house_6, 2}},
        {"snowy/zombie/houses/snowy_small_house_7", {snowy_zombie_houses_snowy_small_house_7, 2}},
        {"snowy/zombie/houses/snowy_small_house_8", {snowy_zombie_houses_snowy_small_house_8, 1}},
        {"snowy/zombie/streets/corner_01", {snowy_zombie_streets_corner_01, 9}},
        {"snowy/zombie/streets/corner_02", {snowy_zombie_streets_corner_02, 3}},
        {"snowy/zombie/streets/corner_03", {snowy_zombie_streets_corner_03, 2}},
        {"snowy/zombie/streets/crossroad_01", {snowy_zombie_streets_crossroad_01, 13}},
        {"snowy/zombie/streets/crossroad_02", {snowy_zombie_streets_crossroad_02, 9}},
        {"snowy/zombie/streets/crossroad_03", {snowy_zombie_streets_crossroad_03, 8}},
        {"snowy/zombie/streets/crossroad_04", {snowy_zombie_streets_crossroad_04, 3}},
        {"snowy/zombie/streets/crossroad_05", {snowy_zombie_streets_crossroad_05, 4}},
        {"snowy/zombie/streets/crossroad_06", {snowy_zombie_streets_crossroad_06, 5}},
        {"snowy/zombie/streets/square_01", {snowy_zombie_streets_square_01, 5}},
        {"snowy/zombie/streets/straight_01", {snowy_zombie_streets_straight_01, 7}},
        {"snowy/zombie/streets/straight_02", {snowy_zombie_streets_straight_02, 3}},
        {"snowy/zombie/streets/straight_03", {snowy_zombie_streets_straight_03, 9}},
        {"snowy/zombie/streets/straight_04", {snowy_zombie_streets_straight_04, 5}},
        {"snowy/zombie/streets/straight_06", {snowy_zombie_streets_straight_06, 19}},
        {"snowy/zombie/streets/straight_08", {snowy_zombie_streets_straight_08, 8}},
        {"snowy/zombie/streets/turn_01", {snowy_zombie_streets_turn_01, 5}},
        {"snowy/zombie/town_centers/snowy_meeting_point_1", {snowy_zombie_town_centers_snowy_meeting_point_1, 9}},
        {"snowy/zombie/town_centers/snowy_meeting_point_2", {snowy_zombie_town_centers_snowy_meeting_point_2, 6}},
        {"snowy/zombie/town_centers/snowy_meeting_point_3", {snowy_zombie_town_centers_snowy_meeting_point_3, 6}},
        {"snowy/zombie/villagers/nitwit", {snowy_zombie_villagers_nitwit, 1}},
        {"snowy/zombie/villagers/unemployed", {snowy_zombie_villagers_unemployed, 1}},
        {"taiga/spruce", {taiga_spruce, 1}},
    };
    
    auto it = LOOKUP.find(templateName);
    if (it != LOOKUP.end()) {
        return std::vector<JigsawBlockEntry>(it->second.first, it->second.first + it->second.second);
    }
    return {};
}

// Version sans allocation (plus rapide)
inline bool getSnowyVillageJigsawBlocksFast(const std::string& templateName, const JigsawBlockEntry*& out, size_t& count) {
    using namespace SnowyVillageJigsawData;
    
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
        {"snowy/houses/snowy_animal_pen_1", {snowy_houses_snowy_animal_pen_1, 2}},
        {"snowy/houses/snowy_animal_pen_2", {snowy_houses_snowy_animal_pen_2, 3}},
        {"snowy/houses/snowy_armorer_house_1", {snowy_houses_snowy_armorer_house_1, 1}},
        {"snowy/houses/snowy_armorer_house_2", {snowy_houses_snowy_armorer_house_2, 1}},
        {"snowy/houses/snowy_butchers_shop_1", {snowy_houses_snowy_butchers_shop_1, 2}},
        {"snowy/houses/snowy_butchers_shop_2", {snowy_houses_snowy_butchers_shop_2, 2}},
        {"snowy/houses/snowy_cartographer_house_1", {snowy_houses_snowy_cartographer_house_1, 1}},
        {"snowy/houses/snowy_farm_1", {snowy_houses_snowy_farm_1, 1}},
        {"snowy/houses/snowy_farm_2", {snowy_houses_snowy_farm_2, 1}},
        {"snowy/houses/snowy_fisher_cottage", {snowy_houses_snowy_fisher_cottage, 1}},
        {"snowy/houses/snowy_fletcher_house_1", {snowy_houses_snowy_fletcher_house_1, 1}},
        {"snowy/houses/snowy_library_1", {snowy_houses_snowy_library_1, 1}},
        {"snowy/houses/snowy_masons_house_1", {snowy_houses_snowy_masons_house_1, 1}},
        {"snowy/houses/snowy_masons_house_2", {snowy_houses_snowy_masons_house_2, 1}},
        {"snowy/houses/snowy_medium_house_1", {snowy_houses_snowy_medium_house_1, 3}},
        {"snowy/houses/snowy_medium_house_2", {snowy_houses_snowy_medium_house_2, 3}},
        {"snowy/houses/snowy_medium_house_3", {snowy_houses_snowy_medium_house_3, 3}},
        {"snowy/houses/snowy_shepherds_house_1", {snowy_houses_snowy_shepherds_house_1, 2}},
        {"snowy/houses/snowy_small_house_1", {snowy_houses_snowy_small_house_1, 2}},
        {"snowy/houses/snowy_small_house_2", {snowy_houses_snowy_small_house_2, 2}},
        {"snowy/houses/snowy_small_house_3", {snowy_houses_snowy_small_house_3, 2}},
        {"snowy/houses/snowy_small_house_4", {snowy_houses_snowy_small_house_4, 2}},
        {"snowy/houses/snowy_small_house_5", {snowy_houses_snowy_small_house_5, 2}},
        {"snowy/houses/snowy_small_house_6", {snowy_houses_snowy_small_house_6, 2}},
        {"snowy/houses/snowy_small_house_7", {snowy_houses_snowy_small_house_7, 2}},
        {"snowy/houses/snowy_small_house_8", {snowy_houses_snowy_small_house_8, 2}},
        {"snowy/houses/snowy_tannery_1", {snowy_houses_snowy_tannery_1, 1}},
        {"snowy/houses/snowy_temple_1", {snowy_houses_snowy_temple_1, 1}},
        {"snowy/houses/snowy_tool_smith_1", {snowy_houses_snowy_tool_smith_1, 1}},
        {"snowy/houses/snowy_weapon_smith_1", {snowy_houses_snowy_weapon_smith_1, 1}},
        {"snowy/pile_ice", {snowy_pile_ice, 1}},
        {"snowy/pile_snow", {snowy_pile_snow, 1}},
        {"snowy/snowy_lamp_post_01", {snowy_snowy_lamp_post_01, 1}},
        {"snowy/snowy_lamp_post_02", {snowy_snowy_lamp_post_02, 1}},
        {"snowy/snowy_lamp_post_03", {snowy_snowy_lamp_post_03, 1}},
        {"snowy/streets/corner_01", {snowy_streets_corner_01, 9}},
        {"snowy/streets/corner_02", {snowy_streets_corner_02, 3}},
        {"snowy/streets/corner_03", {snowy_streets_corner_03, 2}},
        {"snowy/streets/crossroad_01", {snowy_streets_crossroad_01, 13}},
        {"snowy/streets/crossroad_02", {snowy_streets_crossroad_02, 9}},
        {"snowy/streets/crossroad_03", {snowy_streets_crossroad_03, 8}},
        {"snowy/streets/crossroad_04", {snowy_streets_crossroad_04, 3}},
        {"snowy/streets/crossroad_05", {snowy_streets_crossroad_05, 4}},
        {"snowy/streets/crossroad_06", {snowy_streets_crossroad_06, 5}},
        {"snowy/streets/square_01", {snowy_streets_square_01, 5}},
        {"snowy/streets/straight_01", {snowy_streets_straight_01, 7}},
        {"snowy/streets/straight_02", {snowy_streets_straight_02, 3}},
        {"snowy/streets/straight_03", {snowy_streets_straight_03, 9}},
        {"snowy/streets/straight_04", {snowy_streets_straight_04, 5}},
        {"snowy/streets/straight_06", {snowy_streets_straight_06, 19}},
        {"snowy/streets/straight_08", {snowy_streets_straight_08, 8}},
        {"snowy/streets/turn_01", {snowy_streets_turn_01, 5}},
        {"snowy/town_centers/snowy_meeting_point_1", {snowy_town_centers_snowy_meeting_point_1, 12}},
        {"snowy/town_centers/snowy_meeting_point_2", {snowy_town_centers_snowy_meeting_point_2, 9}},
        {"snowy/town_centers/snowy_meeting_point_3", {snowy_town_centers_snowy_meeting_point_3, 9}},
        {"snowy/villagers/baby", {snowy_villagers_baby, 1}},
        {"snowy/villagers/nitwit", {snowy_villagers_nitwit, 1}},
        {"snowy/villagers/unemployed", {snowy_villagers_unemployed, 1}},
        {"snowy/zombie/houses/snowy_medium_house_1", {snowy_zombie_houses_snowy_medium_house_1, 3}},
        {"snowy/zombie/houses/snowy_medium_house_2", {snowy_zombie_houses_snowy_medium_house_2, 3}},
        {"snowy/zombie/houses/snowy_medium_house_3", {snowy_zombie_houses_snowy_medium_house_3, 3}},
        {"snowy/zombie/houses/snowy_small_house_1", {snowy_zombie_houses_snowy_small_house_1, 2}},
        {"snowy/zombie/houses/snowy_small_house_2", {snowy_zombie_houses_snowy_small_house_2, 2}},
        {"snowy/zombie/houses/snowy_small_house_3", {snowy_zombie_houses_snowy_small_house_3, 2}},
        {"snowy/zombie/houses/snowy_small_house_4", {snowy_zombie_houses_snowy_small_house_4, 2}},
        {"snowy/zombie/houses/snowy_small_house_5", {snowy_zombie_houses_snowy_small_house_5, 2}},
        {"snowy/zombie/houses/snowy_small_house_6", {snowy_zombie_houses_snowy_small_house_6, 2}},
        {"snowy/zombie/houses/snowy_small_house_7", {snowy_zombie_houses_snowy_small_house_7, 2}},
        {"snowy/zombie/houses/snowy_small_house_8", {snowy_zombie_houses_snowy_small_house_8, 1}},
        {"snowy/zombie/streets/corner_01", {snowy_zombie_streets_corner_01, 9}},
        {"snowy/zombie/streets/corner_02", {snowy_zombie_streets_corner_02, 3}},
        {"snowy/zombie/streets/corner_03", {snowy_zombie_streets_corner_03, 2}},
        {"snowy/zombie/streets/crossroad_01", {snowy_zombie_streets_crossroad_01, 13}},
        {"snowy/zombie/streets/crossroad_02", {snowy_zombie_streets_crossroad_02, 9}},
        {"snowy/zombie/streets/crossroad_03", {snowy_zombie_streets_crossroad_03, 8}},
        {"snowy/zombie/streets/crossroad_04", {snowy_zombie_streets_crossroad_04, 3}},
        {"snowy/zombie/streets/crossroad_05", {snowy_zombie_streets_crossroad_05, 4}},
        {"snowy/zombie/streets/crossroad_06", {snowy_zombie_streets_crossroad_06, 5}},
        {"snowy/zombie/streets/square_01", {snowy_zombie_streets_square_01, 5}},
        {"snowy/zombie/streets/straight_01", {snowy_zombie_streets_straight_01, 7}},
        {"snowy/zombie/streets/straight_02", {snowy_zombie_streets_straight_02, 3}},
        {"snowy/zombie/streets/straight_03", {snowy_zombie_streets_straight_03, 9}},
        {"snowy/zombie/streets/straight_04", {snowy_zombie_streets_straight_04, 5}},
        {"snowy/zombie/streets/straight_06", {snowy_zombie_streets_straight_06, 19}},
        {"snowy/zombie/streets/straight_08", {snowy_zombie_streets_straight_08, 8}},
        {"snowy/zombie/streets/turn_01", {snowy_zombie_streets_turn_01, 5}},
        {"snowy/zombie/town_centers/snowy_meeting_point_1", {snowy_zombie_town_centers_snowy_meeting_point_1, 9}},
        {"snowy/zombie/town_centers/snowy_meeting_point_2", {snowy_zombie_town_centers_snowy_meeting_point_2, 6}},
        {"snowy/zombie/town_centers/snowy_meeting_point_3", {snowy_zombie_town_centers_snowy_meeting_point_3, 6}},
        {"snowy/zombie/villagers/nitwit", {snowy_zombie_villagers_nitwit, 1}},
        {"snowy/zombie/villagers/unemployed", {snowy_zombie_villagers_unemployed, 1}},
        {"taiga/spruce", {taiga_spruce, 1}},
    };
    
    auto it = LOOKUP.find(templateName);
    if (it != LOOKUP.end()) {
        out = it->second.first;
        count = it->second.second;
        return true;
    }
    return false;
}
