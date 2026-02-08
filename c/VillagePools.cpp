#include "VillagePools.hpp"
#include <random>
#include "JigSawPool.hpp"

// Factory pour créer le bon type de pool en fonction du biome
std::unique_ptr<VillagePool> createVillagePool(VillageType type) {
    switch (type) {
        case VillageType::DESERT:
            return std::make_unique<DesertPool>();
        case VillageType::PLAINS:
            return std::make_unique<PlainsPool>();
        case VillageType::TAIGA:
            return std::make_unique<TaigaPool>();
        case VillageType::SAVANNA:
            return std::make_unique<SavannaPool>();
        case VillageType::SNOWY:
            return std::make_unique<SnowyPool>();
        default:
            return nullptr;
    }
}

const std::unordered_map<VillageType, JigSawPool, EnumClassHash> STARTS = {
  { VillageType::TAIGA,  make_pool(TaigaPool().getTemplates(PoolType::TAIGA_CENTER)) },
  { VillageType::PLAINS, make_pool(PlainsPool().getTemplates(PoolType::PLAIN_CENTER)) },
  { VillageType::DESERT, make_pool(DesertPool().getTemplates(PoolType::DESERT_CENTER)) },
  { VillageType::SAVANNA, make_pool(SavannaPool().getTemplates(PoolType::SAVANNA_CENTER)) },
  { VillageType::SNOWY, make_pool(SnowyPool().getTemplates(PoolType::SNOWY_CENTER)) },
};

// Fonction utilitaire pour sélectionner un template aléatoire en tenant compte des poids
std::string_view selectRandomTemplate(const std::vector<TemplateEntry>& templates, std::mt19937& rng) {
    if (templates.empty()) {
        return "";
    }

    // Calculer la somme totale des poids
    int totalWeight = 0;
    for (const auto& entry : templates) {
        totalWeight += entry.weight;
    }

    // Générer un nombre aléatoire entre 0 et le poids total
    std::uniform_int_distribution<int> dist(0, totalWeight - 1);
    int randomWeight = dist(rng);

    // Sélectionner le template correspondant au poids
    for (const auto& entry : templates) {
        if (randomWeight < entry.weight) {
            return entry.name;
        }
        randomWeight -= entry.weight;
    }

    // Par défaut, retourner le dernier template
    return templates.back().name;
}
