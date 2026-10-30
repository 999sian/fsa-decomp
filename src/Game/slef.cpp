// TU 0x80213e00-0x80214244 — Actor 'SLEF' (Falling Leaf / Environmental Effect).
#include "types.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
void operator delete(void* p);
extern void* lbl_804A6400[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

struct SlefSub270 {
    u8 _pad00[0x10];
    s32 mAnimOffset; // +0x280 on SlefActor
    u8 _pad14[0x10];
    void* mVtable;   // +0x294 on SlefActor
};

struct SlefActor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ u32 mRoomId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ f32 mPos[3];
    /* 0x018 */ u8 _pad18[0x3C - 0x18];
    /* 0x03C */ f32 mVel[3];
    /* 0x048 */ u8 _pad48[0x60 - 0x48];
    /* 0x060 */ f32 mBounds60[4];
    /* 0x070 */ f32 mBounds70[4];
    /* 0x080 */ f32 mBounds80[4];
    /* 0x090 */ u8 _pad90[8];
    /* 0x098 */ s32 mField98;
    /* 0x09C */ u8 _pad9C[0xB0 - 0x9C];
    /* 0x0B0 */ s32 mCollisionMask;
    /* 0x0B4 */ u8 _padB4[0x108 - 0xB4];
    /* 0x108 */ s32 mSortPriority;
    /* 0x10C */ u8 _pad10C[0x194 - 0x10C];
    /* 0x194 */ u8 mFlag194;
    /* 0x195 */ u8 _pad195[3];
    /* 0x198 */ u32 mRoomHandle;
    /* 0x19C */ u8 _pad19C[0x230 - 0x19C];
    /* 0x230 */ u32 mItemFlags;
    /* 0x234 */ u8 _pad234[0x244 - 0x234];
    /* 0x244 */ s32 mCopiedPriority;
    /* 0x248 */ s32 mState;
    /* 0x24C */ s32 mTimer;
    /* 0x250 */ s32 mTargetId;
    /* 0x254 */ f32 mSpeedX;
    /* 0x258 */ f32 mSpeedY;
    /* 0x25C */ u8 _pad25C[0x270 - 0x25C];
    /* 0x270 */ SlefSub270 mAnimSub;
};

extern "C" void* fn_80213E00(SlefActor* this_, s16 freeFlag) {
    if (this_ != 0) {
        this_->mVtable = lbl_804A6400;
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
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_803075AC(u32 callerID, u32 ownerID, void* posPtr, s32 effectRef,
                             s32 unused, s32 mode, s32 targetPlayerIdx, s32 kind,
                             s32 stackArg9, s32 stackArg10);

// SLEF draw (vtable slot 6)
extern "C" void fn_80213E90(SlefActor* this_) {
    fn_803075AC(this_->mRoomHandle, this_->mRoomId,
                this_->mPos, this_->mAnimSub.mAnimOffset + 0x1c3,
                0, 1, -1, 1, 0, 0);
}

extern "C" {

void InitFloatTriple_0x3c_0x40_0x44(SlefActor* thisObj) {
    f32 v = 0.0f;
    thisObj->mVel[0] = v;
    thisObj->mVel[1] = v;
    thisObj->mVel[2] = v;
}

void EmptyHook_80213EF8(void) {}

extern f32 lbl_8053FB84;
extern f32 lbl_8053FB88;
extern void* lbl_8053A180[2];
void fn_801D0ED0(void* this_);
void fn_801D2608(void* seq, void* table, s32 count);
void fn_801D22DC(void* this_, s32 seqIndex, s32 mode, s32 evalNow);

// SLEF init (vtable slot 1)
void fn_80213EFC(SlefActor* this_) {
    fn_801D0ED0(this_);
    this_->mBounds60[0] = 1.0f;
    this_->mBounds60[1] = 1.0f;
    this_->mBounds60[2] = -1.0f;
    this_->mBounds60[3] = -1.0f;
    this_->mBounds70[0] = this_->mBounds60[0];
    this_->mBounds70[1] = this_->mBounds60[1];
    this_->mBounds70[2] = this_->mBounds60[2];
    this_->mBounds70[3] = this_->mBounds60[3];
    this_->mBounds80[0] = 1.0f;
    this_->mBounds80[1] = 1.0f;
    this_->mBounds80[2] = -1.0f;
    this_->mBounds80[3] = -1.0f;
    this_->mCollisionMask = 0;
    this_->mField98 = 2;
    this_->mItemFlags |= 0x380;
    this_->mSortPriority = 1000;
    this_->mCopiedPriority = this_->mSortPriority;
    this_->mFlag194 = 1;
    this_->mState = 0;
    this_->mTimer = 0;
    this_->mTargetId = -1;
    this_->mSpeedX = 0.0f;
    this_->mSpeedY = 0.0f;
    fn_801D2608(&this_->mAnimSub, lbl_8053A180, 1);
    fn_801D22DC(&this_->mAnimSub, 0, 2, 0);
}

}

extern "C" void* fn_801D0F40(void* this_);

extern "C" void* fn_80213FE4(SlefActor* this_) {
    fn_801D0F40(this_);
    this_->mVtable = lbl_804A6400;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
