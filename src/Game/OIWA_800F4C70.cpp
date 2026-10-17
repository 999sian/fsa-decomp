// OIWA_800F4C70: .text 0x800F4C70-0x800F6820 (actor OIWA)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"
#include "Game/ItemBase.h"
#include "JSystem/JGeometry/Box.h"

// ---- from Game/fn_800F659C_dtor.cpp

extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049C4C0[];

extern "C" void* fn_800F659C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049C4C0;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

extern "C" u32 fn_8022461C(void* p);
extern "C" u8 fn_802265DC(void* a, void* b, u32 c);

extern "C" u8 fn_800F51D8(void* this_, void* a, void* b) {
    s32 kind = (u16)fn_8022461C(a);
    if (kind == 3 || kind == 14 || kind == 2) {
        return 0;
    }
    return fn_802265DC(a, b, 0);
}

struct OiwaRandom {
    u32 seed;
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - 1.0f;
    }
};
struct OiwaGame { u8 pad[0xb4]; OiwaRandom rnd; };
extern OiwaGame* lbl_8053AAF8;

static inline void oiwaSetBox(char* this_, f32 lo, f32 hi) {
    *(f32*)(this_ + 0x60) = lo;
    *(f32*)(this_ + 0x64) = lo;
    *(f32*)(this_ + 0x68) = hi;
    *(f32*)(this_ + 0x6c) = hi;
    *(f32*)(this_ + 0x80) = lo;
    *(f32*)(this_ + 0x84) = lo;
    *(f32*)(this_ + 0x88) = hi;
    *(f32*)(this_ + 0x8c) = hi;
}

extern "C" void fn_800F6328(char* this_) {
    *(s32*)(this_ + 0x23c) = 0;
    *(u8*)(this_ + 0x231) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s8*)(this_ + 0x232) = -1;
    *(f32*)(this_ + 0x254) = 0.0f;
    *(f32*)(this_ + 0x258) = 0.0f;
    *(f32*)(this_ + 0x25c) = 0.0f;
    *(u8*)(this_ + 0x230) = *(u32*)(this_ + 0x90);
    *(s32*)(this_ + 0x250) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x244) = 0;
    switch (*(u8*)(this_ + 0x230)) {
    case 0:
    case 4:
        oiwaSetBox(this_, -16.0f, 16.0f);
        *(f32*)(this_ + 0x3c) = 0.0f;
        *(f32*)(this_ + 0x40) = 0.5f + lbl_8053AAF8->rnd.get_ufloat_1();
        *(f32*)(this_ + 0x44) = 1.0f;
        break;
    case 1:
        oiwaSetBox(this_, -10.0f, 10.0f);
        break;
    case 2:
        oiwaSetBox(this_, -6.0f, 6.0f);
        *(f32*)(this_ + 0x14) = 1.0f;
        break;
    case 3:
        oiwaSetBox(this_, -16.0f, 16.0f);
        *(f32*)(this_ + 0x3c) = 0.0f;
        *(f32*)(this_ + 0x40) = 0.0f;
        *(f32*)(this_ + 0x44) = 0.0f;
        break;
    case 5:
        oiwaSetBox(this_, -16.0f, 16.0f);
        *(s32*)(this_ + 0x240) = (s32)(5.0f * lbl_8053AAF8->rnd.get_ufloat_1());
        *(s32*)(this_ + 0x244) = 0;
        *(s32*)(this_ + 0x248) = 0x300 - (s32)(1536.0f * lbl_8053AAF8->rnd.get_ufloat_1());
        *(f32*)(this_ + 0x3c) = 0.0f;
        *(f32*)(this_ + 0x40) = 0.0f;
        *(f32*)(this_ + 0x44) = 0.0f;
        break;
    }
}

extern "C" void fn_800F5E08(char* this_);
extern "C" void fn_800F555C(char* this_);
extern "C" u8 fn_801F2B7C(void* this_, u32 a, s32 b, u32 c);
extern "C" void fn_801F0E34(void* actor, u32 msg, s32 arg);
extern "C" void* fn_8013CC50(u32 id, void* pos, u32 kind, s32 a, u32 b, u32 c, u32 d, u32 e, f32 scale);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D79E8(void* mgr, u32 room, s32 b, f32 x, f32 y);

