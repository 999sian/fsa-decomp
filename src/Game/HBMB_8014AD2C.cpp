#include "types.h"
#include <math.h>
#include "Game/ItemBase.h"

extern "C" f32 lbl_8053D128;
extern "C" f32 lbl_8053D12C;
extern "C" f32 lbl_8053D130;
extern "C" f32 lbl_8053D138;
extern "C" f32 lbl_8053D144;
extern "C" f32 lbl_8053D16C;
extern "C" f32 lbl_8053D170;
extern "C" f32 lbl_8053D174;
extern "C" f32 lbl_8053D19C;
extern "C" f32 lbl_8053D1A0;
extern "C" u8* lbl_8053AAF8;
extern "C" s32 lbl_8049F760[];
extern "C" char lbl_80465D48[];
extern "C" bool fn_80236B50(s32 idx);
extern "C" s32 fn_8023CB24(s32 v);
extern "C" s32 fn_8023CA88(s32 v);
extern "C" void fn_801F06F0(u8* this_, void* p, s32 idx, DrawRec* rec, s32 mode, f32 x, f32 y);
extern "C" void fn_803075AC(void* h, s32 room, void* pos, s32 idx, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
extern "C" s32 fn_8013CC50(u32 id, void* p, f32 f, u32 a, u32 b, u32 c, u32 d, u32 e, u32 g);
extern "C" void fn_801F0E34(void* a, s32 b, s32 c);
extern "C" u16 fn_8022461C(s32 a, s32 b);
extern "C" u16 fn_80226850(s32 a, s32 b);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D79E8(void* mgr, u32 room, s32 b, f32 x, f32 y);
extern "C" void fn_80134DE4(void* game, s32 a, s32 b);
extern "C" void* fn_8013C824(void);
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void* mgr, void* emitter);
extern "C" u8 fn_8029EDB8(void* mgr, void* pos, s32 a, u32 room, void* out);
extern "C" void fn_8014D868(u8* this_, f32* pos);
extern "C" void* lbl_8053AC98;
extern "C" f32 lbl_8053D134;
extern "C" f32 lbl_8053D17C;
extern "C" f32 lbl_8053D180;
extern "C" f32 lbl_8053D184;
extern "C" f32 lbl_8053D188;
extern "C" f32 lbl_8053D1A4;
extern "C" f64 lbl_8053D1A8;

static inline f64 sqrtStep(f64 tmpd, f32 mag) {
    return tmpd * 0.5 * (3.0 - mag * (tmpd * tmpd));
}
static inline f32 dolsqrtfull(f32 mag) {
    if (mag > 0.0f) {
        f64 tmpd = __frsqrte(mag);
        tmpd = sqrtStep(tmpd, mag);
        tmpd = sqrtStep(tmpd, mag);
        tmpd = sqrtStep(tmpd, mag);
        return mag * tmpd;
    } else if (mag < 0.0) {
        return NAN;
    } else if (fpclassify(mag) == 1) {
        return NAN;
    } else {
        return mag;
    }
}

extern "C" s32 fn_801F7818(void* mgr, u32 name, u32 id, void* list, s32 max);
extern "C" s32 Actor_CreateByID(void* mgr, u32 name, u32 id, f32* pos, u32 arg5, s32 arg6, s32 arg7);

