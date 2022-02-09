package thread;

import kaptainwutax.biomeutils.biome.Biomes;
import kaptainwutax.biomeutils.source.OverworldBiomeSource;
import kaptainwutax.featureutils.loot.item.ItemStack;
import kaptainwutax.featureutils.structure.Village;
import kaptainwutax.mcutils.rand.ChunkRand;
import kaptainwutax.mcutils.state.Dimension;
import kaptainwutax.mcutils.util.pos.BPos;
import kaptainwutax.mcutils.util.pos.CPos;
import kaptainwutax.mcutils.version.MCVersion;
import kaptainwutax.terrainutils.TerrainGenerator;
import properties.VillageGenerator;

import java.util.List;
import java.util.Random;

public class WorldSeedThread implements Runnable{
    private final int offset;
    private final int totalThreads;
    private final MCVersion version = MCVersion.v1_17_1;
    private final long structureSeed;

    public WorldSeedThread(int offset, int totalThreads,long structureSeed) {
        this.offset = offset;
        this.totalThreads = totalThreads;
        this.structureSeed = structureSeed;
    }
        public void run() {
            //System.out.println("Started WorldSeedThread "+(offset+1)+"/"+totalThreads);
            ChunkRand chunkRand = new ChunkRand();
            Village ville = new Village(version);
            //CPos villePos = ville.getInRegion(structureSeed, 0, 0, chunkRand);
            CPos villePos = new CPos(822,388);
                //RuinedPortalProperties ruinporp = new RuinedPortalProperties(structureSeed, ruinPosition);
                //List<ItemStack> coffre = ruinporp.getLoot(chunkRand, version);
                //System.out.println("found structureseed : " + structureSeed + ", " + ruinPosition.toBlockPos());
            CheckWorldSeed(structureSeed, villePos, chunkRand,version,ville);
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

        private void CheckWorldSeed(long structureSeed, CPos villePos, ChunkRand chunkRand, MCVersion version, Village ville)
        {

            BPos sPos = new BPos(villePos.getX()*16,0,villePos.getZ()*16);
            BPos sPos1 = new BPos(villePos.getX()*16+2,0,villePos.getZ()*16-2);
            BPos sPos2 = new BPos(villePos.getX()*16-2,0,villePos.getZ()*16+2);
            BPos sPos3 = new BPos(villePos.getX()*16-2,0,villePos.getZ()*16-2);
            structureSeed = structureSeed & 281474976710655L;
            //structureSeed = -6302174073431413815L;
            int numGenerationSucceed = 0;
            float meanBS = 0;
            for(long seed = offset;seed < 1<<16;seed+=this.totalThreads) {
                long worldSeed = structureSeed | (seed<<48);
                //worldSeed = 128550363197991L;
                OverworldBiomeSource bs = new OverworldBiomeSource(version, worldSeed);
                TerrainGenerator generator = TerrainGenerator.of(Dimension.OVERWORLD, bs);
                ChunkRand rand = new ChunkRand();
                if(!(bs.getBiome(sPos2)== Biomes.TAIGA /*&& bs.getBiome(sPos1)== Biomes.TAIGA && bs.getBiome(sPos2)== Biomes.TAIGA && bs.getBiome(sPos3)== Biomes.TAIGA */))continue;
                VillageGenerator villeGen = new VillageGenerator(version);
                if(!villeGen.generate(generator, villePos.getX(),villePos.getZ(),rand))continue;
                meanBS++;
                //System.out.println(meanBS);
                int numBS = villeGen.getNumberOfBlackSmith();
                if(numBS>1){
                    System.out.println("worldSeed : " + worldSeed + " structureSeed " + structureSeed+" "+numBS);
                }
                else {
                    int a = villeGen.getNumberOfHouses();
                    if (a > 46) {
                        System.out.println("worldSeed : " + worldSeed + " " + a + " " + sPos.toString());
                    }
                }
                //meanBS = (numGenerationSucceed*meanBS+numBS)/(numGenerationSucceed+1);
                //System.out.println(numBS+"worldSeed : " + worldSeed );
                /*if(numGenerationSucceed>7 &&  meanBS<1){
                    break;

                }*/
                numGenerationSucceed++;
                //else System.out.println(villeGen.getNumberOfBlackSmith());



            }

        }
        public double calculDistance(BPos spawn,CPos place) {
            int x = (place.getX()<<4) - (spawn.getX());
            int z = (place.getZ()<<4) - (spawn.getZ());
            return Math.sqrt(Math.pow(x,2)+Math.pow(z,2));
        }


    }


