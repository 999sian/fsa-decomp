// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801cafd4-0x801e0c34 (354 functions). split_file divides it into the game's real files.

extern "C" int OSDisableInterrupts(void);
extern "C" void OSRestoreInterrupts(int state);
int lbl_802FF8F4;
int jumptable_8029D79C[];
extern "C" int fn_801CB248(int param_1) {
    volatile int dummy;
    int r30 = param_1;
    int r31 = lbl_802FF8F4;
    int interrupt_state = OSDisableInterrupts();
    lbl_802FF8F4 = r30;
    OSRestoreInterrupts(interrupt_state);
    return r31;
}

extern "C" void fn_801CB2D0(int param_1) {
    if (param_1 >= 0x1b) {
        return;
    }
    
    int addr = jumptable_8029D79C[param_1];
    void (*func)() = (void (*)())addr;
    func();
}

