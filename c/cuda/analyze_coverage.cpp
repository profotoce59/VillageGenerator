/**
 * analyze_coverage.cpp — quelles colonnes de bruit un village consomme-t-il
 * réellement, autour de son centre ?
 *
 * On pré-calcule aujourd'hui une zone carrée de ~2100 colonnes par village.
 * Cet outil mesure lesquelles servent vraiment, pour répondre à deux questions :
 *   - une zone plus petite (ou d'une autre forme) suffirait-elle ?
 *   - un découpage en tuiles calculées à la demande serait-il rentable ?
 *
 * Mono-thread volontairement : on mesure une distribution, pas un débit.
 *
 * Usage : analyze_coverage.exe [--seed N] [--count N] [--tile N]
 */

#include "cuda_height_provider.hpp"

#include "../VillageGenerator.hpp"
#include "../TerrainGenerator.hpp"
#include "../BiomeSource.hpp"
#include "../ChunkRand.hpp"
#include "../SurfaceGenWrapper.hpp"

extern "C" {
    #include "finders.h"
}

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <vector>

int main(int argc, char** argv)
{
    uint64_t seed = 1;
    long count    = 300;
    int  tileBlocks = 16;      // taille de tuile à évaluer, en blocs

    for (int i = 1; i < argc; i++) {
        if      (!strcmp(argv[i], "--seed")  && i+1 < argc) seed  = strtoull(argv[++i], nullptr, 10);
        else if (!strcmp(argv[i], "--count") && i+1 < argc) count = strtol(argv[++i], nullptr, 10);
        else if (!strcmp(argv[i], "--tile")  && i+1 < argc) tileBlocks = atoi(argv[++i]);
        else { fprintf(stderr, "argument inconnu : %s\n", argv[i]); return 2; }
    }

    const int R = 32;          // rayon suivi, en cellules (±128 blocs)
    printf("=== Couverture des colonnes de bruit par village ===\n");
    printf("seed %llu, %ld villages, rayon suivi %d cellules (±%d blocs)\n\n",
           (unsigned long long)seed, count, R, R * 4);

    CudaHeightProvider provider;
    SurfaceGenWrapper::setHeightProvider(&provider);
    provider.enableUsageTracking(R);

    std::vector<Pos> posList;
    for (int rx = 0; rx < 10; rx++)
        for (int rz = 0; rz < 10; rz++) {
            Pos p;
            if (getStructurePos(Village, MC_1_16, seed & MASK48, rx, rz, &p)) {
                Pos c; c.x = p.x >> 4; c.z = p.z >> 4; posList.push_back(c);
            }
        }

    long villages = 0;
    for (uint64_t ws = 0; villages < count; ws++) {
        uint64_t worldSeed = (seed & MASK48) | (ws << 48);
        Generator g;
        setupGenerator(&g, MC_1_16, 0);
        applySeed(&g, DIM_OVERWORLD, worldSeed);
        auto bs = std::make_unique<SimpleBiomeSource>(worldSeed);
        auto tg = std::make_unique<OverworldTerrainGenerator>(worldSeed, std::move(bs));
        for (const Pos& sp : posList) {
            if (villages >= count) break;
            if (!isViableStructurePos(Village, &g, sp.x << 4, sp.z << 4, 0)) continue;
            ChunkRand rand;
            VillageGenerator vg;
            if (!vg.generate(tg.get(), sp.x, sp.z, rand, nullptr, true, false)) continue;
            villages++;
        }
        freeLayerCaches(&g);
    }
    SurfaceGenWrapper::setHeightProvider(nullptr);

    const long tracked = provider.villagesTracked();
    const long used    = provider.uniqueColumnsUsed();
    const long comp    = provider.columnsComputed();
    if (tracked == 0) { printf("aucun village suivi\n"); return 1; }

    printf("villages suivis            : %ld\n", tracked);
    printf("colonnes calculées         : %ld  (%.0f / village)\n", comp, (double)comp / tracked);
    printf("colonnes réellement lues   : %ld  (%.0f / village)\n", used, (double)used / tracked);
    printf("gaspillage                 : %.1fx\n", used ? (double)comp / used : 0.0);

    const auto& map = provider.usageMap();
    const int side = 2 * R + 1;

    // Couverture cumulée par rayon (en cellules) : quelle fraction des lectures
    // tombe dans un carré de ce rayon autour du centre.
    printf("\n--- Couverture cumulée par rayon ---\n");
    printf("  %-10s %-10s %12s %14s\n", "rayon", "blocs", "% lectures", "colonnes zone");
    for (int r = 4; r <= R; r += 4) {
        long inside = 0;
        for (int dz = -r; dz <= r; dz++)
            for (int dx = -r; dx <= r; dx++)
                inside += map[(size_t)(dz + R) * side + (dx + R)];
        int cols = (2 * r + 1) * (2 * r + 1);
        printf("  %-10d %-10d %11.1f%% %14d\n", r, r * 4,
               used ? 100.0 * inside / used : 0.0, cols);
    }

    // Combien de cellules distinctes sont utilisées par au moins X% des villages ?
    printf("\n--- Cellules par fréquence d'usage ---\n");
    for (int pct : {90, 75, 50, 25, 10, 1}) {
        long n = 0;
        for (uint32_t c : map) if (c * 100 >= (uint32_t)pct * (uint32_t)tracked) n++;
        printf("  utilisées par >= %3d %% des villages : %5ld cellules\n", pct, n);
    }

    // Évaluation du découpage en tuiles : combien de tuiles distinctes un
    // village toucherait-il, et combien de colonnes cela représenterait-il ?
    // (approximation : on répartit les cellules utilisées moyennes sur la grille)
    {
        const int tileCells = tileBlocks / 4;          // cellules par côté de tuile
        if (tileCells >= 1) {
            std::vector<uint8_t> tileTouched;
            const int tside = (2 * R) / tileCells + 2;
            tileTouched.assign((size_t)tside * tside, 0);
            long touched = 0;
            for (int dz = -R; dz <= R; dz++)
                for (int dx = -R; dx <= R; dx++)
                    if (map[(size_t)(dz + R) * side + (dx + R)] > 0) {
                        int tx = (dx + R) / tileCells, tz = (dz + R) / tileCells;
                        size_t i = (size_t)tz * tside + tx;
                        if (!tileTouched[i]) { tileTouched[i] = 1; touched++; }
                    }
            // colonnes par tuile : (tileCells+1)^2, le +1 pour les angles
            int colsPerTile = (tileCells + 1) * (tileCells + 1);
            printf("\n--- Découpage en tuiles de %d x %d blocs ---\n", tileBlocks, tileBlocks);
            printf("  tuiles couvrant l'union de tous les villages : %ld\n", touched);
            printf("  colonnes par tuile                          : %d\n", colsPerTile);
            printf("  NB : c'est l'union sur %ld villages, pas le compte par village.\n",
                   tracked);
        }
    }

    // Carte de densité, sous-échantillonnée pour tenir à l'écran.
    printf("\n--- Carte d'usage (%% des villages, centre = C, 1 caractère = 2x2 cellules = 8x8 blocs) ---\n");
    const int step = 2;
    for (int dz = -R; dz <= R; dz += step) {
        printf("  ");
        for (int dx = -R; dx <= R; dx += step) {
            uint32_t best = 0;
            for (int sz = 0; sz < step && dz + sz <= R; sz++)
                for (int sx = 0; sx < step && dx + sx <= R; sx++)
                    best = std::max(best, map[(size_t)(dz + sz + R) * side + (dx + sx + R)]);
            double pc = 100.0 * best / tracked;
            char ch;
            if (dx == 0 && dz == 0)   ch = 'C';
            else if (pc >= 90)        ch = '#';
            else if (pc >= 60)        ch = '@';
            else if (pc >= 30)        ch = '+';
            else if (pc >= 10)        ch = '.';
            else if (pc > 0)          ch = ',';
            else                      ch = ' ';
            putchar(ch);
        }
        putchar('\n');
    }
    printf("  legende : # >=90%%  @ >=60%%  + >=30%%  . >=10%%  , >0%%  (espace) jamais\n");
    return 0;
}
