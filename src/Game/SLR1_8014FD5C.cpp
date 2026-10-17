#include "types.h"
#include "JSystem/JGeometry/Box.h"
#include "JSystem/JMath/JMath.h"
#include <math.h>

#pragma auto_inline off

class Actor;

extern "C" {
void* fn_801F856C();
s32 fn_801F8544(void* pool, u32 type, u32 owner, const Vec* position, u32 parameter);
s32 fn_801F7818(void* pool, u32 type, s32 owner, Actor** output, s32 excludedID);
s32 Actor_CreateByID(void* pool, u32 type, u32 owner, const Vec* position,
                     u32 parameter, s32 arg6, s32 arg7);
Actor* fn_801F666C(void* pool, s32 id);
u8 fn_801F2618(Actor* actor, f32* output, u32 flags);
void* fn_802D6A9C();
s16 fn_801F6874(u32 dir);
u16 fn_8022461C(void* pos, s32 room);
u8 fn_802DE9A0(void);
u8 fn_802DCD0C(void* room);
u8 fn_8030C210(void* camera, const Vec* position);

extern u8* lbl_8053AAF8;
extern u8* lbl_8053AB10;
extern const f32 lbl_8053D258;
extern const f32 lbl_8053D25C;
extern const f32 lbl_8053D2B0;
extern const f64 lbl_8053D2F8;
extern const f64 lbl_8053D300;
extern const f64 lbl_8053D308;
extern const f32 lbl_8053D310;
extern const f32 lbl_8053D288;
extern u8 sincosTable___5JMath[];
extern const f32 lbl_8053D314;
extern s32 lbl_804BF850[];
extern s32 lbl_8053AB44;
extern s32 lbl_8053AB48;
extern s32 lbl_80539F68;
}

extern "C" void fn_8013CC50(u32, const Vec*, s32, s32, s32, s32, s32, s32, f32);
extern "C" void __dt__5ActorFv(Actor*, s16);
extern "C" void __dl__FPv(void*);
extern u8 lbl_8049FCA0[];
extern const f32 lbl_8053D268;
extern "C" s32 fn_801535B4(Actor* actor)
{
    s32 room = *(s32*)((u8*)actor + 0x4);
    s16 angle;
    u16 result;

    if (*(u8*)((u8*)fn_802D6A9C() + room + 0x131DF)) {
        return 0;
    }
    if (*(s32*)((u8*)actor + 0x230) == 0xE) {
        return 1;
    }
    if (*(f32*)((u8*)actor + 0x14) > lbl_8053D288) {
        return 0;
    }
    *(f32*)((u8*)actor + 0x2B8) = *(f32*)((u8*)actor + 0xC);
    *(f32*)((u8*)actor + 0x2BC) = *(f32*)((u8*)actor + 0x10);
    *(f32*)((u8*)actor + 0x2C0) = *(f32*)((u8*)actor + 0x14);
    *(f32*)((u8*)actor + 0x2B8) = (f32)((s32)*(f32*)((u8*)actor + 0x2B8) & 0xFFF8);
    *(f32*)((u8*)actor + 0x2BC) = (f32)((s32)*(f32*)((u8*)actor + 0x2BC) & 0xFFF8);
    angle = fn_801F6874(*(s32*)((u8*)actor + 0x98));
    *(f32*)((u8*)actor + 0x2B8) = lbl_8053D314 * *(f32*)(sincosTable___5JMath + ((u32)(s32)angle >> 2 & 0x3FF8)) + *(f32*)((u8*)actor + 0x2B8);
    angle = fn_801F6874(*(s32*)((u8*)actor + 0x98));
    *(f32*)((u8*)actor + 0x2BC) = lbl_8053D314 * *(f32*)(sincosTable___5JMath + ((u32)(s32)angle >> 2 & 0x3FF8) + 4) + *(f32*)((u8*)actor + 0x2BC);
    result = fn_8022461C((u8*)actor + 0x2B8, *(s32*)((u8*)actor + 0x4));
    if ((u32)(result - 2) < 2 || result == 0xE) {
        *(s32*)((u8*)actor + 0x250) = 10000;
        *(s32*)((u8*)actor + 0x108) = 200;
        *(s32*)((u8*)actor + 0x280) = 0;
        if (result == 0xE && fn_802DE9A0() == 1) {
            *(s32*)((u8*)actor + 0x280) = 1;
        }
        *(f32*)((u8*)actor + 0x44) = lbl_8053D258;
        *(f32*)((u8*)actor + 0x40) = lbl_8053D258;
        *(f32*)((u8*)actor + 0x3C) = lbl_8053D258;
        *(f32*)((u8*)actor + 0x2B4) = lbl_8053D258;
        *(f32*)((u8*)actor + 0x2B0) = lbl_8053D258;
        *(f32*)((u8*)actor + 0x2AC) = lbl_8053D258;
        *(s32*)((u8*)actor + 0xD8) = 0;
        *(s32*)((u8*)actor + 0xDC) = 0;
        *(s32*)((u8*)actor + 0x230) = 0xD;
        return 1;
    }
    return 0;
}

