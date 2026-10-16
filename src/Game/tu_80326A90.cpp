#include "Game/Actor.h"


extern "C" char lbl_804AB4C0[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" void fn_801EE434(void*);
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

