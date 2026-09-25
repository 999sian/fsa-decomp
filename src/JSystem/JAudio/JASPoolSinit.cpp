// First .text TU of main.dol (0x80021840). Its real name is unknown: it holds a
// single function returning 0 and, because it sees the nine JASPoolAllocObject
// memPool_ definitions, the standard FSA per-TU __sinit plus the (weak) nine
// JASMemPool<T> destructors. Being first, it is the TU whose weak pool/guard
// copies the linker kept. See docs/game/sinit_pools.md.

#include "JSystem/JAudio/JASFakeMatchFSA.h"

extern "C" int fn_80021840() {
    return 0;
}
