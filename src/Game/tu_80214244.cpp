// TU 0x80214244-0x802144f0.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// ---- GetCurrentSlotPtr.cpp ----
// Both operate on a 0xc8-byte-stride array embedded at this+0, selected by a current-index byte at this->0x190.
extern "C" {
void* GetCurrentSlotPtr(void* thisPtr) {
	u8 idx = *(u8*)((char*)thisPtr + 0x190);
	return (char*)thisPtr + (idx * 0xc8);
}

void SetCurrentSlotIndex(void* thisPtr, u8 idx) {
	*(u8*)((char*)thisPtr + 0x190) = idx;
}
}

// ---- Slk2_ResetFlags7.cpp ----
// A plain multi-flag reset: zeroes 7 byte fields. Embedded by SLK2 at its own +0x358.
extern "C" {
void Slk2_ResetFlags7(void* thisPtr) {
	char* p = (char*)thisPtr;
	*(u8*)(p + 0x190) = 0;
	*(u8*)(p + 0x2) = 0;
	*(u8*)(p + 0x3) = 0;
	*(u8*)(p + 0x1) = 0;
	*(u8*)(p + 0xca) = 0;
	*(u8*)(p + 0xcb) = 0;
	*(u8*)(p + 0xc9) = 0;
}
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
