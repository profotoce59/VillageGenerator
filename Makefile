# Makefile pour comparer les tests Java et C
# Usage:
#   make -f Makefile.compare test-java    # Exécuter le test Java
#   make -f Makefile.compare test-c       # Exécuter le test C
#   make -f Makefile.compare compare      # Exécuter les deux et comparer

.PHONY: all test-java test-c compare clean help setup test-cuda test-cuda-village bench-c bench-cuda

# Couleurs pour l'affichage
BLUE := \033[0;34m
GREEN := \033[0;32m
YELLOW := \033[0;33m
NC := \033[0m # No Color

all: compare

help:
	@echo "$(BLUE)=== Makefile de comparaison Java/C ===$(NC)"
	@echo ""
	@echo "Cibles disponibles :"
	@echo "  $(GREEN)test-java$(NC)  - Exécuter le test Java"
	@echo "  $(GREEN)test-c$(NC)     - Exécuter le test C"
	@echo "  $(GREEN)compare$(NC)    - Exécuter les deux tests et comparer"
	@echo "  $(GREEN)test-cuda$(NC)  - Heightmap CUDA vs C : correction + benchmark"
	@echo "  $(GREEN)test-cuda-village$(NC) - Village C vs C+CUDA : mêmes pièces + temps"
	@echo "  $(GREEN)bench-c$(NC) / $(GREEN)bench-cuda$(NC) - Débit sur $(BENCH_COUNT) villages (BENCH_COUNT=N)"
	@echo "  $(GREEN)setup$(NC)      - Initialiser les submodules"
	@echo "  $(GREEN)clean$(NC)      - Nettoyer les fichiers générés"
	@echo ""

setup:
	@echo "$(BLUE)========================================$(NC)"
	@echo "$(BLUE)   Initialisation des submodules        $(NC)"
	@echo "$(BLUE)========================================$(NC)"
	@git submodule update --init --recursive

# Test Java
test-java-height:
	@echo "$(BLUE)========================================$(NC)"
	@echo "$(BLUE)     Test JAVA - SurfaceGenerator      $(NC)"
	@echo "$(BLUE)========================================$(NC)"
	@./gradlew runCompareTest --quiet

# Trouver une seed de village
find-village-seed:
	@echo "$(BLUE)========================================$(NC)"
	@echo "$(BLUE)   Recherche de seed avec village      $(NC)"
	@echo "$(BLUE)========================================$(NC)"
	@./gradlew findVillageSeed --quiet

# Comparer les pièces du village Java/C
compare-village-pieces:
	@echo "$(BLUE)========================================$(NC)"
	@echo "$(BLUE)   Comparaison pièces village Java     $(NC)"
	@echo "$(BLUE)========================================$(NC)"
	@./gradlew compareVillagePieces --quiet

# Test C
test-c-height:
	@echo "$(YELLOW)========================================$(NC)"
	@echo "$(YELLOW)       Test C - SurfaceGen             $(NC)"
	@echo "$(YELLOW)========================================$(NC)"
	@cd c && $(MAKE) example_height

# Test C avec la seed de village
test-village-seed:
	@echo "$(YELLOW)========================================$(NC)"
	@echo "$(YELLOW)    Test C - Seed de village trouvée   $(NC)"
	@echo "$(YELLOW)========================================$(NC)"
	@cd c && $(MAKE) test_village_seed && ./test_village_seed

# Heightmap CUDA : vérifie l'égalité bit à bit avec le C, puis benchmark.
# SEED/X0/Z0/SIZE/REPEATS peuvent être surchargés :
#   make test-cuda SEED=42 X0=-5000 Z0=-7000 SIZE=200
SEED    ?= 123456789
X0      ?= 0
Z0      ?= 0
SIZE    ?= 100
REPEATS ?= 5
test-cuda:
	@echo "$(GREEN)========================================$(NC)"
	@echo "$(GREEN)   Heightmap CUDA vs C                 $(NC)"
	@echo "$(GREEN)========================================$(NC)"
	@$(MAKE) -C c/cuda test_cuda
	@cd c/cuda && ./test_cuda.exe $(SEED) $(X0) $(Z0) $(SIZE) $(REPEATS)

# Village complet : C seul vs C + hauteurs CUDA, comparaison des pièces.
# CUBIOMES_LAYER_CACHE=0 est requis : le cache de layer de cubiomes fausse les
# biomes des requêtes 1x1 (cf. c/test_layer_cache_consistency.c).
NB_SEEDS   ?= 300
NB_WORLDS  ?= 2
test-cuda-village:
	@echo "$(GREEN)========================================$(NC)"
	@echo "$(GREEN)   Village : C seul vs C + CUDA        $(NC)"
	@echo "$(GREEN)========================================$(NC)"
	@$(MAKE) -C c/cuda test_village_cuda
	@cd c/cuda && CUBIOMES_LAYER_CACHE=0 ./test_village_cuda.exe $(SEED_V) $(NB_SEEDS) $(NB_WORLDS)

SEED_V ?= 1

# Benchmark de débit : mêmes villages, backend hauteurs différent.
BENCH_COUNT ?= 10000
bench-c:
	@$(MAKE) -C c/cuda bench-c BENCH_COUNT=$(BENCH_COUNT)

bench-cuda:
	@$(MAKE) -C c/cuda bench-cuda BENCH_COUNT=$(BENCH_COUNT)

# Exécuter les deux tests et comparer
compare: clean-output
	@echo "$(GREEN)========================================$(NC)"
	@echo "$(GREEN)   Comparaison Java vs C               $(NC)"
	@echo "$(GREEN)========================================$(NC)"
	@echo ""
	@echo "$(BLUE)>>> Exécution du test Java...$(NC)"
	@./gradlew runCompareTest --quiet > output_java.txt 2>&1 || true
	@cat output_java.txt
	@echo ""
	@echo "$(YELLOW)>>> Exécution du test C...$(NC)"
	@cd c && $(MAKE) example > ../output_c.txt 2>&1
	@cat output_c.txt
	@echo ""
	@echo "$(GREEN)========================================$(NC)"
	@echo "$(GREEN)   Résultats sauvegardés dans :        $(NC)"
	@echo "$(GREEN)   - output_java.txt                   $(NC)"
	@echo "$(GREEN)   - output_c.txt                      $(NC)"
	@echo "$(GREEN)========================================$(NC)"

# Nettoyer les fichiers de sortie
clean-output:
	@rm -f output_java.txt output_c.txt

clean: clean-output
	@cd c && $(MAKE) clean
	@-$(MAKE) -C c/cuda clean 2>/dev/null || true
	@./gradlew clean --quiet 2>/dev/null || true
	@echo "Nettoyage terminé."
