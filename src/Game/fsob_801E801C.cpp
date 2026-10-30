// Game TU 801E801C-801E9AFC (FSOB). Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
// Only functions that re-verify byte-exact are included; the rest remain asm.
#include "types.h"
#include <dolphin/gx.h>
#include "JSystem/JMath/JMath.h"
#include "JSystem/JGeometry/Util.h"
#include "JSystem/JGeometry/Vec.h"

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern void* lbl_804A5568[];
extern void* lbl_804A4808[];
extern void* lbl_8049CC34[];
extern "C" void* fn_801E9AFC();
extern "C" void fn_801EA344(void*);
extern "C" void fn_801EA304(void*);
extern "C" f32 fn_801CD6D8(f32, f32, f32, f32, f32);
extern "C" void fn_801E8B1C(void*, f32*, s32, s32, f32, f32);
extern "C" void fn_801EA108(void* mgr, void* pos, s32 a, f32 r);
extern "C" void fn_8030C210(void* mgr, void* pos);
extern "C" u8 fn_801F2B7C(void* this_, s32 a, s32 b, s32 c);
extern "C" s32 fn_801E9B58(void* this_);
extern "C" void* fn_8013C824();
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void* mgr, void* emitter);
extern "C" void* fn_8013CC50(u32 id, void* pos, s32 type, s32 p4, s32 p5, u32 p6, u32 p7, u32 p8, f32 f);
extern "C" void fn_801D0ED0(void* this_);
extern "C" void fn_801D0F40(char* p);
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void __ct__Q29JGeometry8TVec2_f_Fv();
extern f32 lbl_8053F5FC;
extern f32 lbl_8053F608;
struct Fsob8B10 { u8 pad[0x24]; void* m24; };
extern Fsob8B10* lbl_8053AB10;

struct FsobPath {
    u8 pad[0x2a8];
    u32 flags;
    u8 pad2ac[4];
    JGeometry::TVec2<f32> points[32];
};

#pragma opt_propagation off
#pragma opt_common_subs off
static inline void fsobSample(char* p, u8 seg, u8 step, f32& outX, f32& outY) {
char* q=p+seg*8;
f32 x,y;
switch (step) {
case 0: x=*(f32*)(q+0x2b0); y=*(f32*)(q+0x2b4); break;
case 16: x=*(f32*)(q+0x2b8); y=*(f32*)(q+0x2bc); break;
default: {
 f32 t, x2, x3, x0, x1;
 f32 y0,y1,y2,y3;
 if (seg==0) { x0=*(f32*)(p+0x2b0); y0=*(f32*)(p+0x2b4); }
 else { x0=*(f32*)(q+0x2a8); y0=*(f32*)(q+0x2ac); }
 u8 n=*(u8*)(p+0x2ad);
 x2=*(f32*)(q+0x2b8); y2=*(f32*)(q+0x2bc);
 x1=*(f32*)(q+0x2b0); y1=*(f32*)(q+0x2b4);
 if(seg==n-2) { x3=x2; y3=y2; } else { x3=*(f32*)(q+0x2c0); y3=*(f32*)(q+0x2c4); }
 t=0.0625f*(f32)step;
 y=fn_801CD6D8(y0,y1,y2,y3,t);
 x=fn_801CD6D8(x0,x1,x2,x3,t);
 break;
}}
outX=x;outY=y;
}
#pragma opt_common_subs reset
#pragma opt_propagation reset

extern "C" void fn_801E801C(char* p) {
    static f32 radius = -256.0f;
    if (*(s32*)(p + 0x248) == 0) {
        fn_801EA108(fn_801E9AFC(), p + 0xc, *(s16*)(p + 0x3bc), radius);
    }
}

