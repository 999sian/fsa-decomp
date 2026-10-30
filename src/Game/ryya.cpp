// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 801A6690-801A8194 (RYYA). Remaining functions are not yet decompiled.
#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JGeometry/Box.h"
#include "JSystem/JMath/JMath.h"
#include "std/math.h"
extern "C" void* lbl_8053AB10;
extern "C" void fn_801EEC98(void*,s32,u16*,s32*,f32*,s32*,s32,s32);
extern "C" void fn_80239914(void*,s32,s32);
extern "C" s32 fn_80138A30(void*);
extern "C" int fn_8023DE58(int);
extern "C" void fn_8022FEB8(void*,s32,s32,s32,s32);
extern "C" s32 fn_8022FD8C(s32);
extern "C" u8 fn_802300EC(s32);
extern "C" u8 fn_8038AD24(s32,s32,s32,s32,const JGeometry::TVec3f&,s32);
extern "C" void fn_801EE8F4(void*,void*,f32*,s32);
extern "C" u8 fn_803865B8(s32);
extern "C" s32 fn_8037EFB4(s32);
extern "C" void fn_8038470C(s32,s32);
extern "C" u8 fn_80388CAC(s32,s32);
extern "C" void fn_80230534(s32);
extern "C" void fn_801F0D20(void*,s32);
extern "C" void fn_80458FF0(void*,u32,s32,s32);
extern "C" void fn_8022B1E0(void);
extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F7818(void*,u32,s32,void*,s32);
extern "C" s32 fn_801F68E0(void*);
extern "C" void fn_80230C6C(s32);
extern "C" s32 fn_801F2718(void*,u32);
extern "C" char* fn_801F666C(void*,s32);
extern "C" void fn_801F0E34(void*,u32,s32);
extern "C" void* fn_8013CC50(s32,void*,s32,s32,s32,s32,s32,s32,f32);
extern "C" void fn_801F71A4(void*,f32,f32,f32);
extern "C" void fn_8030C210(void*,void*);
extern "C" s32 fn_8022EA0C(s32);
extern "C" void fn_8022FE80(s32,s32,s32,s32,s32);
extern "C" s32 Actor_CreateByID(void*,u32,u32,f32*,u32,s32,s32);
extern "C" u8 fn_80384C58(s32,s32);
extern "C" void fn_801F6884(void*);
extern "C" s32 fn_801F8544(void*,u32,s32,void*,s32);
extern const f32 lbl_8053E640;
extern const f32 lbl_8053E644;
extern const f32 lbl_8053E648;
extern const f32 lbl_8053E64C;
extern const f32 lbl_8053E650;
extern const f32 lbl_8053E658;
extern const f32 lbl_8053E65C;
extern const f32 lbl_8053E680;
extern const f32 lbl_8053E684;

static inline void ryyaFocus(const JGeometry::TVec3f& pos) {
    char* camera=(char*)((void**)lbl_8053AB10)[9];
    if (*(u8*)(camera+0x7f5)==0) {
        *(u8*)(camera+0x7f4)=1;
        *(s32*)(camera+0x7f8)=4;
        *(f32*)(camera+0x7fc)=pos.x;
        *(f32*)(camera+0x800)=pos.y;
        *(f32*)(camera+0x804)=pos.z;
        *(u8*)(camera+0x7f6)=0;
    }
}
static inline f32 ryyaDistance(char* p,char* obj) {
    f32 dy=*(f32*)(obj+0x10)-*(f32*)(p+0x10);
    f32 dx=*(f32*)(obj+0xc)-*(f32*)(p+0xc);
    return std::sqrtf(dx*dx+dy*dy);
}
static inline void ryyaPlayerDirection(char* p,const JGeometry::TVec3f& delta) {
    u16 angle=(s32)(JMath::atanTable_.atan2_(-delta.x,-delta.y)*lbl_8053E64C);
    if(angle<0x2000 || angle>=0xe000) *(s32*)(p+0x98)=3;
    else if(angle>=0x2000 && angle<0x6000) *(s32*)(p+0x98)=1;
    else if(angle>=0x6000 && angle<=0xa000) *(s32*)(p+0x98)=2;
    else *(s32*)(p+0x98)=0;
}

#include "types.h"

