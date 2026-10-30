#include "types.h"
#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "JSystem/JGeometry/Vec.h"


extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* p);
extern void* lbl_804AB2B0[];
extern u8* lbl_8053AAF8;
extern f32 lbl_80541AA0;
extern f32 lbl_80541AC8;
extern "C" void* fn_8031FD60(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AB2B0;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern f64 lbl_80541AA8;
extern f32 lbl_80541A98;
extern f32 lbl_80541A9C;
extern f32 lbl_80541AB0;
extern f32 lbl_80541AB4;
extern f32 lbl_80541AB8;
extern "C" void* fn_801F856C(void);
extern "C" void Actor_CreateByID(void* manager, s32 procName, u32 param, Vec* pos, u32 flags, s32 r8, s32 r9);
extern "C" void fn_8031FDC0(void* this_) {
    u8* obj = (u8*)this_;
    JGeometry::TVec3<f32> pos(*(Vec*)(obj + 0x230));

    if ((u8)((Actor*)this_)->v11()) {
        return;
    }
    if (*(s32*)(obj + 0x240) == 0) {
        switch (*(s32*)(obj + 0x248)) {
        case 0:
            pos.x += lbl_80541A98;
            break;
        case 1:
            pos.x -= lbl_80541A98;
            break;
        case 2:
            pos.y += lbl_80541A9C;
            break;
        case 3:
            pos.y -= lbl_80541A9C;
            break;
        }
        if (*(u32*)(obj + 0x248) >= 2) {
            if (*(u8*)(obj + 0x254) == 0) {
                u8* rng = lbl_8053AAF8;
                *(u32*)(rng + 0xb4) = *(u32*)(rng + 0xb4) * 0x19660d + 0x3c6ef35f;
                u32 bits = (*(u32*)(rng + 0xb4) >> 9) | 0x3f800000;
                f32 r = *(f32*)&bits - 1.0f;
                if (r <= *(f32*)(obj + 0x23c)) {
                    pos.x = pos.x + lbl_80541AA8;
                    *(f32*)(obj + 0x23c) = lbl_80541AB0;
                } else {
                    pos.x = pos.x - lbl_80541AA8;
                    *(f32*)(obj + 0x23c) = lbl_80541AB4;
                }
            } else {
                if (*(u32*)(obj + 0x248) == 2) {
                    pos.y -= lbl_80541AB8;
                } else {
                    pos.y += lbl_80541AB8;
                }
            }
        }
        Actor_CreateByID(fn_801F856C(), 0x46495245, *(u32*)(obj + 4), &pos, *(u32*)(obj + 0x24c) & 0xF80101FF, -1, -1);
    }
    if (*(s32*)(obj + 0x240) <= 0) {
        u8* rng = lbl_8053AAF8;
        *(u32*)(rng + 0xb4) = *(u32*)(rng + 0xb4) * 0x19660d + 0x3c6ef35f;
        u32 bits = (*(u32*)(rng + 0xb4) >> 9) | 0x3f800000;
        *(s32*)(obj + 0x240) = *(u8*)(obj + 0x244) + (s32)((f32)(int)*(u8*)(obj + 0x245) * (*(f32*)&bits - 1.0f));
    } else {
        (*(s32*)(obj + 0x240))--;
    }
}

#pragma opt_common_subs off
extern "C" void fn_80320024(void* this_) {
    u8* obj = (u8*)this_;
    *(u32*)(obj + 0x24c) = 0;
    *(u32*)(obj + 0x250) = *(u32*)(obj + 0x90) & 0xf;
    if (*(u32*)(obj + 0x250) < 3) {
        *(u32*)(obj + 0x250) = 3;
    }
    f32 probability = 0.5f;
    *(JGeometry::TVec3f*)(obj + 0x230) = *(JGeometry::TVec3f*)(obj + 0xc);
    *(f32*)(obj + 0x23c) = probability;
    *(u8*)(obj + 0x244) = (*(u32*)(obj + 0x90) >> 8) & 0xff;
    *(u8*)(obj + 0x245) = (*(u32*)(obj + 0x90) >> 16) & 0xff;
    *(s32*)(obj + 0x240) = (s32)((f32)*(u8*)(obj + 0x245) *
        ((JMath::TRandom_fast_*)(lbl_8053AAF8 + 0xb4))->get_ufloat_1());
    *(u8*)(obj + 0x254) = (*(u32*)(obj + 0x90) >> 24) & 1;
    *(u8*)(obj + 0x255) = (*(u32*)(obj + 0x90) >> 25) & 1;
    u32 v = *(u32*)(obj + 0x90);
    u32 t = ((v & 0x30) ^ 0x20) | 0xf;
    *(u32*)(obj + 0x24c) = (v & 0xF8000000) | (t | (*(u32*)(obj + 0x250) << 6)) | (*(u8*)(obj + 0x255) << 16);
    *(u32*)(obj + 0x248) = ((*(u32*)(obj + 0x90) >> 4) & 3) ^ 2;
}
#pragma opt_common_subs reset
#include "JSystem/JAudio/JASFakeMatchFSA.h"
