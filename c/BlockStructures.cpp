#include "BlockStructures.hpp"
#include "BlockRotation.hpp"

bool BlockBox::contains(const BPos& pos) const {
    return pos.x >= minX && pos.x <= maxX &&
           pos.y >= minY && pos.y <= maxY &&
           pos.z >= minZ && pos.z <= maxZ;
}

void BlockBox::move(int dx, int dy, int dz) {
    minX += dx;
    minY += dy;
    minZ += dz;
    maxX += dx;
    maxY += dy;
    maxZ += dz;
}

BlockBox BlockBox::getBoundingBox(const BPos& anchor,
                                   BlockRotation rot,
                                   const BPos& size)
{
    BlockBox box = BlockBox(0, 0, 0, 0, 0, 0);

    switch (rot) {
        case BlockRotation::COUNTERCLOCKWISE_90: {
            int sx = size.z - 1;  // X <-> Z
            int sy = size.y - 1;
            int sz = size.x - 1;
            box = BlockBox(0, 0, -sz, sx, sy, 0);
            break;
        }

        case BlockRotation::CLOCKWISE_90: {
            int sx = size.z - 1;
            int sy = size.y - 1;
            int sz = size.x - 1;
            box = BlockBox(-sx, 0, 0, 0, sy, sz);
            break;
        }

        case BlockRotation::CLOCKWISE_180: {
            int sx = size.x - 1;
            int sy = size.y - 1;
            int sz = size.z - 1;
            box = BlockBox(-sx, 0, -sz, 0, sy, 0);
            break;
        }

        case BlockRotation::NONE:
        default: {
            int sx = size.x - 1;
            int sy = size.y - 1;
            int sz = size.z - 1;
            box = BlockBox(0, 0, 0, sx, sy, sz);
            break;
        }
    }

    return box.offset(anchor.x, anchor.y, anchor.z);
}
