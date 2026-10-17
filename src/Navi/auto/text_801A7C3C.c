#include "types.h"

struct VObj_801AE5C8 {
    virtual void vf0(void* a, s32 b);
    virtual void vf1(void* a, s32 b);
    virtual void vf2(void* a, s32 b);
};

struct VObj_801A9EE0 {
    virtual void vf0(void);
    virtual void vf1(void);
    virtual void vf2(void);
};

struct VObj_801A9E44 {
    virtual void vf0(void);
    virtual void vf1(void);
    virtual void vf2(void);
    virtual void vf3(void);
    virtual void vf4(void);
    virtual void vf5(void);
    virtual void vf6(void);
    virtual void vf7(s32 a);
};

extern "C" f32 lbl_80301D68;
extern "C" void* lbl_8029B254[];
extern "C" void fn_801A91FC(void*);
extern u8 lbl_802EE470[];
extern "C" void fn_80192F60(void* p, s32 param_2);

struct Pair_801A7D54 { f32 x, y; };
struct Blk_801A7D54 { Pair_801A7D54 p[3]; u8 b; };
extern void* lbl_8029BBBC[];

extern "C" void* lbl_8029B5AC[];
extern "C" void* lbl_8027F240[];

extern void* lbl_8029B49C[];

// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801a7c3c-0x801ba678 (389 functions). split_file divides it into the game's real files.

extern void* lbl_8029B220[];
struct Src_801B9BBC {
    u8 pad0[8];
    u8 b8;
    u8 b9;
    s16 hA;
    u16 hC;
    u8 padE[6];
    u32 w14;
    u32 w18;
    u32 w1C;
    u32 w20;
};
struct Dst_801B9BBC {
    u8 pad0[4];
    u8 b4;
    u8 pad5;
    s16 h6;
    f32 f8;
    void* pC;
    void* p10;
    void* p14;
    u8 pad18[6];
    u16 h1E;
    u32 w20;
    void* p24;
};
typedef struct { u16 count; u16 offset; } Key_801ABEA8;
typedef struct {
    u8 pad0[8];
    f32 frame;
    f32* values;
    Key_801ABEA8* keys;
} Anim_801ABEA8;
typedef struct { u16 type; u16 offset; u16 unk4; } Key_801ABF3C;
typedef struct {
    u8 pad0[8];
    f32 frame;
    f32* values;
    Key_801ABF3C* keys;
} Anim_801ABF3C;
struct Entry_801B4B54 {
    u8 a;
    f32 b;
    f32 c;
    f32 d;
};
extern "C" Entry_801B4B54 lbl_80202660;
extern "C" void* lbl_8029B50C[];
extern void* lbl_8027F214[];
extern void* lbl_8029B430[];
extern void* lbl_8029B41C[];
extern "C" f32 lbl_80301D6C;
extern void* lbl_8029B388[];
extern void* lbl_8029B374[];

struct Vec6_801A7C3C {
    f32 v[6];
};

struct Struct_801A7C3C {
    Vec6_801A7C3C a;
    u8 b[4];
    Vec6_801A7C3C c;
};
extern "C" void fn_8011935C(void* p);
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void fn_801B075C(void* param_1);
extern "C" int fn_801B2254(void* param_1, s32 param_2, s32 param_3, u16 param_4, void* param_5);
extern "C" void fn_801B7F68(void* param_1);
extern "C" int fn_801B864C(void* param_1);
extern "C" int fn_801B85B8(void* param_1, u16 param_2, void* param_3);
extern "C" void* lbl_802FF700;
extern "C" void fn_801C5DA8(void* a, void* b, void* c);
extern "C" void* fn_80174B40(void* base, u32 offset);
extern "C" void* fn_80174BA0(void* base, u32 offset);
extern "C" void* fn_8018C2F0(void* base, u32 offset);
extern "C" void* fn_801B7348(void* base, u32 offset);
extern "C" void* fn_8015AA14(u32 size);
extern "C" void fn_801A7C3C(Struct_801A7C3C* dst, const Struct_801A7C3C* src) {
    *dst = *src;
}

extern "C" void fn_801A7D54(Blk_801A7D54* dst, Blk_801A7D54* src) {
    *dst = *src;
}

extern "C" void fn_801A833C(void* p) {
    lbl_802FF700 = p;
}

extern "C" void* fn_801A8574(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029B220;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" u32 fn_801A881C(u8* p1, u8* p2) {
    if (*(u16*)(p2 + 0x2e) != 0) {
        *(void**)(p1 + 8) = fn_8015AA14(*(u16*)(p2 + 0x2e));
        *(void**)(p1 + 0x10) = fn_8015AA14(*(u16*)(p2 + 0x2e) * 0x30);
    }
    return 0;
}

extern "C" u32 fn_801A887C(u8* p) {
    extern s32 lbl_802FE7E0;
    extern s32 lbl_802FE7E4;
    s32 b = (s32)&lbl_802FE7E4;
    s32 a = (s32)&lbl_802FE7E0;
    *(s32*)(p + 0x18) = a;
    *(s32*)(p + 0x14) = a;
    *(s32*)(p + 0x20) = b;
    *(s32*)(p + 0x1c) = b;
    *(s32*)(p + 0x28) = 0;
    *(s32*)(p + 0x24) = 0;
    return 0;
}

extern "C" void fn_801A9354(void* param_1, f32* param_2, f32* param_3, void* param_4) {
    f32 m[12];
    f32 m0 = param_3[0] * param_2[0];
    f32 m1 = param_3[1] * param_2[1];
    f32 m2 = param_3[2] * param_2[2];
    f32 m3 = param_3[3];
    f32 m4 = param_3[4] * param_2[0];
    f32 m5 = param_3[5] * param_2[1];
    f32 m6 = param_3[6] * param_2[2];
    f32 m7 = param_3[7];
    f32 m8 = param_3[8] * param_2[0];
    f32 m9 = param_3[9] * param_2[1];
    f32 m10 = param_3[10] * param_2[2];
    f32 m11 = param_3[11];
    m[0] = m0;
    m[1] = m1;
    m[2] = m2;
    m[3] = m3;
    m[4] = m4;
    m[5] = m5;
    m[6] = m6;
    m[7] = m7;
    m[8] = m8;
    m[9] = m9;
    m[10] = m10;
    m[11] = m11;
    fn_801C5DA8(param_1, m, param_4);
}

extern "C" void fn_801C5D48(void* p);
extern "C" f32 lbl_80301D60;
extern "C" void fn_801A940C(u8* param_1) {
    *(u32*)(param_1 + 0x4) = 0;
    *(u32*)(param_1 + 0x8) = 0;
    *(u32*)(param_1 + 0xc) = 0;
    *(u32*)(param_1 + 0x10) = 0;
    *(u32*)(param_1 + 0x14) = 0;
    *(f32*)(param_1 + 0x18) = lbl_80301D60;
    *(f32*)(param_1 + 0x1c) = lbl_80301D60;
    *(f32*)(param_1 + 0x20) = lbl_80301D60;
    fn_801C5D48(param_1 + 0x24);
    fn_801C5D48(param_1 + 0x54);
    *(u32*)(param_1 + 0x84) = 0;
    *(u32*)(param_1 + 0xc0) = 0;
    *(u32*)(param_1 + 0xc4) = 0;
    *(u32*)(param_1 + 0xc8) = 0;
    *(u32*)(param_1 + 0xcc) = 0;
    *(u32*)(param_1 + 0xd0) = 0;
    *(u32*)(param_1 + 0xd4) = 0;
    *(u32*)(param_1 + 0xd8) = 0;
}

extern "C" void* fn_801E0F6C(void* a, void* b, void* c, u32 d, u32 e);
extern "C" void fn_8019428C(void);
extern "C" void fn_801942E4(void);
extern "C" int fn_801945C4(void* a, void* b);
extern "C" void fn_801C5DA8(void* a, void* b, void* c);
extern "C" int fn_801A95FC(u8* param_1, u8* param_2) {
    s32 i;
    u32 n = (u16)*(u16*)(param_2 + 0x7c);
    if (n != 0) {
        *(void**)(param_1 + 0xc4) = fn_801E0F6C(fn_8015AA14(n * 0x3c + 0x10), fn_8019428C, fn_801942E4, 0x3c, n);
        for (i = 0; i < *(u16*)(param_2 + 0x7c); i++) {
            *(u32*)(*(u8**)(param_1 + 0xc4) + i * 0x3c + 0x28) = ((u32*)(*(u8**)(param_2 + 0x80)))[(u16)i];
            *(u8**)(*(u8**)(param_1 + 0xc4) + i * 0x3c + 0x38) = param_1;
        }
    }
    return 0;
}