extern "C" char lbl_8049F784[];
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* p);
extern "C" void fn_801EE434(void* p);
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* a, s32 b);
extern "C" void fn_8013CB44(void* a, void* b, s32 c, s32 d, s32 e);
extern "C" BOOL fn_8014AD2C(u8* this_, u32 b, u32 c) {
    s32 kind = (u16)fn_8022461C(c, b);
    s32 sub = (u16)fn_80226850(c, b);

    if ((u32)(kind - 0x10) <= 7 || (sub >= 0x140 && sub <= 0x15f)) {
        *(s32*)(this_ + 0x264) = 1;
        return 0;
    }
    if (kind == 3) {
        *(s32*)(this_ + 0x264) = 0;
        return 0;
    }
    if (kind == 0xe) {
        *(s32*)(this_ + 0x264) = 0;
        return 0;
    }
    if (kind == 0xd || kind == 0x3b) {
        *(s32*)(this_ + 0x264) = 0;
        return 0;
    }
    if (kind != 0x0 && kind != 0x4 && kind != 0x5 && kind != 0x6 && kind != 0x7 && kind != 0x2 && kind != 0x50 &&
        kind != 0xc && kind != 0x27 && kind != 0x28 && kind != 0x29 && kind != 0x2a && kind != 0x2b && kind != 0x2c &&
        kind != 0x2d && kind != 0x2e && kind != 0x2f && kind != 0x20 && kind != 0x39 && kind != 0x3a && kind != 0x4c &&
        kind != 0x4d && kind != 0x4e && kind != 0x4f && kind != 0x24 && kind != 0x23) {
        if (fn_80226850(c, b) == 0x3a || fn_80226850(c, b) == 0x3d) {
            *(s32*)(this_ + 0x264) = 0;
            return 0;
        }
        if (kind == 0x25) {
            if (*(s32*)(this_ + 0x264) == 0 && ((u8*)fn_802D6A9C())[0x171] == 0) {
                return 1;
            }
            return 0;
        }
        if (kind == 0x26) {
            if (*(s32*)(this_ + 0x264) == 0 && ((u8*)fn_802D6A9C())[0x171] == 1) {
                return 1;
            }
            return 0;
        }
        if (*(s32*)(this_ + 0x264) == 0 && (kind != 0x22 || ((u8*)fn_802D6A9C())[0x170] == 1)) {
            return 1;
        }
    }
    return 0;
}

extern "C" void fn_8014AFB4(u8* this_) {
    s32 i;
    s32 n;
    s32 idx;
    s32 mode;
    f32 ss;
    f32 cz;
    f32 cs, a0, a1, a2, a3, a4, a5, a6, a7, a8;
    f32 cc;
    f32 sx;
    f32 sy;
    f32 sz;
    f32 cx;
    f32 cy;
    f32 angle;
    f32 scale;

    if (*(s32*)(this_ + 0x230) == 9) {
        return;
    }
    DrawRec rec;
    f32 mtx[3][4];
    f32 zero = 0.0f;
    mtx[0][3] = zero;
    mtx[1][3] = zero;
    mtx[2][3] = zero;
    i = 0;
    n = 0;
    for (; i < 4; i++) {
        if (fn_80236B50(i)) {
            n++;
        }
    }
    if (n == 4 && *(s32*)(this_ + 0x230) == 5) {
        if (*(s32*)(this_ + 0x234) == 0) {
            *(s32*)(this_ + 0x24c) += 1;
            if (*(s32*)(this_ + 0x24c) > 8) {
                *(s32*)(this_ + 0x24c) = 8;
                *(s32*)(this_ + 0x234) = 0;
                return;
            }
            *(s32*)(this_ + 0x234) = lbl_8049F760[*(s32*)(this_ + 0x24c)];
        } else {
            *(s32*)(this_ + 0x234) -= 1;
        }
    }
    if (*(u32*)(this_ + 0x90) == 8 || *(u32*)(this_ + 0x90) == 9) {
        if (*(s32*)(this_ + 0x230) != 5) {
            scale = *(f32*)(this_ + 0x274);
            scale *= 0.5f;
            n = 0;
            idx = *(s32*)(this_ + 0x24c) + 0x312;
        } else {
            idx = *(s32*)(this_ + 0x24c) + 0xe8;
            n = 1;
        }
    } else {
        n = 0;
        scale = *(f32*)(this_ + 0x274);
        idx = *(s32*)(this_ + 0x24c) + 0xe8;
    }
    angle = *(f32*)(this_ + 0x278);
    sx = sin(zero);
    sy = sin(angle);
    sz = sin(zero);
    cx = cos(zero);
    cy = cos(angle);
    cz = cos(zero);
    rec.w18 = mtx;
    rec.b1d = 1;
    rec.b1c = 1;
    cc = cx * cz;
    ss = sx * sy;
    cs = cx * sz;
    a0 = cy * cz;
    a1 = cy * sz;
    a2 = -sy;
    a3 = ss * cz - cs;
    a4 = ss * sz + cc;
    a5 = sx * cy;
    a6 = cc * sy + sx * sz;
    a7 = cs * sy - sx * cz;
    a8 = cx * cy;
    mtx[0][0] = scale * a0;
    mtx[1][0] = scale * a1;
    mtx[2][0] = scale * a2;
    mtx[0][1] = scale * a3;
    mtx[1][1] = scale * a4;
    mtx[2][1] = scale * a5;
    mtx[0][2] = scale * a6;
    mtx[1][2] = scale * a7;
    mtx[2][2] = scale * a8;
    if (*(s32*)(this_ + 0x90) == 0xb) {
        fn_803075AC(*(void**)(this_ + 0x198), *(s32*)(this_ + 0x4), this_ + 0xc, *(s32*)(this_ + 0x24c) + 0x2d5, 0, 2, -1, 1, 0, 0);
        return;
    }
    if (*(s32*)(this_ + 0x230) == 0xa || *(s32*)(this_ + 0x230) == 2) {
        rec.b1d = 0;
        rec.b1c = 0;
    }
    if (*(u8*)(this_ + 0xc4) != 0) {
        rec.b20 = 0;
        rec.b1d = fn_8023CB24(*(s32*)(this_ + 0xc8)) + 1;
        rec.b1c = fn_8023CA88(*(s32*)(this_ + 0xc8));
    }
    mode = -1;
    if (*(s32*)(this_ + 0x24c) < 2) {
        s32 st = *(s32*)(this_ + 0x230);
        if (st != 0xa && st != 0 && st != 6 && st != 7 && st != 8 && *(u8*)(this_ + 0xc4) == 0) {
            if (*(u32*)(this_ + 0x90) == 8 || *(u32*)(this_ + 0x90) == 9) {
                mode = 7;
            } else {
                mode = 0;
            }
        }
        if (st != 5) {
            fn_801F06F0(this_, lbl_80465D48, idx, &rec, mode, 1.0f, 1.0f);
        }
    }
    s32 r10 = 0;
    if (*(u8*)(this_ + 0xc4) == 0 && *(s32*)(this_ + 0x90) == 0xb) {
        r10 = 1;
    }
    fn_803075AC(*(void**)(this_ + 0x198), *(s32*)(this_ + 0x4), this_ + 0xc, idx, n != 0, 2, -1, r10, 0, 0);
}

