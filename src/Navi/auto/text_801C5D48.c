// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801c5d48-0x801ca8dc (109 functions). split_file divides it into the game's real files.
#include "Dolphin/dvd.h"
#include "Dolphin/os.h"

BOOL __DVDPushWaitingQueue(s32 prio, DVDCommandBlock* block);
extern "C" void stateReady(void);

static BOOL autoInvalidation_802FE9B4 = TRUE;
static DVDCommandBlock* executing_802FF880;
static volatile BOOL PauseFlag_802FF88C = FALSE;
static volatile BOOL ResetRequired_802FF8B8;
static vu32 ResumeFromHere_802FF8A8;
static u32 lbl_802FF8B4;
static void (*lbl_802FF8C4)(DVDCommandBlock*);
static u8* IDShouldBe_802FF884;
extern char lbl_802F7AC0[];
extern char BB2_802F7AA0[];
extern "C" void fn_801C76C8(u8 a, s32 b, void* cb);
extern "C" void fn_801C8E54(void);
extern "C" void fn_801C8D70(void);
extern "C" void fn_801C6FF4(void* a, s32 b, s32 c, void* cb);
extern "C" void fn_801C9060(DVDCommandBlock* block);
extern "C" void fn_801C8554(u32 result);
extern "C" void fn_801C8C24(DVDCommandBlock* block);

void DVDLowReset(void);
extern "C" BOOL fn_801CA33C(DVDCommandBlock* block, DVDCBCallback callback);
extern "C" void fn_801CA664(s32 result, DVDCommandBlock* block);
extern "C" void fn_801C12E4(OSThreadQueue* queue);
extern "C" void fn_801C13D0(OSThreadQueue* queue);
extern OSThreadQueue __DVDThreadQueue;
extern char lbl_802FE9A8[];
extern char lbl_8029D308[];
extern "C" void fn_80007AB8(const char*, int, const char*, ...);
extern "C" BOOL fn_801C9D94(DVDFileInfo* fileInfo, void* addr, s32 length, s32 offset, DVDCallback callback, s32 prio);

extern "C" void cbForStateError(u32 intType);
extern "C" void __DVDStoreErrorCode(u32 code);
extern "C" BOOL DVDLowStopMotor(DVDLowCallback callback);
extern "C" void fn_801C747C(void (*callback)(u32));
extern "C" void fn_801C88E8(void);
extern "C" void fn_801C8850(u32 param_1);

static BOOL issueCommand(s32 prio, DVDCommandBlock* block)
{
	BOOL level;
	BOOL result;

	if (autoInvalidation_802FE9B4 && (block->command == 1 || block->command == 4 || block->command == 5 || block->command == 14)) {
		DCInvalidateRange(block->addr, block->length);
	}

	level = OSDisableInterrupts();

	block->state = 2;
	result = __DVDPushWaitingQueue(prio, block);

	if ((executing_802FF880 == nullptr) && (PauseFlag_802FF88C == FALSE)) {
		stateReady();
	}

	OSRestoreInterrupts(level);
	return result;
}

extern u8* FstStart_802FF864;
extern s32 MaxEntryNum_802FF86C;
extern "C" BOOL fn_801C7BF8(s32 entryNum, DVDFileInfo* fileInfo)
{
	if (entryNum >= 0 && (u32)entryNum < (u32)MaxEntryNum_802FF86C) {
		u32* entry = (u32*)(FstStart_802FF864 + entryNum * 0xc);
		BOOL isDir = (entry[0] & 0xff000000) != 0;
		if (!isDir) {
			fileInfo->startAddr = entry[1];
			fileInfo->length = entry[2];
			fileInfo->callback = NULL;
			fileInfo->cb.state = 0;
			return TRUE;
		}
	}
	return FALSE;
}

extern "C" s32 fn_801CA5B8(DVDCommandBlock* block);
extern "C" void fn_801C803C(s32 result, DVDFileInfo* fileInfo);
extern "C" BOOL fn_801C7D34(DVDCommandBlock* block)
{
	fn_801CA5B8(block);
	return TRUE;
}

