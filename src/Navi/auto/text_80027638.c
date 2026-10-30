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
extern "C" int fn_80058740(int, void*);
extern "C" int fn_8005887C(void*);
extern "C" void fn_800589CC(int);
extern "C" int fn_80058C08(void);
extern "C" void fn_80058628(int, void*, int);
extern "C" void fn_80058654(int, void*, int, float);
extern "C" int fn_800218C4(void*);
extern "C" int lbl_802FEE28;
extern "C" char lbl_802BB0FC[];
extern "C" unsigned int lbl_8022797C[];
extern float lbl_802FFD10;
extern "C" unsigned char lbl_8022F534[];
extern "C" unsigned char lbl_802FBE3C[8];
extern "C" unsigned int lbl_802FEE30;
extern "C" int fn_8002B484(unsigned char* p, unsigned int a, unsigned char b);
extern "C" int lbl_802FEE08;
extern "C" unsigned int lbl_80227878[];
struct S_801F9280 {
    int v[7];
};
extern "C" struct S_801F9280 lbl_801F9280;
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

#pragma push
#pragma use_lmw_stmw off
extern "C" int fn_80029810(int a, int x, int y, int z, int c, int d, int e, int g, float f, int h, unsigned char i, unsigned char j) {
    struct S_801F9280 tbl = lbl_801F9280;
    tbl.v[4] = x;
    tbl.v[5] = y;
    tbl.v[6] = z;
    return fn_800294AC(a, (int)&tbl, f, c, d, e, g, h, i, j);
}
#pragma pop
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

