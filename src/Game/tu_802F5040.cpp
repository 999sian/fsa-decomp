#include "types.h"
#include "JSystem/JKernel/JKRDecomp.h"
#include <dolphin/mtx.h>

extern "C" s32 checkCompressed__9JKRDecompFPUc(u8*);
extern "C" void decode__9JKRDecompFPUcPUcUlUl(u8*, u8*, u32, u32);

extern "C" void __dt__10JUTTextureFv(void*, s32);
extern "C" void __dl__FPv(void*);
extern "C" void __dla__FPv(void*);
extern "C" u8 lbl_804AA858[];

extern "C" f32 lbl_805414F8;
extern "C" f32 lbl_80541500;
extern "C" f32 lbl_805414FC;
extern "C" f64 lbl_80541508;
extern "C" f32 lbl_80541510;
extern "C" f32 lbl_80541514;
extern "C" f32 lbl_80541518;

extern void* lbl_8053AB10;
extern "C" void fn_8013B3CC(void* mgr, void* mtx);
extern "C" void fn_8013B3F0(void* mgr);
extern void* sManager__8JUTVideo;
extern "C" void fn_802FC80C(u8* this_);
extern "C" u8 fn_802F58A8(u8* this_, f32* src, MtxPtr mtx);

struct Tu802F5040Rect {
    s32 m00;
    s32 m04;
    s32 m08;
    s32 m0c;
};

struct Tu802F5040Tbl {
    u8 pad0[0x28];
    u8* m_tbl[8];
};

extern "C" void fn_802FA3FC(void* mgr);
extern "C" void fn_802FF798(void* mgr);
extern "C" void fn_80432750(void* obj, u32 flag, f32 a, f32 b, f32 c, f32 d);
extern "C" void fn_80432638(void* obj);
extern "C" u8 fn_80301D30(s32 i);
extern "C" s32 fn_8030AAF4(s32 i);
extern "C" s32 AnimTable_IsField0xe0LessThan3(void* table, s32 slot);
extern "C" void fn_802FB69C(u8* p, s32 i, s32 a, u8* b, u8* c, u8 d, u8 e, u8 f);
extern void* lbl_8053AD30;
extern u8 lbl_8053ACF0[4];
extern u8 lbl_80506D88[];
extern u8 lbl_80506D98[];
extern void* lbl_8053AAF8;
extern "C" f32 lbl_80541510;
extern "C" f32 lbl_80541514;
extern "C" f32 lbl_80541518;
extern "C" f32 fn_802F5E9C(u8* this_, f32* pos) {
    f32 z = pos[2];
    if (*(s32*)(this_ + 0xc21c) > 0) {
        f32 lo_x = *(f32*)(this_ + 0x2368);
        f32 x = pos[0];
        if (x >= lo_x && x < (f32)*(s32*)(this_ + 0x2380) * lbl_80541510 + lo_x) {
            f32 lo_y = *(f32*)(this_ + 0x236c);
            f32 y = pos[1];
            if (y >= lo_y && y < (f32)*(s32*)(this_ + 0x2384) * lbl_80541510 + lo_y) {
                f32 scale = lbl_80541514;
                s32 ix = (s32)((x - lo_x) * scale);
                s32 iy = (s32)((y - lo_y) * scale);
                f32 fx = scale * ((x - lo_x) - lbl_80541510 * (f32)ix);
                f32 fy = scale * ((y - lo_y) - lbl_80541510 * (f32)iy);
                u8* p = this_ + *(s32*)(this_ + 0x2388) * 4;
                u8* tbl = *(u8**)(p + 0x100);
                u8* cell = tbl + iy * 0x30c + ix * 0xc;
                f32 a = *(f32*)(cell + 0x8);
                f32 b = *(f32*)(cell + 0x14);
                f32 c = *(f32*)(cell + 0x314);
                f32 d = *(f32*)(cell + 0x320);
                f32 r0 = a * (lbl_80541518 - fx) + b * fx;
                f32 r1 = c * (lbl_80541518 - fx) + d * fx;
                z = z + (r0 * (lbl_80541518 - fy) + r1 * fy);
            }
        }
    }
    return z;
}

extern "C" f32 fn_802F5FF4(f32 x) {
    f32 a = lbl_805414FC;
    f32 v;
    if (x >= lbl_80541500) {
        v = x;
    } else {
        v = lbl_80541500;
    }
    return a / (a - v);
}

