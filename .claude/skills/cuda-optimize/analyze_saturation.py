#!/usr/bin/env python3
"""
analyze_saturation.py — lit les sorties de saturation.sh (TODO 2.16).

    python -I analyze_saturation.py bench bench16_1.txt [bench16_2.txt ...]
    python -I analyze_saturation.py nsys gpu_trace.csv api_sum.csv [sat16.sqlite] [bench16_nsys.txt]

bench : part du temps des threads passée à attendre le prefetch GPU, et la
        borne d'Amdahl qui en découle.
nsys  : occupation du GPU à 16 threads (union des intervalles de kernels),
        concurrence moyenne, trous, transferts, appels CUDA bloquants, et
        métriques GPU (SM Active…) si la trace en contient.
"""
import csv
import os
import re
import sqlite3
import statistics
import sys


def num(s):
    s = (s or "").strip().replace(" ", "").replace(" ", "")
    if s.count(",") == 1 and "." not in s:
        s = s.replace(",", ".")
    else:
        s = s.replace(",", "")
    try:
        return float(s)
    except ValueError:
        return None


# ---------------------------------------------------------------- bench

def parse_bench(path):
    txt = open(path, encoding="utf-8", errors="replace").read()

    def grab(pattern):
        m = re.search(pattern, txt)
        return num(m.group(1)) if m else None

    return {
        "threads": grab(r"Résultat \(CUDA, (\d+) thread"),
        "total_s": grab(r"temps total\s*:\s*([\d.,]+) s"),
        "debit":   grab(r"débit\s*:\s*([\d.,]+)"),
        "wait_s":  grab(r"prefetch : \d+ lancements, ([\d.,]+) s d'attente"),
        "launch":  grab(r"prefetch : (\d+) lancements"),
        "repli":   grab(r"replis sur le C : \d+ \(([\d.,]+) %\)"),
    }


def cmd_bench(paths):
    fs = []
    print(f"{'run':<16}{'débit':>10}{'attente GPU':>14}{'borne Amdahl':>14}{'replis C':>10}")
    for p in paths:
        r = parse_bench(p)
        if not (r["threads"] and r["total_s"] and r["wait_s"] is not None):
            print(f"{os.path.basename(p):<16}  (sortie illisible : lancer sans --quiet ?)")
            continue
        f = r["wait_s"] / (r["threads"] * r["total_s"])
        fs.append(f)
        bound = 1 / (1 - f) if f < 1 else float("inf")
        print(f"{os.path.basename(p):<16}{r['debit'] or 0:>10.0f}{f*100:>13.1f}%"
              f"{(bound-1)*100:>+13.0f}%{(r['repli'] or 0):>9.1f}%")
    if fs:
        f = statistics.median(fs)
        print(f"\nmédiane : {f*100:.1f} % du temps des threads passé à attendre le prefetch GPU.")
        print(f"Un GPU infiniment rapide donnerait au mieux {(1/(1-f)-1)*100:+.0f} % de débit.")
        print("Lecture : sous ~20 %, le CPU domine et les optimisations de kernel sont")
        print("plafonnées ; au-dessus de ~50 %, le GPU (ou la file d'attente) domine.")


# ---------------------------------------------------------------- nsys

def read_csv(path):
    with open(path, newline="", encoding="utf-8", errors="replace") as f:
        lines = [l for l in f if l.strip() and not l.startswith(("NOTICE", "WARNING", "Processing", "Generating"))]
    rows = list(csv.reader(lines))
    if not rows:
        return [], []
    return rows[0], rows[1:]


def col(header, *prefixes):
    for p in prefixes:
        for i, h in enumerate(header):
            if h.strip().startswith(p):
                return i
    return None


def union(intervals):
    out = []
    for s, e in sorted(intervals):
        if out and s <= out[-1][1]:
            out[-1][1] = max(out[-1][1], e)
        else:
            out.append([s, e])
    return out


def analyze_window(kern, lo, hi, label):
    k = [(max(s, lo), min(e, hi)) for s, e, _ in kern if e > lo and s < hi]
    u = union(k)
    busy = sum(e - s for s, e in u)
    tot = sum(e - s for s, e in k)
    wall = hi - lo
    gaps = [u[i + 1][0] - u[i][1] for i in range(len(u) - 1)]
    big = [g for g in gaps if g > 100_000]
    print(f"  [{label}] fenêtre {wall/1e9:.2f} s : au moins un kernel actif {busy/wall*100:.1f} % du temps,"
          f" concurrence moyenne {tot/busy if busy else 0:.2f} kernel(s) quand actif")
    if gaps:
        print(f"           trous : {len(gaps)}, médiane {statistics.median(gaps)/1e3:.1f} µs,"
              f" {len(big)} > 100 µs ({sum(big)/wall*100:.1f} % du temps)")


