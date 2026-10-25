#include "dolphin/card.h"
#include "dolphin/os.h"
#include <string.h>


extern "C" u8 lbl_8051E2C0[];
extern "C" u8 lbl_80529DEC[];
extern "C" u8 lbl_8051C1A0[];
extern "C" char lbl_80476578[];
extern "C" void* fn_804030C4(u32 tag, char* name);
extern "C" int snprintf(char* s, unsigned long n, const char* fmt, ...);

static inline u32 calcCardChecksum(u8* data) {
    u32 sum = 0;
    u16 inv = 0;
    u16* p = (u16*)data;
    s32 i = 0x7ff;
    do {
        sum += p[0];
        inv += ~p[0];
        sum += p[1];
        inv += ~p[1];
        p += 2;
    } while (--i != 0);
    return (sum << 16) | inv;
}
#pragma optimization_level 3
extern "C" void fn_803BACF8(u8* param_1, u8 param_2) {
param_1 += param_2 * 200;
u32 inv = 0;
u32 sum = 0;
u8* p = param_1;
for (s32 i=192; i>0; i--) {
u8 b = *p++;
sum += b;
inv += ~b;
}
*(u32*)(param_1+0xc4) = inv;
*(u32*)(param_1+0xc0) = sum;
}
#pragma optimization_level 4
extern "C" u32 fn_803BADAC(u8* param_1) {
    u32 inv = 0;
    u32 sum = 0;
    u8* p = param_1;
    s32 i;

    for (i = 0; i < 0x18; i++) {
        sum += p[0]; inv += ~p[0];
        sum += p[1]; inv += ~p[1];
        sum += p[2]; inv += ~p[2];
        sum += p[3]; inv += ~p[3];
        sum += p[4]; inv += ~p[4];
        sum += p[5]; inv += ~p[5];
        sum += p[6]; inv += ~p[6];
        sum += p[7]; inv += ~p[7];
        p += 8;
    }
    return ((inv ^ *(u32*)(param_1 + 0xc4)) | (sum ^ *(u32*)(param_1 + 0xc0))) == 0;
}

static inline void cardSumBlock(u8* p, u32* sumOut, u32* invOut) {
    u32 sum = 0;
    u32 inv = 0;
    s32 i;
    for (i = 0; i < 0x18; i++) {
        sum += p[0]; inv += ~p[0];
        sum += p[1]; inv += ~p[1];
        sum += p[2]; inv += ~p[2];
        sum += p[3]; inv += ~p[3];
        sum += p[4]; inv += ~p[4];
        sum += p[5]; inv += ~p[5];
        sum += p[6]; inv += ~p[6];
        sum += p[7]; inv += ~p[7];
        p += 8;
    }
    *sumOut = sum;
    *invOut = inv;
}

extern "C" s32 fn_803BAE68(CARDFileInfo* fileInfo) {
    u8* buf = lbl_8051E2C0;
    s32 result = CARDRead(fileInfo, buf, 0x2000, 0x2000);

    if (result != 0) {
        result = CARDRead(fileInfo, buf, 0x2000, 0x4000);
        if (result != 0) {
            return result;
        }
    }
    *(u8*)(lbl_80529DEC + 0x244) = buf[3];
    *(u8*)(lbl_80529DEC + 0x246) = buf[4];
    return 0;
}

extern "C" s32 fn_803BAEF4(CARDFileInfo* fileInfo, void* dst, s32 unused, s32 size) {
    u8* base = lbl_8051E2C0;
    u8* blkB = base + 0x2000;
    u32 sumA0, invA0, sumA1, invA1, sumA2, invA2;
    u32 sumB0, invB0, sumB1, invB1, sumB2, invB2;
    bool changed = false;
    s32 result;

    result = CARDRead(fileInfo, base, 0x2000, 0x2000);
    if (result != 0) {
        return result;
    }
    result = CARDRead(fileInfo, blkB, 0x2000, 0x4000);
    if (result != 0) {
        return result;
    }

    cardSumBlock(base + 0xa, &sumA0, &invA0);
    cardSumBlock(base + 0xd2, &sumA1, &invA1);
    cardSumBlock(base + 0x19a, &sumA2, &invA2);
    cardSumBlock(blkB + 0xa, &sumB0, &invB0);
    cardSumBlock(blkB + 0xd2, &sumB1, &invB1);
    cardSumBlock(blkB + 0x19a, &sumB2, &invB2);

    if (((sumA0 ^ *(u32*)(base + 0xca)) | (invA0 ^ *(u32*)(base + 0xce))) == 0) {
        memcpy(blkB + 0xa, base + 0xa, 200);
    } else if (((sumB0 ^ *(u32*)(blkB + 0xca)) | (invB0 ^ *(u32*)(blkB + 0xce))) == 0) {
        memcpy(base + 0xa, blkB + 0xa, 200);
        changed = true;
    }

    (void)changed;
    (void)dst;
    (void)size;
    (void)unused;
    return 0;
}

