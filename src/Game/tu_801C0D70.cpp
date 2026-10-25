// Game TU 801C0D70-801C1768 (unnamed). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"
#include "Game/Actor.h"

extern s8 lbl_8053AC10[8];
static u16 lbl_804C7E70[0x30];
extern f32 lbl_8053ED90;
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* base, s32 idx);
extern "C" void fn_801C1768(void* obj);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D7440(void* p, s32 v);
extern "C" void fn_802D6BC8(void* p, s32 v);
extern "C" void fn_80138B7C(void* p);
extern "C" void fn_8022ADCC(void);
extern void* lbl_8053AAF8;
extern "C" void fn_8021C468(void* obj);

extern "C" void* fn_801C0D70(void) {
	if (!lbl_8053AC10[0]) {
		char* p = (char*)lbl_804C7E70;
		f32 rst = lbl_8053ED90;
		u16 zero = 0;
		s32 negone = -1;
		s8 one = 1;
		*(f32*)(p + 0x54) = rst;
		*(f32*)(p + 0x58) = rst;
		*(f32*)(p + 0x5c) = rst;
		*(u16*)(p + 0x0) = zero;
		*(u16*)(p + 0x2) = zero;
		*(u16*)(p + 0x4) = zero;
		*(u16*)(p + 0x6) = zero;
		*(u16*)(p + 0x8) = zero;
		*(s32*)(p + 0xc) = zero;
		*(s32*)(p + 0x50) = negone;
		lbl_8053AC10[0] = one;
	}
	return lbl_804C7E70;
}

extern "C" void* fn_8011921C(void);
extern "C" u8 fn_801186B0(void* p, s32 id);
extern "C" void fn_801F7AB8(void* base, u32 a, s32 b);
extern "C" void fn_801C186C(void* p);
extern "C" void fn_801C26FC(void* this_);
extern "C" void fn_801C272C(void* this_);
extern "C" void fn_801C27A8(void* this_);
extern "C" void fn_801C0DCC(u16* this_) {
	s32 i;
	char* p;
	if (this_[0] & 0x100) {
		if (fn_801186B0(fn_8011921C(), 0xf)) {
			s32 idx = *(s32*)((char*)this_ + 0x50);
			if (idx >= 0) {
				void* obj = fn_801F666C(fn_801F856C(), idx);
				if (obj != 0) {
					fn_801C186C(obj);
				}
			}
			fn_801F7AB8(fn_801F856C(), 0x48424d42, -1);
			p = (char*)this_;
			for (i = 0; i < *(s32*)((char*)this_ + 0xc); i++) {
				void* obj = fn_801F666C(fn_801F856C(), *(s32*)(p + 0x10));
				if (obj != 0) {
					*(s32*)((char*)obj + 0x568) = 1;
				}
				p += 4;
			}
			this_[0] &= ~0x40;
			this_[0] |= 0x400;
			this_[0] &= ~0x100;
		}
	}
	if (this_[0] & 0x200) {
		if (fn_801186B0(fn_8011921C(), 0xd)) {
			this_[0] |= 0x80;
			this_[0] &= ~0x200;
		}
	}
	if (this_[0] & 0x38) {
		s32 n = 0;
		p = (char*)this_;
		for (i = 0; i < *(s32*)((char*)this_ + 0xc); i++) {
			void* obj = fn_801F666C(fn_801F856C(), *(s32*)(p + 0x10));
			if (obj != 0 && (*(u32*)((char*)obj + 0x230) & 0x8000)) {
				n++;
			}
			p += 4;
		}
		u32 a = (u16)n;
		u32 b = this_[1];
		BOOL r28 = ((a | ~b) - ((a - b) >> 1)) >> 31;
		p = (char*)this_;
		for (i = 0; i < *(s32*)((char*)this_ + 0xc); i++) {
			void* obj = fn_801F666C(fn_801F856C(), *(s32*)(p + 0x10));
			if (obj != 0) {
				if (this_[0] & 0x8) {
					fn_801C27A8(obj);
				}
				if ((this_[0] & 0x10) && r28) {
					fn_801C272C(obj);
				}
				if (this_[0] & 0x20) {
					fn_801C26FC(obj);
				}
			}
			p += 4;
		}
		this_[0] &= ~0x29;
		if (r28) {
			this_[0] &= ~0x10;
		}
	}
}

