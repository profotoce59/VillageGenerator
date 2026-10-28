#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <vector>
#include <chrono>
#include <cstdio>
#if defined(_WIN32)
#include <windows.h>
#include <psapi.h>
#elif defined(__APPLE__)
#include <mach/mach.h>
#include <sys/resource.h>
#include <unistd.h>
#else
#include <sys/resource.h>
#include <unistd.h>
#endif

#include "VillageGenerator.hpp"
#include "TerrainGenerator.hpp"
#include "BiomeSource.hpp"
#include "ChunkRand.hpp"
#include "SurfaceGenWrapper.hpp"

extern "C" {
    #include "finders.h"
    #include "surface_gen.h"
}


static void buildVillagePositions(uint64_t structureSeed, std::vector<Pos>& out, int maxPositions) {
    out.clear();
    out.reserve(static_cast<size_t>(maxPositions));
    for (int rx = 0; rx < 10 && (int)out.size() < maxPositions; rx++) {
        for (int rz = 0; rz < 10 && (int)out.size() < maxPositions; rz++) {
            Pos p;
            if (getStructurePos(Village, MC_1_16, structureSeed, rx, rz, &p)) {
                Pos chunkPos;
                chunkPos.x = p.x >> 4;
                chunkPos.z = p.z >> 4;
                out.push_back(chunkPos);
            }
        }
    }
}

static void checkWorldSeed(uint64_t structureSeed,
                           const std::vector<Pos>& posList,
                           uint64_t maxWorldSeeds,
                           bool filterTaiga,
                           bool filterSmith,
                           bool logEach,
                           uint64_t* generatedVillages,
                           uint64_t* totalPieces) {
    structureSeed &= MASK48;
    VillageGenerator villageGen;

    for (uint64_t seed = 0; seed < maxWorldSeeds; seed++) {
        uint64_t worldSeed = structureSeed | (seed << 48);

        Generator g;
        setupGenerator(&g, MC_1_16, 0);
        applySeed(&g, DIM_OVERWORLD, worldSeed);
        auto biomeSource = std::make_unique<SimpleBiomeSource>(worldSeed);
        auto terrainGen = std::make_unique<OverworldTerrainGenerator>(worldSeed, std::move(biomeSource));

        for (const Pos& sPos : posList) {
            int bx = sPos.x << 4;
            int bz = sPos.z << 4;

            bool viable = isViableStructurePos(Village, &g, bx, bz, 0);
            if (!viable) continue;

            ChunkRand rand;
            bool ok = villageGen.generate(terrainGen.get(), sPos.x, sPos.z, rand, nullptr, true, false);
            if (!ok) continue;
            const auto& pieces = villageGen.getPieces();
            size_t pieceCount = pieces.size();
            if (filterTaiga) {
                Biome* biomeAt = terrainGen->getBiomeSource()->getBiomeForNoiseGen((sPos.x << 2) + 2, 0, (sPos.z << 2) + 2);
                if (!biomeAt || biomeAt->getType() != Biome::Type::TAIGA) {
                    continue;
                }
            }

            if (generatedVillages) (*generatedVillages)++;
            if (totalPieces) (*totalPieces) += static_cast<uint64_t>(pieceCount);

            if (logEach) {
                std::cout << "VILLAGE " << structureSeed << " " << worldSeed
                          << " " << sPos.x << " " << sPos.z
                          << " " << pieceCount << std::endl;
            }

            if (filterSmith) {
                int smithCount = 0;
                for (const auto& piece : pieces) {
                    const std::string& name = piece->name;
                    if (name == "plains/houses/plains_weaponsmith_1" ||
                        name == "taiga/houses/taiga_weaponsmith_1" ||
                        name == "savanna/houses/savanna_weaponsmith_2" ||
                        name == "desert/houses/desert_weaponsmith_1") {
                        smithCount++;
                    }
                }
                if (smithCount > 6 || pieceCount >= 250) {
                    int blockX = sPos.x << 4;
                    int blockZ = sPos.z << 4;
                    std::cout << "structureSeed=" << structureSeed
                              << " worldSeed=" << worldSeed
                              << " chunk=(" << sPos.x << "," << sPos.z << ")"
                              << " block=(" << blockX << "," << blockZ << ")"
                              << " pieces=" << pieceCount
                              << " blacksmith=" << smithCount
                              << std::endl;
                }
            }
        }

        freeLayerCaches(&g);
    }
}

static long getMaxRssKb() {
#if defined(_WIN32)
    PROCESS_MEMORY_COUNTERS pmc;
    if (GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc)))
        return static_cast<long>(pmc.PeakWorkingSetSize / 1024);
    return -1;
#elif defined(__APPLE__)
    struct rusage usage {};
    if (getrusage(RUSAGE_SELF, &usage) != 0) return -1;
    return static_cast<long>(usage.ru_maxrss / 1024);
#else
    struct rusage usage {};
    if (getrusage(RUSAGE_SELF, &usage) != 0) return -1;
    return static_cast<long>(usage.ru_maxrss);
#endif
}

static long getCurrentRssKb() {
#if defined(_WIN32)
    PROCESS_MEMORY_COUNTERS pmc;
    if (GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc)))
        return static_cast<long>(pmc.WorkingSetSize / 1024);
    return -1;
