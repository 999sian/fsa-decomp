

#include "types.h"
#include "dolphin/dvd/dvd.h"
#include "dolphin/dvd/dvdfs.h"

extern "C" {
extern void* lbl_8053ADD0;
extern const float lbl_8054360C;
extern const float lbl_80543610;
extern const float lbl_80543604;
extern s32 lbl_8053AF80;
extern char lbl_80477898[];
extern void* lbl_8053ACA8;
extern u8 lbl_80529DEC[];
u8 fn_80457F80(s32, u32*, s32);
void OSSetSaveRegion(void*, void*);
void OSSetBootDol(u32);
BOOL __PADDisableRecalibration(BOOL);
void fn_802B1558(void*);
}

extern "C" int fn_803DAC3C(void)
{
    if (lbl_8053ADD0 != 0) {
        return *(int*)((u8*)lbl_8053ADD0 + 0x68);
    }
    return 2;
}

extern "C" void fn_803DD19C(void)
{
}

extern "C" void fn_803DD1A0(void)
{
}

extern "C" void fn_803DD3DC(void)
{
}

extern "C" void fn_803DD760(void)
{
}

extern "C" void fn_803DD764(void* self_) {
    u8* self = (u8*)self_;
    f32 inc = lbl_8054360C;
    f32 threshold = lbl_80543610;
    *(f32*)(self + 0x7c) += inc;
    if (*(f32*)(self + 0x7c) >= threshold) {
        *(f32*)(self + 0x7c) = threshold;
        u32 arg = 0xb;
        DVDFileInfo fileInfo;
        if (fn_80457F80(lbl_8053AF80, &arg, -2) != 0) {
            s16 v = *(s16*)(self + 0x98) - 1;
            *(s16*)(self + 0x98) = v;
            if (v <= 0 && DVDOpen(lbl_80477898, &fileInfo) == 1) {
                u8* base = lbl_80529DEC;
                u32 off;
                for (off = 0; off < 16; off += 8) {
                    u8* src = base + off;
                    u8* dst = (u8*)(off - 0x7f900000);
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
    f32 threshold = lbl_80543610;
    f32 inc = lbl_8054360C;
    f32 field = *(f32*)(self + 0x78);
    f32 t = field + inc;
    *(f32*)(self + 0x78) = t;
    if (!(*(f32*)(self + 0x78) >= threshold)) {
        return;
    }
    *(f32*)(self + 0x78) = threshold;
    *(f32*)(self + 0x7c) = lbl_80543604;
    s32 v = *(s16*)(self + 0x9a) + 1;
    *(s16*)(self + 0x9a) = v;
    if ((s16)v > 100) {
        *(int*)(self + 0x84) = 7;
    }
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
class SeqMgr;
typedef void (SeqMgr::*SeqFunc)(void);

class SeqVoice {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual BOOL isPlaying();
    virtual void fadeOut(f32);
};

extern SeqFunc lbl_804B0568[];
extern "C" {
void fn_80458FF0(s32, u32, s32, s32);
void fn_80458408(s32, u32, s32);
void fn_803DCCA4(u8*);
int fn_80427DB4(SeqVoice*, u8);
void fn_80427D94(SeqVoice*);
int fn_80427D60(SeqVoice*);
u8 fn_804286A0(void);
u8 fn_802B1DCC(void*);
}
