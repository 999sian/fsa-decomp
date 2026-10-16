// TU 0x80220f54-0x80221b44.
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"
#include "JSystem/JMath/JMath.h"
#include "JSystem/JGeometry/Vec.h"

// ---- stub_80221158.cpp ----
// fn_80221158 - universal shared-actor-default hook: unconditionally
// returns 0, no arguments. Referenced only from actor vtable listings
// in data_80498528.s; the specific method this slot represents (which
// virtual call it answers) is not confirmed.
extern "C" {

int fn_80221158(void) { return 0; }

}

// ---- fn_80221160.cpp ----
extern "C" void fn_8022149C(void* this_, s32 param);

// fn_80221160 - GENERIC default for vtable offset 0x74 (see
// project_fsa_growing_area_extension.md). Thin wrapper: fn_8022149C(this, 0).
extern "C" void fn_80221160(void* this_) {
    fn_8022149C(this_, 0);
}


extern "C" s32 ClassifyBamAngleToQuadrant(u16 angle);
extern "C" void fn_801D22DC(void* obj, s32 a, s32 b, s32 c);
extern "C" void fn_801D22A0(void* obj, s32 a, s32 b);
extern "C" void fn_801F0E34(void* this_, s32 id, s32 c);
extern "C" void fn_801CE2BC(void* this_);
extern "C" void fn_801D01A0(void* this_, void* pos, void* out, f32 f);
extern "C" void detach__5ActorFv(void* this_);
extern "C" void fn_8030C210(void* obj, JGeometry::TVec3<f32> pos);
extern "C" void* fn_802D6A9C();
extern "C" void fn_8013CC50(s32 room, void* pos, f32 scale, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" s32 fn_801CD30C(s32 dir);
extern "C" void fn_801CB434(s32 room, void* pos, s32 c);
extern "C" void fn_801F3604(void* this_);
extern "C" s32 fn_801F6874(s32 dir);
extern "C" void fn_801CBB98(void* base, void* pos, s16 ang, void* out, f32 f);
extern "C" s32 fn_801D05F8(void* this_, void* pos, f32 f);
extern "C" void fn_801D0ED0(void* this_);
extern "C" void fn_801D2608(void* obj, void* tbl, s32 n);
extern "C" void* fn_801D0F40(void* this_);
extern "C" void fn_801EF574(void* tbl, s32 id, void* pos, void* param);
extern "C" void fn_801F06F0(void* this_, void* table, s32 id, void* data, f32 f1, f32 f2, s32 mode);
extern "C" void fn_80307830(void* a, s32 b, void* pos, s32 id, s32 e, s32 f, s32 g, s32 h);
extern void* lbl_8053AB10;
extern void* lbl_8046AAA0[];
extern void* lbl_804A6990[];
extern void* lbl_804A6A00[];
extern const f32 lbl_8053FE74;
extern const f32 lbl_8053FE78;
extern const f32 lbl_8053FE7C;
extern const f32 lbl_8053FE80;
extern const f32 lbl_8053FE84;
extern const f32 lbl_8053FE88;
extern const f32 lbl_8053FE8C;
extern const f32 lbl_8053FE90;
extern const f32 lbl_8053FE94;
extern const f32 lbl_8053FE98;

struct VObj {
    virtual void s00();
    virtual void s01();
    virtual void s02();
    virtual void s03();
    virtual void s04();
    virtual void s05();
    virtual void s06();
    virtual void s07();
    virtual void s08();
    virtual void s09();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
};
#define VCALL(p, off) ((VObj*)(p))->s##off()
struct ActHdr { void* vt; s32 room; u8 pad[4]; f32 pos[3]; };
#define F32(p, o) (*(f32*)((char*)(p) + (o)))
#define S32(p, o) (*(s32*)((char*)(p) + (o)))
#define U8(p, o) (*(u8*)((char*)(p) + (o)))

extern "C" void fn_80220F54(void* this_) {
    u8 buf[0x3c];

    *(s32*)(buf + 0x10) = -1;
    *(s32*)(buf + 0x14) = -1;

    for (u8 i = 0; i < 16; i++) {
        buf[i] = i;
    }

    *(s32*)(buf + 0x10) = -1;
    *(s32*)(buf + 0x14) = 0;
    *(s32*)(buf + 0x18) = 0;
    buf[0x1c] = 0;
    buf[0x1d] = 0;
    buf[0x1e] = 0;
    buf[0x1f] = 1;
    buf[0x20] = 1;
    buf[0x21] = 0;
    buf[0x22] = 0;
    buf[0x23] = 0;
    buf[0x24] = 0;
    buf[0x25] = 0;
    buf[0x26] = 1;
    *(s32*)(buf + 0x28) = 3;
    buf[0x2c] = 1;
    buf[0x2d] = 0;
    buf[0x2e] = 0;
    *(s32*)(buf + 0x30) = -1;
    *(s32*)(buf + 0x34) = 0;
    *(s32*)(buf + 0x38) = 2;
    *(s32*)(buf + 0x30) = 0xe;
    buf[0x2e] = 0x40;

    s32 base = S32(this_, 4);
    if (*(u8*)((s32)fn_802D6A9C() + 0x10000 + base + 0x31df) != 0) {
        buf[0x1f] = 0;
    }

    if (S32(this_, 0x248) == 2) {
        fn_801EF574(lbl_8046AAA0, S32(this_, 0x280), (char*)this_ + 0xc, buf);
    } else {
        fn_801F06F0(this_, lbl_8046AAA0, S32(this_, 0x280), buf, lbl_8053FE74, lbl_8053FE74, 7);
        fn_80307830(*(void**)((char*)this_ + 0x198), S32(this_, 4), (char*)this_ + 0xc, S32(this_, 0x280), 0, 1, 0, 4);
    }
}

extern "C" void fn_80221114(void* this_) {
    fn_8030C210(*(void**)((char*)lbl_8053AB10 + 0x24), JGeometry::TVec3<f32>(F32(this_, 0xc), F32(this_, 0x10), lbl_8053FE78));
}

#pragma fp_contract off
extern "C" void fn_80221184(void* this_) {
    f32 a = JMAAtan2Radian(F32(this_, 0x3c), F32(this_, 0x40));
    S32(this_, 0x98) = ClassifyBamAngleToQuadrant((s32)(a * lbl_8053FE7C) - 0x8000);
    fn_801D22DC((char*)this_ + 0x270, S32(this_, 0x98) + 0xc, 0, 0);
    fn_801F0E34(this_, 0x400c2, 0);
}
#pragma fp_contract reset

extern "C" void fn_80221210(void* this_) {
    if ((S32(this_, 0x230) & 7) == 0) {
        fn_801CE2BC(this_);
    } else {
        VCALL(this_, 35);
    }
}

extern "C" void fn_80221250(void* this_) {
    f32 out[2];
    fn_801D01A0(this_, (char*)this_ + 0x2b0, out, F32(this_, 0x254));
    F32(this_, 0x3c) = out[0];
    F32(this_, 0x40) = out[1];
    VCALL(this_, 31);
}

extern "C" void fn_802212AC(void* this_) {
    s32 t = S32(this_, 0x24c);
    if (t == 0x2d) {
        F32(this_, 0x258) = lbl_8053FE74;
        fn_801D22A0((char*)this_ + 0x270, S32(this_, 0x98) + 4, 2);
    } else if (t > 0x2d) {
        if (__fabs(F32(this_, 0x2b0) - F32(this_, 0xc)) < lbl_8053FE80 &&
            __fabs(F32(this_, 0x2b4) - F32(this_, 0x10)) < lbl_8053FE80) {
            detach__5ActorFv(this_);
        }
    }
}

extern "C" void fn_80221334(char* this_) {
    if (*(s32*)(this_ + 0x24c) >= 0x73) {
        fn_8022149C(this_, 2);
    } else {
        if (*(s32*)(this_ + 0x24c) == 0x46) {
            fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, lbl_8053FE74, 0x416, 0, 0, 0, 0, 1);
            fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, lbl_8053FE74, 0x417, 0, 0, 0, 0, 1);
        }
        if (*(s32*)(this_ + 0x24c) % 4 == 0) {
            *(s32*)(this_ + 0x98) = fn_801CD30C(*(s32*)(this_ + 0x98));
            fn_801D22DC(this_ + 0x270, *(s32*)(this_ + 0x98), 0, 0);
        }
    }
}

