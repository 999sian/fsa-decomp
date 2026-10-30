// TU 0x80214244-0x802144f0 — 2-Slot 0xC8-Byte Sub-Object Array Helpers (embedded at +0x358 in SLK2).
#include "types.h"
#include "JSystem/JGeometry.h"

struct Slk2SubSlot {
    /* 0x00 */ u8 mByte0;
    /* 0x01 */ u8 mFlag1;
    /* 0x02 */ u8 mFlag2;
    /* 0x03 */ u8 mFlag3;
    /* 0x04 */ u8 _pad04[0xC8 - 0x04];
};

struct Slk2SlotPair {
    /* 0x000 */ Slk2SubSlot mSlots[2]; // 2 x 0xC8 = 0x190 bytes
    /* 0x190 */ u8 mCurrentIndex;
};

extern "C" {
void* GetCurrentSlotPtr(Slk2SlotPair* thisPtr) {
    u8 idx = thisPtr->mCurrentIndex;
    return &thisPtr->mSlots[idx];
}

void SetCurrentSlotIndex(Slk2SlotPair* thisPtr, u8 idx) {
    thisPtr->mCurrentIndex = idx;
}

void fn_800FE3EC(void* slot, u32 a, JGeometry::TVec3<f32> v, u32 b);
void fn_8021425C(Slk2SlotPair* thisPtr, u8 idx, u32 a, JGeometry::TVec3<f32> v, u32 b) {
    fn_800FE3EC(&thisPtr->mSlots[idx], a, v, b);
}

void Slk2_ResetFlags7(Slk2SlotPair* thisPtr) {
    thisPtr->mCurrentIndex = 0;
    thisPtr->mSlots[0].mFlag2 = 0;
    thisPtr->mSlots[0].mFlag3 = 0;
    thisPtr->mSlots[0].mFlag1 = 0;
    thisPtr->mSlots[1].mFlag2 = 0;
    thisPtr->mSlots[1].mFlag3 = 0;
    thisPtr->mSlots[1].mFlag1 = 0;
}
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
