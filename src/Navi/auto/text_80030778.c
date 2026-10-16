// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80030778-0x8003a014 (121 functions). split_file divides it into the game's real files.

extern "C" void fn_80030B3C(void*);
extern "C" void fn_8002F228(int);
extern "C" void fn_8002E3C4(void*, int);
extern "C" void fn_8002A3CC(void*, void*, int, int);
extern char lbl_802BB0FC[];
extern unsigned char lbl_802FEE44;
extern unsigned char lbl_802FEE43;
extern unsigned int lbl_802FEE30;
extern int lbl_802FEDE4;
extern float lbl_802FFD38;
extern float lbl_802FFD44;
extern char lbl_802BEF44[];
extern "C" void fn_80030250(int);
extern "C" void fn_800302F0(int);
extern "C" void fn_800300C0(int, float, int, int, int);
extern "C" void fn_8002F358(int, int);
extern "C" void fn_80033ADC(void*, void*);
extern float lbl_802FFD48;
extern int lbl_80244A88[];

extern "C" void fn_80030778(void* p) {
    *(unsigned int*)((char*)lbl_802BB0FC + 0x400) = *(unsigned char*)((char*)p + 0xc);
    *(unsigned int*)((char*)lbl_802BB0FC + 0x444) &= 0xfffffff7;
    *(unsigned int*)((char*)lbl_802BB0FC + 0x450) &= 0xfffffff7;
    *(unsigned int*)((char*)lbl_802BB0FC + 0x45c) &= 0xfffffff7;
    *(unsigned int*)((char*)lbl_802BB0FC + 0x468) &= 0xfffffff7;
    fn_80030250(2);
    fn_800302F0(3);
}

extern "C" void fn_800307E4(void* p) {
    fn_80030B3C(p);
}

extern "C" void fn_80030804(void* p) {
    *(unsigned int*)((char*)lbl_802BB0FC + 0x400) = *(unsigned char*)((char*)p + 0xc);
    *(unsigned int*)((char*)lbl_802BB0FC + 0x444) &= 0xfffffff7;
    *(unsigned int*)((char*)lbl_802BB0FC + 0x450) &= 0xfffffff7;
    *(unsigned int*)((char*)lbl_802BB0FC + 0x45c) &= 0xfffffff7;
    *(unsigned int*)((char*)lbl_802BB0FC + 0x468) &= 0xfffffff7;
    fn_80030250(2);
    fn_800302F0(3);
}

extern "C" void fn_80030870(void* p) {
    *(unsigned int*)((char*)lbl_802BB0FC + 0x400) = *(unsigned char*)((char*)p + 0xc);
    *(unsigned int*)((char*)lbl_802BB0FC + 0x444) &= 0xfffffff7;
    *(unsigned int*)((char*)lbl_802BB0FC + 0x450) &= 0xfffffff7;
    *(unsigned int*)((char*)lbl_802BB0FC + 0x45c) &= 0xfffffff7;
    *(unsigned int*)((char*)lbl_802BB0FC + 0x468) &= 0xfffffff7;
    fn_80030250(2);
    fn_800302F0(3);
    if (lbl_802FEDE4 == 2 || lbl_802FEDE4 == 3) {
        fn_800300C0(0x16, lbl_802FFD38, 0, 0, 0);
    }
}

extern "C" void fn_80030908(void* p) {
    *(int*)p = *(int*)((char*)lbl_802BB0FC + 0x58) + 500;
    *(unsigned int*)((char*)p + 0x8) |= 0x40000;
}

extern "C" void fn_8003092C(void* p) {
    *(unsigned int*)((char*)lbl_802BB0FC + 0xf8) |= 0x8;
    *(unsigned int*)((char*)lbl_802BB0FC + 0x3ec) = 0;
    *(int*)((char*)p + 0x20) = *(int*)((char*)lbl_802BB0FC + 0x58) + 60000;
    fn_8002F358(0x8a, 0);
    if (*(unsigned char*)((char*)p + 0x32) == 0) {
        *(unsigned int*)((char*)p + 0x8) |= 0x2000000;
    } else {
        fn_80030B3C(p);
    }
}

