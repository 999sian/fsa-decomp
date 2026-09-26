// TU 0x8023fbf0-0x80255f4c.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- Player_GetLinkTargetIndex.cpp ----
// Player_GetLinkTargetIndex - raw accessor for the "linked player index" field
// discovered this session (see [[project_fsa_player_target_helper_decoded]]):
// returns playerObj->0xd60 directly, no validation. This is the "get my
// link target index, whatever it is (including negative/unlinked)"
// counterpart to Player_IsLinked's boolean "am I linked at all" check.
extern "C" {

u32 Player_GetLinkTargetIndex(void* thisPtr) { return *(u32*)((char*)thisPtr + 0xd60); }

}

// ---- Player_IsLinked.cpp ----
// The am-I-linked-to-another-player predicate (see project_fsa_player_target_helper_decoded.md).
extern "C" {
BOOL Player_IsLinked(void* thisPtr) {
	u32 v = *(u32*)((char*)thisPtr + 0xd60);
	return (v >> 31) ^ 1;
}
}

// ---- stub_80240818.cpp ----
// fn_80240818 - the sub-checker delegate for fn_8022DCD8 in the
// "per-player capability predicate" family. Returns true if
// playerObj->0x1240 == 0x49(73) OR playerObj->0x1244 == 0x49.
extern "C" s32 fn_80240818(void* playerObj) {
	s32 result = 0;
	if (*(s32*)((char*)playerObj + 0x1240) == 0x49 ||
	    *(s32*)((char*)playerObj + 0x1244) == 0x49) {
		result = 1;
	}
	return result;
}

// ---- ClaimField_0x11f4.cpp ----
// ClaimField_0x11f4 - "claim once" latch: if this->0x11f4 is already set (>0),
// return 0; otherwise store the incoming value and return 1.
// GetField_0x436/GetPtrField_0x4/GetField_0xcfe/IncrementField_0x1224 -
// trivial field accessors, the last one an increment counter.
extern "C" {

s32 ClaimField_0x11f4(void* thisObj, s32 val) {
	if (*(s32*)((char*)thisObj + 0x11f4) <= 0) {
		*(s32*)((char*)thisObj + 0x11f4) = val;
		return 1;
	} else {
		return 0;
	}
}

u8 GetField_0x436(void* thisObj) {
	return *((u8*)thisObj + 0x436);
}

void* GetPtrField_0x4(void* thisObj) {
	return *(void**)((char*)thisObj + 0x4);
}

u8 GetField_0xcfe(void* thisObj) {
	return *((u8*)thisObj + 0xcfe);
}

void IncrementField_0x1224(void* thisObj) {
	*(u32*)((char*)thisObj + 0x1224) += 1;
}

}

// ---- fn_80240888.cpp ----
extern "C" s32 fn_80234004(s32 playerIdx);

// fn_80240888 - another "linked player redirect" (same pattern as
// fn_80241920/fn_8024189C, see
// project_fsa_player_target_helper_decoded.md): if playerObj->0xd60
// (linked-player index) is set, delegates the SAME query to that other
// player via fn_80234004; otherwise returns playerObj->0x1224 directly
// (meaning of this field not yet identified, but consistently threaded
// through the whole link-redirect chain).
extern "C" s32 fn_80240888(void* playerObj) {
    s32 linked = *(s32*)((char*)playerObj + 0xd60);
    if (linked >= 0) {
        return fn_80234004(linked);
    }
    return *(s32*)((char*)playerObj + 0x1224);
}

// ---- Player_GetField_0x454.cpp ----
// Player_GetField_0x454 - a trivial one-field accessor, the sub-checker delegate
// for fn_80230188 in the "per-player capability predicate" family (see
// [[project_fsa_player_target_helper_decoded]]). Just returns
// playerObj->0x454 (a byte field, meaning not yet identified) directly -
// no further logic.
extern "C" {

u8 Player_GetField_0x454(void* thisPtr) { return *(u8*)((char*)thisPtr + 0x454); }

}

// ---- fn_802416C4.cpp ----
extern "C" s32 fn_802373EC(s32 playerIdx);

// fn_802416C4(playerObj) - the SAME "linked-delegate else raw field"
// idiom as the CONFIRMED fn_80247594 (extab_80247594.s): if
// playerObj->0xd60 (co-op LINK/CHAIN target,
// project_fsa_player_target_helper_decoded.md) is non-negative,
// delegates to not-yet-decompiled fn_802373EC(linkedIdx); otherwise
// returns playerObj->0xc10 directly - a "current sub-state" value.
// Confirmed caller: fn_802808E8 (extab_802808e8.s), which checks
// whether the result equals 5 before applying a special-case pitch
// scale.
extern "C" s32 fn_802416C4(void* playerObj) {
    s32 linked = *(s32*)((char*)playerObj + 0xd60);
    if (linked >= 0) {
        return fn_802373EC(linked);
    }
    return *(s32*)((char*)playerObj + 0xc10);
}

