// Game TU 801DE714-801E2540 (THNK). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"

extern "C" void fn_801CE694(void* this_);
extern "C" u8 fn_801CD2F8(s32 owner);
extern "C" void* fn_80212AC0(void);
extern "C" void fn_80212AF0(void* registry, void* posPtr);
extern "C" void fn_801CE2BC(void);
extern "C" void fn_8021835C(void* this_);
extern "C" s32 fn_801CCF7C(void);
extern "C" void* fn_801F856C();
extern "C" void fn_801F7AB8(void* base, s32 a, s32 b);
extern "C" void* fn_802D6A9C(void);
extern f32 lbl_8053F4A4;
extern f32 lbl_8053F480;
extern void* lbl_804A51E4[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];
extern u8 lbl_8050EC80[];
extern "C" void* fn_801F666C(void* mgr, s32 idx);
extern "C" void __dt__5ActorFv(void* this_, s32 flag);
extern "C" void __dl__FPv(void* p);
extern "C" void fn_801D22DC(void* p, s32 a, s32 b, s32 c);
extern "C" void fn_801CE4BC(void* this_);
extern "C" void fn_801D0F40(void* this_);

extern "C" void fn_801DE714(void* this_) {
    s32 state = *(s32*)((char*)this_ + 0x248);
    if (state == 0xa) {
        fn_801CE694(this_);
    }
}

extern "C" void fn_801DE740(void* this_) {
    u8 flag = 0;
    s32 state = *(s32*)((char*)this_ + 0x248);
    switch (state) {
    case 0xb:
    case 0xc:
        flag = 1;
        break;
    }
    if (flag == 0) {
        return;
    }
    if (fn_801CD2F8(*(s32*)((char*)this_ + 0x4)) != 0) {
        return;
    }
    {
        void* registry = fn_80212AC0();
        fn_80212AF0(registry, (char*)this_ + 0xc);
    }
}

extern "C" void fn_801DE9C0(void* this_) {
    fn_801CE2BC();
    fn_8021835C(this_);
}

extern "C" void fn_801DE9F4(void* this_) {
    char* p = (char*)this_;
    if (*(u16*)(p + 0x2ce) != 0) {
        *(u16*)(p + 0x2ce) = *(u16*)(p + 0x2ce) - 1;
    }
    if (*(u16*)(p + 0x2ce) == 0) {
        if (*(s32*)(p + 0x248) == 7) {
            switch (*(s32*)(p + 0x278)) {
            case 0xf:
            case 0x10:
                fn_801D22DC(p + 0x270, *(s32*)(p + 0x98), 2, 0);
                return;
            }
        }
        fn_801CE4BC(this_);
    }
}

extern "C" bool fn_801E1D7C(void* thisObj) {
	s32 v = *(s32*)((char*)thisObj + 0x248);
	return v < 0xd && v >= 0xb;
}

extern "C" bool fn_801E1D9C(void* thisObj) {
	s32 v = *(s32*)((char*)thisObj + 0x278);
	bool result = false;
	if (v == 2) { result = true; }
	return result;
}

static inline u8 thnk_isIdleSub(void* this_) {
    u8 r = 0;
    switch (*(s32*)((char*)this_ + 0x278)) {
    case 0: case 1: case 2:
    case 0xd: case 0xe: case 0xf: case 0x10:
        r = 1;
    }
    return r;
}

extern "C" u8 fn_801E1CF8(void* this_) {
    char* p = (char*)this_;
    u8 r = 0;
    switch (*(s32*)(p + 0x248)) {
    case 0:
    case 0xf: case 0x10: case 0x11: case 0x12:
        break;
    default:
        if (!(*(u32*)(p + 0x230) & 0x80000) && *(u16*)(p + 0x2cc) == 0 && thnk_isIdleSub(this_)) {
            r = 1;
        }
    }
    return r;
}

extern "C" u8 fn_801E1DB4(void* this_) {
    return thnk_isIdleSub(this_);
}

extern "C" s32 fn_801E1DE8(void* this_) {
    return fn_801CCF7C();
}

extern "C" void fn_801E2004(void* this_) {
    char* p = (char*)this_;
    void* base = fn_801F856C();
    fn_801F7AB8(base, *(s32*)(p + 0x1a0), *(s32*)(p + 0x198));
    s32 kind = *(s32*)(p + 0x4);
    char* record = (char*)fn_802D6A9C();
    char* field = (kind < 8) ? (record + 0xcc) : (record + 0xdc);
    *(f32*)(p + 0xc) = *(f32*)field - lbl_8053F4A4;
    f32 v1 = *(f32*)(p + 0x10);
    f32 v0 = *(f32*)(p + 0xc);
    *(f32*)(p + 0x2c4) = v0;
    *(f32*)(p + 0x2c8) = v1;
}

extern "C" void fn_801D0ED0(void* this_);
extern "C" s32 fn_801CD664(s32 kind);
extern "C" void fn_801D2608(void* p, void* data, s32 n);
extern f32 lbl_8053F4C0;
extern f32 lbl_8053F4C4;
extern char lbl_804A51A0[];
extern "C" void fn_801E2080(void* this_) {
    char* p = (char*)this_;
    fn_801D0ED0(this_);
    f32 one = lbl_8053F4C0;
    f32 negOne = lbl_8053F4C4;
    *(f32*)(p + 0x80) = one;
    *(f32*)(p + 0x84) = one;
    *(f32*)(p + 0x88) = negOne;
    *(f32*)(p + 0x8c) = negOne;
    *(f32*)(p + 0x60) = one;
    *(f32*)(p + 0x64) = one;
    *(f32*)(p + 0x68) = negOne;
    *(f32*)(p + 0x6c) = negOne;
    *(f32*)(p + 0x70) = *(f32*)(p + 0x60);
    *(f32*)(p + 0x74) = *(f32*)(p + 0x64);
    *(f32*)(p + 0x78) = *(f32*)(p + 0x68);
    *(f32*)(p + 0x7c) = *(f32*)(p + 0x6c);
    *(s32*)(p + 0xb0) = 0;
    *(s32*)(p + 0x98) = 0;
    *(u32*)(p + 0x230) |= 0x300;
    *(s32*)(p + 0x108) = 1000;
    *(s32*)(p + 0x244) = *(s32*)(p + 0x108);
    *(u8*)(p + 0x194) = 1;
    *(s32*)(p + 0x4) = 0;
    *(s16*)(p + 0x2cc) = fn_801CD664(0x3d) + 0x3c;
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x250) = -1;
    f32 zero = lbl_8053F480;
    *(f32*)(p + 0x254) = zero;
    *(f32*)(p + 0x258) = zero;
    fn_801D2608(p + 0x270, lbl_804A51A0, 0x11);
    fn_801D22DC(p + 0x270, 0, 2, 0);
}

extern "C" void* fn_801E22A4(void* this_) {
    char* p = (char*)this_;
    fn_801D0F40(this_);
    *(void**)p = lbl_804A51E4;
    *(s32*)(p + 0x2a8) = -1;
    *(s32*)(p + 0x2ac) = -1;
    *(s32*)(p + 0x2b0) = -1;
    *(s32*)(p + 0x2b4) = -1;
    *(s32*)(p + 0x2b8) = -1;
    *(s32*)(p + 0x2bc) = -1;
    *(s32*)(p + 0x2c0) = 0;
    *(f32*)(p + 0x2c4) = 0.0f;
    *(f32*)(p + 0x2c8) = 0.0f;
    *(u16*)(p + 0x2cc) = 0;
    *(u16*)(p + 0x2ce) = 0;
    *(s32*)(p + 0x2d0) = -1;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
