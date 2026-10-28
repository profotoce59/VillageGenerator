#pragma once

#include <random>
#include <vector>
#include "BlockStructures.hpp"

// Direction d'un bloc
enum class BlockDirection {
    NORTH,
    SOUTH,
    EAST,
    WEST,
    UP,
    DOWN
};

// Rotation d'un bloc
enum class BlockRotation {
    NONE,           // 0 degrés
    CLOCKWISE_90,   // 90 degrés
    CLOCKWISE_180,  // 180 degrés
    COUNTERCLOCKWISE_90  // 270 degrés
};

// Miroir d'un bloc
enum class BlockMirror {
    NONE,
    LEFT_RIGHT,
    FRONT_BACK
};

// Forward declaration
class ChunkRand;

class BlockRotationHelper {
public:
    // Obtenir une rotation aléatoire from ChunkRand
    static BlockRotation getRandom(ChunkRand& rand);

    // Obtenir une rotation aléatoire from std::mt19937_64
    static BlockRotation getRandom(std::mt19937_64& rng) {
        std::uniform_int_distribution<int> dist(0, 3);
        switch (dist(rng)) {
            case 0: return BlockRotation::NONE;
            case 1: return BlockRotation::CLOCKWISE_90;
            case 2: return BlockRotation::CLOCKWISE_180;
            case 3: return BlockRotation::COUNTERCLOCKWISE_90;
            default: return BlockRotation::NONE;
        }
    }

    // Rotation d'une direction
    static BlockDirection rotate(BlockDirection dir, BlockRotation rot) {
        if (dir == BlockDirection::UP || dir == BlockDirection::DOWN) {
            return dir;
        }

        // Mapping explicite pour coller au comportement Java (mc_core)
        switch (rot) {
            case BlockRotation::CLOCKWISE_90:
                switch (dir) {
                    case BlockDirection::NORTH: return BlockDirection::EAST;
                    case BlockDirection::EAST:  return BlockDirection::SOUTH;
                    case BlockDirection::SOUTH: return BlockDirection::WEST;
                    case BlockDirection::WEST:  return BlockDirection::NORTH;
                    default: return dir;
                }
            case BlockRotation::CLOCKWISE_180:
                return getOpposite(dir);
            case BlockRotation::COUNTERCLOCKWISE_90:
                switch (dir) {
                    case BlockDirection::NORTH: return BlockDirection::WEST;
                    case BlockDirection::WEST:  return BlockDirection::SOUTH;
                    case BlockDirection::SOUTH: return BlockDirection::EAST;
                    case BlockDirection::EAST:  return BlockDirection::NORTH;
                    default: return dir;
                }
            case BlockRotation::NONE:
            default:
                return dir;
        }
    }

    // Rotation d'une position
    static BPos rotate(const BPos& pos, BlockRotation rot) {
        switch (rot) {
            case BlockRotation::NONE:
                return pos;
            case BlockRotation::CLOCKWISE_90:
                return BPos(-pos.z, pos.y, pos.x);
            case BlockRotation::CLOCKWISE_180:
                return BPos(-pos.x, pos.y, -pos.z);
            case BlockRotation::COUNTERCLOCKWISE_90:
                return BPos(pos.z, pos.y, -pos.x);
            default:
                return pos;
        }
    }

    // Obtenir le vecteur de direction
    static BPos getDirectionVector(BlockDirection dir) {
        switch (dir) {
            case BlockDirection::NORTH: return BPos(0, 0, -1);
            case BlockDirection::SOUTH: return BPos(0, 0, 1);
            case BlockDirection::EAST: return BPos(1, 0, 0);
            case BlockDirection::WEST: return BPos(-1, 0, 0);
            case BlockDirection::UP: return BPos(0, 1, 0);
            case BlockDirection::DOWN: return BPos(0, -1, 0);
            default: return BPos(0, 0, 0);
        }
    }

    // Direction opposée (pour canAttach15)
    static BlockDirection getOpposite(BlockDirection dir) {
        switch (dir) {
            case BlockDirection::NORTH: return BlockDirection::SOUTH;
            case BlockDirection::SOUTH: return BlockDirection::NORTH;
            case BlockDirection::EAST: return BlockDirection::WEST;
            case BlockDirection::WEST: return BlockDirection::EAST;
            case BlockDirection::UP: return BlockDirection::DOWN;
            case BlockDirection::DOWN: return BlockDirection::UP;
            default: return dir;
        }
    }

    // Rotations dans un ordre aléatoire (Java BlockRotation.getShuffled(rand))
    static std::vector<BlockRotation> getShuffled(ChunkRand& rand);
}; 
