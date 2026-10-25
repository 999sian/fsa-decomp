#include "types.h"
#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "JSystem/JGeometry.h"
#include "Game/SinitPoolChain.h"
#include "Game/ItemBase.h"

extern "C" const f32 lbl_8053FA0C;
extern "C" u16 fn_8022461C(void* p, u32 b);
static inline u16 getGroundType(u32 room, void* pos) {
    return fn_8022461C(pos, room);
}
extern "C" u8 fn_801CD2F8(u32 o);
extern "C" u8 fn_802DEB58();
extern "C" void fn_801F0E34(void* a, u32 code, u32 z);


extern "C" u8* fn_8013CC50(u32 owner, void* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale);

extern "C" bool fn_801E1D9C();
extern "C" u8 fn_801E1D7C(u8* o);
extern "C" void fn_801EF830(s32 idx, f32* pos, u8* p3, u32 mask, u8* p5, u32 p6, u8* p7);
extern "C" void fn_801EF574(u8* a, s32 b, f32* v, u8* rec);
extern "C" void fn_801CD0D0(f32* a, f32* b);
extern "C" void fn_802F86CC(void* a, void* b, void* c, u32 d, f32 e, f32 f, void* g);
extern "C" int __float_epsilon[];
struct CCA8ResMgr {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void* get(u32 type, void* name);
};
extern "C" void fn_803075AC(s32 x, s32 y, u8* v, s32 p, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern "C" u8 lbl_8046A3C0[];
extern "C" void* lbl_8053AAF8;
extern "C" void* lbl_8053AB10;
extern "C" const f32 lbl_8053FA00;
extern "C" const f32 lbl_8053FA04;
extern "C" const f32 lbl_8053FA08;
extern "C" const f32 lbl_8053FA10;
extern "C" const f32 lbl_8053FA14;
extern "C" void fn_8020CCA8(u8* o0) {
    s32 iv;
    u8* o = o0;
    s32 mask;
    if (*(s32*)(o + 0x248) != 0) {
        DrawRec l;
        f32 m[3][4];
        f32 vec[3];
        l.b2d = 1;
        if (*(s32*)(o + 0x248) == 0xe) {
            JGeometry::TVec3<f32>* p = (JGeometry::TVec3<f32>*)(o + 0x54);
            if (p->squared() <= lbl_8053FA00 * *(f32*)__float_epsilon) {
                return;
            }
            m[0][3] = lbl_8053FA04;
            m[1][3] = lbl_8053FA04;
            m[2][3] = lbl_8053FA04;
            f32 sy = p->y;
            m[0][0] = p->x;
            m[0][1] = lbl_8053FA04;
            m[0][2] = lbl_8053FA04;
            m[1][0] = lbl_8053FA04;
            m[1][1] = sy;
            m[1][2] = lbl_8053FA04;
            m[2][0] = lbl_8053FA04;
            m[2][1] = lbl_8053FA04;
            m[2][2] = p->z;
            l.w18 = m;
        }
        mask = 7;
        iv = *(s32*)(o + 0x280) + 0xc0;
        if (fn_801E1D7C(o) != 0 && fn_8022461C(o + 0xc, *(u32*)(o + 4)) == 0x39) {
            mask = 0;
        }
        if (*(u32*)(o + 0x138) == 0) {
            fn_801EF830(*(s32*)(o + 4), (f32*)(o + 0xc), l.ids, mask, lbl_8046A3C0, iv, 0);
        }
        if (*(s32*)(o + 4) < 8) {
            void* res = ((CCA8ResMgr*)*(void**)((u8*)lbl_8053AAF8 + 0xa4))->get(0x534F4220, lbl_8046A3C0);
            fn_802F86CC(*(void**)((u8*)lbl_8053AB10 + 0x20), o + 0xc, res, iv, lbl_8053FA08, lbl_8053FA08, l.ids);
        }
        if (*(s32*)(o + 4) == 8) {
            fn_801CD0D0((f32*)(o + 0xc), vec);
            fn_801EF574(lbl_8046A3C0, iv, vec, l.ids);
        }
        fn_803075AC(*(s32*)(o + 0x198), *(s32*)(o + 4), o + 0xc, iv, 0, 2, -1, 1, 0, 0);
    }
}

#pragma optimization_level 2
extern "C" void fn_8020CF7C(Actor* o) {
    fn_8013CC50(o->field_04, &o->field_0C, 0x48d, 0, 0, 0, 0, 1, lbl_8053FA08);
}
#pragma optimization_level 4
extern "C" void fn_8020CFC4(u8* o) {
    switch (getGroundType(*(u32*)(o + 4), o + 0xc)) {
    case 0xd:
        fn_8013CC50(*(u32*)(o + 4), o + 0xc, 0x3d0, 0, 1, 0, 0, 1, lbl_8053FA0C);
        fn_8013CC50(*(u32*)(o + 4), o + 0xc, 0x15b, 0, 1, 0, 0, 1, lbl_8053FA08);
        fn_8013CC50(*(u32*)(o + 4), o + 0xc, 0x15c, -1, 0, 0, 0, 1, lbl_8053FA08);
        fn_801F0E34(o, 0x30022, 0);
        break;
    case 0xe:
        if (fn_801CD2F8(*(u32*)(o + 4))) {
            fn_801F0E34(o, 0x4003e, 0);
        } else {
            fn_8013CC50(*(u32*)(o + 4), o + 0xc, 0x2a9, -1, 0, 0, 0, 1, lbl_8053FA08);
            fn_8013CC50(*(u32*)(o + 4), o + 0xc, 0x2aa, 0, 1, 0, 0, 1, lbl_8053FA08);
            if (fn_802DEB58()) {
                fn_801F0E34(o, 0x30022, 0);
            } else {
                fn_801F0E34(o, 0x5005f, 0);
            }
        }
        break;
    default:
        fn_801F0E34(o, 0x4003e, 0);
        break;
    }
}
#pragma optimization_level reset
extern const f32 lbl_8053FA08;
extern "C" u16 fn_8022461C(void* p, u32 b);
extern "C" u8 fn_80224B88(void* p, u32 b);
extern "C" u8 fn_8022517C(void* p, u32 b);
extern "C" u8 fn_80224E88(void* p, u32 b);
extern "C" void fn_801F0E34(void* a, u32 code, u32 z);
extern "C" void fn_8020D16C(u8* a) {
    u32* w = (u32*)a;
    if (fn_8022461C(a + 0xc, w[1]) == 0x39) {
        fn_8013CC50(w[1], a + 0xc, 0x15b, 0, 1, 0, 0, 1, lbl_8053FA08);
        fn_8013CC50(w[1], a + 0xc, 0x15c, -1, 0, 0, 0, 1, lbl_8053FA08);
        fn_801F0E34(a, 0x400e0, 0);
    } else if (fn_80224B88(a + 0xc, w[1]) & 0xff) {
        fn_801F0E34(a, 0x400e1, 0);
    } else if (fn_8022517C(a + 0xc, w[1]) & 0xff) {
        fn_801F0E34(a, 0x400df, 0);
    } else if (fn_80224E88(a + 0xc, w[1]) & 0xff) {
        fn_801F0E34(a, 0x50071, 0);
    } else {
        fn_801F0E34(a, 0x4004f, 0);
    }
}

#pragma opt_propagation off
extern "C" void fn_8020D2AC(u8* o) {
    Vec pos;
    JGeometry::setTVec3f((f32*)(o + 0xc), &pos.x);
    pos.y -= 26.0f;
    if (!fn_801E1D9C()) {
        switch (*(s32*)(o + 0x98)) {
        case 0: pos.x += 6.0f; break;
        case 1: pos.x -= 6.0f; break;
        }
    }
    fn_8013CC50(*(u32*)(o + 4), &pos, 0x33a, 0, 1, 0, 0, 1, 1.0f);
}

void fn_8020D368(void) {}

#pragma opt_propagation reset