extern int __float_epsilon[];
extern f32 lbl_8053ED94;
extern f32 lbl_8053ED98;
extern f32 lbl_8053ED9C;
extern f32 lbl_8053EDA0;
extern f32 lbl_8053EDA4;
extern "C" s32 fn_801C0FEC(u8* this_, const f32* param_2, f32* param_3) {
    f32 y = param_2[1];
    f32 x = param_2[0];
    s32 idx = *(s32*)(this_ + 0x50);
    s32 ret = 0;
    param_3[0] = x;
    param_3[1] = y;
    if (idx >= 0) {
        u8* obj = (u8*)fn_801F666C(fn_801F856C(), idx);
        if (obj != 0) {
            f32 dz = param_2[1] - *(f32*)(obj + 0x10);
            f32 dx = param_2[0] - *(f32*)(obj + 0xc);
            f32 lenSq = dx * dx + dz * dz;
            if (lenSq <= lbl_8053ED94) {
                ret = 1;
                if (param_2[1] <= *(f32*)(obj + 0x10)) {
                    if (param_2[0] < *(f32*)(obj + 0xc)) {
                        param_3[0] = *(f32*)(obj + 0xc) - lbl_8053ED98;
                    } else {
                        param_3[0] = lbl_8053ED98 + *(f32*)(obj + 0xc);
                    }
                } else {
                    if (lenSq <= lbl_8053ED9C * *(f32*)__float_epsilon) {
                    } else {
                        f32 s;
                        if (lenSq <= lbl_8053ED90) {
                            s = lenSq;
                        } else {
                            f32 r = __frsqrte(lenSq);
                            s = lbl_8053EDA0 * r * (lbl_8053EDA4 - lenSq * (r * r));
                        }
                        dx *= s;
                        dz *= s;
                    }
                    param_3[0] = *(f32*)(obj + 0xc);
                    param_3[1] = *(f32*)(obj + 0x10);
                    param_3[0] += dx * lbl_8053ED98;
                    param_3[1] += dz * lbl_8053ED98;
                }
            }
        }
    }
    return ret;
}

extern "C" void fn_801C115C(char* this_) {
    s32 idx = *(s32*)(this_ + 0x50);
    if (idx < 0) return;
    void* result = fn_801F666C(fn_801F856C(), idx);
    if (result != 0) {
        fn_801C1768(result);
    }
}

extern "C" void fn_801C11A4(char* this_) {
    s32 idx = *(s32*)(this_ + 0x50);
    if (idx < 0) return;
    void* result = fn_801F666C(fn_801F856C(), idx);
    if (result != 0) {
        fn_8021C468((char*)result + 0x2d8);
    }
}

extern "C" s32 fn_801C11F0(char* this_) {
    s32 count = *(s32*)(this_ + 0xc);
    s32 result = 0;
    if (count > 1) {
        s32 field2 = *(u16*)(this_ + 0x2);
        if (count != field2) {
            u16 field0 = *(u16*)(this_ + 0x0);
            if (field0 & 0x6) {
                result = 1;
            }
        }
    }
    return result;
}