extern "C" void fn_800309B0(void* p) {
    *(unsigned int*)((char*)lbl_802BB0FC + 0x400) = *(unsigned char*)((char*)p + 0xc);
    *(unsigned int*)((char*)lbl_802BB0FC + 0x444) &= 0xfffffff7;
    *(unsigned int*)((char*)lbl_802BB0FC + 0x450) &= 0xfffffff7;
    *(unsigned int*)((char*)lbl_802BB0FC + 0x45c) &= 0xfffffff7;
    *(unsigned int*)((char*)lbl_802BB0FC + 0x468) &= 0xfffffff7;
    fn_80030250(2);
    fn_800302F0(3);
}

extern "C" void fn_80030A1C(void* p) {
    *(int*)p = *(int*)((char*)lbl_802BB0FC + 0x58) + 500;
    *(unsigned char*)((char*)p + 0x31) |= 0x1;
    *(int*)((char*)p + 0x24) = *(int*)((char*)lbl_802BB0FC + 0x58);
}

extern "C" void fn_80030A48(void* p) {
    *(unsigned int*)((char*)lbl_802BB0FC + 0x400) = *(unsigned char*)((char*)p + 0xc);
    *(unsigned int*)((char*)lbl_802BB0FC + 0x444) &= 0xfffffff7;
    *(unsigned int*)((char*)lbl_802BB0FC + 0x450) &= 0xfffffff7;
    *(unsigned int*)((char*)lbl_802BB0FC + 0x45c) &= 0xfffffff7;
    *(unsigned int*)((char*)lbl_802BB0FC + 0x468) &= 0xfffffff7;
    fn_80030250(2);
    fn_800302F0(3);
}

extern "C" void fn_80030AB4(void* p) {
    *(int*)p = *(int*)((char*)lbl_802BB0FC + 0x58) + 500;
    *(unsigned char*)((char*)p + 0x31) |= 0x4;
    *(unsigned int*)((char*)p + 0x8) |= 0x20000000;
}

extern "C" void fn_80030AE4(void* p) {
    *(unsigned int*)((char*)p + 0x8) = 0;
    *(unsigned char*)((char*)p + 0xc) = 0;
    *(unsigned char*)((char*)p + 0xd) = 0;
    *(unsigned char*)((char*)p + 0x31) = 0;
    *(unsigned char*)((char*)p + 0x34) = 0;
}

extern "C" void fn_80031CBC(void* p) {
    *(void**)((char*)p + 0x38) = *(void**)((char*)lbl_802BB0FC + 0x58);
    *(unsigned int*)((char*)p + 0x40) |= 0x80000000;
}

extern "C" void fn_80031CDC(void* p) {
    *(unsigned int*)((char*)p + 0x8) = 0;
    *(unsigned char*)((char*)p + 0xc) = 0;
    *(unsigned char*)((char*)p + 0xd) = 0;
    *(unsigned char*)((char*)p + 0x29) = 0;
    *(unsigned int*)((char*)p + 0x24) = 0;
}

extern "C" void fn_800320BC(void* p) {
    *(void**)((char*)p + 0x64) = *(void**)((char*)lbl_802BB0FC + 0x58);
    *(unsigned int*)((char*)p + 0x6c) |= 0x80000000;
}

extern "C" void fn_800320DC(void* p) {
    *(unsigned int*)((char*)p + 0x8) = 0;
    *(unsigned char*)((char*)p + 0xc) = 0;
    *(unsigned char*)((char*)p + 0xd) = 0;
    *(unsigned char*)((char*)p + 0x25) = 0;
    *(unsigned int*)((char*)p + 0x20) = 0;
}

extern "C" void fn_8003267C(void* p) {
    *(unsigned int*)((char*)p + 0x8) = 0;
    *(unsigned char*)((char*)p + 0xc) = 0;
    *(unsigned char*)((char*)p + 0xd) = 0;
    *(unsigned char*)((char*)p + 0x25) = 0;
    *(unsigned int*)((char*)p + 0x20) = 0;
}

