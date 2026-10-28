package profotoce59.properties;

import com.seedfinding.mcbiome.source.BiomeSource;
import com.seedfinding.mccore.rand.ChunkRand;
import com.seedfinding.mccore.state.Dimension;
import com.seedfinding.mccore.util.pos.BPos;
import com.seedfinding.mccore.version.MCVersion;
import com.seedfinding.mcterrain.TerrainGenerator;

/**
 * Test pour afficher toutes les pièces d'un village généré
 * Permet de comparer avec la version C
 */
public class CompareVillagePieces {

    public static void main(String[] args) {
        System.out.println("=== Comparaison des pièces de village Java/C ===\n");

        // Utiliser la seed trouvée précédemment
        long worldSeed = 755681386269665L;
        int chunkX = 5030;
        int chunkZ = 5046;

        System.out.println("WorldSeed: " + worldSeed);
        System.out.println("Chunk position: (" + chunkX + ", " + chunkZ + ")");
        System.out.println("Block position: (" + (chunkX * 16) + ", " + (chunkZ * 16) + ")\n");

        MCVersion version = MCVersion.v1_16_1;

        try {
            BiomeSource biomeSource = BiomeSource.of(Dimension.OVERWORLD, version, worldSeed);
            TerrainGenerator generator = TerrainGenerator.of(Dimension.OVERWORLD, biomeSource);

            VillageGenerator villeGen = new VillageGenerator(version);
            ChunkRand rand = new ChunkRand();
            
            System.out.println("Génération du village...");
            boolean generated = villeGen.generate(generator, chunkX, chunkZ, rand, true);

            if (!generated) {
                System.out.println("✗ Échec de la génération du village");
                return;
            }

            System.out.println("✓ Village généré avec succès!\n");

            // Afficher toutes les pièces
            var pieces = villeGen.getPieces();
            System.out.println("=== LISTE DES PIÈCES (" + pieces.size() + " pièces) ===\n");
            System.out.println("Format: [Index] Template | Position (x,y,z) | BoundingBox | Rotation | Depth");
            System.out.println("=" .repeat(100) + "\n");

            for (int i = 0; i < pieces.size(); i++) {
                var piece = pieces.get(i);
                BPos pos = piece.pos;
                var box = piece.box;
                var rotation = piece.rotation;
                int depth = piece.depth;
                String template = piece.getName();

                System.out.printf("[%3d] %-50s | (%6d, %3d, %6d) | Box[%6d,%3d,%6d -> %6d,%3d,%6d] | %s | depth=%d%n",
                    i,
                    template,
                    pos.getX(), pos.getY(), pos.getZ(),
                    box.minX, box.minY, box.minZ,
                    box.maxX, box.maxY, box.maxZ,
                    rotation.toString(),
                    depth
                );
            }

            System.out.println("\n" + "=".repeat(100));
            System.out.println("\n=== RÉSUMÉ ===");
            System.out.println("Nombre total de pièces: " + pieces.size());

            // Compter les types de pièces
            long houses = pieces.stream().filter(p -> p.getName().contains("houses")).count();
            long streets = pieces.stream().filter(p -> p.getName().contains("streets")).count();
            long decor = pieces.stream().filter(p -> p.getName().contains("decor")).count();
            long townCenters = pieces.stream().filter(p -> p.getName().contains("town_center")).count();

            System.out.println("  - Town centers: " + townCenters);
            System.out.println("  - Houses: " + houses);
            System.out.println("  - Streets: " + streets);
            System.out.println("  - Decorations: " + decor);

        } catch (Exception e) {
            System.err.println("Erreur: " + e.getMessage());
            e.printStackTrace();
        }
    }
}
