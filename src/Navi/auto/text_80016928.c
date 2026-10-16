#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80016928-0x8001757c (13 functions). split_file divides it into the game's real files.

extern void* lbl_80205090[];
extern "C" void fn_8015AB1C(void* ptr);
extern char lbl_8029FDB4[];
extern char lbl_80205058[];
extern char lbl_802B488C[];
extern "C" void fn_8001A53C(void);
extern "C" void fn_80019A24(void);
extern "C" void fn_8001978C(void);
extern "C" void fn_8001D288(s32, void (*)(void));
extern "C" void fn_801149B0(s32);
extern "C" void fn_8001D434(void);
extern "C" void fn_8001A59C(void);
extern "C" void fn_80019AE0(void);
extern "C" void fn_80019790(void);
extern "C" void fn_8001AB40(void);
extern "C" void fn_8001A4AC(s32, s32, s32, s32);
extern "C" u8 fn_800126C8(void*, void*, void*);
extern "C" void fn_80017468(void)
{
    fn_8001A53C();
    fn_80019A24();
    fn_8001978C();
}

extern "C" void fn_80017490(void)
{
    fn_8001D288(0, fn_80017468);
    fn_801149B0(0);
}

extern "C" void fn_800174C4(void)
{
    fn_8001D434();
    fn_8001A59C();
    fn_80019AE0();
    fn_80019790();
    fn_8001AB40();
    fn_8001A4AC(1, 0x7fff, 0, 0);
    lbl_802B488C[4] = fn_800126C8(lbl_8029FDB4 + 4, lbl_80205058, lbl_802B488C);
}

extern "C" void* fn_80017534(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80205090;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
