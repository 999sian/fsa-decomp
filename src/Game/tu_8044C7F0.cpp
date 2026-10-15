#include "types.h"
struct J2DScreen {
    u8 pad[0x100];
    u8 b100;
};


extern "C" void fn_804316EC(void*);
extern void* lbl_8053AEC0;
extern void* lbl_8053AF40;

extern "C" u8 fn_8044CB00(u8* p) { return p[0x140]; }

extern "C" u8 fn_8044D290(u8* p) { return p[0x140]; }

extern "C" void* fn_8044F664(void) {
    if (lbl_8053AF40 != 0) {
        return *(void**)((char*)lbl_8053AF40 + 0x184);
    }
    return (void*)9;
}

extern "C" void fn_804522C8(u8* p) {
    s16 v = *(s16*)(p + 0xfa);
    if (v == 7 || v == 8 || v == 9) {
        fn_804316EC(lbl_8053AEC0);
    }
}

extern "C" void fn_8013B490(void*);
extern u8* lbl_8053AB10;
extern f32 lbl_80543DFC;
struct J2DGrafContext;
extern "C" void draw__9J2DScreenFffPC14J2DGrafContext(J2DScreen*, f32, f32, const J2DGrafContext*);
extern "C" void fn_80452308(void* self_) {
    u8* self = (u8*)self_;
    fn_8013B490(lbl_8053AB10);
    f32 f = lbl_80543DFC;
    draw__9J2DScreenFffPC14J2DGrafContext(*(J2DScreen**)(self + 4), f, f, *(const J2DGrafContext**)(lbl_8053AB10 + 0x10));
}

extern "C" u8 fn_80453848(u8* p) {
    u8 dead = 0;
    if ((*(u32*)(p + 0xf4) & 8) && *(s32*)(p + 0xd0) + *(s32*)(p + 0xdc) == 0) {
        dead = 1;
    }
    return dead;
}

extern "C" void fn_80453874(void* thisObj, f32 x, f32 y, f32 z) {
	*(f32*)((char*)thisObj + 0x0) = x;
	*(f32*)((char*)thisObj + 0x4) = y;
	*(f32*)((char*)thisObj + 0x8) = z;
}

