// TU 0x8032ab80-0x8032df94 (actor RUPY).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- fn_8032AB80_dtor.cpp ----
extern "C" void dtor_801F593C(void* this_, int flag);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804AB6D8[];

extern "C" void* fn_8032AB80(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AB6D8;
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- FlagClear_8032D660.cpp ----
// fn_8032D660(this) - RUPY's (Rupee) vtable slot override. Gated on
// this->0x94 (a halfword) being exactly 0x19 or 0x1a - likely a
// rupee-color/value subtype range. When in that range, makes a
// virtual call through its own vtable slot 13 (byte offset 0x34,
// shared with many other actors); if that call returns true, clears
// this->0x280 (a byte flag - plausibly "is still collectible/active",
// given RUPY's role as a pickup). See
// [[reference_fsa_virtual_dispatch_codegen_trick]] for why this calls
// through a real `virtual` member rather than a manual cast.
struct ActorSlot13 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual u8 slot13();
};

extern "C" void fn_8032D660(void* this_) {
    u16 subtype = *(u16*)((char*)this_ + 0x94);
    if (subtype == 0x19 || subtype == 0x1a) {
        if (((ActorSlot13*)this_)->slot13() != 0) {
            *(u8*)((char*)this_ + 0x280) = 0;
        }
    }
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
