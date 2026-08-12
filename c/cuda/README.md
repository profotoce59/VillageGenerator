# Génération de heightmap sur GPU (CUDA)

Portage CUDA de la partie coûteuse de la génération de terrain : le bruit de
surface 3D (`sampleSurfaceNoise`, 40 octaves de Perlin par valeur) et le scan de
colonne qui en déduit la hauteur du premier bloc solide.

Le résultat est **identique au bit près** à l'implémentation C
(`generate_column_from_y` dans [`../surface_gen.c`](../surface_gen.c)), ce que
le test vérifie systématiquement.

## Utilisation

```bash
make test-cuda
```

depuis la racine du dépôt (ou `make -C c/cuda run`). Paramètres surchargeables :

```bash
make test-cuda SEED=42 X0=-5000 Z0=-7000 SIZE=200 REPEATS=5
```

Le binaire prend les mêmes arguments directement :
`./test_cuda.exe [seed] [x0] [z0] [size] [repeats]`.

## Ce que fait le test

| Test | Contenu |
|------|---------|
| 1    | Heightmap `size x size` (100x100 par défaut) générée par le C puis par CUDA, comparée point par point, avec les deux prédicats (`NOT_AIR`, `STONE`/`WORLD_SURFACE_WG`) |
| 1b   | 2000 points dispersés — valide le chemin « requêtes éparses » utilisé par le générateur de villages |
| 2    | Benchmark sur la même zone, avec le détail du temps GPU (upload / kernels / download) |
| 2b   | Passage à l'échelle sur 100², 200², 400² |

## Génération de village accélérée

```bash
CUBIOMES_LAYER_CACHE=0 make -C c/cuda run-village
```

Le jigsaw est séquentiel : la hauteur d'une pièce détermine la position de la
requête suivante, donc les requêtes ne peuvent pas être groupées une par une.
En revanche toutes les pièces d'un village tiennent dans les bounds du
`VoxelShape` (±80 blocs du centre), donc l'Assembler fait calculer la heightmap
entière de la zone en un lancement, avant d'assembler. Les ~190 requêtes
deviennent ensuite de simples lectures de tableau.

Le branchement se fait par l'interface `HeightProvider`
([`../SurfaceGenWrapper.hpp`](../SurfaceGenWrapper.hpp)) : sans provider
installé, le comportement est exactement celui du C d'origine. Les deux chemins
exécutent donc le même `VillageGenerator`.

Mesuré sur 559 villages / 53 658 pièces :

| | C seul | C + CUDA | gain |
|---|---|---|---|
| génération totale | 19,31 ms/village | 10,74 ms/village | **1,80×** |
| dont hauteurs | 57,0 % du temps | 16,7 % | **6,14×** |
| pièces produites | | | **identiques** |

Le plafond d'Amdahl est ici 2,3× (les hauteurs représentaient 57 % du temps) ;
à 1,80× la partie hauteur est donc largement traitée, et le reste du gain se
trouverait désormais dans le jigsaw lui-même (VoxelShape, pools, chaînes), pas
dans le terrain.

À noter : on calcule ~29 000 points par village pour n'en consommer que ~190.
C'est voulu — le GPU calcule une colonne 27× moins cher que le CPU, donc même
avec 6× de gaspillage l'opération reste gagnante. La portée des requêtes
(médiane 74 blocs, p90 84, max 85 sur 105 villages) laisse peu de marge pour
rétrécir la zone.

## Benchmark de débit (10 000 villages)

Deux jobs VS Code dans [`../../.vscode/launch.json`](../../.vscode/launch.json) :
**Bench villages — C (CPU)** et **Bench villages — CUDA (GPU)**.

> Lancer avec **Exécuter sans débogage** (Ctrl+F5). Sous `cppvsdbg` le processus
> est fortement ralenti et les deux jobs ne sont plus comparables.

En ligne de commande :

```bash
make -C c/cuda bench-c
```

