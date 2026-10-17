#include "JSystem/JGeometry/Vec.h"
#include "Game/SinitPoolChain.h"

class Actor;


extern "C" char lbl_804ABA90[];
extern "C" void __dt__5ActorFv(Actor*, s32);
extern "C" void fn_801EE434(void* handle);
extern "C" int fn_80230CFC(int index);
extern "C" int fn_80230498(int index, Vec* pos, s32 a1, u8 a2, u8 a3, u8 a4, u8 a5);
extern "C" const Vec lbl_80471AE0[4][4];
extern "C" s32 fn_80336040(Actor* self) {
    u8* p = (u8*)self;
    s32 ret = 0;
    s32 slot;
    s32 idx;

    ret = 0;
    *(s32*)(p + 0x26c) = *(s32*)(p + 0x26c) + 1;
    if (*(s32*)(p + 0x26c) < 8) {
        *(s32*)(p + 0x260) = 0;
        slot = 0;
    } else if (*(s32*)(p + 0x26c) < 0x10) {
        *(s32*)(p + 0x260) = 1;
        slot = 0;
    } else if (*(s32*)(p + 0x26c) < 0x18) {
        *(s32*)(p + 0x260) = 2;
        slot = 1;
    } else {
        *(s32*)(p + 0x260) = 3;
        slot = 2;
    }

    idx = fn_80230CFC(*(s32*)(p + 0x24c));
    if (idx == 0) {
        *(s32*)(p + 0x270) = 0x2b0;
    } else if (idx == 1) {
        *(s32*)(p + 0x270) = 0x2b4;
    } else if (idx == 2) {
        *(s32*)(p + 0x270) = 0x2b8;
    } else {
        *(s32*)(p + 0x270) = 0x2bc;
    }
    *(s32*)(p + 0x270) = *(s32*)(p + 0x270) + *(s32*)(p + 0x260);

    if (*(s32*)(p + 0x26c) % 0x24 < 6) {
        *(s32*)(p + 0x264) = 0;
    } else if (*(s32*)(p + 0x26c) % 0x24 < 0xc) {
        *(s32*)(p + 0x264) = 1;
    } else if (*(s32*)(p + 0x26c) % 0x24 < 0x12) {
        *(s32*)(p + 0x264) = 0;
    } else if (*(s32*)(p + 0x26c) % 0x24 < 0x18) {
        *(s32*)(p + 0x264) = 2;
    } else if (*(s32*)(p + 0x26c) % 0x24 < 0x1e) {
        *(s32*)(p + 0x264) = 3;
    } else {
        *(s32*)(p + 0x264) = 2;
    }
    *(s32*)(p + 0x274) = (u16)(*(s32*)(p + 0x264) + 0x296);

    if (*(s32*)(p + 0x26c) > 0x28) {
        ret = 1;
    }

    Vec pos = *(Vec*)(p + 0xc);
    Vec sum;
    sum.x = pos.x + lbl_80471AE0[idx][slot].x;
    sum.y = pos.y + lbl_80471AE0[idx][slot].y;
    sum.z = pos.z + lbl_80471AE0[idx][slot].z;
    fn_80230498(*(s32*)(p + 0x24c), &pos, *(s32*)(p + 0x270), 0xff, 0x80, 0x80, 1);
    fn_80230498(*(s32*)(p + 0x250), &sum, *(s32*)(p + 0x274), 0xff, 0x80, 0x80, 1);
    return ret;
}

extern "C" void fn_80336294(void) {
}

extern "C" void* fn_8020D58C(void);
extern "C" u8 fn_8020D6AC(void* entry, int a, f32* b, s32 d, int e);
extern "C" u16 fn_8022461C(void* a, s32 b);
extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802265DC(f32* b, int a, int c);
extern "C" u8 fn_80336C44(Actor* a, s32 b, f32* c) {
    u32 unk = *(u32*)((u8*)a + 0x198);
    u8* base = (u8*)fn_8020D58C();
    if (fn_8020D6AC(base + base[1] * 0x784 + 4, b, c, unk, 0) == 1) {
        return 1;
    }
    s32 code = fn_8022461C(c, b);
    if (code == 0 || code == 2 || code == 0x50 || code == 0x39 || code == 0xd || code == 0x61) {
        return 0;
    }
    if (code == 0x22 && ((u8*)fn_802D6A9C())[0x170] == 0) {
        return 0;
    }
    if (code == 0x25 && ((u8*)fn_802D6A9C())[0x171] == 0) {
        return 0;
    }
    if (code == 4) {
        if (((int)c[1] & 0xf) >= 8) {
            return 0;
        }
    } else if (code == 5) {
        if (((int)c[1] & 0xf) < 8) {
            return 0;
        }
    } else if (code == 6) {
        if (((int)c[0] & 0xf) >= 8) {
            return 0;
        }
    } else if (code == 7) {
        if (((int)c[0] & 0xf) < 8) {
            return 0;
        }
    }
    return fn_802265DC(c, b, 1);
}

extern "C" Actor* fn_80337010(Actor* p, s16 n) {
    if (p != 0) {
        *(void**)p = lbl_804ABA90;
        for (int i = 0; i < 4; i++) {
            fn_801EE434(*(void**)((u8*)p + 0x2a0 + i * 4));
            fn_801EE434(*(void**)((u8*)p + 0x2b0 + i * 4));
        }
        __dt__5ActorFv(p, 0);
        if (n > 0) {
            operator delete(p);
        }
    }
    return p;
}

extern "C" char lbl_805095F8[];
extern "C" char memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr[];
extern "C" char __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr;
extern "C" char memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack[];
extern "C" char __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack;
extern "C" char memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel[];
extern "C" char __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj3_FSA[];
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj4_FSA[];
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA;
extern "C" char memPool___30JASPoolAllocObject_9JAIStream[];
extern "C" char __init__memPool___30JASPoolAllocObject_9JAIStream;
extern "C" char memPool___35JASPoolAllocObject_13JAISoundChild[];
extern "C" char __init__memPool___35JASPoolAllocObject_13JAISoundChild;
extern "C" char memPool___27JASPoolAllocObject_6JAISeq[];
extern "C" char __init__memPool___27JASPoolAllocObject_6JAISeq;
extern "C" char memPool___26JASPoolAllocObject_5JAISe[];
extern "C" char __init__memPool___26JASPoolAllocObject_5JAISe;
extern "C" void __ct__17JASGenericMemPoolFv(void*);
extern "C" void __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv(void*);
extern "C" void __dt__35JASMemPool_MultiThreaded_8JASTrackFv(void*);
extern "C" void __dt__38JASMemPool_MultiThreaded_10JASChannelFv(void*);
extern "C" void __dt__29JASMemPool_15JASPoolObj3_FSAFv(void*);
extern "C" void __dt__29JASMemPool_15JASPoolObj4_FSAFv(void*);
extern "C" void __dt__22JASMemPool_9JAIStreamFv(void*);
extern "C" void __dt__27JASMemPool_13JAISoundChildFv(void*);
extern "C" void __dt__19JASMemPool_6JAISeqFv(void*);
extern "C" void __dt__18JASMemPool_5JAISeFv(void*);
extern "C" void __register_global_object(void*, void*, void*);
extern "C" void fn_803370AC(void) {
    u8* base = (u8*)lbl_805095F8;
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

