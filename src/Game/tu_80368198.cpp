

#include "types.h"
#include "Game/ItemBase.h"
#include "PowerPC_EABI_Support/Runtime/MWCPlusPlusLib.h"
#include "JSystem/JGeometry/Vec.h"
#include "dolphin/mtx.h"
extern "C" void fn_80458FF0(void*,u32,s32,s32);
extern "C" void fn_80458F9C(void*,int);
extern void* lbl_8053AF80;
extern "C" JGeometry::TVec3f* fn_8023E724(s32);
extern "C" s16 fn_8023CBC0(s32);
extern "C" void fn_80230498(s32,void*,u16,s32,s32,s32,s32);
extern "C" void fn_801CD950(f32*,f32,f32);
extern "C" void fn_8022FE80(s32,s32,s32,s32,s32);
extern u32 lbl_80474C68[];
extern "C" u8 fn_8038BD08(s32,u32,s32,void*,s32);
extern "C" void fn_80118454(void*);
extern "C" u8 fn_803865B8(s32);
extern "C" void fn_80388EEC(s32);


union EffWord {
    u32 w;
    u8 b[4];
};

struct EffArgs {
    u8 order[0x10];
    EffWord f10;
    EffWord f14;
    void* ptr;
    u8 b1c, b1d, b1e, b1f, b20, b21, b22, b23, b24, b25, b26;
    u8 pad0;
    u32 w28;
    u8 b2c, b2d, b2e;
    u8 pad1;
    u32 x30, x34, x38;
};

struct Sub8036C69C {
    virtual void v0(int);
    virtual void v1();
    virtual void v2(int);
};
struct Sub8036C0EC {
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24(int);
};
struct Unk8036C300 {
    void state0();
    void state1();
};
struct Vec3f {
    f32 x;
    f32 y;
    f32 z;
};
typedef void (Unk8036C300::*Unk8036C300Func)();
extern "C" void state0__11Unk8036C300Fv(void*);
extern "C" void state1__11Unk8036C300Fv(void*);
static Unk8036C300Func lbl_804AE070[2] = {
    &Unk8036C300::state0,
    &Unk8036C300::state1
};
extern char lbl_804AE088[];
extern char lbl_8049CC34[];
extern "C" void __dt__13Base_8010E074Fv(void* this_, int how);
extern "C" void fn_8036A65C(void* this_);
extern "C" void fn_801F0E34(void* self, u32 msg, s32 flag);
extern "C" void fn_8010DF58(void* this_);
extern "C" void fn_801F06F0(void* self, void* tbl, s32 idx, EffArgs* args, s32 n, f32 a, f32 b);
extern "C" void fn_803683AC(void* this_);
extern "C" void fn_8036A894(void* this_);
extern "C" void fn_8036AC58(void* this_, void* param);
extern "C" void fn_80368660(void* this_);
extern void* lbl_80474C48[];
extern u8 lbl_80474E48[];
extern "C" void fn_801EF830(s32 idx, void* pos, u8* p3, u32 mask, u8* p5, u32 p6, u8* p7);
extern "C" void fn_802F86CC(void*, void*, void*, s32, f32, f32, void*);
extern "C" void fn_803075AC(void*, s32, void*, s32, s32, s32, s32, s32, s32, s32);
class SobResMgr {
public:
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void* vf18(u32 type, const char* name);
};
extern void* lbl_8053AB10;
extern const f32 lbl_80542C58;
extern const f32 lbl_80542C6C;
extern f32 lbl_80542CC0;
extern "C" void PSMTXTrans(f32 m[3][4], f32 x, f32 y, f32 z);
extern "C" void fn_802F745C(void* mgr, f32* pos, void* tgt, EffArgs* args);

extern char lbl_80474C38[];
struct CutsceneTable8036 {
u8 pad00[0x30]; s32 messages[9]; s32 animStart[3]; u8 pad60[0x18];
s32 offsets[5]; u8 pad8c[0x3c]; u16 emitters[8];
u16 d8[8], e8[8], f8[8], f108[8], f118[8], f128[8];
};
static inline u16 cutsceneTable16(const u16* __restrict table, int index) { return table[index]; }
static inline s32 cutsceneTable32(const s32* __restrict table, int index) { return table[index]; }
extern f32 lbl_80542CA4;
extern f32 lbl_80542CC4;
extern f32 lbl_80542CC8;
extern "C" void fn_8010F668(Mtx m, Vec3f* v, f32 f);
struct Obj8036C750 {
    u8 pad0[0x294];
    s32 a294[5];
    JGeometry::TVec3<f32> trail[6];
    u8 pad2f0[8];
    s32 a2f8[6];
    u8 pad310[0x35c - 0x310];
    s32 a35c[7];
    s32 a378[3];
    s32 a384[5];
    s32 w398;
    s32 a39c[6];
    s32 a3b4[2];
    s32 a3bc[6];
    s32 a3d4[6];
    s32 a3ec[5];
    s32 a400[5];
};
extern "C" void* __nw__FUl(u32 size);
extern "C" void __ct__10J2DPictureFPC7ResTIMG(void* this_, void* res);
extern "C" void fn_8013B490(void* p);
extern "C" void* fn_8011921C(void);
extern "C" void fn_801183BC(void);
extern void* lbl_8053AAF8;
extern char* lbl_8053A1C8;
extern void* sManager__8JUTVideo;
extern f32 lbl_80542C64;
extern const f32 lbl_80542C68;
extern const f32 lbl_80542C7C;
extern const f32 lbl_80542C80;
extern const f32 lbl_80542C84;
extern const f32 lbl_80542C88;
extern f32 lbl_80542CB4;
#pragma opt_dead_assignments off
extern "C" void fn_80368198(Sub8036C0EC* this_) {
    char* self = (char*)this_;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    void* mgr;
    void* res;
    void* pic;
    void* render;

    if (*(u8*)(self + 0x270) != 0) {
        if (*(s32*)(self + 0x274) < 0x80) {
            *(f32*)(self + 0x290) = *(f32*)(self + 0x290) - 2.0f;
        } else {
            *(f32*)(self + 0x290) = *(f32*)(self + 0x290) + 2.0f;
        }
        if (*(f32*)(self + 0x290) >= 255.0f) {
            *(f32*)(self + 0x290) = 255.0f;
        } else if (*(f32*)(self + 0x290) < 0.0f) {
            *(f32*)(self + 0x290) = 0.0f;
        }
        if (*(void**)(self + 0x314) == 0) {
            mgr = *(void**)((char*)lbl_8053AAF8 + 0xa4);
            res = ((void* (*)(void*, u32, char*))(*(void***)mgr)[6])(mgr, 0x3f3f3f3f, lbl_8053A1C8);
            pic = __nw__FUl(0x168);
            if (pic != 0) {
                __ct__10J2DPictureFPC7ResTIMG(pic, res);
            }
            *(void**)(self + 0x314) = pic;
        }
        fn_8013B490(lbl_8053AB10);
        a = 0;
        b = 0;
        c = -1;
        d = -1;
        ((void (*)(void*, s32*, s32*))(*(void***)*(void**)(self + 0x314))[76])(*(void**)(self + 0x314), &d, &b);
        ((void (*)(void*, s32))(*(void***)*(void**)(self + 0x314))[9])(*(void**)(self + 0x314), (s32)*(f32*)(self + 0x290));
        render = *(void**)((char*)sManager__8JUTVideo + 4);
        ((void (*)(void*, s32, s32, s32, f32, f32, f32, f32))(*(void***)*(void**)(self + 0x314))[59])(
            *(void**)(self + 0x314), 0, 0, 0, 0.0f, 0.0f, (f32)*(u16*)((char*)render + 4), (f32)*(u16*)((char*)render + 6));
        if (*(s32*)(self + 0x274) == 0x80) {
            *(u8*)(self + 0x234) = 0;
            *(u8*)(self + 0x236) = 1;
            *(s32*)(self + 0x24c) = 1;
            fn_8036A65C(this_);
        } else if (*(s32*)(self + 0x274) == 0) {
            *(u8*)(self + 0x270) = 0;
            this_->v24(0x26);
            fn_8011921C();
            fn_801183BC();
        }
    }
}

