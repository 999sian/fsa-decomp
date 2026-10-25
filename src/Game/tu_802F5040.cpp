#include "types.h"
#include "JSystem/JKernel/JKRDecomp.h"
#include <dolphin/mtx.h>
#include "JSystem/JMath/Inline.h"
#include "JSystem/JKernel/JKRHeap.h"
#include "JSystem/JUtility/JUTTexture.h"
#include "JSystem/JUtility/TColor.h"
#include "JSystem/JGeometry/Vec.h"

extern "C" s32 checkCompressed__9JKRDecompFPUc(u8*);
extern "C" void decode__9JKRDecompFPUcPUcUlUl(u8*, u8*, u32, u32);

extern "C" void __dt__10JUTTextureFv(void*, s32);
extern "C" void __dl__FPv(void*);
extern "C" void __dla__FPv(void*);
extern "C" u8 lbl_804AA858[];
extern "C" void fn_803004C0(void);
struct Tu802F5040ResMgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* getResource(u32 type, const char* name);
};
extern "C" void fn_803003AC(void* p);
extern "C" void fn_803003A8(void);
extern "C" void fn_8030029C(u8* p);

extern "C" f32 lbl_805414F8;
extern "C" f32 lbl_80541500;
extern "C" f32 lbl_805414FC;
extern "C" f64 lbl_80541508;
extern "C" f64 lbl_80541558;
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

struct Tu802F5040Mtx {
    f32 v[12];
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
extern "C" f32 fn_802F5FF4(f32 x);
extern "C" void fn_8013B1E8(void* mgr);
static inline s32 Tu802F93F4_c5(s32 v) {
    f32 f = (f32)v * lbl_80541518 + lbl_805414F8;
    s32 r = (s32)f;
    if (r < 0) {
        r = 0;
    } else if (r > 0x1f) {
        r = 0x1f;
    }
    return r;
}

extern "C" void fn_802F5040(f32* pos, u8* ent, f32* out) {
    f32 t;
    s32 a;
    s32 b;
    s32 i;
    s32 small;
    bool zpos;
    Mtx m;
    f32 s;
    u32 c;

    if (ent != NULL) {
        zpos = FALSE;
        if (*(u8*)(*(u8**)((u8*)lbl_8053AB10 + 0x20) + 0xe461) && ent[0x20]) {
            zpos = pos[2] > lbl_805414F8;
        }
        a = (s8)ent[0x1c];
        b = (s8)ent[0x1d];
        if (zpos && a < 1) {
            a += 1;
            b -= 1;
        }
        t = (f32)((a << 10) + (b << 7));
    } else {
        t = lbl_805414F8;
    }

    small = 0;
    if (ent != NULL && *(void**)(ent + 0x18) != NULL) {
        small = ent[0x25] != 0;
    } else if (pos[2] == lbl_805414F8 || (ent != NULL && ent[0x1f] == 0)) {
        small = 1;
    }

    if (small == 0) {
        if (ent != NULL && *(void**)(ent + 0x18) != NULL) {
            PSMTXCopy(*(MtxPtr*)(ent + 0x18), m);
        } else {
            PSMTXIdentity(m);
        }
        if (pos[2] != lbl_805414F8 && (ent == NULL || ent[0x1f] != 0)) {
            s = fn_802F5FF4(pos[2]);
            for (i = 0; i < 12; i++) {
                ((f32*)m)[i] *= s;
            }
        }
        m[0][3] += pos[0];
        m[1][3] += pos[1] + t;
        m[2][3] += pos[2] + t;
        fn_8013B3CC(lbl_8053AB10, m);
        out[0] = lbl_805414F8;
        out[1] = lbl_805414F8;
        out[2] = lbl_805414F8;
    } else {
        fn_8013B3F0(lbl_8053AB10);
        out[0] = pos[0];
        out[1] = pos[1] + t;
        out[2] = pos[2] + t;
    }
    fn_8013B1E8(lbl_8053AB10);

    if (ent != NULL && *(s32*)(ent + 0x34) == 1) {
        GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_ONE, GX_LO_NOOP);
    } else if (ent != NULL && *(s32*)(ent + 0x34) == 2) {
        GXSetBlendMode(GX_BM_BLEND, GX_BL_DSTALPHA, GX_BL_INVDSTALPHA, GX_LO_NOOP);
    } else {
        GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_NOOP);
    }
    if (ent != NULL) {
        c = *(u32*)(ent + 0x10);
        GXSetTevColor(GX_TEVREG1, *(GXColor*)&c);
        c = *(u32*)(ent + 0x14);
        GXSetTevColor(GX_TEVREG2, *(GXColor*)&c);
        GXSetZMode(ent[0x26], GX_LEQUAL, ent[0x2c]);
    }
    if (ent != NULL && ent[0x2d] != 0) {
        GXSetAlphaUpdate(GX_TRUE);
    }
}

extern "C" void fn_803068D0(void* hdr);
extern "C" s32 fn_8022EA0C(s32 idx);
extern "C" void fn_802F53F4(u8* this_, s32 idx, u8* data);
extern u8 lbl_80506DA8[];
extern u8 lbl_80506DB8[];
extern u8 lbl_80506DC8[];
extern u8 lbl_80506DD8[];
extern "C" void fn_802F53F4(u8* this_, s32 idx, u8* data) {
    if (((data[2] >> 2) & 7) != 0) {
        u32 kind = (data[3] >> 4) & 0xf;
        if (kind == 5 || kind == 0xe) {
            u32* s = (u32*)data - 1;
            u32* d = *(u32**)(this_ + idx * 4 + 0x11c) - 1;
            s32 n = 13;
            do {
                d[1] = s[1];
                d[2] = s[2];
                s += 2;
                d += 2;
            } while (--n != 0);
            if (((data[2] >> 6) & 3) == 2) {
                this_[idx + 0x134] = (data[5] >> 7) & 1;
            } else if (((data[2] >> 6) & 3) == 3) {
                this_[idx + 0x130] = (data[4] >> 5) & 3;
            }
            if (((data[2] >> 6) & 1) != 0) {
                u8* a = lbl_80506DA8 + idx * 4;
                u8* b = lbl_80506DB8 + idx * 4;
                u8* c = lbl_80506DC8 + idx * 4;
                u32* dd = (u32*)lbl_80506DD8;
                for (s32 i = 0; i < 4; i++) {
                    a[i] = (data[6] >> (i * 2)) & 3;
                    b[i] = ((data[7] >> 4) >> i) & 1;
                    c[i] = ((data[7] & 0xf) >> i) & 1;
                    dd[idx] = fn_8022EA0C(idx);
                }
            }
        }
        this_[idx + 0x12c] = 1;
        fn_803068D0(*(void**)(this_ + idx * 4 + 0x11c));
    }
}

