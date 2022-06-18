package enumType;

import kaptainwutax.biomeutils.biome.Biome;
import kaptainwutax.biomeutils.biome.Biomes;
import kaptainwutax.mcutils.block.Block;
import kaptainwutax.mcutils.util.block.BlockDirection;
import kaptainwutax.mcutils.util.data.Pair;
import kaptainwutax.mcutils.util.data.Quad;
import kaptainwutax.mcutils.util.data.Triplet;
import kaptainwutax.mcutils.util.pos.BPos;
import kaptainwutax.mcutils.util.pos.CPos;
import kaptainwutax.mcutils.version.MCVersion;
import properties.VillageGenerator;
import reecriture.VillagePools.*;

import java.util.EnumMap;
import java.util.HashMap;
import java.util.List;

public enum VillageType {
    DESERT,
    PLAINS,
    SAVANNA,
    SNOWY,
    TAIGA,
    LEGACY;
    public static final HashMap<String, List<Pair<Quad<PoolType, String, Pair<BlockDirection,BlockDirection>, Block>, BPos>>> hashMapSavanna15 = new HashMap<>(){{
        this.putAll(SavannaVillageJigsawBlocks.JIGSAW_BLOCKS15);
        this.putAll(PlainsVillageJigsawBlock.JIGSAW_BLOCKS15);
    }};
    public static final HashMap<String, List<Pair<Quad<PoolType, String, Pair<BlockDirection,BlockDirection>, Block>, BPos>>> hashMapSnowy15 = new HashMap<>(){{
        this.putAll(SnowyVillageJigsawBlocks.JIGSAW_BLOCKS15);
        this.putAll(PlainsVillageJigsawBlock.JIGSAW_BLOCKS15);
    }};
    public static final HashMap<String, List<Pair<Quad<PoolType, String, Pair<BlockDirection,BlockDirection>, Block>, BPos>>> hashMapTaiga15 = new HashMap<>(){{
        this.putAll(TaigaVillageJigsawBlocks.JIGSAW_BLOCKS15);
        this.putAll(PlainsVillageJigsawBlock.JIGSAW_BLOCKS15);
    }};
    public static final EnumMap<PoolType, Triplet<PoolType, List<Pair<String, Integer>>, VillageGenerator.PlacementBehaviour>> poolSavanna15 = new EnumMap<>(PoolType.class) {{
        this.putAll(SavannaPool.VILLAGE_POOLS);
        this.putAll(PlainPool.VILLAGE_POOLS);
    }
    };
    public static final EnumMap<PoolType, Triplet<PoolType, List<Pair<String, Integer>>, VillageGenerator.PlacementBehaviour>> poolSnowy15 = new EnumMap<>(PoolType.class) {{
        this.putAll(SnowyPool.VILLAGE_POOLS);
        this.putAll(PlainPool.VILLAGE_POOLS);
    }
    };
    public static final EnumMap<PoolType, Triplet<PoolType, List<Pair<String, Integer>>, VillageGenerator.PlacementBehaviour>> poolTaiga15 = new EnumMap<>(PoolType.class) {{
        this.putAll(TaigaPool.VILLAGE_POOLS);
        this.putAll(PlainPool.VILLAGE_POOLS);
    }
    };



    public static VillageType getType(Biome biome, MCVersion version) {
        if(version.isOlderThan(MCVersion.v1_14)) return LEGACY;
        if(Biomes.DESERT.equals(biome)) {
            return DESERT;
        }
        if(Biomes.SAVANNA.equals(biome)) {
            return SAVANNA;
        }
        if(Biomes.SNOWY_TUNDRA.equals(biome)) {
            return SNOWY;
        }
        if(Biomes.TAIGA.equals(biome)) {
            return TAIGA;
        }
        if(biome.equals(Biomes.PLAINS)) {
            return PLAINS;
        }
        return null;
    }

