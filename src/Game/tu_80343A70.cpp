#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"
#define I7(p,o) (*(s32*)((char*)(p)+(o)))
#define F7(p,o) (*(f32*)((char*)(p)+(o)))
#define B7(p,o) (*(u8*)((char*)(p)+(o)))
#define H7(p,o) (*(u16*)((char*)(p)+(o)))
#define V7(p,o) (*(JGeometry::TVec3<f32>*)((char*)(p)+(o)))
#include "Game/ItemBase.h"

struct Tu80343Random {
    u32 seed;
    f32 get_ufloat_1() {
        union {
            f32 f;
            u32 s;
        } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - 1.0f;
    }
};
struct Tu80343Game {
    u8 pad[0xb4];
    Tu80343Random rnd;
};
extern Tu80343Game* lbl_8053AAF8;

struct Tu80343Vec3 {
    f32 x, y, z;
};


extern "C" char __vt__4BEEE[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F8544(void* mgr, u32 kind, s32 room, void* pos, s32 n);
extern "C" void v07__5ActorFv(void* this_);
extern "C" Actor* fn_80343A70(Actor* p, s16 n) {
    if (p) {
        *(void**)p = __vt__4BEEE;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" void fn_80343AD0(char* this_) {
    u32 n;
    s32 t = *(s32*)(this_ + 0x274);
    if (t == 1) {
        n = 3;
    } else if (t == 2) {
        n = 1;
    }
    fn_801F8544(fn_801F856C(), 'RUPY', *(s32*)(this_ + 4), this_ + 0xc, n | 0x261e00);
    v07__5ActorFv(this_);
}

extern "C" const f32 lbl_80542350;
extern "C" const f32 lbl_80542354;
extern "C" const f32 lbl_80542358;
extern "C" char lbl_80471FE0[];
extern "C" void fn_801F06F0(void* this_, const char* tbl, s32 id, DrawRec* rec, s32 p5, f32 a, f32 b);
extern "C" void fn_80343B48(char* this_) {
    DrawRec rec;
    rec.b1d = -1;
    rec.b1c = 1;
    if (*(s32*)(this_ + 0x274) == 2) {
        rec.b20 = 0;
        if (*(s32*)(this_ + 0x230) != 0) {
            f32 zero = lbl_80542350;
            char* p = this_;
            for (s32 i = 0; i < 7; i++) {
                Tu80343Vec3 a = *(Tu80343Vec3*)(p + 0x2a4);
                Tu80343Vec3 b = *(Tu80343Vec3*)(this_ + 0x2a4);
                Tu80343Vec3 sum;
                sum.x = a.x + b.x;
                sum.y = a.y + b.y;
                sum.z = a.z + b.z;
                *(Tu80343Vec3*)(this_ + 0xc) = sum;
                if (*(f32*)(this_ + 0x14) <= zero) {
                    *(f32*)(this_ + 0x14) = lbl_80542354;
                }
                fn_801F06F0(this_, lbl_80471FE0, *(s32*)(this_ + 0x240) + *(s32*)(this_ + 0x254) + 0x1cc, &rec, 1, lbl_80542358, lbl_80542358);
                p += 0xc;
            }
            *(Tu80343Vec3*)(this_ + 0xc) = *(Tu80343Vec3*)(this_ + 0x2a4);
            if (*(s32*)(this_ + 0x274) == 2 && *(f32*)(this_ + 0x14) <= zero) {
                *(f32*)(this_ + 0x14) = lbl_80542354;
            }
        }
    }
}

extern "C" s32 fn_801F3D94(void*,s32);
extern "C" s32 fn_801F2718(void*,u32);
extern "C" void* fn_801F666C(void*,s32);
extern "C" void fn_801F37AC(void*,u32,void*,s32,s32,s32);
extern "C" s32 fn_801F82CC(void*,void*,u8,f32);
extern "C" s32 fn_801F285C(void*,s32,s32,s32,s32);
extern "C" void* fn_8023E724(s32);
extern "C" s32 fn_801F0E34(void*,u32,s32);
extern "C" void fn_801F71A4(f32*,f32,f32,f32);
extern "C" void fn_801F714C(u16*,u16,s32,s32);
extern "C" u8 fn_801F2B7C(void*,s32,s32,s32);
extern "C" u8 fn_8023A51C(s32);
extern "C" const f32 lbl_8054235C,lbl_80542360,lbl_80542364,lbl_80542368,lbl_8054236C,lbl_80542370,lbl_80542374;
extern "C" const f32 lbl_80542378,lbl_8054237C,lbl_80542380,lbl_80542384,lbl_80542388;
extern "C" u8 fn_801F6758(void*,f32,s32);
extern "C" void fn_801EEC98(void*,s32,s32,s32,s32,s32*,s32,s32);
#pragma opt_common_subs off
#pragma opt_loop_invariants off
#pragma opt_common_subs off
#pragma opt_loop_invariants off
extern "C" void fn_80343D90(char* p) {
    JGeometry::TVec3<f32> delta;
    delta.x=delta.y=delta.z=lbl_80542350;
    if(I7(p,0x230)==0) goto states;
    if(I7(p,0x230)!=6 && I7(p,0x230)!=1) {
        if(fn_801F3D94(p,1)==0) {
            bool hit=false;
            s32 id=fn_801F2718(p,0x48424d42);
            if(id>=0) {
                char* obj=(char*)fn_801F666C(fn_801F856C(),id);
                if(obj && H7(obj,0x94)!=0) {
                    JGeometry::TVec3<f32> pos=V7(p,0xc);
                    pos-=V7(obj,0x3c);
                    I7(p,0x274)=1;hit=true;
                    fn_801F37AC(p,I7(obj,0x118),&pos,3,I7(obj,0x168),I7(obj,0x110));
                }
            }
            if(!hit) {
                id=fn_801F82CC(fn_801F856C(),p,B7(p,0x195),lbl_8054235C);
                if(id>=0) {
                    char* obj=(char*)fn_801F666C(fn_801F856C(),id);
                    if(obj && I7(obj,0x168)==5) {
                        JGeometry::TVec3<f32> pos=V7(p,0xc);
                        pos-=V7(obj,0x3c);
                        I7(p,0x274)=2;hit=true;
                        fn_801F37AC(p,I7(obj,0x118),&pos,3,I7(obj,0x168),I7(obj,0x110));
                    }
                }
            }
            if(!hit) {
                s32 player=fn_801F285C(p,0,0,1,-1);
                if(player>=0) {
                    I7(p,0x24c)=player;I7(p,0x238)=10;I7(p,0x108)=1;
                    delta.x=F7(p,0x2a4)-F7(fn_8023E724(I7(p,0x24c)),0);
                    delta.y=F7(p,0x2a8)-F7(fn_8023E724(I7(p,0x24c)),4);
                    {f32 angle=JMath::atanTable_.atan2_(delta.x,delta.y);H7(p,0x2a2)=(s16)(angle*lbl_80542360);}
                    H7(p,0x294)=H7(p,0x2a2);
                    F7(p,0x34c)=lbl_80542364*JMath::sincosTable_.sinShort(H7(p,0x294));
                    F7(p,0x350)=lbl_80542364*JMath::sincosTable_.cosShort(H7(p,0x294));
                    V7(p,0x2f8)=V7(p,0x34c);
                    I7(p,0x230)=4;
                }
            }
        } else {
            V7(p,0x2a4)=V7(p,0xc);
            if(I7(p,0x108)<=0) {fn_801F0E34(p,0x4007e,0);return;}
        }
    }
    {
        fn_801F0E34(p,0x4007e,0);
        fn_801F71A4(&F7(p,0x2f8),F7(p,0x34c),lbl_80542354,lbl_80542368);
        fn_801F71A4(&F7(p,0x2fc),F7(p,0x350),lbl_80542354,lbl_80542368);
        V7(p,0x2a4)+=V7(p,0x2f8);
        for(s32 i=1;i<7;i++) {
            char* segment=p+i*12;
            fn_801F71A4(&F7(segment,0x2f8),F7(segment,0x34c),lbl_80542354,lbl_80542368);
            fn_801F71A4(&F7(segment,0x2fc),F7(segment,0x350),lbl_80542354,lbl_80542368);
            V7(segment,0x2a4)+=V7(segment,0x2f8);
        }
        fn_801F714C(&H7(p,0x294),H7(p,0x2a2),4,0x400);
        V7(p,0xc)=V7(p,0x2a4);
        if(I7(p,0x230)!=4 && (u32)(I7(p,0x230)-5)>1 && fn_801F2B7C(p,1,-1,1)) {
            I7(p,0x250)++;
            if(I7(p,0x250)>=5) {
                lbl_8053AAF8->rnd.get_ufloat_1();
                F7(p,0x34c)=lbl_80542364*JMath::sincosTable_.sinShort(H7(p,0x2a2));
                F7(p,0x350)=lbl_80542364*JMath::sincosTable_.cosShort(H7(p,0x2a2));
                for(s32 i=1;i<7;i++){F7(p,0x34c+i*12)=lbl_80542350;F7(p,0x350+i*12)=lbl_80542350;}
                I7(p,0x230)=6;return;
            } else {
                I7(p,0x238)=120;
                F7(p,0x2f8)=F7(p,0x2fc)=F7(p,0x300)=lbl_80542350;
                F7(p,0x34c)=F7(p,0x350)=F7(p,0x354)=lbl_80542350;
                I7(p,0x24c)=-1;I7(p,0x244)=I7(p,0x24c);I7(p,0x230)=5;
            }
        }
    }
states:
    switch(I7(p,0x230)) {
    case 0:
        switch(I7(p,0x270)) {
        case 0:
            for(s32 i=0;i<4;i++) {
                if(fn_8023A51C(i)) {
                    delta.x=F7(fn_8023E724(i),0)-F7(p,0xc);
                    f32 playerY=F7(fn_8023E724(i),4);
                    delta.y=playerY-F7(p,0x10);
                    f32 xx=delta.x*delta.x,yy=delta.y*delta.y;
                    if(!(xx+yy>lbl_8054236C)) {
                        I7(p,0x238)=60;
                        {
                            int j;
                            char* segment=p+12;char* angles=p+2;
                            for(j=1;j<7;j++) {
                                V7(segment,0x2f8)=V7(p,0x2f8);
                                H7(angles,0x294)=(j<<16)/6;
                                F7(segment,0x2f8)+=lbl_80542370*JMath::sincosTable_.sinShort(H7(angles,0x294));
                                F7(segment,0x2fc)+=lbl_80542370*JMath::sincosTable_.cosShort(H7(angles,0x294));
                                segment+=12;angles+=2;
                            }
                        }
                        I7(p,0x230)=1;return;
                    }
                }
            } break;
        case 1:
            for(s32 i=0;i<4;i++) {
                delta.x=F7(fn_8023E724(i),0)-F7(p,0xc);
                f32 playerY=F7(fn_8023E724(i),4);
                    delta.y=playerY-F7(p,0x10);
                f32 xx=delta.x*delta.x,yy=delta.y*delta.y;
                if(!(xx+yy>lbl_80542374)) {
                    I7(p,0x238)=120;
                    {
                            int j;
                            char* segment=p+12;char* angles=p+2;
                            for(j=1;j<7;j++) {
                                V7(segment,0x2f8)=V7(p,0x2f8);
                                H7(angles,0x294)=(j<<16)/6;
                                F7(segment,0x2f8)+=lbl_80542370*JMath::sincosTable_.sinShort(H7(angles,0x294));
                                F7(segment,0x2fc)+=lbl_80542370*JMath::sincosTable_.cosShort(H7(angles,0x294));
                                segment+=12;angles+=2;
                            }
                        }
                    I7(p,0x230)=1;return;
                }
            } break;
        }
        break;
    case 1:
        if(I7(p,0x238)<=0) {I7(p,0x238)=30;I7(p,0x230)=2;return;}
        break;
    case 2:case 3:
        if(I7(p,0x238)<=0) {
            f32 closest=lbl_80542378;
            int i;
            s32 id=-1;
            s32 count;
            char* obj;
            s32 offset;
            count=I7(fn_801F856C(),0x1008);
            for(offset=0,i=offset;i<count;offset+=4,i++) {
                obj=*(char**)((char*)fn_801F856C()+8+offset);
                if(obj && (u32)I7(obj,0x1a0)==0x48424d42 && B7(obj,0x11c)==1 && (u32)I7(obj,0x90)!=1 && (u32)I7(obj,0x90)!=2 && (u32)I7(obj,0x90)!=4) {
                    f32 distance=PSVECDistance((Vec*)(p+0xc),(Vec*)(obj+0xc));
                    if(distance<closest) {id=I7(obj,0x198);closest=distance;}
                }
            }
            I7(p,0x248)=id;
            id=I7(p,0x248);
            if(id>=0) {
                char* obj=(char*)fn_801F666C(fn_801F856C(),id);
                if(obj) {
                    JGeometry::TVec3<f32> pos=V7(obj,0xc);
                    delta.x=pos.x-F7(p,0xc);
                    delta.y=pos.y-F7(p,0x10);
        {
            s32 i;
            char* angles=p+2;
            char* segment=p+12;
            char* speeds=p+4;
            for(i=1;i<7;i++) {
                if(I7(p,0x238)%10==0) {
                    H7(angles,0x294)=(s16)(lbl_8054237C*lbl_8053AAF8->rnd.get_ufloat_1());
                    f32 x,y;
                    if(I7(p,0x230)==5 || (I7(p,0x248)>=0 && I7(p,0x244)<0)) {
                        x=-F7(segment,0x2a4);y=-F7(segment,0x2a8);
                    } else {
                        const std::pair<f32,f32>* trig=&JMath::sincosTable_.mTable[(u32)(u16)H7(angles,0x294)>>5];
                        f32 negY=-F7(segment,0x2a8);
                        x=-F7(segment,0x2a4);
                        x+=trig->first*lbl_80542380;
                        y=trig->second*lbl_80542380+negY;
                    }
                    {f32 angle=JMath::atanTable_.atan2_(x,y);H7(angles,0x294)=(s16)(angle*lbl_80542360);}
                }
                F7(segment,0x34c)=F7(speeds,0x278)*JMath::sincosTable_.sinShort(H7(angles,0x294));
                F7(segment,0x350)=F7(speeds,0x278)*JMath::sincosTable_.cosShort(H7(angles,0x294));
                angles+=2;speeds+=4;segment+=12;
            }
        }

                    if(PSVECMag(&delta)>lbl_80542384) {
                        {f32 angle=JMath::atanTable_.atan2_(delta.x,delta.y);H7(p,0x2a2)=(s16)(angle*lbl_80542360);}
                        F7(p,0x34c)=lbl_80542364*JMath::sincosTable_.sinShort(H7(p,0x294));
                        F7(p,0x350)=lbl_80542364*JMath::sincosTable_.cosShort(H7(p,0x294));
                        I7(p,0x238)=5;
                    } else {
                        delta*=lbl_80542388;
                        V7(p,0x34c)=delta;
                        I7(p,0x238)=10;
                    }
                    if(pos.x>F7(p,0x2a4)) I7(p,0x254)=0;else I7(p,0x254)=2;
                    char* segment=p+12;char* frames=p+4;
                    for(s32 j=1;j<7;j++) {
                        if(pos.x>F7(segment,0x2a4)) I7(frames,0x254)=0;else I7(frames,0x254)=2;
                        segment+=12;frames+=4;
                    }
                }
            } else {
                if(I7(p,0x230)==2) fn_801EEC98(p,I7(p,0x198),0,0,0,(s32*)(p+0x244),0,0);
                else fn_801EEC98(p,I7(p,0x198),0,0,0,(s32*)(p+0x244),I7(p,0x24c),2);
                if(I7(p,0x244)>=0) {
                    delta.x=F7(fn_8023E724(I7(p,0x244)),0)-F7(p,0xc);
                    delta.y=F7(fn_8023E724(I7(p,0x244)),4)-F7(p,0x10);
                    {f32 angle=JMath::atanTable_.atan2_(delta.x,delta.y);H7(p,0x2a2)=(s16)(angle*lbl_80542360);}
                }
        {
            char* angles=p+2;
            char* segment=p+12;
            char* speeds=p+4;
            for(s32 i=1;i<7;i++) {
                if(I7(p,0x238)%10==0) {
                    H7(angles,0x294)=(s16)(lbl_8054237C*lbl_8053AAF8->rnd.get_ufloat_1());
                    f32 x,y;
                    if(I7(p,0x230)==5 || (I7(p,0x248)>=0 && I7(p,0x244)<0)) {
                        x=-F7(segment,0x2a4);y=-F7(segment,0x2a8);
                    } else {
                        const std::pair<f32,f32>* trig=&JMath::sincosTable_.mTable[(u32)(u16)H7(angles,0x294)>>5];
                        f32 negY=-F7(segment,0x2a8);
                        x=-F7(segment,0x2a4);
                        x+=trig->first*lbl_80542380;
                        y=trig->second*lbl_80542380+negY;
                    }
                    {f32 angle=JMath::atanTable_.atan2_(x,y);H7(angles,0x294)=(s16)(angle*lbl_80542360);}
                }
                F7(segment,0x34c)=F7(speeds,0x278)*JMath::sincosTable_.sinShort(H7(angles,0x294));
                F7(segment,0x350)=F7(speeds,0x278)*JMath::sincosTable_.cosShort(H7(angles,0x294));
                angles+=2;speeds+=4;segment+=12;
            }
        }

            }
        }
        if(I7(p,0x248)<0) {
            if(I7(p,0x244)>=0) {
                F7(p,0x34c)=lbl_80542364*JMath::sincosTable_.sinShort(H7(p,0x294));
                F7(p,0x350)=lbl_80542364*JMath::sincosTable_.cosShort(H7(p,0x294));
                if(F7(fn_8023E724(I7(p,0x244)),0)>F7(p,0x2a4)) I7(p,0x254)=0;else I7(p,0x254)=2;
                char* segment=p+12;char* frames=p+4;
                for(s32 i=1;i<7;i++) {
                    if(F7(fn_8023E724(I7(p,0x244)),0)>F7(segment,0x2a4)) I7(frames,0x254)=0;else I7(frames,0x254)=2;
                    segment+=12;frames+=4;
                }
            } else {F7(p,0x34c)=lbl_80542350;F7(p,0x350)=lbl_80542350;}
            if(I7(p,0x230)==3 && I7(p,0x244)!=I7(p,0x24c)) {
                I7(p,0x230)=2;I7(p,0x238)=1;I7(p,0x24c)=-1;I7(p,0x244)=I7(p,0x24c);
            }
        }
        if(I7(p,0x238)<=0) I7(p,0x238)=10;
        break;
    case 5:
        if(I7(p,0x238)<=0) {I7(p,0x238)=0;I7(p,0x230)=2;return;}
        {
            char* angles=p+2;
            char* segment=p+12;
            char* speeds=p+4;
            for(s32 i=1;i<7;i++) {
                if(I7(p,0x238)%10==0) {
                    H7(angles,0x294)=(s16)(lbl_8054237C*lbl_8053AAF8->rnd.get_ufloat_1());
                    f32 x,y;
                    if(I7(p,0x230)==5 || (I7(p,0x248)>=0 && I7(p,0x244)<0)) {
                        x=-F7(segment,0x2a4);y=-F7(segment,0x2a8);
                    } else {
                        const std::pair<f32,f32>* trig=&JMath::sincosTable_.mTable[(u32)(u16)H7(angles,0x294)>>5];
                        f32 negY=-F7(segment,0x2a8);
                        x=-F7(segment,0x2a4);
                        x+=trig->first*lbl_80542380;
                        y=trig->second*lbl_80542380+negY;
                    }
                    {f32 angle=JMath::atanTable_.atan2_(x,y);H7(angles,0x294)=(s16)(angle*lbl_80542360);}
                }
                F7(segment,0x34c)=F7(speeds,0x278)*JMath::sincosTable_.sinShort(H7(angles,0x294));
                F7(segment,0x350)=F7(speeds,0x278)*JMath::sincosTable_.cosShort(H7(angles,0x294));
                angles+=2;speeds+=4;segment+=12;
            }
        }

        break;
    case 4:
        if(I7(p,0x238)<=0) {I7(p,0x238)=0;I7(p,0x230)=3;return;}
        {
            char* angles=p+2;
            char* segment=p+12;
            char* speeds=p+4;
            for(s32 i=1;i<7;i++) {
                if(I7(p,0x238)%10==0) {
                    H7(angles,0x294)=(s16)(lbl_8054237C*lbl_8053AAF8->rnd.get_ufloat_1());
                    f32 x,y;
                    if(I7(p,0x230)==5 || (I7(p,0x248)>=0 && I7(p,0x244)<0)) {
                        x=-F7(segment,0x2a4);y=-F7(segment,0x2a8);
                    } else {
                        const std::pair<f32,f32>* trig=&JMath::sincosTable_.mTable[(u32)(u16)H7(angles,0x294)>>5];
                        f32 negY=-F7(segment,0x2a8);
                        x=-F7(segment,0x2a4);
                        x+=trig->first*lbl_80542380;
                        y=trig->second*lbl_80542380+negY;
                    }
                    {f32 angle=JMath::atanTable_.atan2_(x,y);H7(angles,0x294)=(s16)(angle*lbl_80542360);}
                }
                F7(segment,0x34c)=F7(speeds,0x278)*JMath::sincosTable_.sinShort(H7(angles,0x294));
                F7(segment,0x350)=F7(speeds,0x278)*JMath::sincosTable_.cosShort(H7(angles,0x294));
                angles+=2;speeds+=4;segment+=12;
            }
        }

        break;
    case 6:
        if(fn_801F6758(p+0xc,lbl_80542384,I7(p,4))) {
            bool all=true;
            for(s32 i=1;i<7;i++) {
                if(!fn_801F6758(p+0x2a4+i*12,lbl_80542384,I7(p,4))) {all=false;break;}
            }
            if(all) B7(p,0x11c)=0;
        }
        break;
    }
    I7(p,0x23c)--;
    if(I7(p,0x23c)<=0) {
        I7(p,0x240)++;
        I7(p,0x240)&=1;
        I7(p,0x23c)=2;
    }
    if(I7(p,0x238)>0) I7(p,0x238)--;
}
#pragma opt_common_subs reset
#pragma opt_loop_invariants reset
extern "C" void fn_803450AC(char* this_) {
    s32 n;
    char* p;
    char* q;
    Tu80343Game* g;

    *(s32*)(this_ + 0x270) = *(s32*)(this_ + 0x90) & 1;
    *(s32*)(this_ + 0x108) = 1;
    *(f32*)(this_ + 0x2ac) = 0.0f;
    *(f32*)(this_ + 0x2a8) = 0.0f;
    *(f32*)(this_ + 0x2a4) = 0.0f;
    *(f32*)(this_ + 0x300) = 0.0f;
    *(f32*)(this_ + 0x2fc) = 0.0f;
    *(f32*)(this_ + 0x2f8) = 0.0f;
    *(f32*)(this_ + 0x354) = 0.0f;
    *(f32*)(this_ + 0x350) = 0.0f;
    *(f32*)(this_ + 0x34c) = 0.0f;
    p = this_;
    q = this_;
    n = 7;
    do {
        *(f32*)(p + 0x278) = 2.0f + lbl_8053AAF8->rnd.get_ufloat_1();
        *(s32*)(p + 0x254) = 0;
        *(s16*)(q + 0x294) = 0;
        p += 4;
        q += 2;
    } while (--n != 0);
    *(f32*)(this_ + 0x278) = 1.5f + 0.5f * lbl_8053AAF8->rnd.get_ufloat_1();
    *(f32*)(this_ + 0x2a4) = *(f32*)(this_ + 0xc);
    *(f32*)(this_ + 0x2a8) = *(f32*)(this_ + 0x10);
    *(f32*)(this_ + 0x2ac) = *(f32*)(this_ + 0x14);
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = -1;
    *(s32*)(this_ + 0x24c) = -1;
    *(s32*)(this_ + 0x250) = 0;
    *(s16*)(this_ + 0x2a2) = 0;
    *(s32*)(this_ + 0x248) = -1;
    *(s32*)(this_ + 0x274) = 0;
    *(u8*)(this_ + 0x234) = 0;
    *(f32*)(this_ + 0x60) = -4.0f;
    *(f32*)(this_ + 0x64) = -4.0f;
    *(f32*)(this_ + 0x68) = 4.0f;
    *(f32*)(this_ + 0x6c) = 4.0f;
    *(s32*)(this_ + 0x230) = 0;
    *(u8*)(this_ + 0x194) = 1;
}

