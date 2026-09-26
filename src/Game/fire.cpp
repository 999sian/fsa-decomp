// TU 0x802ba558-0x802bc83c (actor FIRE).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

#undef ALIGN_NEXT
#undef ALIGN_PREV
#undef ARRAY_SIZE
#undef ASM
#undef ATTRIBUTE_ALIGN
#undef IS_ALIGNED
#undef IS_NOT_ALIGNED
#undef MACROS_H
#undef MAX
#undef MIN
#undef NULL
#define NULL 0
#ifndef unknown
#define unknown jsys_unknown
#endif
#include "JSystem/JGeometry/Vec.h"

// FIRE: small accessors.
extern "C" s32 fn_802BA9F0(char* p) { return *(s32*)(p + 0x260); }
extern "C" s32 fn_802BA9F8(char* p) { return *(s32*)(p + 0x264); }
extern "C" void fn_802BAA00(char* p) { *(u8*)(p + 0x11c) = 0; }

// fn_802BAB80 - FIRE: snap back to the saved position, or play the
// extinguish sound and delete.
struct FireVec { f32 x, y, z; };
struct FireVT {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void kill();
};
extern "C" void fn_801F0E34(void* this_, s32 p1, s32 p2);
extern "C" void fn_802BAB80(char* p) {
    if (*(u8*)(p + 0x291) == 1) {
        *(JGeometry::TVec3<f32>*)(p + 0xc) = *(JGeometry::TVec3<f32>*)(p + 0x248);
    } else {
        fn_801F0E34(p, 0x3002e, 0);
        ((FireVT*)p)->kill();
    }
}

// ---- fn_802BBDFC_dtor.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void dtor_80084580(void* this_);
extern "C" void fn_801EE434(void* handle);
extern void* lbl_804A89F0[];

extern "C" void* fn_802BBDFC(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A89F0;
        char* p = (char*)this_;
        void* h1 = *(void**)(p + 0x230);
        if (h1 != 0) {
            fn_801EE434(h1);
        }
        void* h2 = *(void**)(p + 0x234);
        if (h2 != 0) {
            fn_801EE434(h2);
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// Shared JAudio pool __sinit (docs/game/sinit_pools.md). Drop the ESD
// macros/typedefs that clash with the JSystem headers first.
#undef ALIGN_NEXT
#undef ALIGN_PREV
#undef ARRAY_SIZE
#undef ASM
#undef ATTRIBUTE_ALIGN
#undef IS_ALIGNED
#undef IS_NOT_ALIGNED
#undef MACROS_H
#undef MAX
#undef MIN
#undef NULL
#define NULL 0
#define unknown jsys_unknown
#include "JSystem/JAudio/JASFakeMatchFSA.h"
