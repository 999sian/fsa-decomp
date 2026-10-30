// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 80197070-8019D12C (unknown). Remaining functions are not yet decompiled.
#include "types.h"
#include "std/math.h"
#include "JSystem/JGeometry/Vec.h"
#include "Game/ItemBase.h"
#include "JSystem/JParticle/JPAEmitter.h"

#if defined(VERSION_G4SP01)
extern "C" const f32 lbl_8053E3EC;
#endif

// from src/Game/Actor_SetVec2_0x0.cpp
// Unnamed actor cluster, part 7/9. fn_8019C4F4 - trivial 2-float setter
// (0x0/0x4), no extab.
extern "C" {

extern "C" void fn_801F71A4(f32* p, f32 target, f32 a, f32 b);
extern "C" const f32 lbl_8053E370;
extern "C" const f32 lbl_8053E374;
extern "C" const f32 lbl_8053E378;
extern "C" const f32 lbl_8053E37C;
extern "C" const f32 lbl_8053E380;
extern "C" const f32 lbl_8053E384;
extern "C" const f32 lbl_8053E388;
extern "C" const f32 lbl_8053E38C;
extern "C" const f32 lbl_8053E390;
extern "C" const f32 lbl_8053E394;
extern "C" const f64 lbl_8053E398;
extern "C" s32 lbl_8053ABA0;
extern "C" s32 lbl_8053ABA4;
extern "C" u8 lbl_8053ABA8;
extern "C" u8 lbl_8053AB98;
extern "C" s32 lbl_8053AB9C;
extern "C" const f32 lbl_8053E3E8;
extern "C" const f32 lbl_8053E434;
extern "C" const f32 lbl_8053E438;
extern "C" const f32 lbl_8053E43C;
extern "C" void* lbl_8053AF80;
extern "C" u8 lbl_804A28C4[];
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D7440(void* mgr, s32 a);
extern "C" void fn_80458F9C(void* p, s32 a);
extern "C" void* fn_801F856C(void);
extern "C" s32 Actor_CreateByID(void* mgr, u32 id, s32 room, void* pos, s32 a, s32 b, s32 c);
extern "C" void* fn_801F666C(void* mgr, s32 id);
extern "C" const u16 lbl_804A28FC[];
extern "C" void* fn_8013C824(void);
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void* mgr, void* emitter);
extern "C" s32 fn_8013CC50(u32 id, void* pos, f32 scale, s32 a, s32 b, s32 c, s32 d, s32 e, s32 g);
extern "C" char* lbl_8053AB10;
extern "C" void fn_8030C210(void* p, JGeometry::TVec3<f32>* v);
extern "C" void fn_80198828(u8*);
extern "C" void fn_80197EB0(u8*);
extern "C" void fn_801979C4(u8*);
extern "C" void fn_801976E8(u8*);
extern "C" void fn_801F06F0(u8* a, void* p2, void* p3, const void* p4, void* p5, f32 f6, f32 f7);
extern "C" void fn_801F02BC(u8* a, void* p2, void* p3, void* p4, void* p5, s32 p6, s32 p7, f32 f8, f32 f9);
extern "C" void fn_801EF830(s32 idx, f32* pos, u8* p3, u32 mask, u8* p5, u32 p6, u8* p7);

struct UnkDrawRec {
    u8 field_00[0x10];
    u32 field_10;
    u32 field_14;
    u32 field_18;
    u8 field_1C;
    u8 field_1D;
    u8 field_1E;
    u8 field_1F;
    u8 field_20;
    u8 field_21;
    u8 field_22;
    u8 field_23;
    u8 field_24;
    u8 field_25;
    u8 field_26;
    s32 field_28;
    u8 field_2C;
    u8 field_2D;
    u8 field_2E;
    s32 field_30;
    s32 field_34;
    s32 field_38;
};

static const s32 drawIndices0[6] = {0x1d0, 0x1e2, 0x1d6, 0x1dc, 0x1e8, 0x1ee};
static const s32 drawIndices1[6] = {0x17f, 0x1cd, 0x199, 0x1b3, 0x1e7, 0x201};
static const char drawName0[] = "enemy_both2_sob.bin";
static const char drawName1[] = "enemy_gc_sob.bin";

extern u8 lbl_80468428[];
extern "C" void fn_80197070(u8* this_) {
    switch (*(s32*)(this_ + 0x90)) {
    case 0: {
        DrawRec local;
        u32 idx = 0x9b;
        s32 p5 = 7;
        if (*(s32*)(this_ + 0x23c) == 0 || (*(u32*)(this_ + 0x23c) & 2) != 0) {
            local.b1f = 0;
            if (*(u8*)(this_ + 0x268) == 1) {
                idx = 0x274;
            }
            if (*(s32*)(this_ + 0x230) == 0x15) {
                p5 = -1;
            }
            fn_801F06F0(this_, (u8*)drawName0, (void*)(idx + *(s32*)(this_ + 0x254)), &local, (void*)p5,
                        lbl_8053E370, lbl_8053E370);
        }
        break;
    }
    case 2: {
        if (*(s32*)(this_ + 0x24c) == 0) {
            DrawRec local;
            local.b1d = 5;
            local.w30 = 0x11;
            s32 total = *(s32*)(this_ + 0x254) + drawIndices0[*(u16*)(this_ + 0x94)];
            fn_801F02BC(this_, (u8*)drawName0, (void*)total, &local, (void*)-1, 0, 0, lbl_8053E370, lbl_8053E370);
            ((u8*)&local.w10)[3] = (u8)(s32)*(f32*)(this_ + 0x270);
            total = *(s32*)(this_ + 0x254) + drawIndices0[*(u16*)(this_ + 0x94)];
        if (*(u32*)(this_ + 0x138) == 0) {
                fn_801EF830(*(s32*)(this_ + 4), (f32*)(this_ + 0xc), (u8*)&local, 0x407, (u8*)drawName0,
                            total, 0);
            }
        }
        break;
    }
    case 3: {
        DrawRec local;
        local.b1f = 0;
        local.b1d = 5;
        s32 total = *(s32*)(this_ + 0x254) + drawIndices1[*(u16*)(this_ + 0x94)];
        fn_801F06F0(this_, (u8*)drawName1, (void*)total, &local, (void*)-1, lbl_8053E370, lbl_8053E370);
        ((u8*)&local.w10)[3] = (u8)(s32)*(f32*)(this_ + 0x270);
        total = *(s32*)(this_ + 0x254) + drawIndices1[*(u16*)(this_ + 0x94)];
        if (*(u32*)(this_ + 0x138) == 0) {
            fn_801EF830(*(s32*)(this_ + 4), (f32*)(this_ + 0xc), (u8*)&local, 0x407, (u8*)drawName1,
                        total, 0);
        }
        break;
    }
    }
}

