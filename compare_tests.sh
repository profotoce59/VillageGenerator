#!/bin/bash
# Script pour comparer les tests Java et C côte à côte

echo "=========================================="
echo "  Comparaison Tests Java vs C"
echo "=========================================="
echo ""

# Couleurs
BLUE='\033[0;34m'
YELLOW='\033[0;33m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

# Test Java
echo -e "${BLUE}>>> Test JAVA${NC}"
./gradlew runCompareTest --quiet 2>&1 | grep -E "(===|Test [0-9]|Position|hauteur|height|pierre|STONE|Première)" > output_java_clean.txt
cat output_java_clean.txt
echo ""

# Test C
echo -e "${YELLOW}>>> Test C${NC}"
cd c && make example 2>&1 | grep -E "(===|Exemple|Position|hauteur|height|pierre|Première)" > ../output_c_clean.txt
cd ..
cat output_c_clean.txt
echo ""

# Comparaison
echo -e "${GREEN}=========================================="
echo -e "  Fichiers générés pour comparaison:"
echo -e "  - output_java_clean.txt"
echo -e "  - output_c_clean.txt"
echo -e "==========================================${NC}"
