#include "Game/Actor.h"
#include "Game/SinitPoolChain.h"


extern "C" char lbl_804AAB40[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" char lbl_80471488[];
extern "C" f32 lbl_805417C4;
extern "C" void fn_801F06F0(void*, void*, s32, s32, s32, f32, f32);
extern "C" void fn_803075AC(void*, s32, void*, s32, s32, s32, s32, s32, s32, s32);
extern "C" void fn_80311C58(void* p) {
    fn_801F06F0(p, lbl_80471488, 0x386, 0, 0, lbl_805417C4, lbl_805417C4);
    fn_803075AC(*(void**)((u8*)p + 0x198), *(s32*)((u8*)p + 4), (u8*)p + 0xc, 0x386, 0, 2, -1, 0, 0, 0);
}

extern "C" Actor* fn_803122F8(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804AAB40;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" void* fn_802D6A9C(void);
extern "C" s8 fn_802D800C(void*, s32);
extern "C" void fn_802D8050(void*, s32, s32, s32);
extern "C" void fn_802A3948(void*, void*, s32, s32, s32);
extern "C" void* lbl_8053AC98;
extern "C" f32 lbl_805417E0;
extern "C" f32 lbl_805417E4;
extern "C" void fn_80312358(Actor* p) {
    void* base;
    f32 one = lbl_805417E4;
    f32 zero = lbl_805417E0;
    *(f32*)((u8*)p + 0x60) = one;
    *(f32*)((u8*)p + 0x64) = one;
    *(f32*)((u8*)p + 0x68) = zero;
    *(f32*)((u8*)p + 0x6c) = zero;
    base = fn_802D6A9C();
    *(s32*)((u8*)p + 0x230) = *(s32*)((u8*)base + 0xcc);
    *(s32*)((u8*)p + 0x234) = *(s32*)((u8*)base + 0xd0);
    *(s32*)((u8*)p + 0x238) = *(s32*)((u8*)base + 0xd4);
    *(s32*)((u8*)p + 0x23c) = *(s32*)((u8*)base + 0xd8);
    *(f32*)((u8*)p + 0x240) = *(f32*)((u8*)p + 0xc);
    *(f32*)((u8*)p + 0x244) = *(f32*)((u8*)p + 0x10);
    *(f32*)((u8*)p + 0x248) = *(f32*)((u8*)p + 0x14);
    *(s32*)((u8*)p + 0x24c) = 0;
    *(s32*)((u8*)p + 0x250) = -1;
    *(s32*)((u8*)p + 0x254) = -1;
    *((u8*)p + 0x258) = 0;
    *((u8*)p + 0x259) = 0;
    *((u8*)p + 0x25a) = 0;
    base = fn_802D6A9C();
    if ((u8)fn_802D800C(base, 0x14) != 0) {
        base = fn_802D6A9C();
        fn_802A3948(lbl_8053AC98, (u8*)base + 0x13280, 0, 0, 0x7a);
    } else {
        base = fn_802D6A9C();
        fn_802D8050(base, 0x15, 0, 0xff);
    }
}

