#include "types.h"
#define GAME_ACTOR_USE_SDK_VEC
#include "JSystem/JGeometry/Vec.h"
#include "Game/Actor.h"
#include "Game/ItemBase.h"
#include "Game/SinitPoolChain.h"


extern "C" char lbl_804ADFE8[];
extern "C" u8 sincosTable___5JMath[];
extern "C" u8* sManager__8JUTVideo;
extern "C" void fn_8013CB44(void* obj, void* p, s32 a, s32 b, s32 c);
extern "C" void fn_8022FE80(s32 a, s32 b, void* c, s32 d, s32 e);
extern "C" u8 fn_803865B8(s32 a);
extern "C" void fn_80388EEC(s32 a);
extern "C" u8 fn_8038BD08(s32 a, s32 b, s32 c, void* d, s32 e);
extern "C" void detach__5ActorFv(void* this_);
static inline void fn_80367888_addVec(u8* p, f32* v) {
    *(f32*)(p + 0xc) = *(f32*)(p + 0x244) + v[0];
    *(f32*)(p + 0x10) = *(f32*)(p + 0x248) + v[1];
    *(f32*)(p + 0x14) = *(f32*)(p + 0x24c) + v[2];
}
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_8036766C(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804ADFE8;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" void fn_803676CC(u8* param_1) {
    u8* p = *(u8**)(param_1 + 0x270);
    if (p != 0) {
        *(u32*)(p + 0xf4) |= 0x100;
        *(u8**)(param_1 + 0x270) = 0;
    }
    p = *(u8**)(param_1 + 0x274);
    if (p == 0) {
        return;
    }
    *(u32*)(p + 0xf4) |= 0x100;
    *(u8**)(param_1 + 0x274) = 0;
}

extern "C" u8 lbl_80474C20[];
extern "C" f32 lbl_80542C08;
extern "C" void fn_801F06F0(void* this_, void* name, s32 id, DrawRec* rec, s32 n, f32 a, f32 b);
extern "C" void fn_80367710(u8* param_1) {
    DrawRec rec;
    u8* p = param_1;
    if (*(s32*)(p + 0x268) != 0) {
        *(s32*)(p + 0x268) = *(s32*)(p + 0x268) - 1;
    }
    if (*(s32*)(p + 0x268) == 0) {
        *(s32*)(p + 0x268) = 1;
        *(s32*)(p + 0x26c) = *(s32*)(p + 0x26c) + 1;
        if (*(s32*)(p + 0x26c) >= 6) {
            *(s32*)(p + 0x26c) = 0;
        }
    }
    fn_801F06F0(p, lbl_80474C20, *(s32*)(p + 0x264) + *(s32*)(p + 0x26c), &rec, 7, lbl_80542C08, lbl_80542C08);
}

