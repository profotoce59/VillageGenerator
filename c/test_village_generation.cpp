#include "VillageGenerator.hpp"
#include "TerrainGenerator.hpp"
#include "BiomeSource.hpp"
#include "ChunkRand.hpp"

extern "C" {
    #include "finders.h"
}

#include <thread>
#include <mutex>
#include <atomic>
#include <chrono>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <csignal>
#include <vector>
#include <string>

// ── Globals ──────────────────────────────────────────────────────────
static std::mutex g_printMutex;
static std::atomic<uint64_t> g_totalVillagesChecked{0};
static std::atomic<bool> g_running{true};

static void signalHandler(int) {
    g_running.store(false, std::memory_order_relaxed);
}

static const char* BLACKSMITH_NAMES[] = {
    "desert/houses/desert_weaponsmith_1",
    "plains/houses/plains_weaponsmith_1",
    "taiga/houses/taiga_weaponsmith_1",
    "savanna/houses/savanna_weaponsmith_2",
    "snowy/houses/snowy_weapon_smith_1",
};
static constexpr int NUM_BS_NAMES = 5;

// ── Helpers ──────────────────────────────────────────────────────────
static int countBlacksmiths(const VillageGenerator& gen) {
    int count = 0;
    for (const auto& piece : gen.getPieces()) {
        for (int i = 0; i < NUM_BS_NAMES; i++) {
            if (piece->name == BLACKSMITH_NAMES[i]) {
                count++;
                break;
            }
        }
    }
    return count;
}

// ── Worker thread ────────────────────────────────────────────────────
struct WorkerParams {
    int threadId;
    int numThreads;
    uint64_t startStructureSeed;
    int numWorldSeeds;      // upper 16 bits to test per structure seed
    int numRegions;         // side length N -> N*N region positions
    int blacksmithThreshold;
};

static void workerThread(WorkerParams params) {
    // Open per-thread log file
    char logName[64];
    snprintf(logName, sizeof(logName), "log_thread_%d.txt", params.threadId);
    std::ofstream logFile(logName);

    auto startTime = std::chrono::steady_clock::now();
    auto lastLogTime = startTime;
    uint64_t localVillagesChecked = 0;

    const uint64_t MASK_48 = (1ULL << 48) - 1;

    for (uint64_t structureSeed = (params.startStructureSeed & MASK_48) + params.threadId;
         structureSeed <= MASK_48 && g_running.load(std::memory_order_relaxed);
         structureSeed += params.numThreads)
    {
        // 1. Compute village positions for this structure seed
        std::vector<Pos> villagePositions;
        villagePositions.reserve(params.numRegions * params.numRegions);

        for (int rx = 0; rx < params.numRegions; rx++) {
            for (int rz = 0; rz < params.numRegions; rz++) {
                Pos pos;
                if (getStructurePos(Village, MC_1_16, structureSeed, rx, rz, &pos)) {
                    // pos is in block coords, convert to chunk coords
                    Pos chunkPos;
                    chunkPos.x = pos.x >> 4;
                    chunkPos.z = pos.z >> 4;
                    villagePositions.push_back(chunkPos);
                }
            }
        }

        // 2. For each world seed (upper bits)
        for (int upperBits = 0; upperBits < params.numWorldSeeds; upperBits++) {
            uint64_t worldSeed = structureSeed | ((uint64_t)upperBits << 48);

            // Create terrain generator
            auto biomeSource = std::make_unique<SimpleBiomeSource>(worldSeed);
            OverworldTerrainGenerator terrainGen(worldSeed, std::move(biomeSource));

            // 3. For each village position
            for (const Pos& vPos : villagePositions) {
                VillageGenerator villeGen;
                ChunkRand rand;

                if (!villeGen.generate(&terrainGen, vPos.x, vPos.z, rand))
                    continue;

                localVillagesChecked++;

                int numBS = countBlacksmiths(villeGen);
                if (numBS > params.blacksmithThreshold) {
                    std::lock_guard<std::mutex> lock(g_printMutex);
                    printf("[FOUND] worldSeed: %lld | pos: /tp %d 80 %d | blacksmiths: %d | structureSeed: %llu\n",
                           (long long)worldSeed,
                           vPos.x * 16, vPos.z * 16,
                           numBS,
                           (unsigned long long)structureSeed);
                    fflush(stdout);

                    logFile << "[FOUND] worldSeed: " << (long long)worldSeed
                            << " pos: " << vPos.x * 16 << " 80 " << vPos.z * 16
                            << " blacksmiths: " << numBS
                            << " structureSeed: " << structureSeed << "\n";
                    logFile.flush();
                }

                // Periodic logging (every 60 seconds)
                auto now = std::chrono::steady_clock::now();
                auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - lastLogTime).count();
                if (elapsed >= 60) {
                    lastLogTime = now;
                    g_totalVillagesChecked += localVillagesChecked;
                    uint64_t snapshotLocal = localVillagesChecked;
                    localVillagesChecked = 0;

                    auto totalElapsed = std::chrono::duration_cast<std::chrono::seconds>(now - startTime).count();

                    double villagesPerSec = (elapsed > 0) ? (double)snapshotLocal / elapsed : 0.0;

                    {
                        std::lock_guard<std::mutex> lock(g_printMutex);
                        printf("[thread %d] %llu villages (%.1f/s) | structureSeed: %llu | elapsed: %llds\n",
                               params.threadId,
                               (unsigned long long)snapshotLocal,
                               villagesPerSec,
                               (unsigned long long)structureSeed,
                               (long long)totalElapsed);
                        fflush(stdout);
                    }

                    logFile << "[LOG] " << snapshotLocal << " villages (" << villagesPerSec << "/s) | structureSeed: "
                            << structureSeed << " | elapsed: " << totalElapsed << "s\n";
                    logFile.flush();
                }
            }
        }
    }

    // Final count
    g_totalVillagesChecked += localVillagesChecked;
    if (!g_running.load(std::memory_order_relaxed))
        logFile << "[STOPPED] thread " << params.threadId << " at structureSeed ~" << ((params.startStructureSeed & MASK_48) + params.threadId) << "+\n";
    else
        logFile << "[DONE] thread " << params.threadId << " finished.\n";
}

