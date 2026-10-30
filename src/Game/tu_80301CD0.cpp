// TU 0x80301cd0-0x803099fc.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"
#define GAME_ACTOR_USE_SDK_VEC
#include "JSystem/JGeometry/Vec.h"
#include "Game/ItemBase.h"
#include "JSystem/JKernel/JKRFileLoader.h"
extern "C" u8 fn_8022F5B0(s32);
extern "C" void fn_803085A4(s32,s32);

// ---- Per-player game state (indexed by fn_8022F340(), the player slot) ----
extern "C" s32 fn_8022F340();
extern "C" s32 fn_8030AAF4(s32 i);
extern "C" u8 fn_8030A308(void* pad, s32 i);
extern "C" s32 fn_8022EA0C(s32);
extern "C" s32 fn_8023DE58(s32);
extern "C" u32 fn_8023D9B0(void*, s32);
extern "C" u8 fn_8023D4F8(void*, s32);
extern void* lbl_8053AD30;
extern u8 lbl_80471208[];
extern u8* lbl_8053AB10;
extern "C" void fn_802F86CC(void* mgr, void* pos, void* res, s32 id, f32 sx, f32 sy, DrawRec* prm);
extern "C" void PSMTXScale(f32 m[3][4], f32 xS, f32 yS, f32 zS);
extern "C" double sin(double);
extern "C" double cos(double);
static inline f32 sobSin(f32 x) { return sin(x); }
static inline f32 sobCos(f32 x) { return cos(x); }
static inline void sobRotMtx(f32 m[3][4], f32 ax, f32 ay, f32 az, f32 s = 1.0f) {
    f32 cx;
    f32 sx = sobSin(ax);
    f32 sy = sobSin(ay);
    f32 sz = sobSin(az);
    cx = sobCos(ax);
    f32 cy = sobCos(ay);
    f32 cz = sobCos(az);
    f32 cc = cx * cz;
    f32 ss = sx * sy;
    f32 cs = cx * sz;
    m[0][0] = s * (cy * cz);
    m[1][0] = s * (cy * sz);
    m[2][0] = s * -sy;
    m[0][1] = s * (ss * cz - cs);
    m[1][1] = s * (ss * sz + cc);
    m[2][1] = s * (sx * cy);
    m[0][2] = s * (cc * sy + sx * sz);
    m[1][2] = s * (cs * sy - sx * cz);
    m[2][2] = s * (cx * cy);
}
extern u8 lbl_8053ACD4[4];
extern u8 lbl_8053ACE0[4];
extern u8 lbl_8053ACE8[4];
extern u8 lbl_8053ACEC[4];
extern u8 lbl_8053ACF0[4];
extern u8 lbl_8053ACF4[4];
extern u8 lbl_8053ACF8[4];
extern u8 lbl_8053ACFC[4];
struct Game_80301CD0;
extern Game_80301CD0* lbl_8053AAF8;
extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802D7804(void* mgr, u32 id, u32 flags);
extern "C" u8 fn_8037F1E4(s32);
extern "C" u8 fn_8037EE8C(s32);
extern "C" u8 fn_80379F84(void*);
extern "C" s32 fn_80237060(s32);
extern "C" u8 fn_802351D8(s32);
extern "C" u8 fn_802DEBF8(void);
extern "C" u8 fn_802DEBA0(void);
extern "C" s32 fn_8023BC38(s32);
extern "C" s32 fn_80236768(s32);
extern "C" s32 fn_80236630(s32);
extern "C" s32 fn_802366CC(s32);
extern u8 lbl_8053AD08;
extern u8 lbl_8053ACD0;
extern u8 lbl_8053ACD8[4];
extern u8 lbl_8053ACDC[4];
extern void* lbl_8053AAF0;
extern void* lbl_8053AEC8;
extern void* lbl_8053AD68;
extern u8 lbl_80529DEC[];
extern u8 lbl_80506DE8[];
extern u8 lbl_8053ACF8[4];
struct Elem28_80301CD0 {
    Elem28_80301CD0();
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fc;
    f32 f10;
    f32 f14;
    u8 pad18[4];
    s32 f1c;
    u8 f20;
    u8 f21;
    u8 f22;
    u8 f23;
    u8 f24;
    u8 f25;
    u8 pad26[2];
};
static inline void tu80301_tickA(Elem28_80301CD0* p) {
    if (p->f25 == 1) {
        p->f24 = 0;
        p->f25 = 0;
        p->f4 = -1;
    } else if (p->f24 == 1 && p->f0 < 5) {
        p->f0++;
    }
}

// This TU's .bss (0x804DBC18-0x805076E8), in retail order.
static u8 lbl_804DBC18[0x20000];
static u8 lbl_804FBC18[0x8E00];
static int lbl_80504A18[4];
static int lbl_80504A28[4];
static Elem28_80301CD0 lbl_80504A38[4][16];
static Elem28_80301CD0 lbl_80505438[4][40];
static u32 lbl_80506D38[4];
static u8 lbl_80506D48[0x10];
static u8 lbl_80506D58[0x10];
static u8 lbl_80506D68[0x10];
static f32 lbl_80506D78[4];
static u8 lbl_80506D88[0x10];
static u8 lbl_80506D98[0x10];
static u8 lbl_80506DA8[0x10];
static u8 lbl_80506DB8[0x10];
static u8 lbl_80506DC8[0x10];
static u8 lbl_80506DD8[0x10];
static u8 lbl_80506DE8[0x1A0];
static u8 lbl_80506F88[0x260];
static u8 lbl_805071E8[0x400];

struct MsgEntry_80301CD0 {
    char text[0x100];
    s32 f100;
    s32 f104;
    int f108;
    s32 f10c;
    s32 f110;
    s32 f114;
    u8 f118;
    u8 f119;
    u8 f11a;
    u8 pad11b;
};

static inline void clearMessageEntry(MsgEntry_80301CD0* entry, const int index) {
    entry->f118 = 0;
    entry->f119 = 0;
    entry->f104 = 0;
    entry->f100 = 0;
    entry->f114 = 0;
    entry->f108 = index;
    entry->f10c = 0;
    entry->text[0] = 0;
}

static inline void clearMessageEntries(MsgEntry_80301CD0* entries) {
    for (int index = 0; index < 32; index++) clearMessageEntry(entries + index, index);
}
static inline void clearMessageQueue(int* head, int* tail, MsgEntry_80301CD0* entries) {
    *head = 0;
    *tail = 0;
    int index;
    for (index = 0; index < 32; index++) clearMessageEntry(entries + index, index);
}
extern u8 lbl_8053AD20[4];
extern u8 lbl_80541618[4];

struct TextCall_80301CD0 {
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual char* convert(u32 tag, const char* src);
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual s32 measure(const char* s);
};
struct Game_80301CD0;
extern Game_80301CD0* lbl_8053AAF8;
extern "C" char* strcpy(char*, const char*);

static inline void tu80301_pushMeasured(s32 i, const char* str, u32 color) {
    if (str == NULL) {
        return;
    }
    if (!fn_8030A308(lbl_8053AD30, fn_8030AAF4(i))) {
        return;
    }
    MsgEntry_80301CD0* e = &((MsgEntry_80301CD0*)(lbl_804FBC18 + i * 0x2380))[lbl_80504A28[i]];
    e->f104 = 0;
    e->f100 = (((TextCall_80301CD0*)*(void**)((u8*)lbl_8053AAF8 + 0xa4))->measure(((TextCall_80301CD0*)*(void**)((u8*)lbl_8053AAF8 + 0xa4))->convert(0x3f3f3f3f, str)) + 3) / 4;
    e->f114 = color;
    e->f119 = 0;
    e->f11a = 1;
    e->f110 = 0;
    e->f118 = 1;
    e->f10c = 0;
    strcpy(e->text, str);
    lbl_80504A28[i]++;
    if (lbl_80504A28[i] >= 0x20) {
        lbl_80504A28[i] = 0;
    }
}

struct Slot_80301CD0 {
    u8 id;
    u8 f1;
    u8 f2;
    u8 type : 3;
    u8 pad3 : 2;
    u8 idHi : 2;
    u8 flag : 1;
};

static inline void resetMessageSlots(Slot_80301CD0* slots) {
    for (int index = 0; index < 19; index++) {
        Slot_80301CD0* a = slots + index;
        Slot_80301CD0* b = a + 19;
        a->flag = 1;
        a->f2 = 0x80;
        b->flag = 1;
        b->f2 = 0x80;
    }
}
struct Rec2_80301CD0 {
    u8 a : 2;
    u8 flag : 1;
    u8 b : 3;
    u8 c : 2;
};

struct Rec3_80301CD0 {
    u8 y : 4;
    u8 m : 2;
    u8 lo : 2;
};

struct Rec5_80301CD0 {
    u8 flag : 1;
    u8 b6 : 1;
    u8 two : 2;
    u8 lo : 4;
};

// Nibble / bit-field views of bytes 1, 4, 5 and 6 of the 0x68-byte status record.
struct Nib_80301CD0 {
    u8 hi : 4;
    u8 lo : 4;
};
struct Rec4a_80301CD0 {
    u8 hi : 3;
    u8 lo : 5;
};
struct Rec4b_80301CD0 {
    u8 flag : 1;
    u8 two : 2;
    u8 lo : 5;
};
struct Rec5a_80301CD0 {
    u8 flag : 1;
    u8 lo : 7;
};
struct Rec6_80301CD0 {
    u8 hi : 6;
    u8 lo : 2;
};

static inline BOOL tu80301_isPlayerOn(s32 i) {
    return (((u8*)lbl_8053AAF8)[0x82] & (u8)(1 << i)) ? TRUE : FALSE;
}

static inline u8 tu80301_isState7(s32 state) { return state == 7; }

struct Hi_80301CD0 {
    u8 y : 4;
    u8 lo : 4;
};

struct Ctl4_80301CD0 {
    u8 y : 4;
    u8 x : 1;
    u8 mode : 2;
    u8 flag : 1;
};

struct Ctl3_80301CD0 {
    u8 yh : 3;
    u8 yl : 1;
    u8 x : 1;
    u8 mode : 2;
    u8 flag : 1;
};

static inline u8 tu80301_roomVisible(s32 owner) {
    u8 active = 0;
    if (fn_8022F5B0(owner)) {
        s32 room = fn_8023DE58(owner);
        if (!fn_802D7804(fn_802D6A9C(), room, 2)) active = 1;
    }
    return active;
}

static inline void tu80301_clearCtl(u8* q, int count) {
    for (; count > 0; count--) {
        ((Ctl3_80301CD0*)(q + 0x1b))->flag = 1;
        q[0x1a] = 0x80;
        q[0x19] = 0xe0;
        ((Ctl3_80301CD0*)(q + 0x1b))->mode = 0;
        q[0x18] = 0;
        ((Ctl3_80301CD0*)(q + 0x1b))->yh = 0;
        ((Ctl3_80301CD0*)(q + 0x1b))->yl = 0;
        q += 4;
    }
}

struct Packet_80301CD0 {
    u8 checksum, f1, f2;
    u8 code : 4;
    u8 rest : 4;
};

static inline u32 tu80301_swapWord(u32 word) {
    Slot_80301CD0 out;
    u8* bytes = (u8*)&word;
    out.id = bytes[3];
    out.f1 = bytes[2];
    out.f2 = bytes[1];
    ((u8*)&out)[3] = bytes[0];
    return *(u32*)&out;
}

struct Hdr_80301CD0 {
    u8 f0;
    u8 f1;
    u8 pad2_7 : 1;
    u8 side : 1;
    u8 pad2_5 : 1;
    u8 count : 3;
    u8 player : 2;
    u8 pad3 : 6;
    u8 kind : 2;
    u8 pad4[0x18 - 4];
    Slot_80301CD0 slots[19];
};

static inline s32 tu80301_rank(s32 mask, s32 player, s32 index) {
    s32 rank;
    if (((mask >> index) & 1) != ((mask >> ((s32*)lbl_80506DD8)[player]) & 1)) {
        rank = -1;
    } else {
        rank = lbl_80506DA8[player * 4 + index];
    }
    return rank;
}
static inline s32 tu80301_rankTables(s32 mask, s32 index, s32 ref, u8* ranks) {
    if (((mask >> index) & 1) != ((mask >> ref) & 1)) return -1;
    return ranks[index];
}
extern "C" s32 fn_803074A4(s32, s32);
extern "C" void fn_80302C34(u8*, s32, s32, s32, u8);

extern "C" u8 fn_80301CD0(void* p) {
    s32 i = fn_8022F340();
    if (lbl_8053ACE8[i] != 0 &&
        (lbl_8053ACEC[i] < 2 || (lbl_8053ACEC[i] == 2 && lbl_8053ACF0[i] < 0x10))) {
        return 1;
    }
    return 0;
}

extern "C" u8 fn_80301D30(s32 i) {
    if (lbl_8053ACEC[i] > 1) {
        return lbl_8053ACE8[i];
    }
    return 0;
}

extern "C" u8 fn_8023ED8C(s32 p);
extern "C" s32 fn_8023ECF0(s32 p);
extern "C" void fn_80301D54(s32 p) {
    s32 i = ((s32 (*)(s32))fn_8022F340)(p);
    if (lbl_8053ACF0[i] == 0) {
        lbl_8053ACE8[i] = 0;
        lbl_8053ACEC[i] = 0;
        lbl_8053ACF4[i] = 0;
    } else {
        lbl_8053ACEC[i] = 0xff;
    }
    lbl_8053ACF8[p] = 0;
    if (fn_8023ED8C(p)) {
        s32 n = fn_8023ECF0(p);
        if (n == fn_8022EA0C(n)) {
            fn_80301D54(n);
        }
    }
}

