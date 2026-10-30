

#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/Inline.h"
#include "JSystem/JAudio/JASFakeMatchFSA.h"


extern "C" int fn_802486A0(void*);
extern "C" int fn_80248778(void*);
extern "C" int fn_80240888(void*);
extern "C" unsigned char fn_8025F448(char* p);
extern "C" int fn_8023DE58(int idx);
extern "C" u16 fn_8022461C(void*, s32);
extern "C" s32 fn_8013CC50(s32 id, void* pos, s32 type, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale);
extern "C" void fn_8013CB44(void* obj, void* p, s32 a, s32 b, s32 c);
extern const f32 lbl_805401F0;
extern const f32 lbl_805401F4;
extern const f32 lbl_80540200;

static f32 fnDist(char* p, Vec* dst) {
    JGeometry::TVec3<f32> pos = *(JGeometry::TVec3<f32>*)(p + 8);
    JMathInlineVEC::PSVECSubtract(&pos, (Vec*)(p + 0x14), &pos);
    *(JGeometry::TVec3<f32>*)dst = *(JGeometry::TVec3<f32>*)&pos;
    return PSVECMag(dst);
}

extern "C" u32 fn_8023FC5C(u8* p);
extern "C" s32 GetPtrField_0x4(void* p);
#include "Game/ItemBase.h"
struct PlayerSpriteRes64998 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* get(u32,const char*);
};
extern "C" char* lbl_8053AAF8;
extern "C" u8* lbl_8053AB10;
extern char lbl_8046B960[];
extern "C" void fn_802F86CC(void*,void*,void*,s32,f32,f32,DrawRec*);
static inline void playerSprite64998(s32 room,void* pos,const char* name,s32 index,DrawRec* rec) {
    if(room<8) {
        void* res=(*(PlayerSpriteRes64998**)(lbl_8053AAF8+0xa4))->get('SOB ',name);
        fn_802F86CC(*(void**)(lbl_8053AB10+0x20),pos,res,index,lbl_805401F4,lbl_805401F4,rec);
    }
}
extern "C" u8 Player_IsLinked(char*);
extern "C" u8 fn_80240DAC(char*);
extern "C" u8 fn_802413F0(char*);
extern "C" u8 fn_8025F418(char*);
extern "C" u8 Player_GetField_0x454(char*);
extern "C" u8 fn_80240818(char*);
extern "C" u8 fn_8023188C(s32);
extern "C" s32 Player_GetLinkTargetIndex(char*);
extern "C" s32 fn_80241544(char*);
extern "C" u32 fn_80246B10(char*,s32);
extern "C" s32 fn_8023CB24(s32);
extern "C" s32 fn_8023CA88(s32);
extern "C" u8 fn_8022517C(void*,s32);
extern "C" u8 fn_80270A8C(char*);
extern "C" u8 fn_802412A4(char*);
extern "C" u8 fn_80241200(char*);
extern "C" u8 Player_GetField_0xce8(char*);
extern "C" u8 fn_80225BE4(void*,s32);
extern "C" u8* fn_802D6A9C(void);
extern "C" void fn_80158B5C(void*,s32,void*,void*);
extern "C" void fn_803075AC(s32,s32,void*,s32,s32,s32,s32,s32,s32,s32);
extern const f32 lbl_805401F8,lbl_805401FC,lbl_80540204,lbl_80540208,lbl_8054020C;
#pragma opt_common_subs off
extern "C" void fn_80264998(char* p) {
    u8* self=(u8*)p;
    char* table=lbl_8046B960;
    if(!self[0xcac])return;
    if(self[0xcee]==1)return;
    if(self[0x1215] && !((u8)lbl_8053AAF8[0x82] & (u8)(1<<*(s32*)(self+4))))return;
    u32 alpha=fn_8023FC5C(self);
    u32 player=GetPtrField_0x4(self);
    if(*(u16*)(self+0x3c4)>=0x3d5)*(u16*)(self+0x3c4)=0x3d4;
    if(*(f32*)(self+0xb90)>lbl_805401F0) {
        u8 c[4];c[0]=0;c[1]=0;c[2]=0;c[3]=255;u32 color=*(u32*)c;
        fn_80158B5C(*(void**)(lbl_8053AB10+0x2c),*(s32*)(self+0x3b4),self+0x338,&color);
    }
    if(*(s32*)(self+0x3b4)>8 && fn_80246B10(p,64)) {
        DrawRec rec;rec.b1c=1;rec.b2d=1;
        s32 ticks=*(s32*)(lbl_8053AAF8+0x5c);
        playerSprite64998(0,self+0xcb0,table,(ticks/6)%3+player*3+0x73,&rec);
    }
    DrawRec shadow;
    if((!Player_IsLinked(p) || !fn_80240DAC(p)) && fn_802413F0(p)) {
        JGeometry::TVec3<f32> pos;
        shadow.b1d=-2;
        if(fn_80240DAC(p)) {
            pos.set(*(f32*)(self+8),*(f32*)(self+0x328)-lbl_805401F8,lbl_805401FC);
            shadow.b1d+=2;
        }else pos.set(*(f32*)(self+8),*(f32*)(self+0xc)-lbl_805401F8,lbl_805401FC);
        if(*(s32*)(self+0x3b4)==8) {
            u8* mgr=fn_802D6A9C();
            pos+=JGeometry::TVec3<f32>(*(f32*)(mgr+0xcc),*(f32*)(mgr+0xd0),lbl_805401F0);
            pos+=JGeometry::TVec3<f32>(lbl_805401F0,-*(f32*)(self+0x10),lbl_805401F0);
        }
        if(self[0xca1]<255)shadow.b2c=0;
        ((u8*)&shadow.w10)[3]=(u8)alpha<self[0xca1]?alpha:self[0xca1];
        if(((u8*)&shadow.w10)[3]>=159)((u8*)&shadow.w10)[3]=159;
        if(*(f32*)(self+0x10)>lbl_805401F0) {
            f32 a=(f32)((u8*)&shadow.w10)[3]-lbl_80540200**(f32*)(self+0x10);
            ((u8*)&shadow.w10)[3]=(s32)(lbl_80540204>=a?lbl_80540204:a);
        }
        Mtx scale;
        if(*(s32*)(self+0x3b4)==8)PSMTXScale(scale,lbl_805401F4,lbl_805401F4,lbl_805401F4);
        else PSMTXScale(scale,lbl_80540208,lbl_80540200,lbl_80540200);
        ((u8*)&shadow.w10)[0]=0;((u8*)&shadow.w10)[1]=0;((u8*)&shadow.w10)[2]=0;
        shadow.w18=scale;
        ((u8*)&shadow.w14)[0]=40;((u8*)&shadow.w14)[1]=40;((u8*)&shadow.w14)[2]=40;
        if(self[0x43f]!=1) {
            if(*(s32*)(self+0x3b4)==8) {
                const JGeometry::TVec3<f32>& draw=pos+*(JGeometry::TVec3<f32>*)(self+0x2b8);
                playerSprite64998(0,(void*)&draw,table+0x14,*(u16*)(self+0x3c4),&shadow);
            }else {
                playerSprite64998(*(s32*)(self+0x3b4),(void*)&(pos+*(JGeometry::TVec3<f32>*)(self+0x2b8)),table+0x14,*(u16*)(self+0x3c4),&shadow);
            }
        }
        if(*(f32*)(self+0x10)>lbl_805401F0 && *(s32*)(self+0x3b4)>=8) {
            s32 room=*(s32*)(self+0x3b4);
            if(!fn_802D6A9C()[0x131df+room]) {
                JGeometry::TVec3<f32> pos;
                if(fn_80240DAC(p))pos.set(*(f32*)(self+8),*(f32*)(self+0x328)-lbl_805401F8,lbl_805401F0);
                else pos.set(*(f32*)(self+8),*(f32*)(self+0xc)-lbl_805401F8,lbl_805401F0);
                const JGeometry::TVec3<f32>& draw=pos+*(JGeometry::TVec3<f32>*)(self+0x2b8);
                fn_803075AC(-40000-*(s32*)(self+4),*(s32*)(self+0x3b4),(void*)&draw,0x3cd,0,1,-1,0,0,0);
            }
        }
    }
    DrawRec rec;
    if(fn_80241544(p)>=2)rec.ids[10]=6;
    rec.ids[7]=player+12;
    rec.b2d=1;
    if((u8)alpha<255)shadow.b2c=0;
    if(self[0x11e9])rec.w30=player+4;
    ((u8*)&rec.w10)[3]=alpha;
    Mtx scale;
    f32 zScale=*(f32*)(self+0xc8c)**(f32*)(self+0xc98);
    f32 yScale=*(f32*)(self+0xc88)**(f32*)(self+0xc94);
    f32 xScale=*(f32*)(self+0xc84)**(f32*)(self+0xc90);
    scale[0][3]=scale[1][3]=scale[2][3]=lbl_805401F0;
    scale[0][0]=xScale;
    scale[0][1]=scale[0][2]=lbl_805401F0;
    scale[1][0]=lbl_805401F0;scale[1][1]=yScale;scale[1][2]=lbl_805401F0;
    scale[2][0]=scale[2][1]=lbl_805401F0;scale[2][2]=zScale;
    rec.w18=scale;rec.b20=0;
    if(fn_8025F418(p)&&!Player_GetField_0x454(p)){
        rec.b1d=fn_8023CB24(*(s32*)(self+0xd70))+1;
        rec.b1c=fn_8023CA88(*(s32*)(self+0xd70));
    }else if(*(f32*)(self+0x10)>=lbl_8054020C){rec.b1d++;rec.b1c++;}
    else if(*(f32*)(self+0x10)>lbl_805401F0)rec.b1d++;
    else if(fn_80240818(p))rec.b1d++;
    if(Player_GetField_0x454(p)) {
        if(*(s8*)(self+0xca3)!=-128)rec.b1c=self[0xca3];
        if(*(s8*)(self+0xca4)!=-128)rec.b1d=self[0xca4];
    }
    if(self[0x43f]==1 || self[0x441]==1)rec.b1f=0;
    if(*(s32*)(self+0xca8)>0) {
        --*(s32*)(self+0xca8);
        switch(player) {
        case 0:((u8*)&rec.w10)[0]=0;((u8*)&rec.w10)[1]=255;((u8*)&rec.w10)[2]=0;break;
        case 1:((u8*)&rec.w10)[0]=255;((u8*)&rec.w10)[1]=0;((u8*)&rec.w10)[2]=0;break;
        case 2:((u8*)&rec.w10)[0]=0;((u8*)&rec.w10)[1]=255;((u8*)&rec.w10)[2]=255;break;
        case 3:((u8*)&rec.w10)[0]=255;((u8*)&rec.w10)[1]=0;((u8*)&rec.w10)[2]=255;break;
        }
    }else if(self[0x400]&&!Player_GetField_0x454(p)){
        s32 c=255-(self[0x400]<<5);if(c<0)c=0;
        ((u8*)&rec.w10)[0]=c;((u8*)&rec.w10)[1]=c;((u8*)&rec.w10)[2]=c;
    }else if(!((u8*)lbl_8053AAF8)[0x7f] && *(s32*)(self+0x1208)<64){
        u8 c=(*(s32*)(self+0x1208)&63)*4;
        ((u8*)&rec.w10)[0]=c;((u8*)&rec.w10)[1]=c;((u8*)&rec.w10)[2]=c;
    }
    self[0x3d8]=rec.b1c;self[0x3d9]=rec.b1d;
    if(fn_802413F0(p) && (u8)alpha>=32) {
    if(Player_IsLinked(p)&&fn_802486A0(p)!=4&&!fn_8023188C(Player_GetLinkTargetIndex(p)))return;
    u32 sprite=*(u16*)(self+0x3c4);
    if(sprite==0x121)return;
    JGeometry::TVec3<f32> draw=*(JGeometry::TVec3<f32>*)(self+8)+*(JGeometry::TVec3<f32>*)(self+0x2b8);
    draw.x=(s32)draw.x;draw.y=(s32)draw.y;draw.z=(s32)draw.z;
    if(*(s32*)(self+0x3b4)<8)playerSprite64998(*(s32*)(self+0x3b4),(void*)&draw,table+0x14,sprite,&rec);
    DrawRec water;
    if(self[0x458]==1&&*(s32*)(self+0x3dc)==2)((u8*)&water.w10)[3]=128;
    u16 tile=fn_8022461C(self+8,*(s32*)(self+0x3b4));
    JGeometry::TVec3<f32> waterPos=*(JGeometry::TVec3<f32>*)(self+8);
    waterPos.y+=lbl_805401F4;
    if(*(f32*)(self+0x10)<=lbl_805401F0&&fn_8022517C(self+8,*(s32*)(self+0x3b4))){
        if(*(s32*)(self+0x3b4)<8)playerSprite64998(*(s32*)(self+0x3b4),&waterPos,table+0x24,*(u16*)(self+0x3c8),&water);
        else fn_803075AC(-10000-*(s32*)(self+4),*(s32*)(self+0x3b4),&waterPos,*(u16*)(self+0x3c8),0,1,-1,0,0,0);
    }else if(*(f32*)(self+0x10)<=lbl_805401F0&&fn_80270A8C(p)&&(tile==0x39||tile==13||tile==0x3b)){
        if(*(u16*)(self+0x3c4)>=0xc2&&*(u16*)(self+0x3c4)<0xc5){
            if(*(s32*)(self+0x3b4)<8)playerSprite64998(*(s32*)(self+0x3b4),&waterPos,table+0x24,*(u16*)(self+0x3ca)+3,&water);
            else fn_803075AC(-20000-*(s32*)(self+4),*(s32*)(self+0x3b4),&waterPos,*(u16*)(self+0x3ca)+3,0,1,-1,0,0,0);
        }else {
            if(*(s32*)(self+0x3b4)<8)playerSprite64998(*(s32*)(self+0x3b4),&waterPos,table+0x24,*(u16*)(self+0x3ca),&water);
            else fn_803075AC(-20000-*(s32*)(self+4),*(s32*)(self+0x3b4),&waterPos,*(u16*)(self+0x3ca),0,1,-1,0,0,0);
        }
    }else if(*(f32*)(self+0x10)<=lbl_805401F0&&(!fn_802412A4(p)||fn_80241200(p))&&!Player_GetField_0xce8(p)&&(tile==0x39||fn_80225BE4(self+8,*(s32*)(self+0x3b4)))){
        if(*(s32*)(self+0x3b4)<8)playerSprite64998(*(s32*)(self+0x3b4),&waterPos,table+0x24,*(u16*)(self+0x3ca),&water);
        else fn_803075AC(-20000-*(s32*)(self+4),*(s32*)(self+0x3b4),&waterPos,*(u16*)(self+0x3ca),0,1,-1,0,0,0);
    }
}
}
#pragma opt_common_subs reset
extern "C" void fn_80265AE4(char* p)
{
    Vec d1;
    Vec d2;
    if (*(unsigned short*)(p + 0x3c4) != *(unsigned short*)(p + 0x3c6) ||
        fnDist(p, &d1) > lbl_80540200) {
        *(int*)(p + 0x3d0) = *(int*)(p + 0x3d0) + 1;
        if (*(int*)(p + 0x3d0) >= 0x10) {
            *(int*)(p + 0x3d0) = 0;
        }
        *(int*)(p + 0x3cc) = 8;
        goto machine;
    }
    if (*(int*)(p + 0x3cc) > 0) {
        *(int*)(p + 0x3cc) = *(int*)(p + 0x3cc) - 1;
    } else {
        *(int*)(p + 0x3d0) = 0;
    }
machine:
    {
        int t = *(int*)(p + 0x3d0);
        if (t < 4) {
            *(short*)(p + 0x3c8) = 0x195;
        } else if (t < 8) {
            *(short*)(p + 0x3c8) = 0x196;
        } else if (t < 0xc) {
            *(short*)(p + 0x3c8) = 0x197;
        } else {
            *(short*)(p + 0x3c8) = 0x196;
        }
    }
    *(int*)(p + 0x3d4) = *(int*)(p + 0x3d4) + 1;
    if (*(int*)(p + 0x3d4) >= 0xc) {
        *(int*)(p + 0x3d4) = 0;
    }
    {
        int t = *(int*)(p + 0x3d4);
        if (t < 3) {
            *(short*)(p + 0x3ca) = 0x18f;
        } else if (t < 6) {
            *(short*)(p + 0x3ca) = 0x190;
        } else if (t < 9) {
            *(short*)(p + 0x3ca) = 0x191;
        } else {
            *(short*)(p + 0x3ca) = 0x190;
        }
    }
    if (*(f32*)(p + 0x10) <= lbl_805401F0 &&
        fn_8022461C(p + 8, *(int*)(p + 0x3b4)) == 0x39) {
        if (*(unsigned short*)(p + 0x3c4) != *(unsigned short*)(p + 0x3c6) ||
            fnDist(p, &d2) > lbl_80540200) {
            goto show;
        }
        goto hide;
    }
    goto hide;
show:
    if (*(unsigned int*)(p + 0x1384) == 0) {
        *(int*)(p + 0x1384) = fn_8013CC50(*(int*)(p + 0x3b4), p + 8, 0x4d2, 0, 0, 0, 0, 1,
                                          lbl_805401F4);
    } else {
        unsigned int em = *(unsigned int*)(p + 0x1384);
        fn_8013CB44((void*)em, p + 8, 0, 0, 1);
    }
    goto end;
hide:
    {
        unsigned int e = *(unsigned int*)(p + 0x1384);
        if (e != 0) {
            *(u32*)(e + 0xf4) |= 1;
            *(int*)(e + 0x24) = 1;
            *(int*)(p + 0x1384) = 0;
        }
    }
end:;
}

