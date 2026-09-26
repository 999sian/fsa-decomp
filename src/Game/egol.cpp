// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 801AFB38-801B0A00 (EGOL). Remaining functions are not yet decompiled.
#include "types.h"

// from src/Game/fn_801AFB38_dtor.cpp
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A3548[];

extern "C" void* fn_801AFB38(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A3548;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

struct EgolRandom {
    u32 seed;
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - 1.0f;
    }
};
struct EgolGame { u8 pad[0xb4]; EgolRandom rnd; };
extern EgolGame* lbl_8053AAF8;

extern "C" void fn_801B0654(char* this_) {
    if (*(s32*)(this_ + 0x254) == *(s32*)(this_ + 0x108)) {
        return;
    }
    *(s32*)(this_ + 0x254) = *(s32*)(this_ + 0x108);
    if (*(s32*)(this_ + 0x258) > 0) {
        (*(s32*)(this_ + 0x258))--;
    }
    if (*(s32*)(this_ + 0x258) <= 0) {
        *(u32*)(this_ + 0xb0) = 0;
    }
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x250) = *(s32*)(this_ + 0x98) + 0x10;
    *(s32*)(this_ + 0x23c) = (s32)(60.0f * lbl_8053AAF8->rnd.get_ufloat_1()) + 0x3c;
    *(s32*)(this_ + 0x230) = 0;
}

// EGOL init (vtable slot 1)
extern "C" void fn_801B0710(char* this_) {
    *(f32*)(this_ + 0x60) = -12.0f;
    *(f32*)(this_ + 0x64) = -22.0f;
    *(f32*)(this_ + 0x68) = 12.0f;
    *(f32*)(this_ + 0x6c) = 2.0f;
    *(f32*)(this_ + 0x80) = -12.0f;
    *(f32*)(this_ + 0x84) = -22.0f;
    *(f32*)(this_ + 0x88) = 12.0f;
    *(f32*)(this_ + 0x8c) = 8.0f;
    *(f32*)(this_ + 0x70) = -16.0f;
    *(f32*)(this_ + 0x74) = -24.0f;
    *(f32*)(this_ + 0x78) = 16.0f;
    *(f32*)(this_ + 0x7c) = 6.0f;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0xb8) = 1;
    *(s32*)(this_ + 0x98) = 2;
    *(s32*)(this_ + 0x250) = 0x12;
    *(s32*)(this_ + 0xbc) = 4;
    *(f32*)(this_ + 0x264) = 0.0f;
    *(f32*)(this_ + 0x260) = 0.0f;
    *(f32*)(this_ + 0x25c) = 0.0f;
    *(f32*)(this_ + 0x44) = 0.0f;
    *(f32*)(this_ + 0x40) = 0.0f;
    *(f32*)(this_ + 0x3c) = 0.0f;
    *(s32*)(this_ + 0x108) = 0x3ef;
    *(s32*)(this_ + 0x258) = 2;
    *(s32*)(this_ + 0x254) = *(s32*)(this_ + 0x108);
    *(s32*)(this_ + 0x230) = 0;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