extern "C" void fn_802F5570(u8* this_, f32* src, u8* ent, f32* outPos, u8** outEnt, MtxPtr mtx, u8* dst) {
    if (ent == NULL || *(s32*)(ent + 0x38) == 2) {
        if (fn_802F58A8(this_, src, mtx) != 0 && ent != NULL) {
            *(u32*)(dst + 0x0) = *(u32*)(ent + 0x0);
            *(u32*)(dst + 0x4) = *(u32*)(ent + 0x4);
            *(u32*)(dst + 0x8) = *(u32*)(ent + 0x8);
            *(u32*)(dst + 0xc) = *(u32*)(ent + 0xc);
            dst[0x10] = ent[0x10];
            dst[0x11] = ent[0x11];
            dst[0x12] = ent[0x12];
            dst[0x13] = ent[0x13];
            dst[0x14] = ent[0x14];
            dst[0x15] = ent[0x15];
            dst[0x16] = ent[0x16];
            dst[0x17] = ent[0x17];
            *(u32*)(dst + 0x18) = *(u32*)(ent + 0x18);
            dst[0x1c] = ent[0x1c];
            dst[0x1d] = ent[0x1d];
            dst[0x1e] = ent[0x1e];
            dst[0x1f] = ent[0x1f];
            dst[0x20] = ent[0x20];
            dst[0x21] = ent[0x21];
            dst[0x22] = ent[0x22];
            dst[0x23] = ent[0x23];
            dst[0x24] = ent[0x24];
            dst[0x25] = ent[0x25];
            dst[0x26] = ent[0x26];
            *(u32*)(dst + 0x28) = *(u32*)(ent + 0x28);
            dst[0x2c] = ent[0x2c];
            dst[0x2d] = ent[0x2d];
            dst[0x2e] = ent[0x2e];
            *(u32*)(dst + 0x30) = *(u32*)(ent + 0x30);
            *(u32*)(dst + 0x34) = *(u32*)(ent + 0x34);
            *(u32*)(dst + 0x38) = *(u32*)(ent + 0x38);
            if (*(MtxPtr*)(dst + 0x18) != NULL) {
                PSMTXConcat(*(MtxPtr*)(dst + 0x18), mtx, mtx);
                *(MtxPtr*)(dst + 0x18) = mtx;
                *outEnt = dst;
            } else {
                *outEnt = ent;
            }
        } else {
            *outEnt = ent;
        }
        outPos[0] = src[0];
        outPos[1] = src[1];
        outPos[2] = src[2];
    } else {
        f32 fVar3 = src[2];
        f32 fVar4 = fVar3;
        if (*(s32*)(ent + 0x38) == 1 && 0 < *(s32*)(this_ + 0xc21c)) {
            f32 fVar5 = src[0];
            f32 fVar6 = *(f32*)(this_ + 0x2368);
            if (fVar6 <= fVar5 && fVar5 < lbl_80541510 * (f32)*(s32*)(this_ + 0x2380) + fVar6) {
                f32 fVar7 = src[1];
                f32 fVar8 = *(f32*)(this_ + 0x236c);
                if (fVar8 <= fVar7 && fVar7 < lbl_80541510 * (f32)*(s32*)(this_ + 0x2384) + fVar8) {
                    u32 uVar1 = (u32)(lbl_80541514 * (fVar5 - fVar6));
                    u32 uVar2 = (u32)(lbl_80541514 * (fVar7 - fVar8));
                    u8* cell = *(u8**)(this_ + *(s32*)(this_ + 0x2388) * 4 + 0x100) + uVar2 * 0x30c + uVar1 * 0xc;
                    f32 fx = lbl_80541514 * ((fVar5 - fVar6) - lbl_80541510 * (f32)uVar1);
                    f32 fy = lbl_80541514 * ((fVar7 - fVar8) - lbl_80541510 * (f32)uVar2);
                    f32 a = *(f32*)(cell + 0x8);
                    f32 b = *(f32*)(cell + 0x14);
                    f32 c = *(f32*)(cell + 0x314);
                    f32 d = *(f32*)(cell + 0x320);
                    f32 r0 = a * (lbl_80541518 - fx) + b * fx;
                    f32 r1 = c * (lbl_80541518 - fx) + d * fx;
                    fVar4 = fVar3 + ((lbl_80541518 - fy) * r0 + fy * r1);
                    fVar3 = fVar3 + fVar4;
                    *outEnt = ent;
                    outPos[0] = src[0];
                    outPos[1] = src[1];
                    outPos[2] = fVar3;
                    return;
                }
            }
        }
        outPos[0] = src[0];
        outPos[1] = src[1];
        outPos[2] = fVar3;
        *outEnt = ent;
    }
}

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
    f32 v = (x >= lbl_80541500) ? x : lbl_80541500;
    return a / (a - v);
}

#include "JSystem/JMath/JMath.h"
extern f64 __frsqrte(f64);

static inline void Tu802F5040_setVec(f32* dst, f32 x, f32 y, f32 z) {
    dst[0] = x;
    dst[1] = y;
    dst[2] = z;
}
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
        if (mag <= 32.0f * *(f32*)&__float_epsilon) {
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
    BOOL ret = FALSE;
    s32 n = *(s32*)(self + 0xe424);
    if (n < 0x20) {
        u8* e = self + n * 0x88 + 0xd324;
        u8 i;
        Tu802F5040_setVec((f32*)e, pos->x, pos->y, pos->z);
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
                JMath::gekko_ps_copy12(e + 0x58, *(u8**)(src + 0x18));
                *(u8**)(e + 0x34) = e + 0x58;
            }
        } else {
            for (i = 0; i < 0x10; i++) {
                e[i + 0x1c] = i;
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
        ret = TRUE;
        *(s32*)(self + 0xe424) = *(s32*)(self + 0xe424) + 1;
    }
    return ret;
}

