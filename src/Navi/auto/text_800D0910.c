#include "types.h"
struct VObjLerp {
    virtual void v0();
    virtual void v1();
    virtual void v4(f32, f32);
    virtual void v3();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v9(s32);
    virtual void v8();
    virtual void v10();
};

struct VObj_800D02D8 {
    virtual void v0();
    virtual void v1();
    virtual void SetPos(f32 x, f32 y);
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void SetAlpha(s32 a);
};

struct VObj_800A1A64 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
};

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x800d0910-0x800d3600 (24 functions). split_file divides it into the game's real files.

extern f32 lbl_80300F88;
extern f32 lbl_802FEAB0;
extern f64 lbl_80300FA8;
extern f64 lbl_80300FB0;
extern f64 lbl_80300FB8;

static inline f32 navi_sqrtf(f32 x)
{
    if (x > lbl_80300F88) {
        f64 guess = __frsqrte((f64)x);
        guess = lbl_80300FA8 * guess * (lbl_80300FB0 - guess * guess * x);
        guess = lbl_80300FA8 * guess * (lbl_80300FB0 - guess * guess * x);
        guess = lbl_80300FA8 * guess * (lbl_80300FB0 - guess * guess * x);
        return (f32)(x * guess);
    } else if (x < lbl_80300FB8) {
        return lbl_802FEAB0;
    } else {
        int t;
        u32 bits = *(u32*)&x;
        switch (bits & 0x7f800000) {
        case 0x7f800000:
            t = (bits & 0x007fffff) ? 1 : 2;
            break;
        case 0:
            t = (bits & 0x007fffff) ? 5 : 3;
            break;
        default:
            t = 4;
            break;
        }
        if (t == 1) {
            return lbl_802FEAB0;
        }
        return x;
    }
}

extern "C" s32 fn_800D2FE8(u8* p, s32 idx, s16 t, u8 max, s32 b, s32 mode, f32 from, f32 to);
extern "C" s32 fn_800D3120(u8* p, s16 a, u8 b, f32 x, f32 y, s32 c, s32 mode);
extern void* lbl_80289490[];
extern "C" void fn_8015AB1C(void* ptr);
extern char lbl_802B7CA0[];
extern f32 lbl_80300F88;
extern "C" void fn_80179CB4(void*, void*, f32, f32);
extern "C" void fn_80060794(void*, void*, void*, void*);
extern "C" void fn_8015FDA8(void*, void*);
extern "C" unsigned char lbl_802C5774[];
extern char lbl_8029FDB4[];
extern char lbl_802891D8[];
extern s32 lbl_802FEC70;
extern s32 lbl_802FD4E0;
extern s32 lbl_802FD4E4;
extern s32 lbl_802FD4EC;
extern "C" u8 fn_800126C8(void*, void*, void*);
extern "C" void* fn_8015A90C(u32 size);
extern "C" void* fn_80178E80(void* self);
extern "C" void* fn_8011FD10(void);
extern "C" void fn_8011FD18(void* a, void* b, s32 c, void* d, void* e, ...);
extern "C" void fn_80007AB8(void* a, s32 b, void* c, ...);
extern "C" void fn_80179030(void* a, void* b, s32 c, void* d);
extern "C" void fn_800D0A4C(u8* p);
extern "C" void fn_800D1E44(u8* p);
extern "C" void fn_800D0910(u8* p) {
    char* base = lbl_802891D8;
    register u8* tbl = lbl_802C5774;
    void* obj;
    s32 v;
    if ((s8)tbl[4] < 0) {
        tbl[4] = fn_800126C8(lbl_8029FDB4 + 4, base + 0x140, tbl);
    }
    *(s32*)(lbl_802C5774 + 8) += 1;
    v = lbl_802FEC70;
    *(s32*)(p + 4) = v;
    obj = fn_8015A90C(0x118);
    if (obj != 0) {
        obj = fn_80178E80(obj);
    }
    *(void**)(p + 0xc) = obj;
    if (*(void**)(p + 0xc) == 0) {
        fn_8011FD18(fn_8011FD10(), base + 0x150, 0x79, &lbl_802FD4E0, base + 0x164);
        fn_80007AB8(base + 0x150, 0x79, &lbl_802FD4E4);
    }
    fn_80179030(*(void**)(p + 0xc), &lbl_802FD4EC, 0x100000, *(void**)(p + 4));
    fn_800D0A4C(p);
    fn_800D1E44(p);
    p[0x286] = 0;
    p[0x267] = 0;
    p[0x268] = 0;
    p[0x266] = 0;
    p[0x26c] = 0;
    p[0x265] = 0;
    p[0x283] = 0;
    p[0x284] = 0;
    ((s8*)p)[0x26e] = -1;
    p[0x287] = 0;
    p[0x264] = 0;
}

