// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801e1070-0x801e1894 (18 functions). split_file divides it into the game's real files.

extern "C" int fn_801E1070(int* param_1) {
    int a = param_1[0];
    int b = param_1[1];
    int c = param_1[2];
    if (a != 0 || b != 0 || c != 0) {
        return 1;
    }
    return 0;
}

extern "C" int fn_801E10A0(int* param_1, int* param_2) {
    int a = param_1[0];
    int b = param_2[0];
    int c = param_1[1];
    int d = param_2[1];
    int e = param_1[2];
    int f = param_2[2];
    if (a != b || c != d || e != f) {
        return 1;
    }
    return 0;
}

extern "C" unsigned long long fn_801E14B4(unsigned long long a, unsigned long long b) {
    int lza;
    int lzb;
    int n;
    unsigned long long r;
    unsigned long long x;

    lza = __cntlzw((unsigned int)(a >> 32));
    if ((unsigned int)(a >> 32) == 0) {
        lza = __cntlzw((unsigned int)a) + 32;
    }
    lzb = __cntlzw((unsigned int)(b >> 32));
    if ((unsigned int)(b >> 32) == 0) {
        lzb = __cntlzw((unsigned int)b) + 32;
    }
    if (lza > lzb) {
        return a;
    }
    n = lzb - lza + 1;
    r = a >> n;
    x = a << (64 - n);
    do {
        r = (r << 1) | (x >> 63);
        x = (x << 1) | 1;
        if (r >= b) {
            r -= b;
        }
    } while (--n != 0);
    return r;
}

extern "C" void fn_801E1594(void) {}

extern "C" unsigned long long fn_801E16A4(unsigned long long x, unsigned int n) {
    return x << n;
}

extern "C" unsigned long long fn_801E16C8(unsigned long long x, unsigned int n) {
    return x >> n;
}

extern "C" long long fn_801E16EC(long long x, int n) {
    int hi = x >> 32;
    unsigned int lo = (unsigned int)x;
    int s = n - 32;
    unsigned int rlo = lo >> n;
    rlo |= hi << (32 - n);
    int t = hi >> s;
    if (s > 0) {
        rlo |= t;
    }
    int rhi = hi >> n;
    return ((long long)rhi << 32) | rlo;
}

extern "C" float fn_801E1714(long long x) {
    unsigned int hi = (unsigned int)(x >> 32);
    unsigned int lo = (unsigned int)x;
    unsigned int sign = hi & 0x80000000;
    if (sign) {
        lo = -lo;
        hi = -hi - (lo != 0);
    }
    if ((hi | lo) == 0) {
        return 0.0f;
    }
    int n = __cntlzw(hi) + (hi == 0 ? __cntlzw(lo) : 0);
    unsigned int m_hi = (hi << n) | (lo >> (32 - n)) | (lo << (n - 32));
    unsigned int m_lo = lo << n;
    return 0.0f;
}

extern "C" long long fn_801E17C8(double x)
{
    union {
        double d;
        struct {
            unsigned long hi;
            unsigned long lo;
        } w;
    } u;
    unsigned long exp;
    unsigned long mant;
    unsigned long lo;
    unsigned long hi;
    long shift;

    u.d = x;
    lo = u.w.lo;
    exp = (u.w.hi >> 20) & 0x7ff;
    if (exp < 0x3ff) {
        return 0;
    }
    mant = (u.w.hi & 0xfffff) | 0x100000;
    shift = exp - 0x433;
    if (shift < 0) {
        shift = -shift;
        lo = (lo >> shift) | (mant << (32 - shift)) | (mant >> (shift - 32));
        hi = mant >> shift;
    } else {
        if (shift > 10) {
            if (u.w.hi & 0x80000000) {
                return 0x8000000000000000LL;
            }
            return 0x7fffffffffffffffLL;
        }
        hi = (mant << shift) | (lo >> (32 - shift)) | (lo << (shift - 32));
        lo = lo << shift;
    }
    if (u.w.hi & 0x80000000) {
        return -(((long long)hi << 32) | lo);
    }
    return ((long long)hi << 32) | lo;
}

