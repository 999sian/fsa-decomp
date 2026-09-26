// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 8016545C-80166BD0 (ARRW). Remaining functions are not yet decompiled.
#include "types.h"

// from src/Game/fn_801662D8_dtor.cpp
extern "C" void dtor_801F593C(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern void* lbl_804A05E0[];

extern "C" void* fn_801662D8(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A05E0;
        char* p = (char*)this_;
        for (s32 i = 0; i < 2; i++) {
            fn_801EE434(*(void**)(p + 0x278));
            p += 4;
        }
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" u8 fn_8022B160(void);
extern "C" s32 fn_8022F340(u32 params);
extern s32 lbl_804C6330[];

// ARRW init (vtable slot 1)
extern "C" void fn_80166814(char* this_) {
    *(u32*)(this_ + 0x98) = (*(u32*)(this_ + 0x90) >> 4) & 3;
    *(u16*)(this_ + 0x94) = (*(u32*)(this_ + 0x90) >> 8) & 0xf;
    *(u32*)(this_ + 0x90) = *(u32*)(this_ + 0x90) & 3;
    if (fn_8022B160()) {
        lbl_804C6330[fn_8022F340(*(u32*)(this_ + 0x90))]++;
    }
    *(s32*)(this_ + 0x278) = 0;
    *(s32*)(this_ + 0x27c) = 0;
    *(f32*)(this_ + 0x60) = -2.0f;
    *(f32*)(this_ + 0x64) = -2.0f;
    *(f32*)(this_ + 0x68) = 2.0f;
    *(f32*)(this_ + 0x6c) = 2.0f;
    *(f32*)(this_ + 0x80) = -2.0f;
    *(f32*)(this_ + 0x84) = -2.0f;
    *(f32*)(this_ + 0x88) = 2.0f;
    *(f32*)(this_ + 0x8c) = 2.0f;
    *(s32*)(this_ + 0x258) = 0;
    *(s32*)(this_ + 0x25c) = 0;
    *(s32*)(this_ + 0x260) = 0;
    *(s32*)(this_ + 0x264) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(s32*)(this_ + 0x254) = 0;
    switch (*(s32*)(this_ + 0x98)) {
    case 0:
        *(f32*)(this_ + 0x3c) = 5.0f;
        *(f32*)(this_ + 0x40) = 0.0f;
        *(f32*)(this_ + 0x44) = 0.0f;
        break;
    case 1:
        *(f32*)(this_ + 0x3c) = -5.0f;
        *(f32*)(this_ + 0x40) = 0.0f;
        *(f32*)(this_ + 0x44) = 0.0f;
        break;
    case 2:
        *(f32*)(this_ + 0x3c) = 0.0f;
        *(f32*)(this_ + 0x40) = 5.0f;
        *(f32*)(this_ + 0x44) = 0.0f;
        break;
    case 3:
        *(f32*)(this_ + 0x3c) = 0.0f;
        *(f32*)(this_ + 0x40) = -5.0f;
        *(f32*)(this_ + 0x44) = 0.0f;
        break;
    }
    *(f32*)(this_ + 0x234) = 255.0f;
    *(s32*)(this_ + 0x24c) = 500;
    *(u8*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x26c) = 0;
    *(s32*)(this_ + 0x270) = 0;
    *(s32*)(this_ + 0x108) = 10000;
    *(s32*)(this_ + 0x268) = *(s32*)(this_ + 0x98);
    *(s32*)(this_ + 0x230) = 0;
    *(u8*)(this_ + 0x274) = 0;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
