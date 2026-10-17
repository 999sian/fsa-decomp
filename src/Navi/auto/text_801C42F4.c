// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801c42f4-0x801c5b54 (24 functions). split_file divides it into the game's real files.

volatile unsigned long __SIRegs[64] : 0xCC006400;

extern "C" int OSDisableInterrupts(void);
extern "C" int OSRestoreInterrupts(int level);
extern unsigned long Type_8029D098[];
extern int Si_8029D084;
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

