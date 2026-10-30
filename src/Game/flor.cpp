// TU 0x8020db74-0x8020f798 (actor FLOR).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JParticle/JPAEmitter.h"

// ---- fn_8020F474_dtor.cpp ----
extern "C" void* fn_801EE434(void* handle);
extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A6004[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

extern "C" void* fn_8020F474(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A6004;
        fn_801EE434(*(void**)(p + 0x2b0));
        if (this_ != 0) {
            *(void**)p = lbl_804A4808;
            if (p + 0x270 != 0) {
                if (p + 0x294 != 0) {
                    *(void**)(p + 0x294) = lbl_8049CC34;
                }
            }
            __dt__5ActorFv(this_, 0);
        }
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

extern "C" void fn_8030C210(void* mgr, void* pos);
extern char* lbl_8053AB10;

extern "C" void fn_8020DDC4(char* this_) {
    if (*(s32*)(this_ + 0x248) != 0) {
        fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), this_ + 0xc);
    }
}

extern "C" void* fn_801D0F40(void* this_);
extern "C" const f32 lbl_8053FA2C;

extern "C" void* fn_8020F510(char* this_) {
    fn_801D0F40(this_);
    *(void**)this_ = lbl_804A6004;
    *(f32*)(this_ + 0x2a8) = lbl_8053FA2C;
    *(f32*)(this_ + 0x2ac) = lbl_8053FA2C;
    *(s32*)(this_ + 0x2b0) = 0;
    *(f32*)(this_ + 0x2b4) = lbl_8053FA2C;
    *(s32*)(this_ + 0x2b8) = -1;
    *(s32*)(this_ + 0x2bc) = 0;
    *(s32*)(this_ + 0x2c0) = -1;
    return this_;
}

extern "C" void fn_801D00B4(void* this_, s32 id, f32 f, f32* out);
extern "C" const f32 lbl_8053FA28;

extern "C" void fn_8020E268(char* this_) {
    f32 v[2];
    *(f32*)(this_ + 0x3c) = lbl_8053FA2C;
    *(f32*)(this_ + 0x40) = lbl_8053FA2C;
    *(f32*)(this_ + 0x44) = lbl_8053FA2C;
    switch (*(s32*)(this_ + 0x248)) {
    case 1:
        if (*(s32*)(this_ + 0x2b8) >= 0) {
            fn_801D00B4(this_, *(s32*)(this_ + 0x2b8), lbl_8053FA28, v);
            *(f32*)(this_ + 0x3c) = v[0];
            *(f32*)(this_ + 0x40) = v[1];
        }
        break;
    }
}

extern "C" u8 fn_801F2DB4(void* this_, u32 a, u32 b, u32 c);
extern "C" void fn_801F0E34(void* this_, u32 id, u32 c);
extern "C" void fn_8020ED5C(char* this_, s32 st);
extern "C" u8 fn_801D21F0(void* p);
extern "C" u8 fn_801F2740(void* this_, s32 a);
extern "C" u8 fn_80230AD4(s32 i);
extern "C" u8 fn_8022DE10(s32 id, s32 a);
extern "C" u8 fn_802300EC(s32 i);
extern "C" u8 fn_801CD1D0(s32 id);
extern "C" void fn_802316C8(s32 id, s32 room, void* v);
extern "C" void fn_801CD150(void* src, void* dst);
extern "C" void* fn_8013C824(void);
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void* mgr, void* emitter);
extern "C" s32 fn_801D05F8(char* this_, char* pos, f32 f);
extern "C" u8 fn_8022DD74(s32 player);
extern "C" u8 fn_8022DCD8(s32 i);
extern "C" u8 fn_80230188(s32 i);
extern "C" void fn_80230224(s32 i, s32 b);
extern "C" void* fn_8013CC50(s32 room, void* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale);
extern const f32 lbl_8053FA58;
#define FLT_EPSILON_FLOR (*(f32*)__float_epsilon)
extern const f32 lbl_8053FA68;
extern const f32 lbl_8053FA6C;
extern "C" void fn_8020EB08(char* this_);
extern const f32 lbl_8053FA28;
extern const f32 lbl_8053FA2C;
extern const f32 lbl_8053FA54;
extern const f32 lbl_8053FA5C;
extern const f32 lbl_8053FA60;
extern const f32 lbl_8053FA64;
extern const f32 lbl_8053FA70;

extern "C" u8 fn_8020DF4C(char* this_) {
    u8 r = 0;
    if (*(f32*)(this_ + 0x68) - *(f32*)(this_ + 0x60) > lbl_8053FA2C &&
        *(f32*)(this_ + 0x6c) - *(f32*)(this_ + 0x64) > lbl_8053FA2C) {
        r = fn_801F2DB4(this_, *(u32*)(this_ + 0x1a0), 'NULL', 0);
        if (r) {
            fn_801F0E34(this_, 0x5007d, 0);
            u8 ok = 0;
            switch (*(s32*)(this_ + 0x248)) {
            case 3:
            case 5:
            case 6:
            case 8:
                ok = 1;
                break;
            }
            if (ok) {
                fn_8020ED5C(this_, 4);
            }
        }
    }
    return r;
}

extern "C" void fn_801D0ED0(void* this_);
extern "C" s32 fn_801CD664(s32 n);
extern "C" void fn_801D2608(void* obj, void* tbl, s32 n);
extern "C" void fn_801D22DC(void* obj, s32 a, s32 b, s32 c);
extern void* lbl_804A5FE8[];
extern const f32 lbl_8053FA30;
extern const f32 lbl_8053FA40;

