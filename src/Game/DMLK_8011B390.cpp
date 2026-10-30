#include "types.h"
#include "Game/SinitPoolChain.h"
#define Vec SDKVec
#include "JSystem/JGeometry/Vec.h"
#undef Vec
#include "Game/Actor.h"
#include "JSystem/JGeometry/Box.h"

extern "C" void fn_8011B878(u8* this_, s32 id);
extern "C" void* fn_8011921C(void);
extern "C" s32 lbl_80464AF8[];

extern "C" char lbl_8049DB90[];
extern "C" const f32 lbl_8053C7D8;
extern "C" void __dt__13Base_8010E074Fv(void*, s32);
extern "C" void fn_8010E074(u8*);

extern "C" u8* lbl_8053AB10;
extern "C" void fn_801CD950(f32* value, f32 target, f32 step);
extern "C" f32 lbl_8053C7DC;
extern "C" f32 lbl_8053C7E0;
extern "C" f32 lbl_8053C7E4;
extern "C" const f32 lbl_8053C7E8;
extern "C" f32 lbl_8053C7EC;
extern "C" const f32 lbl_8053C7F0;
extern "C" f32 lbl_8053C7F4;
extern "C" f32 lbl_8053C7F8;
extern "C" f32 lbl_8053C7FC;
static inline s32 dmlkElapsed(const s32 current) { return current - lbl_80464AF8[7]; }
static inline s32 dmlkElapsed(void* timeline) {
    return *(s32*)((u8*)timeline + 8) - lbl_80464AF8[7];
}

static inline void dmlkRequestBounds(u8* p) {
    u8* view = *(u8**)(lbl_8053AB10 + 0x24);
    if (view[0x7f5] == 0) {
        view[0x7f4] = 1;
        *(s32*)(view + 0x7f8) = 5;
        *(f32*)(view + 0x808) = *(f32*)(p + 0x250);
        *(f32*)(view + 0x80c) = *(f32*)(p + 0x254);
        *(f32*)(view + 0x810) = *(f32*)(p + 0x258);
        *(f32*)(view + 0x814) = *(f32*)(p + 0x25c);
        view[0x7f6] = 0;
    }
}
static inline void dmlkStoreBounds(u8* p, f32 x0, f32 x1, f32 y0, f32 y1) {
    *(f32*)(p + 0x250) = x0;
    *(f32*)(p + 0x254) = y0;
    *(f32*)(p + 0x258) = x1;
    *(f32*)(p + 0x25c) = y1;
}
static inline void dmlkSetBounds(u8* p, const f32* pos) {
    dmlkStoreBounds(p, pos[0] - 64.0f, 64.0f + pos[0],
                   pos[1] - 32.0f, 32.0f + pos[1]);
}

struct DMLKResMgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void* getRes(s32 type, char* name);
};

#if defined(VERSION_G4SP01)
extern "C" s32 fn_8011BDAC(u8* self) {
    switch (*(s32*)(self + 0x238)) {
    case 12:
    case 13:
    case 20:
    case 21:
    case 28:
    case 34:
        return 1;
    default:
        return 0;
    }
}
#else
extern "C" s32 fn_8011BDAC(u8* self) {
    switch (*(s32*)(self + 0x238)) {
    case 12:
    case 13:
    case 20:
    case 21:
    case 28:
    case 34:
        return 1;
    default:
        return 0;
    }
}
#endif

extern "C" s32 fn_8011BDE4(u8* this_) {
#if defined(VERSION_G4SP01)
    return *(s32*)(this_ + 0x23c);
#else
    return *(s32*)(this_ + 0x238);
#endif
}

