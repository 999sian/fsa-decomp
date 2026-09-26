// TU 0x802ef0a0-0x802ef448 (actor AGBW).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- Agbw_dtor_802EF0A0.cpp ----
extern "C" void dtor_801F593C(void* this_, int how);
extern void* lbl_804AA440[];

extern "C" void* fn_802EF0A0(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804AA440;
        dtor_801F593C(this_, 0);
        if (how > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

// ---- Agbw_EmptyHook.cpp ----
// Agbw_EmptyHook - AGBW: empty no-op override (0x4, leaf, no extab needed)
extern "C" {

void Agbw_EmptyHook(void) {}

}

// fn_802EF104 - AGBW: update(). State 0: once this->0x234 == 0x1f and the
// virtual check (vtable +0x34) passes, enter state 1 with counter
// this->0x23c = this->0x238. State 1: while the counter runs, set the flag
// byte +0x216 of the object at global->0x20; then go back to state 0.
struct AgbwVT {
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
    virtual u8 check();
};
extern void* lbl_8053AB10;

extern "C" void fn_802EF104(void* this_) {
    switch (*(s32*)((char*)this_ + 0x230)) {
    case 0:
        if (*(s32*)((char*)this_ + 0x234) == 0x1f && ((AgbwVT*)this_)->check()) {
            *(s32*)((char*)this_ + 0x230) = 1;
            *(s32*)((char*)this_ + 0x23c) = *(s32*)((char*)this_ + 0x238);
        }
        break;
    case 1:
        if (*(s32*)((char*)this_ + 0x23c) != 0) {
            *(u8*)(*(char**)((char*)lbl_8053AB10 + 0x20) + 0x216) = 1;
            *(s32*)((char*)this_ + 0x23c) = *(s32*)((char*)this_ + 0x23c) - 1;
        } else {
            *(s32*)((char*)this_ + 0x230) = 0;
        }
        break;
    }
}

// ---- RoomSelectorParams_802EF1B4.cpp ----
extern "C" void* fn_802D6A9C(void);
extern "C" u32 fn_802D7870(void*, u32);

// fn_802EF1B4 - AGBW: setParams. Extracts a 5-bit selector into
// this->0x234 and a 12-bit value into this->0x238 from this->0x90;
// queries the per-room config via fn_802D6A9C + fn_802D7870
// (this->0x234); zeroes this->0x230/0x23c; calls own virtual slot 5
// (byte offset 0x14, draw/notify passthrough). See
// [[reference_fsa_virtual_dispatch_codegen_trick]] for why this calls
// through a real `virtual` member rather than a manual cast.
struct ActorSlot5 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void slot5();
};

extern "C" void fn_802EF1B4(void* this_) {
    *(u32*)((char*)this_ + 0x234) = (*(u32*)((char*)this_ + 0x90) >> 22) & 0x1F;
    *(u32*)((char*)this_ + 0x238) = *(u32*)((char*)this_ + 0x90) & 0xFFF;
    void* configRecord = fn_802D6A9C();
    fn_802D7870(configRecord, *(u32*)((char*)this_ + 0x234) & 0xFFFF);
    *(u32*)((char*)this_ + 0x230) = 0;
    *(u32*)((char*)this_ + 0x23c) = 0;
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
