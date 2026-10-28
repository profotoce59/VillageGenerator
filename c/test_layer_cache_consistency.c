/*
 * test_layer_cache_consistency — genBiomes() doit donner le meme resultat quelle
 * que soit la taille des requetes precedentes.
 *
 * On lit les memes biomes de deux facons, avec deux contextes independants :
 *   - contexte A : lecture directe, cellule par cellule
 *   - contexte B : on genere d'abord une grande zone, puis on relit les memes
 *                  cellules une par une
 * Les deux doivent donner exactement les memes ids.
 *
 * ETAT ACTUEL : ce test ECHOUE avec le cache de layer de cubiomes/layers.c
 * (mapCached), qui renvoie des biomes faux pour les requetes 1x1. Le
 * contournement est CUBIOMES_LAYER_CACHE=0, avec lequel le test passe.
 * Aucun rapport avec CUDA : c'est un bug du C existant, que le calcul groupe
 * des biomes (cubiomes_get_depth_and_scale_grid) ne fait que rendre visible.
 *
 * Build : make -C c test_layer_cache_consistency
 */
#include <stdio.h>
#include <stdlib.h>
#include "generator.h"

static int biomeAt(Generator *g, int x, int z)
{
    int out[1];
    Range r = {4, x, z, 1, 1, 63, 1};
    size_t need = getMinCacheSize(g, r.scale, r.sx, r.sy, r.sz);
    int *buf = (int*)malloc(sizeof(int) * need);
    if (!buf) return -1;
    int err = genBiomes(g, buf, r);
    out[0] = err ? -1 : buf[0];
    free(buf);
    return out[0];
}

int main(int argc, char **argv)
{
    uint64_t seed = (argc > 1) ? strtoull(argv[1], NULL, 10) : 281474976710703ULL;
    int cx0 = (argc > 2) ? atoi(argv[2]) : -24;
    int cz0 = (argc > 3) ? atoi(argv[3]) : -24;
    int n    = (argc > 4) ? atoi(argv[4]) : 48;

    printf("seed=%llu  zone de cellules (%d,%d) %dx%d\n",
           (unsigned long long)seed, cx0, cz0, n, n);

    /* --- contexte A : lectures unitaires uniquement --- */
    Generator ga;
    setupGenerator(&ga, MC_1_16, 0);
    applySeed(&ga, DIM_OVERWORLD, seed);

    int *refv = (int*)malloc(sizeof(int) * n * n);
    for (int cz = 0; cz < n; cz++)
        for (int cx = 0; cx < n; cx++)
            refv[cz * n + cx] = biomeAt(&ga, cx0 + cx, cz0 + cz);
    freeLayerCaches(&ga);

    /* --- contexte B : grande zone d'abord, puis relecture unitaire --- */
    Generator gb;
    setupGenerator(&gb, MC_1_16, 0);
    applySeed(&gb, DIM_OVERWORLD, seed);

    Range big = {4, cx0, cz0, n, n, 63, 1};
    size_t need = getMinCacheSize(&gb, big.scale, big.sx, big.sy, big.sz);
    int *bigbuf = (int*)malloc(sizeof(int) * need);
    genBiomes(&gb, bigbuf, big);

    int diffAfterBulk = 0, diffInBulk = 0;
    for (int cz = 0; cz < n; cz++) {
        for (int cx = 0; cx < n; cx++) {
            int ref  = refv[cz * n + cx];
            int bulk = bigbuf[cz * n + cx];
            int unit = biomeAt(&gb, cx0 + cx, cz0 + cz);
            if (bulk != ref) {
                if (diffInBulk < 5)
                    printf("  zone   (%4d,%4d) : unitaire=%d  zone=%d\n",
                           cx0 + cx, cz0 + cz, ref, bulk);
                diffInBulk++;
            }
            if (unit != ref) {
                if (diffAfterBulk < 5)
                    printf("  apres  (%4d,%4d) : attendu=%d  obtenu=%d\n",
                           cx0 + cx, cz0 + cz, ref, unit);
                diffAfterBulk++;
            }
        }
    }
    freeLayerCaches(&gb);

    {   /* valeur d'une cellule temoin depuis un contexte tout neuf */
        int probeX = -1, probeZ = -1;
        if (probeX >= cx0 && probeX < cx0 + n && probeZ >= cz0 && probeZ < cz0 + n) {
            Generator gc;
            setupGenerator(&gc, MC_1_16, 0);
            applySeed(&gc, DIM_OVERWORLD, seed);
            int fresh = biomeAt(&gc, probeX, probeZ);
            freeLayerCaches(&gc);
            printf("\ncellule temoin (%d,%d) : contexte neuf=%d  unitaire=%d  zone=%d\n",
                   probeX, probeZ, fresh,
                   refv[(probeZ - cz0) * n + (probeX - cx0)],
                   bigbuf[(probeZ - cz0) * n + (probeX - cx0)]);
        }
    }

    printf("\ncellules comparees          : %d\n", n * n);
    printf("ecarts zone vs unitaire     : %d\n", diffInBulk);
    printf("ecarts unitaire apres zone  : %d\n", diffAfterBulk);
    printf("%s\n", (diffInBulk || diffAfterBulk)
           ? "BUG : le resultat depend de l'historique des requetes"
           : "OK : resultats independants de l'historique");

    free(refv); free(bigbuf);
    return (diffInBulk || diffAfterBulk) ? 1 : 0;
}
