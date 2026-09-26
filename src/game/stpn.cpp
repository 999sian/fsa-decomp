// TU 0x802ed140-0x802ed538 (actor STPN).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- Stpn_EmptyHook1.cpp ----
// Stpn_EmptyHook1 / Stpn_EmptyHook2 - STPN: 2 empty no-op overrides (0x4 each, leaf, no extab needed)
extern "C" {

void Stpn_EmptyHook1(void) {}

void Stpn_EmptyHook2(void) {}

}

// Shared JAudio pool __sinit (docs/game/sinit_pools.md). Drop the ESD
// macros/typedefs that clash with the JSystem headers first.
#undef ALIGN_NEXT
#undef ALIGN_PREV
#undef ARRAY_SIZE
#undef ASM
#undef ATTRIBUTE_ALIGN
#undef IS_ALIGNED
#undef IS_NOT_ALIGNED
#undef MAX
#undef MIN
#undef NULL
#define NULL 0
#define unknown jsys_unknown
#include "JSystem/JAudio/JASFakeMatchFSA.h"
