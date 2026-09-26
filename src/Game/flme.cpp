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

extern const f32 lbl_8053D5EC;
extern const f32 lbl_8053D59C;
extern const f32 lbl_8053D5A0;
extern const f32 lbl_8053D5F0;
extern const f32 lbl_8053D5F4;
extern const f32 lbl_8053D618;
extern const f32 lbl_8053D61C;
extern const f32 lbl_8053D620;
extern "C" s32 fn_8013CC50(s32 room, void* pos, f32 scale, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);

extern "C" void fn_8015EDF4(char* p) {
    *(s32*)(p + 0x240) = 0;
    *(s32*)(p + 0x244) = 0;
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x234) = 0;
    *(s32*)(p + 0x238) = 0;
    *(s32*)(p + 0x23c) = 0;
    *(s32*)(p + 0x264) = 0;
    *(s32*)(p + 0x268) = 0;
    *(s32*)(p + 0x26c) = 0;
    *(s32*)(p + 0x270) = 0;
    *(s32*)(p + 0x254) = 0;
    *(f32*)(p + 0x3c) = lbl_8053D5EC;
    *(f32*)(p + 0x40) = lbl_8053D5EC;
    *(f32*)(p + 0x44) = lbl_8053D5EC;
    *(s32*)(p + 0x118) = 4;
    *(s32*)(p + 0x258) = (*(u32*)(p + 0x90) >> 18) & 3;
    *(s32*)(p + 0x25c) = (*(u32*)(p + 0x90) >> 20) & 1;
    if ((*(u32*)(p + 0x90) & 0xff00) == 0) {
        *(u16*)(p + 0x94) = *(u32*)(p + 0x90) & 0xff;
        *(s32*)(p + 0x98) = (*(u32*)(p + 0x90) >> 16) & 3;
        if (*(u16*)(p + 0x94) == 4 || *(u16*)(p + 0x94) == 5) {
            *(s32*)(p + 0x98) = 3;
        } else {
            *(s32*)(p + 0x114) = 4;
        }
        *(f32*)(p + 0x260) = lbl_8053D5EC;
        if (*(u16*)(p + 0x94) >= 9) {
            *(u16*)(p + 0x94) = 0;
        }
        switch (*(u16*)(p + 0x94)) {
        case 4:
        case 5:
            if (*(u16*)(p + 0x94) == 5) {
                *(f32*)(p + 0x260) = lbl_8053D59C;
            } else {
                *(f32*)(p + 0x260) = lbl_8053D5A0;
            }
            *(s32*)(p + 0x270) = fn_8013CC50(*(s32*)(p + 0x4), p + 0xc, *(f32*)(p + 0x260), 0x3e, 0, -1, 0, 0, 1);
            *(s32*)(p + 0x264) = fn_8013CC50(*(s32*)(p + 0x4), p + 0xc, *(f32*)(p + 0x260), 0x3b, 0, -1, 0, 0, 1);
            *(s32*)(p + 0x268) = fn_8013CC50(*(s32*)(p + 0x4), p + 0xc, *(f32*)(p + 0x260), 0x3c, 1, 1, 0, 0, 1);
            *(s32*)(p + 0x26c) = fn_8013CC50(*(s32*)(p + 0x4), p + 0xc, *(f32*)(p + 0x260), 0x3d, 1, 1, 0, 0, 1);
            *(s32*)(p + 0x240) = 1;
            *(s32*)(p + 0x234) = 8;
            *(s32*)(p + 0x230) = 0;
            break;
        case 0:
        case 6:
            *(f32*)(p + 0x260) = lbl_8053D59C;
            *(s32*)(p + 0x240) = 1;
            *(s32*)(p + 0x234) = 8;
            *(s32*)(p + 0x230) = 0;
            break;
        case 1:
            *(s32*)(p + 0x230) = 1;
            break;
        case 2:
            *(s32*)(p + 0x230) = 2;
            break;
        case 3:
            *(s32*)(p + 0x230) = 3;
            break;
        }
        switch (*(s32*)(p + 0x98)) {
        case 0:
            *(f32*)(p + 0x3c) = lbl_8053D5F4;
            *(f32*)(p + 0x40) = lbl_8053D5F0;
            *(f32*)(p + 0x44) = lbl_8053D5EC;
            break;
        case 1:
            *(f32*)(p + 0x3c) = lbl_8053D618;
            *(f32*)(p + 0x40) = lbl_8053D5F0;
            *(f32*)(p + 0x44) = lbl_8053D5EC;
            break;
        case 2:
            *(f32*)(p + 0x3c) = lbl_8053D5EC;
            *(f32*)(p + 0x40) = lbl_8053D5F4;
            *(f32*)(p + 0x44) = lbl_8053D5EC;
            break;
        case 3:
            *(f32*)(p + 0x3c) = lbl_8053D5EC;
            *(f32*)(p + 0x40) = lbl_8053D618;
            *(f32*)(p + 0x44) = lbl_8053D5EC;
            break;
        }
    } else {
        *(f32*)(p + 0x60) = lbl_8053D61C;
        *(f32*)(p + 0x64) = lbl_8053D61C;
        *(f32*)(p + 0x68) = lbl_8053D620;
        *(f32*)(p + 0x6c) = lbl_8053D620;
        *(u16*)(p + 0x94) = (*(u32*)(p + 0x90) >> 8) & 0xff;
        if (*(u16*)(p + 0x94) >= 9) {
            *(u16*)(p + 0x94) = 1;
        }
        *(s32*)(p + 0x254) = 1;
        switch (*(u16*)(p + 0x94)) {
        case 1:
            *(s32*)(p + 0x230) = 6;
            break;
        case 2:
            *(s32*)(p + 0x230) = 7;
            break;
        case 3:
            *(s32*)(p + 0x230) = 8;
            break;
        }
    }
    *(s32*)(p + 0x250) = 0;
    fn_8015EA2C(p);
    if (*(s32*)(p + 0x240) == 0) {
        *(f32*)(p + 0x260) = lbl_8053D5EC;
    }
    if (*(s32*)(p + 0x230) != 5 && *(s32*)(p + 0x230) != 4) {
        fn_8015DF7C(p);
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
