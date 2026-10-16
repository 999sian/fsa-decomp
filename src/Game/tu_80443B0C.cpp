#include "types.h"
#include <JSystem/J2D/J2DScreen.h>


extern const f32 lbl_80543D78;
extern "C" void fn_8013B490(void*);
extern "C" void fn_80402628(void*, s32, s32, u8);
extern void* lbl_8053AB10;
extern const f32 lbl_80543D7C;
extern "C" u8 fn_80402940(void*, s32, s32, f32, f32);
extern "C" void fn_80443D5C(u8* p) {
    if (fn_80402940(*(void**)(p + 8), 10, 0, lbl_80543D78, lbl_80543D7C)) {
        p[0x4d] = 4;
    }
}

extern const f32 lbl_80543D80;
extern const f32 lbl_80543D84;
extern "C" void fn_80444590(u8* p) {
    if (fn_80402940(*(void**)(p + 8), 5, 0, lbl_80543D80, lbl_80543D78)) {
        p[0x4d] = 2;
    }
}

extern "C" void fn_80444650(void* this_) {
    char* p = (char*)this_;
    if (*(u8*)(p + 0x4d) != 4) {
        fn_8013B490(lbl_8053AB10);
        ((J2DScreen*)*(void**)(p + 0x4))->draw(lbl_80543D78, lbl_80543D78, (const J2DGrafContext*)((void**)lbl_8053AB10)[4]);
    }
}

struct T804446A4;
typedef void (T804446A4::*PMF804446A4)();
extern PMF804446A4 lbl_804B1B30[];
extern "C" bool fn_804446A4(T804446A4* this_) {
    u8 state = *(u8*)((char*)this_ + 0x4d);
    if (state != 4) {
        (this_->*lbl_804B1B30[state])();
        return false;
    }
    return true;
}

