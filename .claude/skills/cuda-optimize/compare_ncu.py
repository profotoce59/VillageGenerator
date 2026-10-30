#!/usr/bin/env python3
"""
compare_ncu.py — compare deux exports ncu (CSV, page raw) kernel par kernel.

Usage :
    python -I compare_ncu.py baseline.csv candidate.csv [--kernel NAME ...]
    python -I compare_ncu.py --metrics-list    # liste pour "ncu --metrics"

Les CSV s'obtiennent avec :
    ncu --import run.ncu-repz --csv --page raw --print-units base > run.csv

Les exports en locale française (virgule décimale, espace insécable entre les
milliers) sont reconnus.

Pour chaque kernel (nom court, sans la signature), prend la MÉDIANE de chaque
métrique sur tous ses lancements, puis affiche avant / après / écart en %.
"""
import csv
import re
import statistics
import sys

# Métriques affichées, dans cet ordre. Une métrique absente des deux fichiers
# est simplement sautée.
METRICS = [
    ("gpu__time_duration.sum",                                   "temps (ns)",               "lower"),
    ("l1tex__t_sectors_pipe_lsu_mem_global_op_ld.sum",           "secteurs ld global",       "lower"),
    ("l1tex__t_requests_pipe_lsu_mem_global_op_ld.sum",          "requêtes ld global",       "lower"),
    ("l1tex__t_sectors_pipe_lsu_mem_global_op_st.sum",           "secteurs st global",       "lower"),
    ("l1tex__t_requests_pipe_lsu_mem_global_op_st.sum",          "requêtes st global",       "lower"),
    ("l1tex__t_sector_hit_rate.pct",                             "L1 hit rate %",            "higher"),
    ("dram__bytes_read.sum",                                     "DRAM lus (o)",             "lower"),
    ("l1tex__data_bank_conflicts_pipe_lsu_mem_shared_op_ld.sum", "conflits banc shared ld",  "lower"),
    ("smsp__inst_executed.sum",                                  "instructions (warp)",      "lower"),
    ("smsp__inst_executed_op_global_ld.sum",                     "instr. ld global",         "lower"),
    ("launch__registers_per_thread",                             "registres / thread",       "info"),
    ("l1tex__t_sectors_pipe_lsu_mem_local_op_ld.sum",            "secteurs local ld (spill)", "lower"),
    ("l1tex__t_sectors_pipe_lsu_mem_local_op_st.sum",            "secteurs local st (spill)", "lower"),
    ("launch__grid_size",                                        "blocs lancés",             "info"),
    ("sm__warps_active.avg.pct_of_peak_sustained_active",        "occupancy atteinte %",     "higher"),
    ("smsp__thread_inst_executed_per_inst_executed.ratio",       "threads actifs / warp",    "higher"),
    ("sm__throughput.avg.pct_of_peak_sustained_elapsed",         "SM throughput %",          "info"),
    ("gpu__compute_memory_throughput.avg.pct_of_peak_sustained_elapsed", "mem throughput %", "info"),
]


# Separateurs de milliers possibles selon la locale de Windows : espace,
# espace insecable (0xA0, ou U+FFFD une fois mal decode), espace fine (U+202F).
THOUSANDS_SPACES = re.compile("[ \t\u00a0\u202f\ufffd]")
# Un nombre "0,25" ou "93,08" (pas exactement 3 chiffres apres la virgule) ne
# peut etre qu'un separateur decimal : export ncu en locale francaise.
DECIMAL_COMMA = re.compile(r"-?\d*,(\d{1,2}|\d{4,})")


def to_float(s, decimal_comma=False):
    s = THOUSANDS_SPACES.sub("", s or "")
    if not s or s.lower() in ("n/a", "nan"):
        return None
    if decimal_comma:
        s = s.replace(".", "").replace(",", ".")
    else:
        s = s.replace(",", "")
    try:
        return float(s)
    except ValueError:
        return None


