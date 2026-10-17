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

struct J2DScreenVt {
    virtual ~J2DScreenVt();
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
    virtual u32 m13(u32, u32, u32) = 0;
};

struct J2DScreenVt2 {
    virtual ~J2DScreenVt2();
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
    virtual u32 m12(u32, u32, u32) = 0;
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
extern "C" void* fn_804030C4(u32 type, const char* name);
extern const char* lbl_804B1CA0[];
extern void* lbl_80490C40[];
extern void* lbl_80490C78[];

static inline void* Create(void* obj, void** tbl, int i) {
    return ((void* (*)(void*, void*, void*, void*))(*(void***)obj)[15])(obj, tbl, tbl[i], tbl[i + 1]);
}

static inline void Attach(void* obj, void* handle) {
    ((void (*)(void*, void*, u32))(*(void***)obj)[68])(obj, handle, 0);
}
extern "C" void fn_8044A024(void* self_) {
    u8* self = (u8*)self_;
    fn_8013B490(lbl_8053AB10);
    f32 f = lbl_80543DB0;
    draw__9J2DScreenFffPC14J2DGrafContext(*(J2DScreen**)(self + 4), f, f, *(const J2DGrafContext**)(lbl_8053AB10 + 0x10));
}

extern "C" void fn_8044A06C(void* self_) {
    u8* self = (u8*)self_;
    void* handle;

    self[0x13] &= 0xFE;
    handle = fn_804030C4(0x54494D47, *(const char**)lbl_804B1CA0);
    Attach(Create(*(void**)(self + 4), lbl_80490C40, 4), handle);
    Attach(Create(*(void**)(self + 4), lbl_80490C40, 6), handle);
    Attach(Create(*(void**)(self + 4), lbl_80490C40, 8), handle);
    Attach(Create(*(void**)(self + 4), lbl_80490C40, 10), handle);
    self[0x13] &= 0xFD;
    handle = fn_804030C4(0x54494D47, *(const char**)lbl_804B1CA0);
    Attach(Create(*(void**)(self + 4), lbl_80490C78, 8), handle);
    Attach(Create(*(void**)(self + 4), lbl_80490C78, 10), handle);
    Attach(Create(*(void**)(self + 4), lbl_80490C78, 12), handle);
    Attach(Create(*(void**)(self + 4), lbl_80490C78, 14), handle);
    Attach(Create(*(void**)(self + 4), lbl_80490C78, 16), handle);
    Attach(Create(*(void**)(self + 4), lbl_80490C78, 18), handle);
    Attach(Create(*(void**)(self + 4), lbl_80490C78, 20), handle);
    Attach(Create(*(void**)(self + 4), lbl_80490C78, 22), handle);
    ((u8*)Create(*(void**)(self + 4), lbl_80490C40, 12))[0xb0] = 0;
    ((u8*)Create(*(void**)(self + 4), lbl_80490C78, 24))[0xb0] = 0;
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
    u32 a = 0x74613030;
    fn_80402F04(param_1[2], ((J2DScreenVt2*)param_1[1])->m12(0x4e0000, 0x4e6461, a));
    param_1[3] = new VObj2();
    u32 b = 0x74613031;
    fn_80402F04(param_1[3], ((J2DScreenVt2*)param_1[1])->m12(0x4e0000, 0x4e6461, b));
    ((u8*)param_1)[0x10] = 0;
    ((u8*)param_1)[0x11] = 0;
    ((u8*)param_1)[0x12] = 0;
    ((u8*)param_1)[0x13] = 0;
    return param_1;
}