extern "C" void fn_80197550(u8* this_) {
    JGeometry::TVec3<f32> pos = *(JGeometry::TVec3<f32>*)(this_ + 0xc);
    *(s32*)(this_ + 0x108) = 10000;
    fn_801F71A4((f32*)(this_ + 0x3c), *(f32*)(this_ + 0x274), lbl_8053E374, lbl_8053E370);
    fn_801F71A4((f32*)(this_ + 0x40), *(f32*)(this_ + 0x278), lbl_8053E374, lbl_8053E370);
    fn_801F71A4((f32*)(this_ + 0x14), *(f32*)(this_ + 0x26c), lbl_8053E374, lbl_8053E370);
    ((JGeometry::TVec3<f32>*)(this_ + 0xc))->add(*(JGeometry::TVec3<f32>*)(this_ + 0x3c));
    switch (*(s32*)(this_ + 0x90)) {
    case 0:
        fn_80198828(this_);
        break;
    case 1:
        fn_80197EB0(this_);
        break;
    case 2:
        fn_801979C4(this_);
        pos.x += lbl_8053E378;
        pos.y -= lbl_8053E37C;
        break;
    case 3:
        fn_801976E8(this_);
        pos.x += lbl_8053E378;
        pos.y -= lbl_8053E37C;
        break;
    }
    fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), &pos);
    for (s32 i = 0; i < 4; i++) {
        s32* t = (s32*)(this_ + i * 4);
        if (t[0x234 / 4] > 0) {
            t[0x234 / 4]--;
        }
    }
}

extern "C" void fn_801976E8(u8* this_) {
    s32 base = *(u16*)(this_ + 0x94) * 6;
    s32 i;
    u8* p;
    fn_801F71A4((f32*)(this_ + 0x270), lbl_8053E380, lbl_8053E374, lbl_8053E384);
    switch (*(s32*)(this_ + 0x230)) {
    case 0x4f:
        lbl_8053ABA0++;
        *(s32*)(this_ + 0x230) = 0x4f;
    case 0x50:
        if (*(s32*)(this_ + 0x234) == 0) {
            *(s32*)(this_ + 0x234) = 9;
            *(s32*)(this_ + 0x254) = *(s32*)(this_ + 0x254) + 1;
            if (*(s32*)(this_ + 0x254) > 5) *(s32*)(this_ + 0x254) = 0;
        }
        if (lbl_8053ABA4 == 2) {
            for (i = 0, p = this_; i < 6; i++, p += 4) {
                if ((u32)i <= 1 || i == 5) {
                    if (*(u32*)(p + 0x304) == 0) {
                        *(s32*)(p + 0x304) = fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, lbl_8053E370, lbl_804A28FC[base + i], 0, 5, 0, 0, 1);
                    }
                } else {
                    fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, lbl_8053E370, lbl_804A28FC[base + i], 0, 5, 0, 0, 1);
                }
            }
            *(s32*)(this_ + 0x238) = 0x1e0;
            *(s32*)(this_ + 0x230) = 0x51;
        }
        break;
    case 0x51:
        if (*(s32*)(this_ + 0x234) == 0) {
            *(s32*)(this_ + 0x234) = 9;
            *(s32*)(this_ + 0x254) = *(s32*)(this_ + 0x254) + 1;
            if (*(s32*)(this_ + 0x254) > 5) *(s32*)(this_ + 0x254) = 0;
        }
        if (*(s32*)(this_ + 0x238) == 0) {
            lbl_8053ABA4 = 3;
            *(s32*)(this_ + 0x230) = 0x52;
        }
        break;
    case 0x52:
        if (lbl_8053ABA4 == 4) {
            *(f32*)(this_ + 0x26c) = lbl_8053E388;
            *(f32*)(this_ + 0x14) = lbl_8053E388;
            for (i = 0; i < 6; i++) {
                if (*(u32*)(this_ + 0x304 + i * 4) != 0) {
                    void* manager = *(void**)((u8*)fn_8013C824() + 0xc);
                    forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(manager, *(void**)(this_ + 0x304 + i * 4));
                    *(s32*)(this_ + 0x304 + i * 4) = 0;
                }
            }
        }
        if (lbl_8053ABA4 == 5) {
            *(f32*)(this_ + 0x10) = *(f32*)(this_ + 0x284) - lbl_8053E38C;
            *(f32*)(this_ + 0xc) = *(f32*)(this_ + 0x280);
            *(f32*)(this_ + 0xc) = lbl_8053E390 * (lbl_8053E394 - (f32)*(u16*)(this_ + 0x94)) + *(f32*)(this_ + 0xc);
            *(s32*)(this_ + 0x254) = 8;
        } else if (*(s32*)(this_ + 0x234) == 0) {
            *(s32*)(this_ + 0x234) = 9;
            *(s32*)(this_ + 0x254) = *(s32*)(this_ + 0x254) + 1;
            if (*(s32*)(this_ + 0x254) > 5) *(s32*)(this_ + 0x254) = 0;
        }
        break;
    }
}

