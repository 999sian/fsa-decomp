// tu_8013C5C8: .text 0x8013C5C8-0x8013F9A8
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

// ---- from Game/dtor_8013C5C8.cpp

extern "C" void fn_800EB208(void* this_, s32 flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049F140[];

extern "C" void* dtor_8013C5C8(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049F140;
        fn_800EB208(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- from Game/fn_8013C86C_dtor.cpp

extern "C" void fn_800EB208(void* this_, s32 flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049F15C[];

extern "C" void* fn_8013C86C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049F15C;
        fn_800EB208(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- from Game/fn_8013D5B0.cpp

// fn_8013D5B0(this) - the first method of the this->0x28 sub-object's own
// class (forward-referenced from fn_8013B4C0/fn_8013B71C/etc in the
// camera-cue-manager cluster; this class's own dtor is dtor_8013C5C8,
// already landed). Thin forwarder: fn_800EC188(this->0xc).
extern "C" s32 fn_800EC188(void* subObj);

extern "C" s32 fn_8013D5B0(void* this_) {
    return fn_800EC188(*(void**)((char*)this_ + 0xc));
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
