// TU 0x80427d2c-0x8042e964.
// Function bodies adapted from EverydaySimpleDev/FSA-Decomp (CC0), commit 09725c3.
// Remaining functions of this TU are not yet decompiled.
#include "types.h"
extern u32 lbl_8053AE70;
extern u8 lbl_8053AE78;
#include <dolphin/os.h>
#include <dolphin/vi.h>
#include <string.h>
#include <dolphin/dvd.h>
#include <dolphin/gx.h>
#include <dolphin/mtx.h>
#include "JSystem/JAudio/System/JASDriver.h"

extern u8* lbl_8053AE74;
extern "C" void fn_8042CD38();
extern "C" void fn_8042CD64();
extern "C" void fn_8042C9F8();
extern "C" void fn_8042C79C();
extern "C" void fn_8042B1DC();
extern "C" void fn_8042CD24();
extern "C" s32 fn_8042BF54(u8* info, void* h);
extern void* lbl_8053AE28;
extern void* lbl_8053AE34;
extern u8 lbl_8048F270[64];

struct Obj8042E1E4 { u8 pad[0x1c]; u16 m1C; u8 pad2[2]; u32 m20; };

// ---- from src/Game/Dtor_lbl804B15D0_80427F60.cpp ----
// fn_80427F60 - lbl_804B15D0: destructor. Reinstalls the base vtable,
// calls own virtual slot 0 (byte offset 0x8) on this->0x4/0x8/0xc if
// set, clearing each afterward, then conditionally forwards to
// __dl__FPv. See [[reference_fsa_virtual_dispatch_codegen_trick]]
// for why this calls through a real `virtual` member rather than a
// manual cast.
extern "C" void __dl__FPv(void* this_);
extern void* lbl_804B15D0[];

struct Slot0 {
    virtual void slot0(s32 arg);
};

// ---- from src/Game/fn_80428030_ctor.cpp ----
class SubObj_8042B12C {
public:
    SubObj_8042B12C();
private:
    unsigned char pad[0x13f8];
};

class SubObj_8042ADC0 {
public:
    SubObj_8042ADC0();
private:
    unsigned char pad[0x64380];
};

class SubObj_8042A7FC {
public:
    SubObj_8042A7FC();
private:
    unsigned char pad[0x64378];
};

extern void* lbl_804B15D0[];

// ---- from src/Game/fn_804281FC.cpp ----
// fn_804281FC + fn_8042828C + fn_80428294 - 3 helpers bundled.
// fn_804281FC(a,b,c,d): if fn_804286A0(a,b,c,d) succeeds, forwards a
// chained lookup (fn_8042828C(fn_80428294())) plus 4 offset-adjusted
// args to fn_804288A0, then calls fn_80428A88().

extern void* sManager__8JUTVideo;
extern s32 lbl_8053AEA4;
extern s32 lbl_8053AEA8;

// ---- from src/Game/fn_804283B0.cpp ----
extern "C" void free__7JKRHeapFPvP7JKRHeap(void* this_, int flag);

// ---- small leaf accessors and manager forwarders (0x8042E1E4-) ----
extern void* lbl_8053AE7C;
extern void* lbl_8053AE80;
extern void* lbl_8053AE84;

extern void* sManager__10JFWDisplay;

// ---- THP movie player core (0x80427D2C-) ----
struct THPTextureSet { u8* ytexture; u8* utexture; u8* vtexture; u32 frameNumber; };
struct THPReadBuffer { u8* ptr; s32 frameNumber; s32 isValid; };
struct THPAudioBuffer { s16* buffer; s16* curPtr; u32 validSample; };
struct THPHeader {
    char magic[4];
    u32 version;
    u32 bufSize;
    u32 audioMaxSamples;
    f32 frameRate;
    u32 numFrames;
    u32 firstFrameSize;
    u32 movieDataSize;
    u32 compInfoDataOffsets;
    u32 offsetDataOffsets;
    u32 movieDataOffsets;
    u32 finalFrameDataOffsets;
};
struct THPFrameCompInfo { u32 numComponents; u8 frameComp[16]; };
struct THPPlayerState {
    DVDFileInfo fileInfo;
    THPHeader header;
    THPFrameCompInfo compInfo;
    u32 videoInfo[3];
    u8 audioInfo[0x10];
    u8* mBufEnd;
    u8 open;
    u8 state;
    u8 internalState;
    u8 playFlag;
    u8 audioExist;
    u8 padA5[3];
    s32 dvdError;
    s32 videoError;
    u8 onMemory;
    u8 padB1[3];
    u8* movieData;
    u32 initOffset;
    s32 initReadSize;
    u32 initReadFrame;
    u8 padC4[0xc8 - 0xc4];
    s64 retraceCount;
    s32 prevCount;
    s32 curCount;
    s32 mD8;
    f32 curVolume;
    f32 targetVolume;
    f32 deltaVolume;
    s32 rampCount;
    u32 curAudioTrack;
    s32 mF0;
    s32 mF4;
    THPTextureSet* dispTextureSet;
    struct THPAudioBuffer* playAudioBuffer;
    THPReadBuffer readBuffer[10];
    THPTextureSet textureSet[3];
    THPAudioBuffer audioBuffer[3];
};
// .bss of this TU (0x8052A540-0x8052BFD8)
static u8 lbl_8052A540[0x460];
static u8 lbl_8052A9A0[0x100];
static u32 lbl_8052AAA0[3];
static u32 lbl_8052AAAC[3];
static u32 lbl_8052AAB8[6];
static THPPlayerState lbl_8052AAD0;
static u8 lbl_8052ACA0[0x40] __attribute__((aligned(32)));
static OSMessageQueue lbl_8052ACE0;
static OSMessageQueue lbl_8052AD00;
static OSMessage lbl_8052AD20[8];
static s16 lbl_8052AD40[2][0x460] __attribute__((aligned(32)));
static u32 lbl_8052BEC0[3];
static u32 lbl_8052BECC[4];
#include "JSystem/JAudio/JASFakeMatchFSA.h"
static u8 lbl_8052BF48[0x90];

extern u8 lbl_8053AEBD;
extern u8 lbl_8053AEBC;
extern u16 lbl_8053AEBE;
extern s32 lbl_8053AEB8;
extern void* lbl_8053AEB4;
extern void* lbl_8053AEAC;
extern void* lbl_8053AE90;
extern void* lbl_804B15C0[];

struct RenderModeHolder { u8 pad[4]; u16 fbWidth; u16 efbHeight; };

extern u32 lbl_8053AEB0;
extern "C" u8 fn_80428AC8(s32, s32, s32);
extern "C" u8 fn_8042E464(s32 prio, void* param);
extern "C" u8 fn_8042E494(s32 prio, void* param);
extern "C" void* fn_8042E758();
extern "C" void* alloc__7JKRHeapFUli(void*, u32, int);

extern "C" u32 AIGetDSPSampleRate(void);
extern u8 lbl_8053AE88;

extern "C" u32 VIGetNextField(void);
extern "C" u32 VIGetTvFormat(void);
extern OSMessage lbl_8053AE8C;

extern "C" void DCInvalidateRange(void*, u32);
extern "C" void DCStoreRange(void*, u32);
extern "C" void LCEnable(void);
extern "C" void LCDisable(void);
extern s32 lbl_8053AEA0;
extern u32 lbl_8053AE94;
extern u32 lbl_8053AE98;
extern u32 lbl_8053AE9C;
extern char lbl_80543ABC[];

extern u16 lbl_804B14C0[];

struct AudioThreadObj {
    void* vtbl;
    s32 created;
    OSThread thread;
    u8 stack[0x64000];
    OSMessageQueue freeQueue;
    OSMessageQueue decodedQueue;
    OSMessage freeMessages[3];
    OSMessage decodedMessages[3];
};

extern void* lbl_804B15DC[];
extern "C" s32 fn_8042DD54(s16*, u8*, s32);

struct VideoThreadObj {
    void* vtbl;
    s32 created;
    OSThread thread;
    u8 stack[0x64000];
    OSMessageQueue freeQueue;
    OSMessageQueue decodedQueue;
    OSMessage freeMessages[3];
    OSMessage decodedMessages[3];
    s32 first;
    u8 pad[4];
};

extern void* lbl_804B15E8[];
extern "C" s32 fn_8042DA54(u8*, u8*, u8*, u8*, void*);

struct ReadThreadObj {
    void* vtbl;
    s32 created;
    OSMessageQueue freeQueue;
    OSMessageQueue readQueue;
    OSMessageQueue readQueue2;
    OSMessage freeMessages[10];
    OSMessage readMessages[10];
    OSMessage readMessages2[10];
    OSThread thread;
    u8 stack[0x1000];
};

