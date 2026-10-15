#include "types.h"

extern "C" void fn_8013B490(void*);

extern u8* lbl_8053AB10;
extern f32 lbl_80543D38;

struct J2DGrafContext;
struct J2DScreen {
    u8 pad[0x100];
    u8 b100;
};

extern "C" void draw__9J2DScreenFffPC14J2DGrafContext(J2DScreen*, f32, f32, const J2DGrafContext*);

struct Obj4 {
    virtual void f00();
    virtual void f04();
    virtual void f08();
    virtual void f0c();
    virtual void f10();
    virtual void f14();
    virtual void f18();
    virtual void f1c();
    virtual void f20();
    virtual void f24();
    virtual void f28();
    virtual void f2c();
    virtual void f30();
    virtual void f34();
    virtual void f38();
    virtual void* fn(u32, u32, u32);
};
