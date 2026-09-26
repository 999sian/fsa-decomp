// TU 0x802cb1c4-0x802cc1c4 (actor ONOF).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- fn_802CBA78_dtor.cpp ----
extern "C" void* fn_801EE434(void* handle);
extern "C" void dtor_801F593C(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A8FC8[];

extern "C" void* fn_802CBA78(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A8FC8;
        if (*(void**)(p + 0x230) != 0) {
            fn_801EE434(*(void**)(p + 0x230));
        }
        if (*(void**)(p + 0x234) != 0) {
            fn_801EE434(*(void**)(p + 0x234));
        }
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
