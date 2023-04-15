package profotoce59.reecriture.VillagePools;

import profotoce59.enumType.PoolType;
import com.seedfinding.mccore.util.data.Pair;
import com.seedfinding.mccore.util.data.Triplet;
import profotoce59.properties.VillageGenerator;

import java.util.*;

public interface SavannaPool {
  public static final EnumMap<PoolType, Triplet<PoolType, List<Pair<String, Integer>>, VillageGenerator.PlacementBehaviour>> VILLAGE_POOLS = new EnumMap<>(PoolType.class) {{
    put(PoolType.SAVANNA_CENTER, new Triplet<>(PoolType.EMPTY, Arrays.asList(
              new Pair<>("savanna/town_centers/savanna_meeting_point_1", 100),
              new Pair<>("savanna/town_centers/savanna_meeting_point_2", 50),
              new Pair<>("savanna/town_centers/savanna_meeting_point_3", 150),
              new Pair<>("savanna/town_centers/savanna_meeting_point_4", 150),
              new Pair<>("savanna/zombie/town_centers/savanna_meeting_point_1",2),
              new Pair<>("savanna/zombie/town_centers/savanna_meeting_point_2",  1),
              new Pair<>("savanna/zombie/town_centers/savanna_meeting_point_3", 3),
              new Pair<>("savanna/zombie/town_centers/savanna_meeting_point_4", 3)), VillageGenerator.PlacementBehaviour.RIGID));
        put(PoolType.SAVANNA_STREET, new Triplet<>(PoolType.SAVANNA_TERMINATOR, Arrays.asList(
            new Pair<>("savanna/streets/corner_01", 2),
            new Pair<>("savanna/streets/corner_03", 2),
            new Pair<>("savanna/streets/straight_02", 4),
            new Pair<>("savanna/streets/straight_04", 7),
            new Pair<>("savanna/streets/straight_05", 3),
            new Pair<>("savanna/streets/straight_06", 4),
            new Pair<>("savanna/streets/straight_08", 4),
            new Pair<>("savanna/streets/straight_09", 4),
            new Pair<>("savanna/streets/straight_10", 4),
            new Pair<>("savanna/streets/straight_11", 4),
            new Pair<>("savanna/streets/crossroad_02", 1),
            new Pair<>("savanna/streets/crossroad_03", 2),
            new Pair<>("savanna/streets/crossroad_04", 2),
            new Pair<>("savanna/streets/crossroad_05", 2),
            new Pair<>("savanna/streets/crossroad_06", 2),
            new Pair<>("savanna/streets/crossroad_07", 2),
            new Pair<>("savanna/streets/split_01", 2),
            new Pair<>("savanna/streets/split_02", 2),
            new Pair<>("savanna/streets/turn_01", 3)), VillageGenerator.PlacementBehaviour.TERRAIN_MATCHING));
      put(PoolType.SAVANNA_ZSTREET, new Triplet<>(PoolType.SAVANNA_ZTERMINATOR, Arrays.asList(//ressourceLocqtion weird ?
            new Pair<>("savanna/zombie/streets/corner_01", 2),
            new Pair<>("savanna/zombie/streets/corner_03", 2),
            new Pair<>("savanna/zombie/streets/straight_02", 4),
            new Pair<>("savanna/zombie/streets/straight_04", 7),
            new Pair<>("savanna/zombie/streets/straight_05", 3),
            new Pair<>("savanna/zombie/streets/straight_06", 4),
            new Pair<>("savanna/zombie/streets/straight_08", 4),
            new Pair<>("savanna/zombie/streets/straight_09", 4),
            new Pair<>("savanna/zombie/streets/straight_10", 4),
            new Pair<>("savanna/zombie/streets/straight_11", 4),
            new Pair<>("savanna/zombie/streets/crossroad_02", 1),
            new Pair<>("savanna/zombie/streets/crossroad_03", 2),
            new Pair<>("savanna/zombie/streets/crossroad_04", 2),
            new Pair<>("savanna/zombie/streets/crossroad_05", 2),
            new Pair<>("savanna/zombie/streets/crossroad_06", 2),
            new Pair<>("savanna/zombie/streets/crossroad_07", 2),
            new Pair<>("savanna/zombie/streets/split_01", 2),
            new Pair<>("savanna/zombie/streets/split_02", 2),
            new Pair<>("savanna/zombie/streets/turn_01", 3)), VillageGenerator.PlacementBehaviour.TERRAIN_MATCHING));
      put(PoolType.SAVANNA_HOUSES, new Triplet<>(PoolType.SAVANNA_TERMINATOR, Arrays.asList(
            new Pair<>("savanna/houses/savanna_small_house_1", 2),
            new Pair<>("savanna/houses/savanna_small_house_2", 2),
            new Pair<>("savanna/houses/savanna_small_house_3", 2),
            new Pair<>("savanna/houses/savanna_small_house_4", 2),
            new Pair<>("savanna/houses/savanna_small_house_5", 2),
            new Pair<>("savanna/houses/savanna_small_house_6", 2),
            new Pair<>("savanna/houses/savanna_small_house_7", 2),
            new Pair<>("savanna/houses/savanna_small_house_8", 2),
            new Pair<>("savanna/houses/savanna_medium_house_1", 2),
            new Pair<>("savanna/houses/savanna_medium_house_2", 2),
            new Pair<>("savanna/houses/savanna_butchers_shop_1", 2),
            new Pair<>("savanna/houses/savanna_butchers_shop_2", 2),
            new Pair<>("savanna/houses/savanna_tool_smith_1", 2),
            new Pair<>("savanna/houses/savanna_fletcher_house_1", 2),
            new Pair<>("savanna/houses/savanna_shepherd_1", 7),
            new Pair<>("savanna/houses/savanna_armorer_1", 1),
            new Pair<>("savanna/houses/savanna_fisher_cottage_1", 3),
            new Pair<>("savanna/houses/savanna_tannery_1", 2),
            new Pair<>("savanna/houses/savanna_cartographer_1", 2),
            new Pair<>("savanna/houses/savanna_library_1", 2),
            new Pair<>("savanna/houses/savanna_mason_1", 2),
            new Pair<>("savanna/houses/savanna_weaponsmith_1", 2),
            new Pair<>("savanna/houses/savanna_weaponsmith_2", 2),
            new Pair<>("savanna/houses/savanna_temple_1", 2),
            new Pair<>("savanna/houses/savanna_temple_2", 3),
            new Pair<>("savanna/houses/savanna_large_farm_1", 4),
            new Pair<>("savanna/houses/savanna_large_farm_2", 6),
            new Pair<>("savanna/houses/savanna_small_farm", 4),
            new Pair<>("savanna/houses/savanna_animal_pen_1", 2),
            new Pair<>("savanna/houses/savanna_animal_pen_2", 2),
            new Pair<>("savanna/houses/savanna_animal_pen_3", 2),
            new Pair<>("empty", 5)), VillageGenerator.PlacementBehaviour.RIGID));
      put(PoolType.SAVANNA_ZHOUSES, new Triplet<>(PoolType.SAVANNA_ZTERMINATOR, Arrays.asList(
            new Pair<>("savanna/zombie/houses/savanna_small_house_1", 2),
            new Pair<>("savanna/zombie/houses/savanna_small_house_2", 2),
            new Pair<>("savanna/zombie/houses/savanna_small_house_3", 2),
            new Pair<>("savanna/zombie/houses/savanna_small_house_4", 2),
            new Pair<>("savanna/zombie/houses/savanna_small_house_5", 2),
            new Pair<>("savanna/zombie/houses/savanna_small_house_6", 2),
            new Pair<>("savanna/zombie/houses/savanna_small_house_7", 2),
            new Pair<>("savanna/zombie/houses/savanna_small_house_8", 2),
            new Pair<>("savanna/zombie/houses/savanna_medium_house_1", 2),
            new Pair<>("savanna/zombie/houses/savanna_medium_house_2", 2),
            new Pair<>("savanna/houses/savanna_butchers_shop_1", 2),
            new Pair<>("savanna/houses/savanna_butchers_shop_2", 2),
            new Pair<>("savanna/houses/savanna_tool_smith_1", 2),
            new Pair<>("savanna/houses/savanna_fletcher_house_1", 2),
            new Pair<>("savanna/houses/savanna_shepherd_1", 2),
            new Pair<>("savanna/houses/savanna_armorer_1", 1),
            new Pair<>("savanna/houses/savanna_fisher_cottage_1", 2),
            new Pair<>("savanna/houses/savanna_tannery_1", 2),
            new Pair<>("savanna/houses/savanna_cartographer_1", 2),
            new Pair<>("savanna/houses/savanna_library_1", 2),
            new Pair<>("savanna/houses/savanna_mason_1", 2),
            new Pair<>("savanna/houses/savanna_weaponsmith_1", 2),
            new Pair<>("savanna/houses/savanna_weaponsmith_2", 2),
            new Pair<>("savanna/houses/savanna_temple_1", 1),
            new Pair<>("savanna/houses/savanna_temple_2", 3),
            new Pair<>("savanna/houses/savanna_large_farm_1", 4),
            new Pair<>("savanna/zombie/houses/savanna_large_farm_2", 4),
            new Pair<>("savanna/houses/savanna_small_farm", 4),
            new Pair<>("savanna/houses/savanna_animal_pen_1", 2),
            new Pair<>("savanna/zombie/houses/savanna_animal_pen_2", 2),
            new Pair<>("savanna/zombie/houses/savanna_animal_pen_3", 2),
            new Pair<>("empty", 5)), VillageGenerator.PlacementBehaviour.RIGID));
      put(PoolType.SAVANNA_TERMINATOR, new Triplet<>(PoolType.EMPTY, Arrays.asList(
            new Pair<>("plains/terminators/terminator_01", 1),
            new Pair<>("plains/terminators/terminator_02", 1),
            new Pair<>("plains/terminators/terminator_03", 1),
            new Pair<>("plains/terminators/terminator_04", 1),
            new Pair<>("savanna/terminators/terminator_05", 1)), VillageGenerator.PlacementBehaviour.TERRAIN_MATCHING));
      put(PoolType.SAVANNA_ZTERMINATOR, new Triplet<>(PoolType.EMPTY, Arrays.asList(
            new Pair<>("plains/terminators/terminator_01", 1),
            new Pair<>("plains/terminators/terminator_02", 1),
            new Pair<>("plains/terminators/terminator_03", 1),
            new Pair<>("plains/terminators/terminator_04", 1),
            new Pair<>("savanna/zombie/terminators/terminator_05", 1)), VillageGenerator.PlacementBehaviour.TERRAIN_MATCHING));
      put(PoolType.SAVANNA_TREE, new Triplet<>(PoolType.EMPTY, Arrays.asList(
            new Pair<>("savanna/acacia", 1)), VillageGenerator.PlacementBehaviour.RIGID));
      put(PoolType.SAVANNA_DECOR, new Triplet<>(PoolType.EMPTY, Arrays.asList(
            new Pair<>("savanna/savanna_lamp_post_01", 4),
            new Pair<>("savanna/acacia", 4),
            new Pair<>("pile_hay", 4),
            new Pair<>("pile_melon", 1),
            new Pair<>("empty", 4)), VillageGenerator.PlacementBehaviour.RIGID));
      put(PoolType.SAVANNA_ZDECOR, new Triplet<>(PoolType.EMPTY, Arrays.asList(
            new Pair<>("savanna/savanna_lamp_post_01", 4),
            new Pair<>("savanna/acacia", 4),
            new Pair<>("pile_hay", 4),
            new Pair<>("pile_melon", 1),
            new Pair<>("empty", 4)), VillageGenerator.PlacementBehaviour.RIGID));
      put(PoolType.SAVANNA_VILLAGER, new Triplet<>(PoolType.EMPTY, Arrays.asList(
            new Pair<>("savanna/villagers/nitwit", 1),
            new Pair<>("savanna/villagers/baby", 1),
            new Pair<>("savanna/villagers/unemployed", 10)), VillageGenerator.PlacementBehaviour.RIGID));
      put(PoolType.SAVANNA_ZVILLAGER, new Triplet<>(PoolType.EMPTY, Arrays.asList(
            new Pair<>("savanna/zombie/villagers/nitwit", 1),
            new Pair<>("savanna/zombie/villagers/unemployed", 10)), VillageGenerator.PlacementBehaviour.RIGID));
      putAll(CommonPool.VILLAGE_POOLS);
    }};}
