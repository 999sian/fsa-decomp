// Functions imported from EverydaySimpleDev/FSA-Decomp (CC0).
// TU 8015DE10-8015F454 (FLME). Remaining functions are not yet decompiled.
#include "types.h"
#include "JSystem/JGeometry/Box.h"
#include "JSystem/JParticle/JPAEmitter.h"
extern const f32 lbl_8053D59C;
extern const f32 lbl_8053D5A0;
extern const f32 lbl_8053D5EC;
extern const f32 lbl_8053D5F0;
extern const f32 lbl_8053D5F4;
extern "C" void fn_801F0D20(void*,s32);
extern const f32 lbl_8053D5A4;
extern "C" s32 fn_8023B004(void*,s32);
extern "C" void fn_80230FD0(s32,u32);
extern "C" void fn_801F71A4(f32*,f32,f32,f32);
extern "C" void fn_801F2B20(void*,s32);
extern "C" u8 fn_801F2B7C(void*,s32,s32,s32);
extern "C" u8 fn_8023F264(s32);
extern "C" s32 fn_8023DE58(s32);
extern "C" f32* fn_8023E724(s32);
extern "C" void fn_8023DFF4(s32,void*);
extern "C" void fn_80239914(void*,s32,u32);
extern "C" void fn_8013CB44(s32,void*,s32,s32,s32);
extern const u8 lbl_80466110[];
extern u8 lbl_804A0310[];
extern u8* lbl_8053AAF8;
extern const f32 lbl_8053D5A8;
extern const f32 lbl_8053D5AC;
extern const f32 lbl_8053D5B0;
extern const f32 lbl_8053D5B4;
extern const f32 lbl_8053D5B8;
extern const f32 lbl_8053D5BC;
extern const f32 lbl_8053D5C0;
extern const f32 lbl_8053D5C4;
extern const f32 lbl_8053D5C8;
extern const f32 lbl_8053D5CC;
extern const f32 lbl_8053D5D0;
extern const f32 lbl_8053D5D4;
extern const f32 lbl_8053D5D8;
extern const f32 lbl_8053D5DC;
extern const f32 lbl_8053D5E0;
extern const f32 lbl_8053D5E4;
extern const f32 lbl_8053D5E8;
extern const f32 lbl_8053D5F8;
extern const f32 lbl_8053D5FC;


// from src/Game/fn_8015F19C_dtor.cpp
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* this_);
extern "C" void fn_801EE434(void* handle);
extern void* lbl_804A0330[];

