package profotoce59.test;

import com.seedfinding.mcbiome.biome.Biome;
import com.seedfinding.mcbiome.source.OverworldBiomeSource;
import com.seedfinding.mccore.block.Blocks;
import com.seedfinding.mccore.version.MCVersion;
import com.seedfinding.mcterrain.utils.NoiseSettings;
import profotoce59.reecriture.SurfaceGenerator2;

/**
 * Test pour comparer les résultats entre Java et C
 * Reproduit exactement le même test que example_cubiomes_surface.c
 */
public class CompareSurfaceGenTest {

    public static void main(String[] args) {
        System.out.println("=== Test de comparaison Java/C - SurfaceGenerator ===\n");

        // Paramètres identiques au test C
        long seed = 123456789L;
        MCVersion version = MCVersion.v1_16_1;

        System.out.println("Initialisation (MC 1.16, seed=" + seed + ")...");

        // Créer le BiomeSource
        OverworldBiomeSource bs = new OverworldBiomeSource(version, seed);

        // Configuration identique au test C
        SurfaceGenerator2 surfaceGen = new SurfaceGenerator2(
            bs,
            256,  // width (hauteur totale du monde)
            1,    // horizontalNoiseResolution
            2,    // verticalNoiseResolution
            NoiseSettings.create(0.9999999814507745, 0.9999999814507745, 80.0, 160.0)
                .addTopSlide(-10, 3, 0)
                .addBottomSlide(-30, 0, 0),
            1.0,      // densityFactor
            -0.46875, // densityOffset
            true,     // useSimplexNoise (amplified)
            105       // startSizeY (sera converti en startSizeY/8 = 13)
        );

        System.out.println("SurfaceGenerator configuré.\n");

        // --- Test 1 : Position (0, 0) - équivalent au test C ---
        System.out.println("--- Test 1 : Trouver la première pierre à (0, 0) ---");
        int height1 = surfaceGen.generateColumnfromY(0, 0, (block) -> block != Blocks.AIR);
        System.out.println("Position (x=0, z=0)");
        System.out.println("Première pierre trouvée à y=" + height1 + "\n");

        // --- Test 2 : Position (100, 200) - équivalent au test C ---
        System.out.println("--- Test 2 : Position (100, 200) ---");
        int height2 = surfaceGen.generateColumnfromY(100, 200, (block) -> block != Blocks.AIR);
        System.out.println("Position (x=100, z=200)");
        System.out.println("Première pierre trouvée à y=" + height2 + "\n");

        // --- Test 3 : Position (50, -100) - équivalent au test C ---
        System.out.println("--- Test 3 : Position (50, -100) ---");
        int height3 = surfaceGen.generateColumnfromY(50, -100, (block) -> block != Blocks.AIR);
        System.out.println("Position (x=50, z=-100)");
        System.out.println("Première pierre trouvée à y=" + height3 + "\n");

        // --- Test 4 : Plusieurs positions - équivalent au test C ---
        System.out.println("--- Test 4 : Hauteur de la première pierre pour plusieurs positions ---");
        int[][] positions = {
            {0, 0},
            {100, 100},
            {-50, 75},
            {200, -200},
            {1000, 1000}
        };

        for (int[] pos : positions) {
            int x = pos[0];
            int z = pos[1];
            int h = surfaceGen.generateColumnfromY(x, z, (block) -> block != Blocks.AIR);

            // Obtenir aussi le biome
            Biome biome = bs.getBiome(x >> 2, 0, z >> 2);
            int biomeId = biome.getId();

            System.out.printf("  (%5d, %5d) -> hauteur=%3d, biome=%d%n", x, z, h, biomeId);
        }

        // --- Test 5 : Tester uniquement la pierre (STONE) ---
        System.out.println("\n--- Test 5 : Trouver uniquement STONE (pas WATER) ---");
        int heightStone = surfaceGen.generateColumnfromY(0, 0, (block) -> block == Blocks.STONE);
        System.out.println("Position (x=0, z=0)");
        System.out.println("Premier bloc STONE trouvé à y=" + heightStone);

        System.out.println("\n=== Terminé ===");
    }
}
