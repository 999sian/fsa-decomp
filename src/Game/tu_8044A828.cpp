#include "types.h"
struct J2DScreen;
struct J2DGrafContext;

struct VObj {
    virtual ~VObj();
};

extern "C" {
extern void* lbl_804B1D00[];
extern int lbl_8053AF28;
extern void __dl__FPv(void* obj);
extern void fn_8013B490(void*);
extern void draw__9J2DScreenFffPC14J2DGrafContext(J2DScreen*, f32, f32, const J2DGrafContext*);
}
extern u8* lbl_8053AB10;
extern f32 lbl_80543DB8;

extern "C" void fn_8044AF90(void* self_) {
    u8* self = (u8*)self_;
    fn_8013B490(lbl_8053AB10);
    f32 f = lbl_80543DB8;
    draw__9J2DScreenFffPC14J2DGrafContext(*(J2DScreen**)(self + 4), f, f, *(const J2DGrafContext**)(lbl_8053AB10 + 0x10));
}

extern "C" void* fn_8044B3FC(VObj** param_1, short param_2) {
    if (param_1 != 0) {
        *(void**)param_1 = lbl_804B1D00;
        delete param_1[1];
        param_1[1] = 0;
        for (int i = 0; i < 2; i++) {
            delete param_1[2 + i];
            param_1[2 + i] = 0;
        }
        lbl_8053AF28 = 0;
        if (param_2 > 0) {
            __dl__FPv(param_1);
        }
    }
    return param_1;
}

