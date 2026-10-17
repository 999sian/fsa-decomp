#include "types.h"
#include "Game/SinitPoolChain.h"
struct BPOHEntry {
    u32 w[3];
};

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
extern "C" void fn_80161F20(char* this_) {
    fn_801F0E34(this_, 0x40015, 0);
    ((BPOHV*)this_)->setAnim(7, lbl_8053D6C0, lbl_8053D6D0);
    s32 p = *(s32*)(this_ + 0x270);
    if (p != 0) {
        fn_802D8050(fn_802D6A9C(), (void*)p, 1, 0xff);
    }
}

extern u8 lbl_804661E0[];
extern "C" void fn_80161F98(char* this_, s32 arg, s32 param3) {
    if (*(s32*)(this_ + 0x2ec) != arg) {
        if (*(s32*)(this_ + 0x2ec) < 0) {
            for (s32 i = 0; i < 12; i++) {
                this_[0x2f4 + i] = lbl_804661E0[arg * 12 + i];
            }
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
                u8* src = lbl_804661E0 + *(s32*)(this_ + 0x2ec) * 12 + j;
                p[0x2f4] = (u8)(s32)((f32)p[0x2f4] * b + a * (f32)src[0]);
                p[0x2f5] = (u8)(s32)((f32)p[0x2f5] * b + a * (f32)src[1]);
                p[0x2f6] = (u8)(s32)((f32)p[0x2f6] * b + a * (f32)src[2]);
                p[0x2f7] = (u8)(s32)((f32)p[0x2f7] * b + a * (f32)src[3]);
            }
            *(s32*)(this_ + 0x2f0) -= 1;
        }
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

