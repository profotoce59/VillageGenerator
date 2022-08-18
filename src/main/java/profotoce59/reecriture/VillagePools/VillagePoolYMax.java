package profotoce59.reecriture.VillagePools;

import profotoce59.enumType.PoolType;

import java.util.EnumMap;

public class VillagePoolYMax {
    public static final EnumMap<PoolType, Integer> Y_MAX = new EnumMap<>(PoolType.class) {{

        put(PoolType.ANIMALS,3);
        put(PoolType.SHEEPS,3);
        put(PoolType.CATS,3);
        put(PoolType.BUTCHER_ANIMAL,3);
        put(PoolType.IRON_GOLEM,3);
        put(PoolType.WELL_BOTTOM,3);

        put(PoolType.PLAIN_CENTER,9);
        put(PoolType.PLAIN_STREET,2);
        put(PoolType.PLAIN_ZSTREET,2);
        put(PoolType.PLAIN_HOUSES,12);
        put(PoolType.PLAIN_ZHOUSES,12);
        put(PoolType.PLAIN_DECOR,4);
        put(PoolType.PLAIN_ZDECOR,4);
        put(PoolType.PLAIN_VILLAGER,3);
        put(PoolType.PLAIN_ZVILLAGER,3);
        put(PoolType.PLAIN_TERMINATOR,2);
        put(PoolType.PLAIN_TREE,0);

        put(PoolType.DESERT_CENTER,6);
        put(PoolType.DESERT_STREET,2);
        put(PoolType.DESERT_ZSTREET,2);
        put(PoolType.DESERT_HOUSES,18);
        put(PoolType.DESERT_ZHOUSES,17);
        put(PoolType.DESERT_TERMINATOR,2);
        put(PoolType.DESERT_ZTERMINATOR,2);
        put(PoolType.DESERT_DECOR,4);
        put(PoolType.DESERT_ZDECOR,4);
        put(PoolType.DESERT_VILLAGER,3);
        put(PoolType.DESERT_ZVILLAGER,3);

        put(PoolType.EMPTY,0);
        put(PoolType.TAIGA_TERMINATOR,2);
        put(PoolType.TAIGA_CENTER,7);
        put(PoolType.TAIGA_STREET,2);
        put(PoolType.TAIGA_ZSTREET,2);
        put(PoolType.TAIGA_HOUSES,14);
        put(PoolType.TAIGA_ZHOUSES,14);
        put(PoolType.TAIGA_DECOR,2);
        put(PoolType.TAIGA_ZDECOR,2);
        put(PoolType.TAIGA_VILLAGER,3);
        put(PoolType.TAIGA_ZVILLAGER,3);

        put(PoolType.SAVANNA_TERMINATOR,2);
        put(PoolType.SAVANNA_ZTERMINATOR,2);
        put(PoolType.SAVANNA_CENTER,6);
        put(PoolType.SAVANNA_STREET,2);
        put(PoolType.SAVANNA_ZSTREET,2);
        put(PoolType.SAVANNA_HOUSES,14);
        put(PoolType.SAVANNA_ZHOUSES,10);
        put(PoolType.SAVANNA_DECOR,2);
        put(PoolType.SAVANNA_ZDECOR,2);
        put(PoolType.SAVANNA_VILLAGER,3);
        put(PoolType.SAVANNA_ZVILLAGER,3);
        put(PoolType.SAVANNA_TREE,1);

        put(PoolType.SNOWY_TERMINATOR,2);
        put(PoolType.SNOWY_CENTER,8);
        put(PoolType.SNOWY_STREET,2);
        put(PoolType.SNOWY_ZSTREET,2);
        put(PoolType.SNOWY_HOUSES,14);
        put(PoolType.SNOWY_ZHOUSES,9);
        put(PoolType.SNOWY_DECOR,4); //not sure about the zombies
        put(PoolType.SNOWY_ZDECOR,4);
        put(PoolType.SNOWY_VILLAGER,3);
        put(PoolType.SNOWY_ZVILLAGER,3);
    }};


}