#pragma opt_propagation off
extern "C" void fn_801E8080(FsobPath* self) {
 char* p=(char*)self;
 JGeometry::TVec2<f32> pos;
 f32 length=0.0f,lastX,lastY;
 const s32 count=(*(u8*)(p+0x2ad)-1)*32+2;
 u8 split=0;
 const f32 normal=*(f32*)((char*)fn_801E9AFC()+0x178);
 const f32 special=*(f32*)((char*)fn_801E9AFC()+0x17c);
 f32 tilt=normal;
 if(*(u8*)(p+0x3b0)==0 && *(f32*)(p+0x3b4)==0.0f) { fn_801EA344(fn_801E9AFC()); }
 else { fn_801EA304(fn_801E9AFC()); tilt=special; if(!(*(u32*)(p+0x230)&0x4000)) split=1; }
 if(split) {
 s32 steps=(u8)(1.0f+*(f32*)(p+0x3b4));
 s32 first=*(u8*)(p+0x3b0)*32+steps*2+2;
 GXBegin((GXPrimitive)0x98,GX_VTXFMT0,first);
 pos.set(*(f32*)(p+0x2b0),*(f32*)(p+0x2b4));
 s32 emitted=0;
 u8 end=*(u8*)(p+0x3b0);
 for(u8 seg=0;seg<=end;seg++) {
 char* q=p+seg*8;
 for(u8 step=1;step<=16;step++) {
 f32 x,y; fsobSample(p,seg,step,x,y);
 f32 dy=y-pos.y,dx=x-pos.x;
 if(seg==0 && step==1) {lastX=dx;lastY=dy;}
 { s32 b=(s32)(JMath::atanTable_.atan2Radian(dx,dy)*10430.4f);
s32 a=(s32)(JMath::atanTable_.atan2Radian(lastX,lastY)*10430.4f);
fn_801E8B1C(p,&pos.x,a,b,length,special); }
 pos.set(x,y); lastX=dx;lastY=dy;
 length+=JGeometry::TUtilf::sqrt(dx*dx+dy*dy);
 emitted+=2;
 if(emitted>=first-2) goto first_done;
 }}
 first_done:
 f32 d=JGeometry::TUtilf::sqrt(lastX*lastX+lastY*lastY);
 f32 partial=length-d;
 partial+=d*(*(f32*)(p+0x3b4)-(u8)*(f32*)(p+0x3b4));
 { s32 b=(s32)(JMath::atanTable_.atan2Radian(lastX,lastY)*10430.4f);
s32 a=(s32)(JMath::atanTable_.atan2Radian(lastX,lastY)*10430.4f);
fn_801E8B1C(p,(f32*)(p+0xc),a,b,partial,special); }
 fn_801EA344(fn_801E9AFC());
 GXBegin((GXPrimitive)0x98,GX_VTXFMT0,count-first+4);
 { s32 b=(s32)(JMath::atanTable_.atan2Radian(lastX,lastY)*10430.4f);
s32 a=(s32)(JMath::atanTable_.atan2Radian(lastX,lastY)*10430.4f);
fn_801E8B1C(p,(f32*)(p+0xc),a,b,partial,normal); }
 u8 start=*(u8*)(p+0x3b0);
 s32 begin=steps+1;
 s32 finish=*(u8*)(p+0x2ad)-1;
 for(u8 seg=start;seg<finish;seg++) {
 char* q=p+seg*8;
 for(u8 step=1;step<=16;step++) {
 if(seg<=start && step<begin) continue;
 f32 x,y; fsobSample(p,seg,step,x,y);
 f32 dy=y-pos.y,dx=x-pos.x;
 { s32 b=(s32)(JMath::atanTable_.atan2Radian(dx,dy)*10430.4f);
s32 a=(s32)(JMath::atanTable_.atan2Radian(lastX,lastY)*10430.4f);
fn_801E8B1C(p,&pos.x,a,b,length,normal); }
 pos.set(x,y);lastX=dx;lastY=dy;
 length+=JGeometry::TUtilf::sqrt(dx*dx+dy*dy);
 }}
 { s32 b=(s32)(JMath::atanTable_.atan2Radian(lastX,lastY)*10430.4f);
s32 a=(s32)(JMath::atanTable_.atan2Radian(lastX,lastY)*10430.4f);
fn_801E8B1C(p,&pos.x,a,b,length,normal); }
 } else {
 GXBegin((GXPrimitive)0x98,GX_VTXFMT0,count);
 pos.set(*(f32*)(p+0x2b0),*(f32*)(p+0x2b4));
 s32 end=*(u8*)(p+0x2ad)-1;
 for(u8 seg=0;seg<end;seg++) {
 char* q=p+seg*8;
 for(u8 step=1;step<=16;step++) {
 f32 x,y; fsobSample(p,seg,step,x,y);
 f32 dy=y-pos.y,dx=x-pos.x;
 if(seg==0 && step==1) {lastX=dx;lastY=dy;}
 { s32 b=(s32)(JMath::atanTable_.atan2Radian(dx,dy)*10430.4f);
s32 a=(s32)(JMath::atanTable_.atan2Radian(lastX,lastY)*10430.4f);
fn_801E8B1C(p,&pos.x,a,b,length,tilt); }
 pos.set(x,y);lastX=dx;lastY=dy;
 length+=JGeometry::TUtilf::sqrt(dx*dx+dy*dy);
 }}
 { s32 b=(s32)(JMath::atanTable_.atan2Radian(lastX,lastY)*10430.4f);
s32 a=(s32)(JMath::atanTable_.atan2Radian(lastX,lastY)*10430.4f);
fn_801E8B1C(p,&pos.x,a,b,length,tilt); }
 }
}
#pragma opt_propagation reset
static s8 lbl_8053AC44;
static f32 lbl_8053AC40;
extern "C" void fn_801E8B1C(void* p0, f32* pos, s32 a, s32 b, f32 scale, f32 tilt) {
    if (lbl_8053AC44 == 0) {
        lbl_8053AC44 = 1;
        lbl_8053AC40 = -256.0f;
    }
    u16 ua = (u16)a;
    f32 t = 0.5f * (f32)(ua + (u16)b);
    s32 idx = (s32)(t + (t > 0.0f ? 0.5f : -0.5f));
    f32 px = pos[0];
    f32 py = pos[1];
    s16 d = (s16)((s16)idx - a);
    f32 base = lbl_8053AC40;
    f32 k = 1.0f / (4.0f * tilt);
    f32 sk = scale * k;
    f32 ic = 1.0f / JMath::sincosTable_.mTable[(u16)d >> 5].second;
    f32 sA = JMath::sincosTable_.mTable[ua >> 5].first;
    f32 cA = JMath::sincosTable_.mTable[ua >> 5].second;
    s16 q = (s16)(d - 0x4000);
    f32 sq = JMath::sincosTable_.mTable[(u16)(-q) >> 5].first;
    f32 cq = JMath::sincosTable_.mTable[(u16)(-q) >> 5].second;
    f32 f = 2.0f * ic;
    f32 X = (sA * sq + cA * cq) * f;
    f32 Y = (sA * cq - cA * sq) * f;
    *(volatile f32*)0xCC008000 = px + Y;
    *(volatile f32*)0xCC008000 = base + (py + X);
    *(volatile f32*)0xCC008000 = base;
    *(volatile f32*)0xCC008000 = 1.0f;
    *(volatile f32*)0xCC008000 = sk;
    *(volatile f32*)0xCC008000 = px - Y;
    *(volatile f32*)0xCC008000 = base + (py - X);
    *(volatile f32*)0xCC008000 = base;
    *(volatile f32*)0xCC008000 = 0.0f;
    *(volatile f32*)0xCC008000 = sk;
}

