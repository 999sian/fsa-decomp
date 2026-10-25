#include "types.h"
#include "JSystem/J2D/J2DPicture.h"

struct FsaVObj {
    virtual void v0(void);
    virtual void v1(void);
    virtual void v2(void);
    virtual void v3(void);
    virtual void v4(u32 a, void* b);
    virtual void v5(void);
    virtual void v6(u32 a, void* b);
    virtual void v9(u8 b);
    virtual void v10(void);
    virtual void v11(void);
    virtual void v12(void);
    virtual void v13(void);
    virtual void v14(void);
    virtual void v15(void);
    virtual void v16(void);
    virtual void v17(void);
    virtual void v18(void);
    virtual void v19(void);
    virtual void v20(void);
    virtual void v21(void);
    virtual void v22(void);
    virtual void v23(void);
    virtual void v24(void);
    virtual void v25(void);
    virtual void v26(void);
    virtual void v27(void);
    virtual void v28(void);
    virtual void v29(void);
    virtual void v30(void);
    virtual void v31(void);
    virtual void v32(void);
    virtual void v33(void);
    virtual void v34(void);
    virtual void v35(void);
    virtual void v36(void);
    virtual void v37(void);
    virtual void v38(void);
    virtual void v39(void);
    virtual void v40(void);
    virtual void v41(void);
    virtual void v42(void);
    virtual void v43(void);
    virtual void v44(void);
    virtual void v45(void);
    virtual void v46(void);
    virtual void v47(void);
    virtual void v48(void);
    virtual void v49(void);
    virtual void v50(void);
    virtual void v51(void);
    virtual void v52(void);
    virtual void v53(void);
    virtual void v54(void);
    virtual void v55(void);
    virtual void v56(void);
    virtual void v57(void);
    virtual void v58(void);
    virtual void v59(s32 a, s32 b, s32 c, f32 d, f32 e, f32 f, f32 g);
    virtual void v60(void);
    virtual void v61(void);
    virtual void v62(void);
    virtual void v63(void);
    virtual void v64(void);
    virtual void v65(void);
    virtual void v66(void);
    virtual void v67(void);
    virtual void v68(void);
    virtual void v69(void);
    virtual void v70(void);
    virtual void v71(void);
    virtual void v72(void);
    virtual void v73(void);
    virtual void v74(void);
    virtual void v75(void);
    virtual void v76(u32* a, u32* b);
};

extern "C" void fn_8013B490(void* this_);
extern u8 lbl_80529DEC[];
extern void* lbl_8053AB10;
extern u8 lbl_8050DB0C[];
extern void* lbl_8053AD68;
extern "C" void fn_80128C58(s32 val);
extern "C" void fn_8013A884(u32* color);
extern "C" void fn_803B7DCC(u8* this_) {
    if (*(s32*)(lbl_80529DEC + 0x118) != 8 || *(s32*)(lbl_80529DEC + 0x11c) != 3) {
        fn_8013B490(lbl_8053AB10);
        FsaVObj* obj = *(FsaVObj**)(this_ + 4);
        obj->v9(this_[0x296]);
        obj = *(FsaVObj**)(this_ + 4);
        obj->v59(0, 0, 0, 0.0f, 0.0f, 800.0f, 640.0f);
    }
}

extern "C" void* lbl_8053AB10;
extern "C" void* lbl_8053ADC8;
extern "C" void* sManager__8JUTVideo;
extern "C" void fn_8013B414(void* this_, f32* rect, s32 n);
extern "C" void fn_803B7E64(u8* this_) {
    f32 rect[4];
    FsaVObj* obj;
    u8* video;
    u16 w;
    u16 h;

    fn_8013B490(lbl_8053AB10);
    if (this_[0x294] == 3 || this_[0x294] == 4) {
        ((u8*)lbl_8053ADC8)[0x20] = 1;
        ((u8*)lbl_8053ADC8)[0x21] = 2;
    }
    obj = *(FsaVObj**)(this_ + 4);
    obj->v9(this_[0x296]);
    obj = *(FsaVObj**)(this_ + 4);
    obj->v59(0, 0, 0, 0.0f, 0.0f, 800.0f, 640.0f);
    video = *(u8**)((u8*)sManager__8JUTVideo + 4);
    h = *(u16*)(video + 6);
    w = *(u16*)(video + 4);
    rect[0] = 0.0f;
    rect[1] = 0.0f;
    rect[2] = (f32)(s32)w;
    rect[3] = (f32)(s32)h;
    fn_8013B414(lbl_8053AB10, rect, 1);
}

