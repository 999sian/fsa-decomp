// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 80192038-80197070 (GNON). Remaining functions are not yet decompiled.
#include "types.h"

// from src/Game/GlobalMgr_GetByte_0x24f.cpp
// fn_80196DF0 - reads a byte at lbl_80529DEC->0x24f.
// fn_80196E00 - sets bit 0x10 in a byte at
// (*lbl_8053AED0)->0xdc. Retest of the batch-2
// "small-data-array" bug using the real 0x354-byte size from
// symbols.txt (the earlier attempt used an inexact 0x300 placeholder).
extern "C" {

extern u8 lbl_80529DEC[0x354];
extern void* lbl_8053AED0;

u8 fn_80196DF0(void) {
	return lbl_80529DEC[0x24f];
}

void fn_80196E00(void) {
	u8* p = (u8*)lbl_8053AED0;
	p[0xdc] |= 0x10;
}

}


#include "JSystem/JAudio/JASFakeMatchFSA.h"