extern "C" void fn_8020F318(char* this_) {
    fn_801D0ED0(this_);
    if (*(u32*)(this_ + 0x90) & 1) {
        *(u32*)(this_ + 0x230) |= 0x2000;
        f32 k = lbl_8053FA40;
        f32 b = (f32)((*(u32*)(this_ + 0x90) >> 5) & 0x1f8);
        f32 a = (f32)((*(u32*)(this_ + 0x90) >> 13) & 0x1f8);
        *(f32*)(this_ + 0x2a8) = k + a;
        *(f32*)(this_ + 0x2ac) = k + b;
    }
    *(f32*)(this_ + 0x60) = lbl_8053FA28;
    *(f32*)(this_ + 0x64) = lbl_8053FA28;
    *(f32*)(this_ + 0x68) = lbl_8053FA30;
    *(f32*)(this_ + 0x6c) = lbl_8053FA30;
    *(f32*)(this_ + 0x70) = *(f32*)(this_ + 0x60);
    *(f32*)(this_ + 0x74) = *(f32*)(this_ + 0x64);
    *(f32*)(this_ + 0x78) = *(f32*)(this_ + 0x68);
    *(f32*)(this_ + 0x7c) = *(f32*)(this_ + 0x6c);
    *(f32*)(this_ + 0x80) = lbl_8053FA28;
    *(f32*)(this_ + 0x84) = lbl_8053FA28;
    *(f32*)(this_ + 0x88) = lbl_8053FA30;
    *(f32*)(this_ + 0x8c) = lbl_8053FA30;
    *(u32*)(this_ + 0xb0) = 0x50303;
    *(s32*)(this_ + 0x98) = 2;
    *(u32*)(this_ + 0x230) |= 0x380;
    *(s32*)(this_ + 0x108) = 1000;
    *(s32*)(this_ + 0x244) = *(s32*)(this_ + 0x108);
    *(u8*)(this_ + 0x194) = 1;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x250) = fn_801CD664(0x3d) + 0x3c;
    *(f32*)(this_ + 0x254) = lbl_8053FA2C;
    *(f32*)(this_ + 0x258) = lbl_8053FA2C;
    fn_801D2608(this_ + 0x270, lbl_804A5FE8, 7);
    fn_801D22DC(this_ + 0x270, 0, 0, 0);
}

extern "C" void fn_801CE4BC(void* this_);
extern const f32 lbl_8053FA34;
extern const f32 lbl_8053FA38;
extern const f32 lbl_8053FA3C;
extern const f32 lbl_8053FA44;
extern const f32 lbl_8053FA48;
extern const f32 lbl_8053FA4C;
extern const f32 lbl_8053FA50;
extern const f32 lbl_8053FA54;

extern "C" void fn_8020E2D8(char* this_) {
    if (*(s32*)(this_ + 0x248) == 4) {
        return;
    }
    fn_801CE4BC(this_);
    if (*(f32*)(this_ + 0x68) - *(f32*)(this_ + 0x60) > lbl_8053FA2C &&
        *(f32*)(this_ + 0x6c) - *(f32*)(this_ + 0x64) > lbl_8053FA2C) {
        switch (*(s32*)(this_ + 0x280)) {
        case 2:
            *(f32*)(this_ + 0x60) = lbl_8053FA34;
            *(f32*)(this_ + 0x64) = lbl_8053FA38;
            *(f32*)(this_ + 0x68) = lbl_8053FA3C;
            *(f32*)(this_ + 0x6c) = lbl_8053FA40;
            break;
        case 3:
            *(f32*)(this_ + 0x60) = lbl_8053FA38;
            *(f32*)(this_ + 0x64) = lbl_8053FA44;
            *(f32*)(this_ + 0x68) = lbl_8053FA48;
            *(f32*)(this_ + 0x6c) = lbl_8053FA40;
            break;
        case 4:
            *(f32*)(this_ + 0x60) = lbl_8053FA38;
            *(f32*)(this_ + 0x64) = lbl_8053FA4C;
            *(f32*)(this_ + 0x68) = lbl_8053FA28;
            *(f32*)(this_ + 0x6c) = lbl_8053FA40;
            break;
        case 5:
            *(f32*)(this_ + 0x60) = lbl_8053FA50;
            *(f32*)(this_ + 0x64) = lbl_8053FA54;
            *(f32*)(this_ + 0x68) = lbl_8053FA3C;
            *(f32*)(this_ + 0x6c) = lbl_8053FA40;
            break;
        }
        if (*(u32*)(this_ + 0x230) & 0x8000) {
            f32 t = *(f32*)(this_ + 0x60);
            *(f32*)(this_ + 0x60) = -*(f32*)(this_ + 0x68);
            *(f32*)(this_ + 0x68) = -t;
        }
        *(f32*)(this_ + 0x70) = *(f32*)(this_ + 0x60);
        *(f32*)(this_ + 0x74) = *(f32*)(this_ + 0x64);
        *(f32*)(this_ + 0x78) = *(f32*)(this_ + 0x68);
        *(f32*)(this_ + 0x7c) = *(f32*)(this_ + 0x6c);
    }
}