extern "C" s32 fn_80427D2C(s32 a, s32 b, s32 c, s32 d, s32 e);
extern "C" s32 fn_80427D60();
extern "C" s32 fn_80427D94();
extern "C" s32 fn_80427DB4(void* a, s32 b);
extern "C" s32 fn_80427DD4(s32, s32 a, s32 b, s32 c, s32 d);
extern "C" s32 fn_80427E08();
extern "C" s32 fn_80427E28();
extern "C" s32 fn_80427E58(void* this_, s32 idx);
extern "C" void* fn_80427F34(s32 i);
extern "C" void* fn_80427F60(void* this_, s16 flag);
extern "C" void* fn_80428030(void* this_);
extern "C" void fn_804280C0(f32 v);
extern "C" s32 fn_80428134();
extern "C" void fn_804281FC(s32 a, s32 b, s32 c, s32 d);
extern "C" s32 fn_8042828C(void* p);
extern "C" void* fn_80428294(void);
extern "C" s32 fn_8042829C();
extern "C" void fn_804283B0(void* this_);
extern "C" void fn_804283D4();
extern "C" u8 fn_8042840C();
extern "C" u8 fn_80428448();
extern "C" void fn_80428524(void* o, u32 v);
extern "C" u8 fn_8042852C(void* p);
extern "C" void fn_8042855C(void* p);
extern "C" u8 fn_8042858C(void* p, u32 prio);
extern "C" void* fn_804285F4(void*, u32);
extern "C" u8 fn_80428630();
extern "C" bool fn_804286A0(s32 a, s32 b, s32 c, s32 d);
extern "C" s32 fn_804286B4(s32 vol, s32 time);
extern "C" s32 fn_804287DC();
extern "C" u32 fn_804287EC();
extern "C" s32 fn_80428810(void* dst);
extern "C" s32 fn_80428858(void* dst);
extern "C" s32 fn_804288A0(void* rmode, s32 x, s32 y, s32 w, s32 h);
extern "C" void fn_80428978();
extern "C" s32 fn_80428A28();
extern "C" void fn_80428A88();
extern "C" void fn_80428C38(u8 v);
extern "C" s32 fn_80428C6C();
extern "C" void fn_80428CBC(u32 retraceCount);
extern "C" u8 fn_80428F74();
extern "C" u8 fn_804290B4();
extern "C" void fn_80429120();
extern "C" s32 fn_804291F0(u8* buffer);
extern "C" s32 fn_80429400();
extern "C" u8 fn_80429454(void* fileName, u8 onMemory);
extern "C" void fn_80429748();
extern "C" u8 fn_80429784(s32 audioSystem);
extern "C" void* fn_80429850();
extern "C" void fn_80429894(THPTextureSet* buffer);
extern "C" void fn_804298C4();
extern "C" void fn_804298EC();
extern "C" s16* fn_80429918(s32 sample);
extern "C" void fn_804299C0(s16* destination, s16* source, u32 sample);
extern "C" void fn_80429BE4(u8* yImage, u8* uImage, u8* vImage, s16 x, s16 y, s16 textureWidth, s16 textureHeight, s16 polygonWidth, s16 polygonHeight);
extern "C" void fn_80429DE0();
extern "C" void fn_80429DE4(s16 s, s16 t);
extern "C" void fn_80429DF4(s16 x, s16 y, s16 z);
extern "C" void fn_80429E08(GXRenderModeObj* rmode);
extern "C" void fn_8042A2A4(GXTexCoordID dst, GXTexGenType func, GXTexGenSrc src, u32 mtx);
extern "C" void fn_8042A2CC();
extern "C" void fn_8042A3E4(AudioThreadObj* t);
extern "C" void fn_8042A428(AudioThreadObj* t);
extern "C" u8 fn_8042A458(AudioThreadObj* t, s32 priority, void* param);
extern "C" void fn_8042A534(AudioThreadObj* t, u8* bufPtr);
extern "C" void fn_8042A5E0(AudioThreadObj* t, u32);
extern "C" void fn_8042A608(AudioThreadObj* t, THPReadBuffer* readBuffer);
extern "C" void fn_8042A6DC(AudioThreadObj* t, OSMessage msg);
extern "C" void* fn_8042A708(AudioThreadObj* t, s32 flag);
extern "C" void fn_8042A74C(AudioThreadObj* t, OSMessage msg);
extern "C" u32 fn_8042A778(AudioThreadObj* t);
extern "C" AudioThreadObj* fn_8042A7AC(AudioThreadObj* t, s16 flag);
extern "C" void fn_8042A7FC(AudioThreadObj* t);
extern "C" void fn_8042A818(VideoThreadObj* t);
extern "C" void fn_8042A85C(VideoThreadObj* t);
extern "C" u8 fn_8042A88C(VideoThreadObj* t, s32 priority, void* param);
extern "C" void fn_8042A970(VideoThreadObj* t, u8* bufPtr);
extern "C" void fn_8042AAA8(VideoThreadObj* t, u32);
extern "C" void fn_8042AB70(VideoThreadObj* t, THPReadBuffer* readBuffer);
extern "C" void fn_8042ACA0(VideoThreadObj* t, OSMessage msg);
extern "C" void* fn_8042ACCC(VideoThreadObj* t, s32 flag);
extern "C" void fn_8042AD10(VideoThreadObj* t, OSMessage msg);
extern "C" u32 fn_8042AD3C(VideoThreadObj* t);
extern "C" VideoThreadObj* fn_8042AD70(VideoThreadObj* t, s16 flag);
extern "C" void fn_8042ADC0(VideoThreadObj* t);
extern "C" u8 fn_8042ADDC(ReadThreadObj* t, s32 priority);
extern "C" void fn_8042AE74(ReadThreadObj* t, u32);
extern "C" s32 fn_8042AF54(THPReadBuffer* readBuffer);
extern "C" void fn_8042AF60(ReadThreadObj* t);
extern "C" void fn_8042AFA4(ReadThreadObj* t);
extern "C" void fn_8042AFD4(ReadThreadObj* t, OSMessage msg);
extern "C" u32 fn_8042AFFC(ReadThreadObj* t);
extern "C" void fn_8042B02C(ReadThreadObj* t, OSMessage msg);
extern "C" u32 fn_8042B054(ReadThreadObj* t);
extern "C" void fn_8042B084(ReadThreadObj* t, OSMessage msg);
extern "C" u32 fn_8042B0AC(ReadThreadObj* t);
extern "C" ReadThreadObj* fn_8042B0DC(ReadThreadObj* t, s16 flag);
extern "C" void fn_8042B12C(ReadThreadObj* t);
extern "C" u8 fn_8042B148();
extern "C" void fn_8042E1E4(Obj8042E1E4* o, u16 v);
extern "C" void* fn_8042E1F4();
extern "C" u16 fn_8042E1FC(Obj8042E1E4* o);
extern "C" void fn_8042E204(u32 a);
extern "C" u8 fn_8042E22C();
extern "C" void fn_8042E250(u32 a);
extern "C" void fn_8042E278();
extern "C" u8 fn_8042E29C(u32 a);
extern "C" void* fn_8042E2C4(u32 a);
extern "C" void fn_8042E2EC(u32 a);
extern "C" void* fn_8042E314(u32 a);
extern "C" void fn_8042E33C(u32 a);
extern "C" void fn_8042E364();
extern "C" void fn_8042E388();
extern "C" void fn_8042E3AC();
extern "C" void fn_8042E3D0();
extern "C" void fn_8042E3F4();
extern "C" void fn_8042E418();
extern "C" void fn_8042E43C(u32 a);
extern "C" void fn_8042E4C4(THPReadBuffer* a);
extern "C" void fn_8042E4EC(u32 a);
extern "C" void fn_8042E514(u32 a);
extern "C" void fn_8042E53C(THPReadBuffer* a);
extern "C" void fn_8042E564(u32 a);
extern "C" u32 fn_8042E58C();
extern "C" void fn_8042E5B0(u32 a);
extern "C" u32 fn_8042E5D8();
extern "C" void fn_8042E5FC(u32 a);
extern "C" void fn_8042E624(u32 a);
extern "C" void fn_8042E64C(THPReadBuffer* a);
extern "C" u32 fn_8042E674();
extern "C" void fn_8042E698(u32 a);
extern "C" u32 fn_8042E6C0();
extern "C" void fn_8042E6E4(u32 a);
extern "C" void fn_8042E70C(u32 a);
extern "C" u32 fn_8042E734();
extern "C" void* fn_8042E780(void* o);
extern void* lbl_804B15F4[];
extern u8 lbl_8053AE78;
extern "C" void fn_8042B1A8();

extern "C" s32 fn_80427D2C(s32 a, s32 b, s32 c, s32 d, s32 e) {
    if (lbl_8053AEBD) {
        return 0;
    }
    return fn_80427DD4(a, b, c, d, e);
}

extern "C" s32 fn_80427D60() {
    if (lbl_8053AEBD) {
        return 0;
    }
    return fn_80427E08();
}

extern "C" s32 fn_80427D94() { return fn_80427E28(); }

extern "C" s32 fn_80427DB4(void* a, s32 b) { return fn_80427E58(a, b); }

extern "C" s32 fn_80427DD4(s32, s32 a, s32 b, s32 c, s32 d) {
    fn_804281FC(a, b, c, d);
    return 1;
}

extern "C" s32 fn_80427E08() { return fn_8042829C(); }

extern "C" s32 fn_80427E28() {
    fn_8042E1E4((Obj8042E1E4*)fn_8042E1F4(), lbl_8053AEBE);
    fn_804283D4();
    return 1;
}

extern "C" s32 fn_80427E58(void* this_, s32 idx) {
    lbl_8053AEBE = fn_8042E1FC((Obj8042E1E4*)fn_8042E1F4());
    fn_8042E1E4((Obj8042E1E4*)fn_8042E1F4(), 1);
    lbl_8053AEBD = 0;
    *(void**)((char*)this_ + 0x10) = (void*)fn_80428134;
    *(void**)((char*)this_ + 0x14) = (void*)fn_804280C0;
    *(void**)((char*)this_ + 0x18) = (void*)fn_804287EC;
    void* p = fn_80427F34(idx);
    if (p) {
        lbl_8053AEB4 = p;
        if (!fn_8042840C()) {
            lbl_8053AEBD = 1;
            return 0;
        }
        return 1;
    }
    lbl_8053AEB4 = fn_80427F34(0);
    if (!fn_8042840C()) {
        lbl_8053AEBD = 1;
        return 0;
    }
    return 1;
}

extern "C" void* fn_80427F34(s32 i) {
    if (i >= 0 && i < 4) {
        return lbl_804B15C0[i];
    }
    return 0;
}

extern "C" void* fn_80427F60(void* this_, s16 flag) {
    if (this_ != 0) {
        *(void**)this_ = lbl_804B15D0;
        void* p1 = *(void**)((char*)this_ + 0x4);
        if (p1 != 0) {
            ((Slot0*)p1)->slot0(1);
        }
        *(void**)((char*)this_ + 0x4) = 0;
        void* p2 = *(void**)((char*)this_ + 0x8);
        if (p2 != 0) {
            ((Slot0*)p2)->slot0(1);
        }
        *(void**)((char*)this_ + 0x8) = 0;
        void* p3 = *(void**)((char*)this_ + 0xc);
        if (p3 != 0) {
            ((Slot0*)p3)->slot0(1);
        }
        *(void**)((char*)this_ + 0xc) = 0;
        if (flag > 0) {
            __dl__FPv(this_);
        }
    }
    return this_;
}

extern "C" void* fn_80428030(void* this_) {
    char* p = (char*)this_;
    *(void**)p = lbl_804B15D0;
    SubObj_8042B12C* obj1 = new SubObj_8042B12C();
    *(SubObj_8042B12C**)(p + 0x4) = obj1;
    SubObj_8042ADC0* obj2 = new SubObj_8042ADC0();
    *(SubObj_8042ADC0**)(p + 0x8) = obj2;
    SubObj_8042A7FC* obj3 = new SubObj_8042A7FC();
    *(SubObj_8042A7FC**)(p + 0xc) = obj3;
    return this_;
}

extern "C" void fn_804280C0(f32 v) {
    if (!lbl_8053AEBD) {
        s32 vol;
        if (v >= 1.0f) {
            vol = 0x7f;
        } else if (v <= 0.0f) {
            vol = 0;
        } else {
            vol = v / 127.0f;
        }
        fn_804286B4(vol, 0);
    }
}

extern "C" s32 fn_80428134() {
    if (lbl_8053AEBD || fn_804287DC() == 5) {
        return 0;
    }
    u32 frame;
    if (lbl_8052AAD0.open && lbl_8052AAD0.dispTextureSet) {
        frame = (lbl_8052AAD0.dispTextureSet->frameNumber + lbl_8052AAD0.initReadFrame) % lbl_8052AAD0.header.numFrames;
    } else {
        return -1;
    }
    u32 n = fn_804287EC();
    if (n == 0) {
        return 0;
    }
    if (n <= 1) {
        return 0;
    }
    n--;
    return frame >= n ? 0 : n - frame;
}

extern "C" void fn_804281FC(s32 a, s32 b, s32 c, s32 d) {
    if (fn_804286A0(a, b, c, d)) {
        fn_804288A0((void*)fn_8042828C(fn_80428294()), lbl_8053AEA4 + a, lbl_8053AEA8 + b, lbl_8052BEC0[0] + c, lbl_8052BEC0[1] + d);
        fn_80428A88();
    }
}

#pragma dont_inline on
extern "C" s32 fn_8042828C(void* p) {
    return *(s32*)((char*)p + 0x4);
}
#pragma dont_inline off

#pragma dont_inline on
extern "C" void* fn_80428294(void) {
    return sManager__8JUTVideo;
}
#pragma dont_inline off

extern "C" s32 fn_8042829C() {
    if (lbl_8053AEB8 == 0) {
        if (fn_8042E22C()) {
            fn_8042E204(0);
            if (lbl_8053AEBC) {
                return 0;
            }
            if (!fn_80428448()) {
                return 0;
            }
            lbl_8053AEB8 = 1;
        }
    } else if (lbl_8053AEB8 == 1) {
        switch (fn_80428C6C()) {
        case 0:
            return 0;
        case 1:
            lbl_8052AAD0.internalState = 0;
            lbl_8052AAD0.state = 1;
            lbl_8052AAD0.dispTextureSet = 0;
            lbl_8052AAD0.playAudioBuffer = 0;
            lbl_8052AAD0.mF0 = 0;
            lbl_8052AAD0.mF4 = 0;
            lbl_8053AE90 = (void*)VISetPostRetraceCallback((VIRetraceCallback)fn_80428CBC);
            fn_80428A28();
            lbl_8053AEB8 = 2;
            break;
        }
    } else if (fn_804287DC() == 5) {
        fn_80428978();
        fn_80429400();
        if (lbl_8053AEAC) {
            fn_804283B0(lbl_8053AEAC);
        }
        return 0;
    }
    return 1;
}

// fn_804283B0(this) - helper: free__7JKRHeapFPvP7JKRHeap(this, 0).
extern "C" void fn_804283B0(void* this_) {
    free__7JKRHeapFPvP7JKRHeap(this_, 0);
}

#pragma dont_inline on
extern "C" void fn_804283D4() {
    fn_80428978();
    fn_80429400();
    fn_80429748();
    if (lbl_8053AEAC) {
        fn_804283B0(lbl_8053AEAC);
    }
}
#pragma dont_inline off

extern "C" u8 fn_8042840C() {
    lbl_8053AEB8 = 0;
    lbl_8053AEBC = 0;
    return fn_80428630() != 0;
}

