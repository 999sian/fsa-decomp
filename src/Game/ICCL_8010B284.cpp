// ICCL_8010B284: .text 0x8010B284-0x8010C294 (actor ICCL)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

// ---- from Game/fn_8010BF7C_dtor.cpp

extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern "C" void fn_801EE434(void* handle);
extern void* lbl_8049CFC8[];
extern void* lbl_8049CC34[];

extern "C" void* fn_8010BF7C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_8049CFC8;
        fn_801EE434(*(void**)(p + 0x27c));
        *(s32*)(p + 0x27c) = 0;
        if (p + 0x244 != 0) {
            if (p + 0x268 != 0) {
                *(void**)(p + 0x268) = lbl_8049CC34;
            }
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}


#include "JSystem/JGeometry/Vec.h"
extern "C" void __ct__5ActorFv(void* this_);
extern "C" void v01__5ActorFv(void* this_);
extern "C" void fn_801D267C(void* anim);
extern "C" void fn_801D2608(void* obj, void* tbl, s32 n);
extern "C" void fn_801D22DC(void* obj, s32 a, s32 b, s32 c);
extern "C" void fn_801D1F14(void* obj, f32 f);
extern "C" BOOL fn_8010B40C(char* this_, s32 state);
extern "C" JGeometry::TVec3<f32>* fn_8023E724(s32 player);
extern "C" s32 fn_8023DE58(s32 player);
extern "C" void fn_801CD150(JGeometry::TVec3<f32>* in, JGeometry::TVec3<f32>* out);
extern "C" u16 fn_80226850(JGeometry::TVec3<f32>* pos, s32 room);
extern const f32 lbl_8053C45C;
extern const f32 lbl_8053C460;
extern const f32 lbl_8053C470;
extern const f32 lbl_8053C478;
extern const f32 lbl_8053C47C;
extern const f32 lbl_8053C488;
extern u8 lbl_80539EE0[8];

struct IcclVT {
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual s32 v13();
};

extern "C" void* fn_8010C00C(char* p) {
    __ct__5ActorFv(p);
    *(void**)p = lbl_8049CFC8;
    *(s32*)(p + 0x230) = 0;
    *(s32*)(p + 0x234) = 0;
    *(s32*)(p + 0x238) = 0;
    *(f32*)(p + 0x240) = lbl_8053C478;
    fn_801D267C(p + 0x244);
    *(s32*)(p + 0x27c) = 0;
    return p;
}

extern "C" void fn_8010BEB8(char* p) {
    v01__5ActorFv(p);
    *(f32*)(p + 0x60) = lbl_8053C488;
    *(f32*)(p + 0x64) = lbl_8053C488;
    *(f32*)(p + 0x68) = lbl_8053C47C;
    *(f32*)(p + 0x6c) = lbl_8053C47C;
    *(f32*)(p + 0x70) = lbl_8053C488;
    *(f32*)(p + 0x74) = lbl_8053C488;
    *(f32*)(p + 0x78) = lbl_8053C47C;
    *(f32*)(p + 0x7c) = lbl_8053C47C;
    *(f32*)(p + 0x80) = lbl_8053C488;
    *(f32*)(p + 0x84) = lbl_8053C488;
    *(f32*)(p + 0x88) = lbl_8053C47C;
    *(f32*)(p + 0x8c) = lbl_8053C47C;
    fn_801D2608(p + 0x244, lbl_80539EE0, 2);
    fn_801D22DC(p + 0x244, 0, 2, 0);
    fn_801D1F14(p + 0x244, lbl_8053C470);
    if (((IcclVT*)p)->v13() > 0) {
        *(u8*)(p + 0x11d) = 0;
        fn_8010B40C(p, 5);
    }
}

#pragma auto_inline off
extern "C" bool fn_8010B284(char* p) {
    JGeometry::TVec3<f32> pl;
    JGeometry::TVec3<f32> pos = *(JGeometry::TVec3<f32>*)(p + 0xc);
    for (s32 i = 0; i < 4; i++) {
        pl = *fn_8023E724(i);
        if (*(s32*)(p + 4) == 8 && fn_8023DE58(i) == 0) {
            fn_801CD150(&pl, &pl);
        }
        if (!(*(f32*)(p + 0x10) > pl.y) && !(*(f32*)(p + 0xc) - lbl_8053C45C > pl.x) &&
            !(pl.x > *(f32*)(p + 0xc) + lbl_8053C45C)) {
            s32 j;
            bool hit = false;
            for (j = 1; j <= 0x18; j++) {
                pos.y = lbl_8053C460 * j + *(f32*)(p + 0x10);
                if (pos.y >= pl.y) {
                    break;
                }
                u16 attr = fn_80226850(&pos, *(s32*)(p + 4));
                if (attr >= 999 || (attr >= 0x250 && attr <= 0x26f)) {
                    hit = true;
                    break;
                }
            }
            return !hit;
        }
    }
    return false;
}
#pragma auto_inline reset

