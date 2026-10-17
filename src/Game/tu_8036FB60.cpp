#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"

namespace JMath {
extern const TAtanTable<1024, f32> atanTable_;
}
#include "JSystem/JUtility/JUTVideo.h"
#include "dolphin/mtx.h"
#include "JSystem/JGeometry/Box.h"

extern "C" u8 fn_8038BD08(s32, s32, u32, JGeometry::TVec3<f32>*, s32);
extern "C" void fn_8022FEB8(f32* box, s32 a, s32 b, s32 c, s32 d);
extern "C" s32 fn_8022FD8C(s32 b);
extern "C" void fn_8022FF8C(s32 a, f32* box, s32 b, s32 c, s32 d, s32 e);
extern "C" u8 fn_802300EC(void);
extern "C" u8 fn_80388CAC(s32 a, s32 b);
extern f32 lbl_80542DDC;


extern "C" void fn_803721F4(void);
extern "C" void fn_803703C8(void* self);
extern "C" void fn_8022FE80(int, int, int, int, int);
extern "C" unsigned char fn_80388EEC(int);
extern "C" unsigned char fn_80230534(int);
extern "C" void fn_8022CA6C(int, int, int);
extern "C" void fn_8023077C(void);
extern "C" void fn_80458FF0(void*, int, int, int);
extern "C" void __dt__5ActorFv(void*, int);
extern "C" unsigned char __vt__4FGAL[];
extern void* lbl_8053AF80;
extern float lbl_80542E00;
extern float lbl_80542E04;
extern float lbl_80542E08;
extern float lbl_80542DC4;
extern float lbl_80542DCC;
extern "C" void* fn_801F856C(void);
extern "C" int Actor_CreateByID(void* mgr, unsigned int name, unsigned int id, void* pos, unsigned int arg5, int arg6, int arg7);
void operator delete(void* p);
extern void* lbl_8053AB10;
extern float lbl_80542DF4;
extern float lbl_80542DF8;
extern float lbl_80542DFC;
extern float lbl_80542E28;
extern float lbl_80542E2C;
extern float lbl_80542E30;
extern float lbl_80542E34;
extern float lbl_80542E3C;
extern "C" f32 lbl_80542E38;
extern "C" s32 fn_80230CFC(s32);
extern s32 lbl_80474F4C[];
extern "C" void fn_80370020(char* self) {
    s32 idx;
    f32 box[4];
    JGeometry::TVec3<f32> pos;

    if (*(u8*)(self + 0x3a8) == 0) {
        if (*(s32*)(self + 0x3ac) == 0) {
            box[0] = *(f32*)(self + 0x60);
            box[1] = *(f32*)(self + 0x64);
            box[2] = *(f32*)(self + 0x68);
            box[3] = *(f32*)(self + 0x6c);
            box[0] += *(f32*)(self + 0x324);
            box[2] += *(f32*)(self + 0x324);
            box[1] += *(f32*)(self + 0x328);
            box[3] += *(f32*)(self + 0x328);
            fn_8022FEB8(box, *(s32*)(self + 4), *(s32*)(self + 0x198), 1, 0);
            idx = fn_8022FD8C(*(s32*)(self + 0x198));
            if (idx >= 0 && fn_802300EC()) {
                if (!(PSVECDistance((Vec*)(self + idx * 0xc + 0x264), (Vec*)(self + 0x324)) <= lbl_80542DDC)) {
                    pos = *(JGeometry::TVec3<f32>*)(self + 0x324);
                    if (fn_8038BD08(idx, 0x510, *(u32*)(self + 4), &pos, 0x22)) {
                        *(s32*)(self + 0x3a4) = idx;
                        *(u8*)(self + 0x3a8) = 1;
                        *(s32*)(self + 0x3a0) = 4;
                        fn_8023077C();
                    }
                }
            }
        }
    } else if (*(s32*)(self + 0x3a0) == 4) {
        box[0] = *(f32*)(self + 0x60);
        box[1] = *(f32*)(self + 0x64);
        box[2] = *(f32*)(self + 0x68);
        box[3] = *(f32*)(self + 0x6c);
        box[0] += *(f32*)(self + 0x324);
        box[2] += *(f32*)(self + 0x324);
        box[1] += *(f32*)(self + 0x328);
        box[3] += *(f32*)(self + 0x328);
        fn_8022FF8C(*(s32*)(self + 0x3a4), box, *(s32*)(self + 4), *(s32*)(self + 0x198), 1, 0);
        if (fn_80388CAC(*(s32*)(self + 0x3a4), *(s32*)(self + 0x198))) {
            *(s32*)(self + 0x3a4) = -1;
            *(u8*)(self + 0x3a8) = 0;
            fn_80230534(0);
            *(s32*)(self + 0x3ac) = 3;
            *(s32*)(self + 0x3a0) = -1;
        }
    }
}

