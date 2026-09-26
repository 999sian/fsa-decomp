// tu_8010DF44: .text 0x8010DF44-0x8010E2D4
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
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

extern "C" void fn_8010DF44(void) {}

extern "C" s32 fn_8010DF48(void) { return -1; }

extern "C" s32 fn_8010DF50(void) { return 0; }

extern "C" void fn_8010DF58(void* this_) { v06__5ActorFv(this_); }

extern "C" void fn_8010DF78(void* this_) { v03__5ActorFv(this_); }

extern "C" void fn_8010DF98(u8* this_) {
    v01__5ActorFv(this_);
    fn_8011888C(fn_8011921C(), this_);
    *(f32*)(this_ + 0x60) = lbl_8053C510;
    *(f32*)(this_ + 0x64) = lbl_8053C510;
    *(f32*)(this_ + 0x68) = lbl_8053C514;
    *(f32*)(this_ + 0x6C) = lbl_8053C514;
    *(f32*)(this_ + 0x80) = lbl_8053C518;
    *(f32*)(this_ + 0x84) = lbl_8053C518;
    *(f32*)(this_ + 0x88) = lbl_8053C518;
    *(f32*)(this_ + 0x8C) = lbl_8053C518;
    *(s32*)(this_ + 0x108) = 0;
}

extern void* lbl_8049D140[];

extern "C" void* __dt__13Base_8010E074Fv(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049D140;
        fn_80118798(fn_8011921C(), this_);
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

// ---- from Game/fn_8010E074_ctor.cpp
extern "C" void* __ct__5ActorFv(void* this_);
extern "C" void* fn_8010E074(void* this_) {
    __ct__5ActorFv(this_);
    *(void**)this_ = lbl_8049D140;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
