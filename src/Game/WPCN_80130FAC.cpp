// WPCN_80130FAC: .text 0x80130FAC-0x80131D98 (actor WPCN)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

// ---- from Game/fn_80131A70_dtor.cpp

extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049EAE0[];
extern void* lbl_8049CC34[];

extern "C" void* fn_80131A70(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_8049EAE0;
        if (p + 0x230 != 0) {
            if (p + 0x254 != 0) {
                *(void**)(p + 0x254) = lbl_8049CC34;
            }
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
