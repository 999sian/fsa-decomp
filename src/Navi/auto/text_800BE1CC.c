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
// .text 0x800be1cc-0x800c43d8 (61 functions). split_file divides it into the game's real files.

extern void* lbl_80288148[];
extern "C" void fn_8015AB1C(void* ptr);
extern char lbl_802B7CA0[];
extern f32 lbl_80300D34;
extern "C" void fn_80179CB4(void*, void*, f32, f32);
extern "C" void fn_8015FDA8(void*, void*);
extern char lbl_802BB0FC[];
extern char lbl_802C562C[];
extern "C" s32 fn_800C3494(void);
extern "C" s32 fn_800C3900(void* p, s16 idx, u8 b, s32 c);
extern "C" s32 fn_800C3A1C(void* p, s16 idx, u8 b, s32 c, s32 d);
extern "C" s32 fn_800C3B30(void* p, s16 idx, u8 b, f32 f, f32 g, s32 c, s32 d);
extern "C" void fn_8002F458(s32 a, s32 b);
extern "C" void fn_800C2610(u8* p) {
    if ((*(u32*)(lbl_802BB0FC + 0x108) & 0x4000) == 0) {
        return;
    }
    p[0x222] = 2;
    *(u16*)(p + 0x220) = 0xe;
    p[0x212] = 9;
}

extern "C" void fn_800C3490(void) {}

extern "C" void fn_800C40D8(void* param_1, void* param_2) {
    fn_8015FDA8(param_2, *(void**)((u8*)param_1 + 4));
}

extern "C" void fn_800C432C(void* param_1) {
    VObj_800A1A64* obj = *(VObj_800A1A64**)(lbl_802B7CA0 + 0x1394);
    obj->v3();
    f32 c = lbl_80300D34;
    fn_80179CB4(*(void**)((char*)param_1 + 4), obj, c, c);
}

extern "C" void* fn_800C4390(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80288148;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
