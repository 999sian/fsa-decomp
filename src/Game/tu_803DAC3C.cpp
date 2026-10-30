

#include "types.h"
struct FsaInitBlock { u32 w0; u32 w1; u32 w2; u32 w3; u32 w4; u32 w5; u32 w6; u32 w7; u32 w8; u32 w9; u32 w10; u32 w11; u32 w12; u32 w13; u32 w14; u32 w15; u32 w16; u32 w17; u32 w18; u32 w19; u32 w20; u32 w21; u32 w22; u32 w23; };
struct FsaInitTriple { u32 a, b, c; };
struct FsaInitTriples { FsaInitTriple t0; FsaInitTriple t1; FsaInitTriple t2; FsaInitTriple t3; FsaInitTriple t4; FsaInitTriple t5; FsaInitTriple t6; FsaInitTriple t7; };
class FsaInitOwner { public: virtual void dispatch(); };

typedef void (FsaInitOwner::*FsaInitFn)();
struct FsaInitFns { FsaInitFn t0; FsaInitFn t1; FsaInitFn t2; FsaInitFn t3; FsaInitFn t4; FsaInitFn t5; FsaInitFn t6; FsaInitFn t7; };
extern "C" FsaInitTriples lbl_804B0508[];
extern "C" char lbl_80528468[];
extern "C" char __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr;
extern "C" char memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr[];
extern "C" void __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv(void*);
extern "C" char __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack;
extern "C" char memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack[];
extern "C" void __dt__35JASMemPool_MultiThreaded_8JASTrackFv(void*);
extern "C" char __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel;
extern "C" char memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel[];
extern "C" void __dt__38JASMemPool_MultiThreaded_10JASChannelFv(void*);
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj3_FSA[];
extern "C" void __dt__29JASMemPool_15JASPoolObj3_FSAFv(void*);
extern "C" char __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA;
extern "C" char memPool___37JASPoolAllocObject_15JASPoolObj4_FSA[];
extern "C" void __dt__29JASMemPool_15JASPoolObj4_FSAFv(void*);
extern "C" char __init__memPool___30JASPoolAllocObject_9JAIStream;
extern "C" char memPool___30JASPoolAllocObject_9JAIStream[];
extern "C" void __dt__22JASMemPool_9JAIStreamFv(void*);
extern "C" char __init__memPool___35JASPoolAllocObject_13JAISoundChild;
extern "C" char memPool___35JASPoolAllocObject_13JAISoundChild[];
extern "C" void __dt__27JASMemPool_13JAISoundChildFv(void*);
extern "C" char __init__memPool___27JASPoolAllocObject_6JAISeq;
extern "C" char memPool___27JASPoolAllocObject_6JAISeq[];
extern "C" void __dt__19JASMemPool_6JAISeqFv(void*);
extern "C" char __init__memPool___26JASPoolAllocObject_5JAISe;
extern "C" char memPool___26JASPoolAllocObject_5JAISe[];
extern "C" void __dt__18JASMemPool_5JAISeFv(void*);
extern "C" void __ct__17JASGenericMemPoolFv(void*);
extern "C" void __register_global_object(void*, void (*)(void*), void*);
#include "dolphin/dvd/dvd.h"
#include "dolphin/dvd/dvdfs.h"
#include "JSystem/J2D/J2DScreen.h"
#include "JSystem/JKernel/JKRArchive.h"
#include "JSystem/J2D/J2DPicture.h"

struct FsaVirtObj {
    virtual void v0(void);
    virtual void v1(void);
    virtual void v2(void);
    virtual void v3(void);
    virtual void v4(void);
    virtual void v5(void);
    virtual void v6(void);
    virtual void set9(s32);
    virtual void v10(void);
    virtual void v11(void);
    virtual void v12(void);
    virtual void v13(void);
    virtual void v14(void);
    virtual void v15(void);
    virtual void v16(void);
    virtual void v17(void);
    virtual void v18(void);
    virtual void v19(void);
    virtual void v20(void);
    virtual void v21(void);
    virtual void v22(void);
    virtual void v23(void);
    virtual void v24(void);
    virtual void v25(void);
    virtual void v26(void);
    virtual void v27(void);
    virtual void v28(void);
    virtual void v29(void);
    virtual void v30(void);
    virtual void v31(void);
    virtual void v32(void);
    virtual void v33(void);
    virtual void v34(void);
    virtual void v35(void);
    virtual void v36(void);
    virtual void v37(void);
    virtual void v38(void);
    virtual void v39(void);
    virtual void v40(void);
    virtual void v41(void);
    virtual void v42(void);
    virtual void v43(void);
    virtual void v44(void);
    virtual void v45(void);
    virtual void v46(void);
    virtual void v47(void);
    virtual void v48(void);
    virtual void v49(void);
    virtual void v50(void);
    virtual void v51(void);
    virtual void v52(void);
    virtual void v53(void);
    virtual void v54(void);
    virtual void v55(void);
    virtual void v56(void);
    virtual void v57(void);
    virtual void v58(void);
    virtual void set59(s32, s32, s32, f32, f32, f32, f32);
};

struct FsaDisposable {
    virtual void del(s32);
    virtual void v3(void);
};

extern "C" {
extern void* lbl_8053ADD0;
extern const float lbl_8054360C;
extern const float lbl_80543610;
extern const float lbl_80543604;
extern const float lbl_80543608;
extern const float lbl_805435E8;
extern const float lbl_805435F8;
extern const float lbl_805435FC;
extern const float lbl_80543600;
extern const float lbl_80543614;
extern const float lbl_8054361C;
extern const float lbl_8054362C;
extern const float lbl_80543618;
extern const float lbl_80543620;
extern const float lbl_80543624;
extern const float lbl_80543630;
extern u64 lbl_804774C8[];
extern void* lbl_8053AED8;
u8 fn_80402B10(void*, s32, f32, s32, f32);
u8 fn_80402940(void*, s32, f32, s32, f32);
void fn_80440E0C(void*, f32);
void fn_80402E08(void*, f32, f32);
extern s32 lbl_8053AF80;
extern char lbl_80477898[];
extern void* lbl_8053ACA8;
extern u8 lbl_80529DEC[];
extern u8 lbl_8050DB0C[];
u8 fn_80457F80(s32, u32*, s32);
void OSSetSaveRegion(void*, void*);
void OSSetBootDol(u32);
BOOL __PADDisableRecalibration(BOOL);
void fn_802B1558(void*);
void fn_803DAC58(void*, s32, f32);
}

extern "C" int fn_803DAC3C(void)
{
    if (lbl_8053ADD0 != 0) {
        return *(int*)((u8*)lbl_8053ADD0 + 0x68);
    }
    return 2;
}

extern "C" void fn_803DCCA4(u8* self)
{
    f32 f31;
    if (*(s32*)(self + 0x90) != 0) {
        *(s32*)(self + 0x90) = *(s32*)(self + 0x90) + 1;
        f31 = (f32)*(s32*)(self + 0x90) / (f32)*(s16*)(lbl_8050DB0C + 0x12e);
        if (*(s32*)(self + 0x90) >= *(s16*)(lbl_8050DB0C + 0x12e)) {
            *(s32*)(self + 0x90) = 0;
        }
        if (self[0x9e] != 0 && self[0x9f] != 0) {
            (*(J2DScreen**)(self + 0x8))->search(0x50696d3031ULL)->setAlpha(0);
            (*(J2DScreen**)(self + 0x8))->search(0x50696d3032ULL)->setAlpha(0);
        }
        if (self[0x9e] != 1 && self[0x9f] != 1) {
            (*(J2DScreen**)(self + 0x8))->search(0x50696d3131ULL)->setAlpha(0);
            (*(J2DScreen**)(self + 0x8))->search(0x50696d3132ULL)->setAlpha(0);
        }
        if (*(s32*)(self + 0x84) != 2) {
            switch (self[0x9e]) {
            case 0:
                (*(J2DScreen**)(self + 0x8))->search(0x50696d3031ULL)->setAlpha((u8)(self[0x11a] * f31));
                (*(J2DScreen**)(self + 0x8))->search(0x50696d3032ULL)->setAlpha((u8)(self[0x11b] * f31));
                break;
            case 1:
                (*(J2DScreen**)(self + 0x8))->search(0x50696d3131ULL)->setAlpha((u8)(self[0x11c] * f31));
                (*(J2DScreen**)(self + 0x8))->search(0x50696d3132ULL)->setAlpha((u8)(self[0x11d] * f31));
                break;
            case 2:
                break;
            }
        }
        f31 = lbl_805435E8 - f31;
        if (*(s32*)(self + 0x84) != 1 || self[0x9e] != self[0x9f]) {
            switch (self[0x9f]) {
            case 0:
                (*(J2DScreen**)(self + 0x8))->search(0x50696d3031ULL)->setAlpha((u8)(self[0x11a] * f31));
                (*(J2DScreen**)(self + 0x8))->search(0x50696d3032ULL)->setAlpha((u8)(self[0x11b] * f31));
                break;
            case 1:
                (*(J2DScreen**)(self + 0x8))->search(0x50696d3131ULL)->setAlpha((u8)(self[0x11c] * f31));
                (*(J2DScreen**)(self + 0x8))->search(0x50696d3132ULL)->setAlpha((u8)(self[0x11d] * f31));
                break;
            case 2:
                break;
            }
        }
    }
}

extern "C" void fn_803DD19C(void)
{
}

extern "C" void fn_803DD1A0(void)
{
}

extern "C" void fn_803DD1A4(u8* self) {
    f32 f31;
    s32 v = *(s32*)(self + 0x8c);
    if (v < 30) {
        f31 = (f32)(v * v) / lbl_805435F8;
    } else {
        s32 t = v - 30;
        f31 = lbl_805435E8 - (f32)(t * t) / lbl_805435F8;
    }
    s32 d;
    s32 w = *(s32*)(self + 0x88);
    if (w < 5) {
        d = w;
    } else {
        d = 10 - w;
    }
    f32 f30 = lbl_805435FC * (f32)(d * d) / lbl_80543600;
    if (*(s32*)(self + 0x80) == 0) {
        fn_80402E08(*(void**)(self + 0x50), lbl_80543604, f30);
        fn_80402E08(*(void**)(self + 0x54), lbl_80543604, lbl_80543604);
        fn_80402E08(*(void**)(self + 0x58), lbl_80543604, f30);
    } else {
        fn_80402E08(*(void**)(self + 0x50), lbl_80543604, lbl_80543604);
        fn_80402E08(*(void**)(self + 0x54), lbl_80543604, f30);
        fn_80402E08(*(void**)(self + 0x58), *(f32*)(*(u8**)(self + 0x54) + 8) - *(f32*)(*(u8**)(self + 0x50) + 8), f30);
    }
    J2DPane* pane = ((J2DScreen*)*(void**)(self + 0x4))->search('Paccur01');
    pane->setAlpha((u8)((f32)self[0xa2] * f31));
    pane = ((J2DScreen*)*(void**)(self + 0x4))->search('Paccur02');
    pane->setAlpha((u8)((f32)self[0xa2] * f31));
}

