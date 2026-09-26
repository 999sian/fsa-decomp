// TU 0x8022461c-0x80226fc8.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"

// ---- fn_802265DC.cpp ----
// fn_802265DC - trivial thin wrapper: tail-calls not-yet-seen fn_802260DC
// with its arguments unchanged and returns its result. Sibling of
// fn_801CE800's fn_802265FC (extab_801ce800.s) - both sit in the same
// 0x80226xxx cluster.
extern "C" s32 fn_802260DC(void* this_);

extern "C" s32 fn_802265DC(void* this_) {
    return fn_802260DC(this_);
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
