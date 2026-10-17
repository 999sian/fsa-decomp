#include "types.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern u32 lbl_80539E10;
extern u32 lbl_80539E14;
extern u32 lbl_80539E18;
extern u32 lbl_8053A9F8;
extern u32 lbl_8053A9FC;
extern "C" void fn_800DF6DC(void)
{
    s32 b = lbl_80539E18;
    s32 c = b + lbl_80539E14;
    lbl_8053A9F8 = b + lbl_80539E10;
    lbl_8053A9FC = c + lbl_80539E10;
}
