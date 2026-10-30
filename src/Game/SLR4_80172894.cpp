#include "types.h"
#include "Game/SinitPoolChain.h"
#define GAME_ACTOR_USE_SDK_VEC
#include "Game/Actor.h"
#include "Game/ItemBase.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JGeometry/Box.h"

struct Box4 {
    f32 a, b, c, d;
};

struct Vec3f {
    f32 x, y, z;
};

extern "C" u8 fn_801F2B7C(void* this_, s32 a, s32 b, s32 c);
extern f32 lbl_804A0AD8[];
extern Box4 lbl_804A0B10[];
extern const f32 lbl_8053DAC0;
extern const f32 lbl_8053DAC8;
extern "C" s32 fn_801F285C(void* this_, s32 a, s32 b, s32 c, s32 d);
extern "C" void fn_801EF510(void* this_);
extern "C" u8 fn_80235448(void);
extern "C" u8 fn_80237948(s32 idx, f32* pos);
extern "C" void fn_80230FD0(s32 idx, s32 id);
extern "C" s32 fn_8013CC50(u32 id, void* pos, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, f32 g);
extern "C" void* fn_802D6A9C(void);
extern Box4 lbl_804A0A58[];
extern const f32 lbl_8053DB48;

extern "C" void* fn_801F856C(void);
extern "C" s32 Actor_CreateByID(void* base, u32 fourCC, u32 owner, void* posPtr, s32 a, s32 b, s32 c);
extern "C" void* fn_801F666C(void* base, s32 id);
static inline void* slr4FindActor(s32 id) {
    return fn_801F666C(fn_801F856C(), id);
}
extern "C" s32 fn_8023DE58(s32 a);
extern u8 lbl_80529DEC[];
extern const f32 lbl_8053DB4C;
extern const f32 lbl_8053DB00;
extern const f32 lbl_8053DB04;
extern const f32 lbl_8053DB20;
extern const f32 lbl_8053DB24;
extern const f32 lbl_8053DB28;
extern const f32 lbl_8053DB2C;
extern const f32 lbl_8053DB30;
extern const f32 lbl_8053DB34;
extern const f32 lbl_8053DB38;
extern const f32 lbl_8053DB3C;
extern const f32 lbl_8053DB40;
extern const f32 lbl_8053DB44;
extern const f32 lbl_8053DACC;
extern const f32 lbl_8053DAD0;
extern s32 lbl_804A0AF8[];
extern u8 lbl_80539F78[8];
extern "C" u8 fn_802DE814(void);
extern "C" void fn_801746DC(void* this_);
extern u8 lbl_8053AB60;
extern const f32 lbl_8053DAB8;
extern const f32 lbl_8053DABC;
extern const f32 lbl_8053DAC0;
extern char lbl_80466808[];
extern "C" void fn_80172BC8(void* this_);
extern "C" void fn_801F02BC(void* this_, char* name, s32 id, DrawRec* rec, s32 a, s32 b, s32 c, f32 s0, f32 s1);
extern "C" void fn_801EF574(void* a, void* b, f32* v, DrawRec* rec);
extern "C" void fn_803075AC(void*, s32, void*, s32, s32, s32, s32, s32, s32, s32);
struct PukuResMgr {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void* get(u32 type, const char* name);
};
struct PukuGameRes {
    u8 pad[0xa4];
    PukuResMgr* res;
};
extern "C" void fn_802F86CC(void* layer, void* pos, void* res, s32 id, f32 sx, f32 sy, DrawRec* rec);
extern void* lbl_8053AAF8;
extern u8* lbl_8053AB10;
extern const f32 lbl_8053DAB8;
extern const f32 lbl_8053DABC;
extern const f32 lbl_8053DAC0;
extern char lbl_80466808[];
extern "C" void v07__5ActorFv(void* this_);
extern "C" void fn_80172894(void* this_) {
    char* p = (char*)this_;
    if ((s32)(*(u32*)(p + 0x90) & 0xff) == 6) {
        *(s32*)(p + 0x18c) = 0;
        Actor_CreateByID(fn_801F856C(), 0x48415254, *(u32*)(p + 0x4), p + 0xc, 0, -1, -1);
    }
    v07__5ActorFv(this_);
}

extern "C" void fn_80172900(void* this_) {
    register char* p = (char*)this_;
    DrawRec rec;
    f32 mtx[3][4];

    mtx[0][3] = 0.0f;
    mtx[1][3] = 0.0f;
    mtx[2][3] = 0.0f;
    if (lbl_8053AB60 != 1) {
        s32 mode = *(u32*)(p + 0x90) & 0xff;
        if (mode == 7 || mode == 8) {
            fn_80172BC8(this_);
        } else {
            BOOL bVar1 = 0;
            rec.ids[1] = *(u8*)(p + 0x234);
            if (*(s32*)(p + 0x230) == 6 && *(s32*)(p + 0x264) >= 3) {
                rec.w30 = 0x11;
            }
            if (*(s32*)(p + 0x4) >= 8) {
                if (*(s32*)(p + 0x23c) == 1) {
                    bVar1 = 1;
                    mtx[0][0] = lbl_8053DABC;
                    mtx[0][1] = lbl_8053DAB8;
                    mtx[0][2] = lbl_8053DAB8;
                    mtx[1][0] = lbl_8053DAB8;
                    mtx[1][1] = lbl_8053DABC;
                    mtx[1][2] = lbl_8053DAB8;
                    mtx[2][0] = lbl_8053DAB8;
                    mtx[2][1] = lbl_8053DAB8;
                    mtx[2][2] = lbl_8053DABC;
                    rec.w18 = mtx;
                }
                Box4 box = *(Box4*)((char*)fn_802D6A9C() + 0xcc);
                Vec3f v;
                    v.x = *(f32*)(p + 0xc);
                    v.y = *(f32*)(p + 0x10);
                    v.z = *(f32*)(p + 0x14);
                    v.x += box.a;
                    v.y += box.b;
                if ((s32)(*(u32*)(p + 0x90) & 0xff) != 6) {
                    fn_801EF574(lbl_80466808, (void*)(*(s32*)(p + 0x280) + 0x226), (f32*)&v, &rec);
                }
                fn_803075AC(*(void**)(p + 0x198), *(s32*)(p + 0x4), p + 0xc, *(s32*)(p + 0x280) + 0x318, (bool)bVar1, 2, -1, 0, 0, 0);
            } else {
                fn_801F02BC(this_, lbl_80466808, *(s32*)(p + 0x280) + 0x226, &rec, 7, 0, 0, lbl_8053DAC0, lbl_8053DAC0);
            }
        }
    }
}

extern "C" void fn_80172BC8(void* this_) {
    register char* p = (char*)this_;
    DrawRec rec;
    f32 mtx[3][4];
    mtx[0][3] = lbl_8053DAB8;
    mtx[1][3] = lbl_8053DAB8;
    mtx[2][3] = lbl_8053DAB8;
    if (*(u32*)(p + 0x90) != 7) {
        mtx[0][0] = lbl_8053DABC;
        mtx[0][1] = lbl_8053DAB8;
        mtx[0][2] = lbl_8053DAB8;
        mtx[1][0] = lbl_8053DAB8;
        mtx[1][2] = lbl_8053DAB8;
        mtx[1][1] = lbl_8053DABC;
        mtx[2][0] = lbl_8053DAB8;
        mtx[2][2] = lbl_8053DABC;
        mtx[2][1] = lbl_8053DAB8;
        if (*(s32*)(p + 0x23c) == 0) {
            mtx[0][0] = lbl_8053DAC0;
            mtx[0][1] = lbl_8053DAB8;
            mtx[0][2] = lbl_8053DAB8;
            mtx[1][1] = lbl_8053DAC0;
            mtx[1][0] = lbl_8053DAB8;
            mtx[1][2] = lbl_8053DAB8;
            mtx[2][0] = lbl_8053DAB8;
            mtx[2][2] = lbl_8053DAC0;
            mtx[2][1] = lbl_8053DAB8;
        }
        rec.w18 = mtx;
    }
    register u32 id = *(s32*)(p + 0x280) + 0x3fd;
    if (*(s32*)(p + 4) < 8) {
        void* res = ((PukuGameRes*)lbl_8053AAF8)->res->get('SOB ', lbl_80466808);
        fn_802F86CC(*(void**)((char*)lbl_8053AB10 + 0x20), p + 0xc, res, id, lbl_8053DAC0, lbl_8053DAC0, &rec);
    }
}

