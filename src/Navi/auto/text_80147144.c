#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80147144-0x8014717c (1 functions). split_file divides it into the game's real files.

extern "C" void fn_80158D4C(void);
extern "C" void fn_80141F80(u8* p);
extern "C" void fn_80158D14(void);
extern "C" void fn_80147144(u8* p)
{
    u8* q = p;

    fn_80158D4C();
    fn_80141F80(q);
    fn_80158D14();
}
