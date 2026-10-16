#include "types.h"


extern u8* lbl_8053AF80;
typedef void (*VFn)(void*);
typedef u32 (*VFnArg)(void*, void*);
extern "C" int fn_804560D0(void* unused, u8** p) {
    struct VObj {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual void v10();
        virtual void v11();
        virtual void v12();
        virtual void v13();
        virtual void v14();
        virtual void v15();
        virtual void v16();
        virtual void v17();
        virtual u32 v18(u32*);
    };
    u32 v = *(u32*)(*p + 0x18);
    VObj* obj = *(VObj**)(lbl_8053AF80 + 0x40);
    if (obj->v18(&v) & 0x8000) {
        return 0;
    }
    return 1;
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

extern "C" char lbl_804B1E28[];
extern "C" void __dt__11JKRDisposerFv(void*, s16);
extern "C" void __dt__14JAUSoundObjectFv(void*, s16);
extern "C" void* fn_8045787C(char* param_1, s16 param_2)
{
    if (param_1 != 0) {
        *(char**)(param_1 + 8) = lbl_804B1E28;
        *(char**)(param_1 + 0x18) = lbl_804B1E28 + 0x24;
        __dt__11JKRDisposerFv(param_1 + 0x18, 0);
        __dt__14JAUSoundObjectFv(param_1, 0);
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}

