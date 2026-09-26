// OIWA_800F4C70: .text 0x800F4C70-0x800F6820 (actor OIWA)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

// ---- from Game/fn_800F659C_dtor.cpp

extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049C4C0[];

extern "C" void* fn_800F659C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049C4C0;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

extern "C" u32 fn_8022461C(void* p);
extern "C" u8 fn_802265DC(void* a, void* b, u32 c);

extern "C" u8 fn_800F51D8(void* this_, void* a, void* b) {
    s32 kind = (u16)fn_8022461C(b);
    if (kind == 3 || kind == 14 || kind == 2) {
        return 0;
    }
    return fn_802265DC(b, a, 0);
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