extern "C" f32 fn_801CD6D8(f32 p0, f32 p1, f32 p2, f32 p3, f32 t);
extern "C" void fn_801E9C00(s16 angle, f32* out);
extern f32 lbl_8053F604;
extern f32 lbl_8053F608;
extern f32 lbl_8053F60C;
extern f32 lbl_8053F640;
extern f32 lbl_8053F644;
extern "C" void fn_801E8C74(char* p, s32 a) {
    u8 flag = 1;
    s32 i;
    f32 x2;
    f32 y2;
    *(s32*)(p + 0x3b8) = a;
    *(u8*)(p + 0x2ad) = 0;
    for (i = 0; i < 32; i++) {
        if (*(u32*)(p + 0x2a8) & (1 << i)) {
            if (flag) {
                (*(u8*)(p + 0x2ad))++;
            }
        } else {
            flag = 0;
        }
    }
    f32 y0 = *(f32*)(p + 0x2b4);
    f32 x0 = *(f32*)(p + 0x2b0);
    *(f32*)(p + 0xc) = x0;
    *(f32*)(p + 0x10) = y0;
    *(f32*)(p + 0x14) = 0.0f;

    x0 = *(f32*)(p + 0x2b0);
    y0 = *(f32*)(p + 0x2b4);
    f32 x1 = *(f32*)(p + 0x2b8);
    f32 y1 = *(f32*)(p + 0x2bc);
    if (*(u8*)(p + 0x2ad) - 2 == 0) {
        x2 = x1;
        y2 = y1;
    } else {
        x2 = *(f32*)(p + 0x2c0);
        y2 = *(f32*)(p + 0x2c4);
    }
    f32 yc = fn_801CD6D8(y0, y0, y1, y2, 0.0625f);
    f32 xc = fn_801CD6D8(x0, x0, x1, x2, 0.0625f);
    f32 dx = *(f32*)(p + 0xc) - xc;
    f32 dy = *(f32*)(p + 0x10) - yc;
    f32 ang = JMath::atanTable_.atan2Radian(dx, dy);
    *(s16*)(p + 0x3bc) = (s16)(ang * 10430.4f);

    f32 out[2];
    fn_801E9C00(*(s16*)(p + 0x3bc), out);
    *(f32*)(p + 0x60) += out[0];
    *(f32*)(p + 0x64) += out[1];
    *(f32*)(p + 0x68) += out[0];
    *(f32*)(p + 0x6c) += out[1];
}

