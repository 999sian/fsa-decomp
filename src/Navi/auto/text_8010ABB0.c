#include "types.h"
struct VObj_800C8D90 {
    virtual void v0();
    virtual void v1();
    virtual void v2(f32, f32);
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7(u8);
};

struct VObj_800A1A64 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8010abb0-0x8010cb9c (30 functions). split_file divides it into the game's real files.

extern void* lbl_8028EAF8[];
extern "C" void fn_8015AB1C(void* ptr);
extern char lbl_802B7CA0[];
extern f32 lbl_8030127C;
extern "C" void fn_80179CB4(void*, void*, f32, f32);
extern "C" void fn_80060794(void*, void*, void*, void*);
struct NaviState_8010ABB0;
typedef void (NaviState_8010ABB0::*NaviStateFn_8010ABB0)();
extern NaviStateFn_8010ABB0 lbl_8028EA24[];
extern "C" s32 fn_8002F6BC(void* p);
extern void* lbl_802FF278;
extern f32 lbl_80301280;
extern f32 lbl_80301284;
extern "C" void fn_801E10DC(void);
struct VObj_8010BD04 {
    virtual void v0();
    virtual void v1();
    virtual void v2(u8);
};
extern "C" void fn_8010B634(u8* p) {
    *(u8*)(*(u8**)(p + 0x70) + 0xb0) = 0;
    p[0x9d] = 0;
    p[0x9c] = 0;
}

extern "C" void fn_8010BAA0(NaviState_8010ABB0* p) {
    ((u8*)p)[0x9d] = 0;
    (p->*lbl_8028EA24[((u8*)p)[0x9a]])();
}

extern "C" void fn_8010BD6C(u8* param_1) {
    if (param_1[0x9b] != 0) {
        param_1[0x9b]--;
        return;
    }
    param_1[0x9a] = 3;
}

extern "C" void fn_8010C188(void) {}

extern "C" void fn_8010C18C(u8* param_1) {
    f32 off = 0.5f * param_1[0x7c];
    (*(VObj_800C8D90**)(param_1 + 0x70))->v2(*(f32*)(param_1 + 0x74) + off, *(f32*)(param_1 + 0x78));
}

extern "C" void fn_8010C7F4(u8* p) {
    char* base = lbl_802B7CA0 + 0x1424;
    fn_80060794(base, base + 0x204, base + 0x208, p + 8);
}

extern "C" void fn_8010CAF0(void* param_1) {
    VObj_800A1A64* obj = *(VObj_800A1A64**)(lbl_802B7CA0 + 0x1394);
    obj->v3();
    f32 c = lbl_8030127C;
    fn_80179CB4(*(void**)((char*)param_1 + 4), obj, c, c);
}

extern "C" void* fn_8010CB54(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8028EAF8;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
