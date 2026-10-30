// TU 0x8034a6b0-0x8034aa40 — Actor 'HTMK' (Hit Mark / 2-Frame Transient Effect).
#include "types.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);

extern void* lbl_804AC868[];

struct HtmkActor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ u32 mRoomId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ f32 mPos[3];
    /* 0x018 */ u8 _pad18[0x108 - 0x18];
    /* 0x108 */ s32 mSortPriority;
    /* 0x10C */ u8 _pad10C[0x198 - 0x10C];
    /* 0x198 */ u32 mRoomHandle;
    /* 0x19C */ u8 _pad19C[0x230 - 0x19C];
    /* 0x230 */ s32 mFrameTimer;
    /* 0x234 */ s32 mAnimFrame; // 0..1 (sprite 0x2DD + mAnimFrame in "enemy_both2_sob.bin")
};

extern "C" void* fn_8034A6B0(HtmkActor* this_, s16 freeFlag) {
    if (this_ != 0) {
        this_->mVtable = lbl_804AC868;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_801F06F0(void* actor, const char* tbl, s32 idx, u32 p4, s32 p5, f32 a, f32 b);
extern "C" void fn_803075AC(u32 a, u32 id, void* pos, u32 type, u32 p5, u32 p6, s32 p7, u32 p8, u32 p9, u32 p10);
extern "C" void detach__5ActorFv(void* actor);

// HTMK draw (vtable slot 6)
extern "C" void fn_8034A710(HtmkActor* this_) {
    fn_801F06F0(this_, "enemy_both2_sob.bin", this_->mAnimFrame + 0x2dd, 0, -1, 1.0f, 1.0f);
    fn_803075AC(this_->mRoomHandle, this_->mRoomId, this_->mPos, this_->mAnimFrame + 0x2dd, 0, 2, -1, 0, 0, 0);
}

// HTMK update (vtable slot 3): advances frame after 2 ticks, then detaches after 2 more ticks
extern "C" void fn_8034A790(HtmkActor* this_) {
    if (this_->mFrameTimer <= 0 && this_->mAnimFrame == 0) {
        this_->mAnimFrame = this_->mAnimFrame + 1;
        this_->mFrameTimer = 2;
    } else if (this_->mFrameTimer <= 0 && this_->mAnimFrame == 1) {
        detach__5ActorFv(this_);
        return;
    }
    this_->mFrameTimer = this_->mFrameTimer - 1;
}

// HTMK init (vtable slot 1)
extern "C" void fn_8034A800(HtmkActor* this_) {
    this_->mSortPriority = 10000;
    this_->mAnimFrame = 0;
    this_->mFrameTimer = 2;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
