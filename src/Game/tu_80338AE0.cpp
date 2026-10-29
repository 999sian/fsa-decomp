#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JParticle/JPAEmitter.h"
#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
struct WarpActor : Actor {
    s32 state, count, destination, destinationParam, timer, fadeTimer;
    s32 rank[4];
    f32 maxHeight;
    u8 inside[4], linked[4];
    JPABaseEmitter* emitterA;
    JPABaseEmitter* emitterB;
    JPABaseEmitter* emitters[4];
};
#define S32(p,o) (*(s32*)((u8*)(p)+(o)))
#define U8(p,o) (*(u8*)((u8*)(p)+(o)))
#define F32(p,o) (*(f32*)((u8*)(p)+(o)))
#define V3(p,o) (*(JGeometry::TVec3<f32>*)((u8*)(p)+(o)))
#define EMIT(p,o) (*(JPABaseEmitter**)((u8*)(p)+(o)))
extern "C" u8* lbl_8053AB10;
extern "C" void* lbl_8053AAF8;
extern "C" const u16 lbl_805420A0[4];
extern "C" u8 fn_8023F264(s32);
extern "C" u8 fn_8023EA28(s32);
extern "C" u8 fn_8023561C(s32);
extern "C" u8 fn_80236B50(s32);
extern "C" u8 fn_8023077C();
extern "C" s32 fn_8022E970(s32);
extern "C" u8 fn_80234A88(s32);
extern "C" void fn_8022CA6C(s32,s32,s32);
extern "C" u8 fn_8022F514(s32);
extern "C" s32 fn_8022F3DC(s32);
extern "C" s32 fn_8022E8D4(s32);
extern "C" void fn_80230498(s32,void*,s32,u8,s8,s8,s32);
extern "C" void fn_801F71A4(void*,f32,f32,f32);
extern "C" void* fn_802D6A9C();
extern "C" void fn_802D9FF4(void*,s32,s32);
extern "C" void fn_80136798(void*,s32,s32);
extern "C" u32 fn_8013CC50(u32, void*, s32, s32, s32, s32, s32, s32, f32);
inline void stopWarpEmitter(JPABaseEmitter*& e) {
    if (e != 0) { e->becomeInvalidEmitter(); e = 0; }
}


extern void* lbl_804AC0A8[];
extern "C" void fn_801EE434(void* obj);
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* p);
extern "C" void fn_80338AE0(void) {
}

extern "C" void fn_801F0E34(void* obj, u32 a, u32 b);
extern "C" u8 fn_80230188(s32 i);
extern "C" void* fn_8023E724(s32 i);
inline void sortWarpPlayers(s32 (&order)[5]) {
    int n;
    s32* start;
    s32* cur;
    s32 i;
    start = &order[1];
    for(n=4;n>0;n--) {
        cur=start;
        for(i=1;i<n;i++) {
            JGeometry::TVec3<f32> a(*(JGeometry::TVec3<f32>*)fn_8023E724(cur[-1]));
            JGeometry::TVec3<f32> b(*(JGeometry::TVec3<f32>*)fn_8023E724(cur[0]));
            if(a.x>b.x) {
                s32 prev=i-1;
                order[4]=order[prev]; order[prev]=cur[0]; cur[0]=order[4];
            }
            cur++;
        }
    }
}

