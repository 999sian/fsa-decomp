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

extern "C" DSError ddh_cc_initinterrupts(void)
{
	EXI2_EnableInterrupts();
	return DS_NoError;
}

extern "C" int ddh_cc_peek(void)
{
	int iVar1;
	int iVar2;
	u8 auStack_808[2048];

	iVar1 = EXI2_Poll();
	if (iVar1 <= 0) {
		return 0;
	}
	else {
		iVar2 = EXI2_ReadN(auStack_808, iVar1);
		if (iVar2 == 0) {
			fn_801EFBB8(lbl_802FB1B8, auStack_808, iVar1);
		}
		else {
			return -0x2719;
		}
	}
	return iVar1;
}

extern "C" DSError ddh_cc_post_stop(void)
{
	EXI2_Reserve();
	return DS_NoError;
}

extern "C" DSError ddh_cc_pre_continue(void)
{
	EXI2_Unreserve();
	return DS_NoError;
}

void MWTRACE(u8, char*, ...);
extern char lbl_80203220[];
extern int lbl_802FFAC0;
extern "C" void MWTRACE(u8, char*, ...);
extern "C" void MWTRACE(u8 level, char* fmt, ...);
extern "C" int ddh_cc_write(void* buf, int len)
{
	int iVar2;

	if (lbl_802FFAC0 == 0) {
		MWTRACE(8, lbl_80203220);
		return -0x2711;
	}
	MWTRACE(8, lbl_80203220 + 0x14, buf, len);
	while (len > 0) {
		MWTRACE(1, lbl_80203220 + 0x40, len);
		iVar2 = EXI2_WriteN(buf, len);
		if (iVar2 == 0) {
			break;
		}
		buf = (u8*)buf + iVar2;
		len -= iVar2;
	}
	return 0;
}

extern "C" int ddh_cc_close()
{
	return 0;
}

extern "C" int ddh_cc_open()
{
	if (lbl_802FFAC0 != 0) {
		return -0x2715;
	}
	lbl_802FFAC0 = 1;
	return 0;
}

extern "C" int ddh_cc_shutdown()
{
	return 0;
}

extern char lbl_802032D4[];
extern char lbl_802032E8[];
extern u8 lbl_802FA9B8[];
extern "C" void fn_801EFCC0(void* a, void* b, int len);
extern "C" DSError ddh_cc_initialize(vu8** param_1, AmcEXICallback param_2)
{
	MWTRACE(1, lbl_802032D4);
	EXI2_Init(param_1, param_2);
	MWTRACE(1, lbl_802032E8);
	fn_801EFCC0(lbl_802FB1B8, lbl_802FA9B8, 0x800);
	return DS_NoError;
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
	if (n <= 0) {
		return 0;
	}
	if (fn_801F03A4(buf, n) == 0) {
		fn_801EFBB8(lbl_802FB6D8, buf, n);
	} else {
		return -0x2719;
	}
	return n;
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

extern int lbl_802FFAC8;
extern "C" int gdev_cc_open()
{
	if (lbl_802FFAC8 != 0) {
		return -0x2715;
	}
	lbl_802FFAC8 = 1;
	return 0;
}

extern "C" int gdev_cc_shutdown()
{
	return 0;
}

