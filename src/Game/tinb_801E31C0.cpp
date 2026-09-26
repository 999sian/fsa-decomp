// Game TU 801E31C0-801E3618 (TINB). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A5370[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* fn_801D0F40(void* this_);
extern "C" {
}

extern "C" void* fn_801E31C0(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A5370;
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

extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F7884(void* mgr, u32 tag, s32 id);
extern "C" u8* fn_801F666C(void* mgr, s32 idx);
extern u8* lbl_8053AAF8;
extern "C" void fn_801D0ED0(void* this_);
extern const f32 lbl_8053F508;
extern const f32 lbl_8053F50C;

extern "C" BOOL fn_801E3250(u32 id, u8 useHigh) {
    s32 idx;
    BOOL result = FALSE;
    idx = fn_801F7884(fn_801F856C(), 'TINB', id);
    if (idx >= 0) {
        u8* actor = fn_801F666C(fn_801F856C(), idx);
        if (actor != 0) {
            u32 state;
            if (useHigh) {
                state = (*(u32*)(actor + 0x90) >> 4) & 0xf;
            } else {
                state = *(u32*)(actor + 0x90) & 0xf;
            }
            if (state == 0) {
                result = TRUE;
            } else if (lbl_8053AAF8[0x7e] == 0) {
                if (state == 2) {
                    result = TRUE;
                }
            } else if (state == 1) {
                result = TRUE;
            }
        }
    }
    return result;
}

extern "C" void fn_801E331C(void) {}

extern "C" void fn_801E3320(u8* this_) {
    fn_801D0ED0(this_);
    f32 b = lbl_8053F50C;
    f32 a = lbl_8053F508;
    *(f32*)(this_ + 0x60) = a;
    *(f32*)(this_ + 0x64) = a;
    *(f32*)(this_ + 0x68) = b;
    *(f32*)(this_ + 0x6c) = b;
    *(f32*)(this_ + 0x70) = *(f32*)(this_ + 0x60);
    *(f32*)(this_ + 0x74) = *(f32*)(this_ + 0x64);
    *(f32*)(this_ + 0x78) = *(f32*)(this_ + 0x68);
    *(f32*)(this_ + 0x7c) = *(f32*)(this_ + 0x6c);
    *(f32*)(this_ + 0x80) = a;
    *(f32*)(this_ + 0x84) = a;
    *(f32*)(this_ + 0x88) = b;
    *(f32*)(this_ + 0x8c) = b;
    *(u32*)(this_ + 0xb0) = 0;
    *(u32*)(this_ + 0x230) |= 0x380;
    *(u32*)(this_ + 0x108) = 1000;
    *(u32*)(this_ + 0x244) = *(u32*)(this_ + 0x108);
}

extern "C" void* fn_801E33B8(void* this_) {
    fn_801D0F40(this_);
    *(void**)this_ = lbl_804A5370;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
