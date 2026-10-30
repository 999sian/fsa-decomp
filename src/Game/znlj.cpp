// TU 0x802205e0-0x80220f54 — Actor 'ZNLJ' (Jumping Enemy derived from Base_802218C8).
#include "types.h"

extern "C" {
void fn_801CDD58();
void fn_801CE120();
void fn_801CE4BC();
void fn_801CE4E4();
void fn_801CE594();
void fn_801CE694();
void fn_801CE914();
void fn_801CE918();
void fn_801CE920();
void fn_801CE928();
void fn_801CE98C();
void fn_801CEB78();
void fn_801CECEC();
void fn_801D0ECC();
void fn_80220F54();
void fn_80221114();
void fn_80221158();
void fn_80221160();
void fn_80221184();
void fn_80221210();
void v02__5ActorFv();
void v04__5ActorFv();
void v05__5ActorFv();
void v07__5ActorFv();
void v08__5ActorFv();
void v09__5ActorFv();
void v10__5ActorFUlUl();
void v11__5ActorFv();
void v12__5ActorFv();
void v13__5ActorFv();
void v14__5ActorFv();
void v15__5ActorFv();
void v16__5ActorFv();
void v17__5ActorFiPf();
void v18__5ActorFiPf();
void* fn_802205E0(void* this_, s16 freeFlag);
void fn_80220BD0(void* this_);
void fn_80220680(void* this_);
void fn_802206FC(void* this_);
}
void* lbl_804A68D0[] = {
    0,
    0,
    (void*)fn_802205E0,
    (void*)fn_80220BD0,
    (void*)v02__5ActorFv,
    (void*)fn_801CDD58,
    (void*)v04__5ActorFv,
    (void*)v05__5ActorFv,
    (void*)fn_80220F54,
    (void*)v07__5ActorFv,
    (void*)v08__5ActorFv,
    (void*)v09__5ActorFv,
    (void*)v10__5ActorFUlUl,
    (void*)v11__5ActorFv,
    (void*)v12__5ActorFv,
    (void*)v13__5ActorFv,
    (void*)v14__5ActorFv,
    (void*)v15__5ActorFv,
    (void*)v16__5ActorFv,
    (void*)v17__5ActorFiPf,
    (void*)v18__5ActorFiPf,
    (void*)fn_801D0ECC,
    (void*)fn_801CECEC,
    (void*)fn_801CEB78,
    (void*)fn_80221158,
    (void*)fn_801CE98C,
    (void*)fn_801CE928,
    (void*)fn_80221184,
    (void*)fn_801CE920,
    (void*)fn_80221160,
    (void*)fn_801CE918,
    (void*)fn_801CE914,
    (void*)fn_801CE694,
    (void*)fn_801CE594,
    (void*)fn_80220680,
    (void*)fn_801CE4E4,
    (void*)fn_802206FC,
    (void*)fn_801CE4BC,
    (void*)fn_801CE120,
    (void*)fn_80221210,
    (void*)fn_80221114,
};

extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A68D0[];
extern void* lbl_804A6A00[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

#include "JSystem/JMath/JMath.h"

struct ZnljRect { f32 x0, y0, x1, y1; };
struct ZnljGame { u8 pad[0x7e]; u8 mFlag7E; };

struct ZnljSub270 {
    u8 _pad00[0x24];
    void* mVtable; // +0x294 on ZnljActor
    u8 _pad28[0x10];
};

struct ZnljActor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ u32 mRoomId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ f32 mPosX;
    /* 0x010 */ f32 mPosY;
    /* 0x014 */ f32 mPosZ;
    /* 0x018 */ u8 _pad18[0x3C - 0x18];
    /* 0x03C */ f32 mVelX;
    /* 0x040 */ f32 mVelY;
    /* 0x044 */ f32 mVelZ;
    /* 0x048 */ u8 _pad48[0x60 - 0x48];
    /* 0x060 */ ZnljRect mBounds60;
    /* 0x070 */ ZnljRect mBounds70;
    /* 0x080 */ ZnljRect mBounds80;
    /* 0x090 */ u32 mSpawnParam;
    /* 0x094 */ u8 _pad94[4];
    /* 0x098 */ s32 mFacingDir;
    /* 0x09C */ u8 _pad9C[0x230 - 0x9C];
    /* 0x230 */ u32 mItemFlags;
    /* 0x234 */ u8 _pad234[0x248 - 0x234];
    /* 0x248 */ s32 mState;
    /* 0x24C */ s32 mStateTimer;
    /* 0x250 */ s32 mStateDuration;
    /* 0x254 */ f32 mSpeedX;
    /* 0x258 */ f32 mSpeedY;
    /* 0x25C */ u8 _pad25C[0x270 - 0x25C];
    /* 0x270 */ ZnljSub270 mAnimSub;
    /* 0x2A8 */ u8 _pad2A8[8];
    /* 0x2B0 */ f32 mTargetX;
    /* 0x2B4 */ f32 mTargetY;
    /* 0x2B8 */ s32 mJumpAxis;     // 0..1 = X jump, 2..3 = Y jump (from spawnParam & 3)
    /* 0x2BC */ s32 mJumpCount;    // Completed jump hops
    /* 0x2C0 */ s32 mMaxJumpCount; // Randomized hop limit (3..4)
};

