#include "dolphin/gx/GXStruct.h"
extern "C" char lbl_804A8B78[];
extern "C" void fn_801EE434(void*);
extern "C" void __dt__5ActorFv(void*, int);
extern "C" float lbl_80540C10;
extern "C" float lbl_80540C1C;
extern "C" float lbl_80540C24;
extern "C" float lbl_80540C28;

extern "C" float lbl_80540C14;
extern "C" float lbl_80540C18;
extern "C" char* lbl_8053AB10;
extern "C" void fn_80158B5C(void*, int, float*, GXColor, float = 0.0f);
extern "C" void fn_802BE8F8(void* this_) {
    char* p = (char*)this_;
    if (*(int*)(p + 0x250) == 0) {
        if (*(float*)(p + 0x254) > lbl_80540C10) {
            *(float*)(p + 0x254) -= lbl_80540C14;
            if (*(float*)(p + 0x254) <= lbl_80540C10) {
                *(float*)(p + 0x254) = lbl_80540C10;
            }
        } else {
            *(float*)(p + 0x254) = lbl_80540C10;
        }
    } else {
        if (*(float*)(p + 0x254) < lbl_80540C18) {
            *(float*)(p + 0x254) += lbl_80540C14;
        } else {
            *(float*)(p + 0x254) = lbl_80540C18;
        }
    }
    float pos[3];
    pos[0] = lbl_80540C1C + *(float*)(p + 0xc);
    pos[1] = lbl_80540C1C + *(float*)(p + 0x10);
    pos[2] = lbl_80540C10;
    GXColor color = {0, 0, 0, 0x80};
    fn_80158B5C(*(void**)(lbl_8053AB10 + 0x2c), *(int*)(p + 4), pos, color);
}

extern "C" void* fn_802BED00(void* this_, short freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A8B78;
        if (*(void**)(p + 0x234) != 0) {
            fn_801EE434(*(void**)(p + 0x234));
        }
        if (*(void**)(p + 0x238) != 0) {
            fn_801EE434(*(void**)(p + 0x238));
        }
        if (*(void**)(p + 0x23c) != 0) {
            fn_801EE434(*(void**)(p + 0x23c));
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_802BED94(char* p) {
    *(unsigned long*)(p + 0x240) = (*(unsigned long*)(p + 0x90) >> 22) & 0x1f;
    *(unsigned long*)(p + 0x244) = *(unsigned long*)(p + 0x90) & 0xfff;
    *(unsigned long*)(p + 0xb0) = 0xd;
    *(unsigned short*)(p + 0x94) = 0;
    *(unsigned long*)(p + 0x230) = 0;
    *(float*)(p + 0xc) = *(float*)(p + 0xc) + lbl_80540C1C;
    *(float*)(p + 0x10) = *(float*)(p + 0x10) + lbl_80540C1C;
    *(float*)(p + 0x60) = lbl_80540C24;
    *(float*)(p + 0x64) = lbl_80540C24;
    *(float*)(p + 0x68) = lbl_80540C28;
    *(float*)(p + 0x6c) = lbl_80540C28;
    *(unsigned long*)(p + 0x234) = 0;
    *(unsigned long*)(p + 0x238) = 0;
    *(unsigned long*)(p + 0x23c) = 0;
    *(unsigned long*)(p + 0x248) = 0;
    *(unsigned long*)(p + 0x24c) = 0;
    *(unsigned long*)(p + 0x250) = 0;
    *(float*)(p + 0x254) = lbl_80540C10;
}

