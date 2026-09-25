// TU 0x80222cc4-0x802233a4.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- fn_80222CC4.cpp ----
extern "C" void fn_80221184(void* this_);
extern "C" void* SpatialRegistry_GetBase();
extern "C" void* fn_801F666C(void* base, s32 id);

extern "C" void fn_80222CC4(void* this_) {
    fn_80221184(this_);
    char* p = (char*)this_;
    s32 id = *(s32*)(p + 0x2b8);
    if (id >= 0) {
        void* base = SpatialRegistry_GetBase();
        void* found = fn_801F666C(base, id);
        if (found != 0) {
            *(s32*)((char*)found + 0x108) = 0;
        }
        *(s32*)(p + 0x2b8) = -1;
    }
}

// ---- fn_80222D28.cpp ----
extern "C" void fn_80221250(void* this_);
extern "C" void fn_801CE4E8(void* this_);

// fn_80222D28 - fn_8022313C's own vtable-0x88 override (see
// extab_80223060.s and project_fsa_growing_area_extension.md).
// Byte-identical logic to fn_80221BE4 (fn_80222190's own 0x88): if
// this->0x248 == 2, calls fn_80221250, else falls through to the
// generic 0x88 default fn_801CE4E8.
extern "C" void fn_80222D28(void* this_) {
    s32 state = *(s32*)((char*)this_ + 0x248);
    if (state == 2) {
        fn_80221250(this_);
    } else {
        fn_801CE4E8(this_);
    }
}

// ---- fn_80223060_dtor.cpp ----
extern "C" void* SpatialRegistry_GetBase();
extern "C" void* fn_801F666C(void* base, s32 id);
extern "C" void dtor_801F593C(void* this_, int flag);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804A6C38[];
extern void* lbl_804A6A00[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

extern "C" void* fn_80223060(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A6C38;
        s32 id = *(s32*)(p + 0x2b8);
        if (id >= 0) {
            void* base = SpatialRegistry_GetBase();
            void* found = fn_801F666C(base, id);
            if (found != 0) {
                *(s32*)((char*)found + 0x108) = 0;
            }
            *(s32*)(p + 0x2b8) = -1;
        }
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

// ---- fn_8022313C_ctor.cpp ----
extern "C" void* fn_802218C8(void* this_);
extern void* lbl_804A6C38[];

extern "C" void* fn_8022313C(void* this_) {
    fn_802218C8(this_);
    char* p = (char*)this_;
    *(void**)p = lbl_804A6C38;
    *(s32*)(p + 0x2b8) = -1;
    return this_;
}
