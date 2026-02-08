#pragma once

#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <utility>
#include <random>
#include "VillageGenerator.hpp"
#include "JigSawPool.hpp"

// hasher pour enum class (si tu utilises std::unordered_map<VillageType,...>)
struct EnumClassHash {
  template <class E>
  size_t operator()(E e) const {
    using U = std::underlying_type_t<E>;
    return std::hash<U>{}(static_cast<U>(e));
  }
};

// Déclaration (PAS de définition ici)
extern const std::unordered_map<VillageType, JigSawPool, EnumClassHash> STARTS;

// Classe de base pour tous les pools
class VillagePool {
public:
    virtual ~VillagePool() = default;
    virtual std::vector<TemplateEntry> getTemplates(PoolType type) const = 0;
    virtual PlacementBehaviour getPlacementBehaviour() const = 0;
    virtual PlacementBehaviour getPlacementBehaviour(PoolType type) const {
        (void)type;
        return PlacementBehaviour::RIGID;
    }
};

static inline std::vector<TemplateEntry> getCommonTemplates(PoolType type) {
    switch (type) {
        case PoolType::ANIMALS:
            return {
                {"common/animals/cows_1", 7},
                {"common/animals/pigs_1", 7},
                {"common/animals/horses_1", 1},
                {"common/animals/horses_2", 1},
                {"common/animals/horses_3", 1},
                {"common/animals/horses_4", 1},
                {"common/animals/horses_5", 1},
                {"common/animals/sheep_1", 1},
                {"common/animals/sheep_2", 1},
                {"empty", 5}
            };
        case PoolType::SHEEPS:
            return {
                {"common/animals/sheep_1", 1},
                {"common/animals/sheep_2", 1}
            };
        case PoolType::CATS:
            return {
                {"common/animals/cat_black", 1},
                {"common/animals/cat_british", 1},
                {"common/animals/cat_calico", 1},
                {"common/animals/cat_persian", 1},
                {"common/animals/cat_ragdoll", 1},
                {"common/animals/cat_red", 1},
                {"common/animals/cat_siamese", 1},
                {"common/animals/cat_tabby", 1},
                {"common/animals/cat_white", 1},
                {"common/animals/cat_jellie", 1},
                {"empty", 3}
            };
        case PoolType::BUTCHER_ANIMAL:
            return {
                {"common/animals/cows_1", 3},
                {"common/animals/pigs_1", 3},
                {"common/animals/sheep_1", 1},
                {"common/animals/sheep_2", 1}
            };
        case PoolType::IRON_GOLEM:
            return {{"common/iron_golem", 1}};
        case PoolType::WELL_BOTTOM:
            return {{"common/well_bottom", 1}};
        case PoolType::EMPTY:
            return {{"empty", 0}};
        default:
            return {};
    }
}

