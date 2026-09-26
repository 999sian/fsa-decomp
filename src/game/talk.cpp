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
