// TU 0x802ABC74-0x802AC03C — Enemy Count / Threshold Trigger Actor.
#include "types.h"

void operator delete(void* p);
extern "C" void __dt__5ActorFv(void* this_, int how);

struct CountTriggerActor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ s32 mRoomId;
    /* 0x008 */ u8 _pad08[0x90 - 0x08];
    /* 0x090 */ u32 mSpawnParam;
    /* 0x094 */ u8 _pad94[0x11C - 0x94];
    /* 0x11C */ u8 mActiveFlag;
    /* 0x11D */ u8 _pad11D[0x230 - 0x11D];
    /* 0x230 */ s32 mState;
    /* 0x234 */ s32 mScopeMode;     // 0 = sum all 8 rooms, non-zero = current room only
    /* 0x238 */ u32 mTargetCount;   // Unpacked from spawnParam & 0xFF
    /* 0x23C */ u32 mField23C;
    /* 0x240 */ u8 mNoJingleFlag;   // Unpacked from (spawnParam >> 21) & 1
    /* 0x244 */ u32 mSavedBgmState; // Snapshot of *(lbl_8053AF80 + 0x58)
};

extern void* lbl_804A8250[];
extern "C" void* fn_802ABC74(CountTriggerActor* this_, s16 freeFlag) {
    if (this_ != 0) {
        this_->mVtable = lbl_804A8250;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_802ABCD4(void) {}

struct Mgr {
    u32 get(s32 i) { return mCount[i < 8 ? 0 : i - 7]; }
    u8 pad[0x6748];
    u32 mCount[8];
};
extern "C" Mgr* fn_802D6A9C(void);
extern "C" void fn_80138B7C(void* game);
extern u8* lbl_8053AF80;
extern void* lbl_8053AAF8;

struct ActorV {
    virtual void s00(); virtual void s01(); virtual void s02(); virtual void s03();
    virtual void s04(); virtual void s05(); virtual void s06(); virtual void s07();
    virtual void s08(); virtual void s09();
    virtual void s10(s32 a, s32 b);
};

extern "C" void fn_802ABCD8(CountTriggerActor* this_) {
    u32 total = 0;
    if (this_->mScopeMode == 0) {
        for (s32 i = 0; i < 8; i++) {
            total += fn_802D6A9C()->mCount[i];
        }
    } else {
        total = fn_802D6A9C()->get(this_->mRoomId);
    }
    if (total >= this_->mTargetCount) {
        ((ActorV*)this_)->s10(0xff, 1);
        if (this_->mSavedBgmState != *(u32*)(lbl_8053AF80 + 0x58) && this_->mNoJingleFlag == 0) {
            fn_80138B7C(lbl_8053AAF8);
        }
        this_->mActiveFlag = 0;
    }
}

extern "C" void fn_802ABDDC(CountTriggerActor* this_) {
    this_->mState = 0;
    this_->mScopeMode = (this_->mSpawnParam >> 22) & 0x1f;
    this_->mTargetCount = this_->mSpawnParam & 0xff;
    this_->mSavedBgmState = *(u32*)(lbl_8053AF80 + 0x58);
    this_->mNoJingleFlag = (this_->mSpawnParam >> 21) & 1;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"

static u8 lbl_804D13D4[0x94];
