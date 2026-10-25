#include "Game/Actor.h"
#include "Game/SinitPoolChain.h"

extern "C" u16 fn_80226850(s32 a, s32 b);
extern "C" void* fn_802D6A9C(void);
extern f32 lbl_80540BE0;
extern f32 lbl_80540BE4;
extern f32 lbl_80540BE8;


extern "C" char lbl_804A8AC8[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_802BD8C0(Actor* param_1, s16 param_2)
{
    if (param_1 != 0) {
        *(void**)param_1 = lbl_804A8AC8;
        __dt__5ActorFv(param_1, 0);
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_802BD920(void)
{
    return;
}

extern "C" void fn_802BDCC0(u8* param_1)
{
    Vec pos;
    u32 gx;
    u32 gy;
    s32 i;
    u16 s;

    if (*(s32*)(param_1 + 4) < 8) {
        u8* mgr = (u8*)fn_802D6A9C();
        u8* src = (*(s32*)(param_1 + 4) >= 8) ? mgr + 0xdc : mgr + 0xcc;
        *(u32*)(param_1 + 0x23c) = *(u32*)src;
        *(u32*)(param_1 + 0x240) = *(u32*)(src + 4);
        *(u32*)(param_1 + 0x244) = *(u32*)(src + 8);
        *(u32*)(param_1 + 0x248) = *(u32*)(src + 0xc);
        return;
    }

    pos = *(Vec*)(param_1 + 0xc);
    gx = (u32)pos.x & ~7;
    gy = (u32)pos.y & ~7;
    pos.x = (f32)gx;
    pos.y = (f32)gy;
    pos.z = lbl_80540BE0;

    if (pos.x >= lbl_80540BE4) {
        for (i = 0; i < 0x40; i++) {
            if (pos.x < lbl_80540BE4) {
                pos.x = lbl_80540BE4;
                break;
            }
            s = fn_80226850((s32)&pos, *(s32*)(param_1 + 4));
            if (s >= 8 && s < 0x10 && (s & 1)) {
                break;
            }
            pos.x += lbl_80540BE8;
        }
    } else {
        pos.x = lbl_80540BE4;
    }
    *(f32*)(param_1 + 0x244) = pos.x;

    pos.x = (f32)gx;
    if (pos.x >= lbl_80540BE8) {
        for (i = 0; i < 0x40; i++) {
            s = fn_80226850((s32)&pos, *(s32*)(param_1 + 4));
            if (s >= 8 && s < 0x10 && (s & 1)) {
                pos.x += lbl_80540BE8;
                break;
            }
            pos.x -= lbl_80540BE8;
        }
    } else {
        pos.x = lbl_80540BE0;
    }
    *(f32*)(param_1 + 0x23c) = pos.x;

    pos.x = (f32)gx;
    pos.y = (f32)gy;
    pos.z = lbl_80540BE0;
    if (pos.y >= lbl_80540BE4) {
        for (i = 0; i < 0x40; i++) {
            if (pos.y < lbl_80540BE4) {
                pos.y = lbl_80540BE4;
                break;
            }
            s = fn_80226850((s32)&pos, *(s32*)(param_1 + 4));
            if (s >= 8 && s < 0x10 && (s & 1)) {
                break;
            }
            pos.y += lbl_80540BE8;
        }
    } else {
        pos.y = lbl_80540BE4;
    }
    *(f32*)(param_1 + 0x248) = pos.y;

    pos.y = (f32)gy;
    if (pos.y >= lbl_80540BE8) {
        for (i = 0; i < 0x40; i++) {
            s = fn_80226850((s32)&pos, *(s32*)(param_1 + 4));
            if (s >= 8 && s < 0x10 && (s & 1)) {
                pos.y += lbl_80540BE8;
                break;
            }
            pos.y -= lbl_80540BE8;
        }
    } else {
        pos.y = lbl_80540BE0;
    }
    *(f32*)(param_1 + 0x240) = pos.y;
}

extern const f64 lbl_80540BF8;
extern "C" void fn_802BDCC0(u8* param_1);
extern "C" void fn_802BE008(u8* param_1)
{
    s32 t;
    s32 a;
    s32 b;
    f32 scale;

    *(s32*)(param_1 + 0x230) = 0;
    *(u32*)(param_1 + 0x234) = *(u32*)(param_1 + 0x90) & 0x1f;
    *(u32*)(param_1 + 0x238) = (*(u32*)(param_1 + 0x90) >> 7) & 0x1f;
    *(u32*)(param_1 + 0x258) = ((*(u32*)(param_1 + 0x90) >> 22) & 0x1f) + 1;
    *(u32*)(param_1 + 0x25c) = ((*(u32*)(param_1 + 0x90) >> 17) & 0x1f) + 1;
    *(u32*)(param_1 + 0x254) = (*(u32*)(param_1 + 0x90) >> 12) & 0x1f;
    *(u8*)(param_1 + 0x250) = 0;

    t = *(s32*)(param_1 + 0x234);
    if (t < 6) {
        if (t >= 4) {
            goto call;
        }
        if (t < 2) {
            return;
        }
    } else {
        if (t >= 10) {
            return;
        }
        if (t >= 8) {
            goto call;
        }
    }

    scale = lbl_80540BE8;
    a = *(s32*)(param_1 + 0x258);
    b = *(s32*)(param_1 + 0x25c);
    *(f32*)(param_1 + 0x23c) = scale * (f32)(-a);
    *(f32*)(param_1 + 0x240) = scale * (f32)(-b);
    *(f32*)(param_1 + 0x244) = scale * (f32)a;
    *(f32*)(param_1 + 0x248) = scale * (f32)b;
    *(f32*)(param_1 + 0x23c) = *(f32*)(param_1 + 0x23c) + *(f32*)(param_1 + 0xc);
    *(f32*)(param_1 + 0x240) = *(f32*)(param_1 + 0x240) + *(f32*)(param_1 + 0x10);
    *(f32*)(param_1 + 0x244) = *(f32*)(param_1 + 0x244) + *(f32*)(param_1 + 0xc);
    *(f32*)(param_1 + 0x248) = *(f32*)(param_1 + 0x248) + *(f32*)(param_1 + 0x10);
    return;

call:
    fn_802BDCC0(param_1);
}


