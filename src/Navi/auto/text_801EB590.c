#include "types.h"
extern "C" void TRKConstructEvent(void* event, int eventType);
extern "C" int TRKPostEvent(void* event);
extern "C" void MWTRACE(u8, char*, ...);
extern void* lbl_802FA410[];
extern char lbl_80202FBC[];
extern char lbl_80202FC4[];
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801eb590-0x801ecc94 (22 functions). split_file divides it into the game's real files.
extern char lbl_80202DE0[];
extern char lbl_80202E14[];
extern "C" void memset(void* dst, int val, u32 n);
extern "C" void TRKWriteUARTN(void* data, u32 size);
extern "C" int TRKTargetStopped();
extern "C" int TRKTargetContinue();
extern "C" int usr_puts_serial(const char* msg);
extern "C" int fn_801ED220();
extern "C" void fn_801EF5A0(int);

extern "C" int TRKDoSetOption(u8* param_1)
{
	struct {
		u32 length;
		u8 type;
		u8 pad[3];
		u8 flag;
		u8 rest[0x40 - 9];
	} msg;
	u8 option = param_1[0x1c];

	if (param_1[0x18] == 1) {
		usr_puts_serial(lbl_80202DE0);
		if (option != 0) {
			usr_puts_serial(lbl_80202DE0 + 0x20);
		} else {
			usr_puts_serial(lbl_80202DE0 + 0x28);
		}
		fn_801EF5A0(option);
	}
	memset(&msg, 0, 0x40);
	msg.type = 0x80;
	msg.length = 0x40;
	msg.flag = 0;
	TRKWriteUARTN(&msg, 0x40);
	return 0;
}

extern "C" int TRKDoStop()
{
	struct {
		u32 length;
		u8 type;
		u8 pad[3];
		u8 flag;
		u8 rest[0x40 - 9];
	} msg;
	int result;
	u8 state;

	result = fn_801ED220();
	if (result == 0x704) {
		state = 0x21;
	} else if (result < 0x704) {
		if (result == 0) {
			state = 0;
		} else {
			state = 1;
		}
	} else if (result == 0x706) {
		state = 0x20;
	} else if (result < 0x706) {
		state = 0x22;
	} else {
		state = 1;
	}
	memset(&msg, 0, 0x40);
	msg.type = 0x80;
	msg.length = 0x40;
	msg.flag = state;
	TRKWriteUARTN(&msg, 0x40);
	return 0;
}

extern "C" int TRKDoContinue()
{
	int stopped;

	MWTRACE(1, lbl_80202E14);
	stopped = TRKTargetStopped();
	if (stopped == 0) {
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
		msg.flag = 0x16;
		TRKWriteUARTN(&msg, 0x40);
		return 0;
	} else {
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
		return TRKTargetContinue();
	}
}

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
extern "C" int TRKTargetStopped();
extern "C" int TRKTargetContinue();
extern "C" int usr_puts_serial(const char* msg);
extern "C" int fn_801ED220();
extern "C" void fn_801EF5A0(int);
extern char lbl_80202E14[];
extern char lbl_80202DE0[];
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

extern "C" void SetTRKConnected(void* param)
{
	lbl_802FA410[0] = param;
}

extern "C" void* GetTRKConnected(void);
extern void* lbl_802FA410[];
extern "C" void* GetTRKConnected(void) {
    return lbl_802FA410[0];
}

extern "C" int TRKTargetStopped(void);
extern "C" int TRKTargetContinue(void);
extern "C" int fn_801ED220(void);
extern "C" void fn_801EF5A0(int);
extern "C" int usr_puts_serial(const char* msg);
extern char lbl_80202E14[];
extern char lbl_80202DE0[];
extern "C" void fn_801EC4B8(u8* param_1, int param_2)
{
	int i;
	u8* p;
	p = param_1;
	for (i = 0; i < param_2; i++) {
		MWTRACE(8, lbl_80202FBC, *p);
		if (i % 16 == 15) {
			MWTRACE(8, lbl_80202FC4);
		}
		p++;
	}
	MWTRACE(8, lbl_80202FC4);
}

