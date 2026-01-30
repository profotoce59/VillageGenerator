#pragma once

#include "Biome.hpp"
#include <memory>
#include <vector>

class BiomeSource {
public:
    virtual ~BiomeSource() = default;
    
    // Obtenir le biome à une position donnée
    virtual Biome* getBiomeForNoiseGen(int x, int y, int z) = 0;
    
    // Vérifier si un biome peut être généré à une position donnée
    virtual bool canGenerateAt(int x, int z, Biome* biome) = 0;
    
    // Obtenir la seed du monde
    virtual uint64_t getWorldSeed() const = 0;
};

// Implémentation simple pour le test
class SimpleBiomeSource : public BiomeSource {
public:
    SimpleBiomeSource(uint64_t worldSeed);
    
    Biome* getBiomeForNoiseGen(int x, int y, int z) override;
    bool canGenerateAt(int x, int z, Biome* biome) override;
    uint64_t getWorldSeed() const override { return worldSeed; }
    
private:
    uint64_t worldSeed;
    std::vector<std::unique_ptr<Biome>> biomes;
}; 