// TU 0x802ba558-0x802bc83c (actor FIRE).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

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
#ifndef unknown
#define unknown jsys_unknown
#endif
#include "JSystem/JGeometry/Vec.h"

extern "C" char* fn_8020D58C(void);
extern "C" u8 fn_8020D6AC(char* a, s32 b, void* c, void* d, u32* e);
extern "C" s32 fn_80226AE0(void* a, s32 b);
extern "C" s32 fn_802F9908(void* a, s32 b, s32 c);
extern "C" u8 fn_801EE3C0(u16 a);
extern "C" void fn_80226CA8(s32 a, s32 b, f32* c);
extern "C" u16 fn_8022461C(void* a, s32 b);
extern "C" void* fn_802D6A9C(void);
extern u16 lbl_8046CB88[];
extern f32 lbl_80540B50;
extern void* lbl_8053AB10;
typedef void (*FireVFn)(void* self, void* v, s32 flag);
extern f32 lbl_80540B60;
extern f32 lbl_80540B64;
extern f32 lbl_80540B68;
extern "C" u32 __cvt_fp2unsigned(f64);
extern "C" void* fn_8013CC50(s32 id, void* pos, s32 kind, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale);

// FIRE: small accessors.
extern "C" BOOL fn_802BA558(char* p, s32 a, f32* b) {
    u32 names[5] = {'TOMI', 'IPOT', 'WDRY', 'ICEB', 'NULL'};
    f32 v[3];
    JGeometry::TVec3<f32> tmp;
    f32 t[3];
    f32 w[3];
    char* h;
    char* base;
    u8 r;
    u16 q;
    s32 mode;
    s32 idx;
    s32 c;
    u16 sv;

    if (*(s32*)(p + 0x264) != 1) {
        names[3] = 'NULL';
    }
    h = *(char**)(p + 0x198);
    base = fn_8020D58C();
    r = fn_8020D6AC(base + (u8)base[1] * 0x784 + 4, a, b, h, names);
    if (r == 1) {
        return 1;
    }
    if (*(s32*)(p + 0x264) != 3 && *(s32*)(p + 0x264) != 4) {
        if (*(s32*)(p + 0x254) != 0) {
            return 0;
        }
        a = fn_80226AE0(b, *(s32*)(p + 4));
        c = a;
        *(s16*)(p + 0x288) = fn_802F9908(*(void**)((char*)lbl_8053AB10 + 0x20), *(s32*)(p + 4), a);
        if (fn_801EE3C0(*(u16*)(p + 0x288)) == 1) {
            fn_80226CA8(a, *(s32*)(p + 4), v);
            v[0] = v[0] + lbl_80540B50;
            v[1] = v[1] + lbl_80540B50;
            t[0] = v[0];
            t[1] = v[1];
            t[2] = v[2];
            ((FireVFn*)(*(void**)p))[21](p, t, 0);
            *(s32*)(p + 0x254) = 5;
            *(u8*)(p + 0x291) = 1;
            return 1;
        }
        *(u8*)(p + 0x291) = 0;
        sv = *(u16*)(p + 0x288);
        if (sv >= 0x140 && sv <= 0x15f) {
            *(s32*)(p + 0x254) = 0x10;
            if (*(u8*)(p + 0x290) == 0) {
                *(u8*)(p + 0x290) = 1;
            } else {
                *(u8*)(p + 0x290) = 0;
            }
            return 0;
        }
        if (sv == 0x3eb || sv == 0x34 || sv == 0x33) {
            fn_80226CA8(c, *(s32*)(p + 4), v);
            v[0] = v[0] + lbl_80540B50;
            v[1] = v[1] + lbl_80540B50;
            w[0] = v[0];
            w[1] = v[1];
            w[2] = v[2];
            ((FireVFn*)(*(void**)p))[21](p, w, 1);
            return 0;
        }
        *(s32*)(p + 0x27c) = lbl_8046CB88[sv];
        idx = *(s32*)(p + 0x27c);
        if (idx == 0 || idx == 0x61) {
            return 0;
        }
        if ((u32)(idx - 2) <= 5) {
            return 0;
        }
        if (idx == 0x50) {
            return 0;
        }
        if ((u32)(idx - 0x27) <= 8) {
            return 0;
        }
        if (idx == 0x20) {
            return 0;
        }
        if ((u32)(idx - 0xc) <= 2) {
            return 0;
        }
        if ((u32)(idx - 0x39) <= 2) {
            return 0;
        }
        if ((u32)(idx - 0x23) <= 1) {
            return 0;
        }
        if (idx >= 4 && idx <= 7) {
            return 0;
        }
        if (idx >= 0x18 && idx <= 0x1f) {
            return 0;
        }
        if ((u32)(idx - 0x10) <= 6 || idx == 0x17) {
            *(s32*)(p + 0x254) = 0x10;
            if (*(u8*)(p + 0x290) == 0) {
                *(u8*)(p + 0x290) = 1;
            } else {
                *(u8*)(p + 0x290) = 0;
            }
            return 0;
        }
        sv = *(u16*)(p + 0x288);
        if (sv == 0x3a || (u16)(sv - 0x8b) <= 3 || sv == 0x3d) {
            return 0;
        }
        if (idx == 0x25) {
            return *(u8*)((char*)fn_802D6A9C() + 0x171) == 0;
        }
        if (idx == 0x26) {
            return *(u8*)((char*)fn_802D6A9C() + 0x171) == 1;
        }
        if (idx == 0x22) {
            if (*(u8*)((char*)fn_802D6A9C() + 0x170) != 1) {
                return 0;
            }
        }
        return *(u8*)(p + 0x290) == 0;
    } else {
        if (*(s32*)(p + 0x254) > 0) {
            return 0;
        }
        tmp = *(JGeometry::TVec3<f32>*)b;
        q = fn_8022461C(&tmp, a);
        if (q == 0) {
            return 0;
        }
        if (q >= 0x28 && q <= 0x2b) {
            return 0;
        }
        mode = *(s32*)(p + 0x98);
        if (mode == 2) {
            if (q == 0x40) {
                return 0;
            }
            return 1;
        }
        if (mode == 0) {
            if (q == 0x42) {
                return 0;
            }
            return 1;
        }
        if (mode == 1) {
            if (q == 0x43) {
                return 0;
            }
            return 1;
        }
        if (mode == 3) {
            if (q == 0x41) {
                return 0;
            }
            return 1;
        }
        return 0;
    }
}

