#include "types.h"
#include "JSystem/JAudio/Interface/JAISound.h"
#include "JSystem/JAudio/Interface/JAISoundParams.h"


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

extern "C" void* fn_80456334(u8* p, JAISoundID id, u32 x);
extern "C" void fn_804561D8(u8* p, JAISoundID id, u8 mode, u32 x, u8 y) {
    f32 pan;
    f32 vol;
    void** snd;

    p[0x44] = y;
    snd = (void**)fn_80456334(p, id, x);
    if (*snd == NULL) {
        return;
    }
    switch (mode) {
    case 0:
    case 1:
        pan = 0.5f;
        vol = 0.4f;
        break;
    case 2:
        pan = 1.0f;
        vol = 0.4f;
        break;
    case 3:
        pan = 0.0f;
        vol = 0.4f;
        break;
    case 4:
    default:
        pan = 0.5f;
        vol = 0.0f;
        break;
    }
    ((JAISoundParamsMove*)((u8*)*snd + 0x48))->movePan(pan, 0);
    if (y != 0) {
        ((JAISoundParamsMove*)((u8*)*snd + 0x48))->moveVolume(1.0f, 0);
    } else {
        ((JAISoundParamsMove*)((u8*)*snd + 0x48))->moveVolume(vol, 0);
    }
    if (p[0x44] != 1) {
        if (lbl_8053AF80[6] == 1) {
            ((JAISoundParamsMove*)((u8*)*snd + 0x48))->moveVolume(0.35f, 0);
        } else {
            ((JAISoundParamsMove*)((u8*)*snd + 0x48))->moveVolume(vol, 0);
        }
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

