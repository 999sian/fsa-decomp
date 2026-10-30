#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"

struct Unk8030EC18Buf {
    u8 idx[16];
    s32 w20;
    s32 w24;
    s32 w28;
    u8 b2c;
    u8 b2d;
    u8 b2e;
    u8 b2f;
    u8 b30;
    u8 b31;
    u8 b32;
    u8 b33;
    u8 b34;
    u8 b35;
    u8 b36;
    s32 w38;
    u8 b3c;
    u8 b3d;
    u8 b3e;
    s32 w40;
    s32 w44;
    s32 w48;
};


extern "C" char lbl_804AA9F0[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" u16 fn_8022461C(f32* pos, u32 room);
extern "C" u16 fn_80226850(f32* pos, u32 room);
extern "C" u8* fn_802D6A9C(void);
extern "C" const f32 lbl_8054173C;
extern "C" Actor* fn_8030E9A0(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804AA9F0;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" void fn_8030EA00(void* p) {
    *(s32*)((u8*)p + 0x230) = 7;
}

extern "C" bool fn_8030EA0C(void* p) {
    return *(s32*)((u8*)p + 0x230) < 6;
}

extern "C" u32 fn_8030EA2C(Actor* p, s32 room, f32* pos) {
    s32 kind;
    s32 x;

    if (*((u8*)p + 0x245) != 0) {
        return 0;
    }
    kind = fn_8022461C(pos, room);
    x = fn_80226850(pos, room);
    if ((u32)(kind - 0x10) <= 7 || (x >= 0x140 && x <= 0x15f)) {
        *((u8*)p + 0x245) = 1;
        return 0;
    }
    if (kind != 0 && kind != 4 && kind != 5 && kind != 6 && kind != 7 && kind != 2 && kind != 3 && kind != 0xe && kind != 0x50 && kind != 0xc && kind != 0x27 && kind != 0x28 && kind != 0x29 && kind != 0x2a && kind != 0x2b && kind != 0x2c && kind != 0x2d && kind != 0x2e && kind != 0x2f && kind != 0x20 && kind != 0xd && kind != 0x3b && kind != 0x39 && kind != 0x3a && kind != 0x4c && kind != 0x4d && kind != 0x4e && kind != 0x4f && kind != 0x24) {
        if (kind == 0x25) {
            return fn_802D6A9C()[0x171] == 0;
        }
        if (kind == 0x26) {
            return fn_802D6A9C()[0x171] == 1;
        }
        if (kind != 0x22 || fn_802D6A9C()[0x170] == 1) {
            return 1;
        }
    }
    return 0;
}

extern "C" char lbl_804713A8[];
extern "C" f32 lbl_80541744;
extern "C" s32 fn_8023CB24(void*);
extern "C" s32 fn_8023CA88(void*);
extern "C" void fn_801F06F0(Actor* p, void* a, s32 b, u8* buf, s32 c, f32 d, f32 e);
extern "C" void fn_803075AC(void* a, void* b, void* c, s32 d, s32 e, s32 f, s32 g, u8 h, s32 i, s32 j);
extern "C" void fn_8030EC18(Actor* p) {
    Unk8030EC18Buf buf;
    s32 i;

    if (*(s32*)((u8*)p + 0x230) <= 7) {
        buf.w20 = -1;
        buf.w24 = -1;
        for (i = 0; (u8)i < 0x10; i += 8) {
            buf.idx[(u8)i] = i;
            buf.idx[(u8)(i + 1)] = i + 1;
            buf.idx[(u8)(i + 2)] = i + 2;
            buf.idx[(u8)(i + 3)] = i + 3;
            buf.idx[(u8)(i + 4)] = i + 4;
            buf.idx[(u8)(i + 5)] = i + 5;
            buf.idx[(u8)(i + 6)] = i + 6;
            buf.idx[(u8)(i + 7)] = i + 7;
        }
        buf.w20 = -1;
        buf.w24 = 0;
        buf.w28 = 0;
        buf.b2c = 0;
        buf.b2d = 0;
        buf.b2e = 0;
        buf.b2f = 1;
        buf.b30 = 1;
        buf.b31 = 0;
        buf.b32 = 0;
        buf.b33 = 0;
        buf.b34 = 0;
        buf.b35 = 0;
        buf.b36 = 1;
        buf.w38 = 3;
        buf.b3c = 1;
        buf.b3d = 0;
        buf.b3e = 0;
        buf.w40 = -1;
        buf.w44 = 0;
        buf.w48 = 2;
        if (*((u8*)p + 0xc4) != 0) {
            buf.b30 = 0;
            buf.b2d = fn_8023CB24(*(void**)((u8*)p + 0xc8)) + 1;
            buf.b2c = fn_8023CA88(*(void**)((u8*)p + 0xc8));
        }
        fn_801F06F0(p, lbl_804713A8, *(s32*)((u8*)p + 0x24c) + 0x2ff, (u8*)&buf, 0, lbl_80541744, lbl_80541744);
        fn_803075AC(*(void**)((u8*)p + 0x198), *(void**)((u8*)p + 4), (u8*)p + 0xc, 0x2ff, 0, 2, -1, *((u8*)p + 0xc4), 0, 0);
    }
}

extern "C" u8* fn_801F856C(void);
extern "C" void fn_801F31C4(void* a, f32* box);
#include "JSystem/JGeometry.h"
struct SmriActor : Actor {
    s32 state;
    s32 direction;
    s32 timer;
    s32 tile;
    s32 handle;
    u8 tick;
    u8 unk245;
    u8 players[4];
};
extern "C" const f32 lbl_80541738, lbl_80541740, lbl_80541748, lbl_8054174C, lbl_80541750, lbl_80541754, lbl_80541758, lbl_8054175C, lbl_80541760, lbl_80541764;
extern "C" f32 lbl_80471368[];
extern "C" s32 lbl_80471398[];
extern "C" s32 fn_801F78F4(void*,u32,s32);
extern "C" Actor* fn_801F666C(void*,s32);
extern "C" void fn_803513C0(void*);
extern "C" void fn_803511F0(void*);
extern "C" void* fn_8013CC50(s32,void*,s32,s32,s32,s32,s32,s32,f32);
extern "C" void fn_801F0E34(void*,u32,s32);
extern "C" u16 fn_802265FC(void*,s32);
extern "C" s32 fn_801F2618(void*,s32,s32);
extern "C" u8 fn_8022DB04(s32);
extern "C" s32 fn_80238CB4(s32);
extern "C" void fn_80239878(s32,void*,s32,s32);
extern "C" u8 fn_8023B0F4(s32,void*,s32,s32,f32);
extern "C" s32 fn_80238BC4(s32);
extern "C" s32 fn_80239558(void*,s32,s32);
extern "C" s32 fn_80239040(s32);
extern "C" u8 fn_80233DA4(s32);
extern "C" u8 fn_8023F264(s32);
extern "C" u8 fn_80239C00(s32,void*,s32);
extern "C" u8 fn_8022F9E4(s32,s32,s32,s32);
extern "C" u8 fn_80230188(s32);
extern "C" u8 fn_8022D75C(s32);
extern "C" void* fn_8022C52C(s32,s32);
extern "C" Vec* fn_8023E7B0(void*);
extern "C" s32 fn_8023DE58(void*);
extern "C" u8 fn_802DE9A0(void);
extern "C" u8 fn_802DEB58(void);
extern "C" void* Actor_CreateByID(void*,u32,s32,void*,u32,s32,s32);
static inline bool SmriCheckGround(SmriActor* p) {
    const f32 half=0.5f;
    JGeometry::TBox2f box;
    box.set(*(JGeometry::TBox2f*)((u8*)p+0x80));
    box.addPos(*(JGeometry::TVec2<f32>*)&p->field_0C);
    JGeometry::TVec2<f32> center;
    center.set(half*(box.i.x-box.f.x)+box.f.x, half*(box.i.y-box.f.y)+box.f.y);
    s32 kind=fn_802265FC(&center,p->field_04);
    if(kind==3 || (u32)(kind-13)<=1 || kind==0x3b){
        p->field_3C.x=lbl_8054173C;
        p->field_3C.y=lbl_8054173C;
        p->field_3C.z=lbl_8054173C;
        p->state=6;
        p->tile=kind;
        return false;
    }
    return true;
}
static inline void SmriPlayerBox(SmriActor* p, JGeometry::TBox2f& box) {
    for(s32 i=0;i<4;i++){
        if(p->players[i]==1){
            if(fn_8022DB04(i)) {
                s32 handle=p->field_198;
                if(handle!=fn_80238CB4(i)) continue;
            }
            fn_80239878(i,&box,p->field_04,(s32)p->field_198);
        } else if(!fn_8023B0F4(i,&box,p->field_04,0,lbl_80541740)) p->players[i]=1;
    }
}

extern "C" void fn_8030EDBC(SmriActor* p) {
 s32 i,n;
 JGeometry::TBox2f pb;
 pb.set(*(JGeometry::TBox2f*)&p->field_60); pb.addPos(*(JGeometry::TVec2<f32>*)&p->field_0C);
 if(p->state<=6 && p->field_C4==0 && p->field_0C.z<=lbl_8054173C){
 n=*(s32*)(fn_801F856C()+0x1008);
 for(i=0;i<n;i++){
 Actor* other=*(Actor**)(fn_801F856C()+8+i*4);
 if(other && other->field_11C && (s32)other->field_04==(s32)p->field_04 && other->field_1A0=='OBLF'){
 JGeometry::TBox2f box;
 fn_801F31C4(other,(f32*)&box);
 u8* object=(u8*)other;
 if(*(s32*)(object+0x258)==11){
 JGeometry::TBox2f overlap(pb);
 if(overlap.intersect(box)){
 s32 index=-1;
 for(;;){
 s32 found=fn_801F78F4(fn_801F856C(),'SMRI',index); index=found; if(found<0)break;
 SmriActor* actor=(SmriActor*)fn_801F666C(fn_801F856C(),found);
 if(actor->state!=8)continue;
 if(actor->field_110!=p->field_110)continue;
 actor->state=9; break;
 }
 fn_803513C0(object);p->state=8;p->handle=other->field_198;break;
 }}}}}
 switch(p->state){
 case 0:
 fn_8013CC50(p->field_04,&p->field_0C,0x457,0,0,0,0,1,lbl_80541744);
 fn_8013CC50(p->field_04,&p->field_0C,0x458,0,0,0,0,1,lbl_80541744);
 p->state=1;p->timer=20;fn_801F0E34(p,0x30064,0);break;
 case 1: p->timer--; if(p->timer<=0)p->state=2;break;
 case 2:{
 JGeometry::TVec3f delta,saved;
 if(SmriCheckGround(p)){
 JGeometry::TBox2f support;support.set(*(JGeometry::TBox2f*)&p->field_60);support.addPos(*(JGeometry::TVec2<f32>*)&p->field_0C);SmriPlayerBox(p,support);
 s32 player=fn_80238BC4(p->field_198);
 if(player>=0 && player<4){
 saved=*(JGeometry::TVec3f*)&p->field_0C;
 delta.set(lbl_80471368[player*3],lbl_80471368[player*3+1],lbl_80471368[player*3+2]);
 *(JGeometry::TVec3f*)&p->field_0C+=delta;
 if((u8)fn_801F2618(p,0,0)){*(JGeometry::TVec3f*)&p->field_0C=saved;break;}
 *(JGeometry::TVec3f*)&p->field_0C=saved;
 if(fn_80239558(&pb,p->field_04,p->field_198)>=0 && !fn_80233DA4(fn_80239040(p->field_198))){
 ((JGeometry::TVec3f*)&p->field_3C)->set(lbl_80471368[player*3],lbl_80471368[player*3+1],lbl_80471368[player*3+2]);
 p->state=3;p->direction=player;p->timer=1;p->tick=0;
 }
 }else{
 for(s32 i=0;i<4;i++)if(fn_8023F264(i)&&fn_80239C00(i,&pb,p->field_04)&&fn_8022F9E4(i,p->field_198,1,0)){
 p->state=4;p->timer=0;p->players[0]=0;p->players[1]=0;p->players[2]=0;p->players[3]=0;break;
 }
 }}break;}
 case 3:{
 *(JGeometry::TVec3f*)&p->field_0C+=*(JGeometry::TVec3f*)&p->field_3C;
 pb.set(*(JGeometry::TBox2f*)&p->field_60);pb.addPos(*(JGeometry::TVec2<f32>*)&p->field_0C);
 JGeometry::TBox2f moving;moving.set(*(JGeometry::TBox2f*)&p->field_60);moving.addPos(*(JGeometry::TVec2<f32>*)&p->field_0C);SmriPlayerBox(p,moving);
 if((p->tick&31)==0)fn_801F0E34(p,0x30004,0);
 p->tick++;
 if(SmriCheckGround(p)){
 if(!(u8)fn_801F2618(p,0,0)){
 p->timer--;if(p->timer>0)break;
 s32 player=fn_80239040(p->field_198);
 if(player>=0 && !fn_80230188(player)&&!fn_8022D75C(player)&&fn_8022C52C(player,lbl_80471398[p->direction])){
 p->timer=1;break;
 }}
 p->field_3C.x=lbl_8054173C;p->field_3C.y=lbl_8054173C;p->field_3C.z=lbl_8054173C;p->state=2;p->timer=0;p->tick=0;
 }break;}
 case 4:
 if(p->field_C4){
 Vec* pos=fn_8023E7B0((void*)p->field_C8);p->field_0C.x=pos->x;p->field_0C.y=pos->y;p->field_0C.z=pos->z;p->field_04=fn_8023DE58((void*)p->field_C8);break;
 }
 p->field_3C.x*=lbl_80541748;p->field_3C.y*=lbl_80541748;p->field_3C.z=lbl_8054174C;p->state=5;
 case 5:
 *(JGeometry::TVec3f*)&p->field_0C+=*(JGeometry::TVec3f*)&p->field_3C;
 if(p->timer==0)p->field_3C.z-=lbl_80541750;else p->field_3C.z-=lbl_80541754;
 fn_801F2618(p,0,0);
 if(p->field_0C.z<lbl_8054173C && p->field_3C.z<lbl_8054173C && SmriCheckGround(p)){
 p->field_0C.z=lbl_8054173C;p->field_3C.z=lbl_8054173C;p->field_3C.x*=lbl_80541758;p->field_3C.y*=lbl_80541758;
 if(p->timer==0){p->field_3C.z=lbl_8054175C;p->timer++;}else{p->field_3C.z=lbl_8054173C;p->field_3C.y=lbl_8054173C;p->field_3C.x=lbl_8054173C;p->state=2;p->timer=0;}
 p->unk245=0;fn_801F0E34(p,0x5007f,0);
 }break;
 case 6:
 *(JGeometry::TVec3f*)&p->field_0C+=*(JGeometry::TVec3f*)&p->field_3C;
 if(p->field_0C.z<lbl_80541760){
 if(p->tile==14&&fn_802DE9A0()==1)fn_801F0E34(p,0x5005f,0);
 else if(p->tile==14&&fn_802DEB58()==1)fn_801F0E34(p,0x5003f,0);
 else if(p->tile==13||p->tile==0x3b)fn_801F0E34(p,0x30022,0);
 else fn_801F0E34(p,0x3007c,0);
 p->field_11C=0;
 }else p->field_3C.z-=lbl_80541764;break;
 case 8:
 for(u32 i=0;i<4;i++){s32 param=p->field_110;Actor_CreateByID(fn_801F856C(),'FIRE',p->field_04,&p->field_0C,(i*16|0x1000)|(param&3),-1,param);}
 fn_8013CC50(p->field_04,&p->field_0C,0x95,0,0,0,0,1,lbl_80541744);
 fn_8013CC50(p->field_04,&p->field_0C,0x96,0,0,0,0,1,lbl_80541744);
 p->field_11C=0;break;
 case 9:{Actor* actor=fn_801F666C(fn_801F856C(),p->handle);if(actor)fn_803511F0(actor);p->field_11C=0;break;}
 }
}

extern "C" f32 lbl_80471368[];
extern "C" const f32 lbl_80541740;
extern "C" const f32 lbl_8054174C;
extern "C" const f32 lbl_80541760;
extern "C" const f32 lbl_80541768;
extern "C" const f32 lbl_8054176C;
extern "C" const f32 lbl_80541770;
extern "C" const f32 lbl_80541774;
extern "C" s32 fn_80230CFC(void*);
extern "C" s32 fn_801F2618(void*, s32, s32);
#pragma opt_propagation off
extern "C" void fn_8030F9E4(u8* this_) {
    f32 vy;
    f32 vx;
    *(f32*)(this_ + 0x3c) = lbl_8054173C;
    *(f32*)(this_ + 0x40) = lbl_8054173C;
    *(f32*)(this_ + 0x44) = lbl_8054173C;
    *(f32*)(this_ + 0x60) = lbl_80541768;
    *(f32*)(this_ + 0x64) = lbl_80541768;
    *(f32*)(this_ + 0x68) = lbl_8054176C;
    *(f32*)(this_ + 0x6c) = lbl_8054176C;
    *(f32*)(this_ + 0x80) = lbl_80541760;
    *(f32*)(this_ + 0x84) = lbl_80541760;
    *(f32*)(this_ + 0x88) = lbl_80541770;
    *(f32*)(this_ + 0x8c) = lbl_80541770;
    *(s32*)(this_ + 0x1a4) = 0;
    *(s32*)(this_ + 0xb8) = 2;
    *(s32*)(this_ + 0x230) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x240) = -1;
    this_[0x245] = 0;
    this_[0x246] = 0;
    this_[0x247] = 0;
    this_[0x248] = 0;
    this_[0x249] = 0;
    *(s32*)(this_ + 0x23c) = -1;
    this_[0x244] = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(s32*)(this_ + 0x254) = 0;
    s32 i = 0;
    while (fn_801F2618(this_, 0, 0) & 0xff) {
        f32* v = &lbl_80471368[(fn_80230CFC(*(void**)(this_ + 0x110)) ^ 1) * 3];
        vy = v[1];
        vx = v[0];
        i++;
        *(f32*)(this_ + 0xc) += lbl_8054174C * vx;
        *(f32*)(this_ + 0x10) += lbl_8054174C * vy;
        if (i > 8) {
            break;
        }
    }
    *(f32*)(this_ + 0x80) = lbl_80541774;
    *(f32*)(this_ + 0x84) = lbl_80541774;
    *(f32*)(this_ + 0x88) = lbl_80541740;
    *(f32*)(this_ + 0x8c) = lbl_80541740;
}
#pragma opt_propagation reset
#include "JSystem/JAudio/JASFakeMatchFSA.h"
