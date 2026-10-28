# ---- CUDA build for village noise GPU acceleration ----
#
# Usage:
#   make -C cuda                # build village_noise_cuda.lib
#   make -C cuda test_cuda      # build the correctness + benchmark test
#   make -C cuda run            # build and run it
#   make -C cuda clean
#
# Requirements
#   - a CUDA toolkit new enough for the installed GPU. The default below is
#     CUDA 13.1; an RTX 50xx (sm_120) is NOT supported by CUDA 11.x, so do not
#     fall back to whichever nvcc happens to be first in PATH.
#   - MSVC build tools (nvcc needs cl.exe as host compiler on Windows).
#
# Override any of these on the command line, e.g.
#   make -C cuda test_cuda CUDA_HOME="/c/.../CUDA/v12.6" GPU_ARCH=sm_89

CUDA_HOME     ?= C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v13.1
MSVC_BIN      ?= C:/Program Files (x86)/Microsoft Visual Studio/2022/BuildTools/VC/Tools/MSVC/14.44.35207/bin/Hostx64/x64
GPU_ARCH      ?= native

NVCC          := "$(CUDA_HOME)/bin/nvcc"
CUBIOMES_DIR  := ../../cubiomes
PARENT_DIR    := ..

# -fmad=false is REQUIRED for bit-exactness: without it nvcc contracts
# `from + part * (to - from)` into an FMA and the interpolated noise drifts
# from the CPU result, which flips heights at cell boundaries.
# --default-stream per-thread : sans ce flag, TOUS les threads partagent le flux
# CUDA par défaut (legacy null stream) et leurs lancements sont sérialisés sur le
# GPU. Avec, chaque thread a son propre flux implicite et les kernels peuvent
# réellement se recouvrir — nos lancements ne font qu'une centaine de blocs, très
# loin de remplir les 48 SMs à eux seuls.
NVCC_FLAGS    := -O3 -std=c++17 -fmad=false --default-stream per-thread \
                 -arch=$(GPU_ARCH) \
                 -ccbin "$(MSVC_BIN)" \
                 -I$(CUBIOMES_DIR) -I$(PARENT_DIR)

# cubiomes and the shared C sources must be compiled by the same (MSVC) host
# compiler as the CUDA objects, so they are built here rather than reused from
# the mingw build in ../Makefile.
CUBIOMES_SRC  := $(CUBIOMES_DIR)/noise.c $(CUBIOMES_DIR)/biomes.c \
                 $(CUBIOMES_DIR)/layers.c $(CUBIOMES_DIR)/biomenoise.c \
                 $(CUBIOMES_DIR)/generator.c $(CUBIOMES_DIR)/finders.c \
                 $(CUBIOMES_DIR)/util.c $(CUBIOMES_DIR)/quadbase.c
CUBIOMES_OBJ  := $(notdir $(CUBIOMES_SRC:.c=.obj))

HOST_SRC      := $(PARENT_DIR)/surface_gen.c $(PARENT_DIR)/cubiomes_integration.c
HOST_OBJ      := surface_gen.obj cubiomes_integration.obj

LIB           := village_noise_cuda.lib
LIBCUBIOMES   := cubiomes_msvc.lib

.PHONY: all clean run

all: $(LIB)

# ---- CUDA objects --------------------------------------------------------

village_noise.obj: village_noise.cu village_noise.cuh
	$(NVCC) $(NVCC_FLAGS) -c $< -o $@

village_noise_host.obj: village_noise_host.cpp village_noise_host.hpp village_noise.cuh
	$(NVCC) $(NVCC_FLAGS) -c $< -o $@

$(LIB): village_noise.obj village_noise_host.obj
	$(NVCC) -lib -ccbin "$(MSVC_BIN)" $^ -o $@

# ---- cubiomes + shared C sources, MSVC-compatible ------------------------

