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
// .text 0x8011093c-0x80111bac (17 functions). split_file divides it into the game's real files.

extern void* lbl_8028F1BC[];
extern "C" void fn_8015AB1C(void* ptr);
extern char lbl_802B7CA0[];
extern f32 lbl_80301358;
extern "C" void fn_80179CB4(void*, void*, f32, f32);
struct NaviState_8011093C;
typedef void (NaviState_8011093C::*NaviStateFn_8011093C)();
extern NaviStateFn_8011093C lbl_8028F100[];
extern "C" void fn_80060820(f32 a);
extern "C" void fn_8002F308(s32 a);
extern "C" void fn_8002F228(s32 a);
extern "C" s32 fn_8002F2E0(s32 a);
extern "C" s32 fn_8011171C(u8* self, s16 a, u8 b, u32 c, u32 d);
extern f32 lbl_8030134C;
extern u8 lbl_802C5B7C[];
extern void* lbl_802FF278;
extern "C" void fn_80111170(NaviState_8011093C* p) {
    (p->*lbl_8028F100[((u8*)p)[0x118]])();
}

extern "C" void fn_80111248(u8* self) {
    if (self[0x11c] != 0) {
        self[0x11c]--;
        return;
    }
    self[0x118] = 2;
}

extern "C" void fn_80111718(void)
{
}

extern "C" void fn_80111B00(void* param_1) {
    VObj_800A1A64* obj = *(VObj_800A1A64**)(lbl_802B7CA0 + 0x1394);
    obj->v3();
    f32 c = lbl_80301358;
    fn_80179CB4(*(void**)((char*)param_1 + 4), obj, c, c);
}

extern "C" void* fn_80111B64(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8028F1BC;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
