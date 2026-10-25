#include "Game/Actor.h"
#include "dolphin/gx/GXStruct.h"

extern "C" char lbl_804A84C8[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" void fn_801EE434(void*);
extern "C" const f32 lbl_805409A0;
extern "C" const f32 lbl_805409A4;
extern "C" const f32 lbl_80540990;
extern const f32 lbl_80540994;
extern const f32 lbl_80540998;
extern const f32 lbl_8054099C;
extern void* lbl_8053AB10;
extern "C" void fn_80158B5C(void* mgr, void* room, void* pos, void* col, f32 size);
extern "C" void fn_802B055C(char* p) {
    if (*(s32*)(p + 0x254) == 0) {
        if (*(f32*)(p + 0x258) > lbl_80540990) {
            *(f32*)(p + 0x258) -= lbl_80540994;
            if (*(f32*)(p + 0x258) <= lbl_80540990)
                *(f32*)(p + 0x258) = lbl_80540990;
        } else {
            *(f32*)(p + 0x258) = lbl_80540990;
        }
    } else {
        if (*(f32*)(p + 0x258) < lbl_80540998)
            *(f32*)(p + 0x258) += lbl_80540994;
        else
            *(f32*)(p + 0x258) = lbl_80540998;
    }
    GXColor color;
    f32 pos[3];
    pos[1] = lbl_8054099C + *(f32*)(p + 0x10);
    pos[0] = lbl_8054099C + *(f32*)(p + 0xc);
    pos[2] = lbl_80540990;
    color.r = 0;
    color.g = 0;
    color.b = 0;
    color.a = 0x80;
    ((void (*)(void*, void*, void*, GXColor, f32))fn_80158B5C)(*(void**)((char*)lbl_8053AB10 + 0x2c), *(void**)(p + 4), pos, color, *(f32*)(p + 0x258));
}

extern "C" void* fn_802B0998(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A84C8;
        if (*(void**)(p + 0x234) != 0) {
            fn_801EE434(*(void**)(p + 0x234));
        }
        if (*(void**)(p + 0x238) != 0) {
            fn_801EE434(*(void**)(p + 0x238));
        }
        if (*(void**)(p + 0x23c) != 0) {
            fn_801EE434(*(void**)(p + 0x23c));
        }
        if (*(void**)(p + 0x240) != 0) {
            fn_801EE434(*(void**)(p + 0x240));
        }
        if (*(void**)(p + 0x244) != 0) {
            fn_801EE434(*(void**)(p + 0x244));
        }
        __dt__5ActorFv((Actor*)this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_802B0A4C(char* p) {
    *(u32*)(p + 0x248) = (*(u32*)(p + 0x90) >> 22) & 0x1f;
    *(u32*)(p + 0x24c) = (*(u32*)(p + 0x90) >> 17) & 0x1f;
    *(u32*)(p + 0x250) = (*(u32*)(p + 0x90) >> 12) & 0x1f;
    *(f32*)(p + 0x60) = lbl_805409A0;
    *(f32*)(p + 0x64) = lbl_805409A0;
    *(f32*)(p + 0x68) = lbl_805409A4;
    *(f32*)(p + 0x6c) = lbl_805409A4;
    *(u32*)(p + 0x234) = 0;
    *(u32*)(p + 0x238) = 0;
    *(u32*)(p + 0x23c) = 0;
    *(u32*)(p + 0x240) = 0;
    *(u32*)(p + 0x244) = 0;
    *(u32*)(p + 0x230) = 0;
    *(u32*)(p + 0x254) = 0;
    *(f32*)(p + 0x258) = lbl_80540990;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
