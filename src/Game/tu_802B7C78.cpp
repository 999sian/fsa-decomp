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

