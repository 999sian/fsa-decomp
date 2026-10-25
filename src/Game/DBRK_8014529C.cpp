// DBRK_8014529C: .text 0x8014529C-0x80145F60 (actor DBRK)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JGeometry/Box.h"

// ---- from Game/fn_8014529C_dtor.cpp

extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049F498[];

extern "C" void* fn_8014529C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049F498;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

extern "C" void fn_801F06F0(void* actor, const char* tbl, s32 idx, u32 p4, s32 p5, f32 a, f32 b);
extern const char lbl_80465BA8[];
extern const f32 lbl_8053D020;
extern const f32 lbl_8053D034;
extern const f32 lbl_8053D038;
extern const f32 lbl_8053D03C;

extern "C" void fn_801452FC(char* this_) {
    s32 state = *(s32*)(this_ + 0x230);
    s32 idx = *(s32*)(this_ + 0x244) + *(s32*)(this_ + 0x98) * 2;
    if (state == 3 || state == 4) {
        idx = 8;
    }
    if (state != 4 || (*(u32*)(this_ + 0x23c) & 1)) {
        fn_801F06F0(this_, lbl_80465BA8, idx + 0x1c, 0, 0, lbl_8053D020, lbl_8053D020);
    }
}

struct DbrkRandom {
    u32 seed;
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - lbl_8053D020;
    }
};
struct DbrkGame { u8 pad[0xb4]; DbrkRandom rnd; };
extern DbrkGame* lbl_8053AAF8;

