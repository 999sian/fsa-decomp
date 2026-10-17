// TU 0x8021d734-0x8021f064 (actor NAVI).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"
#include "JSystem/JMath/JMath.h"

// ---- fn_8021ED04_dtor.cpp ----
extern "C" void* fn_801EE434(void* handle);
extern "C" void* CompanionRegistry_GetOrInit();
extern "C" void fn_8021F1F0(void* registry, s32 id);
extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_804A6708[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];

extern "C" void* fn_8021ED04(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A6708;
        fn_801EE434(*(void**)(p + 0x2d0));
        fn_801EE434(*(void**)(p + 0x2d4));
        if (*(u32*)(p + 0x230) & 0x4000) {
            void* registry = CompanionRegistry_GetOrInit();
            fn_8021F1F0(registry, *(s32*)(p + 0x198));
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
            dtor_80084580(this_);
        }
    }
    return this_;
}

extern "C" void fn_8021DFAC(void* this_, s32 state);
extern "C" void fn_801CE120(void* this_);
extern "C" void fn_801D0F40(void* this_);
struct NaviVec {
    f32 x, y, z;
    NaviVec(f32 a, f32 b, f32 c) { x = a; y = b; z = c; }
};
extern "C" void fn_8030C210(void* p, NaviVec* v);
extern const f32 lbl_8053FD64;
extern const f32 lbl_8053FD88;
extern const f32 lbl_8053FD58;
extern const f32 lbl_8053FD60;
extern const f32 lbl_8053FD5C;
extern char* lbl_8053AB10;
extern "C" void fn_801D01A0(void* self, f32 speed, void* dir, void* out);
extern int __float_max[];
extern const f32 lbl_8053FD68;
extern const f32 lbl_8053FD6C;
extern const f32 lbl_8053FD70;
extern const f32 lbl_8053FD74;
extern const f32 lbl_8053FD78;
extern const f32 lbl_8053FD7C;

extern "C" void fn_8021D734(char* p) {
    if (*(s32*)(p + 0x248) != 8) {
        fn_8021DFAC(p, 8);
    }
}

extern "C" void fn_8021D764(char* p) {
    if (*(s32*)(p + 0x248) != 6) {
        fn_8021DFAC(p, 6);
    }
}

extern "C" bool fn_8021D794(char* p) {
    return *(s32*)(p + 0x248) == 5;
}

extern "C" void fn_801F02BC(char* this_, char* name, s32 id, u8* buf, s32 flags, s32 a6, s32 a7, f32 a8, f32 a9);
extern s32 lbl_8046A7C0[];
extern char lbl_8046A7D8[];
extern "C" void fn_8021D7A8(char* p) {
    u8 buf[0x40];

    if (*(s32*)(p + 0x248) != 3 && *(f32*)(p + 0x2b8) > lbl_8053FD58) {
        *(s32*)(buf + 0x10) = -1;
        *(s32*)(buf + 0x14) = -1;

        for (s32 i = 0; (u8)i < 16; i += 8) {
            buf[(u8)(i)] = i;
            buf[(u8)(i + 1)] = i + 1;
            buf[(u8)(i + 2)] = i + 2;
            buf[(u8)(i + 3)] = i + 3;
            buf[(u8)(i + 4)] = i + 4;
            buf[(u8)(i + 5)] = i + 5;
            buf[(u8)(i + 6)] = i + 6;
            buf[(u8)(i + 7)] = i + 7;
        }

        *(s32*)(buf + 0x10) = -1;
        *(s32*)(buf + 0x14) = 0;
        *(s32*)(buf + 0x18) = 0;
        buf[0x1c] = 0;
        buf[0x1d] = 0;
        buf[0x1e] = 0;
        buf[0x1f] = 1;
        buf[0x20] = 1;
        buf[0x21] = 0;
        buf[0x22] = 0;
        buf[0x23] = 0;
        buf[0x24] = 0;
        buf[0x25] = 0;
        buf[0x26] = 1;
        *(s32*)(buf + 0x28) = 3;
        buf[0x2c] = 1;
        buf[0x2d] = 0;
        buf[0x2e] = 0;
        *(s32*)(buf + 0x30) = -1;
        *(s32*)(buf + 0x34) = 0;
        *(s32*)(buf + 0x38) = 2;
        buf[0x13] = (s32)*(f32*)(p + 0x2b8);
        u8 flag = 0;
        if (*(s32*)(p + 0x248) == 9) {
            flag = 1;
        }
        buf[0x20] = flag;

        fn_801F02BC(p, lbl_8046A7D8, lbl_8046A7C0[*(u8*)(p + 0x2ac)] + *(s32*)(p + 0x280), buf, 0x407, 0, 0, lbl_8053FD5C, lbl_8053FD5C);
    }
}

