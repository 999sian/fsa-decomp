#!/usr/bin/env python3
"""Report decompilation progress for CI and local workflows.

Uses compiler-verified progress data from build/<version>/report.json if available,
or falls back to the committed progress snapshot in config/<version>/progress.json.
Also computes exact configured object counts directly from configure.py.
"""
import argparse
import json
import os
import pathlib
import re
import sys
from typing import Any, Dict, List, Optional, Tuple

ROOT = pathlib.Path(__file__).resolve().parent.parent


def load_config_objects(version: str = "G4SE01") -> Dict[str, Dict[str, int]]:
    """Parse configure.py to count completed vs total objects per category for the specified version."""
    cats: Dict[str, Dict[str, int]] = {
        "all": {"matching": 0, "total": 0},
        "game": {"matching": 0, "total": 0},
        "sdk": {"matching": 0, "total": 0},
        "jsys": {"matching": 0, "total": 0},
    }

    if version != "G4SE01":
        # Other releases (G4SJ01, G4SP01) are currently assembly-split baselines without C++ source splits
        return cats

    saved_argv = sys.argv
    sys.argv = ["configure.py", "--version", version]
    try:
        sys.path.insert(0, str(ROOT))
        import configure
        config = configure.config
    finally:
        sys.argv = saved_argv

    for lib in config.libs:
        cat_id = lib.get("progress_category", "game")
        if cat_id not in cats:
            cats[cat_id] = {"matching": 0, "total": 0}
        for obj in lib.get("objects", []):
            cats[cat_id]["total"] += 1
            cats["all"]["total"] += 1
            if obj.completed:
                cats[cat_id]["matching"] += 1
                cats["all"]["matching"] += 1
    return cats


def load_progress_data(version: str = "G4SE01") -> Tuple[Dict[str, Any], str]:
    """Load progress data from build report, downloaded CI artifact, or committed snapshot."""
    build_report = ROOT / f"build/{version}/report.json"
    artifact_report = ROOT / f"build/{version}_progress.json"
    snapshot_report = ROOT / f"config/{version}/progress.json"

    source_desc = ""
    data: Dict[str, Any] = {}

    if build_report.exists():
        with open(build_report, "r", encoding="utf-8") as f:
            raw = json.load(f)
            source_desc = f"build/{version}/report.json (fresh build)"
            data = {
                "version": version,
                "source": source_desc,
                "measures": raw.get("measures", {}),
                "categories": raw.get("categories", []),
            }
    elif artifact_report.exists():
        with open(artifact_report, "r", encoding="utf-8") as f:
            data = json.load(f)
            source_desc = f"build/{version}_progress.json (CI artifact)"
            data["source"] = source_desc
    elif snapshot_report.exists():
        with open(snapshot_report, "r", encoding="utf-8") as f:
            data = json.load(f)
            source_desc = f"config/{version}/progress.json (committed snapshot)"
            data["source"] = source_desc
    elif version in ("G4SJ01", "G4SP01"):
        total_code = 4436808 if version == "G4SJ01" else 4542176
        total_funcs = 11559 if version == "G4SJ01" else 11585
        source_desc = f"{version} (baseline metadata)"
        data = {
            "version": version,
            "source": source_desc,
            "measures": {
                "matched_code_percent": 0.0,
                "matched_code": 0,
                "total_code": total_code,
                "matched_functions_percent": 0.0,
                "matched_functions": 0,
                "total_functions": total_funcs,
            },
            "categories": [],
        }
    else:
        sys.exit(f"Error: Neither {build_report}, {artifact_report}, nor {snapshot_report} exists.")
    # Convert numeric strings to int/float
    def convert_numbers(d: Dict[str, Any]) -> None:
        for k, v in d.items():
            if isinstance(v, str):
                if v.isdigit():
                    d[k] = int(v)
                else:
                    try:
                        d[k] = float(v)
                    except ValueError:
                        pass

    convert_numbers(data["measures"])
    for cat in data.get("categories", []):
        convert_numbers(cat.get("measures", {}))

    return data, source_desc


def make_progress_bar(pct: float, width: int = 15) -> str:
    """Generate a text progress bar."""
    filled = int(round(pct / 100.0 * width))
    empty = width - filled
    return "█" * filled + "░" * empty


