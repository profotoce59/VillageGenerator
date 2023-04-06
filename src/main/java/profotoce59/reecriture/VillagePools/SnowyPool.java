package profotoce59.reecriture.VillagePools;

import profotoce59.enumType.PoolType;
import com.seedfinding.mccore.util.data.Pair;
import com.seedfinding.mccore.util.data.Triplet;
import profotoce59.properties.VillageGenerator;

import java.util.*;

public interface SnowyPool {
    public static final EnumMap<PoolType, Triplet<PoolType, List<Pair<String, Integer>>, VillageGenerator.PlacementBehaviour>> VILLAGE_POOLS = new EnumMap<>(PoolType.class) {{
        put(PoolType.SNOWY_CENTER, new Triplet<>(PoolType.EMPTY, Arrays.asList(
                new Pair<>("snowy/town_centers/snowy_meeting_point_1", 100),
                new Pair<>("snowy/town_centers/snowy_meeting_point_2", 50),
                new Pair<>("snowy/town_centers/snowy_meeting_point_3", 150),
                new Pair<>("snowy/zombie/town_centers/snowy_meeting_point_1", 2),
                new Pair<>("snowy/zombie/town_centers/snowy_meeting_point_2", 1),
                new Pair<>("snowy/zombie/town_centers/snowy_meeting_point_3", 3)), VillageGenerator.PlacementBehaviour.RIGID));
         put(PoolType.SNOWY_STREET, new Triplet<>(PoolType.SNOWY_TERMINATOR, Arrays.asList(
            new Pair<>("snowy/streets/corner_01", 2),

            new Pair<>("snowy/streets/corner_02", 2),

            new Pair<>("snowy/streets/corner_03", 2),

            new Pair<>("snowy/streets/square_01", 2),

            new Pair<>("snowy/streets/straight_01", 4),

            new Pair<>("snowy/streets/straight_02", 4),

            new Pair<>("snowy/streets/straight_03", 4),

            new Pair<>("snowy/streets/straight_04", 7),

            new Pair<>("snowy/streets/straight_06", 4),

            new Pair<>("snowy/streets/straight_08", 4),

            new Pair<>("snowy/streets/crossroad_02", 1),

            new Pair<>("snowy/streets/crossroad_03", 2),

            new Pair<>("snowy/streets/crossroad_04", 2),

            new Pair<>("snowy/streets/crossroad_05", 2),

            new Pair<>("snowy/streets/crossroad_06", 2),

            new Pair<>("snowy/streets/turn_01", 3)), VillageGenerator.PlacementBehaviour.TERRAIN_MATCHING));
      put(PoolType.SNOWY_ZSTREET, new Triplet<>(PoolType.SNOWY_TERMINATOR, Arrays.asList(
            new Pair<>("snowy/zombie/streets/corner_01", 2),
            new Pair<>("snowy/zombie/streets/corner_02", 2),
            new Pair<>("snowy/zombie/streets/corner_03", 2),
            new Pair<>("snowy/zombie/streets/square_01", 2),
            new Pair<>("snowy/zombie/streets/straight_01", 4),
            new Pair<>("snowy/zombie/streets/straight_02", 4),
            new Pair<>("snowy/zombie/streets/straight_03", 4),
            new Pair<>("snowy/zombie/streets/straight_04", 7),
            new Pair<>("snowy/zombie/streets/straight_06", 4),
            new Pair<>("snowy/zombie/streets/straight_08", 4),
            new Pair<>("snowy/zombie/streets/crossroad_02", 1),
            new Pair<>("snowy/zombie/streets/crossroad_03", 2),
            new Pair<>("snowy/zombie/streets/crossroad_04", 2),
            new Pair<>("snowy/zombie/streets/crossroad_05", 2),
            new Pair<>("snowy/zombie/streets/crossroad_06", 2),
            new Pair<>("snowy/zombie/streets/turn_01", 3)), VillageGenerator.PlacementBehaviour.TERRAIN_MATCHING));
      put(PoolType.SNOWY_HOUSES, new Triplet<>(PoolType.SNOWY_TERMINATOR, Arrays.asList(
            new Pair<>("snowy/houses/snowy_small_house_1",2),
            new Pair<>("snowy/houses/snowy_small_house_2",2),
            new Pair<>("snowy/houses/snowy_small_house_3",2),
            new Pair<>("snowy/houses/snowy_small_house_4",3),
            new Pair<>("snowy/houses/snowy_small_house_5",2),
            new Pair<>("snowy/houses/snowy_small_house_6",2),
            new Pair<>("snowy/houses/snowy_small_house_7",2),
            new Pair<>("snowy/houses/snowy_small_house_8",2),
            new Pair<>("snowy/houses/snowy_medium_house_1",2),
            new Pair<>("snowy/houses/snowy_medium_house_2",2),
            new Pair<>("snowy/houses/snowy_medium_house_3",2),
            new Pair<>("snowy/houses/snowy_butchers_shop_1",2),
            new Pair<>("snowy/houses/snowy_butchers_shop_2",2),
            new Pair<>("snowy/houses/snowy_tool_smith_1",2),
            new Pair<>("snowy/houses/snowy_fletcher_house_1",2),
            new Pair<>("snowy/houses/snowy_shepherds_house_1",3),
            new Pair<>("snowy/houses/snowy_armorer_house_1",1),
            new Pair<>("snowy/houses/snowy_armorer_house_2",1),
            new Pair<>("snowy/houses/snowy_fisher_cottage",2),
            new Pair<>("snowy/houses/snowy_tannery_1",2),
            new Pair<>("snowy/houses/snowy_cartographer_house_1",2),
            new Pair<>("snowy/houses/snowy_library_1",2),
            new Pair<>("snowy/houses/snowy_masons_house_1",2),
            new Pair<>("snowy/houses/snowy_masons_house_2",2),
            new Pair<>("snowy/houses/snowy_weapon_smith_1",2),
            new Pair<>("snowy/houses/snowy_temple_1",2),
            new Pair<>("snowy/houses/snowy_farm_1", 3),
            new Pair<>("snowy/houses/snowy_farm_2", 3),
            new Pair<>("snowy/houses/snowy_animal_pen_1",2),
            new Pair<>("snowy/houses/snowy_animal_pen_2",2),
            new Pair<>("empty", 6)), VillageGenerator.PlacementBehaviour.RIGID));
      put (PoolType.SNOWY_ZHOUSES, new Triplet<>(PoolType.SNOWY_TERMINATOR, Arrays.asList(
            new Pair<>("snowy/zombie/houses/snowy_small_house_1", 2),
            new Pair<>("snowy/zombie/houses/snowy_small_house_2", 2),
            new Pair<>("snowy/zombie/houses/snowy_small_house_3", 2),
            new Pair<>("snowy/zombie/houses/snowy_small_house_4", 2),
            new Pair<>("snowy/zombie/houses/snowy_small_house_5", 2),
            new Pair<>("snowy/zombie/houses/snowy_small_house_6", 2),
            new Pair<>("snowy/zombie/houses/snowy_small_house_7", 2),
            new Pair<>("snowy/zombie/houses/snowy_small_house_8", 2),
            new Pair<>("snowy/zombie/houses/snowy_medium_house_1", 2),
            new Pair<>("snowy/zombie/houses/snowy_medium_house_2", 2),
            new Pair<>("snowy/zombie/houses/snowy_medium_house_3", 1),
            new Pair<>("snowy/houses/snowy_butchers_shop_1", 2),
            new Pair<>("snowy/houses/snowy_butchers_shop_2", 2),
            new Pair<>("snowy/houses/snowy_tool_smith_1", 2),
            new Pair<>("snowy/houses/snowy_fletcher_house_1", 2),
            new Pair<>("snowy/houses/snowy_shepherds_house_1", 2),
            new Pair<>("snowy/houses/snowy_armorer_house_1", 1),
            new Pair<>("snowy/houses/snowy_armorer_house_2", 1),
            new Pair<>("snowy/houses/snowy_fisher_cottage", 2),
            new Pair<>("snowy/houses/snowy_tannery_1", 2),
            new Pair<>("snowy/houses/snowy_cartographer_house_1", 2),
            new Pair<>("snowy/houses/snowy_library_1", 2),
            new Pair<>("snowy/houses/snowy_masons_house_1", 2),
            new Pair<>("snowy/houses/snowy_masons_house_2", 2),
            new Pair<>("snowy/houses/snowy_weapon_smith_1", 2),
            new Pair<>("snowy/houses/snowy_temple_1", 2),
            new Pair<>("snowy/houses/snowy_farm_1", 3),
            new Pair<>("snowy/houses/snowy_farm_2", 3),
            new Pair<>("snowy/houses/snowy_animal_pen_1", 2),
            new Pair<>("snowy/houses/snowy_animal_pen_2", 2),
            new Pair<>("empty", 6)), VillageGenerator.PlacementBehaviour.RIGID));
      put(PoolType.SNOWY_TERMINATOR, new Triplet<>(PoolType.EMPTY, Arrays.asList(
            new Pair<>("plains/terminators/terminator_01", 1),
            new Pair<>("plains/terminators/terminator_02", 1),
            new Pair<>("plains/terminators/terminator_03", 1),
            new Pair<>("plains/terminators/terminator_04", 1)), VillageGenerator.PlacementBehaviour.TERRAIN_MATCHING));
      put(PoolType.SNOWY_TREE, new Triplet<>(PoolType.EMPTY, Arrays.asList(
              new Pair<>("taiga/spruce", 1)), VillageGenerator.PlacementBehaviour.RIGID));
      put(PoolType.SNOWY_DECOR, new Triplet<>(PoolType.EMPTY, Arrays.asList(//5 block pile mais pas de snow ni pile ice ?
              new Pair<>("snowy/snowy_lamp_post_01",4),
              new Pair<>("snowy/snowy_lamp_post_02",4),
              new Pair<>("snowy/snowy_lamp_post_03",1),
              new Pair<>("taiga/spruce", 4),
              new Pair<>("snowy/pile_snow", 4), //here maybe to see
              new Pair<>("snowy/pile_ice", 1),
              new Pair<>("empty", 9)), VillageGenerator.PlacementBehaviour.RIGID));
      put(PoolType.SNOWY_ZDECOR, new Triplet<>(PoolType.EMPTY, Arrays.asList(
              new Pair<>("snowy/snowy_lamp_post_01",1),
              new Pair<>("snowy/snowy_lamp_post_02",1),
              new Pair<>("snowy/snowy_lamp_post_03",1),
              new Pair<>("taiga/spruce", 4),
              new Pair<>("snowy/pile_snow", 4), //here maybe to see
              new Pair<>("snowy/pile_ice", 4),
              new Pair<>("empty", 7)), VillageGenerator.PlacementBehaviour.RIGID));
      put(PoolType.SNOWY_VILLAGER, new Triplet<>(PoolType.EMPTY, Arrays.asList(
            new Pair<>("snowy/villagers/nitwit",1),
            new Pair<>("snowy/villagers/baby",1),
            new Pair<>("snowy/villagers/unemployed",10)), VillageGenerator.PlacementBehaviour.RIGID));
      put(PoolType.SNOWY_ZVILLAGER, new Triplet<>(PoolType.EMPTY, Arrays.asList(
            new Pair<>("snowy/zombie/villagers/nitwit",1),
            new Pair<>("snowy/zombie/villagers/unemployed",10)), VillageGenerator.PlacementBehaviour.RIGID));
      putAll(CommonPool.VILLAGE_POOLS);
}
};
}