extern "C" void fn_80265D68(char* p)
{
    unsigned char v = *(unsigned char*)(p + 0xca0);
    if (v >= 8) {
        *(unsigned char*)(p + 0xca0) = v - 8;
        return;
    }
    *(unsigned char*)(p + 0xca0) = 0;
}

extern "C" void fn_80265D8C(char* p)
{
    unsigned char v = *(unsigned char*)(p + 0xca0);
    if (v <= 0xf7) {
        *(unsigned char*)(p + 0xca0) = v + 8;
        return;
    }
    *(unsigned char*)(p + 0xca0) = 0xff;
}

extern "C" void fn_80265DB0(char* p)
{
 unsigned short v=*(unsigned short*)(p+0x3c4);
 if(v==0x122 || (v>=0xb7 && v<0xbd) || *(int*)(p+0x3b4)>8) {
  *(unsigned char*)(p+0xca1)=0;return;
 }
 if(*(int*)(p+0x3b4)==8) {
  *(unsigned char*)(p+0xca1)=0xff;return;
 }
 if(fn_8025F448(p)!=0) {
  int n=*(int*)(p+0xd70);
  if(n<0 || fn_8023DE58(n)!=8) {
   if(*(unsigned char*)(p+0xca1)>=8) {
    *(unsigned char*)(p+0xca1)-=8;return;
   }
   *(unsigned char*)(p+0xca1)=0;return;
  }
 }
 if(*(unsigned char*)(p+0xca1)<=0xf7) {
  *(unsigned char*)(p+0xca1)+=8;return;
 }
 *(unsigned char*)(p+0xca1)=0xff;
}

