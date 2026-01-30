#pragma once

#include <string>
#include <vector>
#include <map>
#include <utility>
#include "VillageGenerator.hpp"

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
// Structure pour stocker les informations de template
struct TemplateEntry {
    std::string name;
    int weight;
    
    TemplateEntry(const std::string& name, int weight) 
        : name(name), weight(weight) {}
};

// Classe de base pour tous les pools
class VillagePool {
public:
    virtual ~VillagePool() = default;
    virtual std::vector<TemplateEntry> getTemplates(PoolType type) const = 0;
    virtual PlacementBehaviour getPlacementBehaviour() const = 0;
};

// Pool pour les villages du désert
class DesertPool : public VillagePool {
public:
    std::vector<TemplateEntry> getTemplates(PoolType type) const override {
        switch (type) {
            case PoolType::DESERT_CENTER:
                return {
                    {"desert/town_centers/desert_meeting_point_1", 98},
                    {"desert/town_centers/desert_meeting_point_2", 98},
                    {"desert/town_centers/desert_meeting_point_3", 98}
                };
            case PoolType::DESERT_HOUSES:
                return {
                    {"desert/houses/desert_small_house_1", 50},
                    {"desert/houses/desert_small_house_2", 50},
                    {"desert/houses/desert_small_house_3", 50},
                    {"desert/houses/desert_small_house_4", 50},
                    {"desert/houses/desert_small_house_5", 50},
                    {"desert/houses/desert_medium_house_1", 100},
                    {"desert/houses/desert_medium_house_2", 100},
                    {"desert/houses/desert_butcher_shop_1", 30},
                    {"desert/houses/desert_temple_1", 20},
                    {"desert/houses/desert_library_1", 20}
                };
            case PoolType::DESERT_STREETS:
                return {
                    {"desert/streets/corner_01", 80},
                    {"desert/streets/straight_01", 100},
                    {"desert/streets/crossroad_01", 50},
                    {"desert/streets/crossroad_02", 50},
                    {"desert/streets/crossroad_03", 50}
                };
            case PoolType::DESERT_DECOR:
                return {
                    {"desert/desert_lamp_1", 30},
                    {"desert/palm", 20},
                    {"desert/cactus", 15}
                };
            default:
                return {};
        }
    }