extern "C" void* fn_8015F19C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A0330;
        char* p = (char*)this_;
        for (s32 i = 0; i < 4; i++) {
            fn_801EE434(*(void**)(p + 0x264));
            p += 4;
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_8015EA2C(char* p);
extern "C" void fn_8015DF7C(void* this_);

struct FlmeTimers { u8 pad[0x234]; s32 t[3]; };
// FLME update (vtable slot 3)
extern "C" void fn_8015DEFC(char* this_) {
    fn_8015EA2C(this_);
    if (*(s32*)(this_ + 0x230) != 5) {
        fn_8015DF7C(this_);
    }
    for (int i = 0; i < 3; i++) {
        if (((FlmeTimers*)this_)->t[i] > 0) {
            ((FlmeTimers*)this_)->t[i]--;
        }
    }
}

extern "C" s32 fn_8013CC50(s32,void*,f32,s32,s32,s32,s32,s32,s32);
extern "C" void fn_801F0E34(void*,u32,s32);
extern "C" u8* fn_8020D58C();
extern "C" void fn_8020D7D0(void*,s32);
extern "C" s16 fn_801F6874(s32);
extern const f32 lbl_8053D600;
#pragma opt_common_subs off
extern "C" void fn_8015DF7C(void* this_) {
 const u8* base=lbl_80466110;
 char* p=(char*)((u32)this_);
 JGeometry::TVec3<f32> pos;
 JGeometry::TBox2f box;
 volatile JGeometry::TVec2<f32> savedDelta;
 box.set(*(JGeometry::TBox2f*)(p+0x60));
 f32 x;f32 y;
 y=*(f32*)(p+0x10);
 x=*(f32*)(p+0xc);
 box.addPos(x,y);
 if(*(s32*)(p+0x254)!=0){
 s32 player=fn_8023B004(&box,*(s32*)(p+4));
 if(player>=0){if(*(s32*)(p+0x244)==0){fn_801F0D20(p,3);fn_80230FD0(player,0x30009);*(s32*)(p+0x244)=1;}}
 else *(s32*)(p+0x244)=0;
 return;
 }
 if(*(s32*)(p+0x240)!=0){
 f32 target=lbl_8053D59C;if(*(u16*)(p+0x94)==4)target=lbl_8053D5A0;
 fn_801F71A4((f32*)(p+0x260),target,lbl_8053D5A4,1.0f);
 if(*(u16*)(p+0x94)!=4&&*(u16*)(p+0x94)!=5){
 {const JGeometry::TBox2f* src=&((const JGeometry::TBox2f*)(base+0x20))[*(s32*)(p+0x98)];((JGeometry::TBox2f*)(p+0x60))->i.set(src->i.x,src->i.y);((JGeometry::TBox2f*)(p+0x60))->f.set(src->f.x,src->f.y);}
 if(*(s32*)(p+0x258)==1){((JGeometry::TVec2<f32>*)(p+0x60))->scale(lbl_8053D5A8);((JGeometry::TVec2<f32>*)(p+0x68))->scale(lbl_8053D5A8);}
 if(*(f32*)(p+0x260)>lbl_8053D5AC){
 fn_801F2B20(p,5);
 if(!fn_801F2B7C(p,*(s32*)(p+0x114),-1,9)&&lbl_8053AAF8[0x7f]==1){
 {const JGeometry::TBox2f* src=&((const JGeometry::TBox2f*)(base+0x60))[*(s32*)(p+0x98)];((JGeometry::TBox2f*)(p+0x80))->i.set(src->i.x,src->i.y);((JGeometry::TBox2f*)(p+0x80))->f.set(src->f.x,src->f.y);}
 if(*(s32*)(p+0x258)==1){((JGeometry::TVec2<f32>*)(p+0x80))->scale(lbl_8053D5A8);((JGeometry::TVec2<f32>*)(p+0x88))->scale(lbl_8053D5A8);}
 box=*(JGeometry::TBox2f*)(p+0x80);box.addPos(x,y);
 fn_80239914(&box,*(s32*)(p+4),*(u32*)(p+0x198));
 }}
 }else{
 if(*(u16*)(p+0x94)==5){
 ((JGeometry::TBox2f*)(p+0x60))->set(lbl_8053D5B0,lbl_8053D5B4,lbl_8053D5B8,lbl_8053D5BC);
 ((JGeometry::TBox2f*)(p+0x80))->set(lbl_8053D5C0,lbl_8053D5C4,lbl_8053D5C8,lbl_8053D5B8);
 }else{
 ((JGeometry::TBox2f*)(p+0x60))->set(lbl_8053D5CC,lbl_8053D5CC,lbl_8053D5D0,lbl_8053D5D4);
 ((JGeometry::TBox2f*)(p+0x80))->set(lbl_8053D5D8,lbl_8053D5D8,lbl_8053D5DC,lbl_8053D5E0);
 }
 box=*(JGeometry::TBox2f*)(p+0x60);box.addPos(x,y);
 fn_801F2B20(p,5);
 if(!fn_801F2B7C(p,*(s32*)(p+0x114),-1,9)){
 for(s32 i=0;i<4;i++){
 if(fn_8023F264(i)&&fn_8023DE58(i)!=8){
 f32* src=fn_8023E724(i);
 f32 sx=src[0];f32 sy=src[1];
 f32 dy=sy-*(f32*)(p+0x10);savedDelta.y=sy;
 f32 dx=sx-*(f32*)(p+0xc);savedDelta.x=sx;
 JGeometry::TVec2<f32> d(dx,dy);savedDelta.x=dx;savedDelta.y=dy;
 if(d.squared()<lbl_8053D5E4){d.normalize();if(!(d.squared()<=JGeometry::TUtilf::epsilon()))d.scale(lbl_8053D5F8);pos.set(d.x,d.y,lbl_8053D5EC);fn_8023DFF4(i,&pos);}
 }}}
 }
 }else{
 fn_801F71A4((f32*)(p+0x260),lbl_8053D5EC,lbl_8053D5A4,lbl_8053D59C);
 ((JGeometry::TBox2f*)(p+0x60))->set(lbl_8053D59C,lbl_8053D5FC,lbl_8053D59C,lbl_8053D5FC);
 ((JGeometry::TBox2f*)(p+0x80))->set(lbl_8053D59C,lbl_8053D5FC,lbl_8053D59C,lbl_8053D5FC);
 }

 if(*(u16*)(p+0x94)!=4&&*(u16*)(p+0x94)!=5){
 pos.set(*(JGeometry::TVec3<f32>*)(p+0xc));
 JGeometry::TVec2<f32>* offset=(JGeometry::TVec2<f32>*)lbl_804A0310;
 pos.x+=offset[*(s32*)(p+0x98)].x;pos.y+=offset[*(s32*)(p+0x98)].y;
 if(*(f32*)(p+0x260)<lbl_8053D5A4){
 JPABaseEmitter* emitter=*(JPABaseEmitter**)(p+0x264);if(emitter)emitter->becomeInvalidEmitter();
 if(*(u32*)(p+0x268)==0){
 if(*(u32*)(p+0x264)!=0){
 s32 id=0x1ad;if(*(s32*)(p+0x25c)==1)id=0x253;
 *(u32*)(p+0x268)=fn_8013CC50(*(s32*)(p+4),&pos,lbl_8053D5F0*(f32)*(s32*)(p+0x258)+lbl_8053D59C,id,1,1,0,0,1);
 }else{
 s32 id=0x1ae;if(*(s32*)(p+0x25c)==1)id=0x253;
 *(u32*)(p+0x268)=fn_8013CC50(*(s32*)(p+4),&pos,lbl_8053D5F0*(f32)*(s32*)(p+0x258)+lbl_8053D59C,id,1,1,0,0,1);
 }
 *(u32*)(p+0x264)=0;
 }
 if(*(u32*)(p+0x268)!=0){
 s32 angle=0;if(*(s32*)(p+0x98)==2)angle=0x4000;
 fn_8013CB44(*(u32*)(p+0x268),&pos,1,1,1);
 JPAGetXYZRotateMtx((s16)angle,(s16)((const s32*)base)[*(s32*)(p+0x98)],-0x8000,(*(JPABaseEmitter**)(p+0x268))->mGlobalRot);
 }
 }else{
 JPABaseEmitter* emitter=*(JPABaseEmitter**)(p+0x268);
 if(emitter){emitter->becomeInvalidEmitter();*(u32*)(p+0x268)=0;}
 if(*(u32*)(p+0x264)==0){
 s32 id=0x1ac;if(*(s32*)(p+0x25c)==1)id=0x252;
 *(u32*)(p+0x264)=fn_8013CC50(*(s32*)(p+4),&pos,lbl_8053D5F0*(f32)*(s32*)(p+0x258)+lbl_8053D59C,id,1,1,0,0,1);
 }
 if(*(u32*)(p+0x264)!=0){
 s32 angle=0;if(*(s32*)(p+0x98)==2)angle=0x4000;
 fn_8013CB44(*(u32*)(p+0x264),&pos,1,1,1);
 JPAGetXYZRotateMtx((s16)angle,(s16)((const s32*)base)[*(s32*)(p+0x98)],-0x8000,(*(JPABaseEmitter**)(p+0x264))->mGlobalRot);
 }
 if(lbl_8053D59C!=*(f32*)(p+0x60)&&lbl_8053D5FC!=*(f32*)(p+0x68)){
 s32 room=*(s32*)(p+0x198);u8* g=fn_8020D58C();fn_8020D7D0(g+4+g[0]*0x784,room);fn_801F0E34(p,0x30011,0);
 }
 }
 *(s32*)(p+0x24c)+=1;
 if(*(s32*)(p+0x24c)>10){
 s32 i;s32 count=5;if(*(f32*)(p+0x260)<lbl_8053D5A4)count=1;
 for(i=0;i<count;i++){
 pos.set(*(JGeometry::TVec3<f32>*)(p+0xc));
 s32 a=fn_801F6874(*(s32*)(p+0x98));
 f32 distance=lbl_8053D5F8*(f32)i;
 pos.x+=distance*JMath::sincosTable_.mTable[(u16)a>>5].first;
 a=fn_801F6874(*(s32*)(p+0x98));
 pos.y+=distance*JMath::sincosTable_.mTable[(u16)a>>5].second;
 fn_8013CC50(*(s32*)(p+4),&pos,lbl_8053D59C,0x54d,1,1,0,0,1);
 }
 *(s32*)(p+0x24c)=0;
 }
 }else if(*(u32*)(p+0x264)!=0){
 (*(JPABaseEmitter**)(p+0x264))->mGlobalPrmClr.a=(u8)(lbl_8053D600**(f32*)(p+0x260));
 (*(JPABaseEmitter**)(p+0x268))->mGlobalPScl.setAll(*(f32*)(p+0x260));
 (*(JPABaseEmitter**)(p+0x26c))->mGlobalPScl.setAll(*(f32*)(p+0x260));
 if(*(f32*)(p+0x260)>lbl_8053D5A4){
 *(s32*)(p+0x24c)+=1;
 if(*(s32*)(p+0x24c)>10){
 s32 i;s32 angle;for(i=0,angle=0;i<8;i++,angle+=0x2000){
 pos.set(*(JGeometry::TVec3<f32>*)(p+0xc));
 f32 distance=*(u16*)(p+0x94)==5?lbl_8053D5B8:lbl_8053D5E0;
 pos.x+=distance*JMath::sincosTable_.mTable[(u16)angle>>5].first;
 pos.y+=distance*JMath::sincosTable_.mTable[(u16)angle>>5].second;
 fn_8013CC50(*(s32*)(p+4),&pos,lbl_8053D59C,0x54d,1,1,0,0,1);
 }
 *(s32*)(p+0x24c)=0;
 }
 if(lbl_8053D59C!=*(f32*)(p+0x60)&&lbl_8053D5FC!=*(f32*)(p+0x68)){
 s32 room=*(s32*)(p+0x198);u8* g=fn_8020D58C();fn_8020D7D0(g+4+g[0]*0x784,room);fn_801F0E34(p,0x30011,0);
 }
 }
 }
}
#pragma opt_common_subs reset

struct FlmeColor {
    FlmeColor(u8 r_, u8 g_, u8 b_, u8 a_) { r = r_; g = g_; b = b_; a = a_; }
    u8 r, g, b, a;
};
extern "C" void fn_80158B5C(void* mgr, u32 id, void* pos, FlmeColor col, f32 radius);
extern void** lbl_8053AB10;

static inline void flmeLight(char* this_, f32 r) {
    u32 id = *(u32*)(this_ + 0x4);
    fn_80158B5C(lbl_8053AB10[0xb], id, this_ + 0xc, FlmeColor(0, 0, 0, 0x80), r);
}

// FLME light source
extern "C" void fn_8015DE10(char* this_) {
    if (*(s32*)(this_ + 0x254) == 0 && *(u16*)(this_ + 0x94) != 4 && *(u16*)(this_ + 0x94) != 5) {
        flmeLight(this_, 60.0f);
    }
    if (*(s32*)(this_ + 0x240) != 0) {
        u16 t = *(u16*)(this_ + 0x94);
        if (t == 4 || t == 5) {
            f32 r = 46.2f;
            if (t == 5) {
                r = 140.0f;
            }
            flmeLight(this_, r);
        }
    }
}

extern const f32 lbl_8053D5EC;
extern const f32 lbl_8053D59C;
extern const f32 lbl_8053D5A0;
extern const f32 lbl_8053D5F0;
extern const f32 lbl_8053D5F4;
extern const f32 lbl_8053D618;
extern const f32 lbl_8053D61C;
extern const f32 lbl_8053D620;
extern "C" s32 fn_8013CC50(s32 room, void* pos, f32 scale, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e);

extern "C" void fn_8015EDF4(char* p) {
    *(s32*)(p + 0x240) = 0;
    *(s32*)(p + 0x244) = 0;
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x234) = 0;
    *(s32*)(p + 0x238) = 0;
    *(s32*)(p + 0x23c) = 0;
    *(s32*)(p + 0x264) = 0;
    *(s32*)(p + 0x268) = 0;
    *(s32*)(p + 0x26c) = 0;
    *(s32*)(p + 0x270) = 0;
    *(s32*)(p + 0x254) = 0;
    *(f32*)(p + 0x3c) = lbl_8053D5EC;
    *(f32*)(p + 0x40) = lbl_8053D5EC;
    *(f32*)(p + 0x44) = lbl_8053D5EC;
    *(s32*)(p + 0x118) = 4;
    *(s32*)(p + 0x258) = (*(u32*)(p + 0x90) >> 18) & 3;
    *(s32*)(p + 0x25c) = (*(u32*)(p + 0x90) >> 20) & 1;
    if ((*(u32*)(p + 0x90) & 0xff00) == 0) {
        *(u16*)(p + 0x94) = *(u32*)(p + 0x90) & 0xff;
        *(s32*)(p + 0x98) = (*(u32*)(p + 0x90) >> 16) & 3;
        if (*(u16*)(p + 0x94) == 4 || *(u16*)(p + 0x94) == 5) {
            *(s32*)(p + 0x98) = 3;
        } else {
            *(s32*)(p + 0x114) = 4;
        }
        *(f32*)(p + 0x260) = lbl_8053D5EC;
        if (*(u16*)(p + 0x94) >= 9) {
            *(u16*)(p + 0x94) = 0;
        }
        switch (*(u16*)(p + 0x94)) {
        case 4:
        case 5:
            if (*(u16*)(p + 0x94) == 5) {
                *(f32*)(p + 0x260) = lbl_8053D59C;
            } else {
                *(f32*)(p + 0x260) = lbl_8053D5A0;
            }
            *(s32*)(p + 0x270) = fn_8013CC50(*(s32*)(p + 0x4), p + 0xc, *(f32*)(p + 0x260), 0x3e, 0, -1, 0, 0, 1);
            *(s32*)(p + 0x264) = fn_8013CC50(*(s32*)(p + 0x4), p + 0xc, *(f32*)(p + 0x260), 0x3b, 0, -1, 0, 0, 1);
            *(s32*)(p + 0x268) = fn_8013CC50(*(s32*)(p + 0x4), p + 0xc, *(f32*)(p + 0x260), 0x3c, 1, 1, 0, 0, 1);
            *(s32*)(p + 0x26c) = fn_8013CC50(*(s32*)(p + 0x4), p + 0xc, *(f32*)(p + 0x260), 0x3d, 1, 1, 0, 0, 1);
            *(s32*)(p + 0x240) = 1;
            *(s32*)(p + 0x234) = 8;
            *(s32*)(p + 0x230) = 0;
            break;
        case 0:
        case 6:
            *(f32*)(p + 0x260) = lbl_8053D59C;
            *(s32*)(p + 0x240) = 1;
            *(s32*)(p + 0x234) = 8;
            *(s32*)(p + 0x230) = 0;
            break;
        case 1:
            *(s32*)(p + 0x230) = 1;
            break;
        case 2:
            *(s32*)(p + 0x230) = 2;
            break;
        case 3:
            *(s32*)(p + 0x230) = 3;
            break;
        }
        switch (*(s32*)(p + 0x98)) {
        case 0:
            *(f32*)(p + 0x3c) = lbl_8053D5F4;
            *(f32*)(p + 0x40) = lbl_8053D5F0;
            *(f32*)(p + 0x44) = lbl_8053D5EC;
            break;
        case 1:
            *(f32*)(p + 0x3c) = lbl_8053D618;
            *(f32*)(p + 0x40) = lbl_8053D5F0;
            *(f32*)(p + 0x44) = lbl_8053D5EC;
            break;
        case 2:
            *(f32*)(p + 0x3c) = lbl_8053D5EC;
            *(f32*)(p + 0x40) = lbl_8053D5F4;
            *(f32*)(p + 0x44) = lbl_8053D5EC;
            break;
        case 3:
            *(f32*)(p + 0x3c) = lbl_8053D5EC;
            *(f32*)(p + 0x40) = lbl_8053D618;
            *(f32*)(p + 0x44) = lbl_8053D5EC;
            break;
        }
    } else {
        *(f32*)(p + 0x60) = lbl_8053D61C;
        *(f32*)(p + 0x64) = lbl_8053D61C;
        *(f32*)(p + 0x68) = lbl_8053D620;
        *(f32*)(p + 0x6c) = lbl_8053D620;
        *(u16*)(p + 0x94) = (*(u32*)(p + 0x90) >> 8) & 0xff;
        if (*(u16*)(p + 0x94) >= 9) {
            *(u16*)(p + 0x94) = 1;
        }
        *(s32*)(p + 0x254) = 1;
        switch (*(u16*)(p + 0x94)) {
        case 1:
            *(s32*)(p + 0x230) = 6;
            break;
        case 2:
            *(s32*)(p + 0x230) = 7;
            break;
        case 3:
            *(s32*)(p + 0x230) = 8;
            break;
        }
    }
    *(s32*)(p + 0x250) = 0;
    fn_8015EA2C(p);
    if (*(s32*)(p + 0x240) == 0) {
        *(f32*)(p + 0x260) = lbl_8053D5EC;
    }
    if (*(s32*)(p + 0x230) != 5 && *(s32*)(p + 0x230) != 4) {
        fn_8015DF7C(p);
    }
}

