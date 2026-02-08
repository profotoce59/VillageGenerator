#pragma once

#include <vector>
#include <unordered_map>
#include <cstdint>
#include <algorithm>
#include "VillageGenerator.hpp"

// Classe pour gérer les collisions entre les pièces du village
class VoxelShape {
public:
    VoxelShape() : bounds(0,0,0,0,0,0), hasBounds(false) {}

    // Constructeur avec bounds (limite externe du village)
    explicit VoxelShape(const BlockBox& bounds) : bounds(bounds), hasBounds(true) {}

    // Définir les limites externes (la pièce doit être DANS cette zone)
    void setBounds(const BlockBox& b) {
        bounds = b;
        hasBounds = true;
    }

    // Java: setValue sets the bounds (xs, ys, zs), NOT the fullBoxes
    // xs = [box.minX, box.maxX+1], etc.
    void setValue(const BlockBox& box, bool value) {
        if (value) {
            // Set bounds with +1 on max values (like Java)
            bounds = BlockBox(box.minX, box.minY, box.minZ,
                             box.maxX + 1, box.maxY + 1, box.maxZ + 1);
            hasBounds = true;
        }
    }

    // Ajouter une boîte de collision (pièce placée) - Java: fullBoxes.add()
    void addCollision(const BlockBox& box) {
        fullBoxes.push_back(box);
        lastVisited.push_back(0);
        addToGrid(static_cast<int>(fullBoxes.size() - 1), box);
    }

    // Vérifier si une boîte est en collision avec les pièces existantes
    // ET si elle est dans les limites du village
    bool intersects(const BlockBox& box) const {
        return intersects(box, nullptr);
    }

    bool intersects(const BlockBox& box, uint64_t* boxesScanned) const {
        if (fullBoxes.empty()) return false;
        if (!useGrid) {
            for (const auto& placed : fullBoxes) {
                if (boxesScanned) (*boxesScanned)++;
                if (doBoxesIntersect(box, placed)) {
                    return true;
                }
            }
            return false;
        }

        int minX = box.minX;
        int minY = box.minY;
        int minZ = box.minZ;
        int maxX = box.maxX;
        int maxY = box.maxY;
        int maxZ = box.maxZ;
        if (maxX < minX || maxY < minY || maxZ < minZ) return false;

        int cminX = cellCoord(minX);
        int cmaxX = cellCoord(maxX);
        int cminY = cellCoord(minY);
        int cmaxY = cellCoord(maxY);
        int cminZ = cellCoord(minZ);
        int cmaxZ = cellCoord(maxZ);

        uint32_t qid = ++queryId;
        if (qid == 0) { // overflow, reset
            std::fill(lastVisited.begin(), lastVisited.end(), 0);
            qid = ++queryId;
        }

        for (int cx = cminX; cx <= cmaxX; ++cx) {
            for (int cy = cminY; cy <= cmaxY; ++cy) {
                for (int cz = cminZ; cz <= cmaxZ; ++cz) {
                    CellKey key{cx, cy, cz};
                    auto it = grid.find(key);
                    if (it == grid.end()) continue;
                    const std::vector<int>& list = it->second;
                    for (int idx : list) {
                        if (idx < 0 || idx >= (int)fullBoxes.size()) continue;
                        if (lastVisited[static_cast<size_t>(idx)] == qid) continue;
                        lastVisited[static_cast<size_t>(idx)] = qid;
                        if (boxesScanned) (*boxesScanned)++;
                        if (doBoxesIntersect(box, fullBoxes[static_cast<size_t>(idx)])) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }


    // Vérifie si la box est dans les limites du village
    bool isWithinBounds(const BlockBox& box) const {
        if (!hasBounds) return true;
        return box.minX >= bounds.minX && box.maxX <= bounds.maxX &&
               box.minY >= bounds.minY && box.maxY <= bounds.maxY &&
               box.minZ >= bounds.minZ && box.maxZ <= bounds.maxZ;
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

    // Java: isNull() checks if xs (bounds) is null, NOT fullBoxes
    bool isNull() const {
        return !hasBounds;
    }

    std::vector<BlockBox> fullBoxes;
    BlockBox bounds;
    bool hasBounds;

private:
    struct CellKey {
        int x;
        int y;
        int z;
        bool operator==(const CellKey& other) const {
            return x == other.x && y == other.y && z == other.z;
        }
    };

    struct CellKeyHash {
        size_t operator()(const CellKey& k) const {
            size_t h = std::hash<int>()(k.x);
            h = h * 1315423911u + std::hash<int>()(k.y);
            h = h * 1315423911u + std::hash<int>()(k.z);
            return h;
        }
    };

    static constexpr int CELL_SIZE = 16;
    static constexpr bool useGrid = true;

    static int floorDiv(int x, int s) {
        if (x >= 0) return x / s;
        return -(( -x + s - 1) / s);
    }

    static int cellCoord(int x) {
        return floorDiv(x, CELL_SIZE);
    }

    void addToGrid(int idx, const BlockBox& box) {
        if (!useGrid) return;
        int minX = box.minX;
        int minY = box.minY;
        int minZ = box.minZ;
        int maxX = box.maxX;
        int maxY = box.maxY;
        int maxZ = box.maxZ;
        if (maxX < minX || maxY < minY || maxZ < minZ) return;

        int cminX = cellCoord(minX);
        int cmaxX = cellCoord(maxX);
        int cminY = cellCoord(minY);
        int cmaxY = cellCoord(maxY);
        int cminZ = cellCoord(minZ);
        int cmaxZ = cellCoord(maxZ);

        for (int cx = cminX; cx <= cmaxX; ++cx) {
            for (int cy = cminY; cy <= cmaxY; ++cy) {
                for (int cz = cminZ; cz <= cmaxZ; ++cz) {
                    grid[CellKey{cx, cy, cz}].push_back(idx);
                }
            }
        }
    }

    // Vérifier si deux boîtes se chevauchent
    static bool doBoxesIntersect(const BlockBox& box1, const BlockBox& box2) {
        return box1.maxX >= box2.minX && box1.minX < box2.maxX &&
               box1.maxZ >= box2.minZ && box1.minZ < box2.maxZ &&
               box1.maxY >= box2.minY && box1.minY < box2.maxY;
    }

    std::unordered_map<CellKey, std::vector<int>, CellKeyHash> grid;
    mutable std::vector<uint32_t> lastVisited;
    mutable uint32_t queryId = 0;
};
