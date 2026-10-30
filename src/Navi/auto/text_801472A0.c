// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801472a0-0x80147300 (1 functions). split_file divides it into the game's real files.

extern "C" void fn_80158D4C(void);
extern "C" void fn_80158D14(void);
extern "C" void fn_8014665C(void* p, void* a, void* b, int c, int d);
extern "C" void fn_801472A0(void* p1, void* p2, void* p3) {
    fn_80158D4C();
    fn_8014665C(p1, p2, p3, 0, -1);
    fn_80158D14();
}
