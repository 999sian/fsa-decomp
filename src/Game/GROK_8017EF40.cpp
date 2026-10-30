#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "Game/SinitPoolChain.h"
#include "math.h"
#include "std/math.h"

extern "C" u8* fn_802D6A9C(void);
extern "C" void fn_801F0E34(void* this_, s32 p1, s32 p2);
extern "C" void fn_802D7440(u8* mgr, s32 p);
extern "C" void fn_8022ADCC(void);
extern "C" void fn_801EE434(void* p);
extern "C" void __dt__5ActorFv(void* this_, s32 p);
extern "C" void __dl__FPv(void* p);
extern "C" char __vt__4GROK[];

struct ActorVt_grok {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void setShadow(s32 type, f32 x, f32 y);
};

extern "C" void fn_8017EF40(ActorVt_grok* this_) {
    fn_801F0E34(this_, 0x40038, 0);
    this_->setShadow(2, 0.0f, 16.0f);
}

#include "Game/ItemBase.h"
extern "C" void fn_801F06F0(void*,const char*,s32,DrawRec*,s32,f32,f32);
extern "C" void fn_803075AC(s32,s32,void*,s32,s32,s32,s32,s32,s32,s32);
extern "C" void fn_80307AC8(s32,s32,void*,s32,s32,s32,s32);
extern "C" void* fn_804032E8(int,const char*);
extern "C" void fn_801EFD34(void*,void*,DrawRec*,s32,f32,f32,f32);
extern "C" u32 lbl_8053AB70;
extern "C" s32 lbl_80539F98;
extern const char lbl_80466E50[],lbl_80466E60[];
struct GrokDrawTable {u8 pad[0x80];const char* normal[30];f32 normalY[30];const char* special[28];f32 specialY[28];};
extern GrokDrawTable lbl_804A13E0;
static inline const char* grokTexture(const char* const* table,s32 index) {return table[index];}
static inline f32 grokYOffset(const f32* table,s32 index) {return table[index];}
extern const f32 lbl_8053DDD8;
static inline void grokRotation(f32 m[3][4],f32 scaleX,f32 scaleY,f32 scaleZ) {
    f32 cz,cy,cx,sz,sy,sx;
    sx=sin(lbl_8053DDD8);sy=sin(lbl_8053DDD8);sz=sin(lbl_8053DDD8);
    cx=cos(lbl_8053DDD8);cy=cos(lbl_8053DDD8);cz=cos(lbl_8053DDD8);
    f32 cc=cx*cz;
    f32 ss=sx*sy;
    f32 cs=cx*sz;
    f32 sxsz=sx*sz;
    f32 sxcz=sx*cz;
    f32 cycz=cy*cz;
    f32 cysz=cy*sz;
    m[0][0]=scaleX*cycz;
    m[1][0]=scaleX*cysz;
    m[2][0]=scaleX*-sy;
    m[0][1]=scaleY*__fmsubs(ss,cz,cs);
    m[1][1]=scaleY*__fmadds(ss,sz,cc);
    m[2][1]=scaleY*(sx*cy);
    m[0][2]=scaleZ*__fmadds(cc,sy,sxsz);
    m[1][2]=scaleZ*__fmsubs(cs,sy,sxcz);
    m[2][2]=scaleZ*(cx*cy);
}

