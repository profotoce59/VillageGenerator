package profotoce59.reecriture.VillagePools;

import com.seedfinding.mccore.block.Block;
import com.seedfinding.mccore.block.Blocks;
import com.seedfinding.mccore.util.block.BlockDirection;
import com.seedfinding.mccore.util.data.Pair;
import com.seedfinding.mccore.util.data.Quad;
import com.seedfinding.mccore.util.pos.BPos;
import profotoce59.enumType.PoolType;

import java.util.Collections;
import java.util.HashMap;
import java.util.List;

public class CommonVillageJigsawBlocks {
    public static final HashMap<String, List<Pair<Quad<PoolType, String, Pair<BlockDirection,BlockDirection>, Block>, BPos>>> JIGSAW_BLOCKS = new HashMap<>() {{
        this.put("common/iron_golem", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/well_bottom", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.WELL_BOTTOM, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.COBBLESTONE), new BPos(3,2,0))
        ));
        this.put("common/animals/cat_black", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/cat_british", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/cat_calico", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/cat_jellie", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/cat_persian", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/cat_persia", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/cat_ragdoll", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/cat_red", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/cat_siamese", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/cat_tabby", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/cat_white", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/cows_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/horses_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/horses_2", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/horses_3", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/horses_4", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.HAY_BLOCK), new BPos(0,0,0))
        ));
        this.put("common/animals/horses_5", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/pigs_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/sheep_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/sheep_2", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("decays/grass_11x13", Collections.emptyList(
        ));
        this.put("decays/grass_16x16", Collections.emptyList(
        ));
        this.put("decays/grass_9x9", Collections.emptyList(
        ));
        this.put("plains/terminators/terminator_01", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,1))
        ));
        this.put("plains/terminators/terminator_02", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,0))
        ));
        this.put("plains/terminators/terminator_03", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,1))
        ));
        this.put("plains/terminators/terminator_04", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,1))
        ));
        this.put("patch_cactus", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH) ,Blocks.STRUCTURE_VOID),new BPos(0,0,0))
        ));
        this.put("pile_hay", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH) ,Blocks.STRUCTURE_VOID),new BPos(0,0,0))
        ));
    }};
    public static final HashMap<String, List<Pair<Quad<PoolType, String, Pair<BlockDirection,BlockDirection>, Block>, BPos>>> JIGSAW_BLOCKS15 = new HashMap<>() {{
        this.put("common/iron_golem", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/well_bottom", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.WELL_BOTTOM, "bottom", new Pair<>(BlockDirection.UP,BlockDirection.NORTH), Blocks.COBBLESTONE), new BPos(3,2,0))
        ));
        this.put("common/animals/cat_black", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/cat_british", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/cat_calico", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/cat_jellie", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/cat_persian", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/cat_persia", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/cat_ragdoll", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/cat_red", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/cat_siamese", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/cat_tabby", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/cat_white", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/cows_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/horses_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/horses_2", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/horses_3", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/horses_4", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.HAY_BLOCK), new BPos(0,0,0))
        ));
        this.put("common/animals/horses_5", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/pigs_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/sheep_1", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/sheep_2", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH), Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("decays/grass_11x13", Collections.emptyList(
        ));
        this.put("decays/grass_16x16", Collections.emptyList(
        ));
        this.put("decays/grass_9x9", Collections.emptyList(
        ));
        this.put("plains/terminators/terminator_01", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.PLAIN_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(1,1,1))
        ));
        this.put("plains/terminators/terminator_02", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.PLAIN_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(0,1,0))
        ));
        this.put("plains/terminators/terminator_03", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.PLAIN_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(2,1,1))
        ));
        this.put("plains/terminators/terminator_04", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.PLAIN_STREET, "street", new Pair<>(BlockDirection.EAST,BlockDirection.UP), Blocks.STRUCTURE_VOID), new BPos(3,1,1))
        ));
        this.put("patch_cactus", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH) ,Blocks.STRUCTURE_VOID),new BPos(0,0,0))
        ));
        this.put("pile_hay", Collections.singletonList(
                new Pair<>(new Quad<>(PoolType.EMPTY, "bottom", new Pair<>(BlockDirection.DOWN,BlockDirection.SOUTH) ,Blocks.STRUCTURE_VOID),new BPos(0,0,0))
        ));
//"plains/streets" instead of empty for the terminator
    }};
}
