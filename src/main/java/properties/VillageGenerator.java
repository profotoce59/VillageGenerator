package properties;

import kaptainwutax.biomeutils.biome.Biome;
import kaptainwutax.biomeutils.biome.Biomes;
import kaptainwutax.featureutils.structure.generator.Generator;
import kaptainwutax.mcutils.block.Block;
import kaptainwutax.mcutils.block.Blocks;
import kaptainwutax.mcutils.rand.ChunkRand;
import kaptainwutax.mcutils.util.block.BlockBox;
import kaptainwutax.mcutils.util.block.BlockDirection;
import kaptainwutax.mcutils.util.block.BlockMirror;
import kaptainwutax.mcutils.util.block.BlockRotation;
import kaptainwutax.mcutils.util.data.Pair;
import kaptainwutax.mcutils.util.data.Quad;
import kaptainwutax.mcutils.util.data.Triplet;
import kaptainwutax.mcutils.util.pos.BPos;
import kaptainwutax.mcutils.util.pos.CPos;
import kaptainwutax.mcutils.version.MCVersion;
import kaptainwutax.seedutils.rand.JRand;
import kaptainwutax.terrainutils.TerrainGenerator;
import kaptainwutax.terrainutils.utils.NoiseSettings;
import reecriture.*;
import reecriture.VillagePools.*;

import java.util.*;
import java.util.stream.Collectors;

public class VillageGenerator extends Generator {
    public List<Piece> pieces;
    private VillageType villageType;
    public VillageGenerator(MCVersion version) {
        super(version);
    }
    public boolean generate(TerrainGenerator generator, int chunkX, int chunkZ, ChunkRand rand,Biome biomeWanted) {
        Biome biome = generator.getBiomeSource().getBiomeForNoiseGen((chunkX << 2) + 2, 0, (chunkZ << 2) + 2);
        if(!biomeWanted.equals(biome))return false;
        else return this.generate(generator,chunkX,chunkZ,rand);
    }
    @Override
    public boolean generate(TerrainGenerator generator, int chunkX, int chunkZ, ChunkRand rand) {
        Biome biome = generator.getBiomeSource().getBiomeForNoiseGen((chunkX << 2) + 2, 0, (chunkZ << 2) + 2);
        this.villageType = VillageType.getType(biome, generator.getVersion());
        if(this.villageType == null)return false;
        pieces = new ArrayList<>();
        rand = rand.asChunkRandDebugger();

        rand.setCarverSeed(generator.getWorldSeed(), chunkX, chunkZ, generator.getVersion());
        BlockRotation rotation = BlockRotation.getRandom(rand);

        // compute the template

        JigSawPool jigSawPool = STARTS.get(villageType);
        String template = rand.getRandom(jigSawPool.getTemplates());
        //if(!template.equals("taiga/town_centers/taiga_meeting_point_2"))return false;  //to get the max number of street
        //must be optional to be reusable
        BPos size = STRUCTURE_SIZE.get(template);
        BPos bPos = new CPos(chunkX, chunkZ).toBlockPos(0);
        BlockBox box = BlockBox.getBoundingBox(bPos, rotation, BPos.ORIGIN, BlockMirror.NONE, size);
        int centerX = (box.minX + box.maxX) / 2;
        int centerZ = (box.minZ + box.maxZ) / 2;
        int y = bPos.getY() + generator.getFirstHeightInColumn(centerX,centerZ,TerrainGenerator.WORLD_SURFACE_WG);
        int centerY = box.minY + 1;

        // create the first piece (always rigid)
        Piece piece = new Piece(template, bPos, box, rotation, PlacementBehaviour.RIGID,0);
        piece.move(0, y - centerY, 0);
        piece.setBoundsTop(y + 80);
        BlockBox fullBox = new BlockBox(centerX - 80, y - 80, centerZ - 80, centerX + 80 + 1, y + 80 + 1, centerZ + 80 + 1);
        Assembler assembler = new Assembler(6, generator,this.pieces);
        VoxelShape a = new VoxelShape(fullBox);
        a.fullBoxes.add(new BlockBox(box.minX,box.minY,box.minZ,box.maxX+1,box.maxY+1,box.maxZ+1));
        piece.voxelShape = a;
        assembler.placing.addLast(piece);
        while(!assembler.placing.isEmpty()) {
            assembler.tryPlacing(villageType, assembler.placing.removeFirst(), rand, true);
        }
        return true;
    }

    public void printPieces() {
        for (Piece piece :pieces){
            System.out.println(piece.name + " "+piece.pos.toString());
        }
    }
    public List<Piece> getPieces() {
        return this.pieces;
    }


    static public class Piece {
        String name;
        BPos pos;
        BlockBox box;
        BlockRotation rotation;
        int boundsTop;
        PlacementBehaviour placementBehaviour;
        private VoxelShape voxelShape;
        int depth;

        Piece(String name, BPos pos, BlockBox box, BlockRotation rotation, PlacementBehaviour placementBehaviour,int depth) {
            this.name = name;
            this.pos = pos;
            this.box = box;
            this.rotation = rotation;
            this.placementBehaviour = placementBehaviour;
            this.voxelShape = new VoxelShape(box);
            this.depth = depth;
        }

        public void move(int x, int y, int z) {
            box.move(x, y, z);
            pos = pos.add(x, y, z);
        }

        public void setBoundsTop(int boundsTop) {
            this.boundsTop = boundsTop;
        }

