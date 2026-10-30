#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"
#define I(p,o) (*(s32*)((u8*)(p)+(o)))
#define F(p,o) (*(f32*)((u8*)(p)+(o)))
#define B(p,o) (*(u8*)((u8*)(p)+(o)))
#define V(p,o) (*(JGeometry::TVec3<f32>*)((u8*)(p)+(o)))

#include "Game/ItemBase.h"


extern "C" char lbl_804AC7B8[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_803489A4(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804AC7B8;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" char lbl_804720B8[];
extern const f32 lbl_80542480;
extern "C" void fn_801F06F0(void* this_, const char* name, s32 id, DrawRec* rec, s32 p5, f32 a, f32 b);
extern "C" void fn_80348A04(u8* this_) {
    DrawRec rec;
    rec.b1d = 1;
    rec.b1c = 1;
    s32 pos = *(s32*)(this_ + 0x23c);
    pos += *(s32*)(this_ + 0x248);
    fn_801F06F0(this_, lbl_804720B8, pos + 0x2c5, &rec, 1, lbl_80542480, lbl_80542480);
}

extern "C" void* fn_801F856C();
extern "C" u8* fn_801F666C(void*, s32);
extern "C" s32 fn_801F3D94(void*, s32);
extern "C" s32 fn_801F285C(void*, void*, void*, s32, s32);
extern "C" u8 fn_802353AC(s32);
extern "C" JGeometry::TVec3<f32>* fn_8023E724(s32);
extern "C" s32 fn_8023B6CC(s32);
extern "C" void fn_801F37AC(void*, s32, const JGeometry::TVec3<f32>*, s32, s32, s32);
extern "C" u8 fn_8022F514(s32);
extern "C" s32 fn_8022F3DC(s32);
extern "C" void fn_801F71A4(f32*, f32, f32, f32);
extern "C" s32 fn_8023DE58(s32);
extern "C" s32 fn_8022E970(s32);
extern "C" s32 fn_8022CAF8(s32);
extern "C" s32 fn_8022EA0C(s32);
extern "C" u8 fn_801F2B7C(void*, s32, s32, s32);
extern const f32 lbl_80542484;
extern const f32 lbl_80542488;
extern const f32 lbl_8054248C;
extern const f32 lbl_80542490;
extern const f32 lbl_80542494;
extern const f32 lbl_80542498;
extern const f32 lbl_8054249C;
extern const f32 lbl_805424A0;
extern const f32 lbl_805424A4;
extern const f32 lbl_805424A8;
extern const f32 lbl_805424AC;
extern const f32 lbl_805424B0;
#pragma auto_inline off
extern const f32 lbl_805424B4;
extern const f32 lbl_805424B8;
extern "C" u8 fn_801F6758(void*, f32, s32);
#pragma opt_common_subs off
#pragma opt_propagation on
extern "C" void fn_80348B40(u8* p) {
    u8* owner=fn_801F666C(fn_801F856C(),I(p,0x250));
    if (B(p,0x262)==1) return;
    if (fn_801F3D94(p,0)!=0) return;
    if (I(p,0x230)!=0 && B(p,0x264)==0) {
        I(p,0x24c)=fn_801F285C(p,0,0,1,-1);
        if (I(p,0x24c)>=0 && fn_802353AC(I(p,0x24c))==1) {
            B(p,0x264)=1; I(p,0x240)=10;
            if (I(p,0x230)!=4) {
                V(p,0x3c).zero();I(p,0x230)=4;
            }
            return;
        }
    }
    if (B(p,0x265)==1) {
        const JGeometry::TVec3<f32>* pos=static_cast<const JGeometry::TVec3<f32>*>(fn_8023E724(I(p,0x24c)));
        fn_801F37AC(p,fn_8023B6CC(I(p,0x24c)),pos,0,1,-1);
        s32 idx=I(p,0x250);
        if (idx>=0) {
            u8* actor=fn_801F666C(fn_801F856C(),idx);
            if (actor) {
                s32 player=I(p,0x24c);
                if (player>=0 && fn_8022F514(player)==1) I(actor,0x27c)=fn_8022F3DC(player);
                else I(actor,0x27c)=player;
            }
        }
        return;
    }
    if (B(p,0x264)==1 && I(p,0x240)>0) {I(p,0x240)--;return;}
    fn_801F71A4(&F(p,0x3c),F(p,0x298),lbl_80542488,lbl_80542480);
    fn_801F71A4(&F(p,0x40),F(p,0x29c),lbl_80542488,lbl_80542480);
    fn_801F71A4(&F(p,0x44),F(p,0x2a0),lbl_8054248C,lbl_80542490);
    if (I(p,0x230)!=2 && I(p,0x230)!=3) V(p,0xc)+=V(p,0x3c);
    if (I(p,0x230)!=4) {
        if (I(p,0x230)!=0) {
            if (I(p,0x244)>=0) {
                if (fn_8023DE58(I(p,0x244))<8) {
                    V(p,0x274)=V(p,0x268);
                    V(p,0x268)=*fn_8023E724(I(p,0x244));
                    s32 rank=fn_8022E970(I(p,0x244));
                    switch (fn_8022CAF8(I(p,0x244))) {
                    case 0:
                        switch(rank) {case 1:break;case 2:case 3:case 4:F(p,0x268)+=lbl_80542494*(rank-1);break;}
                        break;
                    case 1:
                        switch(rank) {case 1:break;case 2:case 3:case 4:F(p,0x26c)+=lbl_80542494*(rank-1);break;}
                        break;
                    case 2:
                        switch(rank) {case 1:default:break;case 2:F(p,0x268)+=lbl_80542494;break;
                        case 3:case 4:F(p,0x268)+=lbl_80542494;F(p,0x26c)+=lbl_80542494;break;}
                        break;
                    case 3:
                        if (rank!=1) {
                            if (fn_802353AC(I(p,0x244))==1) V(p,0x268)=V(p,0x274);
                            else switch (I(p,0x244)) {
                            case 0:F(p,0x26c)+=lbl_80542498;break;
                            case 1:F(p,0x268)+=lbl_80542498;break;
                            case 2:F(p,0x268)-=lbl_80542498;break;
                            case 3:F(p,0x26c)-=lbl_80542498;break;
                            }
                        }
                        break;
                    case 4: V(p,0x268)=*fn_8023E724(fn_8022EA0C(I(p,0x244)));break;
                    case 5:break;
                    }
                }
            } else I(p,0x230)=4;
        } else if (owner) V(p,0x268)=V(owner,0xc);
    }
    s16 steps=14;
    if (owner) steps=14;
    V(p,0x28c)=V(p,0x280);
    s16 angle=*(s16*)(p+0x260)+(s32)((f32)(I(p,0x254)<<16)/(f32)steps);
    F(p,0x280)=F(p,0x25c)*JMath::sincosTable_.sinShort(angle)+F(p,0x268);
    F(p,0x284)=F(p,0x25c)*JMath::sincosTable_.cosShort(angle)+F(p,0x26c);
    if (I(p,0x230)==2 || I(p,0x230)==3) {
        fn_801F71A4(&F(p,0xc),F(p,0x280),lbl_80542488,lbl_8054249C);
        fn_801F71A4(&F(p,0x10),F(p,0x284),lbl_80542488,lbl_8054249C);
        if (V(p,0x3c).squared()<lbl_805424A0) V(p,0x3c).zero();
    }
    if ((I(p,0x230)==2 || I(p,0x230)==3) && fn_801F2B7C(p,0,-1,1)) {
        if (I(p,0x230)==3) {I(p,0x234)=30;I(p,0x230)=2;}
        return;
    }
    switch(I(p,0x230)) {
    case 0:
        if (I(p,0x234)<=0) {I(p,0x234)=8;F(p,0x25c)=lbl_805424A4;I(p,0x230)=1;return;}
        F(p,0x298)=F(p,0x280)-F(p,0xc);
        F(p,0x29c)=F(p,0x284)-F(p,0x10);
        if (V(p,0x298).length()>lbl_8054249C) {V(p,0x298).normalize();V(p,0x298).scale(lbl_8054249C);}
        break;
    case 1:
        if (I(p,0x244)>=0 && PSVECDistance(&V(p,0x280),&V(p,0xc))<lbl_80542494) {
            I(p,0x234)=0;I(p,0x230)=2;break;
        }
        {
            f32 speed=lbl_8054249C;
            if (PSVECDistance(&V(p,0xc),&V(p,0x268))>lbl_805424B0) speed=F(p,0x258);
            F(p,0x298)=F(p,0x280)-F(p,0xc);
            F(p,0x29c)=F(p,0x284)-F(p,0x10);
            if (V(p,0x298).length()>speed) {V(p,0x298).normalize();V(p,0x298).scale(speed);}
        }
        if (F(p,0x268)>F(p,0xc)) I(p,0x248)=0;
        else I(p,0x248)=2;
        if (I(p,0x234)<=0) I(p,0x234)=8;
        break;
    case 2:case 3:
        if (I(p,0x244)>=0) {
            if (PSVECDistance(&V(p,0xc),&V(p,0x268))<lbl_805424B4) {
                F(p,0x298)=F(p,0x280)-F(p,0xc);
                F(p,0x29c)=F(p,0x284)-F(p,0x10);
                V(p,0x298).normalize();
                V(p,0x298).scale(lbl_8054249C);
            } else I(p,0x230)=1;
            if (I(p,0x230)==3) {
                if (F(p,0x25c)>lbl_805424B8) {
                    F(p,0x25c)-=lbl_80542480;
                    if (F(p,0x25c)<=lbl_805424B8) F(p,0x25c)=lbl_805424B8;
                }
            } else if (F(p,0x25c)<lbl_805424A4) {
                F(p,0x25c)+=lbl_80542480;
                if (F(p,0x25c)>=lbl_805424A4) F(p,0x25c)=lbl_805424A4;
            }
            if (F(p,0x268)>F(p,0xc)) I(p,0x248)=0;
            else I(p,0x248)=2;
        } else I(p,0x230)=1;
        if (I(p,0x234)<=0) I(p,0x234)=8;
        break;
    case 4:
        if (fn_801F6758(p+0xc,lbl_80542498,I(p,4))
            && fn_801F6758(p+0xc,lbl_80542498,I(p,4))==1) B(p,0x262)=1;
        break;
    }
    I(p,0x238)--;
    if (I(p,0x238)<=0) {
        I(p,0x23c)++;
        I(p,0x23c)&=1;
        I(p,0x238)=2;
    }
    if (I(p,0x234)>0) I(p,0x234)--;
}
#pragma opt_propagation reset
#pragma opt_common_subs reset
extern "C" void fn_80349628(u8* this_) {
    *(s32*)(this_ + 0x108) = 8;
    *(f32*)(this_ + 0x44) = 0.0f;
    *(f32*)(this_ + 0x40) = 0.0f;
    *(f32*)(this_ + 0x3c) = 0.0f;
    *(f32*)(this_ + 0x2a0) = 0.0f;
    *(f32*)(this_ + 0x29c) = 0.0f;
    *(f32*)(this_ + 0x298) = 0.0f;
    *(f32*)(this_ + 0x270) = 0.0f;
    *(f32*)(this_ + 0x26c) = 0.0f;
    *(f32*)(this_ + 0x268) = 0.0f;
    *(f32*)(this_ + 0x27c) = 0.0f;
    *(f32*)(this_ + 0x278) = 0.0f;
    *(f32*)(this_ + 0x274) = 0.0f;
    *(f32*)(this_ + 0x288) = 0.0f;
    *(f32*)(this_ + 0x284) = 0.0f;
    *(f32*)(this_ + 0x280) = 0.0f;
    *(f32*)(this_ + 0x294) = 0.0f;
    *(f32*)(this_ + 0x290) = 0.0f;
    *(f32*)(this_ + 0x28c) = 0.0f;
    *(f32*)(this_ + 0x258) = 5.0f;
    *(f32*)(this_ + 0x25c) = 32.0f;
    *(s32*)(this_ + 0x248) = 0;
    *(s16*)(this_ + 0x260) = 0;
    *(s32*)(this_ + 0x254) = 0;
    *(s32*)(this_ + 0x234) = 0x78;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = -1;
    *(s32*)(this_ + 0x250) = -1;
    *(s32*)(this_ + 0x24c) = -1;
    this_[0x262] = 0;
    this_[0x263] = 0;
    this_[0x264] = 0;
    this_[0x265] = 0;
    *(f32*)(this_ + 0x60) = -8.0f;
    *(f32*)(this_ + 0x64) = -8.0f;
    *(f32*)(this_ + 0x68) = 8.0f;
    *(f32*)(this_ + 0x6c) = 8.0f;
    *(s32*)(this_ + 0x230) = 0;
}
#include "JSystem/JAudio/JASFakeMatchFSA.h"
