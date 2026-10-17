#include "types.h"
#include "JSystem/JAudio/Interface/JAISound.h"
#include "JSystem/JAudio/Interface/JAISoundParams.h"


extern u8* lbl_8053AF80;
typedef void (*VFn)(void*);
typedef u32 (*VFnArg)(void*, void*);
extern "C" void writePort__8JASTrackFUlUs(void* a, u32 b, u16 c);
extern "C" void fn_80455CA4(u8* p, void** snd, f32* src, u32* id) {
    if (src[0] < 0.0f) {
        ((JAISoundParamsMove*)((u8*)*snd + 0x48))->movePan(0.0f, 0);
        ((JAISoundParamsMove*)((u8*)*snd + 0x48))->moveVolume(0.4f, 0);
        return;
    }
    if (src[0] > 1.0f) {
        ((JAISoundParamsMove*)((u8*)*snd + 0x48))->movePan(1.0f, 0);
        ((JAISoundParamsMove*)((u8*)*snd + 0x48))->moveVolume(0.4f, 0);
        return;
    }
    if (src[1] < 0.0f) {
        ((JAISoundParamsMove*)((u8*)*snd + 0x48))->movePan(src[0], 0);
        ((JAISoundParamsMove*)((u8*)*snd + 0x48))->moveVolume(0.4f, 0);
        return;
    }
    if (src[1] > 1.0f) {
        ((JAISoundParamsMove*)((u8*)*snd + 0x48))->movePan(src[0], 0);
        ((JAISoundParamsMove*)((u8*)*snd + 0x48))->moveVolume(0.4f, 0);
        return;
    }
    if (src[0] < 0.1f || src[1] < 0.1f) {
        f32 m = (src[0] <= src[1]) ? src[1] : src[0];
        f32 v = 0.4f + 10.0f * m;
        if (v > 1.0f) {
            v = 1.0f;
        }
        ((JAISoundParamsMove*)((u8*)*snd + 0x48))->moveVolume(v, 0);
        ((JAISoundParamsMove*)((u8*)*snd + 0x48))->movePan(src[0], 0);
        return;
    }
    if (src[0] > 0.9f || src[1] > 0.9f) {
        f32 m = (src[0] >= src[1]) ? src[1] : src[0];
        f32 v = 0.4f + 10.0f * (1.0f - m);
        if (v > 1.0f) {
            v = 1.0f;
        }
        ((JAISoundParamsMove*)((u8*)*snd + 0x48))->moveVolume(v, 0);
        ((JAISoundParamsMove*)((u8*)*snd + 0x48))->movePan(src[0], 0);
        return;
    }
    ((JAISoundParamsMove*)((u8*)*snd + 0x48))->movePan(src[0], 0);
    if (((u8*)id)[1] != 0) {
        if (*id != 0x30009 && *id != 0x30051 && *id != 0x3004b && *id != 0x5006d && p[0x44] != 1) {
            if (lbl_8053AF80[6] == 1) {
                ((JAISoundParamsMove*)((u8*)*snd + 0x48))->moveVolume(0.35f, 0);
            } else {
                ((JAISoundParamsMove*)((u8*)*snd + 0x48))->moveVolume(1.0f, 0);
            }
        }
    }
}

extern "C" void fn_80455F40(u8* param_1, void** param_2) {
    struct SndVT {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void* v6();
    };
    void* track;

    if (param_2 != NULL && *param_2 != NULL) {
        track = ((SndVT*)*param_2)->v6();
        if (param_1[0x44] == 1) {
            writePort__8JASTrackFUlUs(track, 10, 1);
            if (param_1[0x45] == 2) {
                writePort__8JASTrackFUlUs(track, 9, 0x78);
                writePort__8JASTrackFUlUs(track, 0xb, 0);
            } else if (param_1[0x45] == 3) {
                writePort__8JASTrackFUlUs(track, 0xb, 1);
                writePort__8JASTrackFUlUs(track, 9, 0x3c);
            } else {
                writePort__8JASTrackFUlUs(track, 9, 0);
                writePort__8JASTrackFUlUs(track, 0xb, 0);
            }
        } else {
            writePort__8JASTrackFUlUs(track, 10, 0);
            if (param_1[0x45] == 2) {
                writePort__8JASTrackFUlUs(track, 9, 0x78);
                writePort__8JASTrackFUlUs(track, 0xb, 0);
            } else if (param_1[0x45] == 3) {
                writePort__8JASTrackFUlUs(track, 0xb, 1);
                writePort__8JASTrackFUlUs(track, 9, 0x3c);
            } else {
                writePort__8JASTrackFUlUs(track, 9, 0);
                writePort__8JASTrackFUlUs(track, 0xb, 0);
            }
        }
    }
}