extern "C" void fn_80221408(void* this_) {
    s32 t = S32(this_, 0x24c);
    if (t >= 0xa0) {
        fn_801CB434(S32(this_, 4), (char*)this_ + 0xc, 0);
        VCALL(this_, 07);
    } else if (t % 8 == 0) {
        S32(this_, 0x98) = fn_801CD30C(S32(this_, 0x98));
        fn_801D22DC((char*)this_ + 0x270, S32(this_, 0x98), 0, 0);
    }
}

extern "C" void fn_8022149C(void* this_, s32 state) {
    char* p = (char*)this_;
    switch (state) {
    case 0:
    case 1:
        fn_801F3604(this_);
        F32(p, 0x60) = lbl_8053FE74;
        F32(p, 0x64) = lbl_8053FE74;
        F32(p, 0x68) = lbl_8053FE84;
        F32(p, 0x6c) = lbl_8053FE84;
        F32(p, 0x70) = F32(p, 0x60);
        F32(p, 0x74) = F32(p, 0x64);
        F32(p, 0x78) = F32(p, 0x68);
        F32(p, 0x7c) = F32(p, 0x6c);
        F32(p, 0x80) = lbl_8053FE74;
        F32(p, 0x84) = lbl_8053FE74;
        F32(p, 0x88) = lbl_8053FE84;
        F32(p, 0x8c) = lbl_8053FE84;
        F32(p, 0x254) = lbl_8053FE78;
        F32(p, 0x258) = lbl_8053FE78;
        F32(p, 0x3c) = lbl_8053FE78;
        F32(p, 0x40) = lbl_8053FE78;
        fn_801D22DC(p + 0x270, S32(p, 0x98), 0, 0);
        if (state == 0) {
            fn_801F0E34(this_, 0x40037, 0);
        } else if (state == 1) {
            fn_801F0E34(this_, 0x4004a, 0);
        }
        break;
    case 2: {
        fn_801F3604(this_);
        F32(p, 0x60) = lbl_8053FE74;
        F32(p, 0x64) = lbl_8053FE74;
        F32(p, 0x68) = lbl_8053FE84;
        F32(p, 0x6c) = lbl_8053FE84;
        F32(p, 0x70) = F32(p, 0x60);
        F32(p, 0x74) = F32(p, 0x64);
        F32(p, 0x78) = F32(p, 0x68);
        F32(p, 0x7c) = F32(p, 0x6c);
        F32(p, 0x80) = lbl_8053FE74;
        F32(p, 0x84) = lbl_8053FE74;
        F32(p, 0x88) = lbl_8053FE84;
        F32(p, 0x8c) = lbl_8053FE84;
        F32(p, 0x254) = lbl_8053FE78;
        F32(p, 0x258) = lbl_8053FE78;
        F32(p, 0x3c) = lbl_8053FE78;
        F32(p, 0x40) = lbl_8053FE78;
        void* pos = p + 0xc;
        s32 room = S32(p, 4);
        char* game = (char*)fn_802D6A9C();
        void* base;
        if (room < 8) {
            base = game + 0xcc;
        } else {
            base = game + 0xdc;
        }
        fn_801CBB98(base, pos, fn_801F6874(S32(p, 0x2a8)), p + 0x2b0, lbl_8053FE88);
        S32(p, 0x98) = S32(p, 0x2a8);
        fn_801D22A0(p + 0x270, S32(p, 0x98), 0);
        break;
    }
    }
    S32(p, 0x24c) = 0;
    S32(p, 0x248) = state;
}