extern "C" void fn_8011BDEC(u8* this_) {
    s32 v = *(s32*)((u8*)fn_8011921C() + 8);
    switch (*(s32*)(this_ + 0x234)) {
    case 2:
        break;
    case 0:
        if (v == lbl_80464AF8[1]) {
            fn_8011B878(this_, 1);
        } else if (v == lbl_80464AF8[2]) {
            fn_8011B878(this_, 2);
        } else if (v == lbl_80464AF8[3]) {
            fn_8011B878(this_, 3);
        } else if (v == lbl_80464AF8[4]) {
            fn_8011B878(this_, 4);
        } else if (v == lbl_80464AF8[6]) {
            fn_8011B878(this_, 6);
        } else if (v == lbl_80464AF8[7]) {
            fn_8011B878(this_, 7);
        } else if (v == lbl_80464AF8[8]) {
            fn_8011B878(this_, 8);
        } else if (v == lbl_80464AF8[9]) {
            fn_8011B878(this_, 9);
        } else if (v == lbl_80464AF8[10]) {
            fn_8011B878(this_, 10);
        } else if (v == lbl_80464AF8[11]) {
            fn_8011B878(this_, 11);
        } else if (v == lbl_80464AF8[12]) {
            fn_8011B878(this_, 12);
        }
        break;
    case 1:
        if (*(s32*)((u8*)fn_8011921C() + 4) == 0x11) {
            if (v == lbl_80464AF8[14]) {
                fn_8011B878(this_, 14);
            } else if (v == lbl_80464AF8[15]) {
                fn_8011B878(this_, 15);
            } else if (v == lbl_80464AF8[16]) {
                fn_8011B878(this_, 16);
            } else if (v == lbl_80464AF8[17]) {
                fn_8011B878(this_, 17);
            } else if (v == lbl_80464AF8[18]) {
                fn_8011B878(this_, 18);
            } else if (v == lbl_80464AF8[19]) {
                fn_8011B878(this_, 19);
            } else if (v == lbl_80464AF8[20]) {
                fn_8011B878(this_, 20);
            }
        } else if (*(s32*)((u8*)fn_8011921C() + 4) == 2) {
            if (v == lbl_80464AF8[27]) {
                fn_8011B878(this_, 27);
            } else if (v == lbl_80464AF8[28]) {
                fn_8011B878(this_, 28);
            } else if (v == lbl_80464AF8[29]) {
                fn_8011B878(this_, 29);
            } else if (v == lbl_80464AF8[31]) {
                fn_8011B878(this_, 31);
            } else if (v == lbl_80464AF8[32]) {
                fn_8011B878(this_, 32);
            } else if (v == lbl_80464AF8[33]) {
                fn_8011B878(this_, 33);
            }
        }
        break;
    default:
        break;
    }
}

extern "C" void fn_8010DF58(u8* this_);
extern "C" void fn_801EF830(s32 a, u8* b, u8* c, s32 d, char* e, u8* f, s32 g);
extern "C" void fn_802F86CC(void* a, u8* b, void* c, s32 d, f32 e, f32 f, void* g);
extern "C" void fn_803075AC(void* a, s32 b, u8* c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i, s32 j);
extern "C" char lbl_80464B84[];
extern "C" u8* lbl_8053AAF8;
extern "C" u8* lbl_8053AB10;
extern "C" f32 lbl_8053C7F8;
extern "C" const f32 lbl_8053C800;
extern "C" const f32 lbl_8053C804;
extern "C" const f32 lbl_8053C808;
extern "C" const f32 lbl_8053C824;
extern "C" const f32 lbl_8053C828;
extern "C" const f32 lbl_8053C82C;
extern "C" const f32 lbl_8053C830;
extern "C" const f32 lbl_8053C834;
extern "C" const f32 lbl_8053C838;
extern "C" const f32 lbl_8053C83C;
extern "C" const f32 lbl_8053C840;
extern "C" void fn_8010DF78(u8* this_);
extern "C" void fn_8030C210(u8* view, u8* pos);
extern "C" void fn_8011B3F0(u8* this_);
extern "C" void fn_802303FC(s32 idx, f32* v, s32 flag);
extern "C" Vec* fn_8023E724(s32 i);
extern "C" void fn_801186B0(void* r, s32 v);
extern "C" void fn_801F0E34(u8* this_, s32 id, s32 flag);
extern "C" u8 fn_801F2B7C(u8* this_, s32 a, s32 b, s32 c);
static inline void dmlkSetAll(f32* v) {
    for (s32 i = 0; i < 4; i++) {
        fn_802303FC(i, v, 0xff);
    }
}
static inline s32 dmlkTime(s32 idx) {
    s32* tbl = lbl_80464AF8;
    return *(s32*)((u8*)fn_8011921C() + 8) - tbl[idx];
}
static inline bool dmlkSink(u8* p, int t, f32 vz, f32 vy, f32 vx) {
    *(f32*)(p + 0x44) = vz - lbl_8053C804 * t;
    *(f32*)(p + 0x40) = vy;
    *(f32*)(p + 0x3c) = vx;
    if (t > 1 && *(f32*)(p + 0x14) <= lbl_8053C7D8) {
        *(f32*)(p + 0x44) = lbl_8053C7D8;
        *(f32*)(p + 0x40) = lbl_8053C7D8;
        *(f32*)(p + 0x3c) = lbl_8053C7D8;
        *(f32*)(p + 0x14) = lbl_8053C7D8;
        return true;
    }
    return false;
}
extern "C" void fn_8011C118(u8* this_) {
    u8 buf[0x3c];
    s32 i;

    fn_8010DF58(this_);
    *(s32*)(buf + 0x10) = -1;
    *(s32*)(buf + 0x14) = -1;
    for (i = 0; (u8)i < 0x10; i += 8) {
        u8* b = buf;
        b[(u8)(i + 0)] = i + 0;
        b[(u8)(i + 1)] = i + 1;
        b[(u8)(i + 2)] = i + 2;
        b[(u8)(i + 3)] = i + 3;
        b[(u8)(i + 4)] = i + 4;
        b[(u8)(i + 5)] = i + 5;
        b[(u8)(i + 6)] = i + 6;
        b[(u8)(i + 7)] = i + 7;
    }
    buf[0x2e] = 0;
    *(s32*)(buf + 0x14) = 0;
    *(s32*)(buf + 0x10) = -1;
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
    *(s32*)(buf + 0x34) = 0;
    *(s32*)(buf + 0x30) = -1;
    *(s32*)(buf + 0x38) = 2;
    buf[0x2e] = 0x40;

    u8* p280 = *(u8**)(this_ + 0x280);
    if (*(s32*)((unsigned)this_ + 0x138) == 0) {
        fn_801EF830(*(s32*)(this_ + 4), this_ + 0xc, buf, 7, lbl_80464B84, p280, 0);
    }
    u8* pos = this_ + 0xc;
    s32 p280b = *(s32*)(this_ + 0x280);
    if (*(s32*)(this_ + 4) < 8) {
        void* res = (*(DMLKResMgr**)(lbl_8053AAF8 + 0xa4))->getRes('SOB ', lbl_80464B84);
        fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), pos, res, p280b, lbl_8053C7F8, lbl_8053C7F8, 0);
    }
    fn_803075AC(*(void**)(this_ + 0x198), *(s32*)(this_ + 4), this_ + 0xc, *(s32*)(this_ + 0x280), 0, 1, -1, 0, 0, 0);
}

