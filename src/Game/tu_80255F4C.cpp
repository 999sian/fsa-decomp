#include "Game/Actor.h"

struct ShapeArg {
    u8 idx[16];
    s32 unk10;
    s32 unk14;
    f32* mtx;
    u8 unk1c;
    u8 unk1d;
    u8 unk1e;
    u8 unk1f;
    u8 unk20;
    u8 unk21;
    u8 unk22;
    u8 unk23;
    u8 unk24;
    u8 unk25;
    u8 unk26;
    s32 unk28;
    u8 unk2c;
    u8 unk2d;
    u8 unk2e;
    s32 unk30;
    s32 unk34;
    s32 unk38;
};

extern "C" u8 sincosTable___5JMath[];
extern "C" f32 lbl_805400A0;
extern "C" f32 lbl_805400A4;
extern "C" u32 lbl_804A6F48[];
extern "C" char* lbl_8053AAF8;
extern "C" char* lbl_8053AB10;
extern "C" void* fn_802F745C(void* a, void* b, void* c, void* d);


extern "C" char lbl_804A6F6C[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_80255F4C(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804A6F6C;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" u8 sincosTable___5JMath[];
extern "C" f32 lbl_805400AC;
extern "C" f32 lbl_805400B4;
extern "C" void fn_80256410(Actor* param_1)
{
    u8* p = (u8*)param_1;
    s32 w;
    f32 k;

    if (*(u32*)(p + 0x234) != 0) {
        *(u32*)(p + 0x234) = *(u32*)(p + 0x234) - 1;
        return;
    }
    w = *(s32*)(p + 0x90);
    if ((w & 0x7f) == 6 || (w & 0x7f) == 7) {
        if (*(u32*)(p + 0x230) < (((u32)w >> 12) & 0x3e0)) {
            *(u32*)(p + 0x230) = *(u32*)(p + 0x230) + 1;
        } else {
            *(u32*)(p + 0x234) = 0x3c;
            *(u32*)(p + 0x230) = 0;
            switch (*(s32*)(p + 0x98)) {
            case 0:
                *(s32*)(p + 0x98) = 1;
                break;
            case 1:
                *(s32*)(p + 0x98) = 0;
                break;
            case 2:
                *(s32*)(p + 0x98) = 3;
                break;
            case 3:
                *(s32*)(p + 0x98) = 2;
                break;
            }
        }
    }
    if ((*(s32*)(p + 0x90) & 0x7f) < 6) {
        *(s16*)(p + 0x238) = *(s16*)(p + 0x238) + 0x40;
    }
    if ((*(s32*)(p + 0x90) & 0x7f) == 6) {
        if (*(s32*)(p + 0x98) == 0) {
            *(f32*)(p + 0xc) = *(f32*)(p + 0xc) + lbl_805400AC;
        } else {
            *(f32*)(p + 0xc) = *(f32*)(p + 0xc) - lbl_805400AC;
        }
    }
    if ((*(s32*)(p + 0x90) & 0x7f) == 7) {
        if (*(s32*)(p + 0x98) == 2) {
            *(f32*)(p + 0x10) = *(f32*)(p + 0x10) + lbl_805400AC;
        } else {
            *(f32*)(p + 0x10) = *(f32*)(p + 0x10) - lbl_805400AC;
        }
    }
    if ((*(s32*)(p + 0x90) & 0x7f) == 8) {
        k = lbl_805400B4;
        *(s16*)(p + 0x23a) = *(s16*)(p + 0x23a) + 0x40;
        *(f32*)(p + 0xc) = k * *(f32*)(sincosTable___5JMath + ((u32)*(s16*)(p + 0x23a) >> 2 & 0x3ff8) + 4) + *(f32*)(p + 0x24);
        *(f32*)(p + 0x10) = k * *(f32*)(sincosTable___5JMath + ((u32)*(s16*)(p + 0x23a) >> 2 & 0x3ff8)) + *(f32*)(p + 0x28);
    }
}

extern char* lbl_8053AAF8;
extern u32 lbl_804A6F48[];
extern f32 lbl_805400B4;
extern "C" void fn_80256888(Actor* param_1) {
    char* p = (char*)param_1;
    if (((*(u32*)(p + 0x90) >> 17) & 0x1f) == 0) {
        *(u32*)(p + 0x90) = *(u32*)(p + 0x90) | 0x20000;
    }
    char* mgr = *(char**)(lbl_8053AAF8 + 0xa4);
    *(void**)(p + 0x23c) = (*(void* (**)(void*, u32, u32))(*(u32*)mgr + 0x18))(mgr, 0x3f3f3f3f, lbl_804A6F48[*(u32*)(p + 0x90) & 0x7f]);
    u16 a = *(u16*)(*(char**)(p + 0x23c) + 0x2);
    u16 b = *(u16*)(*(char**)(p + 0x23c) + 0x4);
    *(f32*)(p + 0x60) = (f32)(-(s32)a / 2);
    *(f32*)(p + 0x64) = (f32)(-(s32)b / 2);
    *(f32*)(p + 0x68) = (f32)((u32)a >> 1);
    *(f32*)(p + 0x6c) = (f32)((u32)b >> 1);
    *(u32*)(p + 0x108) = 0;
    *(u32*)(p + 0x230) = 0;
    *(u16*)(p + 0x238) = 0;
    *(u16*)(p + 0x23a) = 0;
    if ((*(u32*)(p + 0x90) & 0x7f) == 8) {
        s32 off = ((u32)*(s16*)(p + 0x23a) >> 2) & 0x3ff8;
        *(f32*)(p + 0xc) = lbl_805400B4 * *(f32*)((char*)sincosTable___5JMath + off + 4) + *(f32*)(p + 0x24);
        *(f32*)(p + 0x10) = lbl_805400B4 * *(f32*)((char*)sincosTable___5JMath + off) + *(f32*)(p + 0x28);
    }
    if ((*(u32*)(p + 0x90) & 0x7f) == 6 || (*(u32*)(p + 0x90) & 0x7f) == 7) {
        *(s32*)(p + 0x234) = 0x3c;
    } else {
        *(s32*)(p + 0x234) = 0;
    }
    if ((*(u32*)(p + 0x90) & 0x7f) == 7) {
        *(s32*)(p + 0x98) = 3;
    } else {
        *(s32*)(p + 0x98) = 0;
    }
}

