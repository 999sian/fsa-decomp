// TU 0x8020fe50-0x80210630 — Actor 'IBBM' (Expanding Ice/Energy Beam Obstacle).
#include "types.h"
#include "JSystem/JGeometry.h"

extern "C" {
void fn_801CDD58();
void fn_801CE120();
void fn_801CE4BC();
void fn_801CE4E4();
void fn_801CE4E8();
void fn_801CE594();
void fn_801CE694();
void fn_801CE914();
void fn_801CE918();
void fn_801CE91C();
void fn_801CE920();
void fn_801CE924();
void fn_801CE928();
void fn_801CE98C();
void fn_801CECEC();
void fn_801D0ECC();
void fn_80210898();
void fn_802108BC();
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
void* fn_80210314(void* this_, s16 freeFlag);
void fn_802101C0(void* this_);
void fn_8020FE50(void* this_);
s32 fn_8020FF4C(void* this_);
void fn_80210014(void* this_);
void fn_8020FED4(void* this_);
}
void* lbl_804A6100[] = {
    0,
    0,
    (void*)fn_80210314,
    (void*)fn_802101C0,
    (void*)v02__5ActorFv,
    (void*)fn_801CDD58,
    (void*)v04__5ActorFv,
    (void*)v05__5ActorFv,
    (void*)fn_8020FE50,
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
    (void*)fn_80210898,
    (void*)fn_8020FF4C,
    (void*)fn_801CE98C,
    (void*)fn_801CE928,
    (void*)fn_801CE924,
    (void*)fn_801CE920,
    (void*)fn_801CE91C,
    (void*)fn_801CE918,
    (void*)fn_801CE914,
    (void*)fn_801CE694,
    (void*)fn_801CE594,
    (void*)fn_801CE4E8,
    (void*)fn_801CE4E4,
    (void*)fn_80210014,
    (void*)fn_801CE4BC,
    (void*)fn_801CE120,
    (void*)fn_802108BC,
    (void*)fn_8020FED4,
    0,
};

struct IbbmRect { f32 x0, y0, x1, y1; };

struct IbbmSub270 {
    u8 _pad00[0x24];
    void* mVtable; // +0x294 on IbbmActor
    u8 _pad28[0x10];
};

struct IbbmOtherActor {
    u8 _pad00[0x0C];
    f32 mPos[3];         // +0x00C
    u8 _pad18[0x164 - 0x18];
    u8 mHitFlag164;      // +0x164
    u8 _pad165[0x1A0 - 0x165];
    u32 mActorFourCC;    // +0x1A0
};

struct IbbmActor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ u32 mRoomId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ f32 mPosX;
    /* 0x010 */ f32 mPosY;
    /* 0x014 */ f32 mPosZ;
    /* 0x018 */ u8 _pad18[0x54 - 0x18];
    /* 0x054 */ JGeometry::TVec3<f32> mScale;
    /* 0x060 */ IbbmRect mBounds60;
    /* 0x070 */ IbbmRect mBounds70;
    /* 0x080 */ IbbmRect mBounds80;
    /* 0x090 */ u32 mSpawnParam;
    /* 0x094 */ u8 _pad94[4];
    /* 0x098 */ s32 mDirection;      // Unpacked from spawnParam & 3
    /* 0x09C */ u8 _pad9C[0xB0 - 0x9C];
    /* 0x0B0 */ s32 mCollisionMask;
    /* 0x0B4 */ u8 _padB4[0x108 - 0xB4];
    /* 0x108 */ s32 mSortPriority;
    /* 0x10C */ u8 _pad10C[0x11C - 0x10C];
    /* 0x11C */ u8 mActiveFlag;
    /* 0x11D */ u8 _pad11D[0x195 - 0x11D];
    /* 0x195 */ u8 mLayerFlag;
    /* 0x196 */ u8 _pad196[2];
    /* 0x198 */ s32 mActorHandle;
    /* 0x19C */ u8 _pad19C[0x230 - 0x19C];
    /* 0x230 */ u32 mItemFlags;
    /* 0x234 */ u8 _pad234[0x244 - 0x234];
    /* 0x244 */ s32 mCopiedPriority;
    /* 0x248 */ s32 mState;          // 0 = warmup, 1 = expanding to 3.0x, 2 = active/fading
    /* 0x24C */ s32 mStateTimer;
    /* 0x250 */ s32 mTargetId;
    /* 0x254 */ f32 mSpeedX;
    /* 0x258 */ f32 mSpeedY;
    /* 0x25C */ u8 _pad25C[0x270 - 0x25C];
    /* 0x270 */ IbbmSub270 mAnimSub;
    /* 0x2A8 */ f32 mAnimProgress;
    /* 0x2AC */ s32 mSwitchFlagId;   // Unpacked from (spawnParam >> 2) & 0x1F
    /* 0x2B0 */ s32 mSoundEffectId;  // 0x1A8 or 0x1C1
    /* 0x2B4 */ void* mEmitterHandle;
};

