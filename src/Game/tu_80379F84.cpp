#include "types.h"

struct VObj {
    virtual void v00(int);
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
};
extern u8 lbl_804AE9A0[];
extern "C" u32 getTotalFreeSize__7JKRHeapFv(void* heap);
extern "C" void __dl__FPv(void* p);


extern void* lbl_8053ADB8;
extern "C" void* fn_803D5090(void* game);
extern void* lbl_8053AD68;
extern void* lbl_8053ADA0;
extern void* lbl_8053ADA8;
extern void* lbl_8053ADC0;
extern "C" void fn_803B6768(void* p);
extern "C" void fn_803B8188(void* p);
extern "C" void fn_803D87C0(void* p);
extern "C" void fn_803A97A0(void* p);
extern "C" void fn_803B7E64(void* p);
extern "C" void fn_803D8670(void* p);
extern "C" void* fn_8037AA7C(void);
extern "C" void fn_803A8F5C(void* p);
extern "C" void fn_803B31AC(void* p);
extern "C" void fn_803B7DCC(void* p);
extern "C" void fn_803D8364(void);
extern "C" void fn_803D82EC(void* p);
extern void* lbl_8053AAF8;
extern "C" BOOL fn_80379F84(void* this_) {
    if (*((u8*)lbl_8053AAF8 + 0x7f) == 1 && *((u8*)lbl_8053AAF8 + 0x7e) == 1 && lbl_8053AD68 != 0 &&
        *(void**)((u8*)this_ + 4) != 0) {
        u8 v = *((u8*)lbl_8053ADA0 + 0x4c0);
        if (v != 5 && v != 8 && v != 7 && v != 9) {
            return TRUE;
        }
    }
    return FALSE;
}

extern u8 lbl_80529DEC[];
extern u8 lbl_8050EC80[];
extern "C" void fn_80379FF4(void) {
    s32 x = *(s32*)(lbl_80529DEC + 0x118);
    s32 y = *(s32*)(lbl_80529DEC + 0x11c);
    if (x < 8 && y < 4 && x >= 0 && x <= 7 && y >= 0 && y <= 3) {
        u8* rec = lbl_8050EC80 + *(s32*)(lbl_8050EC80 + 0x10) * 0xc8;
        *(u32*)(rec + 0x28) |= 1 << (y + x * 4);
    }
    if (x >= 8) {
        return;
    }
    s32 ny = y + 1;
    if (ny > 3) {
        s32 nx = x + 1;
        ny = 0;
        if (nx >= 8) {
            nx = 0;
        }
        *(s32*)(lbl_80529DEC + 0x118) = nx;
    } else {
        if ((x == 0 && ny == 2) || (x == 1 && ny == 2) || (x == 2 && ny == 2) || (x == 3 && ny == 2) ||
            (x == 4 && ny == 2) || (x == 5 && ny == 2) || (x == 6 && ny == 2) || (x == 7 && ny == 1)) {
            ny++;
        }
    }
    *(s32*)(lbl_80529DEC + 0x11c) = ny;
}

extern "C" u8 fn_8037A120(void) {
    if (*(void**)((u8*)lbl_8053AD68 + 4) != 0) {
        return *((u8*)lbl_8053ADA0 + 0x4c0);
    }
    if (*(void**)((u8*)lbl_8053AD68 + 8) != 0) {
        return *((u8*)lbl_8053ADA8 + 0x294);
    }
    if (*(void**)((u8*)lbl_8053AD68 + 0xc) != 0) {
        return *((u8*)lbl_8053ADC0 + 0x76);
    }
    return 0;
}

extern "C" void fn_8037A580(u8* p) {
    if (*(void**)(p + 4) != 0) {
        u32 v = *((u8*)lbl_8053ADA0 + 0x4c0);
        u8 c = v;
        if (c != 5 && c != 8 && c != 7) {
            fn_803A8F5C(lbl_8053ADA0);
        } else {
            fn_8037AA7C();
            fn_803B31AC(lbl_8053ADA0);
        }
    }
    if (*(void**)(p + 8) != 0) {
        u32 v = *((u8*)lbl_8053ADA8 + 0x294);
        u8 c = v;
        if (c == 5 || c == 8 || c == 7) {
            fn_8037AA7C();
            fn_803B7DCC(lbl_8053ADA8);
        }
    }
    if (*(void**)(p + 0xc) != 0) {
        u32 v = *((u8*)lbl_8053ADC0 + 0x76);
        u8 c = v;
        if (c == 2 || c == 8 || c == 7) {
            fn_803D8364();
            fn_803D82EC(lbl_8053ADC0);
        }
    }
}