#elif defined(__APPLE__)
    mach_task_basic_info info;
    mach_msg_type_number_t count = MACH_TASK_BASIC_INFO_COUNT;
    if (task_info(mach_task_self(), MACH_TASK_BASIC_INFO, (task_info_t)&info, &count) != KERN_SUCCESS)
        return -1;
    return static_cast<long>(info.resident_size / 1024);
#elif defined(__linux__)
    FILE* f = std::fopen("/proc/self/statm", "r");
    if (!f) return -1;
    long pages = 0;
    if (std::fscanf(f, "%*s%ld", &pages) != 1) {
        std::fclose(f);
        return -1;
    }
    std::fclose(f);
    long pageSize = sysconf(_SC_PAGESIZE);
    if (pageSize <= 0) return -1;
    return (pages * pageSize) / 1024;
#else
    return -1;
#endif
}

int main(int argc, char** argv) {
    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " <startingPoint> <index> <totalThreads> [maxStructureSeeds] [maxPositions] [maxWorldSeeds] [filterTaiga] [filterSmith] [logEach]\n";
        return 1;
    }

    uint64_t startingPoint = std::strtoull(argv[1], nullptr, 10) & MASK48;
    uint64_t offset = std::strtoull(argv[2], nullptr, 10);
    uint64_t totalThreads = std::strtoull(argv[3], nullptr, 10);
    if (totalThreads == 0) {
        std::cerr << "totalThreads must be > 0\n";
        return 1;
    }
    uint64_t maxStructureSeeds = 1000000000;
    int maxPositions = 3000;
    uint64_t maxWorldSeeds = 1ULL << 5;
    bool filterTaiga = true;
    bool filterSmith = true;
    bool logEach = false;
    if (argc >= 5) maxStructureSeeds = std::strtoull(argv[4], nullptr, 10);
    if (argc >= 6) maxPositions = std::atoi(argv[5]);
    if (argc >= 7) maxWorldSeeds = std::strtoull(argv[6], nullptr, 10);
    if (argc >= 8) filterTaiga = std::atoi(argv[7]) != 0;
    if (argc >= 9) filterSmith = std::atoi(argv[8]) != 0;
    if (argc >= 10) logEach = std::atoi(argv[9]) != 0;

    std::cout << "[process " << offset << "/" << totalThreads
              << "] startingPoint=" << startingPoint << std::endl;

    auto t0 = std::chrono::steady_clock::now();
    auto lastReport = t0;
    uint64_t lastProcessedSeeds = 0;
    uint64_t lastGeneratedVillages = 0;
    uint64_t lastTotalPieces = 0;
    const auto reportInterval = std::chrono::seconds(30);
    uint64_t processedSeeds = 0;
    uint64_t generatedVillages = 0;
    uint64_t totalPieces = 0;

    for (uint64_t structureSeed = startingPoint + offset;
         structureSeed < (1ULL << 48) && processedSeeds < maxStructureSeeds;
         structureSeed += totalThreads) {
        std::vector<Pos> villePosList;
        buildVillagePositions(structureSeed, villePosList, maxPositions);
        checkWorldSeed(structureSeed, villePosList, maxWorldSeeds, filterTaiga, filterSmith, logEach, &generatedVillages, &totalPieces);
        processedSeeds++;
        auto now = std::chrono::steady_clock::now();
        if (now - lastReport >= reportInterval) {
            auto elapsedMs = std::chrono::duration_cast<std::chrono::milliseconds>(now - t0).count();
            auto deltaMs = std::chrono::duration_cast<std::chrono::milliseconds>(now - lastReport).count();
            uint64_t deltaSeeds = processedSeeds - lastProcessedSeeds;
            uint64_t deltaVillages = generatedVillages - lastGeneratedVillages;
            uint64_t deltaPieces = totalPieces - lastTotalPieces;
            double seedsPerSec = deltaMs > 0 ? (deltaSeeds * 1000.0) / deltaMs : 0.0;
            double villagesPerSec = deltaMs > 0 ? (deltaVillages * 1000.0) / deltaMs : 0.0;
            std::cout << "[progress] ms=" << elapsedMs
                      << " processedSeeds=" << processedSeeds
                      << " generatedVillages=" << generatedVillages
                      << " totalPieces=" << totalPieces
                      << " deltaSeeds=" << deltaSeeds
                      << " deltaVillages=" << deltaVillages
                      << " deltaPieces=" << deltaPieces
                      << " seedsPerSec=" << seedsPerSec
                      << " villagesPerSec=" << villagesPerSec
                      << " rssKb=" << getCurrentRssKb()
                      << " maxRssKb=" << getMaxRssKb()
                      << std::endl;
            lastReport = now;
            lastProcessedSeeds = processedSeeds;
            lastGeneratedVillages = generatedVillages;
            lastTotalPieces = totalPieces;
        }
    }
    auto t1 = std::chrono::steady_clock::now();
    auto elapsedMs = std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count();
    std::cout << "runtime_ms=" << elapsedMs
              << " processedSeeds=" << processedSeeds
              << " generatedVillages=" << generatedVillages
              << " totalPieces=" << totalPieces
              << std::endl;
    return 0;
}
