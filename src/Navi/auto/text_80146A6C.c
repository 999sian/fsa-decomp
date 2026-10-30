// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80146a6c-0x80146ae8 (2 functions). split_file divides it into the game's real files.

struct Unk80146A6C {
    char pad0[0x18];
    float m18;
    float m1C;
    char pad20[0x9];
    unsigned char m29;
    char pad2A[3];
    unsigned char m2D;
    char pad2E[2];
};

extern "C" unsigned char lbl_802FF3B0;
extern "C" Unk80146A6C lbl_802D4C94[];
extern "C" Unk80146A6C lbl_802D46C0[];
extern "C" unsigned long lbl_802FF3D8;
extern "C" int fn_80146A6C(int no) {
    unsigned char idx = no;
    Unk80146A6C* p = &lbl_802D46C0[idx];
    if (((unsigned char*)p)[0x601] != 4 && (lbl_802FF3D8 & (1 << idx)) && *(float*)((char*)p + 0x5dc) > *(float*)((char*)p + 0x5d8)) {
        return 1;
    }
    return 0;
}

extern "C" void fn_80146AC0(int no, unsigned char val) {
    if (lbl_802FF3B0 == 0) {
        return;
    }
    unsigned char idx = no;
    lbl_802D4C94[idx].m2D = val;
}
