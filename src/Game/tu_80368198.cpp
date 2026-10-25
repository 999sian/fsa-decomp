

#include "types.h"
#include "PowerPC_EABI_Support/Runtime/MWCPlusPlusLib.h"
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
extern "C" void* __nw__FUl(u32 size);
extern "C" void __ct__10J2DPictureFPC7ResTIMG(void* this_, void* res);
extern "C" void fn_8013B490(void* p);
extern "C" void fn_8011921C(void);
extern "C" void fn_801183BC(void);
extern void* lbl_8053AAF8;
extern char* lbl_8053A1C8;
extern void* sManager__8JUTVideo;
extern f32 lbl_80542C64;
extern f32 lbl_80542C68;
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

extern f32 lbl_80542C78;
extern "C" void fn_801F06F0(void* self, void* tbl, s32 idx, EffArgs* args, s32 n, f32 a, f32 b);
extern "C" void fn_8013CB44(void* obj, Vec3f* v, s32 a, s32 b, s32 c);
extern "C" void fn_80368660(void* this_) {
    char* self = (char*)this_;
    void* res;
    void* mgr;
    Vec3f* pos;
    Vec3f* vtx;
    Vec3f sum;
    Vec3f saved;
    EffArgs args;
    s32 idx;
    s32 room;
    s32 st;
    u8 i;

    args.f10.w = -1;
    args.f14.w = -1;
    for (i = 0; i < 0x10; i += 8) {
        args.order[i] = i;
        args.order[i + 1] = i + 1;
        args.order[i + 2] = i + 2;
        args.order[i + 3] = i + 3;
        args.order[i + 4] = i + 4;
        args.order[i + 5] = i + 5;
        args.order[i + 6] = i + 6;
        args.order[i + 7] = i + 7;
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
                if (*(s32*)(self + 0x264) > 5) {
                    *(s32*)(self + 0x264) = 0;
                }
            }
        } else if ((u32)(st - 0x1c) < 2 || st == 0x1e) {
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
                        if (*(s32*)(self + 0x264) > 5) {
                            *(s32*)(self + 0x264) = 0;
                        }
                    }
                }
            }
        } else if (st == 0x22 || st == 0x21) {
            if (*(s32*)(self + 0x260) == 0) {
                *(s32*)(self + 0x260) = 9;
                *(s32*)(self + 0x264) += 1;
                if (*(s32*)(self + 0x264) > 5) {
                    *(s32*)(self + 0x264) = 0;
                }
            }
        } else if (st == 0x23) {
            st = *(s32*)(self + 0x258);
            if (st < 0x50) {
                if (st < 0x46) {
                    if (st < 0x28) {
                        *(s32*)(self + 0x264) = 8;
                    } else {
                        *(s32*)(self + 0x264) = 10;
                    }
                } else {
                    *(s32*)(self + 0x264) = 0xb;
                }
            } else if (*(s32*)(self + 0x260) == 0) {
                *(s32*)(self + 0x260) = 9;
                *(s32*)(self + 0x264) += 1;
                if (*(s32*)(self + 0x264) > 5) {
                    *(s32*)(self + 0x264) = 0;
                }
            }
        }

        saved = *(Vec3f*)(self + 0xc);
        vtx = (Vec3f*)(self + 0x2a8);
        pos = (Vec3f*)(self + 0xc);
        for (i = 0; i < 5; i++) {
            st = *(s32*)(self + 0x240);
            if (st < 0x1c) {
                if (((s32*)(self + 0x294))[i] == 0) {
                    *pos = vtx[i];
                    pos->z = lbl_80542C78;
                    fn_801F06F0(self, lbl_80474C38 + 0x224,
                                *(s32*)(self + 0x264) + ((s32*)(lbl_80474C38 + 0x1a0))[i],
                                &args, 7, lbl_80542C58, lbl_80542C58);
                    if (((s32*)(self + 0x3bc))[i] != 0) {
                        sum.x = vtx[i].x + lbl_80542C6C;
                        sum.y = vtx[i].y + lbl_80542C6C;
                        sum.z = vtx[i].z + lbl_80542C78;
                        fn_8013CB44((void*)((s32*)(self + 0x3bc))[i], &sum, 0, -1, 1);
                    }
                    if (((s32*)(self + 0x3d4))[i] != 0) {
                        sum.x = vtx[i].x + lbl_80542C6C;
                        sum.y = vtx[i].y + lbl_80542C6C;
                        sum.z = vtx[i].z + lbl_80542C78;
                        fn_8013CB44((void*)((s32*)(self + 0x3d4))[i], &sum, 0, -1, 1);
                    }
                }
            } else if (st >= 0x21) {
                *pos = vtx[i];
                fn_801F06F0(self, lbl_80474C38 + 0x210,
                            *(s32*)(self + 0x264) + ((s32*)(lbl_80474C38 + 0x18c))[i],
                            &args, 7, lbl_80542C58, lbl_80542C58);
            } else {
                *pos = vtx[i];
                if (*(s32*)(self + 0x240) >= 0x1e && *(s32*)(self + 0x240) < 0x21) {
                    if (*(s32*)(self + 0x24c) < 0xc0 && *(s32*)(self + 0x138) == 0) {
                        fn_801EF830(*(s32*)(self + 0x4), pos, (u8*)&args, 7, (u8*)(lbl_80474C38 + 0x210),
                                    *(s32*)(self + 0x264) + ((s32*)(lbl_80474C38 + 0x18c))[i], 0);
                    }
                    args.f10.b[0] = 0xff;
                    args.f10.b[1] = 0xff;
                    args.f10.b[2] = 0xff;
                    args.f10.b[3] = 0xff - *(s32*)(self + 0x24c);
                    room = *(s32*)(self + 0x4);
                    idx = *(s32*)(self + 0x264) + ((s32*)(lbl_80474C38 + 0x18c))[i];
                    if (room < 8) {
                        mgr = *(void**)((char*)lbl_8053AAF8 + 0xa4);
                        res = ((void* (*)(void*, u32, char*))(*(void***)mgr)[6])(mgr, 0x534F4220, lbl_80474C38 + 0x210);
                        fn_802F86CC(*(void**)((char*)lbl_8053AB10 + 0x20), pos, res, idx, lbl_80542C58, lbl_80542C58, &args);
                    }
                    fn_803075AC(*(void**)(self + 0x198), *(s32*)(self + 0x4), pos,
                                *(s32*)(self + 0x264) + ((s32*)(lbl_80474C38 + 0x18c))[i], 0, 1, -1, 0, 0, 0);
                } else {
                    fn_801F06F0(self, lbl_80474C38 + 0x210,
                                *(s32*)(self + 0x264) + ((s32*)(lbl_80474C38 + 0x18c))[i],
                                &args, 7, lbl_80542C58, lbl_80542C58);
                }
            }
        }
        *pos = saved;
    }
}

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