extern const f32 lbl_8053D024;
extern const f32 lbl_8053D028;
extern const f32 lbl_8053D02C;
extern const f32 lbl_8053D030;
extern const u32 lbl_80465B98[4];
extern "C" void fn_802397B4(void* box, u32 room, s32 h);
extern "C" s32 fn_801F285C(void* a, s32 b, s32 c, s32 d, s32 e);
extern "C" u8 fn_802379E4(s32 idx, void* pos);
extern "C" void fn_8013CC50(u32 room, void* pos, f32 f, s32 se, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_801F0E34(void* a, s32 b, s32 c);
extern "C" s32 fn_801F3D94(void* a, s32 b);
extern "C" u8 fn_801F2618(void* a, s32 b, s32 c);
extern "C" void fn_801F2B7C(void* a, s32 b, s32 c, s32 d);
extern "C" s32 fn_801A6108(s32 h, void* box, void* pos);
extern "C" s32 fn_801A4D1C(s32 h, void* box, void* pos);
extern "C" s32 fn_801A46FC(s32 h, void* box, void* pos);
extern "C" u8 fn_801F2DB4(void* a, u32 b, u32 c, void* d);
extern "C" void fn_80145374(char* this_) {
    JGeometry::TBox2<f32> box;
    u32 tags[4];
    JGeometry::TVec2<f32> pos;
    JGeometry::TVec2<f32> cen;

    box.i.x = *(f32*)(this_ + 0x60);
    box.i.y = *(f32*)(this_ + 0x64);
    box.f.x = *(f32*)(this_ + 0x68);
    box.f.y = *(f32*)(this_ + 0x6c);
    f32 px = *(f32*)(this_ + 0xc);
    f32 py = *(f32*)(this_ + 0x10);
    pos.x = px;
    pos.y = py;
    box.addPos(pos);

    if (*(s32*)(this_ + 0x230) == 2 || *(s32*)(this_ + 0x230) == 3 || *(s32*)(this_ + 0x230) == 4) {
        fn_802397B4(&box, *(u32*)(this_ + 4), *(s32*)(this_ + 0x198));
        for (s32 i = 0; i < 4; i++) {
            s32 p = fn_801F285C(this_, 0, 0, 0, i);
            if (p >= 0) {
                cen.x = lbl_8053D024 * (box.i.x - box.f.x) + box.f.x;
                cen.y = lbl_8053D024 * (box.i.y - box.f.y) + box.f.y;
                if (fn_802379E4(p, &cen)) {
                    fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, lbl_8053D020, 0x117, 0, 1, 0, 0, 1);
                    fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, lbl_8053D020, 0x118, 0, 1, 0, 0, 1);
                    fn_801F0E34(this_, 0x400d1, 0);
                }
            }
        }
    }

    if (fn_801F3D94(this_, 1) != 0) {
        f32 z = lbl_8053D028;
        *(f32*)(this_ + 0x3c) = z;
        *(f32*)(this_ + 0x40) = z;
        *(f32*)(this_ + 0x44) = z;
        fn_801F2618(this_, 0, 0);
        return;
    }

    if (*(s32*)(this_ + 0x230) != 2 && *(s32*)(this_ + 0x230) != 3 && *(s32*)(this_ + 0x230) != 4) {
        *(u32*)(this_ + 0xb0) = 0x08042104;
        for (s32 i = 0; i < 4; i++) {
            if (fn_801F285C(this_, 0, 0, 1, i) >= 0 ||
                fn_801A6108(*(s32*)(this_ + 0x198), &box, &pos) != 0 ||
                fn_801A4D1C(*(s32*)(this_ + 0x198), &box, &pos) != 0 ||
                fn_801A46FC(*(s32*)(this_ + 0x198), &box, &pos) != 0) {
                f32 z = lbl_8053D028;
                *(s32*)(this_ + 0x108) = 4;
                *(s32*)(this_ + 0x250) -= 1;
                *(f32*)(this_ + 0x3c) = z;
                *(f32*)(this_ + 0x40) = z;
                *(f32*)(this_ + 0x44) = z;
                if (*(s32*)(this_ + 0x250) <= 0) {
                    *(f32*)(this_ + 0x44) = z;
                    *(f32*)(this_ + 0x40) = z;
                    *(f32*)(this_ + 0x3c) = z;
                    *(s32*)(this_ + 0x230) = 2;
                }
                fn_801F2618(this_, 0, 0);
                return;
            }
        }
        *(u32*)(this_ + 0xb0) = 0x08002100;
    }

    if (*(s32*)(this_ + 0x230) != 2 && *(s32*)(this_ + 0x230) != 3 && *(s32*)(this_ + 0x230) != 4) {
        s32 old108 = *(s32*)(this_ + 0x108);
        tags[0] = lbl_80465B98[0];
        tags[1] = lbl_80465B98[1];
        tags[2] = lbl_80465B98[2];
        tags[3] = lbl_80465B98[3];
        if (fn_801F2DB4(this_, 0x4e554c4c, 0x4e554c4c, tags)) {
            if (old108 == *(s32*)(this_ + 0x108)) {
                f32 z = lbl_8053D028;
                *(f32*)(this_ + 0x44) = z;
                *(f32*)(this_ + 0x40) = z;
                *(f32*)(this_ + 0x3c) = z;
                *(s32*)(this_ + 0x230) = 2;
            }
            fn_801F2618(this_, 0, 0);
            return;
        }
    } else {
        if (fn_801F2DB4(this_, 0x4e554c4c, 0x48424d42, 0)) {
            fn_801F0E34(this_, 0x400d1, 0);
            f32 z = lbl_8053D028;
            *(f32*)(this_ + 0x3c) = z;
            *(f32*)(this_ + 0x40) = z;
            *(f32*)(this_ + 0x44) = z;
            *(s32*)(this_ + 0xd8) = 0;
            *(s32*)(this_ + 0xdc) = 0;
        }
    }

    if (*(s32*)(this_ + 0x234) > 0) {
        *(s32*)(this_ + 0x234) -= 1;
    }
    if (*(s32*)(this_ + 0x238) > 0) {
        *(s32*)(this_ + 0x238) -= 1;
    }
    if (*(s32*)(this_ + 0x23c) > 0) {
        *(s32*)(this_ + 0x23c) -= 1;
    }
    if (*(s32*)(this_ + 0x240) > 0) {
        *(s32*)(this_ + 0x240) -= 1;
    }

    *(JGeometry::TVec3<f32>*)(this_ + 0xc) += *(JGeometry::TVec3<f32>*)(this_ + 0x3c);
    u8 hit = fn_801F2618(this_, 0, 0);
    if (*(s32*)(this_ + 0x230) != 2 && *(s32*)(this_ + 0x230) != 3 && *(s32*)(this_ + 0x230) != 4) {
        fn_801F2B7C(this_, -100, -1, 1);
    }

    switch (*(s32*)(this_ + 0x230)) {
    case 0:
        if (*(s32*)(this_ + 0x254) != 0) {
            if (*(u8*)(this_ + 0xc4) == 0) {
                *(f32*)(this_ + 0x44) -= lbl_8053D024;
            }
            f32 z = lbl_8053D028;
            if (*(f32*)(this_ + 0x14) < z && *(f32*)(this_ + 0x44) < z) {
                *(f32*)(this_ + 0x3c) = z;
                *(f32*)(this_ + 0x40) = z;
                *(f32*)(this_ + 0x44) = z;
                *(f32*)(this_ + 0x14) = z;
                *(s32*)(this_ + 0x254) = 0;
                *(s32*)(this_ + 0x234) = 8;
            }
        }
        if (*(s32*)(this_ + 0x238) == 0 && *(s32*)(this_ + 0x254) == 0) {
            if ((*(u32*)(this_ + 0x98) & 2) == 0) {
                if (lbl_8053AAF8->rnd.get_ufloat_1() < lbl_8053D024) {
                    *(s32*)(this_ + 0x98) = 2;
                } else {
                    *(s32*)(this_ + 0x98) = 3;
                }
            } else {
                if (lbl_8053AAF8->rnd.get_ufloat_1() < lbl_8053D024) {
                    *(s32*)(this_ + 0x98) = 0;
                } else {
                    *(s32*)(this_ + 0x98) = 1;
                }
            }
            switch (*(s32*)(this_ + 0x98)) {
            case 0: {
                f32 z = lbl_8053D028;
                *(f32*)(this_ + 0x3c) = lbl_8053D020;
                *(f32*)(this_ + 0x40) = z;
                *(f32*)(this_ + 0x44) = z;
                break;
            }
            case 1: {
                f32 z = lbl_8053D028;
                *(f32*)(this_ + 0x3c) = lbl_8053D02C;
                *(f32*)(this_ + 0x40) = z;
                *(f32*)(this_ + 0x44) = z;
                break;
            }
            case 2: {
                f32 z = lbl_8053D028;
                *(f32*)(this_ + 0x3c) = z;
                *(f32*)(this_ + 0x40) = lbl_8053D020;
                *(f32*)(this_ + 0x44) = z;
                break;
            }
            case 3: {
                f32 z = lbl_8053D028;
                *(f32*)(this_ + 0x3c) = z;
                *(f32*)(this_ + 0x40) = lbl_8053D02C;
                *(f32*)(this_ + 0x44) = z;
                break;
            }
            }
            *(s32*)(this_ + 0x234) = 0;
            *(s32*)(this_ + 0x238) = (s32)(lbl_8053D030 * lbl_8053AAF8->rnd.get_ufloat_1()) + 50;
            *(s32*)(this_ + 0x230) = 1;
        }
        break;
    case 1:
        if (hit != 0 || *(s32*)(this_ + 0x238) == 0) {
            *(s32*)(this_ + 0x24c) = 0;
            if (hit != 0) {
                *(s32*)(this_ + 0x24c) = 1;
            }
            *(s32*)(this_ + 0x234) = 8;
            f32 z = lbl_8053D028;
            *(s32*)(this_ + 0x238) = (s32)(lbl_8053D030 * lbl_8053AAF8->rnd.get_ufloat_1()) + 50;
            *(f32*)(this_ + 0x3c) = z;
            *(f32*)(this_ + 0x40) = z;
            *(f32*)(this_ + 0x44) = z;
            *(s32*)(this_ + 0x230) = 0;
        }
        break;
    case 2:
        *(s32*)(this_ + 0x238) = 200;
        *(u32*)(this_ + 0xb0) = 0x0a042104;
        fn_801F0E34(this_, 0x400d1, 0);
        *(s32*)(this_ + 0x230) = 3;
    case 3:
        if (*(s32*)(this_ + 0x238) == 0) {
            *(s32*)(this_ + 0x23c) = 100;
            *(s32*)(this_ + 0x230) = 4;
        }
        break;
    case 4:
        if (*(s32*)(this_ + 0x23c) == 0) {
            *(s32*)(this_ + 0x98) = (s32)(lbl_8053D034 * lbl_8053AAF8->rnd.get_ufloat_1()) & 3;
            switch (*(s32*)(this_ + 0x98)) {
            case 0: {
                f32 z = lbl_8053D028;
                *(f32*)(this_ + 0x3c) = lbl_8053D020;
                *(f32*)(this_ + 0x40) = z;
                *(f32*)(this_ + 0x44) = z;
                break;
            }
            case 1: {
                f32 z = lbl_8053D028;
                *(f32*)(this_ + 0x3c) = lbl_8053D02C;
                *(f32*)(this_ + 0x40) = z;
                *(f32*)(this_ + 0x44) = z;
                break;
            }
            case 2: {
                f32 z = lbl_8053D028;
                *(f32*)(this_ + 0x3c) = z;
                *(f32*)(this_ + 0x40) = lbl_8053D020;
                *(f32*)(this_ + 0x44) = z;
                break;
            }
            case 3: {
                f32 z = lbl_8053D028;
                *(f32*)(this_ + 0x3c) = z;
                *(f32*)(this_ + 0x40) = lbl_8053D02C;
                *(f32*)(this_ + 0x44) = z;
                break;
            }
            }
            *(u32*)(this_ + 0xb0) = 0x08042104;
            *(s32*)(this_ + 0x250) = 1;
            f32 z = lbl_8053D028;
            *(f32*)(this_ + 0x3c) = z;
            *(f32*)(this_ + 0x40) = z;
            *(f32*)(this_ + 0x44) = z;
            *(s32*)(this_ + 0x230) = 0;
        }
        break;
    }

    if (*(s32*)(this_ + 0x234) <= 0) {
        *(s32*)(this_ + 0x234) = 8;
        *(s32*)(this_ + 0x244) += 1;
        *(s32*)(this_ + 0x244) &= 1;
    }
}

extern "C" void fn_80145C70(char* this_) {
    f32 b = lbl_8053D03C;
    f32 a = lbl_8053D038;
    *(f32*)(this_ + 0x60) = a;
    *(f32*)(this_ + 0x64) = a;
    *(f32*)(this_ + 0x68) = b;
    *(f32*)(this_ + 0x6c) = b;
    *(f32*)(this_ + 0x80) = a;
    *(f32*)(this_ + 0x84) = a;
    *(f32*)(this_ + 0x88) = b;
    *(f32*)(this_ + 0x8c) = b;
    *(s32*)(this_ + 0x98) = (s32)(lbl_8053D034 * lbl_8053AAF8->rnd.get_ufloat_1()) & 3;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x108) = 4;
    *(s32*)(this_ + 0x250) = 1;
    *(u32*)(this_ + 0xb0) = 0x08042104;
    *(s32*)(this_ + 0x230) = 0;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
