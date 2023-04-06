package profotoce59.properties;
//1971160871
import com.seedfinding.mcbiome.biome.Biome;
import com.seedfinding.mccore.block.Block;
import com.seedfinding.mccore.block.Blocks;
import com.seedfinding.mccore.rand.ChunkRand;
import com.seedfinding.mccore.util.block.BlockBox;
import com.seedfinding.mccore.util.block.BlockDirection;
import com.seedfinding.mccore.util.block.BlockMirror;
import com.seedfinding.mccore.util.block.BlockRotation;
import com.seedfinding.mccore.util.data.Pair;
import com.seedfinding.mccore.util.data.Quad;
import com.seedfinding.mccore.util.data.Triplet;
import com.seedfinding.mccore.util.pos.BPos;
import com.seedfinding.mccore.util.pos.CPos;
import com.seedfinding.mccore.version.MCVersion;
import com.seedfinding.mcfeature.loot.LootContext;
import com.seedfinding.mcfeature.loot.LootTable;
import com.seedfinding.mcfeature.loot.MCLootTables;
import com.seedfinding.mcfeature.loot.item.ItemStack;
import com.seedfinding.mcfeature.structure.RegionStructure;
import com.seedfinding.mcfeature.structure.Village;
import com.seedfinding.mcfeature.structure.generator.Generator;
import com.seedfinding.mcnoise.simplex.SimplexNoiseSampler;
import com.seedfinding.mcseed.rand.JRand;
import com.seedfinding.mcterrain.TerrainGenerator;
import com.seedfinding.mcterrain.terrain.OverworldTerrainGenerator;
import com.seedfinding.mcterrain.utils.NoiseSettings;
import profotoce59.enumType.PoolType;
import profotoce59.enumType.VillageType;
import profotoce59.reecriture.*;
import profotoce59.reecriture.VillagePools.*;

import java.util.*;
import profotoce59.utils.Utils;

public class VillageGenerator extends Generator {
    public List<Piece> pieces;
    private VillageType villageType;
    private boolean useHeightMapOptimizer = true;
    private boolean generated = false;
    private boolean superflat = false;
    public VillageGenerator(MCVersion version) {
        super(version);
    }

