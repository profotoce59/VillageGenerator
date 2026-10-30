#!/bin/bash
# saturation.sh — le GPU est-il encore le goulot a 16 threads CPU ? (TODO 2.16)
#
# Usage, depuis c/cuda, apres avoir construit bench_village.exe :
#   bash ../../.claude/skills/cuda-optimize/saturation.sh ncu_runs/2.16
#
# Trois mesures, ecrites dans <dossier>/ :
#   A. Amdahl cote CPU : part du temps des threads passee a attendre le prefetch
#      GPU (upload + kernels + file d'attente + download). Borne le gain maximal
#      de toute optimisation GPU : 1 / (1 - f).
#   B. Sur-souscription : debit a 16, 24 et 32 threads. Si plus de threads que
#      de coeurs logiques fait monter le debit, des coeurs dormaient en attendant
#      le GPU, et le GPU avait de la marge.
#   C. Trace nsys a 16 threads : part du temps mural ou au moins un kernel
#      tourne (union des intervalles), concurrence moyenne, transferts, temps
#      passe dans les appels CUDA bloquants, et metriques GPU (SM Active…) si
#      le pilote les fournit.
set -euo pipefail

DIR=${1:?usage: saturation.sh <dossier de sortie>}
mkdir -p "$DIR"
cp bench_village.exe "$DIR/"
HERE="$(cd "$(dirname "$0")" && pwd)"
export CUBIOMES_LAYER_CACHE=0
export PYTHONIOENCODING=utf-8
WORLDS=${WORLDS:-400}
NSYS_WORLDS=${NSYS_WORLDS:-100}
NSYS="$(ls -d "/c/Program Files/NVIDIA Corporation/Nsight Systems "* | sort -V | tail -1)/target-windows-x64/nsys.exe"

bench() {   # $1 = threads, $2 = mondes
    "$DIR/bench_village.exe" --cuda --seed 1 --worlds "$2" --threads "$1" --quiet \
        < /dev/null 2>&1 | tr -d '\r'
}

echo "== A. attente GPU vue des threads (16 threads, $WORLDS mondes, 3 runs)"
bench 16 "$WORLDS" > /dev/null          # chauffe
for i in 1 2 3; do bench 16 "$WORLDS" > "$DIR/bench16_$i.txt"; done
python -I "$HERE/analyze_saturation.py" bench "$DIR"/bench16_*.txt | tee "$DIR/A_amdahl.txt"

echo
echo "== B. sur-souscription (16 / 24 / 32 threads, 3 runs alternes)"
RUNS="$DIR/B_threads_runs.txt"
: > "$RUNS"
for t in 24 32; do bench "$t" "$WORLDS" > /dev/null; done   # chauffe
for i in 1 2 3; do
    for t in 16 24 32; do
        v=$(bench "$t" "$WORLDS" | grep 'débit' | grep -oE '[0-9]+' | head -1)
        echo "run $i : $t threads = $v v/s" | tee -a "$RUNS"
    done
done
# "run 1 : 16 threads = 2763 v/s" -> champ 7 ; mediane de 3 = 2e valeur triee
{
    ref=""
    for t in 16 24 32; do
        med=$(awk -v t="$t" '$4 == t {print $7}' "$RUNS" | sort -n | sed -n 2p)
        if [ -z "$ref" ]; then
            ref=$med; printf "%2s threads : mediane %s v/s\n" "$t" "$med"
        else
            printf "%2s threads : mediane %s v/s  (%+.1f %%)\n" "$t" "$med" \
                "$(awk -v a="$med" -v b="$ref" 'BEGIN {print (a-b)/b*100}')"
        fi
    done
} | tee "$DIR/B_threads.txt"

echo
echo "== C. trace nsys a 16 threads ($NSYS_WORLDS mondes)"
(cd "$DIR" && "$NSYS" profile -t cuda --gpu-metrics-devices=all \
    -o "$(cygpath -w "$PWD/sat16")" -f true \
    ./bench_village.exe --cuda --seed 1 --worlds "$NSYS_WORLDS" --threads 16 --quiet \
    < /dev/null > bench16_nsys.txt 2>&1) \
  || { echo "(gpu-metrics refuse, nouvel essai sans)";
       (cd "$DIR" && "$NSYS" profile -t cuda -o "$(cygpath -w "$PWD/sat16")" -f true \
        ./bench_village.exe --cuda --seed 1 --worlds "$NSYS_WORLDS" --threads 16 --quiet \
        < /dev/null > bench16_nsys.txt 2>&1); }

REP="$(cygpath -w "$DIR/sat16.nsys-rep")"
"$NSYS" stats -r cuda_gpu_trace -f csv -q "$REP" > "$DIR/gpu_trace.csv"
"$NSYS" stats -r cuda_api_sum   -f csv -q "$REP" > "$DIR/api_sum.csv"
"$NSYS" export -t sqlite -o "$(cygpath -w "$DIR/sat16.sqlite")" -f true "$REP" > /dev/null 2>&1 || true

python -I "$HERE/analyze_saturation.py" nsys "$DIR/gpu_trace.csv" "$DIR/api_sum.csv" \
    "$DIR/sat16.sqlite" "$DIR/bench16_nsys.txt" | tee "$DIR/C_nsys.txt"
