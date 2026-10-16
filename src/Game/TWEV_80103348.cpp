// TWEV_80103348: .text 0x80103348-0x801042D0 (actor TWEV)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

// ---- from Game/fn_80103F28_dtor.cpp

extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern "C" void fn_801EE434(void* handle);
extern void* lbl_8049CA40[];

extern "C" void* fn_80103F28(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049CA40;
        char* p = (char*)this_;
        void* handle = *(void**)(p + 0x260);
        if (handle != 0) {
            fn_801EE434(handle);
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

extern "C" s32 fn_8013CC50(void* a, void* b, f32 scale, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h);
extern f32 lbl_8053C1D0;
extern f32 lbl_8053C1D8;
extern char lbl_80463BD0[];
extern "C" void fn_80103F9C(void* this_) {
    char* p = (char*)this_;
    *(s32*)(p + 0x230) = 0;
    *(s32*)(p + 0x234) = 0;
    *(s32*)(p + 0x260) = 0;
    *(u32*)(p + 0x234) = *(u32*)(p + 0x90) & 0xf;
    *(u32*)(p + 0x25c) = (*(u32*)(p + 0x90) >> 22) & 0x1f;
    switch (*(s32*)(p + 0x234)) {
    case 0: {
        f32 zero;
        *(s32*)(p + 0x288) = 0;
        zero = lbl_8053C1D0;
        *(s32*)(p + 0x264) = 0;
        *(s32*)(p + 0x268) = 0;
        *(s32*)(p + 0x26c) = 0;
        *(f32*)(p + 0x28c) = zero;
        *(f32*)(p + 0x290) = zero;
        *(f32*)(p + 0x294) = zero;
        *(f32*)(p + 0x238) = *(f32*)(p + 0xc);
        *(f32*)(p + 0x23c) = *(f32*)(p + 0x10);
        *(f32*)(p + 0x240) = *(f32*)(p + 0x14);
        *(f32*)(p + 0x244) = *(f32*)(p + 0xc);
        *(f32*)(p + 0x248) = *(f32*)(p + 0x10);
        *(f32*)(p + 0x24c) = *(f32*)(p + 0x14);
        *(f32*)(p + 0x250) = *(f32*)(p + 0xc);
        *(f32*)(p + 0x254) = *(f32*)(p + 0x10);
        *(f32*)(p + 0x258) = *(f32*)(p + 0x14);
        break;
    }
    case 2:
        *(s32*)(p + 0x260) = fn_8013CC50(*(void**)(p + 4), p + 0xc, lbl_8053C1D8, 0x496, 1, 0, 0, 0, 1);
        break;
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
