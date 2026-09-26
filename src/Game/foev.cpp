// TU 0x802ef76c-0x802f032c (actor FOEV).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// ---- Ltev_SetupLightTransition.cpp ----
// Ltev_SetupLightTransition - LTEV: light-transition setup, vtable extension slot (0x9C).
// Two modes selected by whether the final param is 0: mode A (mode!=0)
// stores 5 incoming params as the "target" endpoint fields and computes
// per-component step counts; mode B (mode==0) stores the params as the
// "start" endpoint fields instead.
//
// Ltev_EmptyHook - LTEV: empty no-op override.
extern "C" {

void Ltev_SetupLightTransition(void* thisPtr, s32 p1, s32 p2, s32 p3, s32 p4, s32 p5, s32 mode) {
	char* p = (char*)thisPtr;
	*(s32*)(p + 0x230) = mode;
	if (mode == 0) {
		*(s32*)(p + 0x25c) = p1;
		*(s32*)(p + 0x260) = p2;
		*(s32*)(p + 0x264) = p3;
		*(s32*)(p + 0x258) = p4;
		*(s32*)(p + 0x26c) = p5;
		*(s32*)(p + 0x270) = (*(s32*)(p + 0x25c) - *(s32*)(p + 0x24c)) / 4;
		*(s32*)(p + 0x274) = (*(s32*)(p + 0x260) - *(s32*)(p + 0x250)) / 4;
		*(s32*)(p + 0x278) = (*(s32*)(p + 0x264) - *(s32*)(p + 0x254)) / 4;
		if (*(s32*)(p + 0x268) < *(s32*)(p + 0x26c)) {
			*(s32*)(p + 0x230) = 1;
		}
		return;
	}
	*(s32*)(p + 0x24c) = p1;
	*(s32*)(p + 0x250) = p2;
	*(s32*)(p + 0x254) = p3;
	*(s32*)(p + 0x258) = p4;
	*(s32*)(p + 0x268) = p5;
}

void Ltev_EmptyHook(void) {}

}

// ---- Ltev_dtor_802EFB9C.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804AA4F0[];

extern "C" void* fn_802EFB9C(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804AA4F0;
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}


extern "C" void fn_80128C58(u8 a);
extern "C" void fn_8013A884(u32* color);
extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802D800C(void* mgr, s32 a);
extern "C" void fn_80458FF0(void* mgr, s32 a, s32 b, s32 c);
extern void* lbl_8053AF80;

class FoevVis {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual u8 isVisible();
};

struct FoevRGBA { u8 r, g, b, a; };

struct Foev {
    u8 pad0[0x90];
    u32 m90;
    u8 pad94[0x230 - 0x94];
    s32 state;
    f32 m234;
    f32 m238;
    f32 m23c;
    s32 m240;
    s32 m244;
    FoevRGBA col;
    s32 r, g, b, a;
    s32 tr, tg, tb;
    s32 level;
    s32 target;
    s32 dr, dg, db;
    s32 m27c;

    void apply() {
        fn_80128C58(level);
        u32 c = (r << 24) | (g << 16) | (b << 8) | a;
        fn_8013A884(&c);
    }
    void stepColor() {
        if (r > tr) {
            r += dr;
        } else {
            r = tr;
        }
        if (g > tg) {
            g += dg;
        } else {
            g = tg;
        }
        if (b > tb) {
            b += db;
        } else {
            b = tb;
        }
    }
    void finish() {
        level = target;
        r = tr;
        g = tg;
        b = tb;
        state = 4;
    }
};

extern "C" void fn_802EF80C(Foev* f) {
    switch (f->state) {
    case 0:
        f->level -= 4;
        f->stepColor();
        if (f->level <= f->target) {
            f->finish();
        }
        f->apply();
        return;
    case 1:
        f->level += 4;
        f->stepColor();
        if (f->level >= f->target) {
            f->finish();
        }
        f->apply();
        return;
    case 2:
        f->level += 4;
        if (f->level >= f->target) {
            f->level = f->target;
            f->state = 4;
            if (f->m244 == 0x10 && !fn_802D800C(fn_802D6A9C(), f->m240)) {
                fn_80458FF0(lbl_8053AF80, 0x1000021, 0, 0);
            }
        }
        f->apply();
        return;
    case 3:
    default:
        f->apply();
        return;
    case 5:
        if ((f->m90 >> 27) == 0 || ((FoevVis*)f)->isVisible()) {
            f->state = 2;
        }
        f->apply();
        return;
    }
}