extern "C" f32 lbl_80542C0C;
extern "C" f32 lbl_80542C10;
extern "C" f32 lbl_80542C14;
extern "C" f32 lbl_80542C18;
extern "C" f32 lbl_80542C1C;
extern "C" f32 lbl_80542C20;
extern "C" f32 lbl_80542C24;
extern "C" f32 lbl_80542C28;
extern "C" f32 lbl_80542C2C;
extern "C" f32 lbl_80542C30;
extern "C" f32 lbl_80542C34;
extern "C" f32 lbl_80542C38;
extern "C" f64 lbl_80542C40;
extern "C" void fn_80367888(u8* p) {
    f32 v[3];
    if (*(u8**)(p + 0x270) != 0) {
        fn_8013CB44(*(void**)(p + 0x270), p + 0xc, 0, -1, 1);
    }
    if (*(u8**)(p + 0x274) != 0) {
        fn_8013CB44(*(void**)(p + 0x274), p + 0xc, 0, -1, 1);
    }
    switch (*(s32*)(p + 0x238)) {
    case 0:
        if (*(f32*)(p + 0x10) > lbl_80542C0C + *(f32*)(p + 0x25c)) {
            *(f32*)(p + 0x10) -= lbl_80542C10;
            break;
        }
        *(f32*)(p + 0x10) = lbl_80542C0C + *(f32*)(p + 0x25c);
    case 1:
        *(f32*)(p + 0x244) = *(f32*)(p + 0xc);
        *(f32*)(p + 0x248) = *(f32*)(p + 0x10);
        *(f32*)(p + 0x24c) = *(f32*)(p + 0x14);
        *(s32*)(p + 0x238) = *(s32*)(p + 0x238) + 1;
        *(s16*)(p + 0x240) = 0;
        break;
    case 2:
        if (*(u8*)(p + 0x230) == 0) {
            if (*(s16*)(p + 0x240) >= 0) {
                *(f32*)(p + 0x10) -= lbl_80542C14;
                if (*(f32*)(p + 0x10) <= *(f32*)(p + 0x248) - lbl_80542C18) {
                    *(s16*)(p + 0x240) = -0x8000;
                }
            } else {
                *(f32*)(p + 0x10) += lbl_80542C14;
                if (*(f32*)(p + 0x10) >= *(f32*)(p + 0x248) + lbl_80542C18) {
                    *(s16*)(p + 0x240) = 0;
                }
            }
        } else {
            if (*(f32*)(p + 0x10) > *(f32*)(p + 0x248)) {
                *(f32*)(p + 0x10) -= lbl_80542C14;
            } else if (*(f32*)(p + 0x10) < *(f32*)(p + 0x248)) {
                *(f32*)(p + 0x10) += lbl_80542C14;
            }
        }
        break;
    case 3: {
        s16 ang = *(s16*)(p + 0x240);
        s16 b;
        *(s16*)(p + 0x240) = ang + 0x200;
        b = *(s16*)(p + 0x240);
        v[0] = lbl_80542C1C * *(f32*)(sincosTable___5JMath + (((u16)b >> 5) * 8));
        v[1] = lbl_80542C20 * *(f32*)(sincosTable___5JMath + (((u16)(b * 2) >> 5) * 8));
        v[2] = lbl_80542C24;
        fn_80367888_addVec(p, v);
        fn_8022FE80(0, *(s32*)(p + 4), *(void**)(p + 0x198), 1, 0);
        if (fn_803865B8(0)) {
            fn_80388EEC(0);
            *(s32*)(p + 0x238) = *(s32*)(p + 0x238) + 1;
        }
        break;
    }
    case 4: {
        s16 ang = *(s16*)(p + 0x240);
        s16 b;
        if (ang != 0 && (u16)ang != 0x8000) {
            *(s16*)(p + 0x240) = ang + 0x200;
            b = *(s16*)(p + 0x240);
            v[0] = lbl_80542C1C * *(f32*)(sincosTable___5JMath + (((u16)b >> 5) * 8));
            v[1] = lbl_80542C20 * *(f32*)(sincosTable___5JMath + (((u16)(b * 2) >> 5) * 8));
            v[2] = lbl_80542C24;
            fn_80367888_addVec(p, v);
            break;
        }
        {
            u8* vid = *(u8**)((u8*)sManager__8JUTVideo + 4);
            v[0] = (f32)(s32)*(u16*)(vid + 4) * lbl_80542C28;
            v[1] = (f32)(s32)*(u16*)(vid + 6) * lbl_80542C28 - lbl_80542C2C;
            v[2] = lbl_80542C24;
            fn_8022FE80(0, *(s32*)(p + 4), *(void**)(p + 0x198), 1, 0);
            fn_8038BD08(0, 0x83a, *(s32*)(p + 4), v, 0x62);
            *(s32*)(p + 0x238) = *(s32*)(p + 0x238) + 1;
        }
        break;
    }
    case 6:
        fn_8022FE80(0, *(s32*)(p + 4), *(void**)(p + 0x198), 1, 0);
        if (fn_803865B8(0)) {
            fn_80388EEC(0);
            ((void (*)(void*, s32))(*(void***)*(void**)(p + 0x254))[24])(*(void**)(p + 0x254), 10);
            *(s32*)(p + 0x238) = *(s32*)(p + 0x238) + 1;
        }
        break;
    case 5: {
        f32 t = *(f32*)(p + 0x23c) + lbl_80542C28;
        s16 a;
        f32 d;
        *(f32*)(p + 0x23c) = t;
        *(s16*)(p + 0x240) = *(s16*)(p + 0x240) + 0x800;
        a = *(s16*)(p + 0x240);
        if (t < lbl_80542C30) {
            v[0] = t * *(f32*)(sincosTable___5JMath + (((u16)a >> 5) * 8) + 4);
            v[1] = t * *(f32*)(sincosTable___5JMath + (((u16)a >> 5) * 8));
            v[2] = lbl_80542C24;
            fn_80367888_addVec(p, v);
            break;
        }
        *(f32*)(p + 0x14) -= lbl_80542C34;
        d = lbl_80542C38 - t;
        v[0] = __fabsf(d) * *(f32*)(sincosTable___5JMath + (((u16)a >> 5) * 8) + 4);
        v[1] = __fabsf(d) * *(f32*)(sincosTable___5JMath + (((u16)a >> 5) * 8));
        v[2] = lbl_80542C24;
        if (!(t >= lbl_80542C38)) {
            u8* q = *(u8**)(p + 0x254);
            ((void (*)(void*, s32))(*(void***)q)[24])(q, 0xc);
            if (*(u8**)(p + 0x270) != 0) {
                *(u32*)(*(u8**)(p + 0x270) + 0xf4) |= 0x100;
                *(u8**)(p + 0x270) = 0;
            }
            if (*(u8**)(p + 0x274) != 0) {
                *(u32*)(*(u8**)(p + 0x274) + 0xf4) |= 0x100;
                *(u8**)(p + 0x274) = 0;
            }
            *(s32*)(q + 0x230) = 0;
            detach__5ActorFv(p);
        }
        fn_80367888_addVec(p, v);
        break;
    }
    }
}

