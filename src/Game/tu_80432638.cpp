#include "types.h"
#include "JSystem/J2D/J2DScreen.h"
#include "JSystem/J2D/J2DPane.h"
#include "JSystem/J2D/J2DGrafContext.h"
#include "Game/SinitPoolChain.h"


extern "C" void* fn_802D6A9C(void);
extern "C" u8 lbl_8048F438[];
extern "C" char* lbl_8053AAF8;
extern "C" const u32 lbl_804B1640[];
extern "C" void fn_8022EA0C(s32 idx);
extern "C" s32 fn_80236768(void);
extern "C" s32 fn_80236630(void);
extern "C" s32 fn_802366CC(void);
extern "C" u32 fn_804030C4(u32 tag, u32 id);
extern "C" void fn_802D7870(void*, u16);
extern "C" void fn_8013B490(void* p);
extern "C" void fn_80402E08(void* p, f32 x, f32 y);
extern "C" char* lbl_8053AB10;
extern "C" char lbl_8050DB0C[];
extern "C" void* lbl_804B1668[];
extern "C" void __dl__FPv(void* this_);

struct DtorSlot2 {
	virtual void destroy(s32 freeFlag);
};

static inline void DispatchSlot2(char* slot) {
	DtorSlot2* obj = *(DtorSlot2**)slot;
	if (obj != 0) {
		obj->destroy(1);
	}
	*(void**)slot = 0;
}
extern "C" const f64 lbl_80543BB0;
extern "C" void fn_80432638(char* this_) {
    if (*(u8*)(this_ + 0xac) != 0) {
        f32 x0 = ((J2DPane*)*(void**)(*(char**)(this_ + 0x18) + 4))->getBounds()->i.x;
        f32 x1 = *(f32*)(*(char**)(this_ + 0x18) + 8);
        f32 y0 = ((J2DPane*)*(void**)(*(char**)(this_ + 0x18) + 4))->getBounds()->i.y;
        f32 y1 = *(f32*)(*(char**)(this_ + 0x18) + 0xc);
        fn_8013B490(lbl_8053AB10);
        f32 x = x0 - x1;
        f32 y = y0 - y1;
        x += (f32) * (s16*)(lbl_8050DB0C + 0x23e);
        y += (f32) * (s16*)(lbl_8050DB0C + 0x240);
        fn_80402E08(*(void**)(this_ + 0x3c), x, y);
        ((J2DScreen*)*(void**)(this_ + 0xc))->draw(0.0f, 0.0f, *(J2DGrafContext**)(lbl_8053AB10 + 0x10));
    }
}

