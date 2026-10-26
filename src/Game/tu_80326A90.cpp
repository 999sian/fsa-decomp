#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JGeometry/Box.h"
#include "JSystem/JMath/JMath.h"
#include "Game/ItemBase.h"

struct Actor;
extern "C" f32 sincosTable___5JMath[];
extern f32 lbl_80541C28, lbl_80541C30, lbl_80541C34, lbl_80541C38, lbl_80541C3C, lbl_80541C40, lbl_80541C44, lbl_80541C48, lbl_80541C4C, lbl_80541C50, lbl_80541C54, lbl_80541C58;
extern "C" void fn_801F71A4(f32* v, f32 target, f32 rate, f32 limit);
extern "C" s32 fn_8023AF14(f32* box, s32 room, f32 f, s32 flag);
extern "C" f32* fn_8023E724(s32 i);
extern "C" void fn_8023C830(s32 i);
extern "C" void* fn_801F856C(void);
extern "C" s32 Actor_CreateByID(void* mgr, u32 name, u32 id, f32* pos, u32 arg5, s32 arg6, s32 arg7);


extern "C" char lbl_804AB4C0[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" void fn_801EE434(void*);
extern "C" void* lbl_8053AAF8;
extern "C" s32 fn_8013CC50(u32 id, void* p, f32 f, u32 a, u32 b, u32 c, u32 d, u32 e, u32 g);
extern "C" char lbl_80471888[];
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

extern "C" void fn_80326C5C(void* thisPtr) {
	char* p = (char*)thisPtr;
	JGeometry::TBox2<f32> box;
	f32 x;
	f32 dx;
	f32 dy;
	u32 seed;
	u32 bitsA, bitsB, bitsC;
	s32 hit;
	s32 i;
	char* e;
	s32 room;
	char* q;
	u32* rng;

	fn_801F71A4((f32*)(p + 0x3c), *(f32*)(p + 0x258), 0.1f, 0.5f);
	fn_801F71A4((f32*)(p + 0x40), *(f32*)(p + 0x25c), 0.1f, 0.5f);
	fn_801F71A4((f32*)(p + 0x14), *(f32*)(p + 0x260), 0.3f, 0.5f);
	*(JGeometry::TVec3<f32>*)(p + 0xc) += *(JGeometry::TVec3<f32>*)(p + 0x3c);

	e = *(char**)(p + 0x264);
	if (e != NULL) {
		*(f32*)(e + 0xa4) = *(f32*)(p + 0xc);
		*(f32*)(e + 0xa8) = *(f32*)(p + 0x10);
		*(f32*)(e + 0xac) = *(f32*)(p + 0x14);
	}
	e = *(char**)(p + 0x268);
	if (e != NULL) {
		*(f32*)(e + 0xa4) = *(f32*)(p + 0xc);
		*(f32*)(e + 0xa8) = *(f32*)(p + 0x10);
		*(f32*)(e + 0xac) = *(f32*)(p + 0x14);
	}

	switch (*(s32*)(p + 0x230)) {
	case 1:
		goto chase;
	case 0:
		if (*(s32*)(p + 0x23c) != 0) {
			goto tail;
		}
		*(s32*)(p + 0x244) += 0x300;
		*(f32*)(p + 0x260) = 2.0f * JMath::sincosTable_.mTable[(u16)*(s32*)(p + 0x244) >> 5].first + 7.0f;
		if (*(s32*)(p + 0x24c) == 0) {
			if (*(s32*)(p + 0x240) != 0) {
				*(s32*)(p + 0x248) += 0x100;
			} else {
				rng = (u32*)((char*)lbl_8053AAF8 + 0xb4);
				seed = *rng * 0x19660d + 0x3c6ef35f;
				*rng = seed;
				bitsA = (*rng >> 9) | 0x3f800000;
				x = *(f32*)&bitsA - 1.0f;
				*(s32*)(p + 0x240) = (s32)(30.0f * x) + 30;
				*(s32*)(p + 0x24c) = 1;
				*(f32*)(p + 0x258) = 0.0f;
				*(f32*)(p + 0x25c) = 0.0f;
			}
		} else if (*(s32*)(p + 0x240) == 0) {
			rng = (u32*)((char*)lbl_8053AAF8 + 0xb4);
			seed = *rng * 0x19660d + 0x3c6ef35f;
			*rng = seed;
			bitsB = (*rng >> 9) | 0x3f800000;
			x = *(f32*)&bitsB - 1.0f;
			*(s32*)(p + 0x248) += (s32)(32768.0f * x);
			seed = *rng * 0x19660d + 0x3c6ef35f;
			*rng = seed;
			bitsC = (*rng >> 9) | 0x3f800000;
			x = *(f32*)&bitsC - 1.0f;
			*(s32*)(p + 0x240) = (s32)(40.0f * x) + 40;
			*(s32*)(p + 0x24c) = 0;
		}
		box.set(*(JGeometry::TBox2<f32>*)(p + 0x60));
		box.addPos(*(JGeometry::TVec2<f32>*)(p + 0xc));
		room = *(s32*)(p + 0x4);
		hit = fn_8023AF14((f32*)&box, *(s32*)(p+4), 0.0f, 1);
		if (hit < 0) {
			goto tail;
		}
		*(s32*)(p + 0x244) = 0;
		*(s32*)(p + 0x248) = 0;
		*(s32*)(p + 0x24c) = 0;
		*(s32*)(p + 0x234) = 500;
		*(s32*)(p + 0x244) = hit;
		room = *(s32*)(p + 4);
		if (room >= 8) {
			Actor_CreateByID(fn_801F856C(), 'PEFF', room, (f32*)(p + 0xc), (hit & 3) | 4, -1, -1);
			*(s32*)(p + 0x23c) = 0;
			*(s16*)(p + 0x254) = 0;
			*(s32*)(p + 0x248) = 0;
			*(s32*)(p + 0xb0) = 0;
			*(s32*)(p + 0x230) = 1;
			*(u8*)(p + 0x11e) = 1;
			goto tail;
		}
		fn_8023C830(hit);
		*(s32*)(p + 0x234) = 1000;
		*(s32*)(p + 0x248) += 1;
		goto tail;
	default:
		goto tail;
	}

chase:
	if (*(s32*)(p + 0x23c) == 0) {
		f32* a = fn_8023E724(*(s32*)(p + 0x244));
		dx = *(f32*)(p + 0xc) - a[0];
		a = fn_8023E724(*(s32*)(p + 0x244));
		dy = *(f32*)(p + 0x10) - a[1];
		*(s16*)(p + 0x254) = (s16)(JMath::atanTable_.atan2_(-dx, -dy) * 10430.4f);
		*(s32*)(p + 0x23c) = 5;
		*(f32*)(p + 0x258) = 5.0f * JMath::sincosTable_.mTable[(u16)*(s16*)(p + 0x254) >> 5].first;
		*(f32*)(p + 0x25c) = 5.0f * JMath::sincosTable_.mTable[(u16)*(s16*)(p + 0x254) >> 5].second;
	}

	if (*(s32*)(p + 0x248) > 720) {
		e = *(char**)(p + 0x264);
		if (e != NULL) {
			*(u32*)(e + 0xf4) |= 1;
			*(s32*)(e + 0x24) = 1;
			*(s32*)(p + 0x264) = 0;
		}
		e = *(char**)(p + 0x268);
		if (e != NULL) {
			*(u32*)(e + 0xf4) |= 1;
			*(s32*)(e + 0x24) = 1;
			*(s32*)(p + 0x268) = 0;
		}
		*(u8*)(p + 0x11c) = 0;
	}
tail:
	if (*(s32*)(p + 0x238) == 0) {
		*(s32*)(p + 0x238) = 4;
		*(s32*)(p + 0x250) += 1;
		if (*(s32*)(p + 0x250) > 2) {
			*(s32*)(p + 0x250) = 0;
		}
	}
	q = p;
	for (i = 0; i < 2; i++, q += 8) {
		if (*(s32*)(q + 0x234) > 0) {
			*(s32*)(q + 0x234) -= 1;
		}
		if (*(s32*)(p + 0x234) <= 0) {
			e = *(char**)(p + 0x264);
			if (e != NULL) {
				*(u32*)(e + 0xf4) |= 1;
				*(s32*)(e + 0x24) = 1;
				*(s32*)(p + 0x264) = 0;
			}
			e = *(char**)(p + 0x268);
			if (e != NULL) {
				*(u32*)(e + 0xf4) |= 1;
				*(s32*)(e + 0x24) = 1;
				*(s32*)(p + 0x268) = 0;
			}
			*(u8*)(p + 0x11c) = 0;
		}
		if (*(s32*)(q + 0x238) > 0) {
			*(s32*)(q + 0x238) -= 1;
		}
		if (*(s32*)(p + 0x234) <= 0) {
			e = *(char**)(p + 0x264);
			if (e != NULL) {
				*(u32*)(e + 0xf4) |= 1;
				*(s32*)(e + 0x24) = 1;
				*(s32*)(p + 0x264) = 0;
			}
			e = *(char**)(p + 0x268);
			if (e != NULL) {
				*(u32*)(e + 0xf4) |= 1;
				*(s32*)(e + 0x24) = 1;
				*(s32*)(p + 0x268) = 0;
			}
			*(u8*)(p + 0x11c) = 0;
		}
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

void fn_803274A0(void) {}

#include "JSystem/JAudio/JASFakeMatchFSA.h"

