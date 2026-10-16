#include "types.h"

#pragma auto_inline off

#if defined(VERSION_G4SP01)
extern "C" int fn_801365A8(void);
extern "C" int fn_80045948(void);
#endif

struct RoomMaskEntry {
    u64 flags;
    u8 pad08[0x318];
};

struct RoomArrays {
    u8 pad00[0x60];
    u8 roomNumbers[10][10];
    u8 padC4[0x2C];
    f32 pairsF0[16][2];
    u8 pad170[8];
    u32 flags178[10][10];
    u8 counters308[32];
    u8 values328[32];
    u32 flags348[8][4];
    RoomMaskEntry masks3C8[4];
    u64 flags1048[10][10][8];
    u16 values2948[8][64];
    u32 flags2D48[4][128];
    u32 flags3548[10][10][32];
    s32 counts6748[8];
    u32 flags6768[10][10][32];
    u8 values9968[10][10][256];
    u32 flagsFD68[10][10][32];
    u32 flags12F68[32];
    u32 flags12FE8[32];
    u8 pad13068[0x150];
    u16 flags131B8[16];
    u8 values131D8[4];
    u8 pad131DC[0x70];
    f32 values1324C[4];
    f32 values1325C[4];
    f32 values1326C[4];
    u8 values1327C[4];
};

extern char* lbl_8053AAF8;
extern char* lbl_8053AB10;
extern u8 lbl_8050EC80[];
extern u8 lbl_80529DEC[];
extern const u32 lbl_8046E1CC[];
extern const char* lbl_804A9530[][4];
extern const char* lbl_804A9660[];
extern const char* lbl_804A96D0[];
extern void* lbl_804A9950[];
extern const char lbl_8046E7E8[];
extern const char lbl_8046E804[];
extern const char lbl_8054106C[1];
extern const char lbl_805410DC[2];
extern const char lbl_80541128[1];
extern const f32 lbl_8054111C;
extern const f32 lbl_80541124;

extern "C" {
int sprintf(char*, const char*, ...);
void __dl__FPv(void*);
void* fn_8013C824();
void fn_8013C8CC(void*);
void* fn_801F856C();
void fn_801F7CAC(void*);
void fn_801F7E88(void*);
void fn_801F6204(void*, u8);
void fn_80231424();
void fn_80308D0C();
void fn_8030C85C(void*);
void fn_8030C928(void*, const f32*);
void fn_802D8328(char*, u8, u8);
void fn_802D8D50(char*, u8);
u8 fn_802DCE5C(char*, s32);
}

extern "C" void fn_802D39B8(char* p, s32 index, s32 value) {
    ((s32*)(p + 0x131A8))[index] = value;
}

extern "C" bool fn_802D39CC(char* p) {
    if (*(s32*)(p + 0x18) == *(s32*)(p + 0x10)
        && *(s32*)(p + 0x14) == *(s32*)(p + 0x0C))
        return true;
    return false;
}

extern "C" u8 fn_802D39FC(char* p) {
    s32 x = *(s32*)(p + 0x14);
    return ((RoomArrays*)p)->roomNumbers[*(s32*)(p + 0x18)][x];
}

extern "C" bool fn_802D46D8(char*, s32 index, u32 bit, u8 set) {
    if (!set) {
        char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        return (lbl_8046E1CC[bit % 32] & ((u32*)(p + 0x2D48 + index * 0x200))[bit / 32]) != 0;
    }
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    ((u32*)(p + 0x2D48 + index * 0x200))[bit / 32] |= lbl_8046E1CC[bit % 32];
    return true;
}

extern "C" s32 fn_802D4C10(char*, s32 index, u16 value) {
    index = index < 8 ? 0 : index - 7;
    for (s32 i = 0; i < 64; ++i) {
        char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        if (value == ((RoomArrays*)p)->values2948[index][i])
            return i;
    }
    return -1;
}

extern "C" char* fn_802D6A9C() {
    return *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
}

extern "C" void fn_802D6AAC(char*, u8 value) {
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    *(u8*)(p + 0x131F9) = value;
}

extern "C" bool fn_802D6AC4(char* p, s32 bit) {
    u32* flags = (u32*)(p + 0xFD68 + *(s32*)(p + 0x18) * 0x500 + *(s32*)(p + 0x14) * 0x80);
    return (flags[bit / 32] & (1U << (bit % 32))) != 0;
}

