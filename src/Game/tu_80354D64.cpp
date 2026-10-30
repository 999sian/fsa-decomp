#include "Game/ItemBase.h"
#include "JSystem/JMath/Inline.h"
#include "JSystem/JMath/JMath.h"
#include "JSystem/JAudio/JASFakeMatchFSA.h"
#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JGeometry/Box.h"
#undef GAME_ACTOR_USE_SDK_VEC
extern const f32 lbl_80542790;
extern const f32 lbl_80542798;
extern const f32 lbl_80542794;
extern "C" s32 fn_80239470(void*,s32,s32);
extern "C" s32 fn_80238A68(s32);
extern "C" s32 fn_8023885C(s32);
extern "C" s32 fn_80239108(s32);
extern "C" s32 fn_80238BC4(s32);
extern "C" void fn_80238E08(s32);
extern "C" char lbl_804722B0[];
extern "C" char lbl_804722D0[];
extern const JGeometry::TVec3f lbl_80472320[];

struct MrtaResMgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* getRes(u32 type, const char* name);
};


extern "C" char __vt__4MRTA[];
extern "C" void fn_801EE434(void* p);
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" void* fn_8013CC50(u32, void*, u16, s32, f32, s32, s32, s32, s32);
extern "C" void fn_801F0E34(void*, u32, u32);
extern "C" void detach__5ActorFv(void*);
extern "C" u16 fn_8022461C(f32* pos);
extern "C" s32 v17__5ActorFiPf(void* this_, s32 room, f32* pos);
extern "C" s32 fn_801F132C(void* this_, s32 a, s32 b, void* state);
extern "C" u8 fn_801F2618(Actor* a, f32* out, u32 c);
extern "C" u8 fn_8023B0F4(s32 idx, void* box, s32 a2, s32 a3, f32 f);
extern "C" void* fn_8023E724(s32 i);
extern "C" const Vec lbl_804722F0[];
#pragma opt_propagation off
extern "C" s32 fn_80354D64(Actor* this_, u8 arg2) {
    JGeometry::TVec3f saved;
    JGeometry::TVec3f out;
    JGeometry::TBox2f box;
    JGeometry::TVec3f pos;
    JGeometry::TVec3f offset;
    s32 hit = 0;
    s32 i;
    saved = *(JGeometry::TVec3f*)&this_->field_0C;
    this_->field_3C = lbl_804722F0[arg2];
    *(JGeometry::TVec3f*)&this_->field_0C += *(JGeometry::TVec3f*)&this_->field_3C;
    out.x = 0.0f;
    out.y = 0.0f;
    out.z = 0.0f;
    if (fn_801F2618(this_, &out.x, 0)) {
        switch (arg2) {
        case 0: if (out.x >= 0.0f) hit = true; break;
        case 1: if (out.x <= 0.0f) hit = true; break;
        case 2: if (out.y >= 0.0f) hit = true; break;
        case 3: if (out.y <= 0.0f) hit = true; break;
        }
    } else {
        hit = true;
    }
    if (!(u8)hit) {
        box.set(*(JGeometry::TBox2f*)&this_->field_60);
        box.addPos(*(JGeometry::TVec2f*)&this_->field_0C);
        hit = true;
        for (i = 0; i < 4; i++) {
            if (fn_8023B0F4(i, &box, this_->field_04, 0, 0.0f)) {
                pos = *(JGeometry::TVec3f*)fn_8023E724(i);
                offset.set(lbl_80472320[arg2]);
                pos += offset;
                if ((u8)this_->v17(this_->field_04, &pos.x) == 1) {
                    hit = false;
                }
            }
        }
    }
    *(JGeometry::TVec3f*)&this_->field_0C = saved;
    this_->field_3C.x = 0.0f;
    this_->field_3C.y = 0.0f;
    this_->field_3C.z = 0.0f;
    return hit;
}