extern "C" void fn_8013CB44(void*, void*, s32, s32, s32);
extern "C" s32 fn_801F0E34(void*, u32, u32);
extern "C" const u16 lbl_804A2880[];
extern "C" const u16 lbl_804A28D8[][3];
extern "C" const f32 lbl_8053E3A0;
static inline void orbitPoint(f32& x, f32& y, const u8* p, const s16 angle, const f32 radius) {
    f32 cosine;
    f32 sine;
    x = *(const f32*)(p + 0x280);
    y = *(const f32*)(p + 0x284);
    sine = JMASinShort(angle);
    cosine = JMACosShort(angle);
    x += radius * sine;
    y += radius * cosine;
}
extern "C" const f32 lbl_8053E3A4;
extern "C" const f32 lbl_8053E3A8;
extern "C" void fn_801979C4(u8* p) {
    f32 cosine;
    f32 sine;
    f32 y;
    f32 x;
    s32 id;
    for (s32 i = 0; i < 13; i++) {
        fn_8013CB44(*(void**)(p + 0x304 + i * 4), p + 0xc, 0, 4, 1);
    }
    *(s32*)(p + 0x254) += 1;
    if (*(s32*)(p + 0x254) > 5) *(s32*)(p + 0x254) = 0;
    switch (*(s32*)(p + 0x230)) {
    case 0x4a:
        *(f32*)(p + 0x26c) = lbl_8053E38C;
        *(s32*)(p + 0x230) = 0x4a;
    case 0x4b:
        if ((f32)fabs(*(f32*)(p + 0x26c) - *(f32*)(p + 0x14)) < lbl_8053E370) {
            fn_801F0E34(p, 0x50009, 0);
            *(s32*)(p + 0x230) = 0x4c;
        }
        break;
    case 0x4c: {
        u16 angle = lbl_804A2880[*(u16*)(p + 0x94)];
        x = *(f32*)(p + 0x280);
        y = *(f32*)(p + 0x284);
        cosine = JMACosShort(angle);
        sine = JMASinShort(angle);
        x += lbl_8053E3A0 * sine;
        y += lbl_8053E3A0 * cosine;
        x -= *(f32*)(p + 0xc);
        y -= *(f32*)(p + 0x10) - *(f32*)(p + 0x14);
        f32 direction = JMAAtan2Radian(x, y);
        s16 shortDir = direction * lbl_8053E3A4;
        *(f32*)(p + 0x274) = lbl_8053E3A8 * JMASinShort(shortDir);
        direction = JMAAtan2Radian(x, y);
        shortDir = direction * lbl_8053E3A4;
        *(f32*)(p + 0x278) = lbl_8053E3A8 * JMACosShort(shortDir);
        if (std::sqrtf(x * x + y * y) < lbl_8053E3A8) {
            lbl_8053ABA0++;
            *(s32*)(p + 0x230) = 0x4d;
            *(f32*)(p + 0x27c) = lbl_8053E388;
            *(f32*)(p + 0x278) = lbl_8053E388;
            *(f32*)(p + 0x274) = lbl_8053E388;
            *(f32*)(p + 0x44) = lbl_8053E388;
            *(f32*)(p + 0x40) = lbl_8053E388;
            *(f32*)(p + 0x3c) = lbl_8053E388;
        }
        break;
    }
    case 0x4d:
        if (lbl_8053ABA4 == 1) {
            s32 index = *(u16*)(p + 0x94) * 3;
            fn_8013CC50(*(u32*)(p + 4), p + 0xc, lbl_8053E370, ((const u16*)((const u8*)lbl_804A28D8 + 0))[index], 0, 5, 0, 0, 1);
            fn_8013CC50(*(u32*)(p + 4), p + 0xc, lbl_8053E370, ((const u16*)((const u8*)lbl_804A28D8 + 2))[index], 0, 5, 0, 0, 1);
            fn_8013CC50(*(u32*)(p + 4), p + 0xc, lbl_8053E370, ((const u16*)((const u8*)lbl_804A28D8 + 4))[index], 0, 5, 0, 0, 1);
            *(s32*)(p + 0x248) = 0;
            *(s32*)(p + 0x230) = 0x4e;
        }
        break;
    case 0x4e:
        *(s32*)(p + 0x248) += 1;
        fn_801F0E34(p, 0x5000b, 0);
        fn_801F71A4((f32*)(p + 0x270), lbl_8053E388, lbl_8053E374, lbl_8053E384);
        if (*(s32*)(p + 0x248) == 60) {
            *(s32*)(p + 0x24c) = 1;
            u8* e = *(u8**)(p + 0x304);
            if (e) {
                *(u32*)(e + 0xf4) |= 1;
                *(s32*)(e + 0x24) = 1;
                *(void**)(p + 0x304) = 0;
            }
            e = *(u8**)(p + 0x308);
            if (e) {
                *(u32*)(e + 0xf4) |= 1;
                *(s32*)(e + 0x24) = 1;
                *(void**)(p + 0x308) = 0;
            }
        }
        if (*(s32*)(p + 0x248) == 330) {
            id = Actor_CreateByID(fn_801F856C(), 0x5a4c4432, *(s32*)(p + 4), p + 0xc, (*(u16*)(p + 0x94) << 4) | 3, -1, -1);
            if (id >= 0) {
                u8* child = (u8*)fn_801F666C(fn_801F856C(), id);
                if (child) {
                    *(f32*)(child + 0x280) = *(f32*)(p + 0x280);
                    *(f32*)(child + 0x284) = *(f32*)(p + 0x284);
                    *(f32*)(child + 0x288) = *(f32*)(p + 0x288);
                }
            }
            *(u8*)(p + 0x11c) = 0;
        }
        break;
    }
}

