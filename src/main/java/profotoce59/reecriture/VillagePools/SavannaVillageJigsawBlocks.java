package profotoce59.reecriture.VillagePools;

import profotoce59.enumType.PoolType;
import com.seedfinding.mccore.block.Block;
import com.seedfinding.mccore.block.Blocks;
import com.seedfinding.mccore.util.block.BlockDirection;
import com.seedfinding.mccore.util.data.Pair;
import com.seedfinding.mccore.util.data.Quad;
import com.seedfinding.mccore.util.pos.BPos;

import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;

public class SavannaVillageJigsawBlocks {
    public static final HashMap<String, List<Pair<Quad<PoolType, String, Pair<BlockDirection,BlockDirection>, Block>, BPos>>> JIGSAW_BLOCKS = new HashMap<>() {{
        this.putAll(CommonVillageJigsawBlocks.JIGSAW_BLOCKS);
        this.put("savanna/savanna_lamp_post_01", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.ACACIA_FENCE), new BPos(0,0,0))
        ));
        this.put("savanna/houses/savanna_animal_pen_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.ANIMALS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(3,0,2)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.ACACIA_STAIRS), new BPos(4,0,0))
        ));
        this.put("savanna/houses/savanna_animal_pen_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(0,1,2)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(1,1,10)),
                new Pair<>(new Quad<>(PoolType.ANIMALS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(4,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(7,1,6)),
                new Pair<>(new Quad<>(PoolType.ANIMALS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(8,1,8)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.ACACIA_FENCE_GATE), new BPos(4,2,0))
        ));
        this.put("savanna/houses/savanna_animal_pen_3", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(2,0,6)),
                new Pair<>(new Quad<>(PoolType.ANIMALS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(4,0,5)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.ACACIA_FENCE), new BPos(4,1,8))
        ));
        this.put("savanna/houses/savanna_armorer_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,3))
        ));
        this.put("savanna/houses/savanna_butchers_shop_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,0,6)),
                new Pair<>(new Quad<>(PoolType.BUTCHER_ANIMAL, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.DIRT), new BPos(8,0,5))
        ));
        this.put("savanna/houses/savanna_butchers_shop_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.BUTCHER_ANIMAL, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(10,0,2)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.ACACIA_STAIRS), new BPos(0,1,4))
        ));
        this.put("savanna/houses/savanna_cartographer_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.ACACIA_STAIRS), new BPos(0,0,4)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(4,0,4))
        ));
        this.put("savanna/houses/savanna_fisher_cottage_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(0,1,7)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(4,1,3)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(6,1,8)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.ACACIA_STAIRS), new BPos(3,2,0))
        ));
        this.put("savanna/houses/savanna_fletcher_house_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,8))
        ));
        this.put("savanna/houses/savanna_large_farm_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.ACACIA_LOG), new BPos(3,1,8))
        ));
        this.put("savanna/houses/savanna_large_farm_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(6,1,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,2,0))
        ));
        this.put("savanna/houses/savanna_library_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.ACACIA_STAIRS), new BPos(5,1,0))
        ));
        this.put("savanna/houses/savanna_mason_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,5))
        ));
        this.put("savanna/houses/savanna_medium_house_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(0,0,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.ACACIA_PLANKS), new BPos(3,0,3)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.ACACIA_PLANKS), new BPos(3,0,11)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,7))
        ));
        this.put("savanna/houses/savanna_medium_house_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.ACACIA_PLANKS), new BPos(3,0,3)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(7,0,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.ACACIA_PLANKS), new BPos(7,0,8)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,5))
        ));
        this.put("savanna/houses/savanna_shepherd_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SHEEPS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(7,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_TREE, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.DIRT), new BPos(10,1,8)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.AIR), new BPos(0,2,5))
        ));
        this.put("savanna/houses/savanna_small_farm", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,2,0))
        ));
        this.put("savanna/houses/savanna_small_house_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(2,0,6)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,6))
        ));
        this.put("savanna/houses/savanna_small_house_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(2,0,6)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,6))
        ));
        this.put("savanna/houses/savanna_small_house_3", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(5,0,6)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,6))
        ));
        this.put("savanna/houses/savanna_small_house_4", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.ACACIA_PLANKS), new BPos(5,0,2)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,6))
        ));
        this.put("savanna/houses/savanna_small_house_5", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.ACACIA_PLANKS), new BPos(4,0,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(6,1,3))
        ));
        this.put("savanna/houses/savanna_small_house_6", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.ACACIA_PLANKS), new BPos(3,0,3)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(6,0,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,3))
        ));
        this.put("savanna/houses/savanna_small_house_7", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(5,0,6)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,6))
        ));
        this.put("savanna/houses/savanna_small_house_8", Arrays.asList(
                //new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", null, Blocks.GRASS_BLOCK), new BPos(0,0,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.ACACIA_LOG), new BPos(3,0,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,3))
        ));
        this.put("savanna/houses/savanna_tannery_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(6,1,4))
        ));
        this.put("savanna/houses/savanna_temple_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,4))
        ));
        this.put("savanna/houses/savanna_temple_2", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,4))
        ));
        this.put("savanna/houses/savanna_tool_smith_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,4))
        ));
        this.put("savanna/houses/savanna_weaponsmith_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,4))
        ));
        this.put("savanna/houses/savanna_weaponsmith_2", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.SMOOTH_STONE_SLAB), new BPos(0,1,6))
        ));
        this.put("savanna/streets/corner_01", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(3,0,4)),
                //new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", null, Blocks.GRASS_BLOCK), new BPos(3,0,13)),
                //new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", null, Blocks.GRASS_BLOCK), new BPos(8,0,12)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(10,0,3)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(13,0,9)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,6))
        ));
        this.put("savanna/streets/corner_03", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,3)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,1))
        ));
        this.put("savanna/streets/crossroad_02", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(1,0,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(3,0,6)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,5)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,9)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(6,1,5))
        ));
        this.put("savanna/streets/crossroad_03", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(2,0,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(3,0,13)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(8,0,11)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,0)),
                //new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", null, Blocks.STRUCTURE_VOID), new BPos(4,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,7)),
                //new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", null, Blocks.STRUCTURE_VOID), new BPos(11,1,7)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(11,1,15)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(15,1,8))
        ));
        this.put("savanna/streets/crossroad_04", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,4))
        ));
        this.put("savanna/streets/crossroad_05", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,2))
        ));
        this.put("savanna/streets/crossroad_06", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(2,0,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,2))
        ));
        this.put("savanna/streets/crossroad_07", Arrays.asList(
                //new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", null, Blocks.STRUCTURE_VOID), new BPos(7,0,12)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(12,0,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(13,0,9)),
                //new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", null, Blocks.STRUCTURE_VOID), new BPos(7,1,13)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,13)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(9,1,6)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(13,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(14,1,7))
        ));
        this.put("savanna/streets/split_01", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(4,0,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,3))
        ));
        this.put("savanna/streets/split_02", Arrays.asList(
                /*new Pair<>(new Quad<>(PoolType.EMPTY, PoolType.EMPTY, null, Blocks.STRUCTURE_VOID), new BPos(8,0,5)),*/
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(9,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(13,1,4))
        ));
        this.put("savanna/streets/straight_02", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,15)),
                /*new Pair<>(new Quad<>(PoolType.EMPTY, PoolType.EMPTY, null, Blocks.STRUCTURE_VOID), new BPos(2,1,2)),*/
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,3)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,9)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,10)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,11))
        ));
        this.put("savanna/streets/straight_04", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,4))
        ));
        this.put("savanna/streets/straight_05", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,16)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,7)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,9)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,10))
        ));
        this.put("savanna/streets/straight_06", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(1,0,12)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(6,0,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,13)),
                /*new Pair<>(new Quad<>(PoolType.EMPTY, PoolType.EMPTY, null, Blocks.STRUCTURE_VOID), new BPos(6,1,4)),*/
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,0))
        ));
        this.put("savanna/streets/straight_08", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(5,0,6)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(5,0,13)),
                /*new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", null, Blocks.GRASS_BLOCK), new BPos(6,0,4)),*/
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,15))
        ));
        this.put("savanna/streets/straight_09", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(9,0,3)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(11,0,13)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,5)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(9,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,10)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(11,1,5)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(12,1,15)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(13,1,11))
        ));
        this.put("savanna/streets/straight_10", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,10)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,0))
        ));
        this.put("savanna/streets/straight_11", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,16)),
                /*new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", null, Blocks.STRUCTURE_VOID), new BPos(2,1,7)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", null, Blocks.STRUCTURE_VOID), new BPos(2,1,9)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", null, Blocks.STRUCTURE_VOID), new BPos(2,1,10)),*/
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,12))
        ));
        this.put("savanna/streets/turn_01", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(6,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,6)),
                //new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", null, Blocks.STRUCTURE_VOID), new BPos(9,1,7)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(9,1,10)),
                //new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", null, Blocks.STRUCTURE_VOID), new BPos(10,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,5))
        ));
        this.put("savanna/terminators/terminator_05", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(1,0,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(1,0,12)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(1,0,14)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,8))
        ));
        this.put("savanna/town_centers/savanna_meeting_point_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_PATH), new BPos(2,0,4)),
                new Pair<>(new Quad<>(PoolType.IRON_GOLEM, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(3,0,6)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_PATH), new BPos(5,0,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_PATH), new BPos(8,0,4)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_PATH), new BPos(8,0,6)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(8,0,9)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_PATH), new BPos(10,0,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,5)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,11))
        ));
        this.put("savanna/town_centers/savanna_meeting_point_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(1,0,3)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_PATH), new BPos(1,0,6)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(1,0,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_PATH), new BPos(4,0,9)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_PATH), new BPos(7,0,8)),
                new Pair<>(new Quad<>(PoolType.IRON_GOLEM, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(9,0,7)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,5)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,10)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,5))
        ));
        this.put("savanna/town_centers/savanna_meeting_point_3", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(1,0,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_PATH), new BPos(1,0,3)),
                new Pair<>(new Quad<>(PoolType.IRON_GOLEM, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_PATH), new BPos(1,0,7)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_PATH), new BPos(2,0,5)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(7,0,1)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(8,0,9)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,5)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,10)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,5))
        ));
        this.put("savanna/town_centers/savanna_meeting_point_4", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_PATH), new BPos(0,0,3)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_PATH), new BPos(1,0,1)),
                new Pair<>(new Quad<>(PoolType.IRON_GOLEM, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_PATH), new BPos(1,0,7)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(7,0,8)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(8,0,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,4))
        ));
        this.put("savanna/villagers/baby", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("savanna/villagers/nitwit", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("savanna/villagers/unemployed", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("savanna/zombie/houses/savanna_animal_pen_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(0,1,2)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(1,1,10)),
                new Pair<>(new Quad<>(PoolType.ANIMALS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(4,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(7,1,6)),
                new Pair<>(new Quad<>(PoolType.ANIMALS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(8,1,8)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.ACACIA_FENCE_GATE), new BPos(4,2,0))
        ));
        this.put("savanna/zombie/houses/savanna_animal_pen_3", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(2,0,6)),
                new Pair<>(new Quad<>(PoolType.ANIMALS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(4,0,5)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.ACACIA_FENCE), new BPos(4,1,8))
        ));
        this.put("savanna/zombie/houses/savanna_large_farm_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(6,1,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,2,0))
        ));
        this.put("savanna/zombie/houses/savanna_medium_house_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(0,0,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.ACACIA_PLANKS), new BPos(3,0,3)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.ACACIA_PLANKS), new BPos(3,0,11)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,7))
        ));
        this.put("savanna/zombie/houses/savanna_medium_house_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.ACACIA_PLANKS), new BPos(3,0,3)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(7,0,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.ACACIA_PLANKS), new BPos(7,0,8)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,5))
        ));
        this.put("savanna/zombie/houses/savanna_small_house_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(2,0,6)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,6))
        ));
        this.put("savanna/zombie/houses/savanna_small_house_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(2,0,6)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,6))
        ));
        this.put("savanna/zombie/houses/savanna_small_house_3", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(5,0,6)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,6))
        ));
        this.put("savanna/zombie/houses/savanna_small_house_4", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.ACACIA_PLANKS), new BPos(5,0,2)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,6))
        ));
        this.put("savanna/zombie/houses/savanna_small_house_5", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.ACACIA_PLANKS), new BPos(4,0,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(6,1,3))
        ));
        this.put("savanna/zombie/houses/savanna_small_house_6", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.ACACIA_PLANKS), new BPos(3,0,3)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(6,0,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,3))
        ));
        this.put("savanna/zombie/houses/savanna_small_house_7", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(5,0,6)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,6))
        ));
        this.put("savanna/zombie/houses/savanna_small_house_8", Arrays.asList(
                //new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", null, Blocks.GRASS_BLOCK), new BPos(0,0,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.ACACIA_LOG), new BPos(3,0,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,3))
        ));
        this.put("savanna/zombie/streets/corner_01", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(3,0,4)),
                //new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", null, Blocks.GRASS_BLOCK), new BPos(3,0,13)),
                //new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", null, Blocks.GRASS_BLOCK), new BPos(8,0,12)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(10,0,3)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(13,0,9)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,6))
        ));
        this.put("savanna/zombie/streets/corner_03", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,3)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,1))
        ));
        this.put("savanna/zombie/streets/crossroad_02", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(1,0,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(3,0,6)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,5)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,9)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(6,1,5))
        ));
        this.put("savanna/zombie/streets/crossroad_03", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(2,0,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(3,0,13)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(8,0,11)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,0)),
                //new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", null, Blocks.STRUCTURE_VOID), new BPos(4,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,7)),
                //new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", null, Blocks.STRUCTURE_VOID), new BPos(11,1,7)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(11,1,15)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(15,1,8))
        ));
        this.put("savanna/zombie/streets/crossroad_04", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,4))
        ));
        this.put("savanna/zombie/streets/crossroad_05", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,2))
        ));
        this.put("savanna/zombie/streets/crossroad_06", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(2,0,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,2))
        ));
        this.put("savanna/zombie/streets/crossroad_07", Arrays.asList(
                //new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", null, Blocks.STRUCTURE_VOID), new BPos(7,0,12)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(12,0,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(13,0,9)),
                //new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", null, Blocks.STRUCTURE_VOID), new BPos(7,1,13)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,13)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(9,1,6)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(13,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(14,1,7))
        ));
        this.put("savanna/zombie/streets/split_01", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(4,0,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,3))
        ));
        this.put("savanna/zombie/streets/split_02", Arrays.asList(
                //new Pair<>(new Quad<>(PoolType.EMPTY, PoolType.EMPTY, null, Blocks.STRUCTURE_VOID), new BPos(8,0,5)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(9,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(13,1,4))
        ));
        this.put("savanna/zombie/streets/straight_02", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,15)),
                //new Pair<>(new Quad<>(PoolType.EMPTY, PoolType.EMPTY, null, Blocks.STRUCTURE_VOID), new BPos(2,1,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,3)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,9)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,10)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,11))
        ));
        this.put("savanna/zombie/streets/straight_04", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,4))
        ));
        this.put("savanna/zombie/streets/straight_05", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,16)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,7)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,9)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,10))
        ));
        this.put("savanna/zombie/streets/straight_06", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(1,0,12)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(6,0,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,13)),
                //new Pair<>(new Quad<>(PoolType.EMPTY, PoolType.EMPTY, null, Blocks.STRUCTURE_VOID), new BPos(6,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,0))
        ));
        this.put("savanna/zombie/streets/straight_08", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(5,0,6)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(5,0,13)),
                //new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", null, Blocks.GRASS_BLOCK), new BPos(6,0,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,15))
        ));
        this.put("savanna/zombie/streets/straight_09", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(9,0,3)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(11,0,13)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,5)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(9,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,10)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(11,1,5)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(12,1,15)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(13,1,11))
        ));
        this.put("savanna/zombie/streets/straight_10", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,10)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,0))
        ));
        this.put("savanna/zombie/streets/straight_11", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,16)),
                //new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", null, Blocks.STRUCTURE_VOID), new BPos(2,1,7)),
                //new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", null, Blocks.STRUCTURE_VOID), new BPos(2,1,9)),
                //new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", null, Blocks.STRUCTURE_VOID), new BPos(2,1,10)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,12))
        ));
        this.put("savanna/zombie/streets/turn_01", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(6,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,6)),
                //new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", null, Blocks.STRUCTURE_VOID), new BPos(9,1,7)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(9,1,10)),
                //new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", null, Blocks.STRUCTURE_VOID), new BPos(10,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,5))
        ));
        this.put("savanna/zombie/terminators/terminator_05", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(1,0,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(1,0,12)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(1,0,14)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,8))
        ));
        this.put("savanna/zombie/town_centers/savanna_meeting_point_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,5)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,11))
        ));
        this.put("savanna/zombie/town_centers/savanna_meeting_point_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(1,0,3)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(1,0,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,5)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,10)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,5))
        ));
        this.put("savanna/zombie/town_centers/savanna_meeting_point_3", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(1,0,2)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(7,0,1)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(8,0,9)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,5)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,10)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,5))
        ));
        this.put("savanna/zombie/town_centers/savanna_meeting_point_4", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(7,0,8)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(8,0,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,4))
        ));
        this.put("savanna/zombie/villagers/nitwit", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("savanna/zombie/villagers/unemployed", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("pile_melon",Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID),new BPos(0,0,0))
        ));
        this.put("savanna/acacia",Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID),new BPos(0,0,0))
        ));

    }};
    public static final HashMap<String, List<Pair<Quad<PoolType, String, Pair<BlockDirection,BlockDirection>, Block>, BPos>>> JIGSAW_BLOCKS15 = new HashMap<>() {{
        this.putAll(CommonVillageJigsawBlocks.JIGSAW_BLOCKS15);
        this.put("savanna/houses/savanna_animal_pen_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.ACACIA_STAIRS), new BPos(4,0,0)),
                new Pair<>(new Quad<>(PoolType.ANIMALS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(3,0,2))
        ));
        this.put("savanna/houses/savanna_animal_pen_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(0,1,2)),
                new Pair<>(new Quad<>(PoolType.ANIMALS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(4,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(7,1,6)),
                new Pair<>(new Quad<>(PoolType.ANIMALS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(8,1,8)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(1,1,10)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.ACACIA_FENCE_GATE), new BPos(4,2,0))
        ));
        this.put("savanna/houses/savanna_animal_pen_3", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.ANIMALS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(4,0,5)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(2,0,6)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.ACACIA_FENCE), new BPos(4,1,8))
        ));
        this.put("savanna/houses/savanna_armorer_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,3))
        ));
        this.put("savanna/houses/savanna_butchers_shop_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.BUTCHER_ANIMAL, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.DIRT), new BPos(8,0,5)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,0,6))
        ));
        this.put("savanna/houses/savanna_butchers_shop_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.BUTCHER_ANIMAL, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(10,0,2)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.ACACIA_STAIRS), new BPos(0,1,4))
        ));
        this.put("savanna/houses/savanna_cartographer_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.ACACIA_STAIRS), new BPos(0,0,4)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(4,0,4))
        ));
        this.put("savanna/houses/savanna_fisher_cottage_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(4,1,3)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(0,1,7)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(6,1,8)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.ACACIA_STAIRS), new BPos(3,2,0))
        ));
        this.put("savanna/houses/savanna_fletcher_house_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,8))
        ));
        this.put("savanna/houses/savanna_large_farm_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.ACACIA_LOG), new BPos(3,1,8))
        ));
        this.put("savanna/houses/savanna_large_farm_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(6,1,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,2,0))
        ));
        this.put("savanna/houses/savanna_library_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.ACACIA_STAIRS), new BPos(5,1,0))
        ));
        this.put("savanna/houses/savanna_mason_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,5))
        ));
        this.put("savanna/houses/savanna_medium_house_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.ACACIA_PLANKS), new BPos(3,0,3)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(0,0,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.ACACIA_PLANKS), new BPos(3,0,11)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,7))
        ));
        this.put("savanna/houses/savanna_medium_house_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(7,0,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.ACACIA_PLANKS), new BPos(3,0,3)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.ACACIA_PLANKS), new BPos(7,0,8)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,5))
        ));
        this.put("savanna/houses/savanna_shepherd_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SHEEPS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(7,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_TREE, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.DIRT), new BPos(10,1,8)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.AIR), new BPos(0,2,5))
        ));
        this.put("savanna/houses/savanna_small_farm", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,2,0))
        ));
        this.put("savanna/houses/savanna_small_house_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(2,0,6)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,6))
        ));
        this.put("savanna/houses/savanna_small_house_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(2,0,6)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,6))
        ));
        this.put("savanna/houses/savanna_small_house_3", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(5,0,6)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,6))
        ));
        this.put("savanna/houses/savanna_small_house_4", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.ACACIA_PLANKS), new BPos(5,0,2)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,6))
        ));
        this.put("savanna/houses/savanna_small_house_5", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.ACACIA_PLANKS), new BPos(4,0,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(6,1,3))
        ));
        this.put("savanna/houses/savanna_small_house_6", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.ACACIA_PLANKS), new BPos(3,0,3)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(6,0,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,3))
        ));
        this.put("savanna/houses/savanna_small_house_7", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(5,0,6)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,6))
        ));
        this.put("savanna/houses/savanna_small_house_8", Arrays.asList(
                /*new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", null, Blocks.GRASS_BLOCK), new BPos(0,0,0)),*/
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.ACACIA_LOG), new BPos(3,0,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,3))
        ));
        this.put("savanna/houses/savanna_tannery_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(6,1,4))
        ));
        this.put("savanna/houses/savanna_temple_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,4))
        ));
        this.put("savanna/houses/savanna_temple_2", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,4))
        ));
        this.put("savanna/houses/savanna_tool_smith_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,4))
        ));
        this.put("savanna/houses/savanna_weaponsmith_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,4))
        ));
        this.put("savanna/houses/savanna_weaponsmith_2", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.SMOOTH_STONE_SLAB), new BPos(0,1,6))
        ));
        this.put("savanna/savanna_lamp_post_01", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.ACACIA_FENCE), new BPos(0,0,0))
        ));
        this.put("savanna/streets/corner_01", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(10,0,3)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(3,0,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(13,0,9)),
                /*new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", null, Blocks.GRASS_BLOCK), new BPos(8,0,12)),*/
                /*new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", null, Blocks.GRASS_BLOCK), new BPos(3,0,13)),*/
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,6)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,8))
        ));
        this.put("savanna/streets/corner_03", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,1)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,3))
        ));
        this.put("savanna/streets/crossroad_02", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(1,0,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(3,0,6)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,5)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(6,1,5)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,9))
        ));
        this.put("savanna/streets/crossroad_03", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(2,0,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(8,0,11)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(3,0,13)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,0)),
                /*new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", null, Blocks.STRUCTURE_VOID), new BPos(4,1,0)),*/
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,7)),
                /*new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", null, Blocks.STRUCTURE_VOID), new BPos(11,1,7)),*/
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(15,1,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(11,1,15))
        ));
        this.put("savanna/streets/crossroad_04", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,4))
        ));
        this.put("savanna/streets/crossroad_05", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,4))
        ));
        this.put("savanna/streets/crossroad_06", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(2,0,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,4))
        ));
        this.put("savanna/streets/crossroad_07", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(12,0,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(13,0,9)),
                /*new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", null, Blocks.STRUCTURE_VOID), new BPos(7,0,12)),*/
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(13,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(9,1,6)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(14,1,7)),
                /*new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", null, Blocks.STRUCTURE_VOID), new BPos(7,1,13)),*/
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,13))
        ));
        this.put("savanna/streets/split_01", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(4,0,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,3)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,4))
        ));
        this.put("savanna/streets/split_02", Arrays.asList(
                /*new Pair<>(new Quad<>(PoolType.EMPTY, PoolType.EMPTY, null, Blocks.STRUCTURE_VOID), new BPos(8,0,5)),*/
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(9,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(13,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,8))
        ));
        this.put("savanna/streets/straight_02", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,0)),
                /*new Pair<>(new Quad<>(PoolType.EMPTY, PoolType.EMPTY, null, Blocks.STRUCTURE_VOID), new BPos(2,1,2)),*/
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,3)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,9)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,10)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,11)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,15))
        ));
        this.put("savanna/streets/straight_04", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,8))
        ));
        this.put("savanna/streets/straight_05", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,7)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,9)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,10)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,16))
        ));
        this.put("savanna/streets/straight_06", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(6,0,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(1,0,12)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,0)),
                /*new Pair<>(new Quad<>(PoolType.EMPTY, PoolType.EMPTY, null, Blocks.STRUCTURE_VOID), new BPos(6,1,4)),*/
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,13))
        ));
        this.put("savanna/streets/straight_08", Arrays.asList(
                /*new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", null, Blocks.GRASS_BLOCK), new BPos(6,0,4)),*/
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(5,0,6)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(5,0,13)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,15))
        ));
        this.put("savanna/streets/straight_09", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(9,0,3)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(11,0,13)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(9,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,5)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(11,1,5)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,10)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(13,1,11)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(12,1,15))
        ));
        this.put("savanna/streets/straight_10", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,10))
        ));
        this.put("savanna/streets/straight_11", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,0)),
                /*new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", null, Blocks.STRUCTURE_VOID), new BPos(2,1,7)),*/
                /*new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", null, Blocks.STRUCTURE_VOID), new BPos(2,1,9)),*/
                /*new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", null, Blocks.STRUCTURE_VOID), new BPos(2,1,10)),*/
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,12)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,16))
        ));
        this.put("savanna/streets/turn_01", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(6,1,0)),
                /*new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", null, Blocks.STRUCTURE_VOID), new BPos(10,1,4)),*/
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,5)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,6)),
                /*new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", null, Blocks.STRUCTURE_VOID), new BPos(9,1,7)),*/
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(9,1,10))
        ));
        this.put("savanna/terminators/terminator_05", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(1,0,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(1,0,12)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(1,0,14)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,8))
        ));
        this.put("savanna/town_centers/savanna_meeting_point_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_PATH), new BPos(10,0,2)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_PATH), new BPos(2,0,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_PATH), new BPos(5,0,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_PATH), new BPos(8,0,4)),
                new Pair<>(new Quad<>(PoolType.IRON_GOLEM, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(3,0,6)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_PATH), new BPos(8,0,6)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(8,0,9)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,5)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,11))
        ));
        this.put("savanna/town_centers/savanna_meeting_point_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(1,0,3)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_PATH), new BPos(1,0,6)),
                new Pair<>(new Quad<>(PoolType.IRON_GOLEM, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(9,0,7)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(1,0,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_PATH), new BPos(7,0,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_PATH), new BPos(4,0,9)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,5)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,5)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,10))
        ));
        this.put("savanna/town_centers/savanna_meeting_point_3", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(7,0,1)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(1,0,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_PATH), new BPos(1,0,3)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_PATH), new BPos(2,0,5)),
                new Pair<>(new Quad<>(PoolType.IRON_GOLEM, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_PATH), new BPos(1,0,7)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(8,0,9)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,5)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,5)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,10))
        ));
        this.put("savanna/town_centers/savanna_meeting_point_4", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(8,0,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_PATH), new BPos(1,0,1)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_PATH), new BPos(0,0,3)),
                new Pair<>(new Quad<>(PoolType.IRON_GOLEM, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_PATH), new BPos(1,0,7)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(7,0,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,8))
        ));
        this.put("savanna/villagers/baby", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("savanna/villagers/nitwit", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("savanna/villagers/unemployed", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("savanna/zombie/houses/savanna_animal_pen_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(0,1,2)),
                new Pair<>(new Quad<>(PoolType.ANIMALS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(4,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(7,1,6)),
                new Pair<>(new Quad<>(PoolType.ANIMALS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(8,1,8)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(1,1,10)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.ACACIA_FENCE_GATE), new BPos(4,2,0))
        ));
        this.put("savanna/zombie/houses/savanna_animal_pen_3", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.ANIMALS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(4,0,5)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(2,0,6)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.ACACIA_FENCE), new BPos(4,1,8))
        ));
        this.put("savanna/zombie/houses/savanna_large_farm_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(6,1,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,2,0))
        ));
        this.put("savanna/zombie/houses/savanna_medium_house_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.ACACIA_PLANKS), new BPos(3,0,3)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(0,0,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.ACACIA_PLANKS), new BPos(3,0,11)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,7))
        ));
        this.put("savanna/zombie/houses/savanna_medium_house_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(7,0,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.ACACIA_PLANKS), new BPos(3,0,3)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.ACACIA_PLANKS), new BPos(7,0,8)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,5))
        ));
        this.put("savanna/zombie/houses/savanna_small_house_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(2,0,6)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,6))
        ));
        this.put("savanna/zombie/houses/savanna_small_house_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(2,0,6)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,6))
        ));
        this.put("savanna/zombie/houses/savanna_small_house_3", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(5,0,6)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,6))
        ));
        this.put("savanna/zombie/houses/savanna_small_house_4", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.ACACIA_PLANKS), new BPos(5,0,2)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,6))
        ));
        this.put("savanna/zombie/houses/savanna_small_house_5", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.ACACIA_PLANKS), new BPos(4,0,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(6,1,3))
        ));
        this.put("savanna/zombie/houses/savanna_small_house_6", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.ACACIA_PLANKS), new BPos(3,0,3)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(6,0,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,3))
        ));
        this.put("savanna/zombie/houses/savanna_small_house_7", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(5,0,6)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,6))
        ));
        this.put("savanna/zombie/houses/savanna_small_house_8", Arrays.asList(
                /*new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", null, Blocks.GRASS_BLOCK), new BPos(0,0,0)),*/
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.ACACIA_LOG), new BPos(3,0,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,3))
        ));
        this.put("savanna/zombie/streets/corner_01", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(10,0,3)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(3,0,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(13,0,9)),
                /*new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", null, Blocks.GRASS_BLOCK), new BPos(8,0,12)),*/
                /*new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", null, Blocks.GRASS_BLOCK), new BPos(3,0,13)),*/
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,6)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,8))
        ));
        this.put("savanna/zombie/streets/corner_03", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,1)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,3))
        ));
        this.put("savanna/zombie/streets/crossroad_02", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(1,0,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(3,0,6)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,5)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(6,1,5)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,9))
        ));
        this.put("savanna/zombie/streets/crossroad_03", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(2,0,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(8,0,11)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(3,0,13)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,0)),
                /*new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", null, Blocks.STRUCTURE_VOID), new BPos(4,1,0)),*/
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,7)),
                /*new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", null, Blocks.STRUCTURE_VOID), new BPos(11,1,7)),*/
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(15,1,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(11,1,15))
        ));
        this.put("savanna/zombie/streets/crossroad_04", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,4))
        ));
        this.put("savanna/zombie/streets/crossroad_05", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,4))
        ));
        this.put("savanna/zombie/streets/crossroad_06", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(2,0,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,4))
        ));
        this.put("savanna/zombie/streets/crossroad_07", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(12,0,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(13,0,9)),
                /*new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", null, Blocks.STRUCTURE_VOID), new BPos(7,0,12)),*/
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(13,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(9,1,6)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(14,1,7)),
                /*new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", null, Blocks.STRUCTURE_VOID), new BPos(7,1,13)),*/
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,13))
        ));
        this.put("savanna/zombie/streets/split_01", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(4,0,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,3)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,4))
        ));
        this.put("savanna/zombie/streets/split_02", Arrays.asList(
                /*new Pair<>(new Quad<>(PoolType.EMPTY, PoolType.EMPTY, null, Blocks.STRUCTURE_VOID), new BPos(8,0,5)),*/
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(9,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(13,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,8))
        ));
        this.put("savanna/zombie/streets/straight_02", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,0)),
                /*new Pair<>(new Quad<>(PoolType.EMPTY, PoolType.EMPTY, null, Blocks.STRUCTURE_VOID), new BPos(2,1,2)),*/
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,3)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,9)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,10)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,11)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,15))
        ));
        this.put("savanna/zombie/streets/straight_04", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,8))
        ));
        this.put("savanna/zombie/streets/straight_05", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,7)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,9)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,10)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,16))
        ));
        this.put("savanna/zombie/streets/straight_06", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(6,0,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(1,0,12)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,0)),
                /*new Pair<>(new Quad<>(PoolType.EMPTY, PoolType.EMPTY, null, Blocks.STRUCTURE_VOID), new BPos(6,1,4)),*/
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,13))
        ));
        this.put("savanna/zombie/streets/straight_08", Arrays.asList(
                /*new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", null, Blocks.GRASS_BLOCK), new BPos(6,0,4)),*/
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(5,0,6)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(5,0,13)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,15))
        ));
        this.put("savanna/zombie/streets/straight_09", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(9,0,3)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(11,0,13)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(9,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,5)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(11,1,5)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,10)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(13,1,11)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(12,1,15))
        ));
        this.put("savanna/zombie/streets/straight_10", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,10))
        ));
        this.put("savanna/zombie/streets/straight_11", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,0)),
                /*new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", null, Blocks.STRUCTURE_VOID), new BPos(2,1,7)),*/
                /*new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", null, Blocks.STRUCTURE_VOID), new BPos(2,1,9)),*/
                /*new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", null, Blocks.STRUCTURE_VOID), new BPos(2,1,10)),*/
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,12)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,16))
        ));
        this.put("savanna/zombie/streets/turn_01", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(6,1,0)),
                /*new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", null, Blocks.STRUCTURE_VOID), new BPos(10,1,4)),*/
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,5)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,6)),
                /*new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", null, Blocks.STRUCTURE_VOID), new BPos(9,1,7)),*/
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(9,1,10))
        ));
        this.put("savanna/zombie/terminators/terminator_05", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(1,0,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(1,0,12)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(1,0,14)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,8))
        ));
        this.put("savanna/zombie/town_centers/savanna_meeting_point_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,5)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,11))
        ));
        this.put("savanna/zombie/town_centers/savanna_meeting_point_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(1,0,3)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(1,0,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,5)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,5)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,10))
        ));
        this.put("savanna/zombie/town_centers/savanna_meeting_point_3", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(7,0,1)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(1,0,2)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(8,0,9)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,5)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,5)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,10))
        ));
        this.put("savanna/zombie/town_centers/savanna_meeting_point_4", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(8,0,0)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(7,0,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,8))
        ));
        this.put("savanna/zombie/villagers/nitwit", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("savanna/zombie/villagers/unemployed", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("pile_melon",Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID),new BPos(0,0,0))
        ));
        this.put("savanna/acacia",Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID),new BPos(0,0,0))
        ));
    }};
    public static final HashMap<String, List<Pair<Quad<PoolType, String, Pair<BlockDirection,BlockDirection>, Block>, BPos>>> JIGSAW_BLOCKS17 = new HashMap<>() {{
        this.putAll(CommonVillageJigsawBlocks.JIGSAW_BLOCKS);
        this.put("savanna/houses/savanna_animal_pen_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.ANIMALS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(3,0,2)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.ACACIA_STAIRS), new BPos(4,0,0))
        ));
        this.put("savanna/houses/savanna_animal_pen_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(0,1,2)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(1,1,10)),
                new Pair<>(new Quad<>(PoolType.ANIMALS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(4,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(7,1,6)),
                new Pair<>(new Quad<>(PoolType.ANIMALS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(8,1,8)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.ACACIA_FENCE_GATE), new BPos(4,2,0))
        ));
        this.put("savanna/houses/savanna_animal_pen_3", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(2,0,6)),
                new Pair<>(new Quad<>(PoolType.ANIMALS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(4,0,5)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.ACACIA_FENCE), new BPos(4,1,8))
        ));
        this.put("savanna/houses/savanna_armorer_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,3))
        ));
        this.put("savanna/houses/savanna_butchers_shop_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,0,6)),
                new Pair<>(new Quad<>(PoolType.BUTCHER_ANIMAL, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.DIRT), new BPos(8,0,5))
        ));
        this.put("savanna/houses/savanna_butchers_shop_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.BUTCHER_ANIMAL, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(10,0,2)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.ACACIA_STAIRS), new BPos(0,1,4))
        ));
        this.put("savanna/houses/savanna_cartographer_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.ACACIA_STAIRS), new BPos(0,0,4)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(4,0,4))
        ));
        this.put("savanna/houses/savanna_fisher_cottage_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(0,1,7)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(4,1,3)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(6,1,8)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.ACACIA_STAIRS), new BPos(3,2,0))
        ));
        this.put("savanna/houses/savanna_fletcher_house_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,8))
        ));
        this.put("savanna/houses/savanna_large_farm_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.ACACIA_LOG), new BPos(3,1,8))
        ));
        this.put("savanna/houses/savanna_large_farm_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(6,1,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,2,0))
        ));
        this.put("savanna/houses/savanna_library_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.ACACIA_STAIRS), new BPos(5,1,0))
        ));
        this.put("savanna/houses/savanna_mason_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,5))
        ));
        this.put("savanna/houses/savanna_medium_house_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(0,0,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.ACACIA_PLANKS), new BPos(3,0,3)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.ACACIA_PLANKS), new BPos(3,0,11)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,7))
        ));
        this.put("savanna/houses/savanna_medium_house_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.ACACIA_PLANKS), new BPos(3,0,3)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(7,0,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.ACACIA_PLANKS), new BPos(7,0,8)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,5))
        ));
        this.put("savanna/houses/savanna_shepherd_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SHEEPS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(7,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_TREE, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.DIRT), new BPos(10,1,8)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.AIR), new BPos(0,2,5))
        ));
        this.put("savanna/houses/savanna_small_farm", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,2,0))
        ));
        this.put("savanna/houses/savanna_small_house_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(2,0,6)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,6))
        ));
        this.put("savanna/houses/savanna_small_house_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(2,0,6)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,6))
        ));
        this.put("savanna/houses/savanna_small_house_3", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(5,0,6)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,6))
        ));
        this.put("savanna/houses/savanna_small_house_4", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.ACACIA_PLANKS), new BPos(5,0,2)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,6))
        ));
        this.put("savanna/houses/savanna_small_house_5", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.ACACIA_PLANKS), new BPos(4,0,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(6,1,3))
        ));
        this.put("savanna/houses/savanna_small_house_6", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.ACACIA_PLANKS), new BPos(3,0,3)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(6,0,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,3))
        ));
        this.put("savanna/houses/savanna_small_house_7", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(5,0,6)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,6))
        ));
        this.put("savanna/houses/savanna_small_house_8", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(0,0,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.ACACIA_LOG), new BPos(3,0,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,3))
        ));
        this.put("savanna/houses/savanna_tannery_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(6,1,4))
        ));
        this.put("savanna/houses/savanna_temple_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,4))
        ));
        this.put("savanna/houses/savanna_temple_2", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,4))
        ));
        this.put("savanna/houses/savanna_tool_smith_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,4))
        ));
        this.put("savanna/houses/savanna_weaponsmith_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,4))
        ));
        this.put("savanna/houses/savanna_weaponsmith_2", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.SMOOTH_STONE_SLAB), new BPos(0,1,6))
        ));
        this.put("savanna/savanna_lamp_post_01", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.ACACIA_FENCE), new BPos(0,0,0))
        ));
        this.put("savanna/streets/corner_01", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(3,0,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(3,0,13)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(8,0,12)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(10,0,3)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(13,0,9)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,6))
        ));
        this.put("savanna/streets/corner_03", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,3)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,1))
        ));
        this.put("savanna/streets/crossroad_02", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(1,0,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(3,0,6)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,5)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,9)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(6,1,5))
        ));
        this.put("savanna/streets/crossroad_03", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(2,0,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(3,0,13)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(8,0,11)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,7)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(11,1,7)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(11,1,15)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(15,1,8))
        ));
        this.put("savanna/streets/crossroad_04", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,4))
        ));
        this.put("savanna/streets/crossroad_05", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,2))
        ));
        this.put("savanna/streets/crossroad_06", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(2,0,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,2))
        ));
        this.put("savanna/streets/crossroad_07", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.DIRT_PATH), new BPos(7,0,12)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(12,0,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(13,0,9)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,13)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,13)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(9,1,6)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(13,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(14,1,7))
        ));
        this.put("savanna/streets/split_01", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(4,0,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,3))
        ));
        this.put("savanna/streets/split_02", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(9,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(13,1,4))
        ));
        this.put("savanna/streets/straight_02", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,15)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,3)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,9)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,10)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,11))
        ));
        this.put("savanna/streets/straight_04", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,4))
        ));
        this.put("savanna/streets/straight_05", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,16)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,7)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,9)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,10))
        ));
        this.put("savanna/streets/straight_06", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(1,0,12)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(6,0,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,13)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,0))
        ));
        this.put("savanna/streets/straight_08", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(5,0,6)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(5,0,13)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(6,0,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,15))
        ));
        this.put("savanna/streets/straight_09", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(9,0,3)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(11,0,13)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,5)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(9,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,10)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(11,1,5)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(12,1,15)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(13,1,11))
        ));
        this.put("savanna/streets/straight_10", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,10)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,0))
        ));
        this.put("savanna/streets/straight_11", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,16)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,12))
        ));
        this.put("savanna/streets/turn_01", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(6,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,6)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(9,1,10)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,5))
        ));
        this.put("savanna/terminators/terminator_05", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(1,0,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(1,0,12)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_DECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(1,0,14)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_HOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,8))
        ));
        this.put("savanna/town_centers/savanna_meeting_point_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.DIRT_PATH), new BPos(2,0,4)),
                new Pair<>(new Quad<>(PoolType.IRON_GOLEM, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(3,0,6)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.DIRT_PATH), new BPos(5,0,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.DIRT_PATH), new BPos(8,0,4)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.DIRT_PATH), new BPos(8,0,6)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(8,0,9)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.DIRT_PATH), new BPos(10,0,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,5)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,11))
        ));
        this.put("savanna/town_centers/savanna_meeting_point_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(1,0,3)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.DIRT_PATH), new BPos(1,0,6)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(1,0,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.DIRT_PATH), new BPos(4,0,9)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.DIRT_PATH), new BPos(7,0,8)),
                new Pair<>(new Quad<>(PoolType.IRON_GOLEM, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(9,0,7)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,5)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,10)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,5))
        ));
        this.put("savanna/town_centers/savanna_meeting_point_3", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(1,0,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.DIRT_PATH), new BPos(1,0,3)),
                new Pair<>(new Quad<>(PoolType.IRON_GOLEM, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.DIRT_PATH), new BPos(1,0,7)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.DIRT_PATH), new BPos(2,0,5)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(7,0,1)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(8,0,9)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,5)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,10)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,5))
        ));
        this.put("savanna/town_centers/savanna_meeting_point_4", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.DIRT_PATH), new BPos(0,0,3)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_VILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.DIRT_PATH), new BPos(1,0,1)),
                new Pair<>(new Quad<>(PoolType.IRON_GOLEM, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.DIRT_PATH), new BPos(1,0,7)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(7,0,8)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(8,0,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,4))
        ));
        this.put("savanna/villagers/baby", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("savanna/villagers/nitwit", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("savanna/villagers/unemployed", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("savanna/zombie/houses/savanna_animal_pen_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(0,1,2)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(1,1,10)),
                new Pair<>(new Quad<>(PoolType.ANIMALS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(4,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(7,1,6)),
                new Pair<>(new Quad<>(PoolType.ANIMALS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(8,1,8)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.ACACIA_FENCE_GATE), new BPos(4,2,0))
        ));
        this.put("savanna/zombie/houses/savanna_animal_pen_3", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(2,0,6)),
                new Pair<>(new Quad<>(PoolType.ANIMALS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(4,0,5)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.ACACIA_FENCE), new BPos(4,1,8))
        ));
        this.put("savanna/zombie/houses/savanna_large_farm_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(6,1,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,2,0))
        ));
        this.put("savanna/zombie/houses/savanna_medium_house_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(0,0,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.ACACIA_PLANKS), new BPos(3,0,3)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.ACACIA_PLANKS), new BPos(3,0,11)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,7))
        ));
        this.put("savanna/zombie/houses/savanna_medium_house_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.ACACIA_PLANKS), new BPos(3,0,3)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(7,0,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.ACACIA_PLANKS), new BPos(7,0,8)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,5))
        ));
        this.put("savanna/zombie/houses/savanna_small_house_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(2,0,6)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,6))
        ));
        this.put("savanna/zombie/houses/savanna_small_house_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(2,0,6)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,6))
        ));
        this.put("savanna/zombie/houses/savanna_small_house_3", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(5,0,6)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,6))
        ));
        this.put("savanna/zombie/houses/savanna_small_house_4", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.ACACIA_PLANKS), new BPos(5,0,2)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,6))
        ));
        this.put("savanna/zombie/houses/savanna_small_house_5", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.ACACIA_PLANKS), new BPos(4,0,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(6,1,3))
        ));
        this.put("savanna/zombie/houses/savanna_small_house_6", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.ACACIA_PLANKS), new BPos(3,0,3)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(6,0,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,3))
        ));
        this.put("savanna/zombie/houses/savanna_small_house_7", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(5,0,6)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,6))
        ));
        this.put("savanna/zombie/houses/savanna_small_house_8", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(0,0,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZVILLAGER, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.ACACIA_LOG), new BPos(3,0,3)),
                new Pair<>(new Quad<>(PoolType.EMPTY, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,3))
        ));
        this.put("savanna/zombie/streets/corner_01", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(3,0,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(3,0,13)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(8,0,12)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(10,0,3)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(13,0,9)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,6))
        ));
        this.put("savanna/zombie/streets/corner_03", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,3)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,1))
        ));
        this.put("savanna/zombie/streets/crossroad_02", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(1,0,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(3,0,6)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,5)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,9)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(6,1,5))
        ));
        this.put("savanna/zombie/streets/crossroad_03", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(2,0,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(3,0,13)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(8,0,11)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,7)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(11,1,7)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(11,1,15)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(15,1,8))
        ));
        this.put("savanna/zombie/streets/crossroad_04", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,4))
        ));
        this.put("savanna/zombie/streets/crossroad_05", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,2))
        ));
        this.put("savanna/zombie/streets/crossroad_06", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(2,0,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,2))
        ));
        this.put("savanna/zombie/streets/crossroad_07", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.DIRT_PATH), new BPos(7,0,12)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(12,0,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(13,0,9)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,13)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,13)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(9,1,6)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(13,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(14,1,7))
        ));
        this.put("savanna/zombie/streets/split_01", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(4,0,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,3))
        ));
        this.put("savanna/zombie/streets/split_02", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(9,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(13,1,4))
        ));
        this.put("savanna/zombie/streets/straight_02", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,15)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,3)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,9)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,10)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,11))
        ));
        this.put("savanna/zombie/streets/straight_04", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,4))
        ));
        this.put("savanna/zombie/streets/straight_05", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,16)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,7)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,9)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,10))
        ));
        this.put("savanna/zombie/streets/straight_06", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(1,0,12)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(6,0,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,13)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,0))
        ));
        this.put("savanna/zombie/streets/straight_08", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(5,0,6)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(5,0,13)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(6,0,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,15))
        ));
        this.put("savanna/zombie/streets/straight_09", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(9,0,3)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(11,0,13)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,5)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(9,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,10)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(11,1,5)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(12,1,15)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(13,1,11))
        ));
        this.put("savanna/zombie/streets/straight_10", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,10)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,0))
        ));
        this.put("savanna/zombie/streets/straight_11", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,16)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,12))
        ));
        this.put("savanna/zombie/streets/turn_01", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(6,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,6)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(9,1,10)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,5))
        ));
        this.put("savanna/zombie/terminators/terminator_05", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(1,0,2)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(1,0,12)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZDECOR, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.STRUCTURE_VOID), new BPos(1,0,14)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZHOUSES, "building_entrance", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,8))
        ));
        this.put("savanna/zombie/town_centers/savanna_meeting_point_1", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,5)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(7,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,11))
        ));
        this.put("savanna/zombie/town_centers/savanna_meeting_point_2", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(1,0,3)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(1,0,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,5)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(5,1,10)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(10,1,5))
        ));
        this.put("savanna/zombie/town_centers/savanna_meeting_point_3", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(1,0,2)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(7,0,1)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(8,0,9)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,5)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,10)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,5))
        ));
        this.put("savanna/zombie/town_centers/savanna_meeting_point_4", Arrays.asList(
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(7,0,8)),
                new Pair<>(new Quad<>(PoolType.CATS, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.GRASS_BLOCK), new BPos(8,0,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.WEST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,4)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.NORTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,0)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.SOUTH,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(4,1,8)),
                new Pair<>(new Quad<>(PoolType.SAVANNA_ZSTREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(8,1,4))
        ));
        this.put("savanna/zombie/villagers/nitwit", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("savanna/zombie/villagers/unemployed", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("pile_melon",Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID),new BPos(0,0,0))
        ));
        this.put("savanna/acacia",Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID),new BPos(0,0,0))
        ));
    }};
}