extern "C" void fn_8021D938(char* p) {
    if (*(s32*)(p + 0x248) != 3) {
        u32 fl = *(u32*)(p + 0x230);
        if ((fl & 0x2000) && !(fl & 0x40000)) {
            u8* q = *(u8**)(lbl_8053AB10 + 0x30);
            if (q[0x284] == 0) {
                q[0x284] = 1;
                *(f32*)(q + 0x28c) = lbl_8053FD60;
            }
        }
        if (!(*(u32*)(p + 0x230) & 0x10000)) {
            NaviVec v(*(f32*)(p + 0x2c8), *(f32*)(p + 0x2cc) - *(f32*)(p + 0x14), lbl_8053FD58);
            fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), &v);
        }
    }
}

extern "C" void fn_8021D9D4(char* p) {
    fn_801CE120(p);
    if (*(s32*)(p + 0x248) == 9) {
        if (*(f32*)(p + 0x14) > lbl_8053FD64) {
            *(f32*)(p + 0x14) = lbl_8053FD64;
        }
    }
}

extern "C" void fn_8021DA20(char* p) {
    f32 v[2];
    *(f32*)(p + 0x3c) = lbl_8053FD58;
    *(f32*)(p + 0x40) = lbl_8053FD58;
    *(f32*)(p + 0x44) = lbl_8053FD58;
    switch (*(s32*)(p + 0x248)) {
    case 4:
        *(f32*)(p + 0x44) = lbl_8053FD68;
        break;
    case 7:
        *(f32*)(p + 0x44) = lbl_8053FD6C;
        break;
    case 9:
        *(f32*)(p + 0x44) = lbl_8053FD70;
        break;
    }
    switch (*(s32*)(p + 0x248)) {
    case 4:
    case 7:
        fn_801D01A0(p, *(f32*)__float_max, p + 0x2c0, v);
        *(f32*)(p + 0x3c) = v[0];
        *(f32*)(p + 0x40) = v[1];
        break;
    case 10:
        *(f32*)(p + 0x3c) = lbl_8053FD74;
        *(f32*)(p + 0x40) = lbl_8053FD78;
        break;
    case 9:
        *(f32*)(p + 0x40) = lbl_8053FD7C;
        break;
    }
}

extern "C" void fn_801CE0A4(void* this_);
extern "C" void fn_8013CB44(void* obj, void* pos, s32 a, s32 b, s32 c);
extern const f32 lbl_8053FD80;
extern const f32 lbl_8053FD84;
extern const f32 lbl_8053FD5C;
extern "C" void fn_8021DB24(char* p) {
    f32 f;
    s32 flag;
    fn_801CE0A4(p);
    if (*(s32*)(p + 0x248) == 9) {
        f = *(f32*)(p + 0x14) - lbl_8053FD80;
        f = f * lbl_8053FD84;
        if (f > lbl_8053FD5C) {
            f = lbl_8053FD5C;
        } else if (f < lbl_8053FD58) {
            f = lbl_8053FD58;
        }
        *(f32*)(p + 0x2b8) = lbl_8053FD88 * f;
    } else {
        *(f32*)(p + 0x2b8) = lbl_8053FD88;
    }
    flag = 0;
    if (*(s32*)(p + 0x248) == 9) {
        flag = 1;
    }
    fn_8013CB44(*(void**)(p + 0x2d0), p + 0xc, 0, -1, flag);
    flag = 0;
    if (*(s32*)(p + 0x248) == 9) {
        flag = 1;
    }
    fn_8013CB44(*(void**)(p + 0x2d4), p + 0xc, 0, -1, flag);
    if (*(void**)(p + 0x2d0) != 0) {
        *(char*)(*(char**)(p + 0x2d0) + 0xbb) = (char)(s32)*(f32*)(p + 0x2b8);
    }
    if (*(void**)(p + 0x2d4) != 0) {
        *(char*)(*(char**)(p + 0x2d4) + 0xbb) = (char)(s32)*(f32*)(p + 0x2b8);
    }
}

