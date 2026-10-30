#include "types.h"
#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "JSystem/JGeometry/Vec.h"
#include "Game/SinitPoolChain.h"
#include "JSystem/JGeometry/Box.h"


extern "C" char __vt__4NWOK[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" char lbl_804720E8[];
extern "C" f32 lbl_80542518;
extern "C" f32 lbl_80542528;
extern "C" f32 lbl_8054252C;
extern "C" f32 lbl_80542530;
extern "C" f32 lbl_80542534;
extern "C" s32 lbl_80472158[];
extern "C" void* lbl_8053AED0;
extern "C" void* lbl_8053AF80;
extern "C" void fn_8043D67C(void* snd, s32 a, s32 b, s32 c = 0);
extern "C" void fn_80458508(void* obj, s32 a);
extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F78F4(void* pool, u32 type, s32 afterId);
extern "C" void* fn_801F666C(void* reg, s32 id);
extern "C" void fn_801F06F0(void*, const char*, s32, f32, f32, s32, s32);
extern "C" void* fn_8023E724(s32 idx);
extern "C" void fn_801EE558(void* this_, void* p, f32* len, s32 p4);
extern "C" f32 lbl_8054254C;
extern "C" f32 lbl_80542558;
extern "C" f32 lbl_80542568;
extern "C" f32 lbl_8054255C;
extern "C" f32 lbl_8054256C;
extern "C" void* lbl_80542510;
extern "C" f32 lbl_80542538;
extern "C" f32 lbl_8054253C;
extern "C" f32 lbl_80542540;
extern "C" f32 lbl_80542544;
extern "C" f32 lbl_80542548;
extern "C" f32 lbl_80542550;
extern "C" f32 lbl_80542554;
extern "C" int fn_8023EA28(int idx);
extern "C" void fn_802314D8(s32 idx, JGeometry::TVec3f v);

extern "C" Actor* fn_8034AA40(Actor* p, s16 n) {
    if (p) {
        *(void**)p = __vt__4NWOK;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" s32 fn_8034AAA0(u8* self) {
    struct Box {
        f32 x0, y0, x1, y1;
    };
    volatile Box tmp;
    Box box;
    s32 count = 0;
    s32 idx = -1;
    s32 st;
    u8* p;

    tmp.x0 = lbl_80542528;
    tmp.y0 = lbl_8054252C;
    tmp.x1 = lbl_80542530;
    tmp.y1 = lbl_80542534;
    box = *(Box*)&tmp;

    box.x0 += *(f32*)(self + 0xc);
    box.y0 += *(f32*)(self + 0x10);
    box.x1 += *(f32*)(self + 0xc);
    box.y1 += *(f32*)(self + 0x10);
    *(s32*)(self + 0x274) = 0;
    *(s32*)(self + 0x278) = 0;
    *(s32*)(self + 0x27c) = 0;
    *(s32*)(self + 0x280) = 0;

    while (1) {
        idx = fn_801F78F4(fn_801F856C(), 0x4e495741, idx);
        if (idx < 0) {
            break;
        }
        p = (u8*)fn_801F666C(fn_801F856C(), idx);
        if (p != NULL && *(s32*)(p + 4) == *(s32*)(self + 4) && *(f32*)(p + 0x14) < lbl_8054252C) {
            u8 inside = 0;
            if (*(f32*)(p + 0xc) >= box.x0 && *(f32*)(p + 0x10) >= box.y0 && *(f32*)(p + 0xc) < box.x1 && *(f32*)(p + 0x10) < box.y1) {
                inside = 1;
            }
            if (inside == 1 && p[0xc4] == 0) {
                count++;
                p[0x2a8] = 1;
                *(s32*)(self + 0x274 + *(s32*)(p + 0x25c) * 4) += 1;
            }
        }
    }

    st = *(s32*)(self + 0x25c);
    if (lbl_80472158[st] >= *(s32*)(self + 0x24c) - count && self[0x28c + st] == 0) {
        fn_8043D67C(lbl_8053AED0, 0x42a, 0);
        self[0x28c + st] = 1;
        if (*(s32*)(self + 0x25c) == 2) {
            fn_80458508(lbl_8053AF80, 1);
        }
        if (*(s32*)(self + 0x25c) < 2) {
            *(s32*)(self + 0x25c) = st + 1;
        }
    }
    return count;
}

extern "C" void fn_8034ACF4(u8* self) {
    JGeometry::TBox2f box;
    JGeometry::TVec3f p, w, v;
    f32 tmp[4];
    s32 i;

    tmp[0] = lbl_80542538;
    tmp[1] = lbl_8054253C;
    tmp[2] = lbl_80542540;
    tmp[3] = lbl_80542544;
    box = *(JGeometry::TBox2f*)tmp;

    box.i.x += *(f32*)(self + 0xc);
    box.i.y += *(f32*)(self + 0x10);
    box.f.x += *(f32*)(self + 0xc);
    box.f.y += *(f32*)(self + 0x10);

    for (i = 0; i < 4; i++) {
        if ((u8)fn_8023EA28(i) == 1) {
            self[0x288 + i] = 1;
            *(JGeometry::TVec3f*)(self + 0x290 + i * 0xc) = *(JGeometry::TVec3f*)fn_8023E724(i);
        } else if (self[0x288 + i] == 1) {
            p = *(JGeometry::TVec3f*)fn_8023E724(i);
            JGeometry::TVec3f* vec = (JGeometry::TVec3f*)(self + 0x290 + i * 0xc);
            if (p.x > vec->x) {
                *(s32*)(self + 0x260 + i * 4) = 0;
            } else if (p.x < vec->x) {
                *(s32*)(self + 0x260 + i * 4) = 1;
            } else if (p.y > vec->y) {
                *(s32*)(self + 0x260 + i * 4) = 2;
            } else {
                *(s32*)(self + 0x260 + i * 4) = 3;
            }
            self[0x288 + i] = 0;
        }

        w = *(JGeometry::TVec3f*)fn_8023E724(i);
        if (w.z <= 0.0f) {
            u8 inside = 0;
            if (w.x >= box.i.x && w.y >= box.i.y && w.x < box.f.x && w.y < box.f.y) {
                inside = 1;
            }
            if (inside == 1) {
                fn_8043D67C(lbl_8053AED0, 0x410, 0, 0);
                switch (*(s32*)(self + 0x260 + i * 4)) {
                case 0:
                    v.x = lbl_80542548;
                    v.y = lbl_8054254C;
                    v.z = lbl_80542550;
                    break;
                case 1:
                    v.x = lbl_80542554;
                    v.y = lbl_8054254C;
                    v.z = lbl_80542550;
                    break;
                case 2:
                    v.x = lbl_8054254C;
                    v.y = lbl_80542548;
                    v.z = lbl_80542550;
                    break;
                case 3:
                    v.x = lbl_8054254C;
                    v.y = lbl_80542554;
                    v.z = lbl_80542550;
                    break;
                }
                fn_802314D8(i, v);
            }
        }
    }
}

#pragma opt_propagation off
extern "C" void fn_8034AFE8(u8* p) {
    char* tbl = lbl_804720E8;
    const char* str;
    s32 id;
    switch (*(s32*)(p + 0x244)) {
    case 0: {
        char* base;
        s32 off;
        off = *(s32*)(p + 0x23c);
        base = tbl + 0x10;
        off *= 16;
        s32 index = off + *(s32*)(p + 0x238) * 4;
        str = tbl + 0x7c;
        id = *(s32*)(base + index) + 0x218;
        break;
    }
    case 1: {
        char* base;
        s32 off;
        off = *(s32*)(p + 0x23c);
        base = tbl + 0x50;
        off *= 8;
        s32 index = off + *(s32*)(p + 0x238) * 4;
        str = tbl + 0x90;
        id = *(s32*)(base + index) + 0x2e6;
        break;
    }
    }
    fn_801F06F0(p, str, id, lbl_80542518, lbl_80542518, 0, 0);
}
#pragma opt_propagation reset
#include "JSystem/JMath/JMath.h"
extern "C" u8* lbl_8053AAF8;
extern "C" u8* lbl_8053AF08;
extern "C" void* lbl_8053AB10;
extern "C" void fn_80239914(void*,s32,s32);
extern "C" u8* fn_8020D58C(void);
extern "C" void fn_8020D8C0(void*,void*,s32,s32);
extern "C" void fn_8022FEB8(void*,s32,s32,s32,s32);
extern "C" s32 fn_8022FD8C(s32);
extern "C" u8 fn_802300EC(s32);
extern "C" u8 fn_8038AD24(s32,s32,s32,s32,const JGeometry::TVec3f&,s32);
extern "C" u8 fn_803865B8(s32);
extern "C" s32 fn_8037EFB4(s32);
extern "C" u8 fn_8038470C(s32,s32);
extern "C" void fn_8038938C(s32,s32);
extern "C" void fn_803894BC(s32,s32);
extern "C" void fn_80389254(s32,s32);
extern "C" u8 fn_80388CAC(s32,s32);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_801F6884(void*);
extern "C" s32 fn_801F68E0(void*);
extern "C" void fn_801F0D20(void*,s32);
extern "C" void fn_80458FF0(void*,u32,s32,s32);
extern "C" void fn_8022ADE4(void);
extern "C" void fn_8022ADCC(void);
extern "C" void fn_80138B7C(void*);
extern "C" s32 fn_80138A30(void*);
extern "C" void fn_802D7844(void*,s32,s32);
extern "C" u8 fn_802308E0(s32);
extern "C" u8 fn_80236B50(s32);
extern "C" u8 fn_8022F514(s32);
extern "C" s32 fn_8022F3DC(s32);
extern "C" s32 Actor_CreateByID(void*,u32,u32,void*,u32,s32,s32);
extern "C" void fn_8043D874(void*,s32,s32,s32);
extern "C" void fn_8030C210(void*,void*);
extern "C" f32 lbl_80542560;
extern "C" f32 lbl_80542564;
extern "C" void fn_8022FF8C(s32,void*,s32,s32,s32,s32);
#pragma inline_depth(8)
static inline u8 nwokEnabled(s32 i){u8 mask=1<<i;return (lbl_8053AAF8[0x82]&mask)!=0;}
static inline bool nwokHasChicken(u8* self){
JGeometry::TBox2f tmp;JGeometry::TBox2f box;
tmp.i.x=lbl_80542528;tmp.i.y=lbl_8054252C;tmp.f.x=lbl_80542530;tmp.f.y=lbl_80542534;
box=tmp;box.addPos(*(JGeometry::TVec2<f32>*)(self+0xc));
s32 index=-1;
for(;;){index=fn_801F78F4(fn_801F856C(),0x4e495741,index);if(index<0)break;
u8* obj=(u8*)fn_801F666C(fn_801F856C(),index);
if(obj&&*(s32*)(self+0x4)==*(s32*)(obj+0x4)&&*(f32*)(obj+0x14)<lbl_8054252C){u8 inside=0;if(*(f32*)(obj+0xc)>=box.i.x&&*(f32*)(obj+0x10)>=box.i.y&&*(f32*)(obj+0xc)<box.f.x&&*(f32*)(obj+0x10)<box.f.y)inside=1;if(inside==1&&obj[0xc4]==0)return true;}
}return false;
}
static inline void nwokTally(u8* self){
JGeometry::TBox2f tmp;JGeometry::TBox2f box;
tmp.i.x=lbl_80542528;tmp.i.y=lbl_8054252C;tmp.f.x=lbl_80542530;tmp.f.y=lbl_80542534;
box=tmp;box.addPos(*(JGeometry::TVec2<f32>*)(self+0xc));
*(s32*)(self+0x274)=0;*(s32*)(self+0x278)=0;*(s32*)(self+0x27c)=0;*(s32*)(self+0x280)=0;s32 index=-1;
for(;;){index=fn_801F78F4(fn_801F856C(),0x4e495741,index);if(index<0)break;
u8* obj=(u8*)fn_801F666C(fn_801F856C(),index);
if(obj&&*(s32*)(obj+0x25c)>=0&&*(s32*)(self+0x4)==*(s32*)(obj+0x4)&&*(f32*)(obj+0x14)<lbl_8054252C){
u8 inside=0;if(*(f32*)(obj+0xc)>=box.i.x&&*(f32*)(obj+0x10)>=box.i.y&&*(f32*)(obj+0xc)<box.f.x&&*(f32*)(obj+0x10)<box.f.y)inside=1;if(inside==1){if(obj[0x2a3]==1)self[0x284+*(s32*)(obj+0x25c)]=1;*(s32*)(self+0x274);(*(s32*)(self+0x274+*(s32*)(obj+0x25c)*4))+=1;}
}}
}
static inline s32 nwokWinner(u8* self){
s32 choices[4];s32* next=choices;s32 best=*(s32*)(self+0x274);s32 count=0;
if(fn_80138A30(lbl_8053AAF8)==1)return 0;
if(best<*(s32*)(self+0x278))best=*(s32*)(self+0x278);if(best<*(s32*)(self+0x27c))best=*(s32*)(self+0x27c);if(best<*(s32*)(self+0x280))best=*(s32*)(self+0x280);
if(best==*(s32*)(self+0x274)){*next++=0;count=1;}if(best==*(s32*)(self+0x278)){*next++=1;count++;}if(best==*(s32*)(self+0x27c)){*next++=2;count++;}if(best==*(s32*)(self+0x280)){*next=3;count++;}
if(count==1)return choices[0];
return choices[(s32)(count*((JMath::TRandom_fast_*)(lbl_8053AAF8+0xb4))->get_ufloat_1())];
}
static inline bool nwokHasChicken(u8* self,JGeometry::TBox2f& tmp,JGeometry::TBox2f& box){
tmp.i.x=lbl_80542528;tmp.i.y=lbl_8054252C;tmp.f.x=lbl_80542530;tmp.f.y=lbl_80542534;
box=tmp;box.addPos(*(JGeometry::TVec2<f32>*)(self+0xc));
s32 index=-1;
for(;;){index=fn_801F78F4(fn_801F856C(),0x4e495741,index);if(index<0)break;
u8* obj=(u8*)fn_801F666C(fn_801F856C(),index);
if(obj&&*(s32*)(self+0x4)==*(s32*)(obj+0x4)&&*(f32*)(obj+0x14)<lbl_8054252C){u8 inside=0;if(*(f32*)(obj+0xc)>=box.i.x&&*(f32*)(obj+0x10)>=box.i.y&&*(f32*)(obj+0xc)<box.f.x&&*(f32*)(obj+0x10)<box.f.y)inside=1;if(inside==1&&obj[0xc4]==0)return true;}
}return false;
}
static inline void nwokTally(u8* self,JGeometry::TBox2f& tmp,JGeometry::TBox2f& box){
tmp.i.x=lbl_80542528;tmp.i.y=lbl_8054252C;tmp.f.x=lbl_80542530;tmp.f.y=lbl_80542534;
box=tmp;box.addPos(*(JGeometry::TVec2<f32>*)(self+0xc));
*(s32*)(self+0x274)=0;*(s32*)(self+0x278)=0;*(s32*)(self+0x27c)=0;*(s32*)(self+0x280)=0;s32 index=-1;
for(;;){index=fn_801F78F4(fn_801F856C(),0x4e495741,index);if(index<0)break;
u8* obj=(u8*)fn_801F666C(fn_801F856C(),index);
if(obj){s32 owner=*(s32*)(obj+0x25c);if(owner>=0&&*(s32*)(self+0x4)==*(s32*)(obj+0x4)&&*(f32*)(obj+0x14)<lbl_8054252C){
u8 inside=0;if(*(f32*)(obj+0xc)>=box.i.x&&*(f32*)(obj+0x10)>=box.i.y&&*(f32*)(obj+0xc)<box.f.x&&*(f32*)(obj+0x10)<box.f.y)inside=1;if(inside==1){if(obj[0x2a3]==1)self[0x284+owner]=1;*(s32*)(self+0x274);(*(s32*)(self+0x274+*(s32*)(obj+0x25c)*4))+=1;}
}}}
}
#pragma opt_propagation off
static inline s32 nwokWinner(u8* self,s32* choices){
s32 best=*(s32*)(self+0x274);s32 count=0;
if(fn_80138A30(lbl_8053AAF8)==1)return 0;
s32* next=choices;
if(best<*(s32*)(self+0x278))best=*(s32*)(self+0x278);if(best<*(s32*)(self+0x27c))best=*(s32*)(self+0x27c);if(best<*(s32*)(self+0x280))best=*(s32*)(self+0x280);
s32 digit=0;if(best==*(s32*)(self+0x274)){*next=digit;next++;count=1;}
digit=1;if(best==*(s32*)(self+0x278)){*next=digit;next++;count+=1;}
digit=2;if(best==*(s32*)(self+0x27c)){*next=digit;next++;count+=1;}
digit=3;if(best==*(s32*)(self+0x280)){*next=digit;count+=1;}
if(count==1)return choices[0];
return choices[(s32)(count*((JMath::TRandom_fast_*)(lbl_8053AAF8+0xb4))->get_ufloat_1())];
}
#pragma opt_propagation reset

struct NwokScoreView {u8 field_000[0x274]; s32 scores[4];};

extern "C" void fn_8034B088(NwokScoreView* actor){
u8* self=(u8*)actor;
JGeometry::TBox2f box;JGeometry::TVec3f msg0,msg4,msg6,msg9,msg11,camera;
JGeometry::TBox2f queryTmp,queryBox,tallyTmp,tallyBox;
s32 choices[4];JGeometry::TVec3f delta;f32 distance;
s32 count=0;
if(*(s32*)(self+0x230)==6||*(s32*)(self+0x230)==7){
for(s32 i=0;i<4;i++){if(nwokEnabled(i)==1){u8 mask=1<<i;lbl_8053AF08[0x28+i]=*(s32*)(self+0x274+i*4);lbl_8053AF08[0x2c]|=mask;}}
count=fn_8034AAA0(self);
}
box.i.x=*(f32*)(self+0x60);box.i.y=*(f32*)(self+0x64);box.f.x=*(f32*)(self+0x68);box.f.y=*(f32*)(self+0x6c);box.addPos(*(JGeometry::TVec2<f32>*)(self+0xc));
fn_80239914(&box,*(s32*)(self+0x4),*(s32*)(self+0x198));
s32 roomHandle=*(s32*)(self+0x198);s32 room=*(s32*)(self+0x4);u8* collisions=fn_8020D58C();fn_8020D8C0(collisions+collisions[0]*0x784+4,&box,room,roomHandle);
fn_8034ACF4(self);
s32 state=*(s32*)(self+0x230);switch(state){
case 0:
if(nwokHasChicken(self,queryTmp,queryBox)==1){*(s32*)(self+0x230)=4;break;}
fn_8022FEB8(&box,*(s32*)(self+0x4),*(s32*)(self+0x198),1,0);*(s32*)(self+0x240)=fn_8022FD8C(*(s32*)(self+0x198));
if(*(s32*)(self+0x240)>=0&&fn_802300EC(*(s32*)(self+0x240))){
s32 roomHandle=*(s32*)(self+0x198);s32 room=*(s32*)(self+0x4); if(fn_8038AD24(*(s32*)(self+0x240),*(s32*)(self+0x2c0),roomHandle,room,(msg0=*(JGeometry::TVec3f*)(self+0xc),msg0),0))*(s32*)(self+0x230)=1;}break;
case 1:
fn_8022FEB8(&box,*(s32*)(self+0x4),*(s32*)(self+0x198),1,0);if(fn_803865B8(*(s32*)(self+0x240))){
switch(fn_8037EFB4(*(s32*)(self+0x240))){
case 0:switch(*(s32*)(self+0x244)){case 0:*(s32*)(self+0x2c0)=0x425;break;case 1:*(s32*)(self+0x2c0)=0x429;break;}fn_8038938C(*(s32*)(self+0x240),*(s32*)(self+0x24c));if(fn_8038470C(*(s32*)(self+0x240),*(s32*)(self+0x2c0)))*(s32*)(self+0x230)=3;break;
case 1:switch(*(s32*)(self+0x244)){case 0:*(s32*)(self+0x2c0)=0x424;break;case 1:*(s32*)(self+0x2c0)=0x428;break;}if(fn_8038470C(*(s32*)(self+0x240),*(s32*)(self+0x2c0)))*(s32*)(self+0x230)=2;break;
}}break;
case 2:case 3:case 5:case 12:{
if(state==5){s32 boxRoom=*(s32*)(self+0x4);u8* manager=(u8*)fn_802D6A9C();JGeometry::TBox2f* bounds;if(boxRoom<8)bounds=(JGeometry::TBox2f*)(manager+0xcc);else bounds=(JGeometry::TBox2f*)(manager+0xdc);box=*bounds;}
fn_8022FEB8(&box,*(s32*)(self+0x4),*(s32*)(self+0x198),1,0);if(!fn_80388CAC(*(s32*)(self+0x240),*(s32*)(self+0x198)))break;fn_801F6884(fn_801F856C());
switch(*(s32*)(self+0x230)){
case 3:case 5:fn_801F0D20(self,0x3a);fn_80458FF0(lbl_8053AF80,0x1000007,1,0);fn_8022ADE4();*(s32*)(self+0x230)=6;break;
case 2:switch(*(s32*)(self+0x244)){case 0:*(s32*)(self+0x2c0)=0x423;break;case 1:*(s32*)(self+0x2c0)=0x427;break;}*(s32*)(self+0x230)=0;break;
case 12:fn_8022FEB8(&box,*(s32*)(self+0x4),*(s32*)(self+0x198),1,0);if(fn_80388CAC(*(s32*)(self+0x240),*(s32*)(self+0x198))){fn_801F6884(fn_801F856C());*(s32*)(self+0x230)=11;}break;
}break;}
case 4:{
if(fn_801F68E0(fn_801F856C())!=1)break;s32 boxRoom=*(s32*)(self+0x4);u8* manager=(u8*)fn_802D6A9C();JGeometry::TBox2f* bounds;if(boxRoom<8)bounds=(JGeometry::TBox2f*)(manager+0xcc);else bounds=(JGeometry::TBox2f*)(manager+0xdc);box=*bounds;fn_8022FEB8(&box,*(s32*)(self+0x4),*(s32*)(self+0x198),0,0);
*(s32*)(self+0x240)=fn_8022FD8C(*(s32*)(self+0x198));if(*(s32*)(self+0x240)<0)break;fn_8038938C(*(s32*)(self+0x240),*(s32*)(self+0x24c));
s32 roomHandle=*(s32*)(self+0x198);s32 room=*(s32*)(self+0x4); if(fn_8038AD24(*(s32*)(self+0x240),0x42f,roomHandle,room,(msg4=*(JGeometry::TVec3f*)(self+0xc),msg4),0x112))*(s32*)(self+0x230)=5;break;}
case 6:
if(count>=*(s32*)(self+0x24c)){
fn_801F0D20(self,0x3b);fn_80458508(lbl_8053AF80,0);fn_80138B7C(lbl_8053AAF8);nwokTally(self,tallyTmp,tallyBox);
for(s32 i=0;i<4;i++)fn_802D7844(fn_802D6A9C(),self[0x284+i],i);
*(s32*)(self+0x254)=nwokWinner(self,choices);fn_8022ADCC();*(bool*)(self+0x28f)=fn_801F68E0(fn_801F856C())!=0;*(s32*)(self+0x230)=9;
}else{
*(s32*)(self+0x270)=count;*(s32*)(self+0x248)+=1;fn_8022FEB8(&box,*(s32*)(self+0x4),*(s32*)(self+0x198),1,0);*(s32*)(self+0x240)=fn_8022FD8C(*(s32*)(self+0x198));
if(*(s32*)(self+0x240)>=0&&fn_802300EC(*(s32*)(self+0x240))){
fn_8038938C(*(s32*)(self+0x240),*(s32*)(self+0x270));switch(*(s32*)(self+0x244)){case 0:*(s32*)(self+0x2c0)=0x42c;break;case 1:*(s32*)(self+0x2c0)=0x42a;break;}
if(fn_802300EC(*(s32*)(self+0x240))){s32 roomHandle=*(s32*)(self+0x198);s32 room=*(s32*)(self+0x4); if(fn_8038AD24(*(s32*)(self+0x240),*(s32*)(self+0x2c0),roomHandle,room,(msg6=*(JGeometry::TVec3f*)(self+0xc),msg6),1))*(s32*)(self+0x230)=7;}
}}break;
case 7:case 8:
if(count<*(s32*)(self+0x24c))*(s32*)(self+0x248)+=1;fn_8022FEB8(&box,*(s32*)(self+0x4),*(s32*)(self+0x198),1,0);if(fn_803865B8(*(s32*)(self+0x240))){
switch(*(s32*)(self+0x230)){
case 7:fn_8038938C(*(s32*)(self+0x240),*(s32*)(self+0x24c)-*(s32*)(self+0x270));switch(*(s32*)(self+0x244)){case 0:*(s32*)(self+0x2c0)=0x42e;break;case 1:*(s32*)(self+0x2c0)=0x42d;break;}if(fn_8038470C(*(s32*)(self+0x240),*(s32*)(self+0x2c0)))*(s32*)(self+0x230)=8;break;
case 8:if(fn_80388CAC(*(s32*)(self+0x240),*(s32*)(self+0x198))){fn_801F6884(fn_801F856C());*(s32*)(self+0x230)=6;}break;
}}break;
case 9:{
if(self[0x28f]==0)*(bool*)(self+0x28f)=fn_801F68E0(fn_801F856C())!=0;
if(*(s32*)(self+0x250)>0){*(s32*)(self+0x250)-=1;break;}
if(!self[0x28f])break;s32 boxRoom=*(s32*)(self+0x4);u8* manager=(u8*)fn_802D6A9C();JGeometry::TBox2f* bounds;if(boxRoom<8)bounds=(JGeometry::TBox2f*)(manager+0xcc);else bounds=(JGeometry::TBox2f*)(manager+0xdc);box=*bounds;
switch(*(s32*)(self+0x244)){case 0:fn_8022FEB8(&box,*(s32*)(self+0x4),*(s32*)(self+0x198),0,0);break;case 1:fn_8022FF8C(*(s32*)(self+0x254),&box,*(s32*)(self+0x4),*(s32*)(self+0x198),0,0);break;}
*(s32*)(self+0x240)=fn_8022FD8C(*(s32*)(self+0x198));if(*(s32*)(self+0x240)<0)break;
switch(*(s32*)(self+0x244)){case 0:*(s32*)(self+0x2c0)=0x426;break;case 1:*(s32*)(self+0x2c0)=0x42b;fn_803894BC(*(s32*)(self+0x240),*(s32*)(self+0x254));break;}
s32 roomHandle=*(s32*)(self+0x198);s32 room=*(s32*)(self+0x4); if(fn_8038AD24(*(s32*)(self+0x240),*(s32*)(self+0x2c0),roomHandle,room,(msg9=*(JGeometry::TVec3f*)(self+0xc),msg9),0x112))*(s32*)(self+0x230)=10;break;}
case 10:{
s32 restrictArea=1;if(*(s32*)(self+0x244)==0){s32 boxRoom=*(s32*)(self+0x4);u8* manager=(u8*)fn_802D6A9C();JGeometry::TBox2f* bounds;if(boxRoom<8)bounds=(JGeometry::TBox2f*)(manager+0xcc);else bounds=(JGeometry::TBox2f*)(manager+0xdc);box=*bounds;restrictArea=0;}
fn_8022FEB8(&box,*(s32*)(self+0x4),*(s32*)(self+0x198),restrictArea,0);
if(!fn_803865B8(*(s32*)(self+0x240)))break;
switch(*(s32*)(self+0x244)){
case 0:
if(*(s32*)(self+0x258)<fn_80138A30(lbl_8053AAF8)){
fn_803894BC(*(s32*)(self+0x240),*(s32*)(self+0x258)+1);
fn_8038938C(*(s32*)(self+0x240),actor->scores[*(s32*)(self+0x258)]);
fn_80389254(*(s32*)(self+0x240),actor->scores[*(s32*)(self+0x258)]*100);
if(actor->scores[*(s32*)(self+0x258)]>0){
if(fn_8038470C(*(s32*)(self+0x240),0x427)==1){fn_8043D874(lbl_8053AED0,*(s32*)(self+0x258),actor->scores[*(s32*)(self+0x258)]*100,0);*(s32*)(self+0x258)+=1;}
}else{if(fn_8038470C(*(s32*)(self+0x240),0x428)==1)*(s32*)(self+0x258)+=1;}
}else if(*(s32*)(self+0x258)==fn_80138A30(lbl_8053AAF8)){
if(fn_8038470C(*(s32*)(self+0x240),0x429)==1)*(s32*)(self+0x258)+=1;
}else if(fn_80388CAC(*(s32*)(self+0x240),*(s32*)(self+0x198))){fn_801F6884(fn_801F856C());*(s32*)(self+0x230)=11;((Actor*)self)->v10(255,1);}
break;
case 1:
if(!fn_80388CAC(*(s32*)(self+0x240),*(s32*)(self+0x198)))break;fn_801F6884(fn_801F856C());
if(fn_802308E0(*(s32*)(self+0x254))!=1)break;
s32 winner;void* position;s32 i;u32 shift=0;
for(i=0;i<4;i++,shift+=0x1000000){
winner=*(s32*)(self+0x254);
if(winner==i){position=fn_8023E724(winner);Actor_CreateByID(fn_801F856C(),0x494d5550,*(s32*)(self+0x4),position,(winner<<26)|(winner<<24)|0x1000a,-1,-1);}
else if(!fn_80236B50(i)&&fn_8022F514(i)==1&&*(s32*)(self+0x254)==fn_8022F3DC(i)){
winner=*(s32*)(self+0x254);position=fn_8023E724(i);Actor_CreateByID(fn_801F856C(),0x494d5550,*(s32*)(self+0x4),position,((winner<<26)|0x10000000)|shift|0x1000a,-1,-1);}
}
*(s32*)(self+0x230)=11;((Actor*)self)->v10(255,1);break;
}break;}
case 11:
fn_8022FEB8(&box,*(s32*)(self+0x4),*(s32*)(self+0x198),1,0);*(s32*)(self+0x240)=fn_8022FD8C(*(s32*)(self+0x198));if(*(s32*)(self+0x240)<0)break;switch(*(s32*)(self+0x244)){case 0:*(s32*)(self+0x2c0)=0x435;break;case 1:*(s32*)(self+0x2c0)=0x430;break;}
if(fn_802300EC(*(s32*)(self+0x240))){s32 roomHandle=*(s32*)(self+0x198);s32 room=*(s32*)(self+0x4); if(fn_8038AD24(*(s32*)(self+0x240),*(s32*)(self+0x2c0),roomHandle,room,(msg11=*(JGeometry::TVec3f*)(self+0xc),msg11),0))*(s32*)(self+0x230)=12;}break;
case 13:
if(*(s32*)(self+0x250)<=0)*(f32*)(self+0xc)-=lbl_80542560;else *(s32*)(self+0x250)-=1;
if(*(f32*)(self+0x24)-*(f32*)(self+0xc)>=lbl_80542564)*(s32*)(self+0x230)=11;break;
}
fn_801EE558(self,&delta,&distance,0);
if(distance<lbl_80542558){f32 radians=JMath::atanTable_.atan2_(-delta.x,-delta.y);radians*=lbl_8054255C;u16 angle=(s32)radians;
if(angle<0x2000||angle>=0xe000)*(s32*)(self+0x23c)=3;else if(angle>=0x2000&&angle<0x6000)*(s32*)(self+0x23c)=1;else if(angle>=0x6000&&angle<=0xa000)*(s32*)(self+0x23c)=2;else *(s32*)(self+0x23c)=0;
}else if(*(s32*)(self+0x230)==13)*(s32*)(self+0x23c)=1;else *(s32*)(self+0x23c)=2;
*(s32*)(self+0x234)-=1;if(*(s32*)(self+0x234)<=0){*(s32*)(self+0x238)+=1;switch(*(s32*)(self+0x244)){
case 0:*(s32*)(self+0x238)&=3;*(s32*)(self+0x234)=((s32*)lbl_804720E8)[*(s32*)(self+0x238)];break;
case 1:*(s32*)(self+0x238)&=1;*(s32*)(self+0x234)=((s32*)&lbl_80542510)[*(s32*)(self+0x238)];break;}}
if(*(s32*)(self+0x230)>=6&&*(s32*)(self+0x230)<=10){
camera.set(*(f32*)(self+0xc),*(f32*)(self+0x10)-*(f32*)(self+0x14),lbl_8054254C);fn_8030C210(((void**)lbl_8053AB10)[9],&camera);}
}

extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F78F4(void* mgr, u32 code, s32 idx);
extern "C" void* fn_801F666C(void* mgr, s32 idx);
extern "C" u8* lbl_8053AAF8;
extern "C" void fn_8034C358(void) {
    s32 list[30];
    s32 idx = -1;
    s32 count = 0;
    while (1) {
        s32 v = fn_801F78F4(fn_801F856C(), 0x4e495741, idx);
        idx = v;
        if (v < 0) break;
        if (count < 30) {
            list[count] = v;
            count++;
        }
    }
    u8* g = lbl_8053AAF8;
    *(u32*)(g + 0xb4) = *(u32*)(g + 0xb4) * 0x19660d + 0x3c6ef35f;
    u32 bits = (*(u32*)(g + 0xb4) >> 9) | 0x3f800000;
    void* mgr = fn_801F856C();
    f32 r = *(f32*)&bits;
    s32 n = (s32)((f32)count * (r - lbl_80542518));
    u8* p = (u8*)fn_801F666C(mgr, list[n]);
    if (p != 0) {
        p[0x2a3] = 1;
    }
}

extern "C" void fn_8034C464(Actor* self) {
    u8* p = (u8*)self;
    Vec d;
    f32 len;
    s32 i;
    u32 ang;

    *(s32*)(p + 0x230) = 0;
    *(u32*)(p + 0xb0) = 0x1000;
    *(f32*)(p + 0x3c) = 0.0f;
    *(f32*)(p + 0x40) = 0.0f;
    *(f32*)(p + 0x44) = 0.0f;
    *(s32*)(p + 0x108) = 10000;
    *(s32*)(p + 0x238) = 0;
    *(s32*)(p + 0x234) = 0;
    *(s32*)(p + 0x2c0) = 0;
    *(s32*)(p + 0x244) = *(u32*)(p + 0x90) & 0xf;
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x24c) = (*(u32*)(p + 0x90) >> 4) & 0xff;
    *(s32*)(p + 0x270) = 0;
    *(s32*)(p + 0x250) = 0x3c;
    *(s32*)(p + 0x254) = -1;
    *(s32*)(p + 0x258) = 0;
    *(s32*)(p + 0x25c) = 0;
    p[0x28f] = 0;
    p[0x28c] = 0;
    p[0x28d] = 0;
    p[0x28e] = 0;
    for (i = 0; i < 4; i++) {

        *(s32*)(p + 0x274 + i * 4) = 0;
        p[0x284 + i] = 0;
        *(s32*)(p + 0x260 + i * 4) = -1;
        p[0x288 + i] = 0;
        *(JGeometry::TVec3f*)(p + 0x290 + i * 12) = *(JGeometry::TVec3f*)fn_8023E724(i);
    }
    *(f32*)(p + 0xc) = (f32)((s32)*(f32*)(p + 0xc) / 16) * 16.0f + 8.0f;
    *(f32*)(p + 0x10) = (f32)((s32)*(f32*)(p + 0x10) / 16) * 16.0f + 8.0f;
    fn_801EE558(self, &d, &len, 0);
    if (len < 100.0f) {
        f32 angle = JMath::atanTable_.atan2_(-d.x, -d.y);
        angle *= lbl_8054255C;
        ang = (u16)angle;
        if (ang < 0x2000 || ang >= 0xe000) {
            *(s32*)(p + 0x23c) = 3;
        } else if (ang >= 0x2000 && ang < 0x6000) {
            *(s32*)(p + 0x23c) = 1;
        } else if (ang >= 0x6000 && ang <= 0xa000) {
            *(s32*)(p + 0x23c) = 2;
        } else {
            *(s32*)(p + 0x23c) = 0;
        }
    } else {
        if (*(s32*)(p + 0x230) == 0xd) {
            *(s32*)(p + 0x23c) = 1;
        } else {
            *(s32*)(p + 0x23c) = 2;
        }
    }
    *(f32*)(p + 0x60) = -8.0f;
    *(f32*)(p + 0x64) = -8.0f;
    *(f32*)(p + 0x68) = 8.0f;
    *(f32*)(p + 0x6c) = 8.0f;
    switch (*(s32*)(p + 0x244)) {
    case 0:
        *(void**)(p + 0x234) = *(void**)lbl_804720E8;
        *(s32*)(p + 0x2c0) = 0x423;
        break;
    case 1:
        *(void**)(p + 0x234) = lbl_80542510;
        *(s32*)(p + 0x2c0) = 0x427;
        break;
    }
    if ((u8)self->v11() == 1) {
        *(s32*)(p + 0x230) = 0xb;
    }
}
#pragma opt_propagation reset

void fn_8034C72C(void) {}