extern "C" void fn_801F0E34(void* this_, s32 id, s32 c);
extern "C" char* fn_8013C824();
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void* mgr, void* em);
extern "C" void* fn_8013CC50(u32 room, void* pos, f32 scale, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern const f32 lbl_8053C474;

extern "C" BOOL fn_8010B40C(char* p, s32 state) {
    switch (state) {
    case 0:
        break;
    case 1:
        *(f32*)(p + 0x23c) = lbl_8053C470;
        fn_801F0E34(p, 0x3007c, 0);
        break;
    case 2:
        if (*(void**)(p + 0x100) != NULL) {
            void* mgr = *(void**)(fn_8013C824() + 0xc);
            forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, *(void**)(p + 0x100));
            *(void**)(p + 0x100) = NULL;
        }
        if (*(void**)(p + 0x104) != NULL) {
            void* mgr = *(void**)(fn_8013C824() + 0xc);
            forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, *(void**)(p + 0x104));
            *(void**)(p + 0x104) = NULL;
        }
        if (*(s32*)(p + 4) == 0) {
            fn_8013CC50(*(u32*)(p + 4), p + 0xc, lbl_8053C474, 0x28d, 0, 0, 0, 0, 1);
            *(void**)(p + 0x27c) = fn_8013CC50(*(u32*)(p + 4), p + 0xc, lbl_8053C474, 0x28e, 0, 0, 0, 0, 1);
        }
        *(f32*)(p + 0x23c) = lbl_8053C470;
        fn_801F0E34(p, 0x30061, 0);
        break;
    case 3:
        fn_8013CC50(*(u32*)(p + 4), p + 0xc, lbl_8053C478, 0x28b, 0, 0, 0, 0, 1);
        fn_8013CC50(*(u32*)(p + 4), p + 0xc, lbl_8053C478, 0x28c, 0, 0, 0, 0, 1);
        fn_801D22DC(p + 0x244, 1, 0, 0);
        *(f32*)(p + 0x23c) = lbl_8053C470;
        fn_801F0E34(p, 0x3007d, 0);
        break;
    case 4:
        *(u8*)(p + 0x11d) = 0;
        *(f32*)(p + 0x240) = lbl_8053C470;
        fn_801D22DC(p + 0x244, 0, 2, 0);
        *(f32*)(p + 0xc) = *(f32*)(p + 0x24);
        *(f32*)(p + 0x10) = *(f32*)(p + 0x28);
        *(f32*)(p + 0x14) = *(f32*)(p + 0x2c);
        *(f32*)(p + 0x10) = *(f32*)(p + 0x28) - lbl_8053C47C;
        break;
    case 5:
        *(s32*)(p + 0xd8) = 0;
        *(s32*)(p + 0x238) = 0;
        break;
    }
    fn_801D1F14(p + 0x244, lbl_8053C470);
    *(s32*)(p + 0x230) = state;
    *(s32*)(p + 0x234) = 0;
    return TRUE;
}

struct IcclDrawParam {
    IcclDrawParam() : m40(-1), m44(-1) {
        for (u8 i = 0; i < 16; i++) {
            mIdx[i] = i;
        }
    }
    void reset() {
        m40 = -1;
        m44 = 0;
        mMtx = NULL;
        m4C = 0;
        m4D = 0;
        m4E = 0;
        m4F = 1;
        m50 = 1;
        m51 = 0;
        m52 = 0;
        m53 = 0;
        m54 = 0;
        m55 = 0;
        m56 = 1;
        m58 = 3;
        m5C = 1;
        m5D = 0;
        m5E = 0;
        m60 = -1;
        m64 = 0;
        m68 = 2;
    }
    u8 mIdx[16];
    s32 m40;
    s32 m44;
    f32 (*mMtx)[4];
    u8 m4C, m4D, m4E, m4F, m50, m51, m52, m53, m54, m55, m56;
    s32 m58;
    u8 m5C, m5D, m5E;
    s32 m60;
    s32 m64;
    s32 m68;
};
extern "C" void v06__5ActorFv(void* this_);
extern "C" void fn_801F02BC(void* this_, const char* name, s32 id, IcclDrawParam* prm, s32 a, s32 b, s32 c, f32 s0, f32 s1);
extern const char lbl_804642F0[];

