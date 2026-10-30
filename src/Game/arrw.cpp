// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 8016545C-80166BD0 (ARRW). Remaining functions are not yet decompiled.
#include "types.h"
#include "Game/HitRect.h"
#include "JSystem/JParticle/JPAEmitter.h"
#include "JSystem/JMath/JMath.h"

// from src/Game/fn_801662D8_dtor.cpp
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern void* lbl_804A05E0[];

extern "C" void* fn_801662D8(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A05E0;
        char* p = (char*)this_;
        for (s32 i = 0; i < 2; i++) {
            fn_801EE434(*(void**)(p + 0x278));
            p += 4;
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" u8 fn_8022B160(void);
extern "C" s32 fn_8022F340(u32 params);
extern s32 lbl_804C6330[];

// ARRW init (vtable slot 1)
extern "C" void fn_80166814(char* this_) {
    *(u32*)(this_ + 0x98) = (*(u32*)(this_ + 0x90) >> 4) & 3;
    *(u16*)(this_ + 0x94) = (*(u32*)(this_ + 0x90) >> 8) & 0xf;
    *(u32*)(this_ + 0x90) = *(u32*)(this_ + 0x90) & 3;
    if (fn_8022B160()) {
        lbl_804C6330[fn_8022F340(*(u32*)(this_ + 0x90))]++;
    }
    *(s32*)(this_ + 0x278) = 0;
    *(s32*)(this_ + 0x27c) = 0;
    *(f32*)(this_ + 0x60) = -2.0f;
    *(f32*)(this_ + 0x64) = -2.0f;
    *(f32*)(this_ + 0x68) = 2.0f;
    *(f32*)(this_ + 0x6c) = 2.0f;
    *(f32*)(this_ + 0x80) = -2.0f;
    *(f32*)(this_ + 0x84) = -2.0f;
    *(f32*)(this_ + 0x88) = 2.0f;
    *(f32*)(this_ + 0x8c) = 2.0f;
    *(s32*)(this_ + 0x258) = 0;
    *(s32*)(this_ + 0x25c) = 0;
    *(s32*)(this_ + 0x260) = 0;
    *(s32*)(this_ + 0x264) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(s32*)(this_ + 0x254) = 0;
    switch (*(s32*)(this_ + 0x98)) {
    case 0:
        *(f32*)(this_ + 0x3c) = 5.0f;
        *(f32*)(this_ + 0x40) = 0.0f;
        *(f32*)(this_ + 0x44) = 0.0f;
        break;
    case 1:
        *(f32*)(this_ + 0x3c) = -5.0f;
        *(f32*)(this_ + 0x40) = 0.0f;
        *(f32*)(this_ + 0x44) = 0.0f;
        break;
    case 2:
        *(f32*)(this_ + 0x3c) = 0.0f;
        *(f32*)(this_ + 0x40) = 5.0f;
        *(f32*)(this_ + 0x44) = 0.0f;
        break;
    case 3:
        *(f32*)(this_ + 0x3c) = 0.0f;
        *(f32*)(this_ + 0x40) = -5.0f;
        *(f32*)(this_ + 0x44) = 0.0f;
        break;
    }
    *(f32*)(this_ + 0x234) = 255.0f;
    *(s32*)(this_ + 0x24c) = 500;
    *(u8*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x26c) = 0;
    *(s32*)(this_ + 0x270) = 0;
    *(s32*)(this_ + 0x108) = 10000;
    *(s32*)(this_ + 0x268) = *(s32*)(this_ + 0x98);
    *(s32*)(this_ + 0x230) = 0;
    *(u8*)(this_ + 0x274) = 0;
}

#include "JSystem/JUtility/TColor.h"
#include "dolphin/gx/GXStruct.h"
struct ArrwDrawParam {
    ArrwDrawParam() : m40(-1), m44(-1) {
        for (u8 i = 0; i < 16; i++) {
            mIdx[i] = i;
        }
    }
    void reset() {
        m40 = -1;
        m44 = 0;
        mMtx = NULL;
        m4C = 0;
        m4D = 0;
        m4E = 0;
        m4F = 1;
        m50 = 1;
        m51 = 0;
        m52 = 0;
        m53 = 0;
        m54 = 0;
        m55 = 0;
        m56 = 1;
        m58 = 3;
        m5C = 1;
        m5D = 0;
        m5E = 0;
        m60 = -1;
        m64 = 0;
        m68 = 2;
    }
    u8 mIdx[16];
    s32 m40;
    s32 m44;
    f32 (*mMtx)[4];
    u8 m4C, m4D, m4E, m4F, m50, m51, m52, m53, m54, m55, m56;
    s32 m58;
    u8 m5C, m5D, m5E;
    s32 m60;
    s32 m64;
    s32 m68;
};
struct ArrwResMgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* get(u32 type, const char* name);
};
extern const char lbl_8046630C[];
extern char* lbl_8053AAF8;
extern char* lbl_8053AB10;
extern const f32 lbl_8053D7C0;
extern const f32 lbl_8053D7C4;
extern "C" void fn_802F86CC(void* map, void* pos, void* res, f32 a, f32 b, s32 id, ArrwDrawParam* prm);
extern "C" void fn_803075AC(u32 callerID, u32 ownerID, void* pos, s32 effectRef, s32 flag,
                            s32 mode, s32 targetPlayerIdx, s32 kind, s32 stackArg9, s32 stackArg10);
extern "C" void fn_80158B5C(void* obj, u32 id, void* pos, GXColor color, f32 f);

extern "C" void fn_8016545C(char* p) {
    if (*(u16*)(p + 0x94) == 3) {
        return;
    }
    if (*(s32*)(p + 0x24c) >= 0x32 || !(*(s32*)(p + 0x24c) & 2)) {
        ArrwDrawParam prm;
        prm.reset();
        prm.mIdx[0x13] = (s32)*(f32*)(p + 0x234);
        prm.m4D = 1;
        if (fn_8022B160() == 1) {
            switch (*(s32*)(p + 0x90)) {
            case 0:
                prm.m60 = 0;
                break;
            case 1:
                prm.m60 = 1;
                break;
            case 2:
                prm.m60 = 2;
                break;
            case 3:
                prm.m60 = 3;
                break;
            }
        }
        s32 id = *(s32*)(p + 0x268) + 0x4c;
        if (*(s32*)(p + 4) < 8) {
            void* res = (*(ArrwResMgr**)(lbl_8053AAF8 + 0xa4))->get(0x534f4220, lbl_8046630C);
            fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), p + 0xc, res, lbl_8053D7C0, lbl_8053D7C0, id, &prm);
        }
        s32 eff = 0x4c;
        if ((*(u16*)(p + 0x94) == 0 || *(u16*)(p + 0x94) == 4) && *(s32*)(p + 0x230) == 0) {
            eff = 0x2df;
        }
        fn_803075AC(*(u32*)(p + 0x198), *(u32*)(p + 4), p + 0xc, eff + *(s32*)(p + 0x268), 0, 2, -1, 0, 0, 0);
    }
    if ((*(u16*)(p + 0x94) == 2 || *(u16*)(p + 0x94) == 4) && *(s32*)(p + 0x230) != 4) {
        u32 id = *(u32*)(p + 4);
        JUtility::TColor color(0, 0, 0, 0x80);
        fn_80158B5C(*(void**)(lbl_8053AB10 + 0x2c), id, p + 0xc, color, lbl_8053D7C4);
    }
}

