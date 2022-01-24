package thread;

import kaptainwutax.biomeutils.biome.Biome;
import kaptainwutax.biomeutils.biome.Biomes;
import kaptainwutax.biomeutils.source.BiomeSource;
import kaptainwutax.biomeutils.source.OverworldBiomeSource;
import kaptainwutax.featureutils.loot.item.ItemStack;
import kaptainwutax.featureutils.structure.RuinedPortal;
import kaptainwutax.featureutils.structure.Village;
import kaptainwutax.mcutils.rand.ChunkRand;
import kaptainwutax.mcutils.state.Dimension;
import kaptainwutax.mcutils.util.pos.BPos;
import kaptainwutax.mcutils.util.pos.CPos;
import kaptainwutax.mcutils.version.MCVersion;
import properties.RuinedPortalProperties;
import properties.VillageGenerator;
import kaptainwutax.terrainutils.TerrainGenerator;

import java.util.List;
import java.util.Random;

public class testVillageGen implements Runnable{
        private final int offset;
        private final int totalThreads;
        private  long startingPoint = new Random().nextLong();
        private final MCVersion version = MCVersion.v1_16_1;

        public testVillageGen(int offset, int totalThreads) {
            this.offset = offset;
            this.totalThreads = totalThreads;
            this.startingPoint = (this.startingPoint) & 281474976710655L;
        }
        public void run() {
            //System.out.println("Started WorldSeedThread "+(offset+1)+"/"+totalThreads);
            ChunkRand chunkRand = new ChunkRand();


            Village ville = new Village(version);
            for (long structureSeed = startingPoint + offset; structureSeed < 1L << 48; structureSeed += this.totalThreads) {


                //structureSeed = 21087268964786395L;

                CPos villePos = ville.getInRegion(structureSeed, 0, 0, chunkRand);
                //RuinedPortalProperties ruinporp = new RuinedPortalProperties(structureSeed, ruinPosition);
                //List<ItemStack> coffre = ruinporp.getLoot(chunkRand, version);
                //System.out.println("found structureseed : " + structureSeed + ", " + ruinPosition.toBlockPos());
                CheckWorldSeed(structureSeed, villePos, chunkRand,version,ville);
                //return;
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

        private void CheckWorldSeed(long structureSeed, CPos villePos, ChunkRand chunkRand, MCVersion version, Village ville)
        {

            BPos sPos = new BPos(villePos.getX()*16+7,0,villePos.getZ()*16+7);
            structureSeed = structureSeed & 281474976710655L;
            int numGenerationSucceed = 0;
            float meanBS = 0;
            for(long seed = 0;seed < 1<<14;seed++) {
                long worldSeed = structureSeed | (seed<<48);
                //worldSeed = 21087268964786395L;
                OverworldBiomeSource bs = new OverworldBiomeSource(version, worldSeed);
                TerrainGenerator generator = TerrainGenerator.of(Dimension.OVERWORLD, bs);
                ChunkRand rand = new ChunkRand();
                if(!(bs.getBiome(sPos)== Biomes.TAIGA ))continue;
                VillageGenerator villeGen = new VillageGenerator(version);
                if(!villeGen.generate(generator, villePos.getX(),villePos.getZ(),rand))continue;

                int numBS = villeGen.getNumberOfBlackSmith();
                if(numBS>3){
                    System.out.println("worldSeed : " + worldSeed + " structureSeed " + structureSeed+" "+numBS);
                }
                /*else{
                    villeGen.printPieces();
                }*/
                meanBS = (numGenerationSucceed*meanBS+numBS)/(numGenerationSucceed+1);
                if(numGenerationSucceed>7 &&  meanBS<1){
                        break;

                }
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
