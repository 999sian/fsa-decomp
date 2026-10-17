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



extern const f32 lbl_8053FAFC;
extern const f32 lbl_8053FB00;
extern const f32 lbl_8053FB14;
extern void* lbl_804A6270[];
extern "C" void fn_801D0F40(char* p);
extern "C" void fn_800FE3EC(char* a, u8 b, JGeometry::TVec3f pos, void* c);


extern "C" void fn_802110A8(char* p);



extern const f32 lbl_8053FB20;
extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F76F0(void* mgr, u32 id, void* owner, void* pos, s32 arg);
extern "C" char* fn_801F666C(void* mgr, s32 id);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D8050(void* cr, s32 id, s32 on, s32 v);
extern "C" void fn_801F3604(char* p);
extern "C" void fn_80212ECC(char* p);



extern "C" void fn_801CE0A4(char* p);
extern "C" char* fn_801902C0(void);
extern "C" void fn_801F0E34(char* p, u32 a, s32 b);

static inline u8 Rusa_IsActive(char* p) {
    u8 r = 0;
    if (*(s32*)(p + 0x248) != 0 && 0.0f != *(f32*)(p + 0x54) && 0.0f != *(f32*)(p + 0x398)) {
        r = 1;
    }
    return r;
}


extern const f32 lbl_8053FB04;

static inline void Rusa_CalcPush(char* p, const JGeometry::TVec3f* v, JGeometry::TVec3f* out) {
    out->set(0.0f, 0.0f, 0.0f);
    if (v->z <= 0.0f && *(s32*)(p + 0x248) != 0) {
        f32 rad = lbl_8053FAFC * (lbl_8053FB00 * *(f32*)(p + 0x54));
        if (rad > lbl_8053FB04) {
            f32 dx = v->x - *(f32*)(p + 0xc);
            f32 dy = v->y - *(f32*)(p + 0x10);
            f32 dx2 = dx * dx;
            f32 dy2 = dy * dy;
            f32 d = JMAFastSqrt(dx2 + dy2);
            if (lbl_8053FB04 < d && d <= rad) {
                out->sub(*(JGeometry::TVec3f*)(p + 0xc), *v);
                out->z = 0.0f;
                out->normalize();
                                  f32 m = *(f32*)(p + 0x3a4);
                  f32 f = d - lbl_8053FB04;
                out->scale((f32)__fsel(f - m, m, f));
            }
        }
    }
}


extern "C" u8 fn_802D800C(void* cr, s32 id);
extern "C" s32 fn_801D05F8(char* p, void* pos, f32 r);

