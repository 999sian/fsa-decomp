#include "types.h"
#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"
#include "std/math.h"
#include "Game/ItemBase.h"

extern "C" char lbl_804A0FF8[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_80179150(Actor* p, s16 n)
{
    if (p != NULL) {
        *(void**)p = lbl_804A0FF8;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" void fn_80158624(void* mgr, void* a, void* b, void* col, f32 scale);
extern "C" void fn_801F06F0(void* this_, const char* name, s32 id, DrawRec* rec, s32 p5, f32 a, f32 b);
extern "C" void fn_801F02BC(void* this_, const char* name, s32 id, DrawRec* rec, s32 a, s32 b, s32 c, f32 s0, f32 s1);
extern "C" char lbl_80466868[];
extern void* lbl_8053AB10;
extern "C" void fn_801791B0(Actor* this_) {
    struct ShltColor {
        u32 rgba;
        ShltColor(u32 c) { rgba = c; }
    };
    typedef void (*DrawFn)(void*, void*, void*, ShltColor, f32);
    u8* p = (u8*)this_;
    if (this_->field_90 == 0xd) {
        DrawRec rec;
        rec.b1d = -1;
        fn_801F06F0(this_, lbl_80466868, 0x431, &rec, -1, 1.0f, 1.0f);
        fn_801F02BC(this_, lbl_80466868, 0x431, &rec, -1, 0, 0, 1.0f, 1.0f);
    } else {
        f32 s1 = *(f32*)(p + 0x344) * 0.7f;
        ShltColor c1(0x3f3f1f7f);
        ((DrawFn)fn_80158624)(*(void**)((u8*)lbl_8053AB10 + 0x2c), p + 0x34c, p + 0xc, c1, s1);
        f32 s2 = *(f32*)(p + 0x344);
        ShltColor c2(0x3f3f1f3f);
        ((DrawFn)fn_80158624)(*(void**)((u8*)lbl_8053AB10 + 0x2c), p + 0x34c, p + 0xc, c2, s2);
    }
}

extern "C" void fn_801F71A4(f32* p, f32 a, f32 b, f32 c);
extern "C" f32 lbl_8053DC2C;
extern "C" f32 lbl_8053DC20;
extern "C" Vec lbl_804C0EA0;
extern "C" s32 lbl_8053AB68;
extern "C" s32 lbl_80539F80;
extern "C" s32 lbl_80539F84;
extern "C" const f32 lbl_8053DC28;
extern "C" const f32 lbl_8053DC30;
extern "C" const f32 lbl_8053DC50;
extern "C" const f32 lbl_8053DC54;
extern "C" const f32 lbl_8053DC58;
extern "C" const f32 lbl_8053DC5C;
extern "C" const f32 lbl_8053DC60;
extern "C" void* lbl_8053AF80;
extern "C" void* lbl_8053AAF8;
extern "C" u8 fn_800FE3EC(void*,s32,JGeometry::TVec3<f32>,s32);
extern "C" s32 fn_800FE21C(void*,u8);
extern "C" u8 fn_800FD894(void*,s32,u8*,s32);
extern "C" JGeometry::TVec3<f32> fn_800FD998(void*,JGeometry::TVec3<f32>,s32,s32,u8);
extern "C" void fn_801EEC98(void*,s32,void*,void*,f32*,s32*,s32,s32);
extern "C" void fn_80458880(void*,s32,s32);
extern "C" s32 fn_8023DE58(s32);
extern "C" Vec* fn_8023E724(s32);
extern "C" void* fn_801F856C();
extern "C" void fn_801F6884(void*);
extern "C" s32 fn_801F68E0(void*);
extern "C" s32 Actor_CreateByID(void*,u32,s32,void*,u32,s32,s32);
extern "C" void* fn_8013CC50(s32,void*,u32,f32,s32,s32,s32,s32,s32);
extern "C" void fn_801F0E34(void*,u32,s32);
extern "C" void* fn_802D6A9C();
extern "C" void fn_802D9FF4(void*,s32,s32);
extern "C" void fn_80136798(void*,s32,s32);
extern "C" u8 fn_8022B7C4(s32);
extern "C" void fn_80458F9C(void*,s32);
static inline f32 shltAngle(f32 y, f32 x) {
    f32 radians = JMath::atanTable_.atan2_(y, x);
    return radians * lbl_8053DC54;
}

extern "C" void fn_80179388(Actor* this_) {
 u8* p=(u8*)this_;
 s32 player=0;
 f32 distance=lbl_8053DC28;
 u8 points[32];
 if((*(s32*)(p+0x2f8))!=3) {
  fn_801F71A4(&(*(f32*)(p+0x3c)),(*(f32*)(p+0x370)),lbl_8053DC2C,lbl_8053DC20);
  fn_801F71A4(&(*(f32*)(p+0x40)),(*(f32*)(p+0x374)),lbl_8053DC2C,lbl_8053DC20);
 }
 ((JGeometry::TVec3<f32>*)(p+0xc))->add(*(JGeometry::TVec3<f32>*)(p+0x3c));
 switch((*(s32*)(p+0x2f8))) {
 case 0: if((*(s32*)(p+0x300))==0){(*(s32*)(p+0x300))=300;(*(f32*)(p+0x370))*=lbl_8053DC30;(*(f32*)(p+0x374))*=lbl_8053DC30;} break;
 case 1:
  (*(u16*)(p+0x340))+=(u16)(*(s32*)(p+0x30c));
  (*(f32*)(p+0xc))=(*(f32*)(p+0x348))*JMath::sincosTable_.sinShort((*(u16*)(p+0x340)))+(*(f32*)(p+0x34c));
  (*(f32*)(p+0x10))=(*(f32*)(p+0x348))*JMath::sincosTable_.cosShort((*(u16*)(p+0x340)))+(*(f32*)(p+0x350)); break;
 case 2:
  if(fn_800FE3EC(p+0x230,(*(s32*)(p+0x334)),*(JGeometry::TVec3<f32>*)(p+0xc),(*(s32*)(p+0x4)))){
   (*(s32*)(p+0x338))=fn_800FE21C(p+0x230,0xff); (*(s32*)(p+0x338))*=60;
   if((*(s32*)(p+0x338))==0)(*(s32*)(p+0x338))=3;
   (*(s32*)(p+0x33c))=fn_800FD894(p+0x230,(*(s32*)(p+0x4)),points,32);
   (*(s32*)(p+0x314))=0;(*(s32*)(p+0x318))=0;(*(s32*)(p+0x2f8))=3;(*(s32*)(p+0x2fc))=(*(s32*)(p+0x2f8));
  }else break;
 case 3:
  *(JGeometry::TVec3<f32>*)(p+0x3c)=fn_800FD998(p+0x230,*(JGeometry::TVec3<f32>*)(p+0x358),(*(s32*)(p+0x314)),(*(s32*)(p+0x338)),0xff);
  (*(s32*)(p+0x314))++;
  if((*(s32*)(p+0x314))>(*(s32*)(p+0x338))) {
   (*(s32*)(p+0x314))=0;(*(s32*)(p+0x318))++;
   if((*(s32*)(p+0x318))>=(*(s32*)(p+0x33c)))(*(s32*)(p+0x318))=0;
   fn_800FD894(p+0x230,(*(s32*)(p+0x4)),points,32);
   u8 point=points[(*(s32*)(p+0x318))]; if(point<(*(u8*)(p+0x232))) (*(u8*)(p+0x233))=point;
   (*(f32*)(p+0x358))=(*(f32*)(p+0xc));(*(f32*)(p+0x35c))=(*(f32*)(p+0x10));(*(f32*)(p+0x360))=(*(f32*)(p+0x14));
  }
  break;
 case 4:
  (*(s32*)(p+0x2f8))=5; fn_801EEC98(this_,(*(s32*)(p+0x198)),0,0,&distance,&player,0,0);break;
 case 5: break;
 case 6:
  if((*(s32*)(p+0x328))!=0)fn_80458880(lbl_8053AF80,0x36,-1);
  if(lbl_80539F80<0) goto releasePlayer;
  {s32 room=(*(s32*)(p+0x4));
   if(room!=fn_8023DE58(lbl_80539F80)) goto releasePlayer;
   f32 dx=fn_8023E724(lbl_80539F80)->x-(*(f32*)(p+0xc));
   f32 dy=fn_8023E724(lbl_80539F80)->y-(*(f32*)(p+0x10));
   if(std::sqrtf(dx*dx+dy*dy)>lbl_8053DC50) {
    (*(f32*)(p+0x370))=JMath::sincosTable_.sinShort((s16)(JMath::atanTable_.atan2_(dx,dy)*(65536.0f / 6.2831855f)))*lbl_8053DC50;
    (*(f32*)(p+0x374))=JMath::sincosTable_.cosShort((s16)(JMath::atanTable_.atan2_(dx,dy)*(65536.0f / 6.2831855f)))*lbl_8053DC50;
   } else {
    Vec* v=fn_8023E724(lbl_80539F80);
    (*(f32*)(p+0xc))=v->x;(*(f32*)(p+0x10))=v->y;(*(f32*)(p+0x14))=v->z;
    (*(f32*)(p+0x378))=lbl_8053DC28;(*(f32*)(p+0x374))=lbl_8053DC28;(*(f32*)(p+0x370))=lbl_8053DC28;(*(f32*)(p+0x44))=lbl_8053DC28;(*(f32*)(p+0x40))=lbl_8053DC28;(*(f32*)(p+0x3c))=lbl_8053DC28;
    if((*(s32*)(p+0x300))==0 && (*(s32*)(p+0x310))!=0) {
     fn_801F6884(fn_801F856C());
     if((*(s32*)(p+0x328))==0) {
      for(s32 i=0;i<20;i++) {
       JGeometry::TVec3<f32> pos; pos.set(*(JGeometry::TVec3<f32>*)(p+0xc));
       s16 angle=(i+1)*0xc30;
       pos.x+=lbl_8053DC58*JMath::sincosTable_.mTable[(u16)angle>>5].first;
       pos.y+=lbl_8053DC58*JMath::sincosTable_.mTable[(u16)angle>>5].second;
       if(Actor_CreateByID(fn_801F856C(),'POOH',(*(s32*)(p+0x4)),&pos,0,-1,-1)>=0)fn_8013CC50((*(s32*)(p+0x4)),&pos,0x1fd,lbl_8053DC20,1,1,0,0,1);
      }
      fn_801F0E34(this_,0x50067,0);
     } else {
      fn_802D9FF4(fn_802D6A9C(),(*(s32*)(p+0x32c)),(*(s32*)(p+0x330)));fn_80136798(lbl_8053AAF8,14,0);
     }
     (*(s32*)(p+0x310))=0;
    }
   }
  }
  break;
 releasePlayer:
  fn_801F6884(fn_801F856C());break;
 case 7:
  if(lbl_80539F84>=0 && lbl_8053AB68==(*(s32*)(p+0x4))) {
   f32 dx=(*(f32*)(p+0xc))-lbl_804C0EA0.x;
   f32 dy=(*(f32*)(p+0x10))-lbl_804C0EA0.y;
   s16 angle=(s32)(JMath::atanTable_.atan2_(-dx,-dy)*(65536.0f / 6.2831855f));
   (*(f32*)(p+0x370))=lbl_8053DC50*JMath::sincosTable_.mTable[(u16)angle>>5].first;
   (*(f32*)(p+0x374))=lbl_8053DC50*JMath::sincosTable_.mTable[(u16)angle>>5].second;
   if(std::sqrtf(dx*dx+dy*dy)<lbl_8053DC5C) {(*(f32*)(p+0x378))=lbl_8053DC28;(*(f32*)(p+0x374))=lbl_8053DC28;(*(f32*)(p+0x370))=lbl_8053DC28;(*(f32*)(p+0x44))=lbl_8053DC28;(*(f32*)(p+0x40))=lbl_8053DC28;(*(f32*)(p+0x3c))=lbl_8053DC28; (*(s32*)(p+0x31c))++;}
  }
  if((*(s32*)(p+0x31c))>60 || (lbl_804C0EA0.x==lbl_8053DC28 && lbl_804C0EA0.y==lbl_8053DC28)) {
   lbl_80539F84=-1; lbl_804C0EA0.z=lbl_8053DC28;lbl_804C0EA0.y=lbl_8053DC28;lbl_804C0EA0.x=lbl_8053DC28;
   (*(s32*)(p+0x31c))=0;(*(f32*)(p+0x358))=(*(f32*)(p+0xc));(*(f32*)(p+0x35c))=(*(f32*)(p+0x10));(*(f32*)(p+0x360))=(*(f32*)(p+0x14));(*(s32*)(p+0x2f8))=8;if((*(s32*)(p+0x2fc))==3)(*(s32*)(p+0x2f8))=(*(s32*)(p+0x2fc));
  }
  break;
 case 8: {
  f32 dx=(*(f32*)(p+0xc))-(*(f32*)(p+0x364));f32 dy=(*(f32*)(p+0x10))-(*(f32*)(p+0x368));
  s16 angle=(s32)(JMath::atanTable_.atan2_(-dx,-dy)*(65536.0f / 6.2831855f));
  (*(f32*)(p+0x370))=lbl_8053DC50*JMath::sincosTable_.mTable[(u16)angle>>5].first;
  (*(f32*)(p+0x374))=lbl_8053DC50*JMath::sincosTable_.mTable[(u16)angle>>5].second;
  if(std::sqrtf(dx*dx+dy*dy)<lbl_8053DC5C){(*(f32*)(p+0x378))=lbl_8053DC28;(*(f32*)(p+0x374))=lbl_8053DC28;(*(f32*)(p+0x370))=lbl_8053DC28;(*(s32*)(p+0x2f8))=(*(s32*)(p+0x2fc));}
  break;
 }
 }
 if((*(s32*)(p+0x2f8))==0 || (*(s32*)(p+0x2f8))==1 || (*(s32*)(p+0x2f8))==3 || (*(s32*)(p+0x2f8))==7 || (*(s32*)(p+0x2f8))==8) {
  fn_801EEC98(this_,(*(s32*)(p+0x198)),0,0,&distance,&player,0,0);
  if((*(s32*)(p+0x320))!=0) {
   if(!fn_801F68E0(fn_801F856C()))return;
   (*(s32*)(p+0x310))=1;(*(s32*)(p+0x320))=0;
  }
  if((lbl_80539F80>=0 && (*(s32*)(p+0x320))==0) || (player>=0 && distance<(*(f32*)(p+0x344))-lbl_8053DC60 && !fn_8022B7C4(player))) {
   if(lbl_80539F80==-1) {
    lbl_80539F80=player;
    if(!fn_801F68E0(fn_801F856C())) {(*(s32*)(p+0x320))=1;return;}
    (*(s32*)(p+0x320))=0;(*(s32*)(p+0x310))=1;
   }
   if((*(s32*)(p+0x328))!=0){fn_80458F9C(lbl_8053AF80,60);(*(s32*)(p+0x300))=0x104;}else (*(s32*)(p+0x300))=100;
   (*(s32*)(p+0x2f8))=6;
  }else if((*(s32*)(p+0x2f8))!=7 && (*(s32*)(p+0x2f8))!=8 && lbl_8053AB68==(*(s32*)(p+0x4)) && (lbl_80539F84>=0 || lbl_804C0EA0.x!=lbl_8053DC28 || lbl_804C0EA0.y!=lbl_8053DC28)) {
   lbl_80539F84=1;(*(f32*)(p+0x364))=(*(f32*)(p+0xc));(*(f32*)(p+0x368))=(*(f32*)(p+0x10));(*(f32*)(p+0x36c))=(*(f32*)(p+0x14));(*(s32*)(p+0x31c))=0;(*(s32*)(p+0x2f8))=7;
  }
 }
 if((*(s32*)(p+0x300))>0)(*(s32*)(p+0x300))--;if((*(s32*)(p+0x304))>0)(*(s32*)(p+0x304))--;if((*(s32*)(p+0x308))>0)(*(s32*)(p+0x308))--;
}

extern "C" s32 fn_801F6874(u32 x);
extern "C" u8 sincosTable___5JMath[];
extern "C" Vec lbl_804C0EA0;
extern "C" s32 lbl_8053AB68;
extern "C" s32 lbl_80539F80;
extern "C" s32 lbl_80539F84;
extern "C" void fn_80179F64(Actor* this_)
{
    struct SinCosTable {
        struct Pair { f32 first; f32 second; } mTable[2048];
        f32 sinShort(s16 v) const { return mTable[static_cast<u16>(v) >> 5U].first; }
        f32 cosShort(s16 v) const { return mTable[static_cast<u16>(v) >> 5U].second; }
    };
    u8* p = (u8*)this_;

    *(f32*)(p + 0x60) = -8.0f;
    *(f32*)(p + 0x64) = -8.0f;
    *(f32*)(p + 0x68) = 8.0f;
    *(f32*)(p + 0x6c) = 8.0f;
    *(f32*)(p + 0x80) = -8.0f;
    *(f32*)(p + 0x84) = -8.0f;
    *(f32*)(p + 0x88) = 8.0f;
    *(f32*)(p + 0x8c) = 8.0f;
    *(u32*)(p + 0x328) = (this_->field_90 >> 4) & 0xf;
    *(u32*)(p + 0x32c) = (this_->field_90 >> 8) & 0xf;
    *(u32*)(p + 0x330) = (this_->field_90 >> 12) & 0xf;
    *(u32*)(p + 0x334) = (this_->field_90 >> 16) & 0xff;
    this_->field_90 &= 0xf;
    *(s32*)(p + 0x338) = 0;
    *(s32*)(p + 0x33c) = 0;
    lbl_804C0EA0.z = 0.0f;
    lbl_804C0EA0.y = 0.0f;
    lbl_804C0EA0.x = 0.0f;
    lbl_8053AB68 = -1;
    lbl_80539F80 = -1;
    lbl_80539F84 = -1;
    *(s32*)(p + 0x30c) = 0;
    *(s32*)(p + 0x310) = 0;
    *(s32*)(p + 0x314) = 0;
    *(s32*)(p + 0x318) = 0;
    *(s32*)(p + 0x31c) = 0;
    *(s32*)(p + 0x320) = 0;
    *(s32*)(p + 0x300) = 0;
    *(s32*)(p + 0x304) = 0;
    *(s32*)(p + 0x308) = 0;
    *(s32*)(p + 0x324) = 0;
    *(f32*)(p + 0x344) = 64.0f;
    *(f32*)(p + 0x378) = 0.0f;
    *(f32*)(p + 0x374) = 0.0f;
    *(f32*)(p + 0x370) = 0.0f;
    *(f32*)(p + 0x44) = 0.0f;
    *(f32*)(p + 0x40) = 0.0f;
    *(f32*)(p + 0x3c) = 0.0f;
    *(f32*)(p + 0x34c) = *(f32*)(p + 0xc);
    *(f32*)(p + 0x350) = *(f32*)(p + 0x10);
    *(f32*)(p + 0x354) = *(f32*)(p + 0x14);
    *(f32*)(p + 0x358) = *(f32*)(p + 0xc);
    *(f32*)(p + 0x35c) = *(f32*)(p + 0x10);
    *(f32*)(p + 0x360) = *(f32*)(p + 0x14);
    *(f32*)(p + 0x364) = *(f32*)(p + 0xc);
    *(f32*)(p + 0x368) = *(f32*)(p + 0x10);
    *(f32*)(p + 0x36c) = *(f32*)(p + 0x14);
    *(f32*)(p + 0x348) = 50.0f;
    *(s32*)(p + 0x30c) = 100;
    switch (this_->field_90) {
    case 0:
    case 4:
    case 8:
        *(s32*)(p + 0x98) = 3;
        break;
    case 1:
    case 5:
    case 9:
        *(s32*)(p + 0x98) = 2;
        break;
    case 2:
    case 6:
    case 10:
        *(s32*)(p + 0x98) = 1;
        break;
    case 3:
    case 7:
    case 11:
        *(s32*)(p + 0x98) = 0;
        break;
    }
    if (this_->field_90 >= 4 && this_->field_90 <= 7) {
        *(s32*)(p + 0x30c) = -100;
    }
    *(u16*)(p + 0x340) = fn_801F6874(*(u32*)(p + 0x98));
    if (this_->field_90 == 12) {
        *(s32*)(p + 0x2f8) = 2;
        *(s32*)(p + 0x2fc) = *(s32*)(p + 0x2f8);
    } else if (this_->field_90 == 13) {
        *(s32*)(p + 0x2f8) = 4;
        *(s32*)(p + 0x2fc) = *(s32*)(p + 0x2f8);
    } else {
        if (this_->field_90 >= 4 && this_->field_90 <= 11) {
            *(f32*)(p + 0xc) = *(f32*)(p + 0x348) * ((const SinCosTable*)sincosTable___5JMath)->sinShort(*(u16*)(p + 0x340)) + *(f32*)(p + 0x34c);
            *(f32*)(p + 0x10) = *(f32*)(p + 0x348) * ((const SinCosTable*)sincosTable___5JMath)->cosShort(*(u16*)(p + 0x340)) + *(f32*)(p + 0x350);
            *(s32*)(p + 0x2f8) = 1;
        } else {
            *(s32*)(p + 0x300) = 300;
            *(f32*)(p + 0x370) = 0.5f * ((const SinCosTable*)sincosTable___5JMath)->sinShort(*(u16*)(p + 0x340));
            *(f32*)(p + 0x374) = 0.5f * ((const SinCosTable*)sincosTable___5JMath)->cosShort(*(u16*)(p + 0x340));
            *(s32*)(p + 0x2f8) = 0;
        }
        *(s32*)(p + 0x2fc) = *(s32*)(p + 0x2f8);
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
