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
#include "JSystem/JGeometry/Box.h"

extern "C" s32 fn_8023F264(s32 a);
extern "C" void* fn_8023E724(s32 a);
extern "C" void fn_801F0E34(char* p, s32 a, s32 b);
extern "C" u8 fn_801F2618(char* p, void* delta, s32 flags);
extern "C" BOOL fn_801EE24C(char* p);
extern "C" u8 fn_8022F9E4(s32 index, void* a, s32 b, s32 c);
extern "C" u8 fn_802DCD0C(void* mgr);
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
static inline u32 key0PackActorFlags(u8* p) {
    u32 mode = *(u32*)(p + 0x23c);
    u32 flag = p[0x2b5];
    u32 packed = (mode << 30) | (flag << 29);
    packed = __rlwimi(packed, *(u32*)(p + 0x280), 24, 3, 7);
    return __rlwimi(packed, *(u32*)(p + 4), 0, 24, 31);
}
static inline u32 key0PackActorFlags2(u8* p) {
    u32 flag = p[0x2b5] << 29;
    u32 mode = *(u32*)(p + 0x23c) << 30;
    u32 packed = mode | flag;
    packed = __rlwimi(packed, *(u32*)(p + 0x280), 24, 3, 7);
    return __rlwimi(packed, *(u32*)(p + 4), 0, 24, 31);
}
struct Key0Pt {
    f32 x, y;
    Key0Pt(f32 x_, f32 y_) { x = x_; y = y_; }
};
static inline Key0Pt key0Point(const char* p) {
    return Key0Pt(*(const f32*)p, *(const f32*)(p + 4));
}
extern "C" void* fn_802D6A9C(void);

extern "C" void fn_802D6C10(void* rec, Key0Pt pt, u32 id);

static inline u8 key0RoomFlag(s32 room) {
    u8* base = (u8*)fn_802D6A9C();
    return base[room + 0x131df];
}

static inline void key0Register(char* p) {
    u32 id = *(u32*)(p + 0x238);
    fn_802D6C10(fn_802D6A9C(), Key0Pt(*(f32*)(p + 0x230), *(f32*)(p + 0x234)), id);
}

static inline void key0RegisterPt(char* p) {
    u32 id = *(u32*)(p + 0x238);
    const Key0Pt& pt = Key0Pt(*(f32*)(p + 0x230), *(f32*)(p + 0x234));
    fn_802D6C10(fn_802D6A9C(), pt, id);
}

extern "C" void fn_802D6D70(void* rec, Key0Pt a, Key0Pt b, u32 packed, u32 id);
static inline void key0LinkSelf(char* p, u32 packed) {
    Key0Pt key = key0Point(p + 0x230);
    Key0Pt pos = key0Point(p + 0xc);
    u32 id = *(u32*)(p + 0x238);
    fn_802D6D70(fn_802D6A9C(), pos, key, packed, id);
}

// fn_802C18BC - KEY0: can the key be dropped at pos?
extern "C" u8* fn_8020D58C();
extern "C" u8 fn_8020D6AC(void* slot, s32 room, void* pos, u32 id, void* ext);
extern "C" u8 fn_802C1970(char* p, s32 room, void* pos);
// fn_802C1674 / fn_802C1778 - KEY0: drop the key and record where it went.
// NONMATCHING (~87%): retail builds both points in temporaries (0x18/0x20)
// and copies them to the argument slots; packed-id scheduling differs.
extern "C" void fn_802D6D70(void* rec, Key0Pt a, Key0Pt b, u32 packed, u32 id);
static inline void key0LinkPoints(const Key0Pt& key, const Key0Pt& pos, u32 packed, u32 id) {
    fn_802D6D70(fn_802D6A9C(), pos, key, packed, id);
}
extern "C" u8 fn_8022F478(s32 player);
extern "C" s32 fn_8023EF50(s32 player);

static inline void key0RecordDropPoints(char* p, u16 tile, u32 player, const Key0Pt& key, const Key0Pt& pos) {
    u32 id = *(u32*)(p + 0x238);
    u32 packed = player | (*(u8*)(p + 0x2b5) << 29) |
                 ((*(u32*)(p + 0x280) << 24) & 0x1f000000) | ((tile << 8) & 0xffff00) |
                 (*(u32*)(p + 4) & 0xff);
    fn_802D6D70(fn_802D6A9C(), pos, key, packed, id);
}