#pragma opt_common_subs reset
extern "C" void fn_803683AC(void* this_) {
    const s32* __restrict first;
    const s32* __restrict second;
    s32 i;
    char* self = (char*)this_;
    char* tbl = lbl_80474C38;
    DrawRec rec;
    JGeometry::TVec3<f32> saved(*(Vec*)(self + 0xc));
    if (*(s32*)(self + 0x260) != 0) {
        --*(s32*)(self + 0x260);
    }
    if (*(s32*)(self + 0x260) == 0) {
        ++*(s32*)(self + 0x264);
        if (*(s32*)(self + 0x264) >= 6) *(s32*)(self + 0x264) = 0;
        *(s32*)(self + 0x260) = 1;
    }
    first = (s32*)(tbl + 0x1b4);
    second = (s32*)(tbl + 0x1cc);
    for (i = 0; i < 6; i++, first++, second++) {
        s32 state = ((Obj8036C750*)self)->a2f8[i];
        if (state == 0) {
            *(JGeometry::TVec3<f32>*)(self + 0xc) = ((Obj8036C750*)self)->trail[i];
            ((u8*)&rec.w10)[3] = 0xff;
            fn_801F06F0(self, tbl + 0x210, *first + 8, (EffArgs*)&rec, 7, 1.0f, 1.0f);
        } else if (state != 1 && state != 4) {
            *(JGeometry::TVec3<f32>*)(self + 0xc) = ((Obj8036C750*)self)->trail[i];
            ((u8*)&rec.w10)[3] = 0xff;
            fn_801F06F0(self, tbl + 0x224, *(s32*)(self + 0x264) + *second, (EffArgs*)&rec, -1, 1.0f, 1.0f);
            f32 z = ((Obj8036C750*)self)->trail[i].z;
            if (z < lbl_80542C68) ((u8*)&rec.w10)[3] = 255 - (s32)z;
            else ((u8*)&rec.w10)[3] = 0;
            s32 id = *(s32*)(self + 0x264) + *second;
            if (*(u32*)(self + 0x138) == 0) {
                fn_801EF830(*(s32*)(self + 4), self + 0xc, (u8*)&rec, 0x407, (u8*)(tbl + 0x224), id, 0);
            }
        }
    }
    *(JGeometry::TVec3<f32>*)(self + 0xc) = saved;
}
extern const f32 lbl_80542C78;
extern "C" void fn_801F06F0(void* self, void* tbl, s32 idx, EffArgs* args, s32 n, f32 a, f32 b);
extern "C" void fn_8013CB44(void* obj, Vec3f* v, s32 a, s32 b, s32 c);
extern "C" void fn_80368660(void* this_) {
    char* base=lbl_80474C38;
    Vec3f* pos;
    char* objects;
    char* vertices;
    s32* tableA;
    s32* tableB;
    s32 i;
    char* self = (char*)this_;
    void* res;
    void* mgr;
    Vec3f* vtx;
    EffArgs args;
    s32 idx;
    s32 st;

    args.f10.w = -1;
    args.f14.w = -1;
    for (u8 k=0;k<16;k++) args.order[k]=k;
    args.f10.w = -1;
    args.f14.w = 0;
    args.ptr = 0;
    args.b1c = 0;
    args.b1d = 0;
    args.b1e = 0;
    args.b1f = 1;
    args.b20 = 1;
    args.b21 = 0;
    args.b22 = 0;
    args.b23 = 0;
    args.b24 = 0;
    args.b25 = 0;
    args.b26 = 1;
    args.w28 = 3;
    args.b2c = 1;
    args.b2d = 0;
    args.b2e = 0;
    args.x30 = -1;
    args.x34 = 0;
    args.x38 = 2;

    if (*(s32*)(self + 0x23c) == 5 &&
        (*(u8*)(self + 0x270) != 1 || *(s32*)(self + 0x274) >= 0x80) &&
        *(s32*)(self + 0x25c) >= 0) {
        if (*(s32*)(self + 0x260) != 0) {
            *(s32*)(self + 0x260) -= 1;
        }
        st = *(s32*)(self + 0x240);
        if (st < 0x1c) {
            if (*(s32*)(self + 0x260) == 0) {
                *(s32*)(self + 0x260) = 1;
                *(s32*)(self + 0x264) += 1;
                if (*(s32*)(self + 0x264) >= 6) {
                    *(s32*)(self + 0x264) = 0;
                }
            }
        } else if ((u32)(st - 0x1c) <= 1 || st == 0x1e) {
            if (st == 0x1c) {
                *(s32*)(self + 0x264) = 8;
            } else if (st == 0x1d) {
                *(s32*)(self + 0x264) = 8;
                *(s32*)(self + 0x260) = 0x1e;
            } else if (st == 0x1e) {
                if (*(s32*)(self + 0x260) == 0) {
                    if (*(s32*)(self + 0x264) == 8) {
                        *(s32*)(self + 0x264) = 10;
                        *(s32*)(self + 0x260) = 0x1e;
                    } else if (*(s32*)(self + 0x264) == 10) {
                        *(s32*)(self + 0x264) = 0xb;
                        *(s32*)(self + 0x260) = 10;
                    } else {
                        *(s32*)(self + 0x260) = 9;
                        *(s32*)(self + 0x264) += 1;
                        if (*(s32*)(self + 0x264) >= 6) {
                            *(s32*)(self + 0x264) = 0;
                        }
                    }
                }
            } else {
                if (*(s32*)(self+0x260)==0) {
                    *(s32*)(self+0x260)=9;
                    *(s32*)(self+0x264)+=1;
                    if (*(s32*)(self+0x264)>=6) *(s32*)(self+0x264)=0;
                }
            }
        } else if (st == 0x22 || st == 0x21) {
            if (*(s32*)(self + 0x260) == 0) {
                *(s32*)(self + 0x260) = 9;
                *(s32*)(self + 0x264) += 1;
                if (*(s32*)(self + 0x264) >= 6) {
                    *(s32*)(self + 0x264) = 0;
                }
            }
        } else if (st == 0x23) {
            st = *(s32*)(self + 0x258);
            if (st >= 0x50) {
                if (*(s32*)(self + 0x260) == 0) {
                    *(s32*)(self + 0x260) = 9;
                    *(s32*)(self + 0x264) += 1;
                    if (*(s32*)(self + 0x264) >= 6) *(s32*)(self + 0x264) = 0;
                }
            } else if (st >= 0x46) {
                *(s32*)(self+0x264)=11;
            } else if (st >= 0x28) {
                *(s32*)(self+0x264)=10;
            } else {
                *(s32*)(self+0x264)=8;
            }
        }

        JGeometry::TVec3<f32> saved(*(Vec*)(self + 0xc));
        objects=self;
        vertices=self;
        tableA=(s32*)(base+0x1a0);
        tableB=(s32*)(base+0x18c);
        for (i = 0; i < 5; i++,objects+=4,vertices+=12,tableA++,tableB++) {
            st = *(s32*)(self + 0x240);
            if (st < 0x1c) {
                if (*(s32*)(objects+0x294) == 0) {
                    *(JGeometry::TVec3<f32>*)(self+0xc)=*(JGeometry::TVec3<f32>*)(vertices+0x2a8);
                    int frameA=*tableA;
                    *(f32*)(self+0x14)=lbl_80542C78;
                    fn_801F06F0(self, base + 0x224,
                                frameA + *(s32*)(self + 0x264),
                                &args, 7, 1.0f, 1.0f);
                    if (*(void**)(objects+0x3bc) != 0) {
                        ((void (*)(void*,JGeometry::TVec3<f32>,s32,s32,s32))fn_8013CB44)(*(void**)(objects+0x3bc), *(JGeometry::TVec3<f32>*)(vertices+0x2a8) + JGeometry::TVec3<f32>(0.0f,0.0f,20.0f), 0, -1, 1);
                    }
                    if (*(void**)(objects+0x3d4) != 0) {
                        ((void (*)(void*,JGeometry::TVec3<f32>,s32,s32,s32))fn_8013CB44)(*(void**)(objects+0x3d4), *(JGeometry::TVec3<f32>*)(vertices+0x2a8) + JGeometry::TVec3<f32>(0.0f,0.0f,20.0f), 0, -1, 1);
                    }
                }
            } else if(st<0x21) {
                *(JGeometry::TVec3<f32>*)(self+0xc)=*(JGeometry::TVec3<f32>*)(vertices+0x2a8);
                if (*(s32*)(self + 0x240) >= 0x1e && *(s32*)(self + 0x240) < 0x21) {
                    if (*(s32*)(self + 0x24c) < 0xc0) {
                        s32 entry=*(s32*)(self+0x264)+*tableB;
                        if(*(void**)(self+0x138)==0) {
                        fn_801EF830(*(s32*)(self + 0x4), self+0xc, (u8*)&args, 7, (u8*)(base + 0x210),
                                    entry, 0);
                        }
                    }
                    u8 alpha=0xff-*(s32*)(self+0x24c);
                    args.f10.b[0] = 0xff;
                    args.f10.b[1] = 0xff;
                    args.f10.b[2] = 0xff;
                    args.f10.b[3] = alpha;
                    idx = *(s32*)(self + 0x264) + *tableB;
                    if (*(s32*)(self + 0x4) < 8) {
                        res = (*(SobResMgr**)((char*)lbl_8053AAF8+0xa4))->vf18(0x534F4220,base+0x210);
                        fn_802F86CC(*(void**)((char*)lbl_8053AB10 + 0x20), pos, res, idx, lbl_80542C58, lbl_80542C58, &args);
                    }
                    fn_803075AC(*(void**)(self + 0x198), *(s32*)(self + 0x4), self+0xc,
                                *(s32*)(self + 0x264) + *tableB, 0, 1, -1, 0, 0, 0);
                } else {
                    fn_801F06F0(self, base + 0x210,
                                *(s32*)(self + 0x264) + *tableB,
                                &args, 7, 1.0f, 1.0f);
                }
            } else {
                *(f32*)(self+0xc)=*(f32*)(vertices+0x2a8);
                int frameB=*tableB;
                *(f32*)(self+0x10)=*(f32*)(vertices+0x2ac);
                *(f32*)(self+0x14)=*(f32*)(vertices+0x2b0);
                fn_801F06F0(self,base+0x210,frameB+*(s32*)(self+0x264),&args,7,lbl_80542C58,lbl_80542C58);
            }
        }
        *(JGeometry::TVec3<f32>*)(self+0xc)=saved;
    }
}

extern char lbl_80529DEC[];
extern char lbl_8050EC80[];
extern void* lbl_8053AD30;
extern "C" void fn_8010DF78(void* p);
extern "C" void* fn_8016A3AC(void);
extern "C" void* fn_8013CC50(s32 room, void* pos, f32 f, s32 a, s32 b, s32 c, s32 d, s32 e, s32 g);
static inline void* cutsceneEmitter(s32 room, void* pos, s32 id, s32 a, s32 b, s32 c, s32 d, s32 e, f32 scale) {
    return fn_8013CC50(room,pos,scale,id,a,b,c,d,e);
}
extern "C" s32 fn_80309C4C(void* p, s32 a, s32 b);
extern "C" void fn_80387494(s32 a);
extern "C" void fn_803676CC(void* = 0);
extern "C" void detach__5ActorFv(void* self);
extern "C" void fn_8030C210(void* eff, Vec3f* v);
extern f32 lbl_80542CA0;
extern "C" void fn_801D1C18(void*);
extern "C" void fn_8036AA60(char*);
static inline void cutsceneCameraBox(const f32 x1,const f32 y1,const f32 x2,const f32 y2) {
    u8* eff=*(u8**)((u8*)lbl_8053AB10+0x24);
    if(!eff[0x7f5]) {
        eff[0x7f4]=1;
        *(s32*)(eff+0x7f8)=5;
        *(f32*)(eff+0x808)=x1;
        *(f32*)(eff+0x80c)=y1;
        *(f32*)(eff+0x810)=x2;
        *(f32*)(eff+0x814)=y2;
        eff[0x7f6]=0;
    }
}

static inline s32 cutsceneFlag(s32 idx,s32 bit) {
    if(idx<0 || idx>7)return 0;
    if(bit<0 || bit>3)return 0;
    u32 mask=1 << (bit+idx*4);
    return (mask & *(u32*)(lbl_8050EC80+*(s32*)(lbl_8050EC80+0x10)*200+0x28))!=0;
}

extern "C" void* fn_80119DD0(void);
extern "C" void fn_80119958(void);
extern "C" void fn_80119998(void*,s32,s32,s32,s32,s32,s32,s32);
extern "C" void Gol2_SetField_0x2f4(void*,s32);
extern "C" void* fn_8013C824(void);
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void* mgr, void* emitter);
extern f32 lbl_80542CA8;
struct Rgb8036 {
    u8 r, g, b;
};
extern const f32 lbl_80542C5C;
extern const f32 lbl_80542C60;
extern const f32 lbl_80542C8C;
extern const f32 lbl_80542C90;
extern const f32 lbl_80542C94;
extern const f32 lbl_80542C98;
extern const f32 lbl_80542C9C;
extern const f32 lbl_80542CAC;
extern const f32 lbl_80542CB0;

