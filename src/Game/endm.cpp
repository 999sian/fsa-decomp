// TU 0x802e9428-0x802eb21c (actor ENDM).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"
#include "JSystem/JGeometry/Box.h"
#include "JSystem/JMath/JMath.h"
#include "JSystem/JGeometry/Util.h"

extern char* lbl_8053AB10;
extern "C" void fn_8030C7C4(void* mgr, f32* pos, f32 f);

// ---- Endm_dtor_802E9428.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804AA0FC[];

extern "C" void* fn_802E9428(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804AA0FC;
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

// ---- Endm_EmptyHook.cpp ----
// Endm_EmptyHook - ENDM: empty no-op override (0x4, leaf, no extab needed)
extern "C" {

void Endm_EmptyHook(void) {}

}

// fn_802E948C - ENDM: start a move towards target over n frames; returns 0
// (int->float constant 0x805412F0 is compiler-generated: the TU must own its
// .sdata2 before it can link.)
// when already there.
extern "C" u8 fn_802E948C(char* p, f32 target, s32 frames) {
    f32 cur = *(f32*)(p + 0x270);
    if (cur == target) {
        return 0;
    }
    f32 step = __fabsf(cur - target) / (f32)frames;
    if (cur < target) {
        *(f32*)(p + 0x278) = step;
    } else {
        *(f32*)(p + 0x278) = -step;
    }
    *(f32*)(p + 0x274) = target;
    return 1;
}

extern "C" void fn_802E94F4(char* p) {
    JGeometry::TVec3<f32> vel;
    JGeometry::TBox2<f32> bounds;
    JGeometry::TVec2<f32> pos;
    JGeometry::TVec2<f32> tmp;
    f32 tx;
    f32 ty;
    ty = *(f32*)(p + 0x248);
    tx = *(f32*)(p + 0x244);
    if (*(u8*)(p + 0x298)) {
        *(f32*)(p + 0x250) = tx;
        *(f32*)(p + 0x254) = ty;
    } else {
        vel = *(JGeometry::TVec3<f32>*)(*(char**)(p + 0x240) + 0x3c);
        f32 dx = *(f32*)(p + 0x250) - tx;
        f32 dy = *(f32*)(p + 0x254) - ty;
        f32 dx2 = dx * dx;
        f32 dy2 = dy * dy;
        f32 dist = JGeometry::TUtil<f32>::sqrt(dx2 + dy2);
        f32 speed = PSVECMag((Vec*)&vel);
        if (dist <= 1.5f * speed) {
            *(f32*)(p + 0x250) = tx;
            *(f32*)(p + 0x254) = ty;
            *(u8*)(p + 0x298) = 1;
        } else if (dist <= 2.0f * speed) {
            *(f32*)(p + 0x250) += (*(f32*)(p + 0x244) - *(f32*)(p + 0x250)) * 0.5f;
            *(f32*)(p + 0x254) += (*(f32*)(p + 0x248) - *(f32*)(p + 0x254)) * 0.5f;
        } else if (0.1f * dist < 2.5f) {
            f32 cx, cy;
            *(f32*)(p + 0x250) = (*(f32*)(p + 0x244) - (cx = *(f32*)(p + 0x250))) * 0.1f + cx;
            *(f32*)(p + 0x254) = (*(f32*)(p + 0x248) - (cy = *(f32*)(p + 0x254))) * 0.1f + cy;
        } else {
            f32 ang = JMath::atanTable_.atan2_(*(f32*)(p + 0x248) - *(f32*)(p + 0x254), *(f32*)(p + 0x244) - *(f32*)(p + 0x250));
            f32 scale = 10430.4f;
            s16 idx = (s16)(ang * scale);
            *(f32*)(p + 0x250) = 2.5f * JMACosShort(idx) + *(f32*)(p + 0x250);
            *(f32*)(p + 0x254) = 2.5f * JMASinShort(idx) + *(f32*)(p + 0x254);
        }
    }
    {
        f32* dummy = &tmp.x;
        f32 y0;
        f32 x0;
        x0 = *(f32*)(p + 0x250);
        y0 = *(f32*)(p + 0x254);
        JGeometry::TVec2<f32> off(0.0f, -30.0f);
        tmp.x = x0;
        tmp.y = y0;
        pos.x = x0 + off.x;
        f64 d = pos.x;
        f32 px = (f32)d;
        pos.y = y0 + off.y;
        bounds = *(JGeometry::TBox2<f32>*)(*(char**)(lbl_8053AB10 + 0x24) + 0x164);
        tmp.x = pos.x;
        tmp.y = pos.y;
        f32 half = 0.5f;
        f32 w = bounds.f.x - bounds.i.x;
        f32 hw = w * half;
        f32 h = bounds.f.y - bounds.i.y;
        f32 hh = h * half;
        f32 hh2 = h * half;
        if (px + hw >= *(f32*)(p + 0x268)) {
            pos.x = *(f32*)(p + 0x268) - hw;
        } else if (px - hw <= *(f32*)(p + 0x260)) {
            pos.x = *(f32*)(p + 0x260) + hw;
        }
        if (pos.y + hh >= *(f32*)(p + 0x26c)) {
            pos.y = *(f32*)(p + 0x26c) - hh2;
        } else if (pos.y - h * half <= *(f32*)(p + 0x264)) {
            pos.y = *(f32*)(p + 0x264) + h * half;
        }
    }
    if (*(f32*)(p + 0x270) != *(f32*)(p + 0x274)) {
        *(f32*)(p + 0x270) = *(f32*)(p + 0x270) + *(f32*)(p + 0x278);
        if (*(f32*)(p + 0x278) < 0.0f) {
            if (*(f32*)(p + 0x270) < *(f32*)(p + 0x274)) {
                *(f32*)(p + 0x270) = *(f32*)(p + 0x274);
            }
        } else {
            if (*(f32*)(p + 0x270) > *(f32*)(p + 0x274)) {
                *(f32*)(p + 0x270) = *(f32*)(p + 0x274);
            }
        }
    }
    fn_8030C7C4(*(void**)(lbl_8053AB10 + 0x24), &pos.x, (f32)(s32)*(f32*)(p + 0x270));
}

extern "C" void* fn_802D6A9C(void);
// fn_802E9884 - ENDM: screen-edge check of the scroll position.
extern "C" void fn_802D9CB0(void* rec);
extern "C" u8 fn_802E9884(char* p, const f32* __restrict pos) {
    s32 xm = (s32)pos[0] % 512;
    s32 ym = (s32)pos[1] % 384 - 30;
    if (*(u8*)(p + 0x297) == 0) {
        u8 d = **(u8**)(p + 0x290);
        if (d == 0xff) {
            *(s32*)(p + 0x23c) = 7;
            return 0;
        }
        switch (d) {
        case 0:
            if (ym - ((s32)*(f32*)(p + 0x270) * 3 / 4) / 2 < 0x10) {
                return 1;
            }
            break;
        case 1:
            if (ym + ((s32)*(f32*)(p + 0x270) * 3 / 4) / 2 > 0x170) {
                return 1;
            }
            break;
        case 2:
            if (xm - (s32)*(f32*)(p + 0x270) / 2 < 0x10) {
                return 1;
            }
            break;
        case 3:
            if (xm + (s32)*(f32*)(p + 0x270) / 2 > 0x1f0) {
                return 1;
            }
            break;
        }
    } else {
        s32 v;
        switch (*(u8*)(p + 0x28d)) {
        case 0:
            v = ym + ((s32)*(f32*)(p + 0x270) * 3 / 4) / 2;
            if (v < 0x170 && v > 0x160) {
                *(u8*)(p + 0x297) = 0;
            }
            break;
        case 1:
            v = ym - ((s32)*(f32*)(p + 0x270) * 3 / 4) / 2;
            if (v > 0x20 && v < 0x30) {
                *(u8*)(p + 0x297) = 0;
            }
            break;
        case 2:
            v = xm + (s32)*(f32*)(p + 0x270) / 2;
            if (v < 0x1f0 && v > 0x1e0) {
                *(u8*)(p + 0x297) = 0;
            }
            break;
        case 3:
            v = xm - (s32)*(f32*)(p + 0x270) / 2;
            if (v > 0x10 && v < 0x20) {
                *(u8*)(p + 0x297) = 0;
            }
            break;
        }
        if (*(u8*)(p + 0x297) == 0) {
            fn_802D9CB0(fn_802D6A9C());
        }
    }
    return 0;
}

extern void* lbl_8053AF30;
extern void* lbl_8053AEF0;
extern void* lbl_8053AED0;
#pragma pool_data on
const u8 lbl_8046F280[] = {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,2,0,0,0,2,0,0,0,2,0,0,0,3,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,5,0,0,0,5,0,0,0,6,0,0,0,7,0,0,0,7};
const u32 Endm_layers[] = {0,0,0,1,1,1,1,0,1,3,3,0,0,0,0,3,3};
const s16 Endm_times[] = {180,180,180,180,180,180,180,180,180,180,180,180,180,180,180,180,180};
const u16 Endm_paths[] = {13,0,13,1,13,2,13,3,14,0,14,1,14,2,14,3,15,0,15,1,16,3,15,2,15,3,17,0,16,0,16,1,16,2};
const u8 Endm_fades[] = {0,0,1,1,2,2,2,3,3,3,3,4,5,5,6,7,7,0,0,0};
const u8 Endm_effects[] = {1,0,1,1,1,0,0,1,1,1,0,1,1,0,1,0,0,0,0,0};
#pragma pool_data reset
extern "C" char lbl_804D56A8[];
extern "C" char lbl_804D5730[];
extern u8* lbl_804AA0B8[];
extern const f32 lbl_80541318;
extern const f32 lbl_805412EC;
extern const f32 lbl_8054131C;
extern const f32 lbl_80541320;
extern const f32 lbl_80541324;
extern const f32 lbl_80541328;
extern const f32 lbl_8054132C;
extern const f32 lbl_80541330;
extern const f32 lbl_80541334;
extern "C" void* fn_80119DD0();
extern "C" void fn_80119958(void*);
extern "C" void fn_80119998(void*, int, int, int, int, int, int, int);
extern "C" char* fn_8016A3AC();
extern "C" void fn_8016A2B4(void*);
extern "C" u8 fn_8044B80C(void*, u8);
extern "C" void fn_804432DC(void*, u8, int, int);
extern "C" void fn_8043A268(void*, int, int, s16, f32, f32);
extern "C" void fn_802D9CD8(void*);
extern "C" char* fn_801F856C();
extern "C" void fn_802DCD1C(void*, s32*);
extern "C" void fn_803613D0(void*);
extern "C" void fn_80362634(void*);
extern "C" void fn_8036E544(void*);
static inline void Endm_updateView(char* p) {
    JGeometry::TBox2<f32> bounds;
    JGeometry::TVec2<f32> pos;
    JGeometry::TVec2<f32> tmp;
    {
        f32* dummy = &tmp.x;
        f32 y0;
        f32 x0;
        x0 = *(f32*)(p + 0x250);
        y0 = *(f32*)(p + 0x254);
        JGeometry::TVec2<f32> off(0.0f, -30.0f);
        tmp.x = x0;
        tmp.y = y0;
        pos.x = x0 + off.x;
        f64 d = pos.x;
        f32 px = (f32)d;
        pos.y = y0 + off.y;
        bounds = *(JGeometry::TBox2<f32>*)(*(char**)(lbl_8053AB10 + 0x24) + 0x164);
        tmp.x = pos.x;
        tmp.y = pos.y;
        f32 half = 0.5f;
        f32 w = bounds.f.x - bounds.i.x;
        f32 hw = w * half;
        f32 h = bounds.f.y - bounds.i.y;
        f32 hh = h * half;
        f32 hh2 = h * half;
        if (px + hw >= *(f32*)(p + 0x268)) {
            pos.x = *(f32*)(p + 0x268) - hw;
        } else if (px - hw <= *(f32*)(p + 0x260)) {
            pos.x = *(f32*)(p + 0x260) + hw;
        }
        if (pos.y + hh >= *(f32*)(p + 0x26c)) {
            pos.y = *(f32*)(p + 0x26c) - hh2;
        } else if (pos.y - h * half <= *(f32*)(p + 0x264)) {
            pos.y = *(f32*)(p + 0x264) + h * half;
        }
    }
    if (*(f32*)(p + 0x270) != *(f32*)(p + 0x274)) {
        *(f32*)(p + 0x270) = *(f32*)(p + 0x270) + *(f32*)(p + 0x278);
        if (*(f32*)(p + 0x278) < 0.0f) {
            if (*(f32*)(p + 0x270) < *(f32*)(p + 0x274)) {
                *(f32*)(p + 0x270) = *(f32*)(p + 0x274);
            }
        } else {
            if (*(f32*)(p + 0x270) > *(f32*)(p + 0x274)) {
                *(f32*)(p + 0x270) = *(f32*)(p + 0x274);
            }
        }
    }
    fn_8030C7C4(*(void**)(lbl_8053AB10 + 0x24), &pos.x, (f32)(s32)*(f32*)(p + 0x270));
}
static inline u8 Endm_tick(s32* timer) {
    if (*timer) --*timer;
    return (u32)__cntlzw(*timer) >> 5;
}

extern "C" void fn_802E9B6C(char* p) {
    const u8* data = lbl_8046F280;
    ++*(s32*)(p + 0x234);
    switch (*(s32*)(p + 0x23c)) {
    case 0:
    again:
        if (*(u8*)(p + 0x29a)) {
    begin:
        *(u8*)(p + 0x29a) = 0;
        if (*(u8*)(p + 0x294) == 0) *(s32*)(p + 0x27c) = 300;
        else if (*(u8*)(p + 0x294) == 7) *(s32*)(p + 0x27c) = 480;
        else *(s32*)(p + 0x27c) = 420;
        *((u8*)lbl_8053AF30 + 0x14) = 1;
        ++*(u8*)(p + 0x294);
        if (*(u8*)(p + 0x294) > 7) *(u8*)(p + 0x294) = 7;
        *(s32*)(p + 0x23c) = 1;
        if (*(u8*)(p + 0x299) == 1) {
            fn_80119958(fn_80119DD0());
            fn_80119998(fn_80119DD0(), 50, 0, 0, 0, 0, 0, 0);
            *(u8*)(p + 0x299) = 0;
        }
        char* mgr = fn_8016A3AC();
        *(s32*)(mgr + 0x1d8) = -1;
        fn_8016A2B4(fn_8016A3AC());
        } else {
            *(u8*)(p+0x29a)=fn_8044B80C(lbl_8053AF30, *(u8*)(p+0x294));
            if (*(u8*)(p+0x29a)==1) goto begin;
        }
        break;
    case 1:
        *((u8*)lbl_8053AF30 + 0x14) = 1;
        if (Endm_tick((s32*)(p + 0x27c))) {
            fn_80119998(fn_80119DD0(), 100, 0, 2, 0, 0, 20, 0);
            *(s32*)(p + 0x27c) = 60;
            *(s32*)(p + 0x23c) = 2;
        }
        break;
    case 2:
        if (Endm_tick((s32*)(p + 0x27c))) {
            if (*(u8*)(p + 0x230) == 15) *(s32*)(p + 0x23c) = 4;
            else *(s32*)(p + 0x23c) = 3;
        } else *((u8*)lbl_8053AF30 + 0x14) = 1;
        break;
    case 3:
        if (((const u8 (*)[20])(data+0xf0))[0][*(u8*)(p+0x230)] == 0) {
            fn_804432DC(lbl_8053AEF0, ((const u8 (*)[20])(data+0xf0))[0][*(u8*)(p+0x230)], 200, 200);
            *(s32*)(p + 0x27c) = 430;
        } else {
            fn_804432DC(lbl_8053AEF0, ((const u8 (*)[20])(data+0xf0))[0][*(u8*)(p+0x230)], 0, 200);
            *(s32*)(p + 0x27c) = 200;
        }
        *(s32*)(p + 0x23c) = 4;
        *(u8*)(p + 0x28c) = *(u8*)(p + 0x230) * 2;
        break;
    case 4:
        if (Endm_tick((s32*)(p + 0x27c))) {
            int n = *(u8*)(p + 0x230);
            if (data[0x104 + n]) {
                fn_8043A268(lbl_8053AED0, ((int*)data)[n], ((int*)(data+0x44))[n],
                    ((s16*)(data+0x88))[n], ((f32*)lbl_804D56A8)[n*2], ((f32*)lbl_804D56A8)[n*2+1]);
            }
            *(f32*)(p + 0x274) = lbl_80541318;
            f32 cur = *(f32*)(p + 0x270);
            if (cur != lbl_80541318) {
                f32 step = __fabsf(cur - lbl_80541318) / lbl_8054131C;
                if (cur < lbl_80541318) *(f32*)(p + 0x278) = step;
                else *(f32*)(p + 0x278) = -step;
                *(f32*)(p + 0x274) = lbl_80541318;
            }
            u32 a = ((u16*)(data+0xac))[*(u8*)(p+0x28c)];
            u32 b = ((u16*)(data+0xac))[*(u8*)(p+0x28c)+1];
            char* rec = (char*)fn_802D6A9C();
            *(u32*)(rec+4)=a; *(u32*)(rec+8)=b;
            fn_802D9CD8(fn_802D6A9C());
            u32 oldA=*(u32*)(p+0x280), oldB=*(u32*)(p+0x284);
            rec=(char*)fn_802D6A9C();
            *(u32*)(rec+4)=oldB; *(u32*)(rec+8)=oldA;
            s32 count=*(s32*)(fn_801F856C()+0x1008);
            for (s32 i=0;i<count;++i) {
                *(char**)(p+0x240)=*(char**)(fn_801F856C()+8+i*4);
                char* actor=*(char**)(p+0x240);
                if (!actor || *(u32*)(actor+0x1a0)!=0x454f574c || *(u8*)(actor+0x11c)!=1 || (*(u32*)(actor+0x90)&0x100)) continue;
                if (*(u8*)(p+0x230)>=4 && *(u8*)(p+0x230)<=6 && !(*(u32*)(actor+0x90)&7)) continue;
                *(s32*)(p+0x23c)=5;
                *(JGeometry::TVec3<f32>*)(p+0x244)=*(JGeometry::TVec3<f32>*)(*(char**)(p+0x240)+0xc);
                const f32* point=(f32*)lbl_804D5730 + *(u8*)(p+0x230)*2;
                *(f32*)(p+0x250)=point[0];
                *(f32*)(p+0x254)=point[1];
                JGeometry::TVec2<f32> pos(*(f32*)(p+0x250), -30.0f+*(f32*)(p+0x254));
                fn_8030C7C4(*(void**)(lbl_8053AB10+0x24), &pos.x, (f32)(s32)*(f32*)(p+0x270));
                *(u8**)(p+0x290)=lbl_804AA0B8[*(u8*)(p+0x230)];
                *(f32*)(p+0x260)=lbl_80541320*(s32)(*(f32*)(p+0x250)*lbl_80541324);
                *(f32*)(p+0x264)=lbl_80541328*(s32)(*(f32*)(p+0x254)/lbl_80541328);
                if (*(u8*)(p+0x230)==5) *(f32*)(p+0x26c)-=lbl_8054132C;
                else if (*(u8*)(p+0x230)==16) *(f32*)(p+0x260)+=lbl_80541330;
                *(f32*)(p+0x268)=lbl_80541320+*(f32*)(p+0x260);
                *(f32*)(p+0x26c)=lbl_80541328+*(f32*)(p+0x264);
                u8 d=**(u8**)(p+0x290);
                if(d==0xff) return;
                if(d==0) *(f32*)(p+0x264)-=lbl_80541328;
                else if(d==1) *(f32*)(p+0x26c)+=lbl_80541328;
                else if(d==2) *(f32*)(p+0x260)-=lbl_80541320;
                else if(d==3) *(f32*)(p+0x268)+=lbl_80541320;
                return;
            }
            *(u8*)(p+0x11c)=0;
        } else if (*(s32*)(p+0x27c)==60) fn_80119998(fn_80119DD0(),100,0,2,0,0,20,0);
        break;
    case 5: {
        *(JGeometry::TVec3<f32>*)(p+0x244)=*(JGeometry::TVec3<f32>*)(*(char**)(p+0x240)+0xc);
        if (*(s32*)(*(char**)(p+0x240)+0x230)==1) {
            fn_802E94F4(p);
            *(u8*)(p+0x297)=1;
        } else {
            *(u8*)(p+0x298)=0;
            Endm_updateView(p);
            break;
        }
        *(u8*)(p+0x28d)=**(u8**)(p+0x290);
        if (*(u8*)(p+0x28d)==0xff) { *(s32*)(p+0x23c)=7; break; }
        u32 a=((u16*)(data+0xac))[*(u8*)(p+0x28c)];
        u32 b=((u16*)(data+0xac))[*(u8*)(p+0x28c)+1];
        char* rec=(char*)fn_802D6A9C();
        *(u32*)(rec+4)=a; *(u32*)(rec+8)=b;
        if (*(u8*)(p+0x28d)==0) { s32 v[2]; v[0]=0; v[1]=-1; fn_802DCD1C(fn_802D6A9C(),v); }
        else if (*(u8*)(p+0x28d)==1) { s32 v[2]; v[0]=0; v[1]=1; fn_802DCD1C(fn_802D6A9C(),v); }
        else if (*(u8*)(p+0x28d)==2) { s32 v[2]; v[0]=-1; v[1]=0; fn_802DCD1C(fn_802D6A9C(),v); }
        else if (*(u8*)(p+0x28d)==3) { s32 v[2]; v[0]=1; v[1]=0; fn_802DCD1C(fn_802D6A9C(),v); }
        u32 oldA=*(u32*)(p+0x280), oldB=*(u32*)(p+0x284);
        rec=(char*)fn_802D6A9C();
        *(u32*)(rec+4)=oldB; *(u32*)(rec+8)=oldA;
        *(s32*)(p+0x23c)=6;
        *(u16*)(p+0x288)=(s32)(*(f32*)(p+0x244)*lbl_80541324);
        *(u16*)(p+0x28a)=(s32)(*(f32*)(p+0x248)/lbl_80541328);
        if (**(u8**)(p+0x290)!=0xff) {
            *(f32*)(p+0x260)=lbl_80541320*(s32)(*(f32*)(p+0x250)*lbl_80541324);
            *(f32*)(p+0x264)=lbl_80541328*(s32)(*(f32*)(p+0x254)/lbl_80541328);
            *(f32*)(p+0x268)=lbl_80541320+*(f32*)(p+0x260);
            *(f32*)(p+0x26c)=lbl_80541328+*(f32*)(p+0x264);
            if (*(u8*)(p+0x230)==5) *(f32*)(p+0x26c)-=lbl_8054132C;
            else if (*(u8*)(p+0x230)==16) *(f32*)(p+0x260)+=lbl_80541330;
            u8 d=**(u8**)(p+0x290);
            if(d==0) *(f32*)(p+0x264)-=lbl_80541328;
            else if(d==1) *(f32*)(p+0x26c)+=lbl_80541328;
            else if(d==2) *(f32*)(p+0x260)-=lbl_80541320;
            else if(d==3) *(f32*)(p+0x268)+=lbl_80541320;
        }
        ++*(u8**)(p+0x290);
        break;
    }
    case 6: {
        *(JGeometry::TVec3<f32>*)(p+0x244)=*(JGeometry::TVec3<f32>*)(*(char**)(p+0x240)+0xc);
        fn_802E94F4(p);
        if (*(u16*)(p+0x288)!=(u16)(s32)(*(f32*)(p+0x244)*lbl_80541324) ||
            *(u16*)(p+0x28a)!=(u16)(s32)(*(f32*)(p+0x248)/lbl_80541328)) {
            JGeometry::TVec3<f32> pos=*(JGeometry::TVec3<f32>*)(p+0x244);
            if(fn_802E9884(p,&pos.x)) {
                *(s32*)(p+0x23c)=5; *(u8*)(p+0x297)=1;
            }
        }
        break;
    }
    case 7:
        if(!*(u8*)(p+0x29a)) *(u8*)(p+0x29a)=fn_8044B80C(lbl_8053AF30,*(u8*)(p+0x294));
        if(!*(s32*)(p+0x27c)) {
            *(JGeometry::TVec3<f32>*)(p+0x244)=*(JGeometry::TVec3<f32>*)(*(char**)(p+0x240)+0xc);
            fn_802E94F4(p);
            s32 state=*(s32*)(*(char**)(p+0x240)+0x230);
            if(state==2 || state==3) { *(u8*)(p+0x295)=state; *(s32*)(p+0x27c)=200; }
        } else {
            Endm_updateView(p);
            --*(s32*)(p+0x27c);
            if(!*(s32*)(p+0x27c)) goto finish;
            JGeometry::TVec3<f32> pos=*(JGeometry::TVec3<f32>*)(*(char**)(p+0x240)+0xc);
            JGeometry::TBox2<f32> box;
            box=*(JGeometry::TBox2<f32>*)(*(char**)(lbl_8053AB10+0x24)+0x164);
            if(!(*(u32*)(*(char**)(p+0x240)+0x90)&7)) {
                box.f.x+=lbl_80541334; box.i.x-=lbl_80541334;
                box.f.y+=lbl_80541334; box.i.y-=lbl_80541334;
            }
            u8 inside=0;
            if(pos.x>=box.i.x && pos.y>=box.i.y && pos.x<box.f.x && pos.y<box.f.y) inside=1;
            if(!inside || !*(u8*)(*(char**)(p+0x240)+0x11c)) {
            finish:
                *(s32*)(p+0x27c)=60;
                fn_80119998(fn_80119DD0(),100,0,2,0,0,20,0);
                *(s32*)(p+0x23c)=8;
            }
        }
        break;
    case 8:
        if(Endm_tick((s32*)(p+0x27c))) {
            if(*(u8*)(p+0x295)==2) *(s32*)(p+0x23c)=0;
            else { *(s32*)(p+0x23c)=4; *(s32*)(p+0x27c)=10; }
            ++*(u8*)(p+0x230);
            *(u8*)(p+0x28c)=*(u8*)(p+0x230)*2;
            const f32* point=(f32*)lbl_804D5730 + *(u8*)(p+0x230)*2;
            *(f32*)(p+0x258)=point[0];
            *(f32*)(p+0x25c)=point[1];
            *(f32*)(p+0xc)=*(f32*)(p+0x258);
            *(f32*)(p+0x10)=*(f32*)(p+0x25c);
            *(char**)(p+0x240)=0;
            s32 count=*(s32*)(fn_801F856C()+0x1008);
            for(s32 i=0;i<count;++i) {
                char* a=*(char**)(fn_801F856C()+8+i*4);
                if(!a || *(u8*)(a+0x11c)!=1) continue;
                u32 id=*(u32*)(a+0x1a0);
                if(id==0x454f574c) { fn_803613D0(a); *(u8*)(a+0x11c)=0; }
                else if(id==0x45455443) { fn_80362634(a); *(u8*)(a+0x11c)=0; }
                else if(id==0x454c4b32) { fn_8036E544(a); *(u8*)(a+0x11c)=0; }
                else if(id==0x52555059) *(u8*)(a+0x11c)=0;
            }
            *(u8*)(p+0x231)=0;
        } else Endm_updateView(p);
        break;
    }
    if(*(char**)(p+0x240) && *(s32*)(p+0x23c)<7)
        *(JGeometry::TVec3<f32>*)(p+0xc)=*(JGeometry::TVec3<f32>*)(p+0x244);
}

// fn_802EACC8 - ENDM: setParams().
extern "C" void* fn_802D6A9C(void);
extern const f32 lbl_80541318;
extern const f32 lbl_805412EC;
extern void* lbl_8053AF80;
extern void* lbl_8053AF30;
extern "C" void fn_80458FF0(void* obj, u32 id, s32 a, s32 b);
extern "C" u8 fn_8044B80C(void* obj, u8 v);
extern "C" void fn_802EACC8(char* p) {
    *(s32*)(p + 0x284) = *(s32*)((char*)fn_802D6A9C() + 0x4);
    *(s32*)(p + 0x280) = *(s32*)((char*)fn_802D6A9C() + 0x8);
    *(s32*)(p + 0x23c) = 0;
    *(u8*)(p + 0x230) = 0;
    *(u8*)(p + 0x28d) = 0;
    *(u8*)(p + 0x298) = 0;
    *(s32*)(p + 0x240) = 0;
    *(u8*)(p + 0x294) = 0;
    *(u8*)(p + 0x295) = 0;
    *(u8*)(p + 0x299) = 1;
    *(f32*)(p + 0x270) = lbl_80541318;
    *(f32*)(p + 0x274) = lbl_80541318;
    *(f32*)(p + 0x278) = lbl_805412EC;
    fn_80458FF0(lbl_8053AF80, 0x1000028, 1, 0);
    *(s32*)(p + 0x234) = 0;
    *(u8*)(p + 0x231) = 0;
    *(u8*)(p + 0x29a) = fn_8044B80C(lbl_8053AF30, *(u8*)(p + 0x294));
}

extern "C" char lbl_804D56A8[];
extern "C" void __ct__17JASGenericMemPoolFv(void*);
extern "C" void __register_global_object(void*, void (*)(void*), void*);
extern "C" void __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv(void*);
extern "C" char memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr[];
extern "C" char __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr;
extern "C" void __dt__35JASMemPool_MultiThreaded_8JASTrackFv(void*);
extern "C" char memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack[];
extern "C" char __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack;
extern "C" void __dt__38JASMemPool_MultiThreaded_10JASChannelFv(void*);
extern "C" char memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel[];
extern "C" char __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel;
extern "C" void __dt__29JASMemPool_15JASPoolObj3_FSAFv(void*);
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj3_FSA[];
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA;
extern "C" void __dt__29JASMemPool_15JASPoolObj4_FSAFv(void*);
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj4_FSA[];
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA;
extern "C" void __dt__22JASMemPool_9JAIStreamFv(void*);
extern "C" char memPool___30JASPoolAllocObject_9JAIStream[];
extern "C" char __init__memPool___30JASPoolAllocObject_9JAIStream;
extern "C" void __dt__27JASMemPool_13JAISoundChildFv(void*);
extern "C" char memPool___35JASPoolAllocObject_13JAISoundChild[];
extern "C" char __init__memPool___35JASPoolAllocObject_13JAISoundChild;
extern "C" void __dt__19JASMemPool_6JAISeqFv(void*);
extern "C" char memPool___27JASPoolAllocObject_6JAISeq[];
extern "C" char __init__memPool___27JASPoolAllocObject_6JAISeq;
extern "C" void __dt__18JASMemPool_5JAISeFv(void*);
extern "C" char memPool___26JASPoolAllocObject_5JAISe[];
extern "C" char __init__memPool___26JASPoolAllocObject_5JAISe;
extern "C" f32 lbl_80541338;
extern "C" f32 lbl_8054133C;
extern "C" f32 lbl_80541340;
extern "C" f32 lbl_80541344;
extern "C" f32 lbl_80541348;
extern "C" f32 lbl_8054134C;
extern "C" f32 lbl_80541350;
extern "C" f32 lbl_80541354;
extern "C" f32 lbl_80541358;
extern "C" f32 lbl_8054135C;
extern "C" f32 lbl_80541360;
extern "C" f32 lbl_80541364;
extern "C" f32 lbl_80541368;
extern "C" f32 lbl_8054136C;
extern "C" f32 lbl_80541370;
extern "C" f32 lbl_80541374;
extern "C" f32 lbl_80541378;
extern "C" f32 lbl_8054137C;
extern "C" f32 lbl_80541380;
extern "C" f32 lbl_80541384;
extern "C" f32 lbl_80541388;
extern "C" f32 lbl_8054138C;
extern "C" f32 lbl_80541390;
extern "C" f32 lbl_80541394;
extern "C" f32 lbl_80541398;
extern "C" f32 lbl_8054139C;
extern "C" f32 lbl_805413A0;
extern "C" f32 lbl_805413A4;
extern "C" f32 lbl_805413A8;
extern "C" f32 lbl_805413AC;
#pragma opt_propagation off
extern "C" void fn_802EAD78(void) {
    f32 v28;
    f32 v27;
    f32 v26;
    f32 v25;
    f32 v24;
    f32 v23;
    f32 v22;
    f32 v21;
    f32 v20;
    f32 v19;
    f32 v18;
    f32 v17;
    f32 v16;
    f32 v15;
    f32 v14;
    f32 v13;
    f32 v12;
    f32 v11;
    f32 v10;
    f32 v9;
    f32 v8;
    f32 v7;
    f32 v6;
    f32 v5;
    f32 v4;
    f32 v3;
    f32 v2;
    f32 v1;
    f32 v0;
    v0 = lbl_80541338;
    v2 = lbl_80541340;
    v1 = lbl_8054133C;
    v3 = lbl_80541344;
    v15 = lbl_80541374;
    v5 = lbl_8054134C;
    v4 = lbl_80541348;
    v6 = lbl_80541350;
    v7 = lbl_80541354;
    v8 = lbl_80541358;
    v9 = lbl_8054135C;
    v10 = lbl_80541360;
    v11 = lbl_80541364;
    v12 = lbl_80541368;
    v13 = lbl_8054136C;
    v14 = lbl_80541370;
    v16 = lbl_80541378;
    v17 = lbl_8054137C;
    v18 = lbl_80541380;
    v19 = lbl_80541384;
    v20 = lbl_80541388;
    v21 = lbl_8054138C;
    v22 = lbl_80541390;
    v23 = lbl_80541394;
    v24 = lbl_80541398;
    v25 = lbl_8054139C;
    v26 = lbl_805413A0;
    v27 = lbl_805413A4;
    v28 = lbl_805413A8;
    char* base = lbl_804D56A8;
    f32 (*pts)[34] = (f32 (*)[34])base;
    f32 (*tail)[34] = (f32 (*)[34])(base + 0x88);
    (*pts)[0] = v0;
    (*pts)[1] = v1;
    (*pts)[2] = v0;
    (*pts)[3] = v1;
    (*pts)[4] = v0;
    (*pts)[5] = v1;
    (*pts)[6] = v0;
    (*pts)[7] = v1;
    (*pts)[8] = v0;
    (*pts)[9] = v1;
    (*pts)[10] = v0;
    (*pts)[11] = v1;
    (*pts)[12] = v0;
    (*pts)[13] = v1;
    (*pts)[14] = v0;
    (*pts)[15] = v1;
    (*pts)[16] = v0;
    (*pts)[17] = v1;
    (*pts)[18] = v0;
    (*pts)[19] = v1;
    (*pts)[20] = v0;
    (*pts)[21] = v1;
    (*pts)[22] = v0;
    (*pts)[23] = v1;
    (*pts)[24] = v0;
    (*pts)[25] = v1;
    (*pts)[26] = v0;
    (*pts)[27] = v1;
    (*pts)[28] = v0;
    (*pts)[29] = v1;
    (*pts)[30] = v0;
    (*pts)[31] = v1;
    (*pts)[32] = v0;
    (*pts)[33] = v1;
    (*tail)[0] = v2;
    (*tail)[1] = v3;
    (*tail)[2] = v4;
    (*tail)[3] = v5;
    (*tail)[4] = v6;
    (*tail)[5] = v5;
    (*tail)[6] = v7;
    (*tail)[7] = v8;
    (*tail)[8] = v9;
    (*tail)[9] = v10;
    (*tail)[10] = v11;
    (*tail)[11] = v12;
    (*tail)[12] = v13;
    (*tail)[13] = v14;
    (*tail)[14] = v15;
    (*tail)[15] = v16;
    (*tail)[16] = v17;
    (*tail)[17] = v18;
    (*tail)[18] = v15;
    (*tail)[19] = v19;
    (*tail)[20] = v15;
    (*tail)[21] = v20;
    (*tail)[22] = v15;
    (*tail)[23] = v21;
    (*tail)[24] = v15;
    (*tail)[25] = v22;
    (*tail)[26] = v23;
    (*tail)[27] = v24;
    (*tail)[28] = v25;
    (*tail)[29] = v26;
    (*tail)[30] = v15;
    (*tail)[31] = v27;
    (*tail)[32] = v28;
    (*tail)[33] = lbl_805413AC;
    if (__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr == 0) {
        __ct__17JASGenericMemPoolFv(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr);
        __register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr, __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, base + 0x110);
        __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr = 1;
    }
    if (__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack == 0) {
        __ct__17JASGenericMemPoolFv(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack);
        __register_global_object(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack, __dt__35JASMemPool_MultiThreaded_8JASTrackFv, base + 0x11c);
        __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack = 1;
    }
    if (__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel == 0) {
        __ct__17JASGenericMemPoolFv(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel);
        __register_global_object(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel, __dt__38JASMemPool_MultiThreaded_10JASChannelFv, base + 0x128);
        __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA, __dt__29JASMemPool_15JASPoolObj3_FSAFv, base + 0x134);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA, __dt__29JASMemPool_15JASPoolObj4_FSAFv, base + 0x140);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA = 1;
    }
    if (__init__memPool___30JASPoolAllocObject_9JAIStream == 0) {
        __ct__17JASGenericMemPoolFv(memPool___30JASPoolAllocObject_9JAIStream);
        __register_global_object(memPool___30JASPoolAllocObject_9JAIStream, __dt__22JASMemPool_9JAIStreamFv, base + 0x14c);
        __init__memPool___30JASPoolAllocObject_9JAIStream = 1;
    }
    if (__init__memPool___35JASPoolAllocObject_13JAISoundChild == 0) {
        __ct__17JASGenericMemPoolFv(memPool___35JASPoolAllocObject_13JAISoundChild);
        __register_global_object(memPool___35JASPoolAllocObject_13JAISoundChild, __dt__27JASMemPool_13JAISoundChildFv, base + 0x158);
        __init__memPool___35JASPoolAllocObject_13JAISoundChild = 1;
    }
    if (__init__memPool___27JASPoolAllocObject_6JAISeq == 0) {
        __ct__17JASGenericMemPoolFv(memPool___27JASPoolAllocObject_6JAISeq);
        __register_global_object(memPool___27JASPoolAllocObject_6JAISeq, __dt__19JASMemPool_6JAISeqFv, base + 0x164);
        __init__memPool___27JASPoolAllocObject_6JAISeq = 1;
    }
    if (__init__memPool___26JASPoolAllocObject_5JAISe == 0) {
        __ct__17JASGenericMemPoolFv(memPool___26JASPoolAllocObject_5JAISe);
        __register_global_object(memPool___26JASPoolAllocObject_5JAISe, __dt__18JASMemPool_5JAISeFv, base + 0x170);
        __init__memPool___26JASPoolAllocObject_5JAISe = 1;
    }
}
#pragma opt_propagation reset
// Shared JAudio pool __sinit (docs/game/sinit_pools.md). Drop the ESD
// macros/typedefs that clash with the JSystem headers first.
#undef ALIGN_NEXT
#undef ALIGN_PREV
#undef ARRAY_SIZE
#undef ASM
#undef ATTRIBUTE_ALIGN
#undef IS_ALIGNED
#undef IS_NOT_ALIGNED
#undef MACROS_H
#undef MAX
#undef MIN
#undef NULL
#define NULL 0
#define unknown jsys_unknown
#include "JSystem/JAudio/JASFakeMatchFSA.h"
