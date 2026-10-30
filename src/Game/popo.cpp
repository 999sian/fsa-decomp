// POPO actor — Tentacle/Blob Enemy ('POPO'). TU 80172170-80172894.
#include "types.h"
#include "JSystem/JMath/JMath.h"
#include "JSystem/JGeometry/Vec.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801F06F0(void* actor, const char* file, s32 idx, f32 sx, f32 sy, s32 a, s32 b);
extern void* lbl_804A0868[];

struct PopoGame { u8 pad[0xb4]; JMARandFast rnd; };
extern PopoGame* lbl_8053AAF8;

struct PopoActor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ u8 _pad04[0x0C - 0x04];
    /* 0x00C */ JGeometry::TVec3<f32> mPos;
    /* 0x018 */ u8 _pad18[0x3C - 0x18];
    /* 0x03C */ JGeometry::TVec3<f32> mVel;
    /* 0x048 */ u8 _pad48[0x60 - 0x48];
    /* 0x060 */ f32 mBounds[4];
    /* 0x070 */ u8 _pad70[0x80 - 0x70];
    /* 0x080 */ f32 mHitBounds[4];
    /* 0x090 */ u32 mSpawnParam;
    /* 0x094 */ u8 _pad94[0xB0 - 0x94];
    /* 0x0B0 */ u32 mCollisionMask;
    /* 0x0B4 */ u8 _padB4[0x230 - 0xB4];
    /* 0x230 */ s32 mState;
    /* 0x234 */ s32 mTimers[3];      // [0] = anim timer (+0x234), [1] = move timer (+0x238), [2] = +0x23C
    /* 0x240 */ s32 mMoveToggle;     // Alternates 0 (moving) and 1 (paused)
    /* 0x244 */ s32 mField244;
    /* 0x248 */ s32 mField248;
    /* 0x24C */ s32 mAnimFrame;      // 0..3 (sprite 0x99 + mAnimFrame in "enemy_gc_sob.bin")
    /* 0x250 */ JGeometry::TVec3<f32> mTargetVel;
};

// POPO destructor
extern "C" void* fn_80172170(PopoActor* this_, s16 freeFlag) {
    if (this_ != 0) {
        this_->mVtable = lbl_804A0868;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// POPO draw (vtable slot 6)
extern "C" void fn_801721D0(PopoActor* this_) {
    fn_801F06F0(this_, "enemy_gc_sob.bin", this_->mAnimFrame + 0x99, 1.0f, 1.0f, 0, 0);
}

extern "C" s32 fn_801F3D94(void* this_, s32 a);
extern "C" u8 fn_801F305C(void* this_);
extern "C" u8 fn_801F2618(void* this_, void* out, s32 a);
extern "C" u8 fn_801F2B7C(void* this_, s32 a, s32 b, s32 c);
extern "C" void fn_801F71A4(f32* p, f32 a, f32 b, f32 c);

static inline f32 popoSin(s16 v) { return JMath::sincosTable_.mTable[(u16)v >> 5].first; }
static inline f32 popoCos(s16 v) { return JMath::sincosTable_.mTable[(u16)v >> 5].second; }

// POPO update (vtable slot 3)
extern "C" void fn_80172210(PopoActor* this_) {
    if (this_->mSpawnParam == 1) {
        if (this_->mPos.z > 0.0f) {
            this_->mVel.z = this_->mVel.z - 1.0f;
            if (this_->mVel.z < -10.0f) {
                this_->mVel.z = -10.0f;
            }
            this_->mPos.add(this_->mVel);
            return;
        }
        this_->mPos.z = 0.0f;
        this_->mVel.x = 0.0f;
        this_->mVel.y = 0.0f;
        this_->mVel.z = 0.0f;
        this_->mCollisionMask = 0x11101;
        this_->mSpawnParam = 0;
    }
    if (fn_801F3D94(this_, 1) != 0 || fn_801F305C(this_)) {
        fn_801F2618(this_, 0, 0);
        return;
    }
    fn_801F71A4(&this_->mVel.x, this_->mTargetVel.x, 0.3f, 1.0f);
    fn_801F71A4(&this_->mVel.y, this_->mTargetVel.y, 0.3f, 1.0f);
    this_->mPos.add(this_->mVel);
    fn_801F2B7C(this_, -100, -1, 1);
    fn_801F2618(this_, 0, 0);
    switch (this_->mState) {
    case 0:
        if (this_->mTimers[1] == 0) {
            PopoGame* g = lbl_8053AAF8;
            this_->mTimers[1] = (s32)(10.0f * g->rnd.get_ufloat_1()) + 10;
            this_->mMoveToggle = this_->mMoveToggle + 1;
            this_->mMoveToggle = this_->mMoveToggle & 1;
            if (this_->mMoveToggle == 0) {
                PopoGame* g1 = lbl_8053AAF8;
                this_->mTargetVel.x = 0.5f * popoSin((s16)(s32)(65536.0f * g1->rnd.get_ufloat_1()));
                PopoGame* g2 = lbl_8053AAF8;
                this_->mTargetVel.y = 0.5f * popoCos((s16)(s32)(65536.0f * g2->rnd.get_ufloat_1()));
            } else {
                this_->mTargetVel.x = 0.0f;
                this_->mTargetVel.y = 0.0f;
                this_->mTargetVel.z = 0.0f;
            }
        }
        break;
    }
    if (this_->mTimers[0] == 0) {
        this_->mAnimFrame = this_->mAnimFrame + 1;
        this_->mAnimFrame = this_->mAnimFrame & 3;
        this_->mTimers[0] = 8;
    }
    for (int i = 0; i < 3; i++) {
        if (this_->mTimers[i] > 0) {
            this_->mTimers[i]--;
        }
    }
}

// POPO init (vtable slot 1)
extern "C" void fn_80172530(PopoActor* this_) {
    this_->mSpawnParam = this_->mSpawnParam & 0xff;
    this_->mBounds[0] = -8.0f;
    this_->mBounds[1] = -8.0f;
    this_->mBounds[2] = 8.0f;
    this_->mBounds[3] = 8.0f;
    this_->mHitBounds[0] = -8.0f;
    this_->mHitBounds[1] = -8.0f;
    this_->mHitBounds[2] = 8.0f;
    this_->mHitBounds[3] = 8.0f;
    this_->mMoveToggle = 0;
    this_->mField244 = 0;
    this_->mField248 = 0;
    this_->mTimers[0] = 0;
    this_->mTimers[1] = 0;
    this_->mTimers[2] = 0;
    this_->mAnimFrame = 0;
    this_->mTargetVel.x = 0.0f;
    this_->mTargetVel.y = 0.0f;
    this_->mTargetVel.z = 0.0f;
    this_->mVel.x = 0.0f;
    this_->mVel.y = 0.0f;
    this_->mVel.z = 0.0f;
    this_->mCollisionMask = 0x11101;
    PopoGame* g = lbl_8053AAF8;
    this_->mMoveToggle = (s32)(1.99f * g->rnd.get_ufloat_1());
    PopoGame* g2 = lbl_8053AAF8;
    this_->mTimers[1] = (s32)(10.0f * g2->rnd.get_ufloat_1()) + 10;
    if (this_->mSpawnParam == 1) {
        this_->mCollisionMask = 0;
    }
    this_->mState = 0;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
