// TU 0x802B7890-0x802B7C78 — Multi-Switch OR Gate Relay Actor.
#include "types.h"

void operator delete(void* p);
extern "C" void __dt__5ActorFv(void* this_, int how);

struct SwitchOrRelayActor {
    virtual void s00(); virtual void s01(); virtual void s02(); virtual void s03();
    virtual void s04(); virtual void s05(); virtual void s06(); virtual void s07();
    virtual void s08(); virtual void s09();
    virtual void s10(s32 a, s32 b);

    /* 0x004 */ u8 _pad04[0x90 - 0x04];
    /* 0x090 */ u32 mSpawnParam;
    /* 0x094 */ u8 _pad94[0x230 - 0x94];
    /* 0x230 */ s32 mState;       // 0 = off, 1 = on
    /* 0x234 */ s32 mInputCount;  // Number of 5-bit switch inputs (spawnParam & 0x1F)
};

extern void* lbl_804A8800[];
extern "C" void* fn_802B7890(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A8800;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_802B78F0(void) {}

extern "C" u8* fn_802D6A9C(void);
extern "C" u8 fn_802D800C(void* mgr, u32 id);

static const u32 lbl_8046CB40[4] = {0x7c00000, 0x3e0000, 0x1f000, 0xf80};
static const u32 lbl_8046CB50[4] = {0x16, 0x11, 0xc, 0x7};

extern "C" void fn_802B78F4(SwitchOrRelayActor* this_) {
    s32 i;
    s32 count;
    switch (this_->mState) {
    case 0:
        for (i = 0; i < this_->mInputCount; i++) {
            if (fn_802D800C(fn_802D6A9C(), (this_->mSpawnParam & lbl_8046CB40[i]) >> lbl_8046CB50[i])) {
                this_->s10(0xff, 1);
                this_->mState = 1;
            }
        }
        break;
    case 1:
    default:
        count = 0;
        for (i = 0; i < this_->mInputCount; i++) {
            if (fn_802D800C(fn_802D6A9C(), (this_->mSpawnParam & lbl_8046CB40[i]) >> lbl_8046CB50[i])) {
                count++;
            }
        }
        if (count == 0) {
            this_->s10(0xff, 0);
            this_->mState = 0;
        }
        break;
    }
}

extern "C" void fn_802B7A3C(SwitchOrRelayActor* this_) {
    this_->mState = 0;
    this_->mInputCount = this_->mSpawnParam & 0x1f;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"

static u8 lbl_804D22D4[0x94];
