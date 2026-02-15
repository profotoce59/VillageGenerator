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

NVCC_FLAGS    := -O2 -std=c++17 --expt-relaxed-constexpr \
                 -I$(CUBIOMES_DIR) -I$(PARENT_DIR)
CXX_FLAGS     := -O2 -std=c++17 -I$(CUBIOMES_DIR) -I$(PARENT_DIR)

LIBCUBIOMES   := $(CUBIOMES_DIR)/libcubiomes.a

# Targets
LIB           := libvillage_noise_cuda.a

.PHONY: all clean

all: $(LIB)

# Compile CUDA kernels + host API
village_noise.o: village_noise.cu village_noise.cuh
	$(NVCC) $(NVCC_FLAGS) -c village_noise.cu -o village_noise.o

# Compile host wrapper (plain C++)
village_noise_host.o: village_noise_host.cpp village_noise.cuh
	$(CXX) $(CXX_FLAGS) -c village_noise_host.cpp -o village_noise_host.o

# Static library
$(LIB): village_noise.o village_noise_host.o
	ar rcs $(LIB) village_noise.o village_noise_host.o

# Test executable (optional)
test_cuda: test_cuda.cpp $(LIB) $(LIBCUBIOMES)
	$(NVCC) $(NVCC_FLAGS) test_cuda.cpp \
		$(PARENT_DIR)/surface_gen.c $(PARENT_DIR)/cubiomes_integration.c \
		-L. -lvillage_noise_cuda $(LIBCUBIOMES) \
		-lm -o test_cuda

clean:
	rm -f *.o $(LIB) test_cuda