// Pool pour les villages du désert - matching Java DesertPool.java
class DesertPool : public VillagePool {
public:
    std::vector<TemplateEntry> getTemplates(PoolType type) const override {
        switch (type) {
            case PoolType::DESERT_CENTER:
                return {
                    {"desert/town_centers/desert_meeting_point_1", 98},
                    {"desert/town_centers/desert_meeting_point_2", 98},
                    {"desert/town_centers/desert_meeting_point_3", 49},
                    {"desert/zombie/town_centers/desert_meeting_point_1", 2},
                    {"desert/zombie/town_centers/desert_meeting_point_2", 2},
                    {"desert/zombie/town_centers/desert_meeting_point_3", 1}
                };
            case PoolType::DESERT_HOUSES:
                return {
                    {"desert/houses/desert_small_house_1", 2},
                    {"desert/houses/desert_small_house_2", 2},
                    {"desert/houses/desert_small_house_3", 2},
                    {"desert/houses/desert_small_house_4", 2},
                    {"desert/houses/desert_small_house_5", 2},
                    {"desert/houses/desert_small_house_6", 1},
                    {"desert/houses/desert_small_house_7", 2},
                    {"desert/houses/desert_small_house_8", 2},
                    {"desert/houses/desert_medium_house_1", 2},
                    {"desert/houses/desert_medium_house_2", 2},
                    {"desert/houses/desert_butcher_shop_1", 2},
                    {"desert/houses/desert_tool_smith_1", 2},
                    {"desert/houses/desert_fletcher_house_1", 2},
                    {"desert/houses/desert_shepherd_house_1", 2},
                    {"desert/houses/desert_armorer_1", 1},
                    {"desert/houses/desert_fisher_1", 2},
                    {"desert/houses/desert_tannery_1", 2},
                    {"desert/houses/desert_cartographer_house_1", 2},
                    {"desert/houses/desert_library_1", 2},
                    {"desert/houses/desert_mason_1", 2},
                    {"desert/houses/desert_weaponsmith_1", 2},
                    {"desert/houses/desert_temple_1", 2},
                    {"desert/houses/desert_temple_2", 2},
                    {"desert/houses/desert_large_farm_1", 11},
                    {"desert/houses/desert_farm_1", 4},
                    {"desert/houses/desert_farm_2", 4},
                    {"desert/houses/desert_animal_pen_1", 2},
                    {"desert/houses/desert_animal_pen_2", 2},
                    {"empty", 5}
                };
            case PoolType::DESERT_ZHOUSES:
                return {
                    {"desert/zombie/houses/desert_small_house_1", 2},
                    {"desert/zombie/houses/desert_small_house_2", 2},
                    {"desert/zombie/houses/desert_small_house_3", 2},
                    {"desert/zombie/houses/desert_small_house_4", 2},
                    {"desert/zombie/houses/desert_small_house_5", 2},
                    {"desert/zombie/houses/desert_small_house_6", 1},
                    {"desert/zombie/houses/desert_small_house_7", 2},
                    {"desert/zombie/houses/desert_small_house_8", 2},
                    {"desert/zombie/houses/desert_medium_house_1", 2},
                    {"desert/zombie/houses/desert_medium_house_2", 2},
                    {"desert/houses/desert_butcher_shop_1", 2},
                    {"desert/houses/desert_tool_smith_1", 2},
                    {"desert/houses/desert_fletcher_house_1", 2},
                    {"desert/houses/desert_shepherd_house_1", 2},
                    {"desert/houses/desert_armorer_1", 1},
                    {"desert/houses/desert_fisher_1", 2},
                    {"desert/houses/desert_tannery_1", 2},
                    {"desert/houses/desert_cartographer_house_1", 2},
                    {"desert/houses/desert_library_1", 2},
                    {"desert/houses/desert_mason_1", 2},
                    {"desert/houses/desert_weaponsmith_1", 2},
                    {"desert/houses/desert_temple_1", 2},
                    {"desert/houses/desert_temple_2", 2},
                    {"desert/houses/desert_large_farm_1", 7},
                    {"desert/houses/desert_farm_1", 4},
                    {"desert/houses/desert_farm_2", 4},
                    {"desert/houses/desert_animal_pen_1", 2},
                    {"desert/houses/desert_animal_pen_2", 2},
                    {"empty", 5}
                };
            case PoolType::DESERT_STREET:
                return {
                    {"desert/streets/corner_01", 3},
                    {"desert/streets/corner_02", 3},
                    {"desert/streets/straight_01", 4},
                    {"desert/streets/straight_02", 4},
                    {"desert/streets/straight_03", 3},
                    {"desert/streets/crossroad_01", 3},
                    {"desert/streets/crossroad_02", 3},
                    {"desert/streets/crossroad_03", 3},
                    {"desert/streets/square_01", 3},
                    {"desert/streets/square_02", 3},
                    {"desert/streets/turn_01", 3}
                };
            case PoolType::DESERT_ZSTREET:
                return {
                    {"desert/zombie/streets/corner_01", 3},
                    {"desert/zombie/streets/corner_02", 3},
                    {"desert/zombie/streets/straight_01", 4},
                    {"desert/zombie/streets/straight_02", 4},
                    {"desert/zombie/streets/straight_03", 3},
                    {"desert/zombie/streets/crossroad_01", 3},
                    {"desert/zombie/streets/crossroad_02", 3},
                    {"desert/zombie/streets/crossroad_03", 3},
                    {"desert/zombie/streets/square_01", 3},
                    {"desert/zombie/streets/square_02", 3},
                    {"desert/zombie/streets/turn_01", 3}
                };
            case PoolType::DESERT_DECOR:
                return {
                    {"desert/desert_lamp_1", 10},
                    {"patch_cactus", 4},
                    {"pile_hay", 4},
                    {"empty", 10}
                };
            case PoolType::DESERT_ZDECOR:
                return {
                    {"desert/desert_lamp_1", 10},
                    {"patch_cactus", 4},
                    {"pile_hay", 4},
                    {"empty", 10}
                };
            case PoolType::DESERT_TERMINATOR:
                return {
                    {"desert/terminators/terminator_01", 1},
                    {"desert/terminators/terminator_02", 1}
                };
            case PoolType::DESERT_VILLAGER:
                return {
                    {"desert/villagers/nitwit", 1},
                    {"desert/villagers/baby", 1},
                    {"desert/villagers/unemployed", 10}
                };
            case PoolType::DESERT_ZVILLAGER:
                return {
                    {"desert/zombie/villagers/nitwit", 1},
                    {"desert/zombie/villagers/unemployed", 10}
                };
            case PoolType::DESERT_ZTERMINATOR:
                return {
                    {"desert/terminators/terminator_01", 1},
                    {"desert/zombie/terminators/terminator_02", 1}
                };
            default:
                return getCommonTemplates(type);
        }
    }

    PlacementBehaviour getPlacementBehaviour() const override {
        return PlacementBehaviour::RIGID;
    }

    PlacementBehaviour getPlacementBehaviour(PoolType type) const override {
        if (type == PoolType::DESERT_STREET || type == PoolType::DESERT_ZSTREET ||
            type == PoolType::DESERT_TERMINATOR || type == PoolType::DESERT_ZTERMINATOR)
            return PlacementBehaviour::TERRAIN_MATCHING;
        return PlacementBehaviour::RIGID;
    }
};

