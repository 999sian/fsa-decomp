#include "types.h"
#include "dolphin/gx.h"
#include "dolphin/mtx.h"
#include "JSystem/JUtility/JUTVideo.h"

extern u8* lbl_8053AB10;

extern "C" void fn_8030C5F0(u8* p, s32 a, s32 b, s32 c, f32* out);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802DCDF4(char* p);

struct Vec3f { f32 x, y, z; };
struct Mtx34Blk { f32 m[3][4]; };
struct Mtx44Blk { f32 m[4][4]; };

extern "C" void GXSetZScaleOffset(f32 scale, f32 offset);

static inline bool fn_8030C210_contains(u8* p, f32 x, f32 y) {
    bool in = false;
    if (x >= *(f32*)(p + 0x154) && y >= *(f32*)(p + 0x158) && x < *(f32*)(p + 0x15c) && y < *(f32*)(p + 0x160)) {
        in = true;
    }
    return in;
}

extern "C" bool fn_8030C210(u8* p, f32* v) {
    bool ret = false;
    s32 n = *(s32*)(p + 0x7f0);
    if (n < 0x80) {
        f32 x = v[0];
        f32 y = v[1];
        bool in = false;
        if (x >= *(f32*)(p + 0x154) && y >= *(f32*)(p + 0x158) && x < *(f32*)(p + 0x15c) && y < *(f32*)(p + 0x160)) {
            in = true;
        }
        if (in) {
            f32 y2 = v[1];
            f32 z = v[2];
            ret = true;
            f32* d = (f32*)(p + n * 0xc + 0x1f0);
            d[0] = x;
            d[1] = y2;
            d[2] = z;
            (*(s32*)(p + 0x7f0))++;
        }
    }
    return ret;
}

extern "C" bool fn_8030C2A8(u8* p, s32 r4) {
    f32 pos[3];
    fn_8030C5F0(p, r4, 1, 0, pos);
    bool ret = false;
    if (pos[0] >= (f32)(u32)(*(u32*)(p + 0x144) + 0xe) && pos[0] < (f32)(u32)(*(u32*)(p + 0x14c) - 0xe) &&
        pos[1] >= (f32)(u32)(*(u32*)(p + 0x148) + 0xe) && pos[1] < (f32)(u32)(*(u32*)(p + 0x150) - 0xe)) {
        ret = true;
    }
    return ret;
}

extern "C" void fn_8030C4A0(u8* p, f32* in, u8 flag, f32* out) {
    if (flag != 0) {
        f32 x0 = (f32)*(u32*)(p + 0x144);
        f32 y0 = (f32)*(u32*)(p + 0x148);
        f32 xs = (f32)(*(u32*)(p + 0x14c) - *(u32*)(p + 0x144));
        f32 ys = (f32)(*(u32*)(p + 0x150) - *(u32*)(p + 0x148));
        out[0] = *(f32*)(p + 0x164) + (in[0] - x0) * (*(f32*)(p + 0x16c) - *(f32*)(p + 0x164)) / xs;
        out[1] = *(f32*)(p + 0x168) + (in[1] - y0) * (*(f32*)(p + 0x170) - *(f32*)(p + 0x168)) / ys;
        out[2] = 0.0f;
    } else {
        const GXRenderModeObj* rm = JUTVideo::getManager()->getRenderMode();
        out[0] = *(f32*)(p + 0x164) + in[0] * (*(f32*)(p + 0x16c) - *(f32*)(p + 0x164)) / (f32)rm->fbWidth;
        out[1] = *(f32*)(p + 0x168) + in[1] * (*(f32*)(p + 0x170) - *(f32*)(p + 0x168)) / (f32)rm->efbHeight;
        out[2] = 0.0f;
    }
}

extern "C" void fn_8030C7C4(void* self, f32* pos, f32 size) {
    f32 hw = 0.5f * size;
    f32 x = pos[0];
    const GXRenderModeObj* rm = JUTVideo::getManager()->getRenderMode();
    int h = rm->efbHeight;
    int w = rm->fbWidth;
    u8* obj = *(u8**)(lbl_8053AB10 + 0x24);
    f32 y = pos[1];
    f32 hh = 0.5f * (size * (f32)h / (f32)w);
    *(f32*)(obj + 0x180) = x - hw;
    *(f32*)(obj + 0x184) = y - hh;
    *(f32*)(obj + 0x188) = x + hw;
    *(f32*)(obj + 0x18c) = y + hh;
    obj[0x17e] = 1;
}

