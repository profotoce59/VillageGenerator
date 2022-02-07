package reecriture.VillagePools;

import kaptainwutax.mcutils.util.data.Pair;
import kaptainwutax.mcutils.util.data.Triplet;
import properties.VillageGenerator;

import java.util.*;

public interface TaigaPool {
    public static final Map<String, Triplet<String, List<Pair<String, Integer>>, VillageGenerator.PlacementBehaviour>> VILLAGE_POOLS = new HashMap<String, Triplet<String, List<Pair<String, Integer>>, VillageGenerator.PlacementBehaviour>>() {{

        put("taiga/town_centers", new Triplet<>("empty", Arrays.asList(
 new Pair<>("taiga/town_centers/taiga_meeting_point_1", 49),
 new Pair<>("taiga/town_centers/taiga_meeting_point_2", 49),
 new Pair<>("taiga/zombie/town_centers/taiga_meeting_point_1", 1),
 new Pair<>("taiga/zombie/town_centers/taiga_meeting_point_2", 1)), VillageGenerator.PlacementBehaviour.RIGID));
    put("taiga/streets", new Triplet<>("taiga/terminators", Arrays.asList(
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
    put("taiga/zombie/streets", new Triplet<>("taiga/terminators", Arrays.asList(
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
    put("taiga/houses", new Triplet<>("taiga/terminators", Arrays.asList(
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
    put("taiga/zombie/houses", new Triplet<>("taiga/terminators", Arrays.asList(
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
    put("taiga/terminators", new Triplet<>("empty", Arrays.asList(
 new Pair<>("plains/terminators/terminator_01", 1),
 new Pair<>("plains/terminators/terminator_02", 1),
 new Pair<>("plains/terminators/terminator_03", 1),
 new Pair<>("plains/terminators/terminator_04", 1)), VillageGenerator.PlacementBehaviour.TERRAIN_MATCHING));
    put("taiga/decor", new Triplet<>("empty", Arrays.asList(
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
    put("taiga/zombie/decor", new Triplet<>("empty", Arrays.asList(
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
    put("taiga/villagers", new Triplet<>("empty", Arrays.asList(
 new Pair<>("taiga/villagers/nitwit", 1),
 new Pair<>("taiga/villagers/baby", 1),
 new Pair<>("taiga/villagers/unemployed", 10)), VillageGenerator.PlacementBehaviour.RIGID));
    put("taiga/zombie/villagers", new Triplet<>("empty", Arrays.asList(
 new Pair<>("taiga/zombie/villagers/nitwit", 1),
 new Pair<>("taiga/zombie/villagers/unemployed", 10)), VillageGenerator.PlacementBehaviour.RIGID));
        put("common/cats", new Triplet<>("empty", Arrays.asList(
                new Pair<>("common/animals/cat_black", 1),
                new Pair<>("common/animals/cat_british", 1),
                new Pair<>("common/animals/cat_calico", 1),
                new Pair<>("common/animals/cat_persia", 1),
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

