package profotoce59.reecriture.VillagePools;

import com.seedfinding.mccore.util.data.Pair;
import com.seedfinding.mccore.util.data.Triplet;
import profotoce59.enumType.PoolType;
import profotoce59.properties.VillageGenerator;

import java.util.Arrays;
import java.util.Collections;
import java.util.EnumMap;
import java.util.List;

public interface CommonPool {
    public static final EnumMap<PoolType, Triplet<PoolType, List<Pair<String, Integer>>, VillageGenerator.PlacementBehaviour>> VILLAGE_POOLS = new EnumMap<>(PoolType.class) {{
        put(PoolType.ANIMALS, new Triplet<>(PoolType.EMPTY, Arrays.asList(
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
        ), VillageGenerator.PlacementBehaviour.RIGID));
        put(PoolType.SHEEPS, new Triplet<>(PoolType.EMPTY, Arrays.asList(
                new Pair<>("common/animals/sheep_1", 1),
                new Pair<>("common/animals/sheep_2", 1)
        ), VillageGenerator.PlacementBehaviour.RIGID));
        put(PoolType.CATS, new Triplet<>(PoolType.EMPTY, Arrays.asList(
                new Pair<>("common/animals/cat_black", 1),
                new Pair<>("common/animals/cat_british", 1),
                new Pair<>("common/animals/cat_calico", 1),
                new Pair<>("common/animals/cat_persian", 1),
                new Pair<>("common/animals/cat_ragdoll", 1),
                new Pair<>("common/animals/cat_red", 1),
                new Pair<>("common/animals/cat_siamese", 1),
                new Pair<>("common/animals/cat_tabby", 1),
                new Pair<>("common/animals/cat_white", 1),
                new Pair<>("common/animals/cat_jellie", 1),
                new Pair<>("empty", 3)
        ), VillageGenerator.PlacementBehaviour.RIGID));
        put(PoolType.BUTCHER_ANIMAL, new Triplet<>(PoolType.EMPTY, Arrays.asList(
                new Pair<>("common/animals/cows_1", 3),
                new Pair<>("common/animals/pigs_1", 3),
                new Pair<>("common/animals/sheep_1", 1),
                new Pair<>("common/animals/sheep_2", 1)
        ), VillageGenerator.PlacementBehaviour.RIGID));
        put(PoolType.IRON_GOLEM, new Triplet<>(PoolType.EMPTY, Collections.singletonList(
                new Pair<>("common/iron_golem", 1)
        ), VillageGenerator.PlacementBehaviour.RIGID));
        put(PoolType.WELL_BOTTOM, new Triplet<>(PoolType.EMPTY, Collections.singletonList(
                new Pair<>("common/well_bottom", 1)
        ), VillageGenerator.PlacementBehaviour.RIGID));
        put(PoolType.EMPTY, new Triplet<>(PoolType.EMPTY,Collections.singletonList(
                new Pair<>("empty", 0)
        ), VillageGenerator.PlacementBehaviour.RIGID));
    }};
    }
