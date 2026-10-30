// TU 0x802df458-0x802dfce8 — Actor 'YASI' (Carryable / Breakable Pot/Jar Object).
#include "Game/esd/types.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern void* lbl_804A9968[];

#undef ALIGN_NEXT
#undef ALIGN_PREV
#undef ARRAY_SIZE
#undef ASM
#undef ATTRIBUTE_ALIGN
#undef IS_ALIGNED
#undef IS_NOT_ALIGNED
#undef MACROS_H
#undef MAX
#undef MIN
#undef NULL
#define NULL 0
#ifndef unknown
#define unknown jsys_unknown
#endif
#include "JSystem/JGeometry/Vec.h"
typedef JGeometry::TVec3<f32> YasiVec;

struct YasiActor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ s32 mRoomId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ YasiVec mPos;
    /* 0x018 */ u8 _pad18[0x3C - 0x18];
    /* 0x03C */ YasiVec mVel;
    /* 0x048 */ u8 _pad48[0x60 - 0x48];
    /* 0x060 */ f32 mBounds60[4];
    /* 0x070 */ u8 _pad70[0x80 - 0x70];
    /* 0x080 */ f32 mBounds80[4];
    /* 0x090 */ u8 _pad90[0xC4 - 0x90];
    /* 0x0C4 */ u8 mIsCarried;
    /* 0x0C5 */ u8 _padC5[3];
    /* 0x0C8 */ s32 mCarrierPlayer;
    /* 0x0CC */ u8 _padCC[0x114 - 0xCC];
    /* 0x114 */ s32 mHitType;
    /* 0x118 */ u32 mField118;
    /* 0x11C */ u8 mActiveFlag;
    /* 0x11D */ u8 _pad11D[0x230 - 0x11D];
    /* 0x230 */ s32 mState;
    /* 0x234 */ u8 mDrawAlpha;
};

