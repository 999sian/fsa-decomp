#include "Game/Actor.h"

extern "C" const float lbl_80542210;
extern "C" const float lbl_8054221C;
extern "C" const float lbl_80542224;
extern "C" const float lbl_8054222C;
extern "C" const float lbl_80542238;


extern "C" char lbl_804AC330[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_8033E638(Actor* p, s16 n) {
    if (p != 0) {
        *(void**)p = lbl_804AC330;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" const float lbl_80542210;
extern "C" const float lbl_8054221C;
extern "C" const float lbl_80542240;
extern "C" const float lbl_80542244;
extern "C" const float lbl_80542248;
extern "C" const float lbl_8054224C;
extern "C" const float lbl_80542250;
extern "C" const float lbl_80542254;
extern "C" const float lbl_80542224;
extern "C" const float lbl_80542228;
extern "C" const float lbl_8054222C;
extern "C" const float lbl_80542230;
extern "C" const float lbl_80542234;
extern "C" const float lbl_80542238;
extern "C" void PSVECAdd(const Vec* a, const Vec* b, Vec* c);
extern "C" void fn_8023DEDC(void);
extern "C" void fn_8022CB94(void);
extern "C" void fn_8022DF48(void);
extern "C" void fn_8023E724(void);
extern "C" void fn_8022E088(void);
extern "C" void fn_8023DE58(void);
extern "C" void fn_8033F0E8(u8* this_) {
    *(u8*)(this_ + 0x25e) = 0;
    *(u8*)(this_ + 0x25f) = 0;
    *(u8*)(this_ + 0x260) = 0;
    *(u8*)(this_ + 0x261) = 0;
    *(u32*)(this_ + 0x244) = *(u32*)(this_ + 0x90) & 0xf;
    *(u32*)(this_ + 0x248) = (*(u32*)(this_ + 0x90) >> 4) & 0xf;
    *(u32*)(this_ + 0x250) = (*(u32*)(this_ + 0x90) >> 8) & 0xf;
    *(u32*)(this_ + 0x254) = *(u32*)(this_ + 0x250);
    *(u32*)(this_ + 0x258) = (*(u32*)(this_ + 0x90) >> 12) & 0xff;
    *(u32*)(this_ + 0x24c) = 0;
    *(u16*)(this_ + 0x25c) = 0;
    *(u8*)(this_ + 0x262) = 0;
    *(f32*)(this_ + 0x23c) = lbl_80542210;
    *(f32*)(this_ + 0x238) = lbl_80542210;
    *(f32*)(this_ + 0x234) = lbl_80542210;
    *(f32*)(this_ + 0x240) = lbl_8054221C;
    *(s32*)(this_ + 0x230) = 0;

    if (((s32 (*)(u8*))(*(void***)this_)[15])(this_) > 0) {
        *(s32*)(this_ + 0x230) = 2;
        *(f32*)(this_ + 0x240) = lbl_80542210;
    }

    switch (*(s32*)(this_ + 0x244)) {
    case 0:
        *(f32*)(this_ + 0x60) = lbl_80542240;
        *(f32*)(this_ + 0x64) = lbl_80542240;
        *(f32*)(this_ + 0x68) = lbl_80542244;
        *(f32*)(this_ + 0x6c) = lbl_80542244;
        break;
    case 1:
        *(f32*)(this_ + 0x60) = lbl_80542248;
        *(f32*)(this_ + 0x64) = lbl_80542248;
        *(f32*)(this_ + 0x68) = lbl_8054224C;
        *(f32*)(this_ + 0x6c) = lbl_8054224C;
        break;
    case 2:
        *(f32*)(this_ + 0x60) = lbl_80542250;
        *(f32*)(this_ + 0x64) = lbl_80542250;
        *(f32*)(this_ + 0x68) = lbl_80542254;
        *(f32*)(this_ + 0x6c) = lbl_80542254;
        break;
    }
}

