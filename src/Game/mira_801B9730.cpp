// Game TU 801B9730-801BA65C (MIRA). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"
#include "Game/ItemBase.h"
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);

extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* fn_801D0F40(void* this_);
extern void* lbl_804A3BF8[];

extern "C" void* fn_801B9730(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A3BF8;
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

extern "C" void* fn_801BA3FC(void* this_) {
    fn_801D0F40(this_);
    *(void**)this_ = lbl_804A3BF8;
    return this_;
}

extern "C" void fn_801CE2BC(void* this_, void* arg);
extern "C" void fn_801CE32C(void* this_);

static inline bool mira_canAct(char* p) {
    return *(s32*)(p + 0x248) == 3 ||
           (*(s32*)(p + 0x108) > 0 && ((*(u32*)(p + 0x230) & 7) == 0 || *(s32*)(p + 0xfc) != 5));
}

extern "C" void fn_801B9900(void* this_, void* arg) {
    if (mira_canAct((char*)this_)) {
        fn_801CE2BC(this_, arg);
    }
}

extern "C" void fn_801B9960(void* this_) {
    if (mira_canAct((char*)this_)) {
        fn_801CE32C(this_);
    }
}

struct MiraRGB { u8 r, g, b, a; };
struct MiraEmitter {
    u8 pad[0xb8];
    u8 r, g, b;
    void setColor(const MiraRGB& c) {
        r = c.r;
        g = c.g;
        b = c.b;
    }
};
extern "C" void v07__5ActorFv(void* this_);
extern "C" void fn_801B9DD4(char* p, s32 state);
extern "C" void* fn_8013CC50(u32 id, f32* pos, u32 kind, u32 a, u32 b, u32 c, u32 d, u32 e, f32 scale);


extern const f32 lbl_8053EB70;
extern char* lbl_8053AB10;

extern "C" void fn_801B99C0(void* this_) {
    char* p = (char*)this_;
    if (*(u32*)(p + 0x230) & 0x4000) {
        v07__5ActorFv(this_);
        char* e = (char*)fn_8013CC50(*(u32*)(p + 0x4), (f32*)(p + 0xc), 0x32b, 1, 1, 0, 0, 1, lbl_8053EB70);
        if (e != 0) {
            MiraRGB c = *(MiraRGB*)(*(char**)(lbl_8053AB10 + 0x2c) + 4);
            e[0xb8] = c.r;
            e[0xb9] = c.g;
            e[0xba] = c.b;
        }
    } else {
        fn_801B9DD4((char*)this_, 3);
    }
}

extern "C" void fn_801D0ED0(void* this_);
extern "C" s32 fn_801CD664(s32 n);
extern "C" void fn_801D2608(void* obj, void* tbl, u32 n);
extern "C" void fn_801D22DC(void* obj, u32 a, u32 b, u32 c);
extern "C" void fn_801D1D60(void* obj);
extern u8 lbl_804A3BB8[];
extern const f32 lbl_8053EB7C;
extern const f32 lbl_8053EB94;
extern const f32 lbl_8053EB98;
extern const f32 lbl_8053EB9C;
extern const f32 lbl_8053EBA0;
extern const f32 lbl_8053EBA4;

extern "C" void fn_801BA320(void* this_) {
    char* p = (char*)this_;
    fn_801D0ED0(this_);
    if (*(u32*)(p + 0x90) == 1) {
        *(u32*)(p + 0x230) |= 0x4000;
    }
    *(f32*)(p + 0x60) = lbl_8053EB94;
    *(f32*)(p + 0x64) = lbl_8053EB98;
    *(f32*)(p + 0x68) = lbl_8053EB9C;
    *(f32*)(p + 0x6c) = lbl_8053EB9C;
    *(f32*)(p + 0x80) = lbl_8053EBA0;
    *(f32*)(p + 0x84) = lbl_8053EBA0;
    *(f32*)(p + 0x88) = lbl_8053EBA4;
    *(f32*)(p + 0x8c) = lbl_8053EBA4;
    *(u32*)(p + 0x230) |= 0x80;
    *(u32*)(p + 0x248) = 0;
    *(u32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x250) = fn_801CD664(0x3d) + 0x3c;
    *(f32*)(p + 0x254) = lbl_8053EB7C;
    *(f32*)(p + 0x258) = lbl_8053EB7C;
    fn_801D2608(p + 0x270, lbl_804A3BB8, 0x10);
    fn_801D22DC(p + 0x270, *(u32*)(p + 0x98), 2, 0);
    fn_801D1D60(p + 0x270);
}

extern "C" void fn_801F06F0(void* actor, void* res, u32 id, DrawRec* rec, s32 p5, f32 a, f32 b);
extern u8 lbl_80469300[];

extern "C" void fn_801B97C0(char* this_) {
    DrawRec rec;
    if (*(u32*)(this_ + 0x230) & 0x4000) {
        rec.ids[3] = 6;
    }
    fn_801F06F0(this_, lbl_80469300, *(s32*)(this_ + 0x280) + 0xc1, &rec, 7, lbl_8053EB70, lbl_8053EB70);
}

extern "C" s32 fn_801CF1B0(void* this_, s32 flag, f32 a, f32 b);
extern "C" s32 fn_801D05F8(void* this_, void* pos, f32 r);
extern "C" u8 fn_801D21F0(void* anim);
extern "C" void fn_801CD150(void* src, void* dst);
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* base, s32 id);
extern "C" s32 Actor_CreateByID(void* base, u32 fourCC, u32 owner, void* posPtr, u32 param, s32 p6, s32 p7);
extern const f32 lbl_8053EB74;
extern const f32 lbl_8053EB78;
extern const f32 lbl_8053EB80;
extern const f32 lbl_8053EB84;
extern const f32 lbl_8053EB88;


