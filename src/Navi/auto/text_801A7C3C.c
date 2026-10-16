#include "types.h"

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

extern "C" void* fn_801ABFC0(u8* p) {
    f32 f = lbl_80301D6C;
    *(void**)p = lbl_8027F214;
    p[4] = 0;
    p[5] = 0;
    *(u16*)(p + 6) = 0;
    *(f32*)(p + 8) = f;
    *(void**)p = lbl_8029B430;
    *(u16*)(p + 0xc) = 0;
    *(u16*)(p + 0xe) = 0;
    *(u32*)(p + 0x10) = 0;
    *(u32*)(p + 0x14) = 0;
    *(void**)p = lbl_8029B41C;
    *(u32*)(p + 0x18) = 0;
    *(u32*)(p + 0x1c) = 0;
    return p;
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

extern "C" u32 fn_801ADB98(void) {
    return 2;
}

extern "C" int fn_801ADC28(void) {
    return 5;
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
    d[4] = b;
    *(f32*)(d + 8) = 0.0f;
    *(void**)(d + 0x10) = fn_801BA410(s, *(u32*)(s + 0x10));
    *(void**)(d + 0xc) = fn_8018C2F0(s, *(u32*)(s + 0x14));
}

extern "C" void fn_801B97AC(void* unused, void* dest, void* src);
extern "C" void fn_801B9784(void* self, void* src) {
    fn_801B97AC(self, *(void**)((u8*)self + 4), src);
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