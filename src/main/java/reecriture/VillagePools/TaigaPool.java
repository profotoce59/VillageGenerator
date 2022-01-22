package reecriture.VillagePools;

import kaptainwutax.mcutils.util.data.Pair;
import kaptainwutax.mcutils.util.data.Triplet;
import properties.VillageGenerator;

import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public interface TaigaPool {
    public static final Map<String, Triplet<String, List<Pair<String, Integer>>, VillageGenerator.PlacementBehaviour>> VILLAGE_POOLS = new HashMap<String, Triplet<String, List<Pair<String, Integer>>, VillageGenerator.PlacementBehaviour>>() {{

        put("village/taiga/town_centers", new Triplet<>("empty", Arrays.asList(
 new Pair<>("village/taiga/town_centers/taiga_meeting_point_1", 49),
 new Pair<>("village/taiga/town_centers/taiga_meeting_point_2", 49),
 new Pair<>("village/taiga/zombie/town_centers/taiga_meeting_point_1", 1),
 new Pair<>("village/taiga/zombie/town_centers/taiga_meeting_point_2", 1)), VillageGenerator.PlacementBehaviour.RIGID));
    put("village/taiga/streets", new Triplet<>("village/taiga/terminators", Arrays.asList(
 new Pair<>("village/taiga/streets/corner_01", 2), 
 new Pair<>("village/taiga/streets/corner_02", 2), 
 new Pair<>("village/taiga/streets/corner_03" ,2), 
 new Pair<>("village/taiga/streets/straight_01", 4), 
 new Pair<>("village/taiga/streets/straight_02", 4), 
 new Pair<>("village/taiga/streets/straight_03" ,4), 
 new Pair<>("village/taiga/streets/straight_04", 7), 
 new Pair<>("village/taiga/streets/straight_05", 7), 
 new Pair<>("village/taiga/streets/straight_06", 4), 
 new Pair<>("village/taiga/streets/crossroad_01", 1), 
 new Pair<>("village/taiga/streets/crossroad_02", 1), 
 new Pair<>("village/taiga/streets/crossroad_03", 2), 
 new Pair<>("village/taiga/streets/crossroad_04", 2), 
 new Pair<>("village/taiga/streets/crossroad_05", 2), 
 new Pair<>("village/taiga/streets/crossroad_06", 2), 
 new Pair<>("village/taiga/streets/turn_01", 3)), VillageGenerator.PlacementBehaviour.TERRAIN_MATCHING));
    put("village/taiga/zombie/streets", new Triplet<>("village/taiga/terminators", Arrays.asList(
 new Pair<>("village/taiga/zombie/streets/corner_01", 2), 
 new Pair<>("village/taiga/zombie/streets/corner_02", 2), 
 new Pair<>("village/taiga/zombie/streets/corner_03" ,2), 
 new Pair<>("village/taiga/zombie/streets/straight_01", 4), 
 new Pair<>("village/taiga/zombie/streets/straight_02" ,4), 
 new Pair<>("village/taiga/zombie/streets/straight_03", 4), 
 new Pair<>("village/taiga/zombie/streets/straight_04" ,7), 
 new Pair<>("village/taiga/zombie/streets/straight_05", 7), 
 new Pair<>("village/taiga/zombie/streets/straight_06" ,4), 
 new Pair<>("village/taiga/zombie/streets/crossroad_01", 1), 
 new Pair<>("village/taiga/zombie/streets/crossroad_02" ,1), 
 new Pair<>("village/taiga/zombie/streets/crossroad_03" ,2), 
 new Pair<>("village/taiga/zombie/streets/crossroad_04" ,2), 
 new Pair<>("village/taiga/zombie/streets/crossroad_05" ,2), 
 new Pair<>("village/taiga/zombie/streets/crossroad_06", 2), 
 new Pair<>("village/taiga/zombie/streets/turn_01", 3)), VillageGenerator.PlacementBehaviour.TERRAIN_MATCHING));
    put("village/taiga/houses", new Triplet<>("village/taiga/terminators", Arrays.asList(
 new Pair<>("village/taiga/houses/taiga_small_house_1", 4), 
 new Pair<>("village/taiga/houses/taiga_small_house_2", 4), 
 new Pair<>("village/taiga/houses/taiga_small_house_3", 4), 
 new Pair<>("village/taiga/houses/taiga_small_house_4", 4), 
 new Pair<>("village/taiga/houses/taiga_small_house_5", 4), 
 new Pair<>("village/taiga/houses/taiga_medium_house_1", 2), 
 new Pair<>("village/taiga/houses/taiga_medium_house_2", 2), 
 new Pair<>("village/taiga/houses/taiga_medium_house_3", 2), 
 new Pair<>("village/taiga/houses/taiga_medium_house_4", 2), 
 new Pair<>("village/taiga/houses/taiga_butcher_shop_1", 2), 
 new Pair<>("village/taiga/houses/taiga_tool_smith_1", 2), 
 new Pair<>("village/taiga/houses/taiga_fletcher_house_1", 2), 
 new Pair<>("village/taiga/houses/taiga_shepherds_house_1", 2), 
 new Pair<>("village/taiga/houses/taiga_armorer_house_1", 1), 
 new Pair<>("village/taiga/houses/taiga_armorer_2", 1), 
 new Pair<>("village/taiga/houses/taiga_fisher_cottage_1", 3), 
 new Pair<>("village/taiga/houses/taiga_tannery_1", 2), 
 new Pair<>("village/taiga/houses/taiga_cartographer_house_1", 2), 
 new Pair<>("village/taiga/houses/taiga_library_1", 2), 
 new Pair<>("village/taiga/houses/taiga_masons_house_1", 2), 
 new Pair<>("village/taiga/houses/taiga_weaponsmith_1", 2), 
 new Pair<>("village/taiga/houses/taiga_weaponsmith_2", 2), 
 new Pair<>("village/taiga/houses/taiga_temple_1", 2), 
 new Pair<>("village/taiga/houses/taiga_large_farm_1",  6), 
 new Pair<>("village/taiga/houses/taiga_large_farm_2",  6), 
 new Pair<>("village/taiga/houses/taiga_small_farm_1", 1), 
 new Pair<>("village/taiga/houses/taiga_animal_pen_1", 2), 
 new Pair<>("empty", 6)), VillageGenerator.PlacementBehaviour.RIGID));//ct comme ca
    put("village/taiga/zombie/houses", new Triplet<>("village/taiga/terminators", Arrays.asList(
 new Pair<>("village/taiga/zombie/houses/taiga_small_house_1",  4), 
 new Pair<>("village/taiga/zombie/houses/taiga_small_house_2",  4), 
 new Pair<>("village/taiga/zombie/houses/taiga_small_house_3",  4), 
 new Pair<>("village/taiga/zombie/houses/taiga_small_house_4",  4), 
 new Pair<>("village/taiga/zombie/houses/taiga_small_house_5",  4), 
 new Pair<>("village/taiga/zombie/houses/taiga_medium_house_1",  2), 
 new Pair<>("village/taiga/zombie/houses/taiga_medium_house_2",  2), 
 new Pair<>("village/taiga/zombie/houses/taiga_medium_house_3",  2), 
 new Pair<>("village/taiga/zombie/houses/taiga_medium_house_4",  2), 
 new Pair<>("village/taiga/houses/taiga_butcher_shop_1",  2), 
 new Pair<>("village/taiga/zombie/houses/taiga_tool_smith_1",  2), 
 new Pair<>("village/taiga/houses/taiga_fletcher_house_1",  2), 
 new Pair<>("village/taiga/zombie/houses/taiga_shepherds_house_1",  2), 
 new Pair<>("village/taiga/houses/taiga_armorer_house_1",  1), 
 new Pair<>("village/taiga/zombie/houses/taiga_fisher_cottage_1",  2), 
 new Pair<>("village/taiga/houses/taiga_tannery_1",  2), 
 new Pair<>("village/taiga/zombie/houses/taiga_cartographer_house_1",  2), 
 new Pair<>("village/taiga/zombie/houses/taiga_library_1",  2), 
 new Pair<>("village/taiga/houses/taiga_masons_house_1",  2), 
 new Pair<>("village/taiga/houses/taiga_weaponsmith_1",  2), 
 new Pair<>("village/taiga/zombie/houses/taiga_weaponsmith_2",  2), 
 new Pair<>("village/taiga/zombie/houses/taiga_temple_1",  2), 
 new Pair<>("village/taiga/houses/taiga_large_farm_1",  6), 
 new Pair<>("village/taiga/zombie/houses/taiga_large_farm_2",  6), 
 new Pair<>("village/taiga/houses/taiga_small_farm_1",  1), 
 new Pair<>("village/taiga/houses/taiga_animal_pen_1",  2), 
 new Pair<>("empty", 6)), VillageGenerator.PlacementBehaviour.RIGID));//not sure
    put("village/taiga/terminators", new Triplet<>("empty", Arrays.asList(
 new Pair<>("village/plains/terminators/terminator_01", 1),
 new Pair<>("village/plains/terminators/terminator_02", 1),
 new Pair<>("village/plains/terminators/terminator_03", 1),
 new Pair<>("village/plains/terminators/terminator_04", 1)), VillageGenerator.PlacementBehaviour.TERRAIN_MATCHING));
    put("village/taiga/decor", new Triplet<>("empty", Arrays.asList(
 new Pair<>("village/taiga/taiga_lamp_post_1", 10),
 new Pair<>("village/taiga/taiga_decoration_1", 4),
 new Pair<>("village/taiga/taiga_decoration_2", 1),
 new Pair<>("village/taiga/taiga_decoration_3", 1),
 new Pair<>("village/taiga/taiga_decoration_4", 1),
 new Pair<>("village/taiga/taiga_decoration_5", 2),
 new Pair<>("village/taiga/taiga_decoration_6", 1)),
 /*new Pair<>(JigsawPiece.feature(Features.SPRUCE), 4),
 new Pair<>(JigsawPiece.feature(Features.PINE), 4), 
 new Pair<>(JigsawPiece.feature(Features.PILE_PUMPKIN), 2), 
 new Pair<>(JigsawPiece.feature(Features.PATCH_TAIGA_GRASS), 4), 
 new Pair<>(JigsawPiece.feature(Features.PATCH_BERRY_BUSH), 1), 
 new Pair<>(JigsawPiece.empty(), 4)),*/ VillageGenerator.PlacementBehaviour.RIGID));
    put("village/taiga/zombie/decor", new Triplet<>("empty", Arrays.asList(
 new Pair<>("village/taiga/taiga_decoration_1", 4),
 new Pair<>("village/taiga/taiga_decoration_2", 1),
 new Pair<>("village/taiga/taiga_decoration_3", 1),
 new Pair<>("village/taiga/taiga_decoration_4", 1)),
 /*new Pair<>(JigsawPiece.feature(Features.SPRUCE), 4),
 new Pair<>(JigsawPiece.feature(Features.PINE), 4), 
 new Pair<>(JigsawPiece.feature(Features.PILE_PUMPKIN), 2), 
 new Pair<>(JigsawPiece.feature(Features.PATCH_TAIGA_GRASS), 4), 
 new Pair<>(JigsawPiece.feature(Features.PATCH_BERRY_BUSH), 1), 
 new Pair<>(JigsawPiece.empty(), 4)),*/ VillageGenerator.PlacementBehaviour.RIGID));
    put("village/taiga/villagers", new Triplet<>("empty", Arrays.asList(
 new Pair<>("village/taiga/villagers/nitwit", 1),
 new Pair<>("village/taiga/villagers/baby", 1),
 new Pair<>("village/taiga/villagers/unemployed", 10)), VillageGenerator.PlacementBehaviour.RIGID));
    put("village/taiga/zombie/villagers", new Triplet<>("empty", Arrays.asList(
 new Pair<>("village/taiga/zombie/villagers/nitwit", 1),
 new Pair<>("village/taiga/zombie/villagers/unemployed", 10)), VillageGenerator.PlacementBehaviour.RIGID));


}};}

