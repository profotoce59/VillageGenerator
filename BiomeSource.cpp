#include "BiomeSource.hpp"
#include <cmath>

SimpleBiomeSource::SimpleBiomeSource(uint64_t worldSeed) : worldSeed(worldSeed) {
    // Initialiser les biomes de base
    biomes.push_back(std::make_unique<Biome>(Biome::Type::PLAINS));
    biomes.push_back(std::make_unique<Biome>(Biome::Type::DESERT));
    biomes.push_back(std::make_unique<Biome>(Biome::Type::TAIGA));
    biomes.push_back(std::make_unique<Biome>(Biome::Type::SAVANNA));
    biomes.push_back(std::make_unique<Biome>(Biome::Type::SNOWY_TUNDRA));
}

Biome* SimpleBiomeSource::getBiomeForNoiseGen(int x, int y, int z) {
    // Algorithme simple de sélection de biome basé sur les coordonnées
    // Dans une vraie implémentation, cela utiliserait du bruit de Perlin/Simplex
    
    // Utiliser les coordonnées pour générer un index de biome
    int value = (x * 31 + z * 17 + static_cast<int>(worldSeed)) % static_cast<int>(biomes.size());
    int index = value >= 0 ? value : -value;
    return biomes[index].get();
}

bool SimpleBiomeSource::canGenerateAt(int x, int z, Biome* biome) {
    // Vérifier si le biome à cette position correspond au biome demandé
    return getBiomeForNoiseGen(x, 0, z) == biome;
} 