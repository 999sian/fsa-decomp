#include "types.h"
#include "JSystem/JGeometry/Box.h"

extern void* lbl_8053AB10;

extern "C" void fn_8017EADC(f32* dst, const f32* src) { dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2]; }

extern "C" void fn_8017EB0C(void* thisObj, f32 x, f32 y, f32 z) {
	*(f32*)((char*)thisObj + 0x0) = x;
	*(f32*)((char*)thisObj + 0x4) = y;
	*(f32*)((char*)thisObj + 0x8) = z;
}

extern "C" void fn_8017EC38(u32* dst, const u32* src) {
    dst[0] = src[0];
    dst[1] = src[1];
    dst[2] = src[2];
    dst[3] = src[3];
}

extern "C" void fn_8017EC5C(JGeometry::TBox2<f32>* box, f32 x0, f32 y0, f32 x1, f32 y1)
{
    box->i.x = x0;
    box->i.y = y0;
    box->f.x = x1;
    box->f.y = y1;
}

extern "C" u8 fn_8017ECC0(void) {
    u8 result = 0;
    void* base;
    void* p;
    base = *(void**)lbl_8053AB10;
    p = *(void**)((char*)base + 0x24);
    if (*(u8*)((char*)p + 0x179) == 0) {
        *(u8*)((char*)p + 0x178) = 1;
        result = 1;
    }
    return result;
}

extern "C" void fn_8017ECE8(void* thisPtr, f32 a, f32 b) { 
    *(f32*)((char*)thisPtr + 0x0) = a; 
    *(f32*)((char*)thisPtr + 0x4) = b; 
}

extern "C" void fn_8017ECF4(void* thisPtr, u8 a, u8 b, u8 c, u8 d) {
    *(u8*)((char*)thisPtr + 0x0) = a;
    *(u8*)((char*)thisPtr + 0x1) = b;
    *(u8*)((char*)thisPtr + 0x2) = c;
    *(u8*)((char*)thisPtr + 0x3) = d;
}

extern void* fn_8053AB10_ptr;
extern void* lbl_8053AB10;
extern "C" void fn_8017ED08(void) {
    void* p = *(void**)((char*)lbl_8053AB10 + 0x20);
    *(u8*)((char*)p + 0x216) = 1;
}

