// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801f00b4-0x801f010c (3 functions). split_file divides it into the game's real files.

extern "C" int OSDisableInterrupts(void);
extern "C" int OSRestoreInterrupts(int level);
extern "C" void fn_801F00B4(int* p)
{
    OSRestoreInterrupts(*p);
}

extern "C" void fn_801F00D8(int* p)
{
    *p = OSDisableInterrupts();
}

extern "C" void fn_801F0108(void)
{
}
