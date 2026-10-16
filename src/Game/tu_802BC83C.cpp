#include "types.h"
#include "Game/Actor.h"


extern "C" void* fn_802D6A9C();
extern "C" void fn_802D73CC(void*, u32, s32);
extern "C" void fn_801EE434(void*);
extern "C" char lbl_804A8A50[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" void fn_802BC83C(u8* p) {
    (*(void (**)(u8*))(*(u8**)p + 0x54))(p);
    *(u8*)(p + 0x11c) = 0;
    fn_802D73CC(fn_802D6A9C(), *(u32*)(p + 0x26c), 0);
}

extern "C" void fn_802BC88C(u8* p) {
    u8* e = *(u8**)(p + 0x230);
    if (e) {
        *(u32*)(e + 0xf4) |= 1;
        *(s32*)(e + 0x24) = 1;
        *(u8**)(p + 0x230) = 0;
    }
    e = *(u8**)(p + 0x234);
    if (e) {
        *(u32*)(e + 0xf4) |= 1;
        *(s32*)(e + 0x24) = 1;
        *(u8**)(p + 0x234) = 0;
    }
    e = *(u8**)(p + 0x238);
    if (e) {
        *(u32*)(e + 0xf4) |= 1;
        *(s32*)(e + 0x24) = 1;
        *(u8**)(p + 0x238) = 0;
    }
    e = *(u8**)(p + 0x23c);
    if (e) {
        *(u32*)(e + 0xf4) |= 1;
        *(s32*)(e + 0x24) = 1;
        *(u8**)(p + 0x23c) = 0;
    }
}

extern "C" Actor* fn_802BD1A8(Actor* a, s16 n) {
    if (a) {
        u8* p = (u8*)a;
        *(void**)p = lbl_804A8A50;
        if (*(void**)(p + 0x230)) fn_801EE434(*(void**)(p + 0x230));
        if (*(void**)(p + 0x234)) fn_801EE434(*(void**)(p + 0x234));
        if (*(void**)(p + 0x238)) fn_801EE434(*(void**)(p + 0x238));
        if (*(void**)(p + 0x23c)) fn_801EE434(*(void**)(p + 0x23c));
        fn_802D73CC(fn_802D6A9C(), *(u32*)(p + 0x26c), 0);
        __dt__5ActorFv(a, 0);
        if (n > 0) operator delete(a);
    }
    return a;
}

