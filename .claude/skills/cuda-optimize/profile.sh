#!/bin/bash
# profile.sh — profil allege d'un cote (baseline ou candidate), ~30 s en tout.
#
# Usage, depuis c/cuda :
#   bash ../../.claude/skills/cuda-optimize/profile.sh ncu_runs/<item>/<baseline|candidate>
#
# Le dossier doit contenir test_cuda.exe et bench_village.exe. Produit :
#   micro.csv, bench.csv   (ncu, metriques de compare_ncu.py)  -> SKILL.md §4a
#   nsys_1.txt, nsys_2.txt (vrais temps des kernels)           -> SKILL.md §4b
set -euo pipefail

D=${1:?usage: profile.sh <dossier contenant test_cuda.exe et bench_village.exe>}
D=$(cd "$D" && pwd)
HERE=$(cd "$(dirname "$0")" && pwd)

NCU="$(ls -d "/c/Program Files/NVIDIA Corporation/Nsight Compute "* | sort -V | tail -1)/ncu.bat"
NSYS="$(ls -d "/c/Program Files/NVIDIA Corporation/Nsight Systems "* | sort -V | tail -1)/target-windows-x64/nsys.exe"
M=$(python -I "$HERE/compare_ncu.py" --metrics-list)
export CUBIOMES_LAYER_CACHE=0

cd "$D"

echo "== ncu micro"
"$NCU" --metrics "$M" --launch-skip 4 --launch-count 40 --kernel-name regex:"compute_" \
    -o micro -f ./test_cuda.exe 1 0 0 200 1 < /dev/null 2>&1 | grep -E "ERR|Report" || true

echo "== ncu bench"
"$NCU" --metrics "$M" --launch-skip 50 --launch-count 200 --kernel-name regex:"compute_" \
    -o bench -f ./bench_village.exe --cuda --seed 1 --worlds 3 --threads 1 --quiet < /dev/null 2>&1 \
    | grep -E "ERR|Report" || true

for r in micro bench; do
    "$NCU" --import $r.ncu-repz --csv --page raw --print-units base > $r.csv
done

for i in 1 2; do
    echo "== nsys $i"
    "$NSYS" profile -t cuda -o "$(cygpath -w "$D/nsys_$i")" -f true \
        ./bench_village.exe --cuda --seed 1 --worlds 20 --threads 1 --quiet < /dev/null > /dev/null 2>&1
    "$NSYS" stats -r cuda_gpu_kern_sum -f csv -q "$(cygpath -w "$D/nsys_$i.nsys-rep")" 2>/dev/null \
        | tail -n +2 | tr -d '"' \
        | awk -F, '$9 != "" {split($9,n,"("); printf "%-26s n=%s avg=%.1fus med=%.1fus\n", n[1], $3, $4/1000, $5/1000}' \
        | tee nsys_$i.txt
done