    public VillageGenerator(MCVersion version, boolean superflat){
        super(version);
        this.superflat = superflat;
    }
    public boolean generate(TerrainGenerator generator, int chunkX, int chunkZ, ChunkRand rand, Biome biomeWanted, boolean useHeightMapOptimizer) {
        this.useHeightMapOptimizer = useHeightMapOptimizer;
        Biome biome = generator.getBiomeSource().getBiomeForNoiseGen((chunkX << 2) + 2, 0, (chunkZ << 2) + 2);
        if(!biomeWanted.equals(biome))return false;
        else return this.generate(generator,chunkX,chunkZ,rand);
    }
    public boolean generate(TerrainGenerator generator, int chunkX, int chunkZ, ChunkRand rand,boolean useHeightMapOptimizer) {
        this.useHeightMapOptimizer = useHeightMapOptimizer;
        return this.generate(generator,chunkX,chunkZ,rand);
    }
    public boolean generate(TerrainGenerator generator, int chunkX, int chunkZ, ChunkRand rand, Biome biomeWanted) {
        Biome biome = generator.getBiomeSource().getBiomeForNoiseGen((chunkX << 2) + 2, 0, (chunkZ << 2) + 2);
        if(!biomeWanted.equals(biome))return false;
        else return this.generate(generator,chunkX,chunkZ,rand);
    }
    @Override
    public boolean generate(TerrainGenerator generator, int chunkX, int chunkZ, ChunkRand rand) {
        Biome biome = generator.getBiomeSource().getBiomeForNoiseGen((chunkX << 2) + 2, 0, (chunkZ << 2) + 2);
        this.villageType = VillageType.getType(biome, generator.getVersion(), this.superflat);
        if(this.villageType == null)return false;

        pieces = new ArrayList<>();
        rand = rand.asChunkRandDebugger();
        Village village = new Village(this.getVersion());
        if(!village.canStart((RegionStructure.Data<Village>)village.at(chunkX, chunkZ),generator.getWorldSeed(),rand)){
            return false;
        }

        if(!superflat && !village.canSpawn(chunkX, chunkZ, generator.getBiomeSource())){
            return false;
        }

        if(!superflat && !village.canGenerate(chunkX, chunkZ, generator)){
            return false;
        }

        rand.setCarverSeed(generator.getWorldSeed(), chunkX, chunkZ, generator.getVersion());
        BlockRotation rotation = BlockRotation.getRandom(rand);

        // compute the template

        JigSawPool jigSawPool = STARTS.get(villageType);
        String template = rand.getRandom(jigSawPool.getTemplates());
        //if(!template.equals("desert/town_centers/desert_meeting_point_2"))return false;  //to get the max number of street
        BPos size = VillageStructureSize.STRUCTURE_SIZE.get(template);
        BPos bPos = new CPos(chunkX, chunkZ).toBlockPos(0);
        BlockBox box = BlockBox.getBoundingBox(bPos, rotation, BPos.ORIGIN, BlockMirror.NONE, size);
        int centerX = (box.minX + box.maxX) / 2;
        int centerZ = (box.minZ + box.maxZ) / 2;
        int heightY = generator.getFirstHeightInColumn(centerX,centerZ,TerrainGenerator.WORLD_SURFACE_WG);
        int y = bPos.getY() + heightY;
        int centerY = box.minY + 1;

        // create the first piece (always rigid)
        Piece piece = new Piece(template, bPos, box, rotation, PlacementBehaviour.RIGID,0);
        piece.move(0, y - centerY, 0);
        piece.setBoundsTop(y + 80);
        BlockBox fullBox = new BlockBox(centerX - 80, y - 80, centerZ - 80, centerX + 80 + 1, y + 80 + 1, centerZ + 80 + 1);
        Assembler assembler = new Assembler(6, generator,this.pieces,useHeightMapOptimizer,heightY);
        assembler.pieces.add(piece);
        VoxelShape a = new VoxelShape(fullBox);
        a.fullBoxes.add(new BlockBox(box.minX,box.minY,box.minZ,box.maxX+1,box.maxY+1,box.maxZ+1));
        piece.voxelShape = a;
        assembler.placing.addLast(piece);
        while(!assembler.placing.isEmpty()) {
            assembler.tryPlacing(villageType, assembler.placing.removeFirst(), rand, true);
        }
        generated = true;
        return true;
    }

    public List<Pair<BPos, List<ItemStack>>> generateLoot(OverworldTerrainGenerator generator, ChunkRand rand){
        if(!generated){
            throw new IllegalArgumentException("No village generated yet, please call generate and make sure the call returns true");
        }
        List<Piece> generationPieces = new ArrayList<>(pieces);

        BlockBox maxbox = generationPieces.stream().map(x -> x.box).reduce((piece1, piece2) -> new BlockBox(Math.min(piece1.minX, piece2.minX), Math.min(piece1.minY, piece2.minY), Math.min(piece1.minZ, piece2.minZ),
             Math.max(piece1.maxX, piece2.maxX), Math.max(piece1.maxY, piece2.maxY), Math.max(piece1.maxZ, piece2.maxZ))).get();

        for (int x = maxbox.minX>>4; x <= maxbox.maxX>>4; x++) {
            for (int z = maxbox.minZ>>4; z <= maxbox.maxZ>>4; z++) {
                generateChunkLoot(generationPieces, generator, x, z, rand);
            }
        }

        return pieces.stream()
            .filter(x -> !x.loot.isEmpty())
            .map(x -> {
                BPos offset = VillageStructureLoot.STRUCTURE_LOOT_OFFSETS.get(x.name).get(0);
                BPos chestPos = x.pos.add(x.getTransformedPos(offset, x.rotation));
                return new Pair<BPos, List<ItemStack>>(chestPos, x.loot);
            })
            .toList();
    }