extern "C" void fn_800329CC(void* p) {
    *(unsigned int*)((char*)p + 0x8) = 0;
    *(unsigned char*)((char*)p + 0xc) = 0;
    *(unsigned char*)((char*)p + 0xd) = 0;
    *(unsigned char*)((char*)p + 0x25) = 0;
    *(unsigned int*)((char*)p + 0x20) = 0;
}

extern "C" void fn_80033ADC(void*, void*);
extern float lbl_802FFD48;
extern int lbl_80244A88[];
extern "C" void fn_80033448(void* p) {
    if (*(int*)((char*)lbl_802BB0FC + 0x118) < 6) {
        *(unsigned char*)((char*)p + 0xef) = 0;
    } else if (*(int*)((char*)lbl_802BB0FC + 0x118) < 8) {
        *(unsigned char*)((char*)p + 0xef) = 1;
    } else {
        *(unsigned char*)((char*)p + 0xef) = 2;
    }
    fn_800300C0(0x18, lbl_802FFD48, lbl_80244A88[*(unsigned char*)((char*)p + 0xef)], 0x2000, 0);
}

extern "C" void fn_800334C8(void* p) {
    *(unsigned int*)((char*)p + 0xe8) |= 0x100000;
    *(unsigned int*)((char*)p + 0xe8) &= 0xf7ffffff;
    *(unsigned int*)((char*)p + 0xe8) |= 0x20000000;
    fn_8002A3CC(p, (char*)p + 0xf0, 0x45, 1);
    fn_8002A3CC(p, (char*)p + 0xfc, 0x46, 1);
    if (!lbl_802FEE44) {
        lbl_802FEE44 = 1;
        lbl_802FEE43 |= 4;
        lbl_802FEE30 |= 0x8000;
    }
}

