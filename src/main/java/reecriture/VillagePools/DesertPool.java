package reecriture.VillagePools;

import kaptainwutax.mcutils.util.data.Pair;
import kaptainwutax.mcutils.util.data.Triplet;
import properties.VillageGenerator;

import java.util.*;

public interface DesertPool {
    public static final Map<String, Triplet<String, List<Pair<String, Integer>>, VillageGenerator.PlacementBehaviour>> VILLAGE_POOLS = new HashMap<String, Triplet<String, List<Pair<String, Integer>>, VillageGenerator.PlacementBehaviour>>() {
        {
            put("desert/town_centers", new Triplet<>("empty", Arrays.asList(
                    new Pair<>("desert/town_centers/desert_meeting_point_1", 98),
                    new Pair<>("desert/town_centers/desert_meeting_point_2", 98),
                    new Pair<>("desert/town_centers/desert_meeting_point_3", 49),
                    new Pair<>("desert/zombie/town_centers/desert_meeting_point_1", 2),
                    new Pair<>("desert/zombie/town_centers/desert_meeting_point_2", 2),
                    new Pair<>("desert/zombie/town_centers/desert_meeting_point_3", 1)
            ), VillageGenerator.PlacementBehaviour.RIGID));
            put("desert/streets", new Triplet<>("desert/terminators", Arrays.asList(
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
            put("desert/zombie/streets", new Triplet<>("desert/zombie/terminators", Arrays.asList(
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
            put("desert/houses", new Triplet<>("desert/terminators", Arrays.asList(
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
            put("desert/zombie/houses", new Triplet<>("desert/zombie/terminators", Arrays.asList(
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
            put("desert/terminators", new Triplet<>("empty", Arrays.asList(
                    new Pair<>("desert/terminators/terminator_01", 1),
                    new Pair<>("desert/terminators/terminator_02", 1)
            ), VillageGenerator.PlacementBehaviour.TERRAIN_MATCHING));
            put("desert/zombie/terminators", new Triplet<>("empty", Arrays.asList(
                    new Pair<>("desert/terminators/terminator_01", 1),
                    new Pair<>("desert/zombie/terminators/terminator_02", 1)
            ), VillageGenerator.PlacementBehaviour.TERRAIN_MATCHING));
            put("desert/decor", new Triplet<>("empty", Arrays.asList(
                    new Pair<>("desert/desert_lamp_1", 10),
                    new Pair<>("patch_cactus", 4),
                    new Pair<>("pile_hay", 4),
                    new Pair<>("empty", 10)
            ), VillageGenerator.PlacementBehaviour.RIGID));
            put("desert/zombie/decor", new Triplet<>("empty", Arrays.asList(
                    new Pair<>("desert/desert_lamp_1", 10),
                    new Pair<>("desert/patch_cactus", 4),
                    new Pair<>("desert/pile_hay", 4),
                    new Pair<>("empty", 10)
            ), VillageGenerator.PlacementBehaviour.RIGID));
            put("desert/villagers", new Triplet<>("empty", Arrays.asList(
                    new Pair<>("desert/villagers/nitwit", 1),
                    new Pair<>("desert/villagers/baby", 1),
                    new Pair<>("desert/villagers/unemployed", 10)
            ), VillageGenerator.PlacementBehaviour.RIGID));
            put("desert/zombie/villagers", new Triplet<>("empty", Arrays.asList(
                    new Pair<>("desert/zombie/villagers/nitwit", 1),
                    new Pair<>("desert/zombie/villagers/unemployed", 10)
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
            put("common/well_bottoms", new Triplet<>("empty", Collections.singletonList(
                    new Pair<>("common/well_bottom", 1)
            ), VillageGenerator.PlacementBehaviour.RIGID));
            put("empty", new Triplet<>("empty",Collections.singletonList(
                    new Pair<>("empty", 0)
            ), VillageGenerator.PlacementBehaviour.RIGID));
        }};}
