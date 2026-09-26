// TU 0x802e9428-0x802eb21c (actor ENDM).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// ---- Endm_dtor_802E9428.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804AA0FC[];

extern "C" void* fn_802E9428(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804AA0FC;
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- Endm_EmptyHook.cpp ----
// Endm_EmptyHook - ENDM: empty no-op override (0x4, leaf, no extab needed)
extern "C" {

void Endm_EmptyHook(void) {}

}

// fn_802E948C - ENDM: start a move towards target over n frames; returns 0
// (int->float constant 0x805412F0 is compiler-generated: the TU must own its
// .sdata2 before it can link.)
// when already there.
extern "C" u8 fn_802E948C(char* p, f32 target, s32 frames) {
    f32 cur = *(f32*)(p + 0x270);
    if (cur == target) {
        return 0;
    }
    f32 step = __fabsf(cur - target) / (f32)frames;
    if (cur < target) {
        *(f32*)(p + 0x278) = step;
    } else {
        *(f32*)(p + 0x278) = -step;
    }
    *(f32*)(p + 0x274) = target;
    return 1;
}

extern "C" void* fn_802D6A9C(void);
// fn_802E9884 - ENDM: screen-edge check of the scroll position.
extern "C" void fn_802D9CB0(void* rec);
extern "C" u8 fn_802E9884(char* p, f32* pos) {
    s32 ym = (s32)pos[1] % 384;
    s32 xm = (s32)pos[0] % 512;
    ym -= 30;
    if (*(u8*)(p + 0x297) == 0) {
        u8 d = **(u8**)(p + 0x290);
        if (d == 0xff) {
            *(s32*)(p + 0x23c) = 7;
            return 0;
        }
        switch (d) {
        case 0:
            if (ym - ((s32)*(f32*)(p + 0x270) * 3 / 4) / 2 < 0x10) {
                return 1;
            }
            break;
        case 1:
            if (ym + ((s32)*(f32*)(p + 0x270) * 3 / 4) / 2 > 0x170) {
                return 1;
            }
            break;
        case 2:
            if (xm - (s32)*(f32*)(p + 0x270) / 2 < 0x10) {
                return 1;
            }
            break;
        case 3:
            if (xm + (s32)*(f32*)(p + 0x270) / 2 > 0x1f0) {
                return 1;
            }
            break;
        }
    } else {
        s32 v;
        switch (*(u8*)(p + 0x28d)) {
        case 0:
            v = ym + ((s32)*(f32*)(p + 0x270) * 3 / 4) / 2;
            if (v < 0x170 && v > 0x160) {
                *(u8*)(p + 0x297) = 0;
            }
            break;
        case 1:
            v = ym - ((s32)*(f32*)(p + 0x270) * 3 / 4) / 2;
            if (v > 0x20 && v < 0x30) {
                *(u8*)(p + 0x297) = 0;
            }
            break;
        case 2:
            v = xm + (s32)*(f32*)(p + 0x270) / 2;
            if (v < 0x1f0 && v > 0x1e0) {
                *(u8*)(p + 0x297) = 0;
            }
            break;
        case 3:
            v = xm - (s32)*(f32*)(p + 0x270) / 2;
            if (v > 0x10 && v < 0x20) {
                *(u8*)(p + 0x297) = 0;
            }
            break;
        }
        if (*(u8*)(p + 0x297) == 0) {
            fn_802D9CB0(fn_802D6A9C());
        }
    }
    return 0;
}

// fn_802EACC8 - ENDM: setParams().
extern "C" void* fn_802D6A9C(void);
extern const f32 lbl_80541318;
extern const f32 lbl_805412EC;
extern void* lbl_8053AF80;
extern void* lbl_8053AF30;
extern "C" void fn_80458FF0(void* obj, u32 id, s32 a, s32 b);
extern "C" u8 fn_8044B80C(void* obj, u8 v);
extern "C" void fn_802EACC8(char* p) {
    *(s32*)(p + 0x284) = *(s32*)((char*)fn_802D6A9C() + 0x4);
    *(s32*)(p + 0x280) = *(s32*)((char*)fn_802D6A9C() + 0x8);
    *(s32*)(p + 0x23c) = 0;
    *(u8*)(p + 0x230) = 0;
    *(u8*)(p + 0x28d) = 0;
    *(u8*)(p + 0x298) = 0;
    *(s32*)(p + 0x240) = 0;
    *(u8*)(p + 0x294) = 0;
    *(u8*)(p + 0x295) = 0;
    *(u8*)(p + 0x299) = 1;
    *(f32*)(p + 0x270) = lbl_80541318;
    *(f32*)(p + 0x274) = lbl_80541318;
    *(f32*)(p + 0x278) = lbl_805412EC;
    fn_80458FF0(lbl_8053AF80, 0x1000028, 1, 0);
    *(s32*)(p + 0x234) = 0;
    *(u8*)(p + 0x231) = 0;
    *(u8*)(p + 0x29a) = fn_8044B80C(lbl_8053AF30, *(u8*)(p + 0x294));
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
