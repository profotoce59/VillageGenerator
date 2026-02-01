# ---- config ----
CC              := gcc
CXX             := g++
CUBIOMES_DIR    := ../../cubiomes
CFLAGS_COMMON   := -O2 -std=c11 -fwrapv -I$(CUBIOMES_DIR)
CXXFLAGS_COMMON := -O2 -std=c++17 -fwrapv -I$(CUBIOMES_DIR)
LIBS            := -lm
TARGET          := monprog
SRC             := block_height.c surface_gen.c cubiomes_integration.c
CPP_SRC         := SurfaceGenWrapper.cpp TerrainGenerator.cpp VillageGenerator.cpp

# Chemin du dépôt cubiomes depuis ce dossier

LIBCUBIOMES     := $(CUBIOMES_DIR)/libcubiomes.a

# Mettre USE_SOURCES=1 pour compiler directement les .c de cubiomes
USE_SOURCES     ?= 0

# ---- règles ----
.PHONY: all clean run info example

all: info $(TARGET)

info:
	@echo "==> Build $(TARGET)"
	@echo "    CUBIOMES_DIR = $(CUBIOMES_DIR)"
	@echo "    USE_SOURCES  = $(USE_SOURCES)"

# --- Mode 1: lier contre la lib statique libcubiomes.a (par défaut) ---
ifeq ($(USE_SOURCES),0)

CFLAGS := $(CFLAGS_COMMON)
$(TARGET): $(SRC) $(LIBCUBIOMES)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

# construit libcubiomes.a en appelant le Makefile du dossier cubiomes
$(LIBCUBIOMES):
	$(MAKE) -C $(CUBIOMES_DIR)

clean:
	rm -f $(TARGET) example_cubiomes_surface
	-$(MAKE) -C $(CUBIOMES_DIR) clean

# --- Mode 2: compiler directement les sources cubiomes avec ton main.c ---
else

CFLAGS := $(CFLAGS_COMMON)
CUBIOMES_SRC := $(wildcard $(CUBIOMES_DIR)/*.c)
$(TARGET): $(SRC) $(CUBIOMES_SRC)
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

clean:
	rm -f $(TARGET)

endif

run: $(TARGET)
	./$(TARGET)

# Cible pour l'exemple d'intégration cubiomes
example_height: example_cubiomes_surface
	./example_cubiomes_surface

example_cubiomes_surface: example_cubiomes_surface.c surface_gen.c cubiomes_integration.c $(LIBCUBIOMES)
	$(CC) $(CFLAGS_COMMON) $^ -o $@ $(LIBS)

# Test du wrapper C++
test_village_height: test_village_height.cpp SurfaceGenWrapper.cpp
	$(CC) $(CFLAGS_COMMON) -c surface_gen.c -o surface_gen.o
	$(CC) $(CFLAGS_COMMON) -c cubiomes_integration.c -o cubiomes_integration.o
	$(CXX) $(CXXFLAGS_COMMON) test_village_height.cpp SurfaceGenWrapper.cpp surface_gen.o cubiomes_integration.o $(LIBCUBIOMES) -o $@ $(LIBS)

# Test avec la seed de village trouvée en Java
test_village_seed: test_village_seed.cpp SurfaceGenWrapper.cpp
	$(CC) $(CFLAGS_COMMON) -c surface_gen.c -o surface_gen.o
	$(CC) $(CFLAGS_COMMON) -c cubiomes_integration.c -o cubiomes_integration.o
	$(CXX) $(CXXFLAGS_COMMON) test_village_seed.cpp SurfaceGenWrapper.cpp surface_gen.o cubiomes_integration.o $(LIBCUBIOMES) -o $@ $(LIBS)

# Test de génération complète du village
test_village_generation: test_village_generation.cpp SurfaceGenWrapper.cpp TerrainGenerator.cpp VillageGenerator.cpp BlockStructures.cpp ChunkRand.cpp VillagePools.cpp JigSawPool.cpp village_structure_size.cpp
	$(CC) $(CFLAGS_COMMON) -c surface_gen.c -o surface_gen.o
	$(CC) $(CFLAGS_COMMON) -c cubiomes_integration.c -o cubiomes_integration.o
	$(CXX) $(CXXFLAGS_COMMON) test_village_generation.cpp SurfaceGenWrapper.cpp TerrainGenerator.cpp VillageGenerator.cpp BlockStructures.cpp ChunkRand.cpp VillagePools.cpp JigSawPool.cpp village_structure_size.cpp surface_gen.o cubiomes_integration.o $(LIBCUBIOMES) -o $@ $(LIBS)