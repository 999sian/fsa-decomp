#include "types.h"
#include "JSystem/JGeometry/Vec.h"
extern "C" f32 fn_801326B0(u16 n, void* t, f32 x = 0.0f);
extern "C" void fn_80130BC4(void* a, JGeometry::TVec3f* out);
extern "C" void fn_801D9F18(s32, s32);
extern "C" void fn_801DB8C4(s32, s32, s32);
extern f32 lbl_803016A8;
extern f32 lbl_803016AC;
extern f32 lbl_803016B8;
extern f32 lbl_803016C8;
extern "C" void* fn_8015A90C(s32 size);
extern "C" void* lbl_802FF310;
extern "C" void fn_8011F668(u8* p, void* buf, s16 w, s16 h);
extern "C" void fn_801DE4F4(s32, void*);
extern "C" void fn_8013F0A8(s32 idx, u8* out);
extern "C" void fn_801191F0(void*, s32);
extern "C" void fn_8012302C(void* p, s32 n);
extern "C" void fn_8011F878(void*, u8, u8, u8);
extern "C" void fn_80167A18(void* a, void* b, void* c, void* d);
struct NaviRGB8 { u8 r, g, b; };
#include "stdarg.h"
struct Vec3f { f32 x, y, z; };
class Unk80127A4CListener {
public:
    virtual void vf2();
    virtual void vf3();
    virtual void vf4(void* owner, void* item, void* arg);
};
class Unk801334ACObj {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual double vf5(double);
};
struct Unk801334AC {
    f32 val;
    u32 count;
    u32 pad;
    Unk801334ACObj* obj;
};
extern "C" void fn_801E4334(char* buf, u32 n, const void* fmt, va_list args);
extern "C" void fn_80123628(void* p, char* s);
extern "C" void fn_80123928(void* p, const void* fmt, va_list args);
extern "C" void* fn_8015A9A8(int, void*, int);
extern void* lbl_802FF544;
extern void* lbl_802FF360;
extern void* lbl_802FF348;
extern char lbl_80290AF4[];
extern "C" void* fn_80122E40(void* a, void* b, void* c, s32 d);
extern "C" void fn_80123B6C(void* a, void* b);
extern "C" void fn_80167A68(void* a, void* b);
extern "C" void* fn_80123EB8(void);
extern "C" void fn_80123EB0(void* p);
extern "C" void* fn_80123EA8(void);
extern "C" void fn_80123EA0(void* p);
extern "C" void fn_8015D0B8(void* p, int n);
extern "C" void* fn_80159BE0(u32 size, u32 align, void* p);
extern "C" int fn_80122FB0(int param_1, int param_2);
extern "C" u32 fn_80122FC0(u32 param_1, u32 param_2);
extern "C" void fn_80122FD0(void* p);
extern "C" void fn_80123AFC(void* p, void* q);
extern "C" void fn_8013AF98(void* a, void* b);
extern "C" void fn_80139DEC(void* a, void* b);
extern char lbl_80291450[];

extern "C" void fn_801DBA5C(s32 v, s32 n);
extern "C" void fn_80132450(s16 a, s16 b, s16 c, void* out);
extern "C" void fn_801C5DA8(void* a, void* b, void* c);
extern "C" void fn_801C6684(void* a, void* b, void* c);

extern s32 lbl_802FDDB0;
extern f32 lbl_80301788;
extern f32 lbl_80301694;
extern f32 lbl_80301698;
extern f32 lbl_80301794;
extern f64 lbl_80301778;
extern f32 lbl_802F0BC0[][2];
extern "C" void fn_80123EC0(void* a, ...);
extern "C" BOOL OSEnableInterrupts(void);
extern "C" BOOL OSRestoreInterrupts(BOOL level);
extern "C" void fn_8015AB1C(void* p);
extern "C" s32 fn_801C7C6C(void* a, void* b);
extern "C" void fn_801C7D34(void* p);
#include "dolphin/os/OSFastCast.h"
#include "dolphin/os/OSAlarm.h"
#include "dolphin/os/OSTime.h"
extern "C" void fn_8013A57C(void);
extern "C" void* fn_80139950(void*, void*, void*);
extern "C" void fn_801334AC(Unk801334AC* p, f32 scale);
extern "C" void fn_8013345C(f32*);
extern void* lbl_802925EC[];
extern void* lbl_80292558[];
struct Unk8012092C {
    void** vt;
    s32 m4;
    u16 m8;
    u16 mA;
    u8 padC[3];
    u8 mF;
    u8 pad10[0x10];
    s32 m20;
    s32 m24;
};
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8011f23c-0x80135cf8 (427 functions). split_file divides it into the game's real files.

extern void* lbl_80290ACC[];

extern void* lbl_80298574[];
extern "C" u8 fn_801268E4(void* a, void* b, void* c);
extern f32 lbl_803016CC;
extern "C" void fn_80130090(void** param_1, u8* param_2);
extern void* lbl_80298520[];
extern "C" void fn_80168E04(void* p);
extern "C" void fn_801688F0(void* p, u32* a, u32* b, u32* c, u32* d);
extern "C" void fn_80168A38(void* p, void* rect);

struct Color32 {
    u8 r, g, b, a;
};

struct Unk80168Base {
    void** vt;
    u8 pad[0xCC];
    ~Unk80168Base() { vt = lbl_80298520; }
};

struct Unk80168 : Unk80168Base {
    Unk80168() { fn_80168E04(this); }
    ~Unk80168() { vt = lbl_80298574; }
};

struct Unk80120880 {
    void** vt;
    s32 m4;
    u16 m8;
    u16 mA;
    u32 mC;
    f32 x0, y0, x1, y1;
    s32 m20;
    u32 m24;
};
extern "C" void* lbl_802FF364;
extern "C" void* lbl_802FF368;
extern "C" void* lbl_802FF370;
extern "C" void* fn_801328F8(void* ptr, s16 param_2);
extern char lbl_802911E4[];


static inline void fn_80133624_set(u8* self, int i, f32 v) {
    u8* e = *(u8**)(self + 4) + i * 0x14;
    *(void**)(e + 8) = (void*)fn_8013345C;
    *(u32*)(e + 4) = 0;
    *(f32*)(e + 0xC) = v;
}