extern const f32 lbl_8053FD8C;
extern const f32 lbl_8053FD90;
extern "C" s32 fn_801CCE3C(void* a, void* b);
extern "C" s32 fn_801D05F8(char* p, void* pos, f32 scale);
extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802D800C(void* mgr, s32 kind);
extern "C" u8 fn_8023077C(void);
extern "C" void fn_80230534(s32 a);
extern "C" void fn_8021E4F8(char* p);
extern "C" void* fn_8023E724(s32 i);
extern "C" void fn_801CD8E4(void* p, f32 a, f32 b, f32 c);
extern "C" void fn_801CD754(void* p, f32 a, f32 b, void* v, f32 c);
extern int __float_epsilon[];
extern const f32 lbl_8053FDA0;
extern const f32 lbl_8053FDA4;
extern const f32 lbl_8053FDA8;
extern const f32 lbl_8053FDAC;
extern const f32 lbl_8053FDB0;
extern const f32 lbl_8053FDB4;
extern const f32 lbl_8053FDB8;
extern const f32 lbl_8053FDBC;

static inline f32 navi_invsqrt(f32 x) {
    if (x <= 0.0f) {
        return x;
    }
    f32 y = __frsqrte(x);
    y = 0.5f * y * (3.0f - (x * (y * y)));
    return y;
}

