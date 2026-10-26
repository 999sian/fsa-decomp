#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "JSystem/JGeometry/Vec.h"
#include "Game/SinitPoolChain.h"
#include "JSystem/JGeometry/Box.h"

extern "C" u16 fn_80226850(void* a, s32 b);
extern "C" void* fn_802D6A9C(void);
extern "C" void* fn_801F856C(void);
extern "C" void fn_801F0D20(void*, s32);
extern "C" void fn_80138B7C(void*);
extern "C" f32* fn_8023E724(s32);
extern "C" s32 fn_8023DE58(s32);
extern "C" u8 fn_801F75B4(void*, s32, f32*);
extern void* lbl_8053AF80;
extern void* lbl_8053AAF8;
extern const f32 lbl_80540BE0;
extern const f32 lbl_80540BE4;
extern const f32 lbl_80540BE8;

struct Rect4 {
    f32 x0, y0, x1, y1;
};

static inline u8 rectContains(Rect4* rect, f32* p) {
    return p[0] >= rect->x0 && p[1] >= rect->y0 && p[0] < rect->x1 && p[1] < rect->y1;
}


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

extern "C" void fn_802BDCC0(u8* this_) {
    s32 room;
    u32 ux;
    u32 uy;
    u16 ret;
    f32* o = (f32*)(this_ + 0x23c);
    room = *(s32*)(this_ + 4);
    if (room < 8) {
        u8* mgr = (u8*)fn_802D6A9C();
        f32* box;
        if (room < 8) box = (f32*)(mgr + 0xcc);
        else box = (f32*)(mgr + 0xdc);
        *(JGeometry::TBox2f*)o = *(JGeometry::TBox2f*)box;
    } else {
        JGeometry::TVec3<f32> p(*(Vec*)(this_ + 0xc));
        ux = (u32)p.x & ~7;
        uy = (u32)p.y & ~7;
        p.set((f32)ux, (f32)uy, 0.0f);
        {
            for (s32 i = 0; i < 0x40; i++) {
                if (p.x >= 512.0f) { p.x = 512.0f; break; }
                ret = fn_80226850(&p, *(s32*)(this_ + 4));
                if (ret >= 8 && ret < 0x10 && (ret & 1)) break;
                p.x += 8.0f;
            }
        }
        o[2] = p.x;
        p.x = (f32)ux;
        {
            for (s32 i = 0; i < 0x40; i++) {
                if (p.x < 8.0f) { p.x = 0.0f; break; }
                ret = fn_80226850(&p, *(s32*)(this_ + 4));
                if (ret >= 8 && ret < 0x10 && (ret & 1)) { p.x += 8.0f; break; }
                p.x -= 8.0f;
            }
        }
        o[0] = p.x;
        p.set((f32)ux, (f32)uy, 0.0f);
        {
            for (s32 i = 0; i < 0x40; i++) {
                if (p.y >= 512.0f) { p.y = 512.0f; break; }
                ret = fn_80226850(&p, *(s32*)(this_ + 4));
                if (ret >= 8 && ret < 0x10 && (ret & 1)) break;
                p.y += 8.0f;
            }
        }
        o[3] = p.y;
        p.y = (f32)uy;
        {
            for (s32 i = 0; i < 0x40; i++) {
                if (p.y < 8.0f) { p.y = 0.0f; break; }
                ret = fn_80226850(&p, *(s32*)(this_ + 4));
                if (ret >= 8 && ret < 0x10 && (ret & 1)) { p.y += 8.0f; break; }
                p.y -= 8.0f;
            }
        }
        o[1] = p.y;
    }
}

extern const f64 lbl_80540BF8;
extern "C" void fn_802BDCC0(u8* param_1);
extern "C" void fn_802BE008(u8* param_1)
{
    s32 t;
    s32 a;
    s32 b;
    f32 scale;
    f32 na;
    f32 nb;

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

    a = *(s32*)(param_1 + 0x258);
    b = *(s32*)(param_1 + 0x25c);
    scale = lbl_80540BE8;
    na = (f32)(-a);
    *(f32*)(param_1 + 0x23c) = scale * na;
    nb = (f32)(-b);
    *(f32*)(param_1 + 0x240) = scale * nb;
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

extern "C" void fn_802BE178(void) {}

