#include "Dolphin/OS/OSCache.h"
#include "dolphin/base/PPCArch.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801bc1e0-0x801bc644 (13 functions). split_file divides it into the game's real files.

void ICFlashInvalidate(void)
{
    PPCMthid0(PPCMfhid0() | 0x800);
}

void ICEnable(void)
{
    PPCSync();
    PPCMthid0(PPCMfhid0() | 0x8000);
}

extern "C" u32 PPCMfhid0(void);
extern "C" u32 PPCMfl2cr(void);
extern "C" u32 PPCMfmsr(void);
extern "C" void PPCMtmsr(u32);
extern "C" void PPCMtl2cr(u32);
extern "C" void ICEnable(void);
extern "C" void DCEnable(void);
extern "C" void L2GlobalInvalidate(void);
extern "C" void DBPrintf(const char*, ...);
extern "C" void OSSetErrorHandler(s32, void*);
extern "C" void DMAErrorHandler(void);
extern "C" void __OSCacheInit(void) {
    u32 hid0;
    u32 msr;
    u32 l2cr;

    hid0 = PPCMfhid0();
    if ((hid0 & 0x8000) == 0) {
        ICEnable();
        DBPrintf("");
    }
    hid0 = PPCMfhid0();
    if ((hid0 & 0x4000) == 0) {
        DCEnable();
        DBPrintf("");
    }
    l2cr = PPCMfl2cr();
    if ((l2cr & 0x80000000) == 0) {
        msr = PPCMfmsr();
        PPCSync();
        PPCMtmsr(0x30);
        PPCSync();
        PPCSync();
        l2cr = PPCMfl2cr();
        PPCMtl2cr(l2cr & 0x7fffffff);
        PPCSync();
        L2GlobalInvalidate();
        PPCMtmsr(msr);
        l2cr = PPCMfl2cr();
        PPCMtl2cr((l2cr & 0xffdfffff) | 0x80000000);
        DBPrintf("");
    }
    OSSetErrorHandler(1, DMAErrorHandler);
    DBPrintf("");
}

