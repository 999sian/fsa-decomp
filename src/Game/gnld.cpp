// TU 0x80329468-0x8032ab80 (actor GNLD).
// Function bodies from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
#include "Game/esd/types.h"
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"

// ---- Gold_dtor_8032A8E0.cpp ----
extern "C" void fn_801EE434(void* handle);
extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" void dtor_80084580(void* this_);
extern void* lbl_804AB660[];

// GOLD cluster, part 5/6. Destructor - culls 3 handles (this+0x24c/0x250/
// 0x254) via the confirmed fn_801EE434, then the shared base dtor
// __dt__5ActorFv plus a conditional second-base dtor dtor_80084580.
extern "C" void* Gold_dtor(void* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804AB660;
        fn_801EE434(*(void**)((char*)this_ + 0x24c));
        fn_801EE434(*(void**)((char*)this_ + 0x250));
        fn_801EE434(*(void**)((char*)this_ + 0x254));
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

struct GnldVBase {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10(u32, u32);
    virtual u8 v11();
};

extern "C" void detach__5ActorFv(void* this_);
extern const f32 lbl_80541D10;
extern const f32 lbl_80541D14;
extern const f32 lbl_80541D18;
extern const f32 lbl_80541D7C;

extern "C" void fn_8032A7B8(char* this_) {
    *(s32*)(this_ + 0x24c) = 0;
    *(s32*)(this_ + 0x250) = 0;
    *(s32*)(this_ + 0x254) = 0;
    *(s32*)(this_ + 0x238) = *(u32*)(this_ + 0x90) & 0xffff;
    *(s32*)(this_ + 0x234) = 0;
    *(f32*)(this_ + 0x244) = lbl_80541D10;
    *(f32*)(this_ + 0x248) = lbl_80541D18;
    *(s32*)(this_ + 0x240) = 0xb;
    *(s32*)(this_ + 0x23c) = (*(u32*)(this_ + 0x90) >> 20) & 0xf;
    switch ((*(u32*)(this_ + 0x90) >> 16) & 0xf) {
    default:
    case 0:
    case 5:
    case 6:
        *(s32*)(this_ + 0x230) = 0;
        break;
    case 1:
        *(s32*)(this_ + 0x230) = 1;
        break;
    case 2: {
        *(s32*)(this_ + 0x238) = 0;
        f32 b = lbl_80541D14;
        f32 a = lbl_80541D7C;
        *(f32*)(this_ + 0x60) = a;
        *(f32*)(this_ + 0x64) = a;
        *(f32*)(this_ + 0x68) = b;
        *(f32*)(this_ + 0x6c) = b;
        *(s32*)(this_ + 0x230) = 3;
        break;
    }
    case 3:
        *(s32*)(this_ + 0x230) = 4;
        break;
    case 4:
    case 7:
        *(s32*)(this_ + 0x230) = 5;
        break;
    }
    s32 st = *(s32*)(this_ + 0x230);
    if ((st == 1 || st == 3 || st == 4) && ((GnldVBase*)this_)->v11()) {
        detach__5ActorFv(this_);
    }
}

struct GnldDrawKey {
    s32 a, b;
    GnldDrawKey() { a = -1; b = -1; }
};

struct GnldDrawParam {
    u8 map[16];      // 0x00
    GnldDrawKey key; // 0x10
    void* mtx;       // 0x18
    u8 palette;      // 0x1c
    u8 color;        // 0x1d
    u8 f1e, f1f, f20, f21, f22, f23, f24, f25, f26;
    s32 blend;       // 0x28
    u8 f2c, f2d, f2e;
    s32 g;           // 0x30
    s32 h;           // 0x34
    s32 i;           // 0x38

    GnldDrawParam() {
        for (u8 n = 0; n < 16; n++) {
            map[n] = n;
        }
        key.a = -1;
        key.b = 0;
        mtx = 0;
        palette = 0;
        color = 0;
        f1e = 0;
        f1f = 1;
        f20 = 1;
        f21 = 0;
        f22 = 0;
        f23 = 0;
        f24 = 0;
        f25 = 0;
        f26 = 1;
        blend = 3;
        f2c = 1;
        f2d = 0;
        f2e = 0;
        g = -1;
        h = 0;
        i = 2;
    }
};

class GnldResMgr {
public:
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void* vf18(u32 type, const char* name);
};

extern "C" void PSMTXIdentity(f32 m[3][4]);
extern "C" void fn_802F86CC(void*, void*, void*, s32, f32, f32, GnldDrawParam*);
extern u8* lbl_8053AAF8;
extern u8* lbl_8053AB10;
extern const char lbl_80471930[];

extern "C" void fn_80329468(char* this_) {
    if (*(s32*)(this_ + 0x230) == 3) {
        GnldDrawParam param; f32 m[3][4]; f32 z; f32 sc;
        PSMTXIdentity(m);
        sc = *(f32*)(this_ + 0x248);
        z = lbl_80541D10;
        m[0][0] = sc;
        m[0][1] = z;
        m[0][2] = z;
        m[1][0] = z;
        m[1][1] = sc;
        m[1][2] = z;
        m[2][0] = z;
        m[2][1] = z;
        m[2][2] = sc;
        param.mtx = m;
        f32 x = lbl_80541D14 + *(f32*)(this_ + 0xc);
        f32 y = lbl_80541D14 + *(f32*)(this_ + 0x10);
        f32 z0 = *(f32*)(this_ + 0x14);
        f32 pos[3];
        pos[0] = x;
        pos[1] = y;
        pos[2] = z0;
        if (*(s32*)(this_ + 4) < 8) {
            void* res = (*(GnldResMgr**)(lbl_8053AAF8 + 0xa4))->vf18(0x534f4220, lbl_80471930);
            fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), pos, res, 0x2a, lbl_80541D18, lbl_80541D18, &param);
        }
    }
}

