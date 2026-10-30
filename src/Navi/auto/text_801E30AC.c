// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801e30ac-0x801ea39c (89 functions). split_file divides it into the game's real files.

#include <stdarg.h>

extern "C" unsigned char lbl_8029E7B0[];
extern "C" int fn_801E4650(void* fn, void* lock, void* a, void* b);
extern "C" void* fn_801E45E8(void* param_1, void* param_2, unsigned long param_3);
extern "C" int fn_801E6DB0(struct FileFlags* file, int mode);

extern "C" void __begin_critical_region(int);
extern "C" void __end_critical_region(int);
extern "C" double fn_801E997C(void);
extern "C" void fn_801E9310(int param);
extern "C" int fn_801E7F88(void* param);
extern unsigned char lbl_8029EC18[];
extern unsigned char lbl_8029EA18[];
extern "C" int fn_801E3B6C(unsigned char* s, unsigned short c);

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

extern "C" unsigned long fn_801E3194(void* a, int b, unsigned long c, void* d);
extern "C" unsigned long fn_801E34D0(void* a, int b, unsigned long c, void* d) {
    unsigned long ret;
    __begin_critical_region(2);
    ret = fn_801E3194(*(void* volatile*)&a, *(volatile int*)&b, *(volatile unsigned long*)&c, *(void* volatile*)&d);
    __end_critical_region(2);
    return ret;
}

extern "C" int fn_801E3530(void*);
extern "C" void fn_801E1B54(void*);
#pragma push
#pragma optimization_level 0
extern "C" int fn_801E367C(register void* file) {
    struct LocalFile {
        int handle;
        unsigned short unk0 : 7;
        unsigned short type : 3;
        unsigned short orient : 2;
        unsigned short unk1 : 4;
        unsigned char pad6[2];
        unsigned char unk8a : 3;
        unsigned char free_buffer : 1;
        unsigned char unk8b : 4;
        unsigned char pad9[0x13];
        void* buffer;
        unsigned char pad20[0x24];
        int (*close_proc)(int);
    };
    register int bad;
    register int result;
    register int flush_result;
    register int close_result;
    if (file == 0) {
        return -1;
    }
    if (((LocalFile*)file)->type == 0) {
        return 0;
    }
    flush_result = fn_801E3530(file);
    close_result = ((LocalFile*)file)->close_proc(((LocalFile*)file)->handle);
    ((LocalFile*)file)->type = 0;
    ((LocalFile*)file)->handle = 0;
    if (((LocalFile*)file)->free_buffer) {
        fn_801E1B54(((LocalFile*)file)->buffer);
    }
    bad = 1;
    if (flush_result == 0 && close_result == 0) {
        bad = 0;
    }
    if (bad) {
        result = -1;
    } else {
        result = 0;
    }
    return result;
}
#pragma pop
extern "C" unsigned long fn_801E37A4(void* a, int b, unsigned long c);
extern "C" unsigned long fn_801E3740(void* a, int b, unsigned long c) {
    unsigned long ret;
    int bb = *(volatile int*)&b;
    __begin_critical_region(2);
    ret = fn_801E37A4(*(void* volatile*)&a, bb, *(volatile unsigned long*)&c);
    __end_critical_region(2);
    return ret;
}

extern "C" void* fn_801E39E4(void*);
extern "C" void* fn_801E399C(void* volatile param_1) {
    void* r;
    __begin_critical_region(2);
    r = fn_801E39E4(param_1);
    __end_critical_region(2);
    return r;
}

extern "C" void fn_801E3B3C(unsigned char* p1, unsigned short p2) {
    struct {
        unsigned char* a;
        unsigned short b;
    } s;
    s.a = p1;
    s.b = p2;
    fn_801E3B6C(s.a, s.b);
}

extern "C" int fn_801E3B6C(unsigned char* s, unsigned short c) {
    unsigned char tbl[4] = {0x00, 0x00, 0xc0, 0xe0};
    unsigned char* p;
    int n;
    unsigned short wc;

    if (s == 0) {
        return 0;
    }
    wc = c;
    if (c < 0x80) {
        n = 1;
    } else if (wc < 0x800) {
        n = 2;
    } else {
        n = 3;
    }
    p = s + n;
    switch (n) {
    case 3:
        *--p = (wc & 0x3f) | 0x80;
        wc >>= 6;
    case 2:
        *--p = (wc & 0x3f) | 0x80;
        wc >>= 6;
    case 1:
        *--p = wc | tbl[n];
    }
    return n;
}

