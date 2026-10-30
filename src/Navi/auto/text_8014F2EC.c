// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x8014f2ec-0x8014f314 (1 functions). split_file divides it into the game's real files.

extern "C" void fn_8014F078(void);
extern "C" void fn_8014F2EC(int param_1) {
    *(unsigned char*)(param_1 + 1) = 0;
    fn_8014F078();
}