        public List<BlockJigsawInfo> getShuffledJigsawBlocks(VillageType villageType, BPos offset, JRand rand) {

            List<Pair<Quad<String, String, Pair<BlockDirection,BlockDirection>, Block>, BPos>> defaultValue = Collections.singletonList(
                    new Pair<>(new Quad<>("empty", "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH) ,Blocks.STRUCTURE_VOID),new BPos(0,0,0))
            );
            List<Pair<Quad<String, String, Pair<BlockDirection,BlockDirection>, Block>, BPos>> blocks = villageType.getJigsawBlocks().getOrDefault(this.name,defaultValue);

            List<BlockJigsawInfo> list = new ArrayList<>();
            for (Pair<Quad<String, String, Pair<BlockDirection, BlockDirection>, Block>, BPos> b : blocks) {
                BlockJigsawInfo blockJigsawInfo = new BlockJigsawInfo(b.getFirst()
                        , b.getSecond().transform(BlockMirror.NONE, rotation, BPos.ORIGIN).add(offset), rotation);
                list.add(blockJigsawInfo);
            }
            rand.shuffle(list);
            return list;

        }

        public void setVoxelShape(VoxelShape mutableobject1) {
            this.voxelShape = mutableobject1;
        }
        public VoxelShape getVoxelShape() {
            return this.voxelShape;
        }
    }

    public static class BlockJigsawInfo {
        Quad<String, String, Pair<BlockDirection,BlockDirection>, Block> nbt;
        BPos pos;
        BlockRotation rotation;
        public BlockJigsawInfo(Quad<String, String, Pair<BlockDirection,BlockDirection>, Block> nbt, BPos pos, BlockRotation rotation) {
            // nbt is stored as pool,name,orientation,final_state
            this.nbt = nbt;
            this.pos = pos;
            this.rotation = rotation;

        }

        public BlockDirection getFront() {//il aime pas cette fonction
            return rotation.rotate(this.nbt.getThird().getFirst());
        }
        public BlockDirection getOpposite(BlockDirection b){
            switch (b) {
                case NORTH:
                    return BlockDirection.SOUTH;
                case SOUTH:
                    return BlockDirection.NORTH;
                case WEST:
                    return BlockDirection.EAST;
                case EAST:
                    return BlockDirection.WEST;
                case DOWN:
                    return BlockDirection.UP;
                case UP:
                    return BlockDirection.DOWN;
                default:
                    throw new IllegalStateException("Unable to get facing of " );
            }
        }

        public boolean canAttach(BlockJigsawInfo blockJigsawInfo2,BlockDirection direction) {

            if(!this.nbt.getSecond().equals(blockJigsawInfo2.nbt.getSecond())){//opti
                return false;
            }
            BlockDirection direction2 = blockJigsawInfo2.getFront();
            BlockDirection direction2b = this.getOpposite(direction2);
            if(!direction.equals(direction2b)){//opti
                return false;
            }
            BlockDirection direction3 = this.getFace();
            BlockDirection direction4 = blockJigsawInfo2.getFace();
            boolean isROLLABLE = (direction.getAxis().ordinal())%2==1;
            return (isROLLABLE || direction4 == direction3);

        }

        private BlockDirection getFace() {
            return rotation.rotate(this.nbt.getThird().getSecond());
        }
    }

    public static class Assembler {
        int maxDepth;
        TerrainGenerator generator;
        List<Piece> pieces;
        SurfaceGenerator2 sGen;

        private final Deque<Piece> placing = new ArrayDeque<>();
        Assembler(int maxDepth, TerrainGenerator generator,List<Piece> pieces) {
            this.maxDepth = maxDepth;
            this.generator = generator;
            this.pieces = pieces;
            //must be switchable between normal surface generator and fastSurfaceGenerator
            //here this is the fast one
            this.sGen = new SurfaceGenerator2(generator.getBiomeSource(), 256, 1, 2,
                    NoiseSettings.create(0.9999999814507745, 0.9999999814507745, 80.0, 160.0)
                            .addTopSlide(-10, 3, 0)
                            .addBottomSlide(-30, 0, 0),
                    1.0D, -0.46875D, true,13);
            /* ------- //13 -> 13*8 = 104 si le village est plus que 104, il y aura une mauvaise gen, mais permet d'optimiser de beaucoup.*/
        }

        public void tryPlacing(VillageType villageType, Piece piece, ChunkRand rand, boolean expansionHack) {
            int depth = piece.depth;
            BPos pos = piece.pos;
            PlacementBehaviour placementBehaviour = piece.placementBehaviour;
            boolean isRigid = placementBehaviour == PlacementBehaviour.RIGID;
            VoxelShape mutableobject = new VoxelShape();
            BlockBox box = piece.box;
            int minY = box.minY;
            label139:

            for (BlockJigsawInfo blockJigsawInfo : piece.getShuffledJigsawBlocks(villageType, pos, rand)) {
                BlockDirection blockDirection = blockJigsawInfo.getFront();
                BPos blockPos = blockJigsawInfo.pos;
                BPos relativeBlockPos = new BPos(blockPos.getX() + blockDirection.getVector().getX(),
                        blockPos.getY() + blockDirection.getVector().getY(),
                        blockPos.getZ() + blockDirection.getVector().getZ()); //erreur in relative with vector.getZ
                int y = blockPos.getY() - minY;
                int state = -1;
                Triplet<String, List<Pair<String, Integer>>, PlacementBehaviour> pool = villageType.getPool().get(blockJigsawInfo.nbt.getFirst());
                if (pool != null && pool.getSecond().size() != 0) {
                    String fallbackLocation = pool.getFirst();
                    Triplet<String, List<Pair<String, Integer>>, PlacementBehaviour> fallbackPool = villageType.getPool().get(fallbackLocation);
                    if (fallbackPool != null && fallbackPool.getSecond().size() != 0) {
                        JigSawPool jigSawPool1 = new JigSawPool(pool.getSecond());
                        JigSawPool jigSawPool2 = new JigSawPool(fallbackPool.getSecond());
                        boolean isInside = box.contains(relativeBlockPos);
                        VoxelShape mutableobject1;
                        if (isInside) {
                            mutableobject1 = mutableobject;
                            if (mutableobject.isNull()) {
                                mutableobject.setValue(box,true);

                            }
                        } else {
                            mutableobject1 = piece.getVoxelShape();
                        }
                        LinkedList<String> list = new LinkedList<>();

                        if (depth != this.maxDepth) {
                            list = jigSawPool1.getTemplates();
                            if(list.size() !=0) {
                                rand.shuffle(list);
                                rand.advance(1);
                            }
                        }
                        LinkedList<String> listtmp = jigSawPool2.getTemplates();
                        if(listtmp.size() !=0) {
                            rand.shuffle(listtmp);
                            rand.advance(1);
                        }
                            list.addAll(listtmp);

                        for (String jigsawpiece1 : list) {
                            //2700 passages
                            if (jigsawpiece1.equals("empty")){
                                break;
                            }


                            for (BlockRotation rotation1 : BlockRotation.getShuffled(rand) ) {
                                //10k passages
                                BPos size1 = STRUCTURE_SIZE.get(jigsawpiece1);
                                 //le retirer plus tard on s'en fou des villageois
                                BlockBox box1;
                                if(size1 == null){
                                    box1 = new BlockBox(0,0,0,0,0,0);
                                }
                                else {
                                    box1 = BlockBox.getBoundingBox(BPos.ORIGIN, rotation1, BPos.ORIGIN, BlockMirror.NONE, size1);
                                }
                                Piece piece1 = new Piece(jigsawpiece1, BPos.ORIGIN, box1, rotation1, pool.getThird(),0);
                                List<BlockJigsawInfo> list1 = piece1.getShuffledJigsawBlocks(villageType, BPos.ORIGIN, rand);
                                int i1;
                                if (expansionHack && box1.getYSpan() <= 16) {
                                    i1 = list1.stream().mapToInt((p_242841_2_) -> {
                                        BlockDirection dirtmp = p_242841_2_.getFront();
                                        BPos relativetmp = new BPos(p_242841_2_.pos.getX() + dirtmp.getVector().getX(),
                                                p_242841_2_.pos.getY() + dirtmp.getVector().getY(),
                                                p_242841_2_.pos.getZ() + dirtmp.getVector().getZ());
                                        if (!box1.contains(relativetmp)) {
                                            return 0;
                                        } else {//36k passages optimized
                                            int k3;
                                            int l3;
                                                k3 = VillagePoolYMax.Y_MAX.get(p_242841_2_.nbt.getFirst());
                                                String fallbackLocation2 = villageType.getPool().get(p_242841_2_.nbt.getFirst()).getFirst();
                                                l3 = VillagePoolYMax.Y_MAX.get(fallbackLocation2);
                                            return Math.max(k3, l3);

                                        }

                                    }).max().orElse(0);

                                } else {
                                    i1 = 0;
                                }

                                BlockDirection direction = blockJigsawInfo.getFront();
                                for (BlockJigsawInfo blockJigsawInfo2 : list1) {//55k passages
                                    if (blockJigsawInfo.canAttach(blockJigsawInfo2,direction)) {
                                        //5000 passages
                                        BPos blockPos3 = blockJigsawInfo2.pos;
                                        BPos blockPos4 = new BPos(relativeBlockPos.getX() - blockPos3.getX(),
                                                relativeBlockPos.getY() - blockPos3.getY(), relativeBlockPos.getZ() - blockPos3.getZ());
                                        BlockBox box2;
                                        if(size1 == null){
                                            box2 = new BlockBox(blockPos4.getX(),blockPos4.getY(),blockPos4.getZ(),blockPos4.getX(),
                                                    blockPos4.getY(),blockPos4.getZ());
                                        }
                                        else {
                                            box2 = BlockBox.getBoundingBox(blockPos4, rotation1, BPos.ORIGIN, BlockMirror.NONE, size1);
                                        }
                                        int j1 = box2.minY;
                                        boolean flag2 = piece1.placementBehaviour == PlacementBehaviour.RIGID;
                                        int k1 = blockPos3.getY();
                                        int l1 = y - k1 + blockJigsawInfo.getFront().getVector().getY();
                                        int i2;
                                        if (isRigid && flag2) {
                                            i2 = minY + l1;
                                        } else {
                                            if (state == -1) {
                                                //int state1 = this.generator.getFirstHeightInColumn(blockPos.getX(), blockPos.getZ(),(block) -> block != Blocks.AIR);
                                                state = this.sGen.generateColumnfromY(blockPos.getX(), blockPos.getZ(),(block) -> block != Blocks.AIR);
                                            }
                                            i2 = state - k1;
                                        }
                                        int j2 = i2 - j1;
                                        BlockBox box3 = new BlockBox(box2.minX,box2.minY,box2.minZ,box2.maxX,box2.maxY,box2.maxZ);
                                        box3.move(0, j2, 0);
                                        BPos blockpos5 = blockPos4.add(0, j2, 0);
                                        if (i1 > 0) {
                                            int k2 = Math.max(i1 + 1, box3.maxY - box3.minY);
                                            box3.maxY = box3.minY + k2;
                                        }
                                        if (isNotEmpty(mutableobject1,box3)) {
                                            mutableobject1.fullBoxes.add(new BlockBox(box3.minX,box3.minY,box3.minZ,
                                                    box3.maxX+1,box3.maxY+1,box3.maxZ+1));
                                            Piece piece2 = new Piece(jigsawpiece1,blockpos5,box3,rotation1,piece1.placementBehaviour,depth+1);
                                            if(depth+1<= this.maxDepth){
                                                this.pieces.add(piece2);
                                                piece2.setVoxelShape(mutableobject1);
                                                this.placing.addLast(piece2);
                                            }
                                            continue label139;
                                        }


                                    }
                                }
                            }


                        }
                    }
                }


            }
        }
        private boolean isNotEmpty(VoxelShape voxelShape,BlockBox box1) {
            if(box1.minX<voxelShape.getX().get(0) || box1.minY<voxelShape.getY().get(0) || box1.minZ<voxelShape.getZ().get(0)
                    || box1.maxX>=voxelShape.getLastX() || box1.maxY>=voxelShape.getLastY() || box1.maxZ>=voxelShape.getLastZ()
        )return false;
            for (BlockBox fullBoxe: voxelShape.fullBoxes){
                if(intersects2(box1,fullBoxe)){
                    return false;
                }
            }
            return true;

        }
        public boolean intersects2(BlockBox box1,BlockBox box) {
            return box1.maxX >= box.minX && box1.minX < box.maxX && box1.maxZ >= box.minZ && box1.minZ < box.maxZ && box1.maxY >= box.minY && box1.minY < box.maxY;
        }
    }

    @Override
    public List<Pair<ILootType, BPos>> getLootPos() {
        return getChestsPos();
    }

    @Override
    public List<Pair<ILootType, BPos>> getChestsPos() {
        return null;
    }

    @Override
    public ILootType[] getLootTypes() {
        return new ILootType[0];
    }

    public int getNumberOfBlackSmith(){
        int nb = 0;
        for (Piece piece : this.pieces){
            if(piece.name.equals(villageType.getBlackSmithName()))nb++;
        }
        return nb;
    }
    public int getNumberOfHouses(){
        int nb = 0;
        for (Piece piece : this.pieces) {
            if (piece.name.length() > 21) {
                String pieceName = piece.name.substring(0,20);
                if (pieceName.equals(villageType.getHouseName())) nb++;
            }
        }
        return nb;
    }

    public enum PlacementBehaviour {
        RIGID,
        TERRAIN_MATCHING,
    }
    //put that in another Folder
    private static final HashMap<String, BPos> STRUCTURE_SIZE = new HashMap<>() {{
        this.put("common/iron_golem", new BPos(1, 3, 1));
        this.put("common/well_bottom", new BPos(4, 3, 4));
        this.put("common/animals/cat_black", new BPos(1, 3, 1));
        this.put("common/animals/cat_british", new BPos(1, 3, 1));
        this.put("common/animals/cat_calico", new BPos(1, 3, 1));
        this.put("common/animals/cat_jellie", new BPos(1, 3, 1));
        this.put("common/animals/cat_persian", new BPos(1, 3, 1));
        this.put("common/animals/cat_ragdoll", new BPos(1, 3, 1));
        this.put("common/animals/cat_red", new BPos(1, 3, 1));
        this.put("common/animals/cat_siamese", new BPos(1, 3, 1));
        this.put("common/animals/cat_tabby", new BPos(1, 3, 1));
        this.put("common/animals/cat_white", new BPos(1, 3, 1));
        this.put("common/animals/cows_1", new BPos(1, 3, 1));
        this.put("common/animals/horses_1", new BPos(1, 3, 1));
        this.put("common/animals/horses_2", new BPos(1, 3, 1));
        this.put("common/animals/horses_3", new BPos(1, 3, 1));
        this.put("common/animals/horses_4", new BPos(1, 3, 1));
        this.put("common/animals/horses_5", new BPos(1, 3, 1));
        this.put("common/animals/pigs_1", new BPos(1, 3, 1));
        this.put("common/animals/sheep_1", new BPos(1, 3, 1));
        this.put("common/animals/sheep_2", new BPos(1, 3, 1));
        this.put("decays/grass_11x13", new BPos(13, 1, 11));
        this.put("decays/grass_16x16", new BPos(16, 1, 16));
        this.put("decays/grass_9x9", new BPos(9, 1, 9));
        this.put("desert/desert_lamp_1", new BPos(1, 4, 1));
        this.put("desert/houses/desert_animal_pen_1", new BPos(10, 6, 7));
        this.put("desert/houses/desert_animal_pen_2", new BPos(10, 6, 8));
        this.put("desert/houses/desert_armorer_1", new BPos(7, 7, 7));
        this.put("desert/houses/desert_butcher_shop_1", new BPos(8, 5, 8));
        this.put("desert/houses/desert_cartographer_house_1", new BPos(7, 7, 7));
        this.put("desert/houses/desert_farm_1", new BPos(5, 6, 7));
        this.put("desert/houses/desert_farm_2", new BPos(7, 7, 10));
        this.put("desert/houses/desert_fisher_1", new BPos(8, 6, 11));
        this.put("desert/houses/desert_fletcher_house_1", new BPos(6, 12, 12));
        this.put("desert/houses/desert_large_farm_1", new BPos(11, 7, 13));
        this.put("desert/houses/desert_library_1", new BPos(9, 7, 5));
        this.put("desert/houses/desert_mason_1", new BPos(7, 5, 8));
        this.put("desert/houses/desert_medium_house_1", new BPos(6, 6, 7));
        this.put("desert/houses/desert_medium_house_2", new BPos(11, 9, 7));
        this.put("desert/houses/desert_shepherd_house_1", new BPos(11, 6, 5));
        this.put("desert/houses/desert_small_house_1", new BPos(6, 6, 5));
        this.put("desert/houses/desert_small_house_2", new BPos(7, 6, 5));
        this.put("desert/houses/desert_small_house_3", new BPos(5, 5, 6));
        this.put("desert/houses/desert_small_house_4", new BPos(5, 5, 5));
        this.put("desert/houses/desert_small_house_5", new BPos(5, 6, 6));
        this.put("desert/houses/desert_small_house_6", new BPos(6, 18, 5));
        this.put("desert/houses/desert_small_house_7", new BPos(8, 5, 7));
        this.put("desert/houses/desert_small_house_8", new BPos(5, 5, 5));
        this.put("desert/houses/desert_tannery_1", new BPos(7, 10, 6));
        this.put("desert/houses/desert_temple_1", new BPos(11, 7, 10));
        this.put("desert/houses/desert_temple_2", new BPos(10, 6, 12));
        this.put("desert/houses/desert_tool_smith_1", new BPos(9, 9, 9));
        this.put("desert/houses/desert_weaponsmith_1", new BPos(10, 6, 7));
        this.put("desert/streets/corner_01", new BPos(7, 2, 15));
        this.put("desert/streets/corner_02", new BPos(6, 2, 6));
        this.put("desert/streets/crossroad_01", new BPos(18, 2, 15));
        this.put("desert/streets/crossroad_02", new BPos(11, 2, 11));
        this.put("desert/streets/crossroad_03", new BPos(5, 2, 5));
        this.put("desert/streets/square_01", new BPos(13, 2, 28));
        this.put("desert/streets/square_02", new BPos(16, 2, 19));
        this.put("desert/streets/straight_01", new BPos(15, 2, 12));
        this.put("desert/streets/straight_02", new BPos(15, 2, 18));
        this.put("desert/streets/straight_03", new BPos(4, 2, 3));
        this.put("desert/streets/turn_01", new BPos(4, 2, 4));
        this.put("desert/terminators/terminator_01", new BPos(3, 2, 3));
        this.put("desert/terminators/terminator_02", new BPos(3, 2, 3));
        this.put("desert/town_centers/desert_meeting_point_1", new BPos(17, 6, 9));
        this.put("desert/town_centers/desert_meeting_point_2", new BPos(12, 6, 12));
        this.put("desert/town_centers/desert_meeting_point_3", new BPos(15, 6, 15));
        this.put("desert/villagers/baby", new BPos(1, 2, 1));
        this.put("desert/villagers/nitwit", new BPos(1, 3, 1));
        this.put("desert/villagers/unemployed", new BPos(1, 3, 1));
        this.put("desert/zombie/houses/desert_medium_house_1", new BPos(6, 6, 7));
        this.put("desert/zombie/houses/desert_medium_house_2", new BPos(11, 9, 7));
        this.put("desert/zombie/houses/desert_small_house_1", new BPos(6, 6, 5));
        this.put("desert/zombie/houses/desert_small_house_2", new BPos(7, 6, 5));
        this.put("desert/zombie/houses/desert_small_house_3", new BPos(5, 5, 6));
        this.put("desert/zombie/houses/desert_small_house_4", new BPos(5, 5, 5));
        this.put("desert/zombie/houses/desert_small_house_5", new BPos(5, 6, 6));
        this.put("desert/zombie/houses/desert_small_house_6", new BPos(5, 17, 5));
        this.put("desert/zombie/houses/desert_small_house_7", new BPos(8, 5, 7));
        this.put("desert/zombie/houses/desert_small_house_8", new BPos(5, 5, 5));
        this.put("desert/zombie/streets/corner_01", new BPos(7, 2, 15));
        this.put("desert/zombie/streets/corner_02", new BPos(6, 2, 6));
        this.put("desert/zombie/streets/crossroad_01", new BPos(18, 2, 15));
        this.put("desert/zombie/streets/crossroad_02", new BPos(11, 2, 11));
        this.put("desert/zombie/streets/crossroad_03", new BPos(5, 2, 5));
        this.put("desert/zombie/streets/square_01", new BPos(13, 2, 28));
        this.put("desert/zombie/streets/square_02", new BPos(16, 2, 19));
        this.put("desert/zombie/streets/straight_01", new BPos(15, 2, 12));
        this.put("desert/zombie/streets/straight_02", new BPos(15, 2, 18));
        this.put("desert/zombie/streets/straight_03", new BPos(4, 2, 3));
        this.put("desert/zombie/streets/turn_01", new BPos(4, 2, 4));
        this.put("desert/zombie/terminators/terminator_02", new BPos(3, 2, 3));
        this.put("desert/zombie/town_centers/desert_meeting_point_1", new BPos(17, 6, 9));
        this.put("desert/zombie/town_centers/desert_meeting_point_2", new BPos(12, 6, 12));
        this.put("desert/zombie/town_centers/desert_meeting_point_3", new BPos(15, 6, 15));
        this.put("desert/zombie/villagers/nitwit", new BPos(1, 3, 1));
        this.put("desert/zombie/villagers/unemployed", new BPos(1, 3, 1));
        this.put("plains/plains_lamp_1", new BPos(3, 4, 3));
        this.put("plains/houses/plains_accessory_1", new BPos(3, 2, 5));
        this.put("plains/houses/plains_animal_pen_1", new BPos(5, 8, 6));
        this.put("plains/houses/plains_animal_pen_2", new BPos(7, 7, 11));
        this.put("plains/houses/plains_animal_pen_3", new BPos(8, 6, 11));
        this.put("plains/houses/plains_armorer_house_1", new BPos(9, 8, 8));
        this.put("plains/houses/plains_big_house_1", new BPos(7, 11, 11));
        this.put("plains/houses/plains_butcher_shop_1", new BPos(11, 8, 12));
        this.put("plains/houses/plains_butcher_shop_2", new BPos(15, 12, 7));
        this.put("plains/houses/plains_cartographer_1", new BPos(10, 8, 7));
        this.put("plains/houses/plains_fisher_cottage_1", new BPos(11, 9, 10));
        this.put("plains/houses/plains_fletcher_house_1", new BPos(9, 7, 11));
        this.put("plains/houses/plains_large_farm_1", new BPos(13, 6, 9));
        this.put("plains/houses/plains_library_1", new BPos(11, 10, 17));
        this.put("plains/houses/plains_library_2", new BPos(8, 10, 9));
        this.put("plains/houses/plains_masons_house_1", new BPos(8, 7, 9));
        this.put("plains/houses/plains_medium_house_1", new BPos(13, 8, 11));
        this.put("plains/houses/plains_medium_house_2", new BPos(7, 6, 13));
        this.put("plains/houses/plains_meeting_point_4", new BPos(10, 7, 16));
        this.put("plains/houses/plains_meeting_point_5", new BPos(10, 6, 11));
        this.put("plains/houses/plains_shepherds_house_1", new BPos(9, 6, 13));
        this.put("plains/houses/plains_small_farm_1", new BPos(7, 6, 9));
        this.put("plains/houses/plains_small_house_1", new BPos(7, 7, 7));
        this.put("plains/houses/plains_small_house_2", new BPos(7, 7, 7));
        this.put("plains/houses/plains_small_house_3", new BPos(7, 7, 7));
        this.put("plains/houses/plains_small_house_4", new BPos(7, 7, 7));
        this.put("plains/houses/plains_small_house_5", new BPos(9, 11, 9));
        this.put("plains/houses/plains_small_house_6", new BPos(7, 7, 7));
        this.put("plains/houses/plains_small_house_7", new BPos(7, 7, 8));
        this.put("plains/houses/plains_small_house_8", new BPos(8, 9, 9));
        this.put("plains/houses/plains_stable_1", new BPos(9, 7, 16));
        this.put("plains/houses/plains_stable_2", new BPos(7, 6, 17));
        this.put("plains/houses/plains_tannery_1", new BPos(8, 7, 10));
        this.put("plains/houses/plains_temple_3", new BPos(11, 7, 7));
        this.put("plains/houses/plains_temple_4", new BPos(10, 12, 7));
        this.put("plains/houses/plains_tool_smith_1", new BPos(9, 6, 12));
        this.put("plains/houses/plains_weaponsmith_1", new BPos(9, 8, 11));
        this.put("plains/streets/corner_01", new BPos(16, 2, 16));
        this.put("plains/streets/corner_02", new BPos(16, 2, 16));
        this.put("plains/streets/corner_03", new BPos(4, 2, 4));
        this.put("plains/streets/crossroad_01", new BPos(16, 2, 16));
        this.put("plains/streets/crossroad_02", new BPos(16, 2, 16));
        this.put("plains/streets/crossroad_03", new BPos(16, 2, 16));
        this.put("plains/streets/crossroad_04", new BPos(4, 2, 5));
        this.put("plains/streets/crossroad_05", new BPos(5, 2, 5));
        this.put("plains/streets/crossroad_06", new BPos(5, 2, 5));
        this.put("plains/streets/straight_01", new BPos(16, 2, 16));
        this.put("plains/streets/straight_02", new BPos(16, 2, 16));
        this.put("plains/streets/straight_03", new BPos(13, 2, 11));
        this.put("plains/streets/straight_04", new BPos(11, 2, 9));
        this.put("plains/streets/straight_05", new BPos(20, 2, 17));
        this.put("plains/streets/straight_06", new BPos(21, 2, 18));
        this.put("plains/streets/turn_01", new BPos(18, 2, 8));
        this.put("plains/terminators/terminator_01", new BPos(2, 2, 3));
        this.put("plains/terminators/terminator_02", new BPos(1, 2, 1));
        this.put("plains/terminators/terminator_03", new BPos(3, 2, 3));
        this.put("plains/terminators/terminator_04", new BPos(4, 2, 4));
        this.put("plains/town_centers/plains_fountain_01", new BPos(9, 4, 9));
        this.put("plains/town_centers/plains_meeting_point_1", new BPos(10, 7, 10));
        this.put("plains/town_centers/plains_meeting_point_2", new BPos(8, 5, 15));
        this.put("plains/town_centers/plains_meeting_point_3", new BPos(11, 9, 11));
        this.put("plains/villagers/baby", new BPos(1, 2, 1));
        this.put("plains/villagers/nitwit", new BPos(1, 3, 1));
        this.put("plains/villagers/unemployed", new BPos(1, 3, 1));
        this.put("plains/zombie/houses/plains_animal_pen_3", new BPos(8, 6, 11));
        this.put("plains/zombie/houses/plains_big_house_1", new BPos(7, 11, 11));
        this.put("plains/zombie/houses/plains_butcher_shop_2", new BPos(15, 12, 7));
        this.put("plains/zombie/houses/plains_fletcher_house_1", new BPos(9, 7, 11));
        this.put("plains/zombie/houses/plains_medium_house_1", new BPos(13, 8, 11));
        this.put("plains/zombie/houses/plains_medium_house_2", new BPos(7, 6, 13));
        this.put("plains/zombie/houses/plains_meeting_point_4", new BPos(10, 7, 16));
        this.put("plains/zombie/houses/plains_meeting_point_5", new BPos(10, 6, 11));
        this.put("plains/zombie/houses/plains_shepherds_house_1", new BPos(9, 6, 13));
        this.put("plains/zombie/houses/plains_small_house_1", new BPos(7, 7, 7));
        this.put("plains/zombie/houses/plains_small_house_2", new BPos(7, 7, 7));
        this.put("plains/zombie/houses/plains_small_house_3", new BPos(7, 7, 7));
        this.put("plains/zombie/houses/plains_small_house_4", new BPos(7, 7, 7));
        this.put("plains/zombie/houses/plains_small_house_5", new BPos(9, 11, 9));
        this.put("plains/zombie/houses/plains_small_house_6", new BPos(7, 7, 7));
        this.put("plains/zombie/houses/plains_small_house_7", new BPos(7, 7, 8));
        this.put("plains/zombie/houses/plains_small_house_8", new BPos(8, 9, 9));
        this.put("plains/zombie/houses/plains_stable_1", new BPos(9, 7, 16));
        this.put("plains/zombie/streets/corner_01", new BPos(16, 2, 16));
        this.put("plains/zombie/streets/corner_02", new BPos(16, 2, 16));
        this.put("plains/zombie/streets/corner_03", new BPos(4, 2, 4));
        this.put("plains/zombie/streets/crossroad_01", new BPos(16, 2, 16));
        this.put("plains/zombie/streets/crossroad_02", new BPos(16, 2, 16));
        this.put("plains/zombie/streets/crossroad_03", new BPos(16, 2, 16));
        this.put("plains/zombie/streets/crossroad_04", new BPos(4, 2, 5));
        this.put("plains/zombie/streets/crossroad_05", new BPos(5, 2, 5));
        this.put("plains/zombie/streets/crossroad_06", new BPos(5, 2, 5));
        this.put("plains/zombie/streets/straight_01", new BPos(16, 2, 16));
        this.put("plains/zombie/streets/straight_02", new BPos(16, 2, 16));
        this.put("plains/zombie/streets/straight_03", new BPos(13, 2, 11));
        this.put("plains/zombie/streets/straight_04", new BPos(11, 2, 9));
        this.put("plains/zombie/streets/straight_05", new BPos(20, 2, 17));
        this.put("plains/zombie/streets/straight_06", new BPos(21, 2, 18));
        this.put("plains/zombie/streets/turn_01", new BPos(18, 2, 8));
        this.put("plains/zombie/town_centers/plains_fountain_01", new BPos(9, 6, 9));
        this.put("plains/zombie/town_centers/plains_meeting_point_1", new BPos(10, 7, 10));
        this.put("plains/zombie/town_centers/plains_meeting_point_2", new BPos(8, 5, 15));
        this.put("plains/zombie/town_centers/plains_meeting_point_3", new BPos(11, 9, 11));
        this.put("plains/zombie/villagers/nitwit", new BPos(1, 3, 1));
        this.put("plains/zombie/villagers/unemployed", new BPos(1, 3, 1));
        this.put("savanna/savanna_lamp_post_01", new BPos(1, 2, 1));
        this.put("savanna/houses/savanna_animal_pen_1", new BPos(9, 5, 9));
        this.put("savanna/houses/savanna_animal_pen_2", new BPos(13, 7, 12));
        this.put("savanna/houses/savanna_animal_pen_3", new BPos(8, 5, 9));
        this.put("savanna/houses/savanna_armorer_1", new BPos(7, 7, 7));
        this.put("savanna/houses/savanna_butchers_shop_1", new BPos(11, 8, 11));
        this.put("savanna/houses/savanna_butchers_shop_2", new BPos(13, 10, 9));
        this.put("savanna/houses/savanna_cartographer_1", new BPos(8, 8, 9));
        this.put("savanna/houses/savanna_fisher_cottage_1", new BPos(8, 11, 9));
        this.put("savanna/houses/savanna_fletcher_house_1", new BPos(11, 7, 9));
        this.put("savanna/houses/savanna_large_farm_1", new BPos(9, 6, 9));
        this.put("savanna/houses/savanna_large_farm_2", new BPos(10, 7, 8));
        this.put("savanna/houses/savanna_library_1", new BPos(10, 8, 8));
        this.put("savanna/houses/savanna_mason_1", new BPos(8, 7, 10));
        this.put("savanna/houses/savanna_medium_house_1", new BPos(8, 7, 15));
        this.put("savanna/houses/savanna_medium_house_2", new BPos(10, 8, 11));
        this.put("savanna/houses/savanna_shepherd_1", new BPos(13, 14, 11));
        this.put("savanna/houses/savanna_small_farm", new BPos(6, 7, 9));
        this.put("savanna/houses/savanna_small_house_1", new BPos(7, 7, 7));
        this.put("savanna/houses/savanna_small_house_2", new BPos(7, 7, 7));
        this.put("savanna/houses/savanna_small_house_3", new BPos(7, 7, 7));
        this.put("savanna/houses/savanna_small_house_4", new BPos(10, 8, 7));
        this.put("savanna/houses/savanna_small_house_5", new BPos(7, 10, 7));
        this.put("savanna/houses/savanna_small_house_6", new BPos(7, 7, 7));
        this.put("savanna/houses/savanna_small_house_7", new BPos(7, 7, 7));
        this.put("savanna/houses/savanna_small_house_8", new BPos(6, 7, 7));
        this.put("savanna/houses/savanna_tannery_1", new BPos(8, 6, 9));
        this.put("savanna/houses/savanna_temple_1", new BPos(13, 8, 9));
        this.put("savanna/houses/savanna_temple_2", new BPos(7, 7, 9));
        this.put("savanna/houses/savanna_tool_smith_1", new BPos(7, 7, 11));
        this.put("savanna/houses/savanna_weaponsmith_1", new BPos(8, 6, 9));
        this.put("savanna/houses/savanna_weaponsmith_2", new BPos(9, 7, 13));
        this.put("savanna/streets/corner_01", new BPos(16, 2, 16));
        this.put("savanna/streets/corner_03", new BPos(4, 2, 4));
        this.put("savanna/streets/crossroad_02", new BPos(7, 2, 10));
        this.put("savanna/streets/crossroad_03", new BPos(16, 2, 16));
        this.put("savanna/streets/crossroad_04", new BPos(4, 2, 5));
        this.put("savanna/streets/crossroad_05", new BPos(5, 2, 5));
        this.put("savanna/streets/crossroad_06", new BPos(5, 2, 5));
        this.put("savanna/streets/crossroad_07", new BPos(15, 2, 14));
        this.put("savanna/streets/split_01", new BPos(8, 2, 6));
        this.put("savanna/streets/split_02", new BPos(14, 2, 9));
        this.put("savanna/streets/straight_02", new BPos(16, 2, 16));
        this.put("savanna/streets/straight_04", new BPos(11, 2, 9));
        this.put("savanna/streets/straight_05", new BPos(20, 2, 17));
        this.put("savanna/streets/straight_06", new BPos(9, 2, 14));
        this.put("savanna/streets/straight_08", new BPos(10, 2, 16));
        this.put("savanna/streets/straight_09", new BPos(23, 2, 16));
        this.put("savanna/streets/straight_10", new BPos(6, 2, 11));
        this.put("savanna/streets/straight_11", new BPos(17, 2, 17));
        this.put("savanna/streets/turn_01", new BPos(19, 2, 11));
        this.put("savanna/terminators/terminator_05", new BPos(16, 2, 16));
        this.put("savanna/town_centers/savanna_meeting_point_1", new BPos(14, 5, 12));
        this.put("savanna/town_centers/savanna_meeting_point_2", new BPos(11, 6, 11));
        this.put("savanna/town_centers/savanna_meeting_point_3", new BPos(9, 6, 11));
        this.put("savanna/town_centers/savanna_meeting_point_4", new BPos(9, 6, 9));
        this.put("savanna/villagers/baby", new BPos(1, 2, 1));
        this.put("savanna/villagers/nitwit", new BPos(1, 3, 1));
        this.put("savanna/villagers/unemployed", new BPos(1, 3, 1));
        this.put("savanna/zombie/houses/savanna_animal_pen_2", new BPos(13, 7, 12));
        this.put("savanna/zombie/houses/savanna_animal_pen_3", new BPos(8, 5, 9));
        this.put("savanna/zombie/houses/savanna_large_farm_2", new BPos(10, 7, 8));
        this.put("savanna/zombie/houses/savanna_medium_house_1", new BPos(8, 7, 15));
        this.put("savanna/zombie/houses/savanna_medium_house_2", new BPos(10, 8, 11));
        this.put("savanna/zombie/houses/savanna_small_house_1", new BPos(7, 7, 7));
        this.put("savanna/zombie/houses/savanna_small_house_2", new BPos(7, 7, 7));
        this.put("savanna/zombie/houses/savanna_small_house_3", new BPos(7, 7, 7));
        this.put("savanna/zombie/houses/savanna_small_house_4", new BPos(10, 8, 7));
        this.put("savanna/zombie/houses/savanna_small_house_5", new BPos(7, 10, 7));
        this.put("savanna/zombie/houses/savanna_small_house_6", new BPos(7, 7, 7));
        this.put("savanna/zombie/houses/savanna_small_house_7", new BPos(7, 7, 7));
        this.put("savanna/zombie/houses/savanna_small_house_8", new BPos(6, 7, 7));
        this.put("savanna/zombie/streets/corner_01", new BPos(16, 2, 16));
        this.put("savanna/zombie/streets/corner_03", new BPos(4, 2, 4));
        this.put("savanna/zombie/streets/crossroad_02", new BPos(7, 2, 10));
        this.put("savanna/zombie/streets/crossroad_03", new BPos(16, 2, 16));
        this.put("savanna/zombie/streets/crossroad_04", new BPos(4, 2, 5));
        this.put("savanna/zombie/streets/crossroad_05", new BPos(5, 2, 5));
        this.put("savanna/zombie/streets/crossroad_06", new BPos(5, 2, 5));
        this.put("savanna/zombie/streets/crossroad_07", new BPos(15, 2, 14));
        this.put("savanna/zombie/streets/split_01", new BPos(8, 2, 6));
        this.put("savanna/zombie/streets/split_02", new BPos(14, 2, 9));
        this.put("savanna/zombie/streets/straight_02", new BPos(16, 2, 16));
        this.put("savanna/zombie/streets/straight_04", new BPos(11, 2, 9));
        this.put("savanna/zombie/streets/straight_05", new BPos(20, 2, 17));
        this.put("savanna/zombie/streets/straight_06", new BPos(9, 2, 14));
        this.put("savanna/zombie/streets/straight_08", new BPos(10, 2, 16));
        this.put("savanna/zombie/streets/straight_09", new BPos(23, 2, 16));
        this.put("savanna/zombie/streets/straight_10", new BPos(6, 2, 11));
        this.put("savanna/zombie/streets/straight_11", new BPos(17, 2, 17));
        this.put("savanna/zombie/streets/turn_01", new BPos(19, 2, 11));
        this.put("savanna/zombie/terminators/terminator_05", new BPos(16, 2, 16));
        this.put("savanna/zombie/town_centers/savanna_meeting_point_1", new BPos(14, 6, 12));
        this.put("savanna/zombie/town_centers/savanna_meeting_point_2", new BPos(11, 6, 11));
        this.put("savanna/zombie/town_centers/savanna_meeting_point_3", new BPos(9, 6, 11));
        this.put("savanna/zombie/town_centers/savanna_meeting_point_4", new BPos(9, 6, 9));
        this.put("savanna/zombie/villagers/nitwit", new BPos(1, 3, 1));
        this.put("savanna/zombie/villagers/unemployed", new BPos(1, 3, 1));
        this.put("snowy/snowy_lamp_post_01", new BPos(3, 4, 1));
        this.put("snowy/snowy_lamp_post_02", new BPos(2, 4, 1));
        this.put("snowy/snowy_lamp_post_03", new BPos(3, 4, 3));
        this.put("snowy/houses/snowy_animal_pen_1", new BPos(8, 6, 9));
        this.put("snowy/houses/snowy_animal_pen_2", new BPos(9, 6, 8));
        this.put("snowy/houses/snowy_armorer_house_1", new BPos(8, 8, 7));
        this.put("snowy/houses/snowy_armorer_house_2", new BPos(7, 8, 7));
        this.put("snowy/houses/snowy_butchers_shop_1", new BPos(7, 8, 9));
        this.put("snowy/houses/snowy_butchers_shop_2", new BPos(9, 5, 5));
        this.put("snowy/houses/snowy_cartographer_house_1", new BPos(7, 7, 11));
        this.put("snowy/houses/snowy_farm_1", new BPos(6, 6, 7));
        this.put("snowy/houses/snowy_farm_2", new BPos(7, 6, 9));
        this.put("snowy/houses/snowy_fisher_cottage", new BPos(9, 8, 7));
        this.put("snowy/houses/snowy_fletcher_house_1", new BPos(9, 8, 7));
        this.put("snowy/houses/snowy_library_1", new BPos(13, 10, 7));
        this.put("snowy/houses/snowy_masons_house_1", new BPos(10, 8, 9));
        this.put("snowy/houses/snowy_masons_house_2", new BPos(9, 10, 9));
        this.put("snowy/houses/snowy_medium_house_1", new BPos(7, 6, 8));
        this.put("snowy/houses/snowy_medium_house_2", new BPos(14, 9, 7));
        this.put("snowy/houses/snowy_medium_house_3", new BPos(5, 5, 7));
        this.put("snowy/houses/snowy_shepherds_house_1", new BPos(9, 5, 10));
        this.put("snowy/houses/snowy_small_house_1", new BPos(7, 5, 6));
        this.put("snowy/houses/snowy_small_house_2", new BPos(7, 8, 7));
        this.put("snowy/houses/snowy_small_house_3", new BPos(7, 6, 7));
        this.put("snowy/houses/snowy_small_house_4", new BPos(8, 5, 7));
        this.put("snowy/houses/snowy_small_house_5", new BPos(7, 5, 5));
        this.put("snowy/houses/snowy_small_house_6", new BPos(7, 9, 7));
        this.put("snowy/houses/snowy_small_house_7", new BPos(6, 7, 7));
        this.put("snowy/houses/snowy_small_house_8", new BPos(6, 5, 5));
        this.put("snowy/houses/snowy_tannery_1", new BPos(8, 9, 9));
        this.put("snowy/houses/snowy_temple_1", new BPos(10, 14, 7));
        this.put("snowy/houses/snowy_tool_smith_1", new BPos(8, 8, 7));
        this.put("snowy/houses/snowy_weapon_smith_1", new BPos(9, 7, 10));
        this.put("snowy/streets/corner_01", new BPos(13, 2, 16));
        this.put("snowy/streets/corner_02", new BPos(16, 2, 16));
        this.put("snowy/streets/corner_03", new BPos(4, 2, 4));
        this.put("snowy/streets/crossroad_01", new BPos(16, 2, 16));
        this.put("snowy/streets/crossroad_02", new BPos(16, 2, 16));
        this.put("snowy/streets/crossroad_03", new BPos(16, 2, 17));
        this.put("snowy/streets/crossroad_04", new BPos(4, 2, 5));
        this.put("snowy/streets/crossroad_05", new BPos(5, 2, 5));
        this.put("snowy/streets/crossroad_06", new BPos(5, 2, 5));
        this.put("snowy/streets/square_01", new BPos(20, 2, 17));
        this.put("snowy/streets/straight_01", new BPos(16, 2, 16));
        this.put("snowy/streets/straight_02", new BPos(16, 2, 16));
        this.put("snowy/streets/straight_03", new BPos(13, 2, 11));
        this.put("snowy/streets/straight_04", new BPos(11, 2, 9));
        this.put("snowy/streets/straight_06", new BPos(21, 2, 18));
        this.put("snowy/streets/straight_08", new BPos(16, 2, 17));
        this.put("snowy/streets/turn_01", new BPos(18, 2, 8));
        this.put("snowy/town_centers/snowy_meeting_point_1", new BPos(12, 8, 8));
        this.put("snowy/town_centers/snowy_meeting_point_2", new BPos(11, 5, 9));
        this.put("snowy/town_centers/snowy_meeting_point_3", new BPos(7, 7, 7));
        this.put("snowy/villagers/baby", new BPos(1, 2, 1));
        this.put("snowy/villagers/nitwit", new BPos(1, 3, 1));
        this.put("snowy/villagers/unemployed", new BPos(1, 3, 1));
        this.put("snowy/zombie/houses/snowy_medium_house_1", new BPos(7, 6, 8));
        this.put("snowy/zombie/houses/snowy_medium_house_2", new BPos(14, 9, 7));
        this.put("snowy/zombie/houses/snowy_medium_house_3", new BPos(5, 5, 7));
        this.put("snowy/zombie/houses/snowy_small_house_1", new BPos(7, 5, 6));
        this.put("snowy/zombie/houses/snowy_small_house_2", new BPos(7, 8, 7));
        this.put("snowy/zombie/houses/snowy_small_house_3", new BPos(7, 6, 7));
        this.put("snowy/zombie/houses/snowy_small_house_4", new BPos(8, 5, 7));
        this.put("snowy/zombie/houses/snowy_small_house_5", new BPos(7, 5, 5));
        this.put("snowy/zombie/houses/snowy_small_house_6", new BPos(7, 9, 7));
        this.put("snowy/zombie/houses/snowy_small_house_7", new BPos(6, 7, 7));
        this.put("snowy/zombie/houses/snowy_small_house_8", new BPos(6, 4, 5));
        this.put("snowy/zombie/streets/corner_01", new BPos(13, 2, 16));
        this.put("snowy/zombie/streets/corner_02", new BPos(16, 2, 16));
        this.put("snowy/zombie/streets/corner_03", new BPos(4, 2, 4));
        this.put("snowy/zombie/streets/crossroad_01", new BPos(16, 2, 16));
        this.put("snowy/zombie/streets/crossroad_02", new BPos(16, 2, 16));
        this.put("snowy/zombie/streets/crossroad_03", new BPos(16, 2, 17));
        this.put("snowy/zombie/streets/crossroad_04", new BPos(4, 2, 5));
        this.put("snowy/zombie/streets/crossroad_05", new BPos(5, 2, 5));
        this.put("snowy/zombie/streets/crossroad_06", new BPos(5, 2, 5));
        this.put("snowy/zombie/streets/square_01", new BPos(20, 2, 17));
        this.put("snowy/zombie/streets/straight_01", new BPos(16, 2, 16));
        this.put("snowy/zombie/streets/straight_02", new BPos(16, 2, 16));
        this.put("snowy/zombie/streets/straight_03", new BPos(13, 2, 11));
        this.put("snowy/zombie/streets/straight_04", new BPos(11, 2, 9));
        this.put("snowy/zombie/streets/straight_06", new BPos(21, 2, 18));
        this.put("snowy/zombie/streets/straight_08", new BPos(16, 2, 17));
        this.put("snowy/zombie/streets/turn_01", new BPos(18, 2, 8));
        this.put("snowy/zombie/town_centers/snowy_meeting_point_1", new BPos(12, 8, 8));
        this.put("snowy/zombie/town_centers/snowy_meeting_point_2", new BPos(11, 6, 9));
        this.put("snowy/zombie/town_centers/snowy_meeting_point_3", new BPos(7, 7, 7));
        this.put("snowy/zombie/villagers/nitwit", new BPos(1, 3, 1));
        this.put("snowy/zombie/villagers/unemployed", new BPos(1, 3, 1));
        this.put("taiga/taiga_decoration_1", new BPos(3, 2, 6));
        this.put("taiga/taiga_decoration_2", new BPos(2, 2, 3));
        this.put("taiga/taiga_decoration_3", new BPos(1, 2, 2));
        this.put("taiga/taiga_decoration_4", new BPos(1, 2, 2));
        this.put("taiga/taiga_decoration_5", new BPos(1, 1, 1));
        this.put("taiga/taiga_decoration_6", new BPos(3, 2, 3));
        this.put("taiga/taiga_lamp_post_1", new BPos(1, 2, 1));
        this.put("taiga/houses/taiga_animal_pen_1", new BPos(13, 5, 8));
        this.put("taiga/houses/taiga_armorer_2", new BPos(7, 8, 7));
        this.put("taiga/houses/taiga_armorer_house_1", new BPos(10, 7, 7));
        this.put("taiga/houses/taiga_butcher_shop_1", new BPos(11, 7, 9));
        this.put("taiga/houses/taiga_cartographer_house_1", new BPos(7, 10, 8));
        this.put("taiga/houses/taiga_fisher_cottage_1", new BPos(10, 8, 12));
        this.put("taiga/houses/taiga_fletcher_house_1", new BPos(10, 6, 11));
        this.put("taiga/houses/taiga_large_farm_1", new BPos(10, 7, 10));
        this.put("taiga/houses/taiga_large_farm_2", new BPos(8, 7, 9));
        this.put("taiga/houses/taiga_library_1", new BPos(11, 10, 8));
        this.put("taiga/houses/taiga_masons_house_1", new BPos(8, 7, 9));
        this.put("taiga/houses/taiga_medium_house_1", new BPos(8, 11, 7));
        this.put("taiga/houses/taiga_medium_house_2", new BPos(7, 11, 8));
        this.put("taiga/houses/taiga_medium_house_3", new BPos(8, 7, 13));
        this.put("taiga/houses/taiga_medium_house_4", new BPos(9, 7, 9));
        this.put("taiga/houses/taiga_shepherds_house_1", new BPos(10, 7, 11));
        this.put("taiga/houses/taiga_small_farm_1", new BPos(7, 7, 8));
        this.put("taiga/houses/taiga_small_house_1", new BPos(7, 8, 9));
        this.put("taiga/houses/taiga_small_house_2", new BPos(7, 7, 7));
        this.put("taiga/houses/taiga_small_house_3", new BPos(7, 7, 7));
        this.put("taiga/houses/taiga_small_house_4", new BPos(7, 6, 8));
        this.put("taiga/houses/taiga_small_house_5", new BPos(9, 7, 7));
        this.put("taiga/houses/taiga_tannery_1", new BPos(9, 6, 9));
        this.put("taiga/houses/taiga_temple_1", new BPos(13, 14, 11));
        this.put("taiga/houses/taiga_tool_smith_1", new BPos(11, 6, 8));
        this.put("taiga/houses/taiga_weaponsmith_1", new BPos(7, 9, 7));
        this.put("taiga/houses/taiga_weaponsmith_2", new BPos(6, 5, 7));
        this.put("taiga/streets/corner_01", new BPos(16, 2, 16));
        this.put("taiga/streets/corner_02", new BPos(16, 2, 16));
        this.put("taiga/streets/corner_03", new BPos(4, 2, 4));
        this.put("taiga/streets/crossroad_01", new BPos(16, 2, 16));
        this.put("taiga/streets/crossroad_02", new BPos(16, 2, 16));
        this.put("taiga/streets/crossroad_03", new BPos(16, 2, 16));
        this.put("taiga/streets/crossroad_04", new BPos(4, 2, 5));
        this.put("taiga/streets/crossroad_05", new BPos(5, 2, 5));
        this.put("taiga/streets/crossroad_06", new BPos(5, 2, 5));
        this.put("taiga/streets/straight_01", new BPos(16, 2, 16));
        this.put("taiga/streets/straight_02", new BPos(16, 2, 16));
        this.put("taiga/streets/straight_03", new BPos(13, 2, 11));
        this.put("taiga/streets/straight_04", new BPos(11, 2, 9));
        this.put("taiga/streets/straight_05", new BPos(20, 2, 17));
        this.put("taiga/streets/straight_06", new BPos(21, 2, 18));
        this.put("taiga/streets/turn_01", new BPos(18, 2, 8));
        this.put("taiga/town_centers/taiga_meeting_point_1", new BPos(22, 3, 18));
        this.put("taiga/town_centers/taiga_meeting_point_2", new BPos(9, 7, 9));
        this.put("taiga/villagers/baby", new BPos(1, 2, 1));
        this.put("taiga/villagers/nitwit", new BPos(1, 3, 1));
        this.put("taiga/villagers/unemployed", new BPos(1, 3, 1));
        this.put("taiga/zombie/houses/taiga_cartographer_house_1", new BPos(7, 10, 8));
        this.put("taiga/zombie/houses/taiga_fisher_cottage_1", new BPos(10, 8, 12));
        this.put("taiga/zombie/houses/taiga_large_farm_2", new BPos(8, 7, 9));
        this.put("taiga/zombie/houses/taiga_library_1", new BPos(11, 10, 8));
        this.put("taiga/zombie/houses/taiga_medium_house_1", new BPos(8, 11, 7));
        this.put("taiga/zombie/houses/taiga_medium_house_2", new BPos(7, 11, 8));
        this.put("taiga/zombie/houses/taiga_medium_house_3", new BPos(8, 7, 13));
        this.put("taiga/zombie/houses/taiga_medium_house_4", new BPos(9, 7, 9));
        this.put("taiga/zombie/houses/taiga_shepherds_house_1", new BPos(10, 7, 11));
        this.put("taiga/zombie/houses/taiga_small_house_1", new BPos(7, 8, 9));
        this.put("taiga/zombie/houses/taiga_small_house_2", new BPos(7, 7, 7));
        this.put("taiga/zombie/houses/taiga_small_house_3", new BPos(7, 7, 7));
        this.put("taiga/zombie/houses/taiga_small_house_4", new BPos(7, 6, 8));
        this.put("taiga/zombie/houses/taiga_small_house_5", new BPos(9, 7, 7));
        this.put("taiga/zombie/houses/taiga_temple_1", new BPos(13, 14, 11));
        this.put("taiga/zombie/houses/taiga_tool_smith_1", new BPos(11, 6, 8));
        this.put("taiga/zombie/houses/taiga_weaponsmith_2", new BPos(6, 5, 7));
        this.put("taiga/zombie/streets/corner_01", new BPos(16, 2, 16));
        this.put("taiga/zombie/streets/corner_02", new BPos(16, 2, 16));
        this.put("taiga/zombie/streets/corner_03", new BPos(4, 2, 4));
        this.put("taiga/zombie/streets/crossroad_01", new BPos(16, 2, 16));
        this.put("taiga/zombie/streets/crossroad_02", new BPos(16, 2, 16));
        this.put("taiga/zombie/streets/crossroad_03", new BPos(16, 2, 16));
        this.put("taiga/zombie/streets/crossroad_04", new BPos(4, 2, 5));
        this.put("taiga/zombie/streets/crossroad_05", new BPos(5, 2, 5));
        this.put("taiga/zombie/streets/crossroad_06", new BPos(5, 2, 5));
        this.put("taiga/zombie/streets/straight_01", new BPos(16, 2, 16));
        this.put("taiga/zombie/streets/straight_02", new BPos(16, 2, 16));
        this.put("taiga/zombie/streets/straight_03", new BPos(13, 2, 11));
        this.put("taiga/zombie/streets/straight_04", new BPos(11, 2, 9));
        this.put("taiga/zombie/streets/straight_05", new BPos(20, 2, 17));
        this.put("taiga/zombie/streets/straight_06", new BPos(21, 2, 18));
        this.put("taiga/zombie/streets/turn_01", new BPos(18, 2, 8));
        this.put("taiga/zombie/town_centers/taiga_meeting_point_1", new BPos(22, 6, 18));
        this.put("taiga/zombie/town_centers/taiga_meeting_point_2", new BPos(9, 7, 9));
        this.put("taiga/zombie/villagers/nitwit", new BPos(1, 3, 1));
        this.put("taiga/zombie/villagers/unemployed", new BPos(1, 3, 1));
    }};

    // TODO optimize the hell out of this (with indexes)
    public static class JigSawPool {
        private final LinkedList<String> templates = new LinkedList<>();

        JigSawPool(List<Pair<String, Integer>> templates) {
            for(Pair<String, Integer> template : templates) {
                for(int i = 0; i < template.getSecond(); i++) {
                    this.templates.addLast(template.getFirst());
                }
            }
        }

        public LinkedList<String> getTemplates() {
            return templates;
        }
    }


    public enum VillageType {
        DESERT,
        PLAINS,
        SAVANNA,
        SNOWY,
        TAIGA,
        LEGACY;

        public static VillageType getType(Biome biome, MCVersion version) {
            if(version.isOlderThan(MCVersion.v1_14)) return LEGACY;
            if(Biomes.DESERT.equals(biome)) {
                return DESERT;
            }
            if(Biomes.SAVANNA.equals(biome)) {
                return SAVANNA;
            }
            if(Biomes.SNOWY_TUNDRA.equals(biome)) {
                return SNOWY;
            }
            if(Biomes.TAIGA.equals(biome)) {
                return TAIGA;
            }
            if(biome.equals(Biomes.PLAINS)) {
                return PLAINS;
            }
            return null;
        }

        public HashMap<String, List<Pair<Quad<String, String, Pair<BlockDirection,BlockDirection>, Block>, BPos>>> getJigsawBlocks() {
            switch(this) {
                case DESERT:
                    return DesertVillageJigsawBlocks.JIGSAW_BLOCKS;
                case PLAINS:
                    return PlainsVillageJigsawBlock.JIGSAW_BLOCKS;
                case SAVANNA:
                    return SavannaVillageJigsawBlocks.JIGSAW_BLOCKS;
                case SNOWY:
                    return SnowyVillageJigsawBlocks.JIGSAW_BLOCKS;
                case TAIGA:
                    return TaigaVillageJigsawBlocks.JIGSAW_BLOCKS;
            }
            return null;
        }
        public String getBlackSmithName(){//don't check for zombie village yet
            switch(this){
                case DESERT :
                    return "desert/houses/desert_weaponsmith_1";
                case PLAINS :
                    return "plains/houses/plains_weaponsmith_1";
                case TAIGA:
                    return "taiga/houses/taiga_weaponsmith_1";
                case SAVANNA :
                    return "savanna/houses/savanna_weaponsmith_2";
                case SNOWY :
                    return "snowy/houses/snowy_weapon_smith_1";
            }
            return null;
        }
        public String getHouseName(){
            switch(this){
                case DESERT :
                    return "desert/houses";

                case PLAINS :
                    return "plains/houses";
                case TAIGA:
                    return "taiga/houses";
                case SAVANNA :
                    return "savanna/houses";
                case SNOWY :
                    return "snowy/houses";
                default:
                    return "desert/houses";
            }
        }

        public Map<String, Triplet<String, List<Pair<String, Integer>>, PlacementBehaviour>> getPool() {
            switch(this) {
                case TAIGA:
                    return TaigaPool.VILLAGE_POOLS;
                case DESERT:
                    return DesertPool.VILLAGE_POOLS;
                case PLAINS:
                    return PlainPool.VILLAGE_POOLS;
                case SAVANNA:
                    return SavannaPool.VILLAGE_POOLS;
                case SNOWY:
                    return SnowyPool.VILLAGE_POOLS;

            }
            return null;
        }
    }

    public static final Map<VillageType, JigSawPool> STARTS = new HashMap<>() {{
        put(VillageType.DESERT, new JigSawPool(DesertPool.VILLAGE_POOLS.get("desert/town_centers").getSecond()));
        put(VillageType.LEGACY, null);
        put(VillageType.PLAINS, new JigSawPool(PlainPool.VILLAGE_POOLS.get("plains/town_centers").getSecond()));
        put(VillageType.TAIGA, new JigSawPool(TaigaPool.VILLAGE_POOLS.get("taiga/town_centers").getSecond()));
        put(VillageType.SAVANNA, new JigSawPool(SavannaPool.VILLAGE_POOLS.get("savanna/town_centers").getSecond()));
        put(VillageType.SNOWY, new JigSawPool(SnowyPool.VILLAGE_POOLS.get("snowy/town_centers").getSecond()));
    }};
}