#pragma opt_propagation off
extern "C" void fn_8020E438(char* this_) {
    fn_8020EB08(this_);
    switch (*(s32*)(this_ + 0x248)) {
    case 0:
        if (*(u32*)(this_ + 0x230) & 0x4000) {
            break;
        }
        if (*(s32*)(this_ + 0x24c) >= *(s32*)(this_ + 0x250)) {
            *(s32*)(this_ + 0x2bc) = 0;
            *(s32*)(this_ + 0x2b8) = fn_801D05F8(this_, this_ + 0xc, lbl_8053FA58);
            if (*(s32*)(this_ + 0x2b8) >= 0) {
                fn_8020ED5C(this_, 1);
            }
        }
        break;
    case 1:
        if (*(s32*)(this_ + 0x24c) >= 0x3c) {
            if (*(s32*)(this_ + 0x2b8) >= 0) {
                fn_8020ED5C(this_, 2);
            } else {
                fn_8020ED5C(this_, 0xa);
            }
            break;
        }
        {
            f32 cur;
            f32 t = (f32)(0x3c - *(s32*)(this_ + 0x24c));
            if (t < FLT_EPSILON_FLOR) {
                *(f32*)(this_ + 0x2b4) = lbl_8053FA28;
            } else {
                cur = *(f32*)(this_ + 0x2b4);
                f32 inv = lbl_8053FA28 / t;
                *(f32*)(this_ + 0x2b4) = inv * (lbl_8053FA28 - cur) + cur;
            }
        }
        if (*(void**)(this_ + 0x2b0) != 0) {
            char* em = *(char**)(this_ + 0x2b0);
            u8 g = (u8)(*(f32*)(this_ + 0x2b4) * lbl_8053FA60 + lbl_8053FA5C);
            em[0xb8] = g;
            em[0xb9] = g;
            em[0xba] = g;
            f32 cur = *(f32*)(this_ + 0x2b4);
            u8 b;
            u8 r;
            u8 gg;
            b = (u8)(cur * lbl_8053FA2C + lbl_8053FA5C);
            r = (u8)(cur * lbl_8053FA64 + lbl_8053FA5C);
            gg = (u8)(cur * lbl_8053FA60 + lbl_8053FA5C);
            char* em2 = *(char**)(this_ + 0x2b0);
            em2[0xbc] = r;
            em2[0xbd] = gg;
            em2[0xbe] = b;
        }
        fn_801F0E34(this_, 0x50089, 0);
        break;
    case 2:
        if (*(s32*)(this_ + 0x24c) > 1 && fn_801D21F0(this_ + 0x270)) {
            if (*(s32*)(this_ + 0x2b8) >= 0) {
                fn_8020ED5C(this_, 3);
            } else {
                fn_8020ED5C(this_, 8);
            }
        }
        break;
    case 3: {
        if (*(s32*)(this_ + 0x24c) > 1 && fn_801D21F0(this_ + 0x270)) {
            u8 r30;
            fn_801F0E34(this_, 0x50088, 0);
            if (*(s32*)(this_ + 0x2b8) >= 0) {
            r30 = 0;
            if (*(s32*)(this_ + 0x248) == 3 && *(s32*)(this_ + 0x2b8) >= 0 && !fn_80230188(*(s32*)(this_ + 0x2b8)) && fn_802300EC(*(s32*)(this_ + 0x2b8)) && !fn_8022DCD8(*(s32*)(this_ + 0x2b8)) && !fn_801CD1D0(*(s32*)(this_ + 0x2b8))) {
                *(f32*)(this_ + 0x60) = lbl_8053FA68;
                *(f32*)(this_ + 0x64) = lbl_8053FA54;
                *(f32*)(this_ + 0x68) = lbl_8053FA6C;
                *(f32*)(this_ + 0x6c) = lbl_8053FA6C;
                if (fn_801F2740(this_, -1) & (1 << *(s32*)(this_ + 0x2b8))) {
                    r30 = 1;
                    *(f32*)(this_ + 0x60) = lbl_8053FA70;
                    *(f32*)(this_ + 0x64) = lbl_8053FA54;
                    *(f32*)(this_ + 0x68) = lbl_8053FA40;
                    *(f32*)(this_ + 0x6c) = lbl_8053FA40;
                }
                *(f32*)(this_ + 0x70) = *(f32*)(this_ + 0x60);
                *(f32*)(this_ + 0x74) = *(f32*)(this_ + 0x64);
                *(f32*)(this_ + 0x78) = *(f32*)(this_ + 0x68);
                *(f32*)(this_ + 0x7c) = *(f32*)(this_ + 0x6c);
            }
            if (r30 != 0) {
                if (fn_80230AD4(*(s32*)(this_ + 0x2b8))) {
                    fn_8020ED5C(this_, 5);
                    break;
                }
                fn_8020ED5C(this_, 8);
                break;
            }
            }
            fn_8020ED5C(this_, 8);
        }
        break;
    }
    case 4:
        if (*(s32*)(this_ + 0x24c) >= 0x78) {
            *(s32*)(this_ + 0x2bc) = 0;
            *(s32*)(this_ + 0x2b8) = fn_801D05F8(this_, this_ + 0xc, lbl_8053FA58);
            if (*(s32*)(this_ + 0x2b8) >= 0) {
                fn_8020ED5C(this_, 3);
            } else {
                fn_8020ED5C(this_, 9);
            }
        }
        break;
    case 5:
        if (*(s32*)(this_ + 0x24c) > 1 && fn_801D21F0(this_ + 0x270)) {
            fn_80230224(*(s32*)(this_ + 0x2b8), 0);
            if (fn_8022DE10(*(s32*)(this_ + 0x2b8), 2)) {
                fn_8020ED5C(this_, 6);
            } else {
                fn_8020ED5C(this_, 9);
            }
        }
        break;
    case 6:
        if (*(s32*)(this_ + 0x24c) > 1 && fn_801D21F0(this_ + 0x270)) {
            fn_8020ED5C(this_, 7);
        }
        break;
    case 7:
        if (*(s32*)(this_ + 0x24c) > 1 && fn_801D21F0(this_ + 0x270)) {
            JGeometry::TVec3f v2;
            JGeometry::TVec3f v1;
            f32 tmp[3];
            if (!(*(u32*)(this_ + 0x230) & 0x2000)) {
                fn_801CD150(this_ + 0xc, tmp);
                f32 y = tmp[1];
                *(f32*)(this_ + 0x2a8) = tmp[0];
                *(f32*)(this_ + 0x2ac) = y;
            }
            v1.set(*(f32*)(this_ + 0x2a8), *(f32*)(this_ + 0x2ac), lbl_8053FA2C);
            v2 = v1;
            fn_802316C8(*(s32*)(this_ + 0x2b8), 8, &v2);
            if (fn_8022DD74(*(s32*)(this_ + 0x2b8))) {
                *(u32*)(this_ + 0x230) &= ~0x4000;
                *(s32*)(this_ + 0x2c0) = -1;
            } else {
                *(u32*)(this_ + 0x230) |= 0x4000;
                *(s32*)(this_ + 0x2c0) = *(s32*)(this_ + 0x2b8);
            }
            fn_8013CC50(*(s32*)(this_ + 0x4), this_ + 0xc, 0x1b0, 0, 0, 0, 0, 1, lbl_8053FA28);
            fn_8013CC50(*(s32*)(this_ + 0x4), this_ + 0xc, 0x548, 0, -1, 0, 0, 1, lbl_8053FA28);
            fn_8020ED5C(this_, 0xa);
        }
        break;
    case 8:
        if (*(s32*)(this_ + 0x24c) > 1 && fn_801D21F0(this_ + 0x270)) {
            fn_8020ED5C(this_, 9);
        }
        break;
    case 9:
        if (*(s32*)(this_ + 0x24c) > 1 && fn_801D21F0(this_ + 0x270)) {
            fn_8020ED5C(this_, 0xa);
        }
        break;
    case 10:
        if (*(s32*)(this_ + 0x24c) >= 0x3c) {
            if (*(void**)(this_ + 0x2b0) != 0) {
                void* mgr = *(void**)((char*)fn_8013C824() + 0xc);
                forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, *(void**)(this_ + 0x2b0));
                *(s32*)(this_ + 0x2b0) = 0;
            }
            fn_8020ED5C(this_, 0);
            break;
        }
        {
            f32 cur;
            f32 t = (f32)(0x3c - *(s32*)(this_ + 0x24c));
            if (t < FLT_EPSILON_FLOR) {
                *(f32*)(this_ + 0x2b4) = lbl_8053FA2C;
            } else {
                f32 inv = lbl_8053FA28 / t;
                f32 delta = lbl_8053FA2C - *(f32*)(this_ + 0x2b4);
                cur = *(f32*)(this_ + 0x2b4);
                *(f32*)(this_ + 0x2b4) = inv * delta + cur;
            }
        }
        if (*(void**)(this_ + 0x2b0) != 0) {
            char* em = *(char**)(this_ + 0x2b0);
            u8 g = (u8)(*(f32*)(this_ + 0x2b4) * lbl_8053FA60 + lbl_8053FA5C);
            em[0xb8] = g;
            em[0xb9] = g;
            em[0xba] = g;
            f32 cur = *(f32*)(this_ + 0x2b4);
            u8 b;
            u8 r;
            u8 gg;
            b = (u8)(cur * lbl_8053FA2C + lbl_8053FA5C);
            r = (u8)(cur * lbl_8053FA64 + lbl_8053FA5C);
            gg = (u8)(cur * lbl_8053FA60 + lbl_8053FA5C);
            char* em2 = *(char**)(this_ + 0x2b0);
            em2[0xbc] = r;
            em2[0xbd] = gg;
            em2[0xbe] = b;
        }
        break;
    }
}
#pragma opt_propagation reset
extern "C" void fn_8013CB44(void* a, char* b, s32 c, s32 d, s32 e);
extern "C" s32 fn_801D05F8(char* this_, char* pos, f32 f);
extern "C" void fn_801CD8E4(f32* out, f32 v, f32 lo, f32 hi);
extern "C" void* fn_8023E724(s32 i);
extern "C" void fn_8023DFF4(s32 i, void* pos);
extern "C" void fn_80230498(s32 i, void* pos, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" s32 fn_8023CBC0(s32 i);
extern "C" u8 fn_8022DD74(s32 player);
extern "C" const f32 lbl_8053FA3C;
extern "C" const f32 lbl_8053FA80;
extern const f32 lbl_8053FA5C;
extern const f32 lbl_8053FA60;
extern const f32 lbl_8053FA64;
extern const f32 lbl_8053FA70;
extern const f32 lbl_8053FA84;
extern "C" void* fn_8013CC50(s32 room, void* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale);
extern "C" u8 fn_8022DCD8(s32 i);
extern "C" u8 fn_80230188(s32 i);
extern "C" void fn_80230224(s32 i, s32 b);
#pragma inline_depth(5)
extern "C" void fn_8020EB08(char* this_) {
    JGeometry::TVec3<f32> a;
    JGeometry::TVec3<f32> d;
    JGeometry::TVec3<f32> b;
    f32 y;
    f32 z;
    f32 x;
    s32 r;
    fn_8013CB44(*(void**)(this_ + 0x2b0), this_ + 0xc, 0, 0, 1);
    switch (*(s32*)(this_ + 0x248)) {
    case 1:
    case 2:
    case 3:
        if (*(s32*)(this_ + 0x2b8) >= 0) {
            *(s32*)(this_ + 0x2bc) += 1;
        }
        r = fn_801D05F8(this_, this_ + 0xc, lbl_8053FA2C);
        if (r != *(s32*)(this_ + 0x2b8)) {
            if (*(s32*)(this_ + 0x2b8) < 0) {
                *(s32*)(this_ + 0x2b8) = r;
                *(s32*)(this_ + 0x2bc) = 0;
            } else if (r < 0) {
                *(s32*)(this_ + 0x2b8) = -1;
                *(s32*)(this_ + 0x2bc) = 0;
            } else if (*(s32*)(this_ + 0x2bc) >= 0x2d) {
                *(s32*)(this_ + 0x2b8) = r;
                *(s32*)(this_ + 0x2bc) = 0;
            }
        }
        break;
    }
    {
        u8 ok = 0;
        switch (*(s32*)(this_ + 0x248)) {
        case 5:
        case 6:
        case 7:
            ok = 1;
            break;
        }
        if (ok) {
            a = *(JGeometry::TVec3<f32>*)fn_8023E724(*(s32*)(this_ + 0x2b8));
            b = a;
            if (*(s32*)(this_ + 0x248) == 6) {
                x = *(f32*)(this_ + 0xc);
                y = *(f32*)(this_ + 0x10);
                z = lbl_8053FA3C;
            } else {
                x = *(f32*)(this_ + 0xc);
                y = *(f32*)(this_ + 0x10);
                z = lbl_8053FA2C;
            }
            fn_801CD8E4(&b.x, x, lbl_8053FA80, lbl_8053FA2C);
            fn_801CD8E4(&b.y, y, lbl_8053FA80, lbl_8053FA2C);
            fn_801CD8E4(&b.z, z, lbl_8053FA80, lbl_8053FA2C);
            if (*(s32*)(this_ + 0x248) == 5) {
                fn_80230498(*(s32*)(this_ + 0x2b8), &b, (u16)fn_8023CBC0(*(s32*)(this_ + 0x2b8)), 0xff, -0x80, -0x80, 1);
            } else {
                d.operator=(b.operator-(a));
                fn_8023DFF4(*(s32*)(this_ + 0x2b8), &d);
            }
        }
    }
    if (*(u32*)(this_ + 0x230) & 0x4000) {
        if (fn_8022DD74(*(s32*)(this_ + 0x2c0))) {
            *(u32*)(this_ + 0x230) &= ~0x4000;
            *(s32*)(this_ + 0x2c0) = -1;
        }
    }
}
#pragma opt_propagation off
extern "C" void fn_8020ED5C(char* this_, s32 st) {
    switch (st) {
    case 0:
        *(f32*)(this_ + 0x2b4) = lbl_8053FA2C;
        *(s32*)(this_ + 0x2b8) = -1;
        *(s32*)(this_ + 0x2bc) = 0;
        *(f32*)(this_ + 0x60) = lbl_8053FA28;
        *(f32*)(this_ + 0x64) = lbl_8053FA28;
        *(f32*)(this_ + 0x68) = lbl_8053FA30;
        *(f32*)(this_ + 0x6c) = lbl_8053FA30;
        *(f32*)(this_ + 0x70) = *(f32*)(this_ + 0x60);
        *(f32*)(this_ + 0x74) = *(f32*)(this_ + 0x64);
        *(f32*)(this_ + 0x78) = *(f32*)(this_ + 0x68);
        *(f32*)(this_ + 0x7c) = *(f32*)(this_ + 0x6c);
        *(s32*)(this_ + 0x250) = fn_801CD664(0x3d) + 0x3c;
        *(f32*)(this_ + 0xc) = *(f32*)(this_ + 0x24);
        *(f32*)(this_ + 0x10) = *(f32*)(this_ + 0x28);
        *(f32*)(this_ + 0x14) = *(f32*)(this_ + 0x2c);
        *(f32*)(this_ + 0x254) = lbl_8053FA2C;
        *(f32*)(this_ + 0x258) = lbl_8053FA2C;
        break;
    case 1:
        *(f32*)(this_ + 0x2b4) = lbl_8053FA2C;
        *(f32*)(this_ + 0x60) = lbl_8053FA28;
        *(f32*)(this_ + 0x64) = lbl_8053FA28;
        *(f32*)(this_ + 0x68) = lbl_8053FA30;
        *(f32*)(this_ + 0x6c) = lbl_8053FA30;
        *(f32*)(this_ + 0x70) = *(f32*)(this_ + 0x60);
        *(f32*)(this_ + 0x74) = *(f32*)(this_ + 0x64);
        *(f32*)(this_ + 0x78) = *(f32*)(this_ + 0x68);
        *(f32*)(this_ + 0x7c) = *(f32*)(this_ + 0x6c);
        *(f32*)(this_ + 0x258) = lbl_8053FA28;
        *(void**)(this_ + 0x2b0) = fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, 0x1af, 0, 0, 0, 0, 1, lbl_8053FA28);
        if (*(void**)(this_ + 0x2b0) != 0) {
            char* obj = *(char**)(this_ + 0x2b0);
            u8 c = (u8)(*(f32*)(this_ + 0x2b4) * lbl_8053FA60 + lbl_8053FA5C);
            obj[0xb8] = c;
            obj[0xb9] = c;
            obj[0xba] = c;
            s32 blue = (s32)(*(f32*)(this_ + 0x2b4) * lbl_8053FA2C + lbl_8053FA5C);
            s32 red = (s32)(*(f32*)(this_ + 0x2b4) * lbl_8053FA64 + lbl_8053FA5C);
            c = (s32)(*(f32*)(this_ + 0x2b4) * lbl_8053FA60 + lbl_8053FA5C);
            JPABaseEmitter* emitter = *(JPABaseEmitter**)(this_ + 0x2b0);
            emitter->setGlobalEnvColor(red, c, blue);
        }
        break;
    case 2:
        *(f32*)(this_ + 0x60) = lbl_8053FA28;
        *(f32*)(this_ + 0x64) = lbl_8053FA28;
        *(f32*)(this_ + 0x68) = lbl_8053FA30;
        *(f32*)(this_ + 0x6c) = lbl_8053FA30;
        *(f32*)(this_ + 0x70) = *(f32*)(this_ + 0x60);
        *(f32*)(this_ + 0x74) = *(f32*)(this_ + 0x64);
        *(f32*)(this_ + 0x78) = *(f32*)(this_ + 0x68);
        *(f32*)(this_ + 0x7c) = *(f32*)(this_ + 0x6c);
        *(f32*)(this_ + 0x258) = lbl_8053FA2C;
        fn_801D22DC(this_ + 0x270, 0, 0, 0);
        break;
    case 3:
        *(f32*)(this_ + 0x60) = lbl_8053FA70;
        *(f32*)(this_ + 0x64) = lbl_8053FA54;
        *(f32*)(this_ + 0x68) = lbl_8053FA40;
        *(f32*)(this_ + 0x6c) = lbl_8053FA40;
        *(f32*)(this_ + 0x70) = *(f32*)(this_ + 0x60);
        *(f32*)(this_ + 0x74) = *(f32*)(this_ + 0x64);
        *(f32*)(this_ + 0x78) = *(f32*)(this_ + 0x68);
        *(f32*)(this_ + 0x7c) = *(f32*)(this_ + 0x6c);
        *(f32*)(this_ + 0x258) = lbl_8053FA2C;
        fn_801D22DC(this_ + 0x270, 1, 0, 0);
        break;
    case 4:
        if (*(s32*)(this_ + 0x2b8) >= 0) {
            if (fn_8022DCD8(*(s32*)(this_ + 0x2b8))) {
                if (fn_8022DD74(*(s32*)(this_ + 0x2b8))) {
                    *(u32*)(this_ + 0x230) &= ~0x4000;
                    *(s32*)(this_ + 0x2c0) = -1;
                } else {
                    *(u32*)(this_ + 0x230) |= 0x4000;
                    *(s32*)(this_ + 0x2c0) = *(s32*)(this_ + 0x2b8);
                }
            } else if (fn_80230188(*(s32*)(this_ + 0x2b8))) {
                fn_80230224(*(s32*)(this_ + 0x2b8), 0);

            }
        }
        *(f32*)(this_ + 0x60) = lbl_8053FA70;
        *(f32*)(this_ + 0x64) = lbl_8053FA54;
        *(f32*)(this_ + 0x68) = lbl_8053FA40;
        *(f32*)(this_ + 0x6c) = lbl_8053FA40;
        *(f32*)(this_ + 0x70) = *(f32*)(this_ + 0x60);
        *(f32*)(this_ + 0x74) = *(f32*)(this_ + 0x64);
        *(f32*)(this_ + 0x78) = *(f32*)(this_ + 0x68);
        *(f32*)(this_ + 0x7c) = *(f32*)(this_ + 0x6c);
        *(f32*)(this_ + 0x258) = lbl_8053FA2C;
        break;
    case 5:
        *(f32*)(this_ + 0x60) = lbl_8053FA70;
        *(f32*)(this_ + 0x64) = lbl_8053FA54;
        *(f32*)(this_ + 0x68) = lbl_8053FA40;
        *(f32*)(this_ + 0x6c) = lbl_8053FA40;
        *(f32*)(this_ + 0x70) = *(f32*)(this_ + 0x60);
        *(f32*)(this_ + 0x74) = *(f32*)(this_ + 0x64);
        *(f32*)(this_ + 0x78) = *(f32*)(this_ + 0x68);
        *(f32*)(this_ + 0x7c) = *(f32*)(this_ + 0x6c);
        *(f32*)(this_ + 0x258) = lbl_8053FA2C;
        fn_801D22DC(this_ + 0x270, 2, 0, 0);
        break;
    case 6:
        *(f32*)(this_ + 0x60) = lbl_8053FA70;
        *(f32*)(this_ + 0x64) = lbl_8053FA54;
        *(f32*)(this_ + 0x68) = lbl_8053FA40;
        *(f32*)(this_ + 0x6c) = lbl_8053FA40;
        *(f32*)(this_ + 0x70) = *(f32*)(this_ + 0x60);
        *(f32*)(this_ + 0x74) = *(f32*)(this_ + 0x64);
        *(f32*)(this_ + 0x78) = *(f32*)(this_ + 0x68);
        *(f32*)(this_ + 0x7c) = *(f32*)(this_ + 0x6c);
        *(f32*)(this_ + 0x258) = lbl_8053FA2C;
        fn_801D22DC(this_ + 0x270, 3, 0, 0);
        break;
    case 7:
        *(f32*)(this_ + 0x60) = lbl_8053FA28;
        *(f32*)(this_ + 0x64) = lbl_8053FA28;
        *(f32*)(this_ + 0x68) = lbl_8053FA30;
        *(f32*)(this_ + 0x6c) = lbl_8053FA30;
        *(f32*)(this_ + 0x70) = *(f32*)(this_ + 0x60);
        *(f32*)(this_ + 0x74) = *(f32*)(this_ + 0x64);
        *(f32*)(this_ + 0x78) = *(f32*)(this_ + 0x68);
        *(f32*)(this_ + 0x7c) = *(f32*)(this_ + 0x6c);
        *(f32*)(this_ + 0x258) = lbl_8053FA2C;
        fn_801D22DC(this_ + 0x270, 4, 0, 0);
        break;
    case 8:
        *(f32*)(this_ + 0x60) = lbl_8053FA70;
        *(f32*)(this_ + 0x64) = lbl_8053FA54;
        *(f32*)(this_ + 0x68) = lbl_8053FA40;
        *(f32*)(this_ + 0x6c) = lbl_8053FA40;
        *(f32*)(this_ + 0x70) = *(f32*)(this_ + 0x60);
        *(f32*)(this_ + 0x74) = *(f32*)(this_ + 0x64);
        *(f32*)(this_ + 0x78) = *(f32*)(this_ + 0x68);
        *(f32*)(this_ + 0x7c) = *(f32*)(this_ + 0x6c);
        *(f32*)(this_ + 0x258) = lbl_8053FA2C;
        fn_801D22DC(this_ + 0x270, 5, 0, 0);
        break;
    case 9:
        *(f32*)(this_ + 0x60) = lbl_8053FA28;
        *(f32*)(this_ + 0x64) = lbl_8053FA28;
        *(f32*)(this_ + 0x68) = lbl_8053FA30;
        *(f32*)(this_ + 0x6c) = lbl_8053FA30;
        *(f32*)(this_ + 0x70) = *(f32*)(this_ + 0x60);
        *(f32*)(this_ + 0x74) = *(f32*)(this_ + 0x64);
        *(f32*)(this_ + 0x78) = *(f32*)(this_ + 0x68);
        *(f32*)(this_ + 0x7c) = *(f32*)(this_ + 0x6c);
        *(f32*)(this_ + 0x258) = lbl_8053FA2C;
        fn_801D22DC(this_ + 0x270, 6, 0, 0);
        break;
    case 10:
        *(s32*)(this_ + 0x2b8) = -1;
        *(f32*)(this_ + 0x60) = lbl_8053FA28;
        *(f32*)(this_ + 0x64) = lbl_8053FA28;
        *(f32*)(this_ + 0x68) = lbl_8053FA30;
        *(f32*)(this_ + 0x6c) = lbl_8053FA30;
        *(f32*)(this_ + 0x70) = *(f32*)(this_ + 0x60);
        *(f32*)(this_ + 0x74) = *(f32*)(this_ + 0x64);
        *(f32*)(this_ + 0x78) = *(f32*)(this_ + 0x68);
        *(f32*)(this_ + 0x7c) = *(f32*)(this_ + 0x6c);
        *(f32*)(this_ + 0x258) = lbl_8053FA2C;
        break;
    }
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x248) = st;
    if (*(s32*)(this_ + 0x2b8) >= 0) {
        switch (*(s32*)(this_ + 0x248)) {
        case 2:
        case 3:
            f32* p = (f32*)fn_8023E724(*(s32*)(this_ + 0x2b8));
            if (*(f32*)(this_ + 0xc) < p[0] - lbl_8053FA84) {
                *(u32*)(this_ + 0x230) &= ~0x8000;
            } else {
                f32 upper = lbl_8053FA84;
                upper += p[0];
                if (upper < *(f32*)(this_ + 0xc)) {
                    *(u32*)(this_ + 0x230) |= 0x8000;
                }
            }
        break;
        }
    }
}
#pragma opt_propagation reset
extern "C" s32 fn_801F285C(void* this_, f32* pos, void* out, s32 a, s32 idx);
extern "C" void fn_8023B6CC(s32 idx);
extern "C" u8 fn_801EAC20(void* list, s32 idx);
extern "C" void fn_801CB538(u32 room, f32* pos, s32 a, s32 b);

