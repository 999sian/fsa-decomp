// TU 0x8037b374-0x8037d784 (actor JIJI).
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"

struct JijiBlock {
    u8 raw[0x288];
};
extern "C" u8 lbl_804AE9C0[];

// ---- from src/Game/Jiji_ctor_8037CE00.cpp ----
// fn_8037CE00 - "JIJI" real constructor. Identical shape to FTGL/TWTG -
// see Ftgl_ctor_80317C38.cpp for the full technique writeup. Base Actor
// ctor + own vtable install, allocates a 0x1c-byte resource handle and
// resets it via fn_8031709C if allocation succeeded,
// storing the handle (or null) at +0x274.



struct Actor {
    Actor();
    ~Actor();
};

extern "C" void fn_8031709C(void* h);

class ResourceHandle {
public:
    ResourceHandle() { fn_8031709C(this); }
    ~ResourceHandle();
private:
    unsigned char pad[0x1c];
};

extern "C" void* lbl_804AEED0[];

class Jiji : public Actor {
public:
    Jiji();
};

Jiji::Jiji() : Actor() {
    *(void**)this = lbl_804AEED0;
    ResourceHandle* h = new ResourceHandle();
    *(ResourceHandle**)((char*)this + 0x274) = h;
}

typedef void (Jiji::*JijiAction)();
extern "C" void __sinit_jiji_cpp(void);
#pragma opt_lifetimes on
extern "C" void fn_8037CE5C(void) {
    const JijiAction* src = (JijiAction*)lbl_804AE9C0;
    JijiAction* dst = (JijiAction*)(lbl_804AE9C0+0x288);
    *(dst+0) = *(src+0);
    *(dst+1) = *(src+1);
    *(dst+2) = *(src+2);
    *(dst+3) = *(src+3);
    *(dst+4) = *(src+4);
    *(dst+5) = *(src+5);
    *(dst+6) = *(src+6);
    *(dst+7) = *(src+7);
    *(dst+8) = *(src+8);
    *(dst+9) = *(src+9);
    *(dst+10) = *(src+10);
    *(dst+11) = *(src+11);
    *(dst+12) = *(src+12);
    *(dst+13) = *(src+13);
    *(dst+14) = *(src+14);
    *(dst+15) = *(src+15);
    *(dst+16) = *(src+16);
    *(dst+17) = *(src+17);
    *(dst+18) = *(src+18);
    *(dst+19) = *(src+19);
    *(dst+20) = *(src+20);
    *(dst+21) = *(src+21);
    *(dst+22) = *(src+22);
    *(dst+23) = *(src+23);
    *(dst+24) = *(src+24);
    *(dst+25) = *(src+25);
    *(dst+26) = *(src+26);
    *(dst+27) = *(src+27);
    *(dst+28) = *(src+28);
    *(dst+29) = *(src+29);
    *(dst+30) = *(src+30);
    *(dst+31) = *(src+31);
    *(dst+32) = *(src+32);
    *(dst+33) = *(src+33);
    *(dst+34) = *(src+34);
    *(dst+35) = *(src+35);
    *(dst+36) = *(src+36);
    *(dst+37) = *(src+37);
    *(dst+38) = *(src+38);
    *(dst+39) = *(src+39);
    *(dst+40) = *(src+40);
    *(dst+41) = *(src+41);
    *(dst+42) = *(src+42);
    *(dst+43) = *(src+43);
    *(dst+44) = *(src+44);
    *(dst+45) = *(src+45);
    *(dst+46) = *(src+46);
    *(dst+47) = *(src+47);
    *(dst+48) = *(src+48);
    *(dst+49) = *(src+49);
    *(dst+50) = *(src+50);
    *(dst+51) = *(src+51);
    *(dst+52) = *(src+52);
    *(dst+53) = *(src+53);
    __sinit_jiji_cpp();
}
#pragma opt_lifetimes reset
// ---- JIJI small state helpers (0x8037B374-0x8037B7EC) ----
#include "JSystem/JGeometry/Vec.h"
#include "JSystem/JMath/JMath.h"

struct JijiRandom {
    u32 seed;
    f32 get_ufloat_1() {
        union { f32 f; u32 s; } out;
        seed = seed * 0x19660d + 0x3c6ef35f;
        out.s = (seed >> 9) | 0x3f800000;
        return out.f - 1.0f;
    }
};
struct JijiGame { u8 pad[0xb4]; JijiRandom rnd; };
extern JijiGame* lbl_8053AAF8;

struct JijiWork {
    u8 pad0[0xc];
    JGeometry::TVec3<f32> pos;
    u8 pad18[0x234 - 0x18];
    s32 m234;
    u32 m238;
    u32 m23C;
    u8 pad240[0x248 - 0x240];
    s32 m248;
    u8 pad24C[0x273 - 0x24C];
    u8 m273;
};