extern "C" s32 fn_802BA9F0(char* p) { return *(s32*)(p + 0x260); }
extern "C" s32 fn_802BA9F8(char* p) { return *(s32*)(p + 0x264); }
extern "C" void fn_802BAA00(char* p) { *(u8*)(p + 0x11c) = 0; }

extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802BAA0C(char* p, f32* v) {
    f32 v0 = v[0];
    f32 v1 = v[1];
    f32 v2 = v[2];
    f32 v3 = v[3];
    f32 a = 0.5f * (v0 - v2) + v2;
    f32 b = 0.5f * (v1 - v3) + v3;
    f32 na = -a;
    f32 nb = -b;

    *(f32*)(p + 0xc) = a;
    *(f32*)(p + 0x10) = b;
    *(f32*)(p + 0x14) = 0.0f;
    *(f32*)(p + 0x60) = v0;
    *(f32*)(p + 0x64) = v1;
    *(f32*)(p + 0x68) = v2;
    *(f32*)(p + 0x6c) = v3;
    *(f32*)(p + 0x60) = *(f32*)(p + 0x60) + na;
    *(f32*)(p + 0x64) = *(f32*)(p + 0x64) + nb;
    *(f32*)(p + 0x68) = *(f32*)(p + 0x68) + na;
    *(f32*)(p + 0x6c) = *(f32*)(p + 0x6c) + nb;
    *(f32*)(p + 0x80) = v0;
    *(f32*)(p + 0x84) = v1;
    *(f32*)(p + 0x88) = v2;
    *(f32*)(p + 0x8c) = v3;
    *(f32*)(p + 0x80) = *(f32*)(p + 0x80) + na;
    *(f32*)(p + 0x84) = *(f32*)(p + 0x84) + nb;
    *(f32*)(p + 0x88) = *(f32*)(p + 0x88) + na;
    *(f32*)(p + 0x8c) = *(f32*)(p + 0x8c) + nb;

    if (*(s32*)(p + 0x268) == 1 || *(s32*)(p + 0x268) == 2) {
        s32 idx = *(s32*)(p + 0x4);
        if (((u8*)fn_802D6A9C())[idx + 0x131df] != 0) {
            if (*(s32*)(p + 0x98) < 2) {
                *(f32*)(p + 0x84) = *(f32*)(p + 0x84) + 2.0f;
                *(f32*)(p + 0x8c) = *(f32*)(p + 0x8c) - 2.0f;
            } else {
                *(f32*)(p + 0x80) = *(f32*)(p + 0x80) + 2.0f;
                *(f32*)(p + 0x88) = *(f32*)(p + 0x88) - 2.0f;
            }
        }
    }
}