#define OIWA_POS(p) (*(JGeometry::TVec3<f32>*)((p) + 0xc))
static inline bool oiwaIsZero(const JGeometry::TVec3<f32>& v) {
    f32 z = 0.0f;
    return v.x == z && v.y == z && v.z == z;
}
#define OIWA_VEL(p) (*(JGeometry::TVec3<f32>*)((p) + 0x3c))

extern "C" void fn_800F5248(char* this_) {
    switch (*(u8*)(this_ + 0x230)) {
    case 0:
    case 4:
        fn_800F5E08(this_);
        break;
    case 1:
        f32 z = 0.0f;
        if (*(f32*)(this_ + 0x3c) != z || *(f32*)(this_ + 0x40) != z || *(f32*)(this_ + 0x44) != z) {
            fn_801F2B7C(this_, 2, -1, 6);
            *(f32*)(this_ + 0x44) = *(f32*)(this_ + 0x44) - 0.2f;
        } else {
            *(s32*)(this_ + 0x23c) = 0;
        }
        OIWA_POS(this_) += OIWA_VEL(this_);
        if (*(f32*)(this_ + 0x14) <= 0.0f) {
            fn_801F0E34(this_, 0x30075, 0);
            fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, 0x76, 0, 0, 0, 0, 1, 0.8f);
            fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, 0x77, 0, 0, 0, 0, 1, 0.8f);
            fn_802D79E8(fn_802D6A9C(), *(u32*)(this_ + 4), 0, 4.0f, 0.0f);
            *(u8*)(this_ + 0x11c) = 0;
        }
        break;
    case 2:
        fn_801F2B7C(this_, 1, -1, 1);
        *(f32*)(this_ + 0x44) = *(f32*)(this_ + 0x44) - 0.2f;
        OIWA_POS(this_) += OIWA_VEL(this_);
        if (*(f32*)(this_ + 0x14) <= 0.0f) {
            fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, 0x76, 0, 0, 0, 0, 1, 0.2f);
            fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, 0x77, 0, 0, 0, 0, 1, 0.2f);
            *(u8*)(this_ + 0x11c) = 0;
        }
        break;
    case 3:
        fn_800F555C(this_);
        break;
    case 5:
        *(f32*)(this_ + 0x44) = *(f32*)(this_ + 0x44) - 0.03f;
        *(s32*)(this_ + 0x244) = *(s32*)(this_ + 0x244) + *(s32*)(this_ + 0x248);
        OIWA_POS(this_) += OIWA_VEL(this_);
        if (*(f32*)(this_ + 0x14) <= 0.0f) {
            f32 scale = 1.0f;
            if (*(s32*)(this_ + 0x240) > 1) {
                scale = 0.5f;
            }
            fn_801F0E34(this_, 0x3005a, 0);
            fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, 0x497, 0, 0, 0, 0, 1, scale);
            fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, 0x498, 0, 0, 0, 0, 1, scale);
            *(u8*)(this_ + 0x11c) = 0;
        }
        break;
    }
}

class OiwaActor {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10(s32 a, s32 b);
    virtual u8 v11();
};
extern "C" s32 fn_8023DE58(s32 player);
extern "C" void fn_8022E088(s32 player, s32 idx, JGeometry::TVec3<f32>* out);
extern "C" void fn_8022DF48(s32 player);
extern "C" s32 fn_801F2718(void* actor, u32 type);
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* mgr, s32 id);
extern "C" s32 fn_801F778C(void* mgr, u32 type, void* pos, s32 a);
extern const f32 lbl_80463678[4][2];

