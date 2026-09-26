// TU 0x802e910c-0x802e9428 (actor GLBS).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- Glbs_dtor_802E910C.cpp ----
extern "C" void dtor_801F593C(void* this_, int how);
extern void* lbl_804AA060[];

extern "C" void* fn_802E910C(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804AA060;
        dtor_801F593C(this_, 0);
        if (how > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

// ---- Glbs_EmptyHook.cpp ----
// Glbs_EmptyHook - GLBS: empty no-op override (0x4, leaf, no extab needed)
extern "C" {

void Glbs_EmptyHook(void) {}

}

// ---- RoomBitfieldWriteback_802E9170.cpp ----
extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802D800C(void*, u32);
extern "C" void fn_802D7F84(void*, u32, u32);

// fn_802E9170 - GLBS: setParams. Calls fn_802D6A9C then
// fn_802D800C with a bitfield extracted from this->0x90; if the query
// returns true, reads a value via own virtual slot 15 (byte offset
// 0x3c) and writes it back to the room config via fn_802D6A9C
// + fn_802D7F84(value, 1). See
// [[reference_fsa_virtual_dispatch_codegen_trick]] for why this calls
// through a real `virtual` member rather than a manual cast.
struct ActorSlot15 {
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
    virtual void v11();
    virtual void v12();
    virtual u32 slot15();
};

extern "C" void fn_802E9170(void* this_) {
    void* configRecord = fn_802D6A9C();
    u32 field = (*(u32*)((char*)this_ + 0x90) >> 22) & 0x1F;
    if ((u8)fn_802D800C(configRecord, field) != 0) {
        u32 val = ((ActorSlot15*)this_)->slot15();
        void* configRecord2 = fn_802D6A9C();
        fn_802D7F84(configRecord2, val, 1);
    }
}

// ---- VtableForward_802E91D8.cpp ----
// GLBS: forwarding wrapper - calls own virtual slot 5 (byte offset
// 0x14, "draw/notify passthrough"). See
// [[reference_fsa_virtual_dispatch_codegen_trick]] for why this calls
// through a real `virtual` member rather than a manual cast.
struct ActorSlot5 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void slot5();
};

extern "C" void fn_802E91D8(void* this_) {
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