// Pool pour les villages des plaines
class PlainsPool : public VillagePool {
public:
    std::vector<TemplateEntry> getTemplates(PoolType type) const override {
        switch (type) {
            case PoolType::PLAIN_CENTER:
                return {
                    {"plains/town_centers/plains_fountain_01", 50},
                    {"plains/town_centers/plains_meeting_point_1", 50},
                    {"plains/town_centers/plains_meeting_point_2", 50},
                    {"plains/town_centers/plains_meeting_point_3", 50},
                    {"plains/zombie/town_centers/plains_fountain_01", 1},
                    {"plains/zombie/town_centers/plains_meeting_point_1", 1},
                    {"plains/zombie/town_centers/plains_meeting_point_2", 1},
                    {"plains/zombie/town_centers/plains_meeting_point_3", 1}
                };
            case PoolType::PLAIN_HOUSES:
                return {
                    {"plains/houses/plains_small_house_1", 2},
                    {"plains/houses/plains_small_house_2", 2},
                    {"plains/houses/plains_small_house_3", 2},
                    {"plains/houses/plains_small_house_4", 2},
                    {"plains/houses/plains_small_house_5", 2},
                    {"plains/houses/plains_small_house_6", 1},
                    {"plains/houses/plains_small_house_7", 2},
                    {"plains/houses/plains_small_house_8", 3},
                    {"plains/houses/plains_medium_house_1", 2},
                    {"plains/houses/plains_medium_house_2", 2},
                    {"plains/houses/plains_big_house_1", 2},
                    {"plains/houses/plains_butcher_shop_1", 2},
                    {"plains/houses/plains_butcher_shop_2", 2},
                    {"plains/houses/plains_tool_smith_1", 2},
                    {"plains/houses/plains_fletcher_house_1", 2},
                    {"plains/houses/plains_shepherds_house_1", 2},
                    {"plains/houses/plains_armorer_house_1", 2},
                    {"plains/houses/plains_fisher_cottage_1", 2},
                    {"plains/houses/plains_tannery_1", 2},
                    {"plains/houses/plains_cartographer_1", 1},
                    {"plains/houses/plains_library_1", 5},
                    {"plains/houses/plains_library_2", 1},
                    {"plains/houses/plains_masons_house_1", 2},
                    {"plains/houses/plains_weaponsmith_1", 2},
                    {"plains/houses/plains_temple_3", 2},
                    {"plains/houses/plains_temple_4", 2},
                    {"plains/houses/plains_stable_1", 2},
                    {"plains/houses/plains_stable_2", 2},
                    {"plains/houses/plains_large_farm_1", 4},
                    {"plains/houses/plains_small_farm_1", 4},
                    {"plains/houses/plains_animal_pen_1", 1},
                    {"plains/houses/plains_animal_pen_2", 1},
                    {"plains/houses/plains_animal_pen_3", 5},
                    {"plains/houses/plains_accessory_1", 1},
                    {"plains/houses/plains_meeting_point_4", 3},
                    {"plains/houses/plains_meeting_point_5", 1},
                    {"empty", 10}
                };
            case PoolType::PLAIN_ZHOUSES:
                return {
                    {"plains/zombie/houses/plains_small_house_1", 2},
                    {"plains/zombie/houses/plains_small_house_2", 2},
                    {"plains/zombie/houses/plains_small_house_3", 2},
                    {"plains/zombie/houses/plains_small_house_4", 2},
                    {"plains/zombie/houses/plains_small_house_5", 2},
                    {"plains/zombie/houses/plains_small_house_6", 1},
                    {"plains/zombie/houses/plains_small_house_7", 2},
                    {"plains/zombie/houses/plains_small_house_8", 2},
                    {"plains/zombie/houses/plains_medium_house_1", 2},
                    {"plains/zombie/houses/plains_medium_house_2", 2},
                    {"plains/zombie/houses/plains_big_house_1", 2},
                    {"plains/houses/plains_butcher_shop_1", 2},
                    {"plains/zombie/houses/plains_butcher_shop_2", 2},
                    {"plains/houses/plains_tool_smith_1", 2},
                    {"plains/zombie/houses/plains_fletcher_house_1", 2},
                    {"plains/zombie/houses/plains_shepherds_house_1", 2},
                    {"plains/houses/plains_armorer_house_1", 2},
                    {"plains/houses/plains_fisher_cottage_1", 2},
                    {"plains/houses/plains_tannery_1", 2},
                    {"plains/houses/plains_cartographer_1", 1},
                    {"plains/houses/plains_library_1", 3},
                    {"plains/houses/plains_library_2", 1},
                    {"plains/houses/plains_masons_house_1", 2},
                    {"plains/houses/plains_weaponsmith_1", 2},
                    {"plains/houses/plains_temple_3", 2},
                    {"plains/houses/plains_temple_4", 2},
                    {"plains/zombie/houses/plains_stable_1", 2},
                    {"plains/houses/plains_stable_2", 2},
                    {"plains/houses/plains_large_farm_1", 4},
                    {"plains/houses/plains_small_farm_1", 4},
                    {"plains/houses/plains_animal_pen_1", 1},
                    {"plains/houses/plains_animal_pen_2", 1},
                    {"plains/zombie/houses/plains_animal_pen_3", 5},
                    {"plains/zombie/houses/plains_meeting_point_4", 3},
                    {"plains/zombie/houses/plains_meeting_point_5", 1},
                    {"empty", 10}
                };
            case PoolType::PLAIN_STREET:
                return {
                    {"plains/streets/corner_01", 2},
                    {"plains/streets/corner_02", 2},
                    {"plains/streets/corner_03", 2},
                    {"plains/streets/straight_01", 4},
                    {"plains/streets/straight_02", 4},
                    {"plains/streets/straight_03", 7},
                    {"plains/streets/straight_04", 7},
                    {"plains/streets/straight_05", 3},
                    {"plains/streets/straight_06", 4},
                    {"plains/streets/crossroad_01", 2},
                    {"plains/streets/crossroad_02", 1},
                    {"plains/streets/crossroad_03", 2},
                    {"plains/streets/crossroad_04", 2},
                    {"plains/streets/crossroad_05", 2},
                    {"plains/streets/crossroad_06", 2},
                    {"plains/streets/turn_01", 3}
                };
            case PoolType::PLAIN_ZSTREET:
                return {
                    {"plains/zombie/streets/corner_01", 2},
                    {"plains/zombie/streets/corner_02", 2},
                    {"plains/zombie/streets/corner_03", 2},
                    {"plains/zombie/streets/straight_01", 4},
                    {"plains/zombie/streets/straight_02", 4},
                    {"plains/zombie/streets/straight_03", 7},
                    {"plains/zombie/streets/straight_04", 7},
                    {"plains/zombie/streets/straight_05", 3},
                    {"plains/zombie/streets/straight_06", 4},
                    {"plains/zombie/streets/crossroad_01", 2},
                    {"plains/zombie/streets/crossroad_02", 1},
                    {"plains/zombie/streets/crossroad_03", 2},
                    {"plains/zombie/streets/crossroad_04", 2},
                    {"plains/zombie/streets/crossroad_05", 2},
                    {"plains/zombie/streets/crossroad_06", 2},
                    {"plains/zombie/streets/turn_01", 3}
                };
            case PoolType::PLAIN_DECOR:
                return {
                    {"plains/plains_lamp_1", 2},
                    {"oak", 1},
                    {"flower_plain", 1},
                    {"pile_hay", 1},
                    {"empty", 2}
                };
            case PoolType::PLAIN_ZDECOR:
                return {
                    {"plains/plains_lamp_1", 1},
                    {"oak", 1},
                    {"flower_plain", 1},
                    {"pile_hay", 1},
                    {"empty", 2}
                };
            case PoolType::PLAIN_VILLAGER:
                return {
                    {"plains/villagers/nitwit", 1},
                    {"plains/villagers/baby", 1},
                    {"plains/villagers/unemployed", 10}
                };
            case PoolType::PLAIN_ZVILLAGER:
                return {
                    {"plains/zombie/villagers/nitwit", 1},
                    {"plains/zombie/villagers/unemployed", 10}
                };
            case PoolType::PLAIN_TERMINATOR:
                return {
                    {"plains/terminators/terminator_01", 1},
                    {"plains/terminators/terminator_02", 1},
                    {"plains/terminators/terminator_03", 1},
                    {"plains/terminators/terminator_04", 1}
                };
            case PoolType::PLAIN_TREE:
                return {{"oak", 1}};
            default:
                return getCommonTemplates(type);
        }
    }

