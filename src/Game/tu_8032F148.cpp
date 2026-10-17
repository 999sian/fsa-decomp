#include "Game/ItemBase.h"

extern "C" void fn_801EE434(void* handle);
extern "C" void __dt__5ActorFv(void* this_, int how);
extern "C" void __dl__FPv(void* p);
extern void* lbl_804AB8C0[];

extern "C" void* fn_801F856C(void);
extern "C" int fn_801F78F4(void* mgr, unsigned int code, int idx);
extern "C" void* fn_801F666C(void* mgr, int idx);
extern "C" unsigned char fn_801F6758(void* pos, int idx, float margin);
extern float lbl_80541EEC;
extern "C" int fn_8013CC50(int, char*, float, int, int, int, int, int, int);
extern "C" void fn_8013CB44(void*, void*, int, int, int);
extern float lbl_80541EBC;
extern "C" void fn_803319B8(char* this_) {
    extern unsigned char* lbl_8053AAF8;
    extern int fn_801F0E34(void* this_, unsigned int id, int c);
    extern float lbl_80541EFC;
    extern float lbl_80541EBC;
    int table[4] = {0, 1, 0, 1};
    *(int*)(this_ + 0x264) = table[*(int*)(this_ + 0x254)] + ((*(int*)(this_ + 0x98) & 1) << 1);
    if (*(int*)(this_ + 0x230) == 9) {
        if (lbl_8053AAF8[0x7f] == 1) {
            *(int*)(this_ + 0x264) += 4;
        } else {
            *(int*)(this_ + 0x264) += 8;
        }
    } else if (*(unsigned char*)(this_ + 0x2a3) == 1 && *(unsigned char*)(this_ + 0x2a8) == 0 &&
               (*(float*)(this_ + 0x14) > lbl_80541EFC || *(int*)(this_ + 0x230) == 1)) {
        if (*(int*)(this_ + 0x254) == 0) {
            if (*(int*)(this_ + 0x98) & 1) {
                *(int*)(this_ + 0x264) = 0xd;
            } else {
                *(int*)(this_ + 0x264) = 0xc;
            }
            fn_801F0E34(this_, 0x40001, 0);
        }
        if ((*(int*)(this_ + 0x254) & 1) == 0) {
            if (*(unsigned char*)(this_ + 0x2a1) == 0) {
                fn_8013CC50(*(int*)(this_ + 4), this_ + 0xc, lbl_80541EBC, 0x348, 0, 0, 0, 0, 1);
            } else {
                fn_8013CC50(*(int*)(this_ + 4), this_ + 0xc, lbl_80541EBC, 0xd2, 0, 0, 0, 0, 1);
            }
        }
    }
}

extern "C" void fn_80331B40(char* this_) {
    if (*(unsigned char*)(this_ + 0x2a3) == 1) {
        if (*(int*)(this_ + 0x230) == 1) {
            void* h = *(void**)(this_ + 0x2fc);
            if (h == 0) {
                *(int*)(this_ + 0x2fc) = fn_8013CC50(*(int*)(this_ + 4), this_ + 0xc, lbl_80541EBC, 0x116, 0, 3, 0, 0, 1);
            } else {
                fn_8013CB44(h, this_ + 0xc, 0, 3, 1);
            }
        } else {
            void* h = *(void**)(this_ + 0x2fc);
            if (h != 0) {
                *(unsigned int*)((char*)h + 0xf4) |= 1;
                *(int*)((char*)h + 0x24) = 1;
                *(int*)(this_ + 0x2fc) = 0;
            }
            h = *(void**)(this_ + 0x300);
            if (h != 0) {
                *(unsigned int*)((char*)h + 0xf4) |= 1;
                *(int*)((char*)h + 0x24) = 1;
                *(int*)(this_ + 0x300) = 0;
            }
        }
    }
}

