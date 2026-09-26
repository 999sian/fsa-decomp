// TU 0x8021bfa8-0x8021c2b4.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- Hrmn_InitSlotStateType3.cpp ----
// Hrmn_InitSlotStateType3(this): reset a "cyclic counter + lookup table" record to
// a fixed type tag (3), counters zeroed. Used by HRMN's fn_80216238 to
// initialize per-slot state before Hrmn_AdvanceSlotStateType3 drives it.
extern "C" {

void Hrmn_InitSlotStateType3(void* thisPtr) {
	char* p = (char*)thisPtr;
	*(u32*)(p + 0x0) = 3;
	*(u32*)(p + 0x4) = 0;
	*(u32*)(p + 0x8) = 0;
}

}

// ---- Hrmn_InitSlotStateType0xc.cpp ----
// Hrmn_InitSlotStateType0xc(this): reset a "cyclic counter + lookup table" record to
// a fixed type tag (0xc), counters zeroed. Used by HRMN's fn_80216178
// to initialize per-slot state before Hrmn_AdvanceSlotStateType0xc drives it.
extern "C" {

void Hrmn_InitSlotStateType0xc(void* thisPtr) {
	char* p = (char*)thisPtr;
	*(u32*)(p + 0x0) = 0xc;
	*(u32*)(p + 0x4) = 0;
	*(u32*)(p + 0x8) = 0;
}

}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
