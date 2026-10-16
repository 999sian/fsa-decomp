#include "types.h"
#include "JSystem/JUtility/JUTXfb.h"
#include "JSystem/JUtility/JUTVideo.h"

extern "C" void fn_8008D8E4(void);
extern "C" void LCDisable(void);
extern "C" OSThread* GXGetCurrentGXThread(void);
extern "C" void GXSetCurrentGXThread(void);
extern "C" char lbl_8051C1A0[];


extern "C" char lbl_804A8578[];
extern "C" void* lbl_8053ACA8;
extern "C" u8 lbl_80529DEC[];
extern "C" void __dl__FPv(void*);
extern "C" void fn_802B1558(void) {
    JUTXfb::getManager()->clearIndex();
    fn_8008D8E4();
    VIWaitForRetrace();
    VIWaitForRetrace();
    OSThread* thread = GXGetCurrentGXThread();
    BOOL level = OSDisableInterrupts();
    if (thread != OSGetCurrentThread()) {
        OSCancelThread(thread);
        GXSetCurrentGXThread();
    }
    GXFlush();
    GXAbortFrame();
    GXDrawDone();
    OSRestoreInterrupts(level);
    JUTVideo::destroyManager();
    GXSetDrawDoneCallback(0);
    VISetBlack(TRUE);
    VIFlush();
    VIWaitForRetrace();
    while (*(s32*)(lbl_8051C1A0 + 0x1fcc) != 0) {
        VIWaitForRetrace();
    }
    LCDisable();
}

extern "C" u32 fn_802B1D60(void) {
    u32 v = lbl_80529DEC[0x222];
    if (v > 3) {
        v = -1;
    }
    return v;
}

extern "C" u32 fn_802B1D7C(void) {
    return lbl_80529DEC[0x221] != 0;
}

extern "C" void fn_802B1D98(u8* p) {
    lbl_80529DEC[0x221] = 0;
    p[6] = 0;
}

extern "C" u32 fn_802B1DB0(void) {
    return lbl_80529DEC[0x220] != 0;
}

extern "C" u32 fn_802B1DCC(void) {
    return lbl_80529DEC[0x21f] != 0;
}

extern "C" void fn_802B1DE8(u8* p) {
    s32 i;
    lbl_80529DEC[0x21f] = 0;
    lbl_80529DEC[0x220] = 0;
    p[4] = 0;
    p[5] = 0;
    for (i = 0; i < 2; i++) {
        u8* src = &lbl_80529DEC[0x216 + i * 16];
        u8* dst = (u8*)(0x80700000 + i * 16);
        dst[0] = src[0];
        dst[1] = src[1];
        dst[2] = src[2];
        dst[3] = src[3];
        dst[4] = src[4];
        dst[5] = src[5];
        dst[6] = src[6];
        dst[7] = src[7];
        dst[8] = src[8];
        dst[9] = src[9];
        dst[10] = src[10];
        dst[11] = src[11];
        dst[12] = src[12];
        dst[13] = src[13];
        dst[14] = src[14];
        dst[15] = src[15];
    }
}

extern "C" void fn_802B1EB0(void) {
}

extern "C" void* fn_802B1EB4(void* p, s16 n) {
    if (p != 0) {
        *(char**)p = lbl_804A8578;
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

extern "C" void fn_802B1EFC(u8* p) {
    *(char**)p = lbl_804A8578;
    lbl_8053ACA8 = p;
    p[4] = 0;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0xff;
}

