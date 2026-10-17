#include "types.h"
#include <dolphin/gx.h>
struct JMathSinCos { f32 sin; f32 cos; };
extern "C" {
extern const f32 lbl_8053F65C;
extern const f32 lbl_8053F660;
extern const f32 lbl_8053F664;
extern s8 lbl_8053AC50;
extern u8 lbl_804CA358[];
extern u8 lbl_80469C78[];
extern f32 sincosTable___5JMath[];

void* fn_801F856C(void);
s32 fn_801F7F58(void* a, void* b, void* c, s32 d, f32 e);
void* fn_801F666C(void* a, s32 b);
u8 fn_801CC8E4(void);
void fn_802BAA00(void* p);
void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
void fn_801E9B54(void);
void fn_801E8C74(void* a, s32 b);
s32 fn_801EA8C0(u8* param_1, u8* param_2);
void qsort(void* base, size_t nmemb, size_t size, s32 (*compar)(void*, void*));
}

extern "C" void* fn_801E9AFC(void) {
    if (lbl_8053AC50 == 0) {
        __construct_array(lbl_804CA358, (void*)fn_801E9B54, NULL, 0x78, 2);
        lbl_8053AC50 = 1;
    }
    return lbl_804CA358;
}

extern "C" void fn_801E9B54(void) {
}

extern "C" s32 fn_801E9B58(u8* param_1) {
    s32 iVar2;

    iVar2 = fn_801F7F58(fn_801F856C(), param_1, lbl_80469C78, *(s32*)(param_1 + 0x198), lbl_8053F65C);
    if (iVar2 >= 0 && iVar2 != *(s32*)(param_1 + 0x198)) {
        param_1 = (u8*)fn_801F666C(fn_801F856C(), iVar2);
        if (param_1 != NULL) {
            if (fn_801CC8E4() != 0) {
                iVar2 = -1;
            } else if (*(u32*)(param_1 + 0x1a0) == 0x46495245) {
                fn_802BAA00(param_1);
            }
        }
    }
    return iVar2;
}

extern "C" void fn_801E9C00(s16 param_1, f32* param_2) {
    s16 sVar3;
    u32 uVar2;
    f32* pt;
    f32 fx;
    f32 fy;

    param_2[0] = lbl_8053F660;
    param_2[1] = lbl_8053F664;
    sVar3 = 0x2000;
    if (param_1 < 0) {
        sVar3 = -0x2000;
    }
    uVar2 = ((u32)(-(s32)(s16)(param_1 + sVar3)) >> 2) & 0x3ff8;
    pt = (f32*)((u8*)sincosTable___5JMath + uVar2);
    fx = param_2[0];
    fy = param_2[1];
    param_2[0] = fx * pt[1] - fy * pt[0];
    param_2[1] = fy * pt[1] + fx * pt[0];
}

extern "C" const f32 lbl_8053F668;
extern "C" const f32 lbl_8053F66C;
extern "C" const f32 lbl_8053F670;
extern "C" void fn_801EA108(u8* param_1, f32* pos, s16 angle, f32 z) {
    f32 u0 = lbl_8053F660;
    f32 u1 = lbl_8053F668;
    f32 ox = u0;
    f32 oy = lbl_8053F66C;
    f32 cx, cy, t;
    s32 a;

    if (angle < 0) {
        t = u0;
        ox = -u0;
        u0 = u1;
        u1 = t;
        oy = -oy;
    }
    a = -angle;
    cx = pos[0] + (oy * sincosTable___5JMath[((a >> 5) & 0x7ff) * 2 + 1] - ox * sincosTable___5JMath[((a >> 5) & 0x7ff) * 2]);
    cy = pos[1] + (oy * sincosTable___5JMath[((a >> 5) & 0x7ff) * 2] + ox * sincosTable___5JMath[((a >> 5) & 0x7ff) * 2 + 1]);
    GXBegin(GX_QUADS, GX_VTXFMT0, 4);
    GXPosition3f32(cx + (lbl_8053F670 * sincosTable___5JMath[((a >> 5) & 0x7ff) * 2 + 1] - lbl_8053F670 * sincosTable___5JMath[((a >> 5) & 0x7ff) * 2]), z + (cy + (lbl_8053F670 * sincosTable___5JMath[((a >> 5) & 0x7ff) * 2] + lbl_8053F670 * sincosTable___5JMath[((a >> 5) & 0x7ff) * 2 + 1])), z);
    GXTexCoord2f32(u0, lbl_8053F660);
    GXPosition3f32(cx + (lbl_8053F664 * sincosTable___5JMath[((a >> 5) & 0x7ff) * 2 + 1] - lbl_8053F670 * sincosTable___5JMath[((a >> 5) & 0x7ff) * 2]), z + (cy + (lbl_8053F664 * sincosTable___5JMath[((a >> 5) & 0x7ff) * 2] + lbl_8053F670 * sincosTable___5JMath[((a >> 5) & 0x7ff) * 2 + 1])), z);
    GXTexCoord2f32(u1, lbl_8053F660);
    GXPosition3f32(cx + (lbl_8053F664 * sincosTable___5JMath[((a >> 5) & 0x7ff) * 2 + 1] - lbl_8053F664 * sincosTable___5JMath[((a >> 5) & 0x7ff) * 2]), z + (cy + (lbl_8053F664 * sincosTable___5JMath[((a >> 5) & 0x7ff) * 2] + lbl_8053F664 * sincosTable___5JMath[((a >> 5) & 0x7ff) * 2 + 1])), z);
    GXTexCoord2f32(u1, lbl_8053F668);
    GXPosition3f32(cx + (lbl_8053F670 * sincosTable___5JMath[((a >> 5) & 0x7ff) * 2 + 1] - lbl_8053F664 * sincosTable___5JMath[((a >> 5) & 0x7ff) * 2]), z + (cy + (lbl_8053F670 * sincosTable___5JMath[((a >> 5) & 0x7ff) * 2] + lbl_8053F664 * sincosTable___5JMath[((a >> 5) & 0x7ff) * 2 + 1])), z);
    GXTexCoord2f32(u0, lbl_8053F668);
}

