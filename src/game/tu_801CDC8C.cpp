// Game TU 801CDC8C-801D11FC (unnamed). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"

extern "C" {
}

extern "C" void fn_801CE4E0(void) {}

extern "C" void fn_801CE4E4(void) {}

extern "C" void fn_801CE914(void) {}

extern "C" void fn_801CE918(void) {}

extern "C" void fn_801CE91C(void) {}

extern "C" void fn_801CE920(void) {}

extern "C" void fn_801CE924(void) {}

extern "C" int fn_801CECEC(void) { return 0; }

#pragma fp_contract off
extern "C" s32 fn_801D0D50(void* thisArg, s32 playerIdx, f32* point, f32 radius) {
    u8* p = (u8*)thisArg;
    f32 radiusSq = radius * radius;
    s32 result = 0;
    f32* record = (f32*)(p + playerIdx * 0xc + 0x1ac);
    f32 dz = record[1] - point[1];
    f32 dx = record[0] - point[0];
    f32 distSq = dx * dx + dz * dz;
    if (distSq <= radiusSq) {
        result = 1;
    }
    return result;
}
#pragma fp_contract reset

#pragma fp_contract off
extern "C" f32 fn_801D0DA0(void* thisArg, s32 playerIdx, f32* point) {
    u8* p = (u8*)thisArg;
    f32* record = (f32*)(p + playerIdx * 0xc + 0x1ac);
    f32 dz = record[1] - point[1];
    f32 dx = record[0] - point[0];
    return dx * dx + dz * dz;
}
#pragma fp_contract reset

extern "C" void fn_801D0ECC(void) {}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
