#pragma once
// Auto-generated from TaigaVillageJigsawBlocks.java
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
namespace TaigaVillageJigsawData {

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

    static const JigsawBlockEntry taiga_houses_taiga_animal_pen_1[] = {
        {PoolType::ANIMALS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 6, 0, 4},
        {PoolType::EMPTY, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 6, 0, 7},
        {PoolType::ANIMALS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 0, 3},
    };

    static const JigsawBlockEntry taiga_houses_taiga_armorer_2[] = {
        {PoolType::TAIGA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 0, 0},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 6, 0, 4},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 3},
    };

    static const JigsawBlockEntry taiga_houses_taiga_armorer_house_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 3},
    };

    static const JigsawBlockEntry taiga_houses_taiga_butcher_shop_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 4, 0, 8},
        {PoolType::BUTCHER_ANIMAL, "bottom", BlockDirection::UP, BlockDirection::NORTH, 7, 0, 6},
    };

    static const JigsawBlockEntry taiga_houses_taiga_cartographer_house_1[] = {
        {PoolType::TAIGA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 0, 0},
        {PoolType::EMPTY, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 3, 1, 0},
    };

    static const JigsawBlockEntry taiga_houses_taiga_fisher_cottage_1[] = {
        {PoolType::TAIGA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 1, 0},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 1, 5},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 5, 1, 11},
        {PoolType::TAIGA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 9, 1, 11},
        {PoolType::EMPTY, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 4, 2, 11},
    };

    static const JigsawBlockEntry taiga_houses_taiga_fletcher_house_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 0, 5},
    };

    static const JigsawBlockEntry taiga_houses_taiga_large_farm_1[] = {
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 0, 1},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 3},
    };

    static const JigsawBlockEntry taiga_houses_taiga_large_farm_2[] = {
        {PoolType::TAIGA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 7, 0, 6},
        {PoolType::EMPTY, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 3, 1, 8},
    };

    static const JigsawBlockEntry taiga_houses_taiga_library_1[] = {
        {PoolType::TAIGA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 0, 0},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 7},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 7},
        {PoolType::EMPTY, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 5, 1, 0},
    };

    static const JigsawBlockEntry taiga_houses_taiga_masons_house_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 1, 1, 4},
    };

    static const JigsawBlockEntry taiga_houses_taiga_medium_house_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 5, 3, 6},
        {PoolType::TAIGA_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 5, 2},
        {PoolType::TAIGA_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 5, 3},
    };

    static const JigsawBlockEntry taiga_houses_taiga_medium_house_2[] = {
        {PoolType::TAIGA_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 4},
        {PoolType::EMPTY, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 4, 1, 0},
        {PoolType::TAIGA_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 4, 5},
    };

    static const JigsawBlockEntry taiga_houses_taiga_medium_house_3[] = {
        {PoolType::TAIGA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 6},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 0},
        {PoolType::TAIGA_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 4, 0, 4},
        {PoolType::TAIGA_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 4, 0, 8},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 6},
    };

    static const JigsawBlockEntry taiga_houses_taiga_medium_house_4[] = {
        {PoolType::TAIGA_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 6},
        {PoolType::TAIGA_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 6, 0, 4},
        {PoolType::EMPTY, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 5, 1, 8},
    };

    static const JigsawBlockEntry taiga_houses_taiga_shepherds_house_1[] = {
        {PoolType::TAIGA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 0, 0},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 5},
        {PoolType::SHEEPS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 1, 6},
    };

    static const JigsawBlockEntry taiga_houses_taiga_small_farm_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 3, 1, 0},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 6, 1, 0},
    };

    static const JigsawBlockEntry taiga_houses_taiga_small_house_1[] = {
        {PoolType::TAIGA_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 1, 3},
        {PoolType::EMPTY, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 3, 1, 0},
    };

    static const JigsawBlockEntry taiga_houses_taiga_small_house_2[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 3, 0, 0},
        {PoolType::TAIGA_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 3},
    };

    static const JigsawBlockEntry taiga_houses_taiga_small_house_3[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 3, 0, 0},
        {PoolType::TAIGA_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 3},
    };

    static const JigsawBlockEntry taiga_houses_taiga_small_house_4[] = {
        {PoolType::TAIGA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 0, 6},
        {PoolType::TAIGA_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 3},
        {PoolType::EMPTY, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 3, 1, 7},
    };

    static const JigsawBlockEntry taiga_houses_taiga_small_house_5[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 1, 0, 3},
        {PoolType::TAIGA_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 4, 0, 3},
    };

    static const JigsawBlockEntry taiga_houses_taiga_tannery_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 1, 0, 5},
    };

    static const JigsawBlockEntry taiga_houses_taiga_temple_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 6, 1, 10},
    };

    static const JigsawBlockEntry taiga_houses_taiga_tool_smith_1[] = {
        {PoolType::TAIGA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 7},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 9, 0, 7},
        {PoolType::EMPTY, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 5, 1, 7},
    };

    static const JigsawBlockEntry taiga_houses_taiga_weaponsmith_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 3, 1, 0},
    };

    static const JigsawBlockEntry taiga_houses_taiga_weaponsmith_2[] = {
        {PoolType::TAIGA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 5, 0, 2},
        {PoolType::EMPTY, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 2, 1, 0},
    };

    static const JigsawBlockEntry taiga_patch_berry_bush[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry taiga_patch_taiga_grass[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry taiga_pile_pumpkin[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry taiga_pine[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry taiga_spruce[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry taiga_streets_corner_01[] = {
        {PoolType::TAIGA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 4},
        {PoolType::TAIGA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 13},
        {PoolType::TAIGA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 0, 12},
        {PoolType::TAIGA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 10, 0, 3},
        {PoolType::TAIGA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 13, 0, 9},
        {PoolType::TAIGA_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 8},
        {PoolType::TAIGA_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 7, 1, 0},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 8, 1, 6},
    };

    static const JigsawBlockEntry taiga_streets_corner_02[] = {
        {PoolType::TAIGA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 0, 15},
        {PoolType::TAIGA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 3},
        {PoolType::TAIGA_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 1, 1, 0},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 9, 1, 12},
        {PoolType::TAIGA_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 15, 1, 14},
    };

    static const JigsawBlockEntry taiga_streets_corner_03[] = {
        {PoolType::TAIGA_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 1, 1, 3},
        {PoolType::TAIGA_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 3, 1, 1},
    };

    static const JigsawBlockEntry taiga_streets_crossroad_01[] = {
        {PoolType::TAIGA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 13, 0, 12},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 3},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 4},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 5},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 6},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 7},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 11},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 12},
        {PoolType::TAIGA_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 8, 1, 0},
        {PoolType::TAIGA_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 8, 1, 15},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 9, 1, 3},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 9, 1, 4},
        {PoolType::TAIGA_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 15, 1, 8},
    };

    static const JigsawBlockEntry taiga_streets_crossroad_02[] = {
        {PoolType::TAIGA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 5},
        {PoolType::TAIGA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 5, 0, 1},
        {PoolType::TAIGA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 11, 0, 5},
        {PoolType::TAIGA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 13, 0, 12},
        {PoolType::TAIGA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 14, 0, 2},
        {PoolType::TAIGA_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 8},
        {PoolType::TAIGA_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 8, 1, 0},
        {PoolType::TAIGA_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 8, 1, 15},
        {PoolType::TAIGA_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 15, 1, 8},
    };

    static const JigsawBlockEntry taiga_streets_crossroad_03[] = {
        {PoolType::TAIGA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 13},
        {PoolType::TAIGA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 0, 11},
        {PoolType::TAIGA_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 8},
        {PoolType::TAIGA_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 4, 1, 0},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 11, 1, 7},
        {PoolType::TAIGA_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 11, 1, 15},
        {PoolType::TAIGA_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 15, 1, 8},
    };

    static const JigsawBlockEntry taiga_streets_crossroad_04[] = {
        {PoolType::TAIGA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 2},
        {PoolType::TAIGA_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 2},
        {PoolType::TAIGA_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 2, 1, 0},
        {PoolType::TAIGA_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 2, 1, 4},
    };

    static const JigsawBlockEntry taiga_streets_crossroad_05[] = {
        {PoolType::TAIGA_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 2},
        {PoolType::TAIGA_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 2, 1, 0},
        {PoolType::TAIGA_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 2, 1, 4},
        {PoolType::TAIGA_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 4, 1, 2},
    };

    static const JigsawBlockEntry taiga_streets_crossroad_06[] = {
        {PoolType::TAIGA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 2},
        {PoolType::TAIGA_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 2},
        {PoolType::TAIGA_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 2, 1, 0},
        {PoolType::TAIGA_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 2, 1, 4},
        {PoolType::TAIGA_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 4, 1, 2},
    };

    static const JigsawBlockEntry taiga_streets_straight_01[] = {
        {PoolType::TAIGA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 13},
        {PoolType::TAIGA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 4, 0, 7},
        {PoolType::TAIGA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 11, 0, 6},
        {PoolType::TAIGA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 11, 0, 13},
        {PoolType::TAIGA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 12, 0, 4},
        {PoolType::TAIGA_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 7, 1, 0},
        {PoolType::TAIGA_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 7, 1, 15},
    };

    static const JigsawBlockEntry taiga_streets_straight_02[] = {
        {PoolType::TAIGA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 2},
        {PoolType::TAIGA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 13},
        {PoolType::TAIGA_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 1, 1, 0},
        {PoolType::TAIGA_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 1, 1, 15},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 8},
    };

    static const JigsawBlockEntry taiga_streets_straight_03[] = {
        {PoolType::TAIGA_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 1, 1, 0},
        {PoolType::TAIGA_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 1, 1, 10},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 3},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 4},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 5},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 6},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 7},
    };

    static const JigsawBlockEntry taiga_streets_straight_04[] = {
        {PoolType::TAIGA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 0, 4},
        {PoolType::TAIGA_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 1, 1, 0},
        {PoolType::TAIGA_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 1, 1, 8},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 4},
    };

    static const JigsawBlockEntry taiga_streets_straight_05[] = {
        {PoolType::TAIGA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 3},
        {PoolType::TAIGA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 13},
        {PoolType::TAIGA_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 1, 1, 0},
        {PoolType::TAIGA_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 1, 1, 16},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 7},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 8},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 9},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 10},
    };

    static const JigsawBlockEntry taiga_streets_straight_06[] = {
        {PoolType::TAIGA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 0, 3},
        {PoolType::TAIGA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 9, 0, 9},
        {PoolType::TAIGA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 9, 0, 15},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 3},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 4},
        {PoolType::TAIGA_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 8, 1, 0},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 8, 1, 8},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 8, 1, 9},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 8, 1, 14},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 8, 1, 15},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 9, 1, 2},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 9, 1, 3},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 9, 1, 4},
        {PoolType::TAIGA_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 9, 1, 17},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 10, 1, 8},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 10, 1, 9},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 10, 1, 10},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 10, 1, 14},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 10, 1, 15},
    };

    static const JigsawBlockEntry taiga_streets_turn_01[] = {
        {PoolType::TAIGA_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 5, 1, 0},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 6},
        {PoolType::TAIGA_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 8, 1, 7},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 9, 1, 4},
    };

    static const JigsawBlockEntry taiga_taiga_decoration_1[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 1, 1, 3},
    };

    static const JigsawBlockEntry taiga_taiga_decoration_2[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 1, 0, 1},
    };

    static const JigsawBlockEntry taiga_taiga_decoration_3[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry taiga_taiga_decoration_4[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry taiga_taiga_decoration_5[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry taiga_taiga_decoration_6[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 1, 0, 1},
    };

    static const JigsawBlockEntry taiga_taiga_lamp_post_1[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry taiga_town_centers_taiga_meeting_point_1[] = {
        {PoolType::TAIGA_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 4},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 3},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 5, 0, 3},
        {PoolType::IRON_GOLEM, "bottom", BlockDirection::UP, BlockDirection::NORTH, 6, 0, 4},
        {PoolType::TAIGA_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 7, 0, 2},
        {PoolType::TAIGA_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 9, 0, 5},
        {PoolType::TAIGA_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 3},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 2, 1, 6},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 3, 1, 6},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 4, 1, 6},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 5, 1, 6},
        {PoolType::TAIGA_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 6, 1, 0},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 6, 1, 6},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 7, 1, 6},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 11, 1, 3},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 11, 1, 4},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 11, 1, 5},
        {PoolType::TAIGA_HOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 11, 1, 6},
    };

    static const JigsawBlockEntry taiga_town_centers_taiga_meeting_point_2[] = {
        {PoolType::TAIGA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 1, 0},
        {PoolType::TAIGA_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 1, 3},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 1, 6},
        {PoolType::TAIGA_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 1, 1},
        {PoolType::IRON_GOLEM, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 1, 8},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 1, 0},
        {PoolType::TAIGA_VILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 1, 5},
        {PoolType::TAIGA_DECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 1, 7},
        {PoolType::TAIGA_STREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 2, 4},
        {PoolType::TAIGA_STREET, "street", BlockDirection::NORTH, BlockDirection::UP, 4, 2, 0},
        {PoolType::TAIGA_STREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 4, 2, 8},
        {PoolType::TAIGA_STREET, "street", BlockDirection::EAST, BlockDirection::UP, 8, 2, 4},
    };

    static const JigsawBlockEntry taiga_villagers_baby[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry taiga_villagers_nitwit[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry taiga_villagers_unemployed[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry taiga_zombie_houses_taiga_cartographer_house_1[] = {
        {PoolType::TAIGA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 0, 0},
        {PoolType::EMPTY, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 3, 1, 0},
    };

    static const JigsawBlockEntry taiga_zombie_houses_taiga_fisher_cottage_1[] = {
        {PoolType::TAIGA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 1, 0},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 1, 5},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 5, 1, 11},
        {PoolType::TAIGA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 9, 1, 11},
        {PoolType::EMPTY, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 4, 2, 11},
    };

    static const JigsawBlockEntry taiga_zombie_houses_taiga_large_farm_2[] = {
        {PoolType::TAIGA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 7, 0, 6},
        {PoolType::EMPTY, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 3, 1, 8},
    };

    static const JigsawBlockEntry taiga_zombie_houses_taiga_library_1[] = {
        {PoolType::TAIGA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 0, 0},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 7},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 7},
        {PoolType::EMPTY, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 5, 1, 0},
    };

    static const JigsawBlockEntry taiga_zombie_houses_taiga_medium_house_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 5, 3, 6},
        {PoolType::TAIGA_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 5, 3},
    };

    static const JigsawBlockEntry taiga_zombie_houses_taiga_medium_house_2[] = {
        {PoolType::TAIGA_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 4},
        {PoolType::EMPTY, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 4, 1, 0},
        {PoolType::TAIGA_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 4, 5},
    };

    static const JigsawBlockEntry taiga_zombie_houses_taiga_medium_house_3[] = {
        {PoolType::TAIGA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 6},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 0},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 6},
    };

    static const JigsawBlockEntry taiga_zombie_houses_taiga_medium_house_4[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 5, 1, 8},
    };

    static const JigsawBlockEntry taiga_zombie_houses_taiga_shepherds_house_1[] = {
        {PoolType::TAIGA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 0, 0},
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 0, 1, 5},
        {PoolType::SHEEPS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 1, 6},
    };

    static const JigsawBlockEntry taiga_zombie_houses_taiga_small_house_1[] = {
        {PoolType::TAIGA_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 1, 3},
        {PoolType::EMPTY, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 3, 1, 0},
    };

    static const JigsawBlockEntry taiga_zombie_houses_taiga_small_house_2[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 3, 0, 0},
        {PoolType::TAIGA_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 3},
    };

    static const JigsawBlockEntry taiga_zombie_houses_taiga_small_house_3[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 3, 0, 0},
        {PoolType::TAIGA_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 3},
    };

    static const JigsawBlockEntry taiga_zombie_houses_taiga_small_house_4[] = {
        {PoolType::TAIGA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 0, 6},
        {PoolType::TAIGA_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 3},
        {PoolType::EMPTY, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 3, 1, 7},
    };

    static const JigsawBlockEntry taiga_zombie_houses_taiga_small_house_5[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 1, 0, 3},
        {PoolType::TAIGA_ZVILLAGER, "bottom", BlockDirection::UP, BlockDirection::NORTH, 4, 0, 3},
    };

    static const JigsawBlockEntry taiga_zombie_houses_taiga_temple_1[] = {
        {PoolType::EMPTY, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 6, 1, 10},
    };

    static const JigsawBlockEntry taiga_zombie_houses_taiga_tool_smith_1[] = {
        {PoolType::TAIGA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 7},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 9, 0, 7},
        {PoolType::EMPTY, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 5, 1, 7},
    };

    static const JigsawBlockEntry taiga_zombie_houses_taiga_weaponsmith_2[] = {
        {PoolType::TAIGA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 5, 0, 2},
        {PoolType::EMPTY, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 2, 1, 0},
    };

    static const JigsawBlockEntry taiga_zombie_streets_corner_01[] = {
        {PoolType::TAIGA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 4},
        {PoolType::TAIGA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 13},
        {PoolType::TAIGA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 0, 12},
        {PoolType::TAIGA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 10, 0, 3},
        {PoolType::TAIGA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 13, 0, 9},
        {PoolType::TAIGA_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 8},
        {PoolType::TAIGA_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 7, 1, 0},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 8, 1, 6},
    };

    static const JigsawBlockEntry taiga_zombie_streets_corner_02[] = {
        {PoolType::TAIGA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 0, 15},
        {PoolType::TAIGA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 3},
        {PoolType::TAIGA_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 1, 1, 0},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 9, 1, 12},
        {PoolType::TAIGA_ZSTREET, "street", BlockDirection::EAST, BlockDirection::UP, 15, 1, 14},
    };

    static const JigsawBlockEntry taiga_zombie_streets_corner_03[] = {
        {PoolType::TAIGA_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 1, 1, 3},
        {PoolType::TAIGA_ZSTREET, "street", BlockDirection::EAST, BlockDirection::UP, 3, 1, 1},
    };

    static const JigsawBlockEntry taiga_zombie_streets_crossroad_01[] = {
        {PoolType::TAIGA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 13, 0, 12},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 3},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 4},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 5},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 6},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 7},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 11},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 12},
        {PoolType::TAIGA_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 8, 1, 0},
        {PoolType::TAIGA_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 8, 1, 15},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 9, 1, 3},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 9, 1, 4},
        {PoolType::TAIGA_ZSTREET, "street", BlockDirection::EAST, BlockDirection::UP, 15, 1, 8},
    };

    static const JigsawBlockEntry taiga_zombie_streets_crossroad_02[] = {
        {PoolType::TAIGA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 5},
        {PoolType::TAIGA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 5, 0, 1},
        {PoolType::TAIGA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 11, 0, 5},
        {PoolType::TAIGA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 13, 0, 12},
        {PoolType::TAIGA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 14, 0, 2},
        {PoolType::TAIGA_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 8},
        {PoolType::TAIGA_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 8, 1, 0},
        {PoolType::TAIGA_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 8, 1, 15},
        {PoolType::TAIGA_ZSTREET, "street", BlockDirection::EAST, BlockDirection::UP, 15, 1, 8},
    };

    static const JigsawBlockEntry taiga_zombie_streets_crossroad_03[] = {
        {PoolType::TAIGA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 13},
        {PoolType::TAIGA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 0, 11},
        {PoolType::TAIGA_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 8},
        {PoolType::TAIGA_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 4, 1, 0},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::NORTH, BlockDirection::UP, 11, 1, 7},
        {PoolType::TAIGA_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 11, 1, 15},
        {PoolType::TAIGA_ZSTREET, "street", BlockDirection::EAST, BlockDirection::UP, 15, 1, 8},
    };

    static const JigsawBlockEntry taiga_zombie_streets_crossroad_04[] = {
        {PoolType::TAIGA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 2},
        {PoolType::TAIGA_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 2},
        {PoolType::TAIGA_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 2, 1, 0},
        {PoolType::TAIGA_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 2, 1, 4},
    };

    static const JigsawBlockEntry taiga_zombie_streets_crossroad_05[] = {
        {PoolType::TAIGA_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 2},
        {PoolType::TAIGA_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 2, 1, 0},
        {PoolType::TAIGA_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 2, 1, 4},
        {PoolType::TAIGA_ZSTREET, "street", BlockDirection::EAST, BlockDirection::UP, 4, 1, 2},
    };

    static const JigsawBlockEntry taiga_zombie_streets_crossroad_06[] = {
        {PoolType::TAIGA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 2},
        {PoolType::TAIGA_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 2},
        {PoolType::TAIGA_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 2, 1, 0},
        {PoolType::TAIGA_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 2, 1, 4},
        {PoolType::TAIGA_ZSTREET, "street", BlockDirection::EAST, BlockDirection::UP, 4, 1, 2},
    };

    static const JigsawBlockEntry taiga_zombie_streets_straight_01[] = {
        {PoolType::TAIGA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 0, 13},
        {PoolType::TAIGA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 4, 0, 7},
        {PoolType::TAIGA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 11, 0, 6},
        {PoolType::TAIGA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 11, 0, 13},
        {PoolType::TAIGA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 12, 0, 4},
        {PoolType::TAIGA_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 7, 1, 0},
        {PoolType::TAIGA_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 7, 1, 15},
    };

    static const JigsawBlockEntry taiga_zombie_streets_straight_02[] = {
        {PoolType::TAIGA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 2},
        {PoolType::TAIGA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 13},
        {PoolType::TAIGA_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 1, 1, 0},
        {PoolType::TAIGA_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 1, 1, 15},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 8},
    };

    static const JigsawBlockEntry taiga_zombie_streets_straight_03[] = {
        {PoolType::TAIGA_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 1, 1, 0},
        {PoolType::TAIGA_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 1, 1, 10},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 3},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 4},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 5},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 6},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 7},
    };

    static const JigsawBlockEntry taiga_zombie_streets_straight_04[] = {
        {PoolType::TAIGA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 0, 4},
        {PoolType::TAIGA_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 1, 1, 0},
        {PoolType::TAIGA_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 1, 1, 8},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 4},
    };

    static const JigsawBlockEntry taiga_zombie_streets_straight_05[] = {
        {PoolType::TAIGA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 3},
        {PoolType::TAIGA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 1, 0, 13},
        {PoolType::TAIGA_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 1, 1, 0},
        {PoolType::TAIGA_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 1, 1, 16},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 7},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 8},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 9},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 2, 1, 10},
    };

    static const JigsawBlockEntry taiga_zombie_streets_straight_06[] = {
        {PoolType::TAIGA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 0, 3},
        {PoolType::TAIGA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 9, 0, 9},
        {PoolType::TAIGA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 9, 0, 15},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 3},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 4},
        {PoolType::TAIGA_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 8, 1, 0},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 8, 1, 8},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 8, 1, 9},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 8, 1, 14},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 8, 1, 15},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 9, 1, 2},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 9, 1, 3},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 9, 1, 4},
        {PoolType::TAIGA_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 9, 1, 17},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 10, 1, 8},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 10, 1, 9},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 10, 1, 10},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 10, 1, 14},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 10, 1, 15},
    };

    static const JigsawBlockEntry taiga_zombie_streets_turn_01[] = {
        {PoolType::TAIGA_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 5, 1, 0},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::WEST, BlockDirection::UP, 7, 1, 6},
        {PoolType::TAIGA_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 8, 1, 7},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 9, 1, 4},
    };

    static const JigsawBlockEntry taiga_zombie_town_centers_taiga_meeting_point_1[] = {
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 3, 0, 3},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 5, 0, 3},
        {PoolType::TAIGA_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 1, 3},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 2, 1, 6},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 3, 1, 6},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 4, 1, 6},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 5, 1, 6},
        {PoolType::TAIGA_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 6, 1, 0},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 6, 1, 6},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::SOUTH, BlockDirection::UP, 7, 1, 6},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 11, 1, 3},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 11, 1, 4},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 11, 1, 5},
        {PoolType::TAIGA_ZHOUSES, "building_entrance", BlockDirection::EAST, BlockDirection::UP, 11, 1, 6},
    };

    static const JigsawBlockEntry taiga_zombie_town_centers_taiga_meeting_point_2[] = {
        {PoolType::TAIGA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 1, 0},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 0, 1, 6},
        {PoolType::CATS, "bottom", BlockDirection::UP, BlockDirection::NORTH, 2, 1, 0},
        {PoolType::TAIGA_ZDECOR, "bottom", BlockDirection::UP, BlockDirection::NORTH, 8, 1, 7},
        {PoolType::TAIGA_ZSTREET, "street", BlockDirection::WEST, BlockDirection::UP, 0, 2, 4},
        {PoolType::TAIGA_ZSTREET, "street", BlockDirection::NORTH, BlockDirection::UP, 4, 2, 0},
        {PoolType::TAIGA_ZSTREET, "street", BlockDirection::SOUTH, BlockDirection::UP, 4, 2, 8},
        {PoolType::TAIGA_ZSTREET, "street", BlockDirection::EAST, BlockDirection::UP, 8, 2, 4},
    };

    static const JigsawBlockEntry taiga_zombie_villagers_nitwit[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

    static const JigsawBlockEntry taiga_zombie_villagers_unemployed[] = {
        {PoolType::EMPTY, "bottom", BlockDirection::DOWN, BlockDirection::SOUTH, 0, 0, 0},
    };

} // namespace

