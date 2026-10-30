// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80030778-0x8003a014 (121 functions). split_file divides it into the game's real files.

extern "C" void fn_80030B3C(void*);
extern "C" void fn_8002F228(int);
extern "C" void fn_8002E3C4(void*, int);
extern "C" void fn_8002A3CC(void*, void*, int, int);
extern char lbl_802BB0FC[];
extern char lbl_80245224[];
extern "C" unsigned int lbl_802FEDDC;
extern unsigned char lbl_802FEE44;
extern unsigned char lbl_802FEE43;
extern unsigned int lbl_802FEE30;
extern int lbl_802FEDE4;
extern float lbl_802FFD38;
extern float lbl_802FFD44;
extern char lbl_802BEF44[];
extern unsigned char lbl_802B7CA0[];
extern unsigned int lbl_802444F4[];
extern unsigned int lbl_80244524[];
extern "C" int fn_80039CB8(void* p, int x, int cnt, int n = 0);
extern char lbl_802BEE18[];
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

extern "C" void fn_80030B00(void* p) {
    if (*(int*)((char*)lbl_802BB0FC + 0x420) != 0) {
        return;
    }
    if (*(unsigned int*)((char*)lbl_802BB0FC + 0x40) & 2) {
        return;
    }
    *(unsigned int*)((char*)lbl_802BB0FC + 0xf8) |= 0x100;
    *(unsigned int*)((char*)p + 0x8) |= 0x8000;
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

extern "C" void fn_80032658(void* p) {
    *(int*)((char*)p + 0x8c) = *(int*)((char*)lbl_802BB0FC + 0x58) + 500;
    *(unsigned int*)((char*)p + 0x94) |= 0xc0000000;
}

extern "C" void fn_8003267C(void* p) {
    *(unsigned int*)((char*)p + 0x8) = 0;
    *(unsigned char*)((char*)p + 0xc) = 0;
    *(unsigned char*)((char*)p + 0xd) = 0;
    *(unsigned char*)((char*)p + 0x25) = 0;
    *(unsigned int*)((char*)p + 0x20) = 0;
}

extern "C" void fn_800329A0(void* p) {
    *(int*)((char*)p + 0xb4) = *(int*)(lbl_802BB0FC + 0x58);
    *(unsigned int*)((char*)p + 0xbc) |= 0x80000000;
    lbl_802FEDDC &= ~0x800000;
}

extern "C" void fn_800329CC(void* p) {
    *(unsigned int*)((char*)p + 0x8) = 0;
    *(unsigned char*)((char*)p + 0xc) = 0;
    *(unsigned char*)((char*)p + 0xd) = 0;
    *(unsigned char*)((char*)p + 0x25) = 0;
    *(unsigned int*)((char*)p + 0x20) = 0;
}

extern "C" int fn_80032EC4(unsigned char* self, int id, int n) {
    int i;
    for (i = 0; i < n; i++) {
        int v = self[i + 0x26];
        if (v == id) {
            return 0;
        }
    }
    return 1;
}

extern "C" void fn_800332BC(void* p) {
    *(unsigned int*)((char*)p + 0xe8) |= 0x80;
}

extern "C" void fn_800332CC(void* p) {
    *(void**)((char*)p + 0xe0) = *(void**)((char*)lbl_802BB0FC + 0x58);
    *(unsigned int*)((char*)p + 0xe8) |= 0x20000;
}

extern "C" void fn_800332EC(void* p) {
    *(unsigned int*)((char*)p + 0xe8) |= 0x1000000;
    *(unsigned int*)((char*)p + 0xe8) |= 0x400000;
    fn_8002A3CC(p, (char*)p + 0xfc, 0x46, 0x1);
}

extern "C" void fn_80033330(void* p) {
    *(unsigned int*)((char*)lbl_802BB0FC + 0x118) = *(unsigned int*)((char*)p + 0x11c);
    *(unsigned int*)((char*)p + 0xe0) = *(unsigned int*)((char*)lbl_802BB0FC + 0x58) + 0xfa0;
}

extern "C" unsigned char lbl_802FEE50;
extern "C" char lbl_80244C10[];
extern "C" char lbl_80244C30[];
extern "C" void fn_80029208(const char*, ...);
extern "C" void fn_80033350(void* p) {
    lbl_802FEE50 = 1;
    *(unsigned int*)((char*)p + 0xe8) |= 0x20040;
    if (*(int*)((char*)p + 0x11c) >= 3) {
        *(int*)((char*)p + 0x128) = 0x1e;
        *(int*)((char*)p + 0x12c) = *(int*)((char*)p + 0x11c) - 3;
    }
    fn_80029208(lbl_80244C10);
}

extern "C" void fn_800333B4(void* p) {
    *(int*)(lbl_802BB0FC + 0x118) = *(int*)((char*)p + 0x11c);
}

extern "C" void fn_800333C8(void* p) {
    lbl_802FEE50 = 1;
    *(int*)((char*)p + 0xe0) = *(int*)(lbl_802BB0FC + 0x58) + 2500;
    *(unsigned int*)((char*)p + 0xe8) |= 0x2001040;
    fn_8002F228(6);
    *(int*)((char*)p + 0x128) = 0x1e;
    *(int*)((char*)p + 0x12c) = *(int*)((char*)p + 0x11c) - 3;
    fn_80029208(lbl_80244C30);
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

extern unsigned int lbl_802FEDE0;
extern char lbl_80244C68[];
extern char lbl_80246138[];
extern "C" void fn_800358E4(void* a, void* b);
extern "C" void fn_80033ADC(void* p, void*) {
    lbl_802FEDE0 |= 0x400;
    *(unsigned int*)((char*)p + 0x8) &= ~4;
    *(unsigned int*)(lbl_802BB0FC + 0x118) = 0;
    *(unsigned int*)(lbl_802BB0FC + 0xf8) &= ~1;
    if (!lbl_802FEE44) {
        lbl_802FEE44 = 1;
        lbl_802FEE43 |= 4;
        lbl_802FEE30 |= 0x8000;
    }
    fn_80029208(lbl_80244C68);
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

extern "C" void fn_80034DA4(void) {
    *(unsigned int*)((char*)lbl_802BB0FC + 0x454) = 6;
}

extern "C" void fn_80035304(void* p) {
    fn_800300C0(0x18, lbl_802FFD48, lbl_80244A88[*(unsigned char*)((char*)p + 0x1a7)], 0x2000, 0);
}

extern "C" void fn_80035348(void* p) {
    *(unsigned int*)((char*)p + 0x1a0) |= 0x80000;
    if (*(unsigned char*)((char*)p + 0x23f) < 4) {
        *(unsigned char*)((char*)p + 0x1a4) = *(unsigned char*)((char*)p + 0x23f);
        *(unsigned int*)((char*)p + 0x220) = 2;
    } else {
        *(unsigned int*)((char*)p + 0x220) = 6;
    }
    *(unsigned int*)((char*)p + 0x1a0) |= 0x40000000;
    *(int*)((char*)p + 0x198) = (int)(*(float*)((char*)lbl_802BEF44 + 0x58) * lbl_802FFD44) + *(int*)((char*)lbl_802BB0FC + 0x58);
}

extern "C" void fn_800353C4(void* p) {
    *(unsigned int*)((char*)p + 0x1a0) |= 0x80000;
    *(unsigned int*)((char*)p + 0x220) = 3;
}

extern float lbl_802FFD4C;
extern "C" void fn_800353DC(void) {
    fn_800300C0(0x18, 0.6f, 0x80, 0x2000, 0);
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

extern "C" void fn_8003551C(void* p) {
    fn_800358E4((char*)p + 0x198, p);
}

extern "C" void fn_80035544(void* p) {
    char* base;
    *(unsigned int*)((char*)p + 0x1a0) |= 0x80000;
    *(unsigned int*)((char*)p + 0x220) = 6;
    *(unsigned int*)((char*)p + 0x1a0) |= 0x40000000;
    *(int*)((char*)p + 0x198) = (int)(lbl_802FFD44 * *(float*)((char*)lbl_802BEF44 + 0x58)) + *(int*)((base = (char*)lbl_802BB0FC) + 0x58);
}

extern "C" void fn_800355A4(void* p) {
    *(unsigned int*)((char*)p + 0x1a0) |= 0x80000;
    *(unsigned int*)((char*)p + 0x220) = 4;
    *(unsigned int*)((char*)p + 0x1a0) |= 0x80000000;
}

extern "C" void fn_800355C8(void* p) {
    *(unsigned int*)((char*)p + 0x1a0) |= 0x80000;
    *(unsigned int*)((char*)p + 0x220) = 0x6;
}

extern "C" unsigned short fn_80036C54(int i, int j) {
    return *(unsigned short*)(lbl_80245224 + i * 0x14 + j * 2 + 8);
}

extern "C" void fn_80036F04(void* p) {
    *(unsigned int*)((char*)p + 0x24c) |= 0x80;
}

extern "C" void fn_80036F14(void* p) {
    float f;
    f = lbl_802FFD44 * *(float*)((char*)lbl_802BEF44 + 0x6c);
    *(int*)((char*)p + 0x244) = (int)f + *(int*)((char*)lbl_802BB0FC + 0x58);
    *(unsigned int*)((char*)p + 0x24c) |= 0x2000;
    if (*(int*)((char*)lbl_802BB0FC + 0x12c) == 2 && *(unsigned char*)((char*)p + 0x303) == 0) {
        *(unsigned int*)((char*)lbl_802BB0FC + 0x454) = 8;
    }
    *(unsigned int*)((char*)p + 0x24c) |= 0x200;
}

extern "C" void fn_80036F8C(void* p) {
    *(int*)((char*)p + 0x244) = *(int*)((char*)lbl_802BB0FC + 0x58) + 500;
    *(int*)((char*)p + 0x2e0) = *(int*)((char*)lbl_802BB0FC + 0x58);
    *(unsigned int*)((char*)p + 0x24c) |= 0x4000;
}

extern "C" void fn_80036FB8(void* p) {
    *(int*)((char*)p + 0x244) = *(int*)((char*)lbl_802BB0FC + 0x58) + 500;
    *(int*)((char*)p + 0x2e0) = *(int*)((char*)lbl_802BB0FC + 0x58);
    *(unsigned int*)((char*)p + 0x24c) |= 0x8000;
}

extern "C" void fn_80036FE4(void* p) {
    float f = lbl_802FFD44 * *(float*)((char*)lbl_802BEF44 + 0x88);
    *(int*)((char*)p + 0x244) = (int)f + *(int*)((char*)lbl_802BB0FC + 0x58);
    *(int*)((char*)p + 0x2e0) = *(int*)((char*)lbl_802BB0FC + 0x58);
    *(unsigned int*)((char*)p + 0x24c) |= 0x10000;
}

extern "C" void fn_80037038(void* p) {
    *(unsigned int*)((char*)p + 0x24c) |= 0x100;
    *(int*)((char*)p + 0x244) = *(int*)((char*)lbl_802BB0FC + 0x58) + 1000;
    fn_8002A3CC(p, (char*)p + 0x254, 0x4c, 0x1);
}

extern "C" void fn_800375D8(void* p) {
    int* tbl = lbl_80244A88;
    float f = lbl_802FFD48;
    fn_800300C0(0x18, f, tbl[*(unsigned char*)((char*)p + 0x253)], 0x2000, 0);
}

extern "C" void fn_8003761C(void* p) {
    *(unsigned int*)((char*)p + 0x24c) |= 0x100000;
    if (*(unsigned char*)((char*)p + 0x301) < 4) {
        *(unsigned char*)((char*)p + 0x250) = *(unsigned char*)((char*)p + 0x301);
        *(unsigned int*)((char*)p + 0x2ec) = 2;
    } else {
        *(unsigned int*)((char*)p + 0x2ec) = 6;
    }
    float fVar1 = lbl_802FFD44;
    *(unsigned int*)((char*)p + 0x24c) |= 0x40000000;
    *(int*)((char*)p + 0x244) = (int)(fVar1 * *(float*)(lbl_802BEF44 + 0x8c)) + *(int*)((char*)lbl_802BB0FC + 0x58);
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

extern "C" void fn_80037768(void* p) {
    *(unsigned int*)((char*)p + 0x24c) |= 0x100000;
    *(unsigned int*)((char*)p + 0x2ec) = 0x8;
    *(int*)((char*)p + 0x244) = *(int*)(lbl_802BB0FC + 0x58) + 0x1194;
    fn_8002A3CC(p, (char*)p + 0x254, 0x46, 0x1);
}

extern "C" void fn_8003793C(void* a, void* b);
extern unsigned short lbl_802272D4[];
extern "C" void fn_800377BC(void* p) {
    fn_8003793C((char*)p + 0x244, p);
}

extern "C" void fn_800377E4(void* p) {
    char* base = (char*)lbl_802BB0FC;
    *(unsigned int*)((char*)p + 0x24c) |= 0x100000;
    *(int*)((char*)p + 0x2ec) = 6;
    *(unsigned int*)((char*)p + 0x24c) |= 0x40000000;
    *(int*)((char*)p + 0x244) = (int)(lbl_802FFD44 * *(float*)((char*)lbl_802BEF44 + 0x8c)) + *(int*)(base + 0x58);
}

extern "C" void fn_80037844(void* p) {
    *(unsigned int*)((char*)p + 0x24c) |= 0x100000;
    *(int*)((char*)p + 0x2ec) = 4;
    *(unsigned int*)((char*)p + 0x24c) |= 0x80000000;
}

extern "C" void fn_80037868(void* p) {
    *(unsigned int*)((char*)p + 0x24c) |= 0x100000;
    *(unsigned int*)((char*)p + 0x2ec) = 6;
}

extern "C" void fn_80037880(void* p) {
    *(unsigned int*)((char*)p + 0x8) = 0;
    *(unsigned char*)((char*)p + 0xc) = 0;
    *(unsigned char*)((char*)p + 0xd) = 0;
    *(unsigned int*)((char*)p + 0x28) = 0;
    *(unsigned int*)((char*)p + 0x38) = 0;
    *(unsigned int*)((char*)p + 0x48) = 0;
    *(unsigned int*)((char*)p + 0x58) = 0;
    *(unsigned char*)((char*)p + 0xc1) = 0;
    *(unsigned char*)((char*)p + 0xb8) = 0;
    *(unsigned int*)((char*)p + 0x78) = 0;
    *(unsigned int*)((char*)p + 0x2c) = 0;
    *(unsigned int*)((char*)p + 0x3c) = 0;
    *(unsigned int*)((char*)p + 0x4c) = 0;
    *(unsigned int*)((char*)p + 0x5c) = 0;
    *(unsigned char*)((char*)p + 0xc2) = 0;
    *(unsigned char*)((char*)p + 0xb9) = 0;
    *(unsigned int*)((char*)p + 0x7c) = 0;
    *(unsigned int*)((char*)p + 0x30) = 0;
    *(unsigned int*)((char*)p + 0x40) = 0;
    *(unsigned int*)((char*)p + 0x50) = 0;
    *(unsigned int*)((char*)p + 0x60) = 0;
    *(unsigned char*)((char*)p + 0xc3) = 0;
    *(unsigned char*)((char*)p + 0xba) = 0;
    *(unsigned int*)((char*)p + 0x80) = 0;
    *(unsigned int*)((char*)p + 0x34) = 0;
    *(unsigned int*)((char*)p + 0x44) = 0;
    *(unsigned int*)((char*)p + 0x54) = 0;
    *(unsigned int*)((char*)p + 0x64) = 0;
    *(unsigned char*)((char*)p + 0xc4) = 0;
    *(unsigned char*)((char*)p + 0xbb) = 0;
    *(unsigned int*)((char*)p + 0x84) = 0;
    *(unsigned char*)((char*)p + 0xbe) = 0;
    *(unsigned char*)((char*)p + 0xc0) = 0;
    *(unsigned int*)((char*)lbl_802BB0FC + 0x12c) = 0;
    if (*(unsigned char*)((char*)lbl_802BB0FC + 0xee) == 0) {
        return;
    }
    *(unsigned short*)((char*)p + 0xb4) = lbl_802272D4[*(unsigned int*)((char*)lbl_802BB0FC + 0x70)];
}

extern "C" void fn_8003793C(void* p, void*) {
    lbl_802FEDE0 |= 0x400;
    *(unsigned int*)((char*)p + 0x8) &= ~4;
    if (!lbl_802FEE44) {
        lbl_802FEE44 = 1;
        lbl_802FEE43 |= 4;
        lbl_802FEE30 |= 0x8000;
    }
    *(unsigned int*)(lbl_802BB0FC + 0xf8) &= ~0x20;
    fn_80029208(lbl_80246138);
}

extern "C" void fn_8003916C(void* p) {
    char* c = (char*)p;
    *(int*)(c + 0x8) = 0;
    *(unsigned char*)(c + 0xc) = 0;
    *(unsigned char*)(c + 0xd) = 0;
    *(int*)(c + 0x34) = 0;
    *(unsigned char*)(c + 0x40) = 0;
    *(int*)(c + 0x24) = 0;
    *(int*)(c + 0x28) = 0;
    *(int*)(c + 0x2c) = 0;
    *(int*)(c + 0x30) = 0;
    *(unsigned char*)(c + 0x41) = 1;
}

extern "C" void fn_800399CC(int* p) {
    short* e;
    int i;
    p[0] = lbl_802444F4[lbl_802B7CA0[0x1419]];
    p[3] = lbl_80244524[lbl_802B7CA0[0x1419]];
    e = (short*)p[0];
    for (i = 0; i < p[3]; i++) {
        e[2] = e[2] & 1;
        e += 4;
    }
    p[6] = 0;
}

extern "C" void fn_80039A3C(int* p, int x, short* q) {
    short* e;
    int i;
    int n = 0;
    int cnt = 0;
    short qx = q[0];
    short qy = q[1];
    short r = *(short*)(lbl_802BEF44 + 0x198);
    e = (short*)p[0];
    for (i = 0; i < p[3]; i++) {
        if (e[0] - qx >= -r && e[0] - qx <= r && e[1] - qy >= -r && e[1] - qy <= r) {
            e[2] = e[2] | 0x1000;
            cnt++;
            if (!(e[2] & 0x8000)) {
                n++;
            }
        }
        e += 4;
    }
    fn_80039CB8(p, x, cnt, n);
}

extern "C" int fn_80039AF0(void* p, int x, int idx) {
    short* e;
    short px, py, r;
    int hits, cnt, i;
    if ((*(unsigned int*)((char*)lbl_802B7CA0 + 0x3440) & (1 << idx)) == 0) {
        return 0;
    }
    e = *(short**)p;
    px = *(short*)((char*)lbl_802BB0FC + idx * 0x4c + 0x1a4);
    r = *(short*)((char*)lbl_802BEF44 + 0x198);
    hits = 0;
    py = *(short*)((char*)lbl_802BB0FC + idx * 0x4c + 0x1a6);
    cnt = 0;
    for (i = 0; i < *(int*)((char*)p + 0xc); i++) {
        int d = e[0] - px;
        if (d >= -r && d <= r) {
            d = e[1] - py;
            if (d >= -r && d <= r) {
                hits++;
                e[2] |= 0x1000;
                if (!(e[2] & 0x8000)) {
                    cnt++;
                }
            }
        }
        e += 4;
    }
    fn_80039CB8(p, x, hits);
}

extern "C" int fn_80039BD4(int* p, int x, int idx) {
    short* minx;
    short* miny;
    short* maxx;
    short* maxy;
    int i;
    short* e;
    int n = 0;
    int cnt = 0;
    if (idx < 0 || idx >= 0x24) {
        return 0;
    }
    minx = (short*)((char*)lbl_802BEE18 + idx * 8);
    miny = minx + 1;
    maxx = minx + 2;
    maxy = minx + 3;
    e = (short*)p[0];
    for (i = 0; i < p[3]; i++) {
        if (e[0] >= *minx && e[1] >= *miny && e[0] < *maxx && e[1] < *maxy) {
            cnt++;
            e[2] = e[2] | 0x1000;
            if (!(e[2] & 0x8000)) {
                n++;
            }
        }
        e += 4;
    }
    return fn_80039CB8(p, x, cnt, n);
}

extern "C" void fn_80039FBC(int* p) {
    volatile unsigned int tmp[2];
    unsigned int a;
    unsigned int b;
    unsigned int flags;
    if (p[6] != 0 && !(*(unsigned int*)(lbl_802BB0FC + 0x4c) & 2)) {
        p[6]--;
        flags = *(unsigned int*)(lbl_802BB0FC + 0x4c);
        a = p[1];
        *(unsigned int*)(lbl_802BB0FC + 0x7c) = a;
        flags |= 2;
        b = p[2];
        tmp[1] = a;
        tmp[0] = b;
        *(unsigned int*)(lbl_802BB0FC + 0x80) = b;
        *(unsigned int*)(lbl_802BB0FC + 0x4c) = flags;
    }
}