void Unk8036C300::state1() {
    typedef void* (*EmitFn)(s32, const JGeometry::TVec3f&, f32, s32, s32, s32, s32, s32, s32);
    Vec3f v;
    char* self = (char*)this;
    char* tbl = lbl_80474C38;
    if (*(s32*)(self + 0x258) != 0) {
        *(s32*)(self + 0x258) = *(s32*)(self + 0x258) - 1;
    }
    if (*(s32*)(self + 0x26c) != 0) {
        *(s32*)(self + 0x26c) = *(s32*)(self + 0x26c) - 1;
        if (*(s32*)(self + 0x26c) == 0) {
            char* em = *(char**)(self + 0x398);
            if (em != 0) {
                *(u32*)(em + 0xf4) |= 1;
                *(s32*)(em + 0x24) = 1;
                *(s32*)(self + 0x398) = 0;
            }
        }
    }
    if (*(s32*)(self + 0x274) != 0) {
        *(s32*)(self + 0x274) = *(s32*)(self + 0x274) - 1;
    }
    if (*(s32*)(self + 0x28c) >= 0) {
        *(s32*)(self + 0x28c) = *(s32*)(self + 0x28c) + 1;
        if (*(s32*)(self + 0x28c) >= 0x96 && *(f32*)(self + 0x288) < lbl_80542C68) {
            *(f32*)(self + 0x288) = *(f32*)(self + 0x288) + lbl_80542C58;
            if (*(f32*)(self + 0x288) >= lbl_80542C68) {
                *(f32*)(self + 0x288) = lbl_80542C68;
            }
            if (*(u8**)(self + 0x39c) != 0) (*(u8**)(self + 0x39c))[0xbb] = (s32)*(f32*)(self + 0x288);
            if (*(u8**)(self + 0x3a0) != 0) (*(u8**)(self + 0x3a0))[0xbb] = (s32)*(f32*)(self + 0x288);
            if (*(u8**)(self + 0x3a4) != 0) (*(u8**)(self + 0x3a4))[0xbb] = (s32)*(f32*)(self + 0x288);
            if (*(u8**)(self + 0x3a8) != 0) (*(u8**)(self + 0x3a8))[0xbb] = (s32)*(f32*)(self + 0x288);
            if (*(u8**)(self + 0x3ac) != 0) (*(u8**)(self + 0x3ac))[0xbb] = (s32)*(f32*)(self + 0x288);
            if (*(u8**)(self + 0x3b0) != 0) (*(u8**)(self + 0x3b0))[0xbb] = (s32)*(f32*)(self + 0x288);
        }
    }
    fn_8010DF78(self);
    {
        s32 idx = *(s32*)(lbl_80529DEC + 0x118);
        s32 bit = *(s32*)(lbl_80529DEC + 0x11c);
        s32 vis = cutsceneFlag(idx, bit);
        if (vis && *(u8*)(self + 0x270) == 0) {
            s32 st = *(s32*)(self + 0x240);
            if (st >= 0x18 && st <= 0x23) {
                *(u8*)((char*)lbl_8053AAF8 + 0x85) = 2;
                if ((void*)fn_80309C4C(lbl_8053AD30, 0x1000, -1) != 0) {
                    *(u8*)(self + 0x270) = 1;
                    *(f32*)(self + 0x290) = lbl_80542C6C;
                    fn_80387494(0);
                    fn_80119DD0();
                    fn_80119958();
                    *(s32*)(self + 0x274) = 0x100;
                }
            }
        }
    }
    if (*(s32*)(self + 0x240) <= 0x18 && ((u8*)fn_8016A3AC())[0x1ef] == 0 && *(void**)(self + 0x398) == 0) {
        *(void**)(self + 0x398) = fn_8013CC50(*(u32*)(self + 4), self + 0xc, lbl_80542C58, 0x54c, 0, 1, 0, 0, 1);
    }
    if (*(s32*)(self + 0x240) >= 0x15 && *(s32*)(self + 0x240) != 0x26) {
        if (((*(s32*)(self + 0x240) >= 0x16 && *(s32*)(self + 0x240) < 0x1a) ||
             (*(s32*)(self + 0x240) >= 0x1c && *(s32*)(self + 0x240) < 0x24)) &&
            (*(u8*)(self + 0x270) == 0 || *(s32*)(self + 0x274) >= 0x80)) {
            u8* p = *(u8**)((char*)lbl_8053AB10 + 0x30);
            if (p[0x284] == 0) {
                p[0x284] = 1;
                *(f32*)(p + 0x28c) = lbl_80542C7C;
            }
        }
        v = *(Vec3f*)(self + 0xc);
        f32 oldY;
        f32 bottom;
        bottom = *(f32*)(self + 0x28);
        oldY = *(f32*)(self + 0x10);
        v.y += lbl_80542C80 + ((bottom - oldY) - lbl_80542C84);
        if (*(s32*)(self + 0x240) >= 0x1c) {
            if (*(s32*)(self + 0x240) <= 0x20) {
                v.y = v.y + lbl_80542C80;
            } else {
                v.y = v.y + lbl_80542C84;
            }
        }
        if (*(s32*)(self + 0x240) >= 0x16) {
            u8* eff = *(u8**)((char*)lbl_8053AB10 + 0x24);
            f32 high;
            f32 low;
            f32 y;
            f32 x;
            y = v.y;
            x = v.x;
            high = lbl_80542C88 + y;
            low = y - lbl_80542C88;
            eff[0x179] = 1;
            cutsceneCameraBox(x, low, x, high);
        } else {
            fn_8030C210(*(void**)((char*)lbl_8053AB10 + 0x24), &v);
            {
                u8* eff = *(u8**)((char*)lbl_8053AB10 + 0x24);
                if (eff[0x7f5] == 0) {
                    eff[0x7f4] = 1;
                    *(s32*)(eff + 0x7f8) = 4;
                    *(f32*)(eff + 0x7fc) = v.x;
                    *(f32*)(eff + 0x800) = v.y;
                    *(f32*)(eff + 0x804) = v.z;
                    eff[0x7f6] = 0;
                }
            }
        }
    }
    if (*(u8*)(self + 0x270) != 1) {
        switch (*(s32*)(self + 0x240)) {
        case 0x13:
            fn_80458FF0(lbl_8053AF80, 0x100001b, 0, 0);
            ((Sub8036C0EC*)this)->v24(0x14);
            break;
        case 0x16:
            for (s32 i = 0; i < 4; i++) {
                JGeometry::TVec3f loopPos = *fn_8023E724(i);
                u16 angle = fn_8023CBC0(i);
                fn_80230498(i, &loopPos, angle, 0, -128, -128, 1);
            }
            if (*(s32*)((char*)fn_8011921C() + 8) == 0x1b8) fn_80458F9C(lbl_8053AF80, 60);
            break;
        case 0x17:
            fn_801CD950((f32*)(self + 0x284), lbl_80542C8C, lbl_80542C90);
            fn_801CD950((f32*)(self + 0x27c), lbl_80542C94, lbl_80542C98);
            *(f32*)(self + 0x10) -= *(f32*)(self + 0x27c);
            if (*(f32*)(self + 0x10) <= *(f32*)(self + 0x28) - lbl_80542C9C) {
                *(f32*)(self + 0x10) = *(f32*)(self + 0x28) - lbl_80542C9C;
            }
            *(s32*)(self + 0x24c) += 2;
            if (*(s32*)(self + 0x24c) >= 225) *(s32*)(self + 0x24c) = 225;
            break;
        case 0x18:
            *(s32*)(self + 0x24c) = 225;
            if (!*((u8*)fn_8011921C() + 1)) fn_801CD950((f32*)(self + 0x284), lbl_80542C6C, lbl_80542CA0);
            fn_8022FE80(0, *(s32*)(self + 4), *(s32*)(self + 0x198), 1, 0);
            if (fn_803865B8(0)) {
                fn_80388EEC(0);
                ((Sub8036C0EC*)this)->v24(0x19);
                *(s32*)(self + 0x25c) = 0;
                *(s32*)(self + 0x260) = 0;
                *(s32*)(self + 0x264) = 0;
            }
            break;
        case 0x19: {
            char* objects = self;
            char* vertices = self;
            const u8* color = (const u8*)(tbl + 0x14c);
            const u16* idA = (const u16*)(tbl + 0x134);
            const u16* idB = (const u16*)(tbl + 0x140);
            for (s32 i = 0; i < 5; i++, vertices += 0xc, color += 3, idA++, idB++, objects += 4) {
                if (*(s32*)(objects + 0x294) != 0) {
                    *(s32*)(objects + 0x294) -= 1;
                    if (*(s32*)(objects + 0x294) == 0) {
                        *(void**)(objects + 0x3bc) = ((EmitFn)fn_8013CC50)(*(u32*)(self + 4), *(JGeometry::TVec3f*)(vertices + 0x2a8) + JGeometry::TVec3f(lbl_80542C6C, lbl_80542C6C, lbl_80542C78), lbl_80542C58, 0x32c, 0, -1, 0, 0, 1);
                        *(void**)(objects + 0x3d4) = ((EmitFn)fn_8013CC50)(*(u32*)(self + 4), *(JGeometry::TVec3f*)(vertices + 0x2a8) + JGeometry::TVec3f(lbl_80542C6C, lbl_80542C6C, lbl_80542C78), lbl_80542C58, 0x184, 0, -1, 0, 0, 1);
                        u8* e = *(u8**)(objects + 0x3bc);
                        if (e != 0) {
                            e[0xbc] = color[0];
                            e[0xbd] = color[1];
                            e[0xbe] = color[2];
                        }
                    }
                }
                if (*(s32*)(objects + 0x294) == 0x28) {
                    *(void**)(objects + 0x3ec) = ((EmitFn)fn_8013CC50)(*(u32*)(self + 4), *(JGeometry::TVec3f*)(vertices + 0x2a8) + JGeometry::TVec3f(lbl_80542C6C, lbl_80542C6C, lbl_80542C78), lbl_80542C58, *idA, 1, 0, 0, 0, 1);
                    *(void**)(objects + 0x400) = ((EmitFn)fn_8013CC50)(*(u32*)(self + 4), *(JGeometry::TVec3f*)(vertices + 0x2a8) + JGeometry::TVec3f(lbl_80542C6C, lbl_80542C6C, lbl_80542C78), lbl_80542C58, *idB, 1, 0, 0, 0, 1);
                    fn_801F0E34(self, 0x400d9, 0);
                }
            }
            if ((*(s32*)(self + 0x294) | *(s32*)(self + 0x298) | *(s32*)(self + 0x29c) | *(s32*)(self + 0x2a0) | *(s32*)(self + 0x2a4)) == 0) {
                fn_8011921C();
                fn_801183BC();
            }
            break;
        }
        case 0x1c:
            if (*(s32*)(self + 0x258) == 1) {
                fn_80118454(fn_8011921C());
            } else if (*(s32*)(self + 0x258) == 0) {
                ((Sub8036C0EC*)this)->v24(0x1d);
            }
            break;
        case 0x1d:
            if (*(s32*)(self + 0x258) == 0x32) {
                u8* mode = *(u8**)((char*)sManager__8JUTVideo + 4);
                const s32 height = *(u16*)(mode + 6);
                const s32 width = *(u16*)(mode + 4);
                v.x = (f32)width * lbl_80542CA4;
                v.y = (f32)height * lbl_80542CA4;
                v.z = lbl_80542C6C;
                v.y += lbl_80542CA8;
                fn_8022FE80(0, *(s32*)(self + 4), *(s32*)(self + 0x198), 1, 0);
                s32 room = *(s32*)(self + 4);
                JGeometry::TVec3f spawnPos = *(JGeometry::TVec3f*)&v;
                fn_8038BD08(0, 0x848, room, &spawnPos, 0x62);
            } else if (*(s32*)(self + 0x258) == 0x31) {
                fn_8022FE80(0, *(s32*)(self + 4), *(s32*)(self + 0x198), 1, 0);
                if (!fn_803865B8(0)) {
                    *(s32*)(self + 0x258) += 1;
                } else {
                    fn_80388EEC(0);
                }
            } else if (*(s32*)(self + 0x258) != 0xf && *(s32*)(self + 0x258) == 0) {
                ((Sub8036C0EC*)this)->v24(0x1e);
            }
            break;
        case 0x1e:
            if (*(f32*)(self + 0x250) < lbl_80542CAC) {
                *(f32*)(self + 0x250) += lbl_80542C58;
            } else {
                ((Sub8036C0EC*)this)->v24(0x1f);
            }
            *(s32*)(self + 0x24c) = (s32)*(f32*)(self + 0x250);
            if (*(s32*)(self + 0x24c) >= 0x100) *(s32*)(self + 0x24c) = 0xff;
            Gol2_SetField_0x2f4(*(void**)(self + 0x2f4), (u8)(0xff - *(s32*)(self + 0x24c)));
            break;
        case 0x1f:
            if (*(s32*)(self + 0x258) != 0) {
                if (*(s32*)(self + 0x258) == 1) {
                    u8* mode = *(u8**)((char*)sManager__8JUTVideo + 4);
                    const s32 height = *(u16*)(mode + 6);
                    const s32 width = *(u16*)(mode + 4);
                    v.x = (f32)width * lbl_80542CA4;
                    v.y = (f32)height * lbl_80542CA4;
                    v.z = lbl_80542C6C;
                    v.y += lbl_80542CA8;
                    fn_8022FE80(0, *(s32*)(self + 4), *(s32*)(self + 0x198), 1, 0);
                    s32 room = *(s32*)(self + 4);
                    JGeometry::TVec3f spawnPos = *(JGeometry::TVec3f*)&v;
                    fn_8038BD08(0, cutsceneTable32((s32*)(tbl + 0x30), *(s32*)(self + 0x268)), room, &spawnPos, 0x62);
                    *(s32*)(self + 0x268) += 1;
                }
            } else {
                fn_8022FE80(0, *(s32*)(self + 4), *(s32*)(self + 0x198), 1, 0);
                if (fn_803865B8(0)) {
                    fn_80388EEC(0);
                    ((Sub8036C0EC*)this)->v24(0x20);
                }
            }
            break;
        case 0x20:
            if (*(s32*)(self + 0x258) == 0) ((Sub8036C0EC*)this)->v24(0x21);
            break;
        case 0x21:
            if (*(u8*)fn_80119DD0() == 0) ((Sub8036C0EC*)this)->v24(0x22);
            break;
        case 0x22:
            fn_8022FE80(0, *(s32*)(self + 4), *(s32*)(self + 0x198), 1, 0);
            if (fn_803865B8(0)) {
                fn_80388EEC(0);
                ((Sub8036C0EC*)this)->v24(0x23);
            }
            break;
        case 0x23:
            if (*(s32*)(self + 0x258) != 0) {
                if (*(s32*)(self + 0x258) == 1) {
                    u8* mode = *(u8**)((char*)sManager__8JUTVideo + 4);
                    const s32 height = *(u16*)(mode + 6);
                    const s32 width = *(u16*)(mode + 4);
                    v.x = (f32)width * lbl_80542CA4;
                    v.y = (f32)height * lbl_80542CA4;
                    v.z = lbl_80542C6C;
                    v.y += lbl_80542CA8;
                    fn_8022FE80(0, *(s32*)(self + 4), *(s32*)(self + 0x198), 1, 0);
                    s32 room = *(s32*)(self + 4);
                    JGeometry::TVec3f spawnPos = *(JGeometry::TVec3f*)&v;
                    fn_8038BD08(0, cutsceneTable32((s32*)(tbl + 0x30), *(s32*)(self + 0x268)), room, &spawnPos, 0x62);
                    *(s32*)(self + 0x268) += 1;
                }
            } else {
                fn_8022FE80(0, *(s32*)(self + 4), *(s32*)(self + 0x198), 1, 0);
                if (fn_803865B8(0)) {
                    fn_80388EEC(0);
                    ((Sub8036C0EC*)this)->v24(0x24);
                }
            }
            break;
        case 0x24: {
            char* objects = self;
            char* vertices = self;
            const s32* timing = (const s32*)(tbl + 0x15c);
            const u16* idA = (const u16*)(tbl + 0x1e4);
            const u16* idB = (const u16*)(tbl + 0x1f0);
            const u8* color = (const u8*)(tbl + 0x1fc);
            for (s32 i = 0; i < 6; i++, objects += 4, vertices += 0xc, idA++, idB++, color += 3, timing++) {
                if (*(s32*)(self + 0x258) == *timing) {
                    *(s32*)(objects + 0x2f8) = 1;
                    JGeometry::TVec3f pos = *(JGeometry::TVec3f*)(vertices + 0x2a8);
                    pos.z += lbl_80542C5C;
                    fn_8013CC50(*(u32*)(self + 4), &pos, lbl_80542C58, *idA, 0, 0, 0, 0, 1);
                    pos.z += lbl_80542C60;
                    fn_8013CC50(*(u32*)(self + 4), &pos, lbl_80542C58, *idB, 0, 0, 0, 0, 1);
                    fn_801F0E34(self, 0x400d9, 0);
                    *(f32*)(vertices + 0x2b0) = lbl_80542C80;
                } else if (*(s32*)(self + 0x258) == *timing - 0x28) {
                    *(s32*)(objects + 0x2f8) = 2;
                    *(void**)(objects + 0x3bc) = fn_8013CC50(*(u32*)(self + 4), vertices + 0x2a8, lbl_80542C58, 0x32c, 0, -1, 0, 0, 1);
                    *(void**)(objects + 0x3d4) = fn_8013CC50(*(u32*)(self + 4), vertices + 0x2a8, lbl_80542C58, 0x184, 0, -1, 0, 0, 1);
                    u8* e = *(u8**)(objects + 0x3bc);
                    if (e != 0) {
                        e[0xbc] = color[0];
                        e[0xbd] = color[1];
                        e[0xbe] = color[2];
                    }
                }
            }
            if (*(s32*)(self + 0x258) == 0) ((Sub8036C0EC*)this)->v24(0x25);
            break;
        }
        case 0x25: {
            char* objects = self;
            char* vertices = self;
            const s32* timing = (const s32*)(tbl + 0x174);
            s32 done = 0;
            for (s32 i = 0; i < 6; i++, objects += 4, vertices += 0xc, timing++) {
                if (*(s32*)(self + 0x258) == *timing) *(s32*)(objects + 0x2f8) = 3;
                if (*(s32*)(objects + 0x2f8) == 3) *(f32*)(vertices + 0x2b0) += lbl_80542CB0;
                if (*(void**)(objects + 0x3bc) != 0) fn_8013CB44(*(void**)(objects + 0x3bc), (Vec3f*)(vertices + 0x2a8), 0, -1, 1);
                if (*(void**)(objects + 0x3d4) != 0) fn_8013CB44(*(void**)(objects + 0x3d4), (Vec3f*)(vertices + 0x2a8), 0, -1, 1);
                if (*(s32*)(objects + 0x2f8) != 4 && *(f32*)(vertices + 0x2b0) >= lbl_80542C68) {
                    *(s32*)(objects + 0x2f8) = 4;
                    if (*(void**)(objects + 0x3bc) != 0) {
                        forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((char*)fn_8013C824() + 0xc), *(void**)(objects + 0x3bc));
                        *(void**)(objects + 0x3bc) = 0;
                    }
                }
                if (*(s32*)(objects + 0x2f8) == 4) done++;
            }
            if (done >= 6) {
                fn_8011921C();
                fn_801183BC();
            }
            break;
        }
        case 0x26:
            fn_80119998(fn_80119DD0(), 0x78, 0, 0, 0, 1, 0, 0);
            break;
        }
    }
    if (*(u8*)(self + 0x270) == 1) fn_80368198((Sub8036C0EC*)this);
    if (*((u8*)self + 0x237)) {
        *(f32*)(self + 0x280) += *(f32*)(self + 0x284);
    }
    fn_801D1C18(self + 0x318);
    if (*((u8*)self + 0x234)) fn_8036AA60(self);
}

