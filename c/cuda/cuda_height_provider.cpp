#include "cuda_height_provider.hpp"

#include <chrono>
#include <cstdio>

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

    double ms = std::chrono::duration<double, std::milli>(
        std::chrono::steady_clock::now() - t0).count();
    prefetchCount_++;
    prefetchMs_ += ms;
    if (ms < prefetchMinMs_) prefetchMinMs_ = ms;
    if (ms > prefetchMaxMs_) prefetchMaxMs_ = ms;
    pointsComputed_ += (long long)w * h;

    return ++generation_;
}
