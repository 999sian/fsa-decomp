#include "types.h"


extern "C" void fn_80178990(void);
extern "C" void fn_8017A908(void) {
    fn_80178990();
}

extern "C" int fn_8017D1EC()
{
	return 0;
}

extern "C" int fn_801820CC(int param_1)
{
    return *(int*)(param_1 + 0x100);
}

extern void* lbl_80299504[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_8018C1A0(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80299504;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_8018E9EC(u32* p) {
    p[0] = 0;
    p[1] = 0;
}