def format_markdown(data: Dict[str, Any], obj_counts: Dict[str, Dict[str, int]]) -> str:
    """Format progress data as GitHub Actions Markdown summary."""
    m = data["measures"]
    version = data["version"]
    source = data.get("source", "")

    matched_code_pct = float(m.get("matched_code_percent", 0.0))
    fuzzy_code_pct = float(m.get("fuzzy_match_percent", 0.0))
    matched_code = int(m.get("matched_code", 0))
    total_code = int(m.get("total_code", 0))

    matched_funcs_pct = float(m.get("matched_functions_percent", 0.0))
    matched_funcs = int(m.get("matched_functions", 0))
    total_funcs = int(m.get("total_functions", 0))

    all_objs = obj_counts.get("all", {"matching": 0, "total": 0})
    files_pct = (all_objs["matching"] / all_objs["total"] * 100.0) if all_objs.get("total", 0) > 0 else 0.0

    lines = [
        f"## 🗡️ The Legend of Zelda: Four Swords Adventures — Decompilation Progress",
        "",
        f"**Target**: `{version}` | **Source**: *{source}*",
        "",
        f"| Metric | Progress | Percentage | Count |",
        f"| :--- | :---: | :---: | :---: |",
        f"| **Matched Code** | `{make_progress_bar(matched_code_pct)}` | **{matched_code_pct:.2f}%** | {matched_code:,} / {total_code:,} bytes |",
        f"| **Fuzzy Code** | `{make_progress_bar(fuzzy_code_pct)}` | **{fuzzy_code_pct:.2f}%** | *(includes near-matches)* |",
        f"| **Matched Functions** | `{make_progress_bar(matched_funcs_pct)}` | **{matched_funcs_pct:.2f}%** | {matched_funcs:,} / {total_funcs:,} functions |",
        f"| **Configured Matching Files** | `{make_progress_bar(files_pct)}` | **{files_pct:.2f}%** | {all_objs['matching']} / {all_objs['total']} files |",
        "",
        "### Progress by Category",
        "",
        "| Category | Progress | Matched Code | Code % | Matched Fns | Fns % | Configured Files |",
        "| :--- | :---: | :---: | :---: | :---: | :---: | :---: |",
    ]

    for cat in data.get("categories", []):
        name = cat.get("name", "")
        cid = cat.get("id", "")
        cm = cat.get("measures", {})

        c_matched = int(cm.get("matched_code", 0) or 0)
        c_total = int(cm.get("total_code", 0) or 0)
        c_pct = float(cm.get("matched_code_percent", 0.0) or 0.0) if c_total > 0 else 0.0

        f_matched = int(cm.get("matched_functions", 0) or 0)
        f_total = int(cm.get("total_functions", 0) or 0)
        f_pct = float(cm.get("matched_functions_percent", 0.0) or 0.0) if f_total > 0 else 0.0
        objs = obj_counts.get(cid, {"matching": 0, "total": 0})
        bar = f"`{make_progress_bar(c_pct, 10)}`"

        lines.append(
            f"| **{name}** | {bar} | {c_matched:,} / {c_total:,} B | **{c_pct:.2f}%** | "
            f"{f_matched:,} / {f_total:,} | {f_pct:.2f}% | {objs['matching']} / {objs['total']} |"
        )

    lines.extend([
        "",
        f"*Report generated automatically by GitHub Actions CI.*",
        "",
    ])
    return "\n".join(lines)


def format_console(data: Dict[str, Any], obj_counts: Dict[str, Dict[str, int]]) -> str:
    """Format progress for terminal display."""
    m = data["measures"]
    version = data["version"]

    matched_pct = float(m.get("matched_code_percent", 0.0))
    matched_code = int(m.get("matched_code", 0))
    total_code = int(m.get("total_code", 0))

    funcs_pct = float(m.get("matched_functions_percent", 0.0))
    matched_funcs = int(m.get("matched_functions", 0))
    total_funcs = int(m.get("total_functions", 0))

    all_objs = obj_counts.get("all", {"matching": 0, "total": 0})

    lines = [
        f"Decompilation Progress ({version}):",
        f"  Matched Code:      {make_progress_bar(matched_pct)} {matched_pct:6.2f}% ({matched_code:,} / {total_code:,} bytes)",
        f"  Matched Functions: {make_progress_bar(funcs_pct)} {funcs_pct:6.2f}% ({matched_funcs:,} / {total_funcs:,} functions)",
        f"  Configured Files:  {all_objs['matching']} / {all_objs['total']} completed",
    ]
    for cat in data.get("categories", []):
        name = cat.get("name", "")
        cid = cat.get("id", "")
        cm = cat.get("measures", {})
        c_matched = int(cm.get("matched_code", 0) or 0)
        c_total = int(cm.get("total_code", 0) or 0)
        c_pct = float(cm.get("matched_code_percent", 0.0) or 0.0) if c_total > 0 else 0.0
        f_matched = int(cm.get("matched_functions", 0))
        f_total = int(cm.get("total_functions", 0))
        objs = obj_counts.get(cid, {"matching": 0, "total": 0})

        lines.append(
            f"  {name:18s}: {make_progress_bar(c_pct)} {c_pct:6.2f}% "
            f"({c_matched:>7,} / {c_total:<7,} B, {f_matched}/{f_total} fns, {objs['matching']}/{objs['total']} files)"
        )
    return "\n".join(lines)


