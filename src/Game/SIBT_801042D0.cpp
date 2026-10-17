#include "types.h"
#include "Game/Actor.h"

extern void* lbl_8049CB04[];
extern "C" void* lbl_8053AAF8;
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_80138B7C(void* mgr);
extern "C" void __dt__5ActorFv(Actor* self, s32 flag);
extern "C" void fn_801EEC98(void* this_, void* room, s16* a, s32* dir, f32* dist, s32* player, s32 b, s32 c);
extern "C" void* fn_8023E724(s32 i);
extern "C" void fn_80239914(void* box, u32 room, u32 id);
extern "C" void fn_80458FF0(void* a, u32 b, s32 c, s32 d);
extern "C" void fn_802D79E8(void* mgr, u32 room, s32 b, f32 x, f32 y);
extern "C" void fn_80134DE4(void* a, s32 b, s32 c);
extern u8 lbl_80463C30[];
extern s16 lbl_8049C3B8[];
extern "C" void* lbl_8053AF80;
extern f32 lbl_8053C1FC;
extern f32 lbl_8053C210;
extern f32 lbl_8053C214;
extern f32 lbl_8053C218;
extern f32 lbl_8053C21C;
extern f32 lbl_8053C220;
extern f32 lbl_8053C224;
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
    s32 kind = *(s32*)((u8*)this_ + 0x90);
    *(s32*)((u8*)this_ + 0x238) = kind & 0xf;
    *(s32*)((u8*)this_ + 0x234) = (kind >> 8) & 0xf;
    *(f32*)((u8*)this_ + 0x240) = lbl_8053C1F8;
    *(s32*)((u8*)this_ + 0x23c) = 0;
    *(u8*)((u8*)this_ + 0x244) = 0;
    *(u8*)((u8*)this_ + 0x245) = 0;
    *(u8*)((u8*)this_ + 0x246) = 0;
    if (*(s32*)((u8*)this_ + 0x234) == 2) {
        *(u8*)((u8*)this_ + 0x244) = 1;
    }
    if (*(u8*)((u8*)fn_802D6A9C() + 0x131f9) != 0) {
        ((void (*)(void*, s32, s32))(*(void***)this_)[0xc])(this_, 0xff, 1);
    }
    if (*(s32*)((u8*)this_ + 0x234) == 2) {
        if (((u8 (*)(void*))(*(void***)this_)[0xd])(this_) != 0) {
            *(u8*)((u8*)this_ + 0x245) = 2;
            *(u8*)((u8*)this_ + 0x246) = 1;
        } else {
            *(u8*)((u8*)this_ + 0x246) = 2;
        }
    }
}

void __sinit_SIBT_801042D0_cpp(void) {}

#include "Game/SinitPoolChain.h"
