#include "Biome.hpp"

// Définition des biomes statiques
const Biome Biome::DESERT(Biome::Type::DESERT, 2.0f, 0.0f);
const Biome Biome::PLAINS(Biome::Type::PLAINS, 0.8f, 0.4f);
const Biome Biome::TAIGA(Biome::Type::TAIGA, 0.25f, 0.8f);
const Biome Biome::SAVANNA(Biome::Type::SAVANNA, 1.2f, 0.0f);
const Biome Biome::SNOWY_TUNDRA(Biome::Type::SNOWY_TUNDRA, 0.0f, 0.5f);

Biome::Biome(Type type, float temperature, float rainfall)
    : type(type), temperature(temperature), rainfall(rainfall) {
}

std::string Biome::getName() const {
    switch (type) {
        case Type::DESERT: return "desert";
        case Type::PLAINS: return "plains";
        case Type::TAIGA: return "taiga";
        case Type::SAVANNA: return "savanna";
        case Type::SNOWY_TUNDRA: return "snowy_tundra";
        case Type::OCEAN: return "ocean";
        case Type::FOREST: return "forest";
        default: return "unknown";
    }
}

bool Biome::isOcean() const {
    return type == Type::OCEAN;
}

bool Biome::isSnowy() const {
    return temperature < 0.15f;
} 