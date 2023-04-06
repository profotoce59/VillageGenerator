package profotoce59.thread;


import com.seedfinding.mcbiome.biome.Biomes;
import com.seedfinding.mcbiome.source.OverworldBiomeSource;
import com.seedfinding.mccore.rand.ChunkRand;
import com.seedfinding.mccore.state.Dimension;
import com.seedfinding.mccore.util.pos.BPos;
import com.seedfinding.mccore.util.pos.CPos;
import com.seedfinding.mccore.version.MCVersion;
import com.seedfinding.mcfeature.loot.item.ItemStack;
import com.seedfinding.mcfeature.structure.Village;
import com.seedfinding.mcterrain.TerrainGenerator;
import profotoce59.properties.VillageGenerator;

import java.util.List;

public class WorldSeedThread implements Runnable{
    private final int offset;
    private final int totalThreads;
    private final MCVersion version = MCVersion.v1_16_4;
    private final long structureSeed;
    private final BPos villePos;

    public WorldSeedThread(int offset, int totalThreads, long structureSeed, BPos bpos) {
        this.offset = offset;
        this.totalThreads = totalThreads;
        this.structureSeed = structureSeed;
        villePos = new BPos(bpos);
    }
        public void run() {
            //System.out.println("Started WorldSeedThread "+(offset+1)+"/"+totalThreads);
            ChunkRand chunkRand = new ChunkRand();
            Village ville = new Village(version);
            //CPos villePos = ville.getInRegion(structureSeed, 0, 0, chunkRand);
            //CPos villePos = new CPos(5,10);
                //RuinedPortalProperties ruinporp = new RuinedPortalProperties(structureSeed, ruinPosition);
                //List<ItemStack> coffre = ruinporp.getLoot(chunkRand, version);
                //System.out.println("found structureseed : " + structureSeed + ", " + ruinPosition.toBlockPos());
            CheckWorldSeed(structureSeed, chunkRand,version,ville);
                //return;
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

        private void CheckWorldSeed(long structureSeed,  ChunkRand chunkRand, MCVersion version, Village ville)
        {


            BPos sPos1 = new BPos(villePos.getX()+2,0,villePos.getZ()-2);
            BPos sPos2 = new BPos(villePos.getX()-2,0,villePos.getZ()+2);
            BPos sPos3 = new BPos(villePos.getX()-2,0,villePos.getZ()-2);
            structureSeed = structureSeed & 281474976710655L;
            //structureSeed = -6302174073431413815L;
            int numGenerationSucceed = 0;
            float meanBS = 0;
            for(long seed = offset;seed < 1<<15;seed+=this.totalThreads) {
                long worldSeed = structureSeed | (seed<<48);
                worldSeed = 875524051741357L;
                OverworldBiomeSource bs = new OverworldBiomeSource(version, worldSeed);
                TerrainGenerator generator = TerrainGenerator.of(Dimension.OVERWORLD, bs);
                ChunkRand rand = new ChunkRand();
                if(!(bs.getBiome(villePos)== Biomes.SNOWY_TUNDRA /*&& bs.getBiome(sPos1)== Biomes.TAIGA && bs.getBiome(sPos2)== Biomes.TAIGA && bs.getBiome(sPos3)== Biomes.TAIGA */))continue;
                VillageGenerator villeGen = new VillageGenerator(version);
                if(!villeGen.generate(generator, villePos.getX()/16,villePos.getZ()/16,rand))continue;
                meanBS++;
                //System.out.println(meanBS);
                int numBS = villeGen.getNumberOfBlackSmith();
                if(numBS>8){
                    System.out.println("worldSeed : " + worldSeed + " structureSeed " + villePos.toString()+" "+numBS);
                }
                /*else {
                    int a = villeGen.getNumberOfHouses();
                    if (a > 46) {
                        System.out.println("worldSeed : " + worldSeed + " " + a + " " + villePos.toString());
                    }
                }*/
                //meanBS = (numGenerationSucceed*meanBS+numBS)/(numGenerationSucceed+1);
                //System.out.println(numBS+"worldSeed : " + worldSeed );
                /*if(numGenerationSucceed>7 &&  meanBS<1){
                    break;

                }*/

                numGenerationSucceed++;
                break;
                //else System.out.println(villeGen.getNumberOfBlackSmith());



            }

        }
        public double calculDistance(BPos spawn, CPos place) {
            int x = (place.getX()<<4) - (spawn.getX());
            int z = (place.getZ()<<4) - (spawn.getZ());
            return Math.sqrt(Math.pow(x,2)+Math.pow(z,2));
        }


    }