extern "C" u8 fn_80428448() {
    fn_80428858(lbl_8052BEC0);
    fn_80428810(lbl_8052BECC);
    lbl_8053AEA4 = (((RenderModeHolder*)fn_8042828C(fn_80428294()))->fbWidth - lbl_8052BEC0[0]) >> 1;
    lbl_8053AEA8 = (((RenderModeHolder*)fn_8042828C(fn_80428294()))->efbHeight - lbl_8052BEC0[1]) >> 1;
    fn_804291F0((u8*)lbl_8053AEAC);
    s32 r;
    if (lbl_8052BECC[3] != 1) {
        r = OSGetTick() % lbl_8052BECC[3];
    } else {
        r = 0;
    }
    lbl_8053AEB0 = r;
    if (!((u8 (*)(s32, s32))fn_80428AC8)(0, 0)) {
        return 0;
    }
    return 1;
}

extern "C" void fn_80428524(void* o, u32 v) { *(u32*)((char*)o + 4) = v; }

extern "C" u8 fn_8042852C(void* p) {
    return OSIsThreadTerminated((OSThread*)((char*)p + 0xe0)) != 0;
}

extern "C" void fn_8042855C(void* p) {
    if (*(s32*)((char*)p + 4)) {
        OSResumeThread((OSThread*)((char*)p + 0xe0));
    }
}

extern "C" u8 fn_8042858C(void* p, u32 prio) {
    if (!OSCreateThread((OSThread*)((char*)p + 0xe0), (void*(*)(void*))fn_8042E250, 0, (char*)p + 0x13f8, 0x1000, prio, 1)) {
        return 0;
    }
    *(s32*)((char*)p + 4) = 1;
    return 1;
}

extern "C" void* fn_804285F4(void*, u32) {
    if (!fn_80429454(lbl_8053AEB4, 0)) {
        lbl_8053AEBC = 1;
    }
    return 0;
}

extern "C" u8 fn_80428630() {
    fn_80429784(0);
    lbl_8053AEAC = alloc__7JKRHeapFUli(fn_8042E758(), 0x1c0000, 0x20);
    if (!lbl_8053AEAC) {
        return 0;
    }
    if (!fn_8042E29C(OSGetThreadPriority(OSGetCurrentThread()) + 1)) {
        return 0;
    }
    fn_8042E278();
    return 1;
}

extern "C" bool fn_804286A0(s32 a, s32 b, s32 c, s32 d) {
    return lbl_8053AEB8 == 2;
}

extern "C" s32 fn_804286B4(s32 vol, s32 time) {
    s32 samplePerMs;
    BOOL old;
    if (lbl_8052AAD0.open && lbl_8052AAD0.audioExist) {
        if (AIGetDSPSampleRate() == 0) {
            samplePerMs = 32;
        } else {
            samplePerMs = 48;
        }
        if (vol > 127) {
            vol = 127;
        }
        if (vol < 0) {
            vol = 0;
        }
        if (time > 60000) {
            time = 60000;
        }
        if (time < 0) {
            time = 0;
        }
        old = OSDisableInterrupts();
        lbl_8052AAD0.targetVolume = vol;
        if (time) {
            lbl_8052AAD0.rampCount = samplePerMs * time;
            lbl_8052AAD0.deltaVolume = (lbl_8052AAD0.targetVolume - lbl_8052AAD0.curVolume) / lbl_8052AAD0.rampCount;
        } else {
            lbl_8052AAD0.rampCount = 0;
            lbl_8052AAD0.curVolume = lbl_8052AAD0.targetVolume;
        }
        OSRestoreInterrupts(old);
        return 1;
    }
    return 0;
}

extern "C" s32 fn_804287DC() { return lbl_8052AAD0.state; }

extern "C" u32 fn_804287EC() {
    if (lbl_8052AAD0.open) {
        return lbl_8052AAD0.header.numFrames;
    }
    return 0;
}

extern "C" s32 fn_80428810(void* dst) {
    if (lbl_8052AAD0.open) {
        memcpy(dst, lbl_8052AAD0.audioInfo, 0x10);
        return 1;
    }
    return 0;
}

extern "C" s32 fn_80428858(void* dst) {
    if (lbl_8052AAD0.open) {
        memcpy(dst, lbl_8052AAD0.videoInfo, 0xc);
        return 1;
    }
    return 0;
}

extern "C" s32 fn_804288A0(void* rmode, s32 x, s32 y, s32 w, s32 h) {
    if (lbl_8052AAD0.open && lbl_8052AAD0.state && lbl_8052AAD0.dispTextureSet) {
        fn_80429E08((GXRenderModeObj*)rmode);
        fn_80429BE4(lbl_8052AAD0.dispTextureSet->ytexture, lbl_8052AAD0.dispTextureSet->utexture,
                    lbl_8052AAD0.dispTextureSet->vtexture, x, y, lbl_8052AAD0.videoInfo[0], lbl_8052AAD0.videoInfo[1],
                    w, h);
        fn_8042A2CC();
        return (lbl_8052AAD0.dispTextureSet->frameNumber + lbl_8052AAD0.initReadFrame) % lbl_8052AAD0.header.numFrames;
    }
    return -1;
}

extern "C" void fn_80428978() {
    if (lbl_8052AAD0.open && lbl_8052AAD0.state) {
        lbl_8052AAD0.state = lbl_8052AAD0.internalState = 0;
        VISetPostRetraceCallback((VIRetraceCallback)lbl_8053AE90);
        if (!lbl_8052AAD0.onMemory) {
            DVDCancel(&lbl_8052AAD0.fileInfo.cb);
            fn_8042E3AC();
        }
        fn_8042E388();
        if (lbl_8052AAD0.audioExist) {
            fn_8042E364();
            fn_804298C4();
        }
        while (fn_80429850()) {
        }
        lbl_8052AAD0.curVolume = lbl_8052AAD0.targetVolume;
        lbl_8052AAD0.rampCount = 0;
    }
}

extern "C" s32 fn_80428A28() {
    if (lbl_8052AAD0.open && (lbl_8052AAD0.state == 1 || lbl_8052AAD0.state == 4)) {
        lbl_8052AAD0.state = 2;
        lbl_8052AAD0.prevCount = 0;
        lbl_8052AAD0.curCount = 0;
        lbl_8052AAD0.retraceCount = -1;
        return 1;
    }
    return 0;
}

extern "C" void fn_80428A88() {
    void* p;
    GXDrawDone();
    if (lbl_8053AE88) {
        while (true) {
            p = fn_80429850();
            if (!p) {
                break;
            }
            fn_8042E2EC((u32)p);
        }
    }
}

#pragma dont_inline on
extern "C" u8 fn_80428AC8(s32 frameNum, s32 playFlag, s32 audioTrack) {
    if (lbl_8052AAD0.open && lbl_8052AAD0.state == 0) {
        if (frameNum > 0) {
            if (lbl_8052AAD0.header.offsetDataOffsets == 0) {
                return 0;
            }
            if (lbl_8052AAD0.header.numFrames > (u32)frameNum) {
                u32* tbl = (u32*)lbl_8052ACA0;
                u32 a = *tbl++;
                u32 b = *tbl;
                u32 mdo = lbl_8052AAD0.header.movieDataOffsets;
                lbl_8052AAD0.initReadFrame = frameNum;
                lbl_8052AAD0.initOffset = mdo + a;
                lbl_8052AAD0.initReadSize = b - a;
            } else {
                return 0;
            }
        } else {
            lbl_8052AAD0.initOffset = lbl_8052AAD0.header.movieDataOffsets;
            lbl_8052AAD0.initReadSize = lbl_8052AAD0.header.firstFrameSize;
            lbl_8052AAD0.initReadFrame = frameNum;
        }
        if (lbl_8052AAD0.audioExist) {
            if (audioTrack < 0 || (u32)audioTrack >= *(u32*)(lbl_8052AAD0.audioInfo + 0xc)) {
                return 0;
            }
            lbl_8052AAD0.curAudioTrack = audioTrack;
        }
        lbl_8052AAD0.playFlag = playFlag & 1;
        lbl_8052AAD0.mD8 = 0;
        if (!lbl_8052AAD0.onMemory) {
            fn_8042E494(0x14, NULL);
            if (lbl_8052AAD0.audioExist) {
                fn_8042E464(0xc, NULL);
            }
            fn_8042E43C(8);
        }
        fn_80429120();
        fn_8042E418();
        if (lbl_8052AAD0.audioExist) {
            fn_8042E3F4();
        }
        if (!lbl_8052AAD0.onMemory) {
            fn_8042E3D0();
        }
        return 1;
    }
    return 0;
}

extern "C" void fn_80428C38(u8 v) {
    OSSendMessage(&lbl_8052ACE0, (OSMessage)v, 1);
}
#pragma dont_inline off

extern "C" s32 fn_80428C6C() {
    OSMessage msg;
    if (OSReceiveMessage(&lbl_8052ACE0, &msg, 0) == 1) {
        return (s32)msg != 0;
    }
    return -1;
}

extern "C" void fn_80428CBC(u32 retraceCount) {
    THPTextureSet* textureSet;
    if (lbl_8053AE90) {
        ((VIRetraceCallback)lbl_8053AE90)(retraceCount);
    }
    textureSet = (THPTextureSet*)0xFFFFFFFF;
    if (lbl_8052AAD0.open && lbl_8052AAD0.state == 2) {
        if (lbl_8052AAD0.dvdError || lbl_8052AAD0.videoError) {
            lbl_8052AAD0.state = lbl_8052AAD0.internalState = 5;
            return;
        }
        lbl_8052AAD0.retraceCount++;
        if (lbl_8052AAD0.retraceCount == 0) {
            if (fn_804290B4()) {
                if (lbl_8052AAD0.audioExist) {
                    if (lbl_8052AAD0.mF0 - lbl_8052AAD0.mF4 <= 1) {
                        textureSet = (THPTextureSet*)fn_8042E2C4(0);
                        lbl_8052AAD0.mF0++;
                        lbl_8052AAD0.mD8--;
                    } else {
                        lbl_8052AAD0.internalState = 2;
                    }
                } else {
                    textureSet = (THPTextureSet*)fn_8042E2C4(0);
                }
            } else {
                lbl_8052AAD0.retraceCount = -1;
            }
        } else {
            if (lbl_8052AAD0.retraceCount == 1) {
                lbl_8052AAD0.internalState = 2;
            }
            if (fn_80428F74()) {
                if (lbl_8052AAD0.audioExist) {
                    if (lbl_8052AAD0.mF0 - lbl_8052AAD0.mF4 <= 1) {
                        textureSet = (THPTextureSet*)fn_8042E2C4(0);
                        lbl_8052AAD0.mF0++;
                        lbl_8052AAD0.mD8--;
                    }
                } else {
                    textureSet = (THPTextureSet*)fn_8042E2C4(0);
                }
            }
        }
        if (textureSet && textureSet != (THPTextureSet*)0xFFFFFFFF) {
            if (lbl_8052AAD0.dispTextureSet) {
                fn_80429894(lbl_8052AAD0.dispTextureSet);
            }
            lbl_8052AAD0.dispTextureSet = textureSet;
        }
        if (!(lbl_8052AAD0.playFlag & 1)) {
            if (lbl_8052AAD0.audioExist) {
                if (lbl_8052AAD0.mF4 + lbl_8052AAD0.initReadFrame == lbl_8052AAD0.header.numFrames && lbl_8052AAD0.playAudioBuffer == 0) {
                    lbl_8052AAD0.state = lbl_8052AAD0.internalState = 3;
                }
            } else {
                u32 frame;
                if (lbl_8052AAD0.dispTextureSet) {
                    frame = lbl_8052AAD0.dispTextureSet->frameNumber + lbl_8052AAD0.initReadFrame;
                } else {
                    frame = lbl_8052AAD0.initReadFrame - 1;
                }
                if (frame == lbl_8052AAD0.header.numFrames - 1 && textureSet == 0) {
                    lbl_8052AAD0.state = lbl_8052AAD0.internalState = 3;
                }
            }
        }
    }
}

