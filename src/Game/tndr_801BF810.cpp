// Game TU 801BF810-801C0D70 (TNDR). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A4230[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];
extern "C" void fn_801F06F0(void* this_, void* table, u32 id, void* data, f32 f1, f32 f2, s32 mode);
extern void* lbl_80469400[];
extern "C" const f32 lbl_8053ED30;

extern "C" void* fn_801BF810(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A4230;
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

extern "C" void fn_801BF8A0(void* this_) {
    u8 buf[0x48];

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

    if (*(u32*)((char*)this_ + 0x230) & 0x4000) {
        buf[0x10] = 0;
        buf[0x11] = 0;
        buf[0x12] = 0;
        buf[0x13] = 0x9f;
    }

    fn_801F06F0(this_, lbl_80469400, *(u32*)((char*)this_ + 0x280) + 0x16e, buf, lbl_8053ED30, lbl_8053ED30, 7);
}

extern "C" s32 fn_801F2FAC(void* this_);
extern "C" const f32 lbl_8053ED34;

extern "C" s32 fn_801BF9EC(char* this_) {
    s32 r = 0;
    if (!(*(u32*)(this_ + 0x230) & 0x4000) &&
        *(f32*)(this_ + 0x68) - *(f32*)(this_ + 0x60) > lbl_8053ED34 &&
        *(f32*)(this_ + 0x6c) - *(f32*)(this_ + 0x64) > lbl_8053ED34) {
        r = fn_801F2FAC(this_);
    }
    return r;
}

extern "C" void fn_801CE4BC(void* this_);
extern "C" const f32 lbl_8053ED3C;

extern "C" void fn_801BFCB8(char* this_) {
    f32 f = lbl_8053ED30;
    switch (*(s32*)(this_ + 0x248)) {
    case 1:
    case 3:
    case 4:
        f = lbl_8053ED3C;
        break;
    }
    *(f32*)(this_ + 0x2a0) = f;
    fn_801CE4BC(this_);
}

extern "C" f32* fn_8023E724(s32 id);

extern "C" void fn_801BFC4C(char* this_) {
    *(f32*)(this_ + 0x2b8) = *(f32*)(this_ + 0xc);
    *(f32*)(this_ + 0x2bc) = *(f32*)(this_ + 0x10);
    if (*(s32*)(this_ + 0x2a8) >= 0) {
        f32* v = fn_8023E724(*(s32*)(this_ + 0x2a8));
        *(f32*)(this_ + 0x2c0) = v[0];
        *(f32*)(this_ + 0x2c4) = v[1];
    } else {
        *(f32*)(this_ + 0x2c0) = *(f32*)(this_ + 0x24);
        *(f32*)(this_ + 0x2c4) = *(f32*)(this_ + 0x28);
    }
}

extern "C" void* fn_801D0F40(void* this_);

extern "C" void* fn_801C0AD8(char* this_) {
    fn_801D0F40(this_);
    *(void**)this_ = lbl_804A4230;
    *(s32*)(this_ + 0x2a8) = -1;
    *(f32*)(this_ + 0x2ac) = lbl_8053ED34;
    *(s16*)(this_ + 0x2b0) = 0;
    *(s16*)(this_ + 0x2b2) = 0;
    *(u8*)(this_ + 0x2b4) = 0;
    *(f32*)(this_ + 0x2b8) = lbl_8053ED34;
    *(f32*)(this_ + 0x2bc) = lbl_8053ED34;
    *(f32*)(this_ + 0x2c0) = lbl_8053ED34;
    *(f32*)(this_ + 0x2c4) = lbl_8053ED34;
    *(f32*)(this_ + 0x2c8) = lbl_8053ED34;
    *(f32*)(this_ + 0x2cc) = lbl_8053ED34;
    return this_;
}

struct TndrG { u8 pad[0x131df]; u8 arr[4]; };
extern "C" TndrG* fn_802D6A9C(void);
extern "C" s32 fn_801CEA60(void* this_);
extern "C" s32 fn_801CE9F8(void* this_);
extern "C" const f32 lbl_8053ED38;

extern "C" s32 fn_801BFA50(char* this_) {
    s32 r = 0;
    if (!(*(u32*)(this_ + 0x230) & 0x4000)) {
        s32 id = *(s32*)(this_ + 0x4);
        u8* g = fn_802D6A9C()->arr; if (g[id] == 0 && *(f32*)(this_ + 0x14) > lbl_8053ED38) {
            r = fn_801CEA60(this_);
        } else {
            r = fn_801CE9F8(this_);
        }
    }
    return r;
}

extern "C" void fn_801D0ED0(void* this_);
extern "C" s32 fn_801CD664(s32 n);
extern "C" void fn_801D2608(void* obj, void* tbl, s32 n);
extern "C" void fn_801D22DC(void* obj, s32 a, s32 b, s32 c);
extern u8 lbl_8053A128[8];
extern const f32 lbl_8053ED80;
extern const f32 lbl_8053ED84;
extern const f32 lbl_8053ED88;
extern const f32 lbl_8053ED8C;
extern const f32 lbl_8053ED58;

extern "C" void fn_801C097C(char* this_) {
    fn_801D0ED0(this_);
    *(u8*)(this_ + 0x2b4) = ((u8)*(u32*)(this_ + 0x90) > 4) ? (u8)*(u32*)(this_ + 0x90) : 4;
    if (*(u32*)(this_ + 0x90) >> 31) {
        *(u32*)(this_ + 0x230) |= 0x4000;
    }
    *(f32*)(this_ + 0x80) = lbl_8053ED30;
    *(f32*)(this_ + 0x84) = lbl_8053ED30;
    *(f32*)(this_ + 0x88) = lbl_8053ED80;
    *(f32*)(this_ + 0x8c) = lbl_8053ED80;
    *(f32*)(this_ + 0x60) = lbl_8053ED84;
    *(f32*)(this_ + 0x64) = lbl_8053ED88;
    *(f32*)(this_ + 0x68) = lbl_8053ED8C;
    *(f32*)(this_ + 0x6c) = lbl_8053ED58;
    if (*(u32*)(this_ + 0x230) & 0x4000) {
        *(f32*)(this_ + 0x70) = lbl_8053ED30;
        *(f32*)(this_ + 0x74) = lbl_8053ED30;
        *(f32*)(this_ + 0x78) = lbl_8053ED80;
        *(f32*)(this_ + 0x7c) = lbl_8053ED80;
        *(u32*)(this_ + 0xb0) = 0;
    } else {
        *(f32*)(this_ + 0x70) = *(f32*)(this_ + 0x60);
        *(f32*)(this_ + 0x74) = *(f32*)(this_ + 0x64);
        *(f32*)(this_ + 0x78) = *(f32*)(this_ + 0x68);
        *(f32*)(this_ + 0x7c) = *(f32*)(this_ + 0x6c);
        *(u32*)(this_ + 0xb0) = 0x50202;
    }
    *(s32*)(this_ + 0x98) = 2;
    *(u32*)(this_ + 0x230) |= 0x20;
    *(u8*)(this_ + 0x194) = 1;
    *(f32*)(this_ + 0x14) = lbl_8053ED30;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x250) = fn_801CD664(0x37) + 6;
    *(f32*)(this_ + 0x254) = lbl_8053ED34;
    *(f32*)(this_ + 0x258) = lbl_8053ED34;
    fn_801D2608(this_ + 0x270, lbl_8053A128, 2);
    fn_801D22DC(this_ + 0x270, 0, 0, 0);
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