extern u8 lbl_8053A1D0[4];
extern u8 lbl_8053A1D4[4];
extern u8 lbl_8053A1D8[2];
extern u8 lbl_8053A1DC[4];
extern u8 lbl_8053A1E0[4];
extern u8 lbl_8053A1E4[4];
extern u8 lbl_8053A1E8[4];
extern u8 lbl_8053A1EC[4];
extern u8 lbl_8053A1F0[4];
extern u8 lbl_8053A1F4[2];
extern u8 lbl_8053A1F8[4];
extern u8 lbl_8053A1FC[4];
extern u8 lbl_8053A200[4];
extern u8 lbl_8053A204[2][4];
extern u8 lbl_8053A20C[2];

extern "C" void fn_8037B374(JijiWork* w, const JGeometry::TVec3<f32>* pos, s32 n) {
    w->pos = *pos;
    w->m248 = n / 3;
    w->m273 = 1;
}

extern "C" void fn_8037B3A8(JijiWork* w) {
    if (w->m234 <= 0) {
        w->m238 = w->m238 + 1;
        w->m238 = w->m238 & 1;
        w->m234 = lbl_8053A20C[w->m238];
    }
}

extern "C" void fn_8037B3E0(JijiWork* w) {
    if (w->m248 < 3) {
        if (w->m234 == 10) {
            w->m238 = 1;
        } else if (w->m234 <= 0) {
            w->m234 = (s32)(50.0f * lbl_8053AAF8->rnd.get_ufloat_1()) + 40;
            w->m238 = 0;
        }
    } else {
        w->m234 = 0;
        w->m238 = 0;
    }
}

extern "C" void fn_8037B488(JijiWork* w) {
    if (w->m234 == 25) {
        w->m238 = 1;
    } else if (w->m234 == 10) {
        w->m238 = 2;
    } else if (w->m234 <= 0) {
        w->m234 = 30;
        w->m238 = 0;
    }
}

extern "C" void fn_8037B4D0(JijiWork* w) {
    if (w->m234 == 35) {
        w->m238 = 1;
    } else if (w->m234 == 20) {
        w->m238 = 2;
    } else if (w->m234 == 18) {
        w->m238 = 0;
    } else if (w->m234 == 17) {
        w->m238 = 1;
    } else if (w->m234 == 2) {
        w->m238 = 2;
    } else if (w->m234 <= 0) {
        w->m238 = 0;
        w->m234 = 55;
    }
}

#define JIJI_CYCLE4(name, a, b)                  \
    extern "C" void name(JijiWork* w) {          \
        if (w->m234 <= 0) {                      \
            w->m23C = w->m23C + 1;               \
            w->m23C = w->m23C & 3;               \
            w->m234 = a[w->m23C];                \
            w->m238 = b[w->m23C];                \
        }                                        \
    }
#define JIJI_CYCLE2(name, a)                     \
    extern "C" void name(JijiWork* w) {          \
        if (w->m234 <= 0) {                      \
            w->m238 = w->m238 + 1;               \
            w->m238 = w->m238 & 1;               \
            w->m234 = a[w->m238];                \
        }                                        \
    }

extern "C" void fn_8037B554(JijiWork* w) {
    if (w->m234 <= 0) {
        w->m23C = w->m23C + 1;
        w->m23C = w->m23C & 3;
        w->m234 = lbl_8053A200[w->m23C];
        w->m238 = lbl_8053A204[w->m248 / 2][w->m23C];
    }
}

JIJI_CYCLE4(fn_8037B5B4, lbl_8053A1F8, lbl_8053A1FC)
JIJI_CYCLE2(fn_8037B5FC, lbl_8053A1F4)
JIJI_CYCLE4(fn_8037B634, lbl_8053A1EC, lbl_8053A1F0)
JIJI_CYCLE4(fn_8037B67C, lbl_8053A1E4, lbl_8053A1E8)
JIJI_CYCLE4(fn_8037B6C4, lbl_8053A1DC, lbl_8053A1E0)
JIJI_CYCLE2(fn_8037B70C, lbl_8053A1D8)
JIJI_CYCLE4(fn_8037B744, lbl_8053A1D0, lbl_8053A1D4)

extern "C" void fn_8037B78C(JijiWork* w) {
    if (w->m234 <= 0) {
        w->m234 = w->m23C;
        w->m238 = w->m238 + 1;
        w->m238 = w->m238 & 7;
    }
}

extern "C" void fn_8037B7BC(JijiWork* w) {
    if (w->m234 <= 0) {
        w->m234 = w->m23C;
        w->m238 = w->m238 + 1;
        w->m238 = w->m238 & 1;
    }
}

extern "C" void fn_8037B7EC(JijiWork* w) {
    w->m238 = 0;
}

#include "Game/AnimEffectRec.h"
extern "C" void fn_801EE434(void* h);


