// TU 0x80316e34-0x803172dc.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- ResetResourceHandleRecord.cpp ----
// Small POD-record reset used by JIJI/TWTG/FTGL after a resource handle lookup.
extern "C" {
void ResetResourceHandleRecord(void* thisPtr) {
	char* p = (char*)thisPtr;
	*(s32*)(p + 0x0) = -1;
	*(s32*)(p + 0x4) = -1;
	*(u8*)(p + 0x8) = 0;
	*(u8*)(p + 0x9) = 0;
}
}

// Shared JAudio pool __sinit (docs/game/sinit_pools.md). Drop the ESD
// macros/typedefs that clash with the JSystem headers first.
#undef ALIGN_NEXT
#undef ALIGN_PREV
#undef ARRAY_SIZE
#undef ASM
#undef ATTRIBUTE_ALIGN
#undef IS_ALIGNED
#undef IS_NOT_ALIGNED
#undef MACROS_H
#undef MAX
#undef MIN
#undef NULL
#define NULL 0
#define unknown jsys_unknown
#include "JSystem/JAudio/JASFakeMatchFSA.h"