extern "C" int fn_801A98A0(u8* param_1, void* param_2) {
    u16 n;
    u16 i;
    int r;
    *(void**)(param_1 + 0xc) = param_2;
    n = *(u16*)(*(u8**)(param_1 + 4) + 0x7c);
    for (i = 0; i < n; i++) {
        r = fn_801945C4(*(u8**)(param_1 + 0xc4) + i * 0x3c, param_2);
        if (r != 0) {
            return r;
        }
    }
    return 0;
}

extern "C" void fn_801A9E44(u8* p) {
    u16 n = *(u16*)(*(u8**)(p + 4) + 0x5c);
    u8* g = lbl_802EE470;
    u16 i;
    for (i = 0; i < n; i++) {
        *(u8**)(g + 0x3c) = *(u8**)(p + 0xc0) + (i << 6);
        ((VObj_801A9E44*)(*(void***)(*(u8**)(p + 4) + 0x60))[i])->vf7(*(s32*)(p + 0xc));
    }
}

extern "C" void fn_801A9EE0(VObj_801A9EE0* p) {
    p->vf2();
    p->vf1();
}

extern "C" void fn_801A9040(void* p);
extern "C" void fn_801AA450(u8* p) {
    fn_801A9040(*(void**)(p + 0x84));
}

extern "C" void fn_801AA57C(u8* p) {
    if (*(u16*)(*(u8**)(p + 4) + 0xe) == 1) {
        fn_801A91FC(*(void**)(p + 0x84));
    }
}

extern "C" void fn_801AA5B0(u8* p) {
    u16 n = *(u16*)(*(u8**)(p + 4) + 0x7c);
    void* a = p + 0x54;
    void* b = lbl_802EE470;
    u16 i;
    for (i = 0; i < n; i++) {
        u8* e = *(u8**)(p + 0xc4) + i * 0x3c;
        *(void**)(e + 0x2c) = *(void**)(p + 0x84);
        if ((*(u32*)(p + 8) & 3) == 2) {
            *(void**)(e + 0x30) = a;
        } else {
            *(void**)(e + 0x30) = b;
        }
    }
}

extern "C" void* fn_801AA614(void* param_1, s16 param_2) {
    if (param_1 != nullptr) {
        *(void**)param_1 = (void*)lbl_8029B254;
        fn_80192F60((u8*)param_1 + 0x88, -1);
        if (param_2 > 0) {
            fn_8015AB1C(param_1);
        }
    }
    return param_1;
}

extern void* lbl_8029B288[];
extern "C" void* fn_801AA678(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)((u8*)ptr + 0x38) = lbl_8029B288;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_801A91FC(void*);
extern u8 lbl_802EE470[];
extern void* lbl_8027F240[];
extern "C" void fn_801AA6C0(u8* p, s16 param_2) {
    p[4] = 2;
    f32 b = lbl_80301D6C;
    p[5] = 0;
    f32 a = lbl_80301D68;
    *(s16*)(p + 6) = 0;
    *(s16*)(p + 8) = param_2;
    *(s16*)(p + 0xa) = 0;
    *(f32*)(p + 0xc) = a;
    *(f32*)(p + 0x10) = b;
}

extern "C" void fn_801AAB64(u8* p, s16 param_2, void* param_3, void* param_4, void* param_5) {
    *(void**)p = lbl_8027F214;
    f32 f = lbl_80301D6C;
    p[4] = 0;
    p[5] = 0;
    *(s16*)(p + 6) = param_2;
    *(f32*)(p + 8) = f;
    *(void**)p = lbl_8027F240;
    *(void**)(p + 0xc) = param_3;
    *(void**)(p + 0x10) = param_4;
    *(void**)(p + 0x14) = param_5;
    *(s16*)(p + 0x18) = 0;
    *(s16*)(p + 0x1a) = 0;
    *(s16*)(p + 0x1c) = 0;
    *(s16*)(p + 0x1e) = 0;
}

extern "C" void* fn_801ABB80(u8* p) {
    f32 f = lbl_80301D6C;
    *(void**)p = lbl_8027F214;
    p[4] = 0;
    p[5] = 0;
    *(u16*)(p + 6) = 0;
    *(f32*)(p + 8) = f;
    *(void**)p = lbl_8029B50C;
    fn_8011935C(p + 0x30);
    fn_8011935C(p + 0x64);
    *(u32*)(p + 0xc) = 0;
    *(u16*)(p + 0x1a) = 0;
    *(u16*)(p + 0x18) = 0;
    *(u16*)(p + 0x16) = 0;
    *(u16*)(p + 0x14) = 0;
    *(u32*)(p + 0x10) = 0;
    *(u32*)(p + 0x24) = 0;
    *(u32*)(p + 0x1c) = 0;
    *(u32*)(p + 0x20) = 0;
    *(u16*)(p + 0x48) = 0;
    *(u16*)(p + 0x46) = 0;
    *(u16*)(p + 0x44) = 0;
    *(u16*)(p + 0x4a) = 0;
    *(u32*)(p + 0x58) = 0;
    *(u32*)(p + 0x54) = 0;
    *(u32*)(p + 0x4c) = 0;
    *(u32*)(p + 0x50) = 0;
    *(u32*)(p + 0x78) = 0;
    return p;
}

extern f32 lbl_80301D80;
extern "C" f32 lbl_80301D80;
extern "C" f32 fn_801ABEA8(Anim_801ABEA8* self, u16 idx)
{
    s32 frame = self->frame + lbl_80301D80;
    s32 count = self->keys[idx].count;
    if (self->frame < lbl_80301D6C) {
        return self->values[self->keys[idx].offset];
    }
    if (frame >= count) {
        return self->values[count + self->keys[idx].offset - 1];
    }
    return self->values[frame + self->keys[idx].offset];
}

extern "C" f32 lbl_80301D68;
extern "C" f32 fn_801AD8D8(u16* hdr, f32 t, f32* k);
extern "C" f32 fn_801ABF3C(Anim_801ABF3C* self, u16 idx)
{
    Key_801ABF3C* key = &self->keys[idx];
    switch (key->type) {
    case 0:
        return lbl_80301D68;
    case 1:
        return self->values[key->offset];
    default:
        return fn_801AD8D8(&self->keys[idx].type, self->frame, &self->values[self->keys[idx].offset]);
    }
}

extern "C" void fn_801ABFC0(u8* p) {
    void* vt0 = lbl_8027F214;
    void* vt1 = lbl_8029B430;
    void* vt2 = lbl_8029B41C;
    f32 f = lbl_80301D6C;
    *(void**)p = vt0;
    p[4] = 0;
    p[5] = 0;
    *(s16*)(p + 6) = 0;
    *(f32*)(p + 8) = f;
    *(void**)p = vt1;
    *(s16*)(p + 0xc) = 0;
    *(s16*)(p + 0xe) = 0;
    *(s32*)(p + 0x10) = 0;
    *(s32*)(p + 0x14) = 0;
    *(void**)p = vt2;
    *(s32*)(p + 0x18) = 0;
    *(s32*)(p + 0x1c) = 0;
}

extern "C" int fn_801194B4(void*, unsigned short);
extern "C" int fn_80119414(int, int);
extern "C" void fn_801AC4DC(char* self, char* other)
{
    int a;
    unsigned short i;
    for (i = 0; i < *(unsigned short*)(self + 0x14); i++) {
        a = *(int*)(other + 0xc);
        int r = fn_80119414(a, fn_801194B4(self + 0x1c, i));
        if (r != -1) {
            (*(unsigned short**)(self + 0x18))[i] = r;
        } else {
            (*(unsigned short**)(self + 0x18))[i] = 0xffff;
        }
    }
}

extern "C" void* fn_801AC584(u8* p) {
    f32 f = lbl_80301D6C;
    *(void**)p = lbl_8027F214;
    p[4] = 0;
    p[5] = 0;
    *(u16*)(p + 6) = 0;
    *(f32*)(p + 8) = f;
    *(void**)p = lbl_8029B388;
    *(u16*)(p + 0xc) = 0;
    *(u16*)(p + 0xe) = 0;
    *(u16*)(p + 0x10) = 0;
    *(u16*)(p + 0x12) = 0;
    *(u16*)(p + 0x14) = 0;
    *(u32*)(p + 0x18) = 0;
    fn_8011935C(p + 0x1c);
    *(void**)p = lbl_8029B374;
    *(u32*)(p + 0x2c) = 0;
    *(u32*)(p + 0x30) = 0;
    *(u32*)(p + 0x34) = 0;
    *(u32*)(p + 0x38) = 0;
    *(u32*)(p + 0x3c) = 0;
    return p;
}

