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
| `compute_heightmap_rect` (2b) | ❌ | ✅ écriture ; ⚠️ lectures `noiseGrid` strided (sans effet mesurable, cf. 2.1) | ✅ la ligne `cellY+1` est déjà gardée en registres par `nvcc` (cf. 2.2) ; ❌ les 4 coins sont rechargés par chacune des 16 positions d'une même cellule |
| `compute_heights_scattered` (2a) | ❌ | ⚠️ `cornerIndices[q*4+k]` strided ; `noiseGrid` aléatoire par nature | ✅ idem 2b (cf. 2.2) |

Mise en perspective :
- le kernel 1 est **limité par le calcul** (40 octaves de Perlin en FP64, et le
  FP64 tourne à 1/32 ou 1/64 du FP32 sur RTX) : mesuré à 61 % de SM throughput
  pour ~1 % de mem throughput. Son occupancy atteinte est très basse (9,5 %) :
  111 blocs par lancement en moyenne. **Corrigé par 2.3** : à 1 thread CPU, un
  lancement isolé est surtout limité par la **latence** (trop peu de warps).
  À 16 threads CPU (l'usage réel), le GPU est plein et c'est le travail total
  qui compte : 2.3 (K=2) y gagne 3 % malgré un lancement isolé 22 % plus lent.
- le kernel 2b est lui aussi **limité par le calcul et la latence**, pas par
  la mémoire (SM 70 %, mem < 1 %, L1 hit 80 %), avec de la **divergence** :
  chaque thread s'arrête à une hauteur différente, et le warp attend son
  thread le plus lent. Mieux coalescer ses lectures n'a rien changé (2.1).
- `bench_village` n'appelle jamais 2a.

---

## 2. Items, par ordre de priorité

### 2.1 `[-]` Transposer `noiseGrid` en y-major — kernels 1, 2a, 2b

**Rejeté le 2026-10-30** (mesures au journal §4). Bit-exact, et la coalescence
de 2b s'améliore bien (4,05 → 2,00 secteurs par requête `ld`), mais :
- 2b ne gagne rien en temps (−0,3 %) : il est limité par le calcul et la
  latence (SM throughput 70 %, mem throughput < 1 %), pas par la mémoire ;
- le kernel 1, qui pèse 60 % du temps GPU, régresse de 4 %. Avec
  `col = tid % numColumns`, des threads voisins traitent des colonnes
  différentes : les lookups `perm[h1]`/`perm[h3]` ne sont plus identiques dans
  le warp (conflits de banc shared +22 %), `columns[col]` n'est plus diffusé
  (secteurs `ld` +15 %), et les instructions augmentent de 4,6 %.

Enseignement pour les items suivants : dans le kernel 1, des threads voisins
doivent rester sur **la même colonne** (y différents).

Ce que le changement faisait :

**Avant** : `noiseGrid[col * allocStride + y]`. Dans 2b, des threads voisins en x
lisent, au même `cellY`, des colonnes espacées de `allocStride * 8` octets (136 à
264 o). Résultat : environ 9 secteurs de 32 o par requête pour 9 doubles utiles.

**Après** : `noiseGrid[y * numColumns + col]`. Les colonnes voisines sont
contiguës : 2 à 3 secteurs par requête. Le kernel 1 fait varier `col` le plus
vite (`col = tid % numColumns`), son écriture reste coalescée. `allocStride`
devient `allocRows`. L'extension ajoute des lignes sans rien déplacer.

Code annulé (retour à la version de `main`).

### 2.2 `[-]` Réutiliser la ligne `cellY+1` en registres dans `scan_column` — kernels 2a, 2b

**Rejeté le 2026-10-30 : le compilateur le fait déjà.** Bit-exact, mais les
requêtes `ld` global de 2a et 2b sont **strictement identiques** (37,2k sur le
bench, 55,1k sur le micro), et les temps ne bougent pas (ncu +0,1 %, nsys
+0,5 %, dans le bruit). Le SASS de la baseline l'explique : avec `-O3` et
`__restrict__`, `nvcc` déroule la 1re itération (8 `LDG.E.64`) puis la boucle
ne charge que les 4 valeurs de `cellY` (`[R.64+-0x8]`), et passe les 4 autres
d'une itération à l'autre en registres. La version manuelle produit la même
boucle ; elle économise seulement 2 à 4 registres (58 → 56 pour 2b, 60 → 56
pour 2a), sans effet sur l'occupancy. Code annulé.

Enseignement : avant de « sortir une lecture de la boucle » à la main,
regarder le SASS (`nvcc -cubin` puis `cuobjdump -sass`, les binaires liés ne
se désassemblent pas directement).

Ce que l'item proposait :

(Ne dépend plus de 2.1, rejeté : se fait sur le layout colonne `col[cellY]`.)

`scan_column` charge 8 valeurs à chaque `cellY` : 4 à `cellY` et 4 à
`cellY+1`. À l'itération suivante (`cellY-1`), les valeurs à `cellY+1` sont
exactement celles lues à `cellY` juste avant. Garder ces 4 valeurs en registres :

```cpp
// avant la boucle : charger startSizeY (le "haut" de la 1re iteration)
double t0 = col0[startSizeY], t1 = col1[startSizeY], t2 = ..., t3 = ...;
for (cellY = startSizeY - 1; ...) {
    double b0 = col0[cellY], b1 = ..., b2 = ..., b3 = ...;   // 4 lectures au lieu de 8
    ... lerp3 avec (b*, t*) ...
    t0 = b0; t1 = b1; t2 = b2; t3 = b3;                      // le bas devient le haut
}
```

Lectures divisées par 2, arithmétique identique, donc bit-exact.

⚠️ 2b n'est pas limité par la mémoire (cf. 2.1) : le gain en temps risque
d'être faible. Ce qui peut compter, c'est la baisse d'instructions et de
latence par itération.

À mesurer : `l1tex__t_requests_pipe_lsu_mem_global_op_ld.sum` (environ ÷2), temps de 2a et 2b.

### 2.3 `[x]` Kernel 1 : plusieurs `y` par thread (*thread coarsening*)

**Gardé le 2026-10-30 avec K = 2** (`#define NOISE_K 2` dans
`village_noise.cu`, réglable par `-DNOISE_K=…` ; `NOISE_K=1` redonne l'ancien
comportement). Mesures au journal §4. Bit-exact, sans spill.

**Gain dans le régime réel (16 threads CPU)** : débit `bench_village` +3,2 %
(1877 → 1938 v/s, médiane de 10, K=2 devant sur 8 runs appariés sur 10 ;
une 1re série de 5 donnait +2,1 %). Les instructions du kernel 1 baissent de
4,1 %, et quand le GPU est rempli par 16 flux, c'est le travail total qui compte.

**Coût accepté : un lancement isolé est plus lent.** À 1 thread CPU, le
kernel 1 prend +22 % au bench ncu (265 → 345 µs dans nsys). Il est limité par
la latence : 111 blocs pour 48 SM, et K=2 divise les blocs par 2 (111 → 56)
et l'occupancy aussi (9,5 → 4,8 %). Décision de l'utilisateur : l'usage réel
est à 16 threads.

**K = 4 rejeté** : −6,3 % de débit à 16 threads, +120 % à 1 thread. Il ne
retire que 6,5 % des instructions, et ses 130 registres limitent les warps
par SM, même quand le GPU est plein.

Deux hypothèses de l'item étaient fausses :
- **la partie x/z ne pèse presque rien** : les instructions ne baissent que de
  4,1 % (K=2) et 6,5 % (K=4), loin des 20 à 30 % estimés. L'essentiel du coût
  d'une octave dépend de `y` : 6 lookups de `perm`, les 8 `d_indexedLerp` et
  les 7 `lerp` ;
- **un lancement isolé du kernel 1 est limité par la latence**, pas par le
  débit de calcul : il manque de warps.

Enseignement : à 1 thread, le kernel 1 manque de **parallélisme** ; à 16
threads, c'est le travail total qui compte. Les meilleures pistes améliorent
les deux : moins de divergence (2.14, threads actifs 18,8 / 32), ou des
lancements plus gros.

Ce que l'item proposait :

C'est **l'item qui attaque le goulot principal** : le calcul FP64 du kernel 1,
qui pèse 60 % du temps GPU (cf. journal).

Dans `d_samplePerlin`, tout ce qui vient de x/z ne dépend pas de `y` : `d1`,
`d3`, `floor(d1)`, `floor(d3)`, `h1`, `h3`, `t1`, `t3` (2 polynômes de fade) et
les lookups `idx[h1]` / `idx[h1+1]`. De même dans `d_sampleSurfaceNoise`,
`dx`, `dz`, `dx2` et `dz2` ne dépendent pas de `y`. Un thread qui traite K
valeurs de `y` d'une même colonne fait ce travail une seule fois par octave.

- Mapping : garder des threads voisins **sur la même colonne** (leçon de 2.1 :
  sinon les lookups `perm` divergent et les conflits de banc augmentent).
  Avec `nChunks = ceil((yTo - yFrom) / K)` : `col = tid / nChunks`,
  `yBase = yFrom + (tid % nChunks) * K`. Les écritures dans
  `noiseGrid[col * stride + y]` deviennent espacées de K doubles : à surveiller,
  mais elles sont rares face au calcul.
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

### 2.4 `[-]` Paramètres d'octave et config par valeur en argument de kernel — kernels 0, 1

**Rejeté le 2026-10-30** (mesures au journal §4). Bit-exact. Les lectures
globales baissent bien (instructions `ld` global du kernel 1 : −71 %), mais
le débit à 16 threads ne bouge pas (−0,4 % et −0,6 % sur 2 séries de 10).
Seul le kernel 0, plus court, gagne un peu (−7,4 % au ncu, nsys 52,3 → 49,7 µs) ;
le kernel 1 fait −0,6 %. Ces lectures étaient déjà diffusées à tout le warp et
servies par L1 : elles ne coûtaient presque rien face au calcul de Perlin. Le
gain ne justifie pas le code en plus (struct `GpuOctParams`, copie hôte,
`static_assert`). Code annulé ; la version est gardée dans
`ncu_runs/2.4/village_noise_2.4.cu` (non versionné).

Ce que l'item proposait :

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

### 2.5 `[x]` Taille de bloc du kernel 1 (`NOISE_BLOCK` 64 / 128 / 256 / 512)

**Balayé le 2026-10-30 (après 2.3 et 2.14) : 64 reste le meilleur, rien ne
change.** Débit à 16 threads (médiane de 10, alternés) : 32 → 2238 v/s
(−0,2 %), **64 → 2242 v/s**, 128 → 2115 (−5,6 %), 256 → 2039 (−9,1 %),
512 → 1884 (−15,9 %). Les 5 tailles sont bit-exactes. À 1 thread, 32 accélère
le kernel 1 de 2 % (deux fois plus de blocs : 56 → 111), mais ça ne se voit
pas quand le GPU est plein. Les gros blocs perdent parce que les lancements
sont petits : moins de blocs, c'est moins de SM occupés.

Ce que l'item proposait :

2.3 est gardé avec K=2 : il y a 2 fois moins de threads (56 blocs de 64 par
lancement en moyenne). Essayer aussi **32**, qui double le nombre de blocs et
répartit le travail sur plus de SM. Juger au débit à 16 threads (balayage
avec `throughput.sh`).

Chaque bloc recopie 10 Ko de `perm`, donc des blocs plus gros amortissent mieux
la copie. Mais 10 Ko de shared par bloc limitent le nombre de blocs par SM, et
nos lancements ne font qu'une centaine de blocs (README, § multi-threading) : des
blocs plus gros, c'est moins de SM occupés. Balayer les tailles et comparer le temps,
`sm__warps_active.avg.pct_of_peak_sustained_active` et le débit `bench_village`.

Cas particulier du skill : pas une baseline contre une candidate, mais une
mesure par taille. Garder la meilleure.

### 2.6 `[x]` Kernel 2b : 4 positions x par thread (*thread coarsening*)

Dépendait de 2.2. 2.2 est rejeté parce que `nvcc` le fait déjà : la
réutilisation verticale est acquise, donc la dépendance est levée.

**Gardé le 2026-10-30** (mesures au journal §4). Bit-exact, y compris sur des
rectangles non alignés (`test_cuda` avec x0 négatif et w = 1, 2, 63, 101).
- Débit `bench_village --threads 16` : **+4,0 %** (2159 → 2244 v/s, médiane de 10) ;
- 2b : −25 % au bench ncu (nsys 124 → 95 µs), instructions −50 %, requêtes
  `ld` global −29 %, L1 hit 80 → 91 %, registres 58 → 72 (sans spill) ;
- coûts attendus : occupancy 31 → 9 % (4× moins de threads), threads actifs
  par warp 28,5 → 26,3.

Le bonus `int4` n'est pas fait : les écritures deviennent strided (secteurs
`st` ×4), mais elles sont rares (832 requêtes contre 26,5k lectures). Le
kernel refuse un `chunkWidth` > 4 (`HMAP_PX`), ce qui n'arrive dans aucune
dimension.

