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
  conclusion.
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
ncu --version                          # Nsight Compute, souvent dans
                                       # "C:/Program Files/NVIDIA Corporation/Nsight Compute <ver>/"
nvidia-smi
```

- Pas de `nvcc` / `ncu` / GPU NVIDIA : **ne rien modifier**. Dire à
  l'utilisateur que la machine ne convient pas et s'arrêter.
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

Construire, profiler et exporter :

```bash
cd c/cuda
make clean && make test_cuda bench_village
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
make clean && make test_cuda bench_village test_village_cuda test_village_seeds
```

## 4. Profil ncu (identique pour baseline et candidate)

Toujours **les mêmes binaires d'entrée, arguments et options** des deux côtés.

```bash
D=ncu_runs/<item>/<baseline|candidate>
export CUBIOMES_LAYER_CACHE=0

# Micro : heightmap 200x200 déterministe -> kernels 0, 1, 2a, 2b
ncu --set full --launch-skip 4 --launch-count 40 \
    --kernel-name regex:"compute_" \
    -o $D/micro -f  $D/test_cuda.exe 1 0 0 200 1

# Réel : vrais villages, chemin d'extension inclus -> 1 thread, peu de mondes
ncu --set full --launch-skip 50 --launch-count 200 \
    --kernel-name regex:"compute_" \
    -o $D/bench -f  $D/bench_village.exe --cuda --seed 1 --worlds 3 --threads 1 --quiet

for r in micro bench; do
  ncu --import $D/$r.ncu-rep --csv --page raw --print-units base > $D/$r.csv
done
```

Comparer :

```bash
python -I ../../.claude/skills/cuda-optimize/compare_ncu.py \
    ncu_runs/<item>/baseline/micro.csv ncu_runs/<item>/candidate/micro.csv
python -I ../../.claude/skills/cuda-optimize/compare_ncu.py \
    ncu_runs/<item>/baseline/bench.csv ncu_runs/<item>/candidate/bench.csv
```

Pour creuser un kernel précis (sections *Memory Workload Analysis*, *Source
Counters* avec les lignes fautives) :
`ncu --import $D/micro.ncu-rep --page details --kernel-name compute_heightmap_rect`.

Débit de bout en bout, qui reste le juge final (3 runs, prendre la médiane) :

```bash
for i in 1 2 3; do ./ncu_runs/<item>/<side>/bench_village.exe --cuda --seed 1 --worlds 100 --threads 16 --quiet | grep "débit"; done
```

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

Lire d'abord la section *GPU Speed Of Light* du kernel visé : est-il limité par
le calcul (SM throughput élevé) ou par la mémoire (Memory throughput élevé) ?
Un gain mémoire sur un kernel limité par le calcul ne se verra pas dans le temps.
C'est normal, et ça justifie de rejeter l'item.

- **Garder `[x]`** : la métrique visée par l'item s'améliore dans le sens
  attendu, le temps du kernel baisse de plus de 2 % (au-delà du bruit), aucun
  autre kernel ne régresse de plus de 2 %, et le débit `bench_village` ne baisse pas.
- **Rejeter `[-]`** : pas de gain, ou une régression. Annuler le code
  (`git checkout -- …`). L'item reste documenté avec ses chiffres, pour ne pas
  le retenter.
- **Ambigu** (la métrique visée s'améliore mais le temps ne bouge pas) :
  présenter les chiffres à l'utilisateur et le laisser trancher.

Cas attendus, à ne pas confondre avec une régression :
- *thread coarsening* : le ratio de threads actifs par warp baisse un peu (la
  divergence interne augmente), et l'occupancy peut baisser (plus de registres).
  C'est acceptable si le temps baisse.
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
