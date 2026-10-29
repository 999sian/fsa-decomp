#include "types.h"
#include "JSystem/J2D/J2DScreen.h"
#include "JSystem/J2D/J2DPane.h"
#include "JSystem/J2D/J2DGrafContext.h"
#include "Game/SinitPoolChain.h"
#include "JSystem/JAudio/JASFakeMatchFSA.h"


extern "C" void* fn_802D6A9C(void);
extern "C" u64 lbl_8048F438[];
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
extern "C" const f32 lbl_80543BB8;
extern "C" void fn_80432750(char* this_, u8 flag, f32 a, f32 b, f32 c, f32 d) {
    fn_8013B490(lbl_8053AB10);
    if (*(u8*)(this_ + 0xa4) == 0) {
        f32 t;
        f32 sx;
        f32 sy;
        sx = c / *(f32*)(*(char**)(this_ + 0x20) + 0x18);
        sy = d / *(f32*)(*(char**)(this_ + 0x20) + 0x1c);
        t = *(f32*)(*(char**)(this_ + 0x20) + 0x10);
        a = (a + c * lbl_80543BB8) - (t + ((J2DScreen*)*(void**)(this_ + 4))->search(0x004E646174613031ULL)->getBounds()->i.x);
        f32 y = *(f32*)(*(char**)(this_ + 0x20) + 0x14);

        f32 resultY = (b + d * lbl_80543BB8) - (y + ((J2DScreen*)*(void**)(this_ + 4))->search(0x004E646174613031ULL)->getBounds()->i.y);
        char* p = this_;
        for (s32 i = 0; i < 4; ++i, p += 4) {
            fn_80402E08(*(void**)(p + 0x18), a, resultY);
            fn_80402CE0(*(void**)(p + 0x18), sx, sy);
        }
        if (flag != 0 && sx == 1.0f) {
            if (*(u16*)(this_+0x9e) == 1 || *(u16*)(this_+0x9e) == 2 || *(u16*)(this_+0x9e) == 3) this_[0xa2] = 1;
            else this_[0xa2] = 0;
            if (*(u8*)(this_ + 0xa2) == *(u8*)(this_ + 0xa3)) {
                J2DPane* pane = *(J2DPane**)(*(char**)(this_ + 0x34) + 4);
                if (!((u8*)pane)[0xb0]) pane->show();
                if (*(u8*)(this_ + 0xa2) == 1) resultY += 290.0f;
                fn_80402E08(*(void**)(this_ + 0x34), a, resultY);
            } else {
                J2DPane* pane = *(J2DPane**)(*(char**)(this_ + 0x34) + 4);
                if (((u8*)pane)[0xb0]) pane->hide();
                this_[0xa3] = this_[0xa2];
            }
        } else {
            J2DPane* pane = *(J2DPane**)(*(char**)(this_ + 0x34) + 4);
            if (((u8*)pane)[0xb0]) pane->hide();
            if (sx != 1.0f && *(u8*)(this_ + 0xac) == 1) this_[0xac] = 0;
        }
        ((J2DScreen*)*(void**)(this_ + 4))->draw(0.0f, 0.0f, *(J2DGrafContext**)(lbl_8053AB10 + 0x10));
    } else {
        f32 sx;
        f32 sy;
        f32 t;
        sx = c / *(f32*)(*(char**)(this_ + 0x2c) + 0x18);
        sy = d / *(f32*)(*(char**)(this_ + 0x2c) + 0x1c);
        t = *(f32*)(*(char**)(this_ + 0x2c) + 0x10);
        a = (a + c * lbl_80543BB8) - (t + ((J2DScreen*)*(void**)(this_ + 8))->search(0x004E646174613031ULL)->getBounds()->i.x);
        f32 y = *(f32*)(*(char**)(this_ + 0x2c) + 0x14);

        f32 resultY = (b + d * lbl_80543BB8) - (y + ((J2DScreen*)*(void**)(this_ + 8))->search(0x004E646174613031ULL)->getBounds()->i.y);
        s32 i;
        char* p = this_;
        for (i = 0; i < 3; ++i, p += 4) {
            fn_80402E08(*(void**)(p + 0x28), a, resultY);
            fn_80402CE0(*(void**)(p + 0x28), sx, sy);
        }
        ((J2DScreen*)*(void**)(this_ + 8))->draw(0.0f, 0.0f, *(J2DGrafContext**)(lbl_8053AB10 + 0x10));
    }
}

