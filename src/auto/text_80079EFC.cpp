// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

#include <JSystem/JKernel/JKRFile.h>

extern void* lbl_80498BB0[];
extern "C" void* fn_8007BC30(void* this_);
extern "C" void* fn_80079EFC(void* this_) {
    fn_8007BC30(this_);
    *(void**)this_ = lbl_80498BB0;
    return this_;
}
