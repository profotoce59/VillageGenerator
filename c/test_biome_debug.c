#include <stdio.h>
#include "generator.h"
#include "biomenoise.h"

int main(void) {
    uint64_t seed = 123456789ULL;

    Generator g;
    setupGenerator(&g, MC_1_16, 0);
    applySeed(&g, DIM_OVERWORLD, seed);

    printf("Biomes autour de (0, 0):\n");
    for (int rx = -2; rx <= 2; rx++) {
        for (int rz = -2; rz <= 2; rz++) {
            int biomeId = getBiomeAt(&g, 4, rx, 0, rz);
            double depth, scale;
            int grass;
            getBiomeDepthAndScale(biomeId, &depth, &scale, &grass);
            printf("  (%2d,%2d): biome=%3d, depth=%.4f, scale=%.4f\n",
                   rx, rz, biomeId, depth, scale);
        }
    }

    return 0;
}
