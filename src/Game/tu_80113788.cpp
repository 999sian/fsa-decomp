#include "types.h"
#include "Game/SinitPoolChain.h"
#include "JSystem/JGeometry/Vec.h"

extern "C" f32 lbl_8053C67C;
extern "C" const f32 lbl_8053C684;
extern "C" f32 lbl_8053C690;
extern "C" f32 lbl_8053C698;
extern "C" f32 lbl_8053C69C;
extern "C" u16 lbl_804648E8[];
extern "C" u32 lbl_804648F4[];
extern "C" char lbl_8049D820[];
extern "C" char lbl_80464968[];
extern "C" char lbl_8046497C[];
extern "C" void* lbl_8053AAF8;
extern "C" void fn_801EF830(s32 a, void* b, void* c, s32 d, void* e, s32 f, s32 g);
extern "C" void fn_802F86CC(void* a, void* b, void* c, s32 d, void* e, f32 f1, f32 f2);
extern "C" void* fn_8011921C(void);
extern "C" s32 lbl_8046486C[];
extern "C" s32 lbl_8053AF80;
extern "C" void fn_80458F9C(s32, s32);
extern "C" f32 lbl_8053C680;
extern "C" f32 lbl_8053C6B8;
extern "C" f32 lbl_8053C6BC;
extern "C" f32 lbl_8053C6C0;
extern "C" f32 lbl_8053C6C4;
extern "C" f32 lbl_8053C6C8;
extern "C" f32 lbl_8053C6CC;
extern "C" s32 lbl_8053AD30;
extern "C" char lbl_8050EC80[];
extern "C" void fn_8010DF78(void* p);
extern "C" void fn_8030C210(void* p, void* v);
extern "C" void fn_80458FF0(void* a, u32 b, s32 c, s32 d);
extern "C" s32 fn_8023BCD4(s32 i);
extern "C" void* fn_8023E724(s32 i);
extern "C" u16 fn_8023CBC0(s32 i);
extern "C" void fn_80230498(s32 i, void* v, u16 a, u8 b, s32 c, s32 d, s32 e);
extern "C" void* fn_8016A3AC(void);
extern "C" void fn_8013CB44(void* obj, void* p, s32 a, s32 b, s32 c);
extern "C" void fn_801CD950(void* p, f32 a, f32 b);
extern "C" void fn_801D1C18(void* p);
extern "C" void fn_8022FE80(s32 a, u32 b, void* c, s32 d, s32 e);
extern "C" u8 fn_803865B8(s32 a);
extern "C" void fn_80388EEC(s32 a);
extern "C" void fn_80387494(s32 a);
extern "C" void fn_801183BC(void);
extern "C" void* fn_80309C4C(void* a, u32 b, s32 c);
extern "C" void fn_801F0E34(void* a, u32 b, u32 c);
extern "C" s32 fn_8013CC50(void* obj, void* v, u16 a, s32 b, f32 c, u32 d, s32 e, s32 f, s32 g);

static inline BOOL stateEventFlag(s32 index) {
    if (index < 0 || index > 7) return FALSE;
    u32 mask = 1u << (index * 4 + 3);
    char* base = lbl_8050EC80;
    return (*(u32*)(base + *(s32*)(base + 0x10) * 0xc8 + 0x28) & mask) != 0;
}

static inline u8 stateRequestFlag(s32 index) {
    u8 result;
    if (!stateEventFlag(index)) {
        result = 0;
    } else {
        if (fn_80309C4C((void*)lbl_8053AD30, 0x1000, -1) != 0) result = 1;
        else result = 0;
    }
    return result;
}

struct StateActor80113788 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void setState(s32 state);
};

static inline void CallVfn24(char* obj, s32 arg) {
    (*(void (***)(char*, s32))obj)[24](obj, arg);
}

struct SpriteResources_80113B54 {
    virtual void v0(); virtual void v1(); virtual void v2();
    virtual void v3();
    virtual void* v6(u32, void*);
};

struct Vec3_80113B54 {
    f32 x;
    f32 y;
    f32 z;
};

struct Vec2_80113B54 {
    f32 x, y;
};

struct Vec3xy_80113B54 {
    Vec2_80113B54 xy;
    f32 z;
};

struct Mtx34_8011395C {
    float m[3][4];
};

