// TU 0x802c1614-0x802c5950 (actor KEY0).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

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

// ---- fn_802C1614_dtor.cpp ----
extern "C" void dtor_801F593C(void* this_, int flag);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804A8CD8[];

extern "C" void* fn_802C1614(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A8CD8;
        dtor_801F593C(this_, 0);
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
        if (*(u8*)(p + 0x2af) == 0) {
            return;
        }
        if (*(u16*)(p + 0x2a8) != 0xffff) {
            key0RecordDrop(p);
            *(u16*)(p + 0x2a8) = 0xffff;
            *(u8*)(p + 0x2af) = 0;
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
        if (fn_8023EF50(*(s32*)(p + 0x23c)) != me) {
            return;
        }
    } else if (fn_8022F478(*(s32*)(p + 0xd0)) == 1 && *(s32*)(p + 0x240) == 10) {
        if (*(u8*)(p + 0xcc) == 0) {
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
extern "C" s32 fn_801F9484(void* base, u32 fourCC, u32 owner, void* posPtr, u32 param, s32 p6, s32 p7);
extern "C" void fn_8013CC50(s32 room, void* pos, f32 scale, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern const f32 lbl_80540C7C;
extern "C" void fn_802C1DFC(char* p) {
    s32 room = *(s32*)(p + 0x4);
    if (room >= 8) {
        fn_801F9484(fn_801F856C(), 0x4b4d5249, room, p + 0xc, 0, -1, -1);
    } else {
        fn_8013CC50(room, p + 0xc, lbl_80540C7C, 0x503, 1, 0, 0, 0, 1);
    }
    key0Register(p);
    *(u8*)(p + 0x11c) = 0;
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
