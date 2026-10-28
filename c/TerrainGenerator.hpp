#pragma once

#include "Biome.hpp"
#include "SurfaceGenWrapper.hpp"
#include <memory>
#include <functional>
#include <vector>

class BiomeSource;
// Note: Block is defined in surface_gen.h (C enum), not as a C++ class
// We use void* for now to avoid conflicts
// class Block;

class TerrainGenerator {
public:
    static constexpr int WORLD_SURFACE_WG = 0;
    
    TerrainGenerator(uint64_t worldSeed, std::unique_ptr<BiomeSource> biomeSource);
    virtual ~TerrainGenerator() = default;

    // Getters
    uint64_t getWorldSeed() const { return worldSeed; }
    BiomeSource* getBiomeSource() const { return biomeSource.get(); }

    // Terrain generation methods
    virtual int getFirstHeightInColumn(int x, int z, std::function<bool(void*)> predicate) = 0;
    virtual int getHeightOnGround(int x, int z) = 0;
    virtual void setHeightMapStartSizeY(int startSizeYBlocks) { (void)startSizeYBlocks; }
    
    // Utility methods
    virtual std::vector<void*> getColumnBlocks(int x, int z) = 0;
    virtual bool canGenerate(int chunkX, int chunkZ) const = 0;

protected:
    uint64_t worldSeed;
    std::unique_ptr<BiomeSource> biomeSource;
};

// Classe concrète pour la génération du monde normal (Overworld)
class OverworldTerrainGenerator : public TerrainGenerator {
public:
    OverworldTerrainGenerator(uint64_t worldSeed, std::unique_ptr<BiomeSource> biomeSource);

    int getFirstHeightInColumn(int x, int z, std::function<bool(void*)> predicate) override;
    int getHeightOnGround(int x, int z) override;
    void setHeightMapStartSizeY(int startSizeYBlocks) override;
    std::vector<void*> getColumnBlocks(int x, int z) override;
    bool canGenerate(int chunkX, int chunkZ) const override;

private:
    // Générateur de surface utilisant cubiomes
    std::unique_ptr<SurfaceGenWrapper> surfaceGen;

    // Paramètres de génération du terrain
    double heightScale;
    double heightStretch;
    int seaLevel;

    // Méthodes privées pour la génération
    double getNoise(int x, int z) const;
    void generateTerrain(int x, int z, std::vector<void*>& blocks);
}; 