extern "C" u8 fn_8023F264(s32 i);
extern "C" u8 fn_8022E438(s32 i, u32 a);
extern "C" u8 fn_8023B190(s32 i, u32 a, void* pos);
extern "C" void fn_8022E1A0(s32 i, u32 a);
struct ArrwTables {
    JGeometry::TVec2<f32> offsets[4];
    s32 directions[4];
    s32 frames[32];
};
extern const u8 lbl_804A0530[];
extern const s32 lbl_804662FC[];
extern const f32 lbl_8053D7C8;
extern const f32 lbl_8053D7CC;
extern const f32 lbl_8053D7D0;
extern const f32 lbl_8053D7D4;
extern const f32 lbl_8053D7D8;
extern const f32 lbl_8053D7DC;
extern const f32 lbl_8053D7E0;
extern const f32 lbl_8053D7E4;
extern const f32 lbl_8053D7E8;
extern void* lbl_8053AC98;
extern "C" s32 fn_801F2718(void*,u32);
extern "C" void* fn_801F856C();
extern "C" char* fn_801F666C(void*,s32);
extern "C" void* fn_8013CC50(s32,void*,u32,f32,s32,s32,s32,s32,s32);
extern "C" void fn_8013CB44(void*,void*,s32,s32,s32);
extern "C" void fn_801F0E34(void*,u32,s32);
extern "C" u8 fn_801F2B7C(void*,u32,u32,s32);
extern "C" u8 fn_801F2A10(void*,u32,s32,s32,s32);
extern "C" s16 fn_801F6874(s32);
extern "C" void fn_802A20F0(void*,void*,u32,s32,s32,s32);
extern "C" void fn_80238548(s32,s32,void*,s32);
extern "C" u8 fn_801F2618(void*,void*,s32);
extern "C" void Actor_CreateByID(void*,u32,s32,void*,u32,s32,s32);
extern "C" void fn_8030C210(void*,void*);
extern "C" void fn_801F71A4(f32*,f32,f32,f32);
extern "C" void JPAGetXYZRotateMtx__FsssPA4_f(s16,s16,s16,void*);
#pragma opt_propagation off
extern "C" void fn_80165730(char* p) {
 const ArrwTables* table=(const ArrwTables*)lbl_804A0530;
 JGeometry::TVec3<f32> pos;
 s32 index;
 if((*(u16*)(p+0x94))==3) {
   HitBox box; box.set(*(HitBox*)(p+0x60)); box.addPos((*(f32*)(p+0xc)),(*(f32*)(p+0x10)));
   for(index=0;index<4;index++) if(fn_8023F264(index) && !fn_8022E438(index,(*(s32*)(p+0x90))) && ((u8(*)(s32,void*,s32))fn_8023B190)(index,&box,(*(s32*)(p+0x4)))) fn_8022E1A0(index,(*(s32*)(p+0x198)));
   return;
 }
 if((*(s32*)(p+0x230))!=4) {
   index=fn_801F2718(p,'FLME');
   if(index<0) {
     index=fn_801F2718(p,'BLZ2');
     if(index>=0) {char* a=fn_801F666C(fn_801F856C(),index); if(!a) index=-1; else if(*(u16*)(a+0x94)==0) index=-1;}
   }
   if(index>=0) {
     (*(f32*)(p+0x3c))=(*(f32*)(p+0x40))=(*(f32*)(p+0x44))=lbl_8053D7C8;
     (*(void**)(p+0x278))=fn_8013CC50((*(s32*)(p+0x4)),p+0xc,0xbd,lbl_8053D7C0,0,1,0,0,1);
     (*(s32*)(p+0x26c))=2; (*(s32*)(p+0x108))=0; (*(s32*)(p+0x258))=0; (*(s32*)(p+0x244))=20; fn_801F0E34(p,0x30005,0); (*(s32*)(p+0x230))=4;
   }
 }
 ((JGeometry::TVec3<f32>*)(p+0xc))->add(*(JGeometry::TVec3<f32>*)(p+0x3c));
 if(((*(u16*)(p+0x94))==2 || (*(u16*)(p+0x94))==4) && (*(s32*)(p+0x230))!=4) {
   if((*(s32*)(p+0x260))==0) {(*(void**)(p+0x278))=fn_8013CC50((*(s32*)(p+0x4)),p+0xc,0xbd,lbl_8053D7C0,0,1,0,0,1); (*(s32*)(p+0x260))=1;}
   if((*(void**)(p+0x278))) {
     pos.set(*(JGeometry::TVec3<f32>*)(p+0xc));
     const JGeometry::TVec2<f32>* offsets=table->offsets;
     pos.x+=offsets[(*(s32*)(p+0x98))].x; pos.y+=offsets[(*(s32*)(p+0x98))].y;
     fn_8013CB44((*(void**)(p+0x278)),&pos,0,2,1);
     s32 dir=(*(s32*)(p+0x98)); s32 rot=0; if(dir==2) rot=lbl_804662FC[dir];
     s16 zrot=lbl_804662FC[dir]; JPAGetXYZRotateMtx__FsssPA4_f(-1,rot,zrot,(char*)(*(void**)(p+0x278))+0x68);
   }
   fn_8013CB44((*(void**)(p+0x27c)),p+0xc,0,1,1);
   (*(f32*)(p+0x60))=lbl_8053D7CC; (*(f32*)(p+0x64))=lbl_8053D7CC; (*(f32*)(p+0x68))=lbl_8053D7D0; (*(f32*)(p+0x6c))=lbl_8053D7D0;
   (*(f32*)(p+0x70))=lbl_8053D7CC; (*(f32*)(p+0x74))=lbl_8053D7CC; (*(f32*)(p+0x78))=lbl_8053D7D0; (*(f32*)(p+0x7c))=lbl_8053D7D0;
   fn_801F2B7C(p,(*(s32*)(p+0x114)),(*(s32*)(p+0x90)),7);
 }
 switch((*(s32*)(p+0x230))) {
 case 0:
   if((*(s32*)(p+0x24c))==0) (*(u8*)(p+0x11c))=0;
   if(((*(u8*)(p+0x274))==0 && fn_801F2A10(p,(*(s32*)(p+0x90)),(*(s32*)(p+0x98)),1,1)) || (*(s32*)(p+0x108))==0) {
     if((*(s32*)(p+0x98))==3) {
       if(((JMath::TRandom_fast_*)(lbl_8053AAF8+0xb4))->get_ufloat_1()<lbl_8053D7D4) (*(f32*)(p+0x3c))=lbl_8053D7D8;
       else (*(f32*)(p+0x3c))=lbl_8053D7DC;
     }
     (*(f32*)(p+0x3c))*=lbl_8053D7E0; (*(f32*)(p+0x40))*=lbl_8053D7E0; (*(f32*)(p+0x44))=lbl_8053D7D8;
     fn_801F0E34(p,0x400d1,0); (*(s32*)(p+0x248))=100;
     switch((*(s32*)(p+0x98))) {case 0:(*(s32*)(p+0x258))=3;break;case 1:(*(s32*)(p+0x258))=1;break;case 2:(*(s32*)(p+0x258))=0;break;case 3:(*(s32*)(p+0x258))=2;break;}
     (*(s32*)(p+0x26c))=2;(*(s32*)(p+0x108))=0;
     fn_8013CC50((*(s32*)(p+0x4)),p+0xc,0x117,lbl_8053D7C0,0,1,0,0,1);
     fn_8013CC50((*(s32*)(p+0x4)),p+0xc,0x118,lbl_8053D7C0,0,1,0,0,1);
     (*(s32*)(p+0x230))=1;
   } else {
     if((*(u16*)(p+0x94))==0 || (*(u16*)(p+0x94))==4) {
       if(!(*(void**)(p+0x27c))) {
         s32 effect=0; switch((*(s32*)(p+0x98))){case 0:effect=0x283;break;case 1:effect=0x282;break;case 2:effect=0x281;break;case 3:effect=0x284;break;}
         (*(void**)(p+0x27c))=fn_8013CC50((*(s32*)(p+0x4)),p+0xc,effect,lbl_8053D7C0,0,1,0,0,1);
       } else fn_8013CB44((*(void**)(p+0x27c)),p+0xc,0,1,1);
       index=fn_801F6874((*(s32*)(p+0x98)));
       index+=0x2000;
       for(s32 i=0;i<2;i++,index-=0x4000) {
         pos.set(*(JGeometry::TVec3<f32>*)(p+0xc));
         pos.x+=lbl_8053D7D0*JMath::sincosTable_.mTable[(u16)index>>5].first;
         pos.y+=lbl_8053D7D0*JMath::sincosTable_.mTable[(u16)index>>5].second;
         fn_802A20F0(lbl_8053AC98,&pos,(*(s32*)(p+0x90)),(*(s32*)(p+0x4)),0,0);
       }
     }
     HitBox box; box.set(*(HitBox*)(p+0x60)); box.addPos((*(f32*)(p+0xc)),(*(f32*)(p+0x10)));
     if((*(u8*)(p+0x274))==0) {
       for(s32 i=0;i<4;i++) if(fn_8023F264(i) && !fn_8022E438(i,(*(s32*)(p+0x90))) && ((u8(*)(s32,void*,s32))fn_8023B190)(i,&box,(*(s32*)(p+0x4)))) {
         JGeometry::TVec2<f32> center;
         f32 half=lbl_8053D7D4; f32 x=box.f.x; f32 y=box.f.y; center.x=half*(box.i.x-x)+x; center.y=half*(box.i.y-y)+y;
         if((*(u16*)(p+0x94))==0 || (*(u16*)(p+0x94))==4) {
           if(((u8*)lbl_8053AAF8)[0x7f]) fn_80238548(i,0,&center,0); else fn_80238548(i,2,&center,0);
           fn_8022E1A0(i,(*(s32*)(p+0x198)));
         } else {
           if(((u8*)lbl_8053AAF8)[0x7f]) fn_80238548(i,0,&center,1); else fn_80238548(i,1,&center,1);
           (*(u8*)(p+0x11c))=0;
         }
         (*(u8*)(p+0x274))=1;
       }
     }
     if(fn_801F2618(p,0,0)) {
       if((*(u16*)(p+0x94))==2 || (*(u16*)(p+0x94))==4) Actor_CreateByID(fn_801F856C(),'BLZE',(*(s32*)(p+0x4)),p+0xc,(*(s32*)(p+0x90))&3,-1,-1);
       s32 one=1; s32 zero=0;
       (*(s32*)(p+0x26c))=one;(*(s32*)(p+0x108))=zero;
       if((*(void**)(p+0x27c))){JPABaseEmitter* emitter=(JPABaseEmitter*)(*(void**)(p+0x27c)); emitter->mFlags|=1; emitter->mMaxFrame=one; (*(void**)(p+0x27c))=(void*)zero;}
       (*(f32*)(p+0x44))=(*(f32*)(p+0x40))=(*(f32*)(p+0x3c))=lbl_8053D7C8; (*(s32*)(p+0x258))=0;(*(s32*)(p+0x244))=0;(*(s32*)(p+0x230))=2;
     } else {
       if((*(s32*)(p+0x258))!=(*(s32*)(p+0x270))){(*(s32*)(p+0x258))=(*(s32*)(p+0x270));fn_801F0E34(p,0x3001d,0);}
       if((*(s32*)(p+0x4))<8) fn_8030C210(*(void**)(lbl_8053AB10+0x24),p+0xc);
     }
   }
   break;
 case 1: {
   if(!((*(s32*)(p+0x248))&1)){(*(s32*)(p+0x258))++;const s32* directions=table->directions;(*(s32*)(p+0x258))&=3;(*(s32*)(p+0x98))=directions[(*(s32*)(p+0x258))];}
   s32 one=1; s32 zero=0;
   if((*(void**)(p+0x278))){JPABaseEmitter* emitter=(JPABaseEmitter*)(*(void**)(p+0x278)); emitter->mFlags|=1; emitter->mMaxFrame=one; (*(void**)(p+0x278))=(void*)zero;} if((*(void**)(p+0x27c))){JPABaseEmitter* emitter=(JPABaseEmitter*)(*(void**)(p+0x27c)); emitter->mFlags|=1; emitter->mMaxFrame=one; (*(void**)(p+0x27c))=(void*)zero;}
   fn_801F71A4(&(*(f32*)(p+0x234)),lbl_8053D7C8,lbl_8053D7D4,lbl_8053D7E4);
   (*(f32*)(p+0x44))-=lbl_8053D7E8;
   if((*(f32*)(p+0x14))<lbl_8053D7C8) (*(u8*)(p+0x11c))=0;
   break;
 }
 case 2:
   fn_801F0E34(p,0x30000,0); (*(s32*)(p+0x230))=3;
 case 3:
   if((*(s32*)(p+0x4))<8) fn_8030C210(*(void**)(lbl_8053AB10+0x24),p+0xc);
   if((*(s32*)(p+0x244))==0) {(*(s32*)(p+0x244))=1;(*(s32*)(p+0x258))++;if((*(s32*)(p+0x258))==6)(*(s32*)(p+0x244))=30;else if((*(s32*)(p+0x258))>=7)(*(u8*)(p+0x11c))=0;}
   if((*(s32*)(p+0x258))==6 && (*(s32*)(p+0x244))<3)(*(s32*)(p+0x26c))=2;
   break;
 case 4:
   if((*(s32*)(p+0x244))==0){s32 one=1; s32 zero=0; if((*(void**)(p+0x278))){JPABaseEmitter* emitter=(JPABaseEmitter*)(*(void**)(p+0x278)); emitter->mFlags|=1; emitter->mMaxFrame=one; (*(void**)(p+0x278))=(void*)zero;} if((*(void**)(p+0x27c))){JPABaseEmitter* emitter=(JPABaseEmitter*)(*(void**)(p+0x27c)); emitter->mFlags|=1; emitter->mMaxFrame=one; (*(void**)(p+0x27c))=(void*)zero;} (*(u8*)(p+0x11c))=0;}
   break;
 }
 if((*(s32*)(p+0x244))>0) (*(s32*)(p+0x244))--; if((*(s32*)(p+0x248))>0) (*(s32*)(p+0x248))--; if((*(s32*)(p+0x24c))>0) (*(s32*)(p+0x24c))--; if((*(s32*)(p+0x250))>0) (*(s32*)(p+0x250))--; if((*(s32*)(p+0x254))>0) (*(s32*)(p+0x254))--;
 if((*(s32*)(p+0x230))!=4) {
   if((*(s32*)(p+0x230))==0 || (*(s32*)(p+0x230))==1) {
     (*(s32*)(p+0x268))=(*(s32*)(p+0x98));
     if((*(s32*)(p+0x4))>=8 && ((*(u16*)(p+0x94))==0 || (*(u16*)(p+0x94))==4)) {
       (*(s32*)(p+0x268))=(*(s32*)(p+0x98))*3;(*(s32*)(p+0x268))+=(*(s32*)(p+0x264));
       if((*(s32*)(p+0x244))==0){(*(s32*)(p+0x244))=2;(*(s32*)(p+0x264))++;if((*(s32*)(p+0x264))>2)(*(s32*)(p+0x264))=0;}
     }
   }else {s32 dir=(*(s32*)(p+0x98)); const s32* frames=table->frames; s32 frame=(*(s32*)(p+0x258)); (*(s32*)(p+0x268))=frames[dir*8+frame];}
 }
}

