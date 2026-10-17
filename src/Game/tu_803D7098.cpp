#include "types.h"


extern "C" void* lbl_8053AB10;
extern "C" void* lbl_8053AD68;
extern "C" f32 lbl_80543534;
extern "C" f32 lbl_80543568;
extern "C" f32 lbl_8054356C;
extern "C" void fn_8013B490(void*);
extern "C" void fn_803D75B0(void);
extern "C" void draw__9J2DScreenFffPC14J2DGrafContext(void*, f32, f32, void*);
extern "C" void fn_803D82EC(u8* param_1) {
    u8* obj;

    fn_8013B490(lbl_8053AB10);
    obj = *(u8**)(param_1 + 0x1c);
    ((void (*)(u8*, u8))(*(void***)obj)[0x24 / 4])(obj, param_1[0x77]);
    obj = *(u8**)(param_1 + 0x1c);
    ((void (*)(u8*, s32, s32, s32, f32, f32, f32, f32))(*(void***)obj)[0xec / 4])(obj, 0, 0, 0, lbl_80543534, lbl_80543534, lbl_80543568, lbl_8054356C);
}

extern "C" void fn_803D8670(u8* param_1) {
    u8* obj;

    fn_8013B490(lbl_8053AB10);
    draw__9J2DScreenFffPC14J2DGrafContext(*(void**)(param_1 + 4), lbl_80543534, lbl_80543534, *(void**)((u8*)lbl_8053AB10 + 0x10));
    draw__9J2DScreenFffPC14J2DGrafContext(*(void**)(param_1 + 8), lbl_80543534, lbl_80543534, *(void**)((u8*)lbl_8053AB10 + 0x10));
    obj = *(u8**)(param_1 + 0x1c);
    ((void (*)(u8*, u8))(*(void***)obj)[0x24 / 4])(obj, param_1[0x77]);
    ((void (*)(u8*, s32, s32, s32, f32, f32, f32, f32))(*(void***)(*(u8**)(param_1 + 0x1c)))[0xec / 4])(*(u8**)(param_1 + 0x1c), 0, 0, 0, lbl_80543534, lbl_80543534, lbl_80543568, lbl_8054356C);
}

extern "C" void fn_803D8718(u8* param_1) {
    s32 bVar1 = param_1[0x76];

    switch (bVar1) {
    case 6:
        if (param_1[0x77] >= 0xf5) {
            param_1[0x77] = 0xff;
            param_1[0x76] = 5;
        } else {
            param_1[0x77] += 10;
        }
        break;
    case 5:
        if (param_1[0x77] <= 10) {
            param_1[0x77] = 0;
            ((u8*)lbl_8053AD68)[0x1d] = 1;
            param_1[0x76] = 2;
        } else {
            param_1[0x77] -= 10;
        }
        break;
    case 2:
        fn_803D75B0();
        break;
    }
}

extern "C" char lbl_80528168[];
extern "C" char __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr;
extern "C" char memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr[];
extern "C" void __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv(void*);
extern "C" char __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack;
extern "C" char memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack[];
extern "C" void __dt__35JASMemPool_MultiThreaded_8JASTrackFv(void*);
extern "C" char __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel;
extern "C" char memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel[];
extern "C" void __dt__38JASMemPool_MultiThreaded_10JASChannelFv(void*);
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj3_FSA[];
extern "C" void __dt__29JASMemPool_15JASPoolObj3_FSAFv(void*);
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj4_FSA[];
extern "C" void __dt__29JASMemPool_15JASPoolObj4_FSAFv(void*);
extern "C" char __init__memPool___30JASPoolAllocObject_9JAIStream;
extern "C" char memPool___30JASPoolAllocObject_9JAIStream[];
extern "C" void __dt__22JASMemPool_9JAIStreamFv(void*);
extern "C" char __init__memPool___35JASPoolAllocObject_13JAISoundChild;
extern "C" char memPool___35JASPoolAllocObject_13JAISoundChild[];
extern "C" void __dt__27JASMemPool_13JAISoundChildFv(void*);
extern "C" char __init__memPool___27JASPoolAllocObject_6JAISeq;
extern "C" char memPool___27JASPoolAllocObject_6JAISeq[];
extern "C" void __dt__19JASMemPool_6JAISeqFv(void*);
extern "C" char __init__memPool___26JASPoolAllocObject_5JAISe;
extern "C" char memPool___26JASPoolAllocObject_5JAISe[];
extern "C" void __dt__18JASMemPool_5JAISeFv(void*);
extern "C" void __ct__17JASGenericMemPoolFv(void*);
extern "C" void __register_global_object(void*, void (*)(void*), void*);
void fn_803D9720(void) {
    char* base = lbl_80528168;

    if (!__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr) {
        __ct__17JASGenericMemPoolFv(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr);
        __register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr, __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, base + 0x0);
        __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr = 1;
    }
    if (!__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack) {
        __ct__17JASGenericMemPoolFv(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack);
        __register_global_object(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack, __dt__35JASMemPool_MultiThreaded_8JASTrackFv, base + 0xc);
        __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack = 1;
    }
    if (!__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel) {
        __ct__17JASGenericMemPoolFv(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel);
        __register_global_object(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel, __dt__38JASMemPool_MultiThreaded_10JASChannelFv, base + 0x18);
        __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel = 1;
    }
    if (!__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA, __dt__29JASMemPool_15JASPoolObj3_FSAFv, base + 0x24);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA = 1;
    }
    if (!__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA, __dt__29JASMemPool_15JASPoolObj4_FSAFv, base + 0x30);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA = 1;
    }
    if (!__init__memPool___30JASPoolAllocObject_9JAIStream) {
        __ct__17JASGenericMemPoolFv(memPool___30JASPoolAllocObject_9JAIStream);
        __register_global_object(memPool___30JASPoolAllocObject_9JAIStream, __dt__22JASMemPool_9JAIStreamFv, base + 0x3c);
        __init__memPool___30JASPoolAllocObject_9JAIStream = 1;
    }
    if (!__init__memPool___35JASPoolAllocObject_13JAISoundChild) {
        __ct__17JASGenericMemPoolFv(memPool___35JASPoolAllocObject_13JAISoundChild);
        __register_global_object(memPool___35JASPoolAllocObject_13JAISoundChild, __dt__27JASMemPool_13JAISoundChildFv, base + 0x48);
        __init__memPool___35JASPoolAllocObject_13JAISoundChild = 1;
    }
    if (!__init__memPool___27JASPoolAllocObject_6JAISeq) {
        __ct__17JASGenericMemPoolFv(memPool___27JASPoolAllocObject_6JAISeq);
        __register_global_object(memPool___27JASPoolAllocObject_6JAISeq, __dt__19JASMemPool_6JAISeqFv, base + 0x54);
        __init__memPool___27JASPoolAllocObject_6JAISeq = 1;
    }
    if (!__init__memPool___26JASPoolAllocObject_5JAISe) {
        __ct__17JASGenericMemPoolFv(memPool___26JASPoolAllocObject_5JAISe);
        __register_global_object(memPool___26JASPoolAllocObject_5JAISe, __dt__18JASMemPool_5JAISeFv, base + 0x60);
        __init__memPool___26JASPoolAllocObject_5JAISe = 1;
    }
}

