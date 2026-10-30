#include "types.h"
#include "JSystem/J2D/J2DScreen.h"
#include "JSystem/J2D/J2DPicture.h"
#include "JSystem/JFramework/JFWDisplay.h"
#include "dolphin/os/OSSerial.h"
extern "C" s32 fn_80427D60(void*);
extern "C" void fn_80427D94(void*);
extern "C" s32 fn_80427DB4(void*,s32);
extern "C" u32 fn_80309C4C(void*,u32,s32);
extern "C" u32 fn_80309D24(void*,s32,u32);
extern "C" u32 fn_80309D6C(void*,s32,u32);
extern "C" u8 fn_80309A00(void*,s32);
extern "C" u8 fn_802B1DCC(void*);
extern "C" void* lbl_8053ACA8;
extern "C" void OSSetProgressiveMode(u32);
extern "C" void fn_80458880(void*,s32,s32);
extern "C" void fn_80458F9C(void*,s32);
extern "C" void* fn_8013CC50(s32,Vec*,s32,s32,s32,s32,s32,s32,f32);
extern "C" f32 lbl_805432E4,lbl_805432F0,lbl_805432F4,lbl_805432DC,lbl_805432F8;
extern "C" s32 fn_8030AAF4(s32);
extern "C" u8 fn_8030A308(void*, s32);
extern "C" u8 fn_8030A388(void*, s32);
extern "C" void* lbl_8053AD30;
extern "C" u8 lbl_8050DB0C[];
extern "C" void* fn_8013C824(void);
extern "C" u32 OSGetProgressiveMode(void);
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void*,void*);


struct TResMgr {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void* get(u32 type, const char* name);
};

