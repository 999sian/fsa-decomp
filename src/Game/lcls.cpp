// TU 0x802e8dfc-0x802e910c (actor LCLS).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// ---- Lcls_dtor_802E8DFC.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int how);
extern void* lbl_804AA008[];

extern "C" void* fn_802E8DFC(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804AA008;
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

// ---- Lcls_EmptyHook.cpp ----
// Lcls_EmptyHook - LCLS: empty no-op override (0x4, leaf, no extab needed)
extern "C" {

void Lcls_EmptyHook(void) {}

}

// ---- RoomBitfieldNotify_802E8E60.cpp ----
extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802D7F40(void*, u32);

// fn_802E8E60 - LCLS: setParams. Calls fn_802D6A9C then
// fn_802D7F40 with a bitfield extracted from this->0x90; if the query
// returns true, notifies via own virtual slot 12 (byte offset 0x30)
// with args (0xff, 1). See
// [[reference_fsa_virtual_dispatch_codegen_trick]] for why this calls
// through a real `virtual` member rather than a manual cast.
struct ActorSlot12 {
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
    virtual void slot12(u32 a, u32 b);
};

extern "C" void fn_802E8E60(void* this_) {
    void* configRecord = fn_802D6A9C();
    u32 field = (*(u32*)((char*)this_ + 0x90) >> 22) & 0x1F;
    if ((u8)fn_802D7F40(configRecord, field) != 0) {
        ((ActorSlot12*)this_)->slot12(0xff, 1);
    }
}

// ---- VtableForward_802E8EBC.cpp ----
// LCLS: forwarding wrapper - calls own virtual slot 5 (byte offset
// 0x14, "draw/notify passthrough"). See
// [[reference_fsa_virtual_dispatch_codegen_trick]] for why this calls
// through a real `virtual` member rather than a manual cast.
struct ActorSlot5 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void slot5();
};

extern "C" void fn_802E8EBC(void* this_) {
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
#undef MACROS_H
#undef MAX
#undef MIN
#undef NULL
#define NULL 0
#define unknown jsys_unknown
#include "JSystem/JAudio/JASFakeMatchFSA.h"