    private void generateChunkLoot(List<Piece> generationPieces, OverworldTerrainGenerator generator, int chunkX, int chunkZ, ChunkRand rand){
        BlockBox chunkBox = new BlockBox(chunkX*16, chunkZ*16, chunkX*16 + 15, chunkZ*16 + 15);
        long populationSeed = rand.setPopulationSeed(generator.getWorldSeed(), chunkX*16, chunkZ*16, generator.getVersion());

        boolean confident = true;

        // Numbers taken from 1.16.5 and 1.15
        if(generator.getVersion().isOlderThan(MCVersion.v1_16)){
            rand.setDecoratorSeed(populationSeed, 9, 3, generator.getVersion());
        } else {
            rand.setDecoratorSeed(populationSeed, 11, 4, generator.getVersion());
        }
        Iterator<Piece> iterator = generationPieces.iterator();
        while(iterator.hasNext()) {
            Piece piece = iterator.next();
            if(piece.type==PieceType.Feature){
                confident = false;
            }
            if (piece.box.intersects(chunkBox)){
                if(!piece.place(rand, generator, confident, chunkBox)){
                    iterator.remove();
                }
            }
        }
    }

    @Override
    public List<Pair<ILootType, BPos>> getChestsPos() {
        return null;
    }

    @Override
    public List<Pair<ILootType, BPos>> getLootPos() {
        return null;
    }

    public void printPieces() {
        for (Piece piece :pieces){
            System.out.println(piece.name + " "+piece.pos.toString()+" "+piece.rotation);
        }
    }
    public List<Piece> getPieces() {
        return this.pieces;
    }


    static public class Piece {
        public static List<String> featureList = Arrays.asList("pile_hay", "pile_melon", "snowy/pile_snow", "snowy/pile_ice", "taiga/pile_pumpkin", "taiga/patch_berry_bush", "taiga/patch_taiga_grass", "patch_cactus", "flower_plain", "oak", "savanna/acacia", "taiga/spruce", "taiga/pine");
        String name;
        public BPos pos;
        BlockBox box;
        public BlockRotation rotation;
        int boundsTop;
        PlacementBehaviour placementBehaviour;
        private VoxelShape voxelShape;
        int depth;
        PieceType type;
        List<ItemStack> loot = new ArrayList<>();
        public String getName(){
            return this.name;
        }
        //add a second constructor in order to avoid to use the method contains while we are not sure the piece will spawn (line 532)
        Piece(String name, BPos pos, BlockBox box, BlockRotation rotation, PlacementBehaviour placementBehaviour,int depth) {
            this.name = name;
            this.pos = pos;
            this.box = box;
            this.rotation = rotation;
            this.placementBehaviour = placementBehaviour;
            this.voxelShape = new VoxelShape(box);
            this.depth = depth;
            if(featureList.contains(name)){
                type = PieceType.Feature;
            } else if(name.equals("empty")){
                type = PieceType.Empty;
            } else {
                type = PieceType.LegacySingle;
            }
        }

        public void move(int x, int y, int z) {
            box.move(x, y, z);
            pos = pos.add(x, y, z);
        }

        public void setBoundsTop(int boundsTop) {
            this.boundsTop = boundsTop;
        }

        public List<BlockJigsawInfo> getShuffledJigsawBlocks(VillageType villageType, BPos offset, JRand rand, MCVersion version) {//taking 20% need to opti
            List<Pair<Quad<PoolType, String, Pair<BlockDirection,BlockDirection>, Block>, BPos>> blocks = villageType.getJigsawBlocks(version)
                    .get(this.name);
            List<BlockJigsawInfo> list = new ArrayList<>(blocks.size());
            for (Pair<Quad<PoolType, String, Pair<BlockDirection, BlockDirection>, Block>, BPos> b : blocks) {


                BlockJigsawInfo blockJigsawInfo = new BlockJigsawInfo(b.getFirst()
                        , rotation.rotate(b.getSecond(),new BPos(0,0,0)).add(offset),rotation );//erreur quand c'est up
                list.add(blockJigsawInfo);
            }
            rand.shuffle(list);
            return list;
        }

