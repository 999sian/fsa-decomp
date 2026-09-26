// TU 0x80210d90-0x80212ac0 (actor RUSA).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"

// ---- fn_80212760_dtor.cpp ----
extern "C" void* RusaRegistry_GetOrInit();
extern "C" void RusaRegistry_Unregister(void* registry, s32 id);
extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A6270[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

extern "C" void* fn_80212760(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A6270;
        void* registry = RusaRegistry_GetOrInit();
        RusaRegistry_Unregister(registry, *(s32*)(p + 0x198));
        if (this_ != 0) {
            *(void**)p = lbl_804A4808;
            if (p + 0x270 != 0) {
                if (p + 0x294 != 0) {
                    *(void**)(p + 0x294) = lbl_8049CC34;
                }
            }
            __dt__5ActorFv(this_, 0);
        }
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}


extern const f32 lbl_8053FAF8;
extern const f32 lbl_8053FAFC;
extern const f32 lbl_8053FB00;
extern const f32 lbl_8053FB14;
extern void* lbl_804A6270[];
extern "C" void fn_802110A8(char* p);
extern "C" void fn_801D0F40(char* p);
extern "C" void fn_800FE3EC(char* a, u8 b, JGeometry::TVec3f pos, void* c);

extern "C" BOOL fn_80211000(char* p, const f32* v) {
    BOOL r = FALSE;
    if (v[2] <= lbl_8053FAF8 && *(s32*)(p + 0x248) != 0) {
        f32 rad = lbl_8053FAFC * (lbl_8053FB00 * *(f32*)(p + 0x54));
        f32 dx = v[0] - *(f32*)(p + 0xc);
        f32 dy = v[1] - *(f32*)(p + 0x10);
        f32 dx2 = dx * dx;
        f32 dy2 = dy * dy;
        f32 r2 = rad * rad;
        if (dx2 + dy2 <= r2) {
            r = TRUE;
        }
    }
    return r;
}

extern "C" void fn_80211078(char* p) {
    f32 z = lbl_8053FAF8;
    *(f32*)(p + 0x3c) = z;
    *(f32*)(p + 0x40) = z;
    *(f32*)(p + 0x44) = z;
    fn_802110A8(p);
}

extern "C" void fn_80212170(char* p) {
    if ((*(u32*)(p + 0x230) & 0x8000) && *(u8*)(p + 0x2bc) != 0) {
        fn_800FE3EC(p + 0x2c0, *(u8*)(p + 0x2bc), *(JGeometry::TVec3f*)(p + 0xc), *(void**)(p + 0x4));
    }
}

extern "C" char* fn_80212800(char* p) {
    fn_801D0F40(p);
    *(void**)p = lbl_804A6270;
    *(s32*)(p + 0x2a8) = 0;
    *(s32*)(p + 0x2ac) = 0;
    *(s32*)(p + 0x2b0) = 0;
    *(s32*)(p + 0x2b4) = 0;
    *(s32*)(p + 0x2b8) = 0;
    *(u8*)(p + 0x2bc) = 0;
    *(s32*)(p + 0x388) = -1;
    *(s32*)(p + 0x38c) = -1;
    *(f32*)(p + 0x390) = lbl_8053FAF8;
    *(f32*)(p + 0x394) = lbl_8053FAF8;
    *(f32*)(p + 0x398) = lbl_8053FAF8;
    *(f32*)(p + 0x39c) = lbl_8053FAF8;
    *(f32*)(p + 0x3a0) = lbl_8053FAF8;
    *(f32*)(p + 0x3a4) = lbl_8053FAF8;
    *(f32*)(p + 0x3a8) = lbl_8053FB14;
    *(s32*)(p + 0x3ac) = -1;
    *(u8*)(p + 0x3b0) = 0;
    *(u8*)(p + 0x2c2) = 0;
    *(u8*)(p + 0x2c3) = 0;
    *(u8*)(p + 0x2c1) = 0;
    return p;
}

extern const f32 lbl_8053FB20;
extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F76F0(void* mgr, u32 id, void* owner, void* pos, s32 arg);
extern "C" char* fn_801F666C(void* mgr, s32 id);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D8050(void* cr, s32 id, s32 on, s32 v);
extern "C" void fn_801F3604(char* p);
extern "C" void fn_80212ECC(char* p);

extern "C" void fn_80210D90(char* p) {
    *(u32*)(p + 0x230) |= 0x20000;
    fn_801F3604(p);
    switch (*(s32*)(p + 0x248)) {
    case 1: {
        s32 id = *(s32*)(p + 0x388);
        if (id >= 0) {
            char* a = fn_801F666C(fn_801F856C(), id);
            if (a != 0) {
                fn_80212ECC(a);
            }
        }
        s32 sw = *(s32*)(p + 0x2b8);
        if (sw != 0) {
            fn_802D8050(fn_802D6A9C(), sw, 1, 0xff);
        }
        break;
    }
    case 6: {
        s32 sw = *(s32*)(p + 0x2b8);
        if (sw != 0) {
            fn_802D8050(fn_802D6A9C(), sw, 0, 0xff);
        }
        break;
    }
    }
    s32 id = *(s32*)(p + 0x388);
    if (id >= 0) {
        char* a = fn_801F666C(fn_801F856C(), id);
        if (a != 0) {
            *(u32*)(a + 0x230) |= 0x4000;
        }
    }
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x248) = 6;
}