extern "C" BOOL fn_801C7F7C(DVDFileInfo* fileInfo, void* addr, s32 length, s32 offset, DVDCallback callback, s32 prio)
{
	if (offset < 0 || offset > fileInfo->length) {
		fn_80007AB8(lbl_802FE9A8, 0x2ee, lbl_8029D308);
	}
	if (offset + length < 0 || offset + length >= fileInfo->length + 0x20) {
		fn_80007AB8(lbl_802FE9A8, 0x2f4, lbl_8029D308);
	}
	fileInfo->callback = callback;
	fn_801C9D94(fileInfo, addr, length, fileInfo->startAddr + offset, fn_801C803C, prio);
	return TRUE;
}

extern "C" void fn_80007AB8(const char*, int, const char*, ...);
extern char lbl_802FE9A8[];
extern char lbl_8029D308[];
extern "C" BOOL fn_801C9D94(DVDFileInfo* fileInfo, void* addr, s32 length, s32 offset, DVDCallback callback, s32 prio);
extern "C" void fn_801C803C(s32 result, DVDFileInfo* fileInfo)
{
	if (fileInfo->callback != NULL) {
		fileInfo->callback(result, fileInfo);
	}
}

extern "C" void fn_801C8184(void)
{
	fn_801C13D0(&__DVDThreadQueue);
}

extern "C" void fn_801C87E8(u32 param_1)
{
	if (param_1 == 0x10) {
		executing_802FF880->state = -1;
		__DVDStoreErrorCode(0x1234568);
		DVDReset();
		cbForStateError(0);
	} else if (param_1 & 1) {
		fn_801C88E8();
	} else {
		fn_801C747C(fn_801C8850);
	}
}

extern "C" void fn_801C8850(u32 param_1)
{
	if (param_1 == 0x10) {
		executing_802FF880->state = -1;
		__DVDStoreErrorCode(0x1234568);
		DVDReset();
		cbForStateError(0);
	} else {
		executing_802FF880->state = -1;
		if (param_1 & 2) {
			__DVDStoreErrorCode(0x1234567);
			DVDLowStopMotor(cbForStateError);
		} else {
			__DVDStoreErrorCode(((vu32*)0xCC006000)[8]);
			DVDLowStopMotor(cbForStateError);
		}
	}
}

extern "C" void fn_801C8B48(void) {
    fn_801C76C8(((u8*)IDShouldBe_802FF884)[8], 10, fn_801C8E54);
}

extern "C" void fn_801C8C24(DVDCommandBlock* block) {
    fn_801C6FF4(BB2_802F7AA0, 0x20, 0x420, fn_801C8D70);
}

extern "C" void AlarmHandler(void) {
    DVDReset();
    DCInvalidateRange(lbl_802F7AC0, 0x20);
    DVDCommandBlock* block = executing_802FF880;
    lbl_802FF8C4 = fn_801C9060;
    fn_801C9060(block);
}

extern "C" BOOL fn_801CA014(DVDCommandBlock* block, DVDCBCallback callback)
{
	BOOL idle;

	block->command = 7;
	block->callback = callback;

	idle = issueCommand(1, block);
	return idle;
}

void DVDReset(void)
{
	DVDLowReset();
	__DIRegs[DI_STATUS] = 42;
	__DIRegs[DI_COVER_STATUS] = __DIRegs[DI_COVER_STATUS];
	ResetRequired_802FF8B8 = FALSE;
	ResumeFromHere_802FF8A8 = 0;
}

extern "C" u32 fn_801CA2DC(u32 param_1) {
    u32 old = autoInvalidation_802FE9B4;
    autoInvalidation_802FE9B4 = param_1;
    return old;
}

extern "C" s32 fn_801CA5B8(DVDCommandBlock* block)
{
	BOOL level;
	s32 state;
	DVDCommandBlock* local = block;

	if (fn_801CA33C(local, fn_801CA664) == 0) {
		return -1;
	}

	level = OSDisableInterrupts();
	while (TRUE) {
		state = local->state;
		if (state + 1U <= 1 || state == 10) {
			break;
		}
		if (state == 3 && (local->command - 4U <= 1 || local->command == 13 || local->command == 15)) {
			break;
		}
		fn_801C12E4(&__DVDThreadQueue);
	}
	OSRestoreInterrupts(level);
	return 0;
}

extern "C" u32 fn_801CA688(void)
{
	return 0x80000000;
}