extern "C" void fn_8010B648(char* p) {
    v06__5ActorFv(p);
    IcclDrawParam prm;
    f32 mtx[3][4];
    prm.reset();
    if (*(s32*)(p + 0x230) == 5 && !((JGeometry::TVec3<f32>*)(p + 0x54))->isZero()) {
        mtx[0][3] = lbl_8053C470;
        mtx[1][3] = lbl_8053C470;
        mtx[2][3] = lbl_8053C470;
        f32 sx = *(f32*)(p + 0x54);
        f32 sy = *(f32*)(p + 0x58);
        f32 sz = *(f32*)(p + 0x5c);
        mtx[0][0] = sx;
        mtx[0][1] = lbl_8053C470;
        mtx[0][2] = lbl_8053C470;
        mtx[1][0] = lbl_8053C470;
        mtx[1][1] = sy;
        mtx[1][2] = lbl_8053C470;
        mtx[2][0] = lbl_8053C470;
        mtx[2][1] = lbl_8053C470;
        mtx[2][2] = sz;
        prm.mMtx = mtx;
    }
    if (((JGeometry::TVec3<f32>*)(p + 0x54))->isZero()) {
        *(u8*)(p + 0x11d) = 0;
    }
    fn_801F02BC(p, lbl_804642F0, *(s32*)(p + 0x254) + 0x19c, &prm, 7, 0, 0, lbl_8053C478, lbl_8053C478);
    if (((JGeometry::TVec3<f32>*)(p + 0x54))->isZero()) {
        *(u8*)(p + 0x11d) = 1;
    }
}

#include "JSystem/JGeometry/Box.h"
extern "C" void v03__5ActorFv(void* this_);
extern "C" s32 fn_801F285C(void* this_, s32 a, s32 b, s32 c, s32 d);
extern "C" s32 fn_8023AA18(JGeometry::TBox2<f32>* box, s32 room, JGeometry::TVec2<f32>* out);
extern "C" s32 fn_8023AE34(JGeometry::TBox2<f32>* box, s32 room, JGeometry::TVec2<f32>* out);
extern "C" s32 fn_8023AC74(JGeometry::TBox2<f32>* box, s32 room, JGeometry::TVec2<f32>* out);
extern "C" s32 fn_8023AD54(JGeometry::TBox2<f32>* box, s32 room, JGeometry::TVec2<f32>* out);
extern "C" s32 fn_8023AB94(JGeometry::TBox2<f32>* box, s32 room, JGeometry::TVec2<f32>* out);
extern "C" void fn_801CC820(s32 player, s32 a);
extern "C" void fn_801CC538(s32 player, JGeometry::TVec2<f32>* v, JGeometry::TVec3<f32>* out, s32 a);
extern "C" void fn_801CC640(s32 player, s32 a, s32 b);
extern "C" u8 fn_801F2B7C(void* this_, s32 a, s32 b, s32 c);
extern "C" u8 fn_801F2618(void* this_, void* out, s32 a);
extern "C" void fn_802A381C(void* mgr, JGeometry::TVec3<f32>* pos, s32 room, s32 id);
extern "C" u8 fn_801D21F0(void* anim);
extern "C" void fn_801CD950(f32* value, f32 target, f32 step);
extern "C" void fn_801D1C18(void* anim);
extern void* lbl_8053AC98;
extern const f32 lbl_8053C450;
extern const f32 lbl_8053C454;
extern const f32 lbl_8053C458;
extern const f32 lbl_8053C484;

struct IcclVT2 {
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
    virtual void v10();
    virtual u8 v11();
    virtual void v12();
    virtual s32 v13();
};

static inline bool icclHitPlayer(char* p) {
    JGeometry::TVec2<f32> dir(lbl_8053C470, lbl_8053C470);
    JGeometry::TVec2<f32> off(*(f32*)(p + 0xc), *(f32*)(p + 0x10) - *(f32*)(p + 0x14));
    JGeometry::TBox2<f32> box(*(JGeometry::TVec2<f32>*)(p + 0x70), *(JGeometry::TVec2<f32>*)(p + 0x78));
    box.addPos(off);
    s32 pl;
    if (fn_8023AA18(&box, *(s32*)(p + 4), &dir) >= 0) {
        return true;
    }
    pl = fn_8023AE34(&box, *(s32*)(p + 4), &dir);
    if (pl >= 0) {
        fn_801CC820(pl, 0);
        return true;
    }
    pl = fn_8023AC74(&box, *(s32*)(p + 4), &dir);
    if (pl >= 0) {
        JGeometry::TVec3<f32> out;
        fn_801CC538(pl, &dir, &out, 0);
        return true;
    }
    pl = fn_8023AD54(&box, *(s32*)(p + 4), &dir);
    if (pl >= 0) {
        fn_801CC640(pl, 0, 0);
        return true;
    }
    return false;
}