extern f32 __float_epsilon;
extern f64 __frsqrte(f64);
extern "C" void fn_802F601C(u8* this_, f32* src, s32 type, f32* src2, f32 f1, f32 f2) {
    u8* p;
    s32 best;
    s32 bestIdx;
    s32 slot;
    s32 i;
    u8* e;
    f32* v;
    f32 mag;
    f32 r;
    f32 scale;

    p = this_;
    best = -1;
    bestIdx = 0;
    slot = -1;
    for (i = 0; i < 16; i++) {
        if (*(s32*)(p + 0xBF9C) == 0) {
            slot = i;
            break;
        }
        if (best < 0 || *(s32*)(p + 0xBFAC) < best) {
            best = *(s32*)(p + 0xBFAC);
            bestIdx = i;
        }
        p += 0x28;
    }
    if (slot < 0) {
        slot = bestIdx;
    }

    e = this_ + slot * 0x28 + 0xBF9C;
    *(s32*)e = type;
    *(f32*)(e + 0x4) = src[0];
    *(f32*)(e + 0x8) = src[1];
    *(f32*)(e + 0xC) = src[2];
    *(f32*)(e + 0x14) = f1;
    *(f32*)(e + 0x18) = f2;
    if (type == 4) {
        *(s32*)e = 5;
        *(f32*)(e + 0x14) = -*(f32*)(e + 0x14);
        *(s32*)(e + 0x10) = 1;
        return;
    }
    if (type > 4) {
        if (type == 6) {
            *(s32*)(e + 0x10) = 300;
            return;
        }
        if (type < 6) {
            *(s32*)(e + 0x10) = 1;
        }
        return;
    }
    if (type == 2) {
        *(s32*)(e + 0x10) = 0x3c;
        return;
    }
    if (type > 2) {
        *(s32*)(e + 0x10) = 0x12;
        v = (f32*)(e + 0x1c);
        v[0] = src2[0];
        v[1] = src2[1];
        v[2] = src2[2];
        mag = v[0] * v[0] + v[1] * v[1] + v[2] * v[2];
        if (mag <= 32.0f * __float_epsilon) {
            return;
        }
        if (mag <= 0.0f) {
            scale = mag;
        } else {
            r = (f32)__frsqrte(mag);
            scale = (r * 0.5f) * (3.0f - mag * (r * r));
        }
        v[0] *= scale;
        v[1] *= scale;
        v[2] *= scale;
        return;
    }
    if (type > 0) {
        *(s32*)(e + 0x10) = 5;
    }
}

extern "C" u8 fn_802F6298(u8* self, Vec* pos, s32 a, s32 b, s32 c, s32 d, u8* src) {
    struct Quad {
        s32 v[4];
    };
    struct Blk {
        f32 v[12];
    };
    u8 ret = 0;
    s32 n = *(s32*)(self + 0xe424);
    if (n < 0x20) {
        u8* e = self + n * 0x88 + 0xd324;
        u8 i;
        f32 x = pos->x;
        f32 y = pos->y;
        f32 z = pos->z;
        *(f32*)(e + 0x0) = x;
        *(f32*)(e + 0x4) = y;
        *(f32*)(e + 0x8) = z;
        *(s32*)(e + 0xc) = a;
        *(s32*)(e + 0x10) = b;
        *(s32*)(e + 0x14) = c;
        *(s32*)(e + 0x18) = d;
        if (src != NULL) {
            *(Quad*)(e + 0x1c) = *(Quad*)src;
            e[0x2c] = src[0x10];
            e[0x2d] = src[0x11];
            e[0x2e] = src[0x12];
            e[0x2f] = src[0x13];
            e[0x30] = src[0x14];
            e[0x31] = src[0x15];
            e[0x32] = src[0x16];
            e[0x33] = src[0x17];
            *(s32*)(e + 0x34) = *(s32*)(src + 0x18);
            e[0x38] = src[0x1c];
            e[0x39] = src[0x1d];
            e[0x3a] = src[0x1e];
            e[0x3b] = src[0x1f];
            e[0x3c] = src[0x20];
            e[0x3d] = src[0x21];
            e[0x3e] = src[0x22];
            e[0x3f] = src[0x23];
            e[0x40] = src[0x24];
            e[0x41] = src[0x25];
            e[0x42] = src[0x26];
            *(s32*)(e + 0x44) = *(s32*)(src + 0x28);
            e[0x48] = src[0x2c];
            e[0x49] = src[0x2d];
            e[0x4a] = src[0x2e];
            *(s32*)(e + 0x4c) = *(s32*)(src + 0x30);
            *(s32*)(e + 0x50) = *(s32*)(src + 0x34);
            *(s32*)(e + 0x54) = *(s32*)(src + 0x38);
            e[0x3e] = 0;
            if (*(u8**)(src + 0x18) != NULL) {
                *(Blk*)(e + 0x58) = *(Blk*)*(u8**)(src + 0x18);
                *(u8**)(e + 0x34) = e + 0x58;
            }
        } else {
            for (i = 0; i < 0x10; i += 8) {
                e[(u8)(i + 0) + 0x1c] = i + 0;
                e[(u8)(i + 1) + 0x1c] = i + 1;
                e[(u8)(i + 2) + 0x1c] = i + 2;
                e[(u8)(i + 3) + 0x1c] = i + 3;
                e[(u8)(i + 4) + 0x1c] = i + 4;
                e[(u8)(i + 5) + 0x1c] = i + 5;
                e[(u8)(i + 6) + 0x1c] = i + 6;
                e[(u8)(i + 7) + 0x1c] = i + 7;
            }
            *(s32*)(e + 0x2c) = -1;
            *(s32*)(e + 0x30) = 0;
            *(s32*)(e + 0x34) = 0;
            e[0x38] = 0;
            e[0x39] = 0;
            e[0x3a] = 0;
            e[0x3b] = 1;
            e[0x3c] = 1;
            e[0x3d] = 0;
            e[0x3e] = 0;
            e[0x3f] = 0;
            e[0x40] = 0;
            e[0x41] = 0;
            e[0x42] = 1;
            *(s32*)(e + 0x44) = 3;
            e[0x48] = 1;
            e[0x49] = 0;
            e[0x4a] = 0;
            *(s32*)(e + 0x4c) = -1;
            *(s32*)(e + 0x50) = 0;
            *(s32*)(e + 0x54) = 2;
        }
        ret = 1;
    }
    *(s32*)(self + 0xe424) = *(s32*)(self + 0xe424) + 1;
    return ret;
}

