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
extern "C" void fn_802BE8F8(char* p) {
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
    GXColor color;
    float pos[3];
    pos[1] = lbl_80540C1C + *(float*)(p + 0x10);
    pos[0] = lbl_80540C1C + *(float*)(p + 0xc);
    pos[2] = lbl_80540C10;
    color.r = 0;
    color.g = 0;
    color.b = 0;
    color.a = 0x80;
    fn_80158B5C(*(void**)(lbl_8053AB10 + 0x2c), *(int*)(p + 4), pos, color, *(float*)(p + 0x254));
}

extern "C" float lbl_80540C20;
extern "C" void* fn_8013CC50(u32 owner, void* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale);
extern "C" float lbl_80540C20;
extern "C" s32 fn_8023AB94(const f32* box, u32 owner, f32* pos);
extern "C" s32 fn_801F2718(void* this_, u32 code);
extern "C" u32 fn_80226998(void* p, s32 layer);
extern "C" void fn_801F0E34(void* this_, s32 id, s32 flag);
extern "C" void fn_802BE9E0(char* p) {
    float box[4];
    float pos[2];
    if (*(s32*)(p + 0x248) == 0) {
        char* o = *(char**)(p + 0x23c);
        if (o != 0) {
            *(u32*)(o + 0xf4) |= 1;
            *(s32*)(o + 0x24) = 1;
            *(void**)(p + 0x23c) = 0;
        }
    } else {
        *(s32*)(p + 0x248) -= 1;
    }
    box[0] = *(float*)(p + 0x60);
    box[1] = *(float*)(p + 0x64);
    box[2] = *(float*)(p + 0x68);
    box[3] = *(float*)(p + 0x6c);
    pos[1] = lbl_80540C1C + *(float*)(p + 0x10);
    pos[0] = lbl_80540C1C + *(float*)(p + 0xc);
    box[0] += pos[0];
    box[1] += pos[1];
    box[2] += pos[0];
    box[3] += pos[1];

    switch (*(s32*)(p + 0x230)) {
    case 0:
        if ((*(u16*)(p + 0x94) != 0 || fn_8023AB94(box, *(u32*)(p + 4), pos) >= 0 ||
             fn_801F2718(p, 0x46495245) >= 0) &&
            ((u16)fn_80226998(p + 0xc, *(u32*)(p + 4)) == 0x3d ||
             (u16)fn_80226998(p + 0xc, *(u32*)(p + 4)) == 0x1de)) {
            *(void**)(p + 0x234) = fn_8013CC50(*(u32*)(p + 4), p + 0xc, 0xbd, 0, lbl_80540C20, 0, 0, 0, 1);
            *(void**)(p + 0x238) = fn_8013CC50(*(u32*)(p + 4), p + 0xc, 0x54a, 0, lbl_80540C20, 0, 0, 0, 1);
            (*(void (**)(char*, s32, s32))(*(u32*)p + 0x30))(p, 0xff, 1);
            fn_801F0E34(p, 0x30005, 0);
            *(s32*)(p + 0xb0) = 0xc;
            char* o = *(char**)(p + 0x23c);
            if (o != 0) {
                *(u32*)(o + 0xf4) |= 1;
                *(s32*)(o + 0x24) = 1;
                *(void**)(p + 0x23c) = 0;
            }
            *(s32*)(p + 0x230) = 1;
            *(s32*)(p + 0x24c) = *(s32*)(p + 0x244);
            *(s32*)(p + 0x250) = 1;
            *(u16*)(p + 0x94) = 0;
        }
        break;
    case 1:
        if (*(s32*)(p + 0x24c) != 0) {
            *(s32*)(p + 0x24c) -= 1;
        }
        u8 r = (*(u8 (**)(char*))(*(u32*)p + 0x34))(p);
        if (r == 0 || (*(s32*)(p + 0x240) == 1 && *(s32*)(p + 0x24c) == 0)) {
            *(void**)(p + 0x23c) = fn_8013CC50(*(u32*)(p + 4), p + 0xc, 0x57, 1, lbl_80540C20, 0, 0, 0, 1);
            *(s32*)(p + 0x248) = 0x28;
            char* o = *(char**)(p + 0x234);
            if (o != 0) {
                *(u32*)(o + 0xf4) |= 1;
                *(s32*)(o + 0x24) = 1;
                *(void**)(p + 0x234) = 0;
            }
            o = *(char**)(p + 0x238);
            if (o != 0) {
                *(u32*)(o + 0xf4) |= 1;
                *(s32*)(o + 0x24) = 1;
                *(void**)(p + 0x238) = 0;
            }
            (*(void (**)(char*, s32, s32))(*(u32*)p + 0x30))(p, 0xff, 0);
            *(s32*)(p + 0xb0) = 0xd;
            *(s32*)(p + 0x230) = 0;
            *(s32*)(p + 0x250) = 0;
        }
        break;
    }
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
    float f4 = lbl_80540C1C;
    float f2 = lbl_80540C24;
    float f1 = lbl_80540C28;
    float f0 = lbl_80540C10;
    *(unsigned long*)(p + 0x240) = (*(unsigned long*)(p + 0x90) >> 22) & 0x1f;
    *(unsigned long*)(p + 0x244) = *(unsigned long*)(p + 0x90) & 0xfff;
    *(unsigned long*)(p + 0xb0) = 0xd;
    *(unsigned short*)(p + 0x94) = 0;
    *(unsigned long*)(p + 0x230) = 0;
    *(float*)(p + 0xc) = *(float*)(p + 0xc) + f4;
    *(float*)(p + 0x10) = *(float*)(p + 0x10) + f4;
    *(float*)(p + 0x60) = f2;
    *(float*)(p + 0x64) = f2;
    *(float*)(p + 0x68) = f1;
    *(float*)(p + 0x6c) = f1;
    *(unsigned long*)(p + 0x234) = 0;
    *(unsigned long*)(p + 0x238) = 0;
    *(unsigned long*)(p + 0x23c) = 0;
    *(unsigned long*)(p + 0x248) = 0;
    *(unsigned long*)(p + 0x24c) = 0;
    *(unsigned long*)(p + 0x250) = 0;
    *(float*)(p + 0x254) = f0;
}



