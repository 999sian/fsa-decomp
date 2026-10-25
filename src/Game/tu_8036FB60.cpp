#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"

namespace JMath {
extern const TAtanTable<1024, f32> atanTable_;
}
#include "JSystem/JUtility/JUTVideo.h"
#include "dolphin/mtx.h"
#include "JSystem/JGeometry/Box.h"
#include "Game/ItemBase.h"
extern "C" char lbl_8050C8D0[];
extern "C" s8 lbl_8053AD63;
extern "C" s32 lbl_80474F5C[];
extern "C" void* fn_801F666C(void*, s32);
extern "C" const f32 lbl_80542DC0;
extern "C" void fn_80371D50(void*, s32);
extern "C" void fn_80458880(void*, s32, s32);
extern "C" void fn_8037B374(void*, JGeometry::TVec3<f32>*, s32);

extern "C" u8 fn_8038BD08(s32, s32, u32, JGeometry::TVec3<f32>*, s32);
extern "C" void fn_8022FEB8(f32* box, s32 a, s32 b, s32 c, s32 d);
extern "C" s32 fn_8022FD8C(s32 b);
extern "C" void fn_8022FF8C(s32 a, f32* box, s32 b, s32 c, s32 d, s32 e);
extern "C" u8 fn_802300EC(void);
extern "C" u8 fn_80388CAC(s32 a, s32 b);
extern f32 lbl_80542DDC;
extern const f32 lbl_80542DC4;
extern f32 lbl_80542DE8;
extern f32 lbl_80542DEC;
extern f32 lbl_80542DF0;
extern s32 lbl_80474F30[];
extern s32 lbl_80474F40[];

struct FSAPoolBlock {
	u32 mWord[36];
};


extern "C" void fn_803721F4(char* self);
extern "C" u8 fn_8023ED8C(int);
extern "C" void fn_80230C6C(int);
extern "C" u8 fn_8023E854(int);
extern "C" void fn_8023DFF4(int, void*);
extern "C" int fn_8022CAF8(int);
extern "C" u8 fn_802341D0(int);
extern "C" void fn_803703C8(void* self);
extern "C" void fn_8022FE80(int, int, int, int, int);
extern "C" unsigned char fn_80388EEC(int);
extern "C" unsigned char fn_80230534(int);
extern "C" void fn_8022CA6C(int, int, int);
extern "C" void fn_8023077C(void);
extern "C" void fn_80458FF0(void*, int, int, int);
extern "C" void __dt__5ActorFv(void*, int);
struct FSAObj;
typedef void (FSAObj::*FSAStateFn)(JGeometry::TBox2<f32>);
typedef void (FSAObj::*FSAStateUpdateFn)();
extern FSAStateFn lbl_804AE420[];
extern "C" s32 fn_8022EA0C(s32);
extern "C" JGeometry::TVec3<f32>* fn_8023E724(s32);
extern "C" void fn_80239914(JGeometry::TBox2<f32>* box, s32 room, s32 handle);
extern "C" void fn_8036FB60(char* self);
extern "C" unsigned char __vt__4FGAL[];
extern void* lbl_8053AF80;
extern const float lbl_80542E00;
extern const float lbl_80542E04;
extern float lbl_80542E08;
extern const float lbl_80542DC4;
extern float lbl_80542DCC;
extern "C" void* fn_801F856C(void);
extern "C" int Actor_CreateByID(void* mgr, unsigned int name, unsigned int id, void* pos, unsigned int arg5, int arg6, int arg7);
void operator delete(void* p);
extern void* lbl_8053AB10;
extern const float lbl_80542DF4;
extern const float lbl_80542DF8;
extern const float lbl_80542DFC;
extern float lbl_80542E28;
extern float lbl_80542E2C;
extern float lbl_80542E30;
extern const float lbl_80542E34;
extern const float lbl_80542E3C;
extern "C" const f32 lbl_80542E38;
extern "C" s32 fn_80230CFC(s32);
extern s32 lbl_80474F4C[];
extern "C" void fn_8036FB60(char* self) {
 s32 k;
 s32 j;
 s32 i;
 u8 found = 0;
 if (*(u8*)(self+0x398)==1) {
  for (j=0;j<4;j++) {
   for (i=0;i<4;i++) {
    if (PSVECDistance((Vec*)(self+0x264+i*12),(Vec*)(self+0x294+j*12)) < lbl_80542DC0) {
     found=1;
     break;
    }
   }
   if (found==1) break;
  }
 }
 if (found==1) {
  ++*(s32*)(self+0x238);
 } else {
  for (k=0;k<4;k++) {
   JGeometry::TVec3<f32> pos = *(JGeometry::TVec3<f32>*)(self+0x294+k*12);
   fn_8037B374(*(void**)(self+0x3b0+k*4), &pos, *(s32*)(self+0x340+k*4)*3);
  }
  s32 state=*(s32*)(self+0x230);
  if (state==0 || state==3 || state==11 || *(u8*)(self+0x398)!=1) {
   if (*(s32*)(self+0x238)==0) {
    ++*(s32*)(self+0x234);
    *(s32*)(self+0x234) &= 3;
    fn_80371D50(self,*(s32*)(self+0x234));
   } else {
    ((JGeometry::TVec3<f32>*)(self+0x294))->add(*(JGeometry::TVec3<f32>*)(self+0x2f4));
    ((JGeometry::TVec3<f32>*)(self+0x2a0))->add(*(JGeometry::TVec3<f32>*)(self+0x300));
    ((JGeometry::TVec3<f32>*)(self+0x2ac))->add(*(JGeometry::TVec3<f32>*)(self+0x30c));
    ((JGeometry::TVec3<f32>*)(self+0x2b8))->add(*(JGeometry::TVec3<f32>*)(self+0x318));
    if (*(s32*)(self+0x238)==0x76) {
     f32 zero = lbl_80542DC4;
     for (k=0;k<4;k++) {
      *(JGeometry::TVec3<f32>*)(self+0x294+k*12)=*(JGeometry::TVec3<f32>*)(self+0x2c4+k*12);
      *(f32*)(self+0x2fc+k*12)=zero;
      *(f32*)(self+0x2f8+k*12)=zero;
      *(f32*)(self+0x2f4+k*12)=zero;
      fn_80458880(lbl_8053AF80,0x37,-1);
     }
    } else if (*(s32*)(self+0x238)<0x76) {
     *(u8*)(self+0x398)=1;
    }
   }
  }
 }
}