// fn_802BAB80 - FIRE: snap back to the saved position, or play the
// extinguish sound and delete.
struct FireVec { f32 x, y, z; };
struct FireVT {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void kill();
};
extern "C" void fn_801F0E34(void* this_, s32 p1, s32 p2);
extern "C" void fn_802BAB80(char* p) {
    if (*(u8*)(p + 0x291) == 1) {
        *(JGeometry::TVec3<f32>*)(p + 0xc) = *(JGeometry::TVec3<f32>*)(p + 0x248);
    } else {
        fn_801F0E34(p, 0x3002e, 0);
        ((FireVT*)p)->kill();
    }
}

// ---- fn_802BBDFC_dtor.cpp ----
extern "C" void* fn_801F856C(void);
extern "C" s32 Actor_CreateByID(void* base, u32 fourCC, u32 owner, void* posPtr, u32 param, s32 p6, s32 p7);

extern "C" void fn_802BABEC(char* p, void* pos, u8 flag) {
    if (flag == 0) {
        if (*(s32*)(p + 0x264) == 0 || *(s32*)(p + 0x264) == 1 || *(s32*)(p + 0x264) == 5) {
            s32 n = *(s32*)(p + 0x260);
            if (n < 0) {
                Actor_CreateByID(fn_801F856C(), 'BLZE', *(u32*)(p + 0x4), pos,
                                 (*(s32*)(p + 0x98) << 4) | 0xf, -1, -1);
            } else {
                Actor_CreateByID(fn_801F856C(), 'BLZE', *(u32*)(p + 0x4), pos,
                                 (*(s32*)(p + 0x98) << 4) | n, -1, *(s32*)(p + 0x110));
            }
        }
    } else {
        Actor_CreateByID(fn_801F856C(), 'BLZE', *(u32*)(p + 0x4), pos,
                         (*(s32*)(p + 0x98) << 4) | 0x18f, -1, -1);
    }
}

void* fn_801F856C(void);
s32 fn_801F78F4(void* obj, u32 id, s32 prev);
char* fn_801F666C(void* obj, s32 idx);
extern "C" s32 fn_801F78F4(void*, u32, s32);
extern "C" char* fn_801F666C(void*, s32);
extern "C" BOOL fn_802BACE4(char* p) {
    s32 idx;
    char* obj;
    u8 hit;
    f32 x0;
    f32 y0;
    f32 x1;
    f32 y1;
    f32 ox0;
    f32 oy0;
    f32 ox1;
    f32 oy1;

    if (*(s32*)(p + 0x264) != 0) {
        return FALSE;
    }
    x0 = *(f32*)(p + 0x60) + *(f32*)(p + 0xc);
    x1 = *(f32*)(p + 0x68) + *(f32*)(p + 0xc);
    y0 = *(f32*)(p + 0x64) + *(f32*)(p + 0x10);
    y1 = *(f32*)(p + 0x6c) + *(f32*)(p + 0x10);

    idx = -1;
    for (;;) {
        idx = fn_801F78F4(fn_801F856C(), 'ICEB', idx);
        if (idx < 0) {
            return FALSE;
        }
        obj = fn_801F666C(fn_801F856C(), idx);
        if (obj != NULL && *(s32*)(p + 4) == *(s32*)(obj + 4)) {
            ox0 = *(f32*)(obj + 0x60) + *(f32*)(obj + 0xc);
            ox1 = *(f32*)(obj + 0x68) + *(f32*)(obj + 0xc);
            oy0 = *(f32*)(obj + 0x64) + *(f32*)(obj + 0x10);
            oy1 = *(f32*)(obj + 0x6c) + *(f32*)(obj + 0x10);
            if (ox0 <= x0) {
            } else {
                ox0 = x0;
            }
            if (oy0 <= y0) {
            } else {
                oy0 = y0;
            }
            if (ox1 >= x1) {
            } else {
                ox1 = x1;
            }
            if (oy1 >= y1) {
            } else {
                oy1 = y1;
            }
            hit = 0;
            if (ox1 >= ox0 && oy1 >= oy0) {
                hit = 1;
            }
            if (hit) {
                return TRUE;
            }
        }
    }
}