struct GnldRandom {
    u32 seed;
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - lbl_80541D18;
    }
};


extern "C" void* fn_801F856C(void);
extern "C" char* fn_801F666C(void*,s32);
extern "C" s32 fn_801F8544(void*,u32,s32,void*,u32);
extern "C" void fn_8032A4FC(s32,s32,u8);
extern "C" void* fn_802D6A9C();
extern "C" void fn_80458880(void*,s32,s32);
extern "C" void* fn_8013CC50(s32,void*,s32,s32,s32,s32,s32,s32,f32);
extern "C" void fn_801F71A4(f32*,f32,f32,f32);
extern "C" s32 fn_801F3D94(void*,s32);
extern "C" u8 fn_801F305C(void*);
extern "C" void fn_801EEC98(void*,s32,s16*,s32*,f32*,s32*,s32,s32);
extern void* lbl_8053AF80;
extern const s32 lbl_804AB630[];
extern const f32 lbl_80541D1C;
extern const f32 lbl_80541D20;
extern const f32 lbl_80541D24;
extern const f32 lbl_80541D28;
extern const f32 lbl_80541D2C;
extern const f32 lbl_80541D30;
extern const f32 lbl_80541D34;
extern const f32 lbl_80541D38;
extern const f32 lbl_80541D3C;
extern const f32 lbl_80541D40;
extern const f32 lbl_80541D44;
extern const f32 lbl_80541D48;
extern const f32 lbl_80541D4C;
extern const f32 lbl_80541D50;
extern const f32 lbl_80541D54;

