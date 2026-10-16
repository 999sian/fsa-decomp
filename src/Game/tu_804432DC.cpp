#include "types.h"

struct J2DScreenVt {
    virtual void m0(void);
    virtual void m1(void);
    virtual void m2(void);
    virtual void m3(void);
    virtual void m4(void);
    virtual void m5(void);
    virtual void m6(void);
    virtual void m7(void);
    virtual void m8(void);
    virtual void m9(void);
    virtual void m10(void);
    virtual void m11(void);
    virtual void m12(void);
    virtual void* m15(u32, u32, u32);
};

struct Slot0 {
    virtual void slot0(int);
};

extern "C" void __dl__FPv(void* this_);
extern void* lbl_804B1AE8[];
extern s32 lbl_8053AEF0;
extern "C" void* lbl_8053AB10;
extern "C" f32 lbl_80543D60;
extern "C" void fn_8013B490(void* p);
extern "C" void draw__9J2DScreenFffPC14J2DGrafContext(void* screen, f32 x, f32 y, void* ctx);
extern "C" void fn_80443494(void* this_) {
    char* p = (char*)this_;
    s32 v = *(s16*)(p + 0x12);
    if (v > 0) {
        *(s16*)(p + 0x12) = v - 1;
        return;
    }
    *(u8*)(p + 0x15) = 3;
}

extern "C" void fn_80402B10(void* this_, s32 a, s32 b, f32 c, f32 d);
extern "C" void fn_80402940(void* this_, s32 a, s32 b, f32 c, f32 d);
extern "C" void fn_8040271C(void* this_, s32 a, f32 c, f32 d);
extern u8 lbl_8048FB88[];
extern f32 lbl_80543D64;
extern "C" void fn_804434B8(void* this_) {
    char* p = (char*)this_;
    char* tbl = (char*)lbl_8048FB88;
    *(s16*)(p + 0x10) = *(s16*)(p + 0x10) + 1;
    fn_80402B10(*(void**)(p + 0x8), 0x1e, 0, lbl_80543D60, ((s16*)(tbl + 0x1c))[*(u8*)(p + 0x14)]);
    fn_80402940(*(void**)(p + 0x8), 0x1e, 0, lbl_80543D60, ((s16*)(tbl + 0x2c))[*(u8*)(p + 0x14)]);
    fn_8040271C(*(void**)(p + 0x8), 0x1e, lbl_80543D64, ((f32*)tbl)[*(u8*)(p + 0x14)] / ((f32*)*(void**)(p + 0x8))[6]);
    if (*(s16*)(p + 0x10) >= 0x1e) {
        *(u8*)(p + 0x15) = 2;
    }
}

extern "C" void fn_804435B8(void* this_) {
    char* p = (char*)this_;
    s32 v = *(s16*)(p + 0x10);
    if (v > 0) {
        *(s16*)(p + 0x10) = v - 1;
        return;
    }
    *(s16*)(p + 0x10) = 0;
    *(u8*)(p + 0x15) = 1;
}

extern "C" void fn_804435E4(void* this_) {
    char* p = (char*)this_;
    if (*(u8*)(p + 0x15) != 3) {
        fn_8013B490(lbl_8053AB10);
        draw__9J2DScreenFffPC14J2DGrafContext(*(void**)(p + 0x4), lbl_80543D60, lbl_80543D60, ((void**)lbl_8053AB10)[4]);
    }
}

extern "C" void fn_8013B490(void* p);
extern "C" void draw__9J2DScreenFffPC14J2DGrafContext(void* screen, f32 x, f32 y, void* ctx);
extern "C" void* lbl_8053AB10;
extern "C" f32 lbl_80543D60;
extern "C" void fn_80443688(void) {
}

extern "C" void* fn_8044368C(void* this_, s16 flag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804B1AE8;
        void* p1 = *(void**)((char*)this_ + 0x4);
        if (p1 != 0) {
            ((Slot0*)p1)->slot0(1);
        }
        *(void**)((char*)this_ + 0x4) = 0;
        void* p2 = *(void**)((char*)this_ + 0x8);
        if (p2 != 0) {
            ((Slot0*)p2)->slot0(1);
        }
        *(void**)((char*)this_ + 0x8) = 0;
        void* p3 = *(void**)((char*)this_ + 0xc);
        if (p3 != 0) {
            ((Slot0*)p3)->slot0(1);
        }
        *(void**)((char*)this_ + 0xc) = 0;
        lbl_8053AEF0 = 0;
        if (flag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void* __nw__FUl(unsigned long size);
extern "C" void __ct__9J2DScreenFv(void* self);
extern "C" void setPriority__9J2DScreenFPCcUlP10JKRArchive(void* pane, const char* name, unsigned long id, void* archive);
extern "C" void fn_80402F04(void* a, void* b);
extern "C" u8 lbl_804AF86C[];
extern "C" u8 lbl_8048FBC4[];
extern "C" u8 lbl_80529DEC[];
extern "C" void* fn_80443760(void* this_) {
    u8* self = (u8*)this_;
    *(void**)self = (void*)lbl_804B1AE8;
    lbl_8053AEF0 = (s32)self;

    void* screen = __nw__FUl(0x118);
    if (screen != 0) {
        __ct__9J2DScreenFv(screen);
    }
    *(void**)(self + 4) = screen;
    setPriority__9J2DScreenFPCcUlP10JKRArchive(*(void**)(self + 4), (const char*)lbl_8048FBC4, 0x1100000, *(void**)(lbl_80529DEC + 0x10));

    void* obj = __nw__FUl(0x2c);
    if (obj != 0) {
        *(void**)obj = (void*)lbl_804AF86C;
    }
    *(void**)(self + 8) = obj;
    fn_80402F04(*(void**)(self + 8), ((J2DScreenVt*)*(void**)(self + 4))->m15(0x50740000, 0x50746573, 0x746d6170));

    obj = __nw__FUl(0x2c);
    if (obj != 0) {
        *(void**)obj = (void*)lbl_804AF86C;
    }
    *(void**)(self + 12) = obj;
    fn_80402F04(*(void**)(self + 12), ((J2DScreenVt*)*(void**)(self + 4))->m15(0x500000, 0x506d61, 0x7074656e));

    self[0x14] = 0;
    *(s16*)(self + 0x10) = 0;
    *(s16*)(self + 0x12) = 0;
    self[0x15] = 3;
    return this_;
}

