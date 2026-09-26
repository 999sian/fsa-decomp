// Game TU 801D46FC-801D6CEC (BOGF). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"
#include "JSystem/JMath/JMath.h"
#include "JSystem/JGeometry.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void dtor_801D7730(void* this_, s32 flag);
extern "C" void dtor_801EB8CC(void* this_, s32 flag);
extern "C" void dtor_80217F80(void* this_, s32 flag);
extern void* lbl_804A4958[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];
extern "C" {
}
extern "C" void fn_801D1C18(void* subObj);
extern void* lbl_8053AF80;
extern "C" s32 fn_80458F9C(void* mgr, s32 handle);
extern "C" void fn_801D7874(void* slot);
extern "C" void fn_8021BD18(void* subObj, s32 arg);
extern "C" void fn_801D789C(void* child);

extern "C" void* fn_801D46FC(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A4958;
        if (p + 0x568 != 0) {
            char* q = p + 0x578;
            if (q != 0) {
                if (q + 0x24 != 0) {
                    *(void**)(p + 0x59c) = lbl_8049CC34;
                }
            }
        }
        dtor_801D7730(p + 0x4c4, -1);
        dtor_801EB8CC(p + 0x464, -1);
        dtor_80217F80(p + 0x448, -1);
        if (this_ != 0) {
            *(void**)p = lbl_804A4808;
            if (p + 0x270 != 0) {
                if (p + 0x294 != 0) {
                    *(void**)(p + 0x294) = lbl_8049CC34;
                }
            }
            __dt__5ActorFv(this_, 0);
        }
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_801D47D8(void)
{
}

extern "C" void fn_801D4C70(void* this_);
extern "C" void fn_801E4D74(void* this_);
extern "C" bool fn_801CD2F8(s32 id);
extern "C" void fn_801D5D84(void* this_, s32 state);
extern "C" void fn_80217CD8(void* p);

extern "C" void fn_801D4A84(u8* this_) {
    if (*(s32*)(this_ + 0x248) == 5) {
        fn_801E4D74(this_);
    }
    if (*(u32*)(this_ + 0x230) & 0x8000) {
        *(u32*)(this_ + 0x230) &= ~0x8000;
        if (fn_801CD2F8(*(s32*)(this_ + 0x4))) {
            fn_801D5D84(this_, 0x15);
        } else {
            fn_801D5D84(this_, 0x17);
        }
    } else if (*(s32*)(this_ + 0x248) == 0xb) {
        if (fn_801CD2F8(*(s32*)(this_ + 0x4))) {
            fn_801D5D84(this_, 0xf);
        } else {
            fn_80217CD8(this_ + 0x448);
            fn_801D5D84(this_, 0xc);
        }
    } else if (fn_801CD2F8(*(s32*)(this_ + 0x4))) {
        switch (*(s32*)(this_ + 0x248)) {
        case 0x11:
            break;
        case 0xf:
        case 0x10:
        case 0x12:
        case 0x13:
        case 0x14:
            fn_801D5D84(this_, 0xa);
            break;
        }
    } else if (*(s32*)(this_ + 0x108) > 0 && *(s32*)(this_ + 0x248) != 0x17) {
        fn_80217CD8(this_ + 0x448);
    }
}

extern const f32 lbl_8053F0C8;
extern const f32 lbl_8053F0E0;
extern const f32 lbl_8053F0E4;
extern const f32 lbl_8053F0E8;
extern const f32 lbl_8053F0EC;
extern const f32 lbl_8053F0F0;

extern "C" void fn_801D4BAC(u8* this_) {
    fn_801D4C70(this_);
    switch (*(s32*)(this_ + 0x248)) {
    case 1:
        *(f32*)(this_ + 0x44) = lbl_8053F0E0;
        break;
    case 6:
        *(f32*)(this_ + 0x44) = lbl_8053F0E4;
        break;
    case 8:
        *(f32*)(this_ + 0x44) += lbl_8053F0E8;
        break;
    default:
        *(f32*)(this_ + 0x44) = lbl_8053F0C8;
        break;
    }
    if (*(s32*)(this_ + 0x248) == 5) {
        *(s16*)(this_ + 0x5d4) += 0x300;
        *(f32*)(this_ + 0x14) = lbl_8053F0F0 * JMASSin(*(s16*)(this_ + 0x5d4)) + lbl_8053F0EC;
    }
}

extern "C" void fn_801D5338(void* this_) {
    s32 state = *(s32*)((char*)this_ + 0x248);
    if (state == 0xb) {
        goto skip;
    }
    if (state < 0xb) {
        if (state >= 8) {
            goto call;
        }
        if (state >= 6) {
            goto skip;
        }
        goto call;
    } else {
        if (state >= 0x1b) {
            goto call;
        }
        if (state >= 0x17) {
            goto skip;
        }
        goto call;
    }
call:
    fn_801D1C18((char*)this_ + 0x270);
skip:
    return;
}

extern "C" s32 fn_801D652C(void) {
    return fn_80458F9C(lbl_8053AF80, 0x3c);
}

extern "C" void* dtor_801D69FC(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        if (p + 0x10 != 0) {
            if (p + 0x34 != 0) {
                *(void**)(p + 0x34) = lbl_8049CC34;
            }
        }
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void* fn_801D6A58(void* slot) {
    fn_801D7874(slot);
    return slot;
}

extern "C" void* fn_801D6A88(void* slot) {
    fn_8021BD18((char*)slot + 0xc, 2);
    fn_801D789C(slot);
    return slot;
}

extern const f32 lbl_8053F0D8;
extern const f32 lbl_8053F0FC;
extern const f32 lbl_8053F134;
extern const f32 lbl_8053F138;

struct BogfGame;
extern BogfGame* lbl_8053AAF8;
struct BogfRandom {
    u32 seed;
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - lbl_8053F0D8;
    }
};
struct BogfGame { u8 pad[0xb4]; BogfRandom rnd; };
static inline f32 bogfRand() { return lbl_8053AAF8->rnd.get_ufloat_1(); }
static inline f32 bogfRandF(f32 s) { return s * lbl_8053AAF8->rnd.get_ufloat_1(); }
static inline f32 bogfRandPM(f32 s) { return s * (lbl_8053F138 * lbl_8053AAF8->rnd.get_ufloat_1() - lbl_8053F0D8); }

struct BogfRupy {
    u8 pad[0x3c];
    JGeometry::TVec3<f32> mVel;
};

extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F8544(void* mgr, u32 kind, s32 room, void* pos, s32 n);
extern "C" void* fn_801F666C(void* mgr, s32 id);

extern "C" void fn_801D63D0(u8* this_) {
    for (s32 i = 0; i < 5; i++) {
        s32 id = fn_801F8544(fn_801F856C(), 'RUPY', *(s32*)(this_ + 0x4), this_ + 0xc, 2);
        if (id >= 0) {
            BogfRupy* rupy = (BogfRupy*)fn_801F666C(fn_801F856C(), id);
            if (rupy != NULL) {
                JGeometry::TVec3<f32> v;
                v.set(lbl_8053F134 * (lbl_8053F138 * lbl_8053AAF8->rnd.get_ufloat_1() - lbl_8053F0D8),
                      lbl_8053F134 * (lbl_8053F138 * lbl_8053AAF8->rnd.get_ufloat_1() - lbl_8053F0D8),
                      lbl_8053F0FC * lbl_8053AAF8->rnd.get_ufloat_1() + lbl_8053F0FC);
                rupy->mVel = v;
            }
        }
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
