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

extern unsigned int RunQueueBits_802FF7C8;
extern unsigned int SwitchThreadCallback_802FE980;
extern "C" void fn_801C13D0(unsigned char* p);
extern "C" void fn_801C033C(unsigned char* p) {
    unsigned char* next = *(unsigned char**)(p + 0x2e0);
    unsigned int* q = *(unsigned int**)(p + 0x2dc);
    unsigned char* prev = *(unsigned char**)(p + 0x2e4);
    if (next == 0) {
        q[1] = (unsigned int)prev;
    } else {
        *(unsigned char**)(next + 0x2e4) = prev;
    }
    if (prev == 0) {
        q[0] = (unsigned int)next;
    } else {
        *(unsigned char**)(prev + 0x2e0) = next;
    }
    if (q[0] == 0) {
        int prio = *(int*)(p + 0x2d0);
        RunQueueBits_802FF7C8 &= ~(1 << (31 - prio));
    }
    *(unsigned int*)(p + 0x2dc) = 0;
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

extern "C" unsigned char* fn_801C03E0(unsigned char* p, int prio);
extern "C" void fn_801C05A0(unsigned char* p, int prio) {
    int i;
    for (;;) {
        if (*(int*)(p + 0x2cc) > 0) {
            return;
        }
        if (*(int*)(p + 0x2d0) <= prio) {
            return;
        }
        p = fn_801C03E0(p, prio);
        if (p == 0) {
            return;
        }
    }
}

extern "C" void SelectThread(int);
extern "C" void fn_801C0848(void) {
    int level = OSDisableInterrupts();
    SelectThread(1);
    OSRestoreInterrupts(level);
}

extern int RunQueueHint_802FF7CC;
#pragma dont_inline on
extern "C" int fn_801C14D4(unsigned char* thread, int priority) {
    int enabled;
    int prio;
    if (priority < 0 || priority > 31) {
        return 0;
    }
    enabled = OSDisableInterrupts();
    if (*(int*)(thread + 0x2d4) != priority) {
        *(int*)(thread + 0x2d4) = priority;
        do {
            if (0 < *(int*)(thread + 0x2cc)) break;
            prio = fn_801C03A4((unsigned int*)thread);
            if (*(int*)(thread + 0x2d0) == prio) break;
            thread = fn_801C03E0(thread, prio);
        } while (thread != 0);
        if (RunQueueHint_802FF7CC != 0) {
            SelectThread(0);
        }
    }
    OSRestoreInterrupts(enabled);
    return 1;
}
#pragma dont_inline reset
extern "C" unsigned int fn_801C1594(unsigned char* p) { return *(unsigned int*)(p + 0x2d4); }

extern "C" long long fn_801C1EB8(long long time) {
    int enabled;
    long long result;

    enabled = OSDisableInterrupts();
    result = time + *(long long*)0x800030D8;
    OSRestoreInterrupts(enabled);
    return result;
}