extern "C" int fn_801E3C54(unsigned char* s1, unsigned char* s2, unsigned int n) {
    unsigned char* p1 = s1 - 1;
    unsigned char* p2 = s2 - 1;
    int result;
    while (n--) {
        if (*++p1 == *++p2) {
            continue;
        }
        if (*p1 < *p2) {
            result = -1;
        } else {
            result = 1;
        }
        return result;
    }
    return 0;
}

extern "C" unsigned char* fn_801E3CD4(unsigned char* s, int c, unsigned int n) {
    unsigned char* p = s + n;
    unsigned char ch = c;
    unsigned int i = n + 1;
    while (--i) {
        if (*--p == ch) {
            return p;
        }
    }
    return 0;
}

extern "C" char* fn_801E3D2C(char* str, int c, unsigned long n) {
    register char* p = str - 1;
    register unsigned char target = c;
    unsigned long count = n;
    char* result = 0;

    count++;
    while (--count) {
        if ((unsigned char)*++p == target) {
            result = p;
            break;
        }
    }
    return result;
}

extern "C" void fn_801E3E8C(unsigned char* dst, const unsigned char* src, unsigned long n) {
    unsigned long i;
    unsigned long chunks;
    unsigned long words;

    dst += n;
    src += n;
    i = (unsigned long)dst & 3;
    if (i != 0) {
        n -= i;
        do {
            *--dst = *--src;
        } while (--i != 0);
    }
}

extern "C" void fn_801E3F48(unsigned char* dst, const unsigned char* src, unsigned long n) {
    unsigned long b;
    unsigned long a;
    unsigned long shr;
    unsigned long shl;
    unsigned long sh;
    unsigned long i;
    unsigned long* d;
    unsigned long* w;

    i = -(unsigned long)dst & 3;
    src--;
    dst--;
    if (i != 0) {
        n -= i;
        do {
            *++dst = *++src;
        } while (--i != 0);
    }
    i = n >> 3;
    src++;
    sh = (unsigned long)src & 3;
    shl = sh << 3;
    shr = 32 - shl;
    d = (unsigned long*)(dst - 3);
    w = (unsigned long*)((unsigned long)src - sh);
    a = w[0];
    do {
        b = w[1];
        *++d = (a << shl) | (b >> shr);
        w += 2;
        a = w[0];
        *++d = (b << shl) | (a >> shr);
    } while (--i != 0);
    if (n & 4) {
        w += 1;
        b = w[0];
        *++d = (a << shl) | (b >> shr);
    }
    dst = (unsigned char*)d + 3;
    src = (const unsigned char*)w + sh - 1;
    i = n & 3;
    if (i != 0) {
        do {
            *++dst = *++src;
        } while (--i != 0);
    }
}

extern "C" void fn_801E4018(unsigned char* dst, const unsigned char* src, unsigned long n) {
    unsigned long i;
    unsigned long* d32;
    const unsigned long* s32;

    dst += n;
    src += n;
    i = (unsigned long)dst & 3;
    if (i != 0) {
        n -= i;
        do {
            *--dst = *--src;
        } while (--i != 0);
    }
    d32 = (unsigned long*)dst;
    s32 = (const unsigned long*)src;
    i = n >> 5;
    if (i != 0) {
        do {
            d32[-1] = s32[-1];
            d32[-2] = s32[-2];
            d32[-3] = s32[-3];
            d32[-4] = s32[-4];
            d32[-5] = s32[-5];
            d32[-6] = s32[-6];
            d32[-7] = s32[-7];
            d32[-8] = s32[-8];
            d32 -= 8;
            s32 -= 8;
        } while (--i != 0);
    }
    i = (n >> 2) & 7;
    if (i != 0) {
        do {
            *--d32 = *--s32;
        } while (--i != 0);
    }
    dst = (unsigned char*)d32;
    src = (const unsigned char*)s32;
    i = n & 3;
    if (i != 0) {
        do {
            *--dst = *--src;
        } while (--i != 0);
    }
}

