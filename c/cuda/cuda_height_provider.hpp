#pragma once

/**
 * cuda_height_provider.hpp — HeightProvider adossé au GPU.
 *
 * Se branche sur SurfaceGenWrapper via setHeightProvider(). À chaque village,
 * l'Assembler appelle prefetchRegion() avec la zone bornée du village ; on
 * calcule la heightmap complète en un lancement CUDA, puis les ~200 requêtes
 * du jigsaw sont de simples lectures de tableau.
 *
 * Le CudaHeightBatcher est recréé quand la seed ou startSizeY changent (une
 * fois par village), mais les buffers device sont réutilisés.
 */

#include "village_noise_host.hpp"
#include "../SurfaceGenWrapper.hpp"

#include <cstdint>
#include <memory>
#include <vector>

class CudaHeightProvider : public HeightProvider {
public:
    CudaHeightProvider() = default;

    uint64_t prefetch(SurfaceGen* sg, int x0, int z0, int w, int h) override;
    uint64_t currentGeneration() const override { return generation_; }
    int      lookup(int x, int z) const override
    {
        int ix = x - x0_, iz = z - z0_;
        if (ix < 0 || iz < 0 || ix >= w_ || iz >= h_) return -1;
        int h = heights_[(size_t)iz * w_ + ix];
        // Hauteur collée au plafond du scan : le terrain dépasse la plage, et
        // le chemin C doit reprendre avec un startSizeY plus grand (ce que le
        // kernel, à startSizeY fixe, ne sait pas faire). On renvoie -1 pour
        // forcer le repli.
        if (h >= ceilingHeight_) return -1;
        if (trackRadius_ > 0) noteUsage(x, z);
        return h;
    }

    // ---- étude de couverture (désactivée par défaut) -------------------
    // Enregistre quelles cellules de bruit sont réellement consultées autour du
    // centre du village, pour savoir si une zone plus petite ou d'une autre
    // forme suffirait. Coût : une branche par lookup quand c'est éteint.
    void enableUsageTracking(int radiusCells);
    int  trackRadius()        const { return trackRadius_; }
    long villagesTracked()    const { return villagesTracked_; }
    long uniqueColumnsUsed()  const { return uniqueColumnsUsed_; }
    long columnsComputed()    const { return columnsComputed_; }
    // aggregate_[(dz+R)*(2R+1) + (dx+R)] = nombre de villages ayant utilisé
    // la cellule à cet écart du centre.
    const std::vector<uint32_t>& usageMap() const { return aggregate_; }

    // Temps GPU cumulés (événements CUDA), pour distinguer le temps de calcul
    // réel du surcoût de lancement/synchronisation côté hôte.
    double gpuUploadMs()  const { return gpuUploadMs_; }
    double gpuColumnsMs() const { return gpuColumnsMs_; }
    double gpuHeightsMs() const { return gpuHeightsMs_; }
    double gpuDownloadMs()const { return gpuDownloadMs_; }
    double gpuTotalMs()   const {
        return gpuUploadMs_ + gpuColumnsMs_ + gpuHeightsMs_ + gpuDownloadMs_;
    }

    // Diagnostics cumulés
    int    prefetchCount()  const { return prefetchCount_; }
    int    extendCount()    const { return extendCount_; }
    double prefetchMs()     const { return prefetchMs_; }
    double prefetchMinMs()  const { return prefetchCount_ ? prefetchMinMs_ : 0.0; }
    double prefetchMaxMs()  const { return prefetchMaxMs_; }
    long long pointsComputed() const { return pointsComputed_; }
    void resetStats() {
        prefetchCount_ = 0; prefetchMs_ = 0.0; pointsComputed_ = 0;
        prefetchMinMs_ = 1e30; prefetchMaxMs_ = 0.0;
        gpuUploadMs_ = gpuColumnsMs_ = gpuHeightsMs_ = gpuDownloadMs_ = 0.0;
        extendCount_ = 0;
    }

private:
    void noteUsage(int x, int z) const;
    void flushVillageUsage() const;

    std::unique_ptr<CudaHeightBatcher> batcher_;
    std::vector<int> heights_;

    // Suivi de couverture. mutable : lookup() est const par contrat d'interface.
    int  trackRadius_ = 0;
    int  cellCenterX_ = 0, cellCenterZ_ = 0;
    mutable std::vector<uint8_t>  perVillage_;
    mutable std::vector<uint32_t> aggregate_;
    mutable long villagesTracked_   = 0;
    mutable long uniqueColumnsUsed_ = 0;
    mutable long columnsComputed_   = 0;
    mutable bool villageHasUsage_   = false;
    int x0_ = 0, z0_ = 0, w_ = 0, h_ = 0;
    int ceilingHeight_ = INT32_MAX;   // startSizeY * chunkHeight de la zone
    // Extension incrementale apres une reprise de scan : evite de recalculer
    // toute la zone alors qu'il ne manque que quelques cellules en hauteur.
    bool canExtend_ = false;
    int  extendFromStartSizeY_ = -1;
    int  extendCount_ = 0;
    uint64_t lastSeed_ = 0;
    uint64_t generation_ = 0;

    int       prefetchCount_  = 0;
    double    prefetchMs_     = 0.0;
    double    prefetchMinMs_  = 1e30;
    double    prefetchMaxMs_  = 0.0;
    long long pointsComputed_ = 0;
    double    gpuUploadMs_ = 0.0, gpuColumnsMs_ = 0.0;
    double    gpuHeightsMs_ = 0.0, gpuDownloadMs_ = 0.0;
};
