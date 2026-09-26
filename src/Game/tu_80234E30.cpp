// TU 0x80234e30-0x8023fbf0.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// ---- Player_GetCapabilityFlag.cpp ----
// Player_GetCapabilityFlag - the same master-enable-flag read as Player_GetCapabilityFlagByIndex
// (`playerObj->0xcac`, see [[project_fsa_player_target_helper_decoded]]),
// but taking the player OBJECT directly instead of an index (no bounds-
// checking/roster lookup) - a convenience variant for callers that
// already hold the player pointer.
extern "C" {

u8 Player_GetCapabilityFlag(void* thisPtr) { return *(u8*)((char*)thisPtr + 0xcac); }

}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