extern void* lbl_8029B388[];
extern void* lbl_8029B374[];
extern void* lbl_8029B2F0[];
extern void* lbl_8029B2C4[];
extern "C" void* fn_801ACBC8(u8* p) {
    f32 f = lbl_80301D6C;
    *(void**)p = lbl_8027F214;
    p[4] = 0;
    p[5] = 0;
    *(u16*)(p + 6) = 0;
    *(f32*)(p + 8) = f;
    *(void**)p = lbl_8029B2C4;
    *(u32*)(p + 0xc) = 0;
    *(u32*)(p + 0x10) = 0;
    *(u16*)(p + 0x14) = 0;
    *(u16*)(p + 0x16) = 0;
    *(u32*)(p + 0x18) = 0;
    fn_8011935C(p + 0x1c);
    return p;
}

extern "C" void fn_801ACC40(u8* self, u16 idx, u16* out) {
    f32 t = *(f32*)(self + 8);
    u16* e = (u16*)(*(u8**)(self + 0x10) + idx * 8);
    u32 n = e[0];
    if (t < lbl_80301D6C) {
        *out = (*(u16**)(self + 0xc))[e[1]];
    } else if (t >= (f32)n) {
        *out = (*(u16**)(self + 0xc))[n + e[1] - 1];
    } else {
        *out = (*(u16**)(self + 0xc))[(int)t + e[1]];
    }
}

extern "C" void fn_801ACCF4(u8* self, u16 idx, u8* out) {
    u16* tbl = *(u16**)(self + 0x10);
    s32 count = tbl[idx * 2];
    s32 i = (s32)(lbl_80301D80 + *(f32*)(self + 8));
    if (i < 0) {
        *out = (*(u8**)(self + 0x14))[tbl[idx * 2 + 1]];
    } else if (i >= count) {
        *out = (*(u8**)(self + 0x14))[count + tbl[idx * 2 + 1] - 1];
    } else {
        *out = (*(u8**)(self + 0x14))[i + tbl[idx * 2 + 1]];
    }
}

extern "C" void fn_801ACD84(char* self, char* other)
{
    int a;
    unsigned short i;
    for (i = 0; i < *(unsigned short*)(self + 0x16); i++) {
        a = *(int*)(other + 0xc);
        int r = fn_80119414(a, fn_801194B4(self + 0x1c, i));
        if (r != -1) {
            (*(unsigned short**)(self + 0x18))[i] = r;
        } else {
            (*(unsigned short**)(self + 0x18))[i] = 0xffff;
        }
    }
}

extern "C" void fn_801ACE2C(char* self, char* other)
{
    unsigned short i;
    int a;
    for (i = 0; i < *(unsigned short*)(self + 0x16); i++) {
        a = *(int*)(other + 0x64);
        int r = fn_80119414(a, fn_801194B4(self + 0x1c, i));
        if (r != -1) {
            (*(unsigned short**)(self + 0x18))[i] = r;
        } else {
            (*(unsigned short**)(self + 0x18))[i] = 0xffff;
        }
    }
}

extern "C" f32 fn_801AD8D8(u16* hdr, f32 t, f32* k) {
    if (t < k[0]) {
        return k[1];
    }
    if (hdr[2] == 0) {
        u32 n = hdr[0];
        if (k[(n - 1) * 3] <= t) {
            return k[(n - 1) * 3 + 1];
        }
        while (n > 1) {
            u32 half = n >> 1;
            u32 idx = half * 3;
            if (t >= k[idx]) {
                k += idx;
                n -= half;
            } else {
                n = half;
            }
        }
        f32 dt = t - k[0];
        f32 len = k[3] - k[0];
        f32 v0 = k[1];
        f32 v1 = k[4];
        f32 m0 = k[2];
        f32 m1 = k[5];
        f32 u = dt / len;
        f32 u2 = u * u;
        f32 dv = v0 - v1;
        f32 u2x = u + u;
        f32 w = u2 - u;
        return (u2x * w - u2) * dv + v0 - dt * (u * m0 - (m1 * w + (m0 * w + m0)));
    } else {
        u32 n = hdr[0];
        if (k[(n - 1) * 4] <= t) {
            return k[(n - 1) * 4 + 1];
        }
        while (n > 1) {
            u32 half = n >> 1;
            if (t >= k[half * 4]) {
                k += half * 4;
                n -= half;
            } else {
                n = half;
            }
        }
        f32 dt = t - k[0];
        f32 len = k[4] - k[0];
        f32 v0 = k[1];
        f32 v1 = k[5];
        f32 m0 = k[3];
        f32 m1 = k[6];
        f32 u = dt / len;
        f32 u2 = u * u;
        f32 dv = v0 - v1;
        f32 u2x = u + u;
        f32 w = u2 - u;
        return (u2x * w - u2) * dv + v0 - dt * (u * m0 - (m1 * w + (m0 * w + m0)));
    }
}