extern "C" void __dt__13AnimEffectRecFv(void* p, int flag);
extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_8037CD78(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AEED0;
        if (*(AnimEffectRec**)((char*)this_ + 0x274) != 0) {
            __dt__13AnimEffectRecFv(*(AnimEffectRec**)((char*)this_ + 0x274), 1);
        }
        if (*(void**)((char*)this_ + 0x278) != 0) {
            fn_801EE434(*(void**)((char*)this_ + 0x278));
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

#include "Game/ItemBase.h"
struct JijiTable {
    u8 pad0[0xd8];
    s32 frames[11][4];
    char res0[0x14];
    char res1[0x14];
    char res2[0x18];
};
extern const JijiTable lbl_804753C0;
static inline s32 jijiFrame(const s32 (*fr)[4], u8* p) { return *(const s32*)((const u8*)fr + *(s32*)(p + 0x264) * 16 + *(s32*)(p + 0x248) * 4); }
#define JIJI_FRAME(t, p) (*(s32*)((p) + 0x238) + ((const s32(*)[4])((const u8*)(t) + 0xd8))[*(s32*)((p) + 0x264)][*(s32*)((p) + 0x248)])
extern "C" void fn_801F06F0(void* actor, const char* res, u32 id, DrawRec* rec, s32 p5, f32 a, f32 b);
extern "C" void fn_801F0E34(void* actor, u32 msg, s32 arg);
extern "C" void fn_803075AC(void*, s32, void*, s32, s32, s32, s32, s32, s32, s32);
extern "C" void fn_80307AC8(void* obj, u32 id, void* pos, u32 kind, u32 a, u32 b, s32 c);

extern f32 lbl_80543054;
struct JijiUpdateActor {
    virtual void v00(); virtual void v01(); virtual void v02();
    virtual void v03(); virtual void v04(); virtual void v05();
    virtual void v06(); virtual void v07(); virtual void v08();
    virtual void v09(); virtual void v10(); virtual void v11();
    virtual void v12(s32,s32);
};

#include "JSystem/JGeometry/Box.h"
static inline void jijiExpandBox(JGeometry::TBox2<f32>* dst,f32* src,f32 v) {
    dst->set(src[0]-v,src[1]-v,v+src[2],v+src[3]);
}
static inline void jijiBoxTranslate(JGeometry::TBox2<f32>* b,u8* p) {
    b->addPos(*(JGeometry::TVec2<f32>*)(p+0xc));
}

extern f32 lbl_8054304C;
extern "C" void fn_801EE558(void*, JGeometry::TVec3<f32>*, f32*, s32);

extern "C" void fn_80239914(void*, s32, s32);
extern "C" u8 fn_80303750(s32);
extern "C" u8 fn_8022C8EC(s32);
extern "C" u8 fn_8022B160();
extern "C" void fn_8022FEB8(void*,s32,s32,s32,s32);
extern "C" s32 fn_8023AF14(void*,s32,s32,f32);
extern "C" s32 fn_8022FD8C(s32);
extern "C" s32 fn_8037E54C(s32);
extern "C" f32* fn_8023E724(s32);
extern "C" u8 fn_802300EC(s32);
extern "C" u8 fn_8038C678(s32,s32,s32,s32,const JGeometry::TVec3<f32>&,s32);
extern "C" void fn_8022FF8C(s32,void*,s32,s32,s32,s32);
extern "C" u8 fn_80388CAC(s32,s32);
extern "C" void* fn_8013CC50(s32,void*,s32,s32,s32,s32,s32,s32,f32);
extern "C" void fn_8015F8FC(void*,s32,void*,s32);
extern "C" void* fn_802D6A9C();
extern "C" void fn_802D79E8(void*,s32,s32,f32,f32);
extern "C" void* fn_8013C824();
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void*,void*);
extern u8* lbl_8053AB10;
extern u8 lbl_80529DEC[];
extern u8 lbl_8050DB0C[];
extern JijiAction lbl_804AEC48[];
static inline void jijiFace(u8* p,s32 player) {
    if (*(s32*)(p+0x24c)) {
        --*(s32*)(p+0x24c);
    } else {
        *(s32*)(p+0x24c)=20;
        JGeometry::TVec3<f32> dir;
        f32 dist;
        fn_801EE558(p,&dir,&dist,player);
        if(dist<100.0f) {
            f32 rad=JMAAtan2Radian(-dir.x,-dir.y);
            u16 ang=(u16)(s32)(rad*lbl_8054304C);
            if(ang<0x2000 || ang>=0xe000) *(s32*)(p+0x248)=3;
            else if(ang>=0x2000 && ang<0x6000) *(s32*)(p+0x248)=1;
            else if(ang>=0x6000 && ang<=0xa000) *(s32*)(p+0x248)=2;
            else *(s32*)(p+0x248)=0;
        } else *(s32*)(p+0x248)=2;
    }
}
static inline void jijiExpand(f32* dst,f32* src,f32 v) {
    dst[3]=v+src[3];
    dst[2]=v+src[2];
    dst[1]=src[1]-v;
    dst[0]=src[0]-v;
}
static inline void jijiBoxPos(f32* b,u8* p) {
    b[0]+=*(f32*)(p+0xc);
    b[2]+=*(f32*)(p+0xc);
    b[1]+=*(f32*)(p+0x10);
    b[3]+=*(f32*)(p+0x10);
}

extern "C" void fn_8037B7F8(u8* this_) {
    const JijiTable* t = &lbl_804753C0;
    if (*(s32*)(this_ + 0x230) == 5 && *(AnimEffectRec**)(this_ + 0x274) != 0) {
        u32 snd = fn_80316E74(*(AnimEffectRec**)(this_ + 0x274), *(s32*)(this_ + 0x244));
        if (snd != 0xffffffff) {
            fn_801F0E34(this_, snd, 0);
        }
    }
    if (*(s32*)(this_ + 0x230) == 4) {
        return;
    }
    if (*(s32*)(this_ + 0x258) == 0x15) {
        return;
    }
    if (*(s32*)(this_ + 0x258) == 0x11 && *(s32*)(this_ + 0x230) == 2) {
        fn_801F06F0(this_, t->res0, 0x2b1, 0, 7, 1.0f, 1.0f);
    } else if (*(s32*)(this_ + 0x258) == 0x12 || *(s32*)(this_ + 0x258) == 0x13 || *(s32*)(this_ + 0x258) == 0x14) {
        DrawRec rec;
        ((u8*)&rec.w10)[3] = *(u8*)(this_ + 0x270);
        fn_801F06F0(this_, t->res0,
                    *(s32*)(this_ + 0x25c) + (*(s32*)(this_ + 0x238) + *(const s32*)((u32)t->frames + (*(u32*)(this_ + 0x264) * 16 + *(u32*)(this_ + 0x248) * 4))),
                    &rec, 7, 1.0f, 1.0f);
    } else if (*(s32*)(this_ + 0x258) == 0x23 && *(AnimEffectRec**)(this_ + 0x274) != 0 &&
               fn_80316E34(*(AnimEffectRec**)(this_ + 0x274)) >= 0) {
        fn_801F06F0(this_, t->res1, *(s32*)(this_ + 0x25c) + fn_80316E34(*(AnimEffectRec**)(this_ + 0x274)), 0, 7, 1.0f, 1.0f);
        fn_803075AC(*(void**)(this_ + 0x198), *(s32*)(this_ + 4), this_ + 0xc,
                    *(s32*)(this_ + 0x25c) + fn_80316E34(*(AnimEffectRec**)(this_ + 0x274)), 0, 2, -1, 0, 0, 0);
    } else if (*(s32*)(this_ + 0x260) == 0) {
        fn_801F06F0(this_, t->res0,
                    *(s32*)(this_ + 0x25c) + (*(s32*)(this_ + 0x238) + *(const s32*)((u32)t->frames + (*(u32*)(this_ + 0x264) * 16 + *(u32*)(this_ + 0x248) * 4))),
                    0, -1, 1.0f, 1.0f);
    } else if (*(s32*)(this_ + 0x260) == 1) {
        fn_801F06F0(this_, t->res2,
                    *(s32*)(this_ + 0x25c) + (*(s32*)(this_ + 0x238) + *(const s32*)((u32)t->frames + (*(u32*)(this_ + 0x264) * 16 + *(u32*)(this_ + 0x248) * 4))),
                    0, 7, 1.0f, 1.0f);
        fn_80307AC8(*(void**)(this_ + 0x198), *(s32*)(this_ + 4), this_ + 0xc,
                    *(s32*)(this_ + 0x25c) + (*(s32*)(this_ + 0x238) + *(const s32*)((u32)t->frames + (*(u32*)(this_ + 0x264) * 16 + *(u32*)(this_ + 0x248) * 4))),
                    0, 0, -1);
    } else {
        fn_801F06F0(this_, t->res1,
                    *(s32*)(this_ + 0x25c) + (*(s32*)(this_ + 0x238) + *(const s32*)((u32)t->frames + (*(u32*)(this_ + 0x264) * 16 + *(u32*)(this_ + 0x248) * 4))),
                    0, 7, 1.0f, 1.0f);
        fn_803075AC(*(void**)(this_ + 0x198), *(s32*)(this_ + 4), this_ + 0xc,
                    *(s32*)(this_ + 0x25c) + (*(s32*)(this_ + 0x238) + *(const s32*)((u32)t->frames + (*(u32*)(this_ + 0x264) * 16 + *(u32*)(this_ + 0x248) * 4))),
                    0, 2, -1, 0, 0, 0);
    }
}

extern "C" void fn_8037BC30(u8* p) {
    s32 ready=0;
    s32 active=0;
    JGeometry::TBox2<f32> box;
    JGeometry::TBox2<f32> range;
    JGeometry::TVec3<f32> pos4,pos6,posCall,posAnim;
    box.set(*(JGeometry::TBox2<f32>*)(p+0x60));
    jijiBoxTranslate(&box,p);
    if(*(s32*)(p+0x230)!=3 && *(s32*)(p+0x230)!=4)
        fn_80239914(&box,*(s32*)(p+4),*(s32*)(p+0x198));
    if(*(s32*)(p+0x258)==4 && *(u8*)(p+0x273)==1) {
        *(u8*)(p+0x273)=0;
        --*(s32*)(p+0x234);
        (((Jiji*)p)->*lbl_804AEC48[*(s32*)(p+0x258)])();
        return;
    }
    if(*(u8*)(p+0x272)==1) {
        if(*(s32*)(p+0x268)==1) jijiExpandBox(&range,(f32*)(p+0x60),16.0f);
        else if(*(s32*)(p+0x268)==2) {range.set(*(JGeometry::TBox2<f32>*)(p+0x60));}
        else if(*(s32*)(p+0x268)==3) jijiExpandBox(&range,(f32*)(p+0x60),40.0f);
    } else {
        if(*(s32*)(p+0x268)==1) jijiExpandBox(&range,(f32*)(p+0x60),28.0f);
        else if(*(s32*)(p+0x268)==2) jijiExpandBox(&range,(f32*)(p+0x60),12.0f);
        else if(*(s32*)(p+0x268)==3) jijiExpandBox(&range,(f32*)(p+0x60),48.0f);
    }
    jijiBoxTranslate(&range,p);
    if(*(s32*)(p+0x230)==2) {
        *(JGeometry::TVec3<f32>*)(p+0xc)+=*(JGeometry::TVec3<f32>*)(p+0x3c);
        *(f32*)(p+0x44)-=0.2f;
    }
    switch(*(s32*)(p+0x230)) {
    case 0:
        if(*(s32*)(p+4)<8) *(s32*)(p+0x230)=1;
        else *(s32*)(p+0x230)=3;
        if(*(s32*)(p+0x258)==18 || *(s32*)(p+0x258)==19 || *(s32*)(p+0x258)==20)
            *(void**)(p+0x278)=fn_8013CC50(*(s32*)(p+4),p+0xc,0x1fe,0,0,0,0,1,1.0f);
        break;
    case 3:
        for(s32 i=0;i<4;i++) {
            if((u8)((*((u8*)lbl_8053AAF8+0x82)&(u8)(1<<i))!=0)==1) {
                active++;
                if(!fn_80303750(i) || !fn_8022C8EC(i)) ready++;
            }
        }
        if(ready==active) *(s32*)(p+0x230)=1;
        break;
    case 4:
        if(*(s32*)(p+4)<8) {
            pos4.set(*(JGeometry::TVec3<f32>*)(p+0xc));
            pos4.y+=32.0f;
            pos4.z+=16.0f;
            fn_8013CC50(*(s32*)(p+4),&pos4,0x17d,1,0,0,0,1,1.0f);
            fn_8015F8FC(*(void**)(lbl_8053AB10+0x30),*(s32*)(p+4),&pos4,3);
        }
        *(s32*)(p+0x230)=1;
        break;
    case 1:
        jijiFace(p,0);
        if(fn_8022B160()) break;
        if(*(s32*)(p+0x268)==0)
            fn_8022FEB8(&box,*(s32*)(p+4),*(s32*)(p+0x198),1,0);
        else if(*(u8*)(p+0x272)==1)
            fn_8022FEB8(&range,*(s32*)(p+4),*(s32*)(p+0x198),0,0);
        else {
            if(fn_8023AF14(&range,*(s32*)(p+4),0,500.0f)==-1) *(u8*)(p+0x272)=1;
            break;
        }
        *(s32*)(p+0x244)=fn_8022FD8C(*(s32*)(p+0x198));
        if(*(s32*)(lbl_80529DEC+0x118)>=8 && *(s32*)(lbl_80529DEC+0x11c)==0)
            *(s32*)(p+0x250)=fn_8037E54C(*(s32*)(p+0x244));
        else if(*(u8*)(lbl_8050DB0C+4)) *(s32*)(p+0x250)=*(s16*)(lbl_8050DB0C+6);
        if(*(s32*)(p+0x244)<0) break;
        if(fn_8023E724(*(s32*)(p+0x244))[2]!=0.0f) break;
        if(!fn_802300EC(*(s32*)(p+0x244))) break;
        {s32 handle=*(s32*)(p+0x198);s32 room=*(s32*)(p+4);posCall=*(JGeometry::TVec3<f32>*)(p+0xc);
        if(!fn_8038C678(*(s32*)(p+0x244),*(s32*)(p+0x250),handle,room,posCall,16)) break;}
        *(s32*)(p+0x24c)=0;
        jijiFace(p,*(s32*)(p+0x244)+1);
        *(s32*)(p+0x230)=5;
        *(s32*)(p+0x240)=0;
        if(*(s32*)(p+0x258)==18 || *(s32*)(p+0x258)==19 || *(s32*)(p+0x258)==20) fn_801F0E34(p,0x60001,0);
        break;
    case 2:
        if(*(f32*)(p+0x14)<=0.0f) {
            *(f32*)(p+0x14)=0.0f;
            *(f32*)(p+0x44)=0.0f;
            *(f32*)(p+0x40)=0.0f;
            *(f32*)(p+0x3c)=0.0f;
            *(s32*)(p+0x230)=1;
            fn_8013CC50(*(s32*)(p+4),p+0xc,0x3cf,0,-1,0,0,1,1.5f);
            fn_802D79E8(fn_802D6A9C(),*(s32*)(p+4),0,4.0f,0.0f);
        }
        break;
    case 5:
        if(*(s32*)(p+0x268)==0) fn_8022FF8C(*(s32*)(p+0x244),&box,*(s32*)(p+4),*(s32*)(p+0x198),1,0);
        else fn_8022FF8C(*(s32*)(p+0x244),&range,*(s32*)(p+4),*(s32*)(p+0x198),0,0);
        if(!fn_80388CAC(*(s32*)(p+0x244),*(s32*)(p+0x198))) break;
        *(s32*)(p+0x240)=0;
        *(s32*)(p+0x244)=-1;
        ((void(*)(u8*,s32,s32))(*(void***)(p))[12])(p,255,1);
        if(*(s32*)(p+0x268)!=0) {*(u8*)(p+0x272)=0; *(s32*)(p+0x268)=0;}
        if(*(s32*)(p+0x254)) *(s32*)(p+0x230)=6;
        else *(s32*)(p+0x230)=1;
        if(*(AnimEffectRec**)(p+0x274)) { s32 room=*(s32*)(p+4); posAnim=*(JGeometry::TVec3<f32>*)(p+0xc); fn_80316E50(*(AnimEffectRec**)(p+0x274),room,posAnim); }
        break;
    case 6:
        ++*(s32*)(p+0x240);
        if(*(s32*)(p+0x240)<150) break;
        if(*(s32*)(p+4)<8) {
            pos6.set(*(JGeometry::TVec3<f32>*)(p+0xc));
            pos6.y+=32.0f; pos6.z+=16.0f;
            fn_8013CC50(*(s32*)(p+4),&pos6,0x17d,1,0,0,0,1,1.0f);
            fn_8015F8FC(*(void**)(lbl_8053AB10+0x30),*(s32*)(p+4),p+0xc,3);
        }
        if(*(void**)(p+0x278)) {
            void* mgr=*(void**)((u8*)fn_8013C824()+0xc);
            forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr,*(void**)(p+0x278));
            *(void**)(p+0x278)=0;
        }
        fn_801F0E34(p,0x40017,0);
        *(u8*)(p+0x11c)=0;
        break;
    }
    if(*(s32*)(p+0x258)==18 || *(s32*)(p+0x258)==19 || *(s32*)(p+0x258)==20) {
        f32 dist;
        fn_801EE558(p,0,&dist,0);
        if(*(s32*)(p+0x230)==5) {
            *(u8*)(p+0x270)+=2;
            if(*(u8*)(p+0x270)>=200) *(u8*)(p+0x270)=200;
            *(s32*)(p+0x26c)=0;
        } else if(dist<48.0f) {
            if((*(s32*)(p+0x26c)&1)==0) {
                *(u8*)(p+0x270)+=2;
                if(*(u8*)(p+0x270)>=200) ++*(s32*)(p+0x26c);
            } else {
                --*(u8*)(p+0x270);
                if(*(s32*)(p+0x26c)<6) {if(*(u8*)(p+0x270)<=80) ++*(s32*)(p+0x26c);}
                else if(*(u8*)(p+0x270)<=40) ++*(s32*)(p+0x26c);
            }
            if(*(s32*)(p+0x26c)>=8) *(s32*)(p+0x26c)=0;
        } else {
            if(*(u8*)(p+0x270)>2) *(u8*)(p+0x270)-=2;
            else *(u8*)(p+0x270)=0;
            *(s32*)(p+0x26c)=0;
        }
    }
    --*(s32*)(p+0x234);
    (((Jiji*)p)->*lbl_804AEC48[*(s32*)(p+0x258)])();
}