```bash
make -C c/cuda bench-cuda
```

(`BENCH_SEED` et `BENCH_COUNT` sont surchargeables.)

Les deux jobs lancent **le même binaire**, seul `--c` / `--cuda` change. C'est
délibéré : opposer un binaire mingw à un binaire MSVC mesurerait surtout la
différence entre les deux compilateurs. Chaque job imprime un checksum FNV de
toutes les pièces de tous les villages — **s'ils sont égaux, les deux backends
ont produit exactement les mêmes villages** et la comparaison de temps est
valable.

L'énumération est déterministe : à partir de `--seed`, on parcourt les positions
de village de la structure seed puis les world seeds, jusqu'à `--count`.

## Recherche de villages (forgerons)

Job VS Code **Recherche villages — CUDA (> 5 forgerons)** : part d'une structure
seed aléatoire (imprimée en première ligne pour pouvoir rejouer avec `--seed`),
parcourt les seeds sans fin, et journalise chaque village au-delà du seuil, sur
la console et dans `c/cuda/village_finds.log`.

Une variante **seuil au choix** demande le seuil au lancement.

En ligne de commande :

```bash
make -C c/cuda search SMITHS=6
```

Options de [`search_village_cuda.cpp`](search_village_cuda.cpp) : `--seed`,
`--smiths`, `--pieces`, `--worlds`, `--regions`, `--max-seeds`, `--out`,
`--index`/`--threads` (partitionnement multi-processus), `--cpu` (bascule le
backend hauteurs pour comparer les débits).

### Forgerons comptés

Les 4 mêmes noms que `test_village_generation.cpp` :

- `plains/houses/plains_weaponsmith_1`
- `desert/houses/desert_weaponsmith_1`
- `savanna/houses/savanna_weaponsmith_2`
- `taiga/houses/taiga_weaponsmith_1`

Les pools contiennent trois autres forgerons d'armes —
`savanna_weaponsmith_1`, `taiga_weaponsmith_2` et `snowy/houses/snowy_weapon_smith_1`
— **volontairement exclus**. Ne pas les ajouter en croyant corriger un oubli.
Les `tool_smith` et `armorer` ne comptent pas non plus.

## Multi-threading et plafond GPU

Un thread = une seed, avec **son propre `CudaHeightProvider`** (le contexte CUDA
et la zone pré-calculée ne sont pas partageables). Aucune coordination
inter-thread : `SurfaceGenWrapper::setHeightProvider` est `thread_local`.

Mesuré sur RTX 5070 + Ryzen 7 9700X, 4383 villages :

| threads | C | CUDA |
|---|---|---|
| 1 | 83/s | 285/s |
| 4 | 284/s | 910/s |
| 6 | — | 1068/s |
| 8 | 449/s | 1117/s |

Le GPU sature vers 6 threads. 4 threads en atteignent déjà ~85 %.

### Pourquoi le batching de plusieurs villages par lancement n'aurait rien donné

Les événements CUDA mesurent, à 1 thread : **1,19 ms de kernels contre 0,29 ms
de surcoût hôte** par lancement. Le surcoût est minoritaire, et le
multi-threading le recouvre déjà (un thread qui attend le GPU laisse le CPU aux
autres). Le mur est le temps de calcul des kernels, pas le nombre de lancements.

### Ce qui a effectivement relevé le plafond : le plancher de scan

Avec le prédicat NOT_AIR, `get_block_from_noise` renvoie WATER dès que
`y < seaLevel`. Le scan de hauteur touche donc **toujours** un bloc dans la
cellule contenant `y = seaLevel-1` (soit la cellule 7 avec seaLevel=63 et des
cellules de 8 blocs) et ne descend jamais plus bas. Les cellules 0 à 6 étaient
calculées pour rien — environ la moitié du volume, `startSizeY` valant 11 à 15.