#pragma opt_common_subs off
extern "C" void fn_80354FE8(void* this_) {
    JGeometry::TVec3f saved;
    JGeometry::TVec3f offset;
    JGeometry::TBox2f box;
    u16 effect;
    u8* p=(u8*)this_;
    const char* __restrict steps;
    s32 first;
    s32 second;
    s32 index;
    const f32* __restrict step;
    s32 chosen;
    s32 direction;
    if(((JGeometry::TVec3f*)(p+0x2d4))->squared()<=lbl_80542794 * FLT_EPSILON) {
    if(p[0x2cc]==1) { p[0x2cc]=0; return; }
    box.set(*(JGeometry::TBox2f*)(p+0x80));
    box.addPos(*(JGeometry::TVec2f*)(p+0xc));
    s32 d;
    if(fn_80239470(&box,*(s32*)(p+4),*(s32*)(p+0x198))>=0 &&
       fn_80238A68(*(s32*)(p+0x198))>=4 &&
       (d=fn_8023885C(*(s32*)(p+0x198)))>=0 && d<4) {
            if(d==0) d=1;
            else if(d==1) d=0;
            else if(d==2) d=3;
            else if(d==3) d=2;
            first=d;
    } else first=-1;
    if(fn_80239108(*(s32*)(p+0x198))>=4 &&
       (d=fn_80238BC4(*(s32*)(p+0x198)))>=0 && d<4) second=d;
    else second=-1;
    if(first!=-1) chosen=first;
    else if(second!=-1) chosen=second;
    else return;
    steps=lbl_804722B0;
    index=chosen*8;
    step=(const f32*)(steps+index);
    saved=*(JGeometry::TVec3f*)(p+0xc);
    offset.set(*(const f32*)(steps+index),*++step,lbl_80542790);
    *(JGeometry::TVec3f*)(p+0xc)+=offset;
    u8 hit=fn_801F2618((Actor*)p,0,0);
    *(JGeometry::TVec3f*)(p+0xc)=saved;
    if(hit==1) return;
    if(!(u8)fn_80354D64((Actor*)p,(u8)chosen)) return;
    if(first==-1 && second!=-1) fn_80238E08(*(s32*)(p+0x198));
    *(f32*)(p+0x44)=lbl_80542790;
    *(f32*)(p+0x40)=lbl_80542790;
    *(f32*)(p+0x3c)=lbl_80542790;
    const char* __restrict velocities=lbl_804722D0;
    const f32* v=(const f32*)(velocities+index);
    ((JGeometry::TVec2f*)(p+0x3c))->set(*(const f32*)(velocities+index),v[1]);
    *(f32*)(p+0x44)=lbl_80542790;
    fn_801F0E34(p,0x30004,0);
    ((JGeometry::TVec3f*)(p+0x2d4))->x=*(const f32*)(steps+index);
    ((JGeometry::TVec3f*)(p+0x2d4))->y=*step;
    ((JGeometry::TVec3f*)(p+0x2d4))->z=lbl_80542790;
    if(*(s32*)(p+0x2c8)==0) {
        switch(*(s32*)(p+0x2c0)) {
        case 0:
            switch(*(s32*)(p+0x2c4)) {case 0: effect=0x327;break;case 1: effect=0x325;break;}
            break;
        case 1:
            switch(*(s32*)(p+0x2c4)) {case 0: effect=0x328;break;case 1: effect=0x326;break;}
            break;
        }
        if(*(void**)(p+0x2e0)==0)
            *(void**)(p+0x2e0)=fn_8013CC50(*(u32*)(p+4),p+0xc,effect,0,lbl_80542798,-2,0,0,1);
    }
    }
}

#pragma opt_propagation reset
extern "C" s32 fn_8035533C(void* this_, s32 param2, f32* param3) {
    u8* p = (u8*)this_;
    if (*(s32*)(p + 0x230) == 0) {
        s32 kind = fn_8022461C(param3);
        if (kind == 0x27 || kind == 3) {
            return 0;
        }
        if (kind == 4 || kind == 0x28 || kind == 0x2c) {
            if (((s32)param3[1] & 0xf) >= 8) {
                return 0;
            }
        } else if (kind == 5 || kind == 0x29 || kind == 0x2d) {
            if (((s32)param3[1] & 0xf) < 8) {
                return 0;
            }
        } else if (kind == 6 || kind == 0x2a || kind == 0x2e) {
            if (((s32)param3[0] & 0xf) >= 8) {
                return 0;
            }
        } else if (kind == 7 || kind == 0x2b || kind == 0x2f) {
            if (((s32)param3[0] & 0xf) < 8) {
                return 0;
            }
        }
        return v17__5ActorFiPf(this_, param2, param3);
    }
    return fn_801F132C(this_, param2, (s32)param3, p + 0x2b8);
}

