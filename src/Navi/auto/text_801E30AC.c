// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801e30ac-0x801ea39c (89 functions). split_file divides it into the game's real files.

extern "C" double fn_801E997C(void);
extern "C" void fn_801E9310(int param);
extern "C" int fn_801E7F88(void* param);
extern unsigned char lbl_8029EC18[];
extern unsigned char lbl_8029EA18[];

struct FileFlags {
    unsigned char pad[4];
    unsigned short unk0 : 7;
    unsigned short type : 3;
    unsigned short orient : 2;
    unsigned short unk1 : 4;
};

extern "C" void fn_801E6F54(void);
#pragma push
#pragma optimization_level 1
extern "C" void fn_801E2238(void);
extern "C" void* __stdio_exit;
#pragma push
#pragma optimization_level 0
extern "C" int fn_801E30AC(int param_1) {
    register int result;
    if (param_1 == -1) {
        result = -1;
    } else {
        result = lbl_8029EC18[(unsigned char)param_1];
    }
    return result;
}

extern unsigned char lbl_8029EB18[];
extern "C" int fn_801E30E8(int param_1) {
    register int result;
    if (param_1 == -1) {
        result = -1;
    } else {
        result = lbl_8029EB18[(unsigned char)param_1];
    }
    return result;
}

#pragma pop
extern "C" unsigned char fn_801E3124(unsigned int param_1) {
    return lbl_8029EA18[(unsigned char)param_1] & 0x80;
}

extern "C" unsigned char fn_801E3140(unsigned int param_1) {
    unsigned char* p = lbl_8029EA18 + (unsigned char)param_1;
    return *p & 6;
}

extern "C" unsigned char fn_801E315C(unsigned int param_1) {
    unsigned char* p = lbl_8029EA18 + (unsigned char)param_1;
    return *p & 0x10;
}

extern "C" unsigned char fn_801E3178(unsigned int param_1) {
    unsigned char* p = lbl_8029EA18 + (unsigned char)param_1;
    return *p & 0xc0;
}

extern "C" void fn_801E419C(void) {
    __stdio_exit = (void*)fn_801E2238;
}

extern "C" unsigned int lbl_802FEAA8;
extern "C" unsigned int fn_801E63D0(void) {
    lbl_802FEAA8 = lbl_802FEAA8 * 0x41c64e6d + 0x3039;
    return (lbl_802FEAA8 >> 16) & 0x7fff;
}

extern "C" char* fn_801E64A4(char* str, int c) {
    register char* p = str - 1;
    register unsigned char target = c;
    register unsigned char ch;
    register char* result;

    ch = *++p;
    while (ch != 0) {
        if (ch == target) {
            return p;
        }
        ch = *++p;
    }
    if (target == 0) {
        result = p;
    } else {
        result = 0;
    }
    return result;
}

extern "C" char* fn_801E6704(char* dst, const char* src, unsigned long n) {
    register unsigned char* q = (unsigned char*)dst - 1;
    register const unsigned char* p = (const unsigned char*)src - 1;
    volatile unsigned char zero = 0;

    n++;

    while (--n) {
        if (!(*++q = *++p)) {
            while (--n)
                *++q = 0;
            break;
        }
    }

    return dst;
}

#pragma push
#pragma optimization_level 0
extern "C" unsigned long fn_801E6840(const char* str) {
    register unsigned long len = -1;
    register unsigned char* p = (unsigned char*)str - 1;

    do {
        len++;
    } while (*++p);

    return len;
}

extern "C" int fn_801E63F4(void*, int, int);
extern "C" unsigned long fn_801E6A3C(int base, int max_width, int (*ReadProc)(void*, int, int), void* ReadProcArg, int* chars_scanned, int* negative, int* overflow);
extern "C" int lbl_802FFAA8;
extern "C" unsigned long fn_801E6980(const char* str, char** end, int base) {
    struct {
        char* NextChar;
        int NullCharDetected;
    } isc;
    unsigned long value;
    int count, negative, overflow;

    isc.NextChar = (char*)str;
    isc.NullCharDetected = 0;

    value = fn_801E6A3C(base, 0x7FFFFFFF, fn_801E63F4, (void*)&isc, &count, &negative, &overflow);

    if (end)
        *end = (char*)str + count;

    if (overflow) {
        value = -1;
        lbl_802FFAA8 = 0x22;
    } else if (negative) {
        value = -value;
    }

    return value;
}