Ce que l'item proposait :

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

### 2.7 `[-]` Kernel 2b : tiling en shared memory — conditionnel

**Non fait (2026-10-30) : la condition n'est pas remplie.** Après 2.6, 2b
n'est pas limité par la mémoire : mem throughput 0,49 %, hit rate L1 91 %.

Alternative ou complément à 2.6. **Ne faire que si**, après 2.6, `ncu` montre
encore 2b limité par la mémoire (*Memory Throughput* élevé, hit rate L1 bas).

Blocs 2D de 16×16 threads, qui couvrent 4×4 cellules et lisent 5×5 = 25 colonnes ×
`startSizeY + 1` lignes (environ 6,6 Ko au pire). Le chargement en shared est
coopératif ; en layout colonne, chaque colonne est un segment contigu.
Peu probable d'être utile : 2b n'est pas limité par la mémoire (cf. 2.1).
- Gérer les bords quand `x0` / `w` ne sont pas multiples de 4.
- `__syncthreads()` **avant** tout `return` anticipé.
- Si 2.6 a été gardé : un tile par bloc, avec 4 positions par thread.

### 2.8 `[-]` Copie de `s_perm` en `uint32_t` (vectorisation) — kernels 0, 1

**Rejeté le 2026-10-30** (mesures au journal §4). Bit-exact. Les kernels
accélèrent un peu à 1 thread : kernel 1 −3,7 % et kernel 0 −5,5 % au ncu
(instructions `ld` global −21 % et −25 %). Mais le débit à 16 threads ne bouge
pas : −0,3 % sur une série de 10 runs de 400 mondes. Les 3 séries de 100
mondes (−1,8 %, +3,0 %, +1,5 %) étaient trop bruitées pour conclure (±7 %),
d'où le passage de `throughput.sh` à 400 mondes par run. Code annulé.

