// TU 0x8021a570-0x8021af28.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- InitDefaultRecord.cpp ----
// Small POD-record zero-initializer. Used by KEPO and EOWL as a plain default-init record.
extern "C" {
void InitDefaultRecord(void* thisPtr) {
	char* p = (char*)thisPtr;
	*(s32*)(p + 0x0) = 0;
	*(u16*)(p + 0x4) = 0;
	*(u16*)(p + 0x6) = 0;
	*(u16*)(p + 0x8) = 0;
	*(u16*)(p + 0xa) = 0;
	*(u8*)(p + 0xc) = 0;
	*(u8*)(p + 0xd) = 0;
}
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
