package reecriture;

import jdk.jshell.execution.Util;
import kaptainwutax.mcutils.util.block.BlockBox;
import java.util.Arrays;
import java.util.List;
import java.util.BitSet;

public class VoxelShape {
    private List<Double> xs;
    private List<Double> ys;
    private List<Double> zs;
    private BitSetVoxelShapePart storage;
    public static final BitSetVoxelShapePart BLOCK = block();
    public VoxelShape() {
        this.xs = null;
        this.ys = null;
        this.zs = null;
        this.storage = null;
    }
    private static final BitSetVoxelShapePart block(){
        BitSetVoxelShapePart voxelshapepart = new BitSetVoxelShapePart(1, 1, 1);
        voxelshapepart.setFull(0, 0, 0, true, true);
        return voxelshapepart;
    }



    public VoxelShape(BlockBox box) {
        xs = Arrays.asList((double)box.minX,(double)box.maxX);
        ys = Arrays.asList((double)box.minY,(double)box.maxY);
        zs = Arrays.asList((double)box.minZ,(double)box.maxZ);
        this.storage = BLOCK;

    }
    public VoxelShape(BlockBox box,double deflate) {
        xs = Arrays.asList(box.minX+deflate,box.maxX+1-deflate);
        ys = Arrays.asList(box.minY+deflate,box.maxY+1-deflate);
        zs = Arrays.asList(box.minZ+deflate,box.maxZ+1-deflate);
        this.storage = BLOCK;

    }
    public VoxelShape(BlockBox box,boolean boundingtoVoxel) {
        xs = Arrays.asList((double)box.minX,(double)box.maxX+1.0);
        ys = Arrays.asList((double)box.minY,(double)box.maxY+1.0);
        zs = Arrays.asList((double)box.minZ,(double)box.maxZ+1);
        this.storage = BLOCK;

    }

    public VoxelShape(BitSetVoxelShapePart bitsetvoxelshapepart, List<Double> list, List<Double> list1, List<Double> list2) {
        int i = bitsetvoxelshapepart.getXSize()+1;
        int j = bitsetvoxelshapepart.getYSize()+1;
        int k = bitsetvoxelshapepart.getZSize()+1;
        if(i== list.size() && j == list1.size() && k == list2.size()){// quand tous sera bon a retiré ?
            this.xs = list;
            this.ys = list1;
            this.zs = list2;
            this.storage = bitsetvoxelshapepart;
        }
        else {
            throw (new IllegalArgumentException());
        }
    }



    public boolean isNull(){
        return (this.xs == null);
    }
    public List<Double> getCoords(int axe){
        switch(axe){
            case 0:
                return xs;
            case 1:
                return ys;
            case 2 :
                return zs;
            default:
                throw new IllegalArgumentException();
        }
    }
    public boolean isFullWide(int a,int b, int c){
        if (a >= 0 && b >= 0 && c >= 0) {
            return a < (this.xs.size()-1) && b < (this.ys.size()-1) && c < (this.zs.size()-1) ? this.isFull(a, b, c) : false;
        } else {
            return false;
        }

    }
    protected int getIndex(int a, int b, int c) {
        return (a * (this.ys.size()-1) + b) * (this.zs.size()-1) + c;
    }
    public boolean isFull(int a,int b,int c){
        return this.storage.getStorage().get(this.getIndex(a,b,c));
    }

    public void setValue(BlockBox box, boolean b) {
        this.xs = Arrays.asList((double)box.minX,(double)box.maxX+1.0);
        ys = Arrays.asList((double)box.minY,(double)box.maxY+1.0);
        zs = Arrays.asList((double)box.minZ,(double)box.maxZ+1);
        this.storage = BLOCK;
    }

    public void setValue(VoxelShape joinUnoptimized) {
        this.xs = joinUnoptimized.xs;
        this.ys = joinUnoptimized.ys;
        this.zs = joinUnoptimized.zs;
        this.storage = joinUnoptimized.storage;

    }
}