extern "C" u8 fn_802F654C(u8* self, f32* pos, s32 a, s32 b, s32 c, s32 d, u8* src) {
    u8 ret = 0;
    s32 n = *(s32*)(self + 0xd320);
    if (n < 0x20) {
        u8* e = self + n * 0x88 + 0xc220;
        f32 z = pos[2];
        f32 y = pos[1];
        f32 x = pos[0];
        *(f32*)(e + 0x0) = x;
        *(f32*)(e + 0x4) = y;
        *(f32*)(e + 0x8) = z;
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
                *(Tu802F5040Mtx*)(e + 0x58) = *(Tu802F5040Mtx*)(*(u8**)(src + 0x18));
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

extern "C" u8 lbl_8046F940[];
extern "C" void* lbl_8053AAF8;
extern "C" u8 fn_802F6800(u8* this_, f32* src, s32 param_3, s32 param_4, s32 param_5, s32 param_6, u8* param_7) {
    s32 i;
    u8* p;
    u8* c1;
    u8* c2;
    s32 off;
    s32 div;
    u8 done;
    s32 t;
    u8 a0;
    u8 a1;
    u8 a2;
    u8 a3;

    done = 0;
    off = *(s32*)(param_7 + 0x30) * 4;
    div = *(s32*)(lbl_8046F940 + 0x1840 + off);
    if (this_[0xbf98] != 0 && (u32)(param_3 + (param_5 + param_6)) % (u32)div == *(s32*)((u8*)lbl_8053AAF8 + 0x5c) % div) {
        p = this_;
        for (i = 0; i < 0x100; i++) {
            if (*(s32*)(p + 0x2398) == 0) {
                c1 = lbl_8046F940 + 0x1720 + off;
                c2 = lbl_8046F940 + 0x1768 + off;
                *(s32*)(p + 0x2398) = *(s32*)(lbl_8046F940 + 0x17b0 + off);
                *(f32*)(p + 0x23a0) = ((f32*)(lbl_8046F940 + 0x17f8))[*(s32*)(param_7 + 0x30)];
                *(s32*)(p + 0x239c) = *(s32*)(p + 0x2398);
                *(f32*)(p + 0x23a4) = src[0];
                *(f32*)(p + 0x23a8) = src[1];
                *(f32*)(p + 0x23ac) = src[2];
                *(s32*)(p + 0x23b0) = param_3;
                *(s32*)(p + 0x23b4) = param_4;
                *(s32*)(p + 0x23b8) = param_5;
                *(s32*)(p + 0x23bc) = param_6;
                *(u8*)(p + 0x242c) = (u8)((param_7[0x10] * c1[0]) / 0xff);
                *(u8*)(p + 0x242d) = (u8)((param_7[0x11] * c1[1]) / 0xff);
                *(u8*)(p + 0x242e) = (u8)((param_7[0x12] * c1[2]) / 0xff);
                *(u8*)(p + 0x242f) = (u8)((param_7[0x13] * c1[3]) / 0xff);
                a3 = 0xff;
                t = param_7[0x17] + c2[3];
                if (t < 0xff) {
                    a3 = t;
                }
                a2 = 0xff;
                t = param_7[0x16] + c2[2];
                if (t < 0xff) {
                    a2 = t;
                }
                a1 = 0xff;
                t = param_7[0x15] + c2[1];
                if (t < 0xff) {
                    a1 = t;
                }
                a0 = 0xff;
                t = param_7[0x14] + c2[0];
                if (t < 0xff) {
                    a0 = t;
                }
                *(u8*)(p + 0x2430) = a0;
                *(u8*)(p + 0x2431) = a1;
                *(u8*)(p + 0x2432) = a2;
                *(u8*)(p + 0x2433) = a3;
                *(u32*)(p + 0x23c0) = *(u32*)(param_7 + 0x0);
                *(u32*)(p + 0x23c4) = *(u32*)(param_7 + 0x4);
                *(u32*)(p + 0x23c8) = *(u32*)(param_7 + 0x8);
                *(u32*)(p + 0x23cc) = *(u32*)(param_7 + 0xc);
                *(u8*)(p + 0x23d0) = param_7[0x10];
                *(u8*)(p + 0x23d1) = param_7[0x11];
                *(u8*)(p + 0x23d2) = param_7[0x12];
                *(u8*)(p + 0x23d3) = param_7[0x13];
                *(u8*)(p + 0x23d4) = param_7[0x14];
                *(u8*)(p + 0x23d5) = param_7[0x15];
                *(u8*)(p + 0x23d6) = param_7[0x16];
                *(u8*)(p + 0x23d7) = param_7[0x17];
                *(u32*)(p + 0x23d8) = *(u32*)(param_7 + 0x18);
                *(u8*)(p + 0x23dc) = param_7[0x1c];
                *(u8*)(p + 0x23dd) = param_7[0x1d];
                *(u8*)(p + 0x23de) = param_7[0x1e];
                *(u8*)(p + 0x23df) = param_7[0x1f];
                *(u8*)(p + 0x23e0) = param_7[0x20];
                *(u8*)(p + 0x23e1) = param_7[0x21];
                *(u8*)(p + 0x23e2) = param_7[0x22];
                *(u8*)(p + 0x23e3) = param_7[0x23];
                *(u8*)(p + 0x23e4) = param_7[0x24];
                *(u8*)(p + 0x23e5) = param_7[0x25];
                *(u8*)(p + 0x23e6) = param_7[0x26];
                *(u32*)(p + 0x23e8) = *(u32*)(param_7 + 0x28);
                *(u8*)(p + 0x23ec) = param_7[0x2c];
                *(u8*)(p + 0x23ed) = param_7[0x2d];
                *(u8*)(p + 0x23ee) = param_7[0x2e];
                *(u32*)(p + 0x23f0) = *(u32*)(param_7 + 0x30);
                *(u32*)(p + 0x23f4) = *(u32*)(param_7 + 0x34);
                *(u32*)(p + 0x23f8) = *(u32*)(param_7 + 0x38);
                *(u8*)(p + 0x23ec) = 0;
                *(u8*)(p + 0x23ed) = 1;
                *(u8*)(p + 0x23ee) = 0;
                *(s32*)(p + 0x23f0) = -1;
                *(s32*)(p + 0x23f8) = 0;
                *(u8*)(p + 0x23dc) = param_7[0x1c];
                *(u8*)(p + 0x23dd) = param_7[0x1d] - 1;
                if (*(u32*)(param_7 + 0x18) != 0) {
                    PSMTXCopy((MtxPtr)*(u32*)(param_7 + 0x18), (MtxPtr)(p + 0x23fc));
                    *(u32*)(p + 0x23d8) = (u32)(p + 0x23fc);
                } else if (lbl_80541518 != *(f32*)(p + 0x23a0)) {
                    PSMTXIdentity((MtxPtr)(p + 0x23fc));
                    *(u32*)(p + 0x23d8) = (u32)(p + 0x23fc);
                    done = 1;
                    break;
                }
            }
            p += 0x9c;
        }
    }
    return done;
}

extern "C" void fn_802F6BBC(Tu802F5040Tbl* base, s32 src, s32 dst) {
    u16* s;
    u16* d;
    u32 n;
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
    } while (--n);
}

extern GXColor lbl_805414F4;
extern GXColor lbl_80543F60;
extern "C" void fn_802F8F0C(void*, u8* p) {
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
        GXSetTevColor(GX_TEVREG0, *(GXColor*)(p + 0x10));
        GXSetTevColor(GX_TEVREG1, *(GXColor*)(p + 0x14));
    } else {
        GXSetTevColor(GX_TEVREG0, lbl_805414F4);
        GXSetTevColor(GX_TEVREG1, lbl_80543F60);
    }
    GXSetTevColorIn(GX_TEVSTAGE0, (GXTevColorArg)0xf, (GXTevColorArg)8, (GXTevColorArg)2, (GXTevColorArg)4);
    GXSetTevAlphaIn(GX_TEVSTAGE0, (GXTevAlphaArg)7, (GXTevAlphaArg)4, (GXTevAlphaArg)1, (GXTevAlphaArg)2);
    GXSetTevColorOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevAlphaOp(GX_TEVSTAGE0, GX_TEV_ADD, GX_TB_ZERO, GX_CS_SCALE_1, GX_TRUE, GX_TEVPREV);
    GXSetTevSwapMode(GX_TEVSTAGE0, GX_TEV_SWAP0, GX_TEV_SWAP0);
    GXSetNumTevStages(1);
    GXSetNumIndStages(0);
    if (p != NULL && *(s32*)(p + 0x34) == 1) {
        GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_ONE, GX_LO_NOOP);
    } else if (p != NULL && *(s32*)(p + 0x34) == 2) {
        GXSetBlendMode(GX_BM_BLEND, GX_BL_DSTALPHA, GX_BL_INVDSTALPHA, GX_LO_NOOP);
    } else {
        GXSetBlendMode(GX_BM_BLEND, GX_BL_SRCALPHA, GX_BL_INVSRCALPHA, GX_LO_NOOP);
    }
    if (p != NULL) {
        u8 zc = *(u8*)(p + 0x2c);
        GXSetZMode(*(u8*)(p + 0x26), (GXCompare)*(s32*)(p + 0x28), zc);
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
        PSMTXCopy(*(MtxPtr*)(o + 0x18), *(MtxPtr*)m);
        if (lbl_805414F8 == m[0] && lbl_805414F8 == m[5] && lbl_805414F8 == m[10]) {
            m[0] = lbl_80541518;
            m[5] = lbl_80541518;
            m[10] = lbl_80541518;
        }
    } else {
        PSMTXIdentity(*(MtxPtr*)m);
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

extern "C" void fn_802F93F4(u8* this_, u8* src, u32 srcOff, u32 idx, u32 dstOff, s32 n, u8 flag) {
    s32 size = n;
    u32 k;
    u32 cnt;
    u8* d;
    u16 v;
    u16 o;
    s32 a;
    s32 b;
    s32 c;

    if (size == 0) {
        if (checkCompressed__9JKRDecompFPUc(src) != 0) {
            size = (src[4] << 24) | (src[5] << 16) | (src[6] << 8) | src[7];
        } else {
            u8* dec = *(u8**)((u8*)lbl_8053AAF8 + 0xa4);
            size = (*(s32 (**)(u8*, u8*))(*(u8**)dec + 0x30))(dec, src);
        }
        if (size < 0) {
            size = 0x200;
        }
    }

    if (checkCompressed__9JKRDecompFPUc(src) != 0) {
        decode__9JKRDecompFPUcPUcUlUl(src, *(u8**)(this_ + 0xf8), 0x8000, 0);
        src = *(u8**)(this_ + 0xf8);
    }

    cnt = ((u32)size + 1) >> 1;
    k = 0;
    if (size != 0) {
        do {
            if (k == 0 || (k & 0x1f) != 0) {
                u8 b1 = src[srcOff + k + 1];
                u8 b0 = src[srcOff + k];
                v = ((b1 >> 2) & 0x1f) | ((b0 & 0x1f) << 10) | (((b1 << 8) | b0) & 0x3e0) | 0x8000;
                if (k == 0) {
                    v = 0;
                }
            } else {
                v = 0;
            }
            d = *(u8**)(this_ + idx * 4 + 0x98) + dstOff;
            d[k] = v >> 8;
            d[k + 1] = v;
            k += 2;
        } while (--cnt != 0);
    }

    cnt = ((u32)size + 1) >> 1;
    k = 0;
    if (size != 0) {
        do {
            u16* p = (u16*)(*(u8**)(this_ + idx * 4 + 0x98) + dstOff + k);
            v = *p;
            if (v & 0x8000) {
                a = Tu802F93F4_c5((v >> 10) & 0x1f);
                b = Tu802F93F4_c5((v >> 5) & 0x1f);
                c = Tu802F93F4_c5(v & 0x1f);
                if (flag == 0) {
                    o = (c & 0xff) | ((a & 0x3f) << 10) | 0x8000 | ((b & 0xff) << 5);
                } else {
                    o = (b & 0xff) | ((c & 0x3f) << 10) | 0x8000 | ((a & 0xff) << 5);
                }
                v = o;
            }
            d = *(u8**)(this_ + idx * 4 + 0xc8) + dstOff;
            d[k] = v >> 8;
            d[k + 1] = v;
            k += 2;
        } while (--cnt != 0);
    }
    DCFlushRange(*(u8**)(this_ + idx * 4 + 0xc8) + dstOff, size);
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
        d = ((u8**)(this_ + idx * 4))[10] + (dst & ~1);
    } else if (idx >= 4 && idx < 8) {
        d = ((u8**)(this_ + idx * 4))[10] + (dst & ~1);
    } else {
        d = ((u8**)(this_ + idx * 4))[10] + (dst & ~1);
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
  s32 sz;
  u8* buf;
  u8* p;
  u32 i;
  u32 j;
  u32 n;
  u32 k;

  if (param_5 == 0) {
    if (checkCompressed__9JKRDecompFPUc(param_2) != 0) {
      sz = ((u32)param_2[4] << 24) | ((u32)param_2[5] << 16) | ((u32)param_2[6] << 8) | (u32)param_2[7];
    } else {
      void* obj = *(void**)((u8*)lbl_8053AAF8 + 0xa4);
      sz = ((s32 (*)(void*, u8*))(*(void***)obj)[12])(obj, param_2);
    }
    if (sz < 0) {
      size = 0x2000;
    } else {
      size = sz;
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
  if (param_4 < size) {
    i = param_4;
    j = param_4 & ~1;
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

extern "C" void fn_802F9DA8(u8* this_, u8* src, u32 srcOff, s32 idx, u32 dstOff, u32 size, u8 flag) {
    u8* base;
    u8* d;
    u8* s;
    u32 i;
    u32 len;
    u16 keep;
    u16 v;
    if (size == 0) {
        s32 r;
        if (JKRDecomp::checkCompressed(src)) {
            r = (src[4] << 24) | (src[5] << 16) | (src[6] << 8) | src[7];
        } else {
            void* obj = *(void**)((u8*)lbl_8053AAF8 + 0xa4);
            r = ((s32 (*)(void*, u8*))(*(void***)obj)[12])(obj, src);
        }
        if (r < 0) {
            len = 0x200;
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
    base += srcOff;
    d = *(u8**)(this_ + idx * 4 + 0xc) + dstOff;
    s = base;
    for (i = 0; i < len; i += 2) {
        v = 0;
        if (i == 0 || (i & 0x1f) != 0) {
            u32 w = s[0] | (s[1] << 8);
            u16 c = ((w & 0x1f) << 10) | (w & 0x3e0) | ((w >> 10) & 0x1f) | 0x8000;
            if (i == 0) {
                keep = c;
            } else {
                v = c;
            }
        }
        d[i] = v >> 8;
        d[i + 1] = v;
        s += 2;
    }
    *(u16*)(this_ + idx * 2 + 0x114) = keep;
    {
        u8* t = *(u8**)(this_ + idx * 4 + 0xc);
        u16 w = (t[0x1b0] << 8) | t[0x1b1];
        u16 x = 0x4000 | ((w >> 2) & 0xf0) | ((w >> 1) & 0xf);
        t[0x1b0] = x >> 8;
        t[0x1b1] = x;
    }
    {
        u8* t = *(u8**)(this_ + idx * 4 + 0xc);
        u16 w = (t[0x1b2] << 8) | t[0x1b3];
        u16 x = 0x4000 | ((w >> 2) & 0xf0) | ((w >> 1) & 0xf);
        t[0x1b2] = x >> 8;
        t[0x1b3] = x;
    }
    {
        u8* t = *(u8**)(this_ + idx * 4 + 0xc);
        u16 w = (t[0x1b4] << 8) | t[0x1b5];
        u16 x = 0x4000 | ((w >> 2) & 0xf0) | ((w >> 1) & 0xf);
        t[0x1b4] = x >> 8;
        t[0x1b5] = x;
    }
    s = *(u8**)(this_ + idx * 4 + 0xc) + dstOff;
    d = *(u8**)(this_ + idx * 4 + 0x18) + dstOff;
    for (i = 0; i < len; i += 2) {
        u16 w = (s[i] << 8) | s[i + 1];
        v = w;
        if (w & 0x8000) {
            s32 r;
            u8 a;
            u8 b;
            u8 c;
            r = (s32)((f32)((w >> 10) & 0x1f) * lbl_80541518 + lbl_805414F8);
            if (r < 0) {
                r = 0;
            } else if (r > 0x1f) {
                r = 0x1f;
            }
            a = r;
            r = (s32)((f32)((w >> 5) & 0x1f) * lbl_80541518 + lbl_805414F8);
            if (r < 0) {
                r = 0;
            } else if (r > 0x1f) {
                r = 0x1f;
            }
            b = r;
            r = (s32)((f32)(w & 0x1f) * lbl_80541518 + lbl_805414F8);
            if (r < 0) {
                r = 0;
            } else if (r > 0x1f) {
                r = 0x1f;
            }
            c = r;
            if (flag != 0) {
                v = 0x8000 | (c << 10) | (a << 5) | b;
            } else {
                v = 0x8000 | (a << 10) | (b << 5) | c;
            }
        }
        d[i] = v >> 8;
        d[i + 1] = v;
    }
    DCFlushRange(d, len);
}

extern "C" void fn_802FA160(u8* this_, u8* src, u32 a, s32 idx, u8* dst, u32 size) {
    u8* base;
    u8* s;
    u8* d;
    u32 i;
    u32 len;
    s32 n;
    u8* p;
    u8* q;
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
    dst += *(u32*)(this_ + idx * 4 + 0x4);
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
    if (idx == 1) {
        p = *(u8**)(this_ + 8) + 0x200;
        q = *(u8**)(this_ + 0x238c);
        for (n = 0x10; n > 0; n--) {
            q[0] = p[0];
            q[1] = p[1];
            q[2] = p[2];
            q[3] = p[3];
            q[4] = p[4];
            q[5] = p[5];
            q[6] = p[6];
            q[7] = p[7];
            q[8] = p[8];
            q[9] = p[9];
            q[10] = p[10];
            q[11] = p[11];
            q[12] = p[12];
            q[13] = p[13];
            q[14] = p[14];
            q[15] = p[15];
            p += 0x10;
            q += 0x10;
        }
    }
}

extern "C" void fn_8013B438(void* mgr);
extern "C" void* fn_802D6A9C();
extern "C" void load__10JUTTextureF11_GXTexMapID(void* tex, s32 id);
extern "C" void fn_802FC268(u8* this_, u8* arr, s32 i, u32 v);
extern "C" u32 lbl_805414E8;
extern "C" void fn_802FC80C(u8* this_) {
    s32 i;
    u8* mgr;
    bool flag;
    s32 idx;

    fn_8013B1E8(lbl_8053AB10);
    fn_8013B438(lbl_8053AB10);
    GXClearVtxDesc();
    GXSetVtxDesc((GXAttr)9, (GXAttrType)3);
    GXSetVtxDesc((GXAttr)0xb, (GXAttrType)3);
    GXSetVtxDesc((GXAttr)0xd, (GXAttrType)3);
    GXSetVtxDesc((GXAttr)0xe, (GXAttrType)1);
    GXSetVtxAttrFmt((GXVtxFmt)0, (GXAttr)9, (GXCompCnt)1, (GXCompType)4, 0);
    GXSetVtxAttrFmt((GXVtxFmt)0, (GXAttr)0xb, (GXCompCnt)0, (GXCompType)5, 0);
    GXSetVtxAttrFmt((GXVtxFmt)0, (GXAttr)0xd, (GXCompCnt)1, (GXCompType)4, 0);
    GXSetVtxAttrFmt((GXVtxFmt)0, (GXAttr)0xe, (GXCompCnt)1, (GXCompType)4, 0);
    GXSetArray((GXAttr)9, ((void**)this_)[*(s32*)(this_ + 0x2388) + 0x40], 0xc);
    GXSetArray((GXAttr)0xb, ((void**)this_)[*(s32*)(this_ + 0x2388) + 0x42], 4);
    GXSetArray((GXAttr)0xd, *(void**)(this_ + 0x110), 8);
    GXSetChanCtrl((GXChannelID)4, (GXBool)0, (GXColorSrc)0, (GXColorSrc)1, 0, (GXDiffuseFn)0, (GXAttnFn)2);
    GXSetNumChans(1);
    GXSetTexCoordGen2((GXTexCoordID)1, (GXTexGenType)1, (GXTexGenSrc)5, (GXTexMtx)0x3c, (GXBool)0, (GXPTTexMtx)0x7d);
    GXSetNumTexGens(2);
    GXSetTevOrder((GXTevStageID)0, (GXTexCoordID)0, (GXTexMapID)0, (GXChannelID)4);
    GXSetTevColorIn((GXTevStageID)0, (GXTevColorArg)0xf, (GXTevColorArg)0xc, (GXTevColorArg)0xa, (GXTevColorArg)8);
    GXSetTevAlphaIn((GXTevStageID)0, (GXTevAlphaArg)7, (GXTevAlphaArg)6, (GXTevAlphaArg)5, (GXTevAlphaArg)4);
    GXSetTevColorOp((GXTevStageID)0, (GXTevOp)0, (GXTevBias)2, (GXTevScale)0, (GXBool)1, (GXTevRegID)0);
    GXSetTevAlphaOp((GXTevStageID)0, (GXTevOp)0, (GXTevBias)2, (GXTevScale)0, (GXBool)1, (GXTevRegID)0);
    GXSetTevSwapMode((GXTevStageID)0, (GXTevSwapSel)0, (GXTevSwapSel)0);
    GXSetTevDirect((GXTevStageID)0);
    if (this_[0xe450] != 0) {
        mgr = (u8*)lbl_8053AAF8;
        if (mgr[0x7f] != 0) {
            flag = (*(s32*)(mgr + 0x4c) == 0x7 || *(s32*)(mgr + 0x4c) == 0x8 || *(s32*)(mgr + 0x4c) == 0x9 || *(s32*)(mgr + 0x4c) == 0x16 || *(s32*)(mgr + 0x4c) == 0xa || *(s32*)(mgr + 0x4c) == 0xb);
        } else {
            flag = (*(s32*)(mgr + 0x4c) == 0x7 || *(s32*)(mgr + 0x4c) == 0x8 || *(s32*)(mgr + 0x4c) == 0x9 || *(s32*)(mgr + 0x4c) == 0x16 || *(s32*)(mgr + 0x4c) == 0xa || *(s32*)(mgr + 0x4c) == 0xb || *(s32*)(mgr + 0x4c) == 0xc);
        }
        if (flag && *(void**)(mgr + 0x4) != NULL) {
            idx = *(s32*)((u8*)fn_802D6A9C() + 0x50);
        } else {
            idx = 0;
        }
        load__10JUTTextureF11_GXTexMapID(((void**)(this_ + 0xE428))[idx], 1);
        GXSetTevOrder((GXTevStageID)1, (GXTexCoordID)1, (GXTexMapID)1, (GXChannelID)0xff);
        GXSetTevColorIn((GXTevStageID)1, (GXTevColorArg)0xf, (GXTevColorArg)0, (GXTevColorArg)8, (GXTevColorArg)0xf);
        GXSetTevAlphaIn((GXTevStageID)1, (GXTevAlphaArg)7, (GXTevAlphaArg)7, (GXTevAlphaArg)7, (GXTevAlphaArg)0);
        GXSetTevColorOp((GXTevStageID)1, (GXTevOp)0, (GXTevBias)0, (GXTevScale)0, (GXBool)1, (GXTevRegID)1);
        GXSetTevAlphaOp((GXTevStageID)1, (GXTevOp)0, (GXTevBias)0, (GXTevScale)0, (GXBool)1, (GXTevRegID)0);
        GXSetTevSwapMode((GXTevStageID)1, (GXTevSwapSel)0, (GXTevSwapSel)0);
        GXSetTevDirect((GXTevStageID)1);
        GXSetTevOrder((GXTevStageID)2, (GXTexCoordID)0xff, (GXTexMapID)0xff, (GXChannelID)0xff);
        GXSetTevColorIn((GXTevStageID)2, (GXTevColorArg)0xf, (GXTevColorArg)0xc, (GXTevColorArg)2, (GXTevColorArg)0);
        GXSetTevAlphaIn((GXTevStageID)2, (GXTevAlphaArg)7, (GXTevAlphaArg)7, (GXTevAlphaArg)7, (GXTevAlphaArg)0);
        GXSetTevColorOp((GXTevStageID)2, (GXTevOp)1, (GXTevBias)0, (GXTevScale)0, (GXBool)1, (GXTevRegID)0);
        GXSetTevAlphaOp((GXTevStageID)2, (GXTevOp)0, (GXTevBias)0, (GXTevScale)0, (GXBool)1, (GXTevRegID)0);
        GXSetTevSwapMode((GXTevStageID)2, (GXTevSwapSel)0, (GXTevSwapSel)0);
        GXSetTevDirect((GXTevStageID)2);
        GXSetTevColor((GXTevRegID)2, *(GXColor*)&lbl_805414E8);
        GXSetTevOrder((GXTevStageID)3, (GXTexCoordID)0xff, (GXTexMapID)0xff, (GXChannelID)0xff);
        GXSetTevColorIn((GXTevStageID)3, (GXTevColorArg)5, (GXTevColorArg)1, (GXTevColorArg)0, (GXTevColorArg)2);
        GXSetTevAlphaIn((GXTevStageID)3, (GXTevAlphaArg)7, (GXTevAlphaArg)7, (GXTevAlphaArg)7, (GXTevAlphaArg)0);
        GXSetTevColorOp((GXTevStageID)3, (GXTevOp)8, (GXTevBias)0, (GXTevScale)0, (GXBool)1, (GXTevRegID)0);
        GXSetTevAlphaOp((GXTevStageID)3, (GXTevOp)0, (GXTevBias)0, (GXTevScale)0, (GXBool)1, (GXTevRegID)0);
        GXSetTevSwapMode((GXTevStageID)3, (GXTevSwapSel)0, (GXTevSwapSel)0);
        GXSetTevDirect((GXTevStageID)3);
        GXSetNumTevStages(4);
    } else {
        GXSetNumTevStages(1);
    }
    GXSetNumIndStages(0);
    GXInvalidateVtxCache();
    GXSetCullMode((GXCullMode)0);
    for (i = 0; i <= 8; i++) {
        if (i < 4 && this_[i + 0x235c] != 0) {
            if (i == 0 && this_[0x2365] != 0) {
                GXSetAlphaCompare((GXCompare)2, 0xff, (GXAlphaOp)1, (GXCompare)0, 0);
                GXSetZMode((GXBool)1, (GXCompare)3, (GXBool)1);
            } else {
                GXSetAlphaCompare((GXCompare)4, 0, (GXAlphaOp)0, (GXCompare)7, 0);
                GXSetZMode((GXBool)1, (GXCompare)3, (GXBool)1);
            }
            fn_802FC268(this_, this_ + 0x2368, i, *(u32*)(this_ + i * 4 + 0x28));
        } else if (i >= 4 && i < 8 && this_[i + 0x235c] != 0) {
            GXSetAlphaCompare((GXCompare)4, 0, (GXAlphaOp)0, (GXCompare)7, 0);
            GXSetZMode((GXBool)1, (GXCompare)3, (GXBool)1);
            fn_802FC268(this_, this_ + 0x2374, i - 4, *(u32*)(this_ + i * 4 + 0x28));
        } else if (this_[0x2365] != 0 && i == 8 && this_[0x235c] != 0) {
            GXSetAlphaCompare((GXCompare)1, 0xff, (GXAlphaOp)0, (GXCompare)4, 0);
            GXSetZMode((GXBool)1, (GXCompare)3, (GXBool)0);
            fn_802FC268(this_, this_ + 0x2368, 0, *(u32*)(this_ + 0x28));
        }
    }
}

extern "C" void fn_802FEE68(Tu802F5040Tbl* base) {
    u8* p;
    s32 i;
    f32 ratio;
    f32 s;
    f32 v;
    MtxPtr orig;
    Mtx m;
    s32 j;

    i = 0xff;
    p = (u8*)base + 0x9b64;
    do {
        if (*(s32*)(p + 0x2398) > 0) {
            ratio = (f32)*(s32*)(p + 0x2398) / (f32)*(s32*)(p + 0x239c);
            p[0x23d0] = p[0x242c];
            p[0x23d1] = p[0x242d];
            p[0x23d2] = p[0x242e];
            p[0x23d3] = (u8)(int)((f32)p[0x242f] * ratio);
            p[0x23d4] = p[0x2430];
            p[0x23d5] = p[0x2431];
            p[0x23d6] = p[0x2432];
            p[0x23d7] = (u8)(int)((f32)p[0x2433] * ratio);
            v = *(f32*)(p + 0x23a0);
            if (lbl_80541518 != v) {
                orig = *(MtxPtr*)(p + 0x23d8);
                s = v - (v - lbl_80541518) * ratio;
                PSMTXCopy(orig, m);
                for (j = 0; j < 12; j++) {
                    ((f32*)m)[j] *= s;
                }
                *(MtxPtr*)(p + 0x23d8) = m;
            }
            if (*(s32*)(p + 0x23b0) != 0) {
                fn_802F86CC(base, p + 0x23a4, *(s32*)(p + 0x23b0), *(u32*)(p + 0x23b4), p + 0x23c0, lbl_80541518, lbl_80541518);
            } else if (*(s32*)(p + 0x23b8) != 0) {
                fn_802F745C(base, p + 0x23a4, *(s32*)(p + 0x23b8), p + 0x23c0);
            } else if (*(s32*)(p + 0x23bc) != 0) {
                fn_802F6CF4(base, p + 0x23a4, *(s32*)(p + 0x23bc), p + 0x23c0);
            }
            if (lbl_80541518 != *(f32*)(p + 0x23a0)) {
                *(MtxPtr*)(p + 0x23d8) = orig;
            }
        }
        i--;
        p -= 0x9c;
    } while (i >= 0);
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
    bool f;
    s32 k;
    s32 i;

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

extern "C" f32 lbl_80541528;
extern "C" f32 lbl_8054152C;
extern "C" f32 lbl_80541530;
extern "C" f32 lbl_80541538;
extern "C" f32 lbl_8054153C;
extern "C" f32 lbl_80541610;
extern "C" f32 lbl_80541614;
extern "C" void fn_802FF798(void* mgr) {
    u8* this_ = (u8*)mgr;
    s32 i;
    s32 j;
    s32 n;
    u8* p;

    for (i = 0; i < 4; i++) {
        this_[0x235c + i] = 0;
        this_[0x2360 + i] = 0;
    }
    this_[0x2364] = 0;
    this_[0x2365] = 1;
    *(f32*)(this_ + 0x2368) = *(f32*)(this_ + 0x236c) = *(f32*)(this_ + 0x2370) = 0.0f;
    *(f32*)(this_ + 0x2374) = *(f32*)(this_ + 0x2378) = *(f32*)(this_ + 0x237c) = 0.0f;
    *(s32*)(this_ + 0x2380) = 0x40;
    *(s32*)(this_ + 0x2384) = 0x40;
    p = this_;
    for (i = 0; i < 0x20; i++) {
        for (j = 0; j < 8; j++) {
            *(s32*)(p + 0x2398 + j * 0x9c) = 0;
        }
        p += 0x4e0;
    }
    this_[0xbf98] = 0;
    *(s32*)(this_ + 0x2388) = 0;
    for (int k = 0; k < 0x10; k++) {
        *(s32*)(this_ + 0xbf9c + k * 0x28) = 0;
    }
    for (i = 0; i < 0x40; i++) {
        for (j = 0; j < 0x10; j++) {
            n = i * 0x10 + j;
            ((f32*)*(u8**)(this_ + 0x110))[n * 2] = 0.0078125f * (8.0f * (f32)j + 0.501f);
            ((f32*)*(u8**)(this_ + 0x110))[n * 2 + 1] = 0.001953125f * (8.0f * (f32)i + 0.501f);
            ((f32*)*(u8**)(this_ + 0x110))[n * 2 + 0x800] = 6.98f / 128.0f + ((f32*)*(u8**)(this_ + 0x110))[n * 2];
            ((f32*)*(u8**)(this_ + 0x110))[n * 2 + 0x801] = ((f32*)*(u8**)(this_ + 0x110))[n * 2 + 1];
            ((f32*)*(u8**)(this_ + 0x110))[n * 2 + 0x1000] = ((f32*)*(u8**)(this_ + 0x110))[n * 2];
            ((f32*)*(u8**)(this_ + 0x110))[n * 2 + 0x1001] = 6.98f / 512.0f + ((f32*)*(u8**)(this_ + 0x110))[n * 2 + 1];
            ((f32*)*(u8**)(this_ + 0x110))[n * 2 + 0x1800] = 6.98f / 128.0f + ((f32*)*(u8**)(this_ + 0x110))[n * 2];
            ((f32*)*(u8**)(this_ + 0x110))[n * 2 + 0x1801] = 6.98f / 512.0f + ((f32*)*(u8**)(this_ + 0x110))[n * 2 + 1];
        }
    }
    *(s32*)(this_ + 0xc21c) = 0;
    *(s32*)(this_ + 0xd320) = 0;
    *(s32*)(this_ + 0xe424) = 0;
    fn_802FDDD4(this_);
    for (i = 0; i < 4; i++) {
        s32 x;
        s32 y;
        this_[0x12c + i] = 0;
        *(s32*)(this_ + 0x138 + i * 4) = 0;
        this_[0x148 + i] = 0;
        this_[0x14c + i] = 0;
        this_[0x210 + i] = 0;
        if (i & 2) {
            y = *(u16*)(*(u8**)((u8*)sManager__8JUTVideo + 4) + 6) - 0x90;
        } else {
            y = 0x48;
        }
        if (i & 1) {
            x = *(u16*)(*(u8**)((u8*)sManager__8JUTVideo + 4) + 4) - 0x60;
        } else {
            x = 0x18;
        }
        *(s32*)(this_ + 0x1d0 + i * 0x10) = x;
        *(s32*)(this_ + 0x1d4 + i * 0x10) = y;
        *(s32*)(this_ + 0x1d8 + i * 0x10) = 0x48;
        *(s32*)(this_ + 0x1dc + i * 0x10) = 0x48;
        this_[0x217 + i] = 0;
    }
    this_[0x216] = 0;
    this_[0x214] = 0;
    this_[0x215] = 0;
    *(s32*)(this_ + 0x22c) = -1;
    *(s32*)(this_ + 0x230) = -1;
    *(s32*)(this_ + 0x234) = 0;
    this_[0x248] = 0;
    this_[0xe450] = 1;
    this_[0xe451] = 1;
    *(f32*)(this_ + 0xe458) = 1.8f;
    *(f32*)(this_ + 0xe45c) = -0.25f;
    *(s32*)(this_ + 0x2390) = 0;
    *(s32*)(this_ + 0x2394) = 0;
    this_[0xe461] = 1;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            for (n = 0; n < 0x10; n++) {
                GXInitTlutObj((GXTlutObj*)(this_ + 0x25c + i * 0x300 + j * 0xc0 + n * 0xc),
                              *(u8**)(this_ + 0xc8 + (i * 4 + j) * 4) + n * 0x20, (GXTlutFmt)2, 0x10);
                GXInitTexObjCI((GXTexObj*)(this_ + 0xb5c + i * 0x800 + j * 0x200 + n * 0x20),
                               *(void**)(this_ + 0x88 + j * 4), 0x100, 0x100, (GXCITexFmt)8, (GXTexWrapMode)0,
                               (GXTexWrapMode)0, 0, ((u32*)lbl_8046F940)[n]);
            }
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

extern "C" int sprintf(char* buf, const char* fmt, ...);
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void* fn_8043395C(void* p);
extern "C" char lbl_804711D4[];
extern "C" char lbl_804711E4[];
extern "C" void* fn_802FFDEC(void* self, JKRHeap* heap) {
    u8* p = (u8*)self;
    s32 i;
    char name[32];

    *(u8**)p = lbl_804AA858;
    __construct_array(p + 0x150, (void*)fn_803004C0, 0, 0x10, 4);
    __construct_array(p + 0x190, (void*)fn_803004C0, 0, 0x10, 4);
    __construct_array(p + 0x1d0, (void*)fn_803004C0, 0, 0x10, 4);
    __construct_array(p + 0x2398, (void*)fn_803003AC, 0, 0x9c, 0x100);
    __construct_array(p + 0xbf9c, (void*)fn_803003A8, 0, 0x28, 0x10);
    __construct_array(p + 0xc220, (void*)fn_8030029C, 0, 0x88, 0x20);
    __construct_array(p + 0xd324, (void*)fn_8030029C, 0, 0x88, 0x20);
    heap->getTotalFreeSize();
    {
        u8* q;
        for (i = 0, q = p; i < 2; i++, q += 4) {
            *(void**)(q + 4) = ::operator new[](0x8000, heap, 0x20);
        }
    }
    {
        u8* q;
        for (i = 0, q = p; i < 3; i++, q += 4) {
            *(void**)(q + 0xc) = ::operator new[](0x200, heap, 0x20);
            *(void**)(q + 0x18) = ::operator new[](0x200, heap, 0x20);
        }
    }
    *(void**)(p + 0x24) = ::operator new[](0x2000, heap, 0x20);
    {
        u8* q;
        for (i = 0, q = p; i < 4; i++, q += 4) {
            *(void**)(q + 0x28) = ::operator new[](0x2000, heap, 0x20);
            *(void**)(q + 0x38) = ::operator new[](0x2000, heap, 0x20);
        }
    }
    {
        u8* q;
        for (i = 0, q = p; i < 16; i++, q += 4) {
            *(void**)(q + 0x48) = ::operator new[](0x2000, heap, 0x20);
        }
    }
    {
        u8* q;
        for (i = 0, q = p; i < 4; i++, q += 4) {
            *(void**)(q + 0x88) = ::operator new[](0x8000, heap, 0x20);
        }
    }
    {
        u8* q;
        for (i = 0, q = p; i < 12; i++, q += 4) {
            *(void**)(q + 0x98) = ::operator new[](0x200, heap, 0x20);
            *(void**)(q + 0xc8) = ::operator new[](0x200, heap, 0x20);
        }
    }
    *(void**)(p + 0xf8) = ::operator new[](0x8000, heap, 0x20);
    {
        u8* q;
        s32 j;
        for (j = 0, q = p; j < 2; j++, q += 4) {
            *(JGeometry::TVec3<f32>**)(q + 0x100) = new (heap, 0) JGeometry::TVec3<f32>[0x1081];
            *(JUtility::TColor**)(q + 0x108) = new (heap, 0) JUtility::TColor[0x1081];
        }
    }
    *(JGeometry::TVec2<f32>**)(p + 0x110) = new (heap, 0) JGeometry::TVec2<f32>[0x1000];
    {
        s32 j;
        u8* q;
        for (j = 0, q = p; j < 4; j++, q += 4) {
            *(void**)(q + 0x11c) = ::operator new(0x68, heap, 0);
        }
    }
    {
        s32 j;
        u8* q;
        for (j = 0, q = p; j < 10; j++, q += 4) {
            sprintf(name, lbl_804711D4, j == 0 ? 1 : j);
            *(JUTTexture**)(q + 0xe428) = new (heap, 0) JUTTexture((ResTIMG*)((void* (*)(void*, u32, const char*))(
                *(void***)*(void**)((u8*)lbl_8053AAF8 + 0xa4))[6])(*(void**)((u8*)lbl_8053AAF8 + 0xa4), 0x3f3f3f3f, name));
        }
    }
    *(JUTTexture**)(p + 0xe454) = new (heap, 0) JUTTexture((ResTIMG*)((void* (*)(void*, u32, const char*))(
        *(void***)*(void**)((u8*)lbl_8053AAF8 + 0xa4))[6])(*(void**)((u8*)lbl_8053AAF8 + 0xa4), 0x3f3f3f3f, lbl_804711E4));
    {
        void* o = ::operator new(0xb0, heap, 0);
        if (o != NULL) {
            o = fn_8043395C(o);
        }
        *(void**)(p + 0xfc) = o;
    }
    *(void**)(p + 0x238c) = ::operator new[](0x100, heap, 0x20);
    return p;
}

extern "C" void fn_8030029C(u8* p) {
    *(s32*)(p + 0x2c) = -1;
    *(s32*)(p + 0x30) = -1;
    for (int i = 0; (u8)i < 0x10; i += 8) {
        p[(u8)(i + 0) + 0x1c] = i + 0;
        p[(u8)(i + 1) + 0x1c] = i + 1;
        p[(u8)(i + 2) + 0x1c] = i + 2;
        p[(u8)(i + 3) + 0x1c] = i + 3;
        p[(u8)(i + 4) + 0x1c] = i + 4;
        p[(u8)(i + 5) + 0x1c] = i + 5;
        p[(u8)(i + 6) + 0x1c] = i + 6;
        p[(u8)(i + 7) + 0x1c] = i + 7;
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

extern "C" void __register_global_object(void*, void*, void*);
extern "C" void __ct__17JASGenericMemPoolFv(void*);
extern "C" char __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr;
extern "C" u8 memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr[0x10];
extern "C" void __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv(void*);
extern "C" char __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack;
extern "C" u8 memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack[0x10];
extern "C" void __dt__35JASMemPool_MultiThreaded_8JASTrackFv(void*);
extern "C" char __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel;
extern "C" u8 memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel[0x10];
extern "C" void __dt__38JASMemPool_MultiThreaded_10JASChannelFv(void*);
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA;
extern "C" u8 memPool___37JASPoolAllocObject_15JASPoolObj3_FSA[0x10];
extern "C" void __dt__29JASMemPool_15JASPoolObj3_FSAFv(void*);
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA;
extern "C" u8 memPool___37JASPoolAllocObject_15JASPoolObj4_FSA[0x10];
extern "C" void __dt__29JASMemPool_15JASPoolObj4_FSAFv(void*);
extern "C" char __init__memPool___30JASPoolAllocObject_9JAIStream;
extern "C" u8 memPool___30JASPoolAllocObject_9JAIStream[0x10];
extern "C" void __dt__22JASMemPool_9JAIStreamFv(void*);
extern "C" char __init__memPool___35JASPoolAllocObject_13JAISoundChild;
extern "C" u8 memPool___35JASPoolAllocObject_13JAISoundChild[0x10];
extern "C" void __dt__27JASMemPool_13JAISoundChildFv(void*);
extern "C" char __init__memPool___27JASPoolAllocObject_6JAISeq;
extern "C" u8 memPool___27JASPoolAllocObject_6JAISeq[0x10];
extern "C" void __dt__19JASMemPool_6JAISeqFv(void*);
extern "C" char __init__memPool___26JASPoolAllocObject_5JAISe;
extern "C" u8 memPool___26JASPoolAllocObject_5JAISe[0x10];
extern "C" void __dt__18JASMemPool_5JAISeFv(void*);
extern "C" u8 lbl_804D69B8[];
#include "JSystem/JAudio/JASFakeMatchFSA.h"

