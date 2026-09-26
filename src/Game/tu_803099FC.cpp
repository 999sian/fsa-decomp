// TU 0x803099fc-0x8030ae84.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

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
#ifndef unknown
#define unknown jsys_unknown
#endif
#include "JSystem/JGeometry/Util.h"

// ---- Pad/controller state for the four players (singleton lbl_8053AD30) ----
// Slot indices 0..3 map to themselves; anything else is the "no player"
// sentinel -999 (fn_8030AAF4, inlined everywhere).
struct PadState {
    void* vtbl;       // 0x00
    u32 hold[4];      // 0x04
    u32 f14[4];       // 0x14
    u32 f24[4];       // 0x24
    u32 f34[4];       // 0x34
    s32 rep[4][4];    // 0x44: key-repeat timers [bit][player]
    u32 f84[4];       // 0x84
    u32 f94[4];       // 0x94
    u32 fa4[4];       // 0xa4
    s32 fb4[4];       // 0xb4
    u32 fc4[4];       // 0xc4
    u8 fd4[4];        // 0xd4
    u8 fd8[4];        // 0xd8
    u8 fdc[4];        // 0xdc
    u8 fe0[4];        // 0xe0
    u8 fe4;           // 0xe4
    u8 fe5;           // 0xe5
    u8 fe6[4];        // 0xe6
};

static inline s32 padSlot(s32 i) {
    if (i == 0) {
        return 0;
    }
    if (i == 1) {
        return 1;
    }
    if (i == 2) {
        return 2;
    }
    if (i == 3) {
        return 3;
    }
    return -999;
}

// Element type of the two static arrays built by tu_80301CD0's __sinit.
struct Elem28_80301CD0 {
    Elem28_80301CD0();
    u8 pad[0x28];
};
Elem28_80301CD0::Elem28_80301CD0() {}

extern "C" u32 fn_80309A00(PadState* s, s32 i) {
    if (i == -999) {
        return 0;
    }
    // NONMATCHING (86.8%): retail uses an orc/srwi unsigned-compare idiom.
    return s->fb4[i] < 1;
}

extern "C" u8 fn_80309A38(PadState* s, s32 i) {
    if (i == -999) {
        return 0;
    }
    return s->fe6[i];
}

extern "C" u32 fn_80309A54(PadState* s, s32 i, u32 mask) {
    if (i == -999) {
        return 0;
    }
    return s->f94[i] & mask;
}

extern "C" u32 fn_80309A78(PadState* s, s32 i, u32 mask) {
    if (i == -999) {
        return 0;
    }
    return s->f84[i] & mask;
}

extern char* lbl_8053AAF8;
extern "C" s32 fn_80138A30(void* game);

#define PAD_ANY(NAME, FIELD)                                         \
    extern "C" u32 NAME(PadState* s, u32 mask, s32 n) {             \
        s32 cnt;                                                     \
        if (n == -1) {                                               \
            cnt = fn_80138A30(lbl_8053AAF8);                         \
        } else {                                                     \
            cnt = n;                                                 \
        }                                                            \
        for (s32 i = 0; i < cnt; i++) {                              \
            s32 k = padSlot(i);                                      \
            u32 r;                                                   \
            if (k == -999) {                                         \
                r = 0;                                               \
            } else {                                                 \
                r = s->FIELD[k] & mask;                              \
            }                                                        \
            if (r) {                                                 \
                return r;                                            \
            }                                                        \
        }                                                            \
        return 0;                                                    \
    }

PAD_ANY(fn_80309A9C, f34)
PAD_ANY(fn_80309B74, hold)
PAD_ANY(fn_80309C4C, f24)

extern "C" u32 fn_80309D24(PadState* s, s32 i, u32 mask) {
    if (i == -999) {
        return 0;
    }
    return s->hold[i] & mask;
}

extern "C" u32 fn_80309D48(PadState* s, s32 i, u32 mask) {
    if (i == -999) {
        return 0;
    }
    return s->f34[i] & mask;
}

extern "C" u32 fn_80309D6C(PadState* s, s32 i, u32 mask) {
    if (i == -999) {
        return 0;
    }
    return s->f24[i] & mask;
}


// Stick axes from the digital direction bits (hold[i] bits 0..3).
static inline f32 padAxisY(PadState* s, s32 i) {
    if (i == -999) {
        return 0.0f;
    }
    f32 v = ((i == -999) ? 0 : (s->hold[i] & 4)) ? -1.0f : 0.0f;
    v += ((i == -999) ? 0 : (s->hold[i] & 8)) ? 1.0f : 0.0f;
    if ((i == -999) ? 0 : (s->hold[i] & 3)) {
        v *= 0.70710677f;
    }
    return v;
}

static inline f32 padAxisX(PadState* s, s32 i) {
    if (i == -999) {
        return 0.0f;
    }
    f32 v = ((i == -999) ? 0 : (s->hold[i] & 1)) ? -1.0f : 0.0f;
    v += ((i == -999) ? 0 : (s->hold[i] & 2)) ? 1.0f : 0.0f;
    if ((i == -999) ? 0 : (s->hold[i] & 0xc)) {
        v *= 0.70710677f;
    }
    return v;
}

extern "C" f32 fn_80309D90(PadState* s, s32 i) {
    f32 x = padAxisY(s, i);
    f32 y = padAxisX(s, i);
    return JGeometry::TUtil<f32>::sqrt(y * y + x * x);
}