extern "C" u8 fn_801F6758(f32* p, f32 r, s32 room);

extern "C" const f32 lbl_8053E3C8;
extern "C" const f32 lbl_8053E3CC;
extern "C" const f32 lbl_8053E3D0;
extern "C" const f32 lbl_8053E3D4;
extern "C" const f32 lbl_8053E3D8;
extern "C" void lbl_80529DEC();
extern "C" int fn_8022F514(int);
extern "C" int fn_8022F3DC(int);
static inline void orbitSqrt(f32& squared)
{
if (squared > 0.0f) {
                    f64 guess = __frsqrte((f64)squared);
                    guess = 0.5 * guess * (3.0 - guess*guess*squared);
                    guess = 0.5 * guess * (3.0 - guess*guess*squared);
                    guess = 0.5 * guess * (3.0 - guess*guess*squared);
                    squared = (f32)(squared * guess);
                } else if (squared < 0.0) {
                    squared = NAN;
                } else if (isnan(squared)) {
                    squared = NAN;
                }
}
static inline void captureOrbitTarget(u8* p) {
    s32 id = *(s32*)(p + 0x25c);
    if (id >= 0) {
        u8* target = (u8*)fn_801F666C(fn_801F856C(), id);
        if (target && *(s32*)(p + 0x250) != 0) {
            f32 x = *(f32*)(target + 0xc) - *(f32*)(p + 0xc);
            f32 y = *(f32*)(target + 0x10) - *(f32*)(p + 0x10);
            f32 distance = std::sqrtf(x*x + y*y);
            if (*(s32*)(p + 0x250) >= 1 && distance <= lbl_8053E3D4) {
                *(u16*)(target + 0x94) = 5;
                --*(s32*)(p + 0x250);
                if (*(s32*)(p + 0x250) < 0) *(s32*)(p + 0x250) = 0;
                if ((u8)fn_8022F514(*(s32*)(p + 0x250))) {
                    *(s32*)((u8*)lbl_80529DEC + 0x1a4) = fn_8022F3DC(*(s32*)(p + 0x250));
                } else {
                    *(s32*)((u8*)lbl_80529DEC + 0x1a4) = *(s32*)(p + 0x250);
                }
                *(s32*)(p + 0x238) = 50;
                *(s32*)(p + 0x230) = 0x49;
                if (*(void**)(p + 0x304)) {
                    void* manager = *(void**)((u8*)fn_8013C824() + 0xc);
                    forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(manager, *(void**)(p + 0x304));
                    *(void**)(p + 0x304) = 0;
                }
                if (*(void**)(p + 0x308)) {
                    void* manager = *(void**)((u8*)fn_8013C824() + 0xc);
                    forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(manager, *(void**)(p + 0x308));
                    *(void**)(p + 0x308) = 0;
                }
            } else {
                *(s32*)(p + 0x258) = 0;
            }
        }
    }
}