# /w silences the flood of MSVC warnings from cubiomes' C99 style.
%.obj: $(CUBIOMES_DIR)/%.c
	$(NVCC) -ccbin "$(MSVC_BIN)" -O2 -Xcompiler -w -I$(CUBIOMES_DIR) -c $< -o $@

$(LIBCUBIOMES): $(CUBIOMES_OBJ)
	$(NVCC) -lib -ccbin "$(MSVC_BIN)" $^ -o $@

surface_gen.obj: $(PARENT_DIR)/surface_gen.c $(PARENT_DIR)/surface_gen.h
	$(NVCC) -ccbin "$(MSVC_BIN)" -O2 -Xcompiler -w -I$(CUBIOMES_DIR) -I$(PARENT_DIR) -c $< -o $@

cubiomes_integration.obj: $(PARENT_DIR)/cubiomes_integration.c $(PARENT_DIR)/cubiomes_integration.h
	$(NVCC) -ccbin "$(MSVC_BIN)" -O2 -Xcompiler -w -I$(CUBIOMES_DIR) -I$(PARENT_DIR) -c $< -o $@

# ---- test ----------------------------------------------------------------

test_cuda: test_cuda.cpp $(LIB) $(LIBCUBIOMES) $(HOST_OBJ)
	$(NVCC) $(NVCC_FLAGS) test_cuda.cpp $(HOST_OBJ) $(LIB) $(LIBCUBIOMES) -o $@

run: test_cuda
	./test_cuda.exe

# ---- village : C seul vs C + hauteurs CUDA -------------------------------

# Sources C++ du générateur de villages, recompilées ici avec MSVC.
VILLAGE_SRC := $(PARENT_DIR)/VillageGenerator.cpp $(PARENT_DIR)/TerrainGenerator.cpp \
               $(PARENT_DIR)/SurfaceGenWrapper.cpp $(PARENT_DIR)/BlockStructures.cpp \
               $(PARENT_DIR)/ChunkRand.cpp $(PARENT_DIR)/VillagePools.cpp \
               $(PARENT_DIR)/JigSawPool.cpp $(PARENT_DIR)/village_structure_size.cpp \
               $(PARENT_DIR)/BiomeSource.cpp $(PARENT_DIR)/Biome.cpp

test_village_cuda: test_village_cuda.cpp cuda_height_provider.cpp cuda_height_provider.hpp \
                   $(VILLAGE_SRC) $(LIB) $(LIBCUBIOMES) $(HOST_OBJ)
	$(NVCC) $(NVCC_FLAGS) -Xcompiler -wd4267 -Xcompiler -wd4244 \
		test_village_cuda.cpp cuda_height_provider.cpp $(VILLAGE_SRC) \
		$(HOST_OBJ) $(LIB) $(LIBCUBIOMES) -o $@

run-village: test_village_cuda
	./test_village_cuda.exe

# Benchmark de débit. Un seul binaire, backend choisi à l'exécution.
bench_village: bench_village.cpp cuda_height_provider.cpp cuda_height_provider.hpp \
               $(VILLAGE_SRC) $(LIB) $(LIBCUBIOMES) $(HOST_OBJ)
	$(NVCC) $(NVCC_FLAGS) -Xcompiler -wd4267 -Xcompiler -wd4244 \
		bench_village.cpp cuda_height_provider.cpp $(VILLAGE_SRC) \
		$(HOST_OBJ) $(LIB) $(LIBCUBIOMES) -o $@

# Profil par zones. Compilé à part avec -DVILLAGE_PROFILE pour que les sondes
# n'existent pas dans bench_village / search_village_cuda.
profile_village: profile_village.cpp cuda_height_provider.cpp cuda_height_provider.hpp \
                 $(PARENT_DIR)/Profiler.hpp $(VILLAGE_SRC) $(LIB) $(LIBCUBIOMES) $(HOST_OBJ)
	$(NVCC) $(NVCC_FLAGS) -DVILLAGE_PROFILE -Xcompiler -wd4267 -Xcompiler -wd4244 \
		profile_village.cpp cuda_height_provider.cpp $(VILLAGE_SRC) \
		$(HOST_OBJ) $(LIB) $(LIBCUBIOMES) -o $@

