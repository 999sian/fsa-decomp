// Game TU 801D2C60-801D3320 — Intermediate Projectile Base Class (shared by ARSH, ZOSH, FBAL).
#include "types.h"
#include "Game/ItemBase.h"
#include "JSystem/JGeometry/Vec.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A48B0[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];
extern "C" void* fn_801D0F40(void* this_);

struct ProjectileSub270 {
    u8 _pad00[0x10];
    u32 mAnimOffset; // +0x280 on ProjectileBaseActor
    u8 _pad14[0x10];
    void* mVtable;   // +0x294 on ProjectileBaseActor
    u8 _pad28[0x10];
};

struct ProjectileBaseActor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ s32 mRoomId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ JGeometry::TVec3<f32> mPos;
    /* 0x018 */ u8 _pad18[0x3C - 0x18];
    /* 0x03C */ JGeometry::TVec3<f32> mVel;
    /* 0x048 */ u8 _pad48[0x60 - 0x48];
    /* 0x060 */ f32 mBounds60[4];
    /* 0x070 */ f32 mBounds70[4];
    /* 0x080 */ f32 mBounds80[4];
    /* 0x090 */ u8 _pad90[8];
    /* 0x098 */ s32 mDirection;
    /* 0x09C */ u8 _pad9C[0xB0 - 0x9C];
    /* 0x0B0 */ u32 mCollisionMask;
    /* 0x0B4 */ u8 _padB4[0x108 - 0xB4];
    /* 0x108 */ u32 mSortPriority;
    /* 0x10C */ u8 _pad10C[8];
    /* 0x114 */ u32 mHitType;
    /* 0x118 */ u32 mField118;
    /* 0x11C */ u8 mActiveFlag;
    /* 0x11D */ u8 _pad11D[0x194 - 0x11D];
    /* 0x194 */ u8 mFlag194;
    /* 0x195 */ u8 _pad195[0x230 - 0x195];
    /* 0x230 */ u32 mItemFlags;
    /* 0x234 */ u8 _pad234[0x244 - 0x234];
    /* 0x244 */ u32 mCopiedPriority;
    /* 0x248 */ u8 _pad248[0x270 - 0x248];
    /* 0x270 */ ProjectileSub270 mAnimSub;
    /* 0x2A8 */ u8 mImpactTimer;
};

extern "C" void* __dt__14Fn801D30B8BaseFv(ProjectileBaseActor* this_, s16 freeFlag) {
    if (this_ != 0) {
        this_->mVtable = lbl_804A48B0;
        if (this_ != 0) {
            this_->mVtable = lbl_804A4808;
            if (&this_->mAnimSub != 0) {
                if (&this_->mAnimSub.mVtable != 0) {
                    this_->mAnimSub.mVtable = lbl_8049CC34;
                }
            }
            __dt__5ActorFv(this_, 0);
        }
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" s32 fn_801CF0F4(void* this_);
extern "C" void fn_801F06F0(void* actor, void* res, u32 id, DrawRec* rec, s32 p5, f32 a, f32 b);
extern "C" void fn_801F0E34(void* this_, u32 id, u32 c);
extern "C" void fn_801CB538(u32 id, void* pos, u32 a, u32 b);
extern "C" u8* fn_802D6A9C(void);
extern "C" u8 fn_801F2A10(void* this_, s32 a, s32 b, u32 c, u32 d);
extern "C" u8 fn_801F2B7C(void* this_, u32 a, s32 b, u32 c);
extern "C" void fn_801CE4BC(void* this_);
extern "C" void fn_801D0ED0(void* this_);
extern "C" void fn_801D2608(void* obj, void* tbl, u32 n);
extern "C" void fn_801D22DC(void* obj, u32 a, u32 b, u32 c);
extern "C" void fn_801D1D60(void* obj);
extern u8 lbl_80469474[];
extern u8 lbl_8053A130[8];
extern const f32 lbl_8053F068;
extern const f32 lbl_8053F06C;
extern const f32 lbl_8053F070;
extern const f32 lbl_8053F074;
extern const f32 lbl_8053F078;

extern "C" void fn_801D2CF0(ProjectileBaseActor* this_, const JGeometry::TVec2<f32>& vel) {
    this_->mVel.x = vel.x;
    this_->mVel.y = vel.y;
    this_->mVel.z = lbl_8053F068;
    this_->mDirection = fn_801CF0F4(this_);
}

extern "C" void fn_801D2D38(ProjectileBaseActor* this_) {
    DrawRec rec;
    rec.w30 = 0xc;
    rec.b1d = 1;
    fn_801F06F0(this_, lbl_80469474, this_->mAnimSub.mAnimOffset + 0xd5, &rec, -1, lbl_8053F06C, lbl_8053F06C);
}

extern "C" void fn_801D2E70(ProjectileBaseActor* this_) {
    if (this_->mImpactTimer != 0) {
        this_->mImpactTimer--;
        if (this_->mImpactTimer == 0) {
            fn_801F0E34(this_, 0x400d1, 0);
            fn_801CB538(this_->mRoomId, &this_->mPos, 0, 0);
            this_->mActiveFlag = 0;
        }
    } else {
        s32 idx = this_->mRoomId;
        u8* mgr = fn_802D6A9C();
        f32* r;
        if (idx < 8) {
            r = (f32*)(mgr + 0xcc);
        } else {
            r = (f32*)(mgr + 0xdc);
        }
        if (!ItemBase_inArea(r, &this_->mPos.x)) {
            this_->mActiveFlag = 0;
        } else if (fn_801F2A10(this_, -1, this_->mDirection, 0, 0)) {
            this_->mImpactTimer = 2;
        } else if (fn_801F2B7C(this_, this_->mHitType, -1, 1)) {
            this_->mActiveFlag = 0;
        }
    }
    if (this_->mActiveFlag != 0) {
        this_->mPos.add(this_->mVel);
    }
    fn_801CE4BC(this_);
}

extern "C" void fn_801D2FEC(ProjectileBaseActor* this_) {
    fn_801D0ED0(this_);
    f32 a = lbl_8053F070;
    f32 c = lbl_8053F06C;
    f32 b = lbl_8053F074;
    f32 d = lbl_8053F078;
    this_->mBounds60[0] = a;
    this_->mBounds60[1] = a;
    this_->mBounds60[2] = b;
    this_->mBounds60[3] = b;
    this_->mBounds70[0] = c;
    this_->mBounds70[1] = c;
    this_->mBounds70[2] = d;
    this_->mBounds70[3] = d;
    this_->mBounds80[0] = c;
    this_->mBounds80[1] = c;
    this_->mBounds80[2] = d;
    this_->mBounds80[3] = d;
    this_->mCollisionMask = 0;
    this_->mItemFlags |= 0x280;
    this_->mSortPriority = 1000;
    this_->mCopiedPriority = this_->mSortPriority;
    this_->mFlag194 = 1;
    this_->mHitType = 2;
    fn_801D2608(&this_->mAnimSub, lbl_8053A130, 1);
    fn_801D22DC(&this_->mAnimSub, 0, 2, 0);
    fn_801D1D60(&this_->mAnimSub);
}

extern "C" void* fn_801D30B8(ProjectileBaseActor* this_) {
    fn_801D0F40(this_);
    this_->mVtable = lbl_804A48B0;
    this_->mImpactTimer = 0;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
