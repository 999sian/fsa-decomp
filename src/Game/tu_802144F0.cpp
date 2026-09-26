// TU 0x802144f0-0x802153a8.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// ---- fn_80214900.cpp ----
extern "C" void* SpatialRegistry_GetBase();
extern "C" void* fn_801F666C(void* base, s32 id);
extern "C" void* fn_8013C824();
extern "C" void fn_800EC240(void* table, s32 id);
extern "C" void fn_801CDC8C(void* this_, s32 event);

extern "C" void fn_80214900(void* this_) {
    char* p = (char*)this_;
    s32 id = *(s32*)(p + 0x30);
    if (id >= 0) {
        void* base = SpatialRegistry_GetBase();
        void* found = fn_801F666C(base, id);
        if (found != 0) {
            *(u8*)((char*)found + 0x11c) = 0;
        }
        *(s32*)(p + 0x30) = -1;
    }
    if (*(u32*)(p + 0x18) != 0) {
        void* table = fn_8013C824();
        fn_800EC240(*(void**)((char*)table + 0xc), *(s32*)(p + 0x18));
        *(s32*)(p + 0x18) = 0;
    }
    fn_801CDC8C(*(void**)(p + 0x34), 0x4000E);
}

// ---- Slk2_InitVtablePairRecord.cpp ----
// Slk2_InitVtablePairRecord(this) - initializes a small record with TWO pointer-typed
// fields (+0x4, +0x1c) - each is installed with an interposed value
// (lbl_8049C178) that's IMMEDIATELY overwritten by a second, final value
// (lbl_804A64A8) - the same base-overridden-by-derived double-install
// pattern documented in project_fsa_multiple_inheritance_pattern.md,
// applied to two separate pointer slots within this one record rather
// than the record's own primary vtable. Also zeroes +0x0/+0x14/+0x18/
// +0x2c/+0x34 and sets +0x30=-1. Embedded by SLK2 at its own +0x4ec.
// Declared as functions (not data objects) so MWCC never treats these
// address-only references as small-data-relative - the actual symbols
// live in plain .data (vtables), not .sdata/.sbss, and a bare `extern
// void*` scalar declaration triggers MWCC's small-data-eligible
// heuristic regardless of the real section (same class of bug as the
// "large-bss-struct declared as bare scalar" case in
// project_fsa_phase4_kickoff.md's second batch).
extern "C" void lbl_8049C178();
extern "C" void lbl_804A64A8();

extern "C" {

void Slk2_InitVtablePairRecord(void* thisPtr) {
	char* p = (char*)thisPtr;
	*(u32*)(p + 0x0) = 0;
	*(void**)(p + 0x4) = (void*)lbl_8049C178;
	*(void**)(p + 0x4) = (void*)lbl_804A64A8;
	*(u8*)(p + 0x14) = 0;
	*(u32*)(p + 0x18) = 0;
	*(void**)(p + 0x1c) = (void*)lbl_8049C178;
	*(void**)(p + 0x1c) = (void*)lbl_804A64A8;
	*(u8*)(p + 0x2c) = 0;
	*(s32*)(p + 0x30) = -1;
	*(u32*)(p + 0x34) = 0;
}

}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
