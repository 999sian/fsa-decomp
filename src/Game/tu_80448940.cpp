#include "JSystem/J2D/J2DPane.h"


extern "C" void fn_8013B490(void*);
extern unsigned char* lbl_8053AB10;
extern float lbl_80543DA8;
struct J2DGrafContext;
struct J2DScreen;
extern "C" void draw__9J2DScreenFffPC14J2DGrafContext(J2DScreen*, float, float, const J2DGrafContext*);
struct fn_80449494_Obj {
    virtual void Release(int);
};

extern "C" void fn_80449070(void* self_) {
    u8* self = (u8*)self_;
    fn_8013B490(lbl_8053AB10);
    f32 f = lbl_80543DA8;
    draw__9J2DScreenFffPC14J2DGrafContext(*(J2DScreen**)(self + 4), f, f, *(const J2DGrafContext**)(lbl_8053AB10 + 0x10));
}

extern "C" void __dl__FPv(void*);
extern "C" u8 lbl_804B1C90[];
extern u8* lbl_8053AF18;
extern "C" void* fn_80449494(void* param_1, short param_2) {
    void* result = param_1;

    if (result != 0) {
        *(void**)result = (void*)lbl_804B1C90;

        if (((fn_80449494_Obj**)result)[1] != 0) {
            ((fn_80449494_Obj**)result)[1]->Release(1);
        }
        ((fn_80449494_Obj**)result)[1] = 0;

        if (((fn_80449494_Obj**)result)[2] != 0) {
            ((fn_80449494_Obj**)result)[2]->Release(1);
        }
        ((fn_80449494_Obj**)result)[2] = 0;

        fn_80449494_Obj** ptr = (fn_80449494_Obj**)result;
        int i = 0;
        do {
            if (ptr[3] != 0) {
                ptr[3]->Release(1);
            }
            ptr[3] = 0;
            if (ptr[7] != 0) {
                ptr[7]->Release(1);
            }
            i++;
            ptr[7] = 0;
            ptr++;
        } while (i < 4);

        lbl_8053AF18 = 0;

        if (param_2 > 0) {
            __dl__FPv(result);
        }
    }

    return result;
}

