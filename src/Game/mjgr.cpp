// TU 0x802e7db4-0x802e8dfc (actor MJGR).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"
#include "JSystem/JGeometry/Box.h"
#include <math.h>

static inline f64 sqrtStep(f64 tmpd, f32 mag) {
    return tmpd * 0.5 * (3.0 - mag * (tmpd * tmpd));
}
static inline f32 dolsqrtfull(f32 mag) {
    if (mag > 0.0f) {
        f64 tmpd = __frsqrte(mag);
        tmpd = sqrtStep(tmpd, mag);
        tmpd = sqrtStep(tmpd, mag);
        tmpd = sqrtStep(tmpd, mag);
        return mag * tmpd;
    } else if (mag < 0.0) {
        return NAN;
    } else if (fpclassify(mag) == 1) {
        return NAN;
    } else {
        return mag;
    }
}

// ---- EmptyHook_802E7DB4.cpp ----
// EmptyHook_802E7DB4 - actor @lbl_804A9FB0: empty no-op override (0x4, leaf, no extab needed)
extern "C" {

void EmptyHook_802E7DB4(void) {}

}

extern "C" void* fn_802D6A9C(void);

// ---- fn_802E7DB8: look for an opened key block (KEY0) overlapping us ----
extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F78F4(void* mgr, u32 id, s32 start);
extern "C" char* fn_801F666C(void* mgr, s32 id);
extern "C" void* fn_801EE434(void* handle);
extern "C" void* fn_8013CC50(u32 room, JGeometry::TVec3<f32>* pos, s32 kind, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale);
extern "C" void fn_801F0E34(void* p, u32 se, s32 b);
extern "C" void fn_802C5284(char* p);
extern "C" void fn_801F34DC(char* p);
extern const f32 lbl_80541260;
extern const f32 lbl_80541264;
extern const f32 lbl_80541268;
extern const f32 lbl_8054126C;

// near-match (98.6%): search id copy and float regs in the overlap test differ
extern "C" u8 fn_802E7DB8(char* p) {
    char* key;
    s32 id = -1;
    JGeometry::TVec2<f32> org(*(f32*)(p + 0xc), *(f32*)(p + 0x10));
    JGeometry::TBox2<f32>* hb = (JGeometry::TBox2<f32>*)(p + 0x60);
    hb->set(lbl_80541260, lbl_80541260, lbl_80541264, lbl_80541264);
    JGeometry::TBox2<f32> me(*hb);
    me.addPos(org);
    JGeometry::TVec3<f32> pos;
    while (true) {
        s32 found = fn_801F78F4(fn_801F856C(), 'KEY0', id);
        id = found;
        if (found < 0) {
            return 0;
        }
        key = fn_801F666C(fn_801F856C(), found);
        if (key == 0 || *(s32*)(key + 0x280) != 6) {
            continue;
        }
        pos = *(JGeometry::TVec3<f32>*)(key + 0xc);
        if (pos.z != lbl_80541268) {
            continue;
        }
        JGeometry::TBox2<f32> kb(*(JGeometry::TBox2<f32>*)(key + 0x60));
        kb.addPos(pos.x, pos.y);
        if (kb.intersect(me)) {
            break;
        }
    }
    *(s32*)(p + 0x244) = 1;
    *(s32*)(p + 0x24c) = 20;
    JGeometry::TVec3<f32> fx(pos);
    if (*(void**)(p + 0x230) != 0) {
        fn_801EE434(*(void**)(p + 0x230));
    }
    if (*(void**)(p + 0x234) != 0) {
        fn_801EE434(*(void**)(p + 0x234));
    }
    if (*(void**)(p + 0x238) != 0) {
        fn_801EE434(*(void**)(p + 0x238));
    }
    if (*(void**)(p + 0x23c) != 0) {
        fn_801EE434(*(void**)(p + 0x23c));
    }
    if (*(void**)(p + 0x240) != 0) {
        fn_801EE434(*(void**)(p + 0x240));
    }
    *(s32*)(p + 0x230) = 0;
    *(s32*)(p + 0x234) = 0;
    *(s32*)(p + 0x238) = 0;
    *(s32*)(p + 0x23c) = 0;
    *(s32*)(p + 0x240) = 0;
    fn_8013CC50(*(u32*)(p + 0x4), &fx, 0x85, 0, 0, 0, 0, 1, lbl_8054126C);
    fn_8013CC50(*(u32*)(p + 0x4), &fx, 0x86, 0, 0, 0, 0, 1, lbl_8054126C);
    fn_8013CC50(*(u32*)(p + 0x4), &fx, 0x87, 0, 0, 0, 0, 1, lbl_8054126C);
    fn_801F0E34(p, 0x30069, 0);
    fn_802C5284(key);
    *(u8*)(key + 0x11c) = 0;
    fn_801F34DC(p);
    return 1;
}

