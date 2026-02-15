# ---- CUDA build for village noise GPU acceleration ----
#
# Usage:
#   make -C cuda                     # build libvillage_noise_cuda.a
#   make -C cuda test_cuda           # build + run test
#   make -C cuda clean
#
# Prerequisites: CUDA toolkit (nvcc) + cubiomes built

NVCC          := nvcc
CXX           := g++
CUBIOMES_DIR  := ../../cubiomes
PARENT_DIR    := ..

MSVC2022_BIN  := "C:/Program Files (x86)/Microsoft Visual Studio/2022/BuildTools/VC/Tools/MSVC/14.44.35207/bin/Hostx64/x64"
NVCC_FLAGS    := -O2 -std=c++17 --expt-relaxed-constexpr \
                 -ccbin $(MSVC2022_BIN) \
                 -I$(CUBIOMES_DIR) -I$(PARENT_DIR)
CXX_FLAGS     := -O2 -std=c++17 -I$(CUBIOMES_DIR) -I$(PARENT_DIR)

LIBCUBIOMES   := cubiomes.lib
CUBIOMES_SRC  := $(wildcard $(CUBIOMES_DIR)/*.c)

# Targets (use .lib for MSVC linker)
LIB           := village_noise_cuda.lib

.PHONY: all clean

all: $(LIB)

# Compile CUDA kernels + host API
village_noise: village_noise.cu village_noise.cuh
	$(NVCC) $(NVCC_FLAGS) -c village_noise.cu -o village_noise.o

# Compile host wrapper (plain C++)
village_noise_host: village_noise_host.cpp village_noise.cuh
	$(NVCC) $(NVCC_FLAGS) -c village_noise_host.cpp -o village_noise_host.o

# Static library
$(LIB): village_noise.o village_noise_host.o
	$(NVCC) -lib -ccbin $(MSVC2022_BIN) village_noise.o village_noise_host.o -o $(LIB)

# Build cubiomes as MSVC-compatible .lib (recompile from source via nvcc)
CUBIOMES_OBJS := noise.obj biomes.obj layers.obj biomenoise.obj generator.obj finders.obj util.obj quadbase.obj

$(LIBCUBIOMES): $(CUBIOMES_SRC)
	$(NVCC) -ccbin $(MSVC2022_BIN) -O2 -Xcompiler "/w /D_WIN32" -I$(CUBIOMES_DIR) \
		-c $(CUBIOMES_DIR)/noise.c $(CUBIOMES_DIR)/biomes.c $(CUBIOMES_DIR)/layers.c \
		$(CUBIOMES_DIR)/biomenoise.c $(CUBIOMES_DIR)/generator.c $(CUBIOMES_DIR)/finders.c \
		$(CUBIOMES_DIR)/util.c $(CUBIOMES_DIR)/quadbase.c
	$(NVCC) -lib -ccbin $(MSVC2022_BIN) -o $(LIBCUBIOMES) $(CUBIOMES_OBJS)

# Test executable (optional)
test_cuda: test_cuda.cpp $(LIB) $(LIBCUBIOMES)
	$(NVCC) $(NVCC_FLAGS) test_cuda.cpp \
		$(PARENT_DIR)/surface_gen.c $(PARENT_DIR)/cubiomes_integration.c \
		$(LIB) $(LIBCUBIOMES) \
		-o test_cuda

clean:
	rm -f *.o $(LIB) test_cuda