extern "C" u32 fn_801F6874(void*);
extern "C" void fn_80329640(u8* this_) {
 u8* p=this_;
 s32 n,id,heading,mode;
 u32 kind;
 u8* obj;
 JGeometry::TVec3<f32> motion;
 JGeometry::TVec3<f32> fx1,probe,fx4;
 JGeometry::TVec3<f32> v0,vPlane,vCircle,vSide,v5;
 u16 angle;
 switch((*(s32*)(p+0x230))){
 case 0:{
   heading=fn_801F6874((void*)(*(s32*)(p+0x98)));
   motion.setAll(lbl_80541D10);
   s32 remaining;
   for(n=0;n<100 && (remaining=*(s32*)(p+0x238))>0;n++){
     s32 count=(*(s32*)(p+0x240));
     while(count>0){
       if(remaining>=lbl_804AB630[count])break;
       --count;
     }
     (*(s32*)(p+0x240))=count;
     kind=(u32)((f32)((*(s32*)(p+0x240))+1)*((GnldRandom*)(lbl_8053AAF8+0xb4))->get_ufloat_1());
     if((*(s32*)(p+0x238))<20){
       if((*(s32*)(p+0x238))>5 && kind==2)kind=1;
       else kind=0;
     }
     s32 cost=lbl_804AB630[kind];
     if(*(s32*)(p+0x238)<cost)continue;
     *(s32*)(p+0x238)-=cost;
     id=fn_801F8544(fn_801F856C(),0x52555059,(*(s32*)(p+4)),p+0xc,kind);
     if(id<0)continue;
     obj=(u8*)fn_801F666C(fn_801F856C(),id);
     if(!obj)continue;
     mode=((*(u32*)(p+0x90))>>16)&15;
     if(mode==0){
       s32 room=(*(s32*)(p+4));
       u8* manager=(u8*)fn_802D6A9C();
       u8 plane=*(u8*)(manager+(room+0x131DF));
       if(plane==0){
         v0.set((lbl_80541D1C*(f32)(*(s32*)(p+0x23c))+lbl_80541D18)*(lbl_80541D18-lbl_80541D20*((GnldRandom*)(lbl_8053AAF8+0xb4))->get_ufloat_1()),
                (lbl_80541D1C*(f32)(*(s32*)(p+0x23c))+lbl_80541D18)*(lbl_80541D18-lbl_80541D20*((GnldRandom*)(lbl_8053AAF8+0xb4))->get_ufloat_1()),
                (lbl_80541D1C*(f32)(*(s32*)(p+0x23c))+lbl_80541D18)*(lbl_80541D20*((GnldRandom*)(lbl_8053AAF8+0xb4))->get_ufloat_1()+lbl_80541D20));
         *(JGeometry::TVec3<f32>*)(obj+0x3c)=v0;
       }else{
         vPlane.set((lbl_80541D1C*(f32)(*(s32*)(p+0x23c))+lbl_80541D18)*(lbl_80541D18-lbl_80541D20*((GnldRandom*)(lbl_8053AAF8+0xb4))->get_ufloat_1()),
                (lbl_80541D1C*(f32)(*(s32*)(p+0x23c))+lbl_80541D18)*(lbl_80541D20-lbl_80541D20*((GnldRandom*)(lbl_8053AAF8+0xb4))->get_ufloat_1()),lbl_80541D10);
         *(JGeometry::TVec3<f32>*)(obj+0x3c)=vPlane;
       }
     }else if(mode==6){
       s32 room=(*(s32*)(p+4));
       u8 plane=((u8*)fn_802D6A9C())[0x131DF+room];
       if(plane==0){
         s32 a=(s32)(lbl_80541D24*((GnldRandom*)(lbl_8053AAF8+0xb4))->get_ufloat_1());
         f32 radius=lbl_80541D2C*((GnldRandom*)(lbl_8053AAF8+0xb4))->get_ufloat_1()+lbl_80541D28;
         vCircle.set((lbl_80541D1C*(f32)(*(s32*)(p+0x23c))+lbl_80541D18)*(radius*JMath::sincosTable_.sinShort((u16)a)),
                     (lbl_80541D1C*(f32)(*(s32*)(p+0x23c))+lbl_80541D18)*(radius*JMath::sincosTable_.cosShort((u16)a)),
                     (lbl_80541D1C*(f32)(*(s32*)(p+0x23c))+lbl_80541D18)*(lbl_80541D20*((GnldRandom*)(lbl_8053AAF8+0xb4))->get_ufloat_1()+lbl_80541D20));
         *(JGeometry::TVec3<f32>*)(obj+0x3c)=vCircle;
       }else{
         s32 sign=(s32)(lbl_80541D20*((GnldRandom*)(lbl_8053AAF8+0xb4))->get_ufloat_1());
         sign=(sign==1)-(sign==0);
         vSide.set((lbl_80541D1C*(f32)(*(s32*)(p+0x23c))+lbl_80541D18)*((f32)sign*(lbl_80541D28*((GnldRandom*)(lbl_8053AAF8+0xb4))->get_ufloat_1()+lbl_80541D30)),(lbl_80541D1C*(f32)(*(s32*)(p+0x23c))+lbl_80541D18)*(lbl_80541D20-lbl_80541D20*((GnldRandom*)(lbl_8053AAF8+0xb4))->get_ufloat_1()),lbl_80541D10);
         *(JGeometry::TVec3<f32>*)(obj+0x3c)=vSide;
       }
     }else{
       s32 a=(s32)((f32)(u16)heading+(lbl_80541D34-lbl_80541D38*((GnldRandom*)(lbl_8053AAF8+0xb4))->get_ufloat_1()));
       motion.x=(lbl_80541D1C*(f32)(*(s32*)(p+0x23c))+lbl_80541D18)*(lbl_80541D18+((GnldRandom*)(lbl_8053AAF8+0xb4))->get_ufloat_1());
       motion.x*=JMath::sincosTable_.sinShort((u16)a);
       motion.y=(lbl_80541D1C*(f32)(*(s32*)(p+0x23c))+lbl_80541D18)*(lbl_80541D18+((GnldRandom*)(lbl_8053AAF8+0xb4))->get_ufloat_1());
       motion.y*=JMath::sincosTable_.cosShort((u16)a);
       motion.z=(lbl_80541D40*(f32)(*(s32*)(p+0x23c))+lbl_80541D18)*(lbl_80541D3C*((GnldRandom*)(lbl_8053AAF8+0xb4))->get_ufloat_1())+lbl_80541D3C;
       *(JGeometry::TVec3<f32>*)(obj+0x3c)=motion;
     }
   }
   detach__5ActorFv(p);break;}
 case 1:
   if(((GnldVBase*)p)->v11() && (*(s32*)(p+0x234))==0){
     fx1=(*(JGeometry::TVec3<f32>*)(p+0xc));fx1.x+=lbl_80541D14;fx1.y+=lbl_80541D44;(*(s32*)(p+0x234))=200;
     fn_80458880(lbl_8053AF80,0x1d,-1);
     *(void**)(p+588)=fn_8013CC50((*(s32*)(p+4)),&fx1,981,1,1,0,0,1,lbl_80541D18);
*(void**)(p+592)=fn_8013CC50((*(s32*)(p+4)),&fx1,982,1,1,0,0,1,lbl_80541D18);
*(void**)(p+596)=fn_8013CC50((*(s32*)(p+4)),&fx1,983,1,1,0,0,1,lbl_80541D18);
   }
   if((*(s32*)(p+0x234))>0 && ((*(s32*)(p+0x234))&7)==0)fn_8032A4FC((*(s32*)(p+0x198)),0,0);
   if((*(s32*)(p+0x234))!=0){(*(s32*)(p+0x234))--;if((*(s32*)(p+0x234))<=0){(*(f32*)(p+0x244))=lbl_80541D48;(*(s32*)(p+0x230))=2;}}
   break;
 case 2:
   fn_801F71A4((f32*)(p+0x244),lbl_80541D10,lbl_80541D1C,lbl_80541D4C);
   if((*(f32*)(p+0x244))<lbl_80541D18){
     {u8* effect=*(u8**)(p+588);if(effect){*(u32*)(effect+0xf4)|=1;*(s32*)(effect+0x24)=1;}}
{u8* effect=*(u8**)(p+592);if(effect){*(u32*)(effect+0xf4)|=1;*(s32*)(effect+0x24)=1;}}
{u8* effect=*(u8**)(p+596);if(effect){*(u32*)(effect+0xf4)|=1;*(s32*)(effect+0x24)=1;}}
     detach__5ActorFv(p);
   }break;
 case 3:
   (*(s32*)(p+0x108))=1000;
   if((*(s32*)(p+0x234))!=0){
     (*(s32*)(p+0x234))--;
     if((*(s32*)(p+0x234))<=0){
       u8* effect=*(u8**)(p+0x24c);
       if(effect){*(u32*)(effect+0xf4)|=1;*(s32*)(effect+0x24)=1;}
       detach__5ActorFv(p);break;
     }
   }
   fn_801F71A4((f32*)(p+0x248),lbl_80541D18,lbl_80541D50,lbl_80541D54);
   if(fn_801F3D94(p,1)!=0){
     (*(JGeometry::TVec3<f32>*)(p+0x3c)).setAll(lbl_80541D10);
     if((*(s32*)(p+0xe4))!=1 || (*(s32*)(p+0xe8))==0)break;
   }
   if(!((*(s32*)(p+0xe4))==1 && (*(s32*)(p+0xe8))>0) && !fn_801F305C(p))break;
   probe=(*(JGeometry::TVec3<f32>*)(p+0xc));probe.x+=lbl_80541D14;probe.y+=lbl_80541D44;angle=0;
   (*(s32*)(p+0xd8))=20;(*(s32*)(p+0xdc))=20;(*(JGeometry::TVec3<f32>*)(p+0x3c)).setAll(lbl_80541D10);(*(f32*)(p+0x248))=lbl_80541D20;
   if((*(s32*)(p+0x238))==0){
     (*(s32*)(p+0x238))++;(*(s32*)(p+0x234))=500;
     ((GnldVBase*)p)->v10(0xff,1);
   }
   probe=(*(JGeometry::TVec3<f32>*)(p+0xc));(*(f32*)(p+0xc))+=lbl_80541D14;(*(f32*)(p+0x10))+=lbl_80541D14;
   fn_801EEC98(p,(*(s32*)(p+0x198)),(s16*)&angle,0,0,0,0,0);
   (*(JGeometry::TVec3<f32>*)(p+0xc))=probe;
   fn_8032A4FC((*(s32*)(p+0x198)),(u16)(angle+0x8000),1);
   break;
 case 4:
   if((*(s32*)(p+0x234))==0){
     fx4=(*(JGeometry::TVec3<f32>*)(p+0xc));fx4.x+=lbl_80541D14;fx4.y+=lbl_80541D44;(*(s32*)(p+0x234))=200;
     fn_80458880(lbl_8053AF80,0x1d,-1);
     *(void**)(p+588)=fn_8013CC50((*(s32*)(p+4)),&fx4,981,1,1,0,0,1,lbl_80541D18);
*(void**)(p+592)=fn_8013CC50((*(s32*)(p+4)),&fx4,982,1,1,0,0,1,lbl_80541D18);
*(void**)(p+596)=fn_8013CC50((*(s32*)(p+4)),&fx4,983,1,1,0,0,1,lbl_80541D18);
   }
   if((*(s32*)(p+0x234))>0 && ((*(s32*)(p+0x234))&7)==0)fn_8032A4FC((*(s32*)(p+0x198)),0,0);
   if((*(s32*)(p+0x234))!=0){(*(s32*)(p+0x234))--;if((*(s32*)(p+0x234))<=0){(*(f32*)(p+0x244))=lbl_80541D48;(*(s32*)(p+0x230))=2;}}
   break;
 case 5:
   (*(s32*)(p+0x238))%=12;
   id=fn_801F8544(fn_801F856C(),0x52555059,(*(s32*)(p+4)),p+0xc,(*(s32*)(p+0x238)));
   if(id>=0){
     obj=(u8*)fn_801F666C(fn_801F856C(),id);
     if(obj){
       v5.set(lbl_80541D18-lbl_80541D20*((GnldRandom*)(lbl_8053AAF8+0xb4))->get_ufloat_1(),lbl_80541D18-lbl_80541D20*((GnldRandom*)(lbl_8053AAF8+0xb4))->get_ufloat_1(),lbl_80541D20*((GnldRandom*)(lbl_8053AAF8+0xb4))->get_ufloat_1()+lbl_80541D20);
       *(JGeometry::TVec3<f32>*)(obj+0x3c)=v5;
     }
   }
   detach__5ActorFv(p);break;
 }
}

