// TU 0x80212ac0-0x80212e3c.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"
#include "JSystem/JGeometry.h"

struct RusaRegistry {
	RusaRegistry() { mCount = 0; }
	s32 mIds[32];
	s32 mCount;
};

extern "C" {
void* fn_801F856C();
void* fn_801F666C(void* mgr, s32 id);
bool fn_80211000(void* actor, JGeometry::TVec3<f32>* pos);
void fn_80210E90(void* actor, JGeometry::TVec3<f32>* pos, JGeometry::TVec3<f32>* out);

RusaRegistry* fn_80212AC0() {
	static RusaRegistry sInstance;
	return &sInstance;
}

// NonMatching: only the prologue scheduling differs (retail copies i from found's zero).
void fn_80212AF0(RusaRegistry* reg, JGeometry::TVec3<f32>* pos) {
	s32 n = reg->mCount;
	s32 i = 0;
	void* found = NULL;
	void* actor;
	for (s32* ids = reg->mIds; i < n; ids++, i++) {
		actor = fn_801F666C(fn_801F856C(), *ids);
		if (actor != NULL && fn_80211000(actor, pos)) {
			found = actor;
			break;
		}
	}
	if (found != NULL) {
		JGeometry::TVec3<f32> d;
		fn_80210E90(found, pos, &d);
		*pos += d;
	}
}
}

// ---- RusaRegistry_Unregister_80212BA0.cpp ----
// RusaRegistry_Unregister/RusaRegistry_Unregister - UNREGISTER for the "active
// RUSA instances" registry `lbl_804CCDB8` (see
// project_fsa_rusa_actor_progress.md and the registry's lazy-init
// accessor in extab_80212ac0.s), following the same idiom already
// confirmed for NAVI's companion registry (project_fsa_navi_companion_registry.md).
//
// RusaRegistry_Unregister(registry, id) - UNREGISTER: scans the inline ID array at
// `registry+0x0` for `id` (count from `registry->0x80`); once found,
// compacts the array by shifting all later entries back one slot, then
// decrements the count.
//
// Cracked via 2 refinements over the earlier 2 failed attempts (see
// project_fsa_phase4_kickoff.md): (1) the loop bound must be a fresh
// re-read of `registry->0x80` in the `for` condition itself, not a
// locally-cached value - caching it made MWCC choose a counted
// mtctr/bdnz loop instead of retail's manual compare-and-branch loop.
// (2) declaring the pointer-walking local BEFORE the boolean flag
// local (and incrementing the pointer before the loop counter in the
// `for` increment clause) matches retail's register assignment
// exactly - reversing either swaps 2 register numbers project-wide
// in this function, a real (if narrow) case of source declaration
// order controlling MWCC's register allocation, unlike the similar-
// looking but genuinely unresolvable case in fn_803D6618.
extern "C" void RusaRegistry_Unregister(void* registry, s32 id) {
	s32* ptr = (s32*)registry;
	bool found = false;
	for (s32 i = 0; i < *(s32*)((char*)registry + 0x80); ptr++, i++) {
		if (!found) {
			if (id == *ptr) { found = true; }
		} else {
			*(ptr - 1) = *ptr;
		}
	}
	if (found) {
		*(s32*)((char*)registry + 0x80) -= 1;
	}
}

// ---- RusaRegistry_Register.cpp ----
// RusaRegistry_Register(registry, id) - REGISTER half of the "active RUSA
// instances" registry - push-back `id` at `registry + count*4`, then
// increments the count at `registry->0x80`. Same idiom already
// confirmed for NAVI's companion registry (GrowableArray_PushBack). The
// UNREGISTER half, RusaRegistry_Unregister, contains a real remove-and-shift loop
// and stays raw asm in Dolphin/os/extab_80212ba0.s.
extern "C" {

void RusaRegistry_Register(void* registryPtr, s32 id) {
	char* p = (char*)registryPtr;
	u32 count = *(u32*)(p + 0x80);
	*(s32*)(p + count * 4) = id;
	u32 count2 = *(u32*)(p + 0x80);
	*(u32*)(p + 0x80) = count2 + 1;
}

}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