extern "C" void* fn_8014CF28(u32* this_, s16 freeFlag) {
    if (this_ != 0) {
        u32* p = this_;
        s32 i = 0;
        *(char**)this_ = lbl_8049F784;
        do {
            fn_801EE434((void*)p[0xa4]);
            i++;
            p++;
        } while (i < 3);
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_8014CFBC(u8* this_) {
    struct VObj {
        virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
        virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09();
        virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
        virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
        virtual void v20(); virtual void v21();
    };
    s32 room;

    *(f32*)(this_ + 0x60) = -7.0f;
    *(f32*)(this_ + 0x64) = -7.0f;
    *(f32*)(this_ + 0x68) = 7.0f;
    *(f32*)(this_ + 0x6c) = 7.0f;
    *(f32*)(this_ + 0x80) = -7.0f;
    *(f32*)(this_ + 0x84) = -7.0f;
    *(f32*)(this_ + 0x88) = 7.0f;
    *(f32*)(this_ + 0x8c) = 7.0f;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(s32*)(this_ + 0x254) = 0;
    *(s32*)(this_ + 0x258) = 0;
    *(s32*)(this_ + 0x25c) = 0;
    *(s32*)(this_ + 0x260) = 0;
    *(s32*)(this_ + 0x264) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x108) = 2;
    *(s32*)(this_ + 0x26c) = 0;
    *(u8*)(this_ + 0x280) = 0;
    *(f32*)(this_ + 0x27c) = 1.0f;
    *(s32*)(this_ + 0x290) = 0;
    *(s32*)(this_ + 0x294) = 0;
    *(s32*)(this_ + 0x298) = 0;
    *(f32*)(this_ + 0x274) = 1.0f;
    *(s32*)(this_ + 0x268) = -1;
    *(s32*)(this_ + 0xb0) = 0x53308;
    *(u32*)(this_ + 0x270) = (*(u32*)(this_ + 0x90) >> 8) & 1;
    *(u32*)(this_ + 0x90) = *(u32*)(this_ + 0x90) & 0xff;
    *(u16*)(this_ + 0x94) = 0;
    *(s32*)(this_ + 0x260) = -1;
    *(f32*)(this_ + 0x278) = 0.0f;
    switch (*(u32*)(this_ + 0x90)) {
    case 10:
        *(s32*)(this_ + 0x248) = 0x14;
    case 0:
    case 8:
        *(s32*)(this_ + 0x238) = 0x12c;
        *(s32*)(this_ + 0x230) = 2;
        *(s32*)(this_ + 0xb0) = 0x73308;
        room = *(s32*)(this_ + 4);
        if (((u8*)fn_802D6A9C())[0x131df + room] != 0) {
            *(f32*)(this_ + 0x10) = *(f32*)(this_ + 0x10) - *(f32*)(this_ + 0x14);
            *(f32*)(this_ + 0x14) = 0.0f;
            *(f32*)(this_ + 0x44) = 0.0f;
        }
        if (*(u32*)(this_ + 0x90) == 8) {
            *(f32*)(this_ + 0x60) = -13.0f;
            *(f32*)(this_ + 0x64) = -13.0f;
            *(f32*)(this_ + 0x68) = 13.0f;
            *(f32*)(this_ + 0x6c) = 13.0f;
            *(f32*)(this_ + 0x274) = 2.0f;
        }
        if (*(s32*)(this_ + 0x294) == 0) {
            *(s32*)(this_ + 0x294) = fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, *(f32*)(this_ + 0x274), 0x66, 0, 0, 0, 0, 0);
        }
        if (*(s32*)(this_ + 0x298) == 0) {
            *(s32*)(this_ + 0x298) = fn_8013CC50(*(s32*)(this_ + 4), this_ + 0xc, *(f32*)(this_ + 0x274), 0x67, 0, 0, 0, 0, 0);
        }
        break;
    case 1:
        *(f32*)(this_ + 0x60) = 0.0f;
        *(f32*)(this_ + 0x64) = 0.0f;
        *(f32*)(this_ + 0x68) = 0.0f;
        *(f32*)(this_ + 0x6c) = 0.0f;
        *(f32*)(this_ + 0x274) = 0.0f;
        *(s32*)(this_ + 0xb0) = 0;
        *(s32*)(this_ + 0x230) = 9;
        break;
    case 2:
        *(f32*)(this_ + 0x274) = 0.0f;
    case 4:
        if (lbl_8053AAF8[0x7f] == 0) {
            *(u8*)(this_ + 0x11f) = 1;
            *(f32*)(this_ + 0x60) = -10.0f;
            *(f32*)(this_ + 0x64) = -10.0f;
            *(f32*)(this_ + 0x68) = 10.0f;
            *(f32*)(this_ + 0x6c) = 10.0f;
            *(s32*)(this_ + 0xb0) = 0x53303;
            *(s32*)(this_ + 0x230) = 10;
        } else {
            ((VObj*)lbl_8053AAF8)->v19();
        }
        break;
    case 7:
    case 11:
    case 12:
    case 13:
        *(s32*)(this_ + 0x24c) = 2;
        *(f32*)(this_ + 0x274) = 1.0f;
        if (*(s32*)(this_ + 0x90) == 13) {
            *(f32*)(this_ + 0x274) = 2.0f;
            *(f32*)(this_ + 0x27c) = 2.0f;
        }
        fn_801F0E34(this_, 0x30001, 0);
        *(s32*)(this_ + 0x234) = lbl_8049F760[*(s32*)(this_ + 0x24c)];
        *(s32*)(this_ + 0x230) = 4;
        break;
    default:
    case 5:
    case 6:
        *(s32*)(this_ + 0x240) = 0x32;
    case 3:
    case 9:
        *(s32*)(this_ + 0x240) = 0x32;
        if (*(u32*)(this_ + 0x90) == 9) {
            *(f32*)(this_ + 0x60) = -13.0f;
            *(f32*)(this_ + 0x64) = -13.0f;
            *(f32*)(this_ + 0x68) = 13.0f;
            *(f32*)(this_ + 0x6c) = 13.0f;
            *(f32*)(this_ + 0x274) = 2.0f;
        }
        *(s32*)(this_ + 0xb0) = 0x73308;
        *(s32*)(this_ + 0x230) = 0;
        break;
    }
}