def make_shields_json(data: Dict[str, Any]) -> Dict[str, Any]:
    """Generate shields.io endpoint JSON."""
    pct = float(data["measures"].get("matched_code_percent", 0.0))
    color = "red"
    if pct >= 90:
        color = "brightgreen"
    elif pct >= 75:
        color = "green"
    elif pct >= 50:
        color = "yellowgreen"
    elif pct >= 25:
        color = "yellow"
    elif pct >= 10:
        color = "orange"

    return {
        "schemaVersion": 1,
        "label": "decomp",
        "message": f"{pct:.2f}%",
        "color": color,
    }

def update_readme(readme_path: pathlib.Path, data: Dict[str, Any], obj_counts: Dict[str, Dict[str, int]]) -> bool:
    """Update progress badges and markdown progress tracker table in README.md."""
    if not readme_path.exists():
        raise FileNotFoundError(f"README file not found: {readme_path}")
    content = readme_path.read_text(encoding="utf-8")

    start_tag = "<!-- PROGRESS_START -->"
    end_tag = "<!-- PROGRESS_END -->"
    if start_tag not in content or end_tag not in content:
        raise ValueError(
            f"README.md at {readme_path} must contain both '{start_tag}' and '{end_tag}' marker comments."
        )

    m = data.get("measures", {})
    code_pct = float(m.get("matched_code_percent", 0.0))
    funcs_pct = float(m.get("matched_functions_percent", 0.0))
    all_objs = obj_counts.get("all", {"matching": 0, "total": 0})

    # 1. Update badges
    code_color = "red" if code_pct < 10 else "yellow" if code_pct < 50 else "green"
    badge_code = f"[![Matched Code](https://img.shields.io/badge/Code-{code_pct:.2f}%25-{code_color}.svg)](https://github.com/999sian/fsa-decomp)"
    badge_funcs = f"[![Matched Functions](https://img.shields.io/badge/Functions-{funcs_pct:.2f}%25-green.svg)](https://github.com/999sian/fsa-decomp)"
    badge_objs = f"[![Linked Objects](https://img.shields.io/badge/Linked_Files-{all_objs['matching']}%20%2F%20{all_objs['total']}-blue.svg)](https://github.com/999sian/fsa-decomp)"

    content = re.sub(r'\[!\[Matched Code\]\([^)]+\)\]\([^)]+\)', badge_code, content)
    content = re.sub(r'\[!\[Matched Functions\]\([^)]+\)\]\([^)]+\)', badge_funcs, content)
    content = re.sub(r'\[!\[Linked Objects\]\([^)]+\)\]\([^)]+\)', badge_objs, content)

    # 2. Update progress table between markers
    table_lines = [
        start_tag,
        "| Category | Matched Code | Matched Functions | Linked Files | Progress |",
        "| :--- | :--- | :--- | :--- | :--- |",
        f"| **Overall** | **{code_pct:.2f}%** ({int(m.get('matched_code', 0)):,} / {int(m.get('total_code', 0)):,} B) | **{funcs_pct:.2f}%** ({int(m.get('matched_functions', 0)):,} / {int(m.get('total_functions', 0)):,} fns) | **{all_objs['matching']} / {all_objs['total']}** | `{make_progress_bar(code_pct, 15)}` |",
    ]
    for cat in data.get("categories", []):
        name = cat.get("name", "")
        cid = cat.get("id", "")
        cm = cat.get("measures", {})
        c_matched = int(cm.get("matched_code", 0) or 0)
        c_total = int(cm.get("total_code", 0) or 0)
        c_pct = float(cm.get("matched_code_percent", 0.0) or 0.0) if c_total > 0 else 0.0
        f_matched = int(cm.get("matched_functions", 0) or 0)
        f_total = int(cm.get("total_functions", 0) or 0)
        f_pct = float(cm.get("matched_functions_percent", 0.0) or 0.0) if f_total > 0 else 0.0
        objs = obj_counts.get(cid, {"matching": 0, "total": 0})
        table_lines.append(
            f"| **{name}** | **{c_pct:.2f}%** ({c_matched:,} / {c_total:,} B) | **{f_pct:.2f}%** ({f_matched:,} / {f_total:,} fns) | **{objs['matching']} / {objs['total']}** | `{make_progress_bar(c_pct, 15)}` |"
        )
    fuzzy_pct = float(m.get("fuzzy_match_percent", 0.0))
    table_lines.extend([
        "",
        f"*Fuzzy code matching stands at **{fuzzy_pct:.2f}%** (includes near-matches).*",
        end_tag,
    ])
    pattern = re.compile(rf"{re.escape(start_tag)}[\s\S]*?{re.escape(end_tag)}")
    content = pattern.sub("\n".join(table_lines), content)

    readme_path.write_text(content, encoding="utf-8")
    return True