extern "C" Actor* fn_801537A0(Actor* actor, s16 del)
{
    s32 i;
    s32* slot;

    if (actor != NULL) {
        *(void**)actor = lbl_8049FCA0;
        if (*(s32*)((u8*)actor + 0x108) <= 0) {
            s32 mode = *(s32*)((u8*)actor + 0x288);
            if (mode == 1 || mode == 3) {
                if (mode == 1) {
                    fn_801F8544(fn_801F856C(), 0x52555059, *(u32*)((u8*)actor + 0x4), (Vec*)((u8*)actor + 0xC), 0x30004);
                    fn_8013CC50(*(u32*)((u8*)actor + 0x4), (Vec*)((u8*)actor + 0xC), 0x3D9, 0, 1, 0, 0, 1, lbl_8053D25C);
                } else {
                    fn_801F8544(fn_801F856C(), 0x52555059, *(u32*)((u8*)actor + 0x4), (Vec*)((u8*)actor + 0xC), 0x30008);
                    fn_8013CC50(*(u32*)((u8*)actor + 0x4), (Vec*)((u8*)actor + 0xC), 0x3D9, 0, 1, 0, 0, 1, lbl_8053D268);
                }
            }
        }
        {
            s32 id = *(s32*)((u8*)actor + 0x2A4);
            if (id >= 0) {
                Actor* target = fn_801F666C(fn_801F856C(), id);
                if (target != NULL) {
                    *(s32*)((u8*)target + 0x290) = -1;
                }
            }
        }
        slot = lbl_804BF850;
        for (i = 0; i < 4; i++) {
            if (*slot == *(s32*)((u8*)actor + 0x198)) {
                *slot = -1;
            }
            slot++;
        }
        __dt__5ActorFv(actor, 0);
        if (del > 0) {
            __dl__FPv(actor);
        }
    }
    return actor;
}

extern "C" void fn_8015394C(Actor* actor)
{
    s32 i;
    s32* slot;
    u16 state;

    lbl_8053AB44 = 1;
    *(s32*)((u8*)actor + 0xB8) = 1;
    if (*(s32*)((u8*)actor + 0x108) <= 0) {
        s32 id = *(s32*)((u8*)actor + 0x2A4);
        if (id >= 0) {
            Actor* target = fn_801F666C(fn_801F856C(), id);
            if (target != NULL) {
                *(s32*)((u8*)target + 0x290) = -1;
            }
        }
    }
    state = *(u16*)((u8*)actor + 0x94);
    if (state >= 6 && state <= 9) {
        s32 id = *(s32*)((u8*)actor + 0x2A4);
        if (id >= 0) {
            Actor* target = fn_801F666C(fn_801F856C(), id);
            if (target != NULL) {
                *(s32*)((u8*)target + 0x290) = -1;
            }
        }
    }
    slot = lbl_804BF850;
    for (i = 0; i < 4; i++) {
        if (*slot == *(s32*)((u8*)actor + 0x198)) {
            *slot = -1;
            *(s32*)((u8*)actor + 0xBC) = 2;
        }
        slot++;
    }
    if (*(s32*)((u8*)actor + 0x284) != 0) {
        if (lbl_8053AB48 == 0) {
            lbl_80539F68 = 0;
        }
        lbl_8053AB48 += 2;
        if (lbl_8053AB48 > 200) {
            lbl_8053AB48 = 200;
        }
    }
}

