#include "BiomeSource.hpp"
#include <cmath>

extern "C" {
    #include "generator.h"
}

// IDs de biome cubiomes (de biomes.h)
enum CubiomesBiomeID {
    CUBIOMES_PLAINS = 1,
    CUBIOMES_DESERT = 2,
    CUBIOMES_TAIGA = 5,
    CUBIOMES_SNOWY_TUNDRA = 12,
    CUBIOMES_SAVANNA = 35
};

SimpleBiomeSource::SimpleBiomeSource(uint64_t worldSeed) : worldSeed(worldSeed) {
    // Initialiser les biomes de base
    biomes.push_back(std::make_unique<Biome>(Biome::Type::PLAINS));
    biomes.push_back(std::make_unique<Biome>(Biome::Type::DESERT));
    biomes.push_back(std::make_unique<Biome>(Biome::Type::TAIGA));
    biomes.push_back(std::make_unique<Biome>(Biome::Type::SAVANNA));
    biomes.push_back(std::make_unique<Biome>(Biome::Type::SNOWY_TUNDRA));

    // Initialiser le générateur cubiomes
    setupGenerator(&gen, MC_1_16_1, 0);
    applySeed(&gen, DIM_OVERWORLD, worldSeed);
}

Biome* SimpleBiomeSource::getBiomeForNoiseGen(int x, int y, int z) {
    // Utiliser cubiomes pour obtenir le vrai biome
    // x, y, z sont en noise cell coords (block / 4), comme en Java
    int biomeId = getBiomeAt(&gen, 4, x, y, z);

    // Convertir l'ID cubiomes en notre type de biome
    switch (biomeId) {
        case CUBIOMES_DESERT:
            return biomes[1].get();  // DESERT
        case CUBIOMES_TAIGA:
            return biomes[2].get();  // TAIGA
        case CUBIOMES_SAVANNA:
            return biomes[3].get();  // SAVANNA
        case CUBIOMES_SNOWY_TUNDRA:
            return biomes[4].get();  // SNOWY_TUNDRA
        case CUBIOMES_PLAINS:
        default:
            return biomes[0].get();  // PLAINS (défaut)
    }
}

bool SimpleBiomeSource::canGenerateAt(int x, int z, Biome* biome) {
    // Vérifier si le biome à cette position correspond au biome demandé
    return getBiomeForNoiseGen(x, 0, z) == biome;
}
