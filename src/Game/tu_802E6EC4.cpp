// TU 0x802e6ec4-0x802e72a4.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// ---- fn_802E6EC4_dtor.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A9E50[];

extern "C" void* fn_802E6EC4(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A9E50;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- fn_802E6F24 ----
extern "C" void fn_803075AC(u32 callerID, u32 ownerID, void* posPtr, s32 effectRef,
                             s32 unused, s32 mode, s32 targetPlayerIdx, s32 kind,
                             s32 stackArg9, s32 stackArg10);

extern "C" void fn_802E6F24(char* p) {
    s32 f = 0;
    if (*(s32*)(p + 0x234) != 0) {
        f = 1;
    }
    fn_803075AC(*(u32*)(p + 0x198), *(u32*)(p + 0x4), p + 0xc, *(s32*)(p + 0x238) + 0x26d,
                f != 0, 2, -1, 1, 0, 0);
}

// ---- stub_802e6f94.cpp ----
#include "Game/esd/Actor.h"

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

#include "JSystem/JAudio/JASFakeMatchFSA.h"
