// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801eccac-0x801ee900 (31 functions). split_file divides it into the game's real files.

extern unsigned char gTRKCPUState[];
extern unsigned char gTRKState[];

extern "C" void fn_801ECD7C(void* dst, int val, unsigned long n)
{
    unsigned long v = (unsigned char)val;
    unsigned long i;

    dst = (unsigned char*)dst - 1;

    if (n >= 32) {
        i = (~(unsigned long)dst) & 3;

        if (i) {
            n -= i;
            do {
                dst = (unsigned char*)dst + 1;
                *(unsigned char*)dst = v;
            } while (--i);
        }

        if (v)
            v |= v << 24 | v << 16 | v << 8;

        i = n >> 5;

        dst = (unsigned long*)((unsigned char*)dst + 1) - 1;

        if (i)
            do {
                ((unsigned long*)dst)[1] = v;
                ((unsigned long*)dst)[2] = v;
                ((unsigned long*)dst)[3] = v;
                ((unsigned long*)dst)[4] = v;
                ((unsigned long*)dst)[5] = v;
                ((unsigned long*)dst)[6] = v;
                ((unsigned long*)dst)[7] = v;
                dst = (unsigned long*)dst + 8;
                *(unsigned long*)dst = v;
            } while (--i);

        i = (n & 31) >> 2;

        if (i)
            do {
                dst = (unsigned long*)dst + 1;
                *(unsigned long*)dst = v;
            } while (--i);

        dst = (unsigned char*)((unsigned long*)dst + 1) - 1;

        n &= 3;
    }

    if (n)
        do {
            dst = (unsigned char*)dst + 1;
            *(unsigned char*)dst = v;
        } while (--n);

    return;
}

extern "C" void TRKTargetSetStopped(int stopped)
{
    *(int*)(gTRKState + 0x98) = stopped;
}

extern "C" int TRKTargetStopped(void)
{
    return *(int*)(gTRKState + 0x98);
}

extern "C" int fn_801ED458(void)
{
    return *(int*)(gTRKCPUState + 0x80);
}

extern int lbl_8029F054[5];
extern char lbl_802030F8[];
extern unsigned char gTRKCPUState[];
extern unsigned char gTRKState[];
extern "C" void MWTRACE(int, const char*, ...);
extern "C" int fn_801ED468(unsigned long rangeStart, unsigned long rangeEnd, int stepOver)
{
    int result;

    if (stepOver) {
        result = 0x703;
    } else {
        lbl_8029F054[3] = rangeStart;
        lbl_8029F054[4] = rangeEnd;
        lbl_8029F054[1] = 1;
        lbl_8029F054[0] = 1;
        MWTRACE(1, lbl_802030F8);
        *(unsigned long*)(gTRKCPUState + 0x1f8) |= 0x400;
        if (lbl_8029F054[1] == 0 || lbl_8029F054[1] == 0x10) {
            lbl_8029F054[2]--;
        }
        *(int*)(gTRKState + 0x98) = 0;
        result = 0;
    }
    return result;
}

extern "C" int fn_801ED520(unsigned long count, int stepOver)
{
    int result;

    if (stepOver) {
        result = 0x703;
    } else {
        lbl_8029F054[2] = count;
        lbl_8029F054[1] = 0;
        lbl_8029F054[0] = 1;
        MWTRACE(1, lbl_802030F8);
        *(unsigned long*)(gTRKCPUState + 0x1f8) |= 0x400;
        if (lbl_8029F054[1] == 0 || lbl_8029F054[1] == 0x10) {
            lbl_8029F054[2]--;
        }
        *(int*)(gTRKState + 0x98) = 0;
        result = 0;
    }
    return result;
}

extern unsigned char gTRKExceptionStatus_8029F044[];
extern "C" void* memset(void*, int, unsigned long);
extern "C" void fn_801EE4C0(unsigned long*, unsigned long = 0);
extern "C" int TRKAppendBuffer_ui8(void*, const void*, int);
extern "C" void fn_801ED5CC(void* buffer)
{
    struct {
        unsigned long msgLength;
        unsigned char command;
        unsigned long pc;
        unsigned long instruction;
        unsigned long exceptionID;
        unsigned char pad[0x40 - 0x14];
    } msg;
    unsigned long instr;

    memset(&msg, 0, sizeof(msg));
    msg.msgLength = sizeof(msg);
    msg.command = 0x91;
    msg.pc = *(unsigned long*)gTRKExceptionStatus_8029F044;
    fn_801EE4C0(&instr);
    msg.instruction = instr;
    msg.exceptionID = *(unsigned short*)(gTRKExceptionStatus_8029F044 + 8);
    TRKAppendBuffer_ui8(buffer, &msg, sizeof(msg));
}

extern "C" void fn_801ED650(void* buffer)
{
    struct {
        unsigned long msgLength;
        unsigned char command;
        unsigned long pc;
        unsigned long instruction;
        unsigned long exceptionID;
        unsigned char pad[0x40 - 0x14];
    } msg;
    unsigned long instr;

    memset(&msg, 0, sizeof(msg));
    msg.msgLength = sizeof(msg);
    msg.command = 0x90;
    msg.pc = *(unsigned long*)(gTRKCPUState + 0x80);
    fn_801EE4C0(&instr);
    msg.instruction = instr;
    msg.exceptionID = *(unsigned long*)(gTRKCPUState + 0x2f8) & 0xffff;
    TRKAppendBuffer_ui8(buffer, &msg, sizeof(msg));
}

extern "C" void TRKConstructEvent(void*, int);
extern "C" void TRKPostEvent(void*);
extern "C" void TRKPostInterruptEvent(void)
{
    unsigned long instr;
    unsigned char event[0xc];
    int type;

    if (*(int*)(gTRKState + 0x9c) != 0) {
        *(int*)(gTRKState + 0x9c) = 0;
    } else {
        switch (*(unsigned long*)(gTRKCPUState + 0x2f8) & 0xffff) {
        case 0xd00:
        case 0x700:
            fn_801EE4C0(&instr, *(unsigned long*)(gTRKCPUState + 0x80));
            if (instr == 0xfe00000) {
                type = 5;
            } else {
                type = 3;
            }
            break;
        default:
            type = 4;
            break;
        }
        TRKConstructEvent(event, type);
        TRKPostEvent(event);
    }
}

