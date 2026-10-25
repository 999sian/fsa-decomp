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
static inline Key0Pt key0Point(const char* p) {
    return Key0Pt(*(const f32*)p, *(const f32*)(p + 4));
}
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

static inline void key0RecordDropPoints(char* p, Key0Pt pos, Key0Pt key, u32 player, u16 tile) {
    u32 id = *(u32*)(p + 0x238);
    u32 packed = (player << 30) | (*(u8*)(p + 0x2b5) << 29) |
                 ((*(u32*)(p + 0x280) << 24) & 0x1f000000) | ((tile << 8) & 0xffff00) |
                 (*(u32*)(p + 4) & 0xff);
    fn_802D6D70(fn_802D6A9C(), pos, key, packed, id);
}

static inline void key0RecordDrop(char* p) {
    u32 id = *(u32*)(p + 0x238);
    Key0Pt key(*(f32*)(p + 0x230), *(f32*)(p + 0x234));
    Key0Pt pos(*(f32*)(p + 0xc), *(f32*)(p + 0x10));
    u32 packed = (*(u32*)(p + 0x23c) << 30) | (*(u8*)(p + 0x2b5) << 29) |
                 ((*(u32*)(p + 0x280) << 24) & 0x1f000000) | ((*(u16*)(p + 0x2a8) << 8) & 0xffff00) |
                 (*(u32*)(p + 0x4) & 0xff);
    fn_802D6D70(fn_802D6A9C(), pos, key, packed, id);
}

#pragma peephole off
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

#pragma peephole reset
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