extern "C" u8 Player_GetField_0x454(char* p);
extern "C" u8 fn_80241230(char* p);
extern "C" void fn_80268194(char* p);
extern "C" u8 fn_8025F684(char* p);
extern "C" void fn_80267018(char* p);
extern "C" void fn_802670CC(char* p);
extern "C" void fn_802671C8(char* p);
extern "C" void fn_80267384(char* p);
extern "C" void fn_80267470(char* p);
extern "C" void fn_80267598(char* p);
extern "C" void fn_80267684(char* p);
extern "C" void fn_80267748(char* p);
extern "C" void fn_80267818(char* p);
extern "C" void fn_802678CC(char* p);
extern "C" void fn_80267990(char* p);
extern "C" void fn_80267A54(char* p);
extern "C" void fn_80267B18(char* p);
extern "C" void fn_80267BA8(char* p);
extern "C" void fn_80267C6C(char* p);
extern "C" void fn_80267D30(char* p);
extern "C" void fn_80267E18(char* p);
extern "C" void fn_80267ECC(char* p);

struct StageMgr80264998 {
    u8 flag(u32 i) { return mFlags[i]; }
    u8 pad[0x131df];
    u8 mFlags[1];
};

// Picks the player's animation base by its 0x3dc posture (0..2, else).
#define PLAYER_ANIM4(p, a0, a1, a2, a3)                    \
    do {                                                   \
        int t_ = *(int*)((p) + 0x3dc);                     \
        if (t_ == 0) {                                     \
            *(unsigned short*)((p) + 0x3c4) = (a0);        \
        } else if (t_ == 1) {                              \
            *(unsigned short*)((p) + 0x3c4) = (a1);        \
        } else if (t_ == 2) {                              \
            *(unsigned short*)((p) + 0x3c4) = (a2);        \
        } else {                                           \
            *(unsigned short*)((p) + 0x3c4) = (a3);        \
        }                                                  \
    } while (0)