extern "C" void fn_80331C24(char* this_) {
    extern unsigned short fn_8022461C(void* a, int b);
    extern int fn_801F0E34(void* this_, unsigned int id, int c);
    extern float lbl_80541EE8;
    if (*(int*)(this_ + 0x290) == 0 || *(int*)(this_ + 0x290) == 6) {
        int code = fn_8022461C(this_ + 0xc, *(int*)(this_ + 4));
        if (code == 0x39 &&
            ((*(int*)(this_ + 0x230) == 0 && *(int*)(this_ + 0x258) == 0) || *(int*)(this_ + 0x230) == 1) &&
            *(float*)(this_ + 0x14) < lbl_80541EE8) {
            fn_801F0E34(this_, 0x4007f, 0);
            void* h = *(void**)(this_ + 0x2f8);
            if (h == 0) {
                *(int*)(this_ + 0x2f8) = fn_8013CC50(*(int*)(this_ + 4), this_ + 0xc, lbl_80541EBC, 0x4d2, 0, 3, 0, 0, 1);
            } else {
                fn_8013CB44(h, this_ + 0xc, 0, 3, 1);
            }
        } else {
            void* h = *(void**)(this_ + 0x2f8);
            if (h != 0) {
                *(unsigned int*)((char*)h + 0xf4) |= 1;
                *(int*)((char*)h + 0x24) = 1;
                *(int*)(this_ + 0x2f8) = 0;
            }
        }
    }
}

extern "C" void fn_80331D38(char* this_) {
    extern unsigned char fn_8023F264(int idx);
    extern unsigned char fn_80239C00(int idx, void* box, int a2);
    extern unsigned char fn_8022F9E4(int idx, int a0, unsigned char a1, unsigned char a2);
    extern float lbl_80541E9C;
    extern float lbl_80541EFC;
    if (*(float*)(this_ + 0x14) < lbl_80541EFC && *(int*)(this_ + 0x268) > 0) {
        float box[4];
        int i = 0;
        box[0] = *(float*)(this_ + 0x60);
        box[1] = *(float*)(this_ + 0x64);
        box[2] = *(float*)(this_ + 0x68);
        box[3] = *(float*)(this_ + 0x6c);
        box[0] += *(float*)(this_ + 0xc);
        box[1] += *(float*)(this_ + 0x10);
        box[2] += *(float*)(this_ + 0xc);
        box[3] += *(float*)(this_ + 0x10);
        do {
            if (fn_8023F264(i) && fn_80239C00(i, box, *(int*)(this_ + 4)) &&
                fn_8022F9E4(i, *(int*)(this_ + 0x198), 1, 0)) {
                float zero = lbl_80541E9C;
                *(float*)(this_ + 0x14) = zero;
                *(int*)(this_ + 0x258) = 0;
                *(int*)(this_ + 0x238) = 0;
                *(int*)(this_ + 0x240) = 0;
                *(float*)(this_ + 0x2b8) = zero;
                *(float*)(this_ + 0x2bc) = zero;
                *(float*)(this_ + 0x2c0) = zero;
                *(float*)(this_ + 0x3c) = zero;
                *(float*)(this_ + 0x40) = zero;
                *(float*)(this_ + 0x44) = zero;
                *(int*)(this_ + 0x25c) = *(int*)(this_ + 0xc8);
                *(int*)(this_ + 0xb8) = 2;
                *(int*)(this_ + 0x230) = 3;
                return;
            }
            i++;
        } while (i < 4);
    }
}

extern "C" unsigned char fn_801F2618(char* a, float* out, unsigned int c);
extern "C" int fn_801F11B4(char* a);
extern "C" void* fn_802D6A9C(void);
extern float lbl_80541E9C;
extern "C" unsigned char fn_80332378(char* this_) {
    float v[3];
    unsigned char r;
    v[2] = lbl_80541E9C;
    v[1] = lbl_80541E9C;
    v[0] = lbl_80541E9C;
    r = fn_801F2618(this_, v, 0);
    if (r == 1) {
        fn_801F11B4(this_);
        int id = *(int*)(this_ + 4);
        if (((unsigned char*)fn_802D6A9C())[id + 0x131df] == 1 && v[1] < lbl_80541E9C) {
            *(float*)(this_ + 0x2bc) = lbl_80541E9C;
        }
    } else {
        int n = *(int*)(this_ + 0x270);
        if (n > 0) {
            if (n != *(int*)(this_ + 0x274)) {
                *(int*)(this_ + 0x274) = n;
                *(int*)(this_ + 0x278) = 5;
            } else {
                *(int*)(this_ + 0x278) = *(int*)(this_ + 0x278) - 1;
                if (*(int*)(this_ + 0x278) <= 0) {
                    *(int*)(this_ + 0x270) = 0;
                    *(int*)(this_ + 0x274) = 0;
                }
            }
        }
        int id = *(int*)(this_ + 4);
        if (((unsigned char*)fn_802D6A9C())[id + 0x131df] == 1 && *(unsigned char*)(this_ + 0x2a9) == 1 &&
            lbl_80541E9C == *(float*)(this_ + 0x2b4)) {
            *(float*)(this_ + 0x40) = lbl_80541E9C;
            *(float*)(this_ + 0x2bc) = lbl_80541E9C;
        }
    }
    return r;
}