extern "C" void fn_802D6B24(char* p, s32 bit, u8 set) {
    s32 word = bit / 32;
    s32 shift = bit % 32;
    if (set) {
        ((RoomArrays*)p)->flagsFD68[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)][word] |= 1U << shift;
    } else {
        ((RoomArrays*)p)->flagsFD68[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)][word] &= (1U << shift) ^ 0xFFFFFFFF;
    }
}

extern "C" void fn_802D6BC8(char*, u8 value) {
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    *(u8*)(p + 0x131F4) = value;
}

extern "C" void fn_802D6BE0(char*, u8 value) {
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    *(u8*)(p + 0x131F3) = value;
}

extern "C" void fn_802D6BF8(char*, u8 value) {
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    *(u8*)(p + 0x131F2) = value;
}

extern "C" bool fn_802D72BC(char*, s32 bit) {
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    return (((u32*)(p + 0x12FE8))[bit / 32] & (1U << (bit % 32))) != 0;
}

extern "C" void fn_802D7310(char* p, s32 bit, u8 set) {
    s32 word = bit / 32;
    s32 shift = bit % 32;
    if (set)
        ((u32*)(p + 0x12FE8))[word] |= 1U << shift;
    else
        ((u32*)(p + 0x12FE8))[word] &= (1U << shift) ^ 0xFFFFFFFF;
}

extern "C" bool fn_802D7384(char* p, s32 bit) {
    return (((RoomArrays*)p)->flags12F68[bit / 32] & (1U << (bit % 32))) != 0;
}

extern "C" void fn_802D73CC(char* p, s32 bit, u8 set) {
    s32 word = bit / 32;
    s32 shift = bit % 32;
    if (set)
        ((u32*)(p + 0x12F68))[word] |= 1U << shift;
    else
        ((u32*)(p + 0x12F68))[word] &= (1U << shift) ^ 0xFFFFFFFF;
}

extern "C" void fn_802D7440(char*, u8 value) {
    if (value == 1) {
        u8 mode = *(u8*)(lbl_8053AAF8 + 0x7F);
        u8 enabled;
        if (mode != 0)
            enabled = lbl_8050EC80[*(s32*)(lbl_8050EC80 + 0x10) * 0xC8 + 0x7C];
        else
            enabled = lbl_8050EC80[*(s32*)(lbl_8050EC80 + 0x10) * 0xC8 + 0x7D];
        if (enabled != 1) {
            char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
            *(u8*)(p + 0x131F0) = 0;
        } else if (mode != 0) {
            if (*(u8*)(lbl_8053AAF8 + 0x7E) == 1) {
                char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
                *(u8*)(p + 0x131F0) = 1;
            } else {
                char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
                *(u8*)(p + 0x131F0) = 0;
            }
        } else {
            char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
            *(u8*)(p + 0x131F0) = 1;
        }
    } else {
        char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        *(u8*)(p + 0x131F0) = 0;
    }
}

extern "C" void fn_802D752C(char*, u8 value) {
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    *(u8*)(p + 0x131EF) = value;
}

extern "C" u8 fn_802D7544(char* p, s32 index) {
    if (index >= 0 && index < 256)
        return ((RoomArrays*)p)->values9968[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)][index];
    return 0;
}

extern "C" void fn_802D7584(char* p, s32 index, u8 value) {
    if (index >= 0 && index < 256)
        ((RoomArrays*)p)->values9968[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)][index] = value;
}

extern "C" bool fn_802D75BC(char* p, s32 bit) {
    u32* flags = (u32*)(p + *(s32*)(p + 0x18) * 0x500 + *(s32*)(p + 0x14) * 0x80 + 0x6768);
    return (flags[bit / 32] & (1U << (bit % 32))) != 0;
}

extern "C" void fn_802D7618(char* p, s32 bit) {
    u32* flags = (u32*)(p + *(s32*)(p + 0x18) * 0x500 + *(s32*)(p + 0x14) * 0x80 + 0x6768);
    flags[bit / 32] |= 1U << (bit % 32);
}

extern "C" void fn_802D766C(char* p, u8 value, s32 index) {
    if (value != 0) {
        index = index < 8 ? 0 : index - 7;
        ++((s32*)(p + 0x6748))[index];
    }
}

extern "C" bool fn_802D76A8(char* p, s32 bit) {
    u32* flags = (u32*)(p + *(s32*)(p + 0x18) * 0x500 + *(s32*)(p + 0x14) * 0x80 + 0x3548);
    return (flags[bit / 32] & (1U << (bit % 32))) != 0;
}

