// TU 0x8033f9a0-0x80340ec8 (actor LTZR).
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"
#include "JSystem/JMath/JMath.h"
#include "JSystem/JGeometry.h"
#include "Game/ItemBase.h"

class Ltzr : public ItemBase {
public:
    virtual void v39();
};

// ---- from src/Game/Ltzr_ctor_80340C60.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* fn_801BB3B0(void* this_);
extern void* lbl_804AC3E0[];

extern "C" void fn_801BB30C(void* this_, s32);
extern "C" void __dl__FPv(void*);
extern "C" void fn_801BB1AC(void* this_);
extern "C" void fn_802314D8(s32, f32*);
extern "C" void fn_801F0E34(void*, u32, s32);
extern const f32 lbl_80542268;
extern const f32 lbl_805422AC;
extern const f32 lbl_80542288;
extern const f32 lbl_8054227C;
extern const f32 lbl_8054228C;
extern const f32 lbl_805422B0;
extern const f32 lbl_805422B4;
extern const f32 lbl_8054226C;
extern const f32 lbl_80542270;
extern const f32 lbl_80542274;
extern const f32 lbl_80542278;
extern char lbl_80471EB0[];
extern "C" void fn_801BA670(void);
extern "C" void fn_8033FC4C(Mtx m, f32* scale, f32* rot, f32* trans);
extern "C" void fn_801F06F0(void* this_, const char* name, s32 id, DrawRec* rec, s32 p5, f32 a, f32 b);
extern "C" u8 fn_80233E40(s32);
extern "C" f32* fn_8023E724(s32);
extern "C" void fn_8023DFF4(s32, f32*);
extern "C" void* fn_8013CC50(void*, void*, f32, s32, s32, s32, s32, s32, s32);

