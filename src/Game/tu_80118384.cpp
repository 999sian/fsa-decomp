#include "types.h"

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

