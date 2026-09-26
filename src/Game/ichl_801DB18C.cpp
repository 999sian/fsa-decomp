// Game TU 801DB18C-801DC264 (ICHL). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"

extern "C" void fn_801CE0A4(void* this_);
extern "C" void fn_8013CB44(s32 handle, void* posPtr, s32 a, s32 b, s32 c);
extern "C" void fn_801CE4BC(void* this_);
extern "C" void fn_801F0E34(void* target, u32 effectId, s32 flag);
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern "C" void* fn_801DAC6C(void);
extern "C" void fn_801DAEAC(void* singleton, s32 id);
extern void* lbl_804A4EE8[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

struct IchlDrawKey {
    s32 a, b;
    IchlDrawKey() { a = -1; b = -1; }
};
struct IchlDrawParam {
    u8 map[16];      // 0x00
    IchlDrawKey key; // 0x10
    void* c;         // 0x18
    u8 palette;      // 0x1c
    u8 color;        // 0x1d
    u8 f1e, f1f, f20, f21, f22, f23, f24, f25, f26;
    s32 blend;       // 0x28
    u8 f2c, f2d, f2e;
    s32 g;           // 0x30
    s32 h;           // 0x34
    s32 i;           // 0x38

    IchlDrawParam() {
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
struct IchlVec2 {
    f32 x, y;
};
struct IchlVec3 {
    f32 x, y, z;
};
extern const char lbl_80469AA4[];
extern const f32 lbl_8053F2E0;
extern const f32 lbl_8053F2E4;
extern const f32 lbl_8053F2E8;
extern const f32 lbl_8053F2EC;
extern const f32 lbl_8053F2F0;
extern "C" void fn_801F02BC(void* this_, const char* name, s32 id, IchlDrawParam* param, s32 a, s32 b, s32 c, f32 s0, f32 s1);
extern "C" u8 fn_801F2740(void* this_, s32 id);
extern "C" void fn_801F3128(void* this_, IchlVec2* out);
extern "C" u8 fn_801F329C(void* this_, s32 i);
extern "C" void fn_801CD0D0(IchlVec3* in, IchlVec3* out);
extern "C" void fn_80238548(s32 i, s32 room, IchlVec2* pos, s32 flag);
struct IchlSinCos {
    f32 s, c;
};
namespace JMath { extern IchlSinCos sincosTable_[]; }
static inline void ichlScale(IchlVec2* v, f32 s) {
    v->x *= s;
    v->y *= s;
}
static inline void ichlSet(IchlVec3* v, f32 x, f32 y, f32 z) {
    v->x = x;
    v->y = y;
    v->z = z;
}

extern "C" void fn_801DB18C(char* p) {
    IchlDrawParam param;
    param.palette = 1;
    param.color = 0;
    fn_801F02BC(p, lbl_80469AA4, *(s32*)(p + 0x280) + 0xe3, &param, -1, 0, 0, lbl_8053F2E0, lbl_8053F2E0);
}

extern "C" u8 fn_801DB2C8(char* p) {
    u8 r = 0;
    if (*(f32*)(p + 0x68) - *(f32*)(p + 0x60) > lbl_8053F2E4 &&
        *(f32*)(p + 0x6c) - *(f32*)(p + 0x64) > lbl_8053F2E4) {
        r = fn_801F2740(p, -1);
        if (r) {
            IchlVec2 v;
            IchlVec2 o;
            fn_801F3128(p, &v);
            for (s32 i = 0; i < 4; i++) {
                if (r & (1 << i)) {
                    if (fn_801F329C(p, i)) {
                        IchlVec3 b;
                        IchlVec3 a;
                        a.x = v.x;
                        a.y = v.y;
                        a.z = lbl_8053F2E4;
                        fn_801CD0D0(&a, &b);
                        o.x = b.x;
                        o.y = b.y;
                    } else {
                        o.x = v.x;
                        o.y = v.y;
                    }
                    fn_80238548(i, *(s32*)(p + 0x114), &o, 1);
                }
            }
        }
    }
    return r;
}

extern "C" void fn_801DB3F0(char* p) {
    if (lbl_8053F2E4 != *(f32*)(p + 0x2b4)) {
        if (*(s32*)(p + 0x248) == 0) {
            *(f32*)(p + 0x2b4) *= lbl_8053F2E8;
        } else {
            *(f32*)(p + 0x2b4) *= lbl_8053F2EC;
        }
        if (__fabs(*(f32*)(p + 0x2b4)) < lbl_8053F2F0) {
            *(f32*)(p + 0x2b4) = lbl_8053F2E4;
        }
    }
    if (lbl_8053F2E4 != *(f32*)(p + 0x2b8)) {
        if (*(s32*)(p + 0x248) == 0) {
            *(f32*)(p + 0x2b8) *= lbl_8053F2E8;
        } else {
            *(f32*)(p + 0x2b8) *= lbl_8053F2EC;
        }
        if (__fabs(*(f32*)(p + 0x2b8)) < lbl_8053F2F0) {
            *(f32*)(p + 0x2b8) = lbl_8053F2E4;
        }
    }
    if (*(s32*)(p + 0x248) == 0) {
        ichlSet((IchlVec3*)(p + 0x3c), *(f32*)(p + 0x2b4), *(f32*)(p + 0x2b8), lbl_8053F2E4);
    } else {
        s16 ang = *(s16*)(p + 0x2dc);
        f32 r = *(f32*)(p + 0x2d4);
        f32 bx = *(f32*)(p + 0x2bc);
        f32 by = *(f32*)(p + 0x2c0);
        f32 sx = JMath::sincosTable_[(u16)ang >> 5].s * r;
        f32 sy = JMath::sincosTable_[(u16)ang >> 5].c * r;
        ichlSet((IchlVec3*)(p + 0x3c), (bx + sx) - *(f32*)(p + 0xc), (by + sy) - *(f32*)(p + 0x10), lbl_8053F2E4);
    }
}

extern "C" void fn_801DB51C(void* this_) {
    fn_801CE0A4(this_);
    fn_8013CB44(*(s32*)((char*)this_ + 0x2e4), (char*)this_ + 0xc, 1, 0, 1);
}

extern "C" void fn_801DB560(void* this_) {
    char* p = (char*)this_;
    s32 before = *(s32*)(p + 0x280);
    fn_801CE4BC(this_);
    if (before == 8) {
        if (*(s32*)(p + 0x280) == 7) {
            fn_801F0E34(this_, 0x4005b, 0);
        }
    }
}

extern "C" void* fn_801DBEF4(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A4EE8;
        fn_801EE434(*(void**)(p + 0x2e4));
        *(s32*)(p + 0x2e4) = 0;
        if (*(s32*)(p + 0x16c) == -1) {
            void* singleton = fn_801DAC6C();
            fn_801DAEAC(singleton, *(s32*)(p + 0x198));
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

extern const f32 lbl_8053F33C;
extern const f32 lbl_8053F2F4;
extern const f32 lbl_8053F2F8;
extern "C" void fn_801DB9CC(void* this_);
extern "C" s32 fn_801D05F8(void* this_, void* pos, f32 r);
extern "C" void fn_801D0F40(void* this_);
extern "C" void fn_801CD950(f32* v, f32 target, f32 step);
extern "C" void fn_801CD930(s16* v, s32 target, s32 step);
extern "C" void fn_801DB6C8(void* this_);

extern "C" void fn_801DB950(char* p, s32 state);

extern "C" void fn_801DB5C0(char* p) {
    switch (*(s32*)(p + 0x248)) {
    case 0:
        if (*(s32*)(p + 0x24c) >= *(s32*)(p + 0x250)) {
            fn_801DB950(p, 1);
        }
        break;
    case 1: {
        fn_801CD950((f32*)(p + 0x2d4), *(f32*)(p + 0x2d8), lbl_8053F2E0);
        fn_801CD950((f32*)(p + 0x2e0), lbl_8053F2F4, lbl_8053F2F8);
        if (*(s16*)(p + 0x2de) != 0x200) {
            s32 step = 0x20;
            if (*(s16*)(p + 0x2de) > 0x200) {
                step = 0x800;
            }
            fn_801CD930((s16*)(p + 0x2de), 0x200, step);
        }
        s32 r = fn_801D05F8(p, p + 0x2bc, *(f32*)(p + 0x2b0));
        if (r == -1) {
            *(s32*)(p + 0x2a8) = -1;
            *(s32*)(p + 0x2ac) = 0;
        } else {
            (*(u32*)(p + 0x2ac))++;
            if (*(s32*)(p + 0x2a8) != r && *(u32*)(p + 0x2ac) >= 0x5a) {
                *(s32*)(p + 0x2a8) = r;
                *(s32*)(p + 0x2ac) = 0;
            }
        }
        fn_801DB6C8(p);
        break;
    }
    }
}

extern "C" void fn_801DB950(char* p, s32 state) {
    switch (state) {
    case 1:
        *(s32*)(p + 0x250) = -1;
        *(f32*)(p + 0x2a0) = lbl_8053F2E0;
        *(s32*)(p + 0x2ac) = 0;
        fn_801DB9CC(p);
        *(s32*)(p + 0x2a8) = fn_801D05F8(p, p + 0x2bc, *(f32*)(p + 0x2b0));
        break;
    }
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x248) = state;
}

extern "C" char* fn_801DBFB0(char* p) {
    fn_801D0F40(p);
    *(void**)p = lbl_804A4EE8;
    *(s32*)(p + 0x2a8) = -1;
    *(s32*)(p + 0x2ac) = 0;
    *(f32*)(p + 0x2b0) = lbl_8053F2E4;
    *(f32*)(p + 0x2b4) = lbl_8053F2E4;
    *(f32*)(p + 0x2b8) = lbl_8053F2E4;
    *(f32*)(p + 0x2bc) = lbl_8053F2E4;
    *(f32*)(p + 0x2c0) = lbl_8053F2E4;
    *(f32*)(p + 0x2c4) = lbl_8053F2E4;
    *(f32*)(p + 0x2c8) = lbl_8053F2E4;
    *(f32*)(p + 0x2cc) = lbl_8053F2E4;
    *(f32*)(p + 0x2d0) = lbl_8053F2E4;
    *(f32*)(p + 0x2d4) = lbl_8053F33C;
    *(f32*)(p + 0x2d8) = lbl_8053F33C;
    *(s16*)(p + 0x2dc) = 0;
    *(s16*)(p + 0x2de) = 0;
    *(f32*)(p + 0x2e0) = lbl_8053F2E4;
    *(s32*)(p + 0x2e4) = 0;
    return p;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
