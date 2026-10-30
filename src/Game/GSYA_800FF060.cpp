// GSYA_800FF060: .text 0x800FF060-0x8010089C (actor GSYA)
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0).
#include "types.h"
#define Vec SDKVec
#define PSVECMag SDK_PSVECMag
#define PSMTXScale SDK_PSMTXScale
#define PSMTXConcat SDK_PSMTXConcat
#define PSMTXIdentity SDK_PSMTXIdentity
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"
#undef PSMTXIdentity
#undef PSMTXConcat
#undef PSMTXScale
#undef PSVECMag
#undef Vec
#include "Game/Actor.h"

extern void* lbl_8053AAF8;
extern "C" s32 fn_80138A30(void* game);
extern u8* lbl_8053AF00;
extern const f32 lbl_8053C110;
extern const f32 lbl_8053C118;
extern u8 lbl_80463B8C[];
extern u8 lbl_80463B78[];
extern "C" s32 fn_8023DE58(s32 i);
extern "C" void* fn_8023E724(s32 i);
extern const f32 lbl_8053C114;
extern "C" void fn_801F06F0(Actor* a, void* p2, void* p3, const void* p4, void* p5, f32 f6, f32 f7);
extern "C" void fn_803075AC(u32 x, u32 y, void* v, void* p, int sign, int two, int minus1, u8 p7, u32 u, int zero);

// ---- from Game/fn_800FF060_dtor.cpp

extern "C" void __dt__5ActorFv(void* this_, int flag);
#ifndef dtor_80084580
#define dtor_80084580(p) (::operator delete(p))
#endif
extern void* lbl_8049C858[];

