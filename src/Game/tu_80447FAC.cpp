#include "types.h"
#include "JSystem/J2D/J2DPane.h"

extern "C" void __dl__FPv(void*);
extern "C" u8 lbl_804B1C58[];
extern "C" u32 lbl_8053AF10;

struct fn_804484C8_Obj {
    virtual void Release(int);
};
struct J2DScreen {
    u8 pad[0x100];
    u8 b100;
};

extern "C" void fn_8013B490(void*);
extern u8* lbl_8053AB10;
extern f32 lbl_80543DA0;
struct J2DGrafContext;
extern "C" void draw__9J2DScreenFffPC14J2DGrafContext(J2DScreen*, f32, f32, const J2DGrafContext*);

extern "C" void fn_804482EC(void* self_) {
    u8* self = (u8*)self_;
    fn_8013B490(lbl_8053AB10);
    f32 f = lbl_80543DA0;
    draw__9J2DScreenFffPC14J2DGrafContext(*(J2DScreen**)(self + 4), f, f, *(const J2DGrafContext**)(lbl_8053AB10 + 0x10));
}

extern "C" void* fn_804484C8(void* param_1, short param_2)
{
    void* result = param_1;

    if (result != 0) {
        *(void**)result = (void*)lbl_804B1C58;

        if (((fn_804484C8_Obj**)result)[1] != 0) {
            ((fn_804484C8_Obj**)result)[1]->Release(1);
        }
        ((fn_804484C8_Obj**)result)[1] = 0;

        fn_804484C8_Obj** ptr = (fn_804484C8_Obj**)result;
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

        lbl_8053AF10 = 0;

        if (param_2 > 0) {
            __dl__FPv(result);
        }
    }

    return result;
}

