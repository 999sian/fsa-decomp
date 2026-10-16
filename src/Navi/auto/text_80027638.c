// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80027638-0x80030740 (113 functions). split_file divides it into the game's real files.

extern "C" void fn_8002A410(void);
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
    unsigned int flags = lbl_802FEDE0 | 0x4000;
    if (*(signed char*)(p + 0xc6e) == -1) {
        flags = lbl_802FEDE0 | 0x1000;
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