extern "C" void fn_80402CE0(void* p, f32 x, f32 y);
extern "C" void fn_80432750(char* this_, u8 flag, f32 a, f32 b, f32 c, f32 d) {
	f32 sx;
	f32 sy;
	f32 ox;
	f32 x;
	f32 oy;
	f32 y;
	fn_8013B490(lbl_8053AB10);
	if (*(u8*)(this_ + 0xa4) == 0) {
		sx = c / *(f32*)(*(char**)(this_ + 0x20) + 0x18);
		sy = d / *(f32*)(*(char**)(this_ + 0x20) + 0x1c);
		ox = *(f32*)(*(char**)(this_ + 0x20) + 0x10);
		x = (a + c * 0.5f) - (ox + ((J2DScreen*)*(void**)(this_ + 0x4))->search(0x004E646174613031ULL)->getBounds()->i.x);
		oy = *(f32*)(*(char**)(this_ + 0x20) + 0x14);
		y = (b + d * 0.5f) - (oy + ((J2DScreen*)*(void**)(this_ + 0x4))->search(0x004E646174613031ULL)->getBounds()->i.y);
		char* p = this_;
		for (s32 i = 0; i < 4; i++) {
			fn_80402E08(*(void**)(p + 0x18), x, y);
			fn_80402CE0(*(void**)(p + 0x18), sx, sy);
			p += 4;
		}
		if (flag != 0 && sx == 1.0f) {
			u16 v = *(u16*)(this_ + 0x9e);
			if (v == 1 || v == 2 || v == 3) {
				this_[0xa2] = 1;
			} else {
				this_[0xa2] = 0;
			}
			if (*(u8*)(this_ + 0xa2) == *(u8*)(this_ + 0xa3)) {
				char* q = *(char**)(*(char**)(this_ + 0x34) + 4);
				if (*(u8*)(q + 0xb0) == 0) {
					q[0xb0] = 1;
				}
				if (*(u8*)(this_ + 0xa2) == 1) {
					y += 290.0f;
					fn_80402E08(*(void**)(this_ + 0x34), x, y);
				} else {
					if (*(u8*)(q + 0xb0) != 0) {
						q[0xb0] = 0;
					}
					this_[0xa3] = this_[0xa2];
				}
			} else {
				char* q = *(char**)(*(char**)(this_ + 0x34) + 4);
				if (*(u8*)(q + 0xb0) != 0) {
					q[0xb0] = 0;
				}
				if (sx != 1.0f) {
					if (*(u8*)(this_ + 0xac) == 1) {
						this_[0xac] = 0;
						((J2DScreen*)*(void**)(this_ + 0x4))->draw(0.0f, 0.0f, *(J2DGrafContext**)(lbl_8053AB10 + 0x10));
						return;
					}
				}
			}
		}
		char* p2 = this_;
		sx = c / *(f32*)(*(char**)(this_ + 0x2c) + 0x18);
		sy = d / *(f32*)(*(char**)(this_ + 0x2c) + 0x1c);
		ox = *(f32*)(*(char**)(this_ + 0x2c) + 0x10);
		x = (a + c * 0.5f) - (ox + ((J2DScreen*)*(void**)(this_ + 0x8))->search(0x004E646174613031ULL)->getBounds()->i.x);
		oy = *(f32*)(*(char**)(this_ + 0x2c) + 0x14);
		y = (b + d * 0.5f) - (oy + ((J2DScreen*)*(void**)(this_ + 0x8))->search(0x004E646174613031ULL)->getBounds()->i.y);
		for (s32 j = 0; j < 3; j++) {
			fn_80402E08(*(void**)(p2 + 0x28), x, y);
			fn_80402CE0(*(void**)(p2 + 0x28), sx, sy);
			p2 += 4;
		}
		((J2DScreen*)*(void**)(this_ + 0x8))->draw(0.0f, 0.0f, *(J2DGrafContext**)(lbl_8053AB10 + 0x10));
	}
}

extern "C" void fn_80433718(char* this_) {
    char* mgr = (char*)fn_802D6A9C();
    if (*(u16*)(this_ + 0xA0) != *(u16*)(mgr + 0x131DC)) {
        *(u16*)(this_ + 0xA0) = *(u16*)((char*)fn_802D6A9C() + 0x131DC);
        *(u16*)(this_ + 0x9E) = *(u16*)((char*)fn_802D6A9C() + 0x131DC);
        if (*(u16*)(this_ + 0x9E) & 0x8000) {
            this_[0xA4] = 1;
            *(u16*)(this_ + 0x9E) = *(u16*)(this_ + 0x9E) & 0x7FFF;
            void* mgr2 = fn_802D6A9C();
            fn_802D7870(mgr2, *(u16*)(this_ + 0x9E));
        } else {
            this_[0xA4] = 0;
        }
    }
}

extern "C" void* fn_804337B0(void* this_, s16 how) {
	if (this_ != 0) {
		*(void**)this_ = lbl_804B1668;
		char* p = (char*)this_;

		for (s32 i = 0; i < 2; i++) {
			DispatchSlot2(p + 0x4);
			DispatchSlot2(p + 0x10);
			p += 4;
		}

		s32 j = 0;
		p = (char*)this_;
		for (; j < 4; j++) {
			DispatchSlot2(p + 0x18);
			p += 4;
		}

		s32 k = 0;
		p = (char*)this_;
		for (; k < 3; k++) {
			DispatchSlot2(p + 0x28);
			p += 4;
		}

		DispatchSlot2((char*)this_ + 0x34);
		DispatchSlot2((char*)this_ + 0xc);
		DispatchSlot2((char*)this_ + 0x3c);
		if (how > 0) {
			__dl__FPv(this_);
		}
	}
	return this_;
}