extern "C" void fn_803B7F6C(u8* this_) {
    switch (this_[0x294]) {
    case 0:
        *(s32*)(this_ + 0x280) -= 1;
        if (*(s32*)(this_ + 0x280) == 0) {
            this_[0x294] = 1;
        }
        break;
    case 1:
        this_[0x296] += 2;
        if (this_[0x296] >= 0xfe) {
            this_[0x296] = 0xff;
            this_[0x294] = 2;
            this_[0x295] = 1;
            if (*(s32*)(lbl_80529DEC + 0x118) < 8) {
                *(s32*)(this_ + 0x284) = *(s32*)(lbl_80529DEC + 0x118);
            } else {
                *(s32*)(this_ + 0x284) = 0;
            }
            if (*(s32*)(lbl_80529DEC + 0x11c) < 4) {
                *(s32*)(this_ + 0x288) = *(s32*)(lbl_80529DEC + 0x11c);
            } else {
                *(s32*)(this_ + 0x288) = 0;
            }
            *(u8*)(*(u8**)((u8*)lbl_8053AB10 + 0x20) + 0x235c) = 0;
            *(u8*)(*(u8**)((u8*)lbl_8053AB10 + 0x20) + 0x235d) = 0;
            *(u8*)(*(u8**)((u8*)lbl_8053AB10 + 0x20) + 0x235e) = 0;
            *(u8*)(*(u8**)((u8*)lbl_8053AB10 + 0x20) + 0x235f) = 0;
            fn_80128C58(0xff);
            u32 color = 0xffffff00;
            fn_8013A884(&color);
        }
        break;
    case 2:
        switch (this_[0x295]) {
        case 1:
            *(s32*)(this_ + 0x280) -= 1;
            if (*(s32*)(this_ + 0x280) > 0) {
                *(s32*)(this_ + 0x280) = *(s16*)(lbl_8050DB0C + 0x80);
                this_[0x295] = 2;
                this_[0x29b] = 1;
            }
            break;
        case 0:
            break;
        default:
            break;
        }
        break;
    case 3:
        *(s32*)(this_ + 0x280) -= 1;
        if (*(s32*)(this_ + 0x280) <= 0) {
            *(s32*)(this_ + 0x280) = 0x3c;
        }
        break;
    case 4:
        *(s32*)(this_ + 0x280) -= 1;
        if (*(s32*)(this_ + 0x280) <= 0) {
            *(s32*)(this_ + 0x280) = 0x3c;
        }
        break;
    case 6:
        if (this_[0x296] >= 0xf5) {
            this_[0x296] = 0xff;
            this_[0x294] = 5;
        } else {
            this_[0x296] += 0xa;
        }
        break;
    case 5:
        if (this_[0x296] <= 0xa) {
            this_[0x296] = 0;
            *(u8*)((u8*)lbl_8053AD68 + 0x1d) = 1;
        } else {
            this_[0x296] -= 0xa;
        }
        break;
    }
}

extern "C" void fn_8013A884(u32* color);
extern "C" void fn_80128C58(s32 val);
extern "C" void fn_80458F9C(void* obj, s32 a);
extern "C" void fn_80458FF0(void* obj, s32 id, s32 a, s32 b);
extern void* lbl_8053AF80;
extern "C" void fn_803B8188(u8* this_) {
    this_[0x296] = 0;
    *(s32*)(this_ + 0x1a0) = 0;
    *(s32*)(this_ + 0x1a4) = 0;
    *(s32*)(this_ + 0x1a8) = 0;
    *(s32*)(this_ + 0x1ac) = 0;
    *(s32*)(this_ + 0x1b8) = 0;
    *(s32*)(this_ + 0x1bc) = 0;
    *(s32*)(this_ + 0x284) = 0;
    *(s32*)(this_ + 0x288) = 0;
    *(s32*)(this_ + 0x198) = 0;
    *(s32*)(this_ + 0x19c) = 0;
    *(u16*)(this_ + 0x1dc) = 0;
    *(s32*)(this_ + 0x1c0) = 0;
    *(s32*)(this_ + 0x1c4) = 0;
    *(s32*)(this_ + 0x1c8) = 0;
    *(s32*)(this_ + 0x1cc) = 0;
    *(s32*)(this_ + 0x1d0) = -1;
    *(s32*)(this_ + 0x1d4) = -1;
    *(s32*)(this_ + 0x1d8) = -1;
    this_[0x297] = 0;
    this_[0x298] = 0;
    this_[0x29b] = 0;
    this_[0x29c] = 0;
    this_[0x29d] = 0;
    this_[0x29e] = 0;
    this_[0x29f] = 0;
    if (*(s32*)(lbl_80529DEC + 0x118) < 8) {
        *(s32*)(this_ + 0x284) = *(s32*)(lbl_80529DEC + 0x118);
    } else {
        *(s32*)(this_ + 0x284) = 0;
    }
    if (*(s32*)(lbl_80529DEC + 0x11c) < 4) {
        *(s32*)(this_ + 0x288) = *(s32*)(lbl_80529DEC + 0x11c);
    } else {
        *(s32*)(this_ + 0x288) = 0;
    }
    this_[0x294] = 5;
    this_[0x295] = 1;
    *(s32*)(this_ + 0x280) = 0x80;
    if (*(s32*)(lbl_80529DEC + 0x118) == 7 && *(s32*)(lbl_80529DEC + 0x11c) == 3) {
        fn_80458F9C(lbl_8053AF80, 0x3c);
    } else {
        fn_80458FF0(lbl_8053AF80, 0x100002f, 1, 0);
    }
    *(u8*)(*(u8**)((u8*)lbl_8053AB10 + 0x20) + 0x235c) = 0;
    *(u8*)(*(u8**)((u8*)lbl_8053AB10 + 0x20) + 0x235d) = 0;
    *(u8*)(*(u8**)((u8*)lbl_8053AB10 + 0x20) + 0x235e) = 0;
    *(u8*)(*(u8**)((u8*)lbl_8053AB10 + 0x20) + 0x235f) = 0;
    fn_80128C58(0xff);
    u32 color = 0xffffff00;
    fn_8013A884(&color);
}