    PlacementBehaviour getPlacementBehaviour() const override {
        return PlacementBehaviour::RIGID;
    }

    PlacementBehaviour getPlacementBehaviour(PoolType type) const override {
        if (type == PoolType::PLAIN_STREET || type == PoolType::PLAIN_ZSTREET ||
            type == PoolType::PLAIN_TERMINATOR)
            return PlacementBehaviour::TERRAIN_MATCHING;
        return PlacementBehaviour::RIGID;
    }
};

// Pool pour les villages de la taïga
class TaigaPool : public VillagePool {
public:
    std::vector<TemplateEntry> getTemplates(PoolType type) const override {
        switch (type) {
            case PoolType::TAIGA_CENTER:
                return {
                    {"taiga/town_centers/taiga_meeting_point_1", 49},
                    {"taiga/town_centers/taiga_meeting_point_2", 49},
                    {"taiga/zombie/town_centers/taiga_meeting_point_1", 1},
                    {"taiga/zombie/town_centers/taiga_meeting_point_2", 1}
                };
            case PoolType::TAIGA_HOUSES:
                return {
                    {"taiga/houses/taiga_small_house_1", 4},
                    {"taiga/houses/taiga_small_house_2", 4},
                    {"taiga/houses/taiga_small_house_3", 4},
                    {"taiga/houses/taiga_small_house_4", 4},
                    {"taiga/houses/taiga_small_house_5", 4},
                    {"taiga/houses/taiga_medium_house_1", 2},
                    {"taiga/houses/taiga_medium_house_2", 2},
                    {"taiga/houses/taiga_medium_house_3", 2},
                    {"taiga/houses/taiga_medium_house_4", 2},
                    {"taiga/houses/taiga_butcher_shop_1", 2},
                    {"taiga/houses/taiga_tool_smith_1", 2},
                    {"taiga/houses/taiga_fletcher_house_1", 2},
                    {"taiga/houses/taiga_shepherds_house_1", 2},
                    {"taiga/houses/taiga_armorer_house_1", 1},
                    {"taiga/houses/taiga_armorer_2", 1},
                    {"taiga/houses/taiga_fisher_cottage_1", 3},
                    {"taiga/houses/taiga_tannery_1", 2},
                    {"taiga/houses/taiga_cartographer_house_1", 2},
                    {"taiga/houses/taiga_library_1", 2},
                    {"taiga/houses/taiga_masons_house_1", 2},
                    {"taiga/houses/taiga_weaponsmith_1", 2},
                    {"taiga/houses/taiga_weaponsmith_2", 2},
                    {"taiga/houses/taiga_temple_1", 2},
                    {"taiga/houses/taiga_large_farm_1", 6},
                    {"taiga/houses/taiga_large_farm_2", 6},
                    {"taiga/houses/taiga_small_farm_1", 1},
                    {"taiga/houses/taiga_animal_pen_1", 2},
                    {"empty", 6}
                };
            case PoolType::TAIGA_ZHOUSES:
                return {
                    {"taiga/zombie/houses/taiga_small_house_1", 4},
                    {"taiga/zombie/houses/taiga_small_house_2", 4},
                    {"taiga/zombie/houses/taiga_small_house_3", 4},
                    {"taiga/zombie/houses/taiga_small_house_4", 4},
                    {"taiga/zombie/houses/taiga_small_house_5", 4},
                    {"taiga/zombie/houses/taiga_medium_house_1", 2},
                    {"taiga/zombie/houses/taiga_medium_house_2", 2},
                    {"taiga/zombie/houses/taiga_medium_house_3", 2},
                    {"taiga/zombie/houses/taiga_medium_house_4", 2},
                    {"taiga/houses/taiga_butcher_shop_1", 2},
                    {"taiga/zombie/houses/taiga_tool_smith_1", 2},
                    {"taiga/houses/taiga_fletcher_house_1", 2},
                    {"taiga/zombie/houses/taiga_shepherds_house_1", 2},
                    {"taiga/houses/taiga_armorer_house_1", 1},
                    {"taiga/zombie/houses/taiga_fisher_cottage_1", 2},
                    {"taiga/houses/taiga_tannery_1", 2},
                    {"taiga/zombie/houses/taiga_cartographer_house_1", 2},
                    {"taiga/zombie/houses/taiga_library_1", 2},
                    {"taiga/houses/taiga_masons_house_1", 2},
                    {"taiga/houses/taiga_weaponsmith_1", 2},
                    {"taiga/zombie/houses/taiga_weaponsmith_2", 2},
                    {"taiga/zombie/houses/taiga_temple_1", 2},
                    {"taiga/houses/taiga_large_farm_1", 6},
                    {"taiga/zombie/houses/taiga_large_farm_2", 6},
                    {"taiga/houses/taiga_small_farm_1", 1},
                    {"taiga/houses/taiga_animal_pen_1", 2},
                    {"empty", 6}
                };
            case PoolType::TAIGA_STREET:
                return {
                    {"taiga/streets/corner_01", 2},
                    {"taiga/streets/corner_02", 2},
                    {"taiga/streets/corner_03", 2},
                    {"taiga/streets/straight_01", 4},
                    {"taiga/streets/straight_02", 4},
                    {"taiga/streets/straight_03", 4},
                    {"taiga/streets/straight_04", 7},
                    {"taiga/streets/straight_05", 7},
                    {"taiga/streets/straight_06", 4},
                    {"taiga/streets/crossroad_01", 1},
                    {"taiga/streets/crossroad_02", 1},
                    {"taiga/streets/crossroad_03", 2},
                    {"taiga/streets/crossroad_04", 2},
                    {"taiga/streets/crossroad_05", 2},
                    {"taiga/streets/crossroad_06", 2},
                    {"taiga/streets/turn_01", 3}
                };
            case PoolType::TAIGA_ZSTREET:
                return {
                    {"taiga/zombie/streets/corner_01", 2},
                    {"taiga/zombie/streets/corner_02", 2},
                    {"taiga/zombie/streets/corner_03", 2},
                    {"taiga/zombie/streets/straight_01", 4},
                    {"taiga/zombie/streets/straight_02", 4},
                    {"taiga/zombie/streets/straight_03", 4},
                    {"taiga/zombie/streets/straight_04", 7},
                    {"taiga/zombie/streets/straight_05", 7},
                    {"taiga/zombie/streets/straight_06", 4},
                    {"taiga/zombie/streets/crossroad_01", 1},
                    {"taiga/zombie/streets/crossroad_02", 1},
                    {"taiga/zombie/streets/crossroad_03", 2},
                    {"taiga/zombie/streets/crossroad_04", 2},
                    {"taiga/zombie/streets/crossroad_05", 2},
                    {"taiga/zombie/streets/crossroad_06", 2},
                    {"taiga/zombie/streets/turn_01", 3}
                };
            case PoolType::TAIGA_DECOR:
                return {
                    {"taiga/taiga_lamp_post_1", 10},
                    {"taiga/taiga_decoration_1", 4},
                    {"taiga/taiga_decoration_2", 1},
                    {"taiga/taiga_decoration_3", 1},
                    {"taiga/taiga_decoration_4", 1},
                    {"taiga/taiga_decoration_5", 2},
                    {"taiga/taiga_decoration_6", 1},
                    {"taiga/spruce", 4},
                    {"taiga/pine", 4},
                    {"taiga/pile_pumpkin", 2},
                    {"taiga/patch_taiga_grass", 4},
                    {"taiga/patch_berry_bush", 1},
                    {"empty", 4}
                };
            case PoolType::TAIGA_ZDECOR:
                return {
                    {"taiga/taiga_decoration_1", 4},
                    {"taiga/taiga_decoration_2", 1},
                    {"taiga/taiga_decoration_3", 1},
                    {"taiga/taiga_decoration_4", 1},
                    {"taiga/spruce", 4},
                    {"taiga/pine", 4},
                    {"taiga/pile_pumpkin", 2},
                    {"taiga/patch_taiga_grass", 4},
                    {"taiga/patch_berry_bush", 1},
                    {"empty", 4}
                };
            case PoolType::TAIGA_VILLAGER:
                return {
                    {"taiga/villagers/nitwit", 1},
                    {"taiga/villagers/baby", 1},
                    {"taiga/villagers/unemployed", 10}
                };
            case PoolType::TAIGA_ZVILLAGER:
                return {
                    {"taiga/zombie/villagers/nitwit", 1},
                    {"taiga/zombie/villagers/unemployed", 10}
                };
            case PoolType::TAIGA_TERMINATOR:
                return {
                    {"plains/terminators/terminator_01", 1},
                    {"plains/terminators/terminator_02", 1},
                    {"plains/terminators/terminator_03", 1},
                    {"plains/terminators/terminator_04", 1}
                };
            default:
                return getCommonTemplates(type);
        }
    }