extern "C" void* fn_801F856C(void);
extern "C" void* fn_8013CC50(u32 room, void* pos, f32 scale, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" f64 __psq_l(void* ptr, s32 offset, s32 w, s32 i);
extern "C" void __psq_st(f64 v, void* ptr, s32 offset, s32 w, s32 i);
extern "C" void fn_80367E24(u8* p) {
    s32 n = *(s32*)((u8*)fn_801F856C() + 0x1008);
    s32 off;
    s32 i;
    for (i = 0, off = 0; i < n; off += 4, i++) {
        u8* actor = *(u8**)((u8*)fn_801F856C() + off + 8);
        if (actor != 0 && *(u32*)(actor + 0x1a0) == 'DCR2') {
            *(s32*)(p + 0x250) = i;
            *(u8**)(p + 0x254) = actor;
            *(JGeometry::TVec3<f32>*)(p + 0x258) = *(JGeometry::TVec3<f32>*)(actor + 0xc);
            break;
        }
    }
    *(s32*)(p + 0x238) = 0;
    *(f32*)(p + 0x23c) = 0.0f;
    *(s16*)(p + 0x240) = 0;
    *(s32*)(p + 0x264) = 0x1ee;
    *(void**)(p + 0x270) = fn_8013CC50(*(u32*)(p + 4), p + 0xc, 1.0f, 0x32c, 0, -1, 0, 0, 1);
    *(void**)(p + 0x274) = fn_8013CC50(*(u32*)(p + 4), p + 0xc, 1.0f, 0x184, 0, -1, 0, 0, 1);
    u8* e = *(u8**)(p + 0x270);
    if (e != 0) {
        e[0xbc] = 0x1e;
        e[0xbd] = 0xa0;
        e[0xbe] = 0xbe;
    }
    *(s32*)(p + 0x26c) = 0;
    *(s32*)(p + 0x268) = 1;
    p[0x230] = 0;
}

void fn_80367F74(void) {}