#pragma pop
extern "C" int fn_801E6DB0(FileFlags* file, int mode) {
    register int orientation;
    register int result;

    if (file == 0 || file->type == 0) {
        return 0;
    }
    orientation = file->orient;
    switch (orientation) {
    case 0:
        if (mode > 0) {
            file->orient = 2;
        } else if (mode < 0) {
            file->orient = 1;
        }
        result = mode;
        break;
    case 2:
        result = 1;
        break;
    case 1:
        result = -1;
        break;
    }
    return result;
}
#pragma pop
extern "C" int fn_801E6EB4()
{
	return 0;
}

extern "C" unsigned int OSGetConsoleType(void);
extern "C" int fn_801E6E60(void);
extern "C" int WriteUARTN(void*, unsigned long);
extern "C" void fn_801EF5AC(int, void*, unsigned long*, int);
extern "C" int fn_801E6EBC(volatile int a, void* buf, unsigned long* len, volatile int d) {
    if ((OSGetConsoleType() & 0x20000000) == 0) {
        if (fn_801E6E60() != 0) {
            return 1;
        }
        if (WriteUARTN(buf, *len) != 0) {
            *len = 0;
            return 1;
        }
    }
    fn_801EF5AC(a, buf, len, d);
    return 0;
}

extern const double lbl_80302260;
extern const double lbl_80302268;
extern const double lbl_80302270;
extern const double lbl_80302278;
extern const double lbl_80302280;
extern const double lbl_80302288;
extern const double lbl_80302290;
extern "C" double fn_801E9270(double x, double y, int iy) {
    double z, r, v;
    int ix;
    ix = (*(int*)&x) & 0x7fffffff;
    if (ix < 0x3e400000) {
        if ((int)x == 0) return x;
    }
    z = x * x;
    v = z * x;
    r = lbl_80302260 + z * (lbl_80302268 + z * (lbl_80302270 + z * (lbl_80302278 + lbl_80302280 * z)));
    if (iy == 0) return x + v * (lbl_80302288 + z * r);
    else return x - ((z * (lbl_80302290 * y - v * r) - y) - lbl_80302288 * v);
}

extern "C" double fn_801E9880(double x, double y) {
    *(unsigned int*)&x = (*(unsigned int*)&x & 0x7fffffff) | (*(unsigned int*)&y & 0x80000000);
    return x;
}

extern const double lbl_80302358;
extern "C" double fn_801E9EE8(double x) {
    double y[2], z = lbl_80302358;
    int n, ix;

    ix = *(int*)&x;
    ix &= 0x7fffffff;
    if (ix <= 0x3fe921fb) return ((double (*)(double, double, int))fn_801E9310)(x, z, 1);
    else if (ix >= 0x7ff00000) return x - x;
    else {
        n = ((int (*)(double, double*))fn_801E7F88)(x, y);
        return ((double (*)(double, double, int))fn_801E9310)(y[0], y[1], 1 - ((n & 1) << 1));
    }
}

extern "C" void fn_801E9F60(void) {
    fn_801E6F54();
}

extern "C" void fn_801E718C(void);
extern "C" void fn_801E9F80(void) {
    fn_801E718C();
}

extern "C" void fn_801E741C(void);
extern "C" void fn_801E9FA0(void) {
    fn_801E741C();
}

extern "C" double fn_801E7758(void);
extern "C" double fn_801E9FC0(void) {
    return fn_801E7758();
}

extern "C" float fn_801EA204(void) {
    return (float)fn_801E997C();
}

extern const double lbl_80302320;
extern "C" float fn_801EA228(void) {
    return (float)fn_801E9FC0();
}

extern "C" double fn_801E9E10(void);
extern "C" float fn_801EA270(void) {
    return (float)fn_801E9E10();
}

extern "C" double fn_801E98A8(void);
extern "C" float fn_801EA294(void) {
    return (float)fn_801E98A8();
}

extern "C" int fn_801EA2B8(double f1_param) {
    int high_word = *(int*)&f1_param;
    int exponent = high_word & 0x7ff00000;

    switch (exponent) {
    case 0x7ff00000:
        if ((high_word & 0xfffff) != 0 || *(int*)((unsigned char*)&f1_param + 4) != 0) {
            return 1;
        }
        return 2;
    case 0:
        if ((high_word & 0xfffff) != 0 || *(int*)((unsigned char*)&f1_param + 4) != 0) {
            return 5;
        }
        return 3;
    }
    return 4;
}

extern "C" void fn_801E9FE0(void);
extern "C" void fn_801EA338(void) {
    fn_801E9FE0();
}

extern "C" void fn_801EA358(unsigned char* param_1) {
    register unsigned char* r6;
    register signed char r5;
    unsigned char out;

    for (r6 = param_1; (r5 = *r6) != 0; r6++) {
        if (r5 == -1) {
            out = -1;
        } else {
            out = lbl_8029EC18[(unsigned char)r5];
        }
        *r6 = out;
    }
}

