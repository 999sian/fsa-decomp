#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JAudio/JASFakeMatchFSA.h"
#include "JSystem/JGeometry/Box.h"


extern "C" char lbl_804ACBF0[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_8035280C(Actor* param_1, s16 param_2)
{
    if (param_1 != 0) {
        *(void**)param_1 = lbl_804ACBF0;
        __dt__5ActorFv(param_1, 0);
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}

extern "C" void fn_8035286C(void)
{
    return;
}

extern "C" char* lbl_8053AB10;
extern "C" char* lbl_8053AAF8;
extern "C" void* fn_801F856C(void);
extern "C" void* fn_801F666C(void* mgr, s32 idx);
extern "C" s32 Actor_CreateByID(void* mgr, u32 name, u32 id, f32* pos, u32 arg5, s32 arg6, s32 arg7);
#include "JSystem/JMath/JMath.h"
#define I(p,o) (*(s32*)((char*)(p)+(o)))
#define U(p,o) (*(u32*)((char*)(p)+(o)))
#define F(p,o) (*(f32*)((char*)(p)+(o)))
#define B(p,o) (*(u8*)((char*)(p)+(o)))
#define V(p,o) (*(JGeometry::TVec3<f32>*)((char*)(p)+(o)))
extern "C" void* lbl_8053AD70;
extern "C" void* lbl_8053AED0;
extern "C" void fn_80134FC4(void*,s32);
extern "C" void fn_80134FBC(void*,s32);
extern "C" void fn_8037AE00(void*);
extern "C" void fn_8037AE30(void*);
extern "C" void fn_8030C380(void*,void*);
extern "C" void fn_801F0E34(void*,s32,s32);
extern "C" s32 fn_801F7A08(void*,u32);
extern "C" void fn_8043D67C(void*,s32,s32,s32);
extern "C" void fn_8043D874(void*,s32,s32,s32);
extern "C" u8 fn_8022F514(s32);
extern "C" void* fn_802D6A9C();
extern "C" void fn_8013A884(u32*);
#pragma auto_inline off
inline f32 turtleRand() {
    return ((JMARandFast*)(lbl_8053AAF8+0xb4))->get_ufloat_1();
}
#pragma opt_common_subs on
extern "C" u32 __cvt_fp2unsigned(f64);
#pragma opt_lifetimes off
#pragma opt_propagation on
extern "C" void fn_80352870(Actor* self)
{
    char* p=(char*)self;
    s32 id;
    u32 param;
    s32 count;
    s32 i;
    s32 offset;
    char* sub;
    s32 state = I(p,0x230);
    if (state != 0 && state != 7) {
        sub = *(char**)(lbl_8053AB10 + 0x30);
        if (B(sub,0x284) == 0) {
            B(sub,0x284) = 1;
            F(sub,0x28c) = 0.05f;
        }
        B(*(char**)(lbl_8053AB10+0x20),0x216)=1;
        B(*(char**)(lbl_8053AB10+0x24),0x17d)=1;
    }
    switch(I(p,0x230)) {
    case 0:
        fn_80134FC4(lbl_8053AAF8,1);
        fn_8037AE00(lbl_8053AD70);
        fn_80134FBC(lbl_8053AAF8,1);
        fn_8030C380(*(void**)(lbl_8053AB10+0x24),p+0x27c);
        F(p,0x264)=F(p,0x28c)-F(p,0x280);
        F(p,0x268)=F(p,0x278)-F(p,0x270);
        F(p,0x260)=F(p,0x264)/F(p,0x268);
        I(p,0x234)=30;
        I(p,0x230)=1;
        break;
    case 1:
        if(I(p,0x234)<=0) {
            JGeometry::TVec3<f32> pos;
            pos.set(32.0f+F(p,0x288),(F(p,0x280)+F(p,0x28c))*0.5f+32.0f,32.0f);
            id=Actor_CreateByID(fn_801F856C(),0x5455544c,0,(f32*)&pos,0x40,-1,-1);
            if(id>=0) {
                char* actor=(char*)fn_801F666C(fn_801F856C(),id);
                if(actor) {
                    JGeometry::TVec3<f32> velocity(-2.0f,0.0f,0.0f);
                    V(actor,0x3c)=velocity;
                    I(p,0x234)=150;
                    V(actor,0x254)=V(p,0x27c);
                    V(actor,0x260)=V(p,0x288);
                    I(p,0x230)=3;
                }
            }
            F(p,0x244)=0.6f*(f32)(U(p,0x23c)>>24);
            F(p,0x248)=0.6f*(f32)((U(p,0x23c)>>16)&255);
            F(p,0x24c)=0.6f*(f32)((U(p,0x23c)>>8)&255);
        } else {
            F(p,0x244)+=F(p,0x254);
            F(p,0x248)+=F(p,0x258);
            F(p,0x24c)+=F(p,0x25c);
        }
        break;
    case 3:
        if(I(p,0x234)<=0) {
            param=(__cvt_fp2unsigned(8.0f*turtleRand())<<4)|1;
            JGeometry::TVec3<f32> pos;
            pos.set(32.0f+F(p,0x288),(F(p,0x280)+F(p,0x28c))*0.5f+54.0f,32.0f);
            id=Actor_CreateByID(fn_801F856C(),0x5455544c,0,(f32*)&pos,param,-1,-1);
            if(id>=0) {
                char* actor=(char*)fn_801F666C(fn_801F856C(),id);
                if(actor) {
                    JGeometry::TVec3<f32> velocity(-2.2f,-0.2f,0.0f);
                    V(actor,0x3c)=velocity;
                    I(p,0x234)=15;
                    V(actor,0x254)=V(p,0x27c);
                    V(actor,0x260)=V(p,0x288);
                    I(p,0x230)=4;
                }
            }
        }
        break;
    case 4:
        if(I(p,0x234)<=0) {
            param=(__cvt_fp2unsigned(8.0f*turtleRand())<<4)|2;
            JGeometry::TVec3<f32> pos;
            pos.set(32.0f+F(p,0x288),(F(p,0x280)+F(p,0x28c))*0.5f+8.0f,32.0f);
            id=Actor_CreateByID(fn_801F856C(),0x5455544c,0,(f32*)&pos,param,-1,-1);
            if(id>=0) {
                char* actor=(char*)fn_801F666C(fn_801F856C(),id);
                if(actor) {
                    JGeometry::TVec3<f32> velocity(-2.3f,0.3f,0.0f);
                    V(actor,0x3c)=velocity;
                    I(p,0x234)=45;
                    V(actor,0x254)=V(p,0x27c);
                    V(actor,0x260)=V(p,0x288);
                    I(p,0x230)=2;
                }
            }
        }
        break;
    case 2:
        if(I(p,0x234)<=0) {
            I(p,0x234)=150;I(p,0x230)=5;
            count=I(fn_801F856C(),0x1008);
            i=0;
            offset=i;
            for(;i<count;offset+=4,i++) {
                Actor* actor=*(Actor**)((char*)fn_801F856C()+offset+8);
                if(actor) {
                    u32 kind=actor->field_1A0;
                    if(kind==0x52555059) {
                        s32 s=I(actor,0x230);
                        if(s==0 || (u32)(s-15)<=1 || (u32)(s-1)<=1 || s==9 || s==13) actor->detach();
                    } else if(kind==0x45535259) {
                        s32 s=I(actor,0x230);
                        if(s==0 || (u32)(s-3)<=1 || s==10) actor->detach();
                    } else if(kind==0x484e5259) {
                        if((I(actor,0x230)==0 || I(actor,0x230)==3 || I(actor,0x230)==4) && !B(actor,0x281)) actor->detach();
                    } else if(kind==0x57445259) actor->detach();
                    else if(kind==0x42525259 && I(actor,0x230)==0) actor->detach();
                }
            }
        }
        break;
    case 5: {
        if(I(p,0x234)<=0) {I(p,0x234)=250;I(p,0x230)=6;}
        param=3;
        if(turtleRand()>0.8f) param=(__cvt_fp2unsigned(8.0f*turtleRand())<<4)|3;
        else param|=0x80;
        f32 rnd=turtleRand();
        JGeometry::TVec3<f32> pos;
        pos.set(32.0f+F(p,0x288),64.0f+F(p,0x270)+(s32)((F(p,0x278)-F(p,0x270)-48.0f)*rnd),32.0f);
        id=Actor_CreateByID(fn_801F856C(),0x5455544c,0,(f32*)&pos,param|0x100,-1,-1);
        I(p,0x238)++;
        if(id>=0) {
            char* actor=(char*)fn_801F666C(fn_801F856C(),id);
            if(actor) {
                JGeometry::TVec3<f32> velocity;
                velocity.set(-2.5f-turtleRand(),0.5f*turtleRand()-0.25f,0.0f);
                V(actor,0x3c)=velocity;
                V(actor,0x254)=V(p,0x27c);
                V(actor,0x260)=V(p,0x288);
            }
        }
        break;
    }
    case 6:
        if(fn_801F7A08(fn_801F856C(),0x5455544c)<0) {
            fn_801F0E34(p,0x5001b,0);
            fn_80134FC4(lbl_8053AAF8,0);
            fn_8037AE30(lbl_8053AD70);
            fn_8043D67C(lbl_8053AED0,0x148,0,0);
            for(i=0;i<4;i++) {
                u8 enabled=(B(lbl_8053AAF8,0x82)&(u8)(1<<i))!=0;
                if(enabled==1 && !fn_8022F514(i))
                    fn_8043D874(lbl_8053AED0,i,-300,1);
            }
            fn_80134FBC(lbl_8053AAF8,0);
            I(p,0x234)=60;I(p,0x230)=7;
            F(p,0x254)=((f32)(U(p,0x240)>>24)-F(p,0x244))/60.0f;
            F(p,0x258)=((f32)((U(p,0x240)>>16)&255)-F(p,0x248))/60.0f;
            F(p,0x25c)=((f32)((U(p,0x240)>>8)&255)-F(p,0x24c))/60.0f;
        }
        break;
    case 7:
        if(I(p,0x234)<=0) {
            if(I(fn_802D6A9C(),4)!=5 || I(fn_802D6A9C(),8)!=0) {
                u32 color=U(p,0x240);fn_8013A884(&color);
            }
            ((Actor*)p)->detach();
            return;
        }
        F(p,0x244)+=F(p,0x254);
        F(p,0x248)+=F(p,0x258);
        F(p,0x24c)+=F(p,0x25c);
        break;
    }
    if(I(fn_802D6A9C(),4)!=5 || I(fn_802D6A9C(),8)!=0) {
        u32 color=((s32)F(p,0x244)<<24)|((s32)F(p,0x248)<<16)|((s32)F(p,0x24c)<<8)|(s32)F(p,0x250);
        fn_8013A884(&color);
    }
    if(I(p,0x234)>0) I(p,0x234)--;
}
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_8018330C(u32* out);
#pragma peephole reset
#pragma opt_propagation reset
#pragma scheduling reset
#pragma exceptions reset
#pragma use_lmw_stmw reset
extern "C" void fn_8035335C(void* this_) {
    char* p = (char*)this_;
    char* mgr;
    u32 buf;
    *(u32*)(p + 0x234) = 0;
    *(u32*)(p + 0x238) = 0;
    mgr = (char*)fn_802D6A9C();
    *(JGeometry::TBox2f*)(p + 0x26c) = *(JGeometry::TBox2f*)(mgr + 0xcc);
    *(u32*)(p + 0x230) = 0;
    fn_8018330C(&buf);
    *(u32*)(p + 0x23c) = buf;
    *(u32*)(p + 0x240) = *(u32*)(p + 0x23c);
    *(f32*)(p + 0x244) = (f32)(*(u32*)(p + 0x23c) >> 24);
    *(f32*)(p + 0x248) = (f32)((*(u32*)(p + 0x23c) >> 16) & 0xff);
    *(f32*)(p + 0x24c) = (f32)((*(u32*)(p + 0x23c) >> 8) & 0xff);
    *(f32*)(p + 0x250) = (f32)(*(u32*)(p + 0x23c) & 0xff);
    *(f32*)(p + 0x254) = -(0.4f * *(f32*)(p + 0x244)) / 30.0f;
    *(f32*)(p + 0x258) = -(0.4f * *(f32*)(p + 0x248)) / 30.0f;
    *(f32*)(p + 0x25c) = -(0.4f * *(f32*)(p + 0x24c)) / 30.0f;
    *(f32*)(p + 0x264) = 0.0f;
    *(f32*)(p + 0x268) = 0.0f;
    *(f32*)(p + 0x260) = 0.0f;
}
extern "C" void fn_803534A0(void) {
}

