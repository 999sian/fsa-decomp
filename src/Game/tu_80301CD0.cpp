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
extern s32 lbl_80504A18[4];
extern s32 lbl_80504A28[4];
extern u32 lbl_80506D38[4];

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
extern "C" void* fn_80309014(void* p, s16 how) {
    if (p != 0) {
        *(void**)p = lbl_804AA8B8;
        if (how > 0) {
            operator delete(p);
        }
    }
    return p;
}