extern "C" void fn_803554B8(void* this_)
{
    u8* p = (u8*)this_;
    u16 id0;
    u16 id1;
    u16 id2;

    switch (*(s32*)(p + 0x2c0)) {
    case 0:
        switch (*(s32*)(p + 0x2c4)) {
        case 0:
            id0 = 0xa1;
            id1 = 0xa2;
            id2 = 0xa3;
            break;
        case 1:
            id0 = 0x9b;
            id1 = 0x9c;
            id2 = 0x9d;
            break;
        }
        break;
    case 1:
        switch (*(s32*)(p + 0x2c4)) {
        case 0:
            id0 = 0xa4;
            id1 = 0xa5;
            id2 = 0xa6;
            break;
        case 1:
            id0 = 0x9e;
            id1 = 0x9f;
            id2 = 0xa0;
            break;
        }
        break;
    }
    fn_8013CC50(*(u32*)(p + 4), p + 0xc, id0, 1, 1.0f, 0, 0, 0, 1);
    fn_8013CC50(*(u32*)(p + 4), p + 0xc, id1, 1, 1.0f, 0, 0, 0, 1);
    fn_8013CC50(*(u32*)(p + 4), p + 0xc, id2, 1, 1.0f, 0, 0, 0, 1);
    fn_801F0E34(this_, 0x30003, 0);
    detach__5ActorFv(this_);
}

extern u8* lbl_8053AAF8;
extern "C" char lbl_804722B0[];
extern "C" u8 fn_8023CB24(s32);
extern "C" u8 fn_8023CA88(s32);
extern "C" void fn_801EFD34(void* this_, void* res, void* rec, s32 a, f32 x, f32 y, f32 z);
extern "C" void fn_801F06F0(void* this_, const char* name, s32 id, void* rec, s32 a, f32 sx, f32 sy);
extern "C" void fn_80355610(char* this_) {
    char* tbl = lbl_804722B0;
    DrawRec rec;
    f32 mtx[3][4];
    JGeometry::TVec3f saved;
    const char* name;

    switch (*(s32*)(this_ + 0x2c8)) {
    case 0:
        rec.b1d = -1;
        rec.b1c = 0;
        switch (*(s32*)(this_ + 0x2c4)) {
        case 0:
            name = tbl + 0xa0;
            break;
        case 1:
            name = tbl + 0xb4;
            break;
        }
        if (*(u8*)(this_ + 0xc4) == 1) {
            rec.b20 = 0;
            rec.b1d = fn_8023CB24(*(s32*)(this_ + 0xc8)) + 1;
            rec.b1c = fn_8023CA88(*(s32*)(this_ + 0xc8));
        }
        PSMTXIdentity(mtx);
        if (*(s32*)(this_ + 0x2c0) == 1) {
            f32 c = JMASCos(0x4000);
            f32 s = JMASSin(0x4000);
            mtx[1][1] = 1.0f;
            mtx[0][0] = c;
            mtx[0][2] = s;
            mtx[2][0] = -s;
            mtx[2][2] = c;
            mtx[0][1] = mtx[1][0] = mtx[1][2] = mtx[2][1] = 0.0f;
        }
        rec.w18 = mtx;
        saved = *(JGeometry::TVec3f*)(this_ + 0xc);
        *(f32*)(this_ + 0x10) += 1.0f;
        fn_801EFD34(this_, (*(MrtaResMgr**)(lbl_8053AAF8 + 0xa4))->getRes('TIMG', name), &rec, 7, 0.0f, -1.0f, 0.0f);
        *(JGeometry::TVec3f*)(this_ + 0xc) = saved;
        break;
    case 1:
        fn_801F06F0(this_, tbl + 0xc8, 0x445, &rec, 3, 1.0f, 1.0f);
        break;
    }
}