extern "C" void fn_8036FDAC(void* self_)
{
    s32 id;
    char* self=(char*)self_;
	*(s32*)(self + 0x238) = 0x50;
	if (!lbl_8053AD63) {
		((JGeometry::TVec3<f32>*)lbl_8050C8D0)[0] = JGeometry::TVec3<f32>(0.0f, 0.0f, 0.0f);
		((JGeometry::TVec3<f32>*)lbl_8050C8D0)[1] = JGeometry::TVec3<f32>(16.0f, 0.0f, 0.0f);
		((JGeometry::TVec3<f32>*)lbl_8050C8D0)[2] = JGeometry::TVec3<f32>(32.0f, 0.0f, 0.0f);
		((JGeometry::TVec3<f32>*)lbl_8050C8D0)[3] = JGeometry::TVec3<f32>(48.0f, 0.0f, 0.0f);
		lbl_8053AD63 = 1;
	}
	*(s32*)(self + 0x230) = 0xb;
	*(s32*)(self + 0x234) = 1;
	for (s32 i = 0; i < 4; i++) {
		*(JGeometry::TVec3<f32>*)(self + 0x2c4 + i * 0xc) = *(JGeometry::TVec3<f32>*)(self + 0xc) + ((JGeometry::TVec3<f32>*)lbl_8050C8D0)[i];
		*(JGeometry::TVec3<f32>*)(self + 0x294 + i * 0xc) = *(JGeometry::TVec3<f32>*)(self + 0x2c4 + i * 0xc);
		((JGeometry::TVec3<f32>*)(self + 0x2f4 + i * 0xc))->zero();
		id = Actor_CreateByID(fn_801F856C(), 0x4a494a49, *(u32*)(self+4), self+0x294+i*12, lbl_80474F5C[i], -1, -1);
		*(void**)(self+0x3b0+i*4)=fn_801F666C(fn_801F856C(), id);
		*(s32*)(self + 0x340 + i * 4) = 1;
	}
	*(JGeometry::TVec3<f32>*)(self + 0x3c) = *(JGeometry::TVec3<f32>*)(self + 0x2f4);
	*(s32*)(self + 0x360) = 8;
	*(s32*)(self + 0x364) = 0;
	*(JGeometry::TVec3<f32>*)(self + 0x324) = *(JGeometry::TVec3<f32>*)(self + 0x294);
	*(s32*)(self + 0x368) = 0x386;
	*(s32*)(self + 0x36c) = 0x10;
	*(s32*)(self + 0x370) = 0;
	*(s32*)(self + 0x394) = 0;
	*(u8*)(self + 0x398) = 1;
	*(u8*)(self + 0x399) = 0;
	*(f32*)(self + 0x60) = -8.0f;
	*(f32*)(self + 0x64) = -8.0f;
	*(f32*)(self + 0x68) = 8.0f;
	*(f32*)(self + 0x6c) = 8.0f;
	*(s32*)(self + 0x3a0) = -1;
	*(s32*)(self + 0x3a4) = 0;
	*(u8*)(self + 0x3a8) = 0;
	*(s32*)(self + 0x3ac) = 0;
	((JGeometry::TVec3<f32>*)(self + 0x244))->zero();
	((JGeometry::TVec3<f32>*)(self + 0x250))->zero();
	*(f32*)(self + 0x25c) = 0.0f;
	*(f32*)(self + 0x260) = 0.0f;
	for (s32 i = 0; i < 4; i++) {
		*(s32*)(self + 0x374 + i * 4) = 0;
		*(s32*)(self + 0x384 + i * 4) = 0;
	}
}

