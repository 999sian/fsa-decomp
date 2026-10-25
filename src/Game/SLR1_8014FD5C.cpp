#if defined(VERSION_G4SE01)
#define JGEOMETRY_VEC2_OUT_OF_LINE_CTOR
#endif
#include "types.h"
#include "JSystem/JGeometry/Box.h"
#include "JSystem/JMath/JMath.h"
#include "Game/ItemBase.h"
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
extern "C" void fn_801F02BC(void* this_, const char* name, s32 id, DrawRec* rec, s32 a, s32 b, s32 c, f32 s0, f32 s1);
extern char lbl_80465DBC[];
extern char lbl_80465DD0[];
extern "C" void fn_8014FD5C(Actor* actor)
{
    u8* base = (u8*)actor;
    DrawRec rec;
    f32 mtx[3][4];
    s32 flag = 0;
    s32 kind;
    s32 m90;
    s32 m230;
    u16 state;
    f32 sA, sB, cC, cA, cB, sC;

    mtx[0][3] = lbl_8053D258;
    mtx[1][3] = lbl_8053D258;
    mtx[2][3] = lbl_8053D258;

    state = *(u16*)(base + 0x94);
    if (state == 2) {
        return;
    }
    rec.ids[2] = *(u8*)(base + 0x234);
    if (*(s32*)(base + 0x288) != 1 && *(s32*)(base + 0x288) != 3) {
        if (*(s32*)(base + 0x90) == 2 || *(s32*)(base + 0x90) == 3 || *(s32*)(base + 0x90) == 1) {
            rec.ids[8] = *(u8*)(base + 0x234);
        }
        if (*(u16*)(base + 0x94) >= 6 && *(u16*)(base + 0x94) <= 9) {
            rec.ids[2] = 0xb;
        }
        if (*(s32*)(base + 0x230) == 0xe) {
            f32 ang = *(f32*)(base + 0x294);
            f32 s = *(f32*)(base + 0x298);
            sA = sin(lbl_8053D258);
            sB = sin(ang);
            sC = sin(lbl_8053D258);
            cA = cos(lbl_8053D258);
            cB = cos(ang);
            cC = cos(lbl_8053D258);
            mtx[0][0] = s * (cB * cC);
            mtx[1][0] = s * (cB * sC);
            mtx[2][0] = s * -sB;
            mtx[0][1] = s * (sA * sB * cC - cA * sC);
            mtx[1][1] = s * (sA * sB * sC + cA * cC);
            mtx[2][1] = s * (sA * cB);
            mtx[0][2] = s * (cA * cC * sB + sA * sC);
            mtx[1][2] = s * (cA * sC * sB - sA * cC);
            mtx[2][2] = s * (cA * cB);
            rec.w18 = mtx;
            m90 = *(s32*)(base + 0x90);
            if (m90 == 1) {
                fn_801F02BC(actor, lbl_80465DBC, *(s32*)(base + 0x274) + 0x1f4, &rec, 0, 0, 0, lbl_8053D25C, lbl_8053D25C);
                return;
            }
            if (m90 != 2 && m90 != 3) {
                fn_801F02BC(actor, lbl_80465DD0, *(s32*)(base + 0x274) + 0x8f, &rec, 0, 0, 0, lbl_8053D25C, lbl_8053D25C);
                return;
            }
        }
    }

    m90 = *(s32*)(base + 0x90);
    if (m90 != 6) {
        if (*(s32*)(base + 0x288) == 3) {
            mtx[0][0] = *(f32*)(base + 0x54);
            mtx[0][1] = lbl_8053D258;
            mtx[0][2] = lbl_8053D258;
            mtx[1][0] = lbl_8053D258;
            mtx[1][1] = *(f32*)(base + 0x58);
            mtx[1][2] = lbl_8053D258;
            mtx[2][0] = lbl_8053D258;
            mtx[2][1] = lbl_8053D258;
            mtx[2][2] = *(f32*)(base + 0x5c);
            rec.w18 = mtx;
            flag = 1;
        }
    }

    m230 = *(s32*)(base + 0x230);
    if (m230 == 8) {
        s32 x = *(s32*)(base + 0x248);
        kind = 0;
        if (x < 100) {
            if (x >= 50) {
                if ((x & 8) == 0) {
                    kind = 1;
                }
            } else {
                if ((x & 4) == 0) {
                    kind = 1;
                }
            }
        }
        if (kind == 1) {
            *((u8*)&rec + 0x14) = 0x50;
        }
    }
    if (m230 == 9) {
        mtx[0][0] = *(f32*)(base + 0x54);
        mtx[0][1] = lbl_8053D258;
        mtx[0][2] = lbl_8053D258;
        mtx[1][0] = lbl_8053D258;
        mtx[1][1] = *(f32*)(base + 0x58);
        mtx[1][2] = lbl_8053D258;
        mtx[2][0] = lbl_8053D258;
        mtx[2][1] = lbl_8053D258;
        mtx[2][2] = *(f32*)(base + 0x5c);
        rec.w18 = mtx;
    }
}