#pragma opt_strength_reduction reset
#pragma opt_lifetimes reset
#pragma opt_propagation reset
extern "C" u8* fn_8020D58C();
extern "C" u8 fn_8020D6AC(void* slot, s32 room, void* pos, u32 id, const char* ext);
extern "C" u16 fn_8022461C(void* pos, s32 room);
extern "C" u16 fn_80226850(void* pos, s32 room);
extern "C" char* fn_802D6A9C();
extern const char lbl_804662E8[];

static inline BOOL arrwTick(char* p) {
    if (*(u8*)(p + 0x238) == 0) {
        (*(s32*)(p + 0x240))++;
        if (*(s32*)(p + 0x240) > 0x14) {
            return TRUE;
        }
    }
    return FALSE;
}

extern "C" BOOL fn_8016636C(char* p, s32 room, void* pos) {
    u32 id = *(u32*)(p + 0x198);
    u8* mgr = fn_8020D58C();
    int roomLater = room;
    if (fn_8020D6AC(mgr + 4 + mgr[1] * 0x784, room, pos, id, lbl_804662E8) == 1) {
        return TRUE;
    }
    s32 kind = fn_8022461C(pos, room);
    s32 attr = fn_80226850(pos, room);
    if ((u32)(kind - 0x10) <= 7 || (attr >= 0x140 && attr <= 0x15f)) {
        *(s32*)(p + 0x23c) = 0;
        *(u8*)(p + 0x238) = 1;
        return FALSE;
    }
    if ((*(u16*)(p + 0x94) == 0 || *(u16*)(p + 0x94) == 4) && attr >= 0x40 && attr <= 0x9a) {
        return FALSE;
    }
    if ((u32)(attr - 0x230) <= 1 || attr == 0x234) {
        *(u8*)(p + 0x238) = 0;
        return FALSE;
    }
    if (kind != 0 && kind != 4 && kind != 5 && kind != 6 && kind != 7 && kind != 2 && kind != 3 &&
        kind != 0x50 && kind != 0xe && kind != 0xc && kind != 0x27 && kind != 0x28 && kind != 0x29 &&
        kind != 0x2a && kind != 0x2b && kind != 0x2c && kind != 0x2d && kind != 0x2e && kind != 0x2f &&
        kind != 0x20 && kind != 0xd && kind != 0x39 && kind != 0x3a && kind != 0x3b && kind != 0x4c &&
        kind != 0x4d && kind != 0x4e && kind != 0x4f && kind != 0x24) {
        if ((u32)(kind - 7) <= 1 || kind == 0xa) {
            if (*(s32*)(p + 0x98) == 1) {
                return FALSE;
            }
            return arrwTick(p);
        }
        if (kind == 6 || kind == 9 || kind == 0xb) {
            if (*(s32*)(p + 0x98) == 0) {
                return FALSE;
            }
            return arrwTick(p);
        }
        if (kind == 4) {
            if (*(s32*)(p + 0x98) == 2) {
                return FALSE;
            }
            return arrwTick(p);
        }
        if (kind == 5) {
            if (*(s32*)(p + 0x98) == 3) {
                return FALSE;
            }
            return arrwTick(p);
        }
        if (fn_80226850(pos, roomLater) == 0x3a || fn_80226850(pos, roomLater) == 0x3d) {
            *(u8*)(p + 0x238) = 0;
            return FALSE;
        }
        if (attr == 0x14) {
            *(u8*)(p + 0x238) = 0;
            return FALSE;
        }
        if (kind == 0x25) {
            if (*(u8*)(p + 0x238) == 0 && *(u8*)(fn_802D6A9C() + 0x171) == 0) {
                return TRUE;
            }
            *(u8*)(p + 0x238) = 0;
            return FALSE;
        }
        if (kind == 0x26) {
            if (*(u8*)(p + 0x238) == 0 && *(u8*)(fn_802D6A9C() + 0x171) == 1) {
                return TRUE;
            }
            *(u8*)(p + 0x238) = 0;
            return FALSE;
        }
        if (*(u8*)(p + 0x238) == 0 && (kind != 0x22 || *(u8*)(fn_802D6A9C() + 0x170) == 1)) {
            return TRUE;
        }
        if (*(u8*)(p + 0x238) == 1) {
            return FALSE;
        }
    }
    if (*(u8*)(p + 0x238) == 1) {
        (*(s32*)(p + 0x23c))++;
        if (*(s32*)(p + 0x23c) > 0xb) {
            *(s32*)(p + 0x23c) = 0;
            *(u8*)(p + 0x238) = 0;
        }
    }
    return FALSE;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
