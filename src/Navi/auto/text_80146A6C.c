// Navi Trackers (framework.dol) code that had no source file yet: decomp.wtf gave it this one.
// .text 0x80146a6c-0x80146ae8 (2 functions). split_file divides it into the game's real files.

extern "C" unsigned char lbl_802FF3B0;
extern "C" unsigned char lbl_802D4C94[];
extern "C" unsigned char lbl_802D46C0[];
extern "C" unsigned long lbl_802FF3D8;
extern "C" int fn_80146A6C(unsigned char idx) {
    unsigned char* p = lbl_802D46C0 + idx * 0x30;
    if (p[0x601] != 4 && (lbl_802FF3D8 & (1 << idx)) && *(float*)(p + 0x5dc) > *(float*)(p + 0x5d8)) {
        return 1;
    }
    return 0;
}

extern "C" void fn_80146AC0(unsigned char idx, unsigned char val) {
    if (lbl_802FF3B0 == 0) {
        return;
    }
    lbl_802D4C94[idx * 0x30 + 0x2d] = val;
}
struct Unk80146A6C {
    char pad0[0x28];
    float m28;
    char pad2C[1];
    unsigned char m2D;
    char pad2E[2];
};