    public HashMap<String, List<Pair<Quad<PoolType, String, Pair<BlockDirection,BlockDirection>, Block>, BPos>>> getJigsawBlocks(MCVersion version) {
        if(version.isOlderThan(MCVersion.v1_16)){
            switch(this) {
                case DESERT:
                    return DesertVillageJigsawBlocks.JIGSAW_BLOCKS15;
                case PLAINS:
                    return PlainsVillageJigsawBlock.JIGSAW_BLOCKS15;
                case SAVANNA:
                    return hashMapSavanna15;
                case SNOWY:
                    return hashMapSnowy15;
                case TAIGA:
                    return hashMapTaiga15;
            }
        }
        else if(version.isOlderThan(MCVersion.v1_17)){
            switch (this) {
                case DESERT:
                    return DesertVillageJigsawBlocks.JIGSAW_BLOCKS;
                case PLAINS:
                    return PlainsVillageJigsawBlock.JIGSAW_BLOCKS;
                case SAVANNA:
                    return SavannaVillageJigsawBlocks.JIGSAW_BLOCKS;
                case SNOWY:
                    return SnowyVillageJigsawBlocks.JIGSAW_BLOCKS;
                case TAIGA:
                    return TaigaVillageJigsawBlocks.JIGSAW_BLOCKS;
            }

        }
        else{
            switch (this) {
                case DESERT:
                    return DesertVillageJigsawBlocks.JIGSAW_BLOCKS17;
                case PLAINS:
                    return PlainsVillageJigsawBlock.JIGSAW_BLOCKS17;
                case SAVANNA:
                    return SavannaVillageJigsawBlocks.JIGSAW_BLOCKS17;
                case SNOWY:
                    return SnowyVillageJigsawBlocks.JIGSAW_BLOCKS17;
                case TAIGA:
                    return TaigaVillageJigsawBlocks.JIGSAW_BLOCKS17;
            }

        }
        return null;
    }
    public String getBlackSmithName(){//don't check for zombie village yet
        switch(this){
            case DESERT :
                return "desert/houses/desert_weaponsmith_1";
            case PLAINS :
                return "plains/houses/plains_weaponsmith_1";
            case TAIGA:
                return "taiga/houses/taiga_weaponsmith_1";
            case SAVANNA :
                return "savanna/houses/savanna_weaponsmith_2";
            case SNOWY :
                return "snowy/houses/snowy_weapon_smith_1";
        }
        return null;
    }
    public String getHouseName(){
        switch(this){
            case DESERT :
                return "desert/houses";

            case PLAINS :
                return "plains/houses";
            case TAIGA:
                return "taiga/houses";
            case SAVANNA :
                return "savanna/houses";
            case SNOWY :
                return "snowy/houses";
            default:
                return "desert/houses";
        }
    }
    public CPos getChestChunk(VillageGenerator.Piece piece){
        BPos dist;
        switch(this){
            case DESERT :
                dist = new BPos(1,0,2);
                dist = piece.rotation.rotate(dist,new BPos(0,0,0));
                return piece.pos.add(dist).toChunkPos();
            case PLAINS :
                dist = new BPos(6,0,4);
                dist = piece.rotation.rotate(dist,new BPos(0,0,0));
                return piece.pos.add(dist).toChunkPos();
            case TAIGA:
                dist = new BPos(2,0,3);
                dist = piece.rotation.rotate(dist,new BPos(0,0,0));
                return piece.pos.add(dist).toChunkPos();
            case SAVANNA :
                dist = new BPos(2,0,9);
                dist = piece.rotation.rotate(dist,new BPos(0,0,0));
                return piece.pos.add(dist).toChunkPos();
            case SNOWY :
                dist = new BPos(2,0,2);
                dist = piece.rotation.rotate(dist,new BPos(0,0,0));
                return piece.pos.add(dist).toChunkPos();
            default:
                return new CPos(1,1);
        }
    }

    public EnumMap<PoolType, Triplet<PoolType, List<Pair<String, Integer>>, VillageGenerator.PlacementBehaviour>> getPool(MCVersion version) {
        switch(this) {
            case TAIGA:
                if(version.isNewerOrEqualTo(MCVersion.v1_16))
                    return TaigaPool.VILLAGE_POOLS;
                else {
                    return poolTaiga15;
                }
            case DESERT:
                return DesertPool.VILLAGE_POOLS;
            case PLAINS:
                return PlainPool.VILLAGE_POOLS;
            case SAVANNA:
                if(version.isNewerOrEqualTo(MCVersion.v1_16))
                    return SavannaPool.VILLAGE_POOLS;
                else {
                    return poolSavanna15;
                }
            case SNOWY:
                if(version.isNewerOrEqualTo(MCVersion.v1_16))
                    return SnowyPool.VILLAGE_POOLS;
                else {

                    return poolSnowy15;
                }

        }
        return null;
    }
}
