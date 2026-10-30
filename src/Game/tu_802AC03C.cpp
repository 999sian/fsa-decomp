// TU 0x802AC03C-0x802AC58C — Dialogue/Event Trigger Actor.
#include "types.h"

void operator delete(void* p);
extern "C" void __dt__5ActorFv(void* this_, int how);

struct EventTriggerActor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ s32 mRoomId;
    /* 0x008 */ u8 _pad08[0x90 - 0x08];
    /* 0x090 */ u32 mSpawnParam;
    /* 0x094 */ u8 _pad94[0x11C - 0x94];
    /* 0x11C */ u8 mActiveFlag;
    /* 0x11D */ u8 _pad11D[0x230 - 0x11D];
    /* 0x230 */ s32 mState;
    /* 0x234 */ s32 mTriggerId;     // Unpacked from (spawnParam >> 12) & 0xF
    /* 0x238 */ s32 mDelayTimer;    // Initialized to 40
    /* 0x23C */ s32 mWaitAfterFlag; // Unpacked from (spawnParam >> 4) & 1
    /* 0x240 */ s32 mMappedPlayer;
};

extern void* lbl_804A82A8[];
extern "C" void* fn_802AC03C(EventTriggerActor* this_, s16 freeFlag) {
    if (this_ != 0) {
        this_->mVtable = lbl_804A82A8;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_802AC09C(EventTriggerActor* this_) {
    this_->mDelayTimer = 0;
}

extern "C" void fn_802AC0A8(void) {}

extern "C" u8 fn_80388EEC(s32 p);
extern "C" void fn_8029EC84(void* mgr, u32 a, s32 room, u32 b, s32 c, s32 d);
extern "C" u8 fn_8023061C(s32 p, s32 a);
extern "C" u8 fn_80230534(s32 a);
extern "C" u8 fn_8022F514(s32 p);
extern "C" s32 fn_8022F3DC(s32 p);
extern void* lbl_8053AC98;
extern u8* lbl_8053AAF8;

extern "C" void fn_802AC0AC(EventTriggerActor* this_) {
    switch (this_->mState) {
    case 0:
        if (this_->mDelayTimer == 0) {
            if (fn_80388EEC(this_->mTriggerId)) {
                u32 p = this_->mSpawnParam;
                u32 a = p >> 16;
                u32 b = (p >> 8) & 0xf;
                switch (p & 0xf) {
                case 0:
                    break;
                case 1:
                    fn_8029EC84(lbl_8053AC98, a, this_->mRoomId, b, 0x18, 0x28);
                    break;
                case 2:
                    fn_8029EC84(lbl_8053AC98, a, this_->mRoomId, b, 0x19, 0x29);
                    break;
                case 3:
                    fn_8029EC84(lbl_8053AC98, a, this_->mRoomId, b, 0x1a, 0x2a);
                    break;
                case 4:
                    fn_8029EC84(lbl_8053AC98, a, this_->mRoomId, b, 0x1b, 0x2b);
                    break;
                case 5:
                    fn_8029EC84(lbl_8053AC98, a, this_->mRoomId, b, 0x1c, 0x2c);
                    break;
                case 6:
                    fn_8029EC84(lbl_8053AC98, a, this_->mRoomId, b, 0x1d, 0x2d);
                    break;
                case 7:
                    fn_8029EC84(lbl_8053AC98, a, this_->mRoomId, b, 0x1e, 0x2e);
                    break;
                case 8:
                    fn_8029EC84(lbl_8053AC98, a, this_->mRoomId, b, 0x1f, 0x2f);
                    break;
                case 9:
                    fn_8029EC84(lbl_8053AC98, a, this_->mRoomId, b, 0xa0, 0xb0);
                    break;
                case 10:
                    fn_8029EC84(lbl_8053AC98, a, this_->mRoomId, b, 0xa1, 0xb1);
                    break;
                case 11:
                    fn_8029EC84(lbl_8053AC98, a, this_->mRoomId, b, 0xa2, 0xb2);
                    break;
                case 12:
                    fn_8029EC84(lbl_8053AC98, a, this_->mRoomId, b, 0xa3, 0xb3);
                    break;
                case 13:
                    fn_8029EC84(lbl_8053AC98, a, this_->mRoomId, b, 0xfff, 0x100f);
                    break;
                }
                if (this_->mWaitAfterFlag != 0) {
                    this_->mState = 1;
                } else {
                    this_->mActiveFlag = 0;
                }
            }
        } else if (this_->mDelayTimer > 0) {
            this_->mDelayTimer--;
        }
        break;
    case 1:
        if (lbl_8053AAF8[0x7e] == 1) {
            if (fn_8023061C(this_->mMappedPlayer, 0) == 1) {
                this_->mActiveFlag = 0;
            }
        } else if (fn_80230534(0) == 1) {
            this_->mActiveFlag = 0;
        }
        break;
    }
}

extern "C" void fn_802AC2F4(EventTriggerActor* this_) {
    this_->mTriggerId = (this_->mSpawnParam >> 12) & 0xf;
    this_->mWaitAfterFlag = (this_->mSpawnParam >> 4) & 1;
    this_->mState = 0;
    this_->mDelayTimer = 40;
    this_->mMappedPlayer = this_->mTriggerId;
    if (fn_8022F514(this_->mTriggerId)) {
        this_->mMappedPlayer = fn_8022F3DC(this_->mTriggerId);
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"

static u8 lbl_804D14D4[0x94];
