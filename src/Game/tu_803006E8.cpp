#include "JSystem/J3D/J3DDrawBuffer.h"


extern "C" s32 OSResumeThread(void* subObj);
extern "C" void* DVDGetCurrentDiskID(void);
extern "C" void GBAInit(void);
extern "C" u32 OSGetTick(void);
extern "C" void OSInitMessageQueue(void* queue, void* msgs, s32 count);
extern "C" void OSCreateThread(void* thread, void* (*start)(void*), void* arg, void* stack, u32 size, s32 prio, u32 attr);
extern "C" void* memset(void* dst, s32 c, u32 n);
extern "C" void* fn_80300A8C(void* p);
extern "C" void* fn_80300E1C(void* p);
extern u8 lbl_804D6AB8[];
extern u8 lbl_804711F0[];
extern u8 lbl_80529DEC[];
extern u8* lbl_8053ACBC;
extern u8* lbl_8053ACC0;
extern u8* lbl_8053ACC4;
extern u32 lbl_8053ACC8;

class Unk8053ACB8 {
public:
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void* vf18(u32 a, void* b);
    virtual void vf1C();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2C();
    virtual void* vf30(void* a);
};
extern Unk8053ACB8* lbl_8053ACB8;

extern "C" u8 fn_803006E8(u32 data) {
    u32 crc = 0;
    u32 i;

    for (u32 mask = 0x80; mask != 0; mask >>= 1) {
        crc <<= 1;
        if (data & mask) {
            if (crc & 0x100) {
                crc ^= 0xcc;
            } else {
                crc += 1;
            }
        } else if (crc & 0x100) {
            crc ^= 0xcd;
        }
    }
    data >>= 8;
    for (u32 mask = 0x80; mask != 0; mask >>= 1) {
        crc <<= 1;
        if (data & mask) {
            if (crc & 0x100) {
                crc ^= 0xcc;
            } else {
                crc += 1;
            }
        } else if (crc & 0x100) {
            crc ^= 0xcd;
        }
    }
    i = 0;
    do {
        crc <<= 1;
        if (crc & 0x100) {
            crc ^= 0xcd;
        }
    } while (++i < 8);
    return crc;
}

extern "C" void fn_803007A0(void) {
    lbl_8053ACB8->vf0C();
}

extern "C" void fn_803007D0(void) {
    u8* base = lbl_804D6AB8;
    u8* obj;
    u8* id;
    u8* ub;
    u8* ud;
    u8* p;
    u8* thread;
    s32 i;
    s32 crc;
    u32 off;
    u32 tick;
    void* fn1;
    void* fn2;

    lbl_8053ACC4 = (u8*)DVDGetCurrentDiskID();
    GBAInit();
    lbl_8053ACB8 = *(Unk8053ACB8**)(lbl_80529DEC + 0x58);
    lbl_8053ACBC = (u8*)lbl_8053ACB8->vf18(0x3f3f3f3f, lbl_804711F0);
    lbl_8053ACC0 = (u8*)lbl_8053ACB8->vf30(lbl_8053ACB8->vf18(0x3f3f3f3f, lbl_804711F0));
    tick = OSGetTick();
    lbl_8053ACC8 = tick;
    *(u32*)(lbl_8053ACBC + 0xc8) = tick;

    id = lbl_8053ACC4;
    obj = lbl_8053ACBC;
    obj[0xac] = id[0];
    obj[0xad] = id[1];
    obj[0xae] = id[2];
    obj[0xaf] = id[3];
    crc = 0xe7;
    i = 0xa0;
    if (i < 0xbd) {
        crc = crc - obj[0xa0] - obj[0xa1] - obj[0xa2] - obj[0xa3] - obj[0xa4] - obj[0xa5] - obj[0xa6] - obj[0xa7] -
              obj[0xa8] - obj[0xa9] - obj[0xaa] - obj[0xab] - obj[0xac] - obj[0xad] - obj[0xae] - obj[0xaf] -
              obj[0xb0] - obj[0xb1] - obj[0xb2] - obj[0xb3] - obj[0xb4] - obj[0xb5] - obj[0xb6] - obj[0xb7] -
              obj[0xb8] - obj[0xb9] - obj[0xba] - obj[0xbb];
        i = 0xbc;
        do {
            crc -= obj[i];
            i++;
        } while (i < 0xbd);
    }
    obj[i] = crc;

    fn1 = (void*)fn_80300A8C;
    fn2 = (void*)fn_80300E1C;
    ud = lbl_8053ACC0;
    ub = lbl_8053ACBC;
    p = base + 0x4ce0;
    thread = base + 0x80;
    off = 0x1000;
    for (i = 0; i < 4; i++) {
        memset(p, 0, 0xe0);
        p[0xd0] = i;
        *(void**)(p + 0x24) = fn1;
        *(u8**)(p + 0x4c) = ub;
        *(u8**)(p + 0x50) = ud;
        p[0xda] = 0x1a;
        p[0xdc] = 1;
        p[0xdd] = 0;
        p[0xde] = 0;
        OSInitMessageQueue(p, p + 0x20, 1);
        OSCreateThread(thread, (void* (*)(void*))fn2, p, base + 0xce0 + off, 0x1000, 8, 0);
        OSResumeThread(thread);
        off += 0x1000;
        thread += 0x318;
        p += 0xe0;
    }
}


