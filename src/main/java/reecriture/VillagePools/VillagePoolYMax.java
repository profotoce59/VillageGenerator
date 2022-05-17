package reecriture.VillagePools;
##give directly the height of a structure to avoid to calculate it as in mc code which took a while
import java.util.HashMap;

public class VillagePoolYMax {
    public static final HashMap<String, Integer> Y_MAX = new HashMap<>() {{

        put("common/animals",3);
        put("common/sheep",3);
        put("common/cats",3);
        put("common/butcher_animals",3);
        put("common/iron_golem",3);
        put("common/well_bottoms",3);

        put("plains/town_centers",9);
        put("plains/streets",2);
        put("plains/zombie/streets",2);
        put("plains/houses",12);
        put("plains/zombie/houses",12);
        put("plains/decor",4);
        put("plains/zombie/decor",4);
        put("plains/villagers",3);
        put("plains/zombie/villagers",3);
        put("plains/terminators",2);
        put("plains/trees",0);

        put("desert/town_centers",6);
        put("desert/streets",2);
        put("desert/zombie/streets",2);
        put("desert/houses",18);
        put("desert/zombie/houses",17);
        put("desert/terminators",2);
        put("desert/zombie/terminators",2);
        put("desert/decor",4);
        put("desert/zombie/decor",4);
        put("desert/villagers",3);
        put("desert/zombie/villagers",3);

        put("empty",0);
        put("taiga/terminators",2);
        put("taiga/town_centers",7);
        put("taiga/streets",2);
        put("taiga/zombie/streets",2);
        put("taiga/houses",14);
        put("taiga/zombie/houses",14);
        put("taiga/decor",2);
        put("taiga/zombie/decor",2);
        put("taiga/villagers",3);
        put("taiga/zombie/villagers",3);
    }};


}
