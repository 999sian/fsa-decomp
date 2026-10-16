#include "types.h"

extern "C" void fn_80118384(u8* self)
{
    void fn_801F856C(void);
    void fn_801F6884(void);
    fn_801F856C();
    fn_801F6884();
    self[0] = 0;
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

extern "C" void fn_80119468(u32 a, u32 b, s32 c)
{
    void fn_80119998(u32 a, u32 b, u32 c, s32 d, u32 e, u32 f, u32 g, u32 h);
    u32 v = (c == 2 || c > 1 || c < 0) ? 0x46 : 0x23;
    fn_80119998(a, v, 0, c, 0, 2, 0, b);
}

extern "C" void fn_80119958(u8* self)
{
    *(u32*)(self + 0x0) = 0;
    *(u32*)(self + 0x4) = 0;
    *(u32*)(self + 0x8) = 0;
    *(u32*)(self + 0xc) = 0;
    *(u32*)(self + 0x10) = 0;
    *(u32*)(self + 0x1c) = 0;
    *(u32*)(self + 0x20) = 0;
    *(u32*)(self + 0x24) = 0;
    *(u32*)(self + 0x28) = 0;
}

extern "C" void fn_80119D48(u8* self)
{
    void* fn_80119D48_dummy;
}

extern "C" void* fn_80119DD0(void)
{
    return 0;
}

