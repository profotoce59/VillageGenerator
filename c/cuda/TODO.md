# TODO — optimisations CUDA

Issu de la review de `village_noise.cu` (2026-10-29/30), faite à partir des notes
de `.claude/documentation_cuda.txt` : shared memory, coalescence, registres,
vectorisation, tensor cores.

Chaque item s'applique **seul**, se valide (bit-exactitude) puis se mesure avec
`ncu` avant de passer au suivant. Le skill `/cuda-optimize` déroule ce cycle.

**Les items sont numérotés dans l'ordre de priorité.** Le skill prend le premier
qui n'est ni gardé ni rejeté et dont les dépendances et conditions sont remplies.

Statuts : `[ ]` à faire · `[~]` implémenté, non mesuré · `[x]` gardé · `[-]` rejeté (avec la raison et la mesure) · `[m]` mesure seule, pas de code

---

## 1. État des lieux (review)

| Kernel | Shared memory | Coalescence | Réutilisation en registres |
|---|---|---|---|
| `compute_random_offsets` (0) | ✅ tables `perm` octdepth (4 Ko) | ✅ | – |
| `compute_noise_columns` (1) | ✅ tables `perm` surface (10 Ko) | ✅ écriture ; `sn->oct[i]` et `cfg` lus en global (accès uniforme → broadcast) | ❌ la partie x/z de Perlin est recalculée pour chaque `y` |
| `compute_heightmap_rect` (2b) | ❌ | ✅ écriture ; ⚠️ lectures `noiseGrid` strided (avant 2.1) | ❌ 8 coins rechargés à chaque `cellY`, et par chacune des 16 positions d'une même cellule |
| `compute_heights_scattered` (2a) | ❌ | ⚠️ `cornerIndices[q*4+k]` strided ; `noiseGrid` aléatoire par nature | ❌ idem 2b pour les lignes |

Mise en perspective :
- le kernel 1 est très probablement **limité par le calcul** (40 octaves de
  Perlin en FP64, et le FP64 tourne à 1/32 ou 1/64 du FP32 sur RTX). Seuls les
  items qui **retirent du calcul** (2.3) y feront gagner du temps. À confirmer
  avec la section *Speed Of Light* dès la première mesure.
- les kernels 2a et 2b sont plutôt limités par la mémoire et la latence, avec
  de la **divergence** : chaque thread s'arrête à une hauteur différente, et le
  warp attend son thread le plus lent.

---

## 2. Items, par ordre de priorité

### 2.1 `[~]` Transposer `noiseGrid` en y-major — kernels 1, 2a, 2b

**Priorité 1** : déjà implémenté, et prérequis de 2.2, 2.6 et 2.7. C'est aussi
la mesure de référence : profiler la baseline donne la répartition du temps
entre kernels et leur goulot (*Speed Of Light*), à reporter au journal (§4).
Il faudra **réévaluer l'ordre des items suivants** avec ces chiffres.

**Avant** : `noiseGrid[col * allocStride + y]`. Dans 2b, des threads voisins en x
lisent, au même `cellY`, des colonnes espacées de `allocStride * 8` octets (136 à
264 o). Résultat : environ 9 secteurs de 32 o par requête pour 9 doubles utiles.

**Après** : `noiseGrid[y * numColumns + col]`. Les colonnes voisines sont
contiguës : 2 à 3 secteurs par requête. Le kernel 1 fait varier `col` le plus
vite (`col = tid % numColumns`), son écriture reste coalescée. `allocStride`
devient `allocRows`. L'extension ajoute des lignes sans rien déplacer.

Implémenté **sans compilation ni test** (pas de machine CUDA ce jour-là).

À mesurer :
- 2b / 2a : secteurs par requête `ld` global, et `gpu__time_duration.sum`, doivent baisser
- 1 : `gpu__time_duration.sum` ne doit pas régresser

### 2.2 `[ ]` Réutiliser la ligne `cellY+1` en registres dans `scan_column` — kernels 2a, 2b

Dépend de 2.1.

