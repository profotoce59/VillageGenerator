#!/bin/bash
# throughput.sh — debit de bout en bout a 16 threads CPU, le juge final (SKILL.md §4d).
#
# Usage, depuis c/cuda :
#   bash ../../.claude/skills/cuda-optimize/throughput.sh ncu_runs/<item> baseline candidate [N]
#
# Chaque cote est un sous-dossier contenant bench_village.exe. On peut passer
# plus de deux cotes (balayage). Un run de chauffe par cote est jete, puis N
# runs (10 par defaut) en alternant les cotes pour lisser la derive thermique.
# Affiche chaque run, puis la mediane par cote et l'ecart au premier cote.
# Ecrit aussi <dossier>/throughput.txt.
set -euo pipefail

DIR=${1:?usage: throughput.sh <dossier item> <cote1> <cote2> [... ] [N]}
shift
N=10
SIDES=()
for a in "$@"; do
    if [[ "$a" =~ ^[0-9]+$ ]]; then N=$a; else SIDES+=("$a"); fi
done
[ ${#SIDES[@]} -ge 1 ] || { echo "au moins un cote" >&2; exit 1; }

WORLDS=${WORLDS:-400}   # ~5 s par run ; 100 mondes (~1,3 s) devient trop bruite
ARGS="--cuda --seed 1 --worlds $WORLDS --threads 16 --quiet"

run() {
    "$DIR/$1/bench_village.exe" $ARGS < /dev/null 2>&1 | tr -d '\r' \
        | grep 'débit' | grep -oE '[0-9]+([.,][0-9]+)?' | head -1
}

echo "== chauffe"
for s in "${SIDES[@]}"; do run "$s" > /dev/null; done

declare -A VALS
for i in $(seq 1 "$N"); do
    line="run $i :"
    for s in "${SIDES[@]}"; do
        v=$(run "$s")
        VALS[$s]="${VALS[$s]:-} $v"
        line="$line  $s=$v"
    done
    echo "$line"
done

{
    ref=""
    for s in "${SIDES[@]}"; do
        med=$(echo ${VALS[$s]} | tr ' ' '\n' | sort -n \
              | awk '{a[NR]=$1} END {if (NR%2) print a[(NR+1)/2]; else print (a[NR/2]+a[NR/2+1])/2}')
        if [ -z "$ref" ]; then
            ref=$med
            printf "%-12s mediane %8.1f v/s\n" "$s" "$med"
        else
            printf "%-12s mediane %8.1f v/s  (%+.1f %%)\n" "$s" "$med" \
                "$(awk -v a="$med" -v b="$ref" 'BEGIN {print (a-b)/b*100}')"
        fi
    done
} | tee "$DIR/throughput.txt"
