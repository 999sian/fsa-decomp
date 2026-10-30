// tu_801C6A4C: .text 0x801C6A4C-0x801C71BC — Enemy Attack-State & AI Decision Helpers.
#include "types.h"

extern "C" void fn_800FEB78(void* anim, s32 mode);
extern "C" void fn_801F0E34(void* actor, u32 id, s32 arg);
extern "C" u8 fn_801CAED4(void* actor, s32 target);
extern "C" u8 fn_801D0B44(void* actor, s32 target);
extern "C" s32 fn_801D0280(void* actor, s32 target);
extern "C" void fn_801CD930(void* dir, s32 target, s32 speed);
extern "C" void fn_801C3B7C(void* actor, s32 state);
extern "C" s16 fn_801F6874(s32 v);
extern "C" f32 fn_801D0DA0(void* actor, s32 target, void* pos);
extern "C" s32 fn_801CD664(s32 n);
extern "C" u8 fn_801D12CC(void* actor);
extern "C" s16 fn_801D02E0(void* actor, void* p);
extern const f32 lbl_8053EDF4;

struct Rnd {
    u32 seed;
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - 1.0f;
    }
};
struct RndGame { u8 pad[0xb4]; Rnd rnd; };
extern RndGame* lbl_8053AAF8;

struct EnemyAiActor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ u8 _pad04[0x0C - 0x04];
    /* 0x00C */ f32 mPos[3];
    /* 0x018 */ u8 _pad18[0x98 - 0x18];
    /* 0x098 */ s32 mFacingDir;
    /* 0x09C */ u8 _pad9C[0x248 - 0x9C];
    /* 0x248 */ s32 mActionState;
    /* 0x24C */ s32 mStateTimer;
    /* 0x250 */ s32 mStateDuration;
    /* 0x254 */ f32 mSpeedX;
    /* 0x258 */ f32 mSpeedY;
    /* 0x25C */ u8 _pad25C[0x32C - 0x25C];
    /* 0x32C */ f32 mTargetPos[3];
    /* 0x338 */ s32 mTargetPlayer;
    /* 0x33C */ s16 mAimAngle;
    /* 0x33E */ u16 _pad33E;
    /* 0x340 */ s32 mAnimMode;
    /* 0x344 */ u8 _pad344[9];
    /* 0x34D */ u8 mAnimSubStep;
    /* 0x34E */ u8 _pad34E[6];
    /* 0x354 */ u32 mAnimFlags;
    /* 0x358 */ u8 _pad358[0x524 - 0x358];
    /* 0x524 */ u32 mCapabilityFlags;
    /* 0x528 */ u8 _pad528[0x594 - 0x528];
    /* 0x594 */ u8 mComboCount;
    /* 0x595 */ u8 _pad595[0x5B0 - 0x595];
    /* 0x5B0 */ f32 mAttackRange;
};

extern "C" void fn_801C6A4C(EnemyAiActor* this_) {
    if (this_->mAnimMode == 9) {
        if (this_->mAnimFlags & 0x20) {
            fn_800FEB78(&this_->mAnimMode, 6);
            switch (this_->mActionState) {
            case 0x25:
                fn_801F0E34(this_, 0x400CF, 0);
                fn_801F0E34(this_, 0x400CD, 0);
                break;
            case 0x26:
                this_->mSpeedY = 1.2f;
                break;
            }
        }
    } else {
        if (this_->mAnimFlags & 0x20) {
            this_->mAnimFlags &= ~0x20;
            this_->mAnimSubStep = 3;
            this_->mComboCount++;
        }
        s32 limit = 5;
        if (this_->mActionState == 0x26) {
            limit = 0x14;
            fn_801F0E34(this_, 0x400D0, 0);
            if (this_->mTargetPlayer >= 0 && !fn_801CAED4(this_, this_->mTargetPlayer) && fn_801D0B44(this_, this_->mTargetPlayer)) {
                fn_801CD930(&this_->mAimAngle, fn_801D0280(this_, this_->mTargetPlayer), 0x500);
            }
        }
        if (this_->mComboCount >= limit) {
            fn_801C3B7C(this_, 0x28);
        }
    }
}

extern "C" void fn_801C6BA8(EnemyAiActor* this_) {
    if (this_->mAnimFlags & 0x20) {
        switch (this_->mAnimMode) {
        case 9:
            fn_800FEB78(&this_->mAnimMode, 3);
            fn_801F0E34(this_, 0x400C6, 0);
            this_->mSpeedX = this_->mSpeedY = 2.0f;
            this_->mAimAngle = fn_801F6874(this_->mFacingDir);
            break;
        case 3:
            fn_801C3B7C(this_, 0x27);
            break;
        case 2:
            this_->mAnimFlags &= ~0x20;
            this_->mAnimSubStep = 0;
            this_->mComboCount++;
            if (this_->mComboCount >= 2) {
                fn_801C3B7C(this_, 0x27);
            }
            break;
        }
    }
}

extern "C" void fn_801C6C7C(EnemyAiActor* this_) {
    u8 idle = FALSE;
    if (this_->mStateTimer >= this_->mStateDuration) {
        idle = TRUE;
    } else if (this_->mTargetPlayer >= 0 && !fn_801CAED4(this_, this_->mTargetPlayer) && fn_801D0B44(this_, this_->mTargetPlayer)) {
        f32 d = fn_801D0DA0(this_, this_->mTargetPlayer, this_->mPos);
        u32 fl;
        u32 b8;
        if (this_->mStateTimer > 1 && (b8 = (fl = this_->mCapabilityFlags) & 8) != 0 && d <= this_->mAttackRange * this_->mAttackRange) {
            if (fl & 0x20) {
                switch (fn_801CD664(6)) {
                case 0: {
                    RndGame* g = lbl_8053AAF8;
                    if (g->rnd.get_ufloat_1() < 0.6f) {
                        fn_801C3B7C(this_, 0x23);
                    } else {
                        fn_801C3B7C(this_, 0x24);
                    }
                    break;
                }
                case 1:
                case 2:
                    fn_801C3B7C(this_, 0x25);
                    break;
                default:
                    fn_801C3B7C(this_, 0x26);
                    break;
                }
            } else if (fl & 0x10) {
                switch (fn_801CD664(3)) {
                case 0: {
                    RndGame* g = lbl_8053AAF8;
                    if (g->rnd.get_ufloat_1() < 0.6f) {
                        fn_801C3B7C(this_, 0x23);
                    } else {
                        fn_801C3B7C(this_, 0x24);
                    }
                    break;
                }
                default:
                    fn_801C3B7C(this_, 0x25);
                    break;
                }
            } else if (b8) {
                RndGame* g = lbl_8053AAF8;
                if (g->rnd.get_ufloat_1() < 0.6f) {
                    fn_801C3B7C(this_, 0x23);
                } else {
                    fn_801C3B7C(this_, 0x24);
                }
            }
        } else if (d > lbl_8053EDF4 * lbl_8053EDF4) {
            idle = TRUE;
        } else if (!fn_801D12CC(this_)) {
            idle = TRUE;
        } else {
            this_->mAimAngle = fn_801D02E0(this_, this_->mTargetPos);
        }
    } else {
        idle = TRUE;
    }
    if (idle) {
        RndGame* g = lbl_8053AAF8;
        if (g->rnd.get_ufloat_1() < 0.7f) {
            fn_801C3B7C(this_, 0xF);
        } else {
            fn_801C3B7C(this_, 0x11);
        }
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
