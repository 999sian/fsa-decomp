#include "types.h"
// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x801146e4-0x801149f8 (15 functions). split_file divides it into the game's real files.

extern "C" void* lbl_802FF218;
extern "C" void fn_801147B8();
extern "C" void* lbl_802FF210;
extern "C" int fn_80159C40(void*, void*, void*);
extern "C" int fn_801146E4() {
    return 1;
}

extern "C" int fn_80114864() {
    ((void (*)())lbl_802FF210)();
    return 1;
}

extern "C" int fn_80114890() {
    return 1;
}

extern "C" BOOL fn_80114898(void);
extern "C" BOOL fn_80114898(void)
{
    return TRUE;
}

extern "C" int fn_801148A0() {
    lbl_802FF210 = (void*)fn_801147B8;
    return 4;
}

extern "C" void fn_801148B4(void* p) {
    lbl_802FF218 = p;
}

extern "C" int fn_801148BC(void* a, void* b) {
    if (b == 0) {
        return 0;
    }
    return fn_80159C40(lbl_802FF218, b, a);
}

extern "C" int fn_80159CB4(void*, void*);
extern "C" int (*lbl_8028F698[])();
extern "C" void fn_801148F4(void* p) {
    if (p != 0) {
        fn_80159CB4(lbl_802FF218, p);
    }
}

extern "C" int fn_80114920() {
    return lbl_8028F698[4]();
}

extern "C" int fn_80114950() {
    return lbl_8028F698[2]();
}

extern "C" int fn_80114980() {
    return lbl_8028F698[3]();
}

extern "C" int lbl_802C5C78[];
extern "C" int fn_800198DC();
extern "C" void fn_801146EC();
extern "C" void fn_801149B0(int a) {
    if (a == 1) {
        lbl_802C5C78[1] = 0;
    } else {
        lbl_802C5C78[1]++;
    }
    lbl_802C5C78[0]++;
}