struct FsaSubObj {
    virtual void v00(s32 b);
    virtual void v01(void);
    virtual void v02(void);
    virtual void v03(void);
    virtual void v04(void);
    virtual void v05(void);
    virtual void v06(void);
    virtual void v07(void);
    virtual void v08(void);
    virtual void v09(void);
    virtual void v10(s32 b);
};

extern "C" void __dl__FPv(void* this_);
extern "C" void* fn_8013C824(void);
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void* mgr, void* p);
extern "C" void getTotalFreeSize__7JKRHeapFv(void* heap);
extern "C" char lbl_804AFAB0[];
extern "C" s32 lbl_8053ADA8;
extern "C" void* fn_803B82FC(void* this_, s16 flag) {
    void** p;
    s32 i;
    void** a = (void**)this_;
    if (a != 0) {
        p = a;
        *a = lbl_804AFAB0;
        for (i = 0; i < 50; i++) {
            if (p[9] != 0) {
                void* mgr = *(void**)((char*)fn_8013C824() + 0xc);
                forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(mgr, p[9]);
                p[9] = 0;
            }
            p++;
        }
        getTotalFreeSize__7JKRHeapFv(*(void**)(lbl_80529DEC + 0x8));
        FsaSubObj* p1 = (FsaSubObj*)a[1];
        if (p1 != 0) {
            p1->v00(1);
        }
        a[1] = 0;
        FsaSubObj* p7 = (FsaSubObj*)a[7];
        if (p7 != 0) {
            p7->v10(1);
        }
        a[7] = 0;
        FsaSubObj* p8 = (FsaSubObj*)a[8];
        if (p8 != 0) {
            p8->v10(1);
        }
        a[8] = 0;
        lbl_8053ADA8 = 0;
        if (flag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void __ct__Q29JGeometry8TVec3_f_Fv(void);
extern "C" void* __nw__FUl(u32 size);
extern "C" void* fn_804030C4(u32 type, const char* name);
extern "C" void __ct__10J2DPictureFPC7ResTIMG(void* self, const void* res);
extern "C" void fn_8045B46C(void* self, s32 a, s32 b, s32 c, s32 d);
extern "C" void __ct__14WaveControllerFlll(void* self, void* a, s32 b, s32 c);
extern u8 lbl_80476520[];
extern u8 lbl_80476534[];
extern void* lbl_8053AAF8;
extern const f32 lbl_80543440;
static inline void* createSoundController() {
    void* controller = __nw__FUl(0x60);
    if (controller != 0) {
        fn_8045B46C(controller, 0, 0, 0, 8);
    }
    return controller;
}

static inline void* createWaveController(void* pos) {
    void* controller = __nw__FUl(0x5c);
    if (controller != 0) {
        __ct__14WaveControllerFlll(controller, pos, 0, 8);
    }
    return controller;
}

extern "C" void* fn_803B8414(u8* this_) {
    int i;
    void* res;
    void* pic;
    u8* tbl;
    *(void**)this_ = lbl_804AFAB0;
    __construct_array(this_ + 0xf8, (void*)__ct__Q29JGeometry8TVec3_f_Fv, 0, 0xc, 0xa);
    *(s32*)(this_ + 0x28c) = -1;
    *(s32*)(this_ + 0x290) = -1;
    getTotalFreeSize__7JKRHeapFv(*(void**)(lbl_80529DEC + 0x8));
    lbl_8053ADA8 = (s32)this_;
    FsaVObj* obj = *(FsaVObj**)((u8*)lbl_8053AAF8 + 0xa8);
    obj->v4(0x3f3f3f3f, lbl_80476520);
    for (i = 0; i < 0x32; i++) {
        *(s32*)(this_ + i * 4 + 0x24) = 0;
    }
    res = fn_804030C4(0x54494d47, (const char*)lbl_80476534);
    pic = new J2DPicture((const ResTIMG*)res);
    *(void**)(this_ + 0x4) = pic;
    ((J2DPicture*)*(void**)(this_ + 4))->setBlackWhite(JUtility::TColor(0xff), JUtility::TColor(0));
    *(f32*)(this_ + 0xec) = lbl_80543440;
    *(f32*)(this_ + 0xf0) = lbl_80543440;
    *(f32*)(this_ + 0xf4) = lbl_80543440;
    pic = __nw__FUl(0x60);
    if (pic != 0) {
        fn_8045B46C(pic, 0, 0, 0, 8);
    }
    *(void**)(this_ + 0x1c) = pic;
    pic = __nw__FUl(0x5c);
    if (pic != 0) {
        __ct__14WaveControllerFlll(pic, this_ + 0xec, 0, 8);
    }
    *(void**)(this_ + 0x20) = pic;
    tbl = lbl_80529DEC;
    *(f32*)(this_ + 0xf8) = lbl_80543440;
    *(f32*)(this_ + 0xfc) = lbl_80543440;
    *(f32*)(this_ + 0x100) = lbl_80543440;
    *(s32*)(this_ + 0x170) = -1;
    *(f32*)(this_ + 0x104) = lbl_80543440;
    *(f32*)(this_ + 0x108) = lbl_80543440;
    *(f32*)(this_ + 0x10c) = lbl_80543440;
    *(s32*)(this_ + 0x174) = -1;
    *(f32*)(this_ + 0x110) = lbl_80543440;
    *(f32*)(this_ + 0x114) = lbl_80543440;
    *(f32*)(this_ + 0x118) = lbl_80543440;
    *(s32*)(this_ + 0x178) = -1;
    *(f32*)(this_ + 0x11c) = lbl_80543440;
    *(f32*)(this_ + 0x120) = lbl_80543440;
    *(f32*)(this_ + 0x124) = lbl_80543440;
    *(s32*)(this_ + 0x17c) = -1;
    *(f32*)(this_ + 0x128) = lbl_80543440;
    *(f32*)(this_ + 0x12c) = lbl_80543440;
    *(f32*)(this_ + 0x130) = lbl_80543440;
    *(s32*)(this_ + 0x180) = -1;
    *(f32*)(this_ + 0x134) = lbl_80543440;
    *(f32*)(this_ + 0x138) = lbl_80543440;
    *(f32*)(this_ + 0x13c) = lbl_80543440;
    *(s32*)(this_ + 0x184) = -1;
    *(f32*)(this_ + 0x140) = lbl_80543440;
    *(f32*)(this_ + 0x144) = lbl_80543440;
    *(f32*)(this_ + 0x148) = lbl_80543440;
    *(s32*)(this_ + 0x188) = -1;
    *(f32*)(this_ + 0x14c) = lbl_80543440;
    *(f32*)(this_ + 0x150) = lbl_80543440;
    *(f32*)(this_ + 0x154) = lbl_80543440;
    *(s32*)(this_ + 0x18c) = -1;
    *(f32*)(this_ + 0x158) = lbl_80543440;
    *(f32*)(this_ + 0x15c) = lbl_80543440;
    *(f32*)(this_ + 0x160) = lbl_80543440;
    *(s32*)(this_ + 0x190) = -1;
    *(f32*)(this_ + 0x164) = lbl_80543440;
    *(f32*)(this_ + 0x168) = lbl_80543440;
    *(f32*)(this_ + 0x16c) = lbl_80543440;
    *(s32*)(this_ + 0x194) = -1;
    if (*(s32*)(tbl + 0x118) == 9 && *(s32*)(tbl + 0x11c) == 3) {
        *(s32*)(tbl + 0x118) = 7;
        *(s32*)(tbl + 0x11c) = 3;
    }
    return this_;
}

struct SlotVt {
    virtual void m0(void);
    virtual void m1(void);
    virtual void m2(int);
    virtual void m3(void);
    virtual void m4(void);
    virtual void m5(void);
    virtual void m6(void);
    virtual void m7(void);
    virtual void m8(void);
    virtual void m9(void);
    virtual void m10(void);
    virtual void m11(void);
    virtual void m12(int);
};