extern "C" void fn_8030C85C(u8* self) {
    u8 zero = 0;
    self[0x1e8] = zero;
    if (((u8*)(*(u8**)(lbl_8053AB10 + 0x20)))[0x235c] != 0) {
        ((u8*)(*(u8**)(lbl_8053AB10 + 0x20)))[0x2360] = zero;
    }
    if (((u8*)(*(u8**)(lbl_8053AB10 + 0x20)))[0x235d] != 0) {
        ((u8*)(*(u8**)(lbl_8053AB10 + 0x20)))[0x2361] = zero;
    }
    if (((u8*)(*(u8**)(lbl_8053AB10 + 0x20)))[0x235e] != 0) {
        ((u8*)(*(u8**)(lbl_8053AB10 + 0x20)))[0x2362] = zero;
    }
    if (((u8*)(*(u8**)(lbl_8053AB10 + 0x20)))[0x235f] != 0) {
        ((u8*)(*(u8**)(lbl_8053AB10 + 0x20)))[0x2363] = zero;
    }
    fn_802DCDF4((char*)fn_802D6A9C());
    *(f32*)(self + 0x154) = *(f32*)(self + 0x190);
    *(f32*)(self + 0x158) = *(f32*)(self + 0x194);
    *(f32*)(self + 0x15c) = *(f32*)(self + 0x198);
    *(f32*)(self + 0x160) = *(f32*)(self + 0x19c);
    *(f32*)(self + 0x1b8) = 0.0f;
    *(f32*)(self + 0x1b4) = 0.0f;
    *(f32*)(self + 0x1c0) = 0.0f;
    *(f32*)(self + 0x1bc) = 0.0f;
}

extern "C" void fn_8030C928(u8* self, f32* rect) {
    *(f32*)(self + 0x190) = rect[0];
    *(f32*)(self + 0x194) = rect[1];
    *(f32*)(self + 0x198) = rect[2];
    *(f32*)(self + 0x19c) = rect[3];
    Vec v;
    v.x = rect[0];
    v.y = rect[1];
    v.z = 0.0f;
    u8* g;
    g = *(u8**)(lbl_8053AB10 + 0x20); g[0x2360] = g[0x235c];
    g = *(u8**)(lbl_8053AB10 + 0x20); g[0x2361] = g[0x235d];
    g = *(u8**)(lbl_8053AB10 + 0x20); g[0x2362] = g[0x235e];
    g = *(u8**)(lbl_8053AB10 + 0x20); g[0x2363] = g[0x235f];
    g = *(u8**)(lbl_8053AB10 + 0x20); *(Vec*)(g + 0x2374) = *(Vec*)(g + 0x2368);
    g = *(u8**)(lbl_8053AB10 + 0x20); *(Vec*)(g + 0x2368) = v;
}

extern u8 lbl_804AA8E8[];
extern f32 lbl_805416EC;
extern f32 lbl_805416C8;
extern "C" void fn_8030CD18(u8* p, f32* rect, u8* entry, s32 zero, u8* a, u8* b);
extern "C" void fn_8030C9E4(u8* self, f32* rect) {
    u8* g;
    Vec v;
    self[0x1e8] = 1;
    *(s32*)(self + 0x1ec) = 0x1e;
    self[0x7f5] = 0;
    *(f32*)(self + 0x1d8) = *(f32*)(self + 0x1d4) = lbl_805416EC;
    fn_8030CD18(self, rect, lbl_804AA8E8 + *(s32*)(self + 0x174) * 0x24, 0, self + 0x1a0, self + 0x1b0);
    *(f32*)(self + 0x190) = rect[0];
    *(f32*)(self + 0x194) = rect[1];
    *(f32*)(self + 0x198) = rect[2];
    *(f32*)(self + 0x19c) = rect[3];
    v.x = rect[0];
    v.y = rect[1];
    v.z = lbl_805416C8;
    g = *(u8**)(lbl_8053AB10 + 0x20); g[0x2360] = g[0x235c];
    g = *(u8**)(lbl_8053AB10 + 0x20); g[0x2361] = g[0x235d];
    g = *(u8**)(lbl_8053AB10 + 0x20); g[0x2362] = g[0x235e];
    g = *(u8**)(lbl_8053AB10 + 0x20); g[0x2363] = g[0x235f];
    g = *(u8**)(lbl_8053AB10 + 0x20); *(Vec*)(g + 0x2374) = *(Vec*)(g + 0x2368);
    g = *(u8**)(lbl_8053AB10 + 0x20); *(Vec*)(g + 0x2368) = v;
}

