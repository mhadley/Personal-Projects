#!/usr/bin/env python3
"""Lay all sheets over each other: list unfilled cells, references that do not
resolve, unrun probes and unverified rows. Exit 0 only when everything is clean."""
import json, pathlib, sys

root = pathlib.Path(__file__).resolve().parent.parent / "sheets"
weapons = json.loads((root / "weapons.json").read_text())
mh = json.loads((root / "movement_and_hooks.json").read_text())

problems, pending = [], []

def tables():
    yield "weapons", weapons["columns"], weapons["rows"]
    for name in ("movement", "weapon_feel", "probes", "hooks"):
        yield name, mh[name]["columns"], mh[name]["rows"]

ids = {r["id"] for _, _, rows in tables() for r in rows}
probe_ids = {r["id"] for r in mh["probes"]["rows"]}

for name, cols, rows in tables():
    for r in rows:
        for c in cols:
            if c not in r:
                problems.append(f"{name}.{r['id']}: column '{c}' missing")
            elif r[c] is None and not (name == "probes" and c == "result"):
                problems.append(f"{name}.{r['id']}.{c}: unfilled")
        for ref in r.get("refs", []):
            if ref not in ids:
                problems.append(f"{name}.{r['id']}: ref '{ref}' does not resolve")
        if r.get("needs_probe") and r["needs_probe"] not in probe_ids:
            problems.append(f"{name}.{r['id']}: probe '{r['needs_probe']}' does not resolve")
        if name == "probes" and r["result"] is None:
            pending.append(f"probe {r['id']} not run: {r['question']}")
        elif name != "probes" and r.get("verified") is False:
            pending.append(f"{name}.{r['id']} not verified")

print(f"UNFILLED / BROKEN ({len(problems)})")
for p in problems: print("  -", p)
print(f"NOT YET VERIFIED ({len(pending)})")
for p in pending: print("  -", p)
sys.exit(1 if problems else 0)
