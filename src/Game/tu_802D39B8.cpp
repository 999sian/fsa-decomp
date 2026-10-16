#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "sdk/stl/float.h"

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
extern const f32 lbl_80541160;
extern const f32 lbl_80541164;

struct Vec3f {
    f32 x, y, z;
};

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
void* fn_8023E724(s32);
s32 fn_8023CBC0();
s32 fn_80230498(s32, const Vec3f*, s32, s32, s32, s32, s32);
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
    RoomArrays* r = (RoomArrays*)p;
    s32 row = *(s32*)(p + 0x18);
    return r->roomNumbers[row][*(s32*)(p + 0x14)];
}

extern "C" bool fn_802D46D8(char*, s32 index, u32 bit, u8 set) {
    u32 word = bit / 32;
    if (!set) {
        RoomArrays* p = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        return (lbl_8046E1CC[bit % 32] & p->flags2D48[index][word]) != 0;
    }
    RoomArrays* p = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    p->flags2D48[index][word] |= lbl_8046E1CC[bit % 32];
    return true;
}

extern "C" void fn_802D4768(u8* p, s32 x, u16 v, s32* out, u32* out2) {
    RoomArrays* rooms = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    s32 base = (x < 8) ? 0 : x - 7;
    s32 idx = 0x3c;
    s32 cnt = 0xf;
    do {
        if (rooms->values2948[base][idx] == 0) {
            rooms->values2948[base][idx] = v;
            break;
        }
        idx -= 4;
        cnt--;
    } while (cnt != 0);
    s32 n = 0xf - (idx >> 2);
    out[1] = n;
    out[0] = n >> 31;
    if (x < 8) {
        u8* e = (u8*)rooms + *(s32*)(p + 0x18) * 0x280 + *(s32*)(p + 0x14) * 0x40;
        out2[0] = *(u32*)(e + 0x1048);
        out2[1] = *(u32*)(e + 0x104c);
    } else {
        u8* e = (u8*)rooms + *(s32*)(p + 0x18) * 0x280 + *(s32*)(p + 0x14) * 0x40 + (x << 3);
        out2[0] = *(u32*)(e + 0x1010);
        out2[1] = *(u32*)(e + 0x1014);
    }
}

extern "C" void fn_802D4874(u8* p, s32 x, u16 v, u32* out, u32* out2) {
    s32 base = (x < 8) ? 0 : x - 7;
    s32 idx;
    for (idx = 0; idx < 0x40; idx++) {
        RoomArrays* rooms = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        if (rooms->values2948[base][idx] == 0) {
            rooms->values2948[base][idx] = v;
            break;
        }
    }
    out[1] = 1;
    out[0] = 0;
    for (; idx != 0; idx--) {
        u32 hi = out[1];
        out[1] = hi << 1;
        out[0] = hi >> 0x1f | out[0] << 1;
    }
    RoomArrays* rooms = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    if (x < 8) {
        u8* e = (u8*)rooms + *(s32*)(p + 0x18) * 0x280 + *(s32*)(p + 0x14) * 0x40;
        out2[0] = *(u32*)(e + 0x1048);
        out2[1] = *(u32*)(e + 0x104c);
    } else {
        u8* e = (u8*)rooms + *(s32*)(p + 0x18) * 0x280 + *(s32*)(p + 0x14) * 0x40 + (x << 3);
        out2[0] = *(u32*)(e + 0x1010);
        out2[1] = *(u32*)(e + 0x1014);
    }
}

extern "C" bool fn_802D49A8(char* p, s32 x, u16 value) {
    s32 base = (x < 8) ? 0 : x - 7;
    s32 i;
    for (i = 0; i < 64; i++) {
        RoomArrays* rooms = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        if (rooms->values2948[base][i] == 0) {
            rooms->values2948[base][i] = value;
            break;
        }
    }
    u64 mask = 1;
    for (; i != 0; i--) {
        mask <<= 1;
    }
    u64 flags;
    if (x < 8) {
        RoomArrays* rooms = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        flags = rooms->flags1048[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)][0];
    } else {
        RoomArrays* rooms = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        flags = rooms->flags1048[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)][x - 7];
    }
    return (mask & flags) != 0;
}