// ---- fn_802E80A0: point sparkle effects at the nearest opened key block ----
extern "C" void fn_8013CB44(void* h, JGeometry::TVec3<f32>* pos, s32 a, s32 b, s32 c);
extern "C" JGeometry::TVec3<f32>* fn_8023E7B0(s32 holder);
extern const f32 lbl_80541288;

extern "C" void fn_802E80A0(char* p) {
    s32 id;
    s32 best;
    s32 bestDist;
    best = -1;
    bestDist = -1;
    id = -1;
    JGeometry::TVec3<f32> pos;
    while (true) {
        id = fn_801F78F4(fn_801F856C(), 'KEY0', id);
        if (id < 0) {
            break;
        }
        char* key = fn_801F666C(fn_801F856C(), id);
        if (key == 0 || *(s32*)(key + 0x280) != 6 || *(s32*)(key + 0x240) == 0) {
            continue;
        }
        pos = *(JGeometry::TVec3<f32>*)(key + 0xc);
        f32 dx = pos.x - *(f32*)(p + 0xc);
        f32 dy = pos.y - *(f32*)(p + 0x10);
        s32 d = dolsqrtfull(dx * dx + dy * dy);
        if (d > 0x40) {
            d = 0x40;
        }
        if (bestDist < 0) {
            bestDist = d;
            best = id;
        } else if (d < bestDist) {
            bestDist = d;
            best = id;
        }
    }
    if (best < 0) {
        return;
    }
    char* key = fn_801F666C(fn_801F856C(), best);
    s32 alpha = (0x40 - bestDist) * 4;
    pos = *(JGeometry::TVec3<f32>*)(key + 0xc);
    if (*(void**)(p + 0x238) == 0) {
        *(void**)(p + 0x238) = fn_8013CC50(*(u32*)(p + 0x4), &pos, 0x314, 0, 2, 0, 0, 1, lbl_8054126C);
    }
    if (*(void**)(p + 0x23c) == 0) {
        *(void**)(p + 0x23c) = fn_8013CC50(*(u32*)(p + 0x4), (JGeometry::TVec3<f32>*)(p + 0xc), 0x312, 0, 0, 0, 0, 1, lbl_8054126C);
    }
    if (*(void**)(p + 0x240) == 0) {
        *(void**)(p + 0x240) = fn_8013CC50(*(u32*)(p + 0x4), (JGeometry::TVec3<f32>*)(p + 0xc), 0x313, 0, 0, 0, 0, 1, lbl_8054126C);
    }
    if (*(void**)(p + 0x238) != 0) {
        if (*(u8*)(key + 0xc4) != 0) {
            JGeometry::TVec3<f32>* hp = fn_8023E7B0(*(s32*)(key + 0xc8));
            pos.x = hp->x;
            pos.y = hp->y;
            pos.z = hp->z;
            fn_8013CB44(*(void**)(p + 0x238), &pos, -1, 3, 1);
        } else {
            pos.z += lbl_80541288;
            fn_8013CB44(*(void**)(p + 0x238), &pos, 0, 0, 1);
        }
        *(u8*)(*(char**)(p + 0x238) + 0xbb) = alpha;
    }
    if (*(void**)(p + 0x23c) != 0) {
        *(u8*)(*(char**)(p + 0x23c) + 0xbb) = alpha;
    }
    if (*(void**)(p + 0x240) != 0) {
        *(u8*)(*(char**)(p + 0x240) + 0xbb) = alpha;
    }
}

// ---- fn_802E83DC: MJGR update ----
extern "C" s32 fn_8023AF14(JGeometry::TBox2<f32>* box, u32 room, s32 a, f32 f);
extern "C" void fn_80134DE4(void* game, s32 code, s32 param);
extern "C" u8 fn_802D46D8(void* cfg, s32 a, s32 b, s32 c);
extern "C" void fn_8043D67C(void* mgr, s32 a, s32 b, s32 c);
extern "C" u8 fn_8023B0F4(s32 idx, JGeometry::TBox2<f32>* box, u32 room, f32 f, s32 a);
extern "C" u32 fn_8023EEB4(s32 idx);
extern "C" s32 fn_8023EF50(s32 idx);
extern "C" void fn_8023EE28(s32 idx);
extern "C" s32 Actor_CreateByID(void* mgr, u32 id, s32 room, void* pos, u32 param, s32 a, s32 b);
extern "C" void fn_801F0D20(void* self, u32 id);
extern void* lbl_8053AAF8;
extern void* lbl_8053AED0;
extern const u32 lbl_8046F270[];
extern const f32 lbl_8054128C;
extern const f32 lbl_80541290;
extern const f32 lbl_80541294;
extern const f32 lbl_80541298;
extern const f32 lbl_8054129C;
extern const f32 lbl_805412A0;

