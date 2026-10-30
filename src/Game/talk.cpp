// TU 0x80394134-0x803944c8 — Actor 'TALK' (Dialogue Message Trigger).
#include "types.h"
#include "JSystem/JGeometry/Vec.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804AF548[];

struct TalkActor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ u32 mRoomId;
    /* 0x008 */ u32 mField08;
    /* 0x00C */ Vec mPos;
    /* 0x018 */ u8 _pad18[0x90 - 0x18];
    /* 0x090 */ u32 mSpawnParam;
    /* 0x094 */ u8 _pad94[0x11C - 0x94];
    /* 0x11C */ u8 mActiveFlag;
    /* 0x11D */ u8 mField11D;
    /* 0x11E */ u8 mFlag11E;
    /* 0x11F */ u8 mFlag11F;
    /* 0x120 */ u8 _pad120[0x198 - 0x120];
    /* 0x198 */ u32 mRoomHandle;
    /* 0x19C */ u8 _pad19C[0x230 - 0x19C];
    /* 0x230 */ s32 mState;          // 0 = open message, 1 = wait for close
    /* 0x234 */ u32 mSpeakerHandle;
    /* 0x238 */ s16 mHoldTimer;      // Initialized to 0x78 (120 frames)
};

extern "C" void* fn_80394134(TalkActor* this_, s16 freeFlag) {
    if (this_ != 0) {
        this_->mVtable = lbl_804AF548;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" {
void fn_80394194(void) {}
}

extern "C" u8 fn_8038AD24(u32 a, u32 b, u32 c, u32 d, JGeometry::TVec3<f32>* pos, u32 flags);
extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802DCD0C(void* mgr);
extern "C" u8 fn_80384C58(u32 a, u32 b);

// TALK update (vtable slot 3)
extern "C" void fn_80394198(TalkActor* p) {
    u32 flags = p->mSpawnParam;
    u32 hi = flags >> 28;
    u32 lo = flags & 0x0FFFFFFF;
    switch (p->mState) {
    case 0: {
        u32 id = p->mRoomId;
        JGeometry::TVec3<f32> pos(p->mPos);
        if (fn_8038AD24(hi, lo, p->mSpeakerHandle, id, &pos, 0x1004)) {
            p->mState = 1;
        } else {
            p->mActiveFlag = 0;
        }
        break;
    }
    case 1:
        p->mHoldTimer = p->mHoldTimer - 1;
        if (p->mHoldTimer > 0) {
            if (!fn_802DCD0C(fn_802D6A9C())) {
                break;
            }
        }
        if (fn_80384C58(hi, p->mSpeakerHandle)) {
            p->mActiveFlag = 0;
        }
        break;
    }
}

// TALK init (vtable slot 1)
extern "C" {
void fn_8039427C(TalkActor* p) {
    p->mState = 0;
    p->mHoldTimer = 0x78;
    p->mSpeakerHandle = p->mRoomHandle;
    p->mFlag11F = 1;
    p->mFlag11E = 1;
}
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