extern "C" void fn_803020C8(s32 a, s32 b, s32 c, u8 d) {
    s32 slot = fn_8022F340();
    if ((((u8*)lbl_8053AAF8)[0x82] & (u8)(1 << slot)) == 0) {
        return;
    }
    if (b < 8) {
        if (c < 8) {
            lbl_8053ACE8[slot] = 0;
        } else if (c == 8 || fn_802D7804(fn_802D6A9C(), c, 1) != 0) {
            lbl_8053ACE8[slot] = 1;
        } else {
            lbl_8053ACE8[slot] = 3;
        }
    } else if (b == 8 || fn_802D7804(fn_802D6A9C(), b, 1) != 0) {
        if (c < 8) {
            lbl_8053ACE8[slot] = 3;
            lbl_8053ACF8[a] = 1;
        } else if (c == 8 || fn_802D7804(fn_802D6A9C(), c, 1) != 0) {
            lbl_8053ACE8[slot] = 2;
        } else {
            lbl_8053ACE8[slot] = 2;
            lbl_8053ACF8[a] = 1;
        }
    } else {
        if (c < 8) {
            lbl_8053ACE8[slot] = 3;
        } else if (c == 8 || fn_802D7804(fn_802D6A9C(), c, 1) != 0) {
            lbl_8053ACE8[slot] = 1;
        } else {
            lbl_8053ACE8[slot] = 2;
        }
    }
    ((s32*)lbl_80506D88)[slot] = b;
    ((s32*)lbl_80506D98)[slot] = c;
    switch (d) {
    case 0:
        lbl_8053ACF4[slot] = 0;
        break;
    case 2:
        lbl_8053ACF4[slot] = 0x5a;
        break;
    default:
        lbl_8053ACF4[slot] = 0x14;
        break;
    }
}

extern "C" void fn_80302F9C(u8*, u8, u8, f32);
#pragma opt_common_subs off
extern "C" void fn_803022C4(u8* in, s32 slot, u8 a0, u8 m0) {
    s32 order[4];
    register s32 slotOffset;
    register u8* ranks;
    u8* base;
    s32 left;
    s32 right;
    u8* p;
    register s32* refs;
    s32 count;
    s32* cur;
    s32 rank;
    s32 lr;
    u8 arg;
    f32* angles;
    u8 mode;
    s32 player;
    p = in;
    player = slot;
    arg = a0;
    mode = m0;
    slotOffset = player * 4;
    ranks = lbl_80506DA8 + slotOffset;
    refs = (s32*)lbl_80506DD8;
    order[0] = 0;
    order[1] = 1;
    order[2] = 2;
    order[3] = 3;


    s32 mask = (p[1] >> 4) & 15;
    s32 n = 3;
    do {
        s32* a = order;
        for (s32 j = 0; j < n; ++j, ++a) {
            s32 x = a[0];
            s32 ref = *(s32*)((u8*)refs + slotOffset);
            s32 rx = tu80301_rankTables(mask, x, ref, ranks);
            s32 y = a[1];
            s32 ry = tu80301_rankTables(mask, y, ref, ranks);
            if (rx < ry ||
                (tu80301_rankTables(mask, x, ref, ranks) == tu80301_rankTables(mask, y, ref, ranks) &&
                 p[x * 4 + 9] < p[y * 4 + 9])) {
                a[0] = y;
                a[1] = x;
            }
        }
    } while (--n > 0);
    base = lbl_80506F88 + player * 0x98;
    left = 18;
    right = 18;
    count = 3;
    u8* scan = base + 0x48;
    u8* a = scan;
    for (s32 i = 19; i > 0; --i) {
        if ((a[3] & 1U) != 1U || a[2] != 0x80) break;
        a -= 4;
        --left;
    }
    a = scan;
    for (s32 i = 19; i > 0; --i) {
        if ((a[0x4f] & 1U) != 1U || a[0x4e] != 0x80) break;
        a -= 4;
        --right;
    }
    if ((((u32)p[2] >> 2) & 7U) <= 1U) mode = 1;
    angles = lbl_80506D78;
    cur = order + 3;
    while (left >= 0 || right >= 0 || count >= 0) {
        rank = count >= 0 ? tu80301_rankTables((p[1] >> 4) & 15, *cur, *(s32*)((u8*)refs + slotOffset), ranks) : 255;

        if (left >= 0) {
            u8* entry = base + left * 4;
            u8 flags = entry[3];
            lr = fn_803074A4(flags >> 5 & 7, entry[0] | ((flags & 6) << 7));
        } else lr = 255;
        s32 rr;
        if (right >= 0) {
            u8* entry = base + right * 4;
            u8 flags = entry[0x4f];
            rr = fn_803074A4(flags >> 5 & 7, entry[0x4c] | ((flags & 6) << 7));
        } else rr = 255;
        if (right >= 0 &&
            (count < 0 || rr < rank || (rr == rank && p[*cur * 4 + 9] >= base[right * 4 + 0x4d])) &&
            (left < 0 || lr > rr || (lr == rr && base[left * 4 + 1] >= base[right * 4 + 0x4d]))) {
            if (rr >= 2) fn_80302F9C(base + right * 4 + 0x4c, arg, mode, *(f32*)((u8*)angles + slotOffset));
            --right;
            a = base + right * 4;
            for (; right >= 0; --right) {
                if ((a[0x4f] & 1U) != 1U || a[0x4e] != 0x80) break;
                a -= 4;
            }
        } else if (left >= 0 &&
            (count < 0 || lr < rank || (lr == rank && p[*cur * 4 + 9] >= base[left * 4 + 1]))) {
            if (lr >= 2) fn_80302F9C(base + left * 4, arg, mode, *(f32*)((u8*)angles + slotOffset));
            --left;
            a = base + left * 4;
            for (; left >= 0; --left) {
                if ((a[3] & 1U) != 1U || a[2] != 0x80) break;
                a -= 4;
            }
        } else {
            s32 index = *cur;
            s32 bits = (p[1] >> 4) & 15;
            if (tu80301_rankTables(bits, index, *(s32*)((u8*)refs + slotOffset), ranks) >= 2)
                fn_80302C34(p + index * 4 + 8, player, index, bits, arg);
            --cur;
            --count;
        }
    }
}
#pragma opt_common_subs off
#pragma opt_strength_reduction off
extern "C" void fn_8030275C(u8* in, s32 slot, const u8 a0, const u8 m0) {
    s32 order[4];
    s32 slotOffset;
    u8* ranks;
    s32 player;
    f32* angles;
    s32 right;
    s32 count;
    u8* p;
    s32* refs;
    u8 arg;
    s32 left;
    u8 mode;
    s32 rank;
    s32 lr;
    u8* base;
    p = in;
    player = slot;
    arg = a0;
    mode = m0;
    slotOffset = player * 4;
    refs = (s32*)lbl_80506DD8;
    ranks = lbl_80506DA8 + slotOffset;

    order[0] = 0;
    order[1] = 1;
    order[2] = 2;
    order[3] = 3;
    u32 mask = (p[1] >> 4) & 15;
    for (int n = 3; n > 0; --n) {
        s32* a = order;
        for (int j = 0; j < n; ++j, ++a) {
            int x = a[0];
            int ref = *(s32*)((u8*)refs + slotOffset);
            int rx = tu80301_rankTables(mask, x, ref, ranks);
            int y = a[1];
            int ry = tu80301_rankTables(mask, y, ref, ranks);
            if (rx < ry ||
                (tu80301_rankTables(mask, x, ref, ranks) == tu80301_rankTables(mask, y, ref, ranks) &&
                 p[x * 4 + 9] < p[y * 4 + 9])) {
                a[0] = y;
                a[1] = x;
            }
        }
    }
    base = lbl_80506F88 + player * 0x98;
    left = 18;
    right = 18;
    count = 3;
    u8* scan = base + 0x48;
    u8* a = scan;
    for (s32 i = 19; i > 0; --i) {
        if ((a[3] & 1U) != 1U || a[2] != 0x80) break;
        a -= 4;
        --left;
    }
    a = scan;
    for (s32 i = 19; i > 0; --i) {
        if ((a[0x4f] & 1U) != 1U || a[0x4e] != 0x80) break;
        a -= 4;
        --right;
    }
    if ((((u32)p[2] >> 2) & 7U) <= 1U) mode = 1;
    angles = lbl_80506D78;
    while (left >= 0 || right >= 0 || count >= 0) {
        rank = count >= 0 ? tu80301_rankTables((p[1] >> 4) & 15, order[count], *(s32*)((u8*)refs + slotOffset), ranks) : 255;
        if (left >= 0) {
            u8* entry = base + left * 4;
            u8 flags = entry[3];
            lr = fn_803074A4((flags >> 5) & 7, entry[0] | ((flags & 6) << 7));
        } else lr = 255;
        s32 rr;
        if (right >= 0) {
            u8* entry = base + right * 4;
            register u8 flags = entry[0x4f];
            rr = fn_803074A4((flags >> 5) & 7, entry[0x4c] | ((flags & 6) << 7));
        } else rr = 255;
        if (right >= 0 &&
            (count < 0 || rr < rank || (rr == rank && p[order[count] * 4 + 9] >= base[right * 4 + 0x4d])) &&
            (left < 0 || lr > rr || (lr == rr && base[left * 4 + 1] >= base[right * 4 + 0x4d]))) {
            if (rr >= 2) right = 0;
            else fn_80302F9C(base + right * 4 + 0x4c, arg, mode, *(f32*)((u8*)angles + slotOffset));
            --right;
            a = base + right * 4;
            for (; right >= 0; --right) {
                if ((a[0x4f] & 1U) != 1U || a[0x4e] != 0x80) break;
                a -= 4;
            }
        } else if (left >= 0 &&
            (count < 0 || lr < rank || (lr == rank && p[order[count] * 4 + 9] >= base[left * 4 + 1]))) {
            if (2 <= lr) left = 0;
            else fn_80302F9C(base + left * 4, arg, mode, *(f32*)((u8*)angles + slotOffset));
            --left;
            a = base + left * 4;
            for (; left >= 0; --left) {
                if ((a[3] & 1U) != 1U || a[2] != 0x80) break;
                a -= 4;
            }
        } else {
            s32 index = order[count];
            s32 bits = (p[1] >> 4) & 15;
            if (tu80301_rankTables(bits, index, *(s32*)((u8*)refs + slotOffset), ranks) >= 2) count = 0;
            else fn_80302C34(p + index * 4 + 8, player, index, bits, arg);
            --count;
        }
    }
}
#pragma opt_strength_reduction reset
#pragma opt_common_subs reset
extern "C" void fn_80302C34(u8* __restrict p, s32 player, s32 index, s32 bits, u8 flag) {
    u8* effect;
    s32 off;
    s32 x;
    s32 y;
    s32 id;
    DrawRec rec;
    f32 mtx[3][4];
    f32 pos[3];
    Slot_80301CD0* slot=(Slot_80301CD0*)p;
    u8 b3=p[3];
    x=((b3&1)<<8)|slot->f2;
    y=slot->f1;
    if(x!=0x180 && y!=0xe0 && (effect=lbl_8053ACFC)[(u32)index]<17) {
    if(x>=0x180) x|=-0x100;
    if(y>=0xe0) y|=-0x100;
    off=player*4;
    id=slot->id|(slot->idHi<<8);
    if(lbl_80506DC8[off+index]!=0) ((u8*)&rec.w10)[3]=0xa0;
    if((((u8)bits >> index)&1)!=0) {
        for(int i=0;i<16;i++) rec.ids[i]=7;
    } else rec.ids[7]=index+12;
    if(fn_80237060(index)>=2) rec.ids[10]=6;
    f32 fy;
    f32 fx;
    fx=x;
    fy=y;
    pos[0]=fx;
    pos[1]=fy;
    pos[2]=0.0f;
    u32 n=effect[index];
    if(n!=0) {
        f32 step=0.0625f;
        PSMTXScale(mtx,1.0f-0.75f*(f32)n*step,1.0f,(f32)n*step+1.0f);
    } else if(lbl_80506DB8[off+index]==1) PSMTXScale(mtx,1.0f,1.0f,0.5f);
    else PSMTXScale(mtx,1.0f,1.0f,1.0f);
    rec.b2c=0;
    rec.b26=0;
    rec.b2d=0;
    if(flag==0) rec.w34=2;
    rec.b1f=0;
    rec.w38=0;
    rec.w18=mtx;
    void* obj=*(void**)((u8*)lbl_8053AAF8+0xa4);
    void* res=((JKRFileLoader*)obj)->getResource(0x534f4220,(const char*)lbl_80471208);
    fn_802F86CC(*(void**)(lbl_8053AB10+0x20),pos,res,id,1.0f,1.0f,&rec);
    }
}

#pragma opt_strength_reduction reset
#pragma opt_common_subs reset