extern "C" void fn_800F5E08(char* this_) {
    if (*(s32*)(this_ + 0x240) != 0) {
        *(s32*)(this_ + 0x244) = *(s32*)(this_ + 0x244) + 1;
        if (*(s32*)(this_ + 0x240) != 2 && *(s32*)(this_ + 0x244) >= 120) {
            *(f32*)(this_ + 0xc) = 0.8f * JMASSin((*(s32*)(this_ + 0x244) & 3) << 14) + *(f32*)(this_ + 0xc);
        }
        if (*(s32*)(this_ + 0x244) >= 180) {
            ((OiwaActor*)this_)->v10(0xff, 0);
            *(s32*)(this_ + 0x240) = 2;
            *(s32*)(this_ + 0x248) = *(s32*)(this_ + 0x248) + 1;
            if (*(s32*)(this_ + 0x248) == 60) {
                *(u8*)(this_ + 0x11c) = 0;
            }
        } else {
            for (s32 i = 0; i < 4; i++) {
                s32 room = *(s32*)(this_ + 4);
                if (fn_8023DE58(i) == room) {
                    f32 x0 = *(f32*)(this_ + 0x60) + *(f32*)(this_ + 0xc);
                    f32 y0 = *(f32*)(this_ + 0x64) + *(f32*)(this_ + 0x10);
                    f32 x1 = *(f32*)(this_ + 0x68) + *(f32*)(this_ + 0xc);
                    f32 y1 = *(f32*)(this_ + 0x6c) + *(f32*)(this_ + 0x10);
                    for (s32 j = 0; j < 8; j++) {
                        JGeometry::TVec3<f32> pt;
                        fn_8022E088(i, j, &pt);
                        u8 in = 0;
                        if (pt.x >= x0 && pt.y >= y0 && pt.x < x1 && pt.y < y1) {
                            in = 1;
                        }
                        if (in) {
                            fn_8022DF48(i);
                            break;
                        }
                    }
                }
            }
        }
        return;
    }
    *(u8*)(this_ + 0x231) = *(u8*)(this_ + 0x231) + 1;
    if (*(u8*)(this_ + 0x231) == 10) {
        *(s32*)(this_ + 0x23c) = *(s32*)(this_ + 0x23c) + 1;
        *(u8*)(this_ + 0x231) = 0;
    }
    *(s32*)(this_ + 0x23c) = *(s32*)(this_ + 0x23c) & 3;
    fn_801F2B7C(this_, 2, -1, 6);
    s32 id = fn_801F2718(this_, 'OIWA');
    if (id != -1) {
        char* other = (char*)fn_801F666C(fn_801F856C(), id);
        JGeometry::TVec3<f32> d;
        d.sub(OIWA_POS(this_), OIWA_POS(other));
        if (d.x > 0.0f) {
            *(f32*)(this_ + 0x3c) = 0.5f;
        } else {
            *(f32*)(this_ + 0x3c) = -0.5f;
        }
    }
    *(f32*)(this_ + 0x44) = *(f32*)(this_ + 0x44) - 0.04f;
    OIWA_POS(this_) += OIWA_VEL(this_);
    if (*(f32*)(this_ + 0x14) <= 0.0f) {
        if (lbl_8053AAF8->rnd.get_ufloat_1() < 0.5) {
            *(f32*)(this_ + 0x3c) = 0.5f;
        } else {
            *(f32*)(this_ + 0x3c) = -0.5f;
        }
        *(f32*)(this_ + 0x14) = 0.0f;
        *(f32*)(this_ + 0x44) = 1.0f;
        fn_801F0E34(this_, 0x30028, 0);
        char* eff = (char*)fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, 0x3cf, 1, 0, 0, 0, 1, 1.2f);
        if (eff != 0) {
            *(f32*)(eff + 0x3c) = 0.0f;
        }
        if (*(u8*)(this_ + 0x230) == 4) {
            const f32 (*off)[2] = lbl_80463678;
            for (s32 k = 0; k < 4; k++, off++) {
                JGeometry::TVec3<f32> p(OIWA_POS(this_));
                p.x = p.x + (*off)[0];
                p.y = p.y + (*off)[1];
                s32 t = (u16)((u32(*)(void*, u32))fn_8022461C)(&p, *(u32*)(this_ + 4));
                if ((t == 3 || t == 0xe || t == 2) && !((OiwaActor*)this_)->v11()) {
                    fn_802D79E8(fn_802D6A9C(), *(u32*)(this_ + 4), 0, 4.0f, 0.0f);
                    fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, 0x76, 0, 0, 0, 0, 1, 0.8f);
                    *(s32*)(this_ + 0x240) = 1;
                    ((OiwaActor*)this_)->v10(0xff, 1);
                    fn_801F0E34(this_, 0x4002c, 0);
                    s32 bid = fn_801F778C(fn_801F856C(), 'BTIN', this_ + 0xc, 0);
                    char* b = (char*)fn_801F666C(fn_801F856C(), bid);
                    OIWA_POS(this_) = OIWA_POS(b);
                    *(f32*)(this_ + 0x14) = 0.0f;
                    *(f32*)(this_ + 0x10) = *(f32*)(this_ + 0x10) + 8.0f;
                }
            }
        }
    }
    s32 room = *(s32*)(this_ + 4);
    u8* mgr = (u8*)fn_802D6A9C();
    f32* r;
    if (room < 8) {
        r = (f32*)(mgr + 0xcc);
    } else {
        r = (f32*)(mgr + 0xdc);
    }
    if (50.0f + r[3] < *(f32*)(this_ + 0x10)) {
        *(u8*)(this_ + 0x11c) = 0;
    }
}