extern "C" void fn_8030C210(void* a, void* b);
extern "C" void fn_8043E7CC(void* a, ...);
extern "C" void fn_801752D8(void* this_);
extern "C" void fn_80175024(void* this_);
extern "C" s32 fn_801F3D94(void* this_, s32 a);
extern "C" void fn_801F2618(void* this_, s32 a, s32 b);
extern "C" void fn_80174220(void* this_);
extern void* lbl_8053AED0;
extern "C" JGeometry::TVec3f* fn_8023E724(s32);
extern "C" s32 ClassifyBamAngleToQuadrant(u16);
extern "C" void fn_801F71A4(void*,f32,f32,f32);
extern "C" void fn_801EEC98(void*,s32,void*,void*,void*,s32,s32,s32);
extern "C" u8 fn_801F2FAC(void*);
extern "C" u8 fn_801F2DB4(void*,u32,u32,s32);
extern "C" void fn_801F0E34(void*,u32,s32);
extern "C" void fn_80458FF0(void*,u32,s32,s32);
extern void* lbl_8053AF80;
extern const f32 lbl_8053DAC4,lbl_8053DAD4,lbl_8053DAD8,lbl_8053DADC,lbl_8053DAE0,lbl_8053DAE4,lbl_8053DAE8,lbl_8053DAEC,lbl_8053DAF0,lbl_8053DAF4,lbl_8053DAF8,lbl_8053DAFC,lbl_8053DB08,lbl_8053DB0C;
extern s32 lbl_804A0920[];
static inline f32 slr4Random() {
    union { u32 bits; f32 value; } out;
    u32* seed=(u32*)((u8*)lbl_8053AAF8+0xb4);
    *seed=*seed*0x19660d+0x3c6ef35f;
    out.bits=(*seed>>9)|0x3f800000;
    return out.value-1.0f;
}

