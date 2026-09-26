// Game TU 801C9AF8-801CB270 (unnamed). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"


extern "C" bool fn_801CAED4(void* thisObj, s32 value) {
	s32 v = *(s32*)((char*)thisObj + 0x560);
	return v != 4 && v != value;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