extern "C" s32 fn_801CD664(s32 n);
extern "C" void fn_801C1224(char* this_, s32 param_2) {
    struct VObj {
        virtual void v00();
        virtual void v01();
        virtual void v02();
        virtual void v03();
        virtual void v04();
        virtual void v05();
        virtual void v06();
        virtual void v07();
        virtual void v08();
    };
    s32 count = *(s32*)(this_ + 0xc);
    char* p = this_;
    for (s32 i = 0; i < count; p += 4, i++) {
        char* obj = (char*)fn_801F666C(fn_801F856C(), *(s32*)(p + 0x10));
        if (obj != 0 && (*(u32*)(obj + 0x230) & 0x10000) == 0) {
            *(s32*)(obj + 0x10c) = param_2;
            ((VObj*)obj)->v07();
        }
    }
}

extern "C" void fn_801C12B8(char* this_) {
    char* p = this_ + fn_801CD664(*(s32*)(this_ + 0xc)) * 4;
    s32 id = *(s32*)(p + 0x10);
    void* mgr = (void*)fn_801F856C();
    char* obj = (char*)fn_801F666C(mgr, id);
    if (obj != 0) {
        *(u32*)(obj + 0x230) |= 0x10000;
    }
}

extern "C" s32 fn_801C1314(u16* this_) {
    s32 ret = 0;
    if (*(s32*)((char*)this_ + 0x50) >= 0) {
        if (((this_[0] & 0x40) == 0) && ((this_[0] & 0x80) == 0)) {
            u16 id = this_[2];
            if (id != 0 && *(s32*)((char*)this_ + 0xc) > 0 && this_[3] == id && this_[4] != id) {
                ret = 1;
            }
        }
    }
    return ret;
}

extern "C" void fn_801C1374(u16* this_, u8 param_2) {
    s32 x = *(s32*)((char*)this_ + 0x50);
    bool active;
    this_[4] = this_[4] + 1;
    active = !(x < 0);
    if (this_[4] == this_[2] && (!active || param_2 != 0)) {
        if (param_2 != 0) {
            this_[0] |= 0x200;
        }
        fn_802D7440(fn_802D6A9C(), 1);
        fn_80138B7C(lbl_8053AAF8);
        fn_802D6BC8(fn_802D6A9C(), 0);
        if (!(u8)(((u32)*(s32*)((char*)this_ + 0x50) >> 31) ^ 1)) {
            fn_8022ADCC();
        }
    } else if (active && (s32)this_[4] == 3) {
        this_[0] |= 0x100;
    }
}

extern "C" void fn_801C1440(char* this_, s32 param_2) {
    s32 found = 0;
    s32* p = (s32*)(this_ + 0x10);
    int i;
    if (*(s32*)(this_ + 0xc) <= 0) return;
    for (i = found; i < *(s32*)(this_ + 0xc); i++, p++) {
        if (!(u8)found) {
            if (param_2 == *p) found = 1;
        } else {
            p[-1] = *p;
        }
    }
    if ((u8)found) --*(s32*)(this_ + 0xc);
}

extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D7440(void* p, s32 v);
extern "C" void fn_802D6BC8(void* p, s32 v);
extern "C" void fn_80138B7C(void* p);
extern "C" void fn_8022ADCC(void);
extern void* lbl_8053AAF8;
extern "C" u16 fn_801C14A8(char* this_, void* param_2) {
    void** arr = (void**)(this_ + 0x10);
    arr[*(s32*)(this_ + 0xc)] = param_2;
    *(s32*)(this_ + 0xc) += 1;
    *(u16*)(this_ + 0x4) += 1;
    if (*(u16*)(this_ + 0x4) == 1) {
        fn_802D7440(fn_802D6A9C(), 0);
    }
    return *(u16*)(this_ + 0x4) - 1;
}

extern "C" void fn_801C151C(char* this_) {
    *(u16*)(this_ + 0x0) = 0;
    *(u16*)(this_ + 0x2) = 0;
    *(u16*)(this_ + 0x4) = 0;
    *(u16*)(this_ + 0x6) = 0;
    *(u16*)(this_ + 0x8) = 0;
    *(s32*)(this_ + 0xc) = 0;
    *(s32*)(this_ + 0x50) = -1;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
