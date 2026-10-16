// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801ef76c-0x801f0064 (24 functions). split_file divides it into the game's real files.

#include "sdk/Dolphin/AmcExi2Stubs.h"
#include "sdk/PowerPC_EABI_Support/MetroTRK/trkenum.h"

extern "C" void fn_801F04CC(void);
extern "C" void fn_801F0140(void);
extern "C" void fn_801F013C(void);
extern "C" int fn_801F0430(void);
extern "C" int fn_801F03A4(void* buf, int len);
extern "C" void fn_801EFBB8(void* a, void* buf, int len);
extern u8 lbl_802FB6D8[];
extern u8 lbl_802FB1B8[];

DSError ddh_cc_initinterrupts(void)
{
	EXI2_EnableInterrupts();
	return DS_NoError;
}

DSError ddh_cc_post_stop(void)
{
	EXI2_Reserve();
	return DS_NoError;
}

DSError ddh_cc_pre_continue(void)
{
	EXI2_Unreserve();
	return DS_NoError;
}

extern "C" int ddh_cc_close()
{
	return 0;
}

extern "C" int ddh_cc_shutdown()
{
	return 0;
}

extern "C" int fn_801EFD10(int param_1) {
  return *(int *)(param_1 + 0x10);
}

extern "C" DSError gdev_cc_initinterrupts(void)
{
	fn_801F04CC();
	return DS_NoError;
}

extern "C" int gdev_cc_peek(void)
{
	u8 buf[1280];
	int n = fn_801F0430();
	if (n > 0) {
		if (fn_801F03A4(buf, n) == 0) {
			fn_801EFBB8(lbl_802FB6D8, buf, n);
			return n;
		}
		return -0x2719;
	}
	return 0;
}

extern "C" DSError gdev_cc_post_stop(void)
{
	fn_801F0140();
	return DS_NoError;
}

extern "C" DSError gdev_cc_pre_continue(void)
{
	fn_801F013C();
	return DS_NoError;
}

extern "C" int gdev_cc_close()
{
	return 0;
}

extern "C" int gdev_cc_shutdown()
{
	return 0;
}