// Shared JAudio pool __sinit (docs/game/sinit_pools.md). Drop the ESD
// macros/typedefs that clash with the JSystem headers first.
#undef ALIGN_NEXT
#undef ALIGN_PREV
#undef ARRAY_SIZE
#undef ASM
#undef ATTRIBUTE_ALIGN
#undef IS_ALIGNED
#undef IS_NOT_ALIGNED
#undef MACROS_H
#undef MAX
#undef MIN
#undef NULL
#define NULL 0
#define unknown jsys_unknown
#include "JSystem/JAudio/JASFakeMatchFSA.h"
#include "JSystem/JGeometry/Vec.h"

class FoevV {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void setup(s32 r, s32 g, s32 b, s32 a, s32 lv, s32 mode);
};

struct FoevPos { f32 x, y, z; };

extern "C" u8 fn_802DEBA0(void* p);
extern "C" void fn_8018330C(FoevRGBA* out);
extern "C" u8 fn_801B7550(void);
extern char* lbl_8053AB10;
extern const f32 lbl_80541430;

extern "C" void fn_802EFBFC(Foev* f) {
    if (!fn_802DEBA0(f)) {
        f->m244 = f->m90 & 0xff;
    } else {
        f->m244 = -1;
    }
    f->m240 = (f->m90 >> 22) & 0x1f;
    f->state = 0;
    FoevRGBA c;
    fn_8018330C(&c);
    f->col = c;
    f->r = *(u32*)&f->col >> 24;
    f->g = (*(u32*)&f->col >> 16) & 0xff;
    f->b = (*(u32*)&f->col >> 8) & 0xff;
    f->a = *(u32*)&f->col & 0xff;
    f->level = fn_801B7550();
    char* cam = *(char**)(lbl_8053AB10 + 0x24);
    f->m234 = -*(f32*)(cam + 0x10);
    f->m238 = -*(f32*)(cam + 0x20);
    f->m23c = lbl_80541430;
    switch ((u32)f->m244) {
    case 0:
        ((FoevV*)f)->setup(0xd2, 0xc8, 0xaa, 0x0, 0xa, 4);
        break;
    case 1:
        ((FoevV*)f)->setup(0x96, 0xc8, 0xff, 0x0, 0xa, 4);
        break;
    case 2:
        ((FoevV*)f)->setup(0xff, 0xc8, 0xa0, 0x0, 0x82, 0);
        break;
    case 3:
        ((FoevV*)f)->setup(0xff, 0xc8, 0xa0, 0x0, 0xa, 4);
        break;
    case 4:
        ((FoevV*)f)->setup(0xff, 0xc8, 0xa0, 0x0, 0xc8, 4);
        break;
    case 5:
        ((FoevV*)f)->setup(0xff, 0xc8, 0xa0, 0x0, 0xc8, 0);
        break;
    case 6:
        ((FoevV*)f)->setup(0xc8, 0xd2, 0xff, 0x0, 0xa, 4);
        break;
    case 7:
        ((FoevV*)f)->setup(0xc8, 0xd2, 0xff, 0x0, 0xc8, 4);
        break;
    case 8:
        ((FoevV*)f)->setup(0xc8, 0xd2, 0xff, 0x0, 0xc8, 0);
        break;
    case 9:
        ((FoevV*)f)->setup(0x96, 0xc8, 0xff, 0x0, 0xa, 4);
        break;
    case 10:
        ((FoevV*)f)->setup(0x96, 0xc8, 0xff, 0x0, 0x82, 4);
        break;
    case 11:
        ((FoevV*)f)->setup(0x96, 0xc8, 0xff, 0x0, 0x82, 0);
        break;
    case 12:
        ((FoevV*)f)->setup(0xd2, 0xff, 0xff, 0x19, 0xdc, 4);
        break;
    case 13:
        ((FoevV*)f)->setup(0xff, 0x80, 0xff, 0x0, 0xa, 4);
        break;
    case 14:
        ((FoevV*)f)->setup(0xff, 0x80, 0xff, 0x0, 0xc8, 4);
        break;
    case 15:
        ((FoevV*)f)->setup(0xff, 0x80, 0xff, 0x0, 0x82, 0);
        f->state = 4;
        break;
    case 16:
        ((FoevV*)f)->setup(0xff, 0xc8, 0xa0, 0x0, 0xa, 4);
        f->target = 200;
        f->state = 5;
        break;
    case 17:
        ((FoevV*)f)->setup(0xff, 0xff, 0xff, 0x0, 0x80, 4);
        break;
    default:
        f->state = 4;
        break;
    }
    f->apply();
    JGeometry::TVec3<f32> pos(*(JGeometry::TVec3<f32>*)((char*)f + 0xc));
    ((FoevVis*)f)->v03();
    *(JGeometry::TVec3<f32>*)((char*)f + 0xc) = pos;
    *((u8*)f + 0x11f) = 1;
}