extern "C" void* fn_802DF458(YasiActor* this_, s16 freeFlag) {
    if (this_ != 0) {
        this_->mVtable = lbl_804A9968;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

struct ActorSlot9 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual void slot9();
};

extern "C" void fn_802DF4B8(void* this_) {
    ((ActorSlot9*)this_)->slot9();
}

extern "C" s32 fn_801F132C(void* this_, u32 param2, u32 param3, void* statePtr);

extern "C" s32 Yasi_CanBeActiveHere(YasiActor* this_, u32 param2, u32 param3) {
    return fn_801F132C(this_, param2, param3, &this_->mState);
}

extern const f32 lbl_80541168;
extern const f32 lbl_8054116C;
extern const f32 lbl_80541170;
extern "C" void* fn_801F856C();
extern "C" s32 Actor_CreateByID(void* base, u32 fourCC, u32 owner, void* posPtr, u32 param, s32 p6, s32 p7);
extern "C" u16 fn_8022461C(YasiVec* pos, u32 room);
extern "C" void fn_8013CC50(u32 room, YasiVec* pos, f32 scale, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_801F0E34(void* this_, s32 p1, s32 p2);
extern "C" u8 fn_802DE9A0();
extern "C" u8 fn_802DEB58();

// YASI break handler: spawns 'KMRI' smoke on GBA and tile-dependent splash/shatter effects
extern "C" void fn_802DF508(YasiActor* p) {
    if (p->mRoomId >= 8) {
        YasiVec pos(p->mPos);
        pos.z = lbl_80541168;
        Actor_CreateByID(fn_801F856C(), 'KMRI', p->mRoomId, &pos, 0, -1, -1);
    }
    if (fn_8022461C(&p->mPos, p->mRoomId) == 0xd || fn_8022461C(&p->mPos, p->mRoomId) == 0x39) {
        fn_8013CC50(p->mRoomId, &p->mPos, lbl_8054116C, 0x3d0, 0, 1, 0, 0, 1);
        fn_801F0E34(p, 0x30022, 0);
    } else if (fn_8022461C(&p->mPos, p->mRoomId) == 0xe) {
        if (fn_802DE9A0()) {
            fn_8013CC50(p->mRoomId, &p->mPos, lbl_8054116C, 0x2a9, -1, 1, 0, 0, 1);
            fn_8013CC50(p->mRoomId, &p->mPos, lbl_8054116C, 0x2aa, 0, 0, 0, 0, 1);
            fn_801F0E34(p, 0x5005f, 0);
        } else if (fn_802DEB58()) {
            fn_8013CC50(p->mRoomId, &p->mPos, lbl_8054116C, 0x45e, -1, 1, 0, 0, 1);
            fn_8013CC50(p->mRoomId, &p->mPos, lbl_8054116C, 0x45f, 0, 0, 0, 0, 1);
            fn_801F0E34(p, 0x5003f, 0);
        }
    } else {
        fn_8013CC50(p->mRoomId, &p->mPos, lbl_8054116C, 0x8c, 1, 0, 0, 0, 1);
        fn_8013CC50(p->mRoomId, &p->mPos, lbl_8054116C, 0x7a, 1, 0, 0, 0, 1);
        fn_801F0E34(p, 0x30003, 0);
    }
    p->mActiveFlag = 0;
}

struct YasiDrawKey {
    s32 a, b;
    YasiDrawKey() { a = -1; b = -1; }
};
struct YasiDrawParam {
    u8 map[16];      // 0x00
    YasiDrawKey key; // 0x10
    s32 c;           // 0x18
    u8 palette;      // 0x1c
    u8 color;        // 0x1d
    u8 f1e, f1f, f20, f21, f22, f23, f24, f25, f26;
    s32 blend;       // 0x28
    u8 f2c, f2d, f2e;
    s32 g;           // 0x30
    s32 h;           // 0x34
    s32 i;           // 0x38

    YasiDrawParam() {
        for (u8 n = 0; n < 16; n++) {
            map[n] = n;
        }
        key.a = -1;
        key.b = 0;
        c = 0;
        palette = 0;
        color = 0;
        f1e = 0;
        f1f = 1;
        f20 = 1;
        f21 = 0;
        f22 = 0;
        f23 = 0;
        f24 = 0;
        f25 = 0;
        f26 = 1;
        blend = 3;
        f2c = 1;
        f2d = 0;
        f2e = 0;
        g = -1;
        h = 0;
        i = 2;
    }
};
extern const char lbl_8046E998[];
extern "C" s32 fn_8023CB24(s32 holder);
extern "C" u8 fn_8023CA88(s32 holder);
extern "C" void fn_801F02BC(void* this_, const char* name, s32 id, YasiDrawParam* param, s32 a, s32 b, s32 c, f32 s0, f32 s1);

// YASI draw (vtable slot 6)
extern "C" void fn_802DF754(YasiActor* p) {
    YasiDrawParam param;
    ((u8*)&param.key.a)[3] = p->mDrawAlpha;
    if (p->mIsCarried != 0) {
        param.f20 = 0;
        param.color = fn_8023CB24(p->mCarrierPlayer) + 1;
        param.palette = fn_8023CA88(p->mCarrierPlayer);
    }
    fn_801F02BC(p, lbl_8046E998, 0x1ae, &param, 7, 0, 1, lbl_8054116C, lbl_8054116C);
}

struct YasiVT {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6();
    virtual void breakUp();
};
extern char* lbl_8053AAF8;
extern void* lbl_8053AC98;
extern "C" YasiVec* fn_8023E7B0(s32 holder);
extern "C" s32 fn_8023DE58(s32 holder);
extern "C" u8 fn_8023BCD4(s32 holder);
extern "C" u8 fn_801F2618(void* this_, s32 a, s32 b);
extern "C" u16 fn_80226850(YasiVec* pos, u32 room);
extern "C" void fn_802A381C(void* mgr, YasiVec* pos, u32 room, s32 id);
extern "C" u8 fn_801F2B7C(void* this_, s32 a, s32 holder, s32 b);
extern "C" u8 fn_801F2B20(void* this_, s32 a);

// YASI update (vtable slot 3)
extern "C" void fn_802DF8C8(YasiActor* p) {
    p->mDrawAlpha = 0xff;
    if (p->mIsCarried != 0) {
        YasiVec* h = fn_8023E7B0(p->mCarrierPlayer);
        p->mPos.x = h->x;
        p->mPos.y = h->y;
        p->mPos.z = h->z;
        p->mRoomId = fn_8023DE58(p->mCarrierPlayer);
        p->mDrawAlpha = fn_8023BCD4(p->mCarrierPlayer);
        return;
    }
    p->mVel.z += lbl_80541170;
    p->mPos += p->mVel;
    s32 hit = p->mHitType;
    if (*(u8*)(lbl_8053AAF8 + 0x7f) != 0) {
        hit = 0;
    }
    if (p->mPos.z < lbl_80541168 || fn_801F2618(p, 0, 0)) {
        if (p->mPos.z < lbl_80541168) {
            if (fn_80226850(&p->mPos, p->mRoomId) == 0x90) {
                fn_802A381C(lbl_8053AC98, &p->mPos, p->mRoomId, 0x91);
            } else if (fn_80226850(&p->mPos, p->mRoomId) == 0x91) {
                fn_802A381C(lbl_8053AC98, &p->mPos, p->mRoomId, 0x92);
            }
        }
        ((YasiVT*)p)->breakUp();
    } else if (fn_801F2B7C(p, hit, p->mCarrierPlayer, 4) || fn_801F2B20(p, 0)) {
        ((YasiVT*)p)->breakUp();
    }
}

extern const f32 lbl_80541174;
extern const f32 lbl_80541178;
extern const f32 lbl_8054117C;
extern const f32 lbl_80541180;

// YASI init (vtable slot 1)
extern "C" void fn_802DFA80(YasiActor* p) {
    p->mBounds60[0] = lbl_80541174;
    p->mBounds60[1] = lbl_80541174;
    p->mBounds60[2] = lbl_80541178;
    p->mBounds60[3] = lbl_80541178;
    p->mBounds80[0] = lbl_8054117C;
    p->mBounds80[1] = lbl_8054117C;
    p->mBounds80[2] = lbl_80541180;
    p->mBounds80[3] = lbl_80541180;
    p->mState = 0;
    p->mDrawAlpha = 0xff;
}

#undef ALIGN_NEXT
#undef ALIGN_PREV
#undef ARRAY_SIZE
#undef ASM
#undef ATTRIBUTE_ALIGN
#undef IS_ALIGNED
#undef IS_NOT_ALIGNED
#undef MACROS_H
#undef MAX
#undef MIN
#undef NULL
#define NULL 0
#define unknown jsys_unknown
#include "JSystem/JAudio/JASFakeMatchFSA.h"
