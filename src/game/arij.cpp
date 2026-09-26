// TU 0x80212e3c-0x80213e00 (actor ARIJ).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"

// ---- fn_80212E3C_dtor.cpp ----
extern "C" void dtor_801F593C(void* this_, int flag);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804A6340[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

extern "C" void* fn_80212E3C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A6340;
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

// ---- fn_80212ECC.cpp ----
extern "C" void fn_80213774(void* this_, s32 state);

// fn_80212ECC(this) - called from RUSA's setParams (extab_80212288.s)
// on sub-variant 0, once the spawned ARIJ child handle is confirmed
// valid. Picks a behavior state via fn_80213774(this, state): state 0
// if flag bit 17 of this->0x230 is set, otherwise state 2 (unless the
// current state this->0x248 is already 2, in which case does
// nothing).
extern "C" void fn_80212ECC(void* this_) {
    s32 flags = *(s32*)((char*)this_ + 0x230);
    if (flags & 0x4000) {
        fn_80213774(this_, 0);
    } else {
        if (*(s32*)((char*)this_ + 0x248) != 2) {
            fn_80213774(this_, 2);
        }
    }
}

// ---- fn_80212F14.cpp ----
extern "C" void fn_80213774(void* this_, s32 state);

// fn_80212F14(this) - sibling of fn_80212ECC: same flag-bit-17 gate,
// but the "not yet in this state" target is state 1 (this->0x248==1
// check) instead of state 2.
extern "C" void fn_80212F14(void* this_) {
    s32 flags = *(s32*)((char*)this_ + 0x230);
    if (flags & 0x4000) {
        fn_80213774(this_, 0);
    } else {
        if (*(s32*)((char*)this_ + 0x248) != 1) {
            fn_80213774(this_, 1);
        }
    }
}

// ---- fn_80212FF4.cpp ----
extern "C" void* SpatialRegistry_GetBase();
extern "C" void* fn_801F666C(void* base, s32 id);
extern "C" void fn_80210D90(void* companion);
extern "C" void fn_801F4F28(void* this_);

extern "C" void fn_80212FF4(void* this_) {
    s32 id = *(s32*)((char*)this_ + 0x90);
    if (id >= 0) {
        void* base = SpatialRegistry_GetBase();
        void* found = fn_801F666C(base, id);
        if (found != 0) {
            fn_80210D90(found);
        }
    }
    fn_801F4F28(this_);
}

// ---- fn_80213050.cpp ----
extern "C" void fn_80213774(void* this_, s32 state);

// fn_80213050(this) - a 3-condition gate on the same RUSA-repel state
// machine as fn_80212ECC/fn_80212F14: if this->0xd4==1 AND
// this->0x248!=0 AND flag bit 17 of this->0x230 is clear, transitions
// to state 4 via fn_80213774.
extern "C" void fn_80213050(void* this_) {
    u8 flag = *(u8*)((char*)this_ + 0xd4);
    if (flag != 1) {
        return;
    }
    if (*(s32*)((char*)this_ + 0x248) == 0) {
        return;
    }
    s32 flags = *(s32*)((char*)this_ + 0x230);
    if (flags & 0x4000) {
        return;
    }
    fn_80213774(this_, 4);
}

// ---- Arij_ctor_80213BA0.cpp ----
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* fn_801D0F40(void* this_);
extern void* lbl_804A6340[];

extern "C" void* fn_80213BA0(void* this_) {
    fn_801D0F40(this_);
    *(void**)this_ = lbl_804A6340;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
