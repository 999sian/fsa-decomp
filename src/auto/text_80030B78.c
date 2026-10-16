#include "JSystem/JAudio/System/JASHeapCtrl.h"
#include "JSystem/JAudio/System/JASChannel.h"
// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern "C" void fn_80030B78(void)
{
    static JASMemPool_MultiThreaded<JASChannel> dummy;
}