extern "C" bool fn_802D4ADC(char* p, s32 x, u16 v) {
    s32 base = x < 8 ? 0 : x - 7;
    RoomArrays* rooms = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    s32 i;
    for (i = 0; i < 0x40; i++) {
        if (v == rooms->values2948[base][i]) {
            break;
        }
    }
    if (i < 0x40) {
        u64 mask = 1;
        for (;;) {
            if (i == 0) {
                break;
            }
            mask <<= 1;
            i--;
        }
        u64 word;
        if (x < 8) {
            word = rooms->flags1048[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)][0];
        } else {
            word = rooms->flags1048[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)][x - 7];
        }
        return (mask & word) != 0;
    }
    return false;
}

extern "C" s32 fn_802D4C10(char*, s32 index, u16 value) {
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    index = index < 8 ? 0 : index - 7;
    for (s32 i = 0; i < 64; ++i) {
        if (value == *(u16*)(p + index * 0x80 + 0x2948 + i * 2))
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
    u32* flags = ((RoomArrays*)p)->flagsFD68[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)];
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

extern const f32 lbl_80541120;
extern "C" void fn_802D6C10(char*, f32* pos, u32 id) {
    s32 off4 = 0;
    s32 off8 = 0;
    u32 i = 0;
    for (s32 n = 8; n != 0; n--) {
        char* rooms = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        if (id == *(u32*)(rooms + off4 + 0x13188)) {
            f32* pair = (f32*)(rooms + off8 + 0x13148);
            f32 eps = lbl_80541120 * FLT_EPSILON;
            f32 dx = pair[0] - pos[0];
            if (-eps <= dx && dx <= eps) {
                f32 dy = pair[1] - pos[1];
                if (-eps <= dy && dy <= eps) {
                    off4 = (s32)i * 4;
                    off8 = (s32)i * 8;
                    f32* dst = (f32*)(*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C) + off8 + 0x130E8);
                    dst[0] = lbl_8054111C;
                    dst[1] = lbl_8054111C;
                    *(s32*)(*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C) + off4 + 0x13128) = -1;
                    pair[0] = lbl_8054111C;
                    pair[1] = lbl_8054111C;
                    *(s32*)(*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C) + off4 + 0x13188) = -1;
                    return;
                }
            }
        }
        off4 += 4;
        off8 += 8;
        i++;
    }
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
    s32 word = bit / 32;
    s32 shift = bit % 32;
    return (((u32*)(p + 0x12F68))[word] & (1 << shift)) != 0;
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
    if (index >= 0 && index < 256) {
        char* base = p + 0x10000;
        char* rowp = base + *(s32*)(p + 0x18) * 0xa00;
        char* colp = rowp + *(s32*)(p + 0x14) * 0x100;
        return *(u8*)(colp + index - 0x6698);
    }
    return 0;
}

extern "C" void fn_802D7584(char* p, s32 index, u8 value) {
    if (index >= 0 && index < 256) {
        char* base = p + 0x10000;
        char* rowp = base + *(s32*)(p + 0x18) * 0xa00;
        char* colp = rowp + *(s32*)(p + 0x14) * 0x100;
        *((u8*)(colp + index) - 0x6698) = value;
    }
}

extern "C" bool fn_802D75BC(char* p, s32 bit) {
    s32 word = bit / 32;
    s32 shift = bit % 32;
    u32* flags = ((RoomArrays*)p)->flags6768[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)];
    return (flags[word] & (1U << shift)) != 0;
}

extern "C" void fn_802D7618(char* p, s32 bit) {
    char* q = p + *(s32*)(p + 0x18) * 0x500;
    q += *(s32*)(p + 0x14) * 0x80;
    q += (bit / 32) * 4;
    *(u32*)(q + 0x6768) |= 1U << (bit % 32);
}