    PlacementBehaviour getPlacementBehaviour() const override {
        return PlacementBehaviour::RIGID;
    }

    PlacementBehaviour getPlacementBehaviour(PoolType type) const override {
        if (type == PoolType::TAIGA_STREET || type == PoolType::TAIGA_ZSTREET ||
            type == PoolType::TAIGA_TERMINATOR)
            return PlacementBehaviour::TERRAIN_MATCHING;
        return PlacementBehaviour::RIGID;
    }
};

// Pool pour les villages de la savane
class SavannaPool : public VillagePool {
public:
    std::vector<TemplateEntry> getTemplates(PoolType type) const override {
        switch (type) {
            case PoolType::SAVANNA_CENTER:
                return {
                    {"savanna/town_centers/savanna_meeting_point_1", 100},
                    {"savanna/town_centers/savanna_meeting_point_2", 50},
                    {"savanna/town_centers/savanna_meeting_point_3", 150},
                    {"savanna/town_centers/savanna_meeting_point_4", 150},
                    {"savanna/zombie/town_centers/savanna_meeting_point_1", 2},
                    {"savanna/zombie/town_centers/savanna_meeting_point_2", 1},
                    {"savanna/zombie/town_centers/savanna_meeting_point_3", 3},
                    {"savanna/zombie/town_centers/savanna_meeting_point_4", 3}
                };
            case PoolType::SAVANNA_HOUSES:
                return {
                    {"savanna/houses/savanna_small_house_1", 2},
                    {"savanna/houses/savanna_small_house_2", 2},
                    {"savanna/houses/savanna_small_house_3", 2},
                    {"savanna/houses/savanna_small_house_4", 2},
                    {"savanna/houses/savanna_small_house_5", 2},
                    {"savanna/houses/savanna_small_house_6", 2},
                    {"savanna/houses/savanna_small_house_7", 2},
                    {"savanna/houses/savanna_small_house_8", 2},
                    {"savanna/houses/savanna_medium_house_1", 2},
                    {"savanna/houses/savanna_medium_house_2", 2},
                    {"savanna/houses/savanna_butchers_shop_1", 2},
                    {"savanna/houses/savanna_butchers_shop_2", 2},
                    {"savanna/houses/savanna_tool_smith_1", 2},
                    {"savanna/houses/savanna_fletcher_house_1", 2},
                    {"savanna/houses/savanna_shepherd_1", 7},
                    {"savanna/houses/savanna_armorer_1", 1},
                    {"savanna/houses/savanna_fisher_cottage_1", 3},
                    {"savanna/houses/savanna_tannery_1", 2},
                    {"savanna/houses/savanna_cartographer_1", 2},
                    {"savanna/houses/savanna_library_1", 2},
                    {"savanna/houses/savanna_mason_1", 2},
                    {"savanna/houses/savanna_weaponsmith_1", 2},
                    {"savanna/houses/savanna_weaponsmith_2", 2},
                    {"savanna/houses/savanna_temple_1", 2},
                    {"savanna/houses/savanna_temple_2", 3},
                    {"savanna/houses/savanna_large_farm_1", 4},
                    {"savanna/houses/savanna_large_farm_2", 6},
                    {"savanna/houses/savanna_small_farm", 4},
                    {"savanna/houses/savanna_animal_pen_1", 2},
                    {"savanna/houses/savanna_animal_pen_2", 2},
                    {"savanna/houses/savanna_animal_pen_3", 2},
                    {"empty", 5}
                };
            case PoolType::SAVANNA_ZHOUSES:
                return {
                    {"savanna/zombie/houses/savanna_small_house_1", 2},
                    {"savanna/zombie/houses/savanna_small_house_2", 2},
                    {"savanna/zombie/houses/savanna_small_house_3", 2},
                    {"savanna/zombie/houses/savanna_small_house_4", 2},
                    {"savanna/zombie/houses/savanna_small_house_5", 2},
                    {"savanna/zombie/houses/savanna_small_house_6", 2},
                    {"savanna/zombie/houses/savanna_small_house_7", 2},
                    {"savanna/zombie/houses/savanna_small_house_8", 2},
                    {"savanna/zombie/houses/savanna_medium_house_1", 2},
                    {"savanna/zombie/houses/savanna_medium_house_2", 2},
                    {"savanna/houses/savanna_butchers_shop_1", 2},
                    {"savanna/houses/savanna_butchers_shop_2", 2},
                    {"savanna/houses/savanna_tool_smith_1", 2},
                    {"savanna/houses/savanna_fletcher_house_1", 2},
                    {"savanna/houses/savanna_shepherd_1", 2},
                    {"savanna/houses/savanna_armorer_1", 1},
                    {"savanna/houses/savanna_fisher_cottage_1", 2},
                    {"savanna/houses/savanna_tannery_1", 2},
                    {"savanna/houses/savanna_cartographer_1", 2},
                    {"savanna/houses/savanna_library_1", 2},
                    {"savanna/houses/savanna_mason_1", 2},
                    {"savanna/houses/savanna_weaponsmith_1", 2},
                    {"savanna/houses/savanna_weaponsmith_2", 2},
                    {"savanna/houses/savanna_temple_1", 1},
                    {"savanna/houses/savanna_temple_2", 3},
                    {"savanna/houses/savanna_large_farm_1", 4},
                    {"savanna/zombie/houses/savanna_large_farm_2", 4},
                    {"savanna/houses/savanna_small_farm", 4},
                    {"savanna/houses/savanna_animal_pen_1", 2},
                    {"savanna/zombie/houses/savanna_animal_pen_2", 2},
                    {"savanna/zombie/houses/savanna_animal_pen_3", 2},
                    {"empty", 5}
                };
            case PoolType::SAVANNA_STREET:
                return {
                    {"savanna/streets/corner_01", 2},
                    {"savanna/streets/corner_03", 2},
                    {"savanna/streets/straight_02", 4},
                    {"savanna/streets/straight_04", 7},
                    {"savanna/streets/straight_05", 3},
                    {"savanna/streets/straight_06", 4},
                    {"savanna/streets/straight_08", 4},
                    {"savanna/streets/straight_09", 4},
                    {"savanna/streets/straight_10", 4},
                    {"savanna/streets/straight_11", 4},
                    {"savanna/streets/crossroad_02", 1},
                    {"savanna/streets/crossroad_03", 2},
                    {"savanna/streets/crossroad_04", 2},
                    {"savanna/streets/crossroad_05", 2},
                    {"savanna/streets/crossroad_06", 2},
                    {"savanna/streets/crossroad_07", 2},
                    {"savanna/streets/split_01", 2},
                    {"savanna/streets/split_02", 2},
                    {"savanna/streets/turn_01", 3}
                };
            case PoolType::SAVANNA_ZSTREET:
                return {
                    {"savanna/zombie/streets/corner_01", 2},
                    {"savanna/zombie/streets/corner_03", 2},
                    {"savanna/zombie/streets/straight_02", 4},
                    {"savanna/zombie/streets/straight_04", 7},
                    {"savanna/zombie/streets/straight_05", 3},
                    {"savanna/zombie/streets/straight_06", 4},
                    {"savanna/zombie/streets/straight_08", 4},
                    {"savanna/zombie/streets/straight_09", 4},
                    {"savanna/zombie/streets/straight_10", 4},
                    {"savanna/zombie/streets/straight_11", 4},
                    {"savanna/zombie/streets/crossroad_02", 1},
                    {"savanna/zombie/streets/crossroad_03", 2},
                    {"savanna/zombie/streets/crossroad_04", 2},
                    {"savanna/zombie/streets/crossroad_05", 2},
                    {"savanna/zombie/streets/crossroad_06", 2},
                    {"savanna/zombie/streets/crossroad_07", 2},
                    {"savanna/zombie/streets/split_01", 2},
                    {"savanna/zombie/streets/split_02", 2},
                    {"savanna/zombie/streets/turn_01", 3}
                };
            case PoolType::SAVANNA_DECOR:
                return {
                    {"savanna/savanna_lamp_post_01", 4},
                    {"savanna/acacia", 4},
                    {"pile_hay", 4},
                    {"pile_melon", 1},
                    {"empty", 4}
                };
            case PoolType::SAVANNA_ZDECOR:
                return {
                    {"savanna/savanna_lamp_post_01", 4},
                    {"savanna/acacia", 4},
                    {"pile_hay", 4},
                    {"pile_melon", 1},
                    {"empty", 4}
                };
            case PoolType::SAVANNA_VILLAGER:
                return {
                    {"savanna/villagers/nitwit", 1},
                    {"savanna/villagers/baby", 1},
                    {"savanna/villagers/unemployed", 10}
                };
            case PoolType::SAVANNA_ZVILLAGER:
                return {
                    {"savanna/zombie/villagers/nitwit", 1},
                    {"savanna/zombie/villagers/unemployed", 10}
                };
            case PoolType::SAVANNA_TERMINATOR:
                return {
                    {"plains/terminators/terminator_01", 1},
                    {"plains/terminators/terminator_02", 1},
                    {"plains/terminators/terminator_03", 1},
                    {"plains/terminators/terminator_04", 1},
                    {"savanna/terminators/terminator_05", 1}
                };
            case PoolType::SAVANNA_ZTERMINATOR:
                return {
                    {"plains/terminators/terminator_01", 1},
                    {"plains/terminators/terminator_02", 1},
                    {"plains/terminators/terminator_03", 1},
                    {"plains/terminators/terminator_04", 1},
                    {"savanna/zombie/terminators/terminator_05", 1}
                };
            case PoolType::SAVANNA_TREE:
                return {{"savanna/acacia", 1}};
            default:
                return getCommonTemplates(type);
        }
    }