Ce que l'item proposait :

La copie global → shared se fait octet par octet (32 o par warp et par
instruction), alors qu'en `uint32_t` elle irait 4× plus vite. `10280 = 4 × 2570`
et `4112 = 4 × 1028` ; `perm` commence à l'offset 3616 de `GpuSurfaceNoise`
(aligné sur 16). Déclarer `extern __shared__ __align__(16) uint8_t s_perm[];`.
Gain attendu marginal : la copie est amortie sur 320 lookups par thread.

### 2.9 `[-]` Lecture `int4` de `cornerIndices` (vectorisation) — kernel 2a

**Non fait (2026-10-30) : sans effet sur l'usage réel.** Le kernel 2a
(`cuda_noise_batch_heights`, via `CudaHeightBatcher::execute`) n'est appelé
que par `test_cuda`. `cuda_height_provider` et donc `bench_village` et la
recherche de seeds passent uniquement par le heightmap (2b). À rouvrir si un
appelant réel de 2a apparaît.

`int4 ci = reinterpret_cast<const int4*>(cornerIndices)[q];` : une requête de
16 o par thread au lieu de 4 requêtes strided. `cudaMalloc` aligne sur 256.

### 2.10 `[-]` `ColumnParams` en lecture vectorisée — kernels 0, 1

**Non fait (2026-10-30) : la condition n'est pas remplie.** Après 2.3 et
2.14, le kernel 1 reste dominé par le calcul de Perlin. 2.4 et 2.8, qui
retiraient l'un 71 % et l'autre 21 % des lectures globales du kernel 1, n'ont
rien changé au débit à 16 threads : une lecture de 24 o par thread pèsera
encore moins.

24 o par élément (2 `int` + 2 `double`), en AoS. Le passer à 32 o (padding) pour
charger 2 `double2` alignés, ou le scinder en tableaux séparés `int2 cell[]`,
`double2 depthScale[]`. Gain attendu très faible : une lecture par thread,
noyée dans le calcul. À faire en dernier : 2.3 n'a retiré que 4 % des
instructions, le kernel 1 reste dominé par le calcul de Perlin.

