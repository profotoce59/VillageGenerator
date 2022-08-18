import java.util.List;
import kaptainwutax.biomeutils.source.OverworldBiomeSource;
import kaptainwutax.featureutils.loot.LootTable;
import kaptainwutax.featureutils.loot.item.ItemStack;
import kaptainwutax.featureutils.structure.Village;
import kaptainwutax.mcutils.rand.ChunkRand;
import kaptainwutax.mcutils.util.data.Pair;
import kaptainwutax.mcutils.util.data.Triplet;
import kaptainwutax.mcutils.util.pos.BPos;
import kaptainwutax.mcutils.util.pos.CPos;
import kaptainwutax.mcutils.version.MCVersion;
import kaptainwutax.terrainutils.terrain.OverworldTerrainGenerator;
import properties.VillageGenerator;

public class VillageLootTest {
    public static void main(String[] args) {
        OverworldBiomeSource obs = new OverworldBiomeSource(MCVersion.v1_16_5, 1L);
        OverworldTerrainGenerator otg = new OverworldTerrainGenerator(obs);
        VillageGenerator generator = new VillageGenerator(MCVersion.v1_16_5);
        Village village = new Village(MCVersion.v1_16_5);
        CPos found = null;
        int x = 0;
        while(found == null){
            CPos pos = village.getInRegion(1L, x, 0, new ChunkRand());
            if(village.canSpawn(pos, obs)&&village.canGenerate(pos, otg)){
                found = pos;
            }
            x++;
        }
        generator.generate(otg, found);
        List<Pair<BPos, List<ItemStack>>> list = generator.generateLoot(otg, new ChunkRand());
        list.forEach(y -> System.out.println(y.getFirst() + ", " + y.getSecond().size()));
    }
}
