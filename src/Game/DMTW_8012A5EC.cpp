#include "types.h"

extern s32 lbl_8053AAF8;
extern s32 lbl_8053AB10;
extern "C" void fn_802D9FF4(s32, s32, s32);
extern "C" void fn_80136798(s32, s32, s32);
extern "C" void fn_8011921C(void);
extern "C" void fn_801183BC(void);
extern "C" s32 fn_802D6A9C(void);
extern "C" s32 fn_80119DD0(void);
extern "C" void fn_80119468(s32, s32, s32);
extern "C" u8 fn_803865B8(s32);
extern "C" void fn_80388EEC(s32);
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JUtility/JUTVideo.h"

extern "C" u8 fn_8012A5EC(void*);
extern "C" void fn_8022FE80(int, int, int, u8, u8);
extern "C" u8 fn_8038BD08(s32, s32, u32, JGeometry::TVec3<f32>*, s32);
extern "C" void fn_8011921C();
extern "C" void fn_80118454();
extern "C" void fn_801183BC();
extern "C" u8 fn_803865B8(s32);
extern "C" void fn_80388EEC(s32);
extern s32 lbl_804650C8[];
extern u8 lbl_8053CB60[4];
extern "C" void fn_801F0E34(void* self, u32 id, s32 flag);
extern "C" f32 lbl_8053CB90;
extern "C" void fn_80239914(void*, u32, u32);
extern "C" void fn_8012A8C0(char* this_) {
    struct Vec2 {
        f32 x, y;
    };
    struct Box {
        Vec2 min, max;
    };
    char* p = this_;
    s32 i = 0;
    Box box;
    Box orig;
    box.min.x = *(f32*)(this_ + 0x60);
    orig.min.x = box.min.x;
    box.min.y = *(f32*)(this_ + 0x64);
    orig.min.y = box.min.y;
    box.max.x = *(f32*)(this_ + 0x68);
    orig.max.x = box.max.x;
    box.max.y = *(f32*)(this_ + 0x6c);
    orig.max.y = box.max.y;
    do {
        box.min.x += *(f32*)(p + 0x25c);
        box.min.y += *(f32*)(p + 0x260);
        box.max.x += *(f32*)(p + 0x25c);
        box.max.y += *(f32*)(p + 0x260);
        fn_80239914(&box, *(u32*)(this_ + 4), *(u32*)(this_ + 0x198));
        box = orig;
        i++;
        p += 0xc;
    } while (i < 6);
}

extern "C" void fn_8012A9A0(char* this_) {
    fn_8012A5EC(this_);
    if (*(u8*)(this_ + 0x404) == 0) {
        fn_8022FE80(0, *(s32*)(this_ + 4), *(s32*)(this_ + 0x198), 1, 0);
        if (fn_803865B8(0)) {
            fn_80388EEC(0);
            *(s32*)(this_ + 0x250) = 0x28;
            this_[0x404] = 1;
        }
    } else if (*(s32*)(this_ + 0x250) == 0) {
        fn_8011921C();
        fn_801183BC();
        char* mgr = *(char**)(lbl_8053AB10 + 0x24);
        mgr[0x17a] = 1;
        mgr[0x179] = 0;
        fn_802D9FF4(fn_802D6A9C(), 0, 0);
        fn_80136798(lbl_8053AAF8, 0xd, 0);
        fn_80119468(fn_80119DD0(), 0, 1);
        *(s32*)(this_ + 0x230) += 1;
    }
}

extern "C" void fn_8012B02C(char* this_) {
    fn_8012A5EC(this_);
    fn_8022FE80(0, *(s32*)(this_ + 4), *(s32*)(this_ + 0x198), 1, 0);
    if (fn_803865B8(0)) {
        fn_80388EEC(0);
        fn_8011921C();
        fn_801183BC();
        *(s32*)(this_ + 0x250) = 0x604;
        ++*(s32*)(this_ + 0x230);
        *(f32*)(this_ + 0x244) = (*(f32*)(this_ + 0x23c) - (154.0f + *(f32*)(this_ + 0x3f4))) / 270.0f;
        *(f32*)(this_ + 0x24c) = (*(f32*)(this_ + 0x248) - 186.0f) / 270.0f;
    }
}