extern "C" u8 fn_8020DDFC(char* this_) {
    u8 r = 0;
    if (*(f32*)(this_ + 0x68) - *(f32*)(this_ + 0x60) > lbl_8053FA2C &&
        *(f32*)(this_ + 0x6c) - *(f32*)(this_ + 0x64) > lbl_8053FA2C) {
        for (s32 i = 0; i < 4; i++) {
            f32 pos[2];
            u8 tmp[4];
            if (i == fn_801F285C(this_, pos, tmp, 1, i)) {
                fn_8023B6CC(i);
                if (fn_801EAC20(this_ + 0x1dc, i)) {
                    r = 1;
                    f32 p3[3];
                    p3[0] = pos[0];
                    p3[1] = pos[1];
                    p3[2] = lbl_8053FA2C;
                    fn_801CB538(*(u32*)(this_ + 0x4), p3, 0, 0);
                }
            }
        }
        if (r) {
            fn_801F0E34(this_, 0x5007d, 0);
            u8 ok = 0;
            switch (*(s32*)(this_ + 0x248)) {
            case 3:
            case 5:
            case 6:
            case 8:
                ok = 1;
                break;
            }
            if (ok) {
                fn_8020ED5C(this_, 4);
            }
        }
    }
    return r;
}

extern "C" void fn_801F317C(void* this_, void* out);
extern "C" s32 fn_8023AE34(void* a, u32 id, void* out);
extern "C" s32 fn_8023AA18(void* a, u32 id, void* out);
extern "C" s32 fn_8023AC74(void* a, u32 id, void* out);
extern "C" s32 fn_8023AD54(void* a, u32 id, void* out);
extern "C" u8 fn_801CC820(s32 id, void* pos);
extern "C" u8 fn_801CC538(s32 id, void* a, void* pos, s32* out);
extern "C" void fn_801CC640(s32 id, s32* a, void* pos);
extern "C" void* fn_801F856C(void);
extern "C" char* fn_801F666C(void* base, s32 id);
extern "C" u8 fn_801EAC54(void* list, u32 v);

