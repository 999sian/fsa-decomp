// TU 0x802188b0-0x80218cf4.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// ---- fn_80218A8C.cpp ----
extern "C" s32 fn_801CD664(s32 range);

// fn_80218A8C(this) - zeroes +0x0, then sets a randomized u16 at +0x4
// via the confirmed fn_801CD664 PRNG helper (see
// reference_fsa_global_prng.md): a random int in [0x3c,0x3c+0x79) =
// [60,181]. Embedded by SLK2 at its own +0x540.
extern "C" void* fn_80218A8C(void* this_) {
    *(s32*)((char*)this_ + 0x0) = 0;
    s32 r = fn_801CD664(0x79);
    *(u16*)((char*)this_ + 0x4) = (u16)(r + 0x3c);
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
