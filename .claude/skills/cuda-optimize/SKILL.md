---
name: cuda-optimize
description: Applique UNE optimisation CUDA de c/cuda/TODO.md à la fois (shared memory, coalescence, constant memory, taille de bloc…), vérifie la bit-exactitude avec les tests du dépôt, puis mesure avec Nsight Compute (ncu) avant/après et garde ou annule le changement selon les chiffres. À utiliser quand l'utilisateur demande d'optimiser les kernels CUDA, de dérouler le TODO CUDA, ou de vérifier avec ncu si une modif de village_noise.cu améliore les performances.
---

# cuda-optimize — un item du TODO, mesuré

Cible : `c/cuda/village_noise.cu` (kernels `compute_random_offsets`,
`compute_noise_columns`, `compute_heights_scattered`, `compute_heightmap_rect`).
La liste des items et le journal des mesures sont dans `c/cuda/TODO.md`.

**Règle d'or : un seul item par passage.** Ne jamais empiler deux changements
avant de mesurer : on ne saurait plus lequel a eu quel effet.

Argument optionnel : le numéro d'item (ex. `2.3`). Sans argument, choisir ainsi :

1. Les items sont **numérotés par ordre de priorité**. Parcourir 2.1, 2.2, …
2. Sauter les `[x]` (gardés) et les `[-]` (rejetés).
3. Sauter un item dont une **dépendance** (« Dépend de 2.x ») n'est pas `[x]`.
   Si la dépendance est `[-]`, l'item est bloqué : le signaler à l'utilisateur.
4. Sauter un item **conditionnel** (« Ne faire que si… ») dont la condition
   n'est pas remplie d'après le journal (§4 du TODO). Le dire dans le résumé.
5. Prendre le premier restant, `[~]` ou `[ ]` ou `[m]`.

Types d'items :
- `[ ]` / `[~]` : changement de code, cycle complet (§2 à §7).
- `[m]` : **mesure seule**. Pas de code : profiler l'état courant (§4), lire les
  métriques citées, les consigner (§7), puis passer l'item en `[x]` avec la
  conclusion. Si l'item fixe des règles de décision (ex. 2.16), appliquer
  celles-ci aux items qui en dépendent, et le dire dans le résumé : quels items
  remontent, lesquels deviennent bloqués.
