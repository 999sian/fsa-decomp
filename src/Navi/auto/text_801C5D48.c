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

void DVDLowReset(void);
extern "C" BOOL fn_801CA33C(DVDCommandBlock* block, DVDCBCallback callback);
extern "C" void fn_801CA664(s32 result, DVDCommandBlock* block);
extern "C" void fn_801C12E4(OSThreadQueue* queue);
extern "C" void fn_801C13D0(OSThreadQueue* queue);
extern OSThreadQueue __DVDThreadQueue;

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
	if (entryNum >= 0 && entryNum < MaxEntryNum_802FF86C) {
		u32* entry = (u32*)((u8*)FstStart_802FF864 + entryNum * 0xc);
		if ((entry[0] & 0xff000000) == 0) {
			fileInfo->startAddr = entry[1];
			fileInfo->length = entry[2];
			fileInfo->callback = NULL;
			fileInfo->cb.state = 0;
			return TRUE;
		}
	}
	return FALSE;
}

extern "C" void fn_801C803C(s32 result, DVDCommandBlock* block)
{
	if (block->callback != NULL) {
		block->callback(result, block);
	}
}

extern "C" void fn_801C8184(void)
{
	fn_801C13D0(&__DVDThreadQueue);
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

extern "C" BOOL fn_801CA2DC(BOOL param_1)
{
	BOOL old = autoInvalidation_802FE9B4;
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