extern "C" void fn_803DD3DC(void)
{
}

extern "C" void fn_803DD3E0(u8* self)
{
    f32 f31;
    if (self[0x9e] == 3 || *(s32*)(self + 0x84) != 1) {
        s32 v = *(s32*)(self + 0x8c);
        if (v < 30) {
            f31 = (f32)(v * v) / lbl_805435F8;
        } else {
            s32 t = v - 30;
            f31 = lbl_805435E8 - (f32)(t * t) / lbl_805435F8;
        }
    } else {
        s32 v = *(s32*)(self + 0x8c);
        if (v < 60) {
            f31 = (f32)(v * v) / lbl_80543608;
        } else {
            s32 t = v - 60;
            f31 = lbl_805435E8 - (f32)(t * t) / lbl_80543608;
        }
    }
    s32 d;
    s32 w = *(s32*)(self + 0x88);
    if (w < 5) {
        d = w;
    } else {
        d = 10 - w;
    }
    f32 f30 = lbl_805435FC * (f32)(d * d) / lbl_80543600;
    switch (self[0x9e]) {
    case 0:
        fn_80402E08(*(void**)(self + 0x34), lbl_80543604, f30);
        fn_80402E08(*(void**)(self + 0x38), lbl_80543604, lbl_80543604);
        fn_80402E08(*(void**)(self + 0x30), lbl_80543604, lbl_80543604);
        fn_80402E08(*(void**)(self + 0x44), lbl_80543604, f30);
        fn_80402E08(*(void**)(self + 0x48), lbl_80543604, lbl_80543604);
        fn_803DAC58(self, self[0x9e], f31);
        *(u8*)(*(u8**)(*(u8**)(self + 0x40) + 4) + 0xb0) = 0;
        break;
    case 1:
        fn_80402E08(*(void**)(self + 0x34), lbl_80543604, lbl_80543604);
        fn_80402E08(*(void**)(self + 0x38), lbl_80543604, f30);
        fn_80402E08(*(void**)(self + 0x30), lbl_80543604, lbl_80543604);
        fn_80402E08(*(void**)(self + 0x44), lbl_80543604, lbl_80543604);
        fn_80402E08(*(void**)(self + 0x48), lbl_80543604, f30);
        fn_803DAC58(self, self[0x9e], f31);
        *(u8*)(*(u8**)(*(u8**)(self + 0x40) + 4) + 0xb0) = 0;
        break;
    case 2:
        fn_80402E08(*(void**)(self + 0x34), lbl_80543604, lbl_80543604);
        fn_80402E08(*(void**)(self + 0x38), lbl_80543604, lbl_80543604);
        fn_80402E08(*(void**)(self + 0x30), lbl_80543604, lbl_80543604);
        fn_80402E08(*(void**)(self + 0x44), lbl_80543604, lbl_80543604);
        fn_80402E08(*(void**)(self + 0x48), lbl_80543604, lbl_80543604);
        fn_803DAC58(self, self[0x9e], f31);
        *(u8*)(*(u8**)(*(u8**)(self + 0x40) + 4) + 0xb0) = 0;
        break;
    default:
        fn_80402E08(*(void**)(self + 0x34), lbl_80543604, lbl_80543604);
        fn_80402E08(*(void**)(self + 0x38), lbl_80543604, lbl_80543604);
        fn_80402E08(*(void**)(self + 0x44), lbl_80543604, lbl_80543604);
        fn_80402E08(*(void**)(self + 0x48), lbl_80543604, lbl_80543604);
        fn_80402E08(*(void**)(self + 0x30), lbl_80543604, f30);
        fn_80402E08(*(void**)(self + 0x40), lbl_80543604, f30);
        fn_803DAC58(self, self[0x9e], f31);
        *(u8*)(*(u8**)(*(u8**)(self + 0x40) + 4) + 0xb0) = 1;
        break;
    }
}

extern "C" void fn_803DD760(void)
{
}

extern "C" void fn_803DD764(void* self_) {
    u8* self = (u8*)self_;
    f32 inc;
    f32 threshold;
    inc = lbl_8054360C;
    *(f32*)(self + 0x7c) += inc;
    threshold = lbl_80543610;
    if (*(f32*)(self + 0x7c) >= threshold) {
        *(f32*)(self + 0x7c) = threshold;
        u32 arg = 0xb;
        DVDFileInfo fileInfo;
        if (fn_80457F80(lbl_8053AF80, &arg, -2) != 0) {
            s16 v = *(s16*)(self + 0x98);
            v -= 1;
            *(s16*)(self + 0x98) = v;
            if (v <= 0 && DVDOpen(lbl_80477898, &fileInfo) == 1) {
                u8* base = lbl_80529DEC;
                u8* dst;
                u8* src;
                u32 off;
                for (off = 0; off != 16; off += 8) {
                    src = base + off;
                    dst = (u8*)(off - 0x7f900000);
                    dst[0] = src[0x216];
                    dst[1] = src[0x217];
                    dst[2] = src[0x218];
                    dst[3] = src[0x219];
                    dst[4] = src[0x21a];
                    dst[5] = src[0x21b];
                    dst[6] = src[0x21c];
                    dst[7] = src[0x21d];
                    src = base + off + 8;
                    dst = (u8*)(off + 8 - 0x7f900000);
                    dst[0] = src[0x216];
                    dst[1] = src[0x217];
                    dst[2] = src[0x218];
                    dst[3] = src[0x219];
                    dst[4] = src[0x21a];
                    dst[5] = src[0x21b];
                    dst[6] = src[0x21c];
                    dst[7] = src[0x21d];
                }
                OSSetSaveRegion((void*)0x80700000, (void*)0x8070001f);
                __PADDisableRecalibration(1);
                fn_802B1558(lbl_8053ACA8);
                OSSetBootDol(fileInfo.startAddr);
                OSResetSystem(0, 0, 0);
            }
        }
    }
}

extern "C" void fn_803DD8E8(void* self_)
{
    u8* self = (u8*)self_;
    f32 field;
    f32 inc;
    f32 threshold;
    f32 t;
    threshold = *(volatile const f32*)&lbl_80543610;
    field = *(f32*)(self + 0x78);
    inc = lbl_8054360C;
    t = field + inc;
    *(f32*)(self + 0x78) = t;
    if (!(*(f32*)(self + 0x78) >= threshold)) return;
    *(f32*)(self + 0x78) = threshold;
    *(f32*)(self + 0x7c) = lbl_80543604;
    s32 v = *(s16*)(self + 0x9a) + 1;
    *(s16*)(self + 0x9a) = v;
    if ((s16)v > 100) *(int*)(self + 0x84) = 7;
}

extern "C" void fn_803DD93C(void* self_)
{
    u8* self = (u8*)self_;
    f32 threshold = lbl_80543610;
    f32 t = *(f32*)(self + 0x7c);
    t = t + lbl_8054360C;
    *(f32*)(self + 0x7c) = t;
    if (!(*(f32*)(self + 0x7c) >= threshold)) {
        return;
    }
    *(f32*)(self + 0x7c) = threshold;
    *(int*)(self + 0x84) = 6;
}

