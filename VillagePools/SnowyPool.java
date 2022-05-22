package reecriture.VillagePools;

import kaptainwutax.mcutils.util.data.Pair;
import kaptainwutax.mcutils.util.data.Triplet;
import properties.VillageGenerator;

import java.util.*;

public interface SnowyPool {
    public static final Map<String, Triplet<String, List<Pair<String, Integer>>, VillageGenerator.PlacementBehaviour>> VILLAGE_POOLS = new HashMap<String, Triplet<String, List<Pair<String, Integer>>, VillageGenerator.PlacementBehaviour>>() {{
        put("snowy/town_centers", new Triplet<>("empty", Arrays.asList(
                new Pair<>("snowy/town_centers/snowy_meeting_point_1", 100),
                new Pair<>("snowy/town_centers/snowy_meeting_point_2", 50),
                new Pair<>("snowy/town_centers/snowy_meeting_point_3", 150),
                new Pair<>("snowy/zombie/town_centers/snowy_meeting_point_1", 2),
                new Pair<>("snowy/zombie/town_centers/snowy_meeting_point_2", 1),
                new Pair<>("snowy/zombie/town_centers/snowy_meeting_point_3", 3)), VillageGenerator.PlacementBehaviour.RIGID));
         put("snowy/streets", new Triplet<>("snowy/terminators", Arrays.asList(
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
      put("snowy/zombie/streets", new Triplet<>("snowy/terminators", Arrays.asList(
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
      put("snowy/houses", new Triplet<>("snowy/terminators", Arrays.asList(
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
      put ("snowy/zombie/houses", new Triplet<>("snowy/terminators", Arrays.asList(
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
      put("snowy/terminators", new Triplet<>("empty", Arrays.asList(
            new Pair<>("plains/terminators/terminator_01", 1),
            new Pair<>("plains/terminators/terminator_02", 1),
            new Pair<>("plains/terminators/terminator_03", 1),
            new Pair<>("plains/terminators/terminator_04", 1)), VillageGenerator.PlacementBehaviour.TERRAIN_MATCHING));
      put("snowy/trees", new Triplet<>("empty", Arrays.asList(
              new Pair<>("taiga/spruce", 1)), VillageGenerator.PlacementBehaviour.RIGID));
      put("snowy/decor", new Triplet<>("empty", Arrays.asList(//5 block pile mais pas de snow ni pile ice ?
              new Pair<>("snowy/snowy_lamp_post_01",4),
              new Pair<>("snowy/snowy_lamp_post_02",4),
              new Pair<>("snowy/snowy_lamp_post_03",1),
              new Pair<>("taiga/spruce", 4),
              new Pair<>("snowy/pile_snow", 4), //here maybe to see
              new Pair<>("snowy/pile_ice", 1),
              new Pair<>("empty", 9)), VillageGenerator.PlacementBehaviour.RIGID));
      put("snowy/zombie/decor", new Triplet<>("empty", Arrays.asList(
              new Pair<>("snowy/snowy_lamp_post_01",1),
              new Pair<>("snowy/snowy_lamp_post_02",1),
              new Pair<>("snowy/snowy_lamp_post_03",1),
              new Pair<>("taiga/spruce", 4), new Pair<>("snowy/pile_snow", 4), //here maybe to see
              new Pair<>("snowy/pile_ice", 4),
              new Pair<>("empty", 7)), VillageGenerator.PlacementBehaviour.RIGID));
      put("snowy/villagers", new Triplet<>("empty", Arrays.asList(
            new Pair<>("snowy/villagers/nitwit",1),
            new Pair<>("snowy/villagers/baby",1),
            new Pair<>("snowy/villagers/unemployed",10)), VillageGenerator.PlacementBehaviour.RIGID));
      put("snowy/zombie/villagers", new Triplet<>("empty", Arrays.asList(
            new Pair<>("snowy/zombie/villagers/nitwit",1),
            new Pair<>("snowy/zombie/villagers/unemployed",10)), VillageGenerator.PlacementBehaviour.RIGID));
      put("common/cats", new Triplet<>("empty", Arrays.asList(
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
      put("common/butcher_animals", new Triplet<>("empty", Arrays.asList(
              new Pair<>("common/animals/cows_1", 3),
              new Pair<>("common/animals/pigs_1", 3),
              new Pair<>("common/animals/sheep_1", 1),
              new Pair<>("common/animals/sheep_2", 1)
      ), VillageGenerator.PlacementBehaviour.RIGID));
      put("common/iron_golem", new Triplet<>("empty", Collections.singletonList(
              new Pair<>("common/iron_golem", 1)
      ), VillageGenerator.PlacementBehaviour.RIGID));
      put("empty", new Triplet<>("empty",Collections.singletonList(
              new Pair<>("empty", 0)
      ), VillageGenerator.PlacementBehaviour.RIGID));
      put("common/animals", new Triplet<>("empty", Arrays.asList(
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
      put("common/sheep", new Triplet<>("empty", Arrays.asList(
              new Pair<>("common/animals/sheep_1", 1),
              new Pair<>("common/animals/sheep_2", 1)
      ), VillageGenerator.PlacementBehaviour.RIGID));
}
};
}