extern "C" const f32 lbl_8053C844;
extern "C" const f32 lbl_8053C848;
extern "C" const f32 lbl_8053C84C;
extern "C" const f32 lbl_8053C850;
extern "C" const f32 lbl_8053C854;
extern "C" void fn_800FE8C0(u8* p);
extern "C" void fn_8011C308(u8* this_) {
    JGeometry::TVec3f v20;
    JGeometry::TVec3f v22;
    JGeometry::TVec3f v11;
    s32 j;
    int d;
    f32 fx;

    fn_8010DF78(this_);
    if (*(s32*)(this_ + 0x238) >= 2 && *(s32*)(this_ + 0x238) <= 11) {
        fn_8030C210(*(u8**)(lbl_8053AB10 + 0x24), this_ + 0xc);
        fn_8011B3F0(this_);
    }
    switch (*(s32*)(this_ + 0x238)) {
    case 0:
        this_[0x11d] = 0;
        break;
    case 4:
        if (dmlkSink(this_, dmlkTime(4), lbl_8053C800, lbl_8053C824, lbl_8053C7D8)) {
            fn_8011B878(this_, 5);
        }
        break;
    case 9:
        d = dmlkTime(9);
        *(f32*)(this_ + 0x44) = lbl_8053C800 - lbl_8053C804 * d;
        *(f32*)(this_ + 0x40) = lbl_8053C808;
        if (d > 1 && *(f32*)(this_ + 0x14) <= lbl_8053C7D8) {
            *(f32*)(this_ + 0x44) = lbl_8053C7D8;
            *(f32*)(this_ + 0x40) = lbl_8053C7D8;
            *(f32*)(this_ + 0x3c) = lbl_8053C7D8;
            *(f32*)(this_ + 0x14) = lbl_8053C7D8;
        }
        break;
    case 11: {
        j = 0;
        JGeometry::TVec3f* pv = &v11;
        for (; j < 4; j++) {
            *pv = *(JGeometry::TVec3f*)fn_8023E724(j);
            *pv += *(JGeometry::TVec3f*)(this_ + 0x26c);
            fn_802303FC(j, &pv->x, 0xff);
        }
        break;
    }
    case 16:
        *(f32*)(this_ + 0x10) -= lbl_8053C828;
        if (*(f32*)(this_ + 0x10) <= *(f32*)(this_ + 0x28) - lbl_8053C7F0) {
            *(f32*)(this_ + 0x10) = *(f32*)(this_ + 0x28) - lbl_8053C7F0;
        }
        break;
    case 19:
        dmlkSink(this_, dmlkTime(19), lbl_8053C82C, lbl_8053C7D8, lbl_8053C7D8);
        break;
    case 20:
        *(f32*)(this_ + 0x10) -= lbl_8053C830;
        if (*(f32*)(this_ + 0x10) <= *(f32*)(this_ + 0x28) - lbl_8053C834) {
            *(f32*)(this_ + 0x10) = *(f32*)(this_ + 0x28) - lbl_8053C834;
            fn_8011B878(this_, 0x17);
            break;
        }
        if (*(s32*)((u8*)fn_8011921C() + 8) >= 0x52d) {
            v20 = *(JGeometry::TVec3f*)fn_8023E724(0);
            v20.y -= lbl_8053C838;
            dmlkSetAll(&v20.x);
        }
        break;
    case 22:
        if (*(u8*)fn_8011921C() == 0) {
            fn_801186B0(fn_8011921C(), 0x12);
            *((u8*)fn_8011921C() + 2) = 1;
        }
        *(f32*)(this_ + 0x10) -= lbl_8053C830;
        if (*(f32*)(this_ + 0x10) <= *(f32*)(this_ + 0x28)) {
            *(f32*)(this_ + 0x10) = *(f32*)(this_ + 0x28);
            fn_8011B878(this_, 0x17);
        } else {
            v22 = *(JGeometry::TVec3f*)(this_ + 0xc);
            v22.y += lbl_8053C7E8;
            dmlkSetAll(&v22.x);
        }
        break;
    case 23:
        (*(s32*)(this_ + 0x23c))++;
        if (dmlkSink(this_, *(s32*)(this_ + 0x23c), lbl_8053C800, lbl_8053C83C, lbl_8053C840)) {
            fn_8011B878(this_, 0x18);
        }
        break;
    case 24:
        fn_801F0E34(this_, 0x400c7, 0);
        fn_8011B878(this_, 0x19);
        break;
    case 25:
        (*(s32*)(this_ + 0x23c))++;
        if (dmlkSink(this_, *(s32*)(this_ + 0x23c), lbl_8053C82C, lbl_8053C7D8, lbl_8053C7D8)) {
            *(s32*)(this_ + 0x23c) = 0;
        }
        if (fn_801F2B7C(this_, 0, -1, 1)) {
            fn_8011B878(this_, 0x1a);
        }
        break;
    case 26:
        fx = lbl_8053C844;
        (*(s32*)(this_ + 0x23c))++;
        if (this_[0x231] == 0) {
            fx = lbl_8053C848;
        }
        if (dmlkSink(this_, *(s32*)(this_ + 0x23c), lbl_8053C800, lbl_8053C7D8, fx)) {
            fn_8011B878(this_, 0x19);
            if (this_[0x231] != 0) {
                *(f32*)(this_ + 0xc) = *(f32*)(this_ + 0x24) - lbl_8053C7F0;
            } else {
                *(f32*)(this_ + 0xc) = lbl_8053C7F0 + *(f32*)(this_ + 0x24);
            }
        }
        break;
    case 27:
        if (*(s32*)(this_ + 0x240) < 3) {
            (*(s32*)(this_ + 0x23c))++;
            if (dmlkSink(this_, *(s32*)(this_ + 0x23c), lbl_8053C82C, lbl_8053C7D8, lbl_8053C7D8)) {
                *(s32*)(this_ + 0x23c) = 0;
                (*(s32*)(this_ + 0x240))++;
            }
        }
        break;
    case 28:
        fx = lbl_8053C840;
        if (this_[0x231] == 0) {
            fx = lbl_8053C84C;
        }
        if (dmlkSink(this_, dmlkTime(29), lbl_8053C800, lbl_8053C850, fx)) {
            fn_8011B878(this_, 0x1e);
        }
        break;
    case 34:
        *(f32*)(this_ + 0x10) += lbl_8053C830;
        if (*(f32*)(this_ + 0x10) >= lbl_8053C854 + *(f32*)(this_ + 0x28)) {
            *(f32*)(this_ + 0x10) = lbl_8053C854 + *(f32*)(this_ + 0x28);
        }
        break;
    default:
        break;
    }
    ((JGeometry::TVec3f*)(this_ + 0xc))->add(*(JGeometry::TVec3f*)(this_ + 0x3c));
    this_[0x284] = *(s32*)(this_ + 0x98);
    if (*(s32*)(this_ + 0x238) == 16) {
        if (this_[0x230] != 0) {
            fn_800FE8C0(this_ + 0x278);
            this_[0x230] = 0;
        } else {
            this_[0x230] = 1;
        }
    } else {
        fn_800FE8C0(this_ + 0x278);
    }
}

