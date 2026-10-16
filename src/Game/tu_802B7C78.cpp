#include "Game/Actor.h"


extern "C" char lbl_804A886C[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" void fn_802D6A9C(void);
extern "C" void fn_802D9FBC(void);
extern "C" void* fn_8013CC50(u32 id, void* pos, s32 kind, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale);
extern "C" void fn_801F0E34(void*, u32, s32);
extern f32 lbl_80540ACC;
extern f32 lbl_80540ADC;
extern f32 lbl_80540AE0;
extern f32 lbl_80540AE4;
extern f32 lbl_80540AE8;
extern f32 lbl_80540AEC;
extern void* lbl_8053AED0;
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F6058(void*, s32);
extern "C" void fn_8043D67C(void*, s32, s32, s32);
struct ActorSlot9 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void slot9();
};

extern "C" Actor* fn_802B7C78(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804A886C;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" void fn_802B7CD8(void* this_) {
    fn_802D6A9C();
    fn_802D9FBC();
    ((ActorSlot9*)this_)->slot9();
}

extern "C" void fn_802B8420(char* this_) {
    fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, 0x173, 1, 0, 0, 0, 1, 1.0f);
    *(u8*)(this_ + 0x11c) = 0;
    fn_801F0E34(this_, 0x40041, 0);
}

extern "C" char lbl_8046CB70[];
extern "C" s32 lbl_8046CB60[];
extern "C" void fn_801F06F0(void* this_, const char* name, s32 id, void* rec, s32 p5, f32 a, f32 b);
extern "C" void fn_802B848C(char* this_) {
    if (*(s32*)(this_ + 0x230) != 0) {
        u8 rec[0x3c];
        *(s32*)(rec + 0x10) = -1;
        *(s32*)(rec + 0x14) = -1;
        for (s32 i = 0; (u8)i < 0x10; i += 8) {
            rec[(u8)i] = i;
            rec[(u8)(i + 1)] = i + 1;
            rec[(u8)(i + 2)] = i + 2;
            rec[(u8)(i + 3)] = i + 3;
            rec[(u8)(i + 4)] = i + 4;
            rec[(u8)(i + 5)] = i + 5;
            rec[(u8)(i + 6)] = i + 6;
            rec[(u8)(i + 7)] = i + 7;
        }
        *(s32*)(rec + 0x10) = -1;
        rec[0x1c] = 0;
        rec[0x1d] = 0;
        *(s32*)(rec + 0x14) = 0;
        *(s32*)(rec + 0x18) = 0;
        rec[0x1e] = 0;
        rec[0x1f] = 1;
        rec[0x20] = 1;
        rec[0x21] = 0;
        rec[0x22] = 0;
        rec[0x23] = 0;
        rec[0x24] = 0;
        rec[0x25] = 0;
        rec[0x26] = 1;
        *(s32*)(rec + 0x28) = 3;
        rec[0x2c] = 1;
        rec[0x2d] = 0;
        rec[0x2e] = 0;
        *(s32*)(rec + 0x30) = -1;
        *(s32*)(rec + 0x34) = 0;
        *(s32*)(rec + 0x38) = 2;
        rec[0x1c] = 1;
        rec[0x1d] = 1;
        rec[0x13] = *(s32*)(this_ + 0x270);
        *(s32*)(rec + 0x30) = 8;
        fn_801F06F0(this_, lbl_8046CB70, lbl_8046CB60[*(s32*)(this_ + 0x24c)] + 0x466, rec, 7, lbl_80540ACC, lbl_80540ACC);
    }
}

extern "C" void fn_802B8C44(u8* this_) {
    f32 f1 = lbl_80540ADC;
    f32 f0 = lbl_80540AE0;
    f32 f3 = lbl_80540ACC;
    f32 f2 = lbl_80540AE4;
    *(f32*)(this_ + 0x60) = f1;
    *(f32*)(this_ + 0x64) = f1;
    f1 = lbl_80540AE8;
    *(f32*)(this_ + 0x68) = f0;
    *(f32*)(this_ + 0x6c) = f0;
    f0 = lbl_80540AEC;
    *(s32*)(this_ + 0x244) = 0xb4;
    *(s32*)(this_ + 0x248) = 0x14;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(f32*)(this_ + 0x260) = f3;
    *(f32*)(this_ + 0x268) = f2;
    *(f32*)(this_ + 0x264) = f1;
    *(f32*)(this_ + 0x26c) = f0;
    *(f64*)(this_ + 0x234) = *(f64*)(this_ + 0xc);
    *(f32*)(this_ + 0x23c) = *(f32*)(this_ + 0x14);
    *(s32*)(this_ + 0x270) = 0;
    *(s32*)(this_ + 0x274) = 0;
    *(s32*)(this_ + 0x298) = 4;
    *(s32*)(this_ + 0x280) = 0;
    for (s32 i = 0; i < 4; i++) {
        *(void**)(this_ + 0x2a0 + i * 4) = fn_801F6058(fn_801F856C(), i);
    }
    *(s32*)(this_ + 0x27c) = 0;
    this_[0x196] = 1;
    *(s32*)(this_ + 0x230) = 0;
    fn_801F0E34(this_, 0x4003f, 0);
    fn_8043D67C(lbl_8053AED0, 0x197, 0, 0);
}

