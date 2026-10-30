// LPLK_800F6820: .text 0x800F6820-0x800F7FCC (actor LPLK)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"
#include "Game/ItemBase.h"
#include "JSystem/JGeometry/Vec.h"

// ---- from Game/fn_800F7C4C_dtor.cpp

extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern "C" s32 fn_8022DCD8(s32 player);
extern "C" void fn_8022DD74(s32 player);
extern void* lbl_8049C578[];

extern "C" void* fn_800F7C4C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049C578;
        char* p = (char*)this_;
        s32 player = *(s32*)(p + 0x238);
        if ((u8)fn_8022DCD8(player) != 0) {
            player = *(s32*)(p + 0x238);
            fn_8022DD74(player);
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

struct LplkVirt {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06(); virtual void v07();
    virtual void v08(); virtual void v09(); virtual void v10(); virtual u8 v11();
    virtual void v12(); virtual s32 v13();
};
extern const f32 lbl_8053BF98;
extern const f32 lbl_8053BF68;
extern const f32 lbl_8053BF48;
extern const f32 lbl_8053BF9C;

extern "C" void fn_800F7CC8(char* this_) {
    *(f32*)(this_ + 0x60) = lbl_8053BF98;
    *(f32*)(this_ + 0x64) = lbl_8053BF98;
    *(f32*)(this_ + 0x68) = lbl_8053BF68;
    *(f32*)(this_ + 0x6c) = lbl_8053BF68;
    *(f32*)(this_ + 0x80) = lbl_8053BF98;
    *(f32*)(this_ + 0x84) = lbl_8053BF98;
    *(f32*)(this_ + 0x88) = lbl_8053BF68;
    *(f32*)(this_ + 0x8c) = lbl_8053BF68;
    *(u8*)(this_ + 0x235) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x230) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(u8*)(this_ + 0x234) = *(u32*)(this_ + 0x90) & 0xf;
    *(u8*)(this_ + 0x23c) = 1;
    *(s32*)(this_ + 0x238) = 0;
    *(f32*)(this_ + 0x264) = lbl_8053BF48;
    *(f32*)(this_ + 0x260) = lbl_8053BF48;
    if (*(u32*)(this_ + 0x90) & 0x100) {
        *(s32*)(this_ + 0x230) = 1;
    }
    if (((LplkVirt*)this_)->v13() != 0) {
        *(s32*)(this_ + 0x230) = 4;
    }
    if (*(u32*)(this_ + 0x90) & 0x400) {
        *(u8*)(this_ + 0x23c) = 0;
        *(f32*)(this_ + 0x14) = lbl_8053BF9C;
    }
    *(s32*)(this_ + 0x24c) = 0;
}

extern const f32 lbl_8053BF30;
struct LplkRandom {
    u32 seed;
    f32 get() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - lbl_8053BF30;
    }
};
struct LplkGame { u8 pad[0xb4]; LplkRandom rnd; };
extern LplkGame* lbl_8053AAF8;
extern const f32 lbl_8053BF34;
extern const f32 lbl_8053BF38;
extern const u16 lbl_80539E70[4];
extern "C" void fn_801CD150(void* src, void* dst);
extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F8544(void* base, u32 fourCC, s32 room, void* pos, s32 kind);
extern "C" char* fn_801F666C(void* base, s32 id);
extern "C" void* fn_8013CC50(u32 id, void* pos, u32 kind, u32 a, s32 b, u32 c, u32 d, u32 e, f32 scale);
extern "C" void v07__5ActorFv(void* this_);