struct FlmeV {
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
    virtual void v10(s32 a, s32 b);
    virtual u8 v11();
};
extern const f32 lbl_8053D5A4;
extern const f32 lbl_8053D610;
extern const f32 lbl_8053D614;
extern u16 lbl_80539F70[4];
extern "C" void fn_801F0D20(void* p, s32 a);
extern "C" void fn_801EEC98(void* p, s32 a, s32 b, s32* out, f32* dist, s32 c, s32 d, s32 e);
extern "C" void fn_801F0E34(void* target, u32 effectId, s32 flag);

extern "C" void fn_8015EA2C(char* p) {
    FlmeV* v = (FlmeV*)p;
    f32 dist = lbl_8053D5EC;
    s32 found;
    switch (*(s32*)(p + 0x230)) {
    case 0:
        if (v->v11()) {
            if (*(s32*)(p + 0x240) != 0 && (*(u16*)(p + 0x94) == 4 || *(u16*)(p + 0x94) == 5)) {
                fn_801F0D20(p, 3);
            }
            *(s32*)(p + 0x240) = 0;
            if (*(u16*)(p + 0x94) == 6) {
                *(s32*)(p + 0x230) = 4;
            }
        } else {
            *(s32*)(p + 0x240) = 1;
        }
        break;
    case 1:
        if (v->v11()) {
            *(s32*)(p + 0x240) = 1;
        } else {
            *(s32*)(p + 0x240) = 0;
        }
        break;
    case 2:
        if (v->v11()) {
            *(s32*)(p + 0x240) = 0;
            *(s32*)(p + 0x230) = 4;
        } else {
            fn_801EEC98(p, *(s32*)(p + 0x198), 0, &found, &dist, 0, 0, 0);
            if (*(s32*)(p + 0x240) == 0) {
                if (found >= 0 && dist <= lbl_8053D610) {
                    *(s32*)(p + 0x240) = 1;
                }
            } else {
                if (found >= 0 && dist >= lbl_8053D614) {
                    *(s32*)(p + 0x234) = 8;
                    *(s32*)(p + 0x240) = 0;
                }
            }
        }
        break;
    case 3:
        if (v->v11()) {
            *(s32*)(p + 0x240) = 0;
            *(s32*)(p + 0x230) = 4;
        } else {
            if (*(s32*)(p + 0x238) != 0) {
                if (*(s32*)(p + 0x238) == 1) {
                    *(s32*)(p + 0x238) = 0;
                    *(s32*)(p + 0x240) = 0;
                    *(s32*)(p + 0x23c) = 0xb4;
                }
            } else if (*(s32*)(p + 0x23c) == 0) {
                *(s32*)(p + 0x238) = 0x78;
                *(s32*)(p + 0x240) = 1;
            }
        }
        break;
    case 4:
        *(s32*)(p + 0x240) = 0;
        if (*(f32*)(p + 0x260) < lbl_8053D5A4) {
            char* h;
            u8 played = 0;
            for (s32 i = 0; i < 4; i++) {
                h = *(char**)(p + i * 4 + 0x264);
                if (h != 0) {
                    *(u32*)(h + 0xf4) |= 1;
                    *(s32*)(h + 0x24) = 1;
                    *(char**)(p + i * 4 + 0x264) = 0;
                    if (!played) {
                        fn_801F0E34(p, 0x30061, 0);
                        played = 1;
                    }
                }
            }
            *(s32*)(p + 0x264) = fn_8013CC50(*(s32*)(p + 0x4), p + 0xc, lbl_8053D59C, lbl_80539F70[*(s32*)(p + 0x98)], 1, 0, 0, 0, 1);
            *(s32*)(p + 0x230) = 5;
        }
        break;
    case 6:
        if (*(s32*)(p + 0x244) != 0) {
            v->v10(0xff, 1);
            *(u8*)(p + 0x11c) = 0;
        }
        break;
    case 7:
        if (*(s32*)(p + 0x244) != 0) {
            v->v10(0xff, 1);
            *(u8*)(p + 0x11c) = 0;
        }
        break;
    case 8:
        if (*(s32*)(p + 0x234) == 0) {
            if (*(s32*)(p + 0x248) == 0) {
                if (*(s32*)(p + 0x244) != 0) {
                    v->v10(0xff, 1);
                    *(s32*)(p + 0x234) = 8;
                    *(s32*)(p + 0x248) = 1;
                }
            } else {
                if (*(s32*)(p + 0x244) == 0) {
                    v->v10(0xff, 1);
                    *(s32*)(p + 0x234) = 8;
                    *(s32*)(p + 0x248) = 0;
                }
            }
        }
        break;
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
#include "JSystem/JMath/JMath.h"