#pragma optimization_level 4
#pragma peephole off
#pragma opt_propagation off
#pragma opt_strength_reduction off
extern "C" void fn_8017EF98(u8* const p) {
    GrokDrawTable* t=&lbl_804A13E0;
    DrawRec rec;
    f32 m[3][4];
    JGeometry::TVec3<f32> pos=*(JGeometry::TVec3<f32>*)(p+0xc);
    m[0][3]=0.0f;m[1][3]=0.0f;m[2][3]=0.0f;
    if(*(s32*)(p+0x230)!=0 && *(s32*)(p+0x230)!=1 && *(s32*)(p+0x230)!=23) {
    if(*(u32*)(p+0x90)==1) {return;} else {
    
    f32 offset;
    if(*(u32*)(p+0x90)==2 || *(u32*)(p+0x90)==3) {
        if(*(u16*)(p+0x94)==0) return;
        offset=-16.0f;
        grokRotation(m,1.0f,1.0f,1.0f);
        if(*(u32*)(p+0x90)==3) {offset=16.0f;grokRotation(m,-1.0f,1.0f,1.0f);}
        rec.w18=m;
        void* texture=fn_804032E8(0x47524f43,lbl_80466E50);
        rec.b1d=-2;
        rec.b1c=1;
        fn_801EFD34(p,texture,&rec,-1,offset,-6.0f,0.0f);
        return;
    }
    s32 room=*(s32*)(p+4);
    u8* mgr=fn_802D6A9C();
    if((mgr+0x10000)[0x31df+room]!=0) {
        u32 type=*(u32*)(p+0x90);
        if(type==8) {
            if(*(s32*)(p+0x250)!=0 && (*(s32*)(p+0x24c)&2)) return;
            fn_803075AC(*(s32*)(p+0x198),*(s32*)(p+4),p+0xc,*(s32*)(p+0x26c)+0x192,0,2,-1,1,0,0);
            return;
        }
        if(type==4 || type==5) {
            if((s32)lbl_8053AB70==(s32)type) fn_80307AC8(*(s32*)(p+0x198),*(s32*)(p+4),p+0xc,*(s32*)(p+0x26c)+0x29,0,0,-1);
            return;
        }
        if(type==10) {
            if(*(s32*)(p+0x250)!=0 && (*(s32*)(p+0x24c)&2)) return;
            fn_803075AC(*(s32*)(p+0x198),*(s32*)(p+4),p+0xc,*(s32*)(p+0x26c)+0x192,0,2,-1,1,0,0);
            return;
        }
        if(type==9) {
            if(*(s32*)(p+0x250)!=0 && (*(s32*)(p+0x24c)&2)) return;
            fn_803075AC(*(s32*)(p+0x198),*(s32*)(p+4),p+0xc,*(s32*)(p+0x26c)+0x192,0,2,-1,1,0,0);
            ((JGeometry::TVec3<f32>*)(p+0xc))->set(pos);
            return;
        }
    }
    if(*(u32*)(p+0x90)==6) {
        rec.b1c=1;rec.b1d=2;
        f32 v=*(f32*)(p+0x30c);
        m[0][0]=v;m[0][1]=0.0f;m[0][2]=0.0f;
        m[1][0]=0.0f;m[1][1]=v;m[1][2]=0.0f;
        m[2][0]=0.0f;m[2][1]=0.0f;m[2][2]=v;
        ((u8*)&rec.w10)[3]=(s32)*(f32*)(p+0x310);
        rec.w18=m;
        fn_801F06F0(p,lbl_80466E60,0xb1,&rec,-1,1.0f,1.0f);
        return;
    }
    s32 frame=*(s32*)(p+0x26c);
    s32 index=frame;
    if(lbl_80539F98<=0) index=frame+14;
    void* texture;
    if(*(s32*)(p+0x230)!=9 && *(s32*)(p+0x230)!=15) {
        if(*(s32*)(p+0x230)==12) {
            if(frame==12) index=28;
            else if(frame==13) index=29;
        }
        int byteIndex=index*4;
        const char* const* names=t->normal;
        texture=fn_804032E8(0x47524f43,*(const char**)((u32)names+byteIndex));
        const f32* offsets=t->normalY;
        offset=*(const f32*)((u32)offsets+byteIndex);
    } else {
        int byteIndex=index*4;
        const char* const* names=t->special;
        texture=fn_804032E8(0x47524f43,*(const char**)((u32)names+byteIndex));
        const f32* offsets=t->specialY;
        offset=*(const f32*)((u32)offsets+byteIndex);
    }
    grokRotation(m,1.0f,1.0f,1.0f);
    if(*(s32*)(p+0x98)==0) grokRotation(m,-1.0f,1.0f,1.0f);
    rec.w18=m;
    ((u8*)&rec.w10)[0]=0;((u8*)&rec.w10)[1]=0;((u8*)&rec.w10)[2]=0;((u8*)&rec.w10)[3]=100;
    *(f32*)(p+0x14)=0.0f;
    rec.b1d=-1;rec.b1c=1;
    fn_801EFD34(p,texture,&rec,-1,0.0f,-8.0f+offset,0.0f);
    ((JGeometry::TVec3<f32>*)(p+0xc))->set(pos);
    ((u8*)&rec.w10)[0]=255;((u8*)&rec.w10)[1]=255;((u8*)&rec.w10)[2]=255;((u8*)&rec.w10)[3]=255;
    grokRotation(m,1.0f,1.0f,1.0f);
    frame=*(s32*)(p+0x26c);index=frame;
    if(lbl_80539F98<=0) index=frame+14;
    if(*(s32*)(p+0x230)!=9 && *(s32*)(p+0x230)!=15) {
        if(*(s32*)(p+0x230)==12) {
            if(frame==12) index=28;
            else if(frame==13) index=29;
        }
        int byteIndex=index*4;
        const char* const* names=t->normal;
        texture=fn_804032E8(0x47524f43,*(const char**)((u32)names+byteIndex));const f32* offsets=t->normalY;
        offset=*(const f32*)((u32)offsets+byteIndex);
    } else { int byteIndex=index*4;
        const char* const* names=t->special;
        texture=fn_804032E8(0x47524f43,*(const char**)((u32)names+byteIndex));const f32* offsets=t->specialY;
        offset=*(const f32*)((u32)offsets+byteIndex); }
    rec.b1d=1;
    if(*(s32*)(p+0x230)!=15) rec.b1f=0;
    else rec.b1d=0;
    if(*(s32*)(p+0x98)==0) grokRotation(m,-1.0f,1.0f,1.0f);
    rec.w18=m;
    if(lbl_80539F98<=0) rec.w30=17;
    fn_801EFD34(p,texture,&rec,-1,0.0f,-8.0f+offset,0.0f);
}}
}
#pragma opt_strength_reduction reset
#pragma opt_propagation reset
#pragma peephole reset
#pragma optimization_level 4
extern "C" void fn_801546F4(void* a, void* b);
extern "C" void fn_801826E4(f32* dst, f32 a, f32 b);
extern "C" u8* fn_801826A4(s32 idx);
extern "C" void fn_8017ECC0(void);
extern "C" void fn_8017FB10(u8* this_) {
    fn_801546F4(this_ + 0x60, 0);
    fn_801826E4((f32*)(this_ + 0x1c), *(f32*)(this_ + 0xc), *(f32*)(this_ + 0x10));
    fn_801826A4(*(s32*)(this_ + 4));
    *(s32*)(this_ + 0x108) = 0x2710;
    if (*(u32*)(this_ + 0x90) == 0) {
        fn_8017ECC0();
    }
    *(s32*)(this_ + 0x230) = 8;
}

