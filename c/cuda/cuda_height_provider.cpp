#include "cuda_height_provider.hpp"

#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdio>

void CudaHeightProvider::enableUsageTracking(int radiusCells)
{
    trackRadius_ = radiusCells;
    if (radiusCells <= 0) return;
    const size_t side = (size_t)(2 * radiusCells + 1);
    perVillage_.assign(side * side, 0);
    aggregate_.assign(side * side, 0u);
    villagesTracked_ = uniqueColumnsUsed_ = columnsComputed_ = 0;
    villageHasUsage_ = false;
}

// Marque les 4 colonnes d'angle dont dépend une requête en (x, z).
void CudaHeightProvider::noteUsage(int x, int z) const
{
    const int R = trackRadius_, side = 2 * R + 1;
    const int cellX = (int)std::floor((double)x / 4.0);
    const int cellZ = (int)std::floor((double)z / 4.0);
    for (int c = 0; c < 4; c++) {
        int dx = cellX + (c >> 1) - cellCenterX_;
        int dz = cellZ + (c & 1)  - cellCenterZ_;
        if (dx < -R || dx > R || dz < -R || dz > R) continue;
        size_t idx = (size_t)(dz + R) * side + (dx + R);
        if (!perVillage_[idx]) {
            perVillage_[idx] = 1;
            aggregate_[idx]++;
            uniqueColumnsUsed_++;
            villageHasUsage_ = true;
        }
    }
}

// Clôture le village courant : remet la carte par village à zéro.
void CudaHeightProvider::flushVillageUsage() const
{
    if (villageHasUsage_) {
        villagesTracked_++;
        std::fill(perVillage_.begin(), perVillage_.end(), (uint8_t)0);
        villageHasUsage_ = false;
    }
}

uint64_t CudaHeightProvider::prefetch(SurfaceGen* sg, int x0, int z0, int w, int h)
{
    if (!sg || w <= 0 || h <= 0) return 0;

    CubiomesContext* ctx = (CubiomesContext*)sg->user;
    if (!ctx) return 0;

    auto t0 = std::chrono::steady_clock::now();

    // L'Assembler crée un SurfaceGenWrapper (donc un CubiomesContext ET un
    // SurfaceGen, alloués séparément) par village. On réassocie systématiquement :
    // toute tentative de réutilisation conditionnelle est un piège, parce que
    // malloc recycle les adresses et que le batcher garde ces pointeurs. Une
    // clé qui semblait suffisante (adresse du contexte + seed + startSizeY)
    // laissait passer le cas « même adresse de contexte, autre SurfaceGen » :
    // le batcher lisait alors un startSizeY libéré, ce qui décale le sommet de
    // la colonne de bruit et fausse la hauteur d'un cran.
    // bind() ne fait qu'un ré-upload (~18 Ko), négligeable devant le calcul.
    if (!batcher_) {
        batcher_ = std::make_unique<CudaHeightBatcher>(ctx, sg);
        if (!batcher_->isValid()) {
            batcher_.reset();
            return 0;
        }
    } else if (!batcher_->bind(ctx, sg)) {
        batcher_.reset();
        return 0;
    }

    heights_.resize((size_t)w * h);
    if (batcher_->heightmap(x0, z0, w, h, HEIGHT_PRED_NOT_AIR, heights_.data()) != 0) {
        // Échec GPU : on invalide, l'appelant retombera sur le C.
        heights_.clear();
        w_ = h_ = 0;
        return 0;
    }

    x0_ = x0; z0_ = z0; w_ = w; h_ = h;

    // Nouvelle zone = nouveau village : on clôt le suivi du précédent.
    if (trackRadius_ > 0) {
        flushVillageUsage();
        cellCenterX_ = (int)std::floor((x0 + w / 2.0) / 4.0);
        cellCenterZ_ = (int)std::floor((z0 + h / 2.0) / 4.0);
        columnsComputed_ += (long)batcher_->lastColumnCount();
    }

    {   // temps GPU réels du lancement, mesurés par événements CUDA
        float up = 0, cols = 0, hts = 0, dl = 0;
        batcher_->lastGpuTimings(&up, &cols, &hts, &dl);
        gpuUploadMs_   += up;
        gpuColumnsMs_  += cols;
        gpuHeightsMs_  += hts;
        gpuDownloadMs_ += dl;
    }

    double ms = std::chrono::duration<double, std::milli>(
        std::chrono::steady_clock::now() - t0).count();
    prefetchCount_++;
    prefetchMs_ += ms;
    if (ms < prefetchMinMs_) prefetchMinMs_ = ms;
    if (ms > prefetchMaxMs_) prefetchMaxMs_ = ms;
    pointsComputed_ += (long long)w * h;

    return ++generation_;
}