extern "C" void fn_80333078(char* this_) {
    int idx = -1;
    if (*(int*)(this_ + 0x16c) != -1) {
        for (;;) {
            int h = fn_801F78F4(fn_801F856C(), 0x4e495741, idx);
            idx = h;
            if (h < 0) {
                break;
            }
            char* obj = (char*)fn_801F666C(fn_801F856C(), h);
            if (obj == 0) {
                continue;
            }
            if (*(int*)(obj + 0x198) == *(int*)(this_ + 0x198)) {
                continue;
            }
            if (*(int*)(obj + 0x16c) != *(int*)(this_ + 0x16c)) {
                continue;
            }
            if (fn_801F6758(obj + 0xc, *(int*)(obj + 0x4), lbl_80541EEC) != 0 && *(unsigned char*)(obj + 0xc4) != 1) {
                continue;
            }
            *(unsigned char*)(this_ + 0x11c) = 0;
            break;
        }
    }
}

extern "C" void* fn_803336B0(char* this_, short how) {
    if (this_) {
        *(void**)this_ = lbl_804AB8C0;
        fn_801EE434(*(void**)(this_ + 0x2f4));
        fn_801EE434(*(void**)(this_ + 0x2f8));
        fn_801EE434(*(void**)(this_ + 0x2fc));
        fn_801EE434(*(void**)(this_ + 0x300));
        __dt__5ActorFv(this_, 0);
        if (how > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" char lbl_805091F8[];
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
extern "C" void fn_80333734(void) {
    if (__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr == 0) {
        __ct__17JASGenericMemPoolFv(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr);
        __register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr, __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, lbl_805091F8 + 0x0);
        __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr = 1;
    }
    if (__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack == 0) {
        __ct__17JASGenericMemPoolFv(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack);
        __register_global_object(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack, __dt__35JASMemPool_MultiThreaded_8JASTrackFv, lbl_805091F8 + 0xc);
        __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack = 1;
    }
    if (__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel == 0) {
        __ct__17JASGenericMemPoolFv(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel);
        __register_global_object(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel, __dt__38JASMemPool_MultiThreaded_10JASChannelFv, lbl_805091F8 + 0x18);
        __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA, __dt__29JASMemPool_15JASPoolObj3_FSAFv, lbl_805091F8 + 0x24);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA, __dt__29JASMemPool_15JASPoolObj4_FSAFv, lbl_805091F8 + 0x30);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA = 1;
    }
    if (__init__memPool___30JASPoolAllocObject_9JAIStream == 0) {
        __ct__17JASGenericMemPoolFv(memPool___30JASPoolAllocObject_9JAIStream);
        __register_global_object(memPool___30JASPoolAllocObject_9JAIStream, __dt__22JASMemPool_9JAIStreamFv, lbl_805091F8 + 0x3c);
        __init__memPool___30JASPoolAllocObject_9JAIStream = 1;
    }
    if (__init__memPool___35JASPoolAllocObject_13JAISoundChild == 0) {
        __ct__17JASGenericMemPoolFv(memPool___35JASPoolAllocObject_13JAISoundChild);
        __register_global_object(memPool___35JASPoolAllocObject_13JAISoundChild, __dt__27JASMemPool_13JAISoundChildFv, lbl_805091F8 + 0x48);
        __init__memPool___35JASPoolAllocObject_13JAISoundChild = 1;
    }
    if (__init__memPool___27JASPoolAllocObject_6JAISeq == 0) {
        __ct__17JASGenericMemPoolFv(memPool___27JASPoolAllocObject_6JAISeq);
        __register_global_object(memPool___27JASPoolAllocObject_6JAISeq, __dt__19JASMemPool_6JAISeqFv, lbl_805091F8 + 0x54);
        __init__memPool___27JASPoolAllocObject_6JAISeq = 1;
    }
    if (__init__memPool___26JASPoolAllocObject_5JAISe == 0) {
        __ct__17JASGenericMemPoolFv(memPool___26JASPoolAllocObject_5JAISe);
        __register_global_object(memPool___26JASPoolAllocObject_5JAISe, __dt__18JASMemPool_5JAISeFv, lbl_805091F8 + 0x60);
        __init__memPool___26JASPoolAllocObject_5JAISe = 1;
    }
}

