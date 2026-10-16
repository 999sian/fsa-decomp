#include "types.h"

extern "C" f32 lbl_80541500;
extern "C" f32 lbl_805414FC;
extern "C" f32 lbl_80541508;
extern "C" f32 lbl_80541510;
extern "C" f32 lbl_80541514;
extern "C" f32 lbl_80541518;

extern void* lbl_8053AB10;
extern void* sManager__8JUTVideo;
extern "C" void fn_802FC80C(u8* this_);

struct Tu802F5040Tbl {
    u8 pad0[0x28];
    u8* m_tbl[8];
};

extern "C" void fn_802FA3FC(void* mgr);
extern "C" void fn_802FF798(void* mgr);
extern void* lbl_8053AAF8;
extern "C" f32 lbl_80541508;
extern "C" f32 lbl_80541510;
extern "C" f32 lbl_80541514;
extern "C" f32 lbl_80541518;
extern "C" f32 fn_802F5E9C(u8* this_, f32* pos) {
    f32 z = pos[2];
    if (*(s32*)(this_ + 0xc21c) > 0) {
        f32 x = pos[0];
        f32 lo_x = *(f32*)(this_ + 0x2368);
        if (x >= lo_x && x < (f32)*(s32*)(this_ + 0x2380) * lbl_80541510 + lo_x) {
            f32 y = pos[1];
            f32 lo_y = *(f32*)(this_ + 0x236c);
            if (y >= lo_y && y < (f32)*(s32*)(this_ + 0x2384) * lbl_80541510 + lo_y) {
                f32 scale = lbl_80541514;
                s32 ix = (s32)((x - lo_x) * scale);
                s32 iy = (s32)((y - lo_y) * scale);
                f32 fx = scale * ((x - lo_x) - lbl_80541510 * (f32)ix);
                f32 fy = scale * ((y - lo_y) - lbl_80541510 * (f32)iy);
                u8** slot = (u8**)(this_ + *(s32*)(this_ + 0x2388) * 4);
                u8* tbl = slot[0x100 / 4];
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

extern "C" void fn_802FA3FC(void* mgr);
extern void* lbl_8053AAF8;
extern "C" void fn_802FA3FC(void* mgr);
extern "C" void fn_802FF548(void* mgr) {
    fn_802FF798(mgr);
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

