#include "types.h"
#include "Game/Actor.h"

extern void* lbl_8049CB04[];
extern "C" void* lbl_8053AAF8;
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_80138B7C(void* mgr);
extern "C" void __dt__5ActorFv(Actor* self, s32 flag);
extern "C" Actor* fn_80104894(Actor* p, s16 n) {
    if (p != NULL) {
        *(void**)p = lbl_8049CB04;
        if (*(s32*)((u8*)p + 0x234) == 2) {
            s32 kind = *(s32*)((u8*)lbl_8053AAF8 + 0x4c);
            if (kind != 9 && kind != 0xb) {
                u8* mgr = (u8*)fn_802D6A9C();
                *(s32*)(mgr + 0x1328c) = 0;
                fn_80138B7C(lbl_8053AAF8);
            }
        }
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern f32 lbl_8053C1F8;
extern "C" void fn_80104934(Actor* this_) {
    u8* p = (u8*)this_;
    void** vtbl = *(void***)this_;
    *(s32*)(p + 0x238) = *(s32*)(p + 0x90) & 0xf;
    *(s32*)(p + 0x234) = (*(s32*)(p + 0x90) >> 8) & 0xf;
    *(f32*)(p + 0x240) = lbl_8053C1F8;
    *(s32*)(p + 0x23c) = 0;
    *(u8*)(p + 0x244) = 0;
    *(u8*)(p + 0x245) = 0;
    *(u8*)(p + 0x246) = 0;
    if (*(s32*)(p + 0x234) == 2) {
        *(u8*)(p + 0x244) = 1;
    }
    if (*(u8*)((u8*)fn_802D6A9C() + 0x131f9) != 0) {
        ((void (*)(void*, s32, s32))vtbl[0xc])(this_, 0xff, 1);
    }
    if (*(s32*)(p + 0x234) == 2) {
        if (((u8 (*)(void*))vtbl[0xd])(this_) == 0) {
            *(u8*)(p + 0x246) = 2;
        } else {
            *(u8*)(p + 0x245) = 2;
            *(u8*)(p + 0x246) = 1;
        }
    }
}

