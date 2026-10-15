// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80030778-0x8003a014 (121 functions). split_file divides it into the game's real files.

extern "C" void fn_80030B3C(void);
extern "C" void fn_8002E3C4(void*, int);
extern "C" void fn_8002A3CC(void*, void*, int, int);
extern char lbl_802BB0FC[];
extern unsigned char lbl_802FEE44;
extern unsigned char lbl_802FEE43;
extern unsigned int lbl_802FEE30;

extern "C" void fn_800307E4(void) {
    fn_80030B3C();
}

extern "C" void fn_800335C4(void* p) {
    *(unsigned int*)((char*)p + 0xe8) |= 0x200000;
    *(unsigned int*)((char*)p + 0xe8) |= 0x10000000;
    fn_8002A3CC(p, (char*)p + 0xfc, 0x46, 1);
    if (!lbl_802FEE44) {
        lbl_802FEE44 = 1;
        lbl_802FEE43 |= 4;
        lbl_802FEE30 |= 0x8000;
    }
}

extern "C" void fn_80033644(void* p) {
    fn_8002E3C4(p, 0);
}

extern "C" void fn_80033668(void* p) {
    *(unsigned int*)((char*)p + 0xe8) |= 0x40000000;
}

extern "C" void fn_80033678(void* p) {
    *(unsigned int*)((char*)p + 0xe8) |= 0x80000000;
    *(int*)((char*)p + 0xe0) = *(int*)(lbl_802BB0FC + 0x58) + 4000;
    fn_8002A3CC(p, (char*)p + 0xf0, 0x46, 1);
    if (!lbl_802FEE44) {
        lbl_802FEE44 = 1;
        lbl_802FEE43 |= 4;
        lbl_802FEE30 |= 0x8000;
    }
}

extern "C" void fn_8003545C(void* p) {
    *(unsigned int*)((char*)p + 0x1a0) |= 0x80000;
    *(unsigned int*)((char*)p + 0x220) = 0x6;
}

extern "C" void fn_8003548C(void* p) {
    fn_8002E3C4(p, 0);
}

extern "C" void fn_8003772C(void* p) {
    fn_8002E3C4(p, 0);
}

