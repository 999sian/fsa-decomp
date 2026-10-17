#include "types.h"
#include "Game/SinitPoolChain.h"
struct BPOHV {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void setAnim(s32, float, float);
};

struct BPOHVt {
    char pad[0x28];
    void (*fn28)(void*, s32, float, float);
};

extern "C" void fn_801F0E34(void*, u32, u32);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D8050(void*, void*, s32, s32);
extern "C" void fn_801EE434(void*);
extern "C" void fn_802D7440(void*, s32);
extern "C" void fn_8022ADCC(void);
extern "C" void __dt__5ActorFv(void*, s32);
extern "C" void __dl__FPv(void*);
extern "C" char __vt__4BPOH[];
extern const float lbl_8053D6C0;
extern const float lbl_8053D6D0;
extern const float lbl_8053D6BC;
extern const float lbl_8053D6C4;
extern "C" void fn_80161F20(char* this_) {
    fn_801F0E34(this_, 0x40015, 0);
    ((BPOHV*)this_)->setAnim(7, lbl_8053D6C0, lbl_8053D6D0);
    s32 p = *(s32*)(this_ + 0x270);
    if (p != 0) {
        fn_802D8050(fn_802D6A9C(), (void*)p, 1, 0xff);
    }
}

extern u8 lbl_804661E0[];
extern const float lbl_8053D6C4;
extern "C" void fn_80161F98(char* this_, s32 arg, s32 param3) {
    if (*(s32*)(this_ + 0x2ec) != arg) {
        if (*(s32*)(this_ + 0x2ec) < 0) {
            u32 w0 = *(u32*)(lbl_804661E0 + arg * 12);
            u32 w1 = *(u32*)(lbl_804661E0 + arg * 12 + 4);
            u32 w2 = *(u32*)(lbl_804661E0 + arg * 12 + 8);
            u8* s0 = (u8*)&w0;
            u8* s1 = (u8*)&w1;
            u8* s2 = (u8*)&w2;
            this_[0x2f4] = s0[0];
            this_[0x2f5] = s0[1];
            this_[0x2f6] = s0[2];
            this_[0x2f7] = s0[3];
            this_[0x2f8] = s1[0];
            this_[0x2f9] = s1[1];
            this_[0x2fa] = s1[2];
            this_[0x2fb] = s1[3];
            this_[0x2fc] = s2[0];
            this_[0x2fd] = s2[1];
            this_[0x2fe] = s2[2];
            this_[0x2ff] = s2[3];
        }
        *(s32*)(this_ + 0x2ec) = arg;
        if (*(s32*)(this_ + 0x2f0) < 0) {
            *(s32*)(this_ + 0x2f0) = 0;
        } else {
            *(s32*)(this_ + 0x2f0) = param3;
        }
    } else {
        if (*(s32*)(this_ + 0x2f0) > 0) {
            f32 n = (f32)*(s32*)(this_ + 0x2f0);
            f32 a = 1.0f / n;
            f32 b = 1.0f - a;
            s32 j = 0;
            u8* p = (u8*)this_;
            for (s32 i = 0; i < 3; i++, p += 4, j += 4) {
                p[0x2f4] = (u8)(s32)((f32)p[0x2f4] * b + a * (f32)lbl_804661E0[*(s32*)(this_ + 0x2ec) * 12 + j]);
                p[0x2f5] = (u8)(s32)((f32)p[0x2f5] * b + a * (f32)lbl_804661E0[*(s32*)(this_ + 0x2ec) * 12 + j + 1]);
                p[0x2f6] = (u8)(s32)((f32)p[0x2f6] * b + a * (f32)lbl_804661E0[*(s32*)(this_ + 0x2ec) * 12 + j + 2]);
                p[0x2f7] = (u8)(s32)((f32)p[0x2f7] * b + a * (f32)lbl_804661E0[*(s32*)(this_ + 0x2ec) * 12 + j + 3]);
            }
            *(s32*)(this_ + 0x2f0) -= 1;
        }
    }
}