extern "C" void fn_80172DC4(void* this_) {
    char* p=(char*)this_;
    s16 angle=0;
    s32 direction=0;
    f32 distance=lbl_8053DAB8;
    JGeometry::TVec3f pos;
    if(lbl_8053AB60==1) { (*(f32*)(p+0xc))=(*(f32*)(p+0x2b4)); (*(f32*)(p+0x10))=(*(f32*)(p+0x2b8)); (*(f32*)(p+0x14))=(*(f32*)(p+0x2bc)); return; }
    fn_8030C210(*(void**)(lbl_8053AB10+0x24),p+0xc);
    JGeometry::TVec3f save((*(JGeometry::TVec3f*)(p+0xc)));
    ((void(*)(void*,JGeometry::TVec3f))fn_8043E7CC)(lbl_8053AED0,(*(JGeometry::TVec3f*)(p+0xc)));
    if((s32)((*(u32*)(p+0x90))&0xff)==7 || (s32)((*(u32*)(p+0x90))&0xff)==8) { fn_80174220(p);return; }
    if((*(s32*)(p+0x230))!=8 && (*(s32*)(p+0x230))!=9) fn_801752D8(p);
    fn_80175024(p);
    if(fn_801F3D94(p,1)) {
        fn_801F2618(p,0,0);
        if((*(s32*)(p+0x23c))==0) { (*(s32*)(p+0x250))=20;return; }
        (*(s32*)(p+0x254))=1;(*(s32*)(p+0x250))=60;
    }
    if((*(s32*)(p+0x230))!=8 && (*(s32*)(p+0x230))!=9 && (*(s32*)(p+0xd8))==0) {
        for(s32 i=0;i<4;i++) {
            s32 player=fn_801F285C(p,0,0,1,i);
            if((*(u16*)(p+0x94))!=0) player=(*(u16*)(p+0x94))-1;
            if(player<0) continue;
            if(((u8(*)(s32))fn_80235448)(player)) break;
            f32 dx=(*(f32*)(p+0xc))-fn_8023E724(player)->x;
            f32 dy=(*(f32*)(p+0x10))-fn_8023E724(player)->y;
            u16 a=(s32)(JMAAtan2Radian(-dx,-dy)*lbl_8053DAC4);
            if((*(s32*)(p+0x98))!=ClassifyBamAngleToQuadrant(a)) break;
            (*(s32*)(p+0x254))=1;
            f32 y0=(*(f32*)(p+0x64))+(*(f32*)(p+0x10)), y1=(*(f32*)(p+0x6c))+(*(f32*)(p+0x10));
            f32 x0=(*(f32*)(p+0x60))+(*(f32*)(p+0xc)), x1=(*(f32*)(p+0x68))+(*(f32*)(p+0xc));
            JGeometry::TVec2f center;
            center.set(lbl_8053DAC8*(x0-x1)+x1,lbl_8053DAC8*(y0-y1)+y1);
            if((*(u16*)(p+0x94))!=0 || ((*(u16*)(p+0x94))==0 && fn_80237948(player,(f32*)&center))) {
                fn_801F0E34(p,0x400d1,0);
                if((*(u16*)(p+0x94))==0) {
                    fn_8013CC50((*(u32*)(p+0x4)),p+0xc,0x117,0,1,0,0,1,lbl_8053DAC0);
                    fn_8013CC50((*(u32*)(p+0x4)),p+0xc,0x118,0,1,0,0,1,lbl_8053DAC0);
                }
                (*(JGeometry::TVec3f*)(p+0x2a8)).zero();(*(s32*)(p+0x258))=40;(*(s32*)(p+0x24c))=0;
                if((*(u32*)(p+0x90))!=4 && (*(u32*)(p+0x90))!=5 && (*(u32*)(p+0x90))!=6 && (*(s32*)(p+0x230))==0) (*(s32*)(p+0x230))=1;
                if((*(u32*)(p+0x90))==2 || (*(u32*)(p+0x90))==3) {
                    if((*(s32*)(p+0x23c))==0 && *((u8*)lbl_8053AAF8+0x7f)==1) fn_80458FF0(lbl_8053AF80,0x1000021,0,0);
                    (*(u32*)(p+0x90))+=2;(*(s32*)(p+0x240))=0;(*(s32*)(p+0x264))=0;(*(s32*)(p+0x250))=20;(*(s32*)(p+0x288))=2;
                    if((*(u8*)(p+0x2a5))==1) fn_801F0E34(p,0x5001f,0);
                    (*(s32*)(p+0x230))=2;
                }
                (*(JGeometry::TVec3f*)(p+0x2a8)).zero();
                switch((*(s32*)(p+0x98))^1) {
                case 0: (*(JGeometry::TVec3f*)(p+0x3c)).set(lbl_8053DACC,lbl_8053DAB8,lbl_8053DAB8);break;
                case 1: (*(JGeometry::TVec3f*)(p+0x3c)).set(lbl_8053DAD0,lbl_8053DAB8,lbl_8053DAB8);break;
                case 2: (*(JGeometry::TVec3f*)(p+0x3c)).set(lbl_8053DAB8,lbl_8053DACC,lbl_8053DAB8);break;
                case 3: (*(JGeometry::TVec3f*)(p+0x3c)).set(lbl_8053DAB8,lbl_8053DAD0,lbl_8053DAB8);break;
                }
            }
            break;
        }
        (*(u16*)(p+0x94))=0;
        s32 hp=(*(s32*)(p+0x108));
        if((*(s32*)(p+0xd8))==0 && ((*(s32*)(p+0x254))!=0 || fn_801F2FAC(p) || fn_801F2DB4(p,0x4e554c4c,0x4e554c4c,0))) {
            if(hp!=(*(s32*)(p+0x108))) {
                if((s32)((*(u32*)(p+0x90))&0xff)!=6 && (*(s32*)(p+0x4))>=8 && (*(s32*)(p+0x23c))==1) {
                    (*(s32*)(p+0x284))-=10000-(*(s32*)(p+0x108));
                    if((*(s32*)(p+0x284))<0) (*(s32*)(p+0x284))=0;
                    (*(s32*)(p+0x250))=0;(*(s32*)(p+0x108))=10000;(*(s32*)(p+0x29c))=0;
                    if(direction>=0) { (*(s32*)(p+0x98))=direction;(*(s32*)(p+0x240))=0;(*(s32*)(p+0x264))=0; }
                    if((*(u32*)(p+0x90))==4 || (*(u32*)(p+0x90))==5 || (*(u32*)(p+0x90))==6) (*(s32*)(p+0x230))=2;
                    else { (*(s32*)(p+0x248))=0;(*(s32*)(p+0x230))=0; }
                    (*(s32*)(p+0x250))=20;
                }
                if((*(s32*)(p+0x108))>0 && (*(s32*)(p+0x284))>0 && (*(s32*)(p+0x23c))==1) fn_801F0E34(p,0x4008c,0);
                else if((*(s32*)(p+0x108))<=0 || (*(s32*)(p+0x284))<=0) {
                    s32 id=(*(s32*)(p+0x238));
                    if(id>=0) {
                        void* obj=slr4FindActor(id);
                        if(obj) *((u8*)obj+0x11c)=0;
                    }
                    (*(s32*)(p+0x238))=-1;
                    if((*(s32*)(p+0x4))>=8 && (*(s32*)(p+0x23c))==1) {
                        for(s32 i=0;i<4;i++) {
                            s32 id=(*(s32*)(p+0x2c0+i*4));
                            if(id>=0) {
                                Actor* obj=(Actor*)slr4FindActor(id);
                                fn_801F0E34(p,0x4008d,0);
                                if(obj) obj->v07();
                                (*(s32*)(p+0x2c0+i*4))=-1;
                            }
                        }
                        (*(s32*)(p+0x230))=8;
                    }
                }
            }
            (*(s32*)(p+0x24c))=0;
            if((*(u32*)(p+0x90))!=4 && (*(u32*)(p+0x90))!=5 && (*(u32*)(p+0x90))!=6 && (*(s32*)(p+0x230))==0) (*(s32*)(p+0x230))=1;
            if((*(u32*)(p+0x90))==2 || (*(u32*)(p+0x90))==3) {
                if((*(s32*)(p+0x23c))==0 && *((u8*)lbl_8053AAF8+0x7f)==1) fn_80458FF0(lbl_8053AF80,0x1000021,0,0);
                (*(u32*)(p+0x90))+=2;(*(s32*)(p+0x240))=0;(*(s32*)(p+0x264))=0;(*(s32*)(p+0x250))=20;(*(s32*)(p+0x288))=2;
                if((*(u8*)(p+0x2a5))==1) fn_801F0E34(p,0x5001f,0);
                (*(s32*)(p+0x230))=2;
            }
            (*(s32*)(p+0x26c))=150;
        }
        fn_801F2618(p,0,0);
    }
    if((*(s32*)(p+0x23c))==0) return;
    fn_801F71A4(p+0x3c,(*(f32*)(p+0x2a8)),lbl_8053DAD4,lbl_8053DAC0);
    fn_801F71A4(p+0x40,(*(f32*)(p+0x2ac)),lbl_8053DAD4,lbl_8053DAC0);
    (*(JGeometry::TVec3f*)(p+0xc)).add((*(JGeometry::TVec3f*)(p+0x3c)));
    fn_801EEC98(p,(*(s32*)(p+0x198)),&angle,&direction,&distance,0,0,0);
    if((*(s32*)(p+0x29c))!=2 || (*(s32*)(p+0x264))<4) fn_801F2B7C(p,-100,-1,1);
    else if((s32)((*(u32*)(p+0x90))&0xff)==6) fn_801F2B7C(p,4,-1,3);
    u8 collision=((u8(*)(void*,s32,s32))fn_801F2618)(p,0,0);
    do {
        if ((*(s32*)(p+0x230))==0) goto state0;
        if ((*(s32*)(p+0x230))==1) goto state1;
        if ((*(s32*)(p+0x230))==2) goto state2;
        if ((*(s32*)(p+0x230))==3) goto state3;
        if ((*(s32*)(p+0x230))==4) goto state4;
        if ((*(s32*)(p+0x230))==5) goto state5;
        if ((*(s32*)(p+0x230))==6) goto state6;
        if ((*(s32*)(p+0x230))==7) goto state7;
        if ((*(s32*)(p+0x230))==8) goto state8;
        if ((*(s32*)(p+0x230))==9) goto state9;
        break;
    state0:
        if((*(s32*)(p+0x278))>0) --(*(s32*)(p+0x278));
        if((*(s32*)(p+0x278))==0 && (*(s32*)(p+0x290))<=0) {
            (*(s32*)(p+0x240))=0;(*(s32*)(p+0x264))=0;(*(s32*)(p+0x250))=20;
            if(((*(u32*)(p+0x90))==2 || (*(u32*)(p+0x90))==3) && (*(s32*)(p+0x290))==-1 && (*(u8*)(p+0x2a5))==1) {
                (*(s32*)(p+0x288))=2;fn_801F0E34(p,0x5001f,0);
            }
            if((*(s32*)(p+0x23c))==0 && *((u8*)lbl_8053AAF8+0x7f)==1) fn_80458FF0(lbl_8053AF80,0x1000021,0,0);
            (*(u32*)(p+0x90))=4;(*(s32*)(p+0x230))=2;break;
        }
        if((*(u32*)(p+0x90))==2 || (*(u32*)(p+0x90))==3) {
            (*(s32*)(p+0x230))=0;
            if((*(s32*)(p+0x294))==0 && (*(s32*)(p+0x298))==0) { (*(s32*)(p+0x288))=3;break; }
        }
        if(direction>=0) {
            if(((*(u32*)(p+0x90))!=2 && (*(u32*)(p+0x90))!=3) || (*(u8*)(p+0x2a5))==0) (*(s32*)(p+0x98))=direction;
            (*(s32*)(p+0x29c))=0;
        } else (*(s32*)(p+0x29c))=1;
        if((*(s32*)(p+0x248))==0) {
            if((*(s32*)(p+0x288))!=2) { (*(s32*)(p+0x288))^=1;(*(s32*)(p+0x288))&=1; }
            (*(s32*)(p+0x248))=(s32)(slr4Random()*lbl_8053DAD8)+200;
            if((*(s32*)(p+0x288))==0) {
                if((*(s32*)(p+0x294))!=0) (*(s32*)(p+0x248))=(*(s32*)(p+0x294));
                if((*(s32*)(p+0x278))==0 && (*(s32*)(p+0x290))!=0) fn_801F0E34(p,0x4008e,0);
            } else {
                if((*(s32*)(p+0x298))!=0) (*(s32*)(p+0x248))=(*(s32*)(p+0x298));
                if((*(s32*)(p+0x278))==0 && (*(s32*)(p+0x290))!=0) fn_801F0E34(p,0x4008f,0);
            }
            if((*(u32*)(p+0x90))!=2 && (*(u32*)(p+0x90))!=3) (*(s32*)(p+0x230))=1;
        }
        break;
    state1:
        if((*(s32*)(p+0x248))==0) { (*(s32*)(p+0x230))=0;break; }
        if((*(s32*)(p+0x24c))==0) {
            (*(s32*)(p+0x24c))=10;
            if(direction<0) { (*(JGeometry::TVec3f*)(p+0x2a8)).zero();(*(JGeometry::TVec3f*)(p+0x3c)).zero();(*(s32*)(p+0x29c))=1;break; }
            (*(s32*)(p+0x98))=direction;
            if((*(s32*)(p+0x288))==1) angle+=0x8000;
            if((*(s32*)(p+0x258))==0) {
                (*(f32*)(p+0x2a8))=lbl_8053DADC*JMath::sincosTable_.mTable[(u16)angle>>5].first;
                (*(f32*)(p+0x2ac))=lbl_8053DADC*JMath::sincosTable_.mTable[(u16)angle>>5].second;
                if((*(s32*)(p+0x4))>=8 && (*(s32*)(p+0x23c))==1) {
                    (*(f32*)(p+0x2a8))=lbl_8053DAE0*JMath::sincosTable_.mTable[(u16)angle>>5].first;
                    (*(f32*)(p+0x2ac))=lbl_8053DAE0*JMath::sincosTable_.mTable[(u16)angle>>5].second;
                }
            }
            (*(s32*)(p+0x29c))=0;
        }
        if((*(s32*)(p+0x250))==0 && direction>=0 && distance<lbl_8053DAE4) (*(s32*)(p+0x230))=5;
        if((*(s32*)(p+0x29c))==1 && (*(u8*)(p+0x2a4))==1) (*(s32*)(p+0x230))=4;
        break;
    state2:
        ++(*(s32*)(p+0x270));
        if((*(s32*)(p+0x270))>3) { (*(s32*)(p+0x288))=1;(*(s32*)(p+0x270))=3; }
        if((*(s32*)(p+0x244))==0) {
            (*(s32*)(p+0x244))=40;
            fn_801EEC98(p,(*(s32*)(p+0x198)),&angle,&direction,&distance,0,1,0);
            if(direction>=0) {
                (*(s32*)(p+0x98))=direction;
                if((*(s32*)(p+0x258))==0) {
                    (*(f32*)(p+0x2a8))=lbl_8053DAE8*JMath::sincosTable_.mTable[(u16)angle>>5].first;
                    (*(f32*)(p+0x2ac))=lbl_8053DAE8*JMath::sincosTable_.mTable[(u16)angle>>5].second;
                    if((*(s32*)(p+0x4))>=8 && (*(s32*)(p+0x23c))==1) {
                        (*(f32*)(p+0x2a8))=lbl_8053DAEC*JMath::sincosTable_.mTable[(u16)angle>>5].first;
                        (*(f32*)(p+0x2ac))=lbl_8053DAEC*JMath::sincosTable_.mTable[(u16)angle>>5].second;
                    }
                }
                (*(s32*)(p+0x29c))=0;
            } else { (*(JGeometry::TVec3f*)(p+0x2a8)).zero();(*(s32*)(p+0x29c))=1; }
        }
        if((*(s32*)(p+0x250))==0 && direction>=0 && distance<lbl_8053DAE4) (*(s32*)(p+0x230))=5;
        if((*(s32*)(p+0x29c))==1 && (*(u8*)(p+0x2a4))==1) (*(s32*)(p+0x230))=4;
        break;
    state3:
        (*(s32*)(p+0x29c))=0; (*(s32*)(p+0x244))=(s32)(slr4Random()*lbl_8053DAF0)+50;(*(s32*)(p+0x230))=4;
    state4:
        if(collision) {
            (*(JGeometry::TVec3f*)(p+0x3c)).zero();(*(JGeometry::TVec3f*)(p+0x2a8)).zero();(*(s32*)(p+0x240))=8;(*(s32*)(p+0x98))^=1;(*(s32*)(p+0x280))=lbl_804A0920[(*(s32*)(p+0x98))];(*(s32*)(p+0x29c))=0;
            break;
        }
        if((*(s32*)(p+0x244))==0) {
            (*(s32*)(p+0x29c))=1;(*(JGeometry::TVec3f*)(p+0x3c)).zero();(*(JGeometry::TVec3f*)(p+0x2a8)).zero();
            if((*(u8*)(p+0x2a4))==1) {
                (*(s32*)(p+0x244))=(s32)(slr4Random()*lbl_8053DAF0)+50;(*(s32*)(p+0x29c))=0;
                if(!((*(s32*)(p+0x98))&2)) {
                    if(slr4Random()<lbl_8053DAC8) (*(s32*)(p+0x98))=2;else (*(s32*)(p+0x98))=3;
                } else {
                    if(slr4Random()<lbl_8053DAC8) (*(s32*)(p+0x98))=0;else (*(s32*)(p+0x98))=1;
                }
            }
            break;
        }
        if((*(s32*)(p+0x258))==0) {
            switch((*(s32*)(p+0x98))) {
            case 0: (*(JGeometry::TVec3f*)(p+0x2a8)).set(lbl_8053DAF4,lbl_8053DAB8,lbl_8053DAB8);break;
            case 1: (*(JGeometry::TVec3f*)(p+0x2a8)).set(lbl_8053DAF8,lbl_8053DAB8,lbl_8053DAB8);break;
            case 2: (*(JGeometry::TVec3f*)(p+0x2a8)).set(lbl_8053DAB8,lbl_8053DAF4,lbl_8053DAB8);break;
            case 3: (*(JGeometry::TVec3f*)(p+0x2a8)).set(lbl_8053DAB8,lbl_8053DAF8,lbl_8053DAB8);break;
            }
        }
        if(direction>=0) {
            (*(JGeometry::TVec3f*)(p+0x3c)).zero();(*(JGeometry::TVec3f*)(p+0x2a8)).zero();
            pos.set((*(f32*)(p+0xc)),(*(f32*)(p+0x10)),(*(f32*)(p+0x14)));pos.y+=lbl_8053DAFC;
            fn_801F0E34(p,0x40088,0);
            fn_8013CC50((*(u32*)(p+0x4)),&pos,0x33b,0,1,0,0,1,lbl_8053DAC0);
            (*(s32*)(p+0x29c))=0;
            if((*(u32*)(p+0x90))==4 || (*(u32*)(p+0x90))==5 || (*(u32*)(p+0x90))==6) (*(s32*)(p+0x230))=2;
            else { (*(s32*)(p+0x248))=0;(*(s32*)(p+0x230))=0; }
        }
        break;
    state5:
        (*(JGeometry::TVec3f*)(p+0x3c)).zero();(*(JGeometry::TVec3f*)(p+0x2a8)).zero();(*(s32*)(p+0x26c))=0;(*(s32*)(p+0x29c))=2;(*(s32*)(p+0x230))=6;
    state6:
        (*(u16*)(p+0x236))=angle;
        if((*(s32*)(p+0x264))<3) break;
        pos.set((*(f32*)(p+0xc)),(*(f32*)(p+0x10)),(*(f32*)(p+0x14)));
        (*(f32*)(p+0xc))=pos.x;(*(f32*)(p+0x10))=pos.y;(*(f32*)(p+0x14))=pos.z;
        if((*(u8*)(p+0x2a4))==1) {
            ++(*(s32*)(p+0x26c));
            s32 duration=70;
            if((*(s32*)(p+0x90))>1) duration=42;
            (*(JGeometry::TVec3f*)(p+0x3c)).zero();(*(JGeometry::TVec3f*)(p+0x2a8)).zero();
            if((*(s32*)(p+0x26c))>duration) {
                (*(s32*)(p+0x250))=120;
                if((*(s32*)(p+0x4))>=8 && (*(s32*)(p+0x23c))==1) {
                    (*(f32*)(p+0x60))=lbl_8053DB00;(*(f32*)(p+0x64))=lbl_8053DB00;(*(f32*)(p+0x68))=lbl_8053DB04;(*(f32*)(p+0x6c))=lbl_8053DB04;
                }
                (*(s32*)(p+0x29c))=3;(*(s32*)(p+0x230))=7;
            }
        }
        break;
    state7:
        if((*(u8*)(p+0x2a4))==1) {
            (*(s32*)(p+0x29c))=0;
            if((*(u32*)(p+0x90))==4 || (*(u32*)(p+0x90))==5 || (*(u32*)(p+0x90))==6) (*(s32*)(p+0x230))=2;
            else { (*(s32*)(p+0x248))=0;(*(s32*)(p+0x230))=0; }
        }
        break;
    state8:
        (*(s32*)(p+0x248))=150;(*(s32*)(p+0x230))=9;
    state9:
        if((*(s32*)(p+0x248))!=0) {
            if(!((*(s32*)(p+0x248))&7)) {
                pos.set((*(f32*)(p+0xc)),(*(f32*)(p+0x10)),(*(f32*)(p+0x14)));
                pos.x+=lbl_8053DB08-lbl_8053DB0C*slr4Random();
                pos.y+=lbl_8053DB08-lbl_8053DB0C*slr4Random();
                Actor_CreateByID(fn_801F856C(),0x48424d42,(*(u32*)(p+0x4)),&pos,7,-1,-1);
            }
        } else v07__5ActorFv(p);
        break;
    } while(0);
    if((*(s32*)(p+0x240))>0)--(*(s32*)(p+0x240));
    if((*(s32*)(p+0x244))>0)--(*(s32*)(p+0x244));
    if((*(s32*)(p+0x248))>0)--(*(s32*)(p+0x248));
    if((*(s32*)(p+0x24c))>0)--(*(s32*)(p+0x24c));
    if((*(s32*)(p+0x250))>0)--(*(s32*)(p+0x250));
    if((*(s32*)(p+0x254))>0)--(*(s32*)(p+0x254));
    if((*(s32*)(p+0x258))>0)--(*(s32*)(p+0x258));
    if((*(s32*)(p+0x25c))>0)--(*(s32*)(p+0x25c));
    if((*(s32*)(p+0x260))>0)--(*(s32*)(p+0x260));
    if((*(s32*)(p+0x230))!=8 && (*(s32*)(p+0x230))!=9) fn_801746DC(p);
}

