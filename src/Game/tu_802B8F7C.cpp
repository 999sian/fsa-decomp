#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JGeometry/Box.h"
#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"


extern "C" void fn_802F601C(void*,void*,s32,s32,f32,f32);
extern "C" s32 fn_8023725C(s32);
extern "C" u8 fn_8023AAF8(s32,void*,s32,void*);
extern "C" u8 fn_8023A5B8(s32);
extern "C" u8 fn_8023A51C(s32);
extern "C" JGeometry::TVec3f* fn_8023A478(s32);
extern "C" s32 fn_801F8544(void*,u32,s32,void*,s32);
extern "C" Actor* fn_801F666C(void*,s32);
extern "C" void fn_8013CC50(s32,void*,s32,s32,s32,s32,s32,s32,f32);
extern "C" char* lbl_8053AAF8;
extern "C" char* lbl_8053AB10;
extern const f32 lbl_80540AF4;
extern const f32 lbl_80540B00;
extern const f32 lbl_80540B04;
extern const f32 lbl_80540B18;
extern const f32 lbl_80540B1C;
extern const f32 lbl_80540B20;
extern const f32 lbl_80540B24;
extern const f32 lbl_80540B28;
static inline void interactionVelocity(JGeometry::TVec3f& v, f32 x, f32 y, f32 z) { v.set(x,y,z); }
static inline f32 interactionRand() { char* manager = lbl_8053AAF8; JMARandFast* random = (JMARandFast*)(manager + 0xb4); return random->get_ufloat_1(); }