extern "C" u8 fn_80428F74() {
    if (lbl_8052AAD0.videoInfo[2] & 1) {
        if (VIGetNextField() == 0) {
            return 1;
        }
    } else if (lbl_8052AAD0.videoInfo[2] & 2) {
        if (VIGetNextField() == 1) {
            return 1;
        }
    } else {
        s32 frameRate = lbl_8052AAD0.header.frameRate * 100.0f;
        if (VIGetTvFormat() == 1) {
            lbl_8052AAD0.curCount = (lbl_8052AAD0.retraceCount * frameRate) / 5000;
        } else {
            lbl_8052AAD0.curCount = (lbl_8052AAD0.retraceCount * frameRate) / 5994;
        }
        if (lbl_8052AAD0.prevCount != lbl_8052AAD0.curCount) {
            lbl_8052AAD0.prevCount = lbl_8052AAD0.curCount;
            return 1;
        }
    }
    return 0;
}

extern "C" u8 fn_804290B4() {
    if (lbl_8052AAD0.videoInfo[2] & 1) {
        if (VIGetNextField() == 0) {
            return 1;
        }
    } else if (lbl_8052AAD0.videoInfo[2] & 2) {
        if (VIGetNextField() == 1) {
            return 1;
        }
    } else {
        return 1;
    }
    return 0;
}

extern "C" void fn_80429120() {
    s32 i;
    if (!lbl_8052AAD0.onMemory) {
        for (i = 0; i < 10; i++) {
            fn_8042E4C4(&lbl_8052AAD0.readBuffer[i]);
        }
    }
    for (i = 0; i < 3; i++) {
        fn_8042E2EC((u32)&lbl_8052AAD0.textureSet[i]);
    }
    if (lbl_8052AAD0.audioExist) {
        for (i = 0; i < 3; i++) {
            fn_8042E33C((u32)&lbl_8052AAD0.audioBuffer[i]);
        }
    }
    OSInitMessageQueue(&lbl_8052ACE0, &lbl_8053AE8C, 1);
}

extern "C" s32 fn_804291F0(u8* buffer) {
    u32 i;
    u8* ptr;
    u32 ysize;
    u32 uvsize;
    if (lbl_8052AAD0.open && lbl_8052AAD0.state == 0) {
        if (lbl_8052AAD0.onMemory) {
            lbl_8052AAD0.movieData = buffer;
            ptr = buffer + lbl_8052AAD0.header.movieDataSize;
        } else {
            ptr = buffer;
            for (i = 0; i < 10; i++) {
                lbl_8052AAD0.readBuffer[i].ptr = ptr;
                ptr += OSRoundUp32B(lbl_8052AAD0.header.bufSize);
            }
        }
        ysize = OSRoundUp32B(lbl_8052AAD0.videoInfo[0] * lbl_8052AAD0.videoInfo[1]);
        uvsize = OSRoundUp32B(lbl_8052AAD0.videoInfo[0] * lbl_8052AAD0.videoInfo[1] / 4);
        for (i = 0; i < 3; i++) {
            lbl_8052AAD0.textureSet[i].ytexture = ptr;
            DCInvalidateRange(ptr, ysize);
            ptr += ysize;
            lbl_8052AAD0.textureSet[i].utexture = ptr;
            DCInvalidateRange(ptr, uvsize);
            ptr += uvsize;
            lbl_8052AAD0.textureSet[i].vtexture = ptr;
            DCInvalidateRange(ptr, uvsize);
            ptr += uvsize;
        }
        if (lbl_8052AAD0.audioExist) {
            for (i = 0; i < 3; i++) {
                lbl_8052AAD0.audioBuffer[i].buffer = (s16*)ptr;
                lbl_8052AAD0.audioBuffer[i].curPtr = (s16*)ptr;
                lbl_8052AAD0.audioBuffer[i].validSample = 0;
                ptr += OSRoundUp32B(lbl_8052AAD0.header.audioMaxSamples * 4);
            }
        }
        lbl_8052AAD0.mBufEnd = ptr;
        return 1;
    }
    return 0;
}

extern "C" s32 fn_80429400() {
    if (lbl_8052AAD0.open && lbl_8052AAD0.state == 0) {
        lbl_8052AAD0.open = 0;
        DVDClose(&lbl_8052AAD0.fileInfo);
        return 1;
    }
    return 0;
}

extern "C" u8 fn_80429454(void* fileName, u8 onMemory) {
    s32 offset;
    s32 i;
    if (!lbl_8053AE88) {
        return 0;
    }
    if (lbl_8052AAD0.open) {
        return 0;
    }
    memset(&lbl_8052AAD0.videoInfo, 0, sizeof(lbl_8052AAD0.videoInfo));
    memset(&lbl_8052AAD0.audioInfo, 0, sizeof(lbl_8052AAD0.audioInfo));
    if (!DVDOpen((char*)fileName, &lbl_8052AAD0.fileInfo)) {
        return 0;
    }
    if (DVDReadPrio(&lbl_8052AAD0.fileInfo, lbl_8052ACA0, 0x40, 0, 2) < 0) {
        DVDClose(&lbl_8052AAD0.fileInfo);
        return 0;
    }
    memcpy(&lbl_8052AAD0.header, lbl_8052ACA0, sizeof(THPHeader));
    if (strcmp(lbl_8052AAD0.header.magic, "THP") != 0) {
        DVDClose(&lbl_8052AAD0.fileInfo);
        return 0;
    }
    if (lbl_8052AAD0.header.version != 0x11000) {
        DVDClose(&lbl_8052AAD0.fileInfo);
        return 0;
    }
    offset = lbl_8052AAD0.header.compInfoDataOffsets;
    if (DVDReadPrio(&lbl_8052AAD0.fileInfo, lbl_8052ACA0, 0x20, offset, 2) < 0) {
        DVDClose(&lbl_8052AAD0.fileInfo);
        return 0;
    }
    memcpy(&lbl_8052AAD0.compInfo, lbl_8052ACA0, sizeof(THPFrameCompInfo));
    offset += sizeof(THPFrameCompInfo);
    lbl_8052AAD0.audioExist = 0;
    for (i = 0; i < lbl_8052AAD0.compInfo.numComponents; i++) {
        switch (lbl_8052AAD0.compInfo.frameComp[i]) {
        case 0:
            if (DVDReadPrio(&lbl_8052AAD0.fileInfo, lbl_8052ACA0, 0x20, offset, 2) < 0) {
                DVDClose(&lbl_8052AAD0.fileInfo);
                return 0;
            }
            memcpy(&lbl_8052AAD0.videoInfo, lbl_8052ACA0, sizeof(lbl_8052AAD0.videoInfo));
            offset += sizeof(lbl_8052AAD0.videoInfo);
            break;
        case 1:
            if (DVDReadPrio(&lbl_8052AAD0.fileInfo, lbl_8052ACA0, 0x20, offset, 2) < 0) {
                DVDClose(&lbl_8052AAD0.fileInfo);
                return 0;
            }
            memcpy(&lbl_8052AAD0.audioInfo, lbl_8052ACA0, sizeof(lbl_8052AAD0.audioInfo));
            lbl_8052AAD0.audioExist = 1;
            offset += sizeof(lbl_8052AAD0.audioInfo);
            break;
        default:
            return 0;
        }
    }
    lbl_8052AAD0.state = lbl_8052AAD0.internalState = 0;
    lbl_8052AAD0.playFlag = 0;
    lbl_8052AAD0.onMemory = onMemory;
    lbl_8052AAD0.open = 1;
    lbl_8052AAD0.curVolume = 127.0f;
    lbl_8052AAD0.targetVolume = lbl_8052AAD0.curVolume;
    lbl_8052AAD0.rampCount = 0;
    return 1;
}

extern "C" void fn_80429748() {
    LCDisable();
    fn_804298C4();
    lbl_8053AE88 = 0;
    lbl_8052AAD0.dvdError = 0;
    lbl_8052AAD0.videoError = 0;
}

extern "C" u8 fn_80429784(s32 audioSystem) {
    BOOL old;
    memset(&lbl_8052AAD0, 0, sizeof(THPPlayerState));
    LCEnable();
    OSInitMessageQueue(&lbl_8052AD00, lbl_8052AD20, 3);
    if (!fn_8042B148()) {
        return 0;
    }
    old = OSDisableInterrupts();
    lbl_8053AEA0 = audioSystem;
    lbl_8053AE94 = 0;
    lbl_8053AE98 = 0;
    lbl_8053AE9C = 0;
    fn_804298EC();
    OSRestoreInterrupts(old);
    if (lbl_8053AEA0 == 0) {
        memset(lbl_8052AD40, 0, sizeof(lbl_8052AD40));
        DCStoreRange(lbl_8052AD40, sizeof(lbl_8052AD40));
    }
    lbl_8053AE88 = 1;
    return 1;
}

extern "C" void* fn_80429850() {
    OSMessage msg;
    if (OSReceiveMessage(&lbl_8052AD00, &msg, 0) == 1) {
        return msg;
    }
    return 0;
}

extern "C" void fn_80429894(THPTextureSet* buffer) {
    OSSendMessage(&lbl_8052AD00, buffer, 0);
}

extern "C" void fn_804298C4() {
    JASDriver::registerMixCallback(0, MixMode_Mono);
}

extern "C" void fn_804298EC() {
    JASDriver::registerMixCallback(fn_80429918, MixMode_InterLeave);
}

extern "C" s16* fn_80429918(s32 sample) {
    BOOL old;
    if (!lbl_8052AAD0.open || lbl_8052AAD0.internalState != 2 || !lbl_8052AAD0.audioExist) {
        return 0;
    }
    old = OSEnableInterrupts();
    lbl_8053AE94 ^= 1;
    fn_804299C0(lbl_8052AD40[lbl_8053AE94], 0, sample);
    OSRestoreInterrupts(old);
    return lbl_8052AD40[lbl_8053AE94];
}

extern "C" void fn_804299C0(s16* destination, s16* source, u32 sample) {
    u32 sampleNum;
    u32 requestSample;
    u32 i;
    s32 mix;
    s16* dst;
    s16* thpsrc;
    u16 attenuation;
    if (lbl_8052AAD0.open && lbl_8052AAD0.internalState == 2 && lbl_8052AAD0.audioExist) {
        requestSample = sample;
        dst = destination;
        while (true) {
            if (lbl_8052AAD0.playAudioBuffer == 0) {
                if ((lbl_8052AAD0.playAudioBuffer = (THPAudioBuffer*)fn_8042E314(0)) == 0) {
                    memset(dst, 0, requestSample << 2);
                    return;
                }
                lbl_8052AAD0.mF4++;
            }
            if (lbl_8052AAD0.playAudioBuffer->validSample) {
                if (lbl_8052AAD0.playAudioBuffer->validSample >= requestSample) {
                    sampleNum = requestSample;
                } else {
                    sampleNum = lbl_8052AAD0.playAudioBuffer->validSample;
                }
                thpsrc = lbl_8052AAD0.playAudioBuffer->curPtr;
                for (i = 0; i < sampleNum; i++) {
                    if (lbl_8052AAD0.rampCount) {
                        lbl_8052AAD0.rampCount--;
                        lbl_8052AAD0.curVolume += lbl_8052AAD0.deltaVolume;
                    } else {
                        lbl_8052AAD0.curVolume = lbl_8052AAD0.targetVolume;
                    }
                    attenuation = lbl_804B14C0[(s32)lbl_8052AAD0.curVolume];
                    mix = 0.7f * ((attenuation * *thpsrc) >> 15);
                    if (mix < -32768) {
                        mix = -32768;
                    }
                    if (mix > 32767) {
                        mix = 32767;
                    }
                    *dst = mix;
                    dst++;
                    thpsrc++;
                    mix = 0.7f * ((attenuation * *thpsrc) >> 15);
                    if (mix < -32768) {
                        mix = -32768;
                    }
                    if (mix > 32767) {
                        mix = 32767;
                    }
                    *dst = mix;
                    dst++;
                    thpsrc++;
                }
                requestSample -= sampleNum;
                lbl_8052AAD0.playAudioBuffer->validSample -= sampleNum;
                lbl_8052AAD0.playAudioBuffer->curPtr = thpsrc;
                if (lbl_8052AAD0.playAudioBuffer->validSample == 0) {
                    fn_8042E33C((u32)lbl_8052AAD0.playAudioBuffer);
                    lbl_8052AAD0.playAudioBuffer = 0;
                }
                if (!requestSample) {
                    break;
                }
            }
        }
    } else {
        memset(destination, 0, sample << 2);
    }
}