`scan_column` charge 8 valeurs à chaque `cellY` : 4 sur la ligne `cellY` (row0)
et 4 sur la ligne `cellY+1` (row1). À l'itération suivante (`cellY-1`), la row1
est exactement la row0 qu'on vient de lire. Garder ces 4 valeurs en registres :

```cpp
// avant la boucle : charger la ligne startSizeY (row1 de la 1re iteration)
double t0 = row[c0], t1 = row[c1], t2 = row[c2], t3 = row[c3];
for (cellY = startSizeY - 1; ...) {
    double b0 = rowY[c0], b1 = ..., b2 = ..., b3 = ...;   // 4 lectures au lieu de 8
    ... lerp3 avec (b*, t*) ...
    t0 = b0; t1 = b1; t2 = b2; t3 = b3;                  // la ligne du bas devient celle du haut
}
```

Lectures divisées par 2, arithmétique identique, donc bit-exact.

À mesurer : `l1tex__t_requests_pipe_lsu_mem_global_op_ld.sum` (environ ÷2), temps de 2a et 2b.

### 2.3 `[ ]` Kernel 1 : plusieurs `y` par thread (*thread coarsening*)

Dépend de 2.1. C'est **l'item qui attaque le goulot principal** (le calcul FP64 du kernel 1).

Dans `d_samplePerlin`, tout ce qui vient de x/z ne dépend pas de `y` : `d1`,
`d3`, `floor(d1)`, `floor(d3)`, `h1`, `h3`, `t1`, `t3` (2 polynômes de fade) et
les lookups `idx[h1]` / `idx[h1+1]`. De même dans `d_sampleSurfaceNoise`,
`dx`, `dz`, `dx2` et `dz2` ne dépendent pas de `y`. Un thread qui traite K
valeurs de `y` d'une même colonne fait ce travail une seule fois par octave.

- Mapping : `col = tid % numColumns`, `yBase = yFrom + (tid / numColumns) * K`.
  L'écriture reste coalescée, car les threads voisins traitent toujours des
  colonnes voisines.
- Écrire une variante `d_samplePerlinK` qui prend K valeurs de `d2` et rend K
  résultats. Garder **exactement** les mêmes opérations, dans le même ordre, pour
  chaque `y` : bit-exact.
- Gérer la dernière tranche quand `(yTo - yFrom) % K != 0`, et le cas `d2 == 0`
  (y = 0), qui suit un autre chemin.
- Les accumulateurs `minNoise`, `maxNoise` et `mainNoise` deviennent des
  tableaux `[K]` à **taille fixe** (template ou `#define`), sinon ils partent
  en local memory.
- Essayer K = 2 puis 4. Le risque est la pression sur les registres : surveiller
  `launch__registers_per_thread` et les accès en local memory (spills,
  `l1tex__t_sectors_pipe_lsu_mem_local_op_ld.sum` doit rester à 0). Moins de
  threads au total, c'est aussi moins de blocs pour remplir les SM.

Gain estimé : 20 à 30 % du travail de Perlin (estimation non mesurée).

À mesurer : temps du kernel 1, `smsp__inst_executed.sum`, registres par thread, spills, occupancy.

### 2.4 `[ ]` Paramètres d'octave et config par valeur en argument de kernel — kernels 0, 1

`sn->oct[i]` (`GpuPerlinParams`) et `cfg` sont lus par tous les threads d'un
warp à la même adresse. C'est le cas d'usage de la constant memory (broadcast
en un cycle).
- ⚠️ **Pas de `__constant__` + `cudaMemcpyToSymbol`** : la constant memory est
  globale au module. Or chaque thread CPU (`--threads N`) a son propre
  `CudaNoiseContext`, avec sa seed. Un symbole partagé serait écrasé d'un
  thread à l'autre.
- Variante sûre : passer une struct par valeur, `GpuOctParams { GpuPerlinParams oct[40]; }`
  (2560 o) plus `GpuSurfaceGenConfig` (environ 100 o), soit moins de 4 Ko
  d'arguments. Les arguments de kernel vivent dans un banc de constant memory
  propre à chaque lancement. Marquer `const __grid_constant__` (CUDA 11.7+, sm_70+).
