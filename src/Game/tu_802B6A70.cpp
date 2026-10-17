#include "Game/Actor.h"

extern "C" void* lbl_8053AAF8;
extern "C" u8 lbl_8046CAD0[];
extern "C" void fn_801EFD34(Actor* p, void* obj, f32 x, f32 y, f32 z, void* buf, s32 n);


extern "C" char lbl_804A87A8[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" void fn_801EE434(void*);
extern "C" Actor* fn_802B74F4(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804A87A8;
        if (*(void**)((char*)p + 0x230)) {
            fn_801EE434(*(void**)((char*)p + 0x230));
        }
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" void* fn_802D6A9C(void);
extern "C" void* fn_802D9C4C(void* mgr);
extern "C" u8 fn_802D7544(void* mgr, void* arg);
extern "C" void fn_8029D8F0(void* mgr, f32* pos, s32 room, s32 n, s32 flag);
extern "C" void* lbl_8053AC98;

extern "C" void fn_802B7568(u8* p) {
    f32 vec[3];
    void* mgr;
    s32 room;
    s32 n;

    *(s32*)(p + 0x238) = (*(u32*)(p + 0x90) >> 22) & 0x1f;
    *(f32*)(p + 0xc) += 8.0f;
    *(f32*)(p + 0x60) = -48.0f;
    *(f32*)(p + 0x64) = -16.0f;
    *(f32*)(p + 0x68) = 48.0f;
    *(f32*)(p + 0x6c) = 40.0f;
    *(s32*)(p + 0x1a4) = 1;
    if (*(s32*)(p + 4) < 8) {
        *(s32*)(p + 0x244) = 1;
    } else {
        *(s32*)(p + 0x244) = 8;
    }
    *(s32*)(p + 0x23c) = 2;
    *(s32*)(p + 0x234) = 0;
    mgr = fn_802D6A9C();
    *(void**)(p + 0x248) = fn_802D9C4C(mgr);
    *(s32*)(p + 0x230) = 0;
    *(s32*)(p + 0x240) = 0;
    if (fn_802D7544(fn_802D6A9C(), *(void**)(p + 0x16c))) {
        room = *(s32*)(p + 4);
        n = *(s32*)(p + 0x244);
        vec[0] = *(f32*)(p + 0xc) - 8.0f;
        vec[1] = *(f32*)(p + 0x10);
        vec[2] = *(f32*)(p + 0x14);
        fn_8029D8F0(lbl_8053AC98, vec, room, n, 0);
        *(u8*)(p + 0x11c) = 0;
    }
}

