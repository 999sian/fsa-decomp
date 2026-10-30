#include "types.h"
#include "JSystem/JUtility/JUTXfb.h"
#include "JSystem/JUtility/JUTVideo.h"
#include "Game/SinitPoolChain.h"

extern "C" void fn_8008D8E4(void);
extern "C" void LCDisable(void);
extern "C" OSThread* GXGetCurrentGXThread(void);
extern "C" void GXSetCurrentGXThread(void);
extern "C" BOOL __PADDisableRecalibration(BOOL);
extern "C" void OSResetSystem(int, u32, BOOL);
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

extern "C" s32 DVDCheckDisk(void);
extern "C" void fn_8008E364(u32);
extern "C" void fn_80139994(void);
extern "C" u8 lbl_8053A951;
extern "C" u32 lbl_8053A93C;
extern "C" u32 lbl_8053A940;
extern "C" void* lbl_8053AAF0;
extern "C" void* lbl_8053AD30;
extern "C" u8 lbl_8053ACD4[4];
extern "C" u32 fn_8030AAF4(s32);
extern "C" u8 fn_8030A308(void*, u32);
#pragma opt_lifetimes off
extern "C" void fn_802B1610(u8* param_1, s32 param_2) {
    if (lbl_80529DEC[0x21f] == 0) {
        __PADDisableRecalibration(0);
        if (param_2 == -1) {
            fn_8008D8E4();
            fn_8008E364(0xf0000000);
        } else {
            if ((s32)lbl_80529DEC[0x221] != 0) {
                lbl_8053A951 = 0;
                lbl_8053A93C = (u32)fn_80139994;
                lbl_8053A940 = 0;
                return;
            }
            u8* ptr = (u8*)lbl_8053ACA8;
            lbl_80529DEC[0x221] = 1;
            ptr[6] = 1;
            ptr = (u8*)lbl_8053ACA8;
            s32 c = param_2 & 0xff;
            if (c >= 0 && c <= 3) {
                lbl_80529DEC[0x222] = c;
                ptr[7] = c;
            } else {
                lbl_80529DEC[0x222] = 0xff;
                ptr[7] = 0xff;
            }
            fn_8008D8E4();
            fn_8008E364(0xf0000000);
        }
        if (DVDCheckDisk() == 0) {
            __PADDisableRecalibration(0);
            fn_802B1558();
            u8* base = lbl_80529DEC;
            base[0x21b] = 0xa5;
            for (s32 i = 0; i != 32; i += 8) {
                ((u8*)(i - 0x7f900000))[0] = base[i + 0x216];
                ((u8*)(i - 0x7f900000))[1] = base[i + 0x217];
                ((u8*)(i - 0x7f900000))[2] = base[i + 0x218];
                ((u8*)(i - 0x7f900000))[3] = base[i + 0x219];
                ((u8*)(i - 0x7f900000))[4] = base[i + 0x21a];
                ((u8*)(i - 0x7f900000))[5] = base[i + 0x21b];
                ((u8*)(i - 0x7f900000))[6] = base[i + 0x21c];
                ((u8*)(i - 0x7f900000))[7] = base[i + 0x21d];
            }
            OSResetSystem(1, 0x80000000, 0);
            do {
                VIWaitForRetrace();
            } while (true);
        }
        u8* base = lbl_80529DEC;
        if (base[0x238] != 0xff) {
            base[0x223] = 1;
            for (s32 i = 0; i != 32; i += 8) {
                ((u8*)(i - 0x7f900000))[0] = base[i + 0x216];
                ((u8*)(i - 0x7f900000))[1] = base[i + 0x217];
                ((u8*)(i - 0x7f900000))[2] = base[i + 0x218];
                ((u8*)(i - 0x7f900000))[3] = base[i + 0x219];
                ((u8*)(i - 0x7f900000))[4] = base[i + 0x21a];
                ((u8*)(i - 0x7f900000))[5] = base[i + 0x21b];
                ((u8*)(i - 0x7f900000))[6] = base[i + 0x21c];
                ((u8*)(i - 0x7f900000))[7] = base[i + 0x21d];
            }
            __PADDisableRecalibration(0);
            fn_802B1558();
            base = lbl_80529DEC;
            base[0x21b] = 0xa5;
            for (s32 i = 0; i != 32; i += 8) {
                ((u8*)(i - 0x7f900000))[0] = base[i + 0x216];
                ((u8*)(i - 0x7f900000))[1] = base[i + 0x217];
                ((u8*)(i - 0x7f900000))[2] = base[i + 0x218];
                ((u8*)(i - 0x7f900000))[3] = base[i + 0x219];
                ((u8*)(i - 0x7f900000))[4] = base[i + 0x21a];
                ((u8*)(i - 0x7f900000))[5] = base[i + 0x21b];
                ((u8*)(i - 0x7f900000))[6] = base[i + 0x21c];
                ((u8*)(i - 0x7f900000))[7] = base[i + 0x21d];
            }
            OSResetSystem(0, 0, 0);
            do {
                VIWaitForRetrace();
            } while (true);
        }
        if (((u8*)lbl_8053AAF0)[0x78] < 4) {
            base[0x224] = 1;
        }
        lbl_80529DEC[0x21f] = 1;
        ((u8*)lbl_8053ACA8)[4] = 1;
        if (((u8*)lbl_8053AAF0)[0x79] != 0) {
            int r29 = 0;
            int r28 = 0;
            u8* tbl = lbl_8053ACD4;
            for (s32 i = 0; i < 4; i++, tbl++) {
                if (fn_8030A308(lbl_8053AD30, fn_8030AAF4(i)) == 1) {
                    r29++;
                    if (*tbl == 0) {
                        r28++;
                    }
                }
            }
            if (r29 == r28) {
                lbl_80529DEC[0x220] = 1;
                param_1[5] = 1;
            }
        }
        u8* base2 = lbl_80529DEC;
        for (s32 i = 0; i != 32; i += 8) {
            ((u8*)(i - 0x7f900000))[0] = base2[i + 0x216];
            ((u8*)(i - 0x7f900000))[1] = base2[i + 0x217];
            ((u8*)(i - 0x7f900000))[2] = base2[i + 0x218];
            ((u8*)(i - 0x7f900000))[3] = base2[i + 0x219];
            ((u8*)(i - 0x7f900000))[4] = base2[i + 0x21a];
            ((u8*)(i - 0x7f900000))[5] = base2[i + 0x21b];
            ((u8*)(i - 0x7f900000))[6] = base2[i + 0x21c];
            ((u8*)(i - 0x7f900000))[7] = base2[i + 0x21d];
        }
    }
}
#pragma opt_lifetimes reset
extern "C" void fn_802B1BE0(s32 param_1, int reset, u32 code, u8 forceMenu) {
    __PADDisableRecalibration(0);
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
    lbl_80529DEC[0x21b] = 0xa5;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            ((u8*)0x80700000)[i * 8 + j] = lbl_80529DEC[0x216 + i * 8 + j];
        }
    }
    OSResetSystem(reset, code, forceMenu);
    do {
        VIWaitForRetrace();
    } while (true);
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

#pragma opt_strength_reduction off
#pragma opt_propagation off
extern "C" void fn_802B1DE8(u8* p) {
    u8* dst;
    u8* src;
    u8* base;
    s32 off;
    base = lbl_80529DEC;
    base[0x21f]=0;
    base[0x220]=0;
    p[4]=0;
    p[5]=0;
    for (off=0; off<32; off+=8) {
        src = base + off;
        dst = (u8*)(0x80700000 + off);
        dst[0]=src[0x216];
dst[1]=src[0x217];
dst[2]=src[0x218];
dst[3]=src[0x219];
dst[4]=src[0x21a];
dst[5]=src[0x21b];
dst[6]=src[0x21c];
dst[7]=src[0x21d];
    }
}
#pragma opt_propagation reset
#pragma opt_strength_reduction reset
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



