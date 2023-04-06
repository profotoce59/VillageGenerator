package profotoce59.reecriture.VillagePools;

import profotoce59.enumType.PoolType;
import com.seedfinding.mccore.util.data.Pair;
import com.seedfinding.mccore.util.data.Triplet;
import profotoce59.properties.VillageGenerator;

import java.util.*;

public interface TaigaPool {
    public static final EnumMap<PoolType, Triplet<PoolType, List<Pair<String, Integer>>, VillageGenerator.PlacementBehaviour>> VILLAGE_POOLS = new EnumMap<>(PoolType.class) {{

        put(PoolType.TAIGA_CENTER, new Triplet<>(PoolType.EMPTY, Arrays.asList(
 new Pair<>("taiga/town_centers/taiga_meeting_point_1", 49),
 new Pair<>("taiga/town_centers/taiga_meeting_point_2", 49),
 new Pair<>("taiga/zombie/town_centers/taiga_meeting_point_1", 1),
 new Pair<>("taiga/zombie/town_centers/taiga_meeting_point_2", 1)), VillageGenerator.PlacementBehaviour.RIGID));
    put(PoolType.TAIGA_STREET, new Triplet<>(PoolType.TAIGA_TERMINATOR, Arrays.asList(
 new Pair<>("taiga/streets/corner_01", 2), 
 new Pair<>("taiga/streets/corner_02", 2), 
 new Pair<>("taiga/streets/corner_03" ,2), 
 new Pair<>("taiga/streets/straight_01", 4), 
 new Pair<>("taiga/streets/straight_02", 4), 
 new Pair<>("taiga/streets/straight_03" ,4), 
 new Pair<>("taiga/streets/straight_04", 7), 
 new Pair<>("taiga/streets/straight_05", 7), 
 new Pair<>("taiga/streets/straight_06", 4), 
 new Pair<>("taiga/streets/crossroad_01", 1), 
 new Pair<>("taiga/streets/crossroad_02", 1), 
 new Pair<>("taiga/streets/crossroad_03", 2), 
 new Pair<>("taiga/streets/crossroad_04", 2), 
 new Pair<>("taiga/streets/crossroad_05", 2), 
 new Pair<>("taiga/streets/crossroad_06", 2), 
 new Pair<>("taiga/streets/turn_01", 3)), VillageGenerator.PlacementBehaviour.TERRAIN_MATCHING));
    put(PoolType.TAIGA_ZSTREET, new Triplet<>(PoolType.TAIGA_TERMINATOR, Arrays.asList(
 new Pair<>("taiga/zombie/streets/corner_01", 2), 
 new Pair<>("taiga/zombie/streets/corner_02", 2), 
 new Pair<>("taiga/zombie/streets/corner_03" ,2), 
 new Pair<>("taiga/zombie/streets/straight_01", 4), 
 new Pair<>("taiga/zombie/streets/straight_02" ,4), 
 new Pair<>("taiga/zombie/streets/straight_03", 4), 
 new Pair<>("taiga/zombie/streets/straight_04" ,7), 
 new Pair<>("taiga/zombie/streets/straight_05", 7), 
 new Pair<>("taiga/zombie/streets/straight_06" ,4), 
 new Pair<>("taiga/zombie/streets/crossroad_01", 1), 
 new Pair<>("taiga/zombie/streets/crossroad_02" ,1), 
 new Pair<>("taiga/zombie/streets/crossroad_03" ,2), 
 new Pair<>("taiga/zombie/streets/crossroad_04" ,2), 
 new Pair<>("taiga/zombie/streets/crossroad_05" ,2), 
 new Pair<>("taiga/zombie/streets/crossroad_06", 2), 
 new Pair<>("taiga/zombie/streets/turn_01", 3)), VillageGenerator.PlacementBehaviour.TERRAIN_MATCHING));
    put(PoolType.TAIGA_HOUSES, new Triplet<>(PoolType.TAIGA_TERMINATOR, Arrays.asList(
 new Pair<>("taiga/houses/taiga_small_house_1", 4), 
 new Pair<>("taiga/houses/taiga_small_house_2", 4), 
 new Pair<>("taiga/houses/taiga_small_house_3", 4), 
 new Pair<>("taiga/houses/taiga_small_house_4", 4), 
 new Pair<>("taiga/houses/taiga_small_house_5", 4), 
 new Pair<>("taiga/houses/taiga_medium_house_1", 2), 
 new Pair<>("taiga/houses/taiga_medium_house_2", 2), 
 new Pair<>("taiga/houses/taiga_medium_house_3", 2), 
 new Pair<>("taiga/houses/taiga_medium_house_4", 2), 
 new Pair<>("taiga/houses/taiga_butcher_shop_1", 2), 
 new Pair<>("taiga/houses/taiga_tool_smith_1", 2), 
 new Pair<>("taiga/houses/taiga_fletcher_house_1", 2), 
 new Pair<>("taiga/houses/taiga_shepherds_house_1", 2), 
 new Pair<>("taiga/houses/taiga_armorer_house_1", 1), 
 new Pair<>("taiga/houses/taiga_armorer_2", 1), 
 new Pair<>("taiga/houses/taiga_fisher_cottage_1", 3), 
 new Pair<>("taiga/houses/taiga_tannery_1", 2), 
 new Pair<>("taiga/houses/taiga_cartographer_house_1", 2), 
 new Pair<>("taiga/houses/taiga_library_1", 2), 
 new Pair<>("taiga/houses/taiga_masons_house_1", 2), 
 new Pair<>("taiga/houses/taiga_weaponsmith_1", 2), 
 new Pair<>("taiga/houses/taiga_weaponsmith_2", 2), 
 new Pair<>("taiga/houses/taiga_temple_1", 2), 
 new Pair<>("taiga/houses/taiga_large_farm_1",  6), 
 new Pair<>("taiga/houses/taiga_large_farm_2",  6), 
 new Pair<>("taiga/houses/taiga_small_farm_1", 1), 
 new Pair<>("taiga/houses/taiga_animal_pen_1", 2), 
 new Pair<>("empty", 6)), VillageGenerator.PlacementBehaviour.RIGID));//ct comme ca
    put(PoolType.TAIGA_ZHOUSES, new Triplet<>(PoolType.TAIGA_TERMINATOR, Arrays.asList(
 new Pair<>("taiga/zombie/houses/taiga_small_house_1",  4), 
 new Pair<>("taiga/zombie/houses/taiga_small_house_2",  4), 
 new Pair<>("taiga/zombie/houses/taiga_small_house_3",  4), 
 new Pair<>("taiga/zombie/houses/taiga_small_house_4",  4), 
 new Pair<>("taiga/zombie/houses/taiga_small_house_5",  4), 
 new Pair<>("taiga/zombie/houses/taiga_medium_house_1",  2), 
 new Pair<>("taiga/zombie/houses/taiga_medium_house_2",  2), 
 new Pair<>("taiga/zombie/houses/taiga_medium_house_3",  2), 
 new Pair<>("taiga/zombie/houses/taiga_medium_house_4",  2), 
 new Pair<>("taiga/houses/taiga_butcher_shop_1",  2), 
 new Pair<>("taiga/zombie/houses/taiga_tool_smith_1",  2), 
 new Pair<>("taiga/houses/taiga_fletcher_house_1",  2), 
 new Pair<>("taiga/zombie/houses/taiga_shepherds_house_1",  2), 
 new Pair<>("taiga/houses/taiga_armorer_house_1",  1), 
 new Pair<>("taiga/zombie/houses/taiga_fisher_cottage_1",  2), 
 new Pair<>("taiga/houses/taiga_tannery_1",  2), 
 new Pair<>("taiga/zombie/houses/taiga_cartographer_house_1",  2), 
 new Pair<>("taiga/zombie/houses/taiga_library_1",  2), 
 new Pair<>("taiga/houses/taiga_masons_house_1",  2), 
 new Pair<>("taiga/houses/taiga_weaponsmith_1",  2), 
 new Pair<>("taiga/zombie/houses/taiga_weaponsmith_2",  2), 
 new Pair<>("taiga/zombie/houses/taiga_temple_1",  2), 
 new Pair<>("taiga/houses/taiga_large_farm_1",  6), 
 new Pair<>("taiga/zombie/houses/taiga_large_farm_2",  6), 
 new Pair<>("taiga/houses/taiga_small_farm_1",  1), 
 new Pair<>("taiga/houses/taiga_animal_pen_1",  2), 
 new Pair<>("empty", 6)), VillageGenerator.PlacementBehaviour.RIGID));//not sure
    put(PoolType.TAIGA_TERMINATOR, new Triplet<>(PoolType.EMPTY, Arrays.asList(
 new Pair<>("plains/terminators/terminator_01", 1),
 new Pair<>("plains/terminators/terminator_02", 1),
 new Pair<>("plains/terminators/terminator_03", 1),
 new Pair<>("plains/terminators/terminator_04", 1)), VillageGenerator.PlacementBehaviour.TERRAIN_MATCHING));
    put(PoolType.TAIGA_DECOR, new Triplet<>(PoolType.EMPTY, Arrays.asList(
         new Pair<>("taiga/taiga_lamp_post_1", 10),
         new Pair<>("taiga/taiga_decoration_1", 4),
         new Pair<>("taiga/taiga_decoration_2", 1),
         new Pair<>("taiga/taiga_decoration_3", 1),
         new Pair<>("taiga/taiga_decoration_4", 1),
         new Pair<>("taiga/taiga_decoration_5", 2),
         new Pair<>("taiga/taiga_decoration_6", 1),
         new Pair<>("taiga/spruce", 4),
         new Pair<>("taiga/pine", 4),
         new Pair<>("taiga/pile_pumpkin", 2),
         new Pair<>("taiga/patch_taiga_grass", 4),
         new Pair<>("taiga/patch_berry_bush", 1),
         new Pair<>("empty", 4)), VillageGenerator.PlacementBehaviour.RIGID));
    put(PoolType.TAIGA_ZDECOR, new Triplet<>(PoolType.EMPTY, Arrays.asList(
            new Pair<>("taiga/taiga_decoration_1", 4),
            new Pair<>("taiga/taiga_decoration_2", 1),
            new Pair<>("taiga/taiga_decoration_3", 1),
            new Pair<>("taiga/taiga_decoration_4", 1),
            new Pair<>("taiga/spruce", 4),
            new Pair<>("taiga/pine", 4),
            new Pair<>("taiga/pile_pumpkin", 2),
            new Pair<>("taiga/patch_taiga_grass", 4),
            new Pair<>("taiga/patch_berry_bush", 1),
            new Pair<>("empty", 4)), VillageGenerator.PlacementBehaviour.RIGID));
    put(PoolType.TAIGA_VILLAGER, new Triplet<>(PoolType.EMPTY, Arrays.asList(
             new Pair<>("taiga/villagers/nitwit", 1),
             new Pair<>("taiga/villagers/baby", 1),
             new Pair<>("taiga/villagers/unemployed", 10)), VillageGenerator.PlacementBehaviour.RIGID));
    put(PoolType.TAIGA_ZVILLAGER, new Triplet<>(PoolType.EMPTY, Arrays.asList(
             new Pair<>("taiga/zombie/villagers/nitwit", 1),
             new Pair<>("taiga/zombie/villagers/unemployed", 10)), VillageGenerator.PlacementBehaviour.RIGID));
        putAll(CommonPool.VILLAGE_POOLS);


}};}

