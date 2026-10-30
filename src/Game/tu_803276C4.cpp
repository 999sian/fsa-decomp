#define GAME_ACTOR_USE_SDK_VEC
#include "JSystem/JGeometry/Vec.h"
#include "Game/Actor.h"
#include "Game/ItemBase.h"
#include "Game/SinitPoolChain.h"
#include "Game/HitRect.h"
#include <string.h>
class Osin : public Actor {
public:
    s32 state, frame, weight, maxWeight, size, timer, group, animTimer, anim;
    u8 players[4];
    u8 complete, moving, hidden, field_25B;
    f32 scale;
    JGeometry::TVec3<f32> origin;
};
#define OSIN_S32(p,o) (*(s32*)((u8*)(p)+(o)))
#define OSIN_F32(p,o) (*(f32*)((u8*)(p)+(o)))
#define OSIN_BYTE(p,o) (*((u8*)(p)+(o)))
static inline s32 osinWeight(const Actor* p) { return OSIN_S32(p,0x238); }

class ResMgr {
public:
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void* vf18(u32 type, const char* name);
};
extern u8* lbl_8053AAF8;
extern u8* lbl_8053AB10;
extern const char* lbl_804AB518[];
extern const char lbl_804718D0[];
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802F86CC(void* a, void* b, void* c, u32 d, void* e, f32 f, f32 g);
extern "C" void fn_802F745C(void* a, void* b, void* c, void* d);
extern "C" void fn_803075AC(void* p, s32 room, void* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);


extern "C" char __vt__4OSIN[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_803276C4(Actor* p, s16 n) {
    if (p) {
        *(void**)p = __vt__4OSIN;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" void fn_80327724(u8* this_) {
    if (*(f32*)(this_ + 0x25c) != 0.0f) {
        if (*(s32*)((u8*)fn_802D6A9C() + 4) != 7 || *(s32*)((u8*)fn_802D6A9C() + 8) != 2) {
            DrawRec rec;
            f32 mtx[3][4];
            PSMTXIdentity(mtx);
            f32 s = (f32)(*(s32*)(this_ + 0x240) + 1) * *(f32*)(this_ + 0x25c);
            mtx[0][1] = 0.0f;
            mtx[0][2] = 0.0f;
            mtx[0][0] = s;
            mtx[1][0] = 0.0f;
            mtx[1][1] = s;
            mtx[1][2] = 0.0f;
            mtx[2][0] = 0.0f;
            mtx[2][1] = 0.0f;
            mtx[2][2] = s;
            rec.w18 = mtx;
            s32 id = *(s32*)(this_ + 0x234) + 0x141;
            if (*(s32*)(this_ + 4) < 8) {
                void* res = (*(ResMgr**)(lbl_8053AAF8 + 0xa4))->vf18('SOB ', lbl_804718D0);
                fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), this_ + 0xc, res, id, &rec, 1.0f, 1.0f);
            }
            fn_803075AC(*(void**)(this_ + 0x198), *(s32*)(this_ + 4), this_ + 0xc, *(s32*)(this_ + 0x234) + 0x141,
                        *(s32*)(this_ + 0x240) != 0, 2, -1, 0, 0, 0);
        } else {
            void* res = (*(ResMgr**)(lbl_8053AAF8 + 0xa4))->vf18(0x54494d47, lbl_804AB518[*(s32*)(this_ + 0x250)]);
            if (*(s32*)(this_ + 4) < 8) {
                fn_802F745C(*(void**)(lbl_8053AB10 + 0x20), this_ + 0xc, res, 0);
            }
        }
    }
}

