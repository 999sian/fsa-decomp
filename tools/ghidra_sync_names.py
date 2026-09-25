#!/usr/bin/env python3
"""Push real function names from config/G4SE01/symbols.txt into the Ghidra project
via the MCP server (renames Ghidra's default FUN_xxxxxxxx labels).

Usage: tools/ghidra_sync_names.py   (server must be running: fsa-ghidra-mcp)
"""
import json
import re
import subprocess
import sys
from pathlib import Path

root = Path(__file__).resolve().parent.parent
renames = []
for line in open(root / "config/G4SE01/symbols.txt"):
    m = re.match(r"(\S+) = \.text:0x([0-9A-F]+); // type:function", line)
    if m and not re.match(r"(fn_|@|lbl_)", m[1]):
        renames.append({"target_type": "function",
                        "identifier": "FUN_" + m[2].lower(), "new_name": m[1]})
out = subprocess.run([sys.executable, root / "tools/ghidra_mcp.py", "call", "batch_rename",
                      "--json", json.dumps({"renames": renames})],
                     capture_output=True, text=True).stdout
print(f"{out.count('\"success\" : true')} renamed, {len(renames)} candidates "
      "(already-renamed functions report 'not found')")