// Fonction pour obtenir les JigsawBlocks d'un template
inline std::vector<JigsawBlockEntry> getTaigaVillageJigsawBlocks(const std::string& templateName) {
    using namespace TaigaVillageJigsawData;
    
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
        {"taiga/houses/taiga_animal_pen_1", {taiga_houses_taiga_animal_pen_1, 3}},
        {"taiga/houses/taiga_armorer_2", {taiga_houses_taiga_armorer_2, 3}},
        {"taiga/houses/taiga_armorer_house_1", {taiga_houses_taiga_armorer_house_1, 1}},
        {"taiga/houses/taiga_butcher_shop_1", {taiga_houses_taiga_butcher_shop_1, 2}},
        {"taiga/houses/taiga_cartographer_house_1", {taiga_houses_taiga_cartographer_house_1, 2}},
        {"taiga/houses/taiga_fisher_cottage_1", {taiga_houses_taiga_fisher_cottage_1, 5}},
        {"taiga/houses/taiga_fletcher_house_1", {taiga_houses_taiga_fletcher_house_1, 1}},
        {"taiga/houses/taiga_large_farm_1", {taiga_houses_taiga_large_farm_1, 2}},
        {"taiga/houses/taiga_large_farm_2", {taiga_houses_taiga_large_farm_2, 2}},
        {"taiga/houses/taiga_library_1", {taiga_houses_taiga_library_1, 4}},
        {"taiga/houses/taiga_masons_house_1", {taiga_houses_taiga_masons_house_1, 1}},
        {"taiga/houses/taiga_medium_house_1", {taiga_houses_taiga_medium_house_1, 3}},
        {"taiga/houses/taiga_medium_house_2", {taiga_houses_taiga_medium_house_2, 3}},
        {"taiga/houses/taiga_medium_house_3", {taiga_houses_taiga_medium_house_3, 5}},
        {"taiga/houses/taiga_medium_house_4", {taiga_houses_taiga_medium_house_4, 3}},
        {"taiga/houses/taiga_shepherds_house_1", {taiga_houses_taiga_shepherds_house_1, 3}},
        {"taiga/houses/taiga_small_farm_1", {taiga_houses_taiga_small_farm_1, 2}},
        {"taiga/houses/taiga_small_house_1", {taiga_houses_taiga_small_house_1, 2}},
        {"taiga/houses/taiga_small_house_2", {taiga_houses_taiga_small_house_2, 2}},
        {"taiga/houses/taiga_small_house_3", {taiga_houses_taiga_small_house_3, 2}},
        {"taiga/houses/taiga_small_house_4", {taiga_houses_taiga_small_house_4, 3}},
        {"taiga/houses/taiga_small_house_5", {taiga_houses_taiga_small_house_5, 2}},
        {"taiga/houses/taiga_tannery_1", {taiga_houses_taiga_tannery_1, 1}},
        {"taiga/houses/taiga_temple_1", {taiga_houses_taiga_temple_1, 1}},
        {"taiga/houses/taiga_tool_smith_1", {taiga_houses_taiga_tool_smith_1, 3}},
        {"taiga/houses/taiga_weaponsmith_1", {taiga_houses_taiga_weaponsmith_1, 1}},
        {"taiga/houses/taiga_weaponsmith_2", {taiga_houses_taiga_weaponsmith_2, 2}},
        {"taiga/patch_berry_bush", {taiga_patch_berry_bush, 1}},
        {"taiga/patch_taiga_grass", {taiga_patch_taiga_grass, 1}},
        {"taiga/pile_pumpkin", {taiga_pile_pumpkin, 1}},
        {"taiga/pine", {taiga_pine, 1}},
        {"taiga/spruce", {taiga_spruce, 1}},
        {"taiga/streets/corner_01", {taiga_streets_corner_01, 8}},
        {"taiga/streets/corner_02", {taiga_streets_corner_02, 5}},
        {"taiga/streets/corner_03", {taiga_streets_corner_03, 2}},
        {"taiga/streets/crossroad_01", {taiga_streets_crossroad_01, 13}},
        {"taiga/streets/crossroad_02", {taiga_streets_crossroad_02, 9}},
        {"taiga/streets/crossroad_03", {taiga_streets_crossroad_03, 7}},
        {"taiga/streets/crossroad_04", {taiga_streets_crossroad_04, 4}},
        {"taiga/streets/crossroad_05", {taiga_streets_crossroad_05, 4}},
        {"taiga/streets/crossroad_06", {taiga_streets_crossroad_06, 5}},
        {"taiga/streets/straight_01", {taiga_streets_straight_01, 7}},
        {"taiga/streets/straight_02", {taiga_streets_straight_02, 5}},
        {"taiga/streets/straight_03", {taiga_streets_straight_03, 7}},
        {"taiga/streets/straight_04", {taiga_streets_straight_04, 4}},
        {"taiga/streets/straight_05", {taiga_streets_straight_05, 8}},
        {"taiga/streets/straight_06", {taiga_streets_straight_06, 19}},
        {"taiga/streets/turn_01", {taiga_streets_turn_01, 4}},
        {"taiga/taiga_decoration_1", {taiga_taiga_decoration_1, 1}},
        {"taiga/taiga_decoration_2", {taiga_taiga_decoration_2, 1}},
        {"taiga/taiga_decoration_3", {taiga_taiga_decoration_3, 1}},
        {"taiga/taiga_decoration_4", {taiga_taiga_decoration_4, 1}},
        {"taiga/taiga_decoration_5", {taiga_taiga_decoration_5, 1}},
        {"taiga/taiga_decoration_6", {taiga_taiga_decoration_6, 1}},
        {"taiga/taiga_lamp_post_1", {taiga_taiga_lamp_post_1, 1}},
        {"taiga/town_centers/taiga_meeting_point_1", {taiga_town_centers_taiga_meeting_point_1, 18}},
        {"taiga/town_centers/taiga_meeting_point_2", {taiga_town_centers_taiga_meeting_point_2, 12}},
        {"taiga/villagers/baby", {taiga_villagers_baby, 1}},
        {"taiga/villagers/nitwit", {taiga_villagers_nitwit, 1}},
        {"taiga/villagers/unemployed", {taiga_villagers_unemployed, 1}},
        {"taiga/zombie/houses/taiga_cartographer_house_1", {taiga_zombie_houses_taiga_cartographer_house_1, 2}},
        {"taiga/zombie/houses/taiga_fisher_cottage_1", {taiga_zombie_houses_taiga_fisher_cottage_1, 5}},
        {"taiga/zombie/houses/taiga_large_farm_2", {taiga_zombie_houses_taiga_large_farm_2, 2}},
        {"taiga/zombie/houses/taiga_library_1", {taiga_zombie_houses_taiga_library_1, 4}},
        {"taiga/zombie/houses/taiga_medium_house_1", {taiga_zombie_houses_taiga_medium_house_1, 2}},
        {"taiga/zombie/houses/taiga_medium_house_2", {taiga_zombie_houses_taiga_medium_house_2, 3}},
        {"taiga/zombie/houses/taiga_medium_house_3", {taiga_zombie_houses_taiga_medium_house_3, 3}},
        {"taiga/zombie/houses/taiga_medium_house_4", {taiga_zombie_houses_taiga_medium_house_4, 1}},
        {"taiga/zombie/houses/taiga_shepherds_house_1", {taiga_zombie_houses_taiga_shepherds_house_1, 3}},
        {"taiga/zombie/houses/taiga_small_house_1", {taiga_zombie_houses_taiga_small_house_1, 2}},
        {"taiga/zombie/houses/taiga_small_house_2", {taiga_zombie_houses_taiga_small_house_2, 2}},
        {"taiga/zombie/houses/taiga_small_house_3", {taiga_zombie_houses_taiga_small_house_3, 2}},
        {"taiga/zombie/houses/taiga_small_house_4", {taiga_zombie_houses_taiga_small_house_4, 3}},
        {"taiga/zombie/houses/taiga_small_house_5", {taiga_zombie_houses_taiga_small_house_5, 2}},
        {"taiga/zombie/houses/taiga_temple_1", {taiga_zombie_houses_taiga_temple_1, 1}},
        {"taiga/zombie/houses/taiga_tool_smith_1", {taiga_zombie_houses_taiga_tool_smith_1, 3}},
        {"taiga/zombie/houses/taiga_weaponsmith_2", {taiga_zombie_houses_taiga_weaponsmith_2, 2}},
        {"taiga/zombie/streets/corner_01", {taiga_zombie_streets_corner_01, 8}},
        {"taiga/zombie/streets/corner_02", {taiga_zombie_streets_corner_02, 5}},
        {"taiga/zombie/streets/corner_03", {taiga_zombie_streets_corner_03, 2}},
        {"taiga/zombie/streets/crossroad_01", {taiga_zombie_streets_crossroad_01, 13}},
        {"taiga/zombie/streets/crossroad_02", {taiga_zombie_streets_crossroad_02, 9}},
        {"taiga/zombie/streets/crossroad_03", {taiga_zombie_streets_crossroad_03, 7}},
        {"taiga/zombie/streets/crossroad_04", {taiga_zombie_streets_crossroad_04, 4}},
        {"taiga/zombie/streets/crossroad_05", {taiga_zombie_streets_crossroad_05, 4}},
        {"taiga/zombie/streets/crossroad_06", {taiga_zombie_streets_crossroad_06, 5}},
        {"taiga/zombie/streets/straight_01", {taiga_zombie_streets_straight_01, 7}},
        {"taiga/zombie/streets/straight_02", {taiga_zombie_streets_straight_02, 5}},
        {"taiga/zombie/streets/straight_03", {taiga_zombie_streets_straight_03, 7}},
        {"taiga/zombie/streets/straight_04", {taiga_zombie_streets_straight_04, 4}},
        {"taiga/zombie/streets/straight_05", {taiga_zombie_streets_straight_05, 8}},
        {"taiga/zombie/streets/straight_06", {taiga_zombie_streets_straight_06, 19}},
        {"taiga/zombie/streets/turn_01", {taiga_zombie_streets_turn_01, 4}},
        {"taiga/zombie/town_centers/taiga_meeting_point_1", {taiga_zombie_town_centers_taiga_meeting_point_1, 14}},
        {"taiga/zombie/town_centers/taiga_meeting_point_2", {taiga_zombie_town_centers_taiga_meeting_point_2, 8}},
        {"taiga/zombie/villagers/nitwit", {taiga_zombie_villagers_nitwit, 1}},
        {"taiga/zombie/villagers/unemployed", {taiga_zombie_villagers_unemployed, 1}},
    };
    
    auto it = LOOKUP.find(templateName);
    if (it != LOOKUP.end()) {
        return std::vector<JigsawBlockEntry>(it->second.first, it->second.first + it->second.second);
    }
    return {};
}

