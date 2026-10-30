// TU 0x802f184c-0x802f3b74 (actor TFL2).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"

// ---- Tfl2_dtor_802F184C.cpp ----
extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804AA628[];

extern "C" void* fn_802F184C(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804AA628;
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JGeometry/Box.h"
struct Tfl2Rect { f32 x0,y0,x1,y1; };
struct Tfl2RoomCfg { u8 pad[0xcc]; Tfl2Rect rectA,rectB; };
struct Tfl2Root { u8 pad[0x20]; void* x20; };
extern "C" Tfl2RoomCfg* fn_802D6A9C();
extern "C" void fn_802F9974(void*,u32,u32,s32);
extern Tfl2Root* lbl_8053AB10;
extern u8* lbl_8053AAF8;
extern const s32 lbl_8046F788[];
extern const s32 lbl_8046F7A4[];
extern "C" void fn_80239914(void*,s32,void*);
extern "C" s32 fn_8023AF14(void*,s32,s32,f32);
extern "C" u8 fn_8022F514(s32);
extern "C" u8 fn_8022F478(s32);
extern "C" void fn_8023A89C(void*,s32,void*);
extern "C" u8 fn_8023A97C(s32,void*,s32,void*);
extern "C" s32 fn_801F2718(void*,u32);
extern "C" u8 fn_80234F68(s32);
extern "C" u16 fn_802F9908(void*,u32,u32);
extern "C" void fn_8013CC50(u32,void*,s32,s32,s32,s32,s32,s32,f32);
extern "C" void fn_801F0E34(void*,u32,u32);
extern "C" void fn_802D79E8(void*,s32,s32,f32,f32);
extern "C" const char* fn_802D9C4C(void*);
struct Tfl2Virtual {
virtual void v0();
virtual void v1();
virtual void v2();
virtual void v3();
virtual void v4();
virtual void v5();
virtual void v6();
virtual void v7();
virtual void v8();
virtual void v9();
virtual void trigger(s32,s32);
virtual u8 ready();
};
extern const f32 lbl_80541440;
extern const f32 lbl_80541444;
extern const f32 lbl_80541454;
extern const f32 lbl_80541464;
extern const f32 lbl_80541468;
extern const f32 lbl_8054146C;
extern const f32 lbl_80541470;
extern const f32 lbl_80541474;
extern const f32 lbl_80541478;
extern const f32 lbl_8054147C;
extern const f32 lbl_80541480;
extern const f32 lbl_80541484;
extern const f32 lbl_80541488;
extern const f32 lbl_8054148C;
extern const f32 lbl_80541490;
extern const f32 lbl_80541494;
extern const f32 lbl_80541498;
extern const f32 lbl_8054149C;
extern const f32 lbl_805414A8;
extern const f32 lbl_805414B8;
extern const f32 lbl_805414BC;
extern const f64 lbl_805414A0,lbl_805414B0;
static inline void tfl2Effect(u8* p,s32 id,s32 mode) {
 JGeometry::TVec3<f32> v(lbl_80541454+*(f32*)(p+0xc),
                         lbl_80541454+*(f32*)(p+0x10),lbl_80541440);
 fn_8013CC50(*(u32*)(p+4),&v,id,mode,0,0,0,1,lbl_80541444);
}
#pragma opt_common_subs off
#pragma opt_propagation on
extern "C" void fn_802F25C0(u8* p) {
s32 ball;
f32 y,x,ry;
JGeometry::TVec2<f32> pos2;
JGeometry::TBox2f region;
JGeometry::TBox2f box;
JGeometry::TVec3<f32> saved=*(JGeometry::TVec3<f32>*)(p+0xc);
const s32* base=lbl_8046F788;
switch(*(s32*)(p+0x234)){
default:case 6:
*(f32*)(p+0xc)+=lbl_80541454;*(f32*)(p+0x10)+=lbl_80541454;break;
case 2:*(f32*)(p+0xc)+=lbl_80541464;*(f32*)(p+0x10)+=lbl_8054146C;break;
case 3:*(f32*)(p+0xc)+=lbl_80541454;*(f32*)(p+0x10)+=lbl_8054146C;break;
case 4:case 5:
*(f32*)(p+0x80)=lbl_80541470;*(f32*)(p+0x84)=lbl_80541470;*(f32*)(p+0x88)=lbl_80541464;*(f32*)(p+0x8c)=lbl_80541464;
box=*(JGeometry::TBox2f*)(p+0x80);
*(f32*)(p+0xc)+=lbl_80541464;*(f32*)(p+0x10)+=lbl_80541464;
pos2.set(*(f32*)(p+0xc),*(f32*)(p+0x10));
box.addPos(pos2);
fn_80239914(&box,*(s32*)(p+4),*(void**)(p+0x198));
*(JGeometry::TVec3<f32>*)(p+0xc)=saved;
*(f32*)(p+0x10)+=lbl_80541464;
*(f32*)(p+0x60)=lbl_80541474;*(f32*)(p+0x64)=lbl_80541478;*(f32*)(p+0x68)=lbl_8054147C;*(f32*)(p+0x6c)=lbl_80541480;
break;
}
pos2.set(*(f32*)(p+0xc),*(f32*)(p+0x10));
box.set(*(JGeometry::TBox2f*)(p+0x60));
box.addPos(pos2);
s32 player=fn_8023AF14(&box,*(s32*)(p+4),0,lbl_80541484);
if(player>=0 && fn_8022F514(player)==1 && player==fn_8022F478(player))player=-1;
if(*(s32*)(p+0x23c)==1 && player>=0 && !fn_80234F68(player))player=-1;
ball=fn_801F2718(p,0x5342414c);
fn_8023A89C(&box,*(s32*)(p+4),&pos2);
s32 count=0;
for(s32 i=0;i<4;i++)if(fn_8023A97C(i,&box,*(s32*)(p+4),&pos2))count++;
*(JGeometry::TVec3<f32>*)(p+0xc)=saved;
switch(*(s32*)(p+0x230)){
case 0:{
f32 x=*(f32*)(p+0xc);f32 y=*(f32*)(p+0x10);s32 room=*(s32*)(p+4);
Tfl2RoomCfg* cfg=fn_802D6A9C();Tfl2Rect* source=room<8?&cfg->rectA:&cfg->rectB;
region=*(JGeometry::TBox2f*)source;
s32 tx=(s32)(x-region.i.x);s32 ty=(s32)(y-region.i.y);
if(tx<0)tx=0;else if(tx>=512)tx=511;if(ty<0)ty=0;else if(ty>=512)ty=511;
*(u16*)(p+0x250)=fn_802F9908(lbl_8053AB10->x20,*(u32*)(p+4),((ty<<1)&0x200)|(tx&0x100)|(ty&0xf0)|((tx>>4)&15));
*(s32*)(p+0x230)=2;break;
}
case 2:
switch(*(s32*)(p+0x234)){
case 0:case 1:case 2:case 3:case 6:
if(((Tfl2Virtual*)p)->ready() && (player>=0||ball>=0)){
tfl2Effect(p,897,0);
tfl2Effect(p,898,0);
tfl2Effect(p,899,0);
tfl2Effect(p,900,0);
{
x=*(f32*)(p+0xc);
s32 room=*(s32*)(p+4);
Tfl2RoomCfg* cfg=fn_802D6A9C();
Tfl2Rect* source=room<8?&cfg->rectA:&cfg->rectB;
region=*(JGeometry::TBox2f*)source;
ry=region.i.y;
const s32* heights=base+7;
const s32* widths=base;
for(s32 i=0;i<widths[*(s32*)(p+0x234)];i++){
s32 tx=(s32)(x-region.i.x);y=*(f32*)(p+0x10);
for(s32 j=0;j<heights[*(s32*)(p+0x234)];j++){
s32 cx;
s32 ty=(s32)(y-ry);
cx=tx;if(tx<0)cx=0;else if(tx>=0x200)cx=0x1ff;
if(ty<0)ty=0;else if(ty>=0x200)ty=0x1ff;
u32 tile=((ty<<1)&0x200)|(cx&0x100)|(ty&0xf0)|((cx>>4)&0xf);
fn_802F9974(lbl_8053AB10->x20,*(u32*)(p+4),tile,6);
y+=lbl_80541488;
}x+=lbl_80541488;
}
}
*(s32*)(p+0x230)=3;fn_801F0E34(p,0x3001b,0);
}break;
case 4:case 5:
if(count==4){
((Tfl2Virtual*)p)->trigger(255,1);fn_801F0E34(p,0x30009,0);
{
x=*(f32*)(p+0xc);
s32 room=*(s32*)(p+4);
Tfl2RoomCfg* cfg=fn_802D6A9C();
Tfl2Rect* source=room<8?&cfg->rectA:&cfg->rectB;
region=*(JGeometry::TBox2f*)source;
ry=region.i.y;
const s32* heights=base+7;
const s32* widths=base;
for(s32 i=0;i<widths[*(s32*)(p+0x234)];i++){
s32 tx=(s32)(x-region.i.x);y=*(f32*)(p+0x10);
for(s32 j=0;j<heights[*(s32*)(p+0x234)];j++){
s32 cx;
s32 ty=(s32)(y-ry);
cx=tx;if(tx<0)cx=0;else if(tx>=0x200)cx=0x1ff;
if(ty<0)ty=0;else if(ty>=0x200)ty=0x1ff;
u32 tile=((ty<<1)&0x200)|(cx&0x100)|(ty&0xf0)|((cx>>4)&0xf);
fn_802F9974(lbl_8053AB10->x20,*(u32*)(p+4),tile,0x7c);
y+=lbl_80541488;
}x+=lbl_80541488;
}
}
*(f32*)(p+0x24c)=lbl_8054148C;*(s32*)(p+0x230)=6;fn_801F0E34(p,0x3001b,0);
}break;
}break;
case 3:
*(f32*)(p+0x248)+=lbl_80541490;
if(*(f32*)(p+0x248)>=lbl_80541494){
*(f32*)(p+0x248)=lbl_80541498;
{
x=*(f32*)(p+0xc);
s32 room=*(s32*)(p+4);
Tfl2RoomCfg* cfg=fn_802D6A9C();
Tfl2Rect* source=room<8?&cfg->rectA:&cfg->rectB;
region=*(JGeometry::TBox2f*)source;
ry=region.i.y;
const s32* heights=base+7;
const s32* widths=base;
for(s32 i=0;i<widths[*(s32*)(p+0x234)];i++){
s32 tx=(s32)(x-region.i.x);y=*(f32*)(p+0x10);
for(s32 j=0;j<heights[*(s32*)(p+0x234)];j++){
s32 cx;
s32 ty=(s32)(y-ry);
cx=tx;if(tx<0)cx=0;else if(tx>=0x200)cx=0x1ff;
if(ty<0)ty=0;else if(ty>=0x200)ty=0x1ff;
u32 tile=((ty<<1)&0x200)|(cx&0x100)|(ty&0xf0)|((cx>>4)&0xf);
fn_802F9974(lbl_8053AB10->x20,*(u32*)(p+4),tile,*(u16*)(p+0x252));
y+=lbl_80541488;
}x+=lbl_80541488;
}
}
*(s32*)(p+0x244)=40;
if(*(s32*)(p+0x23c)==2)*(s32*)(p+0x230)=8;else *(s32*)(p+0x230)=4;
}break;
case 4:
if(*(s32*)(p+0x244)==0 && player<0 && ball<0){
fn_801F0E34(p,0x3001c,0);*(s32*)(p+0x230)=5;
}else if(*(s32*)(p+0x244)!=0){
--*(s32*)(p+0x244);
if(*(s32*)(p+0x244)==0 && *(s32*)(p+0x23c)!=0 && ((Tfl2Virtual*)p)->ready()==1)*(s32*)(p+0x244)=1;
}break;
case 5:
*(f32*)(p+0x248)-=lbl_8054149C;
if(*(f32*)(p+0x248)<lbl_80541440){
*(f32*)(p+0x248)=lbl_80541440;
{
x=*(f32*)(p+0xc);
s32 room=*(s32*)(p+4);
Tfl2RoomCfg* cfg=fn_802D6A9C();
Tfl2Rect* source=room<8?&cfg->rectA:&cfg->rectB;
region=*(JGeometry::TBox2f*)source;
ry=region.i.y;
const s32* heights=base+7;
const s32* widths=base;
s32 kind;
const u16* row=(const u16*)((const u8*)base+0x38);
for(s32 i=0;i<widths[*(s32*)(p+0x234)];i++,row+=4){
s32 tx=(s32)(x-region.i.x);y=*(f32*)(p+0x10);
const u16* cell=row;
for(s32 j=0;j<heights[kind=*(s32*)(p+0x234)];j++,cell++){
s32 cx;
s32 ty=(s32)(y-ry);
cx=tx;if(tx<0)cx=0;else if(tx>=0x200)cx=0x1ff;
if(ty<0)ty=0;else if(ty>=0x200)ty=0x1ff;
u32 tile=((ty<<1)&0x200)|(cx&0x100)|(ty&0xf0)|((cx>>4)&0xf);
if(kind!=1)fn_802F9974(lbl_8053AB10->x20,*(u32*)(p+4),tile,*(u16*)(p+0x250));else fn_802F9974(lbl_8053AB10->x20,*(u32*)(p+4),tile,*cell);
y+=lbl_80541488;
}x+=lbl_80541488;
}
}
*(s32*)(p+0x230)=2;
tfl2Effect(p,897,1);
tfl2Effect(p,898,1);
tfl2Effect(p,899,1);
tfl2Effect(p,900,1);
}break;
case 6:
*(f32*)(p+0x248)-=*(f32*)(p+0x24c);
*(f32*)(p+0x24c)-=lbl_805414A0;
if(*(f32*)(p+0x248)<=lbl_805414A8){*(f32*)(p+0x248)=lbl_805414A8;*(s32*)(p+0x244)=4;*(s32*)(p+0x230)=7;}
{u8* mgr=*(u8**)((u8*)lbl_8053AB10+0x24);if(!mgr[0x7f4])mgr[0x7f5]=1;}break;
case 7:
if(*(s32*)(p+0x244)==0){
*(f32*)(p+0x248)-=*(f32*)(p+0x24c);*(f32*)(p+0x24c)+=lbl_805414B0;
if(*(f32*)(p+0x248)<=lbl_805414B8){
*(f32*)(p+0x248)=lbl_805414B8;*(s32*)(p+0x230)=8;
fn_802D79E8(fn_802D6A9C(),*(s32*)(p+4),1,lbl_805414BC,lbl_80541440);
JGeometry::TVec3<f32> v;
v.x=lbl_80541464+(lbl_80541468+*(f32*)(p+0xc));v.y=lbl_80541464+*(f32*)(p+0x10);v.z=lbl_80541440;
fn_8013CC50(*(u32*)(p+4),&v,0x263,0,0,0,0,1,lbl_80541444);
if(*(s32*)(p+0x234)==4){
const char* name=fn_802D9C4C(fn_802D6A9C());
fn_8013CC50(*(u32*)(p+4),&v,130,1,0,0,0,1,lbl_80541444);
fn_8013CC50(*(u32*)(p+4),&v,131,1,0,0,0,1,lbl_80541444);
fn_8013CC50(*(u32*)(p+4),&v,132,1,0,0,0,1,lbl_80541444);
if(*name=='r'||*name=='s'||*name=='y')fn_8013CC50(*(u32*)(p+4),&v,0x80,1,0,0,0,1,lbl_80541444);
else fn_8013CC50(*(u32*)(p+4),&v,0x81,1,0,0,0,1,lbl_80541444);
fn_801F0E34(p,0x30001,0);
}else {
x=lbl_80541468+*(f32*)(p+0xc);
s32 room=*(s32*)(p+4);
Tfl2RoomCfg* cfg=fn_802D6A9C();
Tfl2Rect* source=room<8?&cfg->rectA:&cfg->rectB;
region=*(JGeometry::TBox2f*)source;
ry=region.i.y;
const s32* heights=base+7;
const s32* widths=base;
for(s32 i=0;i<widths[*(s32*)(p+0x234)];i++){
s32 tx=(s32)(x-region.i.x);y=*(f32*)(p+0x10);
for(s32 j=0;j<heights[*(s32*)(p+0x234)];j++){
s32 cx;
s32 ty=(s32)(y-ry);
cx=tx;if(tx<0)cx=0;else if(tx>=0x200)cx=0x1ff;
if(ty<0)ty=0;else if(ty>=0x200)ty=0x1ff;
u32 tile=((ty<<1)&0x200)|(cx&0x100)|(ty&0xf0)|((cx>>4)&0xf);
fn_802F9974(lbl_8053AB10->x20,*(u32*)(p+4),tile,(u16)*(s32*)(p+0x240));
y+=lbl_80541488;
}x+=lbl_80541488;
}
}
p[0x11c]=0;
}
}else --*(s32*)(p+0x244);
{u8* mgr=*(u8**)((u8*)lbl_8053AB10+0x24);if(!mgr[0x7f4])mgr[0x7f5]=1;}
break;
default:case 1:p[0x11c]=0;break;
case 8:break;
}
}
#pragma opt_common_subs reset
#pragma opt_propagation reset
// TFL2 init (vtable slot 1)
static inline s32 tfl2Clamp(s32 v) {
    s32 r = v;
    if (v < 0) {
        r = 0;
    } else if (v >= 0x200) {
        r = 0x1ff;
    }
    return r;
}

extern "C" void fn_802F368C(u8* this_) {
    *(u32*)(this_ + 0x234) = *(u32*)(this_ + 0x90) & 0xf;
    *(u32*)(this_ + 0x238) = (*(u32*)(this_ + 0x90) >> 4) & 0xf;
    *(u32*)(this_ + 0x240) = (*(u32*)(this_ + 0x90) >> 12) & 0xfff;
    *(f32*)(this_ + 0x248) = 0.0f;
    switch (*(s32*)(this_ + 0x234)) {
    default:
    case 6:
        *(f32*)(this_ + 0x60) = -32.0f;
        *(f32*)(this_ + 0x64) = -32.0f;
        *(f32*)(this_ + 0x68) = 32.0f;
        *(f32*)(this_ + 0x6c) = 32.0f;
        break;
    case 2:
        *(f32*)(this_ + 0x60) = -40.0f;
        *(f32*)(this_ + 0x64) = -32.0f;
        *(f32*)(this_ + 0x68) = 40.0f;
        *(f32*)(this_ + 0x6c) = 32.0f;
        break;
    case 3:
        *(f32*)(this_ + 0x60) = -24.0f;
        *(f32*)(this_ + 0x64) = -32.0f;
        *(f32*)(this_ + 0x68) = 24.0f;
        *(f32*)(this_ + 0x6c) = 32.0f;
        break;
    case 4:
    case 5:
        *(f32*)(this_ + 0x60) = -16.0f;
        *(f32*)(this_ + 0x64) = -50.0f;
        *(f32*)(this_ + 0x68) = 24.0f;
        *(f32*)(this_ + 0x6c) = 50.0f;
        *(f32*)(this_ + 0x248) = -0.06f;
        break;
    }
    *(s32*)(this_ + 0x244) = 20;
    if (lbl_8053AAF8[0x7f] == 1) {
        *(s16*)(this_ + 0x252) = 12;
    } else {
        *(s16*)(this_ + 0x252) = 13;
    }
    if (*(s32*)(this_ + 0x234) >= 2) {
        f32 x = *(f32*)(this_ + 0xc);
        s32 room = *(s32*)(this_ + 0x4);
        Tfl2RoomCfg* cfg = fn_802D6A9C();
        Tfl2Rect r = room < 8 ? cfg->rectA : cfg->rectB;
        f32 y;
        f32 ry0 = r.y0;
        for (s32 i = 0; i < lbl_8046F788[*(s32*)(this_ + 0x234)]; i++) {
            s32 tx = (s32)(x - r.x0);
            y = *(f32*)(this_ + 0x10);
            for (s32 j = 0; j < lbl_8046F7A4[*(s32*)(this_ + 0x234)]; j++) {
                s32 ty = (s32)(y - ry0);
                s32 cx = tfl2Clamp(tx);
                if (ty < 0) {
                    ty = 0;
                } else if (ty >= 0x200) {
                    ty = 0x1ff;
                }
                s32 cy = ty;
                fn_802F9974(lbl_8053AB10->x20, *(u32*)(this_ + 0x4),
                            ((cy << 1) & 0x200) | (cx & 0x100) | (cy & 0xf0) | ((cx >> 4) & 0xf), 6);
                y += 16.0f;
            }
            x += 16.0f;
        }
    }
    *(s32*)(this_ + 0x230) = 0;
}

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