#pragma opt_common_subs off
void Unk8036C300::state0() {
    Vec3f v;
    Vec3f camera;
    JGeometry::TVec3f loopPos;
    JGeometry::TVec3f spawnPos;
    char* self = (char*)this;
    if (*(s32*)(self + 0x258) != 0) {
        *(s32*)(self + 0x258) = *(s32*)(self + 0x258) - 1;
    }
    if (*(s32*)(self + 0x26c) != 0) {
        *(s32*)(self + 0x26c) = *(s32*)(self + 0x26c) - 1;
        if (*(s32*)(self + 0x26c) == 0) {
            char* em = *(char**)(self + 0x398);
            if (em != 0) {
                *(u32*)(em + 0xf4) |= 1;
                *(s32*)(em + 0x24) = 1;
                *(s32*)(self + 0x398) = 0;
            }
        }
    }
    fn_8010DF78(self);
    {
        s32 idx = *(s32*)(lbl_80529DEC + 0x118);
        s32 bit = *(s32*)(lbl_80529DEC + 0x11c);
        s32 vis=cutsceneFlag(idx,bit);
        if (vis) {
            s32 st = *(s32*)(self + 0x240);
            if (st >= 5 && st <= 13) {
                *(u8*)((char*)lbl_8053AAF8 + 0x85) = 2;
                if ((void*)fn_80309C4C(lbl_8053AD30, 0x1000, -1) != 0) {
                    *(s32*)(self + 0x240) = 0xd;
                    fn_80387494(0);
                    fn_8011921C();
                    fn_801183BC();
                    if (*(void**)(self + 0x230) != 0) {
                        fn_803676CC(*(void**)(self+0x230));
                        detach__5ActorFv(*(void**)(self + 0x230));
                        *(s32*)(self + 0x230) = 0;
                    }
                }
            }
        }
    }
    if (*(s32*)(self + 0x240) <= 5 && ((u8*)fn_8016A3AC())[0x1ef] == 0 && *(void**)(self + 0x398) == 0) {
        *(void**)(self + 0x398) = fn_8013CC50(*(u32*)(self + 4), self + 0xc, lbl_80542C58, 0x54c, 0, 1, 0, 0, 1);
    }
    {
        
        if (*(s32*)(self+0x240) >= 2 && *(s32*)(self+0x240) != 0x11) {
            if (*(s32*)(self+0x240) >= 3 && *(s32*)(self+0x240) < 0xe) {
                u8* p = *(u8**)((char*)lbl_8053AB10 + 0x30);
                if (p[0x284] == 0) {
                    p[0x284]=1;
                    *(f32*)(p+0x28c)=0.05f;
                }
            }
            v=*(Vec3f*)(self+0xc);
            f32 oldY;
            f32 bottom;
            bottom=*(f32*)(self+0x28);
            oldY=*(f32*)(self+0x10);
            v.y += lbl_80542C80 + ((bottom-oldY) - lbl_80542C84);
            if (*(s32*)(self+0x240) == 5) {
                v.y = v.y + lbl_80542CB4;
            }
            if (*(s32*)(self+0x240) >= 8 && *(s32*)(self+0x240) < 0xa) {
                v.y = v.y + lbl_80542CB4;
            }
            if (*(s32*)(self+0x240) >= 3) {
                u8* eff = *(u8**)((char*)lbl_8053AB10 + 0x24);
                const f32 radius=105.0f;
                f32 high;
                f32 low;
                f32 y;
                f32 x;
                y=v.y;
                x=v.x;
                high=radius+y;
                low=y-radius;
                eff[0x179]=1;
                cutsceneCameraBox(x,low,x,high);
            } else {
                fn_8030C210(*(void**)((char*)lbl_8053AB10 + 0x24), &v);
                {
                    u8* eff = *(u8**)((char*)lbl_8053AB10 + 0x24);
                    if (eff[0x7f5] == 0) {
                        eff[0x7f4] = 1;
                        *(s32*)(eff + 0x7f8) = 4;
                        *(f32*)(eff + 0x7fc) = v.x;
                        *(f32*)(eff + 0x800) = v.y;
                        *(f32*)(eff + 0x804) = v.z;
                        eff[0x7f6] = 0;
                    }
                }
            }
        }
    }

    switch(*(s32*)(self+0x240)) {
    case 0:
        fn_80458FF0(lbl_8053AF80,0x100001b,0,0);
        ((Sub8036C0EC*)this)->v24(1);
        break;
    case 3:
        for(s32 i=0;i<4;i++) {
            loopPos=*fn_8023E724(i);
            u16 angle=fn_8023CBC0(i);
            fn_80230498(i,&loopPos,angle,0,-128,-128,1);
        }
        if(*(s32*)((char*)fn_8011921C()+8)==0x1b8)fn_80458F9C(lbl_8053AF80,60);
        break;
    case 4:
        fn_801CD950((f32*)(self+0x284),0.02f,0.0004f);
        fn_801CD950((f32*)(self+0x27c),0.15f,0.01f);
        *(f32*)(self+0x10)-=*(f32*)(self+0x27c);
        if(*(f32*)(self+0x10)<=*(f32*)(self+0x28)-48.0f) {
            *(f32*)(self+0x10)=*(f32*)(self+0x28)-48.0f;
        }
        *(s32*)(self+0x24c)+=2;
        if(*(s32*)(self+0x24c)>=225)*(s32*)(self+0x24c)=225;
        break;
    case 5:
        *(s32*)(self+0x24c)=225;
        if(*(s32*)(self+0x258)!=0) {
            if(*(s32*)(self+0x258)==1) {
                u8* mode=*(u8**)((char*)sManager__8JUTVideo+4);
                const s32 height=*(u16*)(mode+6);
                const s32 width=*(u16*)(mode+4);
                v.x=(f32)width*lbl_80542CA4;
                v.y=(f32)height*lbl_80542CA4;
                v.z=lbl_80542C6C;
                v.y+=-16.0f;
                fn_8022FE80(0,*(s32*)(self+4),*(s32*)(self+0x198),1,0);
                s32 room=*(s32*)(self+4);
                spawnPos=*(JGeometry::TVec3f*)&v;
                if(fn_8038BD08(0,lbl_80474C68[*(s32*)(self+0x268)],room,&spawnPos,0x62)) {
                    *(s32*)(self+0x268)+=1;
                    fn_80118454(fn_8011921C());
                }
            }
        } else {
            fn_8022FE80(0,*(s32*)(self+4),*(s32*)(self+0x198),1,0);
            if(fn_803865B8(0)) {
                fn_80388EEC(0);
                ((Sub8036C0EC*)this)->v24(6);
            }
        }
        break;
    case 6: {
        *(s32*)(self+0x24c)=225;
        u8* mgr=*(u8**)((char*)lbl_8053AB10+0x24);
        camera.x=-*(f32*)(mgr+0x10);
        camera.y=-*(f32*)(mgr+0x20);
        camera.z=lbl_80542C6C;
        if(PSVECDistance((Vec*)&v,(Vec*)&camera)<0.1f)((Sub8036C0EC*)this)->v24(7);
        break;
    }
    case 7:
        *(s32*)(self+0x24c)=225;
        fn_8022FE80(0,*(s32*)(self+4),*(s32*)(self+0x198),1,0);
        if(fn_803865B8(0)) {
            fn_80388EEC(0);
            ((Sub8036C0EC*)this)->v24(8);
        }
        break;
    case 8: {
        *(s32*)(self+0x24c)=225;
        u8* mgr=*(u8**)((char*)lbl_8053AB10+0x24);
        camera.x=-*(f32*)(mgr+0x10);
        camera.y=-*(f32*)(mgr+0x20);
        camera.z=lbl_80542C6C;
        if(PSVECDistance((Vec*)&v,(Vec*)&camera)<0.1f) {
            ((Sub8036C0EC*)this)->v24(9);
            *(s32*)(*(u8**)(self+0x230)+0x238)=2;
        }
        break;
    }
    case 9: *(s32*)(self+0x24c)=225; break;
    case 10: {
        *(s32*)(self+0x24c)=225;
        u8* mgr=*(u8**)((char*)lbl_8053AB10+0x24);
        camera.x=-*(f32*)(mgr+0x10);
        camera.y=-*(f32*)(mgr+0x20);
        camera.z=lbl_80542C6C;
        if(!(PSVECDistance((Vec*)&v,(Vec*)&camera)>=0.1f)) {
            fn_8022FE80(0,*(s32*)(self+4),*(s32*)(self+0x198),1,0);
            if(fn_803865B8(0)) {
                fn_80388EEC(0);
                ((Sub8036C0EC*)this)->v24(11);
                *(s32*)(*(u8**)(self+0x230)+0x238)=6;
            }
        }
        break;
    }
    case 11: *(s32*)(self+0x24c)=225; break;
    case 12:
        *(s32*)(self+0x24c)=225;
        if(*(s32*)(self+0x258)==0)((Sub8036C0EC*)this)->v24(13);
        break;
    case 13:
        *(s32*)(self+0x24c)=225;
        if(!*((u8*)fn_8011921C()+1))fn_801CD950((f32*)(self+0x284),0.0f,lbl_80542CA0);
        fn_8022FE80(0,*(s32*)(self+4),*(s32*)(self+0x198),1,0);
        if(fn_803865B8(0)) {
            fn_80388EEC(0);
            fn_8011921C();
            fn_801183BC();
        }
        break;
    case 17: break;
    }
    if(*((u8*)self+0x237)) {
        *(f32*)(self+0x280)+=*(f32*)(self+0x284);
        fn_801D1C18(self+0x318);
    }
    if(*((u8*)self+0x234))fn_8036AA60(self);
}
#pragma opt_common_subs reset
extern "C" void* fn_8013C824(void);
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void* mgr, void* emitter);
extern "C" void fn_8036A65C(void* this_) {
    char* p = (char*)this_;
    s32 i;

    if (*(u32*)(p + 0x350) != 0) {
        forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((char*)fn_8013C824() + 0xc), *(void**)(p + 0x350));
        *(u32*)(p + 0x350) = 0;
    }
    if (*(u32*)(p + 0x354) != 0) {
        forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((char*)fn_8013C824() + 0xc), *(void**)(p + 0x354));
        *(u32*)(p + 0x354) = 0;
    }
    if (*(u32*)(p + 0x358) != 0) {
        forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((char*)fn_8013C824() + 0xc), *(void**)(p + 0x358));
        *(u32*)(p + 0x358) = 0;
    }
    if (*(u32*)(p + 0x398) != 0) {
        forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((char*)fn_8013C824() + 0xc), *(void**)(p + 0x398));
        *(u32*)(p + 0x398) = 0;
    }

    i = 0;
    do {
        if (*(u32*)(p + 0x35c) != 0) {
            forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((char*)fn_8013C824() + 0xc), *(void**)(p + 0x35c));
            *(u32*)(p + 0x35c) = 0;
        }
        if (i < 2 && *(u32*)(p + 0x3b4) != 0) {
            forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((char*)fn_8013C824() + 0xc), *(void**)(p + 0x3b4));
            *(u32*)(p + 0x3b4) = 0;
        }
        if (i < 3 && *(u32*)(p + 0x378) != 0) {
            forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((char*)fn_8013C824() + 0xc), *(void**)(p + 0x378));
            *(u32*)(p + 0x378) = 0;
        }
        if (i < 5) {
            if (*(u32*)(p + 0x384) != 0) {
                forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((char*)fn_8013C824() + 0xc), *(void**)(p + 0x384));
                *(u32*)(p + 0x384) = 0;
            }
            if (*(u32*)(p + 0x3ec) != 0) {
                forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((char*)fn_8013C824() + 0xc), *(void**)(p + 0x3ec));
                *(u32*)(p + 0x3ec) = 0;
            }
            if (*(u32*)(p + 0x400) != 0) {
                forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((char*)fn_8013C824() + 0xc), *(void**)(p + 0x400));
                *(u32*)(p + 0x400) = 0;
            }
        }
        if (i < 6) {
            if (*(u32*)(p + 0x3bc) != 0) {
                forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((char*)fn_8013C824() + 0xc), *(void**)(p + 0x3bc));
                *(u32*)(p + 0x3bc) = 0;
            }
            if (*(u32*)(p + 0x3d4) != 0) {
                forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((char*)fn_8013C824() + 0xc), *(void**)(p + 0x3d4));
                *(u32*)(p + 0x3d4) = 0;
            }
            if (*(u32*)(p + 0x39c) != 0) {
                forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((char*)fn_8013C824() + 0xc), *(void**)(p + 0x39c));
                *(u32*)(p + 0x39c) = 0;
            }
        }
        i++;
        p += 4;
    } while (i < 7);
}