extern "C" {
extern void* lbl_8053AB10;
extern void* lbl_8053AED0;
void fn_80210630(void* this_, s32 a, s32 b, s32 c, s32 d);
void fn_80210A30(void* this_, IbbmRect* out);
void fn_8030C058(void* dl, IbbmRect* r);
void* fn_801F856C();
s32 fn_801F82CC(void* mgr, void* actor, u8 layer, f32 radius);
void* fn_801F666C(void* base, s32 id);
void fn_801CB538(u32 id, void* pos, u32 a, u32 b);
s32 fn_801CD950(f32* value, f32 target, f32 step);
void fn_80210990(void* this_, s32 dir, IbbmRect* out);
u8 fn_80210A6C(void* this_);
void fn_80341CB0(u32 room, void* pos);
void* fn_802D6A9C(void);
void fn_802D8050(void* mgr, s32 a, s32 b, s32 c);
void detach__5ActorFv(void* this_);
f32 fn_80210AF8(s32 dir);
f32 fn_80210B34(s32 dir);
void fn_8013CB44(void* h, JGeometry::TVec3<f32>* pos, u32 a, u32 b, u32 c);
void fn_801D0ED0(void* this_);
void fn_8043D67C(void* mgr, s32 id, s32 a, s32 b);
void fn_801F0E34(void* this_, s32 p1, s32 p2);
s32 fn_8013CC50(u32 id, void* pos, s32 kind, f32 scale, s32 a, s32 b, s32 c, s32 d, s32 e);

// IBBM draw (vtable slot 6)
void fn_8020FE50(void* this_) {
    IbbmActor* p = (IbbmActor*)this_;
    if (p->mScale.isZero() == false) {
        s32 frame = 0;
        if (p->mState == 2) {
            frame = (s32)p->mAnimProgress;
        }
        fn_80210630(this_, 0, 0, 0, frame);
    }
}

void fn_8020FED4(void* this_) {
    IbbmActor* p = (IbbmActor*)this_;
    IbbmRect r;
    fn_80210A30(this_, &r);
    r.x0 = r.x0 + p->mPosX;
    r.y0 = r.y0 + p->mPosY;
    r.x1 = r.x1 + p->mPosX;
    r.y1 = r.y1 + p->mPosY;
    fn_8030C058(*(void**)((char*)lbl_8053AB10 + 0x24), &r);
}

s32 fn_8020FF4C(void* this_) {
    IbbmActor* p = (IbbmActor*)this_;
    if (p->mBounds60.x1 - p->mBounds60.x0 > 0.0f && p->mBounds60.y1 - p->mBounds60.y0 > 0.0f) {
        s32 id = fn_801F82CC(fn_801F856C(), this_, p->mLayerFlag, 32.0f);
        if (id >= 0 && id != p->mActorHandle) {
            IbbmOtherActor* other = (IbbmOtherActor*)fn_801F666C(fn_801F856C(), id);
            if (other != 0) {
                if (other->mActorFourCC == 'SWBM') {
                    fn_801CB538(p->mRoomId, other->mPos, 0, 0);
                }
                other->mHitFlag164 = 1;
            }
        }
    }
    return 0;
}

// IBBM state update
void fn_80210014(void* this_) {
    IbbmActor* p = (IbbmActor*)this_;
    switch (p->mState) {
    case 0:
        if (p->mStateTimer >= 0x3c) {
            p->mStateTimer = 0;
            p->mState = 1;
        }
        break;
    case 1:
        if (3.0f != p->mScale.x) {
            fn_801CD950(&p->mScale.x, 3.0f, 0.004f);
            p->mScale.y = p->mScale.x;
            p->mScale.z = p->mScale.x;
            fn_80210990(this_, p->mDirection, &p->mBounds60);
            p->mBounds70 = p->mBounds60;
        } else {
            p->mStateTimer = 0;
            p->mState = 2;
        }
        break;
    case 2:
        if (fn_80210A6C(this_)) {
            fn_80341CB0(p->mRoomId, &p->mPosX);
            s32 flag = p->mSwitchFlagId;
            if (flag != 0) {
                fn_802D8050(fn_802D6A9C(), flag, 1, 0xff);
            }
            detach__5ActorFv(this_);
        }
        break;
    }
    if (p->mActiveFlag) {
        f32 y = p->mScale.y * fn_80210AF8(p->mDirection) + p->mPosY;
        f32 x = p->mScale.x * fn_80210B34(p->mDirection) + p->mPosX;
        JGeometry::TVec3<f32> pos(x, y, 0.0f);
        fn_8013CB44(p->mEmitterHandle, &pos, 0, 2, 1);
        fn_801F0E34(this_, 0x50026, 0);
    }
}

// IBBM init (vtable slot 1)
void fn_802101C0(void* this_) {
    IbbmActor* p = (IbbmActor*)this_;
    fn_801D0ED0(this_);
    p->mDirection = p->mSpawnParam & 3;
    p->mSwitchFlagId = (p->mSpawnParam >> 2) & 0x1f;
    s32 se = 0x1a8;
    if ((p->mSpawnParam >> 7) & 1) {
        se = 0x1c1;
    }
    p->mSoundEffectId = se;
    fn_80210990(this_, p->mDirection, &p->mBounds60);
    p->mBounds80.x0 = 1.0f;
    p->mBounds80.y0 = 1.0f;
    p->mBounds80.x1 = -1.0f;
    p->mBounds80.y1 = -1.0f;
    p->mCollisionMask = 0x40004;
    p->mItemFlags |= 0x380;
    p->mSortPriority = 1000;
    p->mCopiedPriority = p->mSortPriority;
    p->mState = 0;
    p->mStateTimer = 0;
    p->mTargetId = -1;
    p->mSpeedX = 0.0f;
    p->mSpeedY = 0.0f;
    fn_8043D67C(lbl_8053AED0, p->mSoundEffectId, 0, 0);
    f32 y = p->mScale.y * fn_80210AF8(p->mDirection) + p->mPosY;
    f32 x = p->mScale.x * fn_80210B34(p->mDirection) + p->mPosX;
    JGeometry::TVec3<f32> pos(x, y, 0.0f);
    p->mEmitterHandle = (void*)fn_8013CC50(p->mRoomId, &pos, 0x260, 1.0f, 0, 2, 0, 0, 1);
}
}

extern "C" void* fn_801EE434(void* handle);
extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A6100[];
extern void* lbl_804A61C8[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

extern "C" void* fn_80210314(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        IbbmActor* p = (IbbmActor*)this_;
        p->mVtable = lbl_804A6100;
        fn_801EE434(p->mEmitterHandle);
        if (this_ != 0) {
            p->mVtable = lbl_804A61C8;
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

extern "C" void* fn_80210AB4(void* this_);

extern "C" void* fn_802103C0(IbbmActor* this_) {
    fn_80210AB4(this_);
    this_->mVtable = lbl_804A6100;
    this_->mSwitchFlagId = 0;
    this_->mSoundEffectId = 0;
    this_->mEmitterHandle = 0;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
