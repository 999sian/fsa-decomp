#include "types.h"
#include "Game/SinitPoolChain.h"
#include "JSystem/JGeometry/Box.h"

extern "C" void fn_8010DF58(void);
extern "C" void* fn_8011921C(void);
extern "C" void fn_80132454(char* a, s32 b);
extern "C" s32 lbl_80465204[];
extern const char lbl_80465270[];
extern f32 lbl_8053CD00;
extern "C" void fn_801F02BC(void* this_, const char* name, s32 id, struct SPFR_DrawParam* param, s32 a, s32 b, s32 c, f32 s0, f32 s1);
extern "C" void fn_8022FE80(s32 a, s32 b, void* c, s32 d, s32 e);
extern "C" void fn_8022FEB8(void* box, s32 room, void* handle, s32 a, s32 b);
extern "C" void fn_8022FF8C(s32 a, void* box, s32 room, void* handle, s32 b, s32 c);
extern "C" s32 fn_8022FD8C(void* handle);
extern "C" bool fn_802300EC(void);
extern "C" bool fn_8038AD24(s32 a, s32 b, void* c, s32 d, void* e, s32 f);
extern "C" bool fn_80388CAC(s32 a, void* b);
extern "C" bool fn_803865B8(s32 a);
extern "C" void fn_80388EEC(s32 a);
extern "C" void fn_801183BC(void);
extern "C" void fn_801186B0(void* a, s32 b);
extern "C" void fn_801F0E34(void* a, s32 b, s32 c);
extern "C" void fn_8037AE00(void* a);
extern "C" void fn_8010DF78(void);
extern "C" void fn_80239914(void* box, u32 a, u32 b);
extern "C" void fn_801D1C18(void* p);
extern "C" void fn_8030C210(void* a, void* b);
extern "C" void fn_8013CB44(void* a, void* b, s32 c, s32 d, s32 e);
extern "C" s32 fn_8013CC50(void* a, void* b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, f32 i);
extern "C" s32 Actor_CreateByID(void* mgr, u32 name, u32 id, f32* pos, u32 arg5, s32 arg6, s32 arg7);
extern u8* lbl_8053AAF8;
extern void* lbl_8053AD70;
extern f32 lbl_8053CCF0;
extern f32 lbl_8053CCF4;
extern f32 lbl_8053CCF8;
extern f32 lbl_8053CCFC;
extern f32 lbl_8053CD04;
extern f32 lbl_8053CD14;
extern f32 lbl_8053CD08;
extern f32 lbl_8053CD0C;
extern f32 lbl_8053CD10;
extern f32 lbl_8053CD24;
static inline f32 spfrRand01() {
    u32* s = (u32*)(lbl_8053AAF8 + 0xb4);
    *s = *s * 0x19660du + 0x3c6ef35fu;
    u32 a = (*s >> 9) | 0x3f800000u;
    return *(f32*)&a - lbl_8053CD00;
}

struct SPFR_DrawKey {
    s32 a, b;
    SPFR_DrawKey() { a = -1; b = -1; }
};
struct SPFR_DrawParam {
    u8 map[16];
    SPFR_DrawKey key;
    s32 c;
    u8 palette;
    u8 color;
    u8 f1e, f1f, f20, f21, f22, f23, f24, f25, f26;
    s32 blend;
    u8 f2c, f2d, f2e;
    s32 g;
    s32 h;
    s32 i;

