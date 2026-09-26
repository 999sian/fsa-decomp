// TU 0x803524c8-0x8035280c (actor SVGT).
#include "types.h"

extern "C" void dtor_801F593C(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);

extern "C" void fn_801EE434(u32 handle);
extern "C" u32 fn_8013CC50(u32 id, void* pos, u32 type, s32 p4, u32 p5, u32 p6, u32 p7, u32 p8, f32 f);

extern "C" void fn_803524C8(void) {}

extern "C" void fn_803524CC(void) {}

extern "C" void fn_803524D0(void* thisPtr) {
    char* p = (char*)thisPtr;
    *(u32*)(p + 0x234) = 0;
    *(u32*)(p + 0x238) = 0;
    if (*(u32*)(p + 0x234) == 0) {
        *(u32*)(p + 0x234) = fn_8013CC50(*(u32*)(p + 0x4), p + 0xc, 0x447, -1, 0, 0, 0, 1, 1.0f);
    }
    if (*(u32*)(p + 0x238) == 0) {
        *(u32*)(p + 0x238) = fn_8013CC50(*(u32*)(p + 0x4), p + 0xc, 0x448, -1, 0, 0, 0, 1, 1.0f);
    }
}

extern void* lbl_804ACB98[];

extern "C" void* fn_80352574(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804ACB98;
        fn_801EE434(*(u32*)((char*)this_ + 0x234));
        fn_801EE434(*(u32*)((char*)this_ + 0x238));
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
