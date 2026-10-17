// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80027638-0x80030740 (113 functions). split_file divides it into the game's real files.

struct S_8002EEEC {
    unsigned char a;
    unsigned short b;
};

struct S_Slot3C {
    unsigned char unk_0x00[0x14];
    int state;
    unsigned char unk_0x18[0x24];
};

extern "C" void fn_80057C38(void);
extern "C" void fn_80058740(int, void*);
extern "C" int fn_80058C08(void);
extern "C" void fn_80058628(int, void*, int);
extern "C" void fn_80058654(int, void*, int, float);
extern "C" int fn_800218C4(void*);
extern "C" int lbl_802FEE28;
extern "C" char lbl_802BB0FC[];
extern float lbl_802FFD10;
extern "C" unsigned int lbl_802FEDDC;
extern "C" unsigned int lbl_802FEDE0;
extern "C" void fn_800278EC(char* p) {
    extern unsigned int lbl_802FEDD8;
    extern unsigned int lbl_802FEDDC;
    extern unsigned int lbl_802FEDE0;
    extern unsigned int lbl_802FEDE4;
    extern unsigned int lbl_802FEDEC;
    extern unsigned int lbl_802FEDF0;
    extern unsigned int lbl_802FEDF4;
    extern unsigned int lbl_802FEDFC;
    extern int lbl_802FEE04;
    extern int lbl_802FEE08;
    extern unsigned int lbl_802FEE0C;
    extern int lbl_802FEE10;
    extern unsigned int lbl_802FEE14;
    extern unsigned int lbl_802FEE18;
    extern unsigned int lbl_802FEE1C;
    extern unsigned int lbl_802FEE24;
    extern unsigned int lbl_802FEE2C;
    extern unsigned int lbl_802FEE30;
    extern unsigned int lbl_802FEE48;
    extern unsigned char lbl_802FEE35;
    extern unsigned char lbl_802FEE36;
    extern unsigned char lbl_802FEE37;
    extern unsigned char lbl_802FEE3C;
    extern unsigned char lbl_802FEE3D;
    extern unsigned char lbl_802FEE3E;
    extern unsigned char lbl_802FEE3F;
    extern unsigned char lbl_802FEE40;
    extern unsigned char lbl_802FEE41;
    extern unsigned char lbl_802FEE42;
    extern unsigned char lbl_802FEE43;
    extern unsigned char lbl_802FEE44;
    extern unsigned char lbl_802FEE45;

    *(int*)(p + 0x7c4) = -1;
    lbl_802FEDD8 = 0;
    lbl_802FEDE4 = 6;
    lbl_802FEDEC = 0;
    lbl_802FEDF0 = 0;
    lbl_802FEDF4 = 0;
    lbl_802FEDFC = 0;
    lbl_802FEE04 = -1;
    lbl_802FEE08 = -1;
    lbl_802FEE0C = 0x27;
    lbl_802FEDDC = 0;
    lbl_802FEDE0 = 0;
    lbl_802FEE10 = 0x708;
    lbl_802FEE35 = 0;
    lbl_802FEE14 = 0x4b0;
    lbl_802FEE18 = 0;
    lbl_802FEE1C = 0;
    lbl_802FEE36 = 0;
    lbl_802FEE37 = 0;
    lbl_802FEE45 = 0;
    lbl_802FEE24 = 0;
    lbl_802FEE3C = 0;
    lbl_802FEE3D = 0;
    lbl_802FEE3E = 0;
    lbl_802FEE28 = 0;
    lbl_802FEE3F = 0;
    lbl_802FEE2C = 0;
    lbl_802FEE30 = 0;
    lbl_802FEE40 = 0;
    lbl_802FEE41 = 0;
    lbl_802FEE42 = 0xff;
    lbl_802FEE43 = 0;
    lbl_802FEE44 = 0;
    lbl_802FEE48 = 0;
    *(int*)(p + 0x7c8) = 0x100;
    *(int*)(p + 0x7cc) = 0x100;
    *(int*)(p + 0x7d0) = 0x100;
    *(int*)(p + 0x7d4) = 0x100;
}

extern "C" void fn_80027C98(void) {
    extern unsigned int lbl_802FEDDC;
    lbl_802FEDDC |= 0x4000;
}

extern "C" void fn_80027CA8(void) {
    extern unsigned int lbl_802FEDDC;
    lbl_802FEDDC &= 0xffffbfff;
}

