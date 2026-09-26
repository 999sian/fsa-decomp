// TU 0x80394134-0x803944c8 (actor TALK).
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"

// ---- from src/Game/fn_80394134_dtor.cpp ----
extern "C" void dtor_801F593C(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804AF548[];

extern "C" void* fn_80394134(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AF548;
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// ---- from src/Game/Talk_EmptyHook.cpp ----
// fn_80394194 - TALK: empty no-op override (0x4, leaf, no extab needed)
extern "C" {

void fn_80394194(void) {}

}


// ---- fn_80394198: TALK update ----
#include "JSystem/JGeometry/Vec.h"
extern "C" u8 fn_8038AD24(u32 a, u32 b, u32 c, u32 d, JGeometry::TVec3<f32>* pos, u32 flags);
extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802DCD0C(void* mgr);
extern "C" u8 fn_80384C58(u32 a, u32 b);

extern "C" void fn_80394198(void* thisPtr) {
	char* p = (char*)thisPtr;
	u32 flags = *(u32*)(p + 0x90);
	u32 hi = flags >> 28;
	u32 lo = flags & 0x0FFFFFFF;
	switch (*(s32*)(p + 0x230)) {
	case 0: {
		u32 id = *(u32*)(p + 0x4);
		JGeometry::TVec3<f32> pos(*(Vec*)(p + 0xc));
		if (fn_8038AD24(hi, lo, *(u32*)(p + 0x234), id, &pos, 0x1004)) {
			*(s32*)(p + 0x230) = 1;
		} else {
			*(u8*)(p + 0x11c) = 0;
		}
		break;
	}
	case 1:
		*(s16*)(p + 0x238) = *(s16*)(p + 0x238) - 1;
		if (*(s16*)(p + 0x238) > 0) {
			if (!fn_802DCD0C(fn_802D6A9C())) {
				break;
			}
		}
		if (fn_80384C58(hi, *(u32*)(p + 0x234))) {
			*(u8*)(p + 0x11c) = 0;
		}
		break;
	}
}

// ---- from src/Game/Talk_SetParams.cpp ----
// TALK: setParams.
extern "C" {
void fn_8039427C(void* thisPtr) {
	char* p = (char*)thisPtr;
	*(s32*)(p + 0x230) = 0;
	*(u16*)(p + 0x238) = 0x78;
	*(u32*)(p + 0x234) = *(u32*)(p + 0x198);
	*(u8*)(p + 0x11f) = 1;
	*(u8*)(p + 0x11e) = 1;
}
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
