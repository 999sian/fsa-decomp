#include "types.h"
#include "JSystem/J2D/J2DPane.h"
struct J2DScreen {
    u8 pad[0x100];
    u8 b100;
};


extern "C" void fn_804316EC(void*);
extern void* lbl_8053AEC0;
extern void* lbl_8053AF40;
extern f32 lbl_80543DF8;
extern f32 lbl_80543DFC;
extern "C" void fn_80402E08(void*, f32, f32);
struct UlPane {
    virtual void v08();
    virtual void v0c();
    virtual void move(f32, f32);
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void setAlpha(u32);
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual UlPane* find(u64 tag);
};
struct Deletable {
    virtual void v00();
    virtual void v04();
    virtual void del(s32 flag);
};

extern "C" void* fn_8013C824(void);
extern "C" void forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(void* mgr, void* emitter);
extern "C" void fn_8044C7F0(u8* self) {
    s32 i;
    u8* p;
    for (i = 0; i < 7; i++) {
        p = *(u8**)(self + 0x6c + i * 4);
        if (p != NULL) {
            *(u32*)(p + 0xf4) |= 1;
            *(s32*)(p + 0x24) = 1;
            *(u8**)(self + 0x6c + i * 4) = NULL;
        }
        p = *(u8**)(self + 0x88 + i * 4);
        if (p != NULL) {
            *(u32*)(p + 0xf4) |= 1;
            *(s32*)(p + 0x24) = 1;
            *(u8**)(self + 0x88 + i * 4) = NULL;
        }
    }
    p = *(u8**)(self + 0xb0);
    if (p != NULL) {
        *(u32*)(p + 0xf4) |= 1;
        *(s32*)(p + 0x24) = 1;
        *(u8**)(self + 0xb0) = NULL;
    }
    p = *(u8**)(self + 0xb4);
    if (p != NULL) {
        *(u32*)(p + 0xf4) |= 1;
        *(s32*)(p + 0x24) = 1;
        *(u8**)(self + 0xb4) = NULL;
    }
    p = *(u8**)(self + 0xb8);
    if (p != NULL) {
        *(u32*)(p + 0xf4) |= 1;
        *(s32*)(p + 0x24) = 1;
        *(u8**)(self + 0xb8) = NULL;
    }
    p = *(u8**)(self + 0xbc);
    if (p != NULL) {
        *(u32*)(p + 0xf4) |= 1;
        *(s32*)(p + 0x24) = 1;
        *(u8**)(self + 0xbc) = NULL;
    }
    for (i = 0; i < 3; i++) {
        if (*(void**)(self + 0xa4 + i * 4) != NULL) {
            forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((u8*)fn_8013C824() + 0xc), *(void**)(self + 0xa4 + i * 4));
            *(void**)(self + 0xa4 + i * 4) = NULL;
        }
        if (*(void**)(self + 0xc0 + i * 4) != NULL) {
            forceDeleteEmitter__17JPAEmitterManagerFP14JPABaseEmitter(*(void**)((u8*)fn_8013C824() + 0xc), *(void**)(self + 0xc0 + i * 4));
            *(void**)(self + 0xc0 + i * 4) = NULL;
        }
    }
}

extern "C" void fn_8044C968(u8* self) {
    u8* p = self;
    s32 i;
    for (i = 0; i < 3; i++) {
        fn_80402E08(*(void**)(p + 0x48), lbl_80543DF8, lbl_80543DFC);
        fn_80402E08(*(void**)(p + 0x60), lbl_80543DF8, lbl_80543DFC);
        *(s16*)(*(u8**)(p + 0x48) + 0x20) = 0;
        *(s16*)(*(u8**)(p + 0x60) + 0x20) = 0;
        (*(UlPane**)(*(u8**)(p + 0x48) + 4))->setAlpha(0);
        *(s16*)(*(u8**)(p + 0x48) + 0x26) = 0;
        (*(UlPane**)(*(u8**)(p + 0x54) + 4))->setAlpha(0);
        *(s16*)(*(u8**)(p + 0x54) + 0x26) = 0;
        (*(UlPane**)(*(u8**)(p + 0x60) + 4))->setAlpha(0);
        *(s16*)(*(u8**)(p + 0x60) + 0x26) = 0;
        p += 4;
    }
    (*(UlPane**)(self + 4))->find(0x5063756c3031ULL)
        ->move(lbl_80543DF8 + *(f32*)(self + 0x114),
               *(f32*)(self + 0x118) + ((f32*)(self + 0x108))[*(s16*)(self + 0xf8)]);
    (*(UlPane**)(self + 4))->find(0x5063756c3031ULL)->setAlpha(0);
    *(s16*)(self + 0x132) = 0;
    *(s16*)(self + 0xfe) = 0;
    *(s16*)(self + 0xfa) = 2;
}

extern "C" u8 fn_8044CB00(u8* p) { return p[0x140]; }

