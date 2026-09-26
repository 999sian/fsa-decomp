// Game TU 801B3F60-801B4D0C (ZDCO). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A375C[];
extern "C" {
}

extern "C" void* fn_801B3F60(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A375C;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_801B3FC0(void) {}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
