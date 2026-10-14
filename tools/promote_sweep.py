#!/usr/bin/env python3
"""Promote mvlink-validated G4SE01 units into G4SJ01 / G4SP01, gated per unit.

usage: tools/promote_sweep.py [--dry-run] [--only UNIT ...]

For each G4SE01 unit (SE splits order) that is not yet in both JP and PAL splits
and whose `mvlink.plan(unit)` returns a placement for both versions:
  1. write the regional split block and rename auto symbols (non-auto SE names
     copied to the regional address) in config/G4SJ01 and config/G4SP01,
  2. configure + ninja each version and require `build/<V>/main.dol: OK` and
     `sha1sum -c config/<V>/build.sha1`,
  3. keep the unit on success; on failure restore that unit's config files only.
Results go to build/promote_sweep.json.
"""
import argparse, bisect, json, pathlib, re, subprocess, sys, os

ROOT = pathlib.Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT / "tools"))
import mvlink  # noqa: E402
from version_map import is_auto  # noqa: E402

SYM_RE = re.compile(r"^(\S+) = (\.[\w.]+):0x([0-9A-Fa-f]+)(;.*)?$")
PROMOTE = ["G4SJ01", "G4SP01"]


def parse_sym(line):
    m = SYM_RE.match(line.rstrip("\r\n"))
    return (m.group(1), m.group(2), int(m.group(3), 16), m.group(4) or ";") if m else None


def place_symbol(lines, name, sec, addr, rest):
    """Give `name` to the symbol at (sec, addr). Returns a note on conflict/keep."""
    at, names = {}, {}
    for i, l in enumerate(lines):
        p = parse_sym(l)
        if p:
            at.setdefault((p[1], p[2]), i)
            names.setdefault(p[0], i)
    if (sec, addr) in at:
        i = at[(sec, addr)]
        cur = parse_sym(lines[i])[0]
        if cur == name:
            return None
        if not is_auto(cur):
            return f"keep {cur}@{addr:08X} (SE {name})"
        if name in names:
            return f"conflict {name}"
        lines[i] = name + lines[i][len(cur):]
        return None
    if name in names:
        return f"conflict {name}"
    same = sorted(a for (s, a) in at if s == sec)
    j = bisect.bisect_left(same, addr)
    if j == 0:
        pos = at[(sec, same[0])] if same else len(lines)
    else:
        pos = at[(sec, same[j - 1])] + 1
    lines.insert(pos, f"{name} = {sec}:0x{addr:08X}{rest}\n")
    return None


def read_blocks(path):
    blocks = []  # [name, [lines]]; name "" = preamble
    for line in path.read_text().splitlines(keepends=True):
        if line.strip() and not line[0].isspace() and line.rstrip().endswith(":"):
            blocks.append([line.rstrip()[:-1], [line]])
        elif blocks:
            blocks[-1][1].append(line)
        else:
            blocks.append(["", [line]])
    return blocks


def write_split(ver, unit, secs, se_order):
    path = ROOT / f"config/{ver}/splits.txt"
    blocks = [b for b in read_blocks(path) if b[0] != unit]
    body = [f"{unit}:\n"] + [f"\t{s:<12} start:0x{a:08X} end:0x{b:08X}\n" for s, a, b in secs] + ["\n"]
    k = se_order.index(unit)
    pos = next((i for i, b in enumerate(blocks)
                if b[0] in se_order and se_order.index(b[0]) > k), len(blocks))
    blocks.insert(pos, [unit, body])
    path.write_text("".join(l for _, ls in blocks for l in ls))


