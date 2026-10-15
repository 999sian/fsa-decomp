#include "types.h"

extern "C" void __dl__FPv(void*);
extern "C" u8 lbl_804B1BE8[];
extern "C" u32 lbl_8053AF00;

struct fn_80447190_Obj {
    virtual void Release(int);
};

extern "C" void* fn_80447190(void* param_1, short param_2)
{
    void* result = param_1;

    if (result != 0) {
        *(void**)result = (void*)lbl_804B1BE8;

        if (((fn_80447190_Obj**)result)[1] != 0) {
            ((fn_80447190_Obj**)result)[1]->Release(1);
        }
        ((fn_80447190_Obj**)result)[1] = 0;

        fn_80447190_Obj** ptr = (fn_80447190_Obj**)result;
        int i = 0;
        do {
            if (ptr[2] != 0) {
                ptr[2]->Release(1);
            }
            ptr[2] = 0;
            if (ptr[6] != 0) {
                ptr[6]->Release(1);
            }
            i++;
            ptr[6] = 0;
            ptr++;
        } while (i < 4);

        lbl_8053AF00 = 0;

        if (param_2 > 0) {
            __dl__FPv(result);
        }
    }

    return result;
}
