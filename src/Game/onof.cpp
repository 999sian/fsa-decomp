// TU 0x802cb1c4-0x802cc1c4 (actor ONOF).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// fn_802CB1C4 - ONOF: draw a shadow/marker while in state 1 or 2.
// NONMATCHING (79.8%): retail shares the zero register (r7) between the
// colour bytes and the flag argument.
struct OnofColor {
    u8 r, g, b, a;
    OnofColor(u8 r_, u8 g_, u8 b_, u8 a_) { r = r_; g = g_; b = b_; a = a_; }
};
extern const f32 lbl_80540DA8;
extern char* lbl_8053AB10;
struct OnofShadowMgr {
    void draw(u32 room, void* pos, OnofColor color, s32 flag, f32 scale);
};
extern "C" void fn_802CB1C4(char* p) {
    s32 st = *(s32*)(p + 0x238);
    if (st == 2 || st == 1) {
        OnofColor c(0, 0, 0, 0x80);
        (*(OnofShadowMgr**)(lbl_8053AB10 + 0x2c))->draw(*(u32*)(p + 0x4), p + 0xc, c, 0, lbl_80540DA8);
    }
}

// ---- fn_802CBA78_dtor.cpp ----
extern "C" void* fn_801EE434(void* handle);
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804A8FC8[];

extern "C" void* fn_802CBA78(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A8FC8;
        if (*(void**)(p + 0x230) != 0) {
            fn_801EE434(*(void**)(p + 0x230));
        }
        if (*(void**)(p + 0x234) != 0) {
            fn_801EE434(*(void**)(p + 0x234));
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
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
