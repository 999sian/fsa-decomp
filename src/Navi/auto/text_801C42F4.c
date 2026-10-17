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
extern char* __SIVersion;
void SISetSamplingRate(u32 msec);
void SIInterruptHandler(__OSInterrupt interrupt, OSContext* context);
extern int Packet_802F77D0[];
extern "C" int fn_801C42F4(void) {
    if (Si_8029D084[0] == -1) {
        return 0;
    }
    return 1;
}

extern "C" BOOL fn_801C4314(s32 chan) {
    return Packet_802F77D0[chan * 8] != -1 || Si_8029D084[0] == chan;
}

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

extern "C" void SIGetType(void);
extern "C" void fn_801C59E4(void);
extern "C" void fn_801C5B30(void) {
    SIGetType();
    fn_801C59E4();
}

