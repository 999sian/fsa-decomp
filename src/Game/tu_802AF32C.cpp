#include "Game/Actor.h"


extern "C" char lbl_804A8418[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_802AF32C(Actor* p, s16 n) {
	if (p != nullptr) {
		*(void**)p = lbl_804A8418;
		__dt__5ActorFv(p, 0);
		if (n > 0) {
			operator delete(p);
		}
	}
	return p;
}

extern "C" void fn_802AF78C(Actor* thisObj) {
	u8* p = (u8*)thisObj;
	*(u32*)(p + 0x238) = *(u32*)(p + 0x90) & 0x3f;
	*(u32*)(p + 0x23c) = (*(u32*)(p + 0x90) >> 7) & 0x1f;
	*(s32*)(p + 0x234) = 0;
	if (*(s32*)(p + 0x238) == 2) {
		*(s32*)(p + 0x230) = 10;
	} else if (*(s32*)(p + 0x238) == 4) {
		*(s32*)(p + 0x230) = 4;
	} else {
		*(s32*)(p + 0x230) = 2;
	}
	*(s32*)(p + 0x240) = 0;
}

