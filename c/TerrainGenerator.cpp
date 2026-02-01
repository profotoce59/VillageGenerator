#include "TerrainGenerator.hpp"
#include "BiomeSource.hpp"
#include <cmath>

extern "C" {
    #include "surface_gen.h"
}

// =============== TerrainGenerator (classe de base) ===============

TerrainGenerator::TerrainGenerator(uint64_t worldSeed, std::unique_ptr<BiomeSource> biomeSource)
    : worldSeed(worldSeed), biomeSource(std::move(biomeSource)) {
}

// =============== OverworldTerrainGenerator ===============

OverworldTerrainGenerator::OverworldTerrainGenerator(uint64_t worldSeed, std::unique_ptr<BiomeSource> biomeSource)
    : TerrainGenerator(worldSeed, std::move(biomeSource)),
      heightScale(684.412),
      heightStretch(1.0),
      seaLevel(63) {

    // Initialiser le générateur de surface avec cubiomes
    // MC_1_16_1 = 19 (voir biomes.h de cubiomes - enum MCversion)
    surfaceGen = std::make_unique<SurfaceGenWrapper>(worldSeed, 19);
}

int OverworldTerrainGenerator::getFirstHeightInColumn(int x, int z, std::function<bool(void*)> predicate) {
    // Wrapper du prédicat C++ vers C
    // Pour simplifier, on utilise directement la fonction C avec un prédicat simple
    // TODO: Si besoin d'un prédicat personnalisé, créer un wrapper

    if (!predicate) {
        // Pas de prédicat spécifique, utiliser le défaut (premier bloc non-air)
        return surfaceGen->getHeightOnGround(x, z);
    }

    // Pour l'instant, utiliser le prédicat par défaut
    // Une implémentation plus complète nécessiterait de wrapper le std::function en BlockPredicate C
    return surfaceGen->getHeightOnGround(x, z);
}

int OverworldTerrainGenerator::getHeightOnGround(int x, int z) {
    return surfaceGen->getHeightOnGround(x, z);
}

std::vector<void*> OverworldTerrainGenerator::getColumnBlocks(int x, int z) {
    // TODO: Implémenter la génération complète de la colonne
    // Pour l'instant, retourner un vecteur vide
    return std::vector<void*>();
}

bool OverworldTerrainGenerator::canGenerate(int chunkX, int chunkZ) const {
    // Vérifier si un village peut se générer à cette position
    // Pour l'instant, toujours retourner true
    // TODO: Ajouter les vraies conditions de génération
    return true;
}

double OverworldTerrainGenerator::getNoise(int x, int z) const {
    // Méthode utilitaire pour obtenir le bruit à une position
    // TODO: Implémenter si nécessaire
    return 0.0;
}

void OverworldTerrainGenerator::generateTerrain(int x, int z, std::vector<void*>& blocks) {
    // Méthode utilitaire pour générer le terrain
    // TODO: Implémenter si nécessaire
}
