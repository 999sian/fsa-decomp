// TU 0x802ec73c-0x802ecad4 — Actor 'ZOMO' (Switch-Triggered Camera Zoom Request).
#include "Game/esd/types.h"
#include "Game/esd/Actor.h"

extern "C" void __dt__5ActorFv(void* this_, int how);
extern void* lbl_804AA228[];

struct ZomoTarget {
    u8 pad[0x7f4];
    u8 busy;
    u8 request;
    inline bool tryRequest() {
        bool ok = false;
        if (busy == 0) {
            ok = true;
            request = 1;
        }
        return ok;
    }
};
struct ZomoVT {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10();
    virtual u8 check();
};

struct ZomoActor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ u8 _pad04[0x90 - 0x04];
    /* 0x090 */ u32 mSpawnParam;
    /* 0x094 */ u8 _pad94[0x11C - 0x94];
    /* 0x11C */ u8 mActiveFlag;
    /* 0x11D */ u8 _pad11D[0x230 - 0x11D];
    /* 0x230 */ s32 mState;        // 0 = waiting for switch, 1 = holding zoom
    /* 0x234 */ s32 mHoldDuration; // Unpacked from spawnParam & 0xFFF
    /* 0x238 */ s32 mHoldTimer;
};

extern "C" void* fn_802EC73C(ZomoActor* this_, short how) {
    if (this_) {
        this_->mVtable = lbl_804AA228;
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" {
void Zomo_EmptyHook(void) {}
}

extern char* lbl_8053AB10;
#define ZOMO_TARGET (*(ZomoTarget**)(lbl_8053AB10 + 0x24))

// ZOMO update (vtable slot 3)
extern "C" void fn_802EC7A0(ZomoActor* this_) {
    switch (this_->mState) {
    case 0:
        if (((ZomoVT*)this_)->check()) {
            ZOMO_TARGET->tryRequest();
            if (ZOMO_TARGET->tryRequest() == true) {
                this_->mState = 1;
                this_->mHoldTimer = this_->mHoldDuration;
            }
        }
        break;
    case 1:
        ZOMO_TARGET->tryRequest();
        this_->mHoldTimer = this_->mHoldTimer - 1;
        if (this_->mHoldTimer == 0) {
            this_->mActiveFlag = 0;
        }
        break;
    }
}

// ZOMO init (vtable slot 1)
extern "C" {
void Zomo_SetParams(ZomoActor* thisPtr) {
    u32 v = thisPtr->mSpawnParam;
    thisPtr->mHoldDuration = v & 0xFFF;
    thisPtr->mHoldTimer = 0;
    thisPtr->mState = 0;
}
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