def run_regression_test(data: Dict[str, Any], obj_counts: Dict[str, Dict[str, int]], source: str) -> bool:
    """Verify progress reporting against invariant rules, schema constraints, and sanity floors."""
    print(f"Running regression test on progress reporting (source: {source})...")
    m = data.get("measures", {})
    code_pct = float(m.get("matched_code_percent", 0.0))
    funcs_pct = float(m.get("matched_functions_percent", 0.0))
    total_code = int(m.get("total_code", 0))
    matched_code = int(m.get("matched_code", 0))
    total_funcs = int(m.get("total_functions", 0))
    matched_funcs = int(m.get("matched_functions", 0))

    # 1. Total size & function count invariants for G4SE01 retail main.dol
    assert total_code >= 4_400_000, f"Expected total_code >= 4.4M bytes, got {total_code}"
    assert total_funcs >= 11_000, f"Expected total_funcs >= 11,000, got {total_funcs}"
    assert 0 <= matched_code <= total_code, f"Invariant violated: matched_code {matched_code} not in [0, {total_code}]"
    assert 0 <= matched_funcs <= total_funcs, f"Invariant violated: matched_funcs {matched_funcs} not in [0, {total_funcs}]"
    assert 0.0 <= code_pct <= 100.0, f"Invariant violated: code_pct {code_pct} not in [0, 100]"
    assert 0.0 <= funcs_pct <= 100.0, f"Invariant violated: funcs_pct {funcs_pct} not in [0, 100]"

    # 2. Mathematical calculation consistency
    expected_code_pct = 100.0 * matched_code / total_code if total_code else 0.0
    assert abs(code_pct - expected_code_pct) < 0.05, (
        f"Mathematical mismatch in code pct: reported {code_pct:.2f}% != calculated {expected_code_pct:.2f}%"
    )
    expected_funcs_pct = 100.0 * matched_funcs / total_funcs if total_funcs else 0.0
    assert abs(funcs_pct - expected_funcs_pct) < 0.05, (
        f"Mathematical mismatch in funcs pct: reported {funcs_pct:.2f}% != calculated {expected_funcs_pct:.2f}%"
    )

    # 3. Category consistency invariants
    for cat in data.get("categories", []):
        c_m = cat.get("measures", {})
        c_tot_code = int(c_m.get("total_code", 0))
        c_match_code = int(c_m.get("matched_code", 0))
        c_tot_fn = int(c_m.get("total_functions", 0))
        c_match_fn = int(c_m.get("matched_functions", 0))
        c_code_pct = float(c_m.get("matched_code_percent", 0.0))
        c_fn_pct = float(c_m.get("matched_functions_percent", 0.0))
        assert 0 <= c_match_code <= c_tot_code, f"Category {cat.get('id')} code match exceeds total"
        assert 0 <= c_match_fn <= c_tot_fn, f"Category {cat.get('id')} funcs match exceeds total"
        if c_tot_code > 0:
            c_exp_code = 100.0 * c_match_code / c_tot_code
            assert abs(c_code_pct - c_exp_code) < 0.05, (
                f"Category {cat.get('id')} code pct mismatch: reported {c_code_pct:.2f}% != calculated {c_exp_code:.2f}%"
            )
        if c_tot_fn > 0:
            c_exp_fn = 100.0 * c_match_fn / c_tot_fn
            assert abs(c_fn_pct - c_exp_fn) < 0.05, (
                f"Category {cat.get('id')} funcs pct mismatch: reported {c_fn_pct:.2f}% != calculated {c_exp_fn:.2f}%"
            )
    # 3. Configured object count invariants (additive across categories)
    all_objs = obj_counts.get("all", {})
    game_objs = obj_counts.get("game", {})
    sdk_objs = obj_counts.get("sdk", {})
    jsys_objs = obj_counts.get("jsys", {})

    version = data.get("version", "G4SE01")
    for cat_name, counts in obj_counts.items():
        if version == "G4SE01":
            assert counts.get("total", 0) > 0, f"Category {cat_name} has 0 total objects"
        assert 0 <= counts.get("matching", 0) <= counts.get("total", 0), (
            f"Category {cat_name} matching {counts.get('matching')} not in [0, {counts.get('total')}]"
        )
    expected_sum_total = game_objs.get("total", 0) + sdk_objs.get("total", 0) + jsys_objs.get("total", 0)
    assert all_objs.get("total") == expected_sum_total, (
        f"All total {all_objs.get('total')} != sum of categories {expected_sum_total}"
    )
    expected_sum_matching = game_objs.get("matching", 0) + sdk_objs.get("matching", 0) + jsys_objs.get("matching", 0)
    assert all_objs.get("matching") == expected_sum_matching, (
        f"All matching {all_objs.get('matching')} != sum of categories {expected_sum_matching}"
    )

    # 4. Sanity floor bounds for primary target G4SE01
    if version == "G4SE01":
        assert code_pct >= 25.0, f"Code progress sanity floor failed: {code_pct:.2f}% < 25.0%"
        assert funcs_pct >= 50.0, f"Functions progress sanity floor failed: {funcs_pct:.2f}% < 50.0%"
        assert all_objs.get("matching", 0) >= 400, f"Matching objects sanity floor failed: {all_objs.get('matching')} < 400"

    print(f"Code progress: {code_pct:.2f}% ({matched_code:,} / {total_code:,} bytes)")
    print(f"Function progress: {funcs_pct:.2f}% ({matched_funcs:,} / {total_funcs:,} funcs)")
    print(f"Configured objects: {all_objs.get('matching')} / {all_objs.get('total')} matching")
    print("ALL INVARIANT & SCHEMA CHECKS PASSED!")
    return True


