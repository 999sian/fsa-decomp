// Game TU 801B27DC-801B3F60 (unnamed). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"

extern "C" u16 fn_8022461C(void* pos);
extern "C" u16 fn_80226850(void* pos, s32 room);
extern "C" u8* fn_802D6A9C(void);

extern "C" u8 fn_801B27DC(void* this_, s32 room, void* pos) {
    s32 kind = fn_8022461C(pos);
    s32 attr = fn_80226850(pos, room);
    if ((u32)(attr - 0x230) <= 1 || attr == 0x234) {
        return 0;
    }
    if (kind != 0 && kind != 4 && kind != 5 && kind != 6 && kind != 7 && kind != 2 && kind != 3 && kind != 0x50 && kind != 0xE && kind != 0xC && kind != 0x27 && kind != 0x28 && kind != 0x29 && kind != 0x2A && kind != 0x2B && kind != 0x2C && kind != 0x2D && kind != 0x2E && kind != 0x2F && kind != 0x20 && kind != 0xD && kind != 0x39 && kind != 0x3A && kind != 0x3B && kind != 0x4C && kind != 0x4D && kind != 0x4E && kind != 0x4F && kind != 0x24) {
        if (kind == 0x25) {
            return fn_802D6A9C()[0x171] == 0;
        }
        if (kind == 0x26) {
            return fn_802D6A9C()[0x171] == 1;
        }
        if (kind != 0x22 || fn_802D6A9C()[0x170] == 1) {
            return 1;
        }
    }
    return 0;
}

extern "C" void fn_801F06F0(void* this_, const char* name, s32 idx, s32 a, s32 b, f32 x, f32 y);
extern const char lbl_804690E0[];

extern "C" void fn_801B2998(u8* this_) {
    s32 f = *(s32*)(this_ + 0x308);
    if (f != 0 && (f & 2)) {
        fn_801F06F0(this_, lbl_804690E0, *(s32*)(this_ + 0x320) + 0x9B, 0, 7, 1.0f, 1.0f);
    }
}

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A3698[];
extern u8 lbl_8053ABE8;
extern u8 lbl_8053ABF0;

extern "C" void* fn_801B3CD0(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A3698;
        lbl_8053ABE8 = 0;
        lbl_8053ABF0 = 0;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
