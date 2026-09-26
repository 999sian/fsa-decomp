// TU 0x802e1b40-0x802e2074 (actor OFFS).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- fn_802E1B40_dtor.cpp ----
extern "C" void dtor_801F593C(void* this_, int flag);
extern void* lbl_804A9B70[];

extern "C" void* fn_802E1B40(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A9B70;
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

// ---- Offs_EmptyHook.cpp ----
// OFFS cluster, part 2/4. Offs_EmptyHook - empty override (bare blr), no
// extab.
extern "C" {

void Offs_EmptyHook(void) {}

}

// ---- OffsRoomFlagDispatch_802E1BA4.cpp ----
// fn_802E1BA4 - OFFS: a nested-switch room-flag dispatcher, gated by
// own vtable slot 13 (byte offset 0x34, the shared "am I active"
// check) at each leaf. Outer switch on this->0x230 (0/1); state 0
// further dispatches on this->0x234 (0-4), each variant calling
// fn_802D6A9C + fn_802D8050(this->0x238, mode, 0xff) with a
// different mode-selection/state-write pattern per sub-case; state 1
// dispatches on the same field (0 or 2 only) and resets this->0x230
// to 0 on gate failure. See
// [[reference_fsa_virtual_dispatch_codegen_trick]] for why the gate
// calls through a real `virtual` member rather than a manual cast.
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D8050(void*, s32, s32, s32);

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

extern "C" void fn_802E1BA4(void* this_) {
    s32 state = *(s32*)((char*)this_ + 0x230);
    switch (state) {
    case 0: {
        s32 sub = *(s32*)((char*)this_ + 0x234);
        switch (sub) {
        case 0:
            if (((ActorSlot13*)this_)->slot13() != 0) {
                void* cr = fn_802D6A9C();
                fn_802D8050(cr, *(s32*)((char*)this_ + 0x238), 0, 0xff);
                *(s32*)((char*)this_ + 0x230) = 1;
            }
            break;
        case 1:
            if (((ActorSlot13*)this_)->slot13() != 0) {
                void* cr = fn_802D6A9C();
                fn_802D8050(cr, *(s32*)((char*)this_ + 0x238), 0, 0xff);
            } else {
                void* cr = fn_802D6A9C();
                fn_802D8050(cr, *(s32*)((char*)this_ + 0x238), *(u8*)((char*)this_ + 0x23c), 0xff);
            }
            break;
        case 2:
            if (((ActorSlot13*)this_)->slot13() != 0) {
                if (*(u8*)((char*)this_ + 0x23c) != 0) {
                    void* cr = fn_802D6A9C();
                    fn_802D8050(cr, *(s32*)((char*)this_ + 0x238), 0, 0xff);
                    *(u8*)((char*)this_ + 0x23c) = 0;
                } else {
                    void* cr = fn_802D6A9C();
                    fn_802D8050(cr, *(s32*)((char*)this_ + 0x238), 1, 0xff);
                    *(u8*)((char*)this_ + 0x23c) = 1;
                }
                *(s32*)((char*)this_ + 0x230) = 1;
            }
            break;
        case 3:
            if (((ActorSlot13*)this_)->slot13() != 0) {
                void* cr = fn_802D6A9C();
                fn_802D8050(cr, *(s32*)((char*)this_ + 0x238), 0, 0xff);
            } else {
                void* cr = fn_802D6A9C();
                fn_802D8050(cr, *(s32*)((char*)this_ + 0x238), 1, 0xff);
            }
            break;
        case 4:
            if (((ActorSlot13*)this_)->slot13() != 0) {
                void* cr = fn_802D6A9C();
                fn_802D8050(cr, *(s32*)((char*)this_ + 0x238), 0, 0xff);
            }
            break;
        default:
            break;
        }
        break;
    }
    case 1: {
        s32 sub = *(s32*)((char*)this_ + 0x234);
        switch (sub) {
        case 0:
        case 2:
            if (((ActorSlot13*)this_)->slot13() == 0) {
                *(s32*)((char*)this_ + 0x230) = 0;
            }
            break;
        case 4:
        default:
            break;
        }
        break;
    }
    case 2:
    default:
        break;
    }
}

// ---- RoomFlagParams_802E1DCC.cpp ----
extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802D800C(void*, u32);

// fn_802E1DCC - OFFS cluster, part 4/4. Extracts 2 bitfields from
// this->0x90 into this->0x234/0x238; queries the per-room config via
// fn_802D6A9C + fn_802D800C(this->0x238), storing the boolean
// result into this->0x23c; zeroes this->0x230; calls own virtual
// slot 5 (byte offset 0x14, draw/notify passthrough). See
// [[reference_fsa_virtual_dispatch_codegen_trick]] for why this calls
// through a real `virtual` member rather than a manual cast.
struct ActorSlot5 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void slot5();
};

extern "C" void fn_802E1DCC(void* this_) {
    *(u32*)((char*)this_ + 0x234) = *(u32*)((char*)this_ + 0x90) & 0x1F;
    *(u32*)((char*)this_ + 0x238) = (*(u32*)((char*)this_ + 0x90) >> 22) & 0x1F;
    void* configRecord = fn_802D6A9C();
    if (fn_802D800C(configRecord, *(u32*)((char*)this_ + 0x238)) != 0) {
        *(u8*)((char*)this_ + 0x23c) = 1;
    } else {
        *(u8*)((char*)this_ + 0x23c) = 0;
    }
    *(u32*)((char*)this_ + 0x230) = 0;
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