### 2.11 `[x]` Mesurer : conflits de banc sur `s_perm`

**Mesuré le 2026-10-30** (état après 2.6) : 76,9k conflits de banc sur les
`ld` shared du kernel 1 au bench (166k au micro), et 7,7k sur le kernel 0.
Avant 2.3, c'était 70,4k ; K=2 les augmente de 9 %, car un thread fait 2 fois
plus de lookups. Pas de correctif retenu : les index sont aléatoires par
nature, et 2.14 a montré que le goulot était la divergence, pas la shared
memory.

Les lookups `idx[h]` sont aléatoires dans une table de 257 octets : il peut y
avoir des conflits de banc. Lire `l1tex__data_bank_conflicts_pipe_lsu_mem_shared_op_ld.sum`
sur le kernel 1. Pas de correctif évident : stocker en `uint32` (41 Ko) ne
supprime pas les conflits pour des index aléatoires et casse l'occupancy.
Noter le chiffre au journal.

### 2.12 `[x]` Mesurer : divergence des kernels 2a / 2b

**Mesuré le 2026-10-30** (état après 2.6) : 2b à 26,3 threads actifs / 32
au bench (29,4 au micro), contre 28,5 avant 2.6 ; la baisse vient du
coarsening, comme prévu. 2a à 16,8 / 32 (micro, 1 lancement), mais il n'est
pas utilisé en pratique (cf. 2.9). Le kernel 1 est à 31,8 / 32 et le
kernel 0 à 31,5 / 32 depuis 2.14. Pas d'action : la divergence restante de 2b
vient des hauteurs différentes d'une position à l'autre, inhérentes au scan.