extern "C" void fn_8012B0D8(char* this_) {
    u8 result = fn_8012A5EC(this_);
    if (*(f32*)(this_ + 0x23c) == 260.0f + *(f32*)(this_ + 0x3f4) &&
        85.0f == *(f32*)(this_ + 0x248) && result == 1) {
        JGeometry::TVec3<f32> pos(
            (f32)(s32)JUTVideo::getManager()->getFbWidth() / 2.0f,
            (f32)(s32)JUTVideo::getManager()->getEfbHeight() / 2.0f,
            0.0f);
        pos.y += -16.0f;
        fn_8022FE80(0, *(s32*)(this_ + 4), *(s32*)(this_ + 0x198), 1, 0);
        u32 owner = *(u32*)(this_ + 4);
        JGeometry::TVec3<f32> copy(pos);
        if (fn_8038BD08(0, lbl_804650C8[*(s32*)(this_ + 0x254)], owner, &copy, 0x22)) {
            ++*(s32*)(this_ + 0x254);
            fn_8011921C();
            fn_80118454();
            ++*(s32*)(this_ + 0x230);
        }
    }
}

extern "C" void* fn_8013CC50(u32 room, void* pos, f32 scale, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern u8 lbl_8053CB64[];
extern f32 lbl_8053CB8C;
extern f32 lbl_8053CBB0;
extern "C" void fn_8012BC40(char* this_) {
    u8 result = fn_8012A5EC(this_);
    if (*(f32*)(this_ + 0x23c) == 279.0f + *(f32*)(this_ + 0x3f4) && 105.0f == *(f32*)(this_ + 0x248) && result == 1) {
        u8* idx = lbl_8053CB64;
        f32 zero = lbl_8053CB8C;
        f32 half = lbl_8053CBB0;
        *(JGeometry::TVec3<f32>*)(this_ + 0x2c8) = *(JGeometry::TVec3<f32>*)(this_ + 0x3b8 + idx[0] * 12);
        *(f32*)(this_ + 0x2f8) = zero;
        *(f32*)(this_ + 0x2fc) = zero;
        *(f32*)(this_ + 0x300) = half;
        *(JGeometry::TVec3<f32>*)(this_ + 0x2d4) = *(JGeometry::TVec3<f32>*)(this_ + 0x3b8 + idx[1] * 12);
        *(f32*)(this_ + 0x304) = zero;
        *(f32*)(this_ + 0x308) = zero;
        *(f32*)(this_ + 0x30c) = half;
        *(JGeometry::TVec3<f32>*)(this_ + 0x2e0) = *(JGeometry::TVec3<f32>*)(this_ + 0x3b8 + idx[2] * 12);
        *(f32*)(this_ + 0x310) = zero;
        *(f32*)(this_ + 0x314) = zero;
        *(f32*)(this_ + 0x318) = half;
        *(JGeometry::TVec3<f32>*)(this_ + 0x2ec) = *(JGeometry::TVec3<f32>*)(this_ + 0x3b8 + idx[3] * 12);
        *(f32*)(this_ + 0x31c) = zero;
        *(f32*)(this_ + 0x320) = zero;
        *(f32*)(this_ + 0x324) = half;
        for (s32 i = 0; i < 4; i++) {
            *(void**)(this_ + 0x328 + i * 4) = fn_8013CC50(*(u32*)(this_ + 4), this_ + 0x2c8 + i * 12, 1.0f, 0x3c0 + i * 3, 0, 0, 0, 0, 1);
            *(void**)(this_ + 0x338 + i * 4) = fn_8013CC50(*(u32*)(this_ + 4), this_ + 0x2c8 + i * 12, 1.0f, 0x3c1 + i * 3, 0, 0, 0, 0, 1);
            *(void**)(this_ + 0x348 + i * 4) = fn_8013CC50(*(u32*)(this_ + 4), this_ + 0x2c8 + i * 12, 1.0f, 0x3c2 + i * 3, 0, 0, 0, 0, 1);
        }
        *(s32*)(this_ + 0x230) = *(s32*)(this_ + 0x230) + 1;
        *(s32*)(this_ + 0x234) = 0;
    }
}

extern "C" void fn_8012BE2C(char* this_) {
    fn_8012A5EC(this_);
    fn_8022FE80(0, *(s32*)(this_ + 4), *(s32*)(this_ + 0x198), 1, 0);
    if (fn_803865B8(0)) {
        fn_80388EEC(0);
        fn_8011921C();
        fn_801183BC();
        u8* idx = lbl_8053CB60;
        f32 zero = lbl_8053CB8C;
        f32 half = lbl_8053CBB0;
        *(s32*)(this_ + 0x230) += 2;
        *(JGeometry::TVec3<f32>*)(this_ + 0x2c8) = *(JGeometry::TVec3<f32>*)(this_ + 0x3b8 + idx[0] * 12);
        *(f32*)(this_ + 0x2f8) = zero;
        *(f32*)(this_ + 0x2fc) = zero;
        *(f32*)(this_ + 0x300) = half;
        *(JGeometry::TVec3<f32>*)(this_ + 0x2d4) = *(JGeometry::TVec3<f32>*)(this_ + 0x3b8 + idx[1] * 12);
        *(f32*)(this_ + 0x304) = zero;
        *(f32*)(this_ + 0x308) = zero;
        *(f32*)(this_ + 0x30c) = half;
        *(JGeometry::TVec3<f32>*)(this_ + 0x2e0) = *(JGeometry::TVec3<f32>*)(this_ + 0x3b8 + idx[2] * 12);
        *(f32*)(this_ + 0x310) = zero;
        *(f32*)(this_ + 0x314) = zero;
        *(f32*)(this_ + 0x318) = half;
        *(JGeometry::TVec3<f32>*)(this_ + 0x2ec) = *(JGeometry::TVec3<f32>*)(this_ + 0x3b8 + idx[3] * 12);
        *(f32*)(this_ + 0x31c) = zero;
        *(f32*)(this_ + 0x320) = zero;
        *(f32*)(this_ + 0x324) = half;
        s32 i = 0;
        do {
            void* pos = this_ + 0x2c8 + i * 12;
            *(void**)(this_ + 0x328 + i * 4) = fn_8013CC50(*(u32*)(this_ + 4), pos, lbl_8053CB90, (u16)(0x3c0 + i * 3), 0, 0, 0, 0, 1);
            *(void**)(this_ + 0x338 + i * 4) = fn_8013CC50(*(u32*)(this_ + 4), pos, lbl_8053CB90, (u16)(0x3c1 + i * 3), 0, 0, 0, 0, 1);
            *(void**)(this_ + 0x348 + i * 4) = fn_8013CC50(*(u32*)(this_ + 4), pos, lbl_8053CB90, (u16)(0x3c2 + i * 3), 0, 0, 0, 0, 1);
            i++;
        } while (i < 4);
    }
    *(s32*)(this_ + 0x234) = 0;
    fn_801F0E34(this_, 0x50062, 0);
}

extern "C" void fn_8012C030(char* this_) {
    u8 result = fn_8012A5EC(this_);
    if (*(f32*)(this_ + 0x23c) == 260.0f + *(f32*)(this_ + 0x3f4) &&
        85.0f == *(f32*)(this_ + 0x248) && result == 1) {
        JGeometry::TVec3<f32> pos(
            (f32)(s32)JUTVideo::getManager()->getFbWidth() / 2.0f,
            (f32)(s32)JUTVideo::getManager()->getEfbHeight() / 2.0f,
            0.0f);
        pos.y += -16.0f;
        fn_8022FE80(0, *(s32*)(this_ + 4), *(s32*)(this_ + 0x198), 1, 0);
        u32 owner = *(u32*)(this_ + 4);
        JGeometry::TVec3<f32> copy(pos);
        if (fn_8038BD08(0, lbl_804650C8[*(s32*)(this_ + 0x254)], owner, &copy, 0x22)) {
            ++*(s32*)(this_ + 0x254);
            fn_8011921C();
            fn_80118454();
            ++*(s32*)(this_ + 0x230);
        }
    }
}

extern "C" f32 lbl_8053CBEC;
extern "C" f32 lbl_8053CBB0;
extern "C" void fn_8012C170(char* this_) {
    f32 pos;
    f32 step;
    if (*(s32*)(this_ + 0x250) == 1) {
        fn_80119468(fn_80119DD0(), 0, 0);
    }
    pos = *(f32*)(this_ + 0x3bc);
    f32 threshold = lbl_8053CBEC + *(f32*)(this_ + 0x3f4);
    if (pos >= threshold) {
        step = lbl_8053CBB0;
        *(f32*)(this_ + 0x3bc) = pos - step;
        *(f32*)(this_ + 0x3c8) = *(f32*)(this_ + 0x3c8) - step;
        *(f32*)(this_ + 0x3d4) = *(f32*)(this_ + 0x3d4) - step;
        *(f32*)(this_ + 0x3e0) = *(f32*)(this_ + 0x3e0) - step;
        if (*(s32*)(this_ + 0x3f0) == 0) {
            *(s32*)(this_ + 0x3f0) = 6;
            *(s32*)(this_ + 0x3ec) += 1;
            if (*(s32*)(this_ + 0x3ec) >= 8) {
                *(s32*)(this_ + 0x3ec) = 0;
            }
        }
        fn_8012A5EC(this_);
        return;
    }
    *(f32*)(this_ + 0x3bc) = threshold;
    *(s32*)(this_ + 0x3ec) = 0;
    fn_8012A5EC(this_);
    JGeometry::TVec3<f32> pos2(
        (f32)(s32)JUTVideo::getManager()->getFbWidth() / 2.0f,
        (f32)(s32)JUTVideo::getManager()->getEfbHeight() / 2.0f,
        0.0f);
    pos2.y += -16.0f;
    fn_8022FE80(0, *(s32*)(this_ + 4), *(s32*)(this_ + 0x198), 1, 0);
    u32 owner = *(u32*)(this_ + 4);
    JGeometry::TVec3<f32> copy(pos2);
    if (fn_8038BD08(0, lbl_804650C8[*(s32*)(this_ + 0x254)], owner, &copy, 0x22)) {
        ++*(s32*)(this_ + 0x254);
        fn_8011921C();
        fn_80118454();
        *(s32*)(this_ + 0x230) += 2;
    }
}

extern "C" f32 lbl_8053CB68;
extern "C" f32 lbl_8053CB8C;
extern "C" f32 lbl_8053CBF0;
extern "C" f32 lbl_8053CBF4;
extern "C" s8 lbl_8053AAB0;
extern "C" JGeometry::TVec3<f32> lbl_804BD790[4];
extern "C" s32 fn_80230188(s32 idx);
extern "C" u8 fn_802300EC(s32 idx);
extern "C" void fn_8023EE28(s32 idx);
extern "C" void fn_8023077C(void);
extern "C" void fn_80230498(s32 idx, void* vec, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_8012C334(char* this_) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if ((u8)fn_80230188(i) != 0 || fn_802300EC(i) == 0) {
            goto end;
        }
    }
    if (lbl_8053AAB0 == 0) {
        f32 y = lbl_8053CB68 + *(f32*)(this_ + 0x3f4);
        f32 z = lbl_8053CB8C;
        f32 x = *(f32*)(this_ + 0x3f8);
        y = lbl_8053CBF0 + y;
        JGeometry::TVec3<f32> v0(x - lbl_8053CBF0, y, z);
        JGeometry::TVec3<f32> v1(x - lbl_8053CBF4, y, z);
        JGeometry::TVec3<f32> v2(x + lbl_8053CBF4, y, z);
        JGeometry::TVec3<f32> v3(x + lbl_8053CBF0, y, z);
        lbl_804BD790[0] = v0;
        lbl_804BD790[1] = v1;
        lbl_804BD790[2] = v2;
        lbl_804BD790[3] = v3;
        lbl_8053AAB0 = 1;
    }
    for (i = 0; i < 4; i++) {
        *(JGeometry::TVec3<f32>*)(this_ + 0x3b8 + i * 0xc) = lbl_804BD790[i];
        fn_8023EE28(i);
    }
    fn_8023077C();
    *(s32*)(this_ + 0x3e8) = 0x18;
    *(s32*)(this_ + 0x3ec) = 0;
    *(s32*)(this_ + 0x3f0) = 6;
    for (i = 0; i < 4; i++) {
        fn_80230498(i, this_ + 0x3b8 + i * 0xc, *(s32*)(this_ + 0x3e8) + *(s32*)(this_ + 0x3ec), 0xff, -0x80, -0x80, 1);
    }
end:
    *(s32*)(this_ + 0x230) += 1;
    fn_8012A5EC(this_);
}

