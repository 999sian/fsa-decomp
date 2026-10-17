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
    u8* g;
    s32 i;
    u8* p;
    u8 f;
    bool b;

    fn_802FDDD4(this_);
    g = (u8*)lbl_8053AAF8;
    f = 0;
    if (g[0x7f] != 0) {
        s32 t = *(s32*)(g + 0x4c);
        if (t == 7 || t == 8 || t == 9 || t == 0x16 || t == 0xa || t == 0xb) {
            f = 1;
        }
    } else {
        s32 t = *(s32*)(g + 0x4c);
        if (t == 7 || t == 8 || t == 9 || t == 0x16 || t == 0xa || t == 0xb || t == 0xc) {
            f = 1;
        }
    }
    b = f;
    if (b == 1) {
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
        for (i = 0; i < 4; i++) {
            if (fn_8023F264(i) != 0 && ((((u8*)lbl_8053AAF8)[0x83] >> (i * 2)) & 3) == 2) {
                this_[0xe461] = 0;
                return;
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

