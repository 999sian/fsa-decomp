#include "types.h"


extern u8* lbl_8053AF80;
typedef void (*VFn)(void*);
typedef u32 (*VFnArg)(void*, void*);
extern "C" BOOL fn_804560D0(void* unused, u8** p) {
    u32 v = *(u32*)(*p + 0x18);
    void* obj = *(void**)(lbl_8053AF80 + 0x40);
    return (((VFnArg*)*(void**)obj)[0x14](obj, &v) & 0x8000) == 0;
}

extern "C" void fn_80456120(u8* p) {
    struct VObj {
        u32 a;
        u32 b;
        virtual void v0();
        virtual void v1();
    };
    p[0x31] = 0;
    ((VObj*)p)->v1();
}

extern "C" void fn_80456154(u8* p) {
    f32* src = *(f32**)(p + 0x34);
    if (src != NULL) {
        *(f32*)(p + 0x38) = src[0];
        *(f32*)(p + 0x3c) = src[1];
        *(f32*)(p + 0x40) = src[2];
        *(f32**)(p + 0x14) = (f32*)(p + 0x38);
    } else {
        *(f32**)(p + 0x14) = NULL;
    }
    f32* v = *(f32**)(p + 0x14);
    if (v != NULL) {
        f32 t = v[1];
        v[1] = v[2];
        (*(f32**)(p + 0x14))[2] = t;
    }
    if (p[0x50] != 0) {
        p[0x50]--;
    }
    if (p[0x51] != 0) {
        p[0x51]--;
    }
}

extern "C" void fn_80457840(u8* p, f32* src) {
    *(f32**)(p + 0x34) = src;
    if (src != NULL) {
        *(f32*)(p + 0x38) = src[0];
        *(f32*)(p + 0x3c) = src[1];
        *(f32*)(p + 0x40) = src[2];
        *(f32**)(p + 0x14) = (f32*)(p + 0x38);
    } else {
        *(f32**)(p + 0x14) = NULL;
    }
}

