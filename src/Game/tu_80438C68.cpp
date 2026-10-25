#include "types.h"
#include "JSystem/J2D/J2DPane.h"
#include "JSystem/J2D/J2DScreen.h"
#include "JSystem/J2D/J2DPicture.h"
#include "JSystem/JParticle/JPAEmitter.h"


struct FsaVObj {
    virtual void v2(void);
    virtual void v3(void);
    virtual void v4(void);
    virtual void v5(void);
    virtual void v6(void);
    virtual void v7(void);
    virtual void v8(void);
    virtual void v9(s32 a);
    virtual void v10(void);
          virtual void v11(s32 a);

    virtual void v12(void);
    virtual void v13(void);
    virtual void v14(void);
    virtual void v15(void);
    virtual void v16(void);
          virtual J2DPane* v17(s32 a, s32 b, s32 c);

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
};

struct Slot0 {
    virtual void slot0(s32 arg);
};

extern "C" void* fn_8013C824(void);
extern "C" void* lbl_804B17A0[];
extern "C" void* lbl_8053AEC8;
extern "C" void __dl__FPv(void* p);
extern "C" f32 lbl_80543C40;
extern "C" f32 lbl_80543C44;
extern "C" void* fn_801F856C(void);
extern "C" u32 fn_8022EA0C(u32 a);
extern "C" void* fn_8023E724(u32 i);
extern "C" s32 fn_8023DE58(u32 i);
extern "C" s32 Actor_CreateByID(void* mgr, u32 name, s32 id, void* pos, u32 arg5, s32 arg6, s32 arg7);
extern "C" u8 fn_8022ADB0(void);
extern "C" void fn_8022ADE4(void);
extern "C" void fn_8043D67C(void* a, s32 b, s32 c, u8 d);
extern "C" void fn_80458F9C(void* a, u32 b);
extern "C" void fn_802B7CD8(void* p);
extern "C" void* lbl_8053AED0;
extern "C" void* lbl_8053AF80;
extern "C" u8 lbl_80529DEC[];
extern "C" void* lbl_8053AAF8;
extern "C" void* lbl_8053AB10;
extern "C" u8 lbl_8050DB0C[];
extern "C" void fn_8022ADCC(void);
extern "C" s32 fn_801F666C(void* mgr, s32 idx);
extern "C" void* fn_8013CC50(u32 a, void* pos, s32 id, s32 b, s32 c, s32 d, s32 e, s32 f, f32 scale);
extern "C" void fn_80458880(void* mgr, u32 p, s32 v);
extern "C" void fn_80309C4C(void* a, u32 b, s32 c);
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void* a, void* p);
extern "C" void* lbl_8053AD30;
extern "C" f32 lbl_80543C48;
extern "C" f32 lbl_80543C4C;
extern "C" f32 lbl_80543C50;
extern "C" f32 lbl_80543C54;
extern "C" f32 lbl_80543C58;
extern "C" f32 lbl_80543C5C;
extern "C" f32 lbl_80543C60;
extern "C" f32 lbl_80543C64;
extern "C" f32 lbl_80543C68;
extern "C" void fn_80438C68(u8* p) {
    switch (p[0x58]) {
    case 0:
        if (*(s32*)(p + 0x44) == -1) {
            s32 id;
            void* pos;
            u32 a5 = *(u32*)(p + 0x48);
            pos = fn_8023E724(fn_8022EA0C(0));
            id = fn_8023DE58(0);
            *(s32*)(p + 0x44) = Actor_CreateByID(fn_801F856C(), 0x544e474c, id, pos, a5, -1, -1);
            p[0x5f] = fn_8022ADB0();
            if (p[0x5f] == 0) {
                fn_8022ADE4();
            }
        }
        if (*(s32*)(p + 0x44) > 0) {
            p[0x58] = 1;
            p[0x59] = 0xff;
        }
        break;
    case 1:
        switch (p[0x59]) {
        case 0:
            p[0x58] = 2;
            break;
        case 1:
        case 2: {
            s32 n;
            s32 off;
            s32 i;
            fn_8043D67C(lbl_8053AED0, 0x33a, 0, lbl_80529DEC[0x24f]);
            *(s32*)(p + 0x38) += 1;
            p[0x58] = 3;
            p[0x40] = 5;
            fn_80458F9C(lbl_8053AF80, 0x14);
            n = *(s32*)((u8*)fn_801F856C() + 0x1008);
            off = 0;
            for (i = 0; i < n; i++) {
                void* a = *(void**)((u8*)fn_801F856C() + off + 8);
                if (a != 0 && *(u32*)((u8*)a + 0x1a0) == 0x44455448 && a != 0) {
                    fn_802B7CD8(a);
                }
                off += 4;
            }
            break;
        }
        }
        break;
    }
}

