#include "types.h"
#include "JSystem/J2D/J2DScreen.h"
#include "JSystem/J2D/J2DPicture.h"

struct TResMgr {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void* get(u32 type, const char* name);
};

extern "C" u8 lbl_80529DEC[];
extern "C" char lbl_80475F58[];
extern "C" u8* lbl_8053AAF8;
extern "C" u8* lbl_8053AB10;
extern "C" u8* lbl_8053AF80;
extern "C" f32 lbl_805432E0;
extern "C" void fn_802FF798(void* mgr);
extern "C" void fn_802F9714(void* mgr, void* res, s32 a, s32 b, s32 c, s32 d);
extern "C" void fn_802F93F4(void* mgr, void* res, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void fn_8016ED88(u8* self);
extern "C" void fn_80458FF0(void* obj, u32 id, s32 a, s32 b);


extern "C" u8* lbl_8053AD88;
extern "C" s32 fn_803A3484(void) {
    if (lbl_8053AD88 != 0) {
        return *(s32*)(lbl_8053AD88 + 0x154);
    }
    return 1;
}

extern "C" u8* sManager__10JFWDisplay;
extern "C" void fn_8013B438(void* p);
extern "C" void fn_8013B490(void* p);
extern "C" void fn_80427D2C(void* p, s32 a, s32 b, s32 c, s32 d);
extern "C" void fn_803A44D8(u8* this_) {
    u8 col[4] = {0, 0, 0, 0};
    u8 copy[4];
    *(u32*)copy = *(u32*)col;
    sManager__10JFWDisplay[8] = copy[0];
    sManager__10JFWDisplay[9] = copy[1];
    sManager__10JFWDisplay[10] = copy[2];
    sManager__10JFWDisplay[11] = copy[3];
    if (*(s32*)(lbl_80529DEC + 0x1a0) > 0) {
        *(s32*)(lbl_80529DEC + 0x1a0) -= 1;
    } else {
        *(s32*)(lbl_80529DEC + 0x1a0) = 0;
    }
    if (*(s16*)(this_ + 0x6c) != 0) {
        fn_8013B438(lbl_8053AB10);
        fn_80427D2C(*(void**)(this_ + 0x48), 0, 0, 0, 0);
    }
}

extern "C" void fn_803A5380(u8* this_) {
    char* base = lbl_80475F58;
    if (lbl_80529DEC[0x242] == 0) {
        lbl_80529DEC[0x242] = 1;
        fn_802FF798(*(void**)(lbl_8053AB10 + 0x20));
        void* res = ((TResMgr*)*(void**)(lbl_8053AAF8 + 0xa4))->get(0x53434820, base + 0xfc);
        fn_802F9714(*(void**)(lbl_8053AB10 + 0x20), res, 0, 0, 0, 0);
        res = ((TResMgr*)*(void**)(lbl_8053AAF8 + 0xa4))->get(0x53434820, base + 0x114);
        fn_802F9714(*(void**)(lbl_8053AB10 + 0x20), res, 0, 0, 0x7000, 0);
        res = ((TResMgr*)*(void**)(lbl_8053AAF8 + 0xa4))->get(0x53434c20, base + 0x12c);
        fn_802F93F4(*(void**)(lbl_8053AB10 + 0x20), res, 0, 0, 0, 0, 0);
        res = ((TResMgr*)*(void**)(lbl_8053AAF8 + 0xa4))->get(0x53434820, base + 0x144);
        fn_802F9714(*(void**)(lbl_8053AB10 + 0x20), res, 0, 2, 0x4000, 0);
        res = ((TResMgr*)*(void**)(lbl_8053AAF8 + 0xa4))->get(0x53434c20, base + 0x12c);
        fn_802F93F4(*(void**)(lbl_8053AB10 + 0x20), res, 0, 2, 0, 0, 0);
        res = ((TResMgr*)*(void**)(lbl_8053AAF8 + 0xa4))->get(0x53434820, base + 0x154);
        fn_802F9714(*(void**)(lbl_8053AB10 + 0x20), res, 0, 3, 0, 0);
        res = ((TResMgr*)*(void**)(lbl_8053AAF8 + 0xa4))->get(0x53434c20, base + 0x12c);
        fn_802F93F4(*(void**)(lbl_8053AB10 + 0x20), res, 0, 3, 0, 0, 0);
        *(u8*)(*(u8**)(lbl_8053AB10 + 0x20) + 0x2364) = 1;
    }
    *(s32*)(this_ + 0x154) = 1;
    this_[0x14c] = 0;
    *(f32*)(this_ + 0x50) = 0.0f;
    *(f32*)(this_ + 0x4c) = 0.0f;
    *(s16*)(this_ + 0x6e) = 0;
    *(s16*)(this_ + 0x72) = 0;
    *(s16*)(this_ + 0x7a) = 0;
    *(s16*)(this_ + 0x7e) = 0;
    this_[0x14d] = 0;
    *(s16*)(this_ + 0x74) = 0;
    *(s16*)(this_ + 0x76) = 0;
    *(s16*)(this_ + 0x78) = 0;
    *(s32*)(this_ + 0x60) = 0;
    *(s32*)(this_ + 0x64) = 0;
    *(s16*)(this_ + 0x6c) = 0;
    *(s32*)(this_ + 0x5c) = 0;
    *(s16*)(this_ + 0x7c) = 0;
    *(s16*)(this_ + 0x80) = 0;
    *(s16*)(this_ + 0x82) = 0x3c;
    *(s32*)(this_ + 0x54) = 0;
    if (lbl_80529DEC[0x249] != 0) {
        *(s16*)(this_ + 0x68) = 0;
    } else {
        *(s16*)(this_ + 0x68) = 0xff;
    }
    *(s16*)(this_ + 0x6a) = 0;
    this_[0x150] = 0;
    *(s32*)(this_ + 0x84) = 0x78;
    *(s32*)(this_ + 0x88) = 0x3c;
    this_[0x8c] = 1;
    fn_8016ED88(this_ + 0x90);
    if (lbl_80529DEC[0x249] != 0) {
        if (*(u32*)(lbl_8053AF80 + 0x58) != 0x1000006) {
            fn_80458FF0(lbl_8053AF80, 0x1000006, 0, 0);
        }
        *(s16*)(this_ + 0x82) = 0x3c;
    }
}

extern "C" u8 lbl_804AF820[];
extern "C" u8 lbl_80529DEC[];
extern "C" void* fn_8013C824(void);
extern "C" void fn_80427D94(void*);
extern "C" void getTotalFreeSize__7JKRHeapFv(void*);
extern "C" void destroy__7JKRHeapFv(void*);
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void* mgr, void* em);
extern "C" void forceDeleteAllEmitter__17JPAEmitterManagerFv(void* mgr);
struct TDelObj {
    virtual ~TDelObj();
};
struct TPadBase8 {
    u8 pad[8];
};
struct TSlotObj : TPadBase8 {
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
    virtual void m10(s32);
};
struct TSysObj {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
};
#pragma opt_common_subs off
extern "C" u8* fn_803A56C4(u8* p, s16 n) {
    if (p != NULL) {
        *(void**)p = lbl_804AF820;
        getTotalFreeSize__7JKRHeapFv(*(void**)(lbl_80529DEC + 0x8));
        for (s32 i = 0; i < 4; i++) {
            TSlotObj* obj = *(TSlotObj**)(p + i * 0x1c + 0xa8);
            if (obj != NULL) {
                if (obj != NULL) {
                    obj->m10(1);
                }
            }
        }
        if (*(s16*)(p + 0x6c) != 0) {
            fn_80427D94(*(void**)(p + 0x48));
            *(s16*)(p + 0x6c) = 0;
        }
        for (s32 i = 0; i < 3; i++) {
            if (*(void**)(p + 0x28 + i * 4) != NULL) {
                forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((u8*)fn_8013C824() + 0xc), *(void**)(p + 0x28 + i * 4));
                *(void**)(p + 0x28 + i * 4) = NULL;
            }
        }
        for (s32 i = 0; i < 4; i++) {
            if (*(void**)(p + 0x34 + i * 4) != NULL) {
                forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((u8*)fn_8013C824() + 0xc), *(void**)(p + 0x34 + i * 4));
                *(void**)(p + 0x34 + i * 4) = NULL;
            }
        }
        if (*(void**)(p + 0x44) != NULL) {
            forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((u8*)fn_8013C824() + 0xc), *(void**)(p + 0x44));
            *(void**)(p + 0x44) = NULL;
        }
        forceDeleteAllEmitter__17JPAEmitterManagerFv(*(void**)((u8*)fn_8013C824() + 0xc));
        destroy__7JKRHeapFv(*(void**)(p + 0x100));
        delete *(TDelObj**)(p + 0x4);
        *(void**)(p + 0x4) = NULL;
        delete *(TDelObj**)(p + 0x24);
        *(void**)(p + 0x24) = NULL;
        delete *(TDelObj**)(p + 0x8);
        *(void**)(p + 0x8) = NULL;
        delete *(TDelObj**)(p + 0x48);
        *(void**)(p + 0x48) = NULL;
        delete *(TDelObj**)(p + 0xc);
        *(void**)(p + 0xc) = NULL;
        delete *(TDelObj**)(p + 0x10);
        *(void**)(p + 0x10) = NULL;
        delete *(TDelObj**)(p + 0x14);
        *(void**)(p + 0x14) = NULL;
        delete *(TDelObj**)(p + 0x18);
        *(void**)(p + 0x18) = NULL;
        delete *(TDelObj**)(p + 0x1c);
        *(void**)(p + 0x1c) = NULL;
        delete *(TDelObj**)(p + 0x20);
        *(void**)(p + 0x20) = NULL;
        (*(TSysObj**)(lbl_80529DEC + 0x24))->m7();
        lbl_8053AD88 = NULL;
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}
#pragma opt_common_subs reset
extern "C" u32 lbl_804AF7D8[][3];
extern "C" u8* sCurrentHeap__7JKRHeap;
extern "C" void fn_8016FDE0(void);
extern "C" void* fn_80428030(void* this_ = 0);
extern "C" void* __nw__FUl(u32 size);
extern "C" void __construct_array(void* ptr, void* ctor, void* dtor, u32 size, u32 n);
extern "C" void __ct__9J2DScreenFv(void* self);
extern "C" void __ct__10J2DPictureFPC7ResTIMG(void* self, const void* res);
extern "C" void __ct__14WaveControllerFlll(void* self, s32 a, s32 b, s32 c);
extern "C" void getTotalFreeSize__7JKRHeapFv(void* heap);
extern "C" void setPriority__9J2DScreenFPCcUlP10JKRArchive(void* self, const char* name, u32 a, void* archive);
extern "C" void* getGlbResource__13JKRFileLoaderFPCcP13JKRFileLoader(const char* name, void* loader);
extern "C" void* load__20J2DAnmLoaderDataBaseFPCv(const void* res);
extern "C" void* fn_80403204(u32 type, const char* name);
extern "C" void* fn_80403244(u32 type, const char* name);
extern "C" void* fn_804030C4(u32 type, const char* name);
extern "C" void* create__12JKRSolidHeapFUlP7JKRHeapb(u32 size, void* parent, s32 align);
extern "C" void becomeCurrentHeap__7JKRHeapFv(void* heap);
extern "C" void adjustSize__12JKRSolidHeapFv(void* heap);
extern "C" void fn_8016A3BC(void* archive, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, void* heap, void* p0, void* p1, u32 g, void* p2, u32 h);
static inline void* tuNewObj1c() {
    void* p = __nw__FUl(0x1c);
    if (p != NULL) {
        fn_80428030(p);
    }
    return p;
}
struct TObj1c {
    TObj1c() { fn_80428030(this); }
    u8 pad[0x1c];
};
struct WaveController {
    WaveController(long a, long b, long c);
    u8 pad[0x5c];
};

