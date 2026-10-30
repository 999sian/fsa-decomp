// Game TU 801B6634-801B6C50 — Actor 'SAFU' (Bouncing / Squashing Object).
#include "types.h"
#include "Game/ItemBase.h"
#include "JSystem/JGeometry/Vec.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A3948[];

struct SafuActor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ u32 mRoomId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ JGeometry::TVec3<f32> mPos;
    /* 0x018 */ u8 _pad18[0x3C - 0x18];
    /* 0x03C */ JGeometry::TVec3<f32> mVel;
    /* 0x048 */ u8 _pad48[0x60 - 0x48];
    /* 0x060 */ f32 mBounds60[4];
    /* 0x070 */ u8 _pad70[0x80 - 0x70];
    /* 0x080 */ f32 mBounds80[4];
    /* 0x090 */ u32 mSpawnParam;
    /* 0x094 */ u16 mBounceTrigger;
    /* 0x096 */ u8 _pad96[0x11F - 0x96];
    /* 0x11F */ u8 mFlag11F;
    /* 0x120 */ u8 _pad120[0x198 - 0x120];
    /* 0x198 */ void* mRoomHandle;
    /* 0x19C */ u8 _pad19C[0x230 - 0x19C];
    /* 0x230 */ s32 mState;          // 0 = idle, 1 = airborne, 2 = landed/squashed
    /* 0x234 */ s32 mTimers[3];
    /* 0x240 */ u32 mField240;
    /* 0x244 */ u32 mField244;
    /* 0x248 */ u32 mField248;
    /* 0x24C */ f32 mTargetVelX;
    /* 0x250 */ f32 mTargetVelY;
    /* 0x254 */ f32 mTargetVelZ;
    /* 0x258 */ f32 mScaleX;
    /* 0x25C */ f32 mScaleY;
    /* 0x260 */ f32 mScaleZ;
    /* 0x264 */ f32 mTargetScaleX;
    /* 0x268 */ f32 mTargetScaleY;
    /* 0x26C */ f32 mTargetScaleZ;
};

extern "C" void* fn_801B6634(SafuActor* this_, s16 freeFlag) {
    if (this_ != 0) {
        this_->mVtable = lbl_804A3948;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_801F71A4(f32* v, f32 a, f32 b, f32 c);
extern const f32 lbl_8053EA98;
extern const f32 lbl_8053EA9C;
extern const f32 lbl_8053EAA0;
extern const f32 lbl_8053EAA4;
extern const f32 lbl_8053EAA8;
extern const f32 lbl_8053EAAC;
extern const f32 lbl_8053EAB0;
extern const f32 lbl_8053EAB4;
extern const f32 lbl_8053EAB8;
extern const f32 lbl_8053EABC;

extern "C" void fn_801F06F0(void* actor, void* res, u32 id, DrawRec* rec, void* p5, f32 a, f32 b);
extern "C" void fn_803075AC(void* obj, u32 id, void* pos, u32 kind, u32 a, u32 b, s32 c, u32 d, u32 e, u32 f);
extern u8 lbl_80469120[];

// SAFU draw (vtable slot 6)
extern "C" void fn_801B6694(SafuActor* this_) {
    DrawRec rec;
    f32 mtx[3][4];
    f32 zero = lbl_8053EA98;
    mtx[0][3] = zero;
    mtx[1][3] = zero;
    mtx[2][3] = zero;
    f32 sy = this_->mScaleY;
    mtx[0][0] = this_->mScaleX;
    mtx[0][1] = zero;
    mtx[0][2] = zero;
    mtx[1][0] = zero;
    mtx[1][1] = sy;
    mtx[1][2] = zero;
    mtx[2][0] = zero;
    mtx[2][1] = zero;
    mtx[2][2] = sy;
    rec.w18 = mtx;
    rec.b1c = 1;
    rec.b1d = 1;
    rec.b20 = 0;
    rec.b2d = 1;
    fn_801F06F0(this_, lbl_80469120, 0xe6, &rec, 0, 1.0f, 1.0f);
    fn_803075AC(this_->mRoomHandle, this_->mRoomId, &this_->mPos, 0xe6, 0, 2, -1, 0, 0, 1);
}

// SAFU update (vtable slot 3)
extern "C" void fn_801B6854(SafuActor* this_) {
    fn_801F71A4(&this_->mVel.x, this_->mTargetVelX, lbl_8053EAA0, lbl_8053EA9C);
    fn_801F71A4(&this_->mVel.y, this_->mTargetVelY, lbl_8053EAA0, lbl_8053EA9C);
    fn_801F71A4(&this_->mScaleX, this_->mTargetScaleX, lbl_8053EAA4, lbl_8053EAA8);
    fn_801F71A4(&this_->mScaleY, this_->mTargetScaleY, lbl_8053EAA4, lbl_8053EAA8);
    this_->mPos.add(this_->mVel);
    switch (this_->mState) {
    case 2:
        break;
    case 0:
        if (this_->mBounceTrigger == 0) {
            break;
        }
        this_->mBounceTrigger = 0;
        this_->mVel.z = lbl_8053EAAC;
        this_->mState = 1;
        break;
    case 1:
        if (this_->mPos.z < lbl_8053EA98) {
            this_->mScaleX = lbl_8053EAB0;
            this_->mScaleY = lbl_8053EAB4;
            this_->mScaleZ = lbl_8053EA9C;
            this_->mPos.z = lbl_8053EA98;
            this_->mVel.z = lbl_8053EA98;
            this_->mState = 2;
        }
        break;
    }
    for (s32 i = 0; i < 3; i++) {
        s32* t = (s32*)((u8*)this_ + i * 4);
        if (t[0x234 / 4] > 0) {
            t[0x234 / 4]--;
        }
    }
}

// SAFU init (vtable slot 1)
extern "C" void fn_801B69AC(SafuActor* this_) {
    f32 b = lbl_8053EABC;
    f32 a = lbl_8053EAB8;
    this_->mBounds60[0] = a;
    this_->mBounds60[1] = a;
    this_->mBounds60[2] = b;
    this_->mBounds60[3] = b;
    this_->mBounds80[0] = a;
    this_->mBounds80[1] = a;
    this_->mBounds80[2] = b;
    this_->mBounds80[3] = b;
    this_->mField240 = 0;
    this_->mField244 = 0;
    this_->mField248 = 0;
    this_->mTimers[0] = 0;
    this_->mTimers[1] = 0;
    this_->mTimers[2] = 0;
    this_->mScaleX = lbl_8053EA9C;
    this_->mScaleY = lbl_8053EA9C;
    this_->mScaleZ = lbl_8053EA9C;
    this_->mTargetScaleX = lbl_8053EA9C;
    this_->mTargetScaleY = lbl_8053EA9C;
    this_->mTargetScaleZ = lbl_8053EA9C;
    this_->mTargetVelZ = lbl_8053EA98;
    this_->mTargetVelY = lbl_8053EA98;
    this_->mTargetVelX = lbl_8053EA98;
    this_->mState = 0;
    this_->mFlag11F = 1;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
