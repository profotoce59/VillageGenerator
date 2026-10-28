#include "ChunkRand.hpp"

// setSeed(long) Java: (seed ^ MULT) & MASK
void ChunkRand::setSeed(int64_t newSeed) {
    seed48 = (static_cast<uint64_t>(newSeed) ^ MULT) & MASK;
}

int32_t ChunkRand::next(int bits) {
    seed48 = (seed48 * MULT + ADD) & MASK;
    return static_cast<int32_t>(seed48 >> (48 - bits));
}

// Algorithme Java (rejection sampling si bound n'est pas power-of-two)
int32_t ChunkRand::nextInt(int32_t bound) {
    if (bound <= 0) throw std::invalid_argument("bound must be positive");
    if ((bound & -bound) == bound) { // power of two
        return static_cast<int32_t>((bound * (int64_t)next(31)) >> 31);
    }
    int32_t bits, val;
    do {
        bits = next(31);
        val  = bits % bound;
    } while (bits - val + (bound - 1) < 0);
    return val;
}

// Java: (next(32) << 32) + next(32)
int64_t ChunkRand::nextLong() {
    int64_t hi = (int64_t)next(32);
    int64_t lo = (int64_t)next(32);
    return (hi << 32) + lo;
}

// Java: nextFloat() = next(24) / (1<<24)
float ChunkRand::nextFloat() {
    return (next(24)) / static_cast<float>(1 << 24);
}

bool ChunkRand::nextBoolean() {
    return next(1) != 0;
}

void ChunkRand::advance(int count) {
    for (int i = 0; i < count; ++i) next(32);
}

/* ===== Seeders façon Minecraft =====
   Il existe plusieurs variantes selon les versions/étapes.
   Ci-dessous trois patterns fréquents.
*/

// 1) Population seed (très utilisé pour features)
// Variante "vanilla" courante : Random(worldSeed); a=nextLong()/2*2+1; b=nextLong()/2*2+1; setSeed(x*a + z*b ^ worldSeed)
void ChunkRand::setPopulationSeed(int64_t worldSeed, int32_t x, int32_t z) {
    setSeed(worldSeed);
    int64_t a = nextLong() / 2 * 2 + 1; // rendre impair comme MC
    int64_t b = nextLong() / 2 * 2 + 1;
    int64_t pop = (int64_t)x * a + (int64_t)z * b ^ worldSeed;
    setSeed(pop);
}

// 2) Decorator seed (ex: pour placer les décorations spécifiques)
// Souvent basé sur populationSeed, puis re-salé par (index, step)
void ChunkRand::setDecoratorSeed(int64_t populationSeed, int32_t index, int32_t step) {
    setSeed(populationSeed);
    int64_t a = nextLong() / 2 * 2 + 1;
    int64_t b = nextLong() / 2 * 2 + 1;
    int64_t deco = (int64_t)index * a + (int64_t)step * b ^ populationSeed;
    setSeed(deco);
}

// 3) Carver seed (pattern que tu avais commencé)
int64_t ChunkRand::setCarverSeed(int64_t worldSeed, int32_t chunkX, int32_t chunkZ) {
    setSeed(worldSeed);
    int64_t a = nextLong();
    int64_t b = nextLong();
    int64_t s = (int64_t)chunkX * a ^ (int64_t)chunkZ * b ^ worldSeed;
    setSeed(s);
    return s; // (optionnel) renvoyer la seed 64 bits
}


std::string_view ChunkRand::getRandom(const JigSawPool& pool) {
    const auto n = static_cast<int>(pool.index_flat.size());
    if (n <= 0) return {};                 // vide -> string_view vide
    const int r = nextInt(n);              // EXACTEMENT comme Java
    const auto idx = static_cast<size_t>(pool.index_flat[r]);
    return pool.names[idx];
}