#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "JSystem/JAudio/JASFakeMatchFSA.h"

/* Actor with the 0x18 bytes of members that follow the base (size 0x250). */
struct ActorExt : Actor {
    /* 0x230 */ s32 m230;
    /* 0x234 */ s32 m234;
    /* 0x238 */ s32 m238;
    /* 0x23C */ s32 m23C;
    /* 0x240 */ s32 m240;
    /* 0x244 */ s32 m244;
    /* 0x248 */ s32 m248;
    /* 0x24C */ s32 m24C;
};


extern "C" char lbl_804A8010[];
extern "C" void __dt__5ActorFv(void* p, int how);
extern "C" Actor* fn_802A8220(Actor* param_1, s16 param_2)
{
    if (param_1 != 0) {
        *(void**)param_1 = lbl_804A8010;
        __dt__5ActorFv(param_1, 0);
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_802A8280(void)
{
    return;
}

#include "JSystem/JMath/JMath.h"
#include "JSystem/JGeometry/Vec.h"
extern "C" u8* lbl_8053AAF8;
extern "C" u8* lbl_8053AB10;
extern "C" void* lbl_8053AF80;
extern "C" u8* fn_802D6A9C();
extern "C" void fn_801F0D20(void*,s32);
extern "C" void fn_80458880(void*,s32,s32);
extern "C" s32 fn_80138A30(void*);
extern "C" void* fn_801F856C();
extern "C" s32 Actor_CreateByID(void*,u32,u32,void*,u32,s32,s32);
extern "C" Actor* fn_801F666C(void*,s32);
extern "C" s32 fn_801F8544(void*,u32,u32,void*,u32);
extern "C" void fn_802D8050(void*,u32,u8,u8);
extern "C" const f32 sincosTable___5JMath[];
extern "C" const f32 lbl_80540840,lbl_80540844,lbl_80540848,lbl_8054084C,lbl_80540850,lbl_80540854,lbl_80540858,lbl_8054085C,lbl_80540860,lbl_80540864,lbl_80540868,lbl_8054086C,lbl_80540870;

#pragma push
#pragma opt_propagation off
static inline s32 SpawnRadiusNonZero(f32 value) {
    return value!=lbl_80540854;
}

static inline u8 SpawnRadiusZero(f32 value) {
    u8 zero=!SpawnRadiusNonZero(value);
    return zero;
}

static inline f32 SpawnRandom() {
    union { f32 f; u32 s; } out;
    JMARandFast* rnd=(JMARandFast*)(lbl_8053AAF8+0xb4);
    out.s=(rnd->get()>>9)|0x3f800000;
    return out.f-lbl_80540858;
}

extern "C" void fn_802A8284(ActorExt* a) {
    s32 room=a->field_04;
    u8* manager=fn_802D6A9C();
    f32* box=room<8?(f32*)(manager+0xcc):(f32*)(manager+0xdc);
    Vec pos;
    switch((s32)a->m230) {
    case 0: {
        if(a->m244==3||a->m244==12){fn_801F0D20(a,3);a->m230=1;break;}
        if(!(u8)a->v11())break;
        u32 param=0;
        u32 id;
        if((s32)a->m248>0)--a->m248;
        if(a->m24C>0)--a->m24C;
        if(a->m24C!=0) {
            if(a->m244==0||a->m244==1||a->m244==11||a->m244==13){ u8* camera=*(u8**)(lbl_8053AB10+0x24);if(!camera[0x7f4])camera[0x7f5]=1; }
            return;
        }
        if(a->m244==0||a->m244==1||a->m244==11||a->m244==13){ u8* camera=*(u8**)(lbl_8053AB10+0x24);if(!camera[0x7f4])camera[0x7f5]=1; }
        switch(a->m244) {
        case 0:case 6:case 7:fn_801F0D20(a,3);a->m230=1;break;
        case 5:a->m240=128;fn_80458880(lbl_8053AF80,6,-1);a->m230=3;break;
        case 1:a->m240=8;fn_80458880(lbl_8053AF80,6,-1);a->m230=3;break;
        case 2:a->m240=8;fn_80458880(lbl_8053AF80,6,-1);param=3;id=0x48424d42;break;
        case 4:a->m240=8;fn_80458880(lbl_8053AF80,6,-1);param=0x50000;id=0x534c5231;break;
        case 10:a->m240=1;id=0x534c5231;param=0x30000;param|=0x102;break;
        case 8:a->m240=2;fn_80458880(lbl_8053AF80,6,-1);param=1;id=0x48494e4f;break;
        case 9:a->m240=8;fn_80458880(lbl_8053AF80,6,-1);param=4;id=0x5354414c;break;
        case 11:fn_80458880(lbl_8053AF80,6,-1);
        case 13:param=0;id=0x524f5045;break;
        }
        if(a->m244==2||a->m244==4||(u32)(a->m244-8)<=3||a->m244==13) {
            for(s32 i=0;i<a->m240;i++) {
                if(a->m244==8) {
                    if(i==0) {
f32 y=lbl_80540840*sincosTable___5JMath[0x401]+a->field_0C.y;
f32 x=lbl_80540840*sincosTable___5JMath[0x400]+a->field_0C.x;
pos.y=y;pos.x=x;pos.z=lbl_80540844;
} else {
f32 y=lbl_80540840*sincosTable___5JMath[0xc01]+a->field_0C.y;
f32 x=lbl_80540840*sincosTable___5JMath[0xc00]+a->field_0C.x;
pos.y=y;pos.x=x;pos.z=lbl_80540844;
}
                } else if(a->m244==10) {pos.x=a->field_0C.x;pos.y=a->field_0C.y;pos.z=a->field_0C.z;pos.z=lbl_80540848;}
                else if(a->m244==11||a->m244==13) {f32 radius=lbl_8054084C*(f32)((a->field_90>>8)&15);
if(SpawnRadiusZero(radius))radius=lbl_80540850;
f32 z=lbl_80540864*SpawnRandom()+lbl_80540860;
f32 y=a->field_0C.y+(radius-lbl_8054085C*radius*SpawnRandom());
f32 x=a->field_0C.x+(radius-lbl_8054085C*radius*SpawnRandom());
pos.y=y;pos.z=z;pos.x=x;}
                else {
                    s32 idx=((u16)(i*0x2000)>>5);
                    f32 y=lbl_80540868*sincosTable___5JMath[idx*2+1]+a->field_0C.y;
                    f32 x=lbl_80540868*sincosTable___5JMath[idx*2]+a->field_0C.x;
                    pos.z=lbl_80540844;pos.x=x;pos.y=y;
                }
                s32 room=a->field_04;
if(*(u8*)((u32)fn_802D6A9C()+room+0x131df)) {pos.y=a->field_0C.y;pos.z=lbl_80540854;}
                s32 handle=Actor_CreateByID(fn_801F856C(),id,a->field_04,&pos,param,-1,-1);
                if(handle>=0) {
                    Actor* spawned=fn_801F666C(fn_801F856C(),handle);
                    if(spawned){Vec velocity;velocity.x=lbl_80540854;velocity.y=lbl_80540854;velocity.z=lbl_8054086C;
                    JGeometry::setTVec3f((f32*)&velocity,(f32*)&spawned->field_3C);}
                }
            }
            a->m248=40;a->m230=4;
        }
        break;
    }
    case 1:
        switch(a->m238) {
        case 1:
            if(fn_80138A30(lbl_8053AAF8)==2)a->m240=80;
            if(fn_80138A30(lbl_8053AAF8)>2){a->m240=80;a->m234=2;}break;
        case 2:
            if(fn_80138A30(lbl_8053AAF8)==2)a->m240=240;
            if(fn_80138A30(lbl_8053AAF8)>2){a->m240=240;a->m234=2;}break;
        case 3:
            if(fn_80138A30(lbl_8053AAF8)>1) {
                a->m240=255;
                if(fn_80138A30(lbl_8053AAF8)>2)a->m234=fn_80138A30(lbl_8053AAF8)-1;
            }break;
        }
        a->m230=2;
    case 2: {
        { u8* camera=*(u8**)(lbl_8053AB10+0x24);if(!camera[0x7f4])camera[0x7f5]=1; }
        pos.x=a->field_0C.x;pos.y=a->field_0C.y;pos.z=a->field_0C.z;
        s32 i;
        for(i=0;i<2;i++) {
            s32 room=a->field_04;
            if(*(u8*)((u32)fn_802D6A9C()+room+0x131df)) {
                if(a->m244==6||a->m244==7||a->m244==12){
                    f32 radius=lbl_8054084C*(f32)((a->field_90>>8)&15);
                    if(SpawnRadiusZero(radius))radius=lbl_80540850;
                    pos.x=a->field_0C.x+(radius-lbl_8054085C*radius*SpawnRandom());
                }else pos.x=box[0]+(box[2]-box[0])*SpawnRandom();
                pos.z=lbl_80540854;
            } else if(a->m244==6||a->m244==7||a->m244==12) {f32 radius=lbl_8054084C*(f32)((a->field_90>>8)&15);
if(SpawnRadiusZero(radius))radius=lbl_80540850;
f32 z=lbl_80540864*SpawnRandom()+lbl_80540860;
f32 y=a->field_0C.y+(radius-lbl_8054085C*radius*SpawnRandom());
f32 x=a->field_0C.x+(radius-lbl_8054085C*radius*SpawnRandom());
pos.y=y;pos.z=z;pos.x=x;}
            else {f32 z=lbl_80540864*SpawnRandom()+lbl_80540860;
f32 y=box[1]+(box[3]-box[1])*SpawnRandom();
f32 x=box[0]+(box[2]-box[0])*SpawnRandom();
pos.y=y;pos.z=z;pos.x=x;}
            s32 pick=lbl_80540870*SpawnRandom();
            s32 type;
            if(pick<5)type=2;else if(pick<20)type=1;else type=0;
            fn_801F8544(fn_801F856C(),0x52555059,a->field_04,&pos,type);
            ++a->m23C;
            if((s32)a->m23C>=a->m240)break;
        }
        if((s32)a->m23C>=a->m240) {
            for(s32 j=0;j<(s32)a->m234;j++) {
                pos.x=a->field_0C.x;pos.y=a->field_0C.y;pos.z=a->field_0C.z;
                s32 room=a->field_04;
                if(*(u8*)((u32)fn_802D6A9C()+room+0x131df)) {pos.y=a->field_0C.y;pos.z=lbl_80540854;}
                else if(a->m244==6||a->m244==7||a->m244==12) {f32 radius=lbl_8054084C*(f32)((a->field_90>>8)&15);
if(SpawnRadiusZero(radius))radius=lbl_80540850;
f32 z=lbl_80540864*SpawnRandom()+lbl_80540860;
f32 y=a->field_0C.y+(radius-lbl_8054085C*radius*SpawnRandom());
f32 x=a->field_0C.x+(radius-lbl_8054085C*radius*SpawnRandom());
pos.y=y;pos.z=z;pos.x=x;}
                else {f32 z=lbl_80540864*SpawnRandom()+lbl_80540860;
f32 y=box[1]+(box[3]-box[1])*SpawnRandom();
f32 x=box[0]+(box[2]-box[0])*SpawnRandom();
pos.y=y;pos.z=z;pos.x=x;}
                if(a->m244==7){Actor_CreateByID(fn_801F856C(),0x4c504c4b,a->field_04,&a->field_0C,0x400,-1,-1);break;}
                fn_801F8544(fn_801F856C(),0x52555059,a->field_04,&pos,4);
            }
        }
        break;
    }
    case 3: {
        if(a->m244==1){ u8* camera=*(u8**)(lbl_8053AB10+0x24);if(!camera[0x7f4])camera[0x7f5]=1; }
        f32 z=lbl_80540864*SpawnRandom()+lbl_80540860;
f32 y=box[1]+(box[3]-box[1])*SpawnRandom();
f32 x=box[0]+(box[2]-box[0])*SpawnRandom();
pos.y=y;pos.z=z;pos.x=x;
        s32 room=a->field_04;
if(*(u8*)((u32)fn_802D6A9C()+0x131df+room)) {pos.y=a->field_0C.y;pos.z=lbl_80540854;}
        if((s32)a->m248==0){
            if(a->m244==1){
                s32 handle=Actor_CreateByID(fn_801F856C(),0x48424d42,a->field_04,&pos,3,-1,-1);
                if(handle>=0){
                    Actor* spawned=fn_801F666C(fn_801F856C(),handle);
                    if(spawned){Vec velocity;velocity.x=lbl_80540854;velocity.y=lbl_80540854;velocity.z=lbl_80540858;
                    JGeometry::setTVec3f((f32*)&velocity,(f32*)&spawned->field_3C);}
                }
                a->m248=30;
            }else Actor_CreateByID(fn_801F856C(),0x504f504f,a->field_04,&pos,1,-1,-1);
            ++a->m23C;
        }
        break;
    }
    case 4:
        if(a->m244==11||a->m244==13){ u8* camera=*(u8**)(lbl_8053AB10+0x24);if(!camera[0x7f4])camera[0x7f5]=1; }
        if((s32)a->m248==0)a->detach();
        break;
    }
    if(a->m230!=0) {
        if((s32)a->m248>0)--a->m248;
        if(a->m24C>0)--a->m24C;
        if(a->m230!=4 && (s32)a->m23C>=a->m240){
            fn_802D8050(fn_802D6A9C(),(a->field_90>>22)&31,1,255);
            a->detach();
        }
    }
}
#pragma pop
extern "C" void fn_802A92FC(ActorExt* param_1)
{
    param_1->m248 = 0;
    param_1->m24C = 0;
    param_1->m230 = 0;
    param_1->m23C = 0;
    param_1->m240 = 0;
    param_1->m244 = (u8)param_1->field_90;
    if (param_1->m244 != 3 && param_1->m244 != 0xc && (u8)param_1->v11()) {
        param_1->field_11C = 0;
    }
    param_1->m240 = (param_1->field_90 >> 12) & 0xff;
    if (param_1->m240 == 0) {
        param_1->m240 = 0x100;
    }
    param_1->m234 = 1;
    param_1->m238 = 0;
    switch (param_1->m240) {
    case 0x28:
        param_1->m238 = 1;
        break;
    case 0x78:
        param_1->m238 = 2;
        break;
    case 200:
        param_1->m238 = 3;
        break;
    }
    if (param_1->m244 == 2 || param_1->m244 == 4 || (u32)param_1->m244 <= 1 || (u32)param_1->m244 - 8 <= 3 || param_1->m244 == 0xd) {
        param_1->m24C = 0x28;
    }
}