extern "C" void fn_802D766C(char* p, u8 value, s32 index) {
    if (value != 0) {
        index = index < 8 ? 0 : index - 7;
        ++((s32*)(p + 0x6748))[index];
    }
}

extern "C" bool fn_802D76A8(char* p, s32 bit) {
    char* q = p + *(s32*)(p + 0x18) * 0x500;
    q += *(s32*)(p + 0x14) * 0x80;
    q += (bit / 32) * 4;
    return (*(u32*)(q + 0x3548) & (1U << (bit % 32))) != 0;
}

extern "C" void fn_802D7704(char* p, s32 bit, u8 value, s32 index) {
    char* q = p + *(s32*)(p + 0x18) * 0x500;
    q += *(s32*)(p + 0x14) * 0x80;
    q += (bit / 32) * 4;
    *(u32*)(q + 0x3548) |= 1U << (bit % 32);
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
    u16 v = ((u16*)(p + 0x131B8))[index];
    return (v & mask) != 0;
}

extern "C" void fn_802D782C(char*, u8 value) {
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    *(u8*)(p + 0x131DE) = value;
}

extern "C" void fn_802D7844(char*, u8 value, s32 index) {
    if (index >= 0 && index < 4) {
        u8* p = (u8*)*(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        p[0x131D8 + index] = value;
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
        RoomArrays* rooms = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        return rooms->flags1048[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)][0];
    }
    RoomArrays* rooms = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    return rooms->flags1048[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)][index - 7];
}

extern "C" u32 fn_802D7B34(char* p, s32 index, s32 digit) {
    index = index < 8 ? 0 : index - 7;
    s32 shift = 60 - digit * 4;
    u64 mask = (u64)15 << shift;
    RoomArrays* rooms = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    u64 value = rooms->flags1048[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)][index];
    return (mask & value) >> shift;
}

extern "C" void fn_802D7BE8(char* p, s32 index, s32 bit, u32 value) {
    index = index < 8 ? 0 : index - 7;
    RoomArrays* rooms = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    rooms->flags1048[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)][index] &= ~((u64)0xf << (0x3c - bit * 4));
    rooms = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    rooms->flags1048[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)][index] |= (u64)value << (0x3c - bit * 4);
}

extern "C" void fn_802D7D00(char* p, s32 index, s32 bit, u8 set) {
    index = index < 8 ? 0 : index - 7;
    if (set) {
        u64 mask = (u64)1 << bit;
        RoomArrays* rooms = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        rooms->flags1048[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)][index] |= mask;
    } else {
        u64 mask = (u64)1 << bit;
        RoomArrays* rooms = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        rooms->flags1048[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)][index] &= mask ^ (u64)-1;
    }
}

extern "C" u8 fn_802D7E04(char*, s32 index) {
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    return (p + index)[0x308];
}

extern "C" u8 fn_802D7E1C(char*, s32 index) {
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    return (p + index)[0x328];
}

extern "C" void fn_802D7E34(char*, s32 index) {
    RoomArrays* p = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    if (p->counters308[index] < 255)
        ++p->counters308[index];
}

extern "C" u8 fn_802D7E5C(char*, u8 index, s32 bit) {
    char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    u64 mask = *(u64*)(p + index * 0x320 + 0x3C8);
    return ((s64)(s32)(1U << bit) & mask) != 0;
}

extern "C" void fn_802D7EB0(char*, u8 index, s32 bit, u8 set) {
    if (set) {
        char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        char* e = p + index * 0x320;
        *(u64*)(e + 0x3C8) |= (s64)(s32)(1U << bit);
    } else {
        char* p = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        char* e = p + index * 0x320;
        *(u64*)(e + 0x3C8) &= (u64)~(1U << bit);
    }
}

extern "C" bool fn_802D7F40(char* p, s32 bit) {
    char* base = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    u32* row = ((RoomArrays*)base)->flags348[*(s32*)(p + 4)];
    return ((1U << bit) & row[*(s32*)(p + 8)]) != 0;
}

