#include "types.h"
#include "Game/SinitPoolChain.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"

extern "C" void* fn_801F856C();
extern const f32 lbl_8053C3E4;
extern "C" void fn_801D22DC(u8*, s32, s32, s32);
extern "C" void fn_801D1F14(u8*, f32);
extern "C" void* fn_802D6A9C();
extern "C" void fn_802D7704(void*, s32, u8, s32);
extern "C" s32 fn_80230CFC(s32);
extern "C" void fn_80230AD4(s32);
extern "C" void fn_80230224(s32, s32);
extern "C" void fn_8023764C(s32, s32);
extern "C" void fn_80458880(void*, s32, s8);
extern "C" void fn_80230534(s32);
extern "C" void fn_8023077C();
extern "C" void fn_800FE3EC(void*, s32, void*, s32);
extern "C" void fn_8013CC50(s32, void*, s32, s32, s32, s32, s32, s32, f32);
extern "C" void* lbl_8053AF80;
extern "C" u8* lbl_8053AAF8;
extern "C" u8 lbl_8053AA80;
extern "C" s32 fn_801F7A08(void*, u32);
extern "C" void* fn_801F666C(void*, s32);
extern "C" void fn_801F31C4(void*, f32*);
extern int __float_epsilon[];
extern const f32 lbl_8053C3E0;
extern const f32 lbl_8053C3EC;
extern const f32 lbl_8053C3F0;
extern const f32 lbl_8053C400;
extern const f32 lbl_8053C410;
extern const f32 lbl_8053C414;
extern const f32 lbl_8053C418;
extern const f32 lbl_8053C3FC;
extern const f32 lbl_8053C41C;
extern const f32 lbl_8053C420;
extern const f32 lbl_8053C424;
extern const f32 lbl_8053C3E8;
extern "C" const char lbl_804642C0[];
extern "C" void v06__5ActorFv(void* self);
extern "C" void fn_801F02BC(void* self, const char* p, s32 a, void* tbl, s32 b, s32 c, s32 d, f32 e, f32 f);
extern "C" s32 Actor_CreateByID(void* mgr, u32 name, u32 id, void* pos, u32 arg5, s32 arg6, s32 arg7);
extern "C" void fn_80109534(u8* this_) {
    if (*(s32*)(this_ + 0x310) < 0) {
        s32 id = Actor_CreateByID(fn_801F856C(), 0x4C494D54, *(u32*)(this_ + 4), this_ + 0xC, 0, -1, -1);
        *(s32*)(this_ + 0x310) = id;
        if (*(s32*)(this_ + 0x310) < 0) {
            return;
        }
    }
    u8* o = (u8*)fn_801F666C(fn_801F856C(), *(s32*)(this_ + 0x310));
    if (o == 0) {
        *(s32*)(this_ + 0x310) = -1;
    } else {
        if (*(u8*)(this_ + 0x2f8) != 0 || *(s32*)(this_ + 0x328) == 0xc) {
            *(u8*)(o + 0x11d) = 1;
        } else {
            *(u8*)(o + 0x11d) = 0;
        }
        switch (*(s32*)(this_ + 0x328)) {
        case 0xc:
            if (*(s32*)(this_ + 0x358) < 8) {
                s32 v = *(s32*)(this_ + 0x108) + 2;
                *(s32*)(o + 0x250) = *(s32*)(this_ + 0x198);
                *(f32*)(o + 0x254) = lbl_8053C3FC;
                *(s32*)(o + 0x24c) = v;
            } else if (*(s32*)(this_ + 0x358) < 0xc) {
                s32 v = *(s32*)(this_ + 0x108);
                *(s32*)(o + 0x250) = *(s32*)(this_ + 0x198);
                *(f32*)(o + 0x254) = lbl_8053C3FC;
                *(s32*)(o + 0x24c) = v;
            } else {
                *(u8*)(o + 0x11d) = 0;
            }
            break;
        default: {
            s32 v = *(s32*)(this_ + 0x108);
            if (v != 0) {
                if (v == 4) {
                    *(s32*)(o + 0x250) = *(s32*)(this_ + 0x198);
                    *(f32*)(o + 0x254) = lbl_8053C3FC;
                    *(s32*)(o + 0x24c) = v;
                } else if (*(s32*)(this_ + 0x30c) < 0x2d && *(u8*)(this_ + 0x2f8) != 0) {
                    *(s32*)(o + 0x250) = *(s32*)(this_ + 0x198);
                    *(f32*)(o + 0x254) = lbl_8053C3FC;
                    *(s32*)(o + 0x24c) = v + 2;
                } else {
                    *(s32*)(o + 0x250) = *(s32*)(this_ + 0x198);
                    *(f32*)(o + 0x254) = lbl_8053C3FC;
                    *(s32*)(o + 0x24c) = v;
                }
            }
            break;
        }
        }
    }
}