extern "C" u8 fn_802F654C(u8* self, f32* pos, s32 a, s32 b, s32 c, s32 d, u8* src) {
    u8 ret = 0;
    s32 n = *(s32*)(self + 0xd320);
    if (n < 0x20) {
        u8* e = self + n * 0x88 + 0xc220;
        *(f32*)(e + 0x0) = pos[0];
        *(f32*)(e + 0x4) = pos[1];
        *(f32*)(e + 0x8) = pos[2];
        *(s32*)(e + 0xc) = a;
        *(s32*)(e + 0x10) = b;
        *(s32*)(e + 0x14) = c;
        *(s32*)(e + 0x18) = d;
        if (src != NULL) {
            *(s32*)(e + 0x1c) = *(s32*)(src + 0x0);
            *(s32*)(e + 0x20) = *(s32*)(src + 0x4);
            *(s32*)(e + 0x24) = *(s32*)(src + 0x8);
            *(s32*)(e + 0x28) = *(s32*)(src + 0xc);
            e[0x2c] = src[0x10];
            e[0x2d] = src[0x11];
            e[0x2e] = src[0x12];
            e[0x2f] = src[0x13];
            e[0x30] = src[0x14];
            e[0x31] = src[0x15];
            e[0x32] = src[0x16];
            e[0x33] = src[0x17];
            *(s32*)(e + 0x34) = *(s32*)(src + 0x18);
            e[0x38] = src[0x1c];
            e[0x39] = src[0x1d];
            e[0x3a] = src[0x1e];
            e[0x3b] = src[0x1f];
            e[0x3c] = src[0x20];
            e[0x3d] = src[0x21];
            e[0x3e] = src[0x22];
            e[0x3f] = src[0x23];
            e[0x40] = src[0x24];
            e[0x41] = src[0x25];
            e[0x42] = src[0x26];
            *(s32*)(e + 0x44) = *(s32*)(src + 0x28);
            e[0x48] = src[0x2c];
            e[0x49] = src[0x2d];
            e[0x4a] = src[0x2e];
            *(s32*)(e + 0x4c) = *(s32*)(src + 0x30);
            *(s32*)(e + 0x50) = *(s32*)(src + 0x34);
            *(s32*)(e + 0x54) = *(s32*)(src + 0x38);
            e[0x3d] = 0;
            if (*(void**)(src + 0x18) != NULL) {
                memcpy(e + 0x58, *(void**)(src + 0x18), 0x30);
                *(void**)(e + 0x34) = e + 0x58;
            }
        } else {
            for (u8 i = 0; i < 0x10; i += 8) {
                e[0x1c + i] = i;
                e[0x1c + i + 1] = i + 1;
                e[0x1c + i + 2] = i + 2;
                e[0x1c + i + 3] = i + 3;
                e[0x1c + i + 4] = i + 4;
                e[0x1c + i + 5] = i + 5;
                e[0x1c + i + 6] = i + 6;
                e[0x1c + i + 7] = i + 7;
            }
            *(s32*)(e + 0x2c) = -1;
            *(s32*)(e + 0x30) = 0;
            *(s32*)(e + 0x34) = 0;
            e[0x38] = 0;
            e[0x39] = 0;
            e[0x3a] = 0;
            e[0x3b] = 1;
            e[0x3c] = 1;
            e[0x3d] = 0;
            e[0x3e] = 0;
            e[0x3f] = 0;
            e[0x40] = 0;
            e[0x41] = 0;
            e[0x42] = 1;
            *(s32*)(e + 0x44) = 3;
            e[0x48] = 1;
            e[0x49] = 0;
            e[0x4a] = 0;
            *(s32*)(e + 0x4c) = -1;
            *(s32*)(e + 0x50) = 0;
            *(s32*)(e + 0x54) = 2;
        }
        ret = 1;
        *(s32*)(self + 0xd320) += 1;
    }
    return ret;
}

extern "C" void fn_802F6BBC(Tu802F5040Tbl* base, s32 src, s32 dst) {
    u16* s;
    u16* d;
    s32 n;
    if (src >= 0 && src < 4) {
        s = (u16*)base->m_tbl[src];
    } else if (src >= 4 && src < 8) {
        s = (u16*)base->m_tbl[src];
    } else {
        s = (u16*)base->m_tbl[src];
    }
    if (dst >= 0 && dst < 4) {
        d = (u16*)base->m_tbl[dst];
    } else if (dst >= 4 && dst < 8) {
        d = (u16*)base->m_tbl[dst];
    } else {
        d = (u16*)base->m_tbl[dst];
    }
    n = 0x100;
    do {
        d[0] = s[0];
        d[1] = s[1];
        d[2] = s[2];
        d[3] = s[3];
        d[4] = s[4];
        d[5] = s[5];
        d[6] = s[6];
        d[7] = s[7];
        d[8] = s[8];
        d[9] = s[9];
        d[10] = s[10];
        d[11] = s[11];
        d[12] = s[12];
        d[13] = s[13];
        d[14] = s[14];
        d[15] = s[15];
        s += 16;
        d += 16;
    } while (--n != 0);
}