def apply_unit(ver, unit, L, plan_v, se_syms, se_order):
    """plan_v: (funcs, secs) from mvlink.plan. Writes split + symbol renames."""
    funcs, secs = plan_v
    ts, te = L.se[unit][".text"]
    us_funcs = sorted(a for a in L.fm if ts <= a < te)
    reg = {a: (L.fm[a][0] if ver == "G4SJ01" else L.fm[a][1]) for a in us_funcs}
    sec_map = {s: (L.se[unit][s][0], L.se[unit][s][1], a, b) for s, a, b in secs}
    write_split(ver, unit, secs, se_order)
    path = ROOT / f"config/{ver}/symbols.txt"
    lines = path.read_text().splitlines(keepends=True)
    notes = []
    for name, sec, addr, rest in se_syms:
        if sec == ".text":
            f = us_funcs[bisect.bisect_right(us_funcs, addr) - 1]
            tgt = reg[f] + (addr - f)
        else:
            us_s, _, r_s, _ = sec_map[sec]
            tgt = r_s + (addr - us_s)
        n = place_symbol(lines, name, sec, tgt, rest)
        if n: notes.append(n)
    path.write_text("".join(lines))
    return notes


def gate(ver):
    c = subprocess.run(["python3", "configure.py", "--version", ver], cwd=ROOT, capture_output=True, text=True)
    if c.returncode:
        return False, "configure: " + c.stderr[-300:]
    n = subprocess.run(["ninja", "-j4"], cwd=ROOT, capture_output=True, text=True)
    out = n.stdout + n.stderr
    if n.returncode or f"build/{ver}/main.dol: OK" not in out:
        und = sorted(set(re.findall(r"undefined: '([^']*)'", out)))
        return False, ("undefined " + ",".join(und[:6])) if und else out[-300:]
    s = subprocess.run(["sha1sum", "-c", f"config/{ver}/build.sha1"], cwd=ROOT, capture_output=True, text=True)
    return s.returncode == 0, "" if s.returncode == 0 else s.stdout + s.stderr


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--dry-run", action="store_true")
    ap.add_argument("--only", nargs="*", default=None)
    args = ap.parse_args()
    os.chdir(ROOT)

    L = mvlink.Linker()
    se_order = list(L.se)
    linked = {v: set(mvlink.splits(v)) for v in PROMOTE}
    se_syms_all = []
    for line in (ROOT / "config/G4SE01/symbols.txt").read_text().splitlines(keepends=True):
        p = parse_sym(line)
        if p and not is_auto(p[0]):
            se_syms_all.append(p)

    cands = []
    for u in se_order:
        if args.only is not None and u not in args.only: continue
        if ".text" not in L.se[u] or all(u in linked[v] for v in PROMOTE): continue
        try: r = L.plan(u)
        except Exception: continue
        if isinstance(r, dict): cands.append((u, r))
    print(f"{len(cands)} candidates")
    if args.dry_run:
        for u, _ in cands: print("  ", u)
        return

    results = {}
    out_path = ROOT / "build/promote_sweep.json"
    for u, plan in cands:
        se_syms = [p for p in se_syms_all if
                   p[1] in L.se[u] and L.se[u][p[1]][0] <= p[2] < L.se[u][p[1]][1]]
        snap = {v: [(ROOT / f"config/{v}/{f}").read_bytes() for f in ("splits.txt", "symbols.txt")] for v in PROMOTE}
        notes, verdict = {}, {}
        for v in PROMOTE:
            notes[v] = apply_unit(v, u, L, plan[v], se_syms, se_order)
        for v in PROMOTE:
            ok, msg = gate(v)
            verdict[v] = (ok, msg)
            if not ok: break
        keep = all(verdict[v][0] for v in verdict) and len(verdict) == len(PROMOTE)
        if not keep:
            for v in PROMOTE:
                (ROOT / f"config/{v}/splits.txt").write_bytes(snap[v][0])
                (ROOT / f"config/{v}/symbols.txt").write_bytes(snap[v][1])
        results[u] = {"kept": keep, "notes": notes, "gate": {v: verdict[v][1] for v in verdict}}
        status = "KEEP" if keep else "REVERT"
        print(f"{status} {u} {'; '.join(f'{v}:{verdict[v][1] or 'ok'}' for v in verdict)}", flush=True)
        out_path.parent.mkdir(exist_ok=True)
        out_path.write_text(json.dumps(results, indent=1))
    kept = [u for u, r in results.items() if r["kept"]]
    print(f"kept {len(kept)}/{len(results)}")


if __name__ == "__main__":
    main()
