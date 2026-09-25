#ifndef GAME_SINIT_POOL_CHAIN_H
#define GAME_SINIT_POOL_CHAIN_H

#include "JSystem/JAudio/System/JASHeapCtrl.h"
#include "JSystem/JAudio/System/JASTrack.h" // JASTrack and its nested TChannelMgr

/*
 * The shared per-TU `__sinit` chain (0x224 bytes / 137 instructions).
 *
 * Every retail game TU ends with the SAME compiler-generated `__sinit`, which
 * registers nine file-scope objects with dynamic initialisers via
 * `__register_global_object`. The DOL contains 511 occurrences, all 0x224 bytes,
 * all registering the same nine (pool, dtor, guard) triples; the only per-TU
 * differences are the DestructorChain array address, its node offsets and the
 * `bl` displacements.
 *
 * Include this header in a TU that must emit that `__sinit`. Nine `memPool_`
 * definitions are what makes the compiler synthesise the function; two things
 * follow that a caller must know:
 *
 *  - The nine pools (`.bss` 0x804B21AC + 0x10*i), guards (`.sbss` 0x8053A2AC + i)
 *    and deleting destructors (`.text` 0x80021D0C - 0x54*i) are SHARED: this
 *    object emits them as weak/common definitions which the linker coalesces
 *    with the strong definitions the audio units already provide, so they add no
 *    storage. Each object additionally REFERENCES the nine destructors; those
 *    references only resolve because `config/G4SE01/symbols.txt` gives the retail
 *    dtors at 0x80021D0C… the exact mangled names this header's types produce.
 *  - The TU also gets its OWN DestructorChain array: nine 0xC-byte nodes, 0x6C
 *    bytes of `.bss`, which the `__sinit` prologue addresses via `r31`. That
 *    storage is per-unit and must be owned by the unit's `splits.txt` block at
 *    the address the retail `__sinit` loads (read the `lis`/`addi` pair). If it
 *    is left unclaimed, the link grows `.bss` by 0x70 and every later section
 *    shifts, so `ninja` stops printing `main.dol: OK`.
 *
 * Do not include a `JSystem/JAudio/JASFakeMatch*.h` in the same TU: those files
 * carry some of the same explicit specialisations, and a second definition of an
 * explicit specialisation is a hard redefinition error, not an interchangeable
 * interface.
 *
 * `JASMemPool<T>::~JASMemPool()` must stay DECLARED-ONLY (see JASHeapCtrl.h).
 * With an inline body MWCC emits nine weak dtor copies per TU, each with its own
 * extab entry, and the unit can never reach 100 %: retail actor units carry
 * exactly three extabindex entries (their dtor, one virtual, the `__sinit`), and
 * the nine dtors are defined once, in the audio code.
 *
 * The nine `T`, from the `sizeof(T)` immediates at the `JASPoolAllocObject<T>`
 * allocation sites (80, 592, 268, 64, -, 712, 100, 948, 832 for slots 1..9):
 * slots 1, 2, 6, 7, 8, 9 are matched unambiguously by the in-repo class headers.
 * Slots 3, 4 and 5 are the three remaining 268-byte candidates and are NOT
 * settled - slot 4's retail size (64) matches none of them, so at least one of
 * those retail classes differs from the imported one. The identity only decides
 * the NAME of the pool/dtor symbol, never the emitted bytes, so a correction is
 * name-only; `wf/jas-sinit` owns the authoritative answer. Whatever it returns,
 * the header and the `symbols.txt` renames must change together.
 */

class JASChannel;
class JAIStream;
class JAISoundChild;
class JAISeq;
class JAISe;
template <int N>
class JAUAudible;
template <int N>
class JAUDopplerAudible;

typedef JAUAudible<4> TAudible4;
typedef JAUDopplerAudible<4> TDopplerAudible4;

/* The order of these nine definitions IS the order of the `__sinit` entries, the
 * `.sbss` guard bytes and the `.bss` pool objects. Do not reorder. */
template <>
JASMemPool<JASTrack::TChannelMgr> JASPoolAllocObject<JASTrack::TChannelMgr>::memPool_;
template <>
JASMemPool<JASTrack> JASPoolAllocObject<JASTrack>::memPool_;
template <>
JASMemPool<JASChannel> JASPoolAllocObject<JASChannel>::memPool_;
template <>
JASMemPool<TAudible4> JASPoolAllocObject<TAudible4>::memPool_;
template <>
JASMemPool<TDopplerAudible4> JASPoolAllocObject<TDopplerAudible4>::memPool_;
template <>
JASMemPool<JAIStream> JASPoolAllocObject<JAIStream>::memPool_;
template <>
JASMemPool<JAISoundChild> JASPoolAllocObject<JAISoundChild>::memPool_;
template <>
JASMemPool<JAISeq> JASPoolAllocObject<JAISeq>::memPool_;
template <>
JASMemPool<JAISe> JASPoolAllocObject<JAISe>::memPool_;

#endif
