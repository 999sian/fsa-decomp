// TU 0x802153a8-0x802157b8 — Cosmetic Slot/Phase Cycle Helper.
#include "types.h"

extern "C" u8 fn_801CD580(u8 val);
extern "C" u8 fn_801CD398(u8 val1, u8 val2);

struct CosmeticPhaseState {
    /* 0x00 */ u8 mEnabled;
    /* 0x01 */ u8 mCurrentVal;
    /* 0x02 */ u8 mTargetVal;
    /* 0x03 */ u8 mPhase;
    /* 0x04 */ u16 mFrameTimer;
};

extern "C" u8 fn_802153A8(CosmeticPhaseState* this_) {
    u8 retval = 0;

    if (this_->mEnabled != 0) {
        this_->mFrameTimer = this_->mFrameTimer + 1;
        s32 phase = this_->mPhase;

        switch (phase) {
        case 0:
            if (this_->mFrameTimer % 5 == 0) {
                this_->mCurrentVal = fn_801CD580(this_->mCurrentVal);
            }
            if (this_->mFrameTimer >= 0x64) {
                this_->mPhase = this_->mPhase + 1;
                this_->mFrameTimer = 0;
            }
            break;
        case 1:
            if (this_->mFrameTimer % 15 == 0) {
                this_->mCurrentVal = fn_801CD580(this_->mCurrentVal);
            }
            if (this_->mFrameTimer >= 0x4b) {
                u8 same = 0;
                if (this_->mCurrentVal == this_->mTargetVal) {
                    same = 1;
                }
                if (same != 0) {
                    this_->mPhase = this_->mPhase + 1;
                    this_->mFrameTimer = 0;
                } else {
                    retval = 1;
                }
            }
            break;
        case 2:
            if (this_->mFrameTimer % 15 == 0) {
                this_->mCurrentVal = fn_801CD398(this_->mCurrentVal, this_->mTargetVal);
                retval = 1;
            }
            break;
        default:
            break;
        }
    }

    if (retval != 0) {
        this_->mFrameTimer = this_->mFrameTimer - 1;
        this_->mEnabled = 0;
    }

    return retval;
}

extern "C" {

void InitFlagBlock3c_WithFlag(CosmeticPhaseState* thisPtr, u8 flag) {
    thisPtr->mEnabled = 1;
    thisPtr->mCurrentVal = flag;
    thisPtr->mTargetVal = flag;
    thisPtr->mPhase = 0;
    thisPtr->mFrameTimer = 0;
}

void ResetFlagBlock3c_Zero(CosmeticPhaseState* thisPtr) {
    thisPtr->mEnabled = 0;
    thisPtr->mCurrentVal = 0;
    thisPtr->mTargetVal = 0;
    thisPtr->mPhase = 0;
    thisPtr->mFrameTimer = 0;
}

}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