extern "C" void fn_80197EB0(u8* p)
{
    s32 id;
    u8* target;
    switch (*(s32*)(p + 0x230)) {
    case 0x46:
        *(s32*)(p + 0x230) = 0x47;
    case 0x47: {
        fn_801F0E34(p, 0x30056, 0);
        if (*(s32*)(p + 0x250) == 0 &&
            *(f32*)(p + 0x3c) == lbl_8053E388 &&
            *(f32*)(p + 0x40) == lbl_8053E388) break;
        JPABaseEmitter* e = *(JPABaseEmitter**)(p + 0x30c);
        if (e) {
            e->becomeInvalidEmitter();
            *(void**)(p + 0x30c) = 0;
        }
        if (fn_801F6758((f32*)(p + 0xc), lbl_8053E38C, *(s32*)(p + 4))) {
            *(s32*)(p + 0x258) = 0;
            break;
        }
        id = *(s32*)(p + 0x25c);
        if (id >= 0 && (target = (u8*)fn_801F666C(fn_801F856C(), id)) != 0) {
            f32 x = *(f32*)(target + 0xc) - *(f32*)(p + 0xc);
            f32 y = *(f32*)(target + 0x10) - *(f32*)(p + 0x10);
            f32 squared = x*x + y*y;
            if (std::sqrtf(squared) <= lbl_8053E3C8) {
                *(f32*)(p + 0x27c) = lbl_8053E388;
                *(f32*)(p + 0x278) = lbl_8053E388;
                *(f32*)(p + 0x274) = lbl_8053E388;
                *(f32*)(p + 0x44) = lbl_8053E388;
                *(f32*)(p + 0x40) = lbl_8053E388;
                *(f32*)(p + 0x3c) = lbl_8053E388;
                f32 direction = JMAAtan2Radian(x, y);
                direction *= lbl_8053E3A4;
                *(s32*)(p + 0x248) = (s16)direction + 0x8000;
                orbitSqrt(squared);
                *(s32*)(p + 0x24c) = (s32)squared;
                for (s32 i=0; i<13; ++i) {
                    JPABaseEmitter* emitter = *(JPABaseEmitter**)(p + 0x304 + i*4);
                    if (emitter) {
                        *(f32*)((u8*)emitter + 0xb0) = lbl_8053E3CC;
                        *(f32*)((u8*)emitter + 0xb4) = lbl_8053E3CC;
                    }
                }
                *(f32*)(p + 0x60) = lbl_8053E3D0;
                *(f32*)(p + 0x64) = lbl_8053E3D0;
                *(f32*)(p + 0x68) = lbl_8053E384;
                *(f32*)(p + 0x6c) = lbl_8053E384;
                *(s32*)(p + 0x230) = 0x48;
            }
            captureOrbitTarget(p);
        } else {
            *(s32*)(p + 0x258) = 0;
        }
        break;
    }
    case 0x48:
        fn_801F0E34(p, 0x30056, 0);
        id = *(s32*)(p + 0x25c);
        if (id >= 0 && (target = (u8*)fn_801F666C(fn_801F856C(), id)) != 0) {
            if ((*(u32*)(target + 0xb0) & 0xff) != 0xe) {
                *(s32*)(p + 0x258) = 0;
                break;
            }
            if (*(s32*)(p + 0x250) == 0) {
                fn_801F71A4((f32*)(p + 0xc),
                    *(f32*)(target + 0xc) + (f32)*(s32*)(p + 0x24c)*JMASinShort(*(s32*)(p + 0x248)),
                    lbl_8053E3D8, lbl_8053E384);
                fn_801F71A4((f32*)(p + 0x10),
                    *(f32*)(target + 0x10) + (f32)*(s32*)(p + 0x24c)*JMACosShort(*(s32*)(p + 0x248)),
                    lbl_8053E3D8, lbl_8053E384);
                *(s32*)(p + 0x248) += 0x150;
            } else {
                captureOrbitTarget(p);
            }
        } else {
            *(s32*)(p + 0x258) = 0;
        }
        break;
    case 0x49:
        if (*(s32*)(p + 0x238) == 0) *(s32*)(p + 0x258) = 0;
        break;
    }
    if (*(s32*)(p + 0x258) <= 0) {
        for (s32 i=0; i<13; ++i) {
            JPABaseEmitter* emitter = *(JPABaseEmitter**)(p + 0x304 + i*4);
            if (emitter) {
                emitter->becomeInvalidEmitter();
                *(void**)(p + 0x304 + i*4) = 0;
            }
        }
        *(u8*)(p + 0x11c) = 0;
    } else {
        for (s32 i=0; i<13; ++i) fn_8013CB44(*(void**)(p + 0x304 + i*4), p + 0xc, 1, 5, 1);
    }
}

extern "C" void fn_801F3D94(u8* a, s32 b);
extern "C" s32 fn_801F2DB4(u8* a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_801546BC(void* p);
extern "C" void* fn_8015445C(s32 a);
extern "C" void* fn_801545E8(u8* a);
extern "C" void fn_80198828(u8* this_) {
    JGeometry::TVec3<f32> v;
    JGeometry::TVec2<f32> t;
    fn_801F3D94(this_, 1);
    if (*(s32*)(this_ + 0x23c) == 0) {
        s32 st = *(s32*)(this_ + 0x230);
        if (st == 0x1f || st == 0x21) {
            if (fn_801F2DB4(this_, 0x4e554c4c, 0, 0x4e554c4c, 0) != 0) {
                if (*(s32*)(this_ + 0x108) != 10000) {
                    fn_801546BC(this_ + 0x274);
                    fn_801546BC(this_ + 0x3c);
                    *(s32*)(this_ + 0x230) = 0x25;
                }
            }
        }
    }
}

void fn_8019C4F4(void* thisPtr, f32 a, f32 b) { *(f32*)((char*)thisPtr + 0x0) = a; *(f32*)((char*)thisPtr + 0x4) = b; }

}

// from src/Game/SetField_0xb0.cpp
extern "C" {

// fn_8019CEAC(this, val) - trivial setter for this->0xb0.
void fn_8019CEAC(void* thisPtr, u32 val) {
	*(u32*)((char*)thisPtr + 0xb0) = val;
}

// fn_8019CEB4(this) - trivial getter for this->0xb0.
u32 fn_8019CEB4(void* thisPtr) {
	return *(u32*)((char*)thisPtr + 0xb0);
}

// fn_8019CEBC(this, val) - trivial setter for this->0x28c.
void fn_8019CEBC(void* thisPtr, u32 val) {
	*(u32*)((char*)thisPtr + 0x28c) = val;
}

// fn_8019CEC4(this, val) - trivial setter for this->0x2f8.
void fn_8019CEC4(void* thisPtr, u32 val) {
	*(u32*)((char*)thisPtr + 0x2f8) = val;
}

}

// from src/Game/GlobalMgr_SetByte_0x24d.cpp
// fn_8019CEE8(val) - writes a byte into the global manager struct
// (lbl_80529DEC) at +0x24d. Address-only reference (lis/addi, not
// @sda21) - declared as a zero-arg function to dodge MWCC's small-data-
// eligible heuristic, matching the established fix from fn_802150B8.
extern "C" void lbl_80529DEC();

extern "C" {

void fn_8019CEE8(u8 val) {
	*(u8*)((char*)lbl_80529DEC + 0x24d) = val;
}

// fn_8019CEF8(this, a, b, c) - trivial 3-field setter.
void fn_8019CEF8(void* thisPtr, u32 a, f32 b, u32 c) {
	char* p = (char*)thisPtr;
	*(u32*)(p + 0x250) = a;
	*(f32*)(p + 0x254) = b;
	*(u32*)(p + 0x24c) = c;
}

}

