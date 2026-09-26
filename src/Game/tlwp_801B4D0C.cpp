// Game TU 801B4D0C-801B6634 (TLWP). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"

extern "C" void* fn_8013C824(void);
extern "C" void fn_800EC240(void* a, void* b);
extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804A38D4[];

extern "C" void* fn_801B609C(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804A38D4;
        char* p = (char*)this_;
        int i = 0;
        do {
            if (*(void**)(p + 0x294)) {
                void* base = fn_8013C824();
                void* a = *(void**)((char*)base + 0xc);
                fn_800EC240(a, *(void**)(p + 0x294));
                *(void**)(p + 0x294) = 0;
            }
            i++;
            p += 4;
        } while (i < 3);
        p = (char*)this_;
        int j = 0;
        do {
            if (*(void**)(p + 0x2a0)) {
                void* base = fn_8013C824();
                void* a = *(void**)((char*)base + 0xc);
                fn_800EC240(a, *(void**)(p + 0x2a0));
                *(void**)(p + 0x2a0) = 0;
            }
            j++;
            p += 4;
        } while (j < 0x14);
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

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
struct TlwpSave { u8 pad[0x10]; s32 cur; u8 pad2[0x7a - 0x14]; u8 mask; };
extern TlwpSave lbl_8050EC80;
extern const char lbl_804690F8[];
extern const f32 lbl_8053EA10;
extern "C" void fn_801F02BC(void* this_, const char* name, s32 id, TlwpDrawParam* param, s32 a, s32 b, s32 c, f32 s0, f32 s1);
extern "C" void fn_801F06F0(void* this_, const char* name, s32 id, TlwpDrawParam* param, s32 a, f32 s0, f32 s1);
extern "C" void fn_801B4EC8(char* p);
extern "C" void fn_801B56A0(void* this_);
extern "C" void fn_801B5228(char* p);

extern "C" void fn_801B4D0C(char* p) {
    switch (*(s32*)(p + 0x250)) {
    case 0: {
        u8 m = 1 << *(s32*)(p + 0x254);
        if (((TlwpSave*)((u8*)&lbl_8050EC80 + lbl_8050EC80.cur * 0xc8))->mask & m) {
            TlwpDrawParam param;
            *(s8*)&param.color = -1;
            fn_801F06F0(p, lbl_804690F8, 0x431, &param, -1, lbl_8053EA10, lbl_8053EA10);
            fn_801F02BC(p, lbl_804690F8, 0x431, &param, -1, 0, 0, lbl_8053EA10, lbl_8053EA10);
        }
        break;
    }
    case 1:
    case 2:
    case 3:
        fn_801B4EC8(p);
        break;
    }
}

extern "C" void fn_801B5198(char* p) {
    switch (*(s32*)(p + 0x250)) {
    case 0:
        fn_801B56A0(p);
        break;
    case 1:
    case 2:
    case 3:
        fn_801B5228(p);
        break;
    }
    for (s32 i = 0; i < 3; i++) {
        if (*(s32*)(p + i * 4 + 0x234) > 0) {
            (*(s32*)(p + i * 4 + 0x234))--;
        }
    }
}

struct TlwpVec { f32 x, y, z; };
struct TlwpRect { f32 x0, y0, x1, y1; };
extern const f32 lbl_8053EA7C;
extern const f32 lbl_8053EA80;
extern const f32 lbl_8053EA84;
extern const f32 lbl_8053EA3C;
extern const f32 lbl_8053EA88;
extern const f32 lbl_8053EA8C;
extern const f32 lbl_8053EA90;
extern const f32 lbl_8053EA18;
extern const f32 lbl_8053EA58;
extern u8 lbl_8053ABF8;
extern s32 lbl_8053A118;
struct TlwpData {
    u16 ids[20];      // 0x00
    u8 pad[0x88 - 0x28];
    s32 model[3][4];  // 0x88
    s32 timer[3][4];  // 0xb8
    s32 kind[3];      // 0xe8
};
extern TlwpData lbl_804A37E0;
extern "C" char* fn_802D6A9C(void);
extern "C" s32 fn_8013CC50(s32 room, TlwpVec* pos, f32 scale, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);

static inline void tlwpSet(TlwpVec* v, f32 x, f32 y, f32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

static inline void tlwpLerp(TlwpVec* v, const TlwpRect* r, f32 t, f32 z) {
    tlwpSet(v, r->x0 + t * (r->x1 - r->x0), r->y0 + t * (r->y1 - r->y0), z);
}

extern "C" void fn_801B6170(char* p) {
    *(f32*)(p + 0x60) = lbl_8053EA7C;
    *(f32*)(p + 0x64) = lbl_8053EA7C;
    *(f32*)(p + 0x68) = lbl_8053EA80;
    *(f32*)(p + 0x6c) = lbl_8053EA80;
    *(f32*)(p + 0x80) = lbl_8053EA84;
    *(f32*)(p + 0x84) = lbl_8053EA84;
    *(f32*)(p + 0x88) = lbl_8053EA3C;
    *(f32*)(p + 0x8c) = lbl_8053EA3C;
    *(s32*)(p + 0x240) = 0;
    *(s32*)(p + 0x244) = 0;
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x234) = 0;
    *(s32*)(p + 0x238) = 0;
    *(s32*)(p + 0x23c) = 0;
    *(s32*)(p + 0x294) = 0;
    *(s32*)(p + 0x298) = 0;
    *(s32*)(p + 0x29c) = 0;
    *(s32*)(p + 0x2a0) = 0;
    *(s32*)(p + 0x2a4) = 0;
    *(s32*)(p + 0x2a8) = 0;
    *(s32*)(p + 0x2ac) = 0;
    *(s32*)(p + 0x2b0) = 0;
    *(s32*)(p + 0x2b4) = 0;
    *(s32*)(p + 0x2b8) = 0;
    *(s32*)(p + 0x2bc) = 0;
    *(s32*)(p + 0x2c0) = 0;
    *(s32*)(p + 0x2c4) = 0;
    *(s32*)(p + 0x2c8) = 0;
    *(s32*)(p + 0x2cc) = 0;
    *(s32*)(p + 0x2d0) = 0;
    *(s32*)(p + 0x2d4) = 0;
    *(s32*)(p + 0x2d8) = 0;
    *(s32*)(p + 0x2dc) = 0;
    *(s32*)(p + 0x2e0) = 0;
    *(s32*)(p + 0x2e4) = 0;
    *(s32*)(p + 0x2e8) = 0;
    *(s32*)(p + 0x2ec) = 0;
    lbl_8053ABF8 = 0;
    *(f32*)(p + 0x25c) = lbl_8053EA10;
    *(s32*)(p + 0x250) = (*(u32*)(p + 0x90) >> 4) & 0xf;
    *(s32*)(p + 0x254) = *(u32*)(p + 0x90) & 0xf;
    if (*(s32*)(p + 0x250) == 0 && *(s32*)(p + 0x254) == 0) {
        char* cfg = fn_802D6A9C();
        TlwpRect r = *(TlwpRect*)(cfg + 0xcc);
        TlwpVec v;
        TlwpVec* pos = (TlwpVec*)(p + 0xc);
        v.x = pos->x;
        v.y = pos->y;
        tlwpLerp(&v, &r, lbl_8053EA88, pos->z);
        tlwpSet(&v, pos->x, pos->y, pos->z);
        v.x += lbl_8053EA8C;
        v.y += lbl_8053EA90;
        for (s32 i = 0; i < 20; i++) {
            *(s32*)(p + i * 4 + 0x2a0) = fn_8013CC50(*(s32*)(p + 0x4), &v, lbl_8053EA10, lbl_804A37E0.ids[i], 0, 0, 0, 0, 1);
        }
    }
    *(s32*)(p + 0x24c) = 0;
    *(TlwpVec*)(p + 0x264) = *(TlwpVec*)(p + 0xc);
    *(TlwpVec*)(p + 0x270) = *(TlwpVec*)(p + 0xc);
    *(TlwpVec*)(p + 0x27c) = *(TlwpVec*)(p + 0xc);
    *(TlwpVec*)(p + 0x288) = *(TlwpVec*)(p + 0xc);
    *(f32*)(p + 0x258) = lbl_8053EA18;
    *(u16*)(p + 0x260) = 0;
    if (*(s32*)(p + 0x250) == 0) {
        lbl_8053A118 = 3;
        *(s32*)(p + 0x230) = 0;
    } else {
        *(f32*)(p + 0x14) = lbl_8053EA58;
        *(s32*)(p + 0x230) = 8;
    }
}

extern "C" double sin(double);
extern "C" double cos(double);
extern const char lbl_8046910C[];
extern const f32 lbl_8053EA14;

static inline void tlwpRotMtx(f32 m[3][4], f32 ax, f32 ay, f32 az, f32 s) {
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

extern "C" void fn_801B4EC8(char* p) {
    TlwpDrawParam param;
    f32 m[3][4];
    switch (*(s32*)(p + 0x250)) {
    case 2:
        param.color = 1;
        param.map[2] = 9;
        break;
    case 1:
        param.color = 1;
        param.map[2] = 3;
        break;
    case 3:
        param.color = 1;
        param.map[2] = 4;
        break;
    }
    tlwpRotMtx(m, lbl_8053EA18, (f32)*(u16*)(p + 0x260) / lbl_8053EA14, lbl_8053EA18, lbl_8053EA10);
    param.c = m;
    fn_801F06F0(p, lbl_8046910C, *(s32*)(p + 0x24c) + 0xc0, &param, 7, lbl_8053EA10, lbl_8053EA10);
}

#include <std/math.h>
extern const f32 lbl_8053EA28;
extern const f32 lbl_8053EA2C;
extern const f32 lbl_8053EA30;
extern const f32 lbl_8053EA34;
extern const f32 lbl_8053EA38;
extern const f32 lbl_8053EA5C;
extern const f32 lbl_8053EA60;
extern "C" void fn_801F71A4(f32* v, f32 target, f32 a, f32 b);
extern "C" u8 fn_8023F264(s32 id);
extern "C" s32 fn_8023DE58(s32 id);
extern "C" TlwpVec* fn_8023E724(s32 id);
extern "C" void fn_80230498(s32 player, TlwpVec* pos, s32 id, s32 a, s32 b, s32 c, s32 d);
extern "C" void fn_801F0E34(void* target, u32 effectId, s32 flag);

extern "C" void fn_801B5228(char* p) {
    s32 room;
    TlwpData* d = &lbl_804A37E0;
    fn_801F71A4((f32*)(p + 0x14), *(f32*)(p + 0x258), lbl_8053EA28, *(f32*)(p + 0x25c));
    switch (*(s32*)(p + 0x230)) {
    case 8: {
        *(s32*)(p + 0x98) = d->kind[*(s32*)(p + 0x250) - 1];
        for (s32 i = 0; i < 4; i++) {
            if (fn_8023F264(i)) {
                room = *(s32*)(p + 0x4);
                if (room == fn_8023DE58(i)) {
                    *(TlwpVec*)(p + i * 0xc + 0x264) = *fn_8023E724(i);
                    if (i == 0) {
                        *(f32*)(p + i * 0xc + 0x268) += lbl_8053EA2C;
                    }
                }
            }
        }
        *(f32*)(p + 0x25c) = lbl_8053EA30;
        *(s32*)(p + 0x230) = 9;
    }
    case 9: {
        TlwpVec* pos = fn_8023E724(0);
        f32 x = pos->x;
        f32 y = pos->y;
        *(f32*)(p + 0x258) = lbl_8053EA34;
        if (*(s32*)(p + 0x250) == 1) {
            *(u16*)(p + 0x260) = 3000;
            x -= lbl_8053EA38;
            *(f32*)(p + 0x258) = lbl_8053EA3C;
        }
        if (*(s32*)(p + 0x250) == 3) {
            *(u16*)(p + 0x260) = 0x10000 - 3000;
            x += lbl_8053EA38;
            *(f32*)(p + 0x258) = lbl_8053EA3C;
        }
        fn_801F71A4((f32*)(p + 0xc), x, lbl_8053EA28, *(f32*)(p + 0x25c));
        *(f32*)(p + 0x10) = y;
        f32 dz = fabs(*(f32*)(p + 0x14) - *(f32*)(p + 0x258));
        f32 dx = fabs(*(f32*)(p + 0xc) - x);
        if (std::sqrtf(dx * dx + dz * dz) < lbl_8053EA10) {
            if (--lbl_8053A118 == 0) {
                for (s32 i = 0; i < 4; i++) {
                    if (fn_8023F264(i)) {
                        room = *(s32*)(p + 0x4);
                        if (room == fn_8023DE58(i)) {
                            fn_80230498(i, (TlwpVec*)(p + i * 0xc + 0x264), 0x3e, 0xff, -0x80, -0x80, 1);
                        }
                    }
                }
                fn_801F0E34(p, 0x50052, 0);
                *(s32*)(p + 0x230) = 10;
            }
        }
        break;
    }
    case 10:
        if (lbl_8053A118 <= 0) {
            if (lbl_8053EA58 != *(f32*)(p + 0x258)) {
                *(f32*)(p + 0x258) = lbl_8053EA58;
                *(f32*)(p + 0x25c) = lbl_8053EA5C;
            } else if (*(s32*)(p + 0x250) == 2) {
                f32 z = *(f32*)(p + 0x14);
                for (s32 i = 0; i < 4; i++) {
                    if (fn_8023F264(i)) {
                        room = *(s32*)(p + 0x4);
                        if (room == fn_8023DE58(i)) {
                        fn_801F71A4((f32*)(p + i * 0xc + 0x26c), z, lbl_8053EA28, *(f32*)(p + 0x25c));
                        fn_80230498(i, (TlwpVec*)(p + i * 0xc + 0x264), 0xb0, 0xff, -0x80, -0x80, 1);
                        }
                    }
                }
                if ((f32)fabs(*(f32*)(p + 0x14) - *(f32*)(p + 0x258)) < lbl_8053EA60) {
                    lbl_8053A118 = 0x309;
                }
            }
        }
        break;
    }
    if (*(s32*)(p + 0x234) == 0) {
        *(s32*)(p + 0x24c) = d->model[*(s32*)(p + 0x98)][*(s32*)(p + 0x240)];
        *(s32*)(p + 0x234) = d->timer[*(s32*)(p + 0x98)][*(s32*)(p + 0x240)];
        (*(s32*)(p + 0x240))++;
        *(s32*)(p + 0x240) &= 3;
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