extern "C" void* fn_80239914(f32* out, s32 room, s32 handle);
extern "C" void* fn_8020D58C();
extern "C" void fn_8020D8C0(void* a, void* box, s32 room, s32 handle);
extern "C" void fn_80354FE8(void* this_);
extern "C" void fn_8013CB44(void* emitter, void* pos, s32 a, s32 b, s32 c);
extern "C" u8 fn_8023F264(s32);
extern "C" s32 fn_80230CFC(s32);
extern "C" u8 fn_8022C004(s32);
extern "C" u8 fn_8023E8F0(s32);
extern "C" u8 fn_8023188C(s32);
extern "C" u8 fn_802319B4(s32, s32);
extern "C" u8 fn_80234D94(s32);
extern "C" s32 fn_8022CAF8(s32);
extern "C" u8 fn_8022F9E4(s32, s32, s32, s32);
extern "C" u8 fn_8022E438(s32,s32);
extern "C" void fn_80230C6C(s32);
extern "C" void fn_8023DFF4(s32,const JGeometry::TVec3f&);
extern "C" void* fn_8023E7B0(s32);
extern "C" s32 fn_8023DE58(s32);
extern "C" u16 fn_80226850(void*,s32);
extern "C" void* lbl_8053AC98;
extern "C" void fn_802A381C(void*,void*,s32,s32);
extern "C" u8 fn_801F2740(void*,s32);
extern "C" u8 fn_80238548(s32,s32,void*,s32);
extern "C" u8 fn_801F2B20(void*,s32);
extern const f32 lbl_805427A8;
extern const f32 lbl_805427AC;
extern const f32 lbl_805427B0;

static inline u8 mrtaInside(const JGeometry::TBox2f& box, f32 x, f32 y) {
    u8 inside = 0;
    if (x >= box.i.x && y >= box.i.y && x < box.f.x && y < box.f.y) inside = 1;
    return inside;
}

