#include <stdio.h>
#include "cubiomes_integration.h"

// Prédicat simple : retourne 1 pour tout sauf AIR
int not_air(Block block, void *user) {
    (void)user;
    return (block != BLOCK_AIR);
}

int main(void) {
    printf("=== Test simple position (0, 0) ===\n\n");

    // Initialiser cubiomes avec la même seed que Java
    CubiomesContext ctx;
    init_cubiomes_context(&ctx, MC_1_16, 123456789ULL);

    // Configurer SurfaceGen
    SurfaceGen sg = {0};
    setup_surface_gen_with_cubiomes(&sg, &ctx);

    // Debug : afficher les paramètres
    printf("Paramètres SurfaceGen:\n");
    printf("  chunkWidth: %d\n", sg.chunkWidth);
    printf("  chunkHeight: %d\n", sg.chunkHeight);
    printf("  startSizeY: %d\n", sg.startSizeY);
    printf("  noiseSizeY: %d\n", sg.noiseSizeY);
    printf("  seaLevel: %d\n", sg.seaLevel);
    printf("  densityFactor: %.10f\n", sg.densityFactor);
    printf("  densityOffset: %.10f\n", sg.densityOffset);
    printf("  topSlide: (%.1f, %.1f, %.1f)\n",
           sg.noiseSettings.topSlideSettings.target,
           sg.noiseSettings.topSlideSettings.size,
           sg.noiseSettings.topSlideSettings.offset);
    printf("  bottomSlide: (%.1f, %.1f, %.1f)\n\n",
           sg.noiseSettings.bottomSlideSettings.target,
           sg.noiseSettings.bottomSlideSettings.size,
           sg.noiseSettings.bottomSlideSettings.offset);

    // Échantillonner une colonne à (0, 0) et afficher les premières valeurs
    printf("Échantillonnage colonne (cellX=0, cellZ=0):\n");
    double *col = (double*)calloc((size_t)(sg.noiseSizeY + 1), sizeof(double));
    sample_noise_column(&sg, col, 0, 0);

    for (int y = 6; y < 14 && y <= sg.startSizeY; y++) {
        printf("  buffer[%d] = %.6f\n", y, col[y]);
    }
    printf("\n");
    free(col);

    // Tester generateColumnfromY
    int height = generate_column_from_y(&sg, 0, 0, not_air, &sg);
    printf("Hauteur trouvée: %d\n", height);

    return 0;
}
