#include "types.h"

extern "C" void __ct__5ActorFv(void* this_);
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern "C" void fn_801D267C(void* this_);
extern void* lbl_8049E424[];
extern void* lbl_8049CC34[];
extern const f32 lbl_8053CAA4;
extern const f32 lbl_8053CAA8;
extern "C" u8 fn_80126EF8(u8* this_) {
    s32 v = *(s32*)(this_ + 0x230);
    if (v == 1 || v == 0xc) {
        return 1;
    }
    return 0;
}

extern "C" void v06__5ActorFv(void* this_);
extern "C" void fn_801F02BC(void* this_, const char* name, s32 idx, u8* buf, s32 a, s32 b, s32 c, f32 s0, f32 s1);
extern const char lbl_80464FAC[];
extern "C" void fn_80126F1C(void* this_) {
    u8 buf[0x40];

    v06__5ActorFv(this_);

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

    if (*(s32*)((char*)this_ + 0x230) == 0xd || *(s32*)((char*)this_ + 0x230) == 0xe) {
        buf[0x14] = *(s32*)((char*)this_ + 0x254);
        buf[0x15] = *(s32*)((char*)this_ + 0x254);
        buf[0x16] = *(s32*)((char*)this_ + 0x254);
    }

    fn_801F02BC(this_, lbl_80464FAC, *(s32*)((char*)this_ + 0x28c) + 0x242, buf, 0x407, 0, 0, lbl_8053CAA4, lbl_8053CAA4);
}

extern "C" void v01__5ActorFv(void* this_);
extern "C" void fn_801D2608(void* p, void* a, s32 b);
extern "C" void fn_801D22DC(void* p, s32 a, s32 b, s32 c);
extern "C" void fn_801D1F14(void* p, f32 f);
extern "C" void* fn_801283E8(void);
extern "C" void fn_80128398(void* a, void* b);
extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802D800C(void* mgr, s32 kind);
extern "C" void fn_80126A4C(void* this_, s32 flag);
extern "C" void* lbl_8049E400;
extern "C" f32 lbl_8053CAD0;
extern "C" f32 lbl_8053CABC;
extern "C" f32 lbl_8053CAD4;
extern "C" f32 lbl_8053CAA0;
extern "C" void fn_80127958(void* this_) {
    v01__5ActorFv(this_);
    u8* p = (u8*)this_;
    if (*(u32*)(p + 0x90) & 1) {
        *(u8*)(p + 0x258) = 1;
    }
    void* tbl = &lbl_8049E400;
    f32 q3 = lbl_8053CAA0;
    f32 q2 = lbl_8053CAD4;
    f32 q1 = lbl_8053CABC;
    f32 q0 = lbl_8053CAD0;
    *(s32*)(p + 0x234) = (*(u32*)(p + 0x90) >> 22) & 0x1f;
    *(s32*)(p + 0x238) = (*(u32*)(p + 0x90) >> 8) & 0xff;
    *(f32*)(p + 0x60) = q0;
    *(f32*)(p + 0x64) = q1;
    *(f32*)(p + 0x68) = q2;
    *(f32*)(p + 0x6c) = q3;
    *(f32*)(p + 0x70) = *(f32*)(p + 0x60);
    *(f32*)(p + 0x74) = *(f32*)(p + 0x64);
    *(f32*)(p + 0x78) = *(f32*)(p + 0x68);
    *(f32*)(p + 0x7c) = *(f32*)(p + 0x6c);
    *(f32*)(p + 0x80) = *(f32*)(p + 0x60);
    *(f32*)(p + 0x84) = *(f32*)(p + 0x64);
    *(f32*)(p + 0x88) = *(f32*)(p + 0x68);
    *(f32*)(p + 0x8c) = *(f32*)(p + 0x6c);
    fn_801D2608(p + 0x27c, tbl, 9);
    fn_801D22DC(p + 0x27c, 6, 2, 0);
    fn_801D1F14(p + 0x27c, lbl_8053CAA8);
    *(u8*)(p + 0x2b6) = 0;
    *(u8*)(p + 0x2b7) = 0;
    *(u8*)(p + 0x2b5) = 0;
    *(u8*)(p + 0x11d) = 0;
    fn_80128398(fn_801283E8(), this_);
    if (*(s32*)(p + 0x234) > 0) {
        void** vt = *(void***)this_;
        if (!((u8 (*)(void*))vt[13])(this_)) {
            void* mgr = fn_802D6A9C();
            if (fn_802D800C(mgr, *(s32*)(p + 0x234))) {
                fn_80126A4C(this_, 1);
            }
        }
    }
}

extern "C" void* fn_80127AAC(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_8049E424;
        fn_801EE434(*(void**)(p + 0x37c));
        fn_801EE434(*(void**)(p + 0x380));
        *(s32*)(p + 0x37c) = 0;
        *(s32*)(p + 0x380) = 0;
        if (p + 0x27c != 0) {
            if (p + 0x2a0 != 0) {
                *(void**)(p + 0x2a0) = lbl_8049CC34;
            }
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void* fn_80127B48(void* this_) {
    __ct__5ActorFv(this_);
    char* p = (char*)this_;
    *(void**)p = lbl_8049E424;
    *(s32*)(p + 0x230) = 0;
    *(s32*)(p + 0x234) = 0;
    *(s32*)(p + 0x238) = 0;
    *(s32*)(p + 0x23c) = -1;
    *(s32*)(p + 0x240) = 0;
    *(s32*)(p + 0x244) = 0;
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x250) = 0;
    *(s32*)(p + 0x254) = 0xff;
    *(u8*)(p + 0x258) = 0;
    *(u8*)(p + 0x259) = 0;
    *(f32*)(p + 0x25c) = lbl_8053CAA8;
    *(f32*)(p + 0x260) = lbl_8053CAA4;
    *(f32*)(p + 0x264) = lbl_8053CAA8;
    *(f32*)(p + 0x268) = lbl_8053CAA8;
    *(f32*)(p + 0x26c) = lbl_8053CAA8;
    *(f32*)(p + 0x270) = lbl_8053CAA8;
    *(f32*)(p + 0x274) = lbl_8053CAA8;
    *(f32*)(p + 0x278) = lbl_8053CAA8;
    fn_801D267C(p + 0x27c);
    *(s32*)(p + 0x37c) = 0;
    *(s32*)(p + 0x380) = 0;
    return this_;
}