// Small (inline-style) accessors.
extern char* lbl_8053AAF8;
extern "C" void fn_8013670C(void* game, void* a);
struct SaveSlot8050 { u8 pad[0x28]; u32 flags; u8 pad2[0xc8 - 0x2c]; };
struct Save8050 { u8 pad[0x10]; s32 cur; };
extern Save8050 lbl_8050EC80;

extern "C" void fn_8019CD9C(void* a) { fn_8013670C(lbl_8053AAF8, a); }
extern "C" void fn_8019CDC4(s32 a) {
    char* g = lbl_8053AAF8;
    *(u8*)(g + 0x85) = 1;
    *(s32*)(g + 0x74) = 0;
    *(s32*)(g + 0x78) = 0;
    *(s32*)(g + 0x54) = a;
}
extern "C" void fn_8019CDE4(s32 a, s32 b) {
    if (a < 0 || a > 7) return;
    if (b < 0 || b > 3) return;
    ((SaveSlot8050*)((u8*)&lbl_8050EC80 + lbl_8050EC80.cur * 0xc8))->flags |= 1 << (b + a * 4);
}
inline SaveSlot8050* curSlot8050() { return (SaveSlot8050*)((u8*)&lbl_8050EC80 + lbl_8050EC80.cur * 0xc8); }
extern "C" BOOL fn_8019CE40(s32 a, s32 b) {
    if (a < 0 || a > 7) return FALSE;
    if (b < 0 || b > 3) return FALSE;
    return (1 << (b + a * 4)) & curSlot8050()->flags ? TRUE : FALSE;
}
extern "C" void fn_8019CECC(f32* dst, const f32* src) { dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2]; }

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D7440(void* mgr, s32 a);
extern u8 lbl_8053AB98;
extern u8 lbl_8053ABA8;