struct MiraRandom {
    u32 seed;
    u32 get() {
        seed = 0x19660d * seed + 0x3c6ef35f;
        return seed;
    }
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        out.s = (get() >> 9) | 0x3f800000;
        return out.f - lbl_8053EB70;
    }
};

extern "C" void fn_801D22A0(void* obj, u32 a, u32 b);
extern "C" void fn_801F0E34(void* target, s32 soundId, s32 flag);
extern char* lbl_8053AAF8;
extern const f32 lbl_8053EB8C;
extern const f32 lbl_8053EB90;

static inline s32 mira_rndPick(s32 a, s32 b) {
    if (((MiraRandom*)(lbl_8053AAF8 + 0xb4))->get_ufloat_1() < lbl_8053EB8C) {
        return a;
    }
    return b;
}

extern "C" void fn_801B9DD4(char* p, s32 state) {
    *(u32*)(p + 0x230) &= ~0x8000;
    switch (state) {
    case 0:
        if (*(s32*)(p + 0x248) != 0) {
            *(u32*)(p + 0x230) |= 0x8000;
            *(f32*)(p + 0x258) = lbl_8053EB7C;
        }
        *(s32*)(p + 0x250) = fn_801CD664(0x3d) + 0x3c;
        fn_801D22A0(p + 0x270, *(u32*)(p + 0x98), 2);
        break;
    case 1:
        *(f32*)(p + 0x254) = lbl_8053EB7C;
        *(f32*)(p + 0x258) = lbl_8053EB7C;
        fn_801D22DC(p + 0x270, *(u32*)(p + 0x98) + 4, 0, 0);
        break;
    case 2: {
        *(f32*)(p + 0x254) = lbl_8053EB7C;
        *(f32*)(p + 0x258) = lbl_8053EB7C;
        s32 dir = 0;
        s32 cur = *(s32*)(p + 0x98);
        switch (*(u32*)(p + 0x278)) {
        case 0: case 4: case 12: case 14:
            dir = 0;
            break;
        case 1: case 5: case 13: case 15:
            dir = 1;
            break;
        case 2: case 6: case 8: case 10:
            dir = 2;
            break;
        case 3: case 7: case 9: case 11:
            dir = 3;
            break;
        }
        s32 anim = 8;
        switch (dir) {
        case 0:
            switch (cur) {
            case 2:
                break;
            case 3:
                anim = 9;
                break;
            default:
                anim = mira_rndPick(8, 9);
                break;
            }
            break;
        case 1:
            switch (cur) {
            case 2:
                anim = 10;
                break;
            case 3:
                anim = 11;
                break;
            default:
                anim = mira_rndPick(10, 11);
                break;
            }
            break;
        case 2:
            switch (cur) {
            case 0:
                anim = 12;
                break;
            case 1:
                anim = 13;
                break;
            default:
                anim = mira_rndPick(12, 13);
                break;
            }
            break;
        case 3:
            switch (cur) {
            case 0:
                anim = 14;
                break;
            case 1:
                anim = 15;
                break;
            default:
                anim = mira_rndPick(14, 15);
                break;
            }
            break;
        }
        fn_801D22DC(p + 0x270, anim, 0, 0);
        break;
    }
    case 3: {
        *(f32*)(p + 0x254) = lbl_8053EB7C;
        *(f32*)(p + 0x258) = lbl_8053EB7C;
        *(f32*)(p + 0x3c) = lbl_8053EB7C;
        *(f32*)(p + 0x40) = lbl_8053EB7C;
        *(f32*)(p + 0x44) = lbl_8053EB7C;
        *(f32*)(p + 0x60) = lbl_8053EB70;
        *(f32*)(p + 0x64) = lbl_8053EB70;
        *(f32*)(p + 0x68) = lbl_8053EB90;
        *(f32*)(p + 0x6c) = lbl_8053EB90;
        *(f32*)(p + 0x70) = *(f32*)(p + 0x60);
        *(f32*)(p + 0x74) = *(f32*)(p + 0x64);
        *(f32*)(p + 0x78) = *(f32*)(p + 0x68);
        *(f32*)(p + 0x7c) = *(f32*)(p + 0x6c);
        *(f32*)(p + 0x80) = lbl_8053EB70;
        *(f32*)(p + 0x84) = lbl_8053EB70;
        *(f32*)(p + 0x88) = lbl_8053EB90;
        *(f32*)(p + 0x8c) = lbl_8053EB90;
        *(u32*)(p + 0xb0) = 0;
        *(u32*)(p + 0x230) |= 0x300;
        *(u32*)(p + 0x108) = 1;
        MiraRGB c = *(MiraRGB*)(*(char**)(lbl_8053AB10 + 0x2c) + 4);
        char* e[3];
        fn_8013CC50(*(u32*)(p + 0x4), (f32*)(p + 0xc), 0x329, 0, 0, 0, 0, 1, lbl_8053EB70);
        e[0] = (char*)fn_8013CC50(*(u32*)(p + 0x4), (f32*)(p + 0xc), 0x32a, 0, 0, 0, 0, 1, lbl_8053EB70);
        e[1] = (char*)fn_8013CC50(*(u32*)(p + 0x4), (f32*)(p + 0xc), 0x41b, 0, 0, 0, 0, 1, lbl_8053EB70);
        e[2] = (char*)fn_8013CC50(*(u32*)(p + 0x4), (f32*)(p + 0xc), 0x41c, 0, 0, 0, 0, 1, lbl_8053EB70);
        fn_8013CC50(*(u32*)(p + 0x4), (f32*)(p + 0xc), 0x54f, 0, 0, 0, 0, 1, lbl_8053EB70);
        for (int i = 0; i < 3; i++) {
            if (e[i] != 0) {
                ((MiraEmitter*)e[i])->setColor(c);
            }
        }
        fn_801F0E34(p, 0x5007e, 0);
        fn_801F0E34(p, 0x40003, 0);
        *(u8*)(p + 0x11d) = 0;
        break;
    }
    }
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x248) = state;
}
static inline bool mira_chk(char* p, u32 f) { return *(s32*)(p + 0x230) & f; }
static inline void mira_off(char* p, u32 f) { ((ItemBase*)p)->m230 &= ~f; }