extern "C" void fn_8030DD20(u8* param_1, Mtx param_2) {
    Mtx sp8;
    PSMTXConcat((MtxPtr)(param_1 + 0x74), param_2, sp8);
    GXSetCurrentMtx(0x1b);
    GXLoadPosMtxImm(sp8, 0x1b);
    GXLoadNrmMtxImm(sp8, 0x1b);
}

extern "C" void fn_8030DD68(void) {
    GXSetCurrentMtx(0x18);
}

extern "C" void fn_8030DFE8(u8* p, u8 flag) {
    if (flag) {
        *(Mtx34Blk*)(p + 0x74) = *(Mtx34Blk*)(p + 0x4);
        *(Mtx44Blk*)(p + 0xa4) = *(Mtx44Blk*)(p + 0x34);
    }
    GXSetProjection((f32(*)[4])(p + 0xa4), GX_PERSPECTIVE);
    GXLoadPosMtxImm((f32(*)[4])(p + 0x74), 0x18);
    GXLoadNrmMtxImm((f32(*)[4])(p + 0x74), 0x18);
    GXSetCurrentMtx(0x18);
    s32 x = *(s32*)(p + 0x144);
    s32 y = *(s32*)(p + 0x148);
    s32 w = *(s32*)(p + 0x14c) - x;
    s32 h = *(s32*)(p + 0x150) - y;
    GXSetViewport(x, y, w, h, 0.0f, 1.0f);
    GXSetScissor(x, y, w, h);
    GXSetZScaleOffset(1.0f, 0.0f);
}

extern "C" void fn_8030E150(void) {
}

extern "C" void fn_8030CB10(u8* p, f32* v, f32 s);
extern "C" void fn_8030E5BC(u8* p) {
    f32 v[4];
    *(f32*)(p + 0x154) = 0.0f;
    *(f32*)(p + 0x158) = 0.0f;
    *(f32*)(p + 0x15c) = 512.0f;
    *(f32*)(p + 0x160) = 384.0f;
    p[0x1e8] = 0;
    *(f32*)(p + 0x1b8) = 0.0f;
    *(f32*)(p + 0x1b4) = 0.0f;
    *(f32*)(p + 0x1c0) = 0.0f;
    *(f32*)(p + 0x1bc) = 0.0f;
    *(f32*)(p + 0x1e4) = 0.0f;
    *(f32*)(p + 0x1e0) = 0.0f;
    *(f32*)(p + 0x1dc) = 0.0f;
    *(s32*)(p + 0x1c4) = 0;
    *(s32*)(p + 0x1c8) = 0;
    *(s32*)(p + 0x1cc) = 0;
    *(s32*)(p + 0x1d0) = 0;
    *(f32*)(p + 0x1d4) = -1.0f;
    *(f32*)(p + 0x1d8) = -1.0f;
    v[0] = 0.0f;
    v[1] = 0.0f;
    v[2] = 256.0f;
    v[3] = 192.0f;
    fn_8030CB10(p, v, 1024.0f);
    *(s32*)(p + 0x7f0) = 0;
    p[0x7f4] = 0;
    p[0x7f5] = 0;
    *(s32*)(p + 0x838) = -1;
    p[0x7f6] = 0;
    *(s32*)(p + 0x83c) = -1;
    p[0x840] = 0;
    u16 h = JUTVideo::sManager->getRenderMode()->efbHeight;
    u16 w = JUTVideo::sManager->getRenderMode()->fbWidth;
    *(s32*)(p + 0x144) = 0;
    *(s32*)(p + 0x148) = 0;
    *(u32*)(p + 0x14c) = w;
    *(u32*)(p + 0x150) = h;
    *(f32*)(p + 0x858) = 1.0f;
    *(s32*)(p + 0x174) = 0;
    p[0x178] = 0;
    p[0x179] = 0;
    p[0x17a] = 0;
    p[0x17b] = 0;
    p[0x17c] = 0;
    p[0x17d] = 0;
    p[0x17e] = 0;
}

extern u8 lbl_804AA9E4[];
void __dl__FPv(void* p);
extern "C" void __dl__FPv(void* p);
void operator delete(void* p);
extern "C" u32* fn_8030E6D0(u32* param_1, s16 param_2) {
    if (param_1 != NULL) {
        *param_1 = (u32)lbl_804AA9E4;
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}

