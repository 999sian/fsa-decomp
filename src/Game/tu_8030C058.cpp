#include "types.h"
#include "dolphin/gx.h"
#include "dolphin/mtx.h"
#include "JSystem/JUtility/JUTVideo.h"
#include "JSystem/JMath/Inline.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JGeometry/Box.h"

extern u8* lbl_8053AB10;
extern f32 lbl_805416C8;
extern f32 lbl_805416D8;
extern f32 lbl_805416E8;
extern f32 lbl_805416EC;
extern f32 lbl_8054171C;
extern f32 lbl_80541718;

extern "C" void fn_8030C5F0(u8* p, s32 a, s32 b, s32 c, f32* out);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802DCDF4(char* p);
extern "C" f64 __psq_l(void* ptr, s32 offset, s32 w, s32 i);
extern "C" void __psq_st(f64 v, void* ptr, s32 offset, s32 w, s32 i);

struct Vec3f { f32 x, y, z; };
extern "C" void GXSetZScaleOffset(f32 scale, f32 offset);

static inline bool fn_8030C210_contains(u8* p, f32 x, f32 y) {
    bool in = false;
    if (x >= *(f32*)(p + 0x154) && y >= *(f32*)(p + 0x158) && x < *(f32*)(p + 0x15c) && y < *(f32*)(p + 0x160)) {
        in = true;
    }
    return in;
}

static inline bool fn_8030C058_in(u8* p, f32* v) {
    bool in = false;
    if (v[0] >= *(f32*)(p + 0x154) && v[1] >= *(f32*)(p + 0x158) && v[0] < *(f32*)(p + 0x15c) && v[1] < *(f32*)(p + 0x160)) {
        in = true;
    }
    return in;
}

extern "C" u8 fn_8030C058(u8* p, f32* v) {
    f32 x;
    f32 y;
    s32 n = *(s32*)(p + 0x7f0);
    bool ret = false;
    if (n + 1 < 0x80) {
        if (fn_8030C058_in(p, v) && fn_8030C058_in(p, v + 2)) {
            y = v[1];
            x = v[0];
            if (n < 0x80 && fn_8030C058_in(p, v)) {
                f32* d = (f32*)(p + n * 0xc + 0x1f0);
                d[0] = x;
                d[1] = y;
                d[2] = lbl_805416C8;
                (*(s32*)(p + 0x7f0))++;
            }
            n = *(s32*)(p + 0x7f0);
            if (n < 0x80 && fn_8030C058_in(p, v + 2)) {
                f32* d = (f32*)(p + n * 0xc + 0x1f0);
                d[0] = v[2];
                d[1] = v[3];
                d[2] = lbl_805416C8;
                (*(s32*)(p + 0x7f0))++;
            }
            ret = true;
        }
    }
    return ret;
}

extern "C" u8 fn_8030C210(u8* p, f32* v) {
    bool ret = false;
    s32 n = *(s32*)(p + 0x7f0);
    if (n < 0x80 && fn_8030C210_contains(p, v[0], v[1])) {
        f32 z;
        f32 y;
        f32 x;
        y = ((volatile f32*)v)[1];
        z = v[2];
        x = v[0];
        ret = true;
        f32* d = (f32*)(p + n * 0xc + 0x1f0);
        d[0] = x;
        d[1] = y;
        d[2] = z;
        (*(s32*)(p + 0x7f0))++;
    }
    return ret;
}

#pragma opt_common_subs off
#pragma opt_strength_reduction off
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
#pragma opt_strength_reduction reset
#pragma opt_common_subs reset
extern "C" void fn_8030C380(u8* p, f32* out) {
    f32 scale = lbl_805416C8;
    f32 x0 = *(f32*)(p + 0x164);
    f32 y0 = *(f32*)(p + 0x168);
    f32 x1 = *(f32*)(p + 0x16c);
    f32 y1 = *(f32*)(p + 0x170);
    u16 w;
    u16 h;
    JUTVideo::sManager->getBounds(w, h);
    out[0] = x0 + (scale * (x1 - x0)) / (f32)w;
    out[1] = y0 + (scale * (y1 - y0)) / (f32)h;
    out[2] = scale;
    JUTVideo::sManager->getBounds(w, h);
    x0 = *(f32*)(p + 0x164);
    y0 = *(f32*)(p + 0x168);
    x1 = *(f32*)(p + 0x16c);
    y1 = *(f32*)(p + 0x170);
    out[3] = x0 + ((f32)w * (x1 - x0)) / (f32)w;
    out[4] = y0 + ((f32)h * (y1 - y0)) / (f32)h;
    out[5] = scale;
}

