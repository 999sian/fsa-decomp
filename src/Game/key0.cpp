// TU 0x802c1614-0x802c5950 (actor KEY0).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"
#include "Game/ItemBase.h"

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
#include "JSystem/JGeometry/Vec.h"

extern const f32 lbl_80540C74;
extern const f32 lbl_80540C8C;
extern const f32 lbl_80540C98;
extern const f32 lbl_80540C9C;
extern const f32 lbl_80540CA0;
extern const f32 lbl_80540CA4;
extern const f32 lbl_80540CA8;
extern const f32 lbl_80540C84;
extern const f32 lbl_80540C88;
extern f32 lbl_80540C80;
extern const f32 lbl_80540C94;
extern "C" void* fn_801F856C();
extern "C" BOOL fn_802C2684(void* unused, u8* p, f32* rect);

// ---- fn_802C1614_dtor.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804A8CD8[];

extern "C" void* fn_802C1614(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A8CD8;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// KEY0: register this key's tile with the room config.
struct Key0Pt {
    f32 x, y;
    Key0Pt(f32 x_, f32 y_) { x = x_; y = y_; }
};
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D6C10(void* rec, Key0Pt pt, u32 id);

static inline void key0Register(char* p) {
    u32 id = *(u32*)(p + 0x238);
    fn_802D6C10(fn_802D6A9C(), Key0Pt(*(f32*)(p + 0x230), *(f32*)(p + 0x234)), id);
}

// fn_802C18BC - KEY0: can the key be dropped at pos?
extern "C" u8* fn_8020D58C();
extern "C" u8 fn_8020D6AC(void* slot, s32 room, void* pos, u32 id, void* ext);
extern "C" u8 fn_802C1970(char* p, s32 room, void* pos);
// fn_802C1674 / fn_802C1778 - KEY0: drop the key and record where it went.
// NONMATCHING (~87%): retail builds both points in temporaries (0x18/0x20)
// and copies them to the argument slots; packed-id scheduling differs.
extern "C" void fn_802D6D70(void* rec, Key0Pt a, Key0Pt b, u32 packed, u32 id);
extern "C" u8 fn_8022F478(s32 player);
extern "C" s32 fn_8023EF50(s32 player);

static inline void key0RecordDrop(char* p) {
    u32 packed = (*(u32*)(p + 0x23c) << 30) | (*(u8*)(p + 0x2b5) << 29) |
                 ((*(u32*)(p + 0x280) << 24) & 0x1f000000) | ((*(u16*)(p + 0x2a8) << 8) & 0xffff00) |
                 (*(u32*)(p + 0x4) & 0xff);
    Key0Pt key(*(f32*)(p + 0x230), *(f32*)(p + 0x234));
    Key0Pt pos(*(f32*)(p + 0xc), *(f32*)(p + 0x10));
    u32 id = *(u32*)(p + 0x238);
    fn_802D6D70(fn_802D6A9C(), pos, key, packed, id);
}

extern "C" void fn_802C1674(char* p) {
    if (*(s32*)(p + 0x240) == 4 && *(u8*)(p + 0xc4) == 0) {
        if (*(u8*)(p + 0x2af) != 0) {
            if (*(u16*)(p + 0x2a8) != 0xffff) {
                key0RecordDrop(p);
                *(u16*)(p + 0x2a8) = 0xffff;
                *(u8*)(p + 0x2af) = 0;
            }
        }
    }
}

extern "C" void fn_802C1778(char* p) {
    if (*(s32*)(p + 0x4) < 8) {
        return;
    }
    if (*(u16*)(p + 0x2a8) == 0xffff) {
        return;
    }
    if (fn_8022F478(*(s32*)(p + 0x23c)) == 1) {
        s32 me = *(s32*)(p + 0x198);
        if (fn_8023EF50(*(s32*)(p + 0x23c)) == me) {
        } else {
            return;
        }
    } else if (fn_8022F478(*(s32*)(p + 0xd0)) == 1 && *(s32*)(p + 0x240) == 10) {
        if (*(u8*)(p + 0xcc) != 0) {
        } else {
            return;
        }
    } else {
        return;
    }
    key0RecordDrop(p);
    *(u16*)(p + 0x2a8) = 0xffff;
}

extern "C" u8 fn_802C18BC(char* p, s32 room, void* pos) {
    if (*(s32*)(p + 0x288) == 0) {
        u32 id = *(u32*)(p + 0x198);
        u8* mgr = fn_8020D58C();
        if (fn_8020D6AC(mgr + 4 + mgr[1] * 0x784, room, pos, id, 0)) {
            return 1;
        }
        return fn_802C1970(p, room, pos);
    }
    *(s32*)(p + 0x288) = *(s32*)(p + 0x288) - 1;
    return 0;
}

// fn_802C1D30 - KEY0: store the target position and remember the current room pair.
extern "C" void fn_802C1D30(char* p, const JGeometry::TVec3<f32>* pos, s32 v) {
    *(JGeometry::TVec3<f32>*)(p + 0x260) = *pos;
    *(s32*)(p + 0x26c) = v;
    u32 lo = *(u32*)((char*)fn_802D6A9C() + 0x18);
    u32 hi = *(u32*)((char*)fn_802D6A9C() + 0x14);
    *(u16*)(p + 0x2aa) = ((u8)hi << 8) | (u8)lo;
}

extern "C" void fn_802C1D90(char* p) {
    key0Register(p);
    *(u8*)(p + 0x11c) = 0;
}

// fn_802C1DFC - KEY0: collected. Spawns the pickup effect, registers the
// tile and deactivates.
extern "C" void* fn_801F856C();
extern "C" s32 Actor_CreateByID(void* base, u32 fourCC, u32 owner, void* posPtr, u32 param, s32 p6, s32 p7);
extern "C" void fn_8013CC50(s32 room, void* pos, f32 scale, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern const f32 lbl_80540C7C;
extern "C" void fn_802C1DFC(char* p) {
    s32 room = *(s32*)(p + 0x4);
    if (room >= 8) {
        Actor_CreateByID(fn_801F856C(), 0x4b4d5249, room, p + 0xc, 0, -1, -1);
    } else {
        fn_8013CC50(room, p + 0xc, lbl_80540C7C, 0x503, 1, 0, 0, 0, 1);
    }
    key0Register(p);
    *(u8*)(p + 0x11c) = 0;
}

extern "C" void fn_801F02BC(void* p, void* lbl, s32 idx, DrawRec* rec, s32 n, s32 zero, u8 flag, f32 a, f32 b);
extern "C" s32 fn_8023CB24(s32 id);
extern "C" s32 fn_8023CA88(s32 id);
extern char lbl_8046D580[];
extern "C" void fn_802C1EC4(char* p) {
    if (*(s32*)(p + 0x27c) != 8 && *(u8*)(p + 0x2b4) != 0 && *(s32*)(p + 0x280) < 0x10 && *(s32*)(p + 0x240) >= 2) {
        DrawRec rec;
        ((u8*)&rec.w10)[3] = *(u8*)(p + 0x2ad);
        s32 st = *(s32*)(p + 0x294);
        if (st >= 0x2bd4) {
            if (st & 2) {
                ((u8*)&rec.w10)[3] = 0;
            }
        } else if (st >= 0x2b20) {
            if (st & 4) {
                ((u8*)&rec.w10)[3] = 0;
            }
        } else if (st >= 0x2aa8) {
            if (st & 8) {
                ((u8*)&rec.w10)[3] = 0;
            }
        } else if (st >= 0x2a30) {
            if (st & 0x10) {
                ((u8*)&rec.w10)[3] = 0;
            }
        }
        if (*(u8*)(p + 0xc4) != 0) {
            rec.b20 = 0;
            rec.b1d = fn_8023CB24(*(s32*)(p + 0xc8)) + 1;
            rec.b1c = fn_8023CA88(*(s32*)(p + 0xc8));
        } else {
            rec.b1c = *(u8*)(p + 0x2ac);
        }
        s32 iVar2 = *(s32*)(p + 0x280);
        if (*(s8*)(p + 0x2ac) != 0) {
            iVar2 += 10;
        }
        rec.b2d = 1;
        u8 c4 = *(u8*)(p + 0xc4);
        s32 flag = c4;
        if (*(s32*)(p + 0x240) == 7 || *(s32*)(p + 0x240) == 10 || (*(s32*)(p + 0x27c) == 2 && c4 == 0)) {
            flag = 1;
            rec.b1d = 7;
        }
        s32 n = 7;
        if (*(u8*)(p + 0xc4) != 0) {
            n = -1;
        }
        fn_801F02BC(p, lbl_8046D580, iVar2 + 0x2d, &rec, n, 0, flag, lbl_80540C7C, lbl_80540C7C);
        if (*(s32*)(p + 0x240) == 7) {
            *(u8*)(p + 0xc4) = 0;
        }
    }
}

extern "C" s32 fn_801F78F4(void* mgr, u32 id, s32 prev);
extern "C" u8* fn_801F666C(void* mgr, s32 idx);
extern f32 lbl_80540C80;
extern "C" BOOL fn_802C2154(u8* p) {
    f32 m = lbl_80540C80;
    f32 x0 = *(f32*)(p + 0x60);
    f32 y0 = *(f32*)(p + 0x64);
    f32 x1 = *(f32*)(p + 0x68);
    f32 y1 = *(f32*)(p + 0x6c);
    x0 -= m;
    y0 -= m;
    x1 += m;
    y1 += m;
    f32 px = *(f32*)(p + 0xc);
    f32 py = *(f32*)(p + 0x10);
    x0 += px;
    y0 += py;
    x1 += px;
    y1 += py;
    s32 idx = -1;
    for (;;) {
        idx = fn_801F78F4(fn_801F856C(), 0x57415250, idx);
        if (idx < 0) {
            return 0;
        }
        u8* o = fn_801F666C(fn_801F856C(), idx);
        if (o == 0 || *(s32*)(p + 4) != *(s32*)(o + 4) || (*(s32*)(o + 0x90) & 0x7f) != 4) {
            continue;
        }
        f32 ox0 = *(f32*)(o + 0x60);
        f32 oy0 = *(f32*)(o + 0x64);
        f32 ox1 = *(f32*)(o + 0x68);
        f32 oy1 = *(f32*)(o + 0x6c);
        f32 opx = *(f32*)(o + 0xc);
        f32 opy = *(f32*)(o + 0x10);
        ox0 += opx;
        oy0 += opy;
        ox1 += opx;
        oy1 += opy;
        if (ox0 <= x0) ox0 = x0;
        if (oy0 <= y0) oy0 = y0;
        if (ox1 >= x1) ox1 = x1;
        if (oy1 >= y1) oy1 = y1;
        bool hit = false;
        if (ox1 >= ox0 && oy1 >= oy0) {
            hit = true;
        }
        if (hit) {
            p[0x2b0] = 1;
            return 1;
        }
    }
}

extern "C" u8 fn_802DE7CC(void);
extern "C" s32 fn_8022CAF8(s32 player);
extern "C" u8 fn_8022F514(s32 player);
extern "C" s32 fn_8022F3DC(s32 player);
extern "C" u8 fn_802D46D8(void* mgr, s32 a, s32 b, s32 c);
extern "C" u8 fn_802308E0(s32 a);
extern "C" u8 fn_8023077C(void);
extern "C" void fn_8022FE80(s32, s32, s32, u8, u8);
extern s32 lbl_8053AAF8;
extern "C" s32 fn_802C2300(char* p, u32 flags) {
    u8 slot;
    u8 kind;
    if (*(s32*)(p + 0x280) != 0) {
        return 0;
    }
    if (!fn_802DE7CC()) {
        return 0;
    }
    u8 low = flags;
    slot = 0;
    if (flags & 2) {
        slot = 1;
    } else if (low & 4) {
        slot = 2;
    } else if (low & 8) {
        slot = 3;
    }
    kind = slot;
    if (fn_8022CAF8(kind) == 4) {
        if (fn_8022F478(kind)) {
            return 0;
        }
        *(s32*)(p + 0x2a4) = kind;
        if (fn_8022F514(kind)) {
            slot = fn_8022F3DC(kind);
        }
        *(s32*)(p + 0x2a0) = slot;
    } else {
        if (fn_8022F514(kind)) {
            slot = fn_8022F3DC(kind);
        }
        *(s32*)(p + 0x2a4) = slot;
        *(s32*)(p + 0x2a0) = slot;
    }
    if (!fn_802D46D8(fn_802D6A9C(), *(s32*)(p + 0x2a0), 0x168, 0)) {
        if (*(u8*)(lbl_8053AAF8 + 0x7e) == 1) {
            if (fn_802308E0(*(s32*)(p + 0x2a0)) == 1) {
                fn_8022FE80(*(s32*)(p + 0x2a4), *(s32*)(p + 4), *(s32*)(p + 0x198), 0, 0);
            }
        } else {
            if (fn_8023077C() == 1) {
                fn_8022FE80(*(s32*)(p + 0x2a4), *(s32*)(p + 4), *(s32*)(p + 0x198), 0, 0);
            }
        }
        return 1;
    }
    return 0;
}

extern const f32 lbl_80540C94;
extern "C" void fn_802C24A8(u8* p) {
    f32 x0 = *(f32*)(p + 0x60);
    f32 y0 = *(f32*)(p + 0x64);
    f32 x1 = *(f32*)(p + 0x68);
    f32 y1 = *(f32*)(p + 0x6c);
    f32 px = *(f32*)(p + 0xc);
    f32 py = *(f32*)(p + 0x10);
    x0 += px;
    y0 += py;
    x1 += px;
    y1 += py;
    s32 idx = -1;
    for (;;) {
        idx = fn_801F78F4(fn_801F856C(), 0x5354424c, idx);
        if (idx < 0) {
            return;
        }
        u8* o = fn_801F666C(fn_801F856C(), idx);
        if (o == 0 || *(s32*)(p + 4) != *(s32*)(o + 4)) {
            continue;
        }
        s32 st = *(s32*)(o + 0x25c);
        if (st != 0 && st != 2) {
            continue;
        }
        f32 ox0 = *(f32*)(o + 0x60);
        f32 oy0 = *(f32*)(o + 0x64);
        f32 ox1 = *(f32*)(o + 0x68);
        f32 oy1 = *(f32*)(o + 0x6c);
        f32 opx = *(f32*)(o + 0xc);
        f32 opy = *(f32*)(o + 0x10);
        ox0 += opx;
        oy0 += opy;
        ox1 += opx;
        oy1 += opy;
        if (ox0 <= x0) ox0 = x0;
        if (oy0 <= y0) oy0 = y0;
        if (ox1 >= x1) ox1 = x1;
        if (oy1 >= y1) oy1 = y1;
        bool hit = false;
        if (ox1 >= ox0 && oy1 >= oy0) {
            hit = true;
        }
        if (hit) {
            break;
        }
    }
    JGeometry::TVec3<f32>& pos = *(JGeometry::TVec3<f32>*)(p + 0xc);
    JGeometry::TVec3<f32>& vel = *(JGeometry::TVec3<f32>*)(p + 0x3c);
    vel.x = -vel.x;
    vel.y = -vel.y;
    pos.add(vel);
    vel.x /= lbl_80540C94;
    vel.y /= lbl_80540C94;
}

extern "C" BOOL fn_802C2684(void* unused, u8* p, f32* rect) {
    if (p == 0) {
        return 0;
    }
    u32 tag = *(u32*)(p + 0x1a0);
    if (tag == 'LIFT' || tag == 'LIF2' || tag == 'CLOD' || (tag == 'OBLF' && *(s32*)(p + 0x230) == 0) ||
        (tag == 'SSLF' && (*(s16*)(p + 0x230) & 0x7fff) == 0)) {
        f32 x0 = *(f32*)(p + 0x60);
        f32 px = *(f32*)(p + 0xc);
        f32 y0 = *(f32*)(p + 0x64);
        f32 x1 = *(f32*)(p + 0x68);
        f32 py = *(f32*)(p + 0x10);
        f32 y1 = *(f32*)(p + 0x6c);
        x0 += px;
        x1 += px;
        y0 += py;
        y1 += py;
        s32 type = *(s32*)(p + 4);
        u8* base = (u8*)fn_802D6A9C();
        f32* off;
        if (type < 8) {
            off = (f32*)(base + 0xcc);
        } else {
            off = (f32*)(base + 0xdc);
        }
        f32 ox = -off[0];
        f32 oy = -off[1];
        x0 += ox;
        y0 += oy;
        x1 += ox;
        y1 += oy;
        if (x0 <= rect[0]) {
            x0 = rect[0];
        }
        if (y0 <= rect[1]) {
            y0 = rect[1];
        }
        if (x1 >= rect[2]) {
            x1 = rect[2];
        }
        if (y1 >= rect[3]) {
            y1 = rect[3];
        }
        bool hit = false;
        if (x1 >= x0 && y1 >= y0) {
            hit = true;
        }
        if (hit) {
            return 1;
        }
    }
    return 0;
}

extern "C" void fn_802C2B64(char* p) {
    if (*(s32*)(p + 0x240) == 2) {
        *(u8*)(p + 0x2b0) = 1;
        key0Register(p);
    }
}

extern "C" void fn_802C2BD0(char* p) {
    *(u8*)(p + 0x2b0) = 1;
    key0Register(p);
}

extern "C" void fn_802C5284(char* p) {
    key0Register(p);
}

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