#pragma opt_propagation reset
struct JijiAnimEntry { u16 a, b; };
extern "C" void fn_801EE558(void* this_, JGeometry::TVec3<f32>* dir, f32* dist, s32 p);

extern f32 lbl_8054304C;


extern "C" void fn_8037C788(u8* this_) {
    f32 dist;
    JGeometry::TVec3<f32> pos;
    JGeometry::TVec3<f32> dir;
    *(s32*)(this_ + 0x230) = 0;
    *(u32*)(this_ + 0x250) = (*(u32*)(this_ + 0x90) & 0xfff) + 0x12b;
    *(u32*)(this_ + 0x254) = (*(u32*)(this_ + 0x90) >> 24) & 1;
    *(u32*)(this_ + 0x258) = (*(u32*)(this_ + 0x90) >> 16) & 0xff;
    *(u8*)(this_ + 0x271) = (*(u32*)(this_ + 0x90) >> 25) & 1;
    *(u32*)(this_ + 0x268) = (*(u32*)(this_ + 0x90) >> 12) & 3;
    *(u8*)(this_ + 0x272) = 1;
    *(s32*)(this_ + 0x26c) = 0;
    *(u8*)(this_ + 0x270) = 0;
    if (*(u8*)(this_ + 0x271) == 1) {
        *(s32*)(this_ + 0x230) = 2;
    }
    if (*(s32*)(this_ + 0x258) > 54) {
        *(s32*)(this_ + 0x258) = 0;
    }
    s32 k = *(s32*)(this_ + 0x258);
    if (k == 6 || k == 11 || k == 16 || k == 25) {
        *(f32*)(this_ + 0x60) = -16.0f;
        *(f32*)(this_ + 0x64) = -16.0f;
        *(f32*)(this_ + 0x68) = 16.0f;
        *(f32*)(this_ + 0x6c) = 8.0f;
    } else {
        *(f32*)(this_ + 0x60) = -8.0f;
        *(f32*)(this_ + 0x64) = -8.0f;
        *(f32*)(this_ + 0x68) = 8.0f;
        *(f32*)(this_ + 0x6c) = 8.0f;
    }
    *(f32*)(this_ + 0x3c) = 0.0f;
    *(f32*)(this_ + 0x40) = 0.0f;
    *(f32*)(this_ + 0x44) = 0.0f;
    if (*(u8*)(this_ + 0x271) == 1) {
        *(f32*)(this_ + 0x44) = 4.0f;
    }
    *(s32*)(this_ + 0x108) = 1;
    *(s32*)(this_ + 0x238) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x248) = 2;
    *(s32*)(this_ + 0x24c) = 0;
    if (*(s32*)(this_ + 0x24c) != 0) {
        *(s32*)(this_ + 0x24c) = *(s32*)(this_ + 0x24c) - 1;
    } else {
        *(s32*)(this_ + 0x24c) = 20;
        fn_801EE558(this_, &dir, &dist, 0);
        if (dist < 100.0f) {
            f32 rad = JMAAtan2Radian(-dir.x, -dir.y);
            u16 ang = (u16)(s32)(rad * lbl_8054304C);
            if (ang < 0x2000 || ang >= 0xe000) {
                *(s32*)(this_ + 0x248) = 3;
            } else if (ang >= 0x2000 && ang < 0x6000) {
                *(s32*)(this_ + 0x248) = 1;
            } else if (ang >= 0x6000 && ang <= 0xa000) {
                *(s32*)(this_ + 0x248) = 2;
            } else {
                *(s32*)(this_ + 0x248) = 0;
            }
        } else {
            *(s32*)(this_ + 0x248) = 2;
        }
    }
    *(s32*)(this_ + 0x244) = -1;
    *(u32*)(this_ + 0x25c) = ((const JijiAnimEntry*)&lbl_804753C0)[*(s32*)(this_ + 0x258)].a;
    *(u32*)(this_ + 0x260) = ((const JijiAnimEntry*)&lbl_804753C0)[*(s32*)(this_ + 0x258)].b;
    *(u8*)(this_ + 0x273) = 0;
    switch (*(u32*)(this_ + 0x258)) {
    case 1:
        *(s32*)(this_ + 0x234) = 20;
        *(s32*)(this_ + 0x23c) = 0;
        *(s32*)(this_ + 0x264) = 0;
        break;
    case 2:
        *(s32*)(this_ + 0x23c) = 3;
        *(s32*)(this_ + 0x234) = 3;
        *(s32*)(this_ + 0x264) = 6;
        break;
    case 3:
    case 22:
        *(s32*)(this_ + 0x23c) = 15;
        *(s32*)(this_ + 0x234) = 15;
        *(s32*)(this_ + 0x264) = 4;
        break;
    case 4:
    case 23:
        *(s32*)(this_ + 0x234) = 10;
        *(s32*)(this_ + 0x23c) = 0;
        *(s32*)(this_ + 0x264) = 3;
        break;
    case 5:
    case 24:
        *(s32*)(this_ + 0x23c) = 20;
        *(s32*)(this_ + 0x234) = 20;
        *(s32*)(this_ + 0x264) = 4;
        break;
    case 6:
    case 25:
        *(s32*)(this_ + 0x234) = 12;
        *(s32*)(this_ + 0x23c) = 0;
        *(s32*)(this_ + 0x264) = 5;
        break;
    case 7:
        *(s32*)(this_ + 0x23c) = 6;
        *(s32*)(this_ + 0x234) = 6;
        *(s32*)(this_ + 0x264) = 0;
        break;
    case 8:
        *(s32*)(this_ + 0x234) = 15;
        *(s32*)(this_ + 0x23c) = 0;
        *(s32*)(this_ + 0x264) = 0;
        break;
    case 9:
        *(s32*)(this_ + 0x23c) = 10;
        *(s32*)(this_ + 0x234) = 10;
        *(s32*)(this_ + 0x264) = 0;
        break;
    case 10:
        *(s32*)(this_ + 0x234) = 10;
        *(s32*)(this_ + 0x23c) = 0;
        *(s32*)(this_ + 0x264) = 3;
        break;
    case 11:
        *(s32*)(this_ + 0x23c) = 20;
        *(s32*)(this_ + 0x234) = 20;
        *(s32*)(this_ + 0x264) = 7;
        break;
    case 12:
        *(s32*)(this_ + 0x234) = 7;
        *(s32*)(this_ + 0x23c) = 0;
        *(s32*)(this_ + 0x264) = 3;
        break;
    case 13:
        *(s32*)(this_ + 0x234) = 12;
        *(s32*)(this_ + 0x23c) = 0;
        *(s32*)(this_ + 0x264) = 8;
        break;
    case 14:
        *(s32*)(this_ + 0x234) = 0;
        *(s32*)(this_ + 0x23c) = 0;
        *(s32*)(this_ + 0x264) = 6;
        break;
    case 15:
        *(s32*)(this_ + 0x234) = 7;
        *(s32*)(this_ + 0x23c) = 0;
        *(s32*)(this_ + 0x264) = 3;
        break;
    case 16:
        *(s32*)(this_ + 0x23c) = 15;
        *(s32*)(this_ + 0x234) = 15;
        *(s32*)(this_ + 0x264) = 0;
        break;
    case 17:
        *(s32*)(this_ + 0x23c) = 15;
        *(s32*)(this_ + 0x234) = 15;
        *(s32*)(this_ + 0x264) = 1;
        break;
    case 18:
        *(s32*)(this_ + 0x23c) = 15;
        *(s32*)(this_ + 0x234) = 15;
        *(s32*)(this_ + 0x264) = 0;
        break;
    case 19:
        *(s32*)(this_ + 0x23c) = 15;
        *(s32*)(this_ + 0x234) = 15;
        *(s32*)(this_ + 0x264) = 0;
        break;
    case 20:
        *(s32*)(this_ + 0x23c) = 15;
        *(s32*)(this_ + 0x234) = 15;
        *(s32*)(this_ + 0x264) = 0;
        break;
    case 21:
        *(s32*)(this_ + 0x234) = 0;
        *(s32*)(this_ + 0x23c) = 0;
        *(s32*)(this_ + 0x264) = 0;
        break;
    case 26:
        *(s32*)(this_ + 0x234) = 55;
        *(s32*)(this_ + 0x23c) = 0;
        *(s32*)(this_ + 0x264) = 0;
        break;
    case 27:
        *(s32*)(this_ + 0x234) = 40;
        *(s32*)(this_ + 0x23c) = 0;
        *(s32*)(this_ + 0x264) = 0;
        break;
    case 28:
        *(s32*)(this_ + 0x234) = 90;
        *(s32*)(this_ + 0x23c) = 0;
        *(s32*)(this_ + 0x264) = 2;
        break;
    case 29:
    case 30:
        *(s32*)(this_ + 0x23c) = 20;
        *(s32*)(this_ + 0x234) = 20;
        *(s32*)(this_ + 0x264) = 2;
        break;
    case 31:
        *(s32*)(this_ + 0x23c) = 20;
        *(s32*)(this_ + 0x234) = 20;
        *(s32*)(this_ + 0x264) = 2;
        break;
    case 32:
    case 33:
        *(s32*)(this_ + 0x234) = 20;
        *(s32*)(this_ + 0x23c) = 0;
        *(s32*)(this_ + 0x264) = 2;
        break;
    case 34:
        *(s32*)(this_ + 0x264) = 2;
        *(s32*)(this_ + 0x234) = 60;
        *(s32*)(this_ + 0x23c) = 0;
        break;
    case 35:
        *(s32*)(this_ + 0x234) = 0;
        *(s32*)(this_ + 0x23c) = 0;
        *(s32*)(this_ + 0x264) = 9;
        break;
    case 36:
    case 37:
    case 38:
    case 39:
    case 40:
    case 41:
        *(s32*)(this_ + 0x23c) = 0;
        *(s32*)(this_ + 0x234) = 0;
        *(s32*)(this_ + 0x264) = 10;
        break;
    case 42:
        *(s32*)(this_ + 0x23c) = 40;
        *(s32*)(this_ + 0x234) = 40;
        *(s32*)(this_ + 0x264) = 0;
        break;
    case 43:
        *(s32*)(this_ + 0x23c) = 18;
        *(s32*)(this_ + 0x234) = 18;
        *(s32*)(this_ + 0x264) = 0;
        break;
    case 44:
    case 45:
    case 46:
    case 47:
        *(s32*)(this_ + 0x23c) = 16;
        *(s32*)(this_ + 0x234) = 16;
        *(s32*)(this_ + 0x264) = 0;
        break;
    case 48:
        *(s32*)(this_ + 0x23c) = 10;
        *(s32*)(this_ + 0x234) = 10;
        *(s32*)(this_ + 0x264) = 0;
        break;
    case 49:
        *(s32*)(this_ + 0x23c) = 20;
        *(s32*)(this_ + 0x234) = 20;
        *(s32*)(this_ + 0x264) = 0;
        break;
    case 50:
    case 51:
    case 52:
    case 53:
        *(s32*)(this_ + 0x23c) = 16;
        *(s32*)(this_ + 0x234) = 16;
        *(s32*)(this_ + 0x264) = 2;
        break;
    default:
        *(s32*)(this_ + 0x23c) = 20;
        *(s32*)(this_ + 0x234) = 20;
        *(s32*)(this_ + 0x264) = 0;
        break;
    }
    if (*(AnimEffectRec**)(this_ + 0x274) != 0) {
        s32 room = *(s32*)(this_ + 4);
        pos = *(JGeometry::TVec3<f32>*)(this_ + 0xc);
        fn_80316E50(*(AnimEffectRec**)(this_ + 0x274), room, pos);
    }
    *(s32*)(this_ + 0x278) = 0;
}


#include "JSystem/JAudio/JASFakeMatchFSA.h"
