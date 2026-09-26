// TU 0x8021bfa8-0x8021c2b4.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"

// ---- Hrmn_InitSlotStateType3.cpp ----
// Hrmn_InitSlotStateType3(this): reset a "cyclic counter + lookup table" record to
// a fixed type tag (3), counters zeroed. Used by HRMN's fn_80216238 to
// initialize per-slot state before Hrmn_AdvanceSlotStateType3 drives it.
struct HrmnSlotState {
	u32 value;
	u32 index;
	s32 counter;
};

static const u8 lbl_8053FCE0[4] = { 0xC, 0xD, 0xE, 0xF };
static const u8 lbl_8053FCE4[5] = { 3, 4, 5, 3, 0x1D };
static const u8 lbl_8053FCEC[5] = { 5, 5, 7, 7, 0x3C };

extern "C" {

u32 fn_8021BFA8(HrmnSlotState* s) {
	s->counter++;
	if (s->counter >= lbl_8053FCEC[s->index]) {
		s->counter = 0;
		s->index++;
		if (s->index >= 5) {
			s->index--;
		}
	}
	s->value = lbl_8053FCE4[s->index];
	return s->value;
}

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

u32 fn_8021C024(HrmnSlotState* s) {
	s->counter++;
	if (s->counter >= 7) {
		s->counter = 0;
		s->index++;
		if (s->index >= 4) {
			s->index = 0;
		}
	}
	s->value = lbl_8053FCE0[s->index];
	return s->value;
}

void Hrmn_InitSlotStateType0xc(void* thisPtr) {
	char* p = (char*)thisPtr;
	*(u32*)(p + 0x0) = 0xc;
	*(u32*)(p + 0x4) = 0;
	*(u32*)(p + 0x8) = 0;
}

}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
