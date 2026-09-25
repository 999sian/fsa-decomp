// TU 0x802ef76c-0x802f032c (actor FOEV).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- Ltev_SetupLightTransition.cpp ----
// Ltev_SetupLightTransition - LTEV: light-transition setup, vtable extension slot (0x9C).
// Two modes selected by whether the final param is 0: mode A (mode!=0)
// stores 5 incoming params as the "target" endpoint fields and computes
// per-component step counts; mode B (mode==0) stores the params as the
// "start" endpoint fields instead.
//
// Ltev_EmptyHook - LTEV: empty no-op override.
extern "C" {

void Ltev_SetupLightTransition(void* thisPtr, s32 p1, s32 p2, s32 p3, s32 p4, s32 p5, s32 mode) {
	char* p = (char*)thisPtr;
	*(s32*)(p + 0x230) = mode;
	if (mode == 0) {
		*(s32*)(p + 0x25c) = p1;
		*(s32*)(p + 0x260) = p2;
		*(s32*)(p + 0x264) = p3;
		*(s32*)(p + 0x258) = p4;
		*(s32*)(p + 0x26c) = p5;
		*(s32*)(p + 0x270) = (*(s32*)(p + 0x25c) - *(s32*)(p + 0x24c)) / 4;
		*(s32*)(p + 0x274) = (*(s32*)(p + 0x260) - *(s32*)(p + 0x250)) / 4;
		*(s32*)(p + 0x278) = (*(s32*)(p + 0x264) - *(s32*)(p + 0x254)) / 4;
		if (*(s32*)(p + 0x268) < *(s32*)(p + 0x26c)) {
			*(s32*)(p + 0x230) = 1;
		}
		return;
	}
	*(s32*)(p + 0x24c) = p1;
	*(s32*)(p + 0x250) = p2;
	*(s32*)(p + 0x254) = p3;
	*(s32*)(p + 0x258) = p4;
	*(s32*)(p + 0x268) = p5;
}

void Ltev_EmptyHook(void) {}

}

// ---- Ltev_dtor_802EFB9C.cpp ----
extern "C" void dtor_801F593C(void* this_, int how);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804AA4F0[];

extern "C" void* fn_802EFB9C(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804AA4F0;
        dtor_801F593C(this_, 0);
        if (how > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}
