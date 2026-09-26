// TU 0x80316e34-0x803172dc.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// ---- Animated effect record (used by JIJI/TWTG/FTGL) ----
// A small record that plays a frame sequence (table lbl_804AADB8, indexed by
// the current mode) and fires two effects (0x275/0x276) for players 0..7.
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

#include "Game/AnimEffectRec.h"

extern const s32 lbl_804715A8[4];
extern AnimFrame* lbl_804AADB8[4];
extern f32 lbl_805418B8;
extern "C" s32 fn_8037E9F4(s32 arg);
extern "C" void fn_8013CC50(s32 player, JGeometry::TVec3<f32>* pos, f32 scale, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);

extern "C" s32 fn_80316E34(AnimEffectRec* r) {
    if (r->mode >= 0) {
        return r->frame;
    }
    return -1;
}

extern "C" void fn_80316E50(AnimEffectRec* r, s32 player, const JGeometry::TVec3<f32>& pos) {
    r->frame = -1;
    r->mode = -1;
    r->player = player;
    r->pos = pos;
}

// NONMATCHING (98.1%): retail keeps dur in r0 and re-extends it (extsh) for
// the timer compare; register choice around the timer increment differs.
extern "C" s32 fn_80316E74(AnimEffectRec* r, s32 arg) {
    s32 ret = -1;
    s32 mode = fn_8037E9F4(arg);
    if (mode != r->mode) {
        r->mode = mode;
        r->index = 0;
        r->timer = 0;
        if (mode >= 0) {
            ret = lbl_804715A8[mode];
        }
        if (mode == 3 && r->player < 8) {
            fn_8013CC50(r->player, &r->pos, lbl_805418B8, 0x275, 0, 0, 0, 0, 1);
            fn_8013CC50(r->player, &r->pos, lbl_805418B8, 0x276, 0, 0, 0, 0, 1);
        }
    }
    if (r->mode >= 0) {
        AnimFrame* tbl = lbl_804AADB8[r->mode];
        r->frame = tbl[r->index].frame;
        s16 dur = tbl[r->index].duration;
        if (dur != -1) {
            r->timer++;
            if (r->timer >= dur) {
                r->index++;
                s16 next = tbl[r->index].duration;
                if (next == -2) {
                    r->index = 0;
                } else if (next == -1 && r->player < 8) {
                    if (mode == 0) {
                        fn_8013CC50(r->player, &r->pos, lbl_805418B8, 0x275, 0, 0, 0, 0, 1);
                    } else if (mode == 1) {
                        fn_8013CC50(r->player, &r->pos, lbl_805418B8, 0x276, 0, 0, 0, 0, 1);
                    }
                }
                r->timer = 0;
            }
        }
    }
    return ret;
}

// Deleting destructor (TWTG deletes its record at +0x278 with this).
AnimEffectRec::~AnimEffectRec() {}

// ---- ResetResourceHandleRecord.cpp ----
// Small POD-record reset used by JIJI/TWTG/FTGL after a resource handle lookup.
extern "C" {
void ResetResourceHandleRecord(void* thisPtr) {
	char* p = (char*)thisPtr;
	*(s32*)(p + 0x0) = -1;
	*(s32*)(p + 0x4) = -1;
	*(u8*)(p + 0x8) = 0;
	*(u8*)(p + 0x9) = 0;
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