extern "C" s32 fn_80370200(u8* self) {
    u8 found[4] = {0, 0, 0, 0};
    s32 idx = *(s32*)(self + 0x39c);
    f32 best = 100000.0f;
    Vec* tgt = (Vec*)(self + 0x264 + idx * 0xc);
    s32 result = -1;
    bool any = false;
    s32 i;
    for (i = 0; i < 4; i++) {
        Vec* p = (Vec*)(self + 0x294 + i * 0xc);
        u16 ang = JMath::atanTable_.atan2_(tgt->y - p->y, tgt->x - p->x) * 10430.378f;
        s32 dir = ((s32*)(self + 0x340))[i];
        if (ang >= 0x2000 && ang < 0x6000) {
            if (dir != 2) continue;
        } else if (ang >= 0x6000 && ang < 0xa000) {
            if (dir != 1) continue;
        } else if (ang >= 0xa000 && ang < 0xe000) {
            if (dir != 3) continue;
        } else {
            if (dir != 0) continue;
        }
        if (lbl_80474F4C[((s32*)(self + 0x340))[i]] == fn_80230CFC(idx)) {
            found[i] = 1;
            any = true;
        }
    }
    if (!any) {
        return -1;
    }
    for (i = 0; i < 4; i++) {
        if (found[i] == 1) {
            f32 d = PSVECDistance(tgt, (Vec*)(self + 0x294 + i * 0xc));
            if (d < best) {
                best = d;
                result = i;
            }
        }
    }
    return result;
}

extern "C" void fn_803703C8(void* self) {
    char* s = (char*)self;
    char* a = *(char**)((char*)lbl_8053AB10 + 0x24);
    float f2 = *(float*)(s + 0x250);
    float f1 = lbl_80542DF4;
    float a10 = -*(float*)(a + 0x10);
    float a20 = -*(float*)(a + 0x20);
    if (fabs(a10 - f1) < fabs(f2)) {
        *(float*)(s + 0x250) = lbl_80542DC4;
        *(float*)(s + 0x244) = f1;
    } else {
        *(float*)(s + 0x244) = *(float*)(s + 0x244) + f2;
    }
    f1 = lbl_80542DF8;
    f2 = *(float*)(s + 0x254);
    if (fabs(a20 - f1) < fabs(f2)) {
        *(float*)(s + 0x254) = lbl_80542DC4;
        *(float*)(s + 0x248) = f1;
    } else {
        *(float*)(s + 0x248) = *(float*)(s + 0x248) + f2;
    }
    f2 = *(float*)(s + 0x25c);
    f1 = lbl_80542DFC;
    float f3 = *(float*)(s + 0x260);
    if (fabs(f2 - f1) < fabs(f3)) {
        *(float*)(s + 0x260) = lbl_80542DC4;
        *(float*)(s + 0x260) = f1;
    } else {
        *(float*)(s + 0x25c) = f2 + f3;
    }
    float f1b = *(float*)(s + 0x248);
    float f0 = *(float*)(s + 0x25c);
    float sum = f1b + f0;
    float diff = f1b - f0;
    float f3b = *(float*)(s + 0x244);
    *(u8*)(*(char**)((char*)lbl_8053AB10 + 0x24) + 0x179) = 1;
    char* b = *(char**)((char*)lbl_8053AB10 + 0x24);
    if (*(u8*)(b + 0x7f5) != 0) {
        return;
    }
    *(u8*)(b + 0x7f4) = 1;
    *(s32*)(b + 0x7f8) = 5;
    *(float*)(b + 0x808) = f3b;
    *(float*)(b + 0x80c) = diff;
    *(float*)(b + 0x810) = f3b;
    *(float*)(b + 0x814) = sum;
    *(u8*)(b + 0x7f6) = 0;
}

extern "C" void fn_803704E8(void)
{
	fn_803721F4();
}

extern "C" void fn_80370508(char* self)
{
	struct VObj { virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10(int, int); };
	fn_803703C8(self);
	int state = *(int*)(self + 0x240);
	if (state != 0) {
		if (state == 1) {
			*(int*)(self + 0x368) = 0x104;
		}
	} else if (*(float*)(self + 0x328) < lbl_80542E00) {
		*(float*)(self + 0x328) = *(float*)(self + 0x328) + lbl_80542E04;
	} else {
		fn_80230534(0);
		*(int*)(self + 0x230) = 0xb;
		((VObj*)self)->v10(0xff, 1);
	}
}