extern "C" void fn_8014D304(u8* this_) {
    struct VObj {
        virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03(); virtual void v04();
        virtual void v05(); virtual void v06(); virtual void v07(); virtual void v08(); virtual void v09();
        virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14();
        virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
        virtual void v20(); virtual void v21();
    };
    ((VObj*)this_)->v19();
}

extern "C" void fn_8014D330(u8* this_) {
    f32 pos[3];
    f32 out[3];
    f32 zero = lbl_8053D128;

    *(f32*)(this_ + 0x44) = zero;
    *(f32*)(this_ + 0x40) = zero;
    *(f32*)(this_ + 0x3c) = zero;
    *(s32*)(this_ + 0xb0) = 0;
    fn_802D79E8(fn_802D6A9C(), *(u32*)(this_ + 4), 0, lbl_8053D1A4, lbl_8053D128);
    fn_80134DE4(lbl_8053AAF8, 1, 0);
    *(u16*)(this_ + 0x94) = 1;
    if (*(u32*)(this_ + 0x90) == 8 || *(u32*)(this_ + 0x90) == 9) {
        *(f32*)(this_ + 0x27c) = lbl_8053D174;
    }
    if (*(u32*)(this_ + 0x294) != 0) {
        forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((char*)fn_8013C824() + 0xc), *(void**)(this_ + 0x294));
        *(s32*)(this_ + 0x294) = 0;
    }
    if (*(u32*)(this_ + 0x298) != 0) {
        forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((char*)fn_8013C824() + 0xc), *(void**)(this_ + 0x298));
        *(s32*)(this_ + 0x298) = 0;
    }
    fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, *(f32*)(this_ + 0x27c), 0x59, 1, 1, 0, 0, 1);
    fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, *(f32*)(this_ + 0x27c), 0x5a, 1, 1, 0, 0, 1);
    fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, *(f32*)(this_ + 0x27c), 0x5b, 1, 1, 0, 0, 1);
    if (*(u32*)(this_ + 0x90) == 8 || *(u32*)(this_ + 0x90) == 9) {
        fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, lbl_8053D130, 0x5c, 1, 1, 0, 0, 1);
    }
    fn_801F0E34(this_, 0x30001, 0);
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x234) = lbl_8049F760[*(s32*)(this_ + 0x24c)];
    out[2] = out[1] = out[0] = lbl_8053D128;
    if (*(s32*)(this_ + 0x90) != 7 && *(s32*)(this_ + 0x90) != 0xd && *(s32*)(this_ + 0x90) != 0xb) {
        f32 a = lbl_8053D180;
        f32 b = lbl_8053D17C;
        *(f32*)(this_ + 0x60) = a;
        *(f32*)(this_ + 0x64) = a;
        *(f32*)(this_ + 0x68) = b;
        *(f32*)(this_ + 0x6c) = b;
        if (*(s32*)(this_ + 0x90) == 8 || *(s32*)(this_ + 0x90) == 9) {
            a = lbl_8053D184;
            b = lbl_8053D188;
            *(f32*)(this_ + 0x60) = a;
            *(f32*)(this_ + 0x64) = a;
            *(f32*)(this_ + 0x68) = b;
            *(f32*)(this_ + 0x6c) = b;
        }
    }
    if (*(u32*)(this_ + 0x90) != 0xc) {
        if (*(u32*)(this_ + 0x90) != 8 && *(u32*)(this_ + 0x90) != 9) {
            if (fn_8029EDB8(lbl_8053AC98, this_ + 0xc, 0, *(u32*)(this_ + 4), out) == 1) {
                fn_8014D868(this_, out);
            }
        } else {
            f32 k = lbl_8053D17C;
            f32 h = lbl_8053D134;
            for (s32 j = 0; j < 2; j++) {
                f32 fj = k * (f32)j;
                for (s32 i = 0; i < 2; i++) {
                    pos[0] = (*(f32*)(this_ + 0xc) - h) + fj;
                    pos[1] = (*(f32*)(this_ + 0x10) - h) + k * (f32)i;
                    pos[2] = *(f32*)(this_ + 0x14);
                    if (fn_8029EDB8(lbl_8053AC98, pos, 0, *(u32*)(this_ + 4), out) == 1) {
                        fn_8014D868(this_, out);
                    }
                }
            }
        }
    } else {
        fn_8029EDB8(lbl_8053AC98, this_ + 0xc, 0, *(u32*)(this_ + 4), out);
        *(s32*)(this_ + 0x230) = 5;
    }
}

