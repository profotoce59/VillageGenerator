# VillageGenerator

Minecraft 1.16 village generation engine reimplemented in C++ (ported from Java seedfinding libraries).
Searches for villages with specific properties (e.g. many blacksmiths) by brute-forcing structure seeds.

## Project structure

- `c/` — C++ implementation (main codebase)
- `src/` — Original Java implementation (reference)
- `cubiomes/` — External C library for Minecraft biome/structure generation

## Build (C++)

```bash
cd c
make test_village_generation CUBIOMES_DIR=../cubiomes
```

Note: `CUBIOMES_DIR` in the Makefile defaults to `../../cubiomes` but the correct relative path is `../cubiomes`. Pass it explicitly or fix the Makefile.

## Run village search

```bash
./test_village_generation <num_threads> <start_structure_seed> <num_worldseeds> <num_regions> [blacksmith_threshold=6]
```

| Parameter | Description |
|---|---|
| `num_threads` | Number of worker threads |
| `start_structure_seed` | 48-bit starting structure seed |
| `num_worldseeds` | Worldseeds per structure seed (upper 16 bits, max 65536) |
| `num_regions` | Side length N — checks N*N region positions per worldseed |
| `blacksmith_threshold` | Min blacksmiths to report (default: 6) |

Each thread gets an offset and increments by `num_threads` to avoid overlap.

Example:
```bash
./test_village_generation 8 192731432848353 4 400 6
```

## Key C++ classes

- `VillageGenerator` — generates a village at a chunk position, exposes `getPieces()`
- `TerrainGenerator` / `OverworldTerrainGenerator` — terrain height queries using cubiomes
- `BiomeSource` / `SimpleBiomeSource` — biome lookups via cubiomes
- `ChunkRand` — Java-compatible PRNG (48-bit LCG)
- `SurfaceGenWrapper` — bridges C cubiomes with C++ terrain gen

## Seed model

- **Structure seed**: lower 48 bits — determines structure placement
- **World seed**: 64 bits = `structureSeed | (upperBits << 48)`
- Village positions per structure seed come from cubiomes `getStructurePos(Village, MC_1_16, seed, regX, regZ, &pos)`