struct FsobVec2 {
    f32 x, y;
};



extern "C" void fn_801E8EB4(FsobPath* p, u8 idx, s32 unused, FsobVec2* v) {
    f32 y = v->y;
    f32 x = v->x;
    p->flags |= 1 << idx;
    p->points[idx].set(x, y);
}

extern "C" void fn_801E8EE8(char* p) {
    if (*(u32*)(p + 0x230) & 0x2000) {
        fn_8030C210(lbl_8053AB10->m24, p + 0xc);
    }
}

extern "C" u8 fn_801E8F20(char* p) {
    u8 ret = 0;
    if (*(u32*)(p + 0x230) & 0x2000) {
        f32 x0 = *(f32*)(p + 0x60);
        f32 y0 = *(f32*)(p + 0x64);
        f32 x1 = *(f32*)(p + 0x68);
        f32 y1 = *(f32*)(p + 0x6c);
        *(f32*)(p + 0x60) = -8.0f;
        *(f32*)(p + 0x64) = -8.0f;
        *(f32*)(p + 0x68) = 8.0f;
        *(f32*)(p + 0x6c) = 8.0f;
        ret = fn_801F2B7C(p, 0, -1, 0x16);
        *(f32*)(p + 0x60) = x0;
        *(f32*)(p + 0x64) = y0;
        *(f32*)(p + 0x68) = x1;
        *(f32*)(p + 0x6c) = y1;
    }
    return ret;
}

extern "C" s32 fn_801E8FE8(char* p) {
    if (*(s32*)(p + 0x248) == 0 && *(f32*)(p + 0x68) - *(f32*)(p + 0x60) > 0.0f &&
        *(f32*)(p + 0x6c) - *(f32*)(p + 0x64) > 0.0f && fn_801E9B58(p) >= 0) {
        *(u32*)(p + 0x230) |= 0x2000;
        if (*(void**)(p + 0x3c0) != 0) {
            void* mgr = *(void**)((char*)fn_8013C824() + 0xc);
            forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, *(void**)(p + 0x3c0));
        }
        *(void**)(p + 0x3c0) = fn_8013CC50(*(u32*)(p + 0x4), p + 0xc, 0x260, 0, -2, 0, 0, 1, 1.0f);
        *(s32*)(p + 0x24c) = 0;
        *(s32*)(p + 0x248) = 1;
    }
    return 0;
}

struct FsobBox {
    f32 x0, y0, x1, y1;
};
static inline void setBox(FsobBox* b, f32 r) {
    b->x0 = -r;
    b->y0 = -r;
    b->x1 = r;
    b->y1 = r;
}

extern "C" void fn_801E96F8(char* p) {
    fn_801D0ED0(p);
    *(u8*)(p + 0x2ac) = *(u32*)(p + 0x90);
    f32 r = 6.0f;
    *(f32*)(p + 0x64) = *(f32*)(p + 0x60) = -r;
    *(f32*)(p + 0x6c) = *(f32*)(p + 0x68) = r;
    *(f32*)(p + 0x70) = 1.0f;
    *(f32*)(p + 0x74) = 1.0f;
    *(f32*)(p + 0x78) = -1.0f;
    *(f32*)(p + 0x7c) = -1.0f;
    *(f32*)(p + 0x80) = 1.0f;
    *(f32*)(p + 0x84) = 1.0f;
    *(f32*)(p + 0x88) = -1.0f;
    *(f32*)(p + 0x8c) = -1.0f;
    *(u32*)(p + 0xb0) = 0;
    *(u32*)(p + 0x98) = 2;
    *(u32*)(p + 0x230) |= 0x280;
    *(s32*)(p + 0x108) = 1000;
    *(s32*)(p + 0x244) = *(s32*)(p + 0x108);
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x250) = -1;
    *(f32*)(p + 0x254) = 0.0f;
    *(f32*)(p + 0x258) = 0.0f;
}

