package profotoce59;

import java.util.List;

import com.seedfinding.mcbiome.source.OverworldBiomeSource;
import com.seedfinding.mccore.rand.ChunkRand;
import com.seedfinding.mccore.util.data.Pair;
import com.seedfinding.mccore.util.pos.BPos;
import com.seedfinding.mccore.util.pos.CPos;
import com.seedfinding.mccore.version.MCVersion;
import com.seedfinding.mcfeature.loot.item.ItemStack;
import com.seedfinding.mcfeature.loot.item.Items;
import com.seedfinding.mcfeature.structure.Village;
import com.seedfinding.mcterrain.terrain.OverworldTerrainGenerator;
import org.junit.jupiter.api.Test;
import profotoce59.properties.VillageGenerator;

public class Example {
    @Test
    public void villageExample(){
        // In this example we are going to find a seed which has 10 obsidian in a village chest in the village in region 0, 0

        // We will need this to get the village positions later, so we create it now so we don't have to loop it.
        Village village = new Village(MCVersion.v1_16_5);
        // Ditto with the random object.
        ChunkRand rand = new ChunkRand();
        // And the village generator.
        VillageGenerator generator = new VillageGenerator(MCVersion.v1_16_5);

        int seed = 0;
        // We loop until we find a good seed;
        while(true) {
            // We need an overworld biome source and an overworld terrain generator, so we instantiate those.
            OverworldBiomeSource biomeSource = new OverworldBiomeSource(MCVersion.v1_16_5, seed);
            OverworldTerrainGenerator terrainGenerator = new OverworldTerrainGenerator(biomeSource);

            // Then we need the location for the village in region 0, 0.
            CPos pos = village.getInRegion(seed, 0, 0, rand);

            // If we can't find one, go to the next seed.
            if (pos == null) {
                seed++;
                continue;
            }

            // Then we need to generate a village.
            boolean success = generator.generate(terrainGenerator, pos, rand);

            // If the generation was unsuccessful, we go to the next seed.
            if (!success) {
                seed++;
                continue;
            }

            // Now we need a list of chests and their loot.
            List<Pair<BPos, List<ItemStack>>> chests =
                generator.generateLoot(terrainGenerator, rand);

            for (Pair<BPos, List<ItemStack>> chest : chests) {
                int obsidian = 0;
                for (ItemStack item : chest.getSecond()) {
                    // If we find obsidian, add that to the total obsidian in this chest.
                    if (item.getItem().equals(Items.OBSIDIAN)) {
                        obsidian += item.getCount();
                    }
                }
                if (obsidian >= 10) {
                    System.out.println("Found a seed!");
                    System.out.println("Seed: " + seed);
                    System.out.println("Location: " + chest.getFirst());
                    return;
                }
            }

            // If we don't find 10 obsidian, go to the next seed.
            seed++;
            continue;
        }
    }
}
