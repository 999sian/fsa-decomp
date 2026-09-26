// TU 0x80354a44-0x80354d64 (actor RSNP).
#include "types.h"

extern "C" void dtor_801F593C(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);

extern void* lbl_804ACD18[];

extern "C" void* fn_80354A44(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804ACD18;
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_803075AC(u32 a, u32 id, void* pos, u32 type, u32 p5, u32 p6, s32 p7, u32 p8, u32 p9, u32 p10);
extern "C" void fn_801F3668(void* actor);

extern "C" void fn_80354AA4(void* thisPtr) {
    char* p = (char*)thisPtr;
    fn_803075AC(*(u32*)(p + 0x198), *(u32*)(p + 0x4), p + 0xc, 0x3cd, 0, 2, -1, 0, 0, 0);
}

extern "C" void fn_80354AF4(void* thisPtr) {
    char* p = (char*)thisPtr;
    if (*(s32*)(p + 0x230) >= 50) {
        fn_801F3668(p);
    } else {
        *(s32*)(p + 0x230) = *(s32*)(p + 0x230) + 1;
    }
}

extern "C" void fn_80354B2C(void* thisPtr) {
    char* p = (char*)thisPtr;
    *(s32*)(p + 0x230) = 0;
    *(f32*)(p + 0x14) = 0.0f;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
