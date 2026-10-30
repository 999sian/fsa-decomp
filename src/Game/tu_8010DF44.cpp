// tu_8010DF44: .text 0x8010DF44-0x8010E2D4 — Intermediate Base Class for DMxx Demo/Cutscene Actors.
#include "types.h"

extern "C" void v06__5ActorFv(void* this_);
extern "C" void v03__5ActorFv(void* this_);
extern "C" void v01__5ActorFv(void* this_);
extern "C" void* fn_8011921C(void);
extern "C" void fn_8011888C(void* mgr, void* actor);
extern "C" void fn_80118798(void* mgr, void* actor);
extern "C" void __dt__5ActorFv(void* this_, s16 freeFlag);
void operator delete(void* p);
extern const f32 lbl_8053C510;
extern const f32 lbl_8053C514;
extern const f32 lbl_8053C518;

struct DemoBaseActor {
    /* 0x000 */ void* mVtable;
    /* 0x004 */ u8 _pad04[0x60 - 0x04];
    /* 0x060 */ f32 mBounds60[4];
    /* 0x070 */ u8 _pad70[0x80 - 0x70];
    /* 0x080 */ f32 mBounds80[4];
    /* 0x090 */ u8 _pad90[0x108 - 0x90];
    /* 0x108 */ s32 mSortPriority;
};

extern "C" void fn_8010DF44(void) {}
extern "C" s32 fn_8010DF48(void) { return -1; }
extern "C" s32 fn_8010DF50(void) { return 0; }
extern "C" void fn_8010DF58(void* this_) { v06__5ActorFv(this_); }
extern "C" void fn_8010DF78(void* this_) { v03__5ActorFv(this_); }

extern "C" void fn_8010DF98(DemoBaseActor* this_) {
    v01__5ActorFv(this_);
    fn_8011888C(fn_8011921C(), this_);
    this_->mBounds60[0] = lbl_8053C510;
    this_->mBounds60[1] = lbl_8053C510;
    this_->mBounds60[2] = lbl_8053C514;
    this_->mBounds60[3] = lbl_8053C514;
    this_->mBounds80[0] = lbl_8053C518;
    this_->mBounds80[1] = lbl_8053C518;
    this_->mBounds80[2] = lbl_8053C518;
    this_->mBounds80[3] = lbl_8053C518;
    this_->mSortPriority = 0;
}

extern void* lbl_8049D140[];

extern "C" void* __dt__13Base_8010E074Fv(DemoBaseActor* this_, s16 freeFlag) {
    if (this_ != 0) {
        this_->mVtable = lbl_8049D140;
        fn_80118798(fn_8011921C(), this_);
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void* __ct__5ActorFv(void* this_);
extern "C" void* fn_8010E074(DemoBaseActor* this_) {
    __ct__5ActorFv(this_);
    this_->mVtable = lbl_8049D140;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