static inline void otherMenuIndices(s32* out, const u8* selected) {
    for (s32 i = 0; i < 2; i++) {
        if (*selected != i) *out++ = i;
    }
}
static inline void animateMenuPaneRow(u8* self) {
    u8* cur = self + 4;
    for (s32 i = 1; i < 7; i++, cur += 4) {
        fn_80402B10(*(void**)(cur + 0x14), 0x14, lbl_80543604, 0, lbl_80543614);
    }
}
extern "C" void fn_803DD970(u8* arg)
{
    u8* self = arg;
    u64* tbl;
    s32 k;
    void** q;
    u8 r28 = 0;
    u8 r27 = 0;
    s32 j;
    s32 i;
    void** pp;
    s32 n;
    u64* pair;
    s32 buf[2];
    s32* p;
    s32 v;
    s32 t;
    f32 f31;
    f32 f30;
    f32 phase;
    void* obj;

    s16 frame = *(s16*)(self + 0x9c);
    tbl = lbl_804774C8;
    *(s16*)(self + 0x9c) = frame + 1;
    p = buf;
    for (v = 0; v < 2; v++) {
        if (self[0x9e] != v) *p++ = v;
    }
    if (*(s16*)(self + 0x9c) > 0) {
        r28 = fn_80402B10(*(void**)(self + 0x14), 0x14, lbl_80543604, 0, lbl_80543614);
        u8* cur;
        int index;
        cur = self + 4;
        for (index = 1; index < 7; index++, cur += 4) {
            fn_80402B10(*(void**)(cur + 0x14), 0x14, lbl_80543604, 0, lbl_80543614);
        }
        t = *(s16*)(self + 0x9c);
        if (t > 20) {
            t = 20;
        }
        f31 = 1.0f - (f32)(t * t) / lbl_80543618;
        u64* pair = tbl;
        for (s32 n = 0; n < 50; n++) {
            if (n == 0) {
                obj = *(void**)(self + 0x8);
                obj = ((J2DScreen*)obj)->search(*pair);
                ((J2DPane*)obj)->setAlpha((u8)(f31 * (f32)self[0xa3 + n]));
            } else {
                obj = *(void**)(self + 0x4);
                obj = ((J2DScreen*)obj)->search(*pair);
                ((J2DPane*)obj)->setAlpha((u8)(f31 * (f32)self[0xa3 + n]));
            }
            pair++;
        }
    }
    q = (void**)self;
    for (j = 0, k = 10; j < 2; j++, k += 5, q++) {
        if (*(s16*)(self + 0x9c) > k) {
            fn_80402940(*(void**)((u8*)q + 0x50), 0x14, lbl_80543604, 0, lbl_8054361C);
            t = *(s16*)(self + 0x9c) - k;
            if (t > 20) {
                t = 20;
            }
            phase = (f32)(t * t) / lbl_80543618;
            if (j == 0) {
                f30 = lbl_805435E8 - phase;
                u64* pair = tbl + 109;
                for (i = 0; i < 5; i++) {
                    obj = *(void**)(self + 0x4);
                    obj = ((J2DScreen*)obj)->search(*pair);
                    ((J2DPane*)obj)->setAlpha((u8)(f30 * (f32)self[0x110 + i]));
                    pair++;
                }
            } else {
                f30 = lbl_805435E8 - phase;
                u64* pair = tbl + 114;
                for (i = 0; i < 5; i++) {
                    obj = *(void**)(self + 0x4);
                    obj = ((J2DScreen*)obj)->search(*pair);
                    ((J2DPane*)obj)->setAlpha((u8)(f30 * (f32)self[0x115 + i]));
                    pair++;
                }
            }
        }
    }
    if (*(s16*)(self + 0x9c) > 0) {
        fn_80402940(*(void**)(self + 0x34 + self[0x9e] * 4), 0x14, lbl_80543620 - *(f32*)(self + 0x6c + self[0x9e] * 4), 0, lbl_80543604);
        fn_80402940(*(void**)(self + 0x44 + self[0x9e] * 4), 0x14, lbl_80543620 - *(f32*)(self + 0x6c + self[0x9e] * 4), 0, lbl_80543604);
    }
    for (s32 delay=5;delay<6;delay++) if (*(s16*)(self + 0x9c) > delay) {
        r28 = fn_80402B10(*(void**)(self + 0x34 + buf[0] * 4), 0x14, lbl_80543614, 0, lbl_80543604);
        fn_80402B10(*(void**)(self + 0x44 + buf[0] * 4), 0x14, lbl_80543614, 0, lbl_80543604);
        t = *(s16*)(self + 0x9c) - 5;
        if (t > 20) {
            t = 20;
        }
        f30 = (f32)(t * t) / lbl_80543618;
        switch (buf[0]) {
        case 0: {
            u64* pair = tbl + 56;
            for (s32 i = 0; i < 17; i++) {
                obj = *(void**)(self + 0x4);
                obj = ((J2DScreen*)obj)->search(*pair);
                ((J2DPane*)obj)->setAlpha((u8)(f30 * (f32)self[0xdb + i]));
                pair++;
            }
            break;
        }
        case 1: {
            u64* pair = tbl + 73;
            for (s32 i = 0; i < 20; i++) {
                obj = *(void**)(self + 0x4);
                obj = ((J2DScreen*)obj)->search(*pair);
                ((J2DPane*)obj)->setAlpha((u8)(f30 * (f32)self[0xec + i]));
                pair++;
            }
            break;
        }
        }
    }
    if (*(s16*)(self + 0x9c) > 15) {
        r27 = fn_80402940(*(void**)(self + 0x30), 0xf, lbl_8054361C, 0, lbl_80543604);
        t = *(s16*)(self + 0x9c) - 15;
        if (t > 15) {
            t = 15;
        }
        f30 = (f32)(t * t) / lbl_80543624;
        u64* pair = tbl + 50;
        for (s32 i = 0; i < 6; i++) {
            obj = *(void**)(self + 0x4);
            obj = ((J2DScreen*)obj)->search(*pair);
            ((J2DPane*)obj)->setAlpha((u8)(f30 * (f32)self[0xd5 + i]));
            pair++;
        }
    }
    if (r28 && r27) {
        *(u8*)(*(u8**)(*(u8**)(self + 0x14) + 4) + 0xb0) = 0;
        *(u8*)(*(u8**)(*(u8**)(self + 0x18) + 4) + 0xb0) = 0;
        *(u8*)(*(u8**)(*(u8**)(self + 0x1c) + 4) + 0xb0) = 0;
        *(u8*)(*(u8**)(*(u8**)(self + 0x20) + 4) + 0xb0) = 0;
        *(u8*)(*(u8**)(*(u8**)(self + 0x24) + 4) + 0xb0) = 0;
        *(u8*)(*(u8**)(*(u8**)(self + 0x28) + 4) + 0xb0) = 0;
        *(u8*)(*(u8**)(*(u8**)(self + 0x2c) + 4) + 0xb0) = 0;
        *(u8*)(*(u8**)(*(u8**)(self + 0x50) + 4) + 0xb0) = 0;
        *(u8*)(*(u8**)(*(u8**)(self + 0x54) + 4) + 0xb0) = 0;
        *(s32*)(self + 0x80) = 0;
        *(s32*)(self + 0x88) = 0;
        *(s32*)(self + 0x8c) = 0;
        *(s32*)(self + 0x84) = 1;
        *(s32*)(self + 0x90) = 1;
    }
}

extern "C" s32 lbl_8053AD30;
extern "C" s32 lbl_8053AAF8;
extern "C" s32 lbl_8053AF80;
extern "C" u8 lbl_80529DEC[];
extern "C" const f32 lbl_80543620;
extern "C" const f32 lbl_8054361C;
extern "C" s32 fn_80309C4C(s32 a, s32 b, s32 c);
extern "C" s32 fn_80309A9C(s32 a, s32 b, s32 c);
extern "C" void fn_80458880(s32 a, s32 b, s32 c);
extern "C" void fn_80458F9C(s32 a, s32 b);
extern "C" void fn_80402E08(void* a, f32 b, f32 c);
extern "C" void fn_803DE05C(u8* self) {
    if (*(s32*)(self + 0x88) != 0) {
        *(s32*)(self + 0x88) += 1;
        if (*(s32*)(self + 0x88) > 10) {
            *(s32*)(self + 0x88) = 0;
        }
    }
    if (self[0x9e] == 2) {
        s32 a = ((s32 (*)(void*))(*(void**)(*(u8**)(self + 0x64) + 0x18)))(*(void**)(self + 0x64));
        s32 b = ((s32 (*)(s32))(*(void**)(*(u8**)(self + 0x64) + 0x10)))(a);
        if ((u32)(a - b) <= 1) {
            *(s32*)(self + 0x8c) = 0;
            return;
        }
    }
    if ((u32)fn_80309C4C(lbl_8053AD30, 0x1100, 1) != 0) {
        self[0xa0] = 3;
        if (*(s32*)(self + 0x80) == 0) {
            if (self[0x9e] == 0) {
                ((u8*)lbl_8053AAF8)[0x7f] = 1;
                *(s32*)(self + 0x68) = 3;
            } else if (self[0x9e] == 1) {
                ((u8*)lbl_8053AAF8)[0x7f] = 0;
                *(s32*)(self + 0x68) = 3;
            } else if (self[0x9e] == 2) {
                *(f32*)(self + 0x7c) = lbl_80543604;
                *(s32*)(self + 0x84) = 7;
                fn_80458F9C(lbl_8053AF80, 0x3c);

            }
            u8* tbl = lbl_80529DEC;
            tbl[0x23a] = self[0x9e];
            fn_80458880(lbl_8053AF80, 0xb, -1);
        } else {
            *(s16*)(self + 0x9c) = 0;

            for (s32 i = 0; i < 2; i++) {
                *(u8*)(*(u8**)(*(u8**)(self + 0x34 + i * 4) + 4) + 0xb0) = 1;
                *(u8*)(*(u8**)(*(u8**)(self + 0x44 + i * 4) + 4) + 0xb0) = 1;
                if (i == self[0x9e]) {
                    fn_80402E08(*(void**)(self + 0x34 + i * 4), lbl_80543604, lbl_80543620 - *(f32*)(self + 0x6c + i * 4));
                    fn_80402E08(*(void**)(self + 0x44 + i * 4), lbl_80543604, lbl_80543620 - *(f32*)(self + 0x6c + i * 4));
                } else {
                    fn_80402E08(*(void**)(self + 0x34 + i * 4), lbl_80543614, lbl_80543604);
                    fn_80402E08(*(void**)(self + 0x44 + i * 4), lbl_80543614, lbl_80543604);
                }
                *(s16*)(*(u8**)(self + 0x34 + i * 4) + 0x20) = 0;
                *(s16*)(*(u8**)(self + 0x34 + i * 4) + 0x22) = 0;
                *(s16*)(*(u8**)(self + 0x44 + i * 4) + 0x20) = 0;
                *(s16*)(*(u8**)(self + 0x44 + i * 4) + 0x22) = 0;
            }
            *(u8*)(*(u8**)(*(u8**)(self + 0x30) + 4) + 0xb0) = 1;
            fn_80402E08(*(void**)(self + 0x30), lbl_80543604, lbl_8054361C);
            *(s16*)(*(u8**)(self + 0x30) + 0x22) = 0;

            for (s32 i = 0; i < 7; i++) {
                f32 zero = *(volatile f32*)&lbl_80543604;
                fn_80402E08(*(void**)(self + 0x14 + i * 4), zero, zero);
                *(s16*)(*(u8**)(self + 0x14 + i * 4) + 0x20) = 0;
            }

            for (s32 i = 0; i < 2; i++) {
                f32 zero = *(volatile f32*)&lbl_80543604;
                fn_80402E08(*(void**)(self + 0x50 + i * 4), zero, zero);
                *(s16*)(*(u8**)(self + 0x50 + i * 4) + 0x22) = 0;
            }
            *(u8*)(*(u8**)(*(u8**)(self + 0x58) + 4) + 0xb0) = 0;
            *(s32*)(self + 0x84) = 4;
            fn_80458880(lbl_8053AF80, 0xc, -1);
        }
    } else if ((u32)fn_80309C4C(lbl_8053AD30, 0x200, 1) != 0) {
        *(s16*)(self + 0x9c) = 0;
        self[0xa0] = 3;

        for (s32 i = 0; i < 2; i++) {
            *(u8*)(*(u8**)(*(u8**)(self + 0x34 + i * 4) + 4) + 0xb0) = 1;
            *(u8*)(*(u8**)(*(u8**)(self + 0x44 + i * 4) + 4) + 0xb0) = 1;
            if (i == self[0x9e]) {
                fn_80402E08(*(void**)(self + 0x34 + i * 4), lbl_80543604, lbl_80543620 - *(f32*)(self + 0x6c + i * 4));
                fn_80402E08(*(void**)(self + 0x44 + i * 4), lbl_80543604, lbl_80543620 - *(f32*)(self + 0x6c + i * 4));
            } else {
                fn_80402E08(*(void**)(self + 0x34 + i * 4), lbl_80543614, lbl_80543604);
                fn_80402E08(*(void**)(self + 0x44 + i * 4), lbl_80543614, lbl_80543604);
            }
            *(s16*)(*(u8**)(self + 0x34 + i * 4) + 0x20) = 0;
            *(s16*)(*(u8**)(self + 0x34 + i * 4) + 0x22) = 0;
            *(s16*)(*(u8**)(self + 0x44 + i * 4) + 0x20) = 0;
            *(s16*)(*(u8**)(self + 0x44 + i * 4) + 0x22) = 0;
        }
        *(u8*)(*(u8**)(*(u8**)(self + 0x30) + 4) + 0xb0) = 1;
        fn_80402E08(*(void**)(self + 0x30), lbl_80543604, lbl_8054361C);
        *(s16*)(*(u8**)(self + 0x30) + 0x22) = 0;

        for (s32 i = 0; i < 7; i++) {
            f32 zero = *(volatile f32*)&lbl_80543604;
                fn_80402E08(*(void**)(self + 0x14 + i * 4), zero, zero);
            *(s16*)(*(u8**)(self + 0x14 + i * 4) + 0x20) = 0;
        }

        for (s32 i = 0; i < 2; i++) {
            f32 zero = *(volatile f32*)&lbl_80543604;
                fn_80402E08(*(void**)(self + 0x50 + i * 4), zero, zero);
            *(s16*)(*(u8**)(self + 0x50 + i * 4) + 0x22) = 0;
        }
        *(u8*)(*(u8**)(*(u8**)(self + 0x58) + 4) + 0xb0) = 0;
        *(s32*)(self + 0x84) = 4;
        fn_80458880(lbl_8053AF80, 0xc, -1);
    } else if ((u32)fn_80309A9C(lbl_8053AD30, 2, 1) != 0) {
        if (*(s32*)(self + 0x80) == 0) {
            *(s32*)(self + 0x80) = 1;
            *(s32*)(self + 0x88) = 1;
            *(s32*)(self + 0x8c) = 0x1e;
            fn_80458880(lbl_8053AF80, 0x26, -1);
        }
    } else if ((u32)fn_80309A9C(lbl_8053AD30, 1, 1) != 0) {
        if (*(s32*)(self + 0x80) == 1) {
            *(s32*)(self + 0x80) = 0;
            *(s32*)(self + 0x88) = 1;
            *(s32*)(self + 0x8c) = 0x1e;
            fn_80458880(lbl_8053AF80, 0x26, -1);
        }
    }
    *(s32*)(self + 0x8c) += 1;
    if (*(s32*)(self + 0x8c) >= 0x3c) {
        *(s32*)(self + 0x8c) = 0;
    }
}