extern "C" u8 fn_8023F264(s32 i);
extern "C" s32 fn_8023DE58(s32 i);
extern "C" f32* fn_8023E724(s32 i);
extern "C" void fn_801F71A4(void* p, f32 a, f32 b, f32 c);
extern "C" void fn_80230498(s32 i, void* p, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" s32 lbl_804A1440[];
#pragma optimization_level 3
extern const f32 lbl_8053DEAC;
extern "C" void fn_80181BC8(void* this_, u32 param_2, s32 param_3) {
    u8* self = (u8*)this_;
    s32 iVar12;
    u8* vec = (u8*)this_;
    u32 idx = param_2;
    u8* cnt = (u8*)this_;
    s32 off = 0;
    s32 i;

    for (i = 0; i < 4; i++, cnt += 4, vec += 0xc) {
        if (fn_8023F264(i)) {
            iVar12 = *(s32*)(self + 4);
            if (iVar12 == fn_8023DE58(i)) {
                switch (param_3) {
                case 0: {
                    f32* p = fn_8023E724(i);
                    idx = (p[0] < *(f32*)(self + 0xc)) ? 0 : 1;
                    *(s32*)(cnt + 0x2f4) = 0;
                    f32* a = fn_8023E724(i);
                    *(f32*)(vec + 0x294) = a[0];
                    *(f32*)(vec + 0x298) = a[1];
                    *(f32*)(vec + 0x29c) = a[2];
                    f32* b = fn_8023E724(i);
                    *(f32*)(vec + 0x2c4) = b[0];
                    *(f32*)(vec + 0x2c8) = b[1];
                    *(f32*)(vec + 0x2cc) = b[2];
                    *(f32*)(vec + 0x29c) = 0.0f;
                    *(f32*)(vec + 0x2cc) = 0.0f;
                    self[i + 0x304] = 0;
                    break;
                }
                case 1: {
                    iVar12 = i + 0x304;
                    if (self[iVar12] == 1) {
                        idx = param_2 + 4;
                    }
                    s32 n = *(s32*)(cnt + 0x2f4);
                    if (n < 4) {
                        off = 0;
                    } else if (n < 8) {
                        off = 1;
                    } else if (n < 0xb) {
                        off = 2;
                    } else if (n < 0xe) {
                        off = 3;
                    } else if (n < 0x11) {
                        off = 4;
                    } else if (n < 0x14) {
                        off = 5;
                    } else {
                        off = 0;
                        *(s32*)(cnt + 0x2f4) = 0x14;
                        idx = 3;
                    }
                    fn_801F71A4(vec + 0x298, *(f32*)(vec + 0x2c8), 0.3f, 1.0f);
                    if (self[iVar12] == 0) {
                        f32* p = fn_8023E724(i);
                        f32 dx = p[0] - *(f32*)(self + 0xc);
                        f32 dist = std::sqrtf(dx * dx);
                        if (dist < 128.0f) {
                            f32* q = fn_8023E724(i);
                            f32 dy = q[1] - *(f32*)(self + 0x28c);
                            f32 dist2 = std::sqrtf(dy * dy);
                            if (dist2 < 80.0f) {
                                f32* r = fn_8023E724(i);
                                *(f32*)(vec + 0x2c8) = r[1] + 30.0f;
                                self[iVar12] = 1;
                            }
                        }
                    } else {
                        *(s32*)(cnt + 0x2f4) += 1;
                    }
                    break;
                }
                }
                if (param_3 == 0 || self[i + 0x304] == 1) {
                    fn_80230498(i, vec + 0x294, off + lbl_804A1440[idx], 0xff, -0x80, -0x80, 1);
                }
            }
        }
    }
}
#pragma optimization_level 4
extern "C" void* fn_80181FFC(void* this_, s16 param_2) {
    if (this_ != 0) {
        *(void**)this_ = __vt__4GROK;
        if (*(u32*)((u8*)this_ + 0x90) == 0) {
            u8* mgr = fn_802D6A9C();
            fn_802D7440(mgr, 1);
            fn_8022ADCC();
        }
        for (s32 i = 0; i < 2; i++) {
            void* p = *(void**)((u8*)this_ + 0x318 + i * 4);
            if (p != 0) {
                fn_801EE434(p);
            }
        }
        __dt__5ActorFv(this_, 0);
        if (param_2 > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void fn_80458F9C(void* p, s32 n);
extern "C" s32 fn_80138A30(u8* p);
extern "C" void fn_80304C10(s32 i, void* p, u32 a, s32 b, s32 c);
extern "C" void fn_802F9714(void* a, void* b, s32 c, s32 d, s32 e, s32 f);
extern "C" u8* lbl_8053AAF8;
extern "C" u8* lbl_8053AB10;
extern "C" void* lbl_8053AF80;
extern "C" u32 lbl_8053AB70;
extern "C" s32 lbl_80539F98;
extern "C" s32 lbl_80539F9C;
extern "C" s32 lbl_80539FA0;
extern "C" s32 lbl_80539FA4;
extern "C" u8 lbl_8053AB74;
extern "C" u8 lbl_8053AB75;
extern "C" char lbl_80466E74[];
extern const f32 lbl_8053DDE0;
extern const f32 lbl_8053DDE8;
struct GrokResources {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void* getResource(u32 type, void* name);
};
#pragma opt_propagation off
extern "C" void fn_801820B4(void* this_) {
    u8* self = (u8*)this_;
    u8* vec = (u8*)this_;
    u8* cnt = (u8*)this_;
    s32 idx = 0;
    s32 i;
    u32 mode;
    s32 zero;

    *(u32*)(self + 0x90) &= 0xf;
    *(u16*)(self + 0x94) = 0;
    *(f32*)(self + 0x80) = -1.0f;
    *(f32*)(self + 0x84) = -1.0f;
    *(f32*)(self + 0x88) = 1.0f;
    *(f32*)(self + 0x8c) = 1.0f;
    *(u32*)(self + 0x24c) = 0;
    *(u32*)(self + 0x250) = 0;
    *(u32*)(self + 0x254) = 0;
    *(u32*)(self + 0x258) = 0;
    *(u32*)(self + 0x25c) = 0;
    *(u32*)(self + 0x260) = 0;
    *(u32*)(self + 0x264) = 0;
    *(u32*)(self + 0x268) = 0;
    *(u32*)(self + 0x234) = 0;
    *(u32*)(self + 0x238) = 0;
    *(u32*)(self + 0x23c) = 0;
    *(u32*)(self + 0x240) = 0;
    *(u32*)(self + 0x244) = 0;
    *(u32*)(self + 0x248) = 0;
    *(u8*)(self + 0x196) = 1;
    *(u16*)(self + 0x278) = 0;
    *(s32*)(self + 0x274) = -1;

    for (i = 0; i < 4; i++, vec += 0xc, cnt += 4, idx += 1) {
        *(f32*)(vec + 0x294) = *(f32*)(self + 0xc);
        *(f32*)(vec + 0x298) = *(f32*)(self + 0x10);
        *(f32*)(vec + 0x29c) = *(f32*)(self + 0x14);
        *(f32*)(vec + 0x2c4) = *(f32*)(self + 0xc);
        *(f32*)(vec + 0x2c8) = *(f32*)(self + 0x10);
        *(f32*)(vec + 0x2cc) = *(f32*)(self + 0x14);
        *(u32*)(cnt + 0x2f4) = 0;
        self[idx + 0x304] = 0;
    }

    zero = 0;
    *(u32*)(self + 0x98) = zero;
    *(u32*)(self + 0x26c) = 0;
    *(f32*)(self + 0x314) = 0.0f;
    *(u32*)(self + 0x318) = 0;
    *(u32*)(self + 0x31c) = 0;
    *(s32*)(self + 0x270) = -1;
    *(f32*)(self + 0x288) = *(f32*)(self + 0xc);
    *(f32*)(self + 0x28c) = *(f32*)(self + 0x10);
    *(f32*)(self + 0x290) = *(f32*)(self + 0x14);
    *(f32*)(self + 0x30c) = 1.0f;
    *(f32*)(self + 0x310) = 255.0f;
    *(f32*)(self + 0x284) = 0.0f;
    *(f32*)(self + 0x280) = 0.0f;
    *(f32*)(self + 0x27c) = 0.0f;
    *(f32*)(self + 0x308) = 0.0f;

    mode = *(u32*)(self + 0x90);
    switch (mode) {
    case 0:
        *(f32*)(self + 0x60) = -16.0f;
        *(f32*)(self + 0x64) = -16.0f;
        *(f32*)(self + 0x68) = 16.0f;
        *(f32*)(self + 0x6c) = 16.0f;
        *(f32*)(self + 0x70) = -16.0f;
        *(f32*)(self + 0x74) = -16.0f;
        *(f32*)(self + 0x78) = 16.0f;
        *(f32*)(self + 0x7c) = 16.0f;
        fn_802D7440(fn_802D6A9C(), 0);
        fn_80458F9C(lbl_8053AF80, 0x3c);
        lbl_8053AB70 = 0;
        lbl_80539F98 = 8;
        lbl_80539F9C = 0xb4;
        if (fn_80138A30(lbl_8053AAF8) > 1) {
            lbl_80539F9C = 0x6e;
            lbl_8053AB74 = 0;
            lbl_8053AB75 = 0;
            *(s32*)(self + 0x268) = -1;
            for (i = 0; i < 4; i++) {
                fn_80304C10(i, lbl_80466E74, 0x6017000, 1, 0);
            }
            {
                void* obj = *(void**)(lbl_8053AAF8 + 0xa4);
                void* res = ((GrokResources*)obj)->getResource(0x53434820, lbl_80466E74);
                fn_802F9714(*(void**)(lbl_8053AB10 + 0x20), res, 0, 0, 0x7000, 0);
            }
            *(u32*)(self + 0xb0) = 0x9040004;
            *(s32*)(self + 0x98) = 1;
            *(f32*)(self + 0x14) = 500.0f;
            *(f32*)(self + 0x308) = 500.0f;
            *(s32*)(self + 0x230) = 0;
        } else {
        case 1:
            u32 value = 0x9040004;
            *(u32*)(self + 0xb0) = value;
            value = 0x10;
            *(u8*)(self + 0x1a8) = zero;
            *(f32*)(self + 0x60) = -16.0f;
            *(f32*)(self + 0x64) = -16.0f;
            *(f32*)(self + 0x68) = 16.0f;
            *(f32*)(self + 0x6c) = 16.0f;
            *(f32*)(self + 0x70) = -16.0f;
            *(f32*)(self + 0x74) = -16.0f;
            *(f32*)(self + 0x78) = 16.0f;
            *(f32*)(self + 0x7c) = 16.0f;
            *(s32*)(self + 0x230) = value;
        }
        break;
    case 4:
        *(s32*)(self + 0x98) = 1;
    case 5:
        *(u32*)(self + 0xb0) = 0x5000000;
        *(u8*)(self + 0x1a8) = 0;
        *(f32*)(self + 0x60) = -32.0f;
        *(f32*)(self + 0x64) = -32.0f;
        *(f32*)(self + 0x68) = 32.0f;
        *(f32*)(self + 0x6c) = 32.0f;
        *(f32*)(self + 0x70) = -48.0f;
        *(f32*)(self + 0x74) = -48.0f;
        *(f32*)(self + 0x78) = 48.0f;
        *(f32*)(self + 0x7c) = 48.0f;
        *(s32*)(self + 0x230) = 0x11;
        break;
    case 6: {
        u32 bits;
        f32 r;
        *(u8*)(self + 0x1a8) = 0;
        u8* mgr = lbl_8053AAF8;
        *(u32*)(mgr + 0xb4) = *(u32*)(mgr + 0xb4) * 0x19660d + 0x3c6ef35f;
        bits = (*(u32*)(mgr + 0xb4) >> 9) | 0x3f800000;
        r = *(f32*)&bits - 1.0f;
        *(f32*)(self + 0x30c) = 0.1f + 0.2f * r;
        *(s32*)(self + 0x230) = 0x15;
        break;
    }
    case 7:
        *(f32*)(self + 0x308) = 500.0f;
        *(u8*)(self + 0x1a8) = 0;
        *(u32*)(self + 0xb0) = 0x4000000;
        *(s32*)(self + 0x230) = 0x17;
        break;
    case 8: {
        u8* mgr = lbl_8053AAF8;
        u32 bits;
        f32 r;
        *(u32*)(mgr + 0xb4) = *(u32*)(mgr + 0xb4) * 0x19660d + 0x3c6ef35f;
        bits = (*(u32*)(mgr + 0xb4) >> 9) | 0x3f800000;
        r = *(f32*)&bits - 1.0f;
        *(s32*)(self + 0x26c) = (s32)(2.99f * r) + 0x13;
        *(u8*)(self + 0x1a8) = 0;
        *(s32*)(self + 0x230) = 0x19;
        break;
    }
    case 9:
        *(u8*)(self + 0x1a8) = 0;
        *(s32*)(self + 0x234) = 0x14;
        *(s32*)(self + 0x24c) = 1;
        if (*(s32*)(self + 0x98) == 0) {
            *(s32*)(self + 0x26c) = 0x16;
        } else {
            *(s32*)(self + 0x26c) = 0x17;
        }
        *(f32*)(self + 0x10) = *(f32*)(self + 0x10) - 22.0f;
        *(s32*)(self + 0x230) = 0x19;
        break;
    case 10: {
        u8* mgr = lbl_8053AAF8;
        u32 bits;
        f32 r;
        *(u32*)(mgr + 0xb4) = *(u32*)(mgr + 0xb4) * 0x19660d + 0x3c6ef35f;
        bits = (*(u32*)(mgr + 0xb4) >> 9) | 0x3f800000;
        r = *(f32*)&bits - 1.0f;
        *(s32*)(self + 0x26c) = (s32)(2.99f * r) + 0x10;
        *(u8*)(self + 0x1a8) = 0;
        *(s32*)(self + 0x230) = 0x19;
        break;
    }
    default:
        if (mode == 2) {
            lbl_80539FA0 = *(s32*)(self + 0x198);
        } else if (mode == 3) {
            lbl_80539FA4 = *(s32*)(self + 0x198);
        }
        *(u8*)(self + 0x1a8) = 0;
        *(u32*)(self + 0xb0) = 0x4000000;
        *(f32*)(self + 0x60) = -16.0f;
        *(f32*)(self + 0x64) = -16.0f;
        *(f32*)(self + 0x68) = 16.0f;
        *(f32*)(self + 0x6c) = 16.0f;
        *(f32*)(self + 0x70) = -16.0f;
        *(f32*)(self + 0x74) = -16.0f;
        *(f32*)(self + 0x78) = 16.0f;
        *(f32*)(self + 0x7c) = 16.0f;
        *(s32*)(self + 0x230) = 0x16;
        break;
    }
}
#pragma opt_propagation reset
extern "C" void fn_80182640(void* thisObj, f32 x, f32 y, f32 z) {
	*(f32*)((char*)thisObj + 0x0) = x;
	*(f32*)((char*)thisObj + 0x4) = y;
	*(f32*)((char*)thisObj + 0x8) = z;
}

extern "C" void fn_80182650(void* thisObj, f32 x, f32 y, f32 z) {
	*(f32*)((char*)thisObj + 0x0) = x;
	*(f32*)((char*)thisObj + 0x4) = y;
	*(f32*)((char*)thisObj + 0x8) = z;
}

extern "C" void fn_80182660(u8* dst, const f32* src) { JGeometry::setTVec3f(src, (f32*)(dst + 0xc)); }

extern "C" void fn_80182674(f32* dst, const f32* src) { dst[0] = src[0]; dst[1] = src[1]; dst[2] = src[2]; }

extern "C" void fn_80182690(f32* dst, const f32* src) { dst[0] = src[0]; dst[1] = src[1]; }

extern "C" u8* fn_801826A4(s32 idx) {
    u8* mgr = fn_802D6A9C();
    if (idx < 8) {
        return mgr + 0xcc;
    }
    return mgr + 0xdc;
}

extern "C" void fn_801826E4(f32* dst, f32 a, f32 b) { dst[0] = a; dst[1] = b; }