def main():
    parser = argparse.ArgumentParser(description="Decompilation progress reporter")
    parser.add_argument("--version", default="G4SE01", help="Game version target")
    parser.add_argument("--format", choices=["console", "markdown", "json"], default="console")
    parser.add_argument("--summary", action="store_true", help="Write to $GITHUB_STEP_SUMMARY if available")
    parser.add_argument("--output-json", type=pathlib.Path, help="Save progress JSON to file")
    parser.add_argument("--output-shields", type=pathlib.Path, help="Save shields.io JSON to file")
    parser.add_argument("--update-readme", action="store_true", help="Update README.md progress section and badges")
    parser.add_argument("--test", action="store_true", help="Run regression self-test")
    args = parser.parse_args()

    data, source = load_progress_data(args.version)
    obj_counts = load_config_objects(args.version)

    if args.test:
        success = run_regression_test(data, obj_counts, source)
        sys.exit(0 if success else 1)

    if args.format == "markdown":
        output = format_markdown(data, obj_counts)
    elif args.format == "json":
        output = json.dumps(data, indent=2)
    else:
        output = format_console(data, obj_counts)

    print(output)

    if args.summary:
        summary_env = os.getenv("GITHUB_STEP_SUMMARY")
        if summary_env:
            with open(summary_env, "a", encoding="utf-8") as f:
                f.write(format_markdown(data, obj_counts) + "\n")

    if args.output_json:
        args.output_json.parent.mkdir(parents=True, exist_ok=True)
        args.output_json.write_text(json.dumps(data, indent=2), encoding="utf-8")

    if args.output_shields:
        args.output_shields.parent.mkdir(parents=True, exist_ok=True)
        shields = make_shields_json(data)
        args.output_shields.write_text(json.dumps(shields, indent=2), encoding="utf-8")
    if args.update_readme:
        readme_path = ROOT / "README.md"
        if update_readme(readme_path, data, obj_counts):
            print("Successfully updated README.md progress tracker and badges!")


if __name__ == "__main__":
    main()
