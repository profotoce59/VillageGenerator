#pragma once

#include <random>
#include <cstdint>

class ChunkRand {
public:
    ChunkRand(uint64_t seed = 0);
    
    void setSeed(uint64_t seed);
    void setPopulationSeed(uint64_t worldSeed, int x, int z);
    void setDecoratorSeed(uint64_t populationSeed, int index, int step);
    
    int nextInt(int bound);
    int64_t nextLong();
    float nextFloat();
    bool nextBoolean();
    
    void advance(int count);
    
    // Accès au générateur de nombres aléatoires sous-jacent
    std::mt19937_64& getRNG() { return rng; }
    const std::mt19937_64& getRNG() const { return rng; }
    
private:
    std::mt19937_64 rng;
    uint64_t seed;
}; 