extern "C" s32 fn_80154248(u32 type, u32 owner, const Vec* position, u32 parameter)
{
    return fn_801F8544(fn_801F856C(), type, owner, position, parameter);
}

extern "C" s32 fn_801542AC(u32 type, s32 owner, Actor** output, s32 excludedID)
{
    return fn_801F7818(fn_801F856C(), type, owner, output, excludedID);
}

extern "C" s32 fn_80154310(u32 type, u32 owner, const Vec* position, u32 parameter,
                          s32 arg6, s32 arg7)
{
    return Actor_CreateByID(fn_801F856C(), type, owner, position, parameter, arg6, arg7);
}

extern "C" f32 fn_8015436C(f32 value)
{
    f64 result = __fabs((f64)value);
    return (f32)result;
}

extern "C" f32 fn_80154378(f32 value)
{
    if (value > lbl_8053D258) {
        f64 guess = __frsqrte(value);
        guess = lbl_8053D2F8 * guess * (lbl_8053D300 - guess * guess * value);
        guess = lbl_8053D2F8 * guess * (lbl_8053D300 - guess * guess * value);
        guess = lbl_8053D2F8 * guess * (lbl_8053D300 - guess * guess * value);
        return value * guess;
    } else if (value < lbl_8053D308) {
        return NAN;
    } else if (isnan(value)) {
        return NAN;
    }
    return value;
}

extern "C" Actor* fn_8015445C(s32 id)
{
    return fn_801F666C(fn_801F856C(), id);
}

extern "C" void fn_80154490(Actor* actor)
{
    *((u8*)actor + 0x2A5) = 1;
}

extern "C" void fn_8015449C(Actor* actor)
{
    ++*(u32*)((u8*)actor + 0x290);
}

extern "C" s32 fn_801544AC(const Actor* actor)
{
    return *(const s32*)((const u8*)actor + 0x28C);
}

extern "C" void fn_801544B4(Actor* actor)
{
    *(s32*)((u8*)actor + 0x290) = -1;
}

extern "C" s32 fn_801544C0(const Actor* actor)
{
    return *(const s32*)((const u8*)actor + 0x288);
}

extern "C" u32 fn_801544C8(const Actor* actor)
{
    return *(const u32*)((const u8*)actor + 0x90);
}

extern "C" void fn_801544D0(Actor* actor, u32 value)
{
    *(u32*)((u8*)actor + 0xD8) = value;
    *(u32*)((u8*)actor + 0xDC) = value;
}

extern "C" Vec* fn_801544DC(Actor* actor)
{
    return (Vec*)((u8*)actor + 0xC);
}

// Direct accesses keep these small wrappers in retail emission order.
extern "C" f32 fn_801544E4(s16 angle)
{
    return JMath::sincosTable_.mTable[(u16)angle >> 5].second;
}

extern "C" f32 fn_801544FC(s16 angle)
{
    return JMath::sincosTable_.mTable[(u16)angle >> 5].first;
}

extern "C" u32 fn_80154510(const Actor* actor)
{
    return *(const u32*)((const u8*)actor + 0x114);
}

extern "C" void fn_80154518(JGeometry::TVec3<f32>* vector, f32 x, f32 y, f32 z)
{
    vector->x = x;
    vector->y = y;
    vector->z = z;
}