extern "C" void fn_80027CB8(void) {
    extern unsigned char lbl_802FEE34;
    unsigned int flags;

    if (fn_800218C4(lbl_802BB0FC) == 0 || lbl_802FEE34 != 0) {
        flags = *(unsigned int*)(lbl_802BB0FC + 0x4c);
        *(unsigned int*)(lbl_802BB0FC + 0x4c) = flags & ~1;
        *(unsigned int*)(lbl_802BB0FC + 0x4c) = flags & ~3;
    }
    if ((*(unsigned int*)(lbl_802BB0FC + 0x4c) & 1) == 0) {
        *(int*)(lbl_802BB0FC + 0xf4) = 0;
    }
    if ((*(unsigned int*)(lbl_802BB0FC + 0x4c) & 2) == 0) {
        *(int*)(lbl_802BB0FC + 0x7c) = 0;
        *(int*)(lbl_802BB0FC + 0x80) = 0;
    }
}

extern "C" void fn_8002A410(unsigned char* p);

extern "C" void fn_80027D4C(unsigned char* p) {
    fn_8002A410(p);
}

extern "C" int fn_800290BC(unsigned char* p, int idx) {
    switch (((S_Slot3C*)(p + 0x384))[idx].state) {
    case 1:
    case 2:
        if (p[0x57e] != 0) {
            return 0;
        }
        break;
    case 3:
    case 4:
        if (p[0x586] != 0) {
            return 0;
        }
        break;
    }
    return 1;
}

extern "C" void fn_80029118(const char*, ...) {
}

extern "C" void fn_80029168(const char*, ...) {
}

extern "C" void fn_800291B8(const char*, ...) {
}

extern "C" void fn_80029208(const char*, ...) {
}

extern "C" int fn_800294AC(int, int, float, int, int, int, int, int, int, int);
extern "C" int fn_80029794(int a, int b, int c) {
    if ((lbl_802FEDDC & 0x200) && *(int*)(b + 8) != 0x9e) {
        int s = *(int*)(b + 0x18);
        if (s == 2 || s == 4 || s == 0) {
            return 1;
        }
    }
    return fn_800294AC(a, b, c, lbl_802FFD10, 0, 0, *(int*)(b + 8), 0, 0, 0);
}

extern "C" unsigned char* fn_800298BC(unsigned char* self, int id) {
    int i;
    for (i = 0; i < 8; i++) {
        int v = *(int*)(self + i * 0x3c + 0x384);
        if (v != 0 && v == id) {
            return self + i * 0x3c + 0x384;
        }
    }
    return 0;
}

extern "C" void fn_8002A3CC(void* self_, void* node_, int a, int b);
extern "C" int fn_8002A388(unsigned char* self, int a, int b) {
    if (*(int*)(self + 0x6e8) != 0) {
        return 0;
    }
    fn_8002A3CC(self, self + 0x6e4, a, b);
    return 1;
}

extern "C" void fn_8002A3CC(void* self_, void* node_, int a, int b) {
    unsigned char* self = (unsigned char*)self_;
    unsigned char* next;
    unsigned int* node = (unsigned int*)node_;
    node[0] = a;
    node[1] = b;
    node[2] = 0;
    next = *(unsigned char**)(self + 0x6e0);
    if (next != 0) {
        self = next;
        while ((next = *(unsigned char**)(self + 0x8)) != 0) {
            self = next;
        }
        *(unsigned int**)(self + 0x8) = node;
        return;
    }
    *(unsigned int**)(self + 0x6e0) = node;
}

extern "C" int lbl_80227384[3];
extern "C" void fn_8002A4A4(unsigned char* p, int v);
extern "C" void fn_8002A410(unsigned char* p) {
    if ((*(unsigned int*)(lbl_802BB0FC + 0x4c) & 1) == 0) {
        int* obj = *(int**)(p + 0x6e0);
        if (obj != 0) {
            fn_8002A4A4(p, obj[0]);
            (*(int**)(p + 0x6e0))[1]--;
            obj = *(int**)(p + 0x6e0);
            if (obj[1] == 0) {
                *(int*)(p + 0x6e0) = obj[2];
                obj[0] = lbl_80227384[0];
                obj[1] = lbl_80227384[1];
                obj[2] = lbl_80227384[2];
            }
        }
    }
}

extern "C" int fn_8002B620(unsigned char* self, unsigned char idx, unsigned char val) {
    int i;
    unsigned char* p = self + idx * 8;
    for (i = 0; i < 8; i++, p++) {
        if (p[0x840] == val) return 1;
    }
    return 0;
}