extern "C" void fn_80438E10(u8* p, u8 flag)
{
    *(u8*)(p + 0x40) = flag;
    if (flag) {
        return;
    }
    *(u8*)(p + 0x40) = 0;
    *(u8*)(p + 0x42) = 0;
    *(u8*)(p + 0x5d) = 0;
    *(s32*)(p + 0x44) = -1;
    *(s32*)(p + 0x48) = 0;
    *(u8*)(p + 0x58) = 0;
    *(u8*)(p + 0x59) = 0xff;
    *(u8*)(p + 0x5a) = 0xff;
    *(f32*)(p + 0x4c) = 255.0f;
    *(f32*)(p + 0x50) = 0.0f;
    *(s16*)(p + 0x54) = 0;
    *(s16*)(p + 0x56) = 0;
    *(s32*)(p + 0x3c) = 0;
    *(s32*)(p + 0xc) = 0;
    *(s32*)(p + 0x10) = 0;
    *(s32*)(p + 0x14) = 0;
    *(s32*)(p + 0x18) = 0;
    *(s32*)(p + 0x1c) = 0;
    *(s32*)(p + 0x20) = 0;
    *(s32*)(p + 0x24) = 0;
    *(s32*)(p + 0x28) = 0;
    *(s32*)(p + 0x2c) = 0;
    *(s32*)(p + 0x30) = 0;
    *(u8*)(p + 0x5f) = 0;
}

extern "C" u32 fn_80438E94(u8* p) {
    if (*(s32*)(p + 0x44) > 0) {
        if (fn_801F666C(fn_801F856C(), *(s32*)(p + 0x44)) == 0) {
            *(s32*)(p + 0x44) = -2;
        }
    }
    switch (p[0x40]) {
    case 0:
        if (p[0x5a] == 0xff) {
            if (((u8*)lbl_8053AAF8)[0x7f] == 1) {
                if (lbl_80529DEC[0x24f] == 0) {
                    p[0x5a] = 0;
                } else {
                    *(s32*)(p + 0x48) = 0;
                    p[0x5a] = 1;
                }
            } else {
                p[0x5a] = 0;
            }
        }
        p[0x5b] = ((u8*)(*(void**)((u8*)lbl_8053AB10 + 0x2c)))[0xc];
        if (p[0x5a] != 0) {
            fn_80438C68(p);
        } else {
            *(s32*)(p + 0x44) = -2;
            p[0x58] = 2;
        }
        if (p[0x58] == 2) {
            u8 c = p[0x41];
            if ((s32)p[0x42] < (s32)c - 2) {
                p[0x42] += 2;
            }
        }
        break;
    }
    return p[0x40];
}

extern "C" f32 lbl_80543C78;
extern "C" f32 lbl_80543C7C;
extern "C" f32 lbl_80543C80;
extern "C" void* lbl_8053AB10;
extern "C" u8* lbl_8053ADC8;
extern "C" void fn_8013B490(void* p);
extern "C" f64 lbl_80543C70;
extern "C" void fn_804399A0(u8* param_1)
{
    fn_8013B490(lbl_8053AB10);
    FsaVObj* obj = *(FsaVObj**)(param_1 + 0x34);
    obj->v9((s32)*(f32*)(param_1 + 0x50));
    obj = *(FsaVObj**)(param_1 + 0x34);
    obj->v59(0, 0, 0, lbl_80543C78, lbl_80543C78, lbl_80543C7C, lbl_80543C80);
    *(f32*)(*(u8**)(param_1 + 8) + 8) = (f32)*(s32*)(param_1 + 0x3c);
    (*(J2DPane**)(param_1 + 4))->search(0x004e646174613031ULL)->animationTransform();
    (*(J2DScreen**)(param_1 + 4))->draw(lbl_80543C44, lbl_80543C44, *(J2DGrafContext**)((u8*)lbl_8053AB10 + 0x10));
    if (*(u8*)(param_1 + 0x40) == 3) {
        *(u8*)((u8*)lbl_8053ADC8 + 0x20) = 1;
        *(u8*)((u8*)lbl_8053ADC8 + 0x21) = 0;
    }
}

