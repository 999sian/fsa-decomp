# Recipe: matching an FSA actor TU

Everything below is the procedure the five bootstrap units (`Game/actors/`
BOTS, GFBS, DWAP, STGN, TJIJ) were matched with; each step is backed by the numbers
in their commits. It assumes the landed interface from `actor-base`:
`include/Game/Actor.h`, `cflags_game` + `GameLib(...)` in `configure.py`, and the
shared `__sinit` chain.

## 1. What an actor TU is made of

Take the ranges from the retail DOL, not from the round numbers:

| part | how to find it |
|---|---|
| `.text` | the actor's destructor, its overridden virtuals, and — last — the shared `__sinit`. The TU boundary is the first function after the previous TU's `__sinit`. |
| `extab` / `extabindex` | the DOL's `extabindex` table: 12-byte entries at `0x80011860 + 12N`, layout `(funcAddr, size, extabAddr)`. Every function your unit emits that needs exception metadata has one entry, and so does the `__sinit`. |
| `.ctors` | 4-byte word holding your `__sinit`'s address (find it by scanning the `.ctors` words for it) |
| `.data` | the class vtable: `{0, 0}` + the 19 `Actor` slots + the overrides. A 19-virtual class is `0x54` bytes — MWCC emits **no** trailing padding, even though dtk's auto symbol claims `0x58`. |
| `.bss` | the TU's own DestructorChain array (nine 0xC-byte nodes, 0x6C) — see §4 |

Definition order matters: retail emits the functions in a fixed order which is *not*
vtable order (TJIJ is `v06, v03, v01, dtor, __sinit`; STGN is `dtor, v06, v03, v01,
__sinit`; DWAP `dtor, v06, v03, v01, __sinit`; GFBS `v01, dtor, __sinit`). Reproduce
it by the order of the definitions in the source file.

## 2. The class declaration and its vtable

`include/Game/Actor.h` fixes the 19 slot order — never reorder or add a virtual, or
every vtable in the game shifts. A derived actor declares only the slots it
overrides, in slot order, and the compiler fixes the rest.

`docs/gamemap/actor_ctors.csv` maps the factory TU's constructors to the vtable
address each one stores, which is the join key with your class:

```
ctor        size  calls_Actor_ctor  vtable      vtable_symbol
0x801FF7BC  0x3C  yes               0x804AA7A8  lbl_804AA7A8   <- STGN
0x802020F0  0x3C  yes               0x8049C7F0  __vt__4BOTS    <- BOTS
```

The factory function itself lives in the unowned TU `0x801F9484-0x80204638` and is
**not** part of your actor TU.

## 3. `configure.py` and `symbols.txt`

```python
GameLib("Game", [
    Object(Matching, "Game/actors/<ID>.cpp"),
])
```

In `config/G4SE01/symbols.txt` rename, in your own block only:

* each function to the mangled name your object emits (`__dt__4STGNFv`,
  `v01__4STGNFv`, …) — objdiff pairs **by name**, so a `fn_800FEDD0` target against
  an `__dt__4BOTSFv` base reads 0 % even when the bytes are identical;
* the vtable to `__vt__4<ID>` and its size to `0x54`;
* the `__sinit` to `__sinit_<ID>_cpp` with `scope:local` (the compiler derives that
  name from the source file name).

## 4. The shared `__sinit` and its DestructorChain array

Include `Game/SinitPoolChain.h` as the **first** include of the TU. Its nine
`JASPoolAllocObject<T>::memPool_` definitions are what make the compiler synthesise
the 0x224 function; the pools/guards/dtors themselves are shared and coalesce with
the audio units' definitions at link time.

The TU then also owns its own DestructorChain array — nine 0xC-byte nodes, 0x6C bytes
of `.bss`. Read its address out of the retail `__sinit` prologue and claim it in your unit's `splits.txt` block:

```asm
8010312C  3C 60 80 4C   lis   r3, 0x804C0000
80103138  3B E3 B0 F8   addi  r31, r3, -0x4F08    # r31 = 0x804BB0F8  (DWAP)
```

```
	.bss        start:0x804BB0F8 end:0x804BB164
```

dtk will refuse the boundary with *"ends within symbol 'lbl_804BB0F8'
(0x804BB0F8..0x804BB1F8)"*: those 0x100 auto blocks each hold several TUs' chain
arrays, so refine the symbol and re-run:

```
lbl_804BB0F8 = .bss:0x804BB0F8; // type:object size:0x6C
lbl_804BB164 = .bss:0x804BB164; // type:object size:0x94
```

Skip this step and the link grows `.bss` by 0x70, every later section shifts, and
`ninja` stops printing `main.dol: OK`.

## 5. The gate

```sh
ninja -j4 build/G4SE01/src/Game/actors/<ID>.o
build/tools/objdiff-cli diff -p . -u main/Game/actors/<ID> -c functionRelocDiffs=none
rm -f build/G4SE01/ok && ninja -j8        # must print build/G4SE01/main.dol: OK
```

* Always pass `-c functionRelocDiffs=none`: that is the mask the project report uses
  and the CLI default is stricter.
* `NonMatching` objects are not linked, so an incomplete unit cannot break the hash —
  but only flip to `Matching` when every symbol in the diff is 100 % and the link is
  still green.
* Two deviations are expected and are not mismatches:
  **NOTE-1** `.bss` reads 0.0 because the chain array is emitted as the local symbol
  `@171`, which cannot pair with dtk's auto symbol; the bytes are identical.
  **NOTE-2** without the mask, `__sinit` reads 99.708 % because dtk reconstructs the
  eight `addi r5, r31, k` node offsets as relocations with addends.
  Details: `docs/audit/OMP_BRANCH_AUDIT.md`.

## 6. Worked examples (all linked `main.dol: OK`)

| unit | `.text` | extab | extabindex | fns | smallest/first commit |
|---|---|---|---|---|---|
| BOTS | 656 | 16 | 24 | 5 | `b65c58a` (chain array `0x804BACF8`) |
| GFBS | 688 | 24 | 36 | 3 | `602ab33` (`0x804BD160`) |
| DWAP | 716 | 24 | 36 | 5 | `bd5a770` (`0x804BB0F8`) |
| STGN | 716 | 24 | 36 | 5 | `6a2a14d` (`0x804D67B8`) |
| TJIJ | 656 | 16 | 24 | 5 | `c3bed8c` (`0x8050CA00`) |

Sources: `src/Game/actors/*.cpp` plus their `include/Game/actors/*.h`.