extern "C" void* fn_801F856C(void);
extern "C" char* fn_801F666C(void* mgr, s32 id);
extern "C" s32 fn_801F8544(void* mgr, u32 type, s32 room, void* pos, u32 param);
extern const f32 lbl_80541D20;
extern const f32 lbl_80541D3C;
extern const f32 lbl_80541D44;
extern const f64 lbl_80541D68;
extern const f32 lbl_80541D70;
extern const f32 lbl_80541D74;
extern const f32 lbl_80541D78;

#define GNLD_RND (((GnldRandom*)(lbl_8053AAF8 + 0xb4))->get_ufloat_1())

extern "C" void fn_8032A4FC(s32 id, s32 ang, u8 mode) {
    char* a; char* b; f32 r;
    a = fn_801F666C(fn_801F856C(), id);
    if (a != 0) {
        JGeometry::TVec3<f32> pos = *(JGeometry::TVec3<f32>*)(a + 0xc);
        r = GNLD_RND;
        pos.z = lbl_80541D10;
        pos.x += lbl_80541D14;
        pos.y += lbl_80541D44;
        id = fn_801F8544(fn_801F856C(), 0x52555059, *(s32*)(a + 0x4), &pos, (u32)(lbl_80541D68 * r));
        if (id >= 0) {
            b = fn_801F666C(fn_801F856C(), id);
            if (b != 0) {
                if (mode) {
                    ang += (int)(lbl_80541D70 - lbl_80541D74 * GNLD_RND);
                    JGeometry::TVec3<f32> v(lbl_80541D20 * JMASSin(ang), lbl_80541D20 * JMASCos(ang), lbl_80541D3C * GNLD_RND + lbl_80541D3C);
                    *(JGeometry::TVec3<f32>*)(b + 0x3c) = v;
                } else {
                    JGeometry::TVec3<f32> v(lbl_80541D20 - lbl_80541D78 * GNLD_RND, lbl_80541D20 - lbl_80541D78 * GNLD_RND, lbl_80541D3C * GNLD_RND + lbl_80541D3C);
                    *(JGeometry::TVec3<f32>*)(b + 0x3c) = v;
                }
            }
        }
    }
}

// Shared JAudio pool __sinit (docs/game/sinit_pools.md). Drop the ESD
// macros/typedefs that clash with the JSystem headers first.
#undef ALIGN_NEXT
#undef ALIGN_PREV
#undef ARRAY_SIZE
#undef ASM
#undef ATTRIBUTE_ALIGN
#undef IS_ALIGNED
#undef IS_NOT_ALIGNED
#undef MACROS_H
#undef MAX
#undef MIN
#undef NULL
#define NULL 0
#define unknown jsys_unknown
#include "JSystem/JAudio/JASFakeMatchFSA.h"