#pragma opt_common_subs on
extern "C" void fn_803558A4(void* this_) {
    s32 scanIndex;
    s32 hitIndex;
    s32 filterIndex;
    s32 accepted;
    u8* player;
    u8* record;
    u8* order;
    s32 loopIndex;
    JGeometry::TVec3f* next;
    JGeometry::TVec3f positions[4];
    JGeometry::TBox2f box;
    JGeometry::TVec3f current;
    JGeometry::TVec3f saved;
    JGeometry::TVec3f delta;
    JGeometry::TVec3f temp;
    u8* p=(u8*)this_;
    box.set(*(JGeometry::TBox2f*)(p+0x80));
    box.addPos(*(JGeometry::TVec2f*)(p+0xc));
    switch(*(s32*)(p+0x230)) {
    case 0: {
        fn_80239914((f32*)&box,*(s32*)(p+4),*(s32*)(p+0x198));
        s32 handle=*(s32*)(p+0x198);
        s32 room=*(s32*)(p+4);
        u8* map=(u8*)fn_8020D58C();
        fn_8020D8C0(map+4+map[0]*0x784,&box,room,handle);
        fn_80354FE8(p);
        if(!(((JGeometry::TVec3f*)(p+0x2d4))->isZero()!=0)) {
            ((JGeometry::TVec3f*)(p+0xc))->add(*(JGeometry::TVec3f*)(p+0x3c));
            ((JGeometry::TVec3f*)(p+0x2d4))->sub(*(JGeometry::TVec3f*)(p+0x3c));
            if((u8)((JGeometry::TVec3f*)(p+0x2d4))->isZero()==1) {
                ((JGeometry::TVec3f*)(p+0x3c))->z=0.0f;
                ((JGeometry::TVec3f*)(p+0x3c))->y=0.0f;
                ((JGeometry::TVec3f*)(p+0x3c))->x=0.0f;
                u8* emitter=*(u8**)(p+0x2e0);
                if(emitter) {
                    *(u32*)(emitter+0xf4)|=1;
                    *(s32*)(emitter+0x24)=1;
                    *(void**)(p+0x2e0)=0;
                }
                p[0x2cc]=1;
            } else {
                u8* emitter=*(u8**)(p+0x2e0);
                if(emitter) fn_8013CB44(emitter,p+0xc,0,-2,1);
            }
        }
        if(!(((JGeometry::TVec3f*)(p+0x2d4))->isZero()!=0) || *(s32*)(p+0x2c8)!=0) break;
        *(s32*)(p+0x234)=-1;*(s32*)(p+0x238)=-1;*(s32*)(p+0x23c)=-1;*(s32*)(p+0x240)=-1;
        *(s32*)(p+0x244)=0;*(s32*)(p+0x248)=0;*(s32*)(p+0x24c)=0;*(s32*)(p+0x250)=0;
        *(s32*)(p+0x2d0)=-1;
        player=p;
        for(scanIndex=0;scanIndex<4;scanIndex++,player+=4) {
            if(fn_8023F264(scanIndex)) {
                f32* loc=(f32*)fn_8023E724(scanIndex);
                f32 x=loc[0],y=loc[1];
                s32 direction=fn_80230CFC(scanIndex);
                f32* offset=(f32*)(lbl_804722B0+direction*8);
                x+=offset[0];y+=offset[1];
                p[0x264+scanIndex]=fn_8022C004(scanIndex);
                if(p[0x264+scanIndex]==1 && fn_8023E8F0(scanIndex)==1 && fn_8023188C(scanIndex)==1 && fn_802319B4(scanIndex,17)==1 && !fn_80234D94(scanIndex) && (u8)mrtaInside(box,x,y)==1) {
                    *(s32*)(player+0x234)=direction;
                    ++*(s32*)(p+0x244+*(s32*)(player+0x234)*4);
                } else p[0x264+scanIndex]=0;
                if(p[0x264+scanIndex]==1 && *(s32*)(p+0x2d0)==-1) {
                    if(*(s32*)(p+0x2c0)==0) {
                        if(*(s32*)(player+0x234)==0 || *(s32*)(player+0x234)==1) break;
                    } else {
                        if(*(s32*)(player+0x234)==2 || *(s32*)(player+0x234)==3) break;
                    }
                    s32 d=*(s32*)(player+0x234);
                    if(*(s32*)(p+0x244+d*4)>=4) *(s32*)(p+0x2d0)=d;
                }
            }
        }
        if(*(s32*)(p+0x2d0)==-1) break;
        accepted=0;
        if(((s32*)(p+*(s32*)(p+0x2d0)*4))[0x244/4]>=4) {
            player=p;
            for(filterIndex=0;filterIndex<4;filterIndex++,player+=4) {
                if(*(s32*)(player+0x234)==*(s32*)(p+0x2d0) && !fn_8023E8F0(filterIndex)) {
                    *(s32*)(player+0x234)=-1;
                    --*(s32*)(p+0x244+*(s32*)(p+0x2d0)*4);
                }
            }
        }
        if(*(s32*)(p+0x244+*(s32*)(p+0x2d0)*4)>=4) {
            record=p;
            player=p;
            order=p;
            for(loopIndex=0;loopIndex<4;loopIndex++,player+=4,record+=0x14) {
                *(JGeometry::TVec3f*)(record+0x26c)=*(JGeometry::TVec3f*)fn_8023E724(loopIndex);
                *(s32*)(record+0x278)=fn_8022CAF8(loopIndex);
                if(*(s32*)(player+0x234)==*(s32*)(p+0x2d0) && accepted<4) {
                    if(fn_8022F9E4(loopIndex,*(s32*)(p+0x198),1,0)) {
                        ++accepted;
                        *(s32*)(order+0x254)=loopIndex;
                        order+=4;
                        if(accepted>=4) {
                            if(((Actor*)p)->v13()>0) {
                                ((Actor*)p)->v10(255,1);
                                *(s32*)(p+0x230)=1;*(s32*)(p+0xb8)=0;
                            }
                        }
                    }
                } else *(s32*)(player+0x234)=-1;
            }
        }
        if(*(s32*)(p+0x230)==1) {
            player=p;
            for(loopIndex=0;loopIndex<4;loopIndex++,player+=0x14) {
                if(fn_8022E438(*(s32*)(p+0x254),loopIndex)==1 || fn_8022E438(*(s32*)(p+0x258),loopIndex)==1)
                    player[0x268]=0;
            }
        }
        break;
    }
    case 1:
        if(p[0xc4]) {
            player=p;
            record=p;
            next=positions;
            for(loopIndex=0;loopIndex<4;loopIndex++,record+=0x14,player+=4) {
                if(*(s32*)(player+0x234)==*(s32*)(p+0x2d0) && record[0x268]==0) {
                    s32 state=fn_8022CAF8(loopIndex);
                    if(*(s32*)(record+0x278)!=state) {fn_80230C6C(loopIndex);return;}
                }
                current=*(JGeometry::TVec3f*)fn_8023E724(loopIndex);
                saved=*(JGeometry::TVec3f*)(record+0x26c);
                if(!record[0x268]) {
                    f32 x=current.x-saved.x,y=current.y-saved.y;
                    f32 xSquared=x*x;
                    f32 ySquared=y*y;
                    if(JGeometry::TUtilf::sqrt(xSquared+ySquared)>lbl_805427A8) {
                        temp=saved;
                        temp.sub(current);
                        delta=temp;
                        fn_8023DFF4(loopIndex,delta);
                    }
                }
                if(*(s32*)(player+0x234)==*(s32*)(p+0x2d0)) *next++=*(JGeometry::TVec3f*)fn_8023E7B0(loopIndex);
            }
            positions[0].add(positions[1]);
            positions[0].add(positions[2]);
            positions[0].add(positions[3]);
            positions[0].scale(lbl_805427AC);
            if(positions[0].z>0.0f) {
                *(f32*)(p+0xc)=positions[0].x;
                *(f32*)(p+0x10)=positions[0].y;
                *(f32*)(p+0x14)=positions[0].z;
                *(s32*)(p+4)=fn_8023DE58(*(s32*)(p+0xc8));
            }
        } else {
            *(f32*)(p+0x44)+=lbl_805427B0;
            ((JGeometry::TVec3f*)(p+0xc))->add(*(JGeometry::TVec3f*)(p+0x3c));
            if(*(f32*)(p+0x14)<0.0f || fn_801F2618((Actor*)p,0,0)) {
                if(*(f32*)(p+0x14)<0.0f) {
                    if(fn_80226850(p+0xc,*(s32*)(p+4))==0x90) fn_802A381C(lbl_8053AC98,p+0xc,*(s32*)(p+4),0x91);
                    else if(fn_80226850(p+0xc,*(s32*)(p+4))==0x91) fn_802A381C(lbl_8053AC98,p+0xc,*(s32*)(p+4),0x92);
                }
                *(s32*)(p+0x230)=2;
            } else {
                s32 mask=fn_801F2740(p,-1);
                u8 hit=0;
                if(mask>0) {
                    player=p;
                    for(hitIndex=0;hitIndex<4;hitIndex++,player+=4) {
                        if(*(s32*)(player+0x234)!=*(s32*)(p+0x2d0) && (s32)(mask&(1<<hitIndex))>0 &&
                           !fn_8022E438(*(s32*)(p+0x254),hitIndex) && !fn_8022E438(*(s32*)(p+0x258),hitIndex)) {
                            fn_80238548(hitIndex,0,p+0xc,5);hit=1;
                        }
                    }
                }
                if(hit==1 || fn_801F2B20(p,0)) *(s32*)(p+0x230)=2;
            }
        }
        break;
    case 2: ((Actor*)p)->v07();break;
    }
}
#pragma opt_common_subs off
extern "C" void fn_80356268(void* this_) {
    u8* p = (u8*)this_;
    *(s32*)(p + 0x2c0) = *(u32*)(p + 0x90) & 1;
    *(s32*)(p + 0x2c4) = (*(u32*)(p + 0x90) >> 4) & 1;
    *(s32*)(p + 0x2c8) = (*(u32*)(p + 0x90) >> 8) & 1;
    *(s32*)(p + 0x1a4) = 2;
    switch (*(s32*)(p + 0x2c8)) {
    case 0:
        switch (*(s32*)(p + 0x2c0)) {
        case 0:
            switch (*(s32*)(p + 0x2c4)) {
            case 0:
                *(f32*)(p + 0x60) = -46.0f;
                *(f32*)(p + 0x64) = -7.0f;
                *(f32*)(p + 0x68) = 46.0f;
                *(f32*)(p + 0x6c) = 7.0f;
                *(f32*)(p + 0x80) = -47.0f;
                *(f32*)(p + 0x84) = -7.0f;
                *(f32*)(p + 0x88) = 47.0f;
                *(f32*)(p + 0x8c) = 7.0f;
                break;
            case 1:
                *(f32*)(p + 0x60) = -46.0f;
                *(f32*)(p + 0x64) = -14.0f;
                *(f32*)(p + 0x68) = 46.0f;
                *(f32*)(p + 0x6c) = 14.0f;
                *(f32*)(p + 0x80) = -47.0f;
                *(f32*)(p + 0x84) = -15.0f;
                *(f32*)(p + 0x88) = 47.0f;
                *(f32*)(p + 0x8c) = 15.0f;
                break;
            }
            break;
        case 1:
            switch (*(s32*)(p + 0x2c4)) {
            case 0:
                *(f32*)(p + 0x60) = -7.0f;
                *(f32*)(p + 0x64) = -46.0f;
                *(f32*)(p + 0x68) = 7.0f;
                *(f32*)(p + 0x6c) = 46.0f;
                *(f32*)(p + 0x80) = -7.0f;
                *(f32*)(p + 0x84) = -47.0f;
                *(f32*)(p + 0x88) = 7.0f;
                *(f32*)(p + 0x8c) = 47.0f;
                break;
            case 1:
                *(f32*)(p + 0x60) = -14.0f;
                *(f32*)(p + 0x64) = -46.0f;
                *(f32*)(p + 0x68) = 14.0f;
                *(f32*)(p + 0x6c) = 46.0f;
                *(f32*)(p + 0x80) = -15.0f;
                *(f32*)(p + 0x84) = -47.0f;
                *(f32*)(p + 0x88) = 15.0f;
                *(f32*)(p + 0x8c) = 47.0f;
                break;
            }
            break;
        }
        break;
    case 1:
        *(f32*)(p + 0x60) = -15.0f;
        *(f32*)(p + 0x64) = -23.0f;
        *(f32*)(p + 0x68) = 15.0f;
        *(f32*)(p + 0x6c) = 7.0f;
        *(f32*)(p + 0x80) = -15.0f;
        *(f32*)(p + 0x84) = -23.0f;
        *(f32*)(p + 0x88) = 15.0f;
        *(f32*)(p + 0x8c) = 7.0f;
        *(f32*)(p + 0x70) = -15.0f;
        *(f32*)(p + 0x74) = -23.0f;
        *(f32*)(p + 0x78) = 15.0f;
        *(f32*)(p + 0x7c) = 7.0f;
        break;
    }
    *(s32*)(p + 0x234) = -1;
    *(u8*)(p + 0x264) = 0;
    *(u8*)(p + 0x268) = 1;
    *(f32*)(p + 0x274) = 0.0f;
    *(f32*)(p + 0x270) = 0.0f;
    *(f32*)(p + 0x26c) = 0.0f;
    *(s32*)(p + 0x278) = 0;
    *(s32*)(p + 0x238) = -1;
    *(u8*)(p + 0x265) = 0;
    *(u8*)(p + 0x27c) = 1;
    *(f32*)(p + 0x288) = 0.0f;
    *(f32*)(p + 0x284) = 0.0f;
    *(f32*)(p + 0x280) = 0.0f;
    *(s32*)(p + 0x28c) = 0;
    *(s32*)(p + 0x23c) = -1;
    *(u8*)(p + 0x266) = 0;
    *(u8*)(p + 0x290) = 1;
    *(f32*)(p + 0x29c) = 0.0f;
    *(f32*)(p + 0x298) = 0.0f;
    *(f32*)(p + 0x294) = 0.0f;
    *(s32*)(p + 0x2a0) = 0;
    *(s32*)(p + 0x240) = -1;
    *(u8*)(p + 0x267) = 0;
    *(u8*)(p + 0x2a4) = 1;
    *(f32*)(p + 0x2b0) = 0.0f;
    *(f32*)(p + 0x2ac) = 0.0f;
    *(f32*)(p + 0x2a8) = 0.0f;
    *(s32*)(p + 0x2b4) = 0;
    *(s32*)(p + 0x254) = -1;
    *(s32*)(p + 0x258) = -1;
    *(s32*)(p + 0x25c) = -1;
    *(s32*)(p + 0x260) = -1;
    *(s32*)(p + 0x244) = 0;
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x250) = 0;
    *(s32*)(p + 0xb8) = 2;
    *(s32*)(p + 0x230) = 0;
    *(s32*)(p + 0x2b8) = 0;
    *(s32*)(p + 0x2bc) = 0;
    *(s32*)(p + 0x2d0) = -1;
    *(f32*)(p + 0x2dc) = 0.0f;
    *(f32*)(p + 0x2d8) = 0.0f;
    *(f32*)(p + 0x2d4) = 0.0f;
    *(u8*)(p + 0x2cc) = 0;
    *(s32*)(p + 0x2e0) = 0;
}

extern "C" Actor* fn_80356514(Actor* p, s16 n) {
    if (p != 0) {
        *(void**)p = __vt__4MRTA;
        void* emitter = *(void**)((char*)p + 0x2e0);
        if (emitter != 0) fn_801EE434(emitter);
        __dt__5ActorFv(p, 0);
        s32 v = n;
        if (v > 0) operator delete(p);
    }
    return p;
}