extern "C" void fn_8036A894(void* this_) {
    u8* p = (u8*)this_;
    EffArgs args;
    f32 mtx[3][4];
    JGeometry::TVec3<f32> pos;

    if (*(s32*)(p + 0x24c) > 0) {
        args.f10.w = -1;
        args.f14.w = -1;
        for (u8 i = 0; i < 0x10; i++) {
            args.order[i] = i;
        }
        args.f10.w = -1;
        args.f14.w = 0;
        args.ptr = 0;
        args.b1c = 0;
        args.b1d = 0;
        args.b1e = 0;
        args.b1f = 1;
        args.b20 = 1;
        args.b21 = 0;
        args.b22 = 0;
        args.b23 = 0;
        args.b24 = 0;
        args.b25 = 0;
        args.b26 = 1;
        args.w28 = 3;
        args.b2c = 1;
        args.b2d = 0;
        args.b2e = 0;
        args.x30 = -1;
        args.x34 = 0;
        args.x38 = 2;
        PSMTXTrans(mtx, 0.0f, 0.0f, 0.0f);
        mtx[0][0] = 96.0f;
        mtx[0][1] = 0.0f;
        mtx[0][2] = 0.0f;
        mtx[1][0] = 0.0f;
        mtx[1][1] = 1.0f;
        mtx[1][2] = 0.0f;
        mtx[2][0] = 0.0f;
        mtx[2][1] = 0.0f;
        mtx[2][2] = 96.0f;
        s32 a = *(s32*)(p + 0x24c);
        args.f14.b[0] = 0;
        args.f14.b[1] = 0;
        args.f14.b[2] = 0;
        args.f14.b[3] = a;
        args.ptr = mtx;
        *(s8*)&args.b1d = -1;
        args.b2d = 1;
        pos = *(JGeometry::TVec3<f32>*)(p + 0xc);
        pos.z = 0.0f;
        void* tgt = *(void**)(p + 0x310);
        if (*(s32*)(p + 4) < 8) {
            fn_802F745C(*(void**)((u8*)lbl_8053AB10 + 0x20), &pos.x, tgt, &args);
        }
    }
}

extern "C" void fn_8036AA60(char* self) {
    extern void* fn_801902C0(void);
    Mtx m1;
    Mtx m2;
    Vec3f v1;
    Vec3f v2;
    char* entry;
    s32 cnt;
    s32 st;
    s32 idx;

    PSMTXTrans(m1, *(f32*)(self + 0xc), *(f32*)(self + 0x10), *(f32*)(self + 0x14));
    v1.x = lbl_80542C58;
    v1.y = lbl_80542C6C;
    v1.z = lbl_80542C6C;
    fn_8010F668(m1, &v1, lbl_80542CC4);
    m2[0][0] = lbl_80542C6C;
    m2[0][1] = lbl_80542C6C;
    m2[0][2] = lbl_80542C6C;
    m2[0][3] = lbl_80542C6C;
    m2[1][0] = lbl_80542C6C;
    m2[1][1] = lbl_80542C6C;
    m2[1][2] = lbl_80542C6C;
    m2[1][3] = lbl_80542C6C;
    m2[2][0] = lbl_80542C6C;
    m2[2][1] = lbl_80542C6C;
    m2[2][2] = lbl_80542C6C;
    m2[2][3] = lbl_80542C6C;
    v2.x = lbl_80542C6C;
    v2.y = lbl_80542C6C;
    v2.z = lbl_80542C58;
    fn_8010F668(m2, &v2, *(f32*)(self + 0x280));
    PSMTXConcat(m1, m2, m1);

    if (*(u8*)(self + 0x238) != 0) {
        *(s32*)(self + 0x254) = *(s32*)(self + 0x254) + 1;
    }
    st = *(s32*)(self + 0x244);
    switch (st) {
    case 0:
    case 2:
        if (*(s32*)(self + 0x254) >= ((s32*)(lbl_80474C38 + 0x60))[st]) {
            *(s32*)(self + 0x254) = ((s32*)(lbl_80474C38 + 0x54))[st];
        }
        break;
    case 1:
        if (*(s32*)(self + 0x254) >= ((s32*)(lbl_80474C38 + 0x60))[1]) {
            *(s32*)(self + 0x244) = 2;
        }
        break;
    }

    cnt = *(s32*)(self + 0x254);
    idx = ((s32*)(lbl_80474C38 + 0x8c))[*(s32*)(self + 0x23c)];
    entry = (char*)fn_801902C0() + idx * 0x60 + 8;
    if (*(s32*)(entry + 0x3c) != 0 && *(u8*)(entry + 0x5c) == 0) {
        *(u8*)(entry + 0x5c) = 1;
        *(f32*)(entry + 0x0) = lbl_80542CA4;
        *(f32*)(entry + 0x4) = lbl_80542CA4;
        *(f32*)(entry + 0x8) = lbl_80542CA4;
        PSMTXCopy(m1, (f32(*)[4])(entry + 0xc));
        *(f32*)(entry + 0x48) = lbl_80542CC8;
        *(s32*)(entry + 0x4c) = cnt;
        *(s32*)(entry + 0x54) = 0;
        *(s32*)(entry + 0x58) = 2;
    }
}

