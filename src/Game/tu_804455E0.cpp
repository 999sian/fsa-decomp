#include "JSystem/J2D/J2DPane.h"
#include "JSystem/J2D/J2DScreen.h"

struct fn_804461D0_Self {
    void* vt;
    J2DScreen* screen;
    void* a[4];
    void* b[4];
    void* c[4];
    u8 d[4];
    u8 e[4];
    u8 f[4];
    u8 g;
};
extern "C" u64 lbl_8048FC08[];
extern "C" char lbl_80490020[];
extern "C" u8 lbl_80529DEC[];
extern "C" u8 lbl_804AF86C[];
extern "C" void fn_80402F04(void*, void*);


extern "C" void fn_8013B490(void*);
extern u8* lbl_8053AB10;
extern f32 lbl_80543D88;
struct J2DGrafContext;
extern "C" void draw__9J2DScreenFffPC14J2DGrafContext(J2DScreen*, f32, f32, const J2DGrafContext*);
struct fn_804460AC_Obj {
    virtual void Release(int);
};

extern "C" void fn_80445CDC(void* self_) {
    u8* self = (u8*)self_;
    fn_8013B490(lbl_8053AB10);
    f32 f = lbl_80543D88;
    draw__9J2DScreenFffPC14J2DGrafContext(*(J2DScreen**)(self + 4), f, f, *(const J2DGrafContext**)(lbl_8053AB10 + 0x10));
}

extern "C" void __dl__FPv(void*);
extern "C" u8 lbl_804B1BB0[];
extern u8* lbl_8053AEF8;
extern "C" void* fn_804460AC(void* param_1, short param_2) {
    void* result = param_1;

    if (result != 0) {
        *(void**)result = (void*)lbl_804B1BB0;

        if (((fn_804460AC_Obj**)result)[1] != 0) {
            ((fn_804460AC_Obj**)result)[1]->Release(1);
        }
        ((fn_804460AC_Obj**)result)[1] = 0;

        fn_804460AC_Obj** ptr = (fn_804460AC_Obj**)result;
        int i = 0;
        do {
            if (ptr[2] != 0) {
                ptr[2]->Release(1);
            }
            ptr[2] = 0;
            if (ptr[6] != 0) {
                ptr[6]->Release(1);
            }
            ptr[6] = 0;
            if (ptr[10] != 0) {
                ptr[10]->Release(1);
            }
            i++;
            ptr[10] = 0;
            ptr++;
        } while (i < 4);

        lbl_8053AEF8 = 0;

        if (param_2 > 0) {
            __dl__FPv(result);
        }
    }

    return result;
}

