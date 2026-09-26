// TU 0x80329468-0x8032ab80 (actor GNLD).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// ---- Gold_dtor_8032A8E0.cpp ----
extern "C" void fn_801EE434(void* handle);
extern "C" void __dt__5ActorFv(void* this_, int how);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804AB660[];

// GOLD cluster, part 5/6. Destructor - culls 3 handles (this+0x24c/0x250/
// 0x254) via the confirmed fn_801EE434, then the shared base dtor
// __dt__5ActorFv plus a conditional second-base dtor dtor_80084580.
extern "C" void* Gold_dtor(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804AB660;
        fn_801EE434(*(void**)((char*)this_ + 0x24c));
        fn_801EE434(*(void**)((char*)this_ + 0x250));
        fn_801EE434(*(void**)((char*)this_ + 0x254));
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