extern const float lbl_80543628;
extern const float lbl_805435E0;
static inline void fadeMenuGroup(u8* self, const u64* tags, s32 alphaOffset, s32 count, const f32 factor) {
    for(s32 i=0;i<count;i++){
        (*(J2DScreen**)(self+4))->search(*tags)->setAlpha((u8)(factor*(f32)self[alphaOffset+i]));
        tags++;
    }
}

extern "C" void fn_803DE58C(u8* this_)
{
    u8* self=this_;
    s32 start;
    u8* cur;
    u8* const data=(u8*)lbl_804774C8;
    s32 sel[2];
    s32* q = sel;
    s32 k;
    s32 c;
    s32 e;
    u8 ok1 = 0;
    u8 ok2 = 0;
    f32 f30;
    f32 f1;
    u32* p;
    s32 i;

    *(s16*)(self + 0x9c) = *(s16*)(self + 0x9c) + 1;
    for (s32 n=0;n<2;n++) {
        if(self[0x9e]!=n)*q++=n;
    }
    for (s32 n=0;n<1;n++) if (*(s16*)(self + 0x9c) > n) {
        fn_80402B10(*(void**)(self + 0x34 + sel[0] * 4), 8, lbl_80543604, 0, lbl_80543614);
        fn_80402B10(*(void**)(self + 0x44 + sel[0] * 4), 8, lbl_80543604, 0, lbl_80543614);
        c = *(s16*)(self + 0x9c);
        if (c > 8) {
            c = 8;
        }
        f1 = (f32)(c * c);
        f1 *= lbl_80543628;
        switch (sel[0]) {
        case 0:
            f30 = 1.0f - f1;
            p = (u32*)(data + 0x1c0);
            for (i = 0; i < 0x11; i++) {
                (*(J2DScreen**)(self+4))->search(*(u64*)p)->setAlpha((u8)(f30*(f32)self[0xdb + i]));
                p += 2;
            }
            break;
        case 1:
            f30 = lbl_805435E8 - f1;
            p = (u32*)(data + 0x248);
            for (i = 0; i < 0x14; i++) {
                (*(J2DScreen**)(self+4))->search(*(u64*)p)->setAlpha((u8)(f30*(f32)self[0xec + i]));
                p += 2;
            }
            break;
        }
    }
    if (*(s16*)(self + 0x9c) > 0) {
        fn_80402940(*(void**)(self + 0x34 + self[0x9e] * 4), 0x14, lbl_80543604, 0, lbl_80543620 - *(f32*)(self + 0x6c + self[0x9e] * 4));
        fn_80402940(*(void**)(self + 0x44 + self[0x9e] * 4), 0x14, lbl_80543604, 0, lbl_80543620 - *(f32*)(self + 0x6c + self[0x9e] * 4));
    }
    if (*(s16*)(self + 0x9c) > 0) {
        fn_80402940(*(void**)(self + 0x30), 0xf, lbl_80543604, 0, lbl_8054361C);
    c = *(s16*)(self + 0x9c);
    if (c > 0xf) {
        c = 0xf;
    }
    f1 = (f32)(c * c);
    f32 fade=f1 / lbl_80543624;
    f30 = 1.0f - fade;
    p = (u32*)(data + 0x190);
    for (i = 0; i < 6; i++) {
        (*(J2DScreen**)(self+4))->search(*(u64*)p)->setAlpha((u8)(f30*(f32)self[0xd5 + i]));
        p += 2;
    }
    }
    if (*(s16*)(self + 0x9c) > 0) {
        ok1 = fn_80402B10(*(void**)(self + 0x14), 0x14, lbl_80543614, 0, lbl_80543604);
        u8* cur=self+4;
        for (s32 n = 1; n < 7; n++,cur+=4) {
            fn_80402B10(*(void**)(cur + 0x14), 0x14, lbl_80543614, 0, lbl_80543604);
        }
    c = *(s16*)(self + 0x9c);
    if (c > 0x14) {
        c = 0x14;
    }
    f30 = (f32)(c * c) / lbl_80543618;
    p = (u32*)data;
    for (k = 0; k < 0x32; k++) {
        if(k==0) {
            (*(J2DScreen**)(self+8))->search(*(u64*)p)->setAlpha((u8)(f30*(f32)self[0xa3+k]));
        }else{
            (*(J2DScreen**)(self+4))->search(*(u64*)p)->setAlpha((u8)(f30*(f32)self[0xa3+k]));
        }
        p += 2;
    }
    }
    cur=self;
    start=0;
    for (i = 0; i < 2; i++,cur+=4,start+=5) {
        if (*(s16*)(self + 0x9c) > start) {
            ok2 = fn_80402940(*(void**)(cur + 0x50), 0x14, lbl_8054361C, 0, lbl_80543604);
            c = *(s16*)(self + 0x9c) - start;
            if (c > 0x14) {
                c = 0x14;
            }
            f30 = (f32)(c * c) / lbl_80543618;
            if (i == 0) {
                p = (u32*)(data + 0x368);
                for (s32 idx = 0; idx < 5; idx++) {
                    (*(J2DScreen**)(self+4))->search(*(u64*)p)->setAlpha((u8)(f30*(f32)self[0x110 + idx]));
                    p += 2;
                }
            } else {
                p = (u32*)(data + 0x390);
                for (s32 idx = 0; idx < 5; idx++) {
                    (*(J2DScreen**)(self+4))->search(*(u64*)p)->setAlpha((u8)(f30*(f32)self[0x115 + idx]));
                    p += 2;
                }
            }
        }
    }
    if (ok1 && ok2) {
        *(u8*)(*(u8**)(*(u8**)(self + 0x34 + sel[0] * 4) + 4) + 0xb0) = 0;
        *(u8*)(*(u8**)(*(u8**)(self + 0x44 + sel[0] * 4) + 4) + 0xb0) = 0;
        *(u8*)(*(u8**)(*(u8**)(self + 0x30) + 4) + 0xb0) = 0;
        *(u8*)(*(u8**)(*(u8**)(self + 0x58) + 4) + 0xb0) = 1;
        *(s32*)(self + 0x80) = 0;
        *(s32*)(self + 0x88) = 0;
        *(s32*)(self + 0x8c) = 0;
        self[0xa0] = 1;
        *(s32*)(self + 0x84) = 3;
    }
}

