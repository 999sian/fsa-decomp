// TU 0x802dfce8-0x802e038c — Actor 'GRVE' (Grave / Diggable Hole, misdecoded as FGVE in early CSV).
#include "Game/esd/types.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern void* lbl_804A99C0[];

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

struct FgvePt { f32 x, y; };
struct FgveBox { FgvePt min, max; };
struct FgveReward { u16 a, b, c, d; };

struct GrveActor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ u32 mRoomId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ JGeometry::TVec3<f32> mPos;
    /* 0x018 */ u8 _pad18[0x60 - 0x18];
    /* 0x060 */ FgveBox mBounds;
    /* 0x070 */ u8 _pad70[0x90 - 0x70];
    /* 0x090 */ u32 mSpawnParam;
    /* 0x094 */ u8 _pad94[0x11C - 0x94];
    /* 0x11C */ u8 mActiveFlag;
    /* 0x11D */ u8 _pad11D[0x198 - 0x11D];
    /* 0x198 */ u32 mRoomHandle;
    /* 0x19C */ u8 _pad19C[0x230 - 0x19C];
    /* 0x230 */ s32 mState;            // 0 = closed, 1 = pushing, 2 = reward, 3 = sliding, 4 = done
    /* 0x234 */ s32 mRewardIndex;      // Unpacked from spawnParam & 0x3F
    /* 0x238 */ s32 mPushingPlayer;    // Player index pushing/digging (-1 = none)
    /* 0x23C */ f32 mPushProgress;     // Frame counter while pushing / sliding
    /* 0x240 */ JGeometry::TVec3<f32> mSavedPos;
};

extern "C" void* fn_802DFCE8(GrveActor* this_, s16 freeFlag) {
    if (this_ != 0) {
        this_->mVtable = lbl_804A99C0;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern const char lbl_8046E9C0[];
extern "C" void fn_801F06F0(void* this_, const char* name, s32 id, s32 a, s32 b, f32 s0, f32 s1);

// GRVE draw (vtable slot 6)
extern "C" void fn_802DFD48(GrveActor* this_) {
    if (this_->mState >= 2) {
        fn_801F06F0(this_, lbl_8046E9C0, 0x16d, 0, 7, 1.0f, 1.0f);
    }
}

extern const FgveReward lbl_8046E9B0[];
extern void* lbl_8053AC98;
extern "C" void fn_80239914(FgveBox* box, u32 room, u32 id);
extern "C" s32 fn_80239558(FgveBox* box, u32 room, u32 id);
extern "C" s32 fn_8023AF14(FgveBox* box, u32 room, s32 a, f32 f);
extern "C" s32 fn_80230CFC(s32 player);
extern "C" u8 fn_8023513C(s32 player);
extern "C" void fn_8029E050(void* mgr, JGeometry::TVec3<f32>* pos, u32 room, u16 a, u16 b, u16 c, u16 d);
extern "C" void fn_802A3948(void* mgr, JGeometry::TVec3<f32>* pos, s32 player, u32 room, s32 id);
extern "C" void fn_801F0E34(void* this_, s32 p1, s32 p2);
extern "C" void fn_801F0D20(void* this_, s32 id);

static inline void fgveOpen(GrveActor* this_) {
    this_->mState = 2;
    this_->mSavedPos = this_->mPos;
    this_->mPos.x += 16.0f;
    this_->mPos.y += 16.0f;
    this_->mBounds.min.x = -16.0f;
    this_->mBounds.min.y = -16.0f;
    this_->mBounds.max.x = 16.0f;
    this_->mBounds.max.y = 0.0f;
}

// GRVE update (vtable slot 3)
extern "C" void fn_802DFD90(GrveActor* this_) {
    f32 x, y;
    if (this_->mState < 2) {
        x = 16.0f + this_->mPos.x;
        y = 16.0f + this_->mPos.y;
    } else {
        x = this_->mPos.x;
        y = this_->mPos.y;
    }
    FgveBox box;
    box.min.x = this_->mBounds.min.x;
    box.min.y = this_->mBounds.min.y;
    box.max.x = this_->mBounds.max.x;
    box.max.y = this_->mBounds.max.y;
    box.min.x += x;
    box.min.y += y;
    box.max.x += x;
    box.max.y += y;
    fn_80239914(&box, this_->mRoomId, this_->mRoomHandle);
    s32 player = fn_80239558(&box, this_->mRoomId, this_->mRoomHandle);
    switch (this_->mState) {
    case 0: {
        s32 digger = fn_8023AF14(&box, this_->mRoomId, 0, 0.0f);
        if (player >= 0 && fn_80230CFC(player) == 3) {
            this_->mState = 1;
            this_->mPushingPlayer = player;
            this_->mPushProgress = 0.0f;
        } else if (digger >= 0 && fn_8023513C(digger) && fn_80230CFC(digger) == 3) {
            this_->mPushingPlayer = digger;
            this_->mPushProgress = 0.0f;
            fgveOpen(this_);
        }
        break;
    }
    case 1:
        if (player >= 0 && this_->mPushingPlayer == player && fn_80230CFC(player) == 3) {
            this_->mPushProgress += 1.0f;
            if (this_->mPushProgress >= 25.0f) {
                fgveOpen(this_);
            }
        } else if (this_->mPushingPlayer != player) {
            this_->mPushingPlayer = -1;
            this_->mState = 0;
        }
        break;
    case 2: {
        s32 i = this_->mRewardIndex;
        fn_8029E050(lbl_8053AC98, &this_->mSavedPos, this_->mRoomId,
                    lbl_8046E9B0[i].a, lbl_8046E9B0[i].b, lbl_8046E9B0[i].c, lbl_8046E9B0[i].d);
        this_->mState = 3;
        this_->mPushProgress = 0.0f;
        break;
    }
    case 3:
        if (((s32)this_->mPushProgress & 3) == 0) {
            fn_801F0E34(this_, 0x3000e, 0);
        }
        this_->mPushProgress += 0.5;
        this_->mPos.y -= 0.5;
        if (this_->mPushProgress >= 16.0f) {
            this_->mSavedPos.y = this_->mPos.y - 16.0f;
            fn_802A3948(lbl_8053AC98, &this_->mSavedPos, this_->mPushingPlayer, this_->mRoomId, 0x266);
            this_->mSavedPos.x += 16.0f;
            fn_802A3948(lbl_8053AC98, &this_->mSavedPos, this_->mPushingPlayer, this_->mRoomId, 0x269);
            this_->mState = 4;
        }
        break;
    case 4:
        if (this_->mRewardIndex == 1) {
            fn_801F0D20(this_, 3);
        }
        this_->mActiveFlag = 0;
        break;
    }
}

// GRVE init (vtable slot 1)
extern "C" void fn_802E0128(GrveActor* this_) {
    this_->mBounds.min.x = -16.0f;
    this_->mBounds.min.y = -16.0f;
    this_->mBounds.max.x = 16.0f;
    this_->mBounds.max.y = 0.0f;
    this_->mRewardIndex = this_->mSpawnParam & 0x3F;
    this_->mPushingPlayer = -1;
    this_->mPushProgress = 0.0f;
    this_->mState = 0;
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
