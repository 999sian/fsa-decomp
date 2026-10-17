// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801c42f4-0x801c5b54 (24 functions). split_file divides it into the game's real files.

volatile unsigned long __SIRegs[64] : 0xCC006400;

extern "C" void fn_801C4F24(int chan, unsigned long val) {
    __SIRegs[chan * 3] = val;
}
