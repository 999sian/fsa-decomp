#include "Game/Actor.h"


extern "C" char lbl_804A927C[];
struct ActorSlot5 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void slot5();
};
extern "C" const f32 lbl_80540E40;
extern "C" const f32 lbl_80540E44;
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_802CDD3C(Actor* p, s16 n)
{
    if (p != NULL) {
        *(void**)p = lbl_804A927C;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" void fn_802CE7A8(char* p) {
    f32 f;
    *(u32*)(p + 0x234) = *(u32*)(p + 0x90) & 0xfff;
    *(u32*)(p + 0x23c) = (*(u32*)(p + 0x90) >> 12) & 0xf;
    *(u32*)(p + 0x238) = (*(u32*)(p + 0x90) >> 16) & 0xf;
    *(u32*)(p + 0x240) = (*(u32*)(p + 0x90) >> 20) & 0xf;
    *(u32*)(p + 0x244) = (*(u32*)(p + 0x90) >> 25) & 1;
    if (*(u32*)(p + 0x244) != 0) {
        *(u8*)(p + 0x259) = 1;
    } else {
        *(u8*)(p + 0x259) = 0;
    }
    if (*(u32*)(p + 0x90) & 0x4000000) {
        *(u8*)(p + 0x258) = 1;
    } else {
        *(u8*)(p + 0x258) = 0;
    }
    if (*(u32*)(p + 0x240) == 0 || *(u32*)(p + 0x240) == 2 || *(u32*)(p + 0x240) == 4) {
        *(s32*)(p + 0x230) = 1;
    } else {
        *(s32*)(p + 0x230) = 0;
    }
    f = lbl_80540E40;
    *(f32*)(p + 0x24c) = f;
    *(f32*)(p + 0x250) = f;
    *(f32*)(p + 0x254) = f;
    *(s16*)(p + 0x248) = 0;
    if (*(s32*)(p + 0x234) == 0x1b) {
        f = lbl_80540E44;
        *(f32*)(p + 0x24c) = f;
        *(f32*)(p + 0x250) = f;
        *(f32*)(p + 0x254) = f;
        *(s16*)(p + 0x248) = 0x4000;
    } else if (*(s32*)(p + 0x234) == 0x1c) {
        f = lbl_80540E44;
        *(f32*)(p + 0x24c) = f;
        *(f32*)(p + 0x250) = f;
        *(f32*)(p + 0x254) = f;
        *(s16*)(p + 0x248) = -0x4000;
    } else if (*(s32*)(p + 0x234) == 0x1d) {
        f = lbl_80540E44;
        *(f32*)(p + 0x24c) = f;
        *(f32*)(p + 0x250) = f;
        *(f32*)(p + 0x254) = f;
        *(s16*)(p + 0x248) = -0x8000;
    } else if (*(s32*)(p + 0x234) == 0x1e) {
        f = lbl_80540E44;
        *(f32*)(p + 0x24c) = f;
        *(f32*)(p + 0x250) = f;
        *(f32*)(p + 0x254) = f;
        *(s16*)(p + 0x248) = 0;
    }
    ((ActorSlot5*)p)->slot5();
    *(u8*)(p + 0x11f) = 1;
}

