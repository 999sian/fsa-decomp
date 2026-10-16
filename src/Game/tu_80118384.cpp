#include "types.h"

extern "C" void* __nw__FUl(u32 size);
extern "C" void __ct__10J2DPictureFPC7ResTIMG(void* self, const void* res);
extern u8* lbl_8053AAF8;
extern u32 lbl_80539F10;

extern "C" void fn_80118384(u8* self)
{
    void fn_801F856C(void);
    void fn_801F6884(void);
    fn_801F856C();
    fn_801F6884();
    self[0] = 0;
}

extern "C" void fn_801183BC(u8* self)
{
    extern u8 lbl_8053AA91;
    extern u8 lbl_804BC504[];
    extern u8 lbl_804BC4F8[];
    extern f32 lbl_8053C798;
    extern void fn_80119E5C(void);
    self[1] = 0;
    if (lbl_8053AA91 == 0) {
        lbl_804BC504[0] = 0;
        lbl_804BC504[1] = 0;
        lbl_804BC504[2] = 0;
        lbl_8053AA91 = 1;
    }
    lbl_804BC504[1] = 0;
}

extern "C" void fn_8011888C(u8* self, u32 val)
{
    u32 local = val;
    void fn_801188B8(u8* self, u32* ptr);
    fn_801188B8(self + 0xc, &local);
}

extern "C" void fn_801188B8(u8* self, void* ptr)
{
    u32* fn_801188E0(u8* self, u32 p, void* q);
    fn_801188E0(self, *(u32*)(self + 8), ptr);
}

extern "C" u32* fn_801188E0(u8* self, u32 p, void* q)
{
    void fn_80118938(u8* self, u32 unused, u32 count, void* src);
    s32 idx = ((s32)p - *(s32*)(self + 4)) / 4;
    fn_80118938(self, p, 1, q);
    return *(u32**)(self + 4) + idx;
}

extern "C" void fn_80118938(u8* self, u32 unused, u32 count, void* src)
{
    u32* fn_801189B0(void);
    if (count != 0) {
        u32* dst = fn_801189B0();
        if (dst != *(u32**)(self + 8)) {
            u32 val = *(u32*)src;
            while (count != 0) {
                if (dst != 0) {
                    *dst = val;
                }
                dst++;
                count--;
            }
        }
    }
}

struct VObj {
    virtual void v00(int);
    virtual void v04(void);
    virtual void v08(int);
};

extern "C" void __dl__FPv(void* p);

extern "C" void fn_80119468(u32 a, u32 b, s32 c)
{
    void fn_80119998(u32 a, u32 b, u32 c, s32 d, u32 e, u32 f, u32 g, u32 h);
    u32 v;
    switch (c) {
    case 2:
        v = 0x46;
        break;
    case 0:
    case 1:
        v = 0x23;
        break;
    default:
        v = 0x46;
        break;
    }
    fn_80119998(a, v, 0, c, 0, 2, 0, b);
}

extern "C" void fn_80119958(u8* self)
{
    self[0] = 0;
    self[1] = 0;
    self[2] = 0;
    *(u32*)(self + 0x4) = 0;
    *(u32*)(self + 0x8) = 0;
    *(u32*)(self + 0xc) = 0;
    *(f32*)(self + 0x14) = 0.0f;
    *(f32*)(self + 0x18) = 0.0f;
    *(u32*)(self + 0x1c) = 0;
    *(u32*)(self + 0x20) = 0;
    *(u32*)(self + 0x24) = 0;
    *(u32*)(self + 0x28) = 0;
    *(u32*)(self + 0x10) = 0;
}

extern "C" void fn_80119D48(u8* self)
{
    if (*(u32*)(self + 0x2c) == 0) {
        void* obj = *(void**)((u8*)lbl_8053AAF8 + 0xa4);
        void* res = ((void* (*)(void*, u32, u32))(*(void***)obj)[6])(obj, 0x3f3f3f3f, lbl_80539F10);
        u8* pic = (u8*)__nw__FUl(0x168);
        if (pic != 0) {
            __ct__10J2DPictureFPC7ResTIMG(pic, res);
        }
        *(u8**)(self + 0x2c) = pic;
    }
}

extern "C" void* fn_80119DD0(void)
{
    return 0;
}

extern "C" void* fn_80119E5C(u8* self, s16 size)
{
    VObj* obj;
    if (self != 0) {
        obj = *(VObj**)(self + 0x2c);
        if (obj != 0 && obj != 0) {
            obj->v00(1);
        }
        *(VObj**)(self + 0x2c) = 0;
        if (size > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

