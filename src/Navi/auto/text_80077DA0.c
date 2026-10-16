#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80077da0-0x8007bc94 (37 functions). split_file divides it into the game's real files.

extern void* lbl_80282198[];
extern void* lbl_80281950[];
extern void* lbl_8028216C[];
extern void* lbl_80281904[];
extern char lbl_802FCB30[];
extern char lbl_802B7CA0[];
extern char lbl_802BB0FC[];
extern char lbl_802C4F3C[];
extern char lbl_8029FDB4[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_80077F44(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80282198;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" BOOL fn_8007820C(void);
extern "C" BOOL fn_8007820C(void)
{
    return TRUE;
}

extern "C" void fn_80078414(void);
extern "C" void fn_80078364(void) {
    fn_80078414();
}

extern "C" u8 fn_8000D6F4(void* param_1);
extern "C" BOOL fn_8007A190(void* param_1) {
    char* p = (char*)param_1;
    if (p[0x443] == 0) {
        p[0x443] = p[0x443] + 1;
    } else if (p[0x443] != -1) {
        float* sample;
        p[0x447] = fn_8000D6F4(p + 0x38c);
        sample = *(float**)(p + 0x390);
        if (sample[3] < 0.0f) {
            if (*(float*)(p + 0x40c) < sample[4]) {
                p[0x447] = 1;
            }
        } else if (sample[3] > 0.0f) {
            if (*(float*)(p + 0x40c) > sample[4]) {
                p[0x447] = 1;
            }
        }
        *(float*)(p + 0x40c) = (*(float**)(p + 0x390))[4];
    }
    return TRUE;
}

extern "C" void fn_80078384(void);
extern "C" void fn_8007BB2C(void) {
    fn_80078384();
}

extern "C" void fn_8007B638(void);
extern "C" void fn_8007BBD8(void) {
    fn_8007B638();
}

extern "C" void fn_80078F94(void);
extern "C" void fn_8007BBF8(void) {
    fn_80078F94();
}

extern "C" BOOL fn_8007BC18(void);
extern "C" BOOL fn_8007BC18(void)
{
    return TRUE;
}

