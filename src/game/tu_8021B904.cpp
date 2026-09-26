// TU 0x8021b904-0x8021bcbc.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"

// ---- fn_8021BA30.cpp ----
extern "C" s32 fn_801CD664(s32 range);

// fn_8021BA30 - a randomized-timer-range record initializer (this,
// tag). Zeroes +0x0/+0x8, sets +0x4 to a random int in [0x1e,0x1e+0x5b)
// = [30,120] via the confirmed fn_801CD664 PRNG helper, +0xc to a
// random int in [0xa,0xa+0x15) = [10,30], and stores the passed-through
// tag argument as a u16 at +0x10. Used by TZOK (embedded at +0x374,
// tag=0).
extern "C" void fn_801CD930(s16* angle, s16 target, s16 step);

struct Wander_8021B904 {
    s32 moveTimer;
    s32 moveDuration;
    s32 idleTimer;
    s32 idleDuration;
    s16 angle;
};

extern "C" s16 fn_8021B904(Wander_8021B904* w, s16 angle, u8 moving) {
    if (moving) {
        w->idleTimer = 0;
        w->idleDuration = fn_801CD664(0x15) + 0xa;
        w->moveTimer++;
        if (w->moveTimer >= w->moveDuration) {
            angle += (s16)0x8000;
            s32 d = fn_801CD664(0x4001) - 0x2000;
            angle += d;
            w->moveTimer = 0;
            w->moveDuration = fn_801CD664(0x5b) + 0x1e;
        }
        w->angle = angle;
    } else {
        w->moveTimer = 0;
        w->moveDuration = fn_801CD664(0x5b) + 0x1e;
        w->idleTimer++;
        if (w->idleTimer >= w->idleDuration) {
            s32 d = fn_801CD664(0x8001) - 0x4000;
            w->angle += d;
            w->idleTimer = 0;
            w->idleDuration = fn_801CD664(0x15) + 0xa;
        }
        fn_801CD930(&angle, w->angle, 0x200);
    }
    return angle;
}

extern "C" void fn_8021BA30(void* this_, u16 tag) {
    *(s32*)((char*)this_ + 0x0) = 0;
    *(s32*)((char*)this_ + 0x4) = fn_801CD664(0x5b) + 0x1e;
    *(s32*)((char*)this_ + 0x8) = 0;
    *(s32*)((char*)this_ + 0xc) = fn_801CD664(0x15) + 0xa;
    *(u16*)((char*)this_ + 0x10) = tag;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
