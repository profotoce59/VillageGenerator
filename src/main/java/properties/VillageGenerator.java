package properties;

import kaptainwutax.biomeutils.biome.Biome;
import kaptainwutax.biomeutils.biome.Biomes;
import kaptainwutax.featureutils.structure.RegionStructure;
import kaptainwutax.featureutils.structure.Stronghold;
import kaptainwutax.featureutils.structure.Village;
import kaptainwutax.featureutils.structure.generator.Generator;
import kaptainwutax.featureutils.structure.generator.piece.village.*;
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
import reecriture.*;
import reecriture.VillagePools.PlainPool;
import reecriture.VillagePools.PlainsVillageJigsawBlock;

import java.util.*;

import static kaptainwutax.mcutils.util.block.BlockDirection.DOWN;

public class VillageGenerator extends Generator {
    public List<Piece> pieces = new ArrayList<Piece>();
    private VillageType villageType;

    public VillageGenerator(MCVersion version) {
        super(version);
    }

    @Override
    public boolean generate(TerrainGenerator generator, int chunkX, int chunkZ, ChunkRand rand) {
        rand = rand.asChunkRandDebugger();
        //System.out.println(rand.nextInt());
        // check the structure
        Village village = new Village(this.getVersion());
        // instantiate the biome type
        if(!village.canSpawn(chunkX, chunkZ, generator.getBiomeSource())) return false;
        Biome biome = Biomes.PLAINS;
        this.villageType = VillageType.getType(biome, generator.getVersion());
        // compute the rotation
        rand.setCarverSeed(generator.getWorldSeed(), chunkX, chunkZ, generator.getVersion());
        BlockRotation rotation = BlockRotation.getRandom(rand);

        // compute the template

        JigSawPool jigSawPool = STARTS.get(villageType);
        LinkedList<String> g = jigSawPool.getTemplates();
        String template = rand.getRandom(jigSawPool.getTemplates());
        // get the information about the structure
        BPos size = STRUCTURE_SIZE.get(template);
        BPos bPos = new CPos(chunkX, chunkZ).toBlockPos(0);
        BlockBox box = BlockBox.getBoundingBox(bPos, rotation, BPos.ORIGIN, BlockMirror.NONE, size);
        int centerX = (box.minX + box.maxX) / 2;
        int centerZ = (box.minZ + box.maxZ) / 2;
        // startToHeightmap true except bastion
        int y = bPos.getY() + generator.getHeightOnGround(centerX, centerZ);
        int centerY = box.minY + 1;

        // create the first piece (always rigid)
        Piece piece = new Piece(template, bPos, box, rotation, PlacementBehaviour.RIGID,0);
        piece.move(0, y - centerY, 0);
        piece.setBoundsTop(y + 80);
        int depth = 0;

        // make the other connected ones
        // config maxDepth=6
        BlockBox fullBox = new BlockBox(centerX - 80, y - 80, centerZ - 80, centerX + 80 + 1, y + 80 + 1, centerZ + 80 + 1);
        Assembler assembler = new Assembler(6, generator,this.pieces);
        VoxelShape a = assembler.joinUnoptimized(new VoxelShape(fullBox),new VoxelShape(box,true),BoolFunc.ONLYFIRST);
        piece.voxelShape = a;
        assembler.placing.addLast(piece);
        while(!assembler.placing.isEmpty()) {
            assembler.tryPlacing(villageType, assembler.placing.removeFirst(), rand, true);
            //System.out.println("while");
        }
        //System.out.println("fini le village");
        return true;
    }
    String removeDesert(String a){
        return a.substring(8);
    }

    public void printPieces() {
        for (Piece piece :pieces){
            System.out.println(piece.name + " "+piece.pos.toString());
        }
    }
    public List<Piece> getPieces() {
        return this.pieces;
    }


    public class Piece {
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
            List<Pair<Quad<String, String, String, Block>, BPos>> blocks = villageType.getJigsawBlocks().get(removeDesert(this.name));
            List<BlockJigsawInfo> list = new ArrayList<>();
            if (blocks != null){
                list = new ArrayList<>(blocks.size());
                for(int index = 0; index < blocks.size();index++) {
                    if(blocks.get(index).getFirst().getThird()==null){
                        continue;
                    }
                    ChunkRand rand2 = new ChunkRand();
                    int offsetz = rand2.nextInt(blocks.size());
                    BPos pos = blocks.get(index).getSecond().transform(BlockMirror.NONE, rotation, BPos.ORIGIN).add(offset);
                    list.add(new BlockJigsawInfo(blocks.get(index).getFirst(), pos, rotation));
                }
            }

            else /*if((this.name).substring(8,14).equals("common"))*/{
                List<Pair<Quad<String, String, String, Block>, BPos>> listtmp = CommonVillageJigsawBlocks.JIGSAW_BLOCKS.get(removeDesert(this.name));
                if(listtmp != null) {
                    Quad<String, String, String, Block> nbt2 = listtmp.get(0).getFirst();
                    BPos size = CommonVillageJigsawBlocks.JIGSAW_BLOCKS.get(removeDesert(this.name)).get(0).getSecond();
                    list.add(new BlockJigsawInfo(nbt2, size, rotation));
                }
                else list.add(new BlockJigsawInfo(new Quad<String, String, String, Block>("empty", "bottom", "down_south", Blocks.STRUCTURE_VOID),new BPos(0,0,0),rotation));

            }
            //else list = Collections.emptyList();


            //Collections.shuffle(list,rand.toRandom());
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
        Quad<String, String, String, Block> nbt;
        BPos pos;
        BlockRotation rotation;
        String target;
        public BlockJigsawInfo(Quad<String, String, String, Block> nbt, BPos pos, BlockRotation rotation) {
            // nbt is stored as pool,name,orientation,final_state
            this.nbt = nbt;
            this.pos = pos;
            this.rotation = rotation;

        }

        public BlockDirection getFront() {
            return rotation.rotate((BlockDirection.fromString(this.nbt.getThird().split("_")[0])));
        }

        public Triplet<String, List<Pair<String, Integer>>, PlacementBehaviour> getPool() {
            return VILLAGE_POOLS.get(this.nbt.getFirst());
        }

        public static boolean canAttach(BlockJigsawInfo blockJigsawInfo, BlockJigsawInfo blockJigsawInfo2) {
            BlockDirection direction = blockJigsawInfo.getFront();
            BlockDirection direction2 = blockJigsawInfo2.getFront();
            BlockDirection direction2b = null;
            if(direction2 == BlockDirection.UP)direction2b = BlockDirection.fromString("DOWN");
            else if(direction2 == BlockDirection.DOWN) direction2b = BlockDirection.fromString("UP");
            else direction2b = direction2.getOpposite();
            BlockDirection direction3 = blockJigsawInfo.getFace();
            BlockDirection direction4 = blockJigsawInfo2.getFace();
            boolean isROLLABLE = (direction.getAxis().ordinal())%2==1;
            return direction==direction2b && (isROLLABLE || direction4 == direction3) && blockJigsawInfo.nbt.getSecond().equals(blockJigsawInfo2.nbt.getSecond());

        }

        private BlockDirection getFace() {
            return rotation.rotate(BlockDirection.fromString(this.nbt.getThird().split("_")[1]));
        }
    }

    public class Assembler {
        int maxDepth;
        TerrainGenerator generator;
        List<Piece> pieces;

        private final Deque<Piece> placing = new ArrayDeque<>();

        Assembler(int maxDepth, TerrainGenerator generator,List<Piece> pieces) {
            this.maxDepth = maxDepth;
            this.generator = generator;
            this.pieces = pieces;
        }