struct MjV2 { u32 x, y; };

static inline void mjgrKill(char* p, s32 off) {
    char* h = *(char**)(p + off);
    if (h != 0) {
        *(u32*)(h + 0xf4) |= 1;
        *(s32*)(h + 0x24) = 1;
        *(char**)(p + off) = 0;
    }
}

// near-match (~97%): callee-saved GPR assignment and box copy scheduling differ
extern "C" void fn_802E83DC(char* p) {
    switch (*(s32*)(p + 0x244)) {
    case 0: {
        ((JGeometry::TBox2<f32>*)(p + 0x80))->set(lbl_8054128C, lbl_8054128C, lbl_80541290, lbl_80541290);
        JGeometry::TBox2<f32> b;
        *(MjV2*)&b.i = *(MjV2*)(p + 0x80);
        *(MjV2*)&b.f = *(MjV2*)(p + 0x88);
        f32 px = *(f32*)(p + 0xc);
        f32 py = *(f32*)(p + 0x10);
        b.addPos(px, py);
        ((JGeometry::TBox2<f32>*)(p + 0x60))->set(lbl_80541294, lbl_80541294, lbl_80541298, lbl_80541298);
        b.set(*(JGeometry::TBox2<f32>*)(p + 0x60));
        b.addPos(px, py);
        *(s32*)(p + 0x250) = fn_8023AF14(&b, *(u32*)(p + 0x4), 0, lbl_80541268);
        if (*(s32*)(p + 0x250) >= 0) {
            if (*(void**)(p + 0x234) == 0) {
                JGeometry::TVec3<f32> pos(*(f32*)(p + 0xc), *(f32*)(p + 0x10), *(f32*)(p + 0x14));
                *(void**)(p + 0x234) = fn_8013CC50(*(u32*)(p + 0x4), &pos, 0x2a7, 1, 0, 0, 0, 1, lbl_8054126C);
                fn_80134DE4(lbl_8053AAF8, 9, 0);
                if (*(s32*)((char*)fn_802D6A9C() + 0x4) == 1 && *(s32*)((char*)fn_802D6A9C() + 0x8) == 1
                    && !fn_802D46D8(fn_802D6A9C(), *(s32*)(p + 0x250), 0x24e, 0)) {
                    fn_8043D67C(lbl_8053AED0, 0x24e, *(s32*)(p + 0x250), 0);
                    fn_802D46D8(fn_802D6A9C(), *(s32*)(p + 0x250), 0x24e, 1);
                }
            }
            fn_801F0E34(p, 0x30050, 0);
        } else {
            if (*(void**)(p + 0x230) != 0) {
                fn_801EE434(*(void**)(p + 0x230));
                *(void**)(p + 0x230) = 0;
            }
            if (*(void**)(p + 0x234) != 0) {
                fn_801EE434(*(void**)(p + 0x234));
                *(void**)(p + 0x234) = 0;
            }
        }
        fn_802E7DB8(p);
        if (*(s32*)(p + 0x244) != 1) {
            ((JGeometry::TBox2<f32>*)(p + 0x60))->set(lbl_80541260, lbl_8054129C, lbl_80541264, lbl_805412A0);
            b.set(*(JGeometry::TBox2<f32>*)(p + 0x60));
            b.addPos(px, py);
            for (s32 i = 0; i < 4; i++) {
                if (fn_8023B0F4(i, &b, *(u32*)(p + 0x4), lbl_80541268, 0) == 1 && fn_8023EEB4(i) == 'KEY0') {
                    char* key = fn_801F666C(fn_801F856C(), fn_8023EF50(i));
                    if (key != 0 && *(s32*)(key + 0x280) == 6) {
                        JGeometry::TVec3<f32> kp(*(JGeometry::TVec3<f32>*)(key + 0xc));
                        *(s32*)(p + 0x244) = 1;
                        *(s32*)(p + 0x24c) = 20;
                        s32 room = *(s32*)(p + 0x4);
                        if (room >= 8) {
                            Actor_CreateByID(fn_801F856C(), 'KMRI', room, &kp, 0, -1, -1);
                        } else {
                            JGeometry::TVec3<f32> fx(kp);
                            if (*(void**)(p + 0x230) != 0) {
                                fn_801EE434(*(void**)(p + 0x230));
                            }
                            if (*(void**)(p + 0x234) != 0) {
                                fn_801EE434(*(void**)(p + 0x234));
                            }
                            if (*(void**)(p + 0x238) != 0) {
                                fn_801EE434(*(void**)(p + 0x238));
                            }
                            if (*(void**)(p + 0x23c) != 0) {
                                fn_801EE434(*(void**)(p + 0x23c));
                            }
                            if (*(void**)(p + 0x240) != 0) {
                                fn_801EE434(*(void**)(p + 0x240));
                            }
                            *(s32*)(p + 0x230) = 0;
                            *(s32*)(p + 0x234) = 0;
                            *(s32*)(p + 0x238) = 0;
                            *(s32*)(p + 0x23c) = 0;
                            *(s32*)(p + 0x240) = 0;
                            fn_8013CC50(*(u32*)(p + 0x4), &fx, 0x85, 0, 0, 0, 0, 1, lbl_8054126C);
                            fn_8013CC50(*(u32*)(p + 0x4), &fx, 0x86, 0, 0, 0, 0, 1, lbl_8054126C);
                            fn_8013CC50(*(u32*)(p + 0x4), &fx, 0x87, 0, 0, 0, 0, 1, lbl_8054126C);
                            fn_801F0E34(p, 0x30069, 0);
                        }
                        fn_802C5284(key);
                        fn_8023EE28(i);
                        fn_801F34DC(p);
                        break;
                    }
                }
            }
        }
        fn_802E80A0(p);
        break;
    }
    case 1:
        if (*(s32*)(p + 0x24c) == 0) {
            *(s32*)(p + 0x24c) = 2;
            fn_801F0E34(p, 0x3004f, 0);
            *(s32*)(p + 0x244) = 2;
        } else {
            (*(s32*)(p + 0x24c))--;
        }
        break;
    case 2:
        (*(s32*)(p + 0x24c))--;
        if (*(s32*)(p + 0x24c) == 0) {
            u32 param = (*(u32*)(p + 0x90) & ~0xff) | lbl_8046F270[*(s32*)(p + 0x248)];
            Actor_CreateByID(fn_801F856C(), 'CIRC', *(s32*)(p + 0x4), p + 0xc, param, -1, -1);
            *(s32*)(p + 0x244) = 3;
            *(s32*)(p + 0x24c) = 60;
        }
        break;
    case 3:
        (*(s32*)(p + 0x24c))--;
        if (*(s32*)(p + 0x24c) == 0) {
            fn_801F0D20(p, 3);
            mjgrKill(p, 0x230);
            mjgrKill(p, 0x234);
            mjgrKill(p, 0x238);
            mjgrKill(p, 0x23c);
            mjgrKill(p, 0x240);
            *(u8*)(p + 0x11c) = 0;
        }
        break;
    }
}