extern "C" void fn_80265E88(char* p)
{
    *(unsigned short*)(p + 0x3c6) = *(unsigned short*)(p + 0x3c4);
    if (*(u8*)(p + 0xcfe) != 0) {
        if (*(float*)(p + 0x10) > lbl_805401F0) {
            *(unsigned short*)(p + 0x3c4) = 0xc2;
        } else {
            *(unsigned short*)(p + 0x3c4) = 0xc3;
        }
        return;
    }
    if (*(u8*)(p + 0x456) == 1) {
        *(unsigned short*)(p + 0x3c4) = *(unsigned short*)(p + 0x450);
        p[0xca0] = p[0xca2];
        p[0x456] = 0;
        return;
    }
    if (Player_GetField_0x454(p)) {
        *(unsigned short*)(p + 0x3c4) = *(unsigned short*)(p + 0x450);
        p[0xca0] = p[0xca2];
        return;
    }
    if (fn_80241230(p) == 0 && *(int*)(p + 0x488) == 0 && (*(int*)(p + 0x464) & 2) == 2) {
        *(unsigned short*)(p + 0x3c4) = 0x121;
        return;
    }
    switch (*(u32*)(p + 0x1240)) {
    case 0:
        fn_80268194(p);
        break;
    case 1:
        *(unsigned short*)(p + 0x3c4) = 0x31d;
        break;
    case 2:
    case 3:
    case 56:
        PLAYER_ANIM4(p, 0, 8, 0x10, 0x18);
        *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3f9);
        break;
    case 4:
        fn_80267ECC(p);
        break;
    case 5:
    case 6:
        PLAYER_ANIM4(p, 0x1c6, 0x1c9, 0x1cc, 0x1cf);
        *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3fb);
        break;
    case 7:
        PLAYER_ANIM4(p, 0x262, 0x268, 0x26e, 0x274);
        *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3fb);
        break;
    case 8:
        fn_80267E18(p);
        break;
    case 9:
    case 10:
        fn_80267D30(p);
        break;
    case 11:
        fn_80267C6C(p);
        break;
    case 12:
        if (*(unsigned char*)(p + 0x3fd) == 0) {
            *(unsigned short*)(p + 0x3c4) = 0x3e;
        } else if (*(unsigned char*)(p + 0x3fd) == 1) {
            *(unsigned short*)(p + 0x3c4) = 0x3d;
        } else if (*(unsigned char*)(p + 0x3fd) == 2) {
            *(unsigned short*)(p + 0x3c4) = 0x3f;
        } else {
            *(unsigned short*)(p + 0x3c4) = 0x3c;
        }
        break;
    case 17:
        PLAYER_ANIM4(p, 0x2b0, 0x2b4, 0x2b8, 0x2bc);
        *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3fd);
        break;
    case 18:
        PLAYER_ANIM4(p, 0x2c0, 0x2c4, 0x2c8, 0x2cf);
        *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3f9);
        break;
    case 19:
        PLAYER_ANIM4(p, 0x36d, 0x36f, 0x371, 0x373);
        *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3f9);
        break;
    case 20:
        fn_80267BA8(p);
        break;
    case 21:
        PLAYER_ANIM4(p, 0x322, 0x327, 0x32c, 0x331);
        *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3fd);
        break;
    case 22:
    case 23:
        PLAYER_ANIM4(p, 0x322, 0x327, 0x32c, 0x331);
        *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3fd);
        break;
    case 24:
        PLAYER_ANIM4(p, 0x322, 0x327, 0x32c, 0x331);
        *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3fd);
        break;
    case 25:
        if (*(unsigned char*)(p + 0x121c) != 0) {
            *(unsigned short*)(p + 0x3c4) = 0x31d;
        } else {
            *(unsigned short*)(p + 0x3c4) = *(unsigned char*)(p + 0x3fd) + 0x296;
        }
        break;
    case 13:
        PLAYER_ANIM4(p, 0x29a, 0x29e, 0x2a2, 0x2a9);
        *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3f9);
        break;
    case 14:
        PLAYER_ANIM4(p, 0x29a, 0x29e, 0x2a2, 0x2a9);
        *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3f9);
        break;
    case 26:
        PLAYER_ANIM4(p, 0x2d6, 0x2da, 0x2de, 0x2e2);
        *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3f9);
        break;
    case 27:
        if (*(unsigned char*)(p + 0x43f) != 0) break;
        if (fn_8025F684(p)) {
            PLAYER_ANIM4(p, 0x2c0, 0x2c4, 0x2c8, 0x2cf);
            *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3f9);
        } else if (*(unsigned char*)(p + 0x3fd) == 0) {
            PLAYER_ANIM4(p, 0, 8, 0x10, 0x18);
            *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3f9);
        } else if (*(unsigned char*)(p + 0x3fd) == 1) {
            fn_802671C8(p);
        } else if (*(unsigned char*)(p + 0x3fd) == 2) {
            fn_802670CC(p);
        } else {
            PLAYER_ANIM4(p, 0x33a, 0x33d, 0x340, 0x343);
            *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3f9);
        }
        break;
    case 28:
    case 29:
        if (*(unsigned char*)(p + 0xceb) == 1) {
            int idx = *(int*)(p + 0x3b4);
            if (((u8(*)[0x10000])fn_802D6A9C())[1][idx + 0x31df] != 0) {
                fn_802670CC(p);
            } else {
                fn_802671C8(p);
            }
        } else if (*(unsigned char*)(p + 0xcec) == 1) {
            PLAYER_ANIM4(p, 0x33a, 0x33d, 0x340, 0x343);
            *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3f9);
        } else if (fn_8025F684(p)) {
            PLAYER_ANIM4(p, 0x2c0, 0x2c4, 0x2c8, 0x2cf);
            *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3f9);
        } else {
            PLAYER_ANIM4(p, 0, 8, 0x10, 0x18);
            *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3f9);
        }
        break;
    case 30:
        *(unsigned short*)(p + 0x3c4) = *(unsigned char*)(p + 0x3fd) + 0xb7;
        break;
    case 31:
        fn_80268194(p);
        break;
    case 32:
    case 33:
        if (fn_8025F684(p)) {
            PLAYER_ANIM4(p, 0x2c0, 0x2c4, 0x2c8, 0x2cf);
            *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3f9);
        } else if (*(unsigned char*)(p + 0x3fd) == 1) {
            *(unsigned short*)(p + 0x3c4) = 0x31c;
        } else if (*(int*)(p + 0x3b4) < 8) {
            *(unsigned short*)(p + 0x3c4) = 0x121;
        } else {
            fn_80268194(p);
        }
        break;
    case 34:
    case 35:
        if (fn_8025F684(p)) {
            PLAYER_ANIM4(p, 0x2c0, 0x2c4, 0x2c8, 0x2cf);
            *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3f9);
        } else {
            fn_80268194(p);
        }
        break;
    case 38:
        if (*(unsigned char*)(p + 0x3f9) >= 0xb) {
            *(unsigned short*)(p + 0x3c4) = 0x121;
        } else {
            *(unsigned short*)(p + 0x3c4) = 0x3c2;
            *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3f9);
        }
        break;
    case 39:
        fn_802670CC(p);
        break;
    case 40:
        fn_802670CC(p);
        break;
    case 41:
        fn_802671C8(p);
        break;
    case 36:
        if (fn_8025F684(p)) {
            PLAYER_ANIM4(p, 0x2c0, 0x2c4, 0x2c8, 0x2cf);
            *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3f9);
        } else if (*(unsigned char*)(p + 0x3fd) == 1) {
            *(unsigned short*)(p + 0x3c4) = 0x31c;
        } else {
            *(unsigned short*)(p + 0x3c4) = 0x121;
        }
        break;
    case 37:
        if (fn_8025F684(p)) {
            PLAYER_ANIM4(p, 0x2c0, 0x2c4, 0x2c8, 0x2cf);
            *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3f9);
        } else {
            fn_80268194(p);
        }
        break;
    case 42:
    case 43:
        fn_80268194(p);
        break;
    case 44:
    case 45:
        *(unsigned short*)(p + 0x3c4) = 0xb0;
        break;
    case 46:
    case 47:
        *(unsigned short*)(p + 0x3c4) = 0xb0;
        break;
    case 48:
        *(unsigned short*)(p + 0x3c4) = 0x22c;
        *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3f9);
        break;
    case 49:
        if (*(int*)(p + 0x3b4) < 8) {
            *(unsigned short*)(p + 0x3c4) = 0x358;
            *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3f9);
        } else {
            *(unsigned short*)(p + 0x3c4) = 0x3e;
        }
        break;
    case 50:
        fn_80267B18(p);
        break;
    case 15:
    case 16:
        PLAYER_ANIM4(p, 0xa7, 0xab, 0xaf, 0xb3);
        *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3fd);
        break;
    case 51:
        if (*(unsigned char*)(p + 0xd2d) == 1 && *(int*)(p + 0xd30) >= 0x3c) {
            *(unsigned short*)(p + 0x3c4) = 0x3e;
        } else {
            *(unsigned short*)(p + 0x3c4) = *(unsigned char*)(p + 0x3fd) + 0xbd;
        }
        break;
    case 52:
        if (*(int*)(p + 0xd30) >= 0x1a4) {
            *(unsigned short*)(p + 0x3c4) = 0x3e;
        } else {
            *(unsigned short*)(p + 0x3c4) = 0xc3;
        }
        break;
    case 53:
        PLAYER_ANIM4(p, 0x28a, 0x28d, 0x290, 0x293);
        *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3fd);
        break;
    case 54:
        fn_80267ECC(p);
        break;
    case 57:
        fn_80267A54(p);
        break;
    case 58:
        fn_80267990(p);
        break;
    case 59:
        fn_802678CC(p);
        break;
    case 60:
        fn_80267818(p);
        break;
    case 61:
        PLAYER_ANIM4(p, 0x15b, 0x15f, 0x163, 0x167);
        *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3fb);
        break;
    case 62:
        fn_80267598(p);
        break;
    case 63:
        fn_80267470(p);
        break;
    case 64:
        fn_80267384(p);
        break;
    case 65:
        PLAYER_ANIM4(p, 0xa7, 0xab, 0xaf, 0xb3);
        *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3fd);
        break;
    case 66:
        fn_80268194(p);
        break;
    case 67:
        PLAYER_ANIM4(p, 0xa7, 0xab, 0xaf, 0xb3);
        *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3fd);
        break;
    case 68:
    case 69:
        fn_80267748(p);
        break;
    case 70:
        fn_80267684(p);
        break;
    case 71:
        PLAYER_ANIM4(p, 0x1a3, 0x1aa, 0x1b1, 0x1b8);
        *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3fb);
        break;
    case 72:
        PLAYER_ANIM4(p, 0x362, 0x364, 0x366, 0x368);
        *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3fb);
        break;
    case 73:
        if (*(int*)(p + 0x1178) == 0) {
            *(unsigned short*)(p + 0x3c4) = *(unsigned char*)(p + 0x3fd) + 0x35f;
        } else if (*(int*)(p + 0x1178) == 1) {
            *(unsigned short*)(p + 0x3c4) = *(unsigned char*)(p + 0x3fd) + 0x3d0;
        } else if (*(int*)(p + 0x1178) == 2) {
            *(unsigned short*)(p + 0x3c4) = *(unsigned char*)(p + 0x3fd) + 0x296;
        }
        break;
    case 55:
        PLAYER_ANIM4(p, 0x111, 0x115, 0x119, 0x11d);
        *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3fb);
        break;
    case 74:
        fn_802671C8(p);
        break;
    case 75:
        fn_802670CC(p);
        break;
    case 76:
        *(unsigned short*)(p + 0x3c4) = 0x3d0;
        break;
    case 77:
        if (*(unsigned char*)(p + 0x3fc) != 0) {
            *(unsigned short*)(p + 0x3c4) = 0x121;
        } else if (fn_8025F684(p)) {
            PLAYER_ANIM4(p, 0x36d, 0x36f, 0x371, 0x373);
            *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3f9);
        } else {
            *(unsigned short*)(p + 0x3c4) = 0xb0;
        }
        break;
    case 78:
        *(unsigned short*)(p + 0x3c4) = 0xb0;
        break;
    case 79:
        PLAYER_ANIM4(p, 0x302, 0x308, 0x30e, 0x314);
        *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3fb);
        break;
    case 80:
        fn_80267018(p);
        break;
    case 81:
        PLAYER_ANIM4(p, 0x31f, 0x31e, 0x321, 0x320);
        break;
    }
}