extern "C" s32 fn_80301A88(void* this_) {
    return OSResumeThread(*(void**)((char*)this_ + 0x28));
}

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
extern "C" void fn_80301AAC(void)
{
    static u8 pad[0x5060];
    static u32 c0[3];
    static u32 c1[3];
    static u32 c2[3];
    static u32 c3[3];
    static u32 c4[3];
    static u32 c5[3];
    static u32 c6[3];
    static u32 c7[3];
    static u32 c8[3];
    (void)pad;
    if (__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr == 0) {
        __ct__17JASGenericMemPoolFv(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr);
        __register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr, __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, c0);
        __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr = 1;
    }
    if (__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack == 0) {
        __ct__17JASGenericMemPoolFv(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack);
        __register_global_object(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack, __dt__35JASMemPool_MultiThreaded_8JASTrackFv, c1);
        __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack = 1;
    }
    if (__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel == 0) {
        __ct__17JASGenericMemPoolFv(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel);
        __register_global_object(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel, __dt__38JASMemPool_MultiThreaded_10JASChannelFv, c2);
        __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA, __dt__29JASMemPool_15JASPoolObj3_FSAFv, c3);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA, __dt__29JASMemPool_15JASPoolObj4_FSAFv, c4);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA = 1;
    }
    if (__init__memPool___30JASPoolAllocObject_9JAIStream == 0) {
        __ct__17JASGenericMemPoolFv(memPool___30JASPoolAllocObject_9JAIStream);
        __register_global_object(memPool___30JASPoolAllocObject_9JAIStream, __dt__22JASMemPool_9JAIStreamFv, c5);
        __init__memPool___30JASPoolAllocObject_9JAIStream = 1;
    }
    if (__init__memPool___35JASPoolAllocObject_13JAISoundChild == 0) {
        __ct__17JASGenericMemPoolFv(memPool___35JASPoolAllocObject_13JAISoundChild);
        __register_global_object(memPool___35JASPoolAllocObject_13JAISoundChild, __dt__27JASMemPool_13JAISoundChildFv, c6);
        __init__memPool___35JASPoolAllocObject_13JAISoundChild = 1;
    }
    if (__init__memPool___27JASPoolAllocObject_6JAISeq == 0) {
        __ct__17JASGenericMemPoolFv(memPool___27JASPoolAllocObject_6JAISeq);
        __register_global_object(memPool___27JASPoolAllocObject_6JAISeq, __dt__19JASMemPool_6JAISeqFv, c7);
        __init__memPool___27JASPoolAllocObject_6JAISeq = 1;
    }
    if (__init__memPool___26JASPoolAllocObject_5JAISe == 0) {
        __ct__17JASGenericMemPoolFv(memPool___26JASPoolAllocObject_5JAISe);
        __register_global_object(memPool___26JASPoolAllocObject_5JAISe, __dt__18JASMemPool_5JAISeFv, c8);
        __init__memPool___26JASPoolAllocObject_5JAISe = 1;
    }
}