#pragma opt_common_subs off
extern "C" void fn_80174220(void* this_) {
    char* p = static_cast<char*>(this_);
    s32 idx = *(s32*)(p + 0x98);
    s32 n = idx;
    s32 id;
    s32 i;
    f32 ox, oy, oz;
    if ((s32)(u8)*(u32*)(p + 0x90) == 8 && *(s32*)(p + 0x23c) != 0) {
        n = idx + 4;
    }
    if (n < 4) {
        f32 x = *(f32*)(p + 0xc);
        ox = *(volatile f32*)(p + 0xc);
        oy = *(f32*)(p + 0x10);
        oz = *(f32*)(p + 0x14);
        *(f32*)(p + 0xc) = x + lbl_804A0AD8[idx * 2];
        *(f32*)(p + 0x10) = *(f32*)(p + 0x10) + lbl_804A0AD8[*(s32*)(p + 0x98) * 2 + 1];
    }
    {
        const f32* __restrict b = (const f32*)lbl_804A0B10 + n * 4;
        f32 a0 = ((const f32*)lbl_804A0B10)[n * 4];
        f32 a1, a2, a3;
        a3 = b[3];
        a2 = b[2];
        a1 = b[1];
        *(f32*)(p + 0x60) = a0;
        *(f32*)(p + 0x64) = a1;
        *(f32*)(p + 0x68) = a2;
        *(f32*)(p + 0x6c) = a3;
    }
    if (*(u16*)(p + 0x94) == 0 || *(u16*)(p + 0x94) == 2) {
        id = *(s32*)(p + 0x238);
        if (id >= 0) {
            void* obj = fn_801F666C(fn_801F856C(), id);
            if (obj != 0 && *(s32*)((char*)obj + 0xd8) == 0) {
                if (*(u16*)(p + 0x94) == 0) {
                    fn_801F2B7C(p, *(s32*)(p + 0x114), -1, 1);
                } else {
                    fn_801F2B7C(p, 4, -1, 3);
                }
            }
        }
        *(s32*)(p + 0x108) = 10000;
        fn_801EF510(p);
        for (i = 0; i < 4; i++) {
            s32 slot = fn_801F285C(p, 0, 0, 1, i);
            JGeometry::TVec2f v;
            if (slot < 0) continue;
            if (fn_80235448()) continue;
            {
                f32 px, py, t, x0, y0, x1, y1;
                py = *(f32*)(p + 0x10);
                y0 = *(f32*)(p + 0x64);
                y0 += py;
                y1 = *(f32*)(p + 0x6c);
                y1 += py;
                px = *(f32*)(p + 0xc);
                x0 = *(f32*)(p + 0x60);
                x0 += px;
                x1 = *(f32*)(p + 0x68);
                x1 += px;
                t = 0.5f;
                v.set(t * (x0 - x1) + x1, t * (y0 - y1) + y1);
            }
            if (!fn_80237948(slot, (f32*)&v)) continue;
            fn_80230FD0(slot, 0x20002);
            id = *(s32*)(p + 0x238);
            if (id < 0) continue;
            {
                void* obj = fn_801F666C(fn_801F856C(), id);
                if (obj == 0) continue;
                *(s16*)((char*)obj + 0x94) = (s16)(slot + 1);
            }
            fn_8013CC50(*(u32*)(p + 4), p + 0xc, 0x473, 0, 1, 0, 0, 1, lbl_8053DAC0);
            fn_8013CC50(*(u32*)(p + 4), p + 0xc, 0x474, 0, 1, 0, 0, 1, lbl_8053DAC0);
        }
    }
    *(f32*)(p + 0xc) = ox;
    *(f32*)(p + 0x10) = oy;
    *(f32*)(p + 0x14) = oz;
}
#pragma opt_common_subs reset
extern "C" void* fn_801F666C(void* a, s32 b);
extern "C" void fn_801F0E34(void* this_, u32 id, s32 b);
extern "C" void fn_80458FF0(void* a, u32 b, s32 c, s32 d);
extern void* lbl_8053AAF8;
extern void* lbl_8053AF80;
extern "C" s32 fn_801F285C(void* this_, s32 a, s32 b, s32 c, s32 d);
extern "C" void fn_801EF510(void* this_);
extern "C" u8 fn_80235448(void);
extern "C" u8 fn_80237948(s32 idx, f32* pos);
extern "C" void fn_80230FD0(s32 idx, s32 id);
extern "C" s32 fn_8013CC50(u32 id, void* pos, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f, f32 g);
extern f32 lbl_804A0AD8[];
extern Box4 lbl_804A0B10[];
extern const f32 lbl_8053DAC0;
extern const f32 lbl_8053DAC8;
extern "C" void fn_801744E4(void* this_) {
    char* p = (char*)this_;
    if (*(u32*)(p + 0x90) == 2 || *(u32*)(p + 0x90) == 3) {
        *(u32*)(p + 0x90) += 2;
        *(s32*)(p + 0x240) = 0;
        *(s32*)(p + 0x264) = 0;
        *(s32*)(p + 0x250) = 0x14;
        if (*(s32*)(p + 0x23c) == 0 && *(u8*)((char*)lbl_8053AAF8 + 0x7f) == 1) {
            fn_80458FF0(lbl_8053AF80, 0x1000021, 0, 0);
        }
        *(s32*)(p + 0x288) = 2;
        if (*(u8*)(p + 0x2a5) == 1) {
            fn_801F0E34(this_, 0x5001f, 0);
        }
        *(s32*)(p + 0x230) = 2;
    }
    s32 state = *(u32*)(p + 0x90) & 0xff;
    if (state != 7 && state != 8 && *(s32*)(p + 0x108) <= 0) {
        s32 idx = *(s32*)(p + 0x238);
        if (idx >= 0) {
            void* obj = fn_801F666C(fn_801F856C(), idx);
            if (obj != 0) {
                *(u8*)((char*)obj + 0x11c) = 0;
            }
        }
        *(s32*)(p + 0x238) = -1;
    }
}