extern "C" void fn_8010DF98(u8* this_);
extern "C" void fn_8011B878(u8* this_, s32 id);
extern "C" void fn_800FEB78(u8* this_, s32 flag);
extern "C" f32 lbl_8053C858;
extern "C" void fn_8011CB5C(u8* this_) {
    fn_8010DF98(this_);
    *(s32*)(this_ + 0x234) = *(u32*)(this_ + 0x90) & 0xf;
    *(s32*)(this_ + 0x98) = (s8)((*(u32*)(this_ + 0x90) >> 4) & 3);
    switch (*(s32*)(this_ + 0x234)) {
    case 1:
        fn_8011B878(this_, 0xd);
        *(s32*)(this_ + 0x98) = 3;
        fn_800FEB78(this_ + 0x278, 0);
        break;
    case 2:
        fn_8011B878(this_, 0x16);
        *(s32*)(this_ + 0x98) = 3;
        fn_800FEB78(this_ + 0x278, 1);
        *(f32*)(this_ + 0x10) = *(f32*)(this_ + 0x10) + lbl_8053C858;
        break;
    default:
        fn_800FEB78(this_ + 0x278, 0);
        break;
    }
    *(u8*)(this_ + 0x284) = *(s32*)(this_ + 0x98);
}

extern "C" u8* fn_8011CC2C(u8* p) {
    f32 zero;

    fn_8010E074(p);
    *(void**)p = lbl_8049DB90;
    zero = lbl_8053C7D8;
    *(u8*)(p + 0x230) = 1;
    *(u8*)(p + 0x231) = 0;
    *(s32*)(p + 0x234) = 0;
    *(s32*)(p + 0x238) = 0;
    *(s32*)(p + 0x23c) = 0;
    *(s32*)(p + 0x240) = 0;
    *(f32*)(p + 0x244) = zero;
    *(f32*)(p + 0x248) = zero;
    *(f32*)(p + 0x254) = zero;
    *(f32*)(p + 0x250) = zero;
    *(f32*)(p + 0x25c) = zero;
    *(f32*)(p + 0x258) = zero;
    return p;
}

