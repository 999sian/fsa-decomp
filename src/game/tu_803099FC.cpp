// TU 0x803099fc-0x8030ae84.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- AnimTable_IsField0xdcLessThan3_8030A2E4.cpp ----
extern "C" {

// AnimTable_IsField0xdcLessThan3(table, slot) -> bool: sentinel-gated check of whether
// *(table+slot+0xdc) < 3. Split out of the original extab_80309d24.s
// animation-controller bundle - no evidence of scaled indexing here
// (unlike this bundle's other members), so `table+slot` is left as
// raw byte-pointer arithmetic.
s32 AnimTable_IsField0xdcLessThan3(void* table, s32 slot) {
    if (slot == -999) {
        return 0;
    }
    u8* p = (u8*)table;
    p = p + slot;
    u8 val = p[0xdc];
    return val < 3;
}

}

// ---- AnimTable_IsField0xe0LessThan3_8030A364.cpp ----
extern "C" {

// AnimTable_IsField0xe0LessThan3(table, slot) -> bool: same sentinel-gated shape as
// AnimTable_IsField0xdcLessThan3, different field offset (0xe0). Split out of the
// original extab_80309d24.s animation-controller bundle.
s32 AnimTable_IsField0xe0LessThan3(void* table, s32 slot) {
    if (slot == -999) {
        return 0;
    }
    u8* p = (u8*)table;
    p = p + slot;
    u8 val = p[0xe0];
    return val < 3;
}

}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