extern const f32 lbl_80540C70;
extern const f32 lbl_80540C78;
extern "C" u16 fn_8022461C(void* pos, s32 room);
extern "C" u16 fn_80226850(void* pos, s32 room);
extern "C" u8 fn_802C1970(char* p, s32 room, void* pos) {
    s32 type;
    s32 kind;
    type = (u16)fn_8022461C(pos, room);
    kind = (u16)fn_80226850(pos, room);
    if (kind == 0x230 || kind == 0x231) {
        return 0;
    }
    if ((u32)(kind - 0x19e) <= 1 || (u32)(kind - 0x350) <= 1 || (u32)(kind - 0x342) <= 1 ||
        (u32)(kind - 0x345) <= 1 || (u32)(kind - 0x355) <= 1 || (u32)(kind - 0x2ee) <= 1 ||
        (u32)(kind - 0x2fe) <= 1 || (u32)(kind - 0x338) <= 1 || (u32)(kind - 0x32a) <= 1 ||
        (u32)(kind - 0x32d) <= 1 || (u32)(kind - 0x33d) <= 1 || (u32)(kind - 0x2ce) <= 1 ||
        (u32)(kind - 0x2de) <= 1 || (u32)(kind - 0x3b0) <= 1 || (u32)(kind - 0x3a2) <= 1 ||
        (u32)(kind - 0x3a5) <= 1 || kind == 0x3b6 || (u32)(kind - 0x398) <= 1 ||
        (u32)(kind - 0x38a) <= 1 || kind == 0x39d || (u32)(kind - 0x38d) <= 1 || kind == 0x39e) {
        return 1;
    }
    if ((*(s32*)(p + 0x280) == 0 || (u32)(*(s32*)(p + 0x280) - 1) <= 1 || *(s32*)(p + 0x280) == 6 ||
         *(s32*)(p + 0x280) == 9) &&
        ((u32)(kind - 0x1a8) <= 1 || kind == 0x1aa)) {
        return 1;
    }
    if (*(u8*)((u8*)fn_802D6A9C() + *(s32*)(p + 0x4) + 0x131df) != 0 && kind == 0x14) {
        return 0;
    }
    if (type != 0 && type != 4 && type != 5 && type != 6 && type != 7 && type != 2 && type != 3 &&
        type != 0x50 && type != 0xe && type != 0xc && type != 0x2c && type != 0x2d && type != 0x2e &&
        type != 0x2f && type != 0x20 && type != 0xd && type != 0x39 && type != 0x3a && type != 0x3b &&
        type != 0x4c && type != 0x4d && type != 0x4e && type != 0x4f && type != 0x24) {
        if ((u32)(type - 0x10) <= 6 || type == 0x17) {
            if (*(s32*)(p + 0x280) == 7 || *(s32*)(p + 0x280) == 8) {
                return 0;
            }
            if (*(f32*)(p + 0x14) > lbl_80540C70 && *(f32*)(p + 0x3c) == lbl_80540C74) {
                *(s32*)(p + 0x288) = 300;
                if (*(f32*)(p + 0x14) < lbl_80540C78) {
                    *(f32*)(p + 0x14) = lbl_80540C78;
                }
                return 0;
            }
        }
        if (kind == 0x3a) {
            return 1;
        }
        if (kind == 0x3d) {
            return 0;
        }
        if (type == 0x25) {
            return *(u8*)((u8*)fn_802D6A9C() + 0x171) == 0;
        }
        if (type == 0x26) {
            return *(u8*)((u8*)fn_802D6A9C() + 0x171) == 1;
        }
        if ((u32)(type - 0x18) <= 2 || type == 0x1b) {
            return 0;
        }
        if (type != 0x22 || *(u8*)((u8*)fn_802D6A9C() + 0x170) == 1) {
            return 1;
        }
    }
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
        f32 rx0 = rect[0];
        if (x0 <= rx0) {
            x0 = rx0;
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

extern "C" void fn_802C2840(u8* p) {
    s32 room = *(s32*)(p + 4);
    u8* base = (u8*)fn_802D6A9C();
    if ((base + 0x10000)[room + 0x31df] != 0 || *(f32*)(p + 0x14) > lbl_80540C98 ||
        *(f32*)(p + 0x44) > lbl_80540C74) {
        *(s32*)(p + 0x298) = -1;
        return;
    }
    if (*(s32*)(p + 0x280) == 0) {
        *(f32*)(p + 0x60) = lbl_80540C8C;
        *(f32*)(p + 0x64) = lbl_80540C9C;
        *(f32*)(p + 0x68) = lbl_80540C98;
        *(f32*)(p + 0x6c) = lbl_80540C94;
    } else if (*(s32*)(p + 0x280) == 1 || *(s32*)(p + 0x280) >= 6) {
        *(f32*)(p + 0x60) = lbl_80540C9C;
        *(f32*)(p + 0x64) = lbl_80540C9C;
        *(f32*)(p + 0x68) = lbl_80540C94;
        *(f32*)(p + 0x6c) = lbl_80540C94;
    } else {
        f32 b = lbl_80540C80;
        f32 a = lbl_80540CA0;
        *(f32*)(p + 0x60) = a;
        *(f32*)(p + 0x64) = a;
        *(f32*)(p + 0x68) = b;
        *(f32*)(p + 0x6c) = b;
    }
    f32 rect[4] = {*(f32*)(p + 0x60), *(f32*)(p + 0x64), *(f32*)(p + 0x68), *(f32*)(p + 0x6c)};
    if (*(s32*)(p + 0x280) == 0) {
        *(f32*)(p + 0x60) = lbl_80540CA0;
        *(f32*)(p + 0x64) = lbl_80540CA4;
        *(f32*)(p + 0x68) = lbl_80540C80;
        *(f32*)(p + 0x6c) = lbl_80540C84;
    } else if (*(s32*)(p + 0x280) == 1 || *(s32*)(p + 0x280) >= 6) {
        *(f32*)(p + 0x60) = lbl_80540CA4;
        *(f32*)(p + 0x64) = lbl_80540CA4;
        *(f32*)(p + 0x68) = lbl_80540C84;
        *(f32*)(p + 0x6c) = lbl_80540C84;
    } else {
        *(f32*)(p + 0x60) = lbl_80540CA8;
        *(f32*)(p + 0x64) = lbl_80540CA8;
        *(f32*)(p + 0x68) = lbl_80540C88;
        *(f32*)(p + 0x6c) = lbl_80540C88;
    }
    f32 px = *(f32*)(p + 0xc);
    f32 py = *(f32*)(p + 0x10);
    rect[1] += py;
    rect[3] += py;
    rect[0] += px;
    rect[2] += px;
    s32 type = *(s32*)(p + 4);
    base = (u8*)fn_802D6A9C();
    f32* off;
    if (type < 8) {
        off = (f32*)(base + 0xcc);
    } else {
        off = (f32*)(base + 0xdc);
    }
    f32 ox = -off[0];
    f32 oy = -off[1];
    rect[0] += ox;
    rect[1] += oy;
    rect[2] += ox;
    rect[3] += oy;

    JGeometry::TVec3<f32>& pos = *(JGeometry::TVec3<f32>*)(p + 0xc);
    JGeometry::TVec3<f32>& last = *(JGeometry::TVec3<f32>*)(p + 0x254);
    s32 idx = *(s32*)(p + 0x298);
    if (idx != -1) {
        u32* ent = (u32*)((u8*)fn_801F856C() + idx * 4);
        u8* o = (u8*)ent[2];
        if ((u8)fn_802C2684(p, o, rect)) {
            JGeometry::TVec3<f32>& opos = *(JGeometry::TVec3<f32>*)(o + 0xc);
            pos.z = lbl_80540C74;
            JGeometry::TVec3<f32> d;
            d.x = opos.x - last.x;
            d.y = opos.y - last.y;
            d.z = opos.z - last.z;
            pos.add(d);
            last = opos;
            return;
        }
    }
    *(s32*)(p + 0x298) = -1;
    u8* mgr = (u8*)fn_801F856C();
    s32 count = *(s32*)(mgr + 0x1008);
    for (s32 i = 0; i < count; i++) {
        if (i == *(s32*)(p + 0x198)) {
            continue;
        }
        u8* o = (u8*)*(u32*)((u8*)fn_801F856C() + 8 + i * 4);
        if ((u8)fn_802C2684(p, o, rect)) {
            *(s32*)(p + 0x298) = i;
            pos.z = lbl_80540C74;
            last = *(JGeometry::TVec3<f32>*)(o + 0xc);
        }
    }
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

extern "C" s32 fn_8023F264(s32 a);
extern "C" s32 fn_8022D75C(s32 a);
extern "C" u8 fn_8022BC38(s32 a, s32 b, void* c);
extern "C" u8 fn_802DE764(s32 a, s32 b, s32 c);
extern "C" s32 fn_8023DE58(s32 a);
extern "C" void* fn_8023E724(s32 a);
extern "C" void* fn_8023E7B0(s32 a);
extern "C" s32 fn_8023BCD4(s32 a);
extern "C" void fn_801F0E34(char* p, s32 a, s32 b);
extern "C" void fn_801F0D20(char* p, s32 a);
extern "C" void fn_801F355C(char* p);
extern "C" void fn_801F2618(void);
extern "C" void fn_8030C210(s32 a, void* b);
extern "C" void fn_802C2C30(char* p);
extern "C" void fn_802C3AE4(char* p);
extern "C" BOOL fn_801EE24C(char* p);
extern "C" s32 fn_8022D498(s32 a);
extern "C" BOOL fn_80234E30(s32 a);
extern const f32 lbl_80540CAC;
extern const f32 lbl_80540CC8;
extern const f32 lbl_80540CD0;
extern const f32 lbl_80540CF0;
extern "C" void* fn_802D6A9C();
extern "C" void fn_802C4498(char* p) {
    bool bVar4 = true;
    p[0x2ad] = 0xff;
    p[0x2ac] = 0;
    p[0x2b4] = 1;
    if (p[0x2b0] != 0) {
        *(f32*)(p + 0x14) = lbl_80540CAC;
        if (fn_8023F264(*(s32*)(p + 0x23c)) == 0) {
            bVar4 = false;
        } else if (fn_8022D75C(*(s32*)(p + 0x23c)) == 1) {
            bVar4 = false;
        } else if (fn_8022BC38(*(s32*)(p + 0x23c), *(s32*)(p + 4), p + 0xc) == 0) {
            if (fn_802DE764(1, 1, 2) == 0 || *(s32*)(p + 4) != 10 || fn_8023DE58(*(s32*)(p + 0x23c)) != 8) {
                bVar4 = false;
            }
        }
        if (bVar4) {
            f32* pos = (f32*)fn_8023E724(*(s32*)(p + 0x23c));
            *(f32*)(p + 0xc) = pos[0];
            *(f32*)(p + 0x10) = pos[1];
            *(f32*)(p + 0x14) = pos[2];
            *(s32*)(p + 4) = fn_8023DE58(*(s32*)(p + 0x23c));
            *(s32*)(p + 0x44) = 0;
            *(s32*)(p + 0x40) = 0;
            *(s32*)(p + 0x3c) = 0;
            *(s32*)(p + 0x240) = 5;
            *(f32*)(p + 0x14) = 0.0f;
            if (fn_8022461C(p + 0xc, *(s32*)(p + 4)) == 3 && !fn_801EE24C(p)) {
                bVar4 = false;
            } else {
                bVar4 = true;
                p[0x2b0] = 0;
            }
        }
    }
    if (bVar4) {
        if (p[0xc4] == 0 && (p[0xcc] == 0 || *(s32*)(p + 0xd0) == 0)) {
            *(s16*)(p + 0x2a8) = -1;
        } else {
            s32 r29 = *(s32*)((u8*)fn_802D6A9C() + 0x18);
            s32 r3 = *(s32*)((u8*)fn_802D6A9C() + 0x14);
            *(u16*)(p + 0x2a8) = (r3 << 8) | (r29 & 0xff);
        }
        switch (*(s32*)(p + 0x240)) {
        case 0:
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
            break;
        case 12:
            break;
        }
        if (*(s32*)(p + 0x240) > 1 && *(s32*)(p + 0x240) != 9 && *(s32*)(p + 4) < 8) {
            f32 pos[3];
            pos[0] = *(f32*)(p + 0xc);
            pos[1] = *(f32*)(p + 0x10) - *(f32*)(p + 0x14);
            pos[2] = 0.0f;
            fn_8030C210(*(s32*)((u8*)fn_802D6A9C() + 0x24), pos);
        }
    }
}

extern "C" void fn_802C5284(char* p) {
    key0Register(p);
}

extern "C" u8 fn_802D7544(void* mgr, s32 index);
extern "C" void fn_802D7584(void* mgr, s32 index, s32 value);
extern "C" u8 fn_8022F9E4(s32 index, void* a, s32 b, s32 c);
extern "C" u8 fn_802D800C(void* mgr, s32 index);
extern "C" u8 fn_802DCD0C(void* mgr);
extern "C" void fn_802C52DC(u8* p) {
    u32 packed;
    *(u32*)(p + 0x280) = *(u32*)(p + 0x90) & 0x1f;
    *(u32*)(p + 0x27c) = *(u32*)(p + 0x90) >> 7 & 0xf;
    *(u32*)(p + 0x278) = *(u32*)(p + 0x90) >> 12 & 0x1f;
    *(u32*)(p + 0x270) = *(u32*)(p + 0x90) >> 22 & 0x1f;
    *(u32*)(p + 0x274) = *(u32*)(p + 0x90) >> 17 & 0x1f;
    u32 flag = *(u32*)(p + 0x90) >> 5 & 1;
    *(u32*)(p + 0x26c) = *(u32*)(p + 4);
    *(s32*)(p + 0x290) = -1;
    *(s32*)(p + 0x28c) = -1;
    if (*(s32*)(p + 0x27c) != 1) {
        *(s32*)(p + 0xb0) = 0x20000;
    }
    *(s32*)(p + 0x284) = 2;
    *(u8*)(p + 0x2b1) = 0;
    *(u8*)(p + 0x2b5) = 0;
    if ((*(u32*)(p + 0x90) & 0x800) == 0) {
        f32 y = *(f32*)(p + 0x10);
        f32 x = *(f32*)(p + 0xc);
        *(f32*)(p + 0x230) = x;
        *(f32*)(p + 0x234) = y;
        s32 x18 = *(u32*)((u8*)fn_802D6A9C() + 0x18);
        u32 x14 = *(u32*)((u8*)fn_802D6A9C() + 0x14);
        *(u32*)(p + 0x238) = ((*(u32*)(p + 0x280) & 0x1f) << 24) | ((x14 & 0xff) << 16) | ((x18 & 0xff) << 8) | (*(u32*)(p + 4) & 0xff);
        *(s32*)(p + 0x23c) = 0;
    } else if (flag != 0) {
        *(u8*)(p + 0x2b5) = 1;
    }
    switch (*(u32*)(p + 0x27c)) {
    case 0:
        if (fn_802D7544(fn_802D6A9C(), *(s32*)(p + 0x16c))) {
            *(u8*)(p + 0x11c) = 0;
        } else {
            fn_802D7584(fn_802D6A9C(), *(s32*)(p + 0x16c), 1);
            *(s32*)(p + 0x240) = 2;
        }
        break;
    case 1:
        if (fn_8022F9E4(*(s32*)(p + 0x278), *(void**)(p + 0x198), 0, 0)) {
            *(s32*)(p + 0x240) = 4;
        } else {
            *(s32*)(p + 0x240) = 8;
            *(s32*)(p + 0x23c) = *(s32*)(p + 0x278);
        }
        break;
    case 2:
        if (!fn_802D800C(fn_802D6A9C(), *(s32*)(p + 0x270))) {
            *(s32*)(p + 0x240) = 0;
        } else {
            *(u8*)(p + 0x11c) = 0;
        }
        break;
    case 3:
        *(s32*)(p + 0x240) = 6;
        break;
    case 4:
        if (!fn_802D800C(fn_802D6A9C(), *(s32*)(p + 0x270))) {
            *(s32*)(p + 0x240) = 1;
        } else {
            *(u8*)(p + 0x11c) = 0;
        }
        break;
    case 5: {
        *(s32*)(p + 0x240) = 4;
        *(u8*)(p + 0x2b1) = 1;
        u32 a = *(u32*)(p + 0x23c) << 30;
        u32 b = *(u8*)(p + 0x2b5) << 29;
        packed = a | b | ((*(u32*)(p + 0x280) << 24) & 0x1f000000) | (*(u32*)(p + 4) & 0xff);
        if (!fn_802DCD0C(fn_802D6A9C())) {
            s32 x18 = *(u32*)((u8*)fn_802D6A9C() + 0x18);
            packed |= ((x18 & 0xff) << 8) | ((*(u32*)((u8*)fn_802D6A9C() + 0x14) & 0xff) << 16);
        } else {
            packed = *(u16*)(p + 0x2aa) << 8;
        }
        Key0Pt key(*(f32*)(p + 0x230), *(f32*)(p + 0x234));
        Key0Pt pos(*(f32*)(p + 0xc), *(f32*)(p + 0x10));
        u32 id = *(u32*)(p + 0x238);
        fn_802D6D70(fn_802D6A9C(), pos, key, packed, id);
        break;
    }
    case 6:
        if (fn_802D7544(fn_802D6A9C(), *(s32*)(p + 0x16c))) {
            *(u8*)(p + 0x11c) = 0;
        } else {
            *(s32*)(p + 0x240) = 2;
            *(s32*)(p + 0xb0) = 0;
            *(s32*)(p + 0x240) = 9;
        }
        break;
    case 7:
    case 8:
    default:
        *(s32*)(p + 0x240) = 2;
        break;
    }
    *(u8*)(p + 0x2ad) = 0xff;
    *(u8*)(p + 0x2b4) = 1;
    *(JGeometry::TVec3<f32>*)(p + 0x260) = *(JGeometry::TVec3<f32>*)(p + 0xc);
    *(s32*)(p + 0x26c) = *(s32*)(p + 4);
    if (*(s32*)(p + 0x280) == 0) {
        f32 a;
        f32 b;
        b = lbl_80540CA4;
        a = lbl_80540CA0;
        *(f32*)(p + 0x60) = a;
        *(f32*)(p + 0x64) = b;
        f32 d;
        f32 c;
        c = lbl_80540C80;
        d = lbl_80540C84;
        *(f32*)(p + 0x68) = c;
        *(f32*)(p + 0x6c) = d;
    } else if (*(s32*)(p + 0x280) == 1 || *(s32*)(p + 0x280) >= 6) {
        *(f32*)(p + 0x60) = lbl_80540CA4;
        *(f32*)(p + 0x64) = lbl_80540CA4;
        *(f32*)(p + 0x68) = lbl_80540C84;
        *(f32*)(p + 0x6c) = lbl_80540C84;
    } else {
        *(f32*)(p + 0x60) = lbl_80540CA8;
        *(f32*)(p + 0x64) = lbl_80540CA8;
        *(f32*)(p + 0x68) = lbl_80540C88;
        *(f32*)(p + 0x6c) = lbl_80540C88;
    }
    *(f32*)(p + 0x80) = lbl_80540CA4;
    *(f32*)(p + 0x84) = lbl_80540CA4;
    *(f32*)(p + 0x88) = lbl_80540C84;
    *(f32*)(p + 0x8c) = lbl_80540C84;
    *(s32*)(p + 0x288) = 0;
    *(u8*)(p + 0x2b2) = 0;
    *(u8*)(p + 0x2b3) = 0;
    *(u8*)(p + 0x2af) = 0;
    *(s32*)(p + 0x294) = 0;
    *(u8*)(p + 0x2ae) = 0;
    *(u8*)(p + 0x2b0) = 0;
    *(u16*)(p + 0x2a8) = 0xffff;
    *(s32*)(p + 0x298) = -1;
    *(s32*)(p + 0x29c) = -1;
    s32 x18 = *(u32*)((u8*)fn_802D6A9C() + 0x18);
    *(u16*)(p + 0x2aa) = (x18 & 0xff) | ((*(u32*)((u8*)fn_802D6A9C() + 0x14) & 0xff) << 8);
    *(s32*)(p + 0x2a0) = -1;
    if (flag == 0) {
        *(s32*)(p + 0x2a4) = -1;
    }
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
