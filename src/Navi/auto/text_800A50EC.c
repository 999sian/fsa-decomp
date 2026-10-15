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
// .text 0x800a50ec-0x800b08f8 (97 functions). split_file divides it into the game's real files.

extern void* lbl_8028739C[];
extern "C" void fn_8015AB1C(void* ptr);
extern char lbl_802B7CA0[];
extern f32 lbl_80300BFC;
extern "C" void fn_80179CB4(void*, void*, f32, f32);
extern "C" void fn_8015FDA8(void*, void*);
extern u8 lbl_802C5524[];
extern u8 lbl_8029FDB4[];
extern "C" void fn_8015AB1C(void*);
extern "C" void fn_800127A0(void*);
extern "C" u32 fn_800AD744(void* param_1, u8* param_2, u8* param_3) {
    *(u8*)((u8*)param_1 + 0x13c) = param_2[0];
    *(u8*)((u8*)param_1 + 0x13d) = param_2[1];
    *(u8*)((u8*)param_1 + 0x13e) = param_2[2];
    *(u8*)((u8*)param_1 + 0x13f) = param_2[3];
    *(u8*)((u8*)param_1 + 0x138) = param_3[0];
    *(u8*)((u8*)param_1 + 0x139) = param_3[1];
    *(u8*)((u8*)param_1 + 0x13a) = param_3[2];
    *(u8*)((u8*)param_1 + 0x13b) = param_3[3];
    return 1;
}

extern "C" void fn_800AD78C(void* param_1, s32 param_2) {
    void* base = (void*)((u8*)param_1 + param_2 * 0x4c);
    void* p1 = *(void**)((u8*)base + 0xc8);
    *(u8*)((u8*)p1 + 0xb0) = 1;
    void* p2 = *(void**)((u8*)base + 0xcc);
    *(u8*)((u8*)p2 + 0xb0) = 0;
    void* p3 = *(void**)((u8*)base + 0xd0);
    *(u8*)((u8*)p3 + 0xb0) = 0;
    void* p4 = *(void**)((u8*)base + 0xbc);
    *(u8*)((u8*)p4 + 0xb0) = 0;
    void* p5 = *(void**)((u8*)base + 0xc0);
    *(u8*)((u8*)p5 + 0xb0) = 0;
    void* p6 = *(void**)((u8*)base + 0xc4);
    *(u8*)((u8*)p6 + 0xb0) = 0;
    void* p7 = *(void**)((u8*)base + 0xf0);
    *(u8*)((u8*)p7 + 0xb0) = 0;
    void* p8 = *(void**)((u8*)base + 0xf4);
    *(u8*)((u8*)p8 + 0xb0) = 0;
    void* p9 = *(void**)((u8*)base + 0xf8);
    *(u8*)((u8*)p9 + 0xb0) = 0;
    void* p10 = *(void**)((u8*)base + 0xe4);
    *(u8*)((u8*)p10 + 0xb0) = 0;
    void* p11 = *(void**)((u8*)base + 0xe8);
    *(u8*)((u8*)p11 + 0xb0) = 0;
    void* p12 = *(void**)((u8*)base + 0xec);
    *(u8*)((u8*)p12 + 0xb0) = 0;
}

extern "C" void fn_800B05F8(void* param_1, void* param_2) {
    fn_8015FDA8(param_2, *(void**)((u8*)param_1 + 4));
}

extern "C" void fn_800B084C(void* param_1) {
    VObj_800A1A64* obj = *(VObj_800A1A64**)(lbl_802B7CA0 + 0x1394);
    obj->v3();
    f32 c = lbl_80300BFC;
    fn_80179CB4(*(void**)((char*)param_1 + 4), obj, c, c);
}

extern "C" void* fn_800B08B0(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8028739C;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