extern "C" void fn_8037A664(u8* p) {
    if (*(void**)(p + 4) != 0) {
        u32 v = *((u8*)lbl_8053ADA0 + 0x4c0);
        u8 c = v;
        if (c != 5 && c != 8 && c != 7) {
            fn_803A97A0(lbl_8053ADA0);
        }
    }
    if (*(void**)(p + 8) != 0) {
        u32 v = *((u8*)lbl_8053ADA8 + 0x294);
        u8 c = v;
        if (c != 5 && c != 8 && c != 7) {
            fn_803B7E64(lbl_8053ADA8);
        }
    }
    if (*(void**)(p + 0xc) != 0) {
        fn_803D8670(lbl_8053ADC0);
    }
}

extern "C" void fn_8037A708(u8* p) {
    if (*(void**)(p + 4) != 0) {
        fn_803B6768(*(void**)(p + 4));
    }
    if (*(void**)(p + 8) != 0) {
        fn_803B8188(*(void**)(p + 8));
    }
    if (*(void**)(p + 0xc) != 0) {
        fn_803D87C0(*(void**)(p + 0xc));
    }
    p[0x1c] = 0;
}

extern "C" void* fn_8037A768(void* this_, short flag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804AE9A0;
        getTotalFreeSize__7JKRHeapFv(*(void**)(lbl_80529DEC + 0x8));
        lbl_80529DEC[0x242] = 0;
        VObj* p1 = *(VObj**)((u8*)this_ + 0x4);
        if (p1 != 0 && p1 != 0) {
            p1->v00(1);
        }
        *(void**)((u8*)this_ + 0x4) = 0;
        VObj* p2 = *(VObj**)((u8*)this_ + 0x8);
        if (p2 != 0 && p2 != 0) {
            p2->v00(1);
        }
        *(void**)((u8*)this_ + 0x8) = 0;
        VObj* p3 = *(VObj**)((u8*)this_ + 0xc);
        if (p3 != 0 && p3 != 0) {
            p3->v00(1);
        }
        *(void**)((u8*)this_ + 0xc) = 0;
        getTotalFreeSize__7JKRHeapFv(*(void**)(lbl_80529DEC + 0x8));
        VObj* p4 = *(VObj**)((u8*)this_ + 0x10);
        if (p4 != 0) {
            p4->v00(1);
        }
        *(void**)((u8*)this_ + 0x10) = 0;
        ((VObj*)*(void**)((u8*)this_ + 0x14))->v07();
        VObj* p5 = *(VObj**)((u8*)this_ + 0x18);
        if (p5 != 0) {
            p5->v07();
        }
        lbl_8053AD68 = 0;
        if (flag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern u8 lbl_804AE9A0[];
extern void* lbl_8053AB10;
extern "C" void* __nw__FUl(u32 size);
extern "C" u32 getTotalFreeSize__7JKRHeapFv(void* heap);
extern "C" void fn_80158B3C(void* p);
extern "C" void fn_803D901C(void* p);
extern "C" void fn_803B8414(void* p);
extern "C" void fn_803B6FD8(void* p);
extern "C" void fn_803D58E0(void* a, void* b, s32 c);
extern "C" void* fn_8037A8D4(void* this_) {
    u8* p = (u8*)this_;
    void* obj;

    *(void**)p = lbl_804AE9A0;
    getTotalFreeSize__7JKRHeapFv(*(void**)(lbl_80529DEC + 8));
    lbl_8053AD68 = this_;
    fn_80158B3C(*(void**)((u8*)lbl_8053AB10 + 0x2c));
    *(void**)(p + 0x14) = *(void**)(lbl_80529DEC + 0x38);
    *(void**)(p + 0x18) = 0;
    p[0x1d] = 0;
    p[0x1e] = 0;
    *(void**)(p + 4) = 0;
    *(void**)(p + 8) = 0;
    *(void**)(p + 0xc) = 0;

    if (*((u8*)lbl_8053AAF8 + 0x7f) != 0) {
        if (*((u8*)lbl_8053AAF8 + 0x7e) != 0) {
            *(void**)(p + 0x18) = *(void**)(lbl_80529DEC + 0x44);
            *(void**)(lbl_80529DEC + 0x3c) = *(void**)(p + 0x18);
            obj = __nw__FUl(0x4e0);
            if (obj != 0) {
                fn_803B6FD8(obj);
            }
            *(void**)(p + 4) = obj;
        } else {
            *(void**)(p + 0x18) = *(void**)(lbl_80529DEC + 0x40);
            *(void**)(lbl_80529DEC + 0x3c) = *(void**)(p + 0x18);
            obj = __nw__FUl(0x2a0);
            if (obj != 0) {
                fn_803B8414(obj);
            }
            *(void**)(p + 8) = obj;
        }
    } else {
        obj = __nw__FUl(0x84);
        if (obj != 0) {
            fn_803D901C(obj);
        }
        *(void**)(p + 0xc) = obj;
    }

    getTotalFreeSize__7JKRHeapFv(*(void**)(lbl_80529DEC + 8));
    obj = __nw__FUl(0x2180);
    if (obj != 0) {
        fn_803D58E0(obj, *(void**)((u8*)lbl_8053AD68 + 0x14), 1);
    }
    *(void**)(p + 0x10) = obj;
    p[0x1c] = 0;
    return this_;
}

extern "C" u8 fn_8037AA28(void) {
    return *((u8*)lbl_8053ADB8 + 0x216c);
}

extern "C" void* fn_8037AA34(void) { return fn_803D5090(lbl_8053ADB8); }

extern void* lbl_8053ADB8;
extern "C" void* fn_803D5554(void* game);
extern "C" void* fn_8037AA58(void) { return fn_803D5554(lbl_8053ADB8); }

extern "C" void* fn_803D521C(void* game);
extern "C" void* fn_8037AA7C(void) { return fn_803D521C(lbl_8053ADB8); }

extern "C" void __ct__17JASGenericMemPoolFv(void*);
extern "C" void __register_global_object(void*, void (*)(void*), void*);
extern "C" void __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv(void*);
extern "C" void __dt__35JASMemPool_MultiThreaded_8JASTrackFv(void*);
extern "C" void __dt__38JASMemPool_MultiThreaded_10JASChannelFv(void*);
extern "C" void __dt__29JASMemPool_15JASPoolObj3_FSAFv(void*);
extern "C" void __dt__29JASMemPool_15JASPoolObj4_FSAFv(void*);
extern "C" void __dt__22JASMemPool_9JAIStreamFv(void*);
extern "C" void __dt__27JASMemPool_13JAISoundChildFv(void*);
extern "C" void __dt__19JASMemPool_6JAISeqFv(void*);
extern "C" void __dt__18JASMemPool_5JAISeFv(void*);
extern "C" char lbl_8050D700[];
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
extern "C" void fn_8037AAA0(void) {
    char* base = lbl_8050D700;
    if (__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr == 0) {
        __ct__17JASGenericMemPoolFv(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr);
        __register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr, __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, &base[0x0]);
        __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr = 1;
    }
    if (__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack == 0) {
        __ct__17JASGenericMemPoolFv(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack);
        __register_global_object(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack, __dt__35JASMemPool_MultiThreaded_8JASTrackFv, &base[0xc]);
        __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack = 1;
    }
    if (__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel == 0) {
        __ct__17JASGenericMemPoolFv(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel);
        __register_global_object(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel, __dt__38JASMemPool_MultiThreaded_10JASChannelFv, &base[0x18]);
        __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA, __dt__29JASMemPool_15JASPoolObj3_FSAFv, &base[0x24]);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA, __dt__29JASMemPool_15JASPoolObj4_FSAFv, &base[0x30]);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA = 1;
    }
    if (__init__memPool___30JASPoolAllocObject_9JAIStream == 0) {
        __ct__17JASGenericMemPoolFv(memPool___30JASPoolAllocObject_9JAIStream);
        __register_global_object(memPool___30JASPoolAllocObject_9JAIStream, __dt__22JASMemPool_9JAIStreamFv, &base[0x3c]);
        __init__memPool___30JASPoolAllocObject_9JAIStream = 1;
    }
    if (__init__memPool___35JASPoolAllocObject_13JAISoundChild == 0) {
        __ct__17JASGenericMemPoolFv(memPool___35JASPoolAllocObject_13JAISoundChild);
        __register_global_object(memPool___35JASPoolAllocObject_13JAISoundChild, __dt__27JASMemPool_13JAISoundChildFv, &base[0x48]);
        __init__memPool___35JASPoolAllocObject_13JAISoundChild = 1;
    }
    if (__init__memPool___27JASPoolAllocObject_6JAISeq == 0) {
        __ct__17JASGenericMemPoolFv(memPool___27JASPoolAllocObject_6JAISeq);
        __register_global_object(memPool___27JASPoolAllocObject_6JAISeq, __dt__19JASMemPool_6JAISeqFv, &base[0x54]);
        __init__memPool___27JASPoolAllocObject_6JAISeq = 1;
    }
    if (__init__memPool___26JASPoolAllocObject_5JAISe == 0) {
        __ct__17JASGenericMemPoolFv(memPool___26JASPoolAllocObject_5JAISe);
        __register_global_object(memPool___26JASPoolAllocObject_5JAISe, __dt__18JASMemPool_5JAISeFv, &base[0x60]);
        __init__memPool___26JASPoolAllocObject_5JAISe = 1;
    }
}