// from src/Game/Saya_ForceStateRange_801A68A4.cpp
extern char* lbl_8053AAF8;
extern void* lbl_8053AF80;
extern const f32 lbl_8053E628, lbl_8053E62C, lbl_8053E654, lbl_8053E660, lbl_8053E664;
extern "C" void fn_80138B7C(void*);
extern "C" void fn_80458508(void*,s32);
extern "C" void fn_8022B1C8(void);
extern "C" void fn_801A7C48(void*);
static inline void ryyaSetCycle(char* p, s32 st) {
    if (*(s32*)(p + 0x250) != st) {
        *(s32*)(p + 0x250) = st;
        *(s32*)(p + 0x234) = 0;
        *(s32*)(p + 0x240) = 0;
    }
}
extern "C" void fn_801A68DC(void* this_);

// SAYA cluster, part 14/18 (56B). Vtable-slot wrapper directly invoking
// fn_801A68DC (the actor's other big body, landed alongside) when the
// state field is 0 or 1.
extern "C" void fn_801A68A4(void* this_) {
    s32 state = *(s32*)((char*)this_ + 0x260);
    switch (state) {
    case 0:
    case 1:
        fn_801A68DC(this_);
        break;
    }
}

extern "C" void fn_801A68DC(void* this_) {
char* p=(char*)this_;
JGeometry::TVec3f messagePos(*(JGeometry::TVec3f*)(p+0xc));
JGeometry::TVec3f fishPos;
JGeometry::TVec3f cameraPos;
JGeometry::TBox2f box;
JGeometry::TVec3f argPos0,zero1,zero2,argPos5,argPos10,delta0,delta10;
f32 dist;s32 player=-1;
if(*(s32*)(p+0x260)==1) fn_801EEC98(p,*(s32*)(p+0x198),0,&player,&dist,0,0,0);
fishPos.x=*(f32*)(p+0xc);fishPos.y=*(f32*)(p+0x10);fishPos.z=*(f32*)(p+0x14);
messagePos.y-=lbl_8053E640;
cameraPos=*(JGeometry::TVec3f*)(p+0xc);
box.i.x=*(f32*)(p+0x60);box.i.y=*(f32*)(p+0x64);box.f.x=*(f32*)(p+0x68);box.f.y=*(f32*)(p+0x6c);
box.addPos(*(f32*)(p+0xc),*(f32*)(p+0x10));
if(*(s32*)(p+0x250)!=1) fn_80239914(&box,*(s32*)(p+0x4),*(s32*)(p+0x198));
box=*(JGeometry::TBox2f*)(p+0x70);box.addPos(*(JGeometry::TVec2<f32>*)(p+0xc));
switch(*(s32*)(p+0x230)) {
case 0:

if(*(s32*)(p+0x260)==1) {
if(player<0 || dist>lbl_8053E644) {
if(*(s32*)(p+0x250)!=3 && *(s32*)(p+0x250)!=1) {*(s32*)(p+0x250)=3;*(s32*)(p+0x234)=0;*(s32*)(p+0x240)=0;}
break;
}
if(dist>lbl_8053E648) break;
if(*(s32*)(p+0x250)!=2&&*(s32*)(p+0x250)!=0&&*(s32*)(p+0x250)!=4){*(s32*)(p+0x250)=2;*(s32*)(p+0x234)=0;*(s32*)(p+0x240)=0;}
}

if(*(s32*)(p+0x250)!=0) break;
*(s32*)(p+0x264)=fn_80138A30(lbl_8053AAF8);
if(*(s32*)(p+0x264)>1){for(s32 i=1;i<*(s32*)(p+0x264);i++){s32 value=fn_8023DE58(i);if(value!=fn_8023DE58(0))return;}}

if(*(s32*)(p+0x260)==1) {
if(player<0 || dist>lbl_8053E644) {
if(*(s32*)(p+0x250)!=3 && *(s32*)(p+0x250)!=1) {*(s32*)(p+0x250)=3;*(s32*)(p+0x234)=0;*(s32*)(p+0x240)=0;}
break;
}
if(dist>lbl_8053E648) break;
if(*(s32*)(p+0x250)!=2&&*(s32*)(p+0x250)!=0&&*(s32*)(p+0x250)!=4){*(s32*)(p+0x250)=2;*(s32*)(p+0x234)=0;*(s32*)(p+0x240)=0;}
}

if(*(s32*)(p+0x250)!=0) break;
fn_8022FEB8(&box,*(s32*)(p+0x4),*(s32*)(p+0x198),1,0);
*(s32*)(p+0x268)=fn_8022FD8C(*(s32*)(p+0x198));
if(*(s32*)(p+0x268)>=0 && fn_802300EC(*(s32*)(p+0x268))){
s32 message=0x422;if(*(s32*)(p+0x260)==0)message=0x41a;
s32 roomHandle=*(s32*)(p+0x198);s32 room=*(s32*)(p+4);
if(fn_8038AD24(*(s32*)(p+0x268),message,roomHandle,room,(argPos0=messagePos,argPos0),0x100)){
f32 distance;fn_801EE8F4(p,&delta0,&distance,*(s32*)(p+0x268)+1);
if(distance<lbl_8053E62C) ryyaPlayerDirection(p,delta0);
*(s32*)(p+0x230)=2;}}
break;
case 2:
ryyaFocus(cameraPos);fn_8022FEB8(&box,*(s32*)(p+0x4),*(s32*)(p+0x198),1,0);
if(fn_803865B8(*(s32*)(p+0x268))){switch(fn_8037EFB4(*(s32*)(p+0x268))){
case 0: fn_8038470C(*(s32*)(p+0x268),0x41b);*(s32*)(p+0x230)=3;break;
case 1: fn_8038470C(*(s32*)(p+0x268),0x41c);*(s32*)(p+0x230)=12;break;
}}break;
case 3:
ryyaFocus(cameraPos);fn_8022FEB8(&box,*(s32*)(p+0x4),*(s32*)(p+0x198),1,0);
if(fn_80388CAC(*(s32*)(p+0x268),*(s32*)(p+0x198))){
fn_80230534(0);*(s32*)(p+0x258)=3600;fn_801F0D20(p,0x3a);fn_80458FF0(lbl_8053AF80,0x1000007,1,0);fn_8022B1E0();
*(s32*)(p+0x244)=0;*(s32*)(p+0x248)=0;*(s32*)(p+0x24c)=0;*(s32*)(p+0x238)=0;*(s32*)(p+0x23c)=0;
ryyaSetCycle(p,4);*(s32*)(p+0x230)=4;}break;
case 4: {
char* fishes[1024];
*(s32*)(p+0x258)-=1;*(s32*)(p+0x270)=-1;
if((*(s32*)(p+0x258)&15)==0) *(s32*)(p+0x270)=fn_801F7818(fn_801F856C(),0x46495348,*(s32*)(p+0x4),fishes,-1);
if(*(s32*)(p+0x258)<0 || *(s32*)(p+0x270)==0) {
if(fn_801F68E0(fn_801F856C())==0)break;
for(s32 i=0;i<4;i++)fn_80230C6C(i);
fn_801F0D20(p,0x3b);fn_80458508(lbl_8053AF80,0);ryyaSetCycle(p,0);*(s32*)(p+0x244)=0;*(s32*)(p+0x248)=0;*(s32*)(p+0x230)=5;break;
}
if(*(s32*)(p+0x26c)<0&&*(s32*)(p+0x250)==4) {
*(f32*)(p+0x60)=lbl_8053E650;*(f32*)(p+0x64)=lbl_8053E654;*(f32*)(p+0x68)=lbl_8053E658;*(f32*)(p+0x6c)=lbl_8053E65C;
*(s32*)(p+0x26c)=fn_801F2718(p,0x46495348);
*(f32*)(p+0x60)=lbl_8053E660;*(f32*)(p+0x64)=lbl_8053E660;*(f32*)(p+0x68)=lbl_8053E664;*(f32*)(p+0x6c)=lbl_8053E664;
s32 index=*(s32*)(p+0x26c);
if(index>=0){char* obj=fn_801F666C(fn_801F856C(),index);if(obj){
f32 distance=ryyaDistance(p,obj);
if(distance>lbl_8053E658) *(s32*)(p+0x26c)=-1;
else *(JGeometry::TVec3f*)(obj+0x3c)=(zero1.setAll(lbl_8053E654),zero1);
}}}
s32 index=*(s32*)(p+0x26c);
if(index>=0){char* obj=fn_801F666C(fn_801F856C(),index);if(obj) {
f32 distance=ryyaDistance(p,obj);
if(distance<lbl_8053E680){
ryyaSetCycle(p,5);fn_801F0E34(p,0x4005c,0);fn_8013CC50(*(s32*)(p+0x4),p+0xc,0x54e,0,0,0,0,1,lbl_8053E628);
*(s32*)(p+0x25c)+=1;*(u8*)(obj+0x11c)=0;*(s32*)(p+0x26c)=-1;
}else{
*(JGeometry::TVec3f*)(obj+0x3c)=(zero2.setAll(lbl_8053E654),zero2);
fishPos.x=*(f32*)(obj+0xc);fishPos.y=*(f32*)(obj+0x10);fishPos.z=*(f32*)(obj+0x14);
fn_801F71A4(&fishPos.x,*(f32*)(p+0xc),lbl_8053E684,lbl_8053E628);fn_801F71A4(&fishPos.y,*(f32*)(p+0x10),lbl_8053E684,lbl_8053E628);
*(JGeometry::TVec3f*)(obj+0xc)=fishPos;
}
}else *(s32*)(p+0x26c)=-1;
}
if(*(s32*)(p+0x258)/60<=11 && *(s32*)(p+0x258)%60==0 && *(s32*)(p+0x258)>60){
fn_801F0D20(p,0x3f);fn_80458508(lbl_8053AF80,1);
}
break;}
case 5: {
fn_8030C210(((void**)lbl_8053AB10)[9],p+0xc);
*(s32*)(p+0x244)+=1;if(*(s32*)(p+0x244)<=50)break;
*(s32*)(p+0x244)=51;s32 value=fn_8023DE58(0);s32 handle=fn_8022EA0C(0);fn_8022FE80(handle,value,*(s32*)(p+0x198),0,0);
s32 result=fn_8022FD8C(*(s32*)(p+0x198));if(result<0)break;
s32 roomHandle=*(s32*)(p+0x198);s32 room=*(s32*)(p+0x4);argPos5=messagePos;
fn_8038AD24(fn_8022EA0C(0),0x41d,roomHandle,room,argPos5,0x102);*(s32*)(p+0x230)=6;break;}
case 6:{
fn_8030C210(((void**)lbl_8053AB10)[9],p+0xc);s32 value=fn_8023DE58(0);s32 handle=fn_8022EA0C(0);fn_8022FE80(handle,value,*(s32*)(p+0x198),0,0);
if(fn_803865B8(fn_8022EA0C(0))){
fn_80138B7C(lbl_8053AAF8);
if(*(s32*)(p+0x25c)>=10)fn_8038470C(fn_8022EA0C(0),0x41e);else fn_8038470C(fn_8022EA0C(0),0x420);
*(s32*)(p+0x230)=7;}break;}
case 7:{
char* sayas[1024];JGeometry::TVec3f positions[8];
ryyaFocus(cameraPos);s32 value=fn_8023DE58(0);s32 handle=fn_8022EA0C(0);fn_8022FE80(handle,value,*(s32*)(p+0x198),0,0);
if(!fn_803865B8(fn_8022EA0C(0)))break;
*(s32*)(p+0x244)=50;
if(*(s32*)(p+0x25c)>=10){
s32 count=fn_801F7818(fn_801F856C(),0x53415941,*(s32*)(p+0x4),sayas,-1);
s32 found=0;for(s32 i=0;i<count && found<7;i++){char* obj=sayas[i];if(obj && *(u32*)(obj+0x90)==2){
positions[found].x=*(f32*)(obj+0xc);positions[found].y=*(f32*)(obj+0x10);positions[found].z=*(f32*)(obj+0x14);found++;
}}
if(found>0){
u32* seed=(u32*)(lbl_8053AAF8+0xb4);*seed=*seed*0x19660d+0x3c6ef35f;u32 bits=(*seed>>9)|0x3f800000;f32 random=*(f32*)&bits-lbl_8053E628;
s32 index=(s32)(found*random);fishPos.x=positions[index].x;fishPos.y=positions[index].y;fishPos.z=positions[index].z;
}
u32 kind=0x80000;if(*(s32*)(p+0x25c)>40)kind+=3;else if(*(s32*)(p+0x25c)>30)kind+=2;else if(*(s32*)(p+0x25c)>20)kind+=1;
s32 index=Actor_CreateByID(fn_801F856C(),0x484e5259,*(s32*)(p+0x4),(f32*)(p+0xc),kind,-1,-1);
if(index>=0){char* obj=fn_801F666C(fn_801F856C(),index);if(obj) *(JGeometry::TVec3f*)(obj+0x2a4)=fishPos;}
*(s32*)(p+0x244)=0;ryyaSetCycle(p,4);
}
*(s32*)(p+0x230)=8;break;}
case 8:
*(s32*)(p+0x244)+=1;if(*(s32*)(p+0x244)>50){
if(*(s32*)(p+0x25c)>=10)fn_8038470C(fn_8022EA0C(0),0x41f);else fn_8038470C(fn_8022EA0C(0),0x421);
ryyaSetCycle(p,0);*(s32*)(p+0x230)=9;}break;
case 9:{
ryyaFocus(cameraPos);s32 value=fn_8023DE58(0);s32 handle=fn_8022EA0C(0);fn_8022FE80(handle,value,*(s32*)(p+0x198),0,0);
if(!fn_803865B8(fn_8022EA0C(0)))break;
if(!fn_80384C58(fn_8022EA0C(0),*(s32*)(p+0x198)))break;
fn_801F6884(fn_801F856C());
((Actor*)p)->v10(255,1);fn_8022B1C8();
if(*(s32*)(p+0x250)!=3&&*(s32*)(p+0x250)!=1){*(s32*)(p+0x250)=3;*(s32*)(p+0x234)=0;*(s32*)(p+0x240)=0;}
if(*(s32*)(p+0x270)==0)fn_801F8544(fn_801F856C(),0x52555059,*(s32*)(p+0x4),p+0xc,0x230007);
*(s32*)(p+0x258)=-1;*(s32*)(p+0x230)=10;break;}
case 10:
if(*(s32*)(p+0x250)==3||*(s32*)(p+0x250)==1)break;
fn_8022FEB8(&box,*(s32*)(p+0x4),*(s32*)(p+0x198),0,0);
*(s32*)(p+0x268)=fn_8022FD8C(*(s32*)(p+0x198));
if(*(s32*)(p+0x268)>=0&&fn_802300EC(*(s32*)(p+0x268))){
s32 message=0x421;if(*(s32*)(p+0x25c)>=10)message=0x41f;s32 roomHandle=*(s32*)(p+0x198);s32 room=*(s32*)(p+4);
if(fn_8038AD24(*(s32*)(p+0x268),message,roomHandle,room,(argPos10=messagePos,argPos10),0x100)){
f32 distance;fn_801EE8F4(p,&delta10,&distance,*(s32*)(p+0x268)+1);if(distance<lbl_8053E62C)ryyaPlayerDirection(p,delta10);*(s32*)(p+0x230)=11;
}}break;
case 11:
ryyaFocus(cameraPos);fn_8022FEB8(&box,*(s32*)(p+0x4),*(s32*)(p+0x198),1,0);if(fn_80388CAC(*(s32*)(p+0x268),*(s32*)(p+0x198))) *(s32*)(p+0x230)=10;break;
case 12:
ryyaFocus(cameraPos);fn_8022FEB8(&box,*(s32*)(p+0x4),*(s32*)(p+0x198),1,0);if(fn_80388CAC(*(s32*)(p+0x268),*(s32*)(p+0x198))){fn_80230534(0);*(s32*)(p+0x230)=0;}break;
case 1:case 13:break;
}
if(*(s32*)(p+0x234)>0)*(s32*)(p+0x234)-=1;
if(*(s32*)(p+0x238)>0)*(s32*)(p+0x238)-=1;
if(*(s32*)(p+0x23c)>0)*(s32*)(p+0x23c)-=1;
fn_801A7C48(p);
}