extern "C" void fn_80402F04(void* obj, void* pane);
extern "C" const f32 lbl_80543BB8;
extern "C" const f32 lbl_80543BA8;
extern "C" void* lbl_804AF86C[];
extern "C" char lbl_80529DEC[];
extern "C" u8 lbl_8048F438[];
extern "C" void* __nw__FUl(u32 size);
extern "C" void __ct__Q29JGeometry8TVec3_f_Fv();
extern "C" void __construct_array(void* p, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* load__20J2DAnmLoaderDataBaseFPCv(const void* p);
extern "C" void* getGlbResource__13JKRFileLoaderFPCcP13JKRFileLoader(const char* name, void* loader);
extern "C" void __ct__9J2DScreenFv(void* p);
extern "C" void* fn_8043395C(void* this_) {
	char* base = (char*)lbl_8048F438;
	char* self = (char*)this_;
	*(void**)self = lbl_804B1668;
	__construct_array(self + 0x40, (void*)__ct__Q29JGeometry8TVec3_f_Fv, 0, 0xc, 2);
	__construct_array(self + 0x58, (void*)__ct__Q29JGeometry8TVec3_f_Fv, 0, 0xc, 2);

	char* s1 = (char*)__nw__FUl(0x118);
	if (s1 != 0) {
		__ct__9J2DScreenFv(s1);
	}
	*(char**)(self + 0x4) = s1;
	char* mgr = (char*)lbl_80529DEC;
	((J2DScreen*)*(void**)(self + 0x4))->setPriority((const char*)(base + 0xf8), 0x01100000, *(JKRArchive**)(mgr + 0x20));
	*(void**)(self + 0x10) = load__20J2DAnmLoaderDataBaseFPCv(getGlbResource__13JKRFileLoaderFPCcP13JKRFileLoader((const char*)(base + 0x10c), *(void**)(mgr + 0x20)));
	((J2DScreen*)*(void**)(self + 0x4))->setAnimation((J2DAnmTextureSRTKey*)*(void**)(self + 0x10));

	char* o = (char*)__nw__FUl(0x2c);
	if (o != 0) {
		*(void**)o = lbl_804AF86C;
		*(char**)(self + 0x18) = o;
		fn_80402F04(*(void**)(self + 0x18), ((J2DScreen*)*(void**)(self + 0x4))->search(0x0000005073703031ULL));
	}
	o = (char*)__nw__FUl(0x2c);
	if (o != 0) {
		*(void**)o = lbl_804AF86C;
		*(char**)(self + 0x1c) = o;
		fn_80402F04(*(void**)(self + 0x1c), ((J2DScreen*)*(void**)(self + 0x4))->search(0x0000005073703032ULL));
	}
	o = (char*)__nw__FUl(0x2c);
	if (o != 0) {
		*(void**)o = lbl_804AF86C;
		*(char**)(self + 0x20) = o;
		fn_80402F04(*(void**)(self + 0x20), ((J2DScreen*)*(void**)(self + 0x4))->search(0x0000005073703033ULL));
	}
	o = (char*)__nw__FUl(0x2c);
	if (o != 0) {
		*(void**)o = lbl_804AF86C;
		*(char**)(self + 0x24) = o;
		fn_80402F04(*(void**)(self + 0x24), ((J2DScreen*)*(void**)(self + 0x4))->search(0x0000005073703034ULL));
	}
	o = (char*)__nw__FUl(0x2c);
	if (o != 0) {
		*(void**)o = lbl_804AF86C;
		*(char**)(self + 0x34) = o;
		fn_80402F04(*(void**)(self + 0x34), ((J2DScreen*)*(void**)(self + 0x4))->search(0x004E646174613032ULL));
		*(u8*)(*(char**)(*(char**)(self + 0x34) + 4) + 0xb0) = 0;
	}

	f32 ox20 = *(f32*)(*(char**)(self + 0x20) + 0x10);
	f32 w20 = *(f32*)(*(char**)(*(char**)(self + 0x20) + 4) + 0x28) - *(f32*)(*(char**)(*(char**)(self + 0x20) + 4) + 0x20);
	f32 bx20 = ((J2DScreen*)*(void**)(self + 0x4))->search(0x004E646174613031ULL)->getBounds()->i.x;
	*(f32*)(self + 0x40) = (ox20 + bx20) - w20 * lbl_80543BB8;
	f32 oy20 = *(f32*)(*(char**)(self + 0x20) + 0x14);
	f32 h20 = *(f32*)(*(char**)(*(char**)(self + 0x20) + 4) + 0x2c) - *(f32*)(*(char**)(*(char**)(self + 0x20) + 4) + 0x24);
	f32 by20 = ((J2DScreen*)*(void**)(self + 0x4))->search(0x004E646174613031ULL)->getBounds()->i.y;
	*(f32*)(self + 0x44) = (oy20 + by20) - h20 * lbl_80543BB8;
	*(f32*)(self + 0x48) = lbl_80543BA8;
	*(f32*)(self + 0x70) = *(f32*)(*(char**)(*(char**)(self + 0x20) + 4) + 0x28) - *(f32*)(*(char**)(*(char**)(self + 0x20) + 4) + 0x20);
	*(f32*)(self + 0x78) = *(f32*)(*(char**)(*(char**)(self + 0x20) + 4) + 0x2c) - *(f32*)(*(char**)(*(char**)(self + 0x20) + 4) + 0x24);

	f32 mx18 = *(f32*)(*(char**)(self + 0x18) + 0x8);
	f32 bx18 = ((J2DScreen*)*(void**)(self + 0x4))->search(0x004E646174613031ULL)->getBounds()->i.x;
	*(f32*)(self + 0x58) = mx18 + bx18;
	f32 my18 = *(f32*)(*(char**)(self + 0x18) + 0xc);
	f32 by18 = ((J2DScreen*)*(void**)(self + 0x4))->search(0x004E646174613031ULL)->getBounds()->i.y;
	*(f32*)(self + 0x5c) = my18 + by18;
	*(f32*)(self + 0x60) = lbl_80543BA8;
	*(f32*)(self + 0x80) = *(f32*)(*(char**)(*(char**)(self + 0x18) + 4) + 0x28) - *(f32*)(*(char**)(*(char**)(self + 0x18) + 4) + 0x20);
	*(f32*)(self + 0x88) = *(f32*)(*(char**)(*(char**)(self + 0x18) + 4) + 0x2c) - *(f32*)(*(char**)(*(char**)(self + 0x18) + 4) + 0x24);

	char* s2 = (char*)__nw__FUl(0x118);
	if (s2 != 0) {
		__ct__9J2DScreenFv(s2);
	}
	*(char**)(self + 0x8) = s2;
	((J2DScreen*)*(void**)(self + 0x8))->setPriority((const char*)(base + 0x120), 0x01100000, *(JKRArchive**)(mgr + 0x20));
	*(void**)(self + 0x14) = load__20J2DAnmLoaderDataBaseFPCv(getGlbResource__13JKRFileLoaderFPCcP13JKRFileLoader((const char*)(base + 0x138), *(void**)(mgr + 0x20)));
	((J2DScreen*)*(void**)(self + 0x8))->setAnimation((J2DAnmTextureSRTKey*)*(void**)(self + 0x14));

	o = (char*)__nw__FUl(0x2c);
	if (o != 0) {
		*(void**)o = lbl_804AF86C;
		*(char**)(self + 0x28) = o;
		fn_80402F04(*(void**)(self + 0x28), ((J2DScreen*)*(void**)(self + 0x8))->search(0x0000005073703031ULL));
	}
	o = (char*)__nw__FUl(0x2c);
	if (o != 0) {
		*(void**)o = lbl_804AF86C;
		*(char**)(self + 0x2c) = o;
		fn_80402F04(*(void**)(self + 0x2c), ((J2DScreen*)*(void**)(self + 0x8))->search(0x0000005073703033ULL));
	}
	o = (char*)__nw__FUl(0x2c);
	if (o != 0) {
		*(void**)o = lbl_804AF86C;
		*(char**)(self + 0x30) = o;
		fn_80402F04(*(void**)(self + 0x30), ((J2DScreen*)*(void**)(self + 0x8))->search(0x0000005073703034ULL));
	}

	f32 ox2c = *(f32*)(*(char**)(self + 0x2c) + 0x10);
	f32 w2c = *(f32*)(*(char**)(*(char**)(self + 0x2c) + 4) + 0x28) - *(f32*)(*(char**)(*(char**)(self + 0x2c) + 4) + 0x20);
	f32 bx2c = ((J2DScreen*)*(void**)(self + 0x8))->search(0x004E646174613031ULL)->getBounds()->i.x;
	*(f32*)(self + 0x4c) = (ox2c + bx2c) - w2c * lbl_80543BB8;
	f32 oy2c = *(f32*)(*(char**)(self + 0x2c) + 0x14);
	f32 h2c = *(f32*)(*(char**)(*(char**)(self + 0x2c) + 4) + 0x2c) - *(f32*)(*(char**)(*(char**)(self + 0x2c) + 4) + 0x24);
	f32 by2c = ((J2DScreen*)*(void**)(self + 0x8))->search(0x004E646174613031ULL)->getBounds()->i.y;
	*(f32*)(self + 0x50) = (oy2c + by2c) - h2c * lbl_80543BB8;
	*(f32*)(self + 0x54) = lbl_80543BA8;
	*(f32*)(self + 0x74) = *(f32*)(*(char**)(*(char**)(self + 0x2c) + 4) + 0x28) - *(f32*)(*(char**)(*(char**)(self + 0x2c) + 4) + 0x20);
	*(f32*)(self + 0x7c) = *(f32*)(*(char**)(*(char**)(self + 0x2c) + 4) + 0x2c) - *(f32*)(*(char**)(*(char**)(self + 0x2c) + 4) + 0x24);

	f32 mx28 = *(f32*)(*(char**)(self + 0x28) + 0x8);
	f32 bx28 = ((J2DScreen*)*(void**)(self + 0x8))->search(0x004E646174613031ULL)->getBounds()->i.x;
	*(f32*)(self + 0x64) = mx28 + bx28;
	f32 my28 = *(f32*)(*(char**)(self + 0x28) + 0xc);
	f32 by28 = ((J2DScreen*)*(void**)(self + 0x8))->search(0x004E646174613031ULL)->getBounds()->i.y;
	*(f32*)(self + 0x68) = my28 + by28;
	*(f32*)(self + 0x6c) = lbl_80543BA8;
	*(f32*)(self + 0x84) = *(f32*)(*(char**)(*(char**)(self + 0x28) + 4) + 0x28) - *(f32*)(*(char**)(*(char**)(self + 0x28) + 4) + 0x20);
	*(f32*)(self + 0x8c) = *(f32*)(*(char**)(*(char**)(self + 0x28) + 4) + 0x2c) - *(f32*)(*(char**)(*(char**)(self + 0x28) + 4) + 0x24);

	char* s3 = (char*)__nw__FUl(0x118);
	if (s3 != 0) {
		__ct__9J2DScreenFv(s3);
	}
	*(char**)(self + 0xc) = s3;
	((J2DScreen*)*(void**)(self + 0xc))->setPriority((const char*)(base + 0x150), 0x01100000, *(JKRArchive**)(mgr + 0x20));
	o = (char*)__nw__FUl(0x2c);
	if (o != 0) {
		*(void**)o = lbl_804AF86C;
		*(char**)(self + 0x3c) = o;
		fn_80402F04(*(void**)(self + 0x3c), ((J2DScreen*)*(void**)(self + 0xc))->search(0x004E646174613030ULL));
	}

	*(u32*)(self + 0x90) = 0;
	*(u32*)(self + 0x94) = 0;
	*(u16*)(self + 0x9e) = 0;
	self[0xa2] = 0;
	self[0xa3] = 0;
	*(u16*)(self + 0x9c) = 0;
	*(u16*)(self + 0xa0) = 0xffff;
	self[0xa4] = 0;
	self[0xa5] = 0;
	*(u32*)(self + 0x98) = 0;
	self[0xac] = 0;
	char* tbl = base;
	for (s32 i = 0; i < 6; i++) {
		self[0xa6 + i] = *(u8*)((char*)((J2DScreen*)*(void**)(self + 0xc))->search(*(u64*)(tbl)) + 0xb2);
		tbl += 8;
	}
	return this_;
}