extern void* __vt__4DMTW[];
extern "C" void __dt__5ActorFv(void* this_, s32 flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void* fn_8012C4F8(u32* this_, s16 freeFlag) {
    s32 i;
    u32* p;
    u32* a;
    if (this_ != NULL) {
        *(void**)this_ = __vt__4DMTW;
        p = this_;
        for (i = 0; i < 2; i++) {
            a = (u32*)p[0xe2];
            if (a != NULL) {
                a[0x3d] |= 0x100;
                p[0xe2] = 0;
            }
            a = (u32*)p[0xe6];
            if (a != NULL) {
                a[0x3d] |= 0x100;
                p[0xe6] = 0;
            }
            a = (u32*)p[0xea];
            if (a != NULL) {
                a[0x3d] |= 0x100;
                p[0xea] = 0;
            }
            a = (u32*)p[0xe3];
            if (a != NULL) {
                a[0x3d] |= 0x100;
                p[0xe3] = 0;
            }
            a = (u32*)p[0xe7];
            if (a != NULL) {
                a[0x3d] |= 0x100;
                p[0xe7] = 0;
            }
            a = (u32*)p[0xeb];
            if (a != NULL) {
                a[0x3d] |= 0x100;
                p[0xeb] = 0;
            }
            p += 2;
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_801F06F0(void* this_, const char* name, s32 id, s32 a, s32 b, f32 s0, f32 s1);
extern "C" const char lbl_804650E0[];
extern "C" f32 lbl_8053CB90;
extern "C" s32 fn_80230188(s32);
extern "C" void fn_80230498(s32, void*, s32, s32, s32, s32, s32);
extern "C" void fn_8012C638(char* this_) {
    Vec saved;
    s32 i;

    JGeometry::setTVec3f((f32*)(this_ + 0xc), (f32*)&saved);
    for (i = 0; i < 6; i++) {
        JGeometry::setTVec3f((f32*)(this_ + 0x25c + i * 0xc), (f32*)(this_ + 0xc));
        fn_801F06F0(this_, lbl_804650E0, *(s32*)(this_ + 0x2a4 + i * 4) + *(s32*)(this_ + 0x2c0), 0, 7, lbl_8053CB90, lbl_8053CB90);
    }
    if (*(s32*)(this_ + 0x230) > 0) {
        for (i = 0; i < 4; i++) {
            if ((u8)fn_80230188(i)) {
                fn_80230498(i, this_ + 0x3b8 + i * 0xc, *(s32*)(this_ + 0x3e8) + *(s32*)(this_ + 0x3ec), 0xff, -0x80, -0x80, 1);
            }
        }
    }
    JGeometry::setTVec3f((f32*)&saved, (f32*)(this_ + 0xc));
}

extern s32 lbl_8053AF80;
extern s32 lbl_8053AD30;
extern "C" f32 lbl_8053CBF8;
extern "C" char lbl_80529DEC[];
extern "C" char lbl_8050EC80[];
extern "C" void fn_80458FF0(s32, s32, s32, s32);
extern "C" s32 fn_80309C4C(s32, s32, s32);
extern "C" void fn_80387494(s32);
extern "C" void fn_80119958(void);
class DMTW;
typedef void (DMTW::*DMTWStateFn)();
extern DMTWStateFn lbl_8049E6EC[];
extern "C" void fn_8012C73C(char* this_) {
    if (*(s32*)(this_ + 0x258) != 0) {
        *(s32*)(this_ + 0x258) -= 1;
    } else if (*(u32*)(lbl_8053AF80 + 0x58) != 0x100001c) {
        fn_80458FF0(lbl_8053AF80, 0x100001c, 0, 0);
    }
    if (*(s32*)(this_ + 0x3f0) != 0) {
        *(s32*)(this_ + 0x3f0) -= 1;
    }
    if (*(s32*)(this_ + 0x2bc) != 0) {
        *(s32*)(this_ + 0x2bc) -= 1;
    }
    if (*(s32*)(this_ + 0x250) != 0) {
        *(s32*)(this_ + 0x250) -= 1;
    }
    u8* p = *(u8**)(lbl_8053AB10 + 0x30);
    if (p[0x284] == 0) {
        p[0x284] = 1;
        *(f32*)(p + 0x28c) = 0.05f;
    }
    (*(u8**)(lbl_8053AB10 + 0x24))[0x17c] = 1;
    BOOL unlocked;
    s32 a = *(s32*)(lbl_80529DEC + 0x118);
    s32 b = *(s32*)(lbl_80529DEC + 0x11c);
    if (a < 0 || a > 7) {
        unlocked = FALSE;
    } else if (b < 0 || b > 3) {
        unlocked = FALSE;
    } else {
        unlocked = ((1 << (b + a * 4)) & *(u32*)(lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xc8 + 0x28)) != 0;
    }
    if (unlocked && *(s32*)(this_ + 0x230) >= 3 && *(s32*)(this_ + 0x230) <= 9) {
        *(u8*)(lbl_8053AAF8 + 0x85) = 2;
        if ((u32)fn_80309C4C(lbl_8053AD30, 0x1000, -1) != 0) {
            this_[0x404] = 1;
            fn_80387494(0);
            fn_80119DD0();
            fn_80119958();
            *(s32*)(this_ + 0x230) = 9;
            *(s32*)(this_ + 0x250) = 0;
        }
    }
    (((DMTW*)this_)->*lbl_8049E6EC[*(s32*)(this_ + 0x230)])();
}

extern "C" void fn_8012C910(void* this_) {}