extern "C" unsigned char fn_8002B7B0(unsigned char* self, unsigned char idx, int slot, unsigned char val) {
    if (val < 7 || val >= 0x14 || val == 0xe) {
        val = 0;
    }
    (self + idx * 8)[slot + 0x840] = (lbl_802BB0FC + idx * 0x4c)[slot + 0x1d8];
    (lbl_802BB0FC + idx * 0x4c)[slot + 0x1d8] = val;
    return val;
}

extern "C" void fn_8002BC84(void) {
    extern unsigned int lbl_802FEDDC;
    lbl_802FEDDC &= 0xffffffef;
}

extern "C" void fn_8002C050(void) {
    extern unsigned int lbl_802FEDDC;
    lbl_802FEDDC |= 0x2000000;
}

extern "C" void fn_8002C060(void) {
    extern unsigned int lbl_802FEDDC;
    lbl_802FEDDC &= 0xfdffffff;
}

extern "C" void fn_8002C070(void) {
    extern unsigned int lbl_802FEDDC;
    lbl_802FEDDC |= 0x4000000;
}

extern "C" void fn_8002C080(void) {
    extern unsigned int lbl_802FEDDC;
    lbl_802FEDDC &= 0xfbffffff;
}

extern "C" void fn_8002EF5C(int, unsigned char, unsigned char, unsigned char, unsigned char, int, int);
extern "C" void fn_8002D250(int a, int b, int slot, unsigned char v, int e) {
    unsigned char buf[4] = {0, 0, 0, 0};
    buf[slot] = v;
    fn_8002EF5C(b, buf[0], buf[1], buf[2], buf[3], e, 0);
}

