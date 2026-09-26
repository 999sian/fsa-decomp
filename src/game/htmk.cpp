// TU 0x8034a6b0-0x8034aa40 (actor HTMK).
#include "types.h"

extern "C" void dtor_801F593C(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);

extern void* lbl_804AC868[];

extern "C" void* fn_8034A6B0(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AC868;
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_801F06F0(void* actor, const char* tbl, s32 idx, u32 p4, s32 p5, f32 a, f32 b);
extern "C" void fn_803075AC(u32 a, u32 id, void* pos, u32 type, u32 p5, u32 p6, s32 p7, u32 p8, u32 p9, u32 p10);
extern "C" void fn_801F3668(void* actor);

extern "C" void fn_8034A710(void* thisPtr) {
    char* p = (char*)thisPtr;
    fn_801F06F0(p, "enemy_both2_sob.bin", *(s32*)(p + 0x234) + 0x2dd, 0, -1, 1.0f, 1.0f);
    fn_803075AC(*(u32*)(p + 0x198), *(u32*)(p + 0x4), p + 0xc, *(s32*)(p + 0x234) + 0x2dd, 0, 2, -1, 0, 0, 0);
}

extern "C" void fn_8034A790(void* thisPtr) {
    char* p = (char*)thisPtr;
    if (*(s32*)(p + 0x230) <= 0 && *(s32*)(p + 0x234) == 0) {
        *(s32*)(p + 0x234) = *(s32*)(p + 0x234) + 1;
        *(s32*)(p + 0x230) = 2;
    } else if (*(s32*)(p + 0x230) <= 0 && *(s32*)(p + 0x234) == 1) {
        fn_801F3668(p);
        return;
    }
    *(s32*)(p + 0x230) = *(s32*)(p + 0x230) - 1;
}

extern "C" void fn_8034A800(void* thisPtr) {
    char* p = (char*)thisPtr;
    *(s32*)(p + 0x108) = 10000;
    *(s32*)(p + 0x234) = 0;
    *(s32*)(p + 0x230) = 2;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
