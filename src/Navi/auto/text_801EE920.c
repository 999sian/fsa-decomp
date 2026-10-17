// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801ee920-0x801eefac (8 functions). split_file divides it into the game's real files.

extern "C" void EnableEXI2Interrupts(void);
extern unsigned char gTRKState[];
extern unsigned char gTRKCPUState[];
extern unsigned long lbl_802FA998[];
extern "C" unsigned int fn_801ECE34(void);
extern "C" int TRKInitializeTarget(void) {
    *(int*)(gTRKState + 0x98) = 1;
    *(unsigned int*)(gTRKState + 0x8c) = fn_801ECE34();
    *(unsigned long*)&lbl_802FA998 = 0xe0000000;
    return 0;
}

extern "C" unsigned long fn_801EEF34(unsigned long param_1) {
    unsigned long base = *(unsigned long*)&lbl_802FA998;
    if (param_1 >= base && param_1 < base + 0x4000 && (*(unsigned long*)(gTRKCPUState + 0x238) & 3) != 0) {
        return param_1;
    }
    if (param_1 >= 0x7e000000 && param_1 <= 0x80000000) {
        return param_1;
    }
    return (param_1 & 0x3fffffff) | 0x80000000;
}

extern "C" void EnableMetroTRKInterrupts(void) {
    EnableEXI2Interrupts();
}
