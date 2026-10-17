// TU 0x8022461c-0x80226fc8.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"

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
extern char* lbl_8053AAF8;
extern const u16 lbl_8046CB88[];

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
    if (pos[0] >= r.x0 && pos[1] >= r.y0 && pos[0] < r.x1 && pos[1] < r.y1) {
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

static inline u16 tileAtOrdered(const f32* pos, u32 room) {
    u8* g = fn_802D6A9C();
    const TileRect r = *(TileRect*)(((s32)room < 8) ? g + 0xcc : g + 0xdc);
    u8 in = (pos[0] >= r.x0 && pos[1] >= r.y0 && pos[0] < r.x1 && pos[1] < r.y1);
    if (!in) return 0xf;
    s32 x = pos[0] - r.x0;
    s32 y = pos[1] - r.y0;
    if (x < 0) x = 0;
    else if (x >= 0x200) x = 0x1ff;
    if (y < 0) y = 0;
    else if (y >= 0x200) y = 0x1ff;
    return fn_802F9908(*(void**)(lbl_8053AB10 + 0x20), room,
        ((y & 0x100) << 1) | (x & 0x100) | (y & 0xf0) | ((x >> 4) & 0xf)) & 0x3ff;
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
    struct Lookup {
        static inline u16 get(const f32* pos, u32 room) {
    u8* g = fn_802D6A9C();
    const TileRect r = *(TileRect*)(((s32)room < 8) ? g + 0xcc : g + 0xdc);
    f32 x0;
    f32 px = pos[0];
    x0 = r.x0;
    u8 in = (px >= x0 && pos[1] >= r.y0 && px < r.x1 && pos[1] < r.y1);
    if (!in) {
        return 0xf;
    } else {
        s32 x = px - x0;
        s32 y = pos[1] - r.y0;
        if (x < 0) x = 0;
        else if (x >= 0x200) x = 0x1ff;
        if (y < 0) y = 0;
        else if (y >= 0x200) y = 0x1ff;
        return fn_802F9908(*(void**)(lbl_8053AB10 + 0x20), room,
            ((y & 0x100) << 1) | (x & 0x100) | (y & 0xf0) | ((x >> 4) & 0xf)) & 0x3ff;
    }
        }
    };
    u16 tile = Lookup::get(pos, room);
    if (room < 8 && fn_802D6A9C()[0x131f1] != 0) {
        if (tile == 0x1b0 || tile == 0x1bb) return TRUE;
    }
    return FALSE;
}

extern "C" BOOL fn_80224B88(f32* pos, s32 room) {
    struct Lookup {
        static inline u16 get(const f32* pos, u32 room) {
    u8* g = fn_802D6A9C();
    const TileRect r = *(TileRect*)(((s32)room < 8) ? g + 0xcc : g + 0xdc);
    f32 x0;
    f32 px = pos[0];
    x0 = r.x0;
    u8 in = (px >= x0 && pos[1] >= r.y0 && px < r.x1 && pos[1] < r.y1);
    if (!in) {
        return 0xf;
    } else {
        s32 x = px - x0;
        s32 y = pos[1] - r.y0;
        if (x < 0) x = 0;
        else if (x >= 0x200) x = 0x1ff;
        if (y < 0) y = 0;
        else if (y >= 0x200) y = 0x1ff;
        return fn_802F9908(*(void**)(lbl_8053AB10 + 0x20), room,
            ((y & 0x100) << 1) | (x & 0x100) | (y & 0xf0) | ((x >> 4) & 0xf)) & 0x3ff;
    }
        }
    };
    u16 tile = Lookup::get(pos, room);
    if (room < 8 && fn_802D6A9C()[0x131f1] != 0) {
        if (tile == 0x1b0 || tile == 0x1bb) return TRUE;
    }
    return FALSE;
}

extern const u16 lbl_8053FF48[2];
extern const u16 lbl_8053FF4C[2];

extern "C" BOOL fn_80224D0C(f32* pos, s32 room) {
    struct Lookup {
        static inline u16 get(const f32* pos, u32 room) {
    u8* g = fn_802D6A9C();
    const TileRect r = *(TileRect*)(((s32)room < 8) ? g + 0xcc : g + 0xdc);
    f32 x0;
    f32 px = pos[0];
    x0 = r.x0;
    u8 in = (px >= x0 && pos[1] >= r.y0 && px < r.x1 && pos[1] < r.y1);
    if (!in) {
        return 0xf;
    } else {
        s32 x = px - x0;
        s32 y = pos[1] - r.y0;
        if (x < 0) x = 0;
        else if (x >= 0x200) x = 0x1ff;
        if (y < 0) y = 0;
        else if (y >= 0x200) y = 0x1ff;
        return fn_802F9908(*(void**)(lbl_8053AB10 + 0x20), room,
            ((y & 0x100) << 1) | (x & 0x100) | (y & 0xf0) | ((x >> 4) & 0xf)) & 0x3ff;
    }
        }
    };
    u16 tile = Lookup::get(pos, room);
    for (s32 i = 0; i < 2; i++) {
        if (tile == lbl_8053FF4C[i]) return TRUE;
    }
    return FALSE;
}

extern "C" BOOL fn_80224E88(f32* pos, s32 room) {
    struct Lookup {
        static inline u16 get(const f32* pos, u32 room) {
            u8* g = fn_802D6A9C();
            const TileRect r = *(TileRect*)(((s32)room < 8) ? g + 0xcc : g + 0xdc);
            f32 x0 = r.x0;
            f32 px = pos[0];
            u32 tile;
            u8 in = (px >= x0 && pos[1] >= r.y0 && px < r.x1 && pos[1] < r.y1);
            if (!in) {
                tile = 0xf;
            } else {
                s32 x;
                s32 y;
                x = px - x0;
                y = pos[1] - r.y0;
                if (x < 0) x = 0;
                else if (x >= 0x200) x = 0x1ff;
                if (y < 0) y = 0;
                else if (y >= 0x200) y = 0x1ff;
                tile = fn_802F9908(*(void**)(lbl_8053AB10 + 0x20), room,
                    ((y & 0x100) << 1) | (x & 0x100) | (y & 0xf0) | ((x >> 4) & 0xf)) & 0x3ff;
            }
            return tile;
        }
    };
    u16 tt = Lookup::get(pos, room);
    BOOL r2 = FALSE;
    for (s32 i = 0; i < 2; i++) {
        if (tt == lbl_8053FF4C[i]) {
            r2 = TRUE;
            break;
        }
    }
    return r2;
}

extern "C" BOOL fn_80225000(f32* pos, s32 room) {
    struct Lookup {
        static inline u16 get(const f32* pos, u32 room) {
    u8* g = fn_802D6A9C();
    const TileRect r = *(TileRect*)(((s32)room < 8) ? g + 0xcc : g + 0xdc);
    f32 x0;
    f32 px = pos[0];
    x0 = r.x0;
    u8 in = (px >= x0 && pos[1] >= r.y0 && px < r.x1 && pos[1] < r.y1);
    if (!in) {
        return 0xf;
    } else {
        s32 x = px - x0;
        s32 y = pos[1] - r.y0;
        if (x < 0) x = 0;
        else if (x >= 0x200) x = 0x1ff;
        if (y < 0) y = 0;
        else if (y >= 0x200) y = 0x1ff;
        return fn_802F9908(*(void**)(lbl_8053AB10 + 0x20), room,
            ((y & 0x100) << 1) | (x & 0x100) | (y & 0xf0) | ((x >> 4) & 0xf)) & 0x3ff;
    }
        }
    };
    u16 tile = Lookup::get(pos, room);
    for (s32 i = 0; i < 2; i++) {
        if (tile == lbl_8053FF48[i]) return TRUE;
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
    struct Lookup {
        static inline u16 get(const f32* pos, u32 room) {
    u8* g = fn_802D6A9C();
    const TileRect r = *(TileRect*)(((s32)room < 8) ? g + 0xcc : g + 0xdc);
    f32 x0;
    f32 px = pos[0];
    x0 = r.x0;
    u8 in = (px >= x0 && pos[1] >= r.y0 && px < r.x1 && pos[1] < r.y1);
    if (!in) {
        return 0xf;
    } else {
        s32 x = px - x0;
        s32 y = pos[1] - r.y0;
        if (x < 0) x = 0;
        else if (x >= 0x200) x = 0x1ff;
        if (y < 0) y = 0;
        else if (y >= 0x200) y = 0x1ff;
        return fn_802F9908(*(void**)(lbl_8053AB10 + 0x20), room,
            ((y & 0x100) << 1) | (x & 0x100) | (y & 0xf0) | ((x >> 4) & 0xf)) & 0x3ff;
    }
        }
    };
    u16 tile = Lookup::get(pos, room);
    for (s32 i = 0; i < 0x5e; i++) {
        if (tile == lbl_8046AB2C[i]) {
            return TRUE;
        }
    }
    return FALSE;
}


extern "C" u32 fn_80226AE0(f32* pos, s32 room) {
    u8* g = fn_802D6A9C();
    TileRect r = *(TileRect*)((room < 8) ? g + 0xcc : g + 0xdc);
    s32 x = pos[0] - r.x0;
    s32 y = pos[1] - r.y0;
    if (x < 0) {
        x = 0;
    } else if (x >= 0x200) {
        x = 0x1ff;
    }
    if (y < 0) {
        y = 0;
    } else if (y >= 0x200) {
        y = 0x1ff;
    }
    return ((y & 0x100) << 1) | (x & 0x100) | (y & 0xf0) | ((x >> 4) & 0xf);
}

extern "C" u32 fn_80226BC4(f32* pos, s32 room) {
    u8* g = fn_802D6A9C();
    TileRect r = *(TileRect*)((room < 8) ? g + 0xcc : g + 0xdc);
    s32 x = pos[0] - r.x0;
    s32 y = pos[1] - r.y0;
    if (x < 0) {
        x = 0;
    } else if (x >= 0x200) {
        x = 0x1ff;
    }
    if (y < 0) {
        y = 0;
    } else if (y >= 0x200) {
        y = 0x1ff;
    }
    return ((y & 0x100) << 1) | (x & 0x100) | (y & 0xf0) | ((x >> 4) & 0xf);
}

extern "C" u16 fn_80226850(f32* pos, u32 room) {
    u8* g = fn_802D6A9C();
    const TileRect r = *(TileRect*)(((s32)room < 8) ? g + 0xcc : g + 0xdc);
    u8 in = 0;
    if (pos[0] >= r.x0 && pos[1] >= r.y0 && pos[0] < r.x1 && pos[1] < r.y1) {
        in = 1;
    }
    if (!in) {
        return 0xf;
    }
    s32 x = pos[0] - r.x0;
    s32 y = pos[1] - r.y0;
    if (x < 0) {
        x = 0;
    } else if (x >= 0x200) {
        x = 0x1ff;
    }
    if (y < 0) {
        y = 0;
    } else if (y >= 0x200) {
        y = 0x1ff;
    }
    return fn_802F9908(*(void**)(lbl_8053AB10 + 0x20), room, ((y & 0x100) << 1) | (x & 0x100) | (y & 0xf0) | ((x >> 4) & 0xf)) & 0x3ff;
}
extern "C" u16 fn_80226998(f32* pos, u32 room) {
    u8* g = fn_802D6A9C();
    TileRect r = *(TileRect*)(((s32)room < 8) ? g + 0xcc : g + 0xdc);
    u8 in = 0;
    if (pos[0] >= r.x0 && pos[1] >= r.y0 && pos[0] < r.x1 && pos[1] < r.y1) {
        in = 1;
    }
    if (!in) {
        return 0xf;
    }
    s32 x = pos[0] - r.x0;
    s32 y = pos[1] - r.y0;
    if (x < 0) {
        x = 0;
    } else if (x >= 0x200) {
        x = 0x1ff;
    }
    if (y < 0) {
        y = 0;
    } else if (y >= 0x200) {
        y = 0x1ff;
    }
    u32 idx = ((y & 0x100) << 1) | (x & 0x100) | (y & 0xf0) | ((x >> 4) & 0xf);
    return fn_802F9908(*(void**)(lbl_8053AB10 + 0x20), (s32)room, idx) & 0x3ff;
}

extern const f32 lbl_8053FF54;

extern "C" void fn_80226CA8(s32 idx, s32 room, JGeometry::TVec3<f32>* out) {
    JGeometry::TVec3<f32> v(*out);
    u8* g = fn_802D6A9C();
    TileRect* src = (TileRect*)((room < 8) ? g + 0xcc : g + 0xdc);
    s32 iy = ((idx >> 1) & 0x100) + (idx & 0xf0);
    s32 ix = (idx & 0x100) + (idx & 0xf) * 16;
    TileRect r = *src;
    v.x = (f32)ix + r.x0;
    v.y = (f32)iy + r.y0;
    v.z = lbl_8053FF54;
    *out = v;
}

extern const u16 lbl_8046AAB0[12];

extern "C" BOOL fn_80225EF4(f32* pos, s32 room) {
    struct Lookup {
        static inline u16 get(const f32* pos, u32 room) {
    u8* g = fn_802D6A9C();
    const TileRect r = *(TileRect*)(((s32)room < 8) ? g + 0xcc : g + 0xdc);
    f32 x0;
    f32 px = pos[0];
    x0 = r.x0;
    u8 in = (px >= x0 && pos[1] >= r.y0 && px < r.x1 && pos[1] < r.y1);
    if (!in) {
        return 0xf;
    } else {
        s32 x = px - x0;
        s32 y = pos[1] - r.y0;
        if (x < 0) x = 0;
        else if (x >= 0x200) x = 0x1ff;
        if (y < 0) y = 0;
        else if (y >= 0x200) y = 0x1ff;
        return fn_802F9908(*(void**)(lbl_8053AB10 + 0x20), room,
            ((y & 0x100) << 1) | (x & 0x100) | (y & 0xf0) | ((x >> 4) & 0xf)) & 0x3ff;
    }
        }
    };
    u16 tile = Lookup::get(pos, room);
    for (s32 i = 0; i < 12; i++) {
        if (tile == lbl_8046AAB0[i]) {
            return TRUE;
        }
    }
    return FALSE;
}

struct Tu8022G {
    u8 pad0[4];
    s32 f4;
    s32 f8;
    u8 padC[0x8];
    s32 f14;
    s32 f18;
};
extern const u16 lbl_8046CB88[0x400];
extern char* lbl_8053AAF8;
extern const f32 lbl_8053FF50;

#define TG() ((Tu8022G*)fn_802D6A9C())
extern "C" u16 fn_8022461C(f32* pos, u32 room) {
    u8* g = fn_802D6A9C();
    const TileRect r = *(TileRect*)(((s32)room < 8) ? g + 0xcc : g + 0xdc);
    f32 px = pos[0];
    f32 x0 = r.x0;
    u8 in = (px >= x0 && pos[1] >= r.y0 && px < r.x1 && pos[1] < r.y1);
    u16 tile;
    if (!in) {
        tile = 0xf;
    } else {
        s32 x = px - x0;
        s32 y = pos[1] - r.y0;
        if (x < 0) x = 0;
        else if (x >= 0x200) x = 0x1ff;
        if (y < 0) y = 0;
        else if (y >= 0x200) y = 0x1ff;
        tile = fn_802F9908(*(void**)(lbl_8053AB10 + 0x20), room,
            ((y & 0x100) << 1) | (x & 0x100) | (y & 0xf0) | ((x >> 4) & 0xf)) & 0x3ff;
    }
    u16 kind = lbl_8046CB88[tile];
    if (fn_802D6A9C()[room + 0x131df] != 0) {
        if (kind == 0) {
            return 2;
        } else if (kind == 0x61) {
            return 0;
        }
    } else if (kind == 0xe && lbl_8053AAF8[0x7f] != 0) {
        if ((TG()->f4 == 7 && TG()->f8 == 2) ||
            (TG()->f4 == 7 && TG()->f8 == 3 &&
             *((u8*)TG()->f14 + (s32)TG() + TG()->f18 * 10 + 0x60) == 0x10 &&
             pos[1] > lbl_8053FF50)) {
            return 0x51;
        }
    }
    return kind;
}