extern "C" void fn_8036AC58(void* this_, void* param) {
    char* self = (char*)this_;
    EffArgs args;
    u8 i;
    if (*(u8*)(self + 0x270) != 1 || *(s32*)(self + 0x274) >= 0x80) {
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
        if (!(*(s32*)(self + 0x23c) == 5 && *(s32*)(self + 0x240) >= 0x1e && *(s32*)(self + 0x240) < 0x21)) {
            s32 id = *(s32*)(self + 0x240);
            if (id == 0x1c || (u32)(id - 0x1d) < 2 || (u32)(id - 0x21) < 2 || id == 0x23) {
                if (*(s32*)(self + 0x138) == 0) {
                    fn_801EF830(*(s32*)(self + 4), self + 0xc, args.order, 7, lbl_80474E48, *(s32*)(self + 0x264) + 0x1b3, 0);
                }
            } else if (*(s32*)(self + 0x138) == 0) {
                fn_801EF830(*(s32*)(self + 4), self + 0xc, args.order, 7, lbl_80474E48, (u32)param + *(s32*)(self + 0x328), 0);
            }
        } else {
            if (*(s32*)(self + 0x24c) < 0xc0 && *(s32*)(self + 0x138) == 0) {
                fn_801EF830(*(s32*)(self + 4), self + 0xc, args.order, 7, lbl_80474E48, (u32)param + *(s32*)(self + 0x328), 0);
            }
            args.f10.b[0] = 0xff;
            args.f10.b[1] = 0xff;
            args.f10.b[2] = 0xff;
            args.f10.b[3] = 0xff - *(s32*)(self + 0x24c);
        }
        {
            s32 id = *(s32*)(self + 0x240);
            if (id == 0x1c || (u32)(id - 0x1d) < 2 || (u32)(id - 0x21) < 2 || id == 0x23) {
                void* pos = self + 0xc;
                s32 idx = *(s32*)(self + 0x264) + 0x1b3;
                void* res;
                if (*(s32*)(self + 4) < 8) {
                    res = ((SobResMgr*)(*(void**)((u8*)lbl_8053AAF8 + 0xa4)))->vf18('SOB ', (const char*)lbl_80474E48);
                    fn_802F86CC(*(void**)((u8*)lbl_8053AB10 + 0x20), pos, res, idx, 1.0f, 1.0f, &args);
                }
                fn_803075AC(*(void**)(self + 0x198), *(s32*)(self + 4), self + 0xc, idx, 0, 1, -1, 0, 0, 0);
            } else {
                void* pos = self + 0xc;
                u32 idx = (u32)param + *(s32*)(self + 0x328);
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
    extern void fn_801D1F14(void* p);
    extern void fn_802D7440(void* mgr, s32 a);
    extern void* fn_802D6A9C(void);
    extern void* fn_801F856C(void);
    extern s32 fn_8013CC50(u32 id, void* p, f32 f, u32 a, u32 b, u32 c, u32 d, u32 e, u32 g);
    extern char lbl_8053A1C0;
    extern u8 sincosTable___5JMath[];
    extern f32 lbl_80542C58;
    extern f32 lbl_80542C6C;
    extern f32 lbl_80542C84;
    extern f32 lbl_80542C9C;
    extern f32 lbl_80542CBC;
    extern f32 lbl_80542CD0;
    extern f32 lbl_80542CD4;

    char* tbl = lbl_80474C38;
    char* self = (char*)this_;
    s32 i;
    u32* b;
    u16* a;
    Vec3f* pt;
    s32* dst;
    Vec3f pts[5];

    fn_8010DF98(this_);
    *(s32*)(self + 0x23c) = *(s32*)(self + 0x90) & 0x1f;
    *(s32*)(self + 0x248) = (*(u32*)(self + 0x90) >> 22) & 0x1f;
    if (*(s32*)(self + 0x23c) != 4 && *(s32*)(self + 0x23c) != 5) {
        detach__5ActorFv(this_);
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
        *(void**)(self + 0x310) = ((void* (*)(void*, u32, char*))(*(void***)sub)[6])(sub, 0x3f3f3f3f, str);
    }
    fn_801D2608(self + 0x318, &lbl_8053A1C0, 2);
    if (*(s32*)(self + 0x23c) == 6 || *(s32*)(self + 0x23c) >= 6 || *(s32*)(self + 0x23c) < 0) {
        fn_801D22DC(self + 0x318, 1, 2, 0);
    } else {
        fn_801D22DC(self + 0x318, 0, 2, 0);
    }
    fn_801D1F14(self + 0x318);
    *(f32*)(self + 0x10) = *(f32*)(self + 0x10) - lbl_80542C84;

    pts[0] = *(Vec3f*)(self + 0xc);
    pts[1].x = *(f32*)(self + 0x24) - lbl_80542CBC;
    pts[1].y = *(f32*)(self + 0x28) - lbl_80542C9C;
    pts[1].z = lbl_80542C6C;
    pts[2].x = *(f32*)(self + 0x24) + lbl_80542CBC;
    pts[2].y = *(f32*)(self + 0x28) - lbl_80542C9C;
    pts[2].z = lbl_80542C6C;
    pts[3].x = *(f32*)(self + 0x24) - lbl_80542CBC;
    pts[3].y = lbl_80542C9C + *(f32*)(self + 0x28);
    pts[3].z = lbl_80542C6C;
    pts[4].x = lbl_80542CBC + *(f32*)(self + 0x24);
    pts[4].y = lbl_80542C9C + *(f32*)(self + 0x28);
    pts[4].z = lbl_80542C6C;

    b = (u32*)(tbl + 0xb4);
    a = (u16*)(tbl + 0xa8);
    pt = pts;
    dst = (s32*)(self + 0x384);
    for (i = 0; i < 5; i++) {
        *dst = fn_8013CC50(*(u32*)(self + 0x4), pt, lbl_80542C58, *a, 0, *b, 0, 0, 1);
        dst++;
        pt++;
        a++;
        b++;
    }
    fn_802D7440(fn_802D6A9C(), 0);

    for (i = 0; i < 5; i++) {
        s16 ang = *(s16*)(tbl + 0x6c + i * 2);
        f32* sc = (f32*)(sincosTable___5JMath + ((u16)ang >> 5) * 8);
        Vec3f* out = (Vec3f*)(self + 0x2a8);
        out[i].x = *(f32*)(self + 0xc) + lbl_80542CD4 * sc[1];
        out[i].y = lbl_80542C84 + (*(f32*)(self + 0x10) + lbl_80542CD0 * sc[0]);
        out[i].z = lbl_80542C6C;
    }
    *(Vec3f*)(self + 0x2e4) = *(Vec3f*)(self + 0xc);

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


#include "JSystem/JAudio/JASFakeMatchFSA.h"
