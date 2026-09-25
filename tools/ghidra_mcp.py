#!/usr/bin/env python3
"""Minimal CLI client for the GhidrAssistMCP Streamable HTTP server.

Start the server first with `fsa-ghidra-mcp` (headless Ghidra on main.dol).

Usage:
  tools/ghidra_mcp.py tools                      # list tool names + descriptions
  tools/ghidra_mcp.py schema <tool>              # show a tool's input schema
  tools/ghidra_mcp.py call <tool> [key=value ...] # call a tool; values parsed as JSON if possible
  tools/ghidra_mcp.py call <tool> --json '{...}'  # call with a raw JSON arguments object
"""

import json
import os
import sys
import urllib.request

URL = os.environ.get("GHIDRA_MCP_URL", "http://127.0.0.1:8080/mcp")


def post(payload, session=None):
    headers = {
        "Content-Type": "application/json",
        "Accept": "application/json, text/event-stream",
    }
    if session:
        headers["Mcp-Session-Id"] = session
    req = urllib.request.Request(URL, json.dumps(payload).encode(), headers)
    with urllib.request.urlopen(req, timeout=600) as resp:
        sid = resp.headers.get("Mcp-Session-Id") or session
        body = resp.read().decode()
    if not body.strip():
        return None, sid
    if body.lstrip().startswith("{"):
        return json.loads(body), sid
    # SSE framing: take the last `data:` event carrying a JSON-RPC message
    msg = None
    for line in body.splitlines():
        if line.startswith("data:"):
            msg = json.loads(line[5:].strip())
    return msg, sid


def connect():
    _, sid = post({
        "jsonrpc": "2.0", "id": 0, "method": "initialize",
        "params": {"protocolVersion": "2025-03-26", "capabilities": {},
                   "clientInfo": {"name": "fsa-cli", "version": "1"}},
    })
    post({"jsonrpc": "2.0", "method": "notifications/initialized"}, sid)
    return sid


def rpc(sid, method, params):
    msg, _ = post({"jsonrpc": "2.0", "id": 1, "method": method, "params": params}, sid)
    if msg and "error" in msg:
        sys.exit(f"error: {msg['error']}")
    return msg["result"]


def parse_value(v):
    try:
        return json.loads(v)
    except ValueError:
        return v


def main(argv):
    if not argv or argv[0] in ("-h", "--help"):
        print(__doc__)
        return
    sid = connect()
    cmd = argv[0]
    if cmd in ("tools", "schema"):
        tools = rpc(sid, "tools/list", {})["tools"]
        if cmd == "tools":
            for t in tools:
                print(f"{t['name']:32} {(t.get('description') or '').splitlines()[0][:100]}")
        else:
            for t in tools:
                if t["name"] == argv[1]:
                    print(json.dumps(t, indent=2))
    elif cmd == "call":
        name, rest = argv[1], argv[2:]
        if rest and rest[0] == "--json":
            args = json.loads(rest[1])
        else:
            args = {k: parse_value(v) for k, v in (a.split("=", 1) for a in rest)}
        result = rpc(sid, "tools/call", {"name": name, "arguments": args})
        for item in result.get("content", []):
            print(item.get("text", json.dumps(item)))
        if result.get("isError"):
            sys.exit(1)
    else:
        sys.exit(__doc__)


if __name__ == "__main__":
    main(sys.argv[1:])