extern GXColor lbl_805414F4;
extern GXColor lbl_80543F60;
extern "C" void fn_802F8F0C(void*, u8* p) {
    GXColor c1;
    GXColor c2;
    GXClearVtxDesc();
    GXSetVtxDesc(GX_VA_POS, GX_DIRECT);
    GXSetVtxDesc(GX_VA_TEX0, GX_DIRECT);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_POS, GX_POS_XYZ, GX_F32, 0);
    GXSetVtxAttrFmt(GX_VTXFMT0, GX_VA_TEX0, GX_TEX_ST, GX_F32, 0);
    GXSetChanCtrl(GX_COLOR0A0, GX_FALSE, GX_SRC_REG, GX_SRC_REG, GX_LIGHT_NULL, GX_DF_NONE, GX_AF_NONE);
    GXSetNumChans(1);
    GXSetTexCoordGen2(GX_TEXCOORD0, GX_TG_MTX2x4, GX_TG_TEX0, GX_IDENTITY, GX_FALSE, GX_PTIDENTITY);
    GXSetNumTexGens(1);
    if (p != NULL) {
        c1 = *(GXColor*)(p + 0x10);
        c2 = *(GXColor*)(p + 0x14);
    } else {
        c1 = lbl_805414F4;
        c2 = lbl_80543F60;
    }
    GXSetTevColor(GX_TEVREG1, c1);
    GXSetTevColor(GX_TEVREG2, c2);
    GXSetTevColorIn(GX_TEVSTAGE0, (GXTevColorArg)0xf, (GXTevColorArg)8, (GXTevColorArg)2, (GXTevColorArg)4);
    GXSetTevAlphaIn(GX_TEVSTAGE0, (GXTevAlphaArg)7, (GXTevAlphaArg)4, (GXTevAlphaArg)1, (GXTevAlphaArg)2);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevSwapMode(GX_TEVSTAGE0, GX_TEV_SWAP0, GX_TEV_SWAP0);
    GXSetNumTevStages(1);
    GXSetNumIndStages(0);
    if (p != NULL && *(s32*)(p + 0x34) == 1) {
        GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_SET);
    } else if (p != NULL && *(s32*)(p + 0x34) == 2) {
        GXSetBlendMode(GX_BM_BLEND, GX_BL_DSTALPHA, GX_BL_INVDSTALPHA, GX_LO_SET);
    } else {
        GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_SET);
    }
    if (p != NULL) {
        GXSetZMode(*(u8*)(p + 0x26), (GXCompare)*(s32*)(p + 0x28), *(u8*)(p + 0x2c));
    } else {
        GXSetZMode(GX_TRUE, GX_LEQUAL, GX_TRUE);
    }
    GXSetZCompLoc(GX_FALSE);
    GXSetColorUpdate(GX_TRUE);
    if (p != NULL) {
        GXSetAlphaUpdate(*(u8*)(p + 0x2d));
        GXSetAlphaCompare(GX_GREATER, *(u8*)(p + 0x2e), GX_AOP_AND, GX_ALWAYS, 0);
    } else {
        GXSetAlphaUpdate(GX_FALSE);
        GXSetAlphaCompare(GX_GREATER, 0, GX_AOP_AND, GX_ALWAYS, 0);
    }
    GXSetCullMode(GX_CULL_NONE);
}

extern "C" void fn_802F91AC(f32 f, f32* p, u8* o, u8* out) {
    f32 m[12];
    f32 s;
    s32 i;

    *out = 0;
    if (o == 0) {
        fn_8013B3F0(lbl_8053AB10);
        return;
    }
    if (*(u32*)(o + 0x18) != 0) {
        f32* src = *(f32**)(o + 0x18);
        for (i = 0; i < 12; i++) {
            m[i] = src[i];
        }
    } else {
        PSMTXIdentity(*(Mtx*)m);
    }
    if (lbl_805414F8 != p[2] && o[0x1f] != 0) {
        s = 1.0f / (lbl_805414FC - (p[2] >= lbl_80541500 ? p[2] : lbl_80541500));
        for (i = 0; i < 12; i++) {
            m[i] *= s;
        }
    }
    m[3] += p[0];
    m[7] += p[1] + f;
    m[11] += p[2] + f;
    fn_8013B3CC(lbl_8053AB10, m);
    *out = 1;
}

extern "C" void fn_802F9714(u8* this_, u8* src, u32 a, s32 idx, u8* dst, u32 size) {
    u8* base;
    u8* s;
    u8* d;
    u32 i;
    u32 len;
    s32 n;
    if (size == 0) {
        s32 r;
        if (JKRDecomp::checkCompressed(src)) {
            r = (src[4] << 24) | (src[5] << 16) | (src[6] << 8) | src[7];
        } else {
            void* obj = *(void**)((u8*)lbl_8053AAF8 + 0xa4);
            r = ((s32 (*)(void*, u8*))(*(void***)obj)[12])(obj, src);
        }
        if (r < 0) {
            len = 0x8000;
        } else {
            len = r;
        }
    } else {
        len = size;
    }
    dst += *(u32*)(this_ + idx * 4 + 0x88);
    if (JKRDecomp::checkCompressed(src)) {
        JKRDecomp::decode(src, *(u8**)(this_ + 0xf8), 0x8000, 0);
        base = *(u8**)(this_ + 0xf8);
    } else {
        base = src;
    }
    base += a;
    i = 0;
    if (len != 0) {
        if (len > 8) {
            for (n = len - 8; n > 0; n -= 8) {
                s = base + i;
                d = dst + i;
                d[0] = (s[0] >> 4) | (s[0] << 4);
                d[1] = (s[1] >> 4) | (s[1] << 4);
                d[2] = (s[2] >> 4) | (s[2] << 4);
                d[3] = (s[3] >> 4) | (s[3] << 4);
                d[4] = (s[4] >> 4) | (s[4] << 4);
                d[5] = (s[5] >> 4) | (s[5] << 4);
                d[6] = (s[6] >> 4) | (s[6] << 4);
                d[7] = (s[7] >> 4) | (s[7] << 4);
                i += 8;
            }
        }
        s = base + i;
        d = dst + i;
        for (n = len - i; n > 0; n--) {
            u8 b = *s++;
            *d++ = (b >> 4) | (b << 4);
        }
    }
    DCFlushRange(dst, len);
}

