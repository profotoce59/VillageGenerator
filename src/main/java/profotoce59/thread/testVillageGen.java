//tp 17920 80 122560 because of height map

package profotoce59.thread;

import com.seedfinding.mcbiome.source.OverworldBiomeSource;
import com.seedfinding.mccore.rand.ChunkRand;
import com.seedfinding.mccore.state.Dimension;
import com.seedfinding.mccore.util.pos.CPos;
import com.seedfinding.mccore.version.MCVersion;
import com.seedfinding.mcfeature.structure.Village;
import com.seedfinding.mcterrain.TerrainGenerator;
import profotoce59.properties.VillageGenerator;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class testVillageGen implements Runnable{
        private final int offset;
        private final int totalThreads;
        private  long startingPoint = new Random().nextLong();
        private final MCVersion version = MCVersion.v1_15;

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


                structureSeed = 192731432848353L;
                List<CPos> villePosList = new ArrayList<>();
                for (int i=0;i<400;i++)for (int j=157;j<400;j++)
                villePosList.add(ville.getInRegion(structureSeed, i, j, chunkRand));
                //CPos villePosList = new CPos(5129,4756);
                CheckWorldSeed(structureSeed, villePosList,version);
                //return;
            }
        }
        /*public boolean checkCoffre(List<ItemStack> l) {
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
        }*/

        private void CheckWorldSeed(long structureSeed, List<CPos> villePosList, MCVersion version)
        {


            structureSeed = structureSeed & 281474976710655L;
            int numGenerationSucceed = 0;
            VillageGenerator villeGen = new VillageGenerator(version);
            for(long seed = 0;seed < 1<<3;seed++) {
                long worldSeed = structureSeed | (seed<<48);
                OverworldBiomeSource bs = new OverworldBiomeSource(version, worldSeed);
                TerrainGenerator generator = TerrainGenerator.of(Dimension.OVERWORLD, bs);
                int nb = 0;
                for (CPos sPos : villePosList){
                    ChunkRand rand = new ChunkRand();

                    if(!villeGen.generate(generator, sPos.getX(),sPos.getZ(),rand,true))continue;
                    //System.out.println(nb++);
                    int numBS = villeGen.getNumberOfBlackSmith();
                    if(numBS>1){
                        System.out.println("worldSeed : " + worldSeed + " structureSeed " + structureSeed+" "+numBS+" /tp "+sPos.getX()*16+" 80 "+sPos.getZ()*16);
                    }
                    else{
                    int a = villeGen.getNumberOfHouses();
                    if(a>36) {
                        System.out.println("worldSeed : " + worldSeed + " " + a+" "+sPos.toString());
                    }
                    }
                    /*meanBS = (numGenerationSucceed*meanBS+numBS)/(numGenerationSucceed+1);
                    if(numGenerationSucceed>7 &&  meanBS<1.5){
                        break;

                    }
                    numGenerationSucceed++;*/
                }

                //else System.out.println(villeGen.getNumberOfBlackSmith());



            }

        }
    /*private void CheckWorldSeed(long structureSeed, CPos villePosC, ChunkRand chunkRand, MCVersion version, Village ville)
    {


        structureSeed = structureSeed & 281474976710655L;
        int numGenerationSucceed = 0;
        float meanBS = 0;
        for(long seed = 0;seed < 1<<13;seed++) {
            long worldSeed = structureSeed | (seed<<48);
            worldSeed = 609500824323805L;
            OverworldBiomeSource bs = new OverworldBiomeSource(version, worldSeed);
            TerrainGenerator generator = TerrainGenerator.of(Dimension.OVERWORLD, bs);
            ChunkRand rand = new ChunkRand();
            BPos villePosB = new BPos(villePosC.getX()*16,0,villePosC.getZ()*16);
            if(!(bs.getBiome(villePosB)== Biomes.TAIGA ))continue;

            VillageGenerator villeGen = new VillageGenerator(version);
            if(!villeGen.generate(generator, villePosC.getX(),villePosC.getZ(),rand))continue;

            int numBS = villeGen.getNumberOfBlackSmith();
            if(numBS>4){
                System.out.println("worldSeed : " + worldSeed + " structureSeed " + structureSeed+" "+numBS);
            }
                else{
                    villeGen.printPieces();
                }
                    /*meanBS = (numGenerationSucceed*meanBS+numBS)/(numGenerationSucceed+1);
                    if(numGenerationSucceed>7 &&  meanBS<1.5){
                        break;

                    }
                    numGenerationSucceed++;
            }

            //else System.out.println(villeGen.getNumberOfBlackSmith());



        }*/


        /*public double calculDistance(BPos spawn,CPos place) {
            int x = (place.getX()<<4) - (spawn.getX());
            int z = (place.getZ()<<4) - (spawn.getZ());
            return Math.sqrt(Math.pow(x,2)+Math.pow(z,2));
        }*/


    }
