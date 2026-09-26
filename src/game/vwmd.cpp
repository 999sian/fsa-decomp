// TU 0x802e038c-0x802e07c8 (actor VWMD).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "game/esd/types.h"

// ---- fn_802E038C_dtor.cpp ----
extern "C" void dtor_801F593C(void* this_, int flag);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804A9A18[];

extern "C" void* fn_802E038C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A9A18;
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- stub_802e03ec.cpp ----
// VWMD cluster, part 2/4. fn_802E03EC - empty override (bare blr), no
// extab. Likely a "do nothing" draw() or similar no-op virtual.
extern "C" {

void fn_802E03EC(void) {}

}

// fn_802E03F0 / fn_802E055C - VWMD: view-mode room flags.
extern "C" void* fn_802D6A9C(void);
extern "C" s32 fn_8023DE58(s32 player);
extern "C" s32 fn_802373EC(s32 player);
extern "C" u8 fn_802D800C(void* rec, u32 id);
extern "C" void fn_802D7790(void* rec, u32 room, u32 mask);
extern "C" void fn_802D77BC(void* rec, u32 room, u32 mask);
extern "C" void fn_802D77E4(void* rec, u32 room, u32 mask);

struct Vwmd {
    u8 pad0[4];
    s32 room;           // 0x4
    u8 pad8[0x90 - 0x8];
    u32 params;         // 0x90
    u8 pad94[0x230 - 0x94];
    s32 switchId;       // 0x230

    void update();
    inline bool isPlayerInRoom() {
        bool found = false;
        for (s32 i = 0; i < 4; i++) {
            if (room == fn_8023DE58(i) && fn_802373EC(i) == 2) {
                found = true;
                break;
            }
        }
        return found;
    }
    void setParams();
};

// NONMATCHING (96.5%): retail keeps this in r31 and found/i in r30/r29.
void Vwmd::update() {
    if (params & 2) {
        bool found = false;
        s32 i;
        for (i = 0; i < 4; i++) {
            if (room == fn_8023DE58(i) && fn_802373EC(i) == 2) {
                found = true;
                break;
            }
        }
        if (fn_802D800C(fn_802D6A9C(), switchId) || found) {
            fn_802D7790(fn_802D6A9C(), room, 2);
        } else {
            fn_802D77BC(fn_802D6A9C(), room, 2);
        }
    }
    if (params & 0xC) {
        s32 id = switchId;
        if (id != 0) {
            if (fn_802D800C(fn_802D6A9C(), id)) {
                fn_802D77BC(fn_802D6A9C(), room, params & 0xC);
            } else {
                fn_802D7790(fn_802D6A9C(), room, 0xC);
            }
        }
    }
    if (params & 0x3000) {
        s32 id = switchId;
        if (id != 0) {
            if (fn_802D800C(fn_802D6A9C(), id)) {
                fn_802D77BC(fn_802D6A9C(), room, params & 0x3000);
            } else {
                fn_802D7790(fn_802D6A9C(), room, 0x3000);
            }
        }
    }
}

// NONMATCHING (99.3%): epilogue restores r0 before r31 in retail.
void Vwmd::setParams() {
    fn_802D77E4(fn_802D6A9C(), room, params & 0xFFFF);
    switchId = params >> 27;
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
#undef MAX
#undef MIN
#undef NULL
#define NULL 0
#define unknown jsys_unknown
#include "JSystem/JAudio/JASFakeMatchFSA.h"