extern f32 lbl_80541518;
extern "C" void fn_802F86CC(Tu802F5040Tbl* base, void* elem, s32 a, s32 b, void* ptr, f32 f1, f32 f2);
extern "C" void fn_802F745C(Tu802F5040Tbl* base, void* elem, s32 a, void* ptr);
extern "C" void fn_802F6CF4(Tu802F5040Tbl* base, void* elem, s32 a, void* ptr);
extern "C" void fn_802FEE68(Tu802F5040Tbl* base);
extern "C" u16 fn_802F9908(Tu802F5040Tbl* base, s32 idx, s32 off) {
    s32 v;
    if (idx >= 0 && idx < 4) {
        v = *(u16*)(base->m_tbl[idx] + off * 2);
    } else if (idx >= 4 && idx < 8) {
        v = *(u16*)(base->m_tbl[idx] + off * 2);
    } else {
        v = *(u16*)(base->m_tbl[idx] + off * 2);
    }
    return (u16)v;
}

extern "C" void fn_802F9974(Tu802F5040Tbl* base, s32 idx, s32 off, u16 val) {
    if (idx >= 0 && idx < 4) {
        *(u16*)(base->m_tbl[idx] + off * 2) = val;
    } else if (idx >= 4 && idx < 8) {
        *(u16*)(base->m_tbl[idx] + off * 2) = val;
    } else {
        *(u16*)(base->m_tbl[idx] + off * 2) = val;
    }
}

extern "C" void fn_802F99DC(u8* this_, u8* src, u32 a, s32 idx, u32 dst, u32 size) {
    u8* base;
    u8* d;
    u32 i;
    u32 len;
    u32 n;
    u32 k;
    if (size == 0) {
        s32 r;
        if (JKRDecomp::checkCompressed(src)) {
            r = (src[4] << 24) | (src[5] << 16) | (src[6] << 8) | src[7];
        } else {
            void* obj = *(void**)((u8*)lbl_8053AAF8 + 0xa4);
            r = ((s32 (*)(void*, u8*))(*(void***)obj)[12])(obj, src);
        }
        if (r < 0) {
            len = 0x2000;
        } else {
            len = r;
        }
    } else {
        len = size;
    }
    if (JKRDecomp::checkCompressed(src)) {
        JKRDecomp::decode(src, *(u8**)(this_ + 0xf8), 0x8000, 0);
        base = *(u8**)(this_ + 0xf8);
    } else {
        base = src;
    }
    base += a;
    if (idx >= 0 && idx < 4) {
        d = *(u8**)(this_ + idx * 4 + 0x28) + (dst & ~1);
    } else if (idx >= 4 && idx < 8) {
        d = *(u8**)(this_ + idx * 4 + 0x28) + (dst & ~1);
    } else {
        d = *(u8**)(this_ + idx * 4 + 0x28) + (dst & ~1);
    }
    if (len != 0) {
        n = (len + 1) >> 1;
        i = 0;
        k = n >> 2;
        if (k != 0) {
            do {
                *(u16*)(d + (i & ~1)) = base[i] | (base[i + 1] << 8);
                i += 2;
                *(u16*)(d + (i & ~1)) = base[i] | (base[i + 1] << 8);
                i += 2;
                *(u16*)(d + (i & ~1)) = base[i] | (base[i + 1] << 8);
                i += 2;
                *(u16*)(d + (i & ~1)) = base[i] | (base[i + 1] << 8);
                i += 2;
            } while (--k != 0);
        }
        k = n & 3;
        if (k != 0) {
            do {
                *(u16*)(d + (i & ~1)) = base[i] | (base[i + 1] << 8);
                i += 2;
            } while (--k != 0);
        }
    }
}

extern "C" void fn_802F9BE8(u8* param_1, u8* param_2, s32 param_3, u32 param_4, u32 param_5)
{
  u32 size;
  u8* buf;
  u8* p;
  u32 i;
  u32 j;
  u32 n;
  u32 k;

  if (param_5 == 0) {
    if (checkCompressed__9JKRDecompFPUc(param_2) != 0) {
      size = ((u32)param_2[4] << 24) | ((u32)param_2[5] << 16) | ((u32)param_2[6] << 8) | (u32)param_2[7];
    } else {
      void* obj = *(void**)((u8*)lbl_8053AAF8 + 0xa4);
      size = ((u32 (*)(void*, u8*))(*(void***)obj)[12])(obj, param_2);
    }
    if ((s32)size < 0) {
      size = 0x2000;
    }
  } else {
    size = param_5;
  }
  if (checkCompressed__9JKRDecompFPUc(param_2) != 0) {
    decode__9JKRDecompFPUcPUcUlUl(param_2, *(u8**)(param_1 + 0xf8), 0x8000, 0);
    buf = *(u8**)(param_1 + 0xf8);
  } else {
    buf = param_2;
  }
  p = buf + param_3;
  i = param_4;
  j = param_4 & ~1;
  if (param_4 < size) {
    n = ((size + 1) - param_4) >> 1;
    k = n >> 2;
    if (k != 0) {
      do {
        *(u16*)(*(u8**)(param_1 + 0x24) + j) = p[i] | (p[i + 1] << 8);
        i += 2;
        j += 2;
        *(u16*)(*(u8**)(param_1 + 0x24) + j) = p[i] | (p[i + 1] << 8);
        i += 2;
        j += 2;
        *(u16*)(*(u8**)(param_1 + 0x24) + j) = p[i] | (p[i + 1] << 8);
        i += 2;
        j += 2;
        *(u16*)(*(u8**)(param_1 + 0x24) + j) = p[i] | (p[i + 1] << 8);
        i += 2;
        j += 2;
      } while (--k != 0);
    }
    k = n & 3;
    if (k != 0) {
      do {
        *(u16*)(*(u8**)(param_1 + 0x24) + j) = p[i] | (p[i + 1] << 8);
        i += 2;
        j += 2;
      } while (--k != 0);
    }
  }
}

