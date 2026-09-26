// TU 0x80218cf4-0x8021a570 (actor KEPO).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"

// ---- ReturnZero_80218F80.cpp ----
// NEW ACTOR (vtable lbl_804A6550). Two trivial vtable-slot stubs, both return 0.
extern "C" {
int ReturnZero_80218F80(void) { return 0; }
int ReturnZero_80218F88(void) { return 0; }
}

// ---- stub_80219e04.cpp ----
// NEW ACTOR (vtable lbl_804A6550). "Is in an active/vulnerable window"
// predicate: true for states 6-0xa unconditionally, true for state 2
// only when variant (this->0x2b4) == 3, false otherwise.
//
// Cracked via zeldaret/tww's daNpc_Bm1_c::getBitMask() (src/d/actor/d_a_npc_bm1.cpp),
// which uses a `switch` with a default-initialized result variable and
// a single trailing return to get MWCC's switch-lowering to naturally
// produce a shared-tail merge point - if/else-if chains for this same
// logic had failed 3 times (see project_fsa_phase4_kickoff.md, 26th
// batch). The single-comparison case body also needed the established
// "default local + if-override" phrasing (not a bare `return cond;`)
// to avoid MWCC's branchless subfic/cntlzw/srwi canonicalization.
// Case declaration ORDER matters: the single-value case (2) must be
// written FIRST and the range case (6-10) SECOND for MWCC's block
// layout to match retail exactly - the reverse order (range first)
// produced byte-identical LOGIC but a 4-byte-shorter, differently
// laid out object.
extern "C" bool fn_80219E04(void* thisObj) {
	s32 v = *(s32*)((char*)thisObj + 0x248);
	bool result = false;
	switch (v) {
		case 2:
			if (*(s32*)((char*)thisObj + 0x2b4) == 3) { result = true; }
			break;
		case 6: case 7: case 8: case 9: case 10:
			result = true;
			break;
	}
	return result;
}

// ---- fn_8021A234_dtor.cpp ----
extern "C" void* fn_801EE434(void* handle);
extern "C" void dtor_801F593C(void* this_, int flag);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804A6550[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

extern "C" void* fn_8021A234(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A6550;
        fn_801EE434(*(void**)(p + 0x2c4));
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

#include "JSystem/JAudio/JASFakeMatchFSA.h"