extern "C" u8* fn_803A59E0(u8* self) {
    void* tmp;
    char* names = lbl_80475F58;
    *(void**)self = lbl_804AF820;
    __construct_array(self + 0x90, (void*)fn_8016FDE0, NULL, 0x1c, 4);
    getTotalFreeSize__7JKRHeapFv(*(void**)(lbl_80529DEC + 0x8));
    lbl_8053AD88 = self;
    *(J2DScreen**)(self + 0x4) = new J2DScreen();
    u8* tbl = lbl_80529DEC;
    setPriority__9J2DScreenFPCcUlP10JKRArchive(*(void**)(self + 0x4), names + 0x164, 0x1100000, *(void**)(tbl + 0x24));
    *(void**)(self + 0x24) = load__20J2DAnmLoaderDataBaseFPCv(getGlbResource__13JKRFileLoaderFPCcP13JKRFileLoader(names + 0x170, *(void**)(tbl + 0x24)));
    (*(J2DScreen**)(self + 0x4))->setAnimation(*(J2DAnmTextureSRTKey**)(self + 0x24));
    (*(J2DScreen**)(self + 0x4))->search(0x50636d61726bULL)->hide();
    self[0x14e] = (*(J2DScreen**)(self + 0x4))->search(0x7072737374727431ULL)->getAlpha();
    self[0x14f] = (*(J2DScreen**)(self + 0x4))->search(0x7072737374727432ULL)->getAlpha();

    tmp = fn_80403204(0x54494d47, names + 0x17c);
    *(J2DPicture**)(self + 0x8) = new J2DPicture((const ResTIMG*)tmp);
    *(TObj1c**)(self + 0x48) = new TObj1c();
    tmp = fn_80403244(0x54494d47, names + 0x190);
    *(J2DPicture**)(self + 0xc) = new J2DPicture((const ResTIMG*)tmp);
    tmp = fn_80403244(0x54494d47, names + 0x1a8);
    *(J2DPicture**)(self + 0x10) = new J2DPicture((const ResTIMG*)tmp);
    tmp = fn_80403244(0x54494d47, names + 0x1c0);
    *(J2DPicture**)(self + 0x14) = new J2DPicture((const ResTIMG*)tmp);
    tmp = fn_80403244(0x54494d47, names + 0x1d4);
    *(J2DPicture**)(self + 0x18) = new J2DPicture((const ResTIMG*)tmp);
    tmp = fn_80403244(0x54494d47, names + 0x1e8);
    *(J2DPicture**)(self + 0x1c) = new J2DPicture((const ResTIMG*)tmp);
    tmp = fn_804030C4(0x54494d47, names + 0x1fc);
    *(J2DPicture**)(self + 0x20) = new J2DPicture((const ResTIMG*)tmp);
    (*(J2DPicture**)(self + 0x20))->setBlackWhite(JUtility::TColor(0x08, 0x18, 0x28, 0xff), JUtility::TColor(0, 0, 0, 0));

    if (lbl_80529DEC[0x249] != 0) {
        *(s16*)(self + 0x68) = 0;
    } else {
        *(s16*)(self + 0x68) = 0xff;
    }
    self[0x150] = 0;
    tmp = sCurrentHeap__7JKRHeap;
    *(void**)(self + 0x100) = create__12JKRSolidHeapFUlP7JKRHeapb(0x80000, tmp, 0);
    becomeCurrentHeap__7JKRHeapFv(*(void**)(self + 0x100));

    for (s32 i = 0; i < 6; i++) {
        fn_8016A3BC(*(void**)(tbl + 0x24), lbl_804AF7D8[i][0], lbl_804AF7D8[i][1], 0, lbl_804AF7D8[i][2], 0, 0x10240000, *(void**)(self + 0x100),
                    self + 0x104 + i * 4, self + 0x11c + i * 4, 0, self + 0x134 + i * 4, 0);
        if (*(void**)(self + 0x11c + i * 4) != NULL) {
            *(f32*)(*(u8**)(self + 0x11c + i * 4) + 0x8) = 0.0f;
        }
        if (*(void**)(self + 0x134 + i * 4) != NULL) {
            *(f32*)(*(u8**)(self + 0x134 + i * 4) + 0x8) = 0.0f;
        }
    }
    adjustSize__12JKRSolidHeapFv(*(void**)(self + 0x100));
    becomeCurrentHeap__7JKRHeapFv(tmp);

    for (s32 i = 0; i < 4; i++) {
        *(WaveController**)(self + 0xa8 + i * 0x1c) = new WaveController(0, 0, 8);
    }

    self[0x14c] = 0;
    *(f32*)(self + 0x50) = 0.0f;
    *(f32*)(self + 0x4c) = 0.0f;
    *(s16*)(self + 0x6e) = 0;
    *(s16*)(self + 0x72) = 0;
    *(s16*)(self + 0x7a) = 0;
    *(s16*)(self + 0x7e) = 0;
    self[0x14d] = 0;
    *(s16*)(self + 0x74) = 0;
    *(s16*)(self + 0x76) = 0;
    *(s16*)(self + 0x78) = 0;
    *(u32*)(self + 0x58) = 0;
    *(u32*)(self + 0x60) = 0;
    *(u32*)(self + 0x64) = 0;
    *(s16*)(self + 0x6c) = 0;
    *(u32*)(self + 0x5c) = 0;
    *(s16*)(self + 0x7c) = 0;
    *(s16*)(self + 0x80) = 0;
    *(s16*)(self + 0x82) = 0x3c;
    *(u32*)(self + 0x28) = 0;
    *(u32*)(self + 0x2c) = 0;
    *(u32*)(self + 0x30) = 0;
    *(u32*)(self + 0x34) = 0;
    *(u32*)(self + 0x38) = 0;
    *(u32*)(self + 0x3c) = 0;
    *(u32*)(self + 0x40) = 0;
    *(u32*)(self + 0x44) = 0;
    *(u8*)(*(u8**)(lbl_8053AB10 + 0x20) + 0x2364) = 1;
    lbl_80529DEC[0x250] = 0;
    return self;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"