struct Handles_tu_80197070 { u8 pad[0x304]; void* h[13]; };
// TU_80197070 destructor
extern void* lbl_804A2944[];
extern "C" void* fn_8019C7EC(char* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A2944;
        for (int i = 0; i < 13; i++) {
            fn_801EE434(((Handles_tu_80197070*)this_)->h[i]);
        }
        if (*(s32*)(this_ + 0x90) == 0) {
            fn_802D7440(fn_802D6A9C(), 1);
            lbl_8053AB98 = 0;
            lbl_8053ABA8 = 0;
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_8019C8A4(u8* arg) {
    u8* this_ = arg;
    lbl_8053ABA8 = 0;
    *(f32*)(this_ + 0x60) = lbl_8053E434;
    *(f32*)(this_ + 0x64) = lbl_8053E434;
    *(f32*)(this_ + 0x68) = lbl_8053E438;
    *(f32*)(this_ + 0x6c) = lbl_8053E438;
    *(f32*)(this_ + 0x80) = lbl_8053E434;
    *(f32*)(this_ + 0x84) = lbl_8053E434;
    *(f32*)(this_ + 0x88) = lbl_8053E438;
    *(f32*)(this_ + 0x8c) = lbl_8053E438;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(f32*)(this_ + 0x2ac) = lbl_8053E388;
    *(f32*)(this_ + 0x2a8) = lbl_8053E388;
    *(f32*)(this_ + 0x2a4) = lbl_8053E388;
    *(f32*)(this_ + 0x2dc) = lbl_8053E388;
    *(f32*)(this_ + 0x2d8) = lbl_8053E388;
    *(f32*)(this_ + 0x2d4) = lbl_8053E388;
    *(f32*)(this_ + 0x2b8) = lbl_8053E388;
    *(f32*)(this_ + 0x2b4) = lbl_8053E388;
    *(f32*)(this_ + 0x2b0) = lbl_8053E388;
    *(f32*)(this_ + 0x2e8) = lbl_8053E388;
    *(f32*)(this_ + 0x2e4) = lbl_8053E388;
    *(f32*)(this_ + 0x2e0) = lbl_8053E388;
    *(f32*)(this_ + 0x2c4) = lbl_8053E388;
    *(f32*)(this_ + 0x2c0) = lbl_8053E388;
    *(f32*)(this_ + 0x2bc) = lbl_8053E388;
    *(f32*)(this_ + 0x2f4) = lbl_8053E388;
    *(f32*)(this_ + 0x2f0) = lbl_8053E388;
    *(f32*)(this_ + 0x2ec) = lbl_8053E388;
    *(f32*)(this_ + 0x2d0) = lbl_8053E388;
    *(f32*)(this_ + 0x2cc) = lbl_8053E388;
    *(f32*)(this_ + 0x2c8) = lbl_8053E388;
    *(f32*)(this_ + 0x300) = lbl_8053E388;
    *(f32*)(this_ + 0x2fc) = lbl_8053E388;
    *(f32*)(this_ + 0x2f8) = lbl_8053E388;
    *(s32*)(this_ + 0x25c) = -1;
    *(s32*)(this_ + 0x264) = -1;
    *(f32*)(this_ + 0x27c) = lbl_8053E388;
    *(f32*)(this_ + 0x278) = lbl_8053E388;
    *(f32*)(this_ + 0x274) = lbl_8053E388;
    *(f32*)(this_ + 0x44) = lbl_8053E388;
    *(f32*)(this_ + 0x40) = lbl_8053E388;
    *(f32*)(this_ + 0x3c) = lbl_8053E388;
    *(u16*)(this_ + 0x94) = (*(u32*)(this_ + 0x90) >> 4) & 0xF;
    *(u32*)(this_ + 0x90) = *(u32*)(this_ + 0x90) & 3;
    *(f32*)(this_ + 0x26c) = lbl_8053E388;
    *(f32*)(this_ + 0x270) = lbl_8053E388;
    *(u8*)(this_ + 0x268) = 0;
    *(f32*)(this_ + 0x280) = *(f32*)(this_ + 0xc);
    *(f32*)(this_ + 0x284) = *(f32*)(this_ + 0x10);
    *(f32*)(this_ + 0x288) = *(f32*)(this_ + 0x14);
    *(f32*)(this_ + 0x28c) = *(f32*)(this_ + 0xc);
    *(f32*)(this_ + 0x290) = *(f32*)(this_ + 0x10);
    *(f32*)(this_ + 0x294) = *(f32*)(this_ + 0x14);
    *(f32*)(this_ + 0x298) = *(f32*)(this_ + 0xc);
    *(f32*)(this_ + 0x29c) = *(f32*)(this_ + 0x10);
    *(f32*)(this_ + 0x2a0) = *(f32*)(this_ + 0x14);
    for (int i = 0; i < 13; ++i) {
        *(s32*)(this_ + 0x304 + i * 4) = 0;
    }
    lbl_8053AB9C = 0;
    *(s32*)(this_ + 0xb0) = 0xa040004;
    *(s32*)(this_ + 0x254) = 0;
    *(s32*)(this_ + 0x258) = 5;
    switch (*(s32*)(this_ + 0x90)) {
    case 0:
        *(s32*)(this_ + 0x98) = 2;
        lbl_8053AB98 = 0;
        *(s32*)(this_ + 0x254) = 0x24;
        lbl_8053ABA0 = 0;
        lbl_8053ABA4 = 0;
        fn_802D7440(fn_802D6A9C(), 0);
        fn_80458F9C(lbl_8053AF80, 0x3c);
        {
            s32 id = Actor_CreateByID(fn_801F856C(), 0x4c494d54, *(s32*)(this_ + 4), this_ + 0xc, 0, -1, -1);
            *(s32*)(this_ + 0x260) = id;
            id = *(s32*)(this_ + 0x260);
            if (id >= 0) {
                u8* a = (u8*)fn_801F666C(fn_801F856C(), id);
                if (a != 0) {
                    s32 count = *(s32*)(this_ + 0x258);
                    *(s32*)(a + 0x250) = *(s32*)(this_ + 0x198);
                    *(f32*)(a + 0x254) = lbl_8053E3E8;
                    *(s32*)(a + 0x24c) = count;
                }
            }
        }
        if (*(u32*)(this_ + 0x304) == 0) {
            *(s32*)(this_ + 0x304) = (s32)fn_8013CC50(*(s32*)(this_ + 4), this_ + 0x280, lbl_8053E370, 0x1ca, 0, 0, 0, 0, 1);
        }
        if (*(u32*)(this_ + 0x308) == 0) {
            *(s32*)(this_ + 0x308) = (s32)fn_8013CC50(*(s32*)(this_ + 4), this_ + 0x280, lbl_8053E370, 0x1cb, 0, 0, 0, 0, 1);
        }
        *(f32*)(this_ + 0x10) = *(f32*)(this_ + 0x10) + lbl_8053E43C;
        *(f32*)(this_ + 0xc) = *(f32*)(this_ + 0x280);
        *(s32*)(this_ + 0x230) = 0;
        break;
    case 1:
        *(s32*)(this_ + 0xb0) = 0xa000000;
        if (*(u32*)(this_ + 0x304) == 0) {
            *(s32*)(this_ + 0x304) = (s32)fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, lbl_8053E370, 0x533, 1, 5, 0, 0, 1);
        }
        if (*(u32*)(this_ + 0x308) == 0) {
            *(s32*)(this_ + 0x308) = (s32)fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, lbl_8053E370, 0x534, 1, 5, 0, 0, 1);
        }
        if (*(u32*)(this_ + 0x30c) == 0) {
            *(s32*)(this_ + 0x30c) = (s32)fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, lbl_8053E370, 0x535, 1, 5, 0, 0, 1);
        }
        *(s32*)(this_ + 0x230) = 0x46;
        break;
    case 2:
        *(f32*)(this_ + 0x270) = lbl_8053E380;
        if (*(u32*)(this_ + 0x304) == 0) {
            *(s32*)(this_ + 0x304) = (s32)fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, lbl_8053E370, 0x32c, 0, 4, 0, 0, 1);
            u8 (*colors)[3] = (u8 (*)[3])lbl_804A28C4;
            u16 index = *(u16*)(this_ + 0x94);
            JPABaseEmitter* e = *(JPABaseEmitter**)(this_ + 0x304);
            e->setGlobalEnvColor(colors[index][0], colors[index][1], colors[index][2]);
        }
        if (*(u32*)(this_ + 0x308) == 0) {
            *(s32*)(this_ + 0x308) = (s32)fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, lbl_8053E370, 0x184, 0, 4, 0, 0, 1);
            u8 (*colors)[3] = (u8 (*)[3])lbl_804A28C4;
            u16 index = *(u16*)(this_ + 0x94);
            JPABaseEmitter* e = *(JPABaseEmitter**)(this_ + 0x308);
            e->setGlobalEnvColor(colors[index][0], colors[index][1], colors[index][2]);
        }
        *(s32*)(this_ + 0x230) = 0x4a;
        break;
    case 3:
        *(f32*)(this_ + 0x26c) = *(f32*)(this_ + 0x14);
        *(s32*)(this_ + 0x234) = 9;
        *(s32*)(this_ + 0x230) = 0x4f;
        break;
    }
}

