# Makefile pour comparer les tests Java et C
# Usage:
#   make -f Makefile.compare test-java    # Exécuter le test Java
#   make -f Makefile.compare test-c       # Exécuter le test C
#   make -f Makefile.compare compare      # Exécuter les deux et comparer

.PHONY: all test-java test-c compare clean help

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
	@echo "  $(GREEN)clean$(NC)      - Nettoyer les fichiers générés"
	@echo ""

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
	@./gradlew clean --quiet 2>/dev/null || true
	@echo "Nettoyage terminé."
