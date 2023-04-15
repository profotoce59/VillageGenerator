package profotoce59.reecriture.VillagePools;

import profotoce59.enumType.PoolType;
import com.seedfinding.mccore.util.data.Pair;
import com.seedfinding.mccore.util.data.Triplet;
import profotoce59.properties.VillageGenerator;

import java.util.*;

public interface PlainPool {


    public static final EnumMap<PoolType, Triplet<PoolType, List<Pair<String, Integer>>, VillageGenerator.PlacementBehaviour>> VILLAGE_POOLS = new EnumMap<>(PoolType.class) {{

        put(PoolType.PLAIN_CENTER, new Triplet<>(PoolType.EMPTY, Arrays.asList(
                new Pair<>("plains/town_centers/plains_fountain_01", 50),
                new Pair<>("plains/town_centers/plains_meeting_point_1",  50),
                new Pair<>("plains/town_centers/plains_meeting_point_2", 50),
                new Pair<>("plains/town_centers/plains_meeting_point_3",  50),
                new Pair<>("plains/zombie/town_centers/plains_fountain_01",  1),
                new Pair<>("plains/zombie/town_centers/plains_meeting_point_1",  1),
                new Pair<>("plains/zombie/town_centers/plains_meeting_point_2",  1),
                new Pair<>("plains/zombie/town_centers/plains_meeting_point_3",  1)
                ), VillageGenerator.PlacementBehaviour.RIGID));

        put(PoolType.PLAIN_STREET, new Triplet<>(PoolType.PLAIN_TERMINATOR, Arrays.asList(
            new Pair<>("plains/streets/corner_01", 2),
                new Pair<>("plains/streets/corner_02", 2),
                        new Pair<>("plains/streets/corner_03", 2),
                        new Pair<>("plains/streets/straight_01", 4),
                        new Pair<>("plains/streets/straight_02", 4),
                        new Pair<>("plains/streets/straight_03", 7),
                        new Pair<>("plains/streets/straight_04", 7),
                        new Pair<>("plains/streets/straight_05", 3),
                        new Pair<>("plains/streets/straight_06", 4),
                        new Pair<>("plains/streets/crossroad_01", 2),
                        new Pair<>("plains/streets/crossroad_02", 1),
                        new Pair<>("plains/streets/crossroad_03", 2),
                        new Pair<>("plains/streets/crossroad_04", 2),
                        new Pair<>("plains/streets/crossroad_05", 2),
                        new Pair<>("plains/streets/crossroad_06", 2),
                        new Pair<>("plains/streets/turn_01", 3)
                        ), VillageGenerator.PlacementBehaviour.TERRAIN_MATCHING));
    put(PoolType.PLAIN_ZSTREET, new Triplet<>(PoolType.PLAIN_TERMINATOR, Arrays.asList(
            new Pair<>("plains/zombie/streets/corner_01", 2),
                new Pair<>("plains/zombie/streets/corner_02", 2),
                        new Pair<>("plains/zombie/streets/corner_03", 2),
                        new Pair<>("plains/zombie/streets/straight_01", 4),
                        new Pair<>("plains/zombie/streets/straight_02", 4),
                        new Pair<>("plains/zombie/streets/straight_03", 7),
                        new Pair<>("plains/zombie/streets/straight_04", 7),
                        new Pair<>("plains/zombie/streets/straight_05", 3),
                        new Pair<>("plains/zombie/streets/straight_06", 4),
                        new Pair<>("plains/zombie/streets/crossroad_01", 2),
                        new Pair<>("plains/zombie/streets/crossroad_02", 1),
                        new Pair<>("plains/zombie/streets/crossroad_03", 2),
                        new Pair<>("plains/zombie/streets/crossroad_04", 2),
                        new Pair<>("plains/zombie/streets/crossroad_05", 2),
                        new Pair<>("plains/zombie/streets/crossroad_06", 2),
                        new Pair<>("plains/zombie/streets/turn_01", 3)
                        ), VillageGenerator.PlacementBehaviour.TERRAIN_MATCHING));
    put(PoolType.PLAIN_ZHOUSES, new Triplet<>(PoolType.PLAIN_TERMINATOR, Arrays.asList(
            new Pair<>("plains/zombie/houses/plains_small_house_1", 2),
                new Pair<>("plains/zombie/houses/plains_small_house_2", 2),
                        new Pair<>("plains/zombie/houses/plains_small_house_3", 2),
                        new Pair<>("plains/zombie/houses/plains_small_house_4", 2),
                        new Pair<>("plains/zombie/houses/plains_small_house_5", 2),
                        new Pair<>("plains/zombie/houses/plains_small_house_6", 1),
                        new Pair<>("plains/zombie/houses/plains_small_house_7", 2),
                        new Pair<>("plains/zombie/houses/plains_small_house_8", 2),
                        new Pair<>("plains/zombie/houses/plains_medium_house_1", 2),
                        new Pair<>("plains/zombie/houses/plains_medium_house_2", 2),
                        new Pair<>("plains/zombie/houses/plains_big_house_1", 2),
                        new Pair<>("plains/houses/plains_butcher_shop_1", 2),
                        new Pair<>("plains/zombie/houses/plains_butcher_shop_2", 2),
                        new Pair<>("plains/houses/plains_tool_smith_1", 2),
                        new Pair<>("plains/zombie/houses/plains_fletcher_house_1", 2),
                        new Pair<>("plains/zombie/houses/plains_shepherds_house_1", 2),
                        new Pair<>("plains/houses/plains_armorer_house_1", 2),
                        new Pair<>("plains/houses/plains_fisher_cottage_1", 2),
                        new Pair<>("plains/houses/plains_tannery_1", 2),
                        new Pair<>("plains/houses/plains_cartographer_1", 1),
                        new Pair<>("plains/houses/plains_library_1", 3),
                        new Pair<>("plains/houses/plains_library_2", 1),
                        new Pair<>("plains/houses/plains_masons_house_1", 2),
                        new Pair<>("plains/houses/plains_weaponsmith_1", 2),
                        new Pair<>("plains/houses/plains_temple_3", 2),
                        new Pair<>("plains/houses/plains_temple_4", 2),
                        new Pair<>("plains/zombie/houses/plains_stable_1", 2),
                        new Pair<>("plains/houses/plains_stable_2", 2),
                        new Pair<>("plains/houses/plains_large_farm_1", 4),
                        new Pair<>("plains/houses/plains_small_farm_1", 4),
                        new Pair<>("plains/houses/plains_animal_pen_1", 1),
                        new Pair<>("plains/houses/plains_animal_pen_2", 1),
                        new Pair<>("plains/zombie/houses/plains_animal_pen_3", 5),
                        new Pair<>("plains/zombie/houses/plains_meeting_point_4", 3),
                        new Pair<>("plains/zombie/houses/plains_meeting_point_5", 1),
                        new Pair<>("empty", 10)
                        ), VillageGenerator.PlacementBehaviour.RIGID));
    put(PoolType.PLAIN_HOUSES, new Triplet<>(PoolType.PLAIN_TERMINATOR, Arrays.asList(
            new Pair<>("plains/houses/plains_small_house_1", 2),
                new Pair<>("plains/houses/plains_small_house_2", 2),
                        new Pair<>("plains/houses/plains_small_house_3", 2),
                        new Pair<>("plains/houses/plains_small_house_4", 2),
                        new Pair<>("plains/houses/plains_small_house_5", 2),
                        new Pair<>("plains/houses/plains_small_house_6", 1),
                        new Pair<>("plains/houses/plains_small_house_7", 2),
                        new Pair<>("plains/houses/plains_small_house_8", 3),
                        new Pair<>("plains/houses/plains_medium_house_1", 2),
                        new Pair<>("plains/houses/plains_medium_house_2", 2),
                        new Pair<>("plains/houses/plains_big_house_1", 2),
                        new Pair<>("plains/houses/plains_butcher_shop_1", 2),
                        new Pair<>("plains/houses/plains_butcher_shop_2", 2),
                        new Pair<>("plains/houses/plains_tool_smith_1", 2),
                        new Pair<>("plains/houses/plains_fletcher_house_1", 2),
                        new Pair<>("plains/houses/plains_shepherds_house_1", 2),
                        new Pair<>("plains/houses/plains_armorer_house_1", 2),
                        new Pair<>("plains/houses/plains_fisher_cottage_1", 2),
                        new Pair<>("plains/houses/plains_tannery_1", 2),
                        new Pair<>("plains/houses/plains_cartographer_1", 1),
                        new Pair<>("plains/houses/plains_library_1", 5),
                        new Pair<>("plains/houses/plains_library_2", 1),
                        new Pair<>("plains/houses/plains_masons_house_1", 2),
                        new Pair<>("plains/houses/plains_weaponsmith_1", 2),
                        new Pair<>("plains/houses/plains_temple_3", 2),
                        new Pair<>("plains/houses/plains_temple_4", 2),
                        new Pair<>("plains/houses/plains_stable_1", 2),
                        new Pair<>("plains/houses/plains_stable_2", 2),
                        new Pair<>("plains/houses/plains_large_farm_1", 4),
                        new Pair<>("plains/houses/plains_small_farm_1", 4),
                        new Pair<>("plains/houses/plains_animal_pen_1", 1),
                        new Pair<>("plains/houses/plains_animal_pen_2", 1),
                        new Pair<>("plains/houses/plains_animal_pen_3", 5),
                        new Pair<>("plains/houses/plains_accessory_1", 1),
                        new Pair<>("plains/houses/plains_meeting_point_4", 3),
                        new Pair<>("plains/houses/plains_meeting_point_5", 1),
                        new Pair<>("empty", 10)
                        ), VillageGenerator.PlacementBehaviour.RIGID));
    put(PoolType.PLAIN_TERMINATOR, new Triplet<>(PoolType.EMPTY, Arrays.asList(
            new Pair<>("plains/terminators/terminator_01", 1),
                new Pair<>("plains/terminators/terminator_02", 1),
                        new Pair<>("plains/terminators/terminator_03", 1),
                        new Pair<>("plains/terminators/terminator_04", 1)
                        ), VillageGenerator.PlacementBehaviour.TERRAIN_MATCHING));
    put(PoolType.PLAIN_TREE, new Triplet<>(PoolType.EMPTY, Collections.singletonList(
            new Pair<>("oak", 1)
        ), VillageGenerator.PlacementBehaviour.RIGID));
    put(PoolType.PLAIN_DECOR, new Triplet<>(PoolType.EMPTY, Arrays.asList(
            new Pair<>("plains/plains_lamp_1", 2),
                new Pair<>("oak", 1),
                        new Pair<>("flower_plain", 1),
                        new Pair<>("pile_hay", 1),
                        new Pair<>("empty", 2)
                        ), VillageGenerator.PlacementBehaviour.RIGID));
    put(PoolType.PLAIN_ZDECOR, new Triplet<>(PoolType.EMPTY, Arrays.asList(
            new Pair<>("plains/plains_lamp_1", 1),
                new Pair<>("oak", 1),
                        new Pair<>("flower_plain", 1),
                        new Pair<>("pile_hay", 1),
                        new Pair<>("empty", 2)
                        ), VillageGenerator.PlacementBehaviour.RIGID));
    put(PoolType.PLAIN_VILLAGER, new Triplet<>(PoolType.EMPTY, Arrays.asList(
            new Pair<>("plains/villagers/nitwit", 1),
                new Pair<>("plains/villagers/baby", 1),
                        new Pair<>("plains/villagers/unemployed", 10)
                        ), VillageGenerator.PlacementBehaviour.RIGID));
    put(PoolType.PLAIN_ZVILLAGER, new Triplet<>(PoolType.EMPTY, Arrays.asList(
            new Pair<>("plains/zombie/villagers/nitwit", 1),
                new Pair<>("plains/zombie/villagers/unemployed", 10)
                        ), VillageGenerator.PlacementBehaviour.RIGID));
    putAll(CommonPool.VILLAGE_POOLS);

}};}