struct Vec_8019 { f32 x, y, z; };
extern "C" u8 fn_8023F264(s32 i);
extern "C" s32 fn_8023DE58(s32 i);
extern "C" void fn_80230498(s32 i, Vec_8019* pos, s32 a, s32 b, s32 c, s32 d, s32 e);
struct Pos_8019 { u32 vt; s32 id; u8 pad[0x2a4 - 8]; Vec_8019 p[4]; };

#if defined(VERSION_G4SP01)
#pragma opt_propagation off
extern "C" void fn_8019C500(char* obj, int flag)
{
    char* p;
    int i;
    int id;
    float v[3];
    i = 0;
    p = obj;
    do {
        if (!fn_8023F264(i)) goto next;
        id = *(int*)(obj + 4);
        if (id != fn_8023DE58(i)) goto next;
        {
                v[0] = *(float*)(p + 0x2a4);
                v[1] = *(float*)(p + 0x2a8);
                v[2] = *(float*)(p + 0x2ac);
                if (flag == 0) {
                    v[1] = lbl_8053E3EC + *(float*)(obj + 0x10);
                }
                fn_80230498(i, (Vec_8019*)v, 0x3f, 0xff, -0x80, -0x80, 1);
        }
next:
        i++;
        p += 0xc;
    } while (i < 4);
}
#pragma opt_propagation reset
#else
extern "C" void fn_8019C500(Pos_8019* this_, s32 flag) {
    s32 id;
    Pos_8019* p;
    int i;
    Vec_8019 pos;
    p=this_;
    for(i=0;i<4;i++,p=(Pos_8019*)((char*)p+12)) {
        if(fn_8023F264(i)) {
            id=this_->id;
            if(id==fn_8023DE58(i)) {
                pos.x=p->p[0].x;
                pos.y=p->p[0].y;
                pos.z=p->p[0].z;
                if(flag==0)pos.y=32.0f+*(f32*)((char*)this_+0x10);
                fn_80230498(i,&pos,0x3f,0xff,-0x80,-0x80,1);
            }
        }
    }
}
#endif

extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* mgr, s32 idx);
extern "C" void* fn_8013C824(void);
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void* mgr, void* emitter);
extern "C" s32 fn_8013CC50(u32 id, void* pos, f32 scale, s32 a, s32 b, s32 c, s32 d, s32 e, s32 g);
extern "C" void fn_8013CB44(void* obj, void* pos, s32 a, s32 b, s32 c);
extern "C" s32 lbl_8053A100;
extern "C" const f32 lbl_8053E370;
extern "C" const f32 lbl_8053E388;

extern "C" void fn_8019C5B8(u8* this_) {
    if (*(s32*)(this_ + 0x90) == 1 && *(s32*)(this_ + 0x230) != 0x49) {
        u8* src = (u8*)fn_801F666C(fn_801F856C(), *(s32*)(this_ + 0x25c));
        if (src != 0) {
            s32 idx = *(s32*)(this_ + 0xa0);
            if (idx >= 0) {
                src = (u8*)fn_801F666C(fn_801F856C(), idx);
                if (src != 0 && *(u32*)(src + 0x1a0) == 0x41525257) {
                    *(f32*)(this_ + 0xc) = *(f32*)(src + 0xc);
                    *(f32*)(this_ + 0x10) = *(f32*)(src + 0x10);
                    *(f32*)(this_ + 0x14) = *(f32*)(src + 0x14);
                    if (*(s32*)(src + 0x26c) >= 1) {
                        *(s32*)(this_ + 0x250) = -1;
                    } else {
                        u8* p;
                        s32 i;
                        if (*(s32*)(this_ + 0x250) == 0) {
                            *(s32*)(this_ + 0x250) = lbl_8053A100;
                            *(s32*)(this_ + 0x250) += 1;
                            for (i = 0, p = this_; i < 3; i++, p += 4) {
                                if (*(void**)(p + 0x304) != 0) {
                                    void* mgr = fn_8013C824();
                                    forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((u8*)mgr + 0xc), *(void**)(p + 0x304));
                                    *(void**)(p + 0x304) = 0;
                                }
                            }
                            fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, lbl_8053E370, 0xb5, 1, 5, 0, 0, 1);
                            fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, lbl_8053E370, 0xb6, 1, 5, 0, 0, 1);
                            if (*(void**)(this_ + 0x304) == 0) {
                                *(s32*)(this_ + 0x304) = fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, lbl_8053E370, 0x199, 1, 5, 0, 0, 1);
                            }
                            if (*(void**)(this_ + 0x308) == 0) {
                                *(s32*)(this_ + 0x308) = fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, lbl_8053E370, 0x19a, 1, 5, 0, 0, 1);
                            }
                        }
                        *(f32*)(this_ + 0x44) = lbl_8053E388;
                        *(f32*)(this_ + 0x40) = lbl_8053E388;
                        *(f32*)(this_ + 0x3c) = lbl_8053E388;
                        *(f32*)(this_ + 0x27c) = lbl_8053E388;
                        *(f32*)(this_ + 0x278) = lbl_8053E388;
                        *(f32*)(this_ + 0x274) = lbl_8053E388;
                        {
                            s32 j;
                            u8* q;
                            for (j = 0, q = this_; j < 13; j++, q += 4) {
                                fn_8013CB44(*(void**)(q + 0x304), this_ + 0xc, 1, 5, 1);
                            }
                        }
                    }
                }
            }
        }
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