extern "C" int fn_801E90BC(void) { return 0; }

extern f32 lbl_8053F600;
extern "C" void fn_801E9224(char* p);
extern "C" void fn_801E6EAC(void);
extern "C" void fn_8013CB44(void* a, void* b, s32 c, s32 d, s32 e);
extern "C" void fn_801F0E34(void* this_, s32 a, s32 b);
extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802D800C(void* a, u16 b);
extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F666C(void* a, s32 b);
extern "C" void fn_801E90C4(char* p) {
    switch (*(s32*)(p + 0x248)) {
    case 0: {
        u16 sVar = *(u16*)(p + 0x94);
        if (sVar != 0) {
            void* a = fn_802D6A9C();
            if (fn_802D800C(a, sVar) != 0) {
                *(u32*)(p + 0x230) |= 0x2000;
                if (*(void**)(p + 0x3c0) != 0) {
                    void* mgr = *(void**)((char*)fn_8013C824() + 0xc);
                    forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, *(void**)(p + 0x3c0));
                }
                *(void**)(p + 0x3c0) = fn_8013CC50(*(u32*)(p + 0x4), p + 0xc, 0x260, 0, -2, 0, 0, 1, lbl_8053F600);
                *(s32*)(p + 0x24c) = 0;
                *(s32*)(p + 0x248) = 1;
            }
        }
        break;
    }
    case 1:
        fn_801E9224(p);
        fn_8013CB44(*(void**)(p + 0x3c0), p + 0xc, 0, -2, 1);
        fn_801F0E34(p, 0x3003e, 0);
        if (*(u32*)(p + 0x230) & 0x4000) {
            s32 idx = *(s32*)(p + 0x3b8);
            if (idx >= 0) {
                void* a = fn_801F856C();
                if ((u32)fn_801F666C(a, idx) != 0) {
                    fn_801E6EAC();
                }
            }
            *(u32*)(p + 0x230) &= ~0x2000;
            fn_801EE434(*(void**)(p + 0x3c0));
            *(void**)(p + 0x3c0) = 0;
            *(s32*)(p + 0x24c) = 0;
            *(s32*)(p + 0x248) = 2;
        }
        break;
    case 2:
        break;
    }
}


