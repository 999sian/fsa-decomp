// TU 0x803b8970-0x803b8c74 (actor TLK2).
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"

// ---- from src/Game/fn_803B8970_dtor.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804AFAD8[];

extern "C" void* fn_803B8970(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AFAD8;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// ---- from src/Game/Tlk2_EmptyHook1.cpp ----
// fn_803B89D0/fn_803B89D4 - TLK2: 2 empty no-op overrides (0x4 each)
extern "C" {

void fn_803B89D0(void) {}

void fn_803B89D4(void) {}

}

// ---- fn_803B89D8: TLK2 setup ----
#include "JSystem/JUtility/TColor.h"
extern "C" void fn_8037F2FC(u32 a, u32 b, u8 c, JUtility::TColor color, f32 x, f32 y, f32 z, f32 w);

extern "C" void fn_803B89D8(void* thisPtr) {
	char* p = (char*)thisPtr;
	*(u32*)(p + 0x234) = *(u32*)(p + 0x90) & 0xFFFF;
	*(u8*)(p + 0x23c) = *(u32*)(p + 0x90) >> 28;
	*(u32*)(p + 0x238) = (*(u32*)(p + 0x90) >> 16) & 0xFFF;
	fn_8037F2FC(*(u32*)(p + 0x234), *(u32*)(p + 0x238), *(u8*)(p + 0x23c), JUtility::TColor(0xFF0000FF),
	            *(f32*)(p + 0xc), *(f32*)(p + 0x10), *(f32*)(p + 0x14), *(f32*)(p + 0x14));
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