extern "C" u8 lbl_80529DEC[];
extern "C" char lbl_80475F58[];
extern "C" u8* lbl_8053AAF8;
extern "C" u8* lbl_8053AB10;
extern "C" u8* lbl_8053AF80;
extern "C" f32 lbl_805432E0;
extern "C" void fn_802FF798(void* mgr);
extern "C" void fn_802F9714(void* mgr, void* res, s32 a, s32 b, s32 c, s32 d);
extern "C" void fn_802F93F4(void* mgr, void* res, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_8016ED88(u8* self);
extern "C" void fn_80458FF0(void* obj, u32 id, s32 a, s32 b);


extern "C" u8* lbl_8053AD88;
extern "C" s32 fn_803A3484(void) {
    if (lbl_8053AD88 != 0) {
        return *(s32*)(lbl_8053AD88 + 0x154);
    }
    return 1;
}

static inline f32 titleAddStep(f32& value, const f32 step, const f32 bound) {
    value += step;
    return bound;
}
static inline f32 titleSubStep(f32& value, const f32 step, const f32 bound) {
    value -= step;
    return bound;
}
extern "C" void fn_803A34A0(u8* p) {
if(*(s16*)(p+0x6c)!=0) {
    s32 status=fn_80427D60(*(void**)(p+0x48));
    u8 done=0;
    if(*(s16*)(p+0x6c)==2){
        s32 elapsed=((u32(*)())*(void**)((u8*)*(void**)(p+0x48)+0x18))();
        elapsed-=((u32(*)())*(void**)((u8*)*(void**)(p+0x48)+0x10))();
        if(*(s16*)(p+0x80)!=0)++*(s16*)(p+0x80);
        if(elapsed>=150 && ((u32(*)())*(void**)((u8*)*(void**)(p+0x48)+0x18))()>(u32)elapsed){
            if(*(u32*)(lbl_8053AF80+0x58)!=0x1000006){fn_80458FF0(lbl_8053AF80,0x1000006,0,0);++*(s16*)(p+0x80);}
            if(lbl_80529DEC[0x250]==1)done=1;
        }
        if(elapsed>=200 && ((u32(*)())*(void**)((u8*)*(void**)(p+0x48)+0x18))()>(u32)elapsed){if(!*(void**)(p+0x44)){Vec v;v.x=lbl_805432E0;v.y=lbl_805432E0;v.z=lbl_805432E0;*(void**)(p+0x44)=fn_8013CC50(0,&v,0x48e,0,0,0,0,1,lbl_805432E4);*(u32*)((u8*)*(void**)(p+0x44)+0xf4)|=0x40;}
}
        if(elapsed>=201 && ((u32(*)())*(void**)((u8*)*(void**)(p+0x48)+0x18))()>(u32)elapsed){lbl_80529DEC[0x249]=1;done=1;*(s16*)(p+0x80)=0;}
    }else if(((u32(*)())*(void**)((u8*)*(void**)(p+0x48)+0x10))()==0)done=1;
    if(fn_80309C4C(lbl_8053AD30,0x1100,1)) {if(*(s16*)(p+0x6c)==2){lbl_80529DEC[0x249]=1;if(*(s16*)(p+0x6a)<120)*(s16*)(p+0x6a)=153;}
fn_80427D94(*(void**)(p+0x48));
if(*(s16*)(p+0x6c)==2)*(s32*)(p+0x58)=0;
else {++*(s32*)(p+0x58);if(*(s32*)(p+0x58)>=2)*(s32*)(p+0x58)=0;}
*(s16*)(p+0x6c)=0;*(s16*)(p+0x7a)=0;*(s16*)(p+0x7e)=0;p[0x14d]=0;*(s32*)(p+0x5c)=0;*(s16*)(p+0x7c)=0;*(s16*)(p+0x80)=0;*(s32*)(p+0x60)=0;*(s32*)(p+0x64)=0;
if(*(s16*)(p+0x6e)!=3 && *(u32*)(lbl_8053AF80+0x58)!=0x1000006)fn_80458FF0(lbl_8053AF80,0x1000006,0,0);
}
    else if(done || fn_802B1DCC(lbl_8053ACA8) || status==0){if(*(s16*)(p+0x6c)==2){lbl_80529DEC[0x249]=1;if(*(s16*)(p+0x6a)<120)*(s16*)(p+0x6a)=153;}
fn_80427D94(*(void**)(p+0x48));
if(*(s16*)(p+0x6c)==2)*(s32*)(p+0x58)=0;
else {++*(s32*)(p+0x58);if(*(s32*)(p+0x58)>=2)*(s32*)(p+0x58)=0;}
*(s16*)(p+0x6c)=0;*(s16*)(p+0x7a)=0;*(s16*)(p+0x7e)=0;p[0x14d]=0;*(s32*)(p+0x5c)=0;*(s16*)(p+0x7c)=0;*(s16*)(p+0x80)=0;*(s32*)(p+0x60)=0;*(s32*)(p+0x64)=0;
if(*(s16*)(p+0x6e)!=3 && *(u32*)(lbl_8053AF80+0x58)!=0x1000006)fn_80458FF0(lbl_8053AF80,0x1000006,0,0);
}
}else{
    switch(*(s16*)(p+0x6e)){
    case 0:{
        f32 cur=*(f32*)(p+0x4c);f32 step=lbl_805432F0;const f32 limit=lbl_805432F4;
*(f32*)(p+0x4c)=cur+step;
        if(*(f32*)(p+0x4c)>=limit){*(f32*)(p+0x4c)=limit;++*(s16*)(p+0x6e);}
        break;
    }case 1:if(lbl_80529DEC[0x238]==4)++*(s16*)(p+0x6e);break;
    case 2:{f32 cur=*(f32*)(p+0x4c);f32 step=lbl_805432F0;const f32 limit=lbl_805432E0;
*(f32*)(p+0x4c)=cur-step;if(*(f32*)(p+0x4c)<=limit)*(f32*)(p+0x4c)=limit;break;}
    }
    if(lbl_80529DEC[0x238]==1){
        if(SIProbe(0)!=0x40000){++*(s16*)(p+0x78);if(*(s16*)(p+0x78)>=48){lbl_80529DEC[0x238]=255;lbl_80529DEC[0x226]=1;OSSetProgressiveMode(0);}}else *(s16*)(p+0x78)=0;
        if(fn_80309A00(lbl_8053AD30,fn_8030AAF4(0))==1){
            ++*(s16*)(p+0x76);
            if(*(s16*)(p+0x76)>=48){
                if(OSGetProgressiveMode()==1)lbl_80529DEC[0x238]=2;else {lbl_80529DEC[0x238]=255;lbl_80529DEC[0x226]=1;OSSetProgressiveMode(0);}
                *(s16*)(p+0x74)=0;*(s16*)(p+0x76)=0;
            }
        }else *(s16*)(p+0x76)=0;
        if(lbl_80529DEC[0x238]==1 && fn_8030A308(lbl_8053AD30,fn_8030AAF4(0))){
            if(*(s16*)(p+0x74)<3){
                ++*(s16*)(p+0x74);
                if(OSGetProgressiveMode()==1 || fn_80309D24(lbl_8053AD30,fn_8030AAF4(0),0x200)){
                    lbl_80529DEC[0x238]=2;*(s16*)(p+0x74)=0;
                }
            }else {lbl_80529DEC[0x238]=255;lbl_80529DEC[0x226]=1;OSSetProgressiveMode(0);*(s16*)(p+0x74)=0;}
        }
    }
    if(lbl_80529DEC[0x238]==255){
        if(lbl_80529DEC[0x249]!=0) {
            if((fn_8030A308(lbl_8053AD30,fn_8030AAF4(0))||fn_8030A388(lbl_8053AD30,fn_8030AAF4(0))) && *(s16*)(p+0x82)<=0 && fn_80309C4C(lbl_8053AD30,0x1100,1)){
                fn_80458880(lbl_8053AF80,11,-1);*(s32*)(p+0x154)=2;fn_80458F9C(lbl_8053AF80,60);*(s32*)(lbl_80529DEC+0x1a0)=60;*(s16*)(p+0x6e)=3;
            }else{
                ++*(s32*)(p+0x60);
                if(*(s32*)(p+0x60)==*(s16*)(lbl_8050DB0C+0x236)+7440)fn_80458F9C(lbl_8053AF80,60);
                else if(*(s32*)(p+0x60)>=*(s16*)(lbl_8050DB0C+0x236)+7500){
                    if(fn_80427DB4(*(void**)(p+0x48),*(s32*)(p+0x58)))*(s16*)(p+0x6c)=1;
                    else {fn_80427D94(*(void**)(p+0x48));
if(*(s16*)(p+0x6c)==2)*(s32*)(p+0x58)=0;
else {++*(s32*)(p+0x58);if(*(s32*)(p+0x58)>=2)*(s32*)(p+0x58)=0;}
*(s16*)(p+0x6c)=0;*(s16*)(p+0x7a)=0;*(s16*)(p+0x7e)=0;p[0x14d]=0;*(s32*)(p+0x5c)=0;*(s16*)(p+0x7c)=0;*(s16*)(p+0x80)=0;*(s32*)(p+0x60)=0;*(s32*)(p+0x64)=0;
if(*(s16*)(p+0x6e)!=3 && *(u32*)(lbl_8053AF80+0x58)!=0x1000006)fn_80458FF0(lbl_8053AF80,0x1000006,0,0);
}
                }
            }
        }else if(fn_80427DB4(*(void**)(p+0x48),3)){lbl_80529DEC[0x250]=0;*(s16*)(p+0x6c)=2;}
    }else{
        switch(lbl_80529DEC[0x238]){
        case 2:{f32 cur=*(f32*)(p+0x50);f32 step=lbl_805432F0;const f32 limit=lbl_805432F4;
*(f32*)(p+0x50)=cur+step;if(*(f32*)(p+0x50)>=limit){*(f32*)(p+0x50)=limit;lbl_80529DEC[0x238]=3;}break;
        }case 3:
            ++*(s16*)(p+0x74);
            if(fn_80309D6C(lbl_8053AD30,fn_8030AAF4(0),0x100) || *(s16*)(p+0x74)>=600)lbl_80529DEC[0x238]=4;
            else if(fn_80309D6C(lbl_8053AD30,fn_8030AAF4(0),2)){p[0x14c]=1;*(s16*)(p+0x72)=30;}
            else if(fn_80309D6C(lbl_8053AD30,fn_8030AAF4(0),1)){p[0x14c]=0;*(s16*)(p+0x72)=30;}
            ++*(s16*)(p+0x72);if(*(s16*)(p+0x72)>60)*(s16*)(p+0x72)=0;break;
        case 4:{
            if(*(s16*)(p+0x6e)!=2)break;
            f32 cur=*(f32*)(p+0x50);f32 step=lbl_805432F0;const f32 limit=lbl_805432E0;
*(f32*)(p+0x50)=cur-step;
            if(*(f32*)(p+0x50)<=limit){
                *(f32*)(p+0x50)=limit;
                if(p[0x14c]==0){*(s16*)(p+0x72)=0;if(OSGetProgressiveMode()==1){lbl_80529DEC[0x238]=6;OSSetProgressiveMode(1);}else {lbl_80529DEC[0x238]=5;OSSetProgressiveMode(1);}}
                else if(OSGetProgressiveMode()==1){lbl_80529DEC[0x238]=9;*(s16*)(p+0x6e)=0;OSSetProgressiveMode(0);}
                else {lbl_80529DEC[0x238]=9;*(s16*)(p+0x6e)=0;}
            }break;
        }case 5:lbl_80529DEC[0x238]=7;break;
        case 6:lbl_80529DEC[0x238]=8;break;
        case 7:case 8:++*(s16*)(p+0x72);if(lbl_80529DEC[0x251]>90 && *(s16*)(p+0x72)>=90){lbl_80529DEC[0x238]=9;*(s16*)(p+0x6e)=0;lbl_80529DEC[0x251]=0;}break;
        case 9:{f32 cur=*(f32*)(p+0x50);f32 step=lbl_805432F0;const f32 limit=lbl_805432F4;
*(f32*)(p+0x50)=cur+step;if(*(f32*)(p+0x50)>=limit){*(f32*)(p+0x50)=limit;lbl_80529DEC[0x238]=10;*(s16*)(p+0x72)=0;}break;
        }case 10:++*(s16*)(p+0x72);if(*(s16*)(p+0x72)>=120){*(f32*)(p+0x50)=lbl_805432DC;lbl_80529DEC[0x238]=11;}break;
        case 11:{f32 cur=*(f32*)(p+0x50);f32 step=lbl_805432F0;const f32 limit=lbl_805432E0;
*(f32*)(p+0x50)=cur-step;if(*(f32*)(p+0x50)<=limit){*(f32*)(p+0x50)=limit;lbl_80529DEC[0x238]=255;lbl_80529DEC[0x226]=1;}break;}
        }
    }
}
if(lbl_80529DEC[0x238]==255) {
    ++*(s32*)(p+0x5c);
    if(*(s32*)(p+0x5c)==1){if(!*(void**)(p+0x28)){Vec v;v.x=lbl_805432E0;v.y=lbl_805432E0;v.z=lbl_805432E0;*(void**)(p+0x28)=fn_8013CC50(0,&v,0x493,0,0,0,0,1,lbl_805432E4);*(u32*)((u8*)*(void**)(p+0x28)+0xf4)|=0x40;}
if(!*(void**)(p+0x2c)){Vec v;v.x=lbl_805432E0;v.y=lbl_805432E0;v.z=lbl_805432E0;*(void**)(p+0x2c)=fn_8013CC50(0,&v,0x494,0,0,0,0,1,lbl_805432E4);*(u32*)((u8*)*(void**)(p+0x2c)+0xf4)|=0x40;}
if(!*(void**)(p+0x30)){Vec v;v.x=lbl_805432E0;v.y=lbl_805432E0;v.z=lbl_805432E0;*(void**)(p+0x30)=fn_8013CC50(0,&v,0x495,0,0,0,0,1,lbl_805432E4);*(u32*)((u8*)*(void**)(p+0x30)+0xf4)|=0x40;}
}
    if(*(s16*)(p+0x6c)!=0){
for(s32 i=0;i<3;i++){if(*(void**)(p+0x28+i*4)){{void* manager=*(void**)((u8*)fn_8013C824()+0xc);forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(manager,*(void**)(p+0x28+i*4));}*(void**)(p+0x28+i*4)=0;}}
for(s32 i=0;i<4;i++){if(*(void**)(p+0x34+i*4)){{void* manager=*(void**)((u8*)fn_8013C824()+0xc);forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(manager,*(void**)(p+0x34+i*4));}*(void**)(p+0x34+i*4)=0;}}
    }else{
        if(*(s32*)(p+0x5c)>=55){
            s32 t=*(s32*)(p+0x5c)-55;
            if(t==0){if(!*(void**)(p+0x34)){Vec v;v.x=lbl_805432E0;v.y=lbl_805432E0;v.z=lbl_805432E0;*(void**)(p+0x34)=fn_8013CC50(0,&v,0x490,0,0,0,0,1,lbl_805432E4);*(u32*)((u8*)*(void**)(p+0x34)+0xf4)|=0x40;}
if(!*(void**)(p+0x38)){Vec v;v.x=lbl_805432E0;v.y=lbl_805432E0;v.z=lbl_805432E0;*(void**)(p+0x38)=fn_8013CC50(0,&v,0x48f,0,0,0,0,1,lbl_805432E4);*(u32*)((u8*)*(void**)(p+0x38)+0xf4)|=0x40;}
if(!*(void**)(p+0x3c)){Vec v;v.x=lbl_805432E0;v.y=lbl_805432E0;v.z=lbl_805432E0;*(void**)(p+0x3c)=fn_8013CC50(0,&v,0x492,0,0,0,0,1,lbl_805432E4);*(u32*)((u8*)*(void**)(p+0x3c)+0xf4)|=0x40;}
if(!*(void**)(p+0x40)){Vec v;v.x=lbl_805432E0;v.y=lbl_805432E0;v.z=lbl_805432E0;*(void**)(p+0x40)=fn_8013CC50(0,&v,0x491,0,0,0,0,1,lbl_805432E4);*(u32*)((u8*)*(void**)(p+0x40)+0xf4)|=0x40;}
}
            if(t<*(s16*)((u8*)*(void**)(p+0x24)+6))*(f32*)((u8*)*(void**)(p+0x24)+8)=(f32)t;
            else {
                u32* seed=(u32*)(lbl_8053AAF8+0xb4);
                f32 one=lbl_805432E4;
                f32 scale=lbl_805432F8;
                *seed=*seed*0x19660d+0x3c6ef35f;
                u32 bits=(*seed>>9)|0x3f800000;
                s32 frames=*(s16*)((u8*)*(void**)(p+0x24)+6);
                s32 r=(s32)(scale*(*(f32*)&bits-one));
                if(t>=r+frames+400)*(s32*)(p+0x5c)=0;
                *(f32*)((u8*)*(void**)(p+0x24)+8)=lbl_805432E0;
            }
        }else *(f32*)((u8*)*(void**)(p+0x24)+8)=lbl_805432E0;
        (*(J2DScreen**)(p+4))->animation();
for(s32 i=0;i<3;i++){if(*(u8**)(p+0x28+i*4)){
u8* em=*(u8**)(p+0x28+i*4);u8 ready=0;
if((*(u32*)(em+0xf4)&8) && *(s32*)(em+0xd0)+*(s32*)(em+0xdc)==0)ready=1;
if(ready){{void* manager=*(void**)((u8*)fn_8013C824()+0xc);forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(manager,*(void**)(p+0x28+i*4));}*(void**)(p+0x28+i*4)=0;}
}
}
for(s32 i=0;i<4;i++){if(*(u8**)(p+0x34+i*4)){
u8* em=*(u8**)(p+0x34+i*4);u8 ready=0;
if((*(u32*)(em+0xf4)&8) && *(s32*)(em+0xd0)+*(s32*)(em+0xdc)==0)ready=1;
if(ready){{void* manager=*(void**)((u8*)fn_8013C824()+0xc);forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(manager,*(void**)(p+0x34+i*4));}*(void**)(p+0x34+i*4)=0;}
}
}
    }
}
if(*(u8**)(p+0x44)){
u8* em=*(u8**)(p+0x44);u8 ready=0;
if((*(u32*)(em+0xf4)&8) && *(s32*)(em+0xd0)+*(s32*)(em+0xdc)==0)ready=1;
if(ready){{void* manager=*(void**)((u8*)fn_8013C824()+0xc);forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(manager,*(void**)(p+0x44));}*(void**)(p+0x44)=0;}
}

if(p[0x150]==1){++*(s16*)(p+0x6a);if(*(s16*)(p+0x6a)>=154){*(s16*)(p+0x68)-=10;if(*(s16*)(p+0x68)<=0){*(s16*)(p+0x68)=0;p[0x150]=0;}}}
lbl_80529DEC[0x250]=0;
}

extern "C" u8* sManager__10JFWDisplay;
extern "C" void fn_8013B438(void* p);
extern "C" void fn_8013B490(void* p);
extern "C" void fn_80427D2C(void* p, s32 a, s32 b, s32 c, s32 d);
extern "C" s32 fn_8030AAF4(s32);
extern "C" u8 fn_8030A308(void*, s32);
extern "C" u8 fn_8030A388(void*, s32);
extern "C" void* lbl_8053AD30;
extern "C" u8 lbl_8050DB0C[];
extern "C" void* fn_8013C824(void);
extern "C" void fn_8013AC54(Mtx);
extern "C" void fn_8013ABCC(void*, Vec*, Mtx);
extern "C" void fn_8013AB2C(void);
extern "C" void fn_8013AB00(void*);
extern "C" void fn_8013AAD4(void*);
extern "C" void fn_8016D398(void*, void*, s32, s32, void*, void*, void*, void*, void*, void*, f32);
extern "C" void calc__17JPAEmitterManagerFUc(void*, u8);
extern "C" void draw__17JPAEmitterManagerFPC11JPADrawInfoUc(void*, void*, u8);
extern "C" u32 OSGetProgressiveMode(void);
static inline void titleFadePulse(u8* self,f32& value) {
    s32 hold=*(s16*)(lbl_8050DB0C+0x29e);
    s32 period=*(s16*)(lbl_8050DB0C+0x29c);
    s32 twice=2*period;
    ++*(s16*)(self+0x7c);
    s32 t=*(s16*)(self+0x7c);
    if(t<=twice) {
        s32 d;
        if(t<period) d=period-t; else d=t-period;
        f32 base=(f32)*(s16*)(lbl_8050DB0C+0x2a0)/255.0f;
        value=base+((1.0f-base)*(f32)(d*d))/(f32)(period*period);
    } else {
        value=1.0f;
        if(t>=hold+twice) *(s16*)(self+0x7c)=0;
    }
}

static inline void setTitleAlpha(J2DPane* pane,const f32 alpha) { pane->setAlpha((u8)alpha); }

static inline void drawTitleScreen(u8* self, f32 scale, BOOL showLogo) {
    (*(J2DScreen**)(self + 0x4))->search(0x506e7464)->setAlpha((u8)*(f32*)(self + 0x4c));
    (*(J2DScreen**)(self + 0x4))->search(0x50746c6f676f3031ULL)->setAlpha(showLogo ? (u8)*(f32*)(self + 0x4c) : 0);
    (*(J2DScreen**)(self + 0x4))->search(0x50746c6f676f3032ULL)->setAlpha(showLogo ? (u8)*(f32*)(self + 0x4c) : 0);
    (*(J2DScreen**)(self + 0x4))->search(0x7072737374727431ULL)->setAlpha((u8)(self[0x14e] * scale));
    (*(J2DScreen**)(self + 0x4))->search(0x7072737374727432ULL)->setAlpha((u8)(self[0x14f] * scale));
    (*(J2DScreen**)(self + 0x4))->draw(0.0f, 0.0f, *(const J2DGrafContext**)(lbl_8053AB10 + 0x10));
}
#pragma opt_lifetimes on
extern "C" void fn_803A44D8(u8* this_) {
    f32 scale = 0.0f;
    JFWDisplay::getManager()->setClearColor(JUtility::TColor(0, 0, 0, 0));
    if (*(s32*)(lbl_80529DEC + 0x1a0) > 0) {
        *(s32*)(lbl_80529DEC + 0x1a0) -= 1;
    } else {
        *(s32*)(lbl_80529DEC + 0x1a0) = 0;
    }
    if (*(s16*)(this_ + 0x6c) != 0) {
        fn_8013B438(lbl_8053AB10);
        fn_80427D2C(*(void**)(this_ + 0x48), 0, 0, 0, 0);
        if (lbl_80529DEC[0x249] != 0 && *(s16*)(this_ + 0x80) != 0) {
            if ((fn_8030A308(lbl_8053AD30, fn_8030AAF4(0)) || fn_8030A388(lbl_8053AD30, fn_8030AAF4(0))) && *(s16*)(this_ + 0x82) == 0) {
                titleFadePulse(this_,scale);
            }
            fn_8013B490(lbl_8053AB10);
            drawTitleScreen(this_, scale, FALSE);
        }
    } else {
        fn_8013B490(lbl_8053AB10);
        u8 mode = lbl_80529DEC[0x238];
        if (mode == 0xff && lbl_80529DEC[0x249] != 0) {
            if (*(s32*)(this_ + 0x154) == 1) {
                Vec scl;
                Mtx info[2];
                Mtx m;
                scl.x=7.0f; scl.y=7.0f; scl.z=7.0f;
                void* mgr = *(void**)((u8*)fn_8013C824() + 0xc);
                PSMTXIdentity(info[0]);
                PSMTXIdentity(info[1]);
                PSMTXIdentity(m);
                fn_8013AC54(m);
                PSMTXCopy(m, info[0]);
                C_MTXLightOrtho(info[1], 448.0f, 0.0f, 0.0f, 608.0f, 0.5f, 0.5f, 0.5f, 0.5f);
                fn_8016D398(m, *(void**)(lbl_8053AAF8 + 0x5c), 1, 1, this_ + 0x90, this_ + 0x84, this_ + 0x88, this_ + 0x8c, this_ + 0x11c, this_ + 0x134, 7.0f);
                u8* p = this_;
                for (s32 i = 0; i < 6; i++) {
                    void* emitter=*(void**)(p+0x104);
                    m[0][0] = 1.0f;
                    m[0][1] = 0.0f;
                    m[0][2] = 0.0f;
                    m[0][3] = 300.0f;
                    m[1][0] = 0.0f;
                    m[1][1] = 0.0f;
                    m[1][2] = 1.0f;
                    m[1][3] = 250.0f;
                    m[2][0] = 0.0f;
                    m[2][1] = 1.0f;
                    m[2][2] = 0.0f;
                    m[2][3] = -513.0f - 96.0f * i;
                    fn_8013ABCC(emitter, &scl, m);
                    p += 4;
                }
                fn_8013AB2C();
                calc__17JPAEmitterManagerFUc(mgr, 0);
                draw__17JPAEmitterManagerFPC11JPADrawInfoUc(mgr, info, 0);
            }
            if (this_[0x150] == 1) {
                fn_8013B490(lbl_8053AB10);
                (*(J2DPicture**)(this_ + 0x20))->setAlpha((u8)*(s16*)(this_ + 0x68));
                (*(J2DPicture**)(this_ + 0x20))->draw(-1.0f, -1.0f, 611.0f, 451.0f, false, false, false);
            }
            if (*(s16*)(this_ + 0x6e) == 1) {
                if ((fn_8030A308(lbl_8053AD30, fn_8030AAF4(0)) || fn_8030A388(lbl_8053AD30, fn_8030AAF4(0))) && *(s16*)(this_ + 0x82) == 0) {
                    titleFadePulse(this_,scale);
                }
            }
            drawTitleScreen(this_, scale, TRUE);
            if (*(s16*)(this_ + 0x82) > 0 && 255.0f == *(f32*)(this_ + 0x4c)) {
                (*(s16*)(this_ + 0x82))--;
            }
        } else {
            switch (mode) {
            case 2:
            case 3:
            case 4: {
                setTitleAlpha(*(J2DPicture**)(this_ + 0xc),*(f32*)(this_+0x50));
                (*(J2DPicture**)(this_ + 0xc))->draw(113.0f, 281.0f, false, false, false);
                s16 t = *(s16*)(this_ + 0x72);
                f32 r;
                if (t < 30) {
                    r = (f32)t / 30.0f;
                } else {
                    r = (60.0f - (f32)t) / 30.0f;
                }
                s32 g = 255.0f * r;
                s32 b = 200.0f * r;
                if (this_[0x14c] == 0) {
                    (*(J2DPicture**)(this_ + 0x18))->setBlackWhite(JUtility::TColor(g, b, 0, 0), JUtility::TColor(0xff, 0xc8, 0, 0xff));
                    (*(J2DPicture**)(this_ + 0x1c))->setBlackWhite(JUtility::TColor(0, 0, 0, 0), JUtility::TColor(0xa0, 0xa0, 0xa0, 0xff));
                } else {
                    (*(J2DPicture**)(this_ + 0x18))->setBlackWhite(JUtility::TColor(0, 0, 0, 0), JUtility::TColor(0xa0, 0xa0, 0xa0, 0xff));
                    (*(J2DPicture**)(this_ + 0x1c))->setBlackWhite(JUtility::TColor(g, b, 0, 0), JUtility::TColor(0xff, 0xc8, 0, 0xff));
                }
                setTitleAlpha(*(J2DPicture**)(this_ + 0x18),*(f32*)(this_+0x50));
                (*(J2DPicture**)(this_ + 0x18))->draw(211.0f, 372.0f, false, false, false);
                setTitleAlpha(*(J2DPicture**)(this_ + 0x1c),*(f32*)(this_+0x50));
                (*(J2DPicture**)(this_ + 0x1c))->draw(350.0f, 372.0f, false, false, false);
                break;
            }
            case 5:
            case 6:
                fn_8013AB00(lbl_8053AB10);
                lbl_80529DEC[0x251] = 1;
                break;
            case 9:
                if (!OSGetProgressiveMode()) {
                    fn_8013AAD4(lbl_8053AB10);
                }
            case 10:
            case 11:
                if (this_[0x14c] == 0) {
                    setTitleAlpha(*(J2DPicture**)(this_ + 0x14),*(f32*)(this_+0x50));
                    (*(J2DPicture**)(this_ + 0x14))->draw(153.0f, 309.0f, false, false, false);
                } else {
                    setTitleAlpha(*(J2DPicture**)(this_ + 0x10),*(f32*)(this_+0x50));
                    (*(J2DPicture**)(this_ + 0x10))->draw(153.0f, 309.0f, false, false, false);
                }
                break;
            default:
                if (lbl_80529DEC[0x249] != 0) {
                    drawTitleScreen(this_, scale, TRUE);
                    if (*(s16*)(this_ + 0x82) > 0 && 255.0f == *(f32*)(this_ + 0x4c)) {
                        (*(s16*)(this_ + 0x82))--;
                    }
                }
                break;
            }
        }
    }
}
#pragma opt_lifetimes reset
extern "C" void fn_803A5380(u8* this_) {
    char* base = lbl_80475F58;
    if (lbl_80529DEC[0x242] == 0) {
        lbl_80529DEC[0x242] = 1;
        fn_802FF798(*(void**)(lbl_8053AB10 + 0x20));
        void* res = ((TResMgr*)*(void**)(lbl_8053AAF8 + 0xa4))->get(0x53434820, base + 0xfc);
        fn_802F9714(*(void**)(lbl_8053AB10 + 0x20), res, 0, 0, 0, 0);
        res = ((TResMgr*)*(void**)(lbl_8053AAF8 + 0xa4))->get(0x53434820, base + 0x114);
        fn_802F9714(*(void**)(lbl_8053AB10 + 0x20), res, 0, 0, 0x7000, 0);
        res = ((TResMgr*)*(void**)(lbl_8053AAF8 + 0xa4))->get(0x53434c20, base + 0x12c);
        fn_802F93F4(*(void**)(lbl_8053AB10 + 0x20), res, 0, 0, 0, 0, 0);
        res = ((TResMgr*)*(void**)(lbl_8053AAF8 + 0xa4))->get(0x53434820, base + 0x144);
        fn_802F9714(*(void**)(lbl_8053AB10 + 0x20), res, 0, 2, 0x4000, 0);
        res = ((TResMgr*)*(void**)(lbl_8053AAF8 + 0xa4))->get(0x53434c20, base + 0x12c);
        fn_802F93F4(*(void**)(lbl_8053AB10 + 0x20), res, 0, 2, 0, 0, 0);
        res = ((TResMgr*)*(void**)(lbl_8053AAF8 + 0xa4))->get(0x53434820, base + 0x154);
        fn_802F9714(*(void**)(lbl_8053AB10 + 0x20), res, 0, 3, 0, 0);
        res = ((TResMgr*)*(void**)(lbl_8053AAF8 + 0xa4))->get(0x53434c20, base + 0x12c);
        fn_802F93F4(*(void**)(lbl_8053AB10 + 0x20), res, 0, 3, 0, 0, 0);
        *(u8*)(*(u8**)(lbl_8053AB10 + 0x20) + 0x2364) = 1;
    }
    *(s32*)(this_ + 0x154) = 1;
    this_[0x14c] = 0;
    *(f32*)(this_ + 0x50) = 0.0f;
    *(f32*)(this_ + 0x4c) = 0.0f;
    *(s16*)(this_ + 0x6e) = 0;
    *(s16*)(this_ + 0x72) = 0;
    *(s16*)(this_ + 0x7a) = 0;
    *(s16*)(this_ + 0x7e) = 0;
    this_[0x14d] = 0;
    *(s16*)(this_ + 0x74) = 0;
    *(s16*)(this_ + 0x76) = 0;
    *(s16*)(this_ + 0x78) = 0;
    *(s32*)(this_ + 0x60) = 0;
    *(s32*)(this_ + 0x64) = 0;
    *(s16*)(this_ + 0x6c) = 0;
    *(s32*)(this_ + 0x5c) = 0;
    *(s16*)(this_ + 0x7c) = 0;
    *(s16*)(this_ + 0x80) = 0;
    *(s16*)(this_ + 0x82) = 0x3c;
    *(s32*)(this_ + 0x54) = 0;
    if (lbl_80529DEC[0x249] != 0) {
        *(s16*)(this_ + 0x68) = 0;
    } else {
        *(s16*)(this_ + 0x68) = 0xff;
    }
    *(s16*)(this_ + 0x6a) = 0;
    this_[0x150] = 0;
    *(s32*)(this_ + 0x84) = 0x78;
    *(s32*)(this_ + 0x88) = 0x3c;
    this_[0x8c] = 1;
    fn_8016ED88(this_ + 0x90);
    if (lbl_80529DEC[0x249] != 0) {
        if (*(u32*)(lbl_8053AF80 + 0x58) != 0x1000006) {
            fn_80458FF0(lbl_8053AF80, 0x1000006, 0, 0);
        }
        *(s16*)(this_ + 0x82) = 0x3c;
    }
}

extern "C" u8 lbl_804AF820[];
extern "C" u8 lbl_80529DEC[];
extern "C" void* fn_8013C824(void);
extern "C" void fn_80427D94(void*);
extern "C" void getTotalFreeSize__7JKRHeapFv(void*);
extern "C" void destroy__7JKRHeapFv(void*);
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void* mgr, void* em);
extern "C" void forceDeleteAllEmitter__17JPAEmitterManagerFv(void* mgr);
struct TDelObj {
    virtual ~TDelObj();
};
struct TPadBase8 {
    u8 pad[8];
};
struct TSlotObj : TPadBase8 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10(s32);
};
struct TSysObj {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
};
#pragma opt_common_subs off
extern "C" u8* fn_803A56C4(u8* p, s16 n) {
    if (p != NULL) {
        *(void**)p = lbl_804AF820;
        getTotalFreeSize__7JKRHeapFv(*(void**)(lbl_80529DEC + 0x8));
        for (s32 i = 0; i < 4; i++) {
            TSlotObj* obj = *(TSlotObj**)(p + i * 0x1c + 0xa8);
            if (obj != NULL) {
                if (obj != NULL) {
                    obj->m10(1);
                }
            }
        }
        if (*(s16*)(p + 0x6c) != 0) {
            fn_80427D94(*(void**)(p + 0x48));
            *(s16*)(p + 0x6c) = 0;
        }
        for (s32 i = 0; i < 3; i++) {
            if (*(void**)(p + 0x28 + i * 4) != NULL) {
                forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((u8*)fn_8013C824() + 0xc), *(void**)(p + 0x28 + i * 4));
                *(void**)(p + 0x28 + i * 4) = NULL;
            }
        }
        for (s32 i = 0; i < 4; i++) {
            if (*(void**)(p + 0x34 + i * 4) != NULL) {
                forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((u8*)fn_8013C824() + 0xc), *(void**)(p + 0x34 + i * 4));
                *(void**)(p + 0x34 + i * 4) = NULL;
            }
        }
        if (*(void**)(p + 0x44) != NULL) {
            forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((u8*)fn_8013C824() + 0xc), *(void**)(p + 0x44));
            *(void**)(p + 0x44) = NULL;
        }
        forceDeleteAllEmitter__17JPAEmitterManagerFv(*(void**)((u8*)fn_8013C824() + 0xc));
        destroy__7JKRHeapFv(*(void**)(p + 0x100));
        delete *(TDelObj**)(p + 0x4);
        *(void**)(p + 0x4) = NULL;
        delete *(TDelObj**)(p + 0x24);
        *(void**)(p + 0x24) = NULL;
        delete *(TDelObj**)(p + 0x8);
        *(void**)(p + 0x8) = NULL;
        delete *(TDelObj**)(p + 0x48);
        *(void**)(p + 0x48) = NULL;
        delete *(TDelObj**)(p + 0xc);
        *(void**)(p + 0xc) = NULL;
        delete *(TDelObj**)(p + 0x10);
        *(void**)(p + 0x10) = NULL;
        delete *(TDelObj**)(p + 0x14);
        *(void**)(p + 0x14) = NULL;
        delete *(TDelObj**)(p + 0x18);
        *(void**)(p + 0x18) = NULL;
        delete *(TDelObj**)(p + 0x1c);
        *(void**)(p + 0x1c) = NULL;
        delete *(TDelObj**)(p + 0x20);
        *(void**)(p + 0x20) = NULL;
        (*(TSysObj**)(lbl_80529DEC + 0x24))->m7();
        lbl_8053AD88 = NULL;
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
#pragma opt_common_subs reset
extern "C" u32 lbl_804AF7D8[][3];
extern "C" u8* sCurrentHeap__7JKRHeap;
extern "C" void fn_8016FDE0(void);
extern "C" void* fn_80428030(void* this_ = 0);
extern "C" void* __nw__FUl(u32 size);
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void __ct__9J2DScreenFv(void* self);
extern "C" void __ct__10J2DPictureFPC7ResTIMG(void* self, const void* res);
extern "C" void __ct__14WaveControllerFlll(void* self, s32 a, s32 b, s32 c);
extern "C" void getTotalFreeSize__7JKRHeapFv(void* heap);
extern "C" void setPriority__9J2DScreenFPCcUlP10JKRArchive(void* self, const char* name, u32 a, void* archive);
extern "C" void* getGlbResource__13JKRFileLoaderFPCcP13JKRFileLoader(const char* name, void* loader);
extern "C" void* load__20J2DAnmLoaderDataBaseFPCv(const void* res);
extern "C" void* fn_80403204(u32 type, const char* name);
extern "C" void* fn_80403244(u32 type, const char* name);
extern "C" void* fn_804030C4(u32 type, const char* name);
extern "C" void* create__12JKRSolidHeapFUlP7JKRHeapb(u32 size, void* parent, s32 align);
extern "C" void becomeCurrentHeap__7JKRHeapFv(void* heap);
extern "C" void adjustSize__12JKRSolidHeapFv(void* heap);
extern "C" void fn_8016A3BC(void* archive, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, void* heap, void* p0, void* p1, u32 g, void* p2, u32 h);
struct TObj1c {
    TObj1c() { fn_80428030(this); }
    u8 pad[0x1c];
};
struct WaveController {
    WaveController(long a, long b, long c);
    u8 pad[0x5c];
};

