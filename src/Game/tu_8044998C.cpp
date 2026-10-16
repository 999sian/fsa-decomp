#include "types.h"
struct J2DScreen {
    J2DScreen();
    u8 pad[0x118];
};


extern "C" {
extern void* lbl_804B1CC8[];
extern int lbl_8053AF20;
extern void __dl__FPv(void* obj);

    typedef void (*DestructorFunc)(void*, int);
}

struct VObj {
    virtual ~VObj();
};

struct VObj2 {
    virtual ~VObj2();
    u8 pad[0x28];
};

extern "C" {
extern char lbl_80490DA8[];
extern void* lbl_80529DEC[];
extern void setPriority__9J2DScreenFPCcUlP10JKRArchive(J2DScreen*, const char*, u32, void*);
extern void fn_80402F04(void*, u32);
}

extern "C" void fn_8013B490(void*);
extern u8* lbl_8053AB10;
extern f32 lbl_80543DB0;
struct J2DGrafContext;
extern "C" void draw__9J2DScreenFffPC14J2DGrafContext(J2DScreen*, f32, f32, const J2DGrafContext*);
extern "C" void fn_8044A024(void* self_) {
    u8* self = (u8*)self_;
    fn_8013B490(lbl_8053AB10);
    f32 f = lbl_80543DB0;
    draw__9J2DScreenFffPC14J2DGrafContext(*(J2DScreen**)(self + 4), f, f, *(const J2DGrafContext**)(lbl_8053AB10 + 0x10));
}

extern "C" void* fn_8044A418(VObj** param_1, short param_2) {
    if (param_1 != 0) {
        *(void**)param_1 = lbl_804B1CC8;
        delete param_1[1];
        param_1[1] = 0;
        for (int i = 0; i < 2; i++) {
            delete param_1[2 + i];
            param_1[2 + i] = 0;
        }
        lbl_8053AF20 = 0;
        if (param_2 > 0) {
            __dl__FPv(param_1);
        }
    }
    return param_1;
}

extern "C" void* fn_8044A4D4(void** param_1) {
    *param_1 = lbl_804B1CC8;
    lbl_8053AF20 = (int)param_1;
    param_1[1] = new J2DScreen();
    setPriority__9J2DScreenFPCcUlP10JKRArchive((J2DScreen*)param_1[1], lbl_80490DA8, 0x1100000, lbl_80529DEC[4]);
    param_1[2] = new VObj2();
    u32 r = (*(u32 (**)(void*, u32, u32, u32))(*(u8**)param_1[1] + 0x3c))(param_1[1], 0x4e0000, 0x4e6461, 0x74613030);
    fn_80402F04(param_1[2], r);
    param_1[3] = new VObj2();
    r = (*(u32 (**)(void*, u32, u32, u32))(*(u8**)param_1[1] + 0x3c))(param_1[1], 0x4e0000, 0x4e6461, 0x74613031);
    fn_80402F04(param_1[3], r);
    ((u8*)param_1)[0x10] = 0;
    ((u8*)param_1)[0x11] = 0;
    ((u8*)param_1)[0x12] = 0;
    ((u8*)param_1)[0x13] = 0;
    return param_1;
}

