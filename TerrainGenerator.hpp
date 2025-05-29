#pragma once

#include "Biome.hpp"
#include <memory>
#include <functional>
#include <vector>

class BiomeSource;
class Block;

class TerrainGenerator {
public:
    static constexpr int WORLD_SURFACE_WG = 0;
    
    TerrainGenerator(uint64_t worldSeed, std::unique_ptr<BiomeSource> biomeSource);
    virtual ~TerrainGenerator() = default;

    // Getters
    uint64_t getWorldSeed() const { return worldSeed; }
    BiomeSource* getBiomeSource() const { return biomeSource.get(); }

    // Terrain generation methods
    virtual int getFirstHeightInColumn(int x, int z, std::function<bool(Block*)> predicate) = 0;
    virtual int getHeightOnGround(int x, int z) = 0;
    
    // Utility methods
    virtual std::vector<Block*> getColumnBlocks(int x, int z) = 0;
    virtual bool canGenerate(int chunkX, int chunkZ) const = 0;

protected:
    uint64_t worldSeed;
    std::unique_ptr<BiomeSource> biomeSource;
};

// Classe concrète pour la génération du monde normal (Overworld)
class OverworldTerrainGenerator : public TerrainGenerator {
public:
    OverworldTerrainGenerator(uint64_t worldSeed, std::unique_ptr<BiomeSource> biomeSource);
    
    int getFirstHeightInColumn(int x, int z, std::function<bool(Block*)> predicate) override;
    int getHeightOnGround(int x, int z) override;
    std::vector<Block*> getColumnBlocks(int x, int z) override;
    bool canGenerate(int chunkX, int chunkZ) const override;

private:
    // Paramètres de génération du terrain
    double heightScale;
    double heightStretch;
    int seaLevel;
    
    // Méthodes privées pour la génération
    double getNoise(int x, int z) const;
    void generateTerrain(int x, int z, std::vector<Block*>& blocks);
}; 