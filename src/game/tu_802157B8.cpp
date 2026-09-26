// TU 0x802157b8-0x80215a94.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"

// ---- Slk2_ResetBlock0x0.cpp ----
// Slk2_ResetBlock0x0(this): trivial single zero at +0x0 - the RESET/init half
// of a pair sharing one 0xb8-byte block. Embedded by SLK2 at its own
// +0x524. The UPDATE half, fn_802157B8, dispatches through a jump table
// and stays raw asm in Dolphin/os/extab_802157b8.s.
extern "C" {

void fn_802157B8(u32* flags, u8 level) {
	*flags |= 0x48;
	if (level >= 5) {
		*flags |= 0x10;
		if (level >= 6) {
			*flags |= 0x20;
		}
	}
	switch (level) {
	case 1:
		*flags |= 0x1100;
		break;
	case 3:
		*flags |= 0x404;
		break;
	case 5:
		*flags |= 0xb00;
		break;
	case 6:
		*flags |= 0x404;
		break;
	case 7:
		*flags |= 0x7;
		break;
	}
}

void Slk2_ResetBlock0x0(void* thisPtr) {
	*(u32*)((char*)thisPtr + 0x0) = 0;
}

}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