extern "C" void fn_801E40D0(unsigned char* dst, const unsigned char* src, unsigned long n) {
    unsigned long i;
    unsigned long* d32;
    const unsigned long* s32;

    i = (-(unsigned long)dst) & 3;
    dst--;
    src--;
    if (i != 0) {
        n -= i;
        do {
            *++dst = *++src;
        } while (--i != 0);
    }
    d32 = (unsigned long*)(dst - 3);
    s32 = (const unsigned long*)(src - 3);
    i = n >> 5;
    if (i != 0) {
        do {
            d32[1] = s32[1];
            d32[2] = s32[2];
            d32[3] = s32[3];
            d32[4] = s32[4];
            d32[5] = s32[5];
            d32[6] = s32[6];
            d32[7] = s32[7];
            d32[8] = s32[8];
            d32 += 8;
            s32 += 8;
        } while (--i != 0);
    }
    i = (n >> 2) & 7;
    if (i != 0) {
        do {
            *++d32 = *++s32;
        } while (--i != 0);
    }
    dst = (unsigned char*)d32 + 3;
    src = (const unsigned char*)s32 + 3;
    n &= 3;
    if (n != 0) {
        do {
            *++dst = *++src;
        } while (--n != 0);
    }
}

extern "C" void fn_801E419C(void) {
    __stdio_exit = (void*)fn_801E2238;
}

extern "C" int fn_801E445C(const char* format, ...) {
    int res;
    va_list args;
    if (fn_801E6DB0((struct FileFlags*)(lbl_8029E7B0 + 0x50), -1) >= 0) {
        return -1;
    }
    __begin_critical_region(2);
    va_start(args, format);
    res = fn_801E4650((void*)fn_801E45E8, lbl_8029E7B0 + 0x50, (void*)format, args);
    __end_critical_region(2);
    return res;
}

extern "C" unsigned long fn_801E34D0(void* a, int b, unsigned long c, void* d);
extern "C" void* memcpy(void* dst, const void* src, unsigned long n);
extern "C" int fn_801E4650(void* fn, void* lock, void* a, void* b);
extern "C" void __begin_critical_region(int);
extern "C" void __end_critical_region(int);
extern "C" unsigned char lbl_8029E7B0[];
extern "C" void* fn_801E45E8(void* param_1, void* param_2, unsigned long param_3) {
    if (param_3 != fn_801E34D0(param_2, 1, param_3, param_1)) {
        param_1 = 0;
    }
    return param_1;
}

extern "C" unsigned int lbl_802FEAA8;
extern "C" unsigned int fn_801E63D0(void) {
    lbl_802FEAA8 = lbl_802FEAA8 * 0x41c64e6d + 0x3039;
    return (lbl_802FEAA8 >> 16) & 0x7fff;
}

extern "C" int fn_801E63F4(void* state, int param_2, int mode) {
    register int* isc = (int*)state;
    register unsigned char ch;
    register int result;

    result = 0;
    switch (mode) {
    case 0:
        ch = *(unsigned char*)isc[0];
        if (ch == 0) {
            isc[1] = 1;
            result = -1;
        } else {
            isc[0] = isc[0] + 1;
            result = ch;
        }
        break;
    case 1:
        if (isc[1] == 0) {
            isc[0] = isc[0] - 1;
        } else {
            isc[1] = 0;
        }
        result = param_2;
        break;
    case 2:
        result = isc[1];
        break;
    }
    return result;
}