`height_scan_floor()` calcule ce plancher et le kernel ne produit plus que la
tranche `[minCellY, startSizeY)`. Avec STONE le scan peut aller jusqu'en bas,
donc pas de plancher dans ce cas.

Résultat : temps de kernels −41 %, débit **722 → 1068 villages/s** à 6 threads,
à hauteurs strictement identiques.

## Avertissement : cache de layer cubiomes

`cubiomes/layers.c` contient un cache maison (`mapCached`) qui **renvoie des
biomes faux pour les requêtes 1x1**. Le calcul groupé des biomes utilisé ici
n'appelle pas `genBiomes` de la même façon que le chemin d'origine, ce qui rend
l'incohérence visible : quelques villages sur cent diffèrent.

Ce n'est pas un problème CUDA. Le reproducteur
[`../test_layer_cache_consistency.c`](../test_layer_cache_consistency.c) le
montre en C pur, sans GPU :

```bash
make -C c test_layer_cache_consistency && ./c/test_layer_cache_consistency.exe
```

Avec le cache actif, la cellule de biome (-1,-1) de la seed 281474976710703
vaut 0 en lecture unitaire et 2 en lecture groupée ; sans le cache elle vaut 2
dans tous les cas. Le contournement est `CUBIOMES_LAYER_CACHE=0`, avec lequel
les 53 658 pièces sont identiques entre les deux chemins.

## API

Deux niveaux :

- [`village_noise.cuh`](village_noise.cuh) — API C bas niveau
  (`cuda_noise_init`, `cuda_noise_heightmap`, `cuda_noise_batch_heights`).
- [`village_noise_host.hpp`](village_noise_host.hpp) — `CudaHeightBatcher`,
  qui prend directement un `CubiomesContext` + un `SurfaceGen` et se charge de
  la conversion, du travail biome côté CPU et du dimensionnement des buffers.

```cpp
CudaHeightBatcher batcher(&ctx, &sg);
std::vector<int> heights(100 * 100);
batcher.heightmap(x0, z0, 100, 100, HEIGHT_PRED_NOT_AIR, heights.data());
// heights[iz * 100 + ix]
```

## Répartition CPU / GPU

| Étape | Où | Pourquoi |
|-------|----|----------|
| `getBiome` → depth/scale par cellule | CPU | pile de layers cubiomes, séquentielle ; groupée en un seul `genBiomes()` pour toute la zone (`cubiomes_get_depth_and_scale_grid`) |
| `randomOffset` (16 octaves `octdepth`) | GPU | bruit pur, 1 thread par colonne |
| Bruit de surface (40 octaves) | GPU | 1 thread par (colonne, y) — c'est le gros du travail |
| Interpolation trilinéaire + scan | GPU | 1 thread par point |

## Contraintes de build (non évidentes)

- **Version CUDA.** Le toolkit doit connaître l'architecture du GPU installé.
  Une RTX 50xx est `sm_120`, que **CUDA 11.x ne sait pas compiler** — ne pas se
  contenter du `nvcc` qui traîne en premier dans le `PATH`. Le Makefile pointe
  explicitement sur CUDA 13.1 ; surchargez `CUDA_HOME` / `GPU_ARCH` si besoin.
- **`-fmad=false` est obligatoire.** Sans ce flag, nvcc contracte
  `from + part * (to - from)` en FMA. Le résultat reste mathématiquement juste
  mais diverge du CPU au dernier bit, ce qui suffit à faire basculer des
  hauteurs aux frontières de cellules.
- **Host compiler.** nvcc utilise MSVC sous Windows, donc cubiomes,
  `surface_gen.c` et `cubiomes_integration.c` sont recompilés ici avec MSVC
  plutôt que réutilisés depuis le build mingw de [`../Makefile`](../Makefile).
- L'ordre des sommations flottantes est significatif partout : accumulation
  séquentielle des octaves (pas de réduction en arbre) et `d_lerp3` calque
  l'ordre des arguments de `lerp3` de cubiomes.