static inline void Rusa_Finish(char* p) {
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


extern const f32 lbl_8053FB08;
extern "C" void fn_800FDEA0(char* a, JGeometry::TVec3f pos, f32 s, void* vel, s32 b, s32 c, s32 d);
extern "C" u8 fn_801D0B44(char* p, s32 i);
extern "C" JGeometry::TVec3f* fn_8023E724(s32 idx);
extern "C" void fn_801D00B4(char* p, s32 id, JGeometry::TVec2<f32>* out, f32 s);

static inline u8 Rusa_Contains(char* p, const JGeometry::TVec3f* v) {
    u8 r = 0;
    if (v->z <= 0.0f && *(s32*)(p + 0x248) != 0) {
        f32 rad = lbl_8053FAFC * (lbl_8053FB00 * *(f32*)(p + 0x54));
        f32 dx = v->x - *(f32*)(p + 0xc);
        f32 dy = v->y - *(f32*)(p + 0x10);
        f32 dx2 = dx * dx;
        f32 dy2 = dy * dy;
        f32 r2 = rad * rad;
        if (dx2 + dy2 <= r2) {
            r = 1;
        }
    }
    return r;
}


extern "C" s32 fn_802373EC(s32 i);
extern "C" s32 fn_8023725C(s32 i);
extern "C" u8 fn_8023513C(s32 i);
extern "C" void fn_8023DFF4(s32 i, JGeometry::TVec3f* v);
extern "C" void fn_8022CD48(s32 i);
extern "C" void fn_80230FD0(s32 i, u32 flag);


extern const f32 lbl_8053FB10;
extern const f32 lbl_8053FB24;
extern const f32 lbl_8053FB28;
extern const f32 lbl_8053FB2C;
extern const f32 lbl_8053FB30;
extern const f32 lbl_8053FB34;
extern const f32 lbl_8053FB38;
extern const f32 lbl_8053FB3C;
extern const f32 lbl_8053FB40;
extern const f32 lbl_8053FB44;
extern "C" void fn_801D0ED0(char* p);
extern "C" s32 Actor_CreateByID(void* mgr, u32 id, s32 room, void* pos, s32 param, s32 a, s32 b);
extern "C" void fn_80212F5C(char* a);
extern "C" void* fn_80212AC0(void);
extern "C" void RusaRegistry_Register(void* registry, s32 id);

static inline s32 rusaClamp(s32 v, s32 hi) {
    if (v > hi) {
        return hi;
    }
    if (v < 0) {
        return 0;
    }
    return v;
}


extern const f64 lbl_8053FB18;
extern "C" void fn_80212F14(char* a);
extern "C" void detach__5ActorFv(char* p);

static inline void Rusa_Exit(char* p) {
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
}

static inline void Rusa_SetScale(char* p, f32 s) {
    *(f32*)(p + 0x54) = s;
    *(f32*)(p + 0x58) = s;
    *(f32*)(p + 0x5c) = s;
}

static inline void Rusa_Approach(f32* v, f32 target, s32 remain) {
    f32 n = remain;
    if (n < FLT_EPSILON) {
        *v = target;
    } else {
        *v = (lbl_8053FB14 / n) * (target - *v) + *v;
    }
}



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

// near-match: register allocation differs
extern "C" void fn_80210E90(char* p, const JGeometry::TVec3f* v, JGeometry::TVec3f* out) {
    Rusa_CalcPush(p, v, out);
}

extern "C" BOOL fn_80211000(char* p, const f32* v) {
    BOOL r = FALSE;
    if (v[2] <= 0.0f && *(s32*)(p + 0x248) != 0) {
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
    f32 z = 0.0f;
    *(f32*)(p + 0x3c) = z;
    *(f32*)(p + 0x40) = z;
    *(f32*)(p + 0x44) = z;
    fn_802110A8(p);
}

// near-match (99%): loop counter init is li instead of mr
extern "C" void fn_802110A8(char* p) {
    if (!(*(u32*)(p + 0x230) & 0x8000)) {
        return;
    }
    if (*(s32*)(p + 0x248) == 0) {
        return;
    }
    if (*(u8*)(p + 0x2bc) != 0) {
        fn_800FDEA0(p + 0x2c0, *(JGeometry::TVec3f*)(p + 0xc), lbl_8053FB14, p + 0x3c, 0, 0, 0x200);
    } else {
        s32 i;
        u8 found = 0;
        for (i = (s32)found; i < 4; i++) {
            if (fn_801D0B44(p, i) && Rusa_Contains(p, fn_8023E724(i))) {
                found = 1;
                break;
            }
        }
        if (found) {
            *(s32*)(p + 0x3ac) = -1;
            *(u8*)(p + 0x3b0) = 0;
            return;
        }
        if (*(u8*)(p + 0x3b0) != 0) {
            (*(u8*)(p + 0x3b0))--;
        }
        s32 id = fn_801D05F8(p, p + 0xc, 0.0f);
        s32 cur = *(s32*)(p + 0x3ac);
        if (id != cur) {
            if (id < 0) {
                *(s32*)(p + 0x3ac) = -1;
                *(u8*)(p + 0x3b0) = 0;
            } else if (cur < 0) {
                *(s32*)(p + 0x3ac) = id;
                *(u8*)(p + 0x3b0) = 0x2d;
            } else if (*(u8*)(p + 0x3b0) == 0) {
                *(s32*)(p + 0x3ac) = id;
                *(u8*)(p + 0x3b0) = 0x2d;
            }
        }
        if (*(s32*)(p + 0x3ac) >= 0) {
            JGeometry::TVec2<f32> v;
            fn_801D00B4(p, *(s32*)(p + 0x3ac), &v, lbl_8053FB14);
            *(f32*)(p + 0x3c) = v.x;
            *(f32*)(p + 0x40) = v.y;
        }
    }
    if (*(s32*)(p + 0x38c) >= 0 && ((JGeometry::TVec3f*)(p + 0x3c))->isZero() == false) {
        char* a = fn_801F666C(fn_801F856C(), *(s32*)(p + 0x38c));
        if (a != 0) {
            *(JGeometry::TVec3f*)(a + 0xc) = *(JGeometry::TVec3f*)(a + 0xc) + *(JGeometry::TVec3f*)(p + 0x3c);
        }
    }
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

extern "C" void fn_80211EB0(char* p);
extern "C" void fn_80211C94(char* p);

// near-match (98.5%): r29/r30 swapped for the state-exit temps
extern "C" void fn_8021148C(char* p) {
    u8 go;
    fn_80211EB0(p);
    fn_80211C94(p);
    switch (*(s32*)(p + 0x248)) {
    case 0: {
        go = 0;
        switch (*(s32*)(p + 0x2ac)) {
        case 1:
        case 4:
            if (fn_801D05F8(p, p + 0xc, *(f32*)(p + 0x39c)) >= 0) {
                go = 1;
            }
            break;
        case 2:
        case 3: {
            s32 sw = *(s32*)(p + 0x2b0);
            if (sw != 0 && fn_802D800C(fn_802D6A9C(), sw)) {
                go = 1;
            }
            break;
        }
        }
        if (go) {
            Rusa_Exit(p);
            *(s32*)(p + 0x3ac) = -1;
            *(u8*)(p + 0x3b0) = 0;
            if (*(u32*)(p + 0x230) & 0x4000) {
                Rusa_SetScale(p, *(f32*)(p + 0x394));
            } else {
                Rusa_SetScale(p, *(f32*)(p + 0x390));
            }
            s32 id = *(s32*)(p + 0x388);
            if (id >= 0) {
                char* a = fn_801F666C(fn_801F856C(), id);
                if (a != 0) {
                    fn_80212F14(a);
                }
            }
            *(s32*)(p + 0x24c) = 0;
            *(s32*)(p + 0x248) = 1;
        }
        break;
    }
    case 1:
        if (*(s32*)(p + 0x24c) >= 60) {
            if (*(u32*)(p + 0x230) & 0x4000) {
                Rusa_Exit(p);
                *(s32*)(p + 0x24c) = 0;
                *(s32*)(p + 0x248) = 5;
            } else {
                Rusa_Exit(p);
                *(s32*)(p + 0x24c) = 0;
                *(s32*)(p + 0x248) = 3;
            }
        } else {
            Rusa_Approach((f32*)(p + 0x398), lbl_8053FB14, 60 - *(s32*)(p + 0x24c));
        }
        break;
    case 2:
        if (*(s32*)(p + 0x24c) >= 60) {
            Rusa_Exit(p);
            *(s32*)(p + 0x24c) = 0;
            *(s32*)(p + 0x248) = 3;
        } else {
            Rusa_Approach((f32*)(p + 0x54), *(f32*)(p + 0x390), 60 - *(s32*)(p + 0x24c));
            *(f32*)(p + 0x58) = *(f32*)(p + 0x54);
            *(f32*)(p + 0x5c) = *(f32*)(p + 0x54);
        }
        break;
    case 3:
        if (!(*(u32*)(p + 0x230) & 0x10000) && *(s32*)(p + 0x24c) >= 180) {
            Rusa_Exit(p);
            *(s32*)(p + 0x24c) = 0;
            *(s32*)(p + 0x248) = 4;
        }
        break;
    case 4:
        if (*(s32*)(p + 0x24c) >= 60) {
            Rusa_Exit(p);
            *(s32*)(p + 0x24c) = 0;
            *(s32*)(p + 0x248) = 5;
        } else {
            Rusa_Approach((f32*)(p + 0x54), *(f32*)(p + 0x394), 60 - *(s32*)(p + 0x24c));
            *(f32*)(p + 0x58) = *(f32*)(p + 0x54);
            *(f32*)(p + 0x5c) = *(f32*)(p + 0x54);
        }
        break;
    case 5:
        if (!(*(u32*)(p + 0x230) & 0x10000) && *(s32*)(p + 0x24c) >= 180) {
            Rusa_Exit(p);
            *(s32*)(p + 0x24c) = 0;
            *(s32*)(p + 0x248) = 2;
        }
        break;
    case 6:
        if (*(s32*)(p + 0x24c) >= 30) {
            Rusa_Exit(p);
            *(s32*)(p + 0x3ac) = -1;
            *(u8*)(p + 0x3b0) = 0;
            *(s32*)(p + 0x24c) = 0;
            *(s32*)(p + 0x248) = 0;
            if (*(u32*)(p + 0x230) & 0x20000) {
                s32 sw = *(s32*)(p + 0x2b4);
                if (sw != 0) {
                    fn_802D8050(fn_802D6A9C(), sw, 1, 0xff);
                }
                detach__5ActorFv(p);
            }
        } else {
            Rusa_Approach((f32*)(p + 0x398), 0.0f, 30 - *(s32*)(p + 0x24c));
        }
        break;
    }
}

extern "C" void fn_80211C94(char* p) {
    switch (*(s32*)(p + 0x248)) {
    case 2:
    case 3:
    case 4:
    case 5:
        if (*(s32*)(p + 0x2ac) == 3) {
            s32 sw = *(s32*)(p + 0x2b0);
            if (sw != 0 && !fn_802D800C(fn_802D6A9C(), sw)) {
                Rusa_Finish(p);
                break;
            }
        }
        if (*(s32*)(p + 0x2ac) == 4) {
            if (fn_801D05F8(p, p + 0xc, *(f32*)(p + 0x3a0)) < 0) {
                Rusa_Finish(p);
            }
        }
        break;
    }
}

// near-match (~97%): fsel result gets an extra frsp; float regs differ
extern "C" void fn_80211EB0(char* p) {
    if (*(s32*)(p + 0x248) == 0) {
        return;
    }
    for (s32 i = 0; i < 4; i++) {
        if (fn_801D0B44(p, i) && Rusa_Contains(p, fn_8023E724(i))) {
            if (fn_802373EC(i) == 1 && fn_8023725C(i) == 2 && fn_8023513C(i)) {
                continue;
            }
            JGeometry::TVec3f push;
            Rusa_CalcPush(p, fn_8023E724(i), &push);
            fn_8023DFF4(i, &push);
            fn_8022CD48(i);
            fn_80230FD0(i, 0x20045);
        }
    }
}

extern "C" void fn_80212170(char* p) {
    if ((*(u32*)(p + 0x230) & 0x8000) && *(u8*)(p + 0x2bc) != 0) {
        fn_800FE3EC(p + 0x2c0, *(u8*)(p + 0x2bc), *(JGeometry::TVec3f*)(p + 0xc), *(void**)(p + 0x4));
    }
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

// near-match (99.8%): float regs in the radius clamp differ
extern "C" void fn_80212288(char* p) {
    fn_801D0ED0(p);
    *(s32*)(p + 0x2a8) = rusaClamp(*(u32*)(p + 0x90) & 7, 2);
    switch (*(s32*)(p + 0x2a8)) {
    case 0:
        *(f32*)(p + 0x390) = lbl_8053FB14;
        *(f32*)(p + 0x394) = lbl_8053FB04;
        break;
    case 1:
        *(f32*)(p + 0x390) = lbl_8053FB10;
        *(f32*)(p + 0x394) = lbl_8053FB24;
        break;
    case 2:
        *(f32*)(p + 0x390) = lbl_8053FB28;
        *(f32*)(p + 0x394) = lbl_8053FB2C;
        break;
    }
    if ((*(u32*)(p + 0x90) >> 3) & 1) {
        *(u32*)(p + 0x230) |= 0x4000;
    }
    if ((*(u32*)(p + 0x90) >> 4) & 1) {
        *(u32*)(p + 0x230) |= 0x2000;
    }
    *(u8*)(p + 0x2bc) = (*(u32*)(p + 0x90) >> 5) & 7;
    *(s32*)(p + 0x2ac) = rusaClamp((*(u32*)(p + 0x90) >> 8) & 0xf, 4);
    switch ((*(u32*)(p + 0x90) >> 12) & 3) {
    case 0:
        *(f32*)(p + 0x3a4) = lbl_8053FB30;
        *(f32*)(p + 0x3a8) = lbl_8053FB34;
        break;
    case 1:
        *(f32*)(p + 0x3a4) = lbl_8053FB38;
        *(f32*)(p + 0x3a8) = lbl_8053FB3C;
        break;
    default:
        *(f32*)(p + 0x3a4) = lbl_8053FB10;
        *(f32*)(p + 0x3a8) = lbl_8053FB14;
        break;
    }
    if ((*(u32*)(p + 0x90) >> 25) & 1) {
        *(u32*)(p + 0x230) |= 0x10000;
    }
    if ((*(u32*)(p + 0x90) >> 26) & 1) {
        *(u32*)(p + 0x230) |= 0x8000;
    }
    *(s32*)(p + 0x2b8) = (*(u32*)(p + 0x90) >> 15) & 0x1f;
    *(s32*)(p + 0x2b4) = (*(u32*)(p + 0x90) >> 20) & 0x1f;
    *(s32*)(p + 0x2b0) = *(u32*)(p + 0x90) >> 27;
    *(f32*)(p + 0x60) = lbl_8053FB14;
    *(f32*)(p + 0x64) = lbl_8053FB14;
    *(f32*)(p + 0x68) = lbl_8053FB40;
    *(f32*)(p + 0x6c) = lbl_8053FB40;
    *(f32*)(p + 0x70) = *(f32*)(p + 0x60);
    *(f32*)(p + 0x74) = *(f32*)(p + 0x64);
    *(f32*)(p + 0x78) = *(f32*)(p + 0x68);
    *(f32*)(p + 0x7c) = *(f32*)(p + 0x6c);
    *(f32*)(p + 0x80) = lbl_8053FB14;
    *(f32*)(p + 0x84) = lbl_8053FB14;
    *(f32*)(p + 0x88) = lbl_8053FB40;
    *(f32*)(p + 0x8c) = lbl_8053FB40;
    *(s32*)(p + 0xb0) = 0;
    *(s32*)(p + 0x98) = 2;
    *(u32*)(p + 0x230) |= 0x380;
    *(s32*)(p + 0x108) = 1000;
    *(s32*)(p + 0x244) = *(s32*)(p + 0x108);
    *(u8*)(p + 0x194) = 1;
    if (*(s32*)(p + 0x2ac) == 0) {
        if (*(u32*)(p + 0x230) & 0x4000) {
            *(s32*)(p + 0x248) = 5;
            f32 s = *(f32*)(p + 0x394);
            *(f32*)(p + 0x54) = s;
            *(f32*)(p + 0x58) = s;
            *(f32*)(p + 0x5c) = s;
        } else {
            *(s32*)(p + 0x248) = 3;
            f32 s = *(f32*)(p + 0x390);
            *(f32*)(p + 0x54) = s;
            *(f32*)(p + 0x58) = s;
            *(f32*)(p + 0x5c) = s;
        }
        s32 sw = *(s32*)(p + 0x2b8);
        if (sw != 0) {
            fn_802D8050(fn_802D6A9C(), sw, 1, 0xff);
        }
        *(f32*)(p + 0x398) = lbl_8053FB14;
    } else {
        *(s32*)(p + 0x248) = 0;
        *(f32*)(p + 0x54) = 0.0f;
        *(f32*)(p + 0x58) = 0.0f;
        *(f32*)(p + 0x5c) = 0.0f;
    }
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x250) = -1;
    *(f32*)(p + 0x254) = 0.0f;
    *(f32*)(p + 0x258) = 0.0f;
    if (*(u32*)(p + 0x230) & 0x2000) {
        *(s32*)(p + 0x388) = Actor_CreateByID(fn_801F856C(), 'ARIJ', *(s32*)(p + 0x4), p + 0xc, *(s32*)(p + 0x198), -1, -1);
        char* a = fn_801F666C(fn_801F856C(), *(s32*)(p + 0x388));
        if (a != 0) {
            switch (*(s32*)(p + 0x2ac)) {
            case 0: {
                s32 id = *(s32*)(p + 0x388);
                if (id >= 0) {
                    char* b = fn_801F666C(fn_801F856C(), id);
                    if (b != 0) {
                        fn_80212ECC(b);
                    }
                }
                break;
            }
            case 3:
                fn_80212F5C(a);
                break;
            }
        }
    }
    if (*(s32*)(p + 0x2ac) == 4) {
        if (*(u32*)(p + 0x230) & 0x4000) {
            *(f32*)(p + 0x39c) = lbl_8053FB00 * *(f32*)(p + 0x394);
        } else {
            *(f32*)(p + 0x39c) = lbl_8053FB00 * *(f32*)(p + 0x390);
        }
        *(f32*)(p + 0x39c) -= lbl_8053FB00;
        f32 mn = lbl_8053FB44;
        if (*(f32*)(p + 0x39c) < mn) {
            *(f32*)(p + 0x39c) = mn;
        }
        *(f32*)(p + 0x3a0) = lbl_8053FB00 * *(f32*)(p + 0x394) + lbl_8053FB00;
    } else {
        *(f32*)(p + 0x39c) = lbl_8053FB00 * *(f32*)(p + 0x394);
        *(f32*)(p + 0x3a0) = 0.0f;
    }
    RusaRegistry_Register(fn_80212AC0(), *(s32*)(p + 0x198));
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
}

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
    *(f32*)(p + 0x390) = 0.0f;
    *(f32*)(p + 0x394) = 0.0f;
    *(f32*)(p + 0x398) = 0.0f;
    *(f32*)(p + 0x39c) = 0.0f;
    *(f32*)(p + 0x3a0) = 0.0f;
    *(f32*)(p + 0x3a4) = 0.0f;
    *(f32*)(p + 0x3a8) = lbl_8053FB14;
    *(s32*)(p + 0x3ac) = -1;
    *(u8*)(p + 0x3b0) = 0;
    *(u8*)(p + 0x2c2) = 0;
    *(u8*)(p + 0x2c3) = 0;
    *(u8*)(p + 0x2c1) = 0;
    return p;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