extern "C" void fn_802FF0EC(u8* p) {
    bool bVar2 = false;
    s32 i = 0;
    s32* pD88 = (s32*)lbl_80506D88;
    s32* pD98 = (s32*)lbl_80506D98;
    u8* pCell = p;
    u8* pVal = p;
    u8* pBias = lbl_8053ACF0;
    do {
        if (p[i + 0x148] != 0 && *(s32*)((u8*)lbl_8053AAF8 + 0x4c) != 0xc) {
            if (p[0x214] != 0) {
                s32 iVar1 = *(s32*)(p + 0x230);
                if (i == iVar1 || iVar1 == -1) {
                    s32 x0 = *(s32*)(p + 0x21c);
                    s32 x1 = *(s32*)(p + 0x220);
                    s32 x2 = *(s32*)(p + 0x224);
                    s32 x3 = *(s32*)(p + 0x228);
                    fn_80432750(*(void**)(p + 0xfc), (-1 - iVar1) ? 0 : 1, (f32)x0, (f32)x1, (f32)x2, (f32)x3);
                    bVar2 = true;
                }
            }
            u8 bVar11 = 0;
            s32 uVar12 = 0xff;
            if (fn_80301D30(i) == 1) {
                bVar11 = *pBias >> 1;
            } else if (fn_80301D30(i) == 2) {
                if (AnimTable_IsField0xe0LessThan3(lbl_8053AD30, fn_8030AAF4(i)) != 0 || *pD88 == *pD98) {
                    uVar12 = (0x10 - *pBias) * 0x10;
                    if (uVar12 > 0xff) {
                        uVar12 = 0xff;
                    }
                }
            }
            fn_802FB69C(p, i, *(s32*)(pVal + 0x11c), pCell + 0x150, pCell + 0x190, p[i + 0x210], bVar11, (u8)uVar12);
        }
        i++;
        pD88++;
        pD98++;
        pCell += 0x10;
        pVal += 4;
        pBias++;
    } while (i < 4);
    if (bVar2) {
        fn_80432638(*(void**)(p + 0xfc));
    }
    p[0xbf98] = 0;
}

extern "C" void fn_802FF2D8(u8* this_) {
    s32 i;
    u8* p;
    u8* e;
    p = this_;
    for (i = 0; i < *(s32*)(this_ + 0xe424); i++) {
        e = p + 0xd324;
        if (*(u32*)(e + 0xc) != 0) {
            fn_802F86CC((Tu802F5040Tbl*)this_, e, *(u32*)(e + 0xc), *(u32*)(e + 0x10), e + 0x1c, lbl_80541518, lbl_80541518);
        } else if (*(u32*)(e + 0x14) != 0) {
            fn_802F745C((Tu802F5040Tbl*)this_, e, *(u32*)(e + 0x14), e + 0x1c);
        } else if (*(u32*)(e + 0x18) != 0) {
            fn_802F6CF4((Tu802F5040Tbl*)this_, e, *(u32*)(e + 0x18), e + 0x1c);
        }
        p += 0x88;
    }
    *(s32*)(this_ + 0xe424) = 0;
    fn_802FEE68((Tu802F5040Tbl*)this_);
}

extern "C" void fn_802FF3B0(u8* this_) {
    if (this_[0xe451] != 0 && *(u32*)((u8*)lbl_8053AAF8 + 0x4) != 0) {
        fn_802FA3FC(this_);
    }
}