extern "C" void fn_802D7704(char* p, s32 bit, u8 value, s32 index) {
    u32* flags = (u32*)(p + *(s32*)(p + 0x18) * 0x500 + *(s32*)(p + 0x14) * 0x80 + 0x3548);
    flags[bit / 32] |= 1U << (bit % 32);
    if (value != 0) {
        index = index < 8 ? 0 : index - 7;
        ++((s32*)(p + 0x6748))[index];
    }
}

extern "C" void fn_802D7790(char*, s32 index, u32 mask) {
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    ((u16*)(p + 0x131B8))[index] &= mask ^ 0xFF;
}

extern "C" void fn_802D77BC(char*, s32 index, u32 mask) {
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    ((u16*)(p + 0x131B8))[index] |= mask;
}

extern "C" void fn_802D77E4(char*, s32 index, u16 value) {
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    ((u16*)(p + 0x131B8))[index] = value;
}

extern "C" bool fn_802D7804(char* p, s32 index, u16 mask) {
    return (((u16*)(p + 0x131B8))[index] & mask) != 0;
}

extern "C" void fn_802D782C(char*, u8 value) {
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    *(u8*)(p + 0x131DE) = value;
}

extern "C" void fn_802D7844(char*, u8 value, s32 index) {
    if (index >= 0 && index < 4) {
        char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        ((RoomArrays*)p)->values131D8[index] = value;
    }
}

extern "C" void fn_802D7870(char*, u16 value) {
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    *(u16*)(p + 0x131DC) = value;
}

extern "C" bool fn_802D7888(char*, s32 bit) {
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    return ((1U << bit) & *(u32*)(p + 0x174)) != 0;
}

extern "C" void fn_802D78B4(char*, s32 bit, u8 set) {
    if (set) {
        char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        *(u32*)(p + 0x174) |= 1U << bit;
    } else {
        char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        *(u32*)(p + 0x174) &= (1U << bit) ^ 0xFFFFFFFF;
    }
}

extern "C" void fn_802D790C(char*, u8 value) {
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    *(u8*)(p + 0x171) = value;
}

extern "C" void fn_802D7920(char*, u8 value) {
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    *(u8*)(p + 0x170) = value;
}

extern "C" void fn_802D7934(char*, s32 value) {
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    *(s32*)(p + 0x5C) = value;
}

extern "C" s32 fn_802D7948(char*) {
    s32 value;
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    value = *(s32*)(p + 0x5C);
    if (value == 0)
        return *(s32*)(p + 0x58);
    return value - 1;
}

extern "C" void fn_802D7970(char*, s32 value) {
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    *(s32*)(p + 0x34) = value;
    if (value < 17) {
        p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        *(s32*)(p + 0x1328C) = 0;
    }
}

extern "C" void fn_802D79A4(char* p, s32 index, f32 a, f32 b, f32 c) {
    RoomArrays* rooms = (RoomArrays*)p;
    if (rooms->values1327C[index] == 0 && lbl_8054111C == rooms->values1324C[index]) {
        rooms->values1324C[index] = a;
        rooms->values1325C[index] = b;
        rooms->values1326C[index] = c;
        rooms->values1327C[index] = 1;
    }
}

extern "C" void fn_802D79E8(char* p, s32 index, u8 value, f32 a, f32 b) {
    RoomArrays* rooms = (RoomArrays*)p;
    if (rooms->pairsF0[index][0] < b)
        rooms->pairsF0[index][0] = b;
    if (rooms->pairsF0[index][1] < a)
        rooms->pairsF0[index][1] = a;
    if (value == 0) {
        b = lbl_80541124 * b;
        a = lbl_80541124 * a;
        for (s32 i = 0; i < 16; ++i) {
            f32* entry = (f32*)(p + 0xF0 + i * 8);
            if (entry[0] < b)
                entry[0] = b;
            if (entry[1] < a)
                entry[1] = a;
        }
    }
}

extern "C" u64 fn_802D7AC4(char* p, s32 index) {
    if (index < 8) {
        char* base = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        return ((RoomArrays*)base)->flags1048[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)][0];
    }
    char* base = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    return ((RoomArrays*)base)->flags1048[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)][index - 7];
}

extern "C" u32 fn_802D7B34(char* p, s32 index, s32 digit) {
    index = index < 8 ? 0 : index - 7;
    s32 shift = 60 - digit * 4;
    u64 mask = (u64)15 << shift;
    char* base = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    u64 value = ((RoomArrays*)base)->flags1048[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)][index];
    return (value & mask) >> shift;
}