// ---- fn_802E8A64_dtor.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804A9FB0[];

extern "C" void* fn_802E8A64(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A9FB0;
        if (*(void**)(p + 0x230) != 0) {
            fn_801EE434(*(void**)(p + 0x230));
        }
        if (*(void**)(p + 0x234) != 0) {
            fn_801EE434(*(void**)(p + 0x234));
        }
        if (*(void**)(p + 0x238) != 0) {
            fn_801EE434(*(void**)(p + 0x238));
        }
        if (*(void**)(p + 0x23c) != 0) {
            fn_801EE434(*(void**)(p + 0x23c));
        }
        if (*(void**)(p + 0x240) != 0) {
            fn_801EE434(*(void**)(p + 0x240));
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// fn_802E8B18 - MJGR: setParams().
extern "C" u8 fn_802D75BC(void* rec, u32 id);
extern "C" void fn_802E8B18(char* p) {
    *(u32*)(p + 0x248) = *(u32*)(p + 0x90) & 7;
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x264) = 0;
    *(s32*)(p + 0x254) = 0;
    *(s32*)(p + 0x268) = 0;
    *(s32*)(p + 0x258) = 0;
    *(s32*)(p + 0x26c) = 0;
    *(s32*)(p + 0x25c) = 0;
    *(s32*)(p + 0x270) = 0;
    *(s32*)(p + 0x260) = 0;
    *(s32*)(p + 0x230) = 0;
    *(s32*)(p + 0x234) = 0;
    *(s32*)(p + 0x238) = 0;
    *(s32*)(p + 0x23c) = 0;
    *(s32*)(p + 0x240) = 0;
    if (!fn_802D75BC(fn_802D6A9C(), *(u32*)(p + 0x16c))) {
        *(s32*)(p + 0x244) = 0;
    } else if (*(s32*)(p + 0x248) == 0 || *(s32*)(p + 0x248) == 3) {
        *(s32*)(p + 0x244) = 1;
        *(s32*)(p + 0x24c) = 20;
    } else {
        *(u8*)(p + 0x11c) = 0;
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
