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
// .text 0x800bb070-0x800be068 (37 functions). split_file divides it into the game's real files.

extern void* lbl_80287BCC[];
extern "C" void fn_8015AB1C(void* ptr);
extern char lbl_802B7CA0[];
extern f32 lbl_80300CE8;
extern f32 lbl_80300D04;
extern "C" f32 fn_800BDD94(void*, u8, s32);
struct VObj_800BD938 {
    virtual void d0();
    virtual void d1();
    virtual void v4(f32, f32);
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9(s32);
};
extern "C" void fn_80179CB4(void*, void*, f32, f32);
extern "C" void fn_800BCF88(void) {}

extern "C" void fn_800BCF8C(u8* p) {
    *(u8*)(*(u8**)(p + 0x34) + 0xb0) = 1;
    p[0xe4] = 2;
    p[0xd4] = 1;
}

extern "C" void fn_800BD00C(u8* p) {
    *(s32*)(p + 0x48) = 0;
    *(*(u8**)(p + 0x34) + 0xb0) = 1;
}

extern "C" void fn_800BD024(u8* p) {
    if (*(*(u8**)(p + 0x34) + 0xb0) != 0) {
        *(s32*)(p + 0x48) = *(s32*)(p + 0x48) + 1;
        if (*(s32*)(p + 0x48) >= *(s16*)(*(u8**)(p + 0x44) + 6)) {
            *(s32*)(p + 0x48) = *(s32*)(p + 0x48) - *(s16*)(*(u8**)(p + 0x44) + 6);
        }
        *(f32*)(*(u8**)(p + 0x44) + 8) = (f32)*(s32*)(p + 0x48);
    }
}

extern "C" int fn_800BD938(void* param_1, s16 param_2, f32 param_3, f32 param_4, u8 param_5, u32 unused, s32 param_7) {
    u8* p = (u8*)param_1;
    if (param_2 < 0) {
        return 0;
    }
    s32 idx = param_2;
    s32 max = param_5;
    if (idx > max) {
        return 1;
    }
    f32 t = fn_800BDD94(param_1, max, idx);
    f32 d = t * (param_4 - param_3);
    (*(VObj_800BD938**)(p + 0x24))->v4(*(f32*)(p + 0x28), *(f32*)(p + 0x2c) + (param_3 + d));
    if (param_7 != 2) {
        if (param_7 == 1) {
            t = lbl_80300D04 - t;
        }
        (*(VObj_800BD938**)(p + 0x24))->v9((s32)((f32)*(u8*)(p + 0x30) * t));
    }
    return 0;
}

extern "C" void fn_800BDFBC(void* param_1) {
    VObj_800A1A64* obj = *(VObj_800A1A64**)(lbl_802B7CA0 + 0x1394);
    obj->v3();
    f32 c = lbl_80300CE8;
    fn_80179CB4(*(void**)((char*)param_1 + 4), obj, c, c);
}

extern "C" void* fn_800BE020(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80287BCC;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