// ── Main ─────────────────────────────────────────────────────────────
int main(int argc, char* argv[]) {
    if (argc < 5) {
        printf("Usage: %s <num_threads> <start_structure_seed> <num_worldseeds> <num_regions> [blacksmith_threshold=6]\n", argv[0]);
        printf("\n");
        printf("  num_threads          : number of worker threads\n");
        printf("  start_structure_seed : 48-bit starting structure seed\n");
        printf("  num_worldseeds       : number of worldseeds per structure seed (upper bits, max 65536)\n");
        printf("  num_regions          : side length N -> checks N*N region positions per worldseed\n");
        printf("  blacksmith_threshold : min blacksmiths to report (default: 6)\n");
        return 1;
    }

    int numThreads = atoi(argv[1]);
    uint64_t startSeed = strtoull(argv[2], nullptr, 10);
    int numWorldSeeds = atoi(argv[3]);
    int numRegions = atoi(argv[4]);
    int threshold = (argc >= 6) ? atoi(argv[5]) : 6;

    std::signal(SIGINT, signalHandler);
    std::signal(SIGTERM, signalHandler);

    printf("=== Village Generation Search (Ctrl+C to stop) ===\n");
    printf("Threads:          %d\n", numThreads);
    printf("Start seed:       %llu\n", (unsigned long long)startSeed);
    printf("WorldSeeds/struct: %d\n", numWorldSeeds);
    printf("Regions:          %d x %d = %d positions\n", numRegions, numRegions, numRegions * numRegions);
    printf("BS threshold:     > %d\n", threshold);
    printf("================================\n\n");

    std::vector<std::thread> threads;
    threads.reserve(numThreads);

    for (int i = 0; i < numThreads; i++) {
        WorkerParams params;
        params.threadId = i;
        params.numThreads = numThreads;
        params.startStructureSeed = startSeed;
        params.numWorldSeeds = numWorldSeeds;
        params.numRegions = numRegions;
        params.blacksmithThreshold = threshold;

        threads.emplace_back(workerThread, params);
    }

    for (auto& t : threads) {
        t.join();
    }

    if (!g_running.load())
        printf("\n=== Stopped by user (Ctrl+C). Total villages checked: %llu ===\n",
               (unsigned long long)g_totalVillagesChecked.load());
    else
        printf("\n=== Done. Total villages checked: %llu ===\n",
               (unsigned long long)g_totalVillagesChecked.load());

    return 0;
}