extern "C" void fn_8030C4A0(u8* p, f32* in, u8 flag, f32* out) {
    if (flag != 0) {
        u32 a = *(u32*)(p + 0x144);
        u32 b = *(u32*)(p + 0x148);
        u32 c = *(u32*)(p + 0x14c);
        u32 d = *(u32*)(p + 0x150);
        f32 y1 = *(f32*)(p + 0x168);
        f32 x1 = *(f32*)(p + 0x164);
        f32 x2 = *(f32*)(p + 0x16c);
        f32 y2 = *(f32*)(p + 0x170);
        f32 tx = (in[0] - (f32)a) * (x2 - x1) / (f32)(c - a);
        f32 ty = (in[1] - (f32)b) * (y2 - y1) / (f32)(d - b);
        out[0] = x1 + tx;
        out[1] = y1 + ty;
        out[2] = 0.0f;
    } else {
        const GXRenderModeObj* rm = JUTVideo::getManager()->getRenderMode();
        f32 y1 = *(f32*)(p + 0x168);
        f32 x1 = *(f32*)(p + 0x164);
        f32 x2 = *(f32*)(p + 0x16c);
        f32 y2 = *(f32*)(p + 0x170);
        f32 w = (f32)(s32)rm->fbWidth;
        f32 h = (f32)(s32)rm->efbHeight;
        f32 dy = y2 - y1;
        f32 tx = in[0] * (x2 - x1) / w;
        f32 ty = in[1] * dy / h;
        out[0] = x1 + tx;
        out[1] = y1 + ty;
        out[2] = 0.0f;
    }
}

extern "C" void fn_8030C5F0(u8* p, s32 a, s32 b, s32 c, f32* out) {
    Vec v;
    PSMTXMultVec((MtxPtr)(p + 0x74), (Vec*)a, &v);
    f32* m = (f32*)(p + 0xa4);
    f32 one = 1.0f;
    f32 vy = v.y;
    f32 vx = v.x;
    f32 vz = v.z;
    f32 y = vx * m[4] + vy * m[5] + vz * m[6] + one * m[7];
    f32 x = vx * m[0] + vy * m[1] + vz * m[2] + one * m[3];
    if ((u8)c != 0) {
        out[0] = 0.5f * (1.0f + x);
        out[1] = 0.5f * (1.0f - y);
    } else if ((u8)b != 0) {
        u32 x0 = *(u32*)(p + 0x144);
        f32 sx = 0.5f * (1.0f + x);
        f32 sy = 0.5f * (1.0f - y);
        out[0] = sx * (f32)(*(u32*)(p + 0x14c) - x0) + (f32)x0;
        u32 y0 = *(u32*)(p + 0x148);
        out[1] = sy * (f32)(*(u32*)(p + 0x150) - y0) + (f32)y0;
    } else {
        f32 sx = 0.5f * (1.0f + x);
        f32 sy = 0.5f * (1.0f - y);
        out[0] = sx * (f32)(s32)JUTVideo::getManager()->getRenderMode()->fbWidth;
        out[1] = sy * (f32)(s32)JUTVideo::getManager()->getRenderMode()->efbHeight;
    }
    out[2] = 0.0f;
}

extern "C" void fn_8030C7C4(void* self, f32* pos, f32 size) {
    int h = JUTVideo::getManager()->getEfbHeight();
    int w = JUTVideo::getManager()->getFbWidth();
    f32 hw = 0.5f * size;
    f32 hh = 0.5f * (size * (f32)h / (f32)w);
    u8* obj = *(u8**)(lbl_8053AB10 + 0x24);
    ((JGeometry::TBox2f*)(obj + 0x180))->set(pos[0] - hw, pos[1] - hh, pos[0] + hw, pos[1] + hh);
    obj[0x17e] = 1;
}