extern "C" void fn_80439AB0(u8* p)
{
    *(u8*)(p + 0x40) = 0;
    *(u8*)(p + 0x42) = 0;
    *(u8*)(p + 0x5d) = 0;
    *(s32*)(p + 0x44) = -1;
    *(s32*)(p + 0x48) = 0;
    *(u8*)(p + 0x58) = 0;
    *(u8*)(p + 0x59) = 0xff;
    *(u8*)(p + 0x5a) = 0xff;
    *(f32*)(p + 0x4c) = 255.0f;
    *(f32*)(p + 0x50) = 0.0f;
    *(s16*)(p + 0x54) = 0;
    *(s16*)(p + 0x56) = 0;
    *(s32*)(p + 0x3c) = 0;
    *(s32*)(p + 0xc) = 0;
    *(s32*)(p + 0x10) = 0;
    *(s32*)(p + 0x14) = 0;
    *(s32*)(p + 0x18) = 0;
    *(s32*)(p + 0x1c) = 0;
    *(s32*)(p + 0x20) = 0;
    *(s32*)(p + 0x24) = 0;
    *(s32*)(p + 0x28) = 0;
    *(s32*)(p + 0x2c) = 0;
    *(s32*)(p + 0x30) = 0;
    *(u8*)(p + 0x5f) = 0;
}

