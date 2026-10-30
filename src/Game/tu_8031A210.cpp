#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "Game/ItemBase.h"
#include "JSystem/JGeometry/Vec.h"


struct JMathSinCos {
    f32 sin;
    f32 cos;
};
extern "C" const JMathSinCos sincosTable___5JMath[];
extern "C" void* lbl_8053AAF8;
struct ActorRoomModes;
extern "C" ActorRoomModes* fn_802D6A9C(void);
extern "C" char lbl_804AB098[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" Actor* fn_8031A210(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804AB098;
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" void PSMTXIdentity(f32 (*)[4]);
extern "C" s32 fn_8023CB24(s32);
extern "C" s32 fn_8023CA88(s32);
extern "C" void fn_801F06F0(void*, void*, s32, DrawRec*, s32, f32, f32);
extern "C" void fn_801EF830(s32, void*, DrawRec*, s32, void*, s32, s32);
extern "C" void fn_803075AC(void*, s32, void*, s32, s32, s32, s32, s32, s32, s32);
extern "C" s32 lbl_804AB038[];
extern "C" char lbl_804716C8[];
extern "C" const f32 lbl_80541948, lbl_80541934, lbl_80541930, lbl_80541920;
extern "C" void fn_8031A270(Actor* p) {
    char* self = (char*)p;
    if (*(u8*)(self+0x281)==1) return;
    if (*(s32*)(self+0x230)==1 || *(s32*)(self+0x230)==2) return;
    DrawRec rec;
    s32 index;
    if (*(s32*)(self+0x270)==4) {
        if (*(s32*)(self+0x278)<3) index=0; else index=3;
    } else index=*(s32*)(self+0x270);
    rec.b20=0;
    rec.b2d=1;
    if (*(u8*)(self+0x284)==0) {rec.b1c=1;rec.b1d=1;}
    else {rec.b1c=0;rec.b1d=3;}
    if (*(s32*)(self+0x230)==5 || *(s32*)(self+0x230)==6) {
        rec.b2d=1; rec.b1f=0;
        index += 8;
        if (*(s32*)(self+0x26c)>=0 && *(s32*)(self+0x26c)<=3) {
            rec.b1d=fn_8023CB24(*(s32*)(self+0x26c))+1;
            rec.b1c=fn_8023CA88(*(s32*)(self+0x26c));
        }
        fn_801F06F0(p,lbl_804716C8,*(s32*)(self+0x25c)+lbl_804AB038[index],&rec,-1,1.0f,1.0f);
        fn_803075AC(*(void**)(self+0x198),*(s32*)(self+4),self+0xc,*(s32*)(self+0x25c)+lbl_804AB038[index],0,2,-1,1,0,0);
    } else {
        JGeometry::TVec3<f32> save=*(JGeometry::TVec3<f32>*)(self+0xc);
        *(JGeometry::TVec3<f32>*)(self+0xc)+=*(JGeometry::TVec3<f32>*)(self+0x2b0);
        *(f32*)(self+0x14)+=*(f32*)(self+0x248);
        f32 scale=lbl_80541948+lbl_80541934 * *(f32*)(self+0x248)/lbl_80541930;
        f32 m[3][4];
        PSMTXIdentity(m);
        m[0][0]=scale;m[0][1]=lbl_80541920;m[0][2]=lbl_80541920;
        m[1][0]=lbl_80541920;m[1][1]=scale;m[1][2]=lbl_80541920;
        m[2][0]=lbl_80541920;m[2][1]=lbl_80541920;m[2][2]=scale;
        rec.w18=m;
        if (*(s32*)(self+0x274)==1) {
            fn_801F06F0(p,lbl_804716C8,*(s32*)(self+0x25c)+lbl_804AB038[index],&rec,-1,1.0f,1.0f);
            rec.b1d=-1;rec.b1c=0;
            s32 id=*(s32*)(self+0x25c)+lbl_804AB038[index];
            if (*(u32*)(self+0x138)==0) fn_801EF830(*(s32*)(self+4),self+0xc,&rec,7,lbl_804716C8,id,0);
        } else {
            fn_801F06F0(p,lbl_804716C8,*(s32*)(self+0x25c)+lbl_804AB038[index],&rec,7,1.0f,1.0f);
        }
        fn_803075AC(*(void**)(self+0x198),*(s32*)(self+4),self+0xc,*(s32*)(self+0x25c)+lbl_804AB038[index],0,2,-1,0,0,0);
        *(JGeometry::TVec3<f32>*)(self+0xc)=save;
    }
}

#include "JSystem/JGeometry/Box.h"
extern "C" void* fn_801F856C();
extern "C" void fn_8013CC50(s32=0,void* =0,f32=1,s32=0,s32=0,s32=0,s32=0,s32=0,s32=1);
extern "C" void fn_801F0D20(Actor*, s32);
extern "C" void fn_801F0E34(void*,s32,s32);
extern "C" void fn_801F71A4(void*, f32, f32, f32);
extern "C" s32 fn_8023AF14(void*,s32,s32,f32);
extern "C" u8 fn_801F2618(void*,s32,s32);
extern "C" void* Actor_CreateByID(void* =0,u32=0,s32=0,void* =0,s32=0,s32=-1,s32=-1);
extern "C" JGeometry::TVec3f* fn_8023E724(s32);
extern "C" u8 fn_80230188(s32);
extern "C" u8 fn_8023EA28(s32);
extern "C" u8 fn_8023B9CC(s32,void*,s32,void*,s32);
extern "C" u8 fn_8023B848(s32,void*,s32,void*);
extern "C" u8 fn_80234C5C(s32);
extern "C" u8 fn_8022B7C4(s32);
extern "C" u8 fn_80234ECC(s32);
extern "C" u8 fn_8023ED8C(s32);
extern "C" u8 fn_8023EBB8(s32);
extern "C" u8 fn_80233DA4(s32);
extern "C" u8 fn_802308E0(s32);
extern "C" u8 fn_80233E40(s32);
extern "C" void fn_80230498(s32,void*,s32,s32,s32,s32,s32);
extern "C" u8 fn_8022F514(s32);
extern "C" s32 fn_8022F3DC(s32);
extern "C" u8 fn_802D7F40(void*,s32);
extern "C" void fn_802D7F84(void*,s32,s32);
extern "C" void fn_8043D67C(void*,s32,s32,s32);
extern "C" void fn_8043D874(void*,s32,s32,s32);
extern "C" void fn_80230FD0(s32,s32);
extern "C" void fn_802362C4(s32,s32);
extern "C" s32 fn_8023DE58(s32);
extern "C" u8 fn_8023F264(s32);
extern "C" void fn_801F3604(void*);
extern "C" void fn_8030C210(void*,void*);
extern "C" u8 fn_80233D20(s32);
extern "C" s32 fn_801F78F4(void*,u32,s32);
extern "C" u8* fn_801F666C(void*,s32);
extern "C" void fn_801EE558(void*,void*,void*,s32);
extern "C" void* lbl_8053AED0;
extern "C" u8* lbl_8053AB10;
extern "C" u8 lbl_80471678[];
extern "C" s32 lbl_804AB078[];
extern "C" const f32 lbl_80541924,lbl_80541928,lbl_8054192C,lbl_80541938,lbl_8054193C,lbl_80541940,lbl_80541944,lbl_8054194C,lbl_80541950,lbl_80541954,lbl_80541958,lbl_8054195C,lbl_80541960,lbl_80541964,lbl_80541968,lbl_8054196C,lbl_80541970,lbl_80541974,lbl_80541978,lbl_8054197C,lbl_80541980,lbl_80541984;
struct ActorRoomModes {
    u8 pad_0x0[0x131df];
    u8 mode[16];
};

inline u8 actorRoomMode(u32 room) {
    ActorRoomModes* g = fn_802D6A9C();
    return g->mode[room];
}

inline f32 actorRandomUnit() {
    union { u32 bits; f32 value; } out;
    u32* seed = (u32*)((char*)lbl_8053AAF8 + 0xb4);
    *seed = *seed * 0x19660d + 0x3c6ef35f;
    out.bits = (*seed >> 9) | 0x3f800000;
    return out.value - 1.0f;
}

extern "C" f32 PSVECDistance(const Vec*, const Vec*);
extern "C" void fn_8031A6A4(Actor* p) {
    u8* self=(u8*)p;
    u8* tables=lbl_80471678;
    s32 room;
    s32 player;
    s32 i;
    u8 hit=0;
    if ((*(u8*)(self+0x281))==1) {
        if((u8)p->v11()==1) {
            room=(*(s32*)(self+0x4));
            if(room>=8) Actor_CreateByID(fn_801F856C(),0x4b4d5249,room,self+0xc,3,-1,-1);
            else fn_8013CC50(room,self+0xc,lbl_80541948,0x503,1,0,0,0,1);
            fn_801F0D20(p,0x42);
            (*(u8*)(self+0x281))=0;
        }
        return;
    }
    JGeometry::TVec2f old2((*(f32*)(self+0xc)),(*(f32*)(self+0x10)));
    if((*(u16*)(self+0x94))==0) { (*(u8*)(self+0x17c))=0; (*(s32*)(self+0x174))=50; }
    if((*(s32*)(self+0x230))==0) {
        fn_801F71A4(self+0x3c,(*(f32*)(self+0x28c)),lbl_80541934,lbl_80541948);
        fn_801F71A4(self+0x40,(*(f32*)(self+0x290)),lbl_80541934,lbl_80541948);
        fn_801F71A4(self+0x44,(*(f32*)(self+0x294)),lbl_80541934,lbl_80541948);
    }
    if((*(s32*)(self+0x230))!=1 && (*(s32*)(self+0x230))!=2) (*(JGeometry::TVec3f*)(self+0xc)).add((*(JGeometry::TVec3f*)(self+0x3c)));
    if((*(s32*)(self+0x230))!=5 && (*(s32*)(self+0x230))!=6) {
        (*(s32*)(self+0x27c)) += (s32)(lbl_80541944*actorRandomUnit())+0x200;
        fn_801F71A4(self+0x2b8,lbl_80541928*sincosTable___5JMath[(u16)(*(s32*)(self+0x27c))>>5].sin+lbl_80541928,lbl_8054194C,lbl_80541940);
    }
    JGeometry::TBox2f box;
    box.set((*(JGeometry::TBox2f*)(self+0x60)));
    box.addPos(old2);
    if((*(s32*)(self+0x230))==0) {
        JGeometry::TVec3f save((*(JGeometry::TVec3f*)(self+0xc)));
        (*(f32*)(self+0x10))-=(*(f32*)(self+0x248));
        (*(f32*)(self+0x10))-=(*(f32*)(self+0x14));
        player=fn_8023AF14(&box,(*(s32*)(self+0x4)),0,(*(f32*)(self+0x14)));
        if(actorRoomMode((*(s32*)(self+0x4)))!=0) hit=fn_801F2618(p,0,0);
        if(player<0) {
            for(i=0;i<4;i++) {
                if(fn_80230188(i) || fn_8023EA28(i)) continue;
                if(fn_8023B9CC(i,&box,(*(s32*)(self+0x4)),&old2,1)==1 || fn_8023B848(i,&box,(*(s32*)(self+0x4)),&old2)==1) {
                    player=i; break;
                }
            }
        }
        if(player>=0 && !fn_80234C5C(player) && !fn_8022B7C4(player) && !fn_80230188(player) && !fn_8023EA28(player)) {
            if((*(u16*)(self+0x94))==5) {
                if(actorRoomMode((*(s32*)(self+0x4)))!=0) { (*(s32*)(self+0x26c))=player; (*(s32*)(self+0x230))=5; (*(s32*)(self+0xb0))=0; }
                else if((*(f32*)(self+0x14))-fn_8023E724(player)->z<=lbl_80541930) { (*(s32*)(self+0x26c))=player; (*(s32*)(self+0x230))=5; (*(s32*)(self+0xb0))=0; }
            } else if((*(s32*)(self+0x274))==0) {
                if(actorRoomMode((*(s32*)(self+0x4)))!=0 || fn_8023E724(player)->z>lbl_80541950 || fn_80234ECC(player)) {
                    (*(s32*)(self+0x26c))=player; (*(s32*)(self+0x230))=5; (*(s32*)(self+0xb0))=0;
                }
            } else if(actorRoomMode((*(s32*)(self+0x4)))!=0 || fn_8023ED8C(player) || fn_8023EBB8(player) || fn_80233DA4(player) ||
                      (*(s32*)(self+0x270))==5 || (*(s32*)(self+0x270))==6 || (*(s32*)(self+0x270))==7) {
                (*(s32*)(self+0x26c))=player; (*(s32*)(self+0x230))=5; (*(s32*)(self+0xb0))=0;
            } else if(fn_802308E0(player)==1) {
                if((*(s32*)(self+0x270))==4 && (*(s32*)(self+0x278))<3) (*(s32*)(self+0x270))=0;
                else if((*(s32*)(self+0x270))==4 && (*(s32*)(self+0x278))==3) (*(s32*)(self+0x270))=3;
                JGeometry::TVec3f playerPos(*fn_8023E724(player));
                JGeometry::TVec3f spawn(playerPos.x, playerPos.y-lbl_80541954, playerPos.z);
                if(fn_80233E40(player)) fn_80230498(player,&playerPos,0x336,255,-128,-128,1);
                else fn_80230498(player,&playerPos,0xed,255,-128,-128,1);
                i=player;
                if(fn_8022F514(player)==1) i=fn_8022F3DC(player);
                if(*(s32*)((u8*)fn_802D6A9C()+4)==0 && *(s32*)((u8*)fn_802D6A9C()+8)==0 && !fn_802D7F40(fn_802D6A9C(),0)) {
                    fn_8043D67C(lbl_8053AED0,0x13f,i,0);
                    fn_802D7F84(fn_802D6A9C(),0,1);
                }
                Actor_CreateByID(fn_801F856C(),0x494d5550,(*(s32*)(self+0x4)),&spawn,(*(s32*)(self+0x270))+0xa00000+(player<<24)+(player<<26)+4,-1,-1);
                p->detach();
                return;
            }
        }
        if((*(s32*)(self+0x230))==0) {
            for(i=0;i<4;i++) {
                if(fn_80233D20(i)==1) {
                    JGeometry::TVec3f a(*fn_8023E724(i));
                    JGeometry::TVec3f b((*(JGeometry::TVec3f*)(self+0xc)));
                    a.y-=a.z; a.z=lbl_80541920;
                    b.y-=b.z; b.z=lbl_80541920;
                    if(PSVECDistance(&a,&b)<lbl_80541958) {
                        (*(s32*)(self+0x26c))=i; (*(s32*)(self+0x230))=5; (*(s32*)(self+0xb0))=0; break;
                    }
                }
            }
        }
        (*(JGeometry::TVec3f*)(self+0xc))=save;
    }
    switch((*(s32*)(self+0x230))) {
    case 0:
        if((*(u8*)(self+0x286))==1) {
            s32 id=-1;
            bool near=false;
            while((id=fn_801F78F4(fn_801F856C(),0x424f4d45,id))>=0) {
                u8* other=fn_801F666C(fn_801F856C(),id);
                if(!other) continue;
                f32 dy=(*(f32*)(self+0x10))-(*(f32*)(self+0x14))-*(f32*)(other+0x10);
                f32 dx=(*(f32*)(self+0xc))-*(f32*)(other+0xc);
                f32 len=JGeometry::TUtilf::sqrt(dx*dx+dy*dy);
                if(len<lbl_8054192C) { near=true;break; }
            }
            JGeometry::TVec3f toPlayer;
            f32 distance;
            if(!near) fn_801EE558(p,&toPlayer,&distance,0);
            if(near==true || distance<lbl_8054192C)
                fn_801F71A4(self+0x248,lbl_80541930,lbl_80541934,lbl_80541938);
            else fn_801F71A4(self+0x248,lbl_80541920,lbl_8054193C,lbl_80541940);
        }
        (*(s32*)(self+0x260))+=(s32)(lbl_80541944*actorRandomUnit())+0x200;
        switch((int)(*(u16*)(self+0x94))) {
        case 1: case 2: case 6: case 7:
            switch((*(s32*)(self+0x98))) {
            case 0: (*(JGeometry::TVec3f*)(self+0x28c)).set(lbl_8054195C,lbl_80541920,lbl_80541920);break;
            case 1: (*(JGeometry::TVec3f*)(self+0x28c)).set(lbl_80541960,lbl_80541920,lbl_80541920);break;
            case 2: (*(JGeometry::TVec3f*)(self+0x28c)).set(lbl_80541920,lbl_8054195C,lbl_80541920);break;
            case 3: (*(JGeometry::TVec3f*)(self+0x28c)).set(lbl_80541920,lbl_80541960,lbl_80541920);break;
            }
            if((*(u16*)(self+0x94))==1 || (*(u16*)(self+0x94))==2) {
                if((*(s32*)(self+0x250))==0) { (*(s32*)(self+0x250))=200; (*(s32*)(self+0x98))^=1; }
            } else {
                if((*(s32*)(self+0x250))==100) (*(s32*)(self+0x98))^=1;
                else if((*(s32*)(self+0x250))==0) (*(s32*)(self+0x250))=200;
            }
            break;
        case 3: case 4:
            (*(s32*)(self+0x264))+=(*(s32*)(self+0x268));
            (*(f32*)(self+0xc))=(*(f32*)(self+0x238))*sincosTable___5JMath[(u16)(*(s32*)(self+0x264))>>5].sin+(*(f32*)(self+0x298));
            (*(f32*)(self+0x10))=(*(f32*)(self+0x238))*sincosTable___5JMath[(u16)(*(s32*)(self+0x264))>>5].cos+(*(f32*)(self+0x29c));
            break;
        case 5: {
            u8 mode=actorRoomMode((*(s32*)(self+0x4)));
            bool wall=false;
            if(mode!=0 && hit==1) wall=true;
            bool high=false;
            if((*(f32*)(self+0x14))>lbl_80541964 && (*(s32*)(self+0x98))==1) high=true;
            if((*(s32*)(self+0x250))==0 || (*(u8*)(self+0x280))!=mode || wall || high) {
                if((*(s32*)(self+0x250))==0 || wall || high) {
                    if(high) (*(f32*)(self+0x14))=lbl_80541968;
                    (*(s32*)(self+0x250))=500; (*(s32*)(self+0x98))^=1;
                }
                if(mode!=0) {
                    switch((*(s32*)(self+0x98))) {
                    case 0: (*(JGeometry::TVec3f*)(self+0x28c)).set(lbl_80541920,lbl_80541924,lbl_80541920);break;
                    case 1: (*(JGeometry::TVec3f*)(self+0x28c)).set(lbl_80541920,lbl_8054196C,lbl_80541920);break;
                    }
                } else {
                    switch((*(s32*)(self+0x98))) {
                    case 0: (*(JGeometry::TVec3f*)(self+0x28c)).set(lbl_80541920,lbl_80541920,lbl_8054196C);break;
                    case 1: (*(JGeometry::TVec3f*)(self+0x28c)).set(lbl_80541920,lbl_80541920,lbl_80541924);break;
                    }
                }
                if((*(u8*)(self+0x280))!=mode) {
                    if(mode!=0) { (*(f32*)(self+0x40))=-(*(f32*)(self+0x44)); (*(f32*)(self+0x44))=lbl_80541920; (*(f32*)(self+0x14))=lbl_80541920; }
                    else { (*(f32*)(self+0x44))=-(*(f32*)(self+0x40)); (*(f32*)(self+0x40))=lbl_80541920; (*(f32*)(self+0x14))=lbl_80541920; }
                    (*(u8*)(self+0x280))=mode;
                }
            }
            break;
        }
        }
        break;
    case 1:
        fn_801F0E34(p,0x5006d,0);
        fn_8013CC50((*(s32*)(self+0x4)),self+0xc,lbl_80541948,((u16*)(tables+0))[(*(s32*)(self+0x270))],0,0,0,0,1);
        fn_8013CC50((*(s32*)(self+0x4)),self+0xc,lbl_80541948,((u16*)(tables+0x10))[(*(s32*)(self+0x270))],0,0,0,0,1);
        fn_8013CC50((*(s32*)(self+0x4)),self+0xc,lbl_80541948,((u16*)(tables+0x20))[(*(s32*)(self+0x270))],0,0,0,0,1);
        (*(s32*)(self+0x258))=10; (*(s32*)(self+0x230))=2;
    case 2:
        if((*(s32*)(self+0x258))<=0) (*(s32*)(self+0x230))=(*(s32*)(self+0x234));
        break;
    case 3: {
        (*(f32*)(self+0x3c))=(*(f32*)(self+0x2a4))-(*(f32*)(self+0xc));
        (*(f32*)(self+0x40))=(*(f32*)(self+0x2a8))-(*(f32*)(self+0x10));
        f32 xx=(*(f32*)(self+0x3c))*(*(f32*)(self+0x3c)), yy=(*(f32*)(self+0x40))*(*(f32*)(self+0x40));
        f32 len=JGeometry::TUtilf::sqrt(xx+yy);
        (*(JGeometry::TVec3f*)(self+0x3c)).normalize();
        (*(f32*)(self+0x44))=lbl_80541974/len;
        (*(f32*)(self+0x244))=((*(f32*)(self+0x44))*(*(f32*)(self+0x44)))*lbl_80541978;
        (*(JGeometry::TVec3f*)(self+0xc)).add((*(JGeometry::TVec3f*)(self+0x3c)));
        (*(s32*)(self+0x230))=4;
    }
    case 4: {
        (*(f32*)(self+0x44))-=(*(f32*)(self+0x244));
        f32 dx=(*(f32*)(self+0xc))-(*(f32*)(self+0x2a4)),dy=(*(f32*)(self+0x10))-(*(f32*)(self+0x2a8));
        f32 xx=dx*dx,yy=dy*dy;
        f32 len=JGeometry::TUtilf::sqrt(xx+yy);
        if(len<lbl_8054197C) {
            (*(f32*)(self+0xc))=(*(f32*)(self+0x2a4)); (*(f32*)(self+0x10))=(*(f32*)(self+0x2a8)); (*(s32*)(self+0x274))=1; (*(s32*)(self+0x230))=0;
        }
        break;
    }
    case 5:
        if((*(s32*)(self+0x270))==4 && (*(s32*)(self+0x278))<3) (*(s32*)(self+0x270))=0;
        else if((*(s32*)(self+0x270))==4 && (*(s32*)(self+0x278))==3) (*(s32*)(self+0x270))=3;
        player=(*(s32*)(self+0x26c));
        if(fn_8022F514((*(s32*)(self+0x26c)))==1) player=fn_8022F3DC((*(s32*)(self+0x26c)));
        if(*(s32*)((u8*)fn_802D6A9C()+4)==0 && *(s32*)((u8*)fn_802D6A9C()+8)==0 && !fn_802D7F40(fn_802D6A9C(),0)) {
            fn_8043D67C(lbl_8053AED0,0x13f,player,0);
            fn_802D7F84(fn_802D6A9C(),0,1);
        }
        if((*(s32*)(self+0x270))!=5 && (*(s32*)(self+0x270))!=6 && (*(s32*)(self+0x270))!=7) fn_8043D874(lbl_8053AED0,player,lbl_804AB078[(*(s32*)(self+0x270))],0);
        else { fn_80230FD0(player,0x20011); fn_802362C4(player,lbl_804AB078[(*(s32*)(self+0x270))]); }
        if(fn_8023DE58((*(s32*)(self+0x26c)))>=8 && *((u8*)lbl_8053AAF8+0x7e)==1 && (*(s32*)(self+0x270))<4)
            fn_8043D67C(lbl_8053AED0,0x194-(*(s32*)(self+0x270)),player,0);
        (*(JGeometry::TVec3f*)(self+0x3c)).zero(); (*(f32*)(self+0x14))=lbl_80541920;
        (*(s32*)(self+0x25c))=0; (*(s32*)(self+0x24c))=50; (*(s32*)(self+0x250))=30; (*(f32*)(self+0x44))=lbl_80541928; (*(s32*)(self+0x230))=6;
        fn_801F3604(p);
    case 6:
        (*(JGeometry::TVec3f*)(self+0x3c)).zero();
        if(fn_8023F264((*(s32*)(self+0x26c)))) {
            (*(f32*)(self+0x14))=fn_8023E724((*(s32*)(self+0x26c)))->z;
            (*(f32*)(self+0xc))=fn_8023E724((*(s32*)(self+0x26c)))->x;
            (*(f32*)(self+0x10))=fn_8023E724((*(s32*)(self+0x26c)))->y-lbl_80541980;
        }
        if((*(s32*)(self+0x250))==0) { p->v10(255,1); p->detach(); }
        break;
    }
    if((*(JGeometry::TVec3f*)(self+0x3c)).squared()>lbl_8054193C) {
        s32 effect;
        if((*(s32*)(self+0x270))==7) effect=0x347;
        else if((*(s32*)(self+0x270))==5 || (*(s32*)(self+0x270))==6) effect=0x346;
        else effect=0x345;
        fn_8013CC50((*(s32*)(self+0x4)),self+0xc,lbl_80541984,effect,0,0,0,0,1);
    }
    ++(*(s32*)(self+0x24c));
    if((*(s32*)(self+0x230))==6) {
        if((*(s32*)(self+0x24c))>((s32*)(tables+0x40))[(*(s32*)(self+0x25c))]) ++(*(s32*)(self+0x25c));
        if((*(s32*)(self+0x25c))>=4) { (*(s32*)(self+0x25c))=0; (*(s32*)(self+0x24c))=0; }
    } else {
        if((*(s32*)(self+0x24c))>((s32*)(tables+0x30))[(*(s32*)(self+0x25c))]) ++(*(s32*)(self+0x25c));
        if((*(s32*)(self+0x25c))>=4) {
            (*(s32*)(self+0x25c))=0; (*(s32*)(self+0x24c))=0;
            if((*(s32*)(self+0x270))==4) { ++(*(s32*)(self+0x278)); (*(s32*)(self+0x278)) &= 3; }
        }
    }
    if((*(s32*)(self+0x4))<8 && (*(u16*)(self+0x94))==8 && (*(u8*)(self+0x282))==0) {
        JGeometry::TVec3f pos((*(f32*)(self+0xc)),(*(f32*)(self+0x10))-(*(f32*)(self+0x14)),lbl_80541920);
        fn_8030C210(*(void**)(lbl_8053AB10+0x24),&pos);
    }
    if((*(s32*)(self+0x250))>0) --(*(s32*)(self+0x250));
    if((*(s32*)(self+0x254))>0) --(*(s32*)(self+0x254));
    if((*(s32*)(self+0x258))>0) --(*(s32*)(self+0x258));
}

extern "C" void fn_8031B994(Actor* p) {
    char* g1;
    u32 rawSeed;
    u32 b1;
    for (s32 i=0; i<1; i++) {
    *(u16*)((char*)p + 0x94) = (*(u32*)((char*)p + 0x90) >> 16) & 0xff;
    *(s32*)((char*)p + 0x270) = *(u32*)((char*)p + 0x90) & 7;
    *(s32*)((char*)p + 0x274) = (*(u32*)((char*)p + 0x90) >> 12) & 1;
    *(u8*)((char*)p + 0x284) = (*(u32*)((char*)p + 0x90) >> 14) & 1;
    *(u8*)((char*)p + 0x286) = (*(u32*)((char*)p + 0x90) >> 10) & 1;
    *(u8*)((char*)p + 0x282) = (*(u32*)((char*)p + 0x90) >> 25) & 1;
    *(u8*)((char*)p + 0x283) = (*(u32*)((char*)p + 0x90) >> 26) & 1;
    *(s32*)((char*)p + 0x25c) = 0;
    *(s32*)((char*)p + 0x260) = 0;
    *(s32*)((char*)p + 0x264) = 0;
    *(s32*)((char*)p + 0x268) = 0;
    *(s32*)((char*)p + 0x24c) = 0;
    *(s32*)((char*)p + 0x250) = 0;
    *(s32*)((char*)p + 0x254) = 0;
    *(s32*)((char*)p + 0x258) = 0;
    *(u16*)((char*)p + 0x288) = 0;
    *(s32*)((char*)p + 0x108) = 10000;
    *(s32*)((char*)p + 0x26c) = -1;
    *(s32*)((char*)p + 0x98) = 0;
    *(f32*)((char*)p + 0x298) = *(f32*)((char*)p + 0xc);
    *(f32*)((char*)p + 0x29c) = *(f32*)((char*)p + 0x10);
    *(f32*)((char*)p + 0x2a0) = *(f32*)((char*)p + 0x14);
    *(f32*)((char*)p + 0x2ac) = 0.0f;
    *(f32*)((char*)p + 0x2a8) = 0.0f;
    *(f32*)((char*)p + 0x2a4) = 0.0f;
    *(s32*)((char*)p + 0x268) = 100;
    *(s32*)((char*)p + 0x278) = 0;
    *(f32*)((char*)p + 0x23c) = 1.0f;
    *(f32*)((char*)p + 0x240) = 0.0f;
    *(f32*)((char*)p + 0x244) = 0.0f;
    *(f32*)((char*)p + 0x248) = 0.0f;
    *(u8*)((char*)p + 0x280) = 0;
    *(u8*)((char*)p + 0x281) = (*(u32*)((char*)p + 0x90) >> 24) & 1;
    *(u8*)((char*)p + 0x285) = (*(u32*)((char*)p + 0x90) >> 8) & 1;
    *(f32*)((char*)p + 0x238) = 30.0f;
    *(f32*)((char*)p + 0x2b8) = 0.0f;
    *(f32*)((char*)p + 0x2b4) = 0.0f;
    *(f32*)((char*)p + 0x2b0) = 0.0f;
    {
        g1 = (char*)lbl_8053AAF8;
        u32 s = *(u32*)(g1 + 0xb4) * 0x19660d + 0x3c6ef35f;
        *(u32*)(g1 + 0xb4) = s;
    }
    }
    rawSeed = *(u32*)(g1 + 0xb4);
    b1 = (rawSeed >> 9) | 0x3f800000;
            *(s32*)((char*)p + 0x27c) = (s32)(65536.0f * (*(f32*)&b1 - 1.0f));
    *(s32*)((char*)p + 0x230) = 0;
    *(s32*)((char*)p + 0x234) = *(s32*)((char*)p + 0x230);
    {
        char* g = (char*)lbl_8053AAF8;
        u32 s = *(u32*)(g + 0xb4) * 0x19660d + 0x3c6ef35f;
        *(u32*)(g + 0xb4) = s;
        u32 b = (*(u32*)(g + 0xb4) >> 9) | 0x3f800000;
        *(s32*)((char*)p + 0x264) = (s32)(65535.0f * (*(f32*)&b - 1.0f));
    }
    *(f32*)((char*)p + 0x14) = 24.0f;
    if (*(s32*)((char*)p + 0x274) != 0) {
        *(f32*)((char*)p + 0x14) = 8.0f;
        *(s32*)((char*)p + 0xb0) = 0x20000;
    }
    {
        u32 room = *(u32*)((char*)p + 4);
        if (actorRoomMode(room) != 0) {
            *(f32*)((char*)p + 0x10) = *(f32*)((char*)p + 0x10) - *(f32*)((char*)p + 0x14);
            *(f32*)((char*)p + 0x14) = 0.0f;
            *(s32*)((char*)p + 0xb0) = 0x20000;
        }
    }
    switch (*(u16*)((char*)p + 0x94)) {
    case 0:
        *(u8*)((char*)p + 0x17c) = 0;
        *(s32*)((char*)p + 0x174) = 50;
        break;
    case 1:
    case 6:
        *(s32*)((char*)p + 0x98) = 2;
        {
            char* g = (char*)lbl_8053AAF8;
            u32 s = *(u32*)(g + 0xb4) * 0x19660d + 0x3c6ef35f;
            *(u32*)(g + 0xb4) = s;
            u32 b = (*(u32*)(g + 0xb4) >> 9) | 0x3f800000;
            *(s32*)((char*)p + 0x98) |= (s32)(1.99f * (*(f32*)&b - 1.0f));
        }
        break;
    case 2:
    case 7:
        {
            char* g = (char*)lbl_8053AAF8;
            u32 s = *(u32*)(g + 0xb4) * 0x19660d + 0x3c6ef35f;
            *(u32*)(g + 0xb4) = s;
            u32 b = (*(u32*)(g + 0xb4) >> 9) | 0x3f800000;
            *(s32*)((char*)p + 0x98) |= (s32)(1.99f * (*(f32*)&b - 1.0f));
        }
        break;
    case 3:
        *(s32*)((char*)p + 0x268) = -100;
        /* fallthrough */
    case 4:
        *(f32*)((char*)p + 0xc) = *(f32*)((char*)p + 0x238) * sincosTable___5JMath[(u16)*(s32*)((char*)p + 0x264) >> 5].sin + *(f32*)((char*)p + 0x298);
        *(f32*)((char*)p + 0x10) = *(f32*)((char*)p + 0x238) * sincosTable___5JMath[(u16)*(s32*)((char*)p + 0x264) >> 5].cos + *(f32*)((char*)p + 0x29c);
        break;
    case 5:
        *(s32*)((char*)p + 0x180) = 60;
        break;
    case 8:
        *(s32*)((char*)p + 0x230) = 3;
        *(f32*)((char*)p + 0x14) = 0.0f;
        break;
    }
    *(f32*)((char*)p + 0x28c) = 0.0f;
    *(f32*)((char*)p + 0x290) = 0.0f;
    *(f32*)((char*)p + 0x294) = 0.0f;
    *(f32*)((char*)p + 0x3c) = 0.0f;
    *(f32*)((char*)p + 0x40) = 0.0f;
    *(f32*)((char*)p + 0x44) = 0.0f;
    *(f32*)((char*)p + 0x80) = -7.0f;
    *(f32*)((char*)p + 0x84) = -4.0f;
    *(f32*)((char*)p + 0x88) = 7.0f;
    *(f32*)((char*)p + 0x8c) = 4.0f;
    if (*(u16*)((char*)p + 0x94) == 5 || *(s32*)((char*)p + 0x274) != 0) {
        *(f32*)((char*)p + 0x60) = -7.0f;
        *(f32*)((char*)p + 0x64) = -23.0f;
        *(f32*)((char*)p + 0x68) = 7.0f;
        *(f32*)((char*)p + 0x6c) = 7.0f;
    } else {
        *(f32*)((char*)p + 0x60) = -8.0f;
        *(f32*)((char*)p + 0x64) = -32.0f;
        *(f32*)((char*)p + 0x68) = 8.0f;
        *(f32*)((char*)p + 0x6c) = 16.0f;
    }
    if (*((u8*)lbl_8053AAF8 + 0x7f) == 0) {
        p->detach();
    } else if (*(u8*)((char*)p + 0x283) == 1 && *((u8*)lbl_8053AAF8 + 0x7e) == 0) {
        p->detach();
    } else if (*(u8*)((char*)p + 0x285) == 1) {
        *(s32*)((char*)p + 0x234) = *(s32*)((char*)p + 0x230);
        *(s32*)((char*)p + 0x230) = 1;
    }
}

extern "C" char memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr[];
extern "C" void __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv(void*);
extern "C" char __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr;
extern "C" char memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack[];
extern "C" void __dt__35JASMemPool_MultiThreaded_8JASTrackFv(void*);
extern "C" char __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack;
extern "C" char memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel[];
extern "C" void __dt__38JASMemPool_MultiThreaded_10JASChannelFv(void*);
extern "C" char __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj3_FSA[];
extern "C" void __dt__29JASMemPool_15JASPoolObj3_FSAFv(void*);
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj4_FSA[];
extern "C" void __dt__29JASMemPool_15JASPoolObj4_FSAFv(void*);
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA;
extern "C" char memPool___30JASPoolAllocObject_9JAIStream[];
extern "C" void __dt__22JASMemPool_9JAIStreamFv(void*);
extern "C" char __init__memPool___30JASPoolAllocObject_9JAIStream;
extern "C" char memPool___35JASPoolAllocObject_13JAISoundChild[];
extern "C" void __dt__27JASMemPool_13JAISoundChildFv(void*);
extern "C" char __init__memPool___35JASPoolAllocObject_13JAISoundChild;
extern "C" char memPool___27JASPoolAllocObject_6JAISeq[];
extern "C" void __dt__19JASMemPool_6JAISeqFv(void*);
extern "C" char __init__memPool___27JASPoolAllocObject_6JAISeq;
extern "C" char memPool___26JASPoolAllocObject_5JAISe[];
extern "C" void __dt__18JASMemPool_5JAISeFv(void*);
extern "C" char __init__memPool___26JASPoolAllocObject_5JAISe;
extern "C" void __ct__17JASGenericMemPoolFv(void*);
extern "C" void __register_global_object(void*, void (*)(void*), void*);
extern "C" void fn_8031BE2C(void)
{
    static u32 c0[3];
    static u32 c1[3];
    static u32 c2[3];
    static u32 c3[3];
    static u32 c4[3];
    static u32 c5[3];
    static u32 c6[3];
    static u32 c7[3];
    static u32 c8[3];
    if (__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr == 0) {
        __ct__17JASGenericMemPoolFv(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr);
        __register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr, __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, c0);
        __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr = 1;
    }
    if (__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack == 0) {
        __ct__17JASGenericMemPoolFv(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack);
        __register_global_object(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack, __dt__35JASMemPool_MultiThreaded_8JASTrackFv, c1);
        __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack = 1;
    }
    if (__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel == 0) {
        __ct__17JASGenericMemPoolFv(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel);
        __register_global_object(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel, __dt__38JASMemPool_MultiThreaded_10JASChannelFv, c2);
        __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA, __dt__29JASMemPool_15JASPoolObj3_FSAFv, c3);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA, __dt__29JASMemPool_15JASPoolObj4_FSAFv, c4);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA = 1;
    }
    if (__init__memPool___30JASPoolAllocObject_9JAIStream == 0) {
        __ct__17JASGenericMemPoolFv(memPool___30JASPoolAllocObject_9JAIStream);
        __register_global_object(memPool___30JASPoolAllocObject_9JAIStream, __dt__22JASMemPool_9JAIStreamFv, c5);
        __init__memPool___30JASPoolAllocObject_9JAIStream = 1;
    }
    if (__init__memPool___35JASPoolAllocObject_13JAISoundChild == 0) {
        __ct__17JASGenericMemPoolFv(memPool___35JASPoolAllocObject_13JAISoundChild);
        __register_global_object(memPool___35JASPoolAllocObject_13JAISoundChild, __dt__27JASMemPool_13JAISoundChildFv, c6);
        __init__memPool___35JASPoolAllocObject_13JAISoundChild = 1;
    }
    if (__init__memPool___27JASPoolAllocObject_6JAISeq == 0) {
        __ct__17JASGenericMemPoolFv(memPool___27JASPoolAllocObject_6JAISeq);
        __register_global_object(memPool___27JASPoolAllocObject_6JAISeq, __dt__19JASMemPool_6JAISeqFv, c7);
        __init__memPool___27JASPoolAllocObject_6JAISeq = 1;
    }
    if (__init__memPool___26JASPoolAllocObject_5JAISe == 0) {
        __ct__17JASGenericMemPoolFv(memPool___26JASPoolAllocObject_5JAISe);
        __register_global_object(memPool___26JASPoolAllocObject_5JAISe, __dt__18JASMemPool_5JAISeFv, c8);
        __init__memPool___26JASPoolAllocObject_5JAISe = 1;
    }
}

