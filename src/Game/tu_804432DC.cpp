#include "types.h"

struct Slot0 {
    virtual void slot0(int);
};

extern "C" void __dl__FPv(void* this_);
extern void* lbl_804B1AE8[];
extern s32 lbl_8053AEF0;
extern "C" void fn_80443494(void* this_) {
    char* p = (char*)this_;
    s32 v = *(s16*)(p + 0x12);
    if (v > 0) {
        *(s16*)(p + 0x12) = v - 1;
        return;
    }
    *(u8*)(p + 0x15) = 3;
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
