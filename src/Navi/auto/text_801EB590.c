#include "types.h"
extern "C" void TRKConstructEvent(void* event, int eventType);
extern "C" int TRKPostEvent(void* event);
extern "C" void MWTRACE(u8, char*, ...);
extern void* lbl_802FA410[];
extern char lbl_80202FBC[];
extern char lbl_80202FC4[];
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

extern "C" void __TRK_reset();
extern "C" int TRKDoReset()
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
    __TRK_reset();
    return 0;
}

extern "C" int TRKDoDisconnect()
{
	struct {
		u32 length;
		u8 type;
		u8 pad[3];
		u8 flag;
		u8 rest[0x40 - 9];
	} msg;
	u8 event[12];

	lbl_802FA410[0] = 0;
	memset(&msg, 0, 0x40);
	msg.type = 0x80;
	msg.length = 0x40;
	msg.flag = 0;
	TRKWriteUARTN(&msg, 0x40);
	TRKConstructEvent(event, 1);
	TRKPostEvent(event);
	return 0;
}

extern "C" int TRKDoConnect()
{
	struct {
		u32 length;
		u8 type;
		u8 pad[3];
		u8 flag;
		u8 rest[0x40 - 9];
	} msg;

	lbl_802FA410[0] = (void*)1;
	memset(&msg, 0, 0x40);
	msg.type = 0x80;
	msg.length = 0x40;
	msg.flag = 0;
	TRKWriteUARTN(&msg, 0x40);
	return 0;
}

extern "C" void* GetTRKConnected(void);
extern void* lbl_802FA410[];
extern "C" void* GetTRKConnected(void) {
    return lbl_802FA410[0];
}

