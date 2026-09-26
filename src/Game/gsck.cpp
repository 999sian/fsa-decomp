// TU 0x802f4aec-0x802f5040 (actor GSCK).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// ---- Gsck_dtor_802F4AEC.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804AA800[];

extern "C" void* fn_802F4AEC(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804AA800;
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- Gsck_EmptyHook.cpp ----
// Gsck_EmptyHook - GSCK: empty no-op override (0x4, leaf, no extab needed)
extern "C" {

void Gsck_EmptyHook(void) {}

}

// ---- fn_802F4B50: GSCK update() ----
// Waits for three switches (and not a fourth), then runs a countdown that
// shows the number (0xdb + n) over every player, and finally sets the fourth
// switch.
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
typedef JGeometry::TVec3<f32> GsckVec;
extern char* lbl_8053AB10;
extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802D7F40(void* rec, u32 sw);
extern "C" void fn_802D7F84(void* rec, u32 sw, s32 on);
extern "C" u8 fn_8023077C();
extern "C" GsckVec* fn_8023E724(s32 player);
extern "C" void fn_8030C210(void* obj, GsckVec pos);
extern "C" void fn_80230498(s32 player, GsckVec pos, s32 id, s32 a, s32 b, s32 c, s32 d);
extern "C" void fn_80230FD0(s32 player, s32 id);
extern "C" u8 fn_80230534(s32 a);
extern "C" void fn_801F0D20(void* this_, s32 id);
extern "C" void detach__5ActorFv(void* this_);

// NONMATCHING (99.6%): params/switch ids land in r28/r27/r29/r30 instead of
// retail r29/r28/r30/r27.
extern "C" void fn_802F4B50(char* p) {
    s32 i;
    u32 params = *(u32*)(p + 0x90);
    u32 swDone = (params >> 7) & 0x1f;
    switch (*(s32*)(p + 0x230)) {
    case 0: {
        u32 sw2 = (params >> 17) & 0x1f;
        u32 sw3 = (params >> 12) & 0x1f;
        if (fn_802D7F40(fn_802D6A9C(), (params >> 22) & 0x1f) &&
            fn_802D7F40(fn_802D6A9C(), sw2) &&
            fn_802D7F40(fn_802D6A9C(), sw3)) {
            if (!fn_802D7F40(fn_802D6A9C(), swDone)) {
                if (fn_8023077C()) {
                    *(s32*)(p + 0x230) = 2;
                    *(s32*)(p + 0x234) = 0;
                    *(s32*)(p + 0x238) = 30;
                } else {
                    *(s32*)(p + 0x230) = 1;
                }
            } else {
                detach__5ActorFv(p);
            }
        }
        break;
    }
    case 1:
        if (fn_8023077C()) {
            *(s32*)(p + 0x230) = 2;
            *(s32*)(p + 0x234) = 0;
            *(s32*)(p + 0x238) = 30;
        }
        break;
    case 2:
        for (i = 0; i < 4; i++) {
            fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), *fn_8023E724(i));
        }
        *(s32*)(p + 0x238) = *(s32*)(p + 0x238) - 1;
        if (*(s32*)(p + 0x238) == 0) {
            *(s32*)(p + 0x234) = *(s32*)(p + 0x234) + 1;
            for (i = 0; i < 4; i++) {
                fn_80230498(i, *fn_8023E724(i), *(s32*)(p + 0x234) + 0xdb, 0xff, -0x80, -0x80, 1);
                if (*(s32*)(p + 0x234) == 1) {
                    fn_80230FD0(i, 0x10001);
                }
            }
            *(s32*)(p + 0x238) = 2;
            if (*(s32*)(p + 0x234) == 13) {
                *(s32*)(p + 0x230) = 3;
                *(s32*)(p + 0x238) = 10;
            }
        }
        break;
    case 3:
        for (i = 0; i < 4; i++) {
            fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), *fn_8023E724(i));
        }
        if (*(s32*)(p + 0x238) == 0) {
            if (fn_80230534(0)) {
                fn_802D7F84(fn_802D6A9C(), swDone, 1);
                fn_801F0D20(p, 3);
                detach__5ActorFv(p);
            }
        } else {
            *(s32*)(p + 0x238) = *(s32*)(p + 0x238) - 1;
        }
        break;
    }
}

// ---- VtableForward_802F4DE8.cpp ----
// fn_802F4DE8 - GSCK: setParams. Zeroes this->0x230, then calls own
// virtual slot 5 (byte offset 0x14, draw/notify passthrough). See
// [[reference_fsa_virtual_dispatch_codegen_trick]] for why this calls
// through a real `virtual` member rather than a manual cast.
struct ActorSlot5 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void slot5();
};

extern "C" void fn_802F4DE8(void* this_) {
    *(u32*)((char*)this_ + 0x230) = 0;
    ((ActorSlot5*)this_)->slot5();
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
