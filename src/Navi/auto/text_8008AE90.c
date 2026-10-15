#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8008ae90-0x8008bd90 (14 functions). split_file divides it into the game's real files.

extern void* lbl_80284A14[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void fn_8008AF98(void);
extern "C" void fn_8008AE90(void) {
    fn_8008AF98();
}

extern "C" void fn_8008AEB0(void);
extern "C" void fn_8008BC64(void) {
    fn_8008AEB0();
}

extern void fn_8008BA14(void* param);
extern s32 fn_800126C8(void* param1, void* param2, void* param3);
extern void fn_800636F4(void* param1, void* param2, s32 size);
extern void fn_800127A0(void* param);
extern u8 lbl_802FCE90;
extern u8 lbl_802FCE94;
extern f32 lbl_80300A54;
extern s8 lbl_802C5394[];
extern u8 lbl_8029FDB4[];
extern u32 lbl_80284940[];
extern u8 lbl_802B7CA0[];
s32 fn_8008BC84(void)
{
    void* addr = (void*)(0x802B7CA0 + 0x2200);
    fn_800636F4(&lbl_802FCE94, addr, 0x40);
    
    if (lbl_802C5394[4] >= 0) {
        u32 count = lbl_80284940[2] - 1;
        lbl_80284940[2] = count;
        if (count == 0) {
            fn_800127A0(&lbl_8029FDB4[4]);
            lbl_802C5394[4] = -1;
        }
    }
    return 1;
}

extern "C" void fn_8008B95C(void);
extern "C" void fn_8008BD00(void) {
    fn_8008B95C();
}

extern "C" void fn_8008B580(void);
extern "C" void fn_8008BD20(void) {
    fn_8008B580();
}

extern "C" BOOL fn_8008BD40()
{
	return TRUE;
}

extern "C" void* fn_8008BD48(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80284A14;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
