// Game TU 801B6C50-801B7784 (GEWP). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"
extern "C" u8 fn_801B7550(void);
extern "C" f32* fn_8023E724(s32 idx);
extern "C" void* fn_80119DD0(void);
extern "C" void fn_80119468(void* p, u32 a, u32 b);
extern "C" void fn_8023EE28(s32 idx);
extern u8 lbl_8053AC00;
extern const f32 lbl_8053EAE0;
extern const f32 lbl_8053EAE4;
extern const f32 lbl_8053EAE8;
extern const f32 lbl_8053EAEC;

extern "C" void fn_801EE434(void* handle);
extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A39DC[];
extern "C" {
}
extern void* lbl_8053AB10[2];

extern "C" void fn_801B6C50(void) {}

extern "C" void* fn_801B7324(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804A39DC;
        char* p = (char*)this_;
        int i = 0;
        do {
            void* h = *(void**)(p + 0x294);
            fn_801EE434(h);
            i++;
            p += 4;
        } while (i < 4);
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_801B73B8(u8* this_) {
    *(f32*)(this_ + 0x60) = lbl_8053EAE0;
    *(f32*)(this_ + 0x64) = lbl_8053EAE0;
    *(f32*)(this_ + 0x68) = lbl_8053EAE4;
    *(f32*)(this_ + 0x6c) = lbl_8053EAE4;
    *(f32*)(this_ + 0x25c) = fn_801B7550();
    *(f32*)(this_ + 0x260) = *(f32*)(this_ + 0x25c);
    *(f32*)(this_ + 0x60) = lbl_8053EAE8;
    *(f32*)(this_ + 0x64) = lbl_8053EAE8;
    *(f32*)(this_ + 0x68) = lbl_8053EAEC;
    *(f32*)(this_ + 0x6c) = lbl_8053EAEC;
    *(f32*)(this_ + 0x80) = lbl_8053EAE8;
    *(f32*)(this_ + 0x84) = lbl_8053EAE8;
    *(f32*)(this_ + 0x88) = lbl_8053EAEC;
    *(f32*)(this_ + 0x8c) = lbl_8053EAEC;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    s32 i;
    for (i = 0; i < 4; i++) {
        f32* p = fn_8023E724(i);
        f32* d = (f32*)(this_ + i * 0xc + 0x264);
        d[0] = p[0];
        d[1] = p[1];
        d[2] = p[2];
    }
    *(s32*)(this_ + 0x250) = *(u32*)(this_ + 0x90) & 0xf;
    *(s32*)(this_ + 0x254) = (*(u32*)(this_ + 0x90) >> 4) & 0xf;
    *(s32*)(this_ + 0x24c) = (*(u32*)(this_ + 0x90) >> 8) & 0xf;
    *(s32*)(this_ + 0x258) = (*(u32*)(this_ + 0x90) >> 12) & 0xf;
    if (*(s32*)(this_ + 0x258) > 10) {
        *(s32*)(this_ + 0x258) = 0;
    }
    lbl_8053AC00 = 0;
    *(s32*)(this_ + 0x294) = 0;
    *(s32*)(this_ + 0x298) = 0;
    *(s32*)(this_ + 0x29c) = 0;
    *(s32*)(this_ + 0x2a0) = 0;
    if (*(s32*)(this_ + 0x24c) == 0) {
        *(s32*)(this_ + 0x230) = 0;
    } else {
        fn_80119468(fn_80119DD0(), 0, 0);
        for (i = 0; i < 4; i++) {
            fn_8023EE28(i);
        }
        *(s32*)(this_ + 0x230) = 6;
    }
}

extern "C" u8 fn_801B7550(void) {
	void* p1 = lbl_8053AB10[0];
	void* p2 = *(void**)((char*)p1 + 0x2c);
	return *(u8*)((char*)p2 + 0xc);
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
