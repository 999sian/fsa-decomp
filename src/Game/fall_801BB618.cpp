// Game TU 801BB618-801BD108 (FALL). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"

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
    s32 room = *(s32*)(this_ + 0x4);
    if (((u8*)fn_802D6A9C() + room)[0x131df] == 0 && *(f32*)(this_ + 0x14) > lbl_8053EC14) {
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

extern "C" void fn_801BB618(char* this_) {
    switch (*(s32*)(this_ + 0x248)) {
    case 0:
    case 9:
        return;
    }
    FallDrawParam param;
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
        f32 t = (*(f32*)(this_ + 0x14) - lbl_8053EC00) * lbl_8053EC04;
        f32 hi = lbl_8053EC08;
        if (t > hi) {
            t = hi;
        } else if (t < lbl_8053EC0C) {
            t = lbl_8053EC0C;
        }
        alpha = lbl_8053EC10 * t;
        break;
    }
    }
    ((u8*)&param.key.a)[3] = alpha;
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

#include "JSystem/JAudio/JASFakeMatchFSA.h"
