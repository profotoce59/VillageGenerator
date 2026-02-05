#pragma once

#include "VillageGenerator.hpp"

// Mirror of Java VillagePoolYMax.Y_MAX
inline int getPoolYMax(PoolType type) {
    switch (type) {
        case PoolType::ANIMALS: return 3;
        case PoolType::SHEEPS: return 3;
        case PoolType::CATS: return 3;
        case PoolType::BUTCHER_ANIMAL: return 3;
        case PoolType::IRON_GOLEM: return 3;
        case PoolType::WELL_BOTTOM: return 3;

        case PoolType::PLAIN_CENTER: return 9;
        case PoolType::PLAIN_STREET: return 2;
        case PoolType::PLAIN_ZSTREET: return 2;
        case PoolType::PLAIN_HOUSES: return 12;
        case PoolType::PLAIN_ZHOUSES: return 12;
        case PoolType::PLAIN_DECOR: return 4;
        case PoolType::PLAIN_ZDECOR: return 4;
        case PoolType::PLAIN_VILLAGER: return 3;
        case PoolType::PLAIN_ZVILLAGER: return 3;
        case PoolType::PLAIN_TERMINATOR: return 2;
        case PoolType::PLAIN_TREE: return 0;

        case PoolType::DESERT_CENTER: return 6;
        case PoolType::DESERT_STREET: return 2;
        case PoolType::DESERT_ZSTREET: return 2;
        case PoolType::DESERT_HOUSES: return 18;
        case PoolType::DESERT_ZHOUSES: return 17;
        case PoolType::DESERT_TERMINATOR: return 2;
        case PoolType::DESERT_ZTERMINATOR: return 2;
        case PoolType::DESERT_DECOR: return 4;
        case PoolType::DESERT_ZDECOR: return 4;
        case PoolType::DESERT_VILLAGER: return 3;
        case PoolType::DESERT_ZVILLAGER: return 3;

        case PoolType::EMPTY: return 0;

        case PoolType::TAIGA_TERMINATOR: return 2;
        case PoolType::TAIGA_CENTER: return 7;
        case PoolType::TAIGA_STREET: return 2;
        case PoolType::TAIGA_ZSTREET: return 2;
        case PoolType::TAIGA_HOUSES: return 14;
        case PoolType::TAIGA_ZHOUSES: return 14;
        case PoolType::TAIGA_DECOR: return 2;
        case PoolType::TAIGA_ZDECOR: return 2;
        case PoolType::TAIGA_VILLAGER: return 3;
        case PoolType::TAIGA_ZVILLAGER: return 3;

        case PoolType::SAVANNA_TERMINATOR: return 2;
        case PoolType::SAVANNA_ZTERMINATOR: return 2;
        case PoolType::SAVANNA_CENTER: return 6;
        case PoolType::SAVANNA_STREET: return 2;
        case PoolType::SAVANNA_ZSTREET: return 2;
        case PoolType::SAVANNA_HOUSES: return 14;
        case PoolType::SAVANNA_ZHOUSES: return 10;
        case PoolType::SAVANNA_DECOR: return 2;
        case PoolType::SAVANNA_ZDECOR: return 2;
        case PoolType::SAVANNA_VILLAGER: return 3;
        case PoolType::SAVANNA_ZVILLAGER: return 3;
        case PoolType::SAVANNA_TREE: return 1;

        case PoolType::SNOWY_TERMINATOR: return 2;
        case PoolType::SNOWY_CENTER: return 8;
        case PoolType::SNOWY_STREET: return 2;
        case PoolType::SNOWY_ZSTREET: return 2;
        case PoolType::SNOWY_HOUSES: return 14;
        case PoolType::SNOWY_ZHOUSES: return 9;
        case PoolType::SNOWY_DECOR: return 4;
        case PoolType::SNOWY_ZDECOR: return 4;
        case PoolType::SNOWY_VILLAGER: return 3;
        case PoolType::SNOWY_ZVILLAGER: return 3;
        case PoolType::SNOWY_TREE: return 0;
    }
    return 0;
}