        public void tryPlacing(VillageType villageType, Piece piece, ChunkRand rand, boolean expansionHack) {
            int depth = piece.depth;
            BPos pos = piece.pos;
            BlockRotation rotation = piece.rotation;
            PlacementBehaviour placementBehaviour = piece.placementBehaviour;
            boolean isRigid = placementBehaviour == PlacementBehaviour.RIGID;
            VoxelShape mutableobject = new VoxelShape();
            BlockBox box = piece.box;
            int minY = box.minY;
            label139:

            for (BlockJigsawInfo blockJigsawInfo : piece.getShuffledJigsawBlocks(villageType, pos, rand)) {
                //System.out.println("apres getShuffledJigsawBlocks "+ rand.nextInt());
                BlockDirection blockDirection = blockJigsawInfo.getFront();
                BPos blockPos = blockJigsawInfo.pos;
                BPos relativeBlockPos = new BPos(blockPos.getX() + blockDirection.getVector().getX(),
                        blockPos.getY() + blockDirection.getVector().getY(),
                        blockPos.getZ() + blockDirection.getVector().getZ()); //erreur in relative with vector.getZ
                int y = blockPos.getY() - minY;
                int state = -1;
                Triplet<String, List<Pair<String, Integer>>, PlacementBehaviour> pool = blockJigsawInfo.getPool();
                if (pool != null && pool.getSecond().size() != 0) {
                    String fallbackLocation = pool.getFirst();
                    Triplet<String, List<Pair<String, Integer>>, PlacementBehaviour> fallbackPool = VILLAGE_POOLS.get(fallbackLocation);
                    if (fallbackPool != null && fallbackPool.getSecond().size() != 0) {
                        JigSawPool jigSawPool1 = new JigSawPool(pool.getSecond());
                        JigSawPool jigSawPool2 = new JigSawPool(fallbackPool.getSecond());
                        //String template = rand.getRandom(jigSawPool.getTemplates());
                        boolean isInside = box.contains(relativeBlockPos);
                        VoxelShape mutableobject1;
                        int l;
                        if (isInside) {
                            mutableobject1 = mutableobject;//mutable object pas set alors qu'il le devrait
                            l = 72;
                            if (mutableobject.isNull()) {
                                mutableobject.setValue(box,true);

                            }
                        } else {
                            mutableobject1 = piece.getVoxelShape();
                            l = piece.boundsTop;
                        }
                        LinkedList<String> list = new LinkedList<String>();
                        if (depth != this.maxDepth) {
                            list = jigSawPool1.getTemplates();
                            //System.out.println("avant rand.shuffle"+ rand.nextInt());
                            if(list.size() !=0) {
                                rand.shuffle(list);
                                rand.advance(1);
                            }
                            //System.out.println("apres rand.shuffle"+ rand.nextInt());
                        }
                        LinkedList<String> listtmp = jigSawPool2.getTemplates();
                        if(listtmp.size() !=0) {
                            rand.shuffle(listtmp);
                            rand.advance(1);
                        }
                        /*int tmp = rand.nextInt();
                        System.out.println("apres listaddAll 2 "+ tmp);
                        if (tmp == -1737376018){
                            System.out.println("test");
                        }*/
                            list.addAll(listtmp);

                        for (String jigsawpiece1 : list) {
                            if (jigsawpiece1 == "empty") break;
                            for (BlockRotation rotation1 : BlockRotation.getShuffled(rand) ) {
                                BPos size1 = STRUCTURE_SIZE.get(jigsawpiece1);
                                 //le retirer plus tard on s'en fou des villageois
                                BlockBox box1;
                                if(size1 == null){
                                    box1 = new BlockBox(0,0,0,0,0,0);
                                }
                                else {
                                    box1 = BlockBox.getBoundingBox(BPos.ORIGIN, rotation1, BPos.ORIGIN, BlockMirror.NONE, size1);
                                }
                                Piece piece1 = new Piece(jigsawpiece1, BPos.ORIGIN, box1, rotation1, pool.getThird(),0); //problème quand c'est un terminator
                                /*tmp =  rand.nextInt();
                                if (tmp == -300997910){
                                    System.out.println("test");
                                }
                                System.out.println("avant getShuffledJigsawBlocks2 "+ tmp);*/
                                List<BlockJigsawInfo> list1 = piece1.getShuffledJigsawBlocks(villageType, BPos.ORIGIN, rand);
                                int i1;
                                if (expansionHack && box1.getYSpan() <= 16) {//erreur ici avec i1
                                    i1 = list1.stream().mapToInt((p_242841_2_) -> {
                                        BlockDirection dirtmp = p_242841_2_.getFront();
                                        BPos relativetmp = new BPos(p_242841_2_.pos.getX() + dirtmp.getVector().getX(),
                                                p_242841_2_.pos.getY() + dirtmp.getVector().getY(),
                                                p_242841_2_.pos.getZ() + dirtmp.getVector().getZ());
                                        if (!box1.contains(relativetmp)) {
                                            return 0;
                                        } else {
                                            Triplet<String, List<Pair<String, Integer>>, PlacementBehaviour> pool2 = p_242841_2_.getPool();
                                            String fallbackLocation2 = pool2.getFirst();
                                            Triplet<String, List<Pair<String, Integer>>, PlacementBehaviour> fallbackPool2 = VILLAGE_POOLS.get(fallbackLocation2);
                                            Triplet<String, List<Pair<String, Integer>>, PlacementBehaviour> fallbackPool3;
                                            int k3 = 0;

                                            for (String value : new JigSawPool(pool2.getSecond()).getTemplates()) {
                                                BPos sizetmp = STRUCTURE_SIZE.get(value);
                                                if (sizetmp == null) continue;
                                                int boxtmp = BlockBox.getBoundingBox(BPos.ORIGIN, BlockRotation.NONE, BPos.ORIGIN, BlockMirror.NONE, sizetmp).getYSpan();
                                                if (boxtmp > k3) k3 = boxtmp ;
                                            }
                                            int l3 = 0;
                                            if(!pool2.getFirst().equals("empty")) {
                                                for (String value : new JigSawPool(fallbackPool2.getSecond()).getTemplates()) {
                                                    BPos sizetmp = STRUCTURE_SIZE.get(value);
                                                    if (sizetmp == null) continue;
                                                    int boxtmp = BlockBox.getBoundingBox(BPos.ORIGIN, BlockRotation.NONE, BPos.ORIGIN, BlockMirror.NONE, sizetmp).getYSpan();
                                                    if (boxtmp > l3) l3 = boxtmp;
                                                }
                                            }
                                            return Math.max(k3, l3);
                                        }

                                    }).max().orElse(0);
                                } else {
                                    i1 = 0;
                                }
                                for (BlockJigsawInfo blockJigsawInfo2 : list1) {
                                    if (BlockJigsawInfo.canAttach(blockJigsawInfo, blockJigsawInfo2)) {
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
                                                state = this.generator.getFirstHeightInColumn(blockPos.getX(), blockPos.getZ(),(block) -> block != Blocks.AIR);

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
                                        if (!isNotEmpty(mutableobject1, new VoxelShape(box3, 0.25D), BoolFunc.ONLYSECOND)) {
                                            mutableobject1.setValue(joinUnoptimized(mutableobject1,new VoxelShape(box3,true),BoolFunc.ONLYFIRST));
                                            int j3 = 1; // pas tester pour toutes les valeurs
                                            /*if(isInside){
                                                mutableobject = mutableobject1;
                                            }
                                            else{
                                                piece.voxelShape = mutableobject1;
                                            }*/
                                            int l2;
                                            if(flag2){
                                                l2 =  j3-l1;
                                            }
                                            else {
                                                l2 = 1;
                                            }
                                            Piece piece2 = new Piece(jigsawpiece1,blockpos5,box3,rotation1,piece1.placementBehaviour,depth+1);

                                            if(depth+1<= this.maxDepth){
                                                this.pieces.add(piece2);
                                                piece2.setVoxelShape(mutableobject1);
                                                this.placing.addLast(piece2);
                                                System.out.println("piece ajoutée"+piece2.name);
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

        private boolean isNotEmpty(VoxelShape voxelShape, VoxelShape voxelShape1, BoolFunc func) {
            IDoubleListMerger idoublelistmerger = createIndirectMerger(voxelShape.getCoords(0), voxelShape1.getCoords(0), false, true);
            IDoubleListMerger iDouleListMerger1 = createIndirectMerger(voxelShape.getCoords(1), voxelShape1.getCoords(1), false, true);
            IDoubleListMerger idoublelistmerger2 = createIndirectMerger(voxelShape.getCoords(2), voxelShape1.getCoords(2), false, true);
            return !idoublelistmerger.forMergedIndexes((p_199861_5_, p_199861_6_, p_199861_7_) -> {
                return iDouleListMerger1.forMergedIndexes((p_199860_6_, p_199860_7_, p_199860_8_) -> {
                    return idoublelistmerger2.forMergedIndexes((p_199862_7_, p_199862_8_, p_199862_9_) -> {
                        return !func.apply(voxelShape.isFullWide(p_199861_5_, p_199860_6_, p_199862_7_), voxelShape1.isFullWide(p_199861_6_, p_199860_7_, p_199862_8_));
                    });
                });
            });
        }

        public VoxelShape joinUnoptimized(VoxelShape voxelShape, VoxelShape voxelShape1, BoolFunc func) {
            IDoubleListMerger idoublelistmerger = createIndirectMerger(voxelShape.getCoords(0), voxelShape1.getCoords(0), true, false);
            IDoubleListMerger idoublelistmerger1 = createIndirectMerger(voxelShape.getCoords(1), voxelShape1.getCoords(1), true, false);
            IDoubleListMerger idoublelistmerger2 = createIndirectMerger(voxelShape.getCoords(2), voxelShape1.getCoords(2), true, false);
            BitSetVoxelShapePart bitsetvoxelshapepart = BitSetVoxelShapePart.join(voxelShape, voxelShape1, idoublelistmerger, idoublelistmerger1, idoublelistmerger2, func);
            return new VoxelShape(bitsetvoxelshapepart, idoublelistmerger.getList(), idoublelistmerger1.getList(), idoublelistmerger2.getList());
        }

        private IDoubleListMerger createIndirectMerger(List<Double> pair1, List<Double> pair2, boolean flag3, boolean flag4) {
            int i = 0;
            int j = 0;
            double d0 = Double.NaN;
            int k = pair1.size();
            int l = pair2.size();
            int i1 = 4;
            List<Double> result = new ArrayList<Double>();
            List<Integer> firstIndices = new ArrayList<Integer>();
            List<Integer> secondIndices = new ArrayList<Integer>();
            while (true) {
                boolean flag = i < k;
                boolean flag1 = j < l;
                if (!flag && !flag1) {
                    if (result.isEmpty()) {
                        result.add(Math.min(pair1.get(k - 1), pair2.get(l - 1)));
                    }
                    return new IDoubleListMerger(result, firstIndices, secondIndices);
                }
                boolean flag2 = flag && (!flag1 || pair1.get(i) < pair2.get(j) + 1.0E-7D);
                double d1 = flag2 ? pair1.get(i++) : pair2.get(j++);
                if ((i != 0 && flag || flag2 || flag4) && (j != 0 && flag1 || !flag2 || flag3)) {
                    if (!(d0 >= d1 - 1.0E-7D)) {
                        firstIndices.add(i - 1);
                        secondIndices.add(j - 1);
                        result.add(d1);
                        d0 = d1;
                    } else if (!result.isEmpty()) {
                        firstIndices.set(firstIndices.size() - 1, i - 1);
                        secondIndices.set(secondIndices.size() - 1, j - 1);
                    }
                }


            }





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




    public enum PlacementBehaviour {
        RIGID,
        TERRAIN_MATCHING,
    }

    public static final Map<String, Triplet<String, List<Pair<String, Integer>>, PlacementBehaviour>> VILLAGE_POOLS = new HashMap<String, Triplet<String, List<Pair<String, Integer>>, PlacementBehaviour>>() {{
        put("village/desert/town_centers", new Triplet<>("empty", Arrays.asList(
                new Pair<>("village/desert/town_centers/desert_meeting_point_1", 98),
                new Pair<>("village/desert/town_centers/desert_meeting_point_2", 98),
                new Pair<>("village/desert/town_centers/desert_meeting_point_3", 49),
                new Pair<>("village/desert/zombie/town_centers/desert_meeting_point_1", 2),
                new Pair<>("village/desert/zombie/town_centers/desert_meeting_point_2", 2),
                new Pair<>("village/desert/zombie/town_centers/desert_meeting_point_3", 1)
        ), PlacementBehaviour.RIGID));
        put("village/desert/streets", new Triplet<>("village/desert/terminators", Arrays.asList(
                new Pair<>("village/desert/streets/corner_01", 3),
                new Pair<>("village/desert/streets/corner_02", 3),
                new Pair<>("village/desert/streets/straight_01", 4),
                new Pair<>("village/desert/streets/straight_02", 4),
                new Pair<>("village/desert/streets/straight_03", 3),
                new Pair<>("village/desert/streets/crossroad_01", 3),
                new Pair<>("village/desert/streets/crossroad_02", 3),
                new Pair<>("village/desert/streets/crossroad_03", 3),
                new Pair<>("village/desert/streets/square_01", 3),
                new Pair<>("village/desert/streets/square_02", 3),
                new Pair<>("village/desert/streets/turn_01", 3)
        ), PlacementBehaviour.TERRAIN_MATCHING));
        put("village/desert/zombie/streets", new Triplet<>("village/desert/zombie/terminators", Arrays.asList(
                new Pair<>("village/desert/zombie/streets/corner_01", 3),
                new Pair<>("village/desert/zombie/streets/corner_02", 3),
                new Pair<>("village/desert/zombie/streets/straight_01", 4),
                new Pair<>("village/desert/zombie/streets/straight_02", 4),
                new Pair<>("village/desert/zombie/streets/straight_03", 3),
                new Pair<>("village/desert/zombie/streets/crossroad_01", 3),
                new Pair<>("village/desert/zombie/streets/crossroad_02", 3),
                new Pair<>("village/desert/zombie/streets/crossroad_03", 3),
                new Pair<>("village/desert/zombie/streets/square_01", 3),
                new Pair<>("village/desert/zombie/streets/square_02", 3),
                new Pair<>("village/desert/zombie/streets/turn_01", 3)
        ), PlacementBehaviour.TERRAIN_MATCHING));
        put("village/desert/houses", new Triplet<>("village/desert/terminators", Arrays.asList(
                new Pair<>("village/desert/houses/desert_small_house_1", 2),
                new Pair<>("village/desert/houses/desert_small_house_2", 2),
                new Pair<>("village/desert/houses/desert_small_house_3", 2),
                new Pair<>("village/desert/houses/desert_small_house_4", 2),
                new Pair<>("village/desert/houses/desert_small_house_5", 2),
                new Pair<>("village/desert/houses/desert_small_house_6", 1),
                new Pair<>("village/desert/houses/desert_small_house_7", 2),
                new Pair<>("village/desert/houses/desert_small_house_8", 2),
                new Pair<>("village/desert/houses/desert_medium_house_1", 2),
                new Pair<>("village/desert/houses/desert_medium_house_2", 2),
                new Pair<>("village/desert/houses/desert_butcher_shop_1", 2),
                new Pair<>("village/desert/houses/desert_tool_smith_1", 2),
                new Pair<>("village/desert/houses/desert_fletcher_house_1", 2),
                new Pair<>("village/desert/houses/desert_shepherd_house_1", 2),
                new Pair<>("village/desert/houses/desert_armorer_1", 1),
                new Pair<>("village/desert/houses/desert_fisher_1", 2),
                new Pair<>("village/desert/houses/desert_tannery_1", 2),
                new Pair<>("village/desert/houses/desert_cartographer_house_1", 2),
                new Pair<>("village/desert/houses/desert_library_1", 2),
                new Pair<>("village/desert/houses/desert_mason_1", 2),
                new Pair<>("village/desert/houses/desert_weaponsmith_1", 2),
                new Pair<>("village/desert/houses/desert_temple_1", 2),
                new Pair<>("village/desert/houses/desert_temple_2", 2),
                new Pair<>("village/desert/houses/desert_large_farm_1", 11),
                new Pair<>("village/desert/houses/desert_farm_1", 4),
                new Pair<>("village/desert/houses/desert_farm_2", 4),
                new Pair<>("village/desert/houses/desert_animal_pen_1", 2),
                new Pair<>("village/desert/houses/desert_animal_pen_2", 2),
                new Pair<>("empty", 5)
        ), PlacementBehaviour.RIGID));
        put("village/desert/zombie/houses", new Triplet<>("village/desert/zombie/terminators", Arrays.asList(
                new Pair<>("village/desert/zombie/houses/desert_small_house_1", 2),
                new Pair<>("village/desert/zombie/houses/desert_small_house_2", 2),
                new Pair<>("village/desert/zombie/houses/desert_small_house_3", 2),
                new Pair<>("village/desert/zombie/houses/desert_small_house_4", 2),
                new Pair<>("village/desert/zombie/houses/desert_small_house_5", 2),
                new Pair<>("village/desert/zombie/houses/desert_small_house_6", 1),
                new Pair<>("village/desert/zombie/houses/desert_small_house_7", 2),
                new Pair<>("village/desert/zombie/houses/desert_small_house_8", 2),
                new Pair<>("village/desert/zombie/houses/desert_medium_house_1", 2),
                new Pair<>("village/desert/zombie/houses/desert_medium_house_2", 2),
                new Pair<>("village/desert/houses/desert_butcher_shop_1", 2),
                new Pair<>("village/desert/houses/desert_tool_smith_1", 2),
                new Pair<>("village/desert/houses/desert_fletcher_house_1", 2),
                new Pair<>("village/desert/houses/desert_shepherd_house_1", 2),
                new Pair<>("village/desert/houses/desert_armorer_1", 1),
                new Pair<>("village/desert/houses/desert_fisher_1", 2),
                new Pair<>("village/desert/houses/desert_tannery_1", 2),
                new Pair<>("village/desert/houses/desert_cartographer_house_1", 2),
                new Pair<>("village/desert/houses/desert_library_1", 2),
                new Pair<>("village/desert/houses/desert_mason_1", 2),
                new Pair<>("village/desert/houses/desert_weaponsmith_1", 2),
                new Pair<>("village/desert/houses/desert_temple_1", 2),
                new Pair<>("village/desert/houses/desert_temple_2", 2),
                new Pair<>("village/desert/houses/desert_large_farm_1", 7),
                new Pair<>("village/desert/houses/desert_farm_1", 4),
                new Pair<>("village/desert/houses/desert_farm_2", 4),
                new Pair<>("village/desert/houses/desert_animal_pen_1", 2),
                new Pair<>("village/desert/houses/desert_animal_pen_2", 2),
                new Pair<>("empty", 5)
        ), PlacementBehaviour.RIGID));
        put("village/desert/terminators", new Triplet<>("empty", Arrays.asList(
                new Pair<>("village/desert/terminators/terminator_01", 1),
                new Pair<>("village/desert/terminators/terminator_02", 1)
        ), PlacementBehaviour.TERRAIN_MATCHING));
        put("village/desert/zombie/terminators", new Triplet<>("empty", Arrays.asList(
                new Pair<>("village/desert/terminators/terminator_01", 1),
                new Pair<>("village/desert/zombie/terminators/terminator_02", 1)
        ), PlacementBehaviour.TERRAIN_MATCHING));
        put("village/desert/decor", new Triplet<>("empty", Arrays.asList(
                new Pair<>("village/desert/desert_lamp_1", 10),
                new Pair<>("patch_cactus", 4),
                new Pair<>("pile_hay", 4),
                new Pair<>("empty", 10)
        ), PlacementBehaviour.RIGID));
        put("village/desert/zombie/decor", new Triplet<>("empty", Arrays.asList(
                new Pair<>("village/desert/desert_lamp_1", 10),
                new Pair<>("village/desert/patch_cactus", 4),
                new Pair<>("village/desert/pile_hay", 4),
                new Pair<>("empty", 10)
        ), PlacementBehaviour.RIGID));
        put("village/desert/villagers", new Triplet<>("empty", Arrays.asList(
                new Pair<>("village/desert/villagers/nitwit", 1),
                new Pair<>("village/desert/villagers/baby", 1),
                new Pair<>("village/desert/villagers/unemployed", 10)
        ), PlacementBehaviour.RIGID));
        put("village/desert/zombie/villagers", new Triplet<>("empty", Arrays.asList(
                new Pair<>("village/desert/zombie/villagers/nitwit", 1),
                new Pair<>("village/desert/zombie/villagers/unemployed", 10)
        ), PlacementBehaviour.RIGID));

        put("village/plains/streets", new Triplet<>("village/plains/terminators", Arrays.asList(
                new Pair<>("village/plains/streets/corner_01", 2),
                new Pair<>("village/plains/streets/corner_02", 2),
                new Pair<>("village/plains/streets/corner_03", 2),
                new Pair<>("village/plains/streets/straight_01", 4),
                new Pair<>("village/plains/streets/straight_02", 4),
                new Pair<>("village/plains/streets/straight_03", 7),
                new Pair<>("village/plains/streets/straight_04", 7),
                new Pair<>("village/plains/streets/straight_05", 3),
                new Pair<>("village/plains/streets/straight_06", 4),
                new Pair<>("village/plains/streets/crossroad_01", 2),
                new Pair<>("village/plains/streets/crossroad_02", 1),
                new Pair<>("village/plains/streets/crossroad_03", 2),
                new Pair<>("village/plains/streets/crossroad_04", 2),
                new Pair<>("village/plains/streets/crossroad_05", 2),
                new Pair<>("village/plains/streets/crossroad_06", 2),
                new Pair<>("village/plains/streets/turn_01", 3)
        ), PlacementBehaviour.TERRAIN_MATCHING));
        put("village/plains/zombie/streets", new Triplet<>("village/plains/terminators", Arrays.asList(
                new Pair<>("village/plains/zombie/streets/corner_01", 2),
                new Pair<>("village/plains/zombie/streets/corner_02", 2),
                new Pair<>("village/plains/zombie/streets/corner_03", 2),
                new Pair<>("village/plains/zombie/streets/straight_01", 4),
                new Pair<>("village/plains/zombie/streets/straight_02", 4),
                new Pair<>("village/plains/zombie/streets/straight_03", 7),
                new Pair<>("village/plains/zombie/streets/straight_04", 7),
                new Pair<>("village/plains/zombie/streets/straight_05", 3),
                new Pair<>("village/plains/zombie/streets/straight_06", 4),
                new Pair<>("village/plains/zombie/streets/crossroad_01", 2),
                new Pair<>("village/plains/zombie/streets/crossroad_02", 1),
                new Pair<>("village/plains/zombie/streets/crossroad_03", 2),
                new Pair<>("village/plains/zombie/streets/crossroad_04", 2),
                new Pair<>("village/plains/zombie/streets/crossroad_05", 2),
                new Pair<>("village/plains/zombie/streets/crossroad_06", 2),
                new Pair<>("village/plains/zombie/streets/turn_01", 3)
        ), PlacementBehaviour.TERRAIN_MATCHING));
        put("village/plains/houses", new Triplet<>("village/plains/terminators", Arrays.asList(
                new Pair<>("village/plains/houses/plains_small_house_1", 2),
                new Pair<>("village/plains/houses/plains_small_house_2", 2),
                new Pair<>("village/plains/houses/plains_small_house_3", 2),
                new Pair<>("village/plains/houses/plains_small_house_4", 2),
                new Pair<>("village/plains/houses/plains_small_house_5", 2),
                new Pair<>("village/plains/houses/plains_small_house_6", 1),
                new Pair<>("village/plains/houses/plains_small_house_7", 2),
                new Pair<>("village/plains/houses/plains_small_house_8", 3),
                new Pair<>("village/plains/houses/plains_medium_house_1", 2),
                new Pair<>("village/plains/houses/plains_medium_house_2", 2),
                new Pair<>("village/plains/houses/plains_big_house_1", 2),
                new Pair<>("village/plains/houses/plains_butcher_shop_1", 2),
                new Pair<>("village/plains/houses/plains_butcher_shop_2", 2),
                new Pair<>("village/plains/houses/plains_tool_smith_1", 2),
                new Pair<>("village/plains/houses/plains_fletcher_house_1", 2),
                new Pair<>("village/plains/houses/plains_shepherds_house_1", 2),
                new Pair<>("village/plains/houses/plains_armorer_house_1", 2),
                new Pair<>("village/plains/houses/plains_fisher_cottage_1", 2),
                new Pair<>("village/plains/houses/plains_tannery_1", 2),
                new Pair<>("village/plains/houses/plains_cartographer_1", 1),
                new Pair<>("village/plains/houses/plains_library_1", 5),
                new Pair<>("village/plains/houses/plains_library_2", 1),
                new Pair<>("village/plains/houses/plains_masons_house_1", 2),
                new Pair<>("village/plains/houses/plains_weaponsmith_1", 2),
                new Pair<>("village/plains/houses/plains_temple_3", 2),
                new Pair<>("village/plains/houses/plains_temple_4", 2),
                new Pair<>("village/plains/houses/plains_stable_1", 2),
                new Pair<>("village/plains/houses/plains_stable_2", 2),
                new Pair<>("village/plains/houses/plains_large_farm_1", 4),
                new Pair<>("village/plains/houses/plains_small_farm_1", 4),
                new Pair<>("village/plains/houses/plains_animal_pen_1", 1),
                new Pair<>("village/plains/houses/plains_animal_pen_2", 1),
                new Pair<>("village/plains/houses/plains_animal_pen_3", 5),
                new Pair<>("village/plains/houses/plains_accessory_1", 1),
                new Pair<>("village/plains/houses/plains_meeting_point_4", 3),
                new Pair<>("village/plains/houses/plains_meeting_point_5", 1),
                new Pair<>("empty", 10)
        ), PlacementBehaviour.RIGID));
        put("village/plains/zombie/houses", new Triplet<>("village/plains/terminators", Arrays.asList(
                new Pair<>("village/plains/zombie/houses/plains_small_house_1", 2),
                new Pair<>("village/plains/zombie/houses/plains_small_house_2", 2),
                new Pair<>("village/plains/zombie/houses/plains_small_house_3", 2),
                new Pair<>("village/plains/zombie/houses/plains_small_house_4", 2),
                new Pair<>("village/plains/zombie/houses/plains_small_house_5", 2),
                new Pair<>("village/plains/zombie/houses/plains_small_house_6", 1),
                new Pair<>("village/plains/zombie/houses/plains_small_house_7", 2),
                new Pair<>("village/plains/zombie/houses/plains_small_house_8", 2),
                new Pair<>("village/plains/zombie/houses/plains_medium_house_1", 2),
                new Pair<>("village/plains/zombie/houses/plains_medium_house_2", 2),
                new Pair<>("village/plains/zombie/houses/plains_big_house_1", 2),
                new Pair<>("village/plains/houses/plains_butcher_shop_1", 2),
                new Pair<>("village/plains/zombie/houses/plains_butcher_shop_2", 2),
                new Pair<>("village/plains/houses/plains_tool_smith_1", 2),
                new Pair<>("village/plains/zombie/houses/plains_fletcher_house_1", 2),
                new Pair<>("village/plains/zombie/houses/plains_shepherds_house_1", 2),
                new Pair<>("village/plains/houses/plains_armorer_house_1", 2),
                new Pair<>("village/plains/houses/plains_fisher_cottage_1", 2),
                new Pair<>("village/plains/houses/plains_tannery_1", 2),
                new Pair<>("village/plains/houses/plains_cartographer_1", 1),
                new Pair<>("village/plains/houses/plains_library_1", 3),
                new Pair<>("village/plains/houses/plains_library_2", 1),
                new Pair<>("village/plains/houses/plains_masons_house_1", 2),
                new Pair<>("village/plains/houses/plains_weaponsmith_1", 2),
                new Pair<>("village/plains/houses/plains_temple_3", 2),
                new Pair<>("village/plains/houses/plains_temple_4", 2),
                new Pair<>("village/plains/zombie/houses/plains_stable_1", 2),
                new Pair<>("village/plains/houses/plains_stable_2", 2),
                new Pair<>("village/plains/houses/plains_large_farm_1", 4),
                new Pair<>("village/plains/houses/plains_small_farm_1", 4),
                new Pair<>("village/plains/houses/plains_animal_pen_1", 1),
                new Pair<>("village/plains/houses/plains_animal_pen_2", 1),
                new Pair<>("village/plains/zombie/houses/plains_animal_pen_3", 5),
                new Pair<>("village/plains/zombie/houses/plains_meeting_point_4", 3),
                new Pair<>("village/plains/zombie/houses/plains_meeting_point_5", 1),
                new Pair<>("empty", 10)
        ), PlacementBehaviour.RIGID));
        put("village/plains/terminators", new Triplet<>("empty", Arrays.asList(
                new Pair<>("village/plains/terminators/terminator_01", 1),
                new Pair<>("village/plains/terminators/terminator_02", 1),
                new Pair<>("village/plains/terminators/terminator_03", 1),
                new Pair<>("village/plains/terminators/terminator_04", 1)
        ), PlacementBehaviour.TERRAIN_MATCHING));
        put("village/plains/trees", new Triplet<>("empty", Collections.singletonList(
                new Pair<>("village/oak", 1)
        ), PlacementBehaviour.RIGID));
        put("village/plains/decor", new Triplet<>("empty", Arrays.asList(
                new Pair<>("village/plains/plains_lamp_1", 2),
                new Pair<>("village/oak", 1),
                new Pair<>("village/flower_plain", 1),
                new Pair<>("village/pile_hay", 1),
                new Pair<>("empty", 2)
        ), PlacementBehaviour.RIGID));
        put("village/plains/zombie/decor", new Triplet<>("empty", Arrays.asList(
                new Pair<>("village/plains/plains_lamp_1", 1),
                new Pair<>("village/oak", 1),
                new Pair<>("village/flower_plain", 1),
                new Pair<>("village/pile_hay", 1),
                new Pair<>("empty", 2)
        ), PlacementBehaviour.RIGID));
        put("village/plains/villagers", new Triplet<>("empty", Arrays.asList(
                new Pair<>("plains/villagers/nitwit", 1),
                new Pair<>("plains/villagers/baby", 1),
                new Pair<>("plains/villagers/unemployed", 10)
        ), PlacementBehaviour.RIGID));
        put("village/plains/zombie/villagers", new Triplet<>("empty", Arrays.asList(
                new Pair<>("plains/zombie/villagers/nitwit", 1),
                new Pair<>("plains/zombie/villagers/unemployed", 10)
        ), PlacementBehaviour.RIGID));
        put("village/common/animals", new Triplet<>("empty", Arrays.asList(
                new Pair<>("common/animals/cows_1", 7),
                new Pair<>("common/animals/pigs_1", 7),
                new Pair<>("common/animals/horses_1", 1),
                new Pair<>("common/animals/horses_2", 1),
                new Pair<>("common/animals/horses_3", 1),
                new Pair<>("common/animals/horses_4", 1),
                new Pair<>("common/animals/horses_5", 1),
                new Pair<>("common/animals/sheep_1", 1),
                new Pair<>("common/animals/sheep_2", 1),
                new Pair<>("empty", 5)
        ), PlacementBehaviour.RIGID));
        put("village/common/sheep", new Triplet<>("empty", Arrays.asList(
                new Pair<>("common/animals/sheep_1", 1),
                new Pair<>("common/animals/sheep_2", 1)
        ), PlacementBehaviour.RIGID));
        put("village/common/cats", new Triplet<>("empty", Arrays.asList(
                new Pair<>("village/common/animals/cat_black", 1),
                new Pair<>("village/common/animals/cat_british", 1),
                new Pair<>("village/common/animals/cat_calico", 1),
                new Pair<>("village/common/animals/cat_persia", 1),
                new Pair<>("village/common/animals/cat_ragdoll", 1),
                new Pair<>("village/common/animals/cat_red", 1),
                new Pair<>("village/common/animals/cat_siamese", 1),
                new Pair<>("village/common/animals/cat_tabby", 1),
                new Pair<>("village/common/animals/cat_white", 1),
                new Pair<>("village/common/animals/cat_jellie", 1),
                new Pair<>("empty", 3)
        ), PlacementBehaviour.RIGID));
        put("village/common/butcher_animals", new Triplet<>("empty", Arrays.asList(
                new Pair<>("village/common/animals/cows_1", 3),
                new Pair<>("village/common/animals/pigs_1", 3),
                new Pair<>("village/common/animals/sheep_1", 1),
                new Pair<>("village/common/animals/sheep_2", 1)
        ), PlacementBehaviour.RIGID));
        put("village/common/iron_golem", new Triplet<>("empty", Collections.singletonList(
                new Pair<>("village/common/iron_golem", 1)
        ), PlacementBehaviour.RIGID));
        put("village/common/well_bottoms", new Triplet<>("empty", Collections.singletonList(
                new Pair<>("village/common/well_bottom", 1)
        ), PlacementBehaviour.RIGID));
        put("empty", new Triplet<>("empty",Collections.singletonList(
                new Pair<>("empty", 0)
        ), PlacementBehaviour.RIGID));
    }};

    //import nbtlib
    //from pathlib import *
    //import sys
    //
    //p = Path(r'.').glob('**/*.nbt')
    //files = [x for x in p if x.is_file()]
    //for file in files:
    //    nbt_file=nbtlib.load(file)
    //    root=nbt_file.root
    //    if "size" in root.keys():
    //        parents=str(file.parents[0]).replace("\\","/")
    //        print(f'STRUCTURE_SIZE.put("{parents}/{file.name.rstrip(".nbt")}",new BPos({",".join(map(str,map(int,root["size"])))}));')
    //    else:
    //        print(f'Missing size key for {file.parents[-1]}/{file.name.rstrip(".nbt")}')
    //        sys.exit(1)
    private static final HashMap<String, BPos> STRUCTURE_SIZE = new HashMap<String, BPos>() {{
        this.put("village/common/iron_golem", new BPos(1, 3, 1));
        this.put("village/common/well_bottom", new BPos(4, 3, 4));
        this.put("village/common/animals/cat_black", new BPos(1, 3, 1));
        this.put("village/common/animals/cat_british", new BPos(1, 3, 1));
        this.put("village/common/animals/cat_calico", new BPos(1, 3, 1));
        this.put("village/common/animals/cat_jellie", new BPos(1, 3, 1));
        this.put("village/common/animals/cat_persia", new BPos(1, 3, 1));
        this.put("village/common/animals/cat_ragdoll", new BPos(1, 3, 1));
        this.put("village/common/animals/cat_red", new BPos(1, 3, 1));
        this.put("village/common/animals/cat_siamese", new BPos(1, 3, 1));
        this.put("village/common/animals/cat_tabby", new BPos(1, 3, 1));
        this.put("village/common/animals/cat_white", new BPos(1, 3, 1));
        this.put("village/common/animals/cows_1", new BPos(1, 3, 1));
        this.put("village/common/animals/horses_1", new BPos(1, 3, 1));
        this.put("village/common/animals/horses_2", new BPos(1, 3, 1));
        this.put("village/common/animals/horses_3", new BPos(1, 3, 1));
        this.put("village/common/animals/horses_4", new BPos(1, 3, 1));
        this.put("village/common/animals/horses_5", new BPos(1, 3, 1));
        this.put("village/common/animals/pigs_1", new BPos(1, 3, 1));
        this.put("village/common/animals/sheep_1", new BPos(1, 3, 1));
        this.put("village/common/animals/sheep_2", new BPos(1, 3, 1));
        this.put("decays/grass_11x13", new BPos(13, 1, 11));
        this.put("decays/grass_16x16", new BPos(16, 1, 16));
        this.put("decays/grass_9x9", new BPos(9, 1, 9));
        this.put("village/desert/desert_lamp_1", new BPos(1, 4, 1));
        this.put("village/desert/houses/desert_animal_pen_1", new BPos(10, 6, 7));
        this.put("village/desert/houses/desert_animal_pen_2", new BPos(10, 6, 8));
        this.put("village/desert/houses/desert_armorer_1", new BPos(7, 7, 7));
        this.put("village/desert/houses/desert_butcher_shop_1", new BPos(8, 5, 8));
        this.put("village/desert/houses/desert_cartographer_house_1", new BPos(7, 7, 7));
        this.put("village/desert/houses/desert_farm_1", new BPos(5, 6, 7));
        this.put("village/desert/houses/desert_farm_2", new BPos(7, 7, 10));
        this.put("village/desert/houses/desert_fisher_1", new BPos(8, 6, 11));
        this.put("village/desert/houses/desert_fletcher_house_1", new BPos(6, 12, 12));
        this.put("village/desert/houses/desert_large_farm_1", new BPos(11, 7, 13));
        this.put("village/desert/houses/desert_library_1", new BPos(9, 7, 5));
        this.put("village/desert/houses/desert_mason_1", new BPos(7, 5, 8));
        this.put("village/desert/houses/desert_medium_house_1", new BPos(6, 6, 7));
        this.put("village/desert/houses/desert_medium_house_2", new BPos(11, 9, 7));
        this.put("village/desert/houses/desert_shepherd_house_1", new BPos(11, 6, 5));
        this.put("village/desert/houses/desert_small_house_1", new BPos(6, 6, 5));
        this.put("village/desert/houses/desert_small_house_2", new BPos(7, 6, 5));
        this.put("village/desert/houses/desert_small_house_3", new BPos(5, 5, 6));
        this.put("village/desert/houses/desert_small_house_4", new BPos(5, 5, 5));
        this.put("village/desert/houses/desert_small_house_5", new BPos(5, 6, 6));
        this.put("village/desert/houses/desert_small_house_6", new BPos(6, 18, 5));
        this.put("village/desert/houses/desert_small_house_7", new BPos(8, 5, 7));
        this.put("village/desert/houses/desert_small_house_8", new BPos(5, 5, 5));
        this.put("village/desert/houses/desert_tannery_1", new BPos(7, 10, 6));
        this.put("village/desert/houses/desert_temple_1", new BPos(11, 7, 10));
        this.put("village/desert/houses/desert_temple_2", new BPos(10, 6, 12));
        this.put("village/desert/houses/desert_tool_smith_1", new BPos(9, 9, 9));
        this.put("village/desert/houses/desert_weaponsmith_1", new BPos(10, 6, 7));
        this.put("village/desert/streets/corner_01", new BPos(7, 2, 15));
        this.put("village/desert/streets/corner_02", new BPos(6, 2, 6));
        this.put("village/desert/streets/crossroad_01", new BPos(18, 2, 15));
        this.put("village/desert/streets/crossroad_02", new BPos(11, 2, 11));
        this.put("village/desert/streets/crossroad_03", new BPos(5, 2, 5));
        this.put("village/desert/streets/square_01", new BPos(13, 2, 28));
        this.put("village/desert/streets/square_02", new BPos(16, 2, 19));
        this.put("village/desert/streets/straight_01", new BPos(15, 2, 12));
        this.put("village/desert/streets/straight_02", new BPos(15, 2, 18));
        this.put("village/desert/streets/straight_03", new BPos(4, 2, 3));
        this.put("village/desert/streets/turn_01", new BPos(4, 2, 4));
        this.put("village/desert/terminators/terminator_01", new BPos(3, 2, 3));
        this.put("village/desert/terminators/terminator_02", new BPos(3, 2, 3));
        this.put("village/desert/town_centers/desert_meeting_point_1", new BPos(17, 6, 9));
        this.put("village/desert/town_centers/desert_meeting_point_2", new BPos(12, 6, 12));
        this.put("village/desert/town_centers/desert_meeting_point_3", new BPos(15, 6, 15));
        this.put("village/desert/villagers/baby", new BPos(1, 2, 1));
        this.put("village/desert/villagers/nitwi", new BPos(1, 3, 1));
        this.put("village/desert/villagers/unemployed", new BPos(1, 3, 1));
        this.put("village/desert/zombie/houses/desert_medium_house_1", new BPos(6, 6, 7));
        this.put("village/desert/zombie/houses/desert_medium_house_2", new BPos(11, 9, 7));
        this.put("village/desert/zombie/houses/desert_small_house_1", new BPos(6, 6, 5));
        this.put("village/desert/zombie/houses/desert_small_house_2", new BPos(7, 6, 5));
        this.put("village/desert/zombie/houses/desert_small_house_3", new BPos(5, 5, 6));
        this.put("village/desert/zombie/houses/desert_small_house_4", new BPos(5, 5, 5));
        this.put("village/desert/zombie/houses/desert_small_house_5", new BPos(5, 6, 6));
        this.put("village/desert/zombie/houses/desert_small_house_6", new BPos(5, 17, 5));
        this.put("village/desert/zombie/houses/desert_small_house_7", new BPos(8, 5, 7));
        this.put("village/desert/zombie/houses/desert_small_house_8", new BPos(5, 5, 5));
        this.put("village/desert/zombie/streets/corner_01", new BPos(7, 2, 15));
        this.put("village/desert/zombie/streets/corner_02", new BPos(6, 2, 6));
        this.put("village/desert/zombie/streets/crossroad_01", new BPos(18, 2, 15));
        this.put("village/desert/zombie/streets/crossroad_02", new BPos(11, 2, 11));
        this.put("village/desert/zombie/streets/crossroad_03", new BPos(5, 2, 5));
        this.put("village/desert/zombie/streets/square_01", new BPos(13, 2, 28));
        this.put("village/desert/zombie/streets/square_02", new BPos(16, 2, 19));
        this.put("village/desert/zombie/streets/straight_01", new BPos(15, 2, 12));
        this.put("village/desert/zombie/streets/straight_02", new BPos(15, 2, 18));
        this.put("village/desert/zombie/streets/straight_03", new BPos(4, 2, 3));
        this.put("village/desert/zombie/streets/turn_01", new BPos(4, 2, 4));
        this.put("village/desert/zombie/terminators/terminator_02", new BPos(3, 2, 3));
        this.put("village/desert/zombie/town_centers/desert_meeting_point_1", new BPos(17, 6, 9));
        this.put("village/desert/zombie/town_centers/desert_meeting_point_2", new BPos(12, 6, 12));
        this.put("village/desert/zombie/town_centers/desert_meeting_point_3", new BPos(15, 6, 15));
        this.put("village/desert/zombie/villagers/nitwi", new BPos(1, 3, 1));
        this.put("village/desert/zombie/villagers/unemployed", new BPos(1, 3, 1));
        this.put("village/plains/plains_lamp_1", new BPos(3, 4, 3));
        this.put("village/plains/houses/plains_accessory_1", new BPos(3, 2, 5));
        this.put("village/plains/houses/plains_animal_pen_1", new BPos(5, 8, 6));
        this.put("village/plains/houses/plains_animal_pen_2", new BPos(7, 7, 11));
        this.put("village/plains/houses/plains_animal_pen_3", new BPos(8, 6, 11));
        this.put("village/plains/houses/plains_armorer_house_1", new BPos(9, 8, 8));
        this.put("village/plains/houses/plains_big_house_1", new BPos(7, 11, 11));
        this.put("village/plains/houses/plains_butcher_shop_1", new BPos(11, 8, 12));
        this.put("village/plains/houses/plains_butcher_shop_2", new BPos(15, 12, 7));
        this.put("village/plains/houses/plains_cartographer_1", new BPos(10, 8, 7));
        this.put("village/plains/houses/plains_fisher_cottage_1", new BPos(11, 9, 10));
        this.put("village/plains/houses/plains_fletcher_house_1", new BPos(9, 7, 11));
        this.put("village/plains/houses/plains_large_farm_1", new BPos(13, 6, 9));
        this.put("village/plains/houses/plains_library_1", new BPos(11, 10, 17));
        this.put("village/plains/houses/plains_library_2", new BPos(8, 10, 9));
        this.put("village/plains/houses/plains_masons_house_1", new BPos(8, 7, 9));
        this.put("village/plains/houses/plains_medium_house_1", new BPos(13, 8, 11));
        this.put("village/plains/houses/plains_medium_house_2", new BPos(7, 6, 13));
        this.put("village/plains/houses/plains_meeting_point_4", new BPos(10, 7, 16));
        this.put("village/plains/houses/plains_meeting_point_5", new BPos(10, 6, 11));
        this.put("village/plains/houses/plains_shepherds_house_1", new BPos(9, 6, 13));
        this.put("village/plains/houses/plains_small_farm_1", new BPos(7, 6, 9));
        this.put("village/plains/houses/plains_small_house_1", new BPos(7, 7, 7));
        this.put("village/plains/houses/plains_small_house_2", new BPos(7, 7, 7));
        this.put("village/plains/houses/plains_small_house_3", new BPos(7, 7, 7));
        this.put("village/plains/houses/plains_small_house_4", new BPos(7, 7, 7));
        this.put("village/plains/houses/plains_small_house_5", new BPos(9, 11, 9));
        this.put("village/plains/houses/plains_small_house_6", new BPos(7, 7, 7));
        this.put("village/plains/houses/plains_small_house_7", new BPos(7, 7, 8));
        this.put("village/plains/houses/plains_small_house_8", new BPos(8, 9, 9));
        this.put("village/plains/houses/plains_stable_1", new BPos(9, 7, 16));
        this.put("village/plains/houses/plains_stable_2", new BPos(7, 6, 17));
        this.put("village/plains/houses/plains_tannery_1", new BPos(8, 7, 10));
        this.put("village/plains/houses/plains_temple_3", new BPos(11, 7, 7));
        this.put("village/plains/houses/plains_temple_4", new BPos(10, 12, 7));
        this.put("village/plains/houses/plains_tool_smith_1", new BPos(9, 6, 12));
        this.put("village/plains/houses/plains_weaponsmith_1", new BPos(9, 8, 11));
        this.put("village/plains/streets/corner_01", new BPos(16, 2, 16));
        this.put("village/plains/streets/corner_02", new BPos(16, 2, 16));
        this.put("village/plains/streets/corner_03", new BPos(4, 2, 4));
        this.put("village/plains/streets/crossroad_01", new BPos(16, 2, 16));
        this.put("village/plains/streets/crossroad_02", new BPos(16, 2, 16));
        this.put("village/plains/streets/crossroad_03", new BPos(16, 2, 16));
        this.put("village/plains/streets/crossroad_04", new BPos(4, 2, 5));
        this.put("village/plains/streets/crossroad_05", new BPos(5, 2, 5));
        this.put("village/plains/streets/crossroad_06", new BPos(5, 2, 5));
        this.put("village/plains/streets/straight_01", new BPos(16, 2, 16));
        this.put("village/plains/streets/straight_02", new BPos(16, 2, 16));
        this.put("village/plains/streets/straight_03", new BPos(13, 2, 11));
        this.put("village/plains/streets/straight_04", new BPos(11, 2, 9));
        this.put("village/plains/streets/straight_05", new BPos(20, 2, 17));
        this.put("village/plains/streets/straight_06", new BPos(21, 2, 18));
        this.put("village/plains/streets/turn_01", new BPos(18, 2, 8));
        this.put("village/plains/terminators/terminator_01", new BPos(2, 2, 3));
        this.put("village/plains/terminators/terminator_02", new BPos(1, 2, 1));
        this.put("village/plains/terminators/terminator_03", new BPos(3, 2, 3));
        this.put("village/plains/terminators/terminator_04", new BPos(4, 2, 4));
        this.put("village/plains/town_centers/plains_fountain_01", new BPos(9, 4, 9));
        this.put("village/plains/town_centers/plains_meeting_point_1", new BPos(10, 7, 10));
        this.put("village/plains/town_centers/plains_meeting_point_2", new BPos(8, 5, 15));
        this.put("village/plains/town_centers/plains_meeting_point_3", new BPos(11, 9, 11));
        this.put("village/plains/villagers/baby", new BPos(1, 2, 1));
        this.put("village/plains/villagers/nitwi", new BPos(1, 3, 1));
        this.put("village/plains/villagers/unemployed", new BPos(1, 3, 1));
        this.put("village/plains/zombie/houses/plains_animal_pen_3", new BPos(8, 6, 11));
        this.put("village/plains/zombie/houses/plains_big_house_1", new BPos(7, 11, 11));
        this.put("village/plains/zombie/houses/plains_butcher_shop_2", new BPos(15, 12, 7));
        this.put("village/plains/zombie/houses/plains_fletcher_house_1", new BPos(9, 7, 11));
        this.put("village/plains/zombie/houses/plains_medium_house_1", new BPos(13, 8, 11));
        this.put("village/plains/zombie/houses/plains_medium_house_2", new BPos(7, 6, 13));
        this.put("village/plains/zombie/houses/plains_meeting_point_4", new BPos(10, 7, 16));
        this.put("village/plains/zombie/houses/plains_meeting_point_5", new BPos(10, 6, 11));
        this.put("village/plains/zombie/houses/plains_shepherds_house_1", new BPos(9, 6, 13));
        this.put("village/plains/zombie/houses/plains_small_house_1", new BPos(7, 7, 7));
        this.put("village/plains/zombie/houses/plains_small_house_2", new BPos(7, 7, 7));
        this.put("village/plains/zombie/houses/plains_small_house_3", new BPos(7, 7, 7));
        this.put("village/plains/zombie/houses/plains_small_house_4", new BPos(7, 7, 7));
        this.put("village/plains/zombie/houses/plains_small_house_5", new BPos(9, 11, 9));
        this.put("village/plains/zombie/houses/plains_small_house_6", new BPos(7, 7, 7));
        this.put("village/plains/zombie/houses/plains_small_house_7", new BPos(7, 7, 8));
        this.put("village/plains/zombie/houses/plains_small_house_8", new BPos(8, 9, 9));
        this.put("village/plains/zombie/houses/plains_stable_1", new BPos(9, 7, 16));
        this.put("village/plains/zombie/streets/corner_01", new BPos(16, 2, 16));
        this.put("village/plains/zombie/streets/corner_02", new BPos(16, 2, 16));
        this.put("village/plains/zombie/streets/corner_03", new BPos(4, 2, 4));
        this.put("village/plains/zombie/streets/crossroad_01", new BPos(16, 2, 16));
        this.put("village/plains/zombie/streets/crossroad_02", new BPos(16, 2, 16));
        this.put("village/plains/zombie/streets/crossroad_03", new BPos(16, 2, 16));
        this.put("village/plains/zombie/streets/crossroad_04", new BPos(4, 2, 5));
        this.put("village/plains/zombie/streets/crossroad_05", new BPos(5, 2, 5));
        this.put("village/plains/zombie/streets/crossroad_06", new BPos(5, 2, 5));
        this.put("village/plains/zombie/streets/straight_01", new BPos(16, 2, 16));
        this.put("village/plains/zombie/streets/straight_02", new BPos(16, 2, 16));
        this.put("village/plains/zombie/streets/straight_03", new BPos(13, 2, 11));
        this.put("village/plains/zombie/streets/straight_04", new BPos(11, 2, 9));
        this.put("village/plains/zombie/streets/straight_05", new BPos(20, 2, 17));
        this.put("village/plains/zombie/streets/straight_06", new BPos(21, 2, 18));
        this.put("village/plains/zombie/streets/turn_01", new BPos(18, 2, 8));
        this.put("village/plains/zombie/town_centers/plains_fountain_01", new BPos(9, 6, 9));
        this.put("village/plains/zombie/town_centers/plains_meeting_point_1", new BPos(10, 7, 10));
        this.put("village/plains/zombie/town_centers/plains_meeting_point_2", new BPos(8, 5, 15));
        this.put("village/plains/zombie/town_centers/plains_meeting_point_3", new BPos(11, 9, 11));
        this.put("village/plains/zombie/villagers/nitwi", new BPos(1, 3, 1));
        this.put("village/plains/zombie/villagers/unemployed", new BPos(1, 3, 1));
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
        this.put("savanna/villagers/nitwi", new BPos(1, 3, 1));
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
        this.put("savanna/zombie/villagers/nitwi", new BPos(1, 3, 1));
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
        this.put("snowy/villagers/nitwi", new BPos(1, 3, 1));
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
        this.put("snowy/zombie/villagers/nitwi", new BPos(1, 3, 1));
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
        this.put("taiga/villagers/nitwi", new BPos(1, 3, 1));
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
        this.put("taiga/zombie/villagers/nitwi", new BPos(1, 3, 1));
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
            if(Biomes.DESERT.equals(biome) || Biomes.DESERT_HILLS.equals(biome)) {
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
            if(!biome.equals(Biomes.PLAINS)) {
                System.err.println("Biome unknown to village gen : " + biome.getName());
            }
            return PLAINS;
        }

        public HashMap<String, List<Pair<Quad<String, String, String, Block>, BPos>>> getJigsawBlocks() {
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
        public String getBlackSmithName(){
            switch(this){
                case DESERT :
                    return "village/desert/houses/desert_weaponsmith_1";

                case PLAINS :
                    return "village/plains/houses/plains_weaponsmith_1";
                default:
                    return "village/desert/houses/desert_weaponsmith_1";
            }
        }
    }

    public static final Map<VillageType, JigSawPool> STARTS = new HashMap<VillageType, JigSawPool>() {{
        put(VillageType.DESERT, new JigSawPool(VILLAGE_POOLS.get("village/desert/town_centers").getSecond()));
        put(VillageType.LEGACY, null);
        put(VillageType.PLAINS, new JigSawPool(PlainPool.VILLAGE_POOLS.get("village/plains/town_centers").getSecond()));
        put(VillageType.TAIGA, null);
        put(VillageType.SAVANNA, null);
        put(VillageType.SNOWY, null);
    }};
}