    PlacementBehaviour getPlacementBehaviour() const override {
        return PlacementBehaviour::RIGID;
    }

    PlacementBehaviour getPlacementBehaviour(PoolType type) const override {
        if (type == PoolType::SAVANNA_STREET || type == PoolType::SAVANNA_ZSTREET ||
            type == PoolType::SAVANNA_TERMINATOR || type == PoolType::SAVANNA_ZTERMINATOR)
            return PlacementBehaviour::TERRAIN_MATCHING;
        return PlacementBehaviour::RIGID;
    }
};

// Pool pour les villages enneigés
class SnowyPool : public VillagePool {
public:
    std::vector<TemplateEntry> getTemplates(PoolType type) const override {
        switch (type) {
            case PoolType::SNOWY_CENTER:
                return {
                    {"snowy/town_centers/snowy_meeting_point_1", 100},
                    {"snowy/town_centers/snowy_meeting_point_2", 50},
                    {"snowy/town_centers/snowy_meeting_point_3", 150},
                    {"snowy/zombie/town_centers/snowy_meeting_point_1", 2},
                    {"snowy/zombie/town_centers/snowy_meeting_point_2", 1},
                    {"snowy/zombie/town_centers/snowy_meeting_point_3", 3}
                };
            case PoolType::SNOWY_HOUSES:
                return {
                    {"snowy/houses/snowy_small_house_1", 2},
                    {"snowy/houses/snowy_small_house_2", 2},
                    {"snowy/houses/snowy_small_house_3", 2},
                    {"snowy/houses/snowy_small_house_4", 3},
                    {"snowy/houses/snowy_small_house_5", 2},
                    {"snowy/houses/snowy_small_house_6", 2},
                    {"snowy/houses/snowy_small_house_7", 2},
                    {"snowy/houses/snowy_small_house_8", 2},
                    {"snowy/houses/snowy_medium_house_1", 2},
                    {"snowy/houses/snowy_medium_house_2", 2},
                    {"snowy/houses/snowy_medium_house_3", 2},
                    {"snowy/houses/snowy_butchers_shop_1", 2},
                    {"snowy/houses/snowy_butchers_shop_2", 2},
                    {"snowy/houses/snowy_tool_smith_1", 2},
                    {"snowy/houses/snowy_fletcher_house_1", 2},
                    {"snowy/houses/snowy_shepherds_house_1", 3},
                    {"snowy/houses/snowy_armorer_house_1", 1},
                    {"snowy/houses/snowy_armorer_house_2", 1},
                    {"snowy/houses/snowy_fisher_cottage", 2},
                    {"snowy/houses/snowy_tannery_1", 2},
                    {"snowy/houses/snowy_cartographer_house_1", 2},
                    {"snowy/houses/snowy_library_1", 2},
                    {"snowy/houses/snowy_masons_house_1", 2},
                    {"snowy/houses/snowy_masons_house_2", 2},
                    {"snowy/houses/snowy_weapon_smith_1", 2},
                    {"snowy/houses/snowy_temple_1", 2},
                    {"snowy/houses/snowy_farm_1", 3},
                    {"snowy/houses/snowy_farm_2", 3},
                    {"snowy/houses/snowy_animal_pen_1", 2},
                    {"snowy/houses/snowy_animal_pen_2", 2},
                    {"empty", 6}
                };
            case PoolType::SNOWY_ZHOUSES:
                return {
                    {"snowy/zombie/houses/snowy_small_house_1", 2},
                    {"snowy/zombie/houses/snowy_small_house_2", 2},
                    {"snowy/zombie/houses/snowy_small_house_3", 2},
                    {"snowy/zombie/houses/snowy_small_house_4", 2},
                    {"snowy/zombie/houses/snowy_small_house_5", 2},
                    {"snowy/zombie/houses/snowy_small_house_6", 2},
                    {"snowy/zombie/houses/snowy_small_house_7", 2},
                    {"snowy/zombie/houses/snowy_small_house_8", 2},
                    {"snowy/zombie/houses/snowy_medium_house_1", 2},
                    {"snowy/zombie/houses/snowy_medium_house_2", 2},
                    {"snowy/zombie/houses/snowy_medium_house_3", 1},
                    {"snowy/houses/snowy_butchers_shop_1", 2},
                    {"snowy/houses/snowy_butchers_shop_2", 2},
                    {"snowy/houses/snowy_tool_smith_1", 2},
                    {"snowy/houses/snowy_fletcher_house_1", 2},
                    {"snowy/houses/snowy_shepherds_house_1", 2},
                    {"snowy/houses/snowy_armorer_house_1", 1},
                    {"snowy/houses/snowy_armorer_house_2", 1},
                    {"snowy/houses/snowy_fisher_cottage", 2},
                    {"snowy/houses/snowy_tannery_1", 2},
                    {"snowy/houses/snowy_cartographer_house_1", 2},
                    {"snowy/houses/snowy_library_1", 2},
                    {"snowy/houses/snowy_masons_house_1", 2},
                    {"snowy/houses/snowy_masons_house_2", 2},
                    {"snowy/houses/snowy_weapon_smith_1", 2},
                    {"snowy/houses/snowy_temple_1", 2},
                    {"snowy/houses/snowy_farm_1", 3},
                    {"snowy/houses/snowy_farm_2", 3},
                    {"snowy/houses/snowy_animal_pen_1", 2},
                    {"snowy/houses/snowy_animal_pen_2", 2},
                    {"empty", 6}
                };
            case PoolType::SNOWY_STREET:
                return {
                    {"snowy/streets/corner_01", 2},
                    {"snowy/streets/corner_02", 2},
                    {"snowy/streets/corner_03", 2},
                    {"snowy/streets/square_01", 2},
                    {"snowy/streets/straight_01", 4},
                    {"snowy/streets/straight_02", 4},
                    {"snowy/streets/straight_03", 4},
                    {"snowy/streets/straight_04", 7},
                    {"snowy/streets/straight_06", 4},
                    {"snowy/streets/straight_08", 4},
                    {"snowy/streets/crossroad_02", 1},
                    {"snowy/streets/crossroad_03", 2},
                    {"snowy/streets/crossroad_04", 2},
                    {"snowy/streets/crossroad_05", 2},
                    {"snowy/streets/crossroad_06", 2},
                    {"snowy/streets/turn_01", 3}
                };
            case PoolType::SNOWY_ZSTREET:
                return {
                    {"snowy/zombie/streets/corner_01", 2},
                    {"snowy/zombie/streets/corner_02", 2},
                    {"snowy/zombie/streets/corner_03", 2},
                    {"snowy/zombie/streets/square_01", 2},
                    {"snowy/zombie/streets/straight_01", 4},
                    {"snowy/zombie/streets/straight_02", 4},
                    {"snowy/zombie/streets/straight_03", 4},
                    {"snowy/zombie/streets/straight_04", 7},
                    {"snowy/zombie/streets/straight_06", 4},
                    {"snowy/zombie/streets/straight_08", 4},
                    {"snowy/zombie/streets/crossroad_02", 1},
                    {"snowy/zombie/streets/crossroad_03", 2},
                    {"snowy/zombie/streets/crossroad_04", 2},
                    {"snowy/zombie/streets/crossroad_05", 2},
                    {"snowy/zombie/streets/crossroad_06", 2},
                    {"snowy/zombie/streets/turn_01", 3}
                };
            case PoolType::SNOWY_DECOR:
                return {
                    {"snowy/snowy_lamp_post_01", 4},
                    {"snowy/snowy_lamp_post_02", 4},
                    {"snowy/snowy_lamp_post_03", 1},
                    {"taiga/spruce", 4},
                    {"snowy/pile_snow", 4},
                    {"snowy/pile_ice", 1},
                    {"empty", 9}
                };
            case PoolType::SNOWY_ZDECOR:
                return {
                    {"snowy/snowy_lamp_post_01", 1},
                    {"snowy/snowy_lamp_post_02", 1},
                    {"snowy/snowy_lamp_post_03", 1},
                    {"taiga/spruce", 4},
                    {"snowy/pile_snow", 4},
                    {"snowy/pile_ice", 4},
                    {"empty", 7}
                };
            case PoolType::SNOWY_VILLAGER:
                return {
                    {"snowy/villagers/nitwit", 1},
                    {"snowy/villagers/baby", 1},
                    {"snowy/villagers/unemployed", 10}
                };
            case PoolType::SNOWY_ZVILLAGER:
                return {
                    {"snowy/zombie/villagers/nitwit", 1},
                    {"snowy/zombie/villagers/unemployed", 10}
                };
            case PoolType::SNOWY_TERMINATOR:
                return {
                    {"plains/terminators/terminator_01", 1},
                    {"plains/terminators/terminator_02", 1},
                    {"plains/terminators/terminator_03", 1},
                    {"plains/terminators/terminator_04", 1}
                };
            case PoolType::SNOWY_TREE:
                return {{"taiga/spruce", 1}};
            default:
                return getCommonTemplates(type);
        }
    }

    PlacementBehaviour getPlacementBehaviour() const override {
        return PlacementBehaviour::RIGID;
    }

    PlacementBehaviour getPlacementBehaviour(PoolType type) const override {
        if (type == PoolType::SNOWY_STREET || type == PoolType::SNOWY_ZSTREET ||
            type == PoolType::SNOWY_TERMINATOR)
            return PlacementBehaviour::TERRAIN_MATCHING;
        return PlacementBehaviour::RIGID;
    }
};

// Déclaration de la fonction factory
std::unique_ptr<VillagePool> createVillagePool(VillageType type);

// Fonction utilitaire pour la sélection aléatoire
std::string_view selectRandomTemplate(const std::vector<TemplateEntry>& templates, std::mt19937& rng); 
