#include "ChunkRand.hpp"

ChunkRand::ChunkRand(uint64_t seed) : seed(seed) {
    setSeed(seed);
}

void ChunkRand::setSeed(uint64_t newSeed) {
    seed = newSeed;
    rng.seed(seed);
}

void ChunkRand::setPopulationSeed(uint64_t worldSeed, int x, int z) {
    uint64_t populationSeed = worldSeed;
    populationSeed = populationSeed * 341873128712ULL + 132897987541ULL;
    populationSeed += x;
    populationSeed = populationSeed * 341873128712ULL + 132897987541ULL;
    populationSeed += z;
    setSeed(populationSeed);
}

void ChunkRand::setDecoratorSeed(uint64_t populationSeed, int index, int step) {
    uint64_t decoratorSeed = populationSeed;
    decoratorSeed = decoratorSeed * 341873128712ULL + 132897987541ULL;
    decoratorSeed += index;
    decoratorSeed = decoratorSeed * 341873128712ULL + 132897987541ULL;
    decoratorSeed += step;
    setSeed(decoratorSeed);
}

int ChunkRand::nextInt(int bound) {
    if (bound <= 0)
        throw std::invalid_argument("bound must be positive");
    
    std::uniform_int_distribution<int> dist(0, bound - 1);
    return dist(rng);
}

int64_t ChunkRand::nextLong() {
    std::uniform_int_distribution<int64_t> dist;
    return dist(rng);
}

float ChunkRand::nextFloat() {
    std::uniform_real_distribution<float> dist(0.0f, 1.0f);
    return dist(rng);
}

bool ChunkRand::nextBoolean() {
    return nextInt(2) == 0;
}

void ChunkRand::advance(int count) {
    rng.discard(count);
} 