extern "C" s32 fn_801096C8(u8* self, u32 state) {
    JGeometry::TVec3<f32> posCreate;
    JGeometry::TVec3<f32> posEffect;
    JGeometry::TVec3<f32> pos7;
    JGeometry::TVec3<f32> pos8;
    s32 actorId;
    *(u32*)(self + 0x32c) = *(u32*)(self + 0x328);
    *(u32*)(self + 0x328) = state;
    self[0x338] = 0;
    switch (state) {
    case 0: return 0;
    case 1:
        self[0x338] = 1;
        fn_801D22DC(self + 0x33c, 7, 2, 0);
        break;
    case 5: {
        actorId = *(s32*)(self + 0x16c);
        if (actorId != -1) fn_802D7704(fn_802D6A9C(), actorId, self[0x1a8], *(s32*)(self + 4));
        fn_801D22DC(self + 0x33c, 2, 2, 0);
        break;
    }
    case 6:
        fn_801D22DC(self + 0x33c, 2, 2, 0);
        break;
    case 7: {
        pos7 = *(JGeometry::TVec3<f32>*)(self + 0xc);
        pos7.y += lbl_8053C3E4;
        fn_8013CC50(*(s32*)(self + 4), &pos7, 0x33a, 0, 0, 0, 0, 1, lbl_8053C3E8);
        fn_801D22DC(self + 0x33c, 9, 0, 0);
        break;
    }
    case 8: {
        pos8 = *(JGeometry::TVec3<f32>*)(self + 0xc);
        pos8.y += lbl_8053C3E4;
        fn_8013CC50(*(s32*)(self + 4), &pos8, 0x33a, 0, 0, 0, 0, 1, lbl_8053C3E8);
        fn_801D22DC(self + 0x33c, 2, 2, 0);
        break;
    }
    case 9:
        fn_801D22DC(self + 0x33c, fn_80230CFC(*(s32*)(self + 0x300)), 2, 0);
        break;
    case 10:
        fn_801D22DC(self + 0x33c, fn_80230CFC(*(s32*)(self + 0x300)), 2, 0);
        break;
    case 11:
        fn_801D22DC(self + 0x33c, *(s32*)(self + 0x98) + 10, 0, 0);
        self[0x2f8] = 1;
        break;
    case 12:
        fn_801D22DC(self + 0x33c, 4, 0, 0);
        fn_80458880(lbl_8053AF80, 10, (s8)*(s32*)(self + 0x300));
        for (s32 i = 0; i < 4; ++i) fn_80230AD4(i);
        break;
    case 13: {
        for (s32 i = 0; i < 4; ++i) {
            fn_80230224(i, 0);
            if (lbl_8053AAF8[0x82] & (u8)(1 << i)) fn_8023764C(i, 0);
        }
        actorId = *(s32*)(self + 0x310);
        if (actorId >= 0) {
            u8* obj = (u8*)fn_801F666C(fn_801F856C(), actorId);
            if (obj && *(u32*)(obj + 0x1a0) == 0x4c494d54) obj[0x11c] = 0;
        }
        *(s32*)(self + 0x308) = 0;
        *(s32*)(self + 0x310) = -1;
        return 1;
    }
    case 14:
        fn_801D22DC(self + 0x33c, 2, 2, 0);
        lbl_8053AA80 = 0;
        *(s32*)(self + 0x108) = 4;
        self[0x2f8] = 1;
        *(s32*)(self + 0x30c) = 0;
        *(s32*)(self + 0x310) = Actor_CreateByID(fn_801F856C(), 0x4c494d54, *(u32*)(self + 4), self + 0xc, 0, -1, -1);
        break;
    case 15: {
        if (*(s32*)(self + 0x2fc) > 0 && *(s32*)(self + 0x320) == 0) {
            posCreate = *(JGeometry::TVec3<f32>*)(self + 0xc);
            fn_800FE3EC(self + 0x230, *(s32*)(self + 0x2fc), &posCreate, *(s32*)(self + 4));
        }
        fn_8023077C();
        posEffect = *(JGeometry::TVec3<f32>*)(self + 0xc);
        posEffect.y += lbl_8053C3E4;
        fn_8013CC50(*(s32*)(self + 4), &posEffect, 0x33a, 0, 0, 0, 0, 1, lbl_8053C3E8);
        break;
    }
    case 16:
        fn_80230534(0);
        fn_801D22DC(self + 0x33c, 7, 2, 0);
        self[0x338] = 1;
        *(s32*)(self + 0x318) = 0;
        break;
    case 17:
        self[0x338] = 1;
        break;
    default: return 0;
    }
    fn_801D1F14(self + 0x33c, lbl_8053C3E0);
    return 1;
}