- Les tables `perm` restent en shared memory : en constant memory, leurs accès
  divergents seraient sérialisés.

À mesurer : temps du kernel 1, `smsp__inst_executed_op_global_ld.sum` (doit baisser).

### 2.5 `[ ]` Taille de bloc du kernel 1 (`NOISE_BLOCK` 64 / 128 / 256 / 512)

À faire **après 2.3**, qui change le nombre de threads.

Chaque bloc recopie 10 Ko de `perm`, donc des blocs plus gros amortissent mieux
la copie. Mais 10 Ko de shared par bloc limitent le nombre de blocs par SM, et
nos lancements ne font qu'une centaine de blocs (README, § multi-threading) : des
blocs plus gros, c'est moins de SM occupés. Balayer les tailles et comparer le temps,
`sm__warps_active.avg.pct_of_peak_sustained_active` et le débit `bench_village`.

Cas particulier du skill : pas une baseline contre une candidate, mais une
mesure par taille. Garder la meilleure.

### 2.6 `[ ]` Kernel 2b : 4 positions x par thread (*thread coarsening*)

Dépend de 2.1 et 2.2.

Les 4×4 positions d'une même cellule utilisent les **mêmes 8 coins**. Un thread
qui traite les (jusqu'à) 4 positions x d'une cellule sur une rangée z charge
les coins une fois et interpole pour chaque position : 4× moins de lectures.
- Mapping par **cellule** : thread → (rangée z, cellule x), positions
  `[max(x0, 4*cellX), min(x0+w, 4*cellX+4))`. Il y en a moins de 4 aux bords
  quand `x0 % 4 != 0` ou `w % 4 != 0`.
- Boucle de scan commune, avec un masque « position trouvée » : on sort quand
  les 4 sont trouvées. Chaque position garde **son propre** `lerp3`, avec son
  `percentX` : bit-exact.
- Coût accepté : un thread attend sa position la plus basse (divergence
  interne). C'est faible, car les 4 positions sont dans la même cellule et ont
  des hauteurs proches. Le ratio `smsp__thread_inst_executed_per_inst_executed.ratio`
  va un peu baisser, c'est attendu. Ce qui tranche, c'est le temps.
- Bonus vectorisation : si `x0 % 4 == 0` et `w % 4 == 0`, écrire les 4 hauteurs
  en un `int4`. Sinon, garder des écritures scalaires.

À mesurer : temps de 2b, requêtes `ld` global, ratio de threads actifs par warp.

### 2.7 `[ ]` Kernel 2b : tiling en shared memory — conditionnel

Alternative ou complément à 2.6. **Ne faire que si**, après 2.6, `ncu` montre
encore 2b limité par la mémoire (*Memory Throughput* élevé, hit rate L1 bas).

Blocs 2D de 16×16 threads, qui couvrent 4×4 cellules et lisent 5×5 = 25 colonnes ×
`startSizeY + 1` lignes (environ 6,6 Ko au pire). Le chargement en shared est
coopératif et coalescé, grâce à 2.1.
- Gérer les bords quand `x0` / `w` ne sont pas multiples de 4.
- `__syncthreads()` **avant** tout `return` anticipé.
- Si 2.6 a été gardé : un tile par bloc, avec 4 positions par thread.

### 2.8 `[ ]` Copie de `s_perm` en `uint32_t` (vectorisation) — kernels 0, 1

La copie global → shared se fait octet par octet (32 o par warp et par
instruction), alors qu'en `uint32_t` elle irait 4× plus vite. `10280 = 4 × 2570`
et `4112 = 4 × 1028` ; `perm` commence à l'offset 3616 de `GpuSurfaceNoise`
(aligné sur 16). Déclarer `extern __shared__ __align__(16) uint8_t s_perm[];`.
Gain attendu marginal : la copie est amortie sur 320 lookups par thread.

### 2.9 `[ ]` Lecture `int4` de `cornerIndices` (vectorisation) — kernel 2a

`int4 ci = reinterpret_cast<const int4*>(cornerIndices)[q];` : une requête de
16 o par thread au lieu de 4 requêtes strided. `cudaMalloc` aligne sur 256.

### 2.10 `[ ]` `ColumnParams` en lecture vectorisée — kernels 0, 1

24 o par élément (2 `int` + 2 `double`), en AoS. Le passer à 32 o (padding) pour
charger 2 `double2` alignés, ou le scinder en tableaux séparés `int2 cell[]`,
`double2 depthScale[]`. Gain attendu très faible : une lecture par thread,
noyée dans le calcul. À faire en dernier, et seulement si 2.3 a fait du kernel 1
un kernel moins limité par le calcul.

### 2.11 `[m]` Mesurer : conflits de banc sur `s_perm`

Les lookups `idx[h]` sont aléatoires dans une table de 257 octets : il peut y
avoir des conflits de banc. Lire `l1tex__data_bank_conflicts_pipe_lsu_mem_shared_op_ld.sum`
sur le kernel 1. Pas de correctif évident : stocker en `uint32` (41 Ko) ne
supprime pas les conflits pour des index aléatoires et casse l'occupancy.
Noter le chiffre au journal.

### 2.12 `[m]` Mesurer : divergence des kernels 2a / 2b

`smsp__thread_inst_executed_per_inst_executed.ratio` (32 = aucune divergence).
Si le ratio est bas même après 2.6, une piste (hors périmètre pour l'instant)
est de regrouper les requêtes par hauteur attendue.

### 2.13 `[-]` Tensor cores — rejeté sans mesure

Les tensor cores ne font que `D = A × B + C` sur de petites tuiles de matrices.
- Il n'y a pas de multiplication de matrices dans le calcul : lookups
  data-dépendants, `floor`, polynômes et `lerp`. Seul `d_lerp3` s'écrit comme un
  produit scalaire 8 × 8.
- La bit-exactitude l'interdit : le tensor core additionne dans son propre ordre,
  avec des FMA internes, alors que le code exige l'ordre exact et `-fmad=false`.
- Pas de FP64 sur les tensor cores des RTX (seulement A100/H100). Les formats
  disponibles (FP16, BF16, TF32, INT8) sont trop imprécis.

À rouvrir seulement si la contrainte de bit-exactitude est levée **et** que le
calcul devient matriciel.

---

## 3. Corrections des notes (`documentation_cuda.txt`)

- *« Shared Memory 16KB / SM »* : c'est la valeur de Fermi (2010). Aujourd'hui
  c'est 48 Ko par bloc par défaut (plus avec opt-in), et 100 à 228 Ko par SM
  selon l'architecture.
- *« Registers 8KB / thread »* : faux. Un SM a 64K registres de 32 bits (256 Ko)
  **partagés** entre ses threads, avec au maximum 255 registres (environ 1 Ko)
  par thread. Plus un thread utilise de registres, moins le SM peut porter de
  threads (occupancy). Un tableau indexé dynamiquement ne tient pas en
  registres : il part en *local memory*, qui est en VRAM.
- *« la SM possède des Warps qui peuvent chacun exécuter 32 threads »* : plus
  précisément, un warp **est** un groupe de 32 threads consécutifs du bloc, et
  le SM l'ordonnance. La coalescence se raisonne donc par warp.
- *« Interaction entre les threads d'un même bloc ? »* : concrètement, un thread
  écrit en shared memory, un autre la lit, et `__syncthreads()` est la barrière
  qui garantit l'ordre (voir le chargement de `s_perm` dans le kernel 1).
- **Divergence** (à ajouter) : comme un warp exécute la même instruction pour
  ses 32 threads, quand ils suivent des chemins de longueurs différentes (une
  boucle qui sort plus tôt pour certains), ceux qui ont fini sont masqués et
  attendent. Le warp coûte le temps de son thread le plus lent.

---

## 4. Journal des mesures

GPU : _(à remplir au premier passage : modèle, `nvidia-smi`, version de ncu)_

| Date | Item | Kernel | Métrique | Avant | Après | Décision |
|---|---|---|---|---|---|---|
| | | | | | | |