extern "C" void fn_802D7D00(char* p, s32 index, s32 bit, u8 set) {
    index = index < 8 ? 0 : index - 7;
    if (set) {
        u64 mask = (u64)1 << bit;
        char* base = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        ((RoomArrays*)base)->flags1048[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)][index] |= mask;
    } else {
        u64 mask = (u64)1 << bit;
        char* base = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        ((RoomArrays*)base)->flags1048[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)][index] &= ~mask;
    }
}

extern "C" u8 fn_802D7E04(char*, s32 index) {
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    return (p + index)[0x308];
}

extern "C" u8 fn_802D7E1C(char*, s32 index) {
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    return *(u8*)(p + index + 0x328);
}

extern "C" void fn_802D7E34(char*, s32 index) {
    RoomArrays* p = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    if (p->counters308[index] < 255)
        ++p->counters308[index];
}

extern "C" u8 fn_802D7E5C(char*, u8 index, s32 bit) {
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    return ((s64)(s32)(1U << bit) & ((RoomArrays*)p)->masks3C8[index].flags) != 0;
}

extern "C" void fn_802D7EB0(char*, u8 index, s32 bit, u8 set) {
    if (set) {
        char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        *(u64*)(p + 0x3C8 + index * 0x320) |= (s64)(s32)(1U << bit);
    } else {
        char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        *(u64*)(p + 0x3C8 + index * 0x320) &= (u64)~(1U << bit);
    }
}

extern "C" bool fn_802D7F40(char* p, s32 bit) {
    char* base = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    return ((1U << bit) & ((RoomArrays*)base)->flags348[*(s32*)(p + 4)][*(s32*)(p + 8)]) != 0;
}

extern "C" void fn_802D7F84(char* p, s32 bit, u8 set) {
    if (set) {
        char* base = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        ((RoomArrays*)base)->flags348[*(s32*)(p + 4)][*(s32*)(p + 8)] |= 1U << bit;
    } else {
        char* base = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        ((RoomArrays*)base)->flags348[*(s32*)(p + 4)][*(s32*)(p + 8)] &= (1U << bit) ^ 0xFFFFFFFF;
    }
}

extern "C" bool fn_802D800C(char* p, s32 bit) {
    char* base = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    return ((1U << bit) & ((RoomArrays*)base)->flags178[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)]) != 0;
}

extern "C" void fn_802D8050(char* p, s32 bit, u8 set, u8 value) {
    if (set) {
        RoomArrays* base = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        base->flags178[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)] |= 1U << bit;
        base = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        if (base->counters308[bit] < 255)
            ++base->counters308[bit];
        base = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        base->values328[bit] = value;
    } else {
        RoomArrays* base = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        base->flags178[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)] &= (1U << bit) ^ 0xFFFFFFFF;
        base = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        base->values328[bit] = 255;
    }
}

extern "C" char* fn_802D8128(char* p, s32 index) {
    s32 x = *(s32*)(p + 0x14);
    if (x < 0 || x >= 10)
        return 0;
    s32 y = *(s32*)(p + 0x18);
    if (y < 0 || y >= 10)
        return 0;
    const char* name;
    if (*(u8*)(lbl_8053AAF8 + 0x7F) == 1)
        name = lbl_804A9530[*(s32*)(p + 4)][*(s32*)(p + 8)];
    else
        name = lbl_80541128;
    s32 number = ((RoomArrays*)p)->roomNumbers[y][x];
    if (number == 255)
        number = 0;
    sprintf(p + 0x1321A, lbl_8046E7E8, name, number / 10, number % 10, index - 7);
    return p + 0x1321A;
}

extern "C" char* fn_802D8228(char* p, s32 index) {
    s32 x = *(s32*)(p + 0x14);
    if (x < 0 || x >= 10)
        return 0;
    s32 y = *(s32*)(p + 0x18);
    if (y < 0 || y >= 10)
        return 0;
    const char* name;
    if (*(u8*)(lbl_8053AAF8 + 0x7F) == 1)
        name = lbl_804A9530[*(s32*)(p + 4)][*(s32*)(p + 8)];
    else
        name = lbl_80541128;
    s32 number = ((RoomArrays*)p)->roomNumbers[y][x];
    if (number == 255)
        number = 0;
    sprintf(p + 0x131FA, lbl_8046E804, name, number / 10, number % 10, index - 7);
    return p + 0x131FA;
}

extern "C" const char* fn_802D9C1C(char* p) {
    s32 index = *(s32*)(p + 0x44);
    if (index >= 0 && index < 16)
        return lbl_804A96D0[index];
    return lbl_805410DC;
}

