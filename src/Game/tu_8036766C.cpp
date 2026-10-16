#include "types.h"
#include "Game/Actor.h"

struct Pair2f {
    f32 x;
    f32 y;
};

struct Vec3f {
    f32 x;
    f32 y;
    f32 z;
};


extern "C" char lbl_804ADFE8[];
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

extern "C" void* fn_801F856C(void);
extern "C" void* fn_8013CC50(u32 room, void* pos, f32 scale, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_80367E24(u8* p) {
    s32 n = *(s32*)((u8*)fn_801F856C() + 0x1008);
    s32 off;
    s32 i;
    for (i = 0, off = 0; i < n; i++, off += 4) {
        u8* actor = *(u8**)((u8*)fn_801F856C() + off + 8);
        if (actor != 0 && *(u32*)(actor + 0x1a0) == 'DCR2') {
            *(s32*)(p + 0x250) = i;
            *(u8**)(p + 0x254) = actor;
            *(Pair2f*)(p + 0x258) = *(Pair2f*)(actor + 0xc);
            *(f32*)(p + 0x260) = *(f32*)(actor + 0x14);
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

