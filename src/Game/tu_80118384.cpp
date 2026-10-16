#include "types.h"

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

