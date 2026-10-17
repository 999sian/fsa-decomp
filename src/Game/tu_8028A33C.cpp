#include "Game/Actor.h"


extern "C" char lbl_804A7908[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" u8* lbl_8053AAF8;
extern "C" u8* lbl_8053AB10;
extern "C" f32 lbl_80540490;
extern "C" const char lbl_8046C0E8[];
extern "C" void fn_802F86CC(void*, void*, void*, s32, s32, f32, f32);
extern "C" void fn_803075AC(void*, s32, void*, s32, s32, s32, s32, s32, s32, s32);
extern "C" char lbl_804CFF68[];
extern "C" void __ct__17JASGenericMemPoolFv(void*);
extern "C" void __register_global_object(void*, void (*)(void*), void*);
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

class SobResMgr {
public:
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void* vf18(u32 type, const char* name);
};
extern "C" Actor* fn_8028A33C(Actor* p, s16 n) {
    if (p) {
        *(void**)p = lbl_804A7908;
        __dt__5ActorFv(p, 0);
        if (n > 0) operator delete(p);
    }
    return p;
}

extern "C" void fn_8028A39C(Actor* this_) {
    u8* p = (u8*)this_;
    s32 id = *(s32*)(p + 0x23c) + 0x147;
    if (*(s32*)(p + 4) < 8) {
        SobResMgr* mgr = *(SobResMgr**)(lbl_8053AAF8 + 0xa4);
        void* res = mgr->vf18('SOB ', lbl_8046C0E8);
        fn_802F86CC(*(void**)(lbl_8053AB10 + 0x20), p + 0x24, res, id, 0, lbl_80540490, lbl_80540490);
    }
    fn_803075AC(*(void**)(p + 0x198), *(s32*)(p + 4), p + 0x24, *(s32*)(p + 0x23c) + 0x147, 0, 1, -1, 0, 0, 0);
}

extern "C" f32 lbl_805404B8;
extern "C" f32 lbl_80540498;
extern "C" f32 lbl_80540494;
extern "C" void fn_8028A894(Actor* p) {
    p->field_60 = -8.0f;
    p->field_64 = -8.0f;
    p->field_68 = 8.0f;
    p->field_6C = 8.0f;
    p->field_7C.y = 0.0f;
    p->field_7C.z = 0.0f;
    p->field_88 = 0.0f;
    p->field_8C = 0.0f;
    p->field_108 = 0;
    *(s32*)((u8*)p + 0x23c) = 0;
    *(u8*)((u8*)p + 0x240) = p->v11();
    if (*(u8*)((u8*)p + 0x240)) {
        *(f32*)((u8*)p + 0x244) = 8.0f;
        p->field_0C.y = p->field_24.y + *(f32*)((u8*)p + 0x244);
    } else {
        *(f32*)((u8*)p + 0x244) = 0.0f;
    }
    p->field_3C.x = 0.0f;
    p->field_3C.y = 0.0f;
    p->field_3C.z = 0.0f;
    *(s32*)((u8*)p + 0x248) = 0;
    *(s32*)((u8*)p + 0x24c) = -1;
}