extern "C" void fn_80429BE4(u8* yImage, u8* uImage, u8* vImage, s16 x, s16 y, s16 textureWidth, s16 textureHeight, s16 polygonWidth, s16 polygonHeight) {
    GXTexObj tobj0;
    GXTexObj tobj1;
    GXTexObj tobj2;
    GXInitTexObj(&tobj0, yImage, textureWidth, textureHeight, GX_TF_I8, GX_CLAMP, GX_CLAMP, GX_FALSE);
    GXInitTexObjLOD(&tobj0, GX_NEAR, GX_NEAR, 0.0f, 0.0f, 0.0f, GX_FALSE, GX_FALSE, GX_ANISO_1);
    GXLoadTexObj(&tobj0, GX_TEXMAP0);
    GXInitTexObj(&tobj1, uImage, textureWidth >> 1, textureHeight >> 1, GX_TF_I8, GX_CLAMP, GX_CLAMP, GX_FALSE);
    GXInitTexObjLOD(&tobj1, GX_NEAR, GX_NEAR, 0.0f, 0.0f, 0.0f, GX_FALSE, GX_FALSE, GX_ANISO_1);
    GXLoadTexObj(&tobj1, GX_TEXMAP1);
    GXInitTexObj(&tobj2, vImage, textureWidth >> 1, textureHeight >> 1, GX_TF_I8, GX_CLAMP, GX_CLAMP, GX_FALSE);
    GXInitTexObjLOD(&tobj2, GX_NEAR, GX_NEAR, 0.0f, 0.0f, 0.0f, GX_FALSE, GX_FALSE, GX_ANISO_1);
    GXLoadTexObj(&tobj2, GX_TEXMAP2);
    GXBegin(GX_QUADS, GX_VTXFMT7, 4);
    s32 x0 = x;
    s32 y0 = y;
    fn_80429DF4(x0, y0, 0);
    fn_80429DE4(0, 0);
    s32 x1 = x0 + polygonWidth;
    fn_80429DF4(x1, y0, 0);
    fn_80429DE4(1, 0);
    s32 y1 = y0 + polygonHeight;
    fn_80429DF4(x1, y1, 0);
    fn_80429DE4(1, 1);
    fn_80429DF4(x0, y1, 0);
    fn_80429DE4(0, 1);
    fn_80429DE0();
}

extern "C" void fn_80429DE0() {}

#pragma dont_inline on
extern "C" void fn_80429DE4(s16 s, s16 t) {
    GXWGFifo.s16 = s;
    GXWGFifo.s16 = t;
}
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_80429DF4(s16 x, s16 y, s16 z) {
    GXWGFifo.s16 = x;
    GXWGFifo.s16 = y;
    GXWGFifo.s16 = z;
}
#pragma dont_inline off

extern "C" void fn_80429E08(GXRenderModeObj* rmode) {
    s32 scrWidth;
    s32 scrHeight;
    Mtx44 pMtx;
    Mtx mMtx;
    static const GXColorS10 color0 = {-90, 0, -114, 135};
    static const GXColor kcolor0 = {0x00, 0x00, 0xe2, 0x58};
    static const GXColor kcolor1 = {0xb3, 0x00, 0x00, 0xb6};
    static const GXColor kcolor2 = {0xff, 0x00, 0xff, 0x80};
    scrWidth = rmode->fbWidth;
    scrHeight = rmode->efbHeight;
    C_MTXOrtho(pMtx, 0.0f, scrHeight, 0.0f, scrWidth, 0.0f, -1.0f);
    GXSetProjection(pMtx, GX_ORTHOGRAPHIC);
    GXSetViewport(0.0f, 0.0f, scrWidth, scrHeight, 0.0f, 1.0f);
    GXSetScissor(0, 0, scrWidth, scrHeight);
    PSMTXIdentity(mMtx);
    GXLoadPosMtxImm(mMtx, GX_PNMTX0);
    GXSetCurrentMtx(GX_PNMTX0);
    GXSetZMode((GXBool)1, (GXCompare)7, (GXBool)0);
    GXSetBlendMode((GXBlendMode)0, (GXBlendFactor)1, (GXBlendFactor)0, (GXLogicOp)0);
    GXSetColorUpdate((GXBool)1);
    GXSetAlphaUpdate((GXBool)0);
    GXSetNumChans(0);
    GXSetNumTexGens(2);
    fn_8042A2A4((GXTexCoordID)0, GX_TG_MTX2x4, GX_TG_TEX0, GX_IDENTITY);
    fn_8042A2A4((GXTexCoordID)1, GX_TG_MTX2x4, GX_TG_TEX0, GX_IDENTITY);
    GXInvalidateTexAll();
    GXClearVtxDesc();
    GXSetVtxDesc((GXAttr)9, (GXAttrType)1);
    GXSetVtxDesc((GXAttr)13, (GXAttrType)1);
    GXSetVtxAttrFmt((GXVtxFmt)7, (GXAttr)9, (GXCompCnt)1, (GXCompType)3, 0);
    GXSetVtxAttrFmt((GXVtxFmt)7, (GXAttr)13, (GXCompCnt)1, (GXCompType)2, 0);
    GXSetNumTevStages(4);
    GXSetTevOrder((GXTevStageID)0, (GXTexCoordID)1, (GXTexMapID)1, (GXChannelID)255);
    GXSetTevColorIn((GXTevStageID)0, (GXTevColorArg)15, (GXTevColorArg)8, (GXTevColorArg)14, (GXTevColorArg)2);
    GXSetTevColorOp((GXTevStageID)0, (GXTevOp)0, (GXTevBias)0, (GXTevScale)0, (GXBool)0, (GXTevRegID)0);
    GXSetTevAlphaIn((GXTevStageID)0, (GXTevAlphaArg)7, (GXTevAlphaArg)4, (GXTevAlphaArg)6, (GXTevAlphaArg)1);
    GXSetTevAlphaOp((GXTevStageID)0, (GXTevOp)1, (GXTevBias)0, (GXTevScale)0, (GXBool)0, (GXTevRegID)0);
    GXSetTevKColorSel((GXTevStageID)0, (GXTevKColorSel)12);
    GXSetTevKAlphaSel((GXTevStageID)0, (GXTevKAlphaSel)28);
    GXSetTevSwapMode((GXTevStageID)0, (GXTevSwapSel)0, (GXTevSwapSel)0);
    GXSetTevOrder((GXTevStageID)1, (GXTexCoordID)1, (GXTexMapID)2, (GXChannelID)255);
    GXSetTevColorIn((GXTevStageID)1, (GXTevColorArg)15, (GXTevColorArg)8, (GXTevColorArg)14, (GXTevColorArg)0);
    GXSetTevColorOp((GXTevStageID)1, (GXTevOp)0, (GXTevBias)0, (GXTevScale)1, (GXBool)0, (GXTevRegID)0);
    GXSetTevAlphaIn((GXTevStageID)1, (GXTevAlphaArg)7, (GXTevAlphaArg)4, (GXTevAlphaArg)6, (GXTevAlphaArg)0);
    GXSetTevAlphaOp((GXTevStageID)1, (GXTevOp)1, (GXTevBias)0, (GXTevScale)0, (GXBool)0, (GXTevRegID)0);
    GXSetTevKColorSel((GXTevStageID)1, (GXTevKColorSel)13);
    GXSetTevKAlphaSel((GXTevStageID)1, (GXTevKAlphaSel)29);
    GXSetTevSwapMode((GXTevStageID)1, (GXTevSwapSel)0, (GXTevSwapSel)0);
    GXSetTevOrder((GXTevStageID)2, (GXTexCoordID)0, (GXTexMapID)0, (GXChannelID)255);
    GXSetTevColorIn((GXTevStageID)2, (GXTevColorArg)15, (GXTevColorArg)8, (GXTevColorArg)12, (GXTevColorArg)0);
    GXSetTevColorOp((GXTevStageID)2, (GXTevOp)0, (GXTevBias)0, (GXTevScale)0, (GXBool)1, (GXTevRegID)0);
    GXSetTevAlphaIn((GXTevStageID)2, (GXTevAlphaArg)4, (GXTevAlphaArg)7, (GXTevAlphaArg)7, (GXTevAlphaArg)0);
    GXSetTevAlphaOp((GXTevStageID)2, (GXTevOp)0, (GXTevBias)0, (GXTevScale)0, (GXBool)1, (GXTevRegID)0);
    GXSetTevSwapMode((GXTevStageID)2, (GXTevSwapSel)0, (GXTevSwapSel)0);
    GXSetTevOrder((GXTevStageID)3, (GXTexCoordID)255, (GXTexMapID)255, (GXChannelID)255);
    GXSetTevColorIn((GXTevStageID)3, (GXTevColorArg)1, (GXTevColorArg)0, (GXTevColorArg)14, (GXTevColorArg)15);
    GXSetTevColorOp((GXTevStageID)3, (GXTevOp)0, (GXTevBias)0, (GXTevScale)0, (GXBool)1, (GXTevRegID)0);
    GXSetTevAlphaIn((GXTevStageID)3, (GXTevAlphaArg)7, (GXTevAlphaArg)7, (GXTevAlphaArg)7, (GXTevAlphaArg)7);
    GXSetTevAlphaOp((GXTevStageID)3, (GXTevOp)0, (GXTevBias)0, (GXTevScale)0, (GXBool)1, (GXTevRegID)0);
    GXSetTevSwapMode((GXTevStageID)3, (GXTevSwapSel)0, (GXTevSwapSel)0);
    GXSetTevKColorSel((GXTevStageID)3, (GXTevKColorSel)14);
    GXSetTevColorS10(GX_TEVREG0, color0);
    GXSetTevKColor((GXTevKColorID)0, kcolor0);
    GXSetTevKColor((GXTevKColorID)1, kcolor1);
    GXSetTevKColor((GXTevKColorID)2, kcolor2);
    GXSetTevSwapModeTable((GXTevSwapSel)0, (GXTevColorChan)0, (GXTevColorChan)1, (GXTevColorChan)2, (GXTevColorChan)3);
}

#pragma dont_inline on
extern "C" void fn_8042A2A4(GXTexCoordID dst, GXTexGenType func, GXTexGenSrc src, u32 mtx) {
    GXSetTexCoordGen2(dst, func, src, mtx, GX_FALSE, GX_PTIDENTITY);
}
#pragma dont_inline off

extern "C" void fn_8042A2CC() {
    GXSetZMode((GXBool)1, (GXCompare)7, (GXBool)0);
    GXSetBlendMode((GXBlendMode)0, (GXBlendFactor)1, (GXBlendFactor)0, (GXLogicOp)15);
    GXSetNumTexGens(1);
    GXSetNumChans(0);
    GXSetNumTevStages(1);
    GXSetTevOrder((GXTevStageID)0, (GXTexCoordID)0, (GXTexMapID)0, (GXChannelID)255);
    GXSetTevOp((GXTevStageID)0, (GXTevMode)3);
    GXSetTevSwapMode((GXTevStageID)0, (GXTevSwapSel)0, (GXTevSwapSel)0);
    GXSetTevSwapMode((GXTevStageID)1, (GXTevSwapSel)0, (GXTevSwapSel)0);
    GXSetTevSwapMode((GXTevStageID)2, (GXTevSwapSel)0, (GXTevSwapSel)0);
    GXSetTevSwapMode((GXTevStageID)3, (GXTevSwapSel)0, (GXTevSwapSel)0);
    GXSetTevSwapModeTable((GXTevSwapSel)0, (GXTevColorChan)0, (GXTevColorChan)1, (GXTevColorChan)2, (GXTevColorChan)3);
    GXSetTevSwapModeTable((GXTevSwapSel)1, (GXTevColorChan)0, (GXTevColorChan)0, (GXTevColorChan)0, (GXTevColorChan)3);
    GXSetTevSwapModeTable((GXTevSwapSel)2, (GXTevColorChan)1, (GXTevColorChan)1, (GXTevColorChan)1, (GXTevColorChan)3);
    GXSetTevSwapModeTable((GXTevSwapSel)3, (GXTevColorChan)2, (GXTevColorChan)2, (GXTevColorChan)2, (GXTevColorChan)3);
}

