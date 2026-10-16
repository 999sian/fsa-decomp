// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80030778-0x8003a014 (121 functions). split_file divides it into the game's real files.

extern "C" void fn_80030B3C(void);
extern "C" void fn_8002E3C4(void*, int);
extern "C" void fn_8002A3CC(void*, void*, int, int);
extern char lbl_802BB0FC[];
extern unsigned char lbl_802FEE44;
extern unsigned char lbl_802FEE43;
extern unsigned int lbl_802FEE30;
extern int lbl_802FEDE4;
extern float lbl_802FFD38;
extern "C" void fn_80030250(int);
extern "C" void fn_800302F0(int);
extern "C" void fn_800300C0(int, float, int, int, int);
extern "C" void fn_8002F358(int, int);

extern "C" void fn_80030778(void* p) {
    *(unsigned int*)((char*)lbl_802BB0FC + 0x400) = *(unsigned char*)((char*)p + 0xc);
    *(unsigned int*)((char*)lbl_802BB0FC + 0x444) &= 0xfffffff7;
    *(unsigned int*)((char*)lbl_802BB0FC + 0x450) &= 0xfffffff7;
    *(unsigned int*)((char*)lbl_802BB0FC + 0x45c) &= 0xfffffff7;
    *(unsigned int*)((char*)lbl_802BB0FC + 0x468) &= 0xfffffff7;
    fn_80030250(2);
    fn_800302F0(3);
}

extern "C" void fn_800307E4(void) {
    fn_80030B3C();
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
        ((void (*)(void*))fn_80030B3C)(p);
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

extern "C" void fn_80030A48(void* p) {
    *(unsigned int*)((char*)lbl_802BB0FC + 0x400) = *(unsigned char*)((char*)p + 0xc);
    *(unsigned int*)((char*)lbl_802BB0FC + 0x444) &= 0xfffffff7;
    *(unsigned int*)((char*)lbl_802BB0FC + 0x450) &= 0xfffffff7;
    *(unsigned int*)((char*)lbl_802BB0FC + 0x45c) &= 0xfffffff7;
    *(unsigned int*)((char*)lbl_802BB0FC + 0x468) &= 0xfffffff7;
    fn_80030250(2);
    fn_800302F0(3);
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