static inline void key0RecordDropPoints(char* p, u16 tile, const Key0Pt& pos, const Key0Pt& key, u32 player) {
    u32 id = *(u32*)(p + 0x238);
    u32 packed = player | (*(u8*)(p + 0x2b5) << 29) |
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

extern "C" void fn_802C1674(char* p) {
    if (*(s32*)(p + 0x240) == 4 && *(u8*)(p + 0xc4) == 0) {
        if (*(u8*)(p + 0x2af) != 0) {
            u16 tile = *(u16*)(p + 0x2a8);
            if (tile != 0xffff) {
                Key0Pt pos = key0Point(p + 0xc);
                Key0Pt key = key0Point(p + 0x230);
                key0RecordDropPoints(p, tile, pos, key, *(u32*)(p + 0x23c) << 30);
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
        s32 owner = fn_8023EF50(*(s32*)(p + 0x23c));
        if (owner != me) {
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
    {
        Key0Pt pos(*(f32*)(p + 0xc), *(f32*)(p + 0x10));
        Key0Pt key(*(f32*)(p + 0x230), *(f32*)(p + 0x234));
        u32 player = *(u32*)(p + 0x23c) << 30;
        key0RecordDropPoints(p, *(u16*)(p + 0x2a8), pos, key, player);
    }
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
extern "C" u8 fn_802C1970(char* p, s32 roomArg, void* pos) {
    int room = roomArg;
    u16 kind;
    s32 type;
    type = (u16)fn_8022461C(pos, room);
    kind = (u16)fn_80226850(pos, room);
    if ((s32)kind == 0x230 || (s32)kind == 0x231) {
        return 0;
    }
    if ((u32)((s32)kind - 0x19e) <= 1 || (u32)((s32)kind - 0x350) <= 1 || (u32)((s32)kind - 0x342) <= 1 ||
        (u32)((s32)kind - 0x345) <= 1 || (u32)((s32)kind - 0x355) <= 1 || (u32)((s32)kind - 0x2ee) <= 1 ||
        (u32)((s32)kind - 0x2fe) <= 1 || (u32)((s32)kind - 0x338) <= 1 || (u32)((s32)kind - 0x32a) <= 1 ||
        (u32)((s32)kind - 0x32d) <= 1 || (u32)((s32)kind - 0x33d) <= 1 || (u32)((s32)kind - 0x2ce) <= 1 ||
        (u32)((s32)kind - 0x2de) <= 1 || (u32)((s32)kind - 0x3b0) <= 1 || (u32)((s32)kind - 0x3a2) <= 1 ||
        (u32)((s32)kind - 0x3a5) <= 1 || (s32)kind == 0x3b6 || (u32)((s32)kind - 0x398) <= 1 ||
        (u32)((s32)kind - 0x38a) <= 1 || (s32)kind == 0x39d || (u32)((s32)kind - 0x38d) <= 1 || (s32)kind == 0x39e) {
        return 1;
    }
    if ((*(s32*)(p + 0x280) == 0 || (u32)(*(s32*)(p + 0x280) - 1) <= 1 || *(s32*)(p + 0x280) == 6 ||
         *(s32*)(p + 0x280) == 9) &&
        ((u32)((s32)kind - 0x1a8) <= 1 || (s32)kind == 0x1aa)) {
        return 1;
    }
    if (key0RoomFlag(*(s32*)(p + 0x4)) != 0 && (s32)kind == 0x14) {
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
                if (*(f32*)(p + 0x14) < 18.0f) {
                    *(f32*)(p + 0x14) = 18.0f;
                }
                return 0;
            }
        }
        if ((s32)kind == 0x3a) {
            return 1;
        }
        if ((s32)kind == 0x3d) {
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

#pragma opt_lifetimes off
extern "C" void fn_802C2840(u8* p) {
    s32 room;
    s32 type;
    u8* firstObj;
    s32 count;
    u8* loopObj;
    s32 idx;
    s32 i;
    room = *(s32*)(p + 4);
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
        f32 b;
        f32 a;
        a = lbl_80540CA0;
        b = lbl_80540C80;
        *(f32*)(p + 0x60) = a;
        *(f32*)(p + 0x64) = a;
        *(f32*)(p + 0x68) = b;
        *(f32*)(p + 0x6c) = b;
    }
    f32 rect[4];
    rect[0] = *(f32*)(p+0x60);
    rect[1] = *(f32*)(p+0x64);
    rect[2] = *(f32*)(p+0x68);
    rect[3] = *(f32*)(p+0x6c);
    if (*(s32*)(p + 0x280) == 0) {
        f32 b;
        f32 a;
        a = lbl_80540CA0;
        b = lbl_80540CA4;
        *(f32*)(p+0x60) = a;
        a = lbl_80540C80;
        *(f32*)(p+0x64) = b;
        b = lbl_80540C84;
        *(f32*)(p+0x68) = a;
        *(f32*)(p+0x6c) = b;
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
    ((JGeometry::TBox2<f32>*)rect)->addPos(*(f32*)(p+0xc), *(f32*)(p+0x10));
    type = *(s32*)(p + 4);
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
    idx = *(s32*)(p + 0x298);
    if (idx != -1) {
        u32* ent = (u32*)((u8*)fn_801F856C() + idx * 4);
        firstObj = (u8*)ent[2];
        if ((u8)fn_802C2684(p, firstObj, rect)) {
            JGeometry::TVec3<f32>& opos = *(JGeometry::TVec3<f32>*)(firstObj + 0xc);
            pos.z = lbl_80540C74;
            JGeometry::TVec3<f32> d(opos);
            d.sub(last);
            pos.add(d);
            last = opos;
            return;
        }
    }
    *(s32*)(p + 0x298) = -1;
    u8* mgr = (u8*)fn_801F856C();
    count = *(s32*)(mgr + 0x1008);
    i=0;
    for (idx = 0; i < count; idx+=4, i++) {
        if (i == *(s32*)(p + 0x198)) {
            continue;
        }
        loopObj = (u8*)*(u32*)((u8*)fn_801F856C() + 8 + idx);
        if ((u8)fn_802C2684(p, loopObj, rect)) {
            *(s32*)(p + 0x298) = i;
            pos.z = lbl_80540C74;
            last = *(JGeometry::TVec3<f32>*)(loopObj + 0xc);
        }
    }
}
#pragma opt_lifetimes on
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

extern "C" void fn_801F0E34(char* p, s32 a, s32 b);
extern "C" void fn_8013CC50(s32 room, void* pos, f32 scale, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" u8 fn_802DE9A0();
extern "C" u8 fn_802DEB58();
extern const f32 lbl_80540C7C;
extern const f32 lbl_80540C90;
extern const f32 lbl_80540CB0;
extern const f32 lbl_80540CB4;
extern const f32 lbl_80540CB8;
extern const f32 lbl_80540CBC;
extern const f32 lbl_80540CC0;
extern const f32 lbl_80540CC4;
extern const f32 lbl_80540CC8;
extern const f32 lbl_80540CCC;
extern const f32 lbl_80540CD0;
extern "C" void fn_801F2B20(char* p, s32 a);
extern "C" void fn_801F0D20(char* p, s32 a);

// KEY0: link the key's home tile to where it is now.
static inline void key0LinkHere(char* p) {
    u32 packed = key0PackActorFlags((u8*)p);
    u32 x18;
    if (!fn_802DCD0C(fn_802D6A9C())) {
        x18 = *(u32*)((u8*)fn_802D6A9C() + 0x18);
        packed |= ((x18 & 0xff) << 8) | ((*(u32*)((u8*)fn_802D6A9C() + 0x14) & 0xff) << 16);
    } else {
        packed = *(u16*)(p + 0x2aa) << 8;
    }
    const Key0Pt& key = Key0Pt(*(f32*)(p + 0x230), *(f32*)(p + 0x234));
    const Key0Pt& pos = Key0Pt(*(f32*)(p + 0xc), *(f32*)(p + 0x10));
    u32 id = *(u32*)(p + 0x238);
    key0LinkPoints(key, pos, packed, id);
}

static inline void key0LinkPosKey(const Key0Pt& pos, const Key0Pt& key, u32 packed, u32 id) {
    fn_802D6D70(fn_802D6A9C(), pos, key, packed, id);
}

static inline u32 key0MgrBits() {
    u32 x18 = *(u32*)((u8*)fn_802D6A9C() + 0x18);
    u32 bits = (x18 & 0xff) << 8;
    return bits | ((*(u32*)((u8*)fn_802D6A9C() + 0x14) & 0xff) << 16);
}

static inline void key0LinkHere2(char* p) {
    u32 packed = key0PackActorFlags2((u8*)p);
    if (!fn_802DCD0C(fn_802D6A9C())) {
        packed |= key0MgrBits();
    } else {
        packed = *(u16*)(p + 0x2aa) << 8;
    }
    key0LinkPosKey(Key0Pt(*(f32*)(p + 0xc), *(f32*)(p + 0x10)), Key0Pt(*(f32*)(p + 0x230), *(f32*)(p + 0x234)),
                   packed, *(u32*)(p + 0x238));
}

static inline void key0Land(char* p) {
    JGeometry::TVec3<f32>& vel = *(JGeometry::TVec3<f32>*)(p + 0x3c);
    *(u8*)(p + 0x2b3) = 0;
    *(f32*)(p + 0x10) = *(f32*)(p + 0x10) - *(f32*)(p + 0x14);
    *(f32*)(p + 0x14) = 0.0f;
    vel.z = 0.0f;
    if (vel.y >= lbl_80540C94) {
        vel.y = lbl_80540C94;
    } else if (vel.y <= lbl_80540C9C) {
        vel.y = lbl_80540C9C;
    }
    if (*(s32*)(p + 0x280) == 6) {
        if (vel.x != lbl_80540C74 || vel.y != lbl_80540C74) {
            vel.x = lbl_80540CB0 * vel.x;
            vel.y = lbl_80540CB0 * vel.y;
        }
    }
}

static inline void key0RegisterAt(const Key0Pt& pt, u32 id) {
    fn_802D6C10(fn_802D6A9C(), pt, id);
}

static inline void key0RegisterRef(char* p) {
    const Key0Pt& pt = Key0Pt(*(f32*)(p + 0x230), *(f32*)(p + 0x234));
    u32 id = *(u32*)(p + 0x238);
    key0RegisterAt(pt, id);
}

// KEY0: collected. Spawns the pickup effect, registers the tile and deactivates.
static inline void key0Collect(char* p) {
    s32 room = *(s32*)(p + 0x4);
    if (room >= 8) {
        Actor_CreateByID(fn_801F856C(), 0x4b4d5249, room, p + 0xc, 0, -1, -1);
    } else {
        fn_8013CC50(room, p + 0xc, lbl_80540C7C, 0x503, 1, 0, 0, 0, 1);
    }
    key0RegisterRef(p);
    *(u8*)(p + 0x11c) = 0;
}

// KEY0: react to the tile the key landed on (pit / special floor).
static inline u8 key0TileEvent(char* p, u16 tile) {
    u8 handled;
    if (tile == 3) {
        if ((u8)fn_801EE24C(p) == 1) {
            *(s32*)(p + 0x240) = 4;
            handled = 1;
            goto done;
        }
    } else if (tile == 0xe) {
        if (fn_802DE9A0()) {
            fn_8013CC50(*(s32*)(p + 4), p + 0xc, lbl_80540C7C, 0x2a9, -1, 1, 0, 0, 1);
            fn_8013CC50(*(s32*)(p + 4), p + 0xc, lbl_80540C7C, 0x2aa, 0, 0, 0, 0, 1);
            fn_801F0E34(p, 0x5005f, 0);
        } else if (fn_802DEB58()) {
            fn_8013CC50(*(s32*)(p + 4), p + 0xc, lbl_80540C7C, 0x45e, -1, 1, 0, 0, 1);
            fn_8013CC50(*(s32*)(p + 4), p + 0xc, lbl_80540C7C, 0x45f, 0, 0, 0, 0, 1);
            fn_801F0E34(p, 0x5003f, 0);
        }
    } else {
        handled = 0;
        goto done;
    }
    *(u8*)(p + 0x2b0) = handled = 1;
done:
    return handled;
}

#pragma auto_inline off
extern "C" void fn_802C2C30(char* p) {
    JGeometry::TVec3<f32> delta;
    s32 room;
    s32 kind;
    u16 tile;
    u8 moving;
    JGeometry::TVec3<f32>& vel = *(JGeometry::TVec3<f32>*)(p + 0x3c);
    fn_802C24A8((u8*)p);
    room = *(s32*)(p + 4);
    if (key0RoomFlag(room) != 0) {
        if (*(u8*)(p + 0x2b3) == 1) {
            key0Land(p);
        }
        *(f32*)(p + 0x248) = *(f32*)(p + 0xc);
        *(f32*)(p + 0x24c) = *(f32*)(p + 0x10);
        *(f32*)(p + 0x250) = *(f32*)(p + 0x14);
        ((JGeometry::TVec3<f32>*)(p + 0xc))->add(vel);
        vel.y += lbl_80540CB4;
        if (vel.y > lbl_80540CB8) {
            vel.y = lbl_80540CB8;
        }
        delta.set(lbl_80540C74, lbl_80540C74, lbl_80540C74);
        if (fn_801F2618(p, &delta, 0)) {
            kind = *(s32*)(p + 0x280);
            if (kind == 7) {
                room = *(s32*)(p + 4);
                if (room < 8) {
                    Actor_CreateByID(fn_801F856C(), 0x414c4345, room, p + 0xc, (*(s32*)(p + 0x290) << 4) | 2, -1, -1);
                    key0Collect(p);
                    return;
                }
            }
            if (kind == 8) {
                room = *(s32*)(p + 4);
                if (room < 8) {
                    Actor_CreateByID(fn_801F856C(), 0x414c4345, room, p + 0xc, (*(s32*)(p + 0x290) << 4) | 1, -1, -1);
                    key0Collect(p);
                    return;
                }
            }
            if (delta.y != lbl_80540C74) {
                if (kind == 6 && vel.y > lbl_80540CBC) {
                    vel.x = vel.x / lbl_80540C94;
                    vel.y = -(vel.y / lbl_80540C94);
                    return;
                }
                if (delta.y > 0.0f) {
                    if (vel.y < 0.0f) {
                        vel.y = 0.0f;
                    }
                    return;
                }
                JGeometry::TVec3<f32> probe;
                probe.x = lbl_80540C84 + *(f32*)(p + 0xc);
                probe.y = lbl_80540C88 + *(f32*)(p + 0x10);
                probe.z = 0.0f;
                u16 a = fn_80226850(&probe, *(s32*)(p + 4));
                probe.x = *(f32*)(p + 0xc) - lbl_80540C84;
                u16 b = fn_80226850(&probe, *(s32*)(p + 4));
                u8 hit;
                if (a == 0x16 || b == 0x16) {
                    vel.y = lbl_80540C8C;
                    if (*(f32*)fn_8023E724(*(s32*)(p + 0x23c)) > *(f32*)(p + 0xc)) {
                        vel.x = lbl_80540C7C;
                    } else {
                        vel.x = lbl_80540C90;
                    }
                    hit = 1;
                } else {
                    hit = 0;
                }
                if (hit == 1) {
                    return;
                }
                if ((u8)fn_802C2154((u8*)p) == 1) {
                    return;
                }
                *(u8*)(p + 0x2b2) = 0;
                vel.z = lbl_80540C74;
                vel.y = lbl_80540C74;
                vel.x = lbl_80540C74;
                *(s32*)(p + 0x240) = 2;
                if (*(s32*)(p + 0x27c) == 2) {
                    *(s32*)(p + 0x27c) = 3;
                }
                *(f32*)(p + 0xc) = *(f32*)(p + 0x248);
                *(f32*)(p + 0x10) = *(f32*)(p + 0x24c);
                *(f32*)(p + 0x14) = *(f32*)(p + 0x250);
                key0LinkHere2(p);
                return;
            }
            if (delta.x != lbl_80540C74) {
                vel.x = vel.x * lbl_80540CC0;
                if ((delta.x > lbl_80540C74 && *(f32*)(p + 0xc) <= *(f32*)(p + 0x248)) ||
                    (delta.x < 0.0f && *(f32*)(p + 0xc) >= *(f32*)(p + 0x248))) {
                    *(f32*)(p + 0xc) = *(f32*)(p + 0x248);
                    *(f32*)(p + 0x10) = *(f32*)(p + 0x24c);
                    *(f32*)(p + 0x14) = *(f32*)(p + 0x250);
                }
            }
        } else if ((vel.x != lbl_80540C74 || vel.y != lbl_80540C74 || vel.z != lbl_80540C74) &&
                   *(s32*)(p + 0x280) != 2) {
            fn_801F2B20(p, 0);
        }
        return;
    }
    if (*(u8*)(p + 0x2af) != 0) {
        key0LinkHere2(p);
        *(u8*)(p + 0x2af) = 0;
        if (*(s32*)(p + 0x280) == 6) {
            if (vel.x != lbl_80540C74 || vel.y != lbl_80540C74) {
                vel.x = lbl_80540CB0 * vel.x;
                vel.y = lbl_80540CB0 * vel.y;
                vel.z = lbl_80540CC4;
            }
        }
    }
    ((JGeometry::TVec3<f32>*)(p + 0xc))->add(*(JGeometry::TVec3<f32>*)(p + 0xc), vel);
    vel.z += lbl_80540CC8;
    tile = fn_8022461C(p + 0xc, *(s32*)(p + 4));
    if (*(s32*)(p + 0x298) != -1) {
        tile = 0;
    }
    if (*(s32*)(p + 0x280) == 6 && (*(f32*)(p + 0x14) < lbl_80540C74 || *(s32*)(p + 0x298) != -1)) {
        if (key0TileEvent(p, tile) == 1) {
            return;
        }
        if (tile != 0xd && tile != 0x39) {
            if (vel.z < lbl_80540CCC) {
                vel.x = vel.x / lbl_80540C94;
                vel.y = vel.y / lbl_80540C94;
                vel.z = -(vel.z / lbl_80540C94);
                *(f32*)(p + 0x14) = lbl_80540C74;
            }
            fn_801F0E34(p, 0x30072, 0);
        }
    }
    if (*(f32*)(p + 0x14) < lbl_80540C74 || *(s32*)(p + 0x298) != -1) {
        moving = 1;
        if (0.0f == vel.x && 0.0f == vel.y) {
            moving = 0;
        }
        if (*(u8*)(p + 0x2b1) == 1) {
            fn_801F0D20(p, 3);
            *(u8*)(p + 0x2b1) = 0;
        }
        *(f32*)(p + 0x14) = lbl_80540C74;
        vel.z = lbl_80540C74;
        vel.y = lbl_80540C74;
        vel.x = lbl_80540C74;
        *(s32*)(p + 0x240) = 2;
        if (*(s32*)(p + 0x27c) == 2) {
            *(s32*)(p + 0x27c) = 3;
        }
        if (key0TileEvent(p, tile)) {
            return;
        }
        if (tile == 0xd || tile == 0x39) {
            JGeometry::TVec3<f32> e(*(JGeometry::TVec3<f32>*)(p + 0xc));
            e.z -= lbl_80540C80;
            fn_8013CC50(*(s32*)(p + 4), &e, lbl_80540C7C, 0x3d0, 0, 1, 0, 0, 1);
            fn_801F0E34(p, 0x30022, 0);
        }
        kind = *(s32*)(p + 0x280);
        if (kind == 7 || kind == 8) {
            room = *(s32*)(p + 4);
            if (room >= 8) {
                return;
            }
            if (moving != 1) {
                return;
            }
            if (kind == 7) {
                Actor_CreateByID(fn_801F856C(), 0x414c4345, room, p + 0xc, (*(s32*)(p + 0x290) << 4) | 2, -1, -1);
            } else {
                Actor_CreateByID(fn_801F856C(), 0x414c4345, room, p + 0xc, (*(s32*)(p + 0x290) << 4) | 1, -1, -1);
            }
            key0Collect(p);
            return;
        }
        key0RegisterRef(p);
        key0LinkHere2(p);
        return;
    }
    if (fn_801F2618(p, &delta, 0)) {
        if (tile == 0xd || tile == 0xe || tile == 0x3b) {
            return;
        }
        if (delta.x != lbl_80540C74) {
            vel.x = vel.x * lbl_80540CC0;
            if (vel.x < lbl_80540CC0) {
                vel.x = lbl_80540CC0;
            } else if (vel.x > lbl_80540CD0) {
                vel.x = lbl_80540CD0;
            }
        }
        if (delta.y != lbl_80540C74) {
            vel.y = vel.y * lbl_80540CC0;
            if (vel.y < lbl_80540CC0) {
                vel.y = lbl_80540CC0;
            } else if (vel.y > lbl_80540CD0) {
                vel.y = lbl_80540CD0;
            }
        }
    } else if ((vel.x != lbl_80540C74 || vel.y != lbl_80540C74 || vel.z != lbl_80540C74) &&
               *(s32*)(p + 0x280) != 2) {
        fn_801F2B20(p, 0);
    }
}
#pragma auto_inline reset

extern const f32 lbl_80540CD4;
extern const f32 lbl_80540CD8;
extern const f32 lbl_80540CB8;
extern const f32 lbl_8046D560[];
extern "C" u8 fn_80239C00(s32 player, void* rect, s32 room);
extern "C" s32 fn_80230CFC(s32 player);
extern "C" u8 fn_8022F6E8(s32 player, s32 id);
extern "C" u32 fn_801F2740(char* p, s32 flags);
extern "C" void detach__5ActorFv(char* p);
extern "C" u8 fn_802DE9A0();
extern "C" u8 fn_802DEB58();
extern "C" void fn_802C3AE4(char* p) {
    if (!*(u8*)(p + 0x2b2)) return;
    if (*(s32*)(p + 0x280) == 6) {
        JGeometry::TVec3<f32>& pos = *(JGeometry::TVec3<f32>*)(p + 0xc);
        pos.add(*(JGeometry::TVec3<f32>*)(p + 0x3c));
        if (*(f32*)(p+0x3c) > 0.05f) *(f32*)(p+0x3c) -= 0.05f;
        else if (*(f32*)(p+0x3c) < -0.05f) *(f32*)(p+0x3c) += 0.05f;
        else *(f32*)(p+0x3c) = 0.0f;
        if (*(f32*)(p+0x40) > 0.05f) *(f32*)(p+0x40) -= 0.05f;
        else if (*(f32*)(p+0x40) < -0.05f) *(f32*)(p+0x40) += 0.05f;
        else *(f32*)(p+0x40) = 0.0f;
    }
    JGeometry::TBox2<f32> rect(*(JGeometry::TBox2<f32>*)(p+0x60));
    rect.addPos(*(f32*)(p+0xc),*(f32*)(p+0x10));
    s32 kind;
    s32 i;
    for (i=0; i<4; i++) {
        if ((u8)fn_8023F264(i) && fn_80239C00(i, &rect, *(s32*)(p+4))) {
            kind = *(s32*)(p+0x280);
            if (kind==3) goto create;
            if (kind==4) goto create;
            if (kind==5) {
create:
                Actor_CreateByID(fn_801F856C(), 0x544b5241, *(s32*)(p+4), p+0xc, (kind+(i<<12))+0x210, -1, -1);
                key0Register(p);
                detach__5ActorFv(p);
                return;
            }
            if (fn_8022F9E4(i, *(void**)(p+0x198), 1, 0)) {
                *(s32*)(p+0x284)=10;
                *(s32*)(p+0x240)=3;
                key0Register(p);
                *(u8*)(p+0x2ae)=0;
                *(s32*)(p+0x23c)=i;
                break;
            }
        }
    }
    if (*(s32*)(p+0x240)!=2) return;
    s32 room0=*(s32*)(p+4);
    s32 offset=1;
    if (room0>=8) offset=8;
    u16 tile=fn_80226850(p+0xc, room0+offset);
    if (tile!=0 && tile!=0x39) {
        *(u8*)(p+0x2ad)=0x80;
        *(u8*)(p+0x2ac)=2;
    }
    key0Register(p);
    u8 mask=1;
    u32 hit=fn_801F2740(p,-1);
    if ((u8)hit) {
        if ((u8)fn_802C2300(p,hit)==1) {
            *(s32*)(p+0x240)=11;
            return;
        }
        *(u8*)(p+0x2b5)=1;
        tile=fn_8022461C(p+0xc,*(s32*)(p+4));
        if (tile==0xd || tile==0x3b) {
            s32 player;
            for (player=0; player<4; player++,mask<<=1) {
                if ((u8)hit&mask) break;
            }
            if (fn_8022F6E8(player,*(s32*)(p+0x198))==1) {
                *(s32*)(p+0x29c)=player;
                *(s32*)(p+0x240)=10;
                *(u8*)(p+0x2b2)=0;
            }
        } else {
            for (i=0; i<4; i++,mask<<=1) {
                if ((u8)hit&mask) {
                    JGeometry::TVec3<f32> pos(*(Vec*)fn_8023E724(i));
                    s32 dx=(s32)(f32)__fabs(*(f32*)(p+0xc)-pos.x);
                    s32 dy=(s32)(f32)__fabs(*(f32*)(p+0x10)-pos.y);
                    s32 dir=fn_80230CFC(i);
                    if ((dx>=0 && dx<=15 && dir==0) || dir==1) {
                        if (*(f32*)(p+0xc)>pos.x) {
                            *(f32*)(p+0xc)+=(15-dx)>>1;
                            *(u8*)(p+0x2ae)=1;
                        } else {
                            *(f32*)(p+0xc)-=(15-dx)>>1;
                            *(u8*)(p+0x2ae)=2;
                        }
                    }
                    const s32 room2=*(s32*)(p+4);
                    if (key0RoomFlag(room2)) {
                        if (*(f32*)(p+0xc)>pos.x) *(f32*)(p+0xc)+=(15-dx)>>1;
                        else *(f32*)(p+0xc)-=(15-dx)>>1;
                    } else if ((dy>=0 && dy<=15 && dir==3) || dir==2) {
                        if (*(f32*)(p+0x10)>pos.y) {
                            *(f32*)(p+0x10)+=(15-dy)>>1;
                            *(u8*)(p+0x2ae)=3;
                        } else {
                            *(f32*)(p+0x10)-=(15-dy)>>1;
                            *(u8*)(p+0x2ae)=4;
                        }
                    }
                    const s32 room=*(s32*)(p+4);
                    if (key0RoomFlag(room)) *(u8*)(p+0x2ae)=0;
                    *(s32*)(p+0x23c)=i;
                }
            }
        }
    } else if (*(s32*)(p+0x280)==6 && *(u8*)(p+0x2ae)) {
        u8 dir=*(u8*)(p+0x2ae)-1;
        dir &= 0x7f;
        *(f32*)(p+0x3c)=lbl_8046D560[dir*2];
        *(f32*)(p+0x40)=lbl_8046D560[dir*2+1];
        *(u8*)(p+0x2ae)=0;
    }
    JGeometry::TVec3<f32> delta(lbl_80540C74,lbl_80540C74,lbl_80540C74);
    fn_801F2618(p,&delta,0);
    if (delta.y!=lbl_80540C74 && delta.x!=lbl_80540C74) {
        *(f32*)(p+0x10)=(u32)((s32)*(f32*)(p+0x10)&~15);
        if (delta.y<lbl_80540C74) *(f32*)(p+0x10)+=lbl_80540CB8;
        else *(f32*)(p+0x10)+=lbl_80540C84;
        *(f32*)(p+0xc)=(u32)((s32)*(f32*)(p+0xc)&~15);
        if (delta.x<lbl_80540C74) *(f32*)(p+0xc)+=lbl_80540CB8;
        else *(f32*)(p+0xc)+=lbl_80540C84;
    }
    if (*(s32*)(p+0x240)!=10) {
        u32 x18;
        u32 packed=key0PackActorFlags((u8*)p);
        if (!fn_802DCD0C(fn_802D6A9C())) {
            x18=*(u32*)((u8*)fn_802D6A9C()+0x18);
            packed|=((x18&0xff)<<8) | ((*(u32*)((u8*)fn_802D6A9C()+0x14)&0xff)<<16);
        } else packed=*(u16*)(p+0x2aa)<<8;
        key0LinkSelf(p, packed);
    }
    tile=fn_8022461C(p+0xc,*(s32*)(p+4));
    if (*(s32*)(p+0x298)!=-1) tile=0;
    u8 handled;
    if (tile==3) {
        if ((u8)fn_801EE24C(p)==1) {
            *(s32*)(p+0x240)=4;
            handled=1;
            goto done;
        }
    } else if (tile==0xe) {
        if (fn_802DE9A0()) {
            fn_8013CC50(*(s32*)(p+4),p+0xc,lbl_80540C7C,0x2a9,-1,1,0,0,1);
            fn_8013CC50(*(s32*)(p+4),p+0xc,lbl_80540C7C,0x2aa,0,0,0,0,1);
            fn_801F0E34(p,0x5005f,0);
        } else if (fn_802DEB58()) {
            fn_8013CC50(*(s32*)(p+4),p+0xc,lbl_80540C7C,0x45e,-1,1,0,0,1);
            fn_8013CC50(*(s32*)(p+4),p+0xc,lbl_80540C7C,0x45f,0,0,0,0,1);
            fn_801F0E34(p,0x5003f,0);
        }
    } else {
        handled=0;
        goto done;
    }
    *(u8*)(p+0x2b0)=handled=1;
done:
    if (handled!=1) {
        s32 room=*(s32*)(p+4);
        if (key0RoomFlag(room)) {
            *(u8*)(p+0x2b2)=0;
            fn_802C2154((u8*)p);
        }
    }
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
extern "C" void fn_8030C210(s32 a, JGeometry::TVec3<f32> b);
extern "C" void fn_802C2C30(char* p);
extern "C" void fn_802C3AE4(char* p);
extern "C" BOOL fn_801EE24C(char* p);
extern "C" s32 fn_8022D498(s32 a);
extern "C" BOOL fn_80234E30(s32 a);
extern const f32 lbl_80540CAC;
extern const f32 lbl_80540CC8;
extern const f32 lbl_80540CD0;
extern const f32 lbl_80540CF0;
extern const f32 lbl_80540CF4;
extern const f32 lbl_80540CF8;
extern const f32 lbl_80540CFC;
extern "C" void* fn_802D6A9C();
extern "C" void fn_802D7584(void* mgr, s32 index, s32 value);
extern "C" u8 fn_8023A51C(s32 a);
extern "C" void* fn_8023A478(s32 a);
extern "C" s32 fn_8023A240(void);
extern "C" s32 fn_80138A30(s32 a);
extern "C" void fn_8038AD24(s32 a, s32 b, s32 c, s32 d, JGeometry::TVec3<f32> e, s32 f);
extern "C" u8 fn_80388CAC(s32 a, s32 b);
extern "C" u8 fn_8023061C(s32 a, s32 b);
extern "C" u8 fn_80230534(s32 a);
extern u8* lbl_8053AB10;


// KEY0: the key sat dropped too long; send it home.
static inline void key0ReturnHome(char* p) {
    *(s32*)(p + 0x294) = 0;
    *(u8*)(p + 0x2b0) = 1;
    key0Register(p);
    key0LinkHere(p);
}

// KEY0's view of the actor vtable: only slot 0x34 is called here.
struct Key0VObj {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual u8 v11();
};

// KEY0: a carried key that was dropped respawns at its carrier; false if it can't yet.
static inline bool key0Respawn(char* p) {
    if (*(u8*)(p + 0x2b0) == 0) {
        return true;
    }
    *(f32*)(p + 0x14) = lbl_80540CAC;
    if (!(u8)fn_8023F264(*(s32*)(p + 0x23c))) {
        return false;
    }
    if ((u8)fn_8022D75C(*(s32*)(p + 0x23c)) == 1) {
        return false;
    }
    if (!fn_8022BC38(*(s32*)(p + 0x23c), *(s32*)(p + 4), p + 0xc)) {
        if (!fn_802DE764(1, 1, 2)) {
            return false;
        }
        if (*(s32*)(p + 4) != 10) {
            return false;
        }
        if (fn_8023DE58(*(s32*)(p + 0x23c)) != 8) {
            return false;
        }
    }
    f32* src = (f32*)fn_8023E724(*(s32*)(p + 0x23c));
    *(f32*)(p + 0xc) = src[0];
    *(f32*)(p + 0x10) = src[1];
    *(f32*)(p + 0x14) = src[2];
    *(s32*)(p + 4) = fn_8023DE58(*(s32*)(p + 0x23c));
    *(f32*)(p + 0x3c) = *(f32*)(p + 0x40) = *(f32*)(p + 0x44) = lbl_80540C74;
    *(s32*)(p + 0x240) = 5;
    *(f32*)(p + 0x14) = lbl_80540C74;
    u16 kind = fn_8022461C(p + 0xc, *(s32*)(p + 4));
    *(f32*)(p + 0x14) = lbl_80540CAC;
    if (kind == 3 && !(u8)fn_801EE24C(p)) {
        return false;
    }
    *(u8*)(p + 0x2b0) = 0;
    return true;
}
extern "C" void fn_802C4498(char* p) {
    *(u8*)(p + 0x2ad) = 0xff;
    *(u8*)(p + 0x2ac) = 0;
    *(u8*)(p + 0x2b4) = 1;
    if (!key0Respawn(p)) {
        return;
    }
    if (*(u8*)(p + 0xc4) != 0 || (*(u8*)(p + 0xcc) != 0 && *(s32*)(p + 0xd0) != 0)) {
        u32 lo = *(u32*)((char*)fn_802D6A9C() + 0x18);
        u32 hi = *(u32*)((char*)fn_802D6A9C() + 0x14);
        *(u16*)(p + 0x2a8) = ((u8)hi << 8) | (u8)lo;
    } else {
        *(u16*)(p + 0x2a8) = 0xffff;
    }
    JGeometry::TVec3<f32>& pos = *(JGeometry::TVec3<f32>*)(p + 0xc);
    JGeometry::TVec3<f32>& vel = *(JGeometry::TVec3<f32>*)(p + 0x3c);
    switch (*(s32*)(p + 0x240)) {
    case 0:
        *(s32*)(p + 0x294) = 0;
        if ((*(u32*)(p + 0x90) >> 27) != 0 && ((Key0VObj*)p)->v11() != 1) {
            break;
        }
        fn_8013CC50(*(s32*)(p + 4), p + 0xc, lbl_80540CD0, 0x564, 0, 0, 0, 0, 1);
        fn_8013CC50(*(s32*)(p + 4), p + 0xc, lbl_80540C7C, 0x503, 1, 0, 0, 0, 1);
        fn_801F0E34(p, 0x30072, 0);
        fn_801F0D20(p, 3);
        *(s32*)(p + 0x240) = 2;
        fn_801F355C(p);
        *(s32*)(p + 0xb0) = 0x20000;
        break;
    case 1:
        *(s32*)(p + 0x294) = 0;
        if ((*(u32*)(p + 0x90) >> 27) != 0 && ((Key0VObj*)p)->v11() != 1) {
            break;
        }
        *(f32*)(p + 0x14) = lbl_80540CF0;
        *(s32*)(p + 0x240) = 4;
        Actor_CreateByID(fn_801F856C(), 0x53454e32, *(s32*)(p + 4), p + 0xc, 0x3c00, -1, -1);
        fn_801F355C(p);
        key0LinkHere(p);
        break;
    case 2: {
        fn_802C2840((u8*)p);
        s32 room = *(s32*)(p + 4);
        if (key0RoomFlag(room)) {
            if (!*(u8*)(p + 0x2b2)) {
                vel.y += lbl_80540CD0;
                if (vel.y > lbl_80540CB8) {
                    vel.y = lbl_80540CB8;
                }
                pos.add(vel);
                if (((u8 (*)(char*, void*, s32))fn_801F2618)(p, 0, 0)) {
                    *(u8*)(p + 0x2b2) = 1;
                    vel.x = vel.y = vel.z = lbl_80540C74;
                }
            }
        } else {
            *(u8*)(p + 0x2b2) = 1;
        }
        fn_802C3AE4(p);
        break;
    }
    case 3:
        (*(s32*)(p + 0x284))--;
        if (*(s32*)(p + 0x284) == 0) {
            *(s32*)(p + 0x240) = 4;
            *(u8*)(p + 0x2b2) = 0;
            *(f32*)(p + 0x40) = lbl_80540C74;
        }
        break;
    case 4:
        fn_802C2840((u8*)p);
        *(u8*)(p + 0x2ad) = 0xff;
        if (*(u8*)(p + 0xc4) != 0) {
            *(s32*)(p + 0xb0) = 0;
            *(s32*)(p + 0x294) = 0;
            {
                f32* src = (f32*)fn_8023E7B0(*(s32*)(p + 0xc8));
                *(f32*)(p + 0xc) = src[0];
                *(f32*)(p + 0x10) = src[1];
                *(f32*)(p + 0x14) = src[2];
            }
            *(s32*)(p + 4) = fn_8023DE58(*(s32*)(p + 0xc8));
            *(u8*)(p + 0x2ad) = fn_8023BCD4(*(s32*)(p + 0xc8));
            *(s32*)(p + 0x290) = *(s32*)(p + 0xc8);
            if ((u8)fn_8022D75C(*(s32*)(p + 0x290))) {
                if ((u8)fn_80234E30(*(s32*)(p + 0x290))) {
                    *(u8*)(p + 0x2b4) = 0;
                } else {
                    s32 r = fn_8022D498(*(s32*)(p + 0x290));
                    if (r == 4 || r == 7 || r == 8 || r == 9) {
                        *(u8*)(p + 0x2b4) = 0;
                    } else if ((r == 6 || r == 11 || r == 0x14) && *(s32*)(p + 4) >= 8) {
                        *(u8*)(p + 0x2b4) = 0;
                    }
                }
            }
            *(u8*)(p + 0x2b3) = 1;
            *(u8*)(p + 0x2af) = 1;
            *(u8*)(p + 0x2b5) = 1;
        } else {
            *(s32*)(p + 0xb0) = 0x20000;
            fn_802C2C30(p);
        }
        break;
    case 5:
        vel.z += lbl_80540CC8;
        pos.add(vel);
        if (pos.z < lbl_80540C74) {
            pos.z = lbl_80540C74;
            vel.x = vel.y = vel.z = lbl_80540C74;
            *(s32*)(p + 0x240) = 2;
            fn_801F0E34(p, 0x30072, 0);
        }
        break;
    case 6: {
        *(s32*)(p + 0x294) = 0;
        s32 n = *(s32*)((u8*)fn_801F856C() + 0x1008);
        s32 idx;
        s32 i;
        for (i = 0, idx = 0; i < n; idx += 4, i++) {
            *(u8**)(p + 0x244) = (u8*)*(u32*)((u8*)fn_801F856C() + 8 + idx);
            u8* o = *(u8**)(p + 0x244);
            if (o != 0 && *(s32*)(p + 0x198) != *(s32*)(o + 0x198) && *(s32*)(o + 4) == *(s32*)(p + 4) &&
                (f32)__fabs(*(f32*)(o + 0xc) - *(f32*)(p + 0xc)) < lbl_80540C88 &&
                (f32)__fabs(*(f32*)(o + 0x10) - *(f32*)(p + 0x10)) < lbl_80540C88) {
                *(u8*)(p + 0x2ad) = 0xb4;
                *(s32*)(p + 0x28c) = i;
                *(s32*)(p + 0x240) = 7;
                return;
            }
        }
        *(u8*)(p + 0x11c) = 0;
        break;
    }
    case 7: {
        *(s32*)(p + 0x294) = 0;
        s32 idx = *(s32*)(p + 0x28c);
        if (idx >= 0) {
            u8* mgr = (u8*)fn_801F856C() + idx * 4;
            *(u8**)(p + 0x244) = *(u8**)(mgr + 8);
            if (*(u8**)(p + 0x244) != 0) {
                u8* o = *(u8**)(p + 0x244);
                *(f32*)(p + 0x248) = *(f32*)(o + 0xc);
                *(f32*)(p + 0x24c) = *(f32*)(o + 0x10);
                *(f32*)(p + 0x250) = *(f32*)(o + 0x14);
                s32 room = *(s32*)(*(u8**)(p + 0x244) + 4);
                if (room < 8 && *(s32*)(p + 4) == 8) {
                    struct Key0Rect {
                        f32 x0, y0, x1, y1;
                    };
                    u8* base = (u8*)fn_802D6A9C();
                    Key0Rect* off;
                    if (room < 8) {
                        off = (Key0Rect*)(base + 0xcc);
                    } else {
                        off = (Key0Rect*)(base + 0xdc);
                    }
                    Key0Rect r = *off;
                    *(f32*)(p + 0x248) = *(f32*)(*(u8**)(p + 0x244) + 0xc) - r.x0;
                    *(f32*)(p + 0x24c) = *(f32*)(*(u8**)(p + 0x244) + 0x10) - r.y0;
                }
                *(f32*)(p + 0xc) = *(f32*)(p + 0x248);
                *(f32*)(p + 0x10) = *(f32*)(p + 0x24c);
                *(f32*)(p + 0x14) = *(f32*)(p + 0x250);
            } else {
                fn_801F0D20(p, 3);
                *(s32*)(p + 0x28c) = -1;
                *(f32*)(p + 0x44) = lbl_80540CF4;
            }
        }
        if (*(s32*)(p + 0x28c) >= 0) {
            break;
        }
        pos.add(vel);
        if (pos.z > lbl_80540C74) {
            vel.z -= lbl_80540C7C;
            break;
        }
        s32 kind = *(s32*)(p + 0x280);
        if (kind < 0x10) {
            pos.z = lbl_80540C74;
            vel.z = lbl_80540C74;
            *(s32*)(p + 0x27c) = 0;
            *(u8*)(p + 0x2ad) = 0xff;
            *(s32*)(p + 0x240) = 2;
            break;
        }
        Actor_CreateByID(fn_801F856C(), 0x4c535449, *(s32*)(p + 4), p + 0xc, (kind - 15) | 0x880100, -1, -1);
        *(u8*)(p + 0x11c) = 0;
        break;
    }
    case 8:
        *(s32*)(p + 0x294) = 0;
        if (fn_8022F9E4(*(s32*)(p + 0x278), *(void**)(p + 0x198), 0, 0)) {
            *(s32*)(p + 0x240) = 4;
        }
        break;
    case 9: {
        s32 i;
        *(s32*)(p + 0x294) = i = 0;
        for (; i < 4; i++) {
            if ((u8)fn_8023A51C(i) == 1) {
                s32 room = *(s32*)(p + 4);
                if (room == fn_8023DE58(i)) {
                    f32* q = (f32*)fn_8023A478(i);
                    f32 dx = q[0] - *(f32*)(p + 0xc);
                    f32 dy = q[1] - *(f32*)(p + 0x10);
                    f32 dx2 = dx * dx;
                    f32 dy2 = dy * dy;
                    if (!(dx2 + dy2 > lbl_80540CF8)) {
                        switch (fn_8023A240() ^ 1) {
                        case 0:
                            vel = JGeometry::TVec3<f32>(lbl_80540C98, lbl_80540C74, lbl_80540C94);
                            break;
                        case 1:
                            vel = JGeometry::TVec3<f32>(lbl_80540C8C, lbl_80540C74, lbl_80540C94);
                            break;
                        case 2:
                            vel = JGeometry::TVec3<f32>(lbl_80540C74, lbl_80540C98, lbl_80540C94);
                            break;
                        case 3:
                            vel = JGeometry::TVec3<f32>(lbl_80540C74, lbl_80540C8C, lbl_80540C94);
                            break;
                        default:
                            vel = JGeometry::TVec3<f32>(lbl_80540C74, lbl_80540C74, lbl_80540C94);
                            break;
                        }
                        *(s32*)(p + 0xb0) = 0x20000;
                        *(s32*)(p + 0x27c) = 6;
                        *(s32*)(p + 0x240) = 4;
                        fn_802D7584(fn_802D6A9C(), *(s32*)(p + 0x16c), 1);
                        *(s32*)(p + 0x288) = 300;
                        *(f32*)(p + 0x10) += lbl_80540CFC;
                        *(f32*)(p + 0x14) = lbl_80540CFC;
                        return;
                    }
                }
            }
        }
        break;
    }
    case 10:
        *(s32*)(p + 0xb0) = 0;
        *(s32*)(p + 0x294) = 0;
        if (*(u8*)(p + 0xcc) != 0) {
            {
                f32* src = (f32*)fn_8023E724(*(s32*)(p + 0xd0));
                *(f32*)(p + 0xc) = src[0];
                *(f32*)(p + 0x10) = src[1];
                *(f32*)(p + 0x14) = src[2];
            }
            *(s32*)(p + 4) = fn_8023DE58(*(s32*)(p + 0xd0));
            *(u8*)(p + 0x2ad) = fn_8023BCD4(*(s32*)(p + 0xd0));
            if (fn_80138A30(lbl_8053AAF8) == 1 && *(s32*)(p + 0x29c) >= 1 &&
                fn_8022F514(*(s32*)(p + 0x29c)) == 1) {
                u16 kind = fn_8022461C(p + 0xc, *(s32*)(p + 4));
                if (kind != 0xd && kind != 0x3b &&
                    fn_8022F9E4(*(s32*)(p + 0x29c), *(void**)(p + 0x198), 0, 0)) {
                    *(s32*)(p + 0x29c) = -1;
                    *(s32*)(p + 0x240) = 4;
                }
            }
        } else {
            *(s32*)(p + 0x240) = 4;
        }
        break;
    case 11:
        fn_8022FE80(*(s32*)(p + 0x2a4), *(s32*)(p + 4), *(s32*)(p + 0x198), 1, 0);
        fn_8038AD24(*(s32*)(p + 0x2a4), 0x168, *(s32*)(p + 0x198), *(s32*)(p + 4), pos, 4);
        *(s32*)(p + 0x240) = 12;
        return;
    case 12:
        fn_8022FE80(*(s32*)(p + 0x2a4), *(s32*)(p + 4), *(s32*)(p + 0x198), 1, 0);
        if (!fn_80388CAC(*(s32*)(p + 0x2a4), *(s32*)(p + 0x198))) {
            return;
        }
        if (*(u8*)(lbl_8053AAF8 + 0x7e) == 1) {
            if (fn_8023061C(*(s32*)(p + 0x2a0), 0) == 1) {
                *(s32*)(p + 0x240) = 2;
            }
        } else if (fn_80230534(0) == 1) {
            *(s32*)(p + 0x240) = 2;
        }
        return;
    }
    if (*(s32*)(p + 0x240) >= 2 && *(s32*)(p + 0x240) != 9 && *(s32*)(p + 4) < 8) {
        fn_8030C210(*(s32*)(lbl_8053AB10 + 0x24),
                    JGeometry::TVec3<f32>(*(f32*)(p + 0xc), *(f32*)(p + 0x10) - *(f32*)(p + 0x14), lbl_80540C74));
    }
    if (*(u8*)(p + 0x2b5) == 0) {
        return;
    }
    (*(s32*)(p + 0x294))++;
    if (*(s32*)(p + 0x294) < 0x2c88) {
        return;
    }
    key0ReturnHome(p);
}

extern "C" void fn_802C5284(char* p) {
    key0Register(p);
}

extern "C" u8 fn_802D7544(void* mgr, s32 index);
extern "C" void fn_802D7584(void* mgr, s32 index, s32 value);
extern "C" u8 fn_8022F9E4(s32 index, void* a, s32 b, s32 c);
extern "C" u8 fn_802D800C(void* mgr, s32 index);
extern "C" u8 fn_802DCD0C(void* mgr);
#pragma opt_lifetimes off
extern "C" void fn_802C52DC(u8* p) {
    u32 packed;
    s32 x18;
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
        x18 = *(u32*)((u8*)fn_802D6A9C() + 0x18);
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
        packed = key0PackActorFlags(p);
        if (!fn_802DCD0C(fn_802D6A9C())) {
            x18 = *(u32*)((u8*)fn_802D6A9C() + 0x18);
            packed |= ((x18 & 0xff) << 8) | ((*(u32*)((u8*)fn_802D6A9C() + 0x14) & 0xff) << 16);
        } else {
            packed = *(u16*)(p + 0x2aa) << 8;
        }
        Key0Pt key(*(f32*)(p + 0x230), *(f32*)(p + 0x234));
        Key0Pt pos(*(f32*)(p + 0xc), *(f32*)(p + 0x10));
        u32 id = *(u32*)(p + 0x238);
        key0LinkPoints(key, pos, packed, id);
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
        b = -6.0f;
        a = -4.0f;
        *(f32*)(p + 0x60) = a;
        *(f32*)(p + 0x64) = b;
        f32 d;
        f32 c;
        c = 4.0f;
        d = 6.0f;
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
    s32 x18End = *(u32*)((u8*)fn_802D6A9C() + 0x18);
    *(u16*)(p + 0x2aa) = (x18End & 0xff) | ((*(u32*)((u8*)fn_802D6A9C() + 0x14) & 0xff) << 8);
    *(s32*)(p + 0x2a0) = -1;
    if (flag == 0) {
        *(s32*)(p + 0x2a4) = -1;
    }
}
#pragma opt_lifetimes reset
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
