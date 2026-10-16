// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801c5d48-0x801ca8dc (109 functions). split_file divides it into the game's real files.

#include <types.h>
#include "dolphin/dvd/dvd.h"

extern "C" s32 OSDisableInterrupts(void);
extern "C" void OSRestoreInterrupts(s32 state);
extern "C" void stateReady(void);

extern s32 autoInvalidation_802FE9B4;
extern volatile s32 PauseFlag_802FF88C;
extern volatile s32 PausingFlag_802FF890;
extern volatile s32 FatalErrorFlag_802FF898;
extern DVDCommandBlock* executing_802FF880;
extern DVDCommandBlock DummyCommandBlock_802F7AE0;

extern "C" void fn_801C8278(void)
{
	return;
}