extern "C" void fn_80370020(void* this_) {
    f32 box[4];
    JGeometry::TVec3<f32> pos;
    char* self = (char*)this_;

    if (*(u8*)(self + 0x3a8) == 0) {
        if (*(s32*)(self + 0x3ac) == 0) {
            s32 idx;
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
                if (PSVECDistance((Vec*)(self + idx * 0xc + 0x264), (Vec*)(self + 0x324)) <= lbl_80542DDC) {
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
    f32 best = 100000.0f;
    Vec* tgt;
    s32 i;
    s32 idx;
    s32 result = -1;
    bool any = false;
    idx = *(s32*)(self + 0x39c);
    tgt = (Vec*)(self + 0x264 + idx * 0xc);
    for (i = 0; i < 4; i++) {
        Vec* p = (Vec*)(self + 0x294 + i * 0xc);
        u16 ang = JMath::atanTable_.atan2_(tgt->y - p->y, tgt->x - p->x) * 10430.378f;
        if (ang >= 0x2000 && ang < 0x6000) {
            if (((s32*)(self + 0x340))[i] != 2) continue;
        } else if (ang >= 0x6000 && ang < 0xa000) {
            if (((s32*)(self + 0x340))[i] != 1) continue;
        } else if (ang >= 0xa000 && ang < 0xe000) {
            if (((s32*)(self + 0x340))[i] != 3) continue;
        } else {
            if (((s32*)(self + 0x340))[i] != 0) continue;
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

extern "C" void fn_803704E8(char* self)
{
	fn_803721F4(self);
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
            int k = *(int*)(self + 0x23c);
            int n = (k < 0) + ((unsigned)k <= 0xb4) + 2;
            JGeometry::TVec3<f32> pos = *(JGeometry::TVec3<f32>*)(self + 0x324);
            JGeometry::TVec3<f32> off;
            off.x = lbl_80542DC4;
            off.y = lbl_80542DCC;
            off.z = lbl_80542DC4;
            pos.sub(off);
            JGeometry::TVec3<f32> v = pos;
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

#pragma opt_lifetimes off
static inline void move80370764ToTarget() {
    JGeometry::TVec3<f32>* p = fn_8023E724(0);
    JGeometry::TVec3<f32> tgt(lbl_80542DE8, lbl_80542DEC, lbl_80542DC4);
    JGeometry::TVec3<f32> d = tgt - *p;
    if (PSVECMag((Vec*)&d) > lbl_80542DF0) fn_8023DFF4(0, &d);
}
static inline void move80370764ToTarget(JGeometry::TVec3<f32>& pos) {
    JGeometry::TVec3<f32>* p = fn_8023E724(0);
    JGeometry::TVec3<f32> tgt(lbl_80542DE8, lbl_80542DEC, lbl_80542DC4);
    pos = tgt - *p;
    if (PSVECMag((Vec*)&pos) > lbl_80542DF0) fn_8023DFF4(0, &pos);
}

extern "C" void fn_80370764(char* self)
{
	fn_803703C8(self);
	for (int i = 0; i < 4; i++) {
		if (fn_8023ED8C(i)) {
			fn_80230C6C(i);
		}
	}
	for (int i = 0; i < 4; i++) {
		if (fn_8023E854(i)) {
			JGeometry::TVec3<f32>* p = fn_8023E724(0);
			JGeometry::TVec3<f32> tgt(lbl_80542DE8, lbl_80542DEC, lbl_80542DC4);
			JGeometry::TVec3<f32> d = tgt - *p;
			if (PSVECMag((Vec*)&d) > lbl_80542DF0) {
				fn_8023DFF4(0, &d);
			}
			break;
		}
	}
	if (fn_8022CAF8(0) == 4) {
		fn_8022CA6C(0, 5, 0);
	}
	*(s32*)(self + 0x23c) += 1;
	fn_803721F4(self);
	{
		JGeometry::TVec3<f32>* p = fn_8023E724(0);
		JGeometry::TVec3<f32> tgt(lbl_80542DE8, lbl_80542DEC, lbl_80542DC4);
		JGeometry::TVec3<f32> pos = tgt - *p;
		if (PSVECMag((Vec*)&pos) > lbl_80542DF0) {
			fn_8023DFF4(0, &pos);
		}
	if (!fn_802341D0(0)) {
        *(s32*)(self + 0x240) = 2;
        return;
    }
    {
		if (*(u8*)(self + 0x398) != 0 && *(s32*)(self + 0x240) == 0) {
			if (fn_8022CAF8(0) == lbl_80474F30[*(s32*)(self + 0x394)]) {
				if (((u8 (*)(int))fn_802300EC)(0)) {
					f32 half = lbl_80542E04;
                    f32 width = (f32)(s32)JUTVideo::getManager()->getFbWidth();
                    f32 height = (f32)(s32)JUTVideo::getManager()->getEfbHeight();
                    pos.set(width * half, height * half, 0.0f);
					fn_8022FE80(0, *(int*)(self + 0x4), *(int*)(self + 0x198), 1, 0);
					s32 msg;
					s32 n = *(s32*)(self + 0x394);
					if (n < 3) {
						msg = lbl_80474F40[n];
                        *(s32*)(self + 0x394) = n + 1;
					} else if (*(s32*)(self + 0x23c) < 0x168) {
						*(s32*)(self + 0x394) = 4;
						msg = 0x509;
					} else {
						*(s32*)(self + 0x394) = 5;
						msg = 0x50a;
					}
					JGeometry::TVec3<f32> copy(pos);
					if (fn_8038BD08(0, msg, *(u32*)(self + 0x4), &copy, 0x22)) {
						fn_8023077C();
						*(s32*)(self + 0x230) = 8;
					}
				}
			}
		}
    }
}
}
#pragma opt_lifetimes reset
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
extern "C" void fn_8036FDAC(void* self);
extern "C" char lbl_8050C840[];
extern s8 lbl_8053AD60;
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

extern "C" u8 fn_80230188(int);
extern "C" u8 fn_80230AD4(int);
extern "C" u8 fn_8023EFEC(s32 idx);
extern f32 lbl_80542DC8;
extern void* lbl_8053AD70;
extern "C" void fn_80230498(s32 i, JGeometry::TVec3<f32>* v, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_8037AE30(void* p);
extern "C" void fn_80370C84(void* this_) {
    char* self = (char*)this_;
    s32 i;

    for (i = 0; i < 4; i++) {
        if (!fn_80230188(i) && ((u8 (*)(int))fn_802300EC)(i)) {
            fn_80230AD4(i);
        }
    }
    fn_803703C8(self);
    if (*(s32*)(self + 0x240) == 0x23) {
        *(s32*)(self + 0x234) = 1;
        for (i = 0; i < 4; i++) {
            *(s32*)(self + 0x350 + i * 4) = 0x38e;
            *(s32*)(self + 0x330 + i * 4) = 0;
            *(s32*)(self + 0x340 + i * 4) = 2;
        }
        *(u8*)(self + 0x398) = 1;
        *(s32*)(self + 0x238) = 0x80;
    }
    if (*(s32*)(self + 0x240) <= 0x23) {
        for (i = 0; i < 4; i++) {
            JGeometry::TVec3<f32> v;
            if (fn_8023EFEC(i)) {
                v.x = (f32)i * lbl_80542DC8;
            } else {
                v.x = (f32)i * lbl_80542DC8;
            }
            fn_80230498(i, &v, 0x2c8, 0xff, -0x80, -0x80, 1);
        }
    }
    if (*(s32*)(self + 0x240) == 0) {
        JGeometry::TVec3<f32> pos;
        pos = *(JGeometry::TVec3<f32>*)(self + 0xc);
        fn_8037AE30(lbl_8053AD70);
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
	JGeometry::TBox2f copy;
	JGeometry::TBox2f box(lbl_80542E18, lbl_80542DEC, lbl_80542E1C, lbl_80542E20);
	copy = box;
	bool bVar3 = false;
	JGeometry::TVec3<f32>* pos = (JGeometry::TVec3<f32>*)(self + *(s32*)(self + 0x39c) * 0xc + 0x264);
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

extern "C" u8 fn_8023EFEC(s32 idx);
extern "C" u8 fn_8023EA28(s32 idx);
extern "C" void fn_80230498(s32 i, JGeometry::TVec3<f32>* pos, s32 a, s32 b, s32 c, s32 d, s32 e);
extern f32 lbl_80542DD8;
extern f32 lbl_80542E24;
extern "C" void fn_80371284(char* self)
{
	s32 i;
	char* p;
	for (i = 0; i < 4; i++) {
		if (fn_80230188(i) == 0 && ((u8 (*)(int))fn_802300EC)(i) != 0) {
			fn_80230AD4(i);
		}
	}
	fn_803703C8(self);
	do {
		if (*(f32*)(self + 0x328) > lbl_80542E24) {
			*(f32*)(self + 0x328) -= lbl_80542E04;
			for (i = 0, p = self; i < 4; i++, p += 4) {
				if (*(s32*)(p + 0x374) != 0) {
					*(s32*)(p + 0x374) -= 1;
				}
				if (*(s32*)(p + 0x374) == 0) {
					*(s32*)(p + 0x374) = 6;
					*(s32*)(p + 0x384) += 1;
					if (fn_8023EFEC(i) && *(s32*)(p + 0x384) >= 7) {
						*(s32*)(p + 0x384) = 0;
					} else if (fn_8023EA28(i) && *(s32*)(p + 0x384) >= 4) {
						*(s32*)(p + 0x384) = 0;
					} else if (*(s32*)(p + 0x384) >= 8) {
						*(s32*)(p + 0x384) = 0;
					}
				}
				if (fn_80230188(i) || *(s32*)(self + 0x230) == 1) {
					JGeometry::TVec3<f32> tmp;
					if (fn_8023EFEC(i)) {
						tmp = *(JGeometry::TVec3<f32>*)(self + *(s32*)(self + 0x39c) * 0xc + 0x264) - JGeometry::TVec3<f32>(lbl_80542DC4, lbl_80542DD8, lbl_80542DC4);
						fn_80230498(i, &tmp, *(s32*)(p + 0x384) + 0x2cf, 0xff, -0x80, -0x80, 1);
					} else {
						tmp = *(JGeometry::TVec3<f32>*)(self + *(s32*)(self + 0x39c) * 0xc + 0x264) - JGeometry::TVec3<f32>(lbl_80542DC4, lbl_80542DD8, lbl_80542DC4);
						fn_80230498(i, &tmp, *(s32*)(p + 0x384) + 0x18, 0xff, -0x80, -0x80, 1);
					}
				}
			}
			if (*(f32*)(self + 0x328) > lbl_80542E24) {
				break;
			}
			*(f32*)(self + 0x328) = lbl_80542E24;
			*(s32*)(self + 0x384) = 0;
			*(s32*)(self + 0x388) = 0;
			*(s32*)(self + 0x38c) = 0;
			*(s32*)(self + 0x390) = 0;
		}
		JGeometry::TVec3<f32> v(JUTVideo::sManager->getFbWidth() * lbl_80542E04, JUTVideo::sManager->getEfbHeight() * lbl_80542E04, lbl_80542DC4);
		fn_8022FE80(0, *(s32*)(self + 0x4), *(s32*)(self + 0x198), 1, 0);
		if (!fn_8038BD08(0, 0x50f, *(u32*)(self + 0x4), &v, 0x22)) {
			break;
		}
		*(s32*)(self + 0x230) = 2;
		for (i = 0, p = self; i < 4; i++, p += 4) {
			if (*(s32*)(p + 0x374) != 0) {
				*(s32*)(p + 0x374) -= 1;
			}
			if (*(s32*)(p + 0x374) == 0) {
				*(s32*)(p + 0x374) = 6;
				*(s32*)(p + 0x384) += 1;
				if (fn_8023EFEC(i) && *(s32*)(p + 0x384) >= 7) {
					*(s32*)(p + 0x384) = 0;
				} else if (fn_8023EA28(i) && *(s32*)(p + 0x384) >= 4) {
					*(s32*)(p + 0x384) = 0;
				} else if (*(s32*)(p + 0x384) >= 8) {
					*(s32*)(p + 0x384) = 0;
				}
			}
			if (fn_80230188(i) || *(s32*)(self + 0x230) == 1) {
				JGeometry::TVec3<f32> tmp;
				if (fn_8023EFEC(i)) {
					tmp = *(JGeometry::TVec3<f32>*)(self + *(s32*)(self + 0x39c) * 0xc + 0x264) - JGeometry::TVec3<f32>(lbl_80542DC4, lbl_80542DD8, lbl_80542DC4);
					fn_80230498(i, &tmp, *(s32*)(p + 0x384) + 0x2cf, 0xff, -0x80, -0x80, 1);
				} else {
					tmp = *(JGeometry::TVec3<f32>*)(self + *(s32*)(self + 0x39c) * 0xc + 0x264) - JGeometry::TVec3<f32>(lbl_80542DC4, lbl_80542DD8, lbl_80542DC4);
					fn_80230498(i, &tmp, *(s32*)(p + 0x384) + 0x18, 0xff, -0x80, -0x80, 1);
				}
			}
		}
	} while (0);
	*(s32*)(self + 0x3a4) = 0;
	*(u8*)(self + 0x3a8) = 1;
	*(s32*)(self + 0x3a0) = 4;
	*(s32*)(self + 0x368) = 0x108;
}

#pragma opt_propagation off
extern "C" void fn_803717CC(char* self)
{
    JGeometry::TBox2<f32> area;
    JGeometry::TBox2<f32> rect;
    u32 b;
    u32 d;
    u32 c;
    u32 a;
    bool inside;
    f32* pos;
    fn_803721F4(self);
    JGeometry::TBox2<f32> tmp;
    tmp.i.x = lbl_80542E1C;
    tmp.i.y = lbl_80542E28;
    tmp.f.x = lbl_80542E2C;
    tmp.f.y = lbl_80542E30;
    a = *(u32*)&tmp.i.x;
    *(u32*)&area.i.x = a;
    b = *(u32*)&tmp.i.y;
    *(u32*)&area.i.y = b;
    c = *(u32*)&tmp.f.x;
    *(u32*)&area.f.x = c;
    d = *(u32*)&tmp.f.y;
    *(u32*)&area.f.y = d;
	pos = (f32*)(self + *(s32*)(self + 0x39c) * 0xc + 0x264);
    inside = false;
    if (pos[0] >= area.i.x && pos[1] >= area.i.y && pos[0] < area.f.x && pos[1] < area.f.y) inside = true;
    if (inside) {
		for (s32 i = 0; i < 4; i++) {
			if (fn_8023ED8C(i) != 0) {
				fn_80230C6C(i);
			}
		}
		fn_8022CA6C(*(s32*)(self + 0x39c), 5, 0);
		for (s32 i = 0; i < 4; i++) {
			if (fn_80230188(i) == 0 && ((u8 (*)(int))fn_802300EC)(i) != 0) {
				fn_80230AD4(i);
			}
		}
		*(f32*)(self + 0x324) = lbl_80542DF4;
		*(f32*)(self + 0x328) = lbl_80542E00;
		*(f32*)(self + 0x32c) = lbl_80542DC4;
		*(u8*)(self + 0x399) = 1;
		*(s32*)(self + 0x230) = 1;
		char* view = *(char**)((char*)lbl_8053AB10 + 0x24);
        *(f32*)(self + 0x244) = -*(f32*)(view + 0x10);
		*(f32*)(self + 0x248) = -*(f32*)(view + 0x20);
		*(f32*)(self + 0x24c) = lbl_80542DC4;
		*(f32*)(self + 0x250) = (lbl_80542DF4 - *(f32*)(self + 0x244)) / lbl_80542E34;
		*(f32*)(self + 0x254) = (lbl_80542DF8 - *(f32*)(self + 0x248)) / lbl_80542E34;
        u32* src = (u32*)(*(char**)((char*)lbl_8053AB10 + 0x24) + 0x164);
        *(u32*)&rect.i.x = src[0]; *(u32*)&rect.i.y = src[1];
        *(u32*)&rect.f.x = src[2]; *(u32*)&rect.f.y = src[3];
		*(f32*)(self + 0x25c) = (rect.f.y - rect.i.y) * lbl_80542E04;
		*(f32*)(self + 0x260) = lbl_80542DFC - *(f32*)(self + 0x25c);
        f32 f0;
        f32 f1;
        f1 = *(f32*)(self + 0x248);
        f0 = *(f32*)(self + 0x25c);
		f32 f4 = *(f32*)(self + 0x244);
        f32 diff;
        f32 sum;
        sum = f1 + f0;
        diff = f1 - f0;
		*(u8*)(*(char**)((char*)lbl_8053AB10 + 0x24) + 0x179) = 1;
		char* a = *(char**)((char*)lbl_8053AB10 + 0x24);
		if (*(u8*)(a + 0x840) == 0) {
			*(u8*)(a + 0x840) = 1;
			*(f32*)(a + 0x844) = f4;
			*(f32*)(a + 0x848) = diff;
			*(f32*)(a + 0x84c) = f4;
			*(f32*)(a + 0x850) = sum;
			*(f32*)(a + 0x854) = lbl_80542E38;
			*(f32*)(a + 0x1d4) = lbl_80542E3C;
			*(f32*)(a + 0x1d8) = lbl_80542E3C;
		}
	}
}
#pragma opt_propagation reset
extern "C" char lbl_8050C870[];
extern "C" char lbl_8050C8A0[];
extern s8 lbl_8053AD61;
extern s8 lbl_8053AD62;
extern "C" const s32 lbl_80474EE0[];
extern "C" const s32 lbl_80474EF0[];
extern "C" void fn_80371D50(void* this_, s32 id)
{
	s32 i;
	*(s32*)((char*)this_ + 0x238) = 0x80;
	*(u8*)((char*)this_ + 0x398) = 0;
	char* self = (char*)this_;
	switch (id) {
	case 3:
		if (!lbl_8053AD61) {
			((JGeometry::TVec3<f32>*)lbl_8050C870)[0] = JGeometry::TVec3<f32>(0.0f, 0.0f, 0.0f);
			((JGeometry::TVec3<f32>*)lbl_8050C870)[1] = JGeometry::TVec3<f32>(-16.0f, 16.0f, 0.0f);
			((JGeometry::TVec3<f32>*)lbl_8050C870)[2] = JGeometry::TVec3<f32>(16.0f, 16.0f, 0.0f);
			((JGeometry::TVec3<f32>*)lbl_8050C870)[3] = JGeometry::TVec3<f32>(0.0f, 32.0f, 0.0f);
			lbl_8053AD61 = 1;
		}
		for (i = 0; i < 4; i++) {
			*(JGeometry::TVec3<f32>*)(self + 0x2c4 + i * 0xc) = *(JGeometry::TVec3<f32>*)(self + 0xc) + ((JGeometry::TVec3<f32>*)lbl_8050C870)[i];
			*(JGeometry::TVec3<f32>*)(self + 0x2f4 + i * 0xc) = JGeometry::TVec3<f32>(
				(*(f32*)(self + 0x2c4 + i * 0xc) - *(f32*)(self + 0x294 + i * 0xc)) / 10.0f,
				(*(f32*)(self + 0x2c8 + i * 0xc) - *(f32*)(self + 0x298 + i * 0xc)) / 10.0f,
				0.0f);
			*(s32*)(self + 0x350 + i * 4) = lbl_80474EE0[i];
			*(s32*)(self + 0x340 + i * 4) = lbl_80474EF0[i];
		}
		break;
	case 1:
		for (i = 0; i < 4; i++) {
			*(JGeometry::TVec3<f32>*)(self + 0x2c4 + i * 0xc) = *(JGeometry::TVec3<f32>*)(self + 0xc) + JGeometry::TVec3<f32>(16.0f * i, 0.0f, 0.0f);
			*(JGeometry::TVec3<f32>*)(self + 0x2f4 + i * 0xc) = JGeometry::TVec3<f32>(
				(*(f32*)(self + 0x2c4 + i * 0xc) - *(f32*)(self + 0x294 + i * 0xc)) / 10.0f,
				(*(f32*)(self + 0x2c8 + i * 0xc) - *(f32*)(self + 0x298 + i * 0xc)) / 10.0f,
				0.0f);
			*(s32*)(self + 0x350 + i * 4) = 0x388;
			*(s32*)(self + 0x340 + i * 4) = 0;
		}
		break;
	case 2:
		for (i = 0; i < 4; i++) {
			*(JGeometry::TVec3<f32>*)(self + 0x2c4 + i * 0xc) = *(JGeometry::TVec3<f32>*)(self + 0xc) + JGeometry::TVec3<f32>(0.0f, 16.0f * i, 0.0f);
			*(JGeometry::TVec3<f32>*)(self + 0x2f4 + i * 0xc) = JGeometry::TVec3<f32>(
				(*(f32*)(self + 0x2c4 + i * 0xc) - *(f32*)(self + 0x294 + i * 0xc)) / 10.0f,
				(*(f32*)(self + 0x2c8 + i * 0xc) - *(f32*)(self + 0x298 + i * 0xc)) / 10.0f,
				0.0f);
			*(s32*)(self + 0x350 + i * 4) = 0x38e;
			*(s32*)(self + 0x340 + i * 4) = 2;
		}
		break;
	case 0:
		if (!lbl_8053AD62) {
			((JGeometry::TVec3<f32>*)lbl_8050C8A0)[0] = JGeometry::TVec3<f32>(0.0f, 0.0f, 0.0f);
			((JGeometry::TVec3<f32>*)lbl_8050C8A0)[1] = JGeometry::TVec3<f32>(16.0f, 0.0f, 0.0f);
			((JGeometry::TVec3<f32>*)lbl_8050C8A0)[2] = JGeometry::TVec3<f32>(0.0f, 16.0f, 0.0f);
			((JGeometry::TVec3<f32>*)lbl_8050C8A0)[3] = JGeometry::TVec3<f32>(16.0f, 16.0f, 0.0f);
			lbl_8053AD62 = 1;
		}
		for (i = 0; i < 4; i++) {
			*(JGeometry::TVec3<f32>*)(self + 0x2c4 + i * 0xc) = *(JGeometry::TVec3<f32>*)(self + 0xc) + ((JGeometry::TVec3<f32>*)lbl_8050C8A0)[i];
			*(JGeometry::TVec3<f32>*)(self + 0x2f4 + i * 0xc) = JGeometry::TVec3<f32>(
				(*(f32*)(self + 0x2c4 + i * 0xc) - *(f32*)(self + 0x294 + i * 0xc)) / 10.0f,
				(*(f32*)(self + 0x2c8 + i * 0xc) - *(f32*)(self + 0x298 + i * 0xc)) / 10.0f,
				0.0f);
			*(s32*)(self + 0x350 + i * 4) = 0x391;
			*(s32*)(self + 0x340 + i * 4) = 3;
		}
		break;
	}
}

extern "C" const f32 lbl_80542DC0;
extern "C" void fn_80371A2C(void*);
extern "C" void fn_80458880(void*, s32, s32);
extern "C" void fn_803721F4(char* self) {
 s32 k;
 s32 j;
 s32 i;
 u8 found = 0;
 if (*(u8*)(self+0x398)==1) {
  for (j=0;j<4;j++) {
   for (i=0;i<4;i++) {
    if (PSVECDistance((Vec*)(self+0x264+i*12),(Vec*)(self+0x294+j*12)) < lbl_80542DC0) {
     found=1;
     break;
    }
   }
   if (found==1) break;
  }
 }
 if (found==1) {
  ++*(s32*)(self+0x238);
  fn_80371A2C(self);
 } else {
  s32 state=*(s32*)(self+0x230);
  if (state==0 || state==3 || state==11 || *(u8*)(self+0x398)!=1) {
   if (*(s32*)(self+0x238)==0) {
    ++*(s32*)(self+0x234);
    *(s32*)(self+0x234) &= 3;
    fn_80371D50(self,*(s32*)(self+0x234));
   } else {
    k = 0;
    ((JGeometry::TVec3<f32>*)(self+0x294))->add(*(JGeometry::TVec3<f32>*)(self+0x2f4));
    ((JGeometry::TVec3<f32>*)(self+0x2a0))->add(*(JGeometry::TVec3<f32>*)(self+0x300));
    ((JGeometry::TVec3<f32>*)(self+0x2ac))->add(*(JGeometry::TVec3<f32>*)(self+0x30c));
    ((JGeometry::TVec3<f32>*)(self+0x2b8))->add(*(JGeometry::TVec3<f32>*)(self+0x318));
    if (*(s32*)(self+0x238)==0x76) {
     f32 zero = lbl_80542DC4;
     for (;k<4;k++) {
      *(JGeometry::TVec3<f32>*)(self+0x294+k*12)=*(JGeometry::TVec3<f32>*)(self+0x2c4+k*12);
      *(f32*)(self+0x2fc+k*12)=zero;
      *(f32*)(self+0x2f8+k*12)=zero;
      *(f32*)(self+0x2f4+k*12)=zero;
      fn_80458880(lbl_8053AF80,0x37,-1);
     }
    } else if (*(s32*)(self+0x238)<0x76) {
     *(u8*)(self+0x398)=1;
    }
   }
  }
 }
}

extern "C" void fn_801F06F0(void* this_, const char* name, s32 id, s32 a, s32 b, f32 s0, f32 s1);
extern "C" const char lbl_80474ED0[];
extern "C" const f32 lbl_80542E38;
extern "C" void* lbl_8053AAF8;
extern "C" void fn_80372400(char* self) {
    Vec saved;
    s32 i;
    char* vp;
    char* sp;
    s32* ids = (s32*)lbl_80474ED0;
    const char* tbl = lbl_80474ED0;

    if (*(u8*)((char*)lbl_8053AAF8 + 0x7e) == 0) {
        JGeometry::setTVec3f((f32*)(self + 0xc), (f32*)&saved);
        vp = self;
        sp = self;
        for (i = 0; i < 4; i++) {
            *(JGeometry::TVec3<f32>*)(self + 0xc) = *(JGeometry::TVec3<f32>*)(vp + 0x294);
            fn_801F06F0(self, tbl + 0x9c, *(s32*)(sp + 0x350) + ids[*(s32*)(self + 0x364)], 0, 7, lbl_80542E38, lbl_80542E38);
            vp += 0xc;
            sp += 4;
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

#pragma opt_lifetimes off
extern "C" void fn_8037251C(char* self)
{
    char* dst;
    char* tp;
    char* op;
    s32 i;
	if (*(s32*)(self + 0x238) != 0) {
		*(s32*)(self + 0x238) = *(s32*)(self + 0x238) - 1;
	}
	*(s32*)(self + 0x39c) = fn_8022EA0C(0);
	dst = self;
	for (i = 0; i < 4; i++) {
		*(JGeometry::TVec3<f32>*)(dst + 0x264) = *fn_8023E724(i);
		dst += 0xc;
	}
	if (*(u8*)((char*)lbl_8053AAF8 + 0x7e) != 0) {
		fn_8036FB60(self);
		return;
	}
	if (*(s32*)(self + 0x240) != 0) {
		*(s32*)(self + 0x240) = *(s32*)(self + 0x240) - 1;
	}
	if (*(s32*)(self + 0x3ac) != 0) {
		*(s32*)(self + 0x3ac) = *(s32*)(self + 0x3ac) - 1;
	}
	if (*(s32*)(self + 0x360) != 0) {
		*(s32*)(self + 0x360) = *(s32*)(self + 0x360) - 1;
	}
	if (*(s32*)(self + 0x360) == 0) {
		*(s32*)(self + 0x360) = 8;
		*(s32*)(self + 0x364) = *(s32*)(self + 0x364) + 1;
		if (*(s32*)(self + 0x364) >= 4) {
			*(s32*)(self + 0x364) = 0;
		}
	}
	if (*(s32*)(self + 0x36c) != 0) {
		*(s32*)(self + 0x36c) = *(s32*)(self + 0x36c) - 1;
	}
	if (*(s32*)(self + 0x36c) == 0) {
		if (*(s32*)(self + 0x368) == 0x108) {
			*(s32*)(self + 0x36c) = 0x10;
		} else {
			*(s32*)(self + 0x36c) = 0xa;
		}
		*(s32*)(self + 0x370) = *(s32*)(self + 0x370) ^ 1;
	}

	JGeometry::TBox2<f32> box;
	box.set(*(JGeometry::TBox2<f32>*)(self + 0x60));
	JGeometry::TBox2<f32> orig = box;
	tp = self;
	op = self;
	for (i = 0; i < 4; i++) {
		if (*(s32*)(tp + 0x330) != 0) {
			*(s32*)(tp + 0x330) = *(s32*)(tp + 0x330) - 1;
		}
		box.addPos(*(JGeometry::TVec2<f32>*)(op + 0x294));
		fn_80239914(&box, *(s32*)(self + 0x4), *(s32*)(self + 0x198));
		box = orig;
		tp += 4;
		op += 0xc;
	}
	box.addPos(*(JGeometry::TVec2<f32>*)(self + 0x324));
	fn_80239914(&box, *(s32*)(self + 0x4), *(s32*)(self + 0x198));
	box = orig;
	(((FSAObj*)self)->*((FSAStateUpdateFn*)lbl_804AE420)[*(s32*)(self + 0x230)])();
}
#pragma opt_lifetimes reset
extern "C" void fn_803727D0(char* self)
{
	struct VObj { virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09(); virtual void v10(); virtual u8 v11(); };
	if (*(u8*)((char*)lbl_8053AAF8 + 0x7e) != 0) {
		fn_8036FDAC(self);
		return;
	}
	*(s32*)(self + 0x238) = 0x50;
	if (!lbl_8053AD60) {
		((JGeometry::TVec3<f32>*)lbl_8050C840)[0] = JGeometry::TVec3<f32>(0.0f, 0.0f, 0.0f);
		((JGeometry::TVec3<f32>*)lbl_8050C840)[1] = JGeometry::TVec3<f32>(16.0f, 0.0f, 0.0f);
		((JGeometry::TVec3<f32>*)lbl_8050C840)[2] = JGeometry::TVec3<f32>(32.0f, 0.0f, 0.0f);
		((JGeometry::TVec3<f32>*)lbl_8050C840)[3] = JGeometry::TVec3<f32>(48.0f, 0.0f, 0.0f);
		lbl_8053AD60 = 1;
	}
	if (((VObj*)self)->v11()) {
		*(s32*)(self + 0x230) = 0xb;
	} else {
		*(s32*)(self + 0x230) = 0;
	}
	*(s32*)(self + 0x234) = 1;
	for (s32 i = 0; i < 4; i++) {
		*(JGeometry::TVec3<f32>*)(self + 0x2c4 + i * 0xc) = *(JGeometry::TVec3<f32>*)(self + 0xc) + ((JGeometry::TVec3<f32>*)lbl_8050C840)[i];
		*(JGeometry::TVec3<f32>*)(self + 0x294 + i * 0xc) = *(JGeometry::TVec3<f32>*)(self + 0x2c4 + i * 0xc);
		((JGeometry::TVec3<f32>*)(self + 0x2f4 + i * 0xc))->zero();
		*(s32*)(self + 0x350 + i * 4) = 0x38b;
		*(s32*)(self + 0x330 + i * 4) = 0;
		*(s32*)(self + 0x340 + i * 4) = 1;
	}
	*(JGeometry::TVec3<f32>*)(self + 0x3c) = *(JGeometry::TVec3<f32>*)(self + 0x2f4);
	*(s32*)(self + 0x360) = 8;
	*(s32*)(self + 0x364) = 0;
	*(JGeometry::TVec3<f32>*)(self + 0x324) = *(JGeometry::TVec3<f32>*)(self + 0x294);
	*(s32*)(self + 0x368) = 0x106;
	*(s32*)(self + 0x36c) = 0x10;
	*(s32*)(self + 0x370) = 0;
	*(s32*)(self + 0x394) = 0;
	*(u8*)(self + 0x398) = 1;
	*(u8*)(self + 0x399) = 0;
	*(f32*)(self + 0x60) = -8.0f;
	*(f32*)(self + 0x64) = -8.0f;
	*(f32*)(self + 0x68) = 8.0f;
	*(f32*)(self + 0x6c) = 8.0f;
	*(s32*)(self + 0x3a0) = -1;
	*(s32*)(self + 0x3a4) = 0;
	*(u8*)(self + 0x3a8) = 0;
	*(s32*)(self + 0x3ac) = 0;
	((JGeometry::TVec3<f32>*)(self + 0x244))->zero();
	((JGeometry::TVec3<f32>*)(self + 0x250))->zero();
	*(f32*)(self + 0x25c) = 0.0f;
	*(f32*)(self + 0x260) = 0.0f;
	for (s32 i = 0; i < 4; i++) {
		*(s32*)(self + 0x374 + i * 4) = 0;
		*(s32*)(self + 0x384 + i * 4) = 0;
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

extern "C" char lbl_804AE390[];
extern "C" char lbl_8050C840[];
extern "C" void __ct__17JASGenericMemPoolFv(void*);
extern "C" void __register_global_object(void*, void*, void*);
extern "C" char memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr[];
extern "C" void __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv(void*);
extern "C" char __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr;
extern "C" char memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack[];
extern "C" void __dt__35JASMemPool_MultiThreaded_8JASTrackFv(void*);
extern "C" char __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack;
extern "C" char memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel[];
extern "C" void __dt__38JASMemPool_MultiThreaded_10JASChannelFv(void*);
extern "C" char __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj3_FSA[];
extern "C" void __dt__29JASMemPool_15JASPoolObj3_FSAFv(void*);
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj4_FSA[];
extern "C" void __dt__29JASMemPool_15JASPoolObj4_FSAFv(void*);
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA;
extern "C" char memPool___30JASPoolAllocObject_9JAIStream[];
extern "C" void __dt__22JASMemPool_9JAIStreamFv(void*);
extern "C" char __init__memPool___30JASPoolAllocObject_9JAIStream;
extern "C" char memPool___35JASPoolAllocObject_13JAISoundChild[];
extern "C" void __dt__27JASMemPool_13JAISoundChildFv(void*);
extern "C" char __init__memPool___35JASPoolAllocObject_13JAISoundChild;
extern "C" char memPool___27JASPoolAllocObject_6JAISeq[];
extern "C" void __dt__19JASMemPool_6JAISeqFv(void*);
extern "C" char __init__memPool___27JASPoolAllocObject_6JAISeq;
extern "C" char memPool___26JASPoolAllocObject_5JAISe[];
extern "C" void __dt__18JASMemPool_5JAISeFv(void*);
extern "C" char __init__memPool___26JASPoolAllocObject_5JAISe;
extern "C" void fn_80372B00(void) {
	u32* src = (u32*)lbl_804AE390;
	u32* dst = (u32*)(lbl_804AE390 + 0x90);
	u32 tmp[11];
	dst[0] = src[0];
	dst[1] = src[1];
	dst[2] = src[2];
	dst[3] = src[3];
	dst[4] = src[4];
	dst[5] = src[5];
	dst[6] = src[6];
	dst[7] = src[7];
	dst[8] = src[8];
	dst[9] = src[9];
	dst[10] = src[10];
	dst[11] = src[11];
	dst[12] = src[12];
	dst[13] = src[13];
	dst[14] = src[14];
	dst[15] = src[15];
	dst[16] = src[16];
	dst[17] = src[17];
	dst[18] = src[18];
	dst[19] = src[19];
	dst[20] = src[20];
	dst[21] = src[21];
	dst[22] = src[22];
	dst[23] = src[23];
	dst[24] = src[24];
	for (int i = 0; i < 11; i++) {
		tmp[i] = src[25 + i];
		dst[25 + i] = tmp[i];
	}
	char* base = lbl_8050C840;
	if (__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr == 0) {
		__ct__17JASGenericMemPoolFv(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr);
		__register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr, __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, base + 0xc0);
		__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr = 1;
	}
	if (__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack == 0) {
		__ct__17JASGenericMemPoolFv(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack);
		__register_global_object(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack, __dt__35JASMemPool_MultiThreaded_8JASTrackFv, base + 0xcc);
		__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack = 1;
	}
	if (__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel == 0) {
		__ct__17JASGenericMemPoolFv(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel);
		__register_global_object(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel, __dt__38JASMemPool_MultiThreaded_10JASChannelFv, base + 0xd8);
		__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel = 1;
	}
	if (__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA == 0) {
		__ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA);
		__register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA, __dt__29JASMemPool_15JASPoolObj3_FSAFv, base + 0xe4);
		__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA = 1;
	}
	if (__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA == 0) {
		__ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA);
		__register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA, __dt__29JASMemPool_15JASPoolObj4_FSAFv, base + 0xf0);
		__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA = 1;
	}
	if (__init__memPool___30JASPoolAllocObject_9JAIStream == 0) {
		__ct__17JASGenericMemPoolFv(memPool___30JASPoolAllocObject_9JAIStream);
		__register_global_object(memPool___30JASPoolAllocObject_9JAIStream, __dt__22JASMemPool_9JAIStreamFv, base + 0xfc);
		__init__memPool___30JASPoolAllocObject_9JAIStream = 1;
	}
	if (__init__memPool___35JASPoolAllocObject_13JAISoundChild == 0) {
		__ct__17JASGenericMemPoolFv(memPool___35JASPoolAllocObject_13JAISoundChild);
		__register_global_object(memPool___35JASPoolAllocObject_13JAISoundChild, __dt__27JASMemPool_13JAISoundChildFv, base + 0x108);
		__init__memPool___35JASPoolAllocObject_13JAISoundChild = 1;
	}
	if (__init__memPool___27JASPoolAllocObject_6JAISeq == 0) {
		__ct__17JASGenericMemPoolFv(memPool___27JASPoolAllocObject_6JAISeq);
		__register_global_object(memPool___27JASPoolAllocObject_6JAISeq, __dt__19JASMemPool_6JAISeqFv, base + 0x114);
		__init__memPool___27JASPoolAllocObject_6JAISeq = 1;
	}
	if (__init__memPool___26JASPoolAllocObject_5JAISe == 0) {
		__ct__17JASGenericMemPoolFv(memPool___26JASPoolAllocObject_5JAISe);
		__register_global_object(memPool___26JASPoolAllocObject_5JAISe, __dt__18JASMemPool_5JAISeFv, base + 0x120);
		__init__memPool___26JASPoolAllocObject_5JAISe = 1;
	}
}