#pragma opt_propagation off
extern "C" void fn_8030C85C(u8* self) {
    u32 zero = 0;
    self[0x1e8] = zero;
    if ((*(u8**)(lbl_8053AB10 + 0x20))[0x235c] != 0) {
        (*(u8**)(lbl_8053AB10 + 0x20))[0x2360] = zero;
    }
    if ((*(u8**)(lbl_8053AB10 + 0x20))[0x235d] != 0) {
        (*(u8**)(lbl_8053AB10 + 0x20))[0x2361] = zero;
    }
    if ((*(u8**)(lbl_8053AB10 + 0x20))[0x235e] != 0) {
        (*(u8**)(lbl_8053AB10 + 0x20))[0x2362] = zero;
    }
    if ((*(u8**)(lbl_8053AB10 + 0x20))[0x235f] != 0) {
        (*(u8**)(lbl_8053AB10 + 0x20))[0x2363] = zero;
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
#pragma opt_propagation reset
extern "C" void fn_8030C928(u8* self, f32* rect) {
    f32 y;
    f32 x0;
    f32 bottom;
    f32 right;
    x0 = rect[0];
    y = rect[1];
    *(f32*)(self + 0x190) = x0;
    *(f32*)(self + 0x194) = rect[1];
    right = rect[2];
    bottom = rect[3];
    *(f32*)(self + 0x198) = right;
    JGeometry::TVec3f v(rect[0], y, lbl_805416C8);
    *(f32*)(self + 0x19c) = bottom;
    u8* g;
    g = *(u8**)(lbl_8053AB10 + 0x20); g[0x2360] = g[0x235c];
    g = *(u8**)(lbl_8053AB10 + 0x20); g[0x2361] = g[0x235d];
    g = *(u8**)(lbl_8053AB10 + 0x20); g[0x2362] = g[0x235e];
    g = *(u8**)(lbl_8053AB10 + 0x20); g[0x2363] = g[0x235f];
    g = *(u8**)(lbl_8053AB10 + 0x20);
    JGeometry::TVec3f* dst = (JGeometry::TVec3f*)(g + 0x2374);
    JGeometry::TVec3f* src = (JGeometry::TVec3f*)(g + 0x2368);
    *dst = *src;
    g = *(u8**)(lbl_8053AB10 + 0x20); *(JGeometry::TVec3f*)(g + 0x2368) = v;
}
extern u8 lbl_804AA8E8[];
extern f32 lbl_805416EC;
extern f32 lbl_805416C8;
extern "C" void fn_8030CD18(u8* p, f32* rect, u8* entry, s32 zero, u8* a, u8* b);
extern "C" f64 __psq_l(void* ptr, s32 offset, s32 w, s32 i);
extern "C" void __psq_st(f64 v, void* ptr, s32 offset, s32 w, s32 i);
extern "C" void fn_8030C9E4(u8* self, f32* rect) {
    u8* g;
    JGeometry::TVec3<f32> v;
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
    g = *(u8**)(lbl_8053AB10 + 0x20);
    *(JGeometry::TVec3<f32>*)(g + 0x2374) = *(JGeometry::TVec3<f32>*)(g + 0x2368);
    g = *(u8**)(lbl_8053AB10 + 0x20);
    *(JGeometry::TVec3<f32>*)(g + 0x2368) = v;
}

extern "C" void fn_8030CB10(u8* p, f32* v, f32 s) {
    f32 hw = 0.5f * (v[2] - v[0]);
    f32 hh = 0.5f * (v[3] - v[1]);
    f32 cx = 0.5f * (v[0] + v[2]);
    f32 cy = 0.5f * (v[1] + v[3]);
    f32* m = (f32*)(p + 0x4);
    m[0] = 1.0f;
    m[1] = 0.0f;
    m[2] = 0.0f;
    m[3] = -cx;
    m[4] = 0.0f;
    m[5] = 1.0f;
    m[6] = -1.0f;
    m[7] = -cy;
    m[8] = 0.0f;
    m[9] = 1.0f;
    m[10] = 0.0f;
    m[11] = -s;
    C_MTXOrtho((f32(*)[4])(p + 0x34), -hh, hh, -hw, hw, 0.0f, 5120.0f);
    PSMTXCopy((f32(*)[4])(p + 0x4), (f32(*)[4])(p + 0xe4));
    C_MTXLightOrtho((f32(*)[4])(p + 0x114), hh, -hh, -hw, hw, 0.5f, 0.5f, 0.5f, 0.5f);
    for (int i = 0; i < 12; i++) {
        ((f32*)(p + 0x74))[i] = m[i];
    }
    for (int i = 0; i < 16; i++) {
        ((f32*)(p + 0xa4))[i] = ((f32*)(p + 0x34))[i];
    }
    f32* r = (f32*)(p + 0x164);
    r[0] = v[0];
    r[1] = v[1];
    r[2] = v[2];
    r[3] = v[3];
}

#include "JSystem/JMath/JMath.h"
extern f32 lbl_805416F4, lbl_805416F8, lbl_805416FC;
extern f32 lbl_80541700, lbl_80541704, lbl_80541708, lbl_8054170C;
extern f32 lbl_80541710, lbl_80541714;
extern u8* lbl_8053AAF8;
extern "C" u8 fn_8023F264(s32);
extern "C" s32 fn_8023DE58(s32);
extern "C" s32 fn_8022CAF8(s32);
extern "C" u8 fn_80234134(s32);
extern "C" s32 fn_8022EA0C(s32);
extern "C" f32* fn_8023E3B8(s32);
extern "C" f32* fn_8023E32C(s32);

static inline f32 cameraCos(const f32 x) {
    f32 angle = x;
    if (angle < 0.0f) angle = -angle;
    return JMath::sincosTable_.mTable[(u16)((2048.0f / 360.0f) * angle) & 2047].second;
}
static inline f32 cameraBlend(const s32 timer, const f32 speed) {
    f32 a = speed * (180.0f * (f32)timer);
    f32 b = 180.0f * (1.0f - (0.5f * cameraCos(a) + 0.5f));
    return 0.5f * cameraCos(b) + 0.5f;
}
static inline f32 cameraBlendAngle(const s32 timer, const f32 speed) {
    f32 a = speed * (180.0f * (f32)timer);
    return 180.0f * (1.0f - (0.5f * cameraCos(a) + 0.5f));
}
static inline f32 cameraClampDelta(f32 value, f32 lower, f32 upper) {
    if (value < 0.0f) {
        if (value < lower) value = lower;
    } else {
        if (value > upper) value = upper;
    }
    return value;
}
#pragma dont_inline reset
extern "C" void fn_8030CD18(u8* p, f32* rect, u8* entry, s32 zero, u8* a, u8* b) {
    f32* old = (f32*)zero;
    f32* out = (f32*)a;
    f32* center = (f32*)b;
    f32 left, right, bottom, top, minY, maxY;
    const GXRenderModeObj* mode;
    u16 videoWidth, videoHeight;
    JUTVideo::getManager()->getBounds(videoWidth, videoHeight);
    f32 aspect = (f32)(s32)videoHeight / (f32)(s32)videoWidth;
    u8 first = 1;
    s32 count = 0;
    f32* cfg = (f32*)entry;
    f32 value = *(f32*)(p + 0x1d4);
    if (value < 0.0f) {
        *(f32*)(p + 0x1d4) = cfg[0];
    } else {
        f32 step = 0.1f * (cfg[0] - value);
        if (step < 0.0f) {
            if (step < -3.0f) step = -3.0f;
        } else {
            if (step > 3.0f) step = 3.0f;
        }
        *(f32*)(p + 0x1d4) = value + step;
    }
    value = *(f32*)(p + 0x1d8);
    if (value < 0.0f) {
        *(f32*)(p + 0x1d8) = cfg[1];
    } else {
        f32 step = 0.1f * (cfg[1] - value);
        if (step < 0.0f) {
            if (step < -3.0f) step = -3.0f;
        } else {
            if (step > 3.0f) step = 3.0f;
        }
        *(f32*)(p + 0x1d8) = value + step;
    }
    if (old && !(0.0f == old[0] && 0.0f == old[2] && 0.0f == old[1] && 0.0f == old[3])) {
        count = *(s32*)(p + 0x7f0);
        if (p[0x7f4]) {
            s32 kind = *(s32*)(p + 0x7f8);
            if (kind == 4) {
                top = *(f32*)(p + 0x800);
                first = 0;
                left = *(f32*)(p + 0x7fc);
                bottom = top; right = left; minY = top; maxY = top;
            } else if (kind == 5) {
                minY = *(f32*)(p + 0x80c);
                first = 0;
                maxY = *(f32*)(p + 0x814);
                top = minY;
                left = *(f32*)(p + 0x808);
                bottom = maxY;
                right = *(f32*)(p + 0x810);
            }
            *(s32*)(p + 0x1c4) = 0;
            *(s32*)(p + 0x1c8) = 0;
            *(s32*)(p + 0x1cc) = 0;
            *(s32*)(p + 0x1d0) = 0;
        }
    } else {
        p[0x7f4] = 0;
    }
    for (s32 i = 0; i < count + 4; i++) {
        f32 x, y;
        if (p[0x7f4] && *(s32*)(p + 0x7f8) >= 0) {
            s32 kind = *(s32*)(p + 0x7f8);
            if (!(kind == i && i < 4) && !(kind == 6 && i >= 4)) continue;
        }
        if (i < 4) {
            if (!fn_8023F264(i)) continue;
            s32 kind = fn_8023DE58(i);
            f32* pos;
            if (entry[0x20] && (fn_8022CAF8(0) != 4 || p[0x1e8] || fn_80234134(0))) {
                if (i != 0 || (fn_8022CAF8(0) == 4 && !fn_80234134(0))) {
                    if (!p[0x1e8] || fn_8022CAF8(0) != 4 || i != fn_8022EA0C(0)) continue;
                }
                if (kind <= 8) { pos = fn_8023E3B8(i); x = pos[0]; y = pos[1]; }
                else { pos = fn_8023E32C(i); x = pos[0]; y = pos[1]; }
            } else {
                if (kind <= 8) { pos = fn_8023E3B8(i); x = pos[0]; y = pos[1]; }
                else {
                    if (i != 0 && !lbl_8053AAF8[0x7e]) continue;
                    { pos = fn_8023E32C(i); x = pos[0]; y = pos[1]; }
                }
            }
        } else {
            f32* pos = (f32*)(p + i * 12 + 0x1c0);
            if (entry[0x20] && !first) {
                f32 step = *(f32*)(p + 0x1d4) - cfg[2];
                x = pos[0]; y = pos[1];
                if (0.0f != step) {
                    if (x < left) { if (x < left - step) x += step; else x = left; }
                    else if (x > right) { if (x > right + step) x -= step; else x = right; }
                    if (y < top) { if (y < top - step) y += step; else y = top; }
                    else if (y > bottom) { if (y > bottom + step) y -= step; else y = bottom; }
                }
            } else { x = pos[0]; y = pos[1]; }
        }
        if (first) {
            left = x;
            first = 0;
            right = x; top = y; bottom = y; minY = y; maxY = y;
        } else {
            if (left > x) left = x;
            if (top > y) top = y;
            if (minY > y) minY = y;
            if (right < x) right = x;
            if (bottom < y) bottom = y;
            if (maxY < y) maxY = y;
        }
    }
    if (p[0x7f5]) {
        minY = rect[1];
        maxY = rect[3];
        top = minY + cfg[0];
        bottom = maxY - cfg[0];
        left = rect[0] + cfg[0];
        right = rect[2] - cfg[0];
    } else {
        *(s32*)(p + 0x838) = -1;
    }
    if (!p[0x7f4]) *(s32*)(p + 0x83c) = -1;
    if (old && !(0.0f == old[0] && 0.0f == old[2] && 0.0f == old[1] && 0.0f == old[3])) {
        f32 step;
        if (p[0x7f4] || count > 0) step = 0.0f;
        else step = cfg[5];
        if (left > old[0]) { if (left < old[0] + step) left = old[0]; else left -= step; }
        if (right < old[2]) { if (right > old[2] - step) right = old[2]; else right += step; }
        if (top > old[1]) { if (top < old[1] + step) top = old[1]; else top -= step; }
        if (bottom < old[3]) { if (bottom > old[3] - step) bottom = old[3]; else bottom += step; }
        u8 blended = 0;
        if (p[0x7f5]) {
            if (*(s32*)(p + 0x838) < 0) {
                *(s32*)(p + 0x838) = 70;
                *(f32*)(p + 0x818) = old[0];
                *(f32*)(p + 0x81c) = old[1];
                *(f32*)(p + 0x820) = old[2];
                *(f32*)(p + 0x824) = old[3];
            }
            if (*(s32*)(p + 0x838) > 0) {
                const f32 phase = cameraBlendAngle(*(s32*)(p + 0x838), 1.0f / 70.0f);
                f32 angle = phase;
                if (angle < 0.0f) angle = -angle;
                const f32 previousLeft = *(f32*)(p + 0x818);
                const f32 previousTop = *(f32*)(p + 0x81c);
                const f32 previousRight = *(f32*)(p + 0x820);
                const f32 previousBottom = *(f32*)(p + 0x824);
                f32 cosine = JMath::sincosTable_.mTable[(u16)((2048.0f / 360.0f) * angle) & 2047].second;
                f32 w = 0.5f * cosine + 0.5f;
                blended = 1;
                --*(s32*)(p + 0x838);
                f32 inv = 1.0f - w;
                left = previousLeft * inv + left * w;
                top = previousTop * inv + top * w;
                right = previousRight * inv + right * w;
                bottom = previousBottom * inv + bottom * w;
            }
        }
        if (!blended && p[0x7f4] && p[0x7f6]) {
            if (*(s32*)(p + 0x83c) < 0) {
                *(s32*)(p + 0x83c) = 40;
                *(f32*)(p + 0x828) = old[0];
                *(f32*)(p + 0x82c) = old[1];
                *(f32*)(p + 0x830) = old[2];
                *(f32*)(p + 0x834) = old[3];
            }
            if (*(s32*)(p + 0x83c) > 0) {
                const f32 phase = cameraBlendAngle(*(s32*)(p + 0x83c), 1.0f / 40.0f);
                f32 angle = phase;
                if (angle < 0.0f) angle = -angle;
                const f32 previousLeft = *(f32*)(p + 0x828);
                const f32 previousTop = *(f32*)(p + 0x82c);
                const f32 previousRight = *(f32*)(p + 0x830);
                const f32 previousBottom = *(f32*)(p + 0x834);
                f32 cosine = JMath::sincosTable_.mTable[(u16)((2048.0f / 360.0f) * angle) & 2047].second;
                f32 w = 0.5f * cosine + 0.5f;
                blended = 1;
                --*(s32*)(p + 0x83c);
                f32 inv = 1.0f - w;
                left = previousLeft * inv + left * w;
                top = previousTop * inv + top * w;
                right = previousRight * inv + right * w;
                bottom = previousBottom * inv + bottom * w;
            }
        }
        if (!blended) {
            f32 diff[4];
            f32 negative[4];
            f32 positive[4];
            diff[0] = old[0] - left;
            diff[1] = right - old[2];
            diff[2] = old[1] - top;
            diff[3] = bottom - old[3];
            f32 high = 0.0f;
            for (s32 k = 0; k < 4; k++) if (diff[k] > high) high = diff[k];
            f32 low = 0.0f;
            for (s32 k = 0; k < 4; k++) if (diff[k] < low) low = diff[k];
            f32 zeroValue = 0.0f;
            for (s32 k = 0; k < 4; k++) {
                if (diff[k] < zeroValue) {
                    if (*(s32*)(p + 0x1c4 + k * 4) == 0 || diff[k ^ 1] > zeroValue) {
                        if (diff[k ^ 1] < 0.1f) negative[k] = cfg[4] * diff[k] / low;
                        else negative[k] = cfg[3] * diff[k] / low;
                    } else negative[k] = zeroValue;
                } else negative[k] = zeroValue;
                if (*(s32*)(p + 0x1c4 + k * 4) > 0) --*(s32*)(p + 0x1c4 + k * 4);
            }
            zeroValue = 0.0f;
            f32 rate = cfg[3];
            s32 delay = *(s32*)(entry + 0x18);
            for (s32 k = 0; k < 4; k++) {
                if (diff[k] > zeroValue) {
                    positive[k] = rate * diff[k] / high;
                    if (*(s32*)(p + 0x1c4 + k * 4) < delay) *(s32*)(p + 0x1c4 + k * 4) = delay;
                } else positive[k] = zeroValue;
            }
            f32 speed = cfg[7];
            left = old[0] + cameraClampDelta(speed * (left - old[0]), -positive[0], negative[0]);
            right = old[2] + cameraClampDelta(speed * (right - old[2]), -negative[1], positive[1]);
            top = old[1] + cameraClampDelta(speed * (top - old[1]), -positive[2], negative[2]);
            bottom = old[3] + cameraClampDelta(speed * (bottom - old[3]), -negative[3], positive[3]);
        }
    }
    if (p[0x840]) {
        f32 inv = 1.0f - *(f32*)(p + 0x854);
        f32 w = *(f32*)(p + 0x854);
        const f32 previousTop = *(f32*)(p + 0x848);
        const f32 previousBottom = *(f32*)(p + 0x850);
        const f32 previousLeft = *(f32*)(p + 0x844);
        const f32 previousRight = *(f32*)(p + 0x84c);
        f32 t = top * inv;
        f32 b = bottom * inv;
        f32 l = left * inv;
        f32 r = right * inv;
        top = previousTop * w + t;
        bottom = previousBottom * w + b;
        left = previousLeft * w + l;
        minY = top;
        maxY = bottom;
        right = previousRight * w + r;
    }
    if (old) { old[0] = left; old[1] = top; old[2] = right; old[3] = bottom; }
    f32 pad = *(f32*)(p + 0x1d4);
    left -= pad; top -= pad; right += pad; bottom += pad;
    f32 x0 = rect[0];
    if (left < x0) left = x0;
    f32 y0 = rect[1];
    if (top < y0) top = y0;
    f32 x1 = rect[2];
    if (right > x1) right = x1;
    f32 y1 = rect[3];
    if (bottom > y1) bottom = y1;
    f32 minSize = *(f32*)(p + 0x1d8);
    f32 twice = 2.0f * minSize;
    if (right - left < twice) {
        f32 mid = 0.5f * (right + left);
        left = mid - minSize; right = mid + minSize;
        if (left < x0) { f32 d = x0 - left; left = x0; right += d; }
        if (right > x1) { f32 d = right - x1; right = x1; left -= d; }
    }
    if (bottom - top < twice * aspect) {
        f32 mid = 0.5f * (bottom + top);
        minSize *= aspect;
        top = mid - minSize; bottom = mid + minSize;
        if (top < y0) { f32 d = y0 - top; top = y0; bottom += d; }
        if (bottom > y1) { f32 d = bottom - y1; bottom = y1; top -= d; }
    }
    mode = JUTVideo::getManager()->getRenderMode();
    s32 height = mode->efbHeight;
    s32 width = mode->fbWidth;
    f32 totalWidth = x1 - x0;
    if ((bottom - top) * (f32)width > totalWidth * (f32)height) {
        f32 mid = 0.5f * (top + bottom);
        f32 half = aspect * (0.5f * totalWidth);
        top = mid - half; bottom = mid + half;
    }
    f32 spanX = right - left;
    f32 spanY = bottom - top;
    if (spanX * (f32)height > spanY * (f32)width) {
        f32 mid = 0.5f * (top + bottom);
        f32 half = (0.5f * spanX) * aspect;
        top = mid - half; bottom = mid + half;
        if (top < y0) {
            f32 d = y0 - top; top = y0; bottom += d;
            if (bottom > y1) bottom = y1;
        }
        if (bottom > y1) {
            f32 d = bottom - y1; bottom = y1; top -= d;
            if (top < y0) top = y0;
        }
    } else {
        f32 mid = 0.5f * (left + right);
        f32 half = (0.5f * spanY) / aspect;
        left = mid - half; right = mid + half;
        if (left < x0) {
            f32 d = x0 - left; left = x0; right += d;
            if (right > x1) right = x1;
        }
        if (right > x1) {
            f32 d = right - x1; right = x1; left -= d;
            if (left < x0) left = x0;
        }
    }
    f32 dx = *(f32*)(p + 0x1dc);
    f32 dy = *(f32*)(p + 0x1e0);
    left += dx; top += dy; right += dx; bottom += dy;
    if (left < x0) { f32 d = x0 - left; left = x0; right += d; }
    if (top < y0) { f32 d = y0 - top; top = y0; bottom += d; }
    if (right > x1) {
        f32 d = right - x1; right = x1; left -= d;
        if (left < x0) { f32 d = x0 - left; left += d; right = x1 + d; }
    }
    if (bottom > y1) {
        f32 d = bottom - y1; bottom = y1; top -= d;
        if (top < y0) { f32 d = y0 - top; top += d; bottom = y1 + d; }
    }
    if (out) { out[0] = left; out[1] = top; out[2] = right; out[3] = bottom; }
    if (center) *center = 0.5f * (minY + maxY) + 3072.0f;
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

extern "C" void fn_8030DD8C(u8* p, f32* rect, u8 flag) {
    f32 x0 = rect[0];
    f32 y0 = rect[1];
    f32 x1 = rect[2];
    f32 y1 = rect[3];
    u8 useLight = flag;
    *(f32*)(p + 0x164) = x0;
    *(f32*)(p + 0x168) = y0;
    *(f32*)(p + 0x16c) = x1;
    *(f32*)(p + 0x170) = y1;
    f32 hw = 0.5f * (x1 - x0);
    f32 hh = 0.5f * (y1 - y0);
    f32 cx = 0.5f * (x0 + x1);
    f32 cy = 0.5f * (y0 + y1);
    f32* m = (f32*)(p + 0x74);
    m[0] = 1.0f;
    m[1] = 0.0f;
    m[2] = 0.0f;
    m[3] = -cx;
    m[4] = 0.0f;
    m[5] = 1.0f;
    m[6] = lbl_805416EC;
    m[7] = -cy;
    m[8] = 0.0f;
    m[9] = 1.0f;
    m[10] = 0.0f;
    m[11] = -lbl_80541718;
    C_MTXOrtho((MtxPtr)(p + 0xa4), -hh, hh, -hw, hw, 0.0f, lbl_8054171C);
    if (useLight != 0) {
        PSMTXCopy((MtxPtr)(p + 0x74), (MtxPtr)(p + 0xe4));
        C_MTXLightOrtho((MtxPtr)(p + 0x114), -hh, hh, -hw, hw, lbl_805416E8, lbl_805416E8, lbl_805416E8, lbl_805416E8);
    }
    GXSetProjection((MtxPtr)(p + 0xa4), GX_ORTHOGRAPHIC);
    GXLoadPosMtxImm((MtxPtr)(p + 0x74), 0x18);
    GXLoadNrmMtxImm((MtxPtr)(p + 0x74), 0x18);
    GXSetCurrentMtx(0x18);
    u32 a = *(u32*)(p + 0x144);
    u32 b = *(u32*)(p + 0x148);
    u32 c = *(u32*)(p + 0x14c);
    u32 d = *(u32*)(p + 0x150);
    GXSetViewport((f32)a, (f32)b, (f32)(c - a), (f32)(d - b), 0.0f, 1.0f);
    GXSetScissor(a, b, c - a, d - b);
    GXSetZScaleOffset(1.0f, 0.0f);
}

extern "C" void fn_8030DFE8(u8* p, u8 flag) {
    u32 h;
    u32 w;
    if (flag) {
        JMath::gekko_ps_copy12(p + 0x74, p + 0x4);
        JMath::gekko_ps_copy12(p + 0xa4, p + 0x34);
    }
    GXSetProjection((f32(*)[4])(p + 0xa4), GX_ORTHOGRAPHIC);
    GXLoadPosMtxImm((f32(*)[4])(p + 0x74), 0x18);
    GXLoadNrmMtxImm((f32(*)[4])(p + 0x74), 0x18);
    GXSetCurrentMtx(0x18);
    w = *(u32*)(p + 0x14c) - *(u32*)(p + 0x144);
    h = *(u32*)(p + 0x150) - *(u32*)(p + 0x148);
    GXSetViewport(*(u32*)(p + 0x144), *(u32*)(p + 0x148), w, h, lbl_805416C8, lbl_805416D8);
    GXSetScissor(*(u32*)(p + 0x144), *(u32*)(p + 0x148), w, h);
    GXSetZScaleOffset(lbl_805416D8, lbl_805416C8);
}

extern "C" void fn_8030E150(void) {
}

extern u8* lbl_8053AAF8;
extern void* lbl_8053AF80;
extern f32 lbl_80541720;
extern f32 lbl_805416D8;
extern f32 lbl_805416E8;
extern f32 lbl_80541714;
extern "C" void fn_80459624(char* self, f32* pos, f32 (*mtx)[4], int idx);
extern "C" f64 __ps_add(f64 a, f64 b);
extern "C" f64 __ps_muls0(f64 a, f64 b);
extern "C" void fn_8030E154(u8* p) {
    f32 s;
    f32 v[4];
    f32 rect[4];
    Vec c;
    Vec b;
    Vec a;

    rect[0] = *(f32*)(p + 0x154);
    rect[1] = *(f32*)(p + 0x158);
    rect[2] = *(f32*)(p + 0x15c);
    rect[3] = *(f32*)(p + 0x160);

    if (lbl_8053AAF8[0x7e]) {
        if (p[0x179]) {
            *(s32*)(p + 0x174) = 3;
        } else {
            *(s32*)(p + 0x174) = 1;
        }
    } else if (p[0x179]) {
        *(s32*)(p + 0x174) = 3;
    } else if (p[0x17a]) {
        *(s32*)(p + 0x174) = 6;
    } else if (p[0x178]) {
        *(s32*)(p + 0x174) = 2;
    } else if (p[0x17b]) {
        *(s32*)(p + 0x174) = 5;
    } else if (*(s32*)(p + 0x7f0) == 0) {
        *(s32*)(p + 0x174) = 4;
    } else {
        *(s32*)(p + 0x174) = 0;
    }
    p[0x179] = 0;
    p[0x178] = 0;
    p[0x17a] = 0;
    p[0x17b] = 0;
    if (0.0f == *(f32*)(p + 0x1b4) && 0.0f == *(f32*)(p + 0x1b8) && 0.0f == *(f32*)(p + 0x1bc) && 0.0f == *(f32*)(p + 0x1c0)) {
        p[0x7f5] = 0;
    }

    u8* entry = lbl_804AA8E8 + *(s32*)(p + 0x174) * 0x24;
    if (p[0x17c]) {
        f32 dx = rect[2] - rect[0];
        f32 dy = rect[3] - rect[1];
        rect[0] = rect[0] - dx;
        rect[1] = rect[1] - dy;
        rect[2] = rect[2] + dx;
        rect[3] = rect[3] + dy;
    }
    if (!p[0x17d]) {
        fn_8030CD18(p, rect, entry, (s32)(p + 0x1b4), (u8*)v, (u8*)&s);

        if (p[0x1e8]) {
            f32 t = (f32)*(s32*)(p + 0x1ec) / lbl_80541720;
            f32 t2 = t * t;
            f32 u = lbl_805416D8 - t2;
            v[0] = t2 * v[0] + u * *(f32*)(p + 0x1a0);
            v[1] = t2 * v[1] + u * *(f32*)(p + 0x1a4);
            v[2] = t2 * v[2] + u * *(f32*)(p + 0x1a8);
            v[3] = t2 * v[3] + u * *(f32*)(p + 0x1ac);
            s = t2 * s + u * *(f32*)(p + 0x1b0);
            if (*(s32*)(p + 0x1ec) == 0) {
                p[0x1e8] = 0;
                for (s32 i = 0; i < 4; i++) {
                    u8* g = *(u8**)(lbl_8053AB10 + 0x20);
                    if (g[0x235c + i]) {
                        g[0x2360 + i] = 0;
                    }
                }
                fn_802DCDF4((char*)fn_802D6A9C());
                *(f32*)(p + 0x154) = *(f32*)(p + 0x190);
                *(f32*)(p + 0x158) = *(f32*)(p + 0x194);
                *(f32*)(p + 0x15c) = *(f32*)(p + 0x198);
                *(f32*)(p + 0x160) = *(f32*)(p + 0x19c);
                *(f32*)(p + 0x1b4) = *(f32*)(p + 0x1b8) = 0.0f;
                *(f32*)(p + 0x1bc) = *(f32*)(p + 0x1c0) = 0.0f;
            } else {
                (*(s32*)(p + 0x1ec))--;
            }
        }

        if (p[0x17e]) {
            *(f32*)(p + 0x1b4) = *(f32*)(p + 0x1b8) = 0.0f;
            *(f32*)(p + 0x1bc) = *(f32*)(p + 0x1c0) = 0.0f;
            v[0] = *(f32*)(p + 0x180);
            v[1] = *(f32*)(p + 0x184);
            v[2] = *(f32*)(p + 0x188);
            v[3] = *(f32*)(p + 0x18c);
            s = 0.5f * (v[1] + v[3]) + 3072.0f;
            p[0x17e] = 0;
        }
        fn_8030CB10(p, v, s);

        *(f32*)(p + 0x858) = (f32)(s32)JUTVideo::getManager()->getRenderMode()->fbWidth / (v[2] - v[0]);
        a.x = v[2];
        a.y = v[1];
        a.z = s;
        b.x = v[0];
        b.y = v[1];
        b.z = s;
        JMathInlineVEC::PSVECAdd(&b, &a, &c);
        JMathInlineVEC::PSVECScale(&c, &c, 0.5f);
        fn_80459624((char*)lbl_8053AF80, (f32*)&c, (f32(*)[4])(p + 0x4), 0);
    }
    *(s32*)(p + 0x7f0) = 0;
    p[0x7f4] = 0;
    p[0x7f5] = 0;
    p[0x840] = 0;
    p[0x17c] = 0;
    p[0x17d] = 0;
}

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

extern "C" u8 lbl_804AA9E4[];
extern "C" void __ct__Q29JGeometry8TVec3_f_Fv();
extern "C" void __construct_array(void* p, void (*ctor)(), void (*dtor)(), u32 size, u32 count);
extern "C" void* fn_8030E718(u8* p) {
    *(void**)p = lbl_804AA9E4;
    PSMTXIdentity((MtxPtr)(p + 0xe4));
    PSMTXIdentity((MtxPtr)(p + 0x114));
    __construct_array(p + 0x1f0, __ct__Q29JGeometry8TVec3_f_Fv, 0, 0xc, 0x80);
    return p;
}
#include "JSystem/JAudio/JASFakeMatchFSA.h"
#include "JSystem/JMath/JMath.h"
