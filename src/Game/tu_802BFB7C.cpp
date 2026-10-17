#include "types.h"


extern "C" char lbl_804A8C80[];
extern "C" void __dt__5ActorFv(void*, int);
void operator delete(void*);
extern "C" f32 lbl_80540C40;
extern "C" f32 lbl_80540C38;
extern "C" f32 lbl_80540C44;
extern "C" char lbl_8046D54C[];
extern "C" u8* lbl_8053AB10;
extern "C" void fn_801F06F0(void* a, const char* name, s32 id, void* rec, s32 p5, f32 f6, f32 f7);
extern "C" void fn_803075AC(void*, s32, void*, s32, s32, s32, s32, s32, s32, s32);
extern "C" void fn_80158B5C(void*, s32, void*, void*, f32);

struct Rec {
    u32 w00;
    u32 w04;
    u32 w08;
    u32 w0c;
    u32 w10;
    u32 w14;
    u32 w18;
    u8 b1c;
    u8 b1d;
    u8 b1e;
    u8 b1f;
    u8 b20;
    u8 b21;
    u8 b22;
    u8 b23;
    u8 b24;
    u8 b25;
    u8 b26;
    u32 w28;
    u8 b2c;
    u8 b2d;
    u8 b2e;
    u32 w30;
    u32 w34;
    u32 w38;
};

struct Col4 {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
};
extern "C" void* fn_802BFB7C(void* p, s16 flags) {
    if (p != 0) {
        *(char**)p = lbl_804A8C80;
        __dt__5ActorFv(p, 0);
        if (flags > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" void fn_802C0EE0(char* p) {
    f32 z = lbl_80540C40;
    *(f32*)(p + 0x44) = z;
    *(f32*)(p + 0x40) = z;
    *(f32*)(p + 0x3c) = z;
    *(s32*)(p + 0x248) = 0;
    if (*(s32*)(p + 0x254) < 0xb4) {
        *(s32*)(p + 0x254) = 0xb4;
    }
    *(s32*)(p + 0x24c) = 0xff;
    *(s32*)(p + 0x250) = 1;
}

