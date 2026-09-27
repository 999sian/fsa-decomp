# Playbook: matching a game TU in parallel workstreams

Written from the Actor base TU run (`0x801EE24C-0x801F6058`, 75 functions, 32,268 bytes), where ten
workstreams ran in parallel and the rounds were integrated and verified. Everything here is either a
measured result or a trap that cost a round; the numbers are from that run.

## The problem the contract solves

All the functions of one retail TU live in **one file**, so N workers cannot simply edit it. The pattern
that works:

1. **One worktree per workstream**, all forked from the same verified commit: `git worktree add -f
   <dir> -b <tag> <base-commit>`, plus the gitignored `orig/G4SE01/sys/main.dol` (a fresh worktree
   cannot build without it, and `ninja` re-runs `configure` so you cannot dodge it).
2. **Disjoint function sets** - no two workstreams touch the same function.
3. **Append-only edits**: each workstream adds its own block (its `extern "C"` declarations + definitions) at
   the **end** of the `.cpp` and edits nothing else. No reformatting, no reordering, no touching
   `configure.py` / `splits.txt` / `symbols.txt` / the header.
4. **One owner per shared config.** Only the integrator edits `configure.py` and the unit's split/symbols.
5. Each workstream commits on its own branch and never rebases, merges or pushes.

## Integration: apply each branch's delta as a patch

`tools/integrate_actor_branches.sh <content-base> <default-fork> <branch>[=<fork>]...` applies each
branch's delta onto the content base with **`git apply -3`** (a patch whose merge base is that branch's
own fork point) and then builds, gates, commits the round and advances the content base ref.

Three failure modes shaped this, all found by running it rather than reading it:

* A textual union merge of two appended C++ blocks produced unbalanced braces and nested `extern "C" {`;
  plain concatenation cannot express "this branch *replaced* an existing function", and hand-rolled
  definition removal truncated a body (dangling identifier). `git apply` handles additions, rewrites and
  deletions and fails loudly.
