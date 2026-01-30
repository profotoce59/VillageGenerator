#pragma once

#include <vector>
#include "VillageGenerator.hpp"

// Classe pour gérer les collisions entre les pièces du village
class VoxelShape {
public:
    VoxelShape() = default;
    explicit VoxelShape(const BlockBox& box) {
        setValue(box, true);
    }

    // Ajouter une boîte de collision
    void setValue(const BlockBox& box, bool value) {
        if (value) {
            fullBoxes.push_back(box);
        }
    }

    // Vérifier si une boîte est en collision avec la forme
    bool intersects(const BlockBox& box) const {
        for (const auto& fullBox : fullBoxes) {
            if (doBoxesIntersect(box, fullBox)) {
                return true;
            }
        }
        return false;
    }

    // Obtenir les limites de la forme
    std::vector<int> getX() const {
        std::vector<int> result;
        for (const auto& box : fullBoxes) {
            result.push_back(box.minX);
            result.push_back(box.maxX);
        }
        return result;
    }

    std::vector<int> getY() const {
        std::vector<int> result;
        for (const auto& box : fullBoxes) {
            result.push_back(box.minY);
            result.push_back(box.maxY);
        }
        return result;
    }

    std::vector<int> getZ() const {
        std::vector<int> result;
        for (const auto& box : fullBoxes) {
            result.push_back(box.minZ);
            result.push_back(box.maxZ);
        }
        return result;
    }

    int getLastX() const {
        int maxX = fullBoxes.empty() ? 0 : fullBoxes[0].maxX;
        for (const auto& box : fullBoxes) {
            maxX = std::max(maxX, box.maxX);
        }
        return maxX;
    }

    int getLastY() const {
        int maxY = fullBoxes.empty() ? 0 : fullBoxes[0].maxY;
        for (const auto& box : fullBoxes) {
            maxY = std::max(maxY, box.maxY);
        }
        return maxY;
    }

    int getLastZ() const {
        int maxZ = fullBoxes.empty() ? 0 : fullBoxes[0].maxZ;
        for (const auto& box : fullBoxes) {
            maxZ = std::max(maxZ, box.maxZ);
        }
        return maxZ;
    }

    bool isNull() const {
        return fullBoxes.empty();
    }

    std::vector<BlockBox> fullBoxes;

private:
    // Vérifier si deux boîtes se chevauchent
    static bool doBoxesIntersect(const BlockBox& box1, const BlockBox& box2) {
        return box1.maxX >= box2.minX && box1.minX < box2.maxX &&
               box1.maxZ >= box2.minZ && box1.minZ < box2.maxZ &&
               box1.maxY >= box2.minY && box1.minY < box2.maxY;
    }
}; 