extern "C" void fn_80338AE4(WarpActor* p) {
    s32 order[5];
    JGeometry::TVec3<f32> firstPos, activatePos, movePos, otherPos, emitterPos;
    WarpActor* actor = p;
    f32 left,bottom,right,top;
    f32 xOrigin;
    f32 yOrigin = F32(actor,0x10);
    bottom = F32(actor,0x64);
    top = F32(actor,0x6c);
    xOrigin = F32(actor,0xc);
    bottom += yOrigin;
    left = F32(actor,0x60);
    top += yOrigin;
    right = F32(actor,0x68);
    left += xOrigin;
    right += xOrigin;
    fn_801F0E34(actor,0x5003b,0);
    u8* settings = *(u8**)(lbl_8053AB10+0x2c);
    if (settings[0xc] > 0x80) {
        u32 alpha = settings[0xc]-1;
        if((u8)alpha <= 0x80) alpha=0x80;
        settings[0xc]=alpha;
    }
    for(s32 j=0;j<4;j++) {
        if(fn_80230188(j) && (S32(actor,0x230)==2 || S32(actor,0x230)==3)) {
            firstPos = *(JGeometry::TVec3<f32>*)fn_8023E724(j);
            if(S32(actor,0x230)!=1) {
                firstPos += V3(actor,0x3c);
                fn_801F71A4(&firstPos,16.0f*(f32)actor->rank[j]+(F32(actor,0xc)-24.0f),0.02f,10.0f);
            }
            if(S32(actor,0x230)==3)
                fn_80230498(j,&firstPos,0x3cf,(u8)(S32(actor,0x244)*255/50),-128,-128,1);
            else fn_80230498(j,&firstPos,0x3cf,255,-128,-128,1);
        }
    }
    if(S32(actor,0x230)!=0 && S32(actor,0x230)!=1) F32(actor,0x40) -= 0.05f;
    S32(actor,0x234)=0;
    switch(S32(actor,0x230)) {
    case 0:
        for(s32 i=0;i<4;i++) {
            if(fn_8023F264(i) && !fn_8023EA28(i) && fn_8023561C(i) && !fn_80236B50(i)) {
                JGeometry::TVec3<f32>* pos=(JGeometry::TVec3<f32>*)fn_8023E724(i);
                actor->inside[i] = pos->x >= left && pos->y >= bottom && pos->x < right && pos->y < top;
                if(actor->inside[i]) {
                    S32(actor,0x234)++;
                    if(actor->emitters[i]==0) {
                        emitterPos.set(F32(actor,0xc),16.0f+F32(actor,0x10),F32(actor,0x14));
                        actor->emitters[i]=(JPABaseEmitter*)fn_8013CC50(S32(actor,4),&emitterPos,lbl_805420A0[i],1,2,0,0,1,1.0f);
                    }
                } else stopWarpEmitter(actor->emitters[i]);
            }
        }
        if(S32(actor,0x234)>=4 && fn_8023077C()) {
            for(s32 i=0;i<4;i++) {
                activatePos = *(JGeometry::TVec3<f32>*)fn_8023E724(i);
                if(fn_8022E970(i)>1 && fn_80234A88(i)) {
                    fn_8022CA6C(i,5,1);
                    actor->linked[i]=1;
                }
                fn_80230498(i,&activatePos,0x3cd,255,-128,-128,1);
            }
            S32(actor,0x240)=50;
            S32(actor,0x230)=1;
        }
        break;
    case 1:
        S32(actor,0x240)--;
        if(S32(actor,0x240)<=0) {
            for(s32 i=0;i<4;i++) {
                if(F32(actor,0x258) < ((JGeometry::TVec3<f32>*)fn_8023E724(i))->y)
                    F32(actor,0x258)=((JGeometry::TVec3<f32>*)fn_8023E724(i))->y;
            }
            order[0]=0;order[1]=1;order[2]=2;order[3]=3;
            sortWarpPlayers(order);
            actor->rank[order[0]]=0;
            actor->rank[order[1]]=1;
            actor->rank[order[2]]=2;
            actor->rank[order[3]]=3;
            F32(actor,0x40)=-0.5f;
            S32(actor,0x230)=2;
        } else {
            for(s32 i=0;i<4;i++) {
                s32 owner;
                if(fn_8022F514(i)==0) owner=i; else owner=fn_8022F3DC(i);
                movePos = *(JGeometry::TVec3<f32>*)fn_8023E724(i);
                if(actor->linked[owner]) {
                    otherPos = *(JGeometry::TVec3<f32>*)fn_8023E724(owner);
                    s32 n=fn_8022E8D4(i);
                    f32 dx=movePos.x-otherPos.x;
                    if(dx<16.0f*(f32)n && dx > -16.0f*(f32)n) {
                        if(otherPos.x>F32(actor,0xc)) movePos.x -= (f32)n;
                        else movePos.x += (f32)n;
                    }
                }
                s32 effect=0x3cd;
                if(S32(actor,0x240)<=46) effect=0x3ce;
                fn_80230498(i,&movePos,effect,255,-128,-128,1);
            }
        }
        break;
    case 2: {
        fn_801F0E34(actor,0x5003a,0);
        f32 maxY=0.0f;
        for(s32 i=0;i<4;i++) {
            if(maxY<((JGeometry::TVec3<f32>*)fn_8023E724(i))->y)
                maxY=((JGeometry::TVec3<f32>*)fn_8023E724(i))->y;
        }
        if(F32(actor,0x258)-maxY>30.0f) {S32(actor,0x244)=50;S32(actor,0x230)=3;}
        break;
    }
    case 3:
        fn_801F0E34(actor,0x5003a,0);
        S32(actor,0x244)--;
        if(S32(actor,0x244)<=0) {
            fn_802D9FF4(fn_802D6A9C(),S32(actor,0x238),S32(actor,0x23c));
            fn_80136798(lbl_8053AAF8,15,0);
            stopWarpEmitter(EMIT(actor,0x264));
            stopWarpEmitter(EMIT(actor,0x268));
            for(s32 i=0;i<4;i++) stopWarpEmitter(actor->emitters[i]);
            U8(actor,0x11c)=0;
        }
        break;
    }
}