extern "C" void fn_8013CC50(void* a, void* b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, f32 scale = 1.0f);
extern "C" void fn_801F0E34(void* a, s32 b, s32 c);
extern "C" u8 fn_80230188(s32);
extern "C" JGeometry::TVec3<f32>* fn_8023E724(s32);
extern "C" s32 fn_80230CFC(s32);
extern "C" void fn_80230498(s32,void*,s32,s32,s32,s32,s32);
extern "C" u8 fn_801F6758(f32*,s32,f32);
static inline u8 osinRoomCheck(Actor* actor, const f32 margin) {
    return fn_801F6758(&actor->field_0C.x,actor->field_04,margin);
}
extern "C" u8 fn_801F2618(Actor*,s32,s32);
extern "C" void fn_80239914(void*,s32,s32);
extern "C" u8 fn_8023F264(s32);
extern "C" u8 fn_8023EA28(s32);
extern "C" u8 fn_8023B0F4(s32,void*,s32,s32,f32);
extern "C" s32 fn_8022CAF8(s32);
extern "C" s32 fn_8022E970(s32);
extern "C" u8 fn_8022E438(s32,s32);
extern "C" u8 fn_8023ED8C(s32);
extern "C" u8 fn_8023EBB8(s32);
extern "C" u8 fn_802DCD0C(void*);
extern "C" u8 fn_80233EDC(s32);
extern "C" void fn_80230AD4(s32);
extern "C" void fn_802D9FE8(void*,s32,s32);
extern "C" void fn_80136798(void*,s32,s32);
extern "C" void fn_80230224(s32,s32);
extern "C" void fn_80231368();
extern const f32 lbl_80541C68;
extern const f32 lbl_80541C6C;
extern const f32 lbl_80541C78;
extern const f32 lbl_80541C7C;
extern const f32 lbl_80541C80;
extern const f32 lbl_80541C84;
extern const f32 lbl_80541C88;
extern const f32 lbl_80541C8C;
extern const f32 lbl_80541C90;
extern const f32 lbl_80541C94;
extern const f32 lbl_80541C98;
extern const f32 lbl_80541C9C;
#pragma opt_propagation off
extern "C" void fn_803279D0(Osin* p) {
    s32 area;
    s32 offset;
    if(p->scale<1.0f) {
        if((u8)p->v11()==1 && p->hidden==1) {
            fn_8013CC50((void*)p->field_04,&p->field_0C,0x503,1,0,0,0,1,(f32)(p->size+1));
            fn_801F0E34(p,0x30003,0);
            p->hidden=0;
        }
        if(p->hidden==0) {
            p->scale+=0.1f;
            if(p->scale>=1.0f) p->scale=1.0f;
        }
        return;
    }
    s32 blocked = 0;
    HitBox box;
    JGeometry::TVec2<f32> xy;
    xy.set(p->field_0C.x,p->field_0C.y);
    box.set(*(HitBox*)&p->field_60);
    box.addPos(xy);
    HitBox inset;
    inset = box;
    inset.i.x+=4.0f;
    inset.i.y-=2.0f;
    inset.f.x-=4.0f;
    *(JGeometry::TVec3<f32>*)&p->field_0C+=*(JGeometry::TVec3<f32>*)&p->field_3C;
    if(p->field_94==2 || p->field_94==3) {
        for(s32 i=3;i>=0;i--) {
            if(fn_80230188(i) && p->moving==1) {
                JGeometry::TVec3<f32> pos(*fn_8023E724(i));
                pos+=*(JGeometry::TVec3<f32>*)&p->field_3C;
                fn_80230498(i,&pos,fn_80230CFC(i)+60,0xff,-128,-128,1);
            }
        }
    }
    f32 margin=-40.0f;
    f32* pos=&p->field_0C.x;
    s32 room=p->field_04;
    if(!fn_801F6758(pos,room,margin)) blocked=fn_801F2618(p,0,0);
    p->weight=0;
    fn_80239914(&box,p->field_04,p->field_198);
    switch(p->field_94) {
    case 0: case 1:
        p->players[0]=0;
        p->players[1]=0;
        p->players[2]=0;
        p->players[3]=0;
        for(s32 i=0;i<4;i++) {
            if(fn_8023F264(i) && !fn_8023EA28(i) && (offset=i+0x254, OSIN_BYTE(p,offset)==0)) {
                OSIN_BYTE(p,offset)=fn_8023B0F4(i,&inset,p->field_04,0,0.0f);
                if(OSIN_BYTE(p,offset)!=0 && fn_8023E724(i)->y<p->field_0C.y) {
                    if(fn_8022CAF8(i)==4) p->weight++;
                    else p->weight+=fn_8022E970(i);
                    for(s32 j=0;j<4;j++) {
                        if(p->players[j]==0 && fn_8022CAF8(j)!=4 && i!=j && fn_8022E438(i,j)==1) p->players[j]=1;
                    }
                }
            }
        }
        for(s32 i=0;i<4;i++) {
            if(p->players[i]==1 && (fn_8023ED8C(i)||fn_8023EBB8(i))) p->weight++;
        }
        if(p->complete==1) return;
        if(p->maxWeight!=0 && p->weight<p->maxWeight) p->weight=p->maxWeight;
        s32 weight=p->weight;
        if(weight>1) {
            if(!blocked && 48.0f*(f32)(weight-1)+p->origin.y>p->field_0C.y) {
                p->field_3C.y=0.5f;
                OSIN_S32(p,0x234)=1;
                if(p->field_94!=0) {
                    s32 current=osinWeight(p);
                    if(current>=p->maxWeight) p->maxWeight=current;
                }
            } else if(!blocked && 48.0f*(f32)(weight-1)+p->origin.y<p->field_0C.y) {
                p->field_3C.y=-0.5f;
                p->frame=0;
            } else {
                p->field_3C.y=0.0f; p->frame=0;
            }
        } else if(weight<=1 && p->origin.y<p->field_0C.y) {
            p->field_3C.y=-0.5f; p->frame=0;
        } else {p->field_3C.y=0.0f;p->frame=0;}
        if(p->field_94!=0 && p->weight>=4) {
            if(48.0f*(f32)(p->weight-1)+p->origin.y<=p->field_0C.y || blocked) {
                p->complete=1;
                p->field_3C.y=0.0f;
                if(!blocked) p->frame=0;
                else p->frame=1;
            }
        }
        break;
    case 2: case 3:
        switch(p->state) {
        case 0:
            if(!fn_802DCD0C(fn_802D6A9C())) {
                for(s32 i=0;i<4;i++) {
                    if(fn_80233EDC(i)==1) break;
                    if(fn_8023F264(i) && !fn_8023EA28(i)) {
                        p->players[i]=fn_8023B0F4(i,&inset,p->field_04,0,0.0f);
                        if(p->players[i]!=0 && fn_8023E724(i)->y<=box.i.y) {
                            p->weight++;
                            if(fn_8023ED8C(i)) p->weight++;
                        }
                    }
                }
            }
            if(p->weight<4) break;
            for(s32 i=0;i<4;i++) fn_80230AD4(i);
            p->state=1;
            p->moving=1;
            p->field_3C.y=0.5f;
            break;
        case 1:
            if(p->field_0C.y-p->origin.y>=8.0f) {
                if(p->field_94==2) p->field_3C.x=1.0f;
                else if(p->field_94==3) p->field_3C.x=-1.0f;
                p->field_3C.y=0.0f;
                p->state=2;
                p->timer=240;
            }
            break;
        case 2:
            p->timer--;
            if(p->field_94==2) {
                void* bounds=fn_802D6A9C();
                if(p->field_0C.x-OSIN_F32(bounds,0xd4)>40.0f) {
                    area = OSIN_S32(fn_802D6A9C(),0x18);
                    void* mgr = fn_802D6A9C();
                    fn_802D9FE8(fn_802D6A9C(),OSIN_S32(mgr,0x14)+1,area);
                    fn_80136798(lbl_8053AAF8,17,0);
                }
            } else if(p->field_94==3) {
                void* bounds=fn_802D6A9C();
                if(p->field_0C.x-OSIN_F32(bounds,0xcc)<-40.0f) {
                    area=OSIN_S32(fn_802D6A9C(),0x18);
                    void* mgr=fn_802D6A9C();
                    fn_802D9FE8(fn_802D6A9C(),OSIN_S32(mgr,0x14)-1,area);
                    fn_80136798(lbl_8053AAF8,17,0);
                }
            }
            if(blocked || p->timer==0) {
                JGeometry::setTVec3f(&p->field_0C.x,&p->origin.x);
                p->field_3C.x=0.0f;
                p->field_3C.y=-0.5f;
                p->state=3;
            }
            break;
        case 3:
            if(p->origin.y-p->field_0C.y>=8.0f) {
                JGeometry::setTVec3f(&p->field_0C.x,&p->origin.x);
                p->field_3C.z=0.0f;
                p->field_3C.y=0.0f;
                p->field_3C.x=0.0f;
                for(s32 i=0;i<4;i++) fn_80230224(i,0);
                fn_80231368();
                if(p->field_94==2) p->field_94=3;
                else if(p->field_94==3) p->field_94=2;
                p->state=4;
            }
            break;
        case 4:
            for(s32 i=0;i<4;i++) {
                if(fn_8023F264(i) && !fn_8023EA28(i)) {
                    p->players[i]=fn_8023B0F4(i,&inset,p->field_04,0,0.0f);
                    if(p->players[i]!=0 && fn_8023E724(i)->y<=box.i.y) {
                        p->weight++;
                        if(fn_8023ED8C(i)) p->weight++;
                    }
                }
            }
            if(p->moving==1 && p->weight>0) p->moving=0;
            else if(p->moving==0 && p->weight<=0) p->state=0;
            break;
        }
        break;
    }
    p->animTimer--;
    if(p->animTimer<=0) {
        p->animTimer=10;
        p->anim++;
        p->anim&=3;
    }
}
#pragma opt_propagation reset
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* mgr, s32 idx);
extern "C" s32 fn_801F78F4(void* mgr, u32 code, s32 idx);
extern "C" u8 fn_801F6758(f32* pos, s32 room, f32 r);
extern "C" void fn_803283FC(u8* this_) {
    s32 idx = -1;
    u8* p = 0;
    *(u16*)(this_ + 0x94) = *(u32*)(this_ + 0x90) & 0xf;
    *(s32*)(this_ + 0x240) = (*(u32*)(this_ + 0x90) >> 4) & 0xf;
    *(s32*)(this_ + 0x248) = (*(u32*)(this_ + 0x90) >> 8) & 0xf;
    *(u8*)(this_ + 0x25a) = (*(u32*)(this_ + 0x90) >> 12) & 1;
    for (;;) {
        idx = fn_801F78F4(fn_801F856C(), 0x4f53494e, idx);
        if (idx < 0) {
            break;
        }
        if (idx == *(s32*)(this_ + 0x198)) {
            continue;
        }
        p = (u8*)fn_801F666C(fn_801F856C(), idx);
        if (p == 0) {
            continue;
        }
        if (*(s32*)(p + 0x248) != *(s32*)(this_ + 0x248)) {
            continue;
        }
        if (fn_801F6758((f32*)(p + 0xc), *(s32*)(p + 0x4), 0.0f) != 0) {
            continue;
        }
        break;
    }
    *(u8*)(this_ + 0x11c) = 0;
    *(s32*)(this_ + 0x108) = 10000;
    *(f32*)(this_ + 0x10) -= 8.0f;
    *(JGeometry::TVec3<f32>*)(this_ + 0x260) = *(JGeometry::TVec3<f32>*)(this_ + 0xc);
    *(s32*)(this_ + 0x230) = 0;
    *(s32*)(this_ + 0x234) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(f32*)(this_ + 0x25c) = 1.0f;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x24c) = 10;
    *(s32*)(this_ + 0x250) = 0;
    *(u8*)(this_ + 0x258) = 0;
    *(u8*)(this_ + 0x259) = 0;
    *(u8*)(this_ + 0x254) = 0;
    *(u8*)(this_ + 0x255) = 0;
    *(u8*)(this_ + 0x256) = 0;
    *(u8*)(this_ + 0x257) = 0;
    if (*(u8*)(this_ + 0x25a) == 1) {
        *(f32*)(this_ + 0x25c) = 0.0f;
        if (*(s32*)(this_ + 0x240) == 0) {
            *(f32*)(this_ + 0x80) = -15.0f;
            *(f32*)(this_ + 0x84) = -7.0f;
            *(f32*)(this_ + 0x88) = 15.0f;
            *(f32*)(this_ + 0x8c) = 7.0f;
            *(f32*)(this_ + 0x60) = -15.0f;
            *(f32*)(this_ + 0x64) = -7.0f;
            *(f32*)(this_ + 0x68) = 15.0f;
            *(f32*)(this_ + 0x6c) = 7.0f;
        } else if (*(s32*)(this_ + 0x240) == 1) {
            *(f32*)(this_ + 0x80) = -31.0f;
            *(f32*)(this_ + 0x84) = -15.0f;
            *(f32*)(this_ + 0x88) = 31.0f;
            *(f32*)(this_ + 0x8c) = 15.0f;
            *(f32*)(this_ + 0x60) = -31.0f;
            *(f32*)(this_ + 0x64) = -15.0f;
            *(f32*)(this_ + 0x68) = 31.0f;
            *(f32*)(this_ + 0x6c) = 15.0f;
        }
    }
}

extern "C" void fn_803285CC(void) {
}

