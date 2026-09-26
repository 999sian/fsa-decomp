// TU 0x802153a8-0x802157b8.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// ---- CosmeticPhaseCycle_802153A8.cpp ----
extern "C" u8 fn_801CD580(u8 val);
extern "C" u8 fn_801CD398(u8 val1, u8 val2);

// fn_802153A8(this) - a randomized cosmetic state-cycle: this->0x0 is an
// enable flag, this->0x3 a 0-3 phase, this->0x4 a per-phase frame
// counter, this->0x1/0x2 a pair of selected byte values. Uses
// compiler-generated divide-by-5 and divide-by-15 magic-number
// sequences (0x66666667/0x88888889) to detect "every 5th frame" and
// "every 15th frame" boundaries; on those boundaries, rerolls
// this->0x1 via fn_801CD580(this->0x1) or, in the phase-1 branch,
// fn_801CD398(this->0x1, this->0x2) instead. Each phase caps
// this->0x4 against a threshold and advances this->0x3 to the next
// phase, comparing this->0x1 against this->0x2 along the way.
extern "C" u8 fn_802153A8(void* this_) {
    char* t = (char*)this_;
    u8 retval = 0;

    if (*(u8*)(t + 0x0) != 0) {
        *(u16*)(t + 0x4) = *(u16*)(t + 0x4) + 1;
        s32 phase = *(u8*)(t + 0x3);

        switch (phase) {
        case 0:
            if (*(u16*)(t + 0x4) % 5 == 0) {
                *(u8*)(t + 0x1) = fn_801CD580(*(u8*)(t + 0x1));
            }
            if (*(u16*)(t + 0x4) >= 0x64) {
                *(u8*)(t + 0x3) = *(u8*)(t + 0x3) + 1;
                *(u16*)(t + 0x4) = 0;
            }
            break;
        case 1:
            if (*(u16*)(t + 0x4) % 15 == 0) {
                *(u8*)(t + 0x1) = fn_801CD580(*(u8*)(t + 0x1));
            }
            if (*(u16*)(t + 0x4) >= 0x4b) {
                u8 same = 0;
                if (*(u8*)(t + 0x1) == *(u8*)(t + 0x2)) {
                    same = 1;
                }
                if (same != 0) {
                    *(u8*)(t + 0x3) = *(u8*)(t + 0x3) + 1;
                    *(u16*)(t + 0x4) = 0;
                } else {
                    retval = 1;
                }
            }
            break;
        case 2:
            if (*(u16*)(t + 0x4) % 15 == 0) {
                *(u8*)(t + 0x1) = fn_801CD398(*(u8*)(t + 0x1), *(u8*)(t + 0x2));
                retval = 1;
            }
            break;
        default:
            break;
        }
    }

    if (retval != 0) {
        *(u16*)(t + 0x4) = *(u16*)(t + 0x4) - 1;
        *(u8*)(t + 0x0) = 0;
    }

    return retval;
}

// ---- InitFlagBlock3c_WithFlag.cpp ----
// A self-contained pair sharing one 0x3c-byte block. InitFlagBlock3c_WithFlag takes a
// caller flag; ResetFlagBlock3c_Zero is the plain all-zero variant.
extern "C" {

void InitFlagBlock3c_WithFlag(void* thisPtr, u8 flag) {
	char* p = (char*)thisPtr;
	*(u8*)(p + 0x0) = 1;
	*(u8*)(p + 0x1) = flag;
	*(u8*)(p + 0x2) = flag;
	*(u8*)(p + 0x3) = 0;
	*(u16*)(p + 0x4) = 0;
}

void ResetFlagBlock3c_Zero(void* thisPtr) {
	char* p = (char*)thisPtr;
	*(u8*)(p + 0x0) = 0;
	*(u8*)(p + 0x1) = 0;
	*(u8*)(p + 0x2) = 0;
	*(u8*)(p + 0x3) = 0;
	*(u16*)(p + 0x4) = 0;
}

}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
