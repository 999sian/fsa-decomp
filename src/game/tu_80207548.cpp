// TU 0x80207548-0x80207d84.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- fn_80207548_dtor.cpp ----
extern "C" void dtor_801F593C(void* this_, int flag);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804A5B28[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

extern "C" void* fn_80207548(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A5B28;
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