extern "C" double sin(double);
extern "C" double cos(double);
extern "C" void fn_801F06F0(void* actor, const char* res, u32 id, DrawRec* rec, s32 p5, f32 a, f32 b);
extern "C" void fn_801F02BC(void* actor, const char* res, u32 id, DrawRec* rec, s32 p5, u32 p6, u32 p7, f32 a, f32 b);
extern "C" void fn_801EFD34(void* actor, void* tex, DrawRec* rec, s32 p, f32 a, f32 b, f32 c);
extern "C" void* fn_804032E8(u32 type, const char* name);
extern const char lbl_804636E8[];
extern const char lbl_804636FC[];
extern const char* lbl_8049C458[];

static inline void oiwaScaleMtx(f32 (*m)[4], f32 s) {
    m[0][0] = s;
    m[0][1] = 0.0f;
    m[0][2] = 0.0f;
    m[1][0] = 0.0f;
    m[1][1] = s;
    m[1][2] = 0.0f;
    m[2][0] = 0.0f;
    m[2][1] = 0.0f;
    m[2][2] = s;
}

extern "C" void fn_800F4C70(char* this_) {
    DrawRec rec;
    f32 mtx[3][4];
    s32 mode;
    rec.b1c = 1;
    rec.b1f = 0;
    mtx[0][3] = 0.0f;
    mtx[1][3] = 0.0f;
    mtx[2][3] = 0.0f;
    switch (*(u8*)(this_ + 0x230)) {
    case 0:
    case 4:
        oiwaScaleMtx(mtx, 1.0f);
        mode = 3;
        if (*(s32*)(this_ + 0x240) == 1) {
            rec.b1c = 0;
            *(s8*)&rec.b1d = -1;
            mode = -1;
            ((u8*)&rec.w10)[0] = 200;
            ((u8*)&rec.w10)[1] = 200;
            ((u8*)&rec.w10)[2] = 200;
        } else if (*(s32*)(this_ + 0x240) == 2) {
            rec.b1c = 0;
            *(s8*)&rec.b1d = -1;
            mode = -1;
            oiwaScaleMtx(mtx, (f32)(60 - *(s32*)(this_ + 0x248)) / 60.0f);
            ((u8*)&rec.w10)[0] = 200 - *(s32*)(this_ + 0x248) * 2;
            ((u8*)&rec.w10)[1] = 200 - *(s32*)(this_ + 0x248) * 2;
            ((u8*)&rec.w10)[2] = 200 - *(s32*)(this_ + 0x248) * 2;
        }
        break;
    case 1:
        oiwaScaleMtx(mtx, 0.8f);
        {
            f32 z = 0.0f;
            if (*(f32*)(this_ + 0x3c) != z || *(f32*)(this_ + 0x40) != z || *(f32*)(this_ + 0x44) != z) {
                mode = 3;
            } else {
                mode = -1;
            }
        }
        break;
    case 2:
        oiwaScaleMtx(mtx, 0.2f);
        mode = 7;
        rec.w30 = 0x11;
        break;
    case 3:
        oiwaScaleMtx(mtx, 1.0f);
        mode = 3;
        if (*(s32*)(this_ + 0x240) == 2) {
            *(s8*)&rec.b1d = -1;
            *(s8*)&rec.b1c = -1;
        }
        break;
    case 5: {
        mtx[0][3] = 0.0f;
        mtx[1][3] = 0.0f;
        mtx[2][3] = 0.0f;
        f32 ang = (f32)*(s32*)(this_ + 0x244) / -10430.228f;
        f32 rx = 0.0f;
        f32 sa = sin(rx);
        f32 sb = sin(ang);
        f32 sc = sin(rx);
        f32 ca = cos(rx);
        f32 cb = cos(ang);
        f32 cc = cos(rx);
        f32 s = 1.0f;
        mtx[0][0] = s * (cb * cc);
        mtx[1][0] = s * (cb * sc);
        mtx[2][0] = s * -sb;
        f32 sasb = sa * sb;
        f32 cacc = ca * cc;
        f32 casc = ca * sc;
        mtx[0][1] = s * (sasb * cc - casc);
        mtx[1][1] = s * (sasb * sc + cacc);
        mtx[2][1] = s * (sa * cb);
        mtx[0][2] = s * (cacc * sb + sa * sc);
        mtx[1][2] = s * (casc * sb - sa * cc);
        mtx[2][2] = s * (ca * cb);
        rec.w18 = mtx;
        fn_801EFD34(this_, fn_804032E8('TIMG', lbl_8049C458[*(s32*)(this_ + 0x240)]), &rec, -1, 0.0f, 0.0f, 0.0f);
        return;
    }
    }
    rec.w18 = mtx;
    JGeometry::TVec3<f32> save(OIWA_POS(this_));
    OIWA_POS(this_) += *(JGeometry::TVec3<f32>*)(this_ + 0x254);
    if (*(s32*)(this_ + 4) <= 8) {
        fn_801F06F0(this_, lbl_804636E8, *(s32*)(this_ + 0x23c) + 0xb1, &rec, mode, 1.0f, 1.0f);
    } else {
        fn_801F02BC(this_, lbl_804636FC, *(s32*)(this_ + 0x23c), &rec, mode, 0, 0, 1.0f, 1.0f);
    }
    *(Vec*)(this_ + 0xc) = save;
}