extern "C" void fn_801E9224(char* p) {
    if (*(u32*)(p + 0x230) & 0x4000) {
        return;
    }
    u8 done = 0;
    f32 zero = lbl_8053F5FC;
    f32 rem = lbl_8053F60C;
    rem = __fsel(rem, rem, zero);
    while (zero < rem) {
        u8 segment = *(u8*)(p + 0x3b0);
        s32 ti = (s32)*(f32*)(p + 0x3b4);
        f32 ax;
        f32 ay;
        switch ((u8)ti) {
        case 0: {
            char* q = p + segment * 8;
            ax = *(f32*)(q + 0x2b0);
            ay = *(f32*)(q + 0x2b4);
            break;
        }
        case 16: {
            char* q = p + segment * 8;
            ax = *(f32*)(q + 0x2b8);
            ay = *(f32*)(q + 0x2bc);
            break;
        }
        default: {
            f32 u, p2x, p3x, p0x, p1x;
            f32 p0y, p1y, p2y, p3y;
            if (segment == 0) {
                p0x = *(f32*)(p + 0x2b0);
                p0y = *(f32*)(p + 0x2b4);
            } else {
                char* q = p + segment * 8;
                p0x = *(f32*)(q + 0x2a8);
                p0y = *(f32*)(q + 0x2ac);
            }
            u8 count = *(u8*)(p + 0x2ad);
            char* q = p + segment * 8;
            p2x = *(f32*)(q + 0x2b8);
            p2y = *(f32*)(q + 0x2bc);
            p1x = *(f32*)(q + 0x2b0);
            p1y = *(f32*)(q + 0x2b4);
            if (segment == count - 2) {
                p3x = p2x;
                p3y = p2y;
            } else {
                p3x = *(f32*)(q + 0x2c0);
                p3y = *(f32*)(q + 0x2c4);
            }
            u = 0.0625f * (f32)(u8)ti;
            ay = fn_801CD6D8(p0y, p1y, p2y, p3y, u);
            ax = fn_801CD6D8(p0x, p1x, p2x, p3x, u);
            break;
        }
        }

        u8 seg = *(u8*)(p + 0x3b0);
        u8 next = (u8)((s32)*(f32*)(p + 0x3b4) + 1);
        if (next >= 16) {
            if (seg >= *(u8*)(p + 0x2ad) - 2) {
                done = 1;
            } else {
                seg++;
                next -= 16;
            }
        }

        f32 by;
        f32 bx;
        switch (next) {
        case 0: {
            char* q = p + seg * 8;
            bx = *(f32*)(q + 0x2b0);
            by = *(f32*)(q + 0x2b4);
            break;
        }
        case 16: {
            char* q = p + seg * 8;
            bx = *(f32*)(q + 0x2b8);
            by = *(f32*)(q + 0x2bc);
            break;
        }
        default: {
            f32 u, p2x, p3x, p0x, p1x;
            f32 p0y, p1y, p2y, p3y;
            if (seg == 0) {
                p0x = *(f32*)(p + 0x2b0);
                p0y = *(f32*)(p + 0x2b4);
            } else {
                char* q = p + seg * 8;
                p0x = *(f32*)(q + 0x2a8);
                p0y = *(f32*)(q + 0x2ac);
            }
            u8 count = *(u8*)(p + 0x2ad);
            char* q = p + seg * 8;
            p2x = *(f32*)(q + 0x2b8);
            p2y = *(f32*)(q + 0x2bc);
            p1x = *(f32*)(q + 0x2b0);
            p1y = *(f32*)(q + 0x2b4);
            if (seg == count - 2) {
                p3x = p2x;
                p3y = p2y;
            } else {
                p3x = *(f32*)(q + 0x2c0);
                p3y = *(f32*)(q + 0x2c4);
            }
            u = 0.0625f * (f32)next;
            by = fn_801CD6D8(p0y, p1y, p2y, p3y, u);
            bx = fn_801CD6D8(p0x, p1x, p2x, p3x, u);
            break;
        }
        }

        JGeometry::TVec2<f32> ab;
        JGeometry::TVec2<f32> d;
        ab.set(bx - ax, by - ay);
        d.x = bx - *(f32*)(p + 0xc);
        d.y = by - *(f32*)(p + 0x10);
        f32 len = d.length();
        if (rem >= len) {
            *(f32*)(p + 0xc) = bx;
            *(f32*)(p + 0x10) = by;
            *(f32*)(p + 0x14) = zero;
            if (done) {
                *(u32*)(p + 0x230) |= 0x4000;
                *(u8*)(p + 0x3b0) = *(u8*)(p + 0x2ad) - 2;
                *(f32*)(p + 0x3b4) = 16.0f;
                return;
            } else {
                rem -= len;
                *(f32*)(p + 0x3b4) = (f32)next;
                *(u8*)(p + 0x3b0) = seg;
            }
        } else {
            d.normalize();
            d.scale(rem);
            *(f32*)(p + 0xc) += d.x;
            *(f32*)(p + 0x10) += d.y;
            f32 abLen = ab.length();
            *(f32*)(p + 0x3b4) += rem * (1.0f / abLen);
            return;
        }
    }
}

extern "C" void* fn_801E97B4(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)p = lbl_804A5568;
        fn_801EE434(*(void**)(p + 0x3c0));
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

extern "C" char* fn_801E9850(char* p) {
    fn_801D0F40(p);
    *(void***)p = lbl_804A5568;
    *(u32*)(p + 0x2a8) = 0;
    *(u8*)(p + 0x2ac) = 0;
    *(u8*)(p + 0x2ad) = 0;
    __construct_array(p + 0x2b0, (void*)__ct__Q29JGeometry8TVec2_f_Fv, 0, 8, 0x20);
    *(u8*)(p + 0x3b0) = 0;
    *(f32*)(p + 0x3b4) = 0.0f;
    *(s32*)(p + 0x3b8) = -1;
    *(s16*)(p + 0x3bc) = 0;
    *(u32*)(p + 0x3c0) = 0;
    return p;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
#include "dolphin/gx.h"
