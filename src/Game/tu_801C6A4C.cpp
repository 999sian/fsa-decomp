// tu_801C6A4C: .text 0x801C6A4C-0x801C71BC (enemy attack-state helpers)
#include "types.h"

extern "C" void fn_800FEB78(void* anim, s32 mode);
extern "C" void fn_801F0E34(void* actor, u32 id, s32 arg);
extern "C" u8 fn_801CAED4(void* actor, s32 target);
extern "C" u8 fn_801D0B44(void* actor, s32 target);
extern "C" s32 fn_801D0280(void* actor, s32 target);
extern "C" void fn_801CD930(void* dir, s32 target, s32 speed);
extern "C" void fn_801C3B7C(void* actor, s32 state);
extern "C" s16 fn_801F6874(s32 v);
extern "C" f32 fn_801D0DA0(void* actor, s32 target, void* pos);
extern "C" s32 fn_801CD664(s32 n);
extern "C" u8 fn_801D12CC(void* actor);
extern "C" s16 fn_801D02E0(void* actor, void* p);
extern const f32 lbl_8053EDF4;

struct Rnd {
    u32 seed;
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - 1.0f;
    }
};
struct RndGame { u8 pad[0xb4]; Rnd rnd; };
extern RndGame* lbl_8053AAF8;

#define S32(o) (*(s32*)(this_ + (o)))
#define U32(o) (*(u32*)(this_ + (o)))
#define S16(o) (*(s16*)(this_ + (o)))
#define U8(o) (*(u8*)(this_ + (o)))
#define F32(o) (*(f32*)(this_ + (o)))

extern "C" void fn_801C6A4C(u8* this_) {
    if (S32(0x340) == 9) {
        if (U32(0x354) & 0x20) {
            fn_800FEB78(this_ + 0x340, 6);
            switch (S32(0x248)) {
            case 0x25:
                fn_801F0E34(this_, 0x400CF, 0);
                fn_801F0E34(this_, 0x400CD, 0);
                break;
            case 0x26:
                F32(0x258) = 1.2f;
                break;
            }
        }
    } else {
        if (U32(0x354) & 0x20) {
            U32(0x354) &= ~0x20;
            U8(0x34D) = 3;
            U8(0x594)++;
        }
        s32 limit = 5;
        if (S32(0x248) == 0x26) {
            limit = 0x14;
            fn_801F0E34(this_, 0x400D0, 0);
            if (S32(0x338) >= 0 && !fn_801CAED4(this_, S32(0x338)) && fn_801D0B44(this_, S32(0x338))) {
                fn_801CD930(this_ + 0x33C, fn_801D0280(this_, S32(0x338)), 0x500);
            }
        }
        if (U8(0x594) >= limit) {
            fn_801C3B7C(this_, 0x28);
        }
    }
}

extern "C" void fn_801C6BA8(u8* this_) {
    if (U32(0x354) & 0x20) {
        switch (S32(0x340)) {
        case 9:
            fn_800FEB78(this_ + 0x340, 3);
            fn_801F0E34(this_, 0x400C6, 0);
            F32(0x254) = F32(0x258) = 2.0f;
            S16(0x33C) = fn_801F6874(S32(0x98));
            break;
        case 3:
            fn_801C3B7C(this_, 0x27);
            break;
        case 2:
            U32(0x354) &= ~0x20;
            U8(0x34D) = 0;
            U8(0x594)++;
            if (U8(0x594) >= 2) {
                fn_801C3B7C(this_, 0x27);
            }
            break;
        }
    }
}

extern "C" void fn_801C6C7C(u8* this_) {
    u8 idle = FALSE;
    if (S32(0x24C) >= S32(0x250)) {
        idle = TRUE;
    } else if (S32(0x338) >= 0 && !fn_801CAED4(this_, S32(0x338)) && fn_801D0B44(this_, S32(0x338))) {
        f32 d = fn_801D0DA0(this_, S32(0x338), this_ + 0xC);
        u32 fl;
        u32 b8;
        if (S32(0x24C) > 1 && (b8 = (fl = U32(0x524)) & 8) != 0 && d <= F32(0x5B0) * F32(0x5B0)) {
            if (fl & 0x20) {
                switch (fn_801CD664(6)) {
                case 0: {
                    RndGame* g = lbl_8053AAF8;
                    if (g->rnd.get_ufloat_1() < 0.6f) {
                        fn_801C3B7C(this_, 0x23);
                    } else {
                        fn_801C3B7C(this_, 0x24);
                    }
                    break;
                }
                case 1:
                case 2:
                    fn_801C3B7C(this_, 0x25);
                    break;
                default:
                    fn_801C3B7C(this_, 0x26);
                    break;
                }
            } else if (fl & 0x10) {
                switch (fn_801CD664(3)) {
                case 0: {
                    RndGame* g = lbl_8053AAF8;
                    if (g->rnd.get_ufloat_1() < 0.6f) {
                        fn_801C3B7C(this_, 0x23);
                    } else {
                        fn_801C3B7C(this_, 0x24);
                    }
                    break;
                }
                default:
                    fn_801C3B7C(this_, 0x25);
                    break;
                }
            } else if (b8) {
                RndGame* g = lbl_8053AAF8;
                if (g->rnd.get_ufloat_1() < 0.6f) {
                    fn_801C3B7C(this_, 0x23);
                } else {
                    fn_801C3B7C(this_, 0x24);
                }
            }
        } else if (d > lbl_8053EDF4 * lbl_8053EDF4) {
            idle = TRUE;
        } else if (!fn_801D12CC(this_)) {
            idle = TRUE;
        } else {
            S16(0x33C) = fn_801D02E0(this_, this_ + 0x32C);
        }
    } else {
        idle = TRUE;
    }
    if (idle) {
        RndGame* g = lbl_8053AAF8;
        if (g->rnd.get_ufloat_1() < 0.7f) {
            fn_801C3B7C(this_, 0xF);
        } else {
            fn_801C3B7C(this_, 0x11);
        }
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
