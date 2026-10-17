#include "Game/Actor.h"
#include "Game/ItemBase.h"


extern "C" char lbl_804AB4C0[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" void fn_801EE434(void*);
extern "C" void* lbl_8053AAF8;
extern "C" s32 fn_8013CC50(u32 id, void* p, f32 f, u32 a, u32 b, u32 c, u32 d, u32 e, u32 g);
extern "C" void* lbl_80471888;
extern "C" void fn_801F06F0(void* this_, void* name, s32 id, void* ids, s32 flag, f32 f, f32 g);
extern "C" void fn_803075AC(void* a, void* b, void* c, s32 id, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i);
extern "C" void fn_80326A90(void* this_) {
	DrawRec rec;
	f32 m[12];
	m[3] = 0.0f;
	m[7] = 0.0f;
	m[11] = 0.0f;
	m[0] = 1.5f;
	m[1] = 0.0f;
	m[2] = 0.0f;
	m[4] = 0.0f;
	m[5] = 1.5f;
	m[6] = 0.0f;
	m[8] = 0.0f;
	m[9] = 0.0f;
	m[10] = 1.5f;
	rec.w18 = m;
	if (*(s32*)((u8*)this_ + 0x234) >= 0x100 || (*(s32*)((u8*)this_ + 0x234) & 2) == 0) {
		rec.b2d = 1;
		fn_801F06F0(this_, &lbl_80471888, *(s32*)((u8*)this_ + 0x250) + 0x5e, rec.ids, 0, 1.0f, 1.0f);
		fn_803075AC(*(void**)((u8*)this_ + 0x198), *(void**)((u8*)this_ + 4), (u8*)this_ + 0xc, *(s32*)((u8*)this_ + 0x250) + 0x5e, 0, 2, -1, 0, 0, 0);
	}
}

extern "C" void fn_8032722C(void* thisPtr) {
	char* p = (char*)thisPtr;
	*(f32*)(p + 0x60) = -4.0f;
	*(f32*)(p + 0x64) = -4.0f;
	*(f32*)(p + 0x68) = 4.0f;
	*(f32*)(p + 0x6c) = 4.0f;
	*(s32*)(p + 0x244) = 0;
	*(s32*)(p + 0x248) = 0;
	*(s32*)(p + 0x24c) = 0;
	*(s32*)(p + 0x234) = 0;
	*(s32*)(p + 0x238) = 0;
	*(s32*)(p + 0x23c) = 0;
	*(s32*)(p + 0x240) = 0;
	*(s32*)(p + 0x108) = 8;
	*(s32*)(p + 0x250) = 0;
	*(f32*)(p + 0x258) = 0.0f;
	*(f32*)(p + 0x25c) = 0.0f;
	*(f32*)(p + 0x260) = 0.0f;
	*(f32*)(p + 0x3c) = 0.0f;
	*(f32*)(p + 0x40) = 0.0f;
	*(f32*)(p + 0x44) = 0.0f;
	*(s32*)(p + 0x234) = 0x400;
	*(f32*)(p + 0x260) = 10.0f;
	*(s32*)(p + 0x23c) = 10;
	{
		char* g = (char*)lbl_8053AAF8;
		u32 s = *(u32*)(g + 0xb4) * 0x19660d + 0x3c6ef35f;
		*(u32*)(g + 0xb4) = s;
		u32 b = (*(u32*)(g + 0xb4) >> 9) | 0x3f800000;
		*(s32*)(p + 0x240) = (s32)(30.0f * (*(f32*)&b - 1.0f)) + 0x1e;
	}
	{
		char* g = (char*)lbl_8053AAF8;
		u32 s = *(u32*)(g + 0xb4) * 0x19660d + 0x3c6ef35f;
		*(u32*)(g + 0xb4) = s;
		u32 b = (*(u32*)(g + 0xb4) >> 9) | 0x3f800000;
		*(s32*)(p + 0x248) = (s32)(32768.0f * (*(f32*)&b - 1.0f));
	}
	*(s32*)(p + 0x230) = 0;
	*(u32*)(p + 0xb0) = 0x20000;
	*(s32*)(p + 0x264) = fn_8013CC50(*(u32*)(p + 4), p + 0xc, 1.5f, 0x183, 0, 0, 0, 0, 1);
	*(s32*)(p + 0x268) = fn_8013CC50(*(u32*)(p + 4), p + 0xc, 1.5f, 0x184, 0, 0, 0, 0, 1);
}

extern "C" void fn_803273E0(void* thisPtr) {
	char* p = (char*)thisPtr;
	void* a = *(void**)(p + 0x264);
	if (a != 0) {
		*(f32*)((char*)a + 0xa4) = *(f32*)(p + 0xc);
		*(f32*)((char*)a + 0xa8) = *(f32*)(p + 0x10);
		*(f32*)((char*)a + 0xac) = *(f32*)(p + 0x14);
	}
	void* b = *(void**)(p + 0x268);
	if (b == 0) return;
	*(f32*)((char*)b + 0xa4) = *(f32*)(p + 0xc);
	*(f32*)((char*)b + 0xa8) = *(f32*)(p + 0x10);
	*(f32*)((char*)b + 0xac) = *(f32*)(p + 0x14);
}

extern "C" Actor* fn_8032742C(Actor* p, s16 n) {
	if (p) {
		*(void**)p = lbl_804AB4C0;
		fn_801EE434(*(void**)((char*)p + 0x264));
		fn_801EE434(*(void**)((char*)p + 0x268));
		__dt__5ActorFv(p, 0);
		if (n > 0) operator delete(p);
	}
	return p;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"