// from src/Game/Saya_AdvanceCycleCounter_801A7C48.cpp
// SAYA cluster, part 17/18. Private cycle-counter helper called from
// fn_801A68DC - advances a wraparound counter (this->0x240) and, on
// specific values, records a state snapshot (this->0x250/0x254/0x234).
//
// A 6-way switch on this->0x250, where case 0 and case 5 share one
// block (the switch-shared-tail idiom, see project_fsa_phase4_kickoff.md).
// The shared block ends with a genuinely redundant re-check
// (`if (this->0x250 != 5) return; if (this->0x250 == 4) return;` -
// the second check can never be true given the first, since nothing
// modifies this->0x250 in between) that retail's own compiled output
// has too - kept honestly as-written rather than simplified away,
// since simplifying it would change the logic even though it happens
// to be unreachable in this specific call context; most likely a
// remnant of a shared helper checked against multiple possible
// "settled" states from other call sites. All `this->0x240` reads are
// written as separate fresh dereferences (never cached across
// statements) matching retail's own repeated-reload style, per this
// project's established this-relative-repeated-read rule. Landed
// clean on the first attempt.
extern "C" void fn_801A7C48(void* thisObj) {
	char* p = (char*)thisObj;
	if (*(s32*)(p + 0x234) != 0) return;
	s32 state = *(s32*)(p + 0x250);
	switch (state) {
	case 0:
	case 5:
		*(s32*)(p + 0x254) = *(s32*)(p + 0x240) + 2;
		*(s32*)(p + 0x234) = 8;
		*(s32*)(p + 0x240) = *(s32*)(p + 0x240) + 1;
		*(s32*)(p + 0x240) = *(s32*)(p + 0x240) & 7;
		if (*(s32*)(p + 0x240) < 4) return;
		if (*(s32*)(p + 0x250) != 5) return;
		if (*(s32*)(p + 0x250) == 4) return;
		*(s32*)(p + 0x250) = 4;
		*(s32*)(p + 0x234) = 0;
		*(s32*)(p + 0x240) = 0;
		return;
	case 1:
		*(s32*)(p + 0x254) = *(s32*)(p + 0x240) + 0xc;
		*(s32*)(p + 0x234) = 8;
		*(s32*)(p + 0x240) = *(s32*)(p + 0x240) + 1;
		*(s32*)(p + 0x240) = *(s32*)(p + 0x240) & 3;
		return;
	case 2:
		*(s32*)(p + 0x254) = 0xd - *(s32*)(p + 0x240);
		*(s32*)(p + 0x234) = 8;
		*(s32*)(p + 0x240) = *(s32*)(p + 0x240) + 1;
		*(s32*)(p + 0x240) = *(s32*)(p + 0x240) & 3;
		if (*(s32*)(p + 0x240) != 0) return;
		*(s32*)(p + 0x250) = 0;
		return;
	case 3:
		*(s32*)(p + 0x254) = *(s32*)(p + 0x240) + 0xa;
		*(s32*)(p + 0x234) = 8;
		*(s32*)(p + 0x240) = *(s32*)(p + 0x240) + 1;
		*(s32*)(p + 0x240) = *(s32*)(p + 0x240) & 3;
		if (*(s32*)(p + 0x240) != 0) return;
		*(s32*)(p + 0x250) = 1;
		return;
	case 4:
		*(s32*)(p + 0x254) = *(s32*)(p + 0x240);
		*(s32*)(p + 0x234) = 0xf;
		*(s32*)(p + 0x240) = *(s32*)(p + 0x240) + 1;
		*(s32*)(p + 0x240) = *(s32*)(p + 0x240) & 1;
		return;
	}
}

extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_8022B1C8(void);
extern "C" void fn_80138B7C(void* game);
extern "C" void fn_80458508(void* snd, s32 a);
extern void* lbl_804A2E30[];
extern char* lbl_8053AAF8;
extern void* lbl_8053AF80;

// RYYA destructor
extern "C" void* fn_801A7B98(char* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A2E30;
        s32 kind = *(s32*)(this_ + 0x260);
        if (kind == 0 || kind == 1) {
            s32 state = *(s32*)(this_ + 0x230);
            if (state == 4 || state == 5) {
                fn_8022B1C8();
                if (*(s32*)(lbl_8053AAF8 + 0x4c) != 9) {
                    fn_80138B7C(lbl_8053AAF8);
                    fn_80458508(lbl_8053AF80, 0);
                }
            }
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

struct RyyaDrawParam {
    RyyaDrawParam() : m40(-1), m44(-1) {
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
extern "C" void fn_801F06F0(void* this_, const char* table, s32 id, RyyaDrawParam* prm, f32 f1, f32 f2, s32 mode);
extern const char lbl_80468500[];
extern const f32 lbl_8053E628;
extern const f32 lbl_8053E62C;
extern const f32 lbl_8053E630;
struct RyyaTimer {
    u8 pad[0x10];
    u8 m10;
    u8 m11;
    u8 m12;
    u8 m13;
};
extern RyyaTimer* lbl_8053AF20;

inline void ryyaSetTime(s32 a, f32 b) {
    lbl_8053AF20->m11 = a;
    lbl_8053AF20->m12 = b;
    lbl_8053AF20->m13 |= 2;
}

inline void ryyaSetTime2(s32 t) {
    lbl_8053AF20->m11 = t / 60;
    lbl_8053AF20->m12 = lbl_8053E62C * (t % 60) / lbl_8053E630;
    lbl_8053AF20->m13 |= 2;
}

extern "C" void fn_801A6690(char* p) {
    switch (*(s32*)(p + 0x260)) {
    case 0:
    case 1: {
        RyyaDrawParam prm;
        prm.reset();
        if (*(s32*)(p + 0x250) != 1) {
            fn_801F06F0(p, lbl_80468500, *(s32*)(p + 0x254) + 0x303, &prm, lbl_8053E628, lbl_8053E628, -1);
        }
        if (*(s32*)(p + 0x258) >= 0) {
            lbl_8053AF20->m10 = *(s32*)(p + 0x25c);
            lbl_8053AF20->m13 |= 1;
            s32 t = *(s32*)(p + 0x258);
            s32 r = t - (t / 60) * 60;
            lbl_8053AF20->m11 = t / 60;
            lbl_8053AF20->m12 = (s32)(lbl_8053E62C * r / lbl_8053E630);
            lbl_8053AF20->m13 |= 2;
        }
        break;
    }
    }
}

extern "C" void detach__5ActorFv(void* this_);
extern const f32 lbl_8053E654;
extern const f32 lbl_8053E660;
extern const f32 lbl_8053E664;
extern const f32 lbl_8053E688;
extern const f32 lbl_8053E68C;

struct RyyaVT {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual u8 v11();
};



extern "C" void fn_801A7DD4(char* p) {
    *(f32*)(p + 0x60) = lbl_8053E660;
    *(f32*)(p + 0x64) = lbl_8053E660;
    *(f32*)(p + 0x68) = lbl_8053E664;
    *(f32*)(p + 0x6c) = lbl_8053E664;
    *(f32*)(p + 0x70) = lbl_8053E688;
    *(f32*)(p + 0x74) = lbl_8053E688;
    *(f32*)(p + 0x78) = lbl_8053E68C;
    *(f32*)(p + 0x7c) = lbl_8053E68C;
    *(f32*)(p + 0x80) = lbl_8053E660;
    *(f32*)(p + 0x84) = lbl_8053E660;
    *(f32*)(p + 0x88) = lbl_8053E664;
    *(f32*)(p + 0x8c) = lbl_8053E664;
    *(s32*)(p + 0x240) = 0;
    *(s32*)(p + 0x244) = 0;
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x234) = 0;
    *(s32*)(p + 0x238) = 0;
    *(s32*)(p + 0x23c) = 0;
    *(s32*)(p + 0x254) = 2;
    *(s32*)(p + 0x258) = -1;
    *(s32*)(p + 0x25c) = 0;
    *(s32*)(p + 0x26c) = -1;
    *(s32*)(p + 0x270) = -1;
    *(f32*)(p + 0x44) = lbl_8053E654;
    *(f32*)(p + 0x40) = lbl_8053E654;
    *(f32*)(p + 0x3c) = lbl_8053E654;
    *(s32*)(p + 0x264) = -1;
    *(s32*)(p + 0x268) = -1;
    *(s32*)(p + 0x250) = 0;
    ryyaSetCycle(p, 0);
    *(s32*)(p + 0x260) = *(u32*)(p + 0x90) & 0xf;
    if (((RyyaVT*)p)->v11()) {
        detach__5ActorFv(p);
        return;
    }
    switch (*(s32*)(p + 0x260)) {
    case 1:
        ryyaSetCycle(p, 1);
        *(s32*)(p + 0x254) = *(s32*)(p + 0x240) + 0xc;
    case 0:
        if (((RyyaVT*)p)->v11()) {
            *(s32*)(p + 0x230) = 10;
        } else {
            *(s32*)(p + 0x230) = 0;
        }
        break;
    case 2:
        *(s32*)(p + 0x230) = 0xd;
        break;
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