extern "C" void fn_80267018(char* p)
{
    int t;
    if (*(int*)(p + 0x3b4) < 8) {
        t = *(int*)(p + 0x3dc);
        if (t == 0) {
            *(short*)(p + 0x3c4) = 0x375;
        } else if (t == 1) {
            *(short*)(p + 0x3c4) = 0x37d;
        } else if (t == 2) {
            *(short*)(p + 0x3c4) = 0x385;
        } else {
            *(short*)(p + 0x3c4) = 0x38d;
        }
    } else {
        t = *(int*)(p + 0x3dc);
        if (t == 0) {
            *(short*)(p + 0x3c4) = 0x395;
        } else if (t == 1) {
            *(short*)(p + 0x3c4) = 0x39d;
        } else if (t == 2) {
            *(short*)(p + 0x3c4) = 0x3a5;
        } else {
            *(short*)(p + 0x3c4) = 0x3ad;
        }
    }
    *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3f9);
}

extern "C" void fn_802670CC(char* p)
{
    if (fn_802486A0(p) == 4) {
        int a = fn_80248778(p);
        int b = fn_80240888(p);
        if (b != a) {
            int t = *(int*)(p + 0x3dc);
            if (t == 0) {
                *(short*)(p + 0x3c4) = 0x1bf;
            } else if (t == 1) {
                *(short*)(p + 0x3c4) = 0x1c1;
            } else if (t == 2) {
                *(short*)(p + 0x3c4) = 0x1c3;
            } else {
                *(short*)(p + 0x3c4) = 0x1c3;
            }
            return;
        }
    }
    int t = *(int*)(p + 0x3dc);
    if (t == 0) {
        *(short*)(p + 0x3c4) = 0x20c;
    } else if (t == 1) {
        *(short*)(p + 0x3c4) = 0x214;
    } else if (t == 2) {
        *(short*)(p + 0x3c4) = 0x21c;
    } else {
        *(short*)(p + 0x3c4) = 0x224;
    }
    *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3f9);
}