extern "C" void fn_803832BC(char* a, char* b, s32 c, s32 d, s32 e);
extern "C" char* lbl_8047788C[];
extern "C" char* lbl_80477880[];
typedef void* (*FsaFindPaneFn)(void*, u32, u32, u32);
extern "C" void fn_803DEC44(u8* self)
{
    f32 k;
    f32 k2;
    if (*(s32*)(self + 0x88) != 0) {
        *(s32*)(self + 0x88) += 1;
        if (*(s32*)(self + 0x88) > 10) {
            *(s32*)(self + 0x88) = 0;
        }
    }
    if ((u32)fn_80309C4C(lbl_8053AD30, 0x1100, 1) != 0) {
        if (self[0x9e] == 3) {
            self[0x9f] = self[0x9e];
            *(s32*)(self + 0x68) = 5;
        } else {
            *(s16*)(self + 0x9c) = 0;
            for (s32 i = 0; i < 2; i++) {
                k = *(volatile f32*)&lbl_80543604;
                fn_80402E08(*(void**)(self + 0x34 + i * 4), k, k);
                *(s16*)(*(u8**)(self + 0x34 + i * 4) + 0x20) = 0;
                *(s16*)(*(u8**)(self + 0x34 + i * 4) + 0x22) = 0;
                k = *(volatile f32*)&lbl_80543604;
                fn_80402E08(*(void**)(self + 0x44 + i * 4), k, k);
                *(s16*)(*(u8**)(self + 0x44 + i * 4) + 0x20) = 0;
                *(s16*)(*(u8**)(self + 0x44 + i * 4) + 0x22) = 0;
            }
            k = *(volatile f32*)&lbl_80543604;
            fn_80402E08(*(void**)(self + 0x30), k, k);
            *(s16*)(*(u8**)(self + 0x30) + 0x22) = 0;
            *(u8*)(*(u8**)(*(u8**)(self + 0x40) + 4) + 0xb0) = 0;
            for (s32 i = 0; i < 7; i++) {
                k = *(volatile f32*)&lbl_80543614;
                k2 = *(volatile f32*)&lbl_80543604;
                *(u8*)(*(u8**)(*(u8**)(self + 0x14 + i * 4) + 4) + 0xb0) = 1;
                fn_80402E08(*(void**)(self + 0x14 + i * 4), k, k2);
                *(s16*)(*(u8**)(self + 0x14 + i * 4) + 0x20) = 0;
            }
            for (s32 i = 0; i < 2; i++) {
                *(u8*)(*(u8**)(*(u8**)(self + 0x50 + i * 4) + 4) + 0xb0) = 1;
                k = *(volatile f32*)&lbl_80543604;
                fn_80402E08(*(void**)(self + 0x50 + i * 4), k, lbl_8054361C);
                *(s16*)(*(u8**)(self + 0x50 + i * 4) + 0x22) = 0;
            }
            switch (self[0x9e]) {
            case 0:
                (*(J2DScreen**)(self + 4))->search(0x576762636f3031ULL)->hide();
                (*(J2DScreen**)(self + 4))->search(0x576e6f703031ULL)->hide();
                (*(J2DScreen**)(self + 4))->search(0x576e6f703032ULL)->show();
                (*(J2DScreen**)(self + 4))->search(0x576762636f3032ULL)->show();
                break;
            case 1:
                (*(J2DScreen**)(self + 4))->search(0x576762636f3031ULL)->show();
                (*(J2DScreen**)(self + 4))->search(0x576e6f703031ULL)->show();
                (*(J2DScreen**)(self + 4))->search(0x576e6f703032ULL)->hide();
                (*(J2DScreen**)(self + 4))->search(0x576762636f3032ULL)->hide();
                break;
            default:
                (*(J2DScreen**)(self + 4))->search(0x576762636f3031ULL)->show();
                (*(J2DScreen**)(self + 4))->search(0x576e6f703031ULL)->show();
                (*(J2DScreen**)(self + 4))->search(0x576e6f703032ULL)->hide();
                (*(J2DScreen**)(self + 4))->search(0x576762636f3032ULL)->hide();
                break;
            }
            fn_803832BC(((J2DTextBox*)(*(J2DScreen**)(self + 4))->search(0x546e6f703031ULL))->getStringPtr(), lbl_8047788C[self[0x9e]], 0, 0, 0);
            fn_803832BC(((J2DTextBox*)(*(J2DScreen**)(self + 4))->search(0x546e6f703032ULL))->getStringPtr(), lbl_8047788C[self[0x9e]], 0, 0, 0);
            fn_803832BC(((J2DTextBox*)(*(J2DScreen**)(self + 4))->search(0x546578703031ULL))->getStringPtr(), lbl_80477880[self[0x9e]], 0, 0, 0);
            (*(J2DPane**)(*(u8**)((u8*)((u32*)self + self[0x9e]) + 0x44) + 4))->hide();
            *(s32*)(self + 0x84) = 2;
            self[0x9f] = self[0x9e];
            *(s32*)(self + 0x90) = 1;
        }
        fn_80458880(lbl_8053AF80, 0xb, -1);
    } else if ((u32)fn_80309C4C(lbl_8053AD30, 0x200, 1) != 0) {
        *(s32*)(self + 0x68) = 1;
        fn_80458880(lbl_8053AF80, 0xc, -1);
    } else if ((u32)fn_80309A9C(lbl_8053AD30, 4, 1) != 0) {
        self[0x9f] = self[0x9e];
        if (self[0x9e] < 3) {
            self[0x9e] = self[0x9e] + 1;
            if (self[0x9e] == 2) {
                self[0x9e] = 3;
            }
        } else {
            self[0x9e] = 0;
        }
        *(s32*)(self + 0x88) = 1;
        if (self[0x9e] == 3) {
            *(s32*)(self + 0x8c) = 0x1e;
        } else {
            *(s32*)(self + 0x8c) = 0x3c;
        }
        *(s32*)(self + 0x90) = 1;
        fn_80458880(lbl_8053AF80, 0x26, -1);
    } else if ((u32)fn_80309A9C(lbl_8053AD30, 8, 1) != 0) {
        self[0x9f] = self[0x9e];
        if (self[0x9e] != 0) {
            self[0x9e] = self[0x9e] - 1;
            if (self[0x9e] == 2) {
                self[0x9e] = 1;
            }
        } else {
            self[0x9e] = 3;
        }
        *(s32*)(self + 0x88) = 1;
        if (self[0x9e] == 3) {
            *(s32*)(self + 0x8c) = 0x1e;
        } else {
            *(s32*)(self + 0x8c) = 0x3c;
        }
        *(s32*)(self + 0x90) = 1;
        fn_80458880(lbl_8053AF80, 0x26, -1);
    }
    *(s32*)(self + 0x8c) = *(s32*)(self + 0x8c) + 1;
    if (self[0x9e] == 3) {
        if (*(s32*)(self + 0x8c) >= 0x3c) {
            *(s32*)(self + 0x8c) = 0;
        }
    } else if (*(s32*)(self + 0x8c) >= 0x78) {
        *(s32*)(self + 0x8c) = 0;
    }
}

extern "C" void fn_803DF2B4(u8* self) {
    u64* tbl = lbl_804774C8;
    s32 k;
    u8* q = self;
    u8 a = 0;
    u8 b = 0;
    u8 c = 0;
    s32 i;
    s32 n;
    f32 f30;

    *(s16*)(self + 0x9c) += 1;
    for (i = 0, k = 0; i < 2; i++, k += 3, q += 4) {
        if (*(s16*)(self + 0x9c) > k) {
            a = fn_80402B10(*(void**)(q + 0x34), 0x14, lbl_80543614, 0, lbl_80543604);
            fn_80402B10(*(void**)(q + 0x44), 0x14, lbl_80543614, 0, lbl_80543604);
            n = *(s16*)(self + 0x9c) - k;
            if (n > 20) {
                n = 20;
            }
            f30 = (f32)(n * n) / lbl_80543618;
            switch (i) {
            case 0: {
                s32 j0;
                u64* kp0 = tbl + 56;
                for (j0 = 0; j0 < 17; j0++, kp0++) {
                    J2DPane* pane = ((J2DScreen*)*(void**)(self + 0x4))->search(*kp0);
                    pane->setAlpha((u8)(f30 * (f32)self[0xdb + j0]));
                }
                break;
            }
            case 1: {
                u64* kp1 = tbl + 73;
                s32 j1;
                for (j1 = 0; j1 < 20; j1++, kp1++) {
                    J2DPane* pane = ((J2DScreen*)*(void**)(self + 0x4))->search(*kp1);
                    pane->setAlpha((u8)(f30 * (f32)self[0xec + j1]));
                }
                break;
            }
            }
        }
    }
    if (*(s16*)(self + 0x9c) > 15) {
        u64* kp2;
        s32 j2;
        b = fn_80402940(*(void**)(self + 0x30), 0xf, lbl_8054361C, 0, lbl_80543604);
        n = *(s16*)(self + 0x9c) - 15;
        if (n > 15) {
            n = 15;
        }
        f30 = (f32)(n * n) / lbl_80543624;
        kp2 = tbl + 50;
        for (j2 = 0; j2 < 6; j2++, kp2++) {
            J2DPane* pane = ((J2DScreen*)*(void**)(self + 0x4))->search(*kp2);
            pane->setAlpha((u8)(f30 * (f32)self[0xd5 + j2]));
        }
    }
    if (*(s16*)(self + 0x9c) > 20) {
        c = fn_80402940(*(void**)(self + 0x5c), 0x19, lbl_8054362C, 0, lbl_80543604);
        n = *(s16*)(self + 0x9c) - 20;
        if (n > 25) {
            n = 25;
        }
        fn_80440E0C(lbl_8053AED8, (f32)(n * n) / lbl_80543630);
    }
    if (a && b && c) {
        *(s32*)(self + 0x8c) = 0;
        *(s32*)(self + 0x84) = 1;
        *(s32*)(self + 0x90) = 1;
    }
}
extern void* lbl_8053AB10;
extern void* lbl_8053AED8;
extern void (J2DScreen::*lbl_804B0628[])();
void fn_8013B490(void*);
void fn_80427D2C(void*, s32, s32, s32, s32);
void fn_80440EE8(void*);
extern const float lbl_80543634;
extern const float lbl_80543638;

class SeqVoice {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual BOOL isPlaying();
    virtual void fadeOut(f32);
};

