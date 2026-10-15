#include "types.h"

extern "C" void fn_8010DF58();
extern "C" void fn_8010DF98();
extern "C" void fn_801D2608(void* p, u32 a, u32 b);
extern "C" void fn_801D22DC(void* p, u32 a, u32 b, u32 c);
extern "C" void fn_801D1F14(void* p);
extern "C" void* fn_802D6A9C();
extern "C" void fn_802D7440(void* p, u32 a);
extern "C" void __dt__13Base_8010E074Fv(void* p, int how);
extern "C" void fn_801EE434(void* p);
extern void operator delete(void* p);
extern f32 lbl_8053C7D0;

extern void* lbl_8049DB30[];
extern void* lbl_8049CC34[];

extern f32 lbl_8053C7D0;
extern "C" u32 fn_8011AAB0(void* param_1) {
    u32 val = *(u32*)((u8*)param_1 + 0x234);
    return ((3U - val) | (val - 3U)) >> 31;
}

extern "C" s32 fn_8011AAC8(char* p) {
    return *(s32*)(p + 0x234);
}
