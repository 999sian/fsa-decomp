#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8008be14-0x8008db20 (36 functions). split_file divides it into the game's real files.

extern void* lbl_80284C98[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void fn_8008BE64(void);
extern char lbl_802BB0FC[];
extern char lbl_801FDAC8[];
extern f32 lbl_802C53E4[];
extern "C" void fn_8008D820(void* p, s32 n);
extern void* lbl_8024751C[];
extern "C" void fn_8008BE14(void* p);
extern "C" void fn_8008BE14(void* p) {
    f32* f = (f32*)p;
    *(void**)p = lbl_8024751C;
    f[1] = 0.0f;
    f[2] = 0.0f;
    f[3] = 0.0f;
    f[4] = 1.0f;
    f[5] = 1.0f;
    f[6] = 1.0f;
}

extern "C" void fn_8008BE44(void) {
    fn_8008BE64();
}

extern "C" BOOL fn_8008C4D4(void);
extern "C" BOOL fn_8008C4D4(void)
{
    return TRUE;
}

extern "C" void fn_8008C5F4(void);
extern "C" void fn_8008C4DC(void) {
    fn_8008C5F4();
}

extern "C" void fn_8008C4FC(void);
extern "C" void fn_8008D420(void) {
    fn_8008C4FC();
}

extern "C" void fn_8008C994(void);
extern "C" void fn_8008D4BC(void) {
    fn_8008C994();
}

extern "C" BOOL fn_8008D5B4(void);
extern "C" BOOL fn_8008D5B4(void)
{
    return TRUE;
}

extern char lbl_802BB0FC[];
extern char lbl_801FDAC8[];
extern f32 lbl_802C53E4[];
extern "C" void fn_8008D820(void* p, s32 n);
extern "C" void fn_8008DA68(void* p) {
    s32 idx = *(s32*)(lbl_802BB0FC + 0x424);
    u32* src = (u32*)(lbl_801FDAC8 + idx * 12);
    u32* dst = (u32*)p;
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
}

extern "C" void* fn_8008DAD8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80284C98;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
