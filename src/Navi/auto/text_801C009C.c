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

extern "C" int fn_801C0288(unsigned char* p) {
    return (*(unsigned short*)(p + 0x2c8) == 8 || *(unsigned short*)(p + 0x2c8) == 0) ? 1 : 0;
}

extern "C" int OSDisableScheduler(void) {
    int old;
    int level = OSDisableInterrupts();
    old = Reschedule_802FF7D0;
    Reschedule_802FF7D0 = old + 1;
    OSRestoreInterrupts(level);
    return old;
}

extern "C" int OSEnableScheduler(void) {
    int old;
    int level = OSDisableInterrupts();
    old = Reschedule_802FF7D0;
    Reschedule_802FF7D0 = old - 1;
    OSRestoreInterrupts(level);
    return old;
}

extern "C" int fn_801C03A4(unsigned int* p) {
    int prio;
    int min;
    unsigned int* link;
    min = *(int*)((unsigned char*)p + 0x2d4);
    for (link = *(unsigned int**)((unsigned char*)p + 0x2f4); link != 0; link = *(unsigned int**)((unsigned char*)link + 0x10)) {
        if (*link != 0) {
            prio = *(int*)(*link + 0x2d0);
            if (prio < min) {
                min = prio;
            }
        }
    }
    return min;
}

extern "C" void SelectThread(int);
extern "C" void fn_801C0848(void) {
    int level = OSDisableInterrupts();
    SelectThread(1);
    OSRestoreInterrupts(level);
}

extern "C" unsigned int fn_801C1594(unsigned char* p) { return *(unsigned int*)(p + 0x2d4); }

extern "C" long long fn_801C1EB8(long long time) {
    int enabled;
    long long result;

    enabled = OSDisableInterrupts();
    result = time + *(long long*)0x800030D8;
    OSRestoreInterrupts(enabled);
    return result;
}

