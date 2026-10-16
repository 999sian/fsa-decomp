#include "JSystem/JAudio/System/JASHeapCtrl.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern "C" void __dl__FPv(void* p);
extern "C" void __dt__17JASGenericMemPoolFv(JASGenericMemPool* p, s32 flag);
extern "C" JASGenericMemPool* fn_8003D488(JASGenericMemPool* p, s16 flag)
{
    if (p != NULL) {
        __dt__17JASGenericMemPoolFv(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

extern "C" JASGenericMemPool* fn_8003D530(JASGenericMemPool* p, s16 flag)
{
    if (p != NULL) {
        __dt__17JASGenericMemPoolFv(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

JASGenericMemPool* fn_8003D584(JASGenericMemPool* p, s16 flag)
{
    if (p != NULL) {
        __dt__17JASGenericMemPoolFv(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

