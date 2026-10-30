#include "types.h"

extern "C" void __dl__FPv(void*);
extern "C" u8 lbl_804B19F0[];
extern "C" u32 lbl_8053AEE0;

struct fn_80442368_Obj {
    virtual void Release(int);
};

extern "C" void* fn_80442368(void* param_1, short param_2)
{
    void* result = param_1;

    if (result != 0) {
        *(void**)result = (void*)lbl_804B19F0;

        if (((fn_80442368_Obj**)result)[1] != 0) {
            ((fn_80442368_Obj**)result)[1]->Release(1);
        }
        ((fn_80442368_Obj**)result)[1] = 0;

        if (((fn_80442368_Obj**)result)[2] != 0) {
            ((fn_80442368_Obj**)result)[2]->Release(1);
        }
        ((fn_80442368_Obj**)result)[2] = 0;

        if (((fn_80442368_Obj**)result)[3] != 0) {
            ((fn_80442368_Obj**)result)[3]->Release(1);
        }
        ((fn_80442368_Obj**)result)[3] = 0;

        lbl_8053AEE0 = 0;

        if (param_2 > 0) {
            __dl__FPv(result);
        }
    }

    return result;
}
