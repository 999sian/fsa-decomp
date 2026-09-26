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
    return (u32)s->fb4[i] >= 1;
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
    f32 d = y * y + x * x;
    if (d <= 0.0f) {
        return d;
    }
    f32 r = __frsqrte(d);
    r = 0.5f * r * (3.0f - (d * (r * r)));
    return d * r;
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


#include "dolphin/os/OSMessage.h"
#include "dolphin/pad.h"
#include <string.h>
extern "C" u32 fn_803006E8(u32 v);
extern "C" u8* fn_8008E328(s32 slot);
extern "C" u8 fn_80136320(char* game);
extern u8 lbl_80506DE8[4][0x68];
extern u8 lbl_8053AD08;
extern u8 lbl_80541618[8];
extern u8* lbl_8053AAF0;
extern const f32 lbl_80541688;
extern const f32 lbl_8054168C;
extern const f32 lbl_80541690;
struct PadMapEntry {
    u8 pad[0xa];
    s8 m0a;
    u8 pad2;
};
extern PadMapEntry lbl_8052EA28[];

static inline BOOL padLinkReady() {
    return lbl_8053AAF0[0x78] >= 4;
}

extern "C" void fn_8030A43C(PadState* s) {
    s32 i;
    u32 resetMask = 0;
    for (i = 0; i < 4; i++) {
        s->f14[i] = s->hold[i];
        s->f94[i] = s->f84[i];
        s->f84[i] = s->f24[i];
    }
    for (i = 0; i < 4; i++) {
        lbl_8053AD34[i] = 0;
        lbl_8053AD38[i] = 0;
        if (s->fdc[i] < 3) {
            s->fdc[i]++;
        }
        if (s->fe0[i] < 3) {
            s->fe0[i]++;
        }
        if (lbl_804DB798[i][0xd1] != 0) {
            continue;
        }
        s->fc4[i] = *(u32*)(lbl_804DB798[i] + 0x54);
        s->fd4[i] = lbl_804DB798[i][0xd3];
        s->fd8[i] = lbl_804DB798[i][0xd8];
        if (s->fc4[i] == 0x40000) {
            switch (s->fd4[i]) {
            case 0:
                if (s->fd8[i] == 0) {
                    OSSendMessage((OSMessageQueue*)lbl_804DB798[i], (OSMessage)7, 1);
                } else {
                    if (padLinkReady() != FALSE || lbl_8053AAF0[0x60] != 0) {
                        lbl_8053AD34[i] = lbl_804DB798[i][0xd6];
                        u32 btn = *(u32*)(lbl_804DB798[i] + 0x60);
                        memcpy(lbl_804DB798[i] + 0x68, lbl_80506DE8[i], lbl_80541618[lbl_8053AD08] * 4);
                        OSSendMessage((OSMessageQueue*)lbl_804DB798[i], (OSMessage)10, 1);
                        if (lbl_8053AD34[i] != 0 && (u8)btn == fn_803006E8(((btn >> 16) & 0xff) | (btn & 0xff00))) {
                            s->hold[i] = ((btn & 0x200000) ? 1 : 0) | ((btn & 0x100000) ? 2 : 0) |
                                         ((btn & 0x400000) ? 8 : 0) | ((btn & 0x800000) ? 4 : 0) |
                                         ((btn & 0x200) ? 0x40 : 0) | ((btn & 0x100) ? 0x20 : 0) |
                                         ((btn & 0x80000) ? 0x1000 : 0) | ((btn & 0x40000) ? 0x400 : 0) |
                                         ((btn & 0x10000) ? 0x100 : 0) | ((btn & 0x20000) ? 0x200 : 0);
                            s->fe6[i] = (btn >> 15) & 1;
                        }
                    }
                    s->fdc[i] = 0;
                }
                break;
            case 3:
                *(u32*)(lbl_804DB798[i] + 0x54) = 0;
                if (*(u32*)(lbl_804DB798[i] + 0x20) == 7 && (u32)s->fb4[i] < 0xffffffff) {
                    s->fb4[i]++;
                }
                break;
            default:
                *(u32*)(lbl_804DB798[i] + 0x54) = 0;
                break;
            }
        } else if (s->fc4[i] == 0) {
            s->hold[i] = 0;
            if (*(u32*)(lbl_804DB798[i] + 0x20) != 7) {
                s->fb4[i] = 0;
            }
            OSSendMessage((OSMessageQueue*)lbl_804DB798[i], (OSMessage)6, 1);
        } else {
            s->fb4[i] = 0;
            if (lbl_804DB798[i][0xde] == 1) {
                lbl_804DB798[i][0xdd] = 1;
            }
            s->hold[i] = 0;
            s32 slot = padSlot(i);
            u8* pad = fn_8008E328(slot);
            if (pad != NULL) {
                switch (lbl_8052EA28[slot].m0a) {
                case 0:
                    lbl_8053AD38[i] = 1;
                    if (((*(u32*)(pad + 0x18) & 1) && fn_80136320(lbl_8053AAF8)) || *(f32*)(pad + 0x48) < lbl_80541688) {
                        s->hold[i] |= 1;
                    }
                    if (((*(u32*)(pad + 0x18) & 2) && fn_80136320(lbl_8053AAF8)) || *(f32*)(pad + 0x48) > lbl_8054168C) {
                        s->hold[i] |= 2;
                    }
                    if (((*(u32*)(pad + 0x18) & 4) && fn_80136320(lbl_8053AAF8)) || *(f32*)(pad + 0x4c) < lbl_80541688) {
                        s->hold[i] |= 4;
                    }
                    if (((*(u32*)(pad + 0x18) & 8) && fn_80136320(lbl_8053AAF8)) || *(f32*)(pad + 0x4c) > lbl_8054168C) {
                        s->hold[i] |= 8;
                    }
                    if ((*(u32*)(pad + 0x18) & 0x400) ||
                        ((*(u32*)(pad + 0x18) & 1) && !fn_80136320(lbl_8053AAF8)) ||
                        ((*(u32*)(pad + 0x18) & 2) && !fn_80136320(lbl_8053AAF8)) ||
                        ((*(u32*)(pad + 0x18) & 4) && !fn_80136320(lbl_8053AAF8)) ||
                        ((*(u32*)(pad + 0x18) & 8) && !fn_80136320(lbl_8053AAF8))) {
                        s->hold[i] |= 0x400;
                    }
                    if (*(u32*)(pad + 0x18) & 0x800) {
                        s->hold[i] |= 0x40;
                    }
                    if (s->fe5) {
                        if (*(f32*)(pad + 0x2c) > lbl_8054168C) {
                            s->fe5 = 1;
                        } else {
                            s->fe5 = 0;
                        }
                    } else {
                        if (*(f32*)(pad + 0x2c) > lbl_80541690) {
                            s->fe5 = 1;
                        } else {
                            s->fe5 = 0;
                        }
                    }
                    if (s->fe5) {
                        s->hold[i] |= 0x20;
                    }
                    if (s->fe4) {
                        if (*(f32*)(pad + 0x28) > lbl_8054168C) {
                            s->fe4 = 1;
                        } else {
                            s->fe4 = 0;
                        }
                    } else {
                        if (*(f32*)(pad + 0x28) > lbl_80541690) {
                            s->fe4 = 1;
                        } else {
                            s->fe4 = 0;
                        }
                    }
                    if (s->fe4) {
                        s->hold[i] |= 0x40;
                    }
                    if (*(u32*)(pad + 0x18) & 0x100) {
                        s->hold[i] |= 0x100;
                    }
                    if (*(u32*)(pad + 0x18) & 0x200) {
                        s->hold[i] |= 0x200;
                    }
                    if (*(u32*)(pad + 0x18) & 0x1000) {
                        s->hold[i] |= 0x1000;
                    }
                    s->fe0[i] = 0;
                    break;
                case -1:
                default:
                    *(u32*)(lbl_804DB798[i] + 0x54) = 0;
                    resetMask |= 0x80000000 >> i;
                    break;
                }
            }
        }
    }
    if (resetMask != 0) {
        PADReset(resetMask);
    }
    fn_8030A078(s);
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