extern "C" void* fn_802205E0(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        ZnljActor* p = (ZnljActor*)this_;
        p->mVtable = lbl_804A68D0;
        if (this_ != 0) {
            p->mVtable = lbl_804A6A00;
            if (this_ != 0) {
                p->mVtable = lbl_804A4808;
                if (&p->mAnimSub != 0) {
                    if (&p->mAnimSub.mVtable != 0) {
                        p->mAnimSub.mVtable = lbl_8049CC34;
                    }
                }
                __dt__5ActorFv(this_, 0);
            }
        }
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

struct ZnljVt {
    virtual void s00(); virtual void s01(); virtual void s02(); virtual void s03();
    virtual void s04(); virtual void s05(); virtual void s06(); virtual void s07();
    virtual void s08(); virtual void s09(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27();
    virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31();
};

extern "C" {
extern f32 lbl_8053EFB8;
extern const f32 lbl_8053FE70;
extern ZnljGame* lbl_8053AAF8;
void fn_80221250(void* this_);
void fn_80221408(void* this_);
void fn_80221334(void* this_);
void fn_802212AC(void* this_);
void fn_8022149C(void* this_, s32 a);
void fn_802217C8(void* this_);
void* fn_802218C8(void* this_);
void fn_80221670(void* this_);
s32 fn_801D05F8(void* this_, void* pos, f32 r);
void fn_801D22DC(void* anim, s32 idx, s32 a, s32 b);
void fn_801F0E34(void* this_, s32 p1, s32 p2);
void fn_801F3604(void* this_);
void detach__5ActorFv(void* this_);
s32 fn_801CD664(s32 range);
s32 ClassifyBamAngleToQuadrant(u16 angle);
void fn_8022089C(void* this_, s32 state);

// ZNLJ vtable slot 32: physics velocity update
void fn_80220680(void* this_) {
    ZnljActor* p = (ZnljActor*)this_;
    switch (p->mState) {
    case 2:
        fn_80221250(this_);
        break;
    case 4:
    case 6:
        p->mVelZ += lbl_8053EFB8;
        break;
    default:
        p->mVelX = 0.0f;
        p->mVelY = 0.0f;
        ((ZnljVt*)this_)->s31();
        break;
    }
}

// ZNLJ vtable slot 34: main state machine
void fn_802206FC(void* this_) {
    ZnljActor* p = (ZnljActor*)this_;
    switch ((u32)p->mState) {
    case 0:
        fn_80221408(this_);
        break;
    case 1:
        fn_80221334(this_);
        break;
    case 2:
        fn_802212AC(this_);
        break;
    case 3:
        if (p->mItemFlags & 0x4000) {
            if (p->mPosZ <= 0.0f) {
                fn_8022089C(this_, 4);
            }
        } else if (fn_801D05F8(this_, &p->mPosX, 48.0f) >= 0) {
            p->mItemFlags |= 0x4000;
            ZnljRect* r = &p->mBounds60;
            r->x0 = 1.0f;
            r->y0 = 1.0f;
            r->x1 = -1.0f;
            r->y1 = -1.0f;
            p->mBounds70 = *r;
            if (p->mPosZ <= 0.0f) {
                fn_8022089C(this_, 4);
            }
        } else if (p->mPosZ <= 0.0f) {
            p->mVelZ = lbl_8053FE70;
        }
        break;
    case 4:
        if (p->mPosZ <= 0.0f) {
            p->mJumpCount++;
            fn_8022089C(this_, 5);
        }
        break;
    case 5:
        if (p->mStateTimer >= p->mStateDuration) {
            if (p->mJumpCount >= p->mMaxJumpCount) {
                fn_8022149C(this_, 1);
            } else {
                fn_8022089C(this_, 3);
            }
        }
        break;
    case 6:
        if (p->mStateTimer >= 0x78) {
            detach__5ActorFv(this_);
        }
        break;
    }
}

// ZNLJ state transition handler
void fn_8022089C(void* this_, s32 state) {
    ZnljActor* p = (ZnljActor*)this_;
    switch (state) {
    case 3: {
        ZnljRect* r = &p->mBounds60;
        r->x0 = -8.0f;
        r->y0 = -8.0f;
        r->x1 = 8.0f;
        r->y1 = 8.0f;
        ZnljRect* r2 = &p->mBounds80;
        r2->x0 = -8.0f;
        r2->y0 = -8.0f;
        r2->x1 = 8.0f;
        r2->y1 = 8.0f;
        break;
    }
    case 4: {
        p->mItemFlags &= ~0x4000;
        ZnljRect* r = &p->mBounds60;
        r->x0 = 1.0f;
        r->y0 = 1.0f;
        r->x1 = -1.0f;
        r->y1 = -1.0f;
        p->mBounds70 = *r;
        ZnljRect* r2 = &p->mBounds80;
        r2->x0 = 1.0f;
        r2->y0 = 1.0f;
        r2->x1 = -1.0f;
        r2->y1 = -1.0f;
        static f32 sJumpVel = 0.5f * (45.0f * -lbl_8053EFB8);
        p->mVelZ = sJumpVel;
        switch (p->mJumpAxis) {
        case 0:
        case 1:
            p->mVelX = 2.8444445f;
            if (p->mJumpAxis == 1) {
                p->mVelX = -p->mVelX;
            }
            if (p->mJumpCount & 1) {
                p->mVelX = -p->mVelX;
            }
            p->mVelY = 0.0f;
            break;
        case 2:
        case 3:
            p->mVelY = 2.8444445f;
            if (p->mJumpAxis == 3) {
                p->mVelY = -p->mVelY;
            }
            if (p->mJumpCount & 1) {
                p->mVelY = -p->mVelY;
            }
            p->mVelX = 0.0f;
            break;
        }
        fn_801F0E34(this_, 0x400c7, 0);
        break;
    }
    case 5: {
        ZnljRect* r = &p->mBounds60;
        r->x0 = -8.0f;
        r->y0 = -8.0f;
        r->x1 = 8.0f;
        r->y1 = 8.0f;
        ZnljRect* r2 = &p->mBounds80;
        r2->x0 = -8.0f;
        r2->y0 = -8.0f;
        r2->x1 = 8.0f;
        r2->y1 = 8.0f;
        if (lbl_8053AAF8->mFlag7E) {
            p->mStateDuration = 6;
        } else {
            p->mStateDuration = 0xc;
        }
        break;
    }
    case 6: {
        fn_801F3604(this_);
        ZnljRect* r = &p->mBounds60;
        r->x0 = 1.0f;
        r->y0 = 1.0f;
        r->x1 = -1.0f;
        r->y1 = -1.0f;
        p->mBounds70 = *r;
        ZnljRect* r2 = &p->mBounds80;
        r2->x0 = 1.0f;
        r2->y0 = 1.0f;
        r2->x1 = -1.0f;
        r2->y1 = -1.0f;
        static f32 sLandVel = 0.5f * (120.0f * -lbl_8053EFB8);
        p->mVelZ = sLandVel;
        fn_80221670(this_);
        p->mVelX = (1.0f / 120.0f) * (p->mTargetX - p->mPosX);
        p->mVelY = (1.0f / 120.0f) * (p->mTargetY - p->mPosY);
        f32 ang = JMAAtan2Radian(p->mVelX, p->mVelY);
        ang *= 10430.378f;
        p->mFacingDir = ClassifyBamAngleToQuadrant((u16)(s32)ang);
        fn_801D22DC(&p->mAnimSub, p->mFacingDir + 8, 0, 0);
        break;
    }
    }
    p->mStateTimer = 0;
    p->mState = state;
}

// ZNLJ init (vtable slot 1)
void fn_80220BD0(void* this_) {
    ZnljActor* p = (ZnljActor*)this_;
    fn_802217C8(this_);
    p->mJumpAxis = p->mSpawnParam & 3;
    p->mFacingDir = 2;
    p->mState = 3;
    p->mStateTimer = 0;
    p->mStateDuration = -1;
    p->mSpeedX = 0.0f;
    p->mSpeedY = 0.0f;
    fn_801D22DC(&p->mAnimSub, 2, 0, 0);
}

}

class Base_802218C8 {
public:
    Base_802218C8() { fn_802218C8(this); }
    ~Base_802218C8() {
        ZnljActor* p = (ZnljActor*)this;
        p->mVtable = lbl_804A6A00;
        if (this != 0) {
            p->mVtable = lbl_804A4808;
            if (&p->mAnimSub != 0) {
                if (&p->mAnimSub.mVtable != 0) {
                    p->mAnimSub.mVtable = lbl_8049CC34;
                }
            }
            __dt__5ActorFv(this, 0);
        }
    }
    u8 mBase[0x2b8];
};

class Znlj : public Base_802218C8 {
public:
    Znlj();
    s32 m2B8;
    s32 m2BC;
    s32 m2C0;
};

Znlj::Znlj() {
    *(void**)this = lbl_804A68D0;
    m2B8 = 0;
    m2BC = 0;
    m2C0 = fn_801CD664(1) + 3;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