extern "C" void fn_802D7F84(char* p, s32 bit, u8 set) {
    if (set) {
        char* base = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        *(u32*)(base + *(s32*)(p + 4) * 16 + *(s32*)(p + 8) * 4 + 0x348) |= 1U << bit;
    } else {
        char* base = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        *(u32*)(base + *(s32*)(p + 4) * 16 + *(s32*)(p + 8) * 4 + 0x348) &= (1U << bit) ^ 0xFFFFFFFF;
    }
}

extern "C" bool fn_802D800C(char* p, s32 bit) {
    RoomArrays* rooms = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    return ((1U << bit) & rooms->flags178[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)]) != 0;
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
    if (x >= 0 && x < 10) {
        s32 y = *(s32*)(p + 0x18);
        if (y >= 0 && y < 10) {
            const char* name;
            s32 col = *(s32*)(p + 8);
            s32 row = *(s32*)(p + 4);
            if (*(u8*)(lbl_8053AAF8 + 0x7F) == 1)
                name = lbl_804A9530[row][col];
            else
                name = lbl_80541128;
            s32 number = ((RoomArrays*)(p + y * 10))->roomNumbers[0][x];
            if (number == 255)
                number = 0;
            sprintf(p + 0x1321A, lbl_8046E7E8, name, number / 10, number % 10, index - 7);
            return p + 0x1321A;
        }
    }
    return 0;
}

