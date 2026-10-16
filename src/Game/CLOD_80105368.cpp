// CLOD_80105368: .text 0x80105368-0x80105DD4 (actor CLOD)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"
#include "JSystem/JGeometry/Vec.h"

extern "C" void v06__5ActorFv(void* this_);
extern "C" void fn_802F745C(void* mgr, JGeometry::TVec3f* pos, s32 id, void* out);
extern char* lbl_8053AB10;
extern const f32 lbl_8053C23C;
extern "C" void __ct__5ActorFv(void* this_);
extern "C" void fn_801D267C(void* anim);
extern void* lbl_8049CBE0[];
extern const f32 lbl_8053C228;

extern "C" void fn_80105654(char* p) {
    v06__5ActorFv(p);
    p[0x325] = -1;
    s32 idx = *(s32*)(p + 0x390);
    JGeometry::TVec3f pos = *(JGeometry::TVec3f*)(p + 0xc);
    if (*(s32*)(p + 0x36c) == 2) {
        pos.y -= lbl_8053C23C;
    }
    s32 id = ((s32*)(p + 0x2f8))[idx];
    if (*(s32*)(p + 0x4) < 8) {
        fn_802F745C(*(void**)(lbl_8053AB10 + 0x20), &pos, id, p + 0x308);
    }
}

// ---- from Game/fn_80105368_dtor.cpp

extern "C" void __dt__5ActorFv(void* this_, int flag);
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
        __dt__5ActorFv(this_, 0);
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

extern "C" void* __dt__7AnimSubFv(void* this_, s16 freeFlag) {
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
