package profotoce59.reecriture.VillagePools;

import com.seedfinding.mccore.block.Block;
import com.seedfinding.mccore.block.Blocks;
import com.seedfinding.mccore.util.block.BlockDirection;
import com.seedfinding.mccore.util.data.Pair;
import com.seedfinding.mccore.util.data.Quad;
import com.seedfinding.mccore.util.pos.BPos;
import profotoce59.enumType.PoolType;

import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;

public class DesertVillageJigsawBlocks {
    public static final HashMap<String, List<Pair<Quad<PoolType, String, Pair<BlockDirection,BlockDirection>, Block>, BPos>>> JIGSAW_BLOCKS = new HashMap<>() {{
        this.putAll(CommonVillageJigsawBlocks.JIGSAW_BLOCKS);
        this.put("desert/desert_lamp_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.CUT_SANDSTONE), new BPos(0,0,0))
        ));
        this.put("desert/houses/desert_animal_pen_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.ANIMALS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(2,0,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.SMOOTH_SANDSTONE_STAIRS), new BPos(4,0,0))
        ));
        this.put("desert/houses/desert_animal_pen_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.SMOOTH_SANDSTONE_STAIRS), new BPos(4,0,0)),
                new Pair<>(new Quad<>(PoolType.ANIMALS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(6,0,3))
        ));
        this.put("desert/houses/desert_armorer_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.SMOOTH_SANDSTONE), new BPos(0,1,4))
        ));
        this.put("desert/houses/desert_butcher_shop_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,0,3)),
                new Pair<>(new Quad<>(PoolType.BUTCHER_ANIMAL, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(6,0,6))
        ));
        this.put("desert/houses/desert_cartographer_house_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,0,5)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(5,0,0))
        ));
        this.put("desert/houses/desert_farm_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.CUT_SANDSTONE), new BPos(0,0,3))
        ));
        this.put("desert/houses/desert_farm_2", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.SMOOTH_SANDSTONE_STAIRS), new BPos(0,1,3))
        ));
        this.put("desert/houses/desert_fisher_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(0,0,9)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,6))
        ));
        this.put("desert/houses/desert_fletcher_house_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,4))
        ));
        this.put("desert/houses/desert_large_farm_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,2,6))
        ));
        this.put("desert/houses/desert_library_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(2,0,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.SMOOTH_SANDSTONE), new BPos(3,1,0))
        ));
        this.put("desert/houses/desert_mason_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,4))
        ));
        this.put("desert/houses/desert_medium_house_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(3,0,2)),
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(3,0,4)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.AIR), new BPos(0,1,3))
        ));
        this.put("desert/houses/desert_medium_house_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(4,0,2)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(7,2,2))
        ));
        this.put("desert/houses/desert_shepherd_house_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SHEEPS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(3,0,2)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,4))
        ));
        this.put("desert/houses/desert_small_house_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(3,0,2)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,2))
                /*new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", null, Blocks.SMOOTH_SANDSTONE), new BPos(1,1,3))*/
        ));
        this.put("desert/houses/desert_small_house_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(0,0,3)),
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(1,0,1)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,2))
        ));
        this.put("desert/houses/desert_small_house_3", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(2,0,1)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,5))
        ));
        this.put("desert/houses/desert_small_house_4", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(3,0,2)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.SMOOTH_SANDSTONE), new BPos(3,1,4))
        ));
        this.put("desert/houses/desert_small_house_5", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(3,0,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,0))
        ));
        this.put("desert/houses/desert_small_house_6", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(2,0,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.AIR), new BPos(0,1,2))
        ));
        this.put("desert/houses/desert_small_house_7", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(5,0,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,1))
        ));
        this.put("desert/houses/desert_small_house_8", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(2,0,2)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.SMOOTH_SANDSTONE), new BPos(1,1,0))
        ));
        this.put("desert/houses/desert_tannery_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,2,0))
        ));
        this.put("desert/houses/desert_temple_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,0,5))
        ));
        this.put("desert/houses/desert_temple_2", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,5))
        ));
        this.put("desert/houses/desert_tool_smith_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,3,5))
        ));
        this.put("desert/houses/desert_weaponsmith_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.SMOOTH_SANDSTONE_STAIRS), new BPos(5,0,0))
        ));
        this.put("desert/streets/corner_01", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(2,0,1)),
                /*new Pair<>(new Quad<>(PoolType.CATS, "bottom", null, Blocks.SAND), new BPos(5,0,5)),*/
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,4)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,5)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,0))
        ));
        this.put("desert/streets/corner_02", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(1,0,4)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,1)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,5))
        ));
        this.put("desert/streets/crossroad_01", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(5,0,7)),
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(10,0,12)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,7)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,6)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,8)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,6)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,8)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,14)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,2)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,3)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,7))
        ));
        this.put("desert/streets/crossroad_02", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(1,0,8)),
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(5,0,5)),
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(9,0,1)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,5)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,10)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,5))
        ));
        this.put("desert/streets/crossroad_03", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,2)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,4)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,2))
        ));
        this.put("desert/streets/square_01", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(3,0,13)),
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(10,0,10)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,12)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,10)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,10)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,10)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(6,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,9)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,9)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(9,1,9)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(9,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,9)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(12,1,12))
        ));
        this.put("desert/streets/square_02", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(0,0,10)),
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(4,0,8)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,8)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,5)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,11)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,8))
        ));
        this.put("desert/streets/straight_01", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(1,0,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(13,0,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,2)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,3)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,3)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(12,1,3)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(14,1,2))
        ));
        this.put("desert/streets/straight_02", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(5,0,16)),
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(12,0,17)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,14)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,13)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,13)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(11,1,13)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(14,1,14))
        ));
        this.put("desert/streets/straight_03", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,1)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,1))
        ));
        this.put("desert/streets/turn_01", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(3,0,3)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,2)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,0))
        ));
        this.put("desert/terminators/terminator_01", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,1))
        ));
        this.put("desert/terminators/terminator_02", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(2,0,2)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,1))
        ));
        this.put("desert/town_centers/desert_meeting_point_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.IRON_GOLEM, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(9,0,1)),
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(11,0,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(15,0,1)),
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(15,0,7)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,2)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,3)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,4)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,5)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,6)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(9,1,6)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(12,1,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(12,1,8)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(16,1,4))
        ));
        this.put("desert/town_centers/desert_meeting_point_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(1,0,1)),
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(1,0,8)),
                new Pair<>(new Quad<>(PoolType.IRON_GOLEM, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(1,0,10)),
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(4,0,10)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(10,0,3)),
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(10,0,10)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,5)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,11)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(6,1,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(11,1,6))
        ));
        this.put("desert/town_centers/desert_meeting_point_3", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(1,0,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(2,0,12)),
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(3,0,10)),
                new Pair<>(new Quad<>(PoolType.IRON_GOLEM, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(4,0,11)),
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(6,0,10)),
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(8,0,5)),
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(13,0,11)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,7)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(6,1,4)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(9,1,9)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(12,1,14)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(14,1,8))
        ));
        this.put("desert/villagers/baby", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("desert/villagers/nitwit", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("desert/villagers/unemployed", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("desert/zombie/houses/desert_medium_house_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(3,0,2)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,3))
        ));
        this.put("desert/zombie/houses/desert_medium_house_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(4,0,2)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(7,2,2))
        ));
        this.put("desert/zombie/houses/desert_small_house_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(3,0,2)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,2))
                /*new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", null, Blocks.SMOOTH_SANDSTONE), new BPos(1,1,3))*/
        ));
        this.put("desert/zombie/houses/desert_small_house_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(0,0,3)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(1,0,1)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,2))
        ));
        this.put("desert/zombie/houses/desert_small_house_3", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(2,0,1)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,5))
        ));
        this.put("desert/zombie/houses/desert_small_house_4", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(3,0,2)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.SMOOTH_SANDSTONE), new BPos(3,1,4))
        ));
        this.put("desert/zombie/houses/desert_small_house_5", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(3,0,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,0))
        ));
        this.put("desert/zombie/houses/desert_small_house_6", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(1,0,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.SMOOTH_SANDSTONE), new BPos(0,1,3))
        ));
        this.put("desert/zombie/houses/desert_small_house_7", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(5,0,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,1))
        ));
        this.put("desert/zombie/houses/desert_small_house_8", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(2,0,2)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.SMOOTH_SANDSTONE), new BPos(1,1,0))
        ));
        this.put("desert/zombie/streets/corner_01", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(2,0,1)),
                /*new Pair<>(new Quad<>(PoolType.CATS, "bottom", null, Blocks.SAND), new BPos(5,0,5)),*/
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,4)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,5)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,0))
        ));
        this.put("desert/zombie/streets/corner_02", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(1,0,4)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,1)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,5))
        ));
        this.put("desert/zombie/streets/crossroad_01", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(5,0,7)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(10,0,12)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,7)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,6)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,8)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,6)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,8)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,14)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,2)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,3)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,7))
        ));
        this.put("desert/zombie/streets/crossroad_02", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(1,0,8)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(5,0,5)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(9,0,1)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,5)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,10)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,5))
        ));
        this.put("desert/zombie/streets/crossroad_03", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,2)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,4)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,2))
        ));
        this.put("desert/zombie/streets/square_01", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(3,0,13)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(10,0,10)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,12)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,10)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,10)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,10)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(6,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,9)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,9)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(9,1,9)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(9,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,9)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(12,1,12))
        ));
        this.put("desert/zombie/streets/square_02", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(0,0,10)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(4,0,8)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,8)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,5)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,11)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,8))
        ));
        this.put("desert/zombie/streets/straight_01", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(1,0,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(13,0,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,2)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,3)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,3)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(12,1,3)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(14,1,2))
        ));
        this.put("desert/zombie/streets/straight_02", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(5,0,16)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(12,0,17)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,14)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,13)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,13)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(11,1,13)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(14,1,14))
        ));
        this.put("desert/zombie/streets/straight_03", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,1)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,1))
        ));
        this.put("desert/zombie/streets/turn_01", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(3,0,3)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,2)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,0))
        ));
        this.put("desert/zombie/terminators/terminator_02", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(2,0,2)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,1))
        ));
        this.put("desert/zombie/town_centers/desert_meeting_point_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,2)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,3)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,4)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,5)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,6)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(9,1,6)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(12,1,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(12,1,8)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(16,1,4))
        ));
        this.put("desert/zombie/town_centers/desert_meeting_point_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(1,0,1)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(10,0,3)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,5)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,11)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(6,1,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(11,1,6))
        ));
        this.put("desert/zombie/town_centers/desert_meeting_point_3", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(1,0,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(2,0,12)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(13,0,11)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,7)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(6,1,4)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(9,1,9)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(12,1,14)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(14,1,8))
        ));
        this.put("desert/zombie/villagers/nitwit", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("desert/zombie/villagers/unemployed", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
    }};
    public static final HashMap<String, List<Pair<Quad<PoolType, String, Pair<BlockDirection,BlockDirection>, Block>, BPos>>> JIGSAW_BLOCKS15 = new HashMap<>() {{
        this.putAll(CommonVillageJigsawBlocks.JIGSAW_BLOCKS15);
        this.put("desert/desert_lamp_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.CUT_SANDSTONE), new BPos(0,0,0))
        ));
        this.put("desert/houses/desert_animal_pen_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.SMOOTH_SANDSTONE_STAIRS), new BPos(4,0,0)),
                new Pair<>(new Quad<>(PoolType.ANIMALS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(2,0,3))
        ));
        this.put("desert/houses/desert_animal_pen_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.SMOOTH_SANDSTONE_STAIRS), new BPos(4,0,0)),
                new Pair<>(new Quad<>(PoolType.ANIMALS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(6,0,3))
        ));
        this.put("desert/houses/desert_armorer_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.SMOOTH_SANDSTONE), new BPos(0,1,4))
        ));
        this.put("desert/houses/desert_butcher_shop_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,0,3)),
                new Pair<>(new Quad<>(PoolType.BUTCHER_ANIMAL, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(6,0,6))
        ));
        this.put("desert/houses/desert_cartographer_house_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(5,0,0)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,0,5))
        ));
        this.put("desert/houses/desert_farm_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.CUT_SANDSTONE), new BPos(0,0,3))
        ));
        this.put("desert/houses/desert_farm_2", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.SMOOTH_SANDSTONE_STAIRS), new BPos(0,1,3))
        ));
        this.put("desert/houses/desert_fisher_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(0,0,9)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,6))
        ));
        this.put("desert/houses/desert_fletcher_house_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,4))
        ));
        this.put("desert/houses/desert_large_farm_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,2,6))
        ));
        this.put("desert/houses/desert_library_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(2,0,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.SMOOTH_SANDSTONE), new BPos(3,1,0))
        ));
        this.put("desert/houses/desert_mason_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,4))
        ));
        this.put("desert/houses/desert_medium_house_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(3,0,2)),
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(3,0,4)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.AIR), new BPos(0,1,3))
        ));
        this.put("desert/houses/desert_medium_house_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(4,0,2)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(7,2,2))
        ));
        this.put("desert/houses/desert_shepherd_house_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SHEEPS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(3,0,2)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,4))
        ));
        this.put("desert/houses/desert_small_house_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(3,0,2)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,2))
                /*new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", null, Blocks.SMOOTH_SANDSTONE), new BPos(1,1,3))*/
        ));
        this.put("desert/houses/desert_small_house_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(1,0,1)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(0,0,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,2))
        ));
        this.put("desert/houses/desert_small_house_3", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(2,0,1)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,5))
        ));
        this.put("desert/houses/desert_small_house_4", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(3,0,2)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.SMOOTH_SANDSTONE), new BPos(3,1,4))
        ));
        this.put("desert/houses/desert_small_house_5", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(3,0,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,0))
        ));
        this.put("desert/houses/desert_small_house_6", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(2,0,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.AIR), new BPos(0,1,2))
        ));
        this.put("desert/houses/desert_small_house_7", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(5,0,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,1))
        ));
        this.put("desert/houses/desert_small_house_8", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(2,0,2)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.SMOOTH_SANDSTONE), new BPos(1,1,0))
        ));
        this.put("desert/houses/desert_tannery_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,2,0))
        ));
        this.put("desert/houses/desert_temple_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,0,5))
        ));
        this.put("desert/houses/desert_temple_2", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,5))
        ));
        this.put("desert/houses/desert_tool_smith_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,3,5))
        ));
        this.put("desert/houses/desert_weaponsmith_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.SMOOTH_SANDSTONE_STAIRS), new BPos(5,0,0))
        ));
        this.put("desert/streets/corner_01", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(2,0,1)),
                /*new Pair<>(new Quad<>(PoolType.CATS, "bottom", null, Blocks.SAND), new BPos(5,0,5)),*/
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,4)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,5))
        ));
        this.put("desert/streets/corner_02", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(1,0,4)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,1)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,5))
        ));
        this.put("desert/streets/crossroad_01", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(5,0,7)),
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(10,0,12)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,2)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,3)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,6)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,6)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,7)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,7)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,8)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,8)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,14))
        ));
        this.put("desert/streets/crossroad_02", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(9,0,1)),
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(5,0,5)),
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(1,0,8)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,5)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,5)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,10))
        ));
        this.put("desert/streets/crossroad_03", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,2)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,2)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,4))
        ));
        this.put("desert/streets/square_01", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(10,0,10)),
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(3,0,13)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,9)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,9)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(9,1,9)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,9)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,10)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,10)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,10)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,12)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(12,1,12)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(6,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(9,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,15))
        ));
        this.put("desert/streets/square_02", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(4,0,8)),
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(0,0,10)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,5)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,8)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,8)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,11))
        ));
        this.put("desert/streets/straight_01", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(1,0,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(13,0,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,2)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(14,1,2)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,3)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,3)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(12,1,3))
        ));
        this.put("desert/streets/straight_02", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(5,0,16)),
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(12,0,17)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,13)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,13)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(11,1,13)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,14)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(14,1,14))
        ));
        this.put("desert/streets/straight_03", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,1)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,1))
        ));
        this.put("desert/streets/turn_01", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(3,0,3)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,2))
        ));
        this.put("desert/terminators/terminator_01", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,1))
        ));
        this.put("desert/terminators/terminator_02", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(2,0,2)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,1))
        ));
        this.put("desert/town_centers/desert_meeting_point_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(11,0,0)),
                new Pair<>(new Quad<>(PoolType.IRON_GOLEM, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(9,0,1)),
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(15,0,1)),
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(15,0,7)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(12,1,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,2)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,3)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,4)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(16,1,4)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,5)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,6)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(9,1,6)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(12,1,8))
        ));
        this.put("desert/town_centers/desert_meeting_point_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(1,0,1)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(10,0,3)),
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(1,0,8)),
                new Pair<>(new Quad<>(PoolType.IRON_GOLEM, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(1,0,10)),
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(4,0,10)),
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(10,0,10)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(6,1,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,5)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(11,1,6)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,11))
        ));
        this.put("desert/town_centers/desert_meeting_point_3", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(1,0,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(8,0,5)),
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(3,0,10)),
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(6,0,10)),
                new Pair<>(new Quad<>(PoolType.IRON_GOLEM, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(4,0,11)),
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(13,0,11)),
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(2,0,12)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(6,1,4)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,7)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(14,1,8)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(9,1,9)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(12,1,14))
        ));
        this.put("desert/villagers/baby", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("desert/villagers/nitwit", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("desert/villagers/unemployed", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("desert/zombie/houses/desert_medium_house_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(3,0,2)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,3))
        ));
        this.put("desert/zombie/houses/desert_medium_house_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(4,0,2)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(7,2,2))
        ));
        this.put("desert/zombie/houses/desert_small_house_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(3,0,2)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,2))
                /*new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", null, Blocks.SMOOTH_SANDSTONE), new BPos(1,1,3))*/
        ));
        this.put("desert/zombie/houses/desert_small_house_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(1,0,1)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(0,0,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,2))
        ));
        this.put("desert/zombie/houses/desert_small_house_3", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(2,0,1)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,5))
        ));
        this.put("desert/zombie/houses/desert_small_house_4", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(3,0,2)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.SMOOTH_SANDSTONE), new BPos(3,1,4))
        ));
        this.put("desert/zombie/houses/desert_small_house_5", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(3,0,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,0))
        ));
        this.put("desert/zombie/houses/desert_small_house_6", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(1,0,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.SMOOTH_SANDSTONE), new BPos(0,1,3))
        ));
        this.put("desert/zombie/houses/desert_small_house_7", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(5,0,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,1))
        ));
        this.put("desert/zombie/houses/desert_small_house_8", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(2,0,2)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.SMOOTH_SANDSTONE), new BPos(1,1,0))
        ));
        this.put("desert/zombie/streets/corner_01", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(2,0,1)),
                /*new Pair<>(new Quad<>(PoolType.CATS, "bottom", null, Blocks.SAND), new BPos(5,0,5)),*/
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,4)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,5))
        ));
        this.put("desert/zombie/streets/corner_02", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(1,0,4)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,1)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,5))
        ));
        this.put("desert/zombie/streets/crossroad_01", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(5,0,7)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(10,0,12)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,2)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,3)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,6)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,6)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,7)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,7)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,8)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,8)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,14))
        ));
        this.put("desert/zombie/streets/crossroad_02", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(9,0,1)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(5,0,5)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(1,0,8)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,5)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,5)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,10))
        ));
        this.put("desert/zombie/streets/crossroad_03", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,2)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,2)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,4))
        ));
        this.put("desert/zombie/streets/square_01", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(10,0,10)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(3,0,13)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,9)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,9)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(9,1,9)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,9)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,10)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,10)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,10)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,12)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(12,1,12)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(6,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(9,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,15))
        ));
        this.put("desert/zombie/streets/square_02", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(4,0,8)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(0,0,10)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,5)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,8)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,8)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,11))
        ));
        this.put("desert/zombie/streets/straight_01", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(1,0,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(13,0,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,2)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(14,1,2)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,3)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,3)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(12,1,3))
        ));
        this.put("desert/zombie/streets/straight_02", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(5,0,16)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(12,0,17)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,13)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,13)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(11,1,13)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,14)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(14,1,14))
        ));
        this.put("desert/zombie/streets/straight_03", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,1)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,1))
        ));
        this.put("desert/zombie/streets/turn_01", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(3,0,3)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,2))
        ));
        this.put("desert/zombie/terminators/terminator_02", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(2,0,2)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,1))
        ));
        this.put("desert/zombie/town_centers/desert_meeting_point_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(12,1,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,2)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,3)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,4)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(16,1,4)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,5)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,6)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(9,1,6)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(12,1,8))
        ));
        this.put("desert/zombie/town_centers/desert_meeting_point_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(1,0,1)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(10,0,3)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(6,1,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,5)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(11,1,6)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,11))
        ));
        this.put("desert/zombie/town_centers/desert_meeting_point_3", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(1,0,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(13,0,11)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(2,0,12)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(6,1,4)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,7)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(14,1,8)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(9,1,9)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(12,1,14))
        ));
        this.put("desert/zombie/villagers/nitwit", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("desert/zombie/villagers/unemployed", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
    }};
    public static final HashMap<String, List<Pair<Quad<PoolType, String, Pair<BlockDirection,BlockDirection>, Block>, BPos>>> JIGSAW_BLOCKS17 = new HashMap<>() {{
        this.putAll(CommonVillageJigsawBlocks.JIGSAW_BLOCKS);
        this.put("desert/desert_lamp_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.CUT_SANDSTONE), new BPos(0,0,0))
        ));
        this.put("desert/houses/desert_animal_pen_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.ANIMALS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(2,0,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.SMOOTH_SANDSTONE_STAIRS), new BPos(4,0,0))
        ));
        this.put("desert/houses/desert_animal_pen_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.SMOOTH_SANDSTONE_STAIRS), new BPos(4,0,0)),
                new Pair<>(new Quad<>(PoolType.ANIMALS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(6,0,3))
        ));
        this.put("desert/houses/desert_armorer_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.SMOOTH_SANDSTONE), new BPos(0,1,4))
        ));
        this.put("desert/houses/desert_butcher_shop_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,0,3)),
                new Pair<>(new Quad<>(PoolType.BUTCHER_ANIMAL, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(6,0,6))
        ));
        this.put("desert/houses/desert_cartographer_house_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,0,5)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(5,0,0))
        ));
        this.put("desert/houses/desert_farm_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.CUT_SANDSTONE), new BPos(0,0,3))
        ));
        this.put("desert/houses/desert_farm_2", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.SMOOTH_SANDSTONE_STAIRS), new BPos(0,1,3))
        ));
        this.put("desert/houses/desert_fisher_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(0,0,9)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,6))
        ));
        this.put("desert/houses/desert_fletcher_house_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,4))
        ));
        this.put("desert/houses/desert_large_farm_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,2,6))
        ));
        this.put("desert/houses/desert_library_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(2,0,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.SMOOTH_SANDSTONE), new BPos(3,1,0))
        ));
        this.put("desert/houses/desert_mason_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,4))
        ));
        this.put("desert/houses/desert_medium_house_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(3,0,2)),
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(3,0,4)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.AIR), new BPos(0,1,3))
        ));
        this.put("desert/houses/desert_medium_house_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(4,0,2)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(7,2,2))
        ));
        this.put("desert/houses/desert_shepherd_house_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SHEEPS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(3,0,2)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,4))
        ));
        this.put("desert/houses/desert_small_house_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(3,0,2)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,2))
        ));
        this.put("desert/houses/desert_small_house_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(0,0,3)),
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(1,0,1)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,2))
        ));
        this.put("desert/houses/desert_small_house_3", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(2,0,1)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,5))
        ));
        this.put("desert/houses/desert_small_house_4", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(3,0,2)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.SMOOTH_SANDSTONE), new BPos(3,1,4))
        ));
        this.put("desert/houses/desert_small_house_5", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(3,0,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,0))
        ));
        this.put("desert/houses/desert_small_house_6", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(2,0,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.AIR), new BPos(0,1,2))
        ));
        this.put("desert/houses/desert_small_house_7", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(5,0,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,1))
        ));
        this.put("desert/houses/desert_small_house_8", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(2,0,2)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.SMOOTH_SANDSTONE), new BPos(1,1,0))
        ));
        this.put("desert/houses/desert_tannery_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,2,0))
        ));
        this.put("desert/houses/desert_temple_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,0,5))
        ));
        this.put("desert/houses/desert_temple_2", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,5))
        ));
        this.put("desert/houses/desert_tool_smith_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,3,5))
        ));
        this.put("desert/houses/desert_weaponsmith_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.SMOOTH_SANDSTONE_STAIRS), new BPos(5,0,0))
        ));
        this.put("desert/streets/corner_01", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(2,0,1)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(5,0,5)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,4)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,5)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,0))
        ));
        this.put("desert/streets/corner_02", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(1,0,4)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,1)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,5))
        ));
        this.put("desert/streets/crossroad_01", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(5,0,7)),
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(10,0,12)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,7)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,6)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,8)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,6)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,8)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,14)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,2)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,3)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,7))
        ));
        this.put("desert/streets/crossroad_02", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(1,0,8)),
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(5,0,5)),
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(9,0,1)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,5)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,10)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,5))
        ));
        this.put("desert/streets/crossroad_03", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,2)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,4)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,2))
        ));
        this.put("desert/streets/square_01", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(3,0,13)),
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(10,0,10)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,12)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,10)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,10)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,10)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(6,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,9)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,9)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(9,1,9)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(9,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,9)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(12,1,12))
        ));
        this.put("desert/streets/square_02", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(0,0,10)),
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(4,0,8)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,8)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,5)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,11)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,8))
        ));
        this.put("desert/streets/straight_01", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(1,0,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(13,0,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,2)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,3)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,3)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(12,1,3)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(14,1,2))
        ));
        this.put("desert/streets/straight_02", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(5,0,16)),
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(12,0,17)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,14)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,13)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,13)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(11,1,13)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(14,1,14))
        ));
        this.put("desert/streets/straight_03", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,1)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,1))
        ));
        this.put("desert/streets/turn_01", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(3,0,3)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,2)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,0))
        ));
        this.put("desert/terminators/terminator_01", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,1))
        ));
        this.put("desert/terminators/terminator_02", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(2,0,2)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,1))
        ));
        this.put("desert/town_centers/desert_meeting_point_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.IRON_GOLEM, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(9,0,1)),
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(11,0,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(15,0,1)),
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(15,0,7)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,2)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,3)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,4)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,5)),
                new Pair<>(new Quad<>(PoolType.DESERT_HOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,6)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(9,1,6)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(12,1,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(12,1,8)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(16,1,4))
        ));
        this.put("desert/town_centers/desert_meeting_point_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(1,0,1)),
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(1,0,8)),
                new Pair<>(new Quad<>(PoolType.IRON_GOLEM, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(1,0,10)),
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(4,0,10)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(10,0,3)),
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(10,0,10)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,5)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,11)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(6,1,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(11,1,6))
        ));
        this.put("desert/town_centers/desert_meeting_point_3", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(1,0,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(2,0,12)),
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(3,0,10)),
                new Pair<>(new Quad<>(PoolType.IRON_GOLEM, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(4,0,11)),
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(6,0,10)),
                new Pair<>(new Quad<>(PoolType.DESERT_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(8,0,5)),
                new Pair<>(new Quad<>(PoolType.DESERT_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(13,0,11)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,7)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(6,1,4)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(9,1,9)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(12,1,14)),
                new Pair<>(new Quad<>(PoolType.DESERT_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(14,1,8))
        ));
        this.put("desert/villagers/baby", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("desert/villagers/nitwit", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("desert/villagers/unemployed", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("desert/zombie/houses/desert_medium_house_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(3,0,2)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,3))
        ));
        this.put("desert/zombie/houses/desert_medium_house_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(4,0,2)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(7,2,2))
        ));
        this.put("desert/zombie/houses/desert_small_house_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(3,0,2)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,2))
        ));
        this.put("desert/zombie/houses/desert_small_house_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(0,0,3)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(1,0,1)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,2))
        ));
        this.put("desert/zombie/houses/desert_small_house_3", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(2,0,1)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,5))
        ));
        this.put("desert/zombie/houses/desert_small_house_4", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(3,0,2)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.SMOOTH_SANDSTONE), new BPos(3,1,4))
        ));
        this.put("desert/zombie/houses/desert_small_house_5", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(3,0,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,0))
        ));
        this.put("desert/zombie/houses/desert_small_house_6", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(1,0,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.SMOOTH_SANDSTONE), new BPos(0,1,3))
        ));
        this.put("desert/zombie/houses/desert_small_house_7", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(5,0,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,1))
        ));
        this.put("desert/zombie/houses/desert_small_house_8", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(2,0,2)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.SMOOTH_SANDSTONE), new BPos(1,1,0))
        ));
        this.put("desert/zombie/streets/corner_01", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(2,0,1)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(5,0,5)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,4)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,5)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,0))
        ));
        this.put("desert/zombie/streets/corner_02", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(1,0,4)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,1)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,5))
        ));
        this.put("desert/zombie/streets/crossroad_01", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(5,0,7)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(10,0,12)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,7)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,6)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,8)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,6)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,8)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,14)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,2)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,3)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,7))
        ));
        this.put("desert/zombie/streets/crossroad_02", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(1,0,8)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(5,0,5)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(9,0,1)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,5)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,10)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,5))
        ));
        this.put("desert/zombie/streets/crossroad_03", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,2)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,4)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,2))
        ));
        this.put("desert/zombie/streets/square_01", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(3,0,13)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(10,0,10)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,12)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,10)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,10)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,10)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(6,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,9)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,9)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(9,1,9)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(9,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,9)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,15)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(12,1,12))
        ));
        this.put("desert/zombie/streets/square_02", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(0,0,10)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(4,0,8)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,8)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,5)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,11)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,8))
        ));
        this.put("desert/zombie/streets/straight_01", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(1,0,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(13,0,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,2)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,3)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,3)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(12,1,3)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(14,1,2))
        ));
        this.put("desert/zombie/streets/straight_02", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(5,0,16)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(12,0,17)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,14)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,13)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,13)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(11,1,13)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(14,1,14))
        ));
        this.put("desert/zombie/streets/straight_03", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,1)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,1))
        ));
        this.put("desert/zombie/streets/turn_01", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(3,0,3)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,2)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,0))
        ));
        this.put("desert/zombie/terminators/terminator_02", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(2,0,2)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,1))
        ));
        this.put("desert/zombie/town_centers/desert_meeting_point_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,2)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,3)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,4)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,5)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,6)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(9,1,6)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(12,1,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(12,1,8)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(16,1,4))
        ));
        this.put("desert/zombie/town_centers/desert_meeting_point_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(1,0,1)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SMOOTH_SANDSTONE), new BPos(10,0,3)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,5)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,11)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(6,1,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(11,1,6))
        ));
        this.put("desert/zombie/town_centers/desert_meeting_point_3", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(1,0,0)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(2,0,12)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.SAND), new BPos(13,0,11)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,7)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(6,1,4)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(9,1,9)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(12,1,14)),
                new Pair<>(new Quad<>(PoolType.DESERT_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(14,1,8))
        ));
        this.put("desert/zombie/villagers/nitwit", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("desert/zombie/villagers/unemployed", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("patch_cactus", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH) ,Blocks.STRUCTURE_VOID),new BPos(0,0,0))
        ));
    }};
}