extern "C" void* fn_8033F9A0(void* this_, s16 flag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AC3E0;
        fn_801BB30C(this_, 0);
        if (flag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_8033FA00(char* p) {
    fn_801BA670();
    DrawRec rec;
    Mtx m;
    f32 trans[3];
    f32 scale[3];
    f32 rot[3];
    s32 iVar1;

    rec.b20 = 0;
    rec.b21 = 1;
    rec.b1c = 0;
    PSMTXIdentity(m);
    trans[2] = lbl_80542268;
    trans[1] = lbl_80542268;
    trans[0] = lbl_80542268;
    iVar1 = *(s32*)(p + 0x248);
    if (iVar1 != 0) {
        switch (*(u32*)(p + 0x280)) {
        case 0:
        case 4:
            trans[2] = lbl_8054226C;
            rec.b1d = 1;
            break;
        case 1:
        case 3:
        case 5:
        case 7:
            trans[2] = lbl_80542270;
            rec.b1d = 1;
            break;
        case 2:
        case 6:
            trans[2] = lbl_80542274;
            rec.b1d = 1;
            break;
        case 8:
            trans[2] = lbl_80542278;
            rec.b1d = 0;
            break;
        default:
            if (iVar1 == 2 || iVar1 == 5) {
                rec.b1d = 0;
            } else {
                rec.b1d = -1;
            }
            break;
        }
    } else {
        rec.b1d = -1;
    }
    rot[0] = 0.0f;
    rot[1] = 0.0f;
    rot[2] = 0.0f;
    scale[0] = *(f32*)(p + 0x2b4);
    scale[1] = *(f32*)(p + 0x2b4);
    scale[2] = *(f32*)(p + 0x2b4);
    fn_8033FC4C(m, scale, rot, trans);
    rec.w18 = m;
    fn_801F06F0(p, lbl_80471EB0, 0x173, &rec, -1, lbl_8054227C, lbl_8054227C);
}

extern "C" void fn_8033FC4C(Mtx m, f32* scale, f32* rot, f32* trans) {
    f32 sx = sin(rot[0]);
    f32 sy = sin(rot[1]);
    f32 sz = sin(rot[2]);
    f32 cx = cos(rot[0]);
    f32 cy = cos(rot[1]);
    f32 cz = cos(rot[2]);
    f32 sxsy = sx * sy;
    f32 cxsz = cx * sz;
    f32 cxcz = cx * cz;
    f32 sxsz = sx * sz;
    m[0][0] = scale[0] * (cy * cz);
    m[1][0] = scale[0] * (cy * sz);
    m[2][0] = scale[0] * -sy;
    m[0][1] = scale[1] * (sxsy * cz - cxsz);
    m[1][1] = scale[1] * (sxsy * sz + cxcz);
    m[2][1] = scale[1] * (sx * cy);
    m[0][2] = scale[2] * (cxcz * sy + sxsz);
    m[1][2] = scale[2] * (cxsz * sy - sx * cz);
    m[2][2] = scale[2] * (cx * cy);
    m[0][3] = trans[0];
    m[1][3] = trans[1];
    m[2][3] = trans[2];
}

extern "C" void fn_802399D8(s32, f32*, s32, u32);
extern "C" u8 fn_8023B0F4(s32, f32*, s32, f32, s32);
extern "C" u8 fn_8022F478(s32);
extern "C" s32 fn_8022CAF8(s32);
extern "C" s32 fn_8023DE58(s32);
extern "C" void fn_8022E088(s32, s32, f32*);
extern "C" void fn_8022DF48(s32);
extern "C" s32 fn_801D05F8(void*, void*, f32);
extern "C" u8 fn_801D217C(void*);
extern "C" u8 fn_801D21F0(void*);
extern "C" void fn_801CD950(f32*, f32, f32);
extern "C" void fn_801BACE8(void*, s32);
extern const f32 lbl_80542280;
extern const f32 lbl_80542284;
extern const f32 lbl_80542298;
extern const f32 lbl_8054229C;
extern const f32 lbl_805422A0;
extern const f32 lbl_805422A4;
extern const f32 lbl_805422A8;
extern "C" void fn_8033FE04(char* p) {
    s32 st = *(s32*)(p + 0x248);
    if (st == 4) {
        return;
    }
    if (st > 4) {
        if (st >= 6) {
            return;
        }
        goto reset;
    }
    if (st < 2) {
        return;
    }
reset:
    if (*(u32*)(p + 0x1a0) == 0x4c545a52) {
        *(f32*)(p + 0x60) = lbl_80542280;
        *(f32*)(p + 0x64) = lbl_80542280;
        *(f32*)(p + 0x68) = lbl_80542284;
        *(f32*)(p + 0x6c) = lbl_80542284;
        *(f32*)(p + 0x70) = *(f32*)(p + 0x60);
        *(f32*)(p + 0x74) = *(f32*)(p + 0x64);
        *(f32*)(p + 0x78) = *(f32*)(p + 0x68);
        *(f32*)(p + 0x7c) = *(f32*)(p + 0x6c);
    }
    if (*(s32*)(p + 0x248) == 2 && *(s32*)(p + 0x24c) < 3) {
        (*(void (**)(void*))(*(char**)p + 0xa4))(p);
        return;
    }
    for (s32 i = 0; i < 4; i++) {
        f32 rect[4];
        rect[0] = *(f32*)(p + 0x60) + *(f32*)(p + 0xc);
        rect[1] = *(f32*)(p + 0x64) + *(f32*)(p + 0x10);
        rect[2] = *(f32*)(p + 0x68) + *(f32*)(p + 0xc);
        rect[3] = *(f32*)(p + 0x6c) + *(f32*)(p + 0x10);
        if (fn_80233E40(i) == 1) {
            fn_802399D8(i, rect, *(s32*)(p + 4), *(u32*)(p + 0x198));
            continue;
        }
        if (fn_8023B0F4(i, rect, *(s32*)(p + 4), lbl_80542288, 0) != 1) {
            continue;
        }
        if (!(fn_8022F478(i) && fn_8022CAF8(i) == 5)) {
            if (*(s32*)(p + 0x248) != 5) {
                fn_801F0E34(p, 0x50032, 0);
                fn_8013CC50(*(void**)(p + 4), p + 0xc, lbl_8054227C, 0x15b, 0, -2, 0, 0, 1);
                fn_8013CC50(*(void**)(p + 4), p + 0xc, lbl_8054227C, 0x15c, -1, 0, 0, 0, 1);
            }
            fn_801BACE8(p, 0);
        }
        s32 room = *(s32*)(p + 4);
        if (fn_8023DE58(i) != room) {
            continue;
        }
        for (s32 j = 0; j < 8; j++) {
            JGeometry::TVec3<f32> pt;
            fn_8022E088(i, j, (f32*)&pt);
            JGeometry::TVec3<f32> d = pt - *(JGeometry::TVec3<f32>*)(p + 0xc);
            d.z = lbl_80542268;
            f32 ang = JMath::atanTable_.atan2_(d.y, d.x);
            u16 a = (u16)(s32)(ang * lbl_8054228C);
            f32 len = JGeometry::TUtilf::sqrt(d.x * d.x + d.y * d.y);
            f32 vx = len * JMath::sincosTable_.mTable[a >> 5].second;
            f32 vy = len * JMath::sincosTable_.mTable[a >> 5].first;
            u8 in = 1;
            if (vx < *(f32*)(p + 0x60) || vy < *(f32*)(p + 0x64) || vx >= *(f32*)(p + 0x68) || vy >= *(f32*)(p + 0x6c)) {
                in = 0;
            }
            if (in) {
                fn_8022DF48(i);
                break;
            }
        }
    }
    if (*(s32*)(p + 0x248) != 5) {
        return;
    }
    if (*(u32*)(p + 0x1a0) != 0x4c545a52) {
        return;
    }
    *(f32*)(p + 0x60) = lbl_80542280;
    *(f32*)(p + 0x64) = lbl_80542280;
    *(f32*)(p + 0x68) = lbl_80542284;
    *(f32*)(p + 0x6c) = lbl_80542284;
    *(f32*)(p + 0x70) = *(f32*)(p + 0x60);
    *(f32*)(p + 0x74) = *(f32*)(p + 0x64);
    *(f32*)(p + 0x78) = *(f32*)(p + 0x68);
    *(f32*)(p + 0x7c) = *(f32*)(p + 0x6c);
    if (*(s32*)(p + 0x248) == 1) {
        if (*(u8*)(p + 0x2b1) == 1) {
            *(f32*)(p + 0x2b4) = *(f32*)(p + 0x2b4) + lbl_80542298;
            if (*(f32*)(p + 0x2b4) >= lbl_8054229C) {
                *(f32*)(p + 0x2b4) = lbl_8054229C;
                *(u8*)(p + 0x2b1) = 0;
            }
        } else {
            *(f32*)(p + 0x2b4) = *(f32*)(p + 0x2b4) - lbl_80542298;
            if (*(f32*)(p + 0x2b4) <= lbl_8054227C) {
                *(f32*)(p + 0x2b4) = lbl_8054227C;
                *(u8*)(p + 0x2b1) = 1;
            }
        }
    } else if (lbl_8054227C != *(f32*)(p + 0x2b4)) {
        *(f32*)(p + 0x2b4) = lbl_8054227C;
    }
    s32 s = *(s32*)(p + 0x248);
    if (s == 3) {
        if (*(s32*)(p + 0x24c) > 1 && fn_801D21F0(p + 0x270)) {
            fn_801BACE8(p, 3);
        }
    } else if (s > 3) {
        if (s == 5) {
            goto state5;
        }
    } else if (s == 1) {
        fn_801F0E34(p, 0x50081, 0);
        if (*(u32*)(p + 0x1a0) == 0x4c545a52) {
            *(f32*)(p + 0x60) = lbl_80542280;
            *(f32*)(p + 0x64) = lbl_80542280;
            *(f32*)(p + 0x68) = lbl_80542284;
            *(f32*)(p + 0x6c) = lbl_80542284;
            *(f32*)(p + 0x70) = *(f32*)(p + 0x60);
            *(f32*)(p + 0x74) = *(f32*)(p + 0x64);
            *(f32*)(p + 0x78) = *(f32*)(p + 0x68);
            *(f32*)(p + 0x7c) = *(f32*)(p + 0x6c);
        }
        (*(void (**)(void*))(*(char**)p + 0xa8))(p);
        if (lbl_805422A4 != *(f32*)(p + 0x54)) {
            fn_801CD950((f32*)(p + 0x54), lbl_805422A4, lbl_805422A8);
        }
        *(f32*)(p + 0x58) = *(f32*)(p + 0x54);
        *(f32*)(p + 0x5c) = *(f32*)(p + 0x54);
    } else if (s > 1) {
        if (*(s32*)(p + 0x24c) >= *(s32*)(p + 0x250) && fn_801D217C(p + 0x270)) {
            fn_801BACE8(p, 2);
            (*(void (**)(void*))(*(char**)p + 0xb0))(p);
        }
    } else if (s >= 0) {
        if (*(u32*)(p + 0x1a0) == 0x4c545a52) {
            *(f32*)(p + 0x60) = lbl_80542280;
            *(f32*)(p + 0x64) = lbl_80542280;
            *(f32*)(p + 0x68) = lbl_80542284;
            *(f32*)(p + 0x6c) = lbl_80542284;
            *(f32*)(p + 0x70) = *(f32*)(p + 0x60);
            *(f32*)(p + 0x74) = *(f32*)(p + 0x64);
            *(f32*)(p + 0x78) = *(f32*)(p + 0x68);
            *(f32*)(p + 0x7c) = *(f32*)(p + 0x6c);
        }
        (*(void (**)(void*))(*(char**)p + 0xa8))(p);
        if (*(s32*)(p + 0x24c) >= *(s32*)(p + 0x250) && fn_801D05F8(p, p + 0xc, lbl_805422A0) >= 0) {
            fn_801BACE8(p, 1);
        }
    }
    return;
state5:
    if (*(u32*)(p + 0x1a0) == 0x4c545a52) {
        *(f32*)(p + 0x60) = lbl_80542280;
        *(f32*)(p + 0x64) = lbl_80542280;
        *(f32*)(p + 0x68) = lbl_80542284;
        *(f32*)(p + 0x6c) = lbl_80542284;
        *(f32*)(p + 0x70) = *(f32*)(p + 0x60);
        *(f32*)(p + 0x74) = *(f32*)(p + 0x64);
        *(f32*)(p + 0x78) = *(f32*)(p + 0x68);
        *(f32*)(p + 0x7c) = *(f32*)(p + 0x6c);
    }
    if (*(s32*)(p + 0x24c) >= *(s32*)(p + 0x250) && fn_801D217C(p + 0x270)) {
        fn_801BACE8(p, 5);
    }
}

extern "C" s32 fn_80340650(void) { return 0; }
extern "C" s32 fn_80340658(void) { return 0; }
extern "C" s32 fn_80340660(void) { return 0; }

extern "C" void fn_80340668(void* this_) {
    f32 b;
    f32 a = lbl_80542268;
    b = lbl_805422AC;
    u8 hit = 0;
    u8* flags = (u8*)this_;
    for (s32 i = 0; i < 4; i++) {
        if (flags[0x2ac + i] != 0) {
            f32 v[3];
            v[0] = a;
            v[1] = a;
            v[2] = b;
            fn_802314D8(i, v);
            hit = 1;
        }
    }
    if (hit == 1) {
        fn_801F0E34(this_, 0x50082, 0);
        (*(void (**)(void*))(*(char**)this_ + 0xa4))(this_);
    }
}

extern "C" u8 fn_80340734(void* this_) {
    char* p = (char*)this_;
    u8 found = 0;
    if (*(s32*)(p + 0x90) & 1) {
        for (s32 i = 0; i < 4; i++) {
            if (fn_80233E40(i)) {
                f32 dx = *(f32*)(p + 0xc) - fn_8023E724(i)[0];
                f32 dy = *(f32*)(p + 0x10) - fn_8023E724(i)[1];
                if (dx * dx + dy * dy < lbl_805422B0) {
                    f32 angle = JMath::atanTable_.atan2_(dx, dy);
                    u16 ang = (u16)(s32)(angle * lbl_8054228C);
                    f32 v[3];
                    v[1] = JMath::sincosTable_.cosShort(ang + 0x3000);
                    v[0] = JMath::sincosTable_.sinShort(ang + 0x3000);
                    v[2] = lbl_80542268;
                    fn_8023DFF4(i, v);
                    found = 1;
                }
            }
        }
        if (found) {
            if (*(void**)(p + 0x2b8) == 0) {
                *(void**)(p + 0x2b8) = fn_8013CC50(*(void**)(p + 4), p + 0xc, lbl_805422B4, 0x553, -1, -2, 0, 0, 1);
            }
        } else {
            char* obj = *(char**)(p + 0x2b8);
            if (obj != 0) {
                *(u32*)(obj + 0xf4) |= 1;
                *(s32*)(obj + 0x24) = 1;
                *(void**)(p + 0x2b8) = 0;
            }
        }
    }
    return found;
}

extern "C" void fn_80340BC8(char* p) {
    p[0x2ac] = 0;
    p[0x2ad] = 0;
    p[0x2ae] = 0;
    p[0x2af] = 0;
    *(s16*)(p + 0x2b2) = 0;
    p[0x2b0] = 0;
    *(f32*)(p + 0x10) = *(f32*)(p + 0x28);
}

extern "C" void fn_80340BF0(char* p) {
    fn_801BB1AC(p);
    *(f32*)(p + 0xc) -= lbl_80542288;
    *(f32*)(p + 0x24) -= lbl_80542288;
    *(f32*)(p + 0x10) -= lbl_80542288;
    *(f32*)(p + 0x28) -= lbl_80542288;
    *(f32*)(p + 0x2b4) = lbl_8054227C;
    p[0x2b1] = 1;
}

extern "C" void* fn_80340C60(void* this_) {
    fn_801BB3B0(this_);
    *(void**)this_ = lbl_804AC3E0;
    *(s32*)((char*)this_ + 0x2b8) = 0;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
