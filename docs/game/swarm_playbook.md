# Playbook: matching a game TU with a swarm of agents

Written from the Actor base TU run (`0x801EE24C-0x801F6058`, 75 functions, 32,268 bytes), where ten
agents worked in parallel and the rounds were integrated and verified. Everything here is either a
measured result or a trap that cost a round; the numbers are from that run.

## The problem the contract solves

All the functions of one retail TU live in **one file**, so N agents cannot simply edit it. The pattern
that works:

1. **One worktree per agent**, all forked from the same verified commit: `git worktree add -f
   <dir> -b /<tag> <base-commit>`, plus the gitignored `orig/G4SE01/sys/main.dol` (a fresh worktree
   cannot build without it, and `ninja` re-runs `configure` so you cannot dodge it).
2. **Disjoint function sets** - no two agents touch the same function.
3. **Append-only edits**: each agent adds its own block (its `extern "C"` declarations + definitions) at
   the **end** of the `.cpp` and edits nothing else. No reformatting, no reordering, no touching
   `configure.py` / `splits.txt` / `symbols.txt` / the header.
4. **One owner per shared config.** Only the parent edits `configure.py` and the unit's split/symbols.
5. Each agent commits on its own branch and never rebases, merges or pushes.

## Integration: concatenate, do not merge

`tools/integrate_actor_swarm.sh <content-base> <fork-point> <branch>...` concatenates
`<content-base>:src/<Unit>.cpp` with each branch's **added lines** (diffed against the fork point, not
against the content base - otherwise you get the reverse of whatever the base added afterwards). A
textual union merge of two appended C++ blocks does not work: it produced unbalanced braces and nested
`extern "C" {`; concatenation cannot.

The script then builds, runs the gate and prints the total. It also reconciles **declaration conflicts**:
agents declare the helpers they call, and the same helper can arrive spelled two ways, which C++ forbids
for an `extern "C"` name. Round 1 died of exactly that (`fn_8013CC50` declared `void`, `s32`, and with
`u32`/`void*` where the float belonged). The fix is to derive the canonical prototype **from the retail
call sites** - every one of that helper's 23 sites set `f1` to a float plus `r5..r10`, so
`s32 fn_8013CC50(u32, void*, f32, u32 x5)` - then keep the first spelling and permute the odd call sites
to it (same registers, so no caller loses its 100 %).

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
3. **A flag found on one function can still be wrong.** An agent measured that `-opt nodeadstore` lifted
   its function 95.5 -> 100 %. Applied to the shared cflags it made a DOL-verified unit's linked image
   96 bytes longer and failed the checksum, while the control run in the same worktree printed
   `main.dol: OK`. A flag cannot be right for one function and wrong for a unit already verified by the
   hash - the difference belongs in the source.

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

## Reporting contract for agents

Per function: name, address, size, final `match_percent`, the `main.dol: OK` line, the commit hash, and
the call-target check result. A partial body must be committed as such and **never** described as
matched; a map of a function you could not finish (signature, call sequence with argument setup, branch
structure, needed prototypes) is a legitimate deliverable and lets the next owner start from it.
