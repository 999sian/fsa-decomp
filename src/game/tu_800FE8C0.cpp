// tu_800FE8C0: .text 0x800FE8C0-0x800FEDD0
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"

// Sprite animation sequencer: op selects a (direction-indexed) base frame
// table and a duration sequence; 0xFF loops, 0xFE holds and sets flag 0x20.
struct AnimSeq {
    s32 op;       // 0x00
    s32 prevOp;   // 0x04
    s32 frame;    // 0x08
    s8 dir;       // 0x0C
    u8 idx;       // 0x0D
    s32 timer;    // 0x10
    u32 flags;    // 0x14
};

static const u8 sSeq0[2] = {0x0A, 0xFF};
static const u8 sSeq2[8] = {1, 1, 1, 2, 1, 1, 1, 0xFE};
static const u8 sSeq3[5] = {1, 4, 1, 2, 0xFE};
static const u8 sSeq5[5] = {4, 4, 4, 0x1E, 0xFE};
static const u8 sSeq7[5] = {0x0A, 6, 0x0A, 6, 0xFF};
static const u8 sOfs7[4] = {0, 1, 2, 1};
static const u8 sSeq8[4] = {0x0C, 2, 0x3C, 0xFE};
static const u8 sSeq9[2] = {0x19, 0xFE};

// NonMatching: 99.9%, only r4/r5 swapped in the prologue (op load vs table base).
extern "C" void fn_800FE8C0(AnimSeq* a) {
    static const s32 sFrame0[4] = {0x3C, 0x3D, 0x3E, 0x3F};
    static const s32 sFrame1[4] = {0x00, 0x08, 0x10, 0x18};
    static const u8 sSeq1[9] = {3, 3, 3, 3, 3, 3, 3, 3, 0xFF};
    static const s32 sFrame2[4] = {0x20, 0x27, 0x2E, 0x35};
    static const s32 sFrame3[4] = {0x252, 0x256, 0x25A, 0x25E};
    static const s32 sFrame4[4] = {0xF1, 0xF9, 0x101, 0x109};
    static const u8 sSeq4[10] = {3, 6, 6, 3, 3, 3, 6, 0x50, 3, 0xFE};
    static const u8 sOfs4[10] = {0, 1, 2, 3, 4, 5, 6, 7, 0, 0};
    static const s32 sFrame5[4] = {0xA7, 0xAB, 0xAF, 0xB3};
    static const u8 sFrame6[4][12] = {
        {0x08, 0x09, 0x0A, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x0B},
        {0x0C, 0x0D, 0x0E, 0x04, 0x05, 0x06, 0x07, 0x00, 0x01, 0x02, 0x03, 0x0F},
        {0x10, 0x11, 0x12, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x00, 0x01, 0x13},
        {0x14, 0x15, 0x16, 0x06, 0x07, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x17},
    };
    static const u8 sSeq6[13] = {4, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0xFE};
    static const s32 sFrame9[4] = {0x6F, 0x77, 0x7F, 0x87};
    if (a->op != a->prevOp) {
        a->prevOp = a->op;
        a->timer = 0;
        a->idx = 0;
        a->flags &= ~0x20;
    }
    const u8* seq = 0;
    switch (a->op) {
    case 0:
        a->frame = sFrame0[a->dir];
        seq = sSeq0 + a->idx;
        a->frame += a->idx;
        break;
    case 1:
        a->frame = sFrame1[a->dir];
        seq = sSeq1 + a->idx;
        a->frame += a->idx;
        break;
    case 2:
        a->frame = sFrame2[a->dir];
        seq = sSeq2 + a->idx;
        a->frame += a->idx;
        break;
    case 3:
        a->frame = sFrame3[a->dir];
        seq = sSeq3 + a->idx;
        a->frame += a->idx;
        break;
    case 4:
        a->frame = sFrame4[a->dir];
        seq = sSeq4 + a->idx;
        a->frame += sOfs4[a->idx];
        break;
    case 5:
        a->frame = sFrame5[a->dir];
        seq = sSeq5 + a->idx;
        a->frame += a->idx;
        break;
    case 6:
        a->frame = sFrame6[a->dir][a->idx] + 0x8F;
        seq = sSeq6 + a->idx;
        break;
    case 7:
        a->frame = 0x36A;
        seq = sSeq7 + a->idx;
        a->frame += sOfs7[a->idx];
        break;
    case 8:
        a->frame = 0xE6;
        seq = sSeq8 + a->idx;
        a->frame += a->idx;
        break;
    case 9:
        a->frame = sFrame9[a->dir];
        seq = sSeq9 + a->idx;
        a->frame += a->idx;
        break;
    }
    if (a->timer == seq[0]) {
        a->timer = 0;
        a->idx++;
        if (seq[1] == 0xFF) {
            a->idx = 0;
        } else if (seq[1] == 0xFE) {
            a->idx--;
            a->flags |= 0x20;
        }
    }
    a->timer++;
}

// ---- from Game/fn_800FEB78.cpp


// fn_800FEB78(this, opcode): a "SetOpcode" trigger for the same class as
// fn_800FE8C0 (the event-script player generalized from the
// rupee-container's fn_800FA6B0) - sets this->0x0=opcode, this->0x4=0xa
// (a sentinel guaranteed not to equal any real opcode, forcing
// fn_800FE8C0's state-change reset on its next call), and this->0xc=0,
// then calls fn_800FE8C0(this) once immediately.
extern "C" void fn_800FEB78(void* this_, s32 opcode) {
    *(s32*)((char*)this_ + 0x0) = opcode;
    *(s32*)((char*)this_ + 0x4) = 0xa;
    *(u8*)((char*)this_ + 0xc) = 0;
    fn_800FE8C0((AnimSeq*)this_);
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
