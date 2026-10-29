#include "types.h"
#include "std/math.h"
#include "JSystem/JGeometry/Vec.h"

struct YasiDrawKey {
    s32 a, b;
    YasiDrawKey() { a = -1; b = -1; }
};
struct YasiDrawParam {
    u8 map[16];
    YasiDrawKey key;
    s32 c;
    u8 palette;
    u8 color;
    u8 f1e, f1f, f20, f21, f22, f23, f24, f25, f26;
    s32 blend;
    u8 f2c, f2d, f2e;
    s32 g;
    s32 h;
    s32 i;

    YasiDrawParam() {
        for (u8 n = 0; n < 16; n++) {
            map[n] = n;
        }
        key.a = -1;
        key.b = 0;
        c = 0;
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
struct Rgba802D {
    Rgba802D() {}
    Rgba802D(Rgba802D* p) { *this = *p; }
    Rgba802D(u8 r_, u8 g_, u8 b_, u8 a_) { r = r_; g = g_; b = b_; a = a_; }
    u8 r, g, b, a;
};
struct YasiMgr {
    u8 flag(u32 i) { return mFlags[i]; }
    u8 pad[0x131df];
    u8 mFlags[1];
};
extern const char lbl_8046E100[];
extern "C" const f32 lbl_80540ECC;
extern "C" const f32 lbl_80540EE0;
extern "C" u32 lbl_8053AB10;
extern "C" int fn_8013CC50(s32, void*, f32, s32, s32, s32, s32, s32, s32);
extern "C" void fn_8013CB44(s32, void*, s32, s32, s32);
extern "C" void* fn_8013C824(void);
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void*, void*);
extern "C" f32* fn_8023E7B0(s32);
extern "C" s32 fn_8023DE58(s32);
extern "C" u8 fn_8023BCD4(s32);
extern "C" s32 fn_8023CB24(s32 holder);
extern "C" s32 fn_8023CA88(s32 holder);
extern "C" s32 fn_801F02BC(void* p, const char* name, s32 id, void* param, s32 a, s32 b, s32 c, f32 f1, f32 f2);
extern "C" s32 fn_802D6A9C(void);
extern "C" void fn_80158B5C(void* a, u32 b, void* c, Rgba802D d, f32 f);
extern "C" void* fn_801F856C(void);
extern "C" s32 Actor_CreateByID(void*, s32, s32, void*, s32, s32, s32);
struct Vec3f_802D { float x, y, z; };
struct VObj_802D {
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
};

extern "C" void fn_802D14DC(VObj_802D* p) {
    p->m7();
}

extern "C" void fn_801F132C(void*, int, int, void*);
extern "C" void fn_802D1508(char* this_, int a, int b) {
    fn_801F132C(this_, a, b, this_ + 0x248);
}

extern "C" s32 fn_801CD664(s32);
extern "C" unsigned int fn_8022461C(void*,unsigned int);
extern "C" u8 fn_802DE9A0();
extern "C" u8 fn_802DEB58();
extern "C" void fn_801F0E34(void*,s32,s32);
extern "C" s32 fn_80226AE0(void*,s32);
extern "C" void fn_802F9908(void*,s32,s32);
extern "C" void fn_80226CA8(s32,s32,void*);
struct YasiBreakOffsets {
    f32 smallX[5], smallY[5];
    f32 largeX[13], largeY[13];
};
extern "C" const f32 lbl_8046E070[5] = {0.0f,-16.0f,0.0f,16.0f,0.0f};
static const f32 yasiSmallY[5] = {-16.0f,0.0f,0.0f,0.0f,16.0f};
static const f32 yasiLargeX[13] = {0.0f,-16.0f,0.0f,16.0f,-32.0f,-16.0f,0.0f,16.0f,32.0f,-16.0f,0.0f,16.0f,0.0f};
static const f32 yasiLargeY[13] = {-32.0f,-16.0f,-16.0f,-16.0f,0.0f,0.0f,0.0f,0.0f,0.0f,16.0f,16.0f,16.0f,32.0f};
#define S32(p,o) (*(s32*)((char*)(p)+(o)))
#define F32(p,o) (*(f32*)((char*)(p)+(o)))
#pragma opt_lifetimes on
extern "C" void fn_802D152C(char* p) {
    const f32* x1;
    const f32* y1;
    int room;
    s32 roomB;
    s32 roomC;
    s32 tile1;
    s32 i1;
    s32 color;
    JGeometry::TVec3<f32> tilePos;
    JGeometry::TVec3<f32> pos(*(JGeometry::TVec3<f32>*)(p+0xc));
    if(S32(p,0x234)==0) {
        pos.z=0.0f;
        room=S32(p,4);
        if(room>=8) Actor_CreateByID(fn_801F856C(),0x4b4d5249,room,&pos,0,-1,-1);
        if(S32(p,0x240)<=1) {
            s32 random=fn_801CD664(100);
            if((S32(fn_802D6A9C(),4)==5 && S32(fn_802D6A9C(),8)==3) ||
               (S32(fn_802D6A9C(),4)==3 && S32(fn_802D6A9C(),8)==3)) {
                if(random<25) color=0;
                else if(random<50) color=1;
                else if(random<75) color=2;
                else color=1;
                if(F32(p,0x14)>0.0f)
                    Actor_CreateByID(fn_801F856C(),0x52555059,S32(p,4),&pos,0x260a00+color,-1,-1);
                else Actor_CreateByID(fn_801F856C(),0x52555059,S32(p,4),&pos,0x260000+color,-1,-1);
            } else if(random<=25) {
                if(random&1) {
                    if(F32(p,0x14)>0.0f)
                        Actor_CreateByID(fn_801F856C(),0x52555059,S32(p,4),&pos,0x260a00,-1,-1);
                    else Actor_CreateByID(fn_801F856C(),0x52555059,S32(p,4),&pos,0x260000,-1,-1);
                } else Actor_CreateByID(fn_801F856C(),0x48415254,S32(p,4),&pos,0,-1,-1);
            }
        } else if(S32(p,0x240)==2) {
            Actor_CreateByID(fn_801F856C(),0x48415254,S32(p,4),&pos,0,-1,-1);
        } else if(S32(p,0x240)==3) {
            Actor_CreateByID(fn_801F856C(),0x4d54424f,S32(p,4),&pos,0,-1,-1);
        } else if(S32(p,0x240)==4) {
            f32 y1=pos.y;
            s32 r1=fn_801CD664(13)-6;
            f32 dx1=(f32)r1;
            JGeometry::TVec3<f32> v1(pos.x+dx1,y1,0.0f);
            Actor_CreateByID(fn_801F856C(),0x48415254,S32(p,4),&v1,0,-1,-1);
            f32 y2=pos.y;
            s32 r2=fn_801CD664(13)-6;
            f32 dx2=(f32)r2;
            JGeometry::TVec3<f32> v2(pos.x+dx2,y2,0.0f);
            Actor_CreateByID(fn_801F856C(),0x48415254,S32(p,4),&v2,0,-1,-1);
        } else if(S32(p,0x240)==5) {
            if(fn_801CD664(100)<60)
                Actor_CreateByID(fn_801F856C(),0x48415254,S32(p,4),&pos,0,-1,-1);
        }
        if((u16)fn_8022461C(p+0xc,S32(p,4))==13 || (u16)fn_8022461C(p+0xc,S32(p,4))==57) {
            fn_8013CC50(S32(p,4),p+0xc,lbl_80540ECC,0x3d0,0,1,0,0,1);
            fn_801F0E34(p,0x30022,0);
        } else if((u16)fn_8022461C(p+0xc,S32(p,4))==14) {
            if(fn_802DE9A0()) {
                fn_8013CC50(S32(p,4),p+0xc,lbl_80540ECC,0x2a9,-1,1,0,0,1);
                fn_8013CC50(S32(p,4),p+0xc,lbl_80540ECC,0x2aa,0,0,0,0,1);
                fn_801F0E34(p,0x5005f,0);
            } else if(fn_802DEB58()) {
                fn_8013CC50(S32(p,4),p+0xc,lbl_80540ECC,0x45e,-1,1,0,0,1);
                fn_8013CC50(S32(p,4),p+0xc,lbl_80540ECC,0x45f,0,0,0,0,1);
                fn_801F0E34(p,0x5003f,0);
            }
        } else {
            fn_8013CC50(S32(p,4),p+0xc,lbl_80540ECC,0xab,1,0,0,0,1);
            fn_8013CC50(S32(p,4),p+0xc,lbl_80540ECC,0xac,1,0,0,0,1);
            fn_801F0E34(p,0x3000b,0);
        }
    } else if(S32(p,0x234)==1) {
        fn_801F0E34(p,0x3000b,0);
        roomB=S32(p,4);
        if(roomB>=8) {
            Actor_CreateByID(fn_801F856C(),0x4b4d5249,roomB,&pos,0,-1,-1);
            x1=lbl_8046E070;
            y1=yasiSmallY;
            for(i1=0;i1<5;i1++,x1++,y1++) {
                pos.x=F32(p,0xc)+*x1;
                pos.y=F32(p,0x10)+*y1;
                pos.z=0.0f;
                tile1=fn_80226AE0(&pos,S32(p,4));
                fn_802F9908(*(void**)(lbl_8053AB10+0x20),S32(p,4),tile1);
                fn_80226CA8(tile1,S32(p,4),&tilePos);
                tilePos.x+=8.0f;
                tilePos.y+=8.0f;
                Actor_CreateByID(fn_801F856C(),0x424c5a45,S32(p,4),&tilePos,15,-1,-1);
            }
        } else {
            fn_8013CC50(roomB,p+0xc,lbl_80540ECC,0x1a3,0,-1,0,0,1);
            fn_8013CC50(S32(p,4),p+0xc,lbl_80540ECC,0x1a4,0,0,0,0,1);
            fn_8013CC50(S32(p,4),p+0xc,lbl_80540ECC,0x1a4,0,0,0,0,1);
            s32 tile;
            s32 i;
            const f32* x;
            const f32* y;
            x=yasiLargeX;
            y=yasiLargeY;
            for(i=0;i<13;i++) {
                pos.x=F32(p,0xc)+*x;
                pos.y=F32(p,0x10)+*y;
                pos.z=0.0f;
                tile=fn_80226AE0(&pos,S32(p,4));
                fn_802F9908(*(void**)(lbl_8053AB10+0x20),S32(p,4),tile);
                fn_80226CA8(tile,S32(p,4),&tilePos);
                tilePos.x+=8.0f;
                tilePos.y+=8.0f;
                Actor_CreateByID(fn_801F856C(),0x424c5a45,S32(p,4),&tilePos,15,-1,-1);
                x++;
                y++;
            }
        }
    } else {
        roomC=S32(p,4);
        if(roomC>=8) Actor_CreateByID(fn_801F856C(),0x4b4d5249,roomC,&pos,5,-1,-1);
        else {
            fn_8013CC50(roomC,p+0xc,lbl_80540ECC,0x4ef,0,-1,0,0,1);
            fn_8013CC50(S32(p,4),p+0xc,lbl_80540ECC,0x4f0,0,0,0,0,1);
            fn_8013CC50(S32(p,4),p+0xc,lbl_80540ECC,0x4f1,0,0,0,0,1);
        }
        fn_801F0E34(p,0x3000b,0);
    }
    *(u8*)(p+0x11c)=0;
}
#pragma opt_lifetimes reset
extern "C" void fn_802D1DB4(char* p) {
    s32 flag = 7;
    YasiDrawParam param;
    ((u8*)&param.key.a)[3] = *(u8*)(p + 0x254);
    if (*(u8*)(p + 0xc4) != 0) {
        param.f20 = 0;
        flag = -1;
        param.color = fn_8023CB24(*(s32*)(p + 0xc8)) + 1;
        param.palette = fn_8023CA88(*(s32*)(p + 0xc8));
    }
    u32 n = *(u32*)(p + 4);
    if (((YasiMgr*)fn_802D6A9C())->flag(n) != 0) {
        fn_801F02BC(p, lbl_8046E100, 0x1bb + *(s32*)(p + 0x234) + *(s32*)(p + 0x238), &param, flag, 0, 1, lbl_80540ECC, lbl_80540ECC);
    } else {
        fn_801F02BC(p, lbl_8046E100, 0x21 + *(s32*)(p + 0x234) + *(s32*)(p + 0x238), &param, flag, 0, 1, lbl_80540ECC, lbl_80540ECC);
    }
    if (*(s32*)(p + 0x234) == 1) {
        u32 id = *(u32*)(p + 4);
        Rgba802D c(0, 0, 0, 0x80);
        fn_80158B5C(*(void**)(lbl_8053AB10 + 0x2c), id, p + 0xc, c, lbl_80540EE0);
    }
}

extern "C" f32* fn_8023E7B0(s32);
extern "C" s32 fn_8023DE58(s32);
extern "C" u8 fn_8023BCD4(s32);
extern "C" u8 fn_801F2618(void*, s32, s32);
extern "C" u8 fn_801F2B7C(void*, s32, s32, s32);
extern "C" u8 fn_801F2B20(void*, s32);
extern "C" void* fn_8013C824(void);
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void*, void*);
extern "C" void fn_8013CB44(s32, void*, s32, s32, s32);
extern "C" void* fn_801F856C(void);
extern "C" s32 fn_801F7818(void*, u32, s32, void*, s32);
extern "C" u32 fn_80226850(void*, s32);
extern "C" void fn_802A381C(void*, void*, s32, s32);
extern "C" void fn_8030C210(void*, void*);
extern "C" u8* lbl_8053AAF8;
extern "C" u32 lbl_8053AC98;
extern "C" const f32 lbl_80540F00;
extern "C" s32 fn_801F7818(void*, u32, s32, void*, s32);
extern "C" void* fn_801F856C(void);
extern "C" u32 lbl_8053ADF8;
extern "C" const f32 lbl_80540EE4;
extern "C" const f32 lbl_80540F04;
inline void setYasiEmitter(char* p, s32 direction, s32 effect) {
    if (*(s32*)(p + 0x244) != direction) {
        if (*(void**)(p + 0x230) != NULL) {
            void* manager = *(void**)((char*)fn_8013C824() + 0xc);
            forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(manager, *(void**)(p + 0x230));
            *(void**)(p + 0x230) = NULL;
        }
        *(s32*)(p + 0x230) = fn_8013CC50(*(s32*)(p + 4), p + 0xc, lbl_80540ECC, effect, 0, 0, 0, 0, 1);
        *(s32*)(p + 0x244) = direction;
    }
}
#pragma opt_lifetimes on
extern "C" void fn_802D1FEC(void* this_) {
    u8* actor;
    char** e;
    char* p = (char*)this_;
    char* buf[0x400];

    *(u8*)(p + 0x254) = 0xff;
    if (*(u8*)(p + 0xc4) != 0) {
        f32* v = fn_8023E7B0(*(s32*)(p + 0xc8));
        *(f32*)(p + 0xc) = v[0];
        *(f32*)(p + 0x10) = v[1];
        *(f32*)(p + 0x14) = v[2];
        *(s32*)(p + 4) = fn_8023DE58(*(s32*)(p + 0xc8));
        *(u8*)(p + 0x254) = fn_8023BCD4(*(s32*)(p + 0xc8));
        if (*(s32*)(p + 0x234) == 1) {
            *(s32*)(p + 0x250) -= 1;
            if (*(s32*)(p + 0x250) == 0) {
                *(s32*)(p + 0x250) = 4;
                *(s32*)(p + 0x23c) += 1;
                if (*(s32*)(p + 0x23c) >= 3) {
                    *(s32*)(p + 0x23c) = 0;
                }
            }
            if (*(s32*)(p + 4) >= 8) {
                *(s32*)(p + 0x238) = *(s32*)(p + 0x23c) + 2;
            } else {
                *(s32*)(p + 0x238) = 2;
            }
        }
    } else {
        s32 id;
        s32 mode = *(s32*)(p + 0x114);
        if (lbl_8053AAF8[0x7f] != 0) mode = 0;
        id = *(s32*)(p + 4);
        if (((YasiMgr*)fn_802D6A9C())->flag(id) == 0) {
            *(f32*)(p + 0x44) += lbl_80540EE4;
            *(JGeometry::TVec3<f32>*)(p + 0xc) += *(JGeometry::TVec3<f32>*)(p + 0x3c);
            if (*(f32*)(p + 0x14) < 0.0f || fn_801F2618(p, 0, 0)) {
                if (*(f32*)(p + 0x14) < 0.0f) {
                    if ((u16)fn_80226850(p + 0xc, *(s32*)(p + 4)) == 0x90) {
                        fn_802A381C((void*)lbl_8053AC98, p + 0xc, *(s32*)(p + 4), 0x91);
                    } else if ((u16)fn_80226850(p + 0xc, *(s32*)(p + 4)) == 0x91 ||
                               (u16)fn_80226850(p + 0xc, *(s32*)(p + 4)) == 0x22e) {
                        fn_802A381C((void*)lbl_8053AC98, p + 0xc, *(s32*)(p + 4), 0x92);
                    }
                }
                if (*(s32*)(p + 0x234) == 2) {
                    s32 n = fn_801F7818(fn_801F856C(), 0x424c5a32, *(s32*)(p + 4), buf, -1);
                    e = buf;
                    for (s32 i = 0; i < n; e++, i++) {
                        actor = (u8*)*e;
                        if (actor != NULL) {
                            if (actor != NULL) {
                                f32 dy = *(f32*)(actor + 0x10) - *(f32*)(p + 0x10);
                                f32 dx = *(f32*)(actor + 0xc) - *(f32*)(p + 0xc);
                                f32 d = std::sqrtf(dx * dx + dy * dy);
                                if (d < lbl_80540F00) *(s16*)(actor + 0x94) = 2;
                            }
                        }
                    }
                }
                ((VObj_802D*)p)->m7();
            } else {
                if (fn_801F2B7C(p, mode, *(s32*)(p + 0xc8), 1) || fn_801F2B20(p, 0)) {
                    ((VObj_802D*)p)->m7();
                }
            }
        } else {
            if (*(s32*)(p + 0x24c) == 0) {
                *(f32*)(p + 0x10) -= *(f32*)(p + 0x14);
                *(f32*)(p + 0x14) = 0.0f;
                *(f32*)(p + 0x44) = 0.0f;
                *(s32*)(p + 0x24c) = 1;
            }
            *(f32*)(p + 0x40) += lbl_80540F04;
            *(JGeometry::TVec3<f32>*)(p + 0xc) += *(JGeometry::TVec3<f32>*)(p + 0x3c);
            if (fn_801F2B7C(p, mode, *(s32*)(p + 0xc8), 1) ||
                fn_801F2B20(p, 0) || fn_801F2618(p, 0, 0)) {
                ((VObj_802D*)p)->m7();
            }
        }
        fn_8030C210(*(void**)(lbl_8053AB10 + 0x24), p + 0xc);
    }
    if (*(s32*)(p + 0x234) == 1) {
        f32 oldX;
        f32 x;
        x = *(f32*)(p + 0xc);
        oldX = *(f32*)(p + 0x18);
        if (x != oldX || *(f32*)(p + 0x10) != *(f32*)(p + 0x1c)) {
            if (x != oldX) {
                if (x < oldX) setYasiEmitter(p, 1, 0x1a7);
                else setYasiEmitter(p, 2, 0x1a9);
            } else {
                if (*(f32*)(p + 0x10) < *(f32*)(p + 0x1c)) setYasiEmitter(p, 3, 0x1aa);
                else setYasiEmitter(p, 4, 0x1a6);
            }
        } else {
            setYasiEmitter(p, 0, 0x1a8);
        }
        if (*(void**)(p + 0x230) != NULL) {
            fn_8013CB44(*(s32*)(p + 0x230), p + 0xc, 0, 1, 1);
            *(u8*)(*(s32*)(p + 0x230) + 0xbb) = *(u8*)(p + 0x254);
        }
    }
}
#pragma opt_lifetimes reset
extern "C" char lbl_804A9428[];
extern "C" Vec3f_802D lbl_804C0EA0;
extern "C" unsigned int lbl_8053AB68;
extern "C" unsigned int fn_8022461C(void*, unsigned int);
extern "C" void fn_801EE434(void*);
extern "C" void __dt__5ActorFv(void*, int);
void operator delete(void*);
extern "C" void* fn_802D26F8(void* this_, short freeFlag) {
    if (this_ != 0) {
        char* p = (char*)this_;
        *(void**)this_ = lbl_804A9428;
        if ((unsigned short)fn_8022461C(p + 0xc, *(unsigned int*)(p + 4)) != 0xd) {
            lbl_804C0EA0.x = *(float*)(p + 0xc);
            lbl_804C0EA0.y = *(float*)(p + 0x10);
            lbl_804C0EA0.z = *(float*)(p + 0x14);
            lbl_8053AB68 = *(unsigned int*)(p + 4);
        }
        void* h = *(void**)(p + 0x230);
        if (h != 0) {
            fn_801EE434(h);
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" int fn_8013CC50(s32, void*, f32, s32, s32, s32, s32, s32, s32);
extern "C" void fn_802D27A8(void* this_) {
    char* p = (char*)this_;

    *(u32*)(p + 0x240) = *(u32*)(p + 0x90) & 0x7f;
    *(u32*)(p + 0x234) = (*(u32*)(p + 0x90) >> 7) & 0x1f;
    *(u32*)(p + 0x238) = 0;
    *(u32*)(p + 0x23c) = 0;
    *(f32*)(p + 0x60) = -8.0f;
    *(f32*)(p + 0x64) = -8.0f;
    *(f32*)(p + 0x68) = 8.0f;
    *(f32*)(p + 0x6c) = 8.0f;
    *(f32*)(p + 0x80) = -4.0f;
    *(f32*)(p + 0x84) = -4.0f;
    *(f32*)(p + 0x88) = 4.0f;
    *(f32*)(p + 0x8c) = 4.0f;
    *(u8*)(p + 0x254) = 0xff;
    *(s16*)(p + 0x94) = 0;
    *(u32*)(p + 0x248) = 0;
    *(u32*)(p + 0x24c) = 0;
    *(u32*)(p + 0x230) = 0;
    *(u32*)(p + 0x244) = 0;
    if (*(s32*)(p + 0x234) == 1) {
        *(s32*)(p + 0x230) = fn_8013CC50(*(s32*)(p + 4), p + 0xc, 1.0f, 0x1a8, 0, 0, 0, 0, 1);
    }
    *(s32*)(p + 0x250) = 4;
}

void __sinit_tu_802D14DC_cpp(void) {}
#include "JSystem/JAudio/JASFakeMatchFSA.h"
