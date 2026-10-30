// tu_8011A0F8: .text 0x8011A0F8-0x8011A4BC — Cutscene/Demo Trigger Actor (30-Frame Delayed Trigger).
#include "types.h"

extern "C" void v03__5ActorFv(void* this_);
extern "C" void v01__5ActorFv(void* this_);
extern "C" u8* fn_8011921C(void);
extern "C" u8 fn_801186B0(u8* mgr, s32 id);
extern "C" void __dt__5ActorFv(void* this_, s16 freeFlag);
void operator delete(void* p);
extern void* lbl_8049DAD8[];

class tu_8011A0F8_Actor {
public:
    virtual void vf08(); virtual void vf0C(); virtual void vf10(); virtual void vf14();
    virtual void vf18(); virtual void vf1C(); virtual void vf20(); virtual void vf24();
    virtual void vf28(); virtual void vf2C(); virtual void vf30();
    virtual u8 vf34();

    /* 0x004 */ u8 _pad04[0x90 - 0x04];
    /* 0x090 */ u32 mSpawnParam;
    /* 0x094 */ u8 _pad94[0x230 - 0x94];
    /* 0x230 */ s32 mEventId;     // Unpacked from spawnParam & 0x1F
    /* 0x234 */ s32 mDelayTimer;  // Counts to 30 once armed
    /* 0x238 */ u8 mIsArmed;
    /* 0x239 */ u8 mHasFired;
};

extern "C" void fn_8011A0F8(tu_8011A0F8_Actor* this_) {
    v03__5ActorFv(this_);
    if (this_->mHasFired != 0) {
        return;
    }
    if (this_->mIsArmed != 0) {
        this_->mDelayTimer++;
        if (this_->mDelayTimer >= 30) {
            if (*fn_8011921C() != 0) {
                return;
            }
            if (!fn_801186B0(fn_8011921C(), this_->mEventId)) {
                return;
            }
            this_->mHasFired = 1;
        }
    }
    if ((this_->mSpawnParam & 0xF8000000) != 0) {
        if (this_->vf34()) {
            this_->mIsArmed = 1;
        }
    }
}

extern "C" void fn_8011A1B0(tu_8011A0F8_Actor* this_) {
    v01__5ActorFv(this_);
    this_->mEventId = this_->mSpawnParam & 0x1F;
}

extern "C" void* fn_8011A1E8(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049DAD8;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void* __ct__5ActorFv(void*);
extern "C" void* fn_8011A248(tu_8011A0F8_Actor* this_) {
    __ct__5ActorFv(this_);
    *(void**)this_ = lbl_8049DAD8;
    this_->mEventId = 0;
    this_->mDelayTimer = 0;
    this_->mIsArmed = 0;
    this_->mHasFired = 0;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
