// TU 0x802ec73c-0x802ecad4 (actor ZOMO).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- Zomo_dtor_802EC73C.cpp ----
extern "C" void dtor_801F593C(void* this_, int how);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804AA228[];

extern "C" void* fn_802EC73C(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804AA228;
        dtor_801F593C(this_, 0);
        if (how > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- Zomo_EmptyHook.cpp ----
// Zomo_EmptyHook - ZOMO: empty no-op override (0x4, leaf, no extab needed)
extern "C" {

void Zomo_EmptyHook(void) {}

}

// ---- Zomo_SetParams.cpp ----
#include "game/esd/Actor.h"

// ZOMO: setParams.
extern "C" {
void Zomo_SetParams(void* thisPtr) {
	char* p = (char*)thisPtr;
	u32 v = ((Actor*)thisPtr)->spawnParam;
	*(u32*)(p + 0x234) = v & 0xFFF;
	*(s32*)(p + 0x238) = 0;
	*(s32*)(p + 0x230) = 0;
}
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
