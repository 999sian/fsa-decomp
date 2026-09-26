// TU 0x80377e20-0x80378294 (actor ENDR).
#include "types.h"

extern "C" void dtor_801F593C(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);

extern void* lbl_804AE830[];

extern "C" void* fn_80377E20(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AE830;
        dtor_801F593C(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

struct EndrVec { f32 x, y, z; };
extern "C" EndrVec* fn_8023E724(s32 player);
extern "C" void fn_80230050(s32 player);

extern "C" void fn_80377E80(void* thisPtr) {
    char* p = (char*)thisPtr;
    f32 x0 = *(f32*)(p + 0x60);
    f32 y0 = *(f32*)(p + 0x64);
    f32 x1 = *(f32*)(p + 0x68);
    f32 y1 = *(f32*)(p + 0x6c);
    x0 += *(f32*)(p + 0xc);
    x1 += *(f32*)(p + 0xc);
    y0 += *(f32*)(p + 0x10);
    y1 += *(f32*)(p + 0x10);
    for (s32 i = 0; i < 4; i++) {
        EndrVec* v = fn_8023E724(i);
        f32 x = v->x;
        f32 y = v->y;
        u8 in = false;
        if (x >= x0 && y >= y0 && x < x1 && y < y1) {
            in = true;
        }
        if (in == true) {
            fn_80230050(i);
        }
    }
}

extern "C" void fn_80377F70(void* thisPtr) {
    char* p = (char*)thisPtr;
    u32 flags = *(u32*)(p + 0x90);
    f32 w = (u32)(((flags & 0xFF) + 1) * 8);
    f32 h = (u32)((((flags >> 8) & 0xFF) + 1) * 8);
    if ((flags >> 16) & 1) {
        *(f32*)(p + 0xc) += w;
        *(f32*)(p + 0x10) += h;
    } else {
        *(f32*)(p + 0xc) = w + (f32)((s32)*(f32*)(p + 0xc) / 16 * 16);
        *(f32*)(p + 0x10) = h + (f32)((s32)*(f32*)(p + 0x10) / 16 * 16);
    }
    *(f32*)(p + 0x60) = -w;
    *(f32*)(p + 0x64) = -h;
    *(f32*)(p + 0x68) = w;
    *(f32*)(p + 0x6c) = h;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
