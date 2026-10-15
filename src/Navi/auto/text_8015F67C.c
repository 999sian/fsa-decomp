#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8015f67c-0x8015ffac (18 functions). split_file divides it into the game's real files.

extern "C" void fn_8015AB1C(void*);
extern "C" void fn_8015D29C(void*, int);
extern char lbl_80297BD4[];
extern "C" void fn_801BDDBC(void*, void*, int);
extern "C" void fn_801BDEE4(void*, void*, int);
extern "C" void fn_8015F814(void);
extern "C" void* fn_8015D13C(void*, int, int, void*);
extern "C" void fn_801C0EEC(void*);
extern "C" void* fn_8015A9A8(int, void*, int);
extern "C" void fn_8015FB6C(int, int, int);
extern "C" BOOL fn_8015F80C();
extern "C" void* fn_8015F6EC(void*, void*);
extern int lbl_802FF5E0;
extern void* lbl_802FF540;
extern void* lbl_80297B40;
extern void* lbl_80297B30;
extern "C" void* fn_8015F73C(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_80297BD4;
        fn_8015D29C(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" BOOL fn_8015F80C()
{
	return TRUE;
}

