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
extern "C" void fn_80161F20(char* this_) {
    fn_801F0E34(this_, 0x40015, 0);
    ((BPOHV*)this_)->setAnim(7, lbl_8053D6C0, lbl_8053D6D0);
    s32 p = *(s32*)(this_ + 0x270);
    if (p != 0) {
        fn_802D8050(fn_802D6A9C(), (void*)p, 1, 0xff);
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

