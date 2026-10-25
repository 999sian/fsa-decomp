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
    *(f32*)(this_ + 0x50) = lbl_805432E0;
    *(f32*)(this_ + 0x4c) = lbl_805432E0;
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
extern "C" u8* fn_803A56C4(u8* p, s16 n) {
    if (p != NULL) {
        *(void**)p = lbl_804AF820;
        getTotalFreeSize__7JKRHeapFv(*(void**)(lbl_80529DEC + 0x8));
        for (s32 i = 0; i < 4; i++) {
            void* obj = *(void**)(p + i * 0x1c + 0xa8);
            if (obj != NULL) {
                void** vt = *(void***)((u8*)obj + 0x8);
                ((void (*)(void*, s32))vt[0xc])(obj, 1);
            }
        }
        if (*(s16*)(p + 0x6c) != 0) {
            fn_80427D94(*(void**)(p + 0x48));
            *(s16*)(p + 0x6c) = 0;
        }
        for (s32 i = 0; i < 3; i++) {
            void* em = *(void**)(p + 0x28 + i * 4);
            if (em != NULL) {
                forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((u8*)fn_8013C824() + 0xc), em);
                *(void**)(p + 0x28 + i * 4) = NULL;
            }
        }
        for (s32 i = 0; i < 4; i++) {
            void* em = *(void**)(p + 0x34 + i * 4);
            if (em != NULL) {
                forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((u8*)fn_8013C824() + 0xc), em);
                *(void**)(p + 0x34 + i * 4) = NULL;
            }
        }
        if (*(void**)(p + 0x44) != NULL) {
            forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((u8*)fn_8013C824() + 0xc), *(void**)(p + 0x44));
            *(void**)(p + 0x44) = NULL;
        }
        forceDeleteAllEmitter__17JPAEmitterManagerFv(*(void**)((u8*)fn_8013C824() + 0xc));
        destroy__7JKRHeapFv(*(void**)(p + 0x100));
        void* sub;
        sub = *(void**)(p + 0x4);
        if (sub != NULL) {
            ((void (*)(void*, s32))(*(void***)sub)[2])(sub, 1);
            *(void**)(p + 0x4) = NULL;
        }
        sub = *(void**)(p + 0x24);
        if (sub != NULL) {
            ((void (*)(void*, s32))(*(void***)sub)[2])(sub, 1);
            *(void**)(p + 0x24) = NULL;
        }
        sub = *(void**)(p + 0x8);
        if (sub != NULL) {
            ((void (*)(void*, s32))(*(void***)sub)[2])(sub, 1);
            *(void**)(p + 0x8) = NULL;
        }
        sub = *(void**)(p + 0x48);
        if (sub != NULL) {
            ((void (*)(void*, s32))(*(void***)sub)[2])(sub, 1);
            *(void**)(p + 0x48) = NULL;
        }
        sub = *(void**)(p + 0xc);
        if (sub != NULL) {
            ((void (*)(void*, s32))(*(void***)sub)[2])(sub, 1);
            *(void**)(p + 0xc) = NULL;
        }
        sub = *(void**)(p + 0x10);
        if (sub != NULL) {
            ((void (*)(void*, s32))(*(void***)sub)[2])(sub, 1);
            *(void**)(p + 0x10) = NULL;
        }
        sub = *(void**)(p + 0x14);
        if (sub != NULL) {
            ((void (*)(void*, s32))(*(void***)sub)[2])(sub, 1);
            *(void**)(p + 0x14) = NULL;
        }
        sub = *(void**)(p + 0x18);
        if (sub != NULL) {
            ((void (*)(void*, s32))(*(void***)sub)[2])(sub, 1);
            *(void**)(p + 0x18) = NULL;
        }
        sub = *(void**)(p + 0x1c);
        if (sub != NULL) {
            ((void (*)(void*, s32))(*(void***)sub)[2])(sub, 1);
            *(void**)(p + 0x1c) = NULL;
        }
        sub = *(void**)(p + 0x20);
        if (sub != NULL) {
            ((void (*)(void*, s32))(*(void***)sub)[2])(sub, 1);
            *(void**)(p + 0x20) = NULL;
        }
        ((void (*)(void*))(*(void***)*(void**)(lbl_80529DEC + 0x24))[9])(*(void**)(lbl_80529DEC + 0x24));
        lbl_8053AD88 = NULL;
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" u32 lbl_804AF7D8[][3];
extern "C" u8* sCurrentHeap__7JKRHeap;
extern "C" void fn_8016FDE0(void);
extern "C" void fn_80428030(void);
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
extern "C" u8* fn_803A59E0(u8* this_) {
    char* names = lbl_80475F58;
    *(void**)this_ = lbl_804AF820;
    __construct_array(this_ + 0x90, (void*)fn_8016FDE0, NULL, 0x1c, 4);
    getTotalFreeSize__7JKRHeapFv(*(void**)(lbl_80529DEC + 0x8));
    lbl_8053AD88 = this_;
    void* obj = __nw__FUl(0x118);
    if (obj != NULL) {
        __ct__9J2DScreenFv(obj);
    }
    *(void**)(this_ + 0x4) = obj;
    u8* tbl = lbl_80529DEC;
    setPriority__9J2DScreenFPCcUlP10JKRArchive(*(void**)(this_ + 0x4), names + 0x164, 0x1100000, *(void**)(tbl + 0x24));
    *(void**)(this_ + 0x24) = load__20J2DAnmLoaderDataBaseFPCv(getGlbResource__13JKRFileLoaderFPCcP13JKRFileLoader(names + 0x170, *(void**)(tbl + 0x24)));
    void* scr = *(void**)(this_ + 0x4);
    ((void (*)(void*, void*))(*(void***)scr)[27])(scr, *(void**)(this_ + 0x24));
    scr = *(void**)(this_ + 0x4);
    void* pane = ((void* (*)(void*, u32, u32, u32))(*(void***)scr)[15])(scr, 0x6d610000, 0x5063, 0x6d61726b);
    *((u8*)pane + 0xb0) = 0;
    scr = *(void**)(this_ + 0x4);
    pane = ((void* (*)(void*, u32, u32, u32))(*(void***)scr)[15])(scr, 0x70720000, 0x70727373, 0x74727431);
    this_[0x14e] = *((u8*)pane + 0xb2);
    scr = *(void**)(this_ + 0x4);
    pane = ((void* (*)(void*, u32, u32, u32))(*(void***)scr)[15])(scr, 0x74720000, 0x70727373, 0x74727432);
    this_[0x14f] = *((u8*)pane + 0xb2);

    void* res = fn_80403204(0x54494d47, names + 0x17c);
    obj = __nw__FUl(0x168);
    if (obj != NULL) {
        __ct__10J2DPictureFPC7ResTIMG(obj, res);
    }
    *(void**)(this_ + 0x8) = obj;
    obj = __nw__FUl(0x1c);
    if (obj != NULL) {
        fn_80428030();
    }
    *(void**)(this_ + 0x48) = obj;
    res = fn_80403244(0x54494d47, names + 0x190);
    obj = __nw__FUl(0x168);
    if (obj != NULL) {
        __ct__10J2DPictureFPC7ResTIMG(obj, res);
    }
    *(void**)(this_ + 0xc) = obj;
    res = fn_80403244(0x54494d47, names + 0x1a8);
    obj = __nw__FUl(0x168);
    if (obj != NULL) {
        __ct__10J2DPictureFPC7ResTIMG(obj, res);
    }
    *(void**)(this_ + 0x10) = obj;
    res = fn_80403244(0x54494d47, names + 0x1c0);
    obj = __nw__FUl(0x168);
    if (obj != NULL) {
        __ct__10J2DPictureFPC7ResTIMG(obj, res);
    }
    *(void**)(this_ + 0x14) = obj;
    res = fn_80403244(0x54494d47, names + 0x1d4);
    obj = __nw__FUl(0x168);
    if (obj != NULL) {
        __ct__10J2DPictureFPC7ResTIMG(obj, res);
    }
    *(void**)(this_ + 0x18) = obj;
    res = fn_80403244(0x54494d47, names + 0x1e8);
    obj = __nw__FUl(0x168);
    if (obj != NULL) {
        __ct__10J2DPictureFPC7ResTIMG(obj, res);
    }
    *(void**)(this_ + 0x1c) = obj;
    res = fn_804030C4(0x54494d47, names + 0x1fc);
    obj = __nw__FUl(0x168);
    if (obj != NULL) {
        __ct__10J2DPictureFPC7ResTIMG(obj, res);
    }
    *(void**)(this_ + 0x20) = obj;

    u8 zero[4] = {0, 0, 0, 0};
    u8 col[4] = {0x08, 0x18, 0x28, 0xff};
    u8 zeroCopy[4];
    u8 colCopy[4];
    *(u32*)zeroCopy = *(u32*)zero;
    *(u32*)colCopy = *(u32*)col;
    scr = *(void**)(this_ + 0x20);
    ((void (*)(void*, void*, void*))(*(void***)scr)[76])(scr, colCopy, zeroCopy);

    if (tbl[0x249] != 0) {
        *(s16*)(this_ + 0x68) = 0;
    } else {
        *(s16*)(this_ + 0x68) = 0xff;
    }
    this_[0x150] = 0;
    u8* oldHeap = sCurrentHeap__7JKRHeap;
    u8* heap = (u8*)create__12JKRSolidHeapFUlP7JKRHeapb(0x80000, oldHeap, 0);
    *(u8**)(this_ + 0x100) = heap;
    becomeCurrentHeap__7JKRHeapFv(heap);

    void** base = (void**)this_;
    for (s32 i = 0; i < 6; i++) {
        fn_8016A3BC(*(void**)(tbl + 0x24), lbl_804AF7D8[i][0], lbl_804AF7D8[i][1], 0, lbl_804AF7D8[i][2], 0, 0x10240000, heap, &base[0x41 + i], &base[0x47 + i], 0, &base[0x4d + i], 0);
        if (base[0x47 + i] != NULL) {
            *(f32*)((u8*)base[0x47 + i] + 0x8) = lbl_805432E0;
        }
        if (base[0x4d + i] != NULL) {
            *(f32*)((u8*)base[0x4d + i] + 0x8) = lbl_805432E0;
        }
    }
    adjustSize__12JKRSolidHeapFv(*(void**)(this_ + 0x100));
    becomeCurrentHeap__7JKRHeapFv(oldHeap);

    for (s32 i = 0; i < 4; i++) {
        void* wc = __nw__FUl(0x5c);
        if (wc != NULL) {
            __ct__14WaveControllerFlll(wc, 0, 0, 8);
        }
        *(void**)(this_ + 0xa8 + i * 0x1c) = wc;
    }

    this_[0x14c] = 0;
    *(f32*)(this_ + 0x50) = lbl_805432E0;
    *(f32*)(this_ + 0x4c) = lbl_805432E0;
    *(s16*)(this_ + 0x6e) = 0;
    *(s16*)(this_ + 0x72) = 0;
    *(s16*)(this_ + 0x7a) = 0;
    *(s16*)(this_ + 0x7e) = 0;
    this_[0x14d] = 0;
    *(s16*)(this_ + 0x74) = 0;
    *(s16*)(this_ + 0x76) = 0;
    *(s16*)(this_ + 0x78) = 0;
    *(u32*)(this_ + 0x58) = 0;
    *(u32*)(this_ + 0x60) = 0;
    *(u32*)(this_ + 0x64) = 0;
    *(s16*)(this_ + 0x6c) = 0;
    *(u32*)(this_ + 0x5c) = 0;
    *(s16*)(this_ + 0x7c) = 0;
    *(s16*)(this_ + 0x80) = 0;
    *(s16*)(this_ + 0x82) = 0x3c;
    *(u32*)(this_ + 0x28) = 0;
    *(u32*)(this_ + 0x2c) = 0;
    *(u32*)(this_ + 0x30) = 0;
    *(u32*)(this_ + 0x34) = 0;
    *(u32*)(this_ + 0x38) = 0;
    *(u32*)(this_ + 0x3c) = 0;
    *(u32*)(this_ + 0x40) = 0;
    *(u32*)(this_ + 0x44) = 0;
    *(u8*)(*(u8**)(lbl_8053AB10 + 0x20) + 0x2364) = 1;
    tbl[0x250] = 0;
    return this_;
}

#include "JSystem/JAudio/JASFakeMatchFSA.h"