#if !defined(VERSION_G4SP01)
extern "C" Actor* fn_8011B390(Actor* param_1, s16 param_2) {
    if (param_1 != 0) {
        *(void**)param_1 = lbl_8049DB90;
        __dt__13Base_8010E074Fv(param_1, 0);
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_8011B3F0(u8* p) {
    u8* view = *(u8**)(lbl_8053AB10 + 0x24);
    if (view[0x179] == 0) {
        view[0x17a] = 1;
        view[0x179] = 0;
    }
    switch (*(s32*)(p + 0x238)) {
    case 7: {
        s32 elapsed = dmlkElapsed(fn_8011921C());
        if (elapsed < 180) {
            dmlkRequestBounds(p);
            break;
        }
        if (elapsed > 410 && elapsed != 0) {
            fn_801CD950((f32*)(p + 0x244), lbl_8053C7D8, lbl_8053C7DC);
        } else {
            fn_801CD950((f32*)(p + 0x244), lbl_8053C7E0, lbl_8053C7E4);
        }
        fn_801CD950((f32*)(p + 0x254), (*(f32*)(p + 0x10) - lbl_8053C7E8) - lbl_8053C7EC, -*(f32*)(p + 0x244));
        fn_801CD950((f32*)(p + 0x25c), lbl_8053C7EC + (lbl_8053C7E8 + *(f32*)(p + 0x10)), *(f32*)(p + 0x244));
        dmlkRequestBounds(p);
        break;
    }
    case 1:
    case 2:
    case 3:
        dmlkSetBounds(p, (f32*)(p + 0xc));
        dmlkRequestBounds(p);
        break;
    case 4:
    case 5: {
        JGeometry::TVec3f pos(*(JGeometry::TVec3f*)(p + 0xc));
        pos.y += *(f32*)(p + 0x248);
        fn_801CD950((f32*)(p + 0x248), lbl_8053C7E8, lbl_8053C7F4);
        dmlkSetBounds(p, &pos.x);
        dmlkRequestBounds(p);
        break;
    }
    case 6: {
        JGeometry::TVec3f pos(*(JGeometry::TVec3f*)(p + 0xc));
        pos.y += *(f32*)(p + 0x248);
        fn_801CD950((f32*)(p + 0x248), lbl_8053C7D8, lbl_8053C7F4);
        dmlkSetBounds(p, &pos.x);
        dmlkRequestBounds(p);
        break;
    }
    case 8:
        view = *(u8**)(lbl_8053AB10 + 0x24);
        if (view[0x7f5] == 0) {
            view[0x7f4] = 1;
            *(s32*)(view + 0x7f8) = 4;
            *(f32*)(view + 0x7fc) = *(f32*)(p + 0xc);
            *(f32*)(view + 0x800) = *(f32*)(p + 0x10);
            *(f32*)(view + 0x804) = *(f32*)(p + 0x14);
            view[0x7f6] = 0;
        }
        break;
    case 9:
    case 10:
    case 11:
        view = *(u8**)(lbl_8053AB10 + 0x24);
        if (view[0x840] == 0) {
            f32 step;
            f32 zero;
            step = 1.0f;
            view[0x840] = 1;
            zero = -1.0f;
            f32 x = *(f32*)(p + 0xc);
            *(f32*)(view + 0x84c) = x;
            *(f32*)(view + 0x844) = x;
            f32 y = *(f32*)(p + 0x10);
            *(f32*)(view + 0x850) = y;
            *(f32*)(view + 0x848) = y;
            *(f32*)(view + 0x854) = step;
            *(f32*)(view + 0x1d4) = zero;
            *(f32*)(view + 0x1d8) = zero;
        }
        break;
    default:
        dmlkRequestBounds(p);
        break;
    }
}

#endif

#if !defined(VERSION_G4SP01)
extern "C" void* fn_801902C0(void);
extern "C" void fn_801F0E34(u8* this_, s32 id, s32 flag);
extern "C" void fn_8013CC50(u32 room, Vec* pos, f32 scale, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_80230498(s32 i, Vec* v, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_80230BF4(s32 i, s32 n);
extern "C" const f32 lbl_8053C81C;
extern "C" f32 lbl_8053C820;
extern "C" const f32 lbl_8053C818;
static inline JGeometry::TVec3f dmlkDivide(const JGeometry::TVec3f& value, const f32 divisor) {
    JGeometry::TVec3f copy(value);
    return JGeometry::TVec3f(copy.x / divisor, copy.y / divisor, copy.z / divisor);
}
static inline void dmlkEmitBurstImpl(u8* this_) {
        JGeometry::TVec3f tmp12;
        tmp12 = *(JGeometry::TVec3f*)(this_ + 0xc);
        fn_8013CC50(*(u32*)(this_ + 4), (Vec*)&tmp12, lbl_8053C7F8, 0x41d, 0, 0, 0, 0, 1);
        fn_8013CC50(*(u32*)(this_ + 4), (Vec*)&tmp12, lbl_8053C7F8, 0x41e, 0, 0, 0, 0, 1);
        fn_8013CC50(*(u32*)(this_ + 4), (Vec*)&tmp12, lbl_8053C7F8, 0x41f, 0, 0, 0, 0, 1);
        fn_8013CC50(*(u32*)(this_ + 4), (Vec*)&tmp12, lbl_8053C7F8, 0x420, 0, 0, 0, 0, 1);
        fn_801F0E34(this_, 0x30091, 0);
}
static inline void dmlkEmitPuffImpl(u8* this_) {
        JGeometry::TVec3f tmp16;
        *(s32*)(this_ + 0x98) = 2;
        *(s32*)(this_ + 0x278) = 0;
        *(u8*)(this_ + 0x284) = 2;
        tmp16 = *(JGeometry::TVec3f*)(this_ + 0xc);
        tmp16.y = tmp16.y + lbl_8053C818;
        fn_8013CC50(*(u32*)(this_ + 4), (Vec*)&tmp16, 1.0f, 0x33b, 0, 0, 0, 0, 1);
}
static inline void dmlkEmitBurst(u8* this_) { dmlkEmitBurstImpl(this_); }
static inline void dmlkEmitPuff(u8* this_) { dmlkEmitPuffImpl(this_); }
extern "C" void fn_8011B878(u8* this_, s32 id) {
    JGeometry::TVec3f tmp9;
    switch (id) {
    case 0:
        *(u8*)(this_ + 0x11d) = 0;
        break;
    case 1:
        ((Actor*)this_)->v10(0xff, 1);
        break;
    case 4: {
        u8* p = (u8*)fn_801902C0();
        *(u8*)(p + 0x7c0) = 1;
        *(s32*)(p + 0x7bc) = 1;
        fn_801F0E34(this_, 0x40035, 0);
        fn_800FEB78(this_ + 0x278, 4);
        *(u8*)(this_ + 0x11d) = 1;
        break;
    }
    case 5:
        fn_800FEB78(this_ + 0x278, 0);
        break;
    case 6:
        fn_801F0E34(this_, 0x400c7, 0);
        break;
    case 8:
        fn_800FEB78(this_ + 0x278, 4);
        break;
    case 9: {
        ((Actor*)this_)->v10(0xff, 0);
        *(u8*)(this_ + 0x11d) = 0;
        tmp9 = *(JGeometry::TVec3f*)(this_ + 0x24);
        tmp9.y = tmp9.y + lbl_8053C81C;
        for (s32 i = 0; i < 4; i++) {
            fn_80230498(i, (Vec*)&tmp9, 0x18, 0xff, -0x80, -0x80, 1);
        }
        break;
    }
    case 10: {
        Vec* p;
        Vec* pos;
        f32 k;
        for (s32 i = 0; i < 4; i++) {
            fn_80230BF4(i, 3);
        }
        *(JGeometry::TVec3f*)(this_ + 0x260) = *(JGeometry::TVec3f*)(this_ + 0x24);
        p = (Vec*)fn_8023E724(0);
        *(JGeometry::TVec3f*)(this_ + 0x26c) = dmlkDivide(*(JGeometry::TVec3f*)(this_ + 0x24) - *(JGeometry::TVec3f*)p, lbl_8053C820);
        break;
    }
    case 11:
        *(u8*)(this_ + 0x11d) = 0;
        break;
    case 12:
        dmlkEmitBurst(this_);
        break;
    case 13:
        *(u8*)(this_ + 0x11d) = 1;
        break;
    case 14:
        *(s32*)(this_ + 0x98) = 3;
        *(s32*)(this_ + 0x278) = 1;
        *(u8*)(this_ + 0x284) = 3;
        break;
    case 15:
        *(s32*)(this_ + 0x98) = 2;
        *(s32*)(this_ + 0x278) = 0;
        *(u8*)(this_ + 0x284) = 2;
        break;
    case 16:
        dmlkEmitPuff(this_);
        break;
    case 17:
        *(s32*)(this_ + 0x98) = 3;
        fn_800FEB78(this_ + 0x278, 1);
        break;
    case 18:
        fn_800FEB78(this_ + 0x278, 0);
        break;
    case 19:
        *(s32*)(this_ + 0x98) = 3;
        fn_800FEB78(this_ + 0x278, 1);
        *(f32*)(this_ + 0x44) = lbl_8053C7D8;
        *(f32*)(this_ + 0x40) = lbl_8053C7D8;
        *(f32*)(this_ + 0x3c) = lbl_8053C7D8;
        break;
    case 20: {
        s32 i;
        fn_800FEB78(this_ + 0x278, 4);
        *(s32*)(this_ + 0x23c) = 0;
        for (i = 0; i < 4; i++) {
            fn_80230498(i, (Vec*)fn_8023E724(i), 0x3f, 0xff, -0x80, -0x80, 1);
        }
        break;
    }
    case 21:
        *(s32*)(this_ + 0x98) = 2;
        fn_800FEB78(this_ + 0x278, 0);
        *(s32*)(this_ + 0x23c) = 0;
        break;
    case 22:
        fn_800FEB78(this_ + 0x278, 0);
        *(s32*)(this_ + 0x23c) = 0;
        break;
    case 23: {
        fn_800FEB78(this_ + 0x278, 4);
        *(bool*)(this_ + 0x231) = !*(bool*)(this_ + 0x231);
        *(s32*)(this_ + 0x23c) = 0;
        *(f32*)(this_ + 0x14) = lbl_8053C7D8;
        fn_801F0E34(this_, 0x400c7, 0);
        break;
    }
    case 24:
        fn_800FEB78(this_ + 0x278, 0);
        *(f32*)(this_ + 0x44) = lbl_8053C7D8;
        *(f32*)(this_ + 0x40) = lbl_8053C7D8;
        *(f32*)(this_ + 0x3c) = lbl_8053C7D8;
        *(f32*)(this_ + 0x14) = lbl_8053C7D8;
        break;
    case 25:
        fn_801F0E34(this_, 0x400c7, 0);
        break;
    case 26:
        fn_800FEB78(this_ + 0x278, 4);
        *(f32*)(this_ + 0x14) = lbl_8053C7D8;
        break;
    case 27:
        *(s32*)(this_ + 0x98) = 3;
        fn_800FEB78(this_ + 0x278, 0);
        break;
    case 28:
        fn_801F0E34(this_, 0x400c7, 0);
        break;
    case 34:
        *(s32*)(this_ + 0x98) = 2;
        fn_800FEB78(this_ + 0x278, 1);
        break;
    }
    *(s32*)(this_ + 0x238) = id;
}
#endif

// Keep regional definitions that were present before source-tree consolidation.
#if defined(VERSION_G4SP01)
extern "C" char lbl_8049DB90[];
extern "C" void __dt__13Base_8010E074Fv(void*, s32);
extern "C" void fn_8010E074(u8*);
extern "C" Actor* fn_8011B390(Actor* param_1, s16 param_2) {
    if (param_1 != 0) {
        *(void**)param_1 = lbl_8049DB90;
        __dt__13Base_8010E074Fv(param_1, 0);
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}

extern "C" void* fn_801902C0(void);
extern "C" void fn_801F0E34(u8* this_, s32 id, s32 flag);
extern "C" void fn_8013CC50(u32 room, Vec* pos, f32 scale, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_80230498(s32 i, Vec* v, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_80230BF4(s32 i, s32 n);
extern "C" f32 lbl_8053C81C;
extern "C" f32 lbl_8053C820;
extern "C" f32 lbl_8053C818;
extern "C" void fn_8011B878(u8* this_, s32 id) {
    switch (id) {
    case 0:
        *(u8*)(this_ + 0x11d) = 0;
        break;
    case 1:
        (*(void (**)(u8*, s32, s32))((u8*)*(void**)this_ + 0x30))(this_, 0xff, 1);
        break;
    case 4: {
        u8* p = (u8*)fn_801902C0();
        *(u8*)(p + 0x7c0) = 1;
        *(s32*)(p + 0x7bc) = 1;
        fn_801F0E34(this_, 0x40035, 0);
        fn_800FEB78(this_ + 0x278, 4);
        *(u8*)(this_ + 0x11d) = 1;
        break;
    }
    case 5:
        fn_800FEB78(this_ + 0x278, 0);
        break;
    case 6:
        fn_801F0E34(this_, 0x400c7, 0);
        break;
    case 8:
        fn_800FEB78(this_ + 0x278, 4);
        break;
    case 9: {
        Vec tmp;
        (*(void (**)(u8*, s32, s32))((u8*)*(void**)this_ + 0x30))(this_, 0xff, 0);
        *(u8*)(this_ + 0x11d) = 0;
        tmp = *(Vec*)(this_ + 0x24);
        tmp.y = tmp.y + lbl_8053C81C;
        for (s32 i = 0; i < 4; i++) {
            fn_80230498(i, &tmp, 0x18, 0xff, -0x80, -0x80, 1);
        }
        break;
    }
    case 10: {
        Vec* p;
        Vec* pos;
        f32 k;
        for (s32 i = 0; i < 4; i++) {
            fn_80230BF4(i, 3);
        }
        *(Vec*)(this_ + 0x260) = *(Vec*)(this_ + 0x24);
        p = fn_8023E724(0);
        pos = (Vec*)(this_ + 0x24);
        k = lbl_8053C820;
        *(f32*)(this_ + 0x26c) = (pos->x - p->x) / k;
        *(f32*)(this_ + 0x270) = (pos->y - p->y) / k;
        *(f32*)(this_ + 0x274) = (pos->z - p->z) / k;
        break;
    }
    case 11:
        *(u8*)(this_ + 0x11d) = 0;
        break;
    case 12: {
        Vec tmp;
        tmp = *(Vec*)(this_ + 0xc);
        fn_8013CC50(*(u32*)(this_ + 4), &tmp, lbl_8053C7F8, 0x41d, 0, 0, 0, 0, 1);
        fn_8013CC50(*(u32*)(this_ + 4), &tmp, lbl_8053C7F8, 0x41e, 0, 0, 0, 0, 1);
        fn_8013CC50(*(u32*)(this_ + 4), &tmp, lbl_8053C7F8, 0x41f, 0, 0, 0, 0, 1);
        fn_8013CC50(*(u32*)(this_ + 4), &tmp, lbl_8053C7F8, 0x420, 0, 0, 0, 0, 1);
        fn_801F0E34(this_, 0x30091, 0);
        break;
    }
    case 13:
        *(u8*)(this_ + 0x11d) = 1;
        break;
    case 14:
        *(s32*)(this_ + 0x98) = 3;
        *(s32*)(this_ + 0x278) = 1;
        *(u8*)(this_ + 0x284) = 3;
        break;
    case 15:
        *(s32*)(this_ + 0x98) = 2;
        *(s32*)(this_ + 0x278) = 0;
        *(u8*)(this_ + 0x284) = 2;
        break;
    case 16: {
        Vec tmp;
        *(s32*)(this_ + 0x98) = 2;
        *(s32*)(this_ + 0x278) = 0;
        *(u8*)(this_ + 0x284) = 2;
        tmp = *(Vec*)(this_ + 0xc);
        tmp.y = tmp.y + lbl_8053C818;
        fn_8013CC50(*(u32*)(this_ + 4), &tmp, lbl_8053C7F8, 0x33b, 0, 0, 0, 0, 1);
        break;
    }
    case 17:
        *(s32*)(this_ + 0x98) = 3;
        fn_800FEB78(this_ + 0x278, 1);
        break;
    case 18:
        fn_800FEB78(this_ + 0x278, 0);
        break;
    case 19:
        *(s32*)(this_ + 0x98) = 3;
        fn_800FEB78(this_ + 0x278, 1);
        *(f32*)(this_ + 0x44) = lbl_8053C7D8;
        *(f32*)(this_ + 0x40) = lbl_8053C7D8;
        *(f32*)(this_ + 0x3c) = lbl_8053C7D8;
        break;
    case 20: {
        s32 i;
        fn_800FEB78(this_ + 0x278, 4);
        *(s32*)(this_ + 0x23c) = 0;
        for (i = 0; i < 4; i++) {
            fn_80230498(i, fn_8023E724(i), 0x3f, 0xff, -0x80, -0x80, 1);
        }
        break;
    }
    case 21:
        *(s32*)(this_ + 0x98) = 2;
        fn_800FEB78(this_ + 0x278, 0);
        *(s32*)(this_ + 0x23c) = 0;
        break;
    case 22:
        fn_800FEB78(this_ + 0x278, 0);
        *(s32*)(this_ + 0x23c) = 0;
        break;
    case 23:
        fn_800FEB78(this_ + 0x278, 4);
        *(u8*)(this_ + 0x231) = *(u8*)(this_ + 0x231) == 0;
        *(s32*)(this_ + 0x23c) = 0;
        *(f32*)(this_ + 0x14) = lbl_8053C7D8;
        fn_801F0E34(this_, 0x400c7, 0);
        break;
    case 24:
        fn_800FEB78(this_ + 0x278, 0);
        *(f32*)(this_ + 0x44) = lbl_8053C7D8;
        *(f32*)(this_ + 0x40) = lbl_8053C7D8;
        *(f32*)(this_ + 0x3c) = lbl_8053C7D8;
        *(f32*)(this_ + 0x14) = lbl_8053C7D8;
        break;
    case 25:
        fn_801F0E34(this_, 0x400c7, 0);
        break;
    case 26:
        fn_800FEB78(this_ + 0x278, 4);
        *(f32*)(this_ + 0x14) = lbl_8053C7D8;
        break;
    case 27:
        *(s32*)(this_ + 0x98) = 3;
        fn_800FEB78(this_ + 0x278, 0);
        break;
    case 28:
        fn_801F0E34(this_, 0x400c7, 0);
        break;
    case 34:
        *(s32*)(this_ + 0x98) = 2;
        fn_800FEB78(this_ + 0x278, 1);
        break;
    }
    *(s32*)(this_ + 0x238) = id;
}

#endif
