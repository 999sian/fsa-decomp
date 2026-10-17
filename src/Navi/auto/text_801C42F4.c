// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801c42f4-0x801c5b54 (24 functions). split_file divides it into the game's real files.

extern "C" void fn_801C4F24(int chan, unsigned long val) {
    volatile unsigned long* regs = (volatile unsigned long*)0xCC006400;
    *(volatile unsigned long*)((char*)regs + chan * 0xC) = val;
}
volatile unsigned long __SIRegs[64] : 0xCC006400;