struct OiwaV3 { f32 x, y, z; };
struct OiwaRect { f32 x0, y0, x1, y1; };
extern "C" void fn_80239914(OiwaRect* box, u32 room, u32 id);
extern "C" s32 fn_80239108(u32 id);
extern "C" s32 fn_80238BC4(u32 id);
extern "C" void fn_80238E08(u32 id);
extern "C" s32 fn_80238CB4(s32 player);
extern "C" void fn_80230FD0(s32 player, s32 id);
extern "C" void fn_80238D50(u32 id);
extern "C" void fn_800F82CC(void* vel, OiwaV3 target, f32 rate);
extern "C" void fn_801F0D20(void* this_, s32 id);
extern "C" u8 fn_801F2618(void* this_, s32 a, s32 b);
extern "C" s32 Actor_CreateByID(void* mgr, u32 fourCC, u32 owner, void* pos, u32 param, s32 p6, s32 p7);

static inline void oiwaBox(OiwaRect* b, char* this_) {
    f32 r = 16.0f;
    JGeometry::TVec2<f32>& p = *(JGeometry::TVec2<f32>*)(this_ + 0xc);
    ((JGeometry::TBox2<f32>*)b)->set(p.x - r, p.y - r, r + p.x, r + p.y);
}

extern "C" void fn_800F555C(char* this_) {
    OiwaRect box;
    s32 dir;
    s32 present = 0;
    oiwaBox(&box, this_);
    for (s32 i = 0; i < 4; i++) {
        if (*(s32*)(this_ + 4) == fn_8023DE58(i)) {
            present = 1;
        }
    }
    if (*(s32*)(this_ + 0x240) == 0) {
        fn_80239914(&box, *(u32*)(this_ + 4), *(u32*)(this_ + 0x198));
        if (fn_80239108(*(u32*)(this_ + 0x198)) >= 2) {
            dir = fn_80238BC4(*(u32*)(this_ + 0x198));
            if (dir >= 0 && dir < 4) {
                *(s32*)(this_ + 0x244) = *(s32*)(this_ + 0x244) + 1;
                switch (dir) {
                case 0:
                    *(f32*)(this_ + 0x254) = 3.0f;
                    break;
                case 1:
                    *(f32*)(this_ + 0x254) = -3.0f;
                    break;
                case 2:
                    *(f32*)(this_ + 0x258) = 3.0f;
                    break;
                case 3:
                    *(f32*)(this_ + 0x258) = -3.0f;
                    break;
                }
            }
        } else {
            if (*(s32*)(this_ + 0x244) < 60) {
                *(s32*)(this_ + 0x244) = 0;
            }
            *(f32*)(this_ + 0x254) = 0.0f;
            *(f32*)(this_ + 0x258) = 0.0f;
            *(f32*)(this_ + 0x25c) = 0.0f;
        }
        if (*(s32*)(this_ + 0x244) >= 60) {
            *(s32*)(this_ + 0x240) = 1;
            *(f32*)(this_ + 0x254) = 0.0f;
            *(f32*)(this_ + 0x258) = 0.0f;
            *(f32*)(this_ + 0x25c) = 0.0f;
            switch (dir) {
            case 0:
                *(s8*)(this_ + 0x232) = 0;
                *(u8*)(this_ + 0x234) = 0;
                break;
            case 1:
                *(s8*)(this_ + 0x232) = 1;
                *(u8*)(this_ + 0x234) = 1;
                break;
            case 2:
                *(s8*)(this_ + 0x232) = 2;
                *(u8*)(this_ + 0x234) = 2;
                break;
            case 3:
                *(s8*)(this_ + 0x232) = 3;
                *(u8*)(this_ + 0x234) = 3;
                break;
            }
            fn_80238E08(*(u32*)(this_ + 0x198));
            for (s32 i = 0; i < 4; i++) {
                s32 id = *(s32*)(this_ + 0x198);
                if (fn_80238CB4(i) != id) continue; {
                    fn_80230FD0(i, 0x10012);
                }
            }
            fn_80238D50(*(u32*)(this_ + 0x198));
        }
    } else if (*(s32*)(this_ + 0x240) == 1) {
        *(u8*)(this_ + 0x231) = *(u8*)(this_ + 0x231) + 1;
        if (*(u8*)(this_ + 0x231) == 15) {
            *(s32*)(this_ + 0x23c) = *(s32*)(this_ + 0x23c) + 1;
            *(u8*)(this_ + 0x231) = 0;
        }
        *(s32*)(this_ + 0x23c) = *(s32*)(this_ + 0x23c) & 3;
        if (__fabsf(*(f32*)(this_ + 0x3c)) < 1.5f && __fabsf(*(f32*)(this_ + 0x40)) < 1.5f &&
            __fabsf(*(f32*)(this_ + 0x44)) == 0.0f) {
            fn_80239914(&box, *(u32*)(this_ + 4), *(u32*)(this_ + 0x198));
        } else {
            f32 z = 0.0f;
            if (z != *(f32*)(this_ + 0x3c) || z != *(f32*)(this_ + 0x40)) {
                fn_801F0E34(this_, 0x30060, 0);
            }
            fn_801F2B7C(this_, 2, -1, 6);
        }
        s32 t = (u16)((u32(*)(void*, u32))fn_8022461C)(this_ + 0xc, *(u32*)(this_ + 4));
        if (t == 3 || t == 0xe || t == 2) {
            OiwaV3 zero;
            zero.x = 0.0f;
            zero.y = 0.0f;
            zero.z = 0.0f;
            fn_800F82CC(this_ + 0x3c, zero, 0.22f);
            f32 z = 0.0f;
            if (z == *(f32*)(this_ + 0x3c) && z == *(f32*)(this_ + 0x40)) {
                fn_802D79E8(fn_802D6A9C(), *(u32*)(this_ + 4), 0, 4.0f, 0.0f);
                fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, 0x3cf, 0, 0, 0, 0, 1, 1.2f);
                fn_801F0E34(this_, 0x4002c, 0);
                fn_801F0D20(this_, 3);
                *(s32*)(this_ + 0x240) = 2;
                *(s8*)(this_ + 0x232) = -1;
                for (s32 k = 0; k < 8; k++) {
                    JGeometry::TVec3<f32> pos;
                    pos.x = *(f32*)(this_ + 0xc);
                    pos.y = *(f32*)(this_ + 0x10);
                    pos.z = *(f32*)(this_ + 0x14);
                    pos.x = pos.x + (f32)(18 - (s32)(36.0f * lbl_8053AAF8->rnd.get_ufloat_1()));
                    pos.y = pos.y + (f32)(18 - (s32)(36.0f * lbl_8053AAF8->rnd.get_ufloat_1()));
                    Actor_CreateByID(fn_801F856C(), 'KMRI', *(u32*)(this_ + 4), &pos, 3, -1, -1);
                }
            }
        }
        if (fn_801F2618(this_, 0, 0)) {
            *(f32*)(this_ + 0x3c) = 0.0f;
            *(f32*)(this_ + 0x40) = 0.0f;
            *(f32*)(this_ + 0x44) = 3.0f;
            *(s8*)(this_ + 0x233) = *(s8*)(this_ + 0x232);
            *(s8*)(this_ + 0x232) = -1;
            if (present == 1) {
                fn_802D79E8(fn_802D6A9C(), *(u32*)(this_ + 4), 0, 2.0f, 0.0f);
                fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, 0x3cf, 0, 0, 0, 0, 1, 1.2f);
                fn_801F0E34(this_, 0x4002c, 0);
            }
        }
        if (*(s8*)(this_ + 0x232) == -1 && 0.0f == *(f32*)(this_ + 0x44)) {
            if ((s8)*(u8*)(this_ + 0x234) == 1) {
                switch (*(s8*)(this_ + 0x233)) {
                case 0:
                    *(s8*)(this_ + 0x232) = 3;
                    break;
                case 1:
                    *(s8*)(this_ + 0x232) = 2;
                    break;
                case 2:
                    *(s8*)(this_ + 0x232) = 0;
                    break;
                case 3:
                    *(s8*)(this_ + 0x232) = 1;
                    break;
                }
            } else {
                switch (*(s8*)(this_ + 0x233)) {
                case 0:
                    *(s8*)(this_ + 0x232) = 2;
                    break;
                case 1:
                    *(s8*)(this_ + 0x232) = 3;
                    break;
                case 2:
                    *(s8*)(this_ + 0x232) = 1;
                    break;
                case 3:
                    *(s8*)(this_ + 0x232) = 0;
                    break;
                }
            }
        }
    } else {
        for (s32 i = 0; i < 4; i++) {
            s32 room = *(s32*)(this_ + 4);
            if (fn_8023DE58(i) == room) {
                f32 x0 = *(f32*)(this_ + 0x60) + *(f32*)(this_ + 0xc);
                f32 y0 = *(f32*)(this_ + 0x64) + *(f32*)(this_ + 0x10);
                f32 x1 = *(f32*)(this_ + 0x68) + *(f32*)(this_ + 0xc);
                f32 y1 = *(f32*)(this_ + 0x6c) + *(f32*)(this_ + 0x10);
                for (s32 j = 0; j < 8; j++) {
                    JGeometry::TVec3<f32> pt;
                    fn_8022E088(i, j, &pt);
                    u8 in = 0;
                    if (pt.x >= x0 && pt.y >= y0 && pt.x < x1 && pt.y < y1) {
                        in = 1;
                    }
                    if (in) {
                        fn_8022DF48(i);
                        break;
                    }
                }
            }
        }
        return;
    }
    switch (*(s8*)(this_ + 0x232)) {
    case 0:
        *(f32*)(this_ + 0x3c) = *(f32*)(this_ + 0x3c) + 0.1f;
        if (*(f32*)(this_ + 0x3c) >= 2.0f) {
            *(f32*)(this_ + 0x3c) = 2.0f;
        }
        break;
    case 1:
        *(f32*)(this_ + 0x3c) = *(f32*)(this_ + 0x3c) - 0.1f;
        if (*(f32*)(this_ + 0x3c) <= -2.0f) {
            *(f32*)(this_ + 0x3c) = -2.0f;
        }
        break;
    case 2:
        *(f32*)(this_ + 0x40) = *(f32*)(this_ + 0x40) + 0.1f;
        if (*(f32*)(this_ + 0x40) >= 2.0f) {
            *(f32*)(this_ + 0x40) = 2.0f;
        }
        break;
    case 3:
        *(f32*)(this_ + 0x40) = *(f32*)(this_ + 0x40) - 0.1f;
        if (*(f32*)(this_ + 0x40) <= -2.0f) {
            *(f32*)(this_ + 0x40) = -2.0f;
        }
        break;
    }
    *(f32*)(this_ + 0x44) = *(f32*)(this_ + 0x44) - 0.3f;
    OIWA_POS(this_) += OIWA_VEL(this_);
    if (*(f32*)(this_ + 0x14) <= 0.0f) {
        *(f32*)(this_ + 0x14) = 0.0f;
        *(f32*)(this_ + 0x44) = 0.0f;
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