static inline void mira_pickNext(char* p) {
    if (fn_801D05F8(p, p + 0xc, lbl_8053EB74) < 0) {
        fn_801B9DD4(p, 1);
    } else {
        s32 flag = 0;
        if (mira_chk(p, 0x2000)) {
            flag = 1;
            mira_off(p, 0x2000);
        }
        s32 dir = fn_801CF1B0(p, flag, lbl_8053EB74, lbl_8053EB78);
        if (dir == *(s32*)(p + 0x98)) {
            fn_801B9DD4(p, 0);
        } else {
            *(s32*)(p + 0x98) = dir;
            fn_801B9DD4(p, 2);
        }
    }
}

extern "C" void fn_801B9A5C(char* p, u8 arg) {
    switch (*(s32*)(p + 0x248)) {
    case 0:
        if ((*(s32*)(p + 0x230) & 0x8000) && *(s32*)(p + 0x24c) >= 5) {
            *(u32*)(p + 0x230) &= ~0x8000;
        }
        if (arg) {
            s32 dir = fn_801CF1B0(p, 1, lbl_8053EB74, lbl_8053EB78);
            if (dir == *(s32*)(p + 0x98)) {
                *(s32*)(p + 0x250) += 10;
            } else if (fn_801D05F8(p, p + 0xc, lbl_8053EB74) < 0) {
                *(u32*)(p + 0x230) |= 0x2000;
                fn_801B9DD4(p, 1);
            } else {
                *(s32*)(p + 0x98) = dir;
                fn_801B9DD4(p, 2);
            }
        } else if (*(s32*)(p + 0x24c) >= *(s32*)(p + 0x250)) {
            mira_pickNext(p);
        }
        break;
    case 1:
        if (*(s32*)(p + 0x24c) > 1 && fn_801D21F0(p + 0x270)) {
            s32 flag = 0;
            if (*(s32*)(p + 0x230) & 0x2000) {
                flag = 1;
                *(u32*)(p + 0x230) &= ~0x2000;
            }
            s32 dir = fn_801CF1B0(p, flag, lbl_8053EB74, lbl_8053EB78);
            if (dir == *(s32*)(p + 0x98)) {
                fn_801B9DD4(p, 0);
            } else {
                *(s32*)(p + 0x98) = dir;
                fn_801B9DD4(p, 2);
            }
        }
        break;
    case 2:
        if (*(s32*)(p + 0x24c) > 1 && fn_801D21F0(p + 0x270)) {
            s32 cur = *(s32*)(p + 0x98);
            s32 dir = 0;
            switch (*(u32*)(p + 0x278)) {
            case 0: case 4: case 12: case 14:
                dir = 0;
                break;
            case 1: case 5: case 13: case 15:
                dir = 1;
                break;
            case 2: case 6: case 8: case 10:
                dir = 2;
                break;
            case 3: case 7: case 9: case 11:
                dir = 3;
                break;
            }
            if (cur != dir) {
                fn_801B9DD4(p, 2);
            } else {
                fn_801B9DD4(p, 0);
            }
        }
        break;
    case 3:
        if (*(s32*)(p + 0x24c) >= 0xb4) {
            f32 pos[3];
            fn_801CD150(p + 0xc, pos);
            s32 id = Actor_CreateByID(fn_801F856C(), 'STAL', 8, pos, 3, *(s32*)(p + 0x16c), -1);
            if (id >= 0) {
                char* a = (char*)fn_801F666C(fn_801F856C(), id);
                if (a != 0) {
                    *(s32*)(a + 0x98) = 2;
                }
            }
            *(u8*)(p + 0x11c) = 0;
        }
        break;
    }
    if (*(s32*)(p + 0x248) != 0 || (*(u32*)(p + 0x230) & 0x8000)) {
        *(f32*)(p + 0x258) = lbl_8053EB7C;
    } else {
        switch (*(u32*)(p + 0x280)) {
        case 1: case 2: case 6: case 7: case 11: case 12: case 16: case 17:
            *(f32*)(p + 0x258) = lbl_8053EB7C;
            *(f32*)(p + 0x25c) = lbl_8053EB80;
            break;
        default:
            *(f32*)(p + 0x258) = lbl_8053EB84;
            *(f32*)(p + 0x25c) = lbl_8053EB88;
            break;
        }
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
