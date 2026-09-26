// TU 0x802e7db4-0x802e8dfc (actor MJGR).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"
#include "JSystem/JGeometry/Box.h"

// ---- EmptyHook_802E7DB4.cpp ----
// EmptyHook_802E7DB4 - actor @lbl_804A9FB0: empty no-op override (0x4, leaf, no extab needed)
extern "C" {

void EmptyHook_802E7DB4(void) {}

}

// ---- fn_802E7DB8: look for an opened key block (KEY0) overlapping us ----
extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F78F4(void* mgr, u32 id, s32 start);
extern "C" char* fn_801F666C(void* mgr, s32 id);
extern "C" void* fn_801EE434(void* handle);
extern "C" void fn_8013CC50(u32 room, JGeometry::TVec3<f32>* pos, s32 kind, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale);
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
extern "C" void* fn_802D6A9C(void);
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