static inline void drawShadow8036(char* self, DrawRec& args, u32 index)
{
    if (*(u32*)(self + 0x138) == 0) {
        fn_801EF830(*(s32*)(self + 4), self + 0xc, args.ids, 7, lbl_80474E48, index, 0);
    }
}
extern "C" void fn_8036AC58(void* this_, void* param) {
    char* self = (char*)this_;

    if (*(u8*)(self + 0x270) != 1 || *(s32*)(self + 0x274) >= 0x80) {
        DrawRec args;
        if (!(*(s32*)(self + 0x23c) == 5 && *(s32*)(self + 0x240) >= 0x1e && *(s32*)(self + 0x240) < 0x21)) {
            s32 id = *(s32*)(self + 0x240);
            if (id == 0x1c || (u32)(id - 0x1d) <= 1 || (u32)(id - 0x21) <= 1 || id == 0x23) {
                drawShadow8036(self, args, *(s32*)(self + 0x264) + 0x1b3);
            } else {
                drawShadow8036(self, args, (u32)param + *(s32*)(self + 0x328));
            }
        } else {
            if (*(s32*)(self + 0x24c) < 0xc0) {
                drawShadow8036(self, args, (u32)param + *(s32*)(self + 0x328));
            }
            u8 alpha = 0xff - *(s32*)(self + 0x24c);
            ((u8*)&args.w10)[0] = 0xff;
            ((u8*)&args.w10)[1] = 0xff;
            ((u8*)&args.w10)[2] = 0xff;
            ((u8*)&args.w10)[3] = alpha;
        }
        {
            s32 id = *(s32*)(self + 0x240);
            if (id == 0x1c || (u32)(id - 0x1d) <= 1 || (u32)(id - 0x21) <= 1 || id == 0x23) {
                s32 idx;
                void* pos;
                pos = self + 0xc;
                idx = *(s32*)(self + 0x264) + 0x1b3;
                void* res;
                if (*(s32*)(self + 4) < 8) {
                    res = ((SobResMgr*)(*(void**)((u8*)lbl_8053AAF8 + 0xa4)))->vf18('SOB ', (const char*)lbl_80474E48);
                    fn_802F86CC(*(void**)((u8*)lbl_8053AB10 + 0x20), pos, res, idx, 1.0f, 1.0f, &args);
                }
                fn_803075AC(*(void**)(self + 0x198), *(s32*)(self + 4), self + 0xc, *(s32*)(self + 0x264) + 0x1b3, 0, 1, -1, 0, 0, 0);
            } else {
                u32 idx;
                void* pos;
                pos = self + 0xc;
                idx = (u32)param + *(s32*)(self + 0x328);
                void* res;
                if (*(s32*)(self + 4) < 8) {
                    res = ((SobResMgr*)(*(void**)((u8*)lbl_8053AAF8 + 0xa4)))->vf18('SOB ', (const char*)lbl_80474E48);
                    fn_802F86CC(*(void**)((u8*)lbl_8053AB10 + 0x20), pos, res, idx, 1.0f, 1.0f, &args);
                }
                fn_803075AC(*(void**)(self + 0x198), *(s32*)(self + 4), self + 0xc, (u32)param + *(s32*)(self + 0x328), 0, 1, -1, 0, 0, 0);
            }
        }
    }
}

extern "C" u8 fn_8036B018(u8* this_) {
    s32 v = *(s32*)(this_ + 0x240);
    if (v == 0x11 || v == 0x26) {
        return 1;
    }
    return 0;
}