extern "C" u16 fn_802265FC(f32* pos, s32 room);
extern "C" u8 fn_802DE9A0(void);
extern "C" u8 fn_802DEB58(void);
extern "C" f32 lbl_8053D128;
extern "C" f32 lbl_8053D12C;
extern "C" f32 lbl_8053D160;
extern "C" f32 lbl_8053D178;
extern "C" f32 lbl_8053D198;
extern "C" BOOL fn_8014D6DC(u8* this_) {
    f32 pos[2];
    f32 x;
    f32 y;
    f32 minX;
    f32 maxX;
    f32 minY;
    f32 maxY;

    if (*(f32*)(this_ + 0x14) > 0.1f) {
        return 0;
    }
    y = *(f32*)(this_ + 0x10);
    x = *(f32*)(this_ + 0xc);
    minX = x + -3.0f;
    maxX = x + 3.0f;
    minY = y + -3.0f;
    maxY = y + 3.0f;
    pos[0] = maxX + 0.5f * (minX - maxX);
    pos[1] = maxY + 0.5f * (minY - maxY);
    u16 kind = fn_802265FC(pos, *(s32*)(this_ + 4));
    if (kind == 3) {
        *(f32*)(this_ + 0x284) = *(f32*)(this_ + 0xc);
        *(f32*)(this_ + 0x288) = *(f32*)(this_ + 0x10);
        *(f32*)(this_ + 0x28c) = *(f32*)(this_ + 0x14);
        *(f32*)(this_ + 0x44) = 0.0f;
        *(f32*)(this_ + 0x40) = 0.0f;
        *(f32*)(this_ + 0x3c) = 0.0f;
        *(s32*)(this_ + 0x230) = 6;
        return 1;
    } else if (kind == 0xe) {
        *(f32*)(this_ + 0x284) = *(f32*)(this_ + 0xc);
        *(f32*)(this_ + 0x288) = *(f32*)(this_ + 0x10);
        *(f32*)(this_ + 0x28c) = *(f32*)(this_ + 0x14);
        *(f32*)(this_ + 0x44) = 0.0f;
        *(f32*)(this_ + 0x40) = 0.0f;
        *(f32*)(this_ + 0x3c) = 0.0f;
        if (fn_802DE9A0() == 1 || fn_802DEB58() == 1) {
            *(s32*)(this_ + 0x230) = 8;
        } else {
            *(s32*)(this_ + 0x230) = 6;
        }
        return 1;
    } else if (kind == 0xd || kind == 0x3b) {
        *(f32*)(this_ + 0x284) = *(f32*)(this_ + 0xc);
        *(f32*)(this_ + 0x288) = *(f32*)(this_ + 0x10);
        *(f32*)(this_ + 0x28c) = *(f32*)(this_ + 0x14);
        *(f32*)(this_ + 0x44) = 0.0f;
        *(f32*)(this_ + 0x40) = 0.0f;
        *(f32*)(this_ + 0x3c) = 0.0f;
        *(s32*)(this_ + 0x230) = 7;
        return 1;
    }
    return 0;
}

