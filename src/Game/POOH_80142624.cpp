#include "types.h"
#include "std/math.h"
#include "JSystem/JGeometry/Vec.h"
#define POOH_S32(p,o) (*(s32*)((u8*)(p)+(o)))
#define POOH_F32(p,o) (*(f32*)((u8*)(p)+(o)))
#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "Game/ItemBase.h"
#include "JSystem/JUtility/TColor.h"
#include "Game/SinitPoolChain.h"

extern "C" char lbl_8049F330[];
extern "C" void __dt__5ActorFv(Actor* this_, s32 flag);
extern "C" Actor* fn_80142624(Actor* this_, s16 flag) {
    if (this_) {
        *(void**)this_ = lbl_8049F330;
        __dt__5ActorFv(this_, 0);
        if (flag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_80158B5C(void* obj, s32 room, f32 size, void* pos, GXColor color);
extern const f32 lbl_8053CF28;
extern const f32 lbl_8053CF2C;
extern "C" void fn_801EFD34(Actor* this_, s32 id, void* idx, s32 n, f32 a, f32 b, f32 c);
extern "C" void fn_801F06F0(Actor* this_, void* res, s32 id, void* idx, s32 n, f32 a, f32 b);
extern "C" void* lbl_8053AB10;
extern "C" void* lbl_8053AAF8;
extern "C" s32 lbl_8049F318[];
extern "C" char lbl_80465B50[];
class PoohResMgr {
public:
    virtual void v08(); virtual void v0C(); virtual void v10(); virtual void v14();
    virtual s32 getResource(u32, s32);
};
static inline void poohDrawShadow(Actor* p) {
    fn_80158B5C(*(void**)((u8*)lbl_8053AB10+0x2c), *(s32*)((u8*)p+4), lbl_8053CF28, (u8*)p+0xc, JUtility::TColor(0,0,0,0x80));
}
extern "C" void fn_801F0E34(Actor* this_, s32 id, s32 flag);
extern "C" s32 lbl_8049F2B8[];
extern "C" const f32 sincosTable___5JMath[];

extern const f32 lbl_8053CF30;
extern const f32 lbl_8053CF34;
extern const f32 lbl_8053CF38;
extern const f32 lbl_8053CF40;
extern const f32 lbl_8053CF58;
extern const f32 lbl_8053CF60;
extern const f32 lbl_8053CF94;
extern const f32 lbl_8053CF98;
extern const f32 lbl_8053CF9C;
extern const f32 lbl_8053CFA0;
extern const f32 lbl_8053CFA4;

struct PoohRandom {
    u32 seed;
    u32 get() {
        seed = (seed * 0x19660d) + 0x3c6ef35f;
        return seed;
    }
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        out.s = (this->get() >> 9) | 0x3f800000;
        return out.f - lbl_8053CF30;
    }
};
struct PoohGame {
    u8 pad[0xb4];
    PoohRandom rnd;
};
struct PoohSinCos {
    f32 s;
    f32 c;
};

/* 0x19660d/0x3c6ef35f LCG at lbl_8053AAF8+0xB4, mantissa read as [0,1) */
static inline f32 poohRand01() {
    PoohGame* g = (PoohGame*)lbl_8053AAF8;
    return g->rnd.get_ufloat_1();
}
#pragma opt_lifetimes off
extern "C" void fn_80142684(Actor* this_) {
    s32 idx;
    f32 scale;

    if (((*(s32*)((u8*)this_ + 0x254) != 0 || *(u16*)((u8*)this_ + 0x94) < 4 || *(u16*)((u8*)this_ + 0x94) > 7) ||
         (u8)this_->v11() != 0) &&
        *(u16*)((u8*)this_ + 0x94) != 8 && (*(s32*)((u8*)this_ + 0x230) == 1 || *(s32*)((u8*)this_ + 0x230) == 0)) {
        DrawRec rec;
        f32 mtx[12];
        poohDrawShadow(this_);
        ((u8*)&rec.w10)[3] = (u8)(s32)*(f32*)((u8*)this_ + 0x270);
        rec.w30 = 9;
        if (*(u16*)((u8*)this_ + 0x94) == 3 || *(u16*)((u8*)this_ + 0x94) == 7) {
            idx = *(s32*)((u8*)this_ + 0x25c);
            scale = lbl_8053CF2C;
            if (idx > 5) {
                scale = 1.0f;
                idx -= 6;
            }
            mtx[0] = scale;
            mtx[1] = 0.0f;
            mtx[2] = 0.0f;
            mtx[4] = 0.0f;
            mtx[5] = 1.0f;
            mtx[6] = 0.0f;
            mtx[8] = 0.0f;
            mtx[9] = 0.0f;
            mtx[10] = 1.0f;
            mtx[3] = 0.0f;
            mtx[7] = 0.0f;
            mtx[11] = 0.0f;
            rec.w18 = mtx;
            fn_801EFD34(this_, (*(PoohResMgr**)((u8*)lbl_8053AAF8+0xa4))->getResource(0x54494d47, lbl_8049F318[idx]), &rec, 7, 0.0f, lbl_8053CF38, 0.0f);
        } else {
            fn_801F06F0(this_, lbl_80465B50, *(s32*)((u8*)this_ + 0x25c) + 0x84, &rec, 7, 1.0f, 1.0f);
        }
    }
}

extern "C" void fn_801F71A4(f32*, f32, f32, f32);
extern "C" u8 fn_801F37AC(Actor*,s32,void*,s32,s32,s32);
extern "C" s32 fn_801F3D94(Actor*,s32);
extern "C" void fn_8013CC50(s32,void*,s32,s32,s32,s32,s32,s32,f32);
extern "C" void* fn_801F856C();
extern "C" void* Actor_CreateByID(void*,u32,u32,void*,s32,s32,s32);
extern "C" u8 fn_801F305C(Actor*);
extern "C" s32 fn_801F2718(Actor*,u32);
extern "C" s32 fn_801F285C(Actor*,s32,s32,s32,s32);
extern "C" void fn_801EEC98(Actor*,s32,s16*,s32*,s32,s32,s32,s32);
extern "C" void fn_801EE8F4(Actor*,void*,void*,s32);
extern "C" void fn_8030C210(void*,void*);
extern "C" void fn_801F2B7C(Actor*,s32,s32,s32);
extern "C" void fn_80458FF0(void*,s32,s32,s32);
extern "C" void* lbl_8053AF80;
extern "C" s32 lbl_8049F2F8[];
extern const f32 lbl_8053CF3C;
extern const f32 lbl_8053CF44;
extern const f32 lbl_8053CF48;
extern const f32 lbl_8053CF4C;
extern const f32 lbl_8053CF50;
extern const f32 lbl_8053CF54;
extern const f32 lbl_8053CF5C;
extern const f32 lbl_8053CF80;
extern const f32 lbl_8053CF84;
extern const f32 lbl_8053CF88;
extern const f32 lbl_8053CF8C;
extern const f32 lbl_8053CF90;
#pragma opt_lifetimes off
extern "C" void fn_8014292C(Actor* p) {
    s16 hit = 0;
    s32 result = 0;
    if(POOH_S32(p,0x254)==0 && p->field_94>=4 && p->field_94<=7) {
        if(!(u8)p->v11()) return;
        POOH_S32(p,0x254)=1;
        p->field_B0=0x201;
        if(p->field_94==7) p->field_B0=0x4000000;
    }
    if(p->field_94==8) {
        if(!(u8)p->v11() && POOH_S32(p,0x248)==0) return;
        POOH_S32(p,0x248)++;
        if(POOH_S32(p,0x248)>30) {
            fn_80458FF0(lbl_8053AF80,0x1000004,0,0);
            p->field_11C=0;
        }
        return;
    }
    if(POOH_S32(p,0x234)!=0) {
        fn_801F37AC(p,0x80,&p->field_0C,3,0,-1);
        POOH_S32(p,0x234)=0;
    }
    if(fn_801F3D94(p,1)!=0) {
        if((s32)p->field_E0==0x1d) {
            fn_8013CC50(p->field_04,&p->field_0C,0x1ff,1,1,0,0,1,lbl_8053CF30);
            if(p->field_94==9) {
                if(poohRand01()<lbl_8053CF3C) Actor_CreateByID(fn_801F856C(),0x4d54424f,p->field_04,&p->field_0C,1,-1,-1);
                else Actor_CreateByID(fn_801F856C(),0x48415254,p->field_04,&p->field_0C,0,-1,-1);
            }
        }
        return;
    }
    switch(POOH_S32(p,0x230)) {
    case 0:
        fn_801F71A4(&POOH_F32(p,0x270),lbl_8053CF40,lbl_8053CF44,lbl_8053CF48);
        *(JGeometry::TVec3<f32>*)&p->field_0C += *(JGeometry::TVec3<f32>*)&p->field_3C;
        if(POOH_S32(p,0x238)!=0) break;
        p->field_3C.z=0.0f;
        p->field_3C.y=0.0f;
        p->field_3C.x=0.0f;
        POOH_S32(p,0x230)=1;
    case 1:
        fn_801F71A4(&p->field_0C.z,lbl_8053CF50*((const PoohSinCos*)sincosTable___5JMath)[(u16)POOH_S32(p,0x24c)>>5].s+lbl_8053CF4C,lbl_8053CF44,lbl_8053CF30);
        POOH_S32(p,0x24c) += (s32)(lbl_8053CF54*poohRand01())+0x200;
        if((p->field_94==2 || p->field_94==6) && POOH_S32(p,0x238)==0) {
            POOH_S32(p,0x238)=(s32)(lbl_8053CF58*poohRand01())+150;
            POOH_S32(p,0x248)++;
            POOH_S32(p,0x248)&=1;
            if(POOH_S32(p,0x248)==0) fn_801F0E34(p,0x4001d,0);
        }
        if(POOH_S32(p,0x248)==0) {
            fn_801F71A4(&POOH_F32(p,0x270),lbl_8053CF40,lbl_8053CF44,lbl_8053CF48);
        } else {
            fn_801F71A4(&POOH_F32(p,0x270),0.0f,lbl_8053CF44,lbl_8053CF48);
            if((p->field_94==3 || p->field_94==7) && POOH_S32(p,0x238)==0) {
                POOH_S32(p,0x248)=0;
                fn_801F0E34(p,0x4001d,0);
            }
        }
        if(POOH_S32(p,0x248)==0 && POOH_F32(p,0x270)>lbl_8053CF5C) {
            if(p->field_94!=3 && p->field_94!=7 && p->field_B0==0) p->field_B0=0x201;
            if(p->field_94!=3 && p->field_94!=7) {
                if(fn_801F305C(p)) {
                    POOH_F32(p,0x270)=lbl_8053CF40;
                    fn_801F0E34(p,0x40025,0);
                    return;
                }
            } else {
                if(fn_801F2718(p,0x53504f54)>=0) {
                    fn_801F0E34(p,0x40025,0);
                    fn_801F37AC(p,0x80,&p->field_0C,3,0,-1);
                    return;
                }
                for(s32 i=0;i<4;i++) {
                    if(fn_801F285C(p,0,0,1,i)>=0) {
                        fn_801F0E34(p,0x40024,0);
                        POOH_S32(p,0x248)=1;
                        POOH_S32(p,0x238)=20;
                        break;
                    }
                }
            }
        } else p->field_B0=0;
        if(POOH_S32(p,0x23c)==0) {
            POOH_S32(p,0x23c)=(s32)(lbl_8053CF60*poohRand01())+60;
            POOH_S32(p,0x250)^=1;
        }
        fn_801EEC98(p,p->field_198,&hit,&result,0,0,0,0);
        if(result<0 || p->field_94==3 || p->field_94==7) {
            p->field_3C.y=0.0f;
            f32 distance = p->field_0C.x - POOH_F32(p,0x260);
            if(std::sqrtf(distance*distance)>lbl_8053CF80) {
                if(p->field_0C.x>POOH_F32(p,0x260)) POOH_S32(p,0x250)=1;
                else POOH_S32(p,0x250)=0;
            }
        } else {
            Vec direction;
            fn_801EE8F4(p,&direction,0,0);
            if(direction.x<0.0f) p->field_3C.x-=lbl_8053CF84;
            else p->field_3C.x+=lbl_8053CF84;
            if(p->field_94!=2 && p->field_94!=6) {
                if(direction.y<0.0f) p->field_3C.y-=lbl_8053CF84;
                else p->field_3C.y+=lbl_8053CF84;
            }
            POOH_F32(p,0x260)=p->field_0C.x;
            POOH_F32(p,0x264)=p->field_0C.y;
            POOH_F32(p,0x268)=p->field_0C.z;
        }
        if(POOH_S32(p,0x250)!=0) p->field_3C.x-=lbl_8053CF88;
        else p->field_3C.x+=lbl_8053CF88;
        ((JGeometry::TVec3<f32>*)&p->field_3C)->scale(lbl_8053CF8C);
        *(JGeometry::TVec3<f32>*)&p->field_0C += *(JGeometry::TVec3<f32>*)&p->field_3C;
        if(p->field_94>=4 && p->field_94<=7) fn_8030C210(*(void**)((u8*)lbl_8053AB10+0x24),&p->field_0C);
        fn_801F2B7C(p,-100,-1,1);
        break;
    case 2: {
        f32 distance;
        fn_801EE8F4(p,0,&distance,0);
        if(distance<lbl_8053CF90) {
            POOH_F32(p,0x270)=lbl_8053CF5C;
            fn_8013CC50(p->field_04,&p->field_0C,0x1fd,1,1,0,0,1,lbl_8053CF30);
            fn_801F0E34(p,0x4001d,0);
            POOH_S32(p,0x230)=1;
        }
        break;
    }
    }
    if(POOH_S32(p,0x244)==0) {
        result=0;
        if(p->field_3C.x<0.0f) result=1;
        POOH_S32(p,0x244)=lbl_8049F2F8[POOH_S32(p,0x258)];
        POOH_S32(p,0x25c)=lbl_8049F2B8[result*8+POOH_S32(p,0x258)];
        POOH_S32(p,0x258)++;
        POOH_S32(p,0x258)&=7;
    }
    if(POOH_S32(p,0x238)>0) POOH_S32(p,0x238)--;
    if(POOH_S32(p,0x23c)>0) POOH_S32(p,0x23c)--;
    if(POOH_S32(p,0x240)>0) POOH_S32(p,0x240)--;
    if(POOH_S32(p,0x244)>0) POOH_S32(p,0x244)--;
}
#pragma opt_lifetimes reset


#pragma opt_lifetimes on
extern "C" void fn_80143330(Actor* this_) {
    u8* p = (u8*)this_;

    *(f32*)(p + 0x60) = lbl_8053CF38;
    *(f32*)(p + 0x64) = lbl_8053CF38;
    *(f32*)(p + 0x68) = lbl_8053CF94;
    *(f32*)(p + 0x6c) = lbl_8053CF94;
    *(u16*)(p + 0x94) = (u8)*(u32*)(p + 0x90);
    *(s16*)(p + 0x26c) = (s16)((*(u32*)(p + 0x90) >> 8) & 0xffff);
    *(s32*)(p + 0x238) = 0;
    *(s32*)(p + 0x23c) = 0;
    *(s32*)(p + 0x240) = 0;
    *(s32*)(p + 0x244) = 0;
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x250) = 0;
    *(s32*)(p + 0x254) = 0;
    *(s32*)(p + 0x258) = 0;
    *(f32*)(p + 0x270) = lbl_8053CF40;
    {
        u8* g = (u8*)lbl_8053AAF8;
        u32 seed = *(u32*)(g + 0xb4) * 0x19660d + 0x3c6ef35f;
        *(u32*)(g + 0xb4) = seed;
        u32 bits = (*(u32*)(g + 0xb4) >> 9) | 0x3f800000;
        f32 random = *(f32*)&bits - lbl_8053CF30;
        *(s32*)(p + 0x23c) = (s32)(lbl_8053CF60 * random) + 60;
    }
    *(s32*)(p + 0x234) = 0;
    *(s32*)(p + 0xb0) = 0;
    *(f32*)(p + 0x260) = *(f32*)(p + 0xc);
    *(f32*)(p + 0x264) = *(f32*)(p + 0x10);
    *(f32*)(p + 0x268) = *(f32*)(p + 0x14);

    switch (*(u16*)(p + 0x94)) {
    case 6:
        *(f32*)(p + 0x270) = lbl_8053CF34;
    case 2:
        {
        u8* g = (u8*)lbl_8053AAF8;
        u32 seed = *(u32*)(g + 0xb4) * 0x19660d + 0x3c6ef35f;
        *(u32*)(g + 0xb4) = seed;
        u32 bits = (*(u32*)(g + 0xb4) >> 9) | 0x3f800000;
        f32 random = *(f32*)&bits - lbl_8053CF30;
        *(s32*)(p + 0x248) = (s32)random;
    }
        {
        u8* g = (u8*)lbl_8053AAF8;
        u32 seed = *(u32*)(g + 0xb4) * 0x19660d + 0x3c6ef35f;
        *(u32*)(g + 0xb4) = seed;
        u32 bits = (*(u32*)(g + 0xb4) >> 9) | 0x3f800000;
        f32 random = *(f32*)&bits - lbl_8053CF30;
        *(s32*)(p + 0x238) = (s32)(lbl_8053CF58 * random) + 150;
    }
        if (*(u16*)(p + 0x94) == 2) {
            *(s32*)(p + 0xb0) = 0x201;
        }
        *(f32*)(p + 0x14) = lbl_8053CF98;
        *(s32*)(p + 0x230) = 1;
        break;
    case 10:
        fn_801F0E34(this_, 0x4001d, 0);
        *(f32*)(p + 0x270) = lbl_8053CF34;
        *(f32*)(p + 0x14) = lbl_8053CF98;
        *(s32*)(p + 0x238) = 30;
        *(f32*)(p + 0x3c) = lbl_8053CF9C * ((const PoohSinCos*)sincosTable___5JMath)[((u32)*(u16*)(p + 0x26c) & 0xffffU) >> 5].s;
        *(f32*)(p + 0x40) = lbl_8053CF9C * ((const PoohSinCos*)sincosTable___5JMath)[((u32)*(u16*)(p + 0x26c) & 0xffffU) >> 5].c;
        *(s32*)(p + 0x230) = 0;
        break;
    case 4:
    case 9:
        fn_801F0E34(this_, 0x4001d, 0);
        *(f32*)(p + 0x270) = lbl_8053CF34;
    case 0:
        if (*(u16*)(p + 0x94) == 0) {
            *(s32*)(p + 0xb0) = 0x201;
        }
        *(f32*)(p + 0x14) = lbl_8053CF98;
        *(s32*)(p + 0x230) = 1;
        break;
    case 3:
    case 7:
        *(f32*)(p + 0x60) = lbl_8053CFA0;
        *(f32*)(p + 0x64) = lbl_8053CFA0;
        *(f32*)(p + 0x68) = lbl_8053CFA4;
        *(f32*)(p + 0x6c) = lbl_8053CFA4;
        *(f32*)(p + 0x14) = lbl_8053CF98;
        *(s32*)(p + 0x108) = 100;
        *(s32*)(p + 0xb0) = 0x4000000;
        *(s32*)(p + 0x230) = 1;
        break;
    case 1:
    case 5:
        *(f32*)(p + 0x270) = lbl_8053CF34;
        *(s32*)(p + 0x230) = 2;
        break;
    }

    s32 idx = 0;
    if (*(f32*)(p + 0x3c) < lbl_8053CF34) {
        idx = 1;
    }
    *(s32*)(p + 0x25c) = lbl_8049F2B8[idx * 8 + *(s32*)(p + 0x258)];
}
#pragma opt_lifetimes reset
void __sinit_POOH_80142624_cpp(void) {}
