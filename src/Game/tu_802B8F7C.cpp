#include "Game/Actor.h"


extern "C" char lbl_804A88E8[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" f32 lbl_80540B40;
extern "C" f32 lbl_80540B10;
extern "C" f32 lbl_80540AF0;
extern "C" void* fn_802D6A9C(void);
extern "C" void* fn_801F856C(void);
extern "C" s32 Actor_CreateByID(void* mgr, u32 fourCC, u32 owner, void* pos, u32 param, s32 a, s32 b);

struct Unk802B9974Src {
    virtual void m0() = 0;
    virtual void m1() = 0;
    virtual void m2() = 0;
    virtual void m3() = 0;
    virtual void m4() = 0;
    virtual void m5() = 0;
    virtual void m6() = 0;
    virtual void m7() = 0;
    virtual void m8() = 0;
    virtual void m9() = 0;
    virtual void m10() = 0;
    virtual u8 m11() = 0;
};
extern "C" Actor* fn_802B8F7C(Actor* param_1, s16 param_2)
{
    if (param_1 != 0) {
        *(void**)param_1 = lbl_804A88E8;
        __dt__5ActorFv(param_1, 0);
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_802B8FDC(void)
{
    return;
}