extern "C" u8 fn_8020E030(char* this_) {
    if (*(f32*)(this_ + 0x78) - *(f32*)(this_ + 0x70) <= lbl_8053FA2C ||
        *(f32*)(this_ + 0x7c) - *(f32*)(this_ + 0x74) <= lbl_8053FA2C) {
        return 0;
    }
    s32 n = -1;
    f32 pos[2];
    f32 buf24[3];
    f32 v[3];
    u8 bufC[16];
    s32 id;
    u8 hit = 0;
    u8 wall = 0;
    v[0] = lbl_8053FA2C;
    v[1] = lbl_8053FA2C;
    v[2] = lbl_8053FA2C;
    fn_801F317C(this_, bufC);
    id = fn_8023AE34(bufC, *(u32*)(this_ + 0x4), pos);
    if (id >= 0) {
        hit = fn_801CC820(id, v);
    } else {
        id = fn_8023AA18(bufC, *(u32*)(this_ + 0x4), pos);
        if (id >= 0) {
            wall = 1;
        } else {
            id = fn_8023AC74(bufC, *(u32*)(this_ + 0x4), pos);
            if (id >= 0) {
                fn_801CC538(id, pos, buf24, &n);
            } else {
                id = fn_8023AD54(bufC, *(u32*)(this_ + 0x4), pos);
                if (id >= 0) {
                    fn_801CC640(id, &n, v);
                }
            }
        }
    }
    u8 r = 0;
    if (id >= 0) {
    if (hit) {
        r = 1;
    } else if (wall) {
        if (fn_801EAC20(this_ + 0x1dc, id)) {
            r = 1;
        }
    } else {
        id = n;
        if (id >= 0) {
            char* a = fn_801F666C(fn_801F856C(), id);
            if (a != 0 && fn_801EAC54(this_ + 0x1dc, *(u32*)(a + 0x198))) {
                r = 1;
            }
        }
    }
    if (r) {
        f32 p3[3];
        p3[0] = pos[0];
        p3[1] = pos[1];
        p3[2] = lbl_8053FA2C;
        fn_801CB538(*(u32*)(this_ + 0x4), p3, 0, 0);
    }
    if (r) {
    fn_801F0E34(this_, 0x5007d, 0);
    u8 ok = 0;
    switch (*(s32*)(this_ + 0x248)) {
    case 3:
    case 5:
    case 6:
    case 8:
        ok = 1;
        break;
    }
    if (ok) {
        fn_8020ED5C(this_, 4);
    }
    }
    }
    return r;
}

