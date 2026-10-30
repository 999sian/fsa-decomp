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

extern unsigned long lbl_802FFAD8;
extern unsigned long lbl_802FFADC;
extern "C" int fn_801F079C(unsigned long, void*, unsigned long);
extern "C" int fn_801F03A4(void* buf, int len)
{
    int level = OSDisableInterrupts();
    fn_801F079C(((lbl_802FFAD8 & 0x10000) ? 0x1000 : 0) + 0x1E000, buf, (len + 3) & ~3);
    lbl_802FFADC = 0;
    lbl_802FFAE4 = 0;
    OSRestoreInterrupts(level);
    return 0;
}

typedef void (*OSInterruptHandler)(short, void*);
extern "C" OSInterruptHandler __OSSetInterruptHandler(short, OSInterruptHandler);
extern "C" unsigned long __OSUnmaskInterrupts(unsigned long);
extern "C" void fn_801F0598(short, void*);
extern "C" void fn_801F05D8(void);
extern "C" void fn_801F04CC(void)
{
    __OSMaskInterrupts(0x18000);
    __OSMaskInterrupts(0x40);
    lbl_802FFAD4 = (AD16Callback)fn_801F05D8;
    __OSSetInterruptHandler(0x19, fn_801F0598);
    __OSUnmaskInterrupts(0x40);
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

extern "C" int fn_801F06C0(unsigned long addr, unsigned long* buf, long len)
{
    volatile unsigned long* reg = (volatile unsigned long*)0xCC006800;
    volatile unsigned long* status;
    unsigned long cmd;
    unsigned long data;
    int err;

    cmd = ((addr << 8) & 0x1FFFC00) | 0xA0000000;
    reg += 10;
    *reg = (*reg & 0x405) | 0xC0;
    err = !fn_801F0924(&cmd, 4, 1);
    status = (volatile unsigned long*)0xCC006800;
    while (*(status += 13) & 1) {
    }
    while (len != 0) {
        data = *buf++;
        err |= !fn_801F0924(&data, 4, 1);
        while (*status & 1) {
        }
        if ((len -= 4) < 0) {
            len = 0;
        }
    }
    *reg &= 0x405;
    return !err;
}

extern "C" int fn_801F079C(unsigned long addr, void* buf, unsigned long len)
{
    volatile unsigned long* reg = (volatile unsigned long*)0xCC006800;
    volatile unsigned long* hw;
    unsigned long cmd;
    unsigned long data;
    unsigned long* dst = (unsigned long*)buf;
    int err;

    cmd = ((addr << 8) & 0x1FFFC00) | 0x20000000;
    reg[10] = (reg[10] & 0x405) | 0xC0;
    err = !fn_801F0924(&cmd, 4, 1);
    hw = reg + 13;
    while (*hw & 1) {
    }
    while (len != 0) {
        err |= !fn_801F0924(&data, 4, 0);
        while (*hw & 1) {
        }
        *dst++ = data;
        if ((len -= 4) < 0) {
            len = 0;
        }
    }
    reg[10] &= 0x405;
    return !err;
}

extern "C" int fn_801F0878(void* buf)
{
    volatile unsigned long* reg = (volatile unsigned long*)0xCC006800;
    unsigned long cmd;
    int err;

    reg[10] = (reg[10] & 0x405) | 0xC0;
    cmd = 0x60000000;
    err = !fn_801F0924(&cmd, 2, 1);
    while (reg[13] & 1) {
    }
    err |= !fn_801F0924(buf, 4, 0);
    while (reg[13] & 1) {
    }
    reg[10] &= 0x405;
    return !err;
}