extern f32 lbl_80540B50;
extern f32 lbl_80540B64;
extern f32 lbl_80540B78;
extern f32 lbl_80540B7C;
extern void* lbl_8053AB10;
int fn_8022CCAC(void* p);
int fn_80230188(void* p);
void fn_803075AC(void* a, s32 b, void* c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i, s32 j);
void fn_80158B5C(void* a, s32 b, f32* c, u32* d, f32 e);
void fn_802BB1F8(char* p) {
    f32 v[3];
    u8 buf[4];
    u32 flags;
    s32 type;
    s32 n;
    s32 a;
    s32 k;

    type = *(s32*)(p + 0x264);
    if (type == 5 || type == 6) {
        return;
    }
    v[0] = *(f32*)(p + 0xc);
    v[1] = *(f32*)(p + 0x10);
    v[2] = *(f32*)(p + 0x14);
    a = *(s32*)(p + 0x268) == 2;
    n = *(s32*)(p + 4);
    if (n >= 8) {
        if (type == 5) {
            fn_803075AC(*(void**)(p + 0x198), n, p + 0xc, *(s32*)(p + 0x26c) + *(s32*)(p + 0x270) + 0x109, a != 0, 2, -1, 1, 0, 0);
            return;
        }
        if (type == 1) {
            if (fn_8022CCAC(*(void**)(p + 0x260)) != 0) {
                return;
            }
            if (fn_80230188(*(void**)(p + 0x260)) != 0) {
                return;
            }
            k = *(s32*)(p + 0x98);
            if (k == 0) {
                v[0] -= lbl_80540B64;
            } else if (k == 1) {
                v[0] += lbl_80540B64;
            } else if (k == 2) {
                v[1] += lbl_80540B64;
            } else if (k == 3) {
                v[1] -= lbl_80540B64;
            }
            fn_803075AC(*(void**)(p + 0x198), n, v, *(s32*)(p + 0x26c) + *(s32*)(p + 0x270) + 0xf1, a != 0, 2, -1, 1, 0, 0);
            return;
        }
    } else {
        k = *(s32*)(p + 0x98);
        if (k == 0) {
            v[0] -= lbl_80540B78;
            v[1] -= lbl_80540B50;
        } else if (k == 1) {
            v[0] += lbl_80540B78;
            v[1] -= lbl_80540B50;
        } else if (k == 2) {
            v[1] -= lbl_80540B50;
        }
    }
    buf[0] = 0;
    buf[1] = 0;
    buf[2] = 0;
    buf[3] = 0x80;
    flags = *(u32*)buf;
    fn_80158B5C(*(void**)((char*)lbl_8053AB10 + 0x2c), n, v, &flags, lbl_80540B7C);
}

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void dtor_80084580(void* this_);
extern "C" void fn_801EE434(void* handle);
extern void* lbl_804A89F0[];

extern "C" void* fn_802BBDFC(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A89F0;
        char* p = (char*)this_;
        void* h1 = *(void**)(p + 0x230);
        if (h1 != 0) {
            fn_801EE434(h1);
        }
        void* h2 = *(void**)(p + 0x234);
        if (h2 != 0) {
            fn_801EE434(h2);
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
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
