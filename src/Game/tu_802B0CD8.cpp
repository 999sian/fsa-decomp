#include "Game/esd/types.h"
#include "JSystem/JGeometry/Vec.h"
#include "dolphin/gx/GXStruct.h"
#include "Game/SinitPoolChain.h"


extern "C" void __dt__5ActorFv(void* this_, int flag);
extern "C" void dtor_80084580(void* this_);
extern "C" void fn_801EE434(void* handle);
extern void* lbl_804A8520[];
extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802D800C(void* mgr, u32 idx);
extern "C" void* fn_8013CC50(u32 a, void* b, f32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i);
extern "C" void fn_801F0E34(void* this_, u32 a, s32 b);
extern "C" char lbl_804D1B68[];
extern "C" char memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr[];
extern "C" char memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack[];
extern "C" char memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel[];
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj3_FSA[];
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj4_FSA[];
extern "C" char memPool___30JASPoolAllocObject_9JAIStream[];
extern "C" char memPool___35JASPoolAllocObject_13JAISoundChild[];
extern "C" char memPool___27JASPoolAllocObject_6JAISeq[];
extern "C" char memPool___26JASPoolAllocObject_5JAISe[];
extern "C" char __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr;
extern "C" char __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack;
extern "C" char __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel;
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA;
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA;
extern "C" char __init__memPool___30JASPoolAllocObject_9JAIStream;
extern "C" char __init__memPool___35JASPoolAllocObject_13JAISoundChild;
extern "C" char __init__memPool___27JASPoolAllocObject_6JAISeq;
extern "C" char __init__memPool___26JASPoolAllocObject_5JAISe;
extern "C" void __ct__17JASGenericMemPoolFv(void*);
extern "C" void __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv(void*, s32);
extern "C" void __dt__35JASMemPool_MultiThreaded_8JASTrackFv(void*, s32);
extern "C" void __dt__38JASMemPool_MultiThreaded_10JASChannelFv(void*, s32);
extern "C" void __dt__29JASMemPool_15JASPoolObj3_FSAFv(void*, s32);
extern "C" void __dt__29JASMemPool_15JASPoolObj4_FSAFv(void*, s32);
extern "C" void __dt__22JASMemPool_9JAIStreamFv(void*, s32);
extern "C" void __dt__27JASMemPool_13JAISoundChildFv(void*, s32);
extern "C" void __dt__19JASMemPool_6JAISeqFv(void*, s32);
extern "C" void __dt__18JASMemPool_5JAISeFv(void*, s32);
extern "C" void __register_global_object(void*, void (*)(void*, s32), void*);

extern "C" void* lbl_8053AB10;
extern "C" void fn_80158B5C(void* mgr, u32 room, f32 t, JGeometry::TVec3<f32>* pos, GXColor* col);
extern "C" void fn_802B0CD8(void* this_) {
    char* p = (char*)this_;
    if (*((u8*)fn_802D6A9C() + 0x131f5) != 0) {
        if (*(f32*)(p + 0x250) > 0.0f) {
            *(f32*)(p + 0x250) -= 8.0f;
            if (*(f32*)(p + 0x250) <= 0.0f) {
                *(f32*)(p + 0x250) = 0.0f;
            }
        }
    } else if (*(s32*)(p + 0x24c) == 0) {
        if (*(f32*)(p + 0x250) > 0.0f) {
            *(f32*)(p + 0x250) -= 4.0f;
            if (*(f32*)(p + 0x250) <= 0.0f) {
                *(f32*)(p + 0x250) = 0.0f;
            }
        } else {
            *(f32*)(p + 0x250) = 0.0f;
        }
    } else {
        if (*(f32*)(p + 0x250) < *(f32*)(p + 0x254)) {
            *(f32*)(p + 0x250) += 4.0f;
        } else {
            *(f32*)(p + 0x250) = *(f32*)(p + 0x254);
        }
    }

    s32 mode = *(s32*)(p + 0x23c);
    switch (mode) {
    case 0: {
        if (*(u8*)(p + 0x248) == 1) {
            JGeometry::TVec3<f32> pos(*(f32*)(p + 0xc) + 8.0f, *(f32*)(p + 0x10) + 8.0f, 0.0f);
            GXColor col;
            col.r = 0;
            col.g = 0;
            col.b = 0;
            col.a = 0x80;
            fn_80158B5C(*(void**)((u8*)lbl_8053AB10 + 0x2c), *(u32*)(p + 4), *(f32*)(p + 0x250), &pos, &col);
        }
        break;
    }
    case 1: {
        JGeometry::TVec3<f32> pos(*(f32*)(p + 0xc), *(f32*)(p + 0x10) - 4.0f, *(f32*)(p + 0x14));
        GXColor col;
        col.r = 0;
        col.g = 0;
        col.b = 0;
        col.a = 0xc8;
        fn_80158B5C(*(void**)((u8*)lbl_8053AB10 + 0x2c), *(u32*)(p + 4), *(f32*)(p + 0x250), &pos, &col);
        break;
    }
    case 2: {
        if (*(u8*)(p + 0x248) == 1) {
            u8* mgr = (u8*)*(void**)((u8*)lbl_8053AB10 + 0x2c);
            mgr[0xd] = 1;
            JGeometry::TVec3<f32> pos(*(f32*)(p + 0xc) + 8.0f, *(f32*)(p + 0x10) + 8.0f, 0.0f);
            GXColor col;
            col.r = 0;
            col.g = 0;
            col.b = 0;
            col.a = 0x80;
            fn_80158B5C(mgr, *(u32*)(p + 4), *(f32*)(p + 0x250), &pos, &col);
        }
        break;
    }
    case 3: {
        u8* mgr = (u8*)*(void**)((u8*)lbl_8053AB10 + 0x2c);
        mgr[0xd] = 1;
        JGeometry::TVec3<f32> pos(*(f32*)(p + 0xc), *(f32*)(p + 0x10) - 4.0f, *(f32*)(p + 0x14));
        GXColor col;
        col.r = 0;
        col.g = 0;
        col.b = 0;
        col.a = 0xc8;
        fn_80158B5C(mgr, *(u32*)(p + 4), *(f32*)(p + 0x250), &pos, &col);
        break;
    }
    default:
        break;
    }
}