// ---- fn_8024189C.cpp ----
extern "C" s32 fn_80237774(s32 playerIdx);

// fn_8024189C - the sub-checker delegate for fn_80237774 in the "per-
// player capability predicate" family (see
// project_fsa_player_target_helper_decoded.md). Same "linked player"
// redirect pattern as fn_80241920: if playerObj->0xd60 (the
// linked-player index) is set, delegates the query to that OTHER
// player via fn_80237774. Otherwise, checks playerObj->0xc00 (a byte
// flag): if clear, returns playerObj->0xbfc directly; if set, returns
// 0.
extern "C" s32 fn_8024189C(void* playerObj) {
    s32 linked = *(s32*)((char*)playerObj + 0xd60);
    if (linked >= 0) {
        return fn_80237774(linked);
    }
    u8 flag = *(u8*)((char*)playerObj + 0xc00);
    if (flag != 0) {
        return 0;
    } else {
        return *(s32*)((char*)playerObj + 0xbfc);
    }
}

// ---- fn_802418E8.cpp ----
extern "C" s32 fn_80236100(s32 playerIdx);

// fn_802418E8(playerObj) - the SAME "linked-delegate else raw field"
// idiom as fn_802416C4/fn_80247594 (see
// project_fsa_player_target_helper_decoded.md): if playerObj->0xd60
// (co-op LINK/CHAIN target) is non-negative, delegates to
// fn_80236100(linkedIdx); otherwise returns playerObj->0xc04 directly.
extern "C" s32 fn_802418E8(void* playerObj) {
    s32 linked = *(s32*)((char*)playerObj + 0xd60);
    if (linked >= 0) {
        return fn_80236100(linked);
    }
    return *(s32*)((char*)playerObj + 0xc04);
}

// ---- fn_80241920.cpp ----
extern "C" s32 fn_80236228(s32 playerIdx);

// fn_80241920 - the sub-checker delegate for fn_80236228 in the "per-
// player capability predicate" family (see
// project_fsa_player_target_helper_decoded.md). First checks
// playerObj->0xd60 (a signed field): if >= 0, treats it as ANOTHER
// player's slot index and recursively delegates the SAME query to that
// player via fn_80236228 - a genuine "linked player" redirect. This is
// the first confirmed evidence of a per-player "linked to" index
// field, likely backing Four Swords Adventures' co-op link/chain
// mechanic. If unlinked (0xd60 < 0), falls back to returning
// playerObj->0xc04 clamped to non-negative (negative values become 0).
extern "C" s32 fn_80241920(void* playerObj) {
    s32 linked = *(s32*)((char*)playerObj + 0xd60);
    if (linked >= 0) {
        return fn_80236228(linked);
    }
    s32 val = *(s32*)((char*)playerObj + 0xc04);
    u32 mask = ((u32)val >> 31) - 1;
    return val & mask;
}

// ---- fn_80247594.cpp ----
extern "C" s32 fn_80237488(s32 linkedIdx);

// fn_80247594(playerObj, amount) - "consume `amount` units from a
// countdown pool" (playerObj->0xc08), returning whether any pool
// remained. If playerObj->0xd60 (the CONFIRMED co-op LINK/CHAIN target
// index) is non-negative, delegates entirely to fn_80237488(linkedIdx).
// Otherwise: if already flagged "done" (+0x1201==1), returns true
// without consuming further. If the pool covers `amount`, subtracts it
// and sets +0x1201=1 (success). If the pool is partially covered
// (>0 but < amount), zeroes it and still sets +0x1201=1 (success -
// "used up the last of it"). If the pool was already 0, sets
// +0x1202=1 (a distinct "exhausted" flag) and returns false.
extern "C" s32 fn_80247594(void* playerObj, s32 amount) {
	char* p = (char*)playerObj;
	s32 linked = *(s32*)(p + 0xd60);
	if (linked >= 0) {
		return fn_80237488(linked);
	}
	if (*(u8*)(p + 0x1201) == 1) {
		return 1;
	}
	s32 pool = *(s32*)(p + 0xc08);
	if (pool >= amount) {
		*(s32*)(p + 0xc08) = pool - amount;
		*(u8*)(p + 0x1201) = 1;
		return 1;
	}
	if (pool > 0) {
		*(s32*)(p + 0xc08) = 0;
		*(u8*)(p + 0x1201) = 1;
		return 1;
	}
	*(u8*)(p + 0x1202) = 1;
	return 0;
}

// ---- fn_80248FF0.cpp ----
extern "C" void* SpatialRegistry_GetBase();
extern "C" void* fn_801F666C(void* base, s32 id);