extern "C" u8* fn_803A59E0(u8* self) {
    void* tmp;
    char* names = lbl_80475F58;
    *(void**)self = lbl_804AF820;
    __construct_array(self + 0x90, (void*)fn_8016FDE0, NULL, 0x1c, 4);
    getTotalFreeSize__7JKRHeapFv(*(void**)(lbl_80529DEC + 0x8));
    lbl_8053AD88 = self;
    *(J2DScreen**)(self + 0x4) = new J2DScreen();
    u8* tbl = lbl_80529DEC;
    setPriority__9J2DScreenFPCcUlP10JKRArchive(*(void**)(self + 0x4), names + 0x164, 0x1100000, *(void**)(tbl + 0x24));
    *(void**)(self + 0x24) = load__20J2DAnmLoaderDataBaseFPCv(getGlbResource__13JKRFileLoaderFPCcP13JKRFileLoader(names + 0x170, *(void**)(tbl + 0x24)));
    (*(J2DScreen**)(self + 0x4))->setAnimation(*(J2DAnmTextureSRTKey**)(self + 0x24));
    (*(J2DScreen**)(self + 0x4))->search(0x50636d61726bULL)->hide();
    self[0x14e] = (*(J2DScreen**)(self + 0x4))->search(0x7072737374727431ULL)->getAlpha();
    self[0x14f] = (*(J2DScreen**)(self + 0x4))->search(0x7072737374727432ULL)->getAlpha();

    tmp = fn_80403204(0x54494d47, names + 0x17c);
    *(J2DPicture**)(self + 0x8) = new J2DPicture((const ResTIMG*)tmp);
    *(TObj1c**)(self + 0x48) = new TObj1c();
    tmp = fn_80403244(0x54494d47, names + 0x190);
    *(J2DPicture**)(self + 0xc) = new J2DPicture((const ResTIMG*)tmp);
    tmp = fn_80403244(0x54494d47, names + 0x1a8);
    *(J2DPicture**)(self + 0x10) = new J2DPicture((const ResTIMG*)tmp);
    tmp = fn_80403244(0x54494d47, names + 0x1c0);
    *(J2DPicture**)(self + 0x14) = new J2DPicture((const ResTIMG*)tmp);
    tmp = fn_80403244(0x54494d47, names + 0x1d4);
    *(J2DPicture**)(self + 0x18) = new J2DPicture((const ResTIMG*)tmp);
    tmp = fn_80403244(0x54494d47, names + 0x1e8);
    *(J2DPicture**)(self + 0x1c) = new J2DPicture((const ResTIMG*)tmp);
    tmp = fn_804030C4(0x54494d47, names + 0x1fc);
    *(J2DPicture**)(self + 0x20) = new J2DPicture((const ResTIMG*)tmp);
    (*(J2DPicture**)(self + 0x20))->setBlackWhite(JUtility::TColor(0x08, 0x18, 0x28, 0xff), JUtility::TColor(0, 0, 0, 0));

    if (lbl_80529DEC[0x249] != 0) {
        *(s16*)(self + 0x68) = 0;
    } else {
        *(s16*)(self + 0x68) = 0xff;
    }
    self[0x150] = 0;
    tmp = sCurrentHeap__7JKRHeap;
    *(void**)(self + 0x100) = create__12JKRSolidHeapFUlP7JKRHeapb(0x80000, tmp, 0);
    becomeCurrentHeap__7JKRHeapFv(*(void**)(self + 0x100));

    for (s32 i = 0; i < 6; i++) {
        fn_8016A3BC(*(void**)(tbl + 0x24), lbl_804AF7D8[i][0], lbl_804AF7D8[i][1], 0, lbl_804AF7D8[i][2], 0, 0x10240000, *(void**)(self + 0x100),
                    self + 0x104 + i * 4, self + 0x11c + i * 4, 0, self + 0x134 + i * 4, 0);
        if (*(void**)(self + 0x11c + i * 4) != NULL) {
            *(f32*)(*(u8**)(self + 0x11c + i * 4) + 0x8) = 0.0f;
        }
        if (*(void**)(self + 0x134 + i * 4) != NULL) {
            *(f32*)(*(u8**)(self + 0x134 + i * 4) + 0x8) = 0.0f;
        }
    }
    adjustSize__12JKRSolidHeapFv(*(void**)(self + 0x100));
    becomeCurrentHeap__7JKRHeapFv(tmp);

    for (s32 i = 0; i < 4; i++) {
        *(WaveController**)(self + 0xa8 + i * 0x1c) = new WaveController(0, 0, 8);
    }

    self[0x14c] = 0;
    *(f32*)(self + 0x50) = 0.0f;
    *(f32*)(self + 0x4c) = 0.0f;
    *(s16*)(self + 0x6e) = 0;
    *(s16*)(self + 0x72) = 0;
    *(s16*)(self + 0x7a) = 0;
    *(s16*)(self + 0x7e) = 0;
    self[0x14d] = 0;
    *(s16*)(self + 0x74) = 0;
    *(s16*)(self + 0x76) = 0;
    *(s16*)(self + 0x78) = 0;
    *(u32*)(self + 0x58) = 0;
    *(u32*)(self + 0x60) = 0;
    *(u32*)(self + 0x64) = 0;
    *(s16*)(self + 0x6c) = 0;
    *(u32*)(self + 0x5c) = 0;
    *(s16*)(self + 0x7c) = 0;
    *(s16*)(self + 0x80) = 0;
    *(s16*)(self + 0x82) = 0x3c;
    *(u32*)(self + 0x28) = 0;
    *(u32*)(self + 0x2c) = 0;
    *(u32*)(self + 0x30) = 0;
    *(u32*)(self + 0x34) = 0;
    *(u32*)(self + 0x38) = 0;
    *(u32*)(self + 0x3c) = 0;
    *(u32*)(self + 0x40) = 0;
    *(u32*)(self + 0x44) = 0;
    *(u8*)(*(u8**)(lbl_8053AB10 + 0x20) + 0x2364) = 1;
    lbl_80529DEC[0x250] = 0;
    return self;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
#include "JSystem/JGeometry/Matrix.h"