extern void (J2DScreen::*lbl_804B0568[])();
void fn_80458FF0(void*, u32, s32, s32);
void fn_80458408(void*, u32, s32);
void fn_803DCCA4(u8*);
int fn_80427DB4(SeqVoice*, u8);
void fn_80427D94(SeqVoice*);
int fn_80427D60(SeqVoice*);
u8 fn_804286A0(void);
u8 fn_802B1DCC(void*);
extern "C" void fn_803DF624(u8* self) {
    (((J2DScreen*)lbl_8053ADD0)->*(lbl_804B0628[*(s32*)(self + 0x84)]))();
    fn_8013B490(lbl_8053AB10);
    ((J2DScreen*)*(void**)(self + 0x8))->draw(lbl_80543604, lbl_80543604, *(J2DGrafContext**)((u8*)lbl_8053AB10 + 0x10));
    if (self[0xa0] == 2) {
        fn_80427D2C(*(void**)(self + 0x64), 0x32, 0x9f, -0x164, -0x11b);
    }
    fn_8013B490(lbl_8053AB10);
    ((J2DScreen*)*(void**)(self + 0x4))->draw(lbl_80543604, lbl_80543604, *(J2DGrafContext**)((u8*)lbl_8053AB10 + 0x10));
    fn_80440EE8(lbl_8053AED8);
    if (*(s32*)(self + 0x84) == 5) {
        FsaVirtObj* obj = *(FsaVirtObj**)(self + 0x10);
        obj->set9((s32)*(f32*)(self + 0x7c));
        obj = *(FsaVirtObj**)(self + 0x10);
        obj->set59(0, 0, 0, lbl_80543604, lbl_80543604, lbl_80543634, lbl_80543638);
    } else if (*(s32*)(self + 0x84) == 6) {
        FsaVirtObj* obj = *(FsaVirtObj**)(self + 0x10);
        obj->set59(0, 0, 0, lbl_80543604, lbl_80543604, lbl_80543634, lbl_80543638);
    } else if (*(s32*)(self + 0x84) == 7) {
        FsaVirtObj* obj = *(FsaVirtObj**)(self + 0x10);
        obj->set9((s32)*(f32*)(self + 0x7c));
        obj = *(FsaVirtObj**)(self + 0x10);
        obj->set59(0, 0, 0, lbl_80543604, lbl_80543604, lbl_80543634, lbl_80543638);
    }
    if (*(s32*)(self + 0x94) != 0) {
        u8* base = lbl_80529DEC;
        if (*(s32*)(base + 0x1a0) > 0) {
            *(s32*)(base + 0x1a0) -= 1;
        } else {
            *(s32*)(base + 0x1a0) = 0;
        }
        *(s32*)(self + 0x94) = *(s32*)(base + 0x1a0);
    }
}

extern "C" void fn_803DF810(u8* self) {
    if (*(s32*)(self + 0x94) == 0 && *(s32*)(self + 0x84) != 7) {
        fn_80458FF0((void*)lbl_8053AF80, 0x100001a, 0, 0);
        fn_80458408((void*)lbl_8053AF80, 0x100001a, 0);
        lbl_80529DEC[0x248] = 0;
    }
    (((J2DScreen*)lbl_8053ADD0)->*(lbl_804B0568[*(s32*)(self + 0x84)]))();
    fn_803DCCA4(self);
    if (self[0xa0] == 1) {
        if (fn_80427DB4(*(SeqVoice**)(self + 0x64), self[0x9e]) != 0) {
            self[0xa1] = 0;
            self[0xa0] = 2;
        } else {
            fn_80427D94(*(SeqVoice**)(self + 0x64));
        }
    } else if (self[0xa0] == 2) {
        int r = fn_80427D60(*(SeqVoice**)(self + 0x64));
        if (fn_804286A0() && self[0xa1] == 0) {
            SeqVoice* v = *(SeqVoice**)(self + 0x64);
            (*(void (**)(SeqVoice*, f32))((u8*)v + 0x14))(v, lbl_80543604);
            self[0xa1] = 1;
        }
        if (*(s32*)(self + 0x68) != 2 || fn_802B1DCC(lbl_8053ACA8)) {
            fn_80427D94(*(SeqVoice**)(self + 0x64));
            self[0xa0] = 0;
        } else {
            SeqVoice* v = *(SeqVoice**)(self + 0x64);
            if ((*(u32 (**)(SeqVoice*))((u8*)v + 0x10))(v) == 0 || r == 0) {
                fn_80427D94(*(SeqVoice**)(self + 0x64));
                if (fn_80427DB4(*(SeqVoice**)(self + 0x64), self[0x9e]) != 0) {
                    self[0xa1] = 0;
                } else {
                    fn_80427D94(*(SeqVoice**)(self + 0x64));
                    self[0xa0] = 1;
                }
            }
        }
    } else if (self[0xa0] == 3) {
        fn_80427D94(*(SeqVoice**)(self + 0x64));
        self[0xa0] = 0;
    }
}

