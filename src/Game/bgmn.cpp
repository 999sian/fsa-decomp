// TU 0x802e5c44-0x802e694c (actor BGMN).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"
#include "JSystem/JGeometry/Vec.h"

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

extern "C" u8 fn_80230188(s32);
extern "C" void* fn_801F856C(void);
extern "C" void fn_80138B7C(void*);
extern "C" void fn_80458F04(void*, u32);
extern "C" void fn_80458FF0(void*, u32, s32, s32);
extern "C" void fn_80458F9C(void*, s32);
extern "C" void fn_802D7970(void*, s32);
extern "C" void* fn_802D6A9C(void);
extern "C" void* lbl_8053AF80;
extern "C" u32 lbl_8046F1C8[];
extern const f32 lbl_80541228;

extern "C" void* lbl_8053AAF8;

static inline bool bgmnPlayerOn(s32 i) {
    return (((u8*)lbl_8053AAF8)[0x82] & (u8)(1 << i)) != 0;
}

static inline bool bgmnInArea(const JGeometry::TVec3<f32>& p, f32 x0, f32 y0, f32 x1, f32 y1) {
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
    s32 n;
    s32 j;
    u32 mode;
    s32 i;
    s32 k;
    f32 minX;
    f32 minY;
    f32 maxX;
    f32 maxY;
    f32 x;
    f32 y;
    y = *(f32*)(p + 0x10);
    minY = *(f32*)(p + 0x64);
    maxY = *(f32*)(p + 0x6c);
    x = *(f32*)(p + 0xc);
    minY += y;
    minX = *(f32*)(p + 0x60);
    maxY += y;
    maxX = *(f32*)(p + 0x68);
    minX += x;
    maxX += x;
    *(s32*)(p + 0x258) = -1;
    *(s32*)(p + 0x25c) = -1;
    *(u16*)(p + 0x94) = 0xffff;
    if (*(s32*)(p + 0x240) != 2) {
        if (((u8*)lbl_8053AAF8)[0x7e] == 1) {
            for (i = 0; i < 4; i++) {
                u8 on = bgmnPlayerOn(i);
                if (on == 1 && *(s32*)(p + 4) == fn_8023DE58(i)) {
                    JGeometry::TVec3<f32> pt(*(JGeometry::TVec3<f32>*)fn_8023E724(i));
                    if (bgmnInArea(pt, minX, minY, maxX, maxY)) {
                        *(s32*)(p + 0x258) = i;
                        *(u16*)(p + 0x94) = i;
                        break;
                    }
                }
            }
            if (*(s32*)(p + 0x258) >= 0) {
                *(s32*)(p + 0x25c) = fn_8022EA0C(*(s32*)(p + 0x258));
            }
        } else {
            *(s32*)(p + 0x25c) = fn_8022EA0C(0);
            if (*(s32*)(p + 4) == fn_8023DE58(*(s32*)(p + 0x25c))) {
                JGeometry::TVec3<f32> pt(*(JGeometry::TVec3<f32>*)fn_8023E724(*(s32*)(p + 0x25c)));
                if (bgmnInArea(pt, minX, minY, maxX, maxY)) {
                    *(s32*)(p + 0x258) = *(s32*)(p + 0x25c);
                    *(u16*)(p + 0x94) = *(s32*)(p + 0x25c);
                }
            }
        }
    } else if (((u8*)lbl_8053AAF8)[0x7e] == 1) {
        for (i = 0; i < 4; i++) {
            if (*(s32*)(p + 4) == fn_8023DE58(i)) {
                JGeometry::TVec3<f32> pt(*(JGeometry::TVec3<f32>*)fn_8023E724(i));
                if (bgmnInArea(pt, minX, minY, maxX, maxY)) {
                    *(s32*)(p + 0x258) = i;
                    *(u16*)(p + 0x94) = i;
                    break;
                }
            }
        }
        if (*(s32*)(p + 0x258) >= 0) {
            *(s32*)(p + 0x25c) = fn_8022EA0C(*(s32*)(p + 0x258));
            if (*(s32*)(p + 4) == fn_8023DE58(*(s32*)(p + 0x25c))) {
                *(s32*)(p + 0x258) = *(s32*)(p + 0x25c);
                *(u16*)(p + 0x94) = *(s32*)(p + 0x25c);
            }
        }
    } else {
        *(s32*)(p + 0x25c) = fn_8022EA0C(0);
        if (*(s32*)(p + 4) == fn_8023DE58(*(s32*)(p + 0x25c))) {
            *(s32*)(p + 0x258) = *(s32*)(p + 0x25c);
            *(u16*)(p + 0x94) = *(s32*)(p + 0x25c);
        }
    }
    if (*(s32*)(p + 0x25c) >= 0) {
        *(s32*)(p + 0x254) = fn_8023DE58(*(s32*)(p + 0x25c));
    } else {
        *(s32*)(p + 0x254) = -1;
    }
    if (((u8*)lbl_8053AAF8)[0x7e] == 1) {
        if (*(s32*)(p + 0x258) < 0) {
            if (*(s32*)(p + 0x25c) >= 0 && fn_80230188(*(s32*)(p + 0x25c))) {
                *(s32*)(p + 0x258) = *(s32*)(p + 0x24c);
            } else {
                char* mgr = (char*)fn_801F856C();
                j = 0;
                n = *(s32*)(mgr + 0x1008);
                for (; j < n; j++) {
                    char* o = *(char**)((char*)fn_801F856C() + j * 4 + 8);
                    if (o != 0 && *(u32*)(o + 0x1a0) == 'BGMN') {
                        u32 v = *(u32*)(o + 0x90);
                        s32 room = *(s32*)(o + 4);
                        if ((v & 0x7f) == *(u32*)(p + 0x234)) {
                            mode = (v >> 12) & 0x1f;
                            f32 w = lbl_80541228 * (f32)(s32)(((v >> 22) & 0x1f) + 1);
                            f32 h = lbl_80541228 * (f32)(s32)(((v >> 17) & 0x1f) + 1);
                            JGeometry::TVec3<f32> opos(*(JGeometry::TVec3<f32>*)(o + 0xc));
                            *(f32*)(p + 0x60) = -w;
                            *(f32*)(p + 0x64) = -h;
                            *(f32*)(p + 0x68) = w;
                            *(f32*)(p + 0x6c) = h;
                            f32 x0 = *(f32*)(p + 0x60) + opos.x;
                            f32 y0 = *(f32*)(p + 0x64) + opos.y;
                            f32 x1 = *(f32*)(p + 0x68) + opos.x;
                            f32 y1 = *(f32*)(p + 0x6c) + opos.y;
                            for (k = 0; k < 4; k++) {
                                if (room == fn_8023DE58(k)) {
                                    if (mode == 2) {
                                        return;
                                    }
                                    JGeometry::TVec3<f32> pt(*(JGeometry::TVec3<f32>*)fn_8023E724(k));
                                    if (bgmnInArea(pt, x0, y0, x1, y1)) {
                                        return;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if (*(s32*)(p + 0x258) >= 0 && *(s32*)(p + 4) != fn_8023DE58(*(s32*)(p + 0x258))) {
            *(s32*)(p + 0x258) = -1;
        }
        if (*(s32*)(p + 0x250) != 0) {
            *(s32*)(p + 0x258) = -1;
        }
    } else if (*(s32*)(p + 0x254) != *(s32*)(p + 4)) {
        s32 free = 1;
        n = *(s32*)((char*)fn_801F856C() + 0x1008);
        for (j = 0; j < n; j++) {
            char* o = *(char**)((char*)fn_801F856C() + j * 4 + 8);
            if (o != 0 && j != *(s32*)(p + 0x198) && *(u32*)(o + 0x1a0) == 'BGMN' && *(s32*)(p + 0x254) == *(s32*)(o + 4)) {
                if (*(u16*)(o + 0x94) != 0xffff) {
                    free = 0;
                } else if (*(u32*)(p + 0x234) == (*(u32*)(o + 0x90) & 0x7f)) {
                    free = 0;
                }
            }
        }
        if (free == 0) {
            return;
        }
    } else if (*(s32*)(p + 0x258) < 0) {
        if (fn_80230188(*(s32*)(p + 0x25c))) {
            *(s32*)(p + 0x258) = *(s32*)(p + 0x24c);
        } else {
            JGeometry::TVec3<f32> pt(*(JGeometry::TVec3<f32>*)fn_8023E724(*(s32*)(p + 0x25c)));
            n = *(s32*)((char*)fn_801F856C() + 0x1008);
            for (j = 0; j < n; j++) {
                char* o = *(char**)((char*)fn_801F856C() + j * 4 + 8);
                if (o != 0 && *(u32*)(o + 0x1a0) == 'BGMN' && *(s32*)(p + 0x254) == *(s32*)(o + 4)) {
                    u32 v = *(u32*)(o + 0x90);
                    if (((v >> 12) & 0x1f) == 2) {
                        return;
                    }
                    if ((v & 0x7f) == *(u32*)(p + 0x234)) {
                        f32 w = lbl_80541228 * (f32)(s32)(((v >> 22) & 0x1f) + 1);
                        f32 h = lbl_80541228 * (f32)(s32)(((v >> 17) & 0x1f) + 1);
                        JGeometry::TVec3<f32> opos(*(JGeometry::TVec3<f32>*)(o + 0xc));
                        *(f32*)(p + 0x60) = -w;
                        *(f32*)(p + 0x64) = -h;
                        *(f32*)(p + 0x68) = w;
                        *(f32*)(p + 0x6c) = h;
                        if (bgmnInArea(pt, *(f32*)(p + 0x60) + opos.x, *(f32*)(p + 0x64) + opos.y, *(f32*)(p + 0x68) + opos.x, *(f32*)(p + 0x6c) + opos.y)) {
                            return;
                        }
                    }
                }
            }
        }
    }
    u32 cur = *(u32*)((char*)lbl_8053AF80 + 0x60);
    switch (*(s32*)(p + 0x230)) {
    case 0: {
        u8 go = 0;
        if (*(s32*)(p + 0x240) == 0 || *(s32*)(p + 0x240) == 3 || *(s32*)(p + 0x240) == 4) {
            if (*(s32*)(p + 0x258) >= 0 || (*(u32*)(p + 0x90) >> 27) == 0 || ((BgmnVt*)p)->v11()) {
                go = 1;
            }
        } else if (*(s32*)(p + 0x258) >= 0) {
            go = 1;
        }
        if (go == 1) {
            if (*((u8*)fn_802D6A9C() + 0x131f4) != 0) {
                return;
            }
            if (*(s32*)(p + 0x240) == 4 || (cur != 0x1000021 && cur != 0x1000019)) {
                s32 s = *(s32*)(p + 0x234);
                if (s != 0x11) {
                    if (s == 0x14 || s == 0x1e) {
                        fn_80458F04(lbl_8053AF80, lbl_8046F1C8[s]);
                    } else {
                        fn_80458FF0(lbl_8053AF80, lbl_8046F1C8[s], 0, 0);
                    }
                    s = *(s32*)(p + 0x234);
                    if (s < 0x11 || s == 0x26) {
                        fn_802D7970(fn_802D6A9C(), s);
                    }
                } else {
                    fn_80458F9C(lbl_8053AF80, 0x3c);
                }
                if (*(s32*)(p + 0x240) == 3 || *(s32*)(p + 0x240) == 4) {
                    *(u8*)(p + 0x11c) = 0;
                } else {
                    *(s32*)(p + 0x230) = 1;
                    if (*(s32*)(p + 0x258) >= 0) {
                        *(s32*)(p + 0x24c) = *(s32*)(p + 0x258);
                    }
                }
            }
        }
        break;
    }
    case 1:
        if (*(s32*)(p + 0x240) != 0 && *(s32*)(p + 0x258) < 0) {
            fn_80138B7C(lbl_8053AAF8);
            *(s32*)(p + 0x230) = 0;
            *(s32*)(p + 0x24c) = -1;
        } else if (*(s32*)(p + 0x234) != 0x11 && cur != lbl_8046F1C8[*(s32*)(p + 0x234)] && cur != 0x1000021 && cur != 0x1000019) {
            fn_80458FF0(lbl_8053AF80, lbl_8046F1C8[*(s32*)(p + 0x234)], 0, 0);
        }
        break;
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