extern "C" void fn_8002D2A8(char* p) {
    lbl_802FEDE0 |= 0x800;
    if (*(unsigned char*)(lbl_802BB0FC + 0xee) != 0) {
        lbl_802FEDDC |= 0x2000;
    }
    *(int*)(p + 0x770) = *(int*)(lbl_802BB0FC + 0x58) + 1000;
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

extern "C" void fn_8002D3C0(char* p) {
    lbl_802FEDE0 |= 0x2000;
    *(int*)(p + 0x770) = *(int*)(lbl_802BB0FC + 0x58) + 1000;
}

extern "C" void fn_8002D3E4(char* p) {
    lbl_802FEDE0 |= 0x2000;
    *(int*)(p + 0x770) = *(int*)(lbl_802BB0FC + 0x58);
}

extern "C" void fn_8002D404(void) {
    extern unsigned int lbl_802FEDDC;
    lbl_802FEDDC &= 0xfffffdff;
}

extern "C" void fn_8002E444(char* p, int idx);
extern "C" void fn_8002E010(char* p, int idx, int val, float f) {
    if (idx < 0 || idx >= 10) {
        return;
    }
    unsigned char* e = (unsigned char*)(p + idx * 4 + 0x56c);
    fn_8002E444(p, idx);
    if (idx == 0) {
        lbl_802FEE28 = val;
    }
    fn_80058654(idx + 1, (void*)val, 1, f);
    *(unsigned short*)e = val;
    e[2] = 2;
    e[3] = 1;
}

extern "C" void fn_8002E1E4(char* p, int idx, float f) {
    if (idx < 0 || idx >= 10) {
        return;
    }
    unsigned char* e = (unsigned char*)(p + idx * 4 + 0x56c);
    fn_8002E444(p, idx);
    fn_80058654(idx + 1, (void*)*(unsigned short*)e, 1, f);
    e[2] = 2;
    e[3] = 1;
}

extern "C" void fn_8002E380(char* p, int idx) {
    if (idx == 0) {
        lbl_802FEE28 = 0;
    }
    if (idx < 0 || idx >= 10) {
        return;
    }
    unsigned char* e = (unsigned char*)(p + idx * 4);
    *(unsigned short*)(e + 0x56c) = 0;
    e[0x56e] = 0;
    e[0x56f] = 1;
}

extern "C" void fn_8005869C(int, int);
extern "C" void fn_8002E3C4(char* p, int idx) {
    extern int lbl_802FEE28;
    if (idx == 0) {
        lbl_802FEE28 = 0;
    }
    if (idx < 0 || idx >= 10) {
        return;
    }
    unsigned char* e = (unsigned char*)(p + idx * 4 + 0x56c);
    int n = idx + 1;
    if (e[2] == 2) {
        fn_8005869C(n, 3);
        e[2] = 1;
        e[3] = 3;
    }
}

extern "C" void fn_8002EEEC(unsigned char a, unsigned short b) {
    S_8002EEEC s;
    S_8002EEEC t;
    s.a = a;
    s.b = b;
    *(int*)(lbl_802BB0FC + 0x4c) |= 2;
    t = s;
    *(S_8002EEEC*)(lbl_802BB0FC + 0x7c) = t;
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

extern "C" void fn_8005867C(int, void*, int, int, int, float);
extern "C" void fn_8002F228(void* p) {
    extern float lbl_802FFD10;
    unsigned char* obj = *(unsigned char**)(lbl_802BB0FC + 0xf0);
    if (obj != 0) {
        if (obj[0x56e] == 3) {
            fn_800589CC(1);
            fn_800589CC(2);
        } else if (obj[0x56e] != 0) {
            fn_800589CC(1);
        }
        lbl_802FEE28 = 0;
        *(unsigned short*)(obj + 0x56c) = 0;
        obj[0x56e] = 0;
        obj[0x56f] = 1;
        lbl_802FEE28 = (int)p;
        fn_80058654(1, p, 1, lbl_802FFD10);
        *(unsigned short*)(obj + 0x56c) = (unsigned short)(int)p;
        obj[0x56e] = 2;
        obj[0x56f] = 1;
    }
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
    int r = fn_80058C08();
    r = off + r;
    fn_80058628(r, p, 1);
}

extern "C" void fn_8002F3A0(void* p, int off, float f) {
    fn_80058654(off + fn_80058C08(), p, 1, f);
}

extern "C" void fn_8002F3F8(void* p, int off, int v) {
    extern float lbl_802FFD10;
    fn_8005867C(off + fn_80058C08(), p, 1, v, -1, lbl_802FFD10);
}

extern "C" void fn_8002F458(void* p, int off) {
    int r = fn_80058C08();
    r = off + r;
    fn_80058628(r, p, 1);
}

extern "C" void fn_8002F4A0(void* p, int idx) {
    extern float lbl_802FFD10;
    extern void* lbl_80227868[];
    fn_8005867C(idx + fn_80058C08(), p, 1, (int)lbl_80227868[idx], -1, lbl_802FFD10);
}

extern "C" void fn_8002F500(void* p) {
    if ((lbl_802FEDDC & 0x200) == 0) {
        fn_80058628(fn_80058C08(), p, 1);
    }
}

extern "C" void* fn_8002F6BC(void) {
    extern int lbl_802FEE04;
    int i;
    unsigned char* p;
    unsigned char* obj = *(unsigned char**)(lbl_802BB0FC + 0xf0);
    if (obj != 0 && lbl_802FEE04 > 0) {
        p = obj;
        i = 0;
        for (i = 0; i < 8; i++) {
            int id = *(int*)(p + 0x384);
            if (id != 0 && id == lbl_802FEE04) {
                return obj + 0x384 + i * 0x3c;
            }
            p += 0x3c;
        }
        return 0;
    }
    return 0;
}

extern "C" void fn_80058A28(int);
extern "C" void fn_8002F72C(void) {
    extern unsigned int lbl_801F929C[];
    unsigned int buf[8];
    unsigned int i;
    for (i = 0; i < 8; i++) {
        buf[i] = lbl_801F929C[i];
    }
    for (i = 0; i < 8; i++) {
        fn_80058A28(buf[i]);
    }
}

extern "C" void fn_8002F7C0(int param_1) {
    extern float lbl_802FFD14;
    extern unsigned int lbl_802FC710;
    extern int lbl_802FEE10;
    extern char lbl_802BEF44[];
    extern char lbl_8023023C[];
    unsigned int seed = lbl_802FC710 * 0x19660d + 0x3c6ef35f;
    int x = (int)(lbl_802FFD14 * *(float*)(lbl_802BEF44 + 0xfc));
    int y = (int)(lbl_802FFD14 * *(float*)(lbl_802BEF44 + 0xf8));
    unsigned int r = seed & 0x7fff;
    int v;
    lbl_802FC710 = seed;
    lbl_802FEE10 = y + (int)(((unsigned int)x * r) >> 15);
    v = *(int*)(lbl_8023023C + param_1 * 16 + *(int*)(lbl_802BB0FC + 0x420) * 4);
    if (v > 0) {
        fn_8002F0A8(v);
    } else {
        fn_8002F100(-v, 0);
    }
}

extern "C" int fn_8002F87C(void) {
    unsigned char* obj = *(unsigned char**)(lbl_802BB0FC + 0xf0);
    if (obj != 0 && obj[0x57e] != 0) {
        return 1;
    }
    return 0;
}

extern "C" void fn_80030664(void) {}