// TU 0x802C94F4-0x802C9944 — Camera Target / Pan Focus Actor.
#include "types.h"

void operator delete(void* p);
extern "C" void __dt__5ActorFv(void* this_, int how);

struct CamFocusActor {
    virtual void s00(); virtual void s01(); virtual void s02(); virtual void s03();
    virtual void s04(); virtual void s05(); virtual void s06(); virtual void s07();
    virtual void s08(); virtual void s09();
    virtual void s10(s32 a, s32 b);

    /* 0x004 */ u32 mRoomId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ f32 mPos[3];
    /* 0x018 */ u8 _pad18[0x90 - 0x18];
    /* 0x090 */ u32 mSpawnParam;
    /* 0x094 */ u8 _pad94[0x11C - 0x94];
    /* 0x11C */ u8 mActiveFlag;
    /* 0x11D */ u8 _pad11D[0x230 - 0x11D];
    /* 0x230 */ s32 mState;        // 0 = pan to target, 1 = hold duration, 2 = permanent pan
    /* 0x234 */ u32 mGateSwitchId; // Unpacked from (spawnParam >> 22) & 0x1F
    /* 0x238 */ u32 mField238;
    /* 0x23C */ s32 mHoldDuration; // Unpacked from spawnParam & 0xFFF
    /* 0x240 */ s32 mHoldTimer;
};

extern void* lbl_804A8EA0[];
extern "C" void* fn_802C94F4(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A8EA0;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_802C9554(void) {}

extern "C" u8* fn_802D6A9C(void);
extern "C" u8 fn_802D800C(void* mgr, u32 id);
extern "C" void fn_8030C210(void* p, void* pos);
extern "C" u8 fn_8030C2A8(void* p, void* pos);
extern u8* lbl_8053AB10;

extern "C" void fn_802C9558(CamFocusActor* this_) {
    s32 sw;
    switch (this_->mState) {
    case 0:
        sw = this_->mGateSwitchId;
        if (sw != 0 && !fn_802D800C(fn_802D6A9C(), sw)) {
            break;
        }
        fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), this_->mPos);
        if (fn_8030C2A8(*(void**)(lbl_8053AB10 + 0x24), this_->mPos) == 1) {
            if ((this_->mSpawnParam >> 27) != 0) {
                this_->s10(0xff, 1);
            }
            this_->mState = 1;
            this_->mHoldTimer = this_->mHoldDuration;
        }
        break;
    case 1:
        fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), this_->mPos);
        if (this_->mHoldTimer == 0) {
            this_->mActiveFlag = 0;
        } else {
            this_->mHoldTimer = this_->mHoldTimer - 1;
        }
        break;
    case 2:
        sw = this_->mGateSwitchId;
        if (sw != 0 && !fn_802D800C(fn_802D6A9C(), sw)) {
            break;
        }
        fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), this_->mPos);
        if (fn_8030C2A8(*(void**)(lbl_8053AB10 + 0x24), this_->mPos) == 1) {
            if ((this_->mSpawnParam >> 27) != 0) {
                this_->s10(0xff, 1);
            }
        }
        break;
    }
}

extern "C" void fn_802C96E0(CamFocusActor* this_) {
    this_->mGateSwitchId = (this_->mSpawnParam >> 22) & 0x1f;
    this_->mHoldDuration = this_->mSpawnParam & 0xfff;
    this_->mHoldTimer = 0;
    if (this_->mHoldDuration == 0) {
        this_->mState = 2;
    } else {
        this_->mState = 0;
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"

static u8 lbl_804D33D4[0x94];
