// OKTA_8013F9A8: .text 0x8013F9A8-0x80140E24 (actor OKTA)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"
#include "Game/ItemBase.h"
#include "JSystem/JGeometry/Vec.h"
#include "Game/HitRect.h"
#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"

// ---- from Game/fn_8013F9A8_dtor.cpp

extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049F208[];

extern const f32 lbl_8053CE28;
extern const f32 lbl_8053CE2C;
extern const f32 lbl_8053CE34;
extern const f32 lbl_8053CE3C;
extern const f32 lbl_8053CE50;
extern const f32 lbl_8053CE54;
extern const f32 lbl_8053CE80;
extern const f32 lbl_8053CE84;
extern const f32 lbl_8053CE88;
extern const f32 lbl_8053CE8C;
extern const f32 lbl_8053CE90;
extern const f32 lbl_8053CE94;
extern const f32 lbl_8053CE98;

struct OktaVec3 {
    f32 x, y, z;
};

struct OktaVec4 {
    f32 x, y, z, w;
};

struct OktaBlk {
    s32 a;
    s32 b;
    void* c;
    u8 d[11];
    s32 e;
    u8 f[3];
    s32 g;
    s32 h;
    s32 i;
};

extern "C" void* fn_802D6A9C();
extern "C" void fn_801EF574(u8* lbl, s32 idx, OktaVec3* pos, u8* arr);
extern "C" void fn_803075AC(void* a, s32 room, void* c, void* d, s32 e, s32 f, s32 g, s32 h, s32 i, s32 j);
extern "C" void fn_801F02BC(u8* this_, u8* lbl, u32 idx, u8* arr, u32 a, s32 b, u8 c, f32 f1, f32 f2);
extern u8 lbl_80465A80[];
extern u32 lbl_8049F1E0[];
extern u32 lbl_8049F1C0[];

struct OktaRandom {
    u32 seed;
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        const u32 multiplier = 0x19660d;
        u32 value = seed;
        seed = value * multiplier + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - lbl_8053CE2C;
    }
};
struct OktaGame { u8 pad[0xb4]; OktaRandom rnd; };
extern OktaGame* lbl_8053AAF8;
extern s32 lbl_8053AB28;