struct FlorResMgr {
    virtual void v00(); virtual void v01(); virtual void v02();
    virtual void v03();
    virtual void* getRes(u32 type, const char* name);
};
extern char* lbl_8053AAF8;
extern char lbl_8046A430[];
extern "C" void fn_802F86CC(void* mgr, void* pos, void* res, s32 id, void* data, f32 a, f32 b);

extern "C" void fn_8020DB74(char* this_) {
    switch (*(s32*)(this_ + 0x248)) {
    case 0:
    case 1:
    case 10:
        break;
    default: {
    JGeometry::TVec3<f32> pos(*(JGeometry::TVec3<f32>*)(this_ + 0xc));
    if (*(s32*)(this_ + 0x248) == 4 && *(s32*)(this_ + 0x24c) >= 60) {
        if (*(s32*)(this_ + 0x24c) % 4 < 2) {
            pos.x += lbl_8053FA28;
        } else {
            pos.x -= lbl_8053FA28;
        }
    }
    u8 buf[0x3c];
    f32 mtx[3][4];

    *(s32*)(buf + 0x10) = -1;
    *(s32*)(buf + 0x14) = -1;

    for (u8 i = 0; i < 16; i++) {
        buf[i] = i;
    }

    *(s32*)(buf + 0x10) = -1;
    *(s32*)(buf + 0x14) = 0;
    *(s32*)(buf + 0x18) = 0;
    buf[0x1c] = 0;
    buf[0x1d] = 0;
    buf[0x1e] = 0;
    buf[0x1f] = 1;
    buf[0x20] = 1;
    buf[0x21] = 0;
    buf[0x22] = 0;
    buf[0x23] = 0;
    buf[0x24] = 0;
    buf[0x25] = 0;
    buf[0x26] = 1;
    *(s32*)(buf + 0x28) = 3;
    buf[0x2c] = 1;
    buf[0x2d] = 0;
    buf[0x2e] = 0;
    *(s32*)(buf + 0x30) = -1;
    *(s32*)(buf + 0x34) = 0;
    *(s32*)(buf + 0x38) = 2;
    buf[0x1c] = 0;
    buf[0x1d] = 0;

    if (*(u32*)(this_ + 0x230) & 0x8000) {
        f32 zero = lbl_8053FA2C;
        mtx[0][3] = zero;
        mtx[1][3] = zero;
        mtx[2][3] = zero;
        mtx[0][0] = lbl_8053FA30;
        mtx[0][1] = zero;
        mtx[0][2] = zero;
        mtx[1][0] = zero;
        mtx[1][1] = lbl_8053FA28;
        mtx[1][2] = zero;
        mtx[2][0] = zero;
        mtx[2][1] = zero;
        mtx[2][2] = mtx[1][1];
        *(void**)(buf + 0x18) = mtx;
    }
    s32 id = *(s32*)(this_ + 0x280) + 0x321;
    if (*(s32*)(this_ + 0x4) < 8) {
        void* res = ((FlorResMgr*)*(void**)(lbl_8053AAF8 + 0xa4))->getRes('SOB ', lbl_8046A430);
        fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), &pos, res, id, buf, lbl_8053FA28, lbl_8053FA28);
    }
    break;
    }
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