extern "C" f32 lbl_804A0410[];
extern "C" s32 lbl_8053AB58;
extern "C" void fn_80163E80(char* this_)
{
    u8* p = (u8*)this_;

    *(u16*)(p + 0x94) = 0;
    *(f32*)(p + 0x60) = -60.0f;
    *(f32*)(p + 0x64) = -60.0f;
    *(f32*)(p + 0x68) = 60.0f;
    *(f32*)(p + 0x6c) = 60.0f;
    *(s32*)(p + 0x244) = 0;
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x250) = 0;
    *(s32*)(p + 0x234) = 0;
    *(s32*)(p + 0x238) = 0;
    *(s32*)(p + 0x23c) = 0;
    *(s32*)(p + 0x240) = 0;
    *(s32*)(p + 0x258) = 0;
    *(s32*)(p + 0x25c) = 5;
    *(f32*)(p + 0x27c) = 1.0f;
    *(f32*)(p + 0x280) = 1.0f;
    *(f32*)(p + 0x284) = 0.4f;
    *(f32*)(p + 0x274) = 0.0f;
    *(f32*)(p + 0x278) = 0.05f;
    *(s32*)(p + 0x254) = 0;
    *(f32*)(p + 0x2a8) = 0.0f;
    *(f32*)(p + 0x2a4) = 0.0f;
    *(f32*)(p + 0x2a0) = 0.0f;
    *(f32*)(p + 0x294) = *(f32*)(p + 0xc);
    *(f32*)(p + 0x298) = *(f32*)(p + 0x10);
    *(f32*)(p + 0x29c) = *(f32*)(p + 0x14);
    *(f32*)(p + 0x2ac) = *(f32*)(p + 0xc);
    *(f32*)(p + 0x2b0) = *(f32*)(p + 0x10);
    *(f32*)(p + 0x2b4) = *(f32*)(p + 0x14);
    *(s32*)(p + 0x260) = 0;
    *(f32*)(p + 0x288) = 0.0f;
    *(f32*)(p + 0x28c) = 0.0f;
    lbl_8053AB58 = 0;
    *(s32*)(p + 0x2e8) = 0;
    *(f32*)(p + 0x2b8) = *(f32*)(p + 0xc);
    *(f32*)(p + 0x2bc) = *(f32*)(p + 0x10);
    *(f32*)(p + 0x2c0) = *(f32*)(p + 0x14);
    *(f32*)(p + 0x2b8) = *(f32*)(p + 0x2b8) + lbl_804A0410[0];
    *(f32*)(p + 0x2bc) = *(f32*)(p + 0x2bc) + lbl_804A0410[1];
    *(f32*)(p + 0x2c4) = *(f32*)(p + 0xc);
    *(f32*)(p + 0x2c8) = *(f32*)(p + 0x10);
    *(f32*)(p + 0x2cc) = *(f32*)(p + 0x14);
    *(f32*)(p + 0x2c4) = *(f32*)(p + 0x2c4) + lbl_804A0410[2];
    *(f32*)(p + 0x2c8) = *(f32*)(p + 0x2c8) + lbl_804A0410[3];
    *(f32*)(p + 0x2d0) = *(f32*)(p + 0xc);
    *(f32*)(p + 0x2d4) = *(f32*)(p + 0x10);
    *(f32*)(p + 0x2d8) = *(f32*)(p + 0x14);
    *(f32*)(p + 0x2d0) = *(f32*)(p + 0x2d0) + lbl_804A0410[4];
    *(f32*)(p + 0x2d4) = *(f32*)(p + 0x2d4) + lbl_804A0410[5];
    *(f32*)(p + 0x2dc) = *(f32*)(p + 0xc);
    *(f32*)(p + 0x2e0) = *(f32*)(p + 0x10);
    *(f32*)(p + 0x2e4) = *(f32*)(p + 0x14);
    *(f32*)(p + 0x2dc) = *(f32*)(p + 0x2dc) + lbl_804A0410[6];
    *(f32*)(p + 0x2e0) = *(f32*)(p + 0x2e0) + lbl_804A0410[7];
    *(s32*)(p + 0x2ec) = -1;
    *(s32*)(p + 0x2f0) = -1;
    *(s32*)(p + 0x2f4) = 0;
    *(s32*)(p + 0x2f8) = 0;
    *(s32*)(p + 0x2fc) = 0;
    *(s32*)(p + 0x26c) = -1;
    *(u16*)(p + 0x290) = 0;
    *(s32*)(p + 0x270) = (*(u32*)(p + 0x90) >> 2) & 0x1f;
    *(u8*)(p + 0x196) = 1;
    *(s32*)(p + 0x268) = *(u32*)(p + 0x90) & 3;
    *(s32*)(p + 0x108) = 10000;
    switch (*(s32*)(p + 0x268)) {
    case 0:
        fn_802D7440(fn_802D6A9C(), 0);
        *(s32*)(p + 0x230) = 0;
        break;
    case 1:
        *(u16*)(p + 0x290) = 0x8000;
        *(f32*)(p + 0x60) = -12.0f;
        *(f32*)(p + 0x64) = -12.0f;
        *(f32*)(p + 0x68) = 12.0f;
        *(f32*)(p + 0x6c) = 12.0f;
        *(f32*)(p + 0x288) = 1.0f;
        *(s32*)(p + 0x230) = 12;
        break;
    case 2:
        *(s32*)(p + 0x230) = 14;
        break;
    }
}

extern "C" void* fn_80164118(char* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = __vt__4BPOH;
        fn_801EE434(*(void**)(this_ + 0x2e8));
        if (*(s32*)(this_ + 0x268) == 2) {
            fn_802D7440(fn_802D6A9C(), 1);
            fn_8022ADCC();
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

void __sinit_BPOH_801618D0_cpp(void) {}