extern "C" u8 fn_8044D290(u8* p) { return p[0x140]; }

extern "C" void* fn_8044F664(void) {
    if (lbl_8053AF40 != 0) {
        return *(void**)((char*)lbl_8053AF40 + 0x184);
    }
    return (void*)9;
}

extern "C" void fn_804522C8(u8* p) {
    if (*(s16*)(p + 0xfa) == 7 || *(s16*)(p + 0xfa) == 8 || *(s16*)(p + 0xfa) == 9) {
        fn_804316EC(lbl_8053AEC0);
    }
}

extern "C" void fn_8013B490(void*);
extern u8* lbl_8053AB10;
extern f32 lbl_80543DFC;
struct J2DGrafContext;
extern "C" void draw__9J2DScreenFffPC14J2DGrafContext(J2DScreen*, f32, f32, const J2DGrafContext*);
extern "C" void fn_80452308(void* self_) {
    u8* self = (u8*)self_;
    fn_8013B490(lbl_8053AB10);
    f32 f = lbl_80543DFC;
    draw__9J2DScreenFffPC14J2DGrafContext(*(J2DScreen**)(self + 4), f, f, *(const J2DGrafContext**)(lbl_8053AB10 + 0x10));
}

extern "C" void fn_80453830(void* thisPtr) {
	s32* p = (s32*)thisPtr;
	p[0] = -1;
	p[1] = -1;
	p[2] = -1;
	p[3] = -1;
}

extern "C" u8 fn_80453848(u8* p) {
    u8 dead = 0;
    if ((*(u32*)(p + 0xf4) & 8) && *(s32*)(p + 0xd0) + *(s32*)(p + 0xdc) == 0) {
        dead = 1;
    }
    return dead;
}

extern "C" void fn_80453874(void* thisObj, f32 x, f32 y, f32 z) {
	*(f32*)((char*)thisObj + 0x0) = x;
	*(f32*)((char*)thisObj + 0x4) = y;
	*(f32*)((char*)thisObj + 0x8) = z;
}

extern "C" void fn_80453884(J2DWindow* window, JUtility::TColor* colors) {
    window->setContentsColor(colors[0], colors[1], colors[2], colors[3]);
}

extern "C" char lbl_8052D700[];
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
extern "C" void fn_804538D4(void)
{
    char* pool = lbl_8052D700 + 0x0;
    if (__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr == 0) {
        __ct__17JASGenericMemPoolFv(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr);
        __register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr, __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, pool + 0x0);
        __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr = 1;
    }
    if (__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack == 0) {
        __ct__17JASGenericMemPoolFv(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack);
        __register_global_object(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack, __dt__35JASMemPool_MultiThreaded_8JASTrackFv, pool + 0xc);
        __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack = 1;
    }
    if (__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel == 0) {
        __ct__17JASGenericMemPoolFv(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel);
        __register_global_object(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel, __dt__38JASMemPool_MultiThreaded_10JASChannelFv, pool + 0x18);
        __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA, __dt__29JASMemPool_15JASPoolObj3_FSAFv, pool + 0x24);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA, __dt__29JASMemPool_15JASPoolObj4_FSAFv, pool + 0x30);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA = 1;
    }
    if (__init__memPool___30JASPoolAllocObject_9JAIStream == 0) {
        __ct__17JASGenericMemPoolFv(memPool___30JASPoolAllocObject_9JAIStream);
        __register_global_object(memPool___30JASPoolAllocObject_9JAIStream, __dt__22JASMemPool_9JAIStreamFv, pool + 0x3c);
        __init__memPool___30JASPoolAllocObject_9JAIStream = 1;
    }
    if (__init__memPool___35JASPoolAllocObject_13JAISoundChild == 0) {
        __ct__17JASGenericMemPoolFv(memPool___35JASPoolAllocObject_13JAISoundChild);
        __register_global_object(memPool___35JASPoolAllocObject_13JAISoundChild, __dt__27JASMemPool_13JAISoundChildFv, pool + 0x48);
        __init__memPool___35JASPoolAllocObject_13JAISoundChild = 1;
    }
    if (__init__memPool___27JASPoolAllocObject_6JAISeq == 0) {
        __ct__17JASGenericMemPoolFv(memPool___27JASPoolAllocObject_6JAISeq);
        __register_global_object(memPool___27JASPoolAllocObject_6JAISeq, __dt__19JASMemPool_6JAISeqFv, pool + 0x54);
        __init__memPool___27JASPoolAllocObject_6JAISeq = 1;
    }
    if (__init__memPool___26JASPoolAllocObject_5JAISe == 0) {
        __ct__17JASGenericMemPoolFv(memPool___26JASPoolAllocObject_5JAISe);
        __register_global_object(memPool___26JASPoolAllocObject_5JAISe, __dt__18JASMemPool_5JAISeFv, pool + 0x60);
        __init__memPool___26JASPoolAllocObject_5JAISe = 1;
    }
}

