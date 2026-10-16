#include "types.h"
#include "JSystem/JGeometry/Vec.h"

extern "C" u32 fn_8011D4B4(int param_1) {
    return (u32)(__cntlzw(9 - *(int*)(param_1 + 0x234)) >> 5);
}

extern "C" s32 fn_8011D4C8(char* p) {
    return *(s32*)(p + 0x234);
}

extern "C" void fn_8010DF58(void);
extern "C" void fn_8010DF98(void);
extern "C" void fn_801D2608(void* p, void* a, s32 b);
extern "C" void fn_801D22DC(void* p, s32 a, s32 b, s32 c);
extern "C" void fn_801D1F14(void* p);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D7440(void* p, u32 a);
extern "C" void fn_8011D5F4(void) {
    fn_8010DF58();
}

extern "C" void fn_8011D77C(int param_1) {
    fn_8010DF98();
    fn_801D2608((void*)(param_1 + 0x274), (void*)0x80539F20, (s32)1);
    fn_801D22DC((void*)(param_1 + 0x274), 0, 2, 0);
    fn_801D1F14((void*)(param_1 + 0x274));
    
    register f32 f1, f0;
    f1 = 0.5f;
    f0 = -0.5f;
    *(f32*)(param_1 + 0x258) = f0;
    
    fn_802D6A9C();
    fn_802D7440(fn_802D6A9C(), 0);
}