extern "C" void fn_801EA304(u8* param_1) {
    GXLoadTlut((GXTlutObj*)(param_1 + 0x160), 0);
    GXLoadTexObj((GXTexObj*)(param_1 + 0x114), GX_TEXMAP0);
}

extern "C" void fn_801EA344(u8* param_1) {
    GXLoadTlut((GXTlutObj*)(param_1 + 0x154), 0);
    GXLoadTexObj((GXTexObj*)(param_1 + 0xf4), GX_TEXMAP0);
}

extern "C" void fn_801EA594(u8* param_1) {
    s32 i;
    s32 count;
    u8* entry;
    u8* dst;
    u8* src;
    u8* p;
    u8 changed;

    if (*(s32*)(param_1 + 0x60) > 0) {
        do {
            changed = 0;
            count = *(s32*)(param_1 + 0x60);
            entry = param_1;
            for (i = 0; i < count; i++) {
                if (*(s32*)(entry + 8) == -1) {
                    dst = param_1 + i * 12;
                    if (*(u8**)dst != NULL) {
                        (*(u8**)dst)[0x11c] = 0;
                        (*(u8**)dst)[0x11d] = 0;
                    }
                    while (i < *(s32*)(param_1 + 0x60) - 1) {
                        src = param_1 + (i + 1) * 12;
                        i++;
                        *(s32*)dst = *(s32*)src;
                        dst[4] = src[4];
                        *(s32*)(dst + 8) = *(s32*)(src + 8);
                        dst += 12;
                    }
                    *(s32*)(param_1 + 0x60) = *(s32*)(param_1 + 0x60) - 1;
                    changed = 1;
                    break;
                }
                entry += 12;
            }
        } while (changed);
        if (*(s32*)(param_1 + 0x60) > 1) {
            qsort(param_1, *(s32*)(param_1 + 0x60), 12, (s32 (*)(void*, void*))fn_801EA8C0);
        }
        for (entry = param_1, i = 0; i < *(s32*)(param_1 + 0x60); entry += 12, i++) {
            if (*(u8**)entry != NULL) {
                fn_801E8C74(*(u8**)entry, *(s32*)(entry + 8));
            }
        }
    }
}

extern "C" s32 fn_801EA6D8(u8* param_1, u8 param_2, s32 param_3) {
    u8* entry;
    s32 result = -1;
    s32 i;
    s32 count;
    u8* p;

    if (param_2 == 0) {
        u8* slot = param_1 + *(s32*)(param_1 + 0x74) * 4;
        *(s32*)(slot + 0x64) = param_3;
        *(s32*)(param_1 + 0x74) = *(s32*)(param_1 + 0x74) + 1;
    } else {
        count = *(s32*)(param_1 + 0x60);
        entry = param_1;
        for (i = 0; i < count; i++) {
            if (param_2 == entry[4]) {
                *(s32*)(param_1 + i * 0xc + 8) = param_3;
                p = *(u8**)(param_1 + i * 0xc);
                if (p != NULL) {
                    result = *(s32*)(p + 0x198);
                }
                break;
            }
            entry += 0xc;
        }
    }
    return result;
}

extern "C" void fn_801E8EB4(void* p, s32 a, s32 b, void* c);
extern "C" s32 Actor_CreateByID(void* mgr, u32 name, u32 id, f32* pos, u32 arg5, s32 arg6, s32 arg7);
extern "C" void fn_801EA75C(u8* self, u8 idx, u16 flag, s32 p4, s32 p5, f32* p6) {
    s32 i;
    s32 count;
    s32 id;
    f32 pos[3];

    count = *(s32*)(self + 0x60);
    for (i = 0; i < count; i++) {
        if (idx == *(u8*)(self + i * 12 + 4)) {
            break;
        }
    }
    if (i < count) {
        if (*(void**)(self + i * 12) != NULL) {
            if (flag & 0xff) {
                *(u16*)(*(u8**)(self + i * 12) + 0x94) = flag & 0xff;
            }
            fn_801E8EB4(*(void**)(self + i * 12), p4, p5, p6);
        }
    } else {
        *(u8*)(self + count * 12 + 4) = idx;
        pos[0] = p6[0];
        pos[1] = p6[1];
        pos[2] = lbl_8053F660;
        id = Actor_CreateByID(fn_801F856C(), 0x46534f42, p5, pos, idx, -1, -1);
        if (id >= 0) {
            *(void**)(self + *(s32*)(self + 0x60) * 12) = fn_801F666C(fn_801F856C(), id);
            if (*(void**)(self + *(s32*)(self + 0x60) * 12) != NULL) {
                if (flag & 0xff) {
                    *(u16*)(*(u8**)(self + *(s32*)(self + 0x60) * 12) + 0x94) = flag & 0xff;
                }
                fn_801E8EB4(*(void**)(self + *(s32*)(self + 0x60) * 12), p4, p5, p6);
                *(s32*)(self + 0x60) = *(s32*)(self + 0x60) + 1;
            }
        }
    }
}

extern "C" s32 fn_801EA8C0(u8* param_1, u8* param_2) {
    s32 result = 0;
    u8 a = param_1[4];
    u8 b = param_2[4];

    if (a < b) {
        return -1;
    }
    if (a > b) {
        result = 1;
    }
    return result;
}

