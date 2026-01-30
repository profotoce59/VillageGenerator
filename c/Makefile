# ---- config ----
CC              := gcc
CUBIOMES_DIR    := ../../cubiomes
CFLAGS_COMMON   := -O2 -std=c11 -fwrapv -I$(CUBIOMES_DIR)
LIBS            := -lm
TARGET          := monprog
SRC             := block_height.c surface_gen.c cubiomes_integration.c

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
example: example_cubiomes_surface
	./example_cubiomes_surface

example_cubiomes_surface: example_cubiomes_surface.c surface_gen.c cubiomes_integration.c $(LIBCUBIOMES)
	$(CC) $(CFLAGS_COMMON) $^ -o $@ $(LIBS)