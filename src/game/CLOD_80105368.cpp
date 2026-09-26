// CLOD_80105368: .text 0x80105368-0x80105DD4 (actor CLOD)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

// ---- from Game/fn_80105368_dtor.cpp

extern "C" void dtor_801F593C(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049CBE0[];
extern void* lbl_8049CC34[];

extern "C" void* fn_80105368(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_8049CBE0;
        if (p + 0x374 != 0) {
            if (p + 0x398 != 0) {
                *(void**)(p + 0x398) = lbl_8049CC34;
            }
        }
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- from Game/dtor_80105D80.cpp

#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049CC34[];

extern "C" void* dtor_80105D80(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        if (p + 0x24 != 0) {
            *(void**)(p + 0x24) = lbl_8049CC34;
        }
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}
