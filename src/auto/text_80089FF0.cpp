#include "JSystem/JKernel/JKRHeap.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void* lbl_8053A904;

extern void* sSystemHeap;
JKRHeap* fn_8008C484(JKRHeap* param_1)
{
    JKRHeap* old = JKRHeap::sSystemHeap;
    JKRHeap::sSystemHeap = param_1;
    return old;
}