extern "C" const char* fn_802D9C4C(char* p) {
    s32 index = *(s32*)(p + 0x40);
    if (index >= 0 && index < 28)
        return lbl_804A9660[index];
    return lbl_8054106C;
}

extern "C" const char* fn_802D9C7C(char*, s32 a, s32 b) {
    if (*(u8*)(lbl_8053AAF8 + 0x7F) == 1)
        return lbl_804A9530[a][b];
    return lbl_80541128;
}

extern "C" void fn_802D9CB0(char*) {
    fn_8030C85C(*(void**)(lbl_8053AB10 + 0x24));
}

extern "C" void fn_802D9FBC(char* p) {
    if (*(u8*)(lbl_8053AAF8 + 0x7F) == 1)
        *(s32*)(p + 0xC4) = 0x8CA0;
    else
        *(s32*)(p + 0xC4) = 0x2A30;
}

extern "C" void fn_802D9FE8(char* p, s32 a, s32 b) {
    *(s32*)(p + 0x1C) = a;
    *(s32*)(p + 0x20) = b;
}

extern "C" void fn_802D9FF4(char* p, s32 a, s32 b) {
    *(s32*)(p + 0x24) = a;
    *(s32*)(p + 0x28) = b;
}

extern "C" u8 fn_802DA000(char*) {
    return *(u8*)(*(char**)(lbl_8053AB10 + 0x24) + 0x1E8);
}

extern "C" u8 fn_802DCD0C(char*) {
    return *(u8*)(*(char**)(lbl_8053AB10 + 0x24) + 0x1E8);
}

extern "C" u8 fn_802DCD1C(char* p, const s32* direction) {
    s32 result = 0;
    if (*(u8*)(*(char**)(lbl_8053AB10 + 0x24) + 0x1E8) == 0) {
        if (direction[0] > 0)
            ++*(s32*)(p + 0x14);
        else if (direction[0] < 0)
            --*(s32*)(p + 0x14);
        else if (direction[1] > 0)
            ++*(s32*)(p + 0x18);
        else
            --*(s32*)(p + 0x18);
        fn_80231424();
        fn_801F7E88(fn_801F856C());
        fn_802D8D50(p, 1);
        fn_802D8328(p, 0, 0);
        fn_8030C928(*(void**)(lbl_8053AB10 + 0x24), (const f32*)(p + 0xCC));
        result = 1;
    }
    return result;
}

extern "C" void fn_802DCDF4(char* p) {
    fn_801F7CAC(fn_801F856C());
    fn_801F6204(fn_801F856C(), 0);
    fn_80308D0C();
    char* base = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    *(u8*)(base + 0x131DE) = 0;
    fn_8013C8CC(fn_8013C824());
    *(u8*)(p + 0xC9) = 0;
}

extern "C" void fn_802DD548(void) {
}

extern "C" void* fn_802DE604(void* p, s16 freeFlag) {
    if (p != 0) {
        *(void**)p = lbl_804A9950;
        if (freeFlag > 0)
            __dl__FPv(p);
    }
    return p;
}

extern "C" bool fn_802DE764(s32 a, s32 b, s32 c) {
    if (*(u8*)(lbl_8053AAF8 + 0x7F) == 0)
        return false;
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    if (a == *(s32*)(p + 4) && b == *(s32*)(p + 8)
        && c == (u8)(p + *(s32*)(p + 0x18) * 10)[*(s32*)(p + 0x14) + 0x60])
        return true;
    return false;
}

extern "C" bool fn_802DE7CC() {
    if (*(u8*)(lbl_8053AAF8 + 0x7F) == 0)
        return false;
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    if (*(s32*)(p + 4) == 0 && *(s32*)(p + 8) == 0)
        return true;
    return false;
}

extern "C" bool fn_802DE93C() {
    if (*(u8*)(lbl_8053AAF8 + 0x7F) != 0) {
        char* q = *(char**)(lbl_8053AAF8 + 4);
        if (*(s32*)(*(char**)(q + 0xC) + 4) == 4 && *(s32*)(*(char**)(q + 0xC) + 8) == 0)
            return true;
        if (*(s32*)(*(char**)(q + 0xC) + 4) == 7 && *(s32*)(*(char**)(q + 0xC) + 8) == 2)
            return true;
        return false;
    }
    return false;
}