extern "C" void fn_802FF3F0(u8* this_) {
    s32 i;
    u8* p;
    u8* e;
    u8* mgr;
    u8* video;
    Tu802F5040Rect rect;
    if (this_[0x248] != 0 && *(u32*)(this_ + 0x254) != 0) {
        mgr = *(u8**)((u8*)lbl_8053AB10 + 0x24);
        *(s32*)(mgr + 0x144) = *(s32*)(this_ + 0x24c);
        *(s32*)(mgr + 0x148) = *(s32*)(this_ + 0x250);
        *(s32*)(mgr + 0x14c) = *(s32*)(this_ + 0x254);
        *(s32*)(mgr + 0x150) = *(s32*)(this_ + 0x258);
    } else {
        video = *(u8**)((u8*)sManager__8JUTVideo + 4);
        mgr = *(u8**)((u8*)lbl_8053AB10 + 0x24);
        rect.m0c = *(u16*)(video + 6);
        rect.m08 = *(u16*)(video + 4);
        rect.m00 = 0;
        rect.m04 = 0;
        *(Tu802F5040Rect*)(mgr + 0x144) = rect;
    }
    fn_802FC80C(this_);
    p = this_;
    for (i = 0; i < *(s32*)(this_ + 0xd320); i++) {
        e = p + 0xc220;
        if (*(u32*)(e + 0xc) != 0) {
            fn_802F86CC((Tu802F5040Tbl*)this_, e, *(u32*)(e + 0xc), *(u32*)(e + 0x10), e + 0x1c, lbl_80541518, lbl_80541518);
        } else if (*(u32*)(e + 0x14) != 0) {
            fn_802F745C((Tu802F5040Tbl*)this_, e, *(u32*)(e + 0x14), e + 0x1c);
        } else if (*(u32*)(e + 0x18) != 0) {
            fn_802F6CF4((Tu802F5040Tbl*)this_, e, *(u32*)(e + 0x18), e + 0x1c);
        }
        p += 0x88;
    }
    *(s32*)(this_ + 0xd320) = 0;
}

extern "C" void fn_802FA3FC(void* mgr);
extern void* lbl_8053AAF8;
extern "C" void fn_802FA3FC(void* mgr);
extern "C" void fn_802FF548(void* mgr) {
    fn_802FF798(mgr);
}

extern "C" void fn_802FDDD4(u8* this_);
extern "C" void fn_802FCE74(u8* this_);
extern "C" u8 fn_8023F264(s32 i);
extern "C" void fn_802FF568(u8* this_) {
    u8* p;
    s32 i;
    s32 k;
    bool f;

    fn_802FDDD4(this_);
    if (((u8*)lbl_8053AAF8)[0x7f] != 0) {
        f = *(s32*)(((u8*)lbl_8053AAF8) + 0x4c) == 7 || *(s32*)(((u8*)lbl_8053AAF8) + 0x4c) == 8 || *(s32*)(((u8*)lbl_8053AAF8) + 0x4c) == 9 || *(s32*)(((u8*)lbl_8053AAF8) + 0x4c) == 0x16 || *(s32*)(((u8*)lbl_8053AAF8) + 0x4c) == 0xa || *(s32*)(((u8*)lbl_8053AAF8) + 0x4c) == 0xb;
    } else {
        f = *(s32*)(((u8*)lbl_8053AAF8) + 0x4c) == 7 || *(s32*)(((u8*)lbl_8053AAF8) + 0x4c) == 8 || *(s32*)(((u8*)lbl_8053AAF8) + 0x4c) == 9 || *(s32*)(((u8*)lbl_8053AAF8) + 0x4c) == 0x16 || *(s32*)(((u8*)lbl_8053AAF8) + 0x4c) == 0xa || *(s32*)(((u8*)lbl_8053AAF8) + 0x4c) == 0xb || *(s32*)(((u8*)lbl_8053AAF8) + 0x4c) == 0xc;
    }
    if (f == 1) {
        fn_802FCE74(this_);
    }
    p = this_;
    for (i = 0; i < 0x20; i++) {
        if (*(s32*)(p + 0x2398) > 0) {
            *(s32*)(p + 0x2398) = *(s32*)(p + 0x2398) - 1;
        }
        if (*(s32*)(p + 0x2434) > 0) {
            *(s32*)(p + 0x2434) = *(s32*)(p + 0x2434) - 1;
        }
        if (*(s32*)(p + 0x24d0) > 0) {
            *(s32*)(p + 0x24d0) = *(s32*)(p + 0x24d0) - 1;
        }
        if (*(s32*)(p + 0x256c) > 0) {
            *(s32*)(p + 0x256c) = *(s32*)(p + 0x256c) - 1;
        }
        if (*(s32*)(p + 0x2608) > 0) {
            *(s32*)(p + 0x2608) = *(s32*)(p + 0x2608) - 1;
        }
        if (*(s32*)(p + 0x26a4) > 0) {
            *(s32*)(p + 0x26a4) = *(s32*)(p + 0x26a4) - 1;
        }
        if (*(s32*)(p + 0x2740) > 0) {
            *(s32*)(p + 0x2740) = *(s32*)(p + 0x2740) - 1;
        }
        if (*(s32*)(p + 0x27dc) > 0) {
            *(s32*)(p + 0x27dc) = *(s32*)(p + 0x27dc) - 1;
        }
        p += 0x4e0;
    }
    this_[0xbf98] = 1;
    this_[0xe461] = 1;
    if (((u8*)lbl_8053AAF8)[0x7f] == 0) {
        k = 0;
        for (i = 0; i < 4; i++) {
            if (fn_8023F264(i) != 0 && ((((u8*)lbl_8053AAF8)[0x83] >> k) & 3U) == 2) {
                this_[0xe461] = 0;
                return;
            }
            k += 2;
        }
    }
}