extern "C" u32 fn_8013CC50(u32 a, void* pos, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g, f32 h);
extern "C" u32 fn_8013CC50(u32, void*, s32, s32, s32, s32, s32, s32, f32);
extern "C" void fn_80339374(u8* p) {
    *(u16*)(p + 0x94) = *(u32*)(p + 0x90) & 0xf;
    *(u32*)(p + 0x108) = 10000;
    *(u32*)(p + 0x230) = 0;
    *(u32*)(p + 0x234) = 0;
    *(u32*)(p + 0x240) = 0;
    *(u32*)(p + 0x244) = 0;
    *(u32*)(p + 0x238) = (*(u32*)(p + 0x90) >> 4) & 0xf;
    *(u32*)(p + 0x23c) = (*(u32*)(p + 0x90) >> 8) & 0xf;
    *(f32*)(p + 0x258) = 0.0f;
    *(u32*)(p + 0x264) = 0;
    *(u32*)(p + 0x268) = 0;
    *(u8*)(p + 0x25c) = 0;
    *(u32*)(p + 0x26c) = 0;
    *(u32*)(p + 0x248) = 0;
    *(u8*)(p + 0x260) = 0;
    *(u8*)(p + 0x25d) = 0;
    *(u32*)(p + 0x270) = 0;
    *(u32*)(p + 0x24c) = 0;
    *(u8*)(p + 0x261) = 0;
    *(u8*)(p + 0x25e) = 0;
    *(u32*)(p + 0x274) = 0;
    *(u32*)(p + 0x250) = 0;
    *(u8*)(p + 0x262) = 0;
    *(u8*)(p + 0x25f) = 0;
    *(u32*)(p + 0x278) = 0;
    *(u32*)(p + 0x254) = 0;
    *(u8*)(p + 0x263) = 0;

    if (*(u32*)(p + 0x264) == 0) {
        f32 pos[3];
        f32 z = *(f32*)(p + 0x14);
        f32 y = 16.0f + *(f32*)(p + 0x10);
        f32 x = *(f32*)(p + 0xc);
        pos[0] = x;
        pos[1] = y;
        pos[2] = z;
        *(u32*)(p + 0x264) = fn_8013CC50(*(u32*)(p + 4), pos, 0x4e0, 1, 2, 0, 0, 1, 1.0f);
    }
    if (*(u32*)(p + 0x268) == 0) {
        f32 pos[3];
        f32 z = *(f32*)(p + 0x14);
        f32 y = 16.0f + *(f32*)(p + 0x10);
        f32 x = *(f32*)(p + 0xc);
        pos[0] = x;
        pos[1] = y;
        pos[2] = z;
        *(u32*)(p + 0x268) = fn_8013CC50(*(u32*)(p + 4), pos, 0x4e1, 1, 2, 0, 0, 1, 1.0f);
    }
    *(f32*)(p + 0x60) = -47.0f;
    *(f32*)(p + 0x64) = -47.0f;
    *(f32*)(p + 0x68) = 47.0f;
    *(f32*)(p + 0x6c) = 15.0f;
}

extern "C" void* fn_803394F8(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AC0A8;
        fn_801EE434(*(void**)((char*)this_ + 0x264));
        fn_801EE434(*(void**)((char*)this_ + 0x268));
        char* p;
        s32 i;
        for (i = 0, p = (char*)this_; i < 4; i++) {
            fn_801EE434(*(void**)(p + 0x26c));
            p += 4;
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}
#include "JSystem/JAudio/JASFakeMatchFSA.h"