extern "C" bool fn_802DE9A0() {
    if (*(u8*)(lbl_8053AAF8 + 0x7F) != 0) {
        char* q = *(char**)(lbl_8053AAF8 + 4);
        if (*(s32*)(*(char**)(q + 0xC) + 4) == 2 && *(s32*)(*(char**)(q + 0xC) + 8) == 3)
            return true;
        if (*(s32*)(*(char**)(q + 0xC) + 4) == 7 && *(s32*)(*(char**)(q + 0xC) + 8) == 1)
            return true;
        return false;
    }
    s32 index = *(s32*)(lbl_80529DEC + 0x12C) + *(s32*)(lbl_80529DEC + 0x128) * 4;
    if (index == 1 || index == 6)
        return true;
    return false;
}

extern "C" bool fn_802DEA34() {
    if (*(u8*)(lbl_8053AAF8 + 0x7F) != 0) {
        char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        if (*(s32*)(p + 4) == 6 && *(s32*)(p + 8) == 0)
            return true;
        p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        if (*(s32*)(p + 4) == 6 && *(s32*)(p + 8) == 1)
            return true;
        if (*(s32*)(p + 4) == 6 && *(s32*)(p + 8) == 3)
            return true;
        return false;
    }
    return false;
}

extern "C" bool fn_802DEABC() {
    if (*(u8*)(lbl_8053AAF8 + 0x7F) != 0) {
        char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        if (*(s32*)(p + 4) == 7 && *(s32*)(p + 8) == 0)
            return true;
        p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        if (*(s32*)(p + 4) == 7 && *(s32*)(p + 8) == 2)
            return true;
        return false;
    }
    s32 index = *(s32*)(lbl_80529DEC + 0x12C) + *(s32*)(lbl_80529DEC + 0x128) * 4;
    if (index == 4 || index == 9)
        return true;
    return false;
}

extern "C" bool fn_802DEB58() {
    if (*(u8*)(lbl_8053AAF8 + 0x7F) == 0)
        return false;
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    if (*(s32*)(p + 4) == 3 && *(s32*)(p + 8) == 1)
        return true;
    return false;
}

extern "C" bool fn_802DEBA0() {
    if (*(u8*)(lbl_8053AAF8 + 0x7F) == 0)
        return false;
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    if ((*(s32*)(p + 4) == 9 && *(s32*)(p + 8) == 3) || *(s32*)(p + 4) >= 13)
        return true;
    return false;
}

extern "C" bool fn_802DEBF8() {
    if (*(u8*)(lbl_8053AAF8 + 0x7F) == 0)
        return false;
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    if (*(s32*)(p + 4) == 8 && *(s32*)(p + 8) == 3)
        return true;
    return false;
}

extern "C" void fn_802DEC40(s32 index, s32 digit, u32 value) {
    char* root = *(char**)(lbl_8053AAF8 + 4);
    char* p = *(char**)(root + 0x0C);
    index = index < 8 ? 0 : index - 7;
    s32 shift = 60 - digit * 4;
    u64 mask = (u64)15 << shift;
    char* base = *(char**)(root + 0x0C);
    ((RoomArrays*)base)->flags1048[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)][index] &= ~mask;
    u64 bits = (u64)value << shift;
    base = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    ((RoomArrays*)base)->flags1048[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)][index] |= bits;
}

extern "C" u32 fn_802DED40(s32 index, s32 digit) {
    index = index < 8 ? 0 : index - 7;
    s32 shift = 60 - digit * 4;
    char* root = *(char**)(lbl_8053AAF8 + 4);
    char* p = *(char**)(root + 0x0C);
    u64 mask = (u64)15 << shift;
    char* base = *(char**)(root + 0x0C);
    u64 value = ((RoomArrays*)base)->flags1048[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)][index];
    return (value & mask) >> shift;
}

extern "C" u8 fn_802DEDFC(s32 value) {
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    return fn_802DCE5C(p, value);
}

// Keep regional definitions that were present before source-tree consolidation.
#if defined(VERSION_G4SP01)
extern "C" void fn_802E0BD0(char* p)
{
    if (lbl_8053AAF8[0x7f] == 1) {
        if (fn_801365A8() == 1 && fn_80045948() != 1) {
            *(int*)(p + 0xc4) = 30000;
        } else {
            *(int*)(p + 0xc4) = 36000;
        }
    } else {
        if (fn_801365A8() == 1 && fn_80045948() != 1) {
            *(int*)(p + 0xc4) = 9000;
        } else {
            *(int*)(p + 0xc4) = 10800;
        }
    }
}
#endif
