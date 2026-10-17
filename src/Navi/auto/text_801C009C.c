// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801c009c-0x801c22b0 (35 functions). split_file divides it into the game's real files.

extern "C" void fn_801C009C(void) {}

extern "C" int OSDisableInterrupts(void);
extern "C" void OSRestoreInterrupts(int level);
extern int Reschedule_802FF7D0;
extern "C" void OSInitThreadQueue(unsigned int* p) {
    p[1] = 0;
    p[0] = 0;
}

extern "C" unsigned int fn_801C027C(void)
{
	return *(unsigned int*)0x800000E4;
}

extern "C" unsigned int fn_801C1594(unsigned char* p) { return *(unsigned int*)(p + 0x2d4); }

