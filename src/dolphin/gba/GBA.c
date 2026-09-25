#include "Dolphin/gba.h"

static OSResetFunctionInfo ResetFunctionInfo = { OnReset, 0x7F };
static GBASecParam SecParams[4] ATTRIBUTE_ALIGN(32);
GBAControl __GBA[4];
BOOL __GBAReset;

/**
 * @note Address: 0x800FEB2C
 * @note Size: 0x54
 */
static void ShortCommandProc(s32 chan)
{
	GBAControl* port = &__GBA[chan];
	if (port->ret != 0) {
		return;
	}
	if ((port->input[0] != 0) || (port->input[1] != 4)) {
		port->ret = 1;
		return;
	}
	*port->status = port->input[2] & 0x3A;
}

/**
 * @note Address: 0x800FEB80
 * @note Size: 0xC0
 */
void GBAInit(void)
{
	GBAControl* gba;
	s32 chan;

	for (chan = 0; chan < 4; ++chan) {
		gba        = &__GBA[chan];
		gba->delay = OSMicrosecondsToTicks(60);
		OSInitThreadQueue(&gba->threadQueue);
		gba->param = &SecParams[chan];
	}
	OSInitAlarm();

	DSPInit();

	__GBAReset = FALSE;
	OSRegisterResetFunction(&ResetFunctionInfo);
}

/**
 * @note Address: N/A
 * @note Size: 0x64
 */
int GBAGetStatusAsync(s32 chan, u8* statusPtr, GBASyncCallback callback)
{
	GBAControl* gba = &__GBA[chan];
	if (gba->callback) {
		return 2;
	}

	gba->output[0] = 0;
	gba->status    = statusPtr;
	gba->callback  = callback;
	return __GBATransfer(chan, 1, 3, ShortCommandProc);
}

/**
 * @note Address: 0x800FEC40
 * @note Size: 0x90
 */
int GBAGetStatus(s32 chan, u8* statusPtr)
{
	int status = GBAGetStatusAsync(chan, statusPtr, __GBASyncCallback);
	return (status != 0) ? status : __GBASync(chan);
}

/**
 * @note Address: N/A
 * @note Size: 0x64
 */
int GBAResetAsync(s32 chan, u8* statusPtr, GBASyncCallback callback)
{
	GBAControl* gba = &__GBA[chan];
	if (gba->callback) {
		return 2;
	}

	gba->output[0] = 0xFF;
	gba->status    = statusPtr;
	gba->callback  = callback;
	return __GBATransfer(chan, 1, 3, ShortCommandProc);
}

/**
 * @note Address: 0x800FECD0
 * @note Size: 0x90
 */
int GBAReset(s32 chan, u8* statusPtr)
{
	int status = GBAResetAsync(chan, statusPtr, __GBASyncCallback);
	return (status != 0) ? status : __GBASync(chan);
}

/**
 * @note Address: 0x800FED60
 * @note Size: 0x10
 */
static int OnReset(void)
{
	__GBAReset = TRUE;
	return 1;
}
