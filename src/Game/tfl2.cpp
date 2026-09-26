// TU 0x802f184c-0x802f3b74 (actor TFL2).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// ---- Tfl2_dtor_802F184C.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804AA628[];

extern "C" void* fn_802F184C(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804AA628;
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

struct Tfl2Rect { f32 x0, y0, x1, y1; };
struct Tfl2RoomCfg {
    u8 pad[0xcc];
    Tfl2Rect rectA;
    Tfl2Rect rectB;
};
struct Tfl2Root { u8 pad[0x20]; void* x20; };
extern "C" Tfl2RoomCfg* fn_802D6A9C(void);
extern "C" void fn_802F9974(void* layer, u32 room, u32 tile, s32 kind);
extern Tfl2Root* lbl_8053AB10;
extern u8* lbl_8053AAF8;
extern const s32 lbl_8046F788[];
extern const s32 lbl_8046F7A4[];

// TFL2 init (vtable slot 1)
static inline s32 tfl2Clamp(s32 v) {
    s32 r = v;
    if (v < 0) {
        r = 0;
    } else if (v >= 0x200) {
        r = 0x1ff;
    }
    return r;
}

extern "C" void fn_802F368C(u8* this_) {
    *(u32*)(this_ + 0x234) = *(u32*)(this_ + 0x90) & 0xf;
    *(u32*)(this_ + 0x238) = (*(u32*)(this_ + 0x90) >> 4) & 0xf;
    *(u32*)(this_ + 0x240) = (*(u32*)(this_ + 0x90) >> 12) & 0xfff;
    *(f32*)(this_ + 0x248) = 0.0f;
    switch (*(s32*)(this_ + 0x234)) {
    default:
    case 6:
        *(f32*)(this_ + 0x60) = -32.0f;
        *(f32*)(this_ + 0x64) = -32.0f;
        *(f32*)(this_ + 0x68) = 32.0f;
        *(f32*)(this_ + 0x6c) = 32.0f;
        break;
    case 2:
        *(f32*)(this_ + 0x60) = -40.0f;
        *(f32*)(this_ + 0x64) = -32.0f;
        *(f32*)(this_ + 0x68) = 40.0f;
        *(f32*)(this_ + 0x6c) = 32.0f;
        break;
    case 3:
        *(f32*)(this_ + 0x60) = -24.0f;
        *(f32*)(this_ + 0x64) = -32.0f;
        *(f32*)(this_ + 0x68) = 24.0f;
        *(f32*)(this_ + 0x6c) = 32.0f;
        break;
    case 4:
    case 5:
        *(f32*)(this_ + 0x60) = -16.0f;
        *(f32*)(this_ + 0x64) = -50.0f;
        *(f32*)(this_ + 0x68) = 24.0f;
        *(f32*)(this_ + 0x6c) = 50.0f;
        *(f32*)(this_ + 0x248) = -0.06f;
        break;
    }
    *(s32*)(this_ + 0x244) = 20;
    if (lbl_8053AAF8[0x7f] == 1) {
        *(s16*)(this_ + 0x252) = 12;
    } else {
        *(s16*)(this_ + 0x252) = 13;
    }
    if (*(s32*)(this_ + 0x234) >= 2) {
        f32 y;
        f32 x = *(f32*)(this_ + 0xc);
        s32 room = *(s32*)(this_ + 0x4);
        Tfl2RoomCfg* cfg = fn_802D6A9C();
        Tfl2Rect r = room < 8 ? cfg->rectA : cfg->rectB;
        for (s32 i = 0; i < lbl_8046F788[*(s32*)(this_ + 0x234)]; i++) {
            s32 tx = (s32)(x - r.x0);
            y = *(f32*)(this_ + 0x10);
            for (s32 j = 0; j < lbl_8046F7A4[*(s32*)(this_ + 0x234)]; j++) {
                s32 ty = (s32)(y - r.y0);
                s32 cx = tfl2Clamp(tx);
                if (ty < 0) {
                    ty = 0;
                } else if (ty >= 0x200) {
                    ty = 0x1ff;
                }
                s32 cy = ty;
                fn_802F9974(lbl_8053AB10->x20, *(u32*)(this_ + 0x4),
                            ((cy << 1) & 0x200) | (cx & 0x100) | (cy & 0xf0) | ((cx >> 4) & 0xf), 6);
                y += 16.0f;
            }
            x += 16.0f;
        }
    }
    *(s32*)(this_ + 0x230) = 0;
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
