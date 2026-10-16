

extern "C" void OSResetSystem(int reset, unsigned long resetCode, int forceMenu);
extern "C" void fn_803CBEE0(void) {
    OSResetSystem(1, 1, 1);
}