* Most deltas are **pure EOF appends**, and their 3 context lines are whatever happened to be last at
  fork time - which the content base has since replaced, so a 3-way apply conflicts over nothing. The
  script detects that case (single hunk, no `-` lines, preimage reaching the fork's last line) and
  appends at the true end of file. When a conflict does occur, marker *lines* are dropped and both sides
  kept (the function sets are disjoint); pairing markers with a regex is not robust, a conflict can nest
  inside another one's resolution and leave a stray `>>>>>>>`.
* **Give each branch its own fork point** (`branch=fork`): a branch that was integrated in an earlier
  round must be diffed from where it was integrated, or its delta repeats and you get duplicate
  definitions.

**Declaration conflicts** are then reconciled by `tools/reconcile_decls.py`: workstreams declare the helpers
they call and the same helper can arrive spelled two ways, which C++ forbids for an `extern "C"` name.
The tool only considers real declarations (column-0 `extern "C" ...;` or lines inside an
`extern "C" { ... }` block), so it cannot delete a call statement; it reports nested blocks as an error
instead of patching around them. The integrator also runs a repair loop: MWCC names the offending
declaration ("illegal function overloading"), so it targets exactly that name and rebuilds.

One measured subtlety: a declaration's **return type changes the codegen of its callers**, not just its
own function. `fn_801F666C` declared `Actor*` keeps `v07` at 100 %; declared `extern "C" void*` it takes
`fn_801EE24C` to 100 % and drops `v07` to 98.86 %. Two call sites in one TU disagreeing means one of the
two bodies is not yet right - do not "fix" it by flipping the declaration.

## Three checks the matching mask does not do for you

`-c functionRelocDiffs=none` normalises relocation operands. It is the right mask for dtk-reconstructed
relocations, and it means:

1. **A `bl` to the wrong function still reads 100 %.** Run `tools/check_call_targets.py <worktree>
   <unit>` before committing: it compares the `bl` target *name* sequence, retail versus ours. On the
   Actor TU this caught exactly one real case (a function whose first two calls were swapped and whose
   third was a different helper) and cleared the other 55.
2. **Function order is invisible** while the unit is `NonMatching`. At the flip the object is linked and
   every function must sit at its retail address, i.e. the order of the definitions in the source
   decides the `.text` layout. `tools/check_unit_order.py <worktree> <unit>` reports the two orders.
   Doing the reorder: hoist **all** non-definition chunks (includes, comments, every `extern "C"`
   declaration block) above the definitions, then emit only the definitions sorted by `symbols.txt`
   address - a naive line-level pass dropped blank lines and moved declarations that sat inside
   definition chunks, producing an uncompilable file.
3. **A flag that lifts one function can sink another.** A workstream measured that `-opt nodeadstore`
   lifted `fn_801EE24C` from 95.47 % to byte-identical. Applied to the shared `cflags_game` on the
   integrated tree it does exactly that - and drops `v07__5ActorFv`, which is *Matching*, from 100 % to
   98.86 %: 372 bytes gained, 892 lost, 4,968 instead of 5,488. The flag is per TU, so it cannot be
   right for both; the dead store has to go away in `fn_801EE24C`'s source. Check both directions before
   adopting a flag: measure the unit's total and the matched set, not just the function you were
   chasing. (An earlier version of this note blamed a 96-byte DOL growth - that test ran on a tree whose
   `configure.py` union-merge was structurally broken, so it proved nothing. Verify the flag actually
   reaches the compiler with `ninja -t commands <obj> | grep nodeadstore` before believing any result;
   a first-occurrence text replace had silently put it in `cflags_jsystem`.)

## Facts worth knowing before you start (all measured)

* Partial units **do** count in `report.json`: a `NonMatching` unit still reports
  `matched_code` / `matched_functions` for the functions that match (36/75 -> `11.33 %`), so parallel
  progress is visible without waiting for the flip. Only the *link* waits.
* **Triage by shape, not by size alone**: `psq` usage and body size dominate cost. `psq_l`/`psq_st`
  cannot be produced from plain C++ (MWCC 2.6 has no paired-single optimiser at all: `-O4,p` is
  `-opt level=4,peephole,schedule`), so every such op is inline `__asm`, and the FPR numbers follow the
  **declaration order** of the `register f32` temps once there are ~5-6 of them (with 3, one lands in
  `f31` and the `stfd f31` prologue save grows the frame and collapses the match). `tools/
  actor_tu_functions.py` emits that triage table per function.
* Compiler revision and flags are settled for game code: GC/2.6 and GC/2.7 are byte-identical on a
  32 KB unit (36/75 either way), GC/3.0a3/a5 collapse to 17/75, and `-O4,p` beats `-O4` (23) and
  `-O3,p` (11).
* Callee-saved GPRs are allocated in source **declaration order** (first-declared -> `r31` down);
  hoisting one local reorders every later one. Cast the *comparison*, not the variable. Every cross-TU
  helper goes inside the `extern "C"` block, and a `u8`-returning function whose local is `u32` is what
  makes MWCC emit retail's trailing `clrlwi`.
* Residues cluster: (a) the target's load hoisting/pipelining into the prologue, (b) C-level FPR
  allocation, (c) single allocator tie-breaks. Report which family a stuck function is in, with byte
  counts - that is worth more to the next owner than a forced partial commit.

## Ghidra: what to use it for, and what it cannot do

A headless Ghidra 12.1.4 server with the FSA project is usually up on `127.0.0.1:8080`
(`fsa-ghidra-mcp`; `tools/ghidra_mcp.py tools` lists its tools, `tools/ghidra_mcp.py call get_code
function=0x801fd894 format=decompiler`). Use it for **questions about meaning and connectivity**:

* xrefs: who calls this function, who reads this global (`call xrefs address=0x… direction=to`), which
  is how you tell a helper's real callers from the ones you invented;
* the decompiler's view of a function's *shape* (loop nesting, guard polarity, what a manager field is
  used for) when you are reconstructing a body you have never seen - it is faster than reading 200
  instructions to learn "this walks a linked list";
* strings and vtables (`search_strings`, the vtable at `lbl_…`) to identify an actor or a manager.

Do **not** use it to resolve a matching residue. Every residue this run has hit is a *codegen* fact -
which register holds a parameter, where MWCC puts a callee-saved save, whether a struct copy streams or
loads into a register block - and the decompiler has no view of MWCC's allocator or scheduler. The
ground truth for those is the retail instruction stream (`objdiff-cli diff --format json`, or
`build/G4SE01/asm/`), compared instruction by instruction with registers normalised. Ask Ghidra *what
the code means*; ask objdiff *what the compiler did*.

Per function: name, address, size, final `match_percent`, the `main.dol: OK` line, the commit hash, and
the call-target check result. A partial body must be committed as such and **never** described as
matched; a map of a function you could not finish (signature, call sequence with argument setup, branch
structure, needed prototypes) is a legitimate deliverable and lets the next owner start from it.

## Round 7 results (2026-09-27)

Ten isolated source workstreams reconstructed 483 small functions from retail
assembly; five additional workstreams refined the compiler differences. Against
baseline `fd0b86a`, 417 functions / 41,608 bytes became instruction-exact:

| Unit | Implemented | Instruction-exact |
|---|---:|---:|
| `tu_8022AD64` | 160 | 157 |
| `tu_802D39B8` | 79 | 45 |
| `SLR1_8014FD5C` | 38 | 35 |
| `tu_8027E5BC` | 36 | 33 |
| `tu_80256C74` | 34 | 28 |
| `tu_8025EB18` | 34 | 31 |
| `tu_801213EC` | 33 | 25 |
| `tu_8028FBA0` | 26 | 25 |
| `tu_8016A2B4` | 22 | 21 |
| `tu_804023D0` | 21 | 17 |

The USA build passes its retail DOL hash. All 483 emitted symbols have the same
named direct-call sequences as retail, and all 417 instruction-exact functions
have matching relocation bindings or byte-verified equivalent scalar constants.
Neither the baseline nor the first compiled pass lost any function match score.
Overall matched code increased from 29.74% to 30.68%; game code reached 17.52%.

**All ten objects remain NonMatching.** The 66 other implementations, missing
larger functions, data ownership and exception metadata still require work.
The DOL check proves integration safety through the existing assembly fallback,
not that these complete objects can be linked from C++. Function emission order
also remains unresolved in `tu_80256C74`, `tu_801213EC`, `tu_8016A2B4` and
`tu_804023D0`.

Useful matching details:

- An `int` result with an explicit `u8` cast can reproduce a byte-width `extrwi`
  without changing the caller ABI. This matched `fn_8025F684` while preserving
  the already-exact `fn_8023EFEC` forwarder; byte-consuming callers cast explicitly.
- Simple direct geometry-field accesses avoided template-driven function
  deferral in SLR1 without losing its existing instruction matches. Aggregate
  `Vec` initialization was not interchangeable with scalar stores; the dynamic
  offset in `fn_8016B8AC` still needed its original TVec3 constructor.
- Ghidra corroborated signed `/32` and `%32` room indexing, and the asymmetric
  64-bit mask operation in `fn_802D7EB0`: setting sign-extends the 32-bit mask,
  while clearing zeroes the upper word.
- `Game/Actor.h` and the SDK header independently define `Vec`; including both
  exposes a collision. Unifying them also requires migrating Actor.cpp's legacy
  SDK declarations, so no shared-header change was retained in this round.