extern "C" char* fn_801E64A4(char* str, int c) {
    register char* p = str - 1;
    register unsigned char ch;
    register unsigned char target = c;
    register char* result = 0;

    ch = *++p;
    while (ch != 0) {
        if (ch == target) {
            return p;
        }
        ch = *++p;
    }
    if (target == 0) {
        result = p;
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

extern "C" void fn_801E6768(char* dst, const char* src) {
    register unsigned char *destb, *fromb;
    register unsigned long w, t, align;
    register unsigned long K1 = 0xFEFEFEFF;
    register unsigned long K2 = 0x80808080;

    fromb = (unsigned char*)src;
    destb = (unsigned char*)dst;

    if ((align = ((unsigned long)fromb & 3)) != ((unsigned long)destb & 3)) {
        goto bytecopy;
    }
    if (align) {
        if ((*destb = *fromb) == 0) return;
        for (align = 3 - align; align; align--) {
            if ((*(++destb) = *(++fromb)) == 0) return;
        }
        ++destb;
        ++fromb;
    }
    w = *((unsigned long*)fromb);
    t = w + K1;
    t &= K2;
    if (t) goto bytecopy;
    destb -= 4;
    do {
        destb += 4;
        *(unsigned long*)destb = w;
        fromb += 4;
        w = *(unsigned long*)fromb;
        t = w + K1;
        t &= K2;
        if (t) goto adjust;
    } while (1);
adjust:
    destb += 4;
bytecopy:
    if ((*destb = *fromb) == 0) return;
    do {
        if ((*(++destb) = *(++fromb)) == 0) return;
    } while (1);
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

extern const double lbl_803021D8;
extern const double lbl_803021E0;
extern const double lbl_803021E8;
extern const double lbl_803021F0;
extern const double lbl_803021F8;
extern const double lbl_80302200;
extern const double lbl_80302208;
extern const double lbl_80302210;
extern const double lbl_80302218;
extern "C" double fn_801E8328(double x, double y) {
    double z, r, hz, a, qx;
    int ix;
    ix = (*(int*)&x) & 0x7fffffff;
    if (ix < 0x3e400000) {
        if ((int)x == 0) return lbl_803021D8;
    }
    z = x * x;
    r = z * (lbl_803021E0 + z * (lbl_803021E8 + z * (lbl_803021F0 + z * (lbl_803021F8 + z * (lbl_80302208 * z + lbl_80302200)))));
    if (ix < 0x3FD33333) {
        return lbl_803021D8 - (lbl_80302210 * z - (z * r - x * y));
    }
    if (ix > 0x3fe90000) {
        qx = lbl_80302218;
    } else {
        ((int*)&qx)[0] = ix - 0x00200000;
        ((int*)&qx)[1] = 0;
    }
    hz = lbl_80302210 * z - qx;
    a = lbl_803021D8 - qx;
    return a - (hz - (z * r - x * y));
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

extern double lbl_80302308;
extern "C" double fn_801E8328(double x, double y);
#pragma dont_inline on
extern "C" double fn_801E98A8(double x) {
    double y[2];
    int n;
    int ix;

    ix = (*(int*)&x) & 0x7fffffff;
    if (ix <= 0x3fe921fb) {
        return fn_801E8328(x, lbl_80302308);
    } else if (ix >= 0x7ff00000) {
        return x - x;
    } else {
        n = fn_801E7F88(y);
        switch (n & 3) {
        case 0:
            return fn_801E8328(y[0], y[1]);
        case 1:
            return -fn_801E9270(y[0], y[1], 1);
        case 2:
            return -fn_801E8328(y[0], y[1]);
        default:
            return fn_801E9270(y[0], y[1], 1);
        }
    }
}

extern "C" double fn_801E9D14(double x, double* iptr)
{
    int i0, i1, j0;
    unsigned int i;
    i0 = *(int*)&x;
    i1 = *(1 + (int*)&x);
    j0 = ((i0 >> 20) & 0x7ff) - 0x3ff;
    if (j0 < 20) {
        if (j0 < 0) {
            *(int*)iptr = i0 & 0x80000000;
            *(1 + (int*)iptr) = 0;
            return x;
        } else {
            i = (0x000fffff) >> j0;
            if (((i0 & i) | i1) == 0) {
                *iptr = x;
                *(int*)&x = i0 & 0x80000000;
                *(1 + (int*)&x) = 0;
                return x;
            } else {
                *(int*)iptr = i0 & (~i);
                *(1 + (int*)iptr) = 0;
                return x - *iptr;
            }
        }
    } else if (j0 > 51) {
        *iptr = x;
        *(int*)&x = i0 & 0x80000000;
        *(1 + (int*)&x) = 0;
        return x;
    } else {
        i = ((unsigned)(0xffffffff)) >> (j0 - 20);
        if ((i1 & i) == 0) {
            *iptr = x;
            *(int*)&x = i0 & 0x80000000;
            *(1 + (int*)&x) = 0;
            return x;
        } else {
            *(int*)iptr = i0;
            *(1 + (int*)iptr) = i1 & (~i);
            return x - *iptr;
        }
    }
}

#pragma dont_inline reset

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

#pragma dont_inline on
extern "C" float fn_801EA24C(double x) {
    return (float)fn_801E9EE8(x);
}
#pragma dont_inline reset
extern "C" double fn_801E9E10(void);
extern "C" float fn_801EA270(void) {
    return (float)fn_801E9E10();
}

extern "C" double fn_801E98A8(double x);
extern "C" float fn_801EA294(double x) {
    return (float)fn_801E98A8(x);
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