extern "C" void fn_800D1E44(u8* p) {
    u8* tbl = lbl_802C5774;
    s32 i;
    p[0x26d] = 0;
    for (i = 0; i < 4; i++) {
        fn_800D2FE8(p, i, p[0x26d], tbl[0x11], 0, 0, *(f32*)(tbl + 0xc), lbl_80300F88);
    }
    fn_800D3120(p, p[0x26d], lbl_802C5774[0x12], *(f32*)(lbl_802C5774 + 0x14), lbl_80300F88, 0, 0);
}

extern "C" void fn_800D2F3C(void* param_1, void* param_2) {
    fn_8015FDA8(param_2, *(void**)((u8*)param_1 + 4));
}

extern f32 lbl_80300F98;
extern "C" f32 fn_800D332C(u8* p, s32 idx, s32 t, s32 b, f32 from, f32 to);
extern "C" s32 fn_800D2FE8(u8* p, s32 idx, s16 t, u8 max, s32 b, s32 mode, f32 from, f32 to) {
    if (t < 0) {
        return 0;
    }
    if (t > max) {
        return 1;
    }
    f32 r = fn_800D332C(p, max, t, b, from, to);
    u8* q = p + idx * 4;
    f32 d = r * (to - from);
    VObj_800D02D8* o = *(VObj_800D02D8**)(q + 0x28);
    o->SetPos(*(f32*)(q + 0x3c), *(f32*)(q + 0x4c) + (from + d));
    if (mode != 2) {
        if (mode == 1) {
            r = lbl_80300F98 - r;
        }
        f32 a = p[idx + 0x38];
        o = *(VObj_800D02D8**)(q + 0x28);
        o->SetAlpha((s32)(a * r));
    }
    return 0;
}

extern "C" s32 fn_800D3120(u8* p, s16 a, u8 b, f32 x, f32 y, s32 c, s32 mode) {
    if (a < 0) {
        return 0;
    }
    if (a > b) {
        return 1;
    }
    f32 t = fn_800D332C(p, b, a, c, x, y);
    VObjLerp* o = *(VObjLerp**)(p + 0x14);
    f32 d = t * (y - x);
    o->v4(*(f32*)(p + 0x1c) + (x + d), *(f32*)(p + 0x20));
    if (mode != 2) {
        if (mode == 1) {
            t = lbl_80300F98 - t;
        }
        o = *(VObjLerp**)(p + 0x14);
        o->v9((s32)((f32)p[0x18] * t));
    }
    return 0;
}

extern "C" void fn_800D3238(u8* p) {
    char* base = lbl_802B7CA0 + 0x1424;
    fn_80060794(base, base + 0x204, base + 0x208, p + 8);
}

extern char lbl_802F0BC0[];
extern f32 lbl_80300FCC;
extern f32 lbl_80300FC8;
extern f32 lbl_80300FC0;
extern f32 lbl_80300FC4;
extern "C" f32 fn_800D332C(u8* p, s32 max, s32 t, s32 b, f32 from, f32 to) {
    if (max <= 0) {
        return lbl_80300F98;
    }
    if (t < 0) {
        t = 0;
    }
    if (t > max) {
        t = max;
    }
    f32 r = (f32)t / (f32)max;
    switch ((u8)b) {
    case 0:
        return navi_sqrtf(r);
    case 1:
        return r * r;
    case 3: {
        f32 v = *(f32*)(lbl_802F0BC0 + (((s32)(lbl_80300FCC * r * 0.5f)) >> 2 & 0x3FF8));
        return v * v;
    }
    case 4:
        return 2.0f * (2.0f * r - 1.0f) - 1.0f;
    case 5: {
        f32 v = *(f32*)(lbl_802F0BC0 + (((s32)(lbl_80300FC8 * r * 0.5f)) >> 2 & 0x3FF8));
        return v * v;
    }
    default:
        return lbl_802FEAB0;
    }
}

extern "C" void fn_800D3554(void* param_1) {
    VObj_800A1A64* obj = *(VObj_800A1A64**)(lbl_802B7CA0 + 0x1394);
    obj->v3();
    f32 c = lbl_80300F88;
    fn_80179CB4(*(void**)((char*)param_1 + 4), obj, c, c);
}

extern "C" void* fn_800D35B8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80289490;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}
