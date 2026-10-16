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
struct J2DScreenVT {
    virtual void m0() = 0;
    virtual void m1() = 0;
    virtual void m2() = 0;
    virtual void m3() = 0;
    virtual void m4() = 0;
    virtual void m5() = 0;
    virtual void m6() = 0;
    virtual void m7() = 0;
    virtual void m8() = 0;
    virtual void m9() = 0;
    virtual void m10() = 0;
    virtual void m11() = 0;
    virtual void m12() = 0;
    virtual void m13() = 0;
    virtual void m14() = 0;
    virtual u32 m15(u32, u32, u32) = 0;
};
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

extern void __ct__9J2DScreenFv(J2DScreen* self);
extern void setPriority__9J2DScreenFPCcUlP10JKRArchive(J2DScreen* self, const char* name, u32 flags, void* archive);
extern "C" void* __nw__FUl(u32 size);
extern "C" void fn_80402F04(void* self, u32 value);
extern "C" void* lbl_804AF86C[];
extern "C" char lbl_80490F30[];
extern "C" u8 lbl_80529DEC[];
extern "C" void* fn_8044B4B8(VObj** param_1) {
    *(void**)param_1 = lbl_804B1D00;
    lbl_8053AF28 = (int)param_1;
    J2DScreen* screen = (J2DScreen*)__nw__FUl(0x118);
    if (screen != 0) {
        __ct__9J2DScreenFv(screen);
    }
    param_1[1] = (VObj*)screen;
    setPriority__9J2DScreenFPCcUlP10JKRArchive((J2DScreen*)param_1[1], lbl_80490F30, 0x1100000, *(void**)(lbl_80529DEC + 0x10));
    VObj* a = (VObj*)__nw__FUl(0x2c);
    if (a != 0) {
        *(void**)a = lbl_804AF86C;
    }
    param_1[2] = a;
    fn_80402F04(param_1[2], ((u32 (*)(void*, u32, u32, u32))(*(void***)param_1[1])[15])(param_1[1], 0x4e0000, 0x4e6461, 0x74613030));
    VObj* b = (VObj*)__nw__FUl(0x2c);
    if (b != 0) {
        *(void**)b = lbl_804AF86C;
    }
    param_1[3] = b;
    fn_80402F04(param_1[3], ((u32 (*)(void*, u32, u32, u32))(*(void***)param_1[1])[15])(param_1[1], 0x4e0000, 0x4e6461, 0x74613031));
    *(u16*)(param_1 + 4) = 0;
    *(u8*)((u8*)param_1 + 0x12) = 0;
    *(u8*)((u8*)param_1 + 0x13) = 0;
    *(u8*)((u8*)param_1 + 0x14) = 0;
    return param_1;
}

