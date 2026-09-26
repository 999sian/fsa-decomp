// tu_801DA7C0: .text 0x801DA7C0-0x801DAC6C (table-driven frame animator)
#include "types.h"

extern u8* lbl_804A4E68[]; // frame index sequences (0xFF terminated)
extern u8* lbl_804A4EA8[]; // per-step durations
extern u32 lbl_804A4DA8[]; // per-frame values (0x30 entries)

struct FrameAnim {
    s32 mAnim;
    s32 mFrame;
    s32 mTimer;
    s32 mStep;
    s32 mMode;
    u32 mFlags;
};

static inline s32 clampFrame(s32 v) {
    if (v > 0x2F) {
        v = 0x2F;
    } else if (v < 0) {
        v = 0;
    }
    return v;
}

extern "C" void fn_801DA7C0(FrameAnim* a) {
    if (!(a->mFlags & 1)) {
        a->mTimer++;
        if (a->mTimer >= lbl_804A4EA8[a->mAnim][a->mStep]) {
            a->mTimer = 0;
            a->mStep++;
            if (lbl_804A4E68[a->mAnim][a->mStep] == 0xFF) {
                if (a->mMode == 0) {
                    a->mFlags |= 1;
                    a->mStep--;
                } else {
                    a->mFlags |= 2;
                    a->mStep = 0;
                }
            }
        }
    }
    a->mFrame = lbl_804A4E68[a->mAnim][a->mStep];
}

extern "C" BOOL fn_801DA894(FrameAnim* a) {
    BOOL r = FALSE;
    if (a->mMode == 2 && !(a->mFlags & 1) &&
        a->mTimer + 1 == lbl_804A4EA8[a->mAnim][a->mStep] &&
        lbl_804A4E68[a->mAnim][a->mStep + 1] == 0xFF) {
        r = TRUE;
    }
    return r;
}

extern "C" BOOL fn_801DA904(FrameAnim* a) {
    BOOL r = FALSE;
    if (clampFrame(a->mFrame) >= 0x1C) {
        r = TRUE;
    }
    return r;
}

extern "C" u32 fn_801DA938(FrameAnim* a) {
    return lbl_804A4DA8[clampFrame(a->mFrame)];
}

extern "C" s32 fn_801DA96C(FrameAnim* a) {
    s32 v = a->mFrame;
    s32 r = v;
    if (v > 0x2F) {
        r = 0x2F;
    } else if (v < 0) {
        r = 0;
    }
    return r;
}

extern "C" BOOL fn_801DA994(FrameAnim* a, s32 anim, s32 mode) {
    BOOL r = FALSE;
    if (a->mAnim != anim) {
        a->mAnim = anim;
        r = TRUE;
        a->mTimer = 0;
        a->mStep = 0;
        a->mMode = mode;
        a->mFlags = 0;
        a->mFrame = lbl_804A4E68[a->mAnim][a->mStep];
    }
    return r;
}

extern "C" void fn_801DA9E8(FrameAnim* a, s32 anim, s32 mode) {
    a->mAnim = anim;
    a->mTimer = 0;
    a->mStep = 0;
    a->mMode = mode;
    a->mFlags = 0;
    a->mFrame = lbl_804A4E68[a->mAnim][a->mStep];
}

extern "C" void fn_801DAA24(FrameAnim* a) {
    a->mAnim = 0;
    a->mFrame = 0;
    a->mTimer = 0;
    a->mStep = 0;
    a->mMode = 2;
    a->mFlags = 0;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
