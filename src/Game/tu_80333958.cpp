#include "JSystem/JGeometry/Vec.h"

class Actor;

extern const f32 lbl_80541F3C;
extern const f32 lbl_80541F40;
extern const f32 lbl_80541F44;
extern const f32 lbl_80541F48;
extern const f32 lbl_80541F4C;
extern char* lbl_8053AB10;
extern u8* lbl_8053AAF8;
extern char lbl_80471A90[];
extern char lbl_80471AA0[];

struct Tu80333958ResMgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void* get(u32 type, const char* name);
};


extern "C" char lbl_804AB968[];
extern "C" void fn_801F2B7C(void* this_, u32 a, u32 b, u32 c);
extern "C" void fn_801F0E34(void* this_, u32 a, u32 b);
extern "C" double __fabs(double x);
extern const f32 lbl_80541F50;
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_80333958(Actor* p, s16 n)
{
  if (p) {
    *(void**)p = lbl_804AB968;
    __dt__5ActorFv(p, 0);
    if (n > 0) operator delete(p);
  }
  return p;
}

extern const f32 lbl_80541F38;
extern "C" u16 fn_8022461C(Vec* pos, s32 room);
extern "C" BOOL fn_803339B8(void* this_, s32 room, JGeometry::TVec3f* pos) {
    JGeometry::TVec3f v(*pos);
    switch (*(s32*)((char*)this_ + 0x240)) {
    case 0:
        if (*(s32*)((char*)this_ + 0x23c) != 0) {
            v.y -= lbl_80541F38;
        } else {
            v.y -= lbl_80541F38;
        }
        break;
    case 1:
        if (*(s32*)((char*)this_ + 0x23c) != 0) {
            v.y += lbl_80541F38;
        } else {
            v.y += lbl_80541F38;
        }
        break;
    case 2:
        if (*(s32*)((char*)this_ + 0x23c) != 0) {
            v.x -= lbl_80541F38;
        } else {
            v.x -= lbl_80541F38;
        }
        break;
    case 3:
        if (*(s32*)((char*)this_ + 0x23c) != 0) {
            v.x += lbl_80541F38;
        } else {
            v.x += lbl_80541F38;
        }
        break;
    }
    s32 kind = (u16)fn_8022461C(&v, room);
    switch (*(s32*)((char*)this_ + 0x240)) {
    case 0:
        if (kind == 0x41) {
            return 1;
        }
        break;
    case 1:
        if (kind == 0x40) {
            return 1;
        }
        break;
    case 2:
        if (kind == 0x43) {
            return 1;
        }
        break;
    case 3:
        if (kind == 0x42) {
            return 1;
        }
        break;
    }
    return 0;
}

extern "C" void fn_80333E8C(void* this_) {
    char* p = (char*)this_;
    u32* vt;
    u8 r;
    fn_801F2B7C(this_, -0x64, -1, 1);
    vt = *(u32**)p;
    r = ((u8 (*)(void*))(vt[0x34 / 4]))(this_);
    if (r != 0) {
        return;
    }
    *(f32*)(p + 0xc) += *(f32*)(p + 0x3c);
    *(f32*)(p + 0x10) += *(f32*)(p + 0x40);
    *(f32*)(p + 0x14) += *(f32*)(p + 0x44);
    vt = *(u32**)p;
    r = ((u8 (*)(void*, u32))(vt[0x4c / 4]))(this_, *(u32*)(p + 4));
    if (r != 0 || *(s32*)(p + 0x244) > 0x258) {
        *(u8*)(p + 0x11c) = 0;
    }
    *(s32*)(p + 0x234) -= (s32)(lbl_80541F50 + ((f32)__fabs(*(f32*)(p + 0x40)) + (f32)__fabs(*(f32*)(p + 0x3c))));
    if (*(s32*)(p + 0x234) <= 15) {
        *(s32*)(p + 0x238) = 1;
        if (*(s32*)(p + 0x234) <= 0) {
            *(s32*)(p + 0x234) = 0x1e;
            *(s32*)(p + 0x238) = 0;
            fn_801F0E34(this_, 0x30010, 0);
        }
    }
    *(s32*)(p + 0x244) += 1;
}

extern const f32 lbl_80541F40;
extern const f32 lbl_80541F54;
extern const f32 lbl_80541F58;
extern const f32 lbl_80541F5C;
extern const f32 lbl_80541F60;
extern const f32 lbl_80541F64;
extern const f32 lbl_80541F68;
extern "C" void fn_801F0E34(void* this_, u32 a, u32 b);
extern "C" void fn_80333FC4(void* this_) {
    char* p = (char*)this_;
    s32 mode = (*(u32*)(p + 0x90) >> 4) & 0xf;
    *(s32*)(p + 0x240) = mode;
    *(s32*)(p + 0x108) = 0x80;
    if ((*(u32*)(p + 0x90) & 0xf) != 0) {
        *(s32*)(p + 0x23c) = 1;
        *(f32*)(p + 0x60) = lbl_80541F54;
        *(f32*)(p + 0x64) = lbl_80541F54;
        *(f32*)(p + 0x68) = lbl_80541F58;
        *(f32*)(p + 0x6c) = lbl_80541F58;
    } else {
        *(s32*)(p + 0x23c) = 0;
        *(f32*)(p + 0x60) = lbl_80541F5C;
        *(f32*)(p + 0x64) = lbl_80541F5C;
        *(f32*)(p + 0x68) = lbl_80541F60;
        *(f32*)(p + 0x6c) = lbl_80541F60;
    }
    switch (*(s32*)(p + 0x240)) {
    case 0:
        *(f32*)(p + 0x3c) = lbl_80541F40;
        *(f32*)(p + 0x40) = lbl_80541F64;
        *(f32*)(p + 0x44) = lbl_80541F40;
        break;
    case 1:
        *(f32*)(p + 0x3c) = lbl_80541F40;
        *(f32*)(p + 0x40) = lbl_80541F68;
        *(f32*)(p + 0x44) = lbl_80541F40;
        break;
    case 2:
        *(f32*)(p + 0x3c) = lbl_80541F64;
        *(f32*)(p + 0x40) = lbl_80541F40;
        *(f32*)(p + 0x44) = lbl_80541F40;
        break;
    case 3:
        *(f32*)(p + 0x3c) = lbl_80541F68;
        *(f32*)(p + 0x40) = lbl_80541F40;
        *(f32*)(p + 0x44) = lbl_80541F40;
        break;
    }
    *(s32*)(p + 0x230) = 0;
    *(s32*)(p + 0x238) = 0;
    *(s32*)(p + 0x234) = 0x1e;
    *(s32*)(p + 0x244) = 0;
    fn_801F0E34(this_, 0x30019, 0);
}

