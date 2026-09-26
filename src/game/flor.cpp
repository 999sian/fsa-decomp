// TU 0x8020db74-0x8020f798 (actor FLOR).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- fn_8020F474_dtor.cpp ----
extern "C" void* fn_801EE434(void* handle);
extern "C" void dtor_801F593C(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A6004[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

extern "C" void* fn_8020F474(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A6004;
        fn_801EE434(*(void**)(p + 0x2b0));
        if (this_ != 0) {
            *(void**)p = lbl_804A4808;
            if (p + 0x270 != 0) {
                if (p + 0x294 != 0) {
                    *(void**)(p + 0x294) = lbl_8049CC34;
                }
            }
            dtor_801F593C(this_, 0);
        }
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