extern "C" void* fn_801F856C(void);
extern "C" void fn_802B3A3C(void*);
extern "C" s32 Actor_CreateByID(void*,u32,s32,void*,s32,s32,s32);
extern "C" void* fn_801F666C(void*,s32);
extern "C" void* fn_80119DD0(void);
extern "C" void fn_80119998(void*,s32,s32,s32,s32,s32,s32,s32);
extern "C" void* fn_802D6A9C(void);
extern "C" void fn_802D8050(void*,s32,s32,s32);
extern "C" void fn_8037AD00(void*,s32);
extern void* lbl_8053AD70;
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void*,void*);
extern "C" void Gol2_SetField_0x2f4(void*,s32);
extern "C" void fn_8045873C(void*,s32);
extern f32 lbl_80542CCC;
extern f32 lbl_80542CA8;
#pragma opt_common_subs off
extern "C" void fn_8036B03C(u8* this_,s32 param){
s32 n, i;
u8* dst;
u16* ids;
u16* idTable;
s32* wordTable;
const char* tbl;
u8* self;
s32 state;
state=param;
tbl=lbl_80474C38;
self=this_;
JGeometry::TVec3<f32> pos,v,v24;
switch(state){
case 0: {  break; }
case 1: {  break; }
case 2: { self[0x238]=0;{ u8* e = *(u8**)(self + 0x384); *(u32*)(e + 0xf4) |= 1; *(s32*)(e + 0x24) = 1; *(u8**)(self + 0x384) = 0; }
{ u8* e = *(u8**)(self + 0x388); *(u32*)(e + 0xf4) |= 1; *(s32*)(e + 0x24) = 1; *(u8**)(self + 0x388) = 0; }
{ u8* e = *(u8**)(self + 0x38c); *(u32*)(e + 0xf4) |= 1; *(s32*)(e + 0x24) = 1; *(u8**)(self + 0x38c) = 0; }
{ u8* e = *(u8**)(self + 0x390); *(u32*)(e + 0xf4) |= 1; *(s32*)(e + 0x24) = 1; *(u8**)(self + 0x390) = 0; }
{ u8* e = *(u8**)(self + 0x394); *(u32*)(e + 0xf4) |= 1; *(s32*)(e + 0x24) = 1; *(u8**)(self + 0x394) = 0; } break; }
case 3: { self[0x238]=1; *(s32*)(self + 0x244)=1; wordTable=(s32*)(tbl+0x54);*(s32*)(self+0x254)=wordTable[1];
*(u8**)(self + 0x378) = (u8*)fn_8013CC50(*(s32*)(self + 4), self + 0xc, lbl_80542CA4, 0x2ae, 0, 1, 0, 0, 1);
*(u8**)(self + 0x37c) = (u8*)fn_8013CC50(*(s32*)(self + 4), self + 0xc, lbl_80542CA4, (idTable=(u16*)(tbl+0xf8),idTable[*(s32*)(self+0x23c)]), 0, 1, 0, 0, 1);
*(u8**)(self + 0x380) = (u8*)fn_8013CC50(*(s32*)(self + 4), self + 0xc, lbl_80542CA4, (idTable=(u16*)(tbl+0x108),idTable[*(s32*)(self+0x23c)]), 0, 1, 0, 0, 1);
*(u8**)(self + 0x358) = (u8*)fn_8013CC50(*(s32*)(self + 4), self + 0xc, lbl_80542C58, (idTable=(u16*)(tbl+0x118),idTable[*(s32*)(self+0x23c)]), 0, 1, 0, 0, 1);
fn_801F0E34(self,0x400d5,0);
{ n = *(s32*)((u8*)fn_801F856C()+0x1008);
for (i=0;i<n;i++) { u8* a=*(u8**)((u8*)fn_801F856C()+8+i*4);
if(a && *(u32*)(a+0x1a0)==0x53574556){ fn_802B3A3C(a); break; } } }
 break; }
case 4: { switch(*(s32*)(self + 0x23c)){case 6: fn_80458FF0(lbl_8053AF80,0x100000f,0,0);break; default: fn_80458FF0(lbl_8053AF80,0x100001c,0,0);break;} self[0x237]=1; break; }
case 5: { {JGeometry::TVec3<f32> v;v=*(JGeometry::TVec3<f32>*)(self+0xc)+JGeometry::TVec3<f32>(lbl_80542C6C,lbl_80542CCC,lbl_80542C78);*(s32*)(self + 0x25c)=Actor_CreateByID(fn_801F856C(),0x444e4156,*(s32*)(self + 4),&v,0,-1,-1);*(u8**)(self + 0x230)=(u8*)fn_801F666C(fn_801F856C(),*(s32*)(self + 0x25c));*(s32*)(self + 0x258)=60;} break; }
case 6: {  break; }
case 7: { { u8* mode=*(u8**)((u8*)sManager__8JUTVideo+4);
const s32 height=*(u16*)(mode+6);
const s32 width=*(u16*)(mode+4);
pos.x=(f32)width*lbl_80542CA4;pos.y=(f32)height*lbl_80542CA4;pos.z=lbl_80542C6C; }
pos.y+=lbl_80542CA8;
fn_8022FE80(0,*(s32*)(self + 4),*(s32*)(self + 0x198),1,0);
fn_8038BD08(0,cutsceneTable32((s32*)(tbl+0x30),*(s32*)(self+0x268)),*(s32*)(self + 4),&JGeometry::TVec3<f32>(pos),0x62);
++*(s32*)(self + 0x268); (*(u8**)(self + 0x230))[0x230]=1; break; }
case 8: {  break; }
case 9: { { u8* mode=*(u8**)((u8*)sManager__8JUTVideo+4);
const s32 height=*(u16*)(mode+6);
const s32 width=*(u16*)(mode+4);
pos.x=(f32)width*lbl_80542CA4;pos.y=(f32)height*lbl_80542CA4;pos.z=lbl_80542C6C; }
pos.y+=lbl_80542CA8;
fn_8022FE80(0,*(s32*)(self + 4),*(s32*)(self + 0x25c),1,0);
fn_8038BD08(0,cutsceneTable32((s32*)(tbl+0x30),*(s32*)(self+0x268)),*(s32*)(self + 4),&JGeometry::TVec3<f32>(pos),0x62);
++*(s32*)(self + 0x268);  break; }
case 10: { { u8* mode=*(u8**)((u8*)sManager__8JUTVideo+4);
const s32 height=*(u16*)(mode+6);
const s32 width=*(u16*)(mode+4);
pos.x=(f32)width*lbl_80542CA4;pos.y=(f32)height*lbl_80542CA4;pos.z=lbl_80542C6C; }
pos.y+=lbl_80542CA8;
fn_8022FE80(0,*(s32*)(self + 4),*(s32*)(self + 0x198),1,0);
fn_8038BD08(0,cutsceneTable32((s32*)(tbl+0x30),*(s32*)(self+0x268)),*(s32*)(self + 4),&JGeometry::TVec3<f32>(pos),0x62);
++*(s32*)(self + 0x268);  break; }
case 11: {  break; }
case 13: { { u8* mode=*(u8**)((u8*)sManager__8JUTVideo+4);
const s32 height=*(u16*)(mode+6);
const s32 width=*(u16*)(mode+4);
pos.x=(f32)width*lbl_80542CA4;pos.y=(f32)height*lbl_80542CA4;pos.z=lbl_80542C6C; }
pos.y+=lbl_80542CA8;
fn_8022FE80(0,*(s32*)(self + 4),*(s32*)(self + 0x198),1,0);
fn_8038BD08(0,cutsceneTable32((s32*)(tbl+0x30),*(s32*)(self+0x268)),*(s32*)(self + 4),&JGeometry::TVec3<f32>(pos),0x62);
++*(s32*)(self + 0x268);  break; }
case 12: { *(s32*)(self + 0x258)=150; break; }
case 14: { self[0x237]=0;
{ids=(u16*)(tbl+0xc8); dst=self; for(i=0;i<7;i++,ids++,dst+=4){ *(void**)(dst+0x35c)=fn_8013CC50(*(s32*)(self + 4),self+0xc,lbl_80542CA4,*ids,0,1,0,0,1); }}
*(s32*)(self + 0x2f0)=300;fn_801F0E34(self,0x30082,0);
*(u8**)(self + 0x350) = (u8*)fn_8013CC50(*(s32*)(self + 4), self + 0xc, lbl_80542CA4, (idTable=(u16*)(tbl+0xd8),idTable[*(s32*)(self+0x23c)]), 0, 1, 0, 0, 1);
*(u8**)(self + 0x354) = (u8*)fn_8013CC50(*(s32*)(self + 4), self + 0xc, lbl_80542C58, (idTable=(u16*)(tbl+0xe8),idTable[*(s32*)(self+0x23c)]), 0, 1, 0, 0, 1);
*(s32*)(self + 0x26c)=400; break; }
case 15: { self[0x234]=0;self[0x236]=1; break; }
case 16: { self[0x236]=0;fn_80119998(fn_80119DD0(),180,0,0,0,1,0,0);*(s32*)(self + 0x24c)=1;
for(i=0;i<4;i++){v=*fn_8023E724(i);fn_80230498(i,&v,(u16)fn_8023CBC0(i),255,-128,-128,1);}
fn_8036A65C(self);v.set(*(f32*)(self + 0x24),*(f32*)(self + 0x28),*(f32*)(self + 0x2c));v.z+=lbl_80542C78;
Actor_CreateByID(fn_801F856C(),0x43524e56,*(s32*)(self + 4),&v,*(s32*)(self + 0x23c),-1,-1); break; }
case 17: { *(s32*)(self + 0x24c)=0;detach__5ActorFv(self);{s32 v=*(s32*)(self + 0x248);if(v>0){fn_802D8050(fn_802D6A9C(),v,1,255);fn_8037AD00(lbl_8053AD70,4);}} break; }
case 18: {  break; }
case 19: {  break; }
case 20: {  break; }
case 21: { self[0x238]=0;{ u8* e = *(u8**)(self + 0x384); *(u32*)(e + 0xf4) |= 1; *(s32*)(e + 0x24) = 1; *(u8**)(self + 0x384) = 0; }
{ u8* e = *(u8**)(self + 0x388); *(u32*)(e + 0xf4) |= 1; *(s32*)(e + 0x24) = 1; *(u8**)(self + 0x388) = 0; }
{ u8* e = *(u8**)(self + 0x38c); *(u32*)(e + 0xf4) |= 1; *(s32*)(e + 0x24) = 1; *(u8**)(self + 0x38c) = 0; }
{ u8* e = *(u8**)(self + 0x390); *(u32*)(e + 0xf4) |= 1; *(s32*)(e + 0x24) = 1; *(u8**)(self + 0x390) = 0; }
{ u8* e = *(u8**)(self + 0x394); *(u32*)(e + 0xf4) |= 1; *(s32*)(e + 0x24) = 1; *(u8**)(self + 0x394) = 0; } break; }
case 22: { self[0x238]=1; *(s32*)(self + 0x244)=1; wordTable=(s32*)(tbl+0x54);*(s32*)(self+0x254)=wordTable[1];
*(u8**)(self + 0x378) = (u8*)fn_8013CC50(*(s32*)(self + 4), self + 0xc, lbl_80542CA4, 0x2ae, 0, 1, 0, 0, 1);
*(u8**)(self + 0x37c) = (u8*)fn_8013CC50(*(s32*)(self + 4), self + 0xc, lbl_80542CA4, (idTable=(u16*)(tbl+0xf8),idTable[*(s32*)(self+0x23c)]), 0, 1, 0, 0, 1);
*(u8**)(self + 0x380) = (u8*)fn_8013CC50(*(s32*)(self + 4), self + 0xc, lbl_80542CA4, (idTable=(u16*)(tbl+0x108),idTable[*(s32*)(self+0x23c)]), 0, 1, 0, 0, 1);
*(u8**)(self + 0x358) = (u8*)fn_8013CC50(*(s32*)(self + 4), self + 0xc, lbl_80542C58, (idTable=(u16*)(tbl+0x118),idTable[*(s32*)(self+0x23c)]), 0, 1, 0, 0, 1);
fn_801F0E34(self,0x400d5,0);
{ n = *(s32*)((u8*)fn_801F856C()+0x1008);
for (i=0;i<n;i++) { u8* a=*(u8**)((u8*)fn_801F856C()+8+i*4);
if(a && *(u32*)(a+0x1a0)==0x53574556){ fn_802B3A3C(a); break; } } }
 break; }
case 23: { switch(*(s32*)(self + 0x23c)){case 6: fn_80458FF0(lbl_8053AF80,0x100000f,0,0);break; default: fn_80458FF0(lbl_8053AF80,0x100001c,0,0);break;} self[0x237]=1; break; }
case 24: { if(!*(u8**)(self + 0x398)){*(u8**)(self + 0x398) = (u8*)fn_8013CC50(*(s32*)(self + 4), self + 0xc, lbl_80542C58, 0x54c, 0, 1, 0, 0, 1);
}{ u8* mode=*(u8**)((u8*)sManager__8JUTVideo+4);
const s32 height=*(u16*)(mode+6);
const s32 width=*(u16*)(mode+4);
v24.x=(f32)width*lbl_80542CA4;v24.y=(f32)height*lbl_80542CA4;v24.z=lbl_80542C6C; }
v24.y+=lbl_80542CA8;
fn_8022FE80(0,*(s32*)(self + 4),*(s32*)(self + 0x198),1,0);
if (fn_8038BD08(0,cutsceneTable32((s32*)(tbl+0x30),*(s32*)(self+0x268)),*(s32*)(self + 4),&JGeometry::TVec3<f32>(v24),0x62)) {
++*(s32*)(self + 0x268); fn_80118454(fn_8011921C()); } break; }
case 25: { *(s32*)(self + 0x294)=((s32*)(tbl+0x78))[0]+70;
*(s32*)(self + 0x298)=((s32*)(tbl+0x78))[1]+70;
*(s32*)(self + 0x29c)=((s32*)(tbl+0x78))[2]+70;
*(s32*)(self + 0x2a0)=((s32*)(tbl+0x78))[3]+70;
*(s32*)(self + 0x2a4)=((s32*)(tbl+0x78))[4]+70; break; }
case 26: { self[0x237]=0;
{ids=(u16*)(tbl+0xc8); dst=self; for(i=0;i<7;i++,ids++,dst+=4){ *(void**)(dst+0x35c)=fn_8013CC50(*(s32*)(self + 4),self+0xc,lbl_80542CA4,*ids,0,1,0,0,1); }}
*(s32*)(self + 0x2f0)=300;fn_801F0E34(self,0x30082,0);
*(u8**)(self + 0x350) = (u8*)fn_8013CC50(*(s32*)(self + 4), self + 0xc, lbl_80542CA4, (idTable=(u16*)(tbl+0xd8),idTable[*(s32*)(self+0x23c)]), 0, 1, 0, 0, 1);
*(u8**)(self + 0x354) = (u8*)fn_8013CC50(*(s32*)(self + 4), self + 0xc, lbl_80542C58, (idTable=(u16*)(tbl+0xe8),idTable[*(s32*)(self+0x23c)]), 0, 1, 0, 0, 1);
*(s32*)(self + 0x26c)=400; break; }
case 27: { self[0x234]=0;self[0x236]=1; break; }
case 28: { *(s32*)(self + 0x24c)=1; fn_80119998(fn_80119DD0(),180,0,0,0,1,0,0);fn_8036A65C(self);
*(JGeometry::TVec3<f32>*)(self+0xc)+=JGeometry::TVec3<f32>(lbl_80542C6C,lbl_80542C80,lbl_80542C6C);
*(s32*)(self + 0x258)=180;{dst=self;for(i=0;i<5;i++,dst+=4){
if(*(void**)(dst+0x3bc)){forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((u8*)fn_8013C824()+0xc),*(void**)(dst+0x3bc));*(void**)(dst+0x3bc)=0;}
if(*(void**)(dst+0x3d4)){forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((u8*)fn_8013C824()+0xc),*(void**)(dst+0x3d4));*(void**)(dst+0x3d4)=0;}
}} break; }
case 29: { *(s32*)(self + 0x258)=170; break; }
case 30: {  break; }
case 31: { *(s32*)(self + 0x264)=0;v=*(JGeometry::TVec3<f32>*)(self+0xc);v.y+=lbl_80542C80;v.z=lbl_80542C6C;*(f32*)(self + 0x288)=lbl_80542C6C;*(s32*)(self + 0x28c)=0;
{ids=(u16*)(tbl+0x128);dst=self;for(i=0;i<6;i++,ids++,dst+=4){*(void**)(dst+0x39c)=fn_8013CC50(*(s32*)(self + 4),&v,lbl_80542C58,*ids,0,1,0,0,1);(*(u8**)(dst+0x39c))[0xbb]=(s32)*(f32*)(self + 0x288);}}
*(u8**)(self + 0x3b4) = (u8*)fn_8013CC50(*(s32*)(self + 4), &v, lbl_80542C58, 0x540, 0, 1, 0, 0, 1);
*(u8**)(self + 0x3b8) = (u8*)fn_8013CC50(*(s32*)(self + 4), &v, lbl_80542C58, 0x541, 0, 1, 0, 0, 1);

*(s32*)(self + 0x258)=150;fn_8045873C(lbl_8053AF80,1); break; }
case 32: { fn_80119998(fn_80119DD0(),150,0,1,0,0,50,0);*(s32*)(self + 0x258)=185;fn_801F0E34(self,0x40041,0); break; }
case 33: { fn_80119998(fn_80119DD0(),150,0,0,0,0,25,0);*(s32*)(self + 0x24c)=1;Gol2_SetField_0x2f4(*(u8**)(self + 0x2f4),255);
{dst=self;for(i=0;i<6;i++,dst+=4){if(*(void**)(dst+0x39c)){forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((u8*)fn_8013C824()+0xc),*(void**)(dst+0x39c));}*(void**)(dst+0x39c)=0;}}*(s32*)(self + 0x264)=10;fn_8045873C(lbl_8053AF80,0); break; }
case 34: { { u8* mode=*(u8**)((u8*)sManager__8JUTVideo+4);
const s32 height=*(u16*)(mode+6);
const s32 width=*(u16*)(mode+4);
pos.x=(f32)width*lbl_80542CA4;pos.y=(f32)height*lbl_80542CA4;pos.z=lbl_80542C6C; }
pos.y+=lbl_80542CA8;
fn_8022FE80(0,*(s32*)(self + 4),*(s32*)(self + 0x198),1,0);
fn_8038BD08(0,cutsceneTable32((s32*)(tbl+0x30),*(s32*)(self+0x268)),*(s32*)(self + 4),&JGeometry::TVec3<f32>(pos),0x62);
++*(s32*)(self + 0x268);  break; }
case 35: { *(s32*)(self + 0x258)=120; break; }
case 36: { *(s32*)(self + 0x258)=240;*(JGeometry::TVec3<f32>*)(self+0x2e4)=*(JGeometry::TVec3<f32>*)(self+0xc); break; }
case 37: { *(s32*)(self + 0x258)=240; break; }
case 38: { *(s32*)(self + 0x24c)=0;detach__5ActorFv(self);{s32 v=*(s32*)(self + 0x248);if(v>0){fn_802D8050(fn_802D6A9C(),v,1,255);fn_8037AD00(lbl_8053AD70,5);}} break; }
}
*(s32*)(self + 0x240)=param;
}
#pragma opt_common_subs reset
extern "C" void fn_8036C0EC(Sub8036C0EC* this_) {
    extern void* fn_8011921C(void);
    char* self = (char*)this_;
    s32 id;
    s32 v = *(s32*)((char*)fn_8011921C() + 8);
    if (*(u8*)(self + 0x270) != 1) {
        if (*(s32*)(self + 0x23c) == 4) {
            if (v == 0) {
                id = 2;
            } else if (v == 0x96) {
                id = 3;
            } else if (v == 0x1fe) {
                id = 4;
            } else if (v == 0x32a) {
                id = 5;
            } else if (v == 0x3f2) {
                id = 0xe;
            } else if (v == 0x51e) {
                id = 0xf;
            } else if (v == 0x5b4) {
                id = 0x10;
            } else if (v == 0x6e0) {
                id = 0x11;
            } else {
                return;
            }
        } else {
            if (v == 0) {
                id = 0x15;
            } else if (v == 0x96) {
                id = 0x16;
            } else if (v == 0x1fe) {
                id = 0x17;
            } else if (v == 0x32a) {
                id = 0x18;
            } else if (v == 0x3f2) {
                id = 0x1a;
            } else if (v == 0x51e) {
                id = 0x1b;
            } else if (v == 0x5b4) {
                id = 0x1c;
            } else if (v == 0x6e0) {
                id = 0x26;
            } else {
                return;
            }
        }
        this_->v24(id);
    }
}