profile profile-c: export CUBIOMES_LAYER_CACHE = 0
profile: profile_village
	./profile_village.exe --cuda --count $(PROFILE_COUNT)
profile-c: profile_village
	./profile_village.exe --c    --count $(PROFILE_COUNT)

PROFILE_COUNT ?= 300

# Etude de couverture : quelles colonnes un village consomme reellement.
analyze_coverage: analyze_coverage.cpp cuda_height_provider.cpp cuda_height_provider.hpp \
                  $(VILLAGE_SRC) $(LIB) $(LIBCUBIOMES) $(HOST_OBJ)
	$(NVCC) $(NVCC_FLAGS) -Xcompiler -wd4267 -Xcompiler -wd4244 \
		analyze_coverage.cpp cuda_height_provider.cpp $(VILLAGE_SRC) \
		$(HOST_OBJ) $(LIB) $(LIBCUBIOMES) -o $@

coverage: export CUBIOMES_LAYER_CACHE = 0
coverage: analyze_coverage
	./analyze_coverage.exe --count $(PROFILE_COUNT)



# Cas de regression sur des villages precis (coherence avec le jeu).
test_village_seeds: test_village_seeds.cpp cuda_height_provider.cpp cuda_height_provider.hpp                     $(VILLAGE_SRC) $(LIB) $(LIBCUBIOMES) $(HOST_OBJ)
	$(NVCC) $(NVCC_FLAGS) -Xcompiler -wd4267 -Xcompiler -wd4244 		test_village_seeds.cpp cuda_height_provider.cpp $(VILLAGE_SRC) 		$(HOST_OBJ) $(LIB) $(LIBCUBIOMES) -o $@

seeds: export CUBIOMES_LAYER_CACHE = 0
seeds: test_village_seeds
	./test_village_seeds.exe

# Recherche de villages à forte densité de forgerons.
search_village_cuda: search_village_cuda.cpp cuda_height_provider.cpp cuda_height_provider.hpp \
                     $(VILLAGE_SRC) $(LIB) $(LIBCUBIOMES) $(HOST_OBJ)
	$(NVCC) $(NVCC_FLAGS) -Xcompiler -wd4267 -Xcompiler -wd4244 \
		search_village_cuda.cpp cuda_height_provider.cpp $(VILLAGE_SRC) \
		$(HOST_OBJ) $(LIB) $(LIBCUBIOMES) -o $@

search: export CUBIOMES_LAYER_CACHE = 0
search: search_village_cuda
	./search_village_cuda.exe --smiths $(SMITHS) --threads $(THREADS) --out $(SEARCH_OUT)

SMITHS     ?= 6
THREADS    ?= 4
SEARCH_OUT ?= village_finds.log

BENCH_SEED  ?= 1
BENCH_WORLDS ?= 520
BENCH_THREADS ?= 4
BENCH_COUNT ?= 10000

# export cible-spécifique plutôt qu'un préfixe VAR=val : ça marche quel que
# soit le shell que make utilise (sh sous MSYS, cmd sous PowerShell).
bench-c bench-cuda run-village: export CUBIOMES_LAYER_CACHE = 0

bench-c: bench_village
	./bench_village.exe --c    --seed $(BENCH_SEED) --worlds $(BENCH_WORLDS) --threads $(BENCH_THREADS)

bench-cuda: bench_village
	./bench_village.exe --cuda --seed $(BENCH_SEED) --worlds $(BENCH_WORLDS) --threads $(BENCH_THREADS)

clean:
	rm -f *.obj *.o *.lib *.exp *.exe *.pdb test_cuda test_village_cuda bench_village search_village_cuda profile_village analyze_coverage test_village_seeds
