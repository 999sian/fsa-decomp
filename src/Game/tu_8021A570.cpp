// TU 0x8021a570-0x8021af28.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"
#include <math.h>


// ---- fn_8021A570 / fn_8021ABC0: swing/idle record update ----
struct SwingRandom {
    u32 seed;
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - 1.0f;
    }
};
struct SwingGame { u8 pad[0xb4]; SwingRandom rnd; };

struct SwingRecord {
    s32 mState;   // 0x0
    s16 mAngle;   // 0x4
    u16 mTimer6;  // 0x6
    u16 mTimer8;  // 0x8
    s16 mSpeed;   // 0xa
    u8 mLocked;   // 0xc
    u8 mFlipped;  // 0xd
};

extern "C" {
extern SwingGame* lbl_8053AAF8;
s32 fn_801CD664(s32 range);
}

static inline void Swing_Choose(SwingRecord* r) {
    if (!r->mLocked) {
        if (lbl_8053AAF8->rnd.get_ufloat_1() < 0.9f) {
            r->mState = 1;
            r->mTimer8 = fn_801CD664(0xb5) + 0x78;
            if (lbl_8053AAF8->rnd.get_ufloat_1() < 0.5f) {
                r->mSpeed = -0x180;
            } else {
                r->mSpeed = 0x180;
            }
        } else {
            r->mState = 0;
            r->mTimer8 = fn_801CD664(0xb5) + 0x78;
            r->mSpeed = 0;
        }
    } else {
        r->mTimer6 = 0;
    }
}

static inline bool Swing_Stop(SwingRecord* r) {
    bool ret = false;
    if (!r->mLocked) {
        r->mState = 0;
        r->mTimer6 = 0xf;
        r->mTimer8 = 0;
        r->mSpeed = 0;
        ret = true;
    } else {
        r->mTimer6 = 0;
    }
    return ret;
}

static inline f32 Swing_Dist(SwingRecord* r) {
    f32 d = __fabsf((f32)(s16)(r->mAngle + 0x8000));
    return (1.0f / 32768.0f) * d;
}

// NonMatching (99.9%): zero/game-pointer register swap (r4/r5) in the bounce-settle branch.
extern "C" bool fn_8021A570(SwingRecord* r, bool active) {
    bool result = false;
    if (r->mTimer6 != 0) {
        r->mTimer6--;
        if (r->mState == 0) {
            r->mAngle += r->mFlipped ? 0x889 : -0x889;
            if (r->mTimer6 == 0) {
                if (Swing_Dist(r) < 0.5f) {
                    r->mAngle = -0x8000;
                    r->mFlipped = 1;
                } else {
                    r->mAngle = 0;
                    r->mFlipped = 0;
                }
                if (active) {
                    if (!r->mLocked) {
                        r->mState = 1;
                        r->mTimer6 = fn_801CD664(0xb5) + 0x78;
                        r->mTimer8 = 0;
                        if (r->mFlipped) {
                            r->mSpeed = -0x180;
                        } else {
                            r->mSpeed = 0x180;
                        }
                    } else {
                        r->mTimer6 = 0;
                    }
                } else {
                    Swing_Choose(r);
                }
            }
        } else if (r->mState == 1) {
            s16 prev = r->mAngle;
            bool bounced = false;
            r->mAngle = prev + r->mSpeed;
            if (r->mFlipped) {
                if ((u16)r->mAngle >= 0x9555) {
                    r->mAngle = -0x6aab;
                    bounced = true;
                } else if ((u16)r->mAngle <= 0x6aab) {
                    r->mAngle = 0x6aab;
                    bounced = true;
                }
            } else {
                if (r->mAngle >= 0x1555) {
                    r->mAngle = 0x1555;
                    bounced = true;
                } else if (r->mAngle <= -0x1555) {
                    r->mAngle = -0x1555;
                    bounced = true;
                }
            }
            if (bounced) {
                result = true;
                r->mSpeed = -r->mSpeed;
            }
            if ((prev <= 0 && r->mAngle >= 0) || (prev >= 0 && r->mAngle <= 0)) {
                if (r->mTimer6 == 0 || r->mLocked) {
                    if (Swing_Dist(r) < 0.5f) {
                        r->mAngle = -0x8000;
                        if (Swing_Stop(r)) {
                            result = true;
                        }
                    } else {
                        r->mAngle = 0;
                        Swing_Choose(r);
                        r->mTimer6 = 0;
                    }
                }
            } else if (r->mTimer6 == 0) {
                r->mTimer6 = 1;
            }
        }
    }
    if (r->mTimer8 != 0) {
        r->mTimer8--;
        if (r->mTimer8 == 0) {
            if (active && r->mTimer6 == 0 && !r->mLocked) {
                if (r->mState == 0) {
                    result = true;
                    r->mTimer6 = 0xf;
                } else if (r->mState == 1) {
                    r->mTimer6 = fn_801CD664(0xb5) + 0x78;
                }
            } else {
                Swing_Choose(r);
            }
        }
    }
    return result;
}

extern "C" void fn_8021ABC0(SwingRecord* r) {
    Swing_Choose(r);
}

// ---- InitDefaultRecord.cpp ----
// Small POD-record zero-initializer. Used by KEPO and EOWL as a plain default-init record.
extern "C" {
void InitDefaultRecord(void* thisPtr) {
	char* p = (char*)thisPtr;
	*(s32*)(p + 0x0) = 0;
	*(u16*)(p + 0x4) = 0;
	*(u16*)(p + 0x6) = 0;
	*(u16*)(p + 0x8) = 0;
	*(u16*)(p + 0xa) = 0;
	*(u8*)(p + 0xc) = 0;
	*(u8*)(p + 0xd) = 0;
}
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
