#ifndef GAME_TLWP_DRAW_PARAM_H
#define GAME_TLWP_DRAW_PARAM_H
#include "types.h"
struct TlwpDrawKey {
    s32 a, b;
    TlwpDrawKey() { a = -1; b = -1; }
};
struct TlwpDrawParam {
    u8 map[16];      // 0x00
    TlwpDrawKey key; // 0x10
    void* c;         // 0x18
    u8 palette;      // 0x1c
    u8 color;        // 0x1d
    u8 f1e, f1f, f20, f21, f22, f23, f24, f25, f26;
    s32 blend;       // 0x28
    u8 f2c, f2d, f2e;
    s32 g;           // 0x30
    s32 h;           // 0x34
    s32 i;           // 0x38

    TlwpDrawParam() {
        for (u8 n = 0; n < 16; n++) {
            map[n] = n;
        }
        key.a = -1;
        key.b = 0;
        c = 0;
        palette = 0;
        color = 0;
        f1e = 0;
        f1f = 1;
        f20 = 1;
        f21 = 0;
        f22 = 0;
        f23 = 0;
        f24 = 0;
        f25 = 0;
        f26 = 1;
        blend = 3;
        f2c = 1;
        f2d = 0;
        f2e = 0;
        g = -1;
        h = 0;
        i = 2;
    }
};
extern "C" double sin(double);
extern "C" double cos(double);
static inline void tlwpRotMtx(f32 m[3][4], f32 ax, f32 ay, f32 az, const f32 s) {
    f32 sz, sy, sx, cz, cy, cx;
    sx = sin(ax);
    sy = sin(ay);
    sz = sin(az);
    cx = cos(ax);
    cy = cos(ay);
    cz = cos(az);
    m[0][0] = s * (cy * cz);
    m[1][0] = s * (cy * sz);
    m[2][0] = s * -sy;
    f32 sxcz, sxsz, cxcz, cxsz, sxsy;
    sxsy = sx * sy;
    cxsz = cx * sz;
    cxcz = cx * cz;
    sxsz = sx * sz;
    sxcz = sx * cz;
    m[0][1] = s * (sxsy * cz - cxsz);
    m[1][1] = s * (sxsy * sz + cxcz);
    m[2][1] = s * (sx * cy);
    m[0][2] = s * (cxcz * sy + sxsz);
    m[1][2] = s * (cxsz * sy - sxcz);
    m[2][2] = s * (cx * cy);
}
#endif