extern "C" int fn_8002A2B8(unsigned char* p, int id) {
    int i;
    int j = 0;
    for (i = 0; i < 2; i++) {
        if (*(int*)(p + 0x384) != 0 && p[0x3bd] == 1 && *(int*)(p + 0x398) == id) {
            return 1;
        }
        if (*(int*)(p + 0x3c0) != 0 && p[0x3f9] == 1 && *(int*)(p + 0x3d4) == id) {
            return 1;
        }
        if (*(int*)(p + 0x3fc) != 0 && p[0x435] == 1 && *(int*)(p + 0x410) == id) {
            return 1;
        }
        if (*(int*)(p + 0x438) != 0 && p[0x471] == 1 && *(int*)(p + 0x44c) == id) {
            return 1;
        }
        p += 0xf0;
        j += 3;
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

extern "C" int fn_8002B6D4(int a, unsigned char v) {
    int i;
    unsigned char* q;
    unsigned char* p = (unsigned char*)lbl_802BB0FC;
    for (i = 0; i < 4; i++) {
        if (v == p[0x1d8]) {
            return 1;
        }
        q = p + 1;
        if (v == p[0x1d9]) {
            return 1;
        }
        if (v == q[0x1d9]) {
            return 1;
        }
        q++;
        if (v == q[0x1d9]) {
            return 1;
        }
        q++;
        if (v == q[0x1d9]) {
            return 1;
        }
        q++;
        if (v == q[0x1d9]) {
            return 1;
        }
        q++;
        if (v == q[0x1d9]) {
            return 1;
        }
        q++;
        if (v == q[0x1d9]) {
            return 1;
        }
        p += 0x4c;
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

#pragma use_lmw_stmw off
extern "C" int fn_8002B808(unsigned char* p, unsigned int param) {
    unsigned char* q;
    unsigned char* t;
    int i;
    int n;
    int found;
    t = lbl_802FBE3C;
    q = t;
    found = 0;
    n = 5;
    if (lbl_802FEE30 & 0x8000) {
        n = 4;
    }
    for (i = 0; i < n; i++, q++) {
        if (fn_8002B484(p, param, *q) == 0) {
            found = 1;
            break;
        }
    }
    if (found != 0) {
        for (i = 0; i < n; i++, t++) {
            if ((p + 4)[(unsigned char)param + 0x834] == *t) {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}
#pragma use_lmw_stmw reset
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

extern "C" void fn_8002E55C(unsigned char* obj) {
    if (lbl_802FEE28 != 0 && fn_80058740(1, (void*)lbl_802FEE28) == 0 &&
        fn_8005887C((void*)lbl_802FEE28) == 1000000) {
        int p = lbl_802FEE28;
        if (obj[0x56e] == 3) {
            fn_800589CC(1);
            fn_800589CC(2);
        } else if (obj[0x56e] != 0) {
            fn_800589CC(1);
        }
        float f;
        lbl_802FEE28 = 0;
        f = lbl_802FFD10;
        *(unsigned short*)(obj + 0x56c) = 0;
        obj[0x56e] = 0;
        obj[0x56f] = 1;
        lbl_802FEE28 = p;
        fn_80058654(1, (void*)p, 1, f);
        *(unsigned short*)(obj + 0x56c) = (unsigned short)p;
        obj[0x56e] = 2;
        obj[0x56f] = 1;
    }
}

struct S_8002EF20 {
    unsigned char a;
    unsigned char c;
    unsigned short d;
};

extern "C" void fn_8002EEEC(unsigned char a, unsigned short b) {
    S_8002EEEC s;
    S_8002EEEC t;
    s.a = a;
    s.b = b;
    *(int*)(lbl_802BB0FC + 0x4c) |= 2;
    t = s;
    *(S_8002EEEC*)(lbl_802BB0FC + 0x7c) = t;
}

extern "C" void fn_8002EF20(unsigned char a, int b, unsigned char c, unsigned short d) {
    S_8002EF20 s;
    S_8002EF20 t;
    char* p = lbl_802BB0FC;
    s.a = a;
    s.c = c;
    s.d = d;
    *(int*)(p + 0x80) = b;
    *(int*)&t = *(int*)&s;
    *(int*)(p + 0x7c) = *(int*)&t;
    *(int*)(p + 0x4c) |= 2;
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

extern "C" int fn_8002F8AC(int p, int a, unsigned char b, unsigned char c, unsigned char d) {
    if (p == 0) {
        p = (a << 24) + (b << 16) + (c << 8) + d;
    }
    return p;
}

extern "C" void fn_8002F8D4(int param_1) {
    unsigned int uVar1;
    unsigned char* obj = *(unsigned char**)(lbl_802BB0FC + 0xf0);
    float f;
    if (obj != 0 && lbl_802FEE08 != param_1) {
        uVar1 = lbl_80227878[param_1];
        if (obj[0x56e] == 3) {
            fn_800589CC(1);
            fn_800589CC(2);
        } else if (obj[0x56e] != 0) {
            fn_800589CC(1);
        }
        lbl_802FEE28 = 0;
        f = *(float*)&lbl_802FFD10;
        *(unsigned short*)(obj + 0x56c) = 0;
        obj[0x56e] = 0;
        obj[0x56f] = 1;
        lbl_802FEE28 = uVar1;
        fn_80058654(1, (void*)uVar1, 1, f);
        *(unsigned short*)(obj + 0x56c) = uVar1;
        obj[0x56e] = 2;
        obj[0x56f] = 1;
        lbl_802FEE08 = param_1;
    }
}

extern "C" void fn_8002F9B4(void) {
    extern int lbl_802FEE08;
    unsigned char* obj = *(unsigned char**)(lbl_802BB0FC + 0xf0);
    if (obj != 0) {
        lbl_802FEE28 = 0;
        if (obj[0x56e] == 2) {
            fn_8005869C(1, 3);
            obj[0x56e] = 1;
            obj[0x56f] = 3;
        }
        lbl_802FEE08 = -1;
    }
}

extern "C" void fn_80030418(int, int);
extern "C" void fn_8002FA24(int idx) {
    extern int lbl_80227888[];
    fn_80030418(lbl_80227888[idx], idx);
    if (idx == 3) {
        *(unsigned int*)(lbl_802BB0FC + 0x468) |= 0x100;
    }
}

#pragma dont_inline on
extern "C" void fn_8002FA80(int a, int b, int c, int d) {
    extern int lbl_80227898[];
    fn_8002F100(lbl_80227898[*(int*)(lbl_802BB0FC + 0x420)], (a << 24) + (b << 16) + (c << 8) + d);
}

extern "C" int fn_80021994(void);
extern "C" void fn_8002FAD4(int a) {
    extern void* lbl_80225C94[];
    extern int lbl_802278A8[];
    extern float lbl_802FFD10;
    int v = a << 24;
    void* obj = *(void**)(lbl_802BB0FC + 0xf0);
    if (obj != 0) {
        int r = fn_80021994();
        fn_8002E0AC(obj, 4, (int)lbl_80225C94[lbl_802278A8[*(int*)(lbl_802BB0FC + 0x420)]], v, r, 0, 1, lbl_802FFD10);
    }
}

extern "C" void fn_8002FB68(int param_1, int param_2) {
    extern char lbl_8023061C[];
    fn_8002F0A8(*(int*)(lbl_8023061C + param_1 * 0x50 + param_2 * 16 + *(int*)(lbl_802BB0FC + 0x420) * 4));
}

extern "C" void fn_800300C0(int id, unsigned int flags, int val, int idx, float f);
extern "C" void fn_8002FF34(int a, unsigned int b, unsigned int c, int d) {
    extern short lbl_802278B8[];
    extern float lbl_802FFD30;
    fn_800300C0(0x18, ((d << 16) + (b & 0xf)) | 0x70, lbl_802278B8[c & 0x1f], 0, lbl_802FFD30);
}

extern "C" void fn_80030250(int param_1) {
    switch (*(int*)(lbl_802BB0FC + 0x420)) {
    case 1:
        *(unsigned int*)(lbl_802BB0FC + 0x450) |= lbl_8022797C[param_1 * 4 + 1];
        return;
    case 3:
        *(unsigned int*)(lbl_802BB0FC + 0x468) |= lbl_8022797C[param_1 * 4 + 3];
        return;
    case 2:
    default:
        *(unsigned int*)(lbl_802BB0FC + 0x444) |= lbl_8022797C[param_1 * 4];
        return;
    }
}

extern "C" void fn_800302F0(int param_1) {
    switch (*(int*)(lbl_802BB0FC + 0x420)) {
    case 1:
        *(unsigned int*)(lbl_802BB0FC + 0x450) &= ~lbl_8022797C[param_1 * 4 + 1];
        return;
    case 3:
        *(unsigned int*)(lbl_802BB0FC + 0x468) &= ~lbl_8022797C[param_1 * 4 + 3];
        return;
    case 2:
    default:
        *(unsigned int*)(lbl_802BB0FC + 0x444) &= ~lbl_8022797C[param_1 * 4];
        return;
    }
}

extern unsigned char lbl_802313EC[];
extern "C" int fn_80030390(unsigned char c) {
    int i;
    for (i = 0; i < 12; i++) {
        if (lbl_802313EC[i] == c) {
            return i;
        }
    }
    return 0;
}

extern "C" void fn_80030534(void* node_, int a, int b) {
    unsigned char* self = *(unsigned char**)(lbl_802BB0FC + 0xf0);
    unsigned char* p;
    unsigned int* node = (unsigned int*)node_;
    if (self == 0) {
        return;
    }
    node[0] = a;
    node[1] = b;
    node[2] = 0;
    p = *(unsigned char**)(self + 0x6e0);
    if (p != 0) {
        while (*(unsigned char**)(p + 0x8) != 0) {
            p = *(unsigned char**)(p + 0x8);
        }
        *(unsigned int**)(p + 0x8) = node;
        return;
    }
    *(unsigned int**)(self + 0x6e0) = node;
}

extern "C" unsigned char* fn_800298BC(unsigned char* self, int id);
extern "C" int fn_80030588(int param_1) {
    unsigned char* obj;
    unsigned char* p;
    int i;
    int k;
    int id;
    int v;

    if (param_1 != 0 && (lbl_802FEDDC & 0x6004000) != 0) {
        return 1;
    }
    obj = *(unsigned char**)(lbl_802BB0FC + 0xf0);
    if (obj == 0) {
        return 0;
    }
    for (k = 0; k < 3; k++) {
        id = *(int*)(obj + k * 4 + 0x71c);
        p = 0;
        for (i = 0; i < 8; i++) {
            v = *(int*)(obj + i * 0x3c + 0x384);
            if (v != 0 && v == id) {
                p = obj + i * 0x3c + 0x384;
                break;
            }
        }
        if (p != 0) {
            return 1;
        }
    }
    return 0;
}

extern "C" int fn_80030638(int param_1) {
    unsigned char* obj = *(unsigned char**)(lbl_802BB0FC + 0xf0);
    if (obj != 0) {
        return (int)(signed char)obj[param_1 + 0xc69];
    }
    return 0;
}

#pragma dont_inline reset
extern "C" void fn_80030664(void) {}

extern "C" int fn_80030668(int param_1) {
    void* obj = *(void**)(lbl_802BB0FC + 0xf0);
    if (obj != 0) {
        return fn_800294AC((int)obj, (int)(lbl_8022F534 + *(int*)(lbl_802BB0FC + 0x420) * 0x1c), 0xf, 0, 0, param_1, 0, 0, lbl_802FFD10, 1);
    }
    return 0;
}

extern "C" unsigned char* fn_800306DC(int param_1) {
    int i;
    unsigned char* p;
    unsigned char* obj = *(unsigned char**)(lbl_802BB0FC + 0xf0);
    if (obj != 0) {
        p = obj;
        for (i = 0; i < 8; i++) {
            int v = *(int*)(p + 0x384);
            if (v != 0 && v == param_1) {
                return obj + i * 0x3c + 0x384;
            }
            p += 0x3c;
        }
        return 0;
    }
    return 0;
}

