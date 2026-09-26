// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 801A35AC-801A3C50 (ENBZ). Remaining functions are not yet decompiled.
#include "types.h"

// from src/Game/fn_801A35AC_dtor.cpp
extern "C" void dtor_801F593C(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A2CB0[];

extern "C" void* fn_801A35AC(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A2CB0;
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// from src/Game/stub_801a360c.cpp
// ENBZ cluster, part 2/4. fn_801A360C - empty override (bare blr), no
// extab. Likely a "do nothing" draw() or similar no-op virtual.
extern "C" {

void fn_801A360C(void) {}

}


#include "JSystem/JAudio/JASFakeMatchFSA.h"