extern "C" void fn_80248FF0(void* companionObj) {
    char* p = (char*)companionObj;
    void* base = SpatialRegistry_GetBase();
    void* found = fn_801F666C(base, *(s32*)(p + 0x1230));
    if (found != 0) {
        *(u8*)((char*)found + 0x11c) = 0;
        *(s32*)(p + 0x1230) = -1;
    } else if (*(u8*)(p + 0x121f) == 1) {
        *(u8*)(p + 0x121f) = 0;
        if (*(s32*)(p + 0x11f0) < 5) {
            *(s32*)(p + 0x11f0) = 5;
        }
    }
}

// ---- GetBusyLocked.cpp ----
// 3 tiny functions sharing a byte flag at this->0x121f (busy/locked).
extern "C" {
u8 GetBusyLocked(void* thisPtr) { return *(u8*)((char*)thisPtr + 0x121f); }

void ClearBusyLocked(void* thisPtr) {
	char* p = (char*)thisPtr;
	if (*(u8*)(p + 0x121f) != 1) return;
	*(u8*)(p + 0x121f) = 0;
	if (*(s32*)(p + 0x11f0) >= 5) return;
	*(s32*)(p + 0x11f0) = 5;
}

void SetBusyLocked(void* thisPtr) { *(u8*)((char*)thisPtr + 0x121f) = 1; }
}

// ---- fn_8024B298.cpp ----
extern "C" void fn_8026942C(void* subObj, s32 idx, void* outStruct);

// fn_8024B298(playerObj, idx, outStruct) - trivial trampoline: swaps the
// receiver from playerObj to playerObj->0xbf0 (a sub-object) and
// tail-calls fn_8026942C(subObj, idx, outStruct) with the other two
// args forwarded unchanged.
extern "C" void fn_8024B298(char* playerObj, s32 idx, void* outStruct) {
    fn_8026942C(*(void**)(playerObj + 0xbf0), idx, outStruct);
}

// ---- fn_8024B2BC.cpp ----
extern "C" s32 fn_8026947C(void* subObj);

// fn_8024B2BC(playerObj) - trivial delegate: forwards playerObj's
// sub-object pointer at +0xbf0 into fn_8026947C and returns its result
// directly.
extern "C" s32 fn_8024B2BC(char* playerObj) {
    return fn_8026947C(*(void**)(playerObj + 0xbf0));
}

// ---- Player_GetField_0xce8.cpp ----
// Player_GetField_0xce8 - a trivial one-field accessor, part of fn_8022D534's
// two-stage "linked player" capability check (see
// [[project_fsa_player_target_helper_decoded]]). Just returns
// playerObj->0xce8 (a byte field, meaning not yet identified) directly -
// no further logic.
extern "C" {

u8 Player_GetField_0xce8(void* thisPtr) { return *(u8*)((char*)thisPtr + 0xce8); }

}

// ---- Fairy_SetField_0xd28.cpp ----
// Companion-fairy internal accumulator/accessor cluster. This slice:
// Fairy_SetField_0xd28: this->0xd28 = val (plain setter).
// Fairy_GetField_0x11b4Ptr: returns &this->0x11b4 (address of an embedded member).
// Fairy_SetSubField_0x29c/5C: this->0xbec (indirection) ->0x29c / ->0x298 = val
//   (setters through an owned sub-object pointer).
// Fairy_GetSubField_0x294/74: this->0xbec (same indirection) ->0x294 / ->0x290
//   (getters through the same sub-object).
extern "C" {

void Fairy_SetField_0xd28(void* thisPtr, u32 val) {
	*(u32*)((char*)thisPtr + 0xd28) = val;
}

void* Fairy_GetField_0x11b4Ptr(void* thisPtr) {
	return (char*)thisPtr + 0x11b4;
}

void Fairy_SetSubField_0x29c(void* thisPtr, u32 val) {
	void* sub = *(void**)((char*)thisPtr + 0xbec);
	*(u32*)((char*)sub + 0x29c) = val;
}

void Fairy_SetSubField_0x298(void* thisPtr, u32 val) {
	void* sub = *(void**)((char*)thisPtr + 0xbec);
	*(u32*)((char*)sub + 0x298) = val;
}

u32 Fairy_GetSubField_0x294(void* thisPtr) {
	void* sub = *(void**)((char*)thisPtr + 0xbec);
	return *(u32*)((char*)sub + 0x294);
}

u32 Fairy_GetSubField_0x290(void* thisPtr) {
	void* sub = *(void**)((char*)thisPtr + 0xbec);
	return *(u32*)((char*)sub + 0x290);
}

}

// ---- EmptyHook_80252FBC.cpp ----
// EmptyHook_80252FBC: empty stub (no-op virtual override).
extern "C" {

void EmptyHook_80252FBC(void) {}

}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
