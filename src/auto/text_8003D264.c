// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern "C" void __ct__17JASGenericMemPoolFv(void*);
extern "C" void __register_global_object(void*, void*, void*);
extern "C" void __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv(void*);
extern "C" void __dt__35JASMemPool_MultiThreaded_8JASTrackFv(void*);
extern "C" void __dt__38JASMemPool_MultiThreaded_10JASChannelFv(void*);
extern "C" void __dt__29JASMemPool_15JASPoolObj4_FSAFv(void*);
extern "C" void __dt__29JASMemPool_15JASPoolObj3_FSAFv(void*);
extern "C" void fn_8003D584(void*);
extern "C" void fn_8003D530(void*);
extern "C" void fn_8003D4DC(void*);
extern "C" void fn_8003D488(void*);
extern char lbl_804B4C28[];
extern char memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr[];
extern char memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack[];
extern char memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel[];
extern char memPool___37JASPoolAllocObject_15JASPoolObj4_FSA[];
extern char memPool___37JASPoolAllocObject_15JASPoolObj3_FSA[];
extern char lbl_8052E78C[];
extern char lbl_8052E79C[];
extern char lbl_8052E7AC[];
extern char lbl_8052E7BC[];
extern char __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr;
extern char __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack;
extern char __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel;
extern char __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA;
extern char __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA;
extern char lbl_8053A3C0;
extern char lbl_8053A3C1;
extern char lbl_8053A3C2;
extern char lbl_8053A3C3;
void fn_8003D264(void)
{
    char* base = lbl_804B4C28;

    if (__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr == 0) {
        __ct__17JASGenericMemPoolFv(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr);
        __register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr,
                                 (void*)__dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, base);
        __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr = 1;
    }
    if (__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack == 0) {
        __ct__17JASGenericMemPoolFv(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack);
        __register_global_object(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack,
                                 (void*)__dt__35JASMemPool_MultiThreaded_8JASTrackFv, base + 0xc);
        __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack = 1;
    }
    if (__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel == 0) {
        __ct__17JASGenericMemPoolFv(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel);
        __register_global_object(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel,
                                 (void*)__dt__38JASMemPool_MultiThreaded_10JASChannelFv, base + 0x18);
        __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel = 1;
    }
    if (lbl_8053A3C0 == 0) {
        __ct__17JASGenericMemPoolFv(lbl_8052E78C);
        __register_global_object(lbl_8052E78C, (void*)fn_8003D584, base + 0x24);
        lbl_8053A3C0 = 1;
    }
    if (lbl_8053A3C1 == 0) {
        __ct__17JASGenericMemPoolFv(lbl_8052E79C);
        __register_global_object(lbl_8052E79C, (void*)fn_8003D530, base + 0x30);
        lbl_8053A3C1 = 1;
    }
    if (lbl_8053A3C2 == 0) {
        __ct__17JASGenericMemPoolFv(lbl_8052E7AC);
        __register_global_object(lbl_8052E7AC, (void*)fn_8003D4DC, base + 0x3c);
        lbl_8053A3C2 = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA,
                                 (void*)__dt__29JASMemPool_15JASPoolObj4_FSAFv, base + 0x48);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA = 1;
    }
    if (lbl_8053A3C3 == 0) {
        __ct__17JASGenericMemPoolFv(lbl_8052E7BC);
        __register_global_object(lbl_8052E7BC, (void*)fn_8003D488, base + 0x54);
        lbl_8053A3C3 = 1;
    }
    if (__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA == 0) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA,
                                 (void*)__dt__29JASMemPool_15JASPoolObj3_FSAFv, base + 0x60);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA = 1;
    }
}