    SPFR_DrawParam() {
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

extern "C" s32 fn_801321DC(char* p) {
    return *(s32*)(p + 0x234);
}

extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F7A08(void* mgr, u32 type);
extern "C" void* fn_801F666C(void* mgr, s32 idx);
extern u8* lbl_8053AB10;
extern f32 lbl_8053CD18;
extern f32 lbl_8053CD1C;
extern f32 lbl_8053CD20;
extern "C" void fn_801321E4(char* p) {
    JGeometry::TVec3<f32> pos;
    char* g;
    char* obj;
    s32 id;
    f32 c;
    f32 x;
    f32 y;
    f32 xp;
    f32 xm;
    switch (*(s32*)(p + 0x234)) {
    case 4:
    case 5:
    case 6:
    case 7:
    case 22:
        if (*(s32*)(p + 0x238) == 0) {
            g = *(char**)(lbl_8053AB10 + 0x24);
            *(u8*)(g + 0x17d) = 1;
        } else {
            c = lbl_8053CD18;
            g = *(char**)(lbl_8053AB10 + 0x24);
            *(u8*)(g + 0x179) = 1;
            x = *(f32*)(p + 0x10);
            y = *(f32*)(p + 0xc);
            xp = x + c;
            xm = x - c;
            g = *(char**)(lbl_8053AB10 + 0x24);
            if (*(u8*)(g + 0x7f5) == 0) {
                *(u8*)(g + 0x7f4) = 1;
                *(s32*)(g + 0x7f8) = 5;
                *(f32*)(g + 0x808) = y;
                *(f32*)(g + 0x80c) = xm;
                *(f32*)(g + 0x810) = y;
                *(f32*)(g + 0x814) = xp;
                *(u8*)(g + 0x7f6) = 0;
            }
        }
        break;
    case 8:
        g = *(char**)(lbl_8053AB10 + 0x24);
        *(u8*)(g + 0x179) = 1;
        id = fn_801F7A08(fn_801F856C(), 0x42415249);
        if (id >= 0) {
            obj = (char*)fn_801F666C(fn_801F856C(), id);
            if (obj != 0) {
                pos = *(JGeometry::TVec3<f32>*)(obj + 0xc);
                pos.y = pos.y + lbl_8053CD18;
                g = *(char**)(lbl_8053AB10 + 0x24);
                if (*(u8*)(g + 0x840) == 0) {
                    *(u8*)(g + 0x840) = 1;
                    *(f32*)(g + 0x844) = pos.x;
                    *(f32*)(g + 0x848) = pos.y - lbl_8053CD1C;
                    *(f32*)(g + 0x84c) = pos.x;
                    *(f32*)(g + 0x850) = pos.y + lbl_8053CD1C;
                    *(f32*)(g + 0x854) = lbl_8053CD00;
                    *(f32*)(g + 0x1d4) = lbl_8053CD20;
                    *(f32*)(g + 0x1d8) = lbl_8053CD20;
                }
            }
        }
        break;
    case 9:
    case 10:
        c = lbl_8053CD18;
        g = *(char**)(lbl_8053AB10 + 0x24);
        *(u8*)(g + 0x179) = 1;
        x = *(f32*)(p + 0x10);
        y = *(f32*)(p + 0xc);
        xp = x + c;
        xm = x - c;
        g = *(char**)(lbl_8053AB10 + 0x24);
        if (*(u8*)(g + 0x840) == 0) {
            *(u8*)(g + 0x840) = 1;
            *(f32*)(g + 0x844) = y;
            *(f32*)(g + 0x848) = xm;
            *(f32*)(g + 0x84c) = y;
            *(f32*)(g + 0x850) = xp;
            *(f32*)(g + 0x854) = lbl_8053CD00;
            *(f32*)(g + 0x1d4) = lbl_8053CD20;
            *(f32*)(g + 0x1d8) = lbl_8053CD20;
        }
        break;
    case 11:
        g = *(char**)(lbl_8053AB10 + 0x24);
        if (*(u8*)(g + 0x7f4) == 0) {
            *(u8*)(g + 0x7f5) = 1;
        }
        break;
    case 12:
    case 13:
        g = *(char**)(lbl_8053AB10 + 0x24);
        *(u8*)(g + 0x17d) = 1;
        break;
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
        c = lbl_8053CD18;
        g = *(char**)(lbl_8053AB10 + 0x24);
        *(u8*)(g + 0x179) = 1;
        x = *(f32*)(p + 0x10);
        y = *(f32*)(p + 0xc);
        xp = x + c;
        xm = x - c;
        g = *(char**)(lbl_8053AB10 + 0x24);
        if (*(u8*)(g + 0x840) == 0) {
            *(u8*)(g + 0x840) = 1;
            *(f32*)(g + 0x844) = y;
            *(f32*)(g + 0x848) = xm;
            *(f32*)(g + 0x84c) = y;
            *(f32*)(g + 0x850) = xp;
            *(f32*)(g + 0x854) = lbl_8053CD00;
            *(f32*)(g + 0x1d4) = lbl_8053CD20;
            *(f32*)(g + 0x1d8) = lbl_8053CD20;
        }
        break;
    case 0:
    case 1:
    case 2:
    case 3:
    case 21:
    case 23:
    case 24:
    case 25:
    case 26:
        break;
    }
}

extern "C" void fn_80119998(void* a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h);
extern "C" void* fn_80119DD0(void);
extern "C" void fn_801D22DC(void* anim, s32 a, s32 b, s32 c);
extern "C" void fn_801D1F14(void* anim, f32 scale);
extern "C" void fn_80138B7C(void* mgr);
extern "C" void fn_8037AE30(void* a);
extern "C" void fn_80230BF4(void* a, s32 b);
extern "C" void fn_80230498(void* a, void* b, s32 c, s32 d, s32 e, s32 f, s32 g);
extern "C" void fn_802303FC(void* a, void* b, s32 c);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D8050(void* mgr, void* kind, u32 a, u32 b);
extern "C" void fn_801F0D20(char* p, s32 n);
extern "C" void fn_80458FF0(void* a, s32 b, s32 c, s32 d);
extern "C" void fn_8038BD08(s32 a, s32 b, s32 c, void* d, s32 e);
extern "C" void fn_80118454(void);
extern "C" void fn_80118384(void);
extern void* lbl_8053AF80;
extern f32 lbl_8053CD0C;
extern f32 lbl_8053CD10;
extern f32 lbl_8053CD24;
extern "C" void fn_80132454(char* p, s32 state) {
    s32 sfx;
    JGeometry::TVec3<f32> v;
    s32 id;
    s32 i;
    char* obj;
    f32 x;
    f32 y1;
    *(s32*)(p + 0x234) = state;
    switch (state) {
    case 1:
    case 4:
        fn_8013CC50(*(void**)(p + 4), p + 0xc, 0x31, 0, 0, 0, 0, 1, lbl_8053CD00);
        fn_8013CC50(*(void**)(p + 4), p + 0xc, 0x32, 0, 0, 0, 0, 1, lbl_8053CD00);
        fn_801F0E34(p, 0x400d9, 0);
        break;
    case 2:
        *(s32*)(p + 0x23c) = -1;
        break;
    case 5:
    {
        JGeometry::TVec3<f32> tmp = *(JGeometry::TVec3<f32>*)(p + 0xc);
        *(s32*)(p + 0x288) = fn_8013CC50(*(void**)(p + 4), &tmp, 0x184, 0, -1, 0, 0, 1, lbl_8053CD00);
        *(u8*)(p + 0x11d) = 1;
        fn_801F0E34(p, 0x40090, 0);
        break;
    }
    case 6:
        fn_8022FE80(0, *(s32*)(p + 4), *(void**)(p + 0x198), 1, 0);
        fn_8022FD8C(*(void**)(p + 0x198));
        sfx = 0x2b5;
        if (*(s32*)(p + 0x238) == 1) {
            sfx = 0x2b6;
        }
        {
            JGeometry::TVec3<f32> vv;
            vv.x = lbl_8053CCF0;
            vv.y = lbl_8053CD24;
            vv.z = lbl_8053CCF0;
            fn_8038BD08(0, (u16)sfx, *(s32*)(p + 4), &vv, 0x4022);
        }
        fn_8011921C();
        fn_80118454();
        break;
    case 7:
        fn_801F0D20(p, 0x3b);
        break;
    case 8:
        fn_80458FF0(lbl_8053AF80, 0x100021, 0, 0);
        break;
    case 9:
    {
        fn_8022FE80(0, *(s32*)(p + 4), *(void**)(p + 0x198), 1, 0);
        fn_8022FD8C(*(void**)(p + 0x198));
        JGeometry::TVec3<f32> vv;
        vv.x = lbl_8053CCF0;
        vv.y = lbl_8053CD24;
        vv.z = lbl_8053CCF0;
        fn_8038BD08(0, 0x2b0, *(s32*)(p + 4), &vv, 0x4022);
        fn_8011921C();
        fn_80118454();
        break;
    }
    case 10:
        fn_801D22DC(p + 0x250, 1, 0, 0);
        fn_801D1F14(p + 0x250, lbl_8053CCF0);
        fn_801F0E34(p, 0x400ef, 0);
        break;
    case 12:
        break;
    case 13:
        fn_801D22DC(p + 0x250, 0, 2, 0);
        fn_801D1F14(p + 0x250, lbl_8053CCF0);
        fn_80119998(fn_80119DD0(), 0x3c, 0, 2, 0, 0, 0, 0);
        fn_80138B7C(lbl_8053AAF8);
        fn_8037AE00(lbl_8053AD70);
        break;
    default:
        break;
    }
}

extern "C" char lbl_8049EB8C[];
extern "C" char lbl_8049CC34[];
extern "C" void fn_801EE434(void*);
extern "C" void __dt__13Base_8010E074Fv(void*, int);
extern "C" void fn_8010E074(void*);
extern "C" void fn_801D267C(void*);
void operator delete(void*);
extern "C" s32 fn_80132AE0(char* p) {
    switch (*(s32*)(p + 0x234)) {
    case 21:
    case 25:
    case 26:
        return 1;
    }
    return 0;
}

extern "C" void fn_80132B10(char* p)
{
    s32 state;
    s32 v;

    if (*(s32*)((char*)fn_8011921C() + 4) == 0xe) {
        char* ret = (char*)fn_8011921C();
        state = *(s32*)(p + 0x238);
        v = *(s32*)(ret + 8);
        switch (state) {
        case 0:
            if (v == lbl_80465204[5]) {
                fn_80132454(p, 5);
            } else if (v == lbl_80465204[6]) {
                fn_80132454(p, 6);
            } else if (v == lbl_80465204[7]) {
                fn_80132454(p, 7);
            } else if (v == lbl_80465204[8]) {
                fn_80132454(p, 8);
            } else if (v == lbl_80465204[9]) {
                fn_80132454(p, 9);
            } else if (v == lbl_80465204[10]) {
                fn_80132454(p, 10);
            } else if (v == lbl_80465204[11]) {
                fn_80132454(p, 11);
            } else if (v == lbl_80465204[12]) {
                fn_80132454(p, 12);
            } else if (v == lbl_80465204[13]) {
                fn_80132454(p, 13);
            } else if (v == lbl_80465204[14]) {
                fn_80132454(p, 14);
            } else if (v == lbl_80465204[15]) {
                fn_80132454(p, 15);
            } else if (v == lbl_80465204[16]) {
                fn_80132454(p, 16);
            } else if (v == lbl_80465204[17]) {
                fn_80132454(p, 17);
            } else if (v == lbl_80465204[18]) {
                fn_80132454(p, 18);
            } else if (v == lbl_80465204[19]) {
                fn_80132454(p, 19);
            } else if (v == lbl_80465204[20]) {
                fn_80132454(p, 20);
            } else if (v == lbl_80465204[21]) {
                fn_80132454(p, 21);
            }
            break;
        case 1:
            if (v == lbl_80465204[4]) {
                fn_80132454(p, 4);
            } else if (v == lbl_80465204[5]) {
                fn_80132454(p, 5);
            } else if (v == lbl_80465204[6]) {
                fn_80132454(p, 6);
            } else if (v == lbl_80465204[22]) {
                fn_80132454(p, 0x16);
            } else if (v == lbl_80465204[23]) {
                fn_80132454(p, 0x13);
            } else if (v == lbl_80465204[24]) {
                fn_80132454(p, 0x14);
            } else if (v == lbl_80465204[25]) {
                fn_80132454(p, 0x19);
            }
            break;
        }
    }
}

extern "C" void fn_80132E18(void* param_1) {
    fn_8010DF58();
    SPFR_DrawParam param;
    fn_801F02BC(param_1, lbl_80465270, *(s32*)((char*)param_1 + 0x260) + 0x2fb, &param, 0x407, 0, 0, lbl_8053CD00, lbl_8053CD00);
}

extern "C" void fn_80132F60(char* p) {
    JGeometry::TBox2f box;
    s32 id;

    fn_8010DF78();
    box.i.x = *(f32*)(p + 0x60);
    box.i.y = *(f32*)(p + 0x64);
    box.f.x = *(f32*)(p + 0x68);
    box.f.y = *(f32*)(p + 0x6c);
    box.i.x += *(f32*)(p + 0xc);
    box.i.y += *(f32*)(p + 0x10);
    box.f.x += *(f32*)(p + 0xc);
    box.f.y += *(f32*)(p + 0x10);
    fn_801321E4(p);
    switch (*(s32*)(p + 0x234)) {
    case 0:
        switch (*(s32*)(p + 0x238)) {
        case 0:
            fn_8011921C();
            fn_801183BC();
            fn_80132454(p, 4);
            break;
        case 1:
            if ((*(bool(**)(char*))(*(char**)p + 0x34))(p)) {
                fn_801186B0(fn_8011921C(), 0xe);
            }
            break;
        }
        break;
    case 1:
        *(s32*)(p + 0x244) += 1;
        if (*(s32*)(p + 0x244) >= 0x28) {
            JGeometry::TVec3f v = *(JGeometry::TVec3f*)(p + 0xc);
            *(s32*)(p + 0x288) = fn_8013CC50(*(void**)(p + 4), &v, 0x184, 0, -1, 0, 0, 1, lbl_8053CD00);
            *(u8*)(p + 0x11d) = 1;
            fn_801F0E34(p, 0x40090, 0);
            fn_80132454(p, 2);
        }
        break;
    case 2:
        switch (*(s32*)(p + 0x238)) {
        case 0:
        default:
            break;
        case 1: {
            JGeometry::TVec3f v;
            JGeometry::TVec3f pos;
            JGeometry::TBox2f box2;
            box2.i.x = *(f32*)(p + 0x60);
            box2.i.y = *(f32*)(p + 0x64);
            box2.f.x = *(f32*)(p + 0x68);
            box2.f.y = *(f32*)(p + 0x6c);
            box2.i.x += *(f32*)(p + 0xc);
            box2.i.y += *(f32*)(p + 0x10);
            box2.f.x += *(f32*)(p + 0xc);
            box2.f.y += *(f32*)(p + 0x10);
            fn_8022FEB8(&box2, *(s32*)(p + 4), *(void**)(p + 0x198), 1, 0);
            id = fn_8022FD8C(*(void**)(p + 0x198));
            if (id < 0) {
                id = -1;
            } else if (!fn_802300EC()) {
                id = -1;
            } else {
                pos = *(JGeometry::TVec3f*)(p + 0xc);
                pos.y -= lbl_8053CD14;
                v = pos;
                if (!fn_8038AD24(id, 0x2b6, *(void**)(p + 0x198), *(s32*)(p + 4), &v, 0x28)) {
                    id = -1;
                }
            }
            if (id >= 0) {
                *(s32*)(p + 0x23c) = id;
                fn_80132454(p, 3);
            }
            break;
        }
        }
        break;
    case 3:
        fn_8022FF8C(*(s32*)(p + 0x23c), &box, *(s32*)(p + 4), *(void**)(p + 0x198), 1, 0);
        if (fn_80388CAC(*(s32*)(p + 0x23c), *(void**)(p + 0x198))) {
            fn_80132454(p, 2);
        }
        break;
    case 6:
        fn_8022FE80(0, *(s32*)(p + 4), *(void**)(p + 0x198), 1, 0);
        if (fn_803865B8(0)) {
            fn_80388EEC(0);
            fn_8011921C();
            fn_801183BC();
        }
        break;
    case 8:
        *(s32*)(p + 0x24c) += 1;
        if (*(s32*)(p + 0x24c) >= 0xf) {
            JGeometry::TVec3f pos;
            void* obj;

            *(s32*)(p + 0x24c) = 0;
            pos.x = lbl_8053CCF0;
            pos.y = lbl_8053CCF0;
            pos.z = lbl_8053CCF0;
            id = fn_801F7A08(fn_801F856C(), 0x42415249);
            if (id >= 0) {
                obj = fn_801F666C(fn_801F856C(), id);
                if (obj != 0) {
                    pos = *(JGeometry::TVec3f*)((char*)obj + 0xc);
                }
            }
            pos.x -= lbl_8053CCF4;
            pos.y += lbl_8053CCF8;
            pos.x += (spfrRand01()) * lbl_8053CCFC;
            pos.y += (spfrRand01()) * lbl_8053CD04;
            Actor_CreateByID(fn_801F856C(), 0x534c5231, *(u32*)(p + 4), (f32*)&pos, 0x102, -1, -1);
        }
        break;
    case 9:
        fn_8022FE80(0, *(s32*)(p + 4), *(void**)(p + 0x198), 1, 0);
        if (fn_803865B8(0)) {
            fn_80388EEC(0);
            fn_8011921C();
            fn_801183BC();
        }
        break;
    case 12:
        fn_8037AE00(lbl_8053AD70);
        break;
    case 15:
        fn_8022FE80(0, *(s32*)(p + 4), *(void**)(p + 0x198), 1, 0);
        if (fn_803865B8(0)) {
            fn_80388EEC(0);
            fn_8011921C();
            fn_801183BC();
        }
        break;
    case 19:
        fn_8022FE80(0, *(s32*)(p + 4), *(void**)(p + 0x198), 1, 0);
        if (fn_803865B8(0)) {
            fn_80388EEC(0);
            fn_8011921C();
            fn_801183BC();
        }
        break;
    case 26:
        break;
    }
    fn_8013CB44(*(void**)(p + 0x288), p + 0xc, 0, -1, 1);
    if (*(u8*)(p + 0x230) != 0) {
        fn_80239914(&box, *(u32*)(p + 4), *(u32*)(p + 0x198));
    }
    fn_801D1C18(p + 0x250);
    if (*(u8*)(p + 0x11d) != 0) {
        fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), p + 0xc);
    }
}