extern "C" void fn_803705A0(char* self)
{
    fn_803703C8(self);
    if (*(float*)(self + 0x328) > lbl_80542E08) {
        *(float*)(self + 0x328) -= lbl_80542E04;
        if (*(float*)(self + 0x328) <= lbl_80542E08) {
            *(float*)(self + 0x328) = lbl_80542E08;
            JGeometry::TVec3<f32> v = *(JGeometry::TVec3<f32>*)(self + 0x324);
            v.sub(JGeometry::TVec3<f32>(lbl_80542DC4, lbl_80542DCC, lbl_80542DC4));
            int k = *(int*)(self + 0x23c);
            int n = (k < 0) + ((unsigned)k <= 0xb4) + 2;
            Actor_CreateByID(fn_801F856C(), 0x52555059, *(unsigned int*)(self + 4), &v, 0x30000 | (unsigned char)n, -1, -1);
            *(int*)(self + 0x240) = 30;
            *(int*)(self + 0x230) = 10;
            *(int*)(self + 0x368) = 0x108;
        }
    }
}

extern "C" void fn_803706AC(char* self)
{
	fn_803703C8(self);
	fn_8023077C();
	fn_8022FE80(0, *(int*)(self + 0x4), *(int*)(self + 0x198), 1, 0);
	if (fn_80388EEC(0)) {
		int n = *(int*)(self + 0x394);
		if (n >= 4) {
			if (n == 4) {
				*(int*)(self + 0x230) = 9;
				*(int*)(self + 0x368) = 0x106;
			} else {
				*(int*)(self + 0x230) = 10;
				*(int*)(self + 0x368) = 0x104;
			}
			fn_80458FF0(lbl_8053AF80, 0x100000b, 0, 0);
		} else {
			*(int*)(self + 0x230) = 6;
			*(int*)(self + 0x240) = 0x1e;
		}
	}
}

extern "C" void fn_80371D50(void* self, s32 id);
extern "C" u8 fn_8038BD08(s32, s32, u32, JGeometry::TVec3<f32>*, s32);
extern "C" void fn_8043D67C(void*, s32, s32, s32);
extern s32 lbl_80474F10[];
extern s32 lbl_80474F20[];
extern void* lbl_8053AAF8;
extern void* lbl_8053AED0;
extern "C" void fn_80370A7C(char* self)
{
	fn_803703C8(self);
	int state = *(int*)(self + 0x240);
	if (state != 0) {
		if (state == 1) {
			JGeometry::TVec3<f32> pos(
				(f32)(s32)JUTVideo::getManager()->getFbWidth() / 2.0f,
				(f32)(s32)JUTVideo::getManager()->getEfbHeight() / 2.0f,
				0.0f);
			fn_8022FE80(0, *(int*)(self + 0x4), *(int*)(self + 0x198), 1, 0);
			u32 owner = *(u32*)(self + 0x4);
			JGeometry::TVec3<f32> copy(pos);
			if (fn_8038BD08(0, lbl_80474F10[*(int*)(self + 0x394)], owner, &copy, 0x22)) {
				return;
			}
		}
	} else {
		fn_8022FE80(0, *(int*)(self + 0x4), *(int*)(self + 0x198), 1, 0);
		if (fn_80388EEC(0)) {
			fn_80230534(0);
			fn_8022CA6C(0, 5, 0);
			*(int*)(self + 0x230) = 7;
			fn_80371D50(self, lbl_80474F20[*(int*)(self + 0x394)]);
			if ((*(u8*)((char*)lbl_8053AAF8 + 0x83) & 3U) == 2) {
				fn_8043D67C(lbl_8053AED0, 0x50b, 0, 0);
			} else {
				fn_8043D67C(lbl_8053AED0, 0x50c, 0, 0);
			}
		}
	}
}

extern "C" void fn_803703C8(void*);
extern "C" void fn_80370C18(void* this_)
{
	char* p = (char*)this_;
	fn_803703C8(this_);
	fn_8022FE80(0, *(int*)(p + 4), *(int*)(p + 0x198), 1, 0);
	if (fn_80388EEC(0)) {
		*(int*)(p + 0x240) = 0x1e;
		*(int*)(p + 0x230) = 6;
		*(int*)(p + 0x23c) = 0;
	}
}

