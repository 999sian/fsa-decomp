#include "types.h"

struct ScreenTransitionState {
    void* vtable;
    void* screen;
    f32* pane;
    void* other;
    s16 timer;
    s16 delay;
    u8 index;
    u8 state;
};

struct ScreenTransitionTable {
    f32 scale[7];
    s16 x[8];
    s16 y[8];
};

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
extern u8 lbl_8048FB88[];
extern "C" const f32 lbl_80543D64;
extern "C" void fn_80402E08(void* this_, f32 a, f32 b);
extern "C" void fn_80402CE0(void* this_, f32 a, f32 b);
extern "C" void* lbl_8053AB10;
extern "C" const f32 lbl_80543D60;
extern "C" void fn_8013B490(void* p);
extern "C" void draw__9J2DScreenFffPC14J2DGrafContext(void* screen, f32 x, f32 y, void* ctx);
class J2DScreen;
class JKRArchive;
struct J2DGrafContext;
extern "C" s32 fn_804432DC(void* this_, u8 cmd, s16 a, s16 b) {
    u8* p = (u8*)this_;
    char* tbl = (char*)lbl_8048FB88;
    if (cmd < 8 && p[0x15] == 3) {
        p[0x14] = cmd;
        *(s16*)(p + 0x10) = a;
        *(s16*)(p + 0x12) = b;
        if (cmd == 0) {
            *(s16*)(*(char**)(p + 0x8) + 0x20) = 0;
            *(s16*)(*(char**)(p + 0x8) + 0x22) = 0;
            *(s16*)(*(char**)(p + 0x8) + 0x24) = 0;
            fn_80402E08(*(void**)(p + 0x8), lbl_80543D60, lbl_80543D60);
            fn_80402CE0(*(void**)(p + 0x8), lbl_80543D64, lbl_80543D64);
            *(u8*)(*(char**)(*(char**)(p + 0x8) + 0x4) + 0xb0) = 1;
            *(u8*)(*(char**)(*(char**)(p + 0xc) + 0x4) + 0xb0) = 0;
            p[0x15] = 0;
        } else if (cmd == 7) {
            *(u8*)(*(char**)(*(char**)(p + 0x8) + 0x4) + 0xb0) = 0;
            *(u8*)(*(char**)(*(char**)(p + 0xc) + 0x4) + 0xb0) = 1;
            p[0x15] = 2;
        } else {
            *(s16*)(*(char**)(p + 0x8) + 0x20) = 0;
            *(s16*)(*(char**)(p + 0x8) + 0x22) = 0;
            *(s16*)(*(char**)(p + 0x8) + 0x24) = 0;
            u8 idx = p[0x14];
            f32 x = (f32)((s16*)(tbl + 0x1c))[idx];
            f32 y = (f32)((s16*)(tbl + 0x2c))[idx];
            fn_80402E08(*(void**)(p + 0x8), x, y);
            f32 z = ((f32*)tbl)[idx] / ((f32*)*(void**)(p + 0x8))[6];
            fn_80402CE0(*(void**)(p + 0x8), z, z);
            *(u8*)(*(char**)(*(char**)(p + 0x8) + 0x4) + 0xb0) = 1;
            *(u8*)(*(char**)(*(char**)(p + 0xc) + 0x4) + 0xb0) = 0;
            p[0x15] = 2;
        }
    }
    return 0;
}

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
extern const f32 lbl_80543D64;
#pragma opt_propagation off
extern "C" void fn_804434B8(void* this_) {
    ScreenTransitionTable* tbl = (ScreenTransitionTable*)lbl_8048FB88;
    ScreenTransitionState* p = (ScreenTransitionState*)this_;
    p->timer += 1;
    {
    s16* x = tbl->x;
    fn_80402B10(p->pane, 30, 0, lbl_80543D60, x[p->index]);
    s16* y;
    u32 index;
    index = p->index;
    y = tbl->y;
    fn_80402940(p->pane, 30, 0, lbl_80543D60, y[index]);
    f32 (*scales)[7];
    scales = &tbl->scale;
    f32 scale;
    f32 height;
    height = ((f32*)p->pane)[6];
    scale = (*scales)[p->index];
    fn_8040271C(p->pane, 30, lbl_80543D64, scale / height);
    }
    if (p->timer >= 30) p->state = 2;
}
#pragma opt_propagation reset
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

struct T80443638;
typedef void (T80443638::*PMF80443638)();
extern PMF80443638 lbl_804B1AC4[];
extern "C" void fn_80443638(T80443638* this_) {
    u32 state = *(u8*)((char*)this_ + 0x15);
    u32 notThree = (3 - state) | (state - 3);
    if (notThree >> 31) {
        (((T80443638*)lbl_8053AEF0)->*lbl_804B1AC4[state])();
    }
}

extern "C" void fn_8013B490(void* p);
extern "C" void draw__9J2DScreenFffPC14J2DGrafContext(void* screen, f32 x, f32 y, void* ctx);
extern "C" void* lbl_8053AB10;
extern "C" const f32 lbl_80543D60;
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
    void* screen;
    void* obj;
    u8* self = (u8*)this_;
    *(void**)self = (void*)lbl_804B1AE8;
    lbl_8053AEF0 = (s32)self;

    screen = __nw__FUl(0x118);
    if (screen != 0) {
        __ct__9J2DScreenFv(screen);
    }
    *(void**)(self + 4) = screen;
    setPriority__9J2DScreenFPCcUlP10JKRArchive(*(void**)(self + 4), (const char*)lbl_8048FBC4, 0x1100000, *(void**)(lbl_80529DEC + 0x10));

    obj = __nw__FUl(0x2c);
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

void __sinit_tu_804432DC_cpp(void) {}
#include "JSystem/JAudio/JASFakeMatchFSA.h"
