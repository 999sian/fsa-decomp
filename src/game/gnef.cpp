// TU 0x802ed538-0x802eec50 (actor GNEF).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- Gnef_CueHelpers_802ED7D8.cpp ----
// Gnef_SetCueFlag - GNEF: cue-flag setter. Sets flag byte this->0x275=0xff
// and increments counter this->0x24c.
//
// Gnef_QueryCueState - GNEF: cue-state query. If this->0x24c < 0xb (11),
// returns 0. Otherwise checks/sets a latch byte at this->0x274 based
// on the incoming float param vs this->0x270 or a fixed threshold
// constant, returning the latch value.
extern "C" {

extern f32 lbl_80541400;

void Gnef_SetCueFlag(void* thisObj) {
	*(u8*)((char*)thisObj + 0x275) = 0xff;
	*(u32*)((char*)thisObj + 0x24c) += 1;
}

u8 Gnef_QueryCueState(void* thisObj, f32 value) {
	if (*(s32*)((char*)thisObj + 0x24c) < 0xb) {
		return 0;
	}
	if (*(u8*)((char*)thisObj + 0x274) != 0) {
		*(f32*)((char*)thisObj + 0x270) = value;
	} else {
		if (lbl_80541400 == value) {
			*(u8*)((char*)thisObj + 0x274) = 1;
		}
	}
	return *(u8*)((char*)thisObj + 0x274);
}

}

// ---- Gnef_dtor_802EE630.cpp ----
extern "C" void fn_801EE434(void* handle);
extern "C" void dtor_801F593C(void* this_, int how);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804AA350[];

extern "C" void* fn_802EE630(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804AA350;
        void* h0 = *(void**)((char*)this_ + 0x230);
        if (h0) {
            fn_801EE434(h0);
        }
        void* h1 = *(void**)((char*)this_ + 0x234);
        if (h1) {
            fn_801EE434(h1);
        }
        void* h2 = *(void**)((char*)this_ + 0x238);
        if (h2) {
            fn_801EE434(h2);
        }
        void* h3 = *(void**)((char*)this_ + 0x23c);
        if (h3) {
            fn_801EE434(h3);
        }
        void* h4 = *(void**)((char*)this_ + 0x240);
        if (h4) {
            fn_801EE434(h4);
        }
        void* h5 = *(void**)((char*)this_ + 0x244);
        if (h5) {
            fn_801EE434(h5);
        }
        void* h6 = *(void**)((char*)this_ + 0x248);
        if (h6) {
            fn_801EE434(h6);
        }
        dtor_801F593C(this_, 0);
        if (how > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
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
#undef MACROS_H
#undef MAX
#undef MIN
#undef NULL
#define NULL 0
#define unknown jsys_unknown
#include "JSystem/JAudio/JASFakeMatchFSA.h"
