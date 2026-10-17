// TU 0x80301cd0-0x803099fc.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// ---- Per-player game state (indexed by fn_8022F340(), the player slot) ----
extern "C" s32 fn_8022F340();
extern "C" s32 fn_8030AAF4(s32 i);
extern "C" u8 fn_8030A308(void* pad, s32 i);
extern void* lbl_8053AD30;
extern u8 lbl_8053ACD4[4];
extern u8 lbl_8053ACE0[4];
extern u8 lbl_8053ACE8[4];
extern u8 lbl_8053ACEC[4];
extern u8 lbl_8053ACF0[4];
struct Elem28_80301CD0 {
    Elem28_80301CD0();
    s32 f0;
    s32 f4;
    u8 pad8[4];
    s32 fc;
    u8 pad10[0x24 - 0x10];
    u8 f24;
    u8 f25;
    u8 pad26[2];
};
// This TU's .bss (0x804DBC18-0x805076E8), in retail order.
static u8 lbl_804DBC18[0x20000];
static u8 lbl_804FBC18[0x8E00];
static s32 lbl_80504A18[4];
static s32 lbl_80504A28[4];
static Elem28_80301CD0 lbl_80504A38[4][16];
static Elem28_80301CD0 lbl_80505438[4][40];
static u32 lbl_80506D38[4];
static u8 lbl_80506D48[0x40];
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

struct Slot_80301CD0 {
    u8 id;
    u8 f1;
    u8 f2;
    u8 type : 3;
    u8 pad3 : 2;
    u8 idHi : 2;
    u8 flag : 1;
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

extern "C" void fn_803068D0(Hdr_80301CD0* hdr) {
    if (hdr->count == 0) {
        return;
    }
    s32 side = hdr->side;
    Slot_80301CD0* base = (Slot_80301CD0*)(lbl_80506F88 + ((s32(*)(s32))fn_8022F340)(hdr->player) * 0x98);
    Slot_80301CD0* dst = base + side * 19;
    s32 kind = hdr->kind;
    u32* src = (u32*)hdr->slots;
    u32* out = (u32*)dst;
    s32 i;
    for (i = 0; i < *(kind + lbl_80541618) - 7; i++) {
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

// fn_80307AC8 - effect spawn dispatcher: ids below 0x45 go to the small
// effect table (fn_80307830), others to the generic effect spawner.
extern "C" s32 fn_80307830(u32 caller, s32 room, void* pos, s32 id, bool on, s32 a, bool b, s32 kind);
extern "C" s32 fn_803075AC(u32 caller, s32 room, void* pos, s32 id, bool on, s32 mode, s32 target, s32 kind,
                           bool b, s32 d);

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