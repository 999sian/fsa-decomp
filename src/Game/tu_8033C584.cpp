#include "Game/Actor.h"
#include "Game/ItemBase.h"


extern "C" char lbl_804AC250[];
extern "C" void fn_801EE434(void* handle);
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" f32 lbl_80542178;
extern "C" f32 lbl_8054218C;
extern "C" f32 lbl_80542190;
extern "C" f32 lbl_80542194;
extern "C" f32 lbl_80542198;
extern "C" void* fn_8013CC50(u32, void*, s32, s32, s32, s32, s32, s32, f32);
extern "C" char lbl_80471E10[];
extern "C" void fn_801F06F0(void* this_, void* p, s32 n, void* ids, s32 flag, f32 fa, f32 fb);
extern "C" void fn_803075AC(void* a, void* b, void* c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i, s32 j);
extern "C" void fn_8033C584(u8* this_) {
    DrawRec rec;
    if (*(s32*)(this_ + 0x238) < 0x3c) {
        u32 sign = *(u32*)(this_ + 0x234) >> 31;
        if (((*(u32*)(this_ + 0x234) & 1) ^ sign) - sign != 0) {
            return;
        }
    }
    rec.b2d = 1;
    fn_801F06F0(this_, lbl_80471E10, *(s32*)(this_ + 0x23c) + 0x5e, rec.ids, 1, lbl_80542178, lbl_80542178);
    fn_803075AC(*(void**)(this_ + 0x198), *(void**)(this_ + 4), this_ + 0xc, *(s32*)(this_ + 0x23c) + 0x5e, 0, 2, -1, 0, 0, 0);
}

extern "C" void fn_8033C968(u8* this_) {
    f32 zero = lbl_80542190;
    f32 f3 = lbl_8054218C;
    f32 f2 = lbl_80542194;
    f32 f0 = lbl_80542198;

    *(u32*)(this_ + 0x240) = *(u32*)(this_ + 0x90) & 3;
    *(u32*)(this_ + 0x108) = 8;
    *(u32*)(this_ + 0x23c) = 0;
    *(f32*)(this_ + 0x248) = zero;
    *(f32*)(this_ + 0x24c) = zero;
    *(f32*)(this_ + 0x250) = zero;
    *(f32*)(this_ + 0x3c) = zero;
    *(f32*)(this_ + 0x40) = zero;
    *(f32*)(this_ + 0x44) = zero;
    *(f32*)(this_ + 0x3c) = f3;
    *(f32*)(this_ + 0x250) = f2;
    *(f32*)(this_ + 0x40) = f0;
    *(u32*)(this_ + 0x234) = 0;
    *(u32*)(this_ + 0x238) = 0xb4;
    *(u16*)(this_ + 0x244) = 0;
    *(u32*)(this_ + 0x230) = 0;
    *(void**)(this_ + 0x254) = fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, 0x183, 0, 0, 0, 0, 1, lbl_80542178);
    *(void**)(this_ + 0x258) = fn_8013CC50(*(u32*)(this_ + 4), this_ + 0xc, 0x184, 0, 0, 0, 0, 1, lbl_80542178);
}

extern "C" Actor* fn_8033CA4C(Actor* param_1, s16 param_2)
{
    if (param_1 != 0) {
        *(void**)param_1 = lbl_804AC250;
        fn_801EE434(*(void**)((u8*)param_1 + 0x254));
        fn_801EE434(*(void**)((u8*)param_1 + 0x258));
        __dt__5ActorFv(param_1, 0);
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}

extern "C" char lbl_80509BF8[];
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
extern "C" void fn_8033CAC0(void)
{
    if (__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr == 0) {
        __ct__17JASGenericMemPoolFv(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr);
        __register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr, __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, lbl_80509BF8 + 0x0);
        __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr = 1;
    }
    if (__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack == 0) {
        __ct__17JASGenericMemPoolFv(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack);
        __register_global_object(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack, __dt__35JASMemPool_MultiThreaded_8JASTrackFv, lbl_80509BF8 + 0xc);
        __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack = 1;
    }
    if (__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel == 0) {
        __ct__17JASGenericMemPoolFv(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel);
        __register_global_object(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel, __dt__38JASMemPool_MultiThreaded_10JASChannelFv, lbl_80509BF8 + 0x18);
        __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA, __dt__29JASMemPool_15JASPoolObj3_FSAFv, lbl_80509BF8 + 0x24);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA, __dt__29JASMemPool_15JASPoolObj4_FSAFv, lbl_80509BF8 + 0x30);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA = 1;
    }
    if (__init__memPool___30JASPoolAllocObject_9JAIStream == 0) {
        __ct__17JASGenericMemPoolFv(memPool___30JASPoolAllocObject_9JAIStream);
        __register_global_object(memPool___30JASPoolAllocObject_9JAIStream, __dt__22JASMemPool_9JAIStreamFv, lbl_80509BF8 + 0x3c);
        __init__memPool___30JASPoolAllocObject_9JAIStream = 1;
    }
    if (__init__memPool___35JASPoolAllocObject_13JAISoundChild == 0) {
        __ct__17JASGenericMemPoolFv(memPool___35JASPoolAllocObject_13JAISoundChild);
        __register_global_object(memPool___35JASPoolAllocObject_13JAISoundChild, __dt__27JASMemPool_13JAISoundChildFv, lbl_80509BF8 + 0x48);
        __init__memPool___35JASPoolAllocObject_13JAISoundChild = 1;
    }
    if (__init__memPool___27JASPoolAllocObject_6JAISeq == 0) {
        __ct__17JASGenericMemPoolFv(memPool___27JASPoolAllocObject_6JAISeq);
        __register_global_object(memPool___27JASPoolAllocObject_6JAISeq, __dt__19JASMemPool_6JAISeqFv, lbl_80509BF8 + 0x54);
        __init__memPool___27JASPoolAllocObject_6JAISeq = 1;
    }
    if (__init__memPool___26JASPoolAllocObject_5JAISe == 0) {
        __ct__17JASGenericMemPoolFv(memPool___26JASPoolAllocObject_5JAISe);
        __register_global_object(memPool___26JASPoolAllocObject_5JAISe, __dt__18JASMemPool_5JAISeFv, lbl_80509BF8 + 0x60);
        __init__memPool___26JASPoolAllocObject_5JAISe = 1;
    }
}

