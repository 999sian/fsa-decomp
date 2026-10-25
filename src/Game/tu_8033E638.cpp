#include "Game/Actor.h"

extern "C" const float lbl_80542210;
extern "C" const float lbl_8054221C;
extern "C" const float lbl_80542224;
extern "C" const float lbl_8054222C;
extern "C" const float lbl_80542238;


extern "C" const float lbl_80542228;
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

extern "C" void fn_8033EA54(Actor* this_) {
    u8* p = (u8*)this_;
    if (*(s32*)(p + 0x230) == 1) {
        *(f32*)(p + 0xc) = *(f32*)(p + 0xc) + *(f32*)(p + 0x3c);
        *(f32*)(p + 0x10) = *(f32*)(p + 0x10) + *(f32*)(p + 0x40);
        *(f32*)(p + 0x14) = *(f32*)(p + 0x14) + *(f32*)(p + 0x44);
        if (((s32 (*)(Actor*))(*(void***)this_)[15])(this_) > 0) {
            if (!((s32 (*)(Actor*))(*(void***)this_)[13])(this_)) {
                *(s32*)(p + 0x230) = 2;
            }
        }
    }
    switch (*(s32*)(p + 0x230)) {
    case 0:
        if (*(s32*)(p + 0x248) == 0) {
            break;
        }
        if (*(s32*)(p + 0x24c) > 0) {
            break;
        }
        switch (*(s32*)(p + 0x254)) {
        case 0:
            *(f32*)(p + 0x3c) = lbl_80542224 * (f32)*(s32*)(p + 0x248);
            *(f32*)(p + 0x40) = lbl_80542210;
            *(f32*)(p + 0x44) = lbl_80542210;
            break;
        case 1:
            *(f32*)(p + 0x3c) = lbl_80542224 * -(f32)*(s32*)(p + 0x248);
            *(f32*)(p + 0x40) = lbl_80542210;
            *(f32*)(p + 0x44) = lbl_80542210;
            break;
        case 2:
            *(f32*)(p + 0x3c) = lbl_80542210;
            *(f32*)(p + 0x40) = lbl_80542224 * ((f32)*(s32*)(p + 0x248) - lbl_80542238);
            *(f32*)(p + 0x44) = lbl_80542210;
            break;
        case 3:
            *(f32*)(p + 0x3c) = lbl_80542210;
            *(f32*)(p + 0x40) = lbl_80542224 * -((f32)*(s32*)(p + 0x248) - lbl_80542238);
            *(f32*)(p + 0x44) = lbl_80542210;
            break;
        }
        *(s32*)(p + 0x24c) = 1;
        *(s32*)(p + 0x230) = 1;
        break;
    case 1:
        if (*(f32*)(p + 0x240) < lbl_8054221C) {
            *(f32*)(p + 0x240) = *(f32*)(p + 0x240) + lbl_8054222C;
            if (*(f32*)(p + 0x240) < lbl_8054221C) {
                *(f32*)(p + 0x240) = lbl_8054221C;
                *(s32*)(p + 0x230) = 0;
            }
        }
        break;
    case 2:
        if (*(f32*)(p + 0x240) > lbl_80542210) {
            *(f32*)(p + 0x240) = *(f32*)(p + 0x240) - lbl_8054222C;
            if (*(f32*)(p + 0x240) > lbl_80542210) {
                *(f32*)(p + 0x240) = lbl_80542210;
            }
        }
        break;
    }
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
struct FsaVirtBase {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual s32 v15();
};

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

    if (((FsaVirtBase*)this_)->v15() > 0) {
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

