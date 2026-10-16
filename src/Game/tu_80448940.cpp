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
