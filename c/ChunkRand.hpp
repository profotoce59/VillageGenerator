#pragma once

#include "JigSawPool.hpp"
#include <cstdint>
#include <stdexcept>
#include <utility>
#include <vector>


class ChunkRand {
public:
    ChunkRand(int64_t seed = 0) { setSeed(seed); }

    // API Java-compatible
    void     setSeed(int64_t newSeed);
    int32_t  nextInt(int32_t bound);
    int64_t  nextLong();
    float    nextFloat();
    bool     nextBoolean();

    // Helpers Minecraft courants
    void setPopulationSeed(int64_t worldSeed, int32_t x, int32_t z);
    void setDecoratorSeed(int64_t populationSeed, int32_t index, int32_t step);
    int64_t setCarverSeed(int64_t worldSeed, int32_t chunkX, int32_t chunkZ);

    // Avance de n tirages "next(32)" (approx) – utile si tu veux skipper
    void advance(int count);
    // Équivalent de Java: rand.getRandom(jigSawPool.getTemplates())
    // Tire uniformément dans la "liste étendue" (index_flat) -> mêmes proba qu'en Java
    std::string_view getRandom(const JigSawPool& pool);

    // Pour le débogage: obtenir la seed interne
    uint64_t getSeed() const { return seed48; }

    // Équivalent de Java: Collections.shuffle(list, rand)
    template<typename T>
    void shuffle(std::vector<T>& vec) {
        for (size_t i = vec.size(); i > 1; ) {
            size_t j = static_cast<size_t>(nextInt(static_cast<int32_t>(i)));
            --i;
            if (i != j) std::swap(vec[i], vec[j]);
        }
    }

private:
    // état interne 48 bits
    uint64_t seed48 = 0;

    static constexpr uint64_t MULT = 0x5DEECE66DULL;
    static constexpr uint64_t ADD  = 0xBULL;
    static constexpr uint64_t MASK = (1ULL << 48) - 1;

    // impl de Random.next(bits)
    int32_t next(int bits);
};