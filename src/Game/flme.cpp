// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 8015DE10-8015F454 (FLME). Remaining functions are not yet decompiled.
#include "types.h"

// from src/Game/fn_8015F19C_dtor.cpp
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern void* lbl_804A0330[];

extern "C" void* fn_8015F19C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A0330;
        char* p = (char*)this_;
        for (s32 i = 0; i < 4; i++) {
            fn_801EE434(*(void**)(p + 0x264));
            p += 4;
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_8015EA2C(void* this_);
extern "C" void fn_8015DF7C(void* this_);

struct FlmeTimers { u8 pad[0x234]; s32 t[3]; };
// FLME update (vtable slot 3)
extern "C" void fn_8015DEFC(char* this_) {
    fn_8015EA2C(this_);
    if (*(s32*)(this_ + 0x230) != 5) {
        fn_8015DF7C(this_);
    }
    for (int i = 0; i < 3; i++) {
        if (((FlmeTimers*)this_)->t[i] > 0) {
            ((FlmeTimers*)this_)->t[i]--;
        }
    }
}

struct FlmeColor {
    FlmeColor(u8 r_, u8 g_, u8 b_, u8 a_) { r = r_; g = g_; b = b_; a = a_; }
    u8 r, g, b, a;
};
extern "C" void fn_80158B5C(void* mgr, u32 id, void* pos, FlmeColor col, f32 radius);
extern void** lbl_8053AB10;

static inline void flmeLight(char* this_, f32 r) {
    u32 id = *(u32*)(this_ + 0x4);
    fn_80158B5C(lbl_8053AB10[0xb], id, this_ + 0xc, FlmeColor(0, 0, 0, 0x80), r);
}

// FLME light source
extern "C" void fn_8015DE10(char* this_) {
    if (*(s32*)(this_ + 0x254) == 0 && *(u16*)(this_ + 0x94) != 4 && *(u16*)(this_ + 0x94) != 5) {
        flmeLight(this_, 60.0f);
    }
    if (*(s32*)(this_ + 0x240) != 0) {
        u16 t = *(u16*)(this_ + 0x94);
        if (t == 4 || t == 5) {
            f32 r = 46.2f;
            if (t == 5) {
                r = 140.0f;
            }
            flmeLight(this_, r);
        }
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
