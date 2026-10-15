// Code of main that had no source file yet: decomp.wtf gave it this one.
// split_file divides it into the game's real files (file_status shows its range).

extern void* lbl_8049AE38[];
extern void* lbl_8049AE10[];
extern void* lbl_8049AE24[];
void __dl__FPv(void*);
extern "C" void fn_800CF2B0(void** p) {
    void** volatile* vp = (void** volatile*)p;
    *vp = lbl_8049AE38;
    *vp = lbl_8049AE24;
}

extern "C" void** fn_800CF2CC(void** p, short del) {
    if (p != 0) {
        *p = lbl_8049AE38;
        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

extern "C" void** fn_800CF314(void** p, short del) {
    if (p != 0) {
        *p = lbl_8049AE24;
        if (p != 0) {
            *p = lbl_8049AE38;
        }
        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}

extern "C" void fn_800CF370(void** p) {
    void** volatile* vp = (void** volatile*)p;
    *vp = lbl_8049AE38;
    *vp = lbl_8049AE10;
}
struct Base_800CF2B0 {
    void* vt;
    Base_800CF2B0() { vt = lbl_8049AE38; }
};
struct Derived_800CF2B0 : Base_800CF2B0 {
    Derived_800CF2B0() { vt = lbl_8049AE24; }
    void* operator new(unsigned long, void* p) { return p; }
};
