// TU 0x8021d734-0x8021f064 (actor NAVI).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "types.h"
#include "JSystem/JMath/JMath.h"
#include "JSystem/JParticle/JPAEmitter.h"

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
        switch (*(s32*)(p + 0x248)) {
        case 9:
            flag = 1;
            break;
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
        register f32 v = *(f32*)(p + 0x14);
        if (v > lbl_8053FD64) {
            *(f32*)(p + 0x14) = v;
            v = lbl_8053FD64;
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
        f32 t = *(f32*)(p + 0x14) - lbl_8053FD80;
        f = t * lbl_8053FD84;
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
    switch (*(s32*)(p + 0x248)) {
    case 9:
        flag = 1;
        break;
    default:
        break;
    }
    fn_8013CB44(*(void**)(p + 0x2d0), p + 0xc, 0, -1, flag);
    flag = 0;
    switch (*(s32*)(p + 0x248)) {
    case 9:
        flag = 1;
        break;
    default:
        break;
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
        u8 flag = 0;
        s32 r29 = *(s32*)(p + 0x2b0);
        if (r29 != 0) {
            if (fn_802D800C(fn_802D6A9C(), r29)) {
                flag = 1;
            }
        } else {
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

extern "C" void fn_8021E4F8(char* p) {
    switch (*(s32*)(p + 0x248)) {
    case 4: {
        f32 t = (f32)(0x78 - *(s32*)(p + 0x24c));
        if (t < *(f32*)__float_epsilon) {
            *(f32*)(p + 0x2bc) = lbl_8053FDA0;
        } else {
            *(f32*)(p + 0x2bc) = *(f32*)(p + 0x2bc) + (lbl_8053FD5C / t) * (lbl_8053FDA0 - *(f32*)(p + 0x2bc));
        }
        break;
    }
    case 7: {
        f32 t = (f32)(0x78 - *(s32*)(p + 0x24c));
        if (t < *(f32*)__float_epsilon) {
            *(f32*)(p + 0x2bc) = lbl_8053FD5C;
        } else {
            *(f32*)(p + 0x2bc) = *(f32*)(p + 0x2bc) + (lbl_8053FD5C / t) * (lbl_8053FD5C - *(f32*)(p + 0x2bc));
        }
        break;
    }
    }

    f32 dx = *(f32*)(p + 0x2c0) - *(f32*)(p + 0x2c8);
    f32 dz = *(f32*)(p + 0x2c4) - *(f32*)(p + 0x2cc);
    f32 len2 = dx * dx + dz * dz;
    if (len2 > lbl_8053FDA4 * *(f32*)__float_epsilon) {
        f32 inv = navi_invsqrt(len2);
        dx = dx * inv;
        dz = dz * inv;
    }
    dx = dx * *(f32*)(p + 0x2bc);
    dz = dz * *(f32*)(p + 0x2bc);

    u8 flag = 0;
    if (*(s32*)(p + 0x2b4) >= 0 && (*(u32*)(p + 0x230) & 0x30000)) {
        flag = 1;
    }
    f32 tx;
    f32 tz;
    if (flag) {
        f32* q = (f32*)fn_8023E724(*(s32*)(p + 0x2b4));
        tx = q[0];
        tz = q[1];
    } else {
        tx = *(f32*)(p + 0x24);
        tz = *(f32*)(p + 0x28);
    }
    fn_801CD8E4(p + 0x2c8, tx, lbl_8053FD5C, lbl_8053FD58);
    fn_801CD8E4(p + 0x2cc, tz, lbl_8053FD5C, lbl_8053FD58);

    f32 tgt[2];
    tgt[0] = *(f32*)(p + 0x2c8) + dx;
    tgt[1] = *(f32*)(p + 0x2cc) + dz;

    u8 flag2 = 0;
    if (*(s32*)(p + 0x248) == 7) {
        if (*(s32*)(p + 0x2b4) >= 0 && (*(u32*)(p + 0x230) & 0x30000)) {
            flag2 = 1;
        }
    }
    if (flag2) {
        fn_801CD754(p + 0x2c0, lbl_8053FDB0, lbl_8053FD5C, tgt, lbl_8053FDB4);
    } else {
        *(f32*)(p + 0x2c0) = tgt[0];
        *(f32*)(p + 0x2c4) = tgt[1];
    }

    dx = *(f32*)(p + 0x2c0) - *(f32*)(p + 0x2c8);
    dz = *(f32*)(p + 0x2c4) - *(f32*)(p + 0x2cc);
    len2 = dx * dx + dz * dz;
    s32 ang = 0x622;
    f32 len = navi_sqrt(len2);
    if (len > lbl_8053FDB8) {
        s32 v = (s32)((lbl_8053FD5C / len) * (lbl_8053FDBC * *(f32*)(p + 0x2bc)));
        if ((s16)v > 0x622) {
            ang = 0x622;
        } else if ((s16)v < 0x200) {
            ang = 0x200;
        } else {
            ang = v;
        }
    }
    if (*(s32*)(p + 0x248) == 7) {
        ang = -(s16)(-ang);
    }
    f32 sn = JMath::sincosTable_.mTable[(u16)ang >> 5].first;
    f32 cs = JMath::sincosTable_.mTable[(u16)ang >> 5].second;
    f32 cx = *(f32*)(p + 0x2c8);
    f32 cz = *(f32*)(p + 0x2cc);
    *(f32*)(p + 0x2c0) = cx + (dx * cs - dz * sn);
    *(f32*)(p + 0x2c4) = cz + (dx * sn + dz * cs);
}

extern "C" void fn_801D0ED0(char* p);
extern "C" void fn_801D2608(char* anim, u8* arg, s32 n);
extern "C" void fn_801D22DC(char* anim, s32 a, s32 b, s32 c);
extern "C" void fn_801D1D60(char* anim);
extern "C" void* fn_8013CC50(s32 id, void* pos, s32 kind, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale);
extern "C" void GrowableArray_PushBack(void* arr, void* item);
extern "C" void detach__5ActorFv(void* this_);
extern u8 lbl_80529DEC[];
extern u8 lbl_8050EC80[];
extern const u8 lbl_8046A7AC[];
extern u8 lbl_8053A188[1];
extern const f32 lbl_8053FDC8;
struct NaviRGB { u8 r, g, b; };

extern "C" void fn_8021E8D0(char* p) {
    s32 idx;
    s32 x;
    s32 y;
    s32 bit;
    void* e;

    fn_801D0ED0(p);
    *(u32*)(p + 0x2a8) = (*(u32*)(p + 0x90) & 0xffff) + 0x12b;
    idx = (*(u32*)(p + 0x90) >> 0x10) & 7;
    if (idx > 5) {
        idx = 5;
    } else if (idx < 0) {
        idx = 0;
    }
    *(u8*)(p + 0x2ac) = idx;
    if (!((*(u32*)(p + 0x90) >> 0x13) & 1)) {
        *(u32*)(p + 0x230) |= 0x10000;
    }
    *(u8*)(p + 0x2ad) = (*(u32*)(p + 0x90) >> 0x14) & 0x3f;
    if (*(u8*)(p + 0x2ad) < 1) {
        *(u8*)(p + 0x2ad) = 1;
    }
    *(u32*)(p + 0x2b0) = (*(u32*)(p + 0x90) >> 0x1a) & 0x1f;
    u8* tbl = lbl_80529DEC;
    s32 st = *(s32*)(tbl + 0x118);
    if (st == 6 && *(s32*)(tbl + 0x11c) == 0 && (*(u32*)(p + 0x90) >> 31) != 0) {
        *(u32*)(p + 0x230) |= 0x4000;
        if (*(u8*)(p + 0x2ac) == 0) {
            *(u32*)(p + 0x230) |= 0x2000;
        }
    } else if (st == 6 && *(s32*)(lbl_80529DEC + 0x11c) == 1 && (*(u32*)(p + 0x90) >> 31) != 0) {
        *(u32*)(p + 0x230) |= 0xa000;
        *(u32*)(p + 0x230) &= 0xfffeffff;
    } else {
        *(u32*)(p + 0x230) |= 0x2000;
    }
    if ((*(u32*)(p + 0x90) >> 31) != 0 && *(s32*)(lbl_80529DEC + 0x11c) == 0) {
        switch (*(s32*)(tbl + 0x118)) {
        case 1: case 2: case 3: case 4: case 5: case 6:
            *(u32*)(p + 0x230) |= 0x20000;
            *(u32*)(p + 0x230) &= 0xfffeffff;
            break;
        default: break;
        }
    }
    *(f32*)(p + 0x60) = lbl_8053FD5C;
    *(f32*)(p + 0x64) = lbl_8053FD5C;
    *(f32*)(p + 0x68) = lbl_8053FDC8;
    *(f32*)(p + 0x6c) = lbl_8053FDC8;
    *(f32*)(p + 0x70) = *(f32*)(p + 0x60);
    *(f32*)(p + 0x74) = *(f32*)(p + 0x64);
    *(f32*)(p + 0x78) = *(f32*)(p + 0x68);
    *(f32*)(p + 0x7c) = *(f32*)(p + 0x6c);
    *(f32*)(p + 0x80) = lbl_8053FD5C;
    *(f32*)(p + 0x84) = lbl_8053FD5C;
    *(f32*)(p + 0x88) = lbl_8053FDC8;
    *(f32*)(p + 0x8c) = lbl_8053FDC8;
    *(u32*)(p + 0xb0) = 0;
    *(u32*)(p + 0x98) = 2;
    *(u32*)(p + 0x230) |= 0x380;
    *(u32*)(p + 0x108) = 1000;
    *(u32*)(p + 0x244) = *(u32*)(p + 0x108);
    *(u8*)(p + 0x194) = 1;
    if (*(u32*)(p + 0x230) & 0x20000) {
        *(f32*)(p + 0x14) = lbl_8053FDA0;
    }
    *(f32*)(p + 0x2c8) = *(f32*)(p + 0xc);
    *(f32*)(p + 0x2cc) = *(f32*)(p + 0x10);
    if (*(u32*)(p + 0x230) & 0x20000) {
        *(u32*)(p + 0x248) = 0;
    } else {
        *(u32*)(p + 0x248) = 3;
    }
    *(void**)(p + 0x24c) = 0;
    *(s32*)(p + 0x250) = -1;
    *(f32*)(p + 0x254) = lbl_8053FD58;
    *(f32*)(p + 0x258) = lbl_8053FD58;
    fn_801D2608(p + 0x270, lbl_8053A188, 1);
    fn_801D22DC(p + 0x270, 0, 2, 0);
    fn_801D1D60(p + 0x270);
    if (*(u32*)(p + 0x230) & 0x4000) {
        GrowableArray_PushBack(fn_8021F064(), *(void**)(p + 0x198));
    }
    if (((u8*)fn_802D6A9C())[0x131f9] == 2) {
        detach__5ActorFv(p);
    } else if (*(u32*)(p + 0x230) & 0x20000) {
        x = *(s32*)(tbl + 0x118);
        y = *(s32*)(lbl_80529DEC + 0x11c);
        if (x < 0 || x > 7) {
            bit = 0;
        } else if (y < 0 || y > 3) {
            bit = 0;
        } else {
            u8* saves = lbl_8050EC80;
            u32 mask = 1u << (y + x * 4);
            s32 slot = *(s32*)(saves + 0x10);
            bit = mask & *(u32*)(saves + 0x28 + 0xc8 * slot);
            bit = bit != 0;
        }
        if (bit != 0) {
            detach__5ActorFv(p);
        } else {
            s32 state = *(s32*)(p + 0x248);
            s32 f = 0;
            s32 room = *(s32*)(p + 4);
            switch (state) {
            case 9: f = 1; break;
            }
            e = fn_8013CC50(room, p + 0xc, 0x32c, 0, -1, 0, 0, f, lbl_8053FD5C);
            *(void**)(p + 0x2d0) = e;
            f = 0;
            state = *(s32*)(p + 0x248);
            room = *(s32*)(p + 4);
            switch (state) {
            case 9: f = 1; break;
            }
            e = fn_8013CC50(room, p + 0xc, 0x184, 0, -1, 0, 0, f, lbl_8053FD5C);
            *(void**)(p + 0x2d4) = e;
            e = *(void**)(p + 0x2d0);
            if (e != 0) {
                const NaviRGB* colors = (const NaviRGB*)lbl_8046A7AC;
                int i = *(u8*)(p + 0x2ac);
                u8 red = colors[i].r;
                u8 green = colors[i].g;
                ((u8*)e)[0xbc] = red;
                u8 blue = colors[i].b;
                ((u8*)e)[0xbd] = green;
                ((u8*)e)[0xbe] = blue;
            }
        }
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