static inline f32 navi_sqrt(f32 x) {
    if (x <= 0.0f) {
        return x;
    }
    f32 y = __frsqrte(x);
    y = 0.5f * y * (3.0f - (x * (y * y)));
    return x * y;
}
extern "C" u16* fn_8021F064(void);
extern "C" u8 fn_8021F094(void);
extern "C" void fn_8022FE80(s32 a, void* b, void* c, s32 d, s32 e);
extern "C" s32 fn_8022FD8C(void* a);
extern "C" u8 fn_8038C678(s32 a, s32 b, s32 c, s32 d, void* e, s32 f);
extern "C" u8 fn_803865B8(s32 a);
extern "C" u8 fn_80384C58(s32 a, void* b);
extern "C" void fn_8021DC44(char* p) {
    switch (*(s32*)(p + 0x248)) {
    case 0:
        if (*(s32*)(p + 0x24c) >= 5) {
            fn_8021DFAC(p, 1);
        }
        break;
    case 1:
        if (*(s32*)(p + 0x24c) >= 0x2d) {
            fn_8021DFAC(p, 2);
        }
        break;
    case 2:
        if (*(s32*)(p + 0x24c) < 0x2d) {
            break;
        }
        *(s32*)(p + 0x2b4) = fn_801CCE3C(p + 0xc, *(void**)(p + 0x4));
        if (*(s32*)(p + 0x2b4) < 0) {
            *(s32*)(p + 0x2b4) = 0;
            fn_8021DFAC(p, 5);
            break;
        }
    case 3: {
        *(s32*)(p + 0x2b4) = fn_801D05F8(p, p + 0xc, lbl_8053FD8C * (f32)*(u8*)(p + 0x2ad));
        if (*(s32*)(p + 0x2b4) < 0) {
            break;
        }
        s32 r29 = *(s32*)(p + 0x2b0);
        u8 flag = 0;
        if (r29 == 0) {
            flag = 1;
        } else if (fn_802D800C(fn_802D6A9C(), r29)) {
            flag = 1;
        }
        if (flag && fn_8023077C()) {
            fn_8021DFAC(p, 4);
        }
        break;
    }
    case 4:
        if (*(s32*)(p + 0x24c) >= 0x78) {
            fn_8021DFAC(p, 5);
        } else {
            fn_8021E4F8(p);
        }
        break;
    case 5: {
        f32 v[3];
        if (!(*(u32*)(p + 0x230) & 0x2000)) {
            break;
        }
        if (*(u32*)(p + 0x230) & 0x4000) {
            fn_8021F064();
            if (!fn_8021F094()) {
                break;
            }
        }
        fn_8022FE80(*(s32*)(p + 0x2b4), *(void**)(p + 0x4), *(void**)(p + 0x198), 0, 0);
        if (*(s32*)(p + 0x2b4) != fn_8022FD8C(*(void**)(p + 0x198))) {
            break;
        }
        v[0] = lbl_8053FD58;
        v[1] = lbl_8053FD90;
        v[2] = lbl_8053FD58;
        if (!fn_8038C678(*(s32*)(p + 0x2b4), *(s32*)(p + 0x2a8), *(s32*)(p + 0x198), *(s32*)(p + 0x4), v, 0x4002)) {
            break;
        }
        if (*(u32*)(p + 0x230) & 0x4000) {
            u16* q = fn_8021F064();
            *q |= 1;
        } else {
            fn_8021DFAC(p, 6);
        }
        break;
    }
    case 6:
        if (!(*(u32*)(p + 0x230) & 0x2000)) {
            break;
        }
        fn_8022FE80(*(s32*)(p + 0x2b4), *(void**)(p + 0x4), *(void**)(p + 0x198), 0, 0);
        if (!fn_803865B8(*(s32*)(p + 0x2b4))) {
            break;
        }
        if (!fn_80384C58(*(s32*)(p + 0x2b4), *(void**)(p + 0x198))) {
            break;
        }
        if (*(u32*)(p + 0x230) & 0x4000) {
            u16* q = fn_8021F064();
            *q |= 2;
        } else if (*(u32*)(p + 0x230) & 0x8000) {
            fn_8021DFAC(p, 10);
        } else {
            fn_8021DFAC(p, 7);
        }
        break;
    case 7:
        if (*(s32*)(p + 0x24c) >= 0x78) {
            fn_8021DFAC(p, 3);
        } else {
            fn_8021E4F8(p);
        }
        break;
    case 10:
        if (*(s32*)(p + 0x24c) >= 0xf0) {
            fn_8021DFAC(p, 3);
            break;
        }
        if (*(s32*)(p + 0x24c) != 0x78) {
            break;
        }
        if (*(u32*)(p + 0x230) & 0x40000) {
            break;
        }
        if (*(u32*)(p + 0x230) & 0x2000) {
            fn_80230534(0);
            *(u32*)(p + 0x230) |= 0x40000;
        }
        break;
    case 8:
        if (*(s32*)(p + 0x24c) >= *(s32*)(p + 0x250)) {
            fn_8021DFAC(p, 9);
        }
        break;
    case 9:
        if (*(f32*)(p + 0x14) >= lbl_8053FD64) {
            fn_8021DFAC(p, 3);
        }
        break;
    }
}

extern "C" void* fn_8021EDC0(char* p) {
    fn_801D0F40(p);
    *(void**)p = lbl_804A6708;
    *(s32*)(p + 0x2a8) = 0;
    p[0x2ac] = 0;
    p[0x2ad] = 0;
    *(s32*)(p + 0x2b0) = 0;
    *(s32*)(p + 0x2b4) = -1;
    *(f32*)(p + 0x2b8) = lbl_8053FD88;
    *(f32*)(p + 0x2bc) = lbl_8053FD58;
    *(f32*)(p + 0x2c0) = lbl_8053FD58;
    *(f32*)(p + 0x2c4) = lbl_8053FD58;
    *(f32*)(p + 0x2c8) = lbl_8053FD58;
    *(f32*)(p + 0x2cc) = lbl_8053FD58;
    *(s32*)(p + 0x2d0) = 0;
    *(s32*)(p + 0x2d4) = 0;
    return p;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