`smsp__thread_inst_executed_per_inst_executed.ratio` (32 = aucune divergence).
Si le ratio est bas même après 2.6, une piste (hors périmètre pour l'instant)
est de regrouper les requêtes par hauteur attendue.

### 2.14 `[x]` `d_indexedLerp` sans `switch` (divergence) — kernels 0, 1

**Gardé le 2026-10-30. C'est le plus gros gain jusqu'ici** (mesures au
journal §4). Bit-exact.
- Débit `bench_village --threads 16` : **+14,5 %** (1867 → 2138 v/s, médiane
  de 10, la candidate devant sur les 10 runs) ;
- kernel 1 : −36 % au bench ncu (nsys 344 → 216 µs), instructions −35,5 %,
  threads actifs par warp 18,2 → 31,8 / 32, registres 123 → 80 ;
- kernel 0 (même fonction) : −27 % (nsys 74,7 → 52,3 µs), threads actifs
  20,0 → 31,5 / 32.

Le `switch` était compilé en branches : avec un index aléatoire par thread, le
warp exécutait l'un après l'autre jusqu'à 16 chemins, 8 fois par octave. La
version sans branche fait 4 sélections (`u`, `v` et leurs signes, codés par
4 masques de 16 bits vérifiés sur les 16 cas) et une addition.

Conséquence pour la suite : le coût par `y` d'une octave a beaucoup baissé, la
part x/z partagée par 2.3 pèse donc relativement plus, et les registres sont
tombés à 80. Le choix K=2 de 2.3 est à re-mesurer (cf. 2.15).

Ce que l'item proposait (ajouté le 2026-10-30, après 2.3) : Le kernel 1 n'a que 18,8 threads actifs par
warp (sur 32). Une source probable : le `switch (idx & 0xf)` de
`d_indexedLerp`, appelé 8 fois par octave avec un index aléatoire, donc un
chemin différent par thread. Tous les cas s'écrivent `(±u) + (±v)` avec
`u, v ∈ {a, b, c}` : une table de 16 entrées (indice de `u`, de `v`, signes)
permet un calcul sans branche. Pour rester bit-exact, appliquer le signe par
négation (`-x`, exact, signe du zéro compris), pas par `0 * c` ; `x - y` est
identique à `x + (-y)` en IEEE 754.

À mesurer : `smsp__thread_inst_executed_per_inst_executed.ratio`, temps du
kernel 1, instructions.

### 2.15 `[x]` Re-balayer `NOISE_K` (1 / 2 / 4) après 2.14 — kernel 1

**Balayé le 2026-10-30 (après 2.6) : K=2 reste, rien ne change.** Débit à
16 threads (400 mondes, médiane de 10) : K=1 → 2726 v/s (−0,1 %),
**K=2 → 2729 v/s**, K=4 → 2625 v/s (−3,8 %). Les 3 sont bit-exacts.
Registres du kernel 1 : 77 (K=1), 80 (K=2), 122 (K=4). Le temps à 1 thread
n'entre pas dans la décision : seul l'usage à 16 threads compte.

Ajouté le 2026-10-30. 2.3 a choisi K=2 quand le kernel 1 avait 123 registres
et un warp à 18 threads actifs. Après 2.14, il en a 80 et un warp quasi plein :
K=4 pourrait passer sous la barre des registres qui le pénalisait, ou K=1
redevenir meilleur. Balayage avec `throughput.sh ncu_runs/2.15 K1 K2 K4`
(binaires construits avec `NVCC_FLAGS_EXTRA="-DNOISE_K=…"`). Garder le
meilleur débit à 16 threads.

### 2.16 `[m]` Le GPU est-il encore le goulot à 16 threads ?

Ajouté le 2026-10-30. **À faire avant tout autre item** : le résultat décide
si les items de kernel (2.17 à 2.19, 2.21) peuvent encore payer.

Deux indices disent que le GPU n'est peut-être plus le goulot :
- **des gains de kernel qui ne passent plus dans le débit** : 2.4 (kernel 0
  −7,4 %) et 2.8 (kernel 1 −3,7 %) donnent 0 % à 16 threads ;
- **l'argument du README contre le batching est périmé**. Il comparait 1,19 ms
  de kernels à 0,29 ms de surcoût hôte par lancement. Après 2.3, 2.6 et 2.14,
  les kernels font environ 216 + 95 + 52 µs ≈ 0,36 ms : le surcoût hôte est du
  **même ordre** que le calcul.

Mesure, en une commande (environ 5 min) :

```bash
cd c/cuda && rm -f village_noise.obj && make bench_village
bash ../../.claude/skills/cuda-optimize/saturation.sh ncu_runs/2.16
```

- **A. Amdahl côté CPU** : la part `f` du temps des threads passée à attendre
  le prefetch GPU (upload + kernels + file d'attente + download). Un GPU
  infiniment rapide donnerait au mieux `1 / (1 − f)` de débit. Si `f` vaut 15 %,
  toutes les optimisations GPU réunies plafonnent à +18 %.
- **B. Sur-souscription** : débit à 16, 24 et 32 threads. Le Ryzen 7 9700X a
  16 threads logiques : un thread qui attend le GPU laisse son cœur vide. Si 24
  ou 32 threads font monter le débit, le GPU avait de la marge et le CPU
  dormait. C'est aussi un **gain gratuit**, à reporter dans le README et les
  scripts de recherche.
- **C. Trace nsys à 16 threads** : part du temps où au moins un kernel tourne
  (union des intervalles, toutes streams confondues), concurrence moyenne,
  trous de plus de 100 µs, temps des transferts, temps des threads dans
  `cudaEventSynchronize` et `cudaMemcpyAsync`, et `SM Active` si les
  gpu-metrics sont disponibles.

Décision :
- **GPU saturé** (kernel actif ≈ 100 % du temps central, SM Active élevé,
  `f` > 50 %, pas de gain à 24/32 threads) : les items de kernel restent la
  priorité. Continuer par 2.17.
- **GPU sous-rempli** (kernel actif ≈ 100 % mais SM Active bas) : les lancements
  sont trop petits. Remonter 2.21 (fusion) et rouvrir la question du batching
  dans le README.
- **GPU qui attend l'hôte** (kernel actif < 70 %, ou `f` < 20 %, ou gain à
  24/32 threads) : les items de kernel sont plafonnés par Amdahl. Passer à 2.20
  (transferts) et regarder le travail CPU (préparation des colonnes et des
  biomes) ; les items 2.17 à 2.19 et 2.21 passent après.

Dans tous les cas, mettre à jour le § « Pourquoi le batching… » du README avec
les nouveaux chiffres.

### 2.17 `[ ]` Kernel 2b : un thread par cellule 4×4, interpolations partagées

Dépend de 2.6. Conditionnel à 2.16 (GPU saturé ou sous-rempli).

`d_lerp3(percentY, percentX, percentZ, …)` fait, dans cet ordre imposé :
4 lerps en **Y**, puis 2 lerps en **X**, puis 1 lerp en **Z**.
- Les 4 lerps Y ne dépendent que de `posY` et des 8 coins : ils sont
  **identiques pour les 16 positions** de la cellule.
- Les 2 lerps X ne dépendent que de `percentX` : partagés par les 4 positions
  d'une même colonne x.
- Seul le lerp Z est propre à chaque position.

| Positions par thread | Lerps par `posY` pour 16 positions |
|---|---|
| 1 (avant 2.6) | 16 × 7 = 112 |
| 4 en x (2.6), si `nvcc` factorise déjà les lerps Y | 4 × (4 + 4 × 3) = 64 |
| **4×4 (cet item)** | 4 + 4 × 2 + 16 = **28** |

Bit-exact : les mêmes valeurs sont calculées avec les mêmes opérations, une
seule fois au lieu de plusieurs. 2b est limité par le calcul (SM 70 %, mémoire
< 1 %), c'est donc le bon levier pour ce kernel.

- **D'abord le SASS** (leçon de 2.2) : regarder si `nvcc` factorise déjà les
  lerps Y entre les 4 positions de 2.6 (`nvcc -cubin` puis `cuobjdump -sass`,
  compter les `DADD`/`DMUL` de la boucle interne). La factorisation en z, elle,
  n'existe pas encore.
- Mapping : un thread par cellule, avec ses positions `[max(x0, 4·cellX), min(x0+w, 4·cellX+4))`
  × la même chose en z. Il peut y en avoir moins de 16 aux bords.
- Masque de 16 bits « position trouvée » : on sort quand toutes sont trouvées.
  Les lerps Y et X restent calculés tant qu'une position qui en dépend n'est pas
  trouvée.
- Coût attendu : 4× moins de threads que 2.6, et une divergence interne un peu
  plus forte (un thread attend la plus basse de ses 16 positions, qui restent
  proches puisqu'elles sont dans la même cellule). Surveiller les registres
  (72 aujourd'hui) et les spills : 16 hauteurs et 16 `percentZ` à garder.

À mesurer : débit à 16 threads ; instructions de 2b, registres, spills, threads actifs par warp.

### 2.18 `[m]` Kernel 1 : raisons d'attente des warps et limites d'occupancy

Conditionnel à 2.16 (GPU saturé ou sous-rempli). Décide de 2.19 et pèse sur 2.21.

Depuis 2.14, les warps du kernel 1 sont pleins (31,8 / 32). Il reste à savoir
**sur quoi ils attendent**. Profil complet d'un seul kernel (SKILL §4c), puis
lire deux sections :
- *Warp State Statistics* : `short_scoreboard` / `mio_throttle` (latence des
  lookups en shared memory, avec 77k conflits de banc, cf. 2.11),
  `math_pipe_throttle` (pipeline FP64 saturé : bit-exactitude oblige, il ne
  reste presque rien à gagner), `long_scoreboard` (mémoire globale), `barrier`
  (`__syncthreads()` après la copie de `s_perm`).
- *Occupancy* : ce qui limite les warps par SM (registres, shared memory, blocs).
  Calcul théorique **à confirmer** : environ 11,3 Ko de shared par bloc de 64
  threads (10 280 o de tables + réserve), soit environ 8 blocs = 16 warps par SM.
  Les registres (80 par thread) autoriseraient environ 24 warps. La shared
  memory serait donc la limite.

Contre-indice à garder en tête : en 2.5, des blocs de 32 (2× moins de warps
possibles par SM) donnaient le même débit que des blocs de 64. L'occupancy
n'est peut-être pas ce qui limite. Faire la même lecture sur 2b.

### 2.19 `[ ]` Tables `perm` lues via le cache L1 au lieu de la shared memory — kernels 0, 1

Conditionnel à 2.18 : ne faire que si la shared memory limite l'occupancy, ou
si `short_scoreboard` / `barrier` dominent les attentes.

Aujourd'hui, **chaque bloc copie ses 10 Ko de tables** dans sa shared memory.
Avec 8 blocs sur un SM, ce sont 8 copies identiques dans la même mémoire
on-chip (shared et L1 partagent les mêmes 128 Ko du SM), plus la copie au
démarrage et le `__syncthreads()`. En lisant les tables en global, en lecture
seule (`const uint8_t* __restrict__` + `__ldg`), **une seule copie dans le L1
sert tous les blocs du SM**. On libère la shared memory (donc de l'occupancy) et
on supprime la copie (environ 3,7 % du kernel 1 d'après 2.8).

Risque : le L1 sert moins bien que la shared memory des lectures aléatoires à
l'octet (une requête par ligne de cache distincte dans le warp, au lieu de 32
bancs en parallèle). C'est précisément ce que la mesure tranche. Variante
intermédiaire, si le résultat est mitigé : garder en shared les 16 tables
`octmin`, les plus utilisées, et lire le reste via L1.

À mesurer : débit à 16 threads ; occupancy théorique et atteinte,
`l1tex__t_sector_hit_rate.pct`, raisons d'attente, temps du kernel 1.

### 2.20 `[ ]` Mémoire hôte « pinned » pour les transferts

Conditionnel à 2.16 : ne faire que si les transferts ou `cudaMemcpyAsync`
pèsent dans la trace (C), ou si le GPU attend l'hôte.

Les tampons hôte sont des `std::vector` (par exemple `heights_` dans
`cuda_height_provider.cpp`), donc de la **mémoire paginable**. Dans ce cas,
`cudaMemcpyAsync` n'est pas vraiment asynchrone : le pilote recopie d'abord dans
un tampon interne verrouillé, sur le CPU, puis lance le DMA. Avec
`cudaMallocHost` (alloué une fois par contexte, à la taille max), le DMA lit et
écrit directement la mémoire de l'application. Le transfert devient vraiment
asynchrone, et il n'y a plus de copie CPU en plus.

- Concerne : l'upload de `columns` (`ColumnParams`, 24 o × colonnes) et le
  download de `heightsOut` (4 o × w × h).
- Garder la même API : copier depuis ou vers le tampon pinned à l'intérieur du
  provider. Libérer avec `cudaFreeHost` dans `cuda_noise_destroy`.
- Ne pas abuser de la mémoire pinned : c'est de la RAM verrouillée, à raison
  d'un tampon par thread (16 contextes).

À mesurer : débit à 16 threads ; dans nsys, durée des memcpy et temps des
threads dans `cudaMemcpyAsync`.

### 2.21 `[ ]` Fusionner le kernel 0 dans le kernel 1 (coopération en shared memory)

Conditionnel à 2.16 (GPU saturé ou sous-rempli) et à 2.18 (la shared memory ne
doit pas déjà limiter l'occupancy : cet item ajoute 4 Ko par bloc).

Le kernel 0 calcule un `randomOffset` par colonne (16 octaves `octdepth`). Il est
limité par la latence (28 blocs, SM 24 %) et coûte un lancement de plus, ainsi
qu'un aller-retour par `randomOffsets` en mémoire globale. Dans le kernel 1, les
2 à 4 threads d'une même colonne (`nChunks`) peuvent faire ce travail ensemble :
1. charger aussi les 16 tables `octdepth` dans `s_perm` (4 112 o de plus) ;
2. se répartir les 16 octaves : chaque thread calcule `amplitude * pv` pour les
   siennes, et l'écrit dans `s_depth[colonneLocale][octave]` ;
3. `__syncthreads()` ;
4. **un seul thread somme les 16 valeurs dans l'ordre 0 → 15**, comme
   `compute_random_offsets`, puis applique le post-traitement : bit-exact ;
5. `__syncthreads()`, puis tous lisent l'offset et calculent leurs `y`.

- Les colonnes ne doivent pas être coupées entre deux blocs : taille de bloc =
  `colonnesParBloc × nChunks`, à recalculer côté hôte.
- Le chemin d'extension (`computeOffsets == false`) et les dimensions autres
  que l'Overworld (offset nul) doivent sauter cette étape **sans** sauter les
  `__syncthreads()`.
- Supprime un lancement par prefetch et le tableau `d_randomOffsets` devient
  inutile, sauf pour l'extension, qui relit les offsets déjà calculés. Le
  garder donc, en l'écrivant depuis le kernel 1.

À mesurer : débit à 16 threads ; somme des temps kernel 0 + kernel 1 dans
nsys ; occupancy du kernel 1 (shared memory en plus).

### 2.22 `[-]` Pistes écartées sans mesure (2026-10-30)

- **CUDA Graphs** : économisent quelques µs de lancement par opération (5 par
  prefetch). Or le surcoût hôte (environ 0,29 ms par lancement) vient surtout du
  travail CPU (préparation des colonnes et des biomes), pas des lancements. À
  rouvrir seulement si 2.16 montre un temps hôte dominé par les appels
  `cudaLaunchKernel`.
- **Calcul en FP32** : le FP32 est 32 à 64× plus rapide que le FP64 sur RTX,
  mais la bit-exactitude avec le CPU l'interdit.
- **Tiling en shared memory** et **vectorisation** : déjà tranchés par les
  mesures (2.7 à 2.10).

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

GPU : NVIDIA GeForce RTX 5070 (sm_120), driver 610.88, CUDA 13.1, Nsight
Compute 2026.3.1, Nsight Systems 2025.5.2. Les compteurs GPU doivent être
ouverts à tous les utilisateurs (NVIDIA Control Panel → Developer), sinon
`ERR_NVGPUCTRPERM`.

Répartition du temps GPU (baseline `main`, Nsight Systems, `bench_village
--worlds 20 --threads 1`, 599 lancements de kernel 1) :

| Kernel | Part | Durée moyenne | Goulot (ncu, bench) |
|---|---|---|---|
| 1 `compute_noise_columns` | 59,5 % | 265 µs | calcul : SM 61 %, mem 1,3 %, occupancy 9,5 % |
| 2b `compute_heightmap_rect` | 27,7 % | 124 µs | calcul/latence : SM 70 %, mem 0,6 %, L1 hit 80 % |
| 0 `compute_random_offsets` | 12,8 % | 75 µs | latence : SM 24 %, occupancy 4 %, 28 blocs |
| 2a `compute_heights_scattered` | 0 % | – | jamais appelé par `bench_village` |

Débit de référence (`--worlds 100 --threads 16`) : 1921 v/s au départ (médiane de 5) ; 1938 v/s après 2.3 (médiane de 10, `throughput.sh`, le 2026-10-30) ; 2138 v/s après 2.14 ; 2244 v/s après 2.6. Avec 400 mondes par run (`throughput.sh` depuis 2.8) : 2763 v/s après 2.6.

| Date | Item | Kernel | Métrique | Avant | Après | Décision |
|---|---|---|---|---|---|---|
| 2026-10-30 | 2.1 | 1 | temps ncu bench (médiane) | 330,8 µs | 343,9 µs (+4,0 %) | rejeté |
| 2026-10-30 | 2.1 | 1 | temps nsys bench (moyenne, 3 runs) | 264,6 µs | 274,7 µs (+3,8 %) | rejeté |
| 2026-10-30 | 2.1 | 1 | conflits de banc shared `ld` | 70,4k | 85,9k (+22 %) | rejeté |
| 2026-10-30 | 2.1 | 1 | instructions (warp) | 8,71M | 9,11M (+4,6 %) | rejeté |
| 2026-10-30 | 2.1 | 1 | secteurs `ld` global | 86,9k | 100,1k (+15 %) | rejeté |
| 2026-10-30 | 2.1 | 2b | secteurs / requête `ld` global | 4,05 | 2,00 | rejeté |
| 2026-10-30 | 2.1 | 2b | temps ncu bench (médiane) | 121,8 µs | 121,4 µs (−0,3 %) | rejeté |
| 2026-10-30 | 2.1 | 2b | registres / thread | 58 | 52 | rejeté |
| 2026-10-30 | 2.1 | 2a | temps ncu micro | 68,7 µs | 67,0 µs (−2,5 %, 1 lancement) | rejeté |
| 2026-10-30 | 2.1 | – | débit `bench_village` 16 threads (médiane de 5) | 1921 v/s | 1880 v/s (−2 %) | rejeté |
| 2026-10-30 | 2.2 | 2b | requêtes `ld` global (bench) | 37,2k | 37,2k (0 %) | rejeté |
| 2026-10-30 | 2.2 | 2b | temps ncu bench (médiane) | 121,6 µs | 121,7 µs (+0,1 %) | rejeté |
| 2026-10-30 | 2.2 | 2b | temps nsys bench (moyenne, 2 runs) | 123,7 µs | 124,3 µs (+0,5 %) | rejeté |
| 2026-10-30 | 2.2 | 2b | registres / thread | 58 | 56 | rejeté |
| 2026-10-30 | 2.2 | 2a | requêtes `ld` global (micro) | 2,9k | 2,9k (0 %) | rejeté |
| 2026-10-30 | 2.3 | 1 | temps ncu bench (médiane) | 331,1 µs | K=2 : 404,6 µs (+22 %) · K=4 : 727,9 µs (+120 %) | K=2 gardé |
| 2026-10-30 | 2.3 | 1 | temps nsys bench (moyenne, 2 runs) | 264,9 µs | K=2 : 344,9 µs (+30 %) · K=4 : 636 µs | K=2 gardé |
| 2026-10-30 | 2.3 | 1 | instructions (warp) | 8,71M | K=2 : 8,35M (−4,1 %) · K=4 : 8,14M (−6,5 %) | K=2 gardé |
| 2026-10-30 | 2.3 | 1 | registres / thread (spills : 0) | 78 | K=2 : 123 · K=4 : 130 | K=2 gardé |
| 2026-10-30 | 2.3 | 1 | blocs / occupancy atteinte | 111 / 9,5 % | K=2 : 56 / 4,8 % · K=4 : 28 / 4,1 % | K=2 gardé |
| 2026-10-30 | 2.3 | – | débit `bench_village` 16 threads (médiane de 5) | 1846 v/s | K=2 : 1884 (+2,1 %) · K=4 : 1765 (−4,4 %) | K=2 gardé |
| 2026-10-30 | 2.3 | – | débit `bench_village` 16 threads (médiane de 10, `throughput.sh`) | 1877 v/s | K=2 : 1938 (+3,2 %) · K=4 : 1758 (−6,3 %) | K=2 gardé |
| 2026-10-30 | 2.14 | 1 | temps ncu bench (médiane) | 404,7 µs | 258,2 µs (−36,2 %) | gardé |
| 2026-10-30 | 2.14 | 1 | temps nsys bench (moyenne, 2 runs) | 344,4 µs | 215,9 µs (−37,3 %) | gardé |
| 2026-10-30 | 2.14 | 1 | instructions (warp) | 8,35M | 5,38M (−35,5 %) | gardé |
| 2026-10-30 | 2.14 | 1 | threads actifs / warp | 18,2 / 32 | 31,8 / 32 | gardé |
| 2026-10-30 | 2.14 | 1 | registres / thread (spills : 0) | 123 | 80 | gardé |
| 2026-10-30 | 2.14 | 0 | temps ncu bench (médiane) | 89,8 µs | 65,3 µs (−27,4 %) | gardé |
| 2026-10-30 | 2.14 | 0 | threads actifs / warp | 20,0 / 32 | 31,5 / 32 | gardé |
| 2026-10-30 | 2.14 | – | débit `bench_village` 16 threads (médiane de 10) | 1867 v/s | 2138 v/s (+14,5 %) | gardé |
| 2026-10-30 | 2.4 | 1 | instructions `ld` global (bench) | 64,3k | 18,5k (−71 %) | rejeté |
| 2026-10-30 | 2.4 | 1 | temps ncu bench (médiane) | 258,2 µs | 256,6 µs (−0,6 %) | rejeté |
| 2026-10-30 | 2.4 | 0 | temps ncu bench (médiane) | 65,3 µs | 60,5 µs (−7,4 %) | rejeté |
| 2026-10-30 | 2.4 | – | débit `bench_village` 16 threads (2 séries de 10) | 2165 / 2133 v/s | 2156 / 2121 v/s (−0,4 % / −0,6 %) | rejeté |
| 2026-10-30 | 2.5 | – | débit 16 threads (médiane de 10) selon `NOISE_BLOCK` du kernel 1 | 64 : 2242 v/s | 32 : 2238 (−0,2 %) · 128 : 2115 (−5,6 %) · 256 : 2039 (−9,1 %) · 512 : 1884 (−15,9 %) | 64 gardé |
| 2026-10-30 | 2.5 | 1 | temps ncu bench, 32 face à 64 | 258,2 µs | 252,8 µs (−2,1 %), 111 blocs au lieu de 56 | 64 gardé |
| 2026-10-30 | 2.6 | 2b | temps ncu bench (médiane) | 121,6 µs | 91,0 µs (−25,2 %) | gardé |
| 2026-10-30 | 2.6 | 2b | temps nsys bench (moyenne) | 124,0 µs | 94,7 µs (−23,6 %) | gardé |
| 2026-10-30 | 2.6 | 2b | instructions (warp) | 3,87M | 1,92M (−50,3 %) | gardé |
| 2026-10-30 | 2.6 | 2b | requêtes `ld` global | 37,2k | 26,5k (−28,8 %) | gardé |
| 2026-10-30 | 2.6 | 2b | registres / occupancy / threads actifs | 58 / 31,4 % / 28,5 | 72 / 9,4 % / 26,3 | gardé |
| 2026-10-30 | 2.6 | – | débit `bench_village` 16 threads (médiane de 10) | 2159 v/s | 2244 v/s (+4,0 %) | gardé |
| 2026-10-30 | 2.7 | 2b | mem throughput / L1 hit après 2.6 | – | 0,49 % / 91 % | non fait (condition) |
| 2026-10-30 | 2.8 | 1 | temps ncu bench (médiane) | 258,6 µs | 249,0 µs (−3,7 %) | rejeté |
| 2026-10-30 | 2.8 | 0 | temps ncu bench (médiane) | 65,4 µs | 61,8 µs (−5,5 %) | rejeté |
| 2026-10-30 | 2.8 | – | débit 16 threads, 400 mondes (médiane de 10) | 2763 v/s | 2754 v/s (−0,3 %) | rejeté |
| 2026-10-30 | 2.15 | 1 | débit 16 threads, 400 mondes (médiane de 10) selon `NOISE_K` | K=2 : 2729 v/s | K=1 : 2726 (−0,1 %) · K=4 : 2625 (−3,8 %) | K=2 gardé |
| 2026-10-30 | 2.11 | 1 | conflits de banc shared `ld` (baseline, bench, médiane) | 70,4k | – | mesure |
| 2026-10-30 | 2.11 | 1 | conflits de banc shared `ld` (après 2.6, bench) | – | 76,9k | mesure |
| 2026-10-30 | 2.12 | 2b | threads actifs / warp (après 2.6, bench) | 28,5 / 32 | 26,3 / 32 | mesure |
| 2026-10-30 | 2.12 | 2b | threads actifs / warp (baseline, bench) | 28,5 / 32 | – | mesure |
| 2026-10-30 | 2.12 | 2a | threads actifs / warp (baseline, micro) | 16,8 / 32 | – | mesure |