extern const f32 lbl_80541630;
extern "C" void fn_80302F9C(u8* p, u8 a2, u8 a3, f32 ang) {
    const char* names;
    s32 id;
    f32 pos[3];
    int x;
    int y;
    void* obj;
    void* res;
    f32 sx;
    f32 sy;
    f32 sz;
    f32 cx;
    f32 cy;
    f32 cz;
    f32 s;

    u8 b3 = p[3];
    u8 b2 = p[2];
    y = p[1];
    names = (const char*)lbl_80471208;
    x = b2 | ((b3 & 1) << 8);
    if (x == 0x180 || y == 0xe0) {
        return;
    }
    if (x >= 0x180) {
        x |= -0x100;
    }
    if (y >= 0xe0) {
        y |= -0x100;
    }
    id = p[0] | ((p[3] & 6) << 7);
    pos[0] = (f32)x;
    pos[1] = (f32)y;
    pos[2] = lbl_80541630;

    id = p[0] | ((p[3] & 6) << 7);
    DrawRec rec;
    f32 mtx[3][4];
    rec.b2c = 0;
    rec.b26 = 0;
    rec.b2d = 0;
    if (a2 == 0) {
        rec.w34 = 2;
        rec.b1f = 0;
        rec.w38 = 0;
    }

    if ((((u32)p[3] >> 5) & 7) == 2 && id >= 0x200) {
        id &= 0x1ff;
        if ((((u32)p[3] >> 4) & 1) == 1) {
            PSMTXScale(mtx, 2.0f, 2.0f, -2.0f);
        } else {
            PSMTXScale(mtx, 1.0f, 1.0f, -1.0f);
        }
    } else if ((((u32)p[3] >> 3) & 1) == 1) {
        PSMTXScale(mtx, 1.0f, 1.0f, 1.0f);
        if ((((u32)p[3] >> 4) & 1) == 1) {
            sobRotMtx(mtx, lbl_80541630, ang, lbl_80541630, 1.5f);
        } else {
            sobRotMtx(mtx, lbl_80541630, ang, lbl_80541630, 0.75f);
        }
        rec.ids[0] = 7;
        rec.ids[1] = 7;
        rec.ids[2] = 7;
        rec.ids[3] = 7;
        rec.ids[4] = 7;
        rec.ids[5] = 7;
        rec.ids[6] = 7;
        rec.ids[7] = 7;
        rec.ids[8] = 7;
        rec.ids[9] = 7;
        rec.ids[10] = 7;
        rec.ids[11] = 7;
        rec.ids[12] = 7;
        rec.ids[13] = 7;
        rec.ids[14] = 7;
        rec.ids[15] = 7;
    } else {
        if ((((u32)p[3] >> 4) & 1) == 1 || ((((u32)p[3] >> 5) & 7) == 2 && id >= 0x39 && id < 0x45)) {
            PSMTXScale(mtx, 2.0f, 2.0f, 2.0f);
        } else {
            PSMTXScale(mtx, 1.0f, 1.0f, 1.0f);
        }
    }

    rec.w18 = mtx;
    if (a3) rec.b1e = 2;
    else rec.b1e = 1;

    if ((((u32)p[3] >> 5) & 7) < 2) {
        if ((id >= 0x37 && id < 0x41) || (id >= 0x3cd && id < 0x3ce)) {
            ((u8*)&rec.w10)[3] = 0xa0;
        } else if (id == 0x2a8 || id == 0x2a9) {
            id -= 3;
        }
        obj = *(void**)((u8*)lbl_8053AAF8 + 0xa4);
        res = ((JKRFileLoader*)obj)->getResource(0x534F4220, names + 0x10);
        fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), pos, res, id, 1.0f, 1.0f, &rec);
        return;
    }
    if ((((u32)p[3] >> 5) & 7) == 2) {
        obj = *(void**)((u8*)lbl_8053AAF8 + 0xa4);
        res = ((JKRFileLoader*)obj)->getResource(0x534F4220, names + 0x24);
        fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), pos, res, id, 1.0f, 1.0f, &rec);
        return;
    }
    if ((((u32)p[3] >> 5) & 7) & 4) {
        rec.ids[7] = ((((u32)p[3] >> 5) & 7) & 3) + 0xc;
    }
    obj = *(void**)((u8*)lbl_8053AAF8 + 0xa4);
    res = ((JKRFileLoader*)obj)->getResource(0x534F4220, names);
    fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), pos, res, id, 1.0f, 1.0f, &rec);
}

// Player-state accessors (0x80303750..).
static inline u8 tu80301_changed(s32 i) {
    if (lbl_80504A18[i] == lbl_80504A28[i]) {
        return 0;
    }
    return 1;
}

extern "C" void fn_8030361C() {
    for (s32 i = 0; i < 4; i++) {
        MsgEntry_80301CD0* e = &((MsgEntry_80301CD0*)(lbl_804FBC18 + i * 0x2380))[lbl_80504A18[i]];
        while (e != &((MsgEntry_80301CD0*)(lbl_804FBC18 + i * 0x2380))[lbl_80504A28[i]]) {
            if (e->f118 == 1 && e->f104 == 0) {
                u32 c = e->f114;
                if (c == 0x600C000 || c == 0x600E000 || c == 0x6000000 || c == 0x5000001 || c == 0x6017000) {
                    e->f118 = 0;
                    e->f119 = 0;
                    e->f104 = 0;
                    e->text[0] = 0;
                    if (e->f108 == lbl_80504A18[i]) {
                        do {
                            lbl_80504A18[i]++;
                            if (lbl_80504A18[i] >= 0x20) {
                                lbl_80504A18[i] = 0;
                            }
                        } while (lbl_80504A18[i] != lbl_80504A28[i] && ((MsgEntry_80301CD0*)(lbl_804FBC18 + i * 0x2380))[lbl_80504A18[i]].f118 == 0);
                    }
                }
            }
            if (e->f108 < 0x1f) {
                e++;
            } else {
                e = (MsgEntry_80301CD0*)(lbl_804FBC18 + i * 0x2380);
            }
        }
        lbl_8053AD20[i] = 0;
    }
}

extern "C" u8 fn_80303750(void* p) {
    s32 i = fn_8022F340();
    u8 r = fn_8030A308(lbl_8053AD30, fn_8030AAF4(i));
    if (r) {
        r = tu80301_changed(i);
        if (!r) {
            r = lbl_8053ACD4[i];
        }
    }
    return r;
}

extern "C" void fn_803037D4(void* p, u32 v) {
    s32 i = fn_8022F340();
    if (v > lbl_80506D38[i]) {
        lbl_80506D38[i] = v;
    }
}

extern "C" u8 fn_8030381C(void* p) {
    s32 i = fn_8022F340();
    if ((u8)fn_8030A308(lbl_8053AD30, fn_8030AAF4(i))) {
        return lbl_8053ACE0[i];
    }
    return 0;
}

extern "C" int sprintf(char*, const char*, ...);
extern "C" const char* fn_802D9C4C(char*);
extern "C" const char* fn_802D9C1C(char*);
extern "C" u8 fn_80304C10(s32 i, char* str, u32 color, u8 b, s32 id);
extern u8 lbl_80471208[];
extern u8 lbl_8053ACE4[4];
extern "C" void fn_80303870(s32 i) {
    char buf28[0x20];
    char buf8[0x20];
    const char* str;
    const char* base = (char*)lbl_80471208;

    str = fn_802D9C4C((char*)fn_802D6A9C());
    if (str[0] != 'c') {
        sprintf(buf28, base + 0x38, str);
        tu80301_pushMeasured(i, buf28, 0x6000000);
    } else {
        tu80301_pushMeasured(i, base + 0x48, 0x6000000);
    }
    sprintf(buf8, base + 0x58, str);
    tu80301_pushMeasured(i, buf8, 0x5000001);
    sprintf(buf28, base + 0x6c, fn_802D9C1C((char*)fn_802D6A9C()));
    tu80301_pushMeasured(i, buf28, 0x6017000);
    lbl_8053ACE4[i] = 1;
}