#pragma opt_propagation off
extern "C" void fn_800F6820(char* this_) {
    s32 kind;
    int room;
    JGeometry::TVec3<f32> pos;
    BOOL big;
    kind = *(s32*)(this_ + 0x4);
    if ((u8)fn_8022DCD8(*(s32*)(this_ + 0x238)) != 0) {
        fn_8022DD74(*(s32*)(this_ + 0x238));
    }
    if (*(u32*)(this_ + 0x90) & 0x1000) {
        big = TRUE;
        fn_801CD150(this_ + 0xc, &pos);
        kind = 8;
    } else {
        big = FALSE;
        pos.x = *(f32*)(this_ + 0xc);
        pos.y = *(f32*)(this_ + 0x10);
        pos.z = *(f32*)(this_ + 0x14);
    }
    room = kind;
    while (*(s32*)(this_ + 0x244) > 0) {
        if (big == 0) {
            if (*(s32*)(this_ + 0x244) >= 200) {
                kind = 3;
                *(s32*)(this_ + 0x244) -= 50;
            } else if (*(s32*)(this_ + 0x244) >= 80) {
                kind = 2;
                *(s32*)(this_ + 0x244) -= 20;
            } else if (*(s32*)(this_ + 0x244) >= 20) {
                kind = 1;
                *(s32*)(this_ + 0x244) -= 5;
            } else {
                kind = 0;
                *(s32*)(this_ + 0x244) -= 1;
            }
        } else {
            if (*(s32*)(this_ + 0x244) >= 200) {
                kind = 4;
                *(s32*)(this_ + 0x244) -= 100;
            } else if (*(s32*)(this_ + 0x244) >= 50) {
                kind = 3;
                *(s32*)(this_ + 0x244) -= 50;
            } else {
                kind = 2;
                *(s32*)(this_ + 0x244) -= 20;
            }
        }
        s32 id = fn_801F8544(fn_801F856C(), 'RUPY', room, &pos, kind);
        if (id >= 0) {
            char* a = fn_801F666C(fn_801F856C(), id);
            if (a != 0) {
                JGeometry::TVec3<f32> v;
                f32 r = lbl_8053AAF8->rnd.get();
                v.z = lbl_8053BF38 * r + lbl_8053BF38;
                v.y = lbl_8053BF34 - lbl_8053AAF8->rnd.get();
                v.x = lbl_8053BF34 - lbl_8053AAF8->rnd.get();
                *(JGeometry::TVec3<f32>*)(a + 0x3c) = v;
            }
        }
    }
    fn_8013CC50(*(s32*)(this_ + 0x4), this_ + 0xc, lbl_80539E70[*(u8*)(this_ + 0x234)], 0, 0, 0, 0, 1, lbl_8053BF30);
    *(s32*)(this_ + 0x18c) = 0;
    v07__5ActorFv(this_);
}
#pragma opt_propagation reset
extern "C" void fn_801F02BC(char* this_, void* anim, s32 idx, u8* tbl, s32 frame, s32 a, s32 b, f32 x, f32 y);
extern const f32 lbl_8053BF3C;
extern const f32 lbl_8053BF40;
extern const f32 lbl_8053BF44;
extern const s32 lbl_8053BF50[];
extern const s32 lbl_8053BF48_tbl[];
extern u8 lbl_8049C518[];
extern u8 lbl_80463710[];
extern u8 lbl_80463724[];
#pragma opt_propagation off
extern "C" void fn_800F6AB4(char* this_) {
    s32* base = (s32*)lbl_8049C518;
    DrawRec rec;
    f32 arr[12];
    switch (*(s32*)(this_ + 0x230)) {
    case 0:
        fn_801F02BC(this_, lbl_80463710, *(u8*)(this_ + 0x235) + base[*(u8*)(this_ + 0x234)], rec.ids, 0, 0, 0, lbl_8053BF30, lbl_8053BF30);
        return;
    case 2:
        *(f32*)(this_ + 0xc) += *(f32*)(this_ + 0x260);
        *(f32*)(this_ + 0x10) += *(f32*)(this_ + 0x264);
        fn_801F02BC(this_, lbl_80463724, *(u8*)(this_ + 0x235) + (base + 8)[*(u8*)(this_ + 0x234)], rec.ids, 7, 0, 0, lbl_8053BF30, lbl_8053BF30);
        *(f32*)(this_ + 0xc) -= *(f32*)(this_ + 0x260);
        *(f32*)(this_ + 0x10) -= *(f32*)(this_ + 0x264);
        break;
    case 4:
        break;
    default:
        {
            f32 f = lbl_8053BF30 + lbl_8053BF3C * ((f32)*(s32*)(this_ + 0x244) / lbl_8053BF40);
            if (f > lbl_8053BF44) {
                f = lbl_8053BF44;
            }
            rec.w18 = arr;
            arr[0] = f;
            arr[1] = lbl_8053BF48;
            arr[2] = lbl_8053BF48;
            arr[3] = lbl_8053BF48;
            arr[4] = lbl_8053BF48;
            arr[5] = lbl_8053BF30;
            arr[6] = lbl_8053BF48;
            arr[7] = lbl_8053BF48;
            arr[8] = lbl_8053BF48;
            arr[9] = lbl_8053BF48;
            arr[10] = f;
            arr[11] = lbl_8053BF48;
            fn_801F02BC(this_, lbl_80463724, *(u8*)(this_ + 0x235) + (base + 4)[*(u8*)(this_ + 0x234)], rec.ids, 7, 0, 0, lbl_8053BF30, lbl_8053BF30);
        }
        break;
    }
}
#pragma opt_propagation reset
extern "C" void detach__5ActorFv(void*);
extern "C" void fn_801EEC98(void*,s32,u16*,s32*,f32*,s32*,s32,s32);
extern "C" void fn_801F0E34(void*,s32,s32);
extern "C" s32 fn_801F3D94(void*,s32);
extern "C" u8 fn_801F305C(void*);
extern "C" Vec* fn_8023E724(s32);
extern "C" u8 fn_8022DE10(s32,s32);
extern "C" s32 fn_801F778C(void*,u32,void*,f32*);
extern "C" u8 fn_8022F514(s32);
extern "C" s32 fn_8022F3DC(s32);
extern "C" s32 fn_80236228(s32);
extern "C" void fn_802362C4(s32,s32);
extern "C" void* Actor_CreateByID(void*,u32,s32,void*,s32,s32,s32);
extern "C" void fn_8023DFF4(s32,void*);
extern "C" void fn_80238548(s32,s32,void*,s32);
extern "C" u32 fn_8022C5EC(s32,s32);
extern "C" void fn_801F2B7C(void*,s32,s32,s32);
extern "C" void fn_801F2618(void*,s32,s32);
extern const u8 lbl_80539E78[];
extern const s32 lbl_8049C558[];
extern const s32 lbl_8049C548[];
extern const f32 lbl_8053BF58;
extern const f32 lbl_8053BF5C;
extern const f32 lbl_8053BF60;
extern const f32 lbl_8053BF64;
extern const f32 lbl_8053BF6C;
extern const f32 lbl_8053BF70;
extern const f32 lbl_8053BF74;
extern const f32 lbl_8053BF78;
extern const f32 lbl_8053BF7C;
extern const f32 lbl_8053BF80;
extern const f32 lbl_8053BF84;
extern const f32 lbl_8053BF88;
extern const f32 lbl_8053BF8C;
extern const f32 lbl_8053BF90;
extern const f32 lbl_8053BF94;
extern const u8 lbl_80539E78[8];
extern "C" void fn_800F6D80(u8* self){
JGeometry::TVec3<f32> pos;
JGeometry::TVec2<f32> pos2;
f32 dist;
s32 quad,target;
f32 rupeeDist;
u16 angle;
s32 id,priority,player,amount;
bool grounded;
f32 absX,oldV;
angle=0;dist=lbl_8053BF48;quad=0;target=-1;
fn_801EEC98(self,(*(s32*)(self+0x198)),&angle,&quad,&dist,&target,0,0);
++(*(s32*)(self+0x24c));
switch((*(s32*)(self+0x230))){
case 4:if(((u8(*)(void*))(*(void***)self)[13])(self)){(*(s32*)(self+0x230))=0;}break;
case 0:
grounded=false;(*(f32*)(self+0x44))-=lbl_8053BF3C;
if((*(f32*)(self+0x14))<lbl_8053BF48){
if(self[0x23c]==0){
fn_801F0E34(self,0x3000a,0);(*(f32*)(self+0x14))=lbl_8053BF48;
(*(f32*)(self+0x44))=(lbl_8053BF30-lbl_8053BF58*lbl_8053AAF8->rnd.get())+lbl_8053BF58;
(*(f32*)(self+0x3c))=lbl_8053BF34-lbl_8053AAF8->rnd.get();
(*(f32*)(self+0x40))=lbl_8053BF34-lbl_8053AAF8->rnd.get();
self[0x23c]=1;
}else{(*(f32*)(self+0x44))=lbl_8053BF48;(*(f32*)(self+0x40))=lbl_8053BF48;(*(f32*)(self+0x3c))=lbl_8053BF48;grounded=true;}}
*(JGeometry::TVec3<f32>*)(self+0xc)+=*(JGeometry::TVec3<f32>*)(self+0x3c);
--(*(s32*)(self+0x240));
if((*(s32*)(self+0x240))<=0){++self[0x235];self[0x235]&=3;if(self[0x235]==0){(*(s32*)(self+0x240))=(s32)(lbl_8053BF5C*lbl_8053AAF8->rnd.get())+60;}else (*(s32*)(self+0x240))=2;}
if(target!=-1 && dist<lbl_8053BF60 && grounded==true){
(*(s32*)(self+0x230))=1;(*(s32*)(self+0x240))=0;
fn_8013CC50((*(s32*)(self+0x4)),self+0xc,0x3dc,0,0,0,0,1,lbl_8053BF30);
fn_8013CC50((*(s32*)(self+0x4)),self+0xc,lbl_80539E70[self[0x234]],0,0,0,0,1,lbl_8053BF30);
fn_801F0E34(self,0x50023,0);}break;
case 1:
*(u32*)(self+0xb0)=0x11101;
if(fn_801F3D94(self,1)!=0)break;if(fn_801F305C(self))break;
++(*(s32*)(self+0x240));if((*(s32*)(self+0x230))==2){self[0x235]=lbl_80539E78[(*(s32*)(self+0x240))/2];if(self[0x235]==255){self[0x235]=0;(*(s32*)(self+0x240))=0;}}else if((*(s32*)(self+0x230))==3){if((*(s32*)(self+0x240))==6){++self[0x235];if(self[0x235]==7)--self[0x235];(*(s32*)(self+0x240))=0;}}else{if((*(s32*)(self+0x240))==6){++self[0x235];if(self[0x235]==7)self[0x235]=0;(*(s32*)(self+0x240))=0;}}
if(target!=-1 && dist<lbl_8053BF64 && !(u8)fn_8022DCD8(target)){
*(u16*)(self+0x23e)=angle;
absX=__fabsf((*(f32*)(self+0xc))-fn_8023E724(target)->x);
f32 absY=__fabsf((*(f32*)(self+0x10))-fn_8023E724(target)->y);
if(absX<lbl_8053BF68 && absY<lbl_8053BF68 && (u8)fn_8022DE10(target,1)==1){
(*(s32*)(self+0x230))=2;(*(s32*)(self+0x238))=target;(*(s32*)(self+0x250))=0;(*(s32*)(self+0x248))=0;(*(s32*)(self+0x240))=0;self[0x235]=0;}
}else{
id=fn_801F778C(fn_801F856C(),'RUPY',self+0xc,&rupeeDist);
if(id!=-1){
pos=*(JGeometry::TVec3<f32>*)(fn_801F666C(fn_801F856C(),id)+0xc);
*(s16*)(self+0x23e)=JMAAtan2Radian(pos.x-(*(f32*)(self+0xc)),pos.y-(*(f32*)(self+0x10)))*lbl_8053BF6C;
if(rupeeDist<lbl_8053BF70){
u8* item=(u8*)fn_801F666C(fn_801F856C(),id);
s32 kind=-1;
if(*(u16*)(item+0x94)==0 || *(u16*)(item+0x94)==3)kind=*(u32*)(item+0x90)&255;
if(kind!=-1){
(*(s32*)(self+0x244))+=lbl_8049C558[kind];
item=(u8*)fn_801F666C(fn_801F856C(),id);
s32 st=*(s32*)(item+0x230);
if(st==0 || (u32)(st-15)<=1 || (u32)(st-1)<=1 || st==9 || st==13)detach__5ActorFv(item);
}}}else if(((*(s32*)(self+0x24c))&15)==0){*(s16*)(self+0x23e)+=(s32)(lbl_8053BF74*lbl_8053AAF8->rnd.get())-0x4000;}}
(*(f32*)(self+0xc))+=lbl_8053BF3C*JMASSin(*(s16*)(self+0x23e));
(*(f32*)(self+0x10))+=lbl_8053BF3C*JMASCos(*(s16*)(self+0x23e));break;
case 2:
player=(*(s32*)(self+0x238));if(fn_8022F514((*(s32*)(self+0x238))))player=fn_8022F3DC((*(s32*)(self+0x238)));
priority=(*(s32*)(self+0x108));
if(fn_801F305C(self)){
(*(s32*)(self+0x248))+=priority-(*(s32*)(self+0x108));(*(s32*)(self+0x108))=priority;
if(fn_80236228(player)>20){fn_802362C4(player,-20);Actor_CreateByID(fn_801F856C(),'GOLD',(*(s32*)(self+0x4)),self+0xc,20,-1,-1);}
if((*(s32*)(self+0x248))>20)fn_8022DD74((*(s32*)(self+0x238)));}
fn_801F3D94(self,1);
++(*(s32*)(self+0x240));if((*(s32*)(self+0x230))==2){self[0x235]=lbl_80539E78[(*(s32*)(self+0x240))/2];if(self[0x235]==255){self[0x235]=0;(*(s32*)(self+0x240))=0;}}else if((*(s32*)(self+0x230))==3){if((*(s32*)(self+0x240))==6){++self[0x235];if(self[0x235]==7)--self[0x235];(*(s32*)(self+0x240))=0;}}else{if((*(s32*)(self+0x240))==6){++self[0x235];if(self[0x235]==7)self[0x235]=0;(*(s32*)(self+0x240))=0;}}
(*(f32*)(self+0x254))=(*(f32*)(self+0xc))-fn_8023E724((*(s32*)(self+0x238)))->x;(*(f32*)(self+0x258))=(*(f32*)(self+0x10))-fn_8023E724((*(s32*)(self+0x238)))->y;(*(f32*)(self+0x25c))=(*(f32*)(self+0x14))-fn_8023E724((*(s32*)(self+0x238)))->z;
fn_8023DFF4((*(s32*)(self+0x238)),self+0x254);
amount=lbl_8049C548[self[0x234]];
if(((*(s32*)(self+0x24c))&31)==0 && fn_80236228(player)-amount>0){fn_802362C4(player,-amount);(*(s32*)(self+0x244))+=amount;}
if(!(u8)fn_8022DCD8((*(s32*)(self+0x238)))){
(*(s32*)(self+0x230))=3;(*(s32*)(self+0x240))=0;pos2.x=(*(f32*)(self+0xc));pos2.y=(*(f32*)(self+0x10));fn_80238548((*(s32*)(self+0x238)),0,&pos2,1);}
if(target!=-1){(*(f32*)(self+0x254))=(*(f32*)(self+0xc))-fn_8023E724(target)->x;(*(f32*)(self+0x258))=(*(f32*)(self+0x10))-fn_8023E724(target)->y;(*(f32*)(self+0x25c))=(*(f32*)(self+0x14))-fn_8023E724(target)->z;((JGeometry::TVec3<f32>*)(self+0x254))->normalize();}
(*(f32*)(self+0xc))+=lbl_8053BF7C*(*(f32*)(self+0x254));
(*(f32*)(self+0x10))+=lbl_8053BF7C*(*(f32*)(self+0x258));
(*(f32*)(self+0x44))-=lbl_8053BF80;(*(f32*)(self+0x14))+=(*(f32*)(self+0x44));
if((*(f32*)(self+0x14))<=lbl_8053BF48){(*(f32*)(self+0x14))=lbl_8053BF48;(*(f32*)(self+0x44))=lbl_8053BF58;fn_801F0E34(self,0x50024,0);if(fn_80236228(player)>5){fn_802362C4(player,-5);Actor_CreateByID(fn_801F856C(),'GOLD',(*(s32*)(self+0x4)),self+0xc,5,-1,-1);}}
(*(f32*)(self+0x264))=lbl_8053BF48;(*(f32*)(self+0x260))=lbl_8053BF48;
if(fn_8022C5EC((*(s32*)(self+0x238)),8))(*(f32*)(self+0x264))=lbl_8053BF84;
else if(fn_8022C5EC((*(s32*)(self+0x238)),4))(*(f32*)(self+0x264))=lbl_8053BF88;
else if(fn_8022C5EC((*(s32*)(self+0x238)),1))(*(f32*)(self+0x260))=lbl_8053BF84;
else if(fn_8022C5EC((*(s32*)(self+0x238)),2))(*(f32*)(self+0x260))=lbl_8053BF88;
break;
case 3:
oldV=(*(f32*)(self+0x44));
if(fn_801F3D94(self,1)!=0 || fn_801F305C(self)){(*(f32*)(self+0x44))=oldV;}
else{
fn_801F2B7C(self,-100,-1,1);
++(*(s32*)(self+0x240));if((*(s32*)(self+0x230))==2){self[0x235]=lbl_80539E78[(*(s32*)(self+0x240))/2];if(self[0x235]==255){self[0x235]=0;(*(s32*)(self+0x240))=0;}}else if((*(s32*)(self+0x230))==3){if((*(s32*)(self+0x240))==6){++self[0x235];if(self[0x235]==7)--self[0x235];(*(s32*)(self+0x240))=0;}}else{if((*(s32*)(self+0x240))==6){++self[0x235];if(self[0x235]==7)self[0x235]=0;(*(s32*)(self+0x240))=0;}}
if(self[0x235]!=0){
if(lbl_8053BF48==(*(f32*)(self+0x14)) && self[0x235]!=0){
(*(f32*)(self+0x44))=lbl_8053BF8C;fn_801F0E34(self,0x50025,0);
if((s32)(lbl_8053BF38*lbl_8053AAF8->rnd.get())<1){
(*(f32*)(self+0x254))=lbl_8053BF58-lbl_8053AAF8->rnd.get();(*(f32*)(self+0x258))=lbl_8053BF58-lbl_8053AAF8->rnd.get();
}else{(*(f32*)(self+0x254))=(*(f32*)(self+0xc))-fn_8023E724((*(s32*)(self+0x238)))->x;(*(f32*)(self+0x258))=(*(f32*)(self+0x10))-fn_8023E724((*(s32*)(self+0x238)))->y;}
(*(f32*)(self+0x25c))=lbl_8053BF90;((JGeometry::TVec3<f32>*)(self+0x254))->normalize();}
(*(f32*)(self+0xc))+=lbl_8053BF94*(*(f32*)(self+0x254));(*(f32*)(self+0x10))+=lbl_8053BF94*(*(f32*)(self+0x258));
}}
(*(f32*)(self+0x44))-=lbl_8053BF80;(*(f32*)(self+0x14))+=(*(f32*)(self+0x44));
if((*(f32*)(self+0x14))<=lbl_8053BF48){(*(f32*)(self+0x14))=lbl_8053BF48;(*(f32*)(self+0x44))=lbl_8053BF48;self[0x235]=0;}break;
}
fn_801F2618(self,0,0);
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