extern "C" void* fn_802FFBF8(void* self, s16 flag) {
    struct VObj { virtual void Delete(s32); };
    u8* p = (u8*)self;
    if (p != NULL) {
        *(u8**)p = lbl_804AA858;
        __dt__10JUTTextureFv(*(void**)(p + 0xE454), 1);
        {
            u8* q; s32 i;
            i = 9; q = p + 0x24;
            do { __dt__10JUTTextureFv(*(void**)(q + 0xE428), 1); q -= 4; } while (--i >= 0);
        }
        {
            s32 i = 3; u8* q = p + 0xC;
            do { __dl__FPv(*(void**)(q + 0x11C)); q -= 4; } while (--i >= 0);
        }
        if (*(void**)(p + 0x110) != NULL) {
            __dla__FPv((u8*)*(void**)(p + 0x110) - 0x10);
        }
        {
            s32 i = 1; u8* q = p + 0x4;
            do {
                if (*(void**)(q + 0x108) != NULL) __dla__FPv((u8*)*(void**)(q + 0x108) - 0x10);
                if (*(void**)(q + 0x100) != NULL) __dla__FPv((u8*)*(void**)(q + 0x100) - 0x10);
                q -= 4;
            } while (--i >= 0);
        }
        __dla__FPv(*(void**)(p + 0xF8));
        {
            s32 i = 3; u8* q = p + 0xC;
            do {
                __dla__FPv(*(void**)(q + 0xC8));
                __dla__FPv(*(void**)(q + 0x98));
                __dla__FPv(*(void**)(q + 0x88));
                q -= 4;
            } while (--i >= 0);
        }
        {
            s32 i = 15; u8* q = p + 0x3C;
            do { __dla__FPv(*(void**)(q + 0x48)); q -= 4; } while (--i >= 0);
        }
        {
            s32 i = 3; u8* q = p + 0xC;
            do {
                __dla__FPv(*(void**)(q + 0x38));
                __dla__FPv(*(void**)(q + 0x28));
                q -= 4;
            } while (--i >= 0);
        }
        __dla__FPv(*(void**)(p + 0x24));
        {
            s32 i = 2; u8* q = p + 0x8;
            do {
                __dla__FPv(*(void**)(q + 0x18));
                __dla__FPv(*(void**)(q + 0xC));
                q -= 4;
            } while (--i >= 0);
        }
        {
            s32 i = 1; u8* q = p + 0x4;
            do { __dla__FPv(*(void**)(q + 0x4)); q -= 4; } while (--i >= 0);
        }
        if (*(VObj**)(p + 0xFC) != NULL) {
            (*(VObj**)(p + 0xFC))->Delete(1);
        }
        *(void**)(p + 0xFC) = NULL;
        __dl__FPv(*(void**)(p + 0x238C));
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

extern "C" void fn_8030029C(u8* p) {
    *(s32*)(p + 0x2c) = -1;
    *(s32*)(p + 0x30) = -1;
    u8 i = 0;
    while (i < 0x10) {
        p[(u8)(i + 0) + 0x1c] = i;
        p[(u8)(i + 1) + 0x1c] = i + 1;
        p[(u8)(i + 2) + 0x1c] = i + 2;
        p[(u8)(i + 3) + 0x1c] = i + 3;
        p[(u8)(i + 4) + 0x1c] = i + 4;
        p[(u8)(i + 5) + 0x1c] = i + 5;
        p[(u8)(i + 6) + 0x1c] = i + 6;
        p[(u8)(i + 7) + 0x1c] = i + 7;
        i += 8;
    }
    *(s32*)(p + 0x2c) = -1;
    *(s32*)(p + 0x30) = 0;
    *(s32*)(p + 0x34) = 0;
    p[0x38] = 0;
    p[0x39] = 0;
    p[0x3a] = 0;
    p[0x3b] = 1;
    p[0x3c] = 1;
    p[0x3d] = 0;
    p[0x3e] = 0;
    p[0x3f] = 0;
    p[0x40] = 0;
    p[0x41] = 0;
    p[0x42] = 1;
    *(s32*)(p + 0x44) = 3;
    p[0x48] = 1;
    p[0x49] = 0;
    p[0x4a] = 0;
    *(s32*)(p + 0x4c) = -1;
    *(s32*)(p + 0x50) = 0;
    *(s32*)(p + 0x54) = 2;
}

extern "C" void fn_803003A8(void) {}

extern "C" void fn_803003AC(void* p) {
    u8* b = (u8*)p;
    *(s32*)(b + 0x38) = -1;
    *(s32*)(b + 0x3c) = -1;
    for (u8 i = 0; i < 0x10; i += 8) {
        b[i + 0x28] = i;
        b[(u8)(i + 1) + 0x28] = i + 1;
        b[(u8)(i + 2) + 0x28] = i + 2;
        b[(u8)(i + 3) + 0x28] = i + 3;
        b[(u8)(i + 4) + 0x28] = i + 4;
        b[(u8)(i + 5) + 0x28] = i + 5;
        b[(u8)(i + 6) + 0x28] = i + 6;
        b[(u8)(i + 7) + 0x28] = i + 7;
    }
    *(s32*)(b + 0x38) = -1;
    *(s32*)(b + 0x3c) = 0;
    *(s32*)(b + 0x40) = 0;
    b[0x44] = 0;
    b[0x45] = 0;
    b[0x46] = 0;
    b[0x47] = 1;
    b[0x48] = 1;
    b[0x49] = 0;
    b[0x4a] = 0;
    b[0x4b] = 0;
    b[0x4c] = 0;
    b[0x4d] = 0;
    b[0x4e] = 1;
    *(s32*)(b + 0x50) = 3;
    b[0x54] = 1;
    b[0x55] = 0;
    b[0x56] = 0;
    *(s32*)(b + 0x58) = -1;
    *(s32*)(b + 0x5c) = 0;
    *(s32*)(b + 0x60) = 2;
    *(s32*)(b + 0x94) = -1;
    *(s32*)(b + 0x98) = -1;
}

extern "C" void fn_803004C0(void) {}