extern "C" char* fn_802D8228(char* p, s32 index) {
    s32 x = *(s32*)(p + 0x14);
    if (x >= 0 && x < 10) {
        s32 y = *(s32*)(p + 0x18);
        if (y >= 0 && y < 10) {
            s32 b = *(s32*)(p + 8);
            s32 a = *(s32*)(p + 4);
            const char* name;
            if (*(u8*)(lbl_8053AAF8 + 0x7F) == 1)
                name = lbl_804A9530[a][b];
            else
                name = lbl_80541128;
            s32 number = ((u8*)(p + y * 10))[x + 0x60];
            if (number == 255)
                number = 0;
            sprintf(p + 0x131FA, lbl_8046E804, name, number / 10, number % 10, index - 7);
            return p + 0x131FA;
        }
    }
    return 0;
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

extern "C" u8 fn_802DA630(char* p) {
    u8 flag = *(u8*)(*(char**)(lbl_8053AB10 + 0x24) + 0x1E8);
    if (flag == 0) {
        f32 offset;
        s32 i;
        Vec3f v;
        void* e;
        s32 count;

        offset = *(s32*)(p + 0x2C) > 0 ? lbl_80541160 : lbl_80541164;
        for (i = 0; i < 4; i++) {
            v = *(Vec3f*)fn_8023E724(i);
            v.x += offset;
            fn_80230498(i, &v, (u16)fn_8023CBC0(), 0xff, -0x80, -0x80, 1);
        }
        count = *(s32*)((char*)fn_801F856C() + 0x1008);
        for (i = 0; i < count; i++) {
            e = *(void**)((char*)fn_801F856C() + i * 4 + 8);
            if (e != NULL && *(s32*)((char*)e + 0x1A0) == 0x4F53494E && *(s32*)((char*)e + 0x230) == 2) {
                v = *(Vec3f*)((char*)e + 0xC);
                v.x += offset;
                *(Vec3f*)((char*)e + 0xC) = v;
                break;
            }
        }
    }
    return flag;
}

extern "C" u8 fn_802DEDFC(s32 value);
extern "C" void fn_8038D454(void);
extern "C" void fn_8022BD70(void);
extern "C" void fn_8037AE30(void* p);
extern "C" void fn_8023F1D4(int idx, void* pos, int a, int b, u8 c);
extern void* lbl_8053AD70;
extern const f32 lbl_8046E148[];
extern "C" void fn_802DA788(char* p) {
    if (*(s32*)(p + 0x14) < *(s32*)(p + 0x1c)) {
        *(s32*)(p + 0x2c) = 1;
        *(s32*)(p + 0x30) = 0;
    } else {
        *(s32*)(p + 0x2c) = -1;
        *(s32*)(p + 0x30) = 0;
    }
    if (fn_802DEDFC((s32)(p + 0x2c))) {
        fn_8038D454();
        fn_801F7CAC(fn_801F856C());
        fn_801F6204(fn_801F856C(), 0);
        fn_80308D0C();
        char* base = *(char**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
        *(u8*)(base + 0x131DE) = 0;
        fn_8013C8CC(fn_8013C824());
        s32 i = 0;
        *(u8*)(p + 0xC9) = i;
        const f32* t = lbl_8046E148;
        do {
            f32 v[3];
            v[0] = t[0];
            v[1] = t[1];
            v[2] = t[2];
            v[0] = v[0] + *(f32*)(p + 0xCC);
            v[1] = v[1] + *(f32*)(p + 0xD0);
            fn_8023F1D4(i, v, 2, 0, 0);
            i++;
            t += 3;
        } while (i < 4);
        fn_8022BD70();
        fn_8037AE30(lbl_8053AD70);
        if (*(u8*)(lbl_8053AAF8 + 0x7F) == 1) {
            *(s32*)(p + 0xC4) = 36000;
        } else {
            *(s32*)(p + 0xC4) = 0x2A30;
        }
    }
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

extern "C" u8 fn_802DD3D4(char* p, s32* param_2) {
    s32 col = *(s32*)(p + 0x14);
    s32 row = *(s32*)(p + 0x18);
    u32 result = 0;
    u32 mask = 0xf;
    *(u8*)(p + 0xc9) = 0;
    if (*(u8*)(*(char**)(lbl_8053AB10 + 0x24) + 0x1e8) == 0) {
        s32 count = *(s32*)((char*)fn_801F856C() + 0x1008);
        s32 off = 0;
        for (s32 i = 0; i < count; i++) {
            char* e = *(char**)((char*)fn_801F856C() + off + 8);
            if (e != 0 && *(s32*)(e + 0x1a0) == 0x5344534d) {
                mask = *(u32*)(e + 0x90) >> 4;
                break;
            }
            off += 4;
        }
        if (*param_2 > 0) {
            col++;
            *(u8*)(p + 0xc8) = 1;
        } else if (*param_2 < 0) {
            col--;
            *(u8*)(p + 0xc8) = 2;
        } else if (param_2[1] > 0) {
            row++;
            *(u8*)(p + 0xc8) = 4;
        } else {
            row--;
            *(u8*)(p + 0xc8) = 8;
        }
        if (row >= 0 && row < 10 && col >= 0 && col < 10) {
            u8* cell = (u8*)(p + row * 10 + col);
            if (cell[0x60] != 0xff) {
                if ((mask & *(u8*)(p + 0xc8)) != 0) {
                    result = 1;
                } else {
                    *(u8*)(p + 0xc9) = 1;
                }
            } else if ((mask & *(u8*)(p + 0xc8)) == 0) {
                *(u8*)(p + 0xc9) = 1;
            }
        }
    }
    return result;
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

extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void __ct__Q29JGeometry8TVec2_f_Fv();
extern const f32 lbl_80541144;
extern "C" void* fn_802DE64C(char* p) {
    *(void**)p = lbl_804A9950;
    __construct_array(p + 0xf0, (void*)__ct__Q29JGeometry8TVec2_f_Fv, 0, 8, 0x10);
    __construct_array(p + 0x13088, (void*)__ct__Q29JGeometry8TVec2_f_Fv, 0, 8, 8);
    __construct_array(p + 0x130e8, (void*)__ct__Q29JGeometry8TVec2_f_Fv, 0, 8, 8);
    __construct_array(p + 0x13148, (void*)__ct__Q29JGeometry8TVec2_f_Fv, 0, 8, 8);
    *(s32*)(p + 0x4) = 0;
    *(s32*)(p + 0x8) = 0;
    *(s32*)(p + 0x14) = 0;
    *(s32*)(p + 0x18) = 0;
    *(s32*)(p + 0x34) = 0;
    *(s32*)(p + 0x38) = 0;
    *(s32*)(p + 0x3c) = 0;
    *(s32*)(p + 0x40) = 0;
    *(s32*)(p + 0x44) = 0;
    *(s32*)(p + 0x48) = 0;
    *(s32*)(p + 0x4c) = 0;
    *(s32*)(p + 0x50) = 0;
    *(s32*)(p + 0x54) = 0;
    *(s32*)(p + 0x58) = 0;
    *(s32*)(p + 0xec) = 0;
    *(f32*)(p + 0xdc) = lbl_8054111C;
    *(f32*)(p + 0xe0) = lbl_8054111C;
    *(f32*)(p + 0xe4) = lbl_80541144;
    *(f32*)(p + 0xe8) = lbl_80541144;
    *(u8*)(p + 0x131f7) = 0;
    *(u8*)(p + 0x131f8) = 0;
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

extern "C" bool fn_802DE814(void) {
    if (*(u8*)(lbl_8053AAF8 + 0x7F) == 0)
        return false;
    s32 state = *(s32*)(lbl_80529DEC + 0x118);
    if (state == 0 && *(s32*)(lbl_80529DEC + 0x11C) == 2)
        return true;
    if (state == 1 && *(s32*)(lbl_80529DEC + 0x11C) == 2)
        return true;
    if (state == 2 && *(s32*)(lbl_80529DEC + 0x11C) == 2)
        return true;
    if (state == 3 && *(s32*)(lbl_80529DEC + 0x11C) == 2)
        return true;
    if (state == 4 && *(s32*)(lbl_80529DEC + 0x11C) == 2)
        return true;
    if (state == 5 && *(s32*)(lbl_80529DEC + 0x11C) == 2)
        return true;
    if (state == 6 && *(s32*)(lbl_80529DEC + 0x11C) == 2)
        return true;
    if (state == 7 && *(s32*)(lbl_80529DEC + 0x11C) == 1)
        return true;
    if (state == 10 && *(s32*)(lbl_80529DEC + 0x11C) == 2)
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
        char* root = *(char**)(lbl_8053AAF8 + 4);
        char* p = *(char**)(root + 0x0C);
        if (*(s32*)(p + 4) == 6 && *(s32*)(p + 8) == 0)
            return true;
        p = *(char**)(root + 0x0C);
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
        char* root = *(char**)(lbl_8053AAF8 + 4);
        char* p = *(char**)(root + 0x0C);
        if (*(s32*)(p + 4) == 7 && *(s32*)(p + 8) == 0)
            return true;
        p = *(char**)(root + 0x0C);
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
    char* root = *(char**)(lbl_8053AAF8 + 4);
    char* p = *(char**)(root + 0x0C);
    if (*(s32*)(p + 4) == 9 && *(s32*)(p + 8) == 3)
        return true;
    p = *(char**)(root + 0x0C);
    if (*(s32*)(p + 4) >= 13)
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
    RoomArrays* base = *(RoomArrays**)(root + 0x0C);
    base->flags1048[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)][index] &= mask ^ 0xFFFFFFFFFFFFFFFFULL;
    u64 bits = (u64)value << shift;
    base = *(RoomArrays**)(*(char**)(lbl_8053AAF8 + 4) + 0x0C);
    base->flags1048[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)][index] |= bits;
}

extern "C" u32 fn_802DED40(s32 index, s32 digit) {
    index = index < 8 ? 0 : index - 7;
    s32 shift = 60 - digit * 4;
    char* root = *(char**)(lbl_8053AAF8 + 4);
    char* p = *(char**)(root + 0x0C);
    u64 mask = (u64)15 << shift;
    RoomArrays* rooms = *(RoomArrays**)(root + 0x0C);
    u64 value = rooms->flags1048[*(s32*)(p + 0x18)][*(s32*)(p + 0x14)][index];
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