extern "C" s32 fn_801365A8();
extern "C" void fn_80303CE4(s32 i)
{
    MsgEntry_80301CD0* ent;
    MsgEntry_80301CD0* e;
    s32 n;
    s32 p;
    const char* base = (const char*)lbl_80471208;

    lbl_80506D38[i] = 0;
    lbl_8053ACE0[i] = 0;
    lbl_8053ACE4[i] = 0;
    lbl_8053ACD4[i] = 1;
    ((s32*)lbl_80506D88)[i] = 0;
    ((s32*)lbl_80506D98)[i] = 0;
    lbl_8053ACE8[i] = 0;
    lbl_8053ACEC[i] = 0;
    lbl_8053ACF0[i] = 0;
    lbl_8053ACF8[i] = 0;
    lbl_8053ACFC[i] = 0;
    lbl_80504A18[i] = 0;
    lbl_80504A28[i] = 0;

    ent = (MsgEntry_80301CD0*)(lbl_804FBC18 + i * 0x2380);
    n = 0;
    for (p = 0; p < 4; p++) {
        ent[n + 0].f118 = 0;
        ent[n + 0].f119 = 0;
        ent[n + 0].f104 = 0;
        ent[n + 0].f100 = 0;
        ent[n + 0].f114 = 0;
        ent[n + 0].f108 = n + 0;
        ent[n + 0].f10c = 0;
        ent[n + 0].text[0] = 0;
        ent[n + 1].f118 = 0;
        ent[n + 1].f119 = 0;
        ent[n + 1].f104 = 0;
        ent[n + 1].f100 = 0;
        ent[n + 1].f114 = 0;
        ent[n + 1].f108 = n + 1;
        ent[n + 1].f10c = 0;
        ent[n + 1].text[0] = 0;
        ent[n + 2].f118 = 0;
        ent[n + 2].f119 = 0;
        ent[n + 2].f104 = 0;
        ent[n + 2].f100 = 0;
        ent[n + 2].f114 = 0;
        ent[n + 2].f108 = n + 2;
        ent[n + 2].f10c = 0;
        ent[n + 2].text[0] = 0;
        ent[n + 3].f118 = 0;
        ent[n + 3].f119 = 0;
        ent[n + 3].f104 = 0;
        ent[n + 3].f100 = 0;
        ent[n + 3].f114 = 0;
        ent[n + 3].f108 = n + 3;
        ent[n + 3].f10c = 0;
        ent[n + 3].text[0] = 0;
        ent[n + 4].f118 = 0;
        ent[n + 4].f119 = 0;
        ent[n + 4].f104 = 0;
        ent[n + 4].f100 = 0;
        ent[n + 4].f114 = 0;
        ent[n + 4].f108 = n + 4;
        ent[n + 4].f10c = 0;
        ent[n + 4].text[0] = 0;
        ent[n + 5].f118 = 0;
        ent[n + 5].f119 = 0;
        ent[n + 5].f104 = 0;
        ent[n + 5].f100 = 0;
        ent[n + 5].f114 = 0;
        ent[n + 5].f108 = n + 5;
        ent[n + 5].f10c = 0;
        ent[n + 5].text[0] = 0;
        ent[n + 6].f118 = 0;
        ent[n + 6].f119 = 0;
        ent[n + 6].f104 = 0;
        ent[n + 6].f100 = 0;
        ent[n + 6].f114 = 0;
        ent[n + 6].f108 = n + 6;
        ent[n + 6].f10c = 0;
        ent[n + 6].text[0] = 0;
        ent[n + 7].f118 = 0;
        ent[n + 7].f119 = 0;
        ent[n + 7].f104 = 0;
        ent[n + 7].f100 = 0;
        ent[n + 7].f114 = 0;
        ent[n + 7].f108 = n + 7;
        ent[n + 7].f10c = 0;
        ent[n + 7].text[0] = 0;
        n += 8;
    }
    u32* buffer = (u32*)(lbl_804DBC18 + i * 0x8000);
    for (int index = 0; index < 0x2000; index++) buffer[index] = 0xCDCDCDCD;

    if ((base + 0x84) != NULL) {
        if (fn_8030A308(lbl_8053AD30, fn_8030AAF4(i))) {
            e = &ent[lbl_80504A28[i]];
            e->f104 = 0;
            e->f100 = (((TextCall_80301CD0*)*(void**)((u8*)lbl_8053AAF8 + 0xa4))->measure(((TextCall_80301CD0*)*(void**)((u8*)lbl_8053AAF8 + 0xa4))->convert(0x3f3f3f3f, (base + 0x84))) + 3) / 4;
            e->f114 = 0xAAAAAAAA;
            e->f119 = 0;
            e->f11a = 0;
            e->f110 = 0;
            e->f118 = 1;
            e->f10c = 0;
            strcpy(e->text, (base + 0x84));
            lbl_80504A28[i]++;
            if (lbl_80504A28[i] >= 0x20) {
                lbl_80504A28[i] = 0;
            }
        }
    }

    if ((base + 0x98) != NULL) {
        if (fn_8030A308(lbl_8053AD30, fn_8030AAF4(i))) {
            e = &ent[lbl_80504A28[i]];
            e->f104 = 0;
            e->f100 = (((TextCall_80301CD0*)*(void**)((u8*)lbl_8053AAF8 + 0xa4))->measure(((TextCall_80301CD0*)*(void**)((u8*)lbl_8053AAF8 + 0xa4))->convert(0x3f3f3f3f, (base + 0x98))) + 3) / 4;
            e->f114 = 0x02033000;
            e->f119 = 0;
            e->f11a = 1;
            e->f110 = 0;
            e->f118 = 1;
            e->f10c = 0;
            strcpy(e->text, (base + 0x98));
            lbl_80504A28[i]++;
            if (lbl_80504A28[i] >= 0x20) {
                lbl_80504A28[i] = 0;
            }
        }
    }

    if ((base + 0xa8) != NULL) {
        if (fn_8030A308(lbl_8053AD30, fn_8030AAF4(i))) {
            e = &ent[lbl_80504A28[i]];
            e->f104 = 0;
            e->f100 = (((TextCall_80301CD0*)*(void**)((u8*)lbl_8053AAF8 + 0xa4))->measure(((TextCall_80301CD0*)*(void**)((u8*)lbl_8053AAF8 + 0xa4))->convert(0x3f3f3f3f, (base + 0xa8))) + 3) / 4;
            e->f114 = 0x06010000;
            e->f119 = 0;
            e->f11a = 1;
            e->f110 = 0;
            e->f118 = 1;
            e->f10c = 0;
            strcpy(e->text, (base + 0xa8));
            lbl_80504A28[i]++;
            if (lbl_80504A28[i] >= 0x20) {
                lbl_80504A28[i] = 0;
            }
        }
    }

    if ((base + 0xc0) != NULL) {
        if (fn_8030A308(lbl_8053AD30, fn_8030AAF4(i))) {
            e = &ent[lbl_80504A28[i]];
            e->f104 = 0;
            e->f100 = (((TextCall_80301CD0*)*(void**)((u8*)lbl_8053AAF8 + 0xa4))->measure(((TextCall_80301CD0*)*(void**)((u8*)lbl_8053AAF8 + 0xa4))->convert(0x3f3f3f3f, (base + 0xc0))) + 3) / 4;
            e->f114 = 0x05000201;
            e->f119 = 0;
            e->f11a = 1;
            e->f110 = 0;
            e->f118 = 1;
            e->f10c = 0;
            strcpy(e->text, (base + 0xc0));
            lbl_80504A28[i]++;
            if (lbl_80504A28[i] >= 0x20) {
                lbl_80504A28[i] = 0;
            }
        }
    }

    if ((base + 0xd8) != NULL) {
        if (fn_8030A308(lbl_8053AD30, fn_8030AAF4(i))) {
            e = &ent[lbl_80504A28[i]];
            e->f104 = 0;
            e->f100 = (((TextCall_80301CD0*)*(void**)((u8*)lbl_8053AAF8 + 0xa4))->measure(((TextCall_80301CD0*)*(void**)((u8*)lbl_8053AAF8 + 0xa4))->convert(0x3f3f3f3f, (base + 0xd8))) + 3) / 4;
            e->f114 = 0x02034000;
            e->f119 = 0;
            e->f11a = 1;
            e->f110 = 0;
            e->f118 = 1;
            e->f10c = 0;
            strcpy(e->text, (base + 0xd8));
            lbl_80504A28[i]++;
            if (lbl_80504A28[i] >= 0x20) {
                lbl_80504A28[i] = 0;
            }
        }
    }

    if ((base + 0xe8) != NULL) {
        if (fn_8030A308(lbl_8053AD30, fn_8030AAF4(i))) {
            e = &ent[lbl_80504A28[i]];
            e->f104 = 0;
            e->f100 = (((TextCall_80301CD0*)*(void**)((u8*)lbl_8053AAF8 + 0xa4))->measure(((TextCall_80301CD0*)*(void**)((u8*)lbl_8053AAF8 + 0xa4))->convert(0x3f3f3f3f, (base + 0xe8))) + 3) / 4;
            e->f114 = 0x0203C000;
            e->f119 = 0;
            e->f11a = 1;
            e->f110 = 0;
            e->f118 = 1;
            e->f10c = 0;
            strcpy(e->text, (base + 0xe8));
            lbl_80504A28[i]++;
            if (lbl_80504A28[i] >= 0x20) {
                lbl_80504A28[i] = 0;
            }
        }
    }
    if ((base + 0xf8) != NULL) {
        if (fn_8030A308(lbl_8053AD30, fn_8030AAF4(i))) {
            e = &ent[lbl_80504A28[i]];
            e->f104 = 0;
            e->f100 = (((TextCall_80301CD0*)*(void**)((u8*)lbl_8053AAF8 + 0xa4))->measure(((TextCall_80301CD0*)*(void**)((u8*)lbl_8053AAF8 + 0xa4))->convert(0x3f3f3f3f, (base + 0xf8))) + 3) / 4;
            e->f114 = 0x02010000;
            e->f119 = 0;
            e->f11a = 1;
            e->f110 = 0;
            e->f118 = 1;
            e->f10c = 0;
            strcpy(e->text, (base + 0xf8));
            lbl_80504A28[i]++;
            if (lbl_80504A28[i] >= 0x20) {
                lbl_80504A28[i] = 0;
            }
        }
    }
    if ((base + 0x108) != NULL) {
        if (fn_8030A308(lbl_8053AD30, fn_8030AAF4(i))) {
            e = &ent[lbl_80504A28[i]];
            e->f104 = 0;
            e->f100 = (((TextCall_80301CD0*)*(void**)((u8*)lbl_8053AAF8 + 0xa4))->measure(((TextCall_80301CD0*)*(void**)((u8*)lbl_8053AAF8 + 0xa4))->convert(0x3f3f3f3f, (base + 0x108))) + 3) / 4;
            e->f114 = 0x02021000;
            e->f119 = 0;
            e->f11a = 1;
            e->f110 = 0;
            e->f118 = 1;
            e->f10c = 0;
            strcpy(e->text, (base + 0x108));
            lbl_80504A28[i]++;
            if (lbl_80504A28[i] >= 0x20) {
                lbl_80504A28[i] = 0;
            }
        }
    }
    if ((base + 0x11c) != NULL) {
        if (fn_8030A308(lbl_8053AD30, fn_8030AAF4(i))) {
            e = &ent[lbl_80504A28[i]];
            e->f104 = 0;
            e->f100 = (((TextCall_80301CD0*)*(void**)((u8*)lbl_8053AAF8 + 0xa4))->measure(((TextCall_80301CD0*)*(void**)((u8*)lbl_8053AAF8 + 0xa4))->convert(0x3f3f3f3f, (base + 0x11c))) + 3) / 4;
            e->f114 = 0x02018E00;
            e->f119 = 0;
            e->f11a = 1;
            e->f110 = 0;
            e->f118 = 1;
            e->f10c = 0;
            strcpy(e->text, (base + 0x11c));
            lbl_80504A28[i]++;
            if (lbl_80504A28[i] >= 0x20) {
                lbl_80504A28[i] = 0;
            }
        }
    }

    if (fn_801365A8() == 2) {
    if ((base + 0x130) != NULL) {
        if (fn_8030A308(lbl_8053AD30, fn_8030AAF4(i))) {
            e = &ent[lbl_80504A28[i]];
            e->f104 = 0;
            e->f100 = (((TextCall_80301CD0*)*(void**)((u8*)lbl_8053AAF8 + 0xa4))->measure(((TextCall_80301CD0*)*(void**)((u8*)lbl_8053AAF8 + 0xa4))->convert(0x3f3f3f3f, (base + 0x130))) + 3) / 4;
            e->f114 = 0x02038000;
            e->f119 = 0;
            e->f11a = 1;
            e->f110 = 0;
            e->f118 = 1;
            e->f10c = 0;
            strcpy(e->text, (base + 0x130));
            lbl_80504A28[i]++;
            if (lbl_80504A28[i] >= 0x20) {
                lbl_80504A28[i] = 0;
            }
        }
    }

    } else if (fn_801365A8() == 0 || fn_801365A8() == 1) {
    if ((base + 0x148) != NULL) {
        if (fn_8030A308(lbl_8053AD30, fn_8030AAF4(i))) {
            e = &ent[lbl_80504A28[i]];
            e->f104 = 0;
            e->f100 = (((TextCall_80301CD0*)*(void**)((u8*)lbl_8053AAF8 + 0xa4))->measure(((TextCall_80301CD0*)*(void**)((u8*)lbl_8053AAF8 + 0xa4))->convert(0x3f3f3f3f, (base + 0x148))) + 3) / 4;
            e->f114 = 0x02038000;
            e->f119 = 0;
            e->f11a = 1;
            e->f110 = 0;
            e->f118 = 1;
            e->f10c = 0;
            strcpy(e->text, (base + 0x148));
            lbl_80504A28[i]++;
            if (lbl_80504A28[i] >= 0x20) {
                lbl_80504A28[i] = 0;
            }
        }
    }

    }
    if ((base + 0x84) != NULL) {
        if (fn_8030A308(lbl_8053AD30, fn_8030AAF4(i))) {
            e = &ent[lbl_80504A28[i]];
            e->f104 = 0;
            e->f100 = (((TextCall_80301CD0*)*(void**)((u8*)lbl_8053AAF8 + 0xa4))->measure(((TextCall_80301CD0*)*(void**)((u8*)lbl_8053AAF8 + 0xa4))->convert(0x3f3f3f3f, (base + 0x84))) + 3) / 4;
            e->f114 = 0xFFFFFFFF;
            e->f119 = 0;
            e->f11a = 0;
            e->f110 = 0;
            e->f118 = 1;
            e->f10c = 0;
            strcpy(e->text, (base + 0x84));
            lbl_80504A28[i]++;
            if (lbl_80504A28[i] >= 0x20) {
                lbl_80504A28[i] = 0;
            }
        }
    }

}

// ---- stub_803074a4.cpp ----
extern "C" void* fn_802D6A9C();
extern "C" char* fn_802D8128(void*, s32);
extern "C" char* fn_802D8228(void*, s32);
extern "C" s32 fn_80403284(const char*);
extern "C" char* strcpy(char*, const char*);

static inline void tu80301_pushMsg(s32 i, char* str, s32 id, s32 color) {
    MsgEntry_80301CD0* e = &((MsgEntry_80301CD0*)(lbl_804FBC18 + i * 0x2380))[lbl_80504A28[i]];
    e->f104 = 0;
    e->f100 = (fn_80403284(str) + 3) / 4;
    e->f114 = color;
    e->f119 = 0;
    e->f11a = 1;
    e->f110 = id;
    e->f118 = 1;
    e->f10c = 0;
    strcpy(e->text, str);
    lbl_80504A28[i]++;
    if (lbl_80504A28[i] >= 0x20) {
        lbl_80504A28[i] = 0;
    }
}

extern "C" u8 fn_803049F0(void* p, s32 id) {
    s32 i = fn_8022F340();
    char* str = fn_802D8128(fn_802D6A9C(), id);
    if (str == NULL) {
        return 0;
    }
    if (!fn_8030A308(lbl_8053AD30, fn_8030AAF4(i))) {
        return 0;
    }
    tu80301_pushMsg(i, str, id, 0x600C000);
    return 1;
}

extern "C" u8 fn_80304B00(void* p, s32 id) {
    s32 i = fn_8022F340();
    char* str = fn_802D8228(fn_802D6A9C(), id);
    if (str == NULL) {
        return 0;
    }
    if (!fn_8030A308(lbl_8053AD30, fn_8030AAF4(i))) {
        return 0;
    }
    tu80301_pushMsg(i, str, id, 0x600E000);
    return 1;
}


struct TextMgr_80301CD0 {
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual char* convert(u32 tag, const char* src);
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual s32 measure(const char* s);
};
struct Game_80301CD0 {
    u8 pad0[0xa4];
    TextMgr_80301CD0* text;
};
extern Game_80301CD0* lbl_8053AAF8;

struct Ent_803066F0 {
    s32 prio;
    u8 pad4[4];
    s32 f8;
    u8 padc[4];
    u8 f10[0xc];
    u32 f1c;
    u8 f20;
    u8 f21;
    u8 f22;
    u8 f23;
    u8 f24;
    u8 f25;
    u8 pad26[2];
};
struct Out_803066F0 {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 f20 : 3;
    u8 f21 : 1;
    u8 f22 : 1;
    u8 f1c : 2;
    u8 hi : 1;
};
static inline u8 isMode11_803066F0(u8* g) {
    u8 r = *(s32*)(g + 0x4c) == 11;
    return r;
}

extern "C" u8 fn_80304C10(s32 i, char* str, u32 color, u8 b, s32 id) {
    if (str == NULL) {
        return 0;
    }
    if (!fn_8030A308(lbl_8053AD30, fn_8030AAF4(i))) {
        return 0;
    }
    MsgEntry_80301CD0* e = &((MsgEntry_80301CD0*)(lbl_804FBC18 + i * 0x2380))[lbl_80504A28[i]];
    e->f104 = 0;
    s32 len;
    if (color == 0x600C000 || color == 0x600E000) {
        len = fn_80403284(str);
    } else {
        len = lbl_8053AAF8->text->measure(lbl_8053AAF8->text->convert('????', str));
    }
    e->f100 = (len + 3) / 4;
    e->f114 = color;
    e->f119 = 0;
    e->f11a = b;
    e->f110 = id;
    e->f118 = 1;
    e->f10c = 0;
    strcpy(e->text, str);
    lbl_80504A28[i]++;
    if (lbl_80504A28[i] >= 0x20) {
        lbl_80504A28[i] = 0;
    }
    return 1;
}