extern "C" s32 fn_801535B4(Actor* actor)
{
    u8* base = (u8*)actor;
    s32 room = *(s32*)(base + 0x4);
    s16 angle;
    u16 result;

    if (*(u8*)((u8*)fn_802D6A9C() + 0x10000 + room + 0x31DF)) {
        return 0;
    }
    if (*(s32*)(base + 0x230) == 0xE) {
        return 1;
    }
    if (*(f32*)(base + 0x14) > lbl_8053D288) {
        return 0;
    }
    *(f32*)(base + 0x2B8) = *(f32*)(base + 0xC);
    *(f32*)(base + 0x2BC) = *(f32*)(base + 0x10);
    *(f32*)(base + 0x2C0) = *(f32*)(base + 0x14);
    *(f32*)(base + 0x2B8) = (f32)((s32)*(f32*)(base + 0x2B8) & 0xFFF8);
    *(f32*)(base + 0x2BC) = (f32)((s32)*(f32*)(base + 0x2BC) & 0xFFF8);
    angle = fn_801F6874(*(s32*)(base + 0x98));
    *(f32*)(base + 0x2B8) = lbl_8053D314 * *(f32*)((u8*)sincosTable___5JMath + ((u32)(s32)angle >> 2 & 0x3FF8)) + *(f32*)(base + 0x2B8);
    angle = fn_801F6874(*(s32*)(base + 0x98));
    *(f32*)(base + 0x2BC) = lbl_8053D314 * *(f32*)((u8*)sincosTable___5JMath + ((u32)(s32)angle >> 2 & 0x3FF8) + 4) + *(f32*)(base + 0x2BC);
    result = fn_8022461C(base + 0x2B8, *(s32*)(base + 0x4));
    if ((u32)(result - 2) < 2 || result == 0xE) {
        *(s32*)(base + 0x250) = 10000;
        *(s32*)(base + 0x108) = 200;
        *(s32*)(base + 0x280) = 0;
        if (result == 0xE && fn_802DE9A0() == 1) {
            *(s32*)(base + 0x280) = 1;
        }
        *(f32*)(base + 0x44) = lbl_8053D258;
        *(f32*)(base + 0x40) = lbl_8053D258;
        *(f32*)(base + 0x3C) = lbl_8053D258;
        *(f32*)(base + 0x2B4) = lbl_8053D258;
        *(f32*)(base + 0x2B0) = lbl_8053D258;
        *(f32*)(base + 0x2AC) = lbl_8053D258;
        *(s32*)(base + 0xD8) = 0;
        *(s32*)(base + 0xDC) = 0;
        *(s32*)(base + 0x230) = 0xD;
        return 1;
    }
    return 0;
}

#pragma opt_common_subs off
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
#pragma opt_common_subs reset
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