static inline bool icclTouchPlayer(char* p) {
    JGeometry::TVec2<f32> dir;
    JGeometry::TBox2<f32> box(*(JGeometry::TVec2<f32>*)(p + 0x60), *(JGeometry::TVec2<f32>*)(p + 0x68));
    box.i.x += *(f32*)(p + 0xc);
    box.i.y += *(f32*)(p + 0x10);
    box.f.x += *(f32*)(p + 0xc);
    box.f.y += *(f32*)(p + 0x10);
    u8 r = fn_8023AB94(&box, *(s32*)(p + 4), &dir) >= 0;
    return r;
}

extern "C" void fn_8010B8B0(char* p) {
    v03__5ActorFv(p);
    switch (*(s32*)(p + 0x230)) {
    case 0:
        if (fn_8010B284(p)) {
            fn_8010B40C(p, 1);
        } else if (fn_801F285C(p, 0, 0, 1, -1) >= 0) {
            fn_8010B40C(p, 1);
        } else if (icclHitPlayer(p)) {
            fn_8010B40C(p, 1);
        } else if (icclTouchPlayer(p)) {
            fn_8010B40C(p, 2);
        }
        break;
    case 1: {
        *(f32*)(p + 0x23c) = *(f32*)(p + 0x23c) + lbl_8053C450;
        f32 t = *(f32*)(p + 0x23c);
        *(f32*)(p + 0x10) = lbl_8053C454 * (lbl_8053C458 * (t * t)) + *(f32*)(p + 0x28);
        u8 buf[0xc];
        if (fn_801F2B7C(p, *(s32*)(p + 0x114), -1, 0x18)) {
            fn_8010B40C(p, 3);
        } else if (fn_801F2618(p, buf, 0)) {
            JGeometry::TVec3<f32> pos = *(JGeometry::TVec3<f32>*)(p + 0xc);
            pos.y = pos.y + lbl_8053C460;
            u16 attr = fn_80226850(&pos, *(s32*)(p + 4));
            if (attr >= 0x3f0 || (attr >= 0x250 && attr <= 0x26f) || attr == 0x3ed) {
                fn_802A381C(lbl_8053AC98, &pos, *(s32*)(p + 4), 0x34);
            }
            fn_8010B40C(p, 3);
        } else if ((*(s32*)(p + 0x234))++, *(s32*)(p + 0x234) >= 0x1e) {
            if (fn_801F285C(p, 0, 0, 1, -1) >= 0) {
                fn_8010B40C(p, 3);
            } else if (icclHitPlayer(p)) {
                fn_8010B40C(p, 3);
            } else if (icclTouchPlayer(p)) {
                fn_8010B40C(p, 2);
            }
        }
        break;
    }
    case 2:
        fn_8010B40C(p, 4);
        break;
    case 3:
        if (fn_801D21F0(p + 0x244)) {
            fn_8010B40C(p, 4);
        }
        break;
    case 4:
        (*(s32*)(p + 0x238))++;
        if (*(s32*)(p + 0x238) > 300) {
            fn_8010B40C(p, 5);
        }
        break;
    case 5:
        if (((IcclVT2*)p)->v13() <= 0 || ((IcclVT2*)p)->v11()) {
            *(u8*)(p + 0x11d) = 1;
            fn_801CD950((f32*)(p + 0x240), lbl_8053C478, lbl_8053C484);
            *(f32*)(p + 0x10) = *(f32*)(p + 0x28) - lbl_8053C47C * (lbl_8053C478 - *(f32*)(p + 0x240));
            if (*(f32*)(p + 0x240) >= lbl_8053C478) {
                fn_8010B40C(p, 0);
            }
        }
        break;
    }
    f32 sc = *(f32*)(p + 0x240);
    *(f32*)(p + 0x54) = sc;
    *(f32*)(p + 0x58) = sc;
    *(f32*)(p + 0x5c) = sc;
    fn_801D1C18(p + 0x244);
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
