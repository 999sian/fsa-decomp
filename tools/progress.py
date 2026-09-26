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
import sys
from typing import Any, Dict, List, Optional, Tuple

ROOT = pathlib.Path(__file__).resolve().parent.parent


def load_config_objects() -> Dict[str, Dict[str, int]]:
    """Parse configure.py to count completed vs total objects per category."""
    saved_argv = sys.argv
    sys.argv = ["configure.py"]
    try:
        sys.path.insert(0, str(ROOT))
        import configure
        config = configure.config
    finally:
        sys.argv = saved_argv

    cats: Dict[str, Dict[str, int]] = {
        "all": {"matching": 0, "total": 0},
    }
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
    """Load progress data from build report or committed snapshot."""
    build_report = ROOT / f"build/{version}/report.json"
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
    elif snapshot_report.exists():
        with open(snapshot_report, "r", encoding="utf-8") as f:
            data = json.load(f)
            source_desc = f"config/{version}/progress.json (committed snapshot)"
            data["source"] = source_desc
    else:
        sys.exit(f"Error: Neither {build_report} nor {snapshot_report} exists.")

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
        f"| **Configured Matching Files** | `{make_progress_bar(all_objs['matching'] / all_objs['total'] * 100 if all_objs['total'] else 0)}` | **{all_objs['matching'] / all_objs['total'] * 100:.2f}%** | {all_objs['matching']} / {all_objs['total']} files |",
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

        c_pct = float(cm.get("matched_code_percent", 0.0))
        c_matched = int(cm.get("matched_code", 0))
        c_total = int(cm.get("total_code", 0))

        f_pct = float(cm.get("matched_functions_percent", 0.0))
        f_matched = int(cm.get("matched_functions", 0))
        f_total = int(cm.get("total_functions", 0))

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
        c_pct = float(cm.get("matched_code_percent", 0.0))
        c_matched = int(cm.get("matched_code", 0))
        c_total = int(cm.get("total_code", 0))
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


def run_regression_test(data: Dict[str, Any], obj_counts: Dict[str, Dict[str, int]]) -> bool:
    """Verify progress reporting against known verified values on origin/main."""
    print("Running regression test on progress reporting...")
    m = data["measures"]
    code_pct = float(m.get("matched_code_percent", 0.0))
    print(f"Overall matched code percent: {code_pct:.2f}% (expected ~25.47%)")
    assert abs(code_pct - 25.47) < 0.1, f"Unexpected overall code pct: {code_pct}"

    funcs_pct = float(m.get("matched_functions_percent", 0.0))
    print(f"Overall matched functions percent: {funcs_pct:.2f}% (expected ~53.04%)")
    assert abs(funcs_pct - 53.04) < 0.1, f"Unexpected overall funcs pct: {funcs_pct}"

    game_objs = obj_counts.get("game", {})
    print(f"Game matching objects: {game_objs.get('matching')} / {game_objs.get('total')} (expected 73 / 239)")
    assert game_objs.get("matching") == 73, f"Expected 73 matching game objects, got {game_objs.get('matching')}"
    assert game_objs.get("total") == 239, f"Expected 239 total game objects, got {game_objs.get('total')}"

    sdk_objs = obj_counts.get("sdk", {})
    print(f"SDK matching objects: {sdk_objs.get('matching')} / {sdk_objs.get('total')} (expected 172 / 175)")
    assert sdk_objs.get("matching") == 172, f"Expected 172 matching SDK objects, got {sdk_objs.get('matching')}"
    assert sdk_objs.get("total") == 175, f"Expected 175 total SDK objects, got {sdk_objs.get('total')}"

    jsys_objs = obj_counts.get("jsys", {})
    print(f"JSystem matching objects: {jsys_objs.get('matching')} / {jsys_objs.get('total')} (expected 168 / 183)")
    assert jsys_objs.get("matching") == 168, f"Expected 168 matching JSystem objects, got {jsys_objs.get('matching')}"
    assert jsys_objs.get("total") == 183, f"Expected 183 total JSystem objects, got {jsys_objs.get('total')}"

    print("\nALL REGRESSION TESTS PASSED!")
    return True


def main():
    parser = argparse.ArgumentParser(description="Decompilation progress reporter")
    parser.add_argument("--version", default="G4SE01", help="Game version target")
    parser.add_argument("--format", choices=["console", "markdown", "json"], default="console")
    parser.add_argument("--summary", action="store_true", help="Write to $GITHUB_STEP_SUMMARY if available")
    parser.add_argument("--output-json", type=pathlib.Path, help="Save progress JSON to file")
    parser.add_argument("--output-shields", type=pathlib.Path, help="Save shields.io JSON to file")
    parser.add_argument("--test", action="store_true", help="Run regression self-test")
    args = parser.parse_args()

    data, source = load_progress_data(args.version)
    obj_counts = load_config_objects()

    if args.test:
        success = run_regression_test(data, obj_counts)
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


if __name__ == "__main__":
    main()
