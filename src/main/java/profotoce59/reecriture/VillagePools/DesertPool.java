package profotoce59.reecriture.VillagePools;

import com.seedfinding.mccore.util.data.Pair;
import com.seedfinding.mccore.util.data.Triplet;
import profotoce59.enumType.PoolType;
import profotoce59.properties.VillageGenerator;

import java.util.*;

public interface DesertPool {
    public static final EnumMap<PoolType, Triplet<PoolType, List<Pair<String, Integer>>, VillageGenerator.PlacementBehaviour>> VILLAGE_POOLS = new EnumMap<>(PoolType.class) {{
            put(PoolType.DESERT_CENTER, new Triplet<>(PoolType.EMPTY, Arrays.asList(
                    new Pair<>("desert/town_centers/desert_meeting_point_1", 98),
                    new Pair<>("desert/town_centers/desert_meeting_point_2", 98),
                    new Pair<>("desert/town_centers/desert_meeting_point_3", 49),
                    new Pair<>("desert/zombie/town_centers/desert_meeting_point_1", 2),
                    new Pair<>("desert/zombie/town_centers/desert_meeting_point_2", 2),
                    new Pair<>("desert/zombie/town_centers/desert_meeting_point_3", 1)
            ), VillageGenerator.PlacementBehaviour.RIGID));
            put(PoolType.DESERT_STREET, new Triplet<>(PoolType.DESERT_TERMINATOR, Arrays.asList(
                    new Pair<>("desert/streets/corner_01", 3),
                    new Pair<>("desert/streets/corner_02", 3),
                    new Pair<>("desert/streets/straight_01", 4),
                    new Pair<>("desert/streets/straight_02", 4),
                    new Pair<>("desert/streets/straight_03", 3),
                    new Pair<>("desert/streets/crossroad_01", 3),
                    new Pair<>("desert/streets/crossroad_02", 3),
                    new Pair<>("desert/streets/crossroad_03", 3),
                    new Pair<>("desert/streets/square_01", 3),
                    new Pair<>("desert/streets/square_02", 3),
                    new Pair<>("desert/streets/turn_01", 3)
            ), VillageGenerator.PlacementBehaviour.TERRAIN_MATCHING));
            put(PoolType.DESERT_ZSTREET, new Triplet<>(PoolType.DESERT_ZTERMINATOR, Arrays.asList(
                    new Pair<>("desert/zombie/streets/corner_01", 3),
                    new Pair<>("desert/zombie/streets/corner_02", 3),
                    new Pair<>("desert/zombie/streets/straight_01", 4),
                    new Pair<>("desert/zombie/streets/straight_02", 4),
                    new Pair<>("desert/zombie/streets/straight_03", 3),
                    new Pair<>("desert/zombie/streets/crossroad_01", 3),
                    new Pair<>("desert/zombie/streets/crossroad_02", 3),
                    new Pair<>("desert/zombie/streets/crossroad_03", 3),
                    new Pair<>("desert/zombie/streets/square_01", 3),
                    new Pair<>("desert/zombie/streets/square_02", 3),
                    new Pair<>("desert/zombie/streets/turn_01", 3)
            ), VillageGenerator.PlacementBehaviour.TERRAIN_MATCHING));
            put(PoolType.DESERT_HOUSES, new Triplet<>(PoolType.DESERT_TERMINATOR, Arrays.asList(
                    new Pair<>("desert/houses/desert_small_house_1", 2),
                    new Pair<>("desert/houses/desert_small_house_2", 2),
                    new Pair<>("desert/houses/desert_small_house_3", 2),
                    new Pair<>("desert/houses/desert_small_house_4", 2),
                    new Pair<>("desert/houses/desert_small_house_5", 2),
                    new Pair<>("desert/houses/desert_small_house_6", 1),
                    new Pair<>("desert/houses/desert_small_house_7", 2),
                    new Pair<>("desert/houses/desert_small_house_8", 2),
                    new Pair<>("desert/houses/desert_medium_house_1", 2),
                    new Pair<>("desert/houses/desert_medium_house_2", 2),
                    new Pair<>("desert/houses/desert_butcher_shop_1", 2),
                    new Pair<>("desert/houses/desert_tool_smith_1", 2),
                    new Pair<>("desert/houses/desert_fletcher_house_1", 2),
                    new Pair<>("desert/houses/desert_shepherd_house_1", 2),
                    new Pair<>("desert/houses/desert_armorer_1", 1),
                    new Pair<>("desert/houses/desert_fisher_1", 2),
                    new Pair<>("desert/houses/desert_tannery_1", 2),
                    new Pair<>("desert/houses/desert_cartographer_house_1", 2),
                    new Pair<>("desert/houses/desert_library_1", 2),
                    new Pair<>("desert/houses/desert_mason_1", 2),
                    new Pair<>("desert/houses/desert_weaponsmith_1", 2),
                    new Pair<>("desert/houses/desert_temple_1", 2),
                    new Pair<>("desert/houses/desert_temple_2", 2),
                    new Pair<>("desert/houses/desert_large_farm_1", 11),
                    new Pair<>("desert/houses/desert_farm_1", 4),
                    new Pair<>("desert/houses/desert_farm_2", 4),
                    new Pair<>("desert/houses/desert_animal_pen_1", 2),
                    new Pair<>("desert/houses/desert_animal_pen_2", 2),
                    new Pair<>("empty", 5)
            ), VillageGenerator.PlacementBehaviour.RIGID));
            put(PoolType.DESERT_ZHOUSES, new Triplet<>(PoolType.DESERT_ZTERMINATOR, Arrays.asList(
                    new Pair<>("desert/zombie/houses/desert_small_house_1", 2),
                    new Pair<>("desert/zombie/houses/desert_small_house_2", 2),
                    new Pair<>("desert/zombie/houses/desert_small_house_3", 2),
                    new Pair<>("desert/zombie/houses/desert_small_house_4", 2),
                    new Pair<>("desert/zombie/houses/desert_small_house_5", 2),
                    new Pair<>("desert/zombie/houses/desert_small_house_6", 1),
                    new Pair<>("desert/zombie/houses/desert_small_house_7", 2),
                    new Pair<>("desert/zombie/houses/desert_small_house_8", 2),
                    new Pair<>("desert/zombie/houses/desert_medium_house_1", 2),
                    new Pair<>("desert/zombie/houses/desert_medium_house_2", 2),
                    new Pair<>("desert/houses/desert_butcher_shop_1", 2),
                    new Pair<>("desert/houses/desert_tool_smith_1", 2),
                    new Pair<>("desert/houses/desert_fletcher_house_1", 2),
                    new Pair<>("desert/houses/desert_shepherd_house_1", 2),
                    new Pair<>("desert/houses/desert_armorer_1", 1),
                    new Pair<>("desert/houses/desert_fisher_1", 2),
                    new Pair<>("desert/houses/desert_tannery_1", 2),
                    new Pair<>("desert/houses/desert_cartographer_house_1", 2),
                    new Pair<>("desert/houses/desert_library_1", 2),
                    new Pair<>("desert/houses/desert_mason_1", 2),
                    new Pair<>("desert/houses/desert_weaponsmith_1", 2),
                    new Pair<>("desert/houses/desert_temple_1", 2),
                    new Pair<>("desert/houses/desert_temple_2", 2),
                    new Pair<>("desert/houses/desert_large_farm_1", 7),
                    new Pair<>("desert/houses/desert_farm_1", 4),
                    new Pair<>("desert/houses/desert_farm_2", 4),
                    new Pair<>("desert/houses/desert_animal_pen_1", 2),
                    new Pair<>("desert/houses/desert_animal_pen_2", 2),
                    new Pair<>("empty", 5)
            ), VillageGenerator.PlacementBehaviour.RIGID));
            put(PoolType.DESERT_TERMINATOR, new Triplet<>(PoolType.EMPTY, Arrays.asList(
                    new Pair<>("desert/terminators/terminator_01", 1),
                    new Pair<>("desert/terminators/terminator_02", 1)
            ), VillageGenerator.PlacementBehaviour.TERRAIN_MATCHING));
            put(PoolType.DESERT_ZTERMINATOR, new Triplet<>(PoolType.EMPTY, Arrays.asList(
                    new Pair<>("desert/terminators/terminator_01", 1),
                    new Pair<>("desert/zombie/terminators/terminator_02", 1)
            ), VillageGenerator.PlacementBehaviour.TERRAIN_MATCHING));
            put(PoolType.DESERT_DECOR, new Triplet<>(PoolType.EMPTY, Arrays.asList(
                    new Pair<>("desert/desert_lamp_1", 10),
                    new Pair<>("patch_cactus", 4),
                    new Pair<>("pile_hay", 4),
                    new Pair<>("empty", 10)
            ), VillageGenerator.PlacementBehaviour.RIGID));
            put(PoolType.DESERT_ZDECOR, new Triplet<>(PoolType.EMPTY, Arrays.asList(
                    new Pair<>("desert/desert_lamp_1", 10),
                    new Pair<>("patch_cactus", 4),
                    new Pair<>("pile_hay", 4),
                    new Pair<>("empty", 10)
            ), VillageGenerator.PlacementBehaviour.RIGID));
            put(PoolType.DESERT_VILLAGER, new Triplet<>(PoolType.EMPTY, Arrays.asList(
                    new Pair<>("desert/villagers/nitwit", 1),
                    new Pair<>("desert/villagers/baby", 1),
                    new Pair<>("desert/villagers/unemployed", 10)
            ), VillageGenerator.PlacementBehaviour.RIGID));
            put(PoolType.DESERT_ZVILLAGER, new Triplet<>(PoolType.EMPTY, Arrays.asList(
                    new Pair<>("desert/zombie/villagers/nitwit", 1),
                    new Pair<>("desert/zombie/villagers/unemployed", 10)
            ), VillageGenerator.PlacementBehaviour.RIGID));
            putAll(CommonPool.VILLAGE_POOLS);
        }};
    }
