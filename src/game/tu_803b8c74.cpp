// TU 0x803b8c74-0x803b9940.
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"

// ---- from src/Game/fn_803B94C4_dtor.cpp ----
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804AFB30[];

extern "C" void* fn_803B94C4(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AFB30;
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// ---- from src/Game/fn_803B95D4_dtor.cpp ----
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804AFB3C[];

extern "C" void* fn_803B95D4(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AFB3C;
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

// ---- from src/Game/Table_SetSelfIndexedByte86.cpp ----
// fn_803B8C74(val) / fn_803B8C90() - setter/getter for a byte field at
// +0x86 in a global table (lbl_8050EC80, stride 0xc8), indexed by a
// value read from the table's own +0x10 word (row 0's self-index, not
// an incoming argument).
//
// Retry using real typed-array `[]` syntax (per zeldaret/tww's idiom
// for indexed table access) instead of the manual char*+idx*stride
// arithmetic that failed here previously - see project_fsa_phase4_kickoff.md,
// eighteenth batch, for the confirmed root cause (MWCC's indexed-vs-
// base+immediate addressing choice depends on how the address is
// expressed in source, not the underlying computation).
struct EC80Row {
	u8 pad0[0x10];
	u32 selfIndex; // 0x10
	u8 pad1[0x86 - 0x14];
	u8 field86; // 0x86
	u8 pad2[0xc8 - 0x87];
};

extern EC80Row lbl_8050EC80[16];

extern "C" {

void fn_803B8C74(u8 val) {
	u32 idx = lbl_8050EC80[0].selfIndex;
	lbl_8050EC80[idx].field86 = val;
}

u8 fn_803B8C90(void) {
	u32 idx = lbl_8050EC80[0].selfIndex;
	return lbl_8050EC80[idx].field86;
}

}