extern "C" void fn_80304D64(s32 unused = 0) {
    Elem28_80301CD0 (*b)[40] = lbl_80505438;
    Elem28_80301CD0 (*a)[16] = lbl_80504A38;
    for (s32 i = 0; i < 4; i++) {
        for (int j = 0; j < 16; j++) {
            if (a[i][j].f25 == 1) {
                a[i][j].f24 = 0;
                a[i][j].f25 = 0;
                a[i][j].f4 = -1;
            } else if (a[i][j].f24 == 1 && a[i][j].f0 < 5) {
                a[i][j].f0++;
            }
        }
        for (int j = 0; j < 40; j++) {
            if (b[i][j].f25 == 1 && b[i][j].f0 == 0) {
                b[i][j].f24 = 0;
                b[i][j].f25 = 0;
                b[i][j].f4 = -1;
                b[i][j].fc = -1;
            } else if (b[i][j].f25 == 1) {
                b[i][j].fc = -1;
                b[i][j].f0 = 0;
            } else if (b[i][j].f24 == 1 && b[i][j].f0 < 5) {
                b[i][j].f0++;
            }
        }
    }
}

extern u8 lbl_804DB798[4][0xe0];
extern f64 lbl_80541668;
extern u8 lbl_8053AD04[4],lbl_8053AD24[4],lbl_8053AD28[4],lbl_8053AD34[4],lbl_8053AD1C[4];
extern u16 lbl_8053AD0C[4],lbl_8053AD14[4];
extern "C" s32 AnimTable_IsField0xe0LessThan3(void*,s32);
extern "C" u8 fn_8022F64C(s32);
extern "C" void fn_802F53F4(u8*,s32,u8*);
extern "C" u16 fn_8037F0CC(s32);
extern "C" void fn_80303CE4(s32);
extern "C" void fn_80307B58(s32,s32,u8);
extern "C" u8 fn_80309A38(void*,s32);
extern "C" u8* fn_80403328(const char*);
static inline void tu80301_fadeStep(s32 i,s32 owner,bool advance) {
    switch(lbl_8053ACEC[i]) {
    case 0:
        if(lbl_8053ACE8[i]){lbl_8053ACF0[i]=0;lbl_8053ACEC[i]++;}
        break;
    case 1:
        lbl_8053ACF0[i]++;
        if((lbl_8053ACE8[i]==1&&fn_8022F64C(owner))||(lbl_8053ACE8[i]!=1&&lbl_8053ACF0[i]>=lbl_8053ACF4[i])){
            lbl_8053ACF0[i]=0;lbl_8053ACEC[i]++;
        }
        break;
    case 2:
        if(lbl_8053ACE8[i]==1){if(lbl_8053ACF0[i]<31)lbl_8053ACF0[i]++;else if(advance)lbl_8053ACEC[i]++;}
        else{if(lbl_8053ACF0[i]<16)lbl_8053ACF0[i]++;else if(advance)lbl_8053ACEC[i]++;}
        break;
    case 3:
        if(advance){if(lbl_8053ACF0[i])lbl_8053ACF0[i]--;break;}
    default:
        if(advance){lbl_8053ACE8[i]=0;lbl_8053ACEC[i]=0;lbl_8053ACF0[i]=0;lbl_8053ACF4[i]=0;}
        else if(lbl_8053ACF0[i]==0){lbl_8053ACE8[i]=0;lbl_8053ACEC[i]=0;lbl_8053ACF4[i]=0;}
        else lbl_8053ACF0[i]--;
    }
}
static inline void tu80301_fadeCounter(s32 owner) {
    if(lbl_8053ACF8[owner]){if(lbl_8053ACFC[owner]<17)lbl_8053ACFC[owner]++;}
    else lbl_8053ACFC[owner]=0;
}
static inline void tu80301_packetChecksum(u8* p,MsgEntry_80301CD0* entries,s32 head) {
    u32 sum=0;
    if(entries[head].f118==0) {
        int i;u8* q=p+8;int limit=lbl_80541618[lbl_8053AD08]*4;
        for(i=8;i<limit;i++)sum+=*q++;
    }else{
        int i;u8* q=p+8;int limit=lbl_80541618[lbl_8053AD08]*4;
        for(i=8;i<limit;i++)sum+=*q++;
    }
    p[0]=sum;
}

extern "C" void fn_8030801C(s32 param_1, s32 i);
extern "C" void fn_80306A94(void* ctx, int player);
#pragma opt_common_subs off
extern "C" void fn_80304FB0(s32 param_1) {
MsgEntry_80301CD0* entries;
u32* buffer;
u16* data;
u8* p;
u8* received;
s32 owner;
lbl_8053AD08=0;
for(s32 k=0;k<4;k++)if(lbl_804DB798[k][0xd8]||lbl_804DB798[k][0xd9])lbl_8053AD08++;
if(lbl_8053AD08)lbl_8053AD08=(lbl_8053AD08-1)&3;
for(s32 i=0;i<4;i++){
owner=fn_8022EA0C(i);
received=lbl_804DB798[i];
p=lbl_80506DE8+i*0x68;
buffer=(u32*)(lbl_804DBC18+i*0x8000);
data=(u16*)(lbl_805071E8+i*0x100);
entries=(MsgEntry_80301CD0*)(lbl_804FBC18+i*0x2380);
MsgEntry_80301CD0* entry;
if((u8)AnimTable_IsField0xe0LessThan3(lbl_8053AD30,fn_8030AAF4(i))){
if(lbl_8053ACD0&&tu80301_isPlayerOn(i)){
fn_80306A94((void*)param_1,i);
fn_802F53F4(*(u8**)(lbl_8053AB10+0x20),i,p);
lbl_80506D78[i]=(f32)(lbl_80506D78[i]+lbl_80541668);
tu80301_fadeStep(i,owner,false);tu80301_fadeCounter(owner);
}else fn_8030801C(param_1,i);
((u32*)lbl_80506D48)[i]=(((u32*)lbl_80506D48)[i]+1)&3;
goto next;
}
if(!fn_8030A308(lbl_8053AD30,fn_8030AAF4(i))){
entry=&entries[lbl_80504A18[i]];
if(entry->f118==1){entry->f119=0;entry->f104=0;entry->f10c=0;}
else if(lbl_8053AD20[i]==1&&lbl_8053AD24[i]!=1){
if(lbl_8053AD28[i]==1){lbl_8053AD0C[i]=lbl_8053AD14[i];lbl_8053AD24[i]=1;lbl_8053AD1C[i]=60;}
else{
do{data[lbl_8053AD0C[i]++]=fn_8037F0CC(i);}while(fn_8037F1E4(i)==3);
lbl_8053AD24[i]=1;lbl_8053AD1C[i]=60;
}}
((s32*)lbl_80506D58)[i]=5;goto next;
}
if(!lbl_8053AD34[i]){
if(fn_8030A308(lbl_8053AD30,fn_8030AAF4(i))==1&&lbl_8053ACD0&&tu80301_isPlayerOn(i)&&fn_8023DE58(owner)>=8)
(*(u8**)(lbl_8053AB10+0x20))[i+0x12c]=1;
goto next;
}
if(((u8*)lbl_8053AAF0)[0x60]){fn_8030801C(param_1,i);goto next;}
if(received[0xdc]){fn_80303CE4(i);received[0xdc]=0;}
lbl_80506D78[i]=(f32)(lbl_80506D78[i]+lbl_80541668);
tu80301_fadeStep(i,owner,true);tu80301_fadeCounter(owner);
if(((s32*)lbl_80506D58)[i]>0){
fn_8030801C(param_1,i);
((u32*)lbl_80506D48)[i]=(((u32*)lbl_80506D48)[i]+1)&3;
((s32*)lbl_80506D58)[i]--;goto next;
}
entry=&entries[lbl_80504A18[i]];
{
s32 wrong;
if(entry->f118==1&&entry->f104==0&&(entry->f114==0x600c000||entry->f114==0x600e000)&&entry->f110!=fn_8023DE58(owner))wrong=1;else wrong=0;
if(entry->f118==0||wrong==1){
if(lbl_8053AD20[i]==1){
if(lbl_8053AD24[i]==1){
if((*(u32*)(received+0x60)>>24)==3){lbl_8053AD20[i]=0;}
else {
lbl_8053AD1C[i]++;
if(lbl_8053AD1C[i]>40){
lbl_8053AD14[i]=lbl_8053AD0C[i];lbl_8053AD0C[i]=0;lbl_8053AD24[i]=0;((Packet_80301CD0*)p)->code=10;lbl_8053AD28[i]=1;
fn_803085A4(param_1,i);s32 n=0;u8* dst=p;
s32 limit=lbl_80541618[lbl_8053AD08]-2;
for(;n<limit;n++,dst+=4){
u32 word=(u32)data[lbl_8053AD0C[i]]|((u32)data[lbl_8053AD0C[i]+1]<<16);
lbl_8053AD0C[i]+=2;
*(u32*)(dst+8)=tu80301_swapWord(word);
if(lbl_8053AD0C[i]>=lbl_8053AD14[i]){
lbl_8053AD24[i]=1;lbl_8053AD1C[i]=0;((Packet_80301CD0*)p)->code=12;n++;break;
}}
for(;n<limit;n++)((u32*)p)[n+2]=0;
tu80301_packetChecksum(p,entries,lbl_80504A18[i]);
}else fn_8030801C(param_1,i);
}
}else if(lbl_8053AD28[i]==1){
((Packet_80301CD0*)p)->code=11;fn_803085A4(param_1,i);s32 n=0;u8* dst=p;
s32 limit=lbl_80541618[lbl_8053AD08]-2;
for(;n<limit;n++,dst+=4){
u32 word=(u32)data[lbl_8053AD0C[i]]|((u32)data[lbl_8053AD0C[i]+1]<<16);
lbl_8053AD0C[i]+=2;
*(u32*)(dst+8)=tu80301_swapWord(word);
if(lbl_8053AD0C[i]>=lbl_8053AD14[i]){
lbl_8053AD24[i]=1;lbl_8053AD1C[i]=0;((Packet_80301CD0*)p)->code=12;n++;break;
}}
for(;n<limit;n++)((u32*)p)[n+2]=0;
tu80301_packetChecksum(p,entries,lbl_80504A18[i]);
}else fn_80307B58(param_1,i,0);
}else{
if(fn_8037F1E4(i)==3&&tu80301_isPlayerOn(i)){
lbl_8053AD20[i]=1;lbl_8053AD24[i]=0;lbl_8053AD28[i]=0;lbl_8053AD0C[i]=0;
fn_80307B58(param_1,i,1);lbl_8053AD04[i]=0;
}
}
if(lbl_8053AD20[i]==0){if(lbl_8053ACD0&&tu80301_isPlayerOn(i))fn_80306A94((void*)param_1,i);else fn_8030801C(param_1,i);}
if(tu80301_isPlayerOn(i))fn_802F53F4(*(u8**)(lbl_8053AB10+0x20),i,p);
}else{
if(entry->f10c){
fn_8030801C(param_1,i);
if((*(u32*)(received+0x60)>>24)==2){
if((u32)entry->f114==0xffffffff)lbl_8053ACD4[i]=0;
else if(entry->f114==0x2033000)lbl_8053ACE0[i]=1;
entry->f118=0;entry->f119=0;entry->f104=0;entry->text[0]=0;
s32 tail=lbl_80504A28[i];
do{lbl_80504A18[i]++;if(lbl_80504A18[i]>=32)lbl_80504A18[i]=0;
if(lbl_80504A18[i]==tail)break;}while(!entries[lbl_80504A18[i]].f118);
}else{entry->f10c--;if(entry->f10c==0){entry->f119=0;entry->f104=0;}}
}else if(entry->f119==1){
((Packet_80301CD0*)p)->code=7;fn_803085A4(param_1,i);
s32 n=0;u8* dst=p;
while(n<lbl_80541618[lbl_8053AD08]-2){
*(u32*)(dst+8)=buffer[entry->f104++];
if(entry->f104>=entry->f100){((Packet_80301CD0*)p)->code=8;entry->f10c=60;break;}
dst+=4;n++;
}
tu80301_packetChecksum(p,entries,lbl_80504A18[i]);
}else{
((Packet_80301CD0*)p)->code=6;fn_803085A4(param_1,i);
u8* text;
if(entry->f114==0x600c000||entry->f114==0x600e000)text=fn_80403328(entry->text);
else text=(u8*)lbl_8053AAF8->text->convert(0x3f3f3f3f,entry->text);
for(s32 n=0;n<entry->f100;n++){buffer[n]=((u16*)text)[n*2+1]|((u32)((u16*)text)[n*2]<<16);}
*(u32*)(p+8)=tu80301_swapWord(entry->f11a);
*(u32*)(p+12)=tu80301_swapWord(entry->f114);
tu80301_packetChecksum(p,entries,lbl_80504A18[i]);
entry->f104=0;entry->f119=1;
}
}
}
((u32*)lbl_80506D48)[i]=(((u32*)lbl_80506D48)[i]+1)&3;
if(lbl_8053AD20[i]==0)lbl_8053AD04[i]=fn_80309A38(lbl_8053AD30,fn_8030AAF4(i));
next:;
}
fn_80304D64(param_1);
}
#pragma opt_common_subs reset

