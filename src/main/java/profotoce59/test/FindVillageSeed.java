package profotoce59.test;

import com.seedfinding.mcbiome.source.BiomeSource;
import com.seedfinding.mccore.rand.ChunkRand;
import com.seedfinding.mccore.state.Dimension;
import com.seedfinding.mccore.util.pos.CPos;
import com.seedfinding.mccore.version.MCVersion;
import com.seedfinding.mcfeature.structure.Village;
import com.seedfinding.mcterrain.TerrainGenerator;
import profotoce59.properties.VillageGenerator;

/**
 * Test pour trouver une seed avec un village qui se génère correctement
 * Affiche la seed, les coordonnées chunk et bloc pour tester ensuite en C
 */
public class FindVillageSeed {

    public static void main(String[] args) {
        System.out.println("=== Recherche d'une seed avec village ===\n");

        MCVersion version = MCVersion.v1_16_1;
        long structureSeed = 192731432848353L;

        Village villageFeature = new Village(version);
        ChunkRand chunkRand = new ChunkRand();

        // Chercher dans une région spécifique
        System.out.println("Structure seed: " + structureSeed);
        System.out.println("Recherche de villages dans la région (157, 157)...\n");

        // Obtenir la position du village dans cette région
        CPos villageChunkPos = villageFeature.getInRegion(structureSeed, 157, 157, chunkRand);

        if (villageChunkPos == null) {
            System.out.println("Pas de village trouvé dans cette région.");
            return;
        }

        System.out.println("Village trouvé aux coordonnées chunk: " + villageChunkPos);
        System.out.println("  Chunk X: " + villageChunkPos.getX());
        System.out.println("  Chunk Z: " + villageChunkPos.getZ());
        System.out.println("  Bloc X: " + (villageChunkPos.getX() * 16));
        System.out.println("  Bloc Z: " + (villageChunkPos.getZ() * 16));

        // Tester plusieurs worldSeeds
        System.out.println("\nTest de génération du village avec différentes worldSeeds:\n");

        boolean found = false;
        for (long seed = 0; seed < 16 && !found; seed++) {
            long worldSeed = (structureSeed & 281474976710655L) | (seed << 48);

            BiomeSource biomeSource = BiomeSource.of(Dimension.OVERWORLD, version, worldSeed);
            TerrainGenerator generator = TerrainGenerator.of(Dimension.OVERWORLD, biomeSource);

            VillageGenerator villeGen = new VillageGenerator(version);
            ChunkRand rand = new ChunkRand();

            System.out.print("  WorldSeed " + worldSeed + " ... ");

            try {
                boolean generated = villeGen.generate(generator, villageChunkPos.getX(), villageChunkPos.getZ(), rand, true);

                if (generated) {
                    System.out.println("✓ VILLAGE GÉNÉRÉ!");
                    System.out.println("\n=== SEED TROUVÉE ===");
                    System.out.println("WorldSeed: " + worldSeed);
                    System.out.println("StructureSeed: " + structureSeed);
                    System.out.println("Chunk position: (" + villageChunkPos.getX() + ", " + villageChunkPos.getZ() + ")");
                    System.out.println("Block position: (" + (villageChunkPos.getX() * 16) + ", " + (villageChunkPos.getZ() * 16) + ")");
                    System.out.println("\nCommande Minecraft:");
                    System.out.println("  /tp " + (villageChunkPos.getX() * 16) + " 80 " + (villageChunkPos.getZ() * 16));
                    System.out.println("\n===================\n");

                    // Afficher quelques infos sur le village
                    System.out.println("Informations du village:");
                    System.out.println("  Nombre de pièces: " + villeGen.getPieces().size());

                    found = true;
                } else {
                    System.out.println("✗ Génération échouée");
                }
            } catch (Exception e) {
                System.out.println("✗ Erreur: " + e.getMessage());
            }
        }

        if (!found) {
            System.out.println("\nAucune génération réussie trouvée dans les 16 premières worldSeeds.");
        }
    }
}
