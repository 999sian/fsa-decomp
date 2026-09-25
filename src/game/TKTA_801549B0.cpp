// TKTA_801549B0: .text 0x801549B0-0x801555D8 (actor TKTA)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

// ---- from Game/fn_801549B0_dtor.cpp

extern "C" void dtor_801F593C(void* this_, int flag);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_8049FD50[];

extern "C" void* fn_801549B0(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049FD50;
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- from Game/fn_80154A10.cpp

extern "C" void* SpatialRegistry_GetBase();
extern "C" void fn_801F8544(void* base, u32 fourCC, u32 owner, void* posPtr, s32 flag);
extern "C" void fn_801F9484(void* base, u32 fourCC, u32 owner, void* posPtr, s32 a, s32 b, s32 c);
extern "C" void fn_801F4F28(void* this_);

extern "C" void fn_80154A10(void* this_) {
    char* p = (char*)this_;
    *(s32*)(p + 0x18c) = 0;
    if (*(u32*)(p + 0x90) != 0) {
        void* base = SpatialRegistry_GetBase();
        fn_801F8544(base, 0x52555059, *(u32*)(p + 0x4), p + 0xc, 3);
    } else {
        void* base = SpatialRegistry_GetBase();
        fn_801F9484(base, 0x48415254, *(u32*)(p + 0x4), p + 0xc, 0, -1, -1);
    }
    fn_801F4F28(this_);
}
