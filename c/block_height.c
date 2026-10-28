#include <stdio.h>
#include "surface_gen.h"

#include "util.h"


// ====== STUBS À REMPLACER ======
static void my_get_depth_and_scale(int x, int z, double out2[2], void *user) {
    (void)user;
    // TODO: renvoie depth & scale selon le biome de (x,z).
    // Ex: plains ~ (0.125, 0.05), mountains ~ (1.0, 0.5), etc.
    out2[0] = 0.125;
    out2[1] = 0.05;
}
static double my_noise3d(int x,int y,int z, void *user) {
    (void)user;
    // TODO: Perlin/FBM 3D. Ici, bruit dummy centré ~0
    return 0.0
        + 0.001 * (double)( (x*73856093) ^ (y*19349663) ^ (z*83492791) );
}
static double my_noise2d(int x,int z, void *user) {
    (void)user;
    // TODO: Perlin/FBM 2D pour randomOffset overworld
    return 0.0;
}
// =================================

/*int main(void) {
    SurfaceGen sg = {0};
    sg.chunkWidth   = 4;     // doit matcher ta grille (celle de ton code Java)
    sg.chunkHeight  = 8;     // idem
    sg.startSizeY   = 33;    // exemple: 0..32 → 33 entrées (adapter à ton pipeline)
    sg.noiseSizeY   = 32;    // typiquement startSizeY-1
    sg.seaLevel     = 63;
    sg.densityFactor= 1.0;   // mets tes vraies constantes
    sg.densityOffset= -0.46875;
    sg.dim          = DIM_OVERWORLD;

    sg.noiseSettings.topSlideSettings.target  = 0.0;
    sg.noiseSettings.topSlideSettings.size    = 0.0; // 0 → inactif si tu veux
    sg.noiseSettings.topSlideSettings.offset  = 0.0;
    sg.noiseSettings.bottomSlideSettings.target = 0.0;
    sg.noiseSettings.bottomSlideSettings.size   = 0.0;
    sg.noiseSettings.bottomSlideSettings.offset = 0.0;

    sg.get_depth_and_scale = my_get_depth_and_scale;
    sg.sample_noise_3d     = my_noise3d;
    sg.sample_noise_2d     = my_noise2d;

    int x = 39, z = -159;

    // 1) SANS cache
    double *col = (double*)calloc((size_t)(sg.noiseSizeY+1), sizeof(double));
    sample_noise_column(&sg, col, x, z);
    printf("noise[y=6] = %.6f, noise[y=12] = %.6f\n", col[6], col[12]);
    free(col);

    // 2) AVEC cache
    const double *c2 = sample_noise_column_cached(&sg, x, z);
    printf("cached noise[y=6] = %.6f\n", c2[6]);

    free_surface_cache(&sg);
    return 0;
}*/

// Main stub - utiliser example_cubiomes_surface.c pour les tests complets
int main(void) {
    printf("Ce programme est maintenant un stub.\n");
    printf("Pour tester la génération de terrain, utilisez :\n");
    printf("  make example\n\n");
    printf("Voir example_cubiomes_surface.c pour un exemple complet.\n");
    return 0;
}

// Ancien main commenté pour référence
/*
int main(void){
    setvbuf(stdout, NULL, _IONBF, 0);           // stdout non bufferisé
    fprintf(stderr, "[monprog] start\n");       // stderr = non bufferisé
    uint64_t seed = 123456789ULL;  // exemple de seed
    int bx = 0, bz = 0;
    int biomeID = 0;
    int ii;
    int jj;
    Generator g;
    setupGenerator(&g, MC_1_16, 0);
    applySeed(&g, 0, 123456789);
    float y[256];
    int ids[256];
    SurfaceNoise sn;
    fprintf(stderr, "[monprog] initSurfaceNoise...\n");
    initSurfaceNoise(&sn, DIM_OVERWORLD, seed);
    double *col = (double*)calloc((size_t)(sg.noiseSizeY+1), sizeof(double));
    int x = 0, z = 0;
    sample_noise_column(&sn, col, x, z);
    printf("noise[y=6] = %.6f, noise[y=12] = %.6f\n", col[6], col[12]);
    free(col);
    //getHeightFromPos(bx, bz, biomeID, seed);
    //fprintf(stderr, "[monprog] initSurfaceNoise...\n");
    //mapApproxHeight(y, ids, &g, &sn, bx, bz, 16, 16);

    //fprintf(stderr, "[monprog] loop prints...\n");
    //for (ii = 0; ii < 1; ii++)
      //  {
            for (jj = 0; jj < 1; jj++)
            {
                int grass = 0;
                getBiomeDepthAndScale(ids[jj*16+ii], 0, 0, &grass);
                //printf("grass : %d\n", grass); grass ça serait 62 ?
                printf("x %d\n", bx + ii);
                printf("y %d\n", bz + jj);
                printf("height %f\n", y[jj*16+ii]);

            }
        //}
    //tester : mapApproxHeight(y, ids, g, &sn, cx0 >> 2, cz0 >> 2, 4, 4); de Cubiome cx0 étant chunk position cz0 pareil et
    //y et ids initialiser avec ça : float y[16];
                                                   //int ids[16]; Attention ça calcule un chunk j'ai l'impression Comme si c'était du 4 par 4'
                                                   //et donc y c'est un tableau de coordonnées '


}
*/