extern "C" void* fn_8013F9A8(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049F208;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

#pragma opt_common_subs off
#pragma opt_propagation off
extern "C" void fn_8013FA08(u8* this_) {
    DrawRec rec;
    f32 mtx[3][4];
    s32 sel;
    f32 s;
    s32 iVar3;
    u8* iVar1;


    mtx[0][3] = 0.0f;
    mtx[1][3] = 0.0f;
    mtx[2][3] = 0.0f;
    rec.ids[3] = this_[0x278];
    if (*(s32*)(this_ + 0x230) == 2 || *(s32*)(this_ + 0x230) == 1) {
        sel = *(u32*)(this_ + 0x24c) + 2;
    } else if (*(u32*)(this_ + 0x90) == 1) {
        sel = (*(u32*)(this_ + 0x234) >> 3) & 1;
    } else {
        sel = (*(u32*)(this_ + 0x234) >> 2) & 1;
    }
    s = *(f32*)(this_ + 0x260);
    mtx[0][0] = s;
    mtx[0][1] = 0.0f;
    mtx[0][2] = 0.0f;
    mtx[1][0] = 0.0f;
    mtx[1][1] = s;
    mtx[1][2] = 0.0f;
    mtx[2][0] = 0.0f;
    mtx[2][1] = 0.0f;
    mtx[2][2] = s;
    rec.w18 = mtx;

    if (*(s32*)(this_ + 4) == 8) {
        iVar3 = 0;
        u8* p = (u8*)fn_802D6A9C();
        OktaVec4 tmp = *(OktaVec4*)(p + 0xcc);
        OktaVec3 pos;
        pos.x = *(f32*)(this_ + 0xc);
        pos.y = *(f32*)(this_ + 0x10);
        pos.z = *(f32*)(this_ + 0x14);
        pos.x += tmp.x;
        pos.y += tmp.y;
        if (*(u32*)(this_ + 0x90) == 1) {
            iVar3 = 0x446;
        }
        fn_801EF574(lbl_80465A80, iVar3 + *(u32*)(this_ + 0x98) * 4 + sel, &pos, (u8*)&rec);
        if (*(s32*)(this_ + 0x230) == 2 || *(s32*)(this_ + 0x230) == 1) {
            iVar1 = (u8*)lbl_8049F1E0[*(u32*)(this_ + 0x258)];
        } else {
            u32 index = *(u32*)(this_ + 0x98) * 2;
            u32 bit = (*(u32*)(this_ + 0x234) >> 3) & 1;
            iVar1 = (u8*)lbl_8049F1C0[index + bit];
        }
        fn_803075AC(*(void**)(this_ + 0x198), *(s32*)(this_ + 4), this_ + 0xc, iVar1 + 0x158, 0, 2, -1, 0, 0, 0);
    } else if (*(u32*)(this_ + 0x90) == 1) {
        s32 index = *(s32*)(this_ + 0x98);
        s32 frame = (s32)((char*)(index * 4) + sel);
        fn_801F02BC(this_, lbl_80465A80, frame + 0x446, (u8*)&rec, 7, 0, 0, lbl_8053CE2C, lbl_8053CE2C);
    } else {
        fn_801F02BC(this_, lbl_80465A80, (s32)((char*)(*(u32*)(this_ + 0x98) * 4) + sel), (u8*)&rec, 7, 0, 0, lbl_8053CE2C, lbl_8053CE2C);
    }
}
#pragma opt_propagation reset
#pragma opt_common_subs reset
extern const f32 lbl_8053CE30;
extern u8* lbl_8053AB10;
extern "C" void fn_8030C210(void* p);
extern "C" void fn_801F71A4(u8* p, f32 a, f32 b, f32 c);
extern "C" u8 fn_801F2618(u8* this_, s32 a, s32 b);
extern "C" void fn_801F2B7C(u8* this_, s32 a, s32 b, s32 c);
extern "C" s32 fn_801F3D94(void*,u8);
extern "C" u8 fn_801F305C(void*);
extern "C" void fn_801EEC98(void*,s32,u16*,s32*,f32*,s32*,s32,s32);
extern "C" void fn_801F0E34(void*,s32,s32);
extern "C" void* fn_801F856C();
extern "C" s32 fn_801F8544(void*,u32,s32,void*,u32);
extern "C" s32 Actor_CreateByID(void*,u32,s32,void*,u32,s32,s32);
extern "C" void* fn_801F666C(void*,s32);
extern "C" float __fabsf(float);
extern const f32 lbl_8053CE38,lbl_8053CE40,lbl_8053CE44,lbl_8053CE48,lbl_8053CE4C,lbl_8053CE58,lbl_8053CE5C,lbl_8053CE60,lbl_8053CE70,lbl_8053CE74;
extern const f64 lbl_8053CE68;
extern s32 lbl_8049F1F8[];
extern f32 lbl_8049F1A0[];
extern "C" double fabs(double);
#pragma opt_strength_reduction off
extern "C" void fn_8013FD50(u8* p) {
    f32 negSize;
    f32 size;
    JGeometry::TVec3<f32> oldPos;
    JGeometry::setTVec3f((f32*)(p+0xc), &oldPos.x);
    JGeometry::TVec3<f32> velocity;
    JGeometry::TVec3<f32> pos;
    s32 quad = -1;
    f32 distance = lbl_8053CE28;
    u16 angle = 0;
    int flag;
    if ((*(u32*)(p+0x90))==2) fn_8030C210(*(void**)(lbl_8053AB10+0x24));
    fn_801F71A4(p+0x260,(*(f32*)(p+0x264)),lbl_8053CE30,(*(f32*)(p+0x26c)));
    flag=1;
    if ((*(u32*)(p+0x90))==1 && (*(s32*)(p+0x108))>0) flag=0;
    if ((*(u32*)(p+0x90))==1) {
        (*(f32*)(p+0x268))=0.7f+(f32)(48-(*(s32*)(p+0x108)))/80.0f;
        size=4.0f+(f32)(48-(*(s32*)(p+0x108)))/6.0f;
        negSize=-size; (*(f32*)(p+0x60))=negSize; (*(f32*)(p+0x64))=negSize; (*(f32*)(p+0x68))=size; (*(f32*)(p+0x6c))=size;
        if((*(f32*)(p+0x268))>1.0f) (*(f32*)(p+0x268))=1.0f;
        if((*(s32*)(p+0x230))!=1) {
            (*(f32*)(p+0x264))=(*(f32*)(p+0x268));
            if((*(s32*)(p+0xd8))==0) {
                if((*(s32*)(p+0x248))==0) {
                    (*(s32*)(p+0x248))=4; (*(s32*)(p+0x108))++;
                    if((*(s32*)(p+0x108))>48) (*(s32*)(p+0x108))=48;
                }
                (*(f32*)(p+0x26c))=lbl_8053CE44;
            } else (*(f32*)(p+0x26c))=lbl_8053CE48;
        }
    }
    if(fn_801F3D94(p,(u8)flag)) {
        if((*(u32*)(p+0x90))==1 && (*(s32*)(p+0x108))>0) {
            (*(s32*)(p+0x248))=4; (*(f32*)(p+0x44))=lbl_8053CE28; (*(f32*)(p+0x40))=lbl_8053CE28; (*(f32*)(p+0x3c))=lbl_8053CE28;
        } else { fn_801F2618(p,0,0); return; }
    }
    if(fn_801F305C(p)) {
        if((*(u32*)(p+0x90))==1 && (*(s32*)(p+0x108))>0) {
            (*(s32*)(p+0x248))=4; (*(f32*)(p+0x44))=lbl_8053CE28; (*(f32*)(p+0x40))=lbl_8053CE28; (*(f32*)(p+0x3c))=lbl_8053CE28;
            (*(f32*)(p+0x260))=lbl_8053CE4C*(*(f32*)(p+0x268));
        } else { fn_801F2618(p,0,0); return; }
    }
    if((*(s32*)(p+0x234))>0) (*(s32*)(p+0x234))--;
if((*(s32*)(p+0x238))>0) (*(s32*)(p+0x238))--;
if((*(s32*)(p+0x23c))>0) (*(s32*)(p+0x23c))--;
if((*(s32*)(p+0x240))>0) (*(s32*)(p+0x240))--;
if((*(s32*)(p+0x244))>0) (*(s32*)(p+0x244))--;
if((*(s32*)(p+0x248))>0) (*(s32*)(p+0x248))--;
    fn_801F71A4(p+0x3c,(*(f32*)(p+0x27c)),lbl_8053CE50,lbl_8053CE2C);
    fn_801F71A4(p+0x40,(*(f32*)(p+0x280)),lbl_8053CE50,lbl_8053CE2C);
    ((JGeometry::TVec3<f32>*)(p+0xc))->add(*(JGeometry::TVec3<f32>*)(p+0x3c));
    fn_801F2B7C(p,-100,-1,1);
    u8 collision=fn_801F2618(p,0,0);
    switch((*(s32*)(p+0x230))) {
    case 0:
        if(collision || (*(s32*)(p+0x234))==0) {
            (*(f32*)(p+0x3c))=lbl_8053CE28; (*(f32*)(p+0x40))=lbl_8053CE28; (*(f32*)(p+0x44))=lbl_8053CE28;
            if((*(u32*)(p+0x90))!=2) {
                if(!((*(u32*)(p+0x98))&2)) {
                    if(lbl_8053AAF8->rnd.get_ufloat_1()<lbl_8053CE48) {
                        { f32 speed=(*(f32*)(p+0x25c)); (*(f32*)(p+0x27c))=lbl_8053CE28; (*(f32*)(p+0x280))=speed; (*(f32*)(p+0x284))=lbl_8053CE28; } (*(s32*)(p+0x98))=2;
                    } else {
                        { f32 speed=-(*(f32*)(p+0x25c)); (*(f32*)(p+0x27c))=lbl_8053CE28; (*(f32*)(p+0x280))=speed; (*(f32*)(p+0x284))=lbl_8053CE28; } (*(s32*)(p+0x98))=3;
                    }
                } else {
                    if(lbl_8053AAF8->rnd.get_ufloat_1()<lbl_8053CE48) {
                        (*(f32*)(p+0x27c))=(*(f32*)(p+0x25c)); (*(f32*)(p+0x280))=lbl_8053CE28; (*(f32*)(p+0x284))=lbl_8053CE28; (*(s32*)(p+0x98))=0;
                    } else {
                        (*(f32*)(p+0x27c))=-(*(f32*)(p+0x25c)); (*(f32*)(p+0x280))=lbl_8053CE28; (*(f32*)(p+0x284))=lbl_8053CE28; (*(s32*)(p+0x98))=1;
                    }
                }
            }
            if((*(s32*)(p+0x234))==0) (*(s32*)(p+0x234))=(s32)(lbl_8053CE54*lbl_8053AAF8->rnd.get_ufloat_1())+50;
        }
        if((*(u32*)(p+0x90))==0 || (*(u32*)(p+0x90))==3) {
            fn_801EEC98(p,(*(s32*)(p+0x198)),0,&quad,0,0,0,0);
            if(quad==(*(s32*)(p+0x98))) (*(s32*)(p+0x238))=0;
        }
        if((*(u32*)(p+0x90))==2) {
            fn_801EEC98(p,(*(s32*)(p+0x198)),&angle,&quad,&distance,0,0,0);
            if(quad!=-1) {
                (*(s32*)(p+0x98))=quad;
                if(distance<lbl_8053CE58) {
                    angle+=0x8000;
                    angle+=0x2000-((*(s32*)(p+0x274))&15)*0x444;
                    (*(f32*)(p+0x27c))=lbl_8053CE5C*JMath::sincosTable_.mTable[(u32)(u16)angle>>5].first;
                    (*(f32*)(p+0x280))=lbl_8053CE5C*JMath::sincosTable_.mTable[(u32)(u16)angle>>5].second;
                } else { f32 zero=lbl_8053CE28; (*(f32*)(p+0x284))=zero; (*(f32*)(p+0x280))=zero; (*(f32*)(p+0x27c))=zero; }
            }
            if((*(s32*)(*(u8**)((u8*)lbl_8053AAF8+4)+0x34))%(*(s32*)(p+0x270))==0) {
                (*(s32*)(p+0x238))=0; (*(s32*)(p+0x23c))=0;
            }
        }
        if((*(u32*)(p+0x90))!=3 && (*(s32*)(p+0x238))==0 && (*(s32*)(p+0x23c))==0) {
            (*(s32*)(p+0x24c))=0; (*(s32*)(p+0x250))=0; (*(s32*)(p+0x254))=0; (*(s32*)(p+0x258))=0;
            switch((*(s32*)(p+0x98))) {
            case 0:(*(s32*)(p+0x254))=2;break;
            case 1:(*(s32*)(p+0x254))=0;break;
            case 2:(*(s32*)(p+0x254))=1;break;
            case 3:(*(s32*)(p+0x254))=3;break;
            }
            (*(f32*)(p+0x27c))=lbl_8053CE28; (*(f32*)(p+0x280))=lbl_8053CE28; (*(f32*)(p+0x284))=lbl_8053CE28;
            (*(s32*)(p+0x23c))=8;
            if((*(u32*)(p+0x90))==0) { (*(s32*)(p+0x250))=3; (*(s32*)(p+0x23c))=20; }
            if((*(u32*)(p+0x90))==2 || (*(u32*)(p+0x90))==1) {
                (*(f32*)(p+0x264))=lbl_8053CE4C*(*(f32*)(p+0x268)); (*(f32*)(p+0x26c))=lbl_8053CE50; (*(s32*)(p+0x230))=1;
            } else (*(s32*)(p+0x230))=2;
        }
        break;
    case 1:
        if((f32)fabs((*(f32*)(p+0x260))-(*(f32*)(p+0x264)))>lbl_8053CE60) break;
        (*(s32*)(p+0x250))++; (*(s32*)(p+0x24c))++; (*(s32*)(p+0x244))=0; (*(s32*)(p+0x258))=0;
        (*(f32*)(p+0x264))=(*(f32*)(p+0x268)); (*(f32*)(p+0x260))=(*(f32*)(p+0x268)); (*(s32*)(p+0x230))=2;
    case 2:
        if((*(s32*)(p+0x244))==0) {
            (*(s32*)(p+0x244))=4; (*(s32*)(p+0x258))++; if((*(s32*)(p+0x258))>5) (*(s32*)(p+0x258))=0;
        }
        if((*(s32*)(p+0x23c))==0) {
            (*(s32*)(p+0x23c))=8;
            if((*(s32*)(p+0x24c))==0) {
                (*(s32*)(p+0x250))++; (*(s32*)(p+0x24c))++;
                if((*(s32*)(p+0x250))>4) {
                    switch((*(s32*)(p+0x98))) {
case 0: (*(f32*)(p+0x27c))=(*(f32*)(p+0x25c)); (*(f32*)(p+0x280))=lbl_8053CE28; (*(f32*)(p+0x284))=lbl_8053CE28; break;
case 1: (*(f32*)(p+0x27c))=-(*(f32*)(p+0x25c)); (*(f32*)(p+0x280))=lbl_8053CE28; (*(f32*)(p+0x284))=lbl_8053CE28; break;
case 2: { f32 speed=(*(f32*)(p+0x25c)); (*(f32*)(p+0x27c))=lbl_8053CE28; (*(f32*)(p+0x280))=speed; (*(f32*)(p+0x284))=lbl_8053CE28; } break;
case 3: { f32 speed=-(*(f32*)(p+0x25c)); (*(f32*)(p+0x27c))=lbl_8053CE28; (*(f32*)(p+0x280))=speed; (*(f32*)(p+0x284))=lbl_8053CE28; } break;
}
                    (*(s32*)(p+0x234))=(s32)(lbl_8053CE54*lbl_8053AAF8->rnd.get_ufloat_1())+50;
                    (*(s32*)(p+0x238))=(s32)(lbl_8053CE54*lbl_8053AAF8->rnd.get_ufloat_1())+100;
                    (*(s32*)(p+0x23c))=(s32)(lbl_8053CE68*(*(s32*)(p+0x238)));
                    if((*(u32*)(p+0x90))==2) (*(s32*)(p+0x238))=10000;
                    (*(s32*)(p+0x230))=0;
                }
            } else {
                if((*(u32*)(p+0x90))!=2) (*(s32*)(p+0x98))=lbl_8049F1F8[(*(s32*)(p+0x254))];
                switch((*(s32*)(p+0x98))) {
                case 0:velocity.set(3.0f,0.0f,0.0f);break;
                case 1:velocity.set(-3.0f,0.0f,0.0f);break;
                case 2:velocity.set(lbl_8053CE28,lbl_8053CE70,lbl_8053CE28);break;
                case 3:velocity.set(lbl_8053CE28,lbl_8053CE74,lbl_8053CE28);break;
                }
                (*(s32*)(p+0x254))++; (*(u32*)(p+0x254))&=3;
                if((*(u32*)(p+0x90))==0) (*(s32*)(p+0x23c))=20;
                pos.x=(*(f32*)(p+0xc)); pos.y=(*(f32*)(p+0x10)); pos.z=(*(f32*)(p+0x14));
                pos.x+=lbl_8049F1A0[(*(s32*)(p+0x98))*2]; pos.y+=lbl_8049F1A0[(*(s32*)(p+0x98))*2+1];
                fn_801F0E34(p,0x4000a,0);
                s32 id;
                switch((s32)(lbl_8053CE54*lbl_8053AAF8->rnd.get_ufloat_1())) {
                case 0:id=fn_801F8544(fn_801F856C(),0x52555059,(*(s32*)(p+0x4)),&pos,0x20002);break;
                default:id=Actor_CreateByID(fn_801F856C(),0x4f4b544d,(*(s32*)(p+0x4)),&pos,0,-1,-1);break;
                }
                if(id>=0) {
                    u8* actor=(u8*)fn_801F666C(fn_801F856C(),id);
                    if(actor) {
                        *(JGeometry::TVec3<f32>*)(actor+0x3c)=velocity;
                        *(s32*)(actor+0x98)=(*(s32*)(p+0x98));
                    }
                }
                (*(s32*)(p+0x24c))=0;
            }
        }
        break;
    }
}
#pragma opt_strength_reduction reset
extern "C" void fn_80140920(u8* this_) {
    f32 random;
    *(f32*)(this_ + 0x60) = lbl_8053CE80;
    *(f32*)(this_ + 0x64) = lbl_8053CE80;
    *(f32*)(this_ + 0x68) = lbl_8053CE84;
    *(f32*)(this_ + 0x6c) = lbl_8053CE84;
    *(f32*)(this_ + 0x80) = lbl_8053CE80;
    *(f32*)(this_ + 0x84) = lbl_8053CE28;
    *(f32*)(this_ + 0x88) = lbl_8053CE84;
    *(f32*)(this_ + 0x8c) = lbl_8053CE84;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(s32*)(this_ + 0x254) = 0;
    *(s32*)(this_ + 0x258) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(f32*)(this_ + 0x260) = lbl_8053CE2C;
    *(f32*)(this_ + 0x264) = lbl_8053CE2C;
    *(f32*)(this_ + 0x268) = lbl_8053CE2C;
    *(f32*)(this_ + 0x26c) = lbl_8053CE50;
    *(s32*)(this_ + 0x274) = lbl_8053AB28 & 31;
    lbl_8053AB28++;
    *(u32*)(this_ + 0x90) &= 0xff;
    random = lbl_8053AAF8->rnd.get_ufloat_1();
    *(s32*)(this_ + 0x98) = (s32)(lbl_8053CE88 * random) & 3;
    *(u32*)(this_ + 0xb0) = 0x11101;
    *(s32*)(this_ + 0x270) = 0;
    *(f32*)(this_ + 0x25c) = lbl_8053CE2C;
    this_[0x278] = 3;
    random = lbl_8053AAF8->rnd.get_ufloat_1();
    *(s32*)(this_ + 0x234) = (s32)(lbl_8053CE54 * random) + 0x32;
    random = lbl_8053AAF8->rnd.get_ufloat_1();
    *(s32*)(this_ + 0x238) = (s32)(lbl_8053CE54 * random) + 0x64;
    switch (*(s32*)(this_ + 0x90)) {
    case 0: break;
    case 1: {
        *(f32*)(this_ + 0x25c) = lbl_8053CE8C;
        *(s32*)(this_ + 0xc0) = 3;
        *(s32*)(this_ + 0x108) = 0x30;
        *(f32*)(this_ + 0x260) = lbl_8053CE34;
        *(f32*)(this_ + 0x264) = lbl_8053CE34;
        *(f32*)(this_ + 0x268) = lbl_8053CE34;
        this_[0x278] = 4;
        *(f32*)(this_ + 0x60) = lbl_8053CE90;
        *(f32*)(this_ + 0x64) = lbl_8053CE90;
        *(f32*)(this_ + 0x68) = lbl_8053CE3C;
        *(f32*)(this_ + 0x6c) = lbl_8053CE3C;
        *(f32*)(this_ + 0x80) = lbl_8053CE94;
        *(f32*)(this_ + 0x84) = lbl_8053CE90;
        *(f32*)(this_ + 0x88) = lbl_8053CE98;
        *(f32*)(this_ + 0x8c) = lbl_8053CE98;
    } break;
    case 2: {
        *(s32*)(this_ + 0x238) = 10000;
        *(s32*)(this_ + 0x270) = 400;
        *(u32*)(this_ + 0xb8) = 1;
        this_[0x278] = 5;
    } break;
    case 3:
    default: break;
    }
    switch (*(s32*)(this_ + 0x98)) {
    case 0:
        *(f32*)(this_ + 0x27c) = *(f32*)(this_ + 0x25c);
        *(f32*)(this_ + 0x280) = lbl_8053CE28;
        *(f32*)(this_ + 0x284) = lbl_8053CE28;
        break;
    case 1:
        *(f32*)(this_ + 0x27c) = -*(f32*)(this_ + 0x25c);
        *(f32*)(this_ + 0x280) = lbl_8053CE28;
        *(f32*)(this_ + 0x284) = lbl_8053CE28;
        break;
    case 2: {
        f32 speed = *(f32*)(this_ + 0x25c);
        *(f32*)(this_ + 0x27c) = lbl_8053CE28;
        *(f32*)(this_ + 0x280) = speed;
        *(f32*)(this_ + 0x284) = lbl_8053CE28;
        break;
    }
    case 3: {
        f32 speed = -*(f32*)(this_ + 0x25c);
        *(f32*)(this_ + 0x27c) = lbl_8053CE28;
        *(f32*)(this_ + 0x280) = speed;
        *(f32*)(this_ + 0x284) = lbl_8053CE28;
        break;
    }
    }
    *(s32*)(this_ + 0x230) = 0;
}
#pragma opt_common_subs reset
#include "JSystem/JAudio/JASFakeMatchFSA.h"
#include "JSystem/JMath/JMath.h"