extern "C" void fn_800335B4(void* p) {
    *(unsigned int*)((char*)p + 0xe8) |= 0x20000000;
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

extern "C" void fn_80033634(void* p) {
    *(unsigned int*)((char*)p + 0xe8) |= 0x20000000;
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

extern "C" void fn_800336F0(void* p) {
    fn_80033ADC((char*)p + 0xe0, p);
}

extern "C" void fn_80034B54(void) {
    *(unsigned int*)((char*)lbl_802BB0FC + 0x454) = 4;
}

extern "C" void fn_80034B68(void* p) {
    char* base;
    *(int*)((char*)p + 0x198) = (int)(lbl_802FFD44 * *(float*)(lbl_802BEF44 + 0x3c)) + *(int*)((base = lbl_802BB0FC) + 0x58);
    *(unsigned int*)((char*)p + 0x1a0) |= 0x2000;
    *(unsigned int*)(base + 0x454) = 0xe;
}

extern "C" void fn_80034BBC(void* p) {
    fn_8002A3CC(p, (char*)p + 0x1b4, 0x4b, 1);
    *(unsigned int*)((char*)lbl_802BB0FC + 0x454) = 6;
    *(unsigned int*)((char*)p + 0x1a0) |= 0x80;
}

extern "C" void fn_80034C10(void* p) {
    *(unsigned int*)((char*)p + 0x1a0) |= 0x4000;
    *(unsigned char*)((char*)p + 0x240) |= 2;
    *(unsigned int*)((char*)lbl_802BB0FC + 0x454) = 8;
}

extern "C" void fn_80034C3C(void* p) {
    *(int*)((char*)p + 0x238) = *(int*)((char*)lbl_802BB0FC + 0x58) + 0x1388;
    *(int*)((char*)p + 0x214) = *(int*)((char*)lbl_802BB0FC + 0x58);
    *(unsigned int*)((char*)p + 0x1a0) |= 0x8000;
}

extern "C" void fn_80034C68(void) {
    *(unsigned int*)((char*)lbl_802BB0FC + 0x454) = 4;
}

extern "C" void fn_8002F228(int);
extern "C" void fn_80034C7C(void* p) {
    fn_8002F228(3);
    *(int*)((char*)p + 0x198) = (int)(lbl_802FFD44 * *(float*)(lbl_802BEF44 + 0x40)) + *(int*)((char*)lbl_802BB0FC + 0x58);
    *(unsigned int*)((char*)p + 0x1a0) |= 0x20000;
    *(int*)((char*)p + 0x21c) = *(int*)((char*)lbl_802BB0FC + 0x58) + 0x1f4;
    *(unsigned int*)((char*)p + 0x1a0) |= 0x400000;
    fn_8002A3CC(p, (char*)p + 0x1b4, 0x4c, 1);
    *(unsigned int*)((char*)lbl_802BB0FC + 0x454) = 0x11;
}

extern "C" void fn_80034D28(void* p) {
    char* base = lbl_802BB0FC;
    *(int*)((char*)p + 0x198) = (int)(lbl_802FFD44 * *(float*)(lbl_802BEF44 + 0x48)) + *(int*)(base + 0x58);
    *(unsigned int*)((char*)p + 0x1a0) |= 0x40000;
    fn_8002A3CC(p, (char*)p + 0x1a8, 0x4a, 1);
    *(unsigned int*)(base + 0x454) = 0xe;
}

extern "C" void fn_80035410(void* p) {
    *(unsigned int*)((char*)p + 0x1a0) |= 0x80000;
    *(unsigned int*)((char*)p + 0x220) = 0x4;
    *(unsigned int*)((char*)p + 0x1a0) |= 0x80000000;
    fn_8002A3CC(p, (char*)p + 0x1b4, 0x46, 0x1);
}

extern "C" void fn_8003545C(void* p) {
    *(unsigned int*)((char*)p + 0x1a0) |= 0x80000;
    *(unsigned int*)((char*)p + 0x220) = 0x6;
}

extern "C" void fn_80035474(void* p) {
    *(unsigned int*)((char*)p + 0x1a0) |= 0x80000;
    *(unsigned int*)((char*)p + 0x220) = 0x6;
}

extern "C" void fn_8003548C(void* p) {
    fn_8002E3C4(p, 0);
}

extern "C" void fn_800354B0(void* p) {
    *(unsigned int*)((char*)p + 0x1a0) |= 0x80000;
    *(unsigned int*)((char*)p + 0x220) = 0x7;
}

extern "C" void fn_800354C8(void* p) {
    *(unsigned int*)((char*)p + 0x1a0) |= 0x80000;
    *(unsigned int*)((char*)p + 0x220) = 0x8;
    *(int*)((char*)p + 0x198) = *(int*)(lbl_802BB0FC + 0x58) + 0x1194;
    fn_8002A3CC(p, (char*)p + 0x1a8, 0x46, 0x1);
}

extern "C" void fn_800355C8(void* p) {
    *(unsigned int*)((char*)p + 0x1a0) |= 0x80000;
    *(unsigned int*)((char*)p + 0x220) = 0x6;
}

extern "C" void fn_80037698(void* p) {
    *(unsigned int*)((char*)p + 0x24c) |= 0x100000;
    *(unsigned int*)((char*)p + 0x2ec) = 3;
}

extern "C" void fn_800376B0(void* p) {
    *(unsigned int*)((char*)p + 0x24c) |= 0x100000;
    *(unsigned int*)((char*)p + 0x2ec) = 4;
    *(unsigned int*)((char*)p + 0x24c) |= 0x80000000;
    fn_8002A3CC(p, (char*)p + 0x260, 0x46, 0x1);
}

extern "C" void fn_800376FC(void* p) {
    *(unsigned int*)((char*)p + 0x24c) |= 0x100000;
    *(unsigned int*)((char*)p + 0x2ec) = 6;
}

extern "C" void fn_80037714(void* p) {
    *(unsigned int*)((char*)p + 0x24c) |= 0x100000;
    *(unsigned int*)((char*)p + 0x2ec) = 6;
}

extern "C" void fn_8003772C(void* p) {
    fn_8002E3C4(p, 0);
}

extern "C" void fn_80037750(void* p) {
    *(unsigned int*)((char*)p + 0x24c) |= 0x100000;
    *(unsigned int*)((char*)p + 0x2ec) = 7;
}

extern "C" void fn_80037868(void* p) {
    *(unsigned int*)((char*)p + 0x24c) |= 0x100000;
    *(unsigned int*)((char*)p + 0x2ec) = 6;
}