- **Balayage** (l'item demande de comparer plusieurs valeurs, ex. 2.5) : une
  mesure par valeur, dans `ncu_runs/<item>/<valeur>/`, avec le même protocole.
  Garder la meilleure valeur et consigner toutes les mesures.
- **Alternative** (ex. 2.7 face à 2.6) : la baseline est l'état courant, qui
  contient déjà l'item gardé. La candidate est l'alternative appliquée par-dessus
  ou à la place, comme l'item le précise.

## 0. Pré-requis — s'arrêter tout de suite si l'un manque

Machine de build : Windows + MSVC + CUDA (voir l'en-tête de `c/cuda/Makefile`),
shell MSYS/Git Bash.

```bash
"$CUDA_HOME/bin/nvcc" --version        # ou nvcc --version
# Sous Git Bash, seul ncu.bat existe (pas de ncu.exe dans le PATH) :
NCU="$(ls -d "/c/Program Files/NVIDIA Corporation/Nsight Compute "* | sort -V | tail -1)/ncu.bat"
"$NCU" --version
"$NCU" --list-chips | tr ',' '\n' | grep -i gb20   # la puce du GPU doit y figurer
NSYS="$(ls -d "/c/Program Files/NVIDIA Corporation/Nsight Systems "* | sort -V | tail -1)/target-windows-x64/nsys.exe"
nvidia-smi
```

- Pas de `nvcc` / `ncu` / GPU NVIDIA : **ne rien modifier**. Dire à
  l'utilisateur que la machine ne convient pas et s'arrêter.
- `ncu` trop ancien pour le GPU (la puce manque dans `--list-chips`, ex. RTX
  50xx = GB20x, il faut Nsight Compute 2025+) : même chose, le dire.
- `ERR_NVGPUCTRPERM` au premier `ncu` : les compteurs GPU sont réservés aux
  admins. Il faut lancer le terminal en administrateur, ou activer *NVIDIA Control
  Panel → Developer → Manage GPU Performance Counters → Allow all users*. Le
  dire à l'utilisateur, ne pas contourner.
- Arbre git propre en dehors de l'item en cours (`git status`). Sinon,
  demander quoi faire des autres changements.

Dossier de travail des mesures (non versionné) :
`c/cuda/ncu_runs/<item>/{baseline,candidate}/`. Ajouter `c/cuda/ncu_runs/` à
`.gitignore` s'il n'y est pas.

## 1. Lire l'item

Lire la section de l'item dans `c/cuda/TODO.md` : le pourquoi, les pièges
notés, les métriques à regarder, et la condition éventuelle (« ne faire que
si… »). Si une condition dépend d'une mesure précédente, la vérifier dans le
journal (§4 du TODO) avant de coder.

## 2. Baseline (code AVANT l'item)

La baseline est toujours **le code sans l'item**.

- Item `[ ]` : rien n'est encore modifié, l'arbre de travail est la baseline.
- Item `[~]` (déjà dans l'arbre de travail, pas encore commité) : le mettre de
  côté le temps de construire la baseline :
  ```bash
  git stash push -- c/cuda/village_noise.cu c/cuda/village_noise.cuh c/cuda/README.md
  ```
  puis le restaurer juste après le build (`git stash pop`), **même si le build
  échoue**.

Construire, profiler et exporter. **Pas de `make clean`** : il efface aussi les
outils non versionnés de l'utilisateur (`analyze_coverage.exe`,
`refine_seeds.exe`, `stats_pieces.exe`…) et oblige à tout recompiler (~1 min).
Seul `village_noise.cu` change d'un item à l'autre : supprimer son objet suffit,
`make` refait la lib et les liens.

```bash
cd c/cuda
rm -f village_noise.obj && make test_cuda bench_village
mkdir -p ncu_runs/<item>/baseline
cp test_cuda.exe bench_village.exe ncu_runs/<item>/baseline/
```

Puis lancer la commande de profil du §4 sur `ncu_runs/<item>/baseline/`.

## 3. Appliquer l'item

- Ne modifier que ce que l'item décrit. Respecter le style du fichier
  (commentaires en français sans accents dans le `.cu`, mêmes noms).
- **Bit-exactitude obligatoire** : ne pas réordonner les sommes d'octaves, ne
  pas toucher à `-fmad=false`, ne pas remplacer `d_lerp` / `d_lerp3`.
- Avec de la shared memory : `__syncthreads()` doit être atteint par **tous**
  les threads du bloc, donc avant tout `return` anticipé.
- Changement de layout : mettre à jour **tous** les lecteurs et écrivains
  (kernels 1, 2a, 2b, chemin d'extension `cuda_noise_heightmap_extend`, la
  sentinelle).
- *Thread coarsening* (plusieurs éléments par thread) : tableaux de taille
  **fixe à la compilation** (template ou `#define`) et boucles déroulables
  (`#pragma unroll`). Sinon, les tableaux partent en local memory (VRAM).
  Recalculer la taille de grille côté hôte (moins de threads) et gérer le reste
  quand le nombre d'éléments n'est pas multiple de K.

Avant de lancer `ncu`, vérifier les registres et les spills à la compilation :

```bash
rm -f village_noise.obj
make village_noise.obj NVCC_FLAGS_EXTRA="-Xptxas -v" 2>&1 | grep -E "Compiling entry|registers|spill"
```

`NVCC_FLAGS_EXTRA` est ajouté à la règle de `village_noise.obj` dans le
Makefile, et il est vide par défaut. Faire la même chose sur la baseline pour
comparer. Noter, pour chaque kernel modifié, les registres utilisés et les
`bytes spill stores/loads`. Un spill qui apparaît est un signal d'alerte, à
mentionner dans la décision.

Construire :

```bash
rm -f village_noise.obj && make test_cuda bench_village test_village_cuda test_village_seeds
```

`test_village_seeds.exe` est versionné : après les tests, le remettre dans son
état commité (`git checkout -- c/cuda/test_village_seeds.exe`) pour ne pas
polluer le diff.

## 4. Profil ncu (identique pour baseline et candidate)

Toujours **les mêmes binaires d'entrée, arguments et options** des deux côtés.

**Régime d'usage réel : 16 threads CPU** (`--threads 16`). Chaque thread CPU a
son `CudaNoiseContext` et son flux, et leurs kernels tournent en même temps :
le GPU est plein, et c'est le **travail total** qui compte, pas la latence
d'un lancement isolé. Le juge est donc le débit à 16 threads (§4d).

`ncu` et le nsys de 4b tournent à 1 thread CPU : `ncu` rejoue chaque kernel
seul de toute façon, et le profil à 1 thread est lisible et stable. Ils servent
à **expliquer** (instructions, divergence, coalescence, registres), pas à
décider. Un kernel isolé sous-remplit le GPU (environ 111 blocs pour 48 SM) :
un changement qui retire des threads peut ralentir le lancement isolé et
pourtant accélérer le régime à 16 threads (cf. TODO 2.3).

**Utiliser le script fourni**, ne pas en réécrire un. Il enchaîne 4a et 4b en
environ 30 s par côté :

```bash
cd c/cuda
bash ../../.claude/skills/cuda-optimize/profile.sh ncu_runs/<item>/baseline
bash ../../.claude/skills/cuda-optimize/profile.sh ncu_runs/<item>/candidate
```

Si un profil dépasse 2 minutes, quelque chose est bloqué : souvent une commande
qui attend stdin, comme un `cat > fichier` sans heredoc. Vérifier avec
`tasklist | grep -iE "ncu|nsys|bench"` plutôt qu'attendre.

Le détail des commandes est ci-dessous, pour référence ou pour un cas
particulier, par exemple un balayage.

### 4a. Profil allégé (par défaut)

**Ne pas utiliser `--set full` par défaut.** Il rejoue chaque kernel plus de 40
fois : environ 10 min par profil bench et des rapports de 17 à 50 Mo.
`--metrics` ne collecte que les 18 métriques que lit `compare_ncu.py`, en
**environ 10 s** et 0,75 Mo, avec les mêmes valeurs (moins de 0,2 % d'écart,
vérifié le 2026-10-30).

**Garder 200 lancements sur le bench.** Le coût vient des métriques, pas du
nombre de lancements, et 60 lancements donnent un mélange de tailles différent
(temps de 2b décalé de 19 %).

```bash
D=ncu_runs/<item>/<baseline|candidate>
export CUBIOMES_LAYER_CACHE=0
M=$(python -I ../../.claude/skills/cuda-optimize/compare_ncu.py --metrics-list)

# Micro : heightmap 200x200 déterministe -> kernels 0, 1, 2a, 2b
"$NCU" --metrics "$M" --launch-skip 4 --launch-count 40 \
    --kernel-name regex:"compute_" \
    -o $D/micro -f  $D/test_cuda.exe 1 0 0 200 1

# Réel : vrais villages, chemin d'extension inclus -> 1 thread, peu de mondes
"$NCU" --metrics "$M" --launch-skip 50 --launch-count 200 \
    --kernel-name regex:"compute_" \
    -o $D/bench -f  $D/bench_village.exe --cuda --seed 1 --worlds 3 --threads 1 --quiet

# ncu 2026+ ecrit des .ncu-repz (compresses)
for r in micro bench; do
  "$NCU" --import $D/$r.ncu-repz --csv --page raw --print-units base > $D/$r.csv
done
```

Comparer (`PYTHONIOENCODING=utf-8` évite une erreur d'encodage de la console
Windows sur les accents et les ✓/✗) :

```bash
export PYTHONIOENCODING=utf-8
python -I ../../.claude/skills/cuda-optimize/compare_ncu.py \
    ncu_runs/<item>/baseline/micro.csv ncu_runs/<item>/candidate/micro.csv
python -I ../../.claude/skills/cuda-optimize/compare_ncu.py \
    ncu_runs/<item>/baseline/bench.csv ncu_runs/<item>/candidate/bench.csv
```

Le **micro** ne fait que 6 à 8 lancements par kernel, de tailles différentes :
son temps médian est indicatif. Pour les temps, se fier au **bench** et à 4b.

### 4b. Temps réels avec Nsight Systems (rapide, à faire aussi)

`ncu` verrouille les fréquences et rejoue les kernels. Nsight Systems mesure
les vrais temps, sans rejeu, et la mesure est très stable (moins de 0,2 %
d'écart entre deux runs). Le faire 2 fois par côté :

```bash
for i in 1 2; do
  (cd $D && "$NSYS" profile -t cuda -o "$(cygpath -w $PWD/nsys_$i)" -f true \
      ./bench_village.exe --cuda --seed 1 --worlds 20 --threads 1 --quiet > /dev/null)
  "$NSYS" stats -r cuda_gpu_kern_sum -f csv -q "$(cygpath -w $D/nsys_$i.nsys-rep)" \
    | tail -n +2 | awk -F, '{split($9,n,"("); printf "%-26s n=%s avg=%.1fus med=%.1fus\n", n[1], $3, $4/1000, $5/1000}' | tr -d '"'
done
```

### 4c. Creuser un kernel précis (seulement si besoin)

Quand le profil allégé ne suffit pas à expliquer un chiffre (*Memory Workload
Analysis*, *Source Counters* avec les lignes fautives…), profiler **un seul
kernel, sur quelques lancements**, avec le set complet :

```bash
"$NCU" --set full --kernel-name compute_noise_columns --launch-skip 10 --launch-count 3 \
    -o $D/full_k1 -f  $D/bench_village.exe --cuda --seed 1 --worlds 3 --threads 1 --quiet
"$NCU" --import $D/full_k1.ncu-repz --page details
```

### 4d. Débit de bout en bout à 16 threads, le juge final

**Toujours le faire**, avec le script fourni. Il jette un run de chauffe par
côté (le 1er run est souvent 5 % plus bas), puis fait 10 runs en alternant les
côtés, et affiche les médianes et l'écart :

```bash
cd c/cuda
bash ../../.claude/skills/cuda-optimize/throughput.sh ncu_runs/<item> baseline candidate
# balayage : autant de côtés que de valeurs, ex. ncu_runs/2.5 64 32 128 256
```

Chaque run fait 400 mondes (environ 5 s, `WORLDS=…` pour changer) : compter
environ 2 min pour 2 côtés. Avec 100 mondes (1,3 s par run), le bruit montait
à ±7 % une fois le GPU accéléré (mesuré le 2026-10-30 sur 2.8) ; avec 400, la
plupart des runs tiennent dans ±1 %. Si l'écart est entre 1 et 3 %, relancer
une 2e série et regarder si le signe se confirme. Les débits à 400 mondes sont
plus hauts qu'à 100 (démarrage mieux amorti) : ne comparer que des séries
faites avec le même nombre de mondes.

### 4e. Saturation du GPU à 16 threads (item 2.16, et à refaire après un gros gain)

Ce script répond à une question en amont de tous les items de kernel : **le GPU
est-il le goulot ?** Il mesure l'attente GPU vue des threads (borne d'Amdahl),
le débit à 16, 24 et 32 threads (sur-souscription), et une trace nsys à 16
threads (union des intervalles de kernels, transferts, appels CUDA bloquants,
`SM Active`). Environ 5 min :

```bash
cd c/cuda && rm -f village_noise.obj && make bench_village
bash ../../.claude/skills/cuda-optimize/saturation.sh ncu_runs/<item>
```

Les résultats sont dans `ncu_runs/<item>/{A_amdahl,B_threads,C_nsys}.txt`.
Les règles de décision sont dans l'item 2.16 du TODO.

Si `--gpu-metrics-devices` est refusé (pilote, droits), le script relance sans :
la partie `SM Active` manque alors, le reste est valable. Le refaire après
tout item qui gagne plus de 10 % de débit : le goulot a pu changer de côté.

Ne pas confondre avec la ligne « GPU occupé à X % du temps mural » de
`bench_village` : elle additionne les intervalles entre événements de chaque
stream, qui se chevauchent à 16 threads. Elle peut donc dépasser 100 % et ne
dit rien de la saturation. L'union des intervalles de la trace nsys, si.

## 5. Valider la correction (avant de regarder les perfs)

```bash
./test_cuda.exe                 # chaque ligne doit finir par "OK", aucune "ECHEC"
make run-village                # C vs CUDA sur la génération de villages
make seeds                      # régressions sur des villages précis
```

Une seule différence suffit : l'item est **faux**. Corriger, ou annuler
(`git checkout -- <fichiers>`) et marquer `[-]` avec la raison. Ne jamais
garder un gain de perf qui casse la bit-exactitude.

## 6. Décider

Lire d'abord le *Speed Of Light* du kernel visé, c'est-à-dire les lignes
`SM throughput %` et `mem throughput %` de `compare_ncu.py` : est-il limité par
le calcul (SM throughput élevé) ou par la mémoire (Memory throughput élevé) ?
Un gain mémoire sur un kernel limité par le calcul ne se verra pas dans le temps.
C'est normal, et ça justifie de rejeter l'item.

Le critère principal est le **débit à 16 threads** (§4d), le régime d'usage
réel. Les temps de kernel à 1 thread (ncu bench, nsys) expliquent, ils ne
tranchent pas seuls.

- **Garder `[x]`** : le débit à 16 threads monte de plus de 1 % en médiane, et
  le signe se confirme sur 2 séries si l'écart est inférieur à 3 %. Les
  métriques `ncu` doivent expliquer le gain (moins d'instructions, moins de
  divergence, moins de lectures…). Un temps de kernel isolé qui monte n'est
  pas bloquant, mais le noter dans la décision.
- **Rejeter `[-]`** : le débit à 16 threads ne monte pas, ou baisse. Annuler le
  code (`git checkout -- …`). L'item reste documenté avec ses chiffres, pour ne
  pas le retenter.
- **Pas de cas ambigu** : un débit dans le bruit, c'est un rejet, même si une
  métrique `ncu` s'améliore nettement (cf. 2.4, 2.8). Ne jamais départager
  sur le temps à 1 thread, ni lancer de mesure à 1 thread pour trancher : en
  usage réel, l'utilisateur est toujours à 16 threads. Dans un balayage, une
  égalité garde la valeur actuelle.

Cas attendus, à ne pas confondre avec une régression :
- *thread coarsening* : le ratio de threads actifs par warp baisse un peu (la
  divergence interne augmente), et l'occupancy peut baisser (plus de registres).
  C'est acceptable si le débit à 16 threads monte.
- moins de threads lancés : `sm__warps_active` peut baisser sans que ce soit
  un problème.

## 7. Consigner

1. Dans `c/cuda/TODO.md` : passer le statut de l'item à `[x]` ou `[-]` et
   ajouter une ligne par métrique pertinente au journal (§4), avec la date du
   jour, le kernel, avant, après et la décision. Au **premier passage**, remplir
   aussi la ligne « GPU » du journal (modèle, version de ncu) et la répartition
   du temps entre kernels mesurée sur la baseline.
2. **Réévaluer l'ordre** des items restants si une mesure contredit une
   hypothèse du TODO. Par exemple : le kernel 1 n'est pas limité par le calcul,
   ou 2b ne pèse presque rien dans le temps total. Proposer le nouvel ordre à
   l'utilisateur avant de renuméroter. Renuméroter casse les références du
   README (`TODO.md §2.1`) : les mettre à jour en même temps.
3. Si l'item est gardé et change un comportement documenté, mettre à jour
   `c/cuda/README.md`.
4. Si l'item est gardé : **un commit par item**, seulement si l'utilisateur
   l'a demandé. Sinon, proposer le message de commit. Ça compte : la baseline
   de l'item suivant est l'état commité (ou, à défaut, l'arbre de travail avec
   les items gardés).
5. Résumer à l'utilisateur : l'item, le verdict, les 3 à 4 chiffres clés, et
   l'item suivant proposé.
