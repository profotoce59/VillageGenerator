#pragma once

// Forward declarations
enum class BlockRotation;

// Position structure
struct BPos {
    int x, y, z;

    BPos(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}

    BPos add(int dx, int dy, int dz) const {
        return BPos(x + dx, y + dy, z + dz);
    }

    static BPos fromChunk(int chunkX, int y, int chunkZ) {
        return BPos(chunkX << 4, y, chunkZ << 4); // chunk * 16
    }
};

// Bounding box structure
struct BlockBox {
    int minX, minY, minZ;
    int maxX, maxY, maxZ;

    BlockBox(int minX, int minY, int minZ, int maxX, int maxY, int maxZ)
        : minX(minX), minY(minY), minZ(minZ), maxX(maxX), maxY(maxY), maxZ(maxZ) {}

    bool contains(const BPos& pos) const;
    void move(int dx, int dy, int dz);

    // Décalage par un ancrage
    BlockBox offset(int dx, int dy, int dz) const {
        return BlockBox(minX + dx, minY + dy, minZ + dz,
                        maxX + dx, maxY + dy, maxZ + dz);
    }

    static BlockBox getBoundingBox(const BPos& anchor,
                                    BlockRotation rot,
                                    const BPos& size);
};
