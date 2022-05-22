package reecriture.VillagePools;

import kaptainwutax.mcutils.util.data.Pair;
import kaptainwutax.mcutils.util.data.Triplet;
import properties.VillageGenerator;

import java.util.*;

public interface SavannaPool {
    public static final Map<String, Triplet<String, List<Pair<String, Integer>>, VillageGenerator.PlacementBehaviour>> VILLAGE_POOLS = new HashMap<String, Triplet<String, List<Pair<String, Integer>>, VillageGenerator.PlacementBehaviour>>() {{
      put("savanna/town_centers", new Triplet<>("empty", Arrays.asList(
              new Pair<>("savanna/town_centers/savanna_meeting_point_1", 100),
              new Pair<>("savanna/town_centers/savanna_meeting_point_2", 50),
              new Pair<>("savanna/town_centers/savanna_meeting_point_3", 150),
              new Pair<>("savanna/town_centers/savanna_meeting_point_4", 150),
              new Pair<>("savanna/zombie/town_centers/savanna_meeting_point_1",2),
              new Pair<>("savanna/zombie/town_centers/savanna_meeting_point_2",  1),
              new Pair<>("savanna/zombie/town_centers/savanna_meeting_point_3", 3),
              new Pair<>("savanna/zombie/town_centers/savanna_meeting_point_4", 3)), VillageGenerator.PlacementBehaviour.RIGID));
        put("savanna/streets", new Triplet<>("savanna/terminators", Arrays.asList(
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
      put("savanna/zombie/streets", new Triplet<>("savanna/zombie/terminators", Arrays.asList(//ressourceLocqtion weird ?
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
      put("savanna/houses", new Triplet<>("savanna/terminators", Arrays.asList(
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
      put("savanna/zombie/houses", new Triplet<>("savanna/zombie/terminators", Arrays.asList(
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
      put("savanna/terminators", new Triplet<>("empty", Arrays.asList(
            new Pair<>("plains/terminators/terminator_01", 1),
            new Pair<>("plains/terminators/terminator_02", 1),
            new Pair<>("plains/terminators/terminator_03", 1),
            new Pair<>("plains/terminators/terminator_04", 1),
            new Pair<>("savanna/terminators/terminator_05", 1)), VillageGenerator.PlacementBehaviour.TERRAIN_MATCHING));
      put("savanna/zombie/terminators", new Triplet<>("empty", Arrays.asList(
            new Pair<>("plains/terminators/terminator_01", 1),
            new Pair<>("plains/terminators/terminator_02", 1),
            new Pair<>("plains/terminators/terminator_03", 1),
            new Pair<>("plains/terminators/terminator_04", 1),
            new Pair<>("savanna/zombie/terminators/terminator_05", 1)), VillageGenerator.PlacementBehaviour.TERRAIN_MATCHING));
      put("savanna/trees", new Triplet<>("empty", Arrays.asList(
            new Pair<>("savanna/acacia", 1)), VillageGenerator.PlacementBehaviour.RIGID));
      put("savanna/decor", new Triplet<>("empty", Arrays.asList(
            new Pair<>("savanna/savanna_lamp_post_01", 4),
            new Pair<>("savanna/acacia", 4),
            new Pair<>("pile_hay", 4),
            new Pair<>("pile_melon", 1),
            new Pair<>("empty", 4)), VillageGenerator.PlacementBehaviour.RIGID));
      put("savanna/zombie/decor", new Triplet<>("empty", Arrays.asList(
            new Pair<>("savanna/savanna_lamp_post_01", 4),
            new Pair<>("savanna/acacia", 4),
            new Pair<>("pile_hay", 4),
            new Pair<>("pile_melon", 1),
            new Pair<>("empty", 4)), VillageGenerator.PlacementBehaviour.RIGID));
      put("savanna/villagers", new Triplet<>("empty", Arrays.asList(
            new Pair<>("savanna/villagers/nitwit", 1),
            new Pair<>("savanna/villagers/baby", 1),
            new Pair<>("savanna/villagers/unemployed", 10)), VillageGenerator.PlacementBehaviour.RIGID));
      put("savanna/zombie/villagers", new Triplet<>("empty", Arrays.asList(
            new Pair<>("savanna/zombie/villagers/nitwit", 1),
            new Pair<>("savanna/zombie/villagers/unemployed", 10)), VillageGenerator.PlacementBehaviour.RIGID));
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
    }};}
