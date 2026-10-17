#include "types.h"
struct VObj_800A1A64 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x800d73fc-0x800ee3f0 (167 functions). split_file divides it into the game's real files.

extern void* lbl_8028B80C[];
extern "C" char lbl_802BB0FC[];
extern "C" void fn_8015AB1C(void* ptr);
extern char lbl_802B7CA0[];
extern f32 lbl_80301058;
extern "C" void fn_80179CB4(void*, void*, f32, f32);
extern "C" void fn_8015FDA8(void*, void*);
extern "C" int fn_8002F0A8(int);
extern "C" void fn_8002F458(s32 a, s32 b);
extern "C" void fn_800E7F50(void*, s32, s32, s32);
extern char lbl_802C57D4[];
extern "C" void fn_800E38B8(void) {}

extern "C" void fn_800EA848(u8* p) {
    if (p[0xb14] != 0) {
        p[0xb14]--;
    } else {
        p[0xb14] = lbl_802C57D4[0x81];
        fn_8002F0A8(*(int*)(p + 0xa88));
        p[0xa76] = 0x41;
    }
}

extern "C" void fn_800EAA4C(u8* p) {
    ((s8*)p)[0xa4d]--;
    fn_800E7F50(p, p[0xa4e], ((s8*)p)[0xa4d], 0);
    fn_8002F458(0xa7, 0);
    p[0xa76] = 0x4b;
    p[0xa77] = 0x43;
}

extern "C" void fn_800EAAB0(u8* p) {
    *(u16*)(p + 0xa9c) = (u8)lbl_802C57D4[0x95];
    p[0xa76] = 0x49;
}

extern "C" void fn_800EE0F0(void* param_1, void* param_2) {
    fn_8015FDA8(param_2, *(void**)((u8*)param_1 + 4));
}

extern "C" void fn_800EE344(void* param_1) {
    VObj_800A1A64* obj = *(VObj_800A1A64**)(lbl_802B7CA0 + 0x1394);
    obj->v3();
    f32 c = lbl_80301058;
    fn_80179CB4(*(void**)((char*)param_1 + 4), obj, c, c);
}

extern "C" void* fn_800EE3A8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8028B80C;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
