// Game TU 801BB618-801BD108 (FALL). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"
#include "JSystem/JGeometry/Vec.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" u8 fn_8022DD74(s32 id);
extern void* lbl_804A3E44[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

extern "C" void* fn_801BCC40(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A3E44;
        if (*(u32*)(p + 0x230) & 0x8000) {
            s32 id = *(s32*)(p + 0x2c4);
            if (id >= 0) {
                fn_8022DD74(id);
            }
        }
        if (this_ != 0) {
            *(void**)p = lbl_804A4808;
            if (p + 0x270 != 0) {
                if (p + 0x294 != 0) {
                    *(void**)(p + 0x294) = lbl_8049CC34;
                }
            }
            __dt__5ActorFv(this_, 0);
        }
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_8030C210(void* obj, void* pos);
extern "C" char* fn_802D6A9C(void);
extern "C" void fn_801CEA60(void* this_);
extern "C" void fn_801CE9F8(void* this_);
extern "C" u8 fn_8022DCD8(s32 id);
extern "C" void fn_801D00B4(void* this_, s32 id, f32* out, f32 speed);
extern "C" void fn_801D01A0(void* this_, f32* target, f32* out, f32 speed);
extern "C" void fn_801CE4E8(void* this_);
extern "C" void* fn_801D0F40(void* this_);
extern void* lbl_8053AB10;
extern const f32 lbl_8053EC08;
extern const f32 lbl_8053EC0C;
extern const f32 lbl_8053EC14;
extern const f32 lbl_8053EC18;
extern const f32 lbl_8053EC1C;
extern const f32 lbl_8053EC20;
extern const f32 lbl_8053EC24;

extern "C" void fn_801BB7F4(char* this_) {
    switch (*(s32*)(this_ + 0x248)) {
    case 2:
    case 3:
    case 4:
    case 6:
    case 7:
    case 8:
        fn_8030C210(*(void**)((char*)lbl_8053AB10 + 0x24), this_ + 0xc);
        break;
    }
}

extern "C" void fn_801BB844(char* this_) {
    struct TndrG { u8 pad[0x131df]; u8 arr[4]; };
    s32 room = *(s32*)(this_ + 0x4);
    TndrG* g = (TndrG*)fn_802D6A9C();
    if (g->arr[room] == 0 && *(f32*)(this_ + 0x14) > lbl_8053EC14) {
        fn_801CEA60(this_);
    } else {
        fn_801CE9F8(this_);
    }
}

extern "C" void fn_801BB8B4(char* this_) {
    if (*(s32*)(this_ + 0x2b8) >= 0 && fn_8022DCD8(*(s32*)(this_ + 0x2b8))) {
        if (!fn_8022DD74(*(s32*)(this_ + 0x2b8))) {
            *(u32*)(this_ + 0x230) |= 0x8000;
            *(s32*)(this_ + 0x2c4) = *(s32*)(this_ + 0x2b8);
        }
        *(s32*)(this_ + 0x2b8) = -1;
    }
}

extern "C" void fn_801BB920(char* this_) {
    f32 z = lbl_8053EC0C;
    *(f32*)(this_ + 0x3c) = z;
    *(f32*)(this_ + 0x40) = z;
    *(f32*)(this_ + 0x44) = z;
    switch (*(s32*)(this_ + 0x248)) {
    case 1:
    case 2: {
        *(f32*)(this_ + 0x44) = lbl_8053EC18;
        s32 id = *(s32*)(this_ + 0x2b8);
        if (id >= 0) {
            f32 v[2];
            fn_801D00B4(this_, id, v, lbl_8053EC08);
            *(f32*)(this_ + 0x3c) = v[0];
            *(f32*)(this_ + 0x40) = v[1];
        }
        break;
    }
    case 4:
        *(f32*)(this_ + 0x44) = lbl_8053EC1C;
        break;
    case 5:
        *(f32*)(this_ + 0x44) = lbl_8053EC20;
        break;
    case 6: {
        f32 v[2];
        fn_801D01A0(this_, (f32*)(this_ + 0x2b0), v, lbl_8053EC20);
        *(f32*)(this_ + 0x3c) = v[0];
        *(f32*)(this_ + 0x40) = v[1];
        break;
    }
    case 7:
        *(f32*)(this_ + 0x44) = lbl_8053EC1C;
        break;
    case 8:
        *(f32*)(this_ + 0x44) = lbl_8053EC24;
        break;
    case 10:
        fn_801CE4E8(this_);
        break;
    }
}

extern "C" void* fn_801BCCF0(char* this_) {
    fn_801D0F40(this_);
    *(void**)this_ = lbl_804A3E44;
    *(s32*)(this_ + 0x2a8) = 0;
    *(s32*)(this_ + 0x2ac) = 0;
    *(f32*)(this_ + 0x2b0) = lbl_8053EC0C;
    *(f32*)(this_ + 0x2b4) = lbl_8053EC0C;
    *(s32*)(this_ + 0x2b8) = -1;
    *(s32*)(this_ + 0x2bc) = 0;
    *(s32*)(this_ + 0x2c0) = 0;
    *(s32*)(this_ + 0x2c4) = -1;
    *(s32*)(this_ + 0x2c8) = 8;
    *(s32*)(this_ + 0x2e4) = 0;
    *(s32*)(this_ + 0x2e8) = 2;
    *(s32*)(this_ + 0x2ec) = 0;
    return this_;
}

struct FallDrawKey {
    s32 a, b;
    FallDrawKey() { a = -1; b = -1; }
};

struct FallDrawParam {
    u8 map[16];      // 0x00
    FallDrawKey key; // 0x10
    s32 c;           // 0x18
    u8 palette;      // 0x1c
    u8 color;        // 0x1d
    u8 f1e, f1f, f20, f21, f22, f23, f24, f25, f26;
    s32 blend;       // 0x28
    u8 f2c, f2d, f2e;
    s32 g;           // 0x30
    s32 h;           // 0x34
    s32 i;           // 0x38

    FallDrawParam() {
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

extern "C" void fn_801F02BC(void* this_, const char* name, s32 id, FallDrawParam* param, s32 a, s32 b, s32 c, f32 s0, f32 s1);
extern const char lbl_804693C4[];
extern const f32 lbl_8053EC00;
extern const f32 lbl_8053EC04;
extern const f32 lbl_8053EC10;

static inline f32 fallClamp(f32 v, f32 lo, f32 hi) {
    if (v > hi) {
        return hi;
    }
    if (v < lo) {
        return lo;
    }
    return v;
}

static inline u8 fallAlpha(char* this_) {
    u8 alpha;
    switch (*(s32*)(this_ + 0x248)) {
    case 0:
    case 9:
        alpha = 0;
        break;
    case 7:
    case 8:
        alpha = 0xff;
        break;
    default: {
        f32 t = *(f32*)(this_ + 0x14);
          t -= lbl_8053EC00;
          t *= lbl_8053EC04;
        if (t > lbl_8053EC08) {
            t = lbl_8053EC08;
        } else if (t < lbl_8053EC0C) {
            t = lbl_8053EC0C;
        }
        alpha = lbl_8053EC10 * t;
        break;
    }
    }
    return alpha;
}

extern "C" void fn_801BB618(char* this_) {
    switch (*(s32*)(this_ + 0x248)) {
    case 0:
    case 9:
        return;
    }
    FallDrawParam param;
    ((u8*)&param.key.a)[3] = fallAlpha(this_);
    fn_801F02BC(this_, lbl_804693C4, *(s32*)(this_ + 0x280) + 0x8a, &param, 0x407, 0, 0, lbl_8053EC08, lbl_8053EC08);
}

struct FallRoute {
    s32 kind;   // 0x0
    s32 dir[3]; // 0x4
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1c;
    s32 f20;
    s32 f24;
};

extern "C" void fn_801BCD70(FallRoute* r, u32 flags) {
    r->kind = (flags >> 5) & 7;
    switch (r->kind) {
    case 0:
        r->dir[0] = 3;
        r->dir[1] = 0;
        r->dir[2] = 2;
        break;
    case 1:
        r->dir[0] = 3;
        r->dir[1] = 1;
        r->dir[2] = 2;
        break;
    case 2:
        r->dir[0] = 1;
        r->dir[1] = 3;
        r->dir[2] = 0;
        break;
    case 3:
        r->dir[0] = 1;
        r->dir[1] = 2;
        r->dir[2] = 0;
        break;
    case 4:
        r->dir[0] = 2;
        r->dir[1] = 0;
        r->dir[2] = 3;
        break;
    case 5:
        r->dir[0] = 2;
        r->dir[1] = 1;
        r->dir[2] = 3;
        break;
    case 6:
        r->dir[0] = 0;
        r->dir[1] = 3;
        r->dir[2] = 1;
        break;
    case 7:
        r->dir[0] = 0;
        r->dir[1] = 2;
        r->dir[2] = 1;
        break;
    }
    switch (r->kind) {
    case 0:
    case 1:
    case 4:
    case 5:
        r->f14 = 0x1e0;
        break;
    default:
        r->f14 = 0xf0;
        break;
    }
    r->f18 = 0x28;
    r->f10 = 0x28;
    r->f1c = 0;
    r->f20 = r->dir[r->f1c];
    r->f24 = 0;
}

extern "C" void fn_801D0ED0(void* this_);
extern "C" s32 fn_801CD664(s32 range);
extern "C" void fn_801D2608(void* p, void* tbl, s32 n);
extern "C" void fn_801D22DC(void* p, s32 a, s32 b, s32 c);
extern u8 lbl_804A3E30[];
extern const f32 lbl_8053EC3C;
extern const f32 lbl_8053EC68;

static inline u8 fallIsMoving(char* this_) {
    u8 r = FALSE;
    switch (*(s32*)(this_ + 0x248)) {
    case 4:
    case 6:
    case 7:
    case 8:
        r = TRUE;
        break;
    }
    return r;
}

extern "C" void fn_801BC9DC(char* this_) {
    fn_801D0ED0(this_);
    u32 kind = *(u32*)(this_ + 0x90) & 0x1f;
    if (kind >= 2) {
        *(u32*)(this_ + 0x230) |= 0x4000;
    }
    *(s32*)(this_ + 0x2a8) = kind & 1;
    fn_801BCD70((FallRoute*)(this_ + 0x2c8), *(u32*)(this_ + 0x90));
    if (*(u32*)(this_ + 0x230) & 0x4000) {
        *(s32*)(this_ + 0x2ac) = *(s32*)(this_ + 0x4);
    } else {
        *(s32*)(this_ + 0x2ac) = (*(u32*)(this_ + 0x90) >> 24) & 7;
        if (*(s32*)(this_ + 0x2ac) != 0) {
            *(s32*)(this_ + 0x2ac) += 7;
        }
    }
    if (!(*(u32*)(this_ + 0x230) & 0x4000)) {
        f32 ox = lbl_8053EC0C;
        f32 oy = ox;
        s32 room = *(s32*)(this_ + 0x2ac);
        if (room == 0) {
            char* base = fn_802D6A9C();
            f32* r;
            if (room < 8) {
                r = (f32*)(base + 0xcc);
            } else {
                r = (f32*)(base + 0xdc);
            }
            ox = r[0];
            oy = r[1];
        }
        u32 px = ((*(u32*)(this_ + 0x90) >> 16) & 0x3f) * 8;
        u32 py = ((*(u32*)(this_ + 0x90) >> 8) & 0x3f) * 8;
        *(f32*)(this_ + 0x2b0) = lbl_8053EC3C + ((f32)px + ox);
        *(f32*)(this_ + 0x2b4) = lbl_8053EC3C + ((f32)py + oy);
    }
    f32 hi = lbl_8053EC68;
    f32 lo = lbl_8053EC08;
    *(f32*)(this_ + 0x60) = lo;
    *(f32*)(this_ + 0x64) = lo;
    *(f32*)(this_ + 0x68) = hi;
    *(f32*)(this_ + 0x6c) = hi;
    *(f32*)(this_ + 0x70) = *(f32*)(this_ + 0x60);
    *(f32*)(this_ + 0x74) = *(f32*)(this_ + 0x64);
    *(f32*)(this_ + 0x78) = *(f32*)(this_ + 0x68);
    *(f32*)(this_ + 0x7c) = *(f32*)(this_ + 0x6c);
    *(f32*)(this_ + 0x80) = lo;
    *(f32*)(this_ + 0x84) = lo;
    *(f32*)(this_ + 0x88) = hi;
    *(f32*)(this_ + 0x8c) = hi;
    *(s32*)(this_ + 0x98) = 2;
    *(u32*)(this_ + 0x230) |= 0x100;
    *(u8*)(this_ + 0x194) = 1;
    if (*(s32*)(this_ + 0x2a8) == 0) {
        *(s32*)(this_ + 0x248) = 0;
        *(s32*)(this_ + 0x250) = fn_801CD664(0x79) + 0x3c;
        *(f32*)(this_ + 0x14) = lbl_8053EC00;
    } else {
        *(s32*)(this_ + 0x248) = 9;
        *(s32*)(this_ + 0x250) = fn_801CD664(0xb5) + 0xb4;
    }
    *(s32*)(this_ + 0x24c) = 0;
    *(f32*)(this_ + 0x254) = lbl_8053EC0C;
    *(f32*)(this_ + 0x258) = lbl_8053EC0C;
    fn_801D2608(this_ + 0x270, lbl_804A3E30, 5);
    fn_801D22DC(this_ + 0x270, 0, 0, 0);
    if (fallIsMoving(this_)) {
        *(u32*)(this_ + 0xb0) = 0x40004;
    } else {
        *(u32*)(this_ + 0xb0) = 0x41101;
    }
}

struct FallSound {
    u8 pad[0x4c];
    f32 volume;
};
extern "C" FallSound* fn_801F1184(void* this_);
extern "C" void fn_801F0E34(void* this_, s32 p1, s32 p2);
extern "C" s32 fn_801D05F8(void* this_, void* pos, f32 r);

extern "C" f32* fn_8023E724(s32 id);
extern "C" void fn_8023DFF4(s32 id, void* v);
extern "C" s32 fn_80236228(s32 id);
extern "C" void fn_80236074(s32 id, s32 n, s32 f);
extern const f32 lbl_8053EC30;
extern const f32 lbl_8053EC58;

static inline u8 fallIsFalling(char* this_) {
    u8 r = FALSE;
    switch (*(s32*)(this_ + 0x248)) {
    case 6:
    case 7:
    case 8:
        r = TRUE;
        break;
    }
    return r;
}

struct FallVec {
    f32 x, y, z;
    FallVec(f32 x_, f32 y_, f32 z_) { x = x_; y = y_; z = z_; }
};

extern "C" void fn_801BC554(char* this_, s32 state);

extern "C" void fn_801BC244(char* this_) {
    switch (*(s32*)(this_ + 0x248)) {
    case 1:
    case 2: {
        u8 alpha = fallAlpha(this_);
        FallSound* snd = fn_801F1184(this_);
        snd->volume = alpha / lbl_8053EC10;
        fn_801F0E34(this_, 0x400a3, 0);
        break;
    }
    }
    switch (*(s32*)(this_ + 0x248)) {
    case 1:
    case 2: {
        (*(s32*)(this_ + 0x2bc))++;
        s32 p = fn_801D05F8(this_, this_ + 0xc, lbl_8053EC0C);
        if (p != *(s32*)(this_ + 0x2b8)) {
            if (p < 0) {
                if (*(s32*)(this_ + 0x248) != 1 || *(s32*)(this_ + 0x24c) >= 0x3c) {
                    fn_801BC554(this_, 5);
                }
            } else if (*(s32*)(this_ + 0x2bc) >= 0x2d) {
                *(s32*)(this_ + 0x2b8) = p;
                *(s32*)(this_ + 0x2bc) = 0;
            }
        }
        break;
    }
    }
    if (fallIsMoving(this_)) {
        if (!fn_8022DCD8(*(s32*)(this_ + 0x2b8))) {
            fn_801BC554(this_, 5);
        } else {
            FallVec v(*(f32*)(this_ + 0xc) - fn_8023E724(*(s32*)(this_ + 0x2b8))[0], *(f32*)(this_ + 0x10) - fn_8023E724(*(s32*)(this_ + 0x2b8))[1], *(f32*)(this_ + 0x14) - fn_8023E724(*(s32*)(this_ + 0x2b8))[2] - lbl_8053EC30);
            v.x *= lbl_8053EC58;
            v.y *= lbl_8053EC58;
            fn_8023DFF4(*(s32*)(this_ + 0x2b8), &v);
        }
    }
    if (fallIsFalling(this_)) {
        (*(s32*)(this_ + 0x2c0))++;
        if (*(s32*)(this_ + 0x2c0) >= 0x78) {
            if (fn_80236228(*(s32*)(this_ + 0x2b8)) >= 0x14) {
                fn_80236074(*(s32*)(this_ + 0x2b8), 0x14, 1);
            }
            *(s32*)(this_ + 0x2c0) = 0;
        }
    }
    if ((*(u32*)(this_ + 0x230) & 0x8000) && fn_8022DD74(*(s32*)(this_ + 0x2c4))) {
        *(u32*)(this_ + 0x230) &= ~0x8000;
        *(s32*)(this_ + 0x2c4) = -1;
    }
}

extern "C" f32* fn_8023E604(s32 id);
extern "C" void fn_801D22A0(void* p, s32 a, s32 b);
extern const f32 lbl_8053EC44;
extern const f32 lbl_8053EC48;
extern const f32 lbl_8053EC4C;
extern const f32 lbl_8053EC6C;

static inline void fallSetBoxIdle(char* this_) {
    f32 lo = lbl_8053EC08;
    f32 hi = lbl_8053EC68;
    *(f32*)(this_ + 0x60) = lo;
    *(f32*)(this_ + 0x64) = lo;
    *(f32*)(this_ + 0x68) = hi;
    *(f32*)(this_ + 0x6c) = hi;
    *(f32*)(this_ + 0x70) = *(f32*)(this_ + 0x60);
    *(f32*)(this_ + 0x74) = *(f32*)(this_ + 0x64);
    *(f32*)(this_ + 0x78) = *(f32*)(this_ + 0x68);
    *(f32*)(this_ + 0x7c) = *(f32*)(this_ + 0x6c);
}

static inline void fallSetPos(char* this_, f32 x, f32 y, f32 z) {
    *(f32*)(this_ + 0xc) = x;
    *(f32*)(this_ + 0x10) = y;
    *(f32*)(this_ + 0x14) = z;
}

static inline void fallSetBoxHold(char* this_) {
    *(f32*)(this_ + 0x60) = lbl_8053EC44;
    *(f32*)(this_ + 0x64) = lbl_8053EC48;
    *(f32*)(this_ + 0x68) = lbl_8053EC4C;
    *(f32*)(this_ + 0x6c) = lbl_8053EC3C;
    *(f32*)(this_ + 0x70) = *(f32*)(this_ + 0x60);
    *(f32*)(this_ + 0x74) = *(f32*)(this_ + 0x64);
    *(f32*)(this_ + 0x78) = *(f32*)(this_ + 0x68);
    *(f32*)(this_ + 0x7c) = *(f32*)(this_ + 0x6c);
}

extern "C" void fn_801BC554(char* this_, s32 state) {
    switch (state) {
    case 0:
        *(u32*)(this_ + 0x230) &= ~0x2000;
        *(s32*)(this_ + 0x2b8) = -1;
        *(s32*)(this_ + 0x2bc) = 0;
        fallSetBoxIdle(this_);
        *(s32*)(this_ + 0x98) = 2;
        *(s32*)(this_ + 0x250) = fn_801CD664(0x79) + 0x3c;
        fallSetPos(this_, *(f32*)(this_ + 0x24), *(f32*)(this_ + 0x28), lbl_8053EC00);
        *(s32*)(this_ + 0x4) = *(s32*)(this_ + 0x8);
        break;
    case 1:
        *(s32*)(this_ + 0x2bc) = 0;
        fallSetBoxHold(this_);
        fn_801D22DC(this_ + 0x270, 0, 0, 0);
        if (*(s32*)(this_ + 0x248) != 5) {
            fallSetPos(this_, *(f32*)(this_ + 0x24), *(f32*)(this_ + 0x28), lbl_8053EC00);
            *(s32*)(this_ + 0x4) = *(s32*)(this_ + 0x8);
        }
        break;
    case 3:
        *(s32*)(this_ + 0x2bc) = 0;
        fallSetBoxHold(this_);
        fn_801D22DC(this_ + 0x270, 2, 0, 0);
        break;
    case 4:
    case 6:
    case 7:
    case 8:
        *(u32*)(this_ + 0x230) |= 0x2000;
        *(s32*)(this_ + 0x2bc) = 0;
        fallSetBoxHold(this_);
        fn_801D22DC(this_ + 0x270, 1, 0, 0);
        if (state == 4 && (*(u32*)(this_ + 0x230) & 0x4000)) {
            f32* p = fn_8023E604(*(s32*)(this_ + 0x2b8));
            *(f32*)(this_ + 0x2b0) = p[0];
            *(f32*)(this_ + 0x2b4) = p[1];
        }
        break;
    case 5:
        *(s32*)(this_ + 0x2b8) = -1;
        *(s32*)(this_ + 0x2bc) = 0;
        fallSetBoxHold(this_);
        fn_801D22DC(this_ + 0x270, 0, 0, 0);
        break;
    case 9:
        *(u32*)(this_ + 0x230) &= ~0x2000;
        *(s32*)(this_ + 0x2b8) = -1;
        *(s32*)(this_ + 0x2bc) = 0;
        fallSetBoxIdle(this_);
        *(s32*)(this_ + 0x98) = 2;
        *(s32*)(this_ + 0x250) = fn_801CD664(0xb5) + 0xb4;
        *(f32*)(this_ + 0x254) = lbl_8053EC0C;
        *(f32*)(this_ + 0x258) = lbl_8053EC0C;
        *(f32*)(this_ + 0xc) = *(f32*)(this_ + 0x24);
        *(f32*)(this_ + 0x10) = *(f32*)(this_ + 0x28);
        *(f32*)(this_ + 0x14) = *(f32*)(this_ + 0x2c);
        *(s32*)(this_ + 0x4) = *(s32*)(this_ + 0x8);
        break;
    case 10:
        *(u32*)(this_ + 0x230) &= ~0x2000;
        *(s32*)(this_ + 0x2b8) = -1;
        *(s32*)(this_ + 0x2bc) = 0;
        fallSetBoxHold(this_);
        *(f32*)(this_ + 0x254) = lbl_8053EC6C;
        *(f32*)(this_ + 0x258) = lbl_8053EC6C;
        *(s32*)(this_ + 0x2e4) = 0;
        *(s32*)(this_ + 0x2e8) = ((FallRoute*)(this_ + 0x2c8))->dir[*(s32*)(this_ + 0x2e4)];
        *(s32*)(this_ + 0x2ec) = 0;
        fn_801D22A0(this_ + 0x270, 4, 2);
        break;
    }
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x248) = state;
    if (!fallIsFalling(this_)) {
        *(s32*)(this_ + 0x2c0) = 0;
    }
    if (fallIsMoving(this_)) {
        *(u32*)(this_ + 0xb0) = 0x40004;
    } else {
        *(u32*)(this_ + 0xb0) = 0x41101;
    }
}

extern "C" u8 fn_801D08B4(void* this_, s32 player, void* pos, f32 r);
extern "C" void* fn_801F856C(void);
extern "C" s32 Actor_CreateByID(void* mgr, u32 id, s32 owner, void* pos, u32 param, s32 a, s32 b);
extern "C" u8 fn_801D21F0(void* p);
extern "C" u8 fn_801CD2F8(s32 room);
extern "C" u8 fn_801CD1D0(s32 id);
extern "C" u8 fn_801F2740(void* this_, s32 a);
extern "C" u8 fn_8022DE10(s32 id, s32 a);
extern "C" void fn_802316C8(s32 id, s32 room, JGeometry::TVec3<f32> pos);
extern const f32 lbl_8053EC28;
extern const f32 lbl_8053EC2C;
extern const f32 lbl_8053EC34;
extern const f32 lbl_8053EC38;
extern const f32 lbl_8053EC40;
extern const f32 lbl_8053EC50;
extern const f32 lbl_8053EC54;

static inline u8 fallLost(char* this_) {
    u8 r = !fn_801D08B4(this_, *(s32*)(this_ + 0x2b8), this_ + 0x24, lbl_8053EC2C);
    return r;
}

static inline u8 fallTryGrab(char* this_) {
    u8 grabbed = FALSE;
    s32 st = *(s32*)(this_ + 0x248);
    if ((st == 10 || (st == 3 && *(s32*)(this_ + 0x280) == 1)) && *(s32*)(this_ + 0x2b8) >= 0 &&
        !fn_8022DCD8(*(s32*)(this_ + 0x2b8)) &&
        (fn_801CD2F8(*(s32*)(this_ + 0x4)) || !fn_801CD2F8(*(s32*)(this_ + 0x2ac)) || !fn_801CD1D0(*(s32*)(this_ + 0x2b8)))) {
        *(f32*)(this_ + 0x60) = lbl_8053EC34;
        *(f32*)(this_ + 0x64) = lbl_8053EC38;
        *(f32*)(this_ + 0x68) = lbl_8053EC3C;
        *(f32*)(this_ + 0x6c) = lbl_8053EC40;
        if (fn_801F2740(this_, -1) & (1 << *(s32*)(this_ + 0x2b8))) {
            grabbed = TRUE;
        }
        fallSetBoxHold(this_);
    }
    return grabbed;
}

static inline void fallRelease(char* this_) {
    if (!fn_8022DD74(*(s32*)(this_ + 0x2b8))) {
        *(u32*)(this_ + 0x230) |= 0x8000;
        *(s32*)(this_ + 0x2c4) = *(s32*)(this_ + 0x2b8);
    }
}

extern "C" void fn_801BBA0C(char* this_) {
    fn_801BC244(this_);
    switch (*(s32*)(this_ + 0x248)) {
    case 0:
        if (*(s32*)(this_ + 0x24c) >= *(s32*)(this_ + 0x250) && !(*(u32*)(this_ + 0x230) & 0x2000)) {
            s32 p = fn_801D05F8(this_, this_ + 0x24, lbl_8053EC28);
            if (p >= 0) {
                *(s32*)(this_ + 0x2b8) = p;
                fn_801BC554(this_, 1);
            }
        }
        break;
    case 1:
        if (*(s32*)(this_ + 0x24c) >= 0x3c && fallLost(this_)) {
            fn_801BC554(this_, 5);
        } else if (*(f32*)(this_ + 0x14) <= lbl_8053EC28) {
            fn_801BC554(this_, 2);
        } else if (*(s32*)(this_ + 0x24c) >= 0x10) {
            switch (*(s32*)(this_ + 0x278)) {
            case 0: {
                u8 a = fallAlpha(this_);
                if (a >= 150 && a <= 200) {
                    fn_801D22DC(this_ + 0x270, 3, 0, 0);
                }
                break;
            }
            case 3:
                if (fn_801D21F0(this_ + 0x270)) {
                    fn_801D22DC(this_ + 0x270, 0, 0, 0);
                }
                break;
            }
        }
        break;
    case 2:
        if (fallLost(this_)) {
            fn_801BC554(this_, 5);
        } else if (*(f32*)(this_ + 0x14) <= lbl_8053EC30) {
            *(f32*)(this_ + 0x14) = lbl_8053EC30;
            fn_801BC554(this_, 3);
        } else if (*(s32*)(this_ + 0x278) == 3 && fn_801D21F0(this_ + 0x270)) {
            fn_801D22DC(this_ + 0x270, 0, 0, 0);
        }
        break;
    case 3:
        if (fallTryGrab(this_)) {
            if (fn_8022DE10(*(s32*)(this_ + 0x2b8), 0)) {
                fn_801BC554(this_, 4);
            } else if (*(s32*)(this_ + 0x24c) > 1 && fn_801D21F0(this_ + 0x270)) {
                fn_801BC554(this_, 5);
            }
        } else if (*(s32*)(this_ + 0x24c) > 1 && fn_801D21F0(this_ + 0x270)) {
            fn_801BC554(this_, 5);
        }
        break;
    case 4:
        if (*(f32*)(this_ + 0x14) >= lbl_8053EC50) {
            if (*(s32*)(this_ + 0x2ac) != *(s32*)(this_ + 0x4)) {
                fn_801BC554(this_, 7);
            } else {
                *(f32*)(this_ + 0x14) = lbl_8053EC50;
                fn_801BC554(this_, 6);
            }
        }
        break;
    case 5: {
        s32 p = fn_801D05F8(this_, this_ + 0x24, lbl_8053EC28);
        if (*(s32*)(this_ + 0x24c) >= 100 && !(*(u32*)(this_ + 0x230) & 0x2000) && p >= 0) {
            *(s32*)(this_ + 0x2b8) = p;
            fn_801BC554(this_, 1);
        } else if (*(f32*)(this_ + 0x14) >= lbl_8053EC00) {
            if (*(s32*)(this_ + 0x2a8) == 0) {
                fn_801BC554(this_, 0);
            } else {
                fn_801BC554(this_, 9);
            }
        }
        break;
    }
    case 6:
        if (__fabsf(*(f32*)(this_ + 0x2b0) - *(f32*)(this_ + 0xc)) < lbl_8053EC54 &&
            __fabsf(*(f32*)(this_ + 0x2b4) - *(f32*)(this_ + 0x10)) < lbl_8053EC54) {
            fallRelease(this_);
            fn_801BC554(this_, 5);
        }
        break;
    case 7:
        if (*(f32*)(this_ + 0x14) >= lbl_8053EC00) {
            *(f32*)(this_ + 0x14) = lbl_8053EC00;
            *(s32*)(this_ + 0x4) = *(s32*)(this_ + 0x2ac);
            *(f32*)(this_ + 0xc) = *(f32*)(this_ + 0x2b0);
            *(f32*)(this_ + 0x10) = *(f32*)(this_ + 0x2b4);
            JGeometry::TVec3<f32> v(*(f32*)(this_ + 0xc), *(f32*)(this_ + 0x10), *(f32*)(this_ + 0x14) - lbl_8053EC30);
            fn_802316C8(*(s32*)(this_ + 0x2b8), *(s32*)(this_ + 0x2ac), v);
            fn_801BC554(this_, 8);
        }
        break;
    case 8:
        if (*(f32*)(this_ + 0x14) <= lbl_8053EC50) {
            *(f32*)(this_ + 0x14) = lbl_8053EC50;
            fallRelease(this_);
            fn_801BC554(this_, 5);
        }
        break;
    case 9:
        if (*(s32*)(this_ + 0x24c) >= *(s32*)(this_ + 0x250)) {
            Actor_CreateByID(fn_801F856C(), 0x4b4d5249, *(s32*)(this_ + 0x4), this_ + 0xc, 3, -1, -1);
            fn_801BC554(this_, 10);
        }
        break;
    case 10: {
        u8 done = FALSE;
        if (*(s32*)(this_ + 0x2e4) > 2) {
            done = TRUE;
        } else {
            (*(s32*)(this_ + 0x2ec))++;
            if (*(s32*)(this_ + 0x2ec) >= ((s32*)(this_ + 0x2d8))[*(s32*)(this_ + 0x2e4)]) {
                (*(s32*)(this_ + 0x2e4))++;
                if (*(s32*)(this_ + 0x2e4) > 2) {
                    done = TRUE;
                } else {
                    *(s32*)(this_ + 0x2e8) = ((s32*)(this_ + 0x2cc))[*(s32*)(this_ + 0x2e4)];
                    *(s32*)(this_ + 0x2ec) = 0;
                }
            }
        }
        if (done) {
            Actor_CreateByID(fn_801F856C(), 0x4b4d5249, *(s32*)(this_ + 0x4), this_ + 0xc, 3, -1, -1);
            fn_801BC554(this_, 9);
        } else {
            *(s32*)(this_ + 0x98) = *(s32*)(this_ + 0x2e8);
            *(s32*)(this_ + 0x2b8) = fn_801D05F8(this_, this_ + 0xc, lbl_8053EC28);
            if (*(s32*)(this_ + 0x2b8) >= 0 && fallTryGrab(this_) && fn_8022DE10(*(s32*)(this_ + 0x2b8), 0)) {
                *(s32*)(this_ + 0x98) = 2;
                fn_801BC554(this_, 4);
            }
        }
        break;
    }
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
