// TU 0x80221b44-0x802223fc — Ground-Pound Shockwave Enemy (derived from Base_802218C8).
#include "types.h"
#include "JSystem/JGeometry.h"

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
void* fn_80221B44(void* this_, s16 freeFlag);
void fn_80222124(void* this_);
void fn_80221BE4(void* this_);
void fn_80221C4C(void* this_);
void fn_80221C18(void* this_);
}
void* lbl_804A6AA8[] = {
    0,
    0,
    (void*)fn_80221B44,
    (void*)fn_80222124,
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
    (void*)fn_80221BE4,
    (void*)fn_801CE4E4,
    (void*)fn_80221C4C,
    (void*)fn_801CE4BC,
    (void*)fn_801CE120,
    (void*)fn_80221C18,
    (void*)fn_80221114,
};

struct SlamSub270 {
    u8 _pad00[0x24];
    void* mVtable; // +0x294 on SlamEnemyActor
    u8 _pad28[0x10];
};

struct SlamEnemyActor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ u32 mRoomId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ JGeometry::TVec3<f32> mPos;
    /* 0x018 */ u8 _pad18[0x44 - 0x18];
    /* 0x044 */ f32 mVelZ;
    /* 0x048 */ u8 _pad48[0x98 - 0x48];
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
    /* 0x270 */ SlamSub270 mAnimSub;
    /* 0x2A8 */ u8 _pad2A8[0x2B8 - 0x2A8];
    /* 0x2B8 */ s32 mSlamCount;
    /* 0x2BC */ u8 mShockwaveSub[0x0C];
    /* 0x2C8 */ char mSubFlag2C8;
};

extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A6AA8[];
extern void* lbl_804A6A00[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

extern "C" void* fn_80221B44(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        SlamEnemyActor* p = (SlamEnemyActor*)this_;
        p->mVtable = lbl_804A6AA8;
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

extern "C" void fn_80221250(void* this_);
extern "C" void fn_801CE4E8(void* this_);

extern "C" void fn_80221BE4(void* this_) {
    s32 state = ((SlamEnemyActor*)this_)->mState;
    if (state == 2) {
        fn_80221250(this_);
    } else {
        fn_801CE4E8(this_);
    }
}

extern "C" {
extern const f32 lbl_8053FE70;
extern void* lbl_8053AAF8;
void fn_80221210(void* this_);
void fn_800F802C(void* obj);
void fn_800F8210(void* obj, u32 id, JGeometry::TVec3<f32>* pos, s32 n);
void fn_80221408(void* this_);
void fn_80221334(void* this_);
void fn_802212AC(void* this_);
void fn_802216E8(void* this_, s32 t);
void fn_8022149C(void* this_, s32 a);
void fn_802217C8(void* this_);
void fn_801D22DC(void* anim, s32 idx, s32 a, s32 b);
u8 fn_801D21F0(void* anim);
s32 fn_8013CC50(u32 id, void* pos, s32 kind, f32 scale, s32 a, s32 b, s32 c, s32 d, s32 e);
void fn_801F0E34(void* this_, s32 p1, s32 p2);
void* fn_802D6A9C(void);
void fn_802D79E8(void* mgr, u32 a, void* b, f32 x, f32 y);
void fn_80134DE4(void* game, s32 a, void* b);
u8 fn_802258D4(JGeometry::TVec3<f32>* pos, u32 id);
u8 fn_80225614(JGeometry::TVec3<f32>* pos, u32 id);

void fn_80221C18(void* this_) {
    fn_80221210(this_);
    fn_800F802C(((SlamEnemyActor*)this_)->mShockwaveSub);
}

void fn_80221C4C(void* this_) {
    SlamEnemyActor* p = (SlamEnemyActor*)this_;
    JGeometry::TVec3<f32> tmp;
    JGeometry::TVec3<f32> pos;
    JGeometry::TVec3<f32> pos5;
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
        if (p->mStateTimer >= p->mStateDuration) {
            fn_801D22DC(&p->mAnimSub, 0x18, 0, 0);
            p->mStateTimer = 0;
            p->mState = 5;
        }
        break;
    case 4:
        fn_802216E8(this_, 0x3c);
        if (p->mPos.z <= 0.0f) {
            if (p->mItemFlags & 0x2000) {
                fn_801D22DC(&p->mAnimSub, 0x18, 0, 0);
                p->mStateTimer = 0;
                p->mState = 5;
            } else {
                p->mVelZ = lbl_8053FE70;
            }
        }
        break;
    case 5:
        if (p->mStateTimer > 1 && fn_801D21F0(&p->mAnimSub)) {
            fn_801D22DC(&p->mAnimSub, 0x19, 0, 0);
            pos5 = p->mPos;
            pos5.y -= 22.0f;
            fn_8013CC50(p->mRoomId, &pos5, 0xcb, 1.0f, 0, 1, 0, 0, 1);
            fn_8013CC50(p->mRoomId, &pos5, 0xcc, 1.0f, 0, 1, 0, 0, 1);
            fn_801F0E34(this_, 0x400c4, 0);
            p->mStateTimer = 0;
            p->mState = 6;
        }
        break;
    case 6:
        if (p->mStateTimer > 1 && fn_801D21F0(&p->mAnimSub)) {
            fn_801D22DC(&p->mAnimSub, 0x1a, 0, 0);
            p->mStateTimer = 0;
            p->mState = 7;
        }
        break;
    case 7:
        if (p->mStateTimer > 1 && fn_801D21F0(&p->mAnimSub)) {
            p->mSlamCount++;
            if (p->mSlamCount >= 3) {
                fn_801D22DC(&p->mAnimSub, p->mFacingDir, 0, 0);
                p->mStateTimer = 0;
                p->mState = 8;
            } else {
                p->mStateDuration = 0x78;
                fn_801D22DC(&p->mAnimSub, p->mFacingDir, 0, 0);
                p->mStateTimer = 0;
                p->mState = 3;
            }
        } else if (p->mStateTimer == 3) {
            pos.set(p->mPos.x, p->mPos.y, 0.0f);
            switch (p->mFacingDir) {
            case 0:
                pos.x += 12.0f;
                break;
            case 1:
                pos.x -= 12.0f;
                break;
            case 2:
                pos.y += 12.0f;
                break;
            case 3:
                pos.y -= 12.0f;
                break;
            }
            u32 id = p->mRoomId;
            tmp = pos;
            fn_800F8210(p->mShockwaveSub, id, &tmp, 2);
            fn_8013CC50(p->mRoomId, &pos, 0x23b, 1.0f, 0, 0, 0, 0, 1);
            fn_8013CC50(p->mRoomId, &pos, 0x23c, 1.0f, 0, 0, 0, 0, 1);
            fn_8013CC50(p->mRoomId, &pos, 0x23d, 5.0f, 0, 0, 0, 0, 1);
            fn_8013CC50(p->mRoomId, &pos, 0x23e, 2.0f, 0, 0, 0, 0, 1);
            fn_8013CC50(p->mRoomId, &pos, 0x23f, 2.0f, 0, 0, 0, 0, 1);
            if (fn_802258D4(&pos, p->mRoomId) || fn_80225614(&pos, p->mRoomId)) {
                fn_8013CC50(p->mRoomId, &pos, 0x3d0, 2.0f, 0, 0, 0, 0, 1);
            } else {
                fn_8013CC50(p->mRoomId, &pos, 0x3cf, 2.0f, 0, 0, 0, 0, 1);
            }
            fn_801F0E34(this_, 0x400e6, 0);
            fn_802D79E8(fn_802D6A9C(), p->mRoomId, 0, 4.0f, 0.0f);
            fn_80134DE4(lbl_8053AAF8, 1, 0);
        }
        break;
    case 8:
        if (p->mStateTimer >= 0x3c) {
            fn_8022149C(this_, 1);
        }
        break;
    }
}

void fn_80222124(void* this_) {
    SlamEnemyActor* p = (SlamEnemyActor*)this_;
    fn_802217C8(this_);
    p->mFacingDir = 2;
    p->mState = 4;
    p->mStateTimer = 0;
    p->mStateDuration = -1;
    p->mSpeedX = 0.0f;
    p->mSpeedY = 0.0f;
    fn_801D22DC(&p->mAnimSub, 2, 0, 0);
}
}

extern "C" void* fn_802218C8(void* this_);

extern "C" void* fn_80222190(SlamEnemyActor* this_) {
    fn_802218C8(this_);
    this_->mVtable = lbl_804A6AA8;
    this_->mSlamCount = 0;
    this_->mSubFlag2C8 = 0;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
