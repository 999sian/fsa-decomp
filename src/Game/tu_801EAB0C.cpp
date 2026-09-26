// tu_801EAB0C: .text 0x801EAB0C-0x801EB00C (per-player / per-id cooldown table)
#include "types.h"

struct CooldownTable {
    u8 mPlayerTimer[4];
    u8 mTimer[16];
    s32 mId[16];
};

extern "C" void fn_801EAB0C(CooldownTable* t) {
    for (int i = 0; i < 4; i++) {
        if (t->mPlayerTimer[i] != 0) {
            t->mPlayerTimer[i]--;
        }
    }
    for (int i = 0; i < 16; i++) {
        if (t->mTimer[i] != 0) {
            t->mTimer[i]--;
            if (t->mTimer[i] == 0) {
                t->mId[i] = -1;
            }
        }
    }
}

extern "C" BOOL fn_801EAC20(CooldownTable* t, s32 player) {
    BOOL r = FALSE;
    if (player >= 0 && player < 4 && t->mPlayerTimer[player] == 0) {
        t->mPlayerTimer[player] = 0x18;
        r = TRUE;
    }
    return r;
}

static inline u8 isCooling(CooldownTable* t, s32 id) {
    u8 found = FALSE;
    if (id >= 0) {
        for (int i = 0; i < 16; i++) {
            if (t->mTimer[i] != 0 && t->mId[i] == id) {
                found = TRUE;
                break;
            }
        }
    }
    return found;
}

extern "C" BOOL fn_801EAC54(CooldownTable* t, s32 id) {
    BOOL r = FALSE;
    if (id >= 0) {
        if (!isCooling(t, id)) {
            for (int i = 0; i < 16; i++) {
                if (t->mTimer[i] == 0) {
                    t->mTimer[i] = 0x18;
                    t->mId[i] = id;
                    r = TRUE;
                    break;
                }
            }
        }
    }
    return r;
}

extern "C" void fn_801EAD68(CooldownTable* t) {
    t->mPlayerTimer[0] = 0;
    t->mPlayerTimer[1] = 0;
    t->mPlayerTimer[2] = 0;
    t->mPlayerTimer[3] = 0;
    for (int i = 0; i < 16; i++) {
        t->mTimer[i] = 0;
        t->mId[i] = -1;
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