extern "C" int fn_804560D0(void* unused, u8** p) {
    struct VObj {
        virtual void v0();
        virtual void v1();
        virtual void v2();
        virtual void v3();
        virtual void v4();
        virtual void v5();
        virtual void v6();
        virtual void v7();
        virtual void v8();
        virtual void v9();
        virtual void v10();
        virtual void v11();
        virtual void v12();
        virtual void v13();
        virtual void v14();
        virtual void v15();
        virtual void v16();
        virtual void v17();
        virtual u32 v18(u32*);
    };
    u32 v;
    VObj* obj = *(VObj**)(lbl_8053AF80 + 0x40);
    v = *(u32*)(*p + 0x18);
    if (obj->v18(&v) & 0x8000) {
        return 0;
    }
    return 1;
}

extern "C" void fn_80456120(u8* p) {
    struct VObj {
        u32 a;
        u32 b;
        virtual void v0();
        virtual void v1();
    };
    p[0x31] = 0;
    ((VObj*)p)->v1();
}

extern "C" void fn_80456154(u8* p) {
    f32* src = *(f32**)(p + 0x34);
    if (src != NULL) {
        *(f32*)(p + 0x38) = src[0];
        *(f32*)(p + 0x3c) = src[1];
        *(f32*)(p + 0x40) = src[2];
        *(f32**)(p + 0x14) = (f32*)(p + 0x38);
    } else {
        *(f32**)(p + 0x14) = NULL;
    }
    f32* v = *(f32**)(p + 0x14);
    if (v != NULL) {
        f32 t = v[1];
        v[1] = v[2];
        (*(f32**)(p + 0x14))[2] = t;
    }
    if (p[0x50] != 0) {
        p[0x50]--;
    }
    if (p[0x51] != 0) {
        p[0x51]--;
    }
}

extern "C" void* fn_80456334(u8* p, JAISoundID id, u32 x);
extern "C" void fn_804561D8(u8* p, JAISoundID id, u8 mode, u32 x, u8 y) {
    f32 pan;
    f32 vol;
    void** snd;

    p[0x44] = y;
    snd = (void**)fn_80456334(p, id, x);
    if (*snd == NULL) {
        return;
    }
    switch (mode) {
    case 0:
    case 1:
        pan = 0.5f;
        vol = 0.4f;
        break;
    case 2:
        pan = 1.0f;
        vol = 0.4f;
        break;
    case 3:
        pan = 0.0f;
        vol = 0.4f;
        break;
    case 4:
    default:
        pan = 0.5f;
        vol = 0.0f;
        break;
    }
    ((JAISoundParamsMove*)((u8*)*snd + 0x48))->movePan(pan, 0);
    if (y != 0) {
        ((JAISoundParamsMove*)((u8*)*snd + 0x48))->moveVolume(1.0f, 0);
    } else {
        ((JAISoundParamsMove*)((u8*)*snd + 0x48))->moveVolume(vol, 0);
    }
    if (p[0x44] != 1) {
        if (lbl_8053AF80[6] == 1) {
            ((JAISoundParamsMove*)((u8*)*snd + 0x48))->moveVolume(0.35f, 0);
        } else {
            ((JAISoundParamsMove*)((u8*)*snd + 0x48))->moveVolume(vol, 0);
        }
    }
}

extern "C" void fn_80457840(u8* p, f32* src) {
    *(f32**)(p + 0x34) = src;
    if (src != NULL) {
        *(f32*)(p + 0x38) = src[0];
        *(f32*)(p + 0x3c) = src[1];
        *(f32*)(p + 0x40) = src[2];
        *(f32**)(p + 0x14) = (f32*)(p + 0x38);
    } else {
        *(f32**)(p + 0x14) = NULL;
    }
}

extern "C" char lbl_804B1E28[];
extern "C" void __dt__11JKRDisposerFv(void*, s16);
extern "C" void __dt__14JAUSoundObjectFv(void*, s16);
extern "C" void* fn_8045787C(char* param_1, s16 param_2)
{
    if (param_1 != 0) {
        *(char**)(param_1 + 8) = lbl_804B1E28;
        *(char**)(param_1 + 0x18) = lbl_804B1E28 + 0x24;
        __dt__11JKRDisposerFv(param_1 + 0x18, 0);
        __dt__14JAUSoundObjectFv(param_1, 0);
        if (param_2 > 0) {
            operator delete(param_1);
        }
    }
    return param_1;
}

extern "C" char lbl_8052DA00[];
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
extern "C" void fn_804579E4(void)
{
    char* base = lbl_8052DA00;

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