extern void* lbl_8029B430[];
extern void* lbl_8027F214[];
extern "C" void* fn_801ADA54(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029B430;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027F214;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_80286A4C[];
extern "C" void fn_8015AB1C(void* p);
extern "C" void* fn_801ADAB0(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029B388;
        if ((s32)ptr + 0x1c != 0) {
            ((void**)(ptr))[7] = lbl_80286A4C;
        }
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027F214;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* fn_801ADB24(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029B2C4;
        if ((s32)ptr + 0x1c != 0) {
            ((void**)(ptr))[7] = lbl_80286A4C;
        }
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027F214;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" u32 fn_801ADB98(void) {
    return 2;
}

extern "C" void* fn_801ADBA0(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029B2F0;
        if ((s32)ptr + 0x38 != 0) {
            ((void**)(ptr))[0xe] = lbl_80286A4C;
        }
        if ((s32)ptr + 0x24 != 0) {
            ((void**)(ptr))[0x9] = lbl_80286A4C;
        }
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027F214;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" int fn_801ADC28(void) {
    return 5;
}

extern void* lbl_8029B33C[];
extern "C" void* fn_801ADC30(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029B33C;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029B388;
            if ((s32)ptr + 0x1c != 0) {
                ((void**)(ptr))[7] = lbl_80286A4C;
            }
            if (ptr != nullptr) {
                *(void**)ptr = lbl_8027F214;
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" s32 fn_801ADCB4(void) {
    return 0xb;
}

extern "C" void* fn_801ADCBC(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029B374;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029B388;
            if ((s32)ptr + 0x1c != 0) {
                ((void**)(ptr))[7] = lbl_80286A4C;
            }
            if (ptr != nullptr) {
                *(void**)ptr = lbl_8027F214;
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" int fn_801ADD40(void)
{
  return 10;
}

extern "C" BOOL fn_801ADD48(void);
extern "C" BOOL fn_801ADD48(void)
{
    return TRUE;
}

extern "C" void fn_801ADD50(void)
{
  return;
}

extern "C" void* lbl_8029B3E0[];
extern "C" void* fn_801ADD54(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029B3E0;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029B430;
            if (ptr != nullptr) {
                *(void**)ptr = lbl_8027F214;
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" int fn_801ADDC0(void)
{
  return 0xf;
}

extern "C" void* lbl_8029B41C[];
extern "C" void* fn_801ADDC8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029B41C;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029B430;
            if (ptr != nullptr) {
                *(void**)ptr = lbl_8027F214;
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" s32 fn_801ADE34(void) {
    return 0xe;
}

extern "C" s32 fn_801ADE3C(void) {
    return 0x7;
}

extern "C" void fn_801ADE44(void) {
}

extern void* lbl_8029B488[];
extern "C" void* fn_801ADE48(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029B488;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029B49C;
            if (ptr != nullptr) {
                *(void**)ptr = lbl_8027F214;
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" s32 fn_801ADEB4(void) {
    return 0xd;
}

extern void* lbl_8029B49C[];
extern "C" void* fn_801ADEBC(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029B49C;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027F214;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" u32 fn_801ADF18(void) {
    return 3;
}

extern "C" float lbl_80301D68;
extern "C" float fn_801ADF20(void) {
    return lbl_80301D68;
}

extern "C" void* lbl_8029B4D8[];
extern "C" void* fn_801ADF28(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029B4D8;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029B49C;
            if (ptr != nullptr) {
                *(void**)ptr = lbl_8027F214;
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" s32 fn_801ADF94(void) {
    return 0xc;
}

extern "C" void* fn_801ADF9C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029B50C;
        if ((s32)ptr + 0x64 != 0) {
            ((void**)(ptr))[0x19] = lbl_80286A4C;
        }
        if ((s32)ptr + 0x30 != 0) {
            ((void**)(ptr))[0xc] = lbl_80286A4C;
        }
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027F214;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" int fn_801AE024(void) {
    return 4;
}

extern void* lbl_8029B598[];
extern "C" void* fn_801AE02C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029B598;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029B5AC;
            if (ptr != nullptr) {
                *(void**)ptr = lbl_8027F240;
                if (ptr != nullptr) {
                    *(void**)ptr = lbl_8027F214;
                }
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" u32 fn_801AE0A8(void) { return 0x10; }

extern "C" void* lbl_8029B5AC[];
extern "C" void* lbl_8027F240[];
extern "C" void* fn_801AE0B0(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029B5AC;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027F240;
            if (ptr != nullptr) {
                *(void**)ptr = lbl_8027F214;
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" s32 fn_801AE11C(void) {
    return 9;
}

extern "C" void fn_801AE124(u8* p) {
    *(s16*)(p + 0x6) = 0;
    *(s16*)(p + 0xe) = 0;
    *(s16*)(p + 0x5a) = 0;
    *(s16*)(p + 0x66) = 0;
    *(s16*)(p + 0x72) = 0;
    *(s16*)(p + 0x7e) = 0;
    *(s16*)(p + 0x8a) = 0;
    *(s16*)(p + 0x96) = 0;
    *(s16*)(p + 0xa2) = 0;
    *(s16*)(p + 0xae) = 0;
    *(s16*)(p + 0xb6) = 0;
    *(s16*)(p + 0xbe) = 0;
    *(s16*)(p + 0xc6) = 0;
    *(s16*)(p + 0xce) = 0;
    *(s16*)(p + 0xd6) = 0;
    *(s16*)(p + 0xde) = 0;
    *(s16*)(p + 0xe6) = 0;
    *(s16*)(p + 0xee) = 0;
    *(s16*)(p + 0x16) = 0;
    *(s16*)(p + 0x1e) = 0;
    *(s16*)(p + 0x26) = 0;
    *(s16*)(p + 0x2e) = 0;
    *(s16*)(p + 0x36) = 0;
    *(s16*)(p + 0x3e) = 0;
    *(s16*)(p + 0x46) = 0;
    *(s16*)(p + 0x4e) = 0;
}

extern "C" void fn_801AE378(u8* base, u32 idx, u16* src) {
    if (src == nullptr) {
        base += idx * 8;
        *(u16*)(base + 6) = 0;
        return;
    }
    base += idx * 8;
    *(u32*)(base + 8) = *(u32*)(src + 2);
    *(u16*)(base + 4) = src[0];
    *(u16*)(base + 6) = src[1];
}

extern "C" void fn_801AE3B8(u8* p, s32 i, u8* src) {
    if (src == 0) {
        u16 zero = 0;
        p = p + i * 8;
        *(u16*)(p + 0x16) = zero;
        return;
    }
    p = p + i * 8;
    *(u32*)(p + 0x18) = *(u32*)(src + 4);
    *(u16*)(p + 0x14) = *(u16*)(src + 0);
    *(u16*)(p + 0x16) = *(u16*)(src + 2);
}

extern "C" void fn_801AE3F8(u8* p, s32 i, u8* src) {
    if (src == 0) {
        p = p + i * 12;
        *(u16*)(p + 0x5a) = 0;
        return;
    }
    p = p + i * 12;
    *(u32*)(p + 0x5c) = *(u32*)(src + 8);
    *(u16*)(p + 0x58) = *(u16*)(src + 4);
    *(u16*)(p + 0x5a) = *(u16*)(src + 6);
}

extern "C" void fn_801AE438(u8* p, s32 i, u8* src) {
    if (src == 0) {
        p = p + (i << 3);
        *(u16*)(p + 0xb6) = 0;
        return;
    }
    p = p + (i << 3);
    *(u32*)(p + 0xb8) = *(u32*)(src + 4);
    *(u16*)(p + 0xb4) = *(u16*)(src + 0);
    *(u16*)(p + 0xb6) = *(u16*)(src + 2);
}

extern "C" void fn_801AE478(u8* p, s32 i, u8* src) {
    if (src == 0) {
        p = p + i * 8;
        *(u16*)(p + 0xd6) = 0;
        return;
    }
    p = p + i * 8;
    *(u32*)(p + 0xd8) = *(u32*)(src + 4);
    *(u16*)(p + 0xd4) = *(u16*)(src + 0);
    *(u16*)(p + 0xd6) = *(u16*)(src + 2);
}

extern void* lbl_8029B5F8[];
extern "C" void fn_8015AB1C(void* ptr);
extern "C" void* fn_801AE580(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029B5F8;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_801AE5C8(u8* p, u8* src) {
    if (*(u32*)(src + 8) & 4) {
        *(u32*)(p + 0x14) |= 2;
    } else {
        *(u32*)(p + 0x14) &= ~2;
    }
    if (*(u32*)(src + 8) & 8) {
        *(u32*)(p + 0x14) |= 1;
    } else {
        *(u32*)(p + 0x14) &= ~1;
    }
    ((VObj_801AE5C8*)p)->vf0(src + 0x88, *(s32*)(src + 0x84));
}

extern "C" void fn_801AE6DC(void* a, u8* p);
extern "C" void fn_801AE650(VObj_801AE5C8* self, u8* p, s32 b) {
    self->vf0(p + 0x88, b);
}

extern "C" void* fn_801AE680(void* p) {
    *(u16*)((u8*)p + 0x0) = 0;
    *(u16*)((u8*)p + 0x2) = 0;
    *(u16*)((u8*)p + 0x4) = 0;
    *(u32*)((u8*)p + 0x8) = 0;
    *(u32*)((u8*)p + 0xc) = 0;
    *(u32*)((u8*)p + 0x10) = 0;
    *(u16*)((u8*)p + 0x14) = 0;
    *(u16*)((u8*)p + 0x16) = 0;
    *(u32*)((u8*)p + 0x18) = 0;
    *(u32*)((u8*)p + 0x1c) = 0;
    *(u32*)((u8*)p + 0x20) = 0;
    *(u32*)((u8*)p + 0x24) = 0;
    return p;
}

extern "C" void fn_801AE6B8(void* a, u8* p) {
    fn_801AE6DC(a, p + 0x88);
}

extern "C" void fn_801AE7B0(u32* p, u32 v) {
    p[0] = v;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 3;
}

extern "C" void fn_801BA614(void* a, void* b);
extern "C" void* fn_801B3658(void* base, u32 offset);
extern "C" void* fn_801B3640(void* base, u32 offset);
extern "C" void* fn_801B3628(void* base, u32 offset);
extern "C" void* fn_801B0AF0(void* a, void* b, void* c, void* d);
extern "C" void* fn_801B1F9C(void* a, void* b, void* c, void* d);
extern "C" void* fn_801B1504(void* a, void* b, void* c, void* d);
extern "C" void fn_801AF42C(void* a, void* b) {
    extern u32 lbl_8020268C[];
    extern f32 lbl_802EE5BC[];
    extern f32 lbl_802EE5C8[];
    extern u8 lbl_802EE58C[];
    typedef union {
        u32 i[3];
        f32 f[3];
    } Pun_801AF42C;
    Pun_801AF42C v = *(Pun_801AF42C*)lbl_8020268C;
    f32* fa = (f32*)a;
    lbl_802EE5BC[0] = fa[0];
    lbl_802EE5BC[1] = fa[1];
    lbl_802EE5BC[2] = fa[2];
    lbl_802EE5C8[0] = v.f[0];
    lbl_802EE5C8[1] = v.f[1];
    lbl_802EE5C8[2] = v.f[2];
    fn_801BA614(b, lbl_802EE58C);
}

extern "C" void fn_801AF8C4(u8* self, void* node) {
    if (*(u8**)(self + 0xc) == 0) {
        *(void**)(self + 0xc) = node;
        return;
    }
    self = *(u8**)(self + 0xc);
    while (*(u8**)(self + 0x10) != 0) {
        self = *(u8**)(self + 0x10);
    }
    *(void**)(self + 0x10) = node;
}

extern "C" void fn_801AFD48(void* param_1) {
    *(u16*)((u8*)param_1 + 0x4) = 0;
    *(u16*)((u8*)param_1 + 0x6) = 0;
    *(u32*)((u8*)param_1 + 0x8) = 0;
    *(u32*)((u8*)param_1 + 0xc) = 0;
    *(u32*)((u8*)param_1 + 0x10) = 0;
    *(u32*)((u8*)param_1 + 0x14) = 0;
    *(u32*)((u8*)param_1 + 0x18) = 0;
    *(u16*)((u8*)param_1 + 0x1c) = 0;
}

extern "C" void* lbl_8029B61C[];
extern "C" void fn_801AFD70(void* param_1) {
    *(void**)param_1 = lbl_8029B61C;
    *(u16*)((u8*)param_1 + 0x4) = 0;
    *(u16*)((u8*)param_1 + 0x6) = 0;
    *(u32*)((u8*)param_1 + 0x8) = 0;
    *(u32*)((u8*)param_1 + 0xc) = 0;
    *(u32*)((u8*)param_1 + 0x10) = 0;
    *(u32*)((u8*)param_1 + 0x14) = 0;
    *(u32*)((u8*)param_1 + 0x18) = 0;
    *(u16*)((u8*)param_1 + 0x1c) = 0;
}

extern void* lbl_8029B61C[];
extern "C" void* fn_801AFDA4(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029B61C;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" u32 fn_801AFDEC(u8* p1, u8* p2) {
    u16 n = *(u16*)(p2 + 0x14);
    u32 ret = 0;
    u16 i;
    for (i = 0; i < n; i++) {
        u16 idx = ((u16*)*(u8**)(p2 + 0x18))[i];
        if (idx != 0xffff) {
            u8** arr = *(u8***)(p1 + 8);
            u32 v = *(u32*)(arr[idx] + 0x3c);
            if (v >= 0xc0000000) {
                v = 0;
            }
            if (v == 0) {
                ret = 1;
            } else {
                fn_801AE378((u8*)v, 0, 0);
            }
        }
    }
    return ret;
}

extern "C" u32 fn_801AFE98(u8* p1, u8* p2) {
    u16 n = *(u16*)(p2 + 0x16);
    u8* base = *(u8**)(p2 + 0x10);
    u32 ret = 0;
    u16 i;
    for (i = 0; i < n; i++) {
        u16 idx = ((u16*)*(u8**)(p2 + 0x18))[i];
        if (idx != 0xffff) {
            u8** arr = *(u8***)(p1 + 8);
            u32 v = *(u32*)(arr[idx] + 0x3c);
            if (v >= 0xc0000000) {
                v = 0;
            }
            if (v == 0) {
                ret = 1;
            } else {
                fn_801AE3F8((u8*)v, base[i * 8 + 4], 0);
            }
        }
    }
    return ret;
}

extern "C" void* fn_801B09A4(void* self, void* src) {
    u8* d = (u8*)self;
    u8* s = (u8*)src;
    *(u16*)d = *(u16*)(s + 8);
    *(u32*)(d + 4) = 0;
    *(void**)(d + 0x78) = fn_801B3658(src, *(u32*)(s + 0xc));
    *(void**)(d + 0x7c) = fn_801B3640(src, *(u32*)(s + 0x10));
    *(void**)(d + 0x80) = fn_801B3628(src, *(u32*)(s + 0x14));
    *(void**)(d + 0x84) = fn_80174B40(src, *(u32*)(s + 0x18));
    return self;
}

extern "C" s32 fn_801B0A2C(void* self) {
    u16 n = *(u16*)self;
    s32 cnt = 0;
    s32 max = -1;
    u16 i;
    for (i = 0; i < n; i++) {
        if (max < ((u16*)*(u8**)((u8*)self + 8))[i]) {
            max = ((u16*)*(u8**)((u8*)self + 8))[i];
            cnt++;
        }
    }
    return cnt;
}

extern "C" void* fn_801B3658(void* base, u32 offset);
extern "C" void* fn_801B3640(void* base, u32 offset);
extern "C" void* fn_801B3628(void* base, u32 offset);
extern "C" void* fn_801B0AF0(void* a, void* b, void* c, void* d);
extern "C" void* fn_801B1F9C(void* a, void* b, void* c, void* d);
extern "C" void* fn_801B1504(void* a, void* b, void* c, void* d);
extern "C" void* fn_801B0A74(void* a, void* b, s32 sel, void* c, void* d) {
    switch (sel) {
    case 0:
        b = fn_801B0AF0(a, b, c, d);
        break;
    case 1:
        b = fn_801B1F9C(a, b, c, d);
        break;
    case 2:
        b = fn_801B1504(a, b, c, d);
        break;
    }
    return b;
}

extern "C" s32 fn_801B2670(void* a, u32 b) {
    s32 r = 0;
    if (b == 0) {
        r = 100;
    }
    return r + 0x10;
}

extern u32 lbl_80301DD8;
extern "C" void fn_801B2688(u32* out, u8* p, s32 a, s32 b) {
    u32 def = lbl_80301DD8;
    u16 idx = ((u16*)*(u8**)(p + 8))[a];
    u16 v = *(u16*)(*(u8**)(p + 4) + idx * 0x14c + 8 + b * 2);
    if (v != 0xffff) {
        *out = ((u32*)*(u8**)(p + 0x10))[v];
    } else {
        *out = def;
    }
}

extern "C" void fn_801B338C(void) {}

extern void* lbl_8029B650[];
extern void* lbl_80299F88[];
extern "C" void* fn_801B339C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029B650;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_80299F88;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_801B33F8(void) {}

extern "C" void fn_801B33FC(void) {}

extern void* lbl_8029B6F4[];
extern void* lbl_8029AE58[];
extern "C" void* fn_801B3430(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029B6F4;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029AE58;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_801B348C(void) {}

extern "C" void fn_801B3490(void) {}

extern "C" void fn_801B3494(void) {}

extern "C" void fn_801B3498(void) {}

extern "C" void fn_801B349C(void) {}

extern "C" void fn_801B34A0(void) {}

extern "C" void fn_801B34A4(void) {}

extern "C" void fn_801B34A8(void) {}

extern void* lbl_8029B800[];
extern void* lbl_8029A0D4[];
extern "C" void* fn_801B34BC(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029B800;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029A0D4;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8029B89C[];
extern void* lbl_8029A150[];
extern "C" void* fn_801B3524(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029B89C;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029A150;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_8000F080(void* p);
extern "C" void* fn_801B3580(void* p, void* q);
extern "C" u8 lbl_80301D1C[2];
extern "C" void* fn_801B3580(void* param_1, void* param_2) {
    u8* p = (u8*)param_1;
    fn_8000F080(param_1);
    p[7] = (p[7] & ~0x0c) | (((u8)lbl_80301D1C[1]) << 2);
    p[7] = (p[7] & ~3) | lbl_80301D1C[0];
    return param_1;
}

extern void* lbl_80299F4C[];
extern "C" void* fn_801B35E0(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_80299F4C;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* fn_801B3628(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_801B3640(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_801B3658(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_801B3670(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_801B3688(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_801B36A0(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_801B36B8(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_801B36D0(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_801B36E8(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_801B3700(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_801B3718(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_801B3730(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_801B3748(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_801B3760(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_801B3778(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_801B3790(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_801B37A8(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_801B37C0(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_801B37D8(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" u8 fn_801B4AE4(u8* p, s32 i) {
    u8 idx = (*(u8**)(p + 4))[(*(u16**)(p + 8))[i] * 0x138 + 5];
    if (idx != 0xff) {
        return (*(u8**)(p + 0x60))[idx];
    }
    return 0;
}

extern "C" u8 fn_801B4B1C(u8* self, int idx) {
    u8* t = *(u8**)(self + 4);
    u32 off = (*(u16**)(self + 8))[idx] * 0x138 + 7;
    u8 v = t[off];
    if (v != 0xff) {
        return (*(u8**)(self + 0x64))[v];
    }
    return 1;
}

extern "C" Entry_801B4B54 fn_801B4B54(void* self, int idx) {
    Entry_801B4B54 def = lbl_80202660;
    u16* tbl = *(u16**)((u8*)self + 8);
    u8* base = *(u8**)((u8*)self + 4);
    u16 i = *(u16*)(base + tbl[idx] * 0x138 + 0x136);
    if (i != 0xffff) {
        Entry_801B4B54* e = (Entry_801B4B54*)(*(u8**)((u8*)self + 0x68) + i * 0x10);
        Entry_801B4B54 r;
        r.a = e->a;
        r.b = e->b;
        r.c = e->c;
        r.d = e->d;
        return r;
    }
    return def;
}

extern "C" void* fn_801B4BFC(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_801B4C14(u32* data) {
    void* fn_801B4CB0(void*);
    void* fn_801B4D28(void*, u32*);
    void* fn_801B4CCC(void*, s16);
    u8 buf[12];
    if (data[0] == 0x4a334431 && data[1] == 0x626c7331) {
        fn_801B4CB0(buf);
        data = (u32*)fn_801B4D28(buf, data);
        fn_801B4CCC(buf, -1);
        return data;
    } else if (data[0] == 0x4a334432 && data[1] == 0x626c7332) {
        return 0;
    }
    return 0;
}

extern "C" void* fn_801B4CCC(void* ptr, s16 param_2) {
    extern void* lbl_8029B960[];
    extern void* lbl_8029B970[];
    void fn_8015AB1C(void*);
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029B960;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029B970;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

#pragma push
#pragma use_lmw_stmw off
extern "C" void* fn_801B4D28(u8* self, u8* data) {
    void* fn_8015A90C(u32);
    void* fn_801AE680(void*);
    void fn_801B4DC4(void*, u8*);
    void* p = fn_8015A90C(0x28);
    if (p != 0) {
        p = fn_801AE680(p);
    }
    *(void**)(self + 4) = p;
    u32 n = *(u32*)(data + 0xc);
    u8* e = data + 0x20;
    for (u32 i = 0; i < n; i++) {
        switch (*(s32*)e) {
        case 0x434c5331:
            fn_801B4DC4(self, e);
            break;
        }
        e += *(u32*)(e + 4);
    }
    return *(void**)(self + 4);
}
#pragma pop

extern void* lbl_8029B970[];
extern "C" void* fn_801B50C8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029B970;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* fn_801B5110(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_801B5128(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_801B5140(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void fn_801B5FD8(void* self, void* src) {
    u8* s = (u8*)src;
    u8* d = *(u8**)((u8*)self + 4);
    *(s16*)(d + 0x2e) = *(s16*)(s + 8);
    d = *(u8**)((u8*)self + 4);
    *(void**)(d + 0x30) = fn_80174B40(src, *(u32*)(s + 0xc));
    d = *(u8**)((u8*)self + 4);
    *(void**)(d + 0x34) = fn_80174BA0(src, *(u32*)(s + 0x10));
    d = *(u8**)((u8*)self + 4);
    *(void**)(d + 0x38) = fn_8018C2F0(src, *(u32*)(s + 0x14));
    d = *(u8**)((u8*)self + 4);
    *(void**)(d + 0x3c) = fn_801B7348(src, *(u32*)(s + 0x18));
}

extern "C" void fn_801B6070(void* self, void* src) {
    u8* s = (u8*)src;
    u8* d = *(u8**)((u8*)self + 4);
    u16 a = *(u16*)(s + 8);
    *(u16*)(d + 0x44) = a - *(u16*)(d + 0x2e);
    *(void**)(d + 0x48) = fn_80174B40(src, *(u32*)(s + 0xc));
    *(void**)(d + 0x4c) = fn_80174BA0(src, *(u32*)(s + 0x10));
    u16 i;
    for (i = 0; i < *(u16*)(d + 0x44); i++) {
        if (*(u8*)(*(u8**)(d + 0x48) + i) == 1) break;
    }
    *(u16*)(d + 0x46) = i;
    *(void**)(*(u8**)((u8*)self + 4) + 0x40) = fn_8015AA14(*(u16*)(d + 0x44) << 1);
}

#pragma push
#pragma use_lmw_stmw off
extern "C" void fn_801B6818(u8* a, u8* b) {
    void* fn_8015A90C(u32);
    void* fn_801B7330(void*, u32);
    void* fn_8018C2C0(void*, u32);
    void* fn_8011939C(void*, void*);
    extern void* lbl_8029BBB0[];
    void* p;
    u16 h = *(u16*)(b + 8);
    void* q = fn_801B7330(b, *(u32*)(b + 0xc));
    if (*(u32*)(b + 0x10) != 0) {
        p = fn_8015A90C(0x10);
        if (p != 0) {
            p = fn_8011939C(p, fn_8018C2C0(b, *(u32*)(b + 0x10)));
        }
        *(void**)(*(u8**)(a + 8) + 0x18) = p;
    } else {
        *(void**)(*(u8**)(a + 8) + 0x18) = 0;
    }
    void* blk = fn_8015A90C(0xc);
    if (blk != 0) {
        *(void**)((u8*)blk + 8) = lbl_8029BBB0;
        *(u16*)blk = h;
        *(u16*)((u8*)blk + 2) = 0;
        *(void**)((u8*)blk + 4) = q;
    }
    *(void**)(*(u8**)(a + 8) + 0x14) = blk;
}

extern "C" void fn_801B6B7C(u8* a, u8* b) {
    void* fn_8015A90C(u32);
    void* fn_801B7330(void*, u32);
    void* fn_8018C2C0(void*, u32);
    void* fn_8011939C(void*, void*);
    extern void* lbl_8029BBB0[];
    void* p;
    u16 h = *(u16*)(b + 8);
    void* q = fn_801B7330(b, *(u32*)(b + 0xc));
    if (*(u32*)(b + 0x10) != 0) {
        p = fn_8015A90C(0x10);
        if (p != 0) {
            p = fn_8011939C(p, fn_8018C2C0(b, *(u32*)(b + 0x10)));
        }
        *(void**)(*(u8**)(a + 8) + 0x18) = p;
    } else {
        *(void**)(*(u8**)(a + 8) + 0x18) = 0;
    }
    void* blk = fn_8015A90C(0xc);
    if (blk != 0) {
        *(void**)((u8*)blk + 8) = lbl_8029BBB0;
        *(u16*)blk = h;
        *(u16*)((u8*)blk + 2) = 0;
        *(void**)((u8*)blk + 4) = q;
    }
    *(void**)(*(u8**)(a + 8) + 0x14) = blk;
}

#pragma pop
extern "C" void fn_801B1E30(void* param_1, void* param_2, u16 param_3);
extern "C" void fn_801B6F5C(u8* p, u32 flags) {
    u8 buf[0x88];
    u16 i;
    if (flags & 0x2000) {
        ((void (*)(void*, void*))fn_801B075C)(buf, *(void**)(p + 0x10));
        for (i = 0; i < *(u16*)(*(u8**)(p + 8) + 4); i++) {
            fn_801B1E30(buf, ((void**)(*(u8**)(p + 8) + 8))[i], i);
        }
    }
}

extern void* lbl_8029BA14[];
extern "C" void* fn_801B6FD8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029BA14;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029BBBC;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8029B9B0[];
extern "C" void* fn_801B7034(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029B9B0;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029BBBC;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern void* lbl_8029BBBC[];
extern "C" void* fn_801B7090(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029BBBC;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_801B70D8(void) {
    return;
}

extern "C" void fn_801B70DC(void) {
    return;
}

extern "C" void fn_801B70E0(void) {
}

extern "C" void fn_80197AFC(void* param_1);
extern "C" void fn_801C5D74(void* p, void* q);
extern "C" void fn_801B70E4(void) {
}

extern "C" int fn_801B70E8()
{
	return 0;
}

extern "C" int fn_801B70F0()
{
	return 0;
}

extern void* lbl_80204948[];
extern "C" void* lbl_8029BAEC[];
extern "C" void* lbl_8020474C[];
extern "C" void* fn_801B70F8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029BAEC;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8020474C;
            if (ptr != nullptr) {
                *(void**)ptr = lbl_80204948;
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_801B7164(void* unused, f32* param_2, void* param_3) {
    extern f32 lbl_802EE5BC[];
    extern u8 lbl_802EE58C[];
    f32 a = param_2[0];
    f32 b = param_2[1];
    f32 c = param_2[2];
    lbl_802EE5BC[0] = a;
    lbl_802EE5BC[1] = b;
    lbl_802EE5BC[2] = c;
    fn_801C5D74(param_3, lbl_802EE58C);
}

extern "C" void fn_801AF5D4(void*);
extern "C" char* lbl_802FF704;
extern "C" void fn_801B71B0(void) {
    fn_801AF5D4(lbl_802FF704 + 0x18);
}

extern "C" void* lbl_8029BB78[];
extern "C" void* fn_801B71D8(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029BB78;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8020474C;
            if (ptr != nullptr) {
                *(void**)ptr = lbl_80204948;
            }
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_801AF3A4(void*, void*);
extern "C" void fn_801B7244(void* self, void* a, void* b) {
    fn_801AF3A4(a, b);
}

extern "C" void fn_801AF4B4(void*);
extern "C" char* lbl_802FF704;
extern "C" void fn_801B726C(void) {
    fn_801AF4B4(lbl_802FF704 + 0x18);
}

extern "C" void* fn_801B7294(void* param_1) {
    extern void* lbl_80299F4C[];
    *(void**)param_1 = lbl_80299F4C;
    *(u32*)((u8*)param_1 + 0x40) = 0x3CF3CF00;
    *(u32*)((u8*)param_1 + 0x44) = 0x00F3CF3C;
    fn_80197AFC(param_1);
    return param_1;
}

extern "C" void* fn_801B7330(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_801B7348(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_801B7360(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_801B7378(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_801B7390(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_801B73A8(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_801B73C0(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" u16 fn_801B73D8(void* unused, u8* param_2) {
    u32 n = *(u32*)(param_2 + 0xc);
    u8* p = param_2 + 0x20;
    while (n != 0) {
        if (*(u32*)p == 0x4D415433) {
            return *(u16*)(p + 8);
        }
        p += *(u32*)(p + 4);
        n--;
    }
    return 0;
}

extern "C" void* fn_801B7390(void* base, u32 offset);
#pragma dont_inline on
extern "C" int fn_801B78C0(u8* param_1, u8* param_2, s32 param_3) {
    s32 ret = 0;
    s32 flags = (param_3 | *(u16*)(param_2 + 8)) & 0xf;
    switch (flags) {
    case 0:
        ret = 4;
        break;
    case 1:
        ret = 4;
        break;
    case 2:
        ret = 4;
        break;
    }
    *(void**)(param_1 + 0x14) = fn_801B7390(param_2, *(u32*)(param_2 + 0x14));
    return ret;
}
#pragma dont_inline reset
extern "C" int fn_801B7950(void* param_1, u8* param_2) {
    s32 total = 0;
    if (*(void**)(param_2 + 0x14) != nullptr) {
        total = 0x10;
    }
    u32 count = *(u16*)(param_2 + 8);
    total += count * 4;
    total += count * 0x5c;
    return total;
}

#pragma dont_inline reset

extern "C" int fn_801B797C(u8* param_1, u8* param_2) {
    *(u16*)(param_1 + 0x1a) = *(u16*)(param_2 + 8);
    return 0;
}

extern "C" int fn_801B798C(u8* param_1, u8* param_2) {
    return (*(u16*)(param_2 + 8) - *(u16*)(param_1 + 0x1a)) * 2;
}

extern "C" int fn_801B7A8C(u8* param_1, u8* param_2, void* param_3) {
    u8 buf[0x28];
    s32 total = 0;
    fn_801B7F68(buf);
    u32 count = *(u16*)(param_2 + 8);
    if (*(void**)(param_2 + 0x14) != nullptr) {
        total = 0x10;
    }
    total += count * 4;
    total += fn_801B864C(buf);
    for (u16* psVar4 = *(u16**)(param_1 + 0x14); *psVar4 != 0; psVar4 += 2) {
        if (*psVar4 == 0x12) {
            total += fn_801B85B8(buf, psVar4[1], param_3);
        }
    }
    return total;
}

extern "C" void fn_801B075C(void* param_1);
extern "C" int fn_801B2254(void* param_1, s32 param_2, s32 param_3, u16 param_4, void* param_5);
extern "C" void fn_801B7F68(void* param_1);
extern "C" int fn_801B864C(void* param_1);
extern "C" int fn_801B85B8(void* param_1, u16 param_2, void* param_3);
extern "C" int fn_801B7B40(void* param_1, u8* param_2) {
    s32 size = 0;
    if (*(void**)(param_2 + 0x10) != nullptr) {
        size = 0x10;
    }
    return size + 0xc;
}

extern "C" int fn_801B7B5C(void* param_1, u8* param_2, void* param_3) {
    u8 buf[0x88];
    s32 total = 0;
    u32 count = *(u16*)(param_2 + 8);
    fn_801B075C(buf);
    if (*(void**)(param_2 + 0x14) != nullptr) {
        total = 0x10;
    }
    total += count * 4;
    for (s32 i = 0; (u16)i < count; i++) {
        total += fn_801B2254(buf, 0, 0, i, param_3);
    }
    return total;
}

extern "C" int fn_801B7BFC(void* param_1, u8* param_2) {
    s32 size = 0;
    if (*(void**)(param_2 + 0x10) != nullptr) {
        size = 0x10;
    }
    return size + 0xc;
}

extern "C" int fn_801B7C18(void* param_1, u8* param_2, void* param_3) {
    u8 buf[0x88];
    s32 total = 0;
    u32 count = *(u16*)(param_2 + 8);
    fn_801B075C(buf);
    if (*(void**)(param_2 + 0x14) != nullptr) {
        total = 0x10;
    }
    total += count * 4;
    for (s32 i = 0; (u16)i < count; i++) {
        total += fn_801B2254(buf, 0, 2, i, param_3);
    }
    return total;
}

extern "C" void* fn_801B7F50(void* base, u32 offset);
#pragma dont_inline on
extern "C" void* fn_801B7D90(void** param_1, u8* param_2) {
    param_1[0] = fn_801B7F50(param_2, *(u32*)(param_2 + 0xc));
    param_1[1] = fn_801B73C0(param_2, *(u32*)(param_2 + 0x10));
    return param_1;
}
#pragma dont_inline reset
extern "C" void* fn_801B7F50(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_8015A90C(u32 size);
extern "C" void* fn_80196344(void* self, void* a, s32 b);
extern "C" void* fn_801B8420(u8* param_1, u32 param_2, u32 param_3) {
    u8* base = *(u8**)param_1;
    u8* table = *(u8**)(param_1 + 4);
    u8* p = *(u8**)(param_1 + 0x18) + *(u16*)(base + *(u16*)(table + param_2 * 2) * 0x28 + 8) * 8 + param_3 * 8;
    void* r = fn_8015A90C(0xc);
    if (r != nullptr) {
        r = fn_80196344(r, *(u8**)(param_1 + 0x10) + ((u32*)p)[1], ((s32*)p)[0]);
    }
    return r;
}

extern "C" int fn_801B865C(unsigned char** self, unsigned int flags, int idx)
{
    unsigned char* base = self[0];
    int off = ((unsigned short*)self[1])[idx] * 0x28;
    int result = 0;
    switch (flags & 0x10) {
    case 0x10:
        switch (base[off]) {
        case 0:
            result = 8;
            break;
        case 1:
            result = 8;
            break;
        case 2:
            result = 8;
            break;
        case 3:
            result = 0x10;
            break;
        }
        break;
    case 0:
    default:
        switch (base[off]) {
        case 0:
        case 1:
        case 2:
            result = 8;
            break;
        case 3:
            result = 0x10;
            break;
        }
        break;
    }
    return result;
}

extern "C" void* fn_801B8704(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_801B871C(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_801B8734(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_801B874C(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_801B9084(void* ptr, s16 param_2) {
    extern void* lbl_8029BC68[];
    extern void* lbl_8029BC7C[];
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029BC68;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029BC7C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* fn_801B90FC(void* ptr, s16 param_2) {
    extern void* lbl_8029BC30[];
    extern void* lbl_8029BC7C[];
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029BC30;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8029BC7C;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void fn_801B93F8(void* unused, void* dest, void* src);
extern "C" void* fn_8018C260(void* base, u32 offset);
extern "C" void* fn_8018C2D8(void* base, u32 offset);
extern "C" void* fn_8018C2F0(void* base, u32 offset);
extern "C" void fn_801B93D0(void* self, void* src) {
    fn_801B93F8(self, *(void**)((u8*)self + 4), src);
}

extern "C" void fn_801B93F8(void* unused, void* dest, void* src) {
    extern f32 lbl_80301DF0;
    u8* dst = (u8*)dest;
    u8* s = (u8*)src;
    f32 f = lbl_80301DF0;
    u16 a = *(u16*)(s + 0xc);
    s16 b = *(s16*)(s + 0xa);
    *(u16*)(dst + 0x1e) = a;
    u8 c = *(u8*)(s + 8);
    *(s16*)(dst + 6) = b;
    u32 d = *(u32*)(s + 0x14);
    *(u8*)(dst + 4) = c;
    *(f32*)(dst + 8) = f;
    *(void**)(dst + 0x20) = fn_8018C260(s, d);
    *(void**)(dst + 0xc) = fn_8018C2F0(s, *(u32*)(s + 0x18));
    *(void**)(dst + 0x10) = fn_8018C2D8(s, *(u32*)(s + 0x1c));
    *(void**)(dst + 0x14) = fn_8018C2F0(s, *(u32*)(s + 0x20));
}

extern "C" void fn_801B94B4(void* unused, void* dest, void* src);
extern "C" void fn_801B948C(void* self, void* src) {
    fn_801B94B4(self, *(void**)((u8*)self + 4), src);
}

extern "C" void fn_801B95A8(void* unused, void* dest, void* src);
extern "C" void fn_801B9580(void* self, void* src) {
    fn_801B95A8(self, *(void**)((u8*)self + 4), src);
}

extern "C" void* fn_8018C230(void* base, u32 offset);
extern "C" void* fn_80174BA0(void* base, u32 offset);
extern "C" void* fn_8018C2C0(void* base, u32 offset);
extern "C" void fn_801193D8(void* dst, void* src);
extern "C" void fn_801B95A8(void* unused, void* dest, void* src) {
    extern f32 lbl_80301DF0;
    u8* dst = (u8*)dest;
    u8* s = (u8*)src;
    u8 b = s[8];
    *(s16*)(dst + 6) = *(s16*)(s + 0xa);
    u16 h1 = *(u16*)(s + 0xc);
    dst[4] = b;
    u16 h2 = *(u16*)(s + 0xe);
    *(f32*)(dst + 8) = lbl_80301DF0;
    *(u16*)(dst + 0x16) = h1;
    *(u16*)(dst + 0x14) = h2;
    *(void**)(dst + 0x10) = fn_8018C230(s, *(u32*)(s + 0x10));
    *(void**)(dst + 0xc) = fn_80174BA0(s, *(u32*)(s + 0x14));
    *(void**)(dst + 0x18) = fn_80174BA0(s, *(u32*)(s + 0x18));
    fn_801193D8(dst + 0x1c, fn_8018C2C0(s, *(u32*)(s + 0x1c)));
}

extern "C" void fn_801B9674(void* unused, void* dest, void* src);
extern "C" void fn_801B964C(void* self, void* src) {
    fn_801B9674(self, *(void**)((u8*)self + 4), src);
}

extern "C" void* fn_8018C1E8(void* base, u32 offset);
extern "C" void* fn_80174B40(void* base, u32 offset);
extern "C" void fn_801B9674(void* unused, void* dest, void* src) {
    extern f32 lbl_80301DF0;
    u8* dst = (u8*)dest;
    u8* s = (u8*)src;
    f32 f = lbl_80301DF0;
    u8 c = *(u8*)(s + 8);
    s16 b = *(s16*)(s + 0xa);
    *(s16*)(dst + 6) = b;
    u16 a = *(u16*)(s + 0xc);
    *(u8*)(dst + 4) = c;
    u16 e = *(u16*)(s + 0xe);
    *(f32*)(dst + 8) = f;
    *(u16*)(dst + 0xc) = a;
    u32 d = *(u32*)(s + 0x10);
    *(u16*)(dst + 0xe) = e;
    *(void**)(dst + 0x10) = fn_8018C1E8(s, d);
    *(void**)(dst + 0x14) = fn_80174B40(s, *(u32*)(s + 0x14));
}

extern "C" void fn_801B9718(void* unused, void* dest, void* src);
extern "C" void fn_801B96F0(void* self, void* src) {
    fn_801B9718(self, *(void**)((u8*)self + 4), src);
}

extern "C" void* fn_801BA410(void* base, u32 offset);
extern "C" void fn_801B9718(void* unused, void* dest, void* src) {
    u8* d = (u8*)dest;
    u8* s = (u8*)src;
    u8 b = s[8];
    *(s16*)(d + 6) = *(s16*)(s + 0xa);
    u32 v = *(u32*)(s + 0x10);
    d[4] = b;
    *(f32*)(d + 8) = 0.0f;
    *(void**)(d + 0x10) = fn_801BA410(s, v);
    *(void**)(d + 0xc) = fn_8018C2F0(s, *(u32*)(s + 0x14));
}

extern "C" void fn_801B97AC(void* unused, void* dest, void* src);
extern "C" void fn_801B9784(void* self, void* src) {
    fn_801B97AC(self, *(void**)((u8*)self + 4), src);
}

extern "C" void* fn_8018C248(void* base, u32 offset);
extern "C" void* fn_8018C278(void* base, u32 offset);
extern "C" void fn_801B97AC(void* unused, void* dest, void* src) {
    extern f32 lbl_80301DF0;
    f32 f = lbl_80301DF0;
    u8 c = *(u8*)((u8*)src + 8);
    s16 b = *(s16*)((u8*)src + 0xa);
    *(s16*)((u8*)dest + 6) = b;
    u16 a = *(u16*)((u8*)src + 0xc);
    *(u8*)((u8*)dest + 4) = c;
    u16 e = *(u16*)((u8*)src + 0xe);
    *(f32*)((u8*)dest + 8) = f;
    *(u16*)((u8*)dest + 0xc) = a;
    *(u16*)((u8*)dest + 0xe) = e;
    *(void**)((u8*)dest + 0x18) = fn_8018C248(src, *(u32*)((u8*)src + 0x18));
    *(void**)((u8*)dest + 0x1c) = fn_8018C248(src, *(u32*)((u8*)src + 0x1c));
    *(void**)((u8*)dest + 0x10) = fn_8018C278(src, *(u32*)((u8*)src + 0x20));
    *(void**)((u8*)dest + 0x14) = fn_8018C278(src, *(u32*)((u8*)src + 0x24));
    u32 v1 = (u32)fn_80174BA0(src, *(u32*)((u8*)src + 0x28));
    u32 v2 = (u32)fn_80174BA0(src, *(u32*)((u8*)src + 0x2c));
    {
        s32 i;
        u32 off;
        for (i = 0, off = 0; i < *(u16*)((u8*)dest + 0xc); i++, off += 8) {
            u32* w = (u32*)(*(u8**)((u8*)dest + 0x10) + off + 4);
            *w = v1 + *w * 2;
        }
    }
    {
        s32 i;
        u32 off;
        for (i = 0, off = 0; i < *(u16*)((u8*)dest + 0xe); i++, off += 8) {
            u32* w = (u32*)(*(u8**)((u8*)dest + 0x14) + off + 4);
            *w = v2 + *w * 2;
        }
    }
    *(void**)((u8*)dest + 0x20) = fn_80174B40(src, *(u32*)((u8*)src + 0x30));
    *(void**)((u8*)dest + 0x24) = fn_80174B40(src, *(u32*)((u8*)src + 0x34));
    *(void**)((u8*)dest + 0x28) = fn_80174B40(src, *(u32*)((u8*)src + 0x38));
    *(void**)((u8*)dest + 0x2c) = fn_80174B40(src, *(u32*)((u8*)src + 0x3c));
}

extern "C" void fn_801B9BBC(void* unused, void* dest, void* src);
extern "C" void fn_801B9B94(void* self, void* src) {
    fn_801B9BBC(self, *(void**)((u8*)self + 4), src);
}

extern "C" void* fn_8018C308(void* base, u32 offset);
extern "C" void fn_801B9BBC(void* unused, void* dest, void* src) {
    extern f32 lbl_80301DF0;
    u8* dst = (u8*)dest;
    u8* s = (u8*)src;
    f32 f = lbl_80301DF0;
    u16 a = *(u16*)(s + 0xc);
    s16 b = *(s16*)(s + 0xa);
    *(u16*)(dst + 0x1e) = a;
    u8 c = *(u8*)(s + 8);
    *(s16*)(dst + 6) = b;
    u8 e = *(u8*)(s + 9);
    *(u8*)(dst + 4) = c;
    u32 d = *(u32*)(s + 0x14);
    *(u32*)(dst + 0x20) = e;
    *(f32*)(dst + 8) = f;
    *(void**)(dst + 0x24) = fn_8018C308(s, d);
    *(void**)(dst + 0xc) = fn_8018C2F0(s, *(u32*)(s + 0x18));
    *(void**)(dst + 0x10) = fn_8018C2D8(s, *(u32*)(s + 0x1c));
    *(void**)(dst + 0x14) = fn_8018C2F0(s, *(u32*)(s + 0x20));
}

extern "C" void fn_801B9C80(void* unused, void* dest, void* src);
extern "C" void fn_801B9C58(void* self, void* src) {
    fn_801B9C80(self, *(void**)((u8*)self + 4), src);
}

extern "C" void fn_801B9E80(void* unused, void* dest, void* src);
extern "C" void fn_801B9E58(void* self, void* src) {
    fn_801B9E80(self, *(void**)((u8*)self + 4), src);
}

extern "C" void fn_801B9F94(void* unused, void* dest, void* src);
extern "C" void fn_801B9F6C(void* self, void* src) {
    fn_801B9F94(self, *(void**)((u8*)self + 4), src);
}

extern "C" void fn_801BA028(void* unused, void* dest, void* src);
extern "C" void fn_801BA000(void* self, void* src) {
    fn_801BA028(self, *(void**)((u8*)self + 4), src);
}

extern "C" void fn_801BA1DC(void* unused, void* dest, void* src);
extern "C" void fn_801BA1B4(void* self, void* src) {
    fn_801BA1DC(self, *(void**)((u8*)self + 4), src);
}

extern void* lbl_8029BCC0[];
extern "C" void* fn_801BA34C(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029BCC0;
        if (ptr != nullptr) {
            *(void**)ptr = lbl_8027F214;
        }
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" u32 fn_801BA3A8(void) {
    return 6;
}

extern void* lbl_8029BC7C[];
extern "C" void* fn_801BA3B0(void* ptr, s16 param_2) {
    if (ptr != nullptr) {
        *(void**)ptr = lbl_8029BC7C;
        if (param_2 > 0) {
            fn_8015AB1C(ptr);
        }
    }
    return ptr;
}

extern "C" void* fn_801BA3F8(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}

extern "C" void* fn_801BA410(void* base, u32 offset) {
    if (offset == 0) return nullptr;
    return (u8*)base + offset;
}