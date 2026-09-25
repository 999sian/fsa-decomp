// TU 0x802684a4-0x8026fc20.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- SetField_0x98.cpp ----
// SetField_0x98(this) - trivial setter: this->0x98 = 1.
extern "C" {

void SetField_0x98(void* thisPtr) {
	*(u8*)((char*)thisPtr + 0x98) = 1;
}

}
