#include <stdio.h>
#include <stdlib.h>
#include "cubiomes_integration.h"
#include "surface_gen.h"

// Exemple de prédicat : teste si le bloc est de la pierre
int is_stone_predicate(Block block, void *user) {
    (void)user;  // unused
    return (block == BLOCK_STONE);
}

int main(void) {
    printf("=== Exemple d'intégration Cubiomes avec SurfaceGen ===\n\n");

    // 1. Initialiser le contexte cubiomes
    CubiomesContext ctx;
    uint64_t seed = 123456789ULL;
    int mc_version = MC_1_16;

    printf("Initialisation de cubiomes (MC 1.16, seed=%llu)...\n", seed);
    init_cubiomes_context(&ctx, mc_version, seed);

    // 2. Configurer SurfaceGen avec cubiomes
    SurfaceGen sg = {0};
    setup_surface_gen_with_cubiomes(&sg, &ctx);
    printf("SurfaceGen configuré avec cubiomes.\n\n");

    // 3. Exemple 1 : Échantillonner une colonne de bruit
    printf("--- Exemple 1 : Échantillonner une colonne de bruit ---\n");
    int x = 100, z = 200;
    double *col = (double*)calloc((size_t)(sg.noiseSizeY + 1), sizeof(double));

    sample_noise_column(&sg, col, x, z);
    printf("Position (x=%d, z=%d)\n", x, z);
    printf("Bruit[y=6]  = %.6f\n", col[6]);
    printf("Bruit[y=12] = %.6f\n", col[12]);
    printf("Bruit[y=20] = %.6f\n\n", col[20]);
    free(col);

    // 4. Exemple 2 : Générer une colonne et trouver la première pierre
    printf("--- Exemple 2 : Générer une colonne et trouver la première pierre ---\n");
    x = 50;
    z = -100;

    int height = generate_column_from_y(&sg, x, z, is_stone_predicate, &sg);
    printf("Position (x=%d, z=%d)\n", x, z);
    printf("Première pierre trouvée à y=%d\n\n", height);

    // 5. Exemple 3 : Tester plusieurs positions
    printf("--- Exemple 3 : Hauteur de la première pierre pour plusieurs positions ---\n");
    int positions[][2] = {
        {0, 0},
        {100, 100},
        {-50, 75},
        {200, -200},
        {1000, 1000}
    };

    for (int i = 0; i < 5; i++) {
        int px = positions[i][0];
        int pz = positions[i][1];
        int h = generate_column_from_y(&sg, px, pz, is_stone_predicate, &sg);

        // Obtenir aussi le biome
        int biome = getBiomeAt(&ctx.gen, 4, px >> 2, 0, pz >> 2);

        printf("  (%5d, %5d) -> hauteur=%3d, biome=%d\n", px, pz, h, biome);
    }

    // 6. Exemple 4 : Utiliser le cache pour optimiser
    printf("\n--- Exemple 4 : Utilisation du cache ---\n");
    const double *cached1 = sample_noise_column_cached(&sg, 100, 200);
    const double *cached2 = sample_noise_column_cached(&sg, 100, 200); // même position
    printf("Première lecture  : %.6f\n", cached1[10]);
    printf("Seconde lecture (cachée) : %.6f\n", cached2[10]);
    printf("Même pointeur ? %s\n", (cached1 == cached2) ? "Oui (cache hit!)" : "Non");

    free_surface_cache(&sg);

    printf("\n=== Terminé ===\n");
    return 0;
}