class Unk80133A44Listener {
public:
    virtual void vf2();
    virtual void vf3();
    virtual void vf4(void* owner);
    virtual void vf5(void* owner);
};
class Unk8012B8B4Listener {
public:
    virtual void vf2();
    virtual void vf3();
    virtual void vf4(void* owner, void* arg);
};
extern const f32 lbl_803016E0;
extern const f32 lbl_803016E4;
extern const f32 lbl_803017B0;
extern "C" void fn_8012C274(void*);
extern "C" void fn_8015AB1C(void* ptr);
extern u8 lbl_802FF334;
extern f32 lbl_802FEAB4;
extern "C" void fn_80166C08(void*, int);
extern "C" void fn_80166FC4(void* a, void* b);
extern "C" void fn_80166C84(void* a, void* b);
extern "C" void fn_80130404(void* a, void* b, s32 c);
class Unk80133ABCList {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6(void* owner, u32 n);
};
class Unk80133ABCObj {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2(void* list, f32 v);
};
struct Unk80133ABCElem {
    f32 m0;
    s32 m4;
    void (*m8)(void* elem, f32 v);
    Unk80133ABCObj* m10;
    f32 mC;
};
struct Unk80133ABCArr {
    Unk80133ABCList* m0;
    Unk80133ABCElem* m4;
    s32 m8;
};
class Unk80133ABCCb {
public:
    virtual void vf0(void* list, f32 v);
};
struct Unk80133ABCItem {
    f32 m0;
    s32 m4;
    void (*m8)(void* elem, f64 v);
    f32 mC;
    Unk80133ABCCb* m10;
};
class Unk80133ABCMgr {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4(void* owner, u32 n);
    Unk80133ABCItem* m4;
    s32 m8;
};
extern "C" void* fn_8011F23C(void* param_1, s16 param_2) {
    if (param_1) {
        fn_80166C08(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void* fn_8011F290(void)
{
	u8* iVar1 = (u8*)lbl_802FF310;
	if (iVar1 == 0) {
		iVar1 = (u8*)fn_8015A90C(0x2c);
		if (iVar1 != 0) {
			*(s32*)(iVar1 + 0x18) = -1;
			fn_8011F668(iVar1, 0, 0, 0);
			fn_8011F878(iVar1, 0xff, 0xff, 0xff);
		}
		lbl_802FF310 = iVar1;
	}
	return lbl_802FF310;
}

extern "C" void fn_8011F304(u8* p, s32 x, s32 y, s32 w, s32 h) {
    s32 row = 0;
    s32 i;
    s32 temp_r5;
    u32 ctr;
    s16* dst;

    if (*(u32*)p == 0) {
        return;
    }
    if (*(u16*)(p + 4) > 0x190) {
        x *= 2;
        w *= 2;
    }
    if (*(u16*)(p + 6) > 0x12C) {
        y *= 2;
        h *= 2;
    }
    dst = (s16*)(*(u8**)(p + 0x14) + (*(u16*)(p + 8) * y * 2 + x * 2));
    for (row = 0; row < h; row++) {
        i = 0;
        if (w > 0) {
            temp_r5 = w - 8;
            if (w > 8) {
                ctr = (u32)(temp_r5 + 7) >> 3;
                if (temp_r5 > 0) {
                    do {
                        dst[0] = 0x1080;
                        i += 8;
                        dst[1] = 0x1080;
                        dst[2] = 0x1080;
                        dst[3] = 0x1080;
                        dst[4] = 0x1080;
                        dst[5] = 0x1080;
                        dst[6] = 0x1080;
                        dst[7] = 0x1080;
                        dst += 8;
                    } while (--ctr != 0);
                }
            }
            if (i < w) {
                ctr = w - i;
                do {
                    *dst++ = 0x1080;
                    i++;
                } while (--ctr != 0);
            }
        }
        dst += *(u16*)(p + 8) - w;
    }
}

extern "C" void fn_8011F668(u8* p, void* buf, s16 w, s16 h)
{
    *(void**)(p + 0x0) = buf;
    *(void**)(p + 0x14) = buf;
    *(s16*)(p + 0x4) = w;
    *(s16*)(p + 0x6) = h;
    *(u16*)(p + 0x8) = (u16)(((u16)w + 0xf) & 0xfff0);
    *(u32*)(p + 0xc) = *(u16*)(p + 0x8) * *(u16*)(p + 0x6) * 2;
}

extern u8 lbl_802FDD78[8];
extern "C" void fn_8011F6CC(void* a, void* b, void* c, void* d, void* e, ...);
#pragma dont_inline on
extern "C" void fn_8011F6A0(void* a, void* b, void* c, void* e) {
    fn_8011F6CC(a, b, c, lbl_802FDD78, e);
}

extern "C" void fn_8011F848(void* p, NaviRGB8* c) {
    fn_8011F878(p, c->r, c->g, c->b);
}
#pragma dont_inline reset

extern "C" void fn_8011FA0C(void)
{
}

#pragma dont_inline on
extern "C" void fn_8011FA10(void) {
    extern u32 lbl_802FF318;
    extern u8 lbl_802FDD88;
    extern char lbl_802C6448[];
    extern char lbl_802C6488[];
    extern void* lbl_802FF310;
    u32 v;
    if (lbl_802FF318 == 0) {
        v = 0;
    } else {
        if (lbl_802FF318 + 0x10000 != 0xffff) {
            lbl_802FF318--;
        }
        v = lbl_802FF318;
        if (v < 5) {
            v = 0;
        }
    }
    if (v != 0 && lbl_802FDD88 == 1) {
        u8* p = (u8*)lbl_802FF310;
        volatile u32 t;
        u32 cw;
        Color32 c;
        u32 tw;
        t = *(u32*)(p + 0x18);
        c.r = 0xff;
        c.g = 0xc8;
        c.b = 0xc8;
        c.a = 0xff;
        cw = *(u32*)&c;
        fn_8011F848(p, (NaviRGB8*)&cw);
        fn_8011F6A0(p, (void*)0x10, (void*)0x10, lbl_802C6448);
        fn_8011F6A0(p, (void*)0x10, (void*)0x18, lbl_802C6488);
        tw = t;
        fn_8011F848(p, (NaviRGB8*)&tw);
    }
}
#pragma dont_inline reset
extern "C" void* lbl_802FDD84;
extern "C" void* fn_8011FD10(void)
{
	return lbl_802FDD84;
}

extern void* lbl_802FDD84;
extern u8 lbl_802FDD88;
extern void* lbl_802FF328;
extern void* lbl_80290AB4[];
extern "C" void* fn_8015A90C(s32 size);
extern void fn_8015AB1C(void* ptr);
extern "C" void* fn_80120138(void* ptr, void* param);
extern "C" void* fn_801CB248(void* ptr);
extern "C" void* fn_801CB28C(void* ptr);
extern "C" void fn_801CC8B4(s32 a);
extern "C" void fn_801CC710(void);
extern "C" void fn_801DB70C(void* a);
extern "C" void fn_801BDDBC(void* p, void* data, s32 count);
extern "C" u32 fn_801CC930(void);
typedef void (*VirtualMethod0)(void*, s16);
extern "C" void fn_80120090(u8 param_1) {
    lbl_802FDD88 = param_1;
}

extern "C" void* fn_80120098(void* param_1)
{
	void* allocated = lbl_802FF328;
	if (allocated == 0) {
		allocated = fn_8015A90C(0x58);
		if (allocated != 0) {
			allocated = fn_80120138(allocated, param_1);
		}
	}
	lbl_802FF328 = allocated;
	return *(void**)&lbl_802FF328;
}

extern "C" void fn_801200F0(void)
{
	void* obj = lbl_802FF328;
	if (obj != 0) {
		VirtualMethod0 vf = (VirtualMethod0)(*((void**)(*((void***)obj)) + 2));
		vf(obj, 1);
		lbl_802FF328 = 0;
	}
}

extern "C" void fn_801CB570(void* a, void* b);
extern "C" void fn_801205C4(u8* param_1, s32* param_2);
extern "C" void fn_801204F0(void);
extern "C" void fn_80120578(void* arg);
extern "C" void fn_80120294(void* a);
extern s32 lbl_802FF32C;
extern s32 lbl_802FF330;
extern "C" void* fn_80120138(void* ptr, void* param) {
    u8* self = (u8*)ptr;
    *(void**)self = (void*)lbl_80290AB4;
    *(s32*)(self + 4) = 0;
    fn_801CB570(*(void**)self, param);
    fn_801205C4(self, (s32*)param);
    self[0x2c] = 1;
    *(s32*)(self + 0x30) = 2;
    fn_801CC8B4(1);
    fn_801CC710();
    *(s32*)(self + 8) = 0;
    *(u32*)(self + 0xc) = fn_801CC930();
    *(s32*)(self + 0x10) = 1;
    *(s32*)(self + 0x18) = 0;
    lbl_802FF32C = OSGetTick();
    lbl_802FF330 = 0xA3930;
    *(void**)(self + 0x1c) = fn_801CB248(fn_80120294);
    *(void**)(self + 0x20) = fn_801CB28C(fn_80120578);
    *(s32*)(self + 0x24) = 0;
    *(s32*)(self + 0x28) = 0;
    fn_801BDDBC(self + 0x38, self + 0x34, 1);
    fn_801DB70C((void*)fn_801204F0);
    return self;
}

extern "C" void* fn_8012022C(void* param_1, s16 param_2) {
    if (param_1 != 0) {
        *(void**)param_1 = lbl_80290AB4;
        fn_801CB248(*(void**)((u8*)param_1 + 0x1c));
        fn_801CB28C(*(void**)((u8*)param_1 + 0x20));
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_801DB3E0(void);
extern "C" void fn_801204BC(void) {
    lbl_802FF334 = 1;
    fn_801DB3E0();
}

extern "C" void fn_801204E4(void) {
    lbl_802FF334 = 0;
}

extern "C" void fn_801CC840(void*);
extern "C" void fn_801CC710(void);
extern u8* lbl_802FF340;
extern "C" void fn_801204F0(void) {
    u8* p = lbl_802FF340;
    if (p != NULL) {
        lbl_802FF334 = 0;
        if (*(s32*)(p + 0x10) == 1 && *(s32*)(p + 0x1c) == 1) {
            *(s32*)(p + 0x1c) = 0;
            if ((*(s16*)(p + 0x16) >= 0 ? ((void**)p)[*(s16*)(p + 0x16)] : NULL) != NULL) {
                fn_801CC840(*(s16*)(p + 0x16) >= 0 ? ((void**)p)[*(s16*)(p + 0x16)] : NULL);
                fn_801CC710();
            }
        }
    }
}

extern "C" u32 fn_801CC930(void);
extern "C" void fn_801BDE1C(void* p, u32 a, u32 b);
extern "C" void fn_80120578(void* arg)
{
    void (*cb)(void*) = *(void (**)(void*))((u8*)lbl_802FF328 + 0x28);
    if (cb != 0) {
        cb(arg);
    }
    fn_801BDE1C((u8*)lbl_802FF328 + 0x38, fn_801CC930(), 0);
}

extern "C" void fn_801CBEE8(s32* p);
extern "C" void fn_801CBA20(void);
extern "C" void fn_801205C4(u8* param_1, s32* param_2)
{
    s32* cur = *(s32**)(param_1 + 4);
    if (cur != 0 && *param_2 != *cur) {
        *(u8*)(param_1 + 0x2c) = 1;
        *(s32*)(param_1 + 0x30) = 4;
    }
    *(s32**)(param_1 + 4) = param_2;
    fn_801CBEE8(*(s32**)(param_1 + 4));
    fn_801CC710();
    if (*(u8*)(param_1 + 0x2c) != 0) {
        fn_801CBA20();
        fn_801CBA20();
    }
}

extern "C" void fn_8012063C(void)
{
}

extern "C" void fn_80120640(void* self) {
    *(s16*)((u8*)self + 0x14) = -1;
    *(s16*)((u8*)self + 0x16) = -1;
    *(s16*)((u8*)self + 0x18) = -1;
}

extern "C" void fn_801DBEE8(u16, u16);
extern "C" void* fn_801DBE58(u16);
extern "C" void fn_80120794(void*, u16, void*, void*, void*);
#pragma push
#pragma use_lmw_stmw off
extern "C" u8* fn_80120654(void* param_1, void* param_2) {
    if (lbl_802FF340 == 0) {
        u8* obj = (u8*)fn_8015A90C(0x20);
        if (obj != 0) {
            *(void**)(obj + 0x10) = param_2;
            *(s16*)(obj + 0x14) = -1;
            *(s16*)(obj + 0x16) = -1;
            *(s16*)(obj + 0x18) = -1;
            *(s32*)(obj + 0x1c) = 99;
            u8* p = *(u8**)((u8*)lbl_802FF328 + 4);
            u16 a = *(u16*)(p + 6);
            u16 b = *(u16*)(p + 4);
            fn_801DBEE8(a, *(u16*)(p + 8));
            fn_80120794(obj, b, fn_801DBE58(a), param_1, param_2);
        }
        lbl_802FF340 = obj;
    }
    return lbl_802FF340;
}

extern "C" void fn_80120704(void) {
    s32 i;
    void** p;
    u8* obj;
    if ((obj = lbl_802FF340) != 0) {
        for (i = 0, p = (void**)obj; i < 3; i++) {
            if (obj[i + 0xc] != 0 && *p != 0) {
                fn_8015AB1C(*p);
            }
            p++;
        }
        lbl_802FF340 = 0;
        fn_8015AB1C(obj);
    }
    lbl_802FF340 = 0;
}

extern "C" void fn_80120880(Unk80120880* p, s32 x, s32 y, s32 w, s32 h, u32* q) {
    s32 r = x + w;
    s32 b = y + h;
    p->vt = lbl_80290ACC;
    p->mC = *q;
    p->x0 = x;
    p->y0 = y;
    p->x1 = r;
    p->y1 = b;
    p->m4 = 0;
    p->m8 = 0;
    p->mA = 0;
    p->m24 = 0;
    p->m20 = -1;
}

extern "C" void fn_8012092C(Unk8012092C* p) {
    s32 n = p->m20;
    if (n >= 0) {
        p->m20 = n - 1;
        if (n == 0) {
            p->m4 = p->m24;
        }
    }
    switch (p->m4) {
    case 1:
        break;
    case 2: {
        u16 t = p->mA + 1;
        p->mA = t;
        p->mF = (u8)(0xFF - ((s32)(t * 0xFF) / (s32)p->m8));
        if ((u16)p->mA >= (u16)p->m8) {
            p->m4 = 1;
        }
        goto call;
    }
    case 0:
        p->mF = 0xFF;
    default:
        goto call;
    case 3: {
        u16 t = p->mA + 1;
        p->mA = t;
        p->mF = (u8)((s32)(t * 0xFF) / (s32)p->m8);
        if ((u16)p->mA >= (u16)p->m8) {
            p->m4 = 0;
        }
        goto call;
    }
    }
    return;
call:
    void (*fn)(void*) = (void (*)(void*))p->vt[5];
    fn(p);
}

extern "C" void fn_80120A2C(u8* p) {
    if (*(u8*)(p + 0xf) != 0) {
        Unk80168 obj;
        Color32 col = *(Color32*)(p + 0xc);
        Color32 d = col;
        Color32 c = col;
        Color32 b = col;
        Color32 a = col;
        fn_801688F0(&obj, (u32*)&a, (u32*)&b, (u32*)&c, (u32*)&d);
        fn_80168A38(&obj, p + 0x10);
    }
}

extern "C" bool fn_80120ABC(u8* p, u16 v) {
    bool r = *(s32*)(p + 4) == 0;
    if (r) {
        *(s32*)(p + 4) = 2;
        *(u16*)(p + 0xa) = 0;
        *(u16*)(p + 0x8) = v;
    }
    return r;
}

extern "C" bool fn_80120AEC(u8* p, u16 v) {
    bool r = *(s32*)(p + 4) == 1;
    if (r) {
        *(s32*)(p + 4) = 3;
        *(u16*)(p + 0xa) = 0;
        *(u16*)(p + 0x8) = v;
    }
    return r;
}

#pragma pop
extern "C" void* fn_80120B20(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80290ACC;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_80120C98(void) {
    void* p = lbl_802FF348;
    if (p != NULL && p != NULL) {
        lbl_802FF348 = NULL;
        fn_8015AB1C(p);
    }
    lbl_802FF348 = NULL;
}

extern f32 lbl_802FDDA8;
extern f32 lbl_802FDDAC;
extern f32 lbl_803015F0;
extern f32 lbl_803015F4;
extern "C" void fn_80120CD8(void) {
    u8* obj = (u8*)lbl_802FF348;
    obj[0x10] = 0xFF;
    obj[0x11] = 0x81;
    obj[0x12] = 0x1E;
    *(OSTick*)obj = OSGetTick();
    obj = (u8*)lbl_802FF348;
    obj[0x38] = 0xFF;
    obj[0x39] = 0x81;
    obj[0x3A] = 0x1E;
    *(OSTick*)(obj + 0x28) = OSGetTick();
    obj = (u8*)lbl_802FF348;
    obj[0x24] = 0xFF;
    obj[0x25] = 0x81;
    obj[0x26] = 0x1E;
    *(OSTick*)(obj + 0x14) = OSGetTick();
    obj = (u8*)lbl_802FF348;
    obj[0x60] = 0xFF;
    obj[0x61] = 0x81;
    obj[0x62] = 0x1E;
    *(OSTick*)(obj + 0x50) = OSGetTick();
    f32 a = lbl_803015F0;
    *(u32*)((u8*)lbl_802FF348 + 0x104) = 0;
    f32 b = lbl_803015F4;
    lbl_802FDDA8 = a;
    lbl_802FDDAC = b;
}

extern "C" void fn_80120DDC(void);
extern "C" void fn_801225F8(u8* p);
extern "C" void fn_80120DA8(u8* p) {
    fn_80120DDC();
    fn_801225F8(p);
}

extern "C" void fn_80122D04(void* param_1) {
    *(u32*)((u8*)param_1 + 4) = 0;
    *(u32*)((u8*)param_1 + 8) = 0;
    *(u32*)((u8*)param_1 + 0xc) = 0;
}

#pragma push
#pragma use_lmw_stmw off
extern "C" void* fn_80122D18(void* a, void* b, void* c) {
    void* r;
    void* p = lbl_802FF360;
    void* q = fn_80159BE0(fn_80122FB0((s32)a, (s32)b), 0, c);
    r = q;
    if (r != NULL) {
        r = fn_80122E40(q, a, b, 1);
    }
    *(u8**)((u8*)r + 0x28) = (u8*)q + 0x6c;
    fn_80122FD0(r);
    fn_80123AFC(p, r);
    return r;
}
#pragma pop
extern "C" void* fn_80122DA8(void* a, void* b, void* c) {
    void* r;
    void* p = lbl_802FF360;
    void* q = (void*)fn_80122FC0((u32)c, (u32)a);
    r = b;
    if (b != NULL) {
        r = fn_80122E40(b, a, q, 0);
    }
    *(u8**)((u8*)r + 0x28) = (u8*)b + 0x6c;
    fn_80122FD0(r);
    fn_80123AFC(p, r);
    return r;
}

extern "C" void* fn_80122F40(void* p, s16 n) {
    if (p != NULL) {
        *(void**)p = lbl_80290AF4;
        fn_80123B6C(lbl_802FF360, p);
        fn_8015D0B8(p, 0);
        if (n > 0) {
            fn_8015AB1C(p);
        }
    }
    return p;
}

extern "C" int fn_80122FB0(int param_1, int param_2)
{
	return (param_1 + 2) * param_2 + 0x6c;
}

extern "C" u32 fn_80122FC0(u32 param_1, u32 param_2)
{
	return (param_1 - 0x6c) / (param_2 + 2);
}

extern "C" void fn_80122FD0(void* p) {
    u32 i;
    *(u32*)((u8*)p + 0x30) = 0;
    *(u32*)((u8*)p + 0x34) = 0;
    *(u32*)((u8*)p + 0x38) = 0;
    *(u32*)((u8*)p + 0x3c) = 0;
    for (i = 0; i < *(u32*)((u8*)p + 0x24); i++) {
        *(u8*)(*(u8**)((u8*)p + 0x28) + (*(s32*)((u8*)p + 0x20) + 2) * i) = 0;
    }
    *(*(u8**)((u8*)p + 0x28)) = 0xff;
    *(*(u8**)((u8*)p + 0x28) + 1) = 0;
}

extern "C" void fn_8012359C(void* p, const void* fmt, ...) {
    va_list args;
    va_start(args, fmt);
    fn_80123928(p, fmt, args);
}

extern "C" void fn_80123928(void* p, const void* fmt, va_list args) {
    char buf[0x400];
    fn_801E4334(buf, 0x400, fmt, args);
    fn_80123628(p, buf);
}

extern "C" void fn_80123970(u8* p, s32 n)
{
    s32 d;
    s32 s;
    s32 cnt;
    if (n < 0) {
        d = *(s32*)(p + 0x30) - *(s32*)(p + 0x34);
        if (d < 0) {
            d += *(s32*)(p + 0x24);
        }
        if (n < -d) {
            n = -d;
        }
    } else if (n > 0) {
        s = *(s32*)(p + 0x38) - *(s32*)(p + 0x34);
        if (s < 0) {
            s += *(s32*)(p + 0x24);
        }
        cnt = *(s32*)(p + 0x48);
        if ((u32)(s + 1) <= (u32)cnt) {
            n = 0;
        } else {
            d = *(s32*)(p + 0x38) - *(s32*)(p + 0x30);
            if (d < 0) {
                d += *(s32*)(p + 0x24);
            }
            d = d - cnt + 1;
            if (n > d) {
                n = d;
            }
        }
    }
    *(s32*)(p + 0x30) += n;
    if (*(s32*)(p + 0x30) < 0) {
        *(s32*)(p + 0x30) += *(s32*)(p + 0x24);
    }
    if ((u32)*(s32*)(p + 0x30) >= (u32)*(s32*)(p + 0x24)) {
        *(s32*)(p + 0x30) -= *(s32*)(p + 0x24);
    }
}

extern "C" s32 fn_80123A4C(u8* p) {
    s32 n = *(s32*)(p + 0x38) - *(s32*)(p + 0x34);
    if (n >= 0) {
        return n;
    }
    return n + *(s32*)(p + 0x24);
}

extern "C" s32 fn_80123A70(u8* p) {
    s32 n = *(s32*)(p + 0x30) - *(s32*)(p + 0x34);
    if (n >= 0) {
        return n;
    }
    return n + *(s32*)(p + 0x24);
}

extern "C" void fn_80123A94(void* heap) {
    u32* p;
    u32* q;
    if (heap == 0) {
        heap = lbl_802FF544;
    }
    p = (u32*)fn_8015A9A8(0x14, heap, 0);
    if (p != 0) {
        q = (u32*)((u8*)p + 4);
        p[1] = 0;
        p[2] = 0;
        p[0] = 0;
        p[1] = (u32)q;
        p[2] = (u32)q;
        p[3] = 0;
        p[4] = 0;
    }
    lbl_802FF360 = p;
}

extern "C" void fn_80123AFC(void* p, void* q) {
    void* arr[6];
    void* t = (u8*)p + 4;
    arr[1] = t;
    arr[0] = t;
    arr[5] = t;
    arr[4] = t;
    arr[3] = t;
    fn_80167A18(&arr[2], p, &arr[3], (u8*)q + 0x18);
    if (*(void**)((u8*)p + 0xc) == NULL) {
        *(void**)((u8*)p + 0xc) = q;
    }
}

void fn_80123B6C(void* arg0, void* arg1) {
    u32* self = (u32*)arg0;
    if (self[3] == (u32)arg1) {
        if (self[0] <= 1) {
            self[3] = 0;
        } else {
            void* volatile sp14 = (u8*)arg0 + 4;
            void* volatile sp10 = (u8*)arg0 + 4;
            u32 next;
            if ((u32)arg1 != self[2] - 0x18) {
                next = ((u32*)arg1)[6] - 0x18;
            } else {
                void* volatile sp0C = (void*)self[1];
                void* volatile sp08 = (void*)self[1];
                next = self[1] - 0x18;
            }
            self[3] = next;
        }
    }
    if ((u32)fn_80123EB8() == (u32)arg1) {
        fn_80123EB0(0);
    }
    if ((u32)fn_80123EA8() == (u32)arg1) {
        fn_80123EA0(0);
    }
    fn_80167A68(arg0, (u8*)arg1 + 0x18);
}

extern "C" void fn_80123C34(u8* p) {
    u32 owner = *(u32*)(p + 0xC);
    u8* node = *(u8**)(p + 4);
    u8* end = p + 4;
    while (node != end) {
        if ((u32)(node - 0x18) != owner) {
            fn_8012302C(node - 0x18, 1);
        }
        *(u8**)&node = *(u8**)node;
    }
    if (*(u32*)(p + 0xC) != 0) {
        fn_8012302C((void*)*(u32*)(p + 0xC), 0);
    }
}

extern "C" void fn_80123D00(u8* p, u8 flag) {
    if (*(void**)(p + 0x10) != 0) {
        if (flag != 0) {
            BOOL state = OSEnableInterrupts();
            u32 a = fn_801CC930();
            u32 b = fn_801CC930();
            if (a != b) {
                OSRestoreInterrupts(state);
            }
        }
        fn_8012302C(*(void**)(p + 0x10), 2);
    }
}

extern "C" void fn_80123EA0(void* p)
{
	lbl_802FF364 = p;
}

extern "C" void* fn_80123EA8(void)
{
	return lbl_802FF364;
}

extern "C" void fn_80123EB0(void* p)
{
	lbl_802FF368 = p;
}

extern "C" void* fn_80123EB8(void)
{
	return lbl_802FF368;
}

extern "C" void fn_80123EC0(void* a, ...) {
    char buf[0x100];
    va_list args;
    va_start(args, a);
    if (lbl_802FF364 == NULL) {
        fn_801E4334(buf, 0x100, a, args);
    } else if (*(u32*)((u8*)lbl_802FF364 + 0x58) & 3) {
        fn_801E4334(buf, 0x100, a, args);
        fn_80123628(lbl_802FF364, buf);
    }
}

extern "C" void fn_80123F9C(void* p) {
    fn_80123EC0((void*)&lbl_802FDDB0, p);
}

extern "C" void fn_80123FC8(const void* fmt, va_list args) {
    char buf[256];
    if (lbl_802FF368 == 0) {
        fn_801E4334(buf, 0x100, fmt, args);
    } else if (*(u32*)((u8*)lbl_802FF368 + 0x58) & 3) {
        fn_801E4334(buf, 0x100, fmt, args);
        fn_80123628(lbl_802FF368, buf);
    }
}

extern "C" void fn_80124034(void* a, ...);
extern "C" void fn_80124034(void* a, ...) {
    char buf[0x100];
    va_list args;
    va_start(args, a);
    if (lbl_802FF364 == NULL) {
        fn_801E4334(buf, 0x100, a, args);
    } else if (*(u32*)((u8*)lbl_802FF364 + 0x58) & 3) {
        fn_801E4334(buf, 0x100, a, args);
        fn_80123628(lbl_802FF364, buf);
    }
}

extern "C" void fn_80124110(void* p) {
    fn_80123EC0((void*)&lbl_802FDDB0, p);
}

extern "C" void fn_8012413C(void* p) {
    u8* c = (u8*)p;
    *(s32*)(c + 0x828) = 0;
    *(s32*)(c + 0x82c) = 0;
    *(s32*)(c + 0x824) = 0;
    *(u32*)(c + 0x820) = ((u32)c + 0x1f) & ~0x1f;
    *(u8*)(c + 0x830) = 0;
}

extern "C" void* fn_80124160(void* p, s16 n) {
    u8* c = (u8*)p;
    if (c != NULL) {
        c[0x830] = 0;
        if (n > 0) {
            fn_8015AB1C(p);
        }
    }
    return p;
}

extern "C" BOOL fn_801241A4(void* p, void* arg) {
    u8* c = (u8*)p;
    BOOL state;
    BOOL ok;
    if (arg == NULL) {
        return 0;
    }
    state = OSEnableInterrupts();
    ok = fn_801C7C6C(arg, c + 0x834);
    OSRestoreInterrupts(state);
    if (ok == 0) {
        c[0x830] = 0;
        return 0;
    }
    state = OSEnableInterrupts();
    *(s32*)(c + 0x828) = *(s32*)(c + 0x868);
    OSRestoreInterrupts(state);
    *(s32*)(c + 0x82c) = 0;
    c[0x830] = 1;
    return 1;
}

extern "C" void fn_8012424C(void* p) {
    u8* c = (u8*)p;
    if (c[0x830] != 0) {
        BOOL state = OSEnableInterrupts();
        fn_801C7D34(c + 0x834);
        OSRestoreInterrupts(state);
        c[0x830] = 0;
    }
}

extern "C" void fn_80124674(void* self, s32 idx, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f) {
    u8* p = (u8*)lbl_802FF370 + idx * 0x5c + 0x4c60;
    *(u32*)(p + 0x2c) = c;
    *(u32*)(p + 0x30) = d;
    *(u32*)(p + 0x34) = a;
    *(u32*)(p + 0x38) = b;
    *(u32*)(p + 0x4c) = e;
    *(u32*)(p + 0x50) = f;
    *(u8*)(p + 0x3c) = 0;
    fn_801BDE1C(p, 1, 1);
}

extern "C" s32 fn_801246CC(void* self, s32 idx, u8* out) {
    u8* p = (u8*)lbl_802FF370 + idx * 0x5c + 0x4c60;
    if (*(u32*)(p + 0x24) != 1) {
        return -1;
    }
    if (*(u8*)(p + 0x3c) == 0) {
        if (*(s32*)(p + 0x40) == 1) {
            if (out != 0) {
                *out = 0xff;
            }
        } else if (out != 0) {
            fn_8013F0A8(idx, out);
        }
        return -2;
    } else {
        if (*(s32*)(p + 0x40) == 0) {
            if (out != 0) {
                *out = 100;
            }
        } else if (out != 0) {
            *out = 0;
        }
        return *(s32*)(p + 0x40);
    }
}

extern "C" void fn_80124788(void* self, s32 idx, u32 a, u32 b) {
    u8* e = (u8*)lbl_802FF370 + idx * 0x5c + 0x4c60;
    *(u32*)(e + 0x4c) = a;
    *(u32*)(e + 0x50) = b;
    *(u8*)(e + 0x3c) = 0;
    fn_801BDE1C(e, 2, 1);
}

extern "C" s32 fn_801247D0(void* self, s32 idx, s32* out) {
    u8* e = (u8*)lbl_802FF370 + idx * 0x5c + 0x4c60;
    if (*(u32*)(e + 0x24) != 2) {
        return -1;
    }
    if (e[0x3c] != 1) {
        *out = 0;
        return -2;
    }
    *out = *(s32*)(e + 0x40);
    return 0;
}

extern "C" void fn_80124820(void* self, s32 idx, u32 a, u32 b) {
    u8* e = (u8*)lbl_802FF370 + idx * 0x5c + 0x4c60;
    *(u32*)(e + 0x4c) = a;
    *(u32*)(e + 0x50) = b;
    *(u8*)(e + 0x3c) = 0;
    fn_801BDE1C(e, 3, 1);
}

extern "C" s32 fn_80124868(void* self, s32 idx, s32* out) {
    u8* e = (u8*)lbl_802FF370 + idx * 0x5c + 0x4c60;
    if (*(u32*)(e + 0x24) != 3) {
        return -1;
    }
    if (e[0x3c] != 1) {
        *out = 0;
        return -2;
    }
    *out = *(s32*)(e + 0x40);
    return 0;
}

extern "C" void fn_801248B8(void* self, s32 idx, u32 a, u32 b) {
    u8* e = (u8*)lbl_802FF370 + idx * 0x5c + 0x4c60;
    *(u32*)(e + 0x4c) = a;
    *(u32*)(e + 0x50) = b;
    *(u8*)(e + 0x3c) = 0;
    fn_801BDE1C(e, 4, 1);
}

extern "C" s32 fn_80124900(void* a, s32 idx, u8* out) {
    u8* e = (u8*)lbl_802FF370 + idx * 0x5c + 0x4c60;
    if (*(u32*)(e + 0x24) != 4) {
        return -1;
    }
    if (e[0x3c] != 1) {
        return -2;
    }
    if (*(s32*)(e + 0x40) == 0 && out != NULL) {
        *out = e[0x44];
    }
    return *(s32*)(e + 0x40);
}

extern "C" void fn_8012495C(void* self, s32 idx, u32 c, u32 a, u32 b) {
    u8* e = (u8*)lbl_802FF370 + idx * 0x5c + 0x4c60;
    *(u32*)(e + 0x4c) = a;
    *(u32*)(e + 0x50) = b;
    *(u8*)(e + 0x3c) = 0;
    *(u32*)(e + 0x48) = c;
    fn_801BDE1C(e, 5, 1);
}

extern "C" s32 fn_801249A8(void* a, s32 idx, u8* out) {
    u8* e = (u8*)lbl_802FF370 + idx * 0x5c + 0x4c60;
    if (*(u32*)(e + 0x24) != 5) {
        return -1;
    }
    if (e[0x3c] != 1) {
        return -2;
    }
    if (*(s32*)(e + 0x40) == 0 && out != NULL) {
        *out = e[0x44];
    }
    return *(s32*)(e + 0x40);
}

extern "C" void fn_80124A04(void* self, s32 idx, u32 c, u32 a, u32 b) {
    u8* e = (u8*)lbl_802FF370 + idx * 0x5c + 0x4c60;
    *(u32*)(e + 0x4c) = a;
    *(u32*)(e + 0x50) = b;
    *(u8*)(e + 0x3c) = 0;
    *(u32*)(e + 0x48) = c;
    fn_801BDE1C(e, 6, 1);
}

extern "C" s32 fn_80124A50(void* a, s32 idx, u8* out) {
    u8* e = (u8*)lbl_802FF370 + idx * 0x5c + 0x4c60;
    if (*(u32*)(e + 0x24) != 6) {
        return -1;
    }
    if (e[0x3c] != 1) {
        return -2;
    }
    if (*(s32*)(e + 0x40) == 0 && out != NULL) {
        *out = e[0x44];
    }
    return *(s32*)(e + 0x40);
}

extern "C" void fn_80124AAC(void* self, s32 idx, u32 a, u32 b) {
    u8* e = (u8*)lbl_802FF370 + idx * 0x5c + 0x4c60;
    *(u32*)(e + 0x4c) = a;
    *(u32*)(e + 0x50) = b;
    *(u8*)(e + 0x3c) = 0;
    fn_801BDE1C(e, 7, 1);
}

extern "C" s32 fn_80124AF4(void* a, s32 idx, u8* out) {
    u8* e = (u8*)lbl_802FF370 + idx * 0x5c + 0x4c60;
    if (*(u32*)(e + 0x24) != 7) {
        return -1;
    }
    if (e[0x3c] != 1) {
        return -2;
    }
    if (*(s32*)(e + 0x40) == 0 && out != NULL) {
        *out = e[0x44];
    }
    return *(s32*)(e + 0x40);
}

extern "C" void fn_801C0EEC(void*);
extern "C" u32 fn_801C027C(void);
extern "C" void fn_801C1174(void* p);
extern "C" BOOL OSDisableInterrupts(void);
extern "C" void fn_80124DAC(OSAlarm* alarm, OSContext* ctx) {
    fn_801C0EEC(*(void**)((u8*)alarm + 0x28));
}

extern "C" void fn_80124DD0(void* a, void* b, OSTime tick) {
    OSAlarm alarm;
    register BOOL level;
    volatile u32 saved;

    OSCreateAlarm(&alarm);
    saved = fn_801C027C();
    level = OSDisableInterrupts();
    OSSetAlarm(&alarm, tick, fn_80124DAC);
    fn_801C1174((void*)saved);
    OSRestoreInterrupts(level);
}

extern "C" void fn_80124E44(void* p, void** v)
{
	*(u32*)((u8*)*v + 0x40) = 0;
}

extern "C" s32 fn_801400E0(s32 a, s32 b, s32 c, s32 d, s32 e, void* f);
extern "C" s32 fn_80124E54(s32 param_1, s32* param_2) {
    u8* r31 = *(u8**)param_2;
    s32 r3 = fn_801400E0(*(s32*)(r31 + 0x28), *(s32*)(r31 + 0x34), *(s32*)(r31 + 0x38), *(s32*)(r31 + 0x2c), *(s32*)(r31 + 0x30), r31 + 0x44);
    *(s32*)(r31 + 0x40) = r3;
    if (*(s32*)(r31 + 0x40) == 0) {
        *(u8*)(r31 + 0x3C) = 1;
    } else if (*(s32*)(r31 + 0x40) == 1 || *(s32*)(r31 + 0x40) == 3) {
        param_2[5] = param_2[4];
        param_2[6] = ((*(u32*)0x800000F8 >> 2) / 1000) * 15;
    }
    return *(s32*)(r31 + 0x40);
}

extern "C" s32 fn_801C5B30(void* param_1);
extern "C" s32 fn_80125010(s32 param_1, s32* param_2) {
    u8* r31 = *(u8**)param_2;
    s32 r3 = fn_801C5B30(*(void**)(r31 + 0x28));
    *(s32*)(r31 + 0x40) = r3;
    if (*(s32*)(r31 + 0x40) == 0x80) {
        param_2[5] = param_2[4];
        param_2[6] = ((*(u32*)0x800000F8 >> 2) / 1000) * 15;
    } else {
        *(u8*)(r31 + 0x3C) = 1;
    }
    return *(s32*)(r31 + 0x40);
}

extern "C" s32 fn_8013F008(s32 a, void* b);
extern "C" s32 fn_801401F4(s32 a, s32 b, void* c);
extern "C" void* fn_8012F6F8(void* a, s32 b, void* c);
extern "C" s32 fn_80125098(s32 param_1, s32* param_2) {
    u8* r31 = *(u8**)param_2;
    s32 r3 = fn_8013F008(*(s32*)(r31 + 0x28), r31 + 0x44);
    *(s32*)(r31 + 0x40) = r3;
    r31[0x3C] = 1;
    return *(s32*)(r31 + 0x40);
}

extern "C" s32 fn_801250DC(s32 param_1, s32* param_2) {
    u8* r31 = *(u8**)param_2;
    s32 r3 = fn_801401F4(*(s32*)(r31 + 0x28), *(s32*)(r31 + 0x48), r31 + 0x44);
    *(s32*)(r31 + 0x40) = r3;
    r31[0x3C] = 1;
    return *(s32*)(r31 + 0x40);
}

extern "C" s32 fn_8014034C(s32 a, s32 b, void* c);
extern "C" s32 fn_80125124(s32 param_1, s32* param_2) {
    u8* r31 = *(u8**)param_2;
    s32 r3 = fn_8014034C(*(s32*)(r31 + 0x28), *(s32*)(r31 + 0x48), r31 + 0x44);
    *(s32*)(r31 + 0x40) = r3;
    r31[0x3C] = 1;
    return *(s32*)(r31 + 0x40);
}

extern "C" s32 fn_8013EF14(s32 a, void* b);
extern "C" s32 fn_8012516C(s32 param_1, s32* param_2) {
    u8* r31 = *(u8**)param_2;
    s32 r3 = fn_8013EF14(*(s32*)(r31 + 0x28), r31 + 0x44);
    *(s32*)(r31 + 0x40) = r3;
    r31[0x3C] = 1;
    return *(s32*)(r31 + 0x40);
}

extern "C" u8* fn_801251B0(u8* self, s32 param_2, s32 param_3) {
    u8 buf[16];
    *(s32*)(self + 0x4) = 0;
    *(s32*)(self + 0x8) = 0;
    *(s16*)(self + 0xc) = 0;
    *(s16*)(self + 0xe) = 0;
    *(s16*)(self + 0x10) = 0;
    *(s16*)(self + 0x12) = 0;
    *(s32*)self = param_3;
    fn_8012F6F8(buf, param_2, self);
    return self;
}

extern "C" s32 fn_80125208(u8* self, s32 param_2) {
    u16 n = *(u16*)(self + 0xe);
    s32* list = *(s32**)(self + 0x4);
    u16 i = 0;
    s32 r;
    while (i < n) {
        r = list[i];
        if (param_2 == *(u16*)(r + 0x3c)) {
            return r;
        }
        i++;
    }
    return 0;
}

extern "C" void* fn_80125248(void* a, void* b, void* c) {
    s32 i;
    void* r = NULL;
    u8* arr;
    for (i = 0; i < *(u16*)((u8*)a + 0x12); i++) {
    }
    return r;
}

extern "C" void fn_801252EC(void* param_1, void* param_2) {
    ((void**)*(void***)((u8*)param_1 + 0x4))[*(u16*)((u8*)param_1 + 0xe)] = param_2;
    *(u16*)((u8*)param_1 + 0xe) = *(u16*)((u8*)param_1 + 0xe) + 1;
}

extern "C" void fn_8012530C(void* param_1, void* param_2) {
    ((void**)*(void***)((u8*)param_1 + 0x8))[*(u16*)((u8*)param_1 + 0x12)] = param_2;
    *(u16*)((u8*)param_1 + 0x12) = *(u16*)((u8*)param_1 + 0x12) + 1;
}

extern "C" void fn_8012532C(u32* p) {
    p[2] = 0;
    p[1] = 0;
    p[0] = 0;
    p[6] = 0;
    p[5] = 0;
    p[4] = 0;
    p[3] = 0;
    p[7] = 0;
    p[8] = 0;
    p[9] = 0;
    p[10] = 0;
    p[11] = 0;
    p[12] = 0;
    p[13] = 0;
    p[14] = 0;
    *((u8*)p + 0x47) = 0;
    *((u8*)p + 0x46) = 0;
    *((u8*)p + 0x45) = 0;
    *((u8*)p + 0x44) = 0;
    *((u8*)p + 0x43) = 0;
    *((u8*)p + 0x42) = 0;
    *((u8*)p + 0x41) = 0;
    *((u8*)p + 0x40) = 0;
    *((u8*)p + 0x3f) = 0;
    *((u8*)p + 0x3e) = 0;
    *(u16*)((u8*)p + 0x3c) = 0;
}

extern "C" void fn_80126F38(void* a, void* b);
extern "C" void fn_80127274(void* a, void* b);
extern "C" void fn_80127DD4(void* param_1, u8* self);
extern "C" void fn_8012BC90(void* a, void* b);
extern "C" void fn_80126E48(u8* self, u8* p, u8* other) {
    s32 i;
    *(u8**)(p + 0x0) = other;
    *(u8**)(p + 0x4) = self;
    p[0x216] = 0;
    fn_80127DD4(self, p);
    fn_8012BC90(*(void**)(self + 0x1c), p);
    for (i = 1; i <= other[0x110]; i++) {
        p[0x216]++;
        if ((*(u32*)(**(u8***)(self + 0x1c) + 8) & 0x400000) && *(u32*)(self + 0x24) != 0) {
            fn_80127274(self, p);
        }
        fn_80126F38(self, p);
        if (!(*(u32*)(**(u8***)(self + 0x1c) + 8) & 0x400000) && *(u32*)(self + 0x24) != 0) {
            fn_80127274(self, p);
        }
    }
}

extern "C" void fn_80127954(void* p, void* a, void* b) {
    s32 i;
    if (*(void**)((u8*)p + 0xc) != NULL) {
        for (i = *(u8*)((u8*)p + 0x44) - 1; i >= 0; i--) {
            ((void (**)(void*, void*))*(void**)((u8*)p + 0xc))[i](a, b);
        }
    }
}

#pragma use_lmw_stmw off
extern "C" void fn_801279D0(u8* p, void* a, void* b) {
    s32 i;
    if (*(void**)(p + 0x14) != 0) {
        for (i = p[0x46] - 1; i >= 0; i--) {
            ((void (**)(void*, void*))(*(u8**)(p + 0x14)))[i](a, b);
        }
    }
}

extern "C" void fn_80127A4C(u8* p, void* a, void* b) {
    s32 i;
    for (i = p[0x3e] - 1; i >= 0; i--) {
        void* e = ((void**)*(void**)(p + 0x30))[i];
        ((Unk80127A4CListener*)((void**)e)[1])->vf4(a, e, b);
    }
}

#pragma use_lmw_stmw reset
extern "C" void fn_80127DD4(void* param_1, u8* self) {
    f32 mtx[3][4];
    fn_80132450(*(s16*)(*(u8**)self + 0x4c) * 0xb6, *(s16*)(*(u8**)self + 0x4e) * 0xb6, *(s16*)(*(u8**)self + 0x50) * 0xb6, mtx);
    fn_801C5DA8(*(u8**)self + 0x68, mtx, self + 0xa8);
    fn_801C6684(self + 0xa8, *(u8**)self + 0x18, self + 0x120);
}

extern "C" void fn_80127E54(void) {
}

extern "C" void fn_801DBA5C(s32 v, s32 n);
extern "C" void fn_80132450(s16 a, s16 b, s16 c, void* out);
extern "C" void fn_801C5DA8(void* a, void* b, void* c);
extern "C" void fn_801C6684(void* a, void* b, void* c);
extern "C" void fn_80127E58(u8* self) {
    fn_801DBA5C((s32)(25.0f * *(f32*)(self + 0x144)), 5);
}

extern "C" void fn_801DBA1C(s32 v, s32 n);
extern "C" void fn_80127E94(u8* self) {
    fn_801DBA1C((s32)(25.0f * *(f32*)(self + 0x144)), 5);
}

extern "C" void fn_80127ED0(u8* self, u8* other) {
    f32 scale = 25.0f * *(f32*)(self + 0x144);
    fn_801DBA5C((s32)(*(f32*)(other + 0x60) * scale), 5);
}

extern "C" void fn_801DBA1C(s32 v, s32 n);
extern "C" void fn_80127F14(u8* self, u8* other) {
    f32 scale = 25.0f * *(f32*)(self + 0x144);
    fn_801DBA1C((s32)(*(f32*)(other + 0x60) * scale), 5);
}

extern "C" void fn_80127F58(char* p) {
    u8* obj = *(u8**)p;
    u32 c = *(u32*)(obj + 0x108);
    u8* b = (u8*)&c;
    u32 out;
    b[0] = (((u32)b[0] * (obj[0xb8] + 1)) >> 8) & 0xff;
    b[1] = (((u32)b[1] * (obj[0xb9] + 1)) >> 8) & 0xff;
    b[2] = (((u32)b[2] * (obj[0xba] + 1)) >> 8) & 0xff;
    b[3] = (((u32)b[3] * (obj[0xbb] + 1)) >> 8) & 0xff;
    out = c;
    fn_801DE4F4(1, &out);
}

extern "C" void fn_80127FF4(char* p) {
    u8* obj = *(u8**)p;
    u32 c = *(u32*)(obj + 0x10c);
    u8* b = (u8*)&c;
    u32 out;
    b[0] = (((u32)b[0] * (obj[0xbc] + 1)) >> 8) & 0xff;
    b[1] = (((u32)b[1] * (obj[0xbd] + 1)) >> 8) & 0xff;
    b[2] = (((u32)b[2] * (obj[0xbe] + 1)) >> 8) & 0xff;
    out = c;
    fn_801DE4F4(2, &out);
}

extern "C" void fn_80128190(char* p, u8* q) {
    u8* obj = *(u8**)p;
    u32 c = *(u32*)(obj + 0x108);
    u8* b = (u8*)&c;
    u32 out;
    b[3] = (((u32)b[3] * (obj[0xbb] + 1)) >> 8) & 0xff;
    b[3] = (((u32)b[3] * (q[0x96] + 1)) >> 8) & 0xff;
    b[2] = (((u32)b[2] * (obj[0xba] + 1)) >> 8) & 0xff;
    b[1] = (((u32)b[1] * (obj[0xb9] + 1)) >> 8) & 0xff;
    b[0] = (((u32)b[0] * (obj[0xb8] + 1)) >> 8) & 0xff;
    out = c;
    fn_801DE4F4(1, &out);
}

extern "C" void fn_80128240(char* p, char* q) {
    u8* obj = *(u8**)p;
    u32 c = *(u32*)(q + 0x8c);
    u8* b = (u8*)&c;
    u32 out;
    b[0] = (((u32)b[0] * (obj[0xb8] + 1)) >> 8) & 0xff;
    b[1] = (((u32)b[1] * (obj[0xb9] + 1)) >> 8) & 0xff;
    b[2] = (((u32)b[2] * (obj[0xba] + 1)) >> 8) & 0xff;
    b[3] = (((((u32)b[3] * (obj[0xbb] + 1)) >> 8) & 0xff) * ((u32)q[0x96] + 1) >> 8) & 0xff;
    out = c;
    fn_801DE4F4(1, &out);
}

extern "C" void fn_80128548(char* p, char* q) {
    u8* obj = *(u8**)p;
    u32 c = *(u32*)(q + 0x90);
    u8* b = (u8*)&c;
    u32 out;
    b[0] = (((u32)b[0] * (obj[0xbc] + 1)) >> 8) & 0xff;
    b[1] = (((u32)b[1] * (obj[0xbd] + 1)) >> 8) & 0xff;
    b[2] = (((u32)b[2] * (obj[0xbe] + 1)) >> 8) & 0xff;
    out = c;
    fn_801DE4F4(2, &out);
}

extern "C" void fn_801285CC(char* p) {
    u32 a = *(u32*)(*(char**)p + 0x100);
    s16 m = *(s16*)(**(char***)(*(char**)(p + 4) + 0x1c) + 0x24);
    *(s16*)(p + 0x214) = (a < (u32)m) ? (s16)a : m;
}

extern "C" void fn_801285F8(char* p, char* q) {
    s16 a = *(s16*)(q + 0x80);
    s16 m = *(s16*)(**(char***)(*(char**)(p + 4) + 0x1c) + 0x24);
    *(s16*)(p + 0x214) = (a < m) ? a : m;
}

extern "C" void fn_801DE4F4(s32, void*);
extern "C" void fn_80128620(char* p) {
    u32 a = *(u32*)(*(char**)p + 0x100);
    s32 m = *(s16*)(**(char***)(*(char**)(p + 4) + 0x1c) + 0x24) + 1;
    u32 q = a / m;
    *(s16*)(p + 0x214) = a - q * m;
}

extern "C" void fn_80128650(char* p, char* q) {
    char* info = **(char***)(*(char**)(p + 4) + 0x1c);
    s32 a = *(s16*)(q + 0x80) + (*(u8*)(info + 0x2f) & *(u8*)(q + 0x95));
    s32 m = *(s16*)(info + 0x24) + 1;
    s32 r = a / m;
    *(s16*)(p + 0x214) = a - r * m;
}

extern "C" void fn_8012868C(char* p) {
    char* t = *(char**)(p + 4);
    char* obj = *(char**)p;
    char* info = **(char***)(t + 0x1c);
    u32 a = *(u32*)(obj + 0x100);
    s16 m = *(s16*)(info + 0x24);
    u32 q = a / m;
    s32 r = a - q * m;
    *(s16*)(p + 0x214) = r + (q & 1) * (m - 2 * r);
}

extern "C" void fn_801286CC(u8* param_1, u8* param_2) {
    u8* p = *(u8**)(param_1 + 4);
    u8* iVar2 = **(u8***)(p + 0x1c);
    s32 b = *(u8*)(param_2 + 0x95);
    s32 sum = *(s16*)(param_2 + 0x80) + (b & *(u8*)(iVar2 + 0x2f));
    s32 d = *(s16*)(iVar2 + 0x24);
    s32 q = sum / d;
    s32 rem = sum - q * d;
    *(s16*)(param_1 + 0x214) = rem + (q & 1) * (d - rem * 2);
}

extern "C" void fn_80128718(u8* self) {
    *(s16*)(self + 0x214) = 0;
}

extern "C" void fn_80128724(u8* param_1, u8* param_2) {
    u8* iVar1 = **(u8***)(*(u8**)(param_1 + 4) + 0x1c);
    s32 uVar2 = (s32)*(s16*)(iVar1 + 0x24) + 1;
    s32 iVar3 = (s32)(*(f32*)(param_2 + 0x84) * (f32)uVar2) + (*(u8*)(param_2 + 0x95) & *(u8*)(iVar1 + 0x2f));
    *(s16*)(param_1 + 0x214) = iVar3 % uVar2;
}

extern "C" void fn_80128794(u8* self) {
    *(s16*)(self + 0x214) = 0;
}

extern "C" void fn_801287A0(u8* param_1, u8* param_2) {
    u8* p = *(u8**)(param_1 + 4);
    u8* iVar2 = **(u8***)(p + 0x1c);
    u8 b = *(u8*)(param_2 + 0x95);
    s32 d = *(s16*)(iVar2 + 0x24) + 1;
    s32 m = b & *(u8*)(iVar2 + 0x2f);
    *(s16*)(param_1 + 0x214) = m % d;
}

extern "C" void fn_801287D4(u8* p) {
    u8* a = *(u8**)(p + 4);
    s32 i = *(s16*)(p + 0x214);
    u8* b = *(u8**)(*(u8**)(a + 0x1c) + 0xc);
    u8* e = b + i * 4;
    u8* q = *(u8**)p;
    q[0x108] = e[0];
    q[0x109] = e[1];
    q[0x10a] = e[2];
    q[0x10b] = e[3];
}

extern "C" void fn_80128814(char* p, char* q) {
    s32 i = *(s16*)(p + 0x214);
    char* b = *(char**)(*(char**)(*(char**)(p + 4) + 0x1c) + 0xc);
    u8* e = (u8*)(b + i * 4);
    q[0x8c] = e[0];
    q[0x8d] = e[1];
    q[0x8e] = e[2];
    q[0x8f] = e[3];
}

extern "C" void fn_80128850(u8* p) {
    u8* a = *(u8**)(p + 4);
    s32 i = *(s16*)(p + 0x214);
    u8* b = *(u8**)(*(u8**)(a + 0x1c) + 0x10);
    u8* e = b + i * 4;
    u8* q = *(u8**)p;
    q[0x10c] = e[0];
    q[0x10d] = e[1];
    q[0x10e] = e[2];
    q[0x10f] = e[3];
}

extern "C" void fn_80128890(char* p, char* q) {
    s32 i = *(s16*)(p + 0x214);
    char* b = *(char**)(*(char**)(*(char**)(p + 4) + 0x1c) + 0x10);
    u8* e = (u8*)(b + i * 4);
    q[0x90] = e[0];
    q[0x91] = e[1];
    q[0x92] = e[2];
    q[0x93] = e[3];
}

extern "C" void fn_801288CC(void** self, u8* dst) {
    u8* src = (u8*)*self;
    dst[0x8c] = src[0x108];
    dst[0x8d] = src[0x109];
    dst[0x8e] = src[0x10a];
    dst[0x8f] = src[0x10b];
    dst[0x90] = src[0x10c];
    dst[0x91] = src[0x10d];
    dst[0x92] = src[0x10e];
    dst[0x93] = src[0x10f];
}

extern "C" void fn_801DACA4(s32, s32, s32, s32, s32, s32);
extern "C" void fn_80128914(void)
{
	fn_801DACA4(0, 1, 4, 0x3c, 0, 0x7d);
}

extern "C" void fn_8012894C(void) {
    fn_801DACA4(0, 1, 4, 0x1e, 0, 0x7d);
}

extern "C" void fn_80128984(void) {
    fn_801DACA4(0, 0, 0, 0x1e, 0, 0x7d);
}

extern "C" void fn_80128D4C(u8* a)
{
    u8* p = *(u8**)(*(u8**)(a + 4) + 0x1c);
    u16 idx = (*(u16**)(*(u8**)(a + 4) + 0x38))[(u8)(*(u8**)p)[0x20]];
    fn_801191F0((*(u8***)(*(u8**)(a + 8) + 8))[idx] + 4, 0);
}

extern "C" void fn_80128DA0(u8* a)
{
    u16 idx = (*(u16**)(*(u8**)(a + 4) + 0x38))[(*(u8**)a)[0x111]];
    fn_801191F0((*(u8***)(*(u8**)(a + 8) + 8))[idx] + 4, 0);
}

extern "C" void fn_80128DF0(u8* a, u8* b)
{
    u16 idx = (*(u16**)(*(u8**)(a + 4) + 0x38))[b[0x94]];
    fn_801191F0((*(u8***)(*(u8**)(a + 8) + 8))[idx] + 4, 0);
}

extern "C" void fn_80128E3C(void** param_1) {
    u8* obj = (u8*)param_1[0];
    u8** info = *(u8***)((u8*)param_1[1] + 0x1c);
    u32 n = (*info)[0x1f] - 1;
    u32 v = *(u32*)(obj + 0x100);
    if (n < v) {
        v = n;
    }
    obj[0x111] = ((u8*)info[2])[v & 0xff];
}

extern "C" void fn_80128E78(char* p, char* q) {
    char* r6;
    s32 m;
    s32 i;
    r6 = *(char**)(*(char**)(p + 4) + 0x1c);
    m = *(s16*)(q + 0x80);
    i = *(u8*)(*(char**)r6 + 0x1f) - 1;
    if (i < m) {
        m = i;
    }
    q[0x94] = (*(char**)(r6 + 8))[(u8)m];
}

extern "C" void fn_80128EB0(void** param_1) {
    u8* obj = (u8*)*param_1;
    u8* info = *(u8**)((u8*)param_1[1] + 0x1c);
    u32 v = *(u32*)(obj + 0x100);
    u8 idx = v % (*(u8**)info)[0x1f];
    obj[0x111] = (*(u8**)(info + 8))[idx];
}

extern "C" void fn_80128EE8(u8* a, u8* b) {
    u8** info = *(u8***)(*(u8**)(a + 4) + 0x1c);
    b[0x94] = info[2][(u8)((*(s16*)(b + 0x80) + (b[0x95] & info[0][0x30])) % info[0][0x1f])];
}

extern "C" void fn_80128F2C(void** param_1) {
    u8* obj = (u8*)*param_1;
    u8* info = *(u8**)((u8*)param_1[1] + 0x1c);
    s32 v = *(s32*)(obj + 0x100);
    s32 m = (*(u8**)info)[0x1f] - 1;
    s32 q = v / m;
    s32 r = v - q * m;
    u8 idx = r + (q & 1) * (m - 2 * r);
    obj[0x111] = (*(u8**)(info + 8))[idx];
}

extern "C" void fn_80128F7C(u8* a, u8* b) {
    u8* info = *(u8**)(*(u8**)(a + 4) + 0x1c);
    s32 v = *(s16*)(b + 0x80) + (b[0x95] & (*(u8**)info)[0x30]);
    s32 m = (*(u8**)info)[0x1f] - 1;
    s32 q = v / m;
    s32 r = v - q * m;
    u8 idx = r + (q & 1) * (m - 2 * r);
    b[0x94] = (*(u8**)(info + 8))[idx];
}

extern "C" void fn_80128FD8(void** param_1) {
    u8* obj = (u8*)*param_1;
    u8* info = *(u8**)((u8*)param_1[1] + 0x1c);
    obj[0x111] = (*(u8**)info)[0x20];
}

extern "C" void fn_801DF2A4(void*, s32);
extern "C" void fn_80128FF4(u8* a, u8* b) {
    u8** info = *(u8***)(*(u8**)(a + 4) + 0x1c);
    u8* hdr = info[0];
    u8* tbl = info[2];
    s32 m = hdr[0x1f];
    s32 v = (s32)(*(f32*)(b + 0x84) * (f32)m) + (b[0x95] & hdr[0x30]);
    b[0x94] = tbl[(u8)(v % m)];
}

extern "C" void fn_8012906C(void** param_1) {
    u8* obj = (u8*)*param_1;
    u8* info = *(u8**)((u8*)param_1[1] + 0x1c);
    obj[0x111] = (*(u8**)info)[0x20];
}

extern "C" void fn_80129088(void** param_1, u8* b) {
    u8* info = *(u8**)((u8*)param_1[1] + 0x1c);
    b[0x94] = (*(u8**)(info + 8))[(u8)((b[0x95] & (*(u8**)info)[0x30]) % (*(u8**)info)[0x1f])];
}

extern "C" void fn_801290C4(void* p) {
    fn_801DF2A4((u8*)p + 0x184, 0);
}

extern "C" void fn_801290EC(void) {
}

extern "C" void fn_801DF378(void* a, s32 b, s32 c);
extern "C" void fn_801290F0(u8* self, void* p) {
    u8 buf[0x38];
    fn_801C5DA8(self + 0x1b4, p, buf);
    fn_801DF378(buf, 0x1e, 0);
}

extern "C" void fn_801C6630(f32 (*a)[4], void* b, void* c);
extern "C" void fn_801DF0BC(void* p, s32 n);
extern void* lbl_80290DE0[];
extern void* lbl_80290DA0[];
extern "C" void fn_80129308(u8* p, u8* q) {
    f32 v[3];
    f32 m[12];

    if (!(*(u32*)(q + 0x7c) & 8)) {
        fn_801C6630((f32(*)[4])(p + 0x184), q, v);
        m[0] = *(f32*)(p + 0x144) * *(f32*)(q + 0x60);
        m[5] = *(f32*)(p + 0x148) * *(f32*)(q + 0x64);
        m[3] = v[0];
        m[7] = v[1];
        m[11] = v[2];
        m[10] = lbl_80301694;
        m[1] = lbl_80301698;
        m[2] = lbl_80301698;
        m[4] = lbl_80301698;
        m[6] = lbl_80301698;
        m[8] = lbl_80301698;
        m[9] = lbl_80301698;
        ((void (*)(void*, s32, f32, f32, f32, f32, f32))fn_801DF2A4)(m, 0, v[2], lbl_80301694, v[1], m[5], *(f32*)(p + 0x148));
        ((void (*)(void*, void*, void*))lbl_80290DE0[*(s32*)(p + 0x210)])(p, m, lbl_80290DE0);
        fn_801DF0BC(lbl_80290DA0, 0x20);
    }
}

extern "C" void fn_80129734(void* self, u8* obj, f32* out) {
    f32 x = *(f32*)(obj + 0x24);
    f32 y = *(f32*)(obj + 0x28);
    out[0] = x;
    f32 z = *(f32*)(obj + 0x2c);
    out[1] = y;
    out[2] = z;
}

extern "C" void fn_80129750(void* param_1, f32* param_2, f32* param_3) {
    f32 x = param_2[3];
    f32 y = param_2[4];
    param_3[0] = x;
    f32 z = param_2[5];
    param_3[1] = y;
    param_3[2] = z;
}

extern "C" void fn_8012976C(void* a, const Vec3f* src, Vec3f* dst) {
    dst->x = -src->x;
    dst->y = -src->y;
    dst->z = -src->z;
}

extern "C" void fn_801297A0(u8* obj, s32 param_2, f32* out) {
    f32 a = *(f32*)(obj + 0x120);
    f32 b = *(f32*)(obj + 0x124);
    out[0] = a;
    f32 c = *(f32*)(obj + 0x128);
    out[1] = b;
    out[2] = c;
}

extern "C" void fn_801297BC(u8* p, const JGeometry::TVec3f* src, JGeometry::TVec3f* out) {
    f32 x = src->x;
    f32 y = src->y;
    f32 z = src->z;
    JGeometry::TVec3f tmp;
    tmp.x = x;
    tmp.y = y;
    tmp.z = z;
    u8* q = *(u8**)(p + 0x1e8);
    u8* v = *(u8**)q;
    if (v != 0) {
        JGeometry::TVec3f* vv = (JGeometry::TVec3f*)(v + 0x8);
        out->x = vv->x;
        out->y = vv->y;
        out->z = vv->z;
    } else {
        fn_80130BC4(*(void**)p, out);
    }
    out->sub(tmp);
}

extern "C" void fn_80129854(f32* param_1, f32 param_2, f32 param_3) {
    param_1[0] = param_3;
    f32 one = lbl_80301694;
    f32 zero = lbl_80301698;
    f32 neg = -param_2;
    param_1[1] = zero;
    param_1[2] = neg;
    param_1[3] = zero;
    param_1[4] = zero;
    param_1[5] = one;
    param_1[6] = zero;
    param_1[7] = zero;
    param_1[8] = param_2;
    param_1[9] = zero;
    param_1[10] = param_3;
    param_1[11] = zero;
}

extern "C" void fn_80129894(f32* m, f32 s, f32 c) {
    m[0] = 1.0f;
    m[1] = 0.0f;
    m[2] = 0.0f;
    m[3] = 0.0f;
    m[4] = 0.0f;
    m[5] = c;
    m[6] = -s;
    m[7] = 0.0f;
    m[8] = 0.0f;
    m[9] = s;
    m[10] = c;
    m[11] = 0.0f;
}

extern "C" void fn_801298D4(f32* param_1, f32 param_2, f32 param_3) {
    f32 neg = -param_2;
    param_1[0] = param_3;
    f32 zero = lbl_80301698;
    f32 one = lbl_80301694;
    param_1[1] = neg;
    param_1[2] = zero;
    param_1[3] = zero;
    param_1[4] = param_2;
    param_1[5] = param_3;
    param_1[6] = zero;
    param_1[7] = zero;
    param_1[8] = zero;
    param_1[9] = zero;
    param_1[10] = one;
    param_1[11] = zero;
}

extern f32 lbl_803016A8;
extern f32 lbl_803016AC;
extern "C" void fn_80130BC4(void* a, JGeometry::TVec3f* out);
extern "C" void fn_801D9F18(s32, s32);
extern "C" void fn_801DB8C4(s32, s32, s32);
extern "C" void fn_80129914(f32* m, f32 s, f32 c) {
    f32 one = lbl_80301694;
    f32 zero = lbl_80301698;
    f32 a = lbl_803016A8 * (one - c);
    f32 b = lbl_803016AC * s;
    m[0] = a + c;
    m[1] = a - b;
    m[2] = a + b;
    m[3] = zero;
    m[4] = a + b;
    m[5] = a + c;
    m[6] = a - b;
    m[7] = zero;
    m[8] = a - b;
    m[9] = a + b;
    m[10] = a + c;
    m[11] = zero;
}

extern "C" void fn_80129970(f32* p, f32 a, f32 b) {
    p[0] *= a;
    p[4] *= a;
    p[8] *= a;
    p[1] *= b;
    p[5] *= b;
    p[9] *= b;
}

extern "C" void fn_801299BC(f32* p, f32 a, f32 b) {
    p[0] *= a;
    p[4] *= a;
    p[8] *= a;
    p[2] *= b;
    p[6] *= b;
    p[10] *= b;
}

extern "C" void fn_80129A08(f32* p, f32 a, f32 b) {
    p[0] *= a;
    p[4] *= a;
    p[8] *= a;
    p[1] *= b;
    p[5] *= b;
    p[9] *= b;
    p[2] *= a;
    p[6] *= a;
    p[10] *= a;
}

extern "C" void fn_8012A5B0(void* a, u8* p) {
    if ((*(u32*)(p + 0x7c) & 8) == 0) {
        fn_801D9F18(9, 1);
        fn_801D9F18(0xd, 1);
        fn_801DB8C4(0xb8, 1, 1);
        f32 y;
        f32 z = *(f32*)(p + 0x8);
        y = *(f32*)(p + 0x4);
        f32 x = *(f32*)(p + 0x0);
        *(volatile f32*)0xCC008000 = x;
        *(volatile f32*)0xCC008000 = y;
        *(volatile f32*)0xCC008000 = z;
        *(volatile f32*)0xCC008000 = lbl_80301698;
        *(volatile f32*)0xCC008000 = lbl_80301698;
        fn_801D9F18(9, 2);
        fn_801D9F18(0xd, 2);
    }
}

extern "C" void* fn_8012A804(void* p) {
    return *(void**)((char*)p + 4);
}

extern "C" int fn_8012A80C(int* p) { return *p; }

extern "C" void fn_8012B878(u8* p) {
    u8* obj = *(u8**)p;
    Unk80133A44Listener* sub = *(Unk80133A44Listener**)(obj + 0xec);
    if (sub != 0) {
        sub->vf5(obj);
    }
}

extern "C" void fn_8012B8B4(u8* p, void* arg) {
    u8* obj = *(u8**)p;
    Unk8012B8B4Listener* sub = *(Unk8012B8B4Listener**)(obj + 0xf0);
    if (sub != 0) {
        sub->vf4(obj, arg);
    }
}

extern "C" void fn_8012BDD0(u8* p, u8* q) {
    f32 r = *(f32*)(p + 0x1fc);
    u8* b;
    u8* a = *(u8**)(*(u8**)(p + 4) + 0x20);
    b = *(u8**)a;
    if (r < *(f32*)(b + 0xc)) {
        f32 t = r * *(f32*)(a + 0xc);
        *(f32*)(q + 0x60) = *(f32*)(q + 0x68) * (t + *(f32*)(b + 0x14));
        return;
    }
    if (r > *(f32*)(b + 0x10)) {
        f32 t = (r - *(f32*)(b + 0x10)) * *(f32*)(a + 0x14);
        *(f32*)(q + 0x60) = *(f32*)(q + 0x68) * (lbl_803016B8 + t);
        return;
    }
    *(f32*)(q + 0x60) = *(f32*)(q + 0x68);
}

extern "C" void fn_8012BE48(u8* p, u8* q) {
    f32 r = *(f32*)(p + 0x1fc);
    u8* b;
    u8* a = *(u8**)(*(u8**)(p + 4) + 0x20);
    b = *(u8**)a;
    if (r < *(f32*)(b + 0xc)) {
        f32 t = r * *(f32*)(a + 0x10);
        *(f32*)(q + 0x64) = *(f32*)(q + 0x68) * (t + *(f32*)(b + 0x1c));
        return;
    }
    if (r > *(f32*)(b + 0x10)) {
        f32 t = (r - *(f32*)(b + 0x10)) * *(f32*)(a + 0x18);
        *(f32*)(q + 0x64) = *(f32*)(q + 0x68) * (lbl_803016B8 + t);
        return;
    }
    *(f32*)(q + 0x64) = *(f32*)(q + 0x68);
}

extern "C" void fn_8012BEC0(void* a, f32* p) {
    p[0x64 / 4] = p[0x60 / 4];
}

extern "C" void fn_8012BECC(int param_1, int param_2) {
    *(f32 *)(param_1 + 0x1fc) = *(f32 *)(param_2 + 0x84);
}

extern f32 lbl_803016B8;
extern f32 lbl_803016C8;
extern "C" void fn_8012BED8(u8* p, u8* q) {
    s32 v = *(s16*)(q + 0x80);
    u8* a = *(u8**)(*(u8**)(p + 4) + 0x20);
    s32 d = *(s16*)(*(u8**)a + 0x28);
    *(f32*)(p + 0x1fc) = (f32)(v - (v / d) * d) / (f32)d;
}

extern "C" void fn_8012BF3C(u8* p, u8* q) {
    u8* a = *(u8**)(*(u8**)(p + 4) + 0x20);
    s32 d = *(s16*)(*(u8**)a + 0x2a);
    s32 v = *(s16*)(q + 0x80);
    *(f32*)(p + 0x1fc) = (f32)(v - (v / d) * d) / (f32)d;
}

extern "C" void fn_8012BFA0(u8* p, u8* q) {
    u8* a = *(u8**)(*(u8**)(p + 4) + 0x20);
    s16 d = *(s16*)(*(u8**)a + 0x28);
    s16 v = *(s16*)(q + 0x80);
    s32 quo = v / d;
    f32 r = (f32)(v - quo * d) / (f32)d;
    f32 t1 = lbl_803016C8 * r;
    f32 t2 = lbl_803016B8 - t1;
    f32 t3 = (f32)(quo & 1) * t2;
    *(f32*)(p + 0x1fc) = r + t3;
}

extern "C" void fn_8012C034(u8* p, u8* q) {
    u8* a = *(u8**)(*(u8**)(p + 4) + 0x20);
    s16 d = *(s16*)(*(u8**)a + 0x2a);
    s16 v = *(s16*)(q + 0x80);
    s32 quo = v / d;
    f32 r = (f32)(v - quo * d) / (f32)d;
    f32 t1 = lbl_803016C8 * r;
    f32 t2 = lbl_803016B8 - t1;
    f32 t3 = (f32)(quo & 1) * t2;
    *(f32*)(p + 0x1fc) = r + t3;
}

extern "C" void fn_8012C0C8(u8* p, u8* q)
{
    f32 r = *(f32*)(q + 0x84);
    u8* b;
    u8* a = *(u8**)(*(u8**)(p + 4) + 0x20);
    b = *(u8**)a;
    f32 v;
    if (r < *(f32*)(b + 0x2c)) {
        f32 t = r * *(f32*)(a + 4);
        v = lbl_803016CC * (*(f32*)(b + 0x34) + t);
    } else if (r > *(f32*)(b + 0x30)) {
        f32 t = (r - *(f32*)(b + 0x30)) * *(f32*)(a + 8);
        v = lbl_803016CC * (*(f32*)(b + 0x38) + t);
    } else {
        f32 t = lbl_803016CC;
        v = t * *(f32*)(b + 0x38);
    }
    *(u8*)(q + 0x96) = v;
}

extern "C" void* fn_8012C240(void* ptr, void* param_2) {
    *(void**)ptr = param_2;
    fn_8012C274(ptr);
    return ptr;
}

extern f32 lbl_803016D8;
extern "C" void fn_8012C274(void* arg0) {
    u8* d;
    f32 q;
    d = *(u8**)arg0;
    if (lbl_803016D8 != *(f32*)(d + 0x2c)) {
        q = (*(f32*)(d + 0x38) - *(f32*)(d + 0x34)) / *(f32*)(d + 0x2c);
    } else {
        q = lbl_803016B8;
    }
    *(f32*)((u8*)arg0 + 0x4) = q;
    d = *(u8**)arg0;
    if (*(f32*)(d + 0x30) != lbl_803016B8) {
        q = (*(f32*)(d + 0x3c) - *(f32*)(d + 0x38)) / (lbl_803016B8 - *(f32*)(d + 0x30));
    } else {
        q = lbl_803016B8;
    }
    *(f32*)((u8*)arg0 + 0x8) = q;
    d = *(u8**)arg0;
    if (lbl_803016D8 != *(f32*)(d + 0xc)) {
        *(f32*)((u8*)arg0 + 0xc) = (lbl_803016B8 - *(f32*)(d + 0x14)) / *(f32*)(d + 0xc);
        d = *(u8**)arg0;
        *(f32*)((u8*)arg0 + 0x10) = (lbl_803016B8 - *(f32*)(d + 0x1c)) / *(f32*)(d + 0xc);
    } else {
        *(f32*)((u8*)arg0 + 0x10) = lbl_803016B8;
        *(f32*)((u8*)arg0 + 0xc) = lbl_803016B8;
    }
    d = *(u8**)arg0;
    if (lbl_803016B8 != *(f32*)(d + 0x10)) {
        *(f32*)((u8*)arg0 + 0x14) = (*(f32*)(d + 0x18) - lbl_803016B8) / (lbl_803016B8 - *(f32*)(d + 0x10));
        d = *(u8**)arg0;
        *(f32*)((u8*)arg0 + 0x18) = (*(f32*)(d + 0x20) - lbl_803016B8) / (lbl_803016B8 - *(f32*)(d + 0x10));
        return;
    }
    *(f32*)((u8*)arg0 + 0x18) = lbl_803016B8;
    *(f32*)((u8*)arg0 + 0x14) = lbl_803016B8;
}

extern "C" void fn_8012C4A4(void* param_1, u8* param_2) {
    f32 val = lbl_803016E0 * (lbl_803016E4 - *(f32*)(param_2 + 0x84));
    OSf32tou8(&val, param_2 + 0x96);
}

extern "C" void fn_8012C4D0(void* param_1, u8* param_2) {
    *(f32*)(param_2 + 0x60) = *(f32*)(param_2 + 0x68) * (lbl_803016E4 - *(f32*)(param_2 + 0x84));
    *(f32*)(param_2 + 0x64) = *(f32*)(param_2 + 0x6c) * (lbl_803016E4 - *(f32*)(param_2 + 0x84));
}

extern "C" const float lbl_803016E4;
extern "C" const float lbl_803016E0;
extern "C" void fn_8012C274(void*);
extern "C" void fn_8012C500(void** param_1, void* param_2) {
    *param_1 = param_2;
}

extern "C" void fn_8012C508(u8* param_1)
{
    u8* p = param_1;
    u8** data = *(u8***)(*(u8**)(p + 4) + 0x28);
    if (*(u32*)(*data + 8) & 1) {
        fn_801DACA4(1, 1, 4, 0x3c, 0, 0x7d);
        fn_801191F0(*(u8**)(*(u8**)(*(u8**)(p + 8) + 8) + (*(u16*)(*(u8**)(*(u8**)(p + 4) + 0x38) + (u8)(*(s8*)(*data + 0x25)) * 2)) * 4) + 4, 2);
    }
    if (*(u32*)(*data + 8) & 0x100) {
        fn_801DACA4(2, 1, 4, 0x3c, 0, 0x7d);
        fn_801191F0(*(u8**)(*(u8**)(*(u8**)(p + 8) + 8) + (*(u16*)(*(u8**)(*(u8**)(p + 4) + 0x38) + (u8)(*(s8*)(*data + 0x26)) * 2)) * 4) + 4, 3);
    }
}

extern "C" void fn_8012C604(void** param_1, void* param_2) {
    *param_1 = param_2;
}

extern "C" void fn_8012C60C(u8* p)
{
    u32 sp10;
    u32 spC;
    u32 sp8;
    u32 r;
    f32 f1;
    f32 f2;
    f32 f3;
    f32 a;
    f32 b;
    f32 c;
    u8* q;

    f3 = 0.0f;
    f2 = 1.0f;
    f1 = 0.5f;
    *(f32*)(p + 0x18) = f3;
    *(f32*)(p + 0x14) = f3;
    *(f32*)(p + 0x10) = f3;

    q = *(u8**)p;
    r = *(u32*)(q + 0xC4) * 0x19660D + 0x3C6EF35F;
    *(u32*)(q + 0xC4) = r;
    sp10 = (r >> 9) | 0x3F800000;
    a = *(f32*)&sp10;
    a = (a - f2) - f1;

    q = *(u8**)p;
    r = *(u32*)(q + 0xC4) * 0x19660D + 0x3C6EF35F;
    *(u32*)(q + 0xC4) = r;
    spC = (r >> 9) | 0x3F800000;
    b = *(f32*)&spC;
    b = (b - f2) - f1;

    q = *(u8**)p;
    r = *(u32*)(q + 0xC4) * 0x19660D + 0x3C6EF35F;
    *(u32*)(q + 0xC4) = r;
    sp8 = (r >> 9) | 0x3F800000;
    c = *(f32*)&sp8;
    c = (c - f2) - f1;

    *(f32*)(p + 0x1C) = c;
    *(f32*)(p + 0x20) = b;
    *(f32*)(p + 0x24) = a;
    f1 = *(f32*)(p + 0x24);
    *(f32*)(p + 0x28) = *(f32*)(p + 0x1C);
    *(f32*)(p + 0x2C) = f3;
    *(f32*)(p + 0x30) = f1;
}

extern "C" void fn_8012D010(void*);
extern "C" void* fn_8012CFDC(void* ptr, void* param_2) {
    *(void**)ptr = param_2;
    fn_8012D010(ptr);
    return ptr;
}

extern "C" void fn_8012C9B0(void);
extern "C" void fn_8012CAB8(void);
extern "C" void fn_8012CD40(void);
extern "C" void fn_8012CEBC(void);
extern "C" void fn_8012C60C(u8* p);
extern "C" void fn_8012C804(void);
extern "C" void fn_8012C6E8(void);
extern "C" void fn_8012D010(void* ptr) {
    u32 type = (*(u32*)(*(u8**)ptr + 8) >> 8) & 7;
    switch (type) {
    case 0:
        *(void (**)(void))((u8*)ptr + 4) = fn_8012C9B0;
        break;
    case 1:
        *(void (**)(void))((u8*)ptr + 4) = fn_8012CAB8;
        break;
    case 2:
        *(void (**)(void))((u8*)ptr + 4) = fn_8012CD40;
        break;
    case 3:
        *(void (**)(void))((u8*)ptr + 4) = fn_8012CEBC;
        break;
    case 4:
        *(void (**)(void))((u8*)ptr + 4) = (void (*)(void))fn_8012C60C;
        break;
    case 5:
        *(void (**)(void))((u8*)ptr + 4) = fn_8012C804;
        break;
    case 6:
        *(void (**)(void))((u8*)ptr + 4) = fn_8012C6E8;
        break;
    }
}

extern "C" void fn_8012D2B0(u8* p, u8* r4, u8* q)
{
    if ((*(u32*)(*(u8**)q + 8) >> 16) & 2) {
        JMathInlineVEC::PSVECScale((JGeometry::TVec3f*)(q + 0x1c), (JGeometry::TVec3f*)(p + 4), *(f32*)(q + 0x28));
    } else {
        fn_801C6684(r4 + 0x78, q + 0x1c, p + 4);
        ((JGeometry::TVec3f*)(p + 4))->scale(*(f32*)(q + 0x28));
    }
}

extern "C" void fn_8012D7F8(u8* p, u8* a, u8* b) {
    JGeometry::TVec3f* out = (JGeometry::TVec3f*)(p + 0x10);
    out->sub(*(JGeometry::TVec3f*)(b + 0x10), *(JGeometry::TVec3f*)(a + 0x108));
    fn_801C6684(a + 0x78, out, out);
}

extern "C" void fn_8012DA68(u8* p, u8* a, u8* b) {
    JGeometry::TVec3f* out = (JGeometry::TVec3f*)(p + 0x10);
    out->sub(*(JGeometry::TVec3f*)(b + 0x10), *(JGeometry::TVec3f*)(a + 0x108));
    fn_801C6684(a + 0x78, out, out);
    f32 f = *(f32*)(*(u8**)b + 0x2c);
    *(f32*)(p + 0x1c) = f * f;
}

extern const f32 lbl_80301710;
extern const f32 lbl_80301714;
extern "C" void fn_8012EA6C(void* a, void* b, u8* p2, u8* p3) {
    f32 var_f3;
    f32 f2;
    u8* p;
    u32 flags;
    f32 t;

    if (!(*(u32*)(p3 + 0x7c) & 4)) {
        f2 = *(f32*)(p3 + 0x84);
        p = *(u8**)p2;
        flags = *(u32*)(p + 8) >> 16;
        var_f3 = lbl_80301710;
        if ((flags & 8) && f2 < *(f32*)(p + 0x38)) {
            var_f3 = lbl_80301714;
        } else if ((flags & 0x10) && f2 < *(f32*)(p + 0x3c)) {
            var_f3 = lbl_80301714;
        } else if ((flags & 0x40) && f2 < *(f32*)(p + 0x34)) {
            var_f3 = (*(f32*)(p + 0x3c) - f2) * *(f32*)(p2 + 0xc);
        } else if ((flags & 0x20) && f2 < *(f32*)(p + 0x30)) {
            var_f3 = (f2 - *(f32*)(p + 0x38)) * *(f32*)(p2 + 8);
        }
        t = (lbl_80301710 - *(f32*)(p2 + 0x28)) * var_f3;
        *(f32*)(p3 + 0x74) = *(f32*)(p3 + 0x74) * (lbl_80301710 - t);
        return;
    }
    *(f32*)(p3 + 0x74) = *(f32*)(p3 + 0x74) * *(f32*)(p2 + 0x28);
}

extern "C" void fn_8012EF18(void*, void*);
extern "C" void* fn_8012EEE0(void* ptr, void* param_2, void* param_3) {
    *(void**)ptr = param_2;
    fn_8012EF18(ptr, param_3);
    return ptr;
}

extern void* lbl_80290F9C[];
extern "C" void* fn_8012F204(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80290F9C;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80290FCC[];
extern "C" void* fn_8012F24C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80290FCC;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80290F9C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80290FFC[];
extern "C" void* fn_8012F2A8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80290FFC;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80290F9C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8029102C[];
extern "C" void* fn_8012F304(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029102C;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80290F9C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80291060[];
extern "C" void* fn_8012F360(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80291060;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80290F9C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80291090[];
extern "C" void* fn_8012F3BC(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80291090;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80290F9C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_802910C0[];
extern "C" void* fn_8012F418(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802910C0;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80290F9C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_802910F0[];
extern "C" void* fn_8012F474(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802910F0;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80290F9C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8029111C[];
extern "C" void* fn_8012F4D0(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029111C;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80290F9C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8029114C[];
extern "C" void* fn_8012F52C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029114C;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80290F9C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_8012F588(u32* p, u32 v)
{
	p[0] = v;
	p[1] = v + 0xc;
}

extern "C" void fn_8012F598(void** p, f32 t) {
    u8* obj = (u8*)p[0];
    if (obj[0xb] != 0) {
        f32* arr = (f32*)p[1];
        s32 idx = obj[9] - 1;
        s32 a = (s32)t;
        s32 b = (s32)arr[idx];
        s32 q = (a / (b + 1)) * (b + 1);
        t = t - (f32)q;
    }
    fn_801326B0(obj[9], p[1]);
}

extern "C" void fn_80118C44(void* a, u8* b, s32 c);
extern void* lbl_8029116C[];
extern "C" void* fn_8012F62C(u8* self, s32 param_2) {
    *(void**)self = lbl_8029116C;
    self[0x3f] &= 2;
    *(s32*)(self + 0x2c) = 0;
    *(s32*)(self + 0x24) = 0;
    *(s32*)(self + 0x44) = param_2;
    fn_80118C44(self + 4, (u8*)*(s32*)(self + 0x44) + 0x20, 0);
    return self;
}

extern "C" void fn_80118BD0(void* a, s32 b);
extern "C" void* fn_8012F694(u8* self, s16 param_2) {
    if (self != nullptr) {
        *(void**)self = lbl_8029116C;
        fn_80118BD0(self + 4, -1);
        if (param_2 > 0) {
            fn_8015AB1C(self);
        }
    }
    return self;
}

extern "C" void fn_8012F738(void* p);
extern "C" void* fn_8012F6F8(void* a, s32 b, void* c) {
    if (b == 0x322d3130) {
        fn_8012F738(a);
    }
    return a;
}

#pragma use_lmw_stmw off
#pragma dont_inline on
extern "C" void* fn_8012FCFC(u8* self, Vec3f* pos, s32 arg2, u8 arg3, u8 arg4, s32 arg5, s32 arg6)
{
    u8* obj;
    u8* list;
    s32 r;
    f32 z;
    f32 y;
    f32 x;

    r = fn_80125208(*(u8**)(*(u8**)(self + 0x1c) + ((arg4 * 4) & 0x3FC)), arg2);
    if (r != 0 && *(u32*)(self + 0xc) != 0) {
        list = *(u8**)(self + 0x4);
        fn_80166FC4(self + 0x4, list);
        fn_80166C84(*(u8**)self + arg3 * 0xc, list);
        obj = *(u8**)list;
        fn_80130404(obj, self, r);
        x = pos->x;
        *(u8**)(obj + 0xE0) = self + 0x10;
        y = pos->y;
        *(s32*)(obj + 0xEC) = arg5;
        z = pos->z;
        *(s32*)(obj + 0xF0) = arg6;
        *(u8*)(obj + 0x112) = arg3;
        *(u8*)(obj + 0x113) = arg4;
        *(f32*)(obj + 0xA4) = x;
        *(f32*)(obj + 0xA8) = y;
        *(f32*)(obj + 0xAC) = z;
        return obj;
    }
    return NULL;
}
#pragma dont_inline reset
#pragma use_lmw_stmw reset
extern "C" void fn_8012FDE0(u8* p)
{
    u8* node;
    u8* actor;
    u8 i;
    for (i = 0; i < *(u8*)(p + 0x2c); i++) {
        node = *(u8**)(*(u8**)p + i * 0xc);
        while (node != 0) {
            actor = *(u8**)node;
            node = *(u8**)(node + 0xc);
            if (fn_801268E4(*(void**)(actor + 0xe8), *(void**)(p + 0x20), actor) && !(*(u32*)(actor + 0xf4) & 0x200)) {
                fn_80130090((void**)p, actor);
            }
        }
    }
}

extern "C" void fn_80130974(void* p);
extern "C" void fn_80166FC4(void* a, void* b);
extern "C" void fn_80166D3C(void* a, void* b);
extern "C" void fn_80130090(void** param_1, u8* param_2) {
    fn_80130974(param_2);
    *(u32*)(param_2 + 0xf4) |= 0x300;
    fn_80166FC4((u8*)*param_1 + param_2[0x112] * 0xc, param_2 + 0x58);
    fn_80166D3C(param_1 + 1, param_2 + 0x58);
}

extern "C" void fn_801300FC(u8* p, u32 v, u8 i) {
    (*(u32**)(p + 0x1c))[i] = v;
}

extern "C" void fn_80166C70(unsigned short* param_1, unsigned short param_2);
extern "C" void* fn_80130234(unsigned short* param_1, unsigned short param_2) {
    fn_80166C70(param_1, param_2);
    return param_1;
}

extern "C" void* fn_80130264(void* ptr, s16 param_2) {
    if (ptr != nullptr && param_2 > 0) {
        fn_8015AB1C(ptr);
    }
    return ptr;
}

extern "C" void fn_80166B70(void*, s32);
extern "C" void fn_8015AB1C(void*);
extern "C" void fn_80166B58(void*, void*);
extern "C" void fn_801302A0(u32* p) {
    p[0] = 0;
    p[1] = 0;
}

extern "C" void fn_80166C08(void*, int);
extern "C" void* fn_801302B0(void* param_1, s16 param_2) {
    if (param_1) {
        fn_80166C08(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" void* fn_80130304(u8* p, s16 del) {
    if (p) {
        if (p + 0x58) {
            fn_80166B70(p + 0x58, 0);
        }
        if (del > 0) {
            fn_8015AB1C(p);
        }
    }
    return p;
}

extern "C" u8* fn_80130364(u8* p) {
    fn_80166B58(p + 0x58, p);
    *(u32*)(p + 0xc4) = 0;
    *(u32*)(p + 0xc8) = 0;
    *(u32*)(p + 0xcc) = 0;
    *(u32*)(p + 0xd0) = 0;
    *(u32*)(p + 0xd4) = 0;
    *(u32*)(p + 0xd8) = 0;
    *(u32*)(p + 0xdc) = 0;
    return p;
}

extern void* lbl_80247020[];
extern "C" void* fn_801303BC(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80247020;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_801315DC(void* p, s32 a, s32 b, s32 c);
extern "C" void* fn_80130874(void* arg0, s32 arg1) {
    u8* t;
    u8* n;
    u32 type;
    s32 idx;
    t = *(u8**)((u8*)arg0 + 0xe0);
    if (*(u32*)(t + 0x8) != 0) {
        n = 0;
        type = *(u32*)(t + 0x8);
        if (type == 1) {
            n = *(u8**)(t + 0x0);
            *(u32*)(t + 0x4) = 0;
            *(u32*)(t + 0x0) = 0;
            *(u32*)(t + 0x8) = *(u32*)(t + 0x8) - 1;
        } else if (type != 0) {
            n = *(u8**)(t + 0x0);
            **(u32**)(n + 0x4) = 0;
            *(u32*)(t + 0x0) = *(u32*)(n + 0x4);
            *(u32*)(t + 0x8) = *(u32*)(t + 0x8) - 1;
        }
        if (*(u8**)((u8*)arg0 + 0xd4) != 0) {
            *(u32*)(n + 0x0) = 0;
            *(u32*)(n + 0x4) = *(u32*)((u8*)arg0 + 0xd4);
            **(u32**)((u8*)arg0 + 0xd4) = (u32)n;
            *(u8**)((u8*)arg0 + 0xd4) = n;
        } else {
            *(u8**)((u8*)arg0 + 0xd8) = n;
            *(u8**)((u8*)arg0 + 0xd4) = n;
            *(u32*)(n + 0x0) = 0;
            *(u32*)(n + 0x4) = 0;
        }
        idx = *(s32*)((u8*)arg0 + 0xdc);
        *(s32*)((u8*)arg0 + 0xdc) = idx + 1;
        fn_801315DC(n + 0x8, *(s32*)(*(u8**)((u8*)arg0 + 0xe4) + 0x20), arg1, idx);
        return n + 0x8;
    }
    return 0;
}

extern "C" s32 fn_80130AE8(u8* p) {
    s16 v = *(s16*)(p + 0x104);
    if (v >= *(s16*)(**(u8***)(*(u8**)(p + 0xe8) + 0x2c) + 0x70)) {
        return 1;
    }
    if ((*(u32*)(p + 0xf4) & 2) == 0) {
        *(s16*)(p + 0x104) = v + 1;
    }
    return 0;
}

extern "C" int fn_80130B28(u8* p) {
    s32 n;
    if (*(u32*)(p + 0xf4) & 0x100) {
        return 1;
    }
    n = *(s32*)(p + 0x24);
    if (n == 0) {
        return 0;
    }
    if (n < 0) {
        *(volatile u32*)(p + 0xf4) |= 8;
        return (*(s32*)(p + 0xd0) + *(s32*)(p + 0xdc)) == 0;
    }
    if (*(u32*)(p + 0x100) >= (u32)n) {
        *(volatile u32*)(p + 0xf4) |= 8;
        if (*(u32*)(p + 0xf4) & 0x40) {
            return 0;
        }
        return (*(s32*)(p + 0xd0) + *(s32*)(p + 0xdc)) == 0;
    }
    return 0;
}

extern "C" void fn_801C622C(f32 (*)[4], f32, f32, f32);
extern "C" void fn_801C6630(f32 (*)[4], void*, void*);
extern "C" void fn_80130BC4(void* a, JGeometry::TVec3f* out) {
    u8* self = (u8*)a;
    f32 m[3][4];
    fn_801C622C(m, *(f32*)(self + 0x98), *(f32*)(self + 0x9c), *(f32*)(self + 0xa0));
    fn_801C5DA8(self + 0x68, m, m);
    f32 z;
    f32 y;
    f32 x;
    x = *(f32*)(self + 0xa4);
    y = *(f32*)(self + 0xa8);
    z = *(f32*)(self + 0xac);
    m[0][3] = x;
    m[1][3] = y;
    m[2][3] = z;
    fn_801C6630(m, self + 0xc, out);
}

extern "C" u32 fn_80130C44(u8* param_1)
{
    return *(u32*)(*(u32*)(*(u32*)(param_1 + 0xe4) + 0x20) + 0x40);
}

extern "C" u8 fn_80130C54(void* param_1) {
    void* p = *(void**)((u8*)param_1 + 0xe4);
    p = *(void**)((u8*)p + 0x20);
    return *(u8*)((u8*)p + 0x216);
}

extern "C" s32 fn_80130C64(u8* a, u32 b, s32 c)
{
    u8* r6 = *(u8**)(*(u8**)(a + 0xe4) + 0x20);
    u8* r5 = *(u8**)(r6 + 8);
    u8** tbl = *(u8***)(r5 + 8);
    u16 idx = (*(u16**)(*(u8**)(a + 0xe8) + 0x38))[b & 0xff];
    fn_801191F0(tbl[idx] + 4, c);
    return 1;
}

extern void* lbl_802470EC[];
extern "C" void* fn_80130CB8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802470EC;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" BOOL fn_801321E4(void* param_1, void* param_2) {
    u8* t = *(u8**)((u8*)param_2 + 4);
    u8* obj = **(u8***)(t + 0x24);
    s32 n = *(s16*)((u8*)param_1 + 0x82) - 1;
    s32 q = (s32)((f32)n * *(f32*)(obj + 0x3c));
    s32 a = *(s16*)((u8*)param_1 + 0x80) - q;
    if (a >= 0) {
        s32 d = obj[0x44] + 1;
        if (a == (a / d) * d) {
            return 1;
        }
    }
    return 0;
}

extern "C" f32 fn_80132264(void* param_1, u8* param_2) {
    f32 v = lbl_80301788 * *(f32*)((u8*)param_1 + 0x60);
    return v * *(f32*)(*(u8**)(*(u8**)(param_2 + 0xe4) + 0x20) + 0x144);
}

extern "C" f32 fn_80132284(void* param_1, u8* param_2) {
    f32 v = lbl_80301788 * *(f32*)((u8*)param_1 + 0x64);
    return v * *(f32*)(*(u8**)(*(u8**)(param_2 + 0xe4) + 0x20) + 0x148);
}

extern "C" void fn_801323DC(u32 param_1, u32 param_2, f32* param_3) {
    f32* a = lbl_802F0BC0[(param_1 >> 5) & 0x7FF];
    f32* b = lbl_802F0BC0[(param_2 >> 5) & 0x7FF];
    f32 zero = lbl_80301794;
    f32 sA = a[0];
    f32 cA = a[1];
    f32 sB = b[0];
    f32 cB = b[1];
    param_3[0] = cA * cB;
    param_3[1] = -sB;
    param_3[2] = sA * cB;
    param_3[4] = cA * sB;
    param_3[5] = cB;
    param_3[6] = sA * sB;
    param_3[8] = -sA;
    param_3[10] = cA;
    param_3[11] = zero;
    param_3[9] = zero;
    param_3[7] = zero;
    param_3[3] = zero;
}

extern "C" void fn_80132450(s16 a, s16 b, s16 c, void* out) {
    f32* m = (f32*)out;
    f32 sy = lbl_802F0BC0[(u16)b >> 3][0];
    f32 cy = lbl_802F0BC0[(u16)b >> 3][1];
    f32 sz = lbl_802F0BC0[(u16)c >> 3][0];
    f32 cz = lbl_802F0BC0[(u16)c >> 3][1];
    f32 sx = lbl_802F0BC0[(u16)a >> 3][0];
    f32 cx = lbl_802F0BC0[(u16)a >> 3][1];
    m[0] = cy * cz;
    m[4] = cy * sz;
    m[8] = -sy;
    m[9] = sx * cy;
    m[10] = cx * cy;
    m[1] = sx * cz * sy - cx * sz;
    m[6] = cx * sz * sy - sx * cz;
    m[2] = sx * sz + cx * cz * sy;
    m[5] = cx * cz + sx * sz * sy;
    m[11] = lbl_80301794;
    m[7] = lbl_80301794;
    m[3] = lbl_80301794;
}

extern "C" void fn_80132524(void* a, void* b, void* c, void* d);
extern "C" void fn_801324FC(void* a, void* b, void* c) {
    struct Vec3f buf;
    fn_80132524(a, b, &buf, c);
}

extern "C" f32 fn_801326B0(u16 arg0, void* arg1, f32 farg0) {
    f32* t = (f32*)arg1;
    s32 n;
    s32 mid;
    if (farg0 < t[0]) {
        return t[1];
    }
    n = arg0;
    if (t[(n - 1) * 4] <= farg0) {
        return t[(n - 1) * 4 + 1];
    }
    while (n > 1) {
        mid = n / 2;
        if (farg0 >= t[mid * 4]) {
            t += mid * 4;
            n -= mid;
        } else {
            n = mid;
        }
    }
    f32 d = farg0 - t[0];
    f32 u = d / (t[4] - t[0]);
    f32 uu = u * u;
    f32 v = uu - u;
    f32 w = ((u + u) * v) - uu;
    f32 a = (t[1] - t[5]) * w + t[1];
    return a - d * ((u * t[3]) - ((t[6] * v) + ((t[3] * v) + t[3])));
}

extern "C" void* fn_80132778(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_802911E4;
        fn_801328F8(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" u32 fn_801327D8(void) {
    return 3;
}

extern "C" BOOL fn_801327E0(void) {
    return TRUE;
}

extern "C" void fn_801327E8(void) {
}

extern "C" float lbl_803017A0;
extern "C" float fn_801327EC(void) {
    return lbl_803017A0;
}

extern "C" void fn_801327F4(void) {
}

extern f32 lbl_802FEAB4;
extern "C" f32 fn_801327F8(void) {
    f32 temp = lbl_802FEAB4;
    return temp;
}

extern "C" void fn_80132804(void) {
}

extern "C" float lbl_803017A0;
extern "C" float fn_80132808(void) {
    return lbl_803017A0;
}

extern "C" void fn_80132810(void) {
}

extern "C" float fn_80132814(void) {
    return lbl_803017A0;
}

extern "C" void fn_8013281C(void) {
}

extern "C" void fn_80132820(void)
{
    return;
}

extern "C" void fn_80132824(void)
{
    return;
}

extern "C" BOOL fn_80132828(void)
{
    return TRUE;
}

extern "C" void fn_80132830(void)
{
    return;
}

extern "C" void fn_80132834(void) {
}

extern "C" void fn_80132838(void) {
}

extern "C" void fn_8013283C(void) {
}

extern "C" void fn_80132840(void) {
}

extern "C" void fn_80132844(void) {
}

extern "C" void fn_80132848(void) {
}

extern "C" float fn_8013284C(void) {
    return lbl_803017A0;
}

extern "C" void fn_80132854(void) {
}

extern char lbl_802912A4[];
extern "C" void* fn_80132858(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_802912A4;
        fn_801328F8(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern "C" int fn_801328B8(void) {
    return 5;
}

extern "C" BOOL fn_801328C0(void)
{
	return TRUE;
}

extern "C" void fn_801328C8(void) {
}

extern void* lbl_803017A8;
extern "C" void* fn_801328CC(void)
{
	return lbl_803017A8;
}

extern "C" void fn_801328D4(void) {
}

extern "C" void fn_801328D8(void) {
}

extern "C" void fn_801328DC(void)
{
}

extern "C" void fn_801328E0(void)
{
}

extern "C" void fn_801328E4(void) {
}

extern "C" void fn_801328E8(void) {
}

extern "C" void fn_801328EC(void) {
}

extern "C" void fn_801328F0(void) {
}

extern "C" void fn_801328F4(void) {
}

extern void* lbl_80291320[];
extern "C" void* fn_801328F8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80291320;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" int fn_80132940()
{
	return 0;
}

extern "C" void fn_80132948(void) {
}

extern "C" int fn_8013294C()
{
	return 0;
}

extern "C" void fn_80132954(void) {
}

extern "C" int fn_80132958()
{
	return 0;
}

extern "C" void fn_80132960(void) {
}

extern "C" void fn_80132964(void) {
}

extern "C" void fn_80132968(void)
{
}

extern "C" void fn_8013296C(void)
{
}

extern "C" int fn_80132970(void)
{
	return -1;
}

extern "C" int fn_80132978(void* param_1, void* param_2, f32* param_3) {
    f32 val = lbl_803017B0;
    param_3[0] = val;
    param_3[1] = val;
    param_3[2] = val;
    param_3[3] = val;
    param_3[4] = val;
    param_3[5] = val;
    param_3[6] = val;
    param_3[7] = val;
    param_3[8] = val;
    param_3[9] = val;
    param_3[10] = val;
    param_3[11] = val;
    return 0;
}

extern char lbl_8029138C[];
extern "C" void fn_8013AB60(void* self);
extern "C" void fn_80139830(void* self);
extern "C" void fn_80132B3C(void* self, f32 f, void* table);
extern "C" void fn_80132BBC(void* self, f32 f, void* table);
extern f32 lbl_803017B8;
extern char lbl_802914AC[];
extern char lbl_80201E40[];
extern float lbl_803017B8;
extern f32 lbl_803017B8;
extern "C" char lbl_8029138C[];
#pragma dont_inline on
extern "C" void* fn_801329B4(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_8029138C;
        fn_801328F8(param_1, 0);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}
#pragma dont_inline reset
extern "C" BOOL fn_80132A14(void)
{
    return TRUE;
}

extern "C" BOOL fn_80132A1C(void)
{
    return TRUE;
}

extern "C" int fn_80132A24(void)
{
    return 0;
}

extern "C" void fn_80132A2C(void)
{
}

extern "C" int fn_80132A30()
{
	return 0;
}

extern "C" void fn_80132A38(void) {
}

extern "C" void* fn_80132A3C(void* param_1) {
    void* local[3];
    fn_8013AB60(param_1);
    *(void**)param_1 = (void*)lbl_802914AC;
    fn_80139830((u8*)param_1 + 0x60);
    *((u8*)param_1 + 0x74) = 0;
    *((u8*)param_1 + 0x75) = 0;
    f32 f = lbl_803017B8;
    local[0] = ((void**)lbl_80201E40)[0];
    local[1] = ((void**)lbl_80201E40)[1];
    local[2] = ((void**)lbl_80201E40)[2];
    fn_80132B3C(param_1, f, local);
    fn_80132BBC(param_1, lbl_803017B8, local);
    return param_1;
}

extern "C" void fn_80139860(u8* p, s16 del);
extern "C" void fn_8013AC50(void* p, s16 v);
extern "C" void* fn_80132ACC(void* p, s16 param_2) {
    if (p != nullptr) {
        *(void**)p = lbl_802914AC;
        fn_80139860((u8*)p + 0x60, -1);
        fn_8013AC50(p, 0);
        if (param_2 > 0) {
            fn_8015AB1C(p);
        }
    }
    return p;
}

extern "C" void fn_801C5F6C(void* dst, s32 axis, f32 v);
extern "C" void fn_801C61E0(void* tmp, void* dst, f32 x, f32 y, f32 z);
extern f32 lbl_803017BC;
extern "C" void fn_80132B3C(void* self, f32 f, void* table) {
    u8 tmp[0x30];
    f32* v = (f32*)table;
    *(f32*)((u8*)self + 0x78) = v[0];
    *(f32*)((u8*)self + 0x7c) = v[1];
    *(f32*)((u8*)self + 0x80) = v[2];
    *(f32*)((u8*)self + 0x90) = f;
    fn_801C5F6C(tmp, 0x79, lbl_803017BC * f);
    fn_801C61E0(tmp, (u8*)self + 0x98, v[0], v[1], v[2]);
}

extern void* lbl_8020597C[];
extern "C" void* fn_80132C50(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8020597C;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_80167A18(void* a, void* b, void* c, void* d);
extern "C" void fn_80132D1C(u32 p, u32 q) {
    u32 arr[6];
    u32 v = p + 8;
    arr[1] = v;
    arr[0] = v;
    arr[5] = v;
    arr[4] = v;
    arr[3] = v;
    fn_80167A18(&arr[2], (void*)(p + 4), &arr[3], (void*)(q + 4));
}

extern "C" u8* fn_80132E20(u8* p, u8* a) {
    fn_8013AF98(p, a);
    *(void**)p = lbl_80291450;
    fn_80139DEC(p + 8, a + 0x60);
    return p;
}

extern "C" int fn_801E3C54(void*, const void*, int);
extern "C" void fn_80139E0C(void*, int);
extern "C" void fn_8013AFB8(void*, int);
extern "C" void* fn_80132E74(void* p, s16 param_2) {
    if (p != nullptr) {
        *(void**)p = lbl_80291450;
        fn_80139E0C((u8*)p + 8, -1);
        fn_8013AFB8(p, 0);
        if (param_2 > 0) {
            fn_8015AB1C(p);
        }
    }
    return p;
}

extern char lbl_803017C0[];
extern char lbl_803017C0[8];
extern "C" BOOL fn_80132EE4(void* p, u8** q) {
    u8* d = *q + 0x10;
    if (fn_801E3C54(d, lbl_803017C0, 8) != 0) return FALSE;
    u16 n = *(u16*)(d + 0xe);
    if (n < 2) return FALSE;
    return n <= 4;
}

extern "C" void fn_80132FA0(u8* p, u8** q, u32 flags);
extern "C" void fn_8013B140(void);
extern "C" void fn_80132F5C(u8* param_1, u8** param_2, u32 param_3) {
    s32* obj = (s32*)param_2[0];
    if (obj[1] == 0x4a465642) {
        fn_80132FA0(param_1, param_2, param_3);
    } else {
        fn_8013B140();
    }
}

extern "C" void fn_801678C8(void*, void*, u32);
extern "C" void fn_80132FA0(u8* p, u8** q, u32 flags) {
    u8* data = *q + 8;
    u32 f = flags & 0xf;
    if (flags & 0x10) f |= 0x10;
    if (flags & 0x20) f |= 0x20;
    if (flags & 0x40) f |= 0x40;
    u8* local = data;
    fn_801678C8(p + 8, &local, f);
}

extern void* lbl_80292694[];
extern "C" void* fn_80133414(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80292694;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_8013345C(f32* p)
{
    p[0] = p[3];
    ((s32*)p)[2] = 0;
}

extern "C" void fn_80133470(u8* p, f64 t) {
    *(f32*)p = *(f32*)(p + 0xc) * ((f64)*(u32*)(p + 4) * t);
}

extern "C" void fn_801334AC(Unk801334AC* p, f32 scale) {
    p->val = p->obj->vf5((f64)p->count * scale);
}

extern void* lbl_80292684[];
extern "C" void* fn_80133510(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80292684;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80292694;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_8013356C(void) {}

extern "C" void fn_80133570(void) {}

extern "C" void fn_80133574(void) {}

extern "C" void fn_80133578(void) {}

extern "C" void fn_8013357C(void) {}

extern "C" void fn_80133580(void) {}

extern "C" void fn_801338F8(u8* p, void* unused, int i);
extern "C" void fn_80133910(u8* p, void* unused, int i, f32* v);
extern "C" void fn_8013393C(u8* p, void* unused, int i, f32* v);
extern "C" void fn_80133968(u8* p, u8* q, int i, void* a, void* b);
extern "C" void fn_801339D8(u8* p, u8* q, int i, void** a);
typedef void (*DispatchFn)(void*, void*, int, void*, void*);
extern "C" void fn_80133584(void* a, void* b, int c, unsigned int type, void* d, void* e) {
    DispatchFn fn;
    switch (type) {
    case 0: fn = (DispatchFn)fn_801338F8; break;
    case 1: fn = (DispatchFn)fn_80133910; break;
    case 2: fn = (DispatchFn)fn_8013393C; break;
    case 3: fn = (DispatchFn)fn_80133968; break;
    case 4: fn = (DispatchFn)fn_801339D8; break;
    case 18:
    default: return;
    }
    fn(a, b, c, d, e);
}

extern "C" void fn_80133624(u8* self, int* idx, f32* vals) {
    int i0 = idx[0];
    int i1 = idx[1];
    int i2 = idx[2];
    u8* e;
    e = *(u8**)(self + 4) + i0 * 0x14;
    *(void**)(e + 8) = (void*)fn_8013345C;
    *(u32*)(e + 4) = 0;
    *(f32*)(e + 0xC) = vals[0];
    e = *(u8**)(self + 4) + i1 * 0x14;
    *(void**)(e + 8) = (void*)fn_8013345C;
    *(u32*)(e + 4) = 0;
    *(f32*)(e + 0xC) = vals[1];
    e = *(u8**)(self + 4) + i2 * 0x14;
    *(void**)(e + 8) = (void*)fn_8013345C;
    *(u32*)(e + 4) = 0;
    *(f32*)(e + 0xC) = vals[2];
}

extern "C" void fn_80133694(int param_1, f32* param_2, int* param_3) {
    int i1 = param_3[1];
    char* base = *(char**)(param_1 + 4);
    int i2 = param_3[2];
    param_2[0] = *(f32*)(base + param_3[0] * 0x14);
    param_2[1] = *(f32*)(base + i1 * 0x14);
    param_2[2] = *(f32*)(base + i2 * 0x14);
}

extern "C" void fn_801336CC(u8* self, s32* idx, u8* vals) {
    u8 v3 = vals[3];
    u8 v2 = vals[2];
    u8 v1 = vals[1];
    u8 v0 = vals[0];
    fn_80133624_set(self, idx[0], (f32)v0);
    fn_80133624_set(self, idx[1], (f32)v1);
    fn_80133624_set(self, idx[2], (f32)v2);
    fn_80133624_set(self, idx[3], (f32)v3);
}

extern "C" void fn_801338F8(u8* p, void* unused, int i) {
    *(u32*)(*(u8**)(p + 4) + i * 0x14 + 8) = 0;
}

extern "C" void fn_80133910(u8* p, void* unused, int i, f32* v) {
    f32 f = *v;
    u8* e = *(u8**)(p + 4) + i * 0x14;
    *(void**)(e + 8) = (void*)fn_8013345C;
    *(u32*)(e + 4) = 0;
    *(f32*)(e + 0xc) = f;
}

extern "C" void fn_80133470(u8* p, f64 t);
extern "C" void fn_8013393C(u8* p, void* unused, int i, f32* v) {
    f32 f = *v;
    u8* e = *(u8**)(p + 4) + i * 0x14;
    *(void**)(e + 8) = (void*)fn_80133470;
    *(u32*)(e + 4) = 0;
    *(f32*)(e + 0xc) = f;
}

extern "C" void fn_80133968(u8* p, u8* q, int i, void* a, void* b) {
    u8* e = *(u8**)(p + 4) + i * 0x14;
    u8* r = (u8*)fn_80139950(*(u8**)(q + 0x14) + 0x60, a, b);
    u32 v;
    if (r == 0) {
        v = 0;
    } else {
        v = *(u32*)(r + 0x14);
    }
    *(void**)(e + 8) = (void*)fn_801334AC;
    *(u32*)(e + 4) = 0;
    *(u32*)(e + 0xc) = v;
}

extern "C" void* fn_801399E4(void*, void*);
extern "C" void fn_801339D8(u8* p, u8* q, int i, void** a) {
    u8* e = *(u8**)(p + 4) + i * 0x14;
    u8* r = (u8*)fn_801399E4(*(u8**)(q + 0x14) + 0x60, *a);
    u32 v;
    if (r == 0) {
        v = 0;
    } else {
        v = *(u32*)(r + 0x14);
    }
    *(void**)(e + 8) = (void*)fn_801334AC;
    *(u32*)(e + 4) = 0;
    *(u32*)(e + 0xc) = v;
}

extern "C" void fn_80133A44(u8* p) {
    Unk80133A44Listener* obj = *(Unk80133A44Listener**)(p + 0x34);
    if (obj != 0) {
        obj->vf4(p);
    }
}

extern "C" void fn_80133A80(u8* p) {
    Unk80133A44Listener* obj = *(Unk80133A44Listener**)(p + 0x34);
    if (obj != 0) {
        obj->vf5(p);
    }
}

#pragma use_lmw_stmw off
extern "C" void fn_80133ABC(void* param_1, u32 param_2)
{
    Unk80133ABCMgr* arr = *(Unk80133ABCMgr**)((u8*)param_1 + 0x34);
    if (arr != 0) {
        Unk80133ABCItem* end;
        Unk80133ABCItem* cur;
        Unk80133ABCItem* e;
        f64 f;
        e = arr->m4;
        end = (Unk80133ABCItem*)((u8*)e + arr->m8 * 0x14);
        f = *(f64*)(*(u8**)((u8*)param_1 + 0x14) + 0x58);
        while (e != end) {
            s32 v = e->m4;
            cur = e;
            e = (Unk80133ABCItem*)((u8*)e + 0x14);
            if ((u32)(-1 - v) <= param_2) {
                cur->m4 = -1;
            } else {
                cur->m4 = v + param_2;
            }
            if (cur->m8 != 0) {
                cur->m8(cur, f);
                cur->m10->vf0(arr, cur->m0);
            }
        }
        arr->vf4(param_1, param_2);
    }
}
#pragma use_lmw_stmw reset
extern "C" void fn_80133BB0(int param_1, void* param_2, void* param_3, void* param_4, void* param_5) {
    int* obj = *(int**)(param_1 + 0x34);
    if (obj != 0) {
        int** vftbl = *(int***)obj;
        void (*method)(int, int, void*, void*, void*, void*) = (void (*)(int, int, void*, void*, void*, void*))vftbl[7];
        method(param_1, (int)obj, param_2, param_3, param_4, param_5);
    }
}

extern void* lbl_8029259C[];
extern void* lbl_8029260C[];
extern "C" void* fn_80133C0C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029259C;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029260C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" u8* fn_80133C68(u8* p, void* a, void* b) {
    fn_8013A57C();
    *(void***)(p + 8) = lbl_802925EC;
    *(void**)(p + 0x34) = b;
    *(void***)(p + 8) = lbl_80292558;
    return p;
}

extern void* lbl_80292500[];
extern void* lbl_8029260C[];
extern "C" void* fn_8013414C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80292500;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029260C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_802924B4[];
extern "C" u8* fn_801341A8(u8* p, void* a, void* b) {
    fn_8013A57C();
    *(void**)(p + 8) = &lbl_802925EC;
    *(void**)(p + 0x34) = b;
    *(void**)(p + 8) = &lbl_802924B4;
    return p;
}

extern void* lbl_80292438[];
extern "C" void* fn_801343E4(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80292438;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029260C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_802923F0[];
extern "C" u8* fn_80134440(u8* p, void* a, void* b) {
    fn_8013A57C();
    *(void**)(p + 8) = &lbl_802925EC;
    *(void**)(p + 0x34) = b;
    *(void**)(p + 8) = &lbl_802923F0;
    return p;
}

extern void* lbl_80292398[];
extern "C" void* fn_80134898(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80292398;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029260C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80292354[];
extern "C" u8* fn_801348F4(u8* p, void* a, void* b) {
    fn_8013A57C();
    *(void**)(p + 8) = &lbl_802925EC;
    *(void**)(p + 0x34) = b;
    *(void**)(p + 8) = &lbl_80292354;
    return p;
}

extern void* lbl_802922F4[];
extern "C" void* fn_80134B3C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_802922F4;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029260C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_802922B0[];
extern "C" u8* fn_80134B98(u8* p, void* a, void* b) {
    fn_8013A57C();
    *(void**)(p + 8) = &lbl_802925EC;
    *(void**)(p + 0x34) = b;
    *(void**)(p + 8) = &lbl_802922B0;
    return p;
}

extern void* lbl_80292070[];
struct fn_80135858_Obj {
    virtual void Release(int);
    virtual void fn_0C(int);
    virtual void fn_10(int);
    virtual void fn_14(int);
};
extern void* lbl_802026C0;
extern void* lbl_80291BB4;
extern "C" void fn_8013A5EC(int ptr, int param);
extern "C" void fn_8013A57C(void);
extern "C" void fn_801E10DC(int ptr, uint param);
extern "C" int fn_80135858(int param_1, s16 param_2) {
    if (param_1 != 0) {
        *(void**)(param_1 + 0x8) = lbl_80292070;
        if (param_1 != 0) {
            *(void**)(param_1 + 0x8) = lbl_802925EC;
            fn_80135858_Obj* obj = *(fn_80135858_Obj**)(param_1 + 0x34);
            if (obj != 0) {
                obj->Release(1);
            }
            fn_8013A5EC(param_1, 0);
        }
        if (param_2 > 0) {
            fn_8015AB1C((void*)param_1);
        }
    }
    return param_1;
}

extern void* lbl_80292148[];
extern "C" int fn_801358EC(int param_1, s16 param_2) {
    if (param_1 != 0) {
        *(void**)(param_1 + 0x8) = lbl_80292148;
        if (param_1 != 0) {
            *(void**)(param_1 + 0x8) = lbl_802925EC;
            fn_80135858_Obj* obj = *(fn_80135858_Obj**)(param_1 + 0x34);
            if (obj != 0) {
                obj->Release(1);
            }
            fn_8013A5EC(param_1, 0);
        }
        if (param_2 > 0) {
            fn_8015AB1C((void*)param_1);
        }
    }
    return param_1;
}

extern void* lbl_8029220C[];
extern "C" int fn_80135980(int param_1, s16 param_2) {
    if (param_1 != 0) {
        *(void**)(param_1 + 0x8) = lbl_8029220C;
        if (param_1 != 0) {
            *(void**)(param_1 + 0x8) = lbl_802925EC;
            fn_80135858_Obj* obj = *(fn_80135858_Obj**)(param_1 + 0x34);
            if (obj != 0) {
                obj->Release(1);
            }
            fn_8013A5EC(param_1, 0);
        }
        if (param_2 > 0) {
            fn_8015AB1C((void*)param_1);
        }
    }
    return param_1;
}

extern "C" int fn_80135A14(int param_1, s16 param_2) {
    if (param_1 != 0) {
        *(void**)(param_1 + 0x8) = lbl_802922B0;
        if (param_1 != 0) {
            *(void**)(param_1 + 0x8) = lbl_802925EC;
            fn_80135858_Obj* obj = *(fn_80135858_Obj**)(param_1 + 0x34);
            if (obj != 0) {
                obj->Release(1);
            }
            fn_8013A5EC(param_1, 0);
        }
        if (param_2 > 0) {
            fn_8015AB1C((void*)param_1);
        }
    }
    return param_1;
}

extern "C" int fn_80135AA8(int param_1, s16 param_2) {
    if (param_1 != 0) {
        *(void**)(param_1 + 0x8) = lbl_80292354;
        if (param_1 != 0) {
            *(void**)(param_1 + 0x8) = lbl_802925EC;
            fn_80135858_Obj* obj = *(fn_80135858_Obj**)(param_1 + 0x34);
            if (obj != 0) {
                obj->Release(1);
            }
            fn_8013A5EC(param_1, 0);
        }
        if (param_2 > 0) {
            fn_8015AB1C((void*)param_1);
        }
    }
    return param_1;
}

extern "C" int fn_80135B3C(int param_1, s16 param_2) {
    if (param_1 != 0) {
        *(void**)(param_1 + 0x8) = lbl_802923F0;
        if (param_1 != 0) {
            *(void**)(param_1 + 0x8) = lbl_802925EC;
            fn_80135858_Obj* obj = *(fn_80135858_Obj**)(param_1 + 0x34);
            if (obj != 0) {
                obj->Release(1);
            }
            fn_8013A5EC(param_1, 0);
        }
        if (param_2 > 0) {
            fn_8015AB1C((void*)param_1);
        }
    }
    return param_1;
}

extern "C" int fn_80135BD0(int param_1, s16 param_2) {
    if (param_1 != 0) {
        *(void**)(param_1 + 0x8) = lbl_802924B4;
        if (param_1 != 0) {
            *(void**)(param_1 + 0x8) = lbl_802925EC;
            fn_80135858_Obj* obj = *(fn_80135858_Obj**)(param_1 + 0x34);
            if (obj != 0) {
                obj->Release(1);
            }
            fn_8013A5EC(param_1, 0);
        }
        if (param_2 > 0) {
            fn_8015AB1C((void*)param_1);
        }
    }
    return param_1;
}

extern "C" int fn_80135C64(int param_1, s16 param_2) {
    if (param_1 != 0) {
        *(void**)(param_1 + 0x8) = lbl_80292558;
        if (param_1 != 0) {
            *(void**)(param_1 + 0x8) = lbl_802925EC;
            fn_80135858_Obj* obj = *(fn_80135858_Obj**)(param_1 + 0x34);
            if (obj != 0) {
                obj->Release(1);
            }
            fn_8013A5EC(param_1, 0);
        }
        if (param_2 > 0) {
            fn_8015AB1C((void*)param_1);
        }
    }
    return param_1;
}

