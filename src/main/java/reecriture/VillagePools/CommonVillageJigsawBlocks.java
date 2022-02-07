package reecriture.VillagePools;

import kaptainwutax.mcutils.block.Block;
import kaptainwutax.mcutils.block.Blocks;
import kaptainwutax.mcutils.util.data.Pair;
import kaptainwutax.mcutils.util.data.Quad;
import kaptainwutax.mcutils.util.pos.BPos;

import java.util.Collections;
import java.util.HashMap;
import java.util.List;

public class CommonVillageJigsawBlocks {
    public static final HashMap<String, List<Pair<Quad<String, String, String, Block>, BPos>>> JIGSAW_BLOCKS = new HashMap<String, List<Pair<Quad<String, String, String, Block>, BPos>>>() {{
        this.put("common/iron_golem", Collections.singletonList(
                new Pair<>(new Quad<>("empty", "bottom", "down_south", Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/well_bottom", Collections.singletonList(
                new Pair<>(new Quad<>("common/well_bottoms", "bottom", "up_north", Blocks.COBBLESTONE), new BPos(3,2,0))
        ));
        this.put("common/animals/cat_black", Collections.singletonList(
                new Pair<>(new Quad<>("empty", "bottom", "down_south", Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/cat_british", Collections.singletonList(
                new Pair<>(new Quad<>("empty", "bottom", "down_south", Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/cat_calico", Collections.singletonList(
                new Pair<>(new Quad<>("empty", "bottom", "down_south", Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/cat_jellie", Collections.singletonList(
                new Pair<>(new Quad<>("empty", "bottom", "down_south", Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/cat_persia", Collections.singletonList(
                new Pair<>(new Quad<>("empty", "bottom", "down_south", Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/cat_ragdoll", Collections.singletonList(
                new Pair<>(new Quad<>("empty", "bottom", "down_south", Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/cat_red", Collections.singletonList(
                new Pair<>(new Quad<>("empty", "bottom", "down_south", Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/cat_siamese", Collections.singletonList(
                new Pair<>(new Quad<>("empty", "bottom", "down_south", Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/cat_tabby", Collections.singletonList(
                new Pair<>(new Quad<>("empty", "bottom", "down_south", Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/cat_white", Collections.singletonList(
                new Pair<>(new Quad<>("empty", "bottom", "down_south", Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/cows_1", Collections.singletonList(
                new Pair<>(new Quad<>("empty", "bottom", "down_south", Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/horses_1", Collections.singletonList(
                new Pair<>(new Quad<>("empty", "bottom", "down_south", Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/horses_2", Collections.singletonList(
                new Pair<>(new Quad<>("empty", "bottom", "down_south", Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/horses_3", Collections.singletonList(
                new Pair<>(new Quad<>("empty", "bottom", "down_south", Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/horses_4", Collections.singletonList(
                new Pair<>(new Quad<>("empty", "bottom", "down_south", Blocks.HAY_BLOCK), new BPos(0,0,0))
        ));
        this.put("common/animals/horses_5", Collections.singletonList(
                new Pair<>(new Quad<>("empty", "bottom", "down_south", Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/pigs_1", Collections.singletonList(
                new Pair<>(new Quad<>("empty", "bottom", "down_south", Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/sheep_1", Collections.singletonList(
                new Pair<>(new Quad<>("empty", "bottom", "down_south", Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("common/animals/sheep_2", Collections.singletonList(
                new Pair<>(new Quad<>("empty", "bottom", "down_south", Blocks.STRUCTURE_VOID), new BPos(0,0,0))
        ));
        this.put("decays/grass_11x13", Collections.emptyList(
        ));
        this.put("decays/grass_16x16", Collections.emptyList(
        ));
        this.put("decays/grass_9x9", Collections.emptyList(
        ));
    }};
}
