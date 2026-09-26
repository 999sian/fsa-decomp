// tu_8010DF44: .text 0x8010DF44-0x8010E2D4
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

extern "C" void fn_801F5778(void* this_);
extern "C" void fn_801F5930(void* this_);
extern "C" void fn_801F5938(void* this_);
extern "C" void* fn_8011921C(void);
extern "C" void fn_8011888C(void* mgr, void* actor);
extern "C" void fn_80118798(void* mgr, void* actor);
extern "C" void dtor_801F593C(void* this_, s16 freeFlag);
void operator delete(void* p);
extern const f32 lbl_8053C510;
extern const f32 lbl_8053C514;
extern const f32 lbl_8053C518;

extern "C" void fn_8010DF44(void) {}

extern "C" s32 fn_8010DF48(void) { return -1; }

extern "C" s32 fn_8010DF50(void) { return 0; }

extern "C" void fn_8010DF58(void* this_) { fn_801F5778(this_); }

extern "C" void fn_8010DF78(void* this_) { fn_801F5930(this_); }

extern "C" void fn_8010DF98(u8* this_) {
    fn_801F5938(this_);
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

extern "C" void* dtor_8010E004(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049D140;
        fn_80118798(fn_8011921C(), this_);
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

// ---- from Game/fn_8010E074_ctor.cpp
extern "C" void* fn_801F5AE0(void* this_);
extern "C" void* fn_8010E074(void* this_) {
    fn_801F5AE0(this_);
    *(void**)this_ = lbl_8049D140;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
