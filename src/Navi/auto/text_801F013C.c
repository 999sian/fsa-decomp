// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801f013c-0x801f0bbc (14 functions). split_file divides it into the game's real files.

typedef void (*AD16Callback)(int);
extern AD16Callback lbl_802FFAD0;
extern AD16Callback lbl_802FFAD4;
extern unsigned long lbl_802FFAE0;
extern unsigned char lbl_802FFAE4;
extern "C" int OSDisableInterrupts(void);
extern "C" int OSRestoreInterrupts(int);
extern "C" unsigned long __OSMaskInterrupts(unsigned long);
extern "C" int fn_801F0924(void*, int, int);

extern "C" void fn_801F013C(void)
{
}

extern "C" void fn_801F0140(void)
{
}

typedef void (*AD16Callback)(int);
extern AD16Callback lbl_802FFAD0;
extern AD16Callback lbl_802FFAD4;
extern unsigned long lbl_802FFAE0;
extern unsigned char lbl_802FFAE4;
extern "C" int OSDisableInterrupts(void);
extern "C" int OSRestoreInterrupts(int);
extern "C" unsigned long __OSMaskInterrupts(unsigned long);
extern "C" int fn_801F0924(void*, int, int);
extern "C" void fn_801F05D8(void)
{
    lbl_802FFAE4 = 1;
    if (lbl_802FFAD0) {
        lbl_802FFAD0(0);
    }
}

extern "C" int fn_801F0614(void* buf)
{
    volatile unsigned long* reg = (volatile unsigned long*)0xCC006800;
    unsigned long cmd;
    int err;

    reg[10] = (reg[10] & 0x405) | 0xC0;
    cmd = 0x40000000;
    err = !fn_801F0924(&cmd, 2, 1);
    while (reg[13] & 1) {
    }
    err |= !fn_801F0924(buf, 4, 0);
    while (reg[13] & 1) {
    }
    reg[10] &= 0x405;
    return !err;
}