extern "C" s32 fn_80109AE0(char* self, f32* out) {
    out[2] = lbl_8053C3E0;
    out[1] = lbl_8053C3E0;
    out[0] = lbl_8053C3E0;
    s32 id = fn_801F7A08(fn_801F856C(), 0x43495243);
    if (id < 0) return 0;
    char* o = (char*)fn_801F666C(fn_801F856C(), id);
    if (o == 0) return 0;
    if (*(u8*)(o + 0x11c) == 0) return 0;
    if (*(s32*)(self + 4) != *(s32*)(o + 4)) return 0;
    f32 a[4], b[4];
    fn_801F31C4(self, a);
    fn_801F31C4(o, b);
    b[0] += lbl_8053C410;
    b[1] += lbl_8053C410;
    b[2] += lbl_8053C3EC;
    b[3] += lbl_8053C3EC;
    f32 a0 = a[0], a1 = a[1], a2 = a[2], a3 = a[3];
    if (a0 <= b[0]) a0 = b[0];
    if (a1 <= b[1]) a1 = b[1];
    if (a2 >= b[2]) a2 = b[2];
    if (a3 >= b[3]) a3 = b[3];
    bool hit = false;
    if (a2 >= a0 && a3 >= a1) hit = true;
    if (hit) {
        Vec p;
        p = *(Vec*)(o + 0xc);
        Vec* v = (Vec*)out;
        out[0] = *(f32*)(self + 0xc) - p.x;
        out[1] = *(f32*)(self + 0x10) - p.y;
        out[2] = lbl_8053C3E0;
        f32 sq = JMathInlineVEC::PSVECSquareMag(v);
        if (!(sq <= lbl_8053C400 * *(f32*)__float_epsilon)) {
            f32 inv;
            if (sq <= lbl_8053C3E0) {
                inv = sq;
            } else {
                f32 y = __frsqrte(sq);
                inv = lbl_8053C3F0 * y * (lbl_8053C414 - sq * (y * y));
            }
            JMathInlineVEC::PSVECScale(v, v, inv);
        }
        JMathInlineVEC::PSVECScale(v, v, lbl_8053C418);
        return 1;
    }
    return 0;
}

extern "C" void fn_80109D78(u8* this_) {
    v06__5ActorFv(this_);
    struct {
        s32 a;
        s32 b;
        s32 c;
        u8 d[11];
        s32 e;
        u8 f[3];
        s32 g;
        s32 h;
        s32 i;
    } st;
    u8 tbl[16];
    st.a = -1;
    st.b = -1;
    for (u8 i = 0; i < 0x10; i += 8) {
        tbl[(u8)(i + 0)] = i + 0;
        tbl[(u8)(i + 1)] = i + 1;
        tbl[(u8)(i + 2)] = i + 2;
        tbl[(u8)(i + 3)] = i + 3;
        tbl[(u8)(i + 4)] = i + 4;
        tbl[(u8)(i + 5)] = i + 5;
        tbl[(u8)(i + 6)] = i + 6;
        tbl[(u8)(i + 7)] = i + 7;
    }
    st.a = -1;
    st.b = 0;
    st.c = 0;
    st.d[0] = 0;
    st.d[1] = 0;
    st.d[2] = 0;
    st.d[3] = 1;
    st.d[4] = 1;
    st.d[5] = 0;
    st.d[6] = 0;
    st.d[7] = 0;
    st.d[8] = 0;
    st.d[9] = 0;
    st.d[10] = 1;
    st.e = 3;
    st.f[0] = 1;
    st.f[1] = 0;
    st.f[2] = 0;
    st.g = -1;
    st.h = 0;
    st.i = 2;
    if (*(u8*)(this_ + 0x2f8) != 0) {
        f32 x = (f32)(*(s32*)(this_ + 0x30c) * 60);
        ((u8*)&st.a)[3] = (u8)(s32)(lbl_8053C41C * JMath::sincosTable_.sinLap(x));
    }
    if (*(s32*)(this_ + 0x320) == 0) {
        fn_801F02BC(this_, lbl_804642C0, *(s32*)(this_ + 0x34c) + 0x218, tbl, 0x407, 0, 0, lbl_8053C3E8, lbl_8053C3E8);
    } else {
        fn_801F02BC(this_, lbl_804642C0, *(s32*)(this_ + 0x34c) + 0x9b, tbl, 0x407, 0, 0, lbl_8053C3E8, lbl_8053C3E8);
    }
}

