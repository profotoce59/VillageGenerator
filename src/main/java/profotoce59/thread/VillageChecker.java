package profotoce59.thread;

import com.seedfinding.mcbiome.biome.Biomes;
import com.seedfinding.mcbiome.source.BiomeSource;
import com.seedfinding.mccore.rand.ChunkRand;
import com.seedfinding.mccore.state.Dimension;
import com.seedfinding.mccore.util.pos.BPos;
import com.seedfinding.mccore.util.pos.CPos;
import com.seedfinding.mccore.version.MCVersion;
import com.seedfinding.mcfeature.loot.item.ItemStack;
import com.seedfinding.mcfeature.structure.RuinedPortal;
import com.seedfinding.mcfeature.structure.Village;
import com.seedfinding.mcterrain.TerrainGenerator;
import profotoce59.properties.VillageGenerator;

import java.util.List;
import java.util.Random;

public class VillageChecker implements Runnable{
        private final int offset;
        private final int totalThreads;
        private final long startingPoint = new Random().nextLong();
        private final MCVersion version = MCVersion.v1_17_1;

        public VillageChecker(int offset, int totalThreads) {
            this.offset = offset;
            this.totalThreads = totalThreads;

        }
        public void run() {
            //System.out.println("Started WorldSeedThread "+(offset+1)+"/"+totalThreads);
            ChunkRand chunkRand = new ChunkRand();

            RuinedPortal ruinPortal= new RuinedPortal(Dimension.OVERWORLD, version);
            Village ville = new Village(version);
            VillageGenerator villeGen = new VillageGenerator(version);
            for (long structureSeed = startingPoint + offset; structureSeed < 1L << 48; structureSeed += this.totalThreads) {
                CPos villePos = ville.getInRegion(structureSeed, 0, 0, chunkRand);
                CPos ruinPosition = ruinPortal.getInRegion(structureSeed, 0, 0, chunkRand);
                //if(ruinPosition.getX()>8 || ruinPosition.getZ()>8)continue;
                if(Math.abs(villePos.getZ()-ruinPosition.getZ())>3 || Math.abs(villePos.getX()-ruinPosition.getX())>3)continue;
                //CPos shipPosition = ship.getInRegion(structureSeed, 0, 0 ,chunkRand);


                //System.out.println("found structureseed : " + structureSeed + ", " + ruinPosition.toBlockPos());

                CheckWorldSeed(structureSeed, villePos, chunkRand,villeGen);
                break;
            }
        }
        public boolean checkCoffre(List<ItemStack> l) {
            boolean pi = false;

            boolean axe = false;

            for (ItemStack item : l) {
                if (item.getItem().getName().equals("golden_axe")) {
                    pi = true;
                }
                else if (item.getItem().getName().equals("golden_pickaxe")) {
                    axe = true;
                }
            }
            return(pi && axe);
        }

        private void CheckWorldSeed(long structureSeed, CPos villePos, ChunkRand chunkRand, VillageGenerator villeGen )
        {

            BPos sPos = new BPos(villePos.getX()*16+7,0,villePos.getZ()*16+7);
            structureSeed = structureSeed & 281474976710655L;
            for(long seed = 0;seed < 1<<12;seed++) {
                long worldSeed = structureSeed | (seed<<48);
                BiomeSource biomeSource = BiomeSource.of(Dimension.OVERWORLD, version, worldSeed);
                TerrainGenerator generator = TerrainGenerator.of(Dimension.OVERWORLD, biomeSource);
                if(!(biomeSource.getBiome(sPos)== Biomes.PLAINS ))continue;
                System.out.println("avant le generate");
                if(!villeGen.generate(generator, villePos))continue;
                if(villeGen.getNumberOfBlackSmith()>2)System.out.println("worldSeed : " + worldSeed + " structureSeed " + structureSeed);


                //if(checker.getBlockCountInBox(Blocks.LOOM,pickleBox)==0)break;




                //alambicCount.containsValue(ENTITY)



                break;

            }
        }
        public double calculDistance(BPos spawn,CPos place) {
            int x = (place.getX()<<4) - (spawn.getX());
            int z = (place.getZ()<<4) - (spawn.getZ());
            return Math.sqrt(Math.pow(x,2)+Math.pow(z,2));
        }


    }