extern "C" void fn_8042A3E4(AudioThreadObj* t) {
    if (t->created) {
        OSCancelThread(&t->thread);
        t->created = 0;
    }
}

extern "C" void fn_8042A428(AudioThreadObj* t) {
    if (t->created) {
        OSResumeThread(&t->thread);
    }
}

extern "C" u8 fn_8042A458(AudioThreadObj* t, s32 priority, void* param) {
    if (param) {
        if (!OSCreateThread(&t->thread, (void* (*)(void*))fn_8042E514, param, t->stack + sizeof(t->stack), sizeof(t->stack), priority, 1)) {
            return 0;
        }
    } else {
        if (!OSCreateThread(&t->thread, (void* (*)(void*))fn_8042E4EC, 0, t->stack + sizeof(t->stack), sizeof(t->stack), priority, 1)) {
            return 0;
        }
    }
    OSInitMessageQueue(&t->freeQueue, t->freeMessages, 3);
    OSInitMessageQueue(&t->decodedQueue, t->decodedMessages, 3);
    t->created = 1;
    return 1;
}

extern u32 lbl_8053AE68;
extern u32 lbl_8053AE6C;
extern "C" void fn_8042A534(AudioThreadObj* t, u8* bufPtr) {
    THPReadBuffer readBuffer;
    s32 tmp;
    s32 readSize;
    s32 i;
    u32 frame;
    readBuffer.ptr = bufPtr;
    readSize = lbl_8052AAD0.initReadSize;
    i = 0;
    while (true) {
        readBuffer.frameNumber = i;
        fn_8042E53C(&readBuffer);
        frame = i + lbl_8052AAD0.initReadFrame;
        if (frame % lbl_8052AAD0.header.numFrames == lbl_8052AAD0.header.numFrames - 1) {
            if (lbl_8052AAD0.playFlag & 1) {
                readSize = *(s32*)readBuffer.ptr;
                readBuffer.ptr = lbl_8052AAD0.movieData;
            } else {
                OSSuspendThread(&t->thread);
            }
        } else {
            tmp = *(s32*)readBuffer.ptr;
            readBuffer.ptr += readSize;
            readSize = tmp;
        }
        i++;
    }
}

extern "C" void fn_8042A5E0(AudioThreadObj* t, u32) {
    u32 readBuffer;
    while (true) {
        readBuffer = fn_8042E58C();
        fn_8042E53C((THPReadBuffer*)readBuffer);
        fn_8042E564(readBuffer);
    }
}

extern "C" void fn_8042A608(AudioThreadObj* t, THPReadBuffer* readBuffer) {
    THPAudioBuffer* audioBuffer;
    u32 i;
    u32* compSizePtr;
    u8* ptr;
    compSizePtr = (u32*)(readBuffer->ptr + 8);
    ptr = readBuffer->ptr + lbl_8052AAD0.compInfo.numComponents * 4 + 8;
    audioBuffer = (THPAudioBuffer*)fn_8042E5D8();
    for (i = 0; i < lbl_8052AAD0.compInfo.numComponents; i++) {
        switch (lbl_8052AAD0.compInfo.frameComp[i]) {
        case 1:
            audioBuffer->validSample = fn_8042DD54(audioBuffer->buffer, ptr + *compSizePtr * lbl_8052AAD0.curAudioTrack, 0);
            audioBuffer->curPtr = audioBuffer->buffer;
            fn_8042E5B0((u32)audioBuffer);
            return;
        }
        ptr += *compSizePtr;
        compSizePtr++;
    }
}

extern "C" void fn_8042A6DC(AudioThreadObj* t, OSMessage msg) {
    OSSendMessage(&t->decodedQueue, msg, 1);
}

extern "C" void* fn_8042A708(AudioThreadObj* t, s32 flag) {
    OSMessage msg;
    if (OSReceiveMessage(&t->decodedQueue, &msg, flag) == 1) {
        return msg;
    }
    return 0;
}

extern "C" void fn_8042A74C(AudioThreadObj* t, OSMessage msg) {
    OSSendMessage(&t->freeQueue, msg, 0);
}

extern "C" u32 fn_8042A778(AudioThreadObj* t) {
    OSMessage msg;
    OSReceiveMessage(&t->freeQueue, &msg, 1);
    return (u32)msg;
}

extern "C" AudioThreadObj* fn_8042A7AC(AudioThreadObj* t, s16 flag) {
    if (t) {
        t->vtbl = lbl_804B15DC;
        lbl_8053AE84 = 0;
        if (flag > 0) {
            __dl__FPv(t);
        }
    }
    return t;
}

extern "C" void fn_8042A7FC(AudioThreadObj* t) {
    t->vtbl = lbl_804B15DC;
    lbl_8053AE84 = t;
    t->created = 0;
}

extern "C" void fn_8042A818(VideoThreadObj* t) {
    if (t->created) {
        OSCancelThread(&t->thread);
        t->created = 0;
    }
}

extern "C" void fn_8042A85C(VideoThreadObj* t) {
    if (t->created) {
        OSResumeThread(&t->thread);
    }
}

extern "C" u8 fn_8042A88C(VideoThreadObj* t, s32 priority, void* param) {
    if (param) {
        if (!OSCreateThread(&t->thread, (void* (*)(void*))fn_8042E624, param, t->stack + sizeof(t->stack), sizeof(t->stack), priority, 1)) {
            return 0;
        }
    } else {
        if (!OSCreateThread(&t->thread, (void* (*)(void*))fn_8042E5FC, 0, t->stack + sizeof(t->stack), sizeof(t->stack), priority, 1)) {
            return 0;
        }
    }
    OSInitMessageQueue(&t->freeQueue, t->freeMessages, 3);
    OSInitMessageQueue(&t->decodedQueue, t->decodedMessages, 3);
    t->created = 1;
    t->first = 1;
    return 1;
}

extern "C" void fn_8042A970(VideoThreadObj* t, u8* bufPtr) {
    THPReadBuffer readBuffer;
    s32 tmp;
    s32 readSize;
    s32 frame;
    BOOL old;
    readBuffer.ptr = bufPtr;
    readSize = lbl_8052AAD0.initReadSize;
    frame = 0;
    while (true) {
        if (lbl_8052AAD0.audioExist) {
            while (lbl_8052AAD0.mD8 < 0) {
                old = OSDisableInterrupts();
                lbl_8052AAD0.mD8++;
                OSRestoreInterrupts(old);
                if ((frame + lbl_8052AAD0.initReadFrame) % lbl_8052AAD0.header.numFrames == lbl_8052AAD0.header.numFrames - 1) {
                    if (lbl_8052AAD0.playFlag & 1) {
                        readSize = *(s32*)readBuffer.ptr;
                        readBuffer.ptr = lbl_8052AAD0.movieData;
                    } else {
                        break;
                    }
                } else {
                    tmp = *(s32*)readBuffer.ptr;
                    readBuffer.ptr += readSize;
                    readSize = tmp;
                }
                frame++;
            }
        }
        readBuffer.frameNumber = frame;
        fn_8042E64C(&readBuffer);
        if ((frame + lbl_8052AAD0.initReadFrame) % lbl_8052AAD0.header.numFrames == lbl_8052AAD0.header.numFrames - 1) {
            if (lbl_8052AAD0.playFlag & 1) {
                readSize = *(s32*)readBuffer.ptr;
                readBuffer.ptr = lbl_8052AAD0.movieData;
            } else {
                OSSuspendThread(&t->thread);
            }
        } else {
            tmp = *(s32*)readBuffer.ptr;
            readBuffer.ptr += readSize;
            readSize = tmp;
        }
        frame++;
    }
}

extern "C" void fn_8042AAA8(VideoThreadObj* t, u32) {
    THPReadBuffer* readBuffer;
    BOOL old;
    while (true) {
        if (lbl_8052AAD0.audioExist) {
            while (lbl_8052AAD0.mD8 < 0) {
                readBuffer = (THPReadBuffer*)fn_8042E674();
                if ((lbl_8052AAD0.initReadFrame + readBuffer->frameNumber) % lbl_8052AAD0.header.numFrames == lbl_8052AAD0.header.numFrames - 1 &&
                    !(lbl_8052AAD0.playFlag & 1)) {
                    fn_8042E64C(readBuffer);
                }
                fn_8042E4C4(readBuffer);
                old = OSDisableInterrupts();
                lbl_8052AAD0.mD8++;
                OSRestoreInterrupts(old);
            }
        }
        if (lbl_8052AAD0.audioExist) {
            readBuffer = (THPReadBuffer*)fn_8042E674();
        } else {
            readBuffer = (THPReadBuffer*)fn_8042E58C();
        }
        fn_8042E64C(readBuffer);
        fn_8042E4C4(readBuffer);
    }
}

extern "C" void fn_8042AB70(VideoThreadObj* t, THPReadBuffer* readBuffer) {
    THPTextureSet* textureSet;
    u32 i;
    u32* compSizePtr;
    u8* ptr;
    BOOL old;
    compSizePtr = (u32*)(readBuffer->ptr + 8);
    ptr = readBuffer->ptr + lbl_8052AAD0.compInfo.numComponents * 4 + 8;
    textureSet = (THPTextureSet*)fn_8042E6C0();
    for (i = 0; i < lbl_8052AAD0.compInfo.numComponents; i++) {
        switch (lbl_8052AAD0.compInfo.frameComp[i]) {
        case 0:
            if ((lbl_8052AAD0.videoError = fn_8042DA54(ptr, textureSet->ytexture, textureSet->utexture, textureSet->vtexture, lbl_8052AAD0.mBufEnd)) != 0) {
                if (t->first) {
                    fn_80428C38(0);
                    t->first = 0;
                }
                OSSuspendThread(&t->thread);
            }
            textureSet->frameNumber = readBuffer->frameNumber;
            fn_8042E698((u32)textureSet);
            old = OSDisableInterrupts();
            lbl_8052AAD0.mD8++;
            OSRestoreInterrupts(old);
        }
        ptr += *compSizePtr;
        compSizePtr++;
    }
    if (t->first) {
        fn_80428C38(1);
        t->first = 0;
    }
}

extern "C" void fn_8042ACA0(VideoThreadObj* t, OSMessage msg) {
    OSSendMessage(&t->decodedQueue, msg, 1);
}

extern "C" void* fn_8042ACCC(VideoThreadObj* t, s32 flag) {
    OSMessage msg;
    if (OSReceiveMessage(&t->decodedQueue, &msg, flag) == 1) {
        return msg;
    }
    return 0;
}

extern "C" void fn_8042AD10(VideoThreadObj* t, OSMessage msg) {
    OSSendMessage(&t->freeQueue, msg, 0);
}

extern "C" u32 fn_8042AD3C(VideoThreadObj* t) {
    OSMessage msg;
    OSReceiveMessage(&t->freeQueue, &msg, 1);
    return (u32)msg;
}

extern "C" VideoThreadObj* fn_8042AD70(VideoThreadObj* t, s16 flag) {
    if (t) {
        t->vtbl = lbl_804B15E8;
        lbl_8053AE80 = 0;
        if (flag > 0) {
            __dl__FPv(t);
        }
    }
    return t;
}

extern "C" void fn_8042ADC0(VideoThreadObj* t) {
    t->vtbl = lbl_804B15E8;
    lbl_8053AE80 = t;
    t->created = 0;
}

extern "C" u8 fn_8042ADDC(ReadThreadObj* t, s32 priority) {
    if (!OSCreateThread(&t->thread, (void* (*)(void*))fn_8042E6E4, 0, t->stack + sizeof(t->stack), sizeof(t->stack), priority, 1)) {
        return 0;
    }
    OSInitMessageQueue(&t->freeQueue, t->freeMessages, 10);
    OSInitMessageQueue(&t->readQueue, t->readMessages, 10);
    OSInitMessageQueue(&t->readQueue2, t->readMessages2, 10);
    t->created = 1;
    return 1;
}