extern "C" void v01__5ActorFv(void* this_);
extern "C" void fn_801D2608(u8* a, const char* b, s32 c);
extern "C" void fn_801D22DC(u8* a, s32 b, s32 c, s32 d);
extern "C" void fn_801D1F14(u8* a, f32 b);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D7440(void* a, s32 b);
extern "C" void* fn_801F856C(void);
extern "C" s32 Actor_CreateByID(void* mgr, u32 name, u32 id, void* pos, u32 arg5, s32 arg6, s32 arg7);
extern "C" const char lbl_8049CEA8[];
extern "C" const char lbl_8049CE70[];
extern "C" const f32 lbl_8053C3E0;
extern "C" const f32 lbl_8053C43C;
extern "C" const f32 lbl_8053C440;
extern "C" void fn_8010AE10(u8* this_) {
    v01__5ActorFv(this_);
    *(s32*)(this_ + 0x320) = *(s32*)(this_ + 0x90) & 0x1f;
    *(s32*)(this_ + 0x324) = (*(s32*)(this_ + 0x90) >> 4) & 0x1f;
    *(s32*)(this_ + 0x2fc) = (*(s32*)(this_ + 0x90) >> 8) & 0xff;
    *(f32*)(this_ + 0x60) = lbl_8053C43C;
    *(f32*)(this_ + 0x64) = lbl_8053C43C;
    *(f32*)(this_ + 0x68) = lbl_8053C440;
    *(f32*)(this_ + 0x6C) = lbl_8053C440;
    *(f32*)(this_ + 0x70) = lbl_8053C43C;
    *(f32*)(this_ + 0x74) = lbl_8053C43C;
    *(f32*)(this_ + 0x78) = lbl_8053C440;
    *(f32*)(this_ + 0x7C) = lbl_8053C440;
    *(f32*)(this_ + 0x80) = lbl_8053C43C;
    *(f32*)(this_ + 0x84) = lbl_8053C43C;
    *(f32*)(this_ + 0x88) = lbl_8053C440;
    *(f32*)(this_ + 0x8C) = lbl_8053C440;
    *(s32*)(this_ + 0x108) = 4;
    *(s32*)(this_ + 0xB8) = 2;
    *(u8*)(this_ + 0x11E) = 1;
    if (*(s32*)(this_ + 0x320) == 0) {
        fn_801D2608(this_ + 0x33C, lbl_8049CEA8, 0xe);
    } else {
        fn_801D2608(this_ + 0x33C, lbl_8049CE70, 0xe);
    }
    fn_801D22DC(this_ + 0x33C, 2, 2, 0);
    fn_801D1F14(this_ + 0x33C, lbl_8053C3E0);
    fn_802D7440(fn_802D6A9C(), 0);
    s32 id = Actor_CreateByID(fn_801F856C(), 0x4C494D54, *(u32*)(this_ + 4), this_ + 0xC, 0, -1, -1);
    *(s32*)(this_ + 0x310) = id;
}

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* p);
extern "C" void __ct__5ActorFv(void* this_);
extern "C" void fn_801D267C(void* anim);
extern void* lbl_8049CEE0[];
extern void* lbl_8049CC34[];
extern u8 lbl_8053AA81;
extern const f32 lbl_8053C3E8;
extern "C" void* fn_8010AF3C(u8* self, s16 deleting) {
    if (self) {
        *(void***)(self) = lbl_8049CEE0;
        lbl_8053AA81 = 0;
        if (self + 0x33c) {
            if (self + 0x360) {
                *(void***)(self + 0x360) = lbl_8049CC34;
            }
        }
        __dt__5ActorFv(self, 0);
        if (deleting > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

extern "C" void* fn_8010AFC4(u8* self) {
    __ct__5ActorFv(self);
    *(void***)(self) = lbl_8049CEE0;
    *(u8*)(self + 0x2f8) = 0;
    *(s32*)(self + 0x2fc) = 0;
    *(s32*)(self + 0x300) = -1;
    *(s32*)(self + 0x304) = -1;
    *(s32*)(self + 0x308) = 0;
    *(s32*)(self + 0x30c) = 0;
    *(s32*)(self + 0x310) = -1;
    *(s32*)(self + 0x314) = 0;
    *(s32*)(self + 0x31c) = -1;
    *(s32*)(self + 0x320) = 0;
    *(s32*)(self + 0x324) = 0;
    *(s32*)(self + 0x328) = 0;
    *(s32*)(self + 0x32c) = 0;
    *(f32*)(self + 0x330) = lbl_8053C3E8;
    *(f32*)(self + 0x334) = lbl_8053C3E0;
    *(u8*)(self + 0x338) = 1;
    *(u8*)(self + 0x339) = 1;
    fn_801D267C(self + 0x33c);
    return self;
}