def cmd_nsys(trace_csv, api_csv, sqlite_path=None, bench_txt=None):
    h, rows = read_csv(trace_csv)
    cs, cd, cn = col(h, "Start"), col(h, "Duration"), col(h, "Name")
    cb = col(h, "Bytes")
    if cs is None or cd is None or cn is None:
        sys.exit(f"{trace_csv} : colonnes Start/Duration/Name introuvables : {h}")

    kern, mem = [], {}
    first, last = None, None
    for r in rows:
        if len(r) <= max(cs, cd, cn):
            continue
        s, d, name = num(r[cs]), num(r[cd]), r[cn].strip()
        if s is None or d is None:
            continue
        e = s + d
        first = s if first is None else min(first, s)
        last = e if last is None else max(last, e)
        if name.startswith("["):
            m = mem.setdefault(name, [0, 0.0, 0.0])
            m[0] += 1
            m[1] += d
            if cb is not None and len(r) > cb:
                m[2] += num(r[cb]) or 0.0
        else:
            kern.append((s, e, name.split("(")[0]))

    print("== Occupation du GPU (trace des kernels, toutes les streams confondues)")
    if not kern:
        sys.exit("aucun kernel dans la trace")
    analyze_window(kern, first, last, "run complet")
    span = last - first
    analyze_window(kern, first + 0.1 * span, last - 0.1 * span, "80 % central")

    print("\n== Kernels (cumul)")
    per = {}
    for s, e, n in kern:
        p = per.setdefault(n, [0, 0.0])
        p[0] += 1
        p[1] += e - s
    for n, (c, t) in sorted(per.items(), key=lambda x: -x[1][1]):
        print(f"  {n:<28} n={c:<7} total {t/1e6:9.1f} ms  moy {t/c/1e3:7.1f} µs")

    print("\n== Transferts et memsets (cumul)")
    for n, (c, t, b) in sorted(mem.items(), key=lambda x: -x[1][1]):
        bw = f", {b/(t/1e9)/1e3:.1f} Go/s" if t and b else ""
        print(f"  {n:<36} n={c:<7} total {t/1e6:9.1f} ms  moy {t/c/1e3:7.1f} µs  {b:.1f} Mo{bw}")

    wall_threads = None
    if bench_txt and os.path.exists(bench_txt):
        r = parse_bench(bench_txt)
        if r["threads"] and r["total_s"]:
            wall_threads = r["threads"] * r["total_s"] * 1e9

    print("\n== Appels CUDA côté hôte (cumul sur les threads)")
    ah, arows = read_csv(api_csv)
    at, an, ac = col(ah, "Total Time"), col(ah, "Name"), col(ah, "Num Calls")
    if at is None or an is None:
        print(f"  {api_csv} : colonnes inattendues : {ah}")
    else:
        arows = [r for r in arows if len(r) > max(at, an)]
        arows.sort(key=lambda r: -(num(r[at]) or 0))
        for r in arows[:10]:
            t = num(r[at]) or 0
            share = f"  = {t/wall_threads*100:5.1f} % du temps des threads" if wall_threads else ""
            print(f"  {r[an]:<34} appels {r[ac] if ac is not None else '?':>8}  total {t/1e9:8.2f} s{share}")
        print("  (cudaEventSynchronize / cudaStreamSynchronize = attente du GPU ;"
              " un cudaMemcpyAsync lent = mémoire hôte paginable)")

    if sqlite_path and os.path.exists(sqlite_path):
        print("\n== Métriques GPU échantillonnées (moyenne sur le run)")
        try:
            db = sqlite3.connect(sqlite_path)
            names = {t for (t,) in db.execute("SELECT name FROM sqlite_master WHERE type='table'")}
            if "GPU_METRICS" not in names:
                print("  pas de table GPU_METRICS (gpu-metrics non collectées)")
            else:
                info = "TARGET_INFO_GPU_METRICS"
                q = (f"SELECT i.metricName, AVG(g.value), COUNT(*) FROM GPU_METRICS g "
                     f"JOIN (SELECT DISTINCT metricId, metricName FROM {info}) i "
                     f"ON g.metricId = i.metricId GROUP BY i.metricName")
                keep = re.compile(r"SM Active|SM Issue|Warp|Occupancy|DRAM|PCIe|GR Active|Throughput", re.I)
                for n, avg, c in sorted(db.execute(q)):
                    if keep.search(n):
                        print(f"  {n:<48} {avg:8.1f}   ({c} échantillons)")
        except sqlite3.Error as e:
            print(f"  lecture sqlite impossible : {e}")

    print("\nLecture :")
    print("  - kernel actif < ~70 % du temps central : le GPU attend l'hôte (CPU, transferts) ;")
    print("  - kernel actif ~100 % mais SM Active bas : lancements trop petits, GPU sous-rempli ;")
    print("  - kernel actif ~100 % et SM Active élevé : GPU saturé, les items de kernel paient.")


def main(argv):
    if len(argv) < 3:
        sys.exit(__doc__)
    if argv[1] == "bench":
        cmd_bench(argv[2:])
    elif argv[1] == "nsys":
        cmd_nsys(*argv[2:6])
    else:
        sys.exit(__doc__)


if __name__ == "__main__":
    main(sys.argv)