extern "C" void fn_80432AF8(char* this_) {
	*(s32*)(this_ + 0x90) = *(s32*)(this_ + 0x90) + 1;
	*(s32*)(this_ + 0x94) = *(s32*)(this_ + 0x94) + 1;
	if (*(s16*)(*(char**)(this_ + 0x10) + 6) <= *(s32*)(this_ + 0x90)) {
		*(s32*)(this_ + 0x90) = 0;
	}
	*(f32*)(*(char**)(this_ + 0x10) + 8) = (f32)*(s32*)(this_ + 0x90);
	((J2DScreen*)*(void**)(this_ + 0x4))->animation();
	if (*(s16*)(*(char**)(this_ + 0x14) + 6) <= *(s32*)(this_ + 0x94)) {
		*(s32*)(this_ + 0x94) = 0;
	}
	*(f32*)(*(char**)(this_ + 0x14) + 8) = (f32)*(s32*)(this_ + 0x94);
	((J2DScreen*)*(void**)(this_ + 0x8))->animation();
	this_[0xac] = 0;
	s32 idx;
	if (*(u8*)(lbl_8053AAF8 + 0x7e) == 0) {
		idx = 0;
	} else {
		idx = *(s32*)(*(char**)((char*)lbl_8053AB10 + 0x20) + 0x230);
	}
	if (idx >= 0) {
		u8 bVar1 = (*(s32*)(lbl_8053AAF8 + 0x4c) == 0xb) ? 1 : (*(u8*)(lbl_8053AAF8 + 0x88) == 2);
		if (!bVar1) {
			fn_8022EA0C(idx);
			if (fn_80236768() > 0) {
				fn_8022EA0C(idx);
				if (fn_80236768() < 900) {
					fn_8022EA0C(idx);
					s32 v = fn_80236768();
					s32 n = v / 60 + 1;
					if (n != *(s32*)(this_ + 0x98)) {
						if (n > 99) n = 99;
						if (n < 0) n = 0;
						if (n < 10) {
							u32 u = fn_804030C4(0x54494d47, lbl_804B1640[n]);
							void* r = ((void*(*)(void*, void*, u32, u32))(*(void***)(*(char**)(this_ + 0xc)))[15])(*(char**)(this_ + 0xc), lbl_8048F438, ((u32*)lbl_8048F438)[0], ((u32*)lbl_8048F438)[1]);
							((void(*)(void*, u32, u32))(*(void***)(r))[68])(r, u, 0);
							r = ((void*(*)(void*, void*, u32, u32))(*(void***)(*(char**)(this_ + 0xc)))[15])(*(char**)(this_ + 0xc), lbl_8048F438, ((u32*)lbl_8048F438)[2], ((u32*)lbl_8048F438)[3]);
							((void(*)(void*, u32, u32))(*(void***)(r))[68])(r, u, 0);
							r = ((void*(*)(void*, void*, u32, u32))(*(void***)(*(char**)(this_ + 0xc)))[15])(*(char**)(this_ + 0xc), lbl_8048F438, ((u32*)lbl_8048F438)[4], ((u32*)lbl_8048F438)[5]);
							if (((char*)r)[0xb0] == 1) {
								r = ((void*(*)(void*, void*, u32, u32))(*(void***)(*(char**)(this_ + 0xc)))[15])(*(char**)(this_ + 0xc), lbl_8048F438, ((u32*)lbl_8048F438)[4], ((u32*)lbl_8048F438)[5]);
								((char*)r)[0xb0] = 0;
								r = ((void*(*)(void*, void*, u32, u32))(*(void***)(*(char**)(this_ + 0xc)))[15])(*(char**)(this_ + 0xc), lbl_8048F438, ((u32*)lbl_8048F438)[6], ((u32*)lbl_8048F438)[7]);
								((char*)r)[0xb0] = 0;
							}
						} else {
							u32 u = fn_804030C4(0x54494d47, lbl_804B1640[n / 10]);
							void* r = ((void*(*)(void*, void*, u32, u32))(*(void***)(*(char**)(this_ + 0xc)))[15])(*(char**)(this_ + 0xc), lbl_8048F438, ((u32*)lbl_8048F438)[0], ((u32*)lbl_8048F438)[1]);
							((void(*)(void*, u32, u32))(*(void***)(r))[68])(r, u, 0);
							r = ((void*(*)(void*, void*, u32, u32))(*(void***)(*(char**)(this_ + 0xc)))[15])(*(char**)(this_ + 0xc), lbl_8048F438, ((u32*)lbl_8048F438)[2], ((u32*)lbl_8048F438)[3]);
							((void(*)(void*, u32, u32))(*(void***)(r))[68])(r, u, 0);
							u = fn_804030C4(0x54494d47, lbl_804B1640[n - (n / 10) * 10]);
							r = ((void*(*)(void*, void*, u32, u32))(*(void***)(*(char**)(this_ + 0xc)))[15])(*(char**)(this_ + 0xc), lbl_8048F438, ((u32*)lbl_8048F438)[4], ((u32*)lbl_8048F438)[5]);
							((void(*)(void*, u32, u32))(*(void***)(r))[68])(r, u, 0);
							r = ((void*(*)(void*, void*, u32, u32))(*(void***)(*(char**)(this_ + 0xc)))[15])(*(char**)(this_ + 0xc), lbl_8048F438, ((u32*)lbl_8048F438)[6], ((u32*)lbl_8048F438)[7]);
							((void(*)(void*, u32, u32))(*(void***)(r))[68])(r, u, 0);
							r = ((void*(*)(void*, void*, u32, u32))(*(void***)(*(char**)(this_ + 0xc)))[15])(*(char**)(this_ + 0xc), lbl_8048F438, ((u32*)lbl_8048F438)[4], ((u32*)lbl_8048F438)[5]);
							if (((char*)r)[0xb0] == 0) {
								r = ((void*(*)(void*, void*, u32, u32))(*(void***)(*(char**)(this_ + 0xc)))[15])(*(char**)(this_ + 0xc), lbl_8048F438, ((u32*)lbl_8048F438)[4], ((u32*)lbl_8048F438)[5]);
								((char*)r)[0xb0] = 1;
								r = ((void*(*)(void*, void*, u32, u32))(*(void***)(*(char**)(this_ + 0xc)))[15])(*(char**)(this_ + 0xc), lbl_8048F438, ((u32*)lbl_8048F438)[6], ((u32*)lbl_8048F438)[7]);
								((char*)r)[0xb0] = 1;
							}
						}
					}
					*(s32*)(this_ + 0x98) = n;
					this_[0xac] = 1;
					return;
				}
			}
		}
		bVar1 = (*(s32*)(lbl_8053AAF8 + 0x4c) == 0xb) ? 1 : (*(u8*)(lbl_8053AAF8 + 0x88) == 2);
		if (!bVar1) {
			fn_8022EA0C(idx);
			if (fn_80236630() > 0) {
				fn_8022EA0C(idx);
				if (fn_80236630() < 1200) {
					fn_8022EA0C(idx);
					s32 v = fn_80236630();
					s32 n = v / 60 + 1;
					if (n != *(s32*)(this_ + 0x98)) {
						if (n > 99) n = 99;
						if (n < 0) n = 0;
						if (n < 10) {
							u32 u = fn_804030C4(0x54494d47, lbl_804B1640[n]);
							void* r = ((void*(*)(void*, void*, u32, u32))(*(void***)(*(char**)(this_ + 0xc)))[15])(*(char**)(this_ + 0xc), lbl_8048F438, ((u32*)lbl_8048F438)[0], ((u32*)lbl_8048F438)[1]);
							((void(*)(void*, u32, u32))(*(void***)(r))[68])(r, u, 0);
							r = ((void*(*)(void*, void*, u32, u32))(*(void***)(*(char**)(this_ + 0xc)))[15])(*(char**)(this_ + 0xc), lbl_8048F438, ((u32*)lbl_8048F438)[2], ((u32*)lbl_8048F438)[3]);
							((void(*)(void*, u32, u32))(*(void***)(r))[68])(r, u, 0);
							r = ((void*(*)(void*, void*, u32, u32))(*(void***)(*(char**)(this_ + 0xc)))[15])(*(char**)(this_ + 0xc), lbl_8048F438, ((u32*)lbl_8048F438)[4], ((u32*)lbl_8048F438)[5]);
							if (((char*)r)[0xb0] == 1) {
								r = ((void*(*)(void*, void*, u32, u32))(*(void***)(*(char**)(this_ + 0xc)))[15])(*(char**)(this_ + 0xc), lbl_8048F438, ((u32*)lbl_8048F438)[4], ((u32*)lbl_8048F438)[5]);
								((char*)r)[0xb0] = 0;
								r = ((void*(*)(void*, void*, u32, u32))(*(void***)(*(char**)(this_ + 0xc)))[15])(*(char**)(this_ + 0xc), lbl_8048F438, ((u32*)lbl_8048F438)[6], ((u32*)lbl_8048F438)[7]);
								((char*)r)[0xb0] = 0;
							}
						} else {
							u32 u = fn_804030C4(0x54494d47, lbl_804B1640[n / 10]);
							void* r = ((void*(*)(void*, void*, u32, u32))(*(void***)(*(char**)(this_ + 0xc)))[15])(*(char**)(this_ + 0xc), lbl_8048F438, ((u32*)lbl_8048F438)[0], ((u32*)lbl_8048F438)[1]);
							((void(*)(void*, u32, u32))(*(void***)(r))[68])(r, u, 0);
							r = ((void*(*)(void*, void*, u32, u32))(*(void***)(*(char**)(this_ + 0xc)))[15])(*(char**)(this_ + 0xc), lbl_8048F438, ((u32*)lbl_8048F438)[2], ((u32*)lbl_8048F438)[3]);
							((void(*)(void*, u32, u32))(*(void***)(r))[68])(r, u, 0);
							u = fn_804030C4(0x54494d47, lbl_804B1640[n - (n / 10) * 10]);
							r = ((void*(*)(void*, void*, u32, u32))(*(void***)(*(char**)(this_ + 0xc)))[15])(*(char**)(this_ + 0xc), lbl_8048F438, ((u32*)lbl_8048F438)[4], ((u32*)lbl_8048F438)[5]);
							((void(*)(void*, u32, u32))(*(void***)(r))[68])(r, u, 0);
							r = ((void*(*)(void*, void*, u32, u32))(*(void***)(*(char**)(this_ + 0xc)))[15])(*(char**)(this_ + 0xc), lbl_8048F438, ((u32*)lbl_8048F438)[6], ((u32*)lbl_8048F438)[7]);
							((void(*)(void*, u32, u32))(*(void***)(r))[68])(r, u, 0);
							r = ((void*(*)(void*, void*, u32, u32))(*(void***)(*(char**)(this_ + 0xc)))[15])(*(char**)(this_ + 0xc), lbl_8048F438, ((u32*)lbl_8048F438)[4], ((u32*)lbl_8048F438)[5]);
							if (((char*)r)[0xb0] == 0) {
								r = ((void*(*)(void*, void*, u32, u32))(*(void***)(*(char**)(this_ + 0xc)))[15])(*(char**)(this_ + 0xc), lbl_8048F438, ((u32*)lbl_8048F438)[4], ((u32*)lbl_8048F438)[5]);
								((char*)r)[0xb0] = 1;
								r = ((void*(*)(void*, void*, u32, u32))(*(void***)(*(char**)(this_ + 0xc)))[15])(*(char**)(this_ + 0xc), lbl_8048F438, ((u32*)lbl_8048F438)[6], ((u32*)lbl_8048F438)[7]);
								((char*)r)[0xb0] = 1;
							}
						}
					}
					*(s32*)(this_ + 0x98) = n;
					this_[0xac] = 1;
					return;
				}
			}
		}
		bVar1 = (*(s32*)(lbl_8053AAF8 + 0x4c) == 0xb) ? 1 : (*(u8*)(lbl_8053AAF8 + 0x88) == 2);
		if (!bVar1) {
			fn_8022EA0C(idx);
			if (fn_802366CC() > 0) {
				fn_8022EA0C(idx);
				if (fn_802366CC() < 300) {
					fn_8022EA0C(idx);
					s32 v = fn_802366CC();
					s32 n = v / 60 + 1;
					if (n != *(s32*)(this_ + 0x98)) {
						if (n > 99) n = 99;
						if (n < 0) n = 0;
						if (n < 10) {
							u32 u = fn_804030C4(0x54494d47, lbl_804B1640[n]);
							void* r = ((void*(*)(void*, void*, u32, u32))(*(void***)(*(char**)(this_ + 0xc)))[15])(*(char**)(this_ + 0xc), lbl_8048F438, ((u32*)lbl_8048F438)[0], ((u32*)lbl_8048F438)[1]);
							((void(*)(void*, u32, u32))(*(void***)(r))[68])(r, u, 0);
							r = ((void*(*)(void*, void*, u32, u32))(*(void***)(*(char**)(this_ + 0xc)))[15])(*(char**)(this_ + 0xc), lbl_8048F438, ((u32*)lbl_8048F438)[2], ((u32*)lbl_8048F438)[3]);
							((void(*)(void*, u32, u32))(*(void***)(r))[68])(r, u, 0);
							r = ((void*(*)(void*, void*, u32, u32))(*(void***)(*(char**)(this_ + 0xc)))[15])(*(char**)(this_ + 0xc), lbl_8048F438, ((u32*)lbl_8048F438)[4], ((u32*)lbl_8048F438)[5]);
							if (((char*)r)[0xb0] == 1) {
								r = ((void*(*)(void*, void*, u32, u32))(*(void***)(*(char**)(this_ + 0xc)))[15])(*(char**)(this_ + 0xc), lbl_8048F438, ((u32*)lbl_8048F438)[4], ((u32*)lbl_8048F438)[5]);
								((char*)r)[0xb0] = 0;
								r = ((void*(*)(void*, void*, u32, u32))(*(void***)(*(char**)(this_ + 0xc)))[15])(*(char**)(this_ + 0xc), lbl_8048F438, ((u32*)lbl_8048F438)[6], ((u32*)lbl_8048F438)[7]);
								((char*)r)[0xb0] = 0;
							}
						} else {
							u32 u = fn_804030C4(0x54494d47, lbl_804B1640[n / 10]);
							void* r = ((void*(*)(void*, void*, u32, u32))(*(void***)(*(char**)(this_ + 0xc)))[15])(*(char**)(this_ + 0xc), lbl_8048F438, ((u32*)lbl_8048F438)[0], ((u32*)lbl_8048F438)[1]);
							((void(*)(void*, u32, u32))(*(void***)(r))[68])(r, u, 0);
							r = ((void*(*)(void*, void*, u32, u32))(*(void***)(*(char**)(this_ + 0xc)))[15])(*(char**)(this_ + 0xc), lbl_8048F438, ((u32*)lbl_8048F438)[2], ((u32*)lbl_8048F438)[3]);
							((void(*)(void*, u32, u32))(*(void***)(r))[68])(r, u, 0);
							u = fn_804030C4(0x54494d47, lbl_804B1640[n - (n / 10) * 10]);
							r = ((void*(*)(void*, void*, u32, u32))(*(void***)(*(char**)(this_ + 0xc)))[15])(*(char**)(this_ + 0xc), lbl_8048F438, ((u32*)lbl_8048F438)[4], ((u32*)lbl_8048F438)[5]);
							((void(*)(void*, u32, u32))(*(void***)(r))[68])(r, u, 0);
							r = ((void*(*)(void*, void*, u32, u32))(*(void***)(*(char**)(this_ + 0xc)))[15])(*(char**)(this_ + 0xc), lbl_8048F438, ((u32*)lbl_8048F438)[6], ((u32*)lbl_8048F438)[7]);
							((void(*)(void*, u32, u32))(*(void***)(r))[68])(r, u, 0);
							r = ((void*(*)(void*, void*, u32, u32))(*(void***)(*(char**)(this_ + 0xc)))[15])(*(char**)(this_ + 0xc), lbl_8048F438, ((u32*)lbl_8048F438)[4], ((u32*)lbl_8048F438)[5]);
							if (((char*)r)[0xb0] == 0) {
								r = ((void*(*)(void*, void*, u32, u32))(*(void***)(*(char**)(this_ + 0xc)))[15])(*(char**)(this_ + 0xc), lbl_8048F438, ((u32*)lbl_8048F438)[4], ((u32*)lbl_8048F438)[5]);
								((char*)r)[0xb0] = 1;
								r = ((void*(*)(void*, void*, u32, u32))(*(void***)(*(char**)(this_ + 0xc)))[15])(*(char**)(this_ + 0xc), lbl_8048F438, ((u32*)lbl_8048F438)[6], ((u32*)lbl_8048F438)[7]);
								((char*)r)[0xb0] = 1;
							}
						}
					}
					*(s32*)(this_ + 0x98) = n;
					this_[0xac] = 1;
				}
			}
		}
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
extern "C" void* __nw__FUl(u32 size);
extern "C" void __ct__Q29JGeometry8TVec3_f_Fv();
extern "C" void __construct_array(void* p, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* load__20J2DAnmLoaderDataBaseFPCv(const void* p);
extern "C" void* getGlbResource__13JKRFileLoaderFPCcP13JKRFileLoader(const char* name, void* loader);
extern "C" void __ct__9J2DScreenFv(void* p);
struct T80431_Res {
    void* vt;
    u8* data;
    u8 pad[0x24];
    T80431_Res() { vt = lbl_804AF86C; }
    f32 getWidth() const { return ((J2DPane*)data)->getWidth(); }
    f32 getOffsetX() const { return *(f32*)((const u8*)this + 0x10); }
    f32 getHeight() const { return ((J2DPane*)data)->getHeight(); }
};

static inline JKRArchive* MessageArchive() { return *(JKRArchive**)(lbl_80529DEC + 0x20); }

extern "C" void* fn_8043395C(void* this_) {
	char* base;
	u8* mgr;
	char* self = (char*)this_;
	base = (char*)lbl_8048F438;
	*(void**)self = lbl_804B1668;
	__construct_array(self + 0x40, (void*)__ct__Q29JGeometry8TVec3_f_Fv, 0, 0xc, 2);
	__construct_array(self + 0x58, (void*)__ct__Q29JGeometry8TVec3_f_Fv, 0, 0xc, 2);

	*(J2DScreen**)(self + 4) = new J2DScreen;
	mgr = (u8*)lbl_80529DEC;
	((J2DScreen*)*(void**)(self + 0x4))->setPriority((const char*)(base + 0xf8), 0x01100000, *(JKRArchive**)(mgr + 0x20));
	*(void**)(self + 0x10) = load__20J2DAnmLoaderDataBaseFPCv(getGlbResource__13JKRFileLoaderFPCcP13JKRFileLoader((const char*)(base + 0x10c), *(void**)(mgr + 0x20)));
	((J2DScreen*)*(void**)(self + 0x4))->setAnimation((J2DAnmTextureSRTKey*)*(void**)(self + 0x10));

	*(T80431_Res**)(self + 0x18) = new T80431_Res;
	fn_80402F04(*(void**)(self + 0x18), ((J2DScreen*)*(void**)(self + 0x4))->search(0x0000005073703031ULL));

	*(T80431_Res**)(self + 0x1c) = new T80431_Res;
	fn_80402F04(*(void**)(self + 0x1c), ((J2DScreen*)*(void**)(self + 0x4))->search(0x0000005073703032ULL));

	*(T80431_Res**)(self + 0x20) = new T80431_Res;
	fn_80402F04(*(void**)(self + 0x20), ((J2DScreen*)*(void**)(self + 0x4))->search(0x0000005073703033ULL));

	*(T80431_Res**)(self + 0x24) = new T80431_Res;
	fn_80402F04(*(void**)(self + 0x24), ((J2DScreen*)*(void**)(self + 0x4))->search(0x0000005073703034ULL));

	*(T80431_Res**)(self + 0x34) = new T80431_Res;
	fn_80402F04(*(void**)(self + 0x34), ((J2DScreen*)*(void**)(self + 0x4))->search(0x004E646174613032ULL));
	*(u8*)(*(char**)(*(char**)(self + 0x34) + 4) + 0xb0) = 0;


	J2DPane* pane20;
	char* wrapper20 = *(char**)(self + 0x20);
	f32 ox20 = *(f32*)(wrapper20 + 0x10);
	pane20 = *(J2DPane**)(wrapper20 + 4);
	f32 w20 = pane20->mBounds.f.x - pane20->mBounds.i.x;
	*(f32*)(self + 0x40) = -(w20 * lbl_80543BB8 - (ox20 + (((J2DScreen*)*(void**)(self + 0x4))->search(0x004E646174613031ULL)->getBounds()->i.x)));
	f32 oy20 = *(f32*)(*(char**)(self + 0x20) + 0x14);
	f32 h20 = (*(T80431_Res**)(self + 0x20))->getHeight();
	*(f32*)(self + 0x44) = -(h20 * lbl_80543BB8 - (oy20 + (((J2DScreen*)*(void**)(self + 0x4))->search(0x004E646174613031ULL)->getBounds()->i.y)));
	*(f32*)(self + 0x48) = lbl_80543BA8;
	*(f32*)(self + 0x70) = (*(T80431_Res**)(self + 0x20))->getWidth();
	*(f32*)(self + 0x78) = (*(T80431_Res**)(self + 0x20))->getHeight();

	f32 mx18 = *(f32*)(*(char**)(self + 0x18) + 0x8);
	f32 bx18 = ((J2DScreen*)*(void**)(self + 0x4))->search(0x004E646174613031ULL)->getBounds()->i.x;
	*(f32*)(self + 0x58) = mx18 + bx18;
	f32 my18 = *(f32*)(*(char**)(self + 0x18) + 0xc);
	f32 by18 = ((J2DScreen*)*(void**)(self + 0x4))->search(0x004E646174613031ULL)->getBounds()->i.y;
	*(f32*)(self + 0x5c) = my18 + by18;
	*(f32*)(self + 0x60) = lbl_80543BA8;
	*(f32*)(self + 0x80) = *(f32*)(*(char**)(*(char**)(self + 0x18) + 4) + 0x28) - *(f32*)(*(char**)(*(char**)(self + 0x18) + 4) + 0x20);
	*(f32*)(self + 0x88) = *(f32*)(*(char**)(*(char**)(self + 0x18) + 4) + 0x2c) - *(f32*)(*(char**)(*(char**)(self + 0x18) + 4) + 0x24);

	*(J2DScreen**)(self + 0x8) = new J2DScreen;
	((J2DScreen*)*(void**)(self + 0x8))->setPriority((const char*)(base + 0x120), 0x01100000, *(JKRArchive**)(mgr + 0x20));
	*(void**)(self + 0x14) = load__20J2DAnmLoaderDataBaseFPCv(getGlbResource__13JKRFileLoaderFPCcP13JKRFileLoader((const char*)(base + 0x138), *(void**)(mgr + 0x20)));
	((J2DScreen*)*(void**)(self + 0x8))->setAnimation((J2DAnmTextureSRTKey*)*(void**)(self + 0x14));

	*(T80431_Res**)(self + 0x28) = new T80431_Res;
	fn_80402F04(*(void**)(self + 0x28), ((J2DScreen*)*(void**)(self + 0x8))->search(0x0000005073703031ULL));

	*(T80431_Res**)(self + 0x2c) = new T80431_Res;
	fn_80402F04(*(void**)(self + 0x2c), ((J2DScreen*)*(void**)(self + 0x8))->search(0x0000005073703033ULL));

	*(T80431_Res**)(self + 0x30) = new T80431_Res;
	fn_80402F04(*(void**)(self + 0x30), ((J2DScreen*)*(void**)(self + 0x8))->search(0x0000005073703034ULL));


	f32 ox2c = *(f32*)(*(char**)(self + 0x2c) + 0x10);
	f32 w2c = (*(T80431_Res**)(self + 0x2c))->getWidth();
	*(f32*)(self + 0x4c) = -(w2c * lbl_80543BB8 - (ox2c + (((J2DScreen*)*(void**)(self + 0x8))->search(0x004E646174613031ULL)->getBounds()->i.x)));
	f32 oy2c = *(f32*)(*(char**)(self + 0x2c) + 0x14);
	f32 h2c = (*(T80431_Res**)(self + 0x2c))->getHeight();
	*(f32*)(self + 0x50) = -(h2c * lbl_80543BB8 - (oy2c + (((J2DScreen*)*(void**)(self + 0x8))->search(0x004E646174613031ULL)->getBounds()->i.y)));
	*(f32*)(self + 0x54) = lbl_80543BA8;
	*(f32*)(self + 0x74) = (*(T80431_Res**)(self + 0x2c))->getWidth();
	*(f32*)(self + 0x7c) = (*(T80431_Res**)(self + 0x2c))->getHeight();

	f32 mx28 = *(f32*)(*(char**)(self + 0x28) + 0x8);
	f32 bx28 = ((J2DScreen*)*(void**)(self + 0x8))->search(0x004E646174613031ULL)->getBounds()->i.x;
	*(f32*)(self + 0x64) = mx28 + bx28;
	f32 my28 = *(f32*)(*(char**)(self + 0x28) + 0xc);
	f32 by28 = ((J2DScreen*)*(void**)(self + 0x8))->search(0x004E646174613031ULL)->getBounds()->i.y;
	*(f32*)(self + 0x68) = my28 + by28;
	*(f32*)(self + 0x6c) = lbl_80543BA8;
	*(f32*)(self + 0x84) = *(f32*)(*(char**)(*(char**)(self + 0x28) + 4) + 0x28) - *(f32*)(*(char**)(*(char**)(self + 0x28) + 4) + 0x20);
	*(f32*)(self + 0x8c) = *(f32*)(*(char**)(*(char**)(self + 0x28) + 4) + 0x2c) - *(f32*)(*(char**)(*(char**)(self + 0x28) + 4) + 0x24);

	*(J2DScreen**)(self + 0xc) = new J2DScreen;
	((J2DScreen*)*(void**)(self + 0xc))->setPriority((const char*)(base + 0x150), 0x01100000, *(JKRArchive**)(mgr + 0x20));
	*(T80431_Res**)(self + 0x3c) = new T80431_Res;
	fn_80402F04(*(void**)(self + 0x3c), ((J2DScreen*)*(void**)(self + 0xc))->search(0x004E646174613030ULL));


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
	for (s32 i = 0; i < 6; i++) {
		self[0xa6 + i] = *(u8*)((char*)((J2DScreen*)*(void**)(self + 0xc))->search(lbl_8048F438[i]) + 0xb2);

	}
	return this_;
}

