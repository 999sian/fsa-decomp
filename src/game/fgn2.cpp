// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 80187144-8018A8D8 (FGN2). Remaining functions are not yet decompiled.
#include "types.h"

// from src/Game/stub_8018a6a0.cpp
extern void* lbl_8053AF80[2];

// fn_8018A6A0(this, a, b) - trivial 2-float pair setter.
extern "C" void fn_8018A6A0(void* thisObj, f32 a, f32 b) {
	char* p = (char*)thisObj;
	*(f32*)(p + 0x0) = a;
	*(f32*)(p + 0x4) = b;
}

// fn_8018A6AC() - returns the global sound-bank pointer.
extern "C" void* fn_8018A6AC(void) {
	return lbl_8053AF80[0];
}

// Small (inline-style) accessors.
extern char* lbl_8053AAF8;
extern "C" void* fn_8013C824(void* a);
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F6884(void* mgr);
extern "C" void* fn_801F68E0(void* mgr);

extern "C" void fn_8018A588(char* p, s32 v) { *(s32*)(p + 0x108) = v; }
extern "C" u16 fn_8018A590(char* p) { return *(u16*)(p + 0x94); }
extern "C" void fn_8018A598(char* p, u8 v) { *(u8*)(p + 0x11c) = v; }
extern "C" void fn_8018A5A0(char* p, s32 v) { *(s32*)(p + 0x98) = v; }
extern "C" void fn_8018A5A8(char* p, u16 v) { *(u16*)(p + 0x94) = v; }
extern "C" u8 fn_8018A5B0(char* p) { return *(u8*)(p + 0x11c); }
extern "C" void fn_8018A5B8(f32* v, f32 x, f32 y, f32 z) { v[0] = x; v[1] = y; v[2] = z; }
extern "C" void fn_8018A5C8(char* p, u8 v) { *(u8*)(p + 0xbb) = v; }
extern "C" void fn_8018A5D0(char* p) { *(u32*)(p + 0xf4) &= ~4; }
extern "C" void fn_8018A5E0(char* p) { *(u32*)(p + 0xf4) |= 4; }
extern "C" void* fn_8018A5F0(void* a) { return *(void**)((char*)fn_8013C824(a) + 0xc); }
extern "C" BOOL fn_8018A614(s32 bit) { return (*(u8*)(lbl_8053AAF8 + 0x82) & (u8)(1 << bit)) != 0; }
extern "C" void* fn_8018A63C(void) { return fn_801F6884(fn_801F856C()); }
extern "C" void* fn_8018A660(void) { return fn_801F68E0(fn_801F856C()); }
extern "C" void fn_8018A684(f32* dst, const f32* src) { dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2]; }

#include "JSystem/JAudio/JASFakeMatchFSA.h"
