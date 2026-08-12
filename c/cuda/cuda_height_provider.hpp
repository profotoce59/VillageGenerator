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
        return heights_[(size_t)iz * w_ + ix];
    }

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
    double prefetchMs()     const { return prefetchMs_; }
    double prefetchMinMs()  const { return prefetchCount_ ? prefetchMinMs_ : 0.0; }
    double prefetchMaxMs()  const { return prefetchMaxMs_; }
    long long pointsComputed() const { return pointsComputed_; }
    void resetStats() {
        prefetchCount_ = 0; prefetchMs_ = 0.0; pointsComputed_ = 0;
        prefetchMinMs_ = 1e30; prefetchMaxMs_ = 0.0;
        gpuUploadMs_ = gpuColumnsMs_ = gpuHeightsMs_ = gpuDownloadMs_ = 0.0;
    }

private:
    std::unique_ptr<CudaHeightBatcher> batcher_;
    std::vector<int> heights_;
    int x0_ = 0, z0_ = 0, w_ = 0, h_ = 0;
    uint64_t generation_ = 0;

    int       prefetchCount_  = 0;
    double    prefetchMs_     = 0.0;
    double    prefetchMinMs_  = 1e30;
    double    prefetchMaxMs_  = 0.0;
    long long pointsComputed_ = 0;
    double    gpuUploadMs_ = 0.0, gpuColumnsMs_ = 0.0;
    double    gpuHeightsMs_ = 0.0, gpuDownloadMs_ = 0.0;
};
