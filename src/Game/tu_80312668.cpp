#include "Game/esd/types.h"
#include "Game/Actor.h"
#include "Game/ItemBase.h"

extern "C" void fn_801F06F0(void* actor, void* res, u32 id, DrawRec* rec, s32 p5, f32 a, f32 b);
extern "C" u8 fn_802ED7F0(char* p, f32 v);
extern "C" u8* fn_801F856C(void);
extern "C" u8 lbl_804714C0[];
extern const f32 lbl_805417E8;
extern const f32 lbl_805417EC;
extern const f32 lbl_805417F0;
extern const f32 lbl_805417F4;
extern const f32 lbl_805417F8;
extern f32 lbl_80541800;
extern f32 lbl_80541804;
extern const f32 lbl_80541810;


extern "C" char lbl_804AABA8[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" void __dl__FPv(void*);
extern "C" Actor* fn_80312668(Actor* p, s16 n) {
    if (p != 0) {
        *(void**)p = lbl_804AABA8;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_strength_reduction off
extern "C" void fn_803126C8(Actor* p) {
    DrawRec rec;
    s32 t;
    s32 idx;
    s32 p5;
    rec.b1f = 0;
    t = *(s32*)((u8*)p + 0x230);
    if (t >= 6 && t < 0xd) {
        *(f32*)((u8*)p + 0x14) += *(f32*)((u8*)p + 0x44);
        *(f32*)((u8*)p + 0x44) += *(f32*)((u8*)p + 0x284);
        if (*(f32*)((u8*)p + 0x44) <= lbl_805417E8 || *(f32*)((u8*)p + 0x44) >= lbl_805417EC) {
            *(f32*)((u8*)p + 0x284) = -*(f32*)((u8*)p + 0x284);
        }
        ((u8*)&rec.w10)[3] = *((u8*)p + 0x28c);
        rec.b1c = 1;
        rec.b1d = 1;
        rec.b20 = 0;
        rec.b2d = 1;
        fn_801F06F0(p, lbl_804714C0, *(s32*)((u8*)p + 0x234) + 0x27b, &rec, -1, lbl_805417F0, lbl_805417F0);
    } else if (t >= 0xd && *((u8*)p + 0x27c) == 1) {
        if ((t >= 0xe && t < 0x10) || (t == 0x10 && *(s32*)((u8*)p + 0x238) > 0x3c)) {
            *(f32*)((u8*)p + 0x14) += *(f32*)((u8*)p + 0x44);
            *(f32*)((u8*)p + 0x44) += *(f32*)((u8*)p + 0x284);
            if (*(f32*)((u8*)p + 0x44) <= lbl_805417F4 || *(f32*)((u8*)p + 0x44) >= lbl_805417F8) {
                *(f32*)((u8*)p + 0x284) = -*(f32*)((u8*)p + 0x284);
            }
            idx = *(s32*)((u8*)p + 0x278);
            if (idx >= 0) {
                u8* mgr = fn_801F856C();
                u8** slots = (u8**)mgr;
                u8* other = (slots + idx)[2];
                if (other != 0 && *(u32*)(other + 0x1a0) == 0x474e4546) {
                    fn_802ED7F0((char*)other, *(f32*)((u8*)p + 0x14));
                }
            }
        }
        if (*(s32*)((u8*)p + 0x230) < 0x14) {
            rec.b20 = 0;
            p5 = 7;
        } else {
            rec.b1d = 1;
            rec.b1c = 1;
            p5 = -1;
        }
        fn_801F06F0(p, lbl_804714C0, *(s32*)((u8*)p + 0x234) + 0x27f, &rec, p5, lbl_805417F0, lbl_805417F0);
    }
}
#pragma opt_propagation reset
#pragma opt_common_subs reset
#pragma opt_strength_reduction reset
struct GnefList8031 {
    u8 pad[8];
    u8* actors[1];
};
extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802D800C(void* mgr, u32 v);
extern "C" void fn_80458F9C(void* obj, s32 v);
extern void* lbl_8053AF80;
extern void* lbl_8053AD70;
extern void* lbl_8053AC98;
extern u8* lbl_8053AB10;
extern u8* lbl_8053AAF8;
extern "C" s32 lbl_804AAB98[];
extern "C" u32 lbl_804714A0[];
extern "C" u32 lbl_804714B0[];
extern const f32 lbl_805417FC;
extern const f32 lbl_80541808;
extern const f32 lbl_8054180C;
extern const f32 lbl_80541814;
extern const f32 lbl_80541818;
extern const f32 lbl_8054181C;
extern const f32 lbl_80541820;
extern const f32 lbl_80541824;
extern const f32 lbl_80541828;
extern const f32 lbl_8054182C;
extern const f32 lbl_80541830;
extern const f32 lbl_80541834;
extern const f32 lbl_80541838;
extern const f32 lbl_8054183C;
extern const f32 lbl_80541840;
extern const f32 lbl_80541844;
extern const f32 lbl_80541848;
extern const f32 lbl_8054184C;
extern const f32 lbl_80541850;
extern const f32 lbl_80541854;
extern const f32 lbl_80541858;
extern "C" s32 fn_8023DE58(s32);
extern "C" u8 fn_80230188(s32);
extern "C" u8 fn_8022D75C(s32);
extern "C" void fn_8022CA6C(s32, s32, s32);
extern "C" void fn_80230C6C(s32);
extern "C" u8 fn_8022F514(s32);
extern "C" void* fn_8023E724(s32);
extern "C" void fn_802317F0(s32, s32, void*, f32*, s32);
extern "C" u8 fn_8023188C(s32);
extern "C" void fn_80230BF4(s32, s32);
extern "C" void fn_80230AD4(s32);
extern "C" void fn_8037AE00(void*);
extern "C" s32 fn_8022EA0C(s32);
extern "C" void fn_80230498(s32, void*, s32, s32, s32, s32, s32);
extern "C" u8 fn_8022E438(s32);
extern "C" void fn_8029D898(void*, s32);
extern "C" void fn_8045815C(void*, s32);
extern "C" void fn_802303FC(s32, void*, s32);
extern "C" void fn_8022FE80(s32, u32, u32, s32, s32);
extern "C" s32 fn_8022FD8C(u32);
extern "C" u8 fn_8038AD24(s32, u32, u32, u32, f32*, s32);
extern "C" u8 fn_80388CAC(s32, u32);
extern "C" void fn_801F71A4(f32*, f32, f32, f32);
extern "C" void Gnef_SetCueFlag(u8*);
extern "C" u8 fn_8038BD08(s32, u32, u32, f32*, s32);
extern "C" void fn_80138B7C(void*);
extern "C" void fn_80230F44(s32, s32);
extern "C" void fn_8037AD70(void*, s32);
extern "C" void fn_80230534(s32);
extern "C" void fn_8022CC20(s32);
extern "C" void fn_802D8050(void*, u32, s32, s32);
extern "C" void fn_8022ADCC(void);
extern "C" void fn_801F35AC(Actor*);
#pragma opt_propagation off
extern "C" void fn_803129AC(Actor* p) {
    u8* self = (u8*)p;
    s32 j;
    s32 idx;
    u8 flag;
    s32 i;
    f32 vec[3];
    u8* mgr;
    u8** slots;
    u8* other;
    switch (*(s32*)(self + 0x230)) {
    case 0:
        if (!fn_802D800C(fn_802D6A9C(), *(u32*)(self + 0x23c))) {
            break;
        }
        fn_80458F9C(lbl_8053AF80, 0x3c);
        *(s32*)(self + 0x230) = 1;
    case 1: {
        s32 t = *(s32*)(self + 0x238);
        if (t > 0) {
            *(s32*)(self + 0x238) = t - 1;
            break;
        }
        flag = 1;
        f32 step = lbl_805417FC;
        vec[0] = *(f32*)(self + 0x25c);
        vec[1] = *(f32*)(self + 0x260);
        vec[2] = *(f32*)(self + 0x264);
        for (i = 0; i < 4; i++) {
            if (fn_8023DE58(i) != 0) {
                flag = 0;
            }
            if (!fn_80230188(i) && !fn_8022D75C(i)) {
                if (fn_8023DE58(i) != 0) {
                    fn_8022CA6C(i, 5, 0);
                    fn_80230C6C(i);
                    if (!fn_8022F514(i)) {
                        fn_802317F0(i, 0, fn_8023E724(i), vec, 0x1f);
                    }
                } else if (fn_8023188C(i)) {
                    fn_80230C6C(i);
                    fn_80230BF4(i, 3);
                    fn_80230AD4(i);
                    fn_8022CA6C(i, 5, 0);
                    *(u32*)(self + 0x240) |= 1 << i;
                }
            }
            vec[0] += step;
        }
        if (self[0x27e] == 0 && flag == 1) {
            idx = *(s32*)(self + 0x278);
            if (idx >= 0) {
                mgr = fn_801F856C();
                slots = (u8**)mgr;
                other = (slots + idx)[2];
                if (other != 0 && *(u32*)(other + 0x1a0) == 0x474e4546) {
                    other[0x276] = 1;
                }
            }
            self[0x27e] = 1;
        }
        if (*(s32*)(self + 0x240) == 0xf) {
            fn_8037AE00(lbl_8053AD70);
            *(s32*)(self + 0x230) = 2;
            *(s32*)(self + 0x238) = 0x96;
        }
        break;
    }
    case 2:
        (*(s32*)(self + 0x238))--;
        if (*(s32*)(self + 0x238) > 0) {
            break;
        }
        vec[0] = *(f32*)(self + 0x25c);
        vec[1] = *(f32*)(self + 0x260);
        vec[2] = *(f32*)(self + 0x264);
        *(s32*)(self + 0x244) = lbl_804AAB98[*(s32*)(self + 0x234)];
        *(s32*)(self + 0x248) = fn_8022EA0C(*(s32*)(self + 0x244));
        vec[0] += lbl_80541800;
        vec[1] -= lbl_80541804;
        fn_80230498(*(s32*)(self + 0x244), vec, 0x3f, 0xff, -0x80, -0x80, 1);
        fn_80230BF4(*(s32*)(self + 0x244), 3);
        for (j = 0; j < 4; j++) {
            if (j != *(s32*)(self + 0x244) && fn_8022E438(j)) {
                f32* pos = (f32*)fn_8023E724(j);
                vec[0] = pos[0];
                vec[1] = pos[1];
                vec[2] = pos[2];
                vec[1] += lbl_80541808;
                fn_80230498(j, vec, 0x3f, 0xff, -0x80, -0x80, 1);
            }
        }
        fn_8029D898(lbl_8053AC98, 0x1a);
        fn_8045815C(lbl_8053AF80, 0);
        *(s32*)(self + 0x230) = 3;
        *(s32*)(self + 0x238) = 10;
        break;
    case 3:
        (*(s32*)(self + 0x238))--;
        if (*(s32*)(self + 0x238) > 0) {
            break;
        }
        *(s32*)(self + 0x238) = 0x48;
        (*(s32*)(self + 0x230))++;
        break;
    case 4: {
        (*(s32*)(self + 0x238))--;
        f32* pos = (f32*)fn_8023E724(*(s32*)(self + 0x244));
        vec[0] = pos[0];
        vec[1] = pos[1];
        vec[2] = pos[2];
        vec[1] -= lbl_8054180C;
        if (*(s32*)(self + 0x238) <= 0) {
            fn_80230498(*(s32*)(self + 0x244), vec, 0x3f, 0xff, -0x80, -0x80, 1);
        } else {
            fn_802303FC(*(s32*)(self + 0x244), vec, 0xff);
        }
        if (*(s32*)(self + 0x238) > 0) {
            break;
        }
        *(s32*)(self + 0x230) = 5;
        *(s32*)(self + 0x238) = 0x3c;
        *(u16*)(self + 0x280) = *(u16*)(self + 0x282) = (*(u8**)(lbl_8053AB10 + 0x2c))[0xc];
        break;
    }
    case 6: {
        u8 a = self[0x28c];
        if (a < 0xbf) {
            self[0x28c] = a + 1;
        } else {
            self[0x28c] = a + 2;
        }
        if (self[0x28c] >= 0xff) {
            self[0x28c] = 0xff;
            *(s32*)(self + 0x230) = 7;
            *(s32*)(self + 0x238) = 0x3c;
        }
        break;
    }
    case 8:
        fn_8022FE80(*(s32*)(self + 0x248), *(u32*)(self + 4), *(u32*)(self + 0x198), 0, 0);
        if (*(s32*)(self + 0x248) == fn_8022FD8C(*(u32*)(self + 0x198))) {
            f32 v[3];
            v[0] = lbl_80541810;
            v[1] = lbl_80541814;
            v[2] = lbl_80541810;
            if (fn_8038AD24(*(s32*)(self + 0x248), lbl_804714A0[*(s32*)(self + 0x234)], *(u32*)(self + 0x198), *(u32*)(self + 4), v, 0x4102)) {
                *(s32*)(self + 0x230) = 9;
            }
        }
        break;
    case 9:
        fn_8022FE80(*(s32*)(self + 0x248), *(u32*)(self + 4), *(u32*)(self + 0x198), 1, 0);
        if (fn_80388CAC(*(s32*)(self + 0x248), *(u32*)(self + 0x198))) {
            *(s32*)(self + 0x230) = 0xa;
            *(s32*)(self + 0x238) = 0x28;
        }
        break;
    case 0xb: {
        u8 a = self[0x28c];
        if (a > 2) {
            self[0x28c] = a - 2;
            break;
        }
        self[0x28c] = 0;
        *(s32*)(self + 0x230) = 0xc;
        *(s32*)(self + 0x238) = 0x1e;
        break;
    }
    case 0xc:
        (*(s32*)(self + 0x238))--;
        if (*(s32*)(self + 0x238) > 0) {
            break;
        }
        idx = *(s32*)(self + 0x278);
        if (idx >= 0) {
            mgr = fn_801F856C();
            slots = (u8**)mgr;
            other = (slots + idx)[2];
            if (other != 0 && *(u32*)(other + 0x1a0) == 0x474e4546) {
                other[0x277] = 1;
            }
        }
        *(s32*)(self + 0x230) = 0xd;
        *(f32*)(self + 0x10) -= lbl_80541808;
        *(f32*)(self + 0x14) = lbl_80541810;
        *(f32*)(self + 0x44) = lbl_80541818;
        break;
    case 0xd: {
        f32 lim;
        f32 z;
        z = *(f32*)(self + 0x14);
        lim = lbl_8054181C;
        if (z >= lim) {
            *(f32*)(self + 0x14) = lim;
            *(s32*)(self + 0x230) = 0xe;
            *(s32*)(self + 0x238) = 0x5a;
            *(f32*)(self + 0x44) = lbl_80541810;
        }
        idx = *(s32*)(self + 0x278);
        if (idx >= 0) {
            mgr = fn_801F856C();
            slots = (u8**)mgr;
            other = (slots + idx)[2];
            if (other != 0 && *(u32*)(other + 0x1a0) == 0x474e4546) {
                if (fn_802ED7F0((char*)other, *(f32*)(self + 0x14))) {
                    *(f32*)(self + 0x14) += *(f32*)(self + 0x44);
                    fn_801F71A4((f32*)(self + 0x44), lbl_80541820, lbl_80541824, lbl_80541828);
                    self[0x27c] = 1;
                }
            }
        }
        break;
    }
    case 0xe:
        (*(s32*)(self + 0x238))--;
        if (*(s32*)(self + 0x238) > 0) {
            break;
        }
        idx = *(s32*)(self + 0x278);
        if (idx >= 0) {
            mgr = fn_801F856C();
            slots = (u8**)mgr;
            other = (slots + idx)[2];
            if (other != 0 && *(u32*)(other + 0x1a0) == 0x474e4546) {
                other[0x278] = 1;
            }
        }
        *(s32*)(self + 0x230) = 0xf;
        *(s32*)(self + 0x238) = 0x1fe;
        break;
    case 0xf:
        (*(s32*)(self + 0x238))--;
        if (*(s32*)(self + 0x238) > 0) {
            break;
        }
        *(s32*)(self + 0x230) = 0x10;
        *(s32*)(self + 0x238) = 0xa8;
        break;
    case 0x10: {
        (*(s32*)(self + 0x238))--;
        f32* pos = (f32*)fn_8023E724(*(s32*)(self + 0x244));
        vec[0] = pos[0];
        vec[1] = pos[1];
        vec[2] = pos[2];
        vec[1] -= lbl_8054180C;
        if (*(s32*)(self + 0x238) <= 0) {
            fn_80230498(*(s32*)(self + 0x244), vec, 0x3f, 0xff, -0x80, -0x80, 1);
        } else {
            fn_802303FC(*(s32*)(self + 0x244), vec, 0xff);
        }
        if (*(s32*)(self + 0x238) >= 0x3c) {
            break;
        }
        fn_801F71A4((f32*)(self + 0x44), lbl_8054182C, lbl_80541830, lbl_80541820);
        *(f32*)(self + 0x14) += *(f32*)(self + 0x44);
        idx = *(s32*)(self + 0x278);
        if (idx >= 0) {
            mgr = fn_801F856C();
            slots = (u8**)mgr;
            other = (slots + idx)[2];
            if (other != 0 && *(u32*)(other + 0x1a0) == 0x474e4546) {
                fn_802ED7F0((char*)other, *(f32*)(self + 0x14));
            }
        }
        if (*(s32*)(self + 0x238) > 0) {
            break;
        }
        *(s32*)(self + 0x230) = 0x11;
        *(s32*)(self + 0x238) = 0x3c;
        break;
    }
    case 0x12: {
        *(f32*)(self + 0x14) += *(f32*)(self + 0x44);
        idx = *(s32*)(self + 0x278);
        if (idx >= 0) {
            mgr = fn_801F856C();
            slots = (u8**)mgr;
            other = (slots + idx)[2];
            if (other != 0 && *(u32*)(other + 0x1a0) == 0x474e4546) {
                fn_802ED7F0((char*)other, *(f32*)(self + 0x14));
            }
        }
        f32 z = *(f32*)(self + 0x14);
        if (z <= lbl_80541834) {
            *(s32*)(self + 0x230) = 0x13;
            *(s32*)(self + 0x238) = 0x1e;
        } else if (z <= lbl_80541838 && self[0x27d] == 0) {
            idx = *(s32*)(self + 0x278);
            if (idx >= 0) {
                mgr = fn_801F856C();
                slots = (u8**)mgr;
                other = (slots + idx)[2];
                if (other != 0 && *(u32*)(other + 0x1a0) == 0x474e4546) {
                    Gnef_SetCueFlag(other);
                    self[0x27d] = 1;
                }
            }
        }
        if (self[0x27d] == 1) {
            fn_801F71A4((f32*)(self + 0x44), lbl_8054183C, lbl_80541830, lbl_805417EC);
        } else {
            fn_801F71A4((f32*)(self + 0x44), lbl_8054182C, lbl_80541830, lbl_80541820);
        }
        break;
    }
    case 0x13: {
        (*(s32*)(self + 0x238))--;
        if (*(s32*)(self + 0x238) > 0) {
            break;
        }
        *(s32*)(self + 0x230) = 0x14;
        *(s32*)(self + 0x238) = 0x5a;
        f32* pos = (f32*)fn_8023E724(*(s32*)(self + 0x244));
        vec[0] = pos[0];
        vec[1] = pos[1];
        vec[2] = pos[2];
        *(f32*)(self + 0xc) = vec[0];
        *(f32*)(self + 0x10) = vec[1] - lbl_80541838;
        *(f32*)(self + 0x14) = vec[2];
        *(s32*)(self + 0x288) = 0;
        fn_80230498(*(s32*)(self + 0x244), fn_8023E724(*(s32*)(self + 0x244)), *(s32*)(self + 0x288) + 0xed, 0xff, -0x80, -0x80, 1);
        break;
    }
    case 0x14:
        switch (*(s32*)(self + 0x238)) {
        case 0: {
            f32 v[3];
            v[0] = lbl_80541810;
            v[1] = lbl_80541814;
            v[2] = lbl_80541810;
            if (fn_8038BD08(*(s32*)(self + 0x248), lbl_804714B0[*(s32*)(self + 0x234)], *(u32*)(self + 4), v, 0x4102)) {
                *(s32*)(self + 0x230) = 0x15;
            }
            fn_80138B7C(lbl_8053AAF8);
            break;
        }
        case 0x50:
            fn_80230F44(*(s32*)(self + 0x244), 0x1000002);
        case 0x4c:
        case 0x48:
            *(f32*)(self + 0x10) -= lbl_80541840;
            (*(s32*)(self + 0x288))++;
            fn_80230498(*(s32*)(self + 0x244), fn_8023E724(*(s32*)(self + 0x244)), *(s32*)(self + 0x288) + 0xed, 0xff, -0x80, -0x80, 1);
        default:
            (*(s32*)(self + 0x238))--;
            break;
        }
        break;
    case 0x15:
        if (fn_80388CAC(*(s32*)(self + 0x248), *(u32*)(self + 0x198))) {
            fn_8037AD70(lbl_8053AD70, *(s32*)(self + 0x234));
            *(s32*)(self + 0x230) = 0x16;
            for (j = 0; j < 4; j++) {
                if (j != *(s32*)(self + 0x244) && fn_8022E438(j)) {
                    fn_80230498(j, fn_8023E724(*(s32*)(self + 0x244)), 0x3f, 0xff, -0x80, -0x80, 1);
                }
            }
        }
        break;
    case 0x16:
        fn_80230534(0);
        fn_8022CC20(*(s32*)(self + 0x248));
        fn_802D8050(fn_802D6A9C(), (*(u32*)(self + 0x90) >> 20) & 0x1f, 1, 0xff);
        for (j = 0; j < 4; j++) {
            fn_8022CA6C(j, 5, 1);
        }
        fn_8022ADCC();
        fn_801F35AC(p);
        break;
    case 0x11:
        *(f32*)(self + 0x14) += *(f32*)(self + 0x44);
        idx = *(s32*)(self + 0x278);
        if (idx >= 0) {
            mgr = fn_801F856C();
            slots = (u8**)mgr;
            other = (slots + idx)[2];
            if (other != 0 && *(u32*)(other + 0x1a0) == 0x474e4546) {
                fn_802ED7F0((char*)other, *(f32*)(self + 0x14));
            }
        }
    case 5:
    case 7:
    case 0xa:
        (*(s32*)(self + 0x238))--;
        if (*(s32*)(self + 0x238) > 0) {
            break;
        }
        (*(s32*)(self + 0x230))++;
        break;
    }
    {
        s32 st = *(s32*)(self + 0x230);
        if (st >= 3) {
            if (st < 0xd || (st == 0xd && self[0x27c] == 0)) {
                u8* c = *(u8**)(lbl_8053AB10 + 0x24);
                if (c[0x840] == 0) {
                    c[0x840] = 1;
                    *(f32*)(c + 0x844) = *(f32*)(c + 0x84c) = *(f32*)(self + 0x268);
                    *(f32*)(c + 0x848) = *(f32*)(c + 0x850) = *(f32*)(self + 0x26c);
                    *(f32*)(c + 0x854) = lbl_805417F0;
                    *(f32*)(c + 0x1d4) = lbl_80541844;
                    *(f32*)(c + 0x1d8) = lbl_80541844;
                }
            } else {
                f32 a, b, c2, d;
                if (lbl_8053AAF8[0x7e] != 0) {
                    a = lbl_80541848;
                    b = lbl_8054184C;
                    c2 = lbl_80541850;
                    d = lbl_80541854;
                } else {
                    a = lbl_80541814;
                    b = lbl_80541858;
                    c2 = lbl_80541838;
                    d = lbl_80541834;
                }
                u8* c = *(u8**)(lbl_8053AB10 + 0x24);
                f32 x = *(f32*)(self + 0x268);
                f32 y = *(f32*)(self + 0x26c);
                a += x;
                c2 += x;
                b += y;
                d += y;
                if (c[0x7f5] == 0) {
                    c[0x7f4] = 1;
                    *(s32*)(c + 0x7f8) = 5;
                    *(f32*)(c + 0x808) = a;
                    *(f32*)(c + 0x80c) = b;
                    *(f32*)(c + 0x810) = c2;
                    *(f32*)(c + 0x814) = d;
                    c[0x7f6] = 0;
                }
            }
            u8* e = *(u8**)(lbl_8053AB10 + 0x30);
            if (e[0x284] == 0) {
                e[0x284] = 1;
                *(f32*)(e + 0x28c) = lbl_805417EC;
            }
        }
    }
    {
        s32 st = *(s32*)(self + 0x230);
        if (st >= 5 && st < 0xc) {
            if (*(u16*)(self + 0x280) > 100) {
                *(u16*)(self + 0x280) -= 2;
            }
            if (*(u16*)(self + 0x280) < 100) {
                *(u16*)(self + 0x280) = 100;
            }
        } else if (st >= 0xc) {
            if (*(u16*)(self + 0x280) < *(u16*)(self + 0x282)) {
                *(u16*)(self + 0x280) += 2;
            }
            if (*(u16*)(self + 0x280) >= *(u16*)(self + 0x282)) {
                *(u16*)(self + 0x280) = *(u16*)(self + 0x282);
                (*(u8**)(lbl_8053AB10 + 0x2c))[0xc] = *(u16*)(self + 0x280);
                (*(u8**)(lbl_8053AB10 + 0x2c))[0xe] = *(u16*)(self + 0x280);
            }
        }
    }
    if (*(u16*)(self + 0x280) != *(u16*)(self + 0x282)) {
        (*(u8**)(lbl_8053AB10 + 0x2c))[0xc] = *(u16*)(self + 0x280);
        (*(u8**)(lbl_8053AB10 + 0x2c))[0xe] = *(u16*)(self + 0x280);
    }
}
#pragma opt_propagation reset
extern "C" u8* fn_801F856C(void);
extern f32 lbl_80541800;
extern f32 lbl_80541804;
extern const f32 lbl_8054185C;
extern const f32 lbl_80541860;
extern const f32 lbl_80541864;
extern const f32 lbl_80541868;
extern f32 lbl_8054186C;
extern const f32 lbl_80541810;
extern "C" void fn_803137D0(Actor* p) {
    u8* base = (u8*)fn_801F856C();
    long count = *(s32*)(base + 0x1008);
    s32 off;
    s32 i;
    i = 0;
    off = 0;
    while (count > i) {
        u8* other = *(u8**)((u8*)fn_801F856C() + off + 8);
        if (other != 0 && *(u32*)(other + 0x1a0) == 0x474e4546) {
            *(s32*)((u8*)p + 0x278) = i;
            *(f32*)((u8*)p + 0xc) = *(f32*)(other + 0xc);
            *(f32*)((u8*)p + 0x10) = *(f32*)(other + 0x10);
        }
        off += 4;
        i++;
    }
    *(f32*)((u8*)p + 0x24c) = lbl_8054185C;
    *(f32*)((u8*)p + 0x250) = lbl_80541860;
    *(f32*)((u8*)p + 0x254) = lbl_80541864;
    *(f32*)((u8*)p + 0x258) = lbl_80541868;
    *(f32*)((u8*)p + 0x24c) += *(f32*)((u8*)p + 0xc);
    *(f32*)((u8*)p + 0x250) += *(f32*)((u8*)p + 0x10);
    *(f32*)((u8*)p + 0x254) += *(f32*)((u8*)p + 0xc);
    *(f32*)((u8*)p + 0x258) += *(f32*)((u8*)p + 0x10);
    {
        s8 v = (s8)((*(u32*)((u8*)p + 0x90) >> 12) & 0xff);
        if (!v) {
            *(f32*)((u8*)p + 0x25c) = *(f32*)((u8*)p + 0xc) - lbl_80541800;
        } else {
            *(f32*)((u8*)p + 0x25c) = *(f32*)((u8*)p + 0xc) + (f32)v;
        }
    }
    {
        s8 v = (s8)((*(u32*)((u8*)p + 0x90) >> 4) & 0xff);
        if (!v) {
            *(f32*)((u8*)p + 0x260) = lbl_80541804 + (lbl_8054186C + *(f32*)((u8*)p + 0x10));
        } else {
            *(f32*)((u8*)p + 0x260) = *(f32*)((u8*)p + 0x10) + (f32)v;
        }
    }
    {
        f32 c2 = lbl_80541810;
        *(f32*)((u8*)p + 0x264) = c2;
        *(f32*)((u8*)p + 0x268) = *(f32*)((u8*)p + 0xc);
        *(f32*)((u8*)p + 0x26c) = *(f32*)((u8*)p + 0x10);
        *(f32*)((u8*)p + 0x270) = c2;
    }
}

extern "C" const f32 lbl_80541878;
extern "C" const f32 lbl_8054187C;
extern "C" void fn_80313988(u8* p) {
    *(f32*)(p + 0x14) = lbl_80541878;
    *(f32*)(p + 0x44) = lbl_80541810;
    *(f32*)(p + 0x284) = lbl_8054187C;
    *(u32*)(p + 0x230) = 0;
    *(u32*)(p + 0x234) = *(u32*)(p + 0x90) & 3;
    *(u32*)(p + 0x238) = 0x78;
    *(u32*)(p + 0x23c) = *(u32*)(p + 0x90) >> 27;
    *(s32*)(p + 0x244) = -1;
    *(s32*)(p + 0x248) = -1;
    *(u32*)(p + 0x240) = 0;
    *(s32*)(p + 0x278) = -1;
    *(u8*)(p + 0x27c) = 0;
    *(u8*)(p + 0x27d) = 0;
    *(u8*)(p + 0x27e) = 0;
    *(u8*)(p + 0x28c) = 0;
    *(u16*)(p + 0x280) = 0xff;
    *(u16*)(p + 0x282) = 0xff;
}


