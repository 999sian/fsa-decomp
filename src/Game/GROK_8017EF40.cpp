#include "types.h"
#include "JSystem/JGeometry/Vec.h"

extern "C" u8* fn_802D6A9C(void);
extern "C" void fn_801F0E34(void* this_, s32 p1, s32 p2);

extern "C" void fn_80182640(void* thisObj, f32 x, f32 y, f32 z) {
	*(f32*)((char*)thisObj + 0x0) = x;
	*(f32*)((char*)thisObj + 0x4) = y;
	*(f32*)((char*)thisObj + 0x8) = z;
}

extern "C" void fn_80182650(void* thisObj, f32 x, f32 y, f32 z) {
	*(f32*)((char*)thisObj + 0x0) = x;
	*(f32*)((char*)thisObj + 0x4) = y;
	*(f32*)((char*)thisObj + 0x8) = z;
}

extern "C" void fn_80182660(u8* dst, const f32* src) { JGeometry::setTVec3f(src, (f32*)(dst + 0xc)); }

extern "C" void fn_80182674(f32* dst, const f32* src) { dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2]; }

extern "C" void fn_80182690(f32* dst, const f32* src) { dst[0] = src[0]; dst[1] = src[1]; }

extern "C" u8* fn_801826A4(s32 idx) {
    u8* mgr = fn_802D6A9C();
    if (idx < 8) {
        return mgr + 0xcc;
    }
    return mgr + 0xdc;
}

extern "C" void fn_801826E4(f32* dst, f32 a, f32 b) { dst[0] = a; dst[1] = b; }

