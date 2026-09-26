// TU 0x802e40a8-0x802e43e0 (actor SENP).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- fn_802E40A8_dtor.cpp ----
extern "C" void dtor_801F593C(void* this_, int flag);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804A9C78[];

extern "C" void* fn_802E40A8(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A9C78;
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- Senp_EmptyHook.cpp ----
// SENP cluster, part 2/4. Senp_EmptyHook - empty override (bare blr), no
// extab.
extern "C" {

void Senp_EmptyHook(void) {}

}

// ---- SpawnParamBits_802E416C.cpp ----
// SENP cluster, part 4/4. setParams-like - extracts 3 bitfields from
// the spawn parameter (this->0x90) into this->0x234/0x238/0x23c, then
// makes a virtual call to this object's own vtable slot 5 (byte
// offset 0x14). See [[reference_fsa_virtual_dispatch_codegen_trick]]
// for why this calls through a real `virtual` member rather than a
// manual cast.
struct ActorSlot5 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void slot5();
};

extern "C" void fn_802E416C(void* this_) {
    *(u32*)((char*)this_ + 0x234) = *(u32*)((char*)this_ + 0x90) & 0xFFF;
    *(u32*)((char*)this_ + 0x238) = (*(u32*)((char*)this_ + 0x90) >> 24) & 0x7;
    *(u8*)((char*)this_ + 0x23c) = (*(u32*)((char*)this_ + 0x90) >> 23) & 0x1;
    ((ActorSlot5*)this_)->slot5();
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
#undef MAX
#undef MIN
#undef NULL
#define NULL 0
#define unknown jsys_unknown
#include "JSystem/JAudio/JASFakeMatchFSA.h"