extern "C" void fn_802671C8(char* p)
{
    int t;
    int r;
    int s;
    if (fn_802486A0(p) == 4) {
        r = fn_80248778(p);
        t = fn_80240888(p);
        if (t != r) {
            t = *(int*)(p + 0x3dc);
            if (t == 0) {
                *(unsigned short*)(p + 0x3c4) = 0x1bf;
            } else if (t == 1) {
                *(unsigned short*)(p + 0x3c4) = 0x1c1;
            } else if (t == 2) {
                *(unsigned short*)(p + 0x3c4) = 0x1c3;
            } else {
                *(unsigned short*)(p + 0x3c4) = 0x1c3;
            }
            return;
        }
    }
    s = *(unsigned char*)(p + 0x3fb);
    switch (s) {
    case 0:
        t = *(int*)(p + 0x3dc);
        if (t == 0) {
            *(unsigned short*)(p + 0x3c4) = 0x1e8;
        } else if (t == 1) {
            *(unsigned short*)(p + 0x3c4) = 0x1ec;
        } else if (t == 2) {
            *(unsigned short*)(p + 0x3c4) = 0x1f0;
        } else {
            *(unsigned short*)(p + 0x3c4) = 0x1f4;
        }
        *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3f9);
        break;
    case 1:
        *(unsigned short*)(p + 0x3c4) = 0x1f8;
        *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3f9);
        break;
    case 2:
        t = *(int*)(p + 0x3dc);
        if (t == 0) {
            *(unsigned short*)(p + 0x3c4) = 0x1fc;
        } else if (t == 1) {
            *(unsigned short*)(p + 0x3c4) = 0x200;
        } else if (t == 2) {
            *(unsigned short*)(p + 0x3c4) = 0x204;
        } else {
            *(unsigned short*)(p + 0x3c4) = 0x208;
        }
        *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3f9);
        break;
    case 3:
        *(unsigned short*)(p + 0x3c4) = 0x358;
        *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3f9);
        break;
    }
}

extern "C" void fn_80267384(char* p)
{
    if (fn_802486A0(p) == 4) {
        int a = fn_80248778(p);
        int b = fn_80240888(p);
        if (b != a) {
            int t = *(int*)(p + 0x3dc);
            if (t == 0) {
                *(short*)(p + 0x3c4) = 0x1bf;
            } else if (t == 1) {
                *(short*)(p + 0x3c4) = 0x1c1;
            } else if (t == 2) {
                *(short*)(p + 0x3c4) = 0x1c3;
            } else {
                *(short*)(p + 0x3c4) = 0x1c3;
            }
            return;
        }
    }
    int t = *(int*)(p + 0x3dc);
    if (t == 0) {
        *(short*)(p + 0x3c4) = 0x3c;
    } else if (t == 1) {
        *(short*)(p + 0x3c4) = 0x3d;
    } else if (t == 2) {
        *(short*)(p + 0x3c4) = 0x3e;
    } else {
        *(short*)(p + 0x3c4) = 0x3f;
    }
}

extern "C" char* lbl_8053AAF8;
extern "C" unsigned char Player_IsLinked(char* p);
extern "C" void fn_80267470(char* p)
{
    if ((((unsigned char)lbl_8053AAF8[0x82]) & (unsigned char)(1 << *(int*)(p + 4))) == 0 && Player_IsLinked(p) == 0) {
        *(short*)(p + 0x3c4) = 0x31d;
    } else {
        if (fn_802486A0(p) == 4) {
            int a = fn_80248778(p);
            int b = fn_80240888(p);
            if (b != a) {
                int t = *(int*)(p + 0x3dc);
                if (t == 0) {
                    *(short*)(p + 0x3c4) = 0x1bf;
                } else if (t == 1) {
                    *(short*)(p + 0x3c4) = 0x1c1;
                } else if (t == 2) {
                    *(short*)(p + 0x3c4) = 0x1c3;
                } else {
                    *(short*)(p + 0x3c4) = 0x1c3;
                }
                return;
            }
        }
        int t = *(int*)(p + 0x3dc);
        if (t == 0) {
            *(short*)(p + 0x3c4) = 0x3c;
        } else if (t == 1) {
            *(short*)(p + 0x3c4) = 0x3d;
        } else if (t == 2) {
            *(short*)(p + 0x3c4) = 0x3e;
        } else {
            *(short*)(p + 0x3c4) = 0x3f;
        }
    }
}

extern "C" void fn_80267598(char* p)
{
    if (fn_802486A0(p) == 4) {
        int a = fn_80248778(p);
        int b = fn_80240888(p);
        if (b != a) {
            int t = *(int*)(p + 0x3dc);
            if (t == 0) {
                *(short*)(p + 0x3c4) = 0x1bf;
            } else if (t == 1) {
                *(short*)(p + 0x3c4) = 0x1c1;
            } else if (t == 2) {
                *(short*)(p + 0x3c4) = 0x1c3;
            } else {
                *(short*)(p + 0x3c4) = 0x1c3;
            }
            return;
        }
    }
    int t = *(int*)(p + 0x3dc);
    if (t == 0) {
        *(short*)(p + 0x3c4) = 0x3c;
    } else if (t == 1) {
        *(short*)(p + 0x3c4) = 0x3d;
    } else if (t == 2) {
        *(short*)(p + 0x3c4) = 0x3e;
    } else {
        *(short*)(p + 0x3c4) = 0x3f;
    }
}

extern "C" void fn_80267684(char* p)
{
    int t;
    if (*(unsigned char*)(p + 0x458) == 1) {
        t = *(int*)(p + 0x3dc);
        if (t == 0) {
            *(short*)(p + 0x3c4) = 0x262;
        } else if (t == 1) {
            *(short*)(p + 0x3c4) = 0x268;
        } else if (t == 2) {
            *(short*)(p + 0x3c4) = 0x26e;
        } else {
            *(short*)(p + 0x3c4) = 0x274;
        }
        *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3fb);
        return;
    }
    t = *(int*)(p + 0x3dc);
    if (t == 0) {
        *(short*)(p + 0x3c4) = 0xf1;
    } else if (t == 1) {
        *(short*)(p + 0x3c4) = 0xf9;
    } else if (t == 2) {
        *(short*)(p + 0x3c4) = 0x101;
    } else {
        *(short*)(p + 0x3c4) = 0x109;
    }
    *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3fb);
}