def short_name(kernel):
    return kernel.split("(", 1)[0].strip()


def load(path):
    """-> {kernel: {metric: [valeurs]}}"""
    with open(path, newline="", encoding="utf-8", errors="replace") as f:
        lines = [l for l in f if l.strip() and not l.startswith("==")]
    rows = list(csv.reader(lines))
    if not rows:
        sys.exit(f"{path} : vide")
    header = rows[0]
    try:
        kcol = header.index("Kernel Name")
    except ValueError:
        sys.exit(f"{path} : pas de colonne 'Kernel Name' (exporter avec --page raw --csv)")

    data = [r for r in rows[1:] if len(r) == len(header) and r[kcol].strip()]
    decimal_comma = any(DECIMAL_COMMA.fullmatch(THOUSANDS_SPACES.sub("", v))
                        for r in data for v in r)

    out = {}
    for r in data:  # les lignes d'unités et les lignes cassées sont écartées
        per = out.setdefault(short_name(r[kcol]), {})
        for i, name in enumerate(header):
            v = to_float(r[i], decimal_comma)
            if v is not None:
                per.setdefault(name, []).append(v)
    return out


def fmt(v):
    if v is None:
        return "-"
    if abs(v) >= 1e6:
        return f"{v/1e6:.2f}M"
    if abs(v) >= 1e3:
        return f"{v/1e3:.1f}k"
    return f"{v:.2f}"


def main(argv):
    args = [a for a in argv[1:]]
    if args == ["--metrics-list"]:
        # Profil allégé : ncu ne collecte que ce que ce script affiche.
        print(",".join(m for m, _, _ in METRICS))
        return
    kernels_filter = []
    if "--kernel" in args:
        i = args.index("--kernel")
        kernels_filter = args[i + 1:]
        args = args[:i]
    if len(args) != 2:
        sys.exit(__doc__)

    base, cand = load(args[0]), load(args[1])
    names = sorted(set(base) | set(cand))
    if kernels_filter:
        names = [n for n in names if n in kernels_filter]

    for k in names:
        b, c = base.get(k, {}), cand.get(k, {})
        nb = len(b.get("gpu__time_duration.sum", []))
        nc = len(c.get("gpu__time_duration.sum", []))
        print(f"\n=== {k}   (lancements : {nb} avant / {nc} après)")
        print(f"  {'métrique':<26}{'avant':>12}{'après':>12}{'écart':>10}")
        for metric, label, better in METRICS:
            vb = statistics.median(b[metric]) if metric in b else None
            vc = statistics.median(c[metric]) if metric in c else None
            if vb is None and vc is None:
                continue
            delta = ""
            if vb not in (None, 0) and vc is not None:
                d = (vc - vb) / vb * 100.0
                mark = ""
                if better == "lower":
                    mark = " ✓" if d < -2 else (" ✗" if d > 2 else "")
                elif better == "higher":
                    mark = " ✓" if d > 2 else (" ✗" if d < -2 else "")
                delta = f"{d:+.1f}%{mark}"
            print(f"  {label:<26}{fmt(vb):>12}{fmt(vc):>12}{delta:>10}")
        sb = b.get("l1tex__t_sectors_pipe_lsu_mem_global_op_ld.sum")
        rb = b.get("l1tex__t_requests_pipe_lsu_mem_global_op_ld.sum")
        sc = c.get("l1tex__t_sectors_pipe_lsu_mem_global_op_ld.sum")
        rc = c.get("l1tex__t_requests_pipe_lsu_mem_global_op_ld.sum")
        if sb and rb and sc and rc:
            print(f"  {'secteurs / requête ld':<26}"
                  f"{statistics.median(sb)/max(statistics.median(rb),1):>12.2f}"
                  f"{statistics.median(sc)/max(statistics.median(rc),1):>12.2f}"
                  "   (plus bas = mieux coalescé)")


if __name__ == "__main__":
    main(sys.argv)