extern "C" void** fn_80439B28(void** this_, s16 flag) {
    int i;
    if (this_ != 0) {
        *this_ = lbl_804B17A0;
        void* p1 = this_[1];
        if (p1 != 0) {
            ((Slot0*)p1)->slot0(1);
        }
        this_[1] = 0;
        void* p2 = this_[2];
        if (p2 != 0) {
            ((Slot0*)p2)->slot0(1);
        }
        this_[2] = 0;
        void* p3 = this_[13];
        if (p3 != 0) {
            ((Slot0*)p3)->slot0(1);
        }
        this_[13] = 0;
        void** pp = this_;
        i = 0;
        do {
            if (pp[3] != 0) {
                JPAEmitterManager* mgr = *(JPAEmitterManager**)((char*)fn_8013C824() + 0xc);
                mgr->forceDeleteEmitter((JPABaseEmitter*)pp[3]);
                pp[3] = 0;
            }
            pp++;
            i++;
        } while (i < 8);
        if (this_[11] != 0) {
            JPAEmitterManager* mgr = *(JPAEmitterManager**)((char*)fn_8013C824() + 0xc);
            mgr->forceDeleteEmitter((JPABaseEmitter*)this_[11]);
            this_[11] = 0;
        }
        if (this_[12] != 0) {
            JPAEmitterManager* mgr = *(JPAEmitterManager**)((char*)fn_8013C824() + 0xc);
            mgr->forceDeleteEmitter((JPABaseEmitter*)this_[12]);
            this_[12] = 0;
        }
        lbl_8053AEC8 = 0;
        if (flag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void setPriority__9J2DScreenFPCcUlP10JKRArchive(void* self, const char* name, u32 flags, void* archive);
extern "C" void* fn_80403084(u32 id, const char* name);
extern "C" void* fn_804030C4(u32 id, const char* name);
extern "C" void* load__20J2DAnmLoaderDataBaseFPCv(const void* data);
extern "C" char lbl_8048F6D0[];
extern "C" void* fn_80439C78(void** this_) {
    s32 local_24 = 0;
    s32 local_20 = 0xff;
    s32 local_1c = 0xff;
    void** vt;
    void* res;
    J2DPicture* pic;

    this_[0] = lbl_804B17A0;
    lbl_8053AEC8 = this_;
    this_[1] = new J2DScreen();
    setPriority__9J2DScreenFPCcUlP10JKRArchive(this_[1], lbl_8048F6D0 + 0xc, 0x1100000, *(void**)((u8*)lbl_80529DEC + 0x4c));
    fn_80403084(0x5343524e, lbl_8048F6D0 + 0x1c);
    this_[2] = load__20J2DAnmLoaderDataBaseFPCv(0);
    vt = *(void***)this_[1];
    res = ((void* (*)(void*, u32, u32, u32))vt[15])(this_[1], 0x4e0000, 0x4e6461, 0x74613031);
    vt = *(void***)res;
    ((void (*)(void*, void*))vt[24])(res, this_[2]);
    this_[15] = 0;
    this_[3] = 0;
    this_[4] = 0;
    this_[5] = 0;
    this_[6] = 0;
    this_[7] = 0;
    this_[8] = 0;
    this_[9] = 0;
    this_[10] = 0;
    this_[11] = 0;
    this_[12] = 0;
    res = fn_804030C4(0x54494d47, lbl_8048F6D0 + 0x2c);
    pic = new J2DPicture((ResTIMG*)res);
    this_[13] = pic;
    vt = *(void***)pic;
    ((void (*)(void*, void*, void*))vt[76])(pic, &local_1c, &local_24);
    return this_;
}

extern "C" char memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr[];
extern "C" char __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr;
extern "C" void __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv(void*);
extern "C" char memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack[];
extern "C" char __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack;
extern "C" void __dt__35JASMemPool_MultiThreaded_8JASTrackFv(void*);
extern "C" char memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel[];
extern "C" char __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel;
extern "C" void __dt__38JASMemPool_MultiThreaded_10JASChannelFv(void*);
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj3_FSA[];
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA;
extern "C" void __dt__29JASMemPool_15JASPoolObj3_FSAFv(void*);
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj4_FSA[];
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA;
extern "C" void __dt__29JASMemPool_15JASPoolObj4_FSAFv(void*);
extern "C" char memPool___30JASPoolAllocObject_9JAIStream[];
extern "C" char __init__memPool___30JASPoolAllocObject_9JAIStream;
extern "C" void __dt__22JASMemPool_9JAIStreamFv(void*);
extern "C" char memPool___35JASPoolAllocObject_13JAISoundChild[];
extern "C" char __init__memPool___35JASPoolAllocObject_13JAISoundChild;
extern "C" void __dt__27JASMemPool_13JAISoundChildFv(void*);
extern "C" char memPool___27JASPoolAllocObject_6JAISeq[];
extern "C" char __init__memPool___27JASPoolAllocObject_6JAISeq;
extern "C" void __dt__19JASMemPool_6JAISeqFv(void*);
extern "C" char memPool___26JASPoolAllocObject_5JAISe[];
extern "C" char __init__memPool___26JASPoolAllocObject_5JAISe;
extern "C" void __dt__18JASMemPool_5JAISeFv(void*);
extern "C" void __ct__17JASGenericMemPoolFv(void*);
extern "C" void __register_global_object(void*, void*, void*);
extern "C" void fn_80439EC4(void) {
    static u32 c0[3], c1[3], c2[3], c3[3], c4[3], c5[3], c6[3], c7[3], c8[3];
    if (!__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr) {
        __ct__17JASGenericMemPoolFv(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr);
        __register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr, (void*)__dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, c0);
        __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr = 1;
    }
    if (!__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack) {
        __ct__17JASGenericMemPoolFv(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack);
        __register_global_object(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack, (void*)__dt__35JASMemPool_MultiThreaded_8JASTrackFv, c1);
        __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack = 1;
    }
    if (!__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel) {
        __ct__17JASGenericMemPoolFv(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel);
        __register_global_object(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel, (void*)__dt__38JASMemPool_MultiThreaded_10JASChannelFv, c2);
        __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel = 1;
    }
    if (!__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA, (void*)__dt__29JASMemPool_15JASPoolObj3_FSAFv, c3);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA = 1;
    }
    if (!__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA, (void*)__dt__29JASMemPool_15JASPoolObj4_FSAFv, c4);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA = 1;
    }
    if (!__init__memPool___30JASPoolAllocObject_9JAIStream) {
        __ct__17JASGenericMemPoolFv(memPool___30JASPoolAllocObject_9JAIStream);
        __register_global_object(memPool___30JASPoolAllocObject_9JAIStream, (void*)__dt__22JASMemPool_9JAIStreamFv, c5);
        __init__memPool___30JASPoolAllocObject_9JAIStream = 1;
    }
    if (!__init__memPool___35JASPoolAllocObject_13JAISoundChild) {
        __ct__17JASGenericMemPoolFv(memPool___35JASPoolAllocObject_13JAISoundChild);
        __register_global_object(memPool___35JASPoolAllocObject_13JAISoundChild, (void*)__dt__27JASMemPool_13JAISoundChildFv, c6);
        __init__memPool___35JASPoolAllocObject_13JAISoundChild = 1;
    }
    if (!__init__memPool___27JASPoolAllocObject_6JAISeq) {
        __ct__17JASGenericMemPoolFv(memPool___27JASPoolAllocObject_6JAISeq);
        __register_global_object(memPool___27JASPoolAllocObject_6JAISeq, (void*)__dt__19JASMemPool_6JAISeqFv, c7);
        __init__memPool___27JASPoolAllocObject_6JAISeq = 1;
    }
    if (!__init__memPool___26JASPoolAllocObject_5JAISe) {
        __ct__17JASGenericMemPoolFv(memPool___26JASPoolAllocObject_5JAISe);
        __register_global_object(memPool___26JASPoolAllocObject_5JAISe, (void*)__dt__18JASMemPool_5JAISeFv, c8);
        __init__memPool___26JASPoolAllocObject_5JAISe = 1;
    }
}