extern "C" void fn_80267748(char* p)
{
    int t;
    if (*(unsigned char*)(p + 0xb84) != 0 && *(unsigned char*)(p + 0x3fb) >= 5) {
        t = *(int*)(p + 0x3dc);
        if (t == 0) {
            *(short*)(p + 0x3c4) = 0x1d2;
        } else if (t == 1) {
            *(short*)(p + 0x3c4) = 0x1d6;
        } else if (t == 2) {
            *(short*)(p + 0x3c4) = 0x1da;
        } else {
            *(short*)(p + 0x3c4) = 0x1e1;
        }
        *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3f9);
        return;
    }
    t = *(int*)(p + 0x3dc);
    if (t == 0) {
        *(short*)(p + 0x3c4) = 0x18b;
    } else if (t == 1) {
        *(short*)(p + 0x3c4) = 0x191;
    } else if (t == 2) {
        *(short*)(p + 0x3c4) = 0x197;
    } else {
        *(short*)(p + 0x3c4) = 0x19d;
    }
    *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3fb);
}

extern "C" void fn_80267818(char* p)
{
    int t;
    if (*(unsigned char*)(p + 0xb9b) == 1) {
        t = *(int*)(p + 0x3dc);
        if (t == 0) {
            *(short*)(p + 0x3c4) = 0x16b;
        } else if (t == 1) {
            *(short*)(p + 0x3c4) = 0x173;
        } else if (t == 2) {
            *(short*)(p + 0x3c4) = 0x17b;
        } else {
            *(short*)(p + 0x3c4) = 0x183;
        }
    } else {
        t = *(int*)(p + 0x3dc);
        if (t == 0) {
            *(short*)(p + 0x3c4) = 0x123;
        } else if (t == 1) {
            *(short*)(p + 0x3c4) = 0x12a;
        } else if (t == 2) {
            *(short*)(p + 0x3c4) = 0x131;
        } else {
            *(short*)(p + 0x3c4) = 0x138;
        }
    }
    *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3fb);
}

extern "C" void fn_802678CC(char* p)
{
    int t;
    if (*(unsigned char*)(p + 0x3fb) == 1) {
        t = *(int*)(p + 0x3dc);
        if (t == 0) {
            *(short*)(p + 0x3c4) = 0x2f6;
        } else if (t == 1) {
            *(short*)(p + 0x3c4) = 0x2f9;
        } else if (t == 2) {
            *(short*)(p + 0x3c4) = 0x2fc;
        } else {
            *(short*)(p + 0x3c4) = 0x2ff;
        }
        *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3f9);
        return;
    }
    t = *(int*)(p + 0x3dc);
    if (t == 0) {
        *(short*)(p + 0x3c4) = 0x2e6;
    } else if (t == 1) {
        *(short*)(p + 0x3c4) = 0x2ea;
    } else if (t == 2) {
        *(short*)(p + 0x3c4) = 0x2ee;
    } else {
        *(short*)(p + 0x3c4) = 0x2f2;
    }
    *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3fb);
}

extern "C" void fn_80267990(char* p)
{
    int t;
    if (*(unsigned char*)(p + 0x3fb) == 1) {
        t = *(int*)(p + 0x3dc);
        if (t == 0) {
            *(short*)(p + 0x3c4) = 0x14f;
        } else if (t == 1) {
            *(short*)(p + 0x3c4) = 0x152;
        } else if (t == 2) {
            *(short*)(p + 0x3c4) = 0x155;
        } else {
            *(short*)(p + 0x3c4) = 0x158;
        }
        *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3f9);
        return;
    }
    t = *(int*)(p + 0x3dc);
    if (t == 0) {
        *(short*)(p + 0x3c4) = 0x13f;
    } else if (t == 1) {
        *(short*)(p + 0x3c4) = 0x143;
    } else if (t == 2) {
        *(short*)(p + 0x3c4) = 0x147;
    } else {
        *(short*)(p + 0x3c4) = 0x14b;
    }
    *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3fb);
}

extern "C" void fn_80267A54(char* p)
{
    int t;
    if (*(unsigned char*)(p + 0x3fb) == 0) {
        t = *(int*)(p + 0x3dc);
        if (t == 0) {
            *(short*)(p + 0x3c4) = 0;
        } else if (t == 1) {
            *(short*)(p + 0x3c4) = 8;
        } else if (t == 2) {
            *(short*)(p + 0x3c4) = 0x10;
        } else {
            *(short*)(p + 0x3c4) = 0x18;
        }
        *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3f9);
        return;
    }
    t = *(int*)(p + 0x3dc);
    if (t == 0) {
        *(short*)(p + 0x3c4) = 0xc5;
    } else if (t == 1) {
        *(short*)(p + 0x3c4) = 0xc9;
    } else if (t == 2) {
        *(short*)(p + 0x3c4) = 0xcd;
    } else {
        *(short*)(p + 0x3c4) = 0xd4;
    }
    *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3f9);
}

extern "C" void fn_80267B18(char* p)
{
    int t;
    if (*(int*)(p + 0xcf4) == 0xd) {
        *(short*)(p + 0x3c4) = 0x121;
        return;
    }
    if (*(unsigned char*)(p + 0x3fb) == 0) {
        *(short*)(p + 0x3c4) = *(unsigned char*)(p + 0x3fd) + 0xb7;
        return;
    }
    t = *(int*)(p + 0x3dc);
    if (t == 0) {
        *(short*)(p + 0x3c4) = 0xa7;
    } else if (t == 1) {
        *(short*)(p + 0x3c4) = 0xab;
    } else if (t == 2) {
        *(short*)(p + 0x3c4) = 0xaf;
    } else {
        *(short*)(p + 0x3c4) = 0xb3;
    }
    *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3fd);
}

extern "C" void fn_80267BA8(char* p)
{
    int t;
    if (*(unsigned char*)(p + 0x3fb) == 1) {
        t = *(int*)(p + 0x3dc);
        if (t == 0) {
            *(short*)(p + 0x3c4) = 0x322;
        } else if (t == 1) {
            *(short*)(p + 0x3c4) = 0x327;
        } else if (t == 2) {
            *(short*)(p + 0x3c4) = 0x32c;
        } else {
            *(short*)(p + 0x3c4) = 0x331;
        }
        *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3fd);
        return;
    }
    t = *(int*)(p + 0x3dc);
    if (t == 0) {
        *(short*)(p + 0x3c4) = 0x36d;
    } else if (t == 1) {
        *(short*)(p + 0x3c4) = 0x36f;
    } else if (t == 2) {
        *(short*)(p + 0x3c4) = 0x371;
    } else {
        *(short*)(p + 0x3c4) = 0x373;
    }
    *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3f9);
}

extern "C" void fn_80267C6C(char* p)
{
    int t;
    if (*(unsigned char*)(p + 0x3fd) == 1) {
        t = *(int*)(p + 0x3dc);
        if (t == 0) {
            *(short*)(p + 0x3c4) = 0x33a;
        } else if (t == 1) {
            *(short*)(p + 0x3c4) = 0x33d;
        } else if (t == 2) {
            *(short*)(p + 0x3c4) = 0x340;
        } else {
            *(short*)(p + 0x3c4) = 0x343;
        }
        *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3fb);
        return;
    }
    t = *(int*)(p + 0x3dc);
    if (t == 0) {
        *(short*)(p + 0x3c4) = 0x346;
    } else if (t == 1) {
        *(short*)(p + 0x3c4) = 0x34a;
    } else if (t == 2) {
        *(short*)(p + 0x3c4) = 0x34e;
    } else {
        *(short*)(p + 0x3c4) = 0x352;
    }
    *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3fb);
}

