// TU 0x8022461c-0x80226fc8.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"

// ---- fn_802265DC.cpp ----
// fn_802265DC - trivial thin wrapper: tail-calls not-yet-seen fn_802260DC
// with its arguments unchanged and returns its result. Sibling of
// fn_801CE800's fn_802265FC (extab_801ce800.s) - both sit in the same
// 0x80226xxx cluster.
extern "C" s32 fn_802260DC(void* this_);
extern "C" s32 fn_802252F4(void* this_);

extern "C" s32 fn_802255F4(void* this_) {
    return fn_802252F4(this_);
}


extern "C" s32 fn_802265DC(void* this_) {
    return fn_802260DC(this_);
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"

struct TileRect { f32 x0, y0, x1, y1; };
extern "C" u8* fn_802D6A9C(void);
extern "C" u16 fn_802F9908(void* mgr, s32 room, s32 idx);
extern char* lbl_8053AB10;

static inline s32 tileClamp(s32 v) {
    if (v < 0) {
        v = 0;
    } else if (v >= 0x200) {
        v = 0x1ff;
    }
    return v;
}

static inline u8 tileInRect(const TileRect& r, const f32* pos) {
    u8 in = 0;
    if (r.x0 <= pos[0] && r.y0 <= pos[1] && pos[0] < r.x1 && pos[1] < r.y1) {
        in = 1;
    }
    return in;
}

static inline s32 tileClampI(s32 v) {
    if (v < 0) {
        v = 0;
    } else if (v >= 0x200) {
        v = 0x1ff;
    }
    return v;
}

static inline u16 tileRead(s32 room, s32 x, s32 y) {
    return fn_802F9908(*(void**)(lbl_8053AB10 + 0x20), room,
                       (x & 0x100) | ((y << 1) & 0x200) | (y & 0xf0) | ((x >> 4) & 0xf)) & 0x3ff;
}

static inline u16 tileAt(const f32* pos, u32 room) {
    u8* g = fn_802D6A9C();
    TileRect r = *(TileRect*)(((s32)room < 8) ? g + 0xcc : g + 0xdc);
    if (!tileInRect(r, pos)) {
        return 0xf;
    }
    s32 x = pos[0] - r.x0;
    s32 y = pos[1] - r.y0;
    return tileRead(room, tileClampI(x), tileClampI(y));
}

extern "C" BOOL fn_80224A04(f32* pos, s32 room) {
    u16 tile = tileAt(pos, room);
    if (room < 8 && fn_802D6A9C()[0x131f1] != 0) {
        if (tile == 0x1b0 || tile == 0x1bb) {
            return TRUE;
        }
    }
    return FALSE;
}

extern "C" BOOL fn_80224B88(f32* pos, s32 room) {
    u16 tile = tileAt(pos, room);
    if (room < 8 && fn_802D6A9C()[0x131f1] != 0) {
        if (tile == 0x1b0 || tile == 0x1bb) {
            return TRUE;
        }
    }
    return FALSE;
}

extern const u16 lbl_8053FF48[2];
extern const u16 lbl_8053FF4C[2];

extern "C" BOOL fn_80224D0C(f32* pos, s32 room) {
    u16 tile = tileAt(pos, room);
    for (s32 i = 0; i < 2; i++) {
        if (tile == lbl_8053FF4C[i]) {
            return TRUE;
        }
    }
    return FALSE;
}

extern "C" BOOL fn_80224E88(f32* pos, s32 room) {
    u16 tile = tileAt(pos, room);
    BOOL r = FALSE;
    for (s32 i = 0; i < 2; i++) {
        if (tile == lbl_8053FF4C[i]) {
            r = TRUE;
            break;
        }
    }
    return r;
}

extern "C" BOOL fn_80225000(f32* pos, s32 room) {
    u16 tile = tileAt(pos, room);
    for (s32 i = 0; i < 2; i++) {
        if (tile == lbl_8053FF48[i]) {
            return TRUE;
        }
    }
    return FALSE;
}

extern "C" BOOL fn_8022517C(f32* pos, s32 room) {
    u16 tile = tileAt(pos, room);
    BOOL r = FALSE;
    for (s32 i = 0; i < 2; i++) {
        if (tile == lbl_8053FF48[i]) {
            r = TRUE;
            break;
        }
    }
    return r;
}

extern const u16 lbl_8046AB2C[0x5e];

extern "C" BOOL fn_8022486C(f32* pos, s32 room) {
    u16 tile = tileAt(pos, room);
    for (s32 i = 0; i < 0x5e; i++) {
        if (tile == lbl_8046AB2C[i]) {
            return TRUE;
        }
    }
    return FALSE;
}