extern "C" void fn_8010DF98(void);
extern "C" void fn_801D2608(void* a, void* b, s32 c);
extern "C" void fn_801D22DC(void* a, s32 b, s32 c, s32 d);
extern "C" void fn_801D1F14(void* a, f32 b);
extern "C" s32 fn_8013CC50(void* a, void* b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, f32 i);
extern "C" void fn_80132454(char* a, s32 b);
extern char lbl_8049EB80[];
extern f32 lbl_8053CD28;
extern f32 lbl_8053CD08;
extern f32 lbl_8053CCF0;
extern f32 lbl_8053CD00;
extern "C" void fn_801334CC(char* p) {
    struct Vec3f {
        f32 x;
        f32 y;
        f32 z;
    } pos;
    fn_8010DF98();
    f32 b = lbl_8053CD08;
    f32 a = lbl_8053CD28;
    *(s32*)(p + 0x238) = *(s32*)(p + 0x90) & 1;
    *(s32*)(p + 0x248) = (*(u32*)(p + 0x90) >> 22) & 0x1f;
    *(f32*)(p + 0x60) = a;
    *(f32*)(p + 0x64) = a;
    *(f32*)(p + 0x68) = b;
    *(f32*)(p + 0x6c) = b;
    *(f32*)(p + 0x70) = *(f32*)(p + 0x60);
    *(f32*)(p + 0x74) = *(f32*)(p + 0x64);
    *(f32*)(p + 0x78) = *(f32*)(p + 0x68);
    *(f32*)(p + 0x7c) = *(f32*)(p + 0x6c);
    *(f32*)(p + 0x80) = *(f32*)(p + 0x60);
    *(f32*)(p + 0x84) = *(f32*)(p + 0x64);
    *(f32*)(p + 0x88) = *(f32*)(p + 0x68);
    *(f32*)(p + 0x8c) = *(f32*)(p + 0x6c);
    fn_801D2608(p + 0x250, lbl_8049EB80, 3);
    fn_801D22DC(p + 0x250, 0, 2, 0);
    fn_801D1F14(p + 0x250, lbl_8053CCF0);
    *(f32*)(p + 0x14) = lbl_8053CD08;
    *(u8*)(p + 0x11d) = 0;
    if (*(s32*)(p + 0x238) == 1) {
        if ((*(s32(**)(char*))(*(char**)p + 0x34))(p)) {
            *(u8*)(p + 0x11d) = 1;
            pos = *(struct Vec3f*)(p + 0xc);
            *(s32*)(p + 0x288) = fn_8013CC50(*(void**)(p + 0x4), &pos, 0x184, 0, -1, 0, 0, 1, lbl_8053CD00);
        }
    }
    fn_80132454(p, 2);
}

extern "C" void* fn_80133624(char* p, s16 flag) {
    if (p != 0) {
        *(void**)p = lbl_8049EB8C;
        fn_801EE434(*(void**)(p + 0x288));
        *(void**)(p + 0x288) = 0;
        if (p + 0x250 != 0 && p + 0x274 != 0) {
            *(void**)(p + 0x274) = lbl_8049CC34;
        }
        __dt__13Base_8010E074Fv(p, 0);
        if (flag > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" void* fn_801336B4(char* p) {
    fn_8010E074(p);
    *(void**)p = lbl_8049EB8C;
    p[0x230] = 0;
    *(s32*)(p + 0x234) = 0;
    *(s32*)(p + 0x238) = 0;
    *(s32*)(p + 0x23c) = -1;
    *(s32*)(p + 0x240) = 0;
    *(s32*)(p + 0x244) = 0;
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x24c) = 0;
    fn_801D267C(p + 0x250);
    *(void**)(p + 0x288) = 0;
    return p;
}

void __sinit_SPFR_801321DC_cpp(void) {}

