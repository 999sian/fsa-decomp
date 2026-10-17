#include "Game/SinitPoolChain.h"
extern void* lbl_80557E40;
extern void* lbl_80558260;



typedef unsigned char u8;

struct VObj {
    virtual void v00(int);
    virtual void v01();
};
extern char lbl_804AF480[];
extern u8 lbl_80529DEC[];
extern "C" void getTotalFreeSize__7JKRHeapFv(void* heap);
extern "C" void __dl__FPv(void* p);
extern u8* lbl_8053AAF8;
extern u8* lbl_8053ADF8;
extern u8* lbl_8053AE00;
extern "C" void fn_8040F480(void*);
extern "C" void fn_80416BD0(void*);
extern u8* lbl_8053AD80;
extern u8* lbl_8053AB10;
extern u8* lbl_8053AF80;
extern char lbl_80475670[];
struct TResMgr {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void* get(u32 type, const char* name);
};
extern "C" void fn_80158B3C(void* obj);
extern "C" void fn_802FF798(void* mgr);
extern "C" void fn_802F9714(void* mgr, void* res, s32 a, s32 b, s32 c, s32 d);
extern "C" void fn_802F93F4(void* mgr, void* res, s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" void* __nw__FUl(u32 size);
extern "C" void fn_804122F4(void* obj);
extern "C" void fn_8041787C(void* obj);
extern "C" void fn_80458FF0(void* obj, u32 id, s32 a, s32 b);
extern "C" void fn_80458408(void* obj, u32 id, s32 a);
extern "C" u8 fn_804580DC(void* obj, s32 a);
extern "C" void fn_80458090(void* obj);
extern "C" int fn_8040F474(void);
extern "C" int fn_80414F6C(void);
extern "C" int fn_8039003C(void) {
    if (lbl_8053AD80 != 0) {
        if (*(u8*)(lbl_8053AAF8 + 0x7f)) {
            return fn_8040F474();
        } else {
            return fn_80414F6C();
        }
    }
    return 6;
}

extern void* lbl_80558268;
extern "C" void fn_8044A28C(void*);
extern "C" void fn_8044C994(void*);
extern "C" void fn_80390088(void)
{
    if (*((u8*)lbl_80557E40 + 0x7f) != 0) {
        fn_8044A28C(lbl_80558260);
    } else {
        fn_8044C994(lbl_80558268);
    }
}

extern "C" void fn_804108B4(void*);
extern "C" void fn_804170B0__10TU80414F6CFv(void*);
extern "C" void fn_803900C8(void) {
    if (*(u8*)(lbl_8053AAF8 + 0x7f)) {
        fn_804108B4(lbl_8053ADF8);
    } else {
        fn_804170B0__10TU80414F6CFv(lbl_8053AE00);
    }
}

extern "C" void fn_804111C4(void*);
extern void* lbl_80557E40;
extern void* lbl_80558260;
extern "C" void fn_80444988(void*);
extern "C" void fn_80390108(void)
{
    if (*((u8*)lbl_80557E40 + 0x7f) != 0) {
        fn_80444988(lbl_80558260);
    }
}

extern "C" void fn_80411230(void*);
extern "C" void fn_804170EC(void*);
extern "C" void fn_8039013C(void) {
    if (*(u8*)(lbl_8053AAF8 + 0x7f)) {
        fn_80411230(lbl_8053ADF8);
    } else {
        fn_804170EC(lbl_8053AE00);
    }
}

extern "C" void* fn_8039017C(void* this_, short flag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AF480;
        getTotalFreeSize__7JKRHeapFv(*(void**)(lbl_80529DEC + 0x8));
        *(unsigned int*)(lbl_80529DEC + 0xf8) = 0;
        *(unsigned int*)(lbl_80529DEC + 0xfc) = 0;
        *(unsigned int*)(lbl_80529DEC + 0x100) = 0;
        *(unsigned int*)(lbl_80529DEC + 0x104) = 0;
        void* p1 = *(void**)((u8*)this_ + 0x4);
        if (p1 != 0) {
            ((VObj*)p1)->v00(1);
        }
        *(void**)((u8*)this_ + 0x4) = 0;
        void* p2 = *(void**)((u8*)this_ + 0x8);
        if (p2 != 0) {
            ((VObj*)p2)->v00(1);
        }
        *(void**)((u8*)this_ + 0x8) = 0;
        ((VObj*)*(void**)(lbl_80529DEC + 0x34))->v01();
        lbl_8053AD80 = 0;
        if (flag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void* fn_8039027C(void* this_) {
    *(void**)this_ = lbl_804AF480;
    getTotalFreeSize__7JKRHeapFv(*(void**)(lbl_80529DEC + 0x8));
    lbl_8053AD80 = (u8*)this_;
    *(void**)((u8*)this_ + 0x4) = 0;
    *(void**)((u8*)this_ + 0x8) = 0;
    fn_80158B3C(*(void**)(lbl_8053AB10 + 0x2c));
    if (lbl_80529DEC[0x242] == 0) {
        lbl_80529DEC[0x242] = 1;
        fn_802FF798(*(void**)(lbl_8053AB10 + 0x20));
        void* res = ((TResMgr*)*(void**)(lbl_8053AAF8 + 0xa4))->get(0x53434820, lbl_80475670);
        fn_802F9714(*(void**)(lbl_8053AB10 + 0x20), res, 0, 0, 0, 0);
        res = ((TResMgr*)*(void**)(lbl_8053AAF8 + 0xa4))->get(0x53434820, lbl_80475670 + 0x18);
        fn_802F9714(*(void**)(lbl_8053AB10 + 0x20), res, 0, 0, 0x7000, 0);
        res = ((TResMgr*)*(void**)(lbl_8053AAF8 + 0xa4))->get(0x53434c20, lbl_80475670 + 0x30);
        fn_802F93F4(*(void**)(lbl_8053AB10 + 0x20), res, 0, 0, 0, 0, 0);
        res = ((TResMgr*)*(void**)(lbl_8053AAF8 + 0xa4))->get(0x53434820, lbl_80475670 + 0x48);
        fn_802F9714(*(void**)(lbl_8053AB10 + 0x20), res, 0, 2, 0, 0);
        res = ((TResMgr*)*(void**)(lbl_8053AAF8 + 0xa4))->get(0x53434c20, lbl_80475670 + 0x30);
        fn_802F93F4(*(void**)(lbl_8053AB10 + 0x20), res, 0, 2, 0, 0, 0);
        res = ((TResMgr*)*(void**)(lbl_8053AAF8 + 0xa4))->get(0x53434820, lbl_80475670 + 0x58);
        fn_802F9714(*(void**)(lbl_8053AB10 + 0x20), res, 0, 3, 0, 0);
        res = ((TResMgr*)*(void**)(lbl_8053AAF8 + 0xa4))->get(0x53434c20, lbl_80475670 + 0x30);
        fn_802F93F4(*(void**)(lbl_8053AB10 + 0x20), res, 0, 3, 0, 0, 0);
        *((u8*)*(void**)(lbl_8053AB10 + 0x20) + 0x2364) = 1;
    }
    if (lbl_8053AAF8[0x7f] == 0) {
        void* p = __nw__FUl(0x154);
        if (p != 0) {
            fn_8041787C(p);
        }
        *(void**)((u8*)this_ + 0x8) = p;
    } else {
        void* p = __nw__FUl(0x66c);
        if (p != 0) {
            fn_804122F4(p);
        }
        *(void**)((u8*)this_ + 0x4) = p;
    }
    if (*(u32*)(lbl_8053AF80 + 0x58) == 0x100001a) {
        if (lbl_80529DEC[0x248] != 1) {
            fn_80458408(lbl_8053AF80, 0x100001a, 1);
            lbl_80529DEC[0x248] = 1;
        }
    } else {
        fn_80458FF0(lbl_8053AF80, 0x100001a, 1, 0);
        fn_80458408(lbl_8053AF80, 0x100001a, 1);
        lbl_80529DEC[0x248] = 1;
    }
    if (!fn_804580DC(*(void**)(lbl_80529DEC + 0xc), 3)) {
        fn_80458090(lbl_8053AF80);
    }
    return this_;
}

extern "C" char lbl_8050E118[];
extern "C" char memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr[];
extern "C" void __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv(void*);
extern "C" char __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr;
extern "C" char memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack[];
extern "C" void __dt__35JASMemPool_MultiThreaded_8JASTrackFv(void*);
extern "C" char __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack;
extern "C" char memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel[];
extern "C" void __dt__38JASMemPool_MultiThreaded_10JASChannelFv(void*);
extern "C" char __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj3_FSA[];
extern "C" void __dt__29JASMemPool_15JASPoolObj3_FSAFv(void*);
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj4_FSA[];
extern "C" void __dt__29JASMemPool_15JASPoolObj4_FSAFv(void*);
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA;
extern "C" char memPool___30JASPoolAllocObject_9JAIStream[];
extern "C" void __dt__22JASMemPool_9JAIStreamFv(void*);
extern "C" char __init__memPool___30JASPoolAllocObject_9JAIStream;
extern "C" char memPool___35JASPoolAllocObject_13JAISoundChild[];
extern "C" void __dt__27JASMemPool_13JAISoundChildFv(void*);
extern "C" char __init__memPool___35JASPoolAllocObject_13JAISoundChild;
extern "C" char memPool___27JASPoolAllocObject_6JAISeq[];
extern "C" void __dt__19JASMemPool_6JAISeqFv(void*);
extern "C" char __init__memPool___27JASPoolAllocObject_6JAISeq;
extern "C" char memPool___26JASPoolAllocObject_5JAISe[];
extern "C" void __dt__18JASMemPool_5JAISeFv(void*);
extern "C" char __init__memPool___26JASPoolAllocObject_5JAISe;
extern "C" void __ct__17JASGenericMemPoolFv(void*);
extern "C" void __register_global_object(void*, void (*)(void*), void*);
extern "C" void fn_803905F4(void)
{
    char* base = &lbl_8050E118[0];
    if (__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr == 0) {
        __ct__17JASGenericMemPoolFv(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr);
        __register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr, __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, base + 0x0);
        __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr = 1;
    }
    if (__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack == 0) {
        __ct__17JASGenericMemPoolFv(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack);
        __register_global_object(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack, __dt__35JASMemPool_MultiThreaded_8JASTrackFv, base + 0xc);
        __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack = 1;
    }
    if (__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel == 0) {
        __ct__17JASGenericMemPoolFv(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel);
        __register_global_object(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel, __dt__38JASMemPool_MultiThreaded_10JASChannelFv, base + 0x18);
        __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA, __dt__29JASMemPool_15JASPoolObj3_FSAFv, base + 0x24);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA, __dt__29JASMemPool_15JASPoolObj4_FSAFv, base + 0x30);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA = 1;
    }
    if (__init__memPool___30JASPoolAllocObject_9JAIStream == 0) {
        __ct__17JASGenericMemPoolFv(memPool___30JASPoolAllocObject_9JAIStream);
        __register_global_object(memPool___30JASPoolAllocObject_9JAIStream, __dt__22JASMemPool_9JAIStreamFv, base + 0x3c);
        __init__memPool___30JASPoolAllocObject_9JAIStream = 1;
    }
    if (__init__memPool___35JASPoolAllocObject_13JAISoundChild == 0) {
        __ct__17JASGenericMemPoolFv(memPool___35JASPoolAllocObject_13JAISoundChild);
        __register_global_object(memPool___35JASPoolAllocObject_13JAISoundChild, __dt__27JASMemPool_13JAISoundChildFv, base + 0x48);
        __init__memPool___35JASPoolAllocObject_13JAISoundChild = 1;
    }
    if (__init__memPool___27JASPoolAllocObject_6JAISeq == 0) {
        __ct__17JASGenericMemPoolFv(memPool___27JASPoolAllocObject_6JAISeq);
        __register_global_object(memPool___27JASPoolAllocObject_6JAISeq, __dt__19JASMemPool_6JAISeqFv, base + 0x54);
        __init__memPool___27JASPoolAllocObject_6JAISeq = 1;
    }
    if (__init__memPool___26JASPoolAllocObject_5JAISe == 0) {
        __ct__17JASGenericMemPoolFv(memPool___26JASPoolAllocObject_5JAISe);
        __register_global_object(memPool___26JASPoolAllocObject_5JAISe, __dt__18JASMemPool_5JAISeFv, base + 0x60);
        __init__memPool___26JASPoolAllocObject_5JAISe = 1;
    }
}

