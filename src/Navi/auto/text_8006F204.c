#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8006f204-0x80070d28 (26 functions). split_file divides it into the game's real files.

extern void* lbl_80280CEC[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void fn_80132450(s16, s16, s16, void*);
extern "C" void fn_80070454(void* ptr, u8 val)
{
    ((u8*)ptr)[0x2fa] = val;
    ((u8*)ptr)[0x2fb] = 0;
}

extern "C" void* fn_80070464(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void fn_800704A0(void)
{
}

extern "C" BOOL fn_800704C4(void);
extern "C" void fn_800704A4(void) {
    fn_800704C4();
}

extern "C" BOOL fn_800704C4(void)
{
    return TRUE;
}

extern "C" void fn_800708F8(void* param)
{
    u8* base = (u8*)param;
    void** ptrs = (void**)param;
    s16 val0 = *(s16*)(base + 0x20);
    s16 val1 = *(s16*)(base + 0x22);
    s16 val2 = *(s16*)(base + 0x24);
    f32 fval0 = *(f32*)(base + 0x14);
    f32 fval1 = *(f32*)(base + 0x18);
    f32 fval2 = *(f32*)(base + 0x1c);
    
    for (int i = 0; i < 2; i++) {
        void* obj = ptrs[i];
        if (obj != NULL) {
            *(f32*)((u8*)obj + 0xa4) = fval0;
            *(f32*)((u8*)obj + 0xa8) = fval1;
            *(f32*)((u8*)obj + 0xac) = fval2;
            fn_80132450(val0, val1, val2, (u8*)obj + 0x68);
        }
    }
}

extern "C" void fn_800709B4(void* param_1, u8** param_2) {
    for (s32 i = 0; i < 2; i++) {
        u8* p = param_2[i];
        if (p != nullptr) {
            *(u32*)(p + 0xF4) |= 1;
            *(s32*)(p + 0x24) = 1;
            param_2[i] = nullptr;
        }
    }
}

extern "C" void fn_8004A380(void);
extern "C" void fn_8004A550(void);
extern "C" void fn_8003E6C4(f32);
extern "C" void fn_800704CC(void*);
extern u8 lbl_802C01B4[];
extern "C" s32 fn_80070C68(void* param_1) {
    fn_8004A380();
    fn_8004A550();
    fn_8003E6C4(*(f32*)(lbl_802C01B4 + 0xA0));
    fn_800704CC(param_1);
    return 1;
}

extern "C" void fn_8004ACA4(void*, void*);
extern "C" s32 fn_80070CB4(void* tag, void* data) {
    fn_8004ACA4(tag, data);
    return 1;
}

extern "C" int fn_80070CD8(void)
{
    return 1;
}

extern "C" void* fn_80070CE0(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80280CEC;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
