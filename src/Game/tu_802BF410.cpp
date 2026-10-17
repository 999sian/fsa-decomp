#include "Game/Actor.h"


extern "C" char lbl_804A8C28[];
extern "C" void __dt__5ActorFv(Actor*, s32);
struct ActorSlots {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual u8 v13();
};

extern "C" Actor* fn_802BF410(Actor* p, s16 n) {
    if (p != NULL) {
        *(void**)p = lbl_804A8C28;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" void fn_802BF470(void) {
}

extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D4874(void* cfg, s32 room, u16 tile, void* a, void* b);
extern "C" void fn_802D4768(void* cfg, s32 room, u16 tile, void* a, void* b);
extern "C" u8 fn_802D4ADC(void* cfg, s32 room, u16 tile);
extern "C" void fn_802F9974(void* mgr, s32 id, s32 n, s32 flag);
extern "C" s32 fn_80226BC4(f32* pos, s32 n);
extern "C" void* lbl_8053AB10;
extern "C" void fn_802BF7CC(Actor* this_) {
    u8* self = (u8*)this_;
    f32 pos[2];
    f32 y;

    *(u32*)(self + 0x234) = *(u32*)(self + 0x90) & 0x3f;
    *(u32*)(self + 0x238) = (*(u32*)(self + 0x90) >> 6) & 0xf;
    *(u32*)(self + 0x23c) = (*(u32*)(self + 0x90) >> 10) & 0xf;
    *(u32*)(self + 0x240) = (*(u32*)(self + 0x90) >> 14) & 0xf;
    *(u32*)(self + 0x244) = (*(u32*)(self + 0x90) >> 18) & 0xf;
    if ((*(u32*)(self + 0x90) & 0x4000000) != 0) {
        self[0x260] = 1;
    } else {
        self[0x260] = 0;
    }
    y = *(f32*)(self + 0x10);
    pos[0] = *(f32*)(self + 0xc);
    pos[1] = y;
    *(s32*)(self + 0x24c) = fn_80226BC4(pos, *(s32*)(self + 0x4));
    *(s32*)(self + 0x248) = 0;

    switch (*(s32*)(self + 0x234)) {
    case 0:
        fn_802D4874(fn_802D6A9C(), *(s32*)(self + 0x4), (u16)*(s32*)(self + 0x24c), self + 0x250, self + 0x258);
        if (fn_802D4ADC(fn_802D6A9C(), *(s32*)(self + 0x4), (u16)*(s32*)(self + 0x24c)) == 1) {
            fn_802F9974(*(void**)((u8*)lbl_8053AB10 + 0x20), *(s32*)(self + 0x4), *(s32*)(self + 0x24c), 0x10);
            self[0x11c] = 0;
        }
        break;
    case 2:
        fn_802D4768(fn_802D6A9C(), *(s32*)(self + 0x4) + 1, (u16)*(s32*)(self + 0x24c), self + 0x250, self + 0x258);
        break;
    case 3:
        if (*(s32*)(self + 0x244) == 0) {
            *(s32*)(self + 0x248) = 0x32;
        }
        break;
    }

    if (self[0x11c] != 0) {
        ((ActorSlots*)this_)->v3();
    }
}
#include "JSystem/JAudio/JASFakeMatchFSA.h"