extern "C" void fn_8042AE74(ReadThreadObj* t, u32) {
    THPReadBuffer* readBuffer;
    s32 offset;
    s32 size;
    s32 readFrame;
    s32 result;
    readFrame = 0;
    offset = lbl_8052AAD0.initOffset;
    size = lbl_8052AAD0.initReadSize;
    while (true) {
        readBuffer = (THPReadBuffer*)fn_8042E734();
        result = DVDReadPrio(&lbl_8052AAD0.fileInfo, readBuffer->ptr, size, offset, 2);
        if (result != size) {
            if (result == -1) {
                lbl_8052AAD0.dvdError = -1;
            }
            if (readFrame == 0) {
                fn_80428C38(0);
            }
            OSSuspendThread(&t->thread);
        }
        readBuffer->frameNumber = readFrame;
        fn_8042E70C((u32)readBuffer);
        offset += size;
        size = fn_8042AF54(readBuffer);
        if ((readFrame + lbl_8052AAD0.initReadFrame) % lbl_8052AAD0.header.numFrames == lbl_8052AAD0.header.numFrames - 1) {
            if (lbl_8052AAD0.playFlag & 1) {
                offset = lbl_8052AAD0.header.movieDataOffsets;
            } else {
                OSSuspendThread(&t->thread);
            }
        }
        readFrame++;
    }
}

extern "C" s32 fn_8042AF54(THPReadBuffer* readBuffer) {
    return *(s32*)readBuffer->ptr;
}

extern "C" void fn_8042AF60(ReadThreadObj* t) {
    if (t->created) {
        OSCancelThread(&t->thread);
        t->created = 0;
    }
}

extern "C" void fn_8042AFA4(ReadThreadObj* t) {
    if (t->created) {
        OSResumeThread(&t->thread);
    }
}

extern "C" void fn_8042AFD4(ReadThreadObj* t, OSMessage msg) {
    OSSendMessage(&t->readQueue2, msg, 1);
}

extern "C" u32 fn_8042AFFC(ReadThreadObj* t) {
    OSMessage msg;
    OSReceiveMessage(&t->readQueue2, &msg, 1);
    return (u32)msg;
}

extern "C" void fn_8042B02C(ReadThreadObj* t, OSMessage msg) {
    OSSendMessage(&t->freeQueue, msg, 1);
}

extern "C" u32 fn_8042B054(ReadThreadObj* t) {
    OSMessage msg;
    OSReceiveMessage(&t->freeQueue, &msg, 1);
    return (u32)msg;
}

extern "C" void fn_8042B084(ReadThreadObj* t, OSMessage msg) {
    OSSendMessage(&t->readQueue, msg, 1);
}

extern "C" u32 fn_8042B0AC(ReadThreadObj* t) {
    OSMessage msg;
    OSReceiveMessage(&t->readQueue, &msg, 1);
    return (u32)msg;
}

extern "C" ReadThreadObj* fn_8042B0DC(ReadThreadObj* t, s16 flag) {
    if (t) {
        t->vtbl = lbl_804B15F4;
        lbl_8053AE7C = 0;
        if (flag > 0) {
            __dl__FPv(t);
        }
    }
    return t;
}

extern "C" void fn_8042B12C(ReadThreadObj* t) {
    t->vtbl = lbl_804B15F4;
    lbl_8053AE7C = t;
    t->created = 0;
}

extern "C" u8 fn_8042B148() {
    u32 base = 0xE0000000;
    lbl_8052AAA0[0] = base;
    lbl_8052AAA0[1] = base + 0x2000;
    lbl_8052AAA0[2] = base + 0x2800;
    lbl_8052AAAC[0] = base;
    lbl_8052AAAC[1] = base + 0x2800;
    lbl_8052AAAC[2] = base + 0x3200;
    fn_8042B1A8();
    lbl_8053AE78 = 1;
    return 1;
}

extern "C" void fn_8042BD84(u8* info, s16* block) {
    s32 t;
    s16 dc;
    s16 diff;

    __dcbz(block, 0);
    t = fn_8042BF54(info, lbl_8053AE28);
    __dcbz(block, 32);
    diff = 0;
    __dcbz(block, 64);

    if (t) {
        s32 cnt = *(s32*)(info + 0x6a4);
        s32 tmp = 33 - cnt;
        s32 sh = cnt - 1;
        u32 cw = *(u32*)(info + 0x6a0);
        s32 v = t - tmp;
        u32 code;
        if (v <= 0) {
            code = cw << sh;
            *(s32*)(info + 0x6a4) = cnt + t;
            code >>= 32 - t;
        } else {
            u32* p;
            code = cw << sh;
            p = *(u32**)(info + 0x69c);
            cw = *++p;
            *(u32*)(info + 0x6a0) = cw;
            code += cw >> tmp;
            *(u32**)(info + 0x69c) = p;
            *(s32*)(info + 0x6a4) = v + 1;
            code >>= 32 - t;
        }
        diff = code;
        if (__cntlzw(diff) > 32 - t) {
            diff = (-1 << t) + code + 1;
        }
    }

    __dcbz(block, 96);
    {
        s32 k = 1;
        dc = *(s16*)(info + 0x690) + diff;
        *(s16*)(info + 0x690) = dc;
        block[0] = dc;

        for (; k < 64; k++) {
            s32 size;
            s32 run;
            t = fn_8042BF54(info, lbl_8053AE34);
            size = t & 15;
            run = t >> 4;
            if (size) {
                s32 cnt;
                s32 tmp;
                s32 sh;
                u32 cw;
                s32 v;
                u32 code;
                s32 value;
                k += run;
                cnt = *(s32*)(info + 0x6a4);
                tmp = 33 - cnt;
                sh = cnt - 1;
                cw = *(u32*)(info + 0x6a0);
                v = size - tmp;
                if (v <= 0) {
                    code = cw << sh;
                    *(s32*)(info + 0x6a4) = cnt + size;
                    code >>= 32 - size;
                } else {
                    u32* p;
                    code = cw << sh;
                    p = *(u32**)(info + 0x69c);
                    cw = *++p;
                    *(u32*)(info + 0x6a0) = cw;
                    code += cw >> tmp;
                    *(u32**)(info + 0x69c) = p;
                    *(s32*)(info + 0x6a4) = v + 1;
                    code >>= 32 - size;
                }
                value = code;
                if (__cntlzw(value) > 32 - size) {
                    value = (-1 << size) + code + 1;
                }
                block[lbl_8048F270[k]] = value;
            } else {
                if (run != 15) {
                    break;
                }
                k += 15;
            }
        }
    }
}

extern void* lbl_8053AE24;
extern void* lbl_8053AE30;
extern u8 lbl_8048F270[64];
extern "C" s32 fn_8042BF54(u8* info, void* h);
extern "C" void fn_8042C1CC(u8* info, s16* block) {
    s32 t;
    s16 dc;
    s16 diff;

    __dcbz(block, 0);
    t = fn_8042BF54(info, lbl_8053AE24);
    __dcbz(block, 32);
    diff = 0;
    __dcbz(block, 64);

    if (t) {
        s32 cnt = *(s32*)(info + 0x6a4);
        s32 tmp = 33 - cnt;
        u32 cw = *(u32*)(info + 0x6a0);
        s32 v = t - tmp;
        u32 code;
        if (v <= 0) {
            *(s32*)(info + 0x6a4) = cnt + t;
            code = (cw << (cnt - 1)) >> (32 - t);
        } else {
            u32* p;
            code = cw << (cnt - 1);
            p = *(u32**)(info + 0x69c);
            cw = *++p;
            *(u32*)(info + 0x6a0) = cw;
            code += cw >> tmp;
            *(u32**)(info + 0x69c) = p;
            *(s32*)(info + 0x6a4) = v + 1;
            code >>= 32 - t;
        }
        diff = code;
        if (__cntlzw(diff) > 32 - t) {
            diff = code + (-1 << t) + 1;
        }
    }

    __dcbz(block, 96);
    {
        s32 k = 1;
        dc = *(s16*)(info + 0x68a) + diff;
        *(s16*)(info + 0x68a) = dc;
        block[0] = dc;

        for (; k < 64; k++) {
            s32 size;
            s32 run;
            t = fn_8042BF54(info, lbl_8053AE30);
            size = t & 15;
            run = t >> 4;
            if (size) {
                s32 cnt;
                s32 tmp;
                u32 cw;
                s32 v;
                u32 code;
                k += run;
                cnt = *(s32*)(info + 0x6a4);
                tmp = 33 - cnt;
                cw = *(u32*)(info + 0x6a0);
                v = size - tmp;
                if (v <= 0) {
                    *(s32*)(info + 0x6a4) = cnt + size;
                    code = (cw << (cnt - 1)) >> (32 - size);
                } else {
                    u32* p;
                    code = cw << (cnt - 1);
                    p = *(u32**)(info + 0x69c);
                    cw = *++p;
                    *(u32*)(info + 0x6a0) = cw;
                    code += cw >> tmp;
                    *(u32**)(info + 0x69c) = p;
                    *(s32*)(info + 0x6a4) = v + 1;
                    code >>= 32 - size;
                }
                if (__cntlzw(code) > 32 - size) {
                    code += (-1 << size) + 1;
                }
                block[lbl_8048F270[k]] = code;
            } else {
                if (run != 15) {
                    break;
                }
                k += 15;
            }
        }
    }
}

extern "C" void fn_8042CC50(u32 param_1, u32 param_2, u32 param_3)
{
    u16 uVar2;
    u16 uVar1;

    *(u32*)(lbl_8053AE74 + 0x6b0) = param_1;
    *(u32*)(lbl_8053AE74 + 0x6b4) = param_2;
    *(u32*)(lbl_8053AE74 + 0x6b8) = param_3;
    uVar2 = *(u16*)(lbl_8053AE74 + 0x698);
    uVar1 = *(u16*)(lbl_8053AE74 + 0x694);
    fn_8042CD38();
    fn_8042CD64();
    if (*(u16*)(lbl_8053AE74 + 0x692) == 0x200 && uVar1 == 0x1c0) {
        for (; uVar2 < uVar1; uVar2 += 0x10) {
            fn_8042C9F8();
        }
    } else if (*(u16*)(lbl_8053AE74 + 0x692) == 0x280 && uVar1 == 0x1e0) {
        for (; uVar2 < uVar1; uVar2 += 0x10) {
            fn_8042C79C();
        }
    } else {
        for (; uVar2 < uVar1; uVar2 += 0x10) {
            fn_8042B1DC();
        }
    }
    fn_8042CD24();
}

extern u8* lbl_8053AE74;

// ---- THP decoder (SDK THPDec.c, functions laid out in reverse) ----
typedef f32 THPQuantTab[64];
struct THPHuffmanTab {
    u8 quick[32];
    u8 increment[32];
    u8* Vij;
    s32 maxCode[18];
    s32 valPtr[18];
    u8 Vij1;
    u8 pad[11];
};
struct THPComponent {
    u8 quantizationTableSelector;
    u8 DCTableSelector;
    u8 ACTableSelector;
    s16 predDC;
};
struct THPFileInfo {
    THPQuantTab quantTabs[3];
    THPHuffmanTab huffmanTabs[4];
    THPComponent components[3];
    u16 xPixelSize;
    u16 yPixelSize;
    u16 MCUsPerRow;
    u16 decompressedY;
    u8* file;
    u32 currByte;
    u32 cnt;
    u8 validHuffmanTabs;
    u8 RST;
    u16 nMCU;
    u16 currMCU;
    u8* dLC[3];
};
#define __THPInfo ((THPFileInfo*)lbl_8053AE74)
#define __THPHuffmanBits lbl_8053AE38
extern u8* lbl_8053AE38;

#pragma dont_inline on
extern "C" void fn_8042CF9C() {
    lbl_8053AE74[0x6a9] = 1;
    *(u8**)(lbl_8053AE74 + 0x69c) += 2;
    *(u16*)(lbl_8053AE74 + 0x6aa) = (*(u8**)(lbl_8053AE74 + 0x69c))[0] << 8 | (*(u8**)(lbl_8053AE74 + 0x69c))[1];
    *(u8**)(lbl_8053AE74 + 0x69c) += 2;
    *(u16*)(lbl_8053AE74 + 0x6ac) = *(u16*)(lbl_8053AE74 + 0x6aa);
}