#pragma opt_propagation off
#pragma opt_common_subs off
extern "C" void fn_803064A8(void* p, const s32 argPlayer, const s32 argCount, const s32 argStart) {
    s32 v;
    s32 upper;
    u32 r21;
    Elem28_80301CD0* e;
    u8* q;
    u8* o;
    Elem28_80301CD0* base;
    s32 idx;
    s32 slot;
    s32 prio;
    s32 j;
    s32 start;
    start = argStart;
    idx = start;
    if (argCount == 0) {
        return;
    }
    slot = fn_8022EA0C(argPlayer);
    o = lbl_80506DE8 + argPlayer * 0x68 + start * 4;
    base = lbl_80505438[argPlayer];
    for (prio = 5; prio > 0; prio--) {
        e = base;
        q = o;
        for (j = 0; j < 40; j++, e++) {
            if (e->f24 == 0) {
                continue;
            }
            s32 t = fn_8023DE58(slot);
            if ((e->f8 != t && e->fc != argPlayer) || (*(s32*)((u8*)lbl_8053AAF8 + 0x4c) == 0xb && e->f23 == 0)) {
                e->f0 = 0;
                e->f25 = 1;
                continue;
            }
            if (e->f0 != prio && e->fc != argPlayer) {
                continue;
            }
            if (e->fc >= 0) {
                ((Out_803066F0*)(q + 0x18))->hi = ((u32)(int)e->f10) >> 8;
                ((Out_803066F0*)(q + 0x18))->b2 = (int)e->f10;
                ((Out_803066F0*)(q + 0x18))->b1 = (int)e->f14;
            } else {
                r21 = fn_8023D9B0(&e->f10, slot) & 0x1ff;
                u32 c = fn_8023D4F8(&e->f10, slot);
                if (r21 == 0x180 || c == 0xe0) {
                    e->f0 = 0;
                    e->f25 = 1;
                    continue;
                }
                ((Out_803066F0*)(q + 0x18))->hi = r21 >> 8;
                ((Out_803066F0*)(q + 0x18))->b2 = r21;
                ((Out_803066F0*)(q + 0x18))->b1 = c;
            }
            v = e->f1c;
            if (v > 0x3ff) {
                v -= 0x400;
                q[0x1b] = (((v >> 8) << 1) & 6U) | (q[0x1b] & ~6U);
                ((Out_803066F0*)(q + 0x18))->b0 = v;
                ((Out_803066F0*)(q + 0x18))->f20 = 2;
            } else {
                ((Out_803066F0*)(q + 0x18))->f1c = (upper = (u8)(v >> 8));
                ((Out_803066F0*)(q + 0x18))->b0 = v;
                ((Out_803066F0*)(q + 0x18))->f20 = e->f20;
            }
            ((Out_803066F0*)(q + 0x18))->f21 = e->f21;
            ((Out_803066F0*)(q + 0x18))->f22 = e->f22;
            e->f25 = 1;
            o += 4;
            q += 4;
            idx++;
            if (idx >= argCount) {
                return;
            }
        }
    }
}
#pragma opt_common_subs reset
#pragma opt_propagation reset
extern u8 lbl_80506DE8[];
extern "C" s32 fn_8022EA0C(s32);
extern "C" s32 fn_8023DE58(s32);
extern "C" u32 fn_8023D9B0(void*, s32);
extern "C" u8 fn_8023D4F8(void*, s32);
extern "C" s32 fn_803066F0(void* p, s32 idx, s32 max) {
    Out_803066F0* out = (Out_803066F0*)(lbl_80506DE8 + idx * 0x68 + 0x18);
    s32 count = 0;
    s32 big = 0;
    s32 pl = fn_8022EA0C(idx);
    for (s32 prio = 5; prio >= 0; prio--) {
        Ent_803066F0* e = (Ent_803066F0*)((u8*)lbl_80504A38 + idx * 0x280);
        for (s32 i = 0; i < 16; i++, e++) {
            if (e->f24 != 1 || e->prio != prio) {
                continue;
            }
            if (e->f8 != fn_8023DE58(pl)) {
                e->f25 = 1;
                continue;
            }
            u8* g = (u8*)lbl_8053AAF8;
            if (!(11 - *(s32*)(g + 0x4c)) || g[0x88] != 0) {
                if (e->f23 == 0) {
                    e->f25 = 1;
                    continue;
                }
            }
            s32 v = fn_8023D9B0(e->f10, pl) & 0x1ff;
            u8 w = fn_8023D4F8(e->f10, pl);
            if (v == 0x180 || w == 0xe0) {
                e->f25 = 1;
                continue;
            }
            if (e->f20 >= 4) {
                if (big >= 4) {
                    e->f25 = 1;
                    continue;
                }
                big++;
            }
            out->hi = (u8)(v >> 8);
            count++;
            out->b2 = v;
            out->b1 = w;
            out->f1c = e->f1c >> 8;
            e->f25 = 1;
            out->b0 = e->f1c;
            out->f20 = e->f20;
            out->f21 = e->f21;
            out->f22 = e->f22;
            if (count >= max) {
                return count;
            }
            out++;
        }
    }
    return count;
}

extern "C" void fn_803068D0(Hdr_80301CD0* hdr) {
    if (hdr->count == 0) {
        return;
    }
    s32 side = hdr->side;
    Slot_80301CD0* base = (Slot_80301CD0*)(lbl_80506F88 + ((s32(*)(s32))fn_8022F340)(hdr->player) * 0x98);
    Slot_80301CD0* dst = base + side * 19;
    u8 kind = hdr->kind;
    u32* src = (u32*)hdr->slots;
    u32* out = (u32*)dst;
    s32 i = 0;
    while (i < lbl_80541618[kind] - 7) {
        *out++ = *src++;
        i++;
    }
    for (; i < 19; i++) {
        dst[i].flag = 1;
        dst[i].f2 = 0x80;
    }
    Slot_80301CD0* other = base + (side ^ 1) * 19;
    for (i = 0; i < 19; i++) {
        if (other[i].type == 2 && ((other[i].idHi << 8) | other[i].id) < 0x45) {
            other[i].flag = 1;
            other[i].f2 = 0x80;
        }
    }
}

extern "C" u32 fn_802340A0(s32);
extern "C" u8 fn_8023F264(s32);
extern "C" u8 fn_8023188C(s32);
extern "C" void* fn_8023E724(s32);
extern "C" u8 fn_8022BC38(s32,s32,void*);
extern "C" u32 fn_8023D21C(s32,s32);
extern "C" u8 fn_8023CEAC(s32,s32);
extern "C" u32 fn_8023DAF4(s32,s32);
extern "C" u8 fn_8023D644(s32,s32);
extern "C" u32 fn_8023CBC0(s32);
extern "C" s32 fn_8022BECC();
extern "C" s8 fn_8023CA88(s32);
extern "C" u8 fn_8023EA28(s32);
extern "C" u8 fn_8023BCD4(s32);
extern "C" u32 fn_8023CE10(s32);
extern "C" u32 fn_8023CD74(s32);
extern "C" s32 fn_803066F0(void*,s32,s32);

extern "C" u64 fn_802D7AC4(void*,s32);
#pragma opt_lifetimes on
#pragma opt_propagation off
static inline void packetHeaderBits(u8* p,s32 owner,int player) {
    ((Ctl4_80301CD0*)(p+0xb))->y=fn_8023CE10(owner)>>5;
    Ctl4_80301CD0* header0=(Ctl4_80301CD0*)(p+0xb);
    header0->x=fn_8023CE10(owner)>>4;
    ((Ctl4_80301CD0*)(p+0xf))->y=fn_8023CE10(owner);
    Ctl4_80301CD0* header1=(Ctl4_80301CD0*)(p+0xf);
    ((Ctl4_80301CD0*)(p+0x13))->y=fn_8023CD74(owner)>>5;
    Ctl4_80301CD0* header2=(Ctl4_80301CD0*)(p+0x13);
    header2->x=fn_8023CD74(owner)>>4;
    ((Ctl4_80301CD0*)(p+0x17))->y=fn_8023CD74(owner);
    Ctl4_80301CD0* header3=(Ctl4_80301CD0*)(p+0x17);
    u8 active=0;
    if(fn_8037F1E4(player)>=1 && fn_8037F1E4(player)<=5) active=1;
    header1->x=active!=0;
    active=0;
    if(fn_8022F5B0(owner)) {
        s32 room=fn_8023DE58(owner);
        if(!fn_802D7804(fn_802D6A9C(),room,2)) active=1;
    }
    header3->x=active!=0;
}



extern "C" void fn_80306A94(void* ctx,int player) {
    if(((u8*)lbl_8053AAF8)[0x82] & (u8)(1<<player))
        ((Packet_80301CD0*)(lbl_80506DE8+player*0x68))->code=5;
    else ((Packet_80301CD0*)(lbl_80506DE8+player*0x68))->code=14;
    fn_803085A4((s32)ctx,player);
    s32 owner=fn_8022EA0C(player);
    u8* p=lbl_80506DE8+player*0x68;
    Hi_80301CD0* firstFlags=(Hi_80301CD0*)(p+1);
    for(s32 i=0;i<4;i++) {
        u32 slot=fn_802340A0(i);
        if(!fn_8023F264(i) || !fn_8023188C(i) || fn_8023DE58(owner)<8) goto empty;
        {
            if(fn_8022BC38(owner,fn_8023DE58(i),fn_8023E724(i))) goto valid;
            if(fn_8023DE58(owner)<=8 && fn_8023DE58(i)<=8) goto valid;
        }
empty:
        ((Ctl4_80301CD0*)(p+slot*4+0xb))->flag=1;
        p[slot*4+0xa]=0x80;
        p[slot*4+9]=0xe0;
        ((Ctl4_80301CD0*)(p+slot*4+0xb))->mode=0;
        p[slot*4+8]=0;
        goto nextPlayer;
valid:
        if(fn_8023DE58(i)<8) {
            firstFlags->y |=1<<slot;
            ((Ctl4_80301CD0*)(p+slot*4+0xb))->flag=fn_8023D21C(i,owner)>>8;
            p[slot*4+0xa]=fn_8023D21C(i,owner);
            p[slot*4+9]=fn_8023CEAC(i,owner);
        } else {
            ((Ctl4_80301CD0*)(p+slot*4+0xb))->flag=fn_8023DAF4(i,owner)>>8;
            p[slot*4+0xa]=fn_8023DAF4(i,owner);
            p[slot*4+9]=fn_8023D644(i,owner);
        }
        ((Ctl4_80301CD0*)(p+slot*4+0xb))->mode=fn_8023CBC0(i)>>8;
        p[slot*4+8]=fn_8023CBC0(i);
nextPlayer:;
    }
    if((((s32*)lbl_80506D48)[player]&1)==1) {
        Hi_80301CD0* flags7=(Hi_80301CD0*)(p+7);
        u8* state6=p+6;
        for(s32 i=0;i<4;i++) {
            u32 slot=fn_802340A0(i);
            s32 mask=fn_8022BECC()<<slot;
            u8 oldFlags=flags7->y;
            ((volatile Hi_80301CD0*)flags7)->y=oldFlags|mask;
            u8 state;
            u8* game=(u8*)lbl_8053AAF8;
            bool special;
            if(*(s32*)(game+0x4c)==11) special=true;
            else special=game[0x88]==2;
            if(special) state=3;
            else if(fn_8023CA88(slot)>0) {
                s32 room=fn_8023DE58(i);
                u16 flags=*(u16*)((u8*)fn_802D6A9C()+room*2+0x131b8);
                if(((flags>>12)&3)==0) state=3;
                else state=1;
            } else if(fn_8023EA28(i)) state=1;
            else state=0;
            *state6 |=state<<(slot*2);
            if(fn_8023BCD4(slot)<0xa0) flags7->lo |=1<<slot;
        }
    }
    packetHeaderBits(p,owner,player);
    tu80301_clearCtl(p,lbl_80541618[lbl_8053AD08]-7);
    s32 count=0;
    if(fn_8023F264(player)) count=fn_803066F0((void*)ctx,player,lbl_80541618[lbl_8053AD08]-7);
    if(fn_8023F264(player)) fn_803064A8((void*)ctx,player,lbl_80541618[lbl_8053AD08]-7-count,count);
    for(s32 end=lbl_80541618[lbl_8053AD08]-8;end>0;end--) {
        s32 i;
        u8* q=p;
        for(i=0;i<end;q+=4,i++) {
            s32 a=fn_803074A4(((Slot_80301CD0*)(q+0x18))->type,((Slot_80301CD0*)(q+0x18))->id | (((Slot_80301CD0*)(q+0x18))->idHi<<8));
            u8* nextSlot=p+(i+1)*4;
            s32 b=fn_803074A4(((Slot_80301CD0*)(nextSlot+0x18))->type,q[0x1c] | (((Slot_80301CD0*)(nextSlot+0x18))->idHi<<8));
            if(q[0x1d]!=0xe0 && (a<b || (a==b && q[0x19]<q[0x1d]))) {
                u32 tmp=*(u32*)(nextSlot+0x18);
                *(u32*)(nextSlot+0x18)=*(u32*)(q+0x18);
                *(u32*)(q+0x18)=tmp;
            }
        }
    }
    if((((s32*)lbl_80506D48)[player]&1)==0) {
        if(fn_8023DE58(owner)<8) {
            u32 word=fn_802D7AC4(fn_802D6A9C(),8)&0xffffffffULL;
            *(u32*)(p+lbl_80541618[lbl_8053AD08]*4-4)=tu80301_swapWord(word);
        } else {
            s32 room=fn_8023DE58(owner);
            u32 word=fn_802D7AC4(fn_802D6A9C(),room)&0xffffffffULL;
            *(u32*)(p+lbl_80541618[lbl_8053AD08]*4-4)=tu80301_swapWord(word);
        }
    } else {
        if(fn_8023DE58(owner)<8) {
            u32 word=fn_802D7AC4(fn_802D6A9C(),8)>>32;
            *(u32*)(p+lbl_80541618[lbl_8053AD08]*4-4)=tu80301_swapWord(word);
        } else {
            s32 room=fn_8023DE58(owner);
            u32 word=fn_802D7AC4(fn_802D6A9C(),room)>>32;
            *(u32*)(p+lbl_80541618[lbl_8053AD08]*4-4)=tu80301_swapWord(word);
        }
    }
    u32 sum=0;
    MsgEntry_80301CD0* entry=&((MsgEntry_80301CD0*)(lbl_804FBC18+player*0x2380))[lbl_80504A18[player]];
    if(entry->f118==0) {
        int i;
        u8* q;
        int limit;
        q=p+8;
        limit=lbl_80541618[lbl_8053AD08]*4;
        for(i=8;i<limit;i++) sum+=*q++;
    } else {
        int i;
        u8* q;
        int limit;
        q=p+8;
        limit=lbl_80541618[lbl_8053AD08]*4;
        for(i=8;i<limit;i++) sum+=*q++;
    }
    p[0]=sum;
}
#pragma opt_lifetimes reset
// fn_803074A4(a, b) - a range-dispatch classifier: returns a small
// integer code (-1, 0, 1, 2, 3, or 4) based on which named range `b`
// falls in, with the applicable range set selected by `a`.
extern "C" s32 fn_803074A4(s32 a, s32 b) {
	if (a == 2) {
		if (b >= 0x39 && b < 0x45) {
			return 4;
		}
		if (b >= 0x0 && b < 0x25) {
			return -1;
		}
		if (b >= 0x200) {
			return 1;
		}
		return 0;
	} else {
		if (a == 0 || a == 1) {
			if ((b >= 0xc0 && b < 0xd3) || (b >= 0x155 && b < 0x158)) {
				return 3;
			}
			if (b >= 0x37 && b < 0x41) {
				return 2;
			}
			if (b >= 0x3cd && b < 0x3ce) {
				return -1;
			}
			if (b >= 0x2a3 && b < 0x2aa) {
				return 4;
			}
			if (b >= 0x34c && b < 0x37c) {
				return 4;
			}
			if (a == 1) {
				return 1;
			}
			return 0;
		} else {
			return 0;
		}
	}
}

