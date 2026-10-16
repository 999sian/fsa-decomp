// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80027638-0x80030740 (113 functions). split_file divides it into the game's real files.

extern "C" void fn_8002A410(void);
extern "C" void fn_80057C38(void);
extern "C" void fn_80058740(int, void*);
extern "C" int fn_80058C08(void);
extern "C" void fn_80058628(int, void*, int);
extern "C" void fn_80058654(int, void*, int, float);
extern "C" int lbl_802FEE28;
extern "C" char lbl_802BB0FC[];
extern "C" unsigned int lbl_802FEDDC;
extern "C" unsigned int lbl_802FEDE0;
extern "C" void fn_80027D4C(void) {
    fn_8002A410();
}

extern "C" void fn_8002D2EC(char* p) {
    lbl_802FEDE0 |= 0x800;
    lbl_802FEDDC |= 0x2000;
    *(int*)(p + 0x770) = *(int*)(lbl_802BB0FC + 0x58) + 1000;
}

extern "C" void fn_8002D31C(char* p) {
    unsigned int flags;
    if (*(signed char*)(p + 0xc6e) == -1) {
        flags = lbl_802FEDE0 | 0x1000;
    } else {
        flags = lbl_802FEDE0 | 0x4000;
    }
    lbl_802FEDE0 = flags;
    *(int*)(p + 0x770) = *(int*)(lbl_802BB0FC + 0x58) + 1000;
}

extern "C" void fn_8002D354(char* p) {
    lbl_802FEDE0 |= 0x1000;
    *(int*)(p + 0x770) = *(int*)(lbl_802BB0FC + 0x58) + 1000;
}

extern "C" void fn_8002D378(char* p) {
    lbl_802FEDE0 |= 0x8000;
    *(int*)(p + 0x770) = *(int*)(lbl_802BB0FC + 0x58) + 1000;
}

extern "C" void fn_8002D39C(char* p) {
    lbl_802FEDE0 |= 0x1000;
    *(int*)(p + 0x770) = *(int*)(lbl_802BB0FC + 0x58) + 1000;
}

extern "C" int fn_8002E0AC(void* obj, int a, int b, int c, int d, int e, int f, float g);
extern "C" void fn_800589CC(int);
extern "C" void* fn_80024BC8(void);
extern "C" int fn_8002F0A8(int param_1) {
    extern float lbl_802FFD10;
    void* obj = *(void**)(lbl_802BB0FC + 0xf0);
    if (obj != 0) {
        return fn_8002E0AC(obj, 4, param_1, 0, 0, 0, 1, lbl_802FFD10);
    }
    return -1;
}

extern "C" int fn_8002F100(int param_1, int param_2) {
    extern void* lbl_80225C94[];
    extern float lbl_802FFD10;
    void* obj = *(void**)(lbl_802BB0FC + 0xf0);
    if (obj != 0) {
        return fn_8002E0AC(obj, 4, (int)lbl_80225C94[param_1], param_2, 0, 0, 1, lbl_802FFD10);
    }
    return -1;
}

extern "C" int fn_8002F168(void) {
    unsigned char* obj = *(unsigned char**)(lbl_802BB0FC + 0xf0);
    if (obj != 0 && obj[0x57e] != 0) {
        return 1;
    }
    return 0;
}

extern "C" void* fn_8002F198(void) {
    unsigned char* obj = *(unsigned char**)(lbl_802BB0FC + 0xf0);
    void* ret = &lbl_802BB0FC;
    if (obj != 0) {
        if (obj[0x57e] == 3) {
            fn_800589CC(5);
            fn_800589CC(6);
        } else if (obj[0x57e] != 0) {
            fn_800589CC(5);
        }
        *(unsigned short*)(obj + 0x57c) = 0;
        ret = obj + 0x594;
        obj[0x57e] = 0;
        obj[0x57f] = 1;
        if (*(void**)(obj + 0x598) != 0) {
            ret = fn_80024BC8();
        }
    }
    return ret;
}

extern "C" void fn_8002F2E0(void* p) {
    fn_80058740(1, p);
}

extern "C" void fn_8002F308(void) {
    fn_80057C38();
    lbl_802FEE28 = 0;
}

extern "C" void fn_80057B9C(void);
extern "C" void fn_8002F330(void) {
    fn_80057B9C();
    lbl_802FEE28 = 0;
}

extern "C" void fn_8002F358(void* p, int off) {
    fn_80058628(off + fn_80058C08(), p, 1);
}

extern "C" void fn_8002F3A0(void* p, int off, float f) {
    fn_80058654(off + fn_80058C08(), p, 1, f);
}

extern "C" int fn_8002F87C(void) {
    unsigned char* obj = *(unsigned char**)(lbl_802BB0FC + 0xf0);
    if (obj != 0 && obj[0x57e] != 0) {
        return 1;
    }
    return 0;
}

extern "C" void fn_80030664(void) {}