extern "C" void fn_80154528(const JGeometry::TBox2<f32>* box,
                           JGeometry::TVec2<f32>* center)
{
    center->x = lbl_8053D2B0 * (box->i.x - box->f.x) + box->f.x;
    center->y = lbl_8053D2B0 * (box->i.y - box->f.y) + box->f.y;
}

extern "C" void fn_80154558(JGeometry::TVec2<f32>* vector,
                           const JGeometry::TVec2<f32>* other)
{
    vector->add(*other);
}

extern "C" void fn_8015457C(JGeometry::TVec2<f32>* vector,
                           const JGeometry::TVec2<f32>* other)
{
    vector->x = other->x;
    vector->y = other->y;
}

extern "C" void fn_80154590(JGeometry::TBox2<f32>* box, f32 x0, f32 y0, f32 x1, f32 y1)
{
    box->i.x = x0;
    box->i.y = y0;
    box->f.x = x1;
    box->f.y = y1;
}

extern "C" void fn_801545A4(JGeometry::TVec3<f32>* vector,
                           const JGeometry::TVec3<f32>* other)
{
    vector->x = other->x;
    vector->y = other->y;
    vector->z = other->z;
}

extern "C" u8 fn_801545C0(Actor* actor, f32* output, u32 flags)
{
    return fn_801F2618(actor, output, flags);
}

extern "C" u32 fn_801545E0(const Actor* actor)
{
    return *(const u32*)((const u8*)actor + 0x9C);
}

extern "C" s32 fn_801545E8(const Actor* actor)
{
    return *(const s32*)((const u8*)actor + 0x198);
}

extern "C" void fn_801545F0(JGeometry::TVec3<f32>* vector,
                           const JGeometry::TVec3<f32>* other)
{
    vector->add(*other);
}

extern "C" void fn_80154614(Actor* actor, u32 value)
{
    *(u32*)((u8*)actor + 0xB8) = value;
}

extern "C" u32 fn_8015461C(const Actor* actor)
{
    return *(const u32*)((const u8*)actor + 4);
}

extern "C" u8 fn_80154624(s32 index)
{
    u8* base = (u8*)fn_802D6A9C();
    return base[0x131DF + index];
}

extern "C" s32 fn_8015465C(f32 y, f32 x)
{
    f32 result = JMath::atanTable_.atan2_(y, x);
    return (s32)(result * lbl_8053D310);
}

extern "C" u8 fn_80154698()
{
    return fn_802DCD0C(fn_802D6A9C());
}

extern "C" void fn_801546BC(JGeometry::TVec3<f32>* vector)
{
    vector->x = vector->y = vector->z = lbl_8053D258;
}

extern "C" void fn_801546D0(JGeometry::TVec3<f32>* vector,
                           const JGeometry::TVec3<f32>* other)
{
    JGeometry::setTVec3f(&other->x, &vector->x);
}

#if defined(VERSION_G4SE01)
JGeometry::TVec2<f32>::TVec2() {
}
#else
JGeometry::TVec2<f32>::TVec2() {
}
#endif

extern "C" void fn_801546E8(JGeometry::TVec2<f32>* vector, f32 x, f32 y)
{
    vector->x = x;
    vector->y = y;
}

extern "C" void fn_801546F4(JGeometry::TBox2<f32>* box,
                           const JGeometry::TBox2<f32>* other)
{
    box->i.x = other->i.x;
    box->i.y = other->i.y;
    box->f.x = other->f.x;
    box->f.y = other->f.y;
}

extern "C" u8 fn_80154718(const Vec* position)
{
    return fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), position);
}

extern "C" f32 fn_80154744()
{
    JMath::TRandom_fast_* random = (JMath::TRandom_fast_*)(lbl_8053AAF8 + 0xB4);
    union {
        u32 bits;
        f32 value;
    } result;
    result.bits = (random->get_bit32() >> 9) | 0x3F800000;
    return result.value - lbl_8053D25C;
}
