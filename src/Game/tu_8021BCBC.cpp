// TU 0x8021BCBC-0x8021BFA8: small 4-step cycle counter + JAudio pool __sinit.
#include "types.h"

struct Cycle4 {
    s32 value;
    u32 index;
    s32 tick;
};

static const s32 lbl_8046A678[4] = {0, 1, 2, 3};

extern "C" void fn_8021BCBC(Cycle4* c) {
    c->tick++;
    if (c->tick >= 4) {
        c->tick = 0;
        c->index++;
        if (c->index >= 4) {
            c->index = 0;
        }
    }
    c->value = lbl_8046A678[c->index] + 0x3b5;
}

static inline int modeToIndex(int mode) {
    int idx = 0;
    switch (mode) {
    case 0:
        idx = 2;
        break;
    case 1:
        idx = 0;
        break;
    case 2:
        idx = 1;
        break;
    case 3:
        idx = 3;
        break;
    }
    return idx;
}

extern "C" void fn_8021BD18(Cycle4* c, s32 mode) {
    c->tick = 0;
    c->index = modeToIndex(mode);
    c->value = lbl_8046A678[c->index] + 0x3b5;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"

static u8 lbl_804CDFAC[0x94];