extern "C" void fn_8036C250(char* self) {
    JGeometry::TVec3<f32> saved = *(JGeometry::TVec3<f32>*)(self + 0xc);
    if (*(s32*)(self + 0x23c) == 5 && *(s32*)(self + 0x240) >= 0x24 && *(s32*)(self + 0x240) != 0x26) {
        fn_803683AC(self);
    } else {
        fn_8010DF58(self);
        fn_8036A894(self);
        if (*(u8*)(self + 0x236) != 0) {
            fn_8036AC58(self, lbl_80474C48[*(s32*)(self + 0x23c)]);
        }
        fn_80368660(self);
        *(JGeometry::TVec3<f32>*)(self + 0xc) = saved;
    }
}

extern "C" void fn_8036C300(Unk8036C300* this_) {
    char* self = (char*)this_;
    if (*(s32*)(self + 0x2f0) != 0) {
        *(s32*)(self + 0x2f0) = *(s32*)(self + 0x2f0) - 1;
        if (*(s32*)(self + 0x2f0) == 0xe1) {
            fn_801F0E34(self, 0x30082, 0);
        } else if (*(s32*)(self + 0x2f0) == 0xb4) {
            fn_801F0E34(self, 0x30082, 0);
            fn_801F0E34(self, 0x30083, 0);
        }
    }
    (this_->*lbl_804AE070[*(s32*)(self + 0x23c) - 4])();
}

extern "C" void fn_8036C3AC(void* this_) {
    extern void fn_8010DF98(void* p);
    extern void detach__5ActorFv(void* p);
    extern void fn_801D2608(void* p, void* a, s32 b);
    extern void fn_801D22DC(void* p, s32 a, s32 b, s32 c);
    extern void fn_801D1F14(void* p, f32);
    extern void fn_802D7440(void* mgr, s32 a);
    extern void* fn_802D6A9C(void);
    extern void* fn_801F856C(void);
    extern s32 fn_8013CC50(u32 id, void* p, f32 f, u32 a, u32 b, u32 c, u32 d, u32 e, u32 g);
    extern char lbl_8053A1C0;
    extern u8 sincosTable___5JMath[];

    char* self = (char*)this_;
    const char* tbl;
    tbl = lbl_80474C38;
    s32 i;
    u32* b;
    u16* a;
    JGeometry::TVec3<f32>* pt;
    char* dst;


    fn_8010DF98(self);
    *(s32*)(self + 0x23c) = *(s32*)(self + 0x90) & 0x1f;
    *(s32*)(self + 0x248) = (*(u32*)(self + 0x90) >> 22) & 0x1f;
    if (*(s32*)(self + 0x23c) != 4 && *(s32*)(self + 0x23c) != 5) {
        detach__5ActorFv(self);
        return;
    }
    if (*(s32*)(self + 0x23c) == 5) {
        *(s32*)(self + 0x240) = 0x13;
        *(s32*)(self + 0x268) = 5;
    } else {
        *(s32*)(self + 0x268) = 0;
    }
    {
        void* obj = lbl_8053AAF8;
        char* str = lbl_8053A1C8;
        void* sub = *(void**)((char*)obj + 0xa4);
        *(void**)(self + 0x310) = ((SobResMgr*)sub)->vf18(0x3f3f3f3f, str);
    }
    fn_801D2608(self + 0x318, &lbl_8053A1C0, 2);
    switch (*(s32*)(self + 0x23c)) {
    case 0: case 1: case 2: case 3: case 4: case 5:
        fn_801D22DC(self + 0x318, 0, 2, 0);
        break;
    case 6: default:
        fn_801D22DC(self + 0x318, 1, 2, 0);
        break;
    }
    fn_801D1F14(self + 0x318, 0.0f);
    *(f32*)(self + 0x10) = *(f32*)(self + 0x10) - 32.0f;

    JGeometry::TVec3<f32> pts[5];
    JGeometry::TVec3<f32> t4, t3, t2, t1;
    pts[0] = *(JGeometry::TVec3<f32>*)(self + 0xc);
    t1.set(*(f32*)(self+0x24)-80.0f, *(f32*)(self+0x28)-48.0f, 0.0f);
    pts[1] = t1;
    t2.set(*(f32*)(self+0x24)+80.0f, *(f32*)(self+0x28)-48.0f, 0.0f);
    pts[2] = t2;
    t3.set(*(f32*)(self+0x24)-80.0f, 48.0f+*(f32*)(self+0x28), 0.0f);
    pts[3] = t3;
    t4.set(80.0f+*(f32*)(self+0x24), 48.0f+*(f32*)(self+0x28), 0.0f);
    pts[4] = t4;

    b = (u32*)(tbl + 0xb4);
    a = (u16*)(tbl + 0xa8);
    pt = pts;
    dst = self;
    for (i = 0; i < 5; i++) {
        *(s32*)(dst + 0x384) = fn_8013CC50(*(u32*)(self + 0x4), pt, 1.0f, *a, 0, *b, 0, 0, 1);
        dst += 4;
        pt++;
        a++;
        b++;
    }
    fn_802D7440(fn_802D6A9C(), 0);

    for (i = 0; i < 5; i++) {
        s16 ang = *(s16*)(tbl + 0x6c + i * 2);
        f32* sc = (f32*)(sincosTable___5JMath + ((u16)ang >> 5) * 8);
        JGeometry::TVec3<f32>* out = (JGeometry::TVec3<f32>*)(self + 0x2a8);
        out[i].set(*(f32*)(self + 0xc) + 55.0f * sc[1], 32.0f + (*(f32*)(self + 0x10) + 35.0f * sc[0]), 0.0f);
    }
    *(JGeometry::TVec3<f32>*)(self + 0x2e4) = *(JGeometry::TVec3<f32>*)(self + 0xc);

    {
        s32 n = *(s32*)((char*)fn_801F856C() + 0x1008);
        for (i = 0; i < n; i++) {
            char* a = (char*)*(void**)((char*)fn_801F856C() + 8 + i * 4);
            if (a != 0 && *(u32*)(a + 0x1a0) == 0x474F4C32) {
                *(char**)(self + 0x2f4) = a;
                return;
            }
        }
    }
}

extern "C" void* fn_8036C69C(void* this_, short how) {
    if (this_) {
        *(void**)this_ = (void*)lbl_804AE088;
        Sub8036C69C* sub = *(Sub8036C69C**)((char*)this_ + 0x314);
        if (sub && (void*)sub != 0) {
            sub->v0(1);
        }
        *(void**)((char*)this_ + 0x314) = 0;
        fn_8036A65C(this_);
        if ((s32)this_ + 0x318 != 0) {
            if ((s32)this_ + 0x33c != 0) {
                *(void**)((char*)this_ + 0x33c) = (void*)lbl_8049CC34;
            }
        }
        __dt__13Base_8010E074Fv(this_, 0);
        if (how > 0) {
            operator delete(this_);
        }
    }
    return this_;
}

extern "C" void fn_8010E074(void* this_);
extern "C" void fn_801D267C(void* p);
extern "C" void fn_80458F9C(void* p, int n);
extern void* lbl_8053AF80;
extern "C" void __ct__Q29JGeometry8TVec3_f_Fv();
#include "PowerPC_EABI_Support/Runtime/MWCPlusPlusLib.h"
extern "C" u8* fn_8036C750(u8* this_)
{
    fn_8010E074(this_);
    *(void**)this_ = lbl_804AE088;
    *(s32*)(this_ + 0x230) = 0;
    this_[0x234] = 1;
    this_[0x235] = 1;
    this_[0x236] = 0;
    this_[0x237] = 0;
    this_[0x238] = 1;
    *(s32*)(this_ + 0x23c) = 0;
    *(s32*)(this_ + 0x240) = 0;
    *(s32*)(this_ + 0x244) = 0;
    *(s32*)(this_ + 0x248) = 0;
    *(s32*)(this_ + 0x24c) = 0;
    *(f32*)(this_ + 0x250) = 0.0f;
    *(s32*)(this_ + 0x254) = 0;
    *(s32*)(this_ + 0x258) = 0;
    *(s32*)(this_ + 0x25c) = -1;
    *(s32*)(this_ + 0x26c) = 0;
    this_[0x270] = 0;
    *(s32*)(this_ + 0x274) = 0;
    *(f32*)(this_ + 0x278) = 0.0f;
    *(f32*)(this_ + 0x27c) = 0.0f;
    *(f32*)(this_ + 0x280) = 0.0f;
    *(f32*)(this_ + 0x284) = 0.0f;
    *(f32*)(this_ + 0x288) = 0.0f;
    *(s32*)(this_ + 0x28c) = -1;
    *(f32*)(this_ + 0x290) = 0.0f;
    __construct_array(this_ + 0x2a8, (ConstructorDestructor)__ct__Q29JGeometry8TVec3_f_Fv, 0, 0xc, 6);
    *(s32*)(this_ + 0x2f0) = 0;
    *(s32*)(this_ + 0x310) = 0;
    *(s32*)(this_ + 0x314) = 0;
    fn_801D267C(this_ + 0x318);
    s32 j = 0;
    *(s32*)(this_ + 0x350) = 0;
    *(s32*)(this_ + 0x354) = 0;
    *(s32*)(this_ + 0x358) = 0;
    *(s32*)(this_ + 0x398) = 0;
    for (s32 i = 0; i < 7; i++, j += 4) {
        s32 zero = 0;
        s32 k = j + 0x35c;
        *(s32*)(this_ + k) = zero;
        if (i < 2) {
            k = j + 0x3b4;
            *(s32*)(this_ + k) = zero;
        }
        if (i < 3) {
            k = j + 0x378;
            *(s32*)(this_ + k) = zero;
        }
        if (i < 5) {
            k = j + 0x384;
            *(s32*)(this_ + k) = zero;
            k = j + 0x3ec;
            *(s32*)(this_ + k) = zero;
            k = j + 0x400;
            *(s32*)(this_ + k) = zero;
            k = j + 0x294;
            *(s32*)(this_ + k) = zero;
        }
        if (i < 6) {
            k = j + 0x3bc;
            *(s32*)(this_ + k) = zero;
            k = j + 0x3d4;
            *(s32*)(this_ + k) = zero;
            k = j + 0x39c;
            *(s32*)(this_ + k) = zero;
            k = j + 0x2f8;
            *(s32*)(this_ + k) = zero;
        }
    }
    fn_80458F9C(lbl_8053AF80, 0x3c);
    return this_;
}

extern "C" s32 fn_8036C8F4(void* this_) {
    return *(s32*)((char*)this_ + 0x240);
}


#include "JSystem/JAudio/JASFakeMatchFSA.h"
