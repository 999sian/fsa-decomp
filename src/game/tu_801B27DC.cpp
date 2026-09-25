// Game TU 801B27DC-801B3F60 (unnamed). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"

extern "C" void dtor_801F593C(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A3698[];
extern u8 lbl_8053ABE8;
extern u8 lbl_8053ABF0;

extern "C" void* fn_801B3CD0(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A3698;
        lbl_8053ABE8 = 0;
        lbl_8053ABF0 = 0;
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}
