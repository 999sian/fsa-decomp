// TU 0x8026fc20-0x8027e5bc.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- Player_GetLinkedHandleOrInvalid.cpp ----
// The player-object "special-state" cluster: accessors/mutators on a
// shared set of fields. Player_HasAnyStatusFlagSet (the OR-of-3-flags combined
// predicate with a shared-tail accumulator) is kept separately as raw
// asm in Dolphin/os/extab_8026fce0.s - it matches the already-
// documented "default value, conditionally overridden, single merge
// point" idiom that has repeatedly failed natural-C++ promotion this
// session.
extern "C" {

// Player_GetLinkedHandleOrInvalid(player) - if `player->0xb9c` is set, returns the handle
// stored at `player->0x3dc`; otherwise returns -1.
void* Player_GetLinkedHandleOrInvalid(void* thisPtr) {
	char* p = (char*)thisPtr;
	if (*(u8*)(p + 0xb9c) != 0) {
		return *(void**)(p + 0x3dc);
	}
	return (void*)-1;
}

// Player_GetField_0xb9b(player) - trivial byte accessor for `player->0xb9b`.
u8 Player_GetField_0xb9b(void* thisPtr) {
	return *(u8*)((char*)thisPtr + 0xb9b);
}

}

// ---- Player_CheckField_0xc9c.cpp ----
extern "C" {

// Player_CheckField_0xc9c(player) - returns whether `player->0xc9c` is nonzero.
BOOL Player_CheckField_0xc9c(void* thisPtr) {
	return *(s32*)((char*)thisPtr + 0xc9c) != 0;
}

// Player_GetModeSubPtr_0xb9a(player) - returns `player+0x5c0` if `player->0xb9a` is
// set, else `player+0x8`.
void* Player_GetModeSubPtr_0xb9a(void* thisPtr) {
	char* p = (char*)thisPtr;
	if (*(u8*)(p + 0xb9a) != 0) {
		return p + 0x5c0;
	}
	return p + 0x8;
}

}

// ---- Player_HasAnyStatusFlagSet_8026FCE0.cpp ----
// Player_HasAnyStatusFlagSet(player) - returns true if ANY of the three flags
// `player->0xb9a`/`0xb9c`/`0xb9d` is set, false only if all three are
// clear.
//
// A plain bare `return a || b || c;` with `bool` return type matches
// retail exactly on the first attempt - the CAED4-family recipe
// (see project_fsa_phase4_kickoff.md) generalizes cleanly to a 3-term
// OR-chain of independent byte flags, not just 2-term chains.
extern "C" bool Player_HasAnyStatusFlagSet(void* player) {
	char* p = (char*)player;
	return *(u8*)(p + 0xb9a) || *(u8*)(p + 0xb9c) || *(u8*)(p + 0xb9d);
}

// ---- stub_80270a8c.cpp ----
// fn_80270A8C - the sub-checker delegate for fn_80236B50 in the
// "per-player capability predicate" family. Returns true if
// playerObj->0x1244 == 0x33(51) OR playerObj->0x1240 == 0x33 OR
// playerObj->0x1240 == 0x34(52).
extern "C" s32 fn_80270A8C(void* playerObj) {
	if (*(s32*)((char*)playerObj + 0x1244) == 0x33 ||
	    *(s32*)((char*)playerObj + 0x1240) == 0x33 ||
	    *(s32*)((char*)playerObj + 0x1240) == 0x34) {
		return 1;
	}
	return 0;
}