extern const f32 lbl_8053D264;
extern const f32 lbl_8053D284;
extern const f32 lbl_8053D28C;
extern const f32 lbl_8053D2A0;
extern const f32 lbl_8053D318;
extern const f32 lbl_8053D31C;
extern const f32 lbl_8053D26C;
extern const f32 lbl_8053D2C8;
extern const f32 lbl_8053D324;
extern const f32 lbl_8053D2D4;
extern const f32 lbl_8053D260;
extern const f32 lbl_8053D320;
extern const f32 lbl_8053D2DC;
extern const f32 lbl_8053D274;
extern const f32 lbl_8053D27C;
extern const f32 lbl_8053D328;
extern u8 lbl_8049FA40[];
extern u8 lbl_8049FA78[];
extern s32 lbl_8053AB40;
extern u8 lbl_80529DEC[];
extern "C" void fn_80153AA4(Actor* actor)
{
    u8* base = (u8*)actor;
    s32 room;
    s32 m90;
    f32 x18;
    f32 x14;
    f32 x10;
    f32 x0c;
    f32 x08;

    *(f32*)(base + 0x60) = lbl_8053D264;
    *(f32*)(base + 0x64) = lbl_8053D284;
    *(f32*)(base + 0x68) = lbl_8053D28C;
    *(f32*)(base + 0x6c) = lbl_8053D28C;
    *(f32*)(base + 0x70) = lbl_8053D264;
    *(f32*)(base + 0x74) = lbl_8053D264;
    *(f32*)(base + 0x78) = lbl_8053D28C;
    *(f32*)(base + 0x7c) = lbl_8053D28C;
    *(f32*)(base + 0x80) = lbl_8053D264;
    *(f32*)(base + 0x84) = lbl_8053D264;
    *(f32*)(base + 0x88) = lbl_8053D28C;
    *(f32*)(base + 0x8c) = lbl_8053D28C;
    *(u16*)(base + 0x94) = (*(u32*)(base + 0x90) >> 16) & 0xf;
    *(s32*)(base + 0x288) = (*(u32*)(base + 0x90) >> 20) & 0xf;
    *(s32*)(base + 0x280) = 0;
    if (*(u32*)(base + 0x90) & 0x100) {
        *(s32*)(base + 0x280) = 1;
    }
    lbl_804BF850[0] = -1;
    lbl_804BF850[1] = -1;
    lbl_804BF850[2] = -1;
    lbl_804BF850[3] = -1;
    lbl_80539F68 = 200;
    lbl_8053AB48 = 0;
    *(s32*)(base + 0x284) = 0;
    if (!(*(u32*)(base + 0x90) & 0x1000)) {
        *(s32*)(base + 0x284) = 1;
    }
    *(u32*)(base + 0x2a4) = *(u32*)(base + 0x90) >> 24;
    *(s32*)(base + 0x2a8) = 0;
    if (*(s32*)(base + 0x2a4) == 0) {
        *(s32*)(base + 0x2a4) = -1;
    }
    *(s32*)(base + 0x258) = 0;
    *(s32*)(base + 0x25c) = 0;
    *(s32*)(base + 0x260) = 0;
    *(s32*)(base + 0x264) = 0;
    *(s32*)(base + 0x268) = 0;
    *(s32*)(base + 0x26c) = 0;
    *(s32*)(base + 0x270) = 0;
    *(s32*)(base + 0x238) = 0;
    *(s32*)(base + 0x23c) = 0;
    *(s32*)(base + 0x240) = 0;
    *(s32*)(base + 0x244) = 0;
    *(s32*)(base + 0x248) = 0;
    *(s32*)(base + 0x24c) = 0;
    *(s32*)(base + 0x250) = 0;
    *(s32*)(base + 0x254) = 0;
    *(u8*)(base + 0x234) = 5;
    *(s32*)(base + 0x274) = 0;
    *(f32*)(base + 0x294) = lbl_8053D258;
    *(f32*)(base + 0x298) = lbl_8053D25C;
    *(f32*)(base + 0x290) = lbl_8053D2A0;
    *(s32*)(base + 0x27c) = 0;
    *(s16*)(base + 0x29e) = 0;
    if (*(u16*)(base + 0x94) == 1) {
        *(f32*)(base + 0x290) = lbl_8053D318;
    }

    {
        u8* rng = lbl_8053AAF8;
        u32 bits;
        *(u32*)(rng + 0xb4) = *(u32*)(rng + 0xb4) * 0x19660d + 0x3c6ef35f;
        bits = (*(u32*)(rng + 0xb4) >> 9) | 0x3f800000;
        x18 = *(f32*)&bits;
        *(f32*)(base + 0x28c) = lbl_8053D268 * *(f32*)(base + 0x290) + lbl_8053D26C * (x18 - lbl_8053D25C);
    }
    *(f32*)(base + 0x2b4) = lbl_8053D258;
    *(f32*)(base + 0x2b0) = lbl_8053D258;
    *(f32*)(base + 0x2ac) = lbl_8053D258;
    {
        u8* rng = lbl_8053AAF8;
        u32 bits;
        *(u32*)(rng + 0xb4) = *(u32*)(rng + 0xb4) * 0x19660d + 0x3c6ef35f;
        bits = (*(u32*)(rng + 0xb4) >> 9) | 0x3f800000;
        x14 = *(f32*)&bits;
        *(s32*)(base + 0x98) = (s32)(lbl_8053D31C * (x14 - lbl_8053D25C)) & 3;
    }

    room = *(s32*)(base + 0x4);
    {
        u8* tbl = (u8*)fn_802D6A9C() + 0x10000 + room;
        if (*(u8*)(tbl + 0x31DF)) {
            *(s32*)(base + 0x98) = *(s32*)(base + 0x98) & 1;
        }
    }
    *(s32*)(base + 0x238) = 8;
    *(s32*)(base + 0x278) = lbl_8053AB40;
    lbl_8053AB40 = lbl_8053AB40 + 1;
    *(s16*)(base + 0x29c) = -1;
    *(s32*)(base + 0xb0) = 0x12205;
    *(s32*)(base + 0xbc) = 2;
    *(s32*)(base + 0x90) = *(s32*)(base + 0x90) & 7;
    *(s16*)(base + 0x2a0) = 0;
    *(s32*)(base + 0x190) = 4;
    *(s32*)(base + 0x108) = *(s32*)(lbl_8049FA40 + (*(s32*)(base + 0x90) << 3));
    *(u8*)(base + 0x234) = (u8)*(s32*)(lbl_8049FA40 + (*(s32*)(base + 0x90) << 3) + 4);
    *(s32*)(base + 0xb8) = 1;

    if (*(u16*)(base + 0x94) == 2 || *(u16*)(base + 0x94) == 5 || *(u16*)(base + 0x94) == 3) {
        *(s32*)(base + 0xb0) = 0;
        *(s32*)(base + 0xb8) = 0;
        *(s32*)(base + 0x98) = 2;
        *(s32*)(base + 0x274) = *(s32*)(lbl_8049FA78 + (*(s32*)(base + 0x98) << 5));
    }
    m90 = *(s32*)(base + 0x90);
    if ((u32)m90 == 2) {
        goto lab_s5;
    }
    if ((u32)m90 == 3) {
        goto lab_s5;
    }
    if ((u32)m90 == 1) {
        goto lab_s5;
    }
    goto lab_after5;
lab_s5:
    *(s32*)(base + 0x190) = 5;
lab_after5:

    m90 = *(s32*)(base + 0x90);
    if (m90 < 4) {
        if (m90 == 1) {
            goto lab_m1;
        }
        if (m90 >= 1) {
            goto lab_230;
        }
        if (m90 >= 0) {
            goto lab_0x62209;
        }
        goto lab_230;
    } else {
        if (m90 == 6) {
            goto lab_m6;
        }
        if (m90 >= 6) {
            goto lab_230;
        }
        goto lab_0x62209;
    }

lab_m6:
    {
        u8* rng = lbl_8053AAF8;
        u32 bits;
        *(u32*)(rng + 0xb4) = *(u32*)(rng + 0xb4) * 0x19660d + 0x3c6ef35f;
        bits = (*(u32*)(rng + 0xb4) >> 9) | 0x3f800000;
        x10 = *(f32*)&bits;
        *(f32*)(base + 0x28c) = lbl_8053D26C * (x10 - lbl_8053D25C) + *(f32*)(base + 0x290);
    }
    *(s32*)(base + 0xbc) = 3;
    *(s32*)(base + 0xc0) = 3;
    *(s32*)(base + 0x284) = 0;
    *(f32*)(base + 0x54) = lbl_8053D268;
    *(f32*)(base + 0x58) = lbl_8053D268;
    *(f32*)(base + 0x5c) = lbl_8053D268;
    *(s32*)(base + 0x190) = 6;
    *(s32*)(base + 0xb0) = 0x62209;
    *(f32*)(base + 0x70) = lbl_8053D260;
    *(f32*)(base + 0x74) = lbl_8053D264;
    *(f32*)(base + 0x78) = lbl_8053D320;
    *(f32*)(base + 0x7c) = lbl_8053D320;
    *(s32*)(base + 0x230) = 0xb;
    goto lab_1449c;

lab_m1:
    *(s32*)(base + 0xb8) = 0;
    *(s32*)(base + 0x98) = 2;
    *(s32*)(base + 0x274) = 0xc;
    lbl_8053AB44 = 0;
    *(s32*)(base + 0x230) = 0xc;
    goto lab_1449c;

lab_0x62209:
    *(s32*)(base + 0xb0) = 0x62209;
lab_230:
    *(s32*)(base + 0x230) = 1;
    if (*(s32*)(lbl_80529DEC + 0x118) == 0 && *(s32*)(lbl_80529DEC + 0x11c) == 0 &&
        *(s32*)((u8*)fn_802D6A9C() + 0x18) == 2 && *(s32*)((u8*)fn_802D6A9C() + 0x14) == 2) {
        if ((s32)(lbl_8053D2D4 * *(f32*)(base + 0xc)) == 0x68 &&
            (s32)(lbl_8053D2D4 * *(f32*)(base + 0x10)) == 0x57) {
            u8* rng = lbl_8053AAF8;
            u32 bits;
            *(u32*)(rng + 0xb4) = *(u32*)(rng + 0xb4) * 0x19660d + 0x3c6ef35f;
            bits = (*(u32*)(rng + 0xb4) >> 9) | 0x3f800000;
            x08 = *(f32*)&bits;
            *(s32*)(base + 0x23c) = (s32)(lbl_8053D2C8 * (x08 - lbl_8053D25C)) + 0x6e;
            *(f32*)(base + 0x290) = lbl_8053D324;
            *(s32*)(base + 0x98) = 0;
            switch (*(s32*)(base + 0x98)) {
            case 0: {
                f32 v = *(f32*)(base + 0x290);
                *(f32*)(base + 0x2ac) = v;
                *(f32*)(base + 0x2b0) = lbl_8053D258;
                *(f32*)(base + 0x2b4) = lbl_8053D258;
                break;
            }
            case 1: {
                f32 v = *(f32*)(base + 0x290);
                *(f32*)(base + 0x2ac) = -v;
                *(f32*)(base + 0x2b0) = lbl_8053D258;
                *(f32*)(base + 0x2b4) = lbl_8053D258;
                break;
            }
            case 2: {
                f32 v = *(f32*)(base + 0x290);
                *(f32*)(base + 0x2ac) = lbl_8053D258;
                *(f32*)(base + 0x2b0) = v;
                *(f32*)(base + 0x2b4) = lbl_8053D258;
                break;
            }
            case 3: {
                f32 v = *(f32*)(base + 0x290);
                *(f32*)(base + 0x2ac) = lbl_8053D258;
                *(f32*)(base + 0x2b0) = -v;
                *(f32*)(base + 0x2b4) = lbl_8053D258;
                break;
            }
            }
            *(f32*)(base + 0x10) = *(f32*)(base + 0x10) - lbl_8053D328;
            *(s32*)(base + 0x230) = 0;
            goto lab_1449c;
        }
        *(s32*)(base + 0x270) = 1;
    }

lab_1449c:
    if (*(s32*)(base + 0x288) == 1 || *(s32*)(base + 0x288) == 3) {
        *(f32*)(base + 0x70) = lbl_8053D264;
        *(f32*)(base + 0x74) = lbl_8053D264;
        *(f32*)(base + 0x78) = lbl_8053D28C;
        *(f32*)(base + 0x7c) = lbl_8053D28C;
        if (*(s32*)(base + 0x288) == 3) {
            *(f32*)(base + 0x70) = lbl_8053D260;
            *(f32*)(base + 0x74) = lbl_8053D264;
            *(f32*)(base + 0x78) = lbl_8053D320;
            *(f32*)(base + 0x7c) = lbl_8053D320;
            *(f32*)(base + 0x54) = lbl_8053D268;
            *(f32*)(base + 0x58) = lbl_8053D268;
            *(f32*)(base + 0x5c) = lbl_8053D268;
        }
        *(u32*)(base + 0xb0) = 0xa042004;
        *(u8*)(base + 0x234) = 2;
        *(s32*)(base + 0xb8) = 0;
        *(s32*)(base + 0x18c) = 0;
        {
            u8* rng = lbl_8053AAF8;
            u32 bits;
            *(u32*)(rng + 0xb4) = *(u32*)(rng + 0xb4) * 0x19660d + 0x3c6ef35f;
            bits = (*(u32*)(rng + 0xb4) >> 9) | 0x3f800000;
            x0c = *(f32*)&bits;
            *(s32*)(base + 0x238) = (s32)(lbl_8053D2DC * (x0c - lbl_8053D25C)) + 0x3c;
        }
        *(s32*)(base + 0x274) = 0x10;
        *(s32*)(base + 0x230) = 0x11;
    }
    if (*(s32*)(base + 0x2a4) >= 0) {
        if (*(u16*)(base + 0x94) >= 6 && *(u16*)(base + 0x94) <= 9) {
            *(u32*)(base + 0xb0) = 0xa040004;
            *(s32*)(base + 0x98) = *(u16*)(base + 0x94) - 6;
            *(s32*)(base + 0x25c) = *(s32*)(base + 0x98);
            *(s32*)(base + 0x274) = *(s32*)(lbl_8049FA78 + (((*(s32*)(base + 0x98) << 3) + *(s32*)(base + 0x258)) << 2));
            if (*(s32*)(base + 0x288) == 1 || *(s32*)(base + 0x288) == 3) {
                *(s32*)(base + 0x274) = (*(s32*)(base + 0x98) << 2) + (*(s32*)(base + 0x258) & 3);
            }
            *(f32*)(base + 0x80) = lbl_8053D274;
            *(f32*)(base + 0x84) = lbl_8053D274;
            *(f32*)(base + 0x88) = lbl_8053D27C;
            *(f32*)(base + 0x8c) = lbl_8053D27C;
            *(s32*)(base + 0xb8) = 0;
        }
        *(s32*)(base + 0x230) = 0xf;
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
#pragma dont_inline on
#pragma force_active on
template <>
JGeometry::TVec2<f32>::TVec2() {
}
#pragma force_active reset
#pragma dont_inline reset
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
#include "JSystem/JAudio/JASFakeMatchFSA.h"
