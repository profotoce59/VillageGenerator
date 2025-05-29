#pragma once

#include <random>
#include "VillageGenerator.hpp"

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

class BlockRotationHelper {
public:
    // Obtenir une rotation aléatoire
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

        int index = static_cast<int>(dir);
        int rotation = static_cast<int>(rot);
        
        // Calcul de la nouvelle direction après rotation
        index = (index + rotation) % 4;
        return static_cast<BlockDirection>(index);
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
}; 