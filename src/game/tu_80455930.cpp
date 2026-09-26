// TU 0x80455930-0x80455ca4.
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"

// ---- from src/Game/SetSentinelField_0xc.cpp ----
// fn_80455A74 - trivial sentinel setter (this->0xc = -1).
extern "C" void fn_80455A74(void* thisObj) {
	*(s32*)((char*)thisObj + 0xc) = -1;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