// Version sans allocation (plus rapide)
inline bool getTaigaVillageJigsawBlocksFast(const std::string& templateName, const JigsawBlockEntry*& out, size_t& count) {
    using namespace TaigaVillageJigsawData;
    
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
        {"taiga/houses/taiga_animal_pen_1", {taiga_houses_taiga_animal_pen_1, 3}},
        {"taiga/houses/taiga_armorer_2", {taiga_houses_taiga_armorer_2, 3}},
        {"taiga/houses/taiga_armorer_house_1", {taiga_houses_taiga_armorer_house_1, 1}},
        {"taiga/houses/taiga_butcher_shop_1", {taiga_houses_taiga_butcher_shop_1, 2}},
        {"taiga/houses/taiga_cartographer_house_1", {taiga_houses_taiga_cartographer_house_1, 2}},
        {"taiga/houses/taiga_fisher_cottage_1", {taiga_houses_taiga_fisher_cottage_1, 5}},
        {"taiga/houses/taiga_fletcher_house_1", {taiga_houses_taiga_fletcher_house_1, 1}},
        {"taiga/houses/taiga_large_farm_1", {taiga_houses_taiga_large_farm_1, 2}},
        {"taiga/houses/taiga_large_farm_2", {taiga_houses_taiga_large_farm_2, 2}},
        {"taiga/houses/taiga_library_1", {taiga_houses_taiga_library_1, 4}},
        {"taiga/houses/taiga_masons_house_1", {taiga_houses_taiga_masons_house_1, 1}},
        {"taiga/houses/taiga_medium_house_1", {taiga_houses_taiga_medium_house_1, 3}},
        {"taiga/houses/taiga_medium_house_2", {taiga_houses_taiga_medium_house_2, 3}},
        {"taiga/houses/taiga_medium_house_3", {taiga_houses_taiga_medium_house_3, 5}},
        {"taiga/houses/taiga_medium_house_4", {taiga_houses_taiga_medium_house_4, 3}},
        {"taiga/houses/taiga_shepherds_house_1", {taiga_houses_taiga_shepherds_house_1, 3}},
        {"taiga/houses/taiga_small_farm_1", {taiga_houses_taiga_small_farm_1, 2}},
        {"taiga/houses/taiga_small_house_1", {taiga_houses_taiga_small_house_1, 2}},
        {"taiga/houses/taiga_small_house_2", {taiga_houses_taiga_small_house_2, 2}},
        {"taiga/houses/taiga_small_house_3", {taiga_houses_taiga_small_house_3, 2}},
        {"taiga/houses/taiga_small_house_4", {taiga_houses_taiga_small_house_4, 3}},
        {"taiga/houses/taiga_small_house_5", {taiga_houses_taiga_small_house_5, 2}},
        {"taiga/houses/taiga_tannery_1", {taiga_houses_taiga_tannery_1, 1}},
        {"taiga/houses/taiga_temple_1", {taiga_houses_taiga_temple_1, 1}},
        {"taiga/houses/taiga_tool_smith_1", {taiga_houses_taiga_tool_smith_1, 3}},
        {"taiga/houses/taiga_weaponsmith_1", {taiga_houses_taiga_weaponsmith_1, 1}},
        {"taiga/houses/taiga_weaponsmith_2", {taiga_houses_taiga_weaponsmith_2, 2}},
        {"taiga/patch_berry_bush", {taiga_patch_berry_bush, 1}},
        {"taiga/patch_taiga_grass", {taiga_patch_taiga_grass, 1}},
        {"taiga/pile_pumpkin", {taiga_pile_pumpkin, 1}},
        {"taiga/pine", {taiga_pine, 1}},
        {"taiga/spruce", {taiga_spruce, 1}},
        {"taiga/streets/corner_01", {taiga_streets_corner_01, 8}},
        {"taiga/streets/corner_02", {taiga_streets_corner_02, 5}},
        {"taiga/streets/corner_03", {taiga_streets_corner_03, 2}},
        {"taiga/streets/crossroad_01", {taiga_streets_crossroad_01, 13}},
        {"taiga/streets/crossroad_02", {taiga_streets_crossroad_02, 9}},
        {"taiga/streets/crossroad_03", {taiga_streets_crossroad_03, 7}},
        {"taiga/streets/crossroad_04", {taiga_streets_crossroad_04, 4}},
        {"taiga/streets/crossroad_05", {taiga_streets_crossroad_05, 4}},
        {"taiga/streets/crossroad_06", {taiga_streets_crossroad_06, 5}},
        {"taiga/streets/straight_01", {taiga_streets_straight_01, 7}},
        {"taiga/streets/straight_02", {taiga_streets_straight_02, 5}},
        {"taiga/streets/straight_03", {taiga_streets_straight_03, 7}},
        {"taiga/streets/straight_04", {taiga_streets_straight_04, 4}},
        {"taiga/streets/straight_05", {taiga_streets_straight_05, 8}},
        {"taiga/streets/straight_06", {taiga_streets_straight_06, 19}},
        {"taiga/streets/turn_01", {taiga_streets_turn_01, 4}},
        {"taiga/taiga_decoration_1", {taiga_taiga_decoration_1, 1}},
        {"taiga/taiga_decoration_2", {taiga_taiga_decoration_2, 1}},
        {"taiga/taiga_decoration_3", {taiga_taiga_decoration_3, 1}},
        {"taiga/taiga_decoration_4", {taiga_taiga_decoration_4, 1}},
        {"taiga/taiga_decoration_5", {taiga_taiga_decoration_5, 1}},
        {"taiga/taiga_decoration_6", {taiga_taiga_decoration_6, 1}},
        {"taiga/taiga_lamp_post_1", {taiga_taiga_lamp_post_1, 1}},
        {"taiga/town_centers/taiga_meeting_point_1", {taiga_town_centers_taiga_meeting_point_1, 18}},
        {"taiga/town_centers/taiga_meeting_point_2", {taiga_town_centers_taiga_meeting_point_2, 12}},
        {"taiga/villagers/baby", {taiga_villagers_baby, 1}},
        {"taiga/villagers/nitwit", {taiga_villagers_nitwit, 1}},
        {"taiga/villagers/unemployed", {taiga_villagers_unemployed, 1}},
        {"taiga/zombie/houses/taiga_cartographer_house_1", {taiga_zombie_houses_taiga_cartographer_house_1, 2}},
        {"taiga/zombie/houses/taiga_fisher_cottage_1", {taiga_zombie_houses_taiga_fisher_cottage_1, 5}},
        {"taiga/zombie/houses/taiga_large_farm_2", {taiga_zombie_houses_taiga_large_farm_2, 2}},
        {"taiga/zombie/houses/taiga_library_1", {taiga_zombie_houses_taiga_library_1, 4}},
        {"taiga/zombie/houses/taiga_medium_house_1", {taiga_zombie_houses_taiga_medium_house_1, 2}},
        {"taiga/zombie/houses/taiga_medium_house_2", {taiga_zombie_houses_taiga_medium_house_2, 3}},
        {"taiga/zombie/houses/taiga_medium_house_3", {taiga_zombie_houses_taiga_medium_house_3, 3}},
        {"taiga/zombie/houses/taiga_medium_house_4", {taiga_zombie_houses_taiga_medium_house_4, 1}},
        {"taiga/zombie/houses/taiga_shepherds_house_1", {taiga_zombie_houses_taiga_shepherds_house_1, 3}},
        {"taiga/zombie/houses/taiga_small_house_1", {taiga_zombie_houses_taiga_small_house_1, 2}},
        {"taiga/zombie/houses/taiga_small_house_2", {taiga_zombie_houses_taiga_small_house_2, 2}},
        {"taiga/zombie/houses/taiga_small_house_3", {taiga_zombie_houses_taiga_small_house_3, 2}},
        {"taiga/zombie/houses/taiga_small_house_4", {taiga_zombie_houses_taiga_small_house_4, 3}},
        {"taiga/zombie/houses/taiga_small_house_5", {taiga_zombie_houses_taiga_small_house_5, 2}},
        {"taiga/zombie/houses/taiga_temple_1", {taiga_zombie_houses_taiga_temple_1, 1}},
        {"taiga/zombie/houses/taiga_tool_smith_1", {taiga_zombie_houses_taiga_tool_smith_1, 3}},
        {"taiga/zombie/houses/taiga_weaponsmith_2", {taiga_zombie_houses_taiga_weaponsmith_2, 2}},
        {"taiga/zombie/streets/corner_01", {taiga_zombie_streets_corner_01, 8}},
        {"taiga/zombie/streets/corner_02", {taiga_zombie_streets_corner_02, 5}},
        {"taiga/zombie/streets/corner_03", {taiga_zombie_streets_corner_03, 2}},
        {"taiga/zombie/streets/crossroad_01", {taiga_zombie_streets_crossroad_01, 13}},
        {"taiga/zombie/streets/crossroad_02", {taiga_zombie_streets_crossroad_02, 9}},
        {"taiga/zombie/streets/crossroad_03", {taiga_zombie_streets_crossroad_03, 7}},
        {"taiga/zombie/streets/crossroad_04", {taiga_zombie_streets_crossroad_04, 4}},
        {"taiga/zombie/streets/crossroad_05", {taiga_zombie_streets_crossroad_05, 4}},
        {"taiga/zombie/streets/crossroad_06", {taiga_zombie_streets_crossroad_06, 5}},
        {"taiga/zombie/streets/straight_01", {taiga_zombie_streets_straight_01, 7}},
        {"taiga/zombie/streets/straight_02", {taiga_zombie_streets_straight_02, 5}},
        {"taiga/zombie/streets/straight_03", {taiga_zombie_streets_straight_03, 7}},
        {"taiga/zombie/streets/straight_04", {taiga_zombie_streets_straight_04, 4}},
        {"taiga/zombie/streets/straight_05", {taiga_zombie_streets_straight_05, 8}},
        {"taiga/zombie/streets/straight_06", {taiga_zombie_streets_straight_06, 19}},
        {"taiga/zombie/streets/turn_01", {taiga_zombie_streets_turn_01, 4}},
        {"taiga/zombie/town_centers/taiga_meeting_point_1", {taiga_zombie_town_centers_taiga_meeting_point_1, 14}},
        {"taiga/zombie/town_centers/taiga_meeting_point_2", {taiga_zombie_town_centers_taiga_meeting_point_2, 8}},
        {"taiga/zombie/villagers/nitwit", {taiga_zombie_villagers_nitwit, 1}},
        {"taiga/zombie/villagers/unemployed", {taiga_zombie_villagers_unemployed, 1}},
    };
    
    auto it = LOOKUP.find(templateName);
    if (it != LOOKUP.end()) {
        out = it->second.first;
        count = it->second.second;
        return true;
    }
    return false;
}
