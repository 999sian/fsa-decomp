// TU 0x802223fc-0x80222cc4 (actor ZSLA).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// ---- fn_802223FC_dtor.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A6B70[];
extern void* lbl_804A6A00[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

extern "C" void* fn_802223FC(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A6B70;
        if (this_ != 0) {
            *(void**)p = lbl_804A6A00;
            if (this_ != 0) {
                *(void**)p = lbl_804A4808;
                if (p + 0x270 != 0) {
                    if (p + 0x294 != 0) {
                        *(void**)(p + 0x294) = lbl_8049CC34;
                    }
                }
                __dt__5ActorFv(this_, 0);
            }
        }
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- fn_8022249C.cpp ----
extern "C" void fn_80221250(void* this_);
extern "C" void fn_801CE4E8(void* this_);

// fn_8022249C - ZSLA's own vtable-0x88 override (see extab_80222a58.s
// and project_fsa_growing_area_extension.md). Byte-identical to
// fn_80221BE4/fn_80222D28 (fn_80222190's/fn_8022313C's own 0x88
// overrides): if this->0x248 == 2, calls fn_80221250, else falls
// through to the generic 0x88 default fn_801CE4E8. Confirms ZSLA
// carries the SAME 14-slot growing-area vtable extension (0x60-0x8c)
// as ZSLJ and the 3 previously-anonymous siblings - every other slot
// in ZSLA's vtable (0x54-0x8c) matches the already-landed
// generic/shared values exactly, so this was the only genuinely new
// function needed.
extern "C" void fn_8022249C(void* this_) {
    s32 state = *(s32*)((char*)this_ + 0x248);
    if (state == 2) {
        fn_80221250(this_);
    } else {
        fn_801CE4E8(this_);
    }
}

// ---- Zsla_ctor_80222A58.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* fn_802218C8(void* this_);
extern void* lbl_804A6B70[];

extern "C" void* fn_80222A58(void* this_) {
    fn_802218C8(this_);
    *(void**)this_ = lbl_804A6B70;
    *(s32*)((char*)this_ + 0x2b8) = 0;
    *(s32*)((char*)this_ + 0x2bc) = 0;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