#pragma opt_propagation on
extern "C" s32 fn_803075AC(s32 caller, s32 room, const void* __restrict pos, s32 id, u8 on, s32 mode, s32 target, s32 kind, u8 b, u8 d) {
    Elem28_80301CD0* base;
    u8 k;
    s32 ok;
    s32 i;
    bool enabled;
    s32 n;
    s32 c;
    Elem28_80301CD0* e;

    if (room < 8 && room != -1) {
        return 0;
    }
    enabled=on!=0;
    k=kind;
    ok=0;
    for (i = 0; i < 4; i++) {
        s32 r = fn_8022EA0C(i);
        if (((*((u8*)lbl_8053AAF8 + 0x82)) & (u8)(1 << i)) == 0) {
            continue;
        }
        if (target != i && (target >= 0 || fn_8023DE58(r) != room)) {
            continue;
        }
        base = lbl_80505438[i];
        e=base;
        n = 0;
        for(;n<40;e++,n++) { if(e->f24==1 && e->f4==caller) break; }
        if (n < 40) {
            e->f8 = room;
            *(JGeometry::TVec3<f32>*)&e->f10 = *(const JGeometry::TVec3<f32>*)pos;
            ok = 1;
            e->f1c = id;
            e->f21 = enabled;
            e->f22 = b;
        } else {
            e = base;
            for (c = 0x28; c != 0; c--) {
                if (e->f24 == 0) {
                    e->f0 = mode;
                    e->f4 = caller;
                    e->f8 = room;
                    e->fc = target;
                    *(JGeometry::TVec3<f32>*)&e->f10 = *(JGeometry::TVec3<f32>*)pos;
                    ok = 1;
                    e->f1c = id;
                    e->f21 = enabled;
                    e->f20 = k;
                    e->f23 = d;
                    e->f22 = b;
                    e->f24 = 1;
                    break;
                }
                e++;
            }
        }
    }
    return ok;
}

#pragma opt_propagation on
extern "C" s32 fn_80307830(s32 caller, s32 room, const void* __restrict pos, s32 id, u8 on, u8 mode, u8 b, u8 kind) {
    s32 c;
    int k;
    int ok;
    s32 i;
    bool enabled;
    int n;
    register Elem28_80301CD0* base;
    Elem28_80301CD0* e;

    if (room < 8) {
        return 0;
    }
    enabled=on!=0;
    ok=0;
    k=(kind&3)|4;
    for (i = 0; i < 4; i++) {
        s32 r = fn_8022EA0C(i);
        if (((*((u8*)lbl_8053AAF8 + 0x82)) & (u8)(1 << i)) == 0) {
            continue;
        }
        if (fn_8023DE58(r) != room) {
            continue;
        }
        base = lbl_80504A38[i];
        e=base;
        n = 0;
        for(;n<16;e++,n++) { if(e->f24==1 && e->f4==caller) break; }
        if (n < 16) {
            e->f8 = room;
            *(JGeometry::TVec3<f32>*)&e->f10 = *(const JGeometry::TVec3<f32>*)pos;
            ok = 1;
            e->f1c = id;
            e->f21 = enabled;
            e->f22 = b;
        } else {
            e = base;
            for (c = 0x10; c != 0; c--) {
                if (e->f24 != 1) {
                    e->f4=caller;
                    e->f8=room;
                    *(JGeometry::TVec3<f32>*)&e->f10 = *(const JGeometry::TVec3<f32>*)pos;
                    e->f1c=id;
                    e->f24=1;
                    e->f0=1;
                    if(mode) {
                        if(kind==4) e->f20=3;
                        else e->f20=(s32)k;
                    } else e->f20=2;
                    e->f21=enabled;
                    e->f23=0;
                    e->f22=b;
                    ok=1;
                    break;
                }
                ++e;
            }
        }
    }
    return ok;
}
#pragma opt_propagation reset
// fn_80307AC8 - effect spawn dispatcher: ids below 0x45 go to the small
// effect table (fn_80307830), others to the generic effect spawner.
extern "C" s32 fn_80307830(s32 caller, s32 room, const void* pos, s32 id, u8 on, u8 a, u8 b, u8 kind);


extern "C" s32 fn_80307AC8(u32 caller, s32 room, void* pos, s32 id, s32 on, s32 b, s32 target) {
    if (b == 2) {
        b = 0;
        id += 0x200;
    }
    if (id < 0x45) {
        return fn_80307830(caller, room, pos, id, on != 0, 0, b != 0, 4);
    }
    return fn_803075AC(caller, room, pos, id + 0x400, on ? 1 : 0, 2, target, 0, b ? 1 : 0, 0);
}

extern u16 lbl_8053AD0C[4];
extern u8 lbl_8053AD24[4];
extern u8 lbl_8053AD1C[4];
extern "C" u16 fn_8037F0CC(s32);
extern "C" void fn_803085A4(s32, s32);
#pragma opt_common_subs off
#pragma opt_strength_reduction off
extern "C" void fn_80307B58(s32 unused, s32 player, u8 flag) {
    if (flag) {
        u8* rec = lbl_80506DE8 + player * 0x68;
        ((Packet_80301CD0*)rec)->code = 10;
    } else {
        u8* rec = lbl_80506DE8 + player * 0x68;
        ((Packet_80301CD0*)rec)->code = 11;
    }
    fn_803085A4(unused, player);
    s32 i;
    s32 start;
    s32 max = (lbl_80541618[lbl_8053AD08] - 2) * 2;
    start = lbl_8053AD0C[player];
    u16* data = (u16*)(lbl_805071E8 + player * 0x100);
    for (i = 0; i < max; ++i) {
        data[start + i] = fn_8037F0CC(player);
        if (fn_8037F1E4(player) != 3) {
            u8* rec = lbl_80506DE8 + player * 0x68;
            u8 code = 12;
            lbl_8053AD24[player] = 1;
            ++i;
            lbl_8053AD1C[player] = 0;
            ((Packet_80301CD0*)rec)->code = code;
            break;
        }
    }
    lbl_8053AD0C[player] += i;
    for (; i < max; ++i) {
        ((u16*)(lbl_805071E8 + player * 0x100))[start + i] = 0;
    }
    s32 n;
    n = lbl_80541618[lbl_8053AD08] - 2;
    u8* rec = lbl_80506DE8 + player * 0x68;
    u8 b0, b1, b2, b3;
    s32 j;
    u8* dst;
    u8* copyBase = lbl_805071E8 + player * 0x100;
    dst = rec;
    j = start * 2;
    for (s32 k = n; k > 0; --k) {
        u16* src = (u16*)(copyBase + j);
        Slot_80301CD0 out;
        u32 word;
        u32 hi = src[1];
        u32 lo = src[0];
        word = (hi << 16) | lo;
        u8* bytes = (u8*)&word;
        b3 = bytes[3];
        b2 = bytes[2];
        b1 = bytes[1];
        b0 = bytes[0];
        out.id = b3;
        out.f1 = b2;
        out.f2 = b1;
        ((u8*)&out)[3] = b0;
        *(u32*)(dst + 8) = *(u32*)&out;
        dst += 4;
        j += 4;
    }
    u32 sum = 0;
    MsgEntry_80301CD0* e = &((MsgEntry_80301CD0*)(lbl_804FBC18 + player * 0x2380))[lbl_80504A18[player]];
    if (e->f118 == 0) {
        int b;
        u8* p;
        int limit;
        p = rec + 8;
        limit = lbl_80541618[lbl_8053AD08] * 4;
        for (b = 8; b < limit; ++b) sum += *p++;
    } else {
        int b;
        u8* p;
        int limit;
        p = rec + 8;
        limit = lbl_80541618[lbl_8053AD08] * 4;
        for (b = 8; b < limit; ++b) sum += *p++;
    }
    rec[0] = sum;
}
#pragma opt_common_subs reset
#pragma opt_strength_reduction reset
extern "C" u8 fn_8022F5B0(s32);
extern "C" void fn_8030801C(s32 param_1, s32 i) {
    u8* pf;
    u8* pl;
    u8* p;
    u8* q;
    u8* ent;
    u8 lv;
    s32 ret;
    int cnt;
    s32 n;
    s32 done;
    s32 sum;
    s32 k;

    if (*((u8*)lbl_8053AAF0 + 0x78) >= 4) {
        s32 st = *(s32*)((u8*)lbl_8053AAF8 + 0x4c);
        if ((tu80301_isState7(st) & 0xff) || st == 0xb || st == 0xc) {
            ((Hi_80301CD0*)(lbl_80506DE8 + i * 0x68 + 3))->y = 9;
        } else {
            ((Hi_80301CD0*)(lbl_80506DE8 + i * 0x68 + 3))->y = 13;
        }
    } else {
        ((Hi_80301CD0*)(lbl_80506DE8 + i * 0x68 + 3))->y = 13;
    }
    fn_803085A4(param_1, i);
    p = lbl_80506DE8 + i * 0x68;
    pf = p + 0xf;
    pl = p + 0x17;
    ((Ctl4_80301CD0*)(p + 0xb))->flag = 1;
    p[0xa] = 0x80;
    p[0x9] = 0xe0;
    ((Ctl4_80301CD0*)(p + 0xb))->mode = 0;
    p[0x8] = 0;
    ((Ctl4_80301CD0*)pf)->flag = 1;
    p[0xe] = 0x80;
    p[0xd] = 0xe0;
    ((Ctl4_80301CD0*)pf)->mode = 0;
    p[0xc] = 0;
    ((Ctl4_80301CD0*)(p + 0x13))->flag = 1;
    p[0x12] = 0x80;
    p[0x11] = 0xe0;
    ((Ctl4_80301CD0*)(p + 0x13))->mode = 0;
    p[0x10] = 0;
    ((Ctl4_80301CD0*)pl)->flag = 1;
    p[0x16] = 0x80;
    p[0x15] = 0xe0;
    ((Ctl4_80301CD0*)pl)->mode = 0;
    p[0x14] = 0;
    ((Ctl4_80301CD0*)(p + 0xb))->y = 0;
    ((Ctl4_80301CD0*)(p + 0xb))->x = 0;
    ((Ctl4_80301CD0*)pf)->y = 0;
    ((Ctl4_80301CD0*)(p + 0x13))->y = 0;
    ((Ctl4_80301CD0*)(p + 0x13))->x = 0;
    ((Ctl4_80301CD0*)pl)->y = 0;

    ret = fn_8022EA0C(i);
    if (*((u8*)lbl_8053AAF0 + 0x78) >= 4) {
        lv = 0;
        if (fn_8037F1E4(i) >= 1 && fn_8037F1E4(i) <= 5) lv = 1;
        ((Ctl4_80301CD0*)pf)->x = lv != 0;
        if (lbl_8053ACD0 != 0 && (*((u8*)lbl_8053AAF8 + 0x82) & (u8)(1 << i))) {
            ((Ctl4_80301CD0*)pl)->x = tu80301_roomVisible(ret) != 0;
        } else {
            ((Ctl4_80301CD0*)pl)->x = 0;
        }
    } else {
        ((Ctl4_80301CD0*)pf)->x = 0;
        ((Ctl4_80301CD0*)pl)->x = 0;
    }

    tu80301_clearCtl(p, lbl_80541618[lbl_8053AD08] - 7);

    MsgEntry_80301CD0* entry = &((MsgEntry_80301CD0*)(lbl_804FBC18 + i * 0x2380))[lbl_80504A18[i]];
    u32 total = 0;
    if (entry->f118 == 0) {
        int j;
        u8* bytes;
        int limit;
        bytes = p + 8;
        limit = lbl_80541618[lbl_8053AD08] * 4;
        for (j = 8; j < limit; j++) total += *bytes++;
    } else {
        int j;
        u8* bytes;
        int limit;
        bytes = p + 8;
        limit = lbl_80541618[lbl_8053AD08] * 4;
        for (j = 8; j < limit; j++) total += *bytes++;
    }
    p[0] = total;
}

