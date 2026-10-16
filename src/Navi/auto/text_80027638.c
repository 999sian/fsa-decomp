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

extern "C" int fn_8002F168(void) {
    char* obj = *(char**)(lbl_802BB0FC + 0xf0);
    if (obj != 0 && obj[0x57e] != 0) {
        return 1;
    }
    return 0;
}

extern "C" void fn_8002F2E0(void* p) {
    fn_80058740(1, p);
}

extern "C" void fn_80057C38(void);
extern "C" void fn_80058740(int, void*);
extern "C" int fn_80058C08(void);
extern "C" void fn_80058628(int, void*, int);
extern "C" void fn_80058654(int, void*, int, float);
extern "C" int lbl_802FEE28;
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

extern "C" void fn_80030664(void) {}

