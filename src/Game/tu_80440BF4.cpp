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
    virtual void* fn(u32, u32, u32);
};
extern "C" void fn_80440BF4(void* self_, u8 flag) {
    if (flag) {
        u8* self = (u8*)self_;
        Obj4* obj = (Obj4*)*(void**)(self + 4);
        void* r = obj->fn(0x62620000u, 0x50u, 0x62623033u);
        *(u8*)((u8*)r + 0xb0) = 1;
    } else {
        u8* self = (u8*)self_;
        Obj4* obj = (Obj4*)*(void**)(self + 4);
        void* r = obj->fn(0x62620000u, 0x50u, 0x62623033u);
        *(u8*)((u8*)r + 0xb0) = 0;
    }
}
#pragma scheduling reset
extern "C" void fn_80440C6C(void* self_, u8 flag) {
    u8* self = (u8*)self_;
    Obj4* obj = (Obj4*)*(void**)(self + 4);
    if (flag) {
        void* r = obj->fn(0x62610000, 0x50, 0x62613034);
        *(u8*)((u8*)r + 0xb0) = 1;
    } else {
        void* r = obj->fn(0x62620000, 0x50, 0x62623033);
        *(u8*)((u8*)r + 0xb0) = 0;
    }
}

extern "C" void fn_80440EE8(void* self_) {
    u8* self = (u8*)self_;
    fn_8013B490(lbl_8053AB10);
    f32 f = lbl_80543D38;
    draw__9J2DScreenFffPC14J2DGrafContext(*(J2DScreen**)(self + 4), f, f, *(const J2DGrafContext**)(lbl_8053AB10 + 0x10));
}
