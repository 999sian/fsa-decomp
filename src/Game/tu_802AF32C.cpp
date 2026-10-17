#include "Game/Actor.h"
#include "Game/ItemBase.h"

struct PukuResMgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* get(u32 type, const char* name);
};
struct PukuGameRes { u8 pad[0xa4]; PukuResMgr* res; };
extern "C" PukuGameRes* lbl_8053AAF8;
extern "C" void* lbl_8053AB10;
extern "C" char lbl_8046CA50[];
extern "C" char lbl_804668A8[];
extern "C" void fn_802F86CC(void* layer, void* pos, void* res, s32 id, f32 sx, f32 sy, DrawRec* rec);
extern "C" void fn_803075AC(void* a, s32 room, void* pos, s32 id, bool b, s32 c, s32 d, s32 e, s32 f, s32 g);


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

extern "C" void fn_802AF38C(Actor* thisObj) {
	u8* p = (u8*)thisObj;
	DrawRec rec;
	s32 flag = *(s32*)(p + 0x23c) != 0;
	if (*(s32*)(p + 0x238) == 2) {
		fn_803075AC(*(void**)(p + 0x198), *(s32*)(p + 4), p + 0xc, 0x1c2, flag, 2, -1, 1, 0, 0);
	} else if (*(s32*)(p + 0x238) == 3) {
		fn_803075AC(*(void**)(p + 0x198), *(s32*)(p + 4), p + 0xc, *(s32*)(p + 0x234) + 0x2d5, flag, 2, -1, 1, 0, 0);
	} else if (*(s32*)(p + 0x238) == 4) {
		fn_803075AC(*(void**)(p + 0x198), *(s32*)(p + 4), p + 0xc, *(s32*)(p + 0x234) + 0x2ee, flag, 2, -1, 1, 0, 0);
	} else if (*(s32*)(p + 0x238) == 5) {
		fn_803075AC(*(void**)(p + 0x198), *(s32*)(p + 4), p + 0xc, *(s32*)(p + 0x234) + 0x2f7, flag, 2, -1, 1, 0, 0);
	} else if (*(s32*)(p + 0x238) == 6) {
		fn_803075AC(*(void**)(p + 0x198), *(s32*)(p + 4), p + 0xc, *(s32*)(p + 0x234) + 0x129, flag, 2, -1, 1, 0, 0);
	} else {
		s32 frame = *(s32*)(p + 0x234) + 0x70;
		if (*(s32*)(p + 4) < 8) {
			void* res = lbl_8053AAF8->res->get(0x534F4220, lbl_8046CA50);
			fn_802F86CC(*(void**)((u8*)lbl_8053AB10 + 0x20), p + 0xc, res, frame, 1.0f, 1.0f, &rec);
		}
		fn_803075AC(*(void**)(p + 0x198), *(s32*)(p + 4), p + 0xc, frame, flag, 2, -1, 1, 0, 0);
	}
}

extern "C" void fn_802AF6B0(Actor* thisObj) {
	u8* p = (u8*)thisObj;
	*(s32*)(p + 0x230) -= 1;
	if (*(s32*)(p + 0x230) != 0) {
		return;
	}
	if (*(s32*)(p + 0x238) == 2) {
		*(u8*)(p + 0x11c) = 0;
		return;
	}
	*(s32*)(p + 0x230) = 2;
	*(s32*)(p + 0x234) += 1;
	if (*(s32*)(p + 0x238) == 4) {
		*(s32*)(p + 0x230) = 4;
		if (*(s32*)(p + 0x234) < 7) {
			return;
		}
		*(u8*)(p + 0x11c) = 0;
		return;
	}
	if (*(s32*)(p + 0x234) >= 4 && *(s32*)(p + 0x238) == 6) {
		*(u8*)(p + 0x11c) = 0;
		return;
	}
	if (*(s32*)(p + 0x234) < 8) {
		return;
	}
	if (*(s32*)(p + 0x238) == 1) {
		*(s32*)(p + 0x240) += 1;
		if (*(s32*)(p + 0x240) >= 8) {
			*(u8*)(p + 0x11c) = 0;
			return;
		}
		*(s32*)(p + 0x234) = 0;
		return;
	}
	*(u8*)(p + 0x11c) = 0;
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
