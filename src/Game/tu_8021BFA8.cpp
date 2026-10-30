// TU 0x8021bfa8-0x8021c2b4 — Cyclic Animation Slot State Helpers (used by Actor 'HRMN').
#include "types.h"

struct HrmnSlotState {
    /* 0x00 */ u32 value;
    /* 0x04 */ u32 index;
    /* 0x08 */ s32 counter;
};

static const u8 lbl_8053FCE0[4] = { 0xC, 0xD, 0xE, 0xF };
static const u8 lbl_8053FCE4[5] = { 3, 4, 5, 3, 0x1D };
static const u8 lbl_8053FCEC[5] = { 5, 5, 7, 7, 0x3C };

extern "C" {

u32 fn_8021BFA8(HrmnSlotState* s) {
    s->counter++;
    if (s->counter >= lbl_8053FCEC[s->index]) {
        s->counter = 0;
        s->index++;
        if (s->index >= 5) {
            s->index--;
        }
    }
    s->value = lbl_8053FCE4[s->index];
    return s->value;
}

void Hrmn_InitSlotStateType3(HrmnSlotState* thisPtr) {
    thisPtr->value = 3;
    thisPtr->index = 0;
    thisPtr->counter = 0;
}

u32 fn_8021C024(HrmnSlotState* s) {
    s->counter++;
    if (s->counter >= 7) {
        s->counter = 0;
        s->index++;
        if (s->index >= 4) {
            s->index = 0;
        }
    }
    s->value = lbl_8053FCE0[s->index];
    return s->value;
}

void Hrmn_InitSlotStateType0xc(HrmnSlotState* thisPtr) {
    thisPtr->value = 0xc;
    thisPtr->index = 0;
    thisPtr->counter = 0;
}

}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