extern "C" u8 fn_8023ED8C(int);
extern "C" void fn_80230C6C(int);
extern "C" u8 fn_80230188(int);
extern "C" u8 fn_80230AD4(int);
extern "C" void fn_8037AE00(void*);
extern "C" u32 fn_80119DD0(void);
extern "C" void fn_80119998(u32, int, int, int, int, int, int, int);
extern float lbl_80542DEC;
extern float lbl_80542E18;
extern float lbl_80542E1C;
extern float lbl_80542E20;
extern void* lbl_8053AD70;
extern "C" void fn_8037100C(char* self)
{
	fn_803703C8(self);
	((void (*)(void*))fn_803721F4)(self);
	fn_80370020(self);
	JGeometry::TBox2f box(lbl_80542E18, lbl_80542DEC, lbl_80542E1C, lbl_80542E20);
	JGeometry::TBox2f copy = box;
	JGeometry::TVec3<f32>* pos = (JGeometry::TVec3<f32>*)(self + *(s32*)(self + 0x39c) * 0xc + 0x264);
	bool bVar3 = false;
	if (pos->x >= copy.i.x && pos->y >= copy.i.y && pos->x < copy.f.x && pos->y < copy.f.y) {
		bVar3 = true;
	}
	if (bVar3) {
		for (s32 i = 0; i < 4; i++) {
			if (((u8 (*)(int))fn_802300EC)(i) == 0) {
				return;
			}
		}
		if (*(u8*)(self + 0x398) == 1) {
			for (s32 i = 0; i < 4; i++) {
				if (fn_8023ED8C(i) != 0) {
					fn_80230C6C(i);
				}
			}
			fn_8022CA6C(0, 0, 0);
			if (fn_80230AD4(*(s32*)(self + 0x39c)) != 0) {
				for (s32 i = 0; i < 4; i++) {
					if (fn_80230188(i) == 0 && ((u8 (*)(int))fn_802300EC)(i) != 0) {
						fn_80230AD4(i);
					}
				}
				*(s32*)(self + 0x230) = 4;
				fn_8037AE00(lbl_8053AD70);
				u32 uVar4 = fn_80119DD0();
				fn_80119998(uVar4, 0x3c, 0, 2, 0, 0, 10, 0);
				*(s32*)(self + 0x240) = 0x46;
				fn_80458FF0(lbl_8053AF80, 0x1000007, 0, 0);
			}
		}
	}
}

extern "C" void fn_803711F0(char* self)
{
	fn_803703C8(self);
	fn_8022FE80(0, *(int*)(self + 0x4), *(int*)(self + 0x198), 1, 0);
	if (fn_80388EEC(0) && fn_80230534(0)) {
		*(int*)(self + 0x230) = 3;
		*(int*)(self + 0x3a4) = -1;
		*(int*)(self + 0x3ac) = 3;
		*(char*)(self + 0x3a8) = 0;
		*(int*)(self + 0x3a0) = -1;
		fn_8022CA6C(0, 5, 0);
	}
}

extern "C" void fn_801F06F0(void* this_, const char* name, s32 id, s32 a, s32 b, f32 s0, f32 s1);
extern "C" const char lbl_80474ED0[];
extern "C" f32 lbl_80542E38;
extern "C" void* lbl_8053AAF8;
extern "C" void fn_80372400(char* self) {
    Vec saved;
    s32 i;
    const char* tbl = lbl_80474ED0;

    if (*(u8*)((char*)lbl_8053AAF8 + 0x7e) == 0) {
        JGeometry::setTVec3f((f32*)(self + 0xc), (f32*)&saved);
        for (i = 0; i < 4; i++) {
            JGeometry::setTVec3f((f32*)(self + 0x294 + i * 0xc), (f32*)(self + 0xc));
            fn_801F06F0(self, tbl + 0x9c, *(s32*)(self + 0x350 + i * 4) + ((s32*)tbl)[*(s32*)(self + 0x364)], 0, 7, lbl_80542E38, lbl_80542E38);
        }
        if (*(u8*)(self + 0x399) == 0) {
            JGeometry::setTVec3f((f32*)&saved, (f32*)(self + 0xc));
        } else {
            JGeometry::setTVec3f((f32*)(self + 0x324), (f32*)(self + 0xc));
            fn_801F06F0(self, tbl + 0xb0, *(s32*)(self + 0x368) + *(s32*)(self + 0x370), 0, 7, lbl_80542E38, lbl_80542E38);
            JGeometry::setTVec3f((f32*)&saved, (f32*)(self + 0xc));
        }
    }
}

extern "C" void* fn_80372AA0(void* self, short flag)
{
	if (self) {
		*(void**)self = __vt__4FGAL;
		__dt__5ActorFv(self, 0);
		if (flag > 0) {
			operator delete(self);
		}
	}
	return self;
}