        public boolean place(ChunkRand rand, OverworldTerrainGenerator otg, boolean confident, BlockBox boundingBox){
            return switch(type){
                case Empty -> true;
                case Feature -> switch (name){
                    case "pile_hay" -> processPile(rand, otg, false);
                    case "pile_melon" -> processPile(rand,otg, false);
                    case "snowy/pile_snow" -> processPile(rand, otg, true);
                    case "snowy/pile_ice" -> processPile(rand, otg, true);
                    case "patch_cactus" -> processPatch(rand);
                    case "taiga/patch_taiga_grass" -> processPatch(rand);
                    case "taiga/patch_berry_bush" -> processPatch(rand);
                    case "flower_plain" -> processFlowerPlain(rand);
                    case "oak" -> processOak(rand, otg);
                    case "savanna/acacia" -> processAcacia(rand, otg);
                    case "taiga/spruce" -> processSpruce(rand, otg);
                    case "taiga/pine" -> processPine(rand, otg);
                    case "taiga/pile_pumpkin" -> processPile(rand, otg, true);
                    default -> throw new IllegalArgumentException("Unknown feature in village: " + name);
                };
                case LegacySingle -> {
                    List<LootTable> tables = VillageStructureLoot.STRUCTURE_LOOT.get(name);
                    if(tables==null){
                        throw new IllegalArgumentException("Unknown legacy single piece: " + name);
                    }
                    if(tables.isEmpty()){
                        yield true;
                    }
                    for (int i = 0; i < tables.size(); i++) {
                        BPos offset = VillageStructureLoot.STRUCTURE_LOOT_OFFSETS.get(name).get(i);
                        if(boundingBox.contains(pos.add(getTransformedPos(offset, rotation)))) {
                            long lootTableSeed = rand.nextLong();
                            //If we have generated a feature this chunk, don't add the loot. We're not confident enough.
                            if (confident) {
                                //Generate the loot only if we're not talking about barrels
                                if(tables.get(i)!= MCLootTables.NULL) {
                                    tables.get(i).apply(otg.getVersion());
                                    loot.addAll(tables.get(i)
                                        .generate(
                                            new LootContext(lootTableSeed, otg.getVersion())));
                                }
                            }
                        }
                    }
                    yield true;
                }
                default -> throw new IllegalArgumentException("Unknown piece type: " + type);
            };
        }

        public static BPos getTransformedPos(BPos targetPos, BlockRotation rotationIn) {
            int i = targetPos.getX();
            int j = targetPos.getY();
            int k = targetPos.getZ();
            switch(rotationIn) {
                case COUNTERCLOCKWISE_90:
                    return new BPos(k,j, -i);
                case CLOCKWISE_90:
                    return new BPos(-k,j, +i);
                case CLOCKWISE_180:
                    return new BPos(-i, j, -k);
                default:
                    return targetPos;
            }
        }

        public boolean processPile(ChunkRand rand, OverworldTerrainGenerator otg, boolean snow){
            int i = 2 + rand.nextInt(2);
            int j = 2 + rand.nextInt(2);

            for(BPos blockpos : Utils.getAllInBoxMutable(pos.add(-i, 0, -j), pos.add(i, 1, j))) {
                int k = pos.getX() - blockpos.getX();
                int l = pos.getZ() - blockpos.getZ();
                if ((float)(k * k + l * l) <= rand.nextFloat() * 10.0F - rand.nextFloat() * 6.0F) {
                    // Here we start gambling, this might turn the random wrong since we need exact world blocks to generate this and we simply don't have those.
                    if (blockpos.getY() > otg.getHeightOnGround(blockpos.getX(), blockpos.getZ())) {
                        if(!snow){
                            // Account for hay bale rotation
                            rand.nextInt(3);
                        }
                    }
                } else if ((double)rand.nextFloat() < 0.031D) {
                    // Here we start gambling, this might turn the random wrong since we need exact world blocks to generate this and we simply don't have those.
                    if (blockpos.getY() > otg.getHeightOnGround(blockpos.getX(), blockpos.getZ())) {
                        if(!snow){
                            // Account for hay bale rotation
                            rand.nextInt(3);
                        }
                    }
                }
            }
            return true;
        }