extern "C" void fn_80221670(void* this_) {
    char* p = (char*)this_;
    void* pos = p + 0xc;
    s32 room = S32(p, 4);
    char* game = (char*)fn_802D6A9C();
    void* base;
    if (room < 8) {
        base = game + 0xcc;
    } else {
        base = game + 0xdc;
    }
    fn_801CBB98(base, pos, fn_801F6874(S32(p, 0x2a8)), p + 0x2b0, lbl_8053FE88);
}

struct ItemFl { u8 pad[0x230]; u32 flags; };
static inline BOOL isDone(char* p) { return (((ItemFl*)p)->flags & 0x2000) != 0; }

extern "C" void fn_802216E8(char* this_, s32 n) {
    if (*(u32*)(this_ + 0x230) & 0x2000) {
        return;
    }
    switch (*(u8*)(this_ + 0x2ac)) {
    case 0:
        if (*(s32*)(this_ + 0x24c) >= n) {
            *(s32*)(this_ + 0x230) |= 0x2000;
        }
        break;
    case 1:
        if (fn_801D05F8(this_, this_ + 0xc, lbl_8053FE8C) >= 0) {
            *(s32*)(this_ + 0x230) |= 0x2000;
        }
        break;
    case 2:
        if (fn_801D05F8(this_, this_ + 0xc, lbl_8053FE90) >= 0) {
            *(s32*)(this_ + 0x230) |= 0x2000;
        }
        break;
    case 3:
        if (*(s32*)(this_ + 0x24c) >= *(u8*)(this_ + 0x2ad)) {
            *(s32*)(this_ + 0x230) |= 0x2000;
        }
        break;
    }
}

