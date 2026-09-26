// TU 0x80221b44-0x802223fc.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- fn_80221B44_dtor.cpp ----
extern "C" void dtor_801F593C(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A6AA8[];
extern void* lbl_804A6A00[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

extern "C" void* fn_80221B44(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A6AA8;
        if (this_ != 0) {
            *(void**)p = lbl_804A6A00;
            if (this_ != 0) {
                *(void**)p = lbl_804A4808;
                if (p + 0x270 != 0) {
                    if (p + 0x294 != 0) {
                        *(void**)(p + 0x294) = lbl_8049CC34;
                    }
                }
                dtor_801F593C(this_, 0);
            }
        }
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- fn_80221BE4.cpp ----
extern "C" void fn_80221250(void* this_);
extern "C" void fn_801CE4E8(void* this_);

// fn_80221BE4 - fn_80222190's own vtable-0x88 override (see
// extab_80221b44.s and project_fsa_growing_area_extension.md). If
// this->0x248 == 2 (a specific state), calls fn_80221250 (a
// not-further-decompiled "already settled" behavior); otherwise falls
// through to the generic 0x88 default fn_801CE4E8 (direction-vector
// update + growth-step chain).
extern "C" void fn_80221BE4(void* this_) {
    s32 state = *(s32*)((char*)this_ + 0x248);
    if (state == 2) {
        fn_80221250(this_);
    } else {
        fn_801CE4E8(this_);
    }
}

// ---- fn_80222190_ctor.cpp ----
extern "C" void* fn_802218C8(void* this_);
extern void* lbl_804A6AA8[];

extern "C" void* fn_80222190(void* this_) {
    fn_802218C8(this_);
    char* p = (char*)this_;
    *(void**)p = lbl_804A6AA8;
    *(s32*)(p + 0x2b8) = 0;
    *(char*)(p + 0x2c8) = 0;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
