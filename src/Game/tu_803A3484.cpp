#include "types.h"

struct TResMgr {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
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

