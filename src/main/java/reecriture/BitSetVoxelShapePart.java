package reecriture;

import java.util.BitSet;

public class BitSetVoxelShapePart {
    private final BitSet storage;
    private int xMin;
    private int yMin;
    private int zMin;
    private int xMax;
    private int yMax;
    private int zMax;
    private int xSize;
    private int ySize;
    private int zSize;

    public BitSetVoxelShapePart(int p_i47690_1_, int p_i47690_2_, int p_i47690_3_) {
        this(p_i47690_1_, p_i47690_2_, p_i47690_3_, p_i47690_1_, p_i47690_2_, p_i47690_3_, 0, 0, 0);
    }
    public BitSetVoxelShapePart(int xSize, int ySize, int zSize, int xMin, int yMin, int zMin, int xMax, int yMax, int zMax) {
        this.storage = new BitSet(xSize * ySize * zSize);
        this.xMin = xMin;
        this.yMin = yMin;
        this.zMin = zMin;
        this.xMax = xMax;
        this.yMax = yMax;
        this.zMax = zMax;
        this.xSize = xSize;
        this.ySize = ySize;
        this.zSize = zSize;
    }
    public static BitSetVoxelShapePart join(VoxelShape voxelShape, VoxelShape voxelShape1, IDoubleListMerger doubleListMerger, IDoubleListMerger doubleListMerger2, IDoubleListMerger doubleListMerger3, BoolFunc func) {
        BitSetVoxelShapePart bitsetvoxelshapepart = new BitSetVoxelShapePart(doubleListMerger.getList().size() - 1, doubleListMerger2.getList().size() - 1, doubleListMerger3.getList().size() - 1);

        doubleListMerger.forMergedIndexes((p_199628_7_, p_199628_8_, p_199628_9_) -> {
            boolean flag = doubleListMerger2.forMergedIndexes((p_199627_10_, p_199627_11_, p_199627_12_) -> {
                boolean flag1;
                if (doubleListMerger3.forMergedIndexes((p_199629_12_, p_199629_13_, p_199629_14_) -> {
                    boolean flag2 = func.apply(voxelShape.isFullWide(p_199628_7_, p_199627_10_, p_199629_12_), voxelShape1.isFullWide(p_199628_8_, p_199627_11_, p_199629_13_));
                    if (flag2) {
                        bitsetvoxelshapepart.storage.set(bitsetvoxelshapepart.getIndex(p_199628_9_, p_199627_12_, p_199629_14_));
                    }

                    return true;
                })) flag1 = true;
                else flag1 = false;
                return flag1;
            });
            return flag;
        });
        bitsetvoxelshapepart.xMax = bitsetvoxelshapepart.xMin;
        bitsetvoxelshapepart.yMax = bitsetvoxelshapepart.yMin;
        bitsetvoxelshapepart.zMax = bitsetvoxelshapepart.zMin;
        bitsetvoxelshapepart.xMin = 0;
        bitsetvoxelshapepart.yMin = 0;
        bitsetvoxelshapepart.zMin = 0;
        return bitsetvoxelshapepart;
    }
    protected int getIndex(int a, int b, int c) {
        return (a * this.ySize + b) * this.zSize + c;
    }

    public int getXSize() {
        return xSize;
    }
    public int getYSize() {
        return ySize;
    }
    public int getZSize() {
        return zSize;
    }
    public void setFull(int p_199625_1_, int p_199625_2_, int p_199625_3_, boolean p_199625_4_, boolean p_199625_5_) {
        this.storage.set(this.getIndex(p_199625_1_, p_199625_2_, p_199625_3_), p_199625_5_);
        if (p_199625_4_ && p_199625_5_) {
            this.xMin = Math.min(this.xMin, p_199625_1_);
            this.yMin = Math.min(this.yMin, p_199625_2_);
            this.zMin = Math.min(this.zMin, p_199625_3_);
            this.xMax = Math.max(this.xMax, p_199625_1_ + 1);
            this.yMax = Math.max(this.yMax, p_199625_2_ + 1);
            this.zMax = Math.max(this.zMax, p_199625_3_ + 1);
        }

    }
    public BitSet getStorage(){
        return this.storage;
    }

}