#pragma opt_strength_reduction reset
#pragma opt_common_subs reset
extern "C" void fn_803085A4(s32 unused, s32 i)
{
    u8* e;
    Rec2_80301CD0* q2;
    Rec3_80301CD0* q3;
    Rec4b_80301CD0* p4;
    s32 i4;
    s32 off;
    s32 r26;
    s32 r25;
    s32 x;

    r25 = fn_8022EA0C(i);
    off = i * 0x68;
    e = lbl_80506DE8 + off;
    q3 = (Rec3_80301CD0*)(e + 3);
    q2 = (Rec2_80301CD0*)(e + 2);
    q3->lo = lbl_8053AD08;
    q2->c = r25;
    if (fn_8023DE58(r25) < 8) {
        q2->b = 0;
    } else {
        q2->b = fn_8023DE58(r25) - 7;
    }
    i4 = i * 4;
    q2->a = *(s32*)(lbl_80506D48 + i4);

    if (lbl_8053ACD0 != 0 && tu80301_isPlayerOn(i)) {
        if (*(s32*)((u8*)lbl_8053AAF8 + 0x4c) == 9 || ((u8*)lbl_8053AAF8)[0x80] != 0 ||
            (lbl_8053ACD8[i] != 0 && (fn_8037F1E4(i) < 1 || fn_8037F1E4(i) > 5))) {
            q2->flag = 1;
        } else {
            q2->flag = 0;
        }
        q3->m = lbl_8053ACEC[i] > 1 ? lbl_8053ACE8[i] : (u8)0;
    } else {
        q2->flag = 1;
        q3->m = 0;
    }

    ((Nib_80301CD0*)(e + 1))->hi = 0;
    ((Nib_80301CD0*)(e + 1))->lo = 0;
    p4 = (Rec4b_80301CD0*)(e + 4);
    ((Nib_80301CD0*)(e + 1))->lo |= lbl_8053ACF8[0];
    ((Nib_80301CD0*)(e + 1))->lo |= lbl_8053ACF8[1] << 1;
    ((Nib_80301CD0*)(e + 1))->lo |= lbl_8053ACF8[2] << 2;
    ((Nib_80301CD0*)(e + 1))->lo |= lbl_8053ACF8[3] << 3;
    *(u32*)(e + 4) = 0;
    if (*(s32*)(lbl_80506D48 + i4) == 1) {
        ((Nib_80301CD0*)(e + 5))->hi = 0xf;
    }
    if (((u8*)lbl_8053AAF0)[0x78] < 4 || (((u8*)lbl_8053AAF8)[0x82] & (u8)(1 << i)) == 0) {
        goto end;
    }
    ((Rec4a_80301CD0*)p4)->lo = *(s32*)((u8*)lbl_80506D38 + i4);
    *(s32*)((u8*)lbl_80506D38 + i4) = 0;
    if (lbl_8053ACD0 == 0 && !fn_80379F84(lbl_8053AD68)) {
        goto chain2;
    }
    if ((*(s32*)(lbl_80506D48 + i4) & 1) == 0) {
        Rec6_80301CD0* p6;
        ((Rec5a_80301CD0*)(e + 5))->lo = *(s32*)((u8*)lbl_80529DEC + i4 + 0xd8);
        ((Rec4a_80301CD0*)p4)->hi = (u8)(*(s32*)((u8*)lbl_80529DEC + i4 + 0xc8) / 4 - 1);
        ((Rec6_80301CD0*)(e + 6))->lo = (u8)fn_8037EE8C(i);
        p6 = (Rec6_80301CD0*)(e + 6);
        x = *(s32*)((u8*)lbl_80529DEC + (i4 + 0xe8)) + 5000;
        if (x > 14999) {
            x = 14999;
        } else if (x < 0) {
            x = 0;
        }
        lbl_80506DE8[off + 7] = (x >> 6) & 0xff;
        p6->hi = x & 0x3f;
    } else if (*(s32*)(lbl_80506D48 + i4) == 1) {
        u8* g = (u8*)lbl_8053AAF8;
        u8* h = (u8*)lbl_8053AEC8;
        u8 g88 = g[0x88];
        BOOL t = *(s32*)(g + 0x4c) == 0xb;
        u8 cc;
        if (h != NULL && (h[0x40] == 1 || (u8)(h[0x40] - 3) <= 1 || h[0x40] == 6)) {
            cc = 1;
        } else {
            cc = 0;
        }
        p4->two = g88 | ((cc << 1) | t);
        ((Nib_80301CD0*)(e + 5))->hi = *(s32*)((u8*)lbl_80529DEC + i4 + 0xf8);
    }

chain2:
    if (lbl_8053ACD0 != 0) {
        if (*(s32*)(lbl_80506D48 + i4) == 2) {
            r25 = fn_8023DE58(r25);
            ((Rec5_80301CD0*)(e + 5))->flag = fn_802D7804(fn_802D6A9C(), r25, 1);
        } else if ((*(s32*)(lbl_80506D48 + i4) & 1) == 1) {
            if (fn_8023DE58(r25) >= 8) {
                bool blocked;
                if (*(s32*)((u8*)lbl_8053AAF8 + 0x4c) == 0xb) {
                    blocked = true;
                } else {
                    blocked = ((u8*)lbl_8053AAF8)[0x88] == 2;
                }
                if (!blocked) {
                    if (fn_8023BC38(r25) > 0) {
                        r26 = (fn_8023BC38(r25) + 59) / 60;
                        if (r26 > 11) {
                            r26 = 11;
                        }
                        r26 += 20;
                    } else {
                        if (fn_80236768(r25) > 0) {
                            r26 = (fn_80236768(r25) + 59) / 60;
                        } else if (fn_80236630(r25) > 0) {
                            r26 = (fn_80236630(r25) + 59) / 60;
                        } else if (fn_802366CC(r25) > 0) {
                            r26 = (fn_802366CC(r25) + 59) / 60;
                        } else {
                            r26 = (*(s32*)((u8*)fn_802D6A9C() + 0xc4) + 59) / 60;
                            if (*((u8*)fn_802D6A9C() + 0x131f0) == 0 || r26 > 5) {
                                r26 = 0;
                            }
                        }
                        if (r26 > 20) {
                            r26 = 20;
                        }
                    }
                    p4->flag = r26;
                    ((Nib_80301CD0*)(e + 5))->lo = (u8)(r26 >> 1);
                }
            }
            if (*(s32*)(lbl_80506D48 + i4) == 3) {
                Rec5_80301CD0* p5;
                u8 v;
                r26 = fn_8023DE58(r25);
                if (fn_802D7804(fn_802D6A9C(), r26, 0xc)) {
                    r26 = fn_8023DE58(r25);
                    ((Rec5_80301CD0*)(e + 5))->two = (u32)((u16*)((u8*)fn_802D6A9C() + 0x131b8))[r26] >> 2;
                } else {
                    ((Rec5_80301CD0*)(e + 5))->two = (u8)fn_802351D8(r25) != 0;
                }
                r25 = fn_8023DE58(r25);
                p4->two = (u32)((u16*)((u8*)fn_802D6A9C() + 0x131b8))[r25] >> 12;
                v = fn_80237060(i) - 1;
                p5 = (Rec5_80301CD0*)(e + 5);
                e[5] = (e[5] & 0xBF) | ((v << 6) & 0x40);
                if (!fn_802DEBF8() && !fn_802DEBA0()) {
                    p5->flag = 1;
                }
            }
        }
    }

    if (fn_80379F84(lbl_8053AD68)) {
        if (*(s32*)(lbl_80506D48 + i4) == 0) {
            ((Rec5_80301CD0*)(e + 5))->flag = 1;
        } else if (*(s32*)(lbl_80506D48 + i4) == 3) {
            ((Rec5_80301CD0*)(e + 5))->flag = 1;
        }
    }

end:
    lbl_8053ACDC[i] = 0;
}

extern void* lbl_804AA8B8[];
extern "C" void fn_80308D0C() {
    for (s32 i = 0; i < 4; i++) {
        for (int j = 0; j < 16; j++) {
            lbl_80504A38[i][j].f24 = 0;
            lbl_80504A38[i][j].f25 = 0;
            lbl_80504A38[i][j].f0 = 0;
            lbl_80504A38[i][j].f4 = -1;
        }
        for (int j = 0; j < 40; j++) {
            lbl_80505438[i][j].f24 = 0;
            lbl_80505438[i][j].f25 = 0;
            lbl_80505438[i][j].f0 = 0;
            lbl_80505438[i][j].f4 = -1;
            lbl_80505438[i][j].fc = -1;
        }
    }
}

extern "C" void fn_80308E90() {
    s32 i;
    for (i = 0; i < 4; i++) {
        Elem28_80301CD0* b = lbl_80505438[i];
        Elem28_80301CD0* a = lbl_80504A38[i];
        for (int j = 0; j < 16; j++) {
            a[j].f24 = 0;
            a[j].f25 = 0;
            a[j].f0 = 0;
            a[j].f4 = -1;
        }
        for (int j = 0; j < 40; j++) {
            b[j].f24 = 0;
            b[j].f25 = 0;
            b[j].f0 = 0;
            b[j].f4 = -1;
            b[j].fc = -1;
        }
    }
}

extern "C" void* fn_80309014(void* p, s16 how) {
    if (p != 0) {
        *(void**)p = lbl_804AA8B8;
        if (how > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern u8 lbl_8053AD00[4];
extern u8 lbl_8053AD04[4];
extern u8 lbl_8053AD28[4];
extern u8 lbl_8053ACFC[4];
extern u16 lbl_8053AD14[4];
extern "C" s32 fn_8030905C(s32 self) {
int j;
*(void**)self=lbl_804AA8B8;
for(s32 i=0;i<4;i++) {
lbl_80504A28[i]=lbl_80504A18[i]=j=0;
clearMessageEntries((MsgEntry_80301CD0*)(lbl_804FBC18+i*0x2380));
for(j=0;j<0x2000;j++) ((u32*)(lbl_804DBC18+i*0x8000))[j]=0xcdcdcdcd;
lbl_8053AD00[i]=0;
((u32*)lbl_80506D48)[i]=0;
((u32*)lbl_80506D58)[i]=5;
fn_8030801C(self,i);
lbl_8053ACD4[i]=1;
lbl_80506D38[i]=0;
lbl_8053ACD8[i]=0;
lbl_8053ACDC[i]=0;
lbl_8053ACE0[i]=0;
lbl_8053ACE4[i]=0;
((u32*)lbl_80506D68)[i]=0;
for(j=0;j<19;j++) {
Slot_80301CD0* a=(Slot_80301CD0*)(lbl_80506F88+i*0x98+j*4);
a->flag=1;
a->f2=0x80;
Slot_80301CD0* b=(Slot_80301CD0*)(lbl_80506F88+i*0x98+j*4+0x4c);
b->flag=1;
b->f2=0x80;
}
lbl_80506DA8[i*4]=0;
((u32*)lbl_80506D88)[i]=0;
lbl_80506DB8[i*4]=0;
((u32*)lbl_80506D98)[i]=0;
lbl_80506DC8[i*4]=0;
lbl_8053ACE8[i]=0;
lbl_80506DA8[i*4+1]=0;
lbl_8053ACEC[i]=0;
lbl_80506DB8[i*4+1]=0;
lbl_8053ACF0[i]=0;
lbl_80506DC8[i*4+1]=0;
lbl_8053ACF8[i]=0;
lbl_80506DA8[i*4+2]=0;
lbl_80506DB8[i*4+2]=0;
lbl_80506DC8[i*4+2]=0;
lbl_8053ACFC[i]=0;
lbl_80506DA8[i*4+3]=0;
((u32*)lbl_80506DD8)[i]=0;
lbl_80506DB8[i*4+3]=0;
lbl_80506DC8[i*4+3]=0;
for(j=0;j<128;j++) ((u16*)(lbl_805071E8+i*0x100))[j]=0;
lbl_8053AD0C[i]=0;
lbl_8053AD14[i]=0;
lbl_8053AD04[i]=0;
lbl_8053AD1C[i]=0;
lbl_8053AD20[i]=0;
lbl_8053AD24[i]=0;
lbl_8053AD28[i]=0;
}
lbl_8053AD08=0;
return self;
}

// Shared JAudio pool __sinit (docs/game/sinit_pools.md).
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