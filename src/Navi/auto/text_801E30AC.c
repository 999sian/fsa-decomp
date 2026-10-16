// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801e30ac-0x801ea39c (89 functions). split_file divides it into the game's real files.

extern "C" double fn_801E997C(void);
extern "C" void fn_801E9310(int param);
extern "C" int fn_801E7F88(void* param);
extern unsigned char lbl_8029EC18[];

extern "C" void fn_801E6F54(void);
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

extern "C" double fn_801E9880(double x, double y) {
    *(unsigned int*)&x = (*(unsigned int*)&x & 0x7fffffff) | (*(unsigned int*)&y & 0x80000000);
    return x;
}

extern "C" void fn_801E9EE8(double f1_param) {
    unsigned int high_word = *(unsigned int*)&f1_param;
    unsigned int exponent = high_word & 0x7fffffff;
    
    if (exponent < 0x3fe921fc) {
        fn_801E9310(1);
    } else if (exponent < 0x7ff00000) {
        int result = fn_801E7F88((unsigned char*)&f1_param);
        int sign_adjust = ((result & 1) == 0) ? 1 : -1;
        fn_801E9310(sign_adjust);
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
    unsigned int high_word = *(unsigned int*)&f1_param;
    unsigned int exponent = high_word & 0x7ff00000;
    
    if (exponent == 0x7ff00000) {
        if ((high_word & 0xfffff) == 0 && *(unsigned int*)((unsigned char*)&f1_param + 4) == 0) {
            return 2;
        }
        return 1;
    } else if (exponent == 0) {
        if ((high_word & 0xfffff) == 0 && *(unsigned int*)((unsigned char*)&f1_param + 4) == 0) {
            return 3;
        }
        return 5;
    }
    return 4;
}

extern "C" void fn_801E9FE0(void);
extern "C" void fn_801EA338(void) {
    fn_801E9FE0();
}

extern "C" void fn_801EA358(unsigned char* param_1) {
    unsigned char* r6 = param_1;
    unsigned char r5 = *r6;
    
    while (r5 != 0) {
        if ((signed char)r5 == -1) {
            *r6 = 0xff;
        } else {
            *r6 = lbl_8029EC18[(unsigned char)r5];
        }
        r6++;
        r5 = *r6;
    }
}

