// TU 0x802BF03C-0x802BF410 — Random 1-of-4 Switch Selector Actor.
#include "types.h"

void operator delete(void* p);
extern "C" void __dt__5ActorFv(void* this_, int how);

struct RandomSwitchActor {
    virtual void s00(); virtual void s01(); virtual void s02(); virtual void s03();
    virtual void s04(); virtual void s05(); virtual void s06(); virtual void s07();
    virtual void s08(); virtual void s09();
    virtual void s10(s32 a, s32 b);
    virtual u8 s11();

    /* 0x004 */ u8 _pad04[0x90 - 0x04];
    /* 0x090 */ u32 mSpawnParam;
    /* 0x094 */ u8 _pad94[0x11C - 0x94];
    /* 0x11C */ u8 mActiveFlag;
    /* 0x11D */ u8 _pad11D[0x230 - 0x11D];
    /* 0x230 */ s32 mState;          // 0 = ready, 1 = waiting for s11() release
    /* 0x234 */ s32 mCompletionMode; // 0 = detach, 1 = re-armable, 2 = deactivate (spawnParam & 0x1F)
};

extern void* lbl_804A8BD0[];
extern "C" void* fn_802BF03C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A8BD0;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_802BF09C(void) {}

extern "C" s32 fn_801CD664(s32 n);
extern "C" u8* fn_802D6A9C(void);
extern "C" void fn_802D8050(void* mgr, u32 id, s32 a, s32 b);
extern "C" void detach__5ActorFv(void* this_);

static const u32 lbl_8046D460[4] = {0x16, 0x11, 0xc, 0x7};

extern "C" void fn_802BF0A0(RandomSwitchActor* this_) {
    switch (this_->mState) {
    case 0:
        if ((this_->mSpawnParam >> 27) == 0 || this_->s11() == 1) {
            s32 r = fn_801CD664(100) & 3;
            u32 id = (this_->mSpawnParam >> lbl_8046D460[r]) & 0x1f;
            fn_802D8050(fn_802D6A9C(), id, 1, 0xff);
            s32 mode = this_->mCompletionMode;
            if (mode == 0) {
                detach__5ActorFv(this_);
            } else if (mode == 1) {
                this_->mState = 1;
            } else if (mode == 2) {
                this_->mActiveFlag = 0;
            }
        }
        break;
    case 1:
        if (!this_->s11()) {
            this_->mState = 0;
        }
        break;
    }
}

extern "C" void fn_802BF1AC(RandomSwitchActor* this_) {
    this_->mCompletionMode = this_->mSpawnParam & 0x1f;
    this_->mState = 0;
    this_->s03();
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"

static u8 lbl_804D2DD4[0x94];