#pragma opt_propagation off
extern "C" void fn_803DF9E8(u8* self) {
    u8* p;
    s32 i;
    *(s32*)(self + 0x88) = 0;
    *(s32*)(self + 0x8c) = 0;
    *(s32*)(self + 0x90) = 0;
    *(s16*)(self + 0x9c) = 0;
    *(f32*)(self + 0x7c) = lbl_80543604;
    *(f32*)(self + 0x78) = lbl_80543604;
    *(s16*)(self + 0x9a) = 0;
    *(s16*)(self + 0x98) = 0x3c;
    self[0xa1] = 0;
    for (i = 0, p = self; i < 2; i++, p += 4) {
        *(u8*)(*(u8**)(*(u8**)(p + 0x34) + 4) + 0xb0) = 1;
        fn_80402E08(*(void**)(p + 0x34), lbl_80543614, lbl_80543604);
        *(s16*)((u8*)*(void**)(p + 0x34) + 0x20) = 0;
        *(u8*)(*(u8**)(*(u8**)(p + 0x44) + 4) + 0xb0) = 1;
        fn_80402E08(*(void**)(p + 0x44), lbl_80543614, lbl_80543604);
        *(s16*)((u8*)*(void**)(p + 0x44) + 0x20) = 0;
    }
    *(u8*)(*(u8**)(*(u8**)(self + 0x30) + 4) + 0xb0) = 1;
    fn_80402E08(*(void**)(self + 0x30), lbl_80543604, lbl_8054361C);
    *(s16*)((u8*)*(void**)(self + 0x30) + 0x22) = 0;
    fn_80402E08(*(void**)(self + 0x5c), lbl_80543604, lbl_8054362C);
    *(s16*)((u8*)*(void**)(self + 0x5c) + 0x22) = 0;
    *(u8*)(*(u8**)(*(u8**)(self + 0x40) + 4) + 0xb0) = 0;
    *(u8*)(*(u8**)(*(u8**)(self + 0x14) + 4) + 0xb0) = 0;
    *(u8*)(*(u8**)(*(u8**)(self + 0x18) + 4) + 0xb0) = 0;
    *(u8*)(*(u8**)(*(u8**)(self + 0x1c) + 4) + 0xb0) = 0;
    *(u8*)(*(u8**)(*(u8**)(self + 0x20) + 4) + 0xb0) = 0;
    *(u8*)(*(u8**)(*(u8**)(self + 0x24) + 4) + 0xb0) = 0;
    *(u8*)(*(u8**)(*(u8**)(self + 0x28) + 4) + 0xb0) = 0;
    *(u8*)(*(u8**)(*(u8**)(self + 0x2c) + 4) + 0xb0) = 0;
    *(u8*)(*(u8**)(*(u8**)(self + 0x50) + 4) + 0xb0) = 0;
    *(u8*)(*(u8**)(*(u8**)(self + 0x54) + 4) + 0xb0) = 0;
    *(u8*)(*(u8**)(*(u8**)(self + 0x58) + 4) + 0xb0) = 0;
    (*(J2DScreen**)(self + 0x8))->search(0x50696d3031ULL)->setAlpha(0);
    (*(J2DScreen**)(self + 0x8))->search(0x50696d3032ULL)->setAlpha(0);
    (*(J2DScreen**)(self + 0x8))->search(0x50696d3131ULL)->setAlpha(0);
    (*(J2DScreen**)(self + 0x8))->search(0x50696d3132ULL)->setAlpha(0);
    *(s32*)(self + 0x84) = 0;
    *(s32*)(self + 0x68) = 2;
}
#pragma opt_propagation reset
extern "C" u8 lbl_804B0688[];
extern "C" void getTotalFreeSize__7JKRHeapFv(void*);
extern "C" char lbl_804AF86C[];
extern "C" void fn_80402F04(void*, void*);
struct FsaPaneKeys {
    u64 keys[50];
};
static inline void fn_803DFF40_child(u8* self, s32 off, s32 scrOff, u64 key) {
    void* obj = operator new(0x2c);
    if (obj != 0) {
        *(void**)obj = lbl_804AF86C;
    }
    *(void**)(self + off) = obj;
    fn_80402F04(*(void**)(self + off), (*(J2DScreen**)(self + scrOff))->search(key));
}
void __dl__FPv(void*);
extern "C" void* fn_803DFC6C(u8* self, s16 param_2) {
    void* obj;
    s32 i;

    if (self != 0) {
        *(void**)self = lbl_804B0688;
        getTotalFreeSize__7JKRHeapFv(*(void**)(lbl_80529DEC + 8));
        if (self[0xa0] == 2) {
            fn_80427D94(*(SeqVoice**)(self + 0x64));
            self[0xa0] = 0;
        }
        obj = *(void**)(self + 0x60);
        if (obj != 0) {
            ((FsaDisposable*)obj)->del(1);
        }
        *(void**)(self + 0x60) = 0;
        obj = *(void**)(self + 0x64);
        if (obj != 0) {
            ((FsaDisposable*)obj)->del(1);
        }
        *(void**)(self + 0x64) = 0;
        obj = *(void**)(self + 0x4);
        if (obj != 0) {
            ((FsaDisposable*)obj)->del(1);
        }
        *(void**)(self + 0x4) = 0;
        obj = *(void**)(self + 0x8);
        if (obj != 0) {
            ((FsaDisposable*)obj)->del(1);
        }
        *(void**)(self + 0x8) = 0;
        for (int i = 0; i < 7; i++) {
            obj = *(void**)(self + 0x14 + i * 4);
            if (obj != 0) {
                ((FsaDisposable*)obj)->del(1);
            }
            *(void**)(self + 0x14 + i * 4) = 0;
        }
        obj = *(void**)(self + 0x30);
        if (obj != 0) {
            ((FsaDisposable*)obj)->del(1);
        }
        *(void**)(self + 0x30) = 0;
        for (int i = 0; i < 2; i++) {
            obj = *(void**)(self + 0x34 + i * 4);
            if (obj != 0) {
                ((FsaDisposable*)obj)->del(1);
            }
            *(void**)(self + 0x34 + i * 4) = 0;
        }
        obj = *(void**)(self + 0x40);
        if (obj != 0) {
            ((FsaDisposable*)obj)->del(1);
        }
        *(void**)(self + 0x40) = 0;
        for (int i = 0; i < 2; i++) {
            obj = *(void**)(self + 0x44 + i * 4);
            if (obj != 0) {
                ((FsaDisposable*)obj)->del(1);
            }
            *(void**)(self + 0x44 + i * 4) = 0;
        }
        for (int i = 0; i < 2; i++) {
            obj = *(void**)(self + 0x50 + i * 4);
            if (obj != 0) {
                ((FsaDisposable*)obj)->del(1);
            }
            *(void**)(self + 0x50 + i * 4) = 0;
        }
        obj = *(void**)(self + 0x58);
        if (obj != 0) {
            ((FsaDisposable*)obj)->del(1);
        }
        *(void**)(self + 0x58) = 0;
        obj = *(void**)(self + 0x10);
        if (obj != 0) {
            ((FsaDisposable*)obj)->del(1);
        }
        *(void**)(self + 0x10) = 0;
        obj = *(void**)(lbl_80529DEC + 0x2c);
        ((FsaDisposable*)obj)->v3();
        lbl_8053ADD0 = 0;
        if (param_2 > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}

extern "C" void fn_80158B3C(void*);
extern "C" void fn_802FF798(void*);
extern "C" void fn_802F9714(void*, void*, s32, s32, s32, s32);
extern "C" void fn_802F93F4(void*, void*, s32, s32, s32, s32, s32);
extern "C" void fn_803A7898(void*);
extern "C" void* fn_80428030(void*);
extern "C" void* fn_804030C4(u32, const char*);
extern "C" void fn_80440D78(void*, void*);
extern "C" void fn_80440CE4(void*, void*);
extern "C" char* strcpy(char*, const char*);
extern "C" u8* lbl_8053AD78;
extern "C" const char lbl_8054363C[4];
extern "C" void* fn_803DFF40(u8* self) {
    void* tmp;
    f32 a;
    f32 b;
    s32 i;
    u64* p;
    char* names = (char*)&lbl_804774C8[0];
    *(void**)self = lbl_804B0688;
    getTotalFreeSize__7JKRHeapFv(*(void**)(lbl_80529DEC + 8));
    fn_80158B3C(*(void**)((u8*)lbl_8053AB10 + 0x2c));
    if (lbl_80529DEC[0x242] == 0) {
        lbl_80529DEC[0x242] = 1;
        fn_802FF798(*(void**)((u8*)lbl_8053AB10 + 0x20));
        void* res = (*(JKRArchive**)((u8*)lbl_8053AAF8 + 0xa4))->getResource(0x53434820, names + 0x3e4);
        fn_802F9714(*(void**)((u8*)lbl_8053AB10 + 0x20), res, 0, 0, 0, 0);
        res = (*(JKRArchive**)((u8*)lbl_8053AAF8 + 0xa4))->getResource(0x53434820, names + 0x3fc);
        fn_802F9714(*(void**)((u8*)lbl_8053AB10 + 0x20), res, 0, 0, 0x7000, 0);
        res = (*(JKRArchive**)((u8*)lbl_8053AAF8 + 0xa4))->getResource(0x53434c20, names + 0x414);
        fn_802F93F4(*(void**)((u8*)lbl_8053AB10 + 0x20), res, 0, 0, 0, 0, 0);
        res = (*(JKRArchive**)((u8*)lbl_8053AAF8 + 0xa4))->getResource(0x53434820, names + 0x42c);
        fn_802F9714(*(void**)((u8*)lbl_8053AB10 + 0x20), res, 0, 2, 0x4000, 0);
        res = (*(JKRArchive**)((u8*)lbl_8053AAF8 + 0xa4))->getResource(0x53434c20, names + 0x414);
        fn_802F93F4(*(void**)((u8*)lbl_8053AB10 + 0x20), res, 0, 2, 0, 0, 0);
        res = (*(JKRArchive**)((u8*)lbl_8053AAF8 + 0xa4))->getResource(0x53434820, names + 0x43c);
        fn_802F9714(*(void**)((u8*)lbl_8053AB10 + 0x20), res, 0, 3, 0, 0);
        res = (*(JKRArchive**)((u8*)lbl_8053AAF8 + 0xa4))->getResource(0x53434c20, names + 0x414);
        fn_802F93F4(*(void**)((u8*)lbl_8053AB10 + 0x20), res, 0, 3, 0, 0, 0);
        *(u8*)(*(u8**)((u8*)lbl_8053AB10 + 0x20) + 0x2364) = 1;
    }
    {
        void* q = operator new(0x84);
        if (q != 0) {
            fn_803A7898(q);
        }
        *(void**)(self + 0x60) = q;
    }
    {
        void* q = operator new(0x1c);
        if (q != 0) {
            fn_80428030(q);
        }
        *(void**)(self + 0x64) = q;
    }
    *(J2DScreen**)(self + 0x4) = new J2DScreen();
    u8* tbl = lbl_80529DEC;
    (*(J2DScreen**)(self + 0x4))->setPriority(names + 0x44c, 0x1100000, *(JKRArchive**)(tbl + 0x2c));
    *(J2DScreen**)(self + 0x8) = new J2DScreen();
    (*(J2DScreen**)(self + 0x8))->setPriority(names + 0x45c, 0x1100000, *(JKRArchive**)(tbl + 0x2c));
    fn_803DFF40_child(self, 0x14, 0x8, 0x506d6f763031ULL);
    fn_803DFF40_child(self, 0x18, 0x4, 0x4e646174613038ULL);
    fn_803DFF40_child(self, 0x1c, 0x4, 0x576762636f3031ULL);
    fn_803DFF40_child(self, 0x20, 0x4, 0x576e6f703031ULL);
    fn_803DFF40_child(self, 0x24, 0x4, 0x50657870623039ULL);
    fn_803DFF40_child(self, 0x28, 0x4, 0x576e6f703032ULL);
    fn_803DFF40_child(self, 0x2c, 0x4, 0x576762636f3032ULL);
    fn_803DFF40_child(self, 0x30, 0x4, 0x4e646174613035ULL);
    fn_803DFF40_child(self, 0x34, 0x4, 0x4e646174613032ULL);
    fn_803DFF40_child(self, 0x38, 0x4, 0x4e646174613033ULL);
    fn_803DFF40_child(self, 0x40, 0x4, 0x50736375726f3032ULL);
    fn_803DFF40_child(self, 0x44, 0x4, 0x5073637572683035ULL);
    b = lbl_805435E8 + (*(J2DScreen**)(self + 0x4))->search(0x5073637572733035ULL)->getBounds()->i.y;
    a = (*(J2DScreen**)(self + 0x4))->search(0x5073637572733035ULL)->getBounds()->i.x;
    (*(J2DScreen**)(self + 0x4))->search(0x5073637572733035ULL)->move(a, b);
    fn_803DFF40_child(self, 0x48, 0x4, 0x5073637572733035ULL);
    fn_803DFF40_child(self, 0x50, 0x4, 0x50737472623034ULL);
    fn_803DFF40_child(self, 0x54, 0x4, 0x50626163623034ULL);
    fn_803DFF40_child(self, 0x58, 0x4, 0x5061636375723032ULL);
    *(void**)(self + 0x5c) = *(void**)((u8*)lbl_8053AED8 + 0x8);
    tmp = fn_804030C4(0x54494d47, names + 0x470);
    fn_80440D78(lbl_8053AED8, tmp);
    fn_80440CE4(lbl_8053AED8, fn_804030C4(0x54494d47, names + 0x484));
    tmp = fn_804030C4(0x54494d47, names + 0x498);
    *(J2DPicture**)(self + 0x10) = new J2DPicture((const ResTIMG*)tmp);
    (*(J2DPicture**)(self + 0x10))->setBlackWhite(JUtility::TColor((u32)0xff), JUtility::TColor((u32)0));
    self[0xa2] = 0x9c;
    { JUTFont* f = *(JUTFont**)(lbl_8053AD78 + 0x154); ((J2DTextBox*)(*(J2DScreen**)(self + 0x4))->search(0x546167623031ULL))->setFont(f); }
    { JUTFont* f = *(JUTFont**)(lbl_8053AD78 + 0x154); ((J2DTextBox*)(*(J2DScreen**)(self + 0x4))->search(0x546167623032ULL))->setFont(f); }
    { JUTFont* f = *(JUTFont**)(lbl_8053AD78 + 0x154); ((J2DTextBox*)(*(J2DScreen**)(self + 0x4))->search(0x546167623033ULL))->setFont(f); }
    { JUTFont* f = *(JUTFont**)(lbl_8053AD78 + 0x154); ((J2DTextBox*)(*(J2DScreen**)(self + 0x4))->search(0x546167623034ULL))->setFont(f); }
    { JUTFont* f = *(JUTFont**)(lbl_8053AD78 + 0x154); ((J2DTextBox*)(*(J2DScreen**)(self + 0x4))->search(0x546e6f703031ULL))->setFont(f); }
    { JUTFont* f = *(JUTFont**)(lbl_8053AD78 + 0x154); ((J2DTextBox*)(*(J2DScreen**)(self + 0x4))->search(0x546e6f703032ULL))->setFont(f); }
    { JUTFont* f = *(JUTFont**)(lbl_8053AD78 + 0x154); ((J2DTextBox*)(*(J2DScreen**)(self + 0x4))->search(0x546e6f703033ULL))->setFont(f); }
    { JUTFont* f = *(JUTFont**)(lbl_8053AD78 + 0x154); ((J2DTextBox*)(*(J2DScreen**)(self + 0x4))->search(0x546e6f703034ULL))->setFont(f); }
    { JUTFont* f = *(JUTFont**)(lbl_8053AD78 + 0x154); ((J2DTextBox*)(*(J2DScreen**)(self + 0x4))->search(0x546e6f703035ULL))->setFont(f); }
    { JUTFont* f = *(JUTFont**)(lbl_8053AD78 + 0x154); ((J2DTextBox*)(*(J2DScreen**)(self + 0x4))->search(0x546e6f703036ULL))->setFont(f); }
    { JUTFont* f = *(JUTFont**)(lbl_8053AD78 + 0x154); ((J2DTextBox*)(*(J2DScreen**)(self + 0x4))->search(0x546578703031ULL))->setFont(f); }
    { JUTFont* f = *(JUTFont**)(lbl_8053AD78 + 0x154); ((J2DTextBox*)(*(J2DScreen**)(self + 0x4))->search(0x546261633031ULL))->setFont(f); }
    { JUTFont* f = *(JUTFont**)(lbl_8053AD78 + 0x154); ((J2DTextBox*)(*(J2DScreen**)(self + 0x4))->search(0x547374723031ULL))->setFont(f); }
    fn_803832BC(((J2DTextBox*)(*(J2DScreen**)(self + 0x4))->search(0x547374723031ULL))->getStringPtr(), (char*)0x118, 0, 0, 0);
    fn_803832BC(((J2DTextBox*)(*(J2DScreen**)(self + 0x4))->search(0x546261633031ULL))->getStringPtr(), (char*)0x11b, 0, 0, 0);
    fn_803832BC(((J2DTextBox*)(*(J2DScreen**)(self + 0x4))->search(0x546e6f703033ULL))->getStringPtr(), (char*)0x93, 0, 0, 0);
    fn_803832BC(((J2DTextBox*)(*(J2DScreen**)(self + 0x4))->search(0x546e6f703034ULL))->getStringPtr(), (char*)0x93, 0, 0, 0);
    fn_803832BC(((J2DTextBox*)(*(J2DScreen**)(self + 0x4))->search(0x546e6f703035ULL))->getStringPtr(), (char*)0xf4, 0, 0, 0);
    fn_803832BC(((J2DTextBox*)(*(J2DScreen**)(self + 0x4))->search(0x546e6f703036ULL))->getStringPtr(), (char*)0xf4, 0, 0, 0);
    strcpy(((J2DTextBox*)(*(J2DScreen**)(self + 0x4))->search(0x546167623031ULL))->getStringPtr(), lbl_8054363C);
    strcpy(((J2DTextBox*)(*(J2DScreen**)(self + 0x4))->search(0x546167623032ULL))->getStringPtr(), lbl_8054363C);
    strcpy(((J2DTextBox*)(*(J2DScreen**)(self + 0x4))->search(0x546167623033ULL))->getStringPtr(), lbl_8054363C);
    strcpy(((J2DTextBox*)(*(J2DScreen**)(self + 0x4))->search(0x546167623034ULL))->getStringPtr(), lbl_8054363C);
    *(f32*)(self + 0x6c) = (*(J2DScreen**)(self + 0x4))->search(0x506d616462623031ULL)->getBounds()->i.y +
                           ((*(J2DScreen**)(self + 0x4))->search(0x4e646174613032ULL)->getBounds()->i.y +
                            (*(J2DScreen**)(self + 0x4))->search(0x506d616462623037ULL)->getBounds()->i.y);
    *(f32*)(self + 0x70) = (*(J2DScreen**)(self + 0x4))->search(0x506d626162623031ULL)->getBounds()->i.y +
                           ((*(J2DScreen**)(self + 0x4))->search(0x4e646174613033ULL)->getBounds()->i.y +
                            (*(J2DScreen**)(self + 0x4))->search(0x506d626162623037ULL)->getBounds()->i.y);
    self[0x11a] = (*(J2DScreen**)(self + 0x8))->search(0x50696d3031ULL)->getAlpha();
    self[0x11b] = (*(J2DScreen**)(self + 0x8))->search(0x50696d3032ULL)->getAlpha();
    self[0x11c] = (*(J2DScreen**)(self + 0x8))->search(0x50696d3131ULL)->getAlpha();
    self[0x11d] = (*(J2DScreen**)(self + 0x8))->search(0x50696d3132ULL)->getAlpha();
    *(u8*)(*(u8**)(*(u8**)(self + 0x14) + 4) + 0xb0) = 0;
    *(u8*)(*(u8**)(*(u8**)(self + 0x18) + 4) + 0xb0) = 0;
    *(u8*)(*(u8**)(*(u8**)(self + 0x1c) + 4) + 0xb0) = 0;
    *(u8*)(*(u8**)(*(u8**)(self + 0x20) + 4) + 0xb0) = 0;
    *(u8*)(*(u8**)(*(u8**)(self + 0x24) + 4) + 0xb0) = 0;
    *(u8*)(*(u8**)(*(u8**)(self + 0x28) + 4) + 0xb0) = 0;
    *(u8*)(*(u8**)(*(u8**)(self + 0x2c) + 4) + 0xb0) = 0;
    *(u8*)(*(u8**)(*(u8**)(self + 0x50) + 4) + 0xb0) = 0;
    *(u8*)(*(u8**)(*(u8**)(self + 0x54) + 4) + 0xb0) = 0;
    *(u8*)(*(u8**)(*(u8**)(self + 0x58) + 4) + 0xb0) = 0;
    *(s32*)(self + 0x84) = 0;
    self[0x9e] = lbl_80529DEC[0x23a];
    self[0x9f] = self[0x9e];
    *(s32*)(self + 0x80) = 0;
    *(s32*)(self + 0x88) = 0;
    *(f32*)(self + 0x7c) = lbl_80543604;
    *(f32*)(self + 0x78) = lbl_80543604;
    *(s16*)(self + 0x9a) = 0;
    *(s16*)(self + 0x98) = 0x3c;
    self[0xa0] = 0;
    self[0xa1] = 0;
    p = (u64*)(names + 0x0);
    for (i = 0; i < 50; i++) {
        if (i == 0) {
            self[0xa3 + i] = (*(J2DScreen**)(self + 0x8))->search(p[i])->getAlpha();
        } else {
            self[0xa3 + i] = (*(J2DScreen**)(self + 0x4))->search(p[i])->getAlpha();
        }
    }
    p = (u64*)(names + 0x190);
    for (i = 0; i < 6; i++) {
        self[0xd5 + i] = (*(J2DScreen**)(self + 0x4))->search(p[i])->getAlpha();
    }
    p = (u64*)(names + 0x1c0);
    for (i = 0; i < 17; i++) {
        self[0xdb + i] = (*(J2DScreen**)(self + 0x4))->search(p[i])->getAlpha();
    }
    p = (u64*)(names + 0x248);
    for (i = 0; i < 20; i++) {
        self[0xec + i] = (*(J2DScreen**)(self + 0x4))->search(p[i])->getAlpha();
    }
    p = (u64*)(names + 0x368);
    for (i = 0; i < 5; i++) {
        self[0x110 + i] = (*(J2DScreen**)(self + 0x4))->search(p[i])->getAlpha();
    }
    p = (u64*)(names + 0x390);
    for (i = 0; i < 5; i++) {
        self[0x115 + i] = (*(J2DScreen**)(self + 0x4))->search(p[i])->getAlpha();
    }
    *(s32*)(self + 0x94) = 1;
    fn_803DAC58(self, self[0x9e], lbl_80543604);
    lbl_8053ADD0 = self;
    return self;
}

#pragma optimization_level 3
extern "C" void fn_803E1224(void)
{
    char* base = lbl_80528468 - 12;
    *(FsaInitFns*)((u8*)lbl_804B0508 + 0x120) = *(FsaInitFns*)((u8*)lbl_804B0508 + 0xc0);
    *(FsaInitFns*)((u8*)lbl_804B0508 + 0x60) = *(FsaInitFns*)((u8*)lbl_804B0508);
    if (!__init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr) {
        __ct__17JASGenericMemPoolFv(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr);
        __register_global_object(memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr, __dt__50JASMemPool_MultiThreaded_Q28JASTrack11TChannelMgrFv, base + 0xc);
        __init__memPool___58JASPoolAllocObject_MultiThreaded_Q28JASTrack11TChannelMgr = 1;
    }
    if (!__init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack) {
        __ct__17JASGenericMemPoolFv(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack);
        __register_global_object(memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack, __dt__35JASMemPool_MultiThreaded_8JASTrackFv, base + 0x18);
        __init__memPool___43JASPoolAllocObject_MultiThreaded_8JASTrack = 1;
    }
    if (!__init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel) {
        __ct__17JASGenericMemPoolFv(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel);
        __register_global_object(memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel, __dt__38JASMemPool_MultiThreaded_10JASChannelFv, base + 0x24);
        __init__memPool___46JASPoolAllocObject_MultiThreaded_10JASChannel = 1;
    }
    if (!__init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj3_FSA, __dt__29JASMemPool_15JASPoolObj3_FSAFv, base + 0x30);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj3_FSA = 1;
    }
    if (!__init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA) {
        __ct__17JASGenericMemPoolFv(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA);
        __register_global_object(memPool___37JASPoolAllocObject_15JASPoolObj4_FSA, __dt__29JASMemPool_15JASPoolObj4_FSAFv, base + 0x3c);
        __init__memPool___37JASPoolAllocObject_15JASPoolObj4_FSA = 1;
    }
    if (!__init__memPool___30JASPoolAllocObject_9JAIStream) {
        __ct__17JASGenericMemPoolFv(memPool___30JASPoolAllocObject_9JAIStream);
        __register_global_object(memPool___30JASPoolAllocObject_9JAIStream, __dt__22JASMemPool_9JAIStreamFv, base + 0x48);
        __init__memPool___30JASPoolAllocObject_9JAIStream = 1;
    }
    if (!__init__memPool___35JASPoolAllocObject_13JAISoundChild) {
        __ct__17JASGenericMemPoolFv(memPool___35JASPoolAllocObject_13JAISoundChild);
        __register_global_object(memPool___35JASPoolAllocObject_13JAISoundChild, __dt__27JASMemPool_13JAISoundChildFv, base + 0x54);
        __init__memPool___35JASPoolAllocObject_13JAISoundChild = 1;
    }
    if (!__init__memPool___27JASPoolAllocObject_6JAISeq) {
        __ct__17JASGenericMemPoolFv(memPool___27JASPoolAllocObject_6JAISeq);
        __register_global_object(memPool___27JASPoolAllocObject_6JAISeq, __dt__19JASMemPool_6JAISeqFv, base + 0x60);
        __init__memPool___27JASPoolAllocObject_6JAISeq = 1;
    }
    if (!__init__memPool___26JASPoolAllocObject_5JAISe) {
        __ct__17JASGenericMemPoolFv(memPool___26JASPoolAllocObject_5JAISe);
        __register_global_object(memPool___26JASPoolAllocObject_5JAISe, __dt__18JASMemPool_5JAISeFv, base + 0x6c);
        __init__memPool___26JASPoolAllocObject_5JAISe = 1;
    }
}
#pragma optimization_level reset
