// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801c42f4-0x801c5b54 (24 functions). split_file divides it into the game's real files.

volatile unsigned long __SIRegs[64] : 0xCC006400;

extern "C" int OSDisableInterrupts(void);
extern "C" int OSRestoreInterrupts(int level);
extern unsigned long Type_8029D098[];
#include "dolphin/types.h"
#include "dolphin/os.h"

extern int Si_8029D084[];
extern int Packet_802F77D0[];
extern u32 lbl_802F7970[];
extern char* __SIVersion;
extern "C" void SISetSamplingRate(u32 msec);
extern "C" void SIInterruptHandler(__OSInterrupt interrupt, OSContext* context);
extern "C" u32 SIGetType(s32 chan);

inline u32 SIGetStatusInline(s32 chan) {
    BOOL enabled;
    u32 sr;
    int chanShift;

    enabled = OSDisableInterrupts();
    sr = __SIRegs[14];
    chanShift = 8 * (3 - chan);
    sr >>= chanShift;
    if (sr & 8) {
        if (!(Type_8029D098[chan] & 0x80)) {
            Type_8029D098[chan] = 8;
        }
    }
    OSRestoreInterrupts(enabled);
    return sr;
}

extern "C" int fn_801C42F4(void) {
    if (Si_8029D084[0] == -1) {
        return 0;
    }
    return 1;
}

extern "C" BOOL fn_801C4314(s32 chan) {
    BOOL ret = TRUE;
    s32* packet = &((s32*)Packet_802F77D0)[chan * 8];

    if (*packet == -1 && Si_8029D084[0] != chan) {
        ret = FALSE;
    }
    return ret;
}

#pragma dont_inline on
extern "C" BOOL fn_801C4990(s32 param_1) {
    BOOL enabled;
    BOOL ret;
    u32 reg;

    enabled = OSDisableInterrupts();
    reg = *(vu32*)0xCC006434;
    ret = (reg & 0x08000000) != 0;
    if (param_1 != 0) {
        Packet_802F77D0[120] = 0;
        Packet_802F77D0[121] = 0;
        Packet_802F77D0[122] = 0;
        Packet_802F77D0[123] = 0;
        reg |= 0x08000000;
    } else {
        reg &= ~0x08000000;
    }
    reg &= 0x7ffffffe;
    *(vu32*)0xCC006434 = reg;
    OSRestoreInterrupts(enabled);
    return ret;
}
#pragma dont_inline reset

extern "C" int fn_801C4A28(u32 param_1) {
    s32 i;
    u32* p;
    BOOL enabled;

    enabled = OSDisableInterrupts();
    p = lbl_802F7970;
    for (i = 0; i < 4; i++, p++) {
        if (*p == param_1) {
            OSRestoreInterrupts(enabled);
            return 1;
        }
    }
    p = lbl_802F7970;
    for (i = 0; i < 4; i++, p++) {
        if (*p == 0) {
            lbl_802F7970[i] = param_1;
            fn_801C4990(1);
            OSRestoreInterrupts(enabled);
            return 1;
        }
    }
    OSRestoreInterrupts(enabled);
    return 0;
}

extern "C" int fn_801C4AF4(u32 param_1) {
    s32 i;
    u32* p;
    s32 n;
    BOOL enabled;

    enabled = OSDisableInterrupts();
    p = lbl_802F7970;
    for (i = 0; i < 4; i++, p++) {
        if (*p == param_1) {
            lbl_802F7970[i] = 0;
            n = 0;
            if (lbl_802F7970[0] == 0) {
                n = 1;
                if (lbl_802F7970[1] == 0) {
                    n = 2;
                    if (lbl_802F7970[2] == 0) {
                        n = 3;
                        if (lbl_802F7970[3] == 0) {
                            n = 4;
                        }
                    }
                }
            }
            if (n == 4) {
                fn_801C4990(0);
            }
            OSRestoreInterrupts(enabled);
            return 1;
        }
    }
    OSRestoreInterrupts(enabled);
    return 0;
}

extern "C" void SIInit(void) {
    OSRegisterVersion(__SIVersion);
    Packet_802F77D0[0] = -1;
    Packet_802F77D0[8] = -1;
    Packet_802F77D0[16] = -1;
    Packet_802F77D0[24] = -1;
    Si_8029D084[1] = 0;
    SISetSamplingRate(0);
    if ((*(vu32*)0xCC006434 & 1) == 0) {
        *(vu32*)0xCC006434 = 0x80000000;
        __OSSetInterruptHandler(0x14, SIInterruptHandler);
        __OSUnmaskInterrupts(0x800);
        SIGetType(0);
        SIGetType(1);
        SIGetType(2);
        SIGetType(3);
    }
}

extern "C" unsigned long fn_801C4EA8(int chan) {
    int enabled;
    unsigned long sr;
    unsigned long* type;

    enabled = OSDisableInterrupts();
    sr = __SIRegs[14];
    sr >>= (3 - chan) * 8;
    if (sr & 8) {
        type = &Type_8029D098[chan];
        if (!(*type & 0x80)) {
            *type = 8;
        }
    }
    OSRestoreInterrupts(enabled);
    return sr;
}

extern "C" void fn_801C4F24(int chan, unsigned long val) {
    __SIRegs[chan * 3] = val;
}

extern "C" void fn_801C4F38(void) {
    __SIRegs[14] = (int)0x80000000;
}

extern "C" BOOL fn_801C50BC(s32 chan) {
    int enabled;
    u32 sr;
    unsigned long* type;
    int* packet = Packet_802F77D0;

    enabled = OSDisableInterrupts();
    sr = __SIRegs[14];
    sr >>= (3 - chan) * 8;
    if (sr & 8) {
        type = &Type_8029D098[chan];
        if (!(*type & 0x80)) {
            *type = 8;
        }
    }
    OSRestoreInterrupts(enabled);
    if (sr & 0x20) {
        packet[112 + chan * 2] = __SIRegs[chan * 3 + 1];
        packet[113 + chan * 2] = __SIRegs[chan * 3 + 2];
        packet[108 + chan] = TRUE;
        return TRUE;
    }
    return FALSE;
}

extern "C" int fn_801C5190(s32 chan, s32* out) {
    s32 ret;
    s32* packet = (s32*)Packet_802F77D0;
    s32 enabled;
    s32 pad[3];

    enabled = OSDisableInterrupts();
    if (fn_801C4EA8(chan) & 0x20) {
        packet[chan * 2 + 0x70] = __SIRegs[chan * 3 + 1];
        packet[chan * 2 + 0x71] = __SIRegs[chan * 3 + 2];
        packet[chan + 0x6c] = 1;
    }
    ret = packet[chan + 0x6c];
    packet[chan + 0x6c] = 0;
    if (ret) {
        out[0] = packet[chan * 2 + 0x70];
        out[1] = packet[chan * 2 + 0x71];
    }
    OSRestoreInterrupts(enabled);
    return ret;
}

extern "C" u32 SIGetType(s32 chan);
extern "C" void fn_801C59E4(void);
extern "C" void fn_801C5B30(void) {
    SIGetType(0);
    fn_801C59E4();
}