extern "C" void* fn_800FF060(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_8049C858;
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

#pragma opt_common_subs off
extern "C" void fn_800FF0C0(Actor* this_) {
    s32 minutes;
    s32 value;
    s32 i;
    s32 count;
    JGeometry::TVec3<f32> saved;
    s32 state = *(s32*)((u8*)this_ + 0x230);
    if (state == 4 || (u32)(state - 5) <= 1 || state == 7) {
        count = fn_80138A30(lbl_8053AAF8);
        for (i = 0; i < count; i++) {
            lbl_8053AF00[0x30] |= (u8)(1 << i);
            value = *(s32*)((u8*)this_ + 0x250 + i * 4);
            minutes = value / 60;
            value -= minutes * 60;
            value = (s32)((f32)value / lbl_8053C110);
            lbl_8053AF00[0x2c + i] = minutes;
            lbl_8053AF00[0x28 + i] = value;
        }
        lbl_8053AF00[0x30] |= (u8)(1 << (*(s32*)((u8*)this_ + 0x240) + 4));
        if (*(s32*)((u8*)this_ + 0x230) == 4) {
            saved = *(JGeometry::TVec3<f32>*)((u8*)this_ + 0xc);
            Vec* q = (Vec*)fn_8023E724(*(s32*)((u8*)this_ + 0x240));
            this_->field_0C.x = q->x;
            this_->field_0C.y = q->y;
            this_->field_0C.z = q->z;
            this_->field_0C.y -= lbl_8053C114;
            fn_801F06F0(this_, lbl_80463B78, (void*)0x314, 0, (void*)-1, lbl_8053C118, lbl_8053C118);
            if (fn_8023DE58(*(s32*)((u8*)this_ + 0x240)) != 0) {
                fn_803075AC(*(u32*)((u8*)this_ + 0x198), fn_8023DE58(*(s32*)((u8*)this_ + 0x240)), (u8*)this_ + 0xc, (void*)0x314, 0, 2, -1, 0, 0, 0);
            }
            this_->field_0C.x = saved.x;
            this_->field_0C.y = saved.y;
            this_->field_0C.z = saved.z;
        }
    }
    s32 variant = *(u8*)((u8*)this_ + 0x235);
    s32 id = *(s32*)((u8*)this_ + 0x23c);
    variant <<= 1;
    id += variant;
    fn_801F06F0(this_, lbl_80463B8C, (void*)(id + 0x311), 0, 0, lbl_8053C118, lbl_8053C118);
}
#pragma opt_common_subs reset
#include "Game/HitRect.h"
struct GSYA : Actor {
    s32 state;
    u8 tick, direction, finished;
    s8 nextPlayer;
    u8 swapTimer, flag;
    u8 pad23a[2];
    s32 frame, player, time, timer, previousTime;
    s32 scores[4];
    s32 timeFactor;
    s32 order[4];
    s32 rank[4];
    s32 chosen, audio;
    s32 savedMode[4], savedFlag[4];
};
extern u8* lbl_8053AB10;
extern u8* lbl_8053AF80;
extern void* lbl_8053AED0;
extern const u8 lbl_80539EA8[2];
extern const s32 lbl_8049C848[];
extern const f32 lbl_8053C128, lbl_8053C12C, lbl_8053C130;
extern "C" void fn_80239914(void*, s32, s32);
extern "C" void fn_8022FEB8(void*, s32, s32, s32, s32);
extern "C" s32 fn_8022FD8C(s32);
extern "C" u8 fn_802300EC(s32);
extern "C" u8 fn_8038AD24(s32,s32,s32,s32,const JGeometry::TVec3f&,s32);
extern "C" void fn_802308E0(s32);
extern "C" void fn_801EE558(void*,void*,f32*,s32);
extern "C" u8 fn_803865B8(s32);
extern "C" s32 fn_8037EFB4(s32);
extern "C" void fn_8038470C(s32,s32);
extern "C" void fn_803894BC(s32,s32);
extern "C" void fn_8038938C(s32,s32);
extern "C" s32 fn_802373EC(s32);
extern "C" s32 fn_8023725C(s32);
extern "C" void fn_802372F8(s32,s32,s32);
extern "C" u8 fn_80388CAC(s32,s32);
extern "C" void fn_80230534(s32);
extern "C" void fn_8022B278();
extern "C" void fn_801F0D20(void*,s32);
extern "C" void fn_80458FF0(void*,s32,s32,s32);
extern "C" void* fn_802D6A9C();
extern "C" void fn_802D8050(void*,s32,s32,s32);
extern "C" u8 fn_8023061C(s32,s32);
extern "C" void fn_80230498(s32,void*,s32,s32,s32,s32,s32);
extern "C" u8 fn_8022F514(s32);
extern "C" u8 fn_8023A3DC(s32);
extern "C" void fn_80458508(void*,s32);
extern "C" void* fn_801F856C();
extern "C" s32 fn_801F68E0(void*);
extern "C" void fn_8030C210(void*,void*);
extern "C" s32 fn_8022EA0C(s32);
extern "C" void fn_8022FE80(s32,s32,s32,s32,s32);
extern "C" void fn_801003F4(s32*);
extern "C" void fn_8022B260();
extern "C" void fn_80138B7C(void*);
extern "C" void fn_8043D874(void*,s32,s32,s32);
extern "C" u8 fn_80384C58(s32,s32);
extern "C" void fn_801F6884(void*);
#pragma opt_lifetimes off
extern "C" void fn_800FF6F8(Actor* this_) {
    GSYA* p=(GSYA*)this_;
    s32 chosen;
    GSYA* walker;
    s32 message;
    JGeometry::TVec3f pos(*(JGeometry::TVec3f*)&p->field_0C);
    pos.y-=lbl_8053C128;
    JGeometry::TVec3f cam(*(JGeometry::TVec3f*)&p->field_0C);
    f32 box[4];
    JGeometry::TVec3f probe;
    JGeometry::TVec3f temp0,temp1,temp2;
    JGeometry::TVec3f dir,dir2;
    f32 dist,dist2;
    box[0]=p->field_60;
    box[1]=p->field_64;
    box[2]=p->field_68;
    box[3]=p->field_6C;
    box[0]+=p->field_0C.x;
    box[1]+=p->field_0C.y;
    box[2]+=p->field_0C.x;
    box[3]+=p->field_0C.y;
    fn_80239914(box,p->field_04,p->field_198);
    p->tick++;
    if(p->tick==lbl_80539EA8[p->frame]){
        p->frame++;
        if(p->frame==2)p->frame=0;
        p->tick=0;
    }
    switch(p->state){
    case 0:
        fn_8022FEB8(box,p->field_04,p->field_198,1,0);
        p->player=fn_8022FD8C(p->field_198);
        if(p->player>=0 && fn_802300EC(p->player)){
            s32 handle=p->field_198;
            s32 room=p->field_04;
            if(fn_8038AD24(p->player,0x26b,handle,room,(temp0=pos,temp0),0)){
                for(int i=0;i<4;i++)fn_802308E0(i);
                p->state=1;
                fn_801EE558(this_,&dir,&dist,p->player+1);
        if(dist<lbl_8053C12C){
            f32 radians=JMath::atanTable_.atan2_(-dir.x,-dir.y);
            u32 angle=(u16)(s32)(radians*lbl_8053C130);
            if(angle<0x2000 || angle>=0xe000)p->direction=3;
            else if(angle>=0x2000 && angle<0x6000)p->direction=1;
            else if(angle>=0x6000 && angle<=0xa000)p->direction=2;
            else p->direction=0;
        }
            }
        }
        break;
    case 1:
        {u8* c=*(u8**)(lbl_8053AB10+0x24);
        if(c[0x7f5]==0){
            c[0x7f4]=1; *(s32*)(c+0x7f8)=4;
            *(f32*)(c+0x7fc)=cam.x; *(f32*)(c+0x800)=cam.y; *(f32*)(c+0x804)=cam.z;
            c[0x7f6]=0;
        }}
        fn_8022FEB8(box,p->field_04,p->field_198,1,0);
        if(fn_803865B8(p->player)){
            switch(fn_8037EFB4(p->player)){
            case 0:
                if(fn_80138A30(lbl_8053AAF8)==1){
                    fn_8038470C(p->player,0x285);
                    p->state=2;p->timer=0;
                }else{
                    s32 count=fn_80138A30(lbl_8053AAF8);
                    p->chosen=(s32)((f32)count*((JMARandFast*)((u8*)lbl_8053AAF8+0xb4))->get_ufloat_1());
                    if(p->chosen==4)p->chosen=3;
                    fn_803894BC(p->player,p->chosen+1);
                    fn_8038938C(p->player,p->timeFactor);
                    fn_8038470C(p->player,0x26c);
                    chosen=p->chosen;
                    walker=p;
                    for(message=0;message<4;message++,walker=(GSYA*)((u8*)walker+4)){
                        walker->savedMode[0]=fn_802373EC(message);
                        walker->savedFlag[0]=fn_8023725C(message);
                        fn_802372F8(message,0,1);
                    }
                    fn_802372F8(chosen,5,1);
                    p->state=3;p->timer=0;
                }
                break;
            case 1:
                fn_8038470C(p->player,0x26d);
                p->state=2;p->timer=0;
                break;
            }
        }
        break;
    case 2:
        {u8* c=*(u8**)(lbl_8053AB10+0x24);
        if(c[0x7f5]==0){
            c[0x7f4]=1; *(s32*)(c+0x7f8)=4;
            *(f32*)(c+0x7fc)=cam.x; *(f32*)(c+0x800)=cam.y; *(f32*)(c+0x804)=cam.z;
            c[0x7f6]=0;
        }}
        fn_8022FEB8(box,p->field_04,p->field_198,1,0);
        if(fn_80388CAC(p->player,p->field_198)){
            p->state=0;p->timer=0;fn_80230534(0);
        }
        break;
    case 3:
        {u8* c=*(u8**)(lbl_8053AB10+0x24);
        if(c[0x7f5]==0){
            c[0x7f4]=1; *(s32*)(c+0x7f8)=4;
            *(f32*)(c+0x7fc)=cam.x; *(f32*)(c+0x800)=cam.y; *(f32*)(c+0x804)=cam.z;
            c[0x7f6]=0;
        }}
        fn_8022FEB8(box,p->field_04,p->field_198,1,0);
        if(fn_80388CAC(p->player,p->field_198)){
            p->player=p->chosen;p->state=4;p->timer=0;
            p->time=p->timeFactor*60;
            p->previousTime=p->timeFactor*60;
            p->nextPlayer=-2;p->swapTimer=0;
            p->scores[0]=0;p->scores[1]=0;p->scores[2]=0;p->scores[3]=0;p->timeFactor=0;
            fn_80230534(0);fn_802308E0(p->player);fn_8022B278();
            fn_801F0D20(p,0x3a);
            p->audio=*(s32*)(lbl_8053AF80+0x58);
            fn_80458FF0(lbl_8053AF80,0x1000007,1,0);
            u32 flag=p->flag;
            if(flag)fn_802D8050(fn_802D6A9C(),flag,1,0xff);
        }
        break;
    case 4:
        if(p->time==p->previousTime-180){
            fn_8023061C(p->player,0);p->nextPlayer=-1;
        }
        if(p->nextPlayer>=0){
            p->swapTimer++;
            if(p->swapTimer==15){
                fn_801F0D20(p,0x2a);
                fn_802372F8(p->player,0,1);
                p->player=p->nextPlayer;
                fn_802372F8(p->player,5,1);
                fn_802308E0(p->player);
                p->previousTime=p->time;
                p->nextPlayer=-2;p->swapTimer=0;
            }
        }else if(p->nextPlayer==-2){
            probe=*(JGeometry::TVec3f*)fn_8023E724(p->player);
            if((p->time&7)==0)p->swapTimer++;
            fn_80230498(p->player,&probe,(p->swapTimer&3)+0xbd,0xff,-128,-128,1);
            if(p->time%60==59)fn_801F0D20(p,0x3f);
        }else if(p->nextPlayer==-1){
            for(int i=0;i<4;i++){
                if(!fn_8022F514(i) && fn_8023A3DC(i) && p->player!=i){
                    p->nextPlayer=i;p->swapTimer=0;
                }
            }
        }
        p->time--;
        if(p->nextPlayer==-1){
            p->scores[p->player]++;
            if(p->scores[p->player]>=3000)fn_80458508(lbl_8053AF80,1);
            else fn_80458508(lbl_8053AF80,0);
        }
        for(int i=0;i<4;i++)if(p->scores[i]==3600)p->finished=1;
        if(p->time==0 || p->finished){
            fn_801F68E0(fn_801F856C());
            p->state=5;p->timer=0;
            fn_801F0D20(p,0x3b);p->direction=2;fn_80458508(lbl_8053AF80,0);
        }
        break;
    case 5:{
        fn_8030C210(*(void**)(lbl_8053AB10+0x24),&p->field_0C);
        p->timer++;
        s32 status=fn_801F68E0(fn_801F856C());
        if(p->timer>50 && status==1){
            p->player=fn_8022EA0C(p->player);
            fn_8022FE80(p->player,fn_8023DE58(p->player),p->field_198,0,0);
            if(fn_8022FD8C(p->field_198)>=0){
                fn_801003F4((s32*)p);
                fn_803894BC(p->player,1);
                s32 handle=p->field_198;
                s32 room=p->field_04;
                fn_8038AD24(p->player,0x26e,handle,room,(temp1=pos,temp1),2);
                p->state=6;p->timer=0;
                fn_8022B260();fn_80138B7C(lbl_8053AAF8);p->timer=0;
            }
        }
        break;}
    case 6:
        fn_8030C210(*(void**)(lbl_8053AB10+0x24),&p->field_0C);
        fn_8022FE80(p->player,fn_8023DE58(p->player),p->field_198,0,0);
        if(fn_803865B8(p->player)){
            if(p->timer>0){
                s32 reward=lbl_8049C848[p->rank[p->timer-1]];
                if(reward)fn_8043D874(lbl_8053AED0,p->order[p->timer-1],reward,0);
            }
            if(p->timer<fn_80138A30(lbl_8053AAF8)){
                fn_803894BC(p->player,p->order[p->timer]+1);
                switch(p->rank[p->timer]){
                case 0:message=0x36b;break;
                case 1:message=0x36c;break;
                case 2:message=0x36d;break;
                case 3:message=0x36e;break;
                }
                fn_8038470C(p->player,message);
            }else{
                fn_8038470C(p->player,0x36f);p->state=7;p->timer=0;
            }
            p->timer++;
        }
        break;
    case 7:
        fn_8030C210(*(void**)(lbl_8053AB10+0x24),&p->field_0C);
        fn_8022FE80(p->player,fn_8023DE58(p->player),p->field_198,0,0);
        if(fn_803865B8(p->player) && fn_80384C58(p->player,p->field_198)){
            p->v10(0xff,1);
            p->state=8;p->timer=0;
            fn_801F6884(fn_801F856C());
            for(chosen=0,walker=p;chosen<4;chosen++,walker=(GSYA*)((u8*)walker+4))if(!fn_8022F514(chosen))fn_802372F8(chosen,walker->savedMode[0],walker->savedFlag[0]);
        }
        break;
    case 8:
        fn_8022FEB8(box,p->field_04,p->field_198,1,0);
        p->player=fn_8022FD8C(p->field_198);
        if(p->player>=0){
            s32 handle=p->field_198;
            s32 room=p->field_04;
            if(fn_8038AD24(p->player,0x370,handle,room,(temp2=pos,temp2),0)){
                p->state=9;p->timer=0;
                fn_801EE558(this_,&dir2,&dist2,p->player+1);
        if(dist2<lbl_8053C12C){
            f32 radians=JMath::atanTable_.atan2_(-dir2.x,-dir2.y);
            u32 angle=(u16)(s32)(radians*lbl_8053C130);
            if(angle<0x2000 || angle>=0xe000)p->direction=3;
            else if(angle>=0x2000 && angle<0x6000)p->direction=1;
            else if(angle>=0x6000 && angle<=0xa000)p->direction=2;
            else p->direction=0;
        }
            }
        }
        break;
    case 9:
        fn_8022FEB8(box,p->field_04,p->field_198,1,0);
        if(fn_80388CAC(p->player,p->field_198)){p->state=8;p->timer=0;}
        break;
    }
}
#pragma opt_lifetimes reset
extern "C" s32 fn_80138A30(void* game);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D7844(void* mgr, s32 flag, s32 idx);
extern void* lbl_8053AAF8;
extern u32 lbl_80543F18;
extern "C" void fn_801003F4(s32* this_) {
    s32* out;
    s32* p;
    s32 k = 0;
    u32 used = lbl_80543F18;
    s32 count = fn_80138A30(lbl_8053AAF8);
    s32 i;
    p = this_;
    for (i = 0; i < count; i++) {
        if (p[0x94] == 0) {
            fn_802D7844(fn_802D6A9C(), 1, i);
        } else {
            fn_802D7844(fn_802D6A9C(), 0, i);
        }
        p++;
    }
    out = this_;
    for (; k != count; k++) {
        u8* f = (u8*)&used;
        p = this_;
        s32 best = 1000000;
        s32 idx = -1;
        for (s32 j = 0; j < count; j++) {
            if (best > p[0x94] && *f == 0) {
                best = p[0x94];
                idx = j;
            }
            p++;
            f++;
        }
        out[0x99] = idx;
        ((u8*)&used)[idx] = 1;
        out++;
    }
    this_[0x9d] = 0;
    if (this_[0x94 + this_[0x99]] == this_[0x94 + this_[0x9a]]) {
        this_[0x9e] = 0;
    } else {
        this_[0x9e] = 1;
    }
    if (count != 2) {
        if (this_[0x94 + this_[0x9a]] == this_[0x94 + this_[0x9b]]) {
            this_[0x9f] = this_[0x9e];
        } else {
            this_[0x9f] = 2;
        }
        if (count != 3) {
            if (this_[0x94 + this_[0x9b]] == this_[0x94 + this_[0x9c]]) {
                this_[0xa0] = this_[0x9f];
            } else {
                this_[0xa0] = 3;
            }
        }
    }
}

extern const f32 lbl_8053C134;
extern const f32 lbl_8053C138;
extern "C" void fn_801005C4(Actor* this_) {
    f32 b = lbl_8053C138;
    f32 a = lbl_8053C134;
    *(f32*)((u8*)this_ + 0x60) = a;
    *(f32*)((u8*)this_ + 0x64) = a;
    *(f32*)((u8*)this_ + 0x68) = b;
    *(f32*)((u8*)this_ + 0x6c) = b;
    ((u8*)this_)[0x235] = 2;
    *(s32*)((u8*)this_ + 0x23c) = 0;
    ((u8*)this_)[0x234] = 0;
    *(s32*)((u8*)this_ + 0x240) = -1;
    ((u8*)this_)[0x236] = 0;
    ((u8*)this_)[0x239] = (*(u32*)((u8*)this_ + 0x90) >> 0x16) & 0x1f;
    *(s32*)((u8*)this_ + 0x230) = 0;
    *(s32*)((u8*)this_ + 0x248) = 0;
    *(s32*)((u8*)this_ + 0x260) = 600;
    if ((u8)this_->v11()) {
        *(s32*)((u8*)this_ + 0x230) = 8;
        *(s32*)((u8*)this_ + 0x248) = 0;
    } else {
        *(s32*)((u8*)this_ + 0x230) = 0;
        *(s32*)((u8*)this_ + 0x248) = 0;
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
