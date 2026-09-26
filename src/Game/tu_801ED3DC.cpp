// Game TU 801ED3DC-801EDBA4 (unnamed). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"

extern "C" {
}

extern "C" void fn_801ED798(void* thisPtr) {
	char* p = (char*)thisPtr;
	*(u8*)(p + 0x0) = 0;
	*(u32*)(p + 0x4) = 0;
	*(u8*)(p + 0x8) = 0;
	*(u8*)(p + 0x9) = 0;
}

extern "C" s32 fn_801ED7B0(void* thisObj) {
	s32 result = 0;
	if (*(u8*)((char*)thisObj + 0x0) == 1 &&
	    *(s32*)((char*)thisObj + 0x4) == 0x1c20 &&
	    *(u8*)((char*)thisObj + 0x8) == 0x77 &&
	    *(u8*)((char*)thisObj + 0x9) == 0x63) {
		result = 1;
	}
	return result;
}

extern "C" void fn_801ED7F0(void* thisPtr) {
	char* p = (char*)thisPtr;
	*(u8*)(p + 0x0) = 1;
	*(u32*)(p + 0x4) = 0;
	*(u8*)(p + 0x8) = 0;
	*(u8*)(p + 0x9) = 0;
}

extern "C" void fn_801ED80C(void* thisPtr) {
	char* p = (char*)thisPtr;
	*(u8*)(p + 0x0) = 1;
	*(u32*)(p + 0x4) = 0;
	*(u8*)(p + 0x8) = 0;
	*(u8*)(p + 0x9) = 0;
}

extern "C" void fn_801ED968(void* thisPtr) { *(u16*)thisPtr = 0xb4; }

extern "C" void fn_801ED974(void* thisPtr) { *(u16*)thisPtr = 0x0; }

#include "JSystem/JAudio/JASFakeMatchFSA.h"
