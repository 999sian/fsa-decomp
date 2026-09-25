# The shared per-TU `__sinit` (JASPoolAllocObject memPool_)

511 retail TUs end in an identical 0x224-byte `__sinit` that constructs and
registers nine `JASPoolAllocObject<T>::memPool_` objects. It is compiler
generated: any TU that sees the nine `template <>` memPool_ definitions emits it.

## Recipe

```cpp
#include "JSystem/JAudio/JASFakeMatchFSA.h"   // compile with -DMATCHING=1
```

Include it after the TU's own code (at the end, like mkdd's `JASFakeMatch*.h`).
This reproduces `fn_80021848` (now `__sinit_JASPoolSinit_cpp`) byte-for-byte,
including the order, and the nine weak `JASMemPool<T>` destructors in retail
order (0x80021A6C..0x80021D0C). Verified: `src/JSystem/JAudio/JASPoolSinit.cpp`
is linked as `Matching` with `main.dol: OK`.

## The nine pools (retail order)

| i | pool (.bss) | guard (.sbss) | dtor | T |
|---|---|---|---|---|
| 0 | 0x804B21AC | 0x8053A2AC | 0x80021D0C | `JASTrack::TChannelMgr` (MultiThreaded) |
| 1 | 0x804B21BC | 0x8053A2AD | 0x80021CB8 | `JASTrack` (MultiThreaded) |
| 2 | 0x804B21CC | 0x8053A2AE | 0x80021C64 | `JASChannel` (MultiThreaded) |
| 3 | 0x804B21DC | 0x8053A2AF | 0x80021C10 | unknown FSA class (`JASPoolObj3_FSA`) |
| 4 | 0x804B21EC | 0x8053A2B0 | 0x80021BBC | unknown FSA class (`JASPoolObj4_FSA`) |
| 5 | 0x804B21FC | 0x8053A2B1 | 0x80021B68 | `JAIStream` |
| 6 | 0x804B220C | 0x8053A2B2 | 0x80021B14 | `JAISoundChild` |
| 7 | 0x804B221C | 0x8053A2B3 | 0x80021AC0 | `JAISeq` |
| 8 | 0x804B222C | 0x8053A2B4 | 0x80021A6C | `JAISe` |

Pool order = reverse of the declaration order in the header (the `__sinit`
registers them in declaration order; MWCC lays the objects out in reverse).
T identities are fixed by the matched dtor/pool symbol names (the T order
in the header reproduces the retail `__sinit` exactly).

Pools 3 and 4 are FSA-only classes (not in mkdd/tp). Pool 3 is allocated in
the 0x8003CFC0 function (JAU area, size 0x40, via `JASGenericMemPool::alloc`);
pool 4 only appears in `__sinit`s. Their real names are unknown; the
placeholders only affect symbol names (the mangled lengths differ, which is
harmless because the pools are referenced by address in the asm). Rename them
in `JASFakeMatchFSA.h` + `symbols.txt` once identified.

## Linking notes

- The pools and guards are declared `scope:global` in `symbols.txt` and are
  NOT part of the `JASPoolSinit.cpp` split (bss ends at 0x804B21AC, no .sbss):
  the retail layout does not correspond to one object's weak copies, so the
  auto-generated asm owns them and every compiled TU's weak copies are dropped.
- The TU needs `-Cpp_exceptions on`: retail has extab/extabindex entries for
  its `__sinit` and dtors (extab 0x80005600-0x80005650).
- `JASGenericMemPool::JASGenericMemPool()` (0x80028974) and `~JASGenericMemPool()`
  (0x8002898C) must have their real names in `symbols.txt`.
- The JAudio/Interface TUs matched on `wf/jai` use mkdd's `JASFakeMatch*.h`
  subsets; game TUs should use `JASFakeMatchFSA.h`.
