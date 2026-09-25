// TU 0x801f6058-0x801f68e0.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- Registry_GetSlotValueOrFallback_801F6644.cpp ----
// Registry_GetSlotValueOrFallback(registry, idx) - reads the record pointer at
// registry->recordArray[idx] (offset 0x8). If that record's own +0x4
// field is 0, returns a per-index value from a parallel array at
// registry+0x100c; otherwise returns a single shared fallback value at
// registry+0x200c. A "per-slot value with shared default" accessor.
extern "C" u32 Registry_GetSlotValueOrFallback(void* registry, s32 idx) {
	void** recordArray = (void**)((char*)registry + 0x8);
	void* record = recordArray[idx];
	if (*(s32*)((char*)record + 0x4) == 0) {
		u32* perIndexArray = (u32*)((char*)registry + 0x100c);
		return perIndexArray[idx];
	} else {
		return *(u32*)((char*)registry + 0x200c);
	}
}

// ---- ClassifyBamAngleToQuadrant_801F681C.cpp ----
// ClassifyBamAngleToQuadrant(angle) - classifies a 16-bit BAM angle (this project's
// standard binary-angle-measurement format, full circle = 0x10000)
// into a coarse 4-way facing-direction bucket by comparing it against
// the four 45-degree-offset boundaries (0x2000/0x6000/0xA000/0xE000).
// Used by fn_801EEC98 to reduce the winning target player's precise
// angle down to a simple direction bucket for its output.
//
// The middle check (`check2`) re-tests `angle < 0x2000` even though
// that's already known false from the first check above - a genuinely
// redundant comparison preserved honestly here because it's what
// retail's own bytes do (matches the project's real-decompilation
// mandate: preserve, don't silently "fix", a provably redundant
// retail check).
extern "C" s32 ClassifyBamAngleToQuadrant(s32 param) {
	u16 angle = (u16)param;
	s32 result = 1;
	if (angle < 0x2000) goto quad2;
	if (angle < 0xe000) goto check2;
quad2:
	result = 2;
	goto tail;
check2:
	if (angle < 0x2000) goto check3;
	if (angle >= 0x6000) goto check3;
	result = 0;
	goto tail;
check3:
	angle = (u16)param;
	if (angle < 0x6000) goto tail;
	if (angle > 0xa000) goto tail;
	result = 3;
tail:
	return result;
}
