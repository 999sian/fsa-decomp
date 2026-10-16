#include "types.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern "C" void __ct__13JKRFileLoaderFv(void* this_);
extern "C" char __vt__10JKRArchive[];
extern "C" void* fn_8007BC30(void* this_) {
    __ct__13JKRFileLoaderFv(this_);
    *(void**)this_ = __vt__10JKRArchive;
    *(u8*)((char*)this_ + 0x30) = 0;
    *(s32*)((char*)this_ + 0x60) = 1;
    return this_;
}
