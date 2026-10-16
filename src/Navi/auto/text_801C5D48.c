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

extern "C" BOOL fn_801CA014(DVDCommandBlock* block, DVDCBCallback callback)
{
	BOOL idle;

	block->command = 7;
	block->callback = callback;

	idle = issueCommand(1, block);
	return idle;
}

BOOL fn_801CA33C(DVDCommandBlock* block, DVDCBCallback callback);
void fn_801CA664(s32 result, DVDCommandBlock* block);
void fn_801C12E4(OSThreadQueue* queue);
extern OSThreadQueue __DVDThreadQueue;
extern "C" s32 fn_801CA5B8(DVDCommandBlock* block)
{
	BOOL level;

	if (fn_801CA33C(block, fn_801CA664) == 0) {
		return -1;
	}

	level = OSDisableInterrupts();
	while (1 < block->state + 1U && block->state != 10 && (block->state != 3 || (1 < block->command - 4U && block->command != 13 && block->command != 15))) {
		fn_801C12E4(&__DVDThreadQueue);
	}
	OSRestoreInterrupts(level);
	return 0;
}

extern "C" u32 fn_801CA688(void)
{
	return 0x80000000;
}