extern "C" void fn_802217C8(void* this_) {
    char* p = (char*)this_;
    fn_801D0ED0(this_);
    S32(p, 0x2a8) = (S32(p, 0x90) >> 4) & 3;
    U8(p, 0x2ac) = (S32(p, 0x90) >> 8) & 3;
    U8(p, 0x2ad) = (S32(p, 0x90) >> 12) & 0xff;
    F32(p, 0x80) = lbl_8053FE94;
    F32(p, 0x84) = lbl_8053FE94;
    F32(p, 0x88) = lbl_8053FE98;
    F32(p, 0x8c) = lbl_8053FE98;
    F32(p, 0x60) = lbl_8053FE74;
    F32(p, 0x64) = lbl_8053FE74;
    F32(p, 0x68) = lbl_8053FE84;
    F32(p, 0x6c) = lbl_8053FE84;
    F32(p, 0x70) = F32(p, 0x60);
    F32(p, 0x74) = F32(p, 0x64);
    F32(p, 0x78) = F32(p, 0x68);
    F32(p, 0x7c) = F32(p, 0x6c);
    F32(p, 0x60) = lbl_8053FE94;
    F32(p, 0x64) = lbl_8053FE94;
    F32(p, 0x68) = lbl_8053FE98;
    F32(p, 0x6c) = lbl_8053FE98;
    S32(p, 0xb0) = 0;
    S32(p, 0x230) |= 0x300;
    S32(p, 0x108) = 1000;
    S32(p, 0x244) = S32(p, 0x108);
    U8(p, 0x194) = 1;
    F32(p, 0x2b0) = F32(p, 0xc);
    F32(p, 0x2b4) = F32(p, 0x10);
    fn_801D2608(p + 0x270, lbl_804A6990, 0x1c);
}

extern "C" void* fn_802218C8(void* this_) {
    char* p = (char*)this_;
    fn_801D0F40(this_);
    *(void**)p = lbl_804A6A00;
    S32(p, 0x2a8) = 0;
    U8(p, 0x2ac) = 0;
    U8(p, 0x2ad) = 0;
    F32(p, 0x2b0) = lbl_8053FE78;
    F32(p, 0x2b4) = lbl_8053FE78;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
