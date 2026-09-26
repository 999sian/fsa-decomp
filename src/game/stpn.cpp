// TU 0x802ed140-0x802ed538 (actor STPN).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- Stpn_EmptyHook1.cpp ----
// Stpn_EmptyHook1 / Stpn_EmptyHook2 - STPN: 2 empty no-op overrides (0x4 each, leaf, no extab needed)
extern "C" {

void Stpn_EmptyHook1(void) {}

void Stpn_EmptyHook2(void) {}

}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
