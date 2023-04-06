package profotoce59.reecriture;

import com.seedfinding.mccore.util.block.BlockBox;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class VoxelShape {
    private List<Double> xs;
    private List<Double> ys;
    private List<Double> zs;
    public List<BlockBox> fullBoxes = new ArrayList<>();

    public VoxelShape() {
        this.xs = null;
        this.ys = null;
        this.zs = null;
    }
    public VoxelShape(BlockBox box) {
        xs = Arrays.asList((double)box.minX,(double)box.maxX);
        ys = Arrays.asList((double)box.minY,(double)box.maxY);
        zs = Arrays.asList((double)box.minZ,(double)box.maxZ);

    }

    public boolean isNull(){
        return (this.xs == null);
    }
    public void setValue(BlockBox box, boolean b) {
        this.xs = Arrays.asList((double)box.minX,(double)box.maxX+1.0);
        ys = Arrays.asList((double)box.minY,(double)box.maxY+1.0);
        zs = Arrays.asList((double)box.minZ,(double)box.maxZ+1);
    }
    public List<Double> getX(){
        return this.xs;
    }
    public double getLastX(){
        return this.xs.get(xs.size()-1);
    }
    public double getLastY(){
        return this.ys.get(ys.size()-1);
    }
    public double getLastZ(){
        return this.zs.get(zs.size()-1);

    }
    public List<Double> getY(){
        return this.ys;
    }
    public List<Double> getZ(){
        return this.zs;
    }
}
