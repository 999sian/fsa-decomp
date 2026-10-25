// TU 0x80301cd0-0x803099fc.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"
#include "Game/ItemBase.h"

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
extern u8 lbl_8053ACD4[4];
extern u8 lbl_8053ACE0[4];
extern u8 lbl_8053ACE8[4];
extern u8 lbl_8053ACEC[4];
extern u8 lbl_8053ACF0[4];
extern u8 lbl_8053ACF4[4];
extern u8 lbl_8053ACF8[4];
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
static s32 lbl_80504A18[4];
static s32 lbl_80504A28[4];
static Elem28_80301CD0 lbl_80504A38[4][16];
static Elem28_80301CD0 lbl_80505438[4][40];
static u32 lbl_80506D38[4];
static u8 lbl_80506D48[0x30];
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
    s32 f108;
    s32 f10c;
    s32 f110;
    s32 f114;
    u8 f118;
    u8 f119;
    u8 f11a;
    u8 pad11b;
};

extern u8 lbl_8053AD20[4];
extern u8 lbl_80541618[4];

struct TextCall_80301CD0 {
    virtual void v00();
    virtual void v04();
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

static inline void tu80301_pushMeasured(s32 i, char* str, u32 color) {
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

struct Packet_80301CD0 {
    u8 checksum, f1, f2;
    u8 code : 4;
    u8 rest : 4;
};

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
extern "C" void fn_803022C4(u8* p, s32 player, u8 arg, u8 mode) {
    s32 order[4];
    order[0] = 0;
    order[1] = 1;
    order[2] = 2;
    order[3] = 3;
    s32* cur = order + 3;
    s32 mask = (p[1] >> 4) & 15;
    for (s32 n = 3; n > 0; --n) {
        s32* a = order;
        for (s32 j = n; j > 0; --j, ++a) {
            s32 x = a[0];
            s32 y = a[1];
            if (tu80301_rank(mask, player, x) < tu80301_rank(mask, player, y) ||
                (tu80301_rank(mask, player, x) == tu80301_rank(mask, player, y) &&
                 p[x * 4 + 9] < p[y * 4 + 9])) {
                a[0] = y;
                a[1] = x;
            }
        }
    }
    u8* base = lbl_80506F88 + player * 0x98;
    s32 left = 18;
    s32 right = 18;
    s32 count = 3;
    u8* a = base + 0x48;
    for (s32 i = 19; i > 0; --i) {
        if ((a[3] & 1U) != 1U || a[2] != 0x80) break;
        a -= 4;
        --left;
    }
    a = base + 0x48;
    for (s32 i = 19; i > 0; --i) {
        if ((a[0x4f] & 1U) != 1U || a[0x4e] != 0x80) break;
        a -= 4;
        --right;
    }
    if (((p[2] >> 2) & 7U) <= 1U) mode = 1;
    while (left >= 0 || right >= 0 || count >= 0) {
        s32 rank = count >= 0 ? tu80301_rank((p[1] >> 4) & 15, player, *cur) : 255;
        s32 lr = left >= 0 ? fn_803074A4(base[left * 4 + 3] >> 5 & 7, base[left * 4] | ((base[left * 4 + 3] & 6) << 7)) : 255;
        s32 rr = right >= 0 ? fn_803074A4(base[right * 4 + 0x4f] >> 5 & 7, base[right * 4 + 0x4c] | ((base[right * 4 + 0x4f] & 6) << 7)) : 255;
        if (right >= 0 &&
            (count < 0 || rr < rank || (rr == rank && p[*cur * 4 + 9] >= base[right * 4 + 0x4d])) &&
            (left < 0 || lr > rr || (lr == rr && base[left * 4 + 1] >= base[right * 4 + 0x4d]))) {
            if (rr >= 2) fn_80302F9C(base + right * 4 + 0x4c, arg, mode, lbl_80506D78[player]);
            --right;
            a = base + right * 4;
            for (; right >= 0; --right) {
                if ((a[0x4f] & 1U) != 1U || a[0x4e] != 0x80) break;
                a -= 4;
            }
        } else if (left >= 0 &&
            (count < 0 || lr < rank || (lr == rank && p[*cur * 4 + 9] >= base[left * 4 + 1]))) {
            if (lr >= 2) fn_80302F9C(base + left * 4, arg, mode, lbl_80506D78[player]);
            --left;
            a = base + left * 4;
            for (; left >= 0; --left) {
                if ((a[3] & 1U) != 1U || a[2] != 0x80) break;
                a -= 4;
            }
        } else {
            s32 index = *cur;
            s32 bits = (p[1] >> 4) & 15;
            if (tu80301_rank(bits, player, index) >= 2)
                fn_80302C34(p + index * 4 + 8, player, index, bits, arg);
            --cur;
            --count;
        }
    }
}

extern "C" void fn_80302F9C(u8* p, u8 a2, u8 a3, f32 ang) {
    const char* names;
    s32 id;
    f32 mtx[3][4];
    f32 pos[3];
    s32 x;
    s32 y;
    void* obj;
    void* res;
    f32 sx;
    f32 sy;
    f32 sz;
    f32 cx;
    f32 cy;
    f32 cz;
    f32 s;

    names = (const char*)lbl_80471208;
    x = p[2] | ((p[3] & 1) << 8);
    if (x == 0x180) {
        return;
    }
    if (p[1] == 0xe0) {
        return;
    }
    if (x >= 0x180) {
        x |= -0x100;
    }
    y = p[1];
    if (y >= 0xe0) {
        y |= -0x100;
    }
    pos[0] = (f32)x;
    pos[1] = (f32)y;
    pos[2] = 0.0f;

    DrawRec rec;
    id = p[0] | ((p[3] & 6) << 7);
    rec.b26 = 0;
    rec.b2c = 0;
    rec.b2d = 0;
    if (a2 == 0) {
        rec.w34 = 2;
        rec.b1f = 0;
        rec.w38 = 0;
    }

    if (((p[3] >> 5) & 7) == 2 && id >= 0x200) {
        id &= 0x1ff;
        if (((p[3] >> 4) & 1) == 1) {
            PSMTXScale(mtx, 2.0f, 2.0f, -2.0f);
        } else {
            PSMTXScale(mtx, 1.0f, 1.0f, -1.0f);
        }
    } else if (((p[3] >> 3) & 1) == 1) {
        PSMTXScale(mtx, 1.0f, 1.0f, 1.0f);
        if (((p[3] >> 4) & 1) == 1) {
            sx = sin(0.0f);
            sy = sin(ang);
            sz = sin(0.0f);
            cx = cos(0.0f);
            cy = cos(ang);
            cz = cos(0.0f);
            s = 1.5f;
            mtx[0][0] = s * (cy * cz);
            mtx[1][0] = s * (cy * sz);
            mtx[2][0] = s * -sy;
            mtx[0][1] = s * (sx * sy * cz - cx * sz);
            mtx[1][1] = s * (sx * sy * sz + cx * cz);
            mtx[2][1] = s * (sx * cy);
            mtx[0][2] = s * (cx * cz * sy + sx * sz);
            mtx[1][2] = s * (cx * sz * sy - sx * cz);
            mtx[2][2] = s * (cx * cy);
        } else {
            sx = sin(0.0f);
            sy = sin(ang);
            sz = sin(0.0f);
            cx = cos(0.0f);
            cy = cos(ang);
            cz = cos(0.0f);
            s = 0.75f;
            mtx[0][0] = s * (cy * cz);
            mtx[1][0] = s * (cy * sz);
            mtx[2][0] = s * -sy;
            mtx[0][1] = s * (sx * sy * cz - cx * sz);
            mtx[1][1] = s * (sx * sy * sz + cx * cz);
            mtx[2][1] = s * (sx * cy);
            mtx[0][2] = s * (cx * cz * sy + sx * sz);
            mtx[1][2] = s * (cx * sz * sy - sx * cz);
            mtx[2][2] = s * (cx * cy);
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
        if (((p[3] >> 4) & 1) == 1 || (((p[3] >> 5) & 7) == 2 && id >= 0x39 && id < 0x45)) {
            PSMTXScale(mtx, 2.0f, 2.0f, 2.0f);
        } else {
            PSMTXScale(mtx, 1.0f, 1.0f, 1.0f);
        }
    }

    rec.w18 = mtx;
    rec.b1e = a3 != 0 ? 2 : 1;

    if (((p[3] >> 5) & 7) < 2) {
        if ((id >= 0x37 && id < 0x41) || id == 0x3cd) {
            ((u8*)&rec.w10)[3] = 0xa0;
        } else if (id == 0x2a8 || id == 0x2a9) {
            id -= 3;
        }
        obj = *(void**)((u8*)lbl_8053AAF8 + 0xa4);
        res = ((void* (*)(void*, u32, const char*))(*(void***)obj)[6])(obj, 0x534F4220, names + 0x10);
        fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), pos, res, id, 1.0f, 1.0f, &rec);
        return;
    }
    if (((p[3] >> 5) & 7) == 2) {
        obj = *(void**)((u8*)lbl_8053AAF8 + 0xa4);
        res = ((void* (*)(void*, u32, const char*))(*(void***)obj)[6])(obj, 0x534F4220, names + 0x24);
        fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), pos, res, id, 1.0f, 1.0f, &rec);
        return;
    }
    if (((p[3] >> 5) & 7) & 4) {
        rec.ids[7] = (((p[3] >> 5) & 7) & 3) + 0xc;
    }
    obj = *(void**)((u8*)lbl_8053AAF8 + 0xa4);
    res = ((void* (*)(void*, u32, const char*))(*(void***)obj)[6])(obj, 0x534F4220, names);
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
extern "C" char* fn_802D9C4C();
extern "C" char* fn_802D9C1C();
extern "C" u8 fn_80304C10(s32 i, char* str, u32 color, u8 b, s32 id);
extern u8 lbl_80471208[];
extern u8 lbl_8053ACE4[4];
extern "C" void fn_80303870(s32 i) {
    char buf28[0x20];
    char buf8[0x20];
    char* str;
    char* base = (char*)lbl_80471208;

    fn_802D6A9C();
    str = fn_802D9C4C();
    if (str[0] != 'c') {
        sprintf(buf28, base + 0x38, str);
        tu80301_pushMeasured(i, buf28, 0x6000000);
    } else {
        tu80301_pushMeasured(i, base + 0x48, 0x6000000);
    }
    sprintf(buf8, base + 0x58, str);
    tu80301_pushMeasured(i, buf8, 0x5000001);
    fn_802D6A9C();
    sprintf(buf28, base + 0x6c, fn_802D9C1C());
    tu80301_pushMeasured(i, buf28, 0x6017000);
    lbl_8053ACE4[i] = 1;
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

extern "C" void fn_80304D64() {
    for (s32 i = 0; i < 4; i++) {
        for (int j = 0; j < 16; j++) {
            if (lbl_80504A38[i][j].f25 == 1) {
                lbl_80504A38[i][j].f24 = 0;
                lbl_80504A38[i][j].f25 = 0;
                lbl_80504A38[i][j].f4 = -1;
            } else if (lbl_80504A38[i][j].f24 == 1 && lbl_80504A38[i][j].f0 < 5) {
                lbl_80504A38[i][j].f0++;
            }
        }
        for (int j = 0; j < 40; j++) {
            if (lbl_80505438[i][j].f25 == 1 && lbl_80505438[i][j].f0 == 0) {
                lbl_80505438[i][j].f24 = 0;
                lbl_80505438[i][j].f25 = 0;
                lbl_80505438[i][j].f4 = -1;
                lbl_80505438[i][j].fc = -1;
            } else if (lbl_80505438[i][j].f25 == 1) {
                lbl_80505438[i][j].fc = -1;
                lbl_80505438[i][j].f0 = 0;
            } else if (lbl_80505438[i][j].f24 == 1 && lbl_80505438[i][j].f0 < 5) {
                lbl_80505438[i][j].f0++;
            }
        }
    }
}

extern "C" void fn_803064A8(void* p, s32 player, s32 count, s32 start) {
    s32 idx = start;
    if (count == 0) {
        return;
    }
    s32 slot = fn_8022EA0C(player);
    u8* o = lbl_80506DE8 + player * 0x68 + start * 4;
    for (s32 prio = 5; prio > 0; prio--) {
        u8* q = o;
        Elem28_80301CD0* e = lbl_80505438[player];
        for (s32 j = 0; j < 40; j++, e++) {
            if (e->f24 == 0) {
                continue;
            }
            s32 t = fn_8023DE58(slot);
            if ((e->f8 != t && e->fc != player) || (*(s32*)((u8*)lbl_8053AAF8 + 0x4c) == 0xb && e->f23 == 0)) {
                e->f0 = 0;
                e->f25 = 1;
                continue;
            }
            if (e->f0 != prio && e->fc != player) {
                continue;
            }
            if (e->fc >= 0) {
                q[0x1b] = ((((int)e->f10) >> 8) & 1) | (q[0x1b] & 0xfe);
                q[0x1a] = (int)e->f10;
                q[0x19] = (int)e->f14;
            } else {
                u32 r21 = fn_8023D9B0(&e->f10, slot) & 0x1ff;
                u8 c = fn_8023D4F8(&e->f10, slot);
                if (r21 == 0x180 || c == 0xe0) {
                    e->f0 = 0;
                    e->f25 = 1;
                    continue;
                }
                q[0x1b] = ((r21 >> 8) & 1) | (q[0x1b] & 0xfe);
                q[0x1a] = r21;
                q[0x19] = c;
            }
            s32 v = e->f1c;
            if (v > 0x3ff) {
                v -= 0x400;
                q[0x1b] = ((((v >> 8) & 3) << 1)) | (q[0x1b] & 0xf9);
                q[0x18] = v;
                q[0x1b] = (q[0x1b] & 0x1f) | 0x40;
            } else {
                q[0x1b] = ((((v >> 8) & 0xff) << 1) & 6) | (q[0x1b] & 0xf9);
                q[0x18] = v;
                q[0x1b] = (e->f20 << 5) | (q[0x1b] & 0x1f);
            }
            q[0x1b] = ((e->f21 & 1) << 4) | (q[0x1b] & 0xef);
            q[0x1b] = ((e->f22 & 1) << 3) | (q[0x1b] & 0xf7);
            e->f25 = 1;
            o += 4;
            q += 4;
            idx++;
            if (count <= idx) {
                return;
            }
        }
    }
}

extern u8 lbl_80506DE8[];
extern "C" s32 fn_8022EA0C(s32);
extern "C" s32 fn_8023DE58(s32);
extern "C" u32 fn_8023D9B0(void*, s32);
extern "C" u8 fn_8023D4F8(void*, s32);
extern "C" s32 fn_803066F0(void* p, s32 idx, s32 max) {
    s32 count = 0;
    s32 big = 0;
    Out_803066F0* out = (Out_803066F0*)(lbl_80506DE8 + idx * 0x68 + 0x18);
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
            if (((u8)(*(s32*)(g + 0x4c) == 11) || g[0x88] != 0) && e->f23 == 0) {
                e->f25 = 1;
                continue;
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
            count++;
            out->hi = (u8)(v >> 8);
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
    s32 i;
    for (i = 0; i < lbl_80541618[kind] - 7; i++) {
        *out++ = *src++;
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

extern "C" s32 fn_803075AC(s32 caller, s32 room, void* pos, s32 id, bool on, s32 mode, s32 target, u8 kind, bool b, u8 d) {
    s32 ok = 0;
    s32 i;
    s32 n;
    s32 c;
    Elem28_80301CD0* base;
    Elem28_80301CD0* e;

    if (room < 8 && room != -1) {
        return 0;
    }
    for (i = 0; i < 4; i++) {
        s32 r = fn_8022EA0C(i);
        if (((*((u8*)lbl_8053AAF8 + 0x82)) & (u8)(1 << i)) == 0) {
            continue;
        }
        if (target != i && (target >= 0 || fn_8023DE58(r) != room)) {
            continue;
        }
        base = lbl_80505438[i];
        e = base;
        n = 0;
        c = 5;
        do {
            if (e->f24 == 1 && e->f4 == caller) break;
            n++;
            e++;
            if (e->f24 == 1 && e->f4 == caller) break;
            n++;
            e++;
            if (e->f24 == 1 && e->f4 == caller) break;
            n++;
            e++;
            if (e->f24 == 1 && e->f4 == caller) break;
            n++;
            e++;
            if (e->f24 == 1 && e->f4 == caller) break;
            n++;
            e++;
            if (e->f24 == 1 && e->f4 == caller) break;
            n++;
            e++;
            if (e->f24 == 1 && e->f4 == caller) break;
            n++;
            e++;
            if (e->f24 == 1 && e->f4 == caller) break;
            n++;
            e++;
        } while (--c != 0);
        if (n < 40) {
            e->f8 = room;
            *(struct Vec*)&e->f10 = *(struct Vec*)pos;
            ok = 1;
            e->f1c = id;
            e->f21 = on;
            e->f22 = b;
        } else {
            e = base;
            for (c = 0x28; c != 0; c--) {
                if (e->f24 == 0) {
                    e->f0 = mode;
                    e->f4 = caller;
                    e->f8 = room;
                    e->fc = target;
                    *(struct Vec*)&e->f10 = *(struct Vec*)pos;
                    ok = 1;
                    e->f1c = id;
                    e->f21 = on;
                    e->f20 = kind;
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

// fn_80307AC8 - effect spawn dispatcher: ids below 0x45 go to the small
// effect table (fn_80307830), others to the generic effect spawner.
extern "C" s32 fn_80307830(u32 caller, s32 room, void* pos, s32 id, bool on, s32 a, bool b, s32 kind);


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
void fn_803085A4(s32, s32);
extern "C" void fn_80307B58(s32 unused, s32 player, u8 flag) {
    if (flag) {
        u8* rec = lbl_80506DE8 + player * 0x68;
        rec[3] = (rec[3] & 15) | 0xa0;
    } else {
        u8* rec = lbl_80506DE8 + player * 0x68;
        rec[3] = (rec[3] & 15) | 0xb0;
    }
    fn_803085A4(unused, player);
    s32 max = (lbl_80541618[lbl_8053AD08] - 2) * 2;
    s32 start = lbl_8053AD0C[player];
    u16* data = (u16*)(lbl_805071E8 + player * 0x100);
    s32 i;
    for (i = 0; i < max; ++i) {
        data[start + i] = fn_8037F0CC(player);
        if (fn_8037F1E4(player) != 3) {
            u8* rec = lbl_80506DE8 + player * 0x68;
            u8 code = (rec[3] & 15) | 0xc0;
            lbl_8053AD24[player] = 1;
            ++i;
            lbl_8053AD1C[player] = 0;
            rec[3] = code;
            break;
        }
    }
    lbl_8053AD0C[player] += i;
    for (; i < max; ++i) {
        ((u16*)(lbl_805071E8 + player * 0x100))[start + i] = 0;
    }
    u8* rec = lbl_80506DE8 + player * 0x68;
    u32* dst = (u32*)(rec + 8);
    s32 n = lbl_80541618[lbl_8053AD08] - 2;
    s32 j = start;
    for (s32 k = n; k > 0; --k) {
        u16* src = (u16*)(lbl_805071E8 + player * 0x100) + j;
        u32 word = src[0] | ((u32)src[1] << 16);
        Slot_80301CD0 out;
        u8* bytes = (u8*)&word;
        out.id = bytes[3];
        out.f1 = bytes[2];
        out.f2 = bytes[1];
        ((u8*)&out)[3] = bytes[0];
        *dst++ = *(u32*)&out;
        j += 2;
    }
    u32 sum = 0;
    MsgEntry_80301CD0* e = &((MsgEntry_80301CD0*)(lbl_804FBC18 + player * 0x2380))[lbl_80504A18[player]];
    if (e->f118 == 0) {
        u8* p = rec + 8;
        for (s32 b = 8; b < lbl_80541618[lbl_8053AD08] * 4; ++b) sum += *p++;
    } else {
        u8* p = rec + 8;
        for (s32 b = 8; b < lbl_80541618[lbl_8053AD08] * 4; ++b) sum += *p++;
    }
    rec[0] = sum;
}

extern "C" void fn_803085A4(s32 unused, s32 i)
{
    s32 r25;
    s32 r26;
    s32 c;
    s32 lbl;
    s32 x;
    s32 t;
    u8* e;
    u8* g;
    u8* h;
    u8* p2;
    u8* p3;
    u8* p4;
    u8* p5;
    u8* p6;

    r25 = fn_8022EA0C(i);
    e = lbl_80506DE8 + i * 0x68;
    p2 = e + 2;
    p3 = e + 3;
    p3[0] = (p3[0] & 0xFC) | (lbl_8053AD08 & 3);
    p2[0] = (p2[0] & 0xFC) | (r25 & 3);
    if (fn_8023DE58(r25) < 8) {
        p2[0] &= 0xE3;
    } else {
        p2[0] = (p2[0] & 0xE3) | (((fn_8023DE58(r25) - 7) << 2) & 0x1C);
    }
    p2[0] = (p2[0] & 0x3F) | ((lbl_80506D48[i] & 3) << 6);

    g = (u8*)lbl_8053AAF8;
    if (lbl_8053ACD0 != 0 && (g[0x82] & (u8)(1 << i)) != 0) {
        if (*(s32*)(g + 0x4c) == 9 || g[0x80] != 0) {
            p2[0] |= 0x20;
        } else if (lbl_8053ACD8[i] == 0) {
            p2[0] &= 0xDF;
        } else if (fn_8037F1E4(i) < 1) {
            p2[0] |= 0x20;
        } else if (fn_8037F1E4(i) > 5) {
            p2[0] |= 0x20;
        } else {
            p2[0] &= 0xDF;
        }
        t = lbl_8053ACEC[i] > 1 ? lbl_8053ACE8[i] : 0;
        p3[0] = (p3[0] & 0xF3) | ((t << 2) & 0x0C);
    } else {
        p2[0] |= 0x20;
        p3[0] &= 0xF3;
    }

    p4 = e + 4;
    e[1] = 0;
    e[1] |= lbl_8053ACF8[0];
    e[1] |= lbl_8053ACF8[1] << 1;
    e[1] |= lbl_8053ACF8[2] << 2;
    e[1] |= lbl_8053ACF8[3] << 3;
    *(s32*)(e + 4) = 0;
    lbl = lbl_80506D48[i];
    p5 = e + 5;
    p6 = e + 6;
    if (lbl == 1) {
        p5[0] = (p5[0] & 0x0F) | 0xF0;
    }
    if (((u8*)lbl_8053AAF0)[0x78] < 4 || (g[0x82] & (u8)(1 << i)) == 0) {
        goto end;
    }
    p4[0] = (p4[0] & 0xE0) | (lbl_80506D38[i] & 0x1F);
    lbl_80506D38[i] = 0;
    if (lbl_8053ACD0 == 0 && !fn_80379F84(lbl_8053AD68)) {
        goto chain2;
    }
    if ((lbl & 1) == 0) {
        p5[0] = (p5[0] & 0x80) | (*(s32*)((u8*)lbl_80529DEC + 0xd8 + i * 4) & 0x7F);
        p4[0] = (p4[0] & 0x1F) | ((((*(s32*)((u8*)lbl_80529DEC + 0xc8 + i * 4)) / 4 - 1) << 5) & 0xE0);
        p6[0] = (p6[0] & 0xFC) | (fn_8037EE8C(i) & 3);
        x = *(s32*)((u8*)lbl_80529DEC + 0xe8 + i * 4) + 5000;
        if (x > 14999) {
            x = 14999;
        } else if (x < 0) {
            x = 0;
        }
        e[7] = (x >> 6) & 0xFF;
        p6[0] = (p6[0] & 0x03) | ((x & 0x3F) << 2);
    } else if (lbl == 1) {
        h = (u8*)lbl_8053AEC8;
        c = 0;
        if (h != NULL) {
            if (h[0x40] == 1 || (u8)(h[0x40] - 3) <= 1 || h[0x40] == 6) {
                c = 1;
            }
        }
        p4[0] = (p4[0] & 0x9F) | ((((g[0x88] | (c << 1) | (*(s32*)(g + 0x4c) == 0xb))) << 5) & 0x60);
        p5[0] = (p5[0] & 0x0F) | ((*(s32*)((u8*)lbl_80529DEC + 0xf8 + i * 4) << 4) & 0xF0);
    }

chain2:
    if (lbl_8053ACD0 != 0) {
        if (lbl_80506D48[i] == 2) {
            r25 = fn_8023DE58(r25);
            c = fn_802D7804(fn_802D6A9C(), r25, 1);
            p5[0] = (p5[0] & 0x7F) | (c << 7);
            goto tail;
        } else if ((lbl_80506D48[i] & 1) == 1) {
            if (fn_8023DE58(r25) >= 8) {
                if (*(s32*)(g + 0x4c) != 0xb && g[0x88] != 2) {
                    if (fn_8023BC38(r25) > 0) {
                        r26 = (fn_8023BC38(r25) + 59) / 60;
                        if (r26 > 11) {
                            r26 = 11;
                        }
                        r26 += 20;
                    } else if (fn_80236768(r25) > 0) {
                        r26 = (fn_80236768(r25) + 59) / 60;
                        if (r26 > 20) {
                            r26 = 20;
                        }
                    } else if (fn_80236630(r25) > 0) {
                        r26 = (fn_80236630(r25) + 59) / 60;
                        if (r26 > 20) {
                            r26 = 20;
                        }
                    } else if (fn_802366CC(r25) > 0) {
                        r26 = (fn_802366CC(r25) + 59) / 60;
                        if (r26 > 20) {
                            r26 = 20;
                        }
                    } else {
                        r26 = (*(s32*)((u8*)fn_802D6A9C() + 0xc4) + 59) / 60;
                        if (*((u8*)fn_802D6A9C() + 0x131f0) == 0 || r26 > 5) {
                            r26 = 0;
                        }
                        if (r26 > 20) {
                            r26 = 20;
                        }
                    }
                    p4[0] = (p4[0] & 0x7F) | ((r26 & 1) << 7);
                    p5[0] = (p5[0] & 0xF0) | ((r26 >> 1) & 0x0F);
                }
            }
            if (lbl_80506D48[i] == 3) {
                r26 = fn_8023DE58(r25);
                c = fn_802D7804(fn_802D6A9C(), r26, 0xc);
                if (c != 0) {
                    r26 = fn_8023DE58(r25);
                    p5[0] = (p5[0] & 0xCF) | ((*(u16*)((u8*)fn_802D6A9C() + 0x131b8 + r26 * 2) << 2) & 0x30);
                } else {
                    p5[0] = (p5[0] & 0xCF) | ((fn_802351D8(r25) != 0) << 4);
                }
                r25 = fn_8023DE58(r25);
                p4[0] = (p4[0] & 0x9F) | ((*(u16*)((u8*)fn_802D6A9C() + 0x131b8 + r25 * 2) >> 7) & 0x60);
                c = fn_80237060(i) - 1;
                p5[0] = (p5[0] & 0xBF) | ((c & 1) << 6);
                if (!fn_802DEBF8() && !fn_802DEBA0()) {
                    p5[0] |= 0x80;
                }
            }
        }
    }

tail:
    if (fn_80379F84(lbl_8053AD68)) {
        if (lbl_80506D48[i] == 0) {
            p5[0] |= 0x80;
        } else if (lbl_80506D48[i] == 3) {
            p5[0] |= 0x80;
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

extern "C" void* fn_80309014(void* p, s16 how) {
    if (p != 0) {
        *(void**)p = lbl_804AA8B8;
        if (how > 0) {
            operator delete(p);
        }
    }
    return p;
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