        public boolean processPatch(ChunkRand rand){
            for(int j = 0; j < 10; ++j) {
                rand.nextInt(7 + 1);
                rand.nextInt(7 + 1);
                rand.nextInt(3 + 1);
                rand.nextInt(3 + 1);
                rand.nextInt(7 + 1);
                rand.nextInt(7 + 1);
                rand.nextInt(rand.nextInt(2 + 1) + 1);
            }
            return true;
        }

        public boolean processFlowerPlain(ChunkRand rand){
            int blockstate;
            SimplexNoiseSampler sampler = new SimplexNoiseSampler(new ChunkRand(2345L));
            double d0 = sampler.sample2D((double)pos.getX() / 200.0D , (double)pos.getZ() / 200.0D);
            if (d0 < -0.8D) {
                blockstate =  rand.nextInt(4);
            } else {
                blockstate = rand.nextInt(3) > 0 ? rand.nextInt(4) : 0;
            }

            for(int j = 0; j < 64; ++j) {
                rand.nextInt(7 + 1);
                rand.nextInt(7 + 1);
                rand.nextInt(3 + 1);
                rand.nextInt(3 + 1);
                rand.nextInt(7 + 1);
                rand.nextInt(7 + 1);
            }

            return true;
        }

        public boolean processOak(ChunkRand rand, OverworldTerrainGenerator otg){
            int i = 4 + rand.nextInt(2 + 1) + rand.nextInt(0 + 1);
            return false;
        }
        private boolean processPine(ChunkRand rand, OverworldTerrainGenerator otg) {
            int i = 6 + rand.nextInt(4 + 1) + rand.nextInt(0 + 1);
            int j = 3 + rand.nextInt(1 + 1);
            return false;
        }

        private boolean processSpruce(ChunkRand rand, OverworldTerrainGenerator otg) {
            int i = 5 + rand.nextInt(2 + 1) + rand.nextInt(1 + 1);
            int j = Math.max(4, i - 1 + rand.nextInt(1 + 1));
            int l = 2 + rand.nextInt(1 + 1);
            return false;
        }

        private boolean processAcacia(ChunkRand rand, OverworldTerrainGenerator otg) {
            int i = 5 + rand.nextInt(2 + 1) + rand.nextInt(2 + 1);
            return false;
        }

        public void setVoxelShape(VoxelShape mutableobject1) {
            this.voxelShape = mutableobject1;
        }
        public VoxelShape getVoxelShape() {
            return this.voxelShape;
        }
    }

    public static class BlockJigsawInfo {
        Quad<PoolType, String, Pair<BlockDirection,BlockDirection>, Block> nbt;
        BPos pos;
        BlockRotation rotation;
        public BlockJigsawInfo(Quad<PoolType, String, Pair<BlockDirection,BlockDirection>, Block> nbt, BPos pos, BlockRotation rotation) {
            // nbt is stored as pool,name,orientation,final_state
            this.nbt = nbt;
            this.pos = pos;
            this.rotation = rotation;

        }

        public BlockDirection getFront() {
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
        public boolean canAttach15(BlockJigsawInfo blockJigsawInfo2,BlockDirection direction) { //1.15 version is faster and seems the same

            return direction == this.getOpposite(blockJigsawInfo2.getFront())
                    && this.nbt.getSecond().equals(blockJigsawInfo2.nbt.getSecond());

        }
    }

    public static class Assembler {
        int maxDepth;
        TerrainGenerator generator;
        List<Piece> pieces;
        SurfaceGenerator2 sGen;
        boolean useHeightMapOptimizer;