extern "C" void fn_80267D30(char* p)
{
    unsigned char b;
    int t = *(int*)(p + 0x3dc);
    if (t == 0) {
        b = *(unsigned char*)(p + 0x3fb);
        if (b < 8) {
            *(unsigned short*)(p + 0x3c4) = (unsigned char)((b & 7) + 0x8f);
        } else {
            *(unsigned short*)(p + 0x3c4) = (unsigned char)(b + 0x8f);
        }
    } else if (t == 1) {
        b = *(unsigned char*)(p + 0x3fb);
        if (b < 8) {
            *(unsigned short*)(p + 0x3c4) = (unsigned char)(((b + 4) & 7) + 0x8f);
        } else {
            *(unsigned short*)(p + 0x3c4) = (unsigned char)(b + 0x93);
        }
    } else if (t == 2) {
        b = *(unsigned char*)(p + 0x3fb);
        if (b < 8) {
            *(unsigned short*)(p + 0x3c4) = (unsigned char)(((b + 2) & 7) + 0x8f);
        } else {
            *(unsigned short*)(p + 0x3c4) = (unsigned char)(b + 0x97);
        }
    } else {
        b = *(unsigned char*)(p + 0x3fb);
        if (b < 8) {
            *(unsigned short*)(p + 0x3c4) = (unsigned char)(((b + 6) & 7) + 0x8f);
        } else {
            *(unsigned short*)(p + 0x3c4) = (unsigned char)(b + 0x9b);
        }
    }
}

extern "C" void fn_80267E18(char* p)
{
    int t;
    if (*(unsigned char*)(p + 0x403) >= 0xa8) {
        t = *(int*)(p + 0x3dc);
        if (t == 0) {
            *(short*)(p + 0x3c4) = 0x6f;
        } else if (t == 1) {
            *(short*)(p + 0x3c4) = 0x77;
        } else if (t == 2) {
            *(short*)(p + 0x3c4) = 0x7f;
        } else {
            *(short*)(p + 0x3c4) = 0x87;
        }
    } else {
        t = *(int*)(p + 0x3dc);
        if (t == 0) {
            *(short*)(p + 0x3c4) = 0x43;
        } else if (t == 1) {
            *(short*)(p + 0x3c4) = 0x4b;
        } else if (t == 2) {
            *(short*)(p + 0x3c4) = 0x53;
        } else {
            *(short*)(p + 0x3c4) = 0x61;
        }
    }
    *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3f9);
}

extern "C" void fn_80267ECC(char* p)
{
    int t;
    if (*(unsigned char*)(p + 0x3fb) >= 8) {
        if (fn_802486A0(p) == 4) {
            int a = fn_80248778(p);
            int b = fn_80240888(p);
            if (b != a) {
                t = *(int*)(p + 0x3dc);
                if (t == 0) {
                    *(short*)(p + 0x3c4) = 0x1bf;
                } else if (t == 1) {
                    *(short*)(p + 0x3c4) = 0x1c1;
                } else if (t == 2) {
                    *(short*)(p + 0x3c4) = 0x1c3;
                } else {
                    *(short*)(p + 0x3c4) = 0x1c3;
                }
                return;
            }
        }
        t = *(int*)(p + 0x3dc);
        if (t == 0) {
            *(short*)(p + 0x3c4) = 0x3c;
        } else if (t == 1) {
            *(short*)(p + 0x3c4) = 0x3d;
        } else if (t == 2) {
            *(short*)(p + 0x3c4) = 0x3e;
        } else {
            *(short*)(p + 0x3c4) = 0x3f;
        }
    } else {
        switch (*(int*)(p + 0x45c)) {
        case 0:
            t = *(int*)(p + 0x3dc);
            if (t == 0) {
                *(short*)(p + 0x3c4) = 0x20;
            } else if (t == 1) {
                *(short*)(p + 0x3c4) = 0x27;
            } else if (t == 2) {
                *(short*)(p + 0x3c4) = 0x2e;
            } else {
                *(short*)(p + 0x3c4) = 0x35;
            }
            break;
        case 1:
            t = *(int*)(p + 0x3dc);
            if (t == 0) {
                *(short*)(p + 0x3c4) = 0x232;
            } else if (t == 1) {
                *(short*)(p + 0x3c4) = 0x23a;
            } else if (t == 2) {
                *(short*)(p + 0x3c4) = 0x242;
            } else {
                *(short*)(p + 0x3c4) = 0x24a;
            }
            break;
        case 2:
            t = *(int*)(p + 0x3dc);
            if (t == 0) {
                *(short*)(p + 0x3c4) = 0x252;
            } else if (t == 1) {
                *(short*)(p + 0x3c4) = 0x256;
            } else if (t == 2) {
                *(short*)(p + 0x3c4) = 0x25a;
            } else {
                *(short*)(p + 0x3c4) = 0x25e;
            }
            break;
        case 3:
            t = *(int*)(p + 0x3dc);
            if (t == 0) {
                *(short*)(p + 0x3c4) = 0x27a;
            } else if (t == 1) {
                *(short*)(p + 0x3c4) = 0x27e;
            } else if (t == 2) {
                *(short*)(p + 0x3c4) = 0x282;
            } else {
                *(short*)(p + 0x3c4) = 0x286;
            }
            break;
        case 4:
            t = *(int*)(p + 0x3dc);
            if (t == 0) {
                *(short*)(p + 0x3c4) = 0x262;
            } else if (t == 1) {
                *(short*)(p + 0x3c4) = 0x268;
            } else if (t == 2) {
                *(short*)(p + 0x3c4) = 0x26e;
            } else {
                *(short*)(p + 0x3c4) = 0x274;
            }
            *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3fb);
            return;
        }
        *(unsigned short*)(p + 0x3c4) += *(unsigned char*)(p + 0x3fb);
    }
}

extern "C" void fn_80268194(char* p)
{
    if (fn_802486A0(p) == 4) {
        int a = fn_80248778(p);
        int b = fn_80240888(p);
        if (b != a) {
            int t = *(int*)(p + 0x3dc);
            if (t == 0) {
                *(short*)(p + 0x3c4) = 0x1bf;
            } else if (t == 1) {
                *(short*)(p + 0x3c4) = 0x1c1;
            } else if (t == 2) {
                *(short*)(p + 0x3c4) = 0x1c3;
            } else {
                *(short*)(p + 0x3c4) = 0x1c3;
            }
            return;
        }
    }
    int t = *(int*)(p + 0x3dc);
    if (t == 0) {
        *(short*)(p + 0x3c4) = 0x3c;
    } else if (t == 1) {
        *(short*)(p + 0x3c4) = 0x3d;
    } else if (t == 2) {
        *(short*)(p + 0x3c4) = 0x3e;
    } else {
        *(short*)(p + 0x3c4) = 0x3f;
    }
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"