extern "C" s32 fn_803BBF08(CARDFileInfo* fileInfo, void* src, s32 unused, s32 size) {
    u8* base = lbl_8051E2C0;
    char* fmt = lbl_80476578;
    OSCalendarTime cal;
    CARDStat stat;
    CARDStat tailStat;
    s32 result;
    u8* buf0;
    u8* buf1;
    u32 chk0;
    u32 chk1;
    u8* res0;
    u8* res1;
    bool bVar3;

    snprintf((char*)(base + 0x4000) + 0x1c00, 0x20, fmt);
    OSTicksToCalendarTime(OSGetTime(), &cal);
    snprintf((char*)(base + 0x4000) + 0x1c20, 0x20, fmt + 0x18, cal.mon + 1, cal.mday);
    res0 = (u8*)fn_804030C4(0x54494D47, fmt + 0x28);
    res1 = (u8*)fn_804030C4(0x54494D47, fmt + 0x40);
    memcpy(base + 0x4000, res0 + *(u32*)(res0 + 0x1c), *(u16*)(res0 + 0xa) * 2 + 0xc00);
    memcpy((base + 0x4000) + 0xe00, res1 + *(u32*)(res1 + 0x1c), *(u16*)(res1 + 0xa) * 2 + 0x400);
    result = CARDWrite(fileInfo, base + 0x4000, 0x2000, 0);
    if (result != 0) {
        return result;
    }
    CARDGetStatus(lbl_8051C1A0[0x1ff4], fileInfo->fileNo, &stat);
    if (stat.iconAddr == 0 && stat.commentAddr == 0x1c00 && (stat.bannerFormat & 3) == 1 &&
        !(stat.bannerFormat & 4) && (stat.iconFormat & 3) == 1 &&
        (stat.iconFormat >> 2 & 3) == 0 && (stat.iconFormat >> 4 & 3) == 0 &&
        (stat.iconFormat >> 6 & 3) == 0 && (stat.iconFormat >> 8 & 3) == 0 &&
        (stat.iconFormat >> 10 & 3) == 0 && (stat.iconFormat >> 12 & 3) == 0 &&
        (stat.iconFormat >> 14 & 3) == 0 && (stat.iconSpeed & 3) == 3 &&
        (stat.iconSpeed >> 2 & 3) == 0 && (stat.iconSpeed >> 4 & 3) == 0 &&
        (stat.iconSpeed >> 6 & 3) == 0 && (stat.iconSpeed >> 8 & 3) == 0 &&
        (stat.iconSpeed >> 10 & 3) == 0 && (stat.iconSpeed >> 12 & 3) == 0 &&
        (stat.iconSpeed >> 14 & 3) == 0) {
        bVar3 = true;
    } else {
        bVar3 = false;
    }
    if (!bVar3) {
        memset(base, 0, 0x2000);
        result = CARDWrite(fileInfo, base, 0x2000, 0x2000);
        if (result != 0) {
            return result;
        }
        result = CARDWrite(fileInfo, base, 0x2000, 0x4000);
        if (result != 0) {
            return result;
        }
        memset(base + 0x6000, 0, 0x1d4c);
        memset(base + 0x7d60, 0, 0x1d4c);
    }
    buf0 = base;
    buf1 = base + 0x2000;
    *(u16*)buf0 = 0;
    *(u16*)buf1 = 0;
    memcpy(buf0 + 0xa, src, size);
    memcpy(buf1 + 0xa, src, size);
    memcpy(buf0 + 0x262, base + 0x6000, 0x1d4c);
    memcpy(buf1 + 0x262, base + 0x7d60, 0x1d4c);
    buf0[2] = lbl_80529DEC[0x245];
    buf1[2] = lbl_80529DEC[0x245];
    buf0[3] = lbl_80529DEC[0x244];
    buf1[3] = lbl_80529DEC[0x244];
    buf0[4] = lbl_80529DEC[0x246];
    buf1[4] = lbl_80529DEC[0x246];
    chk0 = calcCardChecksum(buf0);
    *(u32*)(buf0 + 0x1ffc) = chk0;
    chk1 = calcCardChecksum(buf1);
    *(u32*)(buf1 + 0x1ffc) = chk1;
    result = CARDWrite(fileInfo, buf0, 0x2000, 0x2000);
    if (result != 0) {
        return result;
    }
    result = CARDRead(fileInfo, buf0, 0x2000, 0x2000);
    if (result != 0) {
        return result;
    }
    if (chk0 != calcCardChecksum(buf0)) {
        return 0;
    }
    result = CARDWrite(fileInfo, buf1, 0x2000, 0x4000);
    if (result != 0) {
        return result;
    }
    result = CARDRead(fileInfo, buf1, 0x2000, 0x4000);
    if (result != 0) {
        return result;
    }
    if (chk1 != calcCardChecksum(buf1)) {
        return 0;
    }
    CARDGetStatus(lbl_8051C1A0[0x1ff4], fileInfo->fileNo, &tailStat);
    tailStat.iconAddr = 0;
    tailStat.commentAddr = 0x1c00;
    tailStat.bannerFormat = (tailStat.bannerFormat & ~3) | 1;
    tailStat.bannerFormat &= ~4;
    tailStat.iconFormat = (tailStat.iconFormat & ~3) | 1;
    tailStat.iconFormat &= ~0xc;
    tailStat.iconFormat &= ~0x30;
    tailStat.iconFormat &= ~0xc0;
    tailStat.iconFormat &= ~0x300;
    tailStat.iconFormat &= ~0xc00;
    tailStat.iconFormat &= ~0x3000;
    tailStat.iconFormat &= 0xfff;
    tailStat.iconSpeed = (tailStat.iconSpeed & ~3) | 3;
    tailStat.iconSpeed &= ~0xc;
    tailStat.iconSpeed &= ~0x30;
    tailStat.iconSpeed &= ~0xc0;
    tailStat.iconSpeed &= ~0x300;
    tailStat.iconSpeed &= ~0xc00;
    tailStat.iconSpeed &= ~0x3000;
    tailStat.iconSpeed &= 0xfff;
    CARDSetStatus(lbl_8051C1A0[0x1ff4], fileInfo->fileNo, &tailStat);
    return result;
}

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
extern "C" void fn_803BC4C8(void) {
    static u8 pad[0x9aac];
    static u32 c0[3], c1[3], c2[3], c3[3], c4[3], c5[3], c6[3], c7[3], c8[3];
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