extern "C" char lbl_804A88E8[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" const f32 lbl_80540B40;
extern "C" const f32 lbl_80540B10;
extern "C" const f32 lbl_80540AF0;
extern "C" void* fn_802D6A9C(void);
extern "C" void* fn_801F856C(void);
extern "C" s32 Actor_CreateByID(void* mgr, u32 fourCC, u32 owner, void* pos, u32 param, s32 a, s32 b);

struct Unk802B9974Src {
    virtual void m0() = 0;
    virtual void m1() = 0;
    virtual void m2() = 0;
    virtual void m3() = 0;
    virtual void m4() = 0;
    virtual void m5() = 0;
    virtual void m6() = 0;
    virtual void m7() = 0;
    virtual void m8() = 0;
    virtual void m9() = 0;
    virtual void m10() = 0;
    virtual u8 m11() = 0;
};
extern "C" Actor* fn_802B8F7C(Actor* param_1, s16 param_2)
{
    if (param_1 != 0) {
        *(void**)param_1 = lbl_804A88E8;
        __dt__5ActorFv(param_1, 0);
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_802B8FDC(void)
{
    return;
}

#pragma opt_strength_reduction off
extern "C" void fn_802B8FE0(Actor* self) {
    char* p = (char*)self;
    JGeometry::TBox2f bounds;
    JGeometry::TVec3f spawn;
    JGeometry::TVec3f keyVelocity;
    JGeometry::TVec3f heartVelocity;
    JGeometry::TVec3f otherVelocity;
    JGeometry::TVec2f hit;
    switch (*(s32*)(p + 0x230)) {
    case 0: {
        if ((*(f32*)(p+0x244)>0.0f || *(f32*)(p+0x248)>0.0f)) {
            f32 effectY = *(f32*)(p+0x248);
            if (*(s32*)(p+4)<8) {
            fn_802F601C(*(void**)(lbl_8053AB10+0x20),p+0xc,5,0,*(f32*)(p+0x244),effectY);
            }
        }
        if (*(u8*)(p+0x24c)==1) {
            if (*(f32*)(p+0x244)<1.0f) *(f32*)(p+0x244)+=0.1f;
            if (*(f32*)(p+0x248)<1.0f) *(f32*)(p+0x248)+=0.1f;
            if (*(f32*)(p+0x244)>=1.0f && *(f32*)(p+0x248)>=1.0f) *(u8*)(p+0x24c)=0;
        } else {
            if (*(f32*)(p+0x248)>0.0f) {
                *(f32*)(p+0x248)-=0.0025f;
                if (*(f32*)(p+0x248)<=0.0f) *(f32*)(p+0x248)=0.0f;
            }
            if (*(f32*)(p+0x248)<=0.7f && *(f32*)(p+0x244)>0.0f) {
                *(f32*)(p+0x244)-=0.0025f;
                if (*(f32*)(p+0x244)<=0.0f) *(f32*)(p+0x244)=0.0f;
            }
        }
        if (*(s32*)(p+0x240)<=0) {
            for (s32 i=0;i<4;++i) {
                f32 scale=fn_8023725C(i);
                f32 y = *(f32*)(p+0x10);
                f32 x = *(f32*)(p+0xc);
                bounds.set(*(f32*)(p+0x60)*scale,*(f32*)(p+0x64)*scale,*(f32*)(p+0x68)*scale,*(f32*)(p+0x6c)*scale);
                bounds.i.x += x;
                bounds.i.y += y;
                bounds.f.x += x;
                bounds.f.y += y;
                if (fn_8023AAF8(i,&bounds,*(s32*)(p+4),&hit)==1) {
                    *(s32*)(p+0x240)=5;
                    f32 dx=hit.x-*(f32*)(p+0xc);
                    f32 dy=hit.y-*(f32*)(p+0x10);
                    f32 xSquared=dx*dx;
                    f32 ySquared=dy*dy;
                    f32 dist=JGeometry::TUtilf::sqrt(xSquared+ySquared);
                    if ((dist<38.0f && (*(f32*)(p+0x244)>0.0f || *(f32*)(p+0x248)>0.0f)) || (fn_8023A5B8(i)==1 && dist<50.0f*scale)) {
                            if (*(s32*)(p+0x234)>0 && *(s32*)(p+0x234)<=8) {
                                spawn=*(JGeometry::TVec3f*)(p+0xc);
                                if (((s32*)fn_802D6A9C())[1]==2 && ((s32*)fn_802D6A9C())[2]==1) spawn.x-=8.0f;
                                s32 kind=*(s32*)(p+0x234);
                                s32 id;
                                if (kind<5 || kind==8) {
                                    s32 value=3;
                                    if (kind<5) value=kind+3;
                                    id=fn_801F8544(fn_801F856C(),'RUPY',*(s32*)(p+4),&spawn,value);
                                } else if (kind==5 || kind==6) {
                                    id=Actor_CreateByID(fn_801F856C(),'KEY0',*(s32*)(p+4),&spawn,((kind-5)*6)|0x300,-1,-1);
                                } else {
                                    id=Actor_CreateByID(fn_801F856C(),'BHRT',*(s32*)(p+4),&spawn,0,-1,-1);
                                }
                                if (id>=0) {
                                    Actor* item=fn_801F666C(fn_801F856C(),id);
                                    if (item!=0) {
                                        if (item->field_1A0=='KEY0') {
                                            interactionVelocity(keyVelocity,0.35f-0.7f*interactionRand(),0.35f-0.7f*interactionRand(),2.0f*interactionRand()+5.0f);
                                            *(JGeometry::TVec3f*)((char*)item+0x3c)=keyVelocity;
                                        } else if (item->field_1A0=='BHRT') {
                                            s16 angle=65536.0f*interactionRand();
                                            f32 speed=0.35f*interactionRand()+0.15f;
                                            interactionVelocity(heartVelocity,speed*JMASinShort(angle),speed*JMACosShort(angle),2.0f*interactionRand()+5.0f);
                                            *(JGeometry::TVec3f*)((char*)item+0x3c)=heartVelocity;
                                        } else {
                                            interactionVelocity(otherVelocity,0.5f-interactionRand(),0.5f-interactionRand(),2.0f*interactionRand()+5.0f);
                                            *(JGeometry::TVec3f*)((char*)item+0x3c)=otherVelocity;
                                        }
                                        fn_8013CC50(*(s32*)(p+4),p+0xc,0x291,0,0,0,0,1,0.4f);
                                        fn_8013CC50(*(s32*)(p+4),p+0xc,0x5c,0,0,0,0,1,0.5f);
                                    }
                                }
                                if (((s32*)fn_802D6A9C())[1]==2 && ((s32*)fn_802D6A9C())[2]==1) {
                                    spawn.x+=16.0f;
                                    s32 value=0x388;
                                    if (*(s32*)(p+0x234)!=5) value=0x389;
                                    Actor_CreateByID(fn_801F856C(),'JIJI',*(s32*)(p+4),&spawn,(value-0x12b)|0x2110000,-1,-1);
                                }
                            } else {
                                s32 value;
                                if (*(s32*)(p+0x234)==0) value=4;
                                else if (*(s32*)(p+0x234)==9) value=5;
                                Actor_CreateByID(fn_801F856C(),'TKTA',*(s32*)(p+4),p+0xc,value,-1,-1);
                                fn_8013CC50(*(s32*)(p+4),p+0xc,0x240,0,0,0,0,1,1.0f);
                            }
                            if (*(u8*)(p+0x24d)==1) self->detach();
                            else {
                                *(s32*)(p+0x230)=1;
                                self->v10(0xff,1);
                            }
                            return;
                    }
                    if (dist<50.0f*scale) {
                        *(s32*)(p+0x23c)=0;
                        *(u8*)(p+0x24c)=1;
                    }
                }
            }
        }
        for(s32 i=0;i<4;i++) {
            if(fn_8023A51C(i)==1 && fn_8023A5B8(i)==1) {
                JGeometry::TVec3f* player=fn_8023A478(i);
                f32 dx=player->x-*(f32*)(p+0xc);
                f32 dy=player->y-*(f32*)(p+0x10);
                f32 xSquared=dx*dx;
                f32 ySquared=dy*dy;
                f32 distance=JGeometry::TUtilf::sqrt(xSquared+ySquared);
                *(s32*)(p+0x23c)=((s32)distance)>>3;
            }
        }
        if(*(s32*)(p+0x240)>0) {
            --*(s32*)(p+0x240);
            if(*(s32*)(p+0x240)<=0) *(s32*)(p+0x240)=0;
        }
        if(*(s32*)(p+0x23c)>0) {
            --*(s32*)(p+0x23c);
            if(*(s32*)(p+0x23c)<=0) {
                *(s32*)(p+0x23c)=0;
                *(u8*)(p+0x24c)=1;
            }
        }
        break;
    }
    case 1:
    default: break;
    }
}
#pragma opt_strength_reduction reset
#pragma opt_propagation off
extern "C" void fn_802B9974(Unk802B9974Src* this_) {
    char* p = (char*)this_;
    const f32 f0 = lbl_80540AF0;
    const f32 f1 = lbl_80540B10;
    const f32 f2 = lbl_80540B40;
    *(f32*)(p + 0x60) = f2;
    *(f32*)(p + 0x64) = f2;
    *(f32*)(p + 0x68) = f1;
    *(f32*)(p + 0x6c) = f1;
    *(u32*)(p + 0x234) = *(u32*)(p + 0x90) & 0xf;
    *(u32*)(p + 0x238) = (*(u32*)(p + 0x90) >> 4) & 0xffff;
    *(u8*)(p + 0x24d) = (*(u32*)(p + 0x90) >> 20) & 1;
    *(u32*)(p + 0x23c) = 0;
    *(u32*)(p + 0x240) = 0;
    *(f32*)(p + 0x244) = f0;
    *(f32*)(p + 0x248) = f0;
    *(u8*)(p + 0x24c) = 0;
    *(u32*)(p + 0x230) = 0;
    if (this_->m11()) {
        if (*(s32*)(p + 0x234) > 0 && ((s32*)fn_802D6A9C())[1] == 2 && ((s32*)fn_802D6A9C())[2] == 1) {
            u32 id = 0x388;
            if (*(s32*)(p + 0x234) != 5) {
                id = 0x389;
            }
            Actor_CreateByID(fn_801F856C(), 0x4a494a49, *(u32*)(p + 4), p + 0xc, (id - 0x12b) | 0x110000, -1, -1);
        }
        *(u8*)(p + 0x11c) = 0;
    }
}
#pragma opt_propagation reset
extern "C" char lbl_804D2468[];
extern "C" char memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr[];
extern "C" char __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr;
extern "C" char memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack[];
extern "C" char __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack;
extern "C" char memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel[];
extern "C" char __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj3_FSA[];
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj4_FSA[];
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA;
extern "C" char memPool___30JASPoolAllocObject_9JAIStream[];
extern "C" char __init__memPool___30JASPoolAllocObject_9JAIStream;
extern "C" char memPool___35JASPoolAllocObject_13JAISoundChild[];
extern "C" char __init__memPool___35JASPoolAllocObject_13JAISoundChild;
extern "C" char memPool___27JASPoolAllocObject_6JAISeq[];
extern "C" char __init__memPool___27JASPoolAllocObject_6JAISeq;
extern "C" char memPool___26JASPoolAllocObject_5JAISe[];
extern "C" char __init__memPool___26JASPoolAllocObject_5JAISe;
extern "C" void __ct__17JASGenericMemPoolFv(void*);
extern "C" void __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv(void*);
extern "C" void __dt__35JASMemPool_MultiThreaded_8JASTrackFv(void*);
extern "C" void __dt__38JASMemPool_MultiThreaded_10JASChannelFv(void*);
extern "C" void __dt__29JASMemPool_15JASPoolObj3_FSAFv(void*);
extern "C" void __dt__29JASMemPool_15JASPoolObj4_FSAFv(void*);
extern "C" void __dt__22JASMemPool_9JAIStreamFv(void*);
extern "C" void __dt__27JASMemPool_13JAISoundChildFv(void*);
extern "C" void __dt__19JASMemPool_6JAISeqFv(void*);
extern "C" void __dt__18JASMemPool_5JAISeFv(void*);
extern "C" void __register_global_object(void*, void (*)(void*), void*);
extern "C" void fn_802B9A88(void)
{
    u8* base = (u8*)lbl_804D2468;
    if (__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr == 0) {
        __ct__17JASGenericMemPoolFv(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr);
        __register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr, __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, (void*)(base + 0x0));
        __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr = 1;
    }
    if (__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack == 0) {
        __ct__17JASGenericMemPoolFv(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack);
        __register_global_object(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack, __dt__35JASMemPool_MultiThreaded_8JASTrackFv, base + 0xc);
        __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack = 1;
    }
    if (__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel == 0) {
        __ct__17JASGenericMemPoolFv(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel);
        __register_global_object(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel, __dt__38JASMemPool_MultiThreaded_10JASChannelFv, base + 0x18);
        __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA, __dt__29JASMemPool_15JASPoolObj3_FSAFv, base + 0x24);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA, __dt__29JASMemPool_15JASPoolObj4_FSAFv, base + 0x30);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA = 1;
    }
    if (__init__memPool___30JASPoolAllocObject_9JAIStream == 0) {
        __ct__17JASGenericMemPoolFv(memPool___30JASPoolAllocObject_9JAIStream);
        __register_global_object(memPool___30JASPoolAllocObject_9JAIStream, __dt__22JASMemPool_9JAIStreamFv, base + 0x3c);
        __init__memPool___30JASPoolAllocObject_9JAIStream = 1;
    }
    if (__init__memPool___35JASPoolAllocObject_13JAISoundChild == 0) {
        __ct__17JASGenericMemPoolFv(memPool___35JASPoolAllocObject_13JAISoundChild);
        __register_global_object(memPool___35JASPoolAllocObject_13JAISoundChild, __dt__27JASMemPool_13JAISoundChildFv, base + 0x48);
        __init__memPool___35JASPoolAllocObject_13JAISoundChild = 1;
    }
    if (__init__memPool___27JASPoolAllocObject_6JAISeq == 0) {
        __ct__17JASGenericMemPoolFv(memPool___27JASPoolAllocObject_6JAISeq);
        __register_global_object(memPool___27JASPoolAllocObject_6JAISeq, __dt__19JASMemPool_6JAISeqFv, base + 0x54);
        __init__memPool___27JASPoolAllocObject_6JAISeq = 1;
    }
    if (__init__memPool___26JASPoolAllocObject_5JAISe == 0) {
        __ct__17JASGenericMemPoolFv(memPool___26JASPoolAllocObject_5JAISe);
        __register_global_object(memPool___26JASPoolAllocObject_5JAISe, __dt__18JASMemPool_5JAISeFv, base + 0x60);
        __init__memPool___26JASPoolAllocObject_5JAISe = 1;
    }
}