extern u8* lbl_8053AE3C;
extern u16* lbl_8053AE40;
extern "C" void fn_8042CFF0(u8 tabIndex) {
    s32 p, l;
    THPHuffmanTab* h;

    p = 0;
    h = &__THPInfo->huffmanTabs[tabIndex];
    for (l = 1; l <= 16; l++) {
        if (__THPHuffmanBits[l - 1]) {
            h->valPtr[l] = p - lbl_8053AE40[p];
            p += __THPHuffmanBits[l - 1];
            h->maxCode[l] = lbl_8053AE40[p - 1];
        } else {
            h->maxCode[l] = -1;
            h->valPtr[l] = -1;
        }
    }
    h->maxCode[17] = 0xfffffL;
}

extern "C" void fn_8042D0E0() {
    u8 len;
    u16 i;
    u16 code;
    i = 0;
    code = 0;
    len = lbl_8053AE3C[0];
    while (lbl_8053AE3C[i] != 0) {
        while (lbl_8053AE3C[i] == len) {
            lbl_8053AE40[i++] = code++;
        }
        code <<= 1;
        len++;
    }
}

extern "C" void fn_8042D144() {
    s32 p, l, i;
    p = 0;
    for (l = 1; l <= 16; l++) {
        i = (s32)__THPHuffmanBits[l - 1];
        while (i--) {
            lbl_8053AE3C[p++] = (u8)l;
        }
    }
    lbl_8053AE3C[p] = 0;
}

extern "C" void fn_8042CFF0(u8 tabIndex);
extern "C" void fn_8042D0E0();
extern "C" void fn_8042D144();
extern u32 lbl_8053AE70;

extern "C" u8 fn_8042D20C() {
    u8 t_class, id, i, tab_index;
    u16 length, num_Vij;

    lbl_8053AE3C = (u8*)lbl_8053AE70;
    lbl_8053AE40 = (u16*)(lbl_8053AE70 + 256 + 1);
    length = (u16)((__THPInfo->file)[0] << 8 | (__THPInfo->file)[1]);
    __THPInfo->file += 2;
    length -= 2;

    for (;;) {
        i = (*(__THPInfo->file)++);
        id = (u8)(i & 15);
        t_class = (u8)(i >> 4);
        __THPHuffmanBits = __THPInfo->file;
        tab_index = (u8)((id << 1) + t_class);
        num_Vij = 0;

        for (i = 0; i < 16; i++) {
            num_Vij += (*(__THPInfo->file)++);
        }

        __THPInfo->huffmanTabs[tab_index].Vij = __THPInfo->file;
        __THPInfo->file += num_Vij;
        fn_8042D144();
        fn_8042D0E0();
        fn_8042CFF0(tab_index);
        __THPInfo->validHuffmanTabs |= 1 << tab_index;
        length -= 17 + num_Vij;

        if (length == 0) {
            break;
        }
    }
    return 0;
}

static const u8 __THPJpegNaturalOrder[80] = {
    0,  1,  8,  16, 9,  2,  3,  10, 17, 24, 32, 25, 18, 11, 4,  5,  12, 19, 26, 33, 40, 48, 41, 34, 27, 20, 13,
    6,  7,  14, 21, 28, 35, 42, 49, 56, 57, 50, 43, 36, 29, 22, 15, 23, 30, 37, 44, 51, 58, 59, 52, 45, 38, 31,
    39, 46, 53, 60, 61, 54, 47, 55, 62, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63, 63 };

static const f64 __THPAANScaleFactor[8] = {
    1.0f, 1.387039845f, 1.306562965f, 1.175875602f, 1.0f, 0.785694958f, 0.541196100f, 0.275899379f,
};

extern "C" u8 fn_8042D3E4() {
    u16 length, id, i, row, col;
    f32 q_temp[64];

    length = (u16)((__THPInfo->file)[0] << 8 | (__THPInfo->file)[1]);
    __THPInfo->file += 2;
    length -= 2;

    for (;;) {
        id = (*(__THPInfo->file)++);

        for (i = 0; i < 64; i++) {
            q_temp[__THPJpegNaturalOrder[i]] = (f32)(*(__THPInfo->file)++);
        }

        i = 0;
        for (row = 0; row < 8; row++) {
            for (col = 0; col < 8; col++) {
                __THPInfo->quantTabs[id][i] = (f32)((f64)q_temp[i] * __THPAANScaleFactor[row] * __THPAANScaleFactor[col]);
                i++;
            }
        }

        length -= 65;
        if (!length) {
            break;
        }
    }
    return 0;
}

extern "C" u8 fn_8042D7B8() {
    u8 i, utmp8;
    __THPInfo->file += 2;

    utmp8 = (*(__THPInfo->file)++);

    if (utmp8 != 3) {
        return 12;
    }

    for (i = 0; i < 3; i++) {
        utmp8 = (*(__THPInfo->file)++);

        utmp8 = (*(__THPInfo->file)++);
        __THPInfo->components[i].DCTableSelector = (u8)(utmp8 >> 4);
        __THPInfo->components[i].ACTableSelector = (u8)(utmp8 & 15);

        if ((__THPInfo->validHuffmanTabs & (1 << ((utmp8 >> 4)))) == 0) {
            return 15;
        }

        if ((__THPInfo->validHuffmanTabs & (1 << ((utmp8 & 15) + 1))) == 0) {
            return 15;
        }
    }

    __THPInfo->file += 3;
    __THPInfo->MCUsPerRow = (u16)((__THPInfo->xPixelSize + 15) / 16);
    __THPInfo->components[0].predDC = 0;
    __THPInfo->components[1].predDC = 0;
    __THPInfo->components[2].predDC = 0;
    return 0;
}

extern "C" u8 fn_8042D8D4() {
    u8 i, utmp8;

    __THPInfo->file += 2;

    utmp8 = (*(__THPInfo->file)++);

    if (utmp8 != 8) {
        return 10;
    }

    __THPInfo->yPixelSize = (u16)((__THPInfo->file)[0] << 8 | (__THPInfo->file)[1]);
    __THPInfo->file += 2;
    __THPInfo->xPixelSize = (u16)((__THPInfo->file)[0] << 8 | (__THPInfo->file)[1]);
    __THPInfo->file += 2;

    utmp8 = (*(__THPInfo->file)++);
    if (utmp8 != 3) {
        return 12;
    }

    for (i = 0; i < 3; i++) {
        utmp8 = (*(__THPInfo->file)++);
        utmp8 = (*(__THPInfo->file)++);
        if ((i == 0 && utmp8 != 0x22) || (i > 0 && utmp8 != 0x11)) {
            return 19;
        }

        __THPInfo->components[i].quantizationTableSelector = (*(__THPInfo->file)++);
    }
    return 0;
}

extern "C" void fn_8042DA10() {
    u32 p = (lbl_8053AE70 + 0x1f) & ~0x1f;
    lbl_8052AAB8[0] = p;
    lbl_8052AAB8[1] = p + 0x80;
    lbl_8052AAB8[2] = p + 0x100;
    lbl_8052AAB8[3] = p + 0x180;
    lbl_8052AAB8[4] = p + 0x200;
    lbl_8052AAB8[5] = p + 0x280;
}

struct BitReader { u8* p; s32 w4; u8 b8; u8 b9; };
extern "C" void fn_8042DC88(BitReader* r, u8* p) {
    r->p = p;
    r->w4 = 2;
    r->b8 = (*r->p >> 4) & 7;
    r->b9 = *r->p & 0xf;
    r->p++;
}

extern "C" s32 fn_8042DCC4(BitReader* r) {
    s32 v;
    if ((r->w4 & 0xf) == 0) {
        r->b8 = (*r->p >> 4) & 7;
        r->b9 = *r->p & 0xf;
        r->p++;
        r->w4 += 2;
    }
    if (r->w4 & 1) {
        v = (s32)(*r->p << 28) >> 28;
        r->p++;
    } else {
        v = (s32)((*r->p & 0xf0) << 24) >> 28;
    }
    r->w4++;
    return v;
}

extern "C" void fn_8042E1E4(Obj8042E1E4* o, u16 v) { o->m1C = v; o->m20 = 0; }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void* fn_8042E1F4() { return sManager__10JFWDisplay; }
#pragma dont_inline off

#pragma dont_inline on
extern "C" u16 fn_8042E1FC(Obj8042E1E4* o) { return o->m1C; }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E204(u32 a) { fn_80428524(lbl_8053AE7C, a); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" u8 fn_8042E22C() { return fn_8042852C(lbl_8053AE7C); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E250(u32 a) { fn_804285F4(lbl_8053AE7C, a); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E278() { fn_8042855C(lbl_8053AE7C); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" u8 fn_8042E29C(u32 a) { return fn_8042858C(lbl_8053AE7C, a); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void* fn_8042E2C4(u32 a) { return fn_8042ACCC((VideoThreadObj*)lbl_8053AE80, a); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E2EC(u32 a) { fn_8042AD10((VideoThreadObj*)lbl_8053AE80, (OSMessage)a); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void* fn_8042E314(u32 a) { return fn_8042A708((AudioThreadObj*)lbl_8053AE84, a); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E33C(u32 a) { fn_8042A74C((AudioThreadObj*)lbl_8053AE84, (OSMessage)a); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E364() { fn_8042A3E4((AudioThreadObj*)lbl_8053AE84); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E388() { fn_8042A818((VideoThreadObj*)lbl_8053AE80); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E3AC() { fn_8042AF60((ReadThreadObj*)lbl_8053AE7C); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E3D0() { fn_8042AFA4((ReadThreadObj*)lbl_8053AE7C); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E3F4() { fn_8042A428((AudioThreadObj*)lbl_8053AE84); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E418() { fn_8042A85C((VideoThreadObj*)lbl_8053AE80); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E43C(u32 a) { fn_8042ADDC((ReadThreadObj*)lbl_8053AE7C, a); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" u8 fn_8042E464(s32 prio, void* param) { return fn_8042A458((AudioThreadObj*)lbl_8053AE84, prio, param); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" u8 fn_8042E494(s32 prio, void* param) { return fn_8042A88C((VideoThreadObj*)lbl_8053AE80, prio, param); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E4C4(THPReadBuffer* a) { fn_8042B02C((ReadThreadObj*)lbl_8053AE7C, (OSMessage)a); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E4EC(u32 a) { fn_8042A5E0((AudioThreadObj*)lbl_8053AE84, a); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E514(u32 a) { fn_8042A534((AudioThreadObj*)lbl_8053AE84, (u8*)a); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E53C(THPReadBuffer* a) { fn_8042A608((AudioThreadObj*)lbl_8053AE84, a); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E564(u32 a) { fn_8042AFD4((ReadThreadObj*)lbl_8053AE7C, (OSMessage)a); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" u32 fn_8042E58C() { return fn_8042B0AC((ReadThreadObj*)lbl_8053AE7C); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E5B0(u32 a) { fn_8042A6DC((AudioThreadObj*)lbl_8053AE84, (OSMessage)a); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" u32 fn_8042E5D8() { return fn_8042A778((AudioThreadObj*)lbl_8053AE84); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E5FC(u32 a) { fn_8042AAA8((VideoThreadObj*)lbl_8053AE80, a); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E624(u32 a) { fn_8042A970((VideoThreadObj*)lbl_8053AE80, (u8*)a); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E64C(THPReadBuffer* a) { fn_8042AB70((VideoThreadObj*)lbl_8053AE80, a); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" u32 fn_8042E674() { return fn_8042AFFC((ReadThreadObj*)lbl_8053AE7C); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E698(u32 a) { fn_8042ACA0((VideoThreadObj*)lbl_8053AE80, (OSMessage)a); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" u32 fn_8042E6C0() { return fn_8042AD3C((VideoThreadObj*)lbl_8053AE80); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E6E4(u32 a) { fn_8042AE74((ReadThreadObj*)lbl_8053AE7C, a); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void fn_8042E70C(u32 a) { fn_8042B084((ReadThreadObj*)lbl_8053AE7C, (OSMessage)a); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" u32 fn_8042E734() { return fn_8042B054((ReadThreadObj*)lbl_8053AE7C); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void* fn_8042E780(void* o);
extern u8 lbl_80529DEC[];
extern "C" void* fn_8042E758() { return fn_8042E780(lbl_80529DEC); }
#pragma dont_inline off

#pragma dont_inline on
extern "C" void* fn_8042E780(void* o) { return *(void**)((char*)o + 8); }
#pragma dont_inline off

#pragma dont_inline on
