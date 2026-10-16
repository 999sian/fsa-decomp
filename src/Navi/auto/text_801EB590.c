#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801eb590-0x801ecc94 (22 functions). split_file divides it into the game's real files.

extern "C" int TRKDoSupportMask()
{
	return 0;
}

extern "C" int TRKDoVersions()
{
	return 0;
}

extern "C" void memset(void* dst, int val, u32 n);
extern "C" void TRKWriteUARTN(void* data, u32 size);
extern "C" void fn_801EEE08();
extern "C" int TRKDoOverride()
{
    struct {
        u32 length;
        u8 type;
        u8 pad[3];
        u8 flag;
        u8 rest[0x40 - 9];
    } msg;

    memset(&msg, 0, 0x40);
    msg.type = 0x80;
    msg.length = 0x40;
    msg.flag = 0;
    TRKWriteUARTN(&msg, 0x40);
    fn_801EEE08();
    return 0;
}

extern "C" void* GetTRKConnected(void);
extern void* lbl_802FA410[];
extern "C" void* GetTRKConnected(void) {
    return lbl_802FA410[0];
}

