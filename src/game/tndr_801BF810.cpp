// Game TU 801BF810-801C0D70 (TNDR). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"

extern "C" void dtor_801F593C(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A4230[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];
extern "C" void fn_801F06F0(void* this_, void* table, u32 id, void* data, f32 f1, f32 f2, s32 mode);
extern void* lbl_80469400[];
extern "C" f32 lbl_8053ED30;

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
            dtor_801F593C(this_, 0);
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
