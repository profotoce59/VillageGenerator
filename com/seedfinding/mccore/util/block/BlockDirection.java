package com.seedfinding.mccore.util.block;

import com.seedfinding.mccore.util.math.Vec3i;
import com.seedfinding.mcseed.rand.JRand;

import java.util.Arrays;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

@SuppressWarnings("unused")
public enum BlockDirection {

	DOWN(Axis.Y, new Vec3i(0, -1, 0)),
	UP(Axis.Y, new Vec3i(0, 1, 0)),
	NORTH(Axis.Z, new Vec3i(0, 0, -1)), // NONE
	SOUTH(Axis.Z, new Vec3i(0, 0, 1)), // CLOCKWISE_180
	WEST(Axis.X, new Vec3i(-1, 0, 0)), // COUNTERCLOCKWISE_90
	EAST(Axis.X, new Vec3i(1, 0, 0)); // CLOCKWISE_90

	private static final BlockDirection[] HORIZONTALS = {BlockDirection.NORTH, BlockDirection.EAST, BlockDirection.SOUTH, BlockDirection.WEST};
	private static final BlockDirection[] BY_2D_DATA = {BlockDirection.SOUTH, BlockDirection.WEST, BlockDirection.NORTH, BlockDirection.EAST};
	private static final Map<String, BlockDirection> STRING_TO_BLOCK_DIRECTION = Arrays.stream(values()).collect(Collectors.toMap(BlockDirection::name, o -> o));
	private final Axis axis;
	private final Vec3i vec;

	BlockDirection(Axis axis, Vec3i vec) {
		this.axis = axis;
		this.vec = vec;
	}

	public static BlockDirection fromString(String name) {
		return STRING_TO_BLOCK_DIRECTION.get(name.toUpperCase());
	}

	public static BlockDirection randomHorizontal(JRand rand) {
		return HORIZONTALS[rand.nextInt(HORIZONTALS.length)];
	}

	public static BlockDirection getRandom(JRand rand) {
		return values()[rand.nextInt(values().length)];
	}

	public static BlockDirection random2D(JRand rand) {
		return BY_2D_DATA[rand.nextInt(BY_2D_DATA.length)];
	}

	public static BlockDirection[] getHorizontal() {
		return HORIZONTALS;
	}

	public static BlockDirection[] get2d() {
		return BY_2D_DATA;
	}

	public static List<BlockDirection> getShuffled(JRand rand) {
		List<BlockDirection> list = Arrays.asList(values());
		JRand.shuffle(list, rand);
		return list;
	}

	public BlockDirection getClockWise() {
		return getDirection(EAST, WEST, NORTH, SOUTH);
	}

	public BlockDirection getCounterClockWise() {
		return getDirection(WEST, EAST, SOUTH, NORTH);
	}

	public BlockDirection getOpposite() {
		return getDirection(SOUTH, NORTH, EAST, WEST);
	}

	private BlockDirection getDirection(BlockDirection dir1, BlockDirection dir2, BlockDirection dir3, BlockDirection dir4) {
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

	public Axis getAxis() {
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

	public enum Axis {
		X, Y, Z;

		public Axis get2DRotated() {
			switch (this) {
				case X:
					return Z;
				case Z:
					return X;
				default:
					return Y;
			}
		}

	}
}
