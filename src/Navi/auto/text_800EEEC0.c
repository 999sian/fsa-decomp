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
// .text 0x800eeec0-0x800efb88 (17 functions). split_file divides it into the game's real files.

extern void* lbl_8028B900[];
extern "C" void fn_8015AB1C(void* ptr);
extern char lbl_802B7CA0[];
extern f32 lbl_8030113C;
extern "C" void fn_80179CB4(void*, void*, f32, f32);
extern "C" void fn_80060794(void*, void*, void*, void*);
extern "C" void fn_801E10DC(void* p, void* q);
extern "C" void fn_800EF4E0(void* p);
extern "C" s32 fn_800EF768(void* p, u8 idx, u8 b, s32 c);
extern u8 lbl_802C587C[];
extern u8 lbl_8028B874[];
extern "C" void fn_800EF378(u8* param_1, u32 param_2, u32 param_3) {
    *(u32*)(param_1 + 0x40) = param_2;
    *(u32*)(param_1 + 0x44) = param_3;
}

extern "C" void fn_800EF3D0(void) {}

extern "C" void fn_800EF450(u8* param_1) {
    if (param_1[0x51] == 1) {
        param_1[0x52] = 0;
    } else {
        s32 r = fn_800EF768(param_1, param_1[0x50], lbl_802C587C[0xc], 1);
        param_1[0x50]++;
        if (r == 1) {
            param_1[0x50] = 0;
            param_1[0x51] = 1;
            param_1[0x52] = 0;
        }
    }
}

extern "C" void fn_800EF4D0(u8* param_1, u8 param_2) {
    if (param_2 != 0) {
        param_1[0x52] = param_2;
    }
}

extern "C" void fn_800EF694(u8* p) {
    char* base = lbl_802B7CA0 + 0x1424;
    fn_80060794(base, base + 0x204, base + 0x208, p + 8);
}

extern "C" void fn_800EFADC(void* param_1) {
    VObj_800A1A64* obj = *(VObj_800A1A64**)(lbl_802B7CA0 + 0x1394);
    obj->v3();
    f32 c = lbl_8030113C;
    fn_80179CB4(*(void**)((char*)param_1 + 4), obj, c, c);
}

extern "C" void* fn_800EFB40(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8028B900;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