union EffWord {
    u32 w;
    u8 b[4];
};

struct EffArgs {
    u8 order[0x10];
    EffWord f10;
    EffWord f14;
    void* ptr;
    u8 b1c;
    u8 b1d;
    u8 b1e;
    u8 b1f;
    u8 b20;
    u8 b21;
    u8 b22;
    u8 b23;
    u8 b24;
    u8 b25;
    u8 b26;
    u8 pad27;
    u32 w28;
    u8 b2c;
    u8 b2d;
    u8 b2e;
    u8 pad2f;
    s32 x30;
    s32 x34;
    s32 x38;
};

// Keep regional definitions that were present before source-tree consolidation.
#if defined(VERSION_G4SP01) || defined(VERSION_G4SE01)
extern "C" int fn_80113788(char* self) {
    return *(int*)(self + 0x23c);
}

extern "C" void PSMTXTrans(f32 mtx[3][4], f32 x, f32 y, f32 z);
extern "C" void fn_802F745C(void* a, void* b, s32 c, void* d);
extern "C" void* lbl_8053AB10;
extern "C" f32 lbl_8053C6A0;
extern "C" void fn_80113790(char* self) {
    JGeometry::TVec3<f32> vec;
    u8 buf[0x40];
    f32 mtx[3][4];
    s32 i;

    if (*(s32*)(self + 0x248) > 0) {
        *(s32*)(buf + 0x10) = -1;
        *(s32*)(buf + 0x14) = -1;
        for (i = 0; (u8)i < 0x10; i += 8) {
            buf[(u8)i] = i;
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
        PSMTXTrans(mtx, lbl_8053C69C, lbl_8053C69C, lbl_8053C69C);
        mtx[0][0] = lbl_8053C6A0;
        mtx[0][1] = lbl_8053C69C;
        mtx[0][2] = lbl_8053C69C;
        mtx[1][0] = lbl_8053C69C;
        mtx[1][1] = lbl_8053C690;
        mtx[1][2] = lbl_8053C69C;
        mtx[2][0] = lbl_8053C69C;
        mtx[2][1] = lbl_8053C69C;
        mtx[2][2] = lbl_8053C6A0;
        buf[0x14] = 0;
        buf[0x15] = 0;
        buf[0x16] = 0;
        buf[0x17] = *(s32*)(self + 0x248);
        *(f32(**)[4])(buf + 0x18) = mtx;
        *(s8*)(buf + 0x1d) = -1;
        buf[0x2d] = 1;
        vec = *(JGeometry::TVec3<f32>*)(self + 0xc);
        vec.z = lbl_8053C69C;
        if (*(s32*)(self + 4) < 8) {
            fn_802F745C(*(void**)((u8*)lbl_8053AB10 + 0x20), &vec, *(s32*)(self + 0x260), buf);
        }
    }
}

extern "C" void fn_8010F668(float m[3][4], float* v, float s);
extern "C" char* fn_801902C0(void);
extern int lbl_804647C8[];
extern float lbl_8053C690;
extern float lbl_8053C694;
extern float lbl_8053C69C;
extern float lbl_8053C6A4;
extern float lbl_8053C6A8;
extern "C" void fn_8011395C(char* self) {
    char* tbl = (char*)lbl_804647C8;
    Mtx34_8011395C mtx;
    Mtx34_8011395C rot;
    float v0[3];
    float v1[3];
    PSMTXTrans(mtx.m, *(float*)(self + 0xc), *(float*)(self + 0x10), *(float*)(self + 0x14));
    v0[0] = lbl_8053C690;
    v0[1] = lbl_8053C69C;
    v0[2] = lbl_8053C69C;
    fn_8010F668(mtx.m, v0, lbl_8053C6A4);
    rot.m[2][3] = lbl_8053C69C; rot.m[1][3] = lbl_8053C69C; rot.m[0][3] = lbl_8053C69C;
    rot.m[2][2] = lbl_8053C69C; rot.m[1][2] = lbl_8053C69C; rot.m[0][2] = lbl_8053C69C;
    rot.m[2][1] = lbl_8053C69C; rot.m[1][1] = lbl_8053C69C; rot.m[0][1] = lbl_8053C69C;
    rot.m[2][0] = lbl_8053C69C; rot.m[1][0] = lbl_8053C69C; rot.m[0][0] = lbl_8053C69C;
    v1[0] = lbl_8053C69C;
    v1[1] = lbl_8053C69C;
    v1[2] = lbl_8053C690;
    fn_8010F668(rot.m, v1, *(float*)(self + 0x258));
    PSMTXConcat(mtx.m, rot.m, mtx.m);
    if (*(u8*)(self + 0x234) != 0) {
        (*(int*)(self + 0x24c))++;
    }
    int* lim = (int*)(tbl + 0xf8);
    switch (*(int*)(self + 0x240)) {
    case 0:
    case 2:
        if (*(int*)(self + 0x24c) >= lim[*(int*)(self + 0x240)]) {
            int* rst = (int*)(tbl + 0xec);
            *(int*)(self + 0x24c) = rst[*(int*)(self + 0x240)];
        }
        break;
    case 1:
        if (*(int*)(self + 0x24c) >= lim[*(int*)(self + 0x240)]) {
            *(int*)(self + 0x240) = 2;
        }
        break;
    }
    int* ids = (int*)(tbl + 0x104);
    int idx = ids[*(int*)(self + 0x238)];
    int cnt = *(int*)(self + 0x24c);
    char* e = fn_801902C0() + idx * 0x60 + 8;
    if (*(void**)(e + 0x3c) != 0 && *(u8*)(e + 0x5c) == 0) {
        *(u8*)(e + 0x5c) = 1;
        *(float*)(e + 0) = lbl_8053C694;
        *(float*)(e + 4) = lbl_8053C694;
        *(float*)(e + 8) = lbl_8053C694;
        PSMTXCopy(mtx.m, (float(*)[4])(e + 0xc));
        *(float*)(e + 0x48) = lbl_8053C6A8;
        *(int*)(e + 0x4c) = cnt;
        *(int*)(e + 0x54) = 0;
        *(int*)(e + 0x58) = 2;
    }
}

#pragma opt_propagation off
static inline void drawSprite_80113B54(char* self, int arg, char* name, void* record) {
    s32 idx;
    void* pos;
    pos = self+0xc;
    idx = arg + *(s32*)(self+0x274);
    if (*(s32*)(self+4) < 8) {
        void* spr = (*(SpriteResources_80113B54**)((char*)lbl_8053AAF8+0xa4))->v6(0x534f4220, name);
        fn_802F86CC(*(void**)((char*)lbl_8053AB10+0x20), pos, spr, idx, record, lbl_8053C690, lbl_8053C690);
    }
}
extern "C" void fn_80113B54(char* self, int arg) {
    JGeometry::TVec3<f32> vec;
    u8 buf50[0x3c];
    u8 buf14[0x3c];
    int i;

    *(s32*)(buf50 + 0x10) = -1;
    *(s32*)(buf50 + 0x14) = -1;
    for (i = 0; (u8)i < 0x10; i += 8) {
        buf50[(u8)i] = i;
        buf50[(u8)(i + 1)] = i + 1;
        buf50[(u8)(i + 2)] = i + 2;
        buf50[(u8)(i + 3)] = i + 3;
        buf50[(u8)(i + 4)] = i + 4;
        buf50[(u8)(i + 5)] = i + 5;
        buf50[(u8)(i + 6)] = i + 6;
        buf50[(u8)(i + 7)] = i + 7;
    }
    *(s32*)(buf50 + 0x10) = -1;
    *(s32*)(buf50 + 0x14) = 0;
    *(s32*)(buf50 + 0x18) = 0;
    buf50[0x1c] = 0;
    buf50[0x1d] = 0;
    buf50[0x1e] = 0;
    buf50[0x1f] = 1;
    buf50[0x20] = 1;
    buf50[0x21] = 0;
    buf50[0x22] = 0;
    buf50[0x23] = 0;
    buf50[0x24] = 0;
    buf50[0x25] = 0;
    buf50[0x26] = 1;
    *(s32*)(buf50 + 0x28) = 3;
    buf50[0x2c] = 1;
    buf50[0x2d] = 0;
    buf50[0x2e] = 0;
    *(s32*)(buf50 + 0x30) = -1;
    *(s32*)(buf50 + 0x34) = 0;
    *(s32*)(buf50 + 0x38) = 2;
    *(s32*)(buf14 + 0x10) = -1;
    *(s32*)(buf14 + 0x14) = -1;

    for (i = 0; (u8)i < 0x10; i += 8) {
        buf14[(u8)i] = i;
        buf14[(u8)(i + 1)] = i + 1;
        buf14[(u8)(i + 2)] = i + 2;
        buf14[(u8)(i + 3)] = i + 3;
        buf14[(u8)(i + 4)] = i + 4;
        buf14[(u8)(i + 5)] = i + 5;
        buf14[(u8)(i + 6)] = i + 6;
        buf14[(u8)(i + 7)] = i + 7;
    }
    *(s32*)(buf14 + 0x10) = -1;
    *(s32*)(buf14 + 0x14) = 0;
    *(s32*)(buf14 + 0x18) = 0;
    buf14[0x1c] = 0;
    buf14[0x1d] = 0;
    buf14[0x1e] = 0;
    buf14[0x1f] = 1;
    buf14[0x20] = 1;
    buf14[0x21] = 0;
    buf14[0x22] = 0;
    buf14[0x23] = 0;
    buf14[0x24] = 0;
    buf14[0x25] = 0;
    buf14[0x26] = 1;
    *(s32*)(buf14 + 0x28) = 3;
    buf14[0x2c] = 1;
    buf14[0x2d] = 0;
    buf14[0x2e] = 0;
    *(s32*)(buf14 + 0x30) = -1;
    *(s32*)(buf14 + 0x34) = 0;
    *(s32*)(buf14 + 0x38) = 2;

    vec = *(JGeometry::TVec3<f32>*)(self + 0xc);
    vec.y = *(f32*)(self + 0x28);

    if (arg == 0x1d6) {
        fn_801EF830(*(s32*)(self + 4), &vec, buf14, 7, lbl_80464968, arg + *(s32*)(self + 0x274), 0);
        drawSprite_80113B54(self, arg, lbl_80464968, buf50);    } else {
        fn_801EF830(*(s32*)(self + 4), &vec, buf14, 7, lbl_8046497C, arg + *(s32*)(self + 0x274), 0);
        drawSprite_80113B54(self, arg, lbl_8046497C, buf50);    }
}
#pragma opt_propagation on
#if defined(VERSION_G4SE01)
extern "C" int fn_80113E98(char* self) {
    switch (*(int*)(self + 0x23c)) {
    case 10:
    case 0x11:
        return 1;
    }
    return 0;
}

extern "C" void fn_80113EC4(char* self, s32 state) {
    switch (state) {
    default:
        break;
    }
}

extern "C" void fn_80114860(char* this_) {
    s32 v = *(s32*)((u8*)fn_8011921C() + 8);
    switch (*(s32*)(this_ + 0x238)) {
    case 0: {
        if (v == lbl_8046486C[2]) {
            ((StateActor80113788*)this_)->setState(2);
        } else if (v == lbl_8046486C[3]) {
            ((StateActor80113788*)this_)->setState(3);
        } else if (v == lbl_8046486C[4]) {
            ((StateActor80113788*)this_)->setState(4);
        } else if (v == lbl_8046486C[5]) {
            ((StateActor80113788*)this_)->setState(5);
        } else if (v == lbl_8046486C[6]) {
            ((StateActor80113788*)this_)->setState(6);
        } else if (v == lbl_8046486C[7]) {
            ((StateActor80113788*)this_)->setState(7);
        } else if (v == lbl_8046486C[9]) {
            ((StateActor80113788*)this_)->setState(9);
        } else if (v == lbl_8046486C[11]) {
            ((StateActor80113788*)this_)->setState(11);
        } else if (v == lbl_8046486C[12]) {
            ((StateActor80113788*)this_)->setState(12);
        } else if (v == lbl_8046486C[13]) {
            ((StateActor80113788*)this_)->setState(13);
        } else if (v == lbl_8046486C[14]) {
            ((StateActor80113788*)this_)->setState(14);
        } else if (v == lbl_8046486C[15]) {
            ((StateActor80113788*)this_)->setState(15);
        } else if (v == lbl_8046486C[16]) {
            ((StateActor80113788*)this_)->setState(16);
        } else if (v == lbl_8046486C[17]) {
            ((StateActor80113788*)this_)->setState(17);
        }
    }
    break;
    default: {
        if (v == lbl_8046486C[2]) {
            ((StateActor80113788*)this_)->setState(2);
        } else if (v == lbl_8046486C[3]) {
            ((StateActor80113788*)this_)->setState(3);
        } else if (v == lbl_8046486C[4]) {
            ((StateActor80113788*)this_)->setState(4);
        } else if (v == lbl_8046486C[5]) {
            ((StateActor80113788*)this_)->setState(5);
        } else if (v == lbl_8046486C[6]) {
            ((StateActor80113788*)this_)->setState(6);
        } else if (v == lbl_8046486C[7]) {
            ((StateActor80113788*)this_)->setState(7);
        } else if (v == lbl_8046486C[9]) {
            ((StateActor80113788*)this_)->setState(9);
        } else if (v == lbl_8046486C[10]) {
            ((StateActor80113788*)this_)->setState(10);
        }
    }
    break;
    }
}

#endif

extern "C" void fn_8010DF58(char*);
extern "C" void fn_80113790(char*);
extern "C" void fn_80113B54(char*, int);
extern int lbl_80464830[];
extern "C" void fn_80114C1C(char* self) {
    fn_8010DF58(self);
    fn_80113790(self);
    switch (*(int*)(self + 0x23c)) {
    case 0x10:
        fn_80113B54(self, 0x1d6);
        break;
    default:
        if (*(unsigned char*)(self + 0x232) != 0) {
            fn_80113B54(self, lbl_80464830[*(int*)(self + 0x238)]);
        }
        break;
    }
}

extern "C" void fn_80114C98(char* self) {
    JGeometry::TVec3f player;
    JGeometry::TVec3f second;
    JGeometry::TVec3f first;
    s32 st;
    s32 r27;
    char* q;
    s32 i;
    s32 k;
    char* o;
    fn_8010DF78(self);
    st = *(s32*)(self + 0x23c);
    switch (st) {
    case 0:
    case 1:
    case 10:
    case 0x11:
        break;
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16: {
        first = *(JGeometry::TVec3f*)(self + 0xc);
        first.y = first.y + lbl_8053C67C;
        fn_8030C210(*(void**)((char*)lbl_8053AB10 + 0x24), &first);
        o = *(char**)((char*)lbl_8053AB10 + 0x24);
        if (*(u8*)(o + 0x7f5) == 0) {
            o[0x7f4] = 1;
            *(s32*)(o + 0x7f8) = 4;
            *(f32*)(o + 0x7fc) = first.x;
            *(f32*)(o + 0x800) = first.y;
            *(f32*)(o + 0x804) = first.z;
            o[0x7f6] = 0;
        }
        break;
    }
    default: {
        second = *(JGeometry::TVec3f*)(self + 0xc);
        second.y = second.y + (lbl_8053C680 + ((*(f32*)(self + 0x28) - *(f32*)(self + 0x10)) - lbl_8053C67C));
        fn_8030C210(*(void**)((char*)lbl_8053AB10 + 0x24), &second);
        o = *(char**)((char*)lbl_8053AB10 + 0x24);
        if (*(u8*)(o + 0x7f5) == 0) {
            o[0x7f4] = 1;
            *(s32*)(o + 0x7f8) = 4;
            *(f32*)(o + 0x7fc) = second.x;
            *(f32*)(o + 0x800) = second.y;
            *(f32*)(o + 0x804) = second.z;
            o[0x7f6] = 0;
        }
        break;
    }
    }
    switch (*(s32*)(self + 0x23c)) {
    case 0: {
        fn_80458FF0((void*)lbl_8053AF80, 0x100001b, 0, 0);
        ((StateActor80113788*)self)->setState(1);
        break;
    }
    case 1:
    case 2:
        break;
    case 3: {
        for (i = 0; i < 4; i++) {
            r27 = (u8)fn_8023BCD4(i) - 2;
            if (r27 <= 0x1e) {
                r27 = 0;
            }
            player = *(JGeometry::TVec3f*)fn_8023E724(i);
            fn_80230498(i, &player, (u16)fn_8023CBC0(i), (u8)r27, -0x80, -0x80, 1);
        }
        if (*(s32*)((char*)fn_8011921C() + 8) == 0x1b8) {
            fn_80458F9C(lbl_8053AF80, 0x3c);
        }
        o = (char*)fn_8016A3AC();
        if (*(u8*)(o + 0x1ef) == 0 && *(u32*)(self + 0x2e4) == 0) {
            *(s32*)(self + 0x2e4) = fn_8013CC50(*(void**)(self + 4), self + 0xc, 0x54c, 0, lbl_8053C690, 0, 0, 0, 1);
        }
        break;
    }
    case 4: {
        fn_801CD950(self + 0x25c, lbl_8053C6B8, lbl_8053C6BC);
        fn_801CD950(self + 0x254, lbl_8053C6C0, lbl_8053C6C4);
        *(f32*)(self + 0x10) = *(f32*)(self + 0x10) - *(f32*)(self + 0x254);
        if (*(f32*)(self + 0x10) <= *(f32*)(self + 0x28) - lbl_8053C684) {
            *(f32*)(self + 0x10) = *(f32*)(self + 0x28) - lbl_8053C684;
        }
        *(s32*)(self + 0x248) = *(s32*)(self + 0x248) + 2;
        if (*(s32*)(self + 0x248) >= 0xe1) {
            *(s32*)(self + 0x248) = 0xe1;
        }
        break;
    }
    case 5: {
        if (stateEventFlag(*(s32*)(self + 0x238))) {
            *(u8*)((char*)lbl_8053AAF8 + 0x85) = 2;
        }
        *(s32*)(self + 0x248) = 0xe1;
        if (((u8*)fn_8011921C())[1] == 0) {
            fn_801CD950(self + 0x25c, lbl_8053C69C, lbl_8053C6C8);
        }
        fn_8022FE80(0, *(u32*)(self + 4), *(void**)(self + 0x198), 1, 0);
        if (fn_803865B8(0)) {
            fn_80388EEC(0);
            fn_8011921C();
            fn_801183BC();
            break;
        }
        if (stateRequestFlag(*(s32*)(self + 0x238))) {
            fn_80387494(0);
            fn_8011921C();
            fn_801183BC();
        }
        break;
    }
    case 6: {
        s32 id = *(s32*)((char*)fn_8011921C() + 8);
        switch (id) {
        case 0x43d:
            fn_801F0E34(self, 0x30082, 0);
            break;
        case 0x46a:
            fn_801F0E34(self, 0x30082, 0);
            fn_801F0E34(self, 0x30083, 0);
            break;
        }
        break;
    }
    case 7:
    case 8:
    case 9:
    case 10:
        break;
    case 11:
        fn_801CD950(self + 0x10, *(f32*)(self + 0x28), lbl_8053C6CC);
        break;
    case 12:
        break;
    case 13: {
        fn_8022FE80(0, *(u32*)(self + 4), *(void**)(self + 0x198), 1, 0);
        if (fn_803865B8(0)) {
            fn_80388EEC(0);
            fn_8011921C();
            fn_801183BC();
        }
        break;
    }
    case 14:
    case 15:
        break;
    case 16: {
        q = self;
        for (r27 = 0; r27 < 2; r27++) {
            o = *(char**)(q + 0x2e8);
            if (o != 0) {
                fn_8013CB44(o, self + 0xc, 0, 0, 1);
                o = *(char**)(q + 0x2e8);
                o[0xbc] = 0x2d;
                o[0xbd] = 0x78;
                *(u8*)(o + 0xbe) = 0xff;
            }
            q += 4;
        }
        break;
    }
    case 17:
        break;
    }
    if (*(u8*)(self + 0x233) != 0) {
        *(f32*)(self + 0x258) = *(f32*)(self + 0x258) + *(f32*)(self + 0x25c);
    }
    fn_801D1C18(self + 0x264);
    if (*(u8*)(self + 0x230) != 0) {
        fn_8011395C(self);
    }
}

extern "C" void fn_8010DF98(char* self);
extern "C" void fn_801D2608(char* p, char* s, s32 n);
extern "C" void fn_801D22DC(char* p, s32 a, s32 b, s32 c);
extern "C" void fn_801D1F14(char* p, ...);
extern "C" s32 fn_8013CC50(void* obj, void* v, u16 a, s32 b, f32 c, u32 d, s32 e, s32 f, s32 g);
extern "C" void fn_802D6A9C(void);
extern "C" void fn_802D7440(s32 a);
extern "C" void* lbl_8053AAF8;
extern "C" void* lbl_80539F00;
extern "C" f32 lbl_8053C680;
extern "C" f32 lbl_8053C6B8;
extern "C" f32 lbl_8053C6BC;
extern "C" f32 lbl_8053C6C0;
extern "C" f32 lbl_8053C6C4;
extern "C" f32 lbl_8053C6C8;
extern "C" f32 lbl_8053C6CC;
extern "C" s32 lbl_8053AD30;
extern "C" char lbl_8050EC80[];
extern "C" void fn_8010DF78(void* p);
extern "C" void fn_8030C210(void* p, void* v);
extern "C" void fn_80458FF0(void* a, u32 b, s32 c, s32 d);
extern "C" s32 fn_8023BCD4(s32 i);
extern "C" void* fn_8023E724(s32 i);
extern "C" u16 fn_8023CBC0(s32 i);
extern "C" void fn_80230498(s32 i, void* v, u16 a, u8 b, s32 c, s32 d, s32 e);
extern "C" void* fn_8016A3AC(void);
extern "C" void fn_8013CB44(void* obj, void* p, s32 a, s32 b, s32 c);
extern "C" void fn_801CD950(void* p, f32 a, f32 b);
extern "C" void fn_801D1C18(void* p);
extern "C" void fn_8022FE80(s32 a, u32 b, void* c, s32 d, s32 e);
extern "C" u8 fn_803865B8(s32 a);
extern "C" void fn_80388EEC(s32 a);
extern "C" void fn_80387494(s32 a);
extern "C" void fn_801183BC(void);
extern "C" void* fn_80309C4C(void* a, u32 b, s32 c);
extern "C" void fn_801F0E34(void* a, u32 b, u32 c);
extern "C" void fn_80115248(char* self) {
    Vec3_80113B54 vec[5];
    Vec3_80113B54 tmp[4];
    fn_8010DF98(self);
    *(u32*)(self + 0x238) = *(u32*)(self + 0x90) & 0xff;
    *(u32*)(self + 0x244) = (*(u32*)(self + 0x90) >> 22) & 0x1f;
    char* obj = *(char**)((char*)lbl_8053AAF8 + 0xa4);
    s32 (*vfn)(char*, s32, void*) = (s32(*)(char*, s32, void*))(*(void***)obj)[6];
    *(s32*)(self + 0x260) = vfn(obj, 0x3f3f3f3f, lbl_80539F00);
    fn_801D2608(self + 0x264, lbl_8049D820, 7);
    s32 st = *(s32*)(self + 0x238);
    if (st == 6 || st >= 6 || st < 0) {
        fn_801D22DC(self + 0x264, 6, 2, 0);
    } else {
        fn_801D22DC(self + 0x264, 4, 2, 0);
    }
    fn_801D1F14(self + 0x264);
    tmp[0].z = lbl_8053C69C;
    *(f32*)(self + 0x10) = *(f32*)(self + 0x10) - lbl_8053C67C;
    vec[0] = *(Vec3_80113B54*)(self + 0xc);
    tmp[1].z = lbl_8053C69C;
    tmp[2].z = lbl_8053C69C;
    tmp[3].z = lbl_8053C69C;
    tmp[0].x = *(f32*)(self + 0x24) - lbl_8053C698;
    tmp[0].y = *(f32*)(self + 0x28) - lbl_8053C684;
    tmp[1].x = *(f32*)(self + 0x24) + lbl_8053C698;
    tmp[1].y = *(f32*)(self + 0x28) - lbl_8053C684;
    tmp[2].x = *(f32*)(self + 0x24) - lbl_8053C698;
    tmp[2].y = *(f32*)(self + 0x28) + lbl_8053C684;
    tmp[3].x = *(f32*)(self + 0x24) + lbl_8053C698;
    tmp[3].y = *(f32*)(self + 0x28) + lbl_8053C684;
    vec[1] = tmp[0];
    vec[2] = tmp[1];
    vec[3] = tmp[2];
    vec[4] = tmp[3];
    for (s32 i = 0; i < 5; i++) {
        *(s32*)(self + 0x2d0 + i * 4) = fn_8013CC50(*(void**)(self + 0x4), &vec[i], lbl_804648E8[i], 0, lbl_8053C690, lbl_804648F4[i], 0, 0, 1);
    }
    fn_802D6A9C();
    fn_802D7440(0);
}

extern "C" void fn_801EE434(void* handle);
extern "C" void __dl__FPv(void* p);
extern "C" void __dt__13Base_8010E074Fv(void* p, s32 how);
extern "C" void* fn_80115430(char* p, s16 freeFlag) {
    extern void* lbl_8049D83C[];
    extern void* lbl_8049CC34[];
    if (p != 0) {
        *(void**)p = lbl_8049D83C;
        if (*(void**)(p + 0x2a0) != 0) {
            fn_801EE434(*(void**)(p + 0x2a0));
            *(s32*)(p + 0x2a0) = 0;
        }
        if (*(void**)(p + 0x29c) != 0) {
            fn_801EE434(*(void**)(p + 0x29c));
            *(s32*)(p + 0x29c) = 0;
        }
        s32 i = 0;
        char* q = p;
        for (; i < 7; i++) {
            fn_801EE434(*(void**)(q + 0x2a8));
            *(s32*)(q + 0x2a8) = 0;
            if (i < 2) {
                fn_801EE434(*(void**)(q + 0x2e8));
                *(s32*)(q + 0x2e8) = 0;
            }
            if (i < 3) {
                fn_801EE434(*(void**)(q + 0x2c4));
                *(s32*)(q + 0x2c4) = 0;
            }
            if (i < 5) {
                fn_801EE434(*(void**)(q + 0x2d0));
                *(s32*)(q + 0x2d0) = 0;
            }
            q += 4;
        }
        if (*(void**)(p + 0x2a4) != 0) {
            fn_801EE434(*(void**)(p + 0x2a4));
            *(s32*)(p + 0x2a4) = 0;
        }
        if (*(void**)(p + 0x2e4) != 0) {
            fn_801EE434(*(void**)(p + 0x2e4));
            *(s32*)(p + 0x2e4) = 0;
        }
        if (p + 0x264 != 0 && p + 0x288 != 0) {
            *(void**)(p + 0x288) = lbl_8049CC34;
        }
        __dt__13Base_8010E074Fv(p, 0);
        if (freeFlag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

extern "C" char lbl_8049D83C[];
extern "C" s32 lbl_8053AF80;
extern "C" f32 lbl_8053C69C;
extern "C" void fn_8010E074(void*);
extern "C" void fn_801D267C(void*);
extern "C" void fn_80458F9C(s32, s32);
extern "C" void* fn_80115590(char* self) {
    s32 i;
    s32 off;
    f32 zero;

    fn_8010E074(self);
    *(void**)self = lbl_8049D83C;
    zero = lbl_8053C69C;
    *(u8*)(self + 0x230) = 1;
    *(u8*)(self + 0x231) = 1;
    *(u8*)(self + 0x232) = 0;
    *(u8*)(self + 0x233) = 0;
    *(u8*)(self + 0x234) = 1;
    *(s32*)(self + 0x238) = 0;
    *(s32*)(self + 0x23c) = 0;
    *(s32*)(self + 0x240) = 0;
    *(s32*)(self + 0x244) = 0;
    *(s32*)(self + 0x248) = 0;
    *(s32*)(self + 0x24c) = 0;
    *(f32*)(self + 0x250) = zero;
    *(f32*)(self + 0x254) = zero;
    *(f32*)(self + 0x258) = zero;
    *(f32*)(self + 0x25c) = zero;
    *(s32*)(self + 0x260) = 0;
    fn_801D267C(self + 0x264);
    *(s32*)(self + 0x29c) = 0;
    *(s32*)(self + 0x2a0) = 0;
    *(s32*)(self + 0x2a4) = 0;
    *(s32*)(self + 0x2e4) = 0;
    for (i = 0, off = 0; i < 7; off += 4, i++) {
        *(s32*)((u8*)self + off + 0x2a8) = 0;
        if (i < 2) {
            *(s32*)((u8*)self + off + 0x2e8) = 0;
        }
        if (i < 3) {
            *(s32*)((u8*)self + off + 0x2c4) = 0;
        }
        if (i < 5) {
            *(s32*)((u8*)self + off + 0x2d0) = 0;
        }
    }
    fn_80458F9C(lbl_8053AF80, 0x3c);
    return self;
}

void __sinit_tu_80113788_cpp(void) {}

#endif