        private final Deque<Piece> placing = new ArrayDeque<>();
        Assembler(int maxDepth, TerrainGenerator generator, List<Piece> pieces, boolean useHeightMapOptimizer, int heightY) {
            this.maxDepth = maxDepth;
            this.generator = generator;
            this.pieces = pieces;
            this.useHeightMapOptimizer = useHeightMapOptimizer;
            this.sGen = new SurfaceGenerator2(generator.getBiomeSource(), 256, 1, 2,
                    NoiseSettings.create(0.9999999814507745, 0.9999999814507745, 80.0, 160.0)
                            .addTopSlide(-10, 3, 0)
                            .addBottomSlide(-30, 0, 0),
                    1.0D, -0.46875D, true,heightY+25);//13*8
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

            for (BlockJigsawInfo blockJigsawInfo : piece.getShuffledJigsawBlocks(villageType, pos, rand,generator.getVersion())) {
                BlockDirection blockDirection = blockJigsawInfo.getFront();
                BPos blockPos = blockJigsawInfo.pos;
                BPos relativeBlockPos = new BPos(blockPos.getX() + blockDirection.getVector().getX(),
                        blockPos.getY() + blockDirection.getVector().getY(),
                        blockPos.getZ() + blockDirection.getVector().getZ());
                int y = blockPos.getY() - minY;
                int state = -1;
                Triplet<PoolType, List<Pair<String, Integer>>, PlacementBehaviour> pool = villageType.getPool(generator.getVersion()).get(blockJigsawInfo.nbt.getFirst());
                if (pool != null && pool.getSecond().size() != 0) {
                    PoolType fallbackLocation = pool.getFirst();
                    Triplet<PoolType, List<Pair<String, Integer>>, PlacementBehaviour> fallbackPool = villageType.getPool(generator.getVersion()).get(fallbackLocation);
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

                                // Next block is setup to get the List<BlockJigsawInfo> (getJigsawBlocks in code)
                                BPos size1 = VillageStructureSize.STRUCTURE_SIZE.get(jigsawpiece1);
                                BlockBox box1;
                                // This means we got a villager.
                                if(size1 == null){
                                    box1 = new BlockBox(0,0,0,0,0,0);
                                }
                                else {
                                    box1 = BlockBox.getBoundingBox(BPos.ORIGIN, rotation1, BPos.ORIGIN, BlockMirror.NONE, size1);
                                }
                                Piece piece1 = new Piece(jigsawpiece1, BPos.ORIGIN, box1, rotation1, pool.getThird(),0);
                                List<BlockJigsawInfo> list1 = piece1.getShuffledJigsawBlocks(villageType, BPos.ORIGIN, rand,generator.getVersion());

                                int i1;
                                if (expansionHack && box1.getYSpan() <= 16) {
                                    i1 = maxHeightOfList(list1,box1);
                                } else {
                                    i1 = 0;
                                }

                                BlockDirection direction = blockJigsawInfo.getFront();

                                // Loop to see if we can attach, written as hasJigsawMatch in code.
                                for (BlockJigsawInfo blockJigsawInfo2 : list1) {//55k passages
                                    if (blockJigsawInfo.canAttach15(blockJigsawInfo2,direction)) {
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
                                                if(this.useHeightMapOptimizer){
                                                    state = this.sGen.generateColumnfromY(blockPos.getX(), blockPos.getZ(),(block) -> block != Blocks.AIR);
                                                }
                                                else{
                                                    state = this.generator.getFirstHeightInColumn(blockPos.getX(), blockPos.getZ(),(block) -> block != Blocks.AIR);
                                                }


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
        private int maxHeightOfList(List<BlockJigsawInfo> list,BlockBox box){
            int max = 0;
            for (BlockJigsawInfo blockJigsaw :list) {

                BlockDirection dirtmp = blockJigsaw.getFront();
                BPos relativetmp = new BPos(blockJigsaw.pos.getX() + dirtmp.getVector().getX(),
                        blockJigsaw.pos.getY() + dirtmp.getVector().getY(),
                        blockJigsaw.pos.getZ() + dirtmp.getVector().getZ());
                if (!box.contains(relativetmp)) {
                    continue;
                } else {//36k passages optimized
                    //still 4% enumMap ?
                    max = Math.max(VillagePoolYMax.Y_MAX.get(blockJigsaw.nbt.getFirst()), max);

                }
            }

            return max;
        }
        private boolean isNotEmpty(VoxelShape voxelShape,BlockBox box1) {
            if(box1.minX<voxelShape.getX().get(0) || box1.minY<voxelShape.getY().get(0) || box1.minZ<voxelShape.getZ().get(0)
                    || box1.maxX>=voxelShape.getLastX() || box1.maxY>=voxelShape.getLastY() || box1.maxZ>=voxelShape.getLastZ()
            )return false;
            for (BlockBox fullBox: voxelShape.fullBoxes){
                if(intersects2(box1,fullBox)){
                    return false;
                }
            }
            return true;

        }
        public boolean intersects2(BlockBox box1,BlockBox box) {
            return box1.maxX >= box.minX && box1.minX < box.maxX && box1.maxZ >= box.minZ && box1.minZ < box.maxZ && box1.maxY >= box.minY && box1.minY < box.maxY;
        }
    }

    public List<CPos> getChestsPosition() {
        List<CPos> chestPos = new ArrayList<>();
        for (Piece piece : this.pieces) {
            if (piece.name.equals(villageType.getBlackSmithName())) {
                chestPos.add(villageType.getChestChunk(piece));
            }
        }
        return chestPos;
    }

    @Override
    public ILootType[] getLootTypes() {
        return new ILootType[0];
    }

    public int getNumberOfBlackSmith(){
        int nb = 0;
        for (Piece piece : this.pieces){
            if(piece.name.equals(villageType.getBlackSmithName())) {
                nb++;
            }
        }
        return nb;
    }
    public int getNumberOfHouses(){
        int nb = 0;
        for (Piece piece : this.pieces) {
            if (piece.name.length() > 21) {
                String pieceName = piece.name.substring(0,20);
                if (pieceName.contains("houses")) nb++;
            }
        }
        return nb;
    }
    public int getNumberOfCat(){
        int nb = 0;
        for (Piece piece : this.pieces) {
            if (piece.name.length() > 21) {
                String pieceName = piece.name.substring(10,piece.name.length());
                if (pieceName.contains("cat")) nb++;

            }
        }
        //tp 61 63 55

        return nb;
    }
    public int getWrongVillage(){
        int nb = 0;
        for (Piece piece : this.pieces) {
            if (piece.name.length() > 21) {
                String pieceName = piece.name.substring(0,20);
                if (pieceName.contains("houses") && !pieceName.contains("small_farm") ) {
                    //
                    if (pieceName.contains("plain")){
                        nb++;
                    }

                }
            }
        }
        //tp 61 63 55

        return nb;
    }

    public enum PlacementBehaviour {
        RIGID,
        TERRAIN_MATCHING,
    }
    //put that in another Folder


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

    static enum PieceType{
        Empty,
        Feature,
        List,
        Single,
        LegacySingle
    }



    public static final Map<VillageType, JigSawPool> STARTS = new HashMap<>() {{
        put(VillageType.DESERT, new JigSawPool(DesertPool.VILLAGE_POOLS.get(PoolType.DESERT_CENTER).getSecond()));
        put(VillageType.LEGACY, null);
        put(VillageType.PLAINS, new JigSawPool(PlainPool.VILLAGE_POOLS.get(PoolType.PLAIN_CENTER).getSecond()));
        put(VillageType.TAIGA, new JigSawPool(TaigaPool.VILLAGE_POOLS.get(PoolType.TAIGA_CENTER).getSecond()));
        put(VillageType.SAVANNA, new JigSawPool(SavannaPool.VILLAGE_POOLS.get(PoolType.SAVANNA_CENTER).getSecond()));
        put(VillageType.SNOWY, new JigSawPool(SnowyPool.VILLAGE_POOLS.get(PoolType.SNOWY_CENTER).getSecond()));
    }};
}