extern "C" void fn_802121C8(char* p) {
    if (!(*(u32*)(p + 0x230) & 0x2000)) {
        *(s32*)(p + 0x38c) = fn_801F76F0(fn_801F856C(), 'WARP', *(void**)(p + 0x4), p + 0xc, -1);
        s32 id = *(s32*)(p + 0x38c);
        if (id >= 0) {
            char* a = fn_801F666C(fn_801F856C(), id);
            if (a == 0) {
                *(s32*)(p + 0x38c) = -1;
            } else {
                f32 dx = *(f32*)(a + 0xc) - *(f32*)(p + 0xc);
                f32 dy = *(f32*)(a + 0x10) - *(f32*)(p + 0x10);
                f32 dx2 = dx * dx;
                f32 dy2 = dy * dy;
                if (dx2 + dy2 > lbl_8053FB20) {
                    *(s32*)(p + 0x38c) = -1;
                }
            }
        }
    }
}

extern "C" void fn_801CE0A4(char* p);
extern "C" char* fn_801902C0(void);
extern "C" void fn_801F0E34(char* p, u32 a, s32 b);

static inline u8 Rusa_IsActive(char* p) {
    u8 r = 0;
    if (*(s32*)(p + 0x248) != 0 && lbl_8053FAF8 != *(f32*)(p + 0x54) && lbl_8053FAF8 != *(f32*)(p + 0x398)) {
        r = 1;
    }
    return r;
}

extern "C" void fn_80211354(char* p) {
    fn_801CE0A4(p);
    if (Rusa_IsActive(p)) {
        f32 a, b, c;
        c = *(f32*)(p + 0x3a8);
        b = *(f32*)(p + 0x398);
        a = *(f32*)(p + 0x54);
        char* m = fn_801902C0();
        s32 n = *(s32*)(m + 0x4a8);
        if (n < 10) {
            f32* e = (f32*)(m + n * 0x24 + 0x340);
            e[0] = *(f32*)(p + 0xc);
            e[1] = *(f32*)(p + 0x10);
            e[2] = *(f32*)(p + 0x14);
            e[3] = a;
            e[4] = b;
            e[5] = c;
            *(s32*)(m + 0x4a8) = *(s32*)(m + 0x4a8) + 1;
        }
    }
    if (Rusa_IsActive(p)) {
        fn_801F0E34(p, 0x30073, 0);
    }
}

extern const f32 lbl_8053FB04;

// near-match (~86%): register allocation and z-load order differ
extern "C" void fn_80210E90(char* p, const JGeometry::TVec3f* v, JGeometry::TVec3f* out) {
    out->set(lbl_8053FAF8, lbl_8053FAF8, lbl_8053FAF8);
    if (!(v->z <= lbl_8053FAF8)) {
        return;
    }
    if (*(s32*)(p + 0x248) == 0) {
        return;
    }
    f32 rad = lbl_8053FAFC * (lbl_8053FB00 * *(f32*)(p + 0x54));
    if (!(rad > lbl_8053FB04)) {
        return;
    }
    f32 dx = v->x - *(f32*)(p + 0xc);
    f32 dy = v->y - *(f32*)(p + 0x10);
    f32 dx2 = dx * dx;
    f32 dy2 = dy * dy;
    f32 d = dx2 + dy2;
    if (d > lbl_8053FAF8) {
        register f32 recip;
        register f32 dd = d;
        __asm { frsqrte recip, dd }
        d = recip * d;
    }
    if (!(lbl_8053FB04 < d)) {
        return;
    }
    if (!(d <= rad)) {
        return;
    }
    out->sub(*(JGeometry::TVec3f*)(p + 0xc), *v);
    out->z = lbl_8053FAF8;
    out->normalize();
    f32 f = d - lbl_8053FB04;
    f32 m = *(f32*)(p + 0x3a4);
    out->scale((f32)__fsel(f - m, m, f));
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
