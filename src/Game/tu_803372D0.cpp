// TU 0x803372D0-0x80337650 — Actor 'TSNO' (Animated Background/Stage Prop).
#include "types.h"

void operator delete(void* p);
extern "C" void __dt__5ActorFv(void* this_, int how);

struct TsnoActor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ s32 mRoomId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ f32 mPos[3];
    /* 0x018 */ u8 _pad18[0x90 - 0x18];
    /* 0x090 */ u32 mSpawnParam;
    /* 0x094 */ u8 _pad94[0x108 - 0x94];
    /* 0x108 */ s32 mSortPriority;
    /* 0x10C */ u8 _pad10C[0x198 - 0x10C];
    /* 0x198 */ u32 mRoomHandle;
    /* 0x19C */ u8 _pad19C[0x230 - 0x19C];
    /* 0x230 */ s32 mAnimTimer;
    /* 0x234 */ s32 mAnimFrame; // 0 or 1 (sprite 0x1AF + mAnimFrame in "enemy_both2_sob.bin")
};

extern void* lbl_804ABAE8[];
extern "C" void* fn_803372D0(TsnoActor* this_, s16 freeFlag) {
    if (this_ != 0) {
        this_->mVtable = lbl_804ABAE8;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_801F06F0(void* actor, const char* file, s32 idx, s32 a, s32 b, f32 sx, f32 sy);
extern "C" s32 fn_803075AC(u32 caller, s32 room, void* pos, s32 id, bool on, s32 mode, s32 target, s32 kind,
                           bool b, s32 d);

// TSNO draw (vtable slot 6)
extern "C" void fn_80337330(TsnoActor* this_) {
    fn_801F06F0(this_, "enemy_both2_sob.bin", this_->mAnimFrame + 0x1af, 0, -1, 1.0f, 1.0f);
    fn_803075AC(this_->mRoomHandle, this_->mRoomId, this_->mPos, this_->mAnimFrame + 0x1af, 0, 2, -1, 0, 0, 0);
}

// TSNO update (vtable slot 3)
extern "C" void fn_803373B0(TsnoActor* this_) {
    this_->mAnimTimer--;
    if (this_->mAnimTimer <= 0) {
        if ((this_->mSpawnParam & 0xf) == 0) {
            this_->mAnimFrame++;
            this_->mAnimFrame = this_->mAnimFrame & 1;
        }
        this_->mAnimTimer = 10;
    }
}

// TSNO init (vtable slot 1)
extern "C" void fn_803373F8(TsnoActor* this_) {
    this_->mSortPriority = 10000;
    this_->mAnimFrame = 0;
    this_->mAnimTimer = 10;
    if ((this_->mSpawnParam & 0xf) == 2) {
        this_->mAnimFrame = 1;
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"

static u8 lbl_80509764[0x94];