extern "C" f32 fn_80309F20(PadState* s, s32 i) {
    if (i == -999) {
        return 0.0f;
    }
    f32 v = ((i == -999) ? 0 : (s->hold[i] & 4)) ? -1.0f : 0.0f;
    v += ((i == -999) ? 0 : (s->hold[i] & 8)) ? 1.0f : 0.0f;
    if ((i == -999) ? 0 : (s->hold[i] & 3)) {
        v *= 0.70710677f;
    }
    return v;
}

extern "C" f32 fn_80309FCC(PadState* s, s32 i) {
    if (i == -999) {
        return 0.0f;
    }
    f32 v = ((i == -999) ? 0 : (s->hold[i] & 1)) ? -1.0f : 0.0f;
    v += ((i == -999) ? 0 : (s->hold[i] & 2)) ? 1.0f : 0.0f;
    if ((i == -999) ? 0 : (s->hold[i] & 0xc)) {
        v *= 0.70710677f;
    }
    return v;
}

extern u8 lbl_804DB798[4][0xe0];
extern u8 lbl_8053ACE4[4];
extern "C" u8 fn_8030A258(PadState* s, s32 i) {
    if (i == -999) {
        return 0;
    }
    if (s->fc4[i] != 0x40000) {
        return 0;
    }
    if (s->fd4[i] != 0) {
        return 0;
    }
    if (s->fd8[i] == 0) {
        return 0;
    }
    if (lbl_804DB798[i][0xdc] != 0) {
        return 0;
    }
    return lbl_8053ACE4[i];
}

// Per-frame update: edge detection and key repeat (20 frames, then 10).
extern "C" void fn_8030A078(PadState* s) {
    for (s32 i = 0; i < 4; i++) {
        s->f24[i] = s->hold[i] & (s->hold[i] ^ s->f14[i]);
        s->fa4[i] = s->f14[i] & (s->hold[i] ^ s->f14[i]);
        s->f34[i] = 0;
#define PAD_REPEAT(BIT, IDX)                          \
        if (s->hold[i] & BIT) {                       \
            if (s->f24[i] & BIT) {                    \
                s->f34[i] |= BIT;                     \
                s->rep[IDX][i] = 20;                  \
            } else {                                  \
                s->rep[IDX][i]--;                     \
                if (s->rep[IDX][i] <= 0) {            \
                s->f34[i] |= BIT;                     \
                s->rep[IDX][i] = 10;                  \
                }                                     \
            }                                         \
        } else {                                      \
            s->rep[IDX][i] = 0;                       \
        }
        PAD_REPEAT(1, 0)
        PAD_REPEAT(2, 1)
        PAD_REPEAT(4, 2)
        PAD_REPEAT(8, 3)
#undef PAD_REPEAT
    }
}

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

extern "C" u32 fn_8030A308(PadState* s, s32 i) {
    if (i == -999) {
        return 0;
    }
    if (s->fc4[i] != 0x40000) {
        return 0;
    }
    if (s->fd4[i] != 0) {
        return 0;
    }
    return s->fd8[i] == 1;
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


extern u8 lbl_8053AD38[8];
extern u8 lbl_8053AD34[8];
extern "C" u32 fn_8030A388(PadState* s, s32 i) {
    if (i == -999) {
        return 0;
    }
    return lbl_8053AD38[i] != 0;
}

static inline bool padIsMode1(PadState* s, s32 i) {
    if (i == -999) {
        return 0;
    }
    if (s->fc4[i] != 0x40000) {
        return 0;
    }
    if (s->fd4[i] != 0) {
        return 0;
    }
    if (s->fd8[i] == 1) {
        return true;
    }
    return false;
}

extern "C" bool fn_8030A3B0(PadState* s, s32 i) {
    if (i == -999) {
        return false;
    }
    return padIsMode1(s, i) || lbl_8053AD38[i] != 0;
}


extern "C" s32 fn_8030AAF4(s32 i) {
    if (i == 0) {
        return 0;
    }
    if (i == 1) {
        return 1;
    }
    if (i == 2) {
        return 2;
    }
    s32 r = -999;
    if (i == 3) {
        r = 3;
    }
    return r;
}

extern "C" void fn_8030AB38(PadState* s) {
    for (s32 i = 0; i < 4; i++) {
        s->hold[i] = 0;
        s->f14[i] = 0;
        s->f24[i] = 0;
        s->f34[i] = 0;
        s->f84[i] = 0;
        s->f94[i] = 0;
        s->fa4[i] = 0;
        lbl_8053AD38[i] = 0;
        lbl_8053AD34[i] = 0;
        s->fc4[i] = 0;
        s->fd4[i] = 3;
        s->fd8[i] = 0;
        s->fdc[i] = 0;
        s->fe0[i] = 0;
        s->fb4[i] = 0;
    }
    s->fe4 = 0;
    s->fe5 = 0;
}

extern void* lbl_804AA8C8[];
extern PadState* lbl_8053AD30;

extern "C" PadState* fn_8030ABFC(PadState* s, s16 how) {
    if (s != 0) {
        s->vtbl = lbl_804AA8C8;
        lbl_8053AD30 = 0;
        if (how > 0) {
            operator delete(s);
        }
    }
    return s;
}

extern "C" void fn_8030AC4C(PadState* s) {
    s->vtbl = lbl_804AA8C8;
    lbl_8053AD30 = s;
}

static u8 lbl_805076E8[0x10];

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