extern "C" void fn_8014D868(u8* this_, f32* pos) {
    s32 list[1024];
    s32 count = fn_801F7818(fn_801F856C(), 0x57415250, *(u32*)(this_ + 4), list, -1);
    for (s32 i = 0; i < count; i++) {
        u8* p = (u8*)list[i];
        if (p != 0) {
            f32 dx = *(f32*)(p + 0xc) - pos[0];
            f32 dz = *(f32*)(p + 0x10) - pos[1];
            f32 dist = dolsqrtfull(dx * dx + dz * dz);
            if (dist < 24.0f) {
                u32 type = (*(u32*)(p + 0x90) >> 24) & 7;
                f32* q = (f32*)(p + 0x238);
                s32 id = type + 7;
                if (type == 0) {
                    id = type;
                }
                Actor_CreateByID(fn_801F856C(), 0x48424d42, id, q, 0xc, -1, -1);
            }
        }
    }
}

extern "C" void fn_8014DA20(u8* this_) {
    s32 idx = *(s32*)(this_ + 0xa0);
    if (idx >= 0) {
        void* p = fn_801F666C(fn_801F856C(), idx);
        if (p != 0 && *(u32*)((u8*)p + 0x1a0) == 0x41525257) {
            fn_8013CB44(*(void**)(this_ + 0x294), this_ + 0xc, 0, 0, 0);
            fn_8013CB44(*(void**)(this_ + 0x298), this_ + 0xc, 0, 0, 0);
        }
    }
}
#include "JSystem/JAudio/JASFakeMatchFSA.h"