extern "C" void fn_802B0F9C(void* this_) {
    char* p = (char*)this_;
    s32 state = *(s32*)(p + 0x238);
    switch (state) {
    case 0: {
        void* mgr = fn_802D6A9C();
        u8 r = fn_802D800C(mgr, *(u32*)(p + 0x244));
        if (r != 0 || *(u16*)(p + 0x94) != 0) {
            *(u8*)(p + 0x248) = 1;
            s32 mode = *(s32*)(p + 0x23c);
            if (mode == 0 || mode == 2 || mode == 4) {
                *(u32*)(p + 0x230) = (u32)fn_8013CC50(*(u32*)(p + 4), p + 0xc, 1.0f, 0xbd, 0, 0, 0, 0, 1);
                if (*(s32*)(p + 0x23c) != 4) {
                    *(u32*)(p + 0x234) = (u32)fn_8013CC50(*(u32*)(p + 4), p + 0xc, 1.0f, 0x54a, 0, 0, 0, 0, 1);
                }
            }
            fn_801F0E34(this_, 0x30005, 0);
            *(u32*)(p + 0xb0) = 0xc;
            *(u32*)(p + 0x238) = 1;
            *(u32*)(p + 0x24c) = 1;
            *(u16*)(p + 0x94) = 0;
        }
        break;
    }
    case 1: {
        s32 idx = *(s32*)(p + 0x244);
        if (idx != 0) {
            void* mgr = fn_802D6A9C();
            u8 r = fn_802D800C(mgr, idx);
            if (r == 0) {
                char* h1 = *(char**)(p + 0x230);
                if (h1 != 0) {
                    *(u32*)(h1 + 0xf4) |= 1;
                    *(u32*)(h1 + 0x24) = 1;
                    *(char**)(p + 0x230) = 0;
                }
                char* h2 = *(char**)(p + 0x234);
                if (h2 != 0) {
                    *(u32*)(h2 + 0xf4) |= 1;
                    *(u32*)(h2 + 0x24) = 1;
                    *(char**)(p + 0x234) = 0;
                }
                *(u32*)(p + 0xb0) = 0xd;
                *(u8*)(p + 0x248) = 0;
                *(u32*)(p + 0x238) = 0;
                *(u32*)(p + 0x24c) = 0;
            }
        }
        break;
    }
    }
}

extern "C" void* fn_802B114C(void* this_, s16 freeFlag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804A8520;
        char* p = (char*)this_;
        void* h1 = *(void**)(p + 0x230);
        if (h1 != 0) {
            fn_801EE434(h1);
        }
        void* h2 = *(void**)(p + 0x234);
        if (h2 != 0) {
            fn_801EE434(h2);
        }
        __dt__5ActorFv(this_, 0);
        if (freeFlag > 0) {
            dtor_80084580(this_);
        }
    }
    return this_;
}

extern "C" void* fn_802D6A9C(void);
extern "C" u8 fn_802D800C(void* mgr, u32 idx);
extern "C" void* fn_8013CC50(u32 a, void* b, f32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i);
extern "C" void fn_802B11D0(void* this_) {
    char* p = (char*)this_;
    *(u32*)(p + 0x23c) = *(u32*)(p + 0x90) & 0x7f;
    *(u32*)(p + 0x244) = *(u32*)(p + 0x90) >> 27;
    *(u32*)(p + 0x24c) = 0;
    *(f32*)(p + 0x250) = 0.0f;
    if (*(s32*)(p + 0x23c) == 0 || *(s32*)(p + 0x23c) == 2) {
        *(f32*)(p + 0x254) = 70.0f;
    } else {
        *(f32*)(p + 0x254) = 20.0f;
    }
    *(u16*)(p + 0x94) = 0;
    *(u32*)(p + 0x230) = 0;
    *(u32*)(p + 0x234) = 0;
    s32 idx = *(s32*)(p + 0x244);
    if (idx == 0 || fn_802D800C(fn_802D6A9C(), idx)) {
        *(u8*)(p + 0x248) = 1;
        s32 state = *(s32*)(p + 0x23c);
        if (state == 0 || state == 2 || state == 4) {
            *(u32*)(p + 0x230) = (u32)fn_8013CC50(*(u32*)(p + 4), p + 0xc, 1.0f, 0xbd, 0, 0, 0, 0, 1);
            if (*(s32*)(p + 0x23c) != 4) {
                *(u32*)(p + 0x234) = (u32)fn_8013CC50(*(u32*)(p + 4), p + 0xc, 1.0f, 0x54a, 0, 0, 0, 0, 1);
            }
        }
        *(u32*)(p + 0xb0) = 0xc;
        *(u32*)(p + 0x238) = 1;
        *(u32*)(p + 0x24c) = 1;
    } else {
        *(u32*)(p + 0xb0) = 0xd;
        *(u32*)(p + 0x238) = 0;
        *(u8*)(p + 0x248) = 0;
    }
}

extern "C" void fn_802B1334(void) {
    char* base = lbl_804D1B68;
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