extern void* lbl_804A0B90[];
extern "C" void __dt__5ActorFv(void* this_, s32 flag);
void __dl__FPv(void*);
extern "C" void fn_80138B7C(void* mgr);
extern "C" void __dl__FPv(void*);
extern "C" void* fn_80174600(void* this_, s16 flag) {
    char* p = (char*)this_;
    if (this_ != 0) {
        *(void**)this_ = lbl_804A0B90;
        s32 mode = *(u32*)(p + 0x90) & 0xff;
        if (mode != 7 && mode != 8) {
            if (mode != 6) {
                s32 st = *(s32*)((char*)lbl_8053AAF8 + 0x4c);
                if (st != 9 && st != 0xb && *(s32*)(p + 0x108) != 0) {
                    fn_80138B7C(lbl_8053AAF8);
                }
            }
            s32 id = *(s32*)(p + 0x238);
            if (id >= 0) {
                void* obj = fn_801F666C(fn_801F856C(), id);
                if (obj != 0) {
                    *(u8*)((char*)obj + 0x11c) = 0;
                }
            }
        }
        __dt__5ActorFv(this_, 0);
        if (flag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

f32 lbl_804A08C0[4][2] = {{-20.0f,-44.0f},{20.0f,-46.0f},{4.0f,-42.0f},{-8.0f,-10.0f}};
static s32 slr4Idle[20] = {0,1,0,2,3,4,3,5,6,7,6,8,9,10,9,11,6,9,3,0};
static s32 slr4Waits[4] = {8,12,8,12};
static s32 slr4Attack[40] = {12,13,14,13,12,15,16,15,17,18,19,18,17,20,21,20,22,23,24,23,22,25,26,25,27,28,29,28,27,30,31,30,15,5,5,3,15,5,5,3};
static s32 slr4Anim[24] = {33,32,33,34,35,36,38,37,38,39,40,41,43,42,43,44,45,46,49,47,48,49,50,51};
static s32 slr4Times[6] = {3,30,2,2,2,5};
struct Slr4AnimTables {
    f32 offsets[4][2];
    s32 idle[20];
    s32 waits[4];
    s32 attack[40];
    s32 anim[24];
    s32 times[6];
    s32 idleAt(s32 n) { return idle[n]; }
    s32 waitAt(s32 n) { return waits[n]; }
    s32 attackAt(s32 n) { return attack[n]; }
    s32 animAt(s32 n) { return anim[n]; }
    s32 timeAt(s32 n) { return times[n]; }
    f32* offsetAt(s32 n) { return offsets[n]; }
};
extern const f32 lbl_8053DB10;
extern "C" void fn_801746DC(void* this_) {
    char* tbl = (char*)lbl_804A08C0;
    char* p = (char*)this_;

    if (*(s32*)(p + 0x29c) != *(s32*)(p + 0x2a0)) {
        *(s32*)(p + 0x2a0) = *(s32*)(p + 0x29c);
        *(u8*)(p + 0x2a4) = 0;
        *(s32*)(p + 0x240) = 0;
        *(s32*)(p + 0x264) = 0;
        *(s32*)(p + 0x274) = 0;
        *(s32*)(p + 0x25c) = 0;
        if (*(s32*)(p + 0x29c) == 3) {
            *(s32*)(p + 0x264) = 5;
        }
    }

    switch (*(s32*)(p + 0x29c)) {
    case 0:
        if (*(s32*)(p + 0x240) == 0) {
            *(s32*)(p + 0x240) = slr4Waits[*(s32*)(p+0x264)];
            *(s32*)(p + 0x280) = slr4Idle[(*(s32*)(p+0x98)<<2) + *(s32*)(p+0x264)];
            *(s32*)(p + 0x264) += 1;
            *(volatile s32*)(p + 0x264) &= 3;
        }
        break;
    case 1:
        if (*(s32*)(p + 0x240) == 0) {
            *(s32*)(p + 0x240) = slr4Attack[*(s32*)(p+0x264)];
            *(s32*)(p + 0x280) = slr4Attack[(*(s32*)(p+0x98)<<3) + *(s32*)(p+0x264)];
            *(s32*)(p + 0x264) += 1;
            *(volatile s32*)(p + 0x264) &= 7;
            if (*(s32*)(p + 0x264) == 0) {
                *(u8*)(p + 0x2a4) = 1;
            }
        }
        break;
    case 2:
        if (*(s32*)(p + 0x240) == 0) {
            if (*(s32*)(p + 0x264) >= 6) {
                *(u8*)(p + 0x2a4) = 1;
                break;
            }
            *(s32*)(p + 0x240) = slr4Times[*(s32*)(p+0x264)];
            if (*(s32*)(p + 4) >= 8 && *(s32*)(p + 0x23c) == 1) {
                *(s32*)(p + 0x240) = (s32)(lbl_8053DAC8 * (f32)*(s32*)(p + 0x240));
            }
            if (*(s32*)(p + 0x264) == 1) {
                Vec3f pos;
                *(s32*)(p + 0x240) += 10;
                pos = *(Vec3f*)(p + 0xc);
                pos.x += lbl_804A08C0[*(s32*)(p+0x98)][0];
                pos.y += lbl_804A08C0[*(s32*)(p+0x98)][1];
                fn_8013CC50(*(u32*)(p + 4), &pos, 0xcb, 0, 3, 0, 0, 1, lbl_8053DAC0);
                fn_8013CC50(*(u32*)(p + 4), &pos, 0xcc, 0, 3, 0, 0, 1, lbl_8053DAC0);
            }
            *(s32*)(p + 0x280) = slr4Anim[*(s32*)(p+0x98)*6 + *(s32*)(p+0x264)];
            *(s32*)(p + 0x264) += 1;
            if (*(s32*)(p + 0x264) == 6) {
                *(s32*)(p + 0x240) += 0xf;
            }
            if (*(s32*)(p + 0x264) == 4) {
                fn_801F0E34(this_, 0x4008b, 0);
                switch (*(s32*)(p + 0x98)) {
                case 0:
                    *(f32*)(p + 0x3c) = lbl_8053DB10;
                    *(f32*)(p + 0x40) = 0.0f;
                    *(f32*)(p + 0x44) = 0.0f;
                    break;
                case 1:
                    *(f32*)(p + 0x3c) = -lbl_8053DB10;
                    *(f32*)(p + 0x40) = 0.0f;
                    *(f32*)(p + 0x44) = 0.0f;
                    break;
                case 2:
                    *(f32*)(p + 0x3c) = 0.0f;
                    *(f32*)(p + 0x40) = lbl_8053DB10;
                    *(f32*)(p + 0x44) = 0.0f;
                    break;
                case 3:
                    *(f32*)(p + 0x3c) = 0.0f;
                    *(f32*)(p + 0x40) = -lbl_8053DB10;
                    *(f32*)(p + 0x44) = 0.0f;
                    break;
                }
            }
        }
        if (*(s32*)(p + 0x25c) == 0) {
            *(s32*)(p + 0x25c) = 4;
            *(s32*)(p + 0x274) += 1;
            if (*(s32*)(p + 0x274) > 5) {
                *(s32*)(p + 0x274) = 0;
            }
        }
        break;
    case 3:
        if (*(s32*)(p + 0x240) == 0) {
            if (*(s32*)(p + 0x264) <= 0) {
                *(u8*)(p + 0x2a4) = 1;
                break;
            }
            *(s32*)(p + 0x240) = slr4Times[*(s32*)(p+0x264)];
            *(s32*)(p + 0x280) = slr4Anim[*(s32*)(p+0x98)*6 + *(s32*)(p+0x264)];
            *(s32*)(p + 0x264) -= 1;
        }
        if (*(s32*)(p + 0x25c) == 0) {
            *(s32*)(p + 0x25c) = (6 - *(s32*)(p + 0x264)) * 2;
            *(s32*)(p + 0x274) += 1;
            if (*(s32*)(p + 0x274) > 5) {
                *(s32*)(p + 0x274) = 0;
            }
        }
        break;
    case 9:
        break;
    }
}

extern "C" void fn_80174B44(void* this_) {
    char* p = (char*)this_;
    char* rng;
    s32 mode;
    s32 room;
    s32 a;
    void* obj;
    u32 bits;

    *(f32*)(p + 0x60) = lbl_8053DB20;
    *(f32*)(p + 0x64) = lbl_8053DB24;
    *(f32*)(p + 0x68) = lbl_8053DB28;
    *(f32*)(p + 0x6c) = lbl_8053DB2C;
    *(f32*)(p + 0x80) = lbl_8053DAD0;
    *(f32*)(p + 0x84) = lbl_8053DAD0;
    *(f32*)(p + 0x88) = lbl_8053DACC;
    *(f32*)(p + 0x8c) = lbl_8053DACC;
    *(s32*)(p + 0x264) = 0;
    *(s32*)(p + 0x268) = 0;
    *(s32*)(p + 0x26c) = 0;
    *(s32*)(p + 0x270) = 0;
    *(s32*)(p + 0x274) = 0;
    *(s32*)(p + 0x278) = 0;
    *(s32*)(p + 0x27c) = 0;
    *(s32*)(p + 0x240) = 0;
    *(s32*)(p + 0x244) = 0;
    *(s32*)(p + 0x248) = 0;
    *(s32*)(p + 0x24c) = 0;
    *(s32*)(p + 0x250) = 0;
    *(s32*)(p + 0x254) = 0;
    *(s32*)(p + 0x258) = 0;
    *(s32*)(p + 0x25c) = 0;
    *(s32*)(p + 0x260) = 0;
    *(s32*)(p + 0x2c0) = -1;
    *(s32*)(p + 0x2c4) = -1;
    *(s32*)(p + 0x2c8) = -1;
    *(s32*)(p + 0x2cc) = -1;
    *(s32*)(p + 0x278) = 3;
    *(s32*)(p + 0x298) = ((*(u32*)(p + 0x90) >> 8) & 0xf) * 0x14;
    *(s32*)(p + 0x294) = ((*(u32*)(p + 0x90) >> 12) & 0xf) * 0x14;
    *(u8*)(p + 0x2a5) = 0;
    *(s32*)(p + 0x29c) = 0;
    *(s32*)(p + 0x2a0) = 0;
    *(s32*)(p + 0x23c) = (*(u32*)(p + 0x90) >> 16) & 0xff;
    if (*(s32*)(p + 0x23c) != 0) {
        *(u8*)(p + 0x196) = 1;
        *(s32*)(p + 0x190) = 0;
    }
    *(u8*)(p + 0x2a4) = 0;
    rng = (char*)lbl_8053AAF8;
    *(u32*)(rng + 0xb4) = *(u32*)(rng + 0xb4) * 0x19660d + 0x3c6ef35f;
    bits = (*(u32*)(rng + 0xb4) >> 9) | 0x3f800000;
    *(s32*)(p + 0x98) = (s32)(lbl_8053DB30 * (*(f32*)&bits - lbl_8053DAC0)) & 3;
    *(f32*)(p + 0x2b4) = *(f32*)(p + 0xc);
    *(f32*)(p + 0x2b8) = *(f32*)(p + 0x10);
    *(f32*)(p + 0x2bc) = *(f32*)(p + 0x14);
    *(s32*)(p + 0x284) = 10000;
    *(s32*)(p + 0x238) = -1;
    mode = *(u32*)(p + 0x90) & 0xff;
    if (mode != 7 && mode != 8 && mode != 6) {
        mode = *(u32*)(p + 0x90) & 0xff;
        if (mode != 2 && mode != 3 && *(s32*)(p + 0x23c) == 0 && *(u8*)((char*)lbl_8053AAF8 + 0x7f) == 1) {
            fn_80458FF0(lbl_8053AF80, 0x1000021, 0, 0);
        }
        *(s32*)(p + 0x108) = lbl_804A0AF8[*(u32*)(p + 0x90) & 0xff] << 1;
        if (fn_802DE814() == 1) {
            *(s32*)(p + 0x108) = lbl_804A0AF8[*(u32*)(p + 0x90) & 0xff];
        }
        s32 originalRoom = *(s32*)(p + 0x4);
        room = originalRoom;
        a = 7;
        if (originalRoom >= 8) {
            a = 8;
            room = 0;
        }
        *(s32*)(p + 0x238) = Actor_CreateByID(fn_801F856C(), 0x534c5234, room, p + 0xc, a, -1, -1);
        mode = *(s32*)(p + 0x238);
        if (mode >= 0) {
            obj = fn_801F666C(fn_801F856C(), mode);
            if (obj != 0) {
                *(s32*)((char*)obj + 0x114) = *(s32*)(p + 0x114);
                *(s32*)((char*)obj + 0x238) = *(s32*)(p + 0x198);
                *(s32*)((char*)obj + 0x23c) = *(s32*)(p + 0x23c);
            }
        }
    }
    mode = *(u32*)(p + 0x90) & 0xff;
    if (mode != 7 && mode != 8 && mode != 6 && *(s32*)(p + 0x4) >= 8) {
        *(s32*)(p + 0x108) = 0x32;
        if (*(s32*)(p + 0x23c) == 1) {
            *(f32*)(p + 0x60) = lbl_8053DB00;
            *(f32*)(p + 0x64) = lbl_8053DB00;
            *(f32*)(p + 0x68) = lbl_8053DB04;
            *(f32*)(p + 0x6c) = lbl_8053DB04;
        } else {
            *(s32*)(p + 0x108) = 0x19;
            *(f32*)(p + 0x60) = lbl_8053DB34;
            *(f32*)(p + 0x64) = lbl_8053DB34;
            *(f32*)(p + 0x68) = lbl_8053DB38;
            *(f32*)(p + 0x6c) = lbl_8053DB38;
            *(f32*)(p + 0x80) = lbl_8053DB34;
            *(f32*)(p + 0x84) = lbl_8053DB34;
            *(f32*)(p + 0x88) = lbl_8053DB38;
            *(f32*)(p + 0x8c) = lbl_8053DB38;
        }
    }
    *(s32*)(p + 0x284) = *(s32*)(p + 0x108);
    mode = *(u32*)(p + 0x90) & 0xff;
    if (mode != 6 && *(s32*)(p + 0x4) >= 8 && *(s32*)(p + 0x23c) == 1) {
        *(s32*)(p + 0x108) = 10000;
    }
    *(s32*)(p + 0x280) = 0;
    *(s32*)(p + 0x288) = 0;
    *(s32*)(p + 0x28c) = *(u32*)(p + 0x90) >> 24;
    if (*(s32*)(p + 0x28c) == 0) {
        *(s32*)(p + 0x28c) = -1;
    }
    *(u32*)(p + 0x90) = *(u32*)(p + 0x90) & 0xff;
    *(u8*)(p + 0x234) = lbl_80539F78[*(u32*)(p + 0x90) >> 1];
    *(f32*)(p + 0x2b0) = lbl_8053DAB8;
    *(f32*)(p + 0x2ac) = lbl_8053DAB8;
    *(f32*)(p + 0x2a8) = lbl_8053DAB8;
    *(s32*)(p + 0x290) = 0;
    *(s32*)(p + 0x244) = 10;
    *(s16*)(p + 0x236) = 0;
    *(s32*)(p + 0xb0) = 0xa042209;
    *(s32*)(p + 0xb8) = 1;
    if (*(u32*)(p + 0x90) == 2 || *(u32*)(p + 0x90) == 3) {
        *(s32*)(p + 0x98) = 3;
    }
    *(s32*)(p + 0x230) = 0;
    fn_801746DC(p);
    *(s32*)(p + 0xc0) = 3;
    *(s32*)(p + 0xbc) = 3;
    if (*(u32*)(p + 0x90) == 4 || *(u32*)(p + 0x90) == 5 || *(u32*)(p + 0x90) == 6) {
        *(s32*)(p + 0x230) = 2;
    }
    mode = *(u32*)(p + 0x90) & 0xff;
    if (mode == 7 || mode == 8) {
        *(u8*)(p + 0x1a8) = 0;
        *(s32*)(p + 0xb0) = 0xa040004;
        *(s32*)(p + 0x108) = 10000;
        *(s32*)(p + 0xb8) = 0;
        *(f32*)(p + 0x60) = lbl_8053DB3C;
        *(f32*)(p + 0x64) = lbl_8053DB3C;
        *(f32*)(p + 0x68) = lbl_8053DB40;
        *(f32*)(p + 0x6c) = lbl_8053DB40;
        *(f32*)(p + 0x80) = lbl_8053DAC0;
        *(f32*)(p + 0x84) = lbl_8053DAC0;
        *(f32*)(p + 0x88) = lbl_8053DB44;
        *(f32*)(p + 0x8c) = lbl_8053DB44;
        *(s32*)(p + 0x230) = 10;
    }
}

#pragma opt_common_subs off
extern "C" void fn_80175024(void* this_) {
    char* p = (char*)this_;
    if ((s32)(*(u32*)(p + 0x90) & 0xff) != 6) {
        void* obj;
        register s32 idx = *(s32*)(p + 0x238);
        if (idx >= 0) {
            obj = slr4FindActor(idx);
            if (obj == 0) {
                s32 a = 7;
                int room;
                int currentRoom = *(s32*)(p + 0x4);
                room = currentRoom;
                if (currentRoom >= 8) {
                    a = 8;
                    room = 0;
                }
                *(s32*)(p + 0x238) = Actor_CreateByID(fn_801F856C(), 0x534c5234, room, p + 0xc, a, -1, -1);
                idx = *(s32*)(p + 0x238);
                if (idx >= 0) {
                    obj = slr4FindActor(idx);
                    if (obj != 0) {
                        *(s32*)((char*)obj + 0x114) = *(s32*)(p + 0x114);
                        *(s32*)((char*)obj + 0x238) = *(s32*)(p + 0x198);
                        *(s32*)((char*)obj + 0x23c) = *(s32*)(p + 0x23c);
                    }
                }
            } else {
                switch (*(s32*)(p + 0x29c)) {
                case 2:
                    if (*(s32*)(p + 0x264) >= 4) {
                        if (*(f32*)(p + 0x3c) < lbl_8053DB48 && *(f32*)(p + 0x40) < lbl_8053DB48) {
                            *(s16*)((char*)obj + 0x94) = 0;
                            if (*(s32*)(p + 0x4) >= 8 && *(s32*)(p + 0x23c) == 1) {
                                register const Box4* table = lbl_804A0A58;
                                s32 index = *(s32*)(p + 0x98);
                                f32 a, b, c, d;
                                a = table[index].a;
                                const Box4* src = &table[index];
                                d = src->d;
                                c = src->c;
                                b = src->b;
                                *(f32*)(p + 0x60) = a;
                                *(f32*)(p + 0x64) = b;
                                *(f32*)(p + 0x68) = c;
                                *(f32*)(p + 0x6c) = d;
                            }
                            fn_801F2B7C(p, -100, -1, 1);
                        } else {
                            fn_801F2B7C(p, 4, -1, 3);
                            *(s16*)((char*)obj + 0x94) = 2;
                        }
                    } else {
                        *(s16*)((char*)obj + 0x94) = 1;
                    }
                case 0:
                case 1:
                case 3:
                    if (*(s32*)(p + 0x29c) != 2) {
                        *(s16*)((char*)obj + 0x94) = 0;
                    }
                    if (*(s32*)(p + 0x29c) == 3) {
                        *(s16*)((char*)obj + 0x94) = 1;
                    }
                    {
                        JGeometry::TVec3f v;
                        if (*(u32*)((char*)obj + 0x90) == 7) {
                            v.x = *(f32*)(p + 0xc);
                            v.y = *(f32*)(p + 0x10);
                            v.z = *(f32*)(p + 0x14);
                        } else {
                            s32 room = *(s32*)((char*)obj + 0x4);
                            char* base = (char*)fn_802D6A9C();
                            Box4* src;
                            if (room < 8) {
                                src = (Box4*)(base + 0xcc);
                            } else {
                                src = (Box4*)(base + 0xdc);
                            }
                            Box4 box = *src;
                            v.x = *(f32*)(p + 0xc);
                            v.y = *(f32*)(p + 0x10);
                            v.z = *(f32*)(p + 0x14);
                            v.x += box.a;
                            v.y += box.b;
                        }
                        *(JGeometry::TVec3f*)((char*)obj + 0xc) = v;
                    }
                    *(u32*)((char*)obj + 0x98) = *(u32*)(p + 0x98);
                    break;
                }
                if (*(u32*)((char*)obj + 0x90) == 8) {
                    *(s32*)((char*)obj + 0x280) = *(s32*)(p + 0x280);
                }
            }
        }
    }
}
#pragma opt_common_subs reset
extern "C" void fn_801752D8(void* this_) {
    char* q;
    char* e;
    s16 rot;
    s32 n;
    s32 i;
    s32 cnt;
    char* p = (char*)this_;
    if (*(s32*)(p + 0x4) >= 8 && *(s32*)(p + 0x23c) == 1 && *(s32*)(lbl_80529DEC + 0x118) == 6) {
        i = 0;
        cnt = 0;
        q = p;
        for (; i < 4; i++, q += 4) {
            s32 id = *(s32*)(q + 0x2c0);
            if (id < 0) {
                cnt++;
            } else {
                void* a = fn_801F666C(fn_801F856C(), id);
                if (a == 0) {
                    *(s32*)(q + 0x2c0) = -1;
                    cnt++;
                } else {
                    JGeometry::TVec3f pos = *(JGeometry::TVec3f*)(p + 0xc);
                    ((JGeometry::TVec3f*)((char*)a + 0x280))->x = pos.x;
                    ((JGeometry::TVec3f*)((char*)a + 0x280))->y = pos.y;
                    ((JGeometry::TVec3f*)((char*)a + 0x280))->z = pos.z;
                    *(s32*)(p + 0x260) = 0x384;
                }
            }
        }
        if (*(s32*)(p + 0x260) == 0 && cnt == 4) {
            s32 room = *(s32*)(p + 0x4);
            if (room == fn_8023DE58(0)) {
                n = 0;
                rot = 0;
                e = p;
                for (i = 0; i < 4; i++, e += 4) {
                    *(s32*)(e + 0x2c0) = Actor_CreateByID(fn_801F856C(), 0x4b455448, *(u32*)(p + 0x4), p + 0xc, 4, -1, -1);
                    s32 id = *(s32*)(e + 0x2c0);
                    if (id >= 0) {
                        void* a = fn_801F666C(fn_801F856C(), id);
                        if (a != 0) {
                            n++;
                            *(s16*)((char*)a + 0x268) = rot;
                            *(f32*)((char*)a + 0x270) = lbl_8053DB4C;
                            if (n >= 4) {
                                *(s32*)(p + 0x260) = 0x384;
                            }
                        }
                    }
                    rot += 0x4000;
                }
            }
        }
    }
}

void __sinit_SLR4_80172894_cpp(void) {
}

