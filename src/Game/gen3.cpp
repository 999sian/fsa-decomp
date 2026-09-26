// TU 0x802ec1d4-0x802ec73c (actor GEN3).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// ---- Gen3_dtor_802EC1D4.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int how);
extern void* lbl_804AA1D0[];

extern "C" void* fn_802EC1D4(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804AA1D0;
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

// ---- Gen3_EmptyHook.cpp ----
// Gen3_EmptyHook - GEN3: empty no-op override (0x4, leaf, no extab needed)
extern "C" {

void Gen3_EmptyHook(void) {}

}

// ---- fn_802EC238: GEN3 update() ----
// State machine: 0 wait for trigger; 1 count down, then (mode 1) stop when
// 30 target actors already exist or spawn the smoke; 2 count down and spawn
// the configured actor, repeat this->0x23c times; 4 wait for the trigger to
// be released.
struct Gen3VT {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual u8 check();
};
extern const u32 lbl_8046F450[];
extern const f32 lbl_805413F0;
extern char* lbl_8053AF80;
extern char* lbl_8053AAF8;
extern "C" void* fn_801F856C();
extern "C" s32 fn_801F78F4(void* reg, u32 fourCC, s32 prev);
extern "C" s32 Actor_CreateByID(void* base, u32 fourCC, u32 owner, void* posPtr, u32 param, s32 p6, s32 p7);
extern "C" void fn_8013CC50(f32 scale, u32 owner, void* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_80458FF0(void* obj, u32 id, s32 a, s32 b);
extern "C" void fn_801F35AC(void* this_);

extern "C" void fn_802EC238(char* p) {
    s32 i;
    s32 id;
    switch (*(s32*)(p + 0x230)) {
    case 0:
        if (((Gen3VT*)p)->check()) {
            *(s32*)(p + 0x230) = 1;
            *(s32*)(p + 0x24c) = 1;
        }
        break;
    case 1:
        *(s32*)(p + 0x24c) = *(s32*)(p + 0x24c) - 1;
        if (*(s32*)(p + 0x24c) == 0) {
            i = 0;
            if (*(s32*)(p + 0x240) == 1) {
                id = -1;
                for (; i < 30; i++) {
                    s32 r = fn_801F78F4(fn_801F856C(), *(u32*)(p + 0x250), id);
                    id = r;
                    if (r < 0) {
                        goto spawn;
                    }
                }
                *(s32*)(p + 0x248) = *(s32*)(p + 0x23c);
                *(s32*)(p + 0x230) = 4;
                break;
            }
        spawn:
            i = *(u32*)(p + 0x4);
            if (i >= 8) {
                Actor_CreateByID(fn_801F856C(), 0x4b4d5249, i, p + 0xc, 3, -1, -1);
            } else {
                fn_8013CC50(lbl_805413F0, i, p + 0xc, 0x35c, 1, 1, 0, 0, 1);
            }
        }
        *(s32*)(p + 0x230) = 2;
        *(s32*)(p + 0x24c) = 2;
        break;
    case 2:
        *(s32*)(p + 0x24c) = *(s32*)(p + 0x24c) - 1;
        if (*(s32*)(p + 0x24c) == 0) {
            i = lbl_8046F450[*(u32*)(p + 0x234)];
            Actor_CreateByID(fn_801F856C(), *(u32*)(p + 0x250), *(u32*)(p + 0x4), p + 0xc, i, -1, -1);
            if (*(u32*)(lbl_8053AF80 + 0x58) != 0x1000021 && *(u8*)(lbl_8053AAF8 + 0x7f) == 1 &&
                *(s32*)(p + 0x244) == 0) {
                fn_80458FF0(lbl_8053AF80, 0x1000021, 1, 0);
            }
            *(s32*)(p + 0x24c) = *(s32*)(p + 0x238);
            *(s32*)(p + 0x248) = *(s32*)(p + 0x248) - 1;
            if (*(s32*)(p + 0x248) == 0) {
                s32 mode = *(s32*)(p + 0x240);
                if (mode == 0) {
                    fn_801F35AC(p);
                } else if (mode == 1) {
                    *(s32*)(p + 0x248) = *(s32*)(p + 0x23c);
                    *(s32*)(p + 0x230) = 4;
                }
            } else {
                *(s32*)(p + 0x230) = 1;
            }
        }
        break;
    case 4:
        if (!((Gen3VT*)p)->check()) {
            *(s32*)(p + 0x230) = 0;
        }
        break;
    }
}

// ---- Gen3_SetParams.cpp ----
#include "Game/esd/Actor.h"

// Gen3_SetParams - GEN3: setParams (0x70)
// Extracts a 7-bit selector from this->0x90 into this->0x234, used to
// index a FourCC lookup table (lbl_8046F398, stride 4) whose result is
// stored at this->0x250 (the target FourCC searched for by update());
// extracts 0x238/0x23c/0x240/0x244 from further bitfields, copies 0x23c
// into 0x248, sets the initial countdown (0x24c=1) and state (0x230=0).
// GEN3 is a generic "spawn/find" template actor whose target type is
// data-driven rather than hardcoded.
extern "C" {
extern u32 lbl_8046F398[0x2e]; // real symbol size is 0xb8 bytes (46 words) per symbols.txt

void Gen3_SetParams(void* thisPtr) {
	char* p = (char*)thisPtr;
	u32 typeIdx = ((Actor*)thisPtr)->spawnParam & 0x7f;
	*(u32*)(p + 0x234) = typeIdx;
	u32 idx = *(u32*)(p + 0x234);
	*(u32*)(p + 0x250) = lbl_8046F398[idx];
	*(u32*)(p + 0x238) = (((Actor*)thisPtr)->spawnParam >> 7) & 0x1ff;
	*(u32*)(p + 0x23c) = (((Actor*)thisPtr)->spawnParam >> 16) & 0xf;
	*(u32*)(p + 0x240) = (((Actor*)thisPtr)->spawnParam >> 20) & 0xf;
	*(u32*)(p + 0x244) = (((Actor*)thisPtr)->spawnParam >> 24) & 0x1;
	*(u32*)(p + 0x248) = *(u32*)(p + 0x23c);
	*(u32*)(p + 0x24c) = 1;
	*(u32*)(p + 0x230) = 0;
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
