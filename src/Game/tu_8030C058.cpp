#include "types.h"
#include "dolphin/gx.h"
#include "dolphin/mtx.h"
#include "JSystem/JUtility/JUTVideo.h"

extern u8* lbl_8053AB10;
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802DCDF4(char* p);

struct Vec3f { f32 x, y, z; };

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

extern "C" void fn_8030E150(void) {
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

