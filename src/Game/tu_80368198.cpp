

#include "types.h"
#include "JSystem/JGeometry/Vec.h"
#include "dolphin/mtx.h"

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
struct Unk8036C300;
struct Vec3f {
    f32 x;
    f32 y;
    f32 z;
};
typedef void (Unk8036C300::*Unk8036C300Func)();
extern Unk8036C300Func lbl_804AE070[];
extern char lbl_804AE088[];
extern char lbl_8049CC34[];
extern "C" void __dt__13Base_8010E074Fv(void* this_, int how);
extern "C" void fn_8036A65C(void* this_);
extern "C" void fn_801F0E34(void* self, u32 msg, s32 flag);
extern "C" void fn_8010DF58(void* this_);
extern "C" void fn_803683AC(void* this_);
extern "C" void fn_8036A894(void* this_);
extern "C" void fn_8036AC58(void* this_, void* param);
extern "C" void fn_80368660(void* this_);
extern void* lbl_80474C48[];
extern void* lbl_8053AB10;
extern f32 lbl_80542C58;
extern f32 lbl_80542C6C;
extern f32 lbl_80542CC0;
extern "C" void PSMTXTrans(f32 m[3][4], f32 x, f32 y, f32 z);
extern "C" void fn_802F745C(void* mgr, f32* pos, void* tgt, EffArgs* args);

extern char lbl_80474C38[];
extern f32 lbl_80542CA4;
extern f32 lbl_80542CC4;
extern f32 lbl_80542CC8;
extern "C" void fn_8010F668(Mtx m, Vec3f* v, f32 f);
struct Obj8036C750 {
    u8 pad0[0x294];
    s32 a294[5];
    u8 pad2a8[0x2f8 - 0x2a8];
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
void fn_8036A894(u8* this_)
{
    EffArgs args;
    f32 mtx[3][4];
    JGeometry::TVec3<f32> pos;
    u8 i;

    if (*(s32*)(this_ + 0x24c) > 0) {
        args.f10.w = -1;
        args.f14.w = -1;
        for (i = 0; i < 0x10; i += 8) {
            args.order[i] = i;
            args.order[(u8)(i + 1)] = i + 1;
            args.order[(u8)(i + 2)] = i + 2;
            args.order[(u8)(i + 3)] = i + 3;
            args.order[(u8)(i + 4)] = i + 4;
            args.order[(u8)(i + 5)] = i + 5;
            args.order[(u8)(i + 6)] = i + 6;
            args.order[(u8)(i + 7)] = i + 7;
        }
        args.f14.w = 0;
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
        args.b1d = -1;
        args.f14.b[3] = *(u8*)(this_ + 0x24c);
        args.ptr = mtx;
        args.b2d = 1;
        pos = *(JGeometry::TVec3<f32>*)(this_ + 0xc);
        pos.z = 0.0f;
        if (*(s32*)(this_ + 4) < 8) {
            fn_802F745C(*(void**)((u8*)lbl_8053AB10 + 0x20), &pos.x, *(void**)(this_ + 0x310), &args);
        }
    }
}

extern "C" void fn_8036AA60(char* self) {
    extern void* fn_801902C0(void);
    char* tbl;
    Mtx m1;
    Mtx m2;
    Vec3f v1;
    Vec3f v2;
    char* entry;
    s32 cnt;
    s32 st;
    s32 idx;

    tbl = lbl_80474C38;
    PSMTXTrans(m1, *(f32*)(self + 0xc), *(f32*)(self + 0x10), *(f32*)(self + 0x14));
    v1.x = lbl_80542C58;
    v1.y = lbl_80542C6C;
    v1.z = lbl_80542C6C;
    fn_8010F668(m1, &v1, lbl_80542CC4);
    m2[2][3] = lbl_80542C6C;
    m2[1][3] = lbl_80542C6C;
    m2[0][3] = lbl_80542C6C;
    m2[2][2] = lbl_80542C6C;
    m2[1][2] = lbl_80542C6C;
    m2[0][2] = lbl_80542C6C;
    m2[2][1] = lbl_80542C6C;
    m2[1][1] = lbl_80542C6C;
    m2[0][1] = lbl_80542C6C;
    m2[2][0] = lbl_80542C6C;
    m2[1][0] = lbl_80542C6C;
    m2[0][0] = lbl_80542C6C;
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
        if (*(s32*)(self + 0x254) >= ((s32*)(tbl + 0x60))[st]) {
            *(s32*)(self + 0x254) = ((s32*)(tbl + 0x54))[st];
        }
        break;
    case 1:
        if (*(s32*)(self + 0x254) >= ((s32*)(tbl + 0x60))[1]) {
            *(s32*)(self + 0x244) = 2;
        }
        break;
    }

    cnt = *(s32*)(self + 0x254);
    idx = ((s32*)(tbl + 0x8c))[*(s32*)(self + 0x23c)];
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

extern "C" u8 fn_8036B018(u8* this_) {
    s32 v = *(s32*)(this_ + 0x240);
    if (v == 0x11 || v == 0x26) {
        return 1;
    }
    return 0;
}

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
    }
    *(JGeometry::TVec3<f32>*)(self + 0xc) = saved;
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
extern "C" void __construct_array(void*, void*, void*, long, long);
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
    __construct_array(this_ + 0x2a8, (void*)__ct__Q29JGeometry8TVec3_f_Fv, 0, 0xc, 6);
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
        *(s32*)(this_ + j + 0x35c) = 0;
        if (i < 2) {
            *(s32*)(this_ + j + 0x3b4) = 0;
        }
        if (i < 3) {
            *(s32*)(this_ + j + 0x378) = 0;
        }
        if (i < 5) {
            *(s32*)(this_ + j + 0x384) = 0;
            *(s32*)(this_ + j + 0x3ec) = 0;
            *(s32*)(this_ + j + 0x400) = 0;
            *(s32*)(this_ + j + 0x294) = 0;
        }
        if (i < 6) {
            *(s32*)(this_ + j + 0x3bc) = 0;
            *(s32*)(this_ + j + 0x3d4) = 0;
            *(s32*)(this_ + j + 0x39c) = 0;
            *(s32*)(this_ + j + 0x2f8) = 0;
        }
    }
    fn_80458F9C(lbl_8053AF80, 0x3c);
    return this_;
}

extern "C" s32 fn_8036C8F4(void* this_) {
    return *(s32*)((char*)this_ + 0x240);
}

void fn_8036C8FC(void)
{
  extern void __ct__17JASGenericMemPoolFv(void);
  extern void __register_global_object(void*, void*, void*);
  extern char __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr;

  if (__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr == 0) {
    __ct__17JASGenericMemPoolFv();
    __register_global_object(0, 0, 0);
  }
}
