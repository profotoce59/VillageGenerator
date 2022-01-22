package reecriture;



import kaptainwutax.mcutils.util.block.BlockDirection;
import kaptainwutax.mcutils.util.block.BlockRotation;
import kaptainwutax.mcutils.util.math.Vec3i;
import kaptainwutax.seedutils.rand.JRand;

import java.util.Arrays;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

@SuppressWarnings("unused")
public enum BlockDirection2 {

    DOWN(BlockDirection.Axis.Y, new Vec3i(0, -1, 0)),
    UP(BlockDirection.Axis.Y, new Vec3i(0, 1, 0)),
    NORTH(BlockDirection.Axis.Z, new Vec3i(0, 0, -1)), // NONE
    SOUTH(BlockDirection.Axis.Z, new Vec3i(0, 0, 1)), // CLOCKWISE_180
    WEST(BlockDirection.Axis.X, new Vec3i(-1, 0, 0)), // COUNTERCLOCKWISE_90
    EAST(BlockDirection.Axis.X, new Vec3i(1, 0, 0)); // CLOCKWISE_90

    private static final BlockDirection2[] HORIZONTALS = {BlockDirection2.NORTH, BlockDirection2.EAST, BlockDirection2.SOUTH, BlockDirection2.WEST};
    private static final BlockDirection2[] BY_2D_DATA = {BlockDirection2.SOUTH, BlockDirection2.WEST, BlockDirection2.NORTH, BlockDirection2.EAST};
    private static final Map<String, BlockDirection2> STRING_TO_BLOCK_DIRECTION = Arrays.stream(values()).collect(Collectors.toMap(BlockDirection2::name, o -> o));
    private final BlockDirection.Axis axis;
    private final Vec3i vec;
    BlockDirection2(BlockDirection b) {
        this.axis = b.getAxis();
        this.vec = b.getVector();
    }
    BlockDirection2(BlockDirection.Axis axis, Vec3i vec) {
        this.axis = axis;
        this.vec = vec;
    }


    public static BlockDirection2 fromString(String name) {
        return STRING_TO_BLOCK_DIRECTION.get(name.toUpperCase());
    }

    public static BlockDirection2 randomHorizontal(JRand rand) {
        return HORIZONTALS[rand.nextInt(HORIZONTALS.length)];
    }

    public static BlockDirection2 getRandom(JRand rand) {
        return values()[rand.nextInt(values().length)];
    }

    public static BlockDirection2 random2D(JRand rand) {
        return BY_2D_DATA[rand.nextInt(BY_2D_DATA.length)];
    }

    public static BlockDirection2[] getHorizontal() {
        return HORIZONTALS;
    }

    public static BlockDirection2[] get2d() {
        return BY_2D_DATA;
    }

    public static List<BlockDirection2> getShuffled(JRand rand) {
        List<BlockDirection2> list = Arrays.asList(values());
        JRand.shuffle(list, rand);
        return list;
    }

    public BlockDirection2 getClockWise() {
        return getDirection(EAST, WEST, NORTH, SOUTH);
    }

    public BlockDirection2 getCounterClockWise() {
        return getDirection(WEST, EAST, SOUTH, NORTH);
    }

    public BlockDirection2 getOpposite() {
        return getDirection(SOUTH, NORTH, EAST, WEST,UP,DOWN);
    }

    private BlockDirection2 getDirection(BlockDirection2 dir1, BlockDirection2 dir2, BlockDirection2 dir3, BlockDirection2 dir4, BlockDirection2 dir5, BlockDirection2 dir6) {
        switch (this) {
            case NORTH:
                return dir1;
            case SOUTH:
                return dir2;
            case WEST:
                return dir3;
            case EAST:
                return dir4;
            case DOWN:
                return dir5;
            case UP:
                return dir6;
            default:
                throw new IllegalStateException("Unable to get facing of " + this);
        }
    }

    private BlockDirection2 getDirection(BlockDirection2 dir1, BlockDirection2 dir2, BlockDirection2 dir3, BlockDirection2 dir4) {
        switch (this) {
            case NORTH:
                return dir1;
            case SOUTH:
                return dir2;
            case WEST:
                return dir3;
            case EAST:
                return dir4;
            default:
                throw new IllegalStateException("Unable to get facing of " + this);
        }
    }

    public BlockDirection.Axis getAxis() {
        return this.axis;
    }

    public Vec3i getVector() {
        return this.vec;
    }

    public BlockRotation getRotation() {
        switch (this) {
            case NORTH:
                return BlockRotation.NONE;
            case SOUTH:
                return BlockRotation.CLOCKWISE_180;
            case WEST:
                return BlockRotation.COUNTERCLOCKWISE_90;
            case EAST:
                return BlockRotation.CLOCKWISE_90;
            default:
                throw new IllegalStateException("Unable to get direction of " + this);
        }
    }

    @Override
    public String toString() {
        return "Direction{" +
                "axis=" + axis +
                ", vec=" + vec +
                '}';
    }
}
