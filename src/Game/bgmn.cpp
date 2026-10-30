// TU 0x802e5c44-0x802e694c (actor BGMN).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// ---- Bgmn_dtor_802E5C44.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804A9DA0[];

extern "C" void* fn_802E5C44(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804A9DA0;
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

struct BgmnVt {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual u8 v11();
};

struct BgmnVec {
    f32 x, y, z;
};

static inline bool bgmnInArea(const BgmnVec& p, f32 x0, f32 y0, f32 x1, f32 y1) {
    bool r = false;
    if (p.x >= x0 && p.y >= y0 && p.x < x1 && p.y < y1) {
        r = true;
    }
    return r;
}

// ---- Bgmn_EmptyHook.cpp ----
// Bgmn_EmptyHook - BGMN: empty no-op override (0x4, leaf, no extab needed)
extern "C" {

void Bgmn_EmptyHook(void) {}

extern "C" s32 fn_8023DE58(s32);
extern "C" void* fn_8023E724(s32);
extern "C" s32 fn_8022EA0C(s32);
extern void* lbl_8053AAF8;
extern "C" void fn_802E5CA8(char* p) {
    f32 minX = *(f32*)(p + 0x60) + *(f32*)(p + 0xc);
    f32 minY = *(f32*)(p + 0x64) + *(f32*)(p + 0x10);
    f32 maxX = *(f32*)(p + 0x68) + *(f32*)(p + 0xc);
    f32 maxY = *(f32*)(p + 0x6c) + *(f32*)(p + 0x10);
    *(s32*)(p + 0x258) = -1;
    *(s32*)(p + 0x25c) = -1;
    *(u16*)(p + 0x94) = 0xffff;
    if (*(u32*)(p + 0x240) != 2) {
        s32 i;
        if (((u8*)lbl_8053AAF8)[0x7e] == 1) {
            for (i = 0; i < 4; i++) {
                if (((u8*)lbl_8053AAF8)[0x82] & (1 << i)) {
                    if (*(s32*)(p + 4) == fn_8023DE58(i)) {
                        f32* box = (f32*)fn_8023E724(i);
                        if (box[0] >= minX && box[1] >= minY && box[0] < maxX && box[1] < maxY) {
                            *(s32*)(p + 0x258) = i;
                            *(u16*)(p + 0x94) = (u16)i;
                            break;
                        }
                    }
                }
            }
        }
    }
}

}

extern "C" void* fn_802D6A9C(void);
// fn_802E6638 - BGMN: setParams(). Area size comes from the spawn params
// (in 16-unit tiles).
extern const f32 lbl_80541228;
extern "C" void fn_802E6638(char* p) {
    *(u32*)(p + 0x234) = *(u32*)(p + 0x90) & 0x7f;
    *(s32*)(p + 0x238) = ((*(u32*)(p + 0x90) >> 22) & 0x1f) + 1;
    *(s32*)(p + 0x23c) = ((*(u32*)(p + 0x90) >> 17) & 0x1f) + 1;
    *(u32*)(p + 0x240) = (*(u32*)(p + 0x90) >> 12) & 0x1f;
    *(u32*)(p + 0x250) = (*(u32*)(p + 0x90) >> 7) & 1;
    *(s32*)(p + 0x248) = *(s32*)((char*)fn_802D6A9C() + 0x34);
    f32 h = lbl_80541228 * *(s32*)(p + 0x23c);
    f32 w = lbl_80541228 * *(s32*)(p + 0x238);
    *(f32*)(p + 0x60) = -w;
    *(f32*)(p + 0x64) = -h;
    *(f32*)(p + 0x68) = w;
    *(f32*)(p + 0x6c) = h;
    *(u16*)(p + 0x94) = 0xffff;
    *(s32*)(p + 0x230) = 0;
    *(s32*)(p + 0x24c) = -1;
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
