// TU 0x802e6ec4-0x802e72a4.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- fn_802E6EC4_dtor.cpp ----
extern "C" void dtor_801F593C(void* this_, int flag);
extern void* lbl_804A9E50[];

extern "C" void* fn_802E6EC4(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A9E50;
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

// fn_802E6F24 - draw(): spawns effect 0x26d + this->0x238 at the actor's
// position via fn_803075AC; the "visible" arg is this->0x234 != 0.
extern "C" void fn_803075AC(u32 callerID, u32 ownerID, void* posPtr, s32 effectRef,
                            bool flag, s32 mode, s32 targetPlayerIdx, s32 kind,
                            s32 stackArg9, s32 stackArg10);

extern "C" void fn_802E6F24(void* this_) {
    int on = 0;
    if (*(s32*)((char*)this_ + 0x234) != 0) {
        on = 1;
    }
    fn_803075AC(*(u32*)((char*)this_ + 0x198), *(u32*)((char*)this_ + 0x4),
                (char*)this_ + 0xc, *(s32*)((char*)this_ + 0x238) + 0x26d,
                on, 2, -1, 1, 0, 0);
}

// ---- stub_802e6f94.cpp ----
#include "game/esd/Actor.h"

// fn_802E6F94 - unnamed actor: update(). Decrements a timer
// (this->0x240); once it reaches 0, resets it to 2 and drives a small
// state machine: while this->0x230==0, advances 2 counters
// (0x238/0x23c, the first capped at 6) until 0x23c reaches 8, then
// clears this->0x11c; otherwise cycles this->0x238 through
// 0->2->6->(clear this->0x11c).
extern "C" void fn_802E6F94(void* thisObj) {
	*(s32*)((char*)thisObj + 0x240) -= 1;
	if (*(s32*)((char*)thisObj + 0x240) != 0) {
		return;
	}
	*(s32*)((char*)thisObj + 0x240) = 2;
	if (*(s32*)((char*)thisObj + 0x230) == 0) {
		*(s32*)((char*)thisObj + 0x238) += 1;
		*(s32*)((char*)thisObj + 0x23c) += 1;
		if (*(s32*)((char*)thisObj + 0x238) > 6) {
			*(s32*)((char*)thisObj + 0x238) = 5;
		}
		if (*(s32*)((char*)thisObj + 0x23c) != 8) {
			return;
		}
		*(u8*)((char*)thisObj + 0x11c) = 0;
		return;
	} else {
		if (*(s32*)((char*)thisObj + 0x238) == 0) {
			*(s32*)((char*)thisObj + 0x238) = 2;
			return;
		}
		if (*(s32*)((char*)thisObj + 0x238) == 2) {
			*(s32*)((char*)thisObj + 0x238) = 6;
			return;
		}
		*(u8*)((char*)thisObj + 0x11c) = 0;
		return;
	}
}

// fn_802E7038 - unnamed actor: setParams(). Extracts a 7-bit field
// from the spawn param into this->0x230 and a further 5-bit field into
// this->0x234, resets 2 counters, and sets the initial timer
// (this->0x240) to 1 or 2 depending on whether this->0x230 is 0.
extern "C" void fn_802E7038(void* thisObj) {
	*(u32*)((char*)thisObj + 0x230) = ((Actor*)thisObj)->spawnParam & 0x7f;
	*(u32*)((char*)thisObj + 0x234) = (((Actor*)thisObj)->spawnParam >> 7) & 0x1f;
	*(s32*)((char*)thisObj + 0x238) = 0;
	*(s32*)((char*)thisObj + 0x23c) = 0;
	if (*(s32*)((char*)thisObj + 0x230) == 0) {
		*(s32*)((char*)thisObj + 0x240) = 1;
	} else {
		*(s32*)((char*)thisObj + 0x240) = 2;
	}
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
