// TU 0x803a8dfc-0x803b7dcc.
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"

// ---- from src/Game/CountdownBlink_803AF604.cpp ----
extern "C" void fn_80458880(void* p1, s32 p2, s32 p3);
extern "C" void fn_803B35F8(void* this_, u8 flag);

extern void* lbl_8053AF80;

extern "C" void fn_803AF604(void* this_) {
    char* t = (char*)this_;
    s32 v = *(s32*)(t + 0x440) - 1;
    *(s32*)(t + 0x440) = v;
    v = *(s32*)(t + 0x440);

    if (v > 10) {
        if (v > 0xb4) {
            if (v % 2 == 0) {
                u8 c = *(u8*)(t + 0x4c7);
                *(u8*)(t + 0x4c7) = c + 1;
                fn_80458880(lbl_8053AF80, 0x20, -1);
            }
        } else if (v > 0x78) {
            if (v % 3 == 0) {
                u8 c = *(u8*)(t + 0x4c7);
                *(u8*)(t + 0x4c7) = c + 1;
                fn_80458880(lbl_8053AF80, 0x20, -1);
            }
        } else if (v > 0x3c) {
            if (v % 4 == 0) {
                u8 c = *(u8*)(t + 0x4c7);
                *(u8*)(t + 0x4c7) = c + 1;
                fn_80458880(lbl_8053AF80, 0x20, -1);
            }
        } else {
            if (v % 5 == 0) {
                u8 c = *(u8*)(t + 0x4c7);
                *(u8*)(t + 0x4c7) = c + 1;
                fn_80458880(lbl_8053AF80, 0x20, -1);
            }
        }
    } else {
        if (v == 10) {
            fn_80458880(lbl_8053AF80, 0x21, -1);
        }
    }

    if (*(u8*)(t + 0x4c7) >= 9) {
        *(u8*)(t + 0x4c7) = 0;
    }

    if (*(s32*)(t + 0x440) == 0) {
        u8 flagArg = *(u8*)(t + 0x4c7);
        fn_803B35F8(this_, flagArg);
        *(s32*)(t + 0x440) = 0x96;
        *(u8*)(t + 0x4c1) = 0xd;
    }
}

// ---- from src/Game/InvalidateFourFields.cpp ----
// fn_803B7B90 - trailing tiny helper (0x18), closes out the whole actor cluster
extern "C" {

void fn_803B7B90(void* thisPtr) {
	s32* p = (s32*)thisPtr;
	p[0] = -1;
	p[1] = -1;
	p[2] = -1;
	p[3] = -1;
}

}
