package profotoce59;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;


import java.util.List;

import com.seedfinding.mcbiome.source.OverworldBiomeSource;
import com.seedfinding.mccore.rand.ChunkRand;
import com.seedfinding.mccore.util.data.Pair;
import com.seedfinding.mccore.util.pos.BPos;
import com.seedfinding.mccore.version.MCVersion;
import com.seedfinding.mcfeature.loot.item.ItemStack;
import com.seedfinding.mcfeature.loot.item.Items;
import com.seedfinding.mcterrain.terrain.OverworldTerrainGenerator;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import profotoce59.properties.VillageGenerator;

public class LootTest {
    static MCVersion version = MCVersion.v1_16_5;
    static long seed = 1L;
    OverworldTerrainGenerator overworldTerrainGenerator;
    ChunkRand rand;

    @BeforeEach
    public void setupGeneratorAndRand(){
        OverworldBiomeSource obs = new OverworldBiomeSource(version, seed);
        overworldTerrainGenerator = new OverworldTerrainGenerator(obs);
        rand = new ChunkRand();
    }


    // Tests if chest at savannah village at chunk (12546, 2) with version 1.16.5 with seed 1 contains 2 wheat seeds, 1 saddle and 4 bread (manually checked to be true).
    @Test
    public void testSavannah(){
        VillageGenerator generator = new VillageGenerator(version);
        generator.generate(overworldTerrainGenerator, 12546, 2);
        List<Pair<BPos, List<ItemStack>>> lootList = generator.generateLoot(overworldTerrainGenerator, rand);
        Pair<BPos, List<ItemStack>> lootWithLocation = lootList.get(0);
        assertEquals(lootWithLocation.getFirst(), new BPos(200742, 70, 21));
        assertTrue(lootWithLocation.getSecond().contains(new ItemStack(Items.WHEAT_SEEDS, 2)));
        assertTrue(lootWithLocation.getSecond().contains(new ItemStack(Items.SADDLE, 1)));
        assertTrue(lootWithLocation.getSecond().contains(new ItemStack(Items.BREAD, 4)));
    }

    // Tests if chest at taiga village at chunk (12887, 12) with version 1.16.5 with seed 1 contains 1 pumpkin pie, 1 bread and 5 spruce logs (manually checked to be true).
    @Test
    public void testTaiga(){
        VillageGenerator generator = new VillageGenerator(version);
        generator.generate(overworldTerrainGenerator, 12887, 12);
        List<Pair<BPos, List<ItemStack>>> lootList = generator.generateLoot(overworldTerrainGenerator, rand);
        Pair<BPos, List<ItemStack>> lootWithLocation = lootList.get(0);
        assertEquals(lootWithLocation.getFirst(), new BPos(206186, 70, 193));
        assertTrue(lootWithLocation.getSecond().contains(new ItemStack(Items.PUMPKIN_PIE, 1)));
        assertTrue(lootWithLocation.getSecond().contains(new ItemStack(Items.BREAD, 1)));
        assertTrue(lootWithLocation.getSecond().contains(new ItemStack(Items.SPRUCE_LOG, 5)));
    }

    // Tests if chest at desert village at chunk (11383, 14) with version 1.16.5 with seed 1 contains 20 wheat, 7 bread, 1 clay ball and 6 cacti (manually checked to be true).
    @Test
    public void testDesert(){
        VillageGenerator generator = new VillageGenerator(version);
        generator.generate(overworldTerrainGenerator, 11383, 14);
        List<Pair<BPos, List<ItemStack>>> lootList = generator.generateLoot(overworldTerrainGenerator, rand);
        Pair<BPos, List<ItemStack>> lootWithLocation = lootList.get(0);
        assertEquals(lootWithLocation.getFirst(), new BPos(182131, 70, 228));
        assertTrue(lootWithLocation.getSecond().contains(new ItemStack(Items.WHEAT, 20)));
        assertTrue(lootWithLocation.getSecond().contains(new ItemStack(Items.BREAD, 7)));
        assertTrue(lootWithLocation.getSecond().contains(new ItemStack(Items.CLAY_BALL, 1)));
        assertTrue(lootWithLocation.getSecond().contains(new ItemStack(Items.CACTUS, 6)));
    }

    // Tests if chest at snowy village at chunk (30478, 9) with version 1.16.5 with seed 1 contains 1 emerald and 1 pair of leather boots (manually checked to be true).
    @Test
    public void testSnowy(){
        VillageGenerator generator = new VillageGenerator(version);
        generator.generate(overworldTerrainGenerator, 30478, 9);
        List<Pair<BPos, List<ItemStack>>> lootList = generator.generateLoot(overworldTerrainGenerator, rand);
        Pair<BPos, List<ItemStack>> lootWithLocation = lootList.get(0);
        assertEquals(lootWithLocation.getFirst(), new BPos(487651, 71, 147));
        assertTrue(lootWithLocation.getSecond().contains(new ItemStack(Items.LEATHER_BOOTS, 1)));
        assertTrue(lootWithLocation.getSecond().contains(new ItemStack(Items.EMERALD, 1)));
    }

    // Tests if chest at Plains village at chunk (30509, 1) with version 1.16.5 with seed 1 contains 4 apples and 8 potatoes (manually checked to be true).
    @Test
    public void testPlains(){
        VillageGenerator generator = new VillageGenerator(version);
        generator.generate(overworldTerrainGenerator, 30509, 1);
        List<Pair<BPos, List<ItemStack>>> lootList = generator.generateLoot(overworldTerrainGenerator, rand);
        Pair<BPos, List<ItemStack>> lootWithLocation = lootList.get(0);
        assertEquals(lootWithLocation.getFirst(), new BPos(488158, 66, 17));
        assertTrue(lootWithLocation.getSecond().contains(new ItemStack(Items.APPLE, 4)));
        assertTrue(lootWithLocation.getSecond().contains(new ItemStack(Items.POTATO, 8)));
    }
}