    PlacementBehaviour getPlacementBehaviour() const override {
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
                    {"plains/town_centers/plains_fountain_01", 98},
                    {"plains/town_centers/plains_meeting_point_1", 98},
                    {"plains/town_centers/plains_meeting_point_2", 98},
                    {"plains/town_centers/plains_meeting_point_3", 98}
                };
            case PoolType::PLAIN_HOUSES:
                return {
                    {"plains/houses/plains_small_house_1", 50},
                    {"plains/houses/plains_small_house_2", 50},
                    {"plains/houses/plains_small_house_3", 50},
                    {"plains/houses/plains_small_house_4", 50},
                    {"plains/houses/plains_small_house_5", 50},
                    {"plains/houses/plains_medium_house_1", 100},
                    {"plains/houses/plains_medium_house_2", 100},
                    {"plains/houses/plains_butcher_shop_1", 30},
                    {"plains/houses/plains_library_1", 20},
                    {"plains/houses/plains_farm_1", 60},
                    {"plains/houses/plains_farm_2", 60}
                };
            case PoolType::PLAIN_STREETS:
                return {
                    {"plains/streets/corner_01", 80},
                    {"plains/streets/straight_01", 100},
                    {"plains/streets/crossroad_01", 50},
                    {"plains/streets/crossroad_02", 50}
                };
            case PoolType::PLAIN_DECOR:
                return {
                    {"plains/plains_lamp_1", 30},
                    {"plains/oak", 20},
                    {"plains/flower_garden", 15}
                };
            default:
                return {};
        }
    }

    PlacementBehaviour getPlacementBehaviour() const override {
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
                    {"taiga/town_centers/taiga_meeting_point_1", 98},
                    {"taiga/town_centers/taiga_meeting_point_2", 98},
                    {"taiga/town_centers/taiga_meeting_point_3", 98}
                };
            case PoolType::TAIGA_HOUSES:
                return {
                    {"taiga/houses/taiga_small_house_1", 50},
                    {"taiga/houses/taiga_small_house_2", 50},
                    {"taiga/houses/taiga_small_house_3", 50},
                    {"taiga/houses/taiga_small_house_4", 50},
                    {"taiga/houses/taiga_small_house_5", 50},
                    {"taiga/houses/taiga_medium_house_1", 100},
                    {"taiga/houses/taiga_medium_house_2", 100},
                    {"taiga/houses/taiga_butcher_shop_1", 30},
                    {"taiga/houses/taiga_tool_smith_1", 30},
                    {"taiga/houses/taiga_fletcher_house_1", 30},
                    {"taiga/houses/taiga_shepherds_house_1", 30}
                };
            case PoolType::TAIGA_STREETS:
                return {
                    {"taiga/streets/corner_01", 80},
                    {"taiga/streets/straight_01", 100},
                    {"taiga/streets/crossroad_01", 50},
                    {"taiga/streets/crossroad_02", 50}
                };
            case PoolType::TAIGA_DECOR:
                return {
                    {"taiga/taiga_lamp_1", 30},
                    {"taiga/spruce", 20},
                    {"taiga/pine", 20},
                    {"taiga/patch_berry_bush", 15}
                };
            default:
                return {};
        }
    }

    PlacementBehaviour getPlacementBehaviour() const override {
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
                    {"savanna/town_centers/savanna_meeting_point_1", 98},
                    {"savanna/town_centers/savanna_meeting_point_2", 98},
                    {"savanna/town_centers/savanna_meeting_point_3", 98},
                    {"savanna/town_centers/savanna_meeting_point_4", 98}
                };
            case PoolType::SAVANNA_HOUSES:
                return {
                    {"savanna/houses/savanna_small_house_1", 50},
                    {"savanna/houses/savanna_small_house_2", 50},
                    {"savanna/houses/savanna_small_house_3", 50},
                    {"savanna/houses/savanna_small_house_4", 50},
                    {"savanna/houses/savanna_medium_house_1", 100},
                    {"savanna/houses/savanna_medium_house_2", 100},
                    {"savanna/houses/savanna_butcher_shop_1", 30},
                    {"savanna/houses/savanna_tool_smith_1", 30},
                    {"savanna/houses/savanna_fletcher_house_1", 30}
                };
            case PoolType::SAVANNA_STREETS:
                return {
                    {"savanna/streets/corner_01", 80},
                    {"savanna/streets/straight_01", 100},
                    {"savanna/streets/crossroad_01", 50},
                    {"savanna/streets/crossroad_02", 50}
                };
            case PoolType::SAVANNA_DECOR:
                return {
                    {"savanna/savanna_lamp_1", 30},
                    {"savanna/acacia", 20},
                    {"savanna/flower_garden", 15}
                };
            default:
                return {};
        }
    }

    PlacementBehaviour getPlacementBehaviour() const override {
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
                    {"snowy/town_centers/snowy_meeting_point_1", 98},
                    {"snowy/town_centers/snowy_meeting_point_2", 98},
                    {"snowy/town_centers/snowy_meeting_point_3", 98}
                };
            case PoolType::SNOWY_HOUSES:
                return {
                    {"snowy/houses/snowy_small_house_1", 50},
                    {"snowy/houses/snowy_small_house_2", 50},
                    {"snowy/houses/snowy_small_house_3", 50},
                    {"snowy/houses/snowy_medium_house_1", 100},
                    {"snowy/houses/snowy_medium_house_2", 100},
                    {"snowy/houses/snowy_butcher_shop_1", 30},
                    {"snowy/houses/snowy_library_1", 20},
                    {"snowy/houses/snowy_mason_house_1", 30}
                };
            case PoolType::SNOWY_STREETS:
                return {
                    {"snowy/streets/corner_01", 80},
                    {"snowy/streets/straight_01", 100},
                    {"snowy/streets/crossroad_01", 50},
                    {"snowy/streets/crossroad_02", 50}
                };
            case PoolType::SNOWY_DECOR:
                return {
                    {"snowy/snowy_lamp_1", 30},
                    {"snowy/spruce", 20},
                    {"snowy/pile_snow", 15},
                    {"snowy/ice_spike", 10}
                };
            default:
                return {};
        }
    }

    PlacementBehaviour getPlacementBehaviour() const override {
        return PlacementBehaviour::RIGID;
    }
};

// Déclaration de la fonction factory
std::unique_ptr<VillagePool> createVillagePool(VillageType type);

// Fonction utilitaire pour la sélection aléatoire
std::string selectRandomTemplate(const std::vector<TemplateEntry>& templates, std::mt19